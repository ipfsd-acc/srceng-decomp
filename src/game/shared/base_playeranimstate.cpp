// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/base_playeranimstate.cpp
// Functions: 40
// ============================================================

#include "game\shared\base_playeranimstate.h"

//------------------------------------------------------------------------------
// Address: 0x10009C90
// Name: public: void CBasePlayerAnimState::Init(class C_BaseAnimatingOverlay __near *,class CModAnimConfig const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayerAnimState::Init(
        CBasePlayerAnimState *this,
        C_BaseAnimatingOverlay *pPlayer,
        const CModAnimConfig *config)
{
  int v3; // eax

  this->m_pOuter = pPlayer;
  *(_QWORD *)&this->m_AnimConfig.m_flMaxBodyYawDegrees = *(_QWORD *)&config->m_flMaxBodyYawDegrees;
  v3 = *(_DWORD *)this->gap4;
  *(_DWORD *)&this->m_AnimConfig.m_bUseAimSequences = *(_DWORD *)&config->m_bUseAimSequences;
  (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)&this->gap4[*(_DWORD *)(v3 + 4)] + 8))(a1: &this->gap4[*(_DWORD *)(v3 + 4)]);
}

//------------------------------------------------------------------------------
// Address: 0x10009CF0
// Name: public: virtual void CBasePlayerAnimState::ClearAnimationState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayerAnimState::ClearAnimationState(CBasePlayerAnimState *this)
{
  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 38) + 4))(a1: (char *)this - 152);
  *((_BYTE *)this - 112) = 0;
  *((float *)this - 17) = *(float *)(gpGlobals.m_Index + 12);
}

//------------------------------------------------------------------------------
// Address: 0x10009D20
// Name: protected: float CBasePlayerAnimState::TimeSinceLastAnimationStateClear(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBasePlayerAnimState::TimeSinceLastAnimationStateClear(CBasePlayerAnimState *this)
{
  return *(float *)(gpGlobals.m_Index + 12) - this->m_flLastAnimationStateClearTime;
}

//------------------------------------------------------------------------------
// Address: 0x10009D30
// Name: public: virtual void CBasePlayerAnimState::ClearAnimationLayers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayerAnimState::ClearAnimationLayers(CBasePlayerAnimState *this)
{
  C_BaseAnimatingOverlay *m_pOuter; // ecx
  int i; // esi
  C_AnimationLayer *AnimOverlay; // eax

  m_pOuter = this->m_pOuter;
  if ( m_pOuter != nullptr )
  {
    C_BaseAnimatingOverlay::SetNumAnimOverlays(this: m_pOuter, num: 5);
    for ( i = 0; i < C_BaseAnimatingOverlay::GetNumAnimOverlays(this: this->m_pOuter); ++i )
    {
      AnimOverlay = C_BaseAnimatingOverlay::GetAnimOverlay(this: this->m_pOuter, i);
      C_AnimationLayer::SetOrder(this: AnimOverlay, order: 15);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009D80
// Name: protected: virtual void CBasePlayerAnimState::ResetGroundSpeed(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayerAnimState::ResetGroundSpeed(CBasePlayerAnimState *this)
{
  this->m_flMaxGroundSpeed = this->GetCurrentMaxGroundSpeed(this);
}

//------------------------------------------------------------------------------
// Address: 0x10009D90
// Name: protected: virtual bool CBasePlayerAnimState::ShouldResetGroundSpeed(enum Activity,enum Activity)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBasePlayerAnimState::ShouldResetGroundSpeed(
        CBasePlayerAnimState *this,
        Activity oldActivity,
        Activity idealActivity)
{
  return (oldActivity == ACT_CROUCHIDLE || oldActivity == ACT_IDLE)
      && (idealActivity == ACT_WALK || idealActivity == ACT_RUN_CROUCH);
}

//------------------------------------------------------------------------------
// Address: 0x10009DC0
// Name: public: virtual bool CBasePlayerAnimState::ShouldBlendAimSequenceToIdle(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBasePlayerAnimState::ShouldBlendAimSequenceToIdle(CBasePlayerAnimState *this)
{
  Activity m_eCurrentMainSequenceActivity; // eax

  m_eCurrentMainSequenceActivity = this->m_eCurrentMainSequenceActivity;
  return m_eCurrentMainSequenceActivity == ACT_RUN
      || m_eCurrentMainSequenceActivity == ACT_LEAP
      || m_eCurrentMainSequenceActivity == ACT_WALK
      || m_eCurrentMainSequenceActivity == ACT_JUMP
      || m_eCurrentMainSequenceActivity == ACT_RUNTOIDLE
      || m_eCurrentMainSequenceActivity == ACT_RUN_CROUCH;
}

//------------------------------------------------------------------------------
// Address: 0x10009E00
// Name: public: virtual int CBasePlayerAnimState::SelectWeightedSequence(enum Activity)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBasePlayerAnimState::SelectWeightedSequence(CBasePlayerAnimState *this, Activity activity)
{
  return C_BaseAnimating::SelectWeightedSequence(this: this->m_pOuter, activity);
}

//------------------------------------------------------------------------------
// Address: 0x10009E10
// Name: public: class Vector Vector::operator*(float)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector::operator*(Vector *this, Vector *result, float fl)
{
  result->x = this->x * fl;
  result->y = this->y * fl;
  result->z = this->z * fl;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10009E50
// Name: class C_BasePlayer __near * ToBasePlayer(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
C_CSPlayer *__cdecl ToBasePlayer(C_BaseEntity *pEntity)
{
  if ( pEntity != nullptr && pEntity->IsPlayer(this: pEntity) )
    return (C_CSPlayer *)pEntity;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10009E80
// Name: float clamp<float,float,float>(float const __near &,float const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl clamp<float,float,float>(const float *val, const float *minVal, const float *maxVal)
{
  if ( *minVal > *val )
    return *minVal;
  if ( *val <= *maxVal )
    return *val;
  return *maxVal;
}

//------------------------------------------------------------------------------
// Address: 0x10009ED0
// Name: float clamp<float,int,int>(float const __near &,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl clamp<float,int,int>(float *val, const int *minVal, const int *maxVal)
{
  float v3; // xmm1_4
  float vala; // [esp+8h] [ebp+8h]

  v3 = (float)*minVal;
  vala = *val;
  if ( v3 > vala )
    return v3;
  if ( vala <= (float)*maxVal )
    return vala;
  return (float)*maxVal;
}

//------------------------------------------------------------------------------
// Address: 0x10009F20
// Name: public: virtual bool CBasePlayerAnimState::ShouldUpdateAnimState(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBasePlayerAnimState::ShouldUpdateAnimState(CBasePlayerAnimState *this)
{
  return this->m_pOuter->IsAlive(this: this->m_pOuter);
}

//------------------------------------------------------------------------------
// Address: 0x10009F30
// Name: public: void CBasePlayerAnimState::RestartMainSequence(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayerAnimState::RestartMainSequence(CBasePlayerAnimState *this)
{
  C_BaseAnimatingOverlay *m_pOuter; // ecx

  m_pOuter = this->m_pOuter;
  m_pOuter->m_flAnimTime = *(float *)(gpGlobals.m_Index + 12);
  C_BaseAnimating::SetCycle(this: m_pOuter, flCycle: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10009F50
// Name: private: void CBasePlayerAnimState::ComputeMainSequence(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayerAnimState::ComputeMainSequence(CBasePlayerAnimState *this)
{
  Activity v2; // eax
  CBasePlayerAnimState_vtbl *v3; // ebx
  Activity (__thiscall *TranslateActivity)(CBasePlayerAnimState *, Activity); // edx
  Activity v5; // edi
  int v6; // eax
  int v7; // eax
  Activity oldActivity; // [esp+Ch] [ebp-8h]
  C_BaseAnimatingOverlay *pPlayer; // [esp+10h] [ebp-4h]

  pPlayer = this->m_pOuter;
  v2 = this->CalcMainActivity(this);
  v3 = this->__vftable;
  TranslateActivity = this->TranslateActivity;
  v5 = v2;
  oldActivity = this->m_eCurrentMainSequenceActivity;
  this->m_eCurrentMainSequenceActivity = v2;
  v6 = TranslateActivity(this, a2: v2);
  v7 = v3->SelectWeightedSequence(this, a2: (Activity)v6);
  if ( v7 < 0 )
    v7 = 0;
  C_BaseAnimating::SetSequence(this: pPlayer, nSequence: v7);
  C_BaseAnimating::ResetSequenceInfo(this: pPlayer);
  if ( this->ShouldResetGroundSpeed(this, a2: oldActivity, a3: v5) )
    this->ResetGroundSpeed(this);
}

//------------------------------------------------------------------------------
// Address: 0x10009FC0
// Name: private: virtual bool CBasePlayerAnimState::ShouldResetMainSequence(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBasePlayerAnimState::ShouldResetMainSequence(
        CBasePlayerAnimState *this,
        int iCurrentSequence,
        int iNewSequence)
{
  C_BaseAnimatingOverlay *m_pOuter; // esi
  int SequenceActivity; // edi

  if ( this->m_pOuter == nullptr )
    return false;
  m_pOuter = this->m_pOuter;
  SequenceActivity = C_BaseAnimating::GetSequenceActivity(this: m_pOuter, iSequence: iCurrentSequence);
  return SequenceActivity == C_BaseAnimating::GetSequenceActivity(this: m_pOuter, iSequence: iNewSequence);
}

//------------------------------------------------------------------------------
// Address: 0x1000A000
// Name: public: virtual float CBasePlayerAnimState::CalcMovementPlaybackRate(bool __near *)
// Source: json
//------------------------------------------------------------------------------
double __userpurge CBasePlayerAnimState::CalcMovementPlaybackRate@<st0>(
        CBasePlayerAnimState *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        bool *bIsMoving)
{
  float v6; // xmm0_4
  int v7; // xmm1_4
  float v10; // [esp-1Ch] [ebp-2Ch]
  float v11[3]; // [esp-Ch] [ebp-1Ch] BYREF
  Vector vel; // [esp+0h] [ebp-10h]
  float retaddr; // [esp+10h] [ebp+0h]

  vel.y = a2;
  vel.z = retaddr;
  ((void (__thiscall *)(C_BaseAnimatingOverlay *, float *, int, int))this->m_pOuter->EstimateAbsVelocity)(
    a1: this->m_pOuter,
    a2: v11,
    a3,
    a4);
  v10 = fsqrt((float)(v11[1] * v11[1]) + (float)(v11[0] * v11[0]));
  *bIsMoving = false;
  vel.x = 1.0;
  if ( v10 > 0.5 && this->CanThePlayerMove(this) )
  {
    if ( this->m_flMaxGroundSpeed >= 0.001 )
    {
      v6 = v10 * 0.011764706;
      *(float *)&v7 = 0.0;
      if ( (float)(v10 * 0.011764706) < 0.0 || (*(float *)&v7 = 1.0, v6 > 1.0) )
        v6 = *(float *)&v7;
    }
    else
    {
      v6 = 0.0099999998;
    }
    vel.x = v6;
    *bIsMoving = true;
  }
  return vel.x;
}

//------------------------------------------------------------------------------
// Address: 0x1000A0F0
// Name: protected: virtual void CBasePlayerAnimState::ComputePoseParam_BodyPitch(class CStudioHdr __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayerAnimState::ComputePoseParam_BodyPitch(CBasePlayerAnimState *this, CStudioHdr *pStudioHdr)
{
  float m_flEyePitch; // xmm0_4
  int v4; // eax
  float flValue; // [esp+Ch] [ebp-4h]

  m_flEyePitch = this->m_flEyePitch;
  if ( m_flEyePitch > 180.0 )
    m_flEyePitch = m_flEyePitch - 360.0;
  if ( m_flEyePitch >= -90.0 )
  {
    if ( m_flEyePitch <= 90.0 )
      flValue = m_flEyePitch;
    else
      flValue = 90.0;
  }
  else
  {
    flValue = -90.0;
  }
  v4 = C_BaseAnimating::LookupPoseParameter(this: this->m_pOuter, pstudiohdr: pStudioHdr, szName: "body_pitch");
  if ( v4 >= 0 )
  {
    C_BaseAnimating::SetPoseParameter(this: this->m_pOuter, pStudioHdr, iParameter: v4, flValue);
    g_flLastBodyPitch = flValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A180
// Name: protected: virtual int CBasePlayerAnimState::ConvergeAngles(float,float,float,float,float __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBasePlayerAnimState::ConvergeAngles(
        CBasePlayerAnimState *this,
        float goal,
        float maxrate,
        float maxgap,
        float dt,
        float *current)
{
  int v7; // edi
  float v8; // xmm4_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float angle; // xmm1_4
  long double v16; // st7
  float v17; // xmm0_4
  float v18; // xmm0_4
  float maxmove; // [esp+10h] [ebp-4h]
  float anglediffabs; // [esp+28h] [ebp+14h]
  float anglediff; // [esp+2Ch] [ebp+18h]
  float anglediffa; // [esp+2Ch] [ebp+18h]
  float anglediffb; // [esp+2Ch] [ebp+18h]

  v7 = 0;
  anglediff = AngleNormalize(angle: goal - *current);
  v8 = anglediff;
  v9 = 1.0;
  LODWORD(v10) = LODWORD(anglediff) & _mask__AbsFloat_;
  if ( COERCE_FLOAT(LODWORD(anglediff) & _mask__AbsFloat_) <= 45.0 )
  {
    if ( (float)(v10 * 0.022222223) >= 0.0099999998 )
    {
      if ( (float)(v10 * 0.022222223) <= 1.0 )
        v9 = v10 * 0.022222223;
    }
    else
    {
      v9 = 0.0099999998;
    }
  }
  v11 = (float)(maxrate * dt) * v9;
  maxmove = v11;
  if ( v10 > maxgap )
  {
    v12 = v11 * 5.0;
    v13 = v10 - maxgap;
    if ( v12 <= v13 )
      v13 = v12;
    v14 = *current;
    if ( anglediff <= 0.0 )
      angle = v14 - v13;
    else
      angle = v14 + v13;
    *current = angle;
    anglediffa = AngleNormalize(angle);
    *current = anglediffa;
    v16 = AngleNormalize(angle: goal - anglediffa);
    anglediffb = v16;
    anglediffabs = fabs(v16);
    _Msg(a1: "jumped = %f\n", v13);
    v8 = anglediffb;
    v10 = anglediffabs;
    v11 = maxmove;
  }
  if ( v11 <= v10 )
  {
    v18 = *current;
    if ( v8 <= 0.0 )
    {
      v17 = v18 - v11;
      v7 = 2;
    }
    else
    {
      v17 = v18 + v11;
      v7 = 1;
    }
  }
  else
  {
    v17 = goal;
  }
  *current = v17;
  *current = AngleNormalize(angle: v17);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x1000A2F0
// Name: protected: virtual void CBasePlayerAnimState::ComputePoseParam_BodyYaw(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBasePlayerAnimState::ComputePoseParam_BodyYaw(
        CBasePlayerAnimState *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>)
{
  float y; // xmm0_4
  float v6; // xmm3_4
  float m_flEyeYaw; // xmm0_4
  __m128 m_flEyeYaw_low; // xmm0
  double v9; // xmm0_8
  double v10; // xmm0_8
  __m128 y_low; // xmm0
  double v12; // xmm0_8
  double v13; // xmm0_8
  float m_flMaxBodyYawDegrees; // xmm0_4
  float m_flGoalFeetYaw; // xmm1_4
  float v16; // xmm1_4
  float *p_m_flCurrentFeetYaw; // edi
  CBasePlayerAnimState_vtbl *v18; // eax
  float (__thiscall *GetFeetYawRate)(CBasePlayerAnimState *); // edx
  double v20; // st7
  float v21; // xmm0_4
  void (__thiscall *v22)(CBasePlayerAnimState *, _DWORD, _DWORD); // edx
  double v23; // st7
  float v25; // [esp+30h] [ebp-38h]
  Vector vFeetYaw; // [esp+3Ch] [ebp-2Ch] BYREF
  Vector vel; // [esp+48h] [ebp-20h]
  Vector vEyeYaw; // [esp+54h] [ebp-14h]
  float flDiff; // [esp+60h] [ebp-8h]
  float retaddr; // [esp+68h] [ebp+0h]

  vEyeYaw.z = a2;
  flDiff = retaddr;
  ((void (__thiscall *)(C_BaseAnimatingOverlay *, Vector *, int, int))this->m_pOuter->EstimateAbsVelocity)(
    a1: this->m_pOuter,
    a2: &vFeetYaw,
    a3,
    a4);
  y = vFeetYaw.y;
  v6 = fsqrt((float)(y * y) + (float)(vFeetYaw.x * vFeetYaw.x));
  if ( !this->m_bCurrentFeetYawInitialized )
  {
    m_flEyeYaw = this->m_flEyeYaw;
    this->m_flCurrentFeetYaw = m_flEyeYaw;
    this->m_flGoalFeetYaw = m_flEyeYaw;
    this->m_bCurrentFeetYawInitialized = true;
    this->m_flLastTurnTime = 0.0;
    goto LABEL_14;
  }
  if ( v6 > 0.5 )
  {
    if ( this->m_AnimConfig.m_LegAnimType >= (unsigned int)LEGANIM_GOLDSRC )
    {
      __libm_sse2_atan2();
      vEyeYaw.y = y * 57.29578;
      this->m_flGoalFeetYaw = y * 57.29578;
      m_flEyeYaw_low = (__m128)LODWORD(this->m_flEyeYaw);
      m_flEyeYaw_low.m128_f32[0] = m_flEyeYaw_low.m128_f32[0] * 0.017453292;
      LODWORD(vEyeYaw.x) = m_flEyeYaw_low.m128_i32[0];
      __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd(m_flEyeYaw_low));
      *(float *)&v9 = v9;
      vel.x = *(float *)&v9;
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(vEyeYaw.x)));
      *(float *)&v10 = v10;
      vel.y = *(float *)&v10;
      y_low = (__m128)LODWORD(vEyeYaw.y);
      y_low.m128_f32[0] = vEyeYaw.y * 0.017453292;
      vEyeYaw.x = vEyeYaw.y * 0.017453292;
      __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd(y_low));
      *(float *)&v12 = v12;
      v25 = *(float *)&v12;
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(vEyeYaw.x)));
      *(float *)&v13 = v13;
      if ( (float)((float)(*(float *)&v13 * vel.y) + (float)(v25 * vel.x)) < -0.01 )
        this->m_flGoalFeetYaw = vEyeYaw.y + 180.0;
      goto LABEL_14;
    }
LABEL_8:
    this->m_flGoalFeetYaw = this->m_flEyeYaw;
    goto LABEL_14;
  }
  if ( (float)(*(float *)(gpGlobals.m_Index + 12) - this->m_flLastTurnTime) > mp_facefronttime.m_pParent->m_Value.m_fValue )
    goto LABEL_8;
  vEyeYaw.x = AngleNormalize(angle: this->m_flGoalFeetYaw - this->m_flEyeYaw);
  m_flMaxBodyYawDegrees = this->m_AnimConfig.m_flMaxBodyYawDegrees;
  if ( COERCE_FLOAT(LODWORD(vEyeYaw.x) & _mask__AbsFloat_) > m_flMaxBodyYawDegrees )
  {
    m_flGoalFeetYaw = this->m_flGoalFeetYaw;
    if ( vEyeYaw.x <= 0.0 )
      v16 = m_flGoalFeetYaw + m_flMaxBodyYawDegrees;
    else
      v16 = m_flGoalFeetYaw - m_flMaxBodyYawDegrees;
    this->m_flGoalFeetYaw = v16;
  }
LABEL_14:
  vEyeYaw.x = AngleNormalize(angle: this->m_flGoalFeetYaw);
  this->m_flGoalFeetYaw = vEyeYaw.x;
  p_m_flCurrentFeetYaw = &this->m_flCurrentFeetYaw;
  if ( this->m_flCurrentFeetYaw != vEyeYaw.x )
  {
    v18 = this->__vftable;
    GetFeetYawRate = this->GetFeetYawRate;
    vEyeYaw.x = *(float *)(gpGlobals.m_Index + 16);
    v20 = ((double (__thiscall *)(CBasePlayerAnimState *, _DWORD, CBasePlayerAnimState_vtbl *, float *))GetFeetYawRate)(
            a1: this,
            a2: LODWORD(this->m_AnimConfig.m_flMaxBodyYawDegrees),
            a3: v18,
            a4: &this->m_flCurrentFeetYaw);
    v21 = this->m_flGoalFeetYaw;
    v22 = *(void (__thiscall **)(CBasePlayerAnimState *, _DWORD, _DWORD))(LODWORD(vEyeYaw.x) + 68);
    vEyeYaw.y = v20;
    v22(a1: this, a2: LODWORD(v21), a3: LODWORD(vEyeYaw.y));
    this->m_flLastTurnTime = *(float *)(gpGlobals.m_Index + 12);
  }
  vEyeYaw.y = AngleNormalize(angle: this->m_flEyeYaw - *p_m_flCurrentFeetYaw);
  v23 = *p_m_flCurrentFeetYaw;
  this->m_angRender.z = 0.0;
  this->m_angRender.y = v23;
  this->m_angRender.x = 0.0;
  ((void (__thiscall *)(CBasePlayerAnimState *))this->SetOuterBodyYaw)(a1: this);
  g_flLastBodyYaw = vEyeYaw.y;
}

//------------------------------------------------------------------------------
// Address: 0x1000A5B0
// Name: protected: float CBasePlayerAnimState::GetOuterXYSpeed(void)const
// Source: json
//------------------------------------------------------------------------------
double __usercall CBasePlayerAnimState::GetOuterXYSpeed@<st0>(CBasePlayerAnimState *this@<ecx>, int a2@<ebp>)
{
  float v3[3]; // [esp-Ch] [ebp-28h] BYREF
  int v4; // [esp+10h] [ebp-Ch]
  void *v5; // [esp+14h] [ebp-8h]
  void *retaddr; // [esp+1Ch] [ebp+0h]

  v4 = a2;
  v5 = retaddr;
  this->m_pOuter->EstimateAbsVelocity(this: this->m_pOuter, a2: (Vector *)v3);
  return fsqrt((float)(v3[0] * v3[0]) + (float)(v3[1] * v3[1]));
}

//------------------------------------------------------------------------------
// Address: 0x1000A620
// Name: public: void CBasePlayerAnimState::AnimStateLog(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CBasePlayerAnimState::AnimStateLog(CBasePlayerAnimState *this, char *pMsg, ...)
{
  ConVar *m_pParent; // eax
  int m_nValue; // ecx
  void *(__thiscall *Open)(IBaseFileSystem *, const char *, const char *, const char *); // eax
  char pDest[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list params; // [esp+1010h] [ebp+10h] BYREF

  va_start(params, pMsg);
  V_vsnprintf(pDest, maxLen: 4096, pFormat: pMsg, params);
  m_pParent = showanimstate_log.m_pParent;
  if ( showanimstate_log.m_pParent != nullptr )
  {
    m_nValue = showanimstate_log.m_pParent->m_Value.m_nValue;
    if ( m_nValue == 1 || m_nValue == 3 )
    {
      _Msg(a1: "%s", pDest);
      m_pParent = showanimstate_log.m_pParent;
    }
    if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue > 1 )
    {
      if ( (_S6 & 1) == 0 )
      {
        Open = filesystem->Open;
        _S6 |= 1u;
        hFile = Open(this: &filesystem->IBaseFileSystem, a2: "AnimStateClient.log", a3: "wt", a4: nullptr);
      }
      filesystem->FPrintf(this: filesystem, a2: hFile, a3: "%s", pDest);
      filesystem->Flush(this: &filesystem->IBaseFileSystem, a2: hFile);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A700
// Name: public: void CBasePlayerAnimState::AnimStatePrintf(int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CBasePlayerAnimState::AnimStatePrintf(CBasePlayerAnimState *this, int iLine, char *pMsg, ...)
{
  char pDest[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list params; // [esp+1014h] [ebp+14h] BYREF

  va_start(params, pMsg);
  V_vsnprintf(pDest, maxLen: 4096, pFormat: pMsg, params);
  engine->Con_NPrintf(this: engine, a2: iLine, a3: "%s", pDest);
  CBasePlayerAnimState::AnimStateLog(this, pMsg: "%s\n", pDest);
}

//------------------------------------------------------------------------------
// Address: 0x1000A760
// Name: public: void CBasePlayerAnimState::DebugShowAnimStateFull(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayerAnimState::DebugShowAnimStateFull(CBasePlayerAnimState *this, int iStartLine)
{
  CBasePlayerAnimState::AnimStateLog(
    this,
    pMsg: "----------------- frame %d -----------------\n",
    *(_DWORD *)(gpGlobals.m_Index + 4));
  this->DebugShowAnimState(this, a2: iStartLine);
  CBasePlayerAnimState::AnimStateLog(this, pMsg: "--------------------------------------------\n\n");
}

//------------------------------------------------------------------------------
// Address: 0x1000A7A0
// Name: public: virtual float CBasePlayerAnimState::GetFeetYawRate(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBasePlayerAnimState::GetFeetYawRate(CBasePlayerAnimState *this)
{
  return mp_feetyawrate.m_pParent->m_Value.m_fValue;
}

//------------------------------------------------------------------------------
// Address: 0x1000A810
// Name: public: float C_BaseAnimating::GetPlaybackRate(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseAnimating::GetPlaybackRate(C_BaseAnimating *this)
{
  float v1; // xmm0_4

  v1 = 1.0 - this->m_flFrozen;
  if ( v1 < 0.0 )
    return this->m_flPlaybackRate * 0.0;
  if ( v1 <= 1.0 )
    return this->m_flPlaybackRate * v1;
  return this->m_flPlaybackRate * 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1000AA80
// Name: private: void CBasePlayerAnimState::UpdateAimSequenceLayers(float,int,bool,class CSequenceTransitioner __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBasePlayerAnimState::UpdateAimSequenceLayers(
        CBasePlayerAnimState *this@<ecx>,
        int a2@<edi>,
        float flCycle,
        int iFirstLayer,
        int bForceIdle,
        CSequenceTransitioner *pTransitioner,
        float flWeightScale)
{
  int (__thiscall *CalcAimLayerSequence)(CBasePlayerAnimState *, float *, float *, bool); // edx
  int v9; // ebx
  C_BaseAnimatingOverlay *m_pOuter; // esi
  CStudioHdr *m_pStudioHdr; // esi
  CStudioHdr *v12; // eax
  C_BaseAnimatingOverlay *v13; // esi
  float v14; // xmm0_4
  bool v15; // zf
  float flCurPlaybackRate; // xmm1_4
  CStudioHdr *v17; // esi
  CStudioHdr *v18; // eax
  int v19; // ebx
  C_AnimationLayer *AnimOverlay; // eax
  C_BaseAnimatingOverlay *v21; // ecx
  C_AnimationLayer *v22; // esi
  C_AnimationLayer *v23; // edi
  int m_Size; // eax
  C_AnimationLayer *m_pMemory; // eax
  float m_Val; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  int v29; // xmm1_4
  float flAimSequenceWeight; // [esp+24h] [ebp-4h] BYREF

  flAimSequenceWeight = *(float *)&this;
  CalcAimLayerSequence = this->CalcAimLayerSequence;
  flAimSequenceWeight = 1.0;
  v9 = ((int (__thiscall *)(CBasePlayerAnimState *, float *, float *, int, int))CalcAimLayerSequence)(
         a1: this,
         a2: &flCycle,
         a3: &flAimSequenceWeight,
         a4: bForceIdle,
         a5: a2);
  if ( v9 == -1 )
    v9 = 0;
  m_pOuter = this->m_pOuter;
  if ( m_pOuter->m_pStudioHdr == nullptr && m_pOuter->GetModel(this: &m_pOuter->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this: m_pOuter);
  m_pStudioHdr = m_pOuter->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
    v12 = m_pStudioHdr;
  else
    v12 = nullptr;
  CSequenceTransitioner::CheckForSequenceChange(
    this: pTransitioner,
    hdr: v12,
    nCurSequence: v9,
    bForceNewSequence: false,
    bInterpolate: true);
  v13 = this->m_pOuter;
  v14 = 1.0 - v13->m_flFrozen;
  if ( v14 >= 0.0 )
  {
    if ( v14 > 1.0 )
      v14 = 1.0;
  }
  else
  {
    v14 = 0.0;
  }
  v15 = v13->m_pStudioHdr == nullptr;
  flCurPlaybackRate = v13->m_flPlaybackRate * v14;
  *(float *)&bForceIdle = flCurPlaybackRate;
  if ( v15 )
  {
    if ( v13->GetModel(this: &v13->IClientRenderable) != nullptr )
      C_BaseAnimating::LockStudioHdr(this: v13);
    flCurPlaybackRate = *(float *)&bForceIdle;
  }
  v17 = v13->m_pStudioHdr;
  if ( v17 != nullptr && v17->m_pStudioHdr != nullptr )
    v18 = v17;
  else
    v18 = nullptr;
  CSequenceTransitioner::UpdateCurrent(
    this: pTransitioner,
    hdr: v18,
    nCurSequence: v9,
    flCurCycle: flCycle,
    flCurPlaybackRate,
    flCurTime: *(float *)(gpGlobals.m_Index + 12));
  v19 = iFirstLayer;
  AnimOverlay = C_BaseAnimatingOverlay::GetAnimOverlay(this: this->m_pOuter, i: iFirstLayer);
  v21 = this->m_pOuter;
  v22 = AnimOverlay;
  bForceIdle = v19 + 1;
  v23 = C_BaseAnimatingOverlay::GetAnimOverlay(this: v21, i: v19 + 1);
  m_Size = pTransitioner->m_animationQueue.m_Size;
  if ( m_Size == 1 )
  {
    *v22 = *pTransitioner->m_animationQueue.m_Memory.m_pMemory;
    C_AnimationLayer::SetWeight(this: v22, flWeight: 1.0);
    C_AnimationLayer::SetWeight(this: v23, flWeight: 0.0);
    C_AnimationLayer::SetOrder(this: v22, order: v19);
  }
  else if ( m_Size >= 2 )
  {
    m_pMemory = pTransitioner->m_animationQueue.m_Memory.m_pMemory;
    *v22 = *pTransitioner->m_animationQueue.m_Memory.m_pMemory;
    *v23 = m_pMemory[1];
    C_AnimationLayer::SetWeight(this: v23, flWeight: 1.0 - v22->m_flWeight.m_Val);
    C_AnimationLayer::SetOrder(this: v22, order: v19);
    C_AnimationLayer::SetOrder(this: v23, order: bForceIdle);
  }
  C_AnimationLayer::SetWeight(this: v22, flWeight: (float)(v22->m_flWeight.m_Val * flWeightScale) * flAimSequenceWeight);
  m_Val = v22->m_flWeight.m_Val;
  v27 = 0.0;
  if ( m_Val >= 0.0 )
  {
    v27 = 1.0;
    if ( m_Val <= 1.0 )
      v27 = v22->m_flWeight.m_Val;
  }
  C_AnimationLayer::SetWeight(this: v22, flWeight: v27);
  C_AnimationLayer::SetWeight(this: v23, flWeight: (float)(v23->m_flWeight.m_Val * flWeightScale) * flAimSequenceWeight);
  v28 = v23->m_flWeight.m_Val;
  *(float *)&v29 = 0.0;
  if ( v28 < 0.0 || (*(float *)&v29 = 1.0, v28 > 1.0) )
    v28 = *(float *)&v29;
  C_AnimationLayer::SetWeight(this: v23, flWeight: v28);
  C_AnimationLayer::SetCycle(this: v22, flCycle);
  C_AnimationLayer::SetCycle(this: v23, flCycle);
}

//------------------------------------------------------------------------------
// Address: 0x1000AD80
// Name: private: void CBasePlayerAnimState::OptimizeLayerWeights(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayerAnimState::OptimizeLayerWeights(CBasePlayerAnimState *this, int iFirstLayer, int nLayers)
{
  int v3; // esi
  C_AnimationLayer *AnimOverlay; // ebx
  float m_Val; // xmm0_4
  C_AnimationLayer *v7; // esi
  float flWeight; // xmm0_4
  int v9; // esi
  C_AnimationLayer *v10; // ebx
  int i; // esi
  C_AnimationLayer *v12; // eax
  float iLastOne; // [esp+10h] [ebp-4h]
  int iLastOnea; // [esp+10h] [ebp-4h]

  v3 = 1;
  for ( iLastOne = 0.0; v3 < nLayers; ++v3 )
  {
    AnimOverlay = C_BaseAnimatingOverlay::GetAnimOverlay(this: this->m_pOuter, i: v3 + iFirstLayer);
    if ( C_AnimationLayer::IsActive(this: AnimOverlay) )
    {
      m_Val = AnimOverlay->m_flWeight.m_Val;
      if ( m_Val > 0.0 )
        iLastOne = m_Val + iLastOne;
    }
  }
  v7 = C_BaseAnimatingOverlay::GetAnimOverlay(this: this->m_pOuter, i: iFirstLayer);
  if ( C_AnimationLayer::IsActive(this: v7) && v7->m_flWeight.m_Val > 0.0 )
  {
    flWeight = 1.0 - iLastOne;
    if ( (float)(1.0 - iLastOne) <= 0.0 )
      flWeight = 0.0;
    C_AnimationLayer::SetWeight(this: v7, flWeight);
  }
  v9 = 0;
  iLastOnea = -1;
  if ( nLayers > 0 )
  {
    do
    {
      v10 = C_BaseAnimatingOverlay::GetAnimOverlay(this: this->m_pOuter, i: v9 + iFirstLayer);
      if ( C_AnimationLayer::IsActive(this: v10) && v10->m_flWeight.m_Val > 0.99 )
        iLastOnea = v9;
      ++v9;
    }
    while ( v9 < nLayers );
    if ( iLastOnea != -1 )
    {
      for ( i = iLastOnea - 1; i >= 0; --i )
      {
        v12 = C_BaseAnimatingOverlay::GetAnimOverlay(this: this->m_pOuter, i: i + iFirstLayer);
        C_AnimationLayer::SetOrder(this: v12, order: 15);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AEA0
// Name: private: void CBasePlayerAnimState::ComputeAimSequence(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBasePlayerAnimState::ComputeAimSequence(CBasePlayerAnimState *this@<ecx>, int a2@<edi>)
{
  bool (__thiscall *ShouldBlendAimSequenceToIdle)(CBasePlayerAnimState *); // eax
  float flCycle; // [esp+1Ch] [ebp-Ch]
  float flPlaybackRate; // [esp+20h] [ebp-8h]
  bool bIsMoving; // [esp+27h] [ebp-1h] BYREF

  ShouldBlendAimSequenceToIdle = this->ShouldBlendAimSequenceToIdle;
  flCycle = this->m_pOuter->m_flCycle.m_Val;
  bIsMoving = false;
  flPlaybackRate = 0.0;
  if ( ShouldBlendAimSequenceToIdle(this) )
    flPlaybackRate = this->CalcMovementPlaybackRate(this, a2: &bIsMoving);
  CBasePlayerAnimState::UpdateAimSequenceLayers(
    this,
    a2,
    flCycle,
    iFirstLayer: 1,
    bForceIdle: 1,
    pTransitioner: &this->m_IdleSequenceTransitioner,
    flWeightScale: 1.0 - flPlaybackRate);
  if ( bIsMoving )
    CBasePlayerAnimState::UpdateAimSequenceLayers(
      this,
      a2,
      flCycle,
      iFirstLayer: 3,
      bForceIdle: 0,
      pTransitioner: &this->m_SequenceTransitioner,
      flWeightScale: flPlaybackRate);
  CBasePlayerAnimState::OptimizeLayerWeights(this, iFirstLayer: 1, nLayers: 4);
}

//------------------------------------------------------------------------------
// Address: 0x1000AF50
// Name: public: virtual float CBasePlayerAnimState::SetOuterBodyYaw(float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBasePlayerAnimState::SetOuterBodyYaw(CBasePlayerAnimState *this, float flValue)
{
  C_BaseAnimatingOverlay *m_pOuter; // esi
  CStudioHdr *m_pStudioHdr; // eax
  int v5; // edi
  C_BaseAnimatingOverlay *v7; // esi
  CStudioHdr *v8; // eax

  m_pOuter = this->m_pOuter;
  if ( m_pOuter->m_pStudioHdr == nullptr && m_pOuter->GetModel(this: &m_pOuter->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this: m_pOuter);
  m_pStudioHdr = m_pOuter->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  v5 = C_BaseAnimating::LookupPoseParameter(this: m_pOuter, pstudiohdr: m_pStudioHdr, szName: "body_yaw");
  if ( v5 < 0 )
    return 0.0;
  v7 = this->m_pOuter;
  if ( v7->m_pStudioHdr == nullptr && v7->GetModel(this: &v7->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this: v7);
  v8 = v7->m_pStudioHdr;
  if ( v8 == nullptr || v8->m_pStudioHdr == nullptr )
    v8 = nullptr;
  C_BaseAnimating::SetPoseParameter(this: v7, pStudioHdr: v8, iParameter: v5, flValue);
  return flValue;
}

//------------------------------------------------------------------------------
// Address: 0x1000B000
// Name: public: virtual void CBasePlayerAnimState::DebugShowAnimState(int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
// positive sp value has been detected, the output may be wrong!
void __userpurge CBasePlayerAnimState::DebugShowAnimState(
        CBasePlayerAnimState *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        int iStartLine)
{
  C_BaseAnimatingOverlay *m_pOuter; // eax
  float v7; // xmm0_4
  C_BaseAnimatingOverlay *v8; // edi
  bool v9; // zf
  float v10; // ecx
  CStudioHdr *m_pStudioHdr; // edi
  C_BaseAnimatingOverlay *v12; // edi
  int m_nSequence; // ecx
  CStudioHdr *v14; // edi
  float y; // eax
  C_BaseAnimatingOverlay *v16; // ecx
  float (__thiscall *GetSequenceCycleRate)(C_BaseAnimating *, CStudioHdr *, int); // edx
  char *SequenceName; // eax
  QAngle *v19; // edi
  C_AnimationLayer *AnimOverlay; // eax
  float v21; // xmm0_4
  C_BaseAnimatingOverlay *v22; // edi
  float v23; // eax
  CStudioHdr *v24; // edi
  int y_low; // ecx
  char *v26; // eax
  int v27; // edi
  C_BaseAnimatingOverlay *v28; // ecx
  C_BaseAnimatingOverlay *v29; // ecx
  C_AnimationLayer *v30; // edi
  float v31; // xmm0_4
  float v32; // xmm0_4
  char *SequenceActivityName; // eax
  C_BaseAnimatingOverlay *v34; // edi
  CStudioHdr *v35; // edi
  C_BaseAnimatingOverlay *v36; // edi
  CStudioHdr *v37; // edi
  int v38; // edi
  C_BaseAnimatingOverlay *v39; // ecx
  int v40; // edi
  C_BaseAnimatingOverlay *v41; // edi
  CStudioHdr *v42; // eax
  double SequenceGroundSpeed; // st7
  int v44; // edi
  __int128 v45; // xmm0
  int v46; // edi
  int v47; // eax
  float v48; // xmm0_4
  float v49; // xmm5_4
  float v50; // xmm2_4
  float v51; // xmm3_4
  float v52; // xmm6_4
  float v53; // xmm5_4
  Vector v55; // [esp+30h] [ebp-B0h] BYREF
  float v56[3]; // [esp+3Ch] [ebp-A4h] BYREF
  Vector vUp; // [esp+48h] [ebp-98h] BYREF
  Vector vOuterVel; // [esp+54h] [ebp-8Ch] BYREF
  QAngle angles; // [esp+60h] [ebp-80h] BYREF
  Vector v60; // [esp+6Ch] [ebp-74h] BYREF
  __int128 vRight; // [esp+78h] [ebp-68h] OVERLAPPED BYREF
  int v62; // [esp+90h] [ebp-50h]
  float v63[2]; // [esp+94h] [ebp-4Ch] BYREF
  float v64; // [esp+9Ch] [ebp-44h]
  int m_nOrder; // [esp+A0h] [ebp-40h]
  float m_Val; // [esp+A4h] [ebp-3Ch]
  _BYTE v67[24]; // [esp+A8h] [ebp-38h]
  Vector vBasePos; // [esp+C0h] [ebp-20h] BYREF
  int v69; // [esp+CCh] [ebp-14h]
  int iLine; // [esp+D0h] [ebp-10h]
  int i; // [esp+D4h] [ebp-Ch]
  QAngle *p_angles; // [esp+D8h] [ebp-8h]
  Vector *v73; // [esp+DCh] [ebp-4h]

  vBasePos.z = a2;
  v69 = i;
  ((void (__thiscall *)(C_BaseAnimatingOverlay *, float *, int, int, _DWORD, _DWORD, _DWORD))this->m_pOuter->EstimateAbsVelocity)(
    a1: this->m_pOuter,
    a2: v56,
    a3,
    a4,
    a5: LODWORD(v55.x),
    a6: LODWORD(v55.y),
    a7: LODWORD(v55.z));
  m_pOuter = this->m_pOuter;
  v7 = 1.0 - m_pOuter->m_flFrozen;
  if ( v7 >= 0.0 )
  {
    if ( v7 > 1.0 )
      v7 = 1.0;
  }
  else
  {
    v7 = 0.0;
  }
  v8 = this->m_pOuter;
  v9 = m_pOuter->m_pStudioHdr == nullptr;
  v10 = *(float *)&m_pOuter->m_nSequence;
  vBasePos.x = m_pOuter->m_flPlaybackRate * v7;
  vBasePos.y = v10;
  if ( v9 && m_pOuter->GetModel(this: &v8->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this: v8);
  m_pStudioHdr = v8->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || (v9 = m_pStudioHdr->m_pStudioHdr == nullptr, *(_DWORD *)&v67[20] = m_pStudioHdr, v9) )
    *(_DWORD *)&v67[20] = 0;
  v12 = this->m_pOuter;
  v9 = v12->m_pStudioHdr == nullptr;
  m_nSequence = v12->m_nSequence;
  m_Val = v12->m_flCycle.m_Val;
  m_nOrder = m_nSequence;
  if ( v9 && v12->GetModel(this: &v12->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this: v12);
  v14 = v12->m_pStudioHdr;
  if ( v14 == nullptr || v14->m_pStudioHdr == nullptr )
    v14 = nullptr;
  y = vBasePos.y;
  v16 = this->m_pOuter;
  GetSequenceCycleRate = v16->GetSequenceCycleRate;
  *(double *)&vBasePos.x = vBasePos.x;
  *(double *)&v67[16] = ((double (__thiscall *)(C_BaseAnimatingOverlay *, _DWORD, _DWORD))GetSequenceCycleRate)(
                          a1: v16,
                          a2: LODWORD(y),
                          a3: LODWORD(y));
  *(double *)&v67[8] = m_Val;
  *(_DWORD *)&v67[4] = m_nOrder;
  SequenceName = GetSequenceName(pstudiohdr: v14, iSequence: m_nOrder);
  v19 = p_angles;
  CBasePlayerAnimState::AnimStatePrintf(
    this,
    iLine: (int)p_angles,
    pMsg: "main: %s(%d), cycle: %.2f cyclerate: %.2f playbackrate: %.2f\n",
    SequenceName,
    *(_DWORD *)&v67[4],
    *(double *)&v67[8],
    *(double *)&v67[16],
    *(double *)&vBasePos.x);
  v9 = this->m_AnimConfig.m_LegAnimType == LEGANIM_8WAY;
  *(_DWORD *)&v67[16] = (char *)&v19->x + 1;
  if ( v9 )
  {
    AnimOverlay = C_BaseAnimatingOverlay::GetAnimOverlay(this: this->m_pOuter, i: 0);
    v21 = AnimOverlay->m_flWeight.m_Val;
    v22 = this->m_pOuter;
    v9 = v22->m_pStudioHdr == nullptr;
    v23 = *(float *)&AnimOverlay->m_nSequence.m_Val;
    vBasePos.x = v21;
    vBasePos.y = v23;
    if ( v9 && v22->GetModel(this: &v22->IClientRenderable) != nullptr )
      C_BaseAnimating::LockStudioHdr(this: v22);
    v24 = v22->m_pStudioHdr;
    if ( v24 == nullptr || v24->m_pStudioHdr == nullptr )
      v24 = nullptr;
    y_low = LODWORD(vBasePos.y);
    *(double *)&vBasePos.x = vBasePos.x;
    v26 = GetSequenceName(pstudiohdr: v24, iSequence: y_low);
    v27 = *(_DWORD *)&v67[16];
    CBasePlayerAnimState::AnimStatePrintf(
      this,
      iLine: *(int *)&v67[16],
      pMsg: "idle: %s, weight: %.2f\n",
      v26,
      *(double *)&vBasePos.x);
    *(_DWORD *)&v67[16] = v27 + 1;
  }
  v28 = this->m_pOuter;
  *(_DWORD *)&v67[20] = 0;
  if ( C_BaseAnimatingOverlay::GetNumAnimOverlays(this: v28) - 1 > 0 )
  {
    do
    {
      v29 = this->m_pOuter;
      *(_DWORD *)&v67[12] = *(_DWORD *)&v67[20] + 1;
      v30 = C_BaseAnimatingOverlay::GetAnimOverlay(this: v29, i: *(_DWORD *)&v67[20] + 1);
      if ( C_AnimationLayer::IsActive(this: v30) )
        m_nOrder = v30->m_nOrder;
      else
        m_nOrder = 0;
      if ( C_AnimationLayer::IsActive(this: v30) )
        v31 = v30->m_flCycle.m_Val;
      else
        v31 = 0.0;
      m_Val = v31;
      if ( C_AnimationLayer::IsActive(this: v30) )
        v32 = v30->m_flWeight.m_Val;
      else
        v32 = 0.0;
      vBasePos.y = v32;
      if ( C_AnimationLayer::IsActive(this: v30) )
        LODWORD(vBasePos.x) = v30->m_nSequence.m_Val;
      else
        vBasePos.x = 0.0;
      if ( C_AnimationLayer::IsActive(this: v30) )
      {
        v62 = v30->m_nSequence.m_Val;
        if ( v62 != 0 )
        {
          if ( showanimstate_activities.m_pParent != nullptr
            && showanimstate_activities.m_pParent->m_Value.m_nValue != 0 )
          {
            v34 = this->m_pOuter;
            if ( v34->m_pStudioHdr == nullptr && v34->GetModel(this: &v34->IClientRenderable) != nullptr )
              C_BaseAnimating::LockStudioHdr(this: v34);
            v35 = v34->m_pStudioHdr;
            if ( v35 == nullptr || v35->m_pStudioHdr == nullptr )
              v35 = nullptr;
            SequenceActivityName = GetSequenceActivityName(pstudiohdr: v35, iSequence: v62);
          }
          else
          {
            v36 = this->m_pOuter;
            if ( v36->m_pStudioHdr == nullptr && v36->GetModel(this: &v36->IClientRenderable) != nullptr )
              C_BaseAnimating::LockStudioHdr(this: v36);
            v37 = v36->m_pStudioHdr;
            if ( v37 == nullptr || v37->m_pStudioHdr == nullptr )
              v37 = nullptr;
            SequenceActivityName = GetSequenceName(pstudiohdr: v37, iSequence: v62);
          }
        }
        else
        {
          SequenceActivityName = "-- ";
        }
      }
      else
      {
        SequenceActivityName = "-- ";
      }
      v38 = *(_DWORD *)&v67[16];
      CBasePlayerAnimState::AnimStatePrintf(
        this,
        iLine: *(int *)&v67[16],
        pMsg: "%s(%d), weight: %.2f, cycle: %.2f, order (%d), aim (%d)",
        SequenceActivityName,
        vBasePos.x,
        *(float *)&v67[20],
        m_Val,
        m_nOrder,
        *(_DWORD *)&v67[20]);
      v39 = this->m_pOuter;
      *(_DWORD *)&v67[16] = v38 + 1;
      v40 = *(_DWORD *)&v67[12];
      *(_DWORD *)&v67[20] = *(_DWORD *)&v67[12];
    }
    while ( v40 < C_BaseAnimatingOverlay::GetNumAnimOverlays(this: v39) - 1 );
  }
  v41 = this->m_pOuter;
  v9 = v41->m_pStudioHdr == nullptr;
  *(_DWORD *)&v67[12] = v41->m_nSequence;
  if ( v9 && v41->GetModel(this: &v41->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this: v41);
  v42 = v41->m_pStudioHdr;
  if ( v42 == nullptr || v42->m_pStudioHdr == nullptr )
    v42 = nullptr;
  SequenceGroundSpeed = C_BaseAnimating::GetSequenceGroundSpeed(
                          this: v41,
                          a2: (int)&vBasePos.z,
                          pStudioHdr: v42,
                          iSequence: *(int *)&v67[12]);
  v44 = *(_DWORD *)&v67[16];
  *(float *)&v67[12] = v56[1] * v56[1];
  v45 = 0;
  *(float *)&v45 = fsqrt((float)(v56[1] * v56[1]) + (float)(v56[0] * v56[0]));
  vRight = v45;
  CBasePlayerAnimState::AnimStatePrintf(
    this,
    iLine: *(int *)&v67[16],
    pMsg: "vel: %.2f, time: %.2f, max: %.2f, animspeed: %.2f",
    *(float *)&v45,
    *(float *)(gpGlobals.m_Index + 12),
    this->m_flMaxGroundSpeed,
    SequenceGroundSpeed);
  v46 = v44 + 1;
  if ( this->m_AnimConfig.m_LegAnimType == LEGANIM_8WAY )
  {
    *(double *)&vBasePos.x = g_flLastBodyPitch;
    *(double *)&v67[16] = this->m_flGaitYaw;
    *(double *)&v67[8] = m_flLastMoveYaw;
    *(double *)v67 = g_flLastBodyYaw;
    CBasePlayerAnimState::AnimStatePrintf(
      this,
      iLine: v46,
      pMsg: "ent yaw: %.2f, body_yaw: %.2f, move_yaw: %.2f, gait_yaw: %.2f, body_pitch: %.2f",
      this->m_angRender.y,
      (unsigned int)COERCE_UNSIGNED_INT64(g_flLastBodyYaw),
      *(_QWORD *)&v67[4],
      *(_QWORD *)&v67[12],
      *(_DWORD *)&v67[20],
      vBasePos.x,
      vBasePos.y);
  }
  else
  {
    *(double *)&vBasePos.x = this->m_vLastMovePose.y;
    *(double *)&v67[16] = this->m_vLastMovePose.x;
    *(double *)&v67[8] = g_flLastBodyPitch;
    *(double *)v67 = g_flLastBodyYaw;
    CBasePlayerAnimState::AnimStatePrintf(
      this,
      iLine: v46,
      pMsg: "ent yaw: %.2f, body_yaw: %.2f, body_pitch: %.2f, move_x: %.2f, move_y: %.2f",
      this->m_angRender.y,
      (unsigned int)COERCE_UNSIGNED_INT64(g_flLastBodyYaw),
      *(_QWORD *)&v67[4],
      *(_QWORD *)&v67[12],
      *(_DWORD *)&v67[20],
      vBasePos.x,
      vBasePos.y);
  }
  v47 = ((int (__thiscall *)(C_BaseAnimatingOverlay *, _DWORD, int, int, int, QAngle *, Vector *))this->m_pOuter->GetAbsOrigin)(
          a1: this->m_pOuter,
          a2: LODWORD(vBasePos.z),
          a3: v69,
          a4: iLine,
          a5: i,
          a6: p_angles,
          a7: v73);
  *(_DWORD *)v67 = *(_DWORD *)v47;
  *(_DWORD *)&v67[4] = *(_DWORD *)(v47 + 4);
  v48 = *(float *)(v47 + 8) + 3.0;
  v73 = &v55;
  p_angles = &angles;
  *(float *)&v67[8] = v48;
  i = (int)&v60;
  vUp.x = 0.0;
  vUp.z = 0.0;
  vUp.y = this->m_flEyeYaw;
  AngleVectors(angles: (const QAngle *)&vUp, forward: &v60, right: (Vector *)&angles, up: &v55);
  v63[1] = (float)(v60.y * 80.0) + *(float *)&v67[4];
  v64 = (float)(v60.z * 80.0) + *(float *)&v67[8];
  v63[0] = (float)(v60.x * 80.0) + *(float *)v67;
  *((float *)&vRight + 3) = (float)(angles.z * 10.0) * 0.5;
  vOuterVel.x = *(float *)v67 - (float)((float)(angles.x * 10.0) * 0.5);
  vOuterVel.y = *(float *)&v67[4] - (float)((float)(angles.y * 10.0) * 0.5);
  vOuterVel.z = *(float *)&v67[8] - *((float *)&vRight + 3);
  *((float *)&vRight + 1) = (float)((float)(angles.x * 10.0) * 0.5) + *(float *)v67;
  *((float *)&vRight + 2) = (float)((float)(angles.y * 10.0) * 0.5) + *(float *)&v67[4];
  *((float *)&vRight + 3) = *((float *)&vRight + 3) + *(float *)&v67[8];
  ((void (__thiscall *)(IVDebugOverlay *, char *, Vector *, float *, int, _DWORD, _DWORD, int, _DWORD, int))debugoverlay->AddTriangleOverlay)(
    a1: debugoverlay,
    a2: (char *)&vRight + 4,
    a3: &vOuterVel,
    a4: v63,
    a5: 255,
    a6: 0,
    a7: 0,
    a8: 255,
    a9: 0,
    a10: 1008981770);
  vUp.y = this->m_angRender.y;
  AngleVectors(angles: (const QAngle *)&vUp, forward: &v60, right: (Vector *)&angles, up: &v55);
  *((float *)&vRight + 2) = (float)(v60.y * 80.0) + *(float *)&v67[4];
  *((float *)&vRight + 3) = (float)(v60.z * 80.0) + *(float *)&v67[8];
  *((float *)&vRight + 1) = (float)(v60.x * 80.0) + *(float *)v67;
  v64 = (float)(angles.z * 10.0) * 0.5;
  v49 = (float)(angles.y * 10.0) * 0.5;
  v50 = v49 + *(float *)&v67[4];
  v51 = v64 + *(float *)&v67[8];
  *(_QWORD *)&v67[12] = 0x3C23D70A00000000LL;
  vOuterVel.x = *(float *)v67 - (float)((float)(angles.x * 10.0) * 0.5);
  v52 = *(float *)&v67[4] - v49;
  v53 = *(float *)&v67[8] - v64;
  *(_QWORD *)&v67[4] = 0xFF000000FFLL;
  vOuterVel.y = v52;
  vOuterVel.z = v53;
  v63[0] = (float)((float)(angles.x * 10.0) * 0.5) + *(float *)v67;
  v63[1] = v50;
  v64 = v51;
  ((void (__thiscall *)(IVDebugOverlay *, float *, Vector *, char *, _DWORD, _DWORD, int, int, _DWORD, int))debugoverlay->AddTriangleOverlay)(
    a1: debugoverlay,
    a2: v63,
    a3: &vOuterVel,
    a4: (char *)&vRight + 4,
    a5: 0,
    a6: 0,
    a7: 255,
    a8: 255,
    a9: 0,
    a10: 1008981770);
}

//------------------------------------------------------------------------------
// Address: 0x1000BE30
// Name: public: virtual void CBasePlayerAnimState::ComputeSequences(class CStudioHdr __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBasePlayerAnimState::ComputeSequences(
        CBasePlayerAnimState *this@<ecx>,
        int a2@<edi>,
        CStudioHdr *pStudioHdr)
{
  CBasePlayerAnimState::ComputeMainSequence(this);
  this->m_flMaxGroundSpeed = this->GetCurrentMaxGroundSpeed(this);
  if ( this->m_AnimConfig.m_bUseAimSequences )
    CBasePlayerAnimState::ComputeAimSequence(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x1000BE60
// Name: protected: virtual void CBasePlayerAnimState::ComputePoseParam_MoveYaw(class CStudioHdr __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBasePlayerAnimState::ComputePoseParam_MoveYaw(
        CBasePlayerAnimState *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        CStudioHdr *pStudioHdr)
{
  float v6; // xmm0_4
  float v7; // xmm0_4
  float m_flEyeYaw; // xmm0_4
  int v9; // xmm0_4
  int v10; // xmm0_4
  C_BaseAnimatingOverlay *m_pOuter; // ecx
  float v12; // eax
  C_BaseAnimatingOverlay *v13; // ecx
  int v14; // eax
  int v15; // ecx
  float v16; // xmm3_4
  __m128 v17; // xmm0
  double v18; // xmm0_8
  double v19; // xmm0_8
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  int v23; // eax
  C_AnimationLayer *AnimOverlay; // edi
  int v25; // eax
  C_BaseAnimatingOverlay *v26; // ecx
  Activity m_eCurrentMainSequenceActivity; // eax
  int m_Val; // eax
  double v29; // st7
  float angle; // [esp+10h] [ebp-50h]
  float anglea; // [esp+10h] [ebp-50h]
  float flWeighta; // [esp+18h] [ebp-48h]
  float v35; // [esp+34h] [ebp-2Ch] BYREF
  float v36; // [esp+38h] [ebp-28h]
  float v37; // [esp+3Ch] [ebp-24h]
  int m_Val_low; // [esp+40h] [ebp-20h]
  Vector2D vCurMovePose; // [esp+44h] [ebp-1Ch]
  int iMoveY; // [esp+4Ch] [ebp-14h]
  int iMoveX; // [esp+50h] [ebp-10h] BYREF
  float flPlaybackRate; // [esp+54h] [ebp-Ch]
  float flYaw; // [esp+58h] [ebp-8h]
  float retaddr; // [esp+60h] [ebp+0h]

  flPlaybackRate = a2;
  flYaw = retaddr;
  if ( this->m_AnimConfig.m_LegAnimType > (unsigned int)LEGANIM_8WAY )
    return;
  this->m_pOuter->EstimateAbsVelocity(this: this->m_pOuter, a2: (Vector *)&v35);
  v6 = v36;
  if ( fsqrt((float)(v6 * v6) + (float)(v35 * v35)) > 0.5 )
  {
    __libm_sse2_atan2();
    v7 = v6 * 57.29578;
    this->m_flGaitYaw = v7;
    this->m_flGaitYaw = AngleNormalize(angle: v7);
  }
  m_flEyeYaw = this->m_flEyeYaw;
  if ( m_flEyeYaw <= 180.0 )
  {
    if ( m_flEyeYaw < -180.0 )
      m_flEyeYaw = m_flEyeYaw + 360.0;
  }
  else
  {
    m_flEyeYaw = m_flEyeYaw - 360.0;
  }
  *(float *)&v9 = COERCE_FLOAT(COERCE_UNSIGNED_INT(m_flEyeYaw - this->m_flGaitYaw) ^ _mask__NegFloat_)
                - (float)(360
                        * (int)(float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(m_flEyeYaw - this->m_flGaitYaw) ^ _mask__NegFloat_)
                                     * 0.0027777778));
  iMoveY = v9;
  if ( *(float *)&v9 >= -180.0 )
  {
    if ( *(float *)&v9 <= 180.0 )
      goto LABEL_13;
    *(float *)&v10 = *(float *)&v9 - 360.0;
  }
  else
  {
    *(float *)&v10 = *(float *)&v9 + 360.0;
  }
  iMoveY = v10;
LABEL_13:
  m_pOuter = this->m_pOuter;
  if ( this->m_AnimConfig.m_LegAnimType != LEGANIM_9WAY )
  {
    v23 = C_BaseAnimating::LookupPoseParameter(this: m_pOuter, pstudiohdr: pStudioHdr, szName: "move_yaw");
    if ( v23 >= 0 )
    {
      C_BaseAnimating::SetPoseParameter(this: this->m_pOuter, pStudioHdr, iParameter: v23, flValue: *(float *)&iMoveY);
      LODWORD(m_flLastMoveYaw) = iMoveY;
      AnimOverlay = C_BaseAnimatingOverlay::GetAnimOverlay(this: this->m_pOuter, i: 0);
      flWeighta = 1.0
                - ((double (__thiscall *)(CBasePlayerAnimState *, char *, int, int))this->CalcMovementPlaybackRate)(
                    a1: this,
                    a2: (char *)&iMoveX + 3,
                    a3,
                    a4);
      C_AnimationLayer::SetWeight(this: AnimOverlay, flWeight: flWeighta);
      if ( HIBYTE(iMoveX) == 0 )
        C_AnimationLayer::SetWeight(this: AnimOverlay, flWeight: 1.0);
      if ( this->ShouldChangeSequences(this) )
      {
        if ( AnimOverlay->m_flWeight.m_Val < 0.02 || this->m_iCurrent8WayIdleSequence == -1 )
        {
          v25 = C_BaseAnimating::SelectWeightedSequence(this: this->m_pOuter, activity: 1);
          v26 = this->m_pOuter;
          this->m_iCurrent8WayIdleSequence = v25;
          this->m_iCurrent8WayCrouchIdleSequence = C_BaseAnimating::SelectWeightedSequence(this: v26, activity: 45);
        }
        m_eCurrentMainSequenceActivity = this->m_eCurrentMainSequenceActivity;
        if ( m_eCurrentMainSequenceActivity == ACT_CROUCHIDLE || m_eCurrentMainSequenceActivity == ACT_RUN_CROUCH )
          C_AnimationLayer::SetSequence(this: AnimOverlay, nSequence: this->m_iCurrent8WayCrouchIdleSequence);
        else
          C_AnimationLayer::SetSequence(this: AnimOverlay, nSequence: this->m_iCurrent8WayIdleSequence);
      }
      AnimOverlay->m_flPlaybackRate.m_Val = 1.0;
      m_Val = AnimOverlay->m_nSequence.m_Val;
      m_Val_low = SLODWORD(AnimOverlay->m_flCycle.m_Val);
      v29 = ((double (__thiscall *)(C_BaseAnimatingOverlay *, CStudioHdr *, int))this->m_pOuter->GetSequenceCycleRate)(
              a1: this->m_pOuter,
              a2: pStudioHdr,
              a3: m_Val);
      angle = v29 * *(float *)(gpGlobals.m_Index + 16) + *(float *)&m_Val_low;
      C_AnimationLayer::SetCycle(this: AnimOverlay, flCycle: angle);
      anglea = fmod(AnimOverlay->m_flCycle.m_Val, 1.0);
      C_AnimationLayer::SetCycle(this: AnimOverlay, flCycle: anglea);
      C_AnimationLayer::SetOrder(this: AnimOverlay, order: 0);
    }
  }
  else
  {
    v12 = COERCE_FLOAT(C_BaseAnimating::LookupPoseParameter(this: m_pOuter, pstudiohdr: pStudioHdr, szName: "move_x"));
    v13 = this->m_pOuter;
    vCurMovePose.x = v12;
    *(float *)&v14 = COERCE_FLOAT(C_BaseAnimating::LookupPoseParameter(this: v13, pstudiohdr: pStudioHdr, szName: "move_y"));
    m_Val_low = v14;
    if ( vCurMovePose.x >= 0.0 && v14 >= 0 )
    {
      vCurMovePose.y = ((double (__thiscall *)(CBasePlayerAnimState *, char *, int, int))this->CalcMovementPlaybackRate)(
                         a1: this,
                         a2: (char *)&iMoveX + 3,
                         a3,
                         a4);
      v16 = 0.0;
      v36 = 0.0;
      v37 = 0.0;
      if ( HIBYTE(iMoveX) != 0 )
      {
        v17 = (__m128)(unsigned int)iMoveY;
        *(float *)&iMoveY = *(float *)&iMoveY * 0.017453292;
        v17.m128_f32[0] = *(float *)&iMoveY;
        __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd(v17));
        *(float *)&v18 = v18;
        v36 = *(float *)&v18 * vCurMovePose.y;
        __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)(unsigned int)iMoveY));
        v16 = v36;
        *(float *)&v19 = v19;
        LODWORD(v20) = COERCE_UNSIGNED_INT(*(float *)&v19 * vCurMovePose.y) ^ _mask__NegFloat_;
        LODWORD(v21) = LODWORD(v36) & _mask__AbsFloat_;
        v37 = v20;
        if ( COERCE_FLOAT(LODWORD(v20) & _mask__AbsFloat_) > COERCE_FLOAT(LODWORD(v36) & _mask__AbsFloat_) )
          LODWORD(v21) = LODWORD(v20) & _mask__AbsFloat_;
        if ( v21 > 0.0099999998 )
        {
          v22 = (float)(1.0 / v21) * vCurMovePose.y;
          v16 = v36 * v22;
          v36 = v36 * v22;
          v37 = v22 * v20;
        }
      }
      iMoveY = v15;
      C_BaseAnimating::SetPoseParameter(
        this: this->m_pOuter,
        pStudioHdr,
        iParameter: SLODWORD(vCurMovePose.x),
        flValue: v16);
      C_BaseAnimating::SetPoseParameter(this: this->m_pOuter, pStudioHdr, iParameter: m_Val_low, flValue: v37);
      this->m_vLastMovePose.x = v36;
      this->m_vLastMovePose.y = v37;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CA00
// Name: public: virtual CBasePlayerAnimState::~CBasePlayerAnimState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayerAnimState::~CBasePlayerAnimState(CBasePlayerAnimState *this)
{
  int v2; // eax

  v2 = *(_DWORD *)this->gap4;
  this->__vftable = (CBasePlayerAnimState_vtbl *)&CBasePlayerAnimState::`vftable'{for `CBasePlayerAnimState'};
  *(_DWORD *)&this->gap4[*(_DWORD *)(v2 + 4)] = &CBasePlayerAnimState::`vftable'{for `IPlayerAnimState'};
  *(CBasePlayerAnimState_vtbl **)((char *)&this->__vftable + *(_DWORD *)(*(_DWORD *)this->gap4 + 4)) = (CBasePlayerAnimState_vtbl *)(*(_DWORD *)(*(_DWORD *)this->gap4 + 4) - 148);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_SequenceTransitioner);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_IdleSequenceTransitioner);
}

//------------------------------------------------------------------------------
// Address: 0x1000CA40
// Name: public: virtual enum Activity CBasePlayerAnimState::TranslateActivity(enum Activity)
// Source: json
//------------------------------------------------------------------------------
Activity __thiscall CBasePlayerAnimState::TranslateActivity(CBasePlayerAnimState *this, Activity actDesired)
{
  return actDesired;
}

//------------------------------------------------------------------------------
// Address: 0x1000CAF0
// Name: public: void CUtlDict<int,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<int,int>::RemoveAll(CUtlDict<int,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1000CB40
// Name: public: CBasePlayerAnimState::CBasePlayerAnimState(void)
// Source: json
//------------------------------------------------------------------------------
CBasePlayerAnimState *__thiscall CBasePlayerAnimState::CBasePlayerAnimState(CBasePlayerAnimState *this, int a2)
{
  CBasePlayerAnimState *result; // eax
  int v3; // edx

  result = this;
  if ( a2 != 0 )
  {
    *(_DWORD *)this->gap4 = &CBasePlayerAnimState::`vbtable';
    *(_DWORD *)&this->gap94[4] = &IPlayerAnimState::`vftable';
  }
  v3 = *(_DWORD *)this->gap4;
  this->__vftable = (CBasePlayerAnimState_vtbl *)&CBasePlayerAnimState::`vftable'{for `CBasePlayerAnimState'};
  *(_DWORD *)&this->gap4[*(_DWORD *)(v3 + 4)] = &CBasePlayerAnimState::`vftable'{for `IPlayerAnimState'};
  *(CBasePlayerAnimState_vtbl **)((char *)&this->__vftable + *(_DWORD *)(*(_DWORD *)this->gap4 + 4)) = (CBasePlayerAnimState_vtbl *)(*(_DWORD *)(*(_DWORD *)this->gap4 + 4) - 148);
  this->m_IdleSequenceTransitioner.m_animationQueue.m_Memory.m_pMemory = nullptr;
  this->m_IdleSequenceTransitioner.m_animationQueue.m_Memory.m_nAllocationCount = 0;
  this->m_IdleSequenceTransitioner.m_animationQueue.m_Memory.m_nGrowSize = 0;
  this->m_IdleSequenceTransitioner.m_animationQueue.m_Size = 0;
  this->m_IdleSequenceTransitioner.m_animationQueue.m_pElements = nullptr;
  this->m_SequenceTransitioner.m_animationQueue.m_Memory.m_pMemory = nullptr;
  this->m_SequenceTransitioner.m_animationQueue.m_Memory.m_nAllocationCount = 0;
  this->m_SequenceTransitioner.m_animationQueue.m_Memory.m_nGrowSize = 0;
  this->m_SequenceTransitioner.m_animationQueue.m_Size = 0;
  this->m_SequenceTransitioner.m_animationQueue.m_pElements = nullptr;
  this->m_flEyeYaw = 0.0;
  this->m_flEyePitch = 0.0;
  this->m_bCurrentFeetYawInitialized = false;
  this->m_flCurrentTorsoYaw = 0.0;
  this->m_flMaxGroundSpeed = 0.0;
  *(_QWORD *)&this->m_flGaitYaw = 0;
  this->m_flGoalFeetYaw = 0.0;
  this->m_flCurrentFeetYaw = 0.0;
  this->m_flLastYaw = 0.0;
  this->m_flLastTurnTime = 0.0;
  this->m_angRender.x = 0.0;
  this->m_angRender.y = 0.0;
  this->m_angRender.z = 0.0;
  this->m_vLastMovePose.x = 0.0;
  this->m_vLastMovePose.y = 0.0;
  this->m_iCurrent8WayIdleSequence = -1;
  this->m_iCurrent8WayCrouchIdleSequence = -1;
  this->m_pOuter = nullptr;
  this->m_eCurrentMainSequenceActivity = ACT_IDLE;
  this->m_flLastAnimationStateClearTime = 0.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000CC80
// Name: public: int CUtlMap<char const __near *,int,int>::Insert(char const __near * const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CUtlMap<char const *,int,int>::Insert@<eax>(
        CUtlMap<char const *,int,int> *this@<ecx>,
        const char *a2@<edi>,
        const char **key,
        int insert)
{
  int v5; // eax
  int v6; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,int,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v5 = *(_DWORD *)insert;
  node.key = *key;
  node.elem = v5;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v6 = CUtlRBTree<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int,CUtlMap<char const *,IViewPortPanel *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IViewPortPanel *,int>::Node_t,int>,int>>::NewNode(
         (CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)this,
         a2);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v6,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v6] != (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)-16 )
    m_pMemory[v6].m_Data = node;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1000CD00
// Name: public: int CUtlDict<int,int>::Insert(char const __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<int,int>::Insert(CUtlDict<int,int> *this, char *pName, const int *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,int,int>::Insert(
           this: &this->m_Elements,
           key: (const char *const *)&pName,
           insert: element);
}

//------------------------------------------------------------------------------
// Address: 0x1000CD60
// Name: protected: virtual int CBasePlayerAnimState::CalcSequenceIndex(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
int CBasePlayerAnimState::CalcSequenceIndex(CBasePlayerAnimState *this, const char *pBaseName, ...)
{
  int result; // eax
  char szFullName[512]; // [esp+0h] [ebp-208h] BYREF
  CUtlMap<char const *,int,int>::Node_t search; // [esp+200h] [ebp-8h] BYREF
  va_list params; // [esp+218h] [ebp+10h] BYREF

  va_start(params, pBaseName);
  V_vsnprintf(pDest: szFullName, maxLen: 512, pFormat: pBaseName, params);
  result = C_BaseAnimating::LookupSequence(this: this->m_pOuter, label: szFullName);
  if ( result == -1 )
  {
    if ( (_S5_0 & 1) == 0 )
    {
      _S5_0 |= 1u;
      dict.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
      dict.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
      dict.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
      dict.m_Elements.m_Tree.m_Root = -1;
      dict.m_Elements.m_Tree.m_NumElements = 0;
      dict.m_Elements.m_Tree.m_FirstFree = -1;
      dict.m_Elements.m_Tree.m_LastAlloc.index = -1;
      dict.m_Elements.m_Tree.m_pElements = nullptr;
      dict.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
      atexit(func: CBasePlayerAnimState::CalcSequenceIndex_::_5_::_dynamic_atexit_destructor_for__dict__);
    }
    search.key = szFullName;
    if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
           this: &dict.m_Elements.m_Tree,
           &search) == -1 )
    {
      this = nullptr;
      CUtlDict<int,int>::Insert(this: &dict, pName: szFullName, element: (const int *)&this);
      _Warning(a1: "CalcSequenceIndex: can't find '%s'.\n", szFullName);
    }
    return 0;
  }
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10094180
// Name: public: void CBasePlayerAnimState::Init(class CBaseAnimatingOverlay __near *,class CModAnimConfig const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayerAnimState::Init(
        CBasePlayerAnimState *this,
        CBaseAnimatingOverlay *pPlayer,
        const CModAnimConfig *config)
{
  int v3; // eax

  this->m_pOuter = pPlayer;
  *(_QWORD *)&this->m_AnimConfig.m_flMaxBodyYawDegrees = *(_QWORD *)&config->m_flMaxBodyYawDegrees;
  v3 = *(_DWORD *)this->gap4;
  *(_DWORD *)&this->m_AnimConfig.m_bUseAimSequences = *(_DWORD *)&config->m_bUseAimSequences;
  (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)&this->gap4[*(_DWORD *)(v3 + 4)] + 8))(a1: &this->gap4[*(_DWORD *)(v3 + 4)]);
}

//------------------------------------------------------------------------------
// Address: 0x100941E0
// Name: public: virtual void CBasePlayerAnimState::ClearAnimationState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayerAnimState::ClearAnimationState(CBasePlayerAnimState *this)
{
  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 38) + 4))(a1: (char *)this - 152);
  *((_BYTE *)this - 112) = 0;
  *((float *)this - 17) = gpGlobals->curtime;
}

//------------------------------------------------------------------------------
// Address: 0x10094210
// Name: protected: float CBasePlayerAnimState::TimeSinceLastAnimationStateClear(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBasePlayerAnimState::TimeSinceLastAnimationStateClear(CBasePlayerAnimState *this)
{
  return gpGlobals->curtime - this->m_flLastAnimationStateClearTime;
}

//------------------------------------------------------------------------------
// Address: 0x10094220
// Name: protected: virtual void CBasePlayerAnimState::ResetGroundSpeed(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayerAnimState::ResetGroundSpeed(CBasePlayerAnimState *this)
{
  this->m_flMaxGroundSpeed = this->GetCurrentMaxGroundSpeed(this);
}

//------------------------------------------------------------------------------
// Address: 0x10094230
// Name: protected: virtual bool CBasePlayerAnimState::ShouldResetGroundSpeed(enum Activity,enum Activity)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBasePlayerAnimState::ShouldResetGroundSpeed(
        CBasePlayerAnimState *this,
        Activity oldActivity,
        Activity idealActivity)
{
  return (oldActivity == ACT_CROUCHIDLE || oldActivity == ACT_IDLE)
      && (idealActivity == ACT_WALK || idealActivity == ACT_RUN_CROUCH);
}

//------------------------------------------------------------------------------
// Address: 0x10094260
// Name: public: virtual bool CBasePlayerAnimState::ShouldBlendAimSequenceToIdle(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBasePlayerAnimState::ShouldBlendAimSequenceToIdle(CBasePlayerAnimState *this)
{
  Activity m_eCurrentMainSequenceActivity; // eax

  m_eCurrentMainSequenceActivity = this->m_eCurrentMainSequenceActivity;
  return m_eCurrentMainSequenceActivity == ACT_RUN
      || m_eCurrentMainSequenceActivity == ACT_LEAP
      || m_eCurrentMainSequenceActivity == ACT_WALK
      || m_eCurrentMainSequenceActivity == ACT_JUMP
      || m_eCurrentMainSequenceActivity == ACT_RUNTOIDLE
      || m_eCurrentMainSequenceActivity == ACT_RUN_CROUCH;
}

//------------------------------------------------------------------------------
// Address: 0x100942B0
// Name: public: virtual int CBasePlayerAnimState::SelectWeightedSequence(enum Activity)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBasePlayerAnimState::SelectWeightedSequence(CBasePlayerAnimState *this, Activity activity)
{
  return CBaseAnimating::SelectWeightedSequence(this: this->m_pOuter, activity);
}

//------------------------------------------------------------------------------
// Address: 0x100942C0
// Name: public: virtual bool CBasePlayerAnimState::ShouldUpdateAnimState(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBasePlayerAnimState::ShouldUpdateAnimState(CBasePlayerAnimState *this)
{
  return this->m_pOuter->IsAlive(this: this->m_pOuter);
}

//------------------------------------------------------------------------------
// Address: 0x100942D0
// Name: private: virtual bool CBasePlayerAnimState::ShouldResetMainSequence(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBasePlayerAnimState::ShouldResetMainSequence(
        CBasePlayerAnimState *this,
        int iCurrentSequence,
        int iNewSequence)
{
  CBaseAnimatingOverlay *m_pOuter; // esi
  int SequenceActivity; // edi

  if ( this->m_pOuter == nullptr )
    return false;
  m_pOuter = this->m_pOuter;
  SequenceActivity = CBaseAnimating::GetSequenceActivity(this: m_pOuter, iSequence: iCurrentSequence);
  return SequenceActivity == CBaseAnimating::GetSequenceActivity(this: m_pOuter, iSequence: iNewSequence);
}

//------------------------------------------------------------------------------
// Address: 0x10094310
// Name: protected: virtual void CBasePlayerAnimState::ComputePoseParam_BodyPitch(class CStudioHdr __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayerAnimState::ComputePoseParam_BodyPitch(CBasePlayerAnimState *this, CStudioHdr *pStudioHdr)
{
  float m_flEyePitch; // xmm0_4
  int v4; // eax
  float flValue; // [esp+Ch] [ebp-4h]

  m_flEyePitch = this->m_flEyePitch;
  if ( m_flEyePitch > 180.0 )
    m_flEyePitch = m_flEyePitch - 360.0;
  if ( m_flEyePitch >= -90.0 )
  {
    if ( m_flEyePitch <= 90.0 )
      flValue = m_flEyePitch;
    else
      flValue = 90.0;
  }
  else
  {
    flValue = -90.0;
  }
  v4 = CBaseAnimating::LookupPoseParameter(this: this->m_pOuter, pStudioHdr, szName: "body_pitch");
  if ( v4 >= 0 )
  {
    CBaseAnimating::SetPoseParameter(this: this->m_pOuter, pStudioHdr, iParameter: v4, flValue);
    g_flLastBodyPitch = flValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100943A0
// Name: protected: virtual int CBasePlayerAnimState::ConvergeAngles(float,float,float,float,float __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBasePlayerAnimState::ConvergeAngles(
        CBasePlayerAnimState *this,
        float goal,
        float maxrate,
        float maxgap,
        float dt,
        float *current)
{
  int v7; // edi
  float v8; // xmm4_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float angle; // xmm1_4
  long double v16; // st7
  float v17; // xmm0_4
  float v18; // xmm0_4
  float maxmove; // [esp+10h] [ebp-4h]
  float anglediffabs; // [esp+28h] [ebp+14h]
  float anglediff; // [esp+2Ch] [ebp+18h]
  float anglediffa; // [esp+2Ch] [ebp+18h]
  float anglediffb; // [esp+2Ch] [ebp+18h]

  v7 = 0;
  anglediff = AngleNormalize(angle: goal - *current);
  v8 = anglediff;
  v9 = 1.0;
  LODWORD(v10) = LODWORD(anglediff) & _mask__AbsFloat_;
  if ( COERCE_FLOAT(LODWORD(anglediff) & _mask__AbsFloat_) <= 45.0 )
  {
    if ( (float)(v10 * 0.022222223) >= 0.0099999998 )
    {
      if ( (float)(v10 * 0.022222223) <= 1.0 )
        v9 = v10 * 0.022222223;
    }
    else
    {
      v9 = 0.0099999998;
    }
  }
  v11 = (float)(maxrate * dt) * v9;
  maxmove = v11;
  if ( v10 > maxgap )
  {
    v12 = v11 * 5.0;
    v13 = v10 - maxgap;
    if ( v12 <= v13 )
      v13 = v12;
    v14 = *current;
    if ( anglediff <= 0.0 )
      angle = v14 - v13;
    else
      angle = v14 + v13;
    *current = angle;
    anglediffa = AngleNormalize(angle);
    *current = anglediffa;
    v16 = AngleNormalize(angle: goal - anglediffa);
    anglediffb = v16;
    anglediffabs = fabs(v16);
    _Msg(a1: "jumped = %f\n", v13);
    v8 = anglediffb;
    v10 = anglediffabs;
    v11 = maxmove;
  }
  if ( v11 <= v10 )
  {
    v18 = *current;
    if ( v8 <= 0.0 )
    {
      v17 = v18 - v11;
      v7 = 2;
    }
    else
    {
      v17 = v18 + v11;
      v7 = 1;
    }
  }
  else
  {
    v17 = goal;
  }
  *current = v17;
  *current = AngleNormalize(angle: v17);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10094510
// Name: protected: float CBasePlayerAnimState::GetOuterXYSpeed(void)const
// Source: json
//------------------------------------------------------------------------------
double __usercall CBasePlayerAnimState::GetOuterXYSpeed@<st0>(CBasePlayerAnimState *this@<ecx>, int a2@<ebp>)
{
  CBaseAnimatingOverlay *m_pOuter; // esi
  _DWORD v4[3]; // [esp+0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v4[0] = a2;
  v4[1] = retaddr;
  m_pOuter = this->m_pOuter;
  if ( (m_pOuter->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this: this->m_pOuter, a2: (int)v4);
  return fsqrt(
           (float)(m_pOuter->m_vecAbsVelocity.y * m_pOuter->m_vecAbsVelocity.y)
         + (float)(m_pOuter->m_vecAbsVelocity.x * m_pOuter->m_vecAbsVelocity.x));
}

//------------------------------------------------------------------------------
// Address: 0x10094580
// Name: public: void CBasePlayerAnimState::AnimStateLog(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CBasePlayerAnimState::AnimStateLog(CBasePlayerAnimState *this, char *pMsg, ...)
{
  ConVar *m_pParent; // eax
  int m_nValue; // ecx
  void *(__thiscall *Open)(IBaseFileSystem *, const char *, const char *, const char *); // eax
  char pDest[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list params; // [esp+1010h] [ebp+10h] BYREF

  va_start(params, pMsg);
  V_vsnprintf(pDest, maxLen: 4096, pFormat: pMsg, params);
  m_pParent = showanimstate_log.m_pParent;
  if ( showanimstate_log.m_pParent != nullptr )
  {
    m_nValue = showanimstate_log.m_pParent->m_Value.m_nValue;
    if ( m_nValue == 1 || m_nValue == 3 )
    {
      _Msg(a1: "%s", pDest);
      m_pParent = showanimstate_log.m_pParent;
    }
    if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue > 1 )
    {
      if ( (_S3_19 & 1) == 0 )
      {
        Open = filesystem->Open;
        _S3_19 |= 1u;
        hFile = Open(this: &filesystem->IBaseFileSystem, a2: "AnimStateServer.log", a3: "wt", a4: nullptr);
      }
      filesystem->FPrintf(this: filesystem, a2: hFile, a3: "%s", pDest);
      filesystem->Flush(this: &filesystem->IBaseFileSystem, a2: hFile);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10094660
// Name: public: void CBasePlayerAnimState::AnimStatePrintf(int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CBasePlayerAnimState::AnimStatePrintf(CBasePlayerAnimState *this, int iLine, char *pMsg, ...)
{
  char pDest[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list params; // [esp+1014h] [ebp+14h] BYREF

  va_start(params, pMsg);
  V_vsnprintf(pDest, maxLen: 4096, pFormat: pMsg, params);
  engine->Con_NPrintf(this: engine, a2: iLine, a3: "%s", pDest);
  CBasePlayerAnimState::AnimStateLog(this, pMsg: "%s\n", pDest);
}

//------------------------------------------------------------------------------
// Address: 0x100946D0
// Name: public: virtual float CBasePlayerAnimState::GetFeetYawRate(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBasePlayerAnimState::GetFeetYawRate(CBasePlayerAnimState *this)
{
  return mp_feetyawrate.m_pParent->m_Value.m_fValue;
}

//------------------------------------------------------------------------------
// Address: 0x10094740
// Name: public: virtual float CBasePlayerAnimState::CalcMovementPlaybackRate(bool __near *)
// Source: json
//------------------------------------------------------------------------------
double __userpurge CBasePlayerAnimState::CalcMovementPlaybackRate@<st0>(
        CBasePlayerAnimState *this@<ecx>,
        int a2@<ebp>,
        bool *bIsMoving)
{
  CBaseAnimatingOverlay *m_pOuter; // esi
  float v5; // xmm0_4
  int v6; // xmm1_4
  float v8; // [esp-20h] [ebp-2Ch]
  float v9; // [esp-4h] [ebp-10h]
  _DWORD v10[2]; // [esp+0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v10[0] = a2;
  v10[1] = retaddr;
  m_pOuter = this->m_pOuter;
  if ( (m_pOuter->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this: this->m_pOuter, a2: (int)v10);
  v8 = fsqrt(
         (float)(m_pOuter->m_vecAbsVelocity.y * m_pOuter->m_vecAbsVelocity.y)
       + (float)(m_pOuter->m_vecAbsVelocity.x * m_pOuter->m_vecAbsVelocity.x));
  *bIsMoving = false;
  v9 = 1.0;
  if ( v8 > 0.5 && this->CanThePlayerMove(this) )
  {
    if ( this->m_flMaxGroundSpeed >= 0.001 )
    {
      v5 = v8 * 0.011764706;
      v6 = 0;
      if ( (float)(v8 * 0.011764706) < 0.0 || (v6 = 1065353216, v5 > 1.0) )
        v5 = *(float *)&v6;
    }
    else
    {
      v5 = 0.0099999998;
    }
    v9 = v5;
    *bIsMoving = true;
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x10094830
// Name: protected: virtual void CBasePlayerAnimState::ComputePoseParam_MoveYaw(class CStudioHdr __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBasePlayerAnimState::ComputePoseParam_MoveYaw(
        CBasePlayerAnimState *this@<ecx>,
        float a2@<ebp>,
        CStudioHdr *pStudioHdr)
{
  float m_flCurrentFeetYaw; // xmm1_4
  CBaseAnimatingOverlay *m_pOuter; // ecx
  CBaseAnimatingOverlay *v6; // edi
  float y; // xmm0_4
  __int128 v8; // xmm3
  float angle; // xmm0_4
  float m_flEyeYaw; // xmm0_4
  int v11; // xmm0_4
  int v12; // xmm0_4
  CBaseAnimatingOverlay *v13; // ecx
  float v14; // xmm1_4
  int v15; // eax
  CBaseAnimatingOverlay *v16; // ecx
  int v17; // eax
  int v18; // ecx
  float v19; // xmm3_4
  __m128 v20; // xmm0
  double v21; // xmm0_8
  double v22; // xmm0_8
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  int v26; // eax
  _QWORD v27[2]; // [esp+18h] [ebp-3Ch] BYREF
  int v28; // [esp+34h] [ebp-20h]
  int v29; // [esp+38h] [ebp-1Ch]
  float v30; // [esp+3Ch] [ebp-18h]
  int iMoveY; // [esp+40h] [ebp-14h]
  int iMoveX; // [esp+44h] [ebp-10h] BYREF
  float flPlaybackRate; // [esp+48h] [ebp-Ch] BYREF
  float flYaw; // [esp+4Ch] [ebp-8h]
  float retaddr; // [esp+54h] [ebp+0h]

  flPlaybackRate = a2;
  flYaw = retaddr;
  if ( this->m_AnimConfig.m_LegAnimType == LEGANIM_GOLDSRC )
  {
    m_flCurrentFeetYaw = this->m_flCurrentFeetYaw;
    m_pOuter = this->m_pOuter;
    HIDWORD(v27[0]) = 0;
    v27[1] = LODWORD(m_flCurrentFeetYaw);
    CBaseEntity::SetLocalAngles(this: m_pOuter, angles: (const QAngle *)((char *)v27 + 4));
  }
  if ( this->m_AnimConfig.m_LegAnimType <= (unsigned int)LEGANIM_8WAY )
  {
    v6 = this->m_pOuter;
    if ( (v6->m_iEFlags & 0x1000) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this: this->m_pOuter, a2: (int)&flPlaybackRate);
    y = v6->m_vecAbsVelocity.y;
    v8 = 0;
    *(float *)&v8 = fsqrt((float)(y * y) + (float)(v6->m_vecAbsVelocity.x * v6->m_vecAbsVelocity.x));
    *(_OWORD *)v27 = v8;
    if ( *(float *)&v8 > 0.5 )
    {
      __libm_sse2_atan2();
      angle = y * 57.29578;
      this->m_flGaitYaw = angle;
      this->m_flGaitYaw = AngleNormalize(angle);
    }
    m_flEyeYaw = this->m_flEyeYaw;
    if ( m_flEyeYaw <= 180.0 )
    {
      if ( m_flEyeYaw < -180.0 )
        m_flEyeYaw = m_flEyeYaw + 360.0;
    }
    else
    {
      m_flEyeYaw = m_flEyeYaw - 360.0;
    }
    *(float *)&v11 = COERCE_FLOAT(COERCE_UNSIGNED_INT(m_flEyeYaw - this->m_flGaitYaw) ^ _mask__NegFloat_)
                   - (float)(360
                           * (int)(float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(m_flEyeYaw - this->m_flGaitYaw) ^ _mask__NegFloat_)
                                        * 0.0027777778));
    iMoveY = v11;
    if ( *(float *)&v11 >= -180.0 )
    {
      if ( *(float *)&v11 <= 180.0 )
        goto LABEL_17;
      *(float *)&v12 = *(float *)&v11 - 360.0;
    }
    else
    {
      *(float *)&v12 = *(float *)&v11 + 360.0;
    }
    iMoveY = v12;
LABEL_17:
    v13 = this->m_pOuter;
    if ( this->m_AnimConfig.m_LegAnimType != LEGANIM_9WAY )
    {
      v26 = CBaseAnimating::LookupPoseParameter(this: v13, pStudioHdr, szName: "move_yaw");
      if ( v26 >= 0 )
      {
        CBaseAnimating::SetPoseParameter(this: this->m_pOuter, pStudioHdr, iParameter: v26, flValue: *(float *)&iMoveY);
        LODWORD(m_flLastMoveYaw) = iMoveY;
      }
    }
    else
    {
      v14 = this->m_flCurrentFeetYaw;
      HIDWORD(v27[0]) = 0;
      v27[1] = LODWORD(v14);
      CBaseEntity::SetLocalAngles(this: v13, angles: (const QAngle *)((char *)v27 + 4));
      v15 = CBaseAnimating::LookupPoseParameter(this: this->m_pOuter, pStudioHdr, szName: "move_x");
      v16 = this->m_pOuter;
      v29 = v15;
      v17 = CBaseAnimating::LookupPoseParameter(this: v16, pStudioHdr, szName: "move_y");
      v28 = v17;
      if ( v29 >= 0 && v17 >= 0 )
      {
        v30 = this->CalcMovementPlaybackRate(this, a2: (bool *)&iMoveX + 3);
        v19 = 0.0;
        v27[1] = 0;
        if ( HIBYTE(iMoveX) != 0 )
        {
          v20 = (__m128)(unsigned int)iMoveY;
          *(float *)&iMoveY = *(float *)&iMoveY * 0.017453292;
          v20.m128_f32[0] = *(float *)&iMoveY;
          __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd(v20));
          *(float *)&v21 = v21;
          *(float *)&v27[1] = *(float *)&v21 * v30;
          __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)(unsigned int)iMoveY));
          v19 = *(float *)&v27[1];
          *(float *)&v22 = v22;
          LODWORD(v23) = COERCE_UNSIGNED_INT(*(float *)&v22 * v30) ^ _mask__NegFloat_;
          LODWORD(v24) = LODWORD(v27[1]) & _mask__AbsFloat_;
          *((float *)&v27[1] + 1) = v23;
          if ( COERCE_FLOAT(LODWORD(v23) & _mask__AbsFloat_) > COERCE_FLOAT(LODWORD(v27[1]) & _mask__AbsFloat_) )
            LODWORD(v24) = LODWORD(v23) & _mask__AbsFloat_;
          if ( v24 > 0.0099999998 )
          {
            v25 = (float)(1.0 / v24) * v30;
            v19 = *(float *)&v27[1] * v25;
            *(float *)&v27[1] = *(float *)&v27[1] * v25;
            *((float *)&v27[1] + 1) = v25 * v23;
          }
        }
        iMoveY = v18;
        CBaseAnimating::SetPoseParameter(this: this->m_pOuter, pStudioHdr, iParameter: v29, flValue: v19);
        CBaseAnimating::SetPoseParameter(
          this: this->m_pOuter,
          pStudioHdr,
          iParameter: v28,
          flValue: *((float *)&v27[1] + 1));
        this->m_vLastMovePose = (Vector2D)v27[1];
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10094B40
// Name: protected: virtual void CBasePlayerAnimState::ComputePoseParam_BodyYaw(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBasePlayerAnimState::ComputePoseParam_BodyYaw(
        CBasePlayerAnimState *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>)
{
  CBaseAnimatingOverlay *m_pOuter; // edi
  float y; // xmm0_4
  __int128 v7; // xmm3
  float v8; // xmm3_4
  float m_flEyeYaw; // xmm0_4
  __m128 m_flEyeYaw_low; // xmm0
  double v11; // xmm0_8
  double v12; // xmm0_8
  __m128 y_low; // xmm0
  double v14; // xmm0_8
  double v15; // xmm0_8
  float v16; // xmm0_4
  float m_flMaxBodyYawDegrees; // xmm0_4
  float *p_m_flCurrentFeetYaw; // edi
  double v19; // st7
  float angle; // [esp+14h] [ebp-50h]
  int v23; // [esp+2Ch] [ebp-38h]
  float v24; // [esp+2Ch] [ebp-38h]
  float v25; // [esp+44h] [ebp-20h]
  float v26; // [esp+48h] [ebp-1Ch]
  Vector vEyeYaw; // [esp+50h] [ebp-14h] BYREF
  float flDiff; // [esp+5Ch] [ebp-8h]
  float retaddr; // [esp+64h] [ebp+0h]

  vEyeYaw.z = a2;
  flDiff = retaddr;
  m_pOuter = this->m_pOuter;
  if ( (m_pOuter->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this: this->m_pOuter, a2: (int)&vEyeYaw.z);
  y = m_pOuter->m_vecAbsVelocity.y;
  v7 = 0;
  v8 = fsqrt((float)(y * y) + (float)(m_pOuter->m_vecAbsVelocity.x * m_pOuter->m_vecAbsVelocity.x));
  v23 = 0;
  if ( !this->m_bCurrentFeetYawInitialized )
  {
    m_flEyeYaw = this->m_flEyeYaw;
    this->m_flCurrentFeetYaw = m_flEyeYaw;
    this->m_flGoalFeetYaw = m_flEyeYaw;
    this->m_bCurrentFeetYawInitialized = true;
    this->m_flLastTurnTime = 0.0;
    goto LABEL_16;
  }
  if ( v8 > 0.5 )
  {
    if ( this->m_AnimConfig.m_LegAnimType >= (unsigned int)LEGANIM_GOLDSRC )
    {
      __libm_sse2_atan2();
      vEyeYaw.y = y * 57.29578;
      this->m_flGoalFeetYaw = y * 57.29578;
      m_flEyeYaw_low = (__m128)LODWORD(this->m_flEyeYaw);
      m_flEyeYaw_low.m128_f32[0] = m_flEyeYaw_low.m128_f32[0] * 0.017453292;
      LODWORD(vEyeYaw.x) = m_flEyeYaw_low.m128_i32[0];
      __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd(m_flEyeYaw_low));
      *(float *)&v11 = v11;
      v25 = *(float *)&v11;
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(vEyeYaw.x)));
      *(float *)&v12 = v12;
      v26 = *(float *)&v12;
      y_low = (__m128)LODWORD(vEyeYaw.y);
      y_low.m128_f32[0] = vEyeYaw.y * 0.017453292;
      __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd(y_low));
      *(float *)&v14 = v14;
      v24 = *(float *)&v14;
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)COERCE_UNSIGNED_INT(vEyeYaw.y * 0.017453292)));
      *(float *)&v15 = v15;
      if ( (float)((float)(*(float *)&v15 * v26) + (float)(v24 * v25)) >= -0.01 )
        goto LABEL_16;
      v16 = vEyeYaw.y + 180.0;
      goto LABEL_15;
    }
LABEL_10:
    this->m_flGoalFeetYaw = this->m_flEyeYaw;
    goto LABEL_16;
  }
  if ( (float)(gpGlobals->curtime - this->m_flLastTurnTime) > mp_facefronttime.m_pParent->m_Value.m_fValue )
    goto LABEL_10;
  vEyeYaw.x = AngleNormalize(angle: this->m_flGoalFeetYaw - this->m_flEyeYaw);
  m_flMaxBodyYawDegrees = this->m_AnimConfig.m_flMaxBodyYawDegrees;
  if ( COERCE_FLOAT(LODWORD(vEyeYaw.x) & _mask__AbsFloat_) > m_flMaxBodyYawDegrees )
  {
    if ( vEyeYaw.x > 0.0 )
    {
      this->m_flGoalFeetYaw = this->m_flGoalFeetYaw - m_flMaxBodyYawDegrees;
      goto LABEL_16;
    }
    v16 = m_flMaxBodyYawDegrees + this->m_flGoalFeetYaw;
LABEL_15:
    this->m_flGoalFeetYaw = v16;
  }
LABEL_16:
  vEyeYaw.x = AngleNormalize(angle: this->m_flGoalFeetYaw);
  this->m_flGoalFeetYaw = vEyeYaw.x;
  p_m_flCurrentFeetYaw = &this->m_flCurrentFeetYaw;
  if ( this->m_flCurrentFeetYaw != vEyeYaw.x )
  {
    LODWORD(vEyeYaw.x) = this->__vftable;
    angle = ((double (__thiscall *)(CBasePlayerAnimState *, _DWORD, _DWORD, float *))this->GetFeetYawRate)(
              a1: this,
              a2: LODWORD(this->m_AnimConfig.m_flMaxBodyYawDegrees),
              a3: LODWORD(gpGlobals->frametime),
              a4: &this->m_flCurrentFeetYaw);
    (*(void (__thiscall **)(CBasePlayerAnimState *, _DWORD, _DWORD))(LODWORD(vEyeYaw.x) + 68))(
      a1: this,
      a2: LODWORD(this->m_flGoalFeetYaw),
      a3: LODWORD(angle));
    this->m_flLastTurnTime = gpGlobals->curtime;
  }
  vEyeYaw.y = AngleNormalize(angle: this->m_flEyeYaw - *p_m_flCurrentFeetYaw);
  v19 = *p_m_flCurrentFeetYaw;
  this->m_angRender.z = 0.0;
  this->m_angRender.y = v19;
  this->m_angRender.x = 0.0;
  ((void (__thiscall *)(CBasePlayerAnimState *, _DWORD, int, int))this->SetOuterBodyYaw)(
    a1: this,
    a2: LODWORD(vEyeYaw.y),
    a3,
    a4);
  g_flLastBodyYaw = vEyeYaw.y;
}

//------------------------------------------------------------------------------
// Address: 0x10094E10
// Name: public: virtual float CBasePlayerAnimState::SetOuterBodyYaw(float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBasePlayerAnimState::SetOuterBodyYaw(CBasePlayerAnimState *this, float flValue)
{
  CBaseAnimatingOverlay *m_pOuter; // esi
  CStudioHdr *m_pStudioHdr; // eax
  int v5; // edi
  CBaseAnimatingOverlay *v7; // esi
  CStudioHdr *v8; // eax

  m_pOuter = this->m_pOuter;
  if ( m_pOuter->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: this->m_pOuter) != nullptr )
    CBaseAnimating::LockStudioHdr(this: m_pOuter);
  m_pStudioHdr = m_pOuter->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  v5 = CBaseAnimating::LookupPoseParameter(this: m_pOuter, pStudioHdr: m_pStudioHdr, szName: "body_yaw");
  if ( v5 < 0 )
    return 0.0;
  v7 = this->m_pOuter;
  if ( v7->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: this->m_pOuter) != nullptr )
    CBaseAnimating::LockStudioHdr(this: v7);
  v8 = v7->m_pStudioHdr;
  if ( v8 == nullptr || v8->m_pStudioHdr == nullptr )
    v8 = nullptr;
  CBaseAnimating::SetPoseParameter(this: v7, pStudioHdr: v8, iParameter: v5, flValue);
  return flValue;
}

//------------------------------------------------------------------------------
// Address: 0x10094EC0
// Name: public: virtual void CBasePlayerAnimState::DebugShowAnimState(int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CBasePlayerAnimState::DebugShowAnimState(
        CBasePlayerAnimState *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        int iStartLine)
{
  CBaseAnimatingOverlay *m_pOuter; // edi
  CBaseAnimatingOverlay *v7; // eax
  float v8; // xmm0_4
  CBaseAnimating *v9; // edi
  bool v10; // zf
  float v11; // ecx
  CStudioHdr *m_pStudioHdr; // edi
  CBaseAnimatingOverlay *v13; // edi
  int m_Value; // edx
  CStudioHdr *v15; // edi
  char *SequenceName; // eax
  CAnimationLayer *AnimOverlay; // eax
  CBaseAnimatingOverlay *v18; // edi
  float v19; // edx
  CStudioHdr *v20; // edi
  char *v21; // eax
  CBaseAnimatingOverlay *v22; // ecx
  int v23; // edx
  CAnimationLayer *v24; // eax
  char v25; // cl
  float v26; // xmm0_4
  float v27; // xmm0_4
  char *SequenceActivityName; // eax
  CBaseAnimatingOverlay *v29; // edi
  CStudioHdr *v30; // edi
  CBaseAnimatingOverlay *v31; // edi
  CStudioHdr *v32; // edi
  int v33; // edx
  CBaseAnimatingOverlay *v34; // edi
  CStudioHdr *v35; // eax
  double v36; // st7
  int v37; // edi
  __int128 v38; // xmm0
  int v39; // edi
  CBaseAnimatingOverlay *v40; // edi
  float v41; // xmm0_4
  float v42; // xmm7_4
  float v43; // xmm5_4
  float v44; // xmm2_4
  float v45; // xmm3_4
  float v46; // xmm6_4
  float v47; // xmm7_4
  float v48; // xmm5_4
  float v49; // xmm2_4
  float v50; // xmm3_4
  double SequenceCycleRate; // [esp+20h] [ebp-BCh]
  Vector v54; // [esp+3Ch] [ebp-A0h] BYREF
  Vector vUp; // [esp+48h] [ebp-94h] BYREF
  QAngle angles; // [esp+54h] [ebp-88h] BYREF
  Vector vRight; // [esp+60h] [ebp-7Ch] BYREF
  Vector v58; // [esp+6Ch] [ebp-70h] BYREF
  _BYTE vForward[24]; // [esp+78h] [ebp-64h] OVERLAPPED BYREF
  float v60[2]; // [esp+9Ch] [ebp-40h] BYREF
  float v61; // [esp+A4h] [ebp-38h]
  __int64 v62; // [esp+A8h] [ebp-34h]
  __int64 v63; // [esp+B0h] [ebp-2Ch]
  int x_low; // [esp+B8h] [ebp-24h]
  int iLine; // [esp+BCh] [ebp-20h]
  float v66; // [esp+C0h] [ebp-1Ch]
  Vector vOuterVel; // [esp+C4h] [ebp-18h]
  _DWORD v68[2]; // [esp+D0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+DCh] [ebp+0h]

  v68[0] = a2;
  v68[1] = retaddr;
  m_pOuter = this->m_pOuter;
  if ( (m_pOuter->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this: this->m_pOuter, a2: (int)v68);
  v7 = this->m_pOuter;
  x_low = SLODWORD(m_pOuter->m_vecAbsVelocity.x);
  iLine = SLODWORD(m_pOuter->m_vecAbsVelocity.y);
  v8 = 1.0 - v7->m_flFrozen.m_Value;
  if ( v8 >= 0.0 )
  {
    if ( v8 > 1.0 )
      v8 = 1.0;
  }
  else
  {
    v8 = 0.0;
  }
  v9 = v7;
  v10 = v7->m_pStudioHdr == nullptr;
  v11 = *(float *)&v7->m_nSequence.m_Value;
  vOuterVel.x = v7->m_flPlaybackRate.m_Value * v8;
  vOuterVel.y = v11;
  if ( v10 && CBaseEntity::GetModel(this: v7) != nullptr )
    CBaseAnimating::LockStudioHdr(this: v9);
  m_pStudioHdr = v9->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr
    || (v10 = m_pStudioHdr->m_pStudioHdr == nullptr, LODWORD(vOuterVel.z) = m_pStudioHdr, v10) )
  {
    vOuterVel.z = 0.0;
  }
  v13 = this->m_pOuter;
  v10 = v13->m_pStudioHdr == nullptr;
  m_Value = v13->m_nSequence.m_Value;
  *(float *)&v62 = v13->m_flCycle.m_Value;
  HIDWORD(v62) = m_Value;
  if ( v10 && CBaseEntity::GetModel(this: v13) != nullptr )
    CBaseAnimating::LockStudioHdr(this: v13);
  v15 = v13->m_pStudioHdr;
  if ( v15 == nullptr || v15->m_pStudioHdr == nullptr )
    v15 = nullptr;
  SequenceCycleRate = CBaseAnimating::GetSequenceCycleRate(
                        this: this->m_pOuter,
                        pStudioHdr: (CStudioHdr *)LODWORD(vOuterVel.z),
                        iSequence: SLODWORD(vOuterVel.y));
  SequenceName = GetSequenceName(pstudiohdr: v15, iSequence: SHIDWORD(v62));
  CBasePlayerAnimState::AnimStatePrintf(
    this,
    iLine: iStartLine,
    pMsg: "main: %s(%d), cycle: %.2f cyclerate: %.2f playbackrate: %.2f\n",
    SequenceName,
    HIDWORD(v62),
    *(float *)&v62,
    SequenceCycleRate,
    vOuterVel.x);
  v10 = this->m_AnimConfig.m_LegAnimType == LEGANIM_8WAY;
  LODWORD(v63) = iStartLine + 1;
  if ( v10 )
  {
    AnimOverlay = CBaseAnimatingOverlay::GetAnimOverlay(this: this->m_pOuter, iIndex: 0);
    v18 = this->m_pOuter;
    v10 = v18->m_pStudioHdr == nullptr;
    v19 = *(float *)&AnimOverlay->m_nSequence.m_Value;
    vOuterVel.x = AnimOverlay->m_flWeight.m_Value;
    vOuterVel.y = v19;
    if ( v10 && CBaseEntity::GetModel(this: v18) != nullptr )
      CBaseAnimating::LockStudioHdr(this: v18);
    v20 = v18->m_pStudioHdr;
    if ( v20 == nullptr || v20->m_pStudioHdr == nullptr )
      v20 = nullptr;
    v21 = GetSequenceName(pstudiohdr: v20, iSequence: SLODWORD(vOuterVel.y));
    CBasePlayerAnimState::AnimStatePrintf(this, iLine: v63, pMsg: "idle: %s, weight: %.2f\n", v21, vOuterVel.x);
    LODWORD(v63) = v63 + 1;
  }
  v22 = this->m_pOuter;
  v23 = v22->m_AnimOverlay.m_Size - 1;
  vOuterVel.z = 0.0;
  if ( v23 > 0 )
  {
    do
    {
      HIDWORD(v63) = LODWORD(vOuterVel.z) + 1;
      v24 = CBaseAnimatingOverlay::GetAnimOverlay(this: v22, iIndex: LODWORD(vOuterVel.z) + 1);
      v25 = v24->m_fFlags & 1;
      if ( v25 != 0 )
        *(_DWORD *)vForward = v24->m_nOrder.m_Value;
      else
        *(_DWORD *)vForward = 0;
      if ( v25 != 0 )
        v26 = v24->m_flCycle.m_Value;
      else
        v26 = 0.0;
      *((float *)&v62 + 1) = v26;
      if ( v25 != 0 )
        v27 = v24->m_flWeight.m_Value;
      else
        v27 = 0.0;
      *(float *)&v62 = v27;
      if ( v25 != 0 )
        LODWORD(vOuterVel.y) = v24->m_fFlags;
      else
        vOuterVel.y = 0.0;
      if ( v25 != 0 )
        LODWORD(vOuterVel.x) = v24->m_nSequence.m_Value;
      else
        vOuterVel.x = 0.0;
      if ( v25 != 0 )
      {
        *(_DWORD *)&vForward[4] = v24->m_nSequence.m_Value;
        if ( *(_DWORD *)&vForward[4] != 0 )
        {
          if ( showanimstate_activities.m_pParent != nullptr
            && showanimstate_activities.m_pParent->m_Value.m_nValue != 0 )
          {
            v29 = this->m_pOuter;
            if ( v29->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: this->m_pOuter) != nullptr )
              CBaseAnimating::LockStudioHdr(this: v29);
            v30 = v29->m_pStudioHdr;
            if ( v30 == nullptr || v30->m_pStudioHdr == nullptr )
              v30 = nullptr;
            SequenceActivityName = GetSequenceActivityName(pstudiohdr: v30, iSequence: *(int *)&vForward[4]);
          }
          else
          {
            v31 = this->m_pOuter;
            if ( v31->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: this->m_pOuter) != nullptr )
              CBaseAnimating::LockStudioHdr(this: v31);
            v32 = v31->m_pStudioHdr;
            if ( v32 == nullptr || v32->m_pStudioHdr == nullptr )
              v32 = nullptr;
            SequenceActivityName = GetSequenceName(pstudiohdr: v32, iSequence: *(int *)&vForward[4]);
          }
        }
        else
        {
          SequenceActivityName = "-- ";
        }
      }
      else
      {
        SequenceActivityName = "-- ";
      }
      CBasePlayerAnimState::AnimStatePrintf(
        this,
        iLine: v63,
        pMsg: "%s(%d), flags (%d), weight: %.2f, cycle: %.2f, order (%d), aim (%d)",
        SequenceActivityName,
        vOuterVel.x,
        vOuterVel.y,
        *(float *)&v62,
        *((float *)&v62 + 1),
        *(_DWORD *)vForward,
        vOuterVel.z);
      v22 = this->m_pOuter;
      v33 = v22->m_AnimOverlay.m_Size - 1;
      LODWORD(v63) = v63 + 1;
      vOuterVel.z = *((float *)&v63 + 1);
    }
    while ( SHIDWORD(v63) < v33 );
  }
  v34 = this->m_pOuter;
  v10 = v34->m_pStudioHdr == nullptr;
  HIDWORD(v63) = v34->m_nSequence.m_Value;
  if ( v10 && CBaseEntity::GetModel(this: v34) != nullptr )
    CBaseAnimating::LockStudioHdr(this: v34);
  v35 = v34->m_pStudioHdr;
  if ( v35 == nullptr || v35->m_pStudioHdr == nullptr )
    v35 = nullptr;
  v36 = ((double (__thiscall *)(CBaseAnimatingOverlay *, CStudioHdr *, _DWORD, int, int))v34->GetSequenceGroundSpeed)(
          a1: v34,
          a2: v35,
          a3: HIDWORD(v63),
          a4: a3,
          a5: a4);
  v37 = v63;
  *((float *)&v63 + 1) = *(float *)&iLine * *(float *)&iLine;
  v38 = 0;
  *(float *)&v38 = fsqrt((float)(*(float *)&iLine * *(float *)&iLine) + (float)(*(float *)&x_low * *(float *)&x_low));
  *(_OWORD *)&vForward[8] = v38;
  CBasePlayerAnimState::AnimStatePrintf(
    this,
    iLine: v63,
    pMsg: "vel: %.2f, time: %.2f, max: %.2f, animspeed: %.2f",
    *(float *)&v38,
    gpGlobals->curtime,
    this->m_flMaxGroundSpeed,
    v36);
  v39 = v37 + 1;
  if ( this->m_AnimConfig.m_LegAnimType == LEGANIM_8WAY )
  {
    *(double *)&vOuterVel.y = g_flLastBodyPitch;
    CBasePlayerAnimState::AnimStatePrintf(
      this,
      iLine: v39,
      pMsg: "ent yaw: %.2f, body_yaw: %.2f, move_yaw: %.2f, gait_yaw: %.2f, body_pitch: %.2f",
      this->m_angRender.y,
      g_flLastBodyYaw,
      m_flLastMoveYaw,
      this->m_flGaitYaw,
      g_flLastBodyPitch);
  }
  else
  {
    CBasePlayerAnimState::AnimStatePrintf(
      this,
      iLine: v39,
      pMsg: "ent yaw: %.2f, body_yaw: %.2f, body_pitch: %.2f, move_x: %.2f, move_y: %.2f",
      this->m_angRender.y,
      g_flLastBodyYaw,
      g_flLastBodyPitch,
      this->m_vLastMovePose.x,
      this->m_vLastMovePose.y);
  }
  v40 = this->m_pOuter;
  if ( (v40->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: this->m_pOuter, a2: (int)v68);
  x_low = SLODWORD(v40->m_vecAbsOrigin.x);
  iLine = SLODWORD(v40->m_vecAbsOrigin.y);
  v41 = v40->m_vecAbsOrigin.z + 3.0;
  LODWORD(vOuterVel.z) = &v54;
  LODWORD(vOuterVel.y) = &angles;
  v66 = v41;
  LODWORD(vOuterVel.x) = &v58;
  vUp.x = 0.0;
  vUp.z = 0.0;
  vUp.y = this->m_flEyeYaw;
  AngleVectors(angles: (const QAngle *)&vUp, forward: &v58, right: (Vector *)&angles, up: &v54);
  v42 = *(float *)&x_low;
  v60[1] = (float)(v58.y * 80.0) + *(float *)&iLine;
  v61 = (float)(v58.z * 80.0) + v66;
  v60[0] = (float)(v58.x * 80.0) + *(float *)&x_low;
  v43 = (float)(angles.y * 10.0) * 0.5;
  *(float *)&vForward[20] = (float)(angles.z * 10.0) * 0.5;
  v44 = v43 + *(float *)&iLine;
  v45 = *(float *)&vForward[20] + v66;
  vOuterVel.z = 0.0099999998;
  vOuterVel.y = 0.0;
  LODWORD(vOuterVel.x) = 255;
  v66 = 0.0;
  vRight.x = *(float *)&x_low - (float)((float)(angles.x * 10.0) * 0.5);
  v46 = *(float *)&iLine - v43;
  *(float *)&iLine = 0.0;
  x_low = 255;
  vRight.y = v46;
  vRight.z = 0.0 - *(float *)&vForward[20];
  *(float *)&vForward[12] = (float)((float)(angles.x * 10.0) * 0.5) + v42;
  *(float *)&vForward[16] = v44;
  *(float *)&vForward[20] = v45;
  ((void (__thiscall *)(IVDebugOverlay *, _BYTE *, Vector *, float *, int, _DWORD, _DWORD))debugoverlay->AddTriangleOverlay)(
    a1: debugoverlay,
    a2: &vForward[12],
    a3: &vRight,
    a4: v60,
    a5: 255,
    a6: 0,
    a7: 0);
  vUp.y = this->m_angRender.y;
  AngleVectors(angles: (const QAngle *)&vUp, forward: &v58, right: (Vector *)&angles, up: &v54);
  v47 = *(float *)&x_low;
  *(float *)&vForward[16] = (float)(v58.y * 80.0) + *(float *)&iLine;
  *(float *)&vForward[20] = (float)(v58.z * 80.0) + v66;
  *(float *)&vForward[12] = (float)(v58.x * 80.0) + *(float *)&x_low;
  v48 = (float)(angles.y * 10.0) * 0.5;
  v49 = v48 + *(float *)&iLine;
  v50 = (float)((float)(angles.z * 10.0) * 0.5) + v66;
  v66 = 0.0099999998;
  *(float *)&iLine = 0.0;
  x_low = 255;
  v61 = (float)(angles.z * 10.0) * 0.5;
  v63 = 0xFF00000000LL;
  vRight.x = v47 - (float)((float)(angles.x * 10.0) * 0.5);
  v62 = (unsigned int)&vForward[12];
  vRight.y = 0.0 - v48;
  vRight.z = 0.0099999998 - v61;
  v60[0] = (float)((float)(angles.x * 10.0) * 0.5) + v47;
  v60[1] = v49;
  ((void (__thiscall *)(IVDebugOverlay *, float *, _DWORD, _BYTE *, _DWORD, _DWORD, int, int, _DWORD, int))debugoverlay->AddTriangleOverlay)(
    a1: debugoverlay,
    a2: v60,
    a3: LODWORD(v50),
    a4: &vForward[12],
    a5: 0,
    a6: 0,
    a7: 255,
    a8: 255,
    a9: 0,
    a10: 1008981770);
}

//------------------------------------------------------------------------------
// Address: 0x10096480
// Name: public: virtual CBasePlayerAnimState::~CBasePlayerAnimState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayerAnimState::~CBasePlayerAnimState(CBasePlayerAnimState *this)
{
  int v2; // eax

  v2 = *(_DWORD *)this->gap4;
  this->__vftable = (CBasePlayerAnimState_vtbl *)&CBasePlayerAnimState::`vftable'{for `CBasePlayerAnimState'};
  *(_DWORD *)&this->gap4[*(_DWORD *)(v2 + 4)] = &CBasePlayerAnimState::`vftable'{for `IPlayerAnimState'};
  *(CBasePlayerAnimState_vtbl **)((char *)&this->__vftable + *(_DWORD *)(*(_DWORD *)this->gap4 + 4)) = (CBasePlayerAnimState_vtbl *)(*(_DWORD *)(*(_DWORD *)this->gap4 + 4) - 148);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_SequenceTransitioner);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_IdleSequenceTransitioner);
}

//------------------------------------------------------------------------------
// Address: 0x100964F0
// Name: public: void CBasePlayerAnimState::RestartMainSequence(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayerAnimState::RestartMainSequence(CBasePlayerAnimState *this)
{
  CGlobalVars *v1; // ebx
  CBaseAnimatingOverlay *m_pOuter; // edi
  CBaseEdict *v3; // ecx
  CBaseEdict *v4; // ecx

  v1 = gpGlobals;
  m_pOuter = this->m_pOuter;
  if ( m_pOuter->m_flAnimTime.m_Value != gpGlobals->curtime )
  {
    if ( m_pOuter->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&m_pOuter->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = &m_pOuter->m_Network.m_pPev->CBaseEdict;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: v3, offset: 0x64u);
    }
    m_pOuter->m_flAnimTime.m_Value = v1->curtime;
  }
  if ( m_pOuter->m_flCycle.m_Value != 0.0 )
  {
    if ( m_pOuter->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&m_pOuter->m_Network + 76) |= 1u;
      m_pOuter->m_flCycle.m_Value = 0.0;
    }
    else
    {
      v4 = &m_pOuter->m_Network.m_pPev->CBaseEdict;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: v4, offset: 0x3ACu);
      m_pOuter->m_flCycle.m_Value = 0.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10096600
// Name: public: CBasePlayerAnimState::CBasePlayerAnimState(void)
// Source: json
//------------------------------------------------------------------------------
CBasePlayerAnimState *__thiscall CBasePlayerAnimState::CBasePlayerAnimState(CBasePlayerAnimState *this, int a2)
{
  CBasePlayerAnimState *result; // eax
  int v3; // edx

  result = this;
  if ( a2 != 0 )
  {
    *(_DWORD *)this->gap4 = &CBasePlayerAnimState::`vbtable';
    *(_DWORD *)&this->gap94[4] = &IPlayerAnimState::`vftable';
  }
  v3 = *(_DWORD *)this->gap4;
  this->__vftable = (CBasePlayerAnimState_vtbl *)&CBasePlayerAnimState::`vftable'{for `CBasePlayerAnimState'};
  *(_DWORD *)&this->gap4[*(_DWORD *)(v3 + 4)] = &CBasePlayerAnimState::`vftable'{for `IPlayerAnimState'};
  *(CBasePlayerAnimState_vtbl **)((char *)&this->__vftable + *(_DWORD *)(*(_DWORD *)this->gap4 + 4)) = (CBasePlayerAnimState_vtbl *)(*(_DWORD *)(*(_DWORD *)this->gap4 + 4) - 148);
  this->m_IdleSequenceTransitioner.m_animationQueue.m_Memory.m_pMemory = nullptr;
  this->m_IdleSequenceTransitioner.m_animationQueue.m_Memory.m_nAllocationCount = 0;
  this->m_IdleSequenceTransitioner.m_animationQueue.m_Memory.m_nGrowSize = 0;
  this->m_IdleSequenceTransitioner.m_animationQueue.m_Size = 0;
  this->m_IdleSequenceTransitioner.m_animationQueue.m_pElements = nullptr;
  this->m_SequenceTransitioner.m_animationQueue.m_Memory.m_pMemory = nullptr;
  this->m_SequenceTransitioner.m_animationQueue.m_Memory.m_nAllocationCount = 0;
  this->m_SequenceTransitioner.m_animationQueue.m_Memory.m_nGrowSize = 0;
  this->m_SequenceTransitioner.m_animationQueue.m_Size = 0;
  this->m_SequenceTransitioner.m_animationQueue.m_pElements = nullptr;
  this->m_flEyeYaw = 0.0;
  this->m_flEyePitch = 0.0;
  this->m_bCurrentFeetYawInitialized = false;
  this->m_flCurrentTorsoYaw = 0.0;
  this->m_flMaxGroundSpeed = 0.0;
  *(_QWORD *)&this->m_flGaitYaw = 0;
  this->m_flGoalFeetYaw = 0.0;
  this->m_flCurrentFeetYaw = 0.0;
  this->m_flLastYaw = 0.0;
  this->m_flLastTurnTime = 0.0;
  this->m_angRender.x = 0.0;
  this->m_angRender.y = 0.0;
  this->m_angRender.z = 0.0;
  this->m_vLastMovePose.x = 0.0;
  this->m_vLastMovePose.y = 0.0;
  this->m_iCurrent8WayIdleSequence = -1;
  this->m_iCurrent8WayCrouchIdleSequence = -1;
  this->m_pOuter = nullptr;
  this->m_eCurrentMainSequenceActivity = ACT_IDLE;
  this->m_flLastAnimationStateClearTime = 0.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10096930
// Name: public: void CUtlDict<int,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<int,int>::RemoveAll(CUtlDict<int,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10096990
// Name: public: void CAnimationLayer::SetOrder(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimationLayer::SetOrder(CAnimationLayer *this, int nOrder)
{
  CBaseAnimatingOverlay *m_pOwnerEntity; // eax
  CBaseEdict *v4; // eax

  if ( this->m_nOrder.m_Value != nOrder )
  {
    m_pOwnerEntity = this->m_pOwnerEntity;
    if ( m_pOwnerEntity != nullptr )
    {
      if ( m_pOwnerEntity->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&m_pOwnerEntity->m_Network + 76) |= 1u;
        this->m_nOrder.m_Value = nOrder;
        return;
      }
      v4 = &m_pOwnerEntity->m_Network.m_pPev->CBaseEdict;
      if ( v4 != nullptr )
      {
        v4->m_fStateFlags |= 0x101u;
        CBaseEdict::GetChangeAccessor(this: v4)->m_iChangeInfoSerialNumber = 0;
      }
    }
    this->m_nOrder.m_Value = nOrder;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100969E0
// Name: public: virtual void CBasePlayerAnimState::ClearAnimationLayers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayerAnimState::ClearAnimationLayers(CBasePlayerAnimState *this)
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
    CBaseAnimatingOverlay::SetNumAnimOverlays(this: m_pOuter, num: 5);
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
// Address: 0x10096A70
// Name: private: void CBasePlayerAnimState::UpdateAimSequenceLayers(float,int,bool,class CSequenceTransitioner __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBasePlayerAnimState::UpdateAimSequenceLayers(
        CBasePlayerAnimState *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        float flCycle,
        float iFirstLayer,
        CAnimationLayer *bForceIdle,
        float pTransitioner,
        float flWeightScale)
{
  int (__thiscall *CalcAimLayerSequence)(CBasePlayerAnimState *, float *, float *, bool); // edx
  int v10; // ebx
  CBaseAnimatingOverlay *m_pOuter; // esi
  CStudioHdr *m_pStudioHdr; // eax
  CSequenceTransitioner *v13; // esi
  CBaseAnimatingOverlay *v14; // ebx
  float v15; // xmm0_4
  bool v16; // zf
  float flCurPlaybackRate; // xmm1_4
  CStudioHdr *v18; // ebx
  CStudioHdr *v19; // eax
  CAnimationLayer *AnimOverlay; // ebx
  CAnimationLayer *v21; // edi
  int m_Size; // eax
  CBaseAnimatingOverlay *m_pOwnerEntity; // eax
  CBaseEdict *v24; // eax
  CAnimationLayer *v25; // ecx
  CBaseAnimatingOverlay *v26; // eax
  CBaseEdict *v27; // eax
  IChangeInfoAccessor *v28; // eax
  CBaseAnimatingOverlay *v29; // eax
  CBaseEdict *v30; // eax
  CAnimationLayer *m_pMemory; // esi
  CAnimationLayer *v32; // edx
  CSequenceTransitioner *v33; // xmm0_4
  float m_Value; // xmm1_4
  CBaseAnimatingOverlay *v35; // eax
  CBaseEdict *v36; // eax
  IChangeInfoAccessor *v37; // eax
  CAnimationLayer *v38; // esi
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm0_4
  CBaseAnimatingOverlay *v42; // eax
  CBaseEdict *v43; // eax
  IChangeInfoAccessor *v44; // eax
  float v45; // xmm0_4
  float v46; // xmm3_4
  CBaseAnimatingOverlay *v47; // eax
  CBaseEdict *v48; // eax
  IChangeInfoAccessor *v49; // eax
  float v50; // xmm1_4
  float v51; // xmm0_4
  CBaseAnimatingOverlay *v52; // eax
  CBaseEdict *v53; // eax
  IChangeInfoAccessor *v54; // eax
  float v55; // xmm0_4
  float v56; // xmm1_4
  CBaseAnimatingOverlay *v57; // eax
  CBaseEdict *v58; // eax
  IChangeInfoAccessor *v59; // eax
  float v60; // xmm0_4
  float v61; // xmm1_4
  CBaseAnimatingOverlay *v62; // eax
  CBaseEdict *v63; // eax
  float v64; // xmm1_4
  CBaseAnimatingOverlay *v65; // eax
  CBaseEdict *v66; // eax
  int nOrder; // [esp+24h] [ebp-8h]
  float flAimSequenceWeight; // [esp+28h] [ebp-4h] BYREF

  CalcAimLayerSequence = this->CalcAimLayerSequence;
  flAimSequenceWeight = 1.0;
  v10 = ((int (__thiscall *)(CBasePlayerAnimState *, float *, float *, CAnimationLayer *, int, int))CalcAimLayerSequence)(
          a1: this,
          a2: &flCycle,
          a3: &flAimSequenceWeight,
          a4: bForceIdle,
          a5: a3,
          a6: a2);
  bForceIdle = (CAnimationLayer *)v10;
  if ( v10 == -1 )
  {
    bForceIdle = nullptr;
    v10 = 0;
  }
  m_pOuter = this->m_pOuter;
  if ( m_pOuter->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: this->m_pOuter) != nullptr )
    CBaseAnimating::LockStudioHdr(this: m_pOuter);
  m_pStudioHdr = m_pOuter->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  v13 = (CSequenceTransitioner *)LODWORD(pTransitioner);
  CSequenceTransitioner::CheckForSequenceChange(
    this: (CSequenceTransitioner *)LODWORD(pTransitioner),
    hdr: m_pStudioHdr,
    nCurSequence: v10,
    bForceNewSequence: false,
    bInterpolate: true);
  v14 = this->m_pOuter;
  v15 = 1.0 - v14->m_flFrozen.m_Value;
  if ( v15 >= 0.0 )
  {
    if ( v15 > 1.0 )
      v15 = 1.0;
  }
  else
  {
    v15 = 0.0;
  }
  v16 = v14->m_pStudioHdr == nullptr;
  flCurPlaybackRate = v14->m_flPlaybackRate.m_Value * v15;
  pTransitioner = flCurPlaybackRate;
  if ( v16 )
  {
    if ( CBaseEntity::GetModel(this: v14) != nullptr )
      CBaseAnimating::LockStudioHdr(this: v14);
    flCurPlaybackRate = pTransitioner;
  }
  v18 = v14->m_pStudioHdr;
  if ( v18 != nullptr && v18->m_pStudioHdr != nullptr )
    v19 = v18;
  else
    v19 = nullptr;
  CSequenceTransitioner::UpdateCurrent(
    this: v13,
    hdr: v19,
    nCurSequence: (int)bForceIdle,
    flCurCycle: flCycle,
    flCurPlaybackRate,
    flCurTime: gpGlobals->curtime);
  AnimOverlay = CBaseAnimatingOverlay::GetAnimOverlay(this: this->m_pOuter, iIndex: SLODWORD(iFirstLayer));
  nOrder = LODWORD(iFirstLayer) + 1;
  v21 = CBaseAnimatingOverlay::GetAnimOverlay(this: this->m_pOuter, iIndex: LODWORD(iFirstLayer) + 1);
  m_Size = v13->m_animationQueue.m_Size;
  bForceIdle = v21;
  if ( m_Size == 1 )
  {
    qmemcpy(AnimOverlay, v13->m_animationQueue.m_Memory.m_pMemory, sizeof(CAnimationLayer));
    if ( AnimOverlay->m_flWeight.m_Value != 1.0 )
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
          v24 = &m_pOwnerEntity->m_Network.m_pPev->CBaseEdict;
          if ( v24 != nullptr )
          {
            v24->m_fStateFlags |= 0x101u;
            CBaseEdict::GetChangeAccessor(this: v24)->m_iChangeInfoSerialNumber = 0;
          }
        }
      }
      AnimOverlay->m_flWeight.m_Value = 1.0;
    }
    v25 = bForceIdle;
    if ( bForceIdle->m_flWeight.m_Value != 0.0 )
    {
      v26 = bForceIdle->m_pOwnerEntity;
      if ( v26 != nullptr )
      {
        if ( v26->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v26->m_Network + 76) |= 1u;
        }
        else
        {
          v27 = &v26->m_Network.m_pPev->CBaseEdict;
          if ( v27 != nullptr )
          {
            v27->m_fStateFlags |= 0x101u;
            v28 = CBaseEdict::GetChangeAccessor(this: v27);
            v25 = bForceIdle;
            v28->m_iChangeInfoSerialNumber = 0;
          }
        }
      }
      v25->m_flWeight.m_Value = 0.0;
    }
    if ( AnimOverlay->m_nOrder.m_Value != LODWORD(iFirstLayer) )
    {
      v29 = AnimOverlay->m_pOwnerEntity;
      if ( v29 != nullptr )
      {
        if ( v29->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v29->m_Network + 76) |= 1u;
          *(float *)&AnimOverlay->m_nOrder.m_Value = iFirstLayer;
          AnimOverlay->m_fFlags |= 1u;
          goto LABEL_53;
        }
        v30 = &v29->m_Network.m_pPev->CBaseEdict;
        if ( v30 != nullptr )
        {
          v30->m_fStateFlags |= 0x101u;
          CBaseEdict::GetChangeAccessor(this: v30)->m_iChangeInfoSerialNumber = 0;
        }
      }
      *(float *)&AnimOverlay->m_nOrder.m_Value = iFirstLayer;
    }
    AnimOverlay->m_fFlags |= 1u;
    goto LABEL_53;
  }
  if ( m_Size < 2 )
    goto LABEL_54;
  m_pMemory = v13->m_animationQueue.m_Memory.m_pMemory;
  v32 = bForceIdle;
  qmemcpy(AnimOverlay, m_pMemory, sizeof(CAnimationLayer));
  qmemcpy(v32, &m_pMemory[1], sizeof(CAnimationLayer));
  m_Value = v32->m_flWeight.m_Value;
  pTransitioner = 1.0 - AnimOverlay->m_flWeight.m_Value;
  *(float *)&v33 = pTransitioner;
  if ( m_Value != pTransitioner )
  {
    v35 = v32->m_pOwnerEntity;
    if ( v35 != nullptr )
    {
      if ( v35->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v35->m_Network + 76) |= 1u;
      }
      else
      {
        v36 = &v35->m_Network.m_pPev->CBaseEdict;
        if ( v36 != nullptr )
        {
          v36->m_fStateFlags |= 0x101u;
          v37 = CBaseEdict::GetChangeAccessor(this: v36);
          *(float *)&v33 = pTransitioner;
          v32 = bForceIdle;
          v37->m_iChangeInfoSerialNumber = 0;
        }
      }
    }
    v32->m_flWeight.m_Value = *(float *)&v33;
  }
  CAnimationLayer::SetOrder(this: AnimOverlay, nOrder: SLODWORD(iFirstLayer));
  v38 = bForceIdle;
  CAnimationLayer::SetOrder(this: bForceIdle, nOrder);
  AnimOverlay->m_fFlags |= 1u;
  v38->m_fFlags |= 1u;
LABEL_53:
  v21 = bForceIdle;
LABEL_54:
  v39 = flWeightScale;
  v40 = AnimOverlay->m_flWeight.m_Value;
  iFirstLayer = (float)(v40 * flWeightScale) * flAimSequenceWeight;
  v41 = iFirstLayer;
  if ( v40 != iFirstLayer )
  {
    v42 = AnimOverlay->m_pOwnerEntity;
    if ( v42 != nullptr )
    {
      if ( v42->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v42->m_Network + 76) |= 1u;
      }
      else
      {
        v43 = &v42->m_Network.m_pPev->CBaseEdict;
        if ( v43 != nullptr )
        {
          v43->m_fStateFlags |= 0x101u;
          v44 = CBaseEdict::GetChangeAccessor(this: v43);
          v39 = flWeightScale;
          v41 = iFirstLayer;
          v44->m_iChangeInfoSerialNumber = 0;
        }
      }
    }
    AnimOverlay->m_flWeight.m_Value = v41;
  }
  v45 = AnimOverlay->m_flWeight.m_Value;
  if ( v45 >= 0.0 )
  {
    if ( v45 > 1.0 )
      v45 = 1.0;
  }
  else
  {
    v45 = 0.0;
  }
  v46 = AnimOverlay->m_flWeight.m_Value;
  iFirstLayer = v45;
  if ( v46 != v45 )
  {
    v47 = AnimOverlay->m_pOwnerEntity;
    if ( v47 != nullptr )
    {
      if ( v47->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v47->m_Network + 76) |= 1u;
      }
      else
      {
        v48 = &v47->m_Network.m_pPev->CBaseEdict;
        if ( v48 != nullptr )
        {
          v48->m_fStateFlags |= 0x101u;
          v49 = CBaseEdict::GetChangeAccessor(this: v48);
          v45 = iFirstLayer;
          v39 = flWeightScale;
          v49->m_iChangeInfoSerialNumber = 0;
        }
      }
    }
    AnimOverlay->m_flWeight.m_Value = v45;
  }
  v50 = (float)(v39 * v21->m_flWeight.m_Value) * flAimSequenceWeight;
  v51 = v21->m_flWeight.m_Value;
  iFirstLayer = v50;
  if ( v51 != v50 )
  {
    v52 = v21->m_pOwnerEntity;
    if ( v52 != nullptr )
    {
      if ( v52->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v52->m_Network + 76) |= 1u;
      }
      else
      {
        v53 = &v52->m_Network.m_pPev->CBaseEdict;
        if ( v53 != nullptr )
        {
          v53->m_fStateFlags |= 0x101u;
          v54 = CBaseEdict::GetChangeAccessor(this: v53);
          v50 = iFirstLayer;
          v54->m_iChangeInfoSerialNumber = 0;
        }
      }
    }
    v21->m_flWeight.m_Value = v50;
  }
  v55 = v21->m_flWeight.m_Value;
  if ( v55 >= 0.0 )
  {
    if ( v55 > 1.0 )
      v55 = 1.0;
  }
  else
  {
    v55 = 0.0;
  }
  v56 = v21->m_flWeight.m_Value;
  iFirstLayer = v55;
  if ( v56 != v55 )
  {
    v57 = v21->m_pOwnerEntity;
    if ( v57 != nullptr )
    {
      if ( v57->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v57->m_Network + 76) |= 1u;
      }
      else
      {
        v58 = &v57->m_Network.m_pPev->CBaseEdict;
        if ( v58 != nullptr )
        {
          v58->m_fStateFlags |= 0x101u;
          v59 = CBaseEdict::GetChangeAccessor(this: v58);
          v55 = iFirstLayer;
          v59->m_iChangeInfoSerialNumber = 0;
        }
      }
    }
    v21->m_flWeight.m_Value = v55;
  }
  v60 = flCycle;
  v61 = AnimOverlay->m_flCycle.m_Value;
  iFirstLayer = flCycle;
  if ( v61 != flCycle )
  {
    v62 = AnimOverlay->m_pOwnerEntity;
    if ( v62 != nullptr )
    {
      if ( v62->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v62->m_Network + 76) |= 1u;
      }
      else
      {
        v63 = &v62->m_Network.m_pPev->CBaseEdict;
        if ( v63 != nullptr )
        {
          v63->m_fStateFlags |= 0x101u;
          CBaseEdict::GetChangeAccessor(this: v63)->m_iChangeInfoSerialNumber = 0;
        }
      }
    }
    AnimOverlay->m_flCycle.m_Value = iFirstLayer;
    v60 = flCycle;
  }
  v64 = v21->m_flCycle.m_Value;
  iFirstLayer = v60;
  if ( v64 != v60 )
  {
    v65 = v21->m_pOwnerEntity;
    if ( v65 != nullptr )
    {
      if ( v65->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v65->m_Network + 76) |= 1u;
        v21->m_flCycle.m_Value = v60;
        return;
      }
      v66 = &v65->m_Network.m_pPev->CBaseEdict;
      if ( v66 != nullptr )
      {
        v66->m_fStateFlags |= 0x101u;
        CBaseEdict::GetChangeAccessor(this: v66)->m_iChangeInfoSerialNumber = 0;
      }
    }
    v21->m_flCycle.m_Value = iFirstLayer;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10096FA0
// Name: private: void CBasePlayerAnimState::OptimizeLayerWeights(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayerAnimState::OptimizeLayerWeights(CBasePlayerAnimState *this, int iFirstLayer, int nLayers)
{
  int v3; // esi
  CAnimationLayer *AnimOverlay; // eax
  float m_Value; // xmm0_4
  CAnimationLayer *v7; // eax
  CAnimationLayer *v8; // esi
  float v9; // xmm0_4
  CBaseAnimatingOverlay *m_pOwnerEntity; // eax
  CBaseEdict *v11; // eax
  int v12; // esi
  int v13; // edi
  CAnimationLayer *v14; // eax
  int i; // edi
  CAnimationLayer *v16; // eax
  CAnimationLayer *v17; // esi
  CBaseAnimatingOverlay *v18; // eax
  CBaseEdict *v19; // eax
  float flWeight; // [esp+0h] [ebp-4h]
  float flWeighta; // [esp+0h] [ebp-4h]

  v3 = 1;
  for ( flWeight = 0.0; v3 < nLayers; ++v3 )
  {
    AnimOverlay = CBaseAnimatingOverlay::GetAnimOverlay(this: this->m_pOuter, iIndex: v3 + iFirstLayer);
    if ( (AnimOverlay->m_fFlags & 1) != 0 )
    {
      m_Value = AnimOverlay->m_flWeight.m_Value;
      if ( m_Value > 0.0 )
        flWeight = m_Value + flWeight;
    }
  }
  v7 = CBaseAnimatingOverlay::GetAnimOverlay(this: this->m_pOuter, iIndex: iFirstLayer);
  v8 = v7;
  if ( (v7->m_fFlags & 1) != 0 && v7->m_flWeight.m_Value > 0.0 )
  {
    v9 = 1.0 - flWeight;
    flWeighta = 1.0 - flWeight;
    if ( flWeighta <= 0.0 )
    {
      v9 = 0.0;
      flWeighta = 0.0;
    }
    if ( v7->m_flWeight.m_Value != v9 )
    {
      m_pOwnerEntity = v7->m_pOwnerEntity;
      if ( m_pOwnerEntity != nullptr )
      {
        if ( m_pOwnerEntity->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&m_pOwnerEntity->m_Network + 76) |= 1u;
        }
        else
        {
          v11 = &m_pOwnerEntity->m_Network.m_pPev->CBaseEdict;
          if ( v11 != nullptr )
          {
            v11->m_fStateFlags |= 0x101u;
            v9 = flWeighta;
            CBaseEdict::GetChangeAccessor(this: v11)->m_iChangeInfoSerialNumber = 0;
          }
        }
      }
      v8->m_flWeight.m_Value = v9;
    }
  }
  v12 = 0;
  v13 = -1;
  if ( nLayers > 0 )
  {
    do
    {
      v14 = CBaseAnimatingOverlay::GetAnimOverlay(this: this->m_pOuter, iIndex: v12 + iFirstLayer);
      if ( (v14->m_fFlags & 1) != 0 && v14->m_flWeight.m_Value > 0.99 )
        v13 = v12;
      ++v12;
    }
    while ( v12 < nLayers );
    if ( v13 != -1 )
    {
      for ( i = v13 - 1; i >= 0; v17->m_fFlags = 0 )
      {
        v16 = CBaseAnimatingOverlay::GetAnimOverlay(this: this->m_pOuter, iIndex: i + iFirstLayer);
        v17 = v16;
        if ( v16->m_nOrder.m_Value != 15 )
        {
          v18 = v16->m_pOwnerEntity;
          if ( v18 != nullptr )
          {
            if ( v18->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&v18->m_Network + 76) |= 1u;
            }
            else
            {
              v19 = &v18->m_Network.m_pPev->CBaseEdict;
              if ( v19 != nullptr )
              {
                v19->m_fStateFlags |= 0x101u;
                CBaseEdict::GetChangeAccessor(this: v19)->m_iChangeInfoSerialNumber = 0;
              }
            }
          }
          v17->m_nOrder.m_Value = 15;
        }
        --i;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10097120
// Name: private: void CBasePlayerAnimState::ComputeAimSequence(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBasePlayerAnimState::ComputeAimSequence(CBasePlayerAnimState *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  bool (__thiscall *ShouldBlendAimSequenceToIdle)(CBasePlayerAnimState *); // eax
  float flCycle; // [esp+1Ch] [ebp-Ch]
  float flPlaybackRate; // [esp+20h] [ebp-8h]
  bool bIsMoving; // [esp+27h] [ebp-1h] BYREF

  ShouldBlendAimSequenceToIdle = this->ShouldBlendAimSequenceToIdle;
  flCycle = this->m_pOuter->m_flCycle.m_Value;
  bIsMoving = false;
  flPlaybackRate = 0.0;
  if ( ShouldBlendAimSequenceToIdle(this) )
    flPlaybackRate = this->CalcMovementPlaybackRate(this, a2: &bIsMoving);
  CBasePlayerAnimState::UpdateAimSequenceLayers(
    this,
    a2,
    a3,
    flCycle,
    iFirstLayer: COERCE_FLOAT(1),
    bForceIdle: (CAnimationLayer *)1,
    pTransitioner: COERCE_FLOAT((CBasePlayerAnimState *)&this->m_IdleSequenceTransitioner),
    flWeightScale: 1.0 - flPlaybackRate);
  if ( bIsMoving )
    CBasePlayerAnimState::UpdateAimSequenceLayers(
      this,
      a2,
      a3,
      flCycle,
      iFirstLayer: COERCE_FLOAT(3),
      bForceIdle: nullptr,
      pTransitioner: COERCE_FLOAT((CBasePlayerAnimState *)&this->m_SequenceTransitioner),
      flWeightScale: flPlaybackRate);
  CBasePlayerAnimState::OptimizeLayerWeights(this, iFirstLayer: 1, nLayers: 4);
}

//------------------------------------------------------------------------------
// Address: 0x100971D0
// Name: public: virtual void CBasePlayerAnimState::ComputeSequences(class CStudioHdr __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayerAnimState::ComputeSequences(CBasePlayerAnimState *this, CStudioHdr *pStudioHdr)
{
  CBaseAnimatingOverlay *m_pOuter; // ebx
  Activity v4; // eax
  CBasePlayerAnimState_vtbl *v5; // edi
  int v6; // eax
  int v7; // eax

  m_pOuter = this->m_pOuter;
  v4 = this->CalcMainActivity(this);
  v5 = this->__vftable;
  this->m_eCurrentMainSequenceActivity = v4;
  v6 = v5->TranslateActivity(this, a2: v4);
  v7 = v5->SelectWeightedSequence(this, a2: (Activity)v6);
  if ( v7 < 0 )
    v7 = 0;
  CBaseAnimating::ResetSequence(this: m_pOuter, nSequence: v7);
  this->m_flMaxGroundSpeed = this->GetCurrentMaxGroundSpeed(this);
  if ( this->m_AnimConfig.m_bUseAimSequences )
    CBasePlayerAnimState::ComputeAimSequence(this, a2: (int)m_pOuter, a3: (int)v5);
}

//------------------------------------------------------------------------------
// Address: 0x10097230
// Name: public: int CUtlMap<char const __near *,int,int>::Insert(char const __near * const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CUtlMap<char const *,int,int>::Insert@<eax>(
        CUtlMap<char const *,int,int> *this@<ecx>,
        const char *a2@<edi>,
        const char **key,
        int insert)
{
  int v5; // eax
  int v6; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,int,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v5 = *(_DWORD *)insert;
  node.key = *key;
  node.elem = v5;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v6 = CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::NewNode(
         (CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)this,
         a2);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v6,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v6] != (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)-16 )
    m_pMemory[v6].m_Data = node;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x100972B0
// Name: public: int CUtlDict<int,int>::Insert(char const __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<int,int>::Insert(CUtlDict<int,int> *this, char *pName, const int *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,int,int>::Insert(
           this: &this->m_Elements,
           a2: v3,
           key: (const char **)&pName,
           insert: (int)element);
}

//------------------------------------------------------------------------------
// Address: 0x10097310
// Name: protected: virtual int CBasePlayerAnimState::CalcSequenceIndex(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
int CBasePlayerAnimState::CalcSequenceIndex(CBasePlayerAnimState *this, const char *pBaseName, ...)
{
  int result; // eax
  char szFullName[512]; // [esp+0h] [ebp-208h] BYREF
  CUtlMap<char const *,int,int>::Node_t search; // [esp+200h] [ebp-8h] BYREF
  va_list params; // [esp+218h] [ebp+10h] BYREF

  va_start(params, pBaseName);
  V_vsnprintf(pDest: szFullName, maxLen: 512, pFormat: pBaseName, params);
  result = CBaseAnimating::LookupSequence(this: this->m_pOuter, label: szFullName);
  if ( result == -1 )
  {
    if ( (_S2_43 & 1) == 0 )
    {
      _S2_43 |= 1u;
      dict.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
      dict.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
      dict.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
      dict.m_Elements.m_Tree.m_Root = -1;
      dict.m_Elements.m_Tree.m_NumElements = 0;
      dict.m_Elements.m_Tree.m_FirstFree = -1;
      dict.m_Elements.m_Tree.m_LastAlloc.index = -1;
      dict.m_Elements.m_Tree.m_pElements = nullptr;
      dict.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
      atexit(func: CBasePlayerAnimState::CalcSequenceIndex_::_5_::_dynamic_atexit_destructor_for__dict__);
    }
    search.key = szFullName;
    if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
           this: &dict.m_Elements.m_Tree,
           &search) == -1 )
    {
      this = nullptr;
      CUtlDict<int,int>::Insert(this: &dict, pName: szFullName, element: (const int *)&this);
      _Warning(a1: "CalcSequenceIndex: can't find '%s'.\n", szFullName);
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A1F70
// Name: public: virtual enum Activity CBasePlayerAnimState::TranslateActivity(enum Activity)
// Source: json
//------------------------------------------------------------------------------
Activity __thiscall CBasePlayerAnimState::TranslateActivity(CBasePlayerAnimState *this, Activity actDesired)
{
  return actDesired;
}

} // namespace server
