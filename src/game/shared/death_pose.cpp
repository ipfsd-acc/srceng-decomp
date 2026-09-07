// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/death_pose.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100C5770
// Name: void GetRagdollCurSequenceWithDeathPose(class C_BaseAnimating __near *,class matrix3x4a_t __near *,float,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetRagdollCurSequenceWithDeathPose(
        C_BaseAnimating *entity,
        matrix3x4a_t *curBones,
        float flTime,
        int activity,
        int frame)
{
  const Vector *v6; // eax
  __int64 v7; // xmm0_8
  float z; // eax
  C_BaseAnimating_vtbl *v9; // edx
  const Vector *v10; // eax
  float v11; // ecx
  int m_nSequence; // ebx
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm3_4
  float flCycle; // xmm0_4
  Vector vAdjustedOrigin; // [esp+28h] [ebp-30h] BYREF
  Vector vPrevOrigin; // [esp+34h] [ebp-24h]
  Vector vDirection; // [esp+40h] [ebp-18h] BYREF
  Vector vNewOrigin; // [esp+4Ch] [ebp-Ch] BYREF
  float flTempCycle; // [esp+60h] [ebp+8h]

  C_BaseAnimating::InvalidateBoneCache(this: entity);
  v6 = entity->GetAbsOrigin(this: entity);
  v7 = *(_QWORD *)&v6->x;
  z = v6->z;
  v9 = entity->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  *(_QWORD *)&vPrevOrigin.x = v7;
  vPrevOrigin.z = z;
  ((void (__thiscall *)(C_BaseAnimating *, _DWORD))v9->Interpolate)(a1: entity, a2: LODWORD(flTime));
  if ( activity == -1 )
  {
    ((void (__thiscall *)(IClientRenderable *, matrix3x4a_t *, int, int, _DWORD))entity->SetupBones)(
      a1: &entity->IClientRenderable,
      a2: curBones,
      a3: 256,
      a4: 524032,
      a5: LODWORD(flTime));
    C_BaseAnimating::InvalidateBoneCache(this: entity);
    ((void (__thiscall *)(IClientRenderable *, _DWORD, int, int, _DWORD))entity->SetupBones)(
      a1: &entity->IClientRenderable,
      a2: 0,
      a3: -1,
      a4: 524032,
      a5: LODWORD(flTime));
  }
  else
  {
    v10 = entity->GetAbsOrigin(this: entity);
    *(_QWORD *)&vNewOrigin.x = *(_QWORD *)&v10->x;
    v11 = v10->z;
    vDirection.x = vNewOrigin.x - vPrevOrigin.x;
    vDirection.y = vNewOrigin.y - vPrevOrigin.y;
    vNewOrigin.z = v11;
    vDirection.z = v11 - vPrevOrigin.z;
    flTempCycle = VectorNormalize(vec: &vDirection);
    m_nSequence = entity->m_nSequence;
    v13 = (float)(flTempCycle * flTempCycle) * *(float *)(gpGlobals.m_Index + 16);
    v14 = (float)(v13 * vDirection.y) + vNewOrigin.y;
    v15 = (float)(vDirection.x * v13) + vNewOrigin.x;
    v16 = (float)(vDirection.z * v13) + vNewOrigin.z;
    flCycle = entity->m_flCycle.m_Val;
    vAdjustedOrigin.x = v15;
    vAdjustedOrigin.y = v14;
    vAdjustedOrigin.z = v16;
    C_BaseEntity::SetEffects(this: entity, nEffects: 8);
    C_BaseAnimating::SetSequence(this: entity, nSequence: activity);
    C_BaseAnimating::SetCycle(this: entity, flCycle: (float)frame * 0.16666667);
    C_BaseEntity::SetAbsOrigin(this: entity, absOrigin: &vAdjustedOrigin);
    ((void (__thiscall *)(IClientRenderable *, matrix3x4a_t *, int, int, _DWORD))entity->SetupBones)(
      a1: &entity->IClientRenderable,
      a2: curBones,
      a3: 256,
      a4: 524032,
      a5: LODWORD(flTime));
    C_BaseEntity::SetAbsOrigin(this: entity, absOrigin: &vNewOrigin);
    C_BaseAnimating::InvalidateBoneCache(this: entity);
    C_BaseAnimating::SetSequence(this: entity, nSequence: m_nSequence);
    C_BaseAnimating::SetCycle(this: entity, flCycle);
    ((void (__thiscall *)(C_BaseAnimating *, _DWORD))entity->Interpolate)(
      a1: entity,
      a2: *(_DWORD *)(gpGlobals.m_Index + 12));
    ((void (__thiscall *)(IClientRenderable *, _DWORD, int, int, _DWORD))entity->SetupBones)(
      a1: &entity->IClientRenderable,
      a2: 0,
      a3: -1,
      a4: 524032,
      a5: *(_DWORD *)(gpGlobals.m_Index + 12));
    entity->m_fEffects &= ~8u;
    C_BaseEntity::OnDisableShadowDepthRenderingChanged(this: entity);
    C_BaseEntity::OnShadowDepthRenderingCacheableStateChanged(this: entity);
  }
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x100FAC20
// Name: enum Activity GetDeathPoseActivity(class CBaseAnimating __near *,class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetDeathPoseActivity(CBaseAnimating *entity, const CTakeDamageInfo *info)
{
  char v3; // bl
  int SequenceActivity; // eax
  float z; // ecx
  float v6; // xmm0_4
  float v7; // xmm1_4
  char v8; // cl
  char v9; // al
  BOOL v10; // eax
  Vector vRight; // [esp+4h] [ebp-30h] BYREF
  Vector vForward; // [esp+10h] [ebp-24h] BYREF
  __int64 v13; // [esp+1Ch] [ebp-18h]
  float v14; // [esp+24h] [ebp-10h]
  Vector vDir; // [esp+28h] [ebp-Ch] BYREF

  if ( entity == nullptr )
    return -1;
  v3 = 0;
  SequenceActivity = CBaseAnimating::GetSequenceActivity(this: entity, iSequence: entity->m_nSequence.m_Value);
  if ( SequenceActivity == 12 || SequenceActivity == 45 )
    v3 = 1;
  entity->GetVectors(this: entity, a2: &vForward, a3: &vRight, a4: nullptr);
  z = info->m_vecDamageForce.z;
  v13 = *(_QWORD *)&info->m_vecDamageForce.x;
  *(_QWORD *)&vDir.x = v13 ^ 0x8000000080000000uLL;
  v14 = z;
  vDir.z = -z;
  VectorNormalize(vec: &vDir);
  v6 = (float)((float)(vForward.y * vDir.y) + (float)(vDir.x * vForward.x)) + (float)(vForward.z * vDir.z);
  v7 = (float)((float)(vRight.y * vDir.y) + (float)(vRight.x * vDir.x)) + (float)(vRight.z * vDir.z);
  v8 = 0;
  v9 = 0;
  if ( v6 < 0.0 )
  {
    v8 = 1;
    v6 = v6 * -1.0;
  }
  if ( v7 < 0.0 )
  {
    v9 = 1;
    v7 = v7 * -1.0;
  }
  if ( v7 <= v6 )
  {
    v10 = v3 == 1;
    if ( v8 == 1 )
      return 4 * v10 + 400;
    else
      return 4 * v10 + 398;
  }
  else if ( v9 == 1 )
  {
    return 4 * (v3 == 1) + 401;
  }
  else
  {
    return 4 * (v3 == 1) + 399;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FAD90
// Name: void SelectDeathPoseActivityAndFrame(class CBaseAnimating __near *,class CTakeDamageInfo const __near &,int,enum Activity __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SelectDeathPoseActivityAndFrame(
        CBaseAnimating *entity,
        const CTakeDamageInfo *info,
        int hitgroup,
        Activity *activity,
        int *frame)
{
  CStudioHdr *m_pStudioHdr; // eax

  *activity = ACT_INVALID;
  *frame = 0;
  if ( entity->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: entity) != nullptr )
    CBaseAnimating::LockStudioHdr(this: entity);
  m_pStudioHdr = entity->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    *activity = GetDeathPoseActivity(entity, info);
    *frame = 1;
    switch ( hitgroup )
    {
      case 1:
        *frame = 1;
        break;
      case 2:
      case 3:
        *frame = 2;
        break;
      case 4:
        *frame = 3;
        break;
      case 5:
        *frame = 4;
        break;
      case 6:
        *frame = 5;
        break;
      case 7:
        *frame = 6;
        break;
      default:
        return;
    }
  }
}

} // namespace server
