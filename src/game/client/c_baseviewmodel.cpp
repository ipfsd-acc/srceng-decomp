// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_baseviewmodel.cpp
// Functions: 35
// ============================================================

#include "game\client\c_baseviewmodel.h"

//------------------------------------------------------------------------------
// Address: 0x1005F210
// Name: public: virtual bool C_BaseViewModel::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseViewModel::ShouldDraw(C_BaseViewModel *this)
{
  C_HLTVCamera *v2; // eax
  C_HLTVCamera *v3; // eax
  C_BaseEntity *PrimaryTarget; // edi
  bool result; // al

  if ( !g_bEngineIsHLTV )
    return C_BaseEntity::ShouldDraw(this);
  v2 = HLTVCamera();
  result = false;
  if ( C_HLTVCamera::GetMode(this: v2) == 4 )
  {
    v3 = HLTVCamera();
    PrimaryTarget = C_HLTVCamera::GetPrimaryTarget(this: v3);
    if ( PrimaryTarget == (C_BaseEntity *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 1) + 908))(a1: (char *)this - 4) )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005F260
// Name: public: virtual enum RenderableTranslucencyType_t C_BaseViewModel::ComputeTranslucencyType(void)
// Source: json
//------------------------------------------------------------------------------
RenderableTranslucencyType_t __thiscall C_BaseViewModel::ComputeTranslucencyType(C_BaseViewModel *this)
{
  C_BaseCombatWeapon *LocalPlayer; // esi

  LocalPlayer = (C_BaseCombatWeapon *)C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr
    && ((unsigned __int8 (__thiscall *)(C_BaseCombatWeapon *))LocalPlayer->HandleFireOnEmpty)(a1: LocalPlayer) != 0 )
  {
    return LocalPlayer->ComputeTranslucencyType(this: LocalPlayer);
  }
  LocalPlayer = this->GetOwningWeapon(this);
  if ( LocalPlayer != nullptr && LocalPlayer->IsOverridingViewmodel(this: LocalPlayer) )
    return LocalPlayer->ComputeTranslucencyType(this: LocalPlayer);
  else
    return C_BaseEntity::ComputeTranslucencyType(this);
}

//------------------------------------------------------------------------------
// Address: 0x1005F2D0
// Name: public: virtual void C_BaseViewModel::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseViewModel::PostDataUpdate(C_BaseViewModel *this, DataUpdateType_t updateType)
{
  C_BaseAnimating::PostDataUpdate(this, updateType);
  (*(void (__thiscall **)(char *, int))(*((_DWORD *)this - 2) + 408))(a1: (char *)this - 8, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1005F300
// Name: public: virtual bool C_ViewmodelAttachmentModel::InitializeAsClientEntity(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_ViewmodelAttachmentModel::InitializeAsClientEntity(
        C_ViewmodelAttachmentModel *this,
        const char *pszModelName,
        BOOL bRenderWithViewModels)
{
  char result; // al

  result = C_BaseEntity::InitializeAsClientEntity(this, pszModelName, bRenderWithViewModels);
  if ( result != 0 )
  {
    C_BaseEntity::AddEffects(this, nEffects: 1);
    C_BaseEntity::AddEffects(this, nEffects: 128);
    C_BaseEntity::AddEffects(this, nEffects: 32);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005F350
// Name: void FormatViewModelAttachment(class C_BasePlayer __near *,class Vector __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FormatViewModelAttachment(C_BasePlayer *pPlayer, Vector *vOrigin, bool bInverse)
{
  int v3; // esi
  int SplitScreenSlotForPlayer; // eax
  const CViewSetup *v5; // edi
  __m128i v6; // xmm0
  double v7; // xmm0_8
  __m128i v8; // xmm0
  double v10; // xmm0_8
  float v11; // xmm1_4
  const Vector *v12; // eax
  const Vector *v13; // eax
  const Vector *v14; // eax
  float v15; // xmm0_4
  float v16; // xmm1_4
  const Vector *v17; // eax
  const Vector *v18; // eax
  const Vector *v19; // eax
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // [esp+Ch] [ebp-28h]
  float v23; // [esp+10h] [ebp-24h]
  float v24; // [esp+14h] [ebp-20h]
  float v25; // [esp+18h] [ebp-1Ch]
  float v26; // [esp+1Ch] [ebp-18h]
  float v27; // [esp+20h] [ebp-14h]
  float vTransformeda; // [esp+24h] [ebp-10h]
  float vTransformed; // [esp+24h] [ebp-10h]
  float vTransformed_4a; // [esp+28h] [ebp-Ch]
  float vTransformed_4; // [esp+28h] [ebp-Ch]
  float vTransformed_8; // [esp+2Ch] [ebp-8h]
  float v33; // [esp+30h] [ebp-4h]
  float factorXa; // [esp+3Ch] [ebp+8h]
  float factorX; // [esp+3Ch] [ebp+8h]
  float vOrigina; // [esp+40h] [ebp+Ch]

  v3 = 0;
  if ( pPlayer != nullptr )
  {
    SplitScreenSlotForPlayer = C_BasePlayer::GetSplitScreenSlotForPlayer(pl: pPlayer);
    v3 = SplitScreenSlotForPlayer != -1 ? SplitScreenSlotForPlayer : 0;
  }
  v5 = view->GetPlayerViewSetup(this: view, a2: v3);
  v6 = (__m128i)_mm_cvtps_pd((__m128)LODWORD(v5->fov));
  *(double *)v6.m128i_i64 = *(double *)v6.m128i_i64 * 3.141592653589793 * 0.002777777777777778;
  __libm_sse2_tan(X: v6);
  *(float *)&v7 = v7;
  factorXa = *(float *)&v7;
  v8 = (__m128i)_mm_cvtps_pd((__m128)LODWORD(v5->fovViewmodel));
  *(double *)v8.m128i_i64 = *(double *)v8.m128i_i64 * 3.141592653589793 * 0.002777777777777778;
  __libm_sse2_tan(X: v8);
  v11 = v10;
  factorX = factorXa / v11;
  vTransformeda = vOrigin->x - v5->origin.x;
  vTransformed_4a = vOrigin->y - v5->origin.y;
  vTransformed_8 = vOrigin->z - v5->origin.z;
  v12 = MainViewForward(nSlot: v3);
  v33 = (float)((float)(v12->y * vTransformed_4a) + (float)(v12->x * vTransformeda)) + (float)(v12->z * vTransformed_8);
  v13 = MainViewUp(nSlot: v3);
  vOrigina = (float)((float)(v13->y * vTransformed_4a) + (float)(v13->x * vTransformeda))
           + (float)(v13->z * vTransformed_8);
  v14 = MainViewRight(nSlot: v3);
  v15 = (float)((float)(v14->y * vTransformed_4a) + (float)(v14->x * vTransformeda)) + (float)(v14->z * vTransformed_8);
  if ( bInverse )
  {
    v16 = 0.0;
    if ( factorX == 0.0 )
    {
      vTransformed = 0.0;
    }
    else
    {
      v16 = (float)(1.0 / factorX) * vOrigina;
      vTransformed = (float)(1.0 / factorX) * v15;
    }
    vTransformed_4 = v16;
  }
  else
  {
    vTransformed = v15 * factorX;
    vTransformed_4 = vOrigina * factorX;
  }
  v17 = MainViewForward(nSlot: v3);
  v22 = v33 * v17->x;
  v23 = v17->y * v33;
  v24 = v17->z * v33;
  v18 = MainViewUp(nSlot: v3);
  v25 = v18->x * vTransformed_4;
  v26 = v18->y * vTransformed_4;
  v27 = v18->z * vTransformed_4;
  v19 = MainViewRight(nSlot: v3);
  v20 = v5->origin.y + (float)((float)((float)(v19->y * vTransformed) + v26) + v23);
  v21 = v5->origin.z + (float)((float)((float)(v19->z * vTransformed) + v27) + v24);
  vOrigin->x = v5->origin.x + (float)((float)((float)(v19->x * vTransformed) + v25) + v22);
  vOrigin->y = v20;
  vOrigin->z = v21;
}

//------------------------------------------------------------------------------
// Address: 0x1005F5E0
// Name: public: virtual void C_BaseViewModel::FormatViewModelAttachment(int,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseViewModel::FormatViewModelAttachment(
        C_BaseViewModel *this,
        int nAttachment,
        matrix3x4_t *attachmentToWorld)
{
  C_BaseEntity *v3; // esi
  C_BasePlayer *v4; // eax
  Vector vecOrigin; // [esp+4h] [ebp-Ch] BYREF

  v3 = this->GetOwner(this);
  if ( v3 != nullptr && v3->IsPlayer(this: v3) )
    v4 = (C_BasePlayer *)v3;
  else
    v4 = nullptr;
  vecOrigin.x = attachmentToWorld->m_flMatVal[0][3];
  vecOrigin.y = attachmentToWorld->m_flMatVal[1][3];
  vecOrigin.z = attachmentToWorld->m_flMatVal[2][3];
  FormatViewModelAttachment(pPlayer: v4, vOrigin: &vecOrigin, bInverse: false);
  MatrixSetColumn(in: &vecOrigin, column: 3, out: attachmentToWorld);
}

//------------------------------------------------------------------------------
// Address: 0x1005F650
// Name: public: virtual void C_BaseViewModel::UncorrectViewModelAttachment(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseViewModel::UncorrectViewModelAttachment(C_BaseViewModel *this, Vector *vOrigin)
{
  C_BasePlayer *v2; // esi

  v2 = (C_BasePlayer *)this->GetOwner(this);
  if ( v2 == nullptr || !v2->IsPlayer(this: v2) )
    v2 = nullptr;
  FormatViewModelAttachment(pPlayer: v2, vOrigin, bInverse: true);
}

//------------------------------------------------------------------------------
// Address: 0x1005F690
// Name: public: virtual void C_BaseViewModel::FireEvent(class Vector const __near &,class QAngle const __near &,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseViewModel::FireEvent(
        C_BaseViewModel *this,
        const Vector *origin,
        const QAngle *angles,
        int eventNum,
        const char *options)
{
  C_BaseEntity *v6; // eax
  unsigned int SoundSourceIndex; // eax
  C_BaseEntity *v8; // eax
  C_BaseEntity *v9; // edi
  int v10; // eax
  const Vector *v11; // [esp-4h] [ebp-34h]
  CLocalPlayerFilter filter; // [esp+10h] [ebp-20h] BYREF

  if ( (eventNum == 15 || eventNum == 5004) && this->GetOwner(this) != nullptr )
  {
    CLocalPlayerFilter::CLocalPlayerFilter(this: &filter);
    v11 = this->GetAbsOrigin(this);
    v6 = this->GetOwner(this);
    SoundSourceIndex = C_BaseEntity::GetSoundSourceIndex(this: v6);
    C_BaseEntity::EmitSound(
      &filter,
      iEntIndex: SoundSourceIndex,
      soundname: options,
      pOrigin: v11,
      soundtime: 0.0,
      duration: nullptr);
    C_RecipientFilter::~C_RecipientFilter(this: &filter);
  }
  else
  {
    v8 = this->GetOwner(this);
    v9 = v8;
    if ( v8 != nullptr && v8->IsPlayer(this: v8) )
    {
      v10 = ((int (__thiscall *)(C_BaseEntity *))v9->IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].VPhysicsUpdate)(a1: v9);
      if ( v10 != 0
        && (*(unsigned __int8 (__thiscall **)(int, C_BaseViewModel *, const Vector *, const QAngle *, int, const char *))(*(_DWORD *)v10 + 1380))(
             a1: v10,
             a2: this,
             a3: origin,
             a4: angles,
             a5: eventNum,
             a6: options) == 0
        && (eventNum != 20 || input->CAM_IsThirdPerson(this: input, a2: -1) == 0) )
      {
        C_BaseAnimating::FireEvent(this, origin, angles, event: eventNum, options);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005F790
// Name: public: virtual unsigned char C_BaseViewModel::OverrideAlphaModulation(unsigned char)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall C_BaseViewModel::OverrideAlphaModulation(C_BaseViewModel *this, unsigned __int8 nAlpha)
{
  C_BasePlayer *LocalPlayer; // esi

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr && LocalPlayer->IsOverridingViewmodel(this: LocalPlayer) )
    return CClientAlphaProperty::ComputeRenderAlpha(this: LocalPlayer->m_pClientAlphaProperty);
  LocalPlayer = (C_BasePlayer *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 1) + 920))(a1: (char *)this - 4);
  if ( LocalPlayer != nullptr
    && LocalPlayer->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].GetTracerType(this: LocalPlayer) != nullptr )
  {
    return CClientAlphaProperty::ComputeRenderAlpha(this: LocalPlayer->m_pClientAlphaProperty);
  }
  else
  {
    return nAlpha;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005F800
// Name: public: void C_BaseViewModel::UpdateAnimationParity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseViewModel::UpdateAnimationParity(C_BaseViewModel *this)
{
  C_BasePlayer *v2; // edi
  float curtime; // [esp+Ch] [ebp-4h]

  v2 = (C_BasePlayer *)this->GetOwner(this);
  if ( v2 == nullptr || !v2->IsPlayer(this: v2) )
    v2 = nullptr;
  if ( this->m_nOldAnimationParity != this->m_nAnimationParity.m_Value && !C_BaseEntity::GetPredictable(this) )
  {
    if ( v2 != nullptr && C_BaseEntity::IsIntermediateDataAllocated(this) )
      curtime = C_BasePlayer::GetFinalPredictedTime(this: v2);
    else
      curtime = *(float *)(gpGlobals.m_Index + 12);
    C_BaseAnimating::SetCycle(this, flCycle: 0.0);
    this->m_flAnimTime = curtime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005F8A0
// Name: public: virtual void C_BaseViewModel::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseViewModel::OnDataChanged(C_BaseViewModel *this, DataUpdateType_t updateType)
{
  if ( updateType == DATA_UPDATE_CREATED )
    ((void (__thiscall *)(ParticleEffectList_t *, int))LODWORD(this->m_Particles.m_ParticleEffects.m_pElements->pControlPoints.m_Memory.m_pMemory->vecOriginOffset.z))(
      a1: this->m_Particles.m_ParticleEffects.m_pElements,
      a2: 1);
  C_BaseEntity::SetPredictionEligible(this: (C_BaseViewModel *)((char *)this - 8), canpredict: true);
  C_BaseAnimating::OnDataChanged(this, updateType);
}

//------------------------------------------------------------------------------
// Address: 0x1005F8E0
// Name: public: virtual class C_BasePlayer __near * C_BaseViewModel::GetPredictionOwner(void)
// Source: json
//------------------------------------------------------------------------------
C_BasePlayer *__thiscall C_BaseViewModel::GetPredictionOwner(C_BaseViewModel *this)
{
  C_BaseEntity *v1; // esi

  v1 = this->GetOwner(this);
  if ( v1 != nullptr && v1->IsPlayer(this: v1) )
    return (C_BasePlayer *)v1;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1005F910
// Name: public: virtual void C_BaseViewModel::GetBoneControllers(float __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseViewModel::GetBoneControllers(C_BaseViewModel *this, float *controllers)
{
  C_BaseEntity *v3; // edi
  int v4; // eax

  C_BaseAnimating::GetBoneControllers(this, controllers);
  v3 = this->GetOwner(this);
  if ( v3 != nullptr && v3->IsPlayer(this: v3) )
  {
    v4 = ((int (__thiscall *)(C_BaseEntity *))v3->IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].VPhysicsUpdate)(a1: v3);
    if ( v4 != 0 )
      (*(void (__thiscall **)(int, C_BaseViewModel *, float *))(*(_DWORD *)v4 + 1428))(
        a1: v4,
        a2: this,
        a3: controllers);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005F970
// Name: public: virtual bool C_BaseViewModel::Interpolate(float)
// Source: json
//------------------------------------------------------------------------------
char __userpurge C_BaseViewModel::Interpolate@<al>(C_BaseViewModel *this@<ecx>, int a2@<ebx>, float currentTime)
{
  CStudioHdr *m_pStudioHdr; // eax
  CStudioHdr *v5; // ebx
  C_BasePlayer *v6; // edi
  float v7; // xmm0_4
  double v8; // st7
  int m_nSequence; // edi
  CStudioHdr *v10; // eax
  float curtime; // [esp+14h] [ebp-8h]
  char bret; // [esp+1Bh] [ebp-1h]
  float elapsed_time; // [esp+24h] [ebp+8h]
  float elapsed_timea; // [esp+24h] [ebp+8h]

  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
    v5 = this->m_pStudioHdr;
  else
    v5 = nullptr;
  C_BaseViewModel::UpdateAnimationParity(this);
  bret = C_BaseAnimating::Interpolate(this, flCurrentTime: currentTime);
  elapsed_time = currentTime - this->m_flAnimTime;
  v6 = (C_BasePlayer *)((int (__thiscall *)(C_BaseViewModel *, int))this->GetOwner)(a1: this, a2);
  if ( v6 == nullptr || !v6->IsPlayer(this: v6) )
    v6 = nullptr;
  if ( C_BaseEntity::GetPredictable(this) || this->IsClientCreated(this) )
  {
    if ( v6 != nullptr )
    {
      curtime = C_BasePlayer::GetFinalPredictedTime(this: v6);
      v7 = curtime;
    }
    else
    {
      v7 = *(float *)(gpGlobals.m_Index + 12);
    }
    elapsed_time = v7 - this->m_flAnimTime;
    if ( !engine->IsPaused(this: engine) )
      elapsed_time = (float)(*(float *)(gpGlobals.m_Index + 32) * *(float *)(gpGlobals.m_Index + 28)) + elapsed_time;
  }
  if ( elapsed_time < 0.0 )
    elapsed_time = 0.0;
  v8 = ((double (__thiscall *)(C_BaseViewModel *, CStudioHdr *))this->GetSequenceCycleRate)(a1: this, a2: v5)
     * elapsed_time;
  elapsed_timea = v8;
  if ( v8 >= 1.0 )
  {
    m_nSequence = this->m_nSequence;
    if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
      C_BaseAnimating::LockStudioHdr(this);
    v10 = this->m_pStudioHdr;
    if ( v10 == nullptr || v10->m_pStudioHdr == nullptr )
      v10 = nullptr;
    if ( (unsigned __int8)C_BaseAnimating::IsSequenceLooping(this, pStudioHdr: v10, iSequence: m_nSequence) != 0 )
      elapsed_timea = fmod(elapsed_timea, 1.0);
    else
      elapsed_timea = 0.99900001;
  }
  C_BaseAnimating::SetCycle(this, flCycle: elapsed_timea);
  return bret;
}

//------------------------------------------------------------------------------
// Address: 0x1005FB30
// Name: public: bool C_BaseViewModel::ShouldFlipViewModel(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseViewModel::ShouldFlipViewModel(C_BaseViewModel *this)
{
  unsigned int m_Index; // ecx
  C_BaseCombatWeapon *m_pEntity; // eax
  const FileWeaponInfo_t *WpnData; // esi

  m_Index = this->m_hWeapon.m_Value.m_Index;
  if ( m_Index == -1 )
    return false;
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return false;
  m_pEntity = (C_BaseCombatWeapon *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity == nullptr )
    return false;
  WpnData = C_BaseCombatWeapon::GetWpnData(this: m_pEntity);
  if ( !WpnData->m_bAllowFlipping )
    return false;
  if ( !ConVarRef::IsValid(this: &ss_righthand) )
    SplitScreenConVarRef::Init(this: &ss_righthand, pName: "cl_righthand", bIgnoreMissing: true);
  return WpnData->m_bBuiltRightHanded != (ss_righthand.m_Info[0].m_pConVarState->m_Value.m_nValue != 0);
}

//------------------------------------------------------------------------------
// Address: 0x1005FBB0
// Name: public: virtual void C_BaseViewModel::ApplyBoneMatrixTransform(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseViewModel::ApplyBoneMatrixTransform(C_BaseViewModel *this, matrix3x4_t *transform)
{
  const CViewSetup *v2; // eax
  matrix3x4_t viewMatrix; // [esp+0h] [ebp-90h] BYREF
  matrix3x4_t viewMatrixInverse; // [esp+30h] [ebp-60h] BYREF
  matrix3x4_t temp; // [esp+60h] [ebp-30h] BYREF

  if ( C_BaseViewModel::ShouldFlipViewModel(this) )
  {
    v2 = view->GetPlayerViewSetup(this: view, a2: -1);
    AngleMatrix(angles: &v2->angles, position: &v2->origin, matrix: &viewMatrixInverse);
    MatrixInvert(in: &viewMatrixInverse, out: &viewMatrix);
    ConcatTransforms(in1: &viewMatrix, in2: transform, out: &temp);
    *(_QWORD *)&temp.m_flMatVal[1][0] ^= 0x8000000080000000uLL;
    temp.m_flMatVal[1][2] = -temp.m_flMatVal[1][2];
    temp.m_flMatVal[1][3] = -temp.m_flMatVal[1][3];
    ConcatTransforms(in1: &viewMatrixInverse, in2: &temp, out: transform);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005FC60
// Name: public: virtual bool C_BaseViewModel::ShouldSuppressForSplitScreenPlayer(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BaseViewModel::ShouldSuppressForSplitScreenPlayer(C_BaseViewModel *this, int nSlot)
{
  int m_nValue; // eax
  C_BasePlayer *LocalPlayer; // ebx
  C_BaseEntity *v6; // eax
  C_BasePlayer *v7; // esi
  int v8; // eax
  int v9; // edi

  if ( vm_draw_always.m_pParent != nullptr )
  {
    m_nValue = vm_draw_always.m_pParent->m_Value.m_nValue;
    if ( m_nValue != 0 )
      return m_nValue != 1;
  }
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot);
  v6 = this->GetOwner(this);
  v7 = (C_BasePlayer *)v6;
  if ( v6 == nullptr || !v6->IsPlayer(this: v6) )
    v7 = nullptr;
  if ( v7 == LocalPlayer )
    return false;
  v8 = (int)LocalPlayer->GetObserverTarget(this: LocalPlayer);
  v9 = v8;
  if ( v8 == 0 || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v8 + 584))(a1: v8) == 0 )
    v9 = 0;
  return v7 != (C_BasePlayer *)v9 || LocalPlayer->GetObserverMode(this: LocalPlayer) != 4;
}

//------------------------------------------------------------------------------
// Address: 0x1005FD10
// Name: public: C_ViewmodelAttachmentModel::C_ViewmodelAttachmentModel(void)
// Source: json
//------------------------------------------------------------------------------
C_ViewmodelAttachmentModel *__thiscall C_ViewmodelAttachmentModel::C_ViewmodelAttachmentModel(
        C_ViewmodelAttachmentModel *this)
{
  C_BaseAnimating::C_BaseAnimating(this);
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_ViewmodelAttachmentModel_vtbl *)&C_ViewmodelAttachmentModel::`vftable'{for `IClientUnknown'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_ViewmodelAttachmentModel::`vftable'{for `IClientRenderable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_ViewmodelAttachmentModel::`vftable'{for `IClientNetworkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_ViewmodelAttachmentModel::`vftable'{for `IClientThinkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_ViewmodelAttachmentModel::`vftable';
  this->m_hViewmodel.m_Index = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005FD50
// Name: public: void C_BaseViewModel::RemoveViewmodelAddon(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseViewModel::RemoveViewmodelAddon(C_BaseViewModel *this)
{
  unsigned int m_Index; // ecx
  C_BaseEntity *m_pEntity; // eax

  m_Index = this->m_viewmodelAddon.m_Index;
  if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity != nullptr )
      C_BaseEntity::Remove(this: m_pEntity);
  }
  this->m_iAddOnWeaponID = -1;
  this->m_iAddOnPlayerClass = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1005FDD0
// Name: public: virtual int C_BaseViewModel::DrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge C_BaseViewModel::DrawModel@<eax>(
        C_BaseViewModel *this@<ecx>,
        int a2@<edi>,
        int flags,
        const RenderableInstance_t *instance)
{
  char *v6; // ebx
  C_BaseCombatWeapon *v7; // eax
  int v8; // edi
  C_BasePlayer *LocalPlayer; // edi
  int v10; // eax
  int v11; // eax
  CStudioHdr *v12; // edi
  const char *m_Value; // eax
  CStudioHdr *ModelPtr; // eax
  int v15; // edi
  const char *SequenceName; // eax
  int v17; // edi
  const mstudioposeparamdesc_t *v18; // eax
  double PoseParameter; // st7
  int v20; // edi
  unsigned __int8 RenderAlpha; // al
  IVEngineClient_vtbl *v22; // ebx
  int v23; // eax
  int v24; // eax
  int v25; // edi
  double v26; // xmm0_8
  double v27; // [esp+40h] [ebp-3Ch]
  int v28; // [esp+50h] [ebp-2Ch]
  float color; // [esp+58h] [ebp-24h]
  float color_4; // [esp+5Ch] [ebp-20h]
  float color_8; // [esp+60h] [ebp-1Ch]
  IMDLCache *cacheCriticalSection; // [esp+64h] [ebp-18h]
  void (**p_Con_NPrintf)(IVEngineClient *, int, const char *, ...); // [esp+68h] [ebp-14h]
  char *v34; // [esp+68h] [ebp-14h]
  int m_nPrevSequence; // [esp+6Ch] [ebp-10h]
  void (**v36)(IVEngineClient *, int, const char *, ...); // [esp+6Ch] [ebp-10h]
  CMatRenderContextPtr pRenderContext; // [esp+70h] [ebp-Ch]
  int ret; // [esp+74h] [ebp-8h]
  CStudioHdr *hdr; // [esp+78h] [ebp-4h]
  CStudioHdr *hdra; // [esp+78h] [ebp-4h]
  char *i; // [esp+84h] [ebp+8h]
  int ia; // [esp+84h] [ebp+8h]
  float ib; // [esp+84h] [ebp+8h]
  float *ic; // [esp+84h] [ebp+8h]
  int id; // [esp+84h] [ebp+8h]
  const RenderableInstance_t *instancea; // [esp+88h] [ebp+Ch]

  if ( LOBYTE(this->m_VisibilityBits.m_Ints[0]) == 0 )
    return 0;
  v6 = (char *)this - 4;
  if ( (*(unsigned __int8 (__thiscall **)(char *, int, const RenderableInstance_t *))(*((_DWORD *)this - 1) + 884))(
         a1: (char *)this - 4,
         a2: flags,
         a3: instance) == 0 )
    return 0;
  if ( flags != 0
    && vm_draw_addon.m_pParent != nullptr
    && vm_draw_addon.m_pParent->m_Value.m_nValue != 0
    && CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&this->m_nOldAnimationParity) != nullptr )
  {
    v7 = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&this->m_nOldAnimationParity);
    v7->DrawModel(this: &v7->IClientRenderable, a2: flags | 0x800, a3: instance);
  }
  v8 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2);
  pRenderContext.m_pObject = (IMatRenderContext *)v8;
  if ( v8 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 8))(a1: v8);
  if ( C_BaseViewModel::ShouldFlipViewModel(this: (C_BaseViewModel *)((char *)this - 4)) )
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 160))(a1: v8, a2: 1);
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  v10 = (*(int (__thiscall **)(char *))(*(_DWORD *)v6 + 920))(a1: (char *)this - 4);
  hdr = (CStudioHdr *)v10;
  if ( LocalPlayer != nullptr )
  {
    if ( LocalPlayer->IsOverridingViewmodel(this: LocalPlayer) )
    {
      v11 = LocalPlayer->DrawOverriddenViewmodel(
              this: LocalPlayer,
              a2: (C_BaseViewModel *)((char *)this - 4),
              a3: flags,
              a4: instance);
LABEL_22:
      v12 = hdr;
      goto LABEL_23;
    }
    v10 = (int)hdr;
  }
  if ( v10 == 0 || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v10 + 1444))(a1: v10) == 0 )
  {
    v11 = C_BaseAnimating::DrawModel(this, flags, instance);
    goto LABEL_22;
  }
  v12 = hdr;
  v11 = ((int (__thiscall *)(CStudioHdr *, char *, int, const RenderableInstance_t *))hdr->m_pStudioHdr[3].numskinfamilies)(
          a1: hdr,
          a2: (char *)this - 4,
          a3: flags,
          a4: instance);
LABEL_23:
  ret = v11;
  ((void (__thiscall *)(CMatRenderContextPtr))pRenderContext.m_pObject->CullMode)(a1: pRenderContext);
  if ( (flags & 1) != 0 )
  {
    m_Value = (const char *)this->m_nViewModelIndex.m_Value;
    if ( this->m_sAnimationPrefix != m_Value )
      this->m_sAnimationPrefix = m_Value;
    if ( v12 != nullptr )
      ((void (__thiscall *)(CStudioHdr *, int, char *))v12->m_pStudioHdr[3].numbonecontrollers)(
        a1: v12,
        a2: flags,
        a3: (char *)this - 4);
    if ( vm_debug.m_pParent != nullptr && vm_debug.m_pParent->m_Value.m_nValue != 0 )
    {
      cacheCriticalSection = mdlcache;
      ((void (__stdcall *)(_DWORD, int))mdlcache->BeginLock)(a1: 0, a2: v28);
      ModelPtr = C_BaseAnimating::GetModelPtr(this: (C_BaseViewModel *)((char *)this - 4));
      hdra = ModelPtr;
      if ( ModelPtr != nullptr )
        i = CStudioHdr::name(this: ModelPtr);
      else
        i = "(null)";
      v15 = *(_DWORD *)&this->m_builtRagdoll;
      m_nPrevSequence = this->m_nPrevSequence;
      p_Con_NPrintf = &engine->Con_NPrintf;
      C_BaseAnimating::GetPlaybackRate(this: (C_BaseViewModel *)((char *)this - 4));
      v27 = ((double (__thiscall *)(char *, CStudioHdr *))*(_DWORD *)(*(_DWORD *)v6 + 800))(
              a1: (char *)this - 4,
              a2: hdra);
      SequenceName = C_BaseAnimating::GetSequenceName(this: (C_BaseViewModel *)((char *)this - 4), iSequence: v15);
      (*p_Con_NPrintf)(
        this: engine,
        a2: 16,
        a3: "%s: %s(%d), cycle: %.2f cyclerate: %.2f playbackrate: %.2f\n",
        i,
        SequenceName,
        v15,
        *(float *)&m_nPrevSequence,
        v27);
      v17 = 17;
      if ( hdra != nullptr )
      {
        for ( ia = 0; ia < CStudioHdr::GetNumPoseParameters(this: hdra); ++v17 )
        {
          v18 = CStudioHdr::pPoseParameter(this: hdra, i: ia);
          v36 = &engine->Con_NPrintf;
          v34 = (char *)v18 + v18->sznameindex;
          PoseParameter = C_BaseAnimating::GetPoseParameter(this: (C_BaseViewModel *)((char *)this - 4), iParameter: ia);
          (*v36)(this: engine, a2: v17, a3: "pose_param %s: %f", v34, PoseParameter);
          ++ia;
        }
      }
      ib = (float)instance->m_nAlpha * 0.0039215689;
      this->GetAbsAngles(this);
      engine->Con_NPrintf(this: engine, a2: v17, a3: "blend=%f, color=%f,%f,%f", ib, color, color_4, color_8);
      v20 = v17 + 1;
      engine->Con_NPrintf(this: engine, a2: v20++, a3: "GetRenderMode()=%d", (unsigned __int8)this->m_iName[259]);
      engine->Con_NPrintf(this: engine, a2: v20, a3: "m_nRenderFX=0x%8.8X", (unsigned __int8)this->m_iName[258]);
      LOBYTE(ib) = v6[108];
      ++v20;
      *(_WORD *)((char *)&ib + 1) = *(_WORD *)(v6 + 109);
      RenderAlpha = C_BaseEntity::GetRenderAlpha(this: (C_BaseViewModel *)((char *)this - 4));
      engine->Con_NPrintf(
        this: engine,
        a2: v20,
        a3: "rendercolor=%d,%d,%d,%d",
        LOBYTE(ib),
        BYTE1(ib),
        BYTE2(ib),
        RenderAlpha);
      v22 = engine->__vftable;
      ++v20;
      ic = (float *)((int (__thiscall *)(C_BaseViewModel *))this->SetRefEHandle)(a1: this);
      v23 = ((int (__thiscall *)(C_BaseViewModel *))this->SetRefEHandle)(a1: this);
      v24 = ((int (__thiscall *)(C_BaseViewModel *, _DWORD, _DWORD))this->SetRefEHandle)(
              a1: this,
              a2: COERCE_UNSIGNED_INT64(*(float *)(v23 + 8)),
              a3: HIDWORD(COERCE_UNSIGNED_INT64(*(float *)(v23 + 8))));
      v22->Con_NPrintf(this: engine, a2: v20, a3: "origin=%f, %f, %f", *ic, *(float *)(v24 + 4));
      v25 = v20 + 1;
      id = this->GetRefEHandle(this)[2].m_Index;
      instancea = (const RenderableInstance_t *)this->GetRefEHandle(this)[1].m_Index;
      v26 = *(float *)&this->GetRefEHandle(this)->m_Index;
      engine->Con_NPrintf(this: engine, a2: v25, a3: "angles=%f, %f, %f", v26, *(float *)&instancea, *(float *)&id);
      if ( (*(_DWORD *)&this->m_nWaterType & 0x20) != 0 )
        engine->Con_NPrintf(this: engine, a2: v25 + 1, a3: "EF_NODRAW");
      cacheCriticalSection->EndLock(this: cacheCriticalSection);
    }
  }
  ((void (__thiscall *)(CMatRenderContextPtr))pRenderContext.m_pObject->EndRender)(a1: pRenderContext);
  ((void (__thiscall *)(CMatRenderContextPtr))pRenderContext.m_pObject->Release)(a1: pRenderContext);
  return ret;
}

//------------------------------------------------------------------------------
// Address: 0x100602D0
// Name: public: void C_ViewmodelAttachmentModel::SetViewmodel(class C_BaseViewModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ViewmodelAttachmentModel::SetViewmodel(C_ViewmodelAttachmentModel *this, C_BaseViewModel *pVM)
{
  if ( pVM != nullptr )
    this->m_hViewmodel.m_Index = pVM->GetRefEHandle(this: pVM)->m_Index;
  else
    this->m_hViewmodel.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10060300
// Name: public: virtual int C_ViewmodelAttachmentModel::InternalDrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
const struct model_t *__userpurge C_ViewmodelAttachmentModel::InternalDrawModel@<eax>(
        C_ViewmodelAttachmentModel *this@<ecx>,
        int a2@<ebx>,
        int flags,
        const RenderableInstance_t *instance)
{
  IMatRenderContext *v5; // esi
  unsigned int m_Index; // ecx
  C_BaseViewModel *m_pEntity; // eax
  const struct model_t *v8; // edi

  v5 = materials->GetRenderContext(this: materials);
  if ( v5 != nullptr )
    v5->BeginRender(this: v5);
  m_Index = this->m_hViewmodel.m_Index;
  if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    m_pEntity = (C_BaseViewModel *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity != nullptr && C_BaseViewModel::ShouldFlipViewModel(this: m_pEntity) )
      v5->CullMode(this: v5, a2: MATERIAL_CULLMODE_CW);
  }
  v8 = C_BaseAnimating::InternalDrawModel(this, a2, flags, instance);
  v5->CullMode(this: v5, a2: MATERIAL_CULLMODE_CCW);
  v5->EndRender(this: v5);
  v5->Release(this: v5);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x100603B0
// Name: public: void C_BaseViewModel::UpdateViewmodelAddon(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseViewModel::UpdateViewmodelAddon(C_BaseViewModel *this)
{
  C_CSPlayer *v2; // ebx
  unsigned int v3; // ecx
  C_BaseEntity *m_pEntity; // eax
  C_BaseCombatWeapon *v5; // eax
  void *v6; // eax
  unsigned int m_Index; // eax
  C_BaseCombatWeapon *v8; // eax
  int v9; // eax
  C_ViewmodelAttachmentModel *v10; // eax
  C_ViewmodelAttachmentModel *v11; // esi
  const char *v12; // eax
  int v13; // eax
  const char *addonName; // [esp+Ch] [ebp-10h]
  int weaponID; // [esp+10h] [ebp-Ch]
  int playerClass; // [esp+14h] [ebp-8h]
  bool addOnParentHandleIsValid; // [esp+1Bh] [ebp-1h]

  v2 = (C_CSPlayer *)this->GetOwner(this);
  if ( v2 != nullptr && v2->IsPlayer(this: v2) )
  {
    v5 = v2->GetActiveWeapon(this: v2);
    if ( v5 != nullptr
      && (v6 = __RTDynamicCast(
                 inptr: v5,
                 VfDelta: 0,
                 SrcType: &C_BaseCombatWeapon `RTTI Type Descriptor',
                 TargetType: &C_WeaponCSBase `RTTI Type Descriptor',
                 isReference: 0)) != nullptr )
    {
      weaponID = (*(int (__thiscall **)(void *))(*(_DWORD *)v6 + 1492))(a1: v6);
      playerClass = C_CSPlayer::PlayerClass(this: v2);
      m_Index = this->m_viewmodelAddon.m_Index;
      if ( m_Index == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr
        || CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&this->m_viewmodelAddon) == nullptr
        || (v8 = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&this->m_viewmodelAddon),
            addOnParentHandleIsValid = true,
            C_BaseEntity::GetMoveParent(this: v8) == nullptr) )
      {
        addOnParentHandleIsValid = false;
      }
      if ( weaponID == 31 )
      {
        v9 = v2->GetTeamNumber(this: v2);
        C_BaseAnimating::SetBodygroup(this, iGroup: 0, iValue: v9 != 2);
      }
      if ( this->m_iAddOnPlayerClass != playerClass || !addOnParentHandleIsValid || this->m_iAddOnWeaponID != weaponID )
      {
        C_BaseViewModel::RemoveViewmodelAddon(this);
        v10 = (C_ViewmodelAttachmentModel *)C_BaseEntity::operator new(stAllocateBlock: 0xCC0u);
        if ( v10 != nullptr )
        {
          v11 = C_ViewmodelAttachmentModel::C_ViewmodelAttachmentModel(this: v10);
          if ( v11 != nullptr )
          {
            addonName = PlayerModelInfo::GetCTViewModelPath();
            v12 = v2->GetTeamNumber(this: v2) == 2 ? PlayerModelInfo::GetTViewModelPath() : addonName;
            if ( v11->InitializeAsClientEntity(this: v11, a2: v12, a3: true) )
            {
              this->m_iAddOnPlayerClass = playerClass;
              this->m_iAddOnWeaponID = weaponID;
              CHandle<C_ViewmodelAttachmentModel>::operator=(
                this: (CHandle<C_BaseEntity> *)&this->m_viewmodelAddon,
                val: v11);
              v13 = this->GetSkin(this: &this->IClientRenderable);
              C_BaseAnimating::SetSkin(this: v11, iSkin: v13);
              C_BaseEntity::SetParent(this: v11, pParentEntity: this, iParentAttachment: 0);
              C_BaseEntity::SetLocalOrigin(this: v11, origin: &vec3_origin);
              v11->UpdatePartitionListEntry(this: v11);
              CCollisionProperty::MarkPartitionHandleDirty(this: &v11->m_Collision);
              C_BaseEntity::UpdateVisibility(this: v11);
              C_ViewmodelAttachmentModel::SetViewmodel(this: v11, pVM: this);
            }
          }
        }
      }
    }
    else
    {
      C_BaseViewModel::RemoveViewmodelAddon(this);
    }
  }
  else
  {
    v3 = this->m_viewmodelAddon.m_Index;
    if ( v3 != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_SerialNumber == HIWORD(v3) )
    {
      m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_pEntity;
      if ( m_pEntity != nullptr )
        C_BaseEntity::Remove(this: m_pEntity);
    }
    this->m_iAddOnPlayerClass = -1;
    this->m_iAddOnWeaponID = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100605F0
// Name: private: virtual void C_BaseViewModel::OnNewParticleEffect(char const __near *,class CNewParticleEffect __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseViewModel::OnNewParticleEffect(
        C_BaseViewModel *this,
        const char *pszParticleName,
        CNewParticleEffect *pNewParticleEffect)
{
  unsigned int v4; // eax
  int v5; // ecx
  CNewParticleEffect *m_pObject; // eax
  CUtlReference<CSheet> *p_m_viewmodelParticleEffect; // esi
  CUtlReference<CNewParticleEffect> *m_pHead; // eax

  v4 = LOBYTE(this->m_VisibilityBits.m_Ints[0]);
  v5 = -1;
  if ( v4 < 3 )
    v5 = v4 - 1;
  CNewParticleEffect::SetDrawOnlyForSplitScreenUser(this: pNewParticleEffect, nSlot: v5);
  if ( _V_stricmp(s1: pszParticleName, s2: "weapon_molotov_fp") == 0 )
  {
    m_pObject = this->m_viewmodelParticleEffect.m_pObject;
    p_m_viewmodelParticleEffect = (CUtlReference<CSheet> *)&this->m_viewmodelParticleEffect;
    if ( m_pObject != pNewParticleEffect )
    {
      if ( m_pObject != nullptr )
      {
        CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
          this: (CUtlIntrusiveDList<CUtlReference<CSheet> > *)&m_pObject->m_References,
          which: p_m_viewmodelParticleEffect);
        p_m_viewmodelParticleEffect->m_pObject = nullptr;
      }
      p_m_viewmodelParticleEffect->m_pObject = (CSheet *)pNewParticleEffect;
      if ( pNewParticleEffect != nullptr )
      {
        p_m_viewmodelParticleEffect->m_pNext = (CUtlReference<CSheet> *)pNewParticleEffect->m_References.m_pHead;
        m_pHead = pNewParticleEffect->m_References.m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = (CUtlReference<CNewParticleEffect> *)p_m_viewmodelParticleEffect;
        p_m_viewmodelParticleEffect->m_pPrev = nullptr;
        pNewParticleEffect->m_References.m_pHead = (CUtlReference<CNewParticleEffect> *)p_m_viewmodelParticleEffect;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10060680
// Name: private: virtual void C_BaseViewModel::OnParticleEffectDeleted(class CNewParticleEffect __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseViewModel::OnParticleEffectDeleted(C_BaseViewModel *this, CNewParticleEffect *pParticleEffect)
{
  CNewParticleEffect *m_pObject; // eax
  CUtlReference<CSheet> *p_m_viewmodelParticleEffect; // esi

  CScoreboardScaleform::SetParent((vgui::TreeView *)this, itemIndex: (int)pParticleEffect);
  if ( pParticleEffect == this->m_viewmodelParticleEffect.m_pObject )
  {
    m_pObject = this->m_viewmodelParticleEffect.m_pObject;
    p_m_viewmodelParticleEffect = (CUtlReference<CSheet> *)&this->m_viewmodelParticleEffect;
    if ( m_pObject != nullptr )
    {
      CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
        this: (CUtlIntrusiveDList<CUtlReference<CSheet> > *)&m_pObject->m_References,
        which: p_m_viewmodelParticleEffect);
      p_m_viewmodelParticleEffect->m_pObject = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100606D0
// Name: private: void C_BaseViewModel::UpdateParticles(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseViewModel::UpdateParticles(C_BaseViewModel *this, int nSlot)
{
  C_CSPlayer *LocalPlayer; // eax
  C_CSPlayer *v4; // esi
  int v5; // eax
  int v6; // ebx
  bool v7; // zf
  C_BaseCombatWeapon *v8; // eax
  _BYTE *v9; // eax
  int v10; // eax
  CNewParticleEffect *m_pObject; // eax
  C_BaseCombatWeapon *pWeapon; // [esp+18h] [ebp-4h]

  LocalPlayer = CClientTools::GetLocalPlayer();
  v4 = LocalPlayer;
  if ( LocalPlayer != nullptr && !C_BasePlayer::IsPlayerDead(this: LocalPlayer) )
  {
    pWeapon = this->GetOwningWeapon(this);
    if ( pWeapon != nullptr )
    {
      v5 = (int)v4->GetActiveWeapon(this: v4);
      if ( v5 != 0 )
      {
        v6 = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 1492))(a1: v5);
        v7 = v4->GetPlayerRenderMode(this: v4, a2: nSlot) == PLAYER_RENDER_THIRDPERSON;
        if ( r_drawviewmodel.m_pParent != nullptr && r_drawviewmodel.m_pParent->m_Value.m_nValue != 0 && !v7 && v6 == 35 )
        {
          v8 = v4->GetActiveWeapon(this: v4);
          v9 = __RTDynamicCast(
                 inptr: v8,
                 VfDelta: 0,
                 SrcType: &C_BaseCombatWeapon `RTTI Type Descriptor',
                 TargetType: &C_BaseCSGrenade `RTTI Type Descriptor',
                 isReference: 0);
          if ( v9[3505] != 0 )
          {
            if ( v9[3512] == 0 )
            {
              if ( v9[3512] != 1 )
                v9[3512] = 1;
              C_BaseEntity::EmitSound(this, soundname: "Molotov.IdleLoop", soundtime: 0, duration: nullptr);
            }
            if ( pWeapon->GetBaseAnimating(this: pWeapon) != nullptr )
            {
              v10 = (int)pWeapon->GetBaseAnimating(this: pWeapon);
              if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)(v10 + 4) + 132))(a1: v10 + 4, a2: "Wick") >= 0
                && this->m_viewmodelParticleEffect.m_pObject == nullptr )
              {
                DispatchParticleEffect(
                  pszParticleName: "weapon_molotov_fp",
                  iAttachType: PATTACH_POINT_FOLLOW,
                  pEntity: this,
                  pszAttachmentName: "Wick",
                  bResetAllParticlesOnEntity: false,
                  nSplitScreenPlayerSlot: -1,
                  filter: nullptr);
              }
            }
          }
        }
        else if ( this->m_viewmodelParticleEffect.m_pObject != nullptr )
        {
          C_BaseEntity::StopSound(this, soundname: "Molotov.IdleLoop");
          CNewParticleEffect::StopEmission(
            this: this->m_viewmodelParticleEffect.m_pObject,
            bInfiniteOnly: false,
            bRemoveAllParticles: true,
            bWakeOnStop: false,
            bPlayEndCap: false);
          *((_BYTE *)this->m_viewmodelParticleEffect.m_pObject + 944) |= 2u;
          m_pObject = this->m_viewmodelParticleEffect.m_pObject;
          if ( m_pObject != nullptr )
          {
            CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
              this: (CUtlIntrusiveDList<CUtlReference<CSheet> > *)&m_pObject->m_References,
              which: (CUtlReference<CSheet> *)&this->m_viewmodelParticleEffect);
            this->m_viewmodelParticleEffect.m_pObject = nullptr;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100608A0
// Name: public: virtual bool C_BaseViewModel::Simulate(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BaseViewModel::Simulate(C_BaseViewModel *this)
{
  C_BaseViewModel::UpdateParticles(this, nSlot: 0);
  C_BaseAnimating::Simulate(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104100F0
// Name: _dynamic_initializer_for__viewmodel_offset_x__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__viewmodel_offset_x__()
{
  ConVar::ConVar(this: &viewmodel_offset_x, pName: "viewmodel_offset_x", pDefaultValue: "0.0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__viewmodel_offset_x__);
}

//------------------------------------------------------------------------------
// Address: 0x10410120
// Name: _dynamic_initializer_for__viewmodel_offset_y__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__viewmodel_offset_y__()
{
  ConVar::ConVar(this: &viewmodel_offset_y, pName: "viewmodel_offset_y", pDefaultValue: "0.0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__viewmodel_offset_y__);
}

//------------------------------------------------------------------------------
// Address: 0x10410150
// Name: _dynamic_initializer_for__viewmodel_offset_z__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__viewmodel_offset_z__()
{
  ConVar::ConVar(this: &viewmodel_offset_z, pName: "viewmodel_offset_z", pDefaultValue: "0.0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__viewmodel_offset_z__);
}

//------------------------------------------------------------------------------
// Address: 0x1042F940
// Name: _dynamic_atexit_destructor_for__viewmodel_offset_x__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__viewmodel_offset_x__()
{
  ConVar::~ConVar(this: &viewmodel_offset_x);
}

//------------------------------------------------------------------------------
// Address: 0x1042F950
// Name: _dynamic_atexit_destructor_for__viewmodel_offset_y__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__viewmodel_offset_y__()
{
  ConVar::~ConVar(this: &viewmodel_offset_y);
}

//------------------------------------------------------------------------------
// Address: 0x1042F960
// Name: _dynamic_atexit_destructor_for__viewmodel_offset_z__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__viewmodel_offset_z__()
{
  ConVar::~ConVar(this: &viewmodel_offset_z);
}

//------------------------------------------------------------------------------
// Address: 0x10410180
// Name: _dynamic_initializer_for____g_C_BaseViewModelClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_BaseViewModelClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_BaseViewModelClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_BaseViewModelClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104101A0
// Name: _dynamic_initializer_for__g_CviewmodelFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CviewmodelFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseViewModel *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "viewmodel",
             a3: "C_BaseViewModel",
             a4: 3352,
             a5: CC_BaseViewModelFactory);
  __g_C_BaseViewModelClientClass.m_pMapClassname = "viewmodel";
  return result;
}
