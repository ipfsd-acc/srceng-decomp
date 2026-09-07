// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/particle_collision.cpp
// Functions: 8
// ============================================================

#include "game\client\particle_collision.h"

//------------------------------------------------------------------------------
// Address: 0x1012D140
// Name: public: virtual void CBaseSimpleCollision::Setup(class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseSimpleCollision::Setup(
        CBaseSimpleCollision *this,
        const Vector *origin,
        float speed,
        float gravity)
{
  void (__thiscall *TestForPlane)(CBaseSimpleCollision *, const Vector *, const Vector *, float, float); // edx
  void (__thiscall *v6)(CBaseSimpleCollision *, const Vector *, const Vector *, float, float); // edx
  void (__thiscall *v7)(CBaseSimpleCollision *, const Vector *, const Vector *, float, float); // edx
  CBaseSimpleCollision_vtbl *v8; // eax
  void (__thiscall *v9)(CBaseSimpleCollision *, const Vector *, const Vector *, float, float); // edx
  int v10; // [esp+60h] [ebp-Ch] BYREF
  int v11; // [esp+64h] [ebp-8h]
  int v12; // [esp+68h] [ebp-4h]

  v10 = 1065353216;
  v11 = 0;
  v12 = 0;
  ((void (__thiscall *)(CBaseSimpleCollision *, const Vector *, int *, _DWORD, _DWORD))this->TestForPlane)(
    a1: this,
    a2: origin,
    a3: &v10,
    a4: LODWORD(speed),
    a5: LODWORD(gravity));
  TestForPlane = this->TestForPlane;
  v10 = -1082130432;
  v11 = 0;
  v12 = 0;
  ((void (__thiscall *)(CBaseSimpleCollision *, const Vector *, int *, _DWORD, _DWORD))TestForPlane)(
    a1: this,
    a2: origin,
    a3: &v10,
    a4: LODWORD(speed),
    a5: LODWORD(gravity));
  v6 = this->TestForPlane;
  v10 = 0;
  v12 = 0;
  v11 = 1065353216;
  ((void (__thiscall *)(CBaseSimpleCollision *, const Vector *, int *, _DWORD, _DWORD))v6)(
    a1: this,
    a2: origin,
    a3: &v10,
    a4: LODWORD(speed),
    a5: LODWORD(gravity));
  v7 = this->TestForPlane;
  v10 = 0;
  v12 = 0;
  v11 = -1082130432;
  ((void (__thiscall *)(CBaseSimpleCollision *, const Vector *, int *, _DWORD, _DWORD))v7)(
    a1: this,
    a2: origin,
    a3: &v10,
    a4: LODWORD(speed),
    a5: LODWORD(gravity));
  v8 = this->__vftable;
  v10 = 0;
  v11 = 0;
  v12 = 1065353216;
  ((void (__thiscall *)(CBaseSimpleCollision *, const Vector *, int *, _DWORD, _DWORD))v8->TestForPlane)(
    a1: this,
    a2: origin,
    a3: &v10,
    a4: LODWORD(speed),
    a5: LODWORD(gravity));
  v9 = this->TestForPlane;
  v10 = 0;
  v11 = 0;
  v12 = -1082130432;
  ((void (__thiscall *)(CBaseSimpleCollision *, const Vector *, int *, _DWORD, _DWORD))v9)(
    a1: this,
    a2: origin,
    a3: &v10,
    a4: LODWORD(speed),
    a5: LODWORD(gravity));
}

//------------------------------------------------------------------------------
// Address: 0x1012D2E0
// Name: protected: virtual void CBaseSimpleCollision::ConsiderPlane(struct cplane_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseSimpleCollision::ConsiderPlane(CBaseSimpleCollision *this, cplane_t *plane)
{
  int m_nActivePlanes; // ebx
  int v3; // edi
  float *p_z; // esi
  float v5; // xmm0_4
  int v6; // eax
  VPlane *v7; // eax

  m_nActivePlanes = this->m_nActivePlanes;
  v3 = 0;
  if ( m_nActivePlanes <= 0 )
  {
LABEL_9:
    if ( m_nActivePlanes < 6 )
    {
      this->m_collisionPlanes[m_nActivePlanes].m_Dist = plane->dist;
      v6 = this->m_nActivePlanes;
      this->m_collisionPlanes[v6].m_Normal.x = plane->normal.x;
      v7 = &this->m_collisionPlanes[v6];
      v7->m_Normal.y = plane->normal.y;
      v7->m_Normal.z = plane->normal.z;
      ++this->m_nActivePlanes;
    }
  }
  else
  {
    p_z = &this->m_collisionPlanes[0].m_Normal.z;
    while ( 1 )
    {
      v5 = p_z[1];
      if ( v5 != -1.0
        && plane->normal.x == *(p_z - 2)
        && plane->normal.y == *(p_z - 1)
        && plane->normal.z == *p_z
        && v5 == plane->dist )
      {
        break;
      }
      ++v3;
      p_z += 4;
      if ( v3 >= m_nActivePlanes )
        goto LABEL_9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012D380
// Name: public: void CBaseSimpleCollision::ClearActivePlanes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseSimpleCollision::ClearActivePlanes(CBaseSimpleCollision *this)
{
  this->m_collisionPlanes[0].m_Dist = -1.0;
  this->m_collisionPlanes[0].m_Normal.x = 0.0;
  this->m_collisionPlanes[0].m_Normal.y = 0.0;
  this->m_collisionPlanes[0].m_Normal.z = 0.0;
  this->m_collisionPlanes[1].m_Dist = -1.0;
  this->m_collisionPlanes[1].m_Normal.x = 0.0;
  this->m_collisionPlanes[1].m_Normal.y = 0.0;
  this->m_collisionPlanes[1].m_Normal.z = 0.0;
  this->m_collisionPlanes[2].m_Dist = -1.0;
  this->m_collisionPlanes[2].m_Normal.x = 0.0;
  this->m_collisionPlanes[2].m_Normal.y = 0.0;
  this->m_collisionPlanes[2].m_Normal.z = 0.0;
  this->m_collisionPlanes[3].m_Dist = -1.0;
  this->m_collisionPlanes[3].m_Normal.x = 0.0;
  this->m_collisionPlanes[3].m_Normal.y = 0.0;
  this->m_collisionPlanes[3].m_Normal.z = 0.0;
  this->m_collisionPlanes[4].m_Dist = -1.0;
  this->m_collisionPlanes[4].m_Normal.x = 0.0;
  this->m_collisionPlanes[4].m_Normal.y = 0.0;
  this->m_collisionPlanes[4].m_Normal.z = 0.0;
  this->m_collisionPlanes[5].m_Dist = -1.0;
  this->m_collisionPlanes[5].m_Normal.x = 0.0;
  this->m_collisionPlanes[5].m_Normal.y = 0.0;
  this->m_collisionPlanes[5].m_Normal.z = 0.0;
  this->m_nActivePlanes = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1012D410
// Name: public: virtual void CParticleCollision::Setup(class Vector const __near &,class Vector const __near *,float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CParticleCollision::Setup(
        CParticleCollision *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        const Vector *origin,
        const Vector *dir,
        float angularSpread,
        float minSpeed,
        float maxSpeed,
        float gravity,
        float dampen)
{
  const Vector *v11; // edi
  void (__thiscall *v12)(struct CParticleCollision *, const Vector *, const Vector *, float, float); // edx
  void (__thiscall *v13)(struct CParticleCollision *, const Vector *, const Vector *, float, float); // edx
  void (__thiscall *v14)(struct CParticleCollision *, const Vector *, const Vector *, float, float); // edx
  void (__thiscall *v15)(struct CParticleCollision *, const Vector *, const Vector *, float, float); // edx
  CParticleCollision_vtbl *v16; // eax
  void (__thiscall *TestForPlane)(struct CParticleCollision *, const Vector *, const Vector *, float, float); // edx
  QAngle vAngles; // [esp+50h] [ebp-24h] BYREF
  Vector vRight; // [esp+5Ch] [ebp-18h] BYREF
  Vector vSkewDir; // [esp+68h] [ebp-Ch] BYREF
  float speedAvg; // [esp+94h] [ebp+20h]

  this->m_flGravity = gravity;
  this->m_flCollisionDampen = dampen;
  this->m_nActivePlanes = 0;
  speedAvg = (float)(minSpeed + maxSpeed) * 0.5;
  if ( dir != nullptr )
  {
    VectorAngles(forward: dir, angles: &vAngles);
    AngleVectors(angles: &vAngles, forward: nullptr, right: &vRight, up: nullptr);
    v11 = origin;
    ((void (__thiscall *)(CParticleCollision *, const Vector *, const Vector *, _DWORD, _DWORD, int, int))this->TestForPlane)(
      a1: this,
      a2: origin,
      a3: dir,
      a4: LODWORD(speedAvg),
      a5: LODWORD(gravity),
      a6: a2,
      a7: a3);
    TestForPlane = this->TestForPlane;
    vSkewDir = vRight;
    ((void (__thiscall *)(CParticleCollision *, const Vector *, Vector *, _DWORD, _DWORD))TestForPlane)(
      a1: this,
      a2: origin,
      a3: &vSkewDir,
      a4: LODWORD(speedAvg),
      a5: LODWORD(gravity));
    vSkewDir.x = vSkewDir.x * -1.0;
    vSkewDir.y = vSkewDir.y * -1.0;
    vSkewDir.z = vSkewDir.z * -1.0;
  }
  else
  {
    v11 = origin;
    v12 = this->TestForPlane;
    vSkewDir.x = 1.0;
    vSkewDir.y = 0.0;
    vSkewDir.z = 0.0;
    ((void (__thiscall *)(CParticleCollision *, const Vector *, Vector *, _DWORD, _DWORD, int, int))v12)(
      a1: this,
      a2: origin,
      a3: &vSkewDir,
      a4: (float)(minSpeed + maxSpeed) * 0.5,
      a5: LODWORD(gravity),
      a6: a2,
      a7: a3);
    v13 = this->TestForPlane;
    vSkewDir.x = -1.0;
    vSkewDir.y = 0.0;
    vSkewDir.z = 0.0;
    ((void (__thiscall *)(CParticleCollision *, const Vector *, Vector *, _DWORD, _DWORD))v13)(
      a1: this,
      a2: origin,
      a3: &vSkewDir,
      a4: LODWORD(speedAvg),
      a5: LODWORD(gravity));
    v14 = this->TestForPlane;
    vSkewDir.x = 0.0;
    vSkewDir.z = 0.0;
    vSkewDir.y = 1.0;
    ((void (__thiscall *)(CParticleCollision *, const Vector *, Vector *, _DWORD, _DWORD))v14)(
      a1: this,
      a2: origin,
      a3: &vSkewDir,
      a4: LODWORD(speedAvg),
      a5: LODWORD(gravity));
    v15 = this->TestForPlane;
    vSkewDir.x = 0.0;
    vSkewDir.z = 0.0;
    vSkewDir.y = -1.0;
    ((void (__thiscall *)(CParticleCollision *, const Vector *, Vector *, _DWORD, _DWORD))v15)(
      a1: this,
      a2: origin,
      a3: &vSkewDir,
      a4: LODWORD(speedAvg),
      a5: LODWORD(gravity));
    v16 = this->__vftable;
    vSkewDir.x = 0.0;
    vSkewDir.y = 0.0;
    vSkewDir.z = 1.0;
    ((void (__thiscall *)(CParticleCollision *, const Vector *, Vector *, float, _DWORD))v16->TestForPlane)(
      a1: this,
      a2: origin,
      a3: &vSkewDir,
      a4: COERCE_FLOAT(LODWORD(speedAvg)),
      a5: LODWORD(gravity));
    vSkewDir.x = 0.0;
    vSkewDir.y = 0.0;
    vSkewDir.z = -1.0;
  }
  ((void (__thiscall *)(CParticleCollision *, const Vector *, Vector *))this->TestForPlane)(
    a1: this,
    a2: v11,
    a3: &vSkewDir);
}

//------------------------------------------------------------------------------
// Address: 0x1012D6A0
// Name: public: virtual void CBaseSimpleCollision::TraceLine(class Vector const __near &,class Vector const __near &,class CGameTrace __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseSimpleCollision::TraceLine(
        CBaseSimpleCollision *this,
        const Vector *start,
        const Vector *end,
        CGameTrace *pTrace,
        bool coarse)
{
  int m_nActivePlanes; // ecx
  int v7; // esi
  float *p_z; // edx
  float v9; // xmm0_4
  float v10; // xmm1_4
  float y; // xmm5_4
  float z; // xmm6_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  int v16; // esi
  CBaseSimpleCollision *v17; // [esp+Ch] [ebp-8h]
  int v18; // [esp+10h] [ebp-4h]
  IHandleEntity savedregs; // [esp+14h] [ebp+0h] BYREF

  m_nActivePlanes = this->m_nActivePlanes;
  v7 = 0;
  v17 = this;
  v18 = m_nActivePlanes;
  if ( m_nActivePlanes <= 0 )
  {
LABEL_8:
    pTrace->plane.normal.x = 0.0;
    pTrace->plane.normal.y = 0.0;
    pTrace->plane.normal.z = 0.0;
    pTrace->plane.dist = 0.0;
    pTrace->fraction = 1.0;
    *(_WORD *)&pTrace->allsolid = 0;
    pTrace->m_pEnt = nullptr;
    return;
  }
  p_z = &this->m_collisionPlanes[0].m_Normal.z;
  while ( 1 )
  {
    if ( p_z[1] != -1.0 )
    {
      v9 = (float)((float)((float)(start->y * *(p_z - 1)) + (float)(*(p_z - 2) * start->x)) + (float)(start->z * *p_z))
         - p_z[1];
      v10 = (float)((float)((float)(end->y * *(p_z - 1)) + (float)(*(p_z - 2) * end->x)) + (float)(end->z * *p_z))
          - p_z[1];
      if ( v9 < -0.0099999998 )
        goto LABEL_7;
      if ( v9 > 0.0099999998 != v10 > 0.0099999998 )
        break;
      m_nActivePlanes = v18;
    }
LABEL_7:
    ++v7;
    p_z += 4;
    if ( v7 >= m_nActivePlanes )
      goto LABEL_8;
  }
  y = start->y;
  z = start->z;
  v13 = v9 / (float)(v9 - v10);
  v14 = (float)(end->y - y) * v13;
  v15 = (float)(end->z - z) * v13;
  v16 = v7;
  pTrace->endpos.x = start->x + (float)((float)(end->x - start->x) * v13);
  pTrace->endpos.y = y + v14;
  pTrace->endpos.z = z + v15;
  pTrace->fraction = v13 - 0.0099999998;
  pTrace->plane.normal = v17->m_collisionPlanes[v16].m_Normal;
  pTrace->plane.dist = v17->m_collisionPlanes[v16].m_Dist;
  if ( !coarse && pTrace->fraction < 1.0 )
    UTIL_TraceLine(
      a1: &savedregs,
      a2: v16 * 16,
      vecAbsStart: start,
      vecAbsEnd: end,
      mask: 0x400Bu,
      ignore: nullptr,
      collisionGroup: 0,
      ptr: pTrace);
}

//------------------------------------------------------------------------------
// Address: 0x1012D880
// Name: protected: virtual void CBaseSimpleCollision::TestForPlane(class Vector const __near &,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseSimpleCollision::TestForPlane(
        CBaseSimpleCollision *this,
        const Vector *start,
        const Vector *dir,
        float speed,
        float gravity)
{
  float x; // xmm5_4
  float y; // xmm6_4
  float z; // xmm7_4
  float v8; // xmm4_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  int v14; // esi
  CGameTrace tr; // [esp+0h] [ebp-84h] BYREF
  float v16; // [esp+54h] [ebp-30h]
  float v17; // [esp+58h] [ebp-2Ch]
  Vector testEnd; // [esp+60h] [ebp-24h] BYREF
  Vector vStepIncr; // [esp+6Ch] [ebp-18h]
  Vector testStart; // [esp+78h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+84h] [ebp+0h] BYREF

  x = start->x;
  y = start->y;
  z = start->z;
  v8 = gravity * 0.25;
  v9 = dir->x * (float)(speed * 0.25);
  v10 = dir->y * (float)(speed * 0.25);
  v11 = dir->z * (float)(speed * 0.25);
  v12 = 1.0;
  testStart.x = start->x;
  testStart.y = y;
  testStart.z = z;
  vStepIncr.x = v9;
  vStepIncr.y = v10;
  vStepIncr.z = v11;
  v14 = 1;
  while ( 1 )
  {
    v16 = v9 + x;
    testEnd.x = v9 + x;
    v17 = v10 + y;
    testEnd.y = v10 + y;
    testEnd.z = (float)(v11 + z) - (float)((float)((float)((float)(v12 * 0.25) * 0.5) * (float)(v12 * 0.25)) * v8);
    UTIL_TraceLine(
      a1: &savedregs,
      a2: v14,
      vecAbsStart: &testStart,
      vecAbsEnd: &testEnd,
      mask: 0x400Bu,
      ignore: nullptr,
      collisionGroup: 0,
      ptr: &tr);
    if ( tr.fraction != 1.0 )
      break;
    x = v16;
    y = v17;
    z = testEnd.z;
    v12 = (float)++v14;
    testStart.x = v16;
    testStart.y = v17;
    testStart.z = testEnd.z;
    if ( (float)v14 > 8.0 )
      return;
    v9 = vStepIncr.x;
    v10 = vStepIncr.y;
    v11 = vStepIncr.z;
    v8 = gravity * 0.25;
  }
  this->ConsiderPlane(this, a2: &tr.plane);
}

//------------------------------------------------------------------------------
// Address: 0x1012D9F0
// Name: public: CParticleCollision::CParticleCollision(void)
// Source: json
//------------------------------------------------------------------------------
CParticleCollision *__thiscall CParticleCollision::CParticleCollision(CParticleCollision *this)
{
  this->m_flGravity = 800.0;
  this->m_flCollisionDampen = 0.5;
  this->__vftable = (CParticleCollision_vtbl *)&CParticleCollision::`vftable';
  this->m_flAngularCollisionDampen = 0.25;
  this->m_collisionPlanes[0].m_Dist = -1.0;
  this->m_collisionPlanes[0].m_Normal.x = 0.0;
  this->m_collisionPlanes[0].m_Normal.y = 0.0;
  this->m_collisionPlanes[0].m_Normal.z = 0.0;
  this->m_collisionPlanes[1].m_Dist = -1.0;
  this->m_collisionPlanes[1].m_Normal.x = 0.0;
  this->m_collisionPlanes[1].m_Normal.y = 0.0;
  this->m_collisionPlanes[1].m_Normal.z = 0.0;
  this->m_collisionPlanes[2].m_Dist = -1.0;
  this->m_collisionPlanes[2].m_Normal.x = 0.0;
  this->m_collisionPlanes[2].m_Normal.y = 0.0;
  this->m_collisionPlanes[2].m_Normal.z = 0.0;
  this->m_collisionPlanes[3].m_Dist = -1.0;
  this->m_collisionPlanes[3].m_Normal.x = 0.0;
  this->m_collisionPlanes[3].m_Normal.y = 0.0;
  this->m_collisionPlanes[3].m_Normal.z = 0.0;
  this->m_collisionPlanes[4].m_Dist = -1.0;
  this->m_collisionPlanes[4].m_Normal.x = 0.0;
  this->m_collisionPlanes[4].m_Normal.y = 0.0;
  this->m_collisionPlanes[4].m_Normal.z = 0.0;
  this->m_collisionPlanes[5].m_Dist = -1.0;
  this->m_collisionPlanes[5].m_Normal.x = 0.0;
  this->m_collisionPlanes[5].m_Normal.y = 0.0;
  this->m_collisionPlanes[5].m_Normal.z = 0.0;
  this->m_nActivePlanes = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1012DAB0
// Name: public: virtual bool CParticleCollision::MoveParticle(class Vector __near &,class Vector __near &,float __near *,float,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CParticleCollision::MoveParticle(
        CParticleCollision *this,
        Vector *origin,
        Vector *velocity,
        float *rollDelta,
        float timeDelta,
        CGameTrace *pTrace)
{
  bool v6; // zf
  bool v8; // cc
  float x; // xmm4_4
  float y; // xmm1_4
  float z; // xmm0_4
  float fraction; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  CParticleCollision *v19; // edx
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm6_4
  float v23; // xmm0_4
  float v24; // xmm4_4
  float v25; // xmm5_4
  double v26; // st7
  Vector testPosition; // [esp+24h] [ebp-10h] BYREF
  CParticleCollision *v28; // [esp+30h] [ebp-4h]
  IHandleEntity savedregs; // [esp+34h] [ebp+0h] BYREF

  v6 = vec3_origin.x == velocity->x;
  v28 = this;
  if ( v6 && vec3_origin.y == velocity->y && vec3_origin.z == velocity->z )
    return 0;
  velocity->z = velocity->z - (float)(this->m_flGravity * timeDelta);
  v8 = this->m_nActivePlanes <= 0;
  x = origin->x + (float)(velocity->x * timeDelta);
  y = origin->y + (float)(velocity->y * timeDelta);
  z = origin->z + (float)(velocity->z * timeDelta);
  testPosition.x = x;
  testPosition.y = y;
  testPosition.z = z;
  if ( v8 )
    goto LABEL_16;
  this->TraceLine(this, a2: origin, a3: &testPosition, a4: pTrace, a5: true);
  if ( pTrace->fraction == 1.0
    || (UTIL_TraceLine(
          a1: &savedregs,
          a2: (int)velocity,
          vecAbsStart: origin,
          vecAbsEnd: &testPosition,
          mask: 0x400Bu,
          ignore: nullptr,
          collisionGroup: 0,
          ptr: pTrace),
        (fraction = pTrace->fraction) == 1.0) )
  {
    z = testPosition.z;
    y = testPosition.y;
    x = testPosition.x;
LABEL_16:
    origin->x = x;
    origin->y = y;
    origin->z = z;
    return 0;
  }
  if ( pTrace->plane.normal.z >= 0.5 && COERCE_FLOAT(LODWORD(velocity->z) & _mask__AbsFloat_) <= 48.0 )
  {
    v13 = (float)(fraction - 0.0099999998) * timeDelta;
    v14 = velocity->y * v13;
    v15 = velocity->z * v13;
    origin->x = origin->x + (float)(velocity->x * v13);
    origin->y = origin->y + v14;
    origin->z = origin->z + v15;
    *velocity = vec3_origin;
    if ( rollDelta != nullptr )
    {
      *rollDelta = 0.0;
      return 0;
    }
    return 0;
  }
  v16 = (float)(fraction - 0.0099999998) * timeDelta;
  v17 = velocity->y * v16;
  v18 = velocity->z * v16;
  v19 = v28;
  origin->x = origin->x + (float)(velocity->x * v16);
  origin->y = origin->y + v17;
  origin->z = origin->z + v18;
  v20 = velocity->y;
  v21 = velocity->x;
  v22 = velocity->z;
  v23 = (float)((float)((float)(pTrace->plane.normal.y * v20) + (float)(pTrace->plane.normal.x * velocity->x))
              + (float)(pTrace->plane.normal.z * v22))
      * -2.0;
  v24 = pTrace->plane.normal.x * v23;
  v25 = pTrace->plane.normal.z * v23;
  velocity->y = v20 + (float)(pTrace->plane.normal.y * v23);
  velocity->x = v21 + v24;
  velocity->z = v22 + v25;
  v26 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
          a1: random,
          a2: v19->m_flCollisionDampen - 0.1,
          a3: v19->m_flCollisionDampen + 0.1);
  velocity->x = velocity->x * v26;
  velocity->y = velocity->y * v26;
  velocity->z = v26 * velocity->z;
  if ( rollDelta != nullptr )
    *rollDelta = *rollDelta * -0.25;
  return 1;
}
