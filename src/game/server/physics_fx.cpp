// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/physics_fx.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x101900A0
// Name: void PhysicsSplash(class IPhysicsFluidController __near *,class IPhysicsObject __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysicsSplash(IPhysicsFluidController *pFluid, IPhysicsObject *pObject, CBaseEntity *pEntity)
{
  int v4; // ebx
  int i; // esi
  float v6; // xmm0_4
  int m_iEFlags; // ecx
  IPhysicsCollision_vtbl *v8; // ebx
  int v10; // eax
  int v11; // eax
  float v12; // xmm0_4
  unsigned int v13; // eax
  IPhysicsCollision_vtbl *v14; // ebx
  int v15; // eax
  int v16; // eax
  float v17; // xmm0_4
  int v18; // eax
  IPhysicsCollision_vtbl *v19; // ebx
  int v20; // eax
  int v21; // eax
  float v22; // xmm0_4
  unsigned int v23; // eax
  IPhysicsCollision_vtbl *v24; // ebx
  int v25; // eax
  float *v26; // eax
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm6_4
  float v31; // xmm1_4
  float v32; // xmm7_4
  float v33; // xmm4_4
  float v34; // xmm5_4
  float v35; // xmm3_4
  float v36; // xmm0_4
  IPhysicsObject_vtbl *v37; // edx
  unsigned __int16 (__thiscall *GetGameFlags)(IPhysicsObject *); // eax
  double v39; // st7
  double v40; // st7
  float v41; // xmm0_4
  int v42; // eax
  IUniformRandomStream *v43; // ecx
  float *v44; // esi
  IUniformRandomStream *v45; // ecx
  IUniformRandomStream *v46; // ecx
  float v47; // xmm1_4
  float v48; // xmm2_4
  Vector vel; // [esp+94h] [ebp-10Ch] BYREF
  float x; // [esp+A0h] [ebp-100h]
  float y; // [esp+A4h] [ebp-FCh]
  float v52[4]; // [esp+A8h] [ebp-F8h] BYREF
  Vector binPts[2]; // [esp+B8h] [ebp-E8h]
  CEffectData data; // [esp+D0h] [ebp-D0h] BYREF
  float dist; // [esp+134h] [ebp-6Ch] BYREF
  float maxs[2]; // [esp+138h] [ebp-68h]
  float v57; // [esp+140h] [ebp-60h]
  float v58; // [esp+144h] [ebp-5Ch]
  float v59; // [esp+148h] [ebp-58h]
  float v60; // [esp+14Ch] [ebp-54h]
  Vector centerPoint; // [esp+150h] [ebp-50h] BYREF
  float mins[2]; // [esp+15Ch] [ebp-44h]
  float v63; // [esp+164h] [ebp-3Ch] BYREF
  float v64; // [esp+168h] [ebp-38h]
  float v65; // [esp+16Ch] [ebp-34h]
  Vector tangent; // [esp+170h] [ebp-30h] BYREF
  Vector binormal; // [esp+17Ch] [ebp-24h] BYREF
  Vector out; // [esp+188h] [ebp-18h] BYREF
  Vector normal; // [esp+194h] [ebp-Ch] BYREF
  int savedregs; // [esp+1A0h] [ebp+0h] BYREF
  float bRippleOnly; // [esp+1A8h] [ebp+8h]
  float bRippleOnlya; // [esp+1A8h] [ebp+8h]
  float bRippleOnlyb; // [esp+1A8h] [ebp+8h]
  char bRippleOnly_3; // [esp+1ABh] [ebp+Bh]
  float rawSpeed; // [esp+1ACh] [ebp+Ch]
  float rawSpeeda; // [esp+1ACh] [ebp+Ch]
  int rawSpeedb; // [esp+1ACh] [ebp+Ch]
  float sizea; // [esp+1B0h] [ebp+10h]
  float size; // [esp+1B0h] [ebp+10h]

  pFluid->GetSurfacePlane(this: pFluid, a2: &normal, a3: &dist);
  if ( (pEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
  v4 = 0;
  bRippleOnly = -1.0;
  for ( i = 0; i < 3; ++i )
  {
    MatrixGetColumn(in: &pEntity->m_rgflCoordinateFrame, column: i, &out);
    v6 = fabs((float)((float)(normal.x * out.x) + (float)(normal.y * out.y)) + (float)(out.z * normal.z));
    if ( v6 > bRippleOnly )
    {
      bRippleOnly = v6;
      v4 = i;
    }
  }
  MatrixGetColumn(in: &pEntity->m_rgflCoordinateFrame, column: (v4 + 1) % 3, out: &tangent);
  binormal.x = (float)(tangent.z * normal.y) - (float)(tangent.y * normal.z);
  binormal.y = (float)(normal.z * tangent.x) - (float)(tangent.z * normal.x);
  binormal.z = (float)(tangent.y * normal.x) - (float)(normal.y * tangent.x);
  VectorNormalize(vec: &binormal);
  tangent.x = (float)(binormal.y * normal.z) - (float)(binormal.z * normal.y);
  tangent.y = (float)(binormal.z * normal.x) - (float)(normal.z * binormal.x);
  tangent.z = (float)(normal.y * binormal.x) - (float)(binormal.y * normal.x);
  VectorNormalize(vec: &tangent);
  m_iEFlags = pEntity->m_iEFlags;
  out.x = -tangent.x;
  out.y = -tangent.y;
  out.z = -tangent.z;
  if ( (m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
  if ( (pEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
  v8 = physcollision->__vftable;
  v10 = ((int (__thiscall *)(IPhysicsObject *, Vector *, QAngle *, Vector *))pObject->GetCollide)(
          a1: pObject,
          a2: &pEntity->m_vecAbsOrigin,
          a3: &pEntity->m_angAbsRotation,
          a4: &out);
  v11 = ((int (__thiscall *)(IPhysicsCollision *, float *, int))v8->CollideGetExtent)(
          a1: physcollision,
          a2: &v63,
          a3: v10);
  *(_QWORD *)maxs = *(_QWORD *)v11;
  v12 = *(float *)(v11 + 8);
  v13 = (unsigned int)pEntity->m_iEFlags >> 11;
  v57 = v12;
  if ( (v13 & 1) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
  if ( (pEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
  v14 = physcollision->__vftable;
  v15 = ((int (__thiscall *)(IPhysicsObject *, Vector *, QAngle *, Vector *))pObject->GetCollide)(
          a1: pObject,
          a2: &pEntity->m_vecAbsOrigin,
          a3: &pEntity->m_angAbsRotation,
          a4: &tangent);
  v16 = ((int (__thiscall *)(IPhysicsCollision *, Vector *, int))v14->CollideGetExtent)(
          a1: physcollision,
          a2: &out,
          a3: v15);
  v58 = *(float *)v16;
  v59 = *(float *)(v16 + 4);
  v17 = *(float *)(v16 + 8);
  v18 = pEntity->m_iEFlags;
  v60 = v17;
  out.x = -binormal.x;
  out.y = -binormal.y;
  out.z = -binormal.z;
  if ( (v18 & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
  if ( (pEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
  v19 = physcollision->__vftable;
  v20 = ((int (__thiscall *)(IPhysicsObject *, Vector *, QAngle *, Vector *))pObject->GetCollide)(
          a1: pObject,
          a2: &pEntity->m_vecAbsOrigin,
          a3: &pEntity->m_angAbsRotation,
          a4: &out);
  v21 = ((int (__thiscall *)(IPhysicsCollision *, float *, int))v19->CollideGetExtent)(
          a1: physcollision,
          a2: &v63,
          a3: v20);
  binPts[0].x = *(float *)v21;
  binPts[0].y = *(float *)(v21 + 4);
  v22 = *(float *)(v21 + 8);
  v23 = (unsigned int)pEntity->m_iEFlags >> 11;
  binPts[0].z = v22;
  if ( (v23 & 1) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
  if ( (pEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&savedregs);
  v24 = physcollision->__vftable;
  v25 = ((int (__thiscall *)(IPhysicsObject *, Vector *, QAngle *, Vector *))pObject->GetCollide)(
          a1: pObject,
          a2: &pEntity->m_vecAbsOrigin,
          a3: &pEntity->m_angAbsRotation,
          a4: &binormal);
  v26 = (float *)((int (__thiscall *)(IPhysicsCollision *, Vector *, int))v24->CollideGetExtent)(
                   a1: physcollision,
                   a2: &out,
                   a3: v25);
  binPts[1].y = v26[1];
  binPts[1].z = v26[2];
  v27 = *v26 * binormal.x;
  mins[0] = (float)((float)(maxs[0] * tangent.x) + (float)(maxs[1] * tangent.y)) + (float)(v57 * tangent.z);
  v28 = (float)(binPts[1].z * binormal.z) + (float)(v27 + (float)(binPts[1].y * binormal.y));
  v29 = (float)((float)((float)((float)(v58 * tangent.x) + (float)(v59 * tangent.y)) + (float)(v60 * tangent.z))
              + mins[0])
      * 0.5;
  v30 = (float)((float)((float)(v58 * tangent.x) + (float)(v59 * tangent.y)) + (float)(v60 * tangent.z)) - v29;
  v60 = v28;
  v31 = (float)(v28
              + (float)((float)(binPts[0].z * binormal.z)
                      + (float)((float)(binPts[0].x * binormal.x) + (float)(binPts[0].y * binormal.y))))
      * 0.5;
  mins[0] = v30;
  sizea = v60 - v31;
  mins[1] = v60 - v31;
  v58 = binormal.x * v31;
  v59 = binormal.y * v31;
  v32 = (float)((float)(tangent.x * v29) + (float)(binormal.x * v31)) + (float)(normal.x * dist);
  centerPoint.x = v32;
  centerPoint.z = (float)((float)(v29 * tangent.z) + (float)(binormal.z * v31)) + (float)(normal.z * dist);
  centerPoint.y = (float)((float)(tangent.y * v29) + (float)(binormal.y * v31)) + (float)(normal.y * dist);
  v33 = binormal.y * (float)(v60 - v31);
  v34 = binormal.z * (float)(v60 - v31);
  v64 = centerPoint.y - (float)(tangent.y * v30);
  v35 = (float)(tangent.z * v30) + centerPoint.z;
  v60 = centerPoint.z - (float)(tangent.z * v30);
  v65 = v60;
  v36 = (float)(v30 * tangent.x) + v32;
  out.x = (float)(v32 - (float)(v30 * tangent.x)) - (float)(sizea * binormal.x);
  out.y = v64 - (float)(binormal.y * sizea);
  out.z = v60 - (float)(binormal.z * sizea);
  x = out.x;
  bRippleOnlya = (float)(tangent.y * v30) + centerPoint.y;
  y = out.y;
  v52[0] = out.z;
  v52[2] = bRippleOnlya - v33;
  v52[3] = v35 - v34;
  v63 = v32 - (float)(v30 * tangent.x);
  v52[1] = v36 - (float)(sizea * binormal.x);
  binPts[0].x = v36 + (float)(sizea * binormal.x);
  v37 = pObject->__vftable;
  binPts[0].z = v35 + v34;
  binPts[1].y = v64 + v33;
  GetGameFlags = v37->GetGameFlags;
  binPts[0].y = bRippleOnlya + v33;
  binPts[1].x = v63 + (float)(sizea * binormal.x);
  binPts[1].z = v60 + v34;
  memset(&data, 0, 56);
  data.m_flScale = 1.0;
  memset(&data.m_flMagnitude, 0, 14);
  memset(&data.m_nMaterial, 0, 17);
  if ( (((int (__thiscall *)(IPhysicsObject *))GetGameFlags)(a1: pObject) & 8) == 0 )
  {
    pObject->GetVelocity(this: pObject, a2: &vel, a3: nullptr);
    rawSpeed = -(vel.x * normal.x + vel.y * normal.y + vel.z * normal.z);
    v39 = ((double (__thiscall *)(IPhysicsObject *))pObject->GetMass)(a1: pObject);
    v40 = v39 * (rawSpeed * rawSpeed * mins[0] * mins[1] * 0.0000004) * 0.0099999998;
    if ( v40 >= 0.0 )
    {
      v41 = v40;
      bRippleOnlyb = v40;
      if ( bRippleOnlyb > 50.0 )
        v41 = 50.0;
    }
    else
    {
      v41 = 0.0;
    }
    bRippleOnly_3 = 0;
    if ( ((unsigned __int8 (__thiscall *)(CBaseEntity *, Vector *, Vector *, _DWORD, _DWORD))pEntity->PhysicsSplash)(
           a1: pEntity,
           a2: &centerPoint,
           a3: &normal,
           a4: LODWORD(rawSpeed),
           a5: LODWORD(v41)) == 0 )
    {
      if ( v41 <= 0.34999999 )
      {
        if ( v41 <= 0.1 )
          return;
        bRippleOnly_3 = 1;
      }
      rawSpeeda = mins[1] * mins[0];
      data.m_vOrigin = centerPoint;
      data.m_vNormal = normal;
      size = (v41 - 0.34999999) * 10.0 * 0.020140987 + 8.0;
      data.m_fFlags = 0;
      VectorAngles(forward: &normal, angles: &data.m_vAngles);
      data.m_flScale = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int))random->RandomFloat)(
                         a1: random,
                         a2: 0,
                         a3: 0x40000000)
                     + size;
      if ( (CBaseEntity::GetWaterType(this: pEntity) & 0x10) != 0 )
        data.m_fFlags |= 1u;
      if ( bRippleOnly_3 != 0 )
        DispatchEffect(pName: "waterripple", &data);
      else
        DispatchEffect(pName: "watersplash", &data);
      if ( rawSpeeda > 500.0 )
      {
        v42 = random->RandomInt(this: random, a2: 1, a3: 4);
        if ( v42 > 0 )
        {
          v44 = v52;
          for ( rawSpeedb = v42; rawSpeedb != 0; --rawSpeedb )
          {
            out.x = _RandomFloat(this: v43, a2: -4.0, a3: 4.0);
            out.y = _RandomFloat(this: v45, a2: -4.0, a3: 4.0);
            _RandomFloat(this: v46, a2: -4.0, a3: 4.0);
            v47 = *(v44 - 1) + out.y;
            v48 = *v44;
            data.m_vOrigin.x = *(v44 - 2) + out.x;
            data.m_vNormal = normal;
            data.m_fFlags = 0;
            data.m_vOrigin.y = v47;
            data.m_vOrigin.z = v48;
            VectorAngles(forward: &normal, angles: &data.m_vAngles);
            data.m_flScale = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                               a1: random,
                               a2: -1069547520,
                               a3: 1065353216)
                           + size;
            if ( (CBaseEntity::GetWaterType(this: pEntity) & 0x10) != 0 )
              data.m_fFlags |= 1u;
            if ( bRippleOnly_3 != 0 )
              DispatchEffect(pName: "waterripple", &data);
            else
              DispatchEffect(pName: "watersplash", &data);
            v44 += 3;
          }
        }
      }
    }
  }
}
