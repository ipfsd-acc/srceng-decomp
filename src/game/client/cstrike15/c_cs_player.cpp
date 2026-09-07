// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/c_cs_player.cpp
// Functions: 132
// ============================================================

#include "game\client\cstrike15\c_cs_player.h"

//------------------------------------------------------------------------------
// Address: 0x101B8190
// Name: public: virtual class ClientClass __near * C_TEPlayerAnimEvent::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEPlayerAnimEvent::GetClientClass(C_TEPlayerAnimEvent *this)
{
  return &__g_C_TEPlayerAnimEventClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x101B8240
// Name: public: virtual struct datamap_t __near * C_CSPlayer::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_CSPlayer::GetPredDescMap(C_CSPlayer *this)
{
  return &C_CSPlayer::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x101B8250
// Name: public: virtual class ClientClass __near * C_CSRagdoll::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_CSRagdoll::GetClientClass(C_CSRagdoll *this)
{
  return &__g_C_CSRagdollClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x101B83E0
// Name: public: virtual void C_CSRagdoll::ValidateModelIndex(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall C_CSRagdoll::ValidateModelIndex(C_CSRagdoll *this)
{
  C_BaseEntity::ValidateModelIndex(this);
}

//------------------------------------------------------------------------------
// Address: 0x101B8470
// Name: public: virtual class ClientClass __near * C_CSPlayer::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_CSPlayer::GetClientClass(C_CSPlayer *this)
{
  return &__g_C_CSPlayerClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x101B8480
// Name: public: bool C_CSPlayer::HasDefuser(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CSPlayer::HasDefuser(C_CSPlayer *this)
{
  return this->m_bHasDefuser;
}

//------------------------------------------------------------------------------
// Address: 0x101B8490
// Name: public: bool C_CSPlayer::IsVIP(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CSPlayer::IsVIP(C_CSPlayer *this)
{
  IGameResources *v2; // eax
  C_CS_PlayerResource *v3; // esi
  int v5; // eax

  v2 = GameResources();
  if ( v2 == nullptr )
    return false;
  v3 = (C_CS_PlayerResource *)&v2[-608];
  if ( v2 == (IGameResources *)2432 )
    return false;
  v5 = this->entindex(this: &this->IClientNetworkable);
  return C_CS_PlayerResource::IsVIP(this: v3, iIndex: v5);
}

//------------------------------------------------------------------------------
// Address: 0x101B84D0
// Name: public: virtual float C_CSPlayer::GetMinFOV(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_CSPlayer::GetMinFOV(C_CSPlayer *this)
{
  return 10.0;
}

//------------------------------------------------------------------------------
// Address: 0x101B84E0
// Name: public: int C_CSPlayer::GetAccount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_CSPlayer::GetAccount(C_CSPlayer *this)
{
  return this->m_iAccount;
}

//------------------------------------------------------------------------------
// Address: 0x101B84F0
// Name: public: int C_CSPlayer::PlayerClass(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_CSPlayer::PlayerClass(C_CSPlayer *this)
{
  return this->m_iClass;
}

//------------------------------------------------------------------------------
// Address: 0x101B8500
// Name: public: int C_CSPlayer::ArmorValue(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_CSPlayer::ArmorValue(C_CSPlayer *this)
{
  return this->m_ArmorValue;
}

//------------------------------------------------------------------------------
// Address: 0x101B8510
// Name: public: bool C_CSPlayer::HasHelmet(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CSPlayer::HasHelmet(C_CSPlayer *this)
{
  return this->m_bHasHelmet;
}

//------------------------------------------------------------------------------
// Address: 0x101B8520
// Name: public: virtual class QAngle const __near & C_CSPlayer::GetRenderAngles(void)
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall C_CSPlayer::GetRenderAngles(C_CSPlayer *this)
{
  char *v3; // ecx

  if ( C_BaseAnimating::IsRagdoll(this: (C_CSPlayer *)((char *)this - 4)) )
    return &vec3_angle;
  v3 = (char *)this->m_SmokeGrenades.m_pElements
     + *(_DWORD *)(*((_DWORD *)this->m_SmokeGrenades.m_pElements + 1) + 4)
     + 4;
  return (*(const QAngle *(__thiscall **)(char *))(*(_DWORD *)v3 + 12))(a1: v3);
}

//------------------------------------------------------------------------------
// Address: 0x101B8550
// Name: public: virtual bool C_CSPlayer::GetShadowCastDirection(class Vector __near *,enum ShadowType_t)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CSPlayer::GetShadowCastDirection(C_CSPlayer *this, Vector *pDirection, ShadowType_t shadowType)
{
  if ( shadowType != SHADOWS_SIMPLE )
    return C_BaseEntity::GetShadowCastDirection(this, pDirection, shadowType);
  pDirection->x = 0.0;
  pDirection->y = 0.0;
  pDirection->z = -1.0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x101B8590
// Name: public: virtual void C_CSPlayer::VPhysicsUpdate(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSPlayer::VPhysicsUpdate(C_CSPlayer *this, IPhysicsObject *pPhysics)
{
  C_BaseAnimating::VPhysicsUpdate(this, pPhysics);
}

//------------------------------------------------------------------------------
// Address: 0x101B85A0
// Name: public: int C_CSPlayer::GetTargetedWeapon(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_CSPlayer::GetTargetedWeapon(C_CSPlayer *this)
{
  return this->m_iTargetedWeaponEntIndex;
}

//------------------------------------------------------------------------------
// Address: 0x101B85B0
// Name: public: virtual void C_CSPlayer::ValidateModelIndex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSPlayer::ValidateModelIndex(C_CSPlayer *this)
{
  C_BaseEntity::SetModelByIndex(this, nModelIndex: this->m_nModelIndex);
}

//------------------------------------------------------------------------------
// Address: 0x101B85C0
// Name: public: virtual void C_CSPlayer::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSPlayer::PostDataUpdate(C_CSPlayer *this, DataUpdateType_t updateType)
{
  const QAngle *LocalAngles; // eax

  LocalAngles = C_BaseEntity::GetLocalAngles(this: (C_CSPlayer *)((char *)this - 8));
  C_BaseEntity::SetNetworkAngles(this: (C_CSPlayer *)((char *)this - 8), ang: LocalAngles);
  C_BasePlayer::PostDataUpdate(this, updateType);
}

//------------------------------------------------------------------------------
// Address: 0x101B85F0
// Name: public: virtual bool C_CSPlayer::Interpolate(float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_CSPlayer::Interpolate(C_CSPlayer *this, float currentTime)
{
  char result; // al
  const Vector *NetworkOrigin; // eax

  result = C_BaseAnimatingOverlay::Interpolate(this, flCurrentTime: currentTime);
  if ( result != 0 )
  {
    if ( C_CSGameRules::IsFreezePeriod(this: (CBaseAchievement *)g_pGameRules) )
    {
      NetworkOrigin = C_BaseEntity::GetNetworkOrigin(this);
      C_BaseEntity::SetAbsOrigin(this, absOrigin: NetworkOrigin);
    }
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B8640
// Name: public: virtual int C_CSPlayer::GetMaxHealth(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_CSPlayer::GetMaxHealth(C_CSPlayer *this)
{
  return 100;
}

//------------------------------------------------------------------------------
// Address: 0x101B8650
// Name: class C_CSPlayer __near * GetLocalOrInEyeCSPlayer(void)
// Source: json
//------------------------------------------------------------------------------
C_CSPlayer *__cdecl GetLocalOrInEyeCSPlayer()
{
  C_BasePlayer *LocalPlayer; // esi
  C_BaseEntity *v1; // edi

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr
    && LocalPlayer->GetObserverMode(this: LocalPlayer) == 4
    && (v1 = LocalPlayer->GetObserverTarget(this: LocalPlayer)) != nullptr
    && v1->IsPlayer(this: v1) )
  {
    return ToBasePlayer(pEntity: v1);
  }
  else
  {
    return (C_CSPlayer *)LocalPlayer;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B86B0
// Name: joinsplitscreen
// Source: json
//------------------------------------------------------------------------------
void __cdecl joinsplitscreen()
{
  char splitScreenCommand[1024]; // [esp+0h] [ebp-400h] BYREF

  memset(splitScreenCommand, 0, sizeof(splitScreenCommand));
  V_snprintf(pDest: splitScreenCommand, maxLen: 0x400u, pFormat: "jointeam 3\njoinclass\n");
  engine->ClientCmd(this: engine, a2: splitScreenCommand);
}

//------------------------------------------------------------------------------
// Address: 0x101B8710
// Name: public: virtual bool C_CSPlayer::CreateMove(float,class CUserCmd __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_CSPlayer::CreateMove(C_CSPlayer *this, float flInputSampleTime, CUserCmd *pCmd)
{
  char Move; // bl
  C_BaseAnimating::AutoAllowBoneAccess boneaccess; // [esp+13h] [ebp-1h] BYREF

  C_BaseAnimating::AutoAllowBoneAccess::AutoAllowBoneAccess(
    this: &boneaccess,
    bAllowForNormalModels: true,
    bAllowForViewModels: true);
  Move = C_BasePlayer::CreateMove(this, flInputSampleTime, pCmd);
  C_BaseAnimating::AutoAllowBoneAccess::~AutoAllowBoneAccess(this: &boneaccess);
  return Move;
}

//------------------------------------------------------------------------------
// Address: 0x101B8750
// Name: public: bool C_CSPlayer::IsInHostageRescueZone(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CSPlayer::IsInHostageRescueZone(C_CSPlayer *this)
{
  return this->m_bInHostageRescueZone;
}

//------------------------------------------------------------------------------
// Address: 0x101B8760
// Name: public: class C_WeaponCSBase __near * C_CSPlayer::GetActiveCSWeapon(void)const
// Source: json
//------------------------------------------------------------------------------
C_BaseCombatWeapon *__thiscall C_CSPlayer::GetActiveCSWeapon(C_BasePlayer *this)
{
  return this->GetActiveWeapon(this);
}

//------------------------------------------------------------------------------
// Address: 0x101B8770
// Name: public: class C_WeaponCSBase __near * C_CSPlayer::GetCSWeapon(enum CSWeaponID)const
// Source: json
//------------------------------------------------------------------------------
C_WeaponCSBase *__thiscall C_CSPlayer::GetCSWeapon(C_CSPlayer *this, const CBaseHandle *id)
{
  int v3; // edi
  C_BaseCombatWeapon *v4; // esi

  v3 = 0;
  while ( 1 )
  {
    v4 = this->GetWeapon(this, a2: v3);
    if ( v4 != nullptr
      && id == v4->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].GetRefEHandle(this: v4) )
    {
      break;
    }
    if ( ++v3 >= 64 )
      return nullptr;
  }
  return (C_WeaponCSBase *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x101B87C0
// Name: public: virtual bool C_CSPlayer::Weapon_CanSwitchTo(class C_BaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CSPlayer::Weapon_CanSwitchTo(C_CSPlayer *this, C_BaseCombatWeapon *pWeapon)
{
  bool result; // al
  C_BaseCombatWeapon *v4; // eax

  result = false;
  if ( pWeapon->CanDeploy(this: pWeapon) )
  {
    if ( this->GetActiveWeapon(this) == nullptr )
      return true;
    v4 = this->GetActiveWeapon(this);
    if ( v4->CanHolster(this: v4) )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B8820
// Name: public: virtual class QAngle const __near & C_CSPlayer::EyeAngles(void)
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall C_CSPlayer::EyeAngles(C_CSPlayer *this)
{
  if ( !C_BasePlayer::IsLocalPlayer(pEntity: this) || g_nKillCamMode != 0 )
    return &this->m_angEyeAngles;
  else
    return C_BasePlayer::EyeAngles(this);
}

//------------------------------------------------------------------------------
// Address: 0x101B8850
// Name: public: virtual bool C_CSPlayer::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CSPlayer::ShouldDraw(C_CSPlayer *this)
{
  C_BaseAnimating *v2; // esi

  v2 = (C_CSPlayer *)((char *)this - 4);
  if ( (*(unsigned __int8 (__thiscall **)(char *))(*((_DWORD *)this - 1) + 576))(a1: (char *)this - 4) == 0
    || v2->GetTeamNumber(this: v2) == 1 )
  {
    return false;
  }
  if ( C_BasePlayer::IsLocalPlayer(pEntity: v2) && C_BaseAnimating::IsRagdoll(this: v2) )
    return true;
  return C_BasePlayer::ShouldDraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x101B88B0
// Name: void GetCorrectionMatrices(class matrix3x4a_t const __near &,class matrix3x4a_t const __near &,class matrix3x4a_t const __near &,class matrix3x4a_t __near &,class matrix3x4a_t __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall GetCorrectionMatrices(
        int a1@<ebp>,
        const matrix3x4a_t *mShoulder,
        const matrix3x4a_t *mElbow,
        const matrix3x4a_t *mHand,
        matrix3x4a_t *mShoulderCorrection,
        matrix3x4a_t *mElbowCorrection)
{
  _BYTE v6[12]; // [esp-Ch] [ebp-15Ch] BYREF
  matrix3x4_t mInvAlignedElbow; // [esp+0h] [ebp-150h] BYREF
  _BYTE mInvAlignedShoulder_36[204]; // [esp+54h] [ebp-FCh] OVERLAPPED BYREF
  Vector vHand; // [esp+120h] [ebp-30h]
  Vector vShoulder; // [esp+12Ch] [ebp-24h]
  Vector vElbow; // [esp+138h] [ebp-18h] BYREF
  int v12; // [esp+144h] [ebp-Ch]
  void *v13; // [esp+148h] [ebp-8h]
  void *retaddr; // [esp+150h] [ebp+0h]

  v12 = a1;
  v13 = retaddr;
  vHand.x = mShoulder->m_flMatVal[0][3];
  vHand.y = mShoulder->m_flMatVal[1][3];
  vHand.z = mShoulder->m_flMatVal[2][3];
  vShoulder.x = mElbow->m_flMatVal[0][3];
  vShoulder.y = mElbow->m_flMatVal[1][3];
  vShoulder.z = mElbow->m_flMatVal[2][3];
  *(float *)&mInvAlignedShoulder_36[192] = mHand->m_flMatVal[0][3];
  *(float *)&mInvAlignedShoulder_36[196] = mHand->m_flMatVal[1][3];
  *(float *)&mInvAlignedShoulder_36[200] = mHand->m_flMatVal[2][3];
  *(matrix3x4a_t *)&mInvAlignedShoulder_36[144] = *mShoulder;
  *(matrix3x4a_t *)&mInvAlignedShoulder_36[96] = *mElbow;
  memset((void *)&vElbow, 0, sizeof(vElbow));
  MatrixSetColumn(in: &vElbow, column: 3, out: (matrix3x4_t *)&mInvAlignedShoulder_36[144]);
  memset((void *)&vElbow, 0, sizeof(vElbow));
  MatrixSetColumn(in: &vElbow, column: 3, out: (matrix3x4_t *)&mInvAlignedShoulder_36[96]);
  *(__m128i *)mInvAlignedShoulder_36 = _mm_load_si128((const __m128i *)&mInvAlignedShoulder_36[144]);
  *(__m128i *)&mInvAlignedShoulder_36[16] = _mm_load_si128((const __m128i *)&mInvAlignedShoulder_36[160]);
  *(__m128i *)&mInvAlignedShoulder_36[32] = _mm_load_si128((const __m128i *)&mInvAlignedShoulder_36[176]);
  *(__m128i *)&mInvAlignedShoulder_36[48] = _mm_load_si128((const __m128i *)&mInvAlignedShoulder_36[96]);
  *(__m128i *)&mInvAlignedShoulder_36[64] = _mm_load_si128((const __m128i *)&mInvAlignedShoulder_36[112]);
  *(__m128i *)&mInvAlignedShoulder_36[80] = _mm_load_si128((const __m128i *)&mInvAlignedShoulder_36[128]);
  vElbow.x = vShoulder.x - vHand.x;
  vElbow.y = vShoulder.y - vHand.y;
  vElbow.z = vShoulder.z - vHand.z;
  Studio_AlignIKMatrix(mMat: (matrix3x4a_t *)mInvAlignedShoulder_36, vAlignTo: &vElbow);
  vElbow.x = *(float *)&mInvAlignedShoulder_36[192] - vShoulder.x;
  vElbow.y = *(float *)&mInvAlignedShoulder_36[196] - vShoulder.y;
  vElbow.z = *(float *)&mInvAlignedShoulder_36[200] - vShoulder.z;
  Studio_AlignIKMatrix(mMat: (matrix3x4a_t *)&mInvAlignedShoulder_36[48], vAlignTo: &vElbow);
  MatrixInvert(in: (const matrix3x4_t *)mInvAlignedShoulder_36, out: (matrix3x4_t *)&mInvAlignedElbow.m_flMatVal[2][1]);
  MatrixInvert(in: (const matrix3x4_t *)&mInvAlignedShoulder_36[48], out: (matrix3x4_t *)v6);
  ConcatTransforms(
    in1: (matrix3x4_t *)&mInvAlignedElbow.m_flMatVal[2][1],
    in2: (const matrix3x4_t *)&mInvAlignedShoulder_36[144],
    out: mShoulderCorrection);
  ConcatTransforms(
    in1: (const matrix3x4_t *)v6,
    in2: (const matrix3x4_t *)&mInvAlignedShoulder_36[96],
    out: mElbowCorrection);
}

//------------------------------------------------------------------------------
// Address: 0x101B8B20
// Name: public: void C_CSPlayer::DoAnimationEvent(enum PlayerAnimEvent_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSPlayer::DoAnimationEvent(C_CSPlayer *this, PlayerAnimEvent_t event, int nData)
{
  if ( event != PLAYERANIMEVENT_THROW_GRENADE )
    this->m_PlayerAnimState->DoAnimationEvent(this: this->m_PlayerAnimState, a2: event, a3: nData);
}

//------------------------------------------------------------------------------
// Address: 0x101B8B50
// Name: public: bool C_CSPlayer::HasC4(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CSPlayer::HasC4(C_CSPlayer *this)
{
  IGameResources *v3; // eax
  C_CS_PlayerResource *v4; // esi
  int v5; // eax

  if ( C_BasePlayer::IsLocalPlayer(pEntity: this) )
    return this->Weapon_OwnsThisType(this, a2: "weapon_c4", a3: 0) != nullptr;
  v3 = GameResources();
  if ( v3 != nullptr )
    v4 = (C_CS_PlayerResource *)&v3[-608];
  else
    v4 = nullptr;
  v5 = this->entindex(this: &this->IClientNetworkable);
  return C_CS_PlayerResource::HasC4(this: v4, iIndex: v5);
}

//------------------------------------------------------------------------------
// Address: 0x101B8BB0
// Name: public: virtual void C_CSPlayer::CalcObserverView(class Vector __near &,class QAngle __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSPlayer::CalcObserverView(C_CSPlayer *this, Vector *eyeOrigin, QAngle *eyeAngles, float *fov)
{
  C_BasePlayer::CalcObserverView(this, eyeOrigin, eyeAngles, fov);
}

//------------------------------------------------------------------------------
// Address: 0x101B8BC0
// Name: public: bool C_CSPlayer::IsPlayerDominated(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CSPlayer::IsPlayerDominated(C_CSPlayer *this, int iPlayerIndex)
{
  return this->m_bPlayerDominated.m_Value[iPlayerIndex];
}

//------------------------------------------------------------------------------
// Address: 0x101B8BE0
// Name: public: bool C_CSPlayer::IsPlayerDominatingMe(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CSPlayer::IsPlayerDominatingMe(C_CSPlayer *this, int iPlayerIndex)
{
  return this->m_bPlayerDominatingMe.m_Value[iPlayerIndex];
}

//------------------------------------------------------------------------------
// Address: 0x101B8C00
// Name: float Interpolators::SmoothStepEnd(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl Interpolators::SmoothStepEnd(float t)
{
  return 2.0
       * ((t + 1.0) * 0.5 * 3.0 * ((t + 1.0) * 0.5) - (t + 1.0) * 0.5 * ((t + 1.0) * 0.5 * 2.0 * ((t + 1.0) * 0.5)) - 0.5);
}

//------------------------------------------------------------------------------
// Address: 0x101B8C40
// Name: public: virtual void C_CSRagdoll::GetRagdollInitBoneArrays(class matrix3x4a_t __near *,class matrix3x4a_t __near *,class matrix3x4a_t __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSRagdoll::GetRagdollInitBoneArrays(
        C_CSRagdoll *this,
        matrix3x4a_t *pDeltaBones0,
        matrix3x4a_t *pDeltaBones1,
        matrix3x4a_t *pCurrentBones,
        float boneDt)
{
  C_BaseAnimating::ForceSetupBonesAtTime(
    this,
    a2: (int)this,
    pBonesOut: pDeltaBones0,
    flTime: *(float *)(gpGlobals.m_Index + 12) - boneDt);
  GetRagdollCurSequenceWithDeathPose(
    entity: this,
    curBones: pDeltaBones1,
    flTime: *(float *)(gpGlobals.m_Index + 12),
    activity: this->m_iDeathPose.m_Value,
    frame: this->m_iDeathFrame.m_Value);
  ((void (__thiscall *)(IClientRenderable *, matrix3x4a_t *, int, int, _DWORD))this->SetupBones)(
    a1: &this->IClientRenderable,
    a2: pCurrentBones,
    a3: 256,
    a4: 524032,
    a5: *(_DWORD *)(gpGlobals.m_Index + 12));
}

//------------------------------------------------------------------------------
// Address: 0x101B8CC0
// Name: public: void C_CSRagdoll::ApplyRandomTaserForce(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSRagdoll::ApplyRandomTaserForce(C_CSRagdoll *this)
{
  IPhysicsObject *m_pPhysicsObject; // edi
  int (__thiscall *RandomInt)(IUniformRandomStream *, int, int); // edx
  int v4; // eax
  int v5; // eax
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // eax
  float m_fValue; // xmm0_4
  QAngle boneAngle; // [esp+20h] [ebp-34h] BYREF
  Vector bonePos; // [esp+2Ch] [ebp-28h] BYREF
  Vector dir; // [esp+38h] [ebp-1Ch] BYREF
  char *boneNameList[2]; // [esp+44h] [ebp-10h]
  float v12; // [esp+4Ch] [ebp-8h]
  float v13; // [esp+50h] [ebp-4h]

  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
  {
    RandomInt = random->RandomInt;
    boneNameList[0] = "ValveBiped.Bip01_r_hand";
    boneNameList[1] = "ValveBiped.Bip01_l_hand";
    v4 = RandomInt(this: random, a2: 0, a3: 1);
    v5 = C_BaseAnimating::LookupBone(this, szName: boneNameList[v4]);
    if ( v5 >= 0 )
    {
      C_BaseAnimating::GetBonePosition(this, iBone: v5, origin: &bonePos, angles: &boneAngle);
      bonePos.y = cl_random_taser_bone_y.m_pParent->m_Value.m_fValue + bonePos.y;
      RandomFloat = random->RandomFloat;
      boneNameList[1] = (char *)LODWORD(cl_random_taser_force_y.m_pParent->m_Value.m_fValue);
      v13 = ((double (__thiscall *)(IUniformRandomStream *, int, int))RandomFloat)(
              a1: random,
              a2: -1082130432,
              a3: 1065353216);
      v12 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
              a1: random,
              a2: -1082130432,
              a3: 1065353216);
      dir.x = v13;
      dir.y = v12;
      *(char **)&dir.z = boneNameList[1];
      VectorNormalize(vec: &dir);
      m_fValue = cl_random_taser_power.m_pParent->m_Value.m_fValue;
      dir.x = dir.x * m_fValue;
      dir.y = dir.y * m_fValue;
      dir.z = dir.z * m_fValue;
      m_pPhysicsObject->ApplyForceOffset(this: m_pPhysicsObject, a2: &dir, a3: &bonePos);
      CRagdoll::ResetRagdollSleepAfterTime(this: this->m_pRagdoll);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B8E30
// Name: public: virtual void C_CSRagdoll::ImpactTrace(class CGameTrace __near *,int,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSRagdoll::ImpactTrace(
        C_CSRagdoll *this,
        CGameTrace *pTrace,
        int iDamageType,
        char *pCustomImpactName)
{
  IPhysicsObject *m_pPhysicsObject; // esi
  float x; // xmm4_4
  float y; // xmm5_4
  float z; // xmm6_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float fraction; // xmm1_4
  Vector hitpos; // [esp+18h] [ebp-18h] BYREF
  Vector dir; // [esp+24h] [ebp-Ch] BYREF

  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
  {
    x = pTrace->startpos.x;
    y = pTrace->startpos.y;
    z = pTrace->startpos.z;
    v9 = pTrace->endpos.x - pTrace->startpos.x;
    v10 = pTrace->endpos.y - y;
    v11 = pTrace->endpos.z - z;
    dir.x = v9;
    dir.y = v10;
    dir.z = v11;
    if ( iDamageType == 64 )
    {
      dir.x = v9 * 4000.0;
      dir.y = v10 * 4000.0;
      dir.z = v11 * 4000.0;
      m_pPhysicsObject->ApplyForceCenter(this: m_pPhysicsObject, a2: &dir);
      CRagdoll::ResetRagdollSleepAfterTime(this: this->m_pRagdoll);
    }
    else
    {
      fraction = pTrace->fraction;
      hitpos.x = (float)(v9 * fraction) + x;
      hitpos.y = (float)(fraction * v10) + y;
      hitpos.z = (float)(fraction * v11) + z;
      VectorNormalize(vec: &dir);
      dir.x = dir.x * 4000.0;
      dir.y = dir.y * 4000.0;
      dir.z = dir.z * 4000.0;
      if ( (iDamageType & 0x100) == 0 )
      {
        m_pPhysicsObject->ApplyForceOffset(this: m_pPhysicsObject, a2: &dir, a3: &hitpos);
        FX_CS_BloodSpray(origin: &hitpos, normal: &dir, flDamage: 10.0);
      }
      CRagdoll::ResetRagdollSleepAfterTime(this: this->m_pRagdoll);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B8F90
// Name: void RecvProxy_HasDefuser(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_HasDefuser(const CRecvProxyData *pData, C_BaseEntity *pStruct)
{
  bool v2; // bl
  CHud *Hud; // eax
  SFItemHistory *Element; // eax

  if ( pStruct != nullptr )
  {
    v2 = false;
    if ( pData->m_Value.m_Int != 0 )
    {
      v2 = LOBYTE(pStruct[2].m_pIntermediateData_FirstPredicted[90]) == 0;
      LOBYTE(pStruct[2].m_pIntermediateData_FirstPredicted[90]) = 1;
    }
    else
    {
      LOBYTE(pStruct[2].m_pIntermediateData_FirstPredicted[90]) = 0;
    }
    if ( C_BasePlayer::IsLocalPlayer(pEntity: pStruct) && v2 )
    {
      Hud = GetHud(nSlot: -1);
      Element = (SFItemHistory *)CHud::FindElement(this: Hud, pName: "SFItemHistory");
      if ( Element != nullptr )
        SFItemHistory::AddToHistory(this: Element, name: "defuser", displayName: "#Cstrike_BMDefuser");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B9190
// Name: public: bool C_CSPlayer::HasNightVision(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CSPlayer::HasNightVision(C_CSPlayer *this)
{
  return this->m_bHasNightVision.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x101B91A0
// Name: public: enum CSPlayerState C_CSPlayer::State_Get(void)const
// Source: json
//------------------------------------------------------------------------------
CSPlayerState __thiscall C_CSPlayer::State_Get(C_CSPlayer *this)
{
  return this->m_iPlayerState.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x101B91B0
// Name: public: bool C_CSPlayer::IsInBuyZone(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CSPlayer::IsInBuyZone(C_CSPlayer *this)
{
  return this->m_bInBuyZone.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x101B91C0
// Name: public: virtual void C_CSPlayer::GetShadowRenderBounds(class Vector __near &,class Vector __near &,enum ShadowType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSPlayer::GetShadowRenderBounds(
        C_CSPlayer *this,
        Vector *mins,
        Vector *maxs,
        ShadowType_t shadowType)
{
  const char **p_m_ModelName; // esi
  float *v5; // eax
  int (__thiscall *v6)(const char **); // edx
  float v7; // xmm0_4
  float v8; // xmm0_4

  if ( shadowType == SHADOWS_SIMPLE )
  {
    p_m_ModelName = &this->m_ModelName;
    v5 = (float *)(*((int (__thiscall **)(const char **))this->m_ModelName + 1))(a1: &this->m_ModelName);
    mins->x = *v5;
    mins->y = v5[1];
    v6 = *((int (__thiscall **)(const char **))*p_m_ModelName + 2);
    mins->z = v5[2];
    *maxs = *(Vector *)v6(a1: p_m_ModelName);
  }
  else
  {
    ((void (__thiscall *)(C_CSPlayer *, Vector *, Vector *))this->GetPredDescMap)(a1: this, a2: mins, a3: maxs);
    v7 = g_flFattenAmt;
    mins->z = mins->z;
    mins->x = mins->x - v7;
    mins->y = mins->y - v7;
    v8 = g_flFattenAmt;
    maxs->z = maxs->z;
    maxs->x = maxs->x + v8;
    maxs->y = maxs->y + v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B9280
// Name: public: virtual void C_CSPlayer::GetRenderBounds(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSPlayer::GetRenderBounds(C_CSPlayer *this, Vector *theMins, Vector *theMaxs)
{
  C_BaseAnimating::GetRenderBounds(this, theMins, theMaxs);
  if ( (this->m_iHealth & 2) != 0 )
    theMaxs->z = theMaxs->z - 18.5;
}

//------------------------------------------------------------------------------
// Address: 0x101B92C0
// Name: public: virtual void C_CSPlayer::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSPlayer::OnDataChanged(C_CSPlayer *this, DataUpdateType_t type)
{
  C_BasePlayer::OnDataChanged(this, updateType: type);
  if ( type == DATA_UPDATE_CREATED )
  {
    (*(void (__thiscall **)(char *, int))(*((_DWORD *)this - 2) + 456))(a1: (char *)this - 8, a2: -996040704);
    if ( C_BasePlayer::IsLocalPlayer(pEntity: (C_CSPlayer *)((char *)this - 8))
      && g_pGameRules != nullptr
      && HIBYTE(g_pGameRules[4].m_pNext) != 0 )
    {
      g_pGameRules[87].m_pNext = nullptr;
      g_pGameRules[87].__vftable = nullptr;
      C_CSGameRules::GetBlackMarketPriceList(this: (C_CSGameRules *)g_pGameRules);
      C_CSGameRules::SetBlackMarketPrices(this: (C_CSGameRules *)g_pGameRules, bSetDefaults: false);
    }
  }
  C_BaseEntity::UpdateVisibility(this: (C_CSPlayer *)((char *)this - 8));
}

//------------------------------------------------------------------------------
// Address: 0x101B9350
// Name: public: virtual void C_CSPlayer::ProcessMuzzleFlashEvent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSPlayer::ProcessMuzzleFlashEvent(C_CSPlayer *this)
{
  C_BaseCombatWeapon *v2; // esi
  C_BasePlayer *LocalPlayer; // edi
  int v4; // edi
  const char *v5; // eax
  const char *v6; // ebx
  int v7; // ebx
  const char *v8; // eax
  const char *v9; // edi
  CPVSFilter filter; // [esp+3Ch] [ebp-30h] BYREF
  Vector origin; // [esp+5Ch] [ebp-10h] BYREF
  int splitScreenRenderFlags; // [esp+68h] [ebp-4h]

  v2 = this->GetActiveWeapon(this);
  if ( v2 != nullptr )
  {
    splitScreenRenderFlags = 0;
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    if ( LocalPlayer == nullptr
      || LocalPlayer->GetObserverMode(this: LocalPlayer) != 4
      || LocalPlayer->GetObserverTarget(this: LocalPlayer) != this )
    {
      splitScreenRenderFlags = 1;
    }
    v4 = (int)v2->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].GetAbsOrigin(this: v2);
    v5 = (const char *)v2->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].GetDataDescMap(this: v2);
    v6 = v5;
    if ( v5 != nullptr && (int)_V_strlen(str: v5) > 0 && v4 >= 0 )
    {
      v2->GetAttachment(this: v2, a2: v4, a3: &origin);
      DispatchParticleEffect(
        pszParticleName: v6,
        iAttachType: PATTACH_POINT_FOLLOW,
        pEntity: v2,
        iAttachmentPoint: v4,
        bResetAllParticlesOnEntity: false,
        nSplitScreenPlayerSlot: splitScreenRenderFlags,
        filter: nullptr,
        bAllowDormantSpawn: false);
      C_RecipientFilter::C_RecipientFilter(this: &filter);
      filter.__vftable = (CPVSFilter_vtbl *)&CPVSFilter::`vftable';
      C_RecipientFilter::AddRecipientsByPVS(this: &filter, &origin);
      TE_DynamicLight(
        &filter,
        delay: 0.0,
        org: &origin,
        r: 0xFFu,
        g: 0xC0u,
        b: 0x40u,
        exponent: 5,
        radius: 70.0,
        time: 0.050000001,
        decay: 768.0,
        nLightIndex: 0x10000000);
      C_RecipientFilter::~C_RecipientFilter(this: &filter);
    }
    v7 = (int)v2->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].GetMouth(this: v2);
    v8 = (const char *)v2->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].YouForgotToImplementOrDeclareClientClass(this: v2);
    v9 = v8;
    if ( v8 != nullptr && (int)_V_strlen(str: v8) > 0 && v7 >= 0 )
      DispatchParticleEffect(
        pszParticleName: v9,
        iAttachType: PATTACH_POINT_FOLLOW,
        pEntity: v2,
        iAttachmentPoint: v7,
        bResetAllParticlesOnEntity: false,
        nSplitScreenPlayerSlot: splitScreenRenderFlags,
        filter: nullptr,
        bAllowDormantSpawn: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B94E0
// Name: bool FindWeaponAttachmentBone(class C_BaseCombatWeapon __near *,int __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl FindWeaponAttachmentBone(C_BaseCombatWeapon *pWeapon, int *iWeaponBone)
{
  CStudioHdr *m_pStudioHdr; // edi
  const studiohdr_t *i; // ecx
  const char *v5; // eax

  if ( pWeapon == nullptr )
    return false;
  if ( pWeapon->m_pStudioHdr == nullptr && pWeapon->GetModel(this: &pWeapon->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this: pWeapon);
  m_pStudioHdr = pWeapon->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    return false;
  *iWeaponBone = 0;
  for ( i = m_pStudioHdr->m_pStudioHdr; *iWeaponBone < m_pStudioHdr->m_pStudioHdr->numbones; i = m_pStudioHdr->m_pStudioHdr )
  {
    v5 = (char *)i + 216 * *iWeaponBone + i->boneindex;
    if ( _V_stricmp(s1: &v5[*(_DWORD *)v5], s2: "L_Hand_Attach") == 0 )
      break;
    ++*iWeaponBone;
  }
  return *iWeaponBone != m_pStudioHdr->m_pStudioHdr->numbones;
}

//------------------------------------------------------------------------------
// Address: 0x101B9590
// Name: bool FindMyAttachmentBone(class C_BaseAnimating __near *,int __near &,class CStudioHdr __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl FindMyAttachmentBone(C_BaseAnimating *pModel, int *iBone, CStudioHdr *pHdr)
{
  const studiohdr_t *i; // ecx
  const char *v5; // eax

  if ( pHdr == nullptr )
    return false;
  *iBone = 0;
  for ( i = pHdr->m_pStudioHdr; *iBone < pHdr->m_pStudioHdr->numbones; i = pHdr->m_pStudioHdr )
  {
    v5 = (char *)i + 216 * *iBone + i->boneindex;
    if ( _V_stricmp(s1: &v5[*(_DWORD *)v5], s2: "Valvebiped.Bip01_L_Hand") == 0 )
      break;
    ++*iBone;
  }
  return *iBone != pHdr->m_pStudioHdr->numbones;
}

//------------------------------------------------------------------------------
// Address: 0x101B9610
// Name: void ApplyDifferenceTransformToChildren(class C_BaseAnimating __near *,struct matrix3x4_t const __near &,struct matrix3x4_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ApplyDifferenceTransformToChildren(
        C_BaseAnimating *pModel,
        const matrix3x4_t *mSource,
        const matrix3x4_t *mDest,
        int iParentBone)
{
  CStudioHdr *m_pStudioHdr; // esi
  const studiohdr_t *v5; // ecx
  int v6; // edi
  int v7; // ebx
  int v8; // eax
  matrix3x4a_t *v9; // esi
  matrix3x4_t mToDest; // [esp+4h] [ebp-94h] BYREF
  matrix3x4_t mSourceInverse; // [esp+34h] [ebp-64h] BYREF
  matrix3x4_t mNew; // [esp+64h] [ebp-34h] BYREF
  CStudioHdr *v13; // [esp+94h] [ebp-4h]

  if ( pModel->m_pStudioHdr == nullptr && pModel->GetModel(this: &pModel->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this: pModel);
  m_pStudioHdr = pModel->m_pStudioHdr;
  v13 = m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    MatrixInvert(in: mSource, out: &mSourceInverse);
    ConcatTransforms(in1: mDest, in2: &mSourceInverse, out: &mToDest);
    v5 = m_pStudioHdr->m_pStudioHdr;
    v6 = 0;
    if ( m_pStudioHdr->m_pStudioHdr->numbones > 0 )
    {
      v7 = 0;
      do
      {
        v8 = v6;
        if ( v6 != iParentBone && v6 != -1 )
        {
          while ( v8 != iParentBone )
          {
            v8 = *(int *)((char *)&v5->version + 216 * v8 + v5->boneindex);
            if ( v8 == -1 )
              goto LABEL_14;
          }
          v9 = &pModel->m_BoneAccessor.m_pBones[v7];
          ConcatTransforms(in1: &mToDest, in2: v9, out: &mNew);
          *v9 = (matrix3x4a_t)mNew;
          m_pStudioHdr = v13;
        }
LABEL_14:
        v5 = m_pStudioHdr->m_pStudioHdr;
        ++v6;
        ++v7;
      }
      while ( v6 < m_pStudioHdr->m_pStudioHdr->numbones );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B9740
// Name: public: virtual void C_CSPlayer::BuildTransformations(class CStudioHdr __near *,class Vector __near *,class Quaternion __near * const,struct matrix3x4_t const __near &,int,class CBoneBitList __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge C_CSPlayer::BuildTransformations(
        C_CSPlayer *this@<ecx>,
        C_BaseCombatWeapon *a2@<ebp>,
        CStudioHdr *pHdr,
        Vector *pos,
        Quaternion *q,
        const matrix3x4_t *cameraTransform,
        int boneMask,
        CBoneBitList *boneComputed)
{
  C_BaseCombatWeapon *v9; // eax
  const studiohdr_t *m_pStudioHdr; // eax
  int v11; // edx
  int v12; // edi
  matrix3x4a_t *m_pBones; // edx
  __int64 v14; // xmm0_8
  matrix3x4a_t *v15; // eax
  __int64 v16; // xmm0_8
  matrix3x4a_t *v17; // esi
  matrix3x4a_t *v18; // edi
  _DWORD *v19; // eax
  _BYTE v20[12]; // [esp+14h] [ebp-12Ch] BYREF
  matrix3x4a_t mElbowCorrection; // [esp+20h] [ebp-120h] BYREF
  matrix3x4a_t mShoulderCorrection; // [esp+50h] [ebp-F0h] BYREF
  _BYTE v23[148]; // [esp+80h] [ebp-C0h] OVERLAPPED BYREF
  Vector vHandTarget; // [esp+114h] [ebp-2Ch]
  int iElbow; // [esp+120h] [ebp-20h]
  C_CSPlayer *v26; // [esp+124h] [ebp-1Ch]
  matrix3x4a_t *pBones; // [esp+128h] [ebp-18h]
  int iShoulder; // [esp+12Ch] [ebp-14h] BYREF
  int v29; // [esp+130h] [ebp-10h] BYREF
  C_BaseCombatWeapon *pWeapon; // [esp+134h] [ebp-Ch] BYREF
  int iWeaponBone; // [esp+138h] [ebp-8h]
  int retaddr; // [esp+140h] [ebp+0h]

  pWeapon = a2;
  iWeaponBone = retaddr;
  v26 = this;
  C_BaseFlex::BuildTransformations(this, pStudioHdr: pHdr, pos, q, cameraTransform, boneMask, boneComputed);
  if ( (!C_BasePlayer::IsLocalPlayer(pEntity: this) || C_BasePlayer::ShouldDrawLocalPlayer(this))
    && cl_left_hand_ik.m_pParent != nullptr
    && cl_left_hand_ik.m_pParent->m_Value.m_nValue != 0 )
  {
    v9 = this->GetActiveWeapon(this);
    pBones = (matrix3x4a_t *)v9;
    if ( v9 != nullptr )
    {
      ((void (__stdcall *)(_DWORD, _DWORD, int, _DWORD))v9->SetupBones)(
        a1: 0,
        a2: 0,
        a3: 524032,
        a4: *(_DWORD *)(gpGlobals.m_Index + 12));
      iShoulder = 0;
      if ( FindWeaponAttachmentBone(pWeapon: (C_BaseCombatWeapon *)pBones, iWeaponBone: &iShoulder) )
      {
        v29 = 0;
        if ( FindMyAttachmentBone(pModel: this, iBone: &v29, pHdr) )
        {
          m_pStudioHdr = pHdr->m_pStudioHdr;
          v11 = m_pStudioHdr->boneindex
              + 216 * *(int *)((char *)&m_pStudioHdr->version + 216 * v29 + m_pStudioHdr->boneindex);
          LODWORD(vHandTarget.x) = *(int *)((char *)&m_pStudioHdr->version + 216 * v29 + m_pStudioHdr->boneindex);
          v12 = *(int *)((char *)&m_pStudioHdr->version + v11);
          m_pBones = v26->m_BoneAccessor.m_pBones;
          iElbow = v12;
          v14 = *(_QWORD *)&m_pBones[v29].m_flMatVal[0][0];
          LODWORD(vHandTarget.y) = 48 * v29;
          v15 = &m_pBones[v29];
          *(_QWORD *)&v23[40] = v14;
          v16 = *(_QWORD *)&v15->m_flMatVal[0][2];
          v17 = &m_pBones[LODWORD(vHandTarget.x)];
          v18 = &m_pBones[v12];
          LODWORD(vHandTarget.z) = m_pBones;
          *(_QWORD *)&v23[48] = v16;
          *(_QWORD *)&v23[56] = *(_QWORD *)&v15->m_flMatVal[1][0];
          *(_QWORD *)&v23[64] = *(_QWORD *)&v15->m_flMatVal[1][2];
          *(_QWORD *)&v23[72] = *(_QWORD *)&v15->m_flMatVal[2][0];
          *(_QWORD *)&v23[80] = *(_QWORD *)&v15->m_flMatVal[2][2];
          GetCorrectionMatrices(
            a1: (int)&pWeapon,
            mShoulder: v18,
            mElbow: v17,
            mHand: v15,
            mShoulderCorrection: (matrix3x4a_t *)&mElbowCorrection.m_flMatVal[2][1],
            mElbowCorrection: (matrix3x4a_t *)v20);
          v19 = (_DWORD *)(LODWORD(pBones[53].m_flMatVal[2][0]) + 48 * iShoulder);
          *(_DWORD *)&v23[136] = v19[3];
          *(_DWORD *)&v23[140] = v19[7];
          *(_DWORD *)&v23[144] = v19[11];
          Studio_SolveIK(
            a1: COERCE_FLOAT(&pWeapon),
            iThigh: iElbow,
            iKnee: SLODWORD(vHandTarget.x),
            iFoot: v29,
            targetFoot: (Vector *)&v23[136],
            pBoneToWorld: (matrix3x4a_t *)LODWORD(vHandTarget.z));
          *(_QWORD *)&v23[88] = *(_QWORD *)&v18->m_flMatVal[0][0];
          *(_QWORD *)&v23[96] = *(_QWORD *)&v18->m_flMatVal[0][2];
          *(_QWORD *)&v23[104] = *(_QWORD *)&v18->m_flMatVal[1][0];
          *(_QWORD *)&v23[112] = *(_QWORD *)&v18->m_flMatVal[1][2];
          *(_QWORD *)&v23[120] = *(_QWORD *)&v18->m_flMatVal[2][0];
          *(_QWORD *)&v23[128] = *(_QWORD *)&v18->m_flMatVal[2][2];
          *(_QWORD *)&mShoulderCorrection.m_flMatVal[2][2] = *(_QWORD *)&v17->m_flMatVal[0][0];
          qmemcpy(v23, &v17->m_flMatVal[0][2], 40);
          ConcatTransforms(
            in1: (const matrix3x4_t *)&v23[88],
            in2: (matrix3x4a_t *)&mElbowCorrection.m_flMatVal[2][1],
            out: v18);
          ConcatTransforms(
            in1: (matrix3x4a_t *)&mShoulderCorrection.m_flMatVal[2][2],
            in2: (const matrix3x4_t *)v20,
            out: v17);
          ApplyDifferenceTransformToChildren(
            pModel: v26,
            mSource: (const matrix3x4_t *)&v23[40],
            mDest: (const matrix3x4_t *)((char *)v26->m_BoneAccessor.m_pBones + LODWORD(vHandTarget.y)),
            iParentBone: v29);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B9A00
// Name: public: virtual class IRagdoll __near * C_CSPlayer::GetRepresentativeRagdoll(void)const
// Source: json
//------------------------------------------------------------------------------
IHandleEntity_vtbl *__thiscall C_CSPlayer::GetRepresentativeRagdoll(C_CSPlayer *this)
{
  unsigned int m_Index; // ecx
  int v2; // eax
  CEntInfo *v3; // edx
  unsigned int v4; // ecx
  int v5; // eax
  bool v6; // zf
  CEntInfo *v7; // eax

  m_Index = this->m_hRagdoll.m_Index;
  if ( m_Index == -1 )
    return nullptr;
  v2 = (unsigned __int16)m_Index;
  v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  v4 = HIWORD(m_Index);
  if ( v3->m_SerialNumber != v4 || v3->m_pEntity == nullptr )
    return nullptr;
  v5 = v2;
  v6 = g_pEntityList->m_EntPtrArray[v5].m_SerialNumber == v4;
  v7 = &g_pEntityList->m_EntPtrArray[v5];
  if ( v6 )
    return v7->m_pEntity[608].__vftable;
  else
    return (IHandleEntity_vtbl *)MEMORY[0x980];
}

//------------------------------------------------------------------------------
// Address: 0x101B9A60
// Name: public: virtual void C_CSPlayer::TeamChange(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSPlayer::TeamChange(C_CSPlayer *this, int iNewTeam)
{
  void (__thiscall *SetValue_2)(IConVar *, int); // edx
  ConVarRef sf_ui_tint; // [esp+8h] [ebp-8h] BYREF

  CScoreboardScaleform::SetParent((vgui::TreeView *)this, itemIndex: iNewTeam);
  if ( C_BasePlayer::IsLocalPlayer(pEntity: this) && !C_BasePlayer::IsBot(this) )
  {
    ConVarRef::ConVarRef(this: &sf_ui_tint, pName: "sf_ui_tint");
    SetValue_2 = sf_ui_tint.m_pConVar->SetValue_2;
    if ( iNewTeam == 2 )
      ((void (__stdcall *)(int))SetValue_2)(a1: 2);
    else
      ((void (__stdcall *)(int))SetValue_2)(a1: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B9AC0
// Name: public: virtual class Vector const __near & C_CSPlayer::GetRenderOrigin(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall C_CSPlayer::GetRenderOrigin(C_CSPlayer *this)
{
  unsigned int v1; // edx
  int v2; // eax
  CEntInfo *v3; // esi
  unsigned int v4; // edx
  int v5; // eax
  bool v6; // zf
  CEntInfo *v7; // eax
  IHandleEntity *m_pEntity; // eax

  v1 = *(_DWORD *)&this->m_bDetected;
  if ( v1 != -1
    && (v2 = (unsigned __int16)v1,
        v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v1],
        v4 = HIWORD(v1),
        v3->m_SerialNumber == v4)
    && v3->m_pEntity != nullptr
    && ((v5 = v2, v6 = g_pEntityList->m_EntPtrArray[v5].m_SerialNumber == v4,
                  v7 = &g_pEntityList->m_EntPtrArray[v5],
                  !v6)
      ? (m_pEntity = nullptr)
      : (m_pEntity = v7->m_pEntity),
        LOBYTE(m_pEntity[849].__vftable) != 0) )
  {
    return ((const Vector *(__thiscall *)(IHandleEntity *))m_pEntity[1].SetRefEHandle)(a1: &m_pEntity[1]);
  }
  else
  {
    return C_BaseAnimating::GetRenderOrigin(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B9B20
// Name: public: bool C_CSPlayer::HasPlayerAsFriend(class C_CSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge C_CSPlayer::HasPlayerAsFriend@<al>(C_CSPlayer *this@<ecx>, int a2@<esi>, C_CSPlayer *player)
{
  IVEngineClient_vtbl *v3; // esi
  int v4; // eax
  int v6; // eax
  player_info_s pi; // [esp+0h] [ebp-90h] BYREF

  if ( steamapicontext == nullptr
    || steamapicontext->m_pSteamFriends == nullptr
    || steamapicontext->m_pSteamUtils == nullptr
    || player == nullptr )
  {
    return false;
  }
  v3 = engine->__vftable;
  v4 = ((int (__thiscall *)(IClientNetworkable *, player_info_s *, int))player->entindex)(
         a1: &player->IClientNetworkable,
         a2: &pi,
         a3: a2);
  if ( ((unsigned __int8 (__thiscall *)(IVEngineClient *, int))v3->GetPlayerInfo)(a1: engine, a2: v4) == 0
    || pi.friendsID == 0 )
  {
    return false;
  }
  v6 = ((int (__thiscall *)(ISteamUtils *, _DWORD, _DWORD))steamapicontext->m_pSteamUtils->GetConnectedUniverse)(
         a1: steamapicontext->m_pSteamUtils,
         a2: pi.xuid,
         a3: HIDWORD(pi.xuid));
  return ((int (__thiscall *)(ISteamFriends *, unsigned int, int, int))steamapicontext->m_pSteamFriends->HasFriend)(
           a1: steamapicontext->m_pSteamFriends,
           a2: pi.friendsID,
           a3: (v6 << 24) | 0x100001,
           a4: 4);
}

//------------------------------------------------------------------------------
// Address: 0x101B9BC0
// Name: public: bool C_CSPlayer::CanUseGrenade(enum CSWeaponID)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CSPlayer::CanUseGrenade(C_CSPlayer *this, CSWeaponID nID)
{
  return nID != WEAPON_MOLOTOV || this->m_fMolotovUseTime.m_Value <= *(float *)(gpGlobals.m_Index + 12);
}

//------------------------------------------------------------------------------
// Address: 0x101B9BF0
// Name: public: void C_CSPlayer::DisplayInventory(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSPlayer::DisplayInventory(C_CSPlayer *this, bool showPistol)
{
  CHud *Hud; // eax
  int v4; // eax
  C_BaseCombatWeapon *v5; // eax
  C_WeaponCSBase *v6; // eax
  C_WeaponCSBase *v7; // esi
  CSWeaponID v8; // eax
  CSWeaponID v9; // edi
  int v10; // eax
  int AmmoCount; // eax
  int v12; // edi
  int i; // [esp+4h] [ebp-8h]
  SFItemHistory *pItemHistory; // [esp+8h] [ebp-4h]

  Hud = GetHud(nSlot: -1);
  pItemHistory = (SFItemHistory *)CHud::FindElement(this: Hud, pName: "SFItemHistory");
  if ( pItemHistory != nullptr )
  {
    v4 = 0;
    i = 0;
    do
    {
      v5 = this->GetWeapon(this, a2: v4);
      v6 = (C_WeaponCSBase *)__RTDynamicCast(
                               inptr: v5,
                               VfDelta: 0,
                               SrcType: &C_BaseCombatWeapon `RTTI Type Descriptor',
                               TargetType: &C_WeaponCSBase `RTTI Type Descriptor',
                               isReference: 0);
      v7 = v6;
      if ( v6 != nullptr )
      {
        v8 = v6->GetCSWeaponID(this: v6);
        v9 = v8;
        if ( (showPistol || !IsSecondaryWeapon(id: v8)) && v9 != WEAPON_C4 )
          SFItemHistory::AddToHistory(this: pItemHistory, pWeapon: v7);
        if ( C_WeaponCSBase::GetCSWpnData(this: v7)->m_WeaponType == WEAPONTYPE_GRENADE )
        {
          v10 = v7->GetPrimaryAmmoType(this: v7);
          AmmoCount = C_BaseCombatCharacter::GetAmmoCount(this, iAmmoIndex: v10);
          if ( AmmoCount > 1 )
          {
            v12 = AmmoCount - 1;
            do
            {
              SFItemHistory::AddToHistory(this: pItemHistory, pWeapon: v7);
              --v12;
            }
            while ( v12 != 0 );
          }
        }
      }
      v4 = i + 1;
      i = v4;
    }
    while ( v4 < 64 );
    if ( this->m_bHasDefuser )
      SFItemHistory::AddToHistory(this: pItemHistory, name: "defuser", displayName: "#Cstrike_BMDefuser");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B9D80
// Name: public: virtual void C_TEPlayerAnimEvent::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEPlayerAnimEvent::PostDataUpdate(C_TEPlayerAnimEvent *this, DataUpdateType_t updateType)
{
  C_BaseTempEntity *m_pNextDynamic; // ecx
  CEntInfo *v4; // eax
  IHandleEntity *m_pEntity; // esi
  unsigned int m_Index; // eax

  m_pNextDynamic = this->m_pNextDynamic;
  if ( m_pNextDynamic != (C_BaseTempEntity *)-1 )
  {
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_pNextDynamic];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_pNextDynamic].m_SerialNumber == (unsigned int)m_pNextDynamic >> 16 )
    {
      m_pEntity = v4->m_pEntity;
      if ( v4->m_pEntity != nullptr
        && m_pEntity->__vftable[48].GetRefEHandle(this: m_pEntity) != nullptr
        && ((unsigned __int8 (__thiscall *)(IHandleEntity *))m_pEntity[2].__vftable[3].dtr_IHandleEntity)(a1: &m_pEntity[2]) == 0 )
      {
        m_Index = this->m_hPlayer.m_Value.m_Index;
        if ( m_Index != 2 )
          (*(void (__thiscall **)(IHandleEntity_vtbl *, unsigned int, int))m_pEntity[1689].dtr_IHandleEntity)(
            a1: m_pEntity[1689].__vftable,
            a2: m_Index,
            a3: this->m_iEvent.m_Value);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B9DF0
// Name: private: void C_CSRagdoll::Interp_Copy(class C_BaseAnimatingOverlay __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSRagdoll::Interp_Copy(C_CSRagdoll *this, C_BaseAnimatingOverlay *pSourceEntity)
{
  VarMapEntry_t *v2; // ebx
  VarMapEntry_t *v3; // esi
  IInterpolatedVar *watcher; // edi
  const char *v5; // eax
  const char *v6; // [esp-10h] [ebp-24h]
  int i; // [esp+0h] [ebp-14h]
  C_CSRagdoll *v8; // [esp+4h] [ebp-10h]
  int j; // [esp+8h] [ebp-Ch]
  int v10; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]

  v8 = this;
  if ( pSourceEntity != nullptr )
  {
    i = 0;
    if ( this->m_VarMap.m_Entries.m_Size > 0 )
    {
      v10 = 0;
      do
      {
        v2 = &this->m_VarMap.m_Entries.m_Memory.m_pMemory[v10];
        j = 0;
        if ( pSourceEntity->m_VarMap.m_Entries.m_Size > 0 )
        {
          v11 = 0;
          while ( 1 )
          {
            v3 = &pSourceEntity->m_VarMap.m_Entries.m_Memory.m_pMemory[v11];
            watcher = v3->watcher;
            v6 = v2->watcher->GetDebugName(this: v2->watcher);
            v5 = watcher->GetDebugName(this: watcher);
            if ( _V_strcmp(s1: v5, s2: v6) == 0 )
              break;
            ++v11;
            if ( ++j >= pSourceEntity->m_VarMap.m_Entries.m_Size )
              goto LABEL_10;
          }
          v2->watcher->Copy(this: v2->watcher, a2: v3->watcher);
LABEL_10:
          this = v8;
        }
        ++v10;
        ++i;
      }
      while ( i < this->m_VarMap.m_Entries.m_Size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B9EB0
// Name: private: void C_CSRagdoll::CreateCSRagdoll(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall C_CSRagdoll::CreateCSRagdoll(C_CSRagdoll *this@<ecx>, int a2@<ebp>)
{
  void *v2; // esp
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  C_BasePlayer *v6; // edi
  const QAngle *v7; // eax
  CDiscontinuousInterpolatedVar<QAngle> *RotationInterpolator; // eax
  const QAngle *v9; // eax
  int v10; // eax
  matrix3x4_t v11[256]; // [esp+24h] [ebp-900Ch] BYREF
  matrix3x4_t v12[256]; // [esp+3024h] [ebp-600Ch] BYREF
  matrix3x4_t v13[255]; // [esp+6024h] [ebp-300Ch] BYREF
  int v14; // [esp+9024h] [ebp-Ch]
  void *v15; // [esp+9028h] [ebp-8h]
  void *retaddr; // [esp+9030h] [ebp+0h]

  v14 = a2;
  v15 = retaddr;
  v2 = alloca(36872);
  m_Index = this->m_hPlayer.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v6 = (C_BasePlayer *)__RTDynamicCast(
                         inptr: m_pEntity,
                         VfDelta: 0,
                         SrcType: &C_BaseEntity `RTTI Type Descriptor',
                         TargetType: &C_CSPlayer `RTTI Type Descriptor',
                         isReference: 0);
  C_BaseAnimating::SetReceivedSequence(this);
  if ( v6 == nullptr || v6->IsDormant(this: &v6->IClientNetworkable) )
  {
    C_BaseEntity::SetNetworkOrigin(this, org: &this->m_vecRagdollOrigin.m_Value);
    C_BaseEntity::SetAbsOrigin(this, absOrigin: &this->m_vecRagdollOrigin.m_Value);
    C_BaseEntity::SetAbsVelocity(this, vecAbsVelocity: &this->m_vecRagdollVelocity.m_Value);
    C_BaseEntity::Interp_Reset(this, map: &this->m_VarMap);
  }
  else
  {
    C_BaseEntity::SnatchModelInstance(this: v6, pToEntity: this);
    if ( v6 == C_BasePlayer::GetLocalPlayer(nSlot: -1) )
    {
      C_BaseEntity::SetAbsOrigin(this, absOrigin: &this->m_vecRagdollOrigin.m_Value);
      v9 = v6->GetRenderAngles(this: &v6->IClientRenderable);
      C_BaseEntity::SetAbsAngles(this, absAngles: v9);
      C_BaseEntity::SetAbsVelocity(this, vecAbsVelocity: &this->m_vecRagdollVelocity.m_Value);
      v10 = C_BaseAnimating::LookupSequence(this, label: "walk_lower");
      if ( v10 == -1 )
        v10 = 0;
      C_BaseAnimating::SetSequence(this, nSequence: v10);
      C_BaseAnimating::SetCycle(this, flCycle: 0.0);
      C_BaseEntity::Interp_Reset(this, map: &this->m_VarMap);
      C_BaseAnimating::CopySequenceTransitions(this, pCopyFrom: v6);
    }
    else
    {
      C_CSRagdoll::Interp_Copy(this, pSourceEntity: v6);
      v7 = v6->GetRenderAngles(this: &v6->IClientRenderable);
      C_BaseEntity::SetAbsAngles(this, absAngles: v7);
      RotationInterpolator = C_BaseEntity::GetRotationInterpolator(this);
      ((void (__thiscall *)(CDiscontinuousInterpolatedVar<QAngle> *, _DWORD))RotationInterpolator->Reset)(
        a1: RotationInterpolator,
        a2: *(_DWORD *)(gpGlobals.m_Index + 12));
      this->m_flAnimTime = v6->m_flAnimTime;
      C_BaseAnimating::SetSequence(this, nSequence: v6->m_nSequence);
      this->m_flPlaybackRate = C_BaseAnimating::GetPlaybackRate(this: v6);
      C_BaseAnimating::CopySequenceTransitions(this, pCopyFrom: v6);
    }
  }
  if ( cl_ragdoll_physics_enable.m_pParent != nullptr && cl_ragdoll_physics_enable.m_pParent->m_Value.m_nValue != 0 )
  {
    this->m_bClientSideRagdoll = true;
    if ( v6 != nullptr && C_BasePlayer::IsLocalPlayer(pEntity: v6) && !v6->IsDormant(this: &v6->IClientNetworkable) )
      ((void (__thiscall *)(C_BasePlayer *, matrix3x4_t *, matrix3x4_t *, matrix3x4_t *, int))v6->GetRagdollInitBoneArrays)(
        a1: v6,
        a2: v11,
        a3: v13,
        a4: v12,
        a5: 1028443341);
    else
      ((void (__thiscall *)(C_CSRagdoll *, matrix3x4_t *, matrix3x4_t *, matrix3x4_t *, int))this->GetRagdollInitBoneArrays)(
        a1: this,
        a2: v11,
        a3: v13,
        a4: v12,
        a5: 1028443341);
    C_BaseAnimating::InitAsClientRagdoll(
      this,
      pDeltaBones0: v11,
      pDeltaBones1: v13,
      pCurrentBonePosition: v12,
      boneDt: 0.050000001);
    this->m_bInitialized = true;
  }
  else
  {
    C_BaseEntity::SetRenderMode(this, nRenderMode: kRenderTransTexture, bForceUpdate: false);
    C_BaseEntity::SetRenderFX(
      this,
      nRenderFX: kRenderFxFadeOut,
      flStartTime: *(float *)(gpGlobals.m_Index + 12),
      flDuration: g_flDieTranslucentTime);
    this->m_bInitialized = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BA180
// Name: public: static void C_CSPlayer::RecvProxy_CycleLatch(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl C_CSPlayer::RecvProxy_CycleLatch(const CRecvProxyData *pData, float *pStruct)
{
  float v3; // xmm0_4
  int v4; // edi
  const char *PlayerName; // eax
  int v6; // [esp-4h] [ebp-20h]
  float currentCycle; // [esp+18h] [ebp-4h]
  float incomingCycle; // [esp+28h] [ebp+Ch]

  if ( !C_BasePlayer::IsLocalPlayer(pEntity: (C_BaseEntity *)pStruct) )
  {
    currentCycle = pStruct[617];
    LODWORD(v3) = COERCE_UNSIGNED_INT(currentCycle - (float)((float)pData->m_Value.m_Int * 0.0625)) & _mask__AbsFloat_;
    incomingCycle = (float)pData->m_Value.m_Int * 0.0625;
    if ( v3 <= 0.85000002 && v3 >= 0.15000001 )
    {
      if ( (*(int (__thiscall **)(float *))(*(_DWORD *)pStruct + 328))(a1: pStruct) != 0 )
      {
        v4 = (*(int (__thiscall **)(float *))(*(_DWORD *)pStruct + 328))(a1: pStruct);
        v6 = (*(int (__thiscall **)(char *, _DWORD, _DWORD, _DWORD, _DWORD))(*((_DWORD *)pStruct + 2) + 40))(
               a1: (char *)pStruct + 8,
               a2: COERCE_UNSIGNED_INT64(currentCycle),
               a3: HIDWORD(COERCE_UNSIGNED_INT64(currentCycle)),
               a4: COERCE_UNSIGNED_INT64(incomingCycle),
               a5: HIDWORD(COERCE_UNSIGNED_INT64(incomingCycle)));
        PlayerName = C_BasePlayer::GetPlayerName(this: (C_BasePlayer *)pStruct);
        (*(void (__thiscall **)(int, const char *, int))(*(_DWORD *)v4 + 688))(a1: v4, a2: PlayerName, a3: v6);
        _DevMsg(a1: 2, a2: "%s %s(%d): Cycle latch wants to correct %.2f in to %.2f.\n");
      }
      (*(void (__thiscall **)(float *, float))(*(_DWORD *)pStruct + 832))(
        a1: pStruct,
        a2: COERCE_FLOAT(LODWORD(incomingCycle)));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BA280
// Name: public: int C_CSPlayer::GetIDTarget(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_CSPlayer::GetIDTarget(C_CSPlayer *this)
{
  int result; // eax

  if ( CountdownTimer::Now(this: (CEffectsClient *)&this->m_delayTargetIDTimer) <= this->m_delayTargetIDTimer.m_timestamp.m_Value )
    return 0;
  result = this->m_iIDEntIndex;
  if ( result != 0 )
    return result;
  if ( this->m_iOldIDEntIndex != 0
    && CountdownTimer::Now(this: (CEffectsClient *)&this->m_holdTargetIDTimer) <= this->m_holdTargetIDTimer.m_timestamp.m_Value )
  {
    return this->m_iOldIDEntIndex;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BA2E0
// Name: public: void C_CSPlayer::UpdateTargetedWeapon(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSPlayer::UpdateTargetedWeapon(C_CSPlayer *this)
{
  int (*EyeAngles)(void); // eax
  const QAngle *v3; // eax
  Vector *(__thiscall *EyePosition)(C_BaseEntity *, Vector *); // edx
  float *v5; // eax
  Vector *(__thiscall *v6)(C_BaseEntity *, Vector *); // edx
  const Vector *v7; // eax
  CGameTrace result; // [esp+4h] [ebp-90h] BYREF
  Vector vecAbsEnd; // [esp+58h] [ebp-3Ch] BYREF
  Vector v10; // [esp+64h] [ebp-30h] BYREF
  Vector aimDir; // [esp+70h] [ebp-24h] BYREF
  unsigned int mask[3]; // [esp+7Ch] [ebp-18h] BYREF
  float v13; // [esp+88h] [ebp-Ch]
  float v14; // [esp+8Ch] [ebp-8h]
  float v15; // [esp+90h] [ebp-4h]
  IHandleEntity savedregs; // [esp+94h] [ebp+0h] BYREF

  EyeAngles = (int (*)(void))this->EyeAngles;
  this->m_iTargetedWeaponEntIndex = 0;
  v3 = (const QAngle *)EyeAngles();
  AngleVectors(angles: v3, forward: &aimDir);
  EyePosition = this->EyePosition;
  v13 = aimDir.x * 275.0;
  v14 = aimDir.y * 275.0;
  v15 = aimDir.z * 275.0;
  v5 = (float *)EyePosition(this, result: &v10);
  v6 = this->EyePosition;
  *(float *)mask = *v5 + v13;
  *(float *)&mask[1] = v5[1] + v14;
  *(float *)&mask[2] = v5[2] + v15;
  v7 = (const Vector *)((int (__thiscall *)(C_CSPlayer *))v6)(a1: this);
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)this,
    vecAbsStart: v7,
    &vecAbsEnd,
    (unsigned int)mask,
    ignore: (const IHandleEntity *)0xFFFFFFFF,
    collisionGroup: (int)this,
    ptr: nullptr);
  if ( CGameTrace::DidHitNonWorldEntity(this: &result)
    && (*(unsigned __int8 (__thiscall **)(struct CBaseEntity *))(*(_DWORD *)result.m_pEnt + 612))(a1: result.m_pEnt) != 0 )
  {
    this->m_iTargetedWeaponEntIndex = (*(int (__thiscall **)(char *))(*((_DWORD *)result.m_pEnt + 2) + 40))(a1: (char *)result.m_pEnt + 8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BA3E0
// Name: public: virtual void C_CSPlayer::FireEvent(class Vector const __near &,class QAngle const __near &,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSPlayer::FireEvent(
        C_CSPlayer *this,
        const Vector *origin,
        const QAngle *angles,
        int event,
        const char *options)
{
  int m_nWaterLevel; // eax
  char v6; // dl
  char v7; // al
  float v8; // xmm0_4
  float v9; // xmm3_4
  float z; // xmm0_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  CGameTrace tr; // [esp+14h] [ebp-C4h] BYREF
  CEffectData data; // [esp+68h] [ebp-70h] BYREF
  Vector vecAbsEnd; // [esp+CCh] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+D8h] [ebp+0h] BYREF

  if ( event == 7001 || event == 7002 )
  {
    m_nWaterLevel = this->m_nWaterLevel;
    if ( m_nWaterLevel == 1 )
    {
      v7 = 1;
      v6 = 0;
    }
    else if ( (unsigned int)(m_nWaterLevel - 2) > 1 )
    {
      v6 = 0;
      v7 = 0;
    }
    else
    {
      v6 = 1;
      v7 = 1;
    }
    if ( this->m_fFlags != 0 && (v7 != 0 || v6 != 0) )
    {
      if ( event == 7001 )
      {
        if ( v7 != 0 )
        {
          memset((void *)&data, 0, 52);
          memset(&data.m_flMagnitude, 0, 14);
          vecAbsEnd.x = origin->x;
          vecAbsEnd.y = origin->y;
          v8 = origin->z + 1024.0;
          data.m_hEntity.m_Index = -1;
          data.m_flScale = 1.0;
          memset(&data.m_nMaterial, 0, 17);
          vecAbsEnd.z = v8;
          UTIL_TraceLine(
            a1: &savedregs,
            a2: (int)origin,
            vecAbsStart: origin,
            &vecAbsEnd,
            mask: 0x4030u,
            ignore: nullptr,
            collisionGroup: 0,
            ptr: &tr);
          if ( tr.fractionleftsolid == 0.0 )
          {
            data.m_vOrigin.x = origin->x;
            data.m_vOrigin.y = origin->y;
            z = origin->z;
          }
          else
          {
            v9 = origin->y + (float)(tr.fractionleftsolid * 0.0);
            z = origin->z + (float)(tr.fractionleftsolid * 1024.0);
            data.m_vOrigin.x = origin->x + (float)(tr.fractionleftsolid * 0.0);
            data.m_vOrigin.y = v9;
          }
          data.m_vOrigin.z = z;
          data.m_vNormal.z = 1.0;
          data.m_vNormal.x = 0.0;
          data.m_vNormal.y = 0.0;
          data.m_flScale = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                             a1: random,
                             a2: 1082130432,
                             a3: 1084227584);
          DispatchEffect(pName: "watersplash", &data);
        }
      }
      else if ( v7 != 0 )
      {
        CEffectData::CEffectData(this: &data);
        vecAbsEnd.x = origin->x;
        vecAbsEnd.y = origin->y;
        vecAbsEnd.z = origin->z + 1024.0;
        UTIL_TraceLine(
          a1: &savedregs,
          a2: (int)origin,
          vecAbsStart: origin,
          &vecAbsEnd,
          mask: 0x4030u,
          ignore: nullptr,
          collisionGroup: 0,
          ptr: &tr);
        if ( tr.fractionleftsolid == 0.0 )
        {
          data.m_vOrigin.x = origin->x;
          data.m_vOrigin.y = origin->y;
          v12 = origin->z;
        }
        else
        {
          v11 = origin->y + (float)(tr.fractionleftsolid * 0.0);
          v12 = origin->z + (float)(tr.fractionleftsolid * 1024.0);
          data.m_vOrigin.x = origin->x + (float)(tr.fractionleftsolid * 0.0);
          data.m_vOrigin.y = v11;
        }
        data.m_vOrigin.z = v12;
        data.m_vNormal.z = 1.0;
        data.m_vNormal.x = 0.0;
        data.m_vNormal.y = 0.0;
        data.m_flScale = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                           a1: random,
                           a2: 1082130432,
                           a3: 1088421888);
        DispatchEffect(pName: "waterripple", &data);
      }
    }
  }
  else
  {
    C_BaseAnimating::FireEvent(this, origin, angles, event, options);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BA730
// Name: public: virtual bool C_CSPlayer::Simulate(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_CSPlayer::Simulate(C_CSPlayer *this)
{
  int v2; // eax
  Beam_t *m_pFlashlightBeam; // eax
  dlight_t *v5; // eax
  Beam_t *v6; // eax
  QAngle dummy; // [esp+Ch] [ebp-120h] BYREF
  CGameTrace tr; // [esp+18h] [ebp-114h] BYREF
  QAngle eyeAngles; // [esp+6Ch] [ebp-C0h] BYREF
  BeamInfo_t beamInfo; // [esp+78h] [ebp-B4h] BYREF
  Vector vecAbsEnd; // [esp+108h] [ebp-24h] BYREF
  Vector vForward; // [esp+114h] [ebp-18h] BYREF
  Vector vecOrigin; // [esp+120h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+12Ch] [ebp+0h] BYREF

  if ( !C_BasePlayer::IsLocalPlayer(pEntity: this) )
  {
    if ( (this->m_fEffects & 4) != 0 )
    {
      eyeAngles = *this->EyeAngles(this);
      AngleVectors(angles: &eyeAngles, forward: &vForward);
      v2 = this->LookupAttachment(this: &this->IClientRenderable, a2: "muzzle_flash");
      if ( v2 < 0 )
        return 0;
      this->GetAttachment_2(this: &this->IClientRenderable, a2: v2, a3: &vecOrigin, a4: &dummy);
      vecAbsEnd.y = vecOrigin.y + (float)(vForward.y * 200.0);
      vecAbsEnd.x = vecOrigin.x + (float)(vForward.x * 200.0);
      vecAbsEnd.z = vecOrigin.z + (float)(vForward.z * 200.0);
      UTIL_TraceLine(
        a1: &savedregs,
        a2: (int)this,
        vecAbsStart: &vecOrigin,
        &vecAbsEnd,
        mask: 0x46004003u,
        ignore: this,
        collisionGroup: 0,
        ptr: &tr);
      if ( this->m_pFlashlightBeam == nullptr )
      {
        beamInfo.m_vecStart = tr.startpos;
        beamInfo.m_vecEnd = tr.endpos;
        beamInfo.m_flHaloScale = 3.0;
        beamInfo.m_flWidth = 8.0;
        beamInfo.m_flEndWidth = 35.0;
        beamInfo.m_flFadeLength = 300.0;
        beamInfo.m_flRed = 255.0;
        beamInfo.m_flGreen = 255.0;
        beamInfo.m_flBlue = 255.0;
        beamInfo.m_pszModelName = "sprites/glow01.vmt";
        beamInfo.m_pszHaloName = "sprites/glow01.vmt";
        beamInfo.m_nModelIndex = -1;
        beamInfo.m_nHaloIndex = -1;
        beamInfo.m_nType = 0;
        beamInfo.m_flAmplitude = 0.0;
        beamInfo.m_flBrightness = 60.0;
        memset(&beamInfo.m_flSpeed, 0, 12);
        beamInfo.m_nSegments = 8;
        beamInfo.m_bRenderable = true;
        beamInfo.m_flLife = 0.5;
        beamInfo.m_nFlags = 49920;
        this->m_pFlashlightBeam = beams->CreateBeamPoints_2(this: beams, a2: &beamInfo);
      }
      m_pFlashlightBeam = this->m_pFlashlightBeam;
      if ( m_pFlashlightBeam != nullptr )
      {
        beamInfo.m_vecStart = tr.startpos;
        beamInfo.m_vecEnd = tr.endpos;
        beamInfo.m_nSegments = -1;
        beamInfo.m_nModelIndex = -1;
        beamInfo.m_nHaloIndex = -1;
        beamInfo.m_nType = 0;
        beamInfo.m_pszModelName = nullptr;
        beamInfo.m_pszHaloName = nullptr;
        beamInfo.m_bRenderable = true;
        beamInfo.m_nFlags = 0;
        beamInfo.m_flRed = 255.0;
        beamInfo.m_flGreen = 255.0;
        beamInfo.m_flBlue = 255.0;
        beams->UpdateBeamInfo(this: beams, a2: m_pFlashlightBeam, a3: &beamInfo);
        v5 = effects->CL_AllocDlight(this: effects, a2: 0);
        v5->origin = tr.endpos;
        v5->radius = 50.0;
        v5->color.b = -56;
        *(_WORD *)&v5->color.r = -14136;
        v5->die = *(float *)(gpGlobals.m_Index + 12) + 0.1;
        C_BasePlayer::Simulate(this);
        return 1;
      }
    }
    else
    {
      v6 = this->m_pFlashlightBeam;
      if ( v6 != nullptr )
      {
        v6->flags = 0;
        this->m_pFlashlightBeam->die = *(float *)(gpGlobals.m_Index + 12) - 1.0;
        this->m_pFlashlightBeam = nullptr;
      }
    }
  }
  C_BasePlayer::Simulate(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101BAAF0
// Name: public: virtual void C_CSPlayer::ImpactTrace(class CGameTrace __near *,int,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSPlayer::ImpactTrace(C_CSPlayer *this, CGameTrace *pTrace, int iDamageType, char *pCustomImpactName)
{
  ConVar *v5; // eax
  ConVar *m_pParent; // eax

  if ( (_S11 & 1) != 0 )
  {
    v5 = violence_hblood_1;
  }
  else
  {
    _S11 |= 1u;
    v5 = cvar->FindVar_2(this: cvar, a2: "violence_hblood");
    violence_hblood_1 = v5;
  }
  if ( v5 == nullptr || (m_pParent = v5->m_pParent) != nullptr && m_pParent->m_Value.m_nValue != 0 )
    C_BaseEntity::ImpactTrace(this, pTrace, iDamageType, pCustomImpactName);
}

//------------------------------------------------------------------------------
// Address: 0x101BAB50
// Name: public: virtual void C_CSPlayer::CalcFreezeCamView(class Vector __near &,class QAngle __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge C_CSPlayer::CalcFreezeCamView(
        C_CSPlayer *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        Vector *eyeOrigin,
        QAngle *eyeAngles,
        float *fov)
{
  float x; // eax
  __int64 v9; // xmm0_8
  QAngle *v10; // ecx
  float z; // edx
  void (__thiscall *v12)(_DWORD); // edx
  Vector *v13; // eax
  const CViewVectors *v14; // eax
  float v15; // ecx
  float v16; // xmm0_4
  int v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  int m_nValue; // eax
  __int128 v22; // xmm0
  int v23; // eax
  __int64 v24; // xmm0_8
  float v25; // eax
  float v26; // xmm1_4
  __int128 v27; // xmm0
  IGameEvent *v28; // eax
  _BYTE v30[12]; // [esp+38h] [ebp-CCh] BYREF
  _BYTE trace[88]; // [esp+44h] [ebp-C0h] OVERLAPPED
  Vector prevEyeOrigin; // [esp+9Ch] [ebp-68h]
  __int128 prevEyeAngles; // [esp+A8h] [ebp-5Ch] OVERLAPPED BYREF
  Vector vecMaxs_4; // [esp+BCh] [ebp-48h] OVERLAPPED BYREF
  float fCurTime; // [esp+C8h] [ebp-3Ch]
  Vector vecMins; // [esp+CCh] [ebp-38h] BYREF
  Vector vToTarget; // [esp+D8h] [ebp-2Ch] BYREF
  float targetRadius; // [esp+E4h] [ebp-20h]
  Vector vLookAt; // [esp+E8h] [ebp-1Ch] BYREF
  Vector vTargetPos; // [esp+F4h] [ebp-10h] BYREF
  float retaddr; // [esp+104h] [ebp+0h]

  vTargetPos.y = a2;
  vTargetPos.z = retaddr;
  x = COERCE_FLOAT(((int (__thiscall *)(C_CSPlayer *, int, int))this->GetObserverTarget)(a1: this, a2: a3, a3: a4));
  v9 = *(_QWORD *)&eyeOrigin->x;
  *(float *)&trace[84] = eyeOrigin->z;
  v10 = eyeAngles;
  z = eyeAngles->z;
  *(_QWORD *)&trace[76] = v9;
  vTargetPos.x = x;
  *(_QWORD *)&prevEyeOrigin.x = *(_QWORD *)&eyeAngles->x;
  prevEyeOrigin.z = z;
  if ( (_S12 & 1) == 0 )
  {
    _S12 |= 1u;
    ConVarRef::ConVarRef(this: &sv_disablefreezecam, pName: "sv_disablefreezecam");
    x = vTargetPos.x;
    v10 = eyeAngles;
  }
  if ( x == 0.0
    || cl_disablefreezecam.m_pParent != nullptr && cl_disablefreezecam.m_pParent->m_Value.m_nValue != 0
    || sv_disablefreezecam.m_pConVarState->m_Value.m_nValue != 0 )
  {
    ((void (__thiscall *)(C_CSPlayer *, Vector *, QAngle *))this->CalcDeathCamView)(a1: this, a2: eyeOrigin, a3: v10);
  }
  else
  {
    v12 = *(void (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(x) + 192);
    LODWORD(vTargetPos.x) = &vToTarget.y;
    v12(a1: LODWORD(x));
    v13 = this->GetChaseCamViewOffset(this, result: (char *)&prevEyeAngles + 4, a3: LODWORD(vTargetPos.x));
    vToTarget.y = v13->x + vToTarget.y;
    vToTarget.z = v13->y + vToTarget.z;
    targetRadius = v13->z + targetRadius;
    if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(vTargetPos.x) + 576))(a1: LODWORD(vTargetPos.x)) == 0 )
    {
      v14 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      targetRadius = v14->m_vDeadViewHeight.z + targetRadius;
    }
    v15 = eyeOrigin->z;
    *(_QWORD *)&vLookAt.x = *(_QWORD *)&eyeOrigin->x;
    vecMins.x = vToTarget.y - vLookAt.x;
    vecMins.y = vToTarget.z - vLookAt.y;
    vecMins.z = 0.0;
    VectorNormalize(vec: (Vector *)LODWORD(v15));
    vLookAt.z = targetRadius - (float)(vecMins.z * this->m_flFreezeFrameDistance);
    C_BaseEntity::PushEnableAbsRecomputations(bEnable: false);
    UTIL_TraceHull(
      a1: (const IHandleEntity *)&vTargetPos.y,
      a2: (int)this,
      vecAbsStart: (Vector *)&vToTarget.y,
      vecAbsEnd: &vLookAt,
      hullMin: &WALL_MIN_1,
      hullMax: &WALL_MAX_1,
      mask: 0x200400Bu,
      ignore: (const IHandleEntity *)LODWORD(vTargetPos.x),
      collisionGroup: 0,
      ptr: (CGameTrace *)v30);
    C_BaseEntity::PopEnableAbsRecomputations();
    if ( *(float *)&trace[32] < 1.0 )
    {
      v16 = COERCE_FLOAT(COERCE_UNSIGNED_INT(targetRadius - *(float *)&trace[8]) & _mask__AbsFloat_) * 0.85
          + *(float *)&trace[8];
      C_BaseEntity::PushEnableAbsRecomputations(bEnable: SLOBYTE(v16));
      UTIL_TraceHull(
        a1: (const IHandleEntity *)&vTargetPos.y,
        a2: (int)this,
        vecAbsStart: (Vector *)&vToTarget.y,
        vecAbsEnd: &vLookAt,
        hullMin: &WALL_MIN_1,
        hullMax: &WALL_MAX_1,
        mask: 0x200400Bu,
        ignore: (const IHandleEntity *)LODWORD(vTargetPos.x),
        collisionGroup: 0,
        ptr: (CGameTrace *)v30);
      C_BaseEntity::PopEnableAbsRecomputations();
      vLookAt = *(Vector *)trace;
    }
    vecMins.x = vToTarget.y - vLookAt.x;
    vecMins.y = vToTarget.z - vLookAt.y;
    vecMins.z = targetRadius - vLookAt.z;
    VectorNormalize(vec: &vecMins);
    VectorAngles(forward: &vecMins, angles: eyeAngles);
    *(float *)&v17 = 0.0;
    vecMaxs_4.x = *(float *)(gpGlobals.m_Index + 12) - this->m_flFreezeFrameStartTime;
    v18 = vecMaxs_4.x / spec_freeze_traveltime.m_pParent->m_Value.m_fValue;
    if ( v18 < 0.0 || (*(float *)&v17 = 1.0, v18 > 1.0) )
      v18 = *(float *)&v17;
    vToTarget.x = Interpolators::SmoothStepEnd(t: v18);
    v19 = vToTarget.x;
    eyeOrigin->x = (float)((float)(vLookAt.x - this->m_vecFreezeFrameStart.x) * vToTarget.x)
                 + this->m_vecFreezeFrameStart.x;
    v20 = vLookAt.z;
    eyeOrigin->y = (float)((float)(vLookAt.y - this->m_vecFreezeFrameStart.y) * v19) + this->m_vecFreezeFrameStart.y;
    eyeOrigin->z = (float)((float)(v20 - this->m_vecFreezeFrameStart.z) * v19) + this->m_vecFreezeFrameStart.z;
    if ( cl_freeze_cam_penetration_tolerance.m_pParent != nullptr )
      m_nValue = cl_freeze_cam_penetration_tolerance.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    if ( !this->m_bSentFreezeFrame && m_nValue >= 0 )
    {
      vToTarget.x = (float)m_nValue;
      if ( (float)m_nValue <= 0.0 )
      {
        (*(void (__thiscall **)(int, float *, char *))(*(_DWORD *)(LODWORD(vTargetPos.x) + 4) + 68))(
          a1: LODWORD(vTargetPos.x) + 4,
          a2: &vecMaxs_4.y,
          a3: (char *)&prevEyeAngles + 4);
        v22 = 0;
        *(float *)&v22 = fsqrt(
                           (float)((float)(vecMaxs_4.z - *((float *)&prevEyeAngles + 2))
                                 * (float)(vecMaxs_4.z - *((float *)&prevEyeAngles + 2)))
                         + (float)((float)(vecMaxs_4.y - *((float *)&prevEyeAngles + 1))
                                 * (float)(vecMaxs_4.y - *((float *)&prevEyeAngles + 1))));
        prevEyeAngles = v22;
        vToTarget.x = *(float *)&v22 * 0.25;
      }
      v23 = (*(int (__thiscall **)(int))(*(_DWORD *)(LODWORD(vTargetPos.x) + 4) + 4))(a1: LODWORD(vTargetPos.x) + 4);
      v24 = *(_QWORD *)v23;
      v25 = *(float *)(v23 + 8);
      *(_QWORD *)&vecMaxs_4.y = v24;
      v26 = (float)((float)(*((float *)&v24 + 1) - vLookAt.y) * (float)(*((float *)&v24 + 1) - vLookAt.y))
          + (float)((float)(*(float *)&v24 - vLookAt.x) * (float)(*(float *)&v24 - vLookAt.x));
      v27 = 0;
      *(float *)&v27 = fsqrt(v26);
      prevEyeAngles = v27;
      fCurTime = v25;
      if ( vToTarget.x > *(float *)&v27 )
      {
        *eyeOrigin = *(Vector *)&trace[76];
        *eyeAngles = (QAngle)prevEyeOrigin;
      }
    }
    if ( vecMaxs_4.x >= spec_freeze_traveltime.m_pParent->m_Value.m_fValue && !this->m_bSentFreezeFrame )
    {
      v28 = (IGameEvent *)((int (__thiscall *)(IGameEventManager2 *, const char *, _DWORD, _DWORD, _DWORD))gameeventmanager->CreateEventA)(
                            a1: gameeventmanager,
                            a2: "freezecam_started",
                            a3: 0,
                            a4: 0,
                            a5: LODWORD(vTargetPos.x));
      if ( v28 != nullptr )
        gameeventmanager->FireEventClientSide(this: gameeventmanager, a2: v28);
      this->m_bSentFreezeFrame = true;
      ((void (__cdecl *)(_DWORD))view->FreezeFrame)(a1: LODWORD(spec_freeze_time.m_pParent->m_Value.m_fValue));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BB0A0
// Name: public: virtual float C_CSPlayer::GetDeathCamInterpolationTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_CSPlayer::GetDeathCamInterpolationTime(C_CSPlayer *this)
{
  if ( (_S13 & 1) == 0 )
  {
    _S13 |= 1u;
    ConVarRef::ConVarRef(this: &sv_disablefreezecam_0, pName: "sv_disablefreezecam");
  }
  if ( cl_disablefreezecam.m_pParent != nullptr && cl_disablefreezecam.m_pParent->m_Value.m_nValue != 0
    || sv_disablefreezecam_0.m_pConVarState->m_Value.m_nValue != 0
    || this->GetObserverTarget(this) == nullptr )
  {
    return spec_freeze_time.m_pParent->m_Value.m_fValue;
  }
  else
  {
    return 0.80000001;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BB110
// Name: public: virtual void C_CSPlayer::CalcDeathCamView(class Vector __near &,class QAngle __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge C_CSPlayer::CalcDeathCamView(
        C_CSPlayer *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        Vector *eyeOrigin,
        QAngle *eyeAngles,
        float *fov)
{
  float v8; // xmm0_4
  float v9; // xmm0_4
  int v10; // xmm1_4
  Vector *(__thiscall *EyePosition)(C_BaseEntity *, Vector *); // edx
  IRagdoll *v12; // eax
  int v13; // eax
  const CViewVectors *v14; // eax
  float *v15; // eax
  float v16; // xmm0_4
  float y; // xmm2_4
  float z; // xmm3_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm1_4
  __int128 v22; // xmm0
  int v23; // [esp+Ch] [ebp-CCh]
  int v24; // [esp+10h] [ebp-C8h]
  _DWORD v25[3]; // [esp+14h] [ebp-C4h] BYREF
  CGameTrace trace; // [esp+20h] [ebp-B8h] BYREF
  int v27; // [esp+74h] [ebp-64h]
  int v28; // [esp+78h] [ebp-60h]
  __int128 aKiller; // [esp+7Ch] [ebp-5Ch] OVERLAPPED BYREF
  int v30; // [esp+8Ch] [ebp-4Ch]
  int v31; // [esp+90h] [ebp-48h]
  QAngle v32; // [esp+94h] [ebp-44h] BYREF
  QAngle aForward; // [esp+A0h] [ebp-38h] BYREF
  Vector vKiller; // [esp+ACh] [ebp-2Ch] BYREF
  Vector vForward; // [esp+B8h] [ebp-20h] BYREF
  C_BaseEntity *pKiller; // [esp+C4h] [ebp-14h]
  float v37; // [esp+C8h] [ebp-10h]
  Vector origin; // [esp+CCh] [ebp-Ch] BYREF
  float retaddr; // [esp+D8h] [ebp+0h]

  origin.x = a2;
  origin.y = retaddr;
  v24 = a4;
  v23 = a3;
  vForward.x = 0.0;
  if ( mp_forcecamera.m_pParent == nullptr || mp_forcecamera.m_pParent->m_Value.m_nValue == 0 )
  {
    LODWORD(vForward.x) = ((int (__thiscall *)(C_CSPlayer *, int, int))this->GetObserverTarget)(
                            a1: this,
                            a2: a3,
                            a3: v24);
    *eyeAngles = *this->EyeAngles(this);
  }
  v8 = (float)(*(float *)(gpGlobals.m_Index + 12) - this->m_flDeathTime) * 1.25;
  if ( v8 >= 0.0 )
  {
    if ( v8 <= 1.0 )
      vForward.y = (float)(*(float *)(gpGlobals.m_Index + 12) - this->m_flDeathTime) * 1.25;
    else
      vForward.y = 1.0;
  }
  else
  {
    vForward.y = 0.0;
  }
  v9 = (float)(*(float *)(gpGlobals.m_Index + 16) * 48.0) + this->m_flObserverChaseDistance;
  *(float *)&v10 = 16.0;
  this->m_flObserverChaseDistance = v9;
  if ( v9 < 16.0 || (*(float *)&v10 = 96.0, v9 > 96.0) )
    v9 = *(float *)&v10;
  EyePosition = this->EyePosition;
  this->m_flObserverChaseDistance = v9;
  ((void (__thiscall *)(C_CSPlayer *, float *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, const char *, _DWORD, int, _DWORD, struct CBaseEntity *, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))EyePosition)(
    a1: this,
    a2: &vForward.z,
    a3: v23,
    a4: v24,
    a5: v25[0],
    a6: v25[1],
    a7: v25[2],
    a8: LODWORD(trace.startpos.x),
    a9: LODWORD(trace.startpos.y),
    a10: LODWORD(trace.startpos.z),
    a11: LODWORD(trace.endpos.x),
    a12: LODWORD(trace.endpos.y),
    a13: LODWORD(trace.endpos.z),
    a14: LODWORD(trace.plane.normal.x),
    a15: LODWORD(trace.plane.normal.y),
    a16: LODWORD(trace.plane.normal.z),
    a17: LODWORD(trace.plane.dist),
    a18: *(_DWORD *)&trace.plane.type,
    a19: LODWORD(trace.fraction),
    a20: trace.contents,
    a21: *(_DWORD *)&trace.dispFlags,
    a22: LODWORD(trace.fractionleftsolid),
    a23: trace.surface.name,
    a24: *(_DWORD *)&trace.surface.surfaceProps,
    a25: trace.hitgroup,
    a26: *(_DWORD *)&trace.physicsbone,
    a27: trace.m_pEnt,
    a28: trace.hitbox,
    a29: v27,
    a30: v28,
    a31: aKiller,
    a32: DWORD1(aKiller),
    a33: DWORD2(aKiller),
    a34: HIDWORD(aKiller),
    a35: v30,
    a36: v31,
    a37: LODWORD(eyeAngles->x),
    a38: LODWORD(eyeAngles->y),
    a39: LODWORD(eyeAngles->z),
    a40: LODWORD(aForward.x),
    a41: LODWORD(aForward.y),
    a42: LODWORD(aForward.z),
    a43: LODWORD(vKiller.x),
    a44: LODWORD(vKiller.y),
    a45: LODWORD(vKiller.z),
    a46: LODWORD(vForward.x),
    a47: LODWORD(vForward.y));
  v12 = this->GetRepresentativeRagdoll(this);
  if ( v12 != nullptr )
  {
    v13 = (int)v12->GetRagdollOrigin(this: v12);
    vForward.z = *(float *)v13;
    pKiller = *(C_BaseEntity **)(v13 + 4);
    v37 = *(float *)(v13 + 8);
    v14 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    v37 = v14->m_vDeadViewHeight.z + v37;
  }
  if ( LODWORD(vForward.x) != 0
    && (*(unsigned __int8 (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(vForward.x) + 584))(a1: LODWORD(vForward.x)) != 0
    && (C_CSPlayer *)LODWORD(vForward.x) != this )
  {
    v15 = (float *)(*(int (__thiscall **)(_DWORD, char *))(*(_DWORD *)LODWORD(vForward.x) + 624))(
                     a1: LODWORD(vForward.x),
                     a2: (char *)&aKiller + 4);
    aForward.x = *v15 - vForward.z;
    aForward.y = v15[1] - *(float *)&pKiller;
    aForward.z = v15[2] - v37;
    VectorAngles(forward: (const Vector *)&aForward, angles: (QAngle *)&trace.hitbox);
    InterpolateAngles(start: &v32, end: (const QAngle *)&trace.hitbox, output: eyeAngles, frac: vForward.y);
  }
  AngleVectors(angles: eyeAngles, forward: &vKiller);
  VectorNormalize(vec: &vKiller);
  LODWORD(v16) = LODWORD(this->m_flObserverChaseDistance) ^ _mask__NegFloat_;
  eyeOrigin->x = (float)(vKiller.x * v16) + vForward.z;
  eyeOrigin->y = (float)(vKiller.y * v16) + *(float *)&pKiller;
  LOBYTE(vForward.x) = 0;
  eyeOrigin->z = (float)(vKiller.z * v16) + v37;
  C_BaseEntity::PushEnableAbsRecomputations(bEnable: SLOBYTE(vForward.x));
  UTIL_TraceHull(
    a1: (const IHandleEntity *)&origin,
    a2: (int)this,
    vecAbsStart: (Vector *)&vForward.z,
    vecAbsEnd: eyeOrigin,
    hullMin: &WALL_MIN_1,
    hullMax: &WALL_MAX_1,
    mask: 0x200400Bu,
    ignore: this,
    collisionGroup: 0,
    ptr: (CGameTrace *)v25);
  C_BaseEntity::PopEnableAbsRecomputations();
  if ( trace.plane.normal.z < 1.0 )
  {
    y = trace.startpos.y;
    z = trace.startpos.z;
    v19 = vForward.z - trace.startpos.x;
    eyeOrigin->x = trace.startpos.x;
    v20 = *(float *)&pKiller - y;
    eyeOrigin->y = y;
    v21 = (float)((float)(v20 * v20) + (float)((float)(v37 - z) * (float)(v37 - z))) + (float)(v19 * v19);
    v22 = 0;
    eyeOrigin->z = z;
    *(float *)&v22 = fsqrt(v21);
    aKiller = v22;
    LODWORD(this->m_flObserverChaseDistance) = v22;
  }
  *fov = this->GetFOV(this);
}

//------------------------------------------------------------------------------
// Address: 0x101BB420
// Name: public: bool C_CSPlayer::IsCursorOnAutoAimTarget(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CSPlayer::IsCursorOnAutoAimTarget(C_CSPlayer *this)
{
  struct CBaseEntity *m_pEnt; // edi
  bool result; // al
  CGameTrace tr; // [esp+8h] [ebp-84h] BYREF
  Vector up; // [esp+5Ch] [ebp-30h] BYREF
  Vector forward; // [esp+68h] [ebp-24h] BYREF
  Vector searchEnd; // [esp+74h] [ebp-18h] BYREF
  Vector searchStart; // [esp+80h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+8Ch] [ebp+0h] BYREF

  C_BasePlayer::EyeVectors(this, pForward: &forward, pRight: nullptr, pUp: &up);
  this->EyePosition(this, result: &searchStart);
  searchEnd.y = searchStart.y + (float)(forward.y * 2048.0);
  searchEnd.x = searchStart.x + (float)(forward.x * 2048.0);
  searchEnd.z = searchStart.z + (float)(forward.z * 2048.0);
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)this,
    vecAbsStart: &searchStart,
    vecAbsEnd: &searchEnd,
    mask: 0x202608Bu,
    ignore: this,
    collisionGroup: 0,
    ptr: &tr);
  result = false;
  if ( tr.fraction != 1.0 && CGameTrace::DidHitNonWorldEntity(this: &tr) && tr.m_pEnt != nullptr )
  {
    m_pEnt = tr.m_pEnt;
    if ( (*(unsigned __int8 (**)(void))(*(_DWORD *)tr.m_pEnt + 584))() != 0
      && !this->InSameTeam(this, a2: (C_BaseEntity *)m_pEnt) )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101BB520
// Name: public: void CStartOfRoundAudioPlayback::PlaySounds(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStartOfRoundAudioPlayback::PlaySounds(CStartOfRoundAudioPlayback *this)
{
  float v1; // xmm0_4
  int v2; // edx
  int v3; // esi

  this->m_bPlaybackEnabled = true;
  v1 = *(float *)(gpGlobals.m_Index + 12);
  v2 = 0;
  if ( this->m_SoundEvents.m_Size > 0 )
  {
    v3 = 0;
    do
    {
      ++v2;
      this->m_SoundEvents.m_Memory.m_pMemory[v3].m_fPlaybackTime = this->m_SoundEvents.m_Memory.m_pMemory[v3].m_fPlaybackTime
                                                                 + v1;
      ++v3;
    }
    while ( v2 < this->m_SoundEvents.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BB820
// Name: public: void CountdownTimer::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CountdownTimer::Reset(CountdownTimer *this)
{
  double v2; // st7
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi
  float v4; // [esp+4h] [ebp-4h]

  v2 = CountdownTimer::Now((CEffectsClient *)this) + this->m_duration.m_Value;
  p_m_timestamp = &this->m_timestamp;
  if ( p_m_timestamp->m_Value != v2 )
  {
    (*(void (__thiscall **)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *, CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *))(LODWORD(p_m_timestamp[-2].m_Value) + 4))(
      a1: p_m_timestamp - 2,
      a2: p_m_timestamp);
    v4 = v2;
    p_m_timestamp->m_Value = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BB860
// Name: private: void C_CSRagdoll::CreateLowViolenceRagdoll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSRagdoll::CreateLowViolenceRagdoll(C_CSRagdoll *this)
{
  int v2; // ebx
  int i; // edi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  C_BaseEntity *v6; // eax
  IUniformRandomStream *v7; // ecx
  C_BaseEntity *v8; // edi
  const QAngle *v9; // eax
  const QAngle *v10; // eax
  int v11; // eax
  int v12; // eax
  char str[512]; // [esp+Ch] [ebp-404h] BYREF
  char pDest[512]; // [esp+20Ch] [ebp-204h] BYREF
  int iMaxDeathAnim; // [esp+40Ch] [ebp-4h]
  int savedregs; // [esp+410h] [ebp+0h] BYREF

  v2 = 9999;
  iMaxDeathAnim = -9999;
  for ( i = 1; i < 100; ++i )
  {
    V_snprintf(pDest, maxLen: 0x200u, pFormat: "death%d", i);
    if ( C_BaseAnimating::LookupSequence(this, label: pDest) == -1 )
      break;
    if ( v2 >= i )
      v2 = i;
    if ( iMaxDeathAnim <= i )
      iMaxDeathAnim = i;
  }
  if ( v2 == 9999 )
  {
    C_CSRagdoll::CreateCSRagdoll(this, a2: (int)&savedregs);
  }
  else
  {
    C_BaseEntity::SetNetworkOrigin(this, org: &this->m_vecRagdollOrigin.m_Value);
    C_BaseEntity::SetAbsOrigin(this, absOrigin: &this->m_vecRagdollOrigin.m_Value);
    C_BaseEntity::SetAbsVelocity(this, vecAbsVelocity: &this->m_vecRagdollVelocity.m_Value);
    m_Index = this->m_hPlayer.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    v6 = (C_BaseEntity *)__RTDynamicCast(
                           inptr: m_pEntity,
                           VfDelta: 0,
                           SrcType: &C_BaseEntity `RTTI Type Descriptor',
                           TargetType: &C_CSPlayer `RTTI Type Descriptor',
                           isReference: 0);
    v8 = v6;
    if ( v6 != nullptr )
    {
      if ( !v6->IsDormant(this: &v6->IClientNetworkable) )
        C_BaseEntity::SnatchModelInstance(this: v8, pToEntity: this);
      v9 = v8->GetRenderAngles(this: &v8->IClientRenderable);
      C_BaseEntity::SetAbsAngles(this, absAngles: v9);
      v10 = v8->GetRenderAngles(this: &v8->IClientRenderable);
      C_BaseEntity::SetNetworkAngles(this, ang: v10);
    }
    v11 = _RandomInt(this: v7, a2: v2, a3: iMaxDeathAnim);
    V_snprintf(pDest: str, maxLen: 0x200u, pFormat: "death%d", v11);
    v12 = C_BaseAnimating::LookupSequence(this, label: str);
    C_BaseAnimating::SetSequence(this, nSequence: v12);
    C_BaseAnimating::ForceClientSideAnimationOn(this);
    C_BaseEntity::Interp_Reset(this, map: &this->m_VarMap);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BB9E0
// Name: public: virtual void C_CSRagdoll::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSRagdoll::OnDataChanged(C_CSRagdoll *this, DataUpdateType_t type)
{
  C_CSRagdoll *v3; // ecx
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  C_BaseAnimating::OnDataChanged(this, updateType: type);
  if ( type != DATA_UPDATE_CREATED )
  {
    if ( cl_ragdoll_physics_enable.m_pParent == nullptr || cl_ragdoll_physics_enable.m_pParent->m_Value.m_nValue == 0 )
      *(&this->m_nOldRenderMode + 1) = 0;
  }
  else
  {
    v3 = (C_CSRagdoll *)((char *)this - 8);
    if ( g_RagdollLVManager.m_bLowViolence )
      C_CSRagdoll::CreateLowViolenceRagdoll(this: v3);
    else
      C_CSRagdoll::CreateCSRagdoll(this: v3, a2: (int)&savedregs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BBA40
// Name: public: void C_CSPlayer::UpdateIDTarget(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSPlayer::UpdateIDTarget(C_CSPlayer *this)
{
  int SplitScreenPlayerSlot; // ebx
  CViewEffects *ViewEffects; // eax
  const Vector *v4; // edi
  const Vector *v5; // eax
  const Vector *v6; // edi
  const Vector *v7; // eax
  C_CSPlayer *LocalOrInEyeCSPlayer; // eax
  C_CSPlayer *v9; // eax
  const Vector *v10; // eax
  float v11; // xmm1_4
  float v12; // xmm2_4
  int v13; // edi
  int v14; // edi
  C_BaseParticleEntity *v15; // ecx
  const Vector *v16; // eax
  int v17; // eax
  const Vector *v18; // [esp+Ch] [ebp-BCh]
  CGameTrace tr; // [esp+2Ch] [ebp-9Ch] BYREF
  CTraceFilterSimple filter; // [esp+80h] [ebp-48h] BYREF
  float flHit2; // [esp+90h] [ebp-38h] BYREF
  float flHit1; // [esp+94h] [ebp-34h] BYREF
  Vector vecStart; // [esp+98h] [ebp-30h] BYREF
  C_BaseEntity *pEntity; // [esp+A4h] [ebp-24h]
  Vector vecEnd; // [esp+A8h] [ebp-20h] BYREF
  Vector vPos; // [esp+B4h] [ebp-14h] BYREF
  bool blend; // [esp+C3h] [ebp-5h] BYREF
  unsigned __int8 color[4]; // [esp+C4h] [ebp-4h] BYREF
  IHandleEntity savedregs; // [esp+C8h] [ebp+0h] BYREF

  if ( C_BasePlayer::IsLocalPlayer(pEntity: this) )
  {
    SplitScreenPlayerSlot = C_BasePlayer::GetSplitScreenPlayerSlot(this);
    this->m_iIDEntIndex = 0;
    if ( (mp_playerid.m_pParent == nullptr || mp_playerid.m_pParent->m_Value.m_nValue != 2)
      && (mp_fadetoblack.m_pParent == nullptr || mp_fadetoblack.m_pParent->m_Value.m_nValue == 0 || this->IsAlive(this))
      && this->GetObserverMode(this) != 5
      && this->GetObserverMode(this) != 1 )
    {
      ViewEffects = GetViewEffects();
      ViewEffects->GetFadeParams(this: ViewEffects, a2: color, a3: &color[1], a4: &color[2], a5: &color[3], a6: &blend);
      if ( (float)color[3] <= 75.0 || !this->IsAlive(this) && this->GetObserverMode(this) != 4 )
      {
        v4 = MainViewForward(nSlot: SplitScreenPlayerSlot);
        v5 = MainViewOrigin(nSlot: SplitScreenPlayerSlot);
        vecEnd.x = (float)(v4->x * 2500.0) + v5->x;
        vecEnd.y = (float)(v4->y * 2500.0) + v5->y;
        vecEnd.z = (float)(v4->z * 2500.0) + v5->z;
        v6 = MainViewForward(nSlot: SplitScreenPlayerSlot);
        v7 = MainViewOrigin(nSlot: SplitScreenPlayerSlot);
        vecStart.x = (float)(v6->x * 10.0) + v7->x;
        vecStart.y = (float)(v6->y * 10.0) + v7->y;
        vecStart.z = (float)(v6->z * 10.0) + v7->z;
        LocalOrInEyeCSPlayer = GetLocalOrInEyeCSPlayer();
        UTIL_TraceLine(
          a1: &savedregs,
          a2: (int)this,
          vecAbsStart: &vecStart,
          vecAbsEnd: &vecEnd,
          mask: 0x2006081u,
          ignore: LocalOrInEyeCSPlayer,
          collisionGroup: 0,
          ptr: &tr);
        if ( !tr.startsolid )
        {
          if ( !CGameTrace::DidHitNonWorldEntity(this: &tr) )
          {
            v9 = GetLocalOrInEyeCSPlayer();
            CTraceFilterSimple::CTraceFilterSimple(
              this: &filter,
              passedict: v9,
              collisionGroup: 0,
              pExtraShouldHitFunc: nullptr);
            v10 = MainViewForward(nSlot: SplitScreenPlayerSlot);
            v11 = (float)(v10->y * 40.0) + vecEnd.y;
            v12 = (float)(v10->z * 40.0) + vecEnd.z;
            vPos.x = (float)(v10->x * 40.0) + vecEnd.x;
            vPos.y = v11;
            vPos.z = v12;
            UTIL_ClipTraceToPlayers(
              a1: (int)&savedregs,
              vecAbsStart: &vecStart,
              vecAbsEnd: &vPos,
              mask: 0x4200400Bu,
              &filter,
              &tr);
          }
          if ( !tr.startsolid && CGameTrace::DidHitNonWorldEntity(this: &tr) )
          {
            pEntity = (C_BaseEntity *)tr.m_pEnt;
            if ( tr.m_pEnt != nullptr && (C_CSPlayer *)tr.m_pEnt != this )
            {
              if ( mp_playerid.m_pParent == nullptr
                || mp_playerid.m_pParent->m_Value.m_nValue != 1
                || (v13 = this->GetTeamNumber(this),
                    (*(int (__thiscall **)(struct CBaseEntity *))(*(_DWORD *)tr.m_pEnt + 332))(a1: tr.m_pEnt) == v13) )
              {
                v14 = 0;
                if ( this->m_SmokeGrenades.m_Size <= 0 )
                {
LABEL_26:
                  if ( C_CSPlayer::GetIDTarget(this) == 0
                    && (this->m_iOldIDEntIndex == 0 || CountdownTimer::IsElapsed(this: &this->m_holdTargetIDTimer)) )
                  {
                    CountdownTimer::Start(
                      this: &this->m_delayTargetIDTimer,
                      duration: mp_playerid_delay.m_pParent->m_Value.m_fValue);
                  }
                  v17 = pEntity->entindex(this: &pEntity->IClientNetworkable);
                  this->m_iIDEntIndex = v17;
                  this->m_iOldIDEntIndex = v17;
                  CountdownTimer::Start(
                    this: &this->m_holdTargetIDTimer,
                    duration: mp_playerid_hold.m_pParent->m_Value.m_fValue);
                }
                else
                {
                  while ( 1 )
                  {
                    v15 = this->m_SmokeGrenades.m_Memory.m_pMemory[v14];
                    if ( v15 != nullptr )
                    {
                      vPos = *v15->GetAbsOrigin(this: v15);
                      v18 = MainViewForward(nSlot: SplitScreenPlayerSlot);
                      v16 = MainViewOrigin(nSlot: SplitScreenPlayerSlot);
                      if ( IntersectInfiniteRayWithSphere(
                             vecRayOrigin: v16,
                             vecRayDelta: v18,
                             vecSphereCenter: &vPos,
                             flRadius: 165.5,
                             pT1: &flHit1,
                             pT2: &flHit2) )
                      {
                        break;
                      }
                    }
                    if ( ++v14 >= this->m_SmokeGrenades.m_Size )
                      goto LABEL_26;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BBDE0
// Name: public: virtual enum ShadowType_t C_CSPlayer::ShadowCastType(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_CSPlayer::ShadowCastType(C_CSPlayer *this)
{
  if ( HIWORD(this->m_flOldSimulationTime) != 0xFFFF && (this->m_nOldRenderMode & 1) != 0 )
    return 3;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101BBF00
// Name: void RecvProxy_NightVision(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_NightVision(const CRecvProxyData *pData, _DWORD *pStruct)
{
  char v2; // al

  v2 = pData->m_Value.m_Int > 0;
  if ( *((_BYTE *)pStruct + 6836) != v2 )
  {
    if ( pData->m_Value.m_Int > 0 )
      pStruct[1713] = 1065353216;
    if ( *((_BYTE *)pStruct + 6836) != v2 )
      *((_BYTE *)pStruct + 6836) = v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BBF40
// Name: void RecvProxy_FlashTime(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_FlashTime(const CRecvProxyData *pData, float *pStruct)
{
  float m_Float; // xmm0_4
  float v3; // xmm1_4
  float v4; // xmm0_4

  if ( C_BasePlayer::IsLocalPlayer(pEntity: (C_BaseEntity *)pStruct) )
  {
    m_Float = pData->m_Value.m_Float;
    v3 = pStruct[1717];
    if ( v3 != m_Float && m_Float > 0.0 )
      pStruct[1714] = 1.0;
    v4 = pData->m_Value.m_Float;
    if ( v3 != v4 )
      pStruct[1717] = v4;
    pStruct[1715] = *(float *)(gpGlobals.m_Index + 12) + pStruct[1717];
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BC450
// Name: public: void C_CSPlayer::HandleTaserAnimation(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall C_CSPlayer::HandleTaserAnimation(C_CSPlayer *this)
{
  unsigned int m_Index; // ecx
  C_CSRagdoll *m_pEntity; // eax

  if ( this->m_bClientSideRagdoll
    && this->m_bKilledByTaser.m_Value
    && *(float *)(gpGlobals.m_Index + 12) > this->m_nextTaserShakeTime )
  {
    m_Index = this->m_hRagdoll.m_Index;
    if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      m_pEntity = (C_CSRagdoll *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      if ( m_pEntity != nullptr )
        C_CSRagdoll::ApplyRandomTaserForce(this: m_pEntity);
    }
    if ( this->m_firstTaserShakeTime == 0.0 )
    {
      this->m_firstTaserShakeTime = *(float *)(gpGlobals.m_Index + 12);
      C_BaseEntity::EmitSound(this, soundname: "Player.DeathTaser", soundtime: 0, duration: nullptr);
    }
    if ( *(float *)(gpGlobals.m_Index + 12) <= (float)(clTaserShakeTimeTotal.m_pParent->m_Value.m_fValue
                                                     + this->m_firstTaserShakeTime) )
    {
      this->m_nextTaserShakeTime = _RandomFloat(
                                     this: (IUniformRandomStream *)clTaserShakeFreqMin.m_pParent,
                                     a2: clTaserShakeFreqMin.m_pParent->m_Value.m_fValue,
                                     a3: clTaserShakeFreqMax.m_pParent->m_Value.m_fValue)
                                 + *(float *)(gpGlobals.m_Index + 12);
    }
    else
    {
      if ( this->m_bKilledByTaser.m_Value )
        this->m_bKilledByTaser.m_Value = false;
      this->m_firstTaserShakeTime = 0.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BC570
// Name: public: virtual void C_CSPlayer::UpdateClientSideAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSPlayer::UpdateClientSideAnimation(C_CSPlayer *this)
{
  ICSPlayerAnimState *m_PlayerAnimState; // edi
  const QAngle *v3; // eax
  int v4; // ecx
  _BYTE *v5; // ecx
  C_BaseCombatWeapon *v6; // eax
  C_BaseViewModel *ViewModel; // eax
  int i; // edi
  C_BaseViewModel *v9; // eax

  if ( this->m_nSequence != -1 )
    ((void (__stdcall *)(_DWORD))this->FrameAdvance)(a1: 0);
  if ( C_BasePlayer::IsLocalPlayer(pEntity: this) )
  {
    m_PlayerAnimState = this->m_PlayerAnimState;
    v3 = this->EyeAngles(this);
    v4 = (int)&m_PlayerAnimState->gap4[*(_DWORD *)(*(_DWORD *)m_PlayerAnimState->gap4 + 4)];
    (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)v4 + 4))(
      a1: v4,
      a2: LODWORD(v3->y),
      a3: LODWORD(this->m_angEyeAngles.x));
  }
  else
  {
    v5 = &this->m_PlayerAnimState->gap4[*(_DWORD *)(*(_DWORD *)this->m_PlayerAnimState->gap4 + 4)];
    (*(void (__thiscall **)(_BYTE *, _DWORD, _DWORD))(*(_DWORD *)v5 + 4))(
      a1: v5,
      a2: LODWORD(this->m_angEyeAngles.y),
      a3: LODWORD(this->m_angEyeAngles.x));
  }
  if ( this->m_nSequence != -1 )
    this->OnLatchInterpolatedVariables(this, a2: 1);
  if ( this->m_bKilledByTaser.m_Value )
    C_CSPlayer::HandleTaserAnimation(this);
  if ( C_BasePlayer::IsLocalPlayer(pEntity: this) )
  {
    v6 = this->GetActiveWeapon(this);
    if ( v6 != nullptr )
    {
      ViewModel = C_BasePlayer::GetViewModel(this, index: v6->m_nViewModelIndex.m_Value);
      if ( ViewModel != nullptr )
        C_BaseViewModel::UpdateViewmodelAddon(this: ViewModel);
    }
    else
    {
      for ( i = 0; i < 2; ++i )
      {
        v9 = C_BasePlayer::GetViewModel(this, index: i);
        if ( v9 != nullptr )
          C_BaseViewModel::RemoveViewmodelAddon(this: v9);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BC6A0
// Name: public: void CStartOfRoundAudioPlayback::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStartOfRoundAudioPlayback::Update(CStartOfRoundAudioPlayback *this)
{
  int v2; // edi
  int v3; // ebx
  RoundStartSoundPlaybackData *v4; // eax
  float m_fPlaybackTime; // xmm0_4
  int nTotalSoundsPlayed; // [esp+14h] [ebp-4h]

  if ( this->m_bPlaybackEnabled )
  {
    v2 = 0;
    v3 = 0;
    for ( nTotalSoundsPlayed = 0; v3 < this->m_SoundEvents.m_Size; ++v2 )
    {
      v4 = &this->m_SoundEvents.m_Memory.m_pMemory[v2];
      if ( v4->m_bHasBeenPlayed )
      {
        ++nTotalSoundsPlayed;
      }
      else
      {
        m_fPlaybackTime = v4->m_fPlaybackTime;
        if ( m_fPlaybackTime > 0.0 && *(float *)(gpGlobals.m_Index + 12) > m_fPlaybackTime )
        {
          if ( v4->m_pEntityPlayingSound != nullptr )
            C_BaseEntity::EmitSound(
              this: v4->m_pEntityPlayingSound,
              soundname: v4->m_SoundName,
              soundtime: 0,
              duration: nullptr);
          this->m_SoundEvents.m_Memory.m_pMemory[v2].m_bHasBeenPlayed = true;
        }
      }
      ++v3;
    }
    if ( nTotalSoundsPlayed == this->m_SoundEvents.m_Size )
    {
      this->m_SoundEvents.m_Size = 0;
      this->m_NextAvailableTime = 1.0;
      this->m_bPlaybackEnabled = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BC740
// Name: public: void CStartOfRoundAudioPlayback::AddSound(class C_BaseEntity __near *,char __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStartOfRoundAudioPlayback::AddSound(
        CStartOfRoundAudioPlayback *this,
        C_BaseEntity *pEntityPlayingSound,
        char *pName,
        float fPlaybackDuration)
{
  int v5; // ebx
  int v6; // edi
  int m_Size; // eax
  RoundStartSoundPlaybackData playbackData; // [esp+Ch] [ebp-4Ch] BYREF

  v5 = 0;
  if ( this->m_SoundEvents.m_Size <= 0 )
  {
LABEL_5:
    if ( pEntityPlayingSound != nullptr && pName != nullptr && (int)_V_strlen(str: pName) > 0 && fPlaybackDuration > 0.0 )
    {
      playbackData.m_SoundName[0] = 0;
      playbackData.m_fPlaybackTime = 0.0;
      playbackData.m_bHasBeenPlayed = false;
      playbackData.m_pEntityPlayingSound = pEntityPlayingSound;
      V_snprintf(pDest: playbackData.m_SoundName, maxLen: 0x40u, pFormat: "%s", pName);
      m_Size = this->m_SoundEvents.m_Size;
      playbackData.m_fPlaybackTime = this->m_NextAvailableTime;
      this->m_NextAvailableTime = playbackData.m_fPlaybackTime + fPlaybackDuration;
      CUtlVector<RoundStartSoundPlaybackData,CUtlMemory<RoundStartSoundPlaybackData,int>>::InsertBefore(
        this: &this->m_SoundEvents,
        elem: m_Size,
        src: &playbackData);
    }
  }
  else
  {
    v6 = 0;
    while ( _V_strcmp(s1: pName, s2: this->m_SoundEvents.m_Memory.m_pMemory[v6].m_SoundName) != 0 )
    {
      ++v5;
      ++v6;
      if ( v5 >= this->m_SoundEvents.m_Size )
        goto LABEL_5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BC8C0
// Name: public: C_CSPlayer::C_CSPlayer(void)
// Source: json
//------------------------------------------------------------------------------
C_CSPlayer *__thiscall C_CSPlayer::C_CSPlayer(C_CSPlayer *this)
{
  CountdownTimer_vtbl *v2; // edx
  CountdownTimer_vtbl *v3; // edx
  CountdownTimer_vtbl *v4; // edx
  CountdownTimer_vtbl *v5; // edx
  CountdownTimer_vtbl *v6; // edx
  CountdownTimer_vtbl *v7; // edx
  UtlLinkedListElem_t<C_CSPlayer::CCSSoundEvent,int> *m_pMemory; // ecx
  UtlLinkedListElem_t<CAddonModel,int> *v9; // edx
  double v10; // st7
  double v11; // st7
  float v13; // [esp+1Ch] [ebp-10h]
  float v14; // [esp+20h] [ebp-Ch]
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *v15; // [esp+24h] [ebp-8h]
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // [esp+28h] [ebp-4h]

  C_BasePlayer::C_BasePlayer(this);
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  this->m_nDebugID = 42;
  this->m_bRegisteredForEvents = false;
  this->ICSPlayerAnimStateHelpers::__vftable = (ICSPlayerAnimStateHelpers_vtbl *)&ICSPlayerAnimStateHelpers::`vftable';
  this->C_BasePlayer::C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_CSPlayer_vtbl *)&C_CSPlayer::`vftable'{for `IClientUnknown'};
  this->C_BasePlayer::C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_CSPlayer::`vftable'{for `IClientRenderable'};
  this->C_BasePlayer::C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_CSPlayer::`vftable'{for `IClientNetworkable'};
  this->C_BasePlayer::C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_CSPlayer::`vftable'{for `IClientThinkable'};
  this->C_BasePlayer::C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_CSPlayer::`vftable'{for `C_BasePlayer'};
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&C_CSPlayer::`vftable'{for `CGameEventListener'};
  this->ICSPlayerAnimStateHelpers::__vftable = (ICSPlayerAnimStateHelpers_vtbl *)&C_CSPlayer::`vftable'{for `ICSPlayerAnimStateHelpers'};
  this->m_SmokeGrenades.m_Memory.m_pMemory = nullptr;
  this->m_SmokeGrenades.m_Memory.m_nAllocationCount = 0;
  this->m_SmokeGrenades.m_Memory.m_nGrowSize = 0;
  this->m_SmokeGrenades.m_Size = 0;
  this->m_SmokeGrenades.m_pElements = nullptr;
  this->m_hRagdoll.m_Index = -1;
  this->m_ladderSurpressionTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v2 = this->m_ladderSurpressionTimer.__vftable;
  this->m_ladderSurpressionTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v2->NetworkStateChanged)(a1: &this->m_ladderSurpressionTimer.m_duration);
  v3 = this->m_ladderSurpressionTimer.__vftable;
  this->m_ladderSurpressionTimer.m_timestamp.m_Value = -1.0;
  v3->NetworkStateChanged(this: &this->m_ladderSurpressionTimer, a2: &this->m_ladderSurpressionTimer.m_timestamp);
  this->m_iv_angEyeAngles.__vftable = (CInterpolatedVar<QAngle>_vtbl *)&CInterpolatedVarArrayBase<QAngle,0>::`vftable';
  this->m_iv_angEyeAngles.m_VarHistory.m_pElements = nullptr;
  *(_DWORD *)&this->m_iv_angEyeAngles.m_VarHistory.m_maxElement = 0;
  *(_DWORD *)&this->m_iv_angEyeAngles.m_VarHistory.m_count = 0x100000;
  CSimpleRingBuffer<CInterpolatedVarEntryBase<QAngle,0>>::EnsureCapacity(
    this: &this->m_iv_angEyeAngles.m_VarHistory,
    capSize: (CInterpolatedVarEntryBase<QAngle,0> *)4);
  this->m_iv_angEyeAngles.m_pDebugName = "C_CSPlayer::m_iv_angEyeAngles";
  this->m_iv_angEyeAngles.m_pValue = nullptr;
  this->m_iv_angEyeAngles.m_InterpolationAmount = 0.0;
  *(_WORD *)&this->m_iv_angEyeAngles.m_fType = 1;
  this->m_iv_angEyeAngles.m_LastNetworkedTime = 0.0;
  this->m_iv_angEyeAngles.m_LastNetworkedValue = nullptr;
  this->m_iv_angEyeAngles.m_bLooping = nullptr;
  this->m_iv_angEyeAngles.__vftable = (CInterpolatedVar<QAngle>_vtbl *)&CInterpolatedVar<QAngle>::`vftable';
  CInterpolatedVarArrayBase<QAngle,0>::SetMaxCount(this: &this->m_iv_angEyeAngles, flCurrentTime: 0.0, newmax: 1);
  this->m_delayTargetIDTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v4 = this->m_delayTargetIDTimer.__vftable;
  this->m_delayTargetIDTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v4->NetworkStateChanged)(a1: &this->m_delayTargetIDTimer.m_duration);
  v5 = this->m_delayTargetIDTimer.__vftable;
  p_m_timestamp = &this->m_delayTargetIDTimer.m_timestamp;
  this->m_delayTargetIDTimer.m_timestamp.m_Value = -1.0;
  v5->NetworkStateChanged(this: &this->m_delayTargetIDTimer, a2: &this->m_delayTargetIDTimer.m_timestamp);
  this->m_holdTargetIDTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v6 = this->m_holdTargetIDTimer.__vftable;
  this->m_holdTargetIDTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v6->NetworkStateChanged)(a1: &this->m_holdTargetIDTimer.m_duration);
  v7 = this->m_holdTargetIDTimer.__vftable;
  v15 = &this->m_holdTargetIDTimer.m_timestamp;
  this->m_holdTargetIDTimer.m_timestamp.m_Value = -1.0;
  v7->NetworkStateChanged(this: &this->m_holdTargetIDTimer, a2: &this->m_holdTargetIDTimer.m_timestamp);
  this->m_SoundEvents.m_Memory.m_pMemory = nullptr;
  this->m_SoundEvents.m_Memory.m_nAllocationCount = 0;
  this->m_SoundEvents.m_Memory.m_nGrowSize = 0;
  this->m_SoundEvents.m_LastAlloc.index = -1;
  m_pMemory = this->m_SoundEvents.m_Memory.m_pMemory;
  this->m_SoundEvents.m_Head = -1;
  this->m_SoundEvents.m_Tail = -1;
  this->m_SoundEvents.m_FirstFree = -1;
  this->m_SoundEvents.m_ElementCount = 0;
  this->m_SoundEvents.m_NumAlloced = 0;
  this->m_SoundEvents.m_pElements = m_pMemory;
  this->m_StartOfRoundSoundEvents.m_SoundEvents.m_Memory.m_pMemory = nullptr;
  this->m_StartOfRoundSoundEvents.m_SoundEvents.m_Memory.m_nAllocationCount = 0;
  this->m_StartOfRoundSoundEvents.m_SoundEvents.m_Memory.m_nGrowSize = 0;
  this->m_StartOfRoundSoundEvents.m_SoundEvents.m_Size = 0;
  this->m_StartOfRoundSoundEvents.m_SoundEvents.m_pElements = nullptr;
  this->m_StartOfRoundSoundEvents.m_NextAvailableTime = 1.0;
  this->m_StartOfRoundSoundEvents.m_bPlaybackEnabled = false;
  this->m_AddonModels.m_Memory.m_pMemory = nullptr;
  this->m_AddonModels.m_Memory.m_nAllocationCount = 0;
  this->m_AddonModels.m_Memory.m_nGrowSize = 0;
  this->m_AddonModels.m_LastAlloc.index = -1;
  v9 = this->m_AddonModels.m_Memory.m_pMemory;
  this->m_AddonModels.m_Head = -1;
  this->m_AddonModels.m_Tail = -1;
  this->m_AddonModels.m_FirstFree = -1;
  this->m_AddonModels.m_ElementCount = 0;
  this->m_AddonModels.m_NumAlloced = 0;
  this->m_AddonModels.m_pElements = v9;
  this->m_PlayerAnimState = CreatePlayerAnimState(
                              pEntity: this,
                              pHelpers: &this->ICSPlayerAnimStateHelpers,
                              legAnimType: LEGANIM_9WAY,
                              bUseAimSequences: true);
  this->m_angEyeAngles.x = 0.0;
  this->m_angEyeAngles.y = 0.0;
  this->m_angEyeAngles.z = 0.0;
  C_BaseEntity::AddVar(
    this,
    data: (void *)&this->m_angEyeAngles,
    watcher: &this->m_iv_angEyeAngles,
    type: 2,
    bSetup: false);
  if ( this->m_iAddonBits.m_Value != 0 )
    this->m_iAddonBits.m_Value = 0;
  this->m_iLastAddonBits = this->m_iAddonBits.m_Value;
  this->m_iLastSecondaryAddon = 0;
  this->m_iLastPrimaryAddon = 0;
  if ( this->m_iProgressBarDuration.m_Value != 0 )
    this->m_iProgressBarDuration.m_Value = 0;
  if ( this->m_flProgressBarStartTime.m_Value != 0.0 )
    this->m_flProgressBarStartTime.m_Value = 0.0;
  this->m_ArmorValue = 0;
  this->m_bHasHelmet = false;
  this->m_iIDEntIndex = 0;
  v10 = CountdownTimer::Now(this: (CEffectsClient *)&this->m_delayTargetIDTimer)
      + this->m_delayTargetIDTimer.m_duration.m_Value;
  if ( p_m_timestamp->m_Value != v10 )
  {
    this->m_delayTargetIDTimer.NetworkStateChanged(
      this: &this->m_delayTargetIDTimer,
      a2: &this->m_delayTargetIDTimer.m_timestamp);
    v14 = v10;
    p_m_timestamp->m_Value = v14;
  }
  this->m_iOldIDEntIndex = 0;
  v11 = CountdownTimer::Now(this: (CEffectsClient *)&this->m_holdTargetIDTimer)
      + this->m_holdTargetIDTimer.m_duration.m_Value;
  if ( v15->m_Value != v11 )
  {
    this->m_holdTargetIDTimer.NetworkStateChanged(
      this: &this->m_holdTargetIDTimer,
      a2: &this->m_holdTargetIDTimer.m_timestamp);
    v13 = v11;
    v15->m_Value = v13;
  }
  if ( this->m_iDirection.m_Value != 0 )
    this->m_iDirection.m_Value = 0;
  this->m_fNextThinkPushAway = 0.0;
  this->m_Activity = ACT_IDLE;
  this->m_pFlashlightBeam = nullptr;
  this->m_serverIntendedCycle = -1.0;
  view->SetScreenOverlayMaterial(this: view, a2: nullptr);
  this->m_iTargetedWeaponEntIndex = 0;
  *(_WORD *)&this->m_bPlayingFreezeCamSound = 0;
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->CGameEventListener,
    a3: "round_freeze_end",
    a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->CGameEventListener,
    a3: "ggtr_player_levelup",
    a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->CGameEventListener,
    a3: "ggprogressive_player_levelup",
    a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->CGameEventListener,
    a3: "gg_player_impending_upgrade",
    a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "gg_killed_enemy", a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->CGameEventListener,
    a3: "gg_final_weapon_achieved",
    a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->CGameEventListener,
    a3: "gg_bonus_grenade_achieved",
    a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->CGameEventListener,
    a3: "gg_reset_round_start_sounds",
    a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "gg_leader", a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "round_start", a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "player_death", a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "player_spawn", a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->CGameEventListener,
    a3: "gg_select_item_pickup",
    a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "gg_halftime", a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->CGameEventListener,
    a3: "switch_team_to_ct",
    a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->CGameEventListener,
    a3: "switch_team_to_t",
    a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "start_vote", a4: false);
  this->m_isCurrentGunGameLeader = false;
  this->m_nextTaserShakeTime = 0.0;
  this->m_firstTaserShakeTime = 0.0;
  if ( this->m_bKilledByTaser.m_Value )
    this->m_bKilledByTaser.m_Value = false;
  this->m_currentVoteKickTarget = -1;
  this->m_currentVoteCaller = -1;
  this->m_currentVoteIssue = VoteType_None;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101BCEA0
// Name: public: virtual void C_CSPlayer::SetServerIntendedCycle(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSPlayer::SetServerIntendedCycle(C_CSPlayer *this, float intended)
{
  this->m_serverIntendedCycle = intended;
}

//------------------------------------------------------------------------------
// Address: 0x101BCEC0
// Name: public: virtual float C_CSPlayer::GetServerIntendedCycle(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_CSPlayer::GetServerIntendedCycle(C_CSPlayer *this)
{
  return this->m_serverIntendedCycle;
}

//------------------------------------------------------------------------------
// Address: 0x101BCED0
// Name: public: virtual bool C_CSPlayer::ShouldReceiveProjectedTextures(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CSPlayer::ShouldReceiveProjectedTextures(C_CSPlayer *this, int flags)
{
  return (C_CSPlayer *)((char *)this - 4) != C_BasePlayer::GetLocalPlayer(nSlot: -1);
}

//------------------------------------------------------------------------------
// Address: 0x101BCF00
// Name: private: virtual void C_CSPlayer::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSPlayer::FireGameEvent(C_CSPlayer *this, IGameEvent *event)
{
  ConVar *LocalPlayer; // ebx
  int v5; // esi
  const char *v6; // eax
  const char *v7; // eax
  int v8; // esi
  bool v9; // zf
  int (__thiscall *GetInt)(IGameEvent *, const char *, int); // eax
  int v11; // ebx
  CCenterPrint *CenterPrint; // eax
  int v13; // esi
  int v14; // esi
  int v15; // esi
  int v16; // esi
  int UserID; // ebx
  CCenterPrint *v18; // eax
  int v19; // eax
  C_BasePlayer *v20; // esi
  IVEngineClient_vtbl *v21; // ebx
  int v22; // eax
  IVEngineClient_vtbl *v23; // ebx
  int v24; // eax
  char weaponSoundName[64]; // [esp+2Ch] [ebp-50h] BYREF
  ConVarRef round_start_reset_duck; // [esp+6Ch] [ebp-10h] BYREF
  ConVarRef v27; // [esp+74h] [ebp-8h] BYREF
  const char *name; // [esp+84h] [ebp+8h]
  const char *namea; // [esp+84h] [ebp+8h]
  const char *nameb; // [esp+84h] [ebp+8h]
  const char *namec; // [esp+84h] [ebp+8h]
  const char *named; // [esp+84h] [ebp+8h]
  const char *namee; // [esp+84h] [ebp+8h]

  name = event->GetName(this: event);
  LocalPlayer = (ConVar *)C_BasePlayer::GetLocalPlayer(nSlot: -1);
  v27.m_pConVarState = LocalPlayer;
  if ( _V_strcmp(s1: name, s2: "round_freeze_end") == 0 )
  {
    if ( cl_enable_roundstart_autobuy.m_pParent != nullptr
      && cl_enable_roundstart_autobuy.m_pParent->m_Value.m_nValue != 0 )
    {
      BYTE1(this->m_nNextThinkTick) = 1;
      ConVarRef::ConVarRef(this: &v27, pName: "mp_startmoney");
      ((void (__stdcall *)(int))v27.m_pConVar->SetValue_2)(a1: (int)v27.m_pConVarState->m_fMaxVal);
    }
    else
    {
      BYTE1(this->m_nNextThinkTick) = 0;
    }
    return;
  }
  if ( _V_strcmp(s1: "gg_reset_round_start_sounds", s2: name) == 0 )
  {
    v5 = event->GetInt(this: event, a2: "userid", a3: 0);
    if ( C_BasePlayer::GetUserID(this: (C_BasePlayer *)LocalPlayer) == v5 )
    {
      *(_DWORD *)&this->m_iName[64] = 0;
      *(_DWORD *)&this->m_iName[72] = 1065353216;
      this->m_iName[76] = 0;
    }
    return;
  }
  if ( _V_strcmp(s1: "gg_select_item_pickup", s2: name) == 0 )
  {
    namea = (const char *)event->GetInt(this: event, a2: "userid", a3: 0);
    if ( (const char *)C_BasePlayer::GetUserID(this: (C_BasePlayer *)LocalPlayer) != namea )
      return;
    v6 = event->GetString(this: event, a2: "item", a3: prType);
LABEL_19:
    if ( v6 != nullptr )
    {
      V_snprintf(pDest: weaponSoundName, maxLen: 0x40u, pFormat: "GunGameWeapon.%s", v6);
      C_BaseEntity::EmitSound(
        this: (C_CSPlayer *)((char *)this - 6720),
        soundname: weaponSoundName,
        soundtime: 0,
        duration: nullptr);
    }
    return;
  }
  if ( _V_strcmp(s1: "ggtr_player_levelup", s2: name) == 0 )
  {
    nameb = (const char *)event->GetInt(this: event, a2: "userid", a3: 0);
    if ( (const char *)C_BasePlayer::GetUserID(this: (C_BasePlayer *)LocalPlayer) == nameb )
    {
      C_BaseEntity::EmitSound(
        this: (C_CSPlayer *)((char *)this - 6720),
        soundname: "GunGameWeapon.LevelUp",
        soundtime: 0,
        duration: nullptr);
      v7 = event->GetString(this: event, a2: "weaponname", a3: prType);
      if ( v7 != nullptr )
      {
        V_snprintf(pDest: weaponSoundName, maxLen: 0x40u, pFormat: "GunGameWeapon.%s", v7);
        CStartOfRoundAudioPlayback::AddSound(
          this: (CStartOfRoundAudioPlayback *)&this->m_iName[52],
          pEntityPlayingSound: (C_CSPlayer *)((char *)this - 6720),
          pName: weaponSoundName,
          fPlaybackDuration: 2.0);
      }
    }
    return;
  }
  if ( _V_strcmp(s1: "ggprogressive_player_levelup", s2: name) == 0 )
  {
    namec = (const char *)event->GetInt(this: event, a2: "userid", a3: 0);
    if ( (const char *)C_BasePlayer::GetUserID(this: (C_BasePlayer *)LocalPlayer) != namec )
      return;
    C_BaseEntity::EmitSound(
      this: (C_CSPlayer *)((char *)this - 6720),
      soundname: "GunGameWeapon.LevelUp",
      soundtime: 0,
      duration: nullptr);
    v6 = event->GetString(this: event, a2: "weaponname", a3: prType);
    goto LABEL_19;
  }
  if ( _V_strcmp(s1: "gg_player_impending_upgrade", s2: name) == 0 )
  {
    v8 = event->GetInt(this: event, a2: "userid", a3: 0);
    if ( C_BasePlayer::GetUserID(this: (C_BasePlayer *)LocalPlayer) == v8 )
      C_BaseEntity::EmitSound(
        this: (C_CSPlayer *)((char *)this - 6720),
        soundname: "GunGameWeapon.ImpendingLevelUp",
        soundtime: 0,
        duration: nullptr);
    return;
  }
  if ( _V_strcmp(s1: "gg_killed_enemy", s2: name) == 0 )
  {
    if ( C_CSGameRules::IsPlayingGunGame(this: (C_CSGameRules *)g_pGameRules) && LocalPlayer != nullptr )
    {
      named = (const char *)event->GetInt(this: event, a2: "attackerid", a3: 0);
      v9 = C_BasePlayer::GetUserID(this: (C_BasePlayer *)LocalPlayer) == (_DWORD)named;
      GetInt = event->GetInt;
      if ( v9 )
      {
        if ( ((int (__thiscall *)(IGameEvent *, const char *))GetInt)(a1: event, a2: "dominated") == 1 )
        {
          C_BaseEntity::EmitSound(
            this: (C_CSPlayer *)((char *)this - 6720),
            soundname: "GunGameWeapon.Dominating",
            soundtime: 0,
            duration: nullptr);
        }
        else if ( event->GetInt(this: event, a2: "revenge", a3: 0) == 1 )
        {
          C_BaseEntity::EmitSound(
            this: (C_CSPlayer *)((char *)this - 6720),
            soundname: "GunGameWeapon.RevengeKill",
            soundtime: 0,
            duration: nullptr);
        }
      }
      else
      {
        v11 = ((int (__thiscall *)(IGameEvent *, const char *))GetInt)(a1: event, a2: "victimid");
        if ( C_BasePlayer::GetUserID(this: (C_BasePlayer *)v27.m_pConVarState) == v11
          && event->GetInt(this: event, a2: "dominated", a3: 0) == 1 )
        {
          C_BaseEntity::EmitSound(
            this: (C_CSPlayer *)((char *)this - 6720),
            soundname: "GunGameWeapon.Nemesis",
            soundtime: 0,
            duration: nullptr);
        }
      }
    }
    return;
  }
  if ( _V_strcmp(s1: "gg_final_weapon_achieved", s2: name) == 0 )
  {
    if ( C_CSGameRules::IsPlayingGunGameProgressive(this: (C_CSGameRules *)g_pGameRules)
      || C_CSGameRules::IsPlayingGunGameTRBomb(this: (C_CSGameRules *)g_pGameRules) )
    {
      C_BaseEntity::EmitSound(
        this: (C_CSPlayer *)((char *)this - 6720),
        soundname: "GunGameWeapon.AchievedFinalWeapon",
        soundtime: 0,
        duration: nullptr);
      CenterPrint = GetCenterPrint();
      CenterPrint->Print_2(this: CenterPrint, a2: "#SFUI_Notice_Knife_Level");
    }
    return;
  }
  if ( _V_strcmp(s1: "gg_bonus_grenade_achieved", s2: name) == 0 )
  {
    if ( C_CSGameRules::IsPlayingGunGameTRBomb(this: (C_CSGameRules *)g_pGameRules) )
    {
      v13 = event->GetInt(this: event, a2: "userid", a3: 0);
      if ( C_BasePlayer::GetUserID(this: (C_BasePlayer *)LocalPlayer) == v13 )
        CStartOfRoundAudioPlayback::AddSound(
          this: (CStartOfRoundAudioPlayback *)&this->m_iName[52],
          pEntityPlayingSound: (C_CSPlayer *)((char *)this - 6720),
          pName: "GunGameWeapon.AchievedBonusGrenade",
          fPlaybackDuration: 2.0);
    }
    return;
  }
  if ( _V_strcmp(s1: "gg_halftime", s2: name) == 0 )
  {
    if ( C_CSGameRules::IsPlayingGunGameTRBomb(this: (C_CSGameRules *)g_pGameRules) )
    {
      v14 = event->GetInt(this: event, a2: "userid", a3: 0);
      if ( C_BasePlayer::GetUserID(this: (C_BasePlayer *)LocalPlayer) == v14 )
        CStartOfRoundAudioPlayback::AddSound(
          this: (CStartOfRoundAudioPlayback *)&this->m_iName[52],
          pEntityPlayingSound: (C_CSPlayer *)((char *)this - 6720),
          pName: "GunGameWeapon.Halftime",
          fPlaybackDuration: 2.0);
    }
    return;
  }
  if ( _V_strcmp(s1: "switch_team_to_ct", s2: name) == 0 )
  {
    v15 = event->GetInt(this: event, a2: "userid", a3: 0);
    if ( C_BasePlayer::GetUserID(this: (C_BasePlayer *)LocalPlayer) == v15 )
      CStartOfRoundAudioPlayback::AddSound(
        this: (CStartOfRoundAudioPlayback *)&this->m_iName[52],
        pEntityPlayingSound: (C_CSPlayer *)((char *)this - 6720),
        pName: "Player.PlayingAsCounterTerrorist",
        fPlaybackDuration: 2.0);
    return;
  }
  if ( _V_strcmp(s1: "switch_team_to_t", s2: name) == 0 )
  {
    v16 = event->GetInt(this: event, a2: "userid", a3: 0);
    if ( C_BasePlayer::GetUserID(this: (C_BasePlayer *)LocalPlayer) == v16 )
      CStartOfRoundAudioPlayback::AddSound(
        this: (CStartOfRoundAudioPlayback *)&this->m_iName[52],
        pEntityPlayingSound: (C_CSPlayer *)((char *)this - 6720),
        pName: "Player.PlayingAsTerrorist",
        fPlaybackDuration: 2.0);
    return;
  }
  if ( _V_strcmp(s1: "gg_leader", s2: name) == 0 )
  {
    if ( C_CSGameRules::IsPlayingGunGameProgressive(this: (C_CSGameRules *)g_pGameRules)
      || C_CSGameRules::IsPlayingGunGameTRBomb(this: (C_CSGameRules *)g_pGameRules) )
    {
      UserID = C_BasePlayer::GetUserID(this: (C_CSPlayer *)((char *)this - 6720));
      if ( UserID == event->GetInt(this: event, a2: "playerid", a3: 0) )
      {
        if ( BYTE2(this->m_flAnimTime) == 0 )
        {
          if ( (C_CSPlayer *)((char *)this - 6720) == C_BasePlayer::GetLocalPlayer(nSlot: -1) )
          {
            v18 = GetCenterPrint();
            v18->Print_2(this: v18, a2: "#SFUI_Notice_Gun_Game_Leader");
          }
          BYTE2(this->m_flAnimTime) = 1;
        }
      }
      else
      {
        BYTE2(this->m_flAnimTime) = 0;
      }
    }
    return;
  }
  if ( _V_strcmp(s1: "round_start", s2: name) == 0 )
  {
    BYTE2(this->m_flAnimTime) = 0;
    if ( *((_BYTE *)this - 444) != 0 && !C_BasePlayer::IsBot(this: (C_CSPlayer *)((char *)this - 6720)) )
    {
      ConVarRef::ConVarRef(this: &v27, pName: "round_start_reset_duck");
      v27.m_pConVar->SetValue_2(this: v27.m_pConVar, a2: 1);
      ConVarRef::ConVarRef(this: &round_start_reset_duck, pName: "round_start_reset_speed");
      round_start_reset_duck.m_pConVar->SetValue_2(this: round_start_reset_duck.m_pConVar, a2: 1);
    }
    CStartOfRoundAudioPlayback::PlaySounds(this: (CStartOfRoundAudioPlayback *)&this->m_iName[52]);
    return;
  }
  if ( _V_strcmp(s1: "player_death", s2: name) == 0 )
  {
    v19 = event->GetInt(this: event, a2: "userid", a3: 0);
    v20 = UTIL_PlayerByUserId(userID: v19);
    if ( ToBasePlayer(pEntity: v20) == nullptr || v20 != C_BasePlayer::GetLocalPlayer(nSlot: -1) )
      return;
    ConVarRef::ConVarRef(this: &round_start_reset_duck, pName: "round_start_reset_duck");
    round_start_reset_duck.m_pConVar->SetValue_2(this: round_start_reset_duck.m_pConVar, a2: 1);
    ConVarRef::ConVarRef(this: &v27, pName: "round_start_reset_speed");
    v27.m_pConVar->SetValue_2(this: v27.m_pConVar, a2: 1);
LABEL_73:
    this->m_vecNetworkOrigin.x = 0.0;
    CountdownTimer::Reset(this: (CountdownTimer *)&this->m_vecNetworkOrigin.y);
    this->m_hOwnerEntity.m_Index = 0;
    CountdownTimer::Reset(this: (CountdownTimer *)&this->m_hGroundEntity);
    this->m_hNetworkMoveParent.m_Index = 0;
    return;
  }
  if ( _V_strcmp(s1: "player_spawn", s2: name) == 0 )
  {
    namee = (const char *)C_BasePlayer::GetUserID(this: (C_CSPlayer *)((char *)this - 6720));
    if ( (const char *)event->GetInt(this: event, a2: "userid", a3: 0) != namee )
      return;
    goto LABEL_73;
  }
  if ( _V_strcmp(s1: "start_vote", s2: name) == 0 )
  {
    LODWORD(this->m_flOldSimulationTime) = event->GetInt(this: event, a2: "type", a3: 0);
    v21 = engine->__vftable;
    v22 = event->GetInt(this: event, a2: "playerToKick", a3: 0);
    *(_DWORD *)&this->m_nOldRenderMode = v21->GetPlayerForUserID(this: engine, a2: v22);
    v23 = engine->__vftable;
    v24 = event->GetInt(this: event, a2: "userid", a3: 0);
    this->m_VisibilityBits.m_Ints[0] = v23->GetPlayerForUserID(this: engine, a2: v24);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BD7C0
// Name: private: void C_CSPlayer::UpdateSoundEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSPlayer::UpdateSoundEvents(C_CSPlayer *this)
{
  int m_Head; // ebx
  CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *p_m_SoundEvents; // esi
  int m_Next; // ecx
  bool v4; // cf
  unsigned int SoundSourceIndex; // eax
  const char *v6; // [esp-8h] [ebp-48h]
  CLocalPlayerFilter filter; // [esp+14h] [ebp-2Ch] BYREF
  int iNext; // [esp+34h] [ebp-Ch]
  C_BaseEntity *v9; // [esp+38h] [ebp-8h]
  const char **v10; // [esp+3Ch] [ebp-4h]

  m_Head = this->m_SoundEvents.m_Head;
  v9 = this;
  if ( m_Head != -1 )
  {
    p_m_SoundEvents = (CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *)&this->m_SoundEvents;
    do
    {
      m_Next = p_m_SoundEvents->m_Memory.m_pMemory[m_Head].m_Next;
      v4 = *(float *)(gpGlobals.m_Index + 12) < *(float *)&p_m_SoundEvents->m_Memory.m_pMemory[m_Head].m_Element.labelPanel;
      v10 = (const char **)&p_m_SoundEvents->m_Memory.m_pMemory[m_Head];
      iNext = m_Next;
      if ( !v4 )
      {
        CLocalPlayerFilter::CLocalPlayerFilter(this: &filter);
        v6 = *v10;
        SoundSourceIndex = C_BaseEntity::GetSoundSourceIndex(this: v9);
        C_BaseEntity::EmitSound(
          &filter,
          iEntIndex: SoundSourceIndex,
          soundname: v6,
          pOrigin: nullptr,
          soundtime: 0.0,
          duration: nullptr);
        CUtlLinkedList<C_CSPlayer::CCSSoundEvent,int,0,int,CUtlMemory<UtlLinkedListElem_t<C_CSPlayer::CCSSoundEvent,int>,int>>::Unlink(
          this: p_m_SoundEvents,
          elem: m_Head);
        p_m_SoundEvents->m_Memory.m_pMemory[m_Head].m_Next = p_m_SoundEvents->m_FirstFree;
        p_m_SoundEvents->m_FirstFree = m_Head;
        C_RecipientFilter::~C_RecipientFilter(this: &filter);
        m_Next = iNext;
      }
      m_Head = m_Next;
    }
    while ( m_Next != -1 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BD9A0
// Name: private: void C_CSPlayer::CreateAddonModel(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSPlayer::CreateAddonModel(C_CSPlayer *this, int i)
{
  CAddonInfo *v3; // edi
  C_BreakableProp *v4; // eax
  C_BreakableProp *v5; // esi
  int v6; // eax
  const char *m_pModelName; // ecx
  FileWeaponInfo_t *FileWeaponInfoFromHandle; // eax
  CCSWeaponInfo *WeaponInfo; // eax
  C_BreakableProp_vtbl *v10; // edx
  CSWeaponID m_Value; // eax
  UtlLinkedListElem_t<CAddonModel,int> *v12; // edi
  unsigned int m_Index; // ecx
  int v14; // eax
  float flMinDist; // [esp+Ch] [ebp-28h]
  float flMaxDist; // [esp+10h] [ebp-24h]
  unsigned __int8 flMaxDista; // [esp+10h] [ebp-24h]
  Vector origin; // [esp+20h] [ebp-14h] BYREF
  int iAttachment; // [esp+2Ch] [ebp-8h]
  CDetailModel *hWpnInfo; // [esp+30h] [ebp-4h]

  v3 = &g_AddonInfo[i];
  iAttachment = this->LookupAttachment(this: &this->IClientRenderable, a2: v3->m_pAttachmentName);
  if ( iAttachment <= 0 )
    return;
  v4 = (C_BreakableProp *)C_BaseEntity::operator new(stAllocateBlock: 0xCD0u);
  if ( v4 != nullptr )
    v5 = C_BreakableProp::C_BreakableProp(this: v4);
  else
    v5 = nullptr;
  v6 = 1 << i;
  if ( 1 << i == 128 )
  {
    m_Value = this->m_iSecondaryAddon.m_Value;
LABEL_19:
    WeaponInfo = GetWeaponInfo(weaponID: m_Value);
    if ( WeaponInfo == nullptr )
    {
      _Warning(a1: "C_CSPlayer::CreateAddonModel: Unable to get weapon info.\n");
      v5->Release(this: &v5->IClientNetworkable);
      return;
    }
    goto LABEL_14;
  }
  if ( v6 == 64 )
  {
    m_Value = this->m_iPrimaryAddon.m_Value;
    goto LABEL_19;
  }
  m_pModelName = v3->m_pModelName;
  if ( m_pModelName == nullptr )
  {
    hWpnInfo = (CDetailModel *)(unsigned __int16)LookupWeaponInfoSlot(name: v3->m_pWeaponClassName);
    if ( (_WORD)hWpnInfo == (unsigned __int16)CDefaultClientRenderable::GetShadowHandle(this: hWpnInfo) )
      return;
    FileWeaponInfoFromHandle = GetFileWeaponInfoFromHandle(handle: (unsigned __int16)hWpnInfo);
    WeaponInfo = (CCSWeaponInfo *)__RTDynamicCast(
                                    inptr: FileWeaponInfoFromHandle,
                                    VfDelta: 0,
                                    SrcType: &FileWeaponInfo_t `RTTI Type Descriptor',
                                    TargetType: &CCSWeaponInfo `RTTI Type Descriptor',
                                    isReference: 0);
    if ( WeaponInfo == nullptr )
    {
      v5->Release(this: &v5->IClientNetworkable);
      _Warning(a1: "C_CSPlayer::CreateAddonModel: Unable to get weapon info for %s.\n", v3->m_pWeaponClassName);
      return;
    }
LABEL_14:
    v10 = v5->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
    if ( WeaponInfo->m_szAddonModel[0] != 0 )
      v10->InitializeAsClientEntity(this: v5, a2: WeaponInfo->m_szAddonModel, a3: false);
    else
      v10->InitializeAsClientEntity(this: v5, a2: WeaponInfo->szWorldModel, a3: false);
    goto LABEL_22;
  }
  if ( v6 == 256 && SLOBYTE(this->m_iAddonBits.m_Value) >= 0 )
    v5->InitializeAsClientEntity(this: v5, a2: v3->m_pHolsterName, a3: false);
  else
    v5->InitializeAsClientEntity(this: v5, a2: m_pModelName, a3: false);
LABEL_22:
  if ( _V_strcmp(s1: v3->m_pAttachmentName, s2: "c4") != 0 )
  {
    flMaxDist = C_BaseEntity::GetMaxFadeDist(this: v5);
    flMinDist = C_BaseEntity::GetMinFadeDist(this: v5);
    C_BaseEntity::SetDistanceFade(this: v5, flMinDist, flMaxDist);
  }
  v12 = &this->m_AddonModels.m_Memory.m_pMemory[CUtlLinkedList<CAddonModel,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAddonModel,int>,int>>::AddToTail(this: &this->m_AddonModels)];
  m_Index = v5->GetRefEHandle(this: v5)->m_Index;
  v14 = iAttachment;
  flMaxDista = iAttachment;
  v12->m_Element.m_hEnt.m_Index = m_Index;
  v12->m_Element.m_iAddon = i;
  v12->m_Element.m_iAttachmentPoint = v14;
  C_BaseEntity::SetParent(this: v5, pParentEntity: this, iParentAttachment: flMaxDista);
  memset((void *)&origin, 0, sizeof(origin));
  C_BaseEntity::SetLocalOrigin(this: v5, &origin);
  memset((void *)&origin, 0, sizeof(origin));
  C_BaseEntity::SetLocalAngles(this: v5, angles: (const QAngle *)&origin);
  if ( C_BasePlayer::IsLocalPlayer(pEntity: this) )
  {
    CCollisionProperty::SetSolid(this: &v5->m_Collision, val: SOLID_NONE);
    v5->m_iEFlags &= ~0x40000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BDC00
// Name: private: void C_CSPlayer::UpdateAddonModels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSPlayer::UpdateAddonModels(C_CSPlayer *this)
{
  int m_Value; // ebx
  C_BasePlayer *LocalPlayer; // esi
  int m_iLastAddonBits; // esi
  int v5; // eax
  int v6; // ecx
  int m_Head; // ebx
  UtlLinkedListElem_t<CAddonModel,int> *m_pMemory; // edx
  unsigned int v9; // esi
  int v10; // eax
  int v11; // eax
  int v12; // eax
  bool v13; // zf
  CEntInfo *v14; // eax
  IHandleEntity *m_pEntity; // eax
  UtlLinkedListElem_t<CAddonModel,int> *v16; // eax
  int m_Previous; // ecx
  int m_Next; // ecx
  int v19; // eax
  int v20; // edx
  UtlLinkedListElem_t<CAddonModel,int> *v21; // esi
  int v22; // eax
  int m_iAddon; // ecx
  int v24; // esi
  int v25; // ebx
  int iNext; // [esp+Ch] [ebp-14h]
  unsigned int m_Index; // [esp+10h] [ebp-10h]
  int i; // [esp+14h] [ebp-Ch]
  int ia; // [esp+14h] [ebp-Ch]
  int iCurAddonBits; // [esp+18h] [ebp-8h]
  bool rebuildPistol2Addon; // [esp+1Fh] [ebp-1h]

  m_Value = this->m_iAddonBits.m_Value;
  iCurAddonBits = m_Value;
  if ( C_BasePlayer::IsLocalPlayer(pEntity: this) && !C_BasePlayer::ShouldDrawLocalPlayer(this) )
  {
    iCurAddonBits = 0;
    m_Value = 0;
  }
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr
    && LocalPlayer->GetObserverMode(this: LocalPlayer) == 4
    && LocalPlayer->GetObserverTarget(this: LocalPlayer) == this )
  {
    iCurAddonBits = 0;
    m_Value = 0;
  }
  m_iLastAddonBits = this->m_iLastAddonBits;
  if ( m_iLastAddonBits != m_Value
    || this->m_iLastPrimaryAddon != this->m_iPrimaryAddon.m_Value
    || this->m_iLastSecondaryAddon != this->m_iSecondaryAddon.m_Value )
  {
    v5 = this->m_iSecondaryAddon.m_Value;
    rebuildPistol2Addon = false;
    if ( v5 == 2 )
      rebuildPistol2Addon = ((m_Value ^ m_iLastAddonBits) & 0x80u) != 0;
    v6 = this->m_iPrimaryAddon.m_Value;
    this->m_iLastAddonBits = m_Value;
    m_Head = this->m_AddonModels.m_Head;
    this->m_iLastPrimaryAddon = v6;
    this->m_iLastSecondaryAddon = v5;
    i = m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        m_pMemory = this->m_AddonModels.m_Memory.m_pMemory;
        v9 = m_Head;
        iNext = m_pMemory[m_Head].m_Next;
        v10 = 1 << m_pMemory[m_Head].m_Element.m_iAddon;
        if ( (v10 & iCurAddonBits) == 0 || rebuildPistol2Addon && v10 == 256 )
        {
          m_Index = m_pMemory[m_Head].m_Element.m_hEnt.m_Index;
          if ( m_Index != -1 )
          {
            v11 = (unsigned __int16)m_pMemory[m_Head].m_Element.m_hEnt.m_Index;
            if ( g_pEntityList->m_EntPtrArray[v11].m_SerialNumber == HIWORD(m_Index)
              && g_pEntityList->m_EntPtrArray[v11].m_pEntity != nullptr )
            {
              v12 = v11;
              v13 = g_pEntityList->m_EntPtrArray[v12].m_SerialNumber == HIWORD(m_Index);
              v14 = &g_pEntityList->m_EntPtrArray[v12];
              if ( v13 )
                m_pEntity = v14->m_pEntity;
              else
                m_pEntity = nullptr;
              ((void (__thiscall *)(IHandleEntity *))m_pEntity[2].SetRefEHandle)(a1: &m_pEntity[2]);
            }
          }
          if ( m_Head >= 0
            && m_Head < this->m_AddonModels.m_Memory.m_nAllocationCount
            && m_Head <= this->m_AddonModels.m_LastAlloc.index )
          {
            v16 = this->m_AddonModels.m_Memory.m_pMemory;
            if ( v16[v9].m_Previous != m_Head )
            {
              m_Previous = v16[v9].m_Previous;
              if ( m_Previous == -1 )
                this->m_AddonModels.m_Head = v16[v9].m_Next;
              else
                v16[m_Previous].m_Next = v16[v9].m_Next;
              m_Next = v16[v9].m_Next;
              if ( m_Next == -1 )
              {
                this->m_AddonModels.m_Tail = v16[v9].m_Previous;
              }
              else
              {
                this->m_AddonModels.m_Memory.m_pMemory[m_Next].m_Previous = v16[v9].m_Previous;
                m_Head = i;
              }
              v16[v9].m_Next = m_Head;
              v16[v9].m_Previous = m_Head;
              --this->m_AddonModels.m_ElementCount;
            }
          }
          this->m_AddonModels.m_Memory.m_pMemory[v9].m_Next = this->m_AddonModels.m_FirstFree;
          this->m_AddonModels.m_FirstFree = m_Head;
        }
        m_Head = iNext;
        i = iNext;
      }
      while ( iNext != -1 );
    }
    v19 = this->m_AddonModels.m_Head;
    v20 = 0;
    ia = 0;
    if ( v19 != -1 )
    {
      v21 = this->m_AddonModels.m_Memory.m_pMemory;
      do
      {
        v22 = v19;
        m_iAddon = v21[v22].m_Element.m_iAddon;
        v19 = v21[v22].m_Next;
        v20 |= 1 << m_iAddon;
      }
      while ( v19 != -1 );
      ia = v20;
    }
    v24 = 0;
    v25 = 1;
    do
    {
      if ( (v25 & iCurAddonBits) != 0 && (v25 & v20) == 0 )
      {
        C_CSPlayer::CreateAddonModel(this, i: v24);
        v20 = ia;
      }
      ++v24;
      v25 = __ROL4__(v25, 1);
    }
    while ( v24 < 10 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BDE80
// Name: public: virtual void C_CSPlayer::NotifyShouldTransmit(enum ShouldTransmitState_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSPlayer::NotifyShouldTransmit(C_CSPlayer *this, ShouldTransmitState_t state)
{
  float m_Value; // eax

  if ( state == SHOULDTRANSMIT_END )
  {
    if ( this->m_iThrowGrenadeCounter.m_Value != 0 )
      this->m_iThrowGrenadeCounter.m_Value = 0;
    C_CSPlayer::UpdateAddonModels(this: (C_CSPlayer *)((char *)this - 8));
    if ( LODWORD(this->m_holdTargetIDTimer.m_duration.m_Value) != 0 )
    {
      m_Value = this->m_holdTargetIDTimer.m_duration.m_Value;
      if ( m_Value != 0.0 )
      {
        *(_DWORD *)(LODWORD(m_Value) + 52) = 0;
        *(float *)(LODWORD(this->m_holdTargetIDTimer.m_duration.m_Value) + 200) = *(float *)(gpGlobals.m_Index + 12)
                                                                                - 1.0;
        this->m_holdTargetIDTimer.m_duration.m_Value = 0.0;
      }
    }
  }
  C_BaseAnimating::NotifyShouldTransmit(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x101BDF00
// Name: public: virtual void C_CSPlayer::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSPlayer::ClientThink(C_CSPlayer *this)
{
  float *v2; // edi
  unsigned int SoundSourceIndex; // eax
  C_BaseEntity *v4; // ecx
  EmitSound_t ep; // [esp+8h] [ebp-68h] BYREF
  CLocalPlayerFilter filter; // [esp+50h] [ebp-20h] BYREF
  int savedregs; // [esp+70h] [ebp+0h] BYREF

  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  v2 = (float *)((char *)this - 12);
  C_CSPlayer::UpdateSoundEvents(this: (C_CSPlayer *)((char *)this - 12));
  C_CSPlayer::UpdateAddonModels(this: (C_CSPlayer *)((char *)this - 12));
  C_CSPlayer::UpdateIDTarget(this: (C_CSPlayer *)((char *)this - 12));
  C_CSPlayer::UpdateTargetedWeapon(this: (C_CSPlayer *)((char *)this - 12));
  if ( *(float *)(gpGlobals.m_Index + 12) >= this->m_angEyeAngles.y )
  {
    PerformObstaclePushaway(
      a1: COERCE_FLOAT(&savedregs),
      a2: v2,
      a3: (int)this,
      pPushingEntity: (C_CSPlayer *)((char *)this - 12));
    this->m_angEyeAngles.y = *(float *)(gpGlobals.m_Index + 12) + 0.050000001;
  }
  if ( LODWORD(this->m_flConstraintWidth) == 2 )
  {
    if ( (_S10_3 & 1) == 0 )
    {
      _S10_3 |= 1u;
      ConVarRef::ConVarRef(this: &sv_disablefreezecam_1, pName: "sv_disablefreezecam");
    }
    if ( LOBYTE(this->m_angEyeAngles.z) == 0
      && (cl_disablefreezecam.m_pParent == nullptr || cl_disablefreezecam.m_pParent->m_Value.m_nValue == 0)
      && sv_disablefreezecam_1.m_pConVarState->m_Value.m_nValue == 0 )
    {
      LOBYTE(this->m_angEyeAngles.z) = 1;
      CLocalPlayerFilter::CLocalPlayerFilter(this: &filter);
      EmitSound_t::EmitSound_t(this: &ep);
      ep.m_nChannel = 2;
      ep.m_pSoundName = "UI/freeze_cam.wav";
      ep.m_flVolume = 1.0;
      ep.m_SoundLevel = SNDLVL_NORM;
      ep.m_bEmitCloseCaption = false;
      SoundSourceIndex = C_BaseEntity::GetSoundSourceIndex(this: (C_CSPlayer *)((char *)this - 12));
      C_BaseEntity::EmitSound(&filter, iEntIndex: SoundSourceIndex, params: &ep);
      CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
      C_RecipientFilter::~C_RecipientFilter(this: &filter);
    }
  }
  else
  {
    LOBYTE(this->m_angEyeAngles.z) = 0;
  }
  if ( C_CSGameRules::IsPlayingGunGameProgressive(this: (C_CSGameRules *)g_pGameRules)
    || C_CSGameRules::IsPlayingGunGameTRBomb(this: (C_CSGameRules *)g_pGameRules) )
  {
    v4 = (C_CSPlayer *)((char *)this - 12);
    if ( *((_BYTE *)&this->m_bResumeZoom + 1) != 0 )
    {
      C_BaseEntity::SetRenderMode(this: v4, nRenderMode: kRenderTransAlpha, bForceUpdate: false);
      C_BaseEntity::SetRenderAlpha(this: (C_CSPlayer *)((char *)this - 12), a: 128);
    }
    else
    {
      C_BaseEntity::SetRenderMode(this: v4, nRenderMode: kRenderNormal, bForceUpdate: true);
      C_BaseEntity::SetRenderAlpha(this: (C_CSPlayer *)((char *)this - 12), a: 255);
    }
  }
  if ( BYTE1(this->m_angEyeAngles.z) != 0 )
  {
    if ( (C_CSPlayer *)((char *)this - 12) == C_BasePlayer::GetLocalPlayer(nSlot: -1) )
    {
      if ( (*(int (__thiscall **)(char *, _DWORD))(*(_DWORD *)v2 + 936))(a1: (char *)this - 12, a2: 0) != 0 )
      {
        if ( this->m_iAccount < 100 )
          engine->ClientCmd_Unrestricted(this: engine, a2: "buy vesthelm");
      }
      else
      {
        engine->ClientCmd_Unrestricted(this: engine, a2: "autobuy");
      }
    }
    BYTE1(this->m_angEyeAngles.z) = 0;
  }
  CStartOfRoundAudioPlayback::Update(this: (CStartOfRoundAudioPlayback *)&this->m_SoundEvents.m_NumAlloced);
}

//------------------------------------------------------------------------------
// Address: 0x101BE0E0
// Name: public: void C_CSPlayer::PlayReloadEffect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSPlayer::PlayReloadEffect(C_CSPlayer *this)
{
  C_WeaponCSBase *v2; // eax
  const CCSWeaponInfo *CSWpnData; // eax
  IVModelInfoClient_vtbl *v4; // esi
  int v5; // eax
  const struct model_t *v6; // eax
  const studiohdr_t *v7; // eax
  const studiohdr_t *m_pStudioHdr; // ecx
  int i; // edi
  int NumSeq_Internal; // eax
  int v11; // eax
  mstudioseqdesc_t *v12; // esi
  mstudioseqdesc_t *v13; // eax
  int v14; // ebx
  int v15; // edi
  int v16; // eax
  int v17; // ecx
  float v18; // xmm0_4
  IMDLCache *v19; // [esp-4h] [ebp-DCh]
  float poseParameters[24]; // [esp+4h] [ebp-D4h] BYREF
  CStudioHdr studioHdr; // [esp+64h] [ebp-74h] BYREF
  C_CSPlayer::CCSSoundEvent event; // [esp+C8h] [ebp-10h] BYREF
  C_CSPlayer *v23; // [esp+D0h] [ebp-8h]
  float cyclesPerSecond; // [esp+D4h] [ebp-4h]

  v23 = this;
  if ( this != C_BasePlayer::GetLocalPlayer(nSlot: -1) )
  {
    v2 = (C_WeaponCSBase *)this->GetActiveWeapon(this);
    if ( v2 != nullptr )
    {
      CSWpnData = C_WeaponCSBase::GetCSWpnData(this: v2);
      v4 = modelinfo->__vftable;
      v5 = modelinfo->GetModelIndex(this: modelinfo, a2: CSWpnData->szViewModel);
      v6 = v4->GetModel(this: modelinfo, a2: v5);
      if ( v6 != nullptr )
      {
        v19 = mdlcache;
        v7 = modelinfo->GetStudiomodel(this: modelinfo, a2: v6);
        CStudioHdr::CStudioHdr(this: &studioHdr, pStudioHdr: v7, mdlcache: v19);
        m_pStudioHdr = studioHdr.m_pStudioHdr;
        if ( studioHdr.m_pStudioHdr != nullptr )
        {
          for ( i = 0; ; ++i )
          {
            if ( studioHdr.m_pVModel != nullptr )
            {
              NumSeq_Internal = CStudioHdr::GetNumSeq_Internal(this: &studioHdr);
              m_pStudioHdr = studioHdr.m_pStudioHdr;
            }
            else
            {
              NumSeq_Internal = m_pStudioHdr->numlocalseq;
            }
            if ( i >= NumSeq_Internal )
              break;
            if ( studioHdr.m_pVModel != nullptr )
            {
              v13 = CStudioHdr::pSeqdesc_Internal(this: &studioHdr, i);
              m_pStudioHdr = studioHdr.m_pStudioHdr;
              v12 = v13;
            }
            else
            {
              v11 = i;
              if ( i < 0 || i >= m_pStudioHdr->numlocalseq )
                v11 = 0;
              v12 = (mstudioseqdesc_t *)((char *)m_pStudioHdr + 212 * v11 + m_pStudioHdr->localseqindex);
            }
            if ( v12->activity == 192 )
            {
              memset(dst: (int)poseParameters, value: nullptr, count: sizeof(poseParameters));
              cyclesPerSecond = Studio_CPS(
                                  pStudioHdr: &studioHdr,
                                  seqdesc: v12,
                                  iSequence: i,
                                  poseParameter: poseParameters);
              v14 = 0;
              if ( v12->numevents > 0 )
              {
                v15 = 0;
                do
                {
                  v16 = (int)v12 + v15 + v12->eventindex;
                  if ( (*(_DWORD *)(v16 + 8) & 0x400) != 0 )
                    v17 = *(unsigned __int16 *)(v16 + 4);
                  else
                    v17 = *(_DWORD *)(v16 + 4);
                  if ( v17 == 5004 )
                  {
                    v18 = (float)(*(float *)v16 / cyclesPerSecond) + *(float *)(gpGlobals.m_Index + 12);
                    event.m_SoundName = (const char *)(v16 + 12);
                    event.m_flEventTime = v18;
                    CUtlLinkedList<C_CSPlayer::CCSSoundEvent,int,0,int,CUtlMemory<UtlLinkedListElem_t<C_CSPlayer::CCSSoundEvent,int>,int>>::AddToTail(
                      this: &v23->m_SoundEvents,
                      src: &event);
                  }
                  ++v14;
                  v15 += 80;
                }
                while ( v14 < v12->numevents );
              }
              break;
            }
          }
          CStudioHdr::Term(this: &studioHdr);
          CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_boneParent);
          CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_boneFlags);
          CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_pStudioHdrCache);
        }
        else
        {
          CStudioHdr::Term(this: &studioHdr);
          CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_boneParent);
          CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_boneFlags);
          CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&studioHdr.m_pStudioHdrCache);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BE2C0
// Name: void __MsgFunc_ReloadEffect(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __MsgFunc_ReloadEffect(bf_read *msg)
{
  int m_nBitsAvail; // ecx
  unsigned int v2; // edx
  __int16 v3; // si
  int v4; // ecx
  const unsigned int *v5; // ecx
  const unsigned int *v6; // edx
  unsigned int v7; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v10; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v12; // esi
  unsigned int v13; // ebx
  C_BaseEntity *v14; // eax
  C_CSPlayer *v15; // eax

  m_nBitsAvail = msg->m_nBitsAvail;
  if ( m_nBitsAvail < 16 )
  {
    m_pBufferEnd = msg->m_pBufferEnd;
    m_nInBufWord = msg->m_nInBufWord;
    v10 = 16 - m_nBitsAvail;
    m_pDataIn = msg->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_15;
      }
      msg->m_nInBufWord = *m_pDataIn;
    }
    msg->m_pDataIn = m_pDataIn + 1;
LABEL_15:
    if ( msg->m_bOverflow )
    {
      v3 = 0;
    }
    else
    {
      v12 = msg->m_nInBufWord;
      v13 = (v12 & CBitBuffer::s_nMaskTable[v10]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v10;
      msg->m_nInBufWord = v12 >> v10;
      v3 = v13 | m_nInBufWord;
    }
    goto LABEL_18;
  }
  v2 = msg->m_nInBufWord;
  v3 = v2;
  v4 = m_nBitsAvail - 16;
  msg->m_nBitsAvail = v4;
  if ( v4 != 0 )
  {
    msg->m_nInBufWord = HIWORD(v2);
  }
  else
  {
    v5 = msg->m_pDataIn;
    v6 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v5 == v6 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v5 + 1;
    }
    else if ( v5 <= v6 )
    {
      v7 = *v5;
      msg->m_pDataIn = v5 + 1;
      msg->m_nInBufWord = v7;
    }
    else
    {
      msg->m_bOverflow = true;
      msg->m_nInBufWord = 0;
    }
  }
LABEL_18:
  v14 = C_BaseEntity::Instance(iEnt: v3);
  v15 = (C_CSPlayer *)__RTDynamicCast(
                        inptr: v14,
                        VfDelta: 0,
                        SrcType: &C_BaseEntity `RTTI Type Descriptor',
                        TargetType: &C_CSPlayer `RTTI Type Descriptor',
                        isReference: 0);
  if ( v15 != nullptr )
    C_CSPlayer::PlayReloadEffect(this: v15);
}

//------------------------------------------------------------------------------
// Address: 0x101BE3E0
// Name: public: virtual C_CSPlayer::~C_CSPlayer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSPlayer::~C_CSPlayer(C_CSPlayer *this)
{
  IMDLCache *v2; // edi
  Beam_t *m_pFlashlightBeam; // eax
  RoundStartSoundPlaybackData *m_pMemory; // eax
  CInterpolatedVarEntryBase<QAngle,0> *m_pElements; // eax
  C_BaseParticleEntity **v6; // eax

  this->C_BasePlayer::C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_CSPlayer_vtbl *)&C_CSPlayer::`vftable'{for `IClientUnknown'};
  this->C_BasePlayer::C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_CSPlayer::`vftable'{for `IClientRenderable'};
  this->C_BasePlayer::C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_CSPlayer::`vftable'{for `IClientNetworkable'};
  this->C_BasePlayer::C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_CSPlayer::`vftable'{for `IClientThinkable'};
  this->C_BasePlayer::C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_CSPlayer::`vftable'{for `C_BasePlayer'};
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&C_CSPlayer::`vftable'{for `CGameEventListener'};
  this->ICSPlayerAnimStateHelpers::__vftable = (ICSPlayerAnimStateHelpers_vtbl *)&C_CSPlayer::`vftable'{for `ICSPlayerAnimStateHelpers'};
  v2 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  if ( this->m_iAddonBits.m_Value != 0 )
    this->m_iAddonBits.m_Value = 0;
  C_CSPlayer::UpdateAddonModels(this);
  m_pFlashlightBeam = this->m_pFlashlightBeam;
  if ( m_pFlashlightBeam != nullptr )
  {
    m_pFlashlightBeam->flags = 0;
    this->m_pFlashlightBeam->die = *(float *)(gpGlobals.m_Index + 12) - 1.0;
    this->m_pFlashlightBeam = nullptr;
  }
  (**(void (__thiscall ***)(_BYTE *))&this->m_PlayerAnimState->gap4[*(_DWORD *)(*(_DWORD *)this->m_PlayerAnimState->gap4
                                                                              + 4)])(a1: &this->m_PlayerAnimState->gap4[*(_DWORD *)(*(_DWORD *)this->m_PlayerAnimState->gap4 + 4)]);
  v2->EndLock(this: v2);
  CUtlLinkedList<CAddonModel,int,0,int,CUtlMemory<UtlLinkedListElem_t<CAddonModel,int>,int>>::RemoveAll(this: &this->m_AddonModels);
  if ( this->m_AddonModels.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_AddonModels.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_AddonModels.m_Memory.m_pMemory);
      this->m_AddonModels.m_Memory.m_pMemory = nullptr;
    }
    this->m_AddonModels.m_Memory.m_nAllocationCount = 0;
  }
  this->m_StartOfRoundSoundEvents.m_SoundEvents.m_Size = 0;
  if ( this->m_StartOfRoundSoundEvents.m_SoundEvents.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_StartOfRoundSoundEvents.m_SoundEvents.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_StartOfRoundSoundEvents.m_SoundEvents.m_Memory.m_pMemory);
      this->m_StartOfRoundSoundEvents.m_SoundEvents.m_Memory.m_pMemory = nullptr;
    }
    this->m_StartOfRoundSoundEvents.m_SoundEvents.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_StartOfRoundSoundEvents.m_SoundEvents.m_Memory.m_pMemory;
  this->m_StartOfRoundSoundEvents.m_SoundEvents.m_pElements = m_pMemory;
  if ( this->m_StartOfRoundSoundEvents.m_SoundEvents.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_StartOfRoundSoundEvents.m_SoundEvents.m_Memory.m_pMemory = nullptr;
    }
    this->m_StartOfRoundSoundEvents.m_SoundEvents.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<C_CSPlayer::CCSSoundEvent,int,0,int,CUtlMemory<UtlLinkedListElem_t<C_CSPlayer::CCSSoundEvent,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *)&this->m_SoundEvents);
  if ( this->m_SoundEvents.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SoundEvents.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SoundEvents.m_Memory.m_pMemory);
      this->m_SoundEvents.m_Memory.m_pMemory = nullptr;
    }
    this->m_SoundEvents.m_Memory.m_nAllocationCount = 0;
  }
  this->m_iv_angEyeAngles.__vftable = (CInterpolatedVar<QAngle>_vtbl *)&CInterpolatedVarArrayBase<QAngle,0>::`vftable';
  *(_DWORD *)&this->m_iv_angEyeAngles.m_VarHistory.m_firstElement = 0;
  C_BaseEntity::operator delete(pMem: this->m_iv_angEyeAngles.m_bLooping);
  C_BaseEntity::operator delete(pMem: (void *)this->m_iv_angEyeAngles.m_LastNetworkedValue);
  m_pElements = this->m_iv_angEyeAngles.m_VarHistory.m_pElements;
  if ( m_pElements != nullptr )
    C_BaseEntity::operator delete(pMem: &m_pElements[-1].value.z);
  this->m_iv_angEyeAngles.m_VarHistory.m_pElements = nullptr;
  this->m_iv_angEyeAngles.__vftable = (CInterpolatedVar<QAngle>_vtbl *)&IInterpolatedVar::`vftable';
  this->m_SmokeGrenades.m_Size = 0;
  if ( this->m_SmokeGrenades.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SmokeGrenades.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SmokeGrenades.m_Memory.m_pMemory);
      this->m_SmokeGrenades.m_Memory.m_pMemory = nullptr;
    }
    this->m_SmokeGrenades.m_Memory.m_nAllocationCount = 0;
  }
  v6 = this->m_SmokeGrenades.m_Memory.m_pMemory;
  this->m_SmokeGrenades.m_pElements = v6;
  if ( this->m_SmokeGrenades.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v6 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
      this->m_SmokeGrenades.m_Memory.m_pMemory = nullptr;
    }
    this->m_SmokeGrenades.m_Memory.m_nAllocationCount = 0;
  }
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  this->m_nDebugID = 13;
  if ( this->m_bRegisteredForEvents )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->CGameEventListener);
    this->m_bRegisteredForEvents = false;
  }
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&IGameEventListener2::`vftable';
  C_BasePlayer::~C_BasePlayer(this);
}

//------------------------------------------------------------------------------
// Address: 0x10421FF0
// Name: DT_TEPlayerAnimEvent::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEPlayerAnimEvent::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEPlayerAnimEvent::g_RecvTable);
  return atexit(func: DT_TEPlayerAnimEvent::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10422010
// Name: DT_TEPlayerAnimEvent::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEPlayerAnimEvent::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEPlayerAnimEvent::ignored>();
  DT_TEPlayerAnimEvent::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10422020
// Name: C_CSPlayer_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_CSPlayer_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_CSPlayer::m_PredMap.dataNumFields = 6;
  C_CSPlayer::m_PredMap.dataDesc = (typedescription_t *)&unk_105AE9EC;
}

//------------------------------------------------------------------------------
// Address: 0x10422060
// Name: DT_CSRagdoll::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_CSRagdoll::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_CSRagdoll::g_RecvTable);
  return atexit(func: DT_CSRagdoll::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10422080
// Name: DT_CSRagdoll::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_CSRagdoll::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_CSRagdoll::ignored>();
  DT_CSRagdoll::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10422140
// Name: DT_CSLocalPlayerExclusive::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_CSLocalPlayerExclusive::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_CSLocalPlayerExclusive::g_RecvTable);
  return atexit(func: DT_CSLocalPlayerExclusive::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10422160
// Name: DT_CSLocalPlayerExclusive::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_CSLocalPlayerExclusive::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_CSLocalPlayerExclusive::ignored>();
  DT_CSLocalPlayerExclusive::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10422170
// Name: DT_CSNonLocalPlayerExclusive::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_CSNonLocalPlayerExclusive::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_CSNonLocalPlayerExclusive::g_RecvTable);
  return atexit(func: DT_CSNonLocalPlayerExclusive::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10422190
// Name: DT_CSNonLocalPlayerExclusive::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_CSNonLocalPlayerExclusive::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_CSNonLocalPlayerExclusive::ignored>();
  DT_CSNonLocalPlayerExclusive::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104221C0
// Name: DT_CSPlayer::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_CSPlayer::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_CSPlayer::g_RecvTable);
  return atexit(func: DT_CSPlayer::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104221E0
// Name: DT_CSPlayer::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_CSPlayer::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_CSPlayer::ignored>();
  DT_CSPlayer::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10435220
// Name: DT_TEPlayerAnimEvent::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEPlayerAnimEvent::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEPlayerAnimEvent::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10435230
// Name: DT_CSRagdoll::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_CSRagdoll::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_CSRagdoll::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10435270
// Name: DT_CSLocalPlayerExclusive::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_CSLocalPlayerExclusive::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_CSLocalPlayerExclusive::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10435280
// Name: DT_CSNonLocalPlayerExclusive::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_CSNonLocalPlayerExclusive::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_CSNonLocalPlayerExclusive::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10435290
// Name: DT_CSPlayer::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_CSPlayer::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_CSPlayer::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x101B81A0
// Name: _C_TEPlayerAnimEvent_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEPlayerAnimEvent_CreateObject()
{
  return &_g_C_TEPlayerAnimEvent.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x101BC840
// Name: _C_CSRagdoll_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_CSRagdoll_CreateObject(int entnum, int serialNum)
{
  C_BaseAnimatingOverlay *v2; // eax
  C_BaseAnimatingOverlay *v3; // esi

  v2 = (C_BaseAnimatingOverlay *)C_BaseEntity::operator new(stAllocateBlock: 0xD48u);
  v3 = v2;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseAnimatingOverlay::C_BaseAnimatingOverlay(this: v2);
  v3->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BaseAnimatingOverlay_vtbl *)&C_CSRagdoll::`vftable'{for `IClientUnknown'};
  v3->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_CSRagdoll::`vftable'{for `IClientRenderable'};
  v3->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_CSRagdoll::`vftable'{for `IClientNetworkable'};
  v3->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_CSRagdoll::`vftable'{for `IClientThinkable'};
  v3->C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_CSRagdoll::`vftable';
  v3[1].C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BaseAnimatingOverlay_vtbl *)-1;
  LOBYTE(v3[1].m_VarMap.m_Entries.m_Memory.m_nAllocationCount) = 0;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v3->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10422040
// Name: _dynamic_initializer_for____g_C_CSRagdollClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_CSRagdollClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_CSRagdollClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_CSRagdollClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10422090
// Name: _dynamic_initializer_for__cl_random_taser_bone_y__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_random_taser_bone_y__()
{
  ConVar::ConVar(
    this: &cl_random_taser_bone_y,
    pName: "cl_random_taser_bone_y",
    pDefaultValue: "-1.0",
    flags: 0,
    pHelpString: "The Y position used for the random taser force.");
  return atexit(func: dynamic_atexit_destructor_for__cl_random_taser_bone_y__);
}

//------------------------------------------------------------------------------
// Address: 0x104220C0
// Name: _dynamic_initializer_for__cl_random_taser_force_y__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_random_taser_force_y__()
{
  ConVar::ConVar(
    this: &cl_random_taser_force_y,
    pName: "cl_random_taser_force_y",
    pDefaultValue: "-1.0",
    flags: 0,
    pHelpString: "The Y position used for the random taser force.");
  return atexit(func: dynamic_atexit_destructor_for__cl_random_taser_force_y__);
}

//------------------------------------------------------------------------------
// Address: 0x104220F0
// Name: _dynamic_initializer_for__cl_random_taser_power__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_random_taser_power__()
{
  ConVar::ConVar(
    this: &cl_random_taser_power,
    pName: "cl_random_taser_power",
    pDefaultValue: "4000.0",
    flags: 0,
    pHelpString: "Power used when applying the taser effect.");
  return atexit(func: dynamic_atexit_destructor_for__cl_random_taser_power__);
}

//------------------------------------------------------------------------------
// Address: 0x10422120
// Name: _dynamic_initializer_for__userMessageRegister_ReloadEffect__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUserMessageRegister *dynamic_initializer_for__userMessageRegister_ReloadEffect__()
{
  return CUserMessageRegister::CUserMessageRegister(
           this: &userMessageRegister_ReloadEffect,
           pMessageName: "ReloadEffect",
           pHookFn: __MsgFunc_ReloadEffect);
}

//------------------------------------------------------------------------------
// Address: 0x104221A0
// Name: _dynamic_initializer_for____g_C_CSPlayerClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_CSPlayerClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_CSPlayerClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_CSPlayerClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104221F0
// Name: _dynamic_initializer_for__joinsplitscreen_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joinsplitscreen_command__()
{
  ConCommand::ConCommand(
    this: &joinsplitscreen_command,
    pName: "joinsplitscreen",
    callback: joinsplitscreen,
    pHelpString: "join split screen",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__joinsplitscreen_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10422220
// Name: _dynamic_initializer_for__clTaserShakeFreqMin__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__clTaserShakeFreqMin__()
{
  ConVar::ConVar(
    this: &clTaserShakeFreqMin,
    pName: "clTaserShakeFreqMin",
    pDefaultValue: "0.2",
    flags: 0,
    pHelpString: "how often the shake is applied (min time)");
  return atexit(func: dynamic_atexit_destructor_for__clTaserShakeFreqMin__);
}

//------------------------------------------------------------------------------
// Address: 0x10422250
// Name: _dynamic_initializer_for__clTaserShakeFreqMax__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__clTaserShakeFreqMax__()
{
  ConVar::ConVar(
    this: &clTaserShakeFreqMax,
    pName: "clTaserShakeFreqMax",
    pDefaultValue: "0.7",
    flags: 0,
    pHelpString: "how often the shake is applied (max time)");
  return atexit(func: dynamic_atexit_destructor_for__clTaserShakeFreqMax__);
}

//------------------------------------------------------------------------------
// Address: 0x10422280
// Name: _dynamic_initializer_for__clTaserShakeTimeTotal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__clTaserShakeTimeTotal__()
{
  ConVar::ConVar(
    this: &clTaserShakeTimeTotal,
    pName: "clTaserShakeTimeTotal",
    pDefaultValue: "7.0",
    flags: 0,
    pHelpString: "time the taser shake is applied.");
  return atexit(func: dynamic_atexit_destructor_for__clTaserShakeTimeTotal__);
}

//------------------------------------------------------------------------------
// Address: 0x104222B0
// Name: _dynamic_initializer_for____g_C_CS_PlayerResourceClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_CS_PlayerResourceClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_CS_PlayerResourceClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_CS_PlayerResourceClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10435240
// Name: _dynamic_atexit_destructor_for__cl_random_taser_bone_y__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_random_taser_bone_y__()
{
  ConVar::~ConVar(this: &cl_random_taser_bone_y);
}

//------------------------------------------------------------------------------
// Address: 0x10435250
// Name: _dynamic_atexit_destructor_for__cl_random_taser_force_y__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_random_taser_force_y__()
{
  ConVar::~ConVar(this: &cl_random_taser_force_y);
}

//------------------------------------------------------------------------------
// Address: 0x10435260
// Name: _dynamic_atexit_destructor_for__cl_random_taser_power__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_random_taser_power__()
{
  ConVar::~ConVar(this: &cl_random_taser_power);
}

//------------------------------------------------------------------------------
// Address: 0x104352A0
// Name: _dynamic_atexit_destructor_for__joinsplitscreen_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joinsplitscreen_command__()
{
  ConCommand::~ConCommand(this: &joinsplitscreen_command);
}

//------------------------------------------------------------------------------
// Address: 0x104352B0
// Name: _dynamic_atexit_destructor_for__clTaserShakeFreqMin__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__clTaserShakeFreqMin__()
{
  ConVar::~ConVar(this: &clTaserShakeFreqMin);
}

//------------------------------------------------------------------------------
// Address: 0x104352C0
// Name: _dynamic_atexit_destructor_for__clTaserShakeFreqMax__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__clTaserShakeFreqMax__()
{
  ConVar::~ConVar(this: &clTaserShakeFreqMax);
}

//------------------------------------------------------------------------------
// Address: 0x104352D0
// Name: _dynamic_atexit_destructor_for__clTaserShakeTimeTotal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__clTaserShakeTimeTotal__()
{
  ConVar::~ConVar(this: &clTaserShakeTimeTotal);
}

//------------------------------------------------------------------------------
// Address: 0x104352E0
// Name: _dynamic_atexit_destructor_for____g_C_TEPlayerAnimEvent__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEPlayerAnimEvent__()
{
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEPlayerAnimEvent);
}
