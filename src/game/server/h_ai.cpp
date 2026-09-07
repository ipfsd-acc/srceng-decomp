// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/h_ai.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1015A2F0
// Name: bool FBoxVisible(class CBaseEntity __near *,class CBaseEntity __near *,class Vector __near &,float)
// Source: json
//------------------------------------------------------------------------------
char __usercall FBoxVisible@<al>(
        int a1@<esi>,
        CBaseEntity *pLooker,
        CBaseEntity *pTarget,
        Vector *vecTargetOrigin,
        float flSize)
{
  CBaseEntity::NetworkVar_m_Collision_vtbl *v6; // eax
  __int64 v7; // xmm0_8
  const Vector *(__thiscall *OBBMaxs)(struct CBaseEntity::NetworkVar_m_Collision *); // edx
  float *v9; // ebx
  const Vector *v10; // eax
  double v11; // st7
  const Vector *(__thiscall *v12)(struct CBaseEntity::NetworkVar_m_Collision *); // eax
  int v13; // ebx
  const Vector *v14; // eax
  double v15; // st7
  const Vector *(__thiscall *v16)(struct CBaseEntity::NetworkVar_m_Collision *); // eax
  int v17; // ebx
  const Vector *v18; // eax
  double v19; // st7
  CGameTrace tr; // [esp+28h] [ebp-70h] BYREF
  Vector vecLookerOrigin; // [esp+7Ch] [ebp-1Ch] BYREF
  Vector vecTarget; // [esp+88h] [ebp-10h] BYREF
  int i; // [esp+94h] [ebp-4h]
  IHandleEntity savedregs; // [esp+98h] [ebp+0h] BYREF

  if ( pLooker->m_nWaterLevel.m_Value == 3 )
  {
    if ( pTarget->m_nWaterLevel.m_Value != 0 )
      goto LABEL_6;
    return 0;
  }
  if ( pTarget->m_nWaterLevel.m_Value == 3 )
    return 0;
LABEL_6:
  ((void (__stdcall *)(Vector *))pLooker->EyePosition)(a1: &vecLookerOrigin);
  i = 0;
  while ( 1 )
  {
    if ( (pTarget->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pTarget, a2: (int)&savedregs);
    v6 = pTarget->m_Collision.__vftable;
    v7 = *(_QWORD *)&pTarget->m_vecAbsOrigin.x;
    vecTarget.z = pTarget->m_vecAbsOrigin.z;
    OBBMaxs = v6->OBBMaxs;
    *(_QWORD *)&vecTarget.x = v7;
    v9 = (float *)OBBMaxs(this: &pTarget->m_Collision);
    v10 = pTarget->m_Collision.OBBMins(this: &pTarget->m_Collision);
    v11 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
            a1: random,
            a2: v10->x + flSize,
            a3: *v9 - flSize);
    v12 = pTarget->m_Collision.OBBMaxs;
    vecTarget.x = v11 + vecTarget.x;
    v13 = (int)v12(this: &pTarget->m_Collision);
    v14 = pTarget->m_Collision.OBBMins(this: &pTarget->m_Collision);
    v15 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
            a1: random,
            a2: v14->y + flSize,
            a3: *(float *)(v13 + 4) - flSize);
    v16 = pTarget->m_Collision.OBBMaxs;
    vecTarget.y = v15 + vecTarget.y;
    v17 = (int)v16(this: &pTarget->m_Collision);
    v18 = pTarget->m_Collision.OBBMins(this: &pTarget->m_Collision);
    v19 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
            a1: random,
            a2: v18->z + flSize,
            a3: *(float *)(v17 + 8) - flSize);
    vecTarget.z = v19 + vecTarget.z;
    UTIL_TraceLine(
      a1: &savedregs,
      a2: a1,
      vecAbsStart: &vecLookerOrigin,
      vecAbsEnd: &vecTarget,
      mask: 0x4041u,
      ignore: pLooker,
      collisionGroup: 0,
      ptr: &tr);
    if ( tr.fraction == 1.0 )
      break;
    if ( ++i >= 5 )
      return 0;
  }
  *vecTargetOrigin = vecTarget;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015A4F0
// Name: class Vector VecCheckToss(class CBaseEntity __near *,class ITraceFilter __near *,class Vector,class Vector,float,float,bool,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
Vector *__usercall VecCheckToss@<eax>(
        float a1@<ebp>,
        Vector *result,
        CBaseEntity *pEntity,
        ITraceFilter *pFilter,
        Vector vecSpot1,
        Vector vecSpot2,
        float flHeightMaxRatio,
        float flGravityAdj,
        bool bRandomize,
        Vector *vecMins,
        Vector *vecMaxs)
{
  double v12; // st7
  double v13; // st7
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v17; // xmm4_4
  float v18; // xmm1_4
  __int128 v19; // xmm1
  float v20; // xmm5_4
  float v21; // xmm2_4
  float v22; // xmm5_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  _BYTE v25[12]; // [esp+30h] [ebp-ACh] BYREF
  CGameTrace tr; // [esp+3Ch] [ebp-A0h] BYREF
  float v27; // [esp+90h] [ebp-4Ch]
  Vector right; // [esp+94h] [ebp-48h] BYREF
  __int128 forward; // [esp+A0h] [ebp-3Ch] OVERLAPPED BYREF
  float v30; // [esp+BCh] [ebp-20h]
  float v31; // [esp+C0h] [ebp-1Ch] BYREF
  float v32; // [esp+C4h] [ebp-18h]
  float flGravity; // [esp+C8h] [ebp-14h]
  Vector vecApex; // [esp+CCh] [ebp-10h] BYREF
  float retaddr; // [esp+DCh] [ebp+0h]

  vecApex.y = a1;
  vecApex.z = retaddr;
  v30 = sv_gravity.m_pParent->m_Value.m_fValue * flGravityAdj;
  if ( (float)(vecSpot2.z - vecSpot1.z) > 500.0 )
    goto LABEL_2;
  AngleVectors(angles: &pEntity->m_angRotation.m_Value, forward: &right, right: (Vector *)&tr.m_pEnt, up: nullptr);
  if ( bRandomize )
  {
    vecApex.x = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                  a1: random,
                  a2: -1056964608,
                  a3: 1090519040);
    v12 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
            a1: random,
            a2: -1048576000,
            a3: 1098907648);
    vecApex.x = v12 + vecApex.x;
    vecSpot2.x = (float)(*(float *)&tr.m_pEnt * vecApex.x) + vecSpot2.x;
    vecSpot2.y = vecSpot2.y + (float)(*(float *)&tr.hitbox * vecApex.x);
    vecSpot2.z = (float)(v27 * vecApex.x) + vecSpot2.z;
    vecApex.x = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                  a1: random,
                  a2: -1056964608,
                  a3: 1090519040);
    v13 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
            a1: random,
            a2: -1048576000,
            a3: 1098907648);
    vecApex.x = v13 + vecApex.x;
    x = (float)(right.x * vecApex.x) + vecSpot2.x;
    y = (float)(right.y * vecApex.x) + vecSpot2.y;
    z = (float)(right.z * vecApex.x) + vecSpot2.z;
    vecSpot2.x = x;
    vecSpot2.y = y;
    vecSpot2.z = z;
  }
  else
  {
    z = vecSpot2.z;
    y = vecSpot2.y;
    x = vecSpot2.x;
  }
  flGravity = (float)((float)(z - vecSpot1.z) * 0.5) + vecSpot1.z;
  v31 = (float)((float)(x - vecSpot1.x) * 0.5) + vecSpot1.x;
  v32 = (float)((float)(y - vecSpot1.y) * 0.5) + vecSpot1.y;
  *((float *)&forward + 1) = v31;
  *((float *)&forward + 2) = v32;
  *((float *)&forward + 3) = flGravity + 300.0;
  UTIL_TraceLine(
    a1: (int)&vecApex.y,
    a2: (int)pFilter,
    vecAbsStart: (const Vector *)&v31,
    vecAbsEnd: (const Vector *)((char *)&forward + 4),
    mask: 0x400Bu,
    pFilter,
    ptr: (CGameTrace *)v25);
  v17 = tr.startpos.z;
  if ( tr.plane.normal.z != 1.0 )
    v17 = tr.startpos.z - 15.0;
  v18 = vecSpot1.z;
  if ( flHeightMaxRatio != -1.0 )
  {
    v19 = 0;
    v20 = vecSpot2.z;
    *(float *)&v19 = fsqrt(
                       (float)((float)((float)(vecSpot2.y - vecSpot1.y) * (float)(vecSpot2.y - vecSpot1.y))
                             + (float)((float)(vecSpot2.z - vecSpot1.z) * (float)(vecSpot2.z - vecSpot1.z)))
                     + (float)((float)(vecSpot2.x - vecSpot1.x) * (float)(vecSpot2.x - vecSpot1.x)));
    forward = v19;
    v18 = vecSpot1.z;
    v21 = *(float *)&forward * flHeightMaxRatio;
    if ( vecSpot1.z > vecSpot2.z )
      v20 = vecSpot1.z;
    if ( (float)(v17 - v20) > v21 )
      v17 = v20 + v21;
  }
  if ( v18 > v17 || vecSpot2.z > v17 )
    goto LABEL_22;
  v22 = 1.0 / (float)(v30 * 0.5);
  v23 = fsqrt((float)(v17 - v18) * v22);
  if ( v23 < 0.1 )
    goto LABEL_2;
  v24 = 1.0 / (float)(fsqrt((float)(v17 - vecSpot2.z) * v22) + v23);
  *((float *)&forward + 1) = v24 * (float)(vecSpot2.x - vecSpot1.x);
  *((float *)&forward + 2) = v24 * (float)(vecSpot2.y - vecSpot1.y);
  *((float *)&forward + 3) = v23 * v30;
  v31 = (float)(*((float *)&forward + 1) * v23) + vecSpot1.x;
  v32 = (float)(*((float *)&forward + 2) * v23) + vecSpot1.y;
  flGravity = v17;
  UTIL_TraceLine(
    a1: (int)&vecApex.y,
    a2: (int)pFilter,
    vecAbsStart: &vecSpot1,
    vecAbsEnd: (const Vector *)&v31,
    mask: 0x2004003u,
    pFilter,
    ptr: (CGameTrace *)v25);
  if ( tr.plane.normal.z == 1.0 )
  {
    UTIL_TraceLine(
      a1: (int)&vecApex.y,
      a2: (int)pFilter,
      vecAbsStart: &vecSpot2,
      vecAbsEnd: (const Vector *)&v31,
      mask: 0x4003u,
      pFilter,
      ptr: (CGameTrace *)v25);
    if ( tr.plane.normal.z != 1.0 )
    {
LABEL_2:
      *result = vec3_origin;
      return result;
    }
    if ( vecMins == nullptr
      || vecMaxs == nullptr
      || (UTIL_TraceHull(
            a1: (int)&vecApex.y,
            a2: (int)pFilter,
            vecAbsStart: &vecSpot1,
            vecAbsEnd: (const Vector *)&v31,
            hullMin: vecMins,
            hullMax: vecMaxs,
            mask: 0x2004003u,
            pFilter,
            ptr: (CGameTrace *)v25),
          tr.plane.normal.z >= 1.0) )
    {
      *result = *(Vector *)((char *)&forward + 4);
      return result;
    }
  }
LABEL_22:
  *result = vec3_origin;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015A9A0
// Name: class Vector VecCheckToss(class CBaseEntity __near *,class Vector,class Vector,float,float,bool,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
Vector *__cdecl VecCheckToss(
        Vector *result,
        CBaseEntity *pEntity,
        Vector vecSpot1,
        Vector vecSpot2,
        float flHeightMaxRatio,
        float flGravityAdj,
        bool bRandomize,
        Vector *vecMins,
        Vector *vecMaxs)
{
  CTraceFilterSimple traceFilter; // [esp+18h] [ebp-10h] BYREF
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  CTraceFilterSimple::CTraceFilterSimple(
    this: &traceFilter,
    passedict: pEntity,
    collisionGroup: 0,
    pExtraShouldHitFunc: nullptr);
  VecCheckToss(
    a1: COERCE_FLOAT(&savedregs),
    result,
    pEntity,
    pFilter: &traceFilter,
    vecSpot1,
    vecSpot2,
    flHeightMaxRatio,
    flGravityAdj,
    bRandomize,
    vecMins,
    vecMaxs);
  return result;
}
