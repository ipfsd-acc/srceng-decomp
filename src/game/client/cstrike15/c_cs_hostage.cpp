// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/c_cs_hostage.cpp
// Functions: 44
// ============================================================

#include "game\client\cstrike15\c_cs_hostage.h"

//------------------------------------------------------------------------------
// Address: 0x1005DF40
// Name: public: virtual int C_CHostage::GetHealth(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_CHostage::GetHealth(C_BasePlayer *this)
{
  return this->m_iHealth;
}

//------------------------------------------------------------------------------
// Address: 0x101B6BC0
// Name: public: virtual class ClientClass __near * C_CHostage::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_CHostage::GetClientClass(C_CHostage *this)
{
  return &__g_C_CHostageClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x101B6BD0
// Name: public: virtual bool C_CHostage::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CHostage::ShouldDraw(C_CHostage *this)
{
  return LOBYTE(this->m_seq) == 0 && C_BaseEntity::ShouldDraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x101B6BF0
// Name: public: virtual void C_CHostage::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CHostage::ClientThink(C_CHostage *this)
{
  C_BaseEntity *v2; // esi
  unsigned __int8 RenderAlpha; // al

  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  v2 = (C_CHostage *)((char *)this - 12);
  RenderAlpha = C_BaseEntity::GetRenderAlpha(this: v2);
  C_BaseEntity::SetRenderAlpha(this: v2, a: RenderAlpha < 2u ? 0 : RenderAlpha - 2);
  if ( C_BaseEntity::GetRenderAlpha(this: v2) != 0 )
    ((void (__thiscall *)(C_BaseEntity *, _DWORD))v2->SetNextClientThink)(
      a1: v2,
      a2: *(float *)(gpGlobals.m_Index + 12) + 0.001);
}

//------------------------------------------------------------------------------
// Address: 0x101B6C50
// Name: public: virtual void C_CHostage::OnPreDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CHostage::OnPreDataChanged(C_CHostage *this, DataUpdateType_t updateType)
{
  C_BaseAnimating::OnPreDataChanged(this, updateType);
  *(&this->m_bloodColor + 1) = this->m_iName[259];
}

//------------------------------------------------------------------------------
// Address: 0x101B6C80
// Name: public: virtual void C_CHostage::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CHostage::OnDataChanged(C_CHostage *this, DataUpdateType_t updateType)
{
  char v3; // al

  C_BaseAnimating::OnDataChanged(this, updateType);
  v3 = this->m_iName[259];
  if ( *(&this->m_bloodColor + 1) != v3 && (v3 == 2 || v3 == 1) )
    *(float *)&this->m_leader.m_Value.m_Index = *(float *)(gpGlobals.m_Index + 12) + 2.0;
}

//------------------------------------------------------------------------------
// Address: 0x101B6CD0
// Name: public: class C_CSPlayer __near * C_CHostage::GetLeader(void)const
// Source: json
//------------------------------------------------------------------------------
C_CSPlayer *__thiscall C_CHostage::GetLeader(C_CHostage *this)
{
  unsigned int m_Index; // ecx
  CEntInfo *v2; // eax
  IHandleEntity *m_pEntity; // esi

  m_Index = this->m_leader.m_Value.m_Index;
  if ( m_Index != -1
    && (v2 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
    && (m_pEntity = v2->m_pEntity, v2->m_pEntity != nullptr)
    && m_pEntity->__vftable[48].GetRefEHandle(this: m_pEntity) != nullptr )
  {
    return (C_CSPlayer *)m_pEntity;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B6D70
// Name: public: bool C_LowViolenceHostageDeathModel::SetupLowViolenceModel(class C_CHostage __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_LowViolenceHostageDeathModel::SetupLowViolenceModel(
        C_LowViolenceHostageDeathModel *this,
        C_CHostage *pHostage)
{
  const struct model_t *v3; // eax
  const char *v4; // eax
  void (__thiscall *SetNextClientThink)(C_BaseEntity *, float); // eax
  int v7; // eax
  const Vector *v8; // eax
  const Vector *v9; // eax
  const QAngle *v10; // eax
  const QAngle *v11; // eax
  CStudioHdr *ModelPtr; // ebx
  const char **v13; // edi
  int v14; // eax
  float poseParameter[24]; // [esp+28h] [ebp-60h] BYREF

  v3 = pHostage->GetModel(this: &pHostage->IClientRenderable);
  v4 = modelinfo->GetModelName(this: modelinfo, a2: v3);
  if ( !this->InitializeAsClientEntity(this, a2: v4, a3: false)
    || C_BaseAnimating::LookupSequence(this, label: "death1") == -1 )
  {
    this->Release(this: &this->IClientNetworkable);
    return 0;
  }
  else
  {
    SetNextClientThink = this->SetNextClientThink;
    this->m_flFadeOutStart = *(float *)(gpGlobals.m_Index + 12) + 5.0;
    ((void (__thiscall *)(C_LowViolenceHostageDeathModel *, int))SetNextClientThink)(a1: this, a2: -996040704);
    v7 = C_BaseAnimating::LookupSequence(this, label: "death1");
    C_BaseAnimating::SetSequence(this, nSequence: v7);
    C_BaseAnimating::ForceClientSideAnimationOn(this);
    if ( !pHostage->IsDormant(this: &pHostage->IClientNetworkable) )
    {
      v8 = pHostage->GetAbsOrigin(this: pHostage);
      C_BaseEntity::SetNetworkOrigin(this, org: v8);
      v9 = pHostage->GetAbsOrigin(this: pHostage);
      C_BaseEntity::SetAbsOrigin(this, absOrigin: v9);
      C_BaseEntity::CalcAbsoluteVelocity(this: pHostage);
      C_BaseEntity::SetAbsVelocity(this, vecAbsVelocity: &pHostage->m_vecAbsVelocity);
      C_BaseEntity::SnatchModelInstance(this: pHostage, pToEntity: this);
      v10 = pHostage->GetRenderAngles(this: &pHostage->IClientRenderable);
      C_BaseEntity::SetAbsAngles(this, absAngles: v10);
      v11 = pHostage->GetRenderAngles(this: &pHostage->IClientRenderable);
      C_BaseEntity::SetNetworkAngles(this, ang: v11);
      ModelPtr = C_BaseAnimating::GetModelPtr(this);
      this->GetPoseParameters(this, a2: ModelPtr, a3: poseParameter);
      v13 = InterestingPoseParameters;
      do
      {
        v14 = C_BaseAnimating::LookupPoseParameter(this, pstudiohdr: ModelPtr, szName: *v13);
        C_BaseAnimating::SetPoseParameter(this, pStudioHdr: ModelPtr, iParameter: v14, flValue: poseParameter[v14]);
        ++v13;
      }
      while ( (int)v13 < (int)&C_CHostage::m_pClassRecvTable );
    }
    C_BaseEntity::Interp_Reset(this, map: &this->m_VarMap);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B6F00
// Name: public: virtual void C_LowViolenceHostageDeathModel::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_LowViolenceHostageDeathModel::ClientThink(C_LowViolenceHostageDeathModel *this)
{
  int RenderAlpha; // edx
  int m_nValue; // ecx
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm0_4

  if ( this->m_vecRenderOriginOverride.y <= *(float *)(gpGlobals.m_Index + 12) )
  {
    RenderAlpha = C_BaseEntity::GetRenderAlpha(this: (C_LowViolenceHostageDeathModel *)((char *)this - 12));
    if ( g_ragdoll_fadespeed.m_pParent != nullptr )
      m_nValue = g_ragdoll_fadespeed.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v4 = *(float *)(gpGlobals.m_Index + 16);
    if ( (float)((float)RenderAlpha - (float)((float)m_nValue * v4)) <= 0.0 )
    {
      v6 = 0.0;
    }
    else
    {
      if ( g_ragdoll_fadespeed.m_pParent != nullptr )
        v5 = (float)g_ragdoll_fadespeed.m_pParent->m_Value.m_nValue * v4;
      else
        v5 = (float)0 * v4;
      v6 = (float)RenderAlpha - v5;
    }
    C_BaseEntity::SetRenderMode(
      this: (C_LowViolenceHostageDeathModel *)((char *)this - 12),
      nRenderMode: kRenderTransAlpha,
      bForceUpdate: false);
    C_BaseEntity::SetRenderAlpha(this: (C_LowViolenceHostageDeathModel *)((char *)this - 12), a: (int)v6);
    if ( (int)v6 == 0 )
      (*(void (__thiscall **)(char *))(*((_DWORD *)this - 1) + 4))(a1: (char *)this - 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B6FC0
// Name: private: void C_CHostage::Initialize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CHostage::Initialize(C_CHostage *this)
{
  int v2; // eax
  bool v3; // zf
  CStudioHdr *m_pStudioHdr; // eax
  int v5; // eax
  CStudioHdr *v6; // eax
  int v7; // eax
  CStudioHdr *v8; // eax
  int v9; // eax
  const Vector *v10; // eax
  float v11; // xmm1_4
  float v12; // xmm2_4
  Vector *(__thiscall *EyePosition)(C_BaseEntity *, Vector *); // edx
  float *v14; // eax
  float v15; // xmm2_4
  float v16; // xmm0_4
  Vector v17; // [esp+8h] [ebp-3Ch] BYREF
  QAngle angles; // [esp+14h] [ebp-30h] BYREF
  Vector forward; // [esp+20h] [ebp-24h] BYREF
  Vector pos; // [esp+2Ch] [ebp-18h] BYREF
  float v21; // [esp+38h] [ebp-Ch]
  float v22; // [esp+3Ch] [ebp-8h]
  float v23; // [esp+40h] [ebp-4h]

  this->m_eyeAttachment = this->LookupAttachment(this: &this->IClientRenderable, a2: "eyes");
  v2 = this->LookupAttachment(this: &this->IClientRenderable, a2: "chest");
  v3 = this->m_pStudioHdr == nullptr;
  this->m_chestAttachment = v2;
  if ( v3 && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  v5 = C_BaseAnimating::LookupPoseParameter(this, pstudiohdr: m_pStudioHdr, szName: "head_yaw");
  this->m_headYawPoseParam = v5;
  C_BaseAnimating::GetPoseParameterRange(this, index: v5, minValue: &this->m_headYawMin, maxValue: &this->m_headYawMax);
  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  v6 = this->m_pStudioHdr;
  if ( v6 == nullptr || v6->m_pStudioHdr == nullptr )
    v6 = nullptr;
  v7 = C_BaseAnimating::LookupPoseParameter(this, pstudiohdr: v6, szName: "head_pitch");
  this->m_headPitchPoseParam = v7;
  C_BaseAnimating::GetPoseParameterRange(
    this,
    index: v7,
    minValue: &this->m_headPitchMin,
    maxValue: &this->m_headPitchMax);
  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  v8 = this->m_pStudioHdr;
  if ( v8 == nullptr || v8->m_pStudioHdr == nullptr )
    v8 = nullptr;
  v9 = C_BaseAnimating::LookupPoseParameter(this, pstudiohdr: v8, szName: "body_yaw");
  this->m_bodyYawPoseParam = v9;
  C_BaseAnimating::GetPoseParameterRange(this, index: v9, minValue: &this->m_bodyYawMin, maxValue: &this->m_bodyYawMax);
  if ( this->GetAttachment_2(this: &this->IClientRenderable, a2: this->m_eyeAttachment, a3: &pos, a4: &angles) )
  {
    v10 = this->GetAbsOrigin(this);
    v11 = pos.y - v10->y;
    v12 = pos.z - v10->z;
    this->m_vecViewOffset.x = pos.x - v10->x;
    this->m_vecViewOffset.y = v11;
    this->m_vecViewOffset.z = v12;
  }
  else
  {
    this->m_vecViewOffset.x = 0.0;
    this->m_vecViewOffset.y = 0.0;
    this->m_vecViewOffset.z = 50.0;
  }
  if ( this->GetAttachment_2(this: &this->IClientRenderable, a2: this->m_chestAttachment, a3: &pos, a4: &angles) )
  {
    AngleVectors(&angles, &forward);
    EyePosition = this->EyePosition;
    v21 = forward.x * 100.0;
    v22 = forward.y * 100.0;
    v23 = forward.z * 100.0;
    v14 = (float *)EyePosition(this, result: &v17);
    v15 = v14[2] + v23;
    v16 = *v14 + v21;
    this->m_lookAt.y = v14[1] + v22;
    this->m_lookAt.z = v15;
    this->m_lookAt.x = v16;
  }
  else
  {
    this->m_lookAt.y = 0.0;
    this->m_lookAt.z = 0.0;
    this->m_lookAt.x = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B7260
// Name: public: virtual void C_CHostage::ImpactTrace(class CGameTrace __near *,int,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CHostage::ImpactTrace(C_CHostage *this, CGameTrace *pTrace, int iDamageType, char *pCustomImpactName)
{
  ConVar *v5; // eax
  ConVar *m_pParent; // eax

  if ( (_S6_50 & 1) != 0 )
  {
    v5 = violence_hblood_0;
  }
  else
  {
    _S6_50 |= 1u;
    v5 = cvar->FindVar_2(this: cvar, a2: "violence_hblood");
    violence_hblood_0 = v5;
  }
  if ( v5 == nullptr || (m_pParent = v5->m_pParent) != nullptr && m_pParent->m_Value.m_nValue != 0 )
    C_BaseEntity::ImpactTrace(this, pTrace, iDamageType, pCustomImpactName);
}

//------------------------------------------------------------------------------
// Address: 0x101B72C0
// Name: private: void C_CHostage::UpdateLookAt(class CStudioHdr __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CHostage::UpdateLookAt(C_CHostage *this, CStudioHdr *pStudioHdr)
{
  C_CSPlayer *Leader; // eax
  float *v4; // eax
  IUniformRandomStream *v5; // ecx
  Vector *v6; // eax
  float v8; // xmm0_4
  float v9; // xmm1_4
  float target; // xmm0_4
  double v11; // st7
  long double v12; // st7
  int m_headYawPoseParam; // edx
  float m_headPitchMin; // xmm0_4
  int m_headPitchPoseParam; // ecx
  float angle; // [esp+8h] [ebp-9Ch]
  float duration; // [esp+14h] [ebp-90h]
  float poseParams[24]; // [esp+1Ch] [ebp-88h] BYREF
  Vector v19; // [esp+7Ch] [ebp-28h] BYREF
  QAngle desiredAngles; // [esp+88h] [ebp-1Ch] BYREF
  Vector to; // [esp+94h] [ebp-10h] BYREF
  float flBodyYawDiff; // [esp+A0h] [ebp-4h]
  float desired; // [esp+ACh] [ebp+8h]
  float desiredb; // [esp+ACh] [ebp+8h]
  float desireda; // [esp+ACh] [ebp+8h]
  float desiredc; // [esp+ACh] [ebp+8h]
  float desiredd; // [esp+ACh] [ebp+8h]

  if ( !this->m_isInit )
  {
    this->m_isInit = true;
    C_CHostage::Initialize(this);
  }
  if ( this->m_headYawPoseParam >= 0 && this->m_bodyYawPoseParam >= 0 && this->m_headPitchPoseParam >= 0 )
  {
    if ( C_CHostage::GetLeader(this) != nullptr )
    {
      Leader = C_CHostage::GetLeader(this);
      v4 = (float *)Leader->EyePosition(this: Leader, result: &v19);
      this->m_lookAt.x = *v4;
      this->m_lookAt.y = v4[1];
      this->m_lookAt.z = v4[2];
    }
    this->m_viewtarget.x = this->m_lookAt.x;
    this->m_viewtarget.y = this->m_lookAt.y;
    this->m_viewtarget.z = this->m_lookAt.z;
    if ( CountdownTimer::Now(this: (CEffectsClient *)&this->m_blinkTimer) > this->m_blinkTimer.m_timestamp.m_Value )
    {
      this->m_blinktoggle = this->m_blinktoggle == 0;
      duration = _RandomFloat(this: v5, a2: 1.5, a3: 4.0);
      CountdownTimer::Start(this: &this->m_blinkTimer, duration);
    }
    v6 = this->EyePosition(this, result: &v19);
    to.x = this->m_lookAt.x - v6->x;
    to.y = this->m_lookAt.y - v6->y;
    to.z = this->m_lookAt.z - v6->z;
    VectorAngles(forward: &to, angles: &desiredAngles);
    this->GetPoseParameters(this, a2: pStudioHdr, a3: poseParams);
    v8 = (float)((float)((float)(this->m_bodyYawMax - this->m_bodyYawMin) * poseParams[this->m_bodyYawPoseParam])
               + this->m_bodyYawMin)
       + this->GetRenderAngles(this: &this->IClientRenderable)->y;
    flBodyYawDiff = v8 - this->m_flLastBodyYaw;
    v9 = desiredAngles.y - v8;
    this->m_flLastBodyYaw = v8;
    desired = AngleNormalize(angle: v9);
    target = this->m_headYawMin;
    if ( target <= desired )
    {
      target = this->m_headYawMax;
      if ( desired <= target )
        target = desired;
    }
    v11 = ApproachAngle(
            target,
            value: this->m_flCurrentHeadYaw,
            speed: *(float *)(gpGlobals.m_Index + 16) * HOSTAGE_HEAD_TURN_RATE);
    this->m_flCurrentHeadYaw = v11;
    angle = v11 - flBodyYawDiff;
    v12 = AngleNormalize(angle);
    m_headYawPoseParam = this->m_headYawPoseParam;
    desiredb = v12;
    this->m_flCurrentHeadYaw = v12;
    C_BaseAnimating::SetPoseParameter(this, pStudioHdr, iParameter: m_headYawPoseParam, flValue: desiredb);
    desireda = AngleNormalize(angle: desiredAngles.x);
    m_headPitchMin = this->m_headPitchMin;
    if ( m_headPitchMin <= desireda )
    {
      m_headPitchMin = this->m_headPitchMax;
      if ( desireda <= m_headPitchMin )
        m_headPitchMin = desireda;
    }
    desiredc = ApproachAngle(
                 target: m_headPitchMin,
                 value: this->m_flCurrentHeadPitch,
                 speed: *(float *)(gpGlobals.m_Index + 16) * HOSTAGE_HEAD_TURN_RATE);
    this->m_flCurrentHeadPitch = desiredc;
    desiredd = AngleNormalize(angle: desiredc);
    m_headPitchPoseParam = this->m_headPitchPoseParam;
    this->m_flCurrentHeadPitch = desiredd;
    C_BaseAnimating::SetPoseParameter(this, pStudioHdr, iParameter: m_headPitchPoseParam, flValue: desiredd);
    C_BaseAnimating::SetPoseParameter(this, pStudioHdr, szName: "head_roll", flValue: 0.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B7600
// Name: private: void C_CHostage::LookAround(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall C_CHostage::LookAround(C_CHostage *this)
{
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  IUniformRandomStream *v4; // ecx
  const QAngle *v5; // eax
  float m_headYawMin; // xmm0_4
  double v7; // st7
  float m_headPitchMin; // xmm0_4
  IUniformRandomStream *v9; // ecx
  Vector *(__thiscall *EyePosition)(C_BaseEntity *, Vector *); // edx
  float *v11; // eax
  float v12; // xmm1_4
  float v13; // xmm2_4
  float duration; // [esp+Ch] [ebp-34h]
  float durationa; // [esp+Ch] [ebp-34h]
  float v16; // [esp+10h] [ebp-30h] BYREF
  float m_headPitchMax; // [esp+14h] [ebp-2Ch]
  Vector forward; // [esp+1Ch] [ebp-24h] BYREF
  float v19; // [esp+28h] [ebp-18h]
  float v20; // [esp+2Ch] [ebp-14h]
  float v21; // [esp+30h] [ebp-10h]
  QAngle angles; // [esp+34h] [ebp-Ch] BYREF

  m_Index = this->m_leader.m_Value.m_Index;
  if ( (m_Index == -1
     || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
     || (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) == nullptr
     || m_pEntity->__vftable[48].GetRefEHandle(this: m_pEntity) == nullptr)
    && CountdownTimer::Now(this: (CEffectsClient *)&this->m_lookAroundTimer) > this->m_lookAroundTimer.m_timestamp.m_Value )
  {
    duration = _RandomFloat(this: v4, a2: 3.0, a3: 15.0);
    CountdownTimer::Start(this: &this->m_lookAroundTimer, duration);
    v5 = this->GetAbsAngles(this);
    *(_QWORD *)&angles.x = *(_QWORD *)&v5->x;
    durationa = this->m_headYawMax;
    m_headYawMin = this->m_headYawMin;
    angles.z = v5->z;
    v7 = _RandomFloat(this: (IUniformRandomStream *)LODWORD(angles.z), a2: m_headYawMin, a3: durationa);
    m_headPitchMax = this->m_headPitchMax;
    m_headPitchMin = this->m_headPitchMin;
    angles.y = v7 + angles.y;
    angles.x = _RandomFloat(this: v9, a2: m_headPitchMin, a3: m_headPitchMax) + angles.x;
    AngleVectors(&angles, &forward);
    EyePosition = this->EyePosition;
    v19 = forward.x * 100.0;
    v20 = forward.y * 100.0;
    v21 = forward.z * 100.0;
    v11 = (float *)EyePosition(this, result: (Vector *)&v16);
    v12 = v11[1] + v20;
    v13 = v11[2] + v21;
    this->m_lookAt.x = *v11 + v19;
    this->m_lookAt.y = v12;
    this->m_lookAt.z = v13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B77A0
// Name: public: virtual void C_CHostage::UpdateClientSideAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CHostage::UpdateClientSideAnimation(C_CHostage *this)
{
  ICSPlayerAnimState *m_PlayerAnimState; // edi
  char **v3; // eax
  const QAngle *(__thiscall *GetAbsAngles)(IClientEntity *); // edx
  int v5; // eax
  int v6; // ecx
  bool v7; // zf
  CStudioHdr *m_pStudioHdr; // ebx
  unsigned int i; // edi
  int v10; // eax
  char *setToZero[2]; // [esp+18h] [ebp-8h]

  if ( !this->IsDormant(this: &this->IClientNetworkable) )
  {
    m_PlayerAnimState = this->m_PlayerAnimState;
    v3 = (char **)this->GetAbsAngles(this);
    GetAbsAngles = this->GetAbsAngles;
    setToZero[1] = *v3;
    v5 = (int)GetAbsAngles(this);
    v6 = (int)&m_PlayerAnimState->gap4[*(_DWORD *)(*(_DWORD *)m_PlayerAnimState->gap4 + 4)];
    (*(void (__thiscall **)(int, _DWORD, char *))(*(_DWORD *)v6 + 4))(a1: v6, a2: *(_DWORD *)(v5 + 4), a3: setToZero[1]);
    v7 = this->m_pStudioHdr == nullptr;
    setToZero[0] = "spine_yaw";
    setToZero[1] = "head_roll";
    if ( v7 && this->GetModel(this: &this->IClientRenderable) != nullptr )
      C_BaseAnimating::LockStudioHdr(this);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
      m_pStudioHdr = nullptr;
    for ( i = 0; i < 2; ++i )
    {
      v10 = C_BaseAnimating::LookupPoseParameter(this, pstudiohdr: m_pStudioHdr, szName: setToZero[i]);
      if ( v10 >= 0 )
        C_BaseAnimating::SetPoseParameter(this, pStudioHdr: m_pStudioHdr, iParameter: v10, flValue: 0.0);
    }
    C_CHostage::LookAround(this);
    C_CHostage::UpdateLookAt(this, pStudioHdr: m_pStudioHdr);
    C_BaseAnimating::UpdateClientSideAnimation(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B7890
// Name: private: static void C_CHostage::RecvProxy_Rescued(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_CHostage::RecvProxy_Rescued(const CRecvProxyData *pData, float *pStruct)
{
  char v2; // bl

  v2 = pData->m_Value.m_Int != 0;
  if ( pData->m_Value.m_Int != 0 && *((_BYTE *)pStruct + 4676) == 0 )
  {
    pStruct[1170] = *(float *)(gpGlobals.m_Index + 12) + 2.0;
    C_BaseEntity::SetRenderMode(this: (C_BaseEntity *)pStruct, nRenderMode: kRenderGlow, bForceUpdate: false);
    (*(void (__thiscall **)(float *, _DWORD))(*(_DWORD *)pStruct + 456))(
      a1: pStruct,
      a2: *(_DWORD *)(gpGlobals.m_Index + 12));
  }
  if ( *((_BYTE *)pStruct + 4676) != v2 )
    *((_BYTE *)pStruct + 4676) = v2;
}

//------------------------------------------------------------------------------
// Address: 0x101B7A10
// Name: public: virtual C_CHostage::~C_CHostage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CHostage::~C_CHostage(C_CHostage *this)
{
  void (__thiscall ***v2)(_DWORD); // ecx
  vgui::TreeNode *src; // [esp+4h] [ebp-4h] BYREF

  this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_CHostage_vtbl *)&C_CHostage::`vftable'{for `IClientUnknown'};
  this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_CHostage::`vftable'{for `IClientRenderable'};
  this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_CHostage::`vftable'{for `IClientNetworkable'};
  this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_CHostage::`vftable'{for `IClientThinkable'};
  this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_CHostage::`vftable'{for `C_BaseCombatCharacter'};
  this->ICSPlayerAnimStateHelpers::__vftable = (ICSPlayerAnimStateHelpers_vtbl *)&C_CHostage::`vftable'{for `ICSPlayerAnimStateHelpers'};
  src = (vgui::TreeNode *)this;
  CUtlVector<C_BaseParticleEntity *,CUtlMemory<C_BaseParticleEntity *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_Hostages,
    &src);
  v2 = (void (__thiscall ***)(_DWORD))&this->m_PlayerAnimState->gap4[*(_DWORD *)(*(_DWORD *)this->m_PlayerAnimState->gap4
                                                                               + 4)];
  (**v2)(a1: v2);
  C_BaseCombatCharacter::~C_BaseCombatCharacter(this);
}

//------------------------------------------------------------------------------
// Address: 0x101B7A80
// Name: public: virtual int C_CHostage::GetMaxHealth(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_CHostage::GetMaxHealth(C_CHostage *this)
{
  return this->m_iMaxHealth;
}

//------------------------------------------------------------------------------
// Address: 0x101B7A90
// Name: public: virtual void C_CHostage::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CHostage::Spawn(C_CHostage *this)
{
  IHandleEntity *m_pEntity; // edi
  unsigned int m_Index; // edx
  IHandleEntity *v3; // eax
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi

  if ( g_pEntityList->m_EntPtrArray[0].m_SerialNumber != 0 )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[0].m_pEntity;
  m_Index = this->m_leader.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    v3 = nullptr;
  else
    v3 = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( v3 != m_pEntity )
    this->m_leader.m_Value.m_Index = 0;
  p_m_timestamp = &this->m_blinkTimer.m_timestamp;
  if ( this->m_blinkTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_blinkTimer.NetworkStateChanged(this: &this->m_blinkTimer, a2: p_m_timestamp);
    p_m_timestamp->m_Value = -1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B7B10
// Name: public: C_CHostage::C_CHostage(void)
// Source: json
//------------------------------------------------------------------------------
C_CHostage *__thiscall C_CHostage::C_CHostage(C_CHostage *this)
{
  CountdownTimer_vtbl *v2; // edx
  CountdownTimer_vtbl *v3; // edx
  CountdownTimer_vtbl *v4; // edx
  CountdownTimer_vtbl *v5; // edx
  int m_Size; // eax
  int v7; // ebx
  C_CHostage **m_pMemory; // ecx
  int v9; // eax
  C_CHostage **v10; // ebx
  IHandleEntity *m_pEntity; // edi
  unsigned int m_Index; // ecx
  IHandleEntity *v13; // eax

  C_BaseCombatCharacter::C_BaseCombatCharacter(this);
  this->ICSPlayerAnimStateHelpers::__vftable = (ICSPlayerAnimStateHelpers_vtbl *)&ICSPlayerAnimStateHelpers::`vftable';
  this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_CHostage_vtbl *)&C_CHostage::`vftable'{for `IClientUnknown'};
  this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_CHostage::`vftable'{for `IClientRenderable'};
  this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_CHostage::`vftable'{for `IClientNetworkable'};
  this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_CHostage::`vftable'{for `IClientThinkable'};
  this->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_CHostage::`vftable'{for `C_BaseCombatCharacter'};
  this->ICSPlayerAnimStateHelpers::__vftable = (ICSPlayerAnimStateHelpers_vtbl *)&C_CHostage::`vftable'{for `ICSPlayerAnimStateHelpers'};
  this->m_leader.m_Value.m_Index = -1;
  this->m_blinkTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v2 = this->m_blinkTimer.__vftable;
  this->m_blinkTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v2->NetworkStateChanged)(a1: &this->m_blinkTimer.m_duration);
  v3 = this->m_blinkTimer.__vftable;
  this->m_blinkTimer.m_timestamp.m_Value = -1.0;
  v3->NetworkStateChanged(this: &this->m_blinkTimer, a2: &this->m_blinkTimer.m_timestamp);
  this->m_lookAroundTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v4 = this->m_lookAroundTimer.__vftable;
  this->m_lookAroundTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v4->NetworkStateChanged)(a1: &this->m_lookAroundTimer.m_duration);
  v5 = this->m_lookAroundTimer.__vftable;
  this->m_lookAroundTimer.m_timestamp.m_Value = -1.0;
  v5->NetworkStateChanged(this: &this->m_lookAroundTimer, a2: &this->m_lookAroundTimer.m_timestamp);
  m_Size = g_Hostages.m_Size;
  v7 = g_Hostages.m_Size;
  if ( g_Hostages.m_Size + 1 > g_Hostages.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&g_Hostages,
      num: g_Hostages.m_Size - g_Hostages.m_Memory.m_nAllocationCount + 1);
    m_Size = g_Hostages.m_Size;
  }
  m_pMemory = g_Hostages.m_Memory.m_pMemory;
  g_Hostages.m_Size = m_Size + 1;
  v9 = m_Size - v7;
  g_Hostages.m_pElements = g_Hostages.m_Memory.m_pMemory;
  if ( v9 > 0 )
  {
    _V_memmove(dest: &g_Hostages.m_Memory.m_pMemory[v7 + 1], src: &g_Hostages.m_Memory.m_pMemory[v7], count: 4 * v9);
    m_pMemory = g_Hostages.m_Memory.m_pMemory;
  }
  v10 = &m_pMemory[v7];
  if ( v10 != nullptr )
    *v10 = this;
  this->m_EntClientFlags |= 2u;
  this->m_flDeadOrRescuedTime = 0.0;
  this->m_flLastBodyYaw = 0.0;
  this->m_createdLowViolenceRagdoll = false;
  C_BaseEntity::SetModelName(this, name: "models/Characters/Hostage_01.mdl");
  this->m_PlayerAnimState = CreateHostageAnimState(
                              pEntity: this,
                              pHelpers: &this->ICSPlayerAnimStateHelpers,
                              legAnimType: LEGANIM_8WAY,
                              bUseAimSequences: false);
  if ( g_pEntityList->m_EntPtrArray[0].m_SerialNumber != 0 )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[0].m_pEntity;
  m_Index = this->m_leader.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    v13 = nullptr;
  else
    v13 = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( v13 != m_pEntity )
    this->m_leader.m_Value.m_Index = 0;
  if ( this->m_blinkTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_blinkTimer.NetworkStateChanged(this: &this->m_blinkTimer, a2: &this->m_blinkTimer.m_timestamp);
    this->m_blinkTimer.m_timestamp.m_Value = -1.0;
  }
  this->m_seq = -1;
  this->m_flCurrentHeadPitch = 0.0;
  this->m_flCurrentHeadYaw = 0.0;
  this->m_eyeAttachment = -1;
  this->m_chestAttachment = -1;
  this->m_headYawPoseParam = -1;
  this->m_headPitchPoseParam = -1;
  this->m_lookAt.x = 0.0;
  this->m_lookAt.y = 0.0;
  this->m_lookAt.z = 0.0;
  this->m_isInit = false;
  if ( this->m_lookAroundTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_lookAroundTimer.NetworkStateChanged(
      this: &this->m_lookAroundTimer,
      a2: &this->m_lookAroundTimer.m_timestamp);
    this->m_lookAroundTimer.m_timestamp.m_Value = -1.0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101B7DB0
// Name: public: virtual class C_BaseAnimating __near * C_CHostage::BecomeRagdollOnClient(void)
// Source: json
//------------------------------------------------------------------------------
C_LowViolenceHostageDeathModel *__usercall C_CHostage::BecomeRagdollOnClient@<eax>(
        C_CHostage *this@<ecx>,
        int a2@<ebp>,
        int a3@<esi>)
{
  C_BaseAnimating *v4; // eax
  C_LowViolenceHostageDeathModel *v5; // esi
  bool v6; // al
  int m_Index; // ebx
  int m_Size; // eax
  int v9; // edi
  CHandle<C_BaseEntity> *m_pMemory; // ecx
  int v11; // eax
  CHandle<C_BaseEntity> *v12; // ecx
  C_ClientRagdoll *v14; // eax
  C_ClientRagdoll *v15; // ebx
  unsigned int v16; // edi
  int v17; // eax
  int v18; // esi
  CHandle<C_BaseEntity> *v19; // ecx
  int v20; // eax
  CHandle<C_BaseEntity> *v21; // ecx

  if ( g_RagdollLVManager.m_bLowViolence )
  {
    v4 = (C_BaseAnimating *)C_BaseEntity::operator new(stAllocateBlock: 0xCC0u);
    v5 = (C_LowViolenceHostageDeathModel *)v4;
    if ( v4 != nullptr )
    {
      C_BaseAnimating::C_BaseAnimating(this: v4);
      v5->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_LowViolenceHostageDeathModel_vtbl *)&C_LowViolenceHostageDeathModel::`vftable'{for `IClientUnknown'};
      v5->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_LowViolenceHostageDeathModel::`vftable'{for `IClientRenderable'};
      v5->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_LowViolenceHostageDeathModel::`vftable'{for `IClientNetworkable'};
      v5->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_LowViolenceHostageDeathModel::`vftable'{for `IClientThinkable'};
      v5->C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_LowViolenceHostageDeathModel::`vftable';
    }
    else
    {
      v5 = nullptr;
    }
    v6 = C_LowViolenceHostageDeathModel::SetupLowViolenceModel(this: v5, pHostage: this);
    this->m_createdLowViolenceRagdoll = v6;
    if ( v6 )
    {
      C_BaseEntity::UpdateVisibility(this);
      if ( v5 != nullptr )
        m_Index = v5->GetRefEHandle(this: v5)->m_Index;
      else
        m_Index = -1;
      m_Size = g_HostageRagdolls.m_Size;
      v9 = g_HostageRagdolls.m_Size;
      if ( g_HostageRagdolls.m_Size + 1 > g_HostageRagdolls.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&g_HostageRagdolls,
          num: g_HostageRagdolls.m_Size - g_HostageRagdolls.m_Memory.m_nAllocationCount + 1);
        m_Size = g_HostageRagdolls.m_Size;
      }
      m_pMemory = g_HostageRagdolls.m_Memory.m_pMemory;
      g_HostageRagdolls.m_Size = m_Size + 1;
      v11 = m_Size - v9;
      g_HostageRagdolls.m_pElements = g_HostageRagdolls.m_Memory.m_pMemory;
      if ( v11 > 0 )
      {
        _V_memmove(
          dest: (void *)&g_HostageRagdolls.m_Memory.m_pMemory[v9 + 1],
          src: &g_HostageRagdolls.m_Memory.m_pMemory[v9],
          count: 4 * v11);
        m_pMemory = g_HostageRagdolls.m_Memory.m_pMemory;
      }
      v12 = &m_pMemory[v9];
      if ( v12 != nullptr )
        v12->m_Index = m_Index;
      return v5;
    }
    else
    {
      return nullptr;
    }
  }
  else
  {
    v14 = C_BaseAnimating::BecomeRagdollOnClient(this, a2, a3);
    v15 = v14;
    if ( v14 != nullptr && v14 != (C_ClientRagdoll *)this )
    {
      v16 = v14->GetRefEHandle(this: v14)->m_Index;
      v17 = g_HostageRagdolls.m_Size;
      v18 = g_HostageRagdolls.m_Size;
      if ( g_HostageRagdolls.m_Size + 1 > g_HostageRagdolls.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&g_HostageRagdolls,
          num: g_HostageRagdolls.m_Size - g_HostageRagdolls.m_Memory.m_nAllocationCount + 1);
        v17 = g_HostageRagdolls.m_Size;
      }
      v19 = g_HostageRagdolls.m_Memory.m_pMemory;
      g_HostageRagdolls.m_Size = v17 + 1;
      v20 = v17 - v18;
      g_HostageRagdolls.m_pElements = g_HostageRagdolls.m_Memory.m_pMemory;
      if ( v20 > 0 )
      {
        _V_memmove(
          dest: (void *)&g_HostageRagdolls.m_Memory.m_pMemory[v18 + 1],
          src: &g_HostageRagdolls.m_Memory.m_pMemory[v18],
          count: 4 * v20);
        v19 = g_HostageRagdolls.m_Memory.m_pMemory;
      }
      v21 = &v19[v18];
      if ( v21 != nullptr )
        v21->m_Index = v16;
    }
    return (C_LowViolenceHostageDeathModel *)v15;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10421DE0
// Name: DT_CHostage::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_CHostage::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_CHostage::g_RecvTable);
  return atexit(func: DT_CHostage::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10421E00
// Name: DT_CHostage::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_CHostage::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_CHostage::ignored>();
  DT_CHostage::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10435170
// Name: DT_CHostage::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_CHostage::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_CHostage::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x101B7F30
// Name: _C_CHostage_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_CHostage_CreateObject(int entnum, int serialNum)
{
  C_CHostage *v2; // eax
  C_CHostage *v3; // eax
  C_CHostage *v4; // esi

  v2 = (C_CHostage *)C_BaseEntity::operator new(stAllocateBlock: 0x12B8u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_CHostage::C_CHostage(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10421E10
// Name: _dynamic_initializer_for__cl_left_hand_ik__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_left_hand_ik__()
{
  ConVar::ConVar(
    this: &cl_left_hand_ik,
    pName: "cl_left_hand_ik",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Attach player's left hand to rifle with IK.");
  return atexit(func: dynamic_atexit_destructor_for__cl_left_hand_ik__);
}

//------------------------------------------------------------------------------
// Address: 0x10421E40
// Name: _dynamic_initializer_for__cl_ragdoll_physics_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_ragdoll_physics_enable__()
{
  ConVar::ConVar(
    this: &cl_ragdoll_physics_enable,
    pName: "cl_ragdoll_physics_enable",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Enable/disable ragdoll physics.");
  return atexit(func: dynamic_atexit_destructor_for__cl_ragdoll_physics_enable__);
}

//------------------------------------------------------------------------------
// Address: 0x10421E70
// Name: _dynamic_initializer_for__cl_minmodels__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_minmodels__()
{
  ConVar::ConVar(
    this: &cl_minmodels,
    pName: "cl_minmodels",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Uses one player model for each team.  Set this value to -1 to allow unapproved / in progress player models to be used.");
  return atexit(func: dynamic_atexit_destructor_for__cl_minmodels__);
}

//------------------------------------------------------------------------------
// Address: 0x10421EA0
// Name: _dynamic_initializer_for__cl_min_ct__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_min_ct__()
{
  ConVar::ConVar(
    this: &cl_min_ct,
    pName: "cl_min_ct",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Controls which CT model is used when cl_minmodels is set to 1.");
  return atexit(func: dynamic_atexit_destructor_for__cl_min_ct__);
}

//------------------------------------------------------------------------------
// Address: 0x10421ED0
// Name: _dynamic_initializer_for__cl_min_t__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_min_t__()
{
  ConVar::ConVar(
    this: &cl_min_t,
    pName: "cl_min_t",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Controls which Terrorist model is used when cl_minmodels is set to 1.");
  return atexit(func: dynamic_atexit_destructor_for__cl_min_t__);
}

//------------------------------------------------------------------------------
// Address: 0x10421F00
// Name: _dynamic_initializer_for__cl_enable_roundstart_autobuy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_enable_roundstart_autobuy__()
{
  ConVar::ConVar(
    this: &cl_enable_roundstart_autobuy,
    pName: "cl_enable_roundstart_autobuy",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Enable/disable autobuy at round start.");
  return atexit(func: dynamic_atexit_destructor_for__cl_enable_roundstart_autobuy__);
}

//------------------------------------------------------------------------------
// Address: 0x10421F30
// Name: _dynamic_initializer_for__cl_enable_weapon_voiceover__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_enable_weapon_voiceover__()
{
  ConVar::ConVar(
    this: &cl_enable_weapon_voiceover,
    pName: "cl_enable_weapon_voiceover",
    pDefaultValue: "1",
    flags: 16810112,
    pHelpString: "Enable/Disable weapon name voice over.");
  return atexit(func: dynamic_atexit_destructor_for__cl_enable_weapon_voiceover__);
}

//------------------------------------------------------------------------------
// Address: 0x10421F60
// Name: _dynamic_initializer_for__cl_freeze_cam_penetration_tolerance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_freeze_cam_penetration_tolerance__()
{
  ConVar::ConVar(
    this: &cl_freeze_cam_penetration_tolerance,
    pName: "cl_freeze_cam_penetration_tolerance",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "If the freeze cam gets closer to target than this distance, we snap to death cam instead (0 = use character bounds i"
    "nstead, -1 = disable this safety check");
  return atexit(func: dynamic_atexit_destructor_for__cl_freeze_cam_penetration_tolerance__);
}

//------------------------------------------------------------------------------
// Address: 0x10421F90
// Name: _dynamic_initializer_for____g_C_TEPlayerAnimEvent__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEPlayerAnimEvent__()
{
  C_BaseTempEntity::C_BaseTempEntity(this: &_g_C_TEPlayerAnimEvent);
  _g_C_TEPlayerAnimEvent.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEPlayerAnimEvent_vtbl *)&C_TEPlayerAnimEvent::`vftable'{for `IClientUnknown'};
  _g_C_TEPlayerAnimEvent.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEPlayerAnimEvent::`vftable'{for `IClientNetworkable'};
  _g_C_TEPlayerAnimEvent.m_hPlayer.m_Value.m_Index = -1;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEPlayerAnimEvent__);
}

//------------------------------------------------------------------------------
// Address: 0x10421FD0
// Name: _dynamic_initializer_for____g_C_TEPlayerAnimEventClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEPlayerAnimEventClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEPlayerAnimEventClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEPlayerAnimEventClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10435180
// Name: _dynamic_atexit_destructor_for__g_Hostages__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Hostages__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_Hostages);
}

//------------------------------------------------------------------------------
// Address: 0x10435190
// Name: _dynamic_atexit_destructor_for__g_HostageRagdolls__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_HostageRagdolls__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_HostageRagdolls);
}

//------------------------------------------------------------------------------
// Address: 0x104351A0
// Name: _dynamic_atexit_destructor_for__cl_left_hand_ik__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_left_hand_ik__()
{
  ConVar::~ConVar(this: &cl_left_hand_ik);
}

//------------------------------------------------------------------------------
// Address: 0x104351B0
// Name: _dynamic_atexit_destructor_for__cl_ragdoll_physics_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_ragdoll_physics_enable__()
{
  ConVar::~ConVar(this: &cl_ragdoll_physics_enable);
}

//------------------------------------------------------------------------------
// Address: 0x104351C0
// Name: _dynamic_atexit_destructor_for__cl_minmodels__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_minmodels__()
{
  ConVar::~ConVar(this: &cl_minmodels);
}

//------------------------------------------------------------------------------
// Address: 0x104351D0
// Name: _dynamic_atexit_destructor_for__cl_min_ct__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_min_ct__()
{
  ConVar::~ConVar(this: &cl_min_ct);
}

//------------------------------------------------------------------------------
// Address: 0x104351E0
// Name: _dynamic_atexit_destructor_for__cl_min_t__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_min_t__()
{
  ConVar::~ConVar(this: &cl_min_t);
}

//------------------------------------------------------------------------------
// Address: 0x104351F0
// Name: _dynamic_atexit_destructor_for__cl_enable_roundstart_autobuy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_enable_roundstart_autobuy__()
{
  ConVar::~ConVar(this: &cl_enable_roundstart_autobuy);
}

//------------------------------------------------------------------------------
// Address: 0x10435200
// Name: _dynamic_atexit_destructor_for__cl_enable_weapon_voiceover__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_enable_weapon_voiceover__()
{
  ConVar::~ConVar(this: &cl_enable_weapon_voiceover);
}

//------------------------------------------------------------------------------
// Address: 0x10435210
// Name: _dynamic_atexit_destructor_for__cl_freeze_cam_penetration_tolerance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_freeze_cam_penetration_tolerance__()
{
  ConVar::~ConVar(this: &cl_freeze_cam_penetration_tolerance);
}
