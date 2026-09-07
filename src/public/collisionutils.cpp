// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/collisionutils.cpp
// Functions: 34
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1014C0F0
// Name: bool IntersectRayWithBox(struct Ray_t const __near &,class VectorAligned const __near &,class VectorAligned const __near &,class VectorAligned const __near &,class CGameTrace restrict __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IntersectRayWithBox(
        const Ray_t *ray,
        __m128 *inInvDelta,
        __m128 *inBoxMins,
        __m128 *inBoxMaxs,
        CGameTrace *pTrace)
{
  __m128 v5; // xmm5
  VectorAligned m_Delta; // xmm6
  VectorAligned m_Extents; // xmm1
  __m128 v8; // xmm2
  __m128 v9; // xmm2
  __m128 v10; // xmm5
  __m128 v11; // xmm1
  __m128 v12; // xmm4
  __m128 v13; // xmm3
  __m128 v14; // xmm0
  __m128 v15; // xmm4
  __m128 v16; // xmm0
  __m128 v17; // xmm3
  __m128 v18; // xmm0
  __m128 v19; // xmm6
  __m128 v20; // xmm3
  __m128 v21; // xmm6
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  int v25; // edx
  __m128 v26; // xmm0
  __m128 v27; // xmm1
  __m128 v28; // xmm5
  __m128 v29; // xmm0
  __m128 v30; // xmm2
  __m128 v31; // xmm1
  __m128 v32; // xmm3
  __m128 v33; // xmm4
  __m128 v34; // xmm2
  __m128 v35; // xmm5
  __m128 v36; // xmm0
  float v37; // xmm6_4
  __m128 v38; // xmm5
  __m128 v39; // xmm2
  bool v40; // dl
  unsigned __int8 v41; // al
  float v42; // xmm1_4
  float v43; // xmm2_4
  float v44; // xmm0_4
  float v46; // xmm2_4
  float v47; // xmm1_4
  unsigned __int8 v48; // dl
  float fraction; // xmm3_4
  float v50; // xmm0_4
  float v51; // xmm1_4
  float v52; // xmm2_4
  float v53; // xmm0_4
  float v54; // xmm4_4
  float z; // xmm0_4
  __m128 v56; // [esp-Ch] [ebp-6Ch]
  unsigned int v57; // [esp-Ch] [ebp-6Ch]
  __m128 faceId_4; // [esp+4h] [ebp-5Ch]
  __m128 v59; // [esp+14h] [ebp-4Ch]
  __m128 invDelta_4a; // [esp+24h] [ebp-3Ch]
  __m128 invDelta_4; // [esp+24h] [ebp-3Ch]
  __m128 lastIn_4; // [esp+34h] [ebp-2Ch]
  __m128 lastIn_4a; // [esp+34h] [ebp-2Ch]
  VectorAligned *p_m_Delta; // [esp+50h] [ebp-10h]

  v5 = *inBoxMaxs;
  m_Delta = ray->m_Delta;
  m_Extents = ray->m_Extents;
  p_m_Delta = &ray->m_Delta;
  v8 = *inBoxMins;
  pTrace->fraction = 1.0;
  v9 = _mm_sub_ps(_mm_sub_ps(v8, (__m128)ray->m_Start), (__m128)m_Extents);
  v10 = _mm_add_ps(_mm_sub_ps(v5, (__m128)ray->m_Start), (__m128)m_Extents);
  v11 = _mm_cmplt_ps(v10, Four_Zeros);
  v12 = _mm_cmplt_ps(v10, (__m128)m_Delta);
  v13 = _mm_cmplt_ps(Four_Zeros, v9);
  v14 = _mm_cmplt_ps((__m128)m_Delta, v9);
  *(_WORD *)&pTrace->allsolid = 0;
  lastIn_4 = v13;
  if ( _mm_movemask_ps(_mm_and_ps(_mm_or_ps(_mm_and_ps(v12, v11), _mm_and_ps(v14, v13)), *(__m128 *)g_SIMD_clear_wmask)) == 0 )
  {
    v59 = *inInvDelta;
    invDelta_4a = _mm_mul_ps(*inInvDelta, v10);
    v15 = _mm_or_ps(_mm_xor_ps(v12, v11), _mm_xor_ps(v14, v13));
    v16 = _mm_mul_ps(*inInvDelta, v9);
    v17 = _mm_max_ps(v16, invDelta_4a);
    faceId_4 = _mm_andnot_ps(v15, Four_Negative_FLT_MAX);
    v18 = _mm_or_ps(_mm_and_ps(_mm_min_ps(v16, invDelta_4a), v15), faceId_4);
    v19 = _mm_andnot_ps(v15, Four_FLT_MAX);
    v20 = _mm_or_ps(_mm_and_ps(v17, v15), v19);
    v56 = v19;
    v21 = _mm_min_ps(_mm_min_ps(v20, _mm_shuffle_ps(v20, v20, 57)), _mm_shuffle_ps(v20, v20, 78));
    v22 = _mm_max_ps(_mm_max_ps(v18, _mm_shuffle_ps(v18, v18, 57)), _mm_shuffle_ps(v18, v18, 78));
    if ( _mm_movemask_ps(
           _mm_cmpeq_ps(
             _mm_cmplt_ps(
               _mm_min_ps(_mm_shuffle_ps(v21, v21, 0), Four_Ones),
               _mm_max_ps(_mm_shuffle_ps(v22, v22, 0), Four_Zeros)),
             Four_Zeros)) == 15 )
    {
      v23 = _mm_mul_ps(_mm_sub_ps(v9, Four_DistEpsilons), v59);
      v24 = _mm_mul_ps(_mm_add_ps(Four_DistEpsilons, v10), v59);
      v25 = _mm_movemask_ps(_mm_and_ps(_mm_or_ps(v11, lastIn_4), *(__m128 *)g_SIMD_clear_wmask));
      v26 = _mm_cmple_ps(v23, v24);
      v27 = _mm_andnot_ps(v26, *(__m128 *)g_CubeFaceIndex1);
      v28 = _mm_and_ps(*(__m128 *)g_CubeFaceIndex0, v26);
      v29 = _mm_or_ps(_mm_and_ps(_mm_min_ps(v23, v24), v15), faceId_4);
      v30 = _mm_or_ps(_mm_and_ps(_mm_max_ps(v23, v24), v15), v56);
      v31 = _mm_or_ps(v27, v28);
      v32 = _mm_shuffle_ps(v29, v29, 57);
      v33 = _mm_min_ps(_mm_min_ps(v30, _mm_shuffle_ps(v30, v30, 57)), _mm_shuffle_ps(v30, v30, 78));
      v34 = _mm_max_ps(v29, v32);
      v35 = _mm_cmplt_ps(v32, v29);
      v36 = _mm_shuffle_ps(v29, v29, 78);
      v37 = _mm_andnot_ps(v35, _mm_shuffle_ps(v31, v31, 57)).m128_f32[0];
      v32.m128_i32[0] = v31.m128_i32[0] & v35.m128_i32[0];
      v38 = _mm_cmplt_ps(v36, v34);
      v39 = _mm_max_ps(v34, v36);
      v57 = _mm_andnot_ps(v38, _mm_shuffle_ps(v31, v31, 78)).m128_u32[0]
          | (v32.m128_i32[0] | LODWORD(v37)) & v38.m128_i32[0];
      lastIn_4a = _mm_min_ps(_mm_shuffle_ps(v33, v33, 0), Four_Ones);
      v40 = v25 != 0;
      invDelta_4 = _mm_max_ps(_mm_shuffle_ps(v39, v39, 0), Four_Zeros);
      if ( _mm_movemask_ps(_mm_cmpeq_ps(_mm_cmplt_ps(lastIn_4a, invDelta_4), Four_Zeros)) == 15 )
      {
        v41 = v57;
        if ( !v40 || ray->m_IsRay && pTrace->fractionleftsolid > invDelta_4.m128_f32[0] )
        {
          v42 = ray->m_StartOffset.y + ray->m_Start.y;
          v43 = ray->m_StartOffset.z + ray->m_Start.z;
          pTrace->fraction = 0.0;
          v44 = ray->m_Start.x + ray->m_StartOffset.x;
          pTrace->startpos.x = v44;
          pTrace->startpos.y = v42;
          pTrace->startpos.z = v43;
          pTrace->startsolid = true;
          pTrace->contents = 1;
          pTrace->endpos.x = v44;
          pTrace->endpos.y = pTrace->startpos.y;
          pTrace->endpos.z = pTrace->startpos.z;
          if ( lastIn_4a.m128_f32[0] < 1.0 )
          {
            if ( lastIn_4a.m128_f32[0] > pTrace->fractionleftsolid )
            {
              v46 = ray->m_Delta.y * lastIn_4a.m128_f32[0];
              v47 = (float)(ray->m_Delta.z * lastIn_4a.m128_f32[0]) + pTrace->startpos.z;
              LODWORD(pTrace->fractionleftsolid) = lastIn_4a.m128_i32[0];
              pTrace->startpos.x = (float)(lastIn_4a.m128_f32[0] * p_m_Delta->x) + pTrace->startpos.x;
              pTrace->startpos.y = pTrace->startpos.y + v46;
              pTrace->startpos.z = v47;
            }
            return 1;
          }
          else
          {
            pTrace->allsolid = true;
            return 1;
          }
        }
        if ( invDelta_4.m128_f32[0] <= 1.0 )
        {
          LODWORD(pTrace->fraction) = invDelta_4.m128_i32[0];
          pTrace->plane.normal = vec3_origin;
          if ( v57 < 3 )
          {
            v48 = signbits[v57];
            LODWORD(pTrace->plane.dist) = inBoxMins->m128_i32[v57] ^ _mask__NegFloat_;
            *((_DWORD *)&pTrace->plane.normal.x + v57) = -1082130432;
            pTrace->plane.signbits = v48;
          }
          else
          {
            v41 = v57 - 3;
            pTrace->plane.dist = inBoxMaxs->m128_f32[v57 - 3];
            *((_DWORD *)&pTrace->endpos.x + v57) = 1065353216;
            pTrace->plane.signbits = 0;
          }
          fraction = pTrace->fraction;
          v50 = ray->m_Start.x + ray->m_StartOffset.x;
          v51 = ray->m_StartOffset.y + ray->m_Start.y;
          v52 = ray->m_StartOffset.z + ray->m_Start.z;
          pTrace->plane.type = v41;
          pTrace->contents = 1;
          if ( fraction == 1.0 )
          {
            pTrace->endpos.x = v50 + p_m_Delta->x;
            pTrace->endpos.y = ray->m_Delta.y + v51;
            v53 = ray->m_Delta.z + v52;
          }
          else
          {
            v54 = (float)(fraction * p_m_Delta->x) + v50;
            pTrace->endpos.y = (float)(ray->m_Delta.y * fraction) + v51;
            z = ray->m_Delta.z;
            pTrace->endpos.x = v54;
            v53 = (float)(z * fraction) + v52;
          }
          pTrace->endpos.z = v53;
          return 1;
        }
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101541B0
// Name: ComputeBoxOffset
// Source: json
//------------------------------------------------------------------------------
long double __usercall ComputeBoxOffset@<st0>(const Ray_t *ray@<eax>)
{
  long double v2; // st7
  double v3; // st6

  if ( ray->m_IsRay )
    return 0.001;
  v2 = fabs(ray->m_Extents.y * ray->m_Delta.y)
     + fabs(ray->m_Extents.x * ray->m_Delta.x)
     + fabs(ray->m_Extents.z * ray->m_Delta.z);
  if ( (float)((float)((float)(ray->m_Delta.y * ray->m_Delta.y) + (float)(ray->m_Delta.x * ray->m_Delta.x))
             + (float)(ray->m_Delta.z * ray->m_Delta.z)) >= 1.0 )
    v3 = 1.0
       / (ray->m_Delta.z * ray->m_Delta.z + ray->m_Delta.y * ray->m_Delta.y + (float)(ray->m_Delta.x * ray->m_Delta.x));
  else
    v3 = 1.0 / 1.0;
  return v2 * v3 + 0.001;
}

//------------------------------------------------------------------------------
// Address: 0x10154250
// Name: bool ComputeIntersectionBarycentricCoordinates(struct Ray_t const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float __near &,float __near &,float __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ComputeIntersectionBarycentricCoordinates(
        const Ray_t *ray,
        const Vector *v1,
        const Vector *v2,
        const Vector *v3,
        float *u,
        float *v,
        float *t)
{
  float v8; // xmm6_4
  float v9; // xmm2_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  float v12; // xmm1_4
  float v13; // xmm3_4
  float v14; // xmm6_4
  float v15; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm3_4
  float v22; // xmm7_4
  float v23; // xmm0_4
  float v24; // xmm5_4
  float v25; // xmm1_4
  float v26; // xmm4_4
  float v27; // xmm6_4
  float *v28; // edx
  float dirCrossEdge2_8; // [esp+8h] [ebp-1Ch]
  float edge1_8; // [esp+14h] [ebp-10h]
  float edge2; // [esp+18h] [ebp-Ch]
  float edge2_4; // [esp+1Ch] [ebp-8h]
  float edge2_8; // [esp+20h] [ebp-4h]
  float boxta; // [esp+30h] [ebp+Ch]
  float boxtb; // [esp+30h] [ebp+Ch]
  float boxt; // [esp+30h] [ebp+Ch]

  v8 = v3->z - v1->z;
  v9 = v3->x - v1->x;
  v10 = v2->x - v1->x;
  v11 = v2->y - v1->y;
  edge1_8 = v2->z - v1->z;
  v12 = v3->y - v1->y;
  boxta = ray->m_Delta.y;
  edge2_4 = v12;
  v13 = (float)(boxta * v8) - (float)(ray->m_Delta.z * v12);
  edge2_8 = v8;
  v14 = (float)(ray->m_Delta.z * v9) - (float)(ray->m_Delta.x * v8);
  edge2 = v9;
  dirCrossEdge2_8 = (float)(ray->m_Delta.x * v12) - (float)(boxta * v9);
  v15 = (float)((float)(v14 * v11) + (float)(v13 * v10)) + (float)(dirCrossEdge2_8 * edge1_8);
  if ( fabs(v15) < 0.000001 )
    return false;
  v17 = ray->m_Start.y - v1->y;
  v18 = 1.0 / v15;
  v19 = ray->m_Start.x - v1->x;
  boxtb = v18;
  v20 = ray->m_Start.z - v1->z;
  *u = (float)((float)((float)(v17 * v14) + (float)(v19 * v13)) + (float)(v20 * dirCrossEdge2_8)) * boxtb;
  v21 = (float)(v17 * edge1_8) - (float)(v20 * v11);
  v22 = v19 * edge1_8;
  v23 = v19 * v11;
  v24 = boxtb;
  v25 = (float)(v20 * v10) - v22;
  v26 = v23 - (float)(v17 * v10);
  *v = (float)((float)((float)(ray->m_Delta.x * v21) + (float)(v25 * ray->m_Delta.y)) + (float)(ray->m_Delta.z * v26))
     * boxtb;
  if ( t == nullptr )
    return true;
  boxt = ComputeBoxOffset(ray);
  v27 = (float)((float)((float)(v25 * edge2_4) + (float)(v21 * edge2)) + (float)(v26 * edge2_8)) * v24;
  *v28 = v27;
  return COERCE_FLOAT(LODWORD(boxt) ^ _mask__NegFloat_) <= v27 && v27 <= (float)(boxt + 1.0);
}

//------------------------------------------------------------------------------
// Address: 0x10154450
// Name: bool IsBoxIntersectingSphere(class Vector const __near &,class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsBoxIntersectingSphere(const Vector *boxMin, const Vector *boxMax, const Vector *center, float radius)
{
  float x; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float y; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm2_4
  float z; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm2_4

  x = center->x;
  v5 = 0.0;
  if ( boxMin->x <= center->x )
  {
    if ( x <= boxMax->x )
      goto LABEL_6;
    v6 = boxMax->x - x;
  }
  else
  {
    v6 = x - boxMin->x;
  }
  v5 = v6 * v6;
LABEL_6:
  y = center->y;
  v8 = boxMin->y;
  if ( v8 <= y )
  {
    v9 = boxMax->y;
    if ( y > v9 )
      v5 = (float)((float)(v9 - y) * (float)(v9 - y)) + v5;
  }
  else
  {
    v5 = (float)((float)(y - v8) * (float)(y - v8)) + v5;
  }
  z = center->z;
  v11 = boxMin->z;
  if ( v11 <= z )
  {
    v12 = boxMax->z;
    if ( z > v12 )
      v5 = v5 + (float)((float)(v12 - z) * (float)(v12 - z));
  }
  else
  {
    v5 = v5 + (float)((float)(z - v11) * (float)(z - v11));
  }
  return (float)(radius * radius) > v5;
}

//------------------------------------------------------------------------------
// Address: 0x10154510
// Name: bool IsBoxIntersectingSphereExtents(class Vector const __near &,class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsBoxIntersectingSphereExtents(
        const Vector *boxCenter,
        const Vector *boxHalfDiag,
        const Vector *center,
        float radius)
{
  float v5; // xmm0_4
  float y; // xmm2_4
  float z; // xmm2_4
  float flDiff; // [esp+10h] [ebp+10h]
  float flDiffa; // [esp+10h] [ebp+10h]
  float flDiffb; // [esp+10h] [ebp+10h]

  v5 = 0.0;
  flDiff = fabs(center->x - boxCenter->x);
  if ( flDiff > boxHalfDiag->x )
    v5 = (float)(flDiff - boxHalfDiag->x) * (float)(flDiff - boxHalfDiag->x);
  y = boxHalfDiag->y;
  flDiffa = fabs(center->y - boxCenter->y);
  if ( flDiffa > y )
    v5 = (float)((float)(flDiffa - y) * (float)(flDiffa - y)) + v5;
  z = boxHalfDiag->z;
  flDiffb = fabs(center->z - boxCenter->z);
  if ( flDiffb > z )
    v5 = v5 + (float)((float)(flDiffb - z) * (float)(flDiffb - z));
  return (float)(radius * radius) > v5;
}

//------------------------------------------------------------------------------
// Address: 0x101545B0
// Name: bool IsCircleIntersectingRectangle(class Vector2D const __near &,class Vector2D const __near &,class Vector2D const __near &,float)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsCircleIntersectingRectangle(
        const Vector2D *boxMin,
        const Vector2D *boxMax,
        const Vector2D *center,
        float radius)
{
  float x; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float y; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm2_4

  x = center->x;
  v5 = 0.0;
  if ( boxMin->x <= center->x )
  {
    if ( x <= boxMax->x )
      goto LABEL_6;
    v6 = boxMax->x - x;
  }
  else
  {
    v6 = x - boxMin->x;
  }
  v5 = v6 * v6;
LABEL_6:
  y = center->y;
  v8 = boxMin->y;
  if ( v8 <= y )
  {
    v9 = boxMax->y;
    if ( y > v9 )
      v5 = v5 + (float)((float)(v9 - y) * (float)(v9 - y));
  }
  else
  {
    v5 = v5 + (float)((float)(y - v8) * (float)(y - v8));
  }
  return (float)(radius * radius) > v5;
}

//------------------------------------------------------------------------------
// Address: 0x10154640
// Name: bool IsSphereIntersectingCone(class Vector const __near &,float,class Vector const __near &,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsSphereIntersectingCone(
        const Vector *sphereCenter,
        float sphereRadius,
        const Vector *coneOrigin,
        const Vector *coneNormal,
        float coneSine,
        float coneCosine)
{
  float y; // xmm0_4
  float z; // xmm5_4
  float v8; // xmm1_4
  float v9; // xmm3_4
  bool result; // al
  float backCenter; // [esp+0h] [ebp-24h]
  float backCenter_4; // [esp+4h] [ebp-20h]
  float backCenter_8; // [esp+8h] [ebp-1Ch]
  float v14; // [esp+Ch] [ebp-18h]
  float x; // [esp+10h] [ebp-14h]
  float v16; // [esp+14h] [ebp-10h]

  y = coneNormal->y;
  z = coneNormal->z;
  backCenter_8 = coneOrigin->y;
  x = coneOrigin->x;
  backCenter = coneOrigin->z;
  v16 = sphereCenter->x;
  v8 = sphereCenter->x - (float)(coneOrigin->x - (float)(coneNormal->x * (float)(sphereRadius / coneSine)));
  v14 = sphereCenter->y;
  backCenter_4 = sphereCenter->z;
  result = false;
  if ( (float)((float)((float)(y * (float)(v14 - (float)(backCenter_8 - (float)(y * (float)(sphereRadius / coneSine)))))
                     + (float)(coneNormal->x * v8))
             + (float)(z * (float)(backCenter_4 - (float)(backCenter - (float)(z * (float)(sphereRadius / coneSine)))))) >= (float)(fsqrt((float)((float)((float)(v14 - (float)(backCenter_8 - (float)(y * (float)(sphereRadius / coneSine)))) * (float)(v14 - (float)(backCenter_8 - (float)(y * (float)(sphereRadius / coneSine))))) + (float)((float)(backCenter_4 - (float)(backCenter - (float)(z * (float)(sphereRadius / coneSine)))) * (float)(backCenter_4 - (float)(backCenter - (float)(z * (float)(sphereRadius / coneSine)))))) + (float)(v8 * v8)) * coneCosine) )
  {
    v9 = fsqrt(
           (float)((float)((float)(v14 - backCenter_8) * (float)(v14 - backCenter_8))
                 + (float)((float)(backCenter_4 - backCenter) * (float)(backCenter_4 - backCenter)))
         + (float)((float)(v16 - x) * (float)(v16 - x)));
    if ( COERCE_FLOAT(
           COERCE_UNSIGNED_INT(
             (float)((float)(y * (float)(v14 - backCenter_8)) + (float)(coneNormal->x * (float)(v16 - x)))
           + (float)(z * (float)(backCenter_4 - backCenter)))
         ^ _mask__NegFloat_) < (float)(v9 * coneSine)
      || sphereRadius >= v9 )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101547E0
// Name: bool IsPointInBox(class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsPointInBox(const Vector *pt, const Vector *boxMin, const Vector *boxMax)
{
  float y; // xmm0_4
  float z; // xmm0_4
  bool result; // al

  result = false;
  if ( pt->x <= boxMax->x && boxMin->x <= pt->x )
  {
    y = pt->y;
    if ( y <= boxMax->y && boxMin->y <= y )
    {
      z = pt->z;
      if ( z <= boxMax->z && boxMin->z <= z )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10154830
// Name: bool IsBoxIntersectingBox(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsBoxIntersectingBox(
        const Vector *boxMin1,
        const Vector *boxMax1,
        const Vector *boxMin2,
        const Vector *boxMax2)
{
  return boxMin1->x <= boxMax2->x
      && boxMin2->x <= boxMax1->x
      && boxMin1->y <= boxMax2->y
      && boxMin2->y <= boxMax1->y
      && boxMin1->z <= boxMax2->z
      && boxMin2->z <= boxMax1->z;
}

//------------------------------------------------------------------------------
// Address: 0x10154890
// Name: bool IsBoxIntersectingRay(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
bool __fastcall IsBoxIntersectingRay(
        const Vector *boxMin,
        const Vector *boxMax,
        const Vector *origin,
        const Vector *vecDelta,
        unsigned int flTolerance)
{
  __m128 v5; // xmm0
  __m128 v6; // xmm5
  __m128 v7; // xmm4
  __m128 v8; // xmm2
  __m128 v9; // xmm3
  __m128 v11; // xmm1
  __m128 v12; // xmm0
  __m128 v13; // xmm7
  __m128 v14; // xmm1
  __m128 v15; // xmm0
  __m128 v16; // xmm2
  __m128 v17; // xmm0
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm0
  __m128 v22; // xmm2
  __m128 v23; // [esp-Ch] [ebp-3Ch]
  __m128 startOutMins_4; // [esp+4h] [ebp-2Ch]

  v5 = _mm_shuffle_ps((__m128)flTolerance, (__m128)flTolerance, 0);
  v6 = _mm_add_ps(_mm_sub_ps(*(__m128 *)&boxMax->x, *(__m128 *)&origin->x), v5);
  v7 = _mm_sub_ps(_mm_sub_ps(*(__m128 *)&boxMin->x, *(__m128 *)&origin->x), v5);
  v8 = _mm_cmplt_ps(v6, *(__m128 *)&vecDelta->x);
  startOutMins_4 = _mm_cmplt_ps(v6, Four_Zeros);
  v9 = _mm_cmplt_ps(*(__m128 *)&vecDelta->x, v7);
  v23 = _mm_cmplt_ps(Four_Zeros, v7);
  if ( _mm_movemask_ps(_mm_and_ps(_mm_or_ps(_mm_and_ps(v8, startOutMins_4), _mm_and_ps(v9, v23)), *(__m128 *)g_SIMD_clear_wmask)) != 0 )
    return false;
  v11 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(Four_Zeros, *(__m128 *)&vecDelta->x), Four_Epsilons), *(__m128 *)&vecDelta->x);
  v12 = _mm_rcp_ps(v11);
  v13 = _mm_mul_ps(_mm_mul_ps(v12, v12), v11);
  v14 = _mm_or_ps(_mm_xor_ps(v8, startOutMins_4), _mm_xor_ps(v9, v23));
  v15 = _mm_sub_ps(_mm_add_ps(v12, v12), v13);
  v16 = _mm_mul_ps(v15, v7);
  v17 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v15, v6), v14), _mm_andnot_ps(v14, Four_FLT_MAX));
  v18 = _mm_or_ps(_mm_and_ps(v16, v14), _mm_andnot_ps(v14, Four_Negative_FLT_MAX));
  v19 = _mm_max_ps(v18, v17);
  v20 = _mm_min_ps(v18, v17);
  v21 = _mm_min_ps(_mm_min_ps(v19, _mm_shuffle_ps(v19, v19, 57)), _mm_shuffle_ps(v19, v19, 78));
  v22 = _mm_max_ps(_mm_max_ps(v20, _mm_shuffle_ps(v20, v20, 57)), _mm_shuffle_ps(v20, v20, 78));
  return _mm_movemask_ps(
           _mm_cmpeq_ps(
             _mm_cmplt_ps(
               _mm_min_ps(_mm_shuffle_ps(v21, v21, 0), Four_Ones),
               _mm_max_ps(_mm_shuffle_ps(v22, v22, 0), Four_Zeros)),
             Four_Zeros)) == 15;
}

//------------------------------------------------------------------------------
// Address: 0x101549F0
// Name: bool IsBoxIntersectingRay(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
bool __fastcall IsBoxIntersectingRay(
        const Vector *boxMin,
        const Vector *boxMax,
        const Vector *origin,
        const Vector *vecDelta,
        const Vector *vecInvDelta,
        unsigned int flTolerance)
{
  __m128 v6; // xmm0
  __m128 v7; // xmm4
  __m128 v8; // xmm6
  __m128 v9; // xmm2
  __m128 v10; // xmm3
  __m128 v11; // xmm5
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  __m128 v15; // xmm3
  __m128 v16; // xmm1
  __m128 v17; // xmm0
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  __m128 v20; // xmm1

  v6 = _mm_sub_ps(*(__m128 *)&boxMin->x, *(__m128 *)&origin->x);
  v7 = _mm_sub_ps(*(__m128 *)&boxMax->x, *(__m128 *)&origin->x);
  v8 = _mm_cmplt_ps(v7, Four_Zeros);
  v9 = _mm_cmplt_ps(v7, *(__m128 *)&vecDelta->x);
  v10 = _mm_cmplt_ps(*(__m128 *)&vecDelta->x, v6);
  v11 = _mm_cmplt_ps(Four_Zeros, v6);
  if ( _mm_movemask_ps(_mm_and_ps(_mm_or_ps(_mm_and_ps(v9, v8), _mm_and_ps(v10, v11)), *(__m128 *)g_SIMD_clear_wmask)) != 0 )
    return false;
  v13 = _mm_shuffle_ps((__m128)flTolerance, (__m128)flTolerance, 0);
  v14 = _mm_or_ps(_mm_xor_ps(v9, v8), _mm_xor_ps(v10, v11));
  v15 = _mm_or_ps(
          _mm_andnot_ps(v14, Four_Negative_FLT_MAX),
          _mm_and_ps(_mm_mul_ps(_mm_sub_ps(v6, v13), *(__m128 *)&vecInvDelta->x), v14));
  v16 = _mm_or_ps(
          _mm_and_ps(_mm_mul_ps(_mm_add_ps(v13, v7), *(__m128 *)&vecInvDelta->x), v14),
          _mm_andnot_ps(v14, Four_FLT_MAX));
  v17 = _mm_min_ps(v15, v16);
  v18 = _mm_max_ps(v15, v16);
  v19 = _mm_min_ps(_mm_min_ps(v18, _mm_shuffle_ps(v18, v18, 57)), _mm_shuffle_ps(v18, v18, 78));
  v20 = _mm_max_ps(_mm_max_ps(v17, _mm_shuffle_ps(v17, v17, 57)), _mm_shuffle_ps(v17, v17, 78));
  return _mm_movemask_ps(
           _mm_cmpeq_ps(
             _mm_cmplt_ps(
               _mm_min_ps(_mm_shuffle_ps(v19, v19, 0), Four_Ones),
               _mm_max_ps(_mm_shuffle_ps(v20, v20, 0), Four_Zeros)),
             Four_Zeros)) == 15;
}

//------------------------------------------------------------------------------
// Address: 0x10154B00
// Name: bool IsBoxIntersectingRay(class Vector const __near &,class Vector const __near &,struct Ray_t const __near &,float)
// Source: json
//------------------------------------------------------------------------------
bool __fastcall IsBoxIntersectingRay(
        const Vector *vecBoxMin,
        const Vector *vecBoxMax,
        const Ray_t *ray,
        unsigned int flTolerance)
{
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  float v9; // xmm5_4
  float v10; // xmm1_4
  float v11; // xmm6_4
  float v12; // xmm2_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  Vector boxMin; // [esp+4h] [ebp-18h] BYREF
  Vector boxMax; // [esp+10h] [ebp-Ch] BYREF

  x = ray->m_Extents.x;
  if ( ray->m_IsSwept )
  {
    v14 = vecBoxMin->y - ray->m_Extents.y;
    v15 = vecBoxMin->z - ray->m_Extents.z;
    v16 = vecBoxMin->x - x;
    boxMax.x = x + vecBoxMax->x;
    boxMax.y = vecBoxMax->y + ray->m_Extents.y;
    v17 = vecBoxMax->z + ray->m_Extents.z;
    boxMin.x = v16;
    boxMin.y = v14;
    boxMin.z = v15;
    boxMax.z = v17;
    return IsBoxIntersectingRay(&boxMin, &boxMax, origin: &ray->m_Start, vecDelta: &ray->m_Delta, flTolerance);
  }
  else
  {
    y = ray->m_Extents.y;
    z = ray->m_Extents.z;
    v7 = ray->m_Start.x - x;
    v8 = x + ray->m_Start.x;
    v9 = ray->m_Start.y - y;
    v10 = y + ray->m_Start.y;
    v11 = ray->m_Start.z - z;
    v12 = z + ray->m_Start.z;
    if ( *(float *)&flTolerance != 0.0 )
    {
      v7 = v7 - *(float *)&flTolerance;
      v9 = v9 - *(float *)&flTolerance;
      v11 = v11 - *(float *)&flTolerance;
      v8 = v8 + *(float *)&flTolerance;
      v10 = v10 + *(float *)&flTolerance;
      v12 = v12 + *(float *)&flTolerance;
    }
    return vecBoxMin->x <= v8
        && v7 <= vecBoxMax->x
        && vecBoxMin->y <= v10
        && v9 <= vecBoxMax->y
        && vecBoxMin->z <= v12
        && v11 <= vecBoxMax->z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10154C30
// Name: bool IsBoxIntersectingRay(union __m128 const __near &,union __m128 const __near &,union __m128 const __near &,union __m128 const __near &,union __m128 const __near &,union __m128 const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __fastcall IsBoxIntersectingRay(
        const __m128 *inBoxMin,
        const __m128 *inBoxMax,
        const __m128 *origin,
        const __m128 *delta,
        const __m128 *invDelta,
        const __m128 *vTolerance)
{
  __m128 v6; // xmm3
  __m128 v7; // xmm0
  __m128 v9; // xmm0
  __m128 v10; // xmm2
  __m128 v11; // xmm1
  __m128 v12; // xmm0
  __m128 v13; // xmm2
  __m128 v14; // xmm1

  v6 = _mm_sub_ps(*inBoxMax, *origin);
  v7 = _mm_sub_ps(*inBoxMin, *origin);
  if ( _mm_movemask_ps(
         _mm_and_ps(
           _mm_or_ps(
             _mm_and_ps(_mm_cmplt_ps(v6, *delta), _mm_cmplt_ps(v6, Four_Zeros)),
             _mm_and_ps(_mm_cmplt_ps(*delta, v7), _mm_cmplt_ps(Four_Zeros, v7))),
           *(__m128 *)g_SIMD_clear_wmask)) != 0 )
    return false;
  v9 = _mm_mul_ps(_mm_sub_ps(v7, *vTolerance), *invDelta);
  v10 = _mm_mul_ps(_mm_add_ps(*vTolerance, v6), *invDelta);
  v11 = _mm_max_ps(v9, v10);
  v12 = _mm_min_ps(v9, v10);
  v13 = _mm_min_ps(_mm_min_ps(v11, _mm_shuffle_ps(v11, v11, 57)), _mm_shuffle_ps(v11, v11, 78));
  v14 = _mm_max_ps(_mm_max_ps(v12, _mm_shuffle_ps(v12, v12, 57)), _mm_shuffle_ps(v12, v12, 78));
  return _mm_movemask_ps(
           _mm_cmpeq_ps(
             _mm_cmplt_ps(
               _mm_min_ps(_mm_shuffle_ps(v13, v13, 0), Four_Ones),
               _mm_max_ps(_mm_shuffle_ps(v14, v14, 0), Four_Zeros)),
             Four_Zeros)) == 15;
}

//------------------------------------------------------------------------------
// Address: 0x10154D00
// Name: bool IntersectRayWithRay(struct Ray_t const __near &,struct Ray_t const __near &,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IntersectRayWithRay(const Ray_t *ray0, const Ray_t *ray1, float *t, float *s)
{
  float y; // ecx
  float z; // edx
  float v7; // ecx
  float v8; // edx
  float v9; // xmm6_4
  float v10; // xmm2_4
  float v11; // xmm4_4
  float v13; // xmm5_4
  float v14; // xmm7_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm4_4
  float v21; // xmm5_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm3_4
  float x; // xmm4_4
  float v26; // xmm0_4
  float v27; // xmm0_4
  float v28; // xmm5_4
  float v29; // xmm0_4
  float v30; // xmm6_4
  float v0xv1; // [esp+14h] [ebp-28h]
  Vector v1; // [esp+20h] [ebp-1Ch] BYREF
  Vector v0; // [esp+2Ch] [ebp-10h] BYREF
  float lengthSq; // [esp+38h] [ebp-4h]
  float ray1a; // [esp+48h] [ebp+Ch]

  y = ray0->m_Delta.y;
  z = ray0->m_Delta.z;
  v0.x = ray0->m_Delta.x;
  v1.x = ray1->m_Delta.x;
  v0.y = y;
  v7 = ray1->m_Delta.y;
  v0.z = z;
  v8 = ray1->m_Delta.z;
  v1.y = v7;
  v1.z = v8;
  VectorNormalize(vec: &v0);
  VectorNormalize(vec: &v1);
  v9 = v1.z;
  v0xv1 = (float)(v1.z * v0.y) - (float)(v1.y * v0.z);
  v10 = (float)(v0.z * v1.x) - (float)(v1.z * v0.x);
  v11 = (float)(v1.y * v0.x) - (float)(v1.x * v0.y);
  lengthSq = (float)((float)(v10 * v10) + (float)(v0xv1 * v0xv1)) + (float)(v11 * v11);
  if ( lengthSq == 0.0 )
  {
    *t = 0.0;
    *s = 0.0;
    return false;
  }
  v13 = ray1->m_Start.x - ray0->m_Start.x;
  v14 = ray1->m_Start.z - ray0->m_Start.z;
  v15 = ray1->m_Start.y - ray0->m_Start.y;
  v16 = v15 * v0xv1;
  v17 = (float)(v14 * v0xv1) - (float)(v11 * v13);
  v18 = (float)(v15 * v11) - (float)(v14 * v10);
  ray1a = (float)(v10 * v13) - v16;
  v19 = v1.y;
  v20 = (float)((float)((float)-v17 * v1.y) + (float)((float)-v18 * v1.x)) + (float)((float)-ray1a * v1.z);
  v21 = (float)-v17 * v0.y;
  v22 = 1.0 / lengthSq;
  v23 = -v18;
  v24 = (float)(1.0 / lengthSq) * v20;
  x = v0.x;
  v26 = v23 * v0.x;
  *t = v24;
  v27 = v26 + v21;
  v28 = v0.z;
  v29 = (float)(v27 + (float)((float)-ray1a * v0.z)) * v22;
  *s = v29;
  v30 = v9 * v29;
  return (float)(ray0->m_Start.x + (float)(x * *t)) == (float)(ray1->m_Start.x + (float)(v1.x * v29))
      && (float)((float)(*t * v0.y) + ray0->m_Start.y) == (float)(ray1->m_Start.y + (float)(v19 * v29))
      && (float)(ray0->m_Start.z + (float)(v28 * *t)) == (float)(ray1->m_Start.z + v30);
}

//------------------------------------------------------------------------------
// Address: 0x10154F50
// Name: float IntersectRayWithPlane(class Vector const __near &,class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl IntersectRayWithPlane(const Vector *org, const Vector *dir, const Vector *normal, float dist)
{
  float x; // xmm2_4
  float z; // xmm3_4
  float denom; // [esp+14h] [ebp+Ch]
  float normala; // [esp+18h] [ebp+10h]

  x = normal->x;
  z = normal->z;
  normala = normal->y;
  denom = (float)((float)(dir->y * normala) + (float)(dir->x * x)) + (float)(dir->z * z);
  if ( denom == 0.0 )
    return 0.0;
  else
    return (dist - (org->y * normala + org->x * x + org->z * z)) * (1.0 / denom);
}

//------------------------------------------------------------------------------
// Address: 0x10154FE0
// Name: float IntersectRayWithAAPlane(class Vector const __near &,class Vector const __near &,int,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl IntersectRayWithAAPlane(
        const Vector *vecStart,
        const Vector *vecEnd,
        int nAxis,
        float flSign,
        float flDist)
{
  float v5; // xmm0_4
  int nAxisa; // [esp+10h] [ebp+10h]

  v5 = (float)(*(&vecEnd->x + nAxis) - *(&vecStart->x + nAxis)) * flSign;
  nAxisa = *((int *)&vecStart->x + nAxis);
  if ( v5 == 0.0 )
    return 0.0;
  else
    return (flDist - *(float *)&nAxisa * flSign) * (1.0 / v5);
}

//------------------------------------------------------------------------------
// Address: 0x10155030
// Name: bool IntersectRayWithBox(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,struct BoxTraceInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IntersectRayWithBox(
        const Vector *vecRayStart,
        const Vector *vecRayDelta,
        const Vector *boxMins,
        const Vector *boxMaxs,
        float flTolerance,
        BoxTraceInfo_t *pTrace)
{
  const Vector *v6; // ecx
  const Vector *v7; // edi
  int v8; // esi
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm1_4

  v6 = vecRayStart;
  v7 = boxMaxs - 1;
  v8 = 0;
  pTrace->t1 = -1.0;
  pTrace->t2 = 1.0;
  pTrace->hitside = -1;
  pTrace->startsolid = true;
  do
  {
    if ( v8 < 3 )
    {
      v9 = *(float *)((char *)&v6->x + (char *)boxMins - (char *)vecRayStart) - v6->x;
      v10 = v9 - *(float *)((char *)&v6->x + (char *)vecRayDelta - (char *)vecRayStart);
    }
    else
    {
      v9 = *(float *)((char *)&v7->x + (char *)vecRayStart - (char *)boxMaxs) - v7->x;
      v10 = *(float *)((char *)&v7->x + (char *)vecRayDelta - (char *)boxMaxs) + v9;
    }
    if ( v9 > 0.0 && v10 > 0.0 )
    {
      pTrace->startsolid = false;
      return false;
    }
    if ( v9 > 0.0 || v10 > 0.0 )
    {
      if ( v9 > 0.0 )
        pTrace->startsolid = false;
      if ( v9 <= v10 )
      {
        v13 = (float)(v9 + flTolerance) / (float)(v9 - v10);
        if ( pTrace->t2 > v13 )
          pTrace->t2 = v13;
      }
      else
      {
        v11 = v9 - flTolerance;
        if ( (float)(v9 - flTolerance) < 0.0 )
          v11 = 0.0;
        v12 = v11 / (float)(v9 - v10);
        if ( v12 > pTrace->t1 )
        {
          pTrace->t1 = v12;
          pTrace->hitside = v8;
        }
      }
    }
    ++v8;
    v7 = (const Vector *)((char *)v7 + 4);
    v6 = (const Vector *)((char *)v6 + 4);
  }
  while ( v8 < 6 );
  return pTrace->startsolid || pTrace->t2 > pTrace->t1 && pTrace->t1 >= 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10155180
// Name: bool IntersectRayWithBox(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,class CBaseTrace __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IntersectRayWithBox(
        const Vector *vecRayStart,
        const Vector *vecRayDelta,
        const Vector *boxMins,
        const Vector *boxMaxs,
        float flTolerance,
        CBaseTrace *pTrace,
        float *pFractionLeftSolid)
{
  bool startsolid; // al
  float t2; // xmm0_4
  float t1; // xmm2_4
  bool v10; // cc
  int hitside; // eax
  double v12; // st7
  bool v14; // al
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm3_4
  float y; // xmm1_4
  BoxTraceInfo_t v20; // [esp+14h] [ebp-10h] BYREF

  pTrace->startpos = *vecRayStart;
  pTrace->endpos = *vecRayStart;
  pTrace->endpos.x = vecRayDelta->x + pTrace->endpos.x;
  pTrace->endpos.y = pTrace->endpos.y + vecRayDelta->y;
  pTrace->endpos.z = pTrace->endpos.z + vecRayDelta->z;
  *(_WORD *)&pTrace->allsolid = 0;
  *(_QWORD *)&pTrace->fraction = 1065353216;
  if ( IntersectRayWithBox(vecRayStart, vecRayDelta, boxMins, boxMaxs, flTolerance, pTrace: &v20) )
  {
    startsolid = v20.startsolid;
    t2 = v20.t2;
    t1 = v20.t1;
    v10 = v20.t2 <= v20.t1;
    pTrace->startsolid = v20.startsolid;
    if ( !v10 && t1 >= 0.0 )
    {
      hitside = v20.hitside;
      pTrace->fraction = t1;
      pTrace->endpos.x = (float)(vecRayDelta->x * t1) + pTrace->startpos.x;
      pTrace->endpos.y = (float)(vecRayDelta->y * t1) + pTrace->startpos.y;
      pTrace->endpos.z = (float)(t1 * vecRayDelta->z) + pTrace->startpos.z;
      pTrace->contents = 1;
      pTrace->plane.normal = vec3_origin;
      if ( hitside < 3 )
      {
        LODWORD(pTrace->plane.dist) = *((_DWORD *)&boxMins->x + hitside) ^ _mask__NegFloat_;
        *((_DWORD *)&pTrace->plane.normal.x + hitside) = -1082130432;
      }
      else
      {
        v12 = *(&boxMaxs[-1].x + hitside);
        hitside -= 3;
        pTrace->plane.dist = v12;
        *((_DWORD *)&pTrace->plane.normal.x + hitside) = 1065353216;
      }
      pTrace->plane.type = hitside;
      return 1;
    }
    if ( startsolid )
    {
      v14 = t2 <= 0.0 || t2 >= 1.0;
      pTrace->allsolid = v14;
      pTrace->fraction = 0.0;
      if ( pFractionLeftSolid != nullptr )
        *pFractionLeftSolid = t2;
      pTrace->endpos = pTrace->startpos;
      pTrace->contents = 1;
      pTrace->plane.dist = pTrace->startpos.x;
      pTrace->plane.normal.y = 0.0;
      pTrace->plane.normal.z = 0.0;
      pTrace->plane.normal.x = 1.0;
      pTrace->plane.type = 0;
      v15 = vecRayDelta->x * t2;
      v16 = vecRayDelta->y * t2;
      v17 = (float)(t2 * vecRayDelta->z) + vecRayStart->z;
      v18 = vecRayStart->x + v15;
      y = vecRayStart->y;
      pTrace->startpos.x = v18;
      pTrace->startpos.y = y + v16;
      pTrace->startpos.z = v17;
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101553B0
// Name: bool IntersectRayWithBox(struct Ray_t const __near &,class Vector const __near &,class Vector const __near &,float,class CBaseTrace __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IntersectRayWithBox(
        const Ray_t *ray,
        const Vector *boxMins,
        const Vector *boxMaxs,
        float flTolerance,
        CBaseTrace *pTrace,
        const Ray_t *pFractionLeftSolid)
{
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  char result; // al
  Vector v12; // [esp+14h] [ebp-18h] BYREF
  Vector v13; // [esp+20h] [ebp-Ch] BYREF

  if ( ray->m_IsRay )
    return IntersectRayWithBox(
             vecRayStart: &ray->m_Start,
             vecRayDelta: &ray->m_Delta,
             boxMins,
             boxMaxs,
             flTolerance,
             pTrace,
             pFractionLeftSolid: &pFractionLeftSolid->m_Start.x);
  v6 = boxMaxs->y + ray->m_Extents.y;
  v7 = boxMins->x - ray->m_Extents.x;
  v8 = boxMins->y - ray->m_Extents.y;
  v12.z = boxMins->z - ray->m_Extents.z;
  v9 = boxMaxs->x + ray->m_Extents.x;
  v13.y = v6;
  v10 = boxMaxs->z + ray->m_Extents.z;
  v12.x = v7;
  v12.y = v8;
  v13.x = v9;
  v13.z = v10;
  result = IntersectRayWithBox(
             vecRayStart: &ray->m_Start,
             vecRayDelta: &ray->m_Delta,
             boxMins: &v12,
             boxMaxs: &v13,
             flTolerance,
             pTrace,
             pFractionLeftSolid: &pFractionLeftSolid->m_Start.x);
  pTrace->startpos.x = pTrace->startpos.x + ray->m_StartOffset.x;
  pTrace->startpos.y = pTrace->startpos.y + ray->m_StartOffset.y;
  pTrace->startpos.z = pTrace->startpos.z + ray->m_StartOffset.z;
  pTrace->endpos.x = pTrace->endpos.x + ray->m_StartOffset.x;
  pTrace->endpos.y = pTrace->endpos.y + ray->m_StartOffset.y;
  pTrace->endpos.z = pTrace->endpos.z + ray->m_StartOffset.z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101554D0
// Name: void ComputeSupportMap(class Vector const __near &,class Vector const __near &,class Vector const __near &,float __near * const)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeSupportMap(
        const Vector *vecDirection,
        const Vector *vecBoxMins,
        const Vector *vecBoxMaxs,
        float *pDist)
{
  unsigned int v4; // edx
  unsigned int v5; // edx
  unsigned int v6; // edx

  v4 = 4 * (vecDirection->x > 0.0);
  pDist[v4 / 4] = vecBoxMaxs->x * vecDirection->x;
  pDist[v4 / 0xFFFFFFFC + 1] = vecDirection->x * vecBoxMins->x;
  v5 = 4 * (vecDirection->y > 0.0);
  pDist[v5 / 4] = (float)(vecBoxMaxs->y * vecDirection->y) + pDist[v5 / 4];
  pDist[v5 / 0xFFFFFFFC + 1] = (float)(vecBoxMins->y * vecDirection->y) + pDist[v5 / 0xFFFFFFFC + 1];
  v6 = 4 * (vecDirection->z > 0.0);
  pDist[v6 / 4] = (float)(vecBoxMaxs->z * vecDirection->z) + pDist[v6 / 4];
  pDist[v6 / 0xFFFFFFFC + 1] = (float)(vecBoxMins->z * vecDirection->z) + pDist[v6 / 0xFFFFFFFC + 1];
}

//------------------------------------------------------------------------------
// Address: 0x101555B0
// Name: void ResolveQuadratic(double,double,class Vector,class Vector,class Vector,class Vector,class Vector,class Vector,int,double __near &,double __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ResolveQuadratic(
        double tPlus,
        long double tMinus,
        Vector axisU0,
        Vector axisU1,
        Vector axisV0,
        Vector axisV1,
        Vector axisOrigin,
        Vector pt,
        int projU,
        long double *s,
        long double *t)
{
  double v11; // st5
  long double v13; // st4
  long double v14; // st6
  long double v15; // st4
  double v16; // rtt
  long double v17; // st3
  double v18; // st6
  long double v19; // st2
  double *v20; // ecx
  long double v21; // st7
  long double *v22; // eax
  long double v23; // st6
  long double v24; // rt2
  long double v25; // st3
  double v26; // st4
  long double v27; // st3
  long double v28; // st2
  double v29; // st1
  long double v30; // st4
  long double v31; // rtt
  long double v32; // st2
  long double v33; // st6
  long double v34; // rt0
  long double v35; // st3
  double v36; // st5
  long double v37; // rt2
  long double v38; // rtt
  long double v39; // st3
  double v40; // st7
  long double v41; // rt0
  long double v42; // st3
  long double v43; // st4
  long double v44; // st3
  long double v45; // st2
  long double v46; // st6
  long double v47; // st2
  long double v48; // st3
  bool v49; // cc
  long double v50; // st4
  double *v51; // edx
  double *v52; // ecx
  double sPlus; // [esp+0h] [ebp-8h]
  double sMinus; // [esp+10h] [ebp+8h]
  double s0; // [esp+18h] [ebp+10h]

  v11 = 1.0;
  v13 = (1.0 - tPlus) * *(&axisU0.x + projU) + *(&axisU1.x + projU) * tPlus;
  v14 = *(&axisU1.x + projU) * tMinus + *(&axisU0.x + projU) * (1.0 - tMinus);
  sPlus = -99999.0;
  sMinus = -99999.0;
  if ( fabs(v13) < 0.00001 )
  {
    v15 = -99999.0;
  }
  else
  {
    sPlus = (*(&pt.x + projU) - *(&axisOrigin.x + projU) - *(&axisV0.x + projU) * tPlus) / v13;
    v15 = sPlus;
  }
  if ( fabs(v14) < 0.00001 )
  {
    v18 = tPlus;
    v17 = -99999.0;
  }
  else
  {
    v16 = tPlus;
    v17 = (*(&pt.x + projU) - *(&axisOrigin.x + projU) - *(&axisV0.x + projU) * tMinus) / v14;
    v18 = v16;
    sMinus = v17;
  }
  v19 = v18;
  if ( v18 >= 0.0 )
  {
    if ( v18 <= 1.0 && v15 >= 0.0 && v15 <= 1.0 )
    {
      v20 = t;
      *s = v15;
      *v20 = v18;
      return;
    }
    v19 = v18;
    v11 = 1.0;
  }
  v21 = v19;
  if ( tMinus < 0.0 )
  {
    v23 = tMinus;
  }
  else if ( v11 < tMinus )
  {
    v23 = tMinus;
  }
  else
  {
    if ( v17 >= 0.0 && v11 >= v17 )
    {
      v22 = t;
      *s = v17;
      *v22 = tMinus;
      return;
    }
    v23 = tMinus;
  }
  v24 = v17;
  v25 = v15;
  v26 = v24;
  s0 = v25;
  if ( v25 >= v11 )
    s0 = v25 - v11;
  v27 = v19;
  if ( v19 >= v11 )
    v21 = v19 - v11;
  v28 = v26;
  v29 = v26;
  v30 = v23;
  if ( v29 >= v11 )
    v28 = sMinus - v11;
  v31 = v28;
  v32 = v23;
  v33 = v31;
  if ( v32 < v11 )
  {
    v36 = v32;
  }
  else
  {
    v34 = v27;
    v35 = v32 - v11;
    v36 = v32;
    v37 = v35;
    v27 = v34;
    v30 = v37;
  }
  v38 = v27;
  v39 = v21;
  v40 = v38;
  v41 = fabs(v39);
  v42 = v30;
  v43 = fabs(v33);
  v44 = fabs(v42);
  v45 = v41;
  v46 = fabs(s0);
  if ( v41 > v46 )
    v46 = v45;
  v47 = v44;
  v48 = v43;
  v49 = v47 <= v43;
  v50 = v47;
  if ( v49 )
    v50 = v48;
  if ( v46 <= v50 )
  {
    v52 = t;
    *s = sPlus;
    *v52 = v40;
  }
  else
  {
    v51 = t;
    *s = sMinus;
    *v51 = v36;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10155770
// Name: void PointInQuadFromBarycentric(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector2D const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PointInQuadFromBarycentric(
        const Vector *v1,
        const Vector *v2,
        const Vector *v3,
        const Vector *v4,
        const Vector2D *uv,
        Vector *point)
{
  float y; // xmm0_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float x; // xmm6_4

  y = uv->y;
  v7 = (float)((float)(v4->x - v1->x) * y) + v1->x;
  v8 = (float)((float)(v4->y - v1->y) * y) + v1->y;
  v9 = (float)((float)(v4->z - v1->z) * y) + v1->z;
  v10 = (float)((float)(v3->y - v2->y) * y) + v2->y;
  v11 = (float)((float)(v3->z - v2->z) * y) + v2->z;
  x = uv->x;
  point->x = (float)((float)((float)((float)((float)(v3->x - v2->x) * y) + v2->x) - v7) * uv->x) + v7;
  point->y = (float)((float)(v10 - v8) * x) + v8;
  point->z = (float)((float)(v11 - v9) * x) + v9;
}

//------------------------------------------------------------------------------
// Address: 0x10155840
// Name: void TexCoordInQuadFromBarycentric(class Vector2D const __near &,class Vector2D const __near &,class Vector2D const __near &,class Vector2D const __near &,class Vector2D const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TexCoordInQuadFromBarycentric(
        const Vector2D *v1,
        const Vector2D *v2,
        const Vector2D *v3,
        const Vector2D *v4,
        const Vector2D *uv,
        Vector2D *texCoord)
{
  float y; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm1_4
  float x; // xmm4_4

  y = uv->y;
  v7 = (float)((float)(v4->x - v1->x) * y) + v1->x;
  v8 = (float)((float)(v4->y - v1->y) * y) + v1->y;
  v9 = (float)((float)(v3->y - v2->y) * y) + v2->y;
  x = uv->x;
  texCoord->x = (float)((float)((float)((float)((float)(v3->x - v2->x) * y) + v2->x) - v7) * uv->x) + v7;
  texCoord->y = (float)((float)(v9 - v8) * x) + v8;
}

//------------------------------------------------------------------------------
// Address: 0x101558D0
// Name: void ComputePointFromBarycentric(class Vector2D const __near &,class Vector2D const __near &,class Vector2D const __near &,float,float,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputePointFromBarycentric(
        const Vector2D *v0,
        const Vector2D *v1,
        const Vector2D *v2,
        float u,
        float v,
        Vector2D *pt)
{
  float v6; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm0_4

  v6 = (float)(v1->y - v0->y) * u;
  v7 = (float)(v2->y - v0->y) * v;
  v8 = (float)((float)(v1->x - v0->x) * u) + v0->x;
  v9 = (float)(v2->x - v0->x) * v;
  pt->x = v8;
  v10 = v6 + v0->y;
  pt->x = v9 + v8;
  pt->y = v7 + v10;
}

//------------------------------------------------------------------------------
// Address: 0x10155940
// Name: bool AxisTestEdgeCrossX3(float,float,float,float,class Vector const __near &,class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
char __cdecl AxisTestEdgeCrossX3(
        float flEdgeZ,
        float flEdgeY,
        float flAbsEdgeZ,
        float flAbsEdgeY,
        const Vector *p1,
        const Vector *p2,
        const Vector *vecExtents,
        float flTolerance)
{
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm0_4

  v8 = (float)(p1->y * flEdgeZ) - (float)(p1->z * flEdgeY);
  v9 = (float)(p2->y * flEdgeZ) - (float)(p2->z * flEdgeY);
  v10 = (float)((float)(vecExtents->y * flAbsEdgeZ) + (float)(vecExtents->z * flAbsEdgeY)) + flTolerance;
  if ( v9 <= v8 )
  {
    if ( v9 > v10 || COERCE_FLOAT(LODWORD(v10) ^ _mask__NegFloat_) > v8 )
      return 0;
  }
  else if ( v8 > v10 || COERCE_FLOAT(LODWORD(v10) ^ _mask__NegFloat_) > v9 )
  {
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101559D0
// Name: bool IsBoxIntersectingTriangle(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,struct cplane_t const __near &,float)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsBoxIntersectingTriangle(
        const Vector *vecBoxCenter,
        const Vector *vecBoxExtents,
        const Vector *v1,
        const Vector *v2,
        const Vector *v3,
        const cplane_t *plane,
        float flTolerance)
{
  float v9; // xmm5_4
  float v10; // xmm6_4
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float y; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm2_4
  float z; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm3_4
  float v25; // xmm4_4
  float v26; // xmm2_4
  long double v27; // st7
  long double v28; // st6
  long double v29; // st7
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  bool v33; // cc
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm0_4
  bool v37; // cc
  long double v38; // st7
  long double v39; // st6
  long double v40; // st7
  float v41; // xmm0_4
  float v42; // xmm1_4
  float v43; // xmm2_4
  bool v44; // cc
  float v45; // xmm1_4
  float v46; // xmm2_4
  float v47; // xmm0_4
  bool v48; // cc
  long double v49; // st7
  long double v50; // st6
  long double v51; // st7
  float v52; // xmm0_4
  float v53; // xmm1_4
  float v54; // xmm3_4
  bool v55; // cc
  float v56; // xmm1_4
  float v57; // xmm0_4
  float v58; // xmm2_4
  bool v59; // cc
  float v60; // xmm1_4
  float v61; // xmm6_4
  float v62; // xmm0_4
  float v63; // xmm1_4
  float v64; // xmm0_4
  float v65; // xmm1_4
  float v66; // xmm6_4
  float v67; // xmm1_4
  float v69; // [esp-28h] [ebp-68h]
  float v70; // [esp-28h] [ebp-68h]
  float v71; // [esp-28h] [ebp-68h]
  float v72; // [esp-24h] [ebp-64h]
  float v73; // [esp-24h] [ebp-64h]
  float v74; // [esp-24h] [ebp-64h]
  float flEdgeZ; // [esp+0h] [ebp-40h] BYREF
  float flEdgeY; // [esp+4h] [ebp-3Ch]
  float flAbsEdgeZ; // [esp+8h] [ebp-38h]
  Vector flAbsEdgeY; // [esp+Ch] [ebp-34h] BYREF
  Vector v79; // [esp+18h] [ebp-28h] BYREF
  Vector v80; // [esp+24h] [ebp-1Ch] BYREF
  float v81; // [esp+30h] [ebp-10h]
  Vector p3; // [esp+34h] [ebp-Ch]
  float p2_8; // [esp+48h] [ebp+8h]
  float p1_4; // [esp+50h] [ebp+10h]
  float p1_4a; // [esp+50h] [ebp+10h]
  float p1_8; // [esp+54h] [ebp+14h]
  float vecAbsEdge; // [esp+58h] [ebp+18h]
  float vecAbsEdgea; // [esp+58h] [ebp+18h]

  v9 = v1->x - vecBoxCenter->x;
  v10 = v2->x - vecBoxCenter->x;
  v11 = v3->x - vecBoxCenter->x;
  p3.z = vecBoxCenter->x;
  v80.x = v9;
  v79.x = v10;
  flAbsEdgeY.x = v11;
  v12 = v9;
  v13 = v9;
  if ( v9 > v10 )
    v13 = v10;
  if ( v10 > v9 )
    v12 = v10;
  if ( v13 > v11 )
    v13 = v11;
  if ( v11 > v12 )
    v12 = v11;
  p2_8 = vecBoxExtents->x;
  v14 = vecBoxExtents->x + flTolerance;
  if ( v13 > v14 || (float)-v14 > v12 )
    return false;
  y = vecBoxCenter->y;
  v16 = v1->y - y;
  v17 = v2->y - y;
  v18 = v3->y - y;
  v80.y = v16;
  v79.y = v17;
  flAbsEdgeY.y = v18;
  v19 = v16;
  v20 = v16;
  if ( v16 > v17 )
    v20 = v17;
  if ( v17 > v16 )
    v19 = v17;
  if ( v20 > v18 )
    v20 = v18;
  if ( v18 > v19 )
    v19 = v18;
  p1_8 = vecBoxExtents->y;
  if ( v20 > (float)(p1_8 + flTolerance) || (float)-(float)(p1_8 + flTolerance) > v19 )
    return false;
  z = vecBoxCenter->z;
  v22 = v1->z - z;
  v23 = v2->z - z;
  v24 = v3->z - z;
  v80.z = v22;
  v79.z = v23;
  flAbsEdgeY.z = v24;
  v25 = v22;
  v26 = v22;
  if ( v22 > v23 )
    v26 = v23;
  if ( v23 > v22 )
    v25 = v23;
  if ( v26 > v24 )
    v26 = v24;
  if ( v24 > v25 )
    v25 = v24;
  p1_4 = vecBoxExtents->z;
  if ( v26 > (float)(p1_4 + flTolerance) )
    return false;
  if ( (float)-(float)(p1_4 + flTolerance) > v25 )
    return false;
  v27 = v79.y - v80.y;
  flEdgeY = v27;
  flEdgeZ = v10 - v9;
  v28 = v79.z - v80.z;
  flAbsEdgeZ = v28;
  p3.x = fabs(v27);
  p3.y = fabs(v28);
  v72 = v27;
  v69 = v28;
  if ( AxisTestEdgeCrossX3(
         flEdgeZ: v69,
         flEdgeY: v72,
         flAbsEdgeZ: p3.y,
         flAbsEdgeY: p3.x,
         p1: &v80,
         p2: &flAbsEdgeY,
         vecExtents: vecBoxExtents,
         flTolerance) == 0 )
    return false;
  v29 = fabs(flEdgeZ);
  v81 = v29;
  v30 = (float)(flEdgeZ * v80.z) - (float)(flAbsEdgeZ * v80.x);
  vecAbsEdge = v29 * p1_4 + p2_8 * p3.y;
  v31 = (float)(flEdgeZ * flAbsEdgeY.z) - (float)(flAbsEdgeZ * flAbsEdgeY.x);
  v32 = vecAbsEdge + flTolerance;
  if ( v31 <= v30 )
  {
    if ( v31 > v32 )
      return false;
    v33 = (float)-v32 <= v30;
  }
  else
  {
    if ( v30 > v32 )
      return false;
    v33 = (float)-v32 <= v31;
  }
  if ( v33 )
  {
    v34 = (float)(flEdgeY * v79.x) - (float)(flEdgeZ * v79.y);
    v35 = (float)(flEdgeY * flAbsEdgeY.x) - (float)(flEdgeZ * flAbsEdgeY.y);
    v36 = (float)((float)(p1_8 * v81) + (float)(p2_8 * p3.x)) + flTolerance;
    if ( v34 <= v35 )
    {
      if ( v34 > v36 )
        return false;
      v37 = (float)-v36 <= v35;
    }
    else
    {
      if ( v35 > v36 )
        return false;
      v37 = (float)-v36 <= v34;
    }
    if ( !v37 )
      return false;
    v38 = flAbsEdgeY.y - v79.y;
    flEdgeY = v38;
    flEdgeZ = flAbsEdgeY.x - v79.x;
    v39 = flAbsEdgeY.z - v79.z;
    flAbsEdgeZ = v39;
    p3.x = fabs(v38);
    p3.y = fabs(v39);
    v73 = v38;
    v70 = v39;
    if ( AxisTestEdgeCrossX3(
           flEdgeZ: v70,
           flEdgeY: v73,
           flAbsEdgeZ: p3.y,
           flAbsEdgeY: p3.x,
           p1: &v80,
           p2: &v79,
           vecExtents: vecBoxExtents,
           flTolerance) == 0 )
      return false;
    v40 = fabs(flEdgeZ);
    v81 = v40;
    v41 = (float)(flEdgeZ * v80.z) - (float)(flAbsEdgeZ * v80.x);
    vecAbsEdgea = v40 * p1_4 + p2_8 * p3.y;
    v42 = (float)(flEdgeZ * v79.z) - (float)(flAbsEdgeZ * v79.x);
    v43 = vecAbsEdgea + flTolerance;
    if ( v42 <= v41 )
    {
      if ( v42 > v43 )
        return false;
      v44 = (float)-v43 <= v41;
    }
    else
    {
      if ( v41 > v43 )
        return false;
      v44 = (float)-v43 <= v42;
    }
    if ( v44 )
    {
      v45 = (float)(flEdgeY * v80.x) - (float)(flEdgeZ * v80.y);
      v46 = (float)(flEdgeY * flAbsEdgeY.x) - (float)(flEdgeZ * flAbsEdgeY.y);
      v47 = (float)((float)(p1_8 * v81) + (float)(p2_8 * p3.x)) + flTolerance;
      if ( v46 <= v45 )
      {
        if ( v46 > v47 )
          return false;
        v48 = (float)-v47 <= v45;
      }
      else
      {
        if ( v45 > v47 )
          return false;
        v48 = (float)-v47 <= v46;
      }
      if ( !v48 )
        return false;
      v49 = v80.y - flAbsEdgeY.y;
      flEdgeY = v49;
      flEdgeZ = v80.x - flAbsEdgeY.x;
      v50 = v80.z - flAbsEdgeY.z;
      flAbsEdgeZ = v50;
      p3.x = fabs(v49);
      p3.y = fabs(v50);
      v74 = v49;
      v71 = v50;
      if ( AxisTestEdgeCrossX3(
             flEdgeZ: v71,
             flEdgeY: v74,
             flAbsEdgeZ: p3.y,
             flAbsEdgeY: p3.x,
             p1: &v80,
             p2: &v79,
             vecExtents: vecBoxExtents,
             flTolerance) == 0 )
        return false;
      v51 = fabs(flEdgeZ);
      v81 = v51;
      v52 = (float)(flEdgeZ * v80.z) - (float)(flAbsEdgeZ * v80.x);
      p1_4a = v51 * p1_4 + p2_8 * p3.y;
      v53 = (float)(flEdgeZ * v79.z) - (float)(flAbsEdgeZ * v79.x);
      v54 = p1_4a + flTolerance;
      if ( v53 <= v52 )
      {
        if ( v53 > v54 )
          return false;
        v55 = (float)-v54 <= v52;
      }
      else
      {
        if ( v52 > v54 )
          return false;
        v55 = (float)-v54 <= v53;
      }
      if ( v55 )
      {
        v56 = (float)(flEdgeY * flAbsEdgeY.x) - (float)(flEdgeZ * flAbsEdgeY.y);
        v57 = (float)(flEdgeY * v79.x) - (float)(flEdgeZ * v79.y);
        v58 = (float)((float)(p1_8 * v81) + (float)(p2_8 * p3.x)) + flTolerance;
        if ( v57 <= v56 )
        {
          if ( v57 > v58 )
            return false;
          v59 = (float)-v58 <= v56;
        }
        else
        {
          if ( v56 > v58 )
            return false;
          v59 = (float)-v58 <= v57;
        }
        if ( v59 )
        {
          v60 = vecBoxCenter->y;
          v61 = vecBoxCenter->z;
          flAbsEdgeY.x = p3.z - p2_8;
          v62 = vecBoxExtents->y;
          v63 = v60 - v62;
          v64 = v62 + vecBoxCenter->y;
          flAbsEdgeY.y = v63;
          v65 = vecBoxExtents->z;
          v66 = v61 - v65;
          v67 = v65 + vecBoxCenter->z;
          flAbsEdgeY.z = v66;
          flEdgeZ = p2_8 + p3.z;
          flEdgeY = v64;
          flAbsEdgeZ = v67;
          return BoxOnPlaneSide(emins: &flAbsEdgeY.x, emaxs: &flEdgeZ, p: plane) == 3;
        }
      }
    }
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10156020
// Name: float IntersectRayWithTriangle(struct Ray_t const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
double __cdecl IntersectRayWithTriangle(const Ray_t *ray, const Vector *v1, float v2, const Vector *v3, int oneSided)
{
  float y; // xmm0_4
  float z; // xmm4_4
  float v7; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm5_4
  float v10; // xmm4_4
  float x; // xmm2_4
  float v12; // xmm6_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm5_4
  float v17; // xmm7_4
  float v18; // xmm4_4
  float v19; // xmm3_4
  float v20; // xmm6_4
  float v21; // xmm2_4
  float v22; // xmm6_4
  float dirCrossEdge2_4; // [esp+4h] [ebp-20h]
  float edge2; // [esp+Ch] [ebp-18h]
  float edge2_4; // [esp+10h] [ebp-14h]
  float edge2_8; // [esp+14h] [ebp-10h]
  float edge1; // [esp+18h] [ebp-Ch]
  float edge1_4; // [esp+1Ch] [ebp-8h]
  float edge1_8; // [esp+20h] [ebp-4h]

  y = v1->y;
  z = v1->z;
  v7 = v3->x - v1->x;
  v8 = v3->y - y;
  v9 = v3->z - z;
  edge1 = *(float *)LODWORD(v2) - v1->x;
  edge1_4 = *(float *)(LODWORD(v2) + 4) - y;
  edge1_8 = *(float *)(LODWORD(v2) + 8) - z;
  edge2 = v7;
  edge2_4 = v8;
  edge2_8 = v9;
  if ( (_BYTE)oneSided != 0
    && (float)((float)((float)(ray->m_Delta.y
                             * (float)((float)((float)(*(float *)(LODWORD(v2) + 8) - z) * v7)
                                     - (float)(v9 * (float)(*(float *)LODWORD(v2) - v1->x))))
                     + (float)((float)((float)(v9 * (float)(*(float *)(LODWORD(v2) + 4) - y))
                                     - (float)(v8 * (float)(*(float *)(LODWORD(v2) + 8) - z)))
                             * ray->m_Delta.x))
             + (float)(ray->m_Delta.z
                     * (float)((float)(v8 * (float)(*(float *)LODWORD(v2) - v1->x))
                             - (float)(v7 * (float)(*(float *)(LODWORD(v2) + 4) - y))))) >= 0.0 )
  {
    return -1.0;
  }
  v10 = (float)(ray->m_Delta.y * v9) - (float)(ray->m_Delta.z * v8);
  x = ray->m_Delta.x;
  dirCrossEdge2_4 = (float)(ray->m_Delta.z * v7) - (float)(x * v9);
  v12 = (float)(x * v8) - (float)(ray->m_Delta.y * v7);
  *(float *)&oneSided = (float)((float)(dirCrossEdge2_4 * edge1_4) + (float)(v10 * edge1)) + (float)(v12 * edge1_8);
  if ( fabs(*(float *)&oneSided) < 0.000001 )
    return -1.0;
  v13 = ray->m_Start.y - v1->y;
  v14 = ray->m_Start.x - v1->x;
  *(float *)&oneSided = 1.0
                      / (float)((float)((float)(dirCrossEdge2_4 * edge1_4) + (float)(v10 * edge1))
                              + (float)(v12 * edge1_8));
  v15 = ray->m_Start.z - v1->z;
  v16 = (float)((float)((float)(v13 * dirCrossEdge2_4) + (float)(v14 * v10)) + (float)(v15 * v12)) * *(float *)&oneSided;
  if ( v16 < 0.0 )
    return -1.0;
  if ( v16 > 1.0 )
    return -1.0;
  v17 = *(float *)&oneSided;
  v18 = (float)(v13 * edge1_8) - (float)(v15 * edge1_4);
  v19 = (float)(v14 * edge1_4) - (float)(v13 * edge1);
  v20 = (float)(v15 * edge1) - (float)(v14 * edge1_8);
  v21 = (float)((float)((float)(x * v18) + (float)(v20 * ray->m_Delta.y)) + (float)(v19 * ray->m_Delta.z))
      * *(float *)&oneSided;
  if ( v21 < 0.0 )
    return -1.0;
  if ( (float)(v21 + v16) > 1.0 )
    return -1.0;
  *(float *)&oneSided = ComputeBoxOffset(ray);
  v22 = (float)((float)((float)(v20 * edge2_4) + (float)(v18 * edge2)) + (float)(v19 * edge2_8)) * v17;
  v2 = v22;
  if ( COERCE_FLOAT(oneSided ^ _mask__NegFloat_) > v22 || v22 > (float)(*(float *)&oneSided + 1.0) )
    return -1.0;
  oneSided = 1;
  v1 = nullptr;
  return clamp<float,int,int>(val: &v2, minVal: (const int *)&v1, maxVal: &oneSided);
}

//------------------------------------------------------------------------------
// Address: 0x101562D0
// Name: bool IsBoxIntersectingRay(union __m128 const __near &,union __m128 const __near &,struct Ray_t const __near &,union __m128 const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
bool __userpurge IsBoxIntersectingRay@<al>(
        const __m128 *boxMin@<ecx>,
        const __m128 *boxMax@<edx>,
        int a3@<ebp>,
        const Ray_t *ray,
        const __m128 *fl4Tolerance)
{
  bool v5; // zf
  VectorAligned m_Extents; // xmm0
  __m128 v7; // xmm1
  __m128 v8; // xmm0
  __m128 v9; // xmm3
  __m128 v10; // xmm0
  __m128 v11; // xmm2
  __m128 v13; // xmm1
  __m128 v14; // xmm0
  _BYTE v15[88]; // [esp-Ch] [ebp-5Ch] OVERLAPPED BYREF
  _UNKNOWN *retaddr; // [esp+50h] [ebp+0h]

  *(_DWORD *)&v15[80] = a3;
  *(_DWORD *)&v15[84] = retaddr;
  v5 = !ray->m_IsSwept;
  m_Extents = ray->m_Extents;
  v7 = _mm_and_ps((__m128)ray->m_Start, *(__m128 *)g_SIMD_clear_wmask);
  *(__m128 *)&v15[48] = v7;
  v8 = _mm_and_ps((__m128)m_Extents, *(__m128 *)g_SIMD_clear_wmask);
  if ( v5 )
  {
    v9 = _mm_add_ps(_mm_sub_ps(v7, v8), *fl4Tolerance);
    v10 = _mm_add_ps(_mm_add_ps(v8, v7), *fl4Tolerance);
    *(__m128 *)&v15[64] = *boxMin;
    v11 = *boxMax;
    *(__m128 *)&v15[48] = v10;
    *(__m128 *)&v15[16] = v11;
    *(__m128 *)&v15[32] = v9;
    return *(float *)&v15[64] <= v10.m128_f32[0]
        && *(float *)&v15[32] <= *(float *)&v15[16]
        && *(float *)&v15[68] <= *(float *)&v15[52]
        && *(float *)&v15[36] <= *(float *)&v15[20]
        && *(float *)&v15[72] <= *(float *)&v15[56]
        && *(float *)&v15[40] <= *(float *)&v15[24];
  }
  else
  {
    v13 = _mm_and_ps((__m128)ray->m_Delta, *(__m128 *)g_SIMD_clear_wmask);
    *(__m128 *)v15 = _mm_sub_ps(*boxMin, v8);
    *(__m128 *)&v15[64] = _mm_add_ps(*boxMax, v8);
    v14 = _mm_rcp_ps(v13);
    *(__m128 *)&v15[32] = v13;
    *(__m128 *)&v15[16] = _mm_sub_ps(_mm_add_ps(v14, v14), _mm_mul_ps(_mm_mul_ps(v14, v14), v13));
    return IsBoxIntersectingRay(
             inBoxMin: (const __m128 *)v15,
             inBoxMax: (const __m128 *)&v15[64],
             origin: (const __m128 *)&v15[48],
             delta: (const __m128 *)&v15[32],
             invDelta: (const __m128 *)&v15[16],
             vTolerance: fl4Tolerance);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101563F0
// Name: bool IntersectRayWithOBB(class Vector const __near &,class Vector const __near &,struct matrix3x4_t const __near &,class Vector const __near &,class Vector const __near &,float,class CBaseTrace __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __cdecl IntersectRayWithOBB(
        const Vector *vecRayStart,
        const Vector *vecRayDelta,
        const matrix3x4_t *matOBBToWorld,
        const Vector *vecOBBMins,
        const Vector *vecOBBMaxs,
        float flTolerance,
        CBaseTrace *pTrace)
{
  Vector *p_endpos; // edi
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float x; // xmm4_4
  float y; // xmm5_4
  float z; // xmm6_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  double v22; // st7
  double v23; // st6
  float *v24; // eax
  int v25; // ecx
  float v26; // xmm2_4
  long double v27; // st4
  float v28; // xmm5_4
  float v29; // xmm3_4
  float v30; // xmm1_4
  double v31; // st7
  double v32; // st6
  double v33; // st5
  double v34; // st4
  double v35; // st7
  long double v36; // st4
  double v37; // st5
  int type; // eax
  float v40; // xmm0_4
  double v41; // st7
  float v42; // xmm0_4
  Vector out; // [esp+18h] [ebp-68h] BYREF
  float v44; // [esp+24h] [ebp-5Ch] BYREF
  Vector start; // [esp+28h] [ebp-58h] BYREF
  Vector vecTemp; // [esp+34h] [ebp-4Ch]
  Vector vecBoxCenter; // [esp+40h] [ebp-40h]
  Vector uextent; // [esp+4Ch] [ebp-34h]
  float v49; // [esp+58h] [ebp-28h]
  float v50; // [esp+5Ch] [ebp-24h]
  Vector v51; // [esp+60h] [ebp-20h] BYREF
  float v52; // [esp+6Ch] [ebp-14h] BYREF
  Vector extent; // [esp+70h] [ebp-10h]
  float vecBoxExtents; // [esp+7Ch] [ebp-4h] OVERLAPPED
  float in1; // [esp+88h] [ebp+8h]
  float *v56; // [esp+8Ch] [ebp+Ch]
  float matOBBToWorlda; // [esp+A0h] [ebp+20h]

  pTrace->startpos = *vecRayStart;
  p_endpos = &pTrace->endpos;
  pTrace->endpos = *vecRayStart;
  pTrace->endpos.x = vecRayDelta->x + pTrace->endpos.x;
  pTrace->endpos.y = vecRayDelta->y + pTrace->endpos.y;
  pTrace->endpos.z = pTrace->endpos.z + vecRayDelta->z;
  pTrace->fraction = 1.0;
  *(_WORD *)&pTrace->allsolid = 0;
  pTrace->contents = 0;
  v10 = (float)(vecOBBMins->y + vecOBBMaxs->y) * 0.5;
  v11 = (float)(vecOBBMins->z + vecOBBMaxs->z) * 0.5;
  v52 = (float)(vecOBBMins->x + vecOBBMaxs->x) * 0.5;
  extent.x = v10;
  extent.y = v11;
  VectorTransform(in1: &v52, in2: matOBBToWorld, out: &start.z);
  v13 = vecOBBMaxs->y - extent.x;
  v14 = vecOBBMaxs->z - extent.y;
  x = vecRayDelta->x;
  y = vecRayDelta->y;
  z = vecRayDelta->z;
  vecBoxCenter.z = vecOBBMaxs->x - v52;
  v52 = vecBoxCenter.z;
  v18 = vecRayStart->x;
  uextent.x = v13;
  extent.x = v13;
  v19 = vecRayStart->y;
  uextent.y = v14;
  extent.y = v14;
  v20 = (float)(v18 + x) - start.z;
  v21 = z + vecRayStart->z;
  uextent.z = v20;
  v50 = v21 - vecTemp.y;
  v22 = (float)(v21 - vecTemp.y);
  v49 = (float)(v19 + y) - vecTemp.x;
  v23 = v49;
  v24 = matOBBToWorld->m_flMatVal[2];
  memset(&v51, 0, sizeof(v51));
  v56 = matOBBToWorld->m_flMatVal[2];
  v25 = 0;
  while ( 1 )
  {
    v26 = *v24;
    matOBBToWorlda = *(v24 - 8);
    in1 = (float)((float)(x * matOBBToWorlda) + (float)(y * *(v24 - 4))) + (float)(z * *v24);
    vecBoxExtents = *(v24 - 4);
    v27 = fabs(in1);
    extent.z = v26;
    *(float *)((char *)&vecTemp.z + v25) = v27;
    *(float *)((char *)&v51.x + v25) = in1;
    if ( fabs(matOBBToWorlda * v20 + vecBoxExtents * v23 + extent.z * v22) > v27 + *(float *)((char *)&v52 + v25) )
      return 0;
    ++v56;
    v25 += 4;
    if ( v25 >= 12 )
      break;
    v24 = v56;
  }
  v28 = vecRayDelta->y;
  v29 = vecRayDelta->z;
  v30 = v49;
  v31 = matOBBToWorld->m_flMatVal[1][0];
  uextent.z = (float)(v28 * v50) - (float)(v29 * v49);
  v49 = (float)(v29 * v20) - (float)(x * v50);
  v32 = v49;
  v33 = matOBBToWorld->m_flMatVal[0][0];
  v50 = (float)(x * v30) - (float)(v28 * v20);
  v34 = v31 * v49;
  v35 = uextent.z;
  v36 = v33 * uextent.z + v34 + v50 * matOBBToWorld->m_flMatVal[2][0];
  v37 = v50;
  if ( fabs(v36) > vecBoxCenter.x * uextent.y + uextent.x * vecBoxCenter.y )
    return 0;
  if ( fabs(
         matOBBToWorld->m_flMatVal[1][1] * v32
       + matOBBToWorld->m_flMatVal[0][1] * v35
       + matOBBToWorld->m_flMatVal[2][1] * v37) > vecBoxCenter.y * vecBoxCenter.z + uextent.y * vecTemp.z )
    return 0;
  if ( fabs(
         v37 * matOBBToWorld->m_flMatVal[2][2]
       + v35 * matOBBToWorld->m_flMatVal[0][2]
       + v32 * matOBBToWorld->m_flMatVal[1][2]) > vecBoxCenter.z * vecBoxCenter.x + vecTemp.z * uextent.x )
    return 0;
  VectorITransform(in1: &vecRayStart->x, in2: matOBBToWorld, out: &out.x);
  v51.x = v51.x * 2.0;
  v51.y = v51.y * 2.0;
  v51.z = v51.z * 2.0;
  if ( IntersectRayWithBox(
         vecRayStart: &out,
         vecRayDelta: &v51,
         boxMins: vecOBBMins,
         boxMaxs: vecOBBMaxs,
         flTolerance,
         pTrace,
         pFractionLeftSolid: nullptr) == 0 )
    return 0;
  VectorTransform(in1: &pTrace->endpos.x, in2: matOBBToWorld, out: &v44);
  p_endpos->x = v44;
  pTrace->endpos.y = start.x;
  pTrace->endpos.z = start.y;
  type = pTrace->plane.type;
  pTrace->startpos.x = vecRayStart->x;
  v40 = pTrace->fraction * 2.0;
  pTrace->startpos.y = vecRayStart->y;
  v41 = vecRayStart->z;
  pTrace->fraction = v40;
  pTrace->startpos.z = v41;
  v42 = *(&pTrace->plane.normal.x + type);
  pTrace->plane.normal.x = matOBBToWorld->m_flMatVal[0][type] * v42;
  pTrace->plane.normal.y = matOBBToWorld->m_flMatVal[1][pTrace->plane.type] * v42;
  pTrace->plane.normal.z = matOBBToWorld->m_flMatVal[2][pTrace->plane.type] * v42;
  pTrace->plane.dist = (float)((float)(pTrace->plane.normal.y * pTrace->endpos.y)
                             + (float)(pTrace->plane.normal.x * pTrace->endpos.x))
                     + (float)(pTrace->plane.normal.z * pTrace->endpos.z);
  pTrace->plane.type = 3;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10156850
// Name: bool IntersectRayWithOBB(class Vector const __near &,class Vector const __near &,class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,float,class CBaseTrace __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IntersectRayWithOBB(
        const Vector *vecRayOrigin,
        const Vector *vecRayDelta,
        const Vector *vecBoxOrigin,
        const Vector *angBoxRotation,
        const Vector *vecOBBMins,
        const Vector *vecOBBMaxs,
        float flTolerance,
        CBaseTrace *pTrace)
{
  float x; // xmm0_4
  float y; // xmm2_4
  float z; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  matrix3x4_t matrix; // [esp+Ch] [ebp-48h] BYREF
  Vector v17; // [esp+3Ch] [ebp-18h] BYREF
  Vector vecAbsMins; // [esp+48h] [ebp-Ch] BYREF

  if ( vec3_angle.x == angBoxRotation->x && vec3_angle.y == angBoxRotation->y && vec3_angle.z == angBoxRotation->z )
  {
    x = vecBoxOrigin->x;
    y = vecOBBMins->y;
    z = vecOBBMins->z;
    v17.x = vecOBBMins->x + vecBoxOrigin->x;
    v11 = vecBoxOrigin->y;
    v17.y = y + v11;
    v12 = vecBoxOrigin->z;
    v17.z = z + v12;
    v13 = vecOBBMaxs->x + x;
    vecAbsMins.y = vecOBBMaxs->y + v11;
    v14 = vecOBBMaxs->z + v12;
    vecAbsMins.x = v13;
    vecAbsMins.z = v14;
    return IntersectRayWithBox(
             vecRayStart: vecRayOrigin,
             vecRayDelta,
             boxMins: &v17,
             boxMaxs: &vecAbsMins,
             flTolerance,
             pTrace,
             pFractionLeftSolid: nullptr);
  }
  else
  {
    AngleMatrix(angles: (const QAngle *)angBoxRotation, position: vecBoxOrigin, &matrix);
    return IntersectRayWithOBB(
             vecRayStart: vecRayOrigin,
             vecRayDelta,
             matOBBToWorld: &matrix,
             vecOBBMins,
             vecOBBMaxs,
             flTolerance,
             pTrace);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10156970
// Name: bool IntersectRayWithOBB(struct Ray_t const __near &,struct matrix3x4_t const __near &,class Vector const __near &,class Vector const __near &,float,class CBaseTrace __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __usercall IntersectRayWithOBB@<al>(
        int a1@<ebp>,
        const Ray_t *ray,
        const matrix3x4_t *matOBBToWorld,
        const Vector *vecOBBMins,
        const Vector *vecOBBMaxs,
        float flTolerance,
        CBaseTrace *pTrace)
{
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float y; // xmm5_4
  float z; // xmm6_4
  float v13; // xmm7_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm5_4
  float v18; // xmm2_4
  float v19; // xmm6_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm7_4
  float v23; // xmm0_4
  __int128 v24; // xmm1
  float x; // xmm4_4
  __int128 v26; // xmm1
  float v27; // xmm5_4
  float v28; // xmm4_4
  float v29; // xmm6_4
  float v30; // xmm3_4
  float v31; // xmm0_4
  float v32; // xmm2_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm2_4
  float v36; // ecx
  float v37; // xmm0_4
  float v38; // xmm0_4
  float *v39; // eax
  float *p_y; // esi
  int v41; // edi
  long double v42; // st7
  float v43; // edx
  double v44; // st6
  long double v45; // st7
  long double v46; // st6
  float *v47; // eax
  long double v48; // st7
  const float *v49; // edx
  long double v50; // st6
  float v51; // xmm0_4
  float v52; // xmm0_4
  int v53; // ecx
  int v54; // edx
  float v55; // xmm3_4
  float v56; // xmm1_4
  float v57; // xmm0_4
  int v58; // ecx
  int v59; // eax
  float *v60; // eax
  float v61; // xmm1_4
  int v62; // ecx
  float v63; // xmm0_4
  float *v64; // edx
  float v65; // xmm0_4
  float v66; // xmm4_4
  long double v67; // st7
  double v68; // st6
  int v69; // ecx
  float v70; // xmm5_4
  long double v71; // st5
  double v72; // st4
  float v73; // xmm3_4
  double v74; // rt0
  long double v75; // st5
  float v76; // xmm0_4
  double v77; // st4
  float v78; // xmm0_4
  float v79; // xmm6_4
  int v80; // ecx
  float v81; // xmm7_4
  float v82; // xmm0_4
  float *v83; // edx
  float v84; // xmm0_4
  int v85; // ecx
  long double v86; // st5
  float v87; // xmm1_4
  long double v88; // st4
  long double v89; // st5
  int v90; // ecx
  float *v91; // eax
  float v92; // xmm0_4
  int v93; // ecx
  float v94; // xmm0_4
  long double v95; // st5
  long double v96; // st7
  long double v97; // st7
  float v98; // xmm6_4
  float v99; // xmm0_4
  int v100; // edi
  float v101; // eax
  int v102; // esi
  float v103; // xmm0_4
  float v104; // xmm1_4
  float v105; // xmm3_4
  float v106; // xmm4_4
  float v107; // xmm3_4
  float v108; // edx
  float v109; // xmm0_4
  float v110; // xmm3_4
  float v111; // xmm1_4
  float v112; // xmm0_4
  float v113; // xmm0_4
  float v114; // xmm0_4
  float v115; // xmm0_4
  VectorAligned *v116; // edx
  float v117; // eax
  float v118; // xmm1_4
  float v119; // xmm0_4
  float v120; // xmm2_4
  float v121; // xmm1_4
  float v122; // xmm3_4
  bool v123; // al
  double v124; // st7
  _DWORD v125[2]; // [esp+18h] [ebp-1ECh] BYREF
  _DWORD v126[10]; // [esp+20h] [ebp-1E4h] BYREF
  Vector pPlaneNormal[15]; // [esp+48h] [ebp-1BCh] BYREF
  float ppPlaneDist[15][2]; // [esp+100h] [ebp-104h] BYREF
  float v129; // [esp+178h] [ebp-8Ch]
  Vector vecLocalRayDirection; // [esp+17Ch] [ebp-88h] BYREF
  float v131; // [esp+188h] [ebp-7Ch]
  float v132; // [esp+18Ch] [ebp-78h]
  float v133; // [esp+190h] [ebp-74h]
  char v134; // [esp+194h] [ebp-70h]
  __int128 flRayExtent1; // [esp+198h] [ebp-6Ch] OVERLAPPED BYREF
  float v136; // [esp+1B0h] [ebp-54h]
  cplane_t temp; // [esp+1B4h] [ebp-50h] BYREF
  VectorAligned *p_m_Delta; // [esp+1C8h] [ebp-3Ch]
  Vector vecLocalRayEnd; // [esp+1CCh] [ebp-38h]
  float *v140; // [esp+1D8h] [ebp-2Ch]
  float v141; // [esp+1DCh] [ebp-28h] BYREF
  float d1[2]; // [esp+1E0h] [ebp-24h]
  float v143; // [esp+1E8h] [ebp-1Ch]
  const float *pMatRow0; // [esp+1ECh] [ebp-18h]
  float v145; // [esp+1F0h] [ebp-14h]
  float v146; // [esp+1F4h] [ebp-10h]
  int v147; // [esp+1F8h] [ebp-Ch]
  const float *pMatRow1; // [esp+1FCh] [ebp-8h]
  const float *vars0; // [esp+204h] [ebp+0h]

  v147 = a1;
  pMatRow1 = vars0;
  if ( ray->m_IsRay )
    return IntersectRayWithOBB(
             vecRayStart: &ray->m_Start,
             vecRayDelta: &ray->m_Delta,
             matOBBToWorld,
             vecOBBMins,
             vecOBBMaxs,
             flTolerance,
             pTrace);
  v8 = ray->m_StartOffset.y + ray->m_Start.y;
  v9 = ray->m_Start.x + ray->m_StartOffset.x;
  v10 = ray->m_StartOffset.z + ray->m_Start.z;
  pTrace->startpos.y = v8;
  pTrace->startpos.x = v9;
  pTrace->startpos.z = v10;
  pTrace->endpos.y = v8;
  pTrace->endpos.x = v9;
  pTrace->endpos.z = v10;
  pTrace->endpos.x = v9 + ray->m_Delta.x;
  pTrace->endpos.y = ray->m_Delta.y + pTrace->endpos.y;
  pTrace->endpos.z = ray->m_Delta.z + pTrace->endpos.z;
  pTrace->fraction = 1.0;
  *(_WORD *)&pTrace->allsolid = 0;
  pTrace->contents = 0;
  y = vecOBBMaxs->y;
  z = vecOBBMaxs->z;
  v13 = matOBBToWorld->m_flMatVal[0][3];
  v14 = (float)(vecOBBMaxs->x - vecOBBMins->x) * 0.5;
  v15 = (float)(vecOBBMaxs->x + vecOBBMins->x) * 0.5;
  v16 = y + vecOBBMins->y;
  v17 = y - vecOBBMins->y;
  v18 = z + vecOBBMins->z;
  v19 = z - vecOBBMins->z;
  d1[1] = v18 * 0.5;
  v20 = matOBBToWorld->m_flMatVal[2][3] + (float)(v18 * 0.5);
  v21 = ray->m_Extents.y;
  v22 = v13 + v15;
  v23 = matOBBToWorld->m_flMatVal[1][3] + (float)(v16 * 0.5);
  v24 = 0;
  d1[0] = v23;
  d1[1] = v20;
  *(float *)&v24 = (float)((float)(v14 * v14) + (float)((float)(v17 * 0.5) * (float)(v17 * 0.5)))
                 + (float)((float)(v19 * 0.5) * (float)(v19 * 0.5));
  x = ray->m_Extents.x;
  *(float *)&v24 = fsqrt(*(float *)&v24);
  *(_OWORD *)&ppPlaneDist[9][0] = v24;
  v26 = 0;
  *(float *)&v26 = fsqrt((float)((float)(x * x) + (float)(v21 * v21)) + (float)(ray->m_Extents.z * ray->m_Extents.z));
  flRayExtent1 = v26;
  p_m_Delta = &ray->m_Delta;
  v27 = ray->m_Start.x;
  v28 = ray->m_Delta.x;
  v29 = ray->m_Delta.y;
  v30 = (float)(*(float *)&v26 + ppPlaneDist[9][0]) + flTolerance;
  v31 = (float)((float)((float)(v23 - ray->m_Start.y) * v29) + (float)((float)(v22 - ray->m_Start.x) * v28))
      + (float)((float)(v20 - ray->m_Start.z) * ray->m_Delta.z);
  v32 = 0.0;
  if ( v31 > 0.0 )
  {
    v143 = (float)(v29 * v29) + (float)(v28 * v28);
    v146 = ray->m_Delta.z * ray->m_Delta.z;
    if ( v31 <= (float)(v143 + v146) )
      v32 = v31 / (float)(v143 + v146);
    else
      v32 = 1.0;
  }
  v33 = (float)((float)(v32 * v29) + ray->m_Start.y) - d1[0];
  v34 = v32 * v28;
  v35 = (float)((float)(v32 * ray->m_Delta.z) + ray->m_Start.z) - d1[1];
  if ( (float)(v30 * v30) >= (float)((float)((float)(v33 * v33)
                                           + (float)((float)((float)(v34 + v27) - v22)
                                                   * (float)((float)(v34 + v27) - v22)))
                                   + (float)(v35 * v35)) )
  {
    VectorITransform(in1: &ray->m_Start.x, in2: matOBBToWorld, out: &v141);
    VectorIRotate(in1: &p_m_Delta->x, in2: matOBBToWorld, out: &ppPlaneDist[9][1]);
    v36 = *(float *)&vecOBBMaxs;
    ppPlaneDist[12][1] = ray->m_Extents.y;
    ppPlaneDist[11][0] = ray->m_Extents.x;
    vecLocalRayDirection.x = ray->m_Extents.z;
    v129 = vecOBBMaxs->z;
    ppPlaneDist[13][1] = vecOBBMins->z;
    temp.normal.x = vecOBBMaxs->x;
    *(float *)&temp.type = vecOBBMins->x;
    v37 = vecOBBMaxs->y;
    v145 = COERCE_FLOAT(v125);
    LODWORD(vecLocalRayEnd.y) = &ray->m_Extents;
    v146 = v37;
    v38 = vecOBBMins->y;
    v39 = matOBBToWorld->m_flMatVal[2];
    LODWORD(ppPlaneDist[14][1]) = (char *)vecOBBMins - (char *)vecOBBMaxs;
    v143 = v38;
    LODWORD(vecLocalRayEnd.z) = vecOBBMaxs;
    pMatRow0 = &matOBBToWorld->m_flMatVal[0][1];
    p_y = &pPlaneNormal[2].y;
    v140 = matOBBToWorld->m_flMatVal[2];
    v41 = 0;
    while ( 1 )
    {
      v42 = *(v39 - 8) * ppPlaneDist[11][0];
      v43 = v145;
      *(p_y - 19) = 0.0;
      *(p_y - 18) = 0.0;
      *(p_y - 17) = 0.0;
      v44 = *(v39 - 4);
      *(_DWORD *)LODWORD(v43) = 1065353216;
      v45 = fabs(v42) + fabs(v44 * ppPlaneDist[12][1]);
      v46 = vecLocalRayDirection.x * *v39;
      v47 = (float *)((char *)&pPlaneNormal[13].y + v41 * 8);
      v48 = v45 + fabs(v46);
      v49 = pMatRow0;
      v50 = *(float *)(LODWORD(ppPlaneDist[14][1]) + LODWORD(v36)) - v48;
      ppPlaneDist[12][0] = *(pMatRow0 - 1);
      *(p_y - 10) = ppPlaneDist[12][0];
      v51 = *v49;
      *(v47 - 6) = v50;
      ppPlaneDist[11][1] = v51;
      *(p_y - 9) = v51;
      v52 = v49[1];
      *(v47 - 5) = v48 + *(float *)LODWORD(v36);
      vecLocalRayDirection.y = v52;
      *(p_y - 8) = v52;
      ComputeSupportMap(
        vecDirection: (const Vector *)(p_y - 10),
        vecBoxMins: vecOBBMins,
        vecBoxMaxs: vecOBBMaxs,
        pDist: (float *)((char *)&pPlaneNormal[13].y + v41 * 8));
      v53 = s_ExtIndices[v41][0];
      v54 = s_ExtIndices[v41][1];
      v55 = vecLocalRayDirection.y;
      v56 = *(float *)((char *)&pPlaneNormal[13].y + v41 * 8) - *(float *)LODWORD(vecLocalRayEnd.y);
      *(float *)((char *)&pPlaneNormal[13].z + v41 * 8) = *(float *)LODWORD(vecLocalRayEnd.y)
                                                        + *(float *)((char *)&pPlaneNormal[13].z + v41 * 8);
      v57 = *(&ray->m_Extents.x + v53);
      v58 = s_MatIndices[v41][1];
      ppPlaneDist[14][0] = v57;
      v59 = s_MatIndices[v41][0];
      ppPlaneDist[13][0] = *(&ray->m_Extents.x + v54);
      v60 = matOBBToWorld->m_flMatVal[v59];
      *(float *)((char *)&pPlaneNormal[13].y + v41 * 8) = v56;
      v61 = ppPlaneDist[11][1];
      LODWORD(temp.dist) = v60;
      LODWORD(vecLocalRayEnd.x) = matOBBToWorld->m_flMatVal[v58];
      *(p_y - 1) = 0.0;
      *p_y = -v55;
      p_y[1] = v61;
      v62 = 4 * ((float)-v55 > 0.0);
      v63 = (float)-v55 * v143;
      v64 = ppPlaneDist[v41];
      v64[v62 / 4u] = (float)-v55 * v146;
      v64[v62 / 0xFFFFFFFC + 1] = v63;
      v65 = p_y[1];
      v66 = v129;
      v67 = fabs(*v60);
      v68 = ppPlaneDist[14][0];
      v69 = 4 * (v65 > 0.0);
      v64[v69 / 4u] = (float)(v65 * v129) + v64[v69 / 4u];
      v70 = ppPlaneDist[13][1];
      v71 = fabs(*(float *)LODWORD(vecLocalRayEnd.x));
      v72 = ppPlaneDist[13][0];
      v64[v69 / 0xFFFFFFFC + 1] = (float)(v65 * ppPlaneDist[13][1]) + v64[v69 / 0xFFFFFFFC + 1];
      p_y[8] = v55;
      v73 = ppPlaneDist[12][0];
      v74 = v72;
      v75 = v71 * v72 + v67 * v68;
      v76 = -ppPlaneDist[12][0];
      v77 = ppPlaneDist[v41][0];
      p_y[9] = 0.0;
      p_y[10] = v76;
      v78 = p_y[8];
      *v64 = v77 - v75;
      ppPlaneDist[v41][1] = v75 + ppPlaneDist[v41][1];
      v79 = temp.normal.x;
      v80 = 4 * (v78 > 0.0);
      v81 = v78;
      v82 = v78 * *(float *)&temp.type;
      v83 = ppPlaneDist[v41 + 3];
      v83[v80 / 4u] = v81 * temp.normal.x;
      v83[v80 / 0xFFFFFFFC + 1] = v82;
      v84 = p_y[10];
      v85 = 4 * (v84 > 0.0);
      v86 = fabs(v60[1]);
      v83[v85 / 4u] = (float)(v84 * v66) + v83[v85 / 4u];
      v83[v85 / 0xFFFFFFFC + 1] = (float)(v84 * v70) + v83[v85 / 0xFFFFFFFC + 1];
      v87 = -v61;
      v88 = fabs(*(float *)(LODWORD(vecLocalRayEnd.x) + 4));
      p_y[17] = v87;
      p_y[18] = v73;
      v89 = v86 * v68 + v88 * v74;
      p_y[19] = 0.0;
      *v83 = *v83 - v89;
      ppPlaneDist[v41 + 3][1] = v89 + ppPlaneDist[v41 + 3][1];
      v90 = 4 * (v87 > 0.0);
      v91 = ppPlaneDist[v41 + 6];
      v92 = v87 * *(float *)&temp.type;
      v91[v90 / 4u] = v87 * v79;
      v91[v90 / 0xFFFFFFFC + 1] = v92;
      v93 = 4 * (v73 > 0.0);
      v94 = v73 * v143;
      v91[v93 / 4u] = (float)(v73 * v146) + v91[v93 / 4u];
      v95 = *(float *)(LODWORD(temp.dist) + 8);
      v91[v93 / 0xFFFFFFFC + 1] = v94 + v91[v93 / 0xFFFFFFFC + 1];
      ++v41;
      p_y += 3;
      v96 = v74 * fabs(*(float *)(LODWORD(vecLocalRayEnd.x) + 8)) + v68 * fabs(v95);
      *v91 = *v91 - v96;
      ++v140;
      v97 = v96 + ppPlaneDist[v41 + 5][1];
      LODWORD(vecLocalRayEnd.z) += 4;
      LODWORD(vecLocalRayEnd.y) += 4;
      LODWORD(v145) += 16;
      ppPlaneDist[v41 + 5][1] = v97;
      pMatRow0 += 4;
      if ( v41 >= 3 )
        break;
      v39 = v140;
      v36 = vecLocalRayEnd.z;
    }
    v98 = ppPlaneDist[9][1] + v141;
    v145 = -1.0;
    *(float *)&pMatRow0 = 1.0;
    *((float *)&flRayExtent1 + 2) = ppPlaneDist[10][0] + d1[0];
    v99 = ppPlaneDist[10][1] + d1[1];
    v100 = -1;
    v101 = COERCE_FLOAT(v126);
    v146 = NAN;
    pTrace->startsolid = true;
    *((float *)&flRayExtent1 + 3) = v99;
    v102 = 0;
    v143 = COERCE_FLOAT(v126);
LABEL_12:
    v103 = (float)((float)(d1[0] * *(float *)(LODWORD(v101) - 4)) + (float)(v141 * *(float *)(LODWORD(v101) - 8)))
         + (float)(d1[1] * *(float *)LODWORD(v101));
    v104 = (float)((float)(*((float *)&flRayExtent1 + 2) * *(float *)(LODWORD(v101) - 4))
                 + (float)(v98 * *(float *)(LODWORD(v101) - 8)))
         + (float)(*((float *)&flRayExtent1 + 3) * *(float *)LODWORD(v101));
    v105 = *(&pPlaneNormal[11].y + 2 * v102);
    v136 = -(float)(v103 - v105);
    v106 = v104 - v105;
    v107 = *(&pPlaneNormal[11].z + 2 * v102);
    temp.normal.z = -v106;
    temp.normal.x = v103 - v107;
    temp.dist = v104 - v107;
    v108 = 0.0;
    while ( 1 )
    {
      v109 = *(&v136 + LODWORD(v108));
      if ( v109 > 0.0 && *(&temp.normal.z + LODWORD(v108)) > 0.0 )
        break;
      if ( v109 > 0.0 || *(&temp.normal.z + LODWORD(v108)) > 0.0 )
      {
        if ( v109 > 0.0 )
          pTrace->startsolid = false;
        v110 = *(&temp.normal.z + LODWORD(v108));
        v111 = 1.0 / (float)(v109 - v110);
        if ( v109 <= v110 )
        {
          v114 = (float)(v109 + flTolerance) * v111;
          if ( *(float *)&pMatRow0 > v114 )
            *(float *)&pMatRow0 = v114;
        }
        else
        {
          v112 = v109 - flTolerance;
          if ( v112 < 0.0 )
            v112 = 0.0;
          v113 = v112 * v111;
          if ( v113 > v145 )
          {
            v101 = v143;
            v145 = v113;
            v100 = v102;
            v146 = v108;
          }
        }
      }
      ++LODWORD(v108);
      if ( SLODWORD(v108) >= 2 )
      {
        ++v102;
        LODWORD(v101) += 12;
        v143 = v101;
        if ( v102 < 15 )
          goto LABEL_12;
        v115 = v145;
        if ( *(float *)&pMatRow0 <= v145 || v145 < 0.0 )
        {
          if ( !pTrace->startsolid )
            return 0;
          v123 = *(float *)&pMatRow0 <= 0.0 || *(float *)&pMatRow0 >= 1.0;
          v124 = pTrace->startpos.x;
          pTrace->allsolid = v123;
          pTrace->fraction = 0.0;
          pTrace->endpos.x = v124;
          pTrace->endpos.y = pTrace->startpos.y;
          pTrace->endpos.z = pTrace->startpos.z;
          pTrace->contents = 1;
          pTrace->plane.dist = pTrace->startpos.x;
          pTrace->plane.normal.x = 1.0;
          pTrace->plane.normal.y = 0.0;
          pTrace->plane.normal.z = 0.0;
          pTrace->plane.type = 0;
          return 1;
        }
        else
        {
          v116 = p_m_Delta;
          v117 = v146;
          pTrace->fraction = v145;
          pTrace->endpos.x = (float)(v115 * v116->x) + pTrace->startpos.x;
          pTrace->endpos.y = (float)(v116->y * v115) + pTrace->startpos.y;
          v118 = (float)(v116->z * v115) + pTrace->startpos.z;
          v119 = *(float *)&v125[3 * v100];
          v120 = *(float *)&v126[3 * v100];
          pTrace->endpos.z = v118;
          v121 = *(float *)&v125[3 * v100 + 1];
          v122 = *(&pPlaneNormal[11].y + 2 * v100 + LODWORD(v117));
          pTrace->contents = 1;
          vecLocalRayDirection.z = v119;
          v131 = v121;
          v132 = v120;
          v133 = v122;
          if ( v117 == 0.0 )
          {
            vecLocalRayDirection.z = v119 * -1.0;
            v131 = v121 * -1.0;
            v132 = v120 * -1.0;
            v133 = v122 * -1.0;
          }
          v134 = 3;
          MatrixGetColumn(in: matOBBToWorld, column: 3, out: (Vector *)&temp.normal.y);
          VectorIRotate(in1: &temp.normal.y, in2: matOBBToWorld, out: (float *)&flRayExtent1 + 1);
          VectorIRotate(in1: &vecLocalRayDirection.z, in2: matOBBToWorld, out: &pTrace->plane.normal.x);
          pTrace->plane.dist = (float)((float)((float)((float)(pTrace->plane.normal.x * pTrace->plane.normal.x)
                                                     + (float)(pTrace->plane.normal.y * pTrace->plane.normal.y))
                                             + (float)(pTrace->plane.normal.z * pTrace->plane.normal.z))
                                     * v133)
                             - (float)((float)((float)(*((float *)&flRayExtent1 + 1) * pTrace->plane.normal.x)
                                             + (float)(*((float *)&flRayExtent1 + 2) * pTrace->plane.normal.y))
                                     + (float)(*((float *)&flRayExtent1 + 3) * pTrace->plane.normal.z));
          return 1;
        }
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10157400
// Name: bool IntersectRayWithOBB(struct Ray_t const __near &,class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,float,class CBaseTrace __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IntersectRayWithOBB(
        const Ray_t *ray,
        const Vector *vecBoxOrigin,
        const Vector *angBoxRotation,
        const Ray_t *vecOBBMins,
        const Vector *vecOBBMaxs,
        float flTolerance,
        CBaseTrace *pTrace)
{
  float x; // xmm0_4
  float y; // xmm2_4
  float z; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  matrix3x4_t matrix; // [esp+Ch] [ebp-48h] BYREF
  Vector v16; // [esp+3Ch] [ebp-18h] BYREF
  Vector vecWorldMins; // [esp+48h] [ebp-Ch] BYREF
  Vector vecWorldMaxs; // [esp+54h] [ebp+0h] BYREF

  if ( vec3_angle.x == angBoxRotation->x && vec3_angle.y == angBoxRotation->y && vec3_angle.z == angBoxRotation->z )
  {
    x = vecBoxOrigin->x;
    y = vecOBBMins->m_Start.y;
    z = vecOBBMins->m_Start.z;
    v16.x = vecOBBMins->m_Start.x + vecBoxOrigin->x;
    v10 = vecBoxOrigin->y;
    v16.y = y + v10;
    v11 = vecBoxOrigin->z;
    v16.z = z + v11;
    v12 = vecOBBMaxs->x + x;
    vecWorldMins.y = vecOBBMaxs->y + v10;
    v13 = vecOBBMaxs->z + v11;
    vecWorldMins.x = v12;
    vecWorldMins.z = v13;
    return IntersectRayWithBox(
             ray,
             boxMins: &v16,
             boxMaxs: &vecWorldMins,
             flTolerance,
             pTrace,
             pFractionLeftSolid: nullptr);
  }
  else if ( ray->m_IsRay )
  {
    return IntersectRayWithOBB(
             vecRayOrigin: &ray->m_Start,
             vecRayDelta: &ray->m_Delta,
             vecBoxOrigin,
             angBoxRotation,
             vecOBBMins: &vecOBBMins->m_Start,
             vecOBBMaxs,
             flTolerance,
             pTrace);
  }
  else
  {
    AngleMatrix(angles: (const QAngle *)angBoxRotation, position: vecBoxOrigin, &matrix);
    return IntersectRayWithOBB(
             a1: (int)&vecWorldMaxs,
             ray,
             matOBBToWorld: &matrix,
             vecOBBMins: &vecOBBMins->m_Start,
             vecOBBMaxs,
             flTolerance,
             pTrace);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10157550
// Name: enum QuadBarycentricRetval_t QuadWithParallelEdges(class Vector const __near &,class Vector const __near &,float,class Vector const __near &,float,class Vector const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall QuadWithParallelEdges@<eax>(
        float a1@<ebp>,
        const Vector *vecOrigin,
        const Vector *vecU,
        float lengthU,
        const Vector *vecV,
        float lengthV,
        const Vector *pt,
        Vector2D *vecUV)
{
  float z; // xmm0_4
  float x; // xmm1_4
  float y; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  Vector v19; // [esp-Ch] [ebp-BCh] BYREF
  Ray_t rayAxis; // [esp+0h] [ebp-B0h] BYREF
  Ray_t rayPt; // [esp+50h] [ebp-60h] BYREF
  float v22[2]; // [esp+A0h] [ebp-10h] BYREF
  float s; // [esp+A8h] [ebp-8h]
  float retaddr; // [esp+B0h] [ebp+0h]

  v22[1] = a1;
  s = retaddr;
  rayAxis.m_Extents.y = 0.0;
  rayPt.m_Extents.y = 0.0;
  v19 = *vecOrigin;
  *(Vector *)&rayAxis.m_Start.y = *vecU;
  *(float *)&rayAxis.m_IsRay = pt->x;
  *(float *)(&rayAxis.m_IsSwept + 3) = pt->y;
  z = pt->z;
  x = vecV->x;
  y = vecV->y;
  v11 = vecV->z;
  LOBYTE(rayAxis.m_Extents.z) = 1;
  LOBYTE(rayPt.m_Extents.z) = 1;
  *(float *)(&rayAxis.m_IsSwept + 7) = z;
  LODWORD(v12) = COERCE_UNSIGNED_INT(lengthV * 10.0) ^ _mask__NegFloat_;
  rayPt.m_Start.y = x * v12;
  rayPt.m_Start.z = y * v12;
  rayPt.m_Start.w = v11 * v12;
  IntersectRayWithRay(
    ray0: (const Ray_t *)&v19,
    ray1: (const Ray_t *)&rayAxis.m_IsRay,
    t: v22,
    s: (float *)(&rayPt.m_IsSwept + 7));
  vecUV->x = v22[0] / lengthU;
  LODWORD(v13) = COERCE_UNSIGNED_INT(lengthU * 10.0) ^ _mask__NegFloat_;
  v14 = vecU->y;
  v15 = vecU->z;
  *(Vector *)&rayAxis.m_Start.y = *vecV;
  rayPt.m_Start.y = vecU->x * v13;
  rayPt.m_Start.z = v14 * v13;
  rayPt.m_Start.w = v15 * v13;
  IntersectRayWithRay(
    ray0: (const Ray_t *)&v19,
    ray1: (const Ray_t *)&rayAxis.m_IsRay,
    t: v22,
    s: (float *)(&rayPt.m_IsSwept + 7));
  v16 = vecUV->x;
  v17 = v22[0] / lengthV;
  vecUV->y = v22[0] / lengthV;
  return v16 >= 0.0 && v16 <= 1.0 && v17 >= 0.0 && v17 <= 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10157730
// Name: enum QuadBarycentricRetval_t PointInQuadToBarycentric(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
QuadBarycentricRetval_t __cdecl PointInQuadToBarycentric(
        const Vector *v1,
        const Vector *v2,
        const Vector *v3,
        const Vector *v4,
        __int64 point)
{
  float z; // xmm2_4
  float v6; // xmm7_4
  float y; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm6_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float x; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm7_4
  float v17; // xmm6_4
  float v18; // xmm5_4
  float v19; // xmm4_4
  QuadBarycentricRetval_t result; // eax
  char v21; // bl
  float v22; // xmm0_4
  float v23; // xmm6_4
  float v24; // xmm0_4
  float v25; // xmm6_4
  float v26; // xmm0_4
  long double v27; // st6
  long double v28; // st7
  int v29; // ecx
  int v30; // eax
  int v31; // edx
  float v32; // xmm0_4
  int v33; // eax
  float v34; // xmm7_4
  double v35; // st7
  double v36; // st6
  double v37; // st4
  double v38; // st7
  long double v39; // st6
  long double v40; // st5
  long double v41; // st7
  float v42; // xmm0_4
  float v43; // xmm0_4
  Vector v44; // [esp-20h] [ebp-C8h]
  float tPlus_4; // [esp+4h] [ebp-A4h]
  float tMinus; // [esp+8h] [ebp-A0h]
  Vector tMinus_4; // [esp+Ch] [ebp-9Ch] BYREF
  Vector vec; // [esp+18h] [ebp-90h] BYREF
  float v49; // [esp+24h] [ebp-84h]
  float v50; // [esp+28h] [ebp-80h]
  Vector vecV; // [esp+2Ch] [ebp-7Ch] BYREF
  Vector v52; // [esp+38h] [ebp-70h] BYREF
  float v53; // [esp+44h] [ebp-64h]
  long double v54; // [esp+48h] [ebp-60h] BYREF
  Vector v55; // [esp+50h] [ebp-58h] BYREF
  float v56; // [esp+5Ch] [ebp-4Ch]
  Vector v57; // [esp+60h] [ebp-48h] BYREF
  Vector v58; // [esp+6Ch] [ebp-3Ch] OVERLAPPED
  Vector axisUNorm[2]; // [esp+78h] [ebp-30h] BYREF
  _BYTE lengthU[25]; // [esp+90h] [ebp-18h] OVERLAPPED BYREF
  float vecOrigin; // [esp+B0h] [ebp+8h]
  float ta; // [esp+B4h] [ebp+Ch]
  float t; // [esp+B4h] [ebp+Ch]
  float t_4; // [esp+B8h] [ebp+10h]
  float v65; // [esp+BCh] [ebp+14h]

  z = v2->z;
  v6 = v3->z;
  y = v3->y;
  v8 = v4->y;
  v9 = v4->z;
  vecOrigin = v2->y;
  v11 = vecOrigin - v1->y;
  ta = v2->x;
  v12 = ta - v1->x;
  v56 = z;
  v13 = z - v1->z;
  v57.y = v11;
  tMinus_4.y = v11;
  *(float *)&lengthU[4] = v11;
  x = v4->x;
  v57.x = v12;
  tMinus_4.x = v12;
  *(float *)lengthU = v12;
  v15 = v3->x;
  v57.z = v13;
  tMinus_4.z = v13;
  *(float *)&lengthU[8] = v13;
  t_4 = v6;
  v16 = v6 - v9;
  v17 = v9 - v1->z;
  v18 = y - v8;
  v19 = v8 - v1->y;
  v53 = x - v1->x;
  vecV.x = v53;
  v58.x = v53;
  v55.x = v15 - x;
  *(_QWORD *)&v55.y = __PAIR64__(LODWORD(v16), LODWORD(v18));
  vec.x = v15 - x;
  vec.y = v18;
  vec.z = v16;
  *(float *)&lengthU[12] = v15 - x;
  *(float *)&lengthU[16] = v18;
  *(float *)&lengthU[20] = v16;
  v54 = COERCE_DOUBLE(__PAIR64__(LODWORD(v17), LODWORD(v19)));
  vecV.y = v19;
  vecV.z = v17;
  v58.y = v19;
  v58.z = v17;
  axisUNorm[1].x = v15 - ta;
  axisUNorm[1].y = y - vecOrigin;
  axisUNorm[1].z = t_4 - v56;
  v52.x = v15 - ta;
  v52.y = y - vecOrigin;
  v52.z = t_4 - v56;
  axisUNorm[0].x = v15 - ta;
  axisUNorm[0].y = y - vecOrigin;
  axisUNorm[0].z = t_4 - v56;
  v49 = VectorNormalize(vec: &tMinus_4);
  v50 = VectorNormalize(&vec);
  tPlus_4 = VectorNormalize(vec: &vecV);
  tMinus = VectorNormalize(vec: &v52);
  if ( (float)((float)((float)(vec.x * tMinus_4.x) + (float)(vec.y * tMinus_4.y)) + (float)(vec.z * tMinus_4.z)) > 0.99000001
    && fabs(v49 - v50) < 0.1 )
  {
    return QuadWithParallelEdges(
             a1: COERCE_FLOAT(&lengthU[24]),
             vecOrigin: v1,
             vecU: &tMinus_4,
             lengthU: v49,
             &vecV,
             lengthV: tPlus_4,
             pt: (const Vector *)point,
             vecUV: (Vector2D *)HIDWORD(point));
  }
  v21 = 0;
  if ( (float)((float)((float)(v52.y * vecV.y) + (float)(v52.x * vecV.x)) + (float)(v52.z * vecV.z)) <= 0.99000001 )
  {
    v23 = *(float *)&lengthU[4];
    v22 = v58.y;
  }
  else
  {
    axisUNorm[0] = v55;
    *(Vector *)&lengthU[12] = axisUNorm[1];
    v58 = v57;
    v22 = v57.y;
    *(float *)lengthU = v53;
    v23 = *(float *)&v54;
    v21 = 1;
    *(long double *)&lengthU[4] = v54;
  }
  v24 = (float)(v22 * *(float *)lengthU) - (float)(v23 * v58.x);
  v25 = 0.0;
  axisUNorm[1].z = v24;
  v26 = 1.0;
  v27 = fabs(*(float *)&lengthU[4] * v58.z - v58.y * *(float *)&lengthU[8]);
  v28 = fabs(*(float *)&lengthU[8] * v58.x - v58.z * *(float *)lengthU);
  if ( v27 <= v28 )
  {
    if ( v28 > fabs(axisUNorm[1].z) )
      goto LABEL_11;
  }
  else if ( v27 > fabs(axisUNorm[1].z) )
  {
    v25 = 1.0;
LABEL_11:
    v26 = 2.0;
  }
  v29 = (int)v25;
  if ( fabs(*(float *)&lengthU[4 * (int)v26]) > fabs(*(float *)&lengthU[4 * (int)v25]) )
  {
    v25 = v26;
    v26 = (float)v29;
  }
  v30 = (int)v26;
  *(double *)&v55.y = 0.0;
  v31 = (int)v25;
  v54 = 0.0;
  v32 = *(&v58.x + (int)v25);
  v33 = 4 * v30;
  v34 = *(float *)&lengthU[v33];
  v35 = *(float *)&lengthU[v33 + 12];
  v36 = *(float *)&lengthU[4 * (int)v25 + 12];
  v65 = *(float *)((char *)&v58.x + v33);
  v56 = *(float *)&lengthU[4 * (int)v25];
  *(double *)&v57.y = (float)(v32 * v34) - (float)(v65 * v56) - v35 * v32 + v36 * v65;
  v37 = *(float *)(v33 + point);
  t = *(float *)(point + 4 * (int)v25);
  v38 = v36 * v37
      + v34 * t
      + *(float *)((char *)&v1->x + v33) * v56
      - v56 * v37
      - *(&v1->x + v31) * v34
      - *(float *)((char *)&v1->x + v33) * v36
      + *(&v1->x + v31) * v35
      - v35 * t
      + (float)(v32 * v34)
      - (float)(v65 * v56);
  if ( *(double *)&v57.y <= -0.1 || *(double *)&v57.y >= 0.1 )
  {
    v39 = v38 * v38
        - (v34 * t + *(float *)((char *)&v1->x + v33) * v56 - v56 * v37 - *(&v1->x + (int)v25) * v34)
        * (*(double *)&v57.y
         * 4.0);
    if ( v39 >= 0.0 )
    {
      v40 = sqrt(v39);
      v44.x = *(float *)point;
      *(_QWORD *)&v44.y = *(_QWORD *)(point + 4);
      ResolveQuadratic(
        tPlus: (v38 + v40) / (*(double *)&v57.y + *(double *)&v57.y),
        tMinus: (v38 - v40) / (*(double *)&v57.y + *(double *)&v57.y),
        axisU0: *(Vector *)lengthU,
        axisU1: *(Vector *)&lengthU[12],
        axisV0: v58,
        axisV1: axisUNorm[0],
        axisOrigin: *v1,
        pt: v44,
        projU: v31,
        s: (long double *)&v55.y,
        t: &v54);
      if ( v21 != 0 )
      {
        *(float *)HIDWORD(point) = v54;
        v41 = *(double *)&v55.y;
      }
      else
      {
        *(float *)HIDWORD(point) = *(double *)&v55.y;
        v41 = v54;
      }
      v42 = *(float *)HIDWORD(point);
      *(float *)(HIDWORD(point) + 4) = v41;
      result = BARY_QUADRATIC_FALSE;
      if ( v42 >= 0.0 && v42 <= 1.0 )
      {
        v43 = *(float *)(HIDWORD(point) + 4);
        if ( v43 >= 0.0 && v43 <= 1.0 )
          return BARY_QUADRATIC_TRUE;
      }
    }
    else
    {
      *(_DWORD *)HIDWORD(point) = -943501440;
      *(_DWORD *)(HIDWORD(point) + 4) = -943501440;
      return BARY_QUADRATIC_NEGATIVE_DISCRIMINANT;
    }
  }
  else
  {
    v57.x = (float)(vec.x + tMinus_4.x) * 0.5;
    axisUNorm[1].x = (float)(v52.x + vecV.x) * 0.5;
    v57.z = (float)(vec.z + tMinus_4.z) * 0.5;
    v57.y = (float)(vec.y + tMinus_4.y) * 0.5;
    axisUNorm[1].y = (float)(v52.y + vecV.y) * 0.5;
    axisUNorm[1].z = (float)(v52.z + vecV.z) * 0.5;
    return QuadWithParallelEdges(
             a1: COERCE_FLOAT(&lengthU[24]),
             vecOrigin: v1,
             vecU: &v57,
             lengthU: (float)(v50 + v49) * 0.5,
             vecV: &axisUNorm[1],
             lengthV: (float)(tMinus + tPlus_4) * 0.5,
             pt: (const Vector *)point,
             vecUV: (Vector2D *)HIDWORD(point));
  }
  return result;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1014C250
// Name: bool IntersectRayWithBox(struct Ray_t const __near &,class VectorAligned const __near &,class VectorAligned const __near &,class VectorAligned const __near &,class CGameTrace restrict __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IntersectRayWithBox(
        const Ray_t *ray,
        __m128 *inInvDelta,
        __m128 *inBoxMins,
        __m128 *inBoxMaxs,
        CGameTrace *pTrace)
{
  __m128 v5; // xmm5
  VectorAligned m_Delta; // xmm6
  VectorAligned m_Extents; // xmm1
  __m128 v8; // xmm2
  __m128 v9; // xmm2
  __m128 v10; // xmm5
  __m128 v11; // xmm1
  __m128 v12; // xmm4
  __m128 v13; // xmm3
  __m128 v14; // xmm0
  __m128 v15; // xmm4
  __m128 v16; // xmm0
  __m128 v17; // xmm3
  __m128 v18; // xmm0
  __m128 v19; // xmm6
  __m128 v20; // xmm3
  __m128 v21; // xmm6
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  int v25; // edx
  __m128 v26; // xmm0
  __m128 v27; // xmm1
  __m128 v28; // xmm5
  __m128 v29; // xmm0
  __m128 v30; // xmm2
  __m128 v31; // xmm1
  __m128 v32; // xmm3
  __m128 v33; // xmm4
  __m128 v34; // xmm2
  __m128 v35; // xmm5
  __m128 v36; // xmm0
  float v37; // xmm6_4
  __m128 v38; // xmm5
  __m128 v39; // xmm2
  bool v40; // dl
  unsigned __int8 v41; // al
  float v42; // xmm1_4
  float v43; // xmm2_4
  float v44; // xmm0_4
  float v46; // xmm2_4
  float v47; // xmm1_4
  unsigned __int8 v48; // dl
  float fraction; // xmm3_4
  float v50; // xmm0_4
  float v51; // xmm1_4
  float v52; // xmm2_4
  float v53; // xmm0_4
  float v54; // xmm4_4
  float z; // xmm0_4
  __m128 v56; // [esp-Ch] [ebp-6Ch]
  unsigned int v57; // [esp-Ch] [ebp-6Ch]
  __m128 faceId_4; // [esp+4h] [ebp-5Ch]
  __m128 v59; // [esp+14h] [ebp-4Ch]
  __m128 invDelta_4a; // [esp+24h] [ebp-3Ch]
  __m128 invDelta_4; // [esp+24h] [ebp-3Ch]
  __m128 lastIn_4; // [esp+34h] [ebp-2Ch]
  __m128 lastIn_4a; // [esp+34h] [ebp-2Ch]
  VectorAligned *p_m_Delta; // [esp+50h] [ebp-10h]

  v5 = *inBoxMaxs;
  m_Delta = ray->m_Delta;
  m_Extents = ray->m_Extents;
  p_m_Delta = &ray->m_Delta;
  v8 = *inBoxMins;
  pTrace->fraction = 1.0;
  v9 = _mm_sub_ps(_mm_sub_ps(v8, (__m128)ray->m_Start), (__m128)m_Extents);
  v10 = _mm_add_ps(_mm_sub_ps(v5, (__m128)ray->m_Start), (__m128)m_Extents);
  v11 = _mm_cmplt_ps(v10, Four_Zeros);
  v12 = _mm_cmplt_ps(v10, (__m128)m_Delta);
  v13 = _mm_cmplt_ps(Four_Zeros, v9);
  v14 = _mm_cmplt_ps((__m128)m_Delta, v9);
  *(_WORD *)&pTrace->allsolid = 0;
  lastIn_4 = v13;
  if ( _mm_movemask_ps(_mm_and_ps(_mm_or_ps(_mm_and_ps(v12, v11), _mm_and_ps(v14, v13)), *(__m128 *)g_SIMD_clear_wmask)) == 0 )
  {
    v59 = *inInvDelta;
    invDelta_4a = _mm_mul_ps(*inInvDelta, v10);
    v15 = _mm_or_ps(_mm_xor_ps(v12, v11), _mm_xor_ps(v14, v13));
    v16 = _mm_mul_ps(*inInvDelta, v9);
    v17 = _mm_max_ps(v16, invDelta_4a);
    faceId_4 = _mm_andnot_ps(v15, Four_Negative_FLT_MAX);
    v18 = _mm_or_ps(_mm_and_ps(_mm_min_ps(v16, invDelta_4a), v15), faceId_4);
    v19 = _mm_andnot_ps(v15, Four_FLT_MAX);
    v20 = _mm_or_ps(_mm_and_ps(v17, v15), v19);
    v56 = v19;
    v21 = _mm_min_ps(_mm_min_ps(v20, _mm_shuffle_ps(v20, v20, 57)), _mm_shuffle_ps(v20, v20, 78));
    v22 = _mm_max_ps(_mm_max_ps(v18, _mm_shuffle_ps(v18, v18, 57)), _mm_shuffle_ps(v18, v18, 78));
    if ( _mm_movemask_ps(
           _mm_cmpeq_ps(
             _mm_cmplt_ps(
               _mm_min_ps(_mm_shuffle_ps(v21, v21, 0), Four_Ones),
               _mm_max_ps(_mm_shuffle_ps(v22, v22, 0), Four_Zeros)),
             Four_Zeros)) == 15 )
    {
      v23 = _mm_mul_ps(_mm_sub_ps(v9, Four_DistEpsilons), v59);
      v24 = _mm_mul_ps(_mm_add_ps(Four_DistEpsilons, v10), v59);
      v25 = _mm_movemask_ps(_mm_and_ps(_mm_or_ps(v11, lastIn_4), *(__m128 *)g_SIMD_clear_wmask));
      v26 = _mm_cmple_ps(v23, v24);
      v27 = _mm_andnot_ps(v26, *(__m128 *)g_CubeFaceIndex1);
      v28 = _mm_and_ps(*(__m128 *)g_CubeFaceIndex0, v26);
      v29 = _mm_or_ps(_mm_and_ps(_mm_min_ps(v23, v24), v15), faceId_4);
      v30 = _mm_or_ps(_mm_and_ps(_mm_max_ps(v23, v24), v15), v56);
      v31 = _mm_or_ps(v27, v28);
      v32 = _mm_shuffle_ps(v29, v29, 57);
      v33 = _mm_min_ps(_mm_min_ps(v30, _mm_shuffle_ps(v30, v30, 57)), _mm_shuffle_ps(v30, v30, 78));
      v34 = _mm_max_ps(v29, v32);
      v35 = _mm_cmplt_ps(v32, v29);
      v36 = _mm_shuffle_ps(v29, v29, 78);
      v37 = _mm_andnot_ps(v35, _mm_shuffle_ps(v31, v31, 57)).m128_f32[0];
      v32.m128_i32[0] = v31.m128_i32[0] & v35.m128_i32[0];
      v38 = _mm_cmplt_ps(v36, v34);
      v39 = _mm_max_ps(v34, v36);
      v57 = _mm_andnot_ps(v38, _mm_shuffle_ps(v31, v31, 78)).m128_u32[0]
          | (v32.m128_i32[0] | LODWORD(v37)) & v38.m128_i32[0];
      lastIn_4a = _mm_min_ps(_mm_shuffle_ps(v33, v33, 0), Four_Ones);
      v40 = v25 != 0;
      invDelta_4 = _mm_max_ps(_mm_shuffle_ps(v39, v39, 0), Four_Zeros);
      if ( _mm_movemask_ps(_mm_cmpeq_ps(_mm_cmplt_ps(lastIn_4a, invDelta_4), Four_Zeros)) == 15 )
      {
        v41 = v57;
        if ( !v40 || ray->m_IsRay && pTrace->fractionleftsolid > invDelta_4.m128_f32[0] )
        {
          v42 = ray->m_StartOffset.y + ray->m_Start.y;
          v43 = ray->m_StartOffset.z + ray->m_Start.z;
          pTrace->fraction = 0.0;
          v44 = ray->m_Start.x + ray->m_StartOffset.x;
          pTrace->startpos.x = v44;
          pTrace->startpos.y = v42;
          pTrace->startpos.z = v43;
          pTrace->startsolid = true;
          pTrace->contents = 1;
          pTrace->endpos.x = v44;
          pTrace->endpos.y = pTrace->startpos.y;
          pTrace->endpos.z = pTrace->startpos.z;
          if ( lastIn_4a.m128_f32[0] < 1.0 )
          {
            if ( lastIn_4a.m128_f32[0] > pTrace->fractionleftsolid )
            {
              v46 = ray->m_Delta.y * lastIn_4a.m128_f32[0];
              v47 = (float)(ray->m_Delta.z * lastIn_4a.m128_f32[0]) + pTrace->startpos.z;
              LODWORD(pTrace->fractionleftsolid) = lastIn_4a.m128_i32[0];
              pTrace->startpos.x = (float)(lastIn_4a.m128_f32[0] * p_m_Delta->x) + pTrace->startpos.x;
              pTrace->startpos.y = pTrace->startpos.y + v46;
              pTrace->startpos.z = v47;
            }
            return 1;
          }
          else
          {
            pTrace->allsolid = true;
            return 1;
          }
        }
        if ( invDelta_4.m128_f32[0] <= 1.0 )
        {
          LODWORD(pTrace->fraction) = invDelta_4.m128_i32[0];
          pTrace->plane.normal = vec3_origin;
          if ( v57 < 3 )
          {
            v48 = signbits[v57];
            LODWORD(pTrace->plane.dist) = inBoxMins->m128_i32[v57] ^ _mask__NegFloat_;
            *((_DWORD *)&pTrace->plane.normal.x + v57) = -1082130432;
            pTrace->plane.signbits = v48;
          }
          else
          {
            v41 = v57 - 3;
            pTrace->plane.dist = inBoxMaxs->m128_f32[v57 - 3];
            *((_DWORD *)&pTrace->endpos.x + v57) = 1065353216;
            pTrace->plane.signbits = 0;
          }
          fraction = pTrace->fraction;
          v50 = ray->m_Start.x + ray->m_StartOffset.x;
          v51 = ray->m_StartOffset.y + ray->m_Start.y;
          v52 = ray->m_StartOffset.z + ray->m_Start.z;
          pTrace->plane.type = v41;
          pTrace->contents = 1;
          if ( fraction == 1.0 )
          {
            pTrace->endpos.x = v50 + p_m_Delta->x;
            pTrace->endpos.y = ray->m_Delta.y + v51;
            v53 = ray->m_Delta.z + v52;
          }
          else
          {
            v54 = (float)(fraction * p_m_Delta->x) + v50;
            pTrace->endpos.y = (float)(ray->m_Delta.y * fraction) + v51;
            z = ray->m_Delta.z;
            pTrace->endpos.x = v54;
            v53 = (float)(z * fraction) + v52;
          }
          pTrace->endpos.z = v53;
          return 1;
        }
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10154310
// Name: ComputeBoxOffset
// Source: json
//------------------------------------------------------------------------------
long double __usercall ComputeBoxOffset@<st0>(const Ray_t *ray@<eax>)
{
  long double v2; // st7
  double v3; // st6

  if ( ray->m_IsRay )
    return 0.001;
  v2 = fabs(ray->m_Extents.y * ray->m_Delta.y)
     + fabs(ray->m_Extents.x * ray->m_Delta.x)
     + fabs(ray->m_Extents.z * ray->m_Delta.z);
  if ( (float)((float)((float)(ray->m_Delta.y * ray->m_Delta.y) + (float)(ray->m_Delta.x * ray->m_Delta.x))
             + (float)(ray->m_Delta.z * ray->m_Delta.z)) >= 1.0 )
    v3 = 1.0
       / (ray->m_Delta.z * ray->m_Delta.z + ray->m_Delta.y * ray->m_Delta.y + (float)(ray->m_Delta.x * ray->m_Delta.x));
  else
    v3 = 1.0 / 1.0;
  return v2 * v3 + 0.001;
}

//------------------------------------------------------------------------------
// Address: 0x101543B0
// Name: bool ComputeIntersectionBarycentricCoordinates(struct Ray_t const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float __near &,float __near &,float __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ComputeIntersectionBarycentricCoordinates(
        const Ray_t *ray,
        const Vector *v1,
        const Vector *v2,
        const Vector *v3,
        float *u,
        float *v,
        float *t)
{
  float v8; // xmm6_4
  float v9; // xmm2_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  float v12; // xmm1_4
  float v13; // xmm3_4
  float v14; // xmm6_4
  float v15; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm3_4
  float v22; // xmm7_4
  float v23; // xmm0_4
  float v24; // xmm5_4
  float v25; // xmm1_4
  float v26; // xmm4_4
  float v27; // xmm6_4
  float *v28; // edx
  float dirCrossEdge2_8; // [esp+8h] [ebp-1Ch]
  float edge1_8; // [esp+14h] [ebp-10h]
  float edge2; // [esp+18h] [ebp-Ch]
  float edge2_4; // [esp+1Ch] [ebp-8h]
  float edge2_8; // [esp+20h] [ebp-4h]
  float boxta; // [esp+30h] [ebp+Ch]
  float boxtb; // [esp+30h] [ebp+Ch]
  float boxt; // [esp+30h] [ebp+Ch]

  v8 = v3->z - v1->z;
  v9 = v3->x - v1->x;
  v10 = v2->x - v1->x;
  v11 = v2->y - v1->y;
  edge1_8 = v2->z - v1->z;
  v12 = v3->y - v1->y;
  boxta = ray->m_Delta.y;
  edge2_4 = v12;
  v13 = (float)(boxta * v8) - (float)(ray->m_Delta.z * v12);
  edge2_8 = v8;
  v14 = (float)(ray->m_Delta.z * v9) - (float)(ray->m_Delta.x * v8);
  edge2 = v9;
  dirCrossEdge2_8 = (float)(ray->m_Delta.x * v12) - (float)(boxta * v9);
  v15 = (float)((float)(v14 * v11) + (float)(v13 * v10)) + (float)(dirCrossEdge2_8 * edge1_8);
  if ( fabs(v15) < 0.000001 )
    return false;
  v17 = ray->m_Start.y - v1->y;
  v18 = 1.0 / v15;
  v19 = ray->m_Start.x - v1->x;
  boxtb = v18;
  v20 = ray->m_Start.z - v1->z;
  *u = (float)((float)((float)(v17 * v14) + (float)(v19 * v13)) + (float)(v20 * dirCrossEdge2_8)) * boxtb;
  v21 = (float)(v17 * edge1_8) - (float)(v20 * v11);
  v22 = v19 * edge1_8;
  v23 = v19 * v11;
  v24 = boxtb;
  v25 = (float)(v20 * v10) - v22;
  v26 = v23 - (float)(v17 * v10);
  *v = (float)((float)((float)(ray->m_Delta.x * v21) + (float)(v25 * ray->m_Delta.y)) + (float)(ray->m_Delta.z * v26))
     * boxtb;
  if ( t == nullptr )
    return true;
  boxt = ComputeBoxOffset(ray);
  v27 = (float)((float)((float)(v25 * edge2_4) + (float)(v21 * edge2)) + (float)(v26 * edge2_8)) * v24;
  *v28 = v27;
  return COERCE_FLOAT(LODWORD(boxt) ^ _mask__NegFloat_) <= v27 && v27 <= (float)(boxt + 1.0);
}

//------------------------------------------------------------------------------
// Address: 0x10154670
// Name: bool IsBoxIntersectingSphereExtents(class Vector const __near &,class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsBoxIntersectingSphereExtents(
        const Vector *boxCenter,
        const Vector *boxHalfDiag,
        const Vector *center,
        float radius)
{
  float v5; // xmm0_4
  float y; // xmm2_4
  float z; // xmm2_4
  float flDiff; // [esp+10h] [ebp+10h]
  float flDiffa; // [esp+10h] [ebp+10h]
  float flDiffb; // [esp+10h] [ebp+10h]

  v5 = 0.0;
  flDiff = fabs(center->x - boxCenter->x);
  if ( flDiff > boxHalfDiag->x )
    v5 = (float)(flDiff - boxHalfDiag->x) * (float)(flDiff - boxHalfDiag->x);
  y = boxHalfDiag->y;
  flDiffa = fabs(center->y - boxCenter->y);
  if ( flDiffa > y )
    v5 = (float)((float)(flDiffa - y) * (float)(flDiffa - y)) + v5;
  z = boxHalfDiag->z;
  flDiffb = fabs(center->z - boxCenter->z);
  if ( flDiffb > z )
    v5 = v5 + (float)((float)(flDiffb - z) * (float)(flDiffb - z));
  return (float)(radius * radius) > v5;
}

//------------------------------------------------------------------------------
// Address: 0x10154710
// Name: bool IsCircleIntersectingRectangle(class Vector2D const __near &,class Vector2D const __near &,class Vector2D const __near &,float)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsCircleIntersectingRectangle(
        const Vector2D *boxMin,
        const Vector2D *boxMax,
        const Vector2D *center,
        float radius)
{
  float x; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float y; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm2_4

  x = center->x;
  v5 = 0.0;
  if ( boxMin->x <= center->x )
  {
    if ( x <= boxMax->x )
      goto LABEL_6;
    v6 = boxMax->x - x;
  }
  else
  {
    v6 = x - boxMin->x;
  }
  v5 = v6 * v6;
LABEL_6:
  y = center->y;
  v8 = boxMin->y;
  if ( v8 <= y )
  {
    v9 = boxMax->y;
    if ( y > v9 )
      v5 = v5 + (float)((float)(v9 - y) * (float)(v9 - y));
  }
  else
  {
    v5 = v5 + (float)((float)(y - v8) * (float)(y - v8));
  }
  return (float)(radius * radius) > v5;
}

//------------------------------------------------------------------------------
// Address: 0x101547A0
// Name: bool IsSphereIntersectingCone(class Vector const __near &,float,class Vector const __near &,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsSphereIntersectingCone(
        const Vector *sphereCenter,
        float sphereRadius,
        const Vector *coneOrigin,
        const Vector *coneNormal,
        float coneSine,
        float coneCosine)
{
  float y; // xmm0_4
  float z; // xmm5_4
  float v8; // xmm1_4
  float v9; // xmm3_4
  bool result; // al
  float backCenter; // [esp+0h] [ebp-24h]
  float backCenter_4; // [esp+4h] [ebp-20h]
  float backCenter_8; // [esp+8h] [ebp-1Ch]
  float v14; // [esp+Ch] [ebp-18h]
  float x; // [esp+10h] [ebp-14h]
  float v16; // [esp+14h] [ebp-10h]

  y = coneNormal->y;
  z = coneNormal->z;
  backCenter_8 = coneOrigin->y;
  x = coneOrigin->x;
  backCenter = coneOrigin->z;
  v16 = sphereCenter->x;
  v8 = sphereCenter->x - (float)(coneOrigin->x - (float)(coneNormal->x * (float)(sphereRadius / coneSine)));
  v14 = sphereCenter->y;
  backCenter_4 = sphereCenter->z;
  result = false;
  if ( (float)((float)((float)(y * (float)(v14 - (float)(backCenter_8 - (float)(y * (float)(sphereRadius / coneSine)))))
                     + (float)(coneNormal->x * v8))
             + (float)(z * (float)(backCenter_4 - (float)(backCenter - (float)(z * (float)(sphereRadius / coneSine)))))) >= (float)(fsqrt((float)((float)((float)(v14 - (float)(backCenter_8 - (float)(y * (float)(sphereRadius / coneSine)))) * (float)(v14 - (float)(backCenter_8 - (float)(y * (float)(sphereRadius / coneSine))))) + (float)((float)(backCenter_4 - (float)(backCenter - (float)(z * (float)(sphereRadius / coneSine)))) * (float)(backCenter_4 - (float)(backCenter - (float)(z * (float)(sphereRadius / coneSine)))))) + (float)(v8 * v8)) * coneCosine) )
  {
    v9 = fsqrt(
           (float)((float)((float)(v14 - backCenter_8) * (float)(v14 - backCenter_8))
                 + (float)((float)(backCenter_4 - backCenter) * (float)(backCenter_4 - backCenter)))
         + (float)((float)(v16 - x) * (float)(v16 - x)));
    if ( COERCE_FLOAT(
           COERCE_UNSIGNED_INT(
             (float)((float)(y * (float)(v14 - backCenter_8)) + (float)(coneNormal->x * (float)(v16 - x)))
           + (float)(z * (float)(backCenter_4 - backCenter)))
         ^ _mask__NegFloat_) < (float)(v9 * coneSine)
      || sphereRadius >= v9 )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10154940
// Name: bool IsPointInBox(class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsPointInBox(const Vector *pt, const Vector *boxMin, const Vector *boxMax)
{
  float y; // xmm0_4
  float z; // xmm0_4
  bool result; // al

  result = false;
  if ( pt->x <= boxMax->x && boxMin->x <= pt->x )
  {
    y = pt->y;
    if ( y <= boxMax->y && boxMin->y <= y )
    {
      z = pt->z;
      if ( z <= boxMax->z && boxMin->z <= z )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10154990
// Name: bool IsBoxIntersectingBox(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsBoxIntersectingBox(
        const Vector *boxMin1,
        const Vector *boxMax1,
        const Vector *boxMin2,
        const Vector *boxMax2)
{
  return boxMin1->x <= boxMax2->x
      && boxMin2->x <= boxMax1->x
      && boxMin1->y <= boxMax2->y
      && boxMin2->y <= boxMax1->y
      && boxMin1->z <= boxMax2->z
      && boxMin2->z <= boxMax1->z;
}

//------------------------------------------------------------------------------
// Address: 0x10154B50
// Name: bool IsBoxIntersectingRay(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
bool __fastcall IsBoxIntersectingRay(
        const Vector *boxMin,
        const Vector *boxMax,
        const Vector *origin,
        const Vector *vecDelta,
        const Vector *vecInvDelta,
        unsigned int flTolerance)
{
  __m128 v6; // xmm0
  __m128 v7; // xmm4
  __m128 v8; // xmm6
  __m128 v9; // xmm2
  __m128 v10; // xmm3
  __m128 v11; // xmm5
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  __m128 v15; // xmm3
  __m128 v16; // xmm1
  __m128 v17; // xmm0
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  __m128 v20; // xmm1

  v6 = _mm_sub_ps(*(__m128 *)&boxMin->x, *(__m128 *)&origin->x);
  v7 = _mm_sub_ps(*(__m128 *)&boxMax->x, *(__m128 *)&origin->x);
  v8 = _mm_cmplt_ps(v7, Four_Zeros);
  v9 = _mm_cmplt_ps(v7, *(__m128 *)&vecDelta->x);
  v10 = _mm_cmplt_ps(*(__m128 *)&vecDelta->x, v6);
  v11 = _mm_cmplt_ps(Four_Zeros, v6);
  if ( _mm_movemask_ps(_mm_and_ps(_mm_or_ps(_mm_and_ps(v9, v8), _mm_and_ps(v10, v11)), *(__m128 *)g_SIMD_clear_wmask)) != 0 )
    return false;
  v13 = _mm_shuffle_ps((__m128)flTolerance, (__m128)flTolerance, 0);
  v14 = _mm_or_ps(_mm_xor_ps(v9, v8), _mm_xor_ps(v10, v11));
  v15 = _mm_or_ps(
          _mm_andnot_ps(v14, Four_Negative_FLT_MAX),
          _mm_and_ps(_mm_mul_ps(_mm_sub_ps(v6, v13), *(__m128 *)&vecInvDelta->x), v14));
  v16 = _mm_or_ps(
          _mm_and_ps(_mm_mul_ps(_mm_add_ps(v13, v7), *(__m128 *)&vecInvDelta->x), v14),
          _mm_andnot_ps(v14, Four_FLT_MAX));
  v17 = _mm_min_ps(v15, v16);
  v18 = _mm_max_ps(v15, v16);
  v19 = _mm_min_ps(_mm_min_ps(v18, _mm_shuffle_ps(v18, v18, 57)), _mm_shuffle_ps(v18, v18, 78));
  v20 = _mm_max_ps(_mm_max_ps(v17, _mm_shuffle_ps(v17, v17, 57)), _mm_shuffle_ps(v17, v17, 78));
  return _mm_movemask_ps(
           _mm_cmpeq_ps(
             _mm_cmplt_ps(
               _mm_min_ps(_mm_shuffle_ps(v19, v19, 0), Four_Ones),
               _mm_max_ps(_mm_shuffle_ps(v20, v20, 0), Four_Zeros)),
             Four_Zeros)) == 15;
}

//------------------------------------------------------------------------------
// Address: 0x10154C60
// Name: bool IsBoxIntersectingRay(class Vector const __near &,class Vector const __near &,struct Ray_t const __near &,float)
// Source: json
//------------------------------------------------------------------------------
bool __fastcall IsBoxIntersectingRay(
        const Vector *vecBoxMin,
        const Vector *vecBoxMax,
        const Ray_t *ray,
        float flTolerance)
{
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  float v9; // xmm5_4
  float v10; // xmm1_4
  float v11; // xmm6_4
  float v12; // xmm2_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  Vector boxMin; // [esp+4h] [ebp-18h] BYREF
  Vector boxMax; // [esp+10h] [ebp-Ch] BYREF

  x = ray->m_Extents.x;
  if ( ray->m_IsSwept )
  {
    v14 = vecBoxMin->y - ray->m_Extents.y;
    v15 = vecBoxMin->z - ray->m_Extents.z;
    v16 = vecBoxMin->x - x;
    boxMax.x = x + vecBoxMax->x;
    boxMax.y = vecBoxMax->y + ray->m_Extents.y;
    v17 = vecBoxMax->z + ray->m_Extents.z;
    boxMin.x = v16;
    boxMin.y = v14;
    boxMin.z = v15;
    boxMax.z = v17;
    return IsBoxIntersectingRay(&boxMin, &boxMax, origin: &ray->m_Start, vecDelta: &ray->m_Delta, flTolerance);
  }
  else
  {
    y = ray->m_Extents.y;
    z = ray->m_Extents.z;
    v7 = ray->m_Start.x - x;
    v8 = x + ray->m_Start.x;
    v9 = ray->m_Start.y - y;
    v10 = y + ray->m_Start.y;
    v11 = ray->m_Start.z - z;
    v12 = z + ray->m_Start.z;
    if ( flTolerance != 0.0 )
    {
      v7 = v7 - flTolerance;
      v9 = v9 - flTolerance;
      v11 = v11 - flTolerance;
      v8 = v8 + flTolerance;
      v10 = v10 + flTolerance;
      v12 = v12 + flTolerance;
    }
    return vecBoxMin->x <= v8
        && v7 <= vecBoxMax->x
        && vecBoxMin->y <= v10
        && v9 <= vecBoxMax->y
        && vecBoxMin->z <= v12
        && v11 <= vecBoxMax->z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10154D90
// Name: bool IsBoxIntersectingRay(union __m128 const __near &,union __m128 const __near &,union __m128 const __near &,union __m128 const __near &,union __m128 const __near &,union __m128 const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __fastcall IsBoxIntersectingRay(
        const __m128 *inBoxMin,
        const __m128 *inBoxMax,
        const __m128 *origin,
        const __m128 *delta,
        const __m128 *invDelta,
        const __m128 *vTolerance)
{
  __m128 v6; // xmm3
  __m128 v7; // xmm0
  __m128 v9; // xmm0
  __m128 v10; // xmm2
  __m128 v11; // xmm1
  __m128 v12; // xmm0
  __m128 v13; // xmm2
  __m128 v14; // xmm1

  v6 = _mm_sub_ps(*inBoxMax, *origin);
  v7 = _mm_sub_ps(*inBoxMin, *origin);
  if ( _mm_movemask_ps(
         _mm_and_ps(
           _mm_or_ps(
             _mm_and_ps(_mm_cmplt_ps(v6, *delta), _mm_cmplt_ps(v6, Four_Zeros)),
             _mm_and_ps(_mm_cmplt_ps(*delta, v7), _mm_cmplt_ps(Four_Zeros, v7))),
           *(__m128 *)g_SIMD_clear_wmask)) != 0 )
    return false;
  v9 = _mm_mul_ps(_mm_sub_ps(v7, *vTolerance), *invDelta);
  v10 = _mm_mul_ps(_mm_add_ps(*vTolerance, v6), *invDelta);
  v11 = _mm_max_ps(v9, v10);
  v12 = _mm_min_ps(v9, v10);
  v13 = _mm_min_ps(_mm_min_ps(v11, _mm_shuffle_ps(v11, v11, 57)), _mm_shuffle_ps(v11, v11, 78));
  v14 = _mm_max_ps(_mm_max_ps(v12, _mm_shuffle_ps(v12, v12, 57)), _mm_shuffle_ps(v12, v12, 78));
  return _mm_movemask_ps(
           _mm_cmpeq_ps(
             _mm_cmplt_ps(
               _mm_min_ps(_mm_shuffle_ps(v13, v13, 0), Four_Ones),
               _mm_max_ps(_mm_shuffle_ps(v14, v14, 0), Four_Zeros)),
             Four_Zeros)) == 15;
}

//------------------------------------------------------------------------------
// Address: 0x10154E60
// Name: bool IntersectRayWithRay(struct Ray_t const __near &,struct Ray_t const __near &,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IntersectRayWithRay(const Ray_t *ray0, const Ray_t *ray1, float *t, float *s)
{
  float y; // ecx
  float z; // edx
  float v7; // ecx
  float v8; // edx
  float v9; // xmm6_4
  float v10; // xmm2_4
  float v11; // xmm4_4
  float v13; // xmm5_4
  float v14; // xmm7_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm4_4
  float v21; // xmm5_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm3_4
  float x; // xmm4_4
  float v26; // xmm0_4
  float v27; // xmm0_4
  float v28; // xmm5_4
  float v29; // xmm0_4
  float v30; // xmm6_4
  float v0xv1; // [esp+14h] [ebp-28h]
  Vector v1; // [esp+20h] [ebp-1Ch] BYREF
  Vector v0; // [esp+2Ch] [ebp-10h] BYREF
  float lengthSq; // [esp+38h] [ebp-4h]
  float ray1a; // [esp+48h] [ebp+Ch]

  y = ray0->m_Delta.y;
  z = ray0->m_Delta.z;
  v0.x = ray0->m_Delta.x;
  v1.x = ray1->m_Delta.x;
  v0.y = y;
  v7 = ray1->m_Delta.y;
  v0.z = z;
  v8 = ray1->m_Delta.z;
  v1.y = v7;
  v1.z = v8;
  VectorNormalize(vec: &v0);
  VectorNormalize(vec: &v1);
  v9 = v1.z;
  v0xv1 = (float)(v1.z * v0.y) - (float)(v1.y * v0.z);
  v10 = (float)(v0.z * v1.x) - (float)(v1.z * v0.x);
  v11 = (float)(v1.y * v0.x) - (float)(v1.x * v0.y);
  lengthSq = (float)((float)(v10 * v10) + (float)(v0xv1 * v0xv1)) + (float)(v11 * v11);
  if ( lengthSq == 0.0 )
  {
    *t = 0.0;
    *s = 0.0;
    return false;
  }
  v13 = ray1->m_Start.x - ray0->m_Start.x;
  v14 = ray1->m_Start.z - ray0->m_Start.z;
  v15 = ray1->m_Start.y - ray0->m_Start.y;
  v16 = v15 * v0xv1;
  v17 = (float)(v14 * v0xv1) - (float)(v11 * v13);
  v18 = (float)(v15 * v11) - (float)(v14 * v10);
  ray1a = (float)(v10 * v13) - v16;
  v19 = v1.y;
  v20 = (float)((float)((float)-v17 * v1.y) + (float)((float)-v18 * v1.x)) + (float)((float)-ray1a * v1.z);
  v21 = (float)-v17 * v0.y;
  v22 = 1.0 / lengthSq;
  v23 = -v18;
  v24 = (float)(1.0 / lengthSq) * v20;
  x = v0.x;
  v26 = v23 * v0.x;
  *t = v24;
  v27 = v26 + v21;
  v28 = v0.z;
  v29 = (float)(v27 + (float)((float)-ray1a * v0.z)) * v22;
  *s = v29;
  v30 = v9 * v29;
  return (float)(ray0->m_Start.x + (float)(x * *t)) == (float)(ray1->m_Start.x + (float)(v1.x * v29))
      && (float)((float)(*t * v0.y) + ray0->m_Start.y) == (float)(ray1->m_Start.y + (float)(v19 * v29))
      && (float)(ray0->m_Start.z + (float)(v28 * *t)) == (float)(ray1->m_Start.z + v30);
}

//------------------------------------------------------------------------------
// Address: 0x101550B0
// Name: float IntersectRayWithPlane(class Vector const __near &,class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl IntersectRayWithPlane(const Vector *org, const Vector *dir, const Vector *normal, float dist)
{
  float x; // xmm2_4
  float z; // xmm3_4
  float denom; // [esp+14h] [ebp+Ch]
  float normala; // [esp+18h] [ebp+10h]

  x = normal->x;
  z = normal->z;
  normala = normal->y;
  denom = (float)((float)(dir->y * normala) + (float)(dir->x * x)) + (float)(dir->z * z);
  if ( denom == 0.0 )
    return 0.0;
  else
    return (dist - (org->y * normala + org->x * x + org->z * z)) * (1.0 / denom);
}

//------------------------------------------------------------------------------
// Address: 0x10155140
// Name: float IntersectRayWithAAPlane(class Vector const __near &,class Vector const __near &,int,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl IntersectRayWithAAPlane(
        const Vector *vecStart,
        const Vector *vecEnd,
        int nAxis,
        float flSign,
        float flDist)
{
  float v5; // xmm0_4
  int nAxisa; // [esp+10h] [ebp+10h]

  v5 = (float)(*(&vecEnd->x + nAxis) - *(&vecStart->x + nAxis)) * flSign;
  nAxisa = *((int *)&vecStart->x + nAxis);
  if ( v5 == 0.0 )
    return 0.0;
  else
    return (flDist - *(float *)&nAxisa * flSign) * (1.0 / v5);
}

//------------------------------------------------------------------------------
// Address: 0x10155190
// Name: bool IntersectRayWithBox(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,struct BoxTraceInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IntersectRayWithBox(
        const Vector *vecRayStart,
        const Vector *vecRayDelta,
        const Vector *boxMins,
        const Vector *boxMaxs,
        float flTolerance,
        BoxTraceInfo_t *pTrace)
{
  const Vector *v6; // ecx
  const Vector *v7; // edi
  int v8; // esi
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm1_4

  v6 = vecRayStart;
  v7 = boxMaxs - 1;
  v8 = 0;
  pTrace->t1 = -1.0;
  pTrace->t2 = 1.0;
  pTrace->hitside = -1;
  pTrace->startsolid = true;
  do
  {
    if ( v8 < 3 )
    {
      v9 = *(float *)((char *)&v6->x + (char *)boxMins - (char *)vecRayStart) - v6->x;
      v10 = v9 - *(float *)((char *)&v6->x + (char *)vecRayDelta - (char *)vecRayStart);
    }
    else
    {
      v9 = *(float *)((char *)&v7->x + (char *)vecRayStart - (char *)boxMaxs) - v7->x;
      v10 = *(float *)((char *)&v7->x + (char *)vecRayDelta - (char *)boxMaxs) + v9;
    }
    if ( v9 > 0.0 && v10 > 0.0 )
    {
      pTrace->startsolid = false;
      return false;
    }
    if ( v9 > 0.0 || v10 > 0.0 )
    {
      if ( v9 > 0.0 )
        pTrace->startsolid = false;
      if ( v9 <= v10 )
      {
        v13 = (float)(v9 + flTolerance) / (float)(v9 - v10);
        if ( pTrace->t2 > v13 )
          pTrace->t2 = v13;
      }
      else
      {
        v11 = v9 - flTolerance;
        if ( (float)(v9 - flTolerance) < 0.0 )
          v11 = 0.0;
        v12 = v11 / (float)(v9 - v10);
        if ( v12 > pTrace->t1 )
        {
          pTrace->t1 = v12;
          pTrace->hitside = v8;
        }
      }
    }
    ++v8;
    v7 = (const Vector *)((char *)v7 + 4);
    v6 = (const Vector *)((char *)v6 + 4);
  }
  while ( v8 < 6 );
  return pTrace->startsolid || pTrace->t2 > pTrace->t1 && pTrace->t1 >= 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x101552E0
// Name: bool IntersectRayWithBox(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,class CBaseTrace __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IntersectRayWithBox(
        const Vector *vecRayStart,
        const Vector *vecRayDelta,
        const Vector *boxMins,
        const Vector *boxMaxs,
        float flTolerance,
        CBaseTrace *pTrace,
        float *pFractionLeftSolid)
{
  bool startsolid; // al
  float t2; // xmm0_4
  float t1; // xmm2_4
  bool v10; // cc
  int hitside; // eax
  double v12; // st7
  bool v14; // al
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm3_4
  float y; // xmm1_4
  BoxTraceInfo_t v20; // [esp+14h] [ebp-10h] BYREF

  pTrace->startpos = *vecRayStart;
  pTrace->endpos = *vecRayStart;
  pTrace->endpos.x = vecRayDelta->x + pTrace->endpos.x;
  pTrace->endpos.y = pTrace->endpos.y + vecRayDelta->y;
  pTrace->endpos.z = pTrace->endpos.z + vecRayDelta->z;
  *(_WORD *)&pTrace->allsolid = 0;
  *(_QWORD *)&pTrace->fraction = 1065353216;
  if ( IntersectRayWithBox(vecRayStart, vecRayDelta, boxMins, boxMaxs, flTolerance, pTrace: &v20) )
  {
    startsolid = v20.startsolid;
    t2 = v20.t2;
    t1 = v20.t1;
    v10 = v20.t2 <= v20.t1;
    pTrace->startsolid = v20.startsolid;
    if ( !v10 && t1 >= 0.0 )
    {
      hitside = v20.hitside;
      pTrace->fraction = t1;
      pTrace->endpos.x = (float)(vecRayDelta->x * t1) + pTrace->startpos.x;
      pTrace->endpos.y = (float)(vecRayDelta->y * t1) + pTrace->startpos.y;
      pTrace->endpos.z = (float)(t1 * vecRayDelta->z) + pTrace->startpos.z;
      pTrace->contents = 1;
      pTrace->plane.normal = vec3_origin;
      if ( hitside < 3 )
      {
        LODWORD(pTrace->plane.dist) = *((_DWORD *)&boxMins->x + hitside) ^ _mask__NegFloat_;
        *((_DWORD *)&pTrace->plane.normal.x + hitside) = -1082130432;
      }
      else
      {
        v12 = *(&boxMaxs[-1].x + hitside);
        hitside -= 3;
        pTrace->plane.dist = v12;
        *((_DWORD *)&pTrace->plane.normal.x + hitside) = 1065353216;
      }
      pTrace->plane.type = hitside;
      return 1;
    }
    if ( startsolid )
    {
      v14 = t2 <= 0.0 || t2 >= 1.0;
      pTrace->allsolid = v14;
      pTrace->fraction = 0.0;
      if ( pFractionLeftSolid != nullptr )
        *pFractionLeftSolid = t2;
      pTrace->endpos = pTrace->startpos;
      pTrace->contents = 1;
      pTrace->plane.dist = pTrace->startpos.x;
      pTrace->plane.normal.y = 0.0;
      pTrace->plane.normal.z = 0.0;
      pTrace->plane.normal.x = 1.0;
      pTrace->plane.type = 0;
      v15 = vecRayDelta->x * t2;
      v16 = vecRayDelta->y * t2;
      v17 = (float)(t2 * vecRayDelta->z) + vecRayStart->z;
      v18 = vecRayStart->x + v15;
      y = vecRayStart->y;
      pTrace->startpos.x = v18;
      pTrace->startpos.y = y + v16;
      pTrace->startpos.z = v17;
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10155510
// Name: bool IntersectRayWithBox(struct Ray_t const __near &,class Vector const __near &,class Vector const __near &,float,class CBaseTrace __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IntersectRayWithBox(
        const Ray_t *ray,
        const Vector *boxMins,
        const Vector *boxMaxs,
        float flTolerance,
        CBaseTrace *pTrace,
        const Ray_t *pFractionLeftSolid)
{
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  char result; // al
  Vector v12; // [esp+14h] [ebp-18h] BYREF
  Vector v13; // [esp+20h] [ebp-Ch] BYREF

  if ( ray->m_IsRay )
    return IntersectRayWithBox(
             vecRayStart: &ray->m_Start,
             vecRayDelta: &ray->m_Delta,
             boxMins,
             boxMaxs,
             flTolerance,
             pTrace,
             pFractionLeftSolid: &pFractionLeftSolid->m_Start.x);
  v6 = boxMaxs->y + ray->m_Extents.y;
  v7 = boxMins->x - ray->m_Extents.x;
  v8 = boxMins->y - ray->m_Extents.y;
  v12.z = boxMins->z - ray->m_Extents.z;
  v9 = boxMaxs->x + ray->m_Extents.x;
  v13.y = v6;
  v10 = boxMaxs->z + ray->m_Extents.z;
  v12.x = v7;
  v12.y = v8;
  v13.x = v9;
  v13.z = v10;
  result = IntersectRayWithBox(
             vecRayStart: &ray->m_Start,
             vecRayDelta: &ray->m_Delta,
             boxMins: &v12,
             boxMaxs: &v13,
             flTolerance,
             pTrace,
             pFractionLeftSolid: &pFractionLeftSolid->m_Start.x);
  pTrace->startpos.x = pTrace->startpos.x + ray->m_StartOffset.x;
  pTrace->startpos.y = pTrace->startpos.y + ray->m_StartOffset.y;
  pTrace->startpos.z = pTrace->startpos.z + ray->m_StartOffset.z;
  pTrace->endpos.x = pTrace->endpos.x + ray->m_StartOffset.x;
  pTrace->endpos.y = pTrace->endpos.y + ray->m_StartOffset.y;
  pTrace->endpos.z = pTrace->endpos.z + ray->m_StartOffset.z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10155630
// Name: void ComputeSupportMap(class Vector const __near &,class Vector const __near &,class Vector const __near &,float __near * const)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeSupportMap(
        const Vector *vecDirection,
        const Vector *vecBoxMins,
        const Vector *vecBoxMaxs,
        float *pDist)
{
  unsigned int v4; // edx
  unsigned int v5; // edx
  unsigned int v6; // edx

  v4 = 4 * (vecDirection->x > 0.0);
  pDist[v4 / 4] = vecBoxMaxs->x * vecDirection->x;
  pDist[v4 / 0xFFFFFFFC + 1] = vecDirection->x * vecBoxMins->x;
  v5 = 4 * (vecDirection->y > 0.0);
  pDist[v5 / 4] = (float)(vecBoxMaxs->y * vecDirection->y) + pDist[v5 / 4];
  pDist[v5 / 0xFFFFFFFC + 1] = (float)(vecBoxMins->y * vecDirection->y) + pDist[v5 / 0xFFFFFFFC + 1];
  v6 = 4 * (vecDirection->z > 0.0);
  pDist[v6 / 4] = (float)(vecBoxMaxs->z * vecDirection->z) + pDist[v6 / 4];
  pDist[v6 / 0xFFFFFFFC + 1] = (float)(vecBoxMins->z * vecDirection->z) + pDist[v6 / 0xFFFFFFFC + 1];
}

//------------------------------------------------------------------------------
// Address: 0x10155710
// Name: void ResolveQuadratic(double,double,class Vector,class Vector,class Vector,class Vector,class Vector,class Vector,int,double __near &,double __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ResolveQuadratic(
        double tPlus,
        long double tMinus,
        Vector axisU0,
        Vector axisU1,
        Vector axisV0,
        Vector axisV1,
        Vector axisOrigin,
        Vector pt,
        int projU,
        long double *s,
        long double *t)
{
  double v11; // st5
  long double v13; // st4
  long double v14; // st6
  long double v15; // st4
  double v16; // rtt
  long double v17; // st3
  double v18; // st6
  long double v19; // st2
  double *v20; // ecx
  long double v21; // st7
  long double *v22; // eax
  long double v23; // st6
  long double v24; // rt2
  long double v25; // st3
  double v26; // st4
  long double v27; // st3
  long double v28; // st2
  double v29; // st1
  long double v30; // st4
  long double v31; // rtt
  long double v32; // st2
  long double v33; // st6
  long double v34; // rt0
  long double v35; // st3
  double v36; // st5
  long double v37; // rt2
  long double v38; // rtt
  long double v39; // st3
  double v40; // st7
  long double v41; // rt0
  long double v42; // st3
  long double v43; // st4
  long double v44; // st3
  long double v45; // st2
  long double v46; // st6
  long double v47; // st2
  long double v48; // st3
  bool v49; // cc
  long double v50; // st4
  double *v51; // edx
  double *v52; // ecx
  double sPlus; // [esp+0h] [ebp-8h]
  double sMinus; // [esp+10h] [ebp+8h]
  double s0; // [esp+18h] [ebp+10h]

  v11 = 1.0;
  v13 = (1.0 - tPlus) * *(&axisU0.x + projU) + *(&axisU1.x + projU) * tPlus;
  v14 = *(&axisU1.x + projU) * tMinus + *(&axisU0.x + projU) * (1.0 - tMinus);
  sPlus = -99999.0;
  sMinus = -99999.0;
  if ( fabs(v13) < 0.00001 )
  {
    v15 = -99999.0;
  }
  else
  {
    sPlus = (*(&pt.x + projU) - *(&axisOrigin.x + projU) - *(&axisV0.x + projU) * tPlus) / v13;
    v15 = sPlus;
  }
  if ( fabs(v14) < 0.00001 )
  {
    v18 = tPlus;
    v17 = -99999.0;
  }
  else
  {
    v16 = tPlus;
    v17 = (*(&pt.x + projU) - *(&axisOrigin.x + projU) - *(&axisV0.x + projU) * tMinus) / v14;
    v18 = v16;
    sMinus = v17;
  }
  v19 = v18;
  if ( v18 >= 0.0 )
  {
    if ( v18 <= 1.0 && v15 >= 0.0 && v15 <= 1.0 )
    {
      v20 = t;
      *s = v15;
      *v20 = v18;
      return;
    }
    v19 = v18;
    v11 = 1.0;
  }
  v21 = v19;
  if ( tMinus < 0.0 )
  {
    v23 = tMinus;
  }
  else if ( v11 < tMinus )
  {
    v23 = tMinus;
  }
  else
  {
    if ( v17 >= 0.0 && v11 >= v17 )
    {
      v22 = t;
      *s = v17;
      *v22 = tMinus;
      return;
    }
    v23 = tMinus;
  }
  v24 = v17;
  v25 = v15;
  v26 = v24;
  s0 = v25;
  if ( v25 >= v11 )
    s0 = v25 - v11;
  v27 = v19;
  if ( v19 >= v11 )
    v21 = v19 - v11;
  v28 = v26;
  v29 = v26;
  v30 = v23;
  if ( v29 >= v11 )
    v28 = sMinus - v11;
  v31 = v28;
  v32 = v23;
  v33 = v31;
  if ( v32 < v11 )
  {
    v36 = v32;
  }
  else
  {
    v34 = v27;
    v35 = v32 - v11;
    v36 = v32;
    v37 = v35;
    v27 = v34;
    v30 = v37;
  }
  v38 = v27;
  v39 = v21;
  v40 = v38;
  v41 = fabs(v39);
  v42 = v30;
  v43 = fabs(v33);
  v44 = fabs(v42);
  v45 = v41;
  v46 = fabs(s0);
  if ( v41 > v46 )
    v46 = v45;
  v47 = v44;
  v48 = v43;
  v49 = v47 <= v43;
  v50 = v47;
  if ( v49 )
    v50 = v48;
  if ( v46 <= v50 )
  {
    v52 = t;
    *s = sPlus;
    *v52 = v40;
  }
  else
  {
    v51 = t;
    *s = sMinus;
    *v51 = v36;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101559A0
// Name: void TexCoordInQuadFromBarycentric(class Vector2D const __near &,class Vector2D const __near &,class Vector2D const __near &,class Vector2D const __near &,class Vector2D const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TexCoordInQuadFromBarycentric(
        const Vector2D *v1,
        const Vector2D *v2,
        const Vector2D *v3,
        const Vector2D *v4,
        const Vector2D *uv,
        Vector2D *texCoord)
{
  float y; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm1_4
  float x; // xmm4_4

  y = uv->y;
  v7 = (float)((float)(v4->x - v1->x) * y) + v1->x;
  v8 = (float)((float)(v4->y - v1->y) * y) + v1->y;
  v9 = (float)((float)(v3->y - v2->y) * y) + v2->y;
  x = uv->x;
  texCoord->x = (float)((float)((float)((float)((float)(v3->x - v2->x) * y) + v2->x) - v7) * uv->x) + v7;
  texCoord->y = (float)((float)(v9 - v8) * x) + v8;
}

//------------------------------------------------------------------------------
// Address: 0x10155A30
// Name: void ComputePointFromBarycentric(class Vector2D const __near &,class Vector2D const __near &,class Vector2D const __near &,float,float,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputePointFromBarycentric(
        const Vector2D *v0,
        const Vector2D *v1,
        const Vector2D *v2,
        float u,
        float v,
        Vector2D *pt)
{
  float v6; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm0_4

  v6 = (float)(v1->y - v0->y) * u;
  v7 = (float)(v2->y - v0->y) * v;
  v8 = (float)((float)(v1->x - v0->x) * u) + v0->x;
  v9 = (float)(v2->x - v0->x) * v;
  pt->x = v8;
  v10 = v6 + v0->y;
  pt->x = v9 + v8;
  pt->y = v7 + v10;
}

//------------------------------------------------------------------------------
// Address: 0x10155AA0
// Name: bool AxisTestEdgeCrossX3(float,float,float,float,class Vector const __near &,class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
char __cdecl AxisTestEdgeCrossX3(
        float flEdgeZ,
        float flEdgeY,
        float flAbsEdgeZ,
        float flAbsEdgeY,
        const Vector *p1,
        const Vector *p2,
        const Vector *vecExtents,
        float flTolerance)
{
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm0_4

  v8 = (float)(p1->y * flEdgeZ) - (float)(p1->z * flEdgeY);
  v9 = (float)(p2->y * flEdgeZ) - (float)(p2->z * flEdgeY);
  v10 = (float)((float)(vecExtents->y * flAbsEdgeZ) + (float)(vecExtents->z * flAbsEdgeY)) + flTolerance;
  if ( v9 <= v8 )
  {
    if ( v9 > v10 || COERCE_FLOAT(LODWORD(v10) ^ _mask__NegFloat_) > v8 )
      return 0;
  }
  else if ( v8 > v10 || COERCE_FLOAT(LODWORD(v10) ^ _mask__NegFloat_) > v9 )
  {
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10155B30
// Name: bool IsBoxIntersectingTriangle(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,struct cplane_t const __near &,float)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsBoxIntersectingTriangle(
        const Vector *vecBoxCenter,
        const Vector *vecBoxExtents,
        const Vector *v1,
        const Vector *v2,
        const Vector *v3,
        const cplane_t *plane,
        float flTolerance)
{
  float v9; // xmm5_4
  float v10; // xmm6_4
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float y; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm2_4
  float z; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm3_4
  float v25; // xmm4_4
  float v26; // xmm2_4
  long double v27; // st7
  long double v28; // st6
  long double v29; // st7
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  bool v33; // cc
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm0_4
  bool v37; // cc
  long double v38; // st7
  long double v39; // st6
  long double v40; // st7
  float v41; // xmm0_4
  float v42; // xmm1_4
  float v43; // xmm2_4
  bool v44; // cc
  float v45; // xmm1_4
  float v46; // xmm2_4
  float v47; // xmm0_4
  bool v48; // cc
  long double v49; // st7
  long double v50; // st6
  long double v51; // st7
  float v52; // xmm0_4
  float v53; // xmm1_4
  float v54; // xmm3_4
  bool v55; // cc
  float v56; // xmm1_4
  float v57; // xmm0_4
  float v58; // xmm2_4
  bool v59; // cc
  float v60; // xmm1_4
  float v61; // xmm6_4
  float v62; // xmm0_4
  float v63; // xmm1_4
  float v64; // xmm0_4
  float v65; // xmm1_4
  float v66; // xmm6_4
  float v67; // xmm1_4
  float v69; // [esp-28h] [ebp-68h]
  float v70; // [esp-28h] [ebp-68h]
  float v71; // [esp-28h] [ebp-68h]
  float v72; // [esp-24h] [ebp-64h]
  float v73; // [esp-24h] [ebp-64h]
  float v74; // [esp-24h] [ebp-64h]
  float flEdgeZ; // [esp+0h] [ebp-40h] BYREF
  float flEdgeY; // [esp+4h] [ebp-3Ch]
  float flAbsEdgeZ; // [esp+8h] [ebp-38h]
  Vector flAbsEdgeY; // [esp+Ch] [ebp-34h] BYREF
  Vector v79; // [esp+18h] [ebp-28h] BYREF
  Vector v80; // [esp+24h] [ebp-1Ch] BYREF
  float v81; // [esp+30h] [ebp-10h]
  Vector p3; // [esp+34h] [ebp-Ch]
  float p2_8; // [esp+48h] [ebp+8h]
  float p1_4; // [esp+50h] [ebp+10h]
  float p1_4a; // [esp+50h] [ebp+10h]
  float p1_8; // [esp+54h] [ebp+14h]
  float vecAbsEdge; // [esp+58h] [ebp+18h]
  float vecAbsEdgea; // [esp+58h] [ebp+18h]

  v9 = v1->x - vecBoxCenter->x;
  v10 = v2->x - vecBoxCenter->x;
  v11 = v3->x - vecBoxCenter->x;
  p3.z = vecBoxCenter->x;
  v80.x = v9;
  v79.x = v10;
  flAbsEdgeY.x = v11;
  v12 = v9;
  v13 = v9;
  if ( v9 > v10 )
    v13 = v10;
  if ( v10 > v9 )
    v12 = v10;
  if ( v13 > v11 )
    v13 = v11;
  if ( v11 > v12 )
    v12 = v11;
  p2_8 = vecBoxExtents->x;
  v14 = vecBoxExtents->x + flTolerance;
  if ( v13 > v14 || (float)-v14 > v12 )
    return false;
  y = vecBoxCenter->y;
  v16 = v1->y - y;
  v17 = v2->y - y;
  v18 = v3->y - y;
  v80.y = v16;
  v79.y = v17;
  flAbsEdgeY.y = v18;
  v19 = v16;
  v20 = v16;
  if ( v16 > v17 )
    v20 = v17;
  if ( v17 > v16 )
    v19 = v17;
  if ( v20 > v18 )
    v20 = v18;
  if ( v18 > v19 )
    v19 = v18;
  p1_8 = vecBoxExtents->y;
  if ( v20 > (float)(p1_8 + flTolerance) || (float)-(float)(p1_8 + flTolerance) > v19 )
    return false;
  z = vecBoxCenter->z;
  v22 = v1->z - z;
  v23 = v2->z - z;
  v24 = v3->z - z;
  v80.z = v22;
  v79.z = v23;
  flAbsEdgeY.z = v24;
  v25 = v22;
  v26 = v22;
  if ( v22 > v23 )
    v26 = v23;
  if ( v23 > v22 )
    v25 = v23;
  if ( v26 > v24 )
    v26 = v24;
  if ( v24 > v25 )
    v25 = v24;
  p1_4 = vecBoxExtents->z;
  if ( v26 > (float)(p1_4 + flTolerance) )
    return false;
  if ( (float)-(float)(p1_4 + flTolerance) > v25 )
    return false;
  v27 = v79.y - v80.y;
  flEdgeY = v27;
  flEdgeZ = v10 - v9;
  v28 = v79.z - v80.z;
  flAbsEdgeZ = v28;
  p3.x = fabs(v27);
  p3.y = fabs(v28);
  v72 = v27;
  v69 = v28;
  if ( AxisTestEdgeCrossX3(
         flEdgeZ: v69,
         flEdgeY: v72,
         flAbsEdgeZ: p3.y,
         flAbsEdgeY: p3.x,
         p1: &v80,
         p2: &flAbsEdgeY,
         vecExtents: vecBoxExtents,
         flTolerance) == 0 )
    return false;
  v29 = fabs(flEdgeZ);
  v81 = v29;
  v30 = (float)(flEdgeZ * v80.z) - (float)(flAbsEdgeZ * v80.x);
  vecAbsEdge = v29 * p1_4 + p2_8 * p3.y;
  v31 = (float)(flEdgeZ * flAbsEdgeY.z) - (float)(flAbsEdgeZ * flAbsEdgeY.x);
  v32 = vecAbsEdge + flTolerance;
  if ( v31 <= v30 )
  {
    if ( v31 > v32 )
      return false;
    v33 = (float)-v32 <= v30;
  }
  else
  {
    if ( v30 > v32 )
      return false;
    v33 = (float)-v32 <= v31;
  }
  if ( v33 )
  {
    v34 = (float)(flEdgeY * v79.x) - (float)(flEdgeZ * v79.y);
    v35 = (float)(flEdgeY * flAbsEdgeY.x) - (float)(flEdgeZ * flAbsEdgeY.y);
    v36 = (float)((float)(p1_8 * v81) + (float)(p2_8 * p3.x)) + flTolerance;
    if ( v34 <= v35 )
    {
      if ( v34 > v36 )
        return false;
      v37 = (float)-v36 <= v35;
    }
    else
    {
      if ( v35 > v36 )
        return false;
      v37 = (float)-v36 <= v34;
    }
    if ( !v37 )
      return false;
    v38 = flAbsEdgeY.y - v79.y;
    flEdgeY = v38;
    flEdgeZ = flAbsEdgeY.x - v79.x;
    v39 = flAbsEdgeY.z - v79.z;
    flAbsEdgeZ = v39;
    p3.x = fabs(v38);
    p3.y = fabs(v39);
    v73 = v38;
    v70 = v39;
    if ( AxisTestEdgeCrossX3(
           flEdgeZ: v70,
           flEdgeY: v73,
           flAbsEdgeZ: p3.y,
           flAbsEdgeY: p3.x,
           p1: &v80,
           p2: &v79,
           vecExtents: vecBoxExtents,
           flTolerance) == 0 )
      return false;
    v40 = fabs(flEdgeZ);
    v81 = v40;
    v41 = (float)(flEdgeZ * v80.z) - (float)(flAbsEdgeZ * v80.x);
    vecAbsEdgea = v40 * p1_4 + p2_8 * p3.y;
    v42 = (float)(flEdgeZ * v79.z) - (float)(flAbsEdgeZ * v79.x);
    v43 = vecAbsEdgea + flTolerance;
    if ( v42 <= v41 )
    {
      if ( v42 > v43 )
        return false;
      v44 = (float)-v43 <= v41;
    }
    else
    {
      if ( v41 > v43 )
        return false;
      v44 = (float)-v43 <= v42;
    }
    if ( v44 )
    {
      v45 = (float)(flEdgeY * v80.x) - (float)(flEdgeZ * v80.y);
      v46 = (float)(flEdgeY * flAbsEdgeY.x) - (float)(flEdgeZ * flAbsEdgeY.y);
      v47 = (float)((float)(p1_8 * v81) + (float)(p2_8 * p3.x)) + flTolerance;
      if ( v46 <= v45 )
      {
        if ( v46 > v47 )
          return false;
        v48 = (float)-v47 <= v45;
      }
      else
      {
        if ( v45 > v47 )
          return false;
        v48 = (float)-v47 <= v46;
      }
      if ( !v48 )
        return false;
      v49 = v80.y - flAbsEdgeY.y;
      flEdgeY = v49;
      flEdgeZ = v80.x - flAbsEdgeY.x;
      v50 = v80.z - flAbsEdgeY.z;
      flAbsEdgeZ = v50;
      p3.x = fabs(v49);
      p3.y = fabs(v50);
      v74 = v49;
      v71 = v50;
      if ( AxisTestEdgeCrossX3(
             flEdgeZ: v71,
             flEdgeY: v74,
             flAbsEdgeZ: p3.y,
             flAbsEdgeY: p3.x,
             p1: &v80,
             p2: &v79,
             vecExtents: vecBoxExtents,
             flTolerance) == 0 )
        return false;
      v51 = fabs(flEdgeZ);
      v81 = v51;
      v52 = (float)(flEdgeZ * v80.z) - (float)(flAbsEdgeZ * v80.x);
      p1_4a = v51 * p1_4 + p2_8 * p3.y;
      v53 = (float)(flEdgeZ * v79.z) - (float)(flAbsEdgeZ * v79.x);
      v54 = p1_4a + flTolerance;
      if ( v53 <= v52 )
      {
        if ( v53 > v54 )
          return false;
        v55 = (float)-v54 <= v52;
      }
      else
      {
        if ( v52 > v54 )
          return false;
        v55 = (float)-v54 <= v53;
      }
      if ( v55 )
      {
        v56 = (float)(flEdgeY * flAbsEdgeY.x) - (float)(flEdgeZ * flAbsEdgeY.y);
        v57 = (float)(flEdgeY * v79.x) - (float)(flEdgeZ * v79.y);
        v58 = (float)((float)(p1_8 * v81) + (float)(p2_8 * p3.x)) + flTolerance;
        if ( v57 <= v56 )
        {
          if ( v57 > v58 )
            return false;
          v59 = (float)-v58 <= v56;
        }
        else
        {
          if ( v56 > v58 )
            return false;
          v59 = (float)-v58 <= v57;
        }
        if ( v59 )
        {
          v60 = vecBoxCenter->y;
          v61 = vecBoxCenter->z;
          flAbsEdgeY.x = p3.z - p2_8;
          v62 = vecBoxExtents->y;
          v63 = v60 - v62;
          v64 = v62 + vecBoxCenter->y;
          flAbsEdgeY.y = v63;
          v65 = vecBoxExtents->z;
          v66 = v61 - v65;
          v67 = v65 + vecBoxCenter->z;
          flAbsEdgeY.z = v66;
          flEdgeZ = p2_8 + p3.z;
          flEdgeY = v64;
          flAbsEdgeZ = v67;
          return BoxOnPlaneSide(emins: &flAbsEdgeY.x, emaxs: &flEdgeZ, p: plane) == 3;
        }
      }
    }
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10156180
// Name: float IntersectRayWithTriangle(struct Ray_t const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
double __cdecl IntersectRayWithTriangle(const Ray_t *ray, const Vector *v1, float v2, const Vector *v3, int oneSided)
{
  float y; // xmm0_4
  float z; // xmm4_4
  float v7; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm5_4
  float v10; // xmm4_4
  float x; // xmm2_4
  float v12; // xmm6_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm5_4
  float v17; // xmm7_4
  float v18; // xmm4_4
  float v19; // xmm3_4
  float v20; // xmm6_4
  float v21; // xmm2_4
  float v22; // xmm6_4
  float dirCrossEdge2_4; // [esp+4h] [ebp-20h]
  float edge2; // [esp+Ch] [ebp-18h]
  float edge2_4; // [esp+10h] [ebp-14h]
  float edge2_8; // [esp+14h] [ebp-10h]
  float edge1; // [esp+18h] [ebp-Ch]
  float edge1_4; // [esp+1Ch] [ebp-8h]
  float edge1_8; // [esp+20h] [ebp-4h]

  y = v1->y;
  z = v1->z;
  v7 = v3->x - v1->x;
  v8 = v3->y - y;
  v9 = v3->z - z;
  edge1 = *(float *)LODWORD(v2) - v1->x;
  edge1_4 = *(float *)(LODWORD(v2) + 4) - y;
  edge1_8 = *(float *)(LODWORD(v2) + 8) - z;
  edge2 = v7;
  edge2_4 = v8;
  edge2_8 = v9;
  if ( (_BYTE)oneSided != 0
    && (float)((float)((float)(ray->m_Delta.y
                             * (float)((float)((float)(*(float *)(LODWORD(v2) + 8) - z) * v7)
                                     - (float)(v9 * (float)(*(float *)LODWORD(v2) - v1->x))))
                     + (float)((float)((float)(v9 * (float)(*(float *)(LODWORD(v2) + 4) - y))
                                     - (float)(v8 * (float)(*(float *)(LODWORD(v2) + 8) - z)))
                             * ray->m_Delta.x))
             + (float)(ray->m_Delta.z
                     * (float)((float)(v8 * (float)(*(float *)LODWORD(v2) - v1->x))
                             - (float)(v7 * (float)(*(float *)(LODWORD(v2) + 4) - y))))) >= 0.0 )
  {
    return -1.0;
  }
  v10 = (float)(ray->m_Delta.y * v9) - (float)(ray->m_Delta.z * v8);
  x = ray->m_Delta.x;
  dirCrossEdge2_4 = (float)(ray->m_Delta.z * v7) - (float)(x * v9);
  v12 = (float)(x * v8) - (float)(ray->m_Delta.y * v7);
  *(float *)&oneSided = (float)((float)(dirCrossEdge2_4 * edge1_4) + (float)(v10 * edge1)) + (float)(v12 * edge1_8);
  if ( fabs(*(float *)&oneSided) < 0.000001 )
    return -1.0;
  v13 = ray->m_Start.y - v1->y;
  v14 = ray->m_Start.x - v1->x;
  *(float *)&oneSided = 1.0
                      / (float)((float)((float)(dirCrossEdge2_4 * edge1_4) + (float)(v10 * edge1))
                              + (float)(v12 * edge1_8));
  v15 = ray->m_Start.z - v1->z;
  v16 = (float)((float)((float)(v13 * dirCrossEdge2_4) + (float)(v14 * v10)) + (float)(v15 * v12)) * *(float *)&oneSided;
  if ( v16 < 0.0 )
    return -1.0;
  if ( v16 > 1.0 )
    return -1.0;
  v17 = *(float *)&oneSided;
  v18 = (float)(v13 * edge1_8) - (float)(v15 * edge1_4);
  v19 = (float)(v14 * edge1_4) - (float)(v13 * edge1);
  v20 = (float)(v15 * edge1) - (float)(v14 * edge1_8);
  v21 = (float)((float)((float)(x * v18) + (float)(v20 * ray->m_Delta.y)) + (float)(v19 * ray->m_Delta.z))
      * *(float *)&oneSided;
  if ( v21 < 0.0 )
    return -1.0;
  if ( (float)(v21 + v16) > 1.0 )
    return -1.0;
  *(float *)&oneSided = ComputeBoxOffset(ray);
  v22 = (float)((float)((float)(v20 * edge2_4) + (float)(v18 * edge2)) + (float)(v19 * edge2_8)) * v17;
  v2 = v22;
  if ( COERCE_FLOAT(oneSided ^ _mask__NegFloat_) > v22 || v22 > (float)(*(float *)&oneSided + 1.0) )
    return -1.0;
  oneSided = 1;
  v1 = nullptr;
  return clamp<float,int,int>(val: &v2, minVal: (const int *)&v1, maxVal: &oneSided);
}

//------------------------------------------------------------------------------
// Address: 0x10156430
// Name: bool IsBoxIntersectingRay(union __m128 const __near &,union __m128 const __near &,struct Ray_t const __near &,union __m128 const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
bool __userpurge IsBoxIntersectingRay@<al>(
        const __m128 *boxMin@<ecx>,
        const __m128 *boxMax@<edx>,
        int a3@<ebp>,
        const Ray_t *ray,
        const __m128 *fl4Tolerance)
{
  bool v5; // zf
  VectorAligned m_Extents; // xmm0
  __m128 v7; // xmm1
  __m128 v8; // xmm0
  __m128 v9; // xmm3
  __m128 v10; // xmm0
  __m128 v11; // xmm2
  __m128 v13; // xmm1
  __m128 v14; // xmm0
  _BYTE v15[88]; // [esp-Ch] [ebp-5Ch] OVERLAPPED BYREF
  _UNKNOWN *retaddr; // [esp+50h] [ebp+0h]

  *(_DWORD *)&v15[80] = a3;
  *(_DWORD *)&v15[84] = retaddr;
  v5 = !ray->m_IsSwept;
  m_Extents = ray->m_Extents;
  v7 = _mm_and_ps((__m128)ray->m_Start, *(__m128 *)g_SIMD_clear_wmask);
  *(__m128 *)&v15[48] = v7;
  v8 = _mm_and_ps((__m128)m_Extents, *(__m128 *)g_SIMD_clear_wmask);
  if ( v5 )
  {
    v9 = _mm_add_ps(_mm_sub_ps(v7, v8), *fl4Tolerance);
    v10 = _mm_add_ps(_mm_add_ps(v8, v7), *fl4Tolerance);
    *(__m128 *)&v15[64] = *boxMin;
    v11 = *boxMax;
    *(__m128 *)&v15[48] = v10;
    *(__m128 *)&v15[16] = v11;
    *(__m128 *)&v15[32] = v9;
    return *(float *)&v15[64] <= v10.m128_f32[0]
        && *(float *)&v15[32] <= *(float *)&v15[16]
        && *(float *)&v15[68] <= *(float *)&v15[52]
        && *(float *)&v15[36] <= *(float *)&v15[20]
        && *(float *)&v15[72] <= *(float *)&v15[56]
        && *(float *)&v15[40] <= *(float *)&v15[24];
  }
  else
  {
    v13 = _mm_and_ps((__m128)ray->m_Delta, *(__m128 *)g_SIMD_clear_wmask);
    *(__m128 *)v15 = _mm_sub_ps(*boxMin, v8);
    *(__m128 *)&v15[64] = _mm_add_ps(*boxMax, v8);
    v14 = _mm_rcp_ps(v13);
    *(__m128 *)&v15[32] = v13;
    *(__m128 *)&v15[16] = _mm_sub_ps(_mm_add_ps(v14, v14), _mm_mul_ps(_mm_mul_ps(v14, v14), v13));
    return IsBoxIntersectingRay(
             inBoxMin: (const __m128 *)v15,
             inBoxMax: (const __m128 *)&v15[64],
             origin: (const __m128 *)&v15[48],
             delta: (const __m128 *)&v15[32],
             invDelta: (const __m128 *)&v15[16],
             vTolerance: fl4Tolerance);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10156550
// Name: bool IntersectRayWithOBB(class Vector const __near &,class Vector const __near &,struct matrix3x4_t const __near &,class Vector const __near &,class Vector const __near &,float,class CBaseTrace __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __cdecl IntersectRayWithOBB(
        const Vector *vecRayStart,
        const Vector *vecRayDelta,
        const matrix3x4_t *matOBBToWorld,
        const Vector *vecOBBMins,
        const Vector *vecOBBMaxs,
        float flTolerance,
        CBaseTrace *pTrace)
{
  Vector *p_endpos; // edi
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float x; // xmm4_4
  float y; // xmm5_4
  float z; // xmm6_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  double v22; // st7
  double v23; // st6
  float *v24; // eax
  int v25; // ecx
  float v26; // xmm2_4
  long double v27; // st4
  float v28; // xmm5_4
  float v29; // xmm3_4
  float v30; // xmm1_4
  double v31; // st7
  double v32; // st6
  double v33; // st5
  double v34; // st4
  double v35; // st7
  long double v36; // st4
  double v37; // st5
  int type; // eax
  float v40; // xmm0_4
  double v41; // st7
  float v42; // xmm0_4
  Vector out; // [esp+18h] [ebp-68h] BYREF
  float v44; // [esp+24h] [ebp-5Ch] BYREF
  Vector start; // [esp+28h] [ebp-58h] BYREF
  Vector vecTemp; // [esp+34h] [ebp-4Ch]
  Vector vecBoxCenter; // [esp+40h] [ebp-40h]
  Vector uextent; // [esp+4Ch] [ebp-34h]
  float v49; // [esp+58h] [ebp-28h]
  float v50; // [esp+5Ch] [ebp-24h]
  Vector v51; // [esp+60h] [ebp-20h] BYREF
  float v52; // [esp+6Ch] [ebp-14h] BYREF
  Vector extent; // [esp+70h] [ebp-10h]
  float vecBoxExtents; // [esp+7Ch] [ebp-4h] OVERLAPPED
  float in1; // [esp+88h] [ebp+8h]
  float *v56; // [esp+8Ch] [ebp+Ch]
  float matOBBToWorlda; // [esp+A0h] [ebp+20h]

  pTrace->startpos = *vecRayStart;
  p_endpos = &pTrace->endpos;
  pTrace->endpos = *vecRayStart;
  pTrace->endpos.x = vecRayDelta->x + pTrace->endpos.x;
  pTrace->endpos.y = vecRayDelta->y + pTrace->endpos.y;
  pTrace->endpos.z = pTrace->endpos.z + vecRayDelta->z;
  pTrace->fraction = 1.0;
  *(_WORD *)&pTrace->allsolid = 0;
  pTrace->contents = 0;
  v10 = (float)(vecOBBMins->y + vecOBBMaxs->y) * 0.5;
  v11 = (float)(vecOBBMins->z + vecOBBMaxs->z) * 0.5;
  v52 = (float)(vecOBBMins->x + vecOBBMaxs->x) * 0.5;
  extent.x = v10;
  extent.y = v11;
  VectorTransform(in1: &v52, in2: matOBBToWorld, out: &start.z);
  v13 = vecOBBMaxs->y - extent.x;
  v14 = vecOBBMaxs->z - extent.y;
  x = vecRayDelta->x;
  y = vecRayDelta->y;
  z = vecRayDelta->z;
  vecBoxCenter.z = vecOBBMaxs->x - v52;
  v52 = vecBoxCenter.z;
  v18 = vecRayStart->x;
  uextent.x = v13;
  extent.x = v13;
  v19 = vecRayStart->y;
  uextent.y = v14;
  extent.y = v14;
  v20 = (float)(v18 + x) - start.z;
  v21 = z + vecRayStart->z;
  uextent.z = v20;
  v50 = v21 - vecTemp.y;
  v22 = (float)(v21 - vecTemp.y);
  v49 = (float)(v19 + y) - vecTemp.x;
  v23 = v49;
  v24 = matOBBToWorld->m_flMatVal[2];
  memset(&v51, 0, sizeof(v51));
  v56 = matOBBToWorld->m_flMatVal[2];
  v25 = 0;
  while ( 1 )
  {
    v26 = *v24;
    matOBBToWorlda = *(v24 - 8);
    in1 = (float)((float)(x * matOBBToWorlda) + (float)(y * *(v24 - 4))) + (float)(z * *v24);
    vecBoxExtents = *(v24 - 4);
    v27 = fabs(in1);
    extent.z = v26;
    *(float *)((char *)&vecTemp.z + v25) = v27;
    *(float *)((char *)&v51.x + v25) = in1;
    if ( fabs(matOBBToWorlda * v20 + vecBoxExtents * v23 + extent.z * v22) > v27 + *(float *)((char *)&v52 + v25) )
      return 0;
    ++v56;
    v25 += 4;
    if ( v25 >= 12 )
      break;
    v24 = v56;
  }
  v28 = vecRayDelta->y;
  v29 = vecRayDelta->z;
  v30 = v49;
  v31 = matOBBToWorld->m_flMatVal[1][0];
  uextent.z = (float)(v28 * v50) - (float)(v29 * v49);
  v49 = (float)(v29 * v20) - (float)(x * v50);
  v32 = v49;
  v33 = matOBBToWorld->m_flMatVal[0][0];
  v50 = (float)(x * v30) - (float)(v28 * v20);
  v34 = v31 * v49;
  v35 = uextent.z;
  v36 = v33 * uextent.z + v34 + v50 * matOBBToWorld->m_flMatVal[2][0];
  v37 = v50;
  if ( fabs(v36) > vecBoxCenter.x * uextent.y + uextent.x * vecBoxCenter.y )
    return 0;
  if ( fabs(
         matOBBToWorld->m_flMatVal[1][1] * v32
       + matOBBToWorld->m_flMatVal[0][1] * v35
       + matOBBToWorld->m_flMatVal[2][1] * v37) > vecBoxCenter.y * vecBoxCenter.z + uextent.y * vecTemp.z )
    return 0;
  if ( fabs(
         v37 * matOBBToWorld->m_flMatVal[2][2]
       + v35 * matOBBToWorld->m_flMatVal[0][2]
       + v32 * matOBBToWorld->m_flMatVal[1][2]) > vecBoxCenter.z * vecBoxCenter.x + vecTemp.z * uextent.x )
    return 0;
  VectorITransform(in1: &vecRayStart->x, in2: matOBBToWorld, out: &out.x);
  v51.x = v51.x * 2.0;
  v51.y = v51.y * 2.0;
  v51.z = v51.z * 2.0;
  if ( IntersectRayWithBox(
         vecRayStart: &out,
         vecRayDelta: &v51,
         boxMins: vecOBBMins,
         boxMaxs: vecOBBMaxs,
         flTolerance,
         pTrace,
         pFractionLeftSolid: nullptr) == 0 )
    return 0;
  VectorTransform(in1: &pTrace->endpos.x, in2: matOBBToWorld, out: &v44);
  p_endpos->x = v44;
  pTrace->endpos.y = start.x;
  pTrace->endpos.z = start.y;
  type = pTrace->plane.type;
  pTrace->startpos.x = vecRayStart->x;
  v40 = pTrace->fraction * 2.0;
  pTrace->startpos.y = vecRayStart->y;
  v41 = vecRayStart->z;
  pTrace->fraction = v40;
  pTrace->startpos.z = v41;
  v42 = *(&pTrace->plane.normal.x + type);
  pTrace->plane.normal.x = matOBBToWorld->m_flMatVal[0][type] * v42;
  pTrace->plane.normal.y = matOBBToWorld->m_flMatVal[1][pTrace->plane.type] * v42;
  pTrace->plane.normal.z = matOBBToWorld->m_flMatVal[2][pTrace->plane.type] * v42;
  pTrace->plane.dist = (float)((float)(pTrace->plane.normal.y * pTrace->endpos.y)
                             + (float)(pTrace->plane.normal.x * pTrace->endpos.x))
                     + (float)(pTrace->plane.normal.z * pTrace->endpos.z);
  pTrace->plane.type = 3;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101569B0
// Name: bool IntersectRayWithOBB(class Vector const __near &,class Vector const __near &,class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,float,class CBaseTrace __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IntersectRayWithOBB(
        const Vector *vecRayOrigin,
        const Vector *vecRayDelta,
        const Vector *vecBoxOrigin,
        const Vector *angBoxRotation,
        const Vector *vecOBBMins,
        const Vector *vecOBBMaxs,
        float flTolerance,
        CBaseTrace *pTrace)
{
  float x; // xmm0_4
  float y; // xmm2_4
  float z; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  matrix3x4_t matrix; // [esp+Ch] [ebp-48h] BYREF
  Vector v17; // [esp+3Ch] [ebp-18h] BYREF
  Vector vecAbsMins; // [esp+48h] [ebp-Ch] BYREF

  if ( vec3_angle.x == angBoxRotation->x && vec3_angle.y == angBoxRotation->y && vec3_angle.z == angBoxRotation->z )
  {
    x = vecBoxOrigin->x;
    y = vecOBBMins->y;
    z = vecOBBMins->z;
    v17.x = vecOBBMins->x + vecBoxOrigin->x;
    v11 = vecBoxOrigin->y;
    v17.y = y + v11;
    v12 = vecBoxOrigin->z;
    v17.z = z + v12;
    v13 = vecOBBMaxs->x + x;
    vecAbsMins.y = vecOBBMaxs->y + v11;
    v14 = vecOBBMaxs->z + v12;
    vecAbsMins.x = v13;
    vecAbsMins.z = v14;
    return IntersectRayWithBox(
             vecRayStart: vecRayOrigin,
             vecRayDelta,
             boxMins: &v17,
             boxMaxs: &vecAbsMins,
             flTolerance,
             pTrace,
             pFractionLeftSolid: nullptr);
  }
  else
  {
    AngleMatrix(angles: (const QAngle *)angBoxRotation, position: vecBoxOrigin, &matrix);
    return IntersectRayWithOBB(
             vecRayStart: vecRayOrigin,
             vecRayDelta,
             matOBBToWorld: &matrix,
             vecOBBMins,
             vecOBBMaxs,
             flTolerance,
             pTrace);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10156AD0
// Name: bool IntersectRayWithOBB(struct Ray_t const __near &,struct matrix3x4_t const __near &,class Vector const __near &,class Vector const __near &,float,class CBaseTrace __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __usercall IntersectRayWithOBB@<al>(
        int a1@<ebp>,
        const Ray_t *ray,
        const matrix3x4_t *matOBBToWorld,
        const Vector *vecOBBMins,
        const Vector *vecOBBMaxs,
        float flTolerance,
        CBaseTrace *pTrace)
{
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float y; // xmm5_4
  float z; // xmm6_4
  float v13; // xmm7_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm5_4
  float v18; // xmm2_4
  float v19; // xmm6_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm7_4
  float v23; // xmm0_4
  __int128 v24; // xmm1
  float x; // xmm4_4
  __int128 v26; // xmm1
  float v27; // xmm5_4
  float v28; // xmm4_4
  float v29; // xmm6_4
  float v30; // xmm3_4
  float v31; // xmm0_4
  float v32; // xmm2_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm2_4
  float v36; // ecx
  float v37; // xmm0_4
  float v38; // xmm0_4
  float *v39; // eax
  float *p_y; // esi
  int v41; // edi
  long double v42; // st7
  float v43; // edx
  double v44; // st6
  long double v45; // st7
  long double v46; // st6
  float *v47; // eax
  long double v48; // st7
  const float *v49; // edx
  long double v50; // st6
  float v51; // xmm0_4
  float v52; // xmm0_4
  int v53; // ecx
  int v54; // edx
  float v55; // xmm3_4
  float v56; // xmm1_4
  float v57; // xmm0_4
  int v58; // ecx
  int v59; // eax
  float *v60; // eax
  float v61; // xmm1_4
  int v62; // ecx
  float v63; // xmm0_4
  float *v64; // edx
  float v65; // xmm0_4
  float v66; // xmm4_4
  long double v67; // st7
  double v68; // st6
  int v69; // ecx
  float v70; // xmm5_4
  long double v71; // st5
  double v72; // st4
  float v73; // xmm3_4
  double v74; // rt0
  long double v75; // st5
  float v76; // xmm0_4
  double v77; // st4
  float v78; // xmm0_4
  float v79; // xmm6_4
  int v80; // ecx
  float v81; // xmm7_4
  float v82; // xmm0_4
  float *v83; // edx
  float v84; // xmm0_4
  int v85; // ecx
  long double v86; // st5
  float v87; // xmm1_4
  long double v88; // st4
  long double v89; // st5
  int v90; // ecx
  float *v91; // eax
  float v92; // xmm0_4
  int v93; // ecx
  float v94; // xmm0_4
  long double v95; // st5
  long double v96; // st7
  long double v97; // st7
  float v98; // xmm6_4
  float v99; // xmm0_4
  int v100; // edi
  float v101; // eax
  int v102; // esi
  float v103; // xmm0_4
  float v104; // xmm1_4
  float v105; // xmm3_4
  float v106; // xmm4_4
  float v107; // xmm3_4
  float v108; // edx
  float v109; // xmm0_4
  float v110; // xmm3_4
  float v111; // xmm1_4
  float v112; // xmm0_4
  float v113; // xmm0_4
  float v114; // xmm0_4
  float v115; // xmm0_4
  VectorAligned *v116; // edx
  float v117; // eax
  float v118; // xmm1_4
  float v119; // xmm0_4
  float v120; // xmm2_4
  float v121; // xmm1_4
  float v122; // xmm3_4
  bool v123; // al
  double v124; // st7
  _DWORD v125[2]; // [esp+18h] [ebp-1ECh] BYREF
  _DWORD v126[10]; // [esp+20h] [ebp-1E4h] BYREF
  Vector pPlaneNormal[15]; // [esp+48h] [ebp-1BCh] BYREF
  float ppPlaneDist[15][2]; // [esp+100h] [ebp-104h] BYREF
  float v129; // [esp+178h] [ebp-8Ch]
  Vector vecLocalRayDirection; // [esp+17Ch] [ebp-88h] BYREF
  float v131; // [esp+188h] [ebp-7Ch]
  float v132; // [esp+18Ch] [ebp-78h]
  float v133; // [esp+190h] [ebp-74h]
  char v134; // [esp+194h] [ebp-70h]
  __int128 flRayExtent1; // [esp+198h] [ebp-6Ch] OVERLAPPED BYREF
  float v136; // [esp+1B0h] [ebp-54h]
  cplane_t temp; // [esp+1B4h] [ebp-50h] BYREF
  VectorAligned *p_m_Delta; // [esp+1C8h] [ebp-3Ch]
  Vector vecLocalRayEnd; // [esp+1CCh] [ebp-38h]
  float *v140; // [esp+1D8h] [ebp-2Ch]
  float v141; // [esp+1DCh] [ebp-28h] BYREF
  float d1[2]; // [esp+1E0h] [ebp-24h]
  float v143; // [esp+1E8h] [ebp-1Ch]
  const float *pMatRow0; // [esp+1ECh] [ebp-18h]
  float v145; // [esp+1F0h] [ebp-14h]
  float v146; // [esp+1F4h] [ebp-10h]
  int v147; // [esp+1F8h] [ebp-Ch]
  const float *pMatRow1; // [esp+1FCh] [ebp-8h]
  const float *vars0; // [esp+204h] [ebp+0h]

  v147 = a1;
  pMatRow1 = vars0;
  if ( ray->m_IsRay )
    return IntersectRayWithOBB(
             vecRayStart: &ray->m_Start,
             vecRayDelta: &ray->m_Delta,
             matOBBToWorld,
             vecOBBMins,
             vecOBBMaxs,
             flTolerance,
             pTrace);
  v8 = ray->m_StartOffset.y + ray->m_Start.y;
  v9 = ray->m_Start.x + ray->m_StartOffset.x;
  v10 = ray->m_StartOffset.z + ray->m_Start.z;
  pTrace->startpos.y = v8;
  pTrace->startpos.x = v9;
  pTrace->startpos.z = v10;
  pTrace->endpos.y = v8;
  pTrace->endpos.x = v9;
  pTrace->endpos.z = v10;
  pTrace->endpos.x = v9 + ray->m_Delta.x;
  pTrace->endpos.y = ray->m_Delta.y + pTrace->endpos.y;
  pTrace->endpos.z = ray->m_Delta.z + pTrace->endpos.z;
  pTrace->fraction = 1.0;
  *(_WORD *)&pTrace->allsolid = 0;
  pTrace->contents = 0;
  y = vecOBBMaxs->y;
  z = vecOBBMaxs->z;
  v13 = matOBBToWorld->m_flMatVal[0][3];
  v14 = (float)(vecOBBMaxs->x - vecOBBMins->x) * 0.5;
  v15 = (float)(vecOBBMaxs->x + vecOBBMins->x) * 0.5;
  v16 = y + vecOBBMins->y;
  v17 = y - vecOBBMins->y;
  v18 = z + vecOBBMins->z;
  v19 = z - vecOBBMins->z;
  d1[1] = v18 * 0.5;
  v20 = matOBBToWorld->m_flMatVal[2][3] + (float)(v18 * 0.5);
  v21 = ray->m_Extents.y;
  v22 = v13 + v15;
  v23 = matOBBToWorld->m_flMatVal[1][3] + (float)(v16 * 0.5);
  v24 = 0;
  d1[0] = v23;
  d1[1] = v20;
  *(float *)&v24 = (float)((float)(v14 * v14) + (float)((float)(v17 * 0.5) * (float)(v17 * 0.5)))
                 + (float)((float)(v19 * 0.5) * (float)(v19 * 0.5));
  x = ray->m_Extents.x;
  *(float *)&v24 = fsqrt(*(float *)&v24);
  *(_OWORD *)&ppPlaneDist[9][0] = v24;
  v26 = 0;
  *(float *)&v26 = fsqrt((float)((float)(x * x) + (float)(v21 * v21)) + (float)(ray->m_Extents.z * ray->m_Extents.z));
  flRayExtent1 = v26;
  p_m_Delta = &ray->m_Delta;
  v27 = ray->m_Start.x;
  v28 = ray->m_Delta.x;
  v29 = ray->m_Delta.y;
  v30 = (float)(*(float *)&v26 + ppPlaneDist[9][0]) + flTolerance;
  v31 = (float)((float)((float)(v23 - ray->m_Start.y) * v29) + (float)((float)(v22 - ray->m_Start.x) * v28))
      + (float)((float)(v20 - ray->m_Start.z) * ray->m_Delta.z);
  v32 = 0.0;
  if ( v31 > 0.0 )
  {
    v143 = (float)(v29 * v29) + (float)(v28 * v28);
    v146 = ray->m_Delta.z * ray->m_Delta.z;
    if ( v31 <= (float)(v143 + v146) )
      v32 = v31 / (float)(v143 + v146);
    else
      v32 = 1.0;
  }
  v33 = (float)((float)(v32 * v29) + ray->m_Start.y) - d1[0];
  v34 = v32 * v28;
  v35 = (float)((float)(v32 * ray->m_Delta.z) + ray->m_Start.z) - d1[1];
  if ( (float)(v30 * v30) >= (float)((float)((float)(v33 * v33)
                                           + (float)((float)((float)(v34 + v27) - v22)
                                                   * (float)((float)(v34 + v27) - v22)))
                                   + (float)(v35 * v35)) )
  {
    VectorITransform(in1: &ray->m_Start.x, in2: matOBBToWorld, out: &v141);
    VectorIRotate(in1: &p_m_Delta->x, in2: matOBBToWorld, out: &ppPlaneDist[9][1]);
    v36 = *(float *)&vecOBBMaxs;
    ppPlaneDist[12][1] = ray->m_Extents.y;
    ppPlaneDist[11][0] = ray->m_Extents.x;
    vecLocalRayDirection.x = ray->m_Extents.z;
    v129 = vecOBBMaxs->z;
    ppPlaneDist[13][1] = vecOBBMins->z;
    temp.normal.x = vecOBBMaxs->x;
    *(float *)&temp.type = vecOBBMins->x;
    v37 = vecOBBMaxs->y;
    v145 = COERCE_FLOAT(v125);
    LODWORD(vecLocalRayEnd.y) = &ray->m_Extents;
    v146 = v37;
    v38 = vecOBBMins->y;
    v39 = matOBBToWorld->m_flMatVal[2];
    LODWORD(ppPlaneDist[14][1]) = (char *)vecOBBMins - (char *)vecOBBMaxs;
    v143 = v38;
    LODWORD(vecLocalRayEnd.z) = vecOBBMaxs;
    pMatRow0 = &matOBBToWorld->m_flMatVal[0][1];
    p_y = &pPlaneNormal[2].y;
    v140 = matOBBToWorld->m_flMatVal[2];
    v41 = 0;
    while ( 1 )
    {
      v42 = *(v39 - 8) * ppPlaneDist[11][0];
      v43 = v145;
      *(p_y - 19) = 0.0;
      *(p_y - 18) = 0.0;
      *(p_y - 17) = 0.0;
      v44 = *(v39 - 4);
      *(_DWORD *)LODWORD(v43) = 1065353216;
      v45 = fabs(v42) + fabs(v44 * ppPlaneDist[12][1]);
      v46 = vecLocalRayDirection.x * *v39;
      v47 = (float *)((char *)&pPlaneNormal[13].y + v41 * 8);
      v48 = v45 + fabs(v46);
      v49 = pMatRow0;
      v50 = *(float *)(LODWORD(ppPlaneDist[14][1]) + LODWORD(v36)) - v48;
      ppPlaneDist[12][0] = *(pMatRow0 - 1);
      *(p_y - 10) = ppPlaneDist[12][0];
      v51 = *v49;
      *(v47 - 6) = v50;
      ppPlaneDist[11][1] = v51;
      *(p_y - 9) = v51;
      v52 = v49[1];
      *(v47 - 5) = v48 + *(float *)LODWORD(v36);
      vecLocalRayDirection.y = v52;
      *(p_y - 8) = v52;
      ComputeSupportMap(
        vecDirection: (const Vector *)(p_y - 10),
        vecBoxMins: vecOBBMins,
        vecBoxMaxs: vecOBBMaxs,
        pDist: (float *)((char *)&pPlaneNormal[13].y + v41 * 8));
      v53 = s_ExtIndices[v41][0];
      v54 = s_ExtIndices[v41][1];
      v55 = vecLocalRayDirection.y;
      v56 = *(float *)((char *)&pPlaneNormal[13].y + v41 * 8) - *(float *)LODWORD(vecLocalRayEnd.y);
      *(float *)((char *)&pPlaneNormal[13].z + v41 * 8) = *(float *)LODWORD(vecLocalRayEnd.y)
                                                        + *(float *)((char *)&pPlaneNormal[13].z + v41 * 8);
      v57 = *(&ray->m_Extents.x + v53);
      v58 = s_MatIndices[v41][1];
      ppPlaneDist[14][0] = v57;
      v59 = s_MatIndices[v41][0];
      ppPlaneDist[13][0] = *(&ray->m_Extents.x + v54);
      v60 = matOBBToWorld->m_flMatVal[v59];
      *(float *)((char *)&pPlaneNormal[13].y + v41 * 8) = v56;
      v61 = ppPlaneDist[11][1];
      LODWORD(temp.dist) = v60;
      LODWORD(vecLocalRayEnd.x) = matOBBToWorld->m_flMatVal[v58];
      *(p_y - 1) = 0.0;
      *p_y = -v55;
      p_y[1] = v61;
      v62 = 4 * ((float)-v55 > 0.0);
      v63 = (float)-v55 * v143;
      v64 = ppPlaneDist[v41];
      v64[v62 / 4u] = (float)-v55 * v146;
      v64[v62 / 0xFFFFFFFC + 1] = v63;
      v65 = p_y[1];
      v66 = v129;
      v67 = fabs(*v60);
      v68 = ppPlaneDist[14][0];
      v69 = 4 * (v65 > 0.0);
      v64[v69 / 4u] = (float)(v65 * v129) + v64[v69 / 4u];
      v70 = ppPlaneDist[13][1];
      v71 = fabs(*(float *)LODWORD(vecLocalRayEnd.x));
      v72 = ppPlaneDist[13][0];
      v64[v69 / 0xFFFFFFFC + 1] = (float)(v65 * ppPlaneDist[13][1]) + v64[v69 / 0xFFFFFFFC + 1];
      p_y[8] = v55;
      v73 = ppPlaneDist[12][0];
      v74 = v72;
      v75 = v71 * v72 + v67 * v68;
      v76 = -ppPlaneDist[12][0];
      v77 = ppPlaneDist[v41][0];
      p_y[9] = 0.0;
      p_y[10] = v76;
      v78 = p_y[8];
      *v64 = v77 - v75;
      ppPlaneDist[v41][1] = v75 + ppPlaneDist[v41][1];
      v79 = temp.normal.x;
      v80 = 4 * (v78 > 0.0);
      v81 = v78;
      v82 = v78 * *(float *)&temp.type;
      v83 = ppPlaneDist[v41 + 3];
      v83[v80 / 4u] = v81 * temp.normal.x;
      v83[v80 / 0xFFFFFFFC + 1] = v82;
      v84 = p_y[10];
      v85 = 4 * (v84 > 0.0);
      v86 = fabs(v60[1]);
      v83[v85 / 4u] = (float)(v84 * v66) + v83[v85 / 4u];
      v83[v85 / 0xFFFFFFFC + 1] = (float)(v84 * v70) + v83[v85 / 0xFFFFFFFC + 1];
      v87 = -v61;
      v88 = fabs(*(float *)(LODWORD(vecLocalRayEnd.x) + 4));
      p_y[17] = v87;
      p_y[18] = v73;
      v89 = v86 * v68 + v88 * v74;
      p_y[19] = 0.0;
      *v83 = *v83 - v89;
      ppPlaneDist[v41 + 3][1] = v89 + ppPlaneDist[v41 + 3][1];
      v90 = 4 * (v87 > 0.0);
      v91 = ppPlaneDist[v41 + 6];
      v92 = v87 * *(float *)&temp.type;
      v91[v90 / 4u] = v87 * v79;
      v91[v90 / 0xFFFFFFFC + 1] = v92;
      v93 = 4 * (v73 > 0.0);
      v94 = v73 * v143;
      v91[v93 / 4u] = (float)(v73 * v146) + v91[v93 / 4u];
      v95 = *(float *)(LODWORD(temp.dist) + 8);
      v91[v93 / 0xFFFFFFFC + 1] = v94 + v91[v93 / 0xFFFFFFFC + 1];
      ++v41;
      p_y += 3;
      v96 = v74 * fabs(*(float *)(LODWORD(vecLocalRayEnd.x) + 8)) + v68 * fabs(v95);
      *v91 = *v91 - v96;
      ++v140;
      v97 = v96 + ppPlaneDist[v41 + 5][1];
      LODWORD(vecLocalRayEnd.z) += 4;
      LODWORD(vecLocalRayEnd.y) += 4;
      LODWORD(v145) += 16;
      ppPlaneDist[v41 + 5][1] = v97;
      pMatRow0 += 4;
      if ( v41 >= 3 )
        break;
      v39 = v140;
      v36 = vecLocalRayEnd.z;
    }
    v98 = ppPlaneDist[9][1] + v141;
    v145 = -1.0;
    *(float *)&pMatRow0 = 1.0;
    *((float *)&flRayExtent1 + 2) = ppPlaneDist[10][0] + d1[0];
    v99 = ppPlaneDist[10][1] + d1[1];
    v100 = -1;
    v101 = COERCE_FLOAT(v126);
    v146 = NAN;
    pTrace->startsolid = true;
    *((float *)&flRayExtent1 + 3) = v99;
    v102 = 0;
    v143 = COERCE_FLOAT(v126);
LABEL_12:
    v103 = (float)((float)(d1[0] * *(float *)(LODWORD(v101) - 4)) + (float)(v141 * *(float *)(LODWORD(v101) - 8)))
         + (float)(d1[1] * *(float *)LODWORD(v101));
    v104 = (float)((float)(*((float *)&flRayExtent1 + 2) * *(float *)(LODWORD(v101) - 4))
                 + (float)(v98 * *(float *)(LODWORD(v101) - 8)))
         + (float)(*((float *)&flRayExtent1 + 3) * *(float *)LODWORD(v101));
    v105 = *(&pPlaneNormal[11].y + 2 * v102);
    v136 = -(float)(v103 - v105);
    v106 = v104 - v105;
    v107 = *(&pPlaneNormal[11].z + 2 * v102);
    temp.normal.z = -v106;
    temp.normal.x = v103 - v107;
    temp.dist = v104 - v107;
    v108 = 0.0;
    while ( 1 )
    {
      v109 = *(&v136 + LODWORD(v108));
      if ( v109 > 0.0 && *(&temp.normal.z + LODWORD(v108)) > 0.0 )
        break;
      if ( v109 > 0.0 || *(&temp.normal.z + LODWORD(v108)) > 0.0 )
      {
        if ( v109 > 0.0 )
          pTrace->startsolid = false;
        v110 = *(&temp.normal.z + LODWORD(v108));
        v111 = 1.0 / (float)(v109 - v110);
        if ( v109 <= v110 )
        {
          v114 = (float)(v109 + flTolerance) * v111;
          if ( *(float *)&pMatRow0 > v114 )
            *(float *)&pMatRow0 = v114;
        }
        else
        {
          v112 = v109 - flTolerance;
          if ( v112 < 0.0 )
            v112 = 0.0;
          v113 = v112 * v111;
          if ( v113 > v145 )
          {
            v101 = v143;
            v145 = v113;
            v100 = v102;
            v146 = v108;
          }
        }
      }
      ++LODWORD(v108);
      if ( SLODWORD(v108) >= 2 )
      {
        ++v102;
        LODWORD(v101) += 12;
        v143 = v101;
        if ( v102 < 15 )
          goto LABEL_12;
        v115 = v145;
        if ( *(float *)&pMatRow0 <= v145 || v145 < 0.0 )
        {
          if ( !pTrace->startsolid )
            return 0;
          v123 = *(float *)&pMatRow0 <= 0.0 || *(float *)&pMatRow0 >= 1.0;
          v124 = pTrace->startpos.x;
          pTrace->allsolid = v123;
          pTrace->fraction = 0.0;
          pTrace->endpos.x = v124;
          pTrace->endpos.y = pTrace->startpos.y;
          pTrace->endpos.z = pTrace->startpos.z;
          pTrace->contents = 1;
          pTrace->plane.dist = pTrace->startpos.x;
          pTrace->plane.normal.x = 1.0;
          pTrace->plane.normal.y = 0.0;
          pTrace->plane.normal.z = 0.0;
          pTrace->plane.type = 0;
          return 1;
        }
        else
        {
          v116 = p_m_Delta;
          v117 = v146;
          pTrace->fraction = v145;
          pTrace->endpos.x = (float)(v115 * v116->x) + pTrace->startpos.x;
          pTrace->endpos.y = (float)(v116->y * v115) + pTrace->startpos.y;
          v118 = (float)(v116->z * v115) + pTrace->startpos.z;
          v119 = *(float *)&v125[3 * v100];
          v120 = *(float *)&v126[3 * v100];
          pTrace->endpos.z = v118;
          v121 = *(float *)&v125[3 * v100 + 1];
          v122 = *(&pPlaneNormal[11].y + 2 * v100 + LODWORD(v117));
          pTrace->contents = 1;
          vecLocalRayDirection.z = v119;
          v131 = v121;
          v132 = v120;
          v133 = v122;
          if ( v117 == 0.0 )
          {
            vecLocalRayDirection.z = v119 * -1.0;
            v131 = v121 * -1.0;
            v132 = v120 * -1.0;
            v133 = v122 * -1.0;
          }
          v134 = 3;
          MatrixGetColumn(in: matOBBToWorld, column: 3, out: (Vector *)&temp.normal.y);
          VectorIRotate(in1: &temp.normal.y, in2: matOBBToWorld, out: (float *)&flRayExtent1 + 1);
          VectorIRotate(in1: &vecLocalRayDirection.z, in2: matOBBToWorld, out: &pTrace->plane.normal.x);
          pTrace->plane.dist = (float)((float)((float)((float)(pTrace->plane.normal.x * pTrace->plane.normal.x)
                                                     + (float)(pTrace->plane.normal.y * pTrace->plane.normal.y))
                                             + (float)(pTrace->plane.normal.z * pTrace->plane.normal.z))
                                     * v133)
                             - (float)((float)((float)(*((float *)&flRayExtent1 + 1) * pTrace->plane.normal.x)
                                             + (float)(*((float *)&flRayExtent1 + 2) * pTrace->plane.normal.y))
                                     + (float)(*((float *)&flRayExtent1 + 3) * pTrace->plane.normal.z));
          return 1;
        }
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10157560
// Name: bool IntersectRayWithOBB(struct Ray_t const __near &,class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,float,class CBaseTrace __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IntersectRayWithOBB(
        const Ray_t *ray,
        const Vector *vecBoxOrigin,
        const Vector *angBoxRotation,
        const Ray_t *vecOBBMins,
        const Vector *vecOBBMaxs,
        float flTolerance,
        CBaseTrace *pTrace)
{
  float x; // xmm0_4
  float y; // xmm2_4
  float z; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  matrix3x4_t matrix; // [esp+Ch] [ebp-48h] BYREF
  Vector v16; // [esp+3Ch] [ebp-18h] BYREF
  Vector vecWorldMins; // [esp+48h] [ebp-Ch] BYREF
  Vector vecWorldMaxs; // [esp+54h] [ebp+0h] BYREF

  if ( vec3_angle.x == angBoxRotation->x && vec3_angle.y == angBoxRotation->y && vec3_angle.z == angBoxRotation->z )
  {
    x = vecBoxOrigin->x;
    y = vecOBBMins->m_Start.y;
    z = vecOBBMins->m_Start.z;
    v16.x = vecOBBMins->m_Start.x + vecBoxOrigin->x;
    v10 = vecBoxOrigin->y;
    v16.y = y + v10;
    v11 = vecBoxOrigin->z;
    v16.z = z + v11;
    v12 = vecOBBMaxs->x + x;
    vecWorldMins.y = vecOBBMaxs->y + v10;
    v13 = vecOBBMaxs->z + v11;
    vecWorldMins.x = v12;
    vecWorldMins.z = v13;
    return IntersectRayWithBox(
             ray,
             boxMins: &v16,
             boxMaxs: &vecWorldMins,
             flTolerance,
             pTrace,
             pFractionLeftSolid: nullptr);
  }
  else if ( ray->m_IsRay )
  {
    return IntersectRayWithOBB(
             vecRayOrigin: &ray->m_Start,
             vecRayDelta: &ray->m_Delta,
             vecBoxOrigin,
             angBoxRotation,
             vecOBBMins: &vecOBBMins->m_Start,
             vecOBBMaxs,
             flTolerance,
             pTrace);
  }
  else
  {
    AngleMatrix(angles: (const QAngle *)angBoxRotation, position: vecBoxOrigin, &matrix);
    return IntersectRayWithOBB(
             a1: (int)&vecWorldMaxs,
             ray,
             matOBBToWorld: &matrix,
             vecOBBMins: &vecOBBMins->m_Start,
             vecOBBMaxs,
             flTolerance,
             pTrace);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101576B0
// Name: enum QuadBarycentricRetval_t QuadWithParallelEdges(class Vector const __near &,class Vector const __near &,float,class Vector const __near &,float,class Vector const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall QuadWithParallelEdges@<eax>(
        float a1@<ebp>,
        const Vector *vecOrigin,
        const Vector *vecU,
        float lengthU,
        const Vector *vecV,
        float lengthV,
        const Vector *pt,
        Vector2D *vecUV)
{
  float z; // xmm0_4
  float x; // xmm1_4
  float y; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  Vector v19; // [esp-Ch] [ebp-BCh] BYREF
  Ray_t rayAxis; // [esp+0h] [ebp-B0h] BYREF
  Ray_t rayPt; // [esp+50h] [ebp-60h] BYREF
  float v22[2]; // [esp+A0h] [ebp-10h] BYREF
  float s; // [esp+A8h] [ebp-8h]
  float retaddr; // [esp+B0h] [ebp+0h]

  v22[1] = a1;
  s = retaddr;
  rayAxis.m_Extents.y = 0.0;
  rayPt.m_Extents.y = 0.0;
  v19 = *vecOrigin;
  *(Vector *)&rayAxis.m_Start.y = *vecU;
  *(float *)&rayAxis.m_IsRay = pt->x;
  *(float *)(&rayAxis.m_IsSwept + 3) = pt->y;
  z = pt->z;
  x = vecV->x;
  y = vecV->y;
  v11 = vecV->z;
  LOBYTE(rayAxis.m_Extents.z) = 1;
  LOBYTE(rayPt.m_Extents.z) = 1;
  *(float *)(&rayAxis.m_IsSwept + 7) = z;
  LODWORD(v12) = COERCE_UNSIGNED_INT(lengthV * 10.0) ^ _mask__NegFloat_;
  rayPt.m_Start.y = x * v12;
  rayPt.m_Start.z = y * v12;
  rayPt.m_Start.w = v11 * v12;
  IntersectRayWithRay(
    ray0: (const Ray_t *)&v19,
    ray1: (const Ray_t *)&rayAxis.m_IsRay,
    t: v22,
    s: (float *)(&rayPt.m_IsSwept + 7));
  vecUV->x = v22[0] / lengthU;
  LODWORD(v13) = COERCE_UNSIGNED_INT(lengthU * 10.0) ^ _mask__NegFloat_;
  v14 = vecU->y;
  v15 = vecU->z;
  *(Vector *)&rayAxis.m_Start.y = *vecV;
  rayPt.m_Start.y = vecU->x * v13;
  rayPt.m_Start.z = v14 * v13;
  rayPt.m_Start.w = v15 * v13;
  IntersectRayWithRay(
    ray0: (const Ray_t *)&v19,
    ray1: (const Ray_t *)&rayAxis.m_IsRay,
    t: v22,
    s: (float *)(&rayPt.m_IsSwept + 7));
  v16 = vecUV->x;
  v17 = v22[0] / lengthV;
  vecUV->y = v22[0] / lengthV;
  return v16 >= 0.0 && v16 <= 1.0 && v17 >= 0.0 && v17 <= 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10157890
// Name: enum QuadBarycentricRetval_t PointInQuadToBarycentric(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
QuadBarycentricRetval_t __cdecl PointInQuadToBarycentric(
        const Vector *v1,
        const Vector *v2,
        const Vector *v3,
        const Vector *v4,
        __int64 point)
{
  float z; // xmm2_4
  float v6; // xmm7_4
  float y; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm6_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float x; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm7_4
  float v17; // xmm6_4
  float v18; // xmm5_4
  float v19; // xmm4_4
  QuadBarycentricRetval_t result; // eax
  char v21; // bl
  float v22; // xmm0_4
  float v23; // xmm6_4
  float v24; // xmm0_4
  float v25; // xmm6_4
  float v26; // xmm0_4
  long double v27; // st6
  long double v28; // st7
  int v29; // ecx
  int v30; // eax
  int v31; // edx
  float v32; // xmm0_4
  int v33; // eax
  float v34; // xmm7_4
  double v35; // st7
  double v36; // st6
  double v37; // st4
  double v38; // st7
  long double v39; // st6
  long double v40; // st5
  long double v41; // st7
  float v42; // xmm0_4
  float v43; // xmm0_4
  Vector v44; // [esp-20h] [ebp-C8h]
  float tPlus_4; // [esp+4h] [ebp-A4h]
  float tMinus; // [esp+8h] [ebp-A0h]
  Vector tMinus_4; // [esp+Ch] [ebp-9Ch] BYREF
  Vector vec; // [esp+18h] [ebp-90h] BYREF
  float v49; // [esp+24h] [ebp-84h]
  float v50; // [esp+28h] [ebp-80h]
  Vector vecV; // [esp+2Ch] [ebp-7Ch] BYREF
  Vector v52; // [esp+38h] [ebp-70h] BYREF
  float v53; // [esp+44h] [ebp-64h]
  long double v54; // [esp+48h] [ebp-60h] BYREF
  Vector v55; // [esp+50h] [ebp-58h] BYREF
  float v56; // [esp+5Ch] [ebp-4Ch]
  Vector v57; // [esp+60h] [ebp-48h] BYREF
  Vector v58; // [esp+6Ch] [ebp-3Ch] OVERLAPPED
  Vector axisUNorm[2]; // [esp+78h] [ebp-30h] BYREF
  _BYTE lengthU[25]; // [esp+90h] [ebp-18h] OVERLAPPED BYREF
  float vecOrigin; // [esp+B0h] [ebp+8h]
  float ta; // [esp+B4h] [ebp+Ch]
  float t; // [esp+B4h] [ebp+Ch]
  float t_4; // [esp+B8h] [ebp+10h]
  float v65; // [esp+BCh] [ebp+14h]

  z = v2->z;
  v6 = v3->z;
  y = v3->y;
  v8 = v4->y;
  v9 = v4->z;
  vecOrigin = v2->y;
  v11 = vecOrigin - v1->y;
  ta = v2->x;
  v12 = ta - v1->x;
  v56 = z;
  v13 = z - v1->z;
  v57.y = v11;
  tMinus_4.y = v11;
  *(float *)&lengthU[4] = v11;
  x = v4->x;
  v57.x = v12;
  tMinus_4.x = v12;
  *(float *)lengthU = v12;
  v15 = v3->x;
  v57.z = v13;
  tMinus_4.z = v13;
  *(float *)&lengthU[8] = v13;
  t_4 = v6;
  v16 = v6 - v9;
  v17 = v9 - v1->z;
  v18 = y - v8;
  v19 = v8 - v1->y;
  v53 = x - v1->x;
  vecV.x = v53;
  v58.x = v53;
  v55.x = v15 - x;
  *(_QWORD *)&v55.y = __PAIR64__(LODWORD(v16), LODWORD(v18));
  vec.x = v15 - x;
  vec.y = v18;
  vec.z = v16;
  *(float *)&lengthU[12] = v15 - x;
  *(float *)&lengthU[16] = v18;
  *(float *)&lengthU[20] = v16;
  v54 = COERCE_DOUBLE(__PAIR64__(LODWORD(v17), LODWORD(v19)));
  vecV.y = v19;
  vecV.z = v17;
  v58.y = v19;
  v58.z = v17;
  axisUNorm[1].x = v15 - ta;
  axisUNorm[1].y = y - vecOrigin;
  axisUNorm[1].z = t_4 - v56;
  v52.x = v15 - ta;
  v52.y = y - vecOrigin;
  v52.z = t_4 - v56;
  axisUNorm[0].x = v15 - ta;
  axisUNorm[0].y = y - vecOrigin;
  axisUNorm[0].z = t_4 - v56;
  v49 = VectorNormalize(vec: &tMinus_4);
  v50 = VectorNormalize(&vec);
  tPlus_4 = VectorNormalize(vec: &vecV);
  tMinus = VectorNormalize(vec: &v52);
  if ( (float)((float)((float)(vec.x * tMinus_4.x) + (float)(vec.y * tMinus_4.y)) + (float)(vec.z * tMinus_4.z)) > 0.99000001
    && fabs(v49 - v50) < 0.1 )
  {
    return QuadWithParallelEdges(
             a1: COERCE_FLOAT(&lengthU[24]),
             vecOrigin: v1,
             vecU: &tMinus_4,
             lengthU: v49,
             &vecV,
             lengthV: tPlus_4,
             pt: (const Vector *)point,
             vecUV: (Vector2D *)HIDWORD(point));
  }
  v21 = 0;
  if ( (float)((float)((float)(v52.y * vecV.y) + (float)(v52.x * vecV.x)) + (float)(v52.z * vecV.z)) <= 0.99000001 )
  {
    v23 = *(float *)&lengthU[4];
    v22 = v58.y;
  }
  else
  {
    axisUNorm[0] = v55;
    *(Vector *)&lengthU[12] = axisUNorm[1];
    v58 = v57;
    v22 = v57.y;
    *(float *)lengthU = v53;
    v23 = *(float *)&v54;
    v21 = 1;
    *(long double *)&lengthU[4] = v54;
  }
  v24 = (float)(v22 * *(float *)lengthU) - (float)(v23 * v58.x);
  v25 = 0.0;
  axisUNorm[1].z = v24;
  v26 = 1.0;
  v27 = fabs(*(float *)&lengthU[4] * v58.z - v58.y * *(float *)&lengthU[8]);
  v28 = fabs(*(float *)&lengthU[8] * v58.x - v58.z * *(float *)lengthU);
  if ( v27 <= v28 )
  {
    if ( v28 > fabs(axisUNorm[1].z) )
      goto LABEL_11;
  }
  else if ( v27 > fabs(axisUNorm[1].z) )
  {
    v25 = 1.0;
LABEL_11:
    v26 = 2.0;
  }
  v29 = (int)v25;
  if ( fabs(*(float *)&lengthU[4 * (int)v26]) > fabs(*(float *)&lengthU[4 * (int)v25]) )
  {
    v25 = v26;
    v26 = (float)v29;
  }
  v30 = (int)v26;
  *(double *)&v55.y = 0.0;
  v31 = (int)v25;
  v54 = 0.0;
  v32 = *(&v58.x + (int)v25);
  v33 = 4 * v30;
  v34 = *(float *)&lengthU[v33];
  v35 = *(float *)&lengthU[v33 + 12];
  v36 = *(float *)&lengthU[4 * (int)v25 + 12];
  v65 = *(float *)((char *)&v58.x + v33);
  v56 = *(float *)&lengthU[4 * (int)v25];
  *(double *)&v57.y = (float)(v32 * v34) - (float)(v65 * v56) - v35 * v32 + v36 * v65;
  v37 = *(float *)(v33 + point);
  t = *(float *)(point + 4 * (int)v25);
  v38 = v36 * v37
      + v34 * t
      + *(float *)((char *)&v1->x + v33) * v56
      - v56 * v37
      - *(&v1->x + v31) * v34
      - *(float *)((char *)&v1->x + v33) * v36
      + *(&v1->x + v31) * v35
      - v35 * t
      + (float)(v32 * v34)
      - (float)(v65 * v56);
  if ( *(double *)&v57.y <= -0.1 || *(double *)&v57.y >= 0.1 )
  {
    v39 = v38 * v38
        - (v34 * t + *(float *)((char *)&v1->x + v33) * v56 - v56 * v37 - *(&v1->x + (int)v25) * v34)
        * (*(double *)&v57.y
         * 4.0);
    if ( v39 >= 0.0 )
    {
      v40 = sqrt(v39);
      v44.x = *(float *)point;
      *(_QWORD *)&v44.y = *(_QWORD *)(point + 4);
      ResolveQuadratic(
        tPlus: (v38 + v40) / (*(double *)&v57.y + *(double *)&v57.y),
        tMinus: (v38 - v40) / (*(double *)&v57.y + *(double *)&v57.y),
        axisU0: *(Vector *)lengthU,
        axisU1: *(Vector *)&lengthU[12],
        axisV0: v58,
        axisV1: axisUNorm[0],
        axisOrigin: *v1,
        pt: v44,
        projU: v31,
        s: (long double *)&v55.y,
        t: &v54);
      if ( v21 != 0 )
      {
        *(float *)HIDWORD(point) = v54;
        v41 = *(double *)&v55.y;
      }
      else
      {
        *(float *)HIDWORD(point) = *(double *)&v55.y;
        v41 = v54;
      }
      v42 = *(float *)HIDWORD(point);
      *(float *)(HIDWORD(point) + 4) = v41;
      result = BARY_QUADRATIC_FALSE;
      if ( v42 >= 0.0 && v42 <= 1.0 )
      {
        v43 = *(float *)(HIDWORD(point) + 4);
        if ( v43 >= 0.0 && v43 <= 1.0 )
          return BARY_QUADRATIC_TRUE;
      }
    }
    else
    {
      *(_DWORD *)HIDWORD(point) = -943501440;
      *(_DWORD *)(HIDWORD(point) + 4) = -943501440;
      return BARY_QUADRATIC_NEGATIVE_DISCRIMINANT;
    }
  }
  else
  {
    v57.x = (float)(vec.x + tMinus_4.x) * 0.5;
    axisUNorm[1].x = (float)(v52.x + vecV.x) * 0.5;
    v57.z = (float)(vec.z + tMinus_4.z) * 0.5;
    v57.y = (float)(vec.y + tMinus_4.y) * 0.5;
    axisUNorm[1].y = (float)(v52.y + vecV.y) * 0.5;
    axisUNorm[1].z = (float)(v52.z + vecV.z) * 0.5;
    return QuadWithParallelEdges(
             a1: COERCE_FLOAT(&lengthU[24]),
             vecOrigin: v1,
             vecU: &v57,
             lengthU: (float)(v50 + v49) * 0.5,
             vecV: &axisUNorm[1],
             lengthV: (float)(tMinus + tPlus_4) * 0.5,
             pt: (const Vector *)point,
             vecUV: (Vector2D *)HIDWORD(point));
  }
  return result;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10013B20
// Name: ComputeBoxOffset
// Source: json
//------------------------------------------------------------------------------
__m128 __usercall ComputeBoxOffset@<xmm0>(const Ray_t *ray@<eax>)
{
  __m128d v2; // xmm4
  float v3; // xmm0_4
  float v4; // xmm1_4
  double v5; // xmm1_8
  __m128 v6; // xmm1
  __m128d v7; // xmm0

  if ( ray->m_IsRay )
  {
    return (__m128)0x3A83126Fu;
  }
  else
  {
    v2 = (__m128d)0x3FF0000000000000uLL;
    v3 = (float)(fabs(ray->m_Extents.y * ray->m_Delta.y) + fabs(ray->m_Extents.x * ray->m_Delta.x))
       + fabs(ray->m_Extents.z * ray->m_Delta.z);
    v4 = ray->m_Delta.x * ray->m_Delta.x;
    if ( (float)((float)((float)(ray->m_Delta.y * ray->m_Delta.y) + v4) + (float)(ray->m_Delta.z * ray->m_Delta.z)) >= 1.0 )
      v5 = (float)((float)((float)(ray->m_Delta.y * ray->m_Delta.y) + v4) + (float)(ray->m_Delta.z * ray->m_Delta.z));
    else
      v5 = 1.0;
    v2.m128d_f64[0] = 1.0 / v5;
    v6 = _mm_cvtpd_ps(v2);
    v6.m128_f32[0] = v6.m128_f32[0] * v3;
    v7 = _mm_cvtps_pd(v6);
    v7.m128d_f64[0] = v7.m128d_f64[0] + 0.001;
    return _mm_cvtpd_ps(v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013BE0
// Name: bool ComputeIntersectionBarycentricCoordinates(struct Ray_t const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float __near &,float __near &,float __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ComputeIntersectionBarycentricCoordinates(
        const Ray_t *ray,
        const Vector *v1,
        const Vector *v2,
        const Vector *v3,
        float *u,
        float *v,
        float *t)
{
  float v8; // xmm3_4
  float v9; // xmm6_4
  float v10; // xmm5_4
  float v11; // xmm2_4
  float v12; // xmm7_4
  float x; // xmm1_4
  float v14; // xmm4_4
  float v15; // xmm6_4
  float v16; // xmm0_4
  float v18; // xmm3_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm4_4
  float v23; // xmm2_4
  float v24; // xmm7_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm4_4
  float v28; // xmm2_4
  float v29; // xmm2_4
  float v30; // xmm3_4
  double v31; // xmm3_8
  float v32; // xmm1_4
  float dirCrossEdge2_8; // [esp+8h] [ebp-1Ch]
  float edge1_4; // [esp+10h] [ebp-14h]
  float edge2; // [esp+18h] [ebp-Ch]
  float edge2_4; // [esp+1Ch] [ebp-8h]
  float edge2_8; // [esp+20h] [ebp-4h]
  float denoma; // [esp+30h] [ebp+Ch]
  float denom; // [esp+30h] [ebp+Ch]

  v8 = v3->x - v1->x;
  v9 = v3->z - v1->z;
  v10 = v2->x - v1->x;
  v11 = v2->z - v1->z;
  edge1_4 = v2->y - v1->y;
  v12 = ray->m_Delta.z * (float)(v3->y - v1->y);
  edge2_4 = v3->y - v1->y;
  x = ray->m_Delta.x;
  denoma = ray->m_Delta.y;
  v14 = (float)(denoma * v9) - v12;
  edge2_8 = v9;
  v15 = (float)(ray->m_Delta.z * v8) - (float)(x * v9);
  edge2 = v8;
  dirCrossEdge2_8 = (float)(x * edge2_4) - (float)(denoma * v8);
  v16 = (float)((float)(v15 * edge1_4) + (float)(v14 * v10)) + (float)(dirCrossEdge2_8 * v11);
  if ( fabs(v16) < 0.000001 )
    return false;
  v18 = ray->m_Start.y - v1->y;
  v19 = 1.0 / v16;
  v20 = ray->m_Start.x - v1->x;
  denom = v19;
  v21 = ray->m_Start.z - v1->z;
  *u = (float)((float)((float)(v18 * v15) + (float)(v20 * v14)) + (float)(v21 * dirCrossEdge2_8)) * denom;
  v22 = v18 * v11;
  v23 = v11 * v20;
  v24 = v21 * edge1_4;
  v25 = (float)(v20 * edge1_4) - (float)(v18 * v10);
  v26 = (float)(v21 * v10) - v23;
  v27 = v22 - v24;
  *v = (float)((float)((float)(ray->m_Delta.x * v27) + (float)(ray->m_Delta.y * v26)) + (float)(v25 * ray->m_Delta.z))
     * denom;
  if ( t == nullptr )
    return true;
  if ( ray->m_IsRay )
  {
    v28 = 0.001;
  }
  else
  {
    v29 = (float)(fabs(ray->m_Extents.y * ray->m_Delta.y) + fabs(ray->m_Extents.x * ray->m_Delta.x))
        + fabs(ray->m_Extents.z * ray->m_Delta.z);
    v30 = ray->m_Delta.x * ray->m_Delta.x;
    v31 = (float)((float)((float)(ray->m_Delta.y * ray->m_Delta.y) + v30) + (float)(ray->m_Delta.z * ray->m_Delta.z)) >= 1.0
        ? (float)((float)((float)(ray->m_Delta.y * ray->m_Delta.y) + v30) + (float)(ray->m_Delta.z * ray->m_Delta.z))
        : 1.0;
    v28 = (float)((float)(1.0 / v31) * v29) + 0.001;
  }
  v32 = (float)((float)((float)(v26 * edge2_4) + (float)(v27 * edge2)) + (float)(v25 * edge2_8)) * denom;
  *t = v32;
  return COERCE_FLOAT(LODWORD(v28) ^ _mask__NegFloat_) <= v32 && v32 <= (float)(v28 + 1.0);
}

//------------------------------------------------------------------------------
// Address: 0x10013EA0
// Name: int IntersectTriangleWithPlaneBarycentric(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector4D const __near &,class Vector2D __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl IntersectTriangleWithPlaneBarycentric(
        const Vector *org,
        const Vector *edgeU,
        const Vector *edgeV,
        const Vector4D *plane,
        Vector2D *pIntersection)
{
  float y; // xmm3_4
  float z; // xmm5_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  int v9; // ecx
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm1_4

  y = plane->y;
  z = plane->z;
  v7 = (float)((float)(org->y * y) + (float)(org->x * plane->x)) + (float)(org->z * z);
  v8 = (float)((float)(edgeU->y * y) + (float)(edgeU->x * plane->x)) + (float)(edgeU->z * z);
  v9 = 0;
  v10 = (float)((float)(edgeV->y * y) + (float)(edgeV->x * plane->x)) + (float)(edgeV->z * z);
  if ( v10 != 0.0 )
  {
    pIntersection->x = 0.0;
    v11 = -(float)((float)(v7 - plane->w) / v10);
    pIntersection->y = v11;
    if ( v11 >= 0.0 )
      v9 = v11 <= 1.0;
  }
  if ( v8 != 0.0 )
  {
    v12 = -(float)((float)(v7 - plane->w) / v8);
    pIntersection[v9].x = v12;
    pIntersection[v9].y = 0.0;
    if ( v12 >= 0.0 && v12 <= 1.0 )
      ++v9;
  }
  if ( v9 == 2 )
    return 2;
  if ( v10 != v8 )
  {
    v14 = -(float)((float)((float)(v7 - plane->w) + v10) / (float)(v8 - v10));
    v15 = 1.0 - v14;
    pIntersection[v9].x = v14;
    pIntersection[v9].y = 1.0 - v14;
    if ( v14 >= 0.0 && v14 <= 1.0 && v15 >= 0.0 && v15 <= 1.0 )
      ++v9;
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x10013FF0
// Name: bool IsBoxIntersectingSphere(class Vector const __near &,class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsBoxIntersectingSphere(const Vector *boxMin, const Vector *boxMax, const Vector *center, float radius)
{
  float x; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float y; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm2_4
  float z; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm2_4

  x = center->x;
  v5 = 0.0;
  if ( boxMin->x <= center->x )
  {
    if ( x <= boxMax->x )
      goto LABEL_6;
    v6 = boxMax->x - x;
  }
  else
  {
    v6 = x - boxMin->x;
  }
  v5 = v6 * v6;
LABEL_6:
  y = center->y;
  v8 = boxMin->y;
  if ( v8 <= y )
  {
    v9 = boxMax->y;
    if ( y > v9 )
      v5 = (float)((float)(v9 - y) * (float)(v9 - y)) + v5;
  }
  else
  {
    v5 = (float)((float)(y - v8) * (float)(y - v8)) + v5;
  }
  z = center->z;
  v11 = boxMin->z;
  if ( v11 <= z )
  {
    v12 = boxMax->z;
    if ( z > v12 )
      v5 = v5 + (float)((float)(v12 - z) * (float)(v12 - z));
  }
  else
  {
    v5 = v5 + (float)((float)(z - v11) * (float)(z - v11));
  }
  return (float)(radius * radius) > v5;
}

//------------------------------------------------------------------------------
// Address: 0x100140B0
// Name: bool IsPointInBox(class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsPointInBox(const Vector *pt, const Vector *boxMin, const Vector *boxMax)
{
  float y; // xmm0_4
  float z; // xmm0_4
  bool result; // al

  result = false;
  if ( pt->x <= boxMax->x && boxMin->x <= pt->x )
  {
    y = pt->y;
    if ( y <= boxMax->y && boxMin->y <= y )
    {
      z = pt->z;
      if ( z <= boxMax->z && boxMin->z <= z )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10014100
// Name: bool IsBoxIntersectingBox(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsBoxIntersectingBox(
        const Vector *boxMin1,
        const Vector *boxMax1,
        const Vector *boxMin2,
        const Vector *boxMax2)
{
  return boxMin1->x <= boxMax2->x
      && boxMin2->x <= boxMax1->x
      && boxMin1->y <= boxMax2->y
      && boxMin2->y <= boxMax1->y
      && boxMin1->z <= boxMax2->z
      && boxMin2->z <= boxMax1->z;
}

//------------------------------------------------------------------------------
// Address: 0x10014160
// Name: bool IntersectRayWithRay(struct Ray_t const __near &,struct Ray_t const __near &,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IntersectRayWithRay(const Ray_t *ray0, const Ray_t *ray1, float *t, float *s)
{
  float z; // eax
  float v6; // ecx
  __int64 v7; // xmm0_8
  float v8; // xmm6_4
  float v9; // xmm2_4
  float v10; // xmm4_4
  float v12; // xmm5_4
  float v13; // xmm7_4
  float v14; // xmm3_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm3_4
  float y; // xmm2_4
  float v19; // xmm4_4
  float v20; // xmm5_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm3_4
  float x; // xmm4_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  float v27; // xmm5_4
  float v28; // xmm0_4
  float v29; // xmm6_4
  float v0xv1; // [esp+10h] [ebp-28h]
  Vector v1; // [esp+1Ch] [ebp-1Ch] BYREF
  Vector v0; // [esp+28h] [ebp-10h] BYREF
  float lengthSq; // [esp+34h] [ebp-4h]
  float ray1a; // [esp+44h] [ebp+Ch]

  z = ray0->m_Delta.z;
  v6 = ray1->m_Delta.z;
  *(_QWORD *)&v0.x = *(_QWORD *)&ray0->m_Delta.x;
  v7 = *(_QWORD *)&ray1->m_Delta.x;
  v0.z = z;
  *(_QWORD *)&v1.x = v7;
  v1.z = v6;
  VectorNormalize(vec: &v0);
  VectorNormalize(vec: &v1);
  v8 = v1.z;
  v0xv1 = (float)(v1.z * v0.y) - (float)(v1.y * v0.z);
  v9 = (float)(v0.z * v1.x) - (float)(v1.z * v0.x);
  v10 = (float)(v1.y * v0.x) - (float)(v1.x * v0.y);
  lengthSq = (float)((float)(v9 * v9) + (float)(v0xv1 * v0xv1)) + (float)(v10 * v10);
  if ( lengthSq == 0.0 )
  {
    *t = 0.0;
    *s = 0.0;
    return false;
  }
  v12 = ray1->m_Start.x - ray0->m_Start.x;
  v13 = ray1->m_Start.z - ray0->m_Start.z;
  v14 = ray1->m_Start.y - ray0->m_Start.y;
  v15 = v14 * v0xv1;
  v16 = (float)(v13 * v0xv1) - (float)(v10 * v12);
  v17 = (float)(v14 * v10) - (float)(v13 * v9);
  ray1a = (float)(v9 * v12) - v15;
  y = v1.y;
  v19 = (float)((float)((float)-v16 * v1.y) + (float)((float)-v17 * v1.x)) + (float)((float)-ray1a * v1.z);
  v20 = (float)-v16 * v0.y;
  v21 = 1.0 / lengthSq;
  v22 = -v17;
  v23 = (float)(1.0 / lengthSq) * v19;
  x = v0.x;
  v25 = v22 * v0.x;
  *t = v23;
  v26 = v25 + v20;
  v27 = v0.z;
  v28 = (float)(v26 + (float)((float)-ray1a * v0.z)) * v21;
  *s = v28;
  v29 = v8 * v28;
  return (float)(ray0->m_Start.x + (float)(x * *t)) == (float)(ray1->m_Start.x + (float)(v1.x * v28))
      && (float)((float)(*t * v0.y) + ray0->m_Start.y) == (float)(ray1->m_Start.y + (float)(y * v28))
      && (float)(ray0->m_Start.z + (float)(v27 * *t)) == (float)(ray1->m_Start.z + v29);
}

//------------------------------------------------------------------------------
// Address: 0x100143A0
// Name: void ResolveQuadratic(double,double,class Vector,class Vector,class Vector,class Vector,class Vector,class Vector,int,double __near &,double __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ResolveQuadratic(
        double tPlus,
        double tMinus,
        Vector axisU0,
        Vector axisU1,
        Vector axisV0,
        Vector axisV1,
        Vector axisOrigin,
        Vector pt,
        int projU,
        long double *s,
        long double *t)
{
  float v12; // xmm4_4
  double v14; // xmm3_8
  double v15; // xmm0_8
  double v16; // xmm1_8
  float v17; // xmm4_4
  double v18; // xmm7_8
  double v19; // xmm0_8
  long double *v20; // ecx
  long double *v21; // eax
  double v22; // xmm4_8
  double v23; // xmm1_8
  double v24; // xmm0_8
  float v25; // xmm0_4
  float v26; // xmm2_4
  double v27; // xmm4_8
  double v28; // xmm2_8
  double v29; // xmm0_8
  double v30; // xmm1_8
  long double *v31; // edx
  long double *v32; // ecx
  double s0; // [esp+0h] [ebp-8h]
  double sMinus; // [esp+10h] [ebp+8h]
  double sPlus; // [esp+18h] [ebp+10h]

  v12 = *(&axisU1.x + projU);
  v14 = *(&axisU0.x + projU);
  v15 = (1.0 - tPlus) * v14 + v12 * tPlus;
  v16 = (1.0 - tMinus) * v14 + v12 * tMinus;
  sPlus = -99999.0;
  sMinus = -99999.0;
  v17 = v15;
  if ( fabs(v17) < 0.00001 )
  {
    v18 = -99999.0;
  }
  else
  {
    v18 = ((float)(*(&pt.x + projU) - *(&axisOrigin.x + projU)) - *(&axisV0.x + projU) * tPlus) / v15;
    sPlus = v18;
  }
  if ( fabs(v16) < 0.00001 )
  {
    v19 = -99999.0;
  }
  else
  {
    v19 = ((float)(*(&pt.x + projU) - *(&axisOrigin.x + projU)) - *(&axisV0.x + projU) * tMinus) / v16;
    sMinus = v19;
  }
  if ( tPlus < 0.0 || tPlus > 1.0 || v18 < 0.0 || v18 > 1.0 )
  {
    if ( tMinus < 0.0 || tMinus > 1.0 || v19 < 0.0 || v19 > 1.0 )
    {
      s0 = v18;
      v22 = tPlus;
      if ( v18 >= 1.0 )
        s0 = v18 - 1.0;
      if ( tPlus >= 1.0 )
        v22 = tPlus - 1.0;
      v23 = v19;
      v24 = tMinus;
      if ( sMinus >= 1.0 )
        v23 = sMinus - 1.0;
      if ( tMinus >= 1.0 )
        v24 = tMinus - 1.0;
      v25 = v24;
      v26 = v22;
      v27 = fabs(v25);
      v28 = fabs(v26);
      v29 = fabs(s0);
      v30 = fabs(v23);
      if ( v28 > v29 )
        v29 = v28;
      if ( v27 > v30 )
        v30 = v27;
      if ( v29 <= v30 )
      {
        v32 = t;
        *s = sPlus;
        *v32 = tPlus;
      }
      else
      {
        v31 = t;
        *s = sMinus;
        *v31 = tMinus;
      }
    }
    else
    {
      v21 = t;
      *s = v19;
      *v21 = tMinus;
    }
  }
  else
  {
    v20 = t;
    *s = v18;
    *v20 = tPlus;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100145D0
// Name: void PointInQuadFromBarycentric(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector2D const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PointInQuadFromBarycentric(
        const Vector *v1,
        const Vector *v2,
        const Vector *v3,
        const Vector *v4,
        const Vector2D *uv,
        Vector *point)
{
  float y; // xmm0_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float x; // xmm6_4

  y = uv->y;
  v7 = (float)((float)(v4->x - v1->x) * y) + v1->x;
  v8 = (float)((float)(v4->y - v1->y) * y) + v1->y;
  v9 = (float)((float)(v4->z - v1->z) * y) + v1->z;
  v10 = (float)((float)(v3->y - v2->y) * y) + v2->y;
  v11 = (float)((float)(v3->z - v2->z) * y) + v2->z;
  x = uv->x;
  point->x = (float)((float)((float)((float)((float)(v3->x - v2->x) * y) + v2->x) - v7) * uv->x) + v7;
  point->y = (float)((float)(v10 - v8) * x) + v8;
  point->z = (float)((float)(v11 - v9) * x) + v9;
}

//------------------------------------------------------------------------------
// Address: 0x100146A0
// Name: void TexCoordInQuadFromBarycentric(class Vector2D const __near &,class Vector2D const __near &,class Vector2D const __near &,class Vector2D const __near &,class Vector2D const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TexCoordInQuadFromBarycentric(
        const Vector2D *v1,
        const Vector2D *v2,
        const Vector2D *v3,
        const Vector2D *v4,
        const Vector2D *uv,
        Vector2D *texCoord)
{
  float y; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm1_4
  float x; // xmm4_4

  y = uv->y;
  v7 = (float)((float)(v4->x - v1->x) * y) + v1->x;
  v8 = (float)((float)(v4->y - v1->y) * y) + v1->y;
  v9 = (float)((float)(v3->y - v2->y) * y) + v2->y;
  x = uv->x;
  texCoord->x = (float)((float)((float)((float)((float)(v3->x - v2->x) * y) + v2->x) - v7) * uv->x) + v7;
  texCoord->y = (float)((float)(v9 - v8) * x) + v8;
}

//------------------------------------------------------------------------------
// Address: 0x10014730
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
// Address: 0x10014780
// Name: float IntersectRayWithTriangle(struct Ray_t const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
double __cdecl IntersectRayWithTriangle(const Ray_t *ray, const Vector *v1, float v2, const Vector *v3, int oneSided)
{
  float y; // xmm0_4
  float z; // xmm5_4
  float v7; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm7_4
  float v12; // xmm5_4
  float x; // xmm2_4
  float v14; // xmm6_4
  float v15; // xmm3_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm4_4
  float v19; // xmm5_4
  float v20; // xmm7_4
  float v21; // xmm6_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm6_4
  float dirCrossEdge2_4; // [esp+4h] [ebp-20h]
  float edge2; // [esp+Ch] [ebp-18h]
  float edge2_4; // [esp+10h] [ebp-14h]
  float edge2_8; // [esp+14h] [ebp-10h]
  float edge1; // [esp+18h] [ebp-Ch]
  float edge1_4; // [esp+1Ch] [ebp-8h]
  float edge1_8; // [esp+20h] [ebp-4h]

  y = v1->y;
  z = v1->z;
  v7 = v3->x - v1->x;
  v8 = v3->y - y;
  v9 = v3->z - z;
  edge1 = *(float *)LODWORD(v2) - v1->x;
  edge1_4 = *(float *)(LODWORD(v2) + 4) - y;
  edge1_8 = *(float *)(LODWORD(v2) + 8) - z;
  edge2 = v7;
  edge2_4 = v8;
  edge2_8 = v9;
  if ( (_BYTE)oneSided != 0
    && (float)((float)((float)(ray->m_Delta.y
                             * (float)((float)((float)(*(float *)(LODWORD(v2) + 8) - z) * v7)
                                     - (float)(v9 * (float)(*(float *)LODWORD(v2) - v1->x))))
                     + (float)((float)((float)(v9 * (float)(*(float *)(LODWORD(v2) + 4) - y))
                                     - (float)(v8 * (float)(*(float *)(LODWORD(v2) + 8) - z)))
                             * ray->m_Delta.x))
             + (float)(ray->m_Delta.z
                     * (float)((float)(v8 * (float)(*(float *)LODWORD(v2) - v1->x))
                             - (float)(v7 * (float)(*(float *)(LODWORD(v2) + 4) - y))))) >= 0.0 )
  {
    return -1.0;
  }
  v10 = ray->m_Delta.y;
  v11 = v10 * v7;
  v12 = (float)(v10 * v9) - (float)(ray->m_Delta.z * v8);
  x = ray->m_Delta.x;
  dirCrossEdge2_4 = (float)(ray->m_Delta.z * v7) - (float)(x * v9);
  v14 = (float)(x * v8) - v11;
  if ( fabs((float)((float)(dirCrossEdge2_4 * edge1_4) + (float)(v12 * edge1)) + (float)(v14 * edge1_8)) < 0.000001 )
    return -1.0;
  v15 = ray->m_Start.y - v1->y;
  v16 = ray->m_Start.x - v1->x;
  *(float *)&oneSided = 1.0
                      / (float)((float)((float)(dirCrossEdge2_4 * edge1_4) + (float)(v12 * edge1))
                              + (float)(v14 * edge1_8));
  v17 = ray->m_Start.z - v1->z;
  v18 = (float)((float)((float)(v15 * dirCrossEdge2_4) + (float)(v16 * v12)) + (float)(v17 * v14)) * *(float *)&oneSided;
  if ( v18 < 0.0 )
    return -1.0;
  if ( v18 > 1.0 )
    return -1.0;
  v19 = (float)(v15 * edge1_8) - (float)(v17 * edge1_4);
  v20 = (float)(v16 * edge1_4) - (float)(v15 * edge1);
  v21 = (float)(v17 * edge1) - (float)(v16 * edge1_8);
  v22 = (float)((float)((float)(x * v19) + (float)(v21 * ray->m_Delta.y)) + (float)(v20 * ray->m_Delta.z))
      * *(float *)&oneSided;
  if ( v22 < 0.0 )
    return -1.0;
  if ( (float)(v22 + v18) > 1.0 )
    return -1.0;
  v23 = ComputeBoxOffset(ray).m128_f32[0];
  v24 = (float)((float)((float)(v21 * edge2_4) + (float)(v19 * edge2)) + (float)(v20 * edge2_8)) * *(float *)&oneSided;
  v2 = v24;
  if ( COERCE_FLOAT(LODWORD(v23) ^ _mask__NegFloat_) > v24 || v24 > (float)(v23 + 1.0) )
    return -1.0;
  oneSided = 1;
  v1 = nullptr;
  return clamp<float,int,int>(val: &v2, minVal: (const int *)&v1, maxVal: &oneSided);
}

//------------------------------------------------------------------------------
// Address: 0x10014A30
// Name: enum QuadBarycentricRetval_t QuadWithParallelEdges(class Vector const __near &,class Vector const __near &,float,class Vector const __near &,float,class Vector const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall QuadWithParallelEdges@<eax>(
        float a1@<ebp>,
        const Vector *vecOrigin,
        const Vector *vecU,
        float lengthU,
        const Vector *vecV,
        float lengthV,
        const Vector *pt,
        Vector2D *vecUV)
{
  float z; // xmm0_4
  float x; // xmm1_4
  float y; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  Vector v19; // [esp-Ch] [ebp-BCh] BYREF
  Ray_t rayAxis; // [esp+0h] [ebp-B0h] BYREF
  Ray_t rayPt; // [esp+50h] [ebp-60h] BYREF
  float v22[2]; // [esp+A0h] [ebp-10h] BYREF
  float s; // [esp+A8h] [ebp-8h]
  float retaddr; // [esp+B0h] [ebp+0h]

  v22[1] = a1;
  s = retaddr;
  rayAxis.m_Extents.y = 0.0;
  rayPt.m_Extents.y = 0.0;
  v19 = *vecOrigin;
  *(Vector *)&rayAxis.m_Start.y = *vecU;
  *(float *)&rayAxis.m_IsRay = pt->x;
  *(float *)(&rayAxis.m_IsSwept + 3) = pt->y;
  z = pt->z;
  x = vecV->x;
  y = vecV->y;
  v11 = vecV->z;
  LOBYTE(rayAxis.m_Extents.z) = 1;
  LOBYTE(rayPt.m_Extents.z) = 1;
  *(float *)(&rayAxis.m_IsSwept + 7) = z;
  LODWORD(v12) = COERCE_UNSIGNED_INT(lengthV * 10.0) ^ _mask__NegFloat_;
  rayPt.m_Start.y = x * v12;
  rayPt.m_Start.z = y * v12;
  rayPt.m_Start.w = v11 * v12;
  IntersectRayWithRay(
    ray0: (const Ray_t *)&v19,
    ray1: (const Ray_t *)&rayAxis.m_IsRay,
    t: v22,
    s: (float *)(&rayPt.m_IsSwept + 7));
  vecUV->x = v22[0] / lengthU;
  LODWORD(v13) = COERCE_UNSIGNED_INT(lengthU * 10.0) ^ _mask__NegFloat_;
  v14 = vecU->y;
  v15 = vecU->z;
  *(Vector *)&rayAxis.m_Start.y = *vecV;
  rayPt.m_Start.y = vecU->x * v13;
  rayPt.m_Start.z = v14 * v13;
  rayPt.m_Start.w = v15 * v13;
  IntersectRayWithRay(
    ray0: (const Ray_t *)&v19,
    ray1: (const Ray_t *)&rayAxis.m_IsRay,
    t: v22,
    s: (float *)(&rayPt.m_IsSwept + 7));
  v16 = vecUV->x;
  v17 = v22[0] / lengthV;
  vecUV->y = v22[0] / lengthV;
  return v16 >= 0.0 && v16 <= 1.0 && v17 >= 0.0 && v17 <= 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10014C10
// Name: enum QuadBarycentricRetval_t PointInQuadToBarycentric(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
QuadBarycentricRetval_t __cdecl PointInQuadToBarycentric(
        const Vector *v1,
        const Vector *v2,
        const Vector *v3,
        const Vector *v4,
        const Vector *point,
        Vector2D *uv)
{
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm7_4
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm6_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm7_4
  float v18; // xmm5_4
  float v19; // xmm4_4
  float v20; // xmm6_4
  QuadBarycentricRetval_t result; // eax
  char v22; // bl
  float v23; // xmm5_4
  float v24; // xmm1_4
  float v25; // xmm3_4
  float v26; // xmm6_4
  float v27; // xmm4_4
  float v28; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm7_4
  float v31; // xmm2_4
  float v32; // xmm3_4
  float v33; // xmm1_4
  float v34; // xmm4_4
  float v35; // xmm0_4
  float v36; // xmm2_4
  float v37; // xmm1_4
  int v38; // eax
  int v39; // ecx
  float v40; // xmm0_4
  float v41; // xmm2_4
  float v42; // xmm6_4
  int v43; // eax
  float v44; // xmm4_4
  float v45; // xmm5_4
  float v46; // xmm6_4
  float v47; // xmm1_4
  float v48; // xmm5_4
  float v49; // xmm3_4
  float v50; // xmm7_4
  float v51; // xmm6_4
  float v52; // xmm0_4
  double v53; // xmm3_8
  double v54; // xmm0_8
  double v55; // xmm1_8
  double v56; // xmm2_8
  double v57; // xmm2_8
  float v58; // xmm0_4
  double v59; // xmm0_8
  float v60; // xmm0_4
  float v61; // xmm0_4
  float v62; // xmm0_4
  float tPlus; // [esp+0h] [ebp-A0h]
  float tPlus_4; // [esp+4h] [ebp-9Ch]
  Vector tMinus; // [esp+8h] [ebp-98h] BYREF
  float v66; // [esp+14h] [ebp-8Ch]
  _BYTE v67[12]; // [esp+18h] [ebp-88h] BYREF
  float v68; // [esp+24h] [ebp-7Ch]
  float v69; // [esp+28h] [ebp-78h]
  Vector vecV; // [esp+2Ch] [ebp-74h] BYREF
  Vector v71; // [esp+38h] [ebp-68h] BYREF
  Vector v72; // [esp+44h] [ebp-5Ch]
  Vector v73; // [esp+50h] [ebp-50h]
  Vector vec; // [esp+5Ch] [ebp-44h] BYREF
  Vector v75; // [esp+68h] [ebp-38h] BYREF
  float v76; // [esp+74h] [ebp-2Ch]
  _BYTE s[41]; // [esp+78h] [ebp-28h] OVERLAPPED BYREF
  float axisVNorm_16; // [esp+A8h] [ebp+8h]
  float axisVNorm_20; // [esp+ACh] [ebp+Ch]
  float axisVNorm_20a; // [esp+ACh] [ebp+Ch]
  float axisV; // [esp+B0h] [ebp+10h]

  x = v2->x;
  y = v2->y;
  z = v3->z;
  v9 = v3->y;
  v10 = v4->y;
  v11 = v4->z;
  *(float *)s = v2->z;
  v13 = *(float *)s - v1->z;
  axisVNorm_16 = y;
  axisVNorm_20 = x;
  v14 = x - v1->x;
  *(float *)&s[8] = y - v1->y;
  vec.y = *(float *)&s[8];
  *(_DWORD *)&s[20] = *(_DWORD *)&s[8];
  v15 = v4->x;
  *(float *)&s[4] = v14;
  *(float *)&s[12] = v13;
  vec.x = v14;
  vec.z = v13;
  *(float *)&s[16] = v14;
  v16 = v3->x;
  *(float *)&s[24] = v13;
  axisV = z;
  v17 = z - v11;
  v18 = v9 - v10;
  v19 = v10 - v1->y;
  v66 = v15 - v1->x;
  vecV.x = v66;
  *(_QWORD *)&v72.x = __PAIR64__(LODWORD(v19), LODWORD(v66));
  tMinus.x = v16 - v15;
  v75.x = v16 - v15;
  *(float *)&s[28] = v16 - v15;
  v20 = v11 - v1->z;
  tMinus.y = v18;
  tMinus.z = v17;
  v75.y = v18;
  v75.z = v17;
  *(float *)&s[32] = v18;
  *(float *)&s[36] = v17;
  *(_QWORD *)v67 = __PAIR64__(LODWORD(v20), LODWORD(v19));
  vecV.y = v19;
  vecV.z = v20;
  v72.z = v20;
  *(float *)&v67[8] = v16 - axisVNorm_20;
  v68 = v9 - axisVNorm_16;
  v69 = axisV - *(float *)s;
  v71.x = v16 - axisVNorm_20;
  v71.y = v9 - axisVNorm_16;
  v71.z = axisV - *(float *)s;
  v73.x = v16 - axisVNorm_20;
  v73.y = v9 - axisVNorm_16;
  v73.z = axisV - *(float *)s;
  v76 = VectorNormalize(&vec);
  *(float *)s = VectorNormalize(vec: &v75);
  tPlus = VectorNormalize(vec: &vecV);
  tPlus_4 = VectorNormalize(vec: &v71);
  if ( (float)((float)((float)(v75.x * vec.x) + (float)(v75.y * vec.y)) + (float)(v75.z * vec.z)) > 0.99000001
    && fabs(v76 - *(float *)s) < 0.1 )
  {
    return QuadWithParallelEdges(
             a1: COERCE_FLOAT(&s[40]),
             vecOrigin: v1,
             vecU: &vec,
             lengthU: v76,
             &vecV,
             lengthV: tPlus,
             pt: point,
             vecUV: uv);
  }
  v22 = 0;
  if ( (float)((float)((float)(v71.y * vecV.y) + (float)(v71.x * vecV.x)) + (float)(v71.z * vecV.z)) <= 0.99000001 )
  {
    v26 = *(float *)&s[16];
    v27 = *(float *)&s[20];
    v28 = *(float *)&s[24];
    v23 = v72.x;
    v24 = v72.y;
    v25 = v72.z;
  }
  else
  {
    v23 = *(float *)&s[4];
    v24 = *(float *)&s[8];
    v25 = *(float *)&s[12];
    v26 = v66;
    v27 = *(float *)v67;
    v28 = *(float *)&v67[4];
    v73 = tMinus;
    *(float *)&s[32] = v68;
    v22 = 1;
    v72 = *(Vector *)&s[4];
    *(float *)&s[16] = v66;
    *(_DWORD *)&s[20] = *(_DWORD *)v67;
    *(_QWORD *)&s[24] = *(_QWORD *)&v67[4];
    *(float *)&s[36] = v69;
  }
  v29 = v25 * v27;
  v30 = v24 * v28;
  v31 = (float)(v28 * v23) - (float)(v25 * v26);
  v32 = 1.0;
  v33 = (float)(v24 * v26) - (float)(v27 * v23);
  v34 = 0.0;
  v35 = fabs(v29 - v30);
  v36 = fabs(v31);
  v37 = fabs(v33);
  if ( v35 <= v36 )
  {
    if ( v36 > v37 )
      goto LABEL_11;
  }
  else if ( v35 > v37 )
  {
    v34 = 1.0;
LABEL_11:
    v32 = 2.0;
  }
  v38 = (int)v34;
  if ( fabs(*(float *)&s[4 * (int)v32 + 16]) > fabs(*(float *)&s[4 * (int)v34 + 16]) )
  {
    v34 = v32;
    v32 = (float)v38;
  }
  *(_QWORD *)&tMinus.y = 0;
  *(_QWORD *)v67 = 0;
  v39 = (int)v34;
  v40 = *(&v72.x + (int)v34);
  v41 = *(float *)&s[4 * (int)v34 + 16];
  v42 = *(float *)&s[4 * (int)v34 + 28];
  v43 = 4 * (int)v32;
  v44 = v40 * *(float *)&s[v43 + 16];
  v45 = *(float *)((char *)&v72.x + v43);
  v46 = v42 * v45;
  v47 = *(&v1->x + v39);
  v48 = v45 * v41;
  v49 = *(&point->x + v39);
  v50 = (float)((float)(v44 - v48) - (float)(*(float *)&s[v43 + 28] * v40)) + v46;
  v51 = *(float *)((char *)&point->x + v43);
  *(double *)&s[8] = v50;
  v52 = *(float *)((char *)&v1->x + v43);
  axisVNorm_20a = v49;
  v53 = (float)((float)((float)((float)(v52 * v41) - (float)(v51 * v41)) - (float)(v47 * *(float *)&s[v43 + 16]))
              + (float)(v49 * *(float *)&s[v43 + 16]));
  v54 = v53
      - (float)(v52 * *(float *)&s[4 * v39 + 28])
      + (float)(v51 * *(float *)&s[4 * v39 + 28])
      + (float)(v47 * *(float *)&s[v43 + 28])
      - (float)(axisVNorm_20a * *(float *)&s[v43 + 28])
      + v44
      - v48;
  v55 = v50;
  if ( v50 <= -0.1 || v55 >= 0.1 )
  {
    v56 = v54 * v54 - v55 * 4.0 * v53;
    if ( v56 >= 0.0 )
    {
      v57 = sqrt(v56);
      ResolveQuadratic(
        tPlus: (v57 + v54) / (v55 * 2.0),
        tMinus: (v54 - v57) / (v55 * 2.0),
        axisU0: *(Vector *)&s[16],
        axisU1: *(Vector *)&s[28],
        axisV0: v72,
        axisV1: v73,
        axisOrigin: *v1,
        pt: *point,
        projU: v39,
        s: (long double *)&tMinus.y,
        t: (long double *)v67);
      if ( v22 != 0 )
      {
        v60 = *(double *)v67;
        uv->x = v60;
        v59 = *(double *)&tMinus.y;
      }
      else
      {
        v58 = *(double *)&tMinus.y;
        uv->x = v58;
        v59 = *(double *)v67;
      }
      v61 = v59;
      uv->y = v61;
      result = BARY_QUADRATIC_FALSE;
      if ( uv->x >= 0.0 && uv->x <= 1.0 )
      {
        v62 = uv->y;
        if ( v62 >= 0.0 && v62 <= 1.0 )
          return BARY_QUADRATIC_TRUE;
      }
    }
    else
    {
      uv->x = -99999.0;
      uv->y = -99999.0;
      return BARY_QUADRATIC_NEGATIVE_DISCRIMINANT;
    }
  }
  else
  {
    *(float *)&s[4] = (float)(v75.x + vec.x) * 0.5;
    *(float *)&v67[8] = (float)(v71.x + vecV.x) * 0.5;
    *(float *)&s[8] = (float)(v75.y + vec.y) * 0.5;
    *(float *)&s[12] = (float)(v75.z + vec.z) * 0.5;
    v68 = (float)(v71.y + vecV.y) * 0.5;
    v69 = (float)(v71.z + vecV.z) * 0.5;
    return QuadWithParallelEdges(
             a1: COERCE_FLOAT(&s[40]),
             vecOrigin: v1,
             vecU: (const Vector *)&s[4],
             lengthU: (float)(*(float *)s + v76) * 0.5,
             vecV: (const Vector *)&v67[8],
             lengthV: (float)(tPlus_4 + tPlus) * 0.5,
             pt: point,
             vecUV: uv);
  }
  return result;
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x00401B70
// Name: public: Vector::Vector(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector::Vector(Vector *this)
{
  return this;
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x00406C40
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

} // namespace mdlcompile

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: public: Vector::Vector(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector::Vector(Vector *this)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401010
// Name: void __near * operator new(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}

} // namespace modelbrowser

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x00406330
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

} // namespace studiomdl

// ============================================================
// Overlay from vbsp (Missing functions)
// ============================================================
namespace vbsp {

//------------------------------------------------------------------------------
// Address: 0x00403570
// Name: float fabs(float)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl fabs(float _X)
{
  return fabs(_X);
}

//------------------------------------------------------------------------------
// Address: 0x00403580
// Name: public: Vector2D::Vector2D(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector2D::Vector2D(Vector *this)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00403590
// Name: void Vector2DSubtract(class Vector2D const __near &,class Vector2D const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector2DSubtract(const Vector2D *a, const Vector2D *b, Vector2D *c)
{
  c->x = a->x - b->x;
  c->y = a->y - b->y;
}

//------------------------------------------------------------------------------
// Address: 0x004035C0
// Name: public: void Vector::Init(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Vector::Init(Vector *this, float ix, float iy, float iz)
{
  this->x = ix;
  this->y = iy;
  this->z = iz;
}

//------------------------------------------------------------------------------
// Address: 0x004035F0
// Name: public: float Vector::Dot(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall Vector::Dot(Vector *this, const Vector *vOther)
{
  return vOther->y * this->y + vOther->x * this->x + vOther->z * this->z;
}

//------------------------------------------------------------------------------
// Address: 0x00403610
// Name: void CrossProduct(class Vector const __near &,class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CrossProduct(const Vector *a, const Vector *b, Vector *result)
{
  result->x = (float)(b->z * a->y) - (float)(a->z * b->y);
  result->y = (float)(a->z * b->x) - (float)(a->x * b->z);
  result->z = (float)(a->x * b->y) - (float)(b->x * a->y);
}

//------------------------------------------------------------------------------
// Address: 0x00403670
// Name: public: float Vector::Length(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall Vector::Length(Vector *this)
{
  return fsqrt((float)((float)(this->x * this->x) + (float)(this->y * this->y)) + (float)(this->z * this->z));
}

//------------------------------------------------------------------------------
// Address: 0x004036D0
// Name: public: class Vector Vector::operator-(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector::operator-(Vector *this, Vector *result, const Vector *v)
{
  result->x = this->x - v->x;
  result->y = this->y - v->y;
  result->z = this->z - v->z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403710
// Name: bool IsPointInBox(class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsPointInBox(const Vector *pt, const Vector *boxMin, const Vector *boxMax)
{
  float y; // xmm0_4
  float z; // xmm0_4
  bool result; // al

  result = false;
  if ( pt->x <= boxMax->x && boxMin->x <= pt->x )
  {
    y = pt->y;
    if ( y <= boxMax->y && boxMin->y <= y )
    {
      z = pt->z;
      if ( z <= boxMax->z && boxMin->z <= z )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403760
// Name: bool IsBoxIntersectingBox(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsBoxIntersectingBox(
        const Vector *boxMin1,
        const Vector *boxMax1,
        const Vector *boxMin2,
        const Vector *boxMax2)
{
  return boxMin1->x <= boxMax2->x
      && boxMin2->x <= boxMax1->x
      && boxMin1->y <= boxMax2->y
      && boxMin2->y <= boxMax1->y
      && boxMin1->z <= boxMax2->z
      && boxMin2->z <= boxMax1->z;
}

//------------------------------------------------------------------------------
// Address: 0x004037C0
// Name: void PointInQuadFromBarycentric(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector2D const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PointInQuadFromBarycentric(
        const Vector *v1,
        const Vector *v2,
        const Vector *v3,
        const Vector *v4,
        const Vector2D *uv,
        Vector *point)
{
  float y; // xmm0_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float x; // xmm6_4

  y = uv->y;
  v7 = (float)((float)(v4->x - v1->x) * y) + v1->x;
  v8 = (float)((float)(v4->y - v1->y) * y) + v1->y;
  v9 = (float)((float)(v4->z - v1->z) * y) + v1->z;
  v10 = (float)((float)(v3->y - v2->y) * y) + v2->y;
  v11 = (float)((float)(v3->z - v2->z) * y) + v2->z;
  x = uv->x;
  point->x = (float)((float)((float)((float)((float)(v3->x - v2->x) * y) + v2->x) - v7) * uv->x) + v7;
  point->y = (float)((float)(v10 - v8) * x) + v8;
  point->z = (float)((float)(v11 - v9) * x) + v9;
}

} // namespace vbsp

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00416240
// Name: public: float Vector::Dot(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall Vector::Dot(Vector *this, const Vector *vOther)
{
  return vOther->y * this->y + vOther->x * this->x + vOther->z * this->z;
}

//------------------------------------------------------------------------------
// Address: 0x00416260
// Name: bool IsBoxIntersectingBox(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsBoxIntersectingBox(
        const Vector *boxMin1,
        const Vector *boxMax1,
        const Vector *boxMin2,
        const Vector *boxMax2)
{
  return boxMin1->x <= boxMax2->x
      && boxMin2->x <= boxMax1->x
      && boxMin1->y <= boxMax2->y
      && boxMin2->y <= boxMax1->y
      && boxMin1->z <= boxMax2->z
      && boxMin2->z <= boxMax1->z;
}

//------------------------------------------------------------------------------
// Address: 0x004162C0
// Name: void PointInQuadFromBarycentric(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector2D const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PointInQuadFromBarycentric(
        const Vector *v1,
        const Vector *v2,
        const Vector *v3,
        const Vector *v4,
        const Vector2D *uv,
        Vector *point)
{
  float y; // xmm0_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float x; // xmm6_4

  y = uv->y;
  v7 = (float)((float)(v4->x - v1->x) * y) + v1->x;
  v8 = (float)((float)(v4->y - v1->y) * y) + v1->y;
  v9 = (float)((float)(v4->z - v1->z) * y) + v1->z;
  v10 = (float)((float)(v3->y - v2->y) * y) + v2->y;
  v11 = (float)((float)(v3->z - v2->z) * y) + v2->z;
  x = uv->x;
  point->x = (float)((float)((float)((float)((float)(v3->x - v2->x) * y) + v2->x) - v7) * uv->x) + v7;
  point->y = (float)((float)(v10 - v8) * x) + v8;
  point->z = (float)((float)(v11 - v9) * x) + v9;
}

//------------------------------------------------------------------------------
// Address: 0x00416390
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

} // namespace vmap

// ============================================================
// Overlay from vphysics (Missing functions)
// ============================================================
namespace vphysics {

//------------------------------------------------------------------------------
// Address: 0x10001000
// Name: bool IsBoxIntersectingRay(union __m128 const __near &,union __m128 const __near &,union __m128 const __near &,union __m128 const __near &,union __m128 const __near &,union __m128 const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __fastcall IsBoxIntersectingRay(
        const __m128 *inBoxMin,
        const __m128 *inBoxMax,
        const __m128 *origin,
        const __m128 *delta,
        const __m128 *invDelta,
        const __m128 *vTolerance)
{
  __m128 v6; // xmm3
  __m128 v7; // xmm0
  __m128 v9; // xmm0
  __m128 v10; // xmm2
  __m128 v11; // xmm1
  __m128 v12; // xmm0
  __m128 v13; // xmm2
  __m128 v14; // xmm1

  v6 = _mm_sub_ps(*inBoxMax, *origin);
  v7 = _mm_sub_ps(*inBoxMin, *origin);
  if ( _mm_movemask_ps(
         _mm_and_ps(
           _mm_or_ps(
             _mm_and_ps(_mm_cmplt_ps(v6, *delta), _mm_cmplt_ps(v6, Four_Zeros)),
             _mm_and_ps(_mm_cmplt_ps(*delta, v7), _mm_cmplt_ps(Four_Zeros, v7))),
           *(__m128 *)g_SIMD_clear_wmask)) != 0 )
    return false;
  v9 = _mm_mul_ps(_mm_sub_ps(v7, *vTolerance), *invDelta);
  v10 = _mm_mul_ps(_mm_add_ps(*vTolerance, v6), *invDelta);
  v11 = _mm_max_ps(v9, v10);
  v12 = _mm_min_ps(v9, v10);
  v13 = _mm_min_ps(_mm_min_ps(v11, _mm_shuffle_ps(v11, v11, 57)), _mm_shuffle_ps(v11, v11, 78));
  v14 = _mm_max_ps(_mm_max_ps(v12, _mm_shuffle_ps(v12, v12, 57)), _mm_shuffle_ps(v12, v12, 78));
  return _mm_movemask_ps(
           _mm_cmpeq_ps(
             _mm_cmplt_ps(
               _mm_min_ps(_mm_shuffle_ps(v13, v13, 0), Four_Ones),
               _mm_max_ps(_mm_shuffle_ps(v14, v14, 0), Four_Zeros)),
             Four_Zeros)) == 15;
}

//------------------------------------------------------------------------------
// Address: 0x100010D0
// Name: bool IsBoxIntersectingRay(union __m128 const __near &,union __m128 const __near &,struct Ray_t const __near &,union __m128 const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
bool __userpurge IsBoxIntersectingRay@<al>(
        const __m128 *boxMin@<ecx>,
        const __m128 *boxMax@<edx>,
        int a3@<ebp>,
        const Ray_t *ray,
        const __m128 *fl4Tolerance)
{
  bool v5; // zf
  VectorAligned m_Extents; // xmm0
  __m128 v7; // xmm1
  __m128 v8; // xmm0
  __m128 v9; // xmm3
  __m128 v10; // xmm0
  __m128 v11; // xmm2
  __m128 v13; // xmm1
  __m128 v14; // xmm0
  _BYTE v15[88]; // [esp-Ch] [ebp-5Ch] OVERLAPPED BYREF
  _UNKNOWN *retaddr; // [esp+50h] [ebp+0h]

  *(_DWORD *)&v15[80] = a3;
  *(_DWORD *)&v15[84] = retaddr;
  v5 = !ray->m_IsSwept;
  m_Extents = ray->m_Extents;
  v7 = _mm_and_ps((__m128)ray->m_Start, *(__m128 *)g_SIMD_clear_wmask);
  *(__m128 *)&v15[48] = v7;
  v8 = _mm_and_ps((__m128)m_Extents, *(__m128 *)g_SIMD_clear_wmask);
  if ( v5 )
  {
    v9 = _mm_add_ps(_mm_sub_ps(v7, v8), *fl4Tolerance);
    v10 = _mm_add_ps(_mm_add_ps(v8, v7), *fl4Tolerance);
    *(__m128 *)&v15[64] = *boxMin;
    v11 = *boxMax;
    *(__m128 *)&v15[48] = v10;
    *(__m128 *)&v15[16] = v11;
    *(__m128 *)&v15[32] = v9;
    return *(float *)&v15[64] <= v10.m128_f32[0]
        && *(float *)&v15[32] <= *(float *)&v15[16]
        && *(float *)&v15[68] <= *(float *)&v15[52]
        && *(float *)&v15[36] <= *(float *)&v15[20]
        && *(float *)&v15[72] <= *(float *)&v15[56]
        && *(float *)&v15[40] <= *(float *)&v15[24];
  }
  else
  {
    v13 = _mm_and_ps((__m128)ray->m_Delta, *(__m128 *)g_SIMD_clear_wmask);
    *(__m128 *)v15 = _mm_sub_ps(*boxMin, v8);
    *(__m128 *)&v15[64] = _mm_add_ps(*boxMax, v8);
    v14 = _mm_rcp_ps(v13);
    *(__m128 *)&v15[32] = v13;
    *(__m128 *)&v15[16] = _mm_sub_ps(_mm_add_ps(v14, v14), _mm_mul_ps(_mm_mul_ps(v14, v14), v13));
    return IsBoxIntersectingRay(
             inBoxMin: (const __m128 *)v15,
             inBoxMax: (const __m128 *)&v15[64],
             origin: (const __m128 *)&v15[48],
             delta: (const __m128 *)&v15[32],
             invDelta: (const __m128 *)&v15[16],
             vTolerance: fl4Tolerance);
  }
}

} // namespace vphysics

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x1004C9C0
// Name: ComputeBoxOffset
// Source: json
//------------------------------------------------------------------------------
__m128 __usercall ComputeBoxOffset@<xmm0>(const Ray_t *ray@<eax>)
{
  __m128d v2; // xmm4
  float v3; // xmm0_4
  float v4; // xmm1_4
  double v5; // xmm1_8
  __m128 v6; // xmm1
  __m128d v7; // xmm0

  if ( ray->m_IsRay )
  {
    return (__m128)0x3A83126Fu;
  }
  else
  {
    v2 = (__m128d)0x3FF0000000000000uLL;
    v3 = (float)(fabs(ray->m_Extents.y * ray->m_Delta.y) + fabs(ray->m_Extents.x * ray->m_Delta.x))
       + fabs(ray->m_Extents.z * ray->m_Delta.z);
    v4 = ray->m_Delta.x * ray->m_Delta.x;
    if ( (float)((float)((float)(ray->m_Delta.y * ray->m_Delta.y) + v4) + (float)(ray->m_Delta.z * ray->m_Delta.z)) >= 1.0 )
      v5 = (float)((float)((float)(ray->m_Delta.y * ray->m_Delta.y) + v4) + (float)(ray->m_Delta.z * ray->m_Delta.z));
    else
      v5 = 1.0;
    v2.m128d_f64[0] = 1.0 / v5;
    v6 = _mm_cvtpd_ps(v2);
    v6.m128_f32[0] = v6.m128_f32[0] * v3;
    v7 = _mm_cvtps_pd(v6);
    v7.m128d_f64[0] = v7.m128d_f64[0] + 0.001;
    return _mm_cvtpd_ps(v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004CA80
// Name: bool ComputeIntersectionBarycentricCoordinates(struct Ray_t const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float __near &,float __near &,float __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ComputeIntersectionBarycentricCoordinates(
        const Ray_t *ray,
        const Vector *v1,
        const Vector *v2,
        const Vector *v3,
        float *u,
        float *v,
        float *t)
{
  float v8; // xmm3_4
  float v9; // xmm6_4
  float v10; // xmm5_4
  float v11; // xmm2_4
  float v12; // xmm7_4
  float x; // xmm1_4
  float v14; // xmm4_4
  float v15; // xmm6_4
  float v16; // xmm0_4
  float v18; // xmm3_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm4_4
  float v23; // xmm2_4
  float v24; // xmm7_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm4_4
  float v28; // xmm2_4
  float v29; // xmm2_4
  float v30; // xmm3_4
  double v31; // xmm3_8
  float v32; // xmm1_4
  float dirCrossEdge2_8; // [esp+8h] [ebp-1Ch]
  float edge1_4; // [esp+10h] [ebp-14h]
  float edge2; // [esp+18h] [ebp-Ch]
  float edge2_4; // [esp+1Ch] [ebp-8h]
  float edge2_8; // [esp+20h] [ebp-4h]
  float denoma; // [esp+30h] [ebp+Ch]
  float denom; // [esp+30h] [ebp+Ch]

  v8 = v3->x - v1->x;
  v9 = v3->z - v1->z;
  v10 = v2->x - v1->x;
  v11 = v2->z - v1->z;
  edge1_4 = v2->y - v1->y;
  v12 = ray->m_Delta.z * (float)(v3->y - v1->y);
  edge2_4 = v3->y - v1->y;
  x = ray->m_Delta.x;
  denoma = ray->m_Delta.y;
  v14 = (float)(denoma * v9) - v12;
  edge2_8 = v9;
  v15 = (float)(ray->m_Delta.z * v8) - (float)(x * v9);
  edge2 = v8;
  dirCrossEdge2_8 = (float)(x * edge2_4) - (float)(denoma * v8);
  v16 = (float)((float)(v15 * edge1_4) + (float)(v14 * v10)) + (float)(dirCrossEdge2_8 * v11);
  if ( fabs(v16) < 0.000001 )
    return false;
  v18 = ray->m_Start.y - v1->y;
  v19 = 1.0 / v16;
  v20 = ray->m_Start.x - v1->x;
  denom = v19;
  v21 = ray->m_Start.z - v1->z;
  *u = (float)((float)((float)(v18 * v15) + (float)(v20 * v14)) + (float)(v21 * dirCrossEdge2_8)) * denom;
  v22 = v18 * v11;
  v23 = v11 * v20;
  v24 = v21 * edge1_4;
  v25 = (float)(v20 * edge1_4) - (float)(v18 * v10);
  v26 = (float)(v21 * v10) - v23;
  v27 = v22 - v24;
  *v = (float)((float)((float)(ray->m_Delta.x * v27) + (float)(ray->m_Delta.y * v26)) + (float)(v25 * ray->m_Delta.z))
     * denom;
  if ( t == nullptr )
    return true;
  if ( ray->m_IsRay )
  {
    v28 = 0.001;
  }
  else
  {
    v29 = (float)(fabs(ray->m_Extents.y * ray->m_Delta.y) + fabs(ray->m_Extents.x * ray->m_Delta.x))
        + fabs(ray->m_Extents.z * ray->m_Delta.z);
    v30 = ray->m_Delta.x * ray->m_Delta.x;
    v31 = (float)((float)((float)(ray->m_Delta.y * ray->m_Delta.y) + v30) + (float)(ray->m_Delta.z * ray->m_Delta.z)) >= 1.0
        ? (float)((float)((float)(ray->m_Delta.y * ray->m_Delta.y) + v30) + (float)(ray->m_Delta.z * ray->m_Delta.z))
        : 1.0;
    v28 = (float)((float)(1.0 / v31) * v29) + 0.001;
  }
  v32 = (float)((float)((float)(v26 * edge2_4) + (float)(v27 * edge2)) + (float)(v25 * edge2_8)) * denom;
  *t = v32;
  return COERCE_FLOAT(LODWORD(v28) ^ _mask__NegFloat_) <= v32 && v32 <= (float)(v28 + 1.0);
}

//------------------------------------------------------------------------------
// Address: 0x1004CD40
// Name: bool IsBoxIntersectingSphere(class Vector const __near &,class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsBoxIntersectingSphere(const Vector *boxMin, const Vector *boxMax, const Vector *center, float radius)
{
  float x; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float y; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm2_4
  float z; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm2_4

  x = center->x;
  v5 = 0.0;
  if ( boxMin->x <= center->x )
  {
    if ( x <= boxMax->x )
      goto LABEL_6;
    v6 = boxMax->x - x;
  }
  else
  {
    v6 = x - boxMin->x;
  }
  v5 = v6 * v6;
LABEL_6:
  y = center->y;
  v8 = boxMin->y;
  if ( v8 <= y )
  {
    v9 = boxMax->y;
    if ( y > v9 )
      v5 = (float)((float)(v9 - y) * (float)(v9 - y)) + v5;
  }
  else
  {
    v5 = (float)((float)(y - v8) * (float)(y - v8)) + v5;
  }
  z = center->z;
  v11 = boxMin->z;
  if ( v11 <= z )
  {
    v12 = boxMax->z;
    if ( z > v12 )
      v5 = v5 + (float)((float)(v12 - z) * (float)(v12 - z));
  }
  else
  {
    v5 = v5 + (float)((float)(z - v11) * (float)(z - v11));
  }
  return (float)(radius * radius) > v5;
}

//------------------------------------------------------------------------------
// Address: 0x1004CE00
// Name: bool IsBoxIntersectingRay(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
bool __fastcall IsBoxIntersectingRay(
        const Vector *boxMin,
        const Vector *boxMax,
        const Vector *origin,
        const Vector *vecDelta,
        unsigned int flTolerance)
{
  __m128 v5; // xmm0
  __m128 v6; // xmm5
  __m128 v7; // xmm4
  __m128 v8; // xmm2
  __m128 v9; // xmm3
  __m128 v11; // xmm1
  __m128 v12; // xmm0
  __m128 v13; // xmm7
  __m128 v14; // xmm1
  __m128 v15; // xmm0
  __m128 v16; // xmm2
  __m128 v17; // xmm0
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm0
  __m128 v22; // xmm2
  __m128 v23; // [esp-Ch] [ebp-3Ch]
  __m128 startOutMins_4; // [esp+4h] [ebp-2Ch]

  v5 = _mm_shuffle_ps((__m128)flTolerance, (__m128)flTolerance, 0);
  v6 = _mm_add_ps(_mm_sub_ps(*(__m128 *)&boxMax->x, *(__m128 *)&origin->x), v5);
  v7 = _mm_sub_ps(_mm_sub_ps(*(__m128 *)&boxMin->x, *(__m128 *)&origin->x), v5);
  v8 = _mm_cmplt_ps(v6, *(__m128 *)&vecDelta->x);
  startOutMins_4 = _mm_cmplt_ps(v6, Four_Zeros);
  v9 = _mm_cmplt_ps(*(__m128 *)&vecDelta->x, v7);
  v23 = _mm_cmplt_ps(Four_Zeros, v7);
  if ( _mm_movemask_ps(_mm_and_ps(_mm_or_ps(_mm_and_ps(v8, startOutMins_4), _mm_and_ps(v9, v23)), *(__m128 *)g_SIMD_clear_wmask)) != 0 )
    return false;
  v11 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(Four_Zeros, *(__m128 *)&vecDelta->x), Four_Epsilons), *(__m128 *)&vecDelta->x);
  v12 = _mm_rcp_ps(v11);
  v13 = _mm_mul_ps(_mm_mul_ps(v12, v12), v11);
  v14 = _mm_or_ps(_mm_xor_ps(v8, startOutMins_4), _mm_xor_ps(v9, v23));
  v15 = _mm_sub_ps(_mm_add_ps(v12, v12), v13);
  v16 = _mm_mul_ps(v15, v7);
  v17 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v15, v6), v14), _mm_andnot_ps(v14, Four_FLT_MAX));
  v18 = _mm_or_ps(_mm_and_ps(v16, v14), _mm_andnot_ps(v14, Four_Negative_FLT_MAX));
  v19 = _mm_max_ps(v18, v17);
  v20 = _mm_min_ps(v18, v17);
  v21 = _mm_min_ps(_mm_min_ps(v19, _mm_shuffle_ps(v19, v19, 57)), _mm_shuffle_ps(v19, v19, 78));
  v22 = _mm_max_ps(_mm_max_ps(v20, _mm_shuffle_ps(v20, v20, 57)), _mm_shuffle_ps(v20, v20, 78));
  return _mm_movemask_ps(
           _mm_cmpeq_ps(
             _mm_cmplt_ps(
               _mm_min_ps(_mm_shuffle_ps(v21, v21, 0), Four_Ones),
               _mm_max_ps(_mm_shuffle_ps(v22, v22, 0), Four_Zeros)),
             Four_Zeros)) == 15;
}

//------------------------------------------------------------------------------
// Address: 0x1004CF60
// Name: bool IntersectRayWithRay(struct Ray_t const __near &,struct Ray_t const __near &,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IntersectRayWithRay(const Ray_t *ray0, const Ray_t *ray1, float *t, float *s)
{
  float z; // eax
  float v6; // ecx
  __int64 v7; // xmm0_8
  float v8; // xmm6_4
  float v9; // xmm2_4
  float v10; // xmm4_4
  float v12; // xmm5_4
  float v13; // xmm7_4
  float v14; // xmm3_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm3_4
  float y; // xmm2_4
  float v19; // xmm4_4
  float v20; // xmm5_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm3_4
  float x; // xmm4_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  float v27; // xmm5_4
  float v28; // xmm0_4
  float v29; // xmm6_4
  float v0xv1; // [esp+10h] [ebp-28h]
  Vector v1; // [esp+1Ch] [ebp-1Ch] BYREF
  Vector v0; // [esp+28h] [ebp-10h] BYREF
  float lengthSq; // [esp+34h] [ebp-4h]
  float ray1a; // [esp+44h] [ebp+Ch]

  z = ray0->m_Delta.z;
  v6 = ray1->m_Delta.z;
  *(_QWORD *)&v0.x = *(_QWORD *)&ray0->m_Delta.x;
  v7 = *(_QWORD *)&ray1->m_Delta.x;
  v0.z = z;
  *(_QWORD *)&v1.x = v7;
  v1.z = v6;
  VectorNormalize(vec: &v0);
  VectorNormalize(vec: &v1);
  v8 = v1.z;
  v0xv1 = (float)(v1.z * v0.y) - (float)(v1.y * v0.z);
  v9 = (float)(v0.z * v1.x) - (float)(v1.z * v0.x);
  v10 = (float)(v1.y * v0.x) - (float)(v1.x * v0.y);
  lengthSq = (float)((float)(v9 * v9) + (float)(v0xv1 * v0xv1)) + (float)(v10 * v10);
  if ( lengthSq == 0.0 )
  {
    *t = 0.0;
    *s = 0.0;
    return false;
  }
  v12 = ray1->m_Start.x - ray0->m_Start.x;
  v13 = ray1->m_Start.z - ray0->m_Start.z;
  v14 = ray1->m_Start.y - ray0->m_Start.y;
  v15 = v14 * v0xv1;
  v16 = (float)(v13 * v0xv1) - (float)(v10 * v12);
  v17 = (float)(v14 * v10) - (float)(v13 * v9);
  ray1a = (float)(v9 * v12) - v15;
  y = v1.y;
  v19 = (float)((float)((float)-v16 * v1.y) + (float)((float)-v17 * v1.x)) + (float)((float)-ray1a * v1.z);
  v20 = (float)-v16 * v0.y;
  v21 = 1.0 / lengthSq;
  v22 = -v17;
  v23 = (float)(1.0 / lengthSq) * v19;
  x = v0.x;
  v25 = v22 * v0.x;
  *t = v23;
  v26 = v25 + v20;
  v27 = v0.z;
  v28 = (float)(v26 + (float)((float)-ray1a * v0.z)) * v21;
  *s = v28;
  v29 = v8 * v28;
  return (float)(ray0->m_Start.x + (float)(x * *t)) == (float)(ray1->m_Start.x + (float)(v1.x * v28))
      && (float)((float)(*t * v0.y) + ray0->m_Start.y) == (float)(ray1->m_Start.y + (float)(y * v28))
      && (float)(ray0->m_Start.z + (float)(v27 * *t)) == (float)(ray1->m_Start.z + v29);
}

//------------------------------------------------------------------------------
// Address: 0x1004D1A0
// Name: void ResolveQuadratic(double,double,class Vector,class Vector,class Vector,class Vector,class Vector,class Vector,int,double __near &,double __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ResolveQuadratic(
        double tPlus,
        double tMinus,
        Vector axisU0,
        Vector axisU1,
        Vector axisV0,
        Vector axisV1,
        Vector axisOrigin,
        Vector pt,
        int projU,
        long double *s,
        long double *t)
{
  float v12; // xmm4_4
  double v14; // xmm3_8
  double v15; // xmm0_8
  double v16; // xmm1_8
  float v17; // xmm4_4
  double v18; // xmm7_8
  double v19; // xmm0_8
  long double *v20; // ecx
  long double *v21; // eax
  double v22; // xmm4_8
  double v23; // xmm1_8
  double v24; // xmm0_8
  float v25; // xmm0_4
  float v26; // xmm2_4
  double v27; // xmm4_8
  double v28; // xmm2_8
  double v29; // xmm0_8
  double v30; // xmm1_8
  long double *v31; // edx
  long double *v32; // ecx
  double s0; // [esp+0h] [ebp-8h]
  double sMinus; // [esp+10h] [ebp+8h]
  double sPlus; // [esp+18h] [ebp+10h]

  v12 = *(&axisU1.x + projU);
  v14 = *(&axisU0.x + projU);
  v15 = (1.0 - tPlus) * v14 + v12 * tPlus;
  v16 = (1.0 - tMinus) * v14 + v12 * tMinus;
  sPlus = -99999.0;
  sMinus = -99999.0;
  v17 = v15;
  if ( fabs(v17) < 0.00001 )
  {
    v18 = -99999.0;
  }
  else
  {
    v18 = ((float)(*(&pt.x + projU) - *(&axisOrigin.x + projU)) - *(&axisV0.x + projU) * tPlus) / v15;
    sPlus = v18;
  }
  if ( fabs(v16) < 0.00001 )
  {
    v19 = -99999.0;
  }
  else
  {
    v19 = ((float)(*(&pt.x + projU) - *(&axisOrigin.x + projU)) - *(&axisV0.x + projU) * tMinus) / v16;
    sMinus = v19;
  }
  if ( tPlus < 0.0 || tPlus > 1.0 || v18 < 0.0 || v18 > 1.0 )
  {
    if ( tMinus < 0.0 || tMinus > 1.0 || v19 < 0.0 || v19 > 1.0 )
    {
      s0 = v18;
      v22 = tPlus;
      if ( v18 >= 1.0 )
        s0 = v18 - 1.0;
      if ( tPlus >= 1.0 )
        v22 = tPlus - 1.0;
      v23 = v19;
      v24 = tMinus;
      if ( sMinus >= 1.0 )
        v23 = sMinus - 1.0;
      if ( tMinus >= 1.0 )
        v24 = tMinus - 1.0;
      v25 = v24;
      v26 = v22;
      v27 = fabs(v25);
      v28 = fabs(v26);
      v29 = fabs(s0);
      v30 = fabs(v23);
      if ( v28 > v29 )
        v29 = v28;
      if ( v27 > v30 )
        v30 = v27;
      if ( v29 <= v30 )
      {
        v32 = t;
        *s = sPlus;
        *v32 = tPlus;
      }
      else
      {
        v31 = t;
        *s = sMinus;
        *v31 = tMinus;
      }
    }
    else
    {
      v21 = t;
      *s = v19;
      *v21 = tMinus;
    }
  }
  else
  {
    v20 = t;
    *s = v18;
    *v20 = tPlus;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004D3D0
// Name: void ComputePointFromBarycentric(class Vector2D const __near &,class Vector2D const __near &,class Vector2D const __near &,float,float,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputePointFromBarycentric(
        const Vector2D *v0,
        const Vector2D *v1,
        const Vector2D *v2,
        float u,
        float v,
        Vector2D *pt)
{
  float v6; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm0_4

  v6 = (float)(v1->y - v0->y) * u;
  v7 = (float)(v2->y - v0->y) * v;
  v8 = (float)((float)(v1->x - v0->x) * u) + v0->x;
  v9 = (float)(v2->x - v0->x) * v;
  pt->x = v8;
  v10 = v6 + v0->y;
  pt->x = v9 + v8;
  pt->y = v7 + v10;
}

//------------------------------------------------------------------------------
// Address: 0x1004D440
// Name: float IntersectRayWithTriangle(struct Ray_t const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
double __cdecl IntersectRayWithTriangle(const Ray_t *ray, const Vector *v1, float v2, const Vector *v3, int oneSided)
{
  float y; // xmm0_4
  float z; // xmm5_4
  float v7; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm7_4
  float v12; // xmm5_4
  float x; // xmm2_4
  float v14; // xmm6_4
  float v15; // xmm3_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm4_4
  float v19; // xmm5_4
  float v20; // xmm7_4
  float v21; // xmm6_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm6_4
  float dirCrossEdge2_4; // [esp+4h] [ebp-20h]
  float edge2; // [esp+Ch] [ebp-18h]
  float edge2_4; // [esp+10h] [ebp-14h]
  float edge2_8; // [esp+14h] [ebp-10h]
  float edge1; // [esp+18h] [ebp-Ch]
  float edge1_4; // [esp+1Ch] [ebp-8h]
  float edge1_8; // [esp+20h] [ebp-4h]

  y = v1->y;
  z = v1->z;
  v7 = v3->x - v1->x;
  v8 = v3->y - y;
  v9 = v3->z - z;
  edge1 = *(float *)LODWORD(v2) - v1->x;
  edge1_4 = *(float *)(LODWORD(v2) + 4) - y;
  edge1_8 = *(float *)(LODWORD(v2) + 8) - z;
  edge2 = v7;
  edge2_4 = v8;
  edge2_8 = v9;
  if ( (_BYTE)oneSided != 0
    && (float)((float)((float)(ray->m_Delta.y
                             * (float)((float)((float)(*(float *)(LODWORD(v2) + 8) - z) * v7)
                                     - (float)(v9 * (float)(*(float *)LODWORD(v2) - v1->x))))
                     + (float)((float)((float)(v9 * (float)(*(float *)(LODWORD(v2) + 4) - y))
                                     - (float)(v8 * (float)(*(float *)(LODWORD(v2) + 8) - z)))
                             * ray->m_Delta.x))
             + (float)(ray->m_Delta.z
                     * (float)((float)(v8 * (float)(*(float *)LODWORD(v2) - v1->x))
                             - (float)(v7 * (float)(*(float *)(LODWORD(v2) + 4) - y))))) >= 0.0 )
  {
    return -1.0;
  }
  v10 = ray->m_Delta.y;
  v11 = v10 * v7;
  v12 = (float)(v10 * v9) - (float)(ray->m_Delta.z * v8);
  x = ray->m_Delta.x;
  dirCrossEdge2_4 = (float)(ray->m_Delta.z * v7) - (float)(x * v9);
  v14 = (float)(x * v8) - v11;
  if ( fabs((float)((float)(dirCrossEdge2_4 * edge1_4) + (float)(v12 * edge1)) + (float)(v14 * edge1_8)) < 0.000001 )
    return -1.0;
  v15 = ray->m_Start.y - v1->y;
  v16 = ray->m_Start.x - v1->x;
  *(float *)&oneSided = 1.0
                      / (float)((float)((float)(dirCrossEdge2_4 * edge1_4) + (float)(v12 * edge1))
                              + (float)(v14 * edge1_8));
  v17 = ray->m_Start.z - v1->z;
  v18 = (float)((float)((float)(v15 * dirCrossEdge2_4) + (float)(v16 * v12)) + (float)(v17 * v14)) * *(float *)&oneSided;
  if ( v18 < 0.0 )
    return -1.0;
  if ( v18 > 1.0 )
    return -1.0;
  v19 = (float)(v15 * edge1_8) - (float)(v17 * edge1_4);
  v20 = (float)(v16 * edge1_4) - (float)(v15 * edge1);
  v21 = (float)(v17 * edge1) - (float)(v16 * edge1_8);
  v22 = (float)((float)((float)(x * v19) + (float)(v21 * ray->m_Delta.y)) + (float)(v20 * ray->m_Delta.z))
      * *(float *)&oneSided;
  if ( v22 < 0.0 )
    return -1.0;
  if ( (float)(v22 + v18) > 1.0 )
    return -1.0;
  v23 = ComputeBoxOffset(ray).m128_f32[0];
  v24 = (float)((float)((float)(v21 * edge2_4) + (float)(v19 * edge2)) + (float)(v20 * edge2_8)) * *(float *)&oneSided;
  v2 = v24;
  if ( COERCE_FLOAT(LODWORD(v23) ^ _mask__NegFloat_) > v24 || v24 > (float)(v23 + 1.0) )
    return -1.0;
  oneSided = 1;
  v1 = nullptr;
  return clamp<float,int,int>(val: &v2, minVal: (const int *)&v1, maxVal: &oneSided);
}

//------------------------------------------------------------------------------
// Address: 0x1004D6F0
// Name: enum QuadBarycentricRetval_t QuadWithParallelEdges(class Vector const __near &,class Vector const __near &,float,class Vector const __near &,float,class Vector const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall QuadWithParallelEdges@<eax>(
        float a1@<ebp>,
        const Vector *vecOrigin,
        const Vector *vecU,
        float lengthU,
        const Vector *vecV,
        float lengthV,
        const Vector *pt,
        Vector2D *vecUV)
{
  float z; // xmm0_4
  float x; // xmm1_4
  float y; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  Vector v19; // [esp-Ch] [ebp-BCh] BYREF
  Ray_t rayAxis; // [esp+0h] [ebp-B0h] BYREF
  Ray_t rayPt; // [esp+50h] [ebp-60h] BYREF
  float v22[2]; // [esp+A0h] [ebp-10h] BYREF
  float s; // [esp+A8h] [ebp-8h]
  float retaddr; // [esp+B0h] [ebp+0h]

  v22[1] = a1;
  s = retaddr;
  rayAxis.m_Extents.y = 0.0;
  rayPt.m_Extents.y = 0.0;
  v19 = *vecOrigin;
  *(Vector *)&rayAxis.m_Start.y = *vecU;
  *(float *)&rayAxis.m_IsRay = pt->x;
  *(float *)(&rayAxis.m_IsSwept + 3) = pt->y;
  z = pt->z;
  x = vecV->x;
  y = vecV->y;
  v11 = vecV->z;
  LOBYTE(rayAxis.m_Extents.z) = 1;
  LOBYTE(rayPt.m_Extents.z) = 1;
  *(float *)(&rayAxis.m_IsSwept + 7) = z;
  LODWORD(v12) = COERCE_UNSIGNED_INT(lengthV * 10.0) ^ _mask__NegFloat_;
  rayPt.m_Start.y = x * v12;
  rayPt.m_Start.z = y * v12;
  rayPt.m_Start.w = v11 * v12;
  IntersectRayWithRay(
    ray0: (const Ray_t *)&v19,
    ray1: (const Ray_t *)&rayAxis.m_IsRay,
    t: v22,
    s: (float *)(&rayPt.m_IsSwept + 7));
  vecUV->x = v22[0] / lengthU;
  LODWORD(v13) = COERCE_UNSIGNED_INT(lengthU * 10.0) ^ _mask__NegFloat_;
  v14 = vecU->y;
  v15 = vecU->z;
  *(Vector *)&rayAxis.m_Start.y = *vecV;
  rayPt.m_Start.y = vecU->x * v13;
  rayPt.m_Start.z = v14 * v13;
  rayPt.m_Start.w = v15 * v13;
  IntersectRayWithRay(
    ray0: (const Ray_t *)&v19,
    ray1: (const Ray_t *)&rayAxis.m_IsRay,
    t: v22,
    s: (float *)(&rayPt.m_IsSwept + 7));
  v16 = vecUV->x;
  v17 = v22[0] / lengthV;
  vecUV->y = v22[0] / lengthV;
  return v16 >= 0.0 && v16 <= 1.0 && v17 >= 0.0 && v17 <= 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1004D8D0
// Name: enum QuadBarycentricRetval_t PointInQuadToBarycentric(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
QuadBarycentricRetval_t __cdecl PointInQuadToBarycentric(
        const Vector *v1,
        const Vector *v2,
        const Vector *v3,
        const Vector *v4,
        const Vector *point,
        Vector2D *uv)
{
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm7_4
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm6_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm7_4
  float v18; // xmm5_4
  float v19; // xmm4_4
  float v20; // xmm6_4
  QuadBarycentricRetval_t result; // eax
  char v22; // bl
  float v23; // xmm5_4
  float v24; // xmm1_4
  float v25; // xmm3_4
  float v26; // xmm6_4
  float v27; // xmm4_4
  float v28; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm7_4
  float v31; // xmm2_4
  float v32; // xmm3_4
  float v33; // xmm1_4
  float v34; // xmm4_4
  float v35; // xmm0_4
  float v36; // xmm2_4
  float v37; // xmm1_4
  int v38; // eax
  int v39; // ecx
  float v40; // xmm0_4
  float v41; // xmm2_4
  float v42; // xmm6_4
  int v43; // eax
  float v44; // xmm4_4
  float v45; // xmm5_4
  float v46; // xmm6_4
  float v47; // xmm1_4
  float v48; // xmm5_4
  float v49; // xmm3_4
  float v50; // xmm7_4
  float v51; // xmm6_4
  float v52; // xmm0_4
  double v53; // xmm3_8
  double v54; // xmm0_8
  double v55; // xmm1_8
  double v56; // xmm2_8
  double v57; // xmm2_8
  float v58; // xmm0_4
  double v59; // xmm0_8
  float v60; // xmm0_4
  float v61; // xmm0_4
  float v62; // xmm0_4
  float lengthV; // [esp+6Ch] [ebp-A0h]
  float lengthV_4; // [esp+70h] [ebp-9Ch]
  Vector v65; // [esp+74h] [ebp-98h] OVERLAPPED BYREF
  float v66; // [esp+80h] [ebp-8Ch]
  _BYTE t[20]; // [esp+84h] [ebp-88h] OVERLAPPED BYREF
  Vector axisVNorm[2]; // [esp+98h] [ebp-74h] BYREF
  Vector axisV[2]; // [esp+B0h] [ebp-5Ch]
  Vector axisUNorm[2]; // [esp+C8h] [ebp-44h] BYREF
  float lengthU[2]; // [esp+E0h] [ebp-2Ch]
  Vector vecU; // [esp+E8h] [ebp-24h] BYREF
  Vector axisU[2]; // [esp+F4h] [ebp-18h]
  int savedregs; // [esp+10Ch] [ebp+0h] BYREF
  const Vector *v1a; // [esp+114h] [ebp+8h]
  float bFlipped; // [esp+118h] [ebp+Ch]
  float bFlippeda; // [esp+118h] [ebp+Ch]
  const Vector *v3a; // [esp+11Ch] [ebp+10h]

  x = v2->x;
  y = v2->y;
  z = v3->z;
  v9 = v3->y;
  v10 = v4->y;
  v11 = v4->z;
  lengthU[1] = v2->z;
  v13 = lengthU[1] - v1->z;
  *(float *)&v1a = y;
  bFlipped = x;
  v14 = x - v1->x;
  vecU.y = y - v1->y;
  axisUNorm[0].y = vecU.y;
  axisU[0].y = vecU.y;
  v15 = v4->x;
  vecU.x = v14;
  vecU.z = v13;
  axisUNorm[0].x = v14;
  axisUNorm[0].z = v13;
  axisU[0].x = v14;
  v16 = v3->x;
  axisU[0].z = v13;
  *(float *)&v3a = z;
  v17 = z - v11;
  v18 = v9 - v10;
  v19 = v10 - v1->y;
  v66 = v15 - v1->x;
  axisVNorm[0].x = v66;
  axisV[0].x = v66;
  v65.x = v16 - v15;
  axisUNorm[1].x = v16 - v15;
  axisU[1].x = v16 - v15;
  v20 = v11 - v1->z;
  *(_QWORD *)&v65.y = __PAIR64__(LODWORD(v17), LODWORD(v18));
  axisUNorm[1].y = v18;
  axisUNorm[1].z = v17;
  axisU[1].y = v18;
  axisU[1].z = v17;
  *(_QWORD *)t = __PAIR64__(LODWORD(v20), LODWORD(v19));
  axisVNorm[0].y = v19;
  axisVNorm[0].z = v20;
  axisV[0].y = v19;
  axisV[0].z = v20;
  *(float *)&t[8] = v16 - bFlipped;
  *(float *)&t[12] = v9 - *(float *)&v1a;
  *(float *)&t[16] = *(float *)&v3a - lengthU[1];
  axisVNorm[1].x = v16 - bFlipped;
  axisVNorm[1].y = v9 - *(float *)&v1a;
  axisVNorm[1].z = *(float *)&v3a - lengthU[1];
  axisV[1].x = v16 - bFlipped;
  axisV[1].y = v9 - *(float *)&v1a;
  axisV[1].z = *(float *)&v3a - lengthU[1];
  lengthU[0] = VectorNormalize(vec: axisUNorm);
  lengthU[1] = VectorNormalize(vec: &axisUNorm[1]);
  lengthV = VectorNormalize(vec: axisVNorm);
  lengthV_4 = VectorNormalize(vec: &axisVNorm[1]);
  if ( (float)((float)((float)(axisUNorm[1].x * axisUNorm[0].x) + (float)(axisUNorm[1].y * axisUNorm[0].y))
             + (float)(axisUNorm[1].z * axisUNorm[0].z)) > 0.99000001
    && fabs(lengthU[0] - lengthU[1]) < 0.1 )
  {
    return QuadWithParallelEdges(
             a1: COERCE_FLOAT(&savedregs),
             vecOrigin: v1,
             vecU: axisUNorm,
             lengthU: lengthU[0],
             vecV: axisVNorm,
             lengthV,
             pt: point,
             vecUV: uv);
  }
  v22 = 0;
  if ( (float)((float)((float)(axisVNorm[1].y * axisVNorm[0].y) + (float)(axisVNorm[1].x * axisVNorm[0].x))
             + (float)(axisVNorm[1].z * axisVNorm[0].z)) <= 0.99000001 )
  {
    v26 = axisU[0].x;
    v27 = axisU[0].y;
    v28 = axisU[0].z;
    v23 = axisV[0].x;
    v24 = axisV[0].y;
    v25 = axisV[0].z;
  }
  else
  {
    v23 = vecU.x;
    v24 = vecU.y;
    v25 = vecU.z;
    v26 = v66;
    v27 = *(float *)t;
    v28 = *(float *)&t[4];
    axisV[1] = v65;
    qmemcpy(&axisU[0].y, t, 20);
    v22 = 1;
    axisV[0] = vecU;
    axisU[0].x = v66;
  }
  v29 = v25 * v27;
  v30 = v24 * v28;
  v31 = (float)(v28 * v23) - (float)(v25 * v26);
  v32 = 1.0;
  v33 = (float)(v24 * v26) - (float)(v27 * v23);
  v34 = 0.0;
  v35 = fabs(v29 - v30);
  v36 = fabs(v31);
  v37 = fabs(v33);
  if ( v35 <= v36 )
  {
    if ( v36 > v37 )
      goto LABEL_11;
  }
  else if ( v35 > v37 )
  {
    v34 = 1.0;
LABEL_11:
    v32 = 2.0;
  }
  v38 = (int)v34;
  if ( fabs(*(&axisU[0].x + (int)v32)) > fabs(*(&axisU[0].x + (int)v34)) )
  {
    v34 = v32;
    v32 = (float)v38;
  }
  *(_QWORD *)&v65.y = 0;
  *(_QWORD *)t = 0;
  v39 = (int)v34;
  v40 = *(&axisV[0].x + (int)v34);
  v41 = *(&axisU[0].x + (int)v34);
  v42 = *(&axisU[1].x + (int)v34);
  v43 = 4 * (int)v32;
  v44 = v40 * *(float *)((char *)&axisU[0].x + v43);
  v45 = *(float *)((char *)&axisV[0].x + v43);
  v46 = v42 * v45;
  v47 = *(&v1->x + v39);
  v48 = v45 * v41;
  v49 = *(&point->x + v39);
  v50 = (float)((float)(v44 - v48) - (float)(*(float *)((char *)&axisU[1].x + v43) * v40)) + v46;
  v51 = *(float *)((char *)&point->x + v43);
  *(double *)&vecU.y = v50;
  v52 = *(float *)((char *)&v1->x + v43);
  bFlippeda = v49;
  v53 = (float)((float)((float)((float)(v52 * v41) - (float)(v51 * v41))
                      - (float)(v47 * *(float *)((char *)&axisU[0].x + v43)))
              + (float)(v49 * *(float *)((char *)&axisU[0].x + v43)));
  v54 = v53
      - (float)(v52 * *(&axisU[1].x + v39))
      + (float)(v51 * *(&axisU[1].x + v39))
      + (float)(v47 * *(float *)((char *)&axisU[1].x + v43))
      - (float)(bFlippeda * *(float *)((char *)&axisU[1].x + v43))
      + v44
      - v48;
  v55 = v50;
  if ( v50 <= -0.1 || v55 >= 0.1 )
  {
    v56 = v54 * v54 - v55 * 4.0 * v53;
    if ( v56 >= 0.0 )
    {
      v57 = sqrt(v56);
      ResolveQuadratic(
        tPlus: (v57 + v54) / (v55 * 2.0),
        tMinus: (v54 - v57) / (v55 * 2.0),
        axisU0: axisU[0],
        axisU1: axisU[1],
        axisV0: axisV[0],
        axisV1: axisV[1],
        axisOrigin: *v1,
        pt: *point,
        projU: v39,
        s: (long double *)&v65.y,
        (long double *)t);
      if ( v22 != 0 )
      {
        v60 = *(double *)t;
        uv->x = v60;
        v59 = *(double *)&v65.y;
      }
      else
      {
        v58 = *(double *)&v65.y;
        uv->x = v58;
        v59 = *(double *)t;
      }
      v61 = v59;
      uv->y = v61;
      result = BARY_QUADRATIC_FALSE;
      if ( uv->x >= 0.0 && uv->x <= 1.0 )
      {
        v62 = uv->y;
        if ( v62 >= 0.0 && v62 <= 1.0 )
          return BARY_QUADRATIC_TRUE;
      }
    }
    else
    {
      uv->x = -99999.0;
      uv->y = -99999.0;
      return BARY_QUADRATIC_NEGATIVE_DISCRIMINANT;
    }
  }
  else
  {
    vecU.x = (float)(axisUNorm[1].x + axisUNorm[0].x) * 0.5;
    *(float *)&t[8] = (float)(axisVNorm[1].x + axisVNorm[0].x) * 0.5;
    vecU.y = (float)(axisUNorm[1].y + axisUNorm[0].y) * 0.5;
    vecU.z = (float)(axisUNorm[1].z + axisUNorm[0].z) * 0.5;
    *(float *)&t[12] = (float)(axisVNorm[1].y + axisVNorm[0].y) * 0.5;
    *(float *)&t[16] = (float)(axisVNorm[1].z + axisVNorm[0].z) * 0.5;
    return QuadWithParallelEdges(
             a1: COERCE_FLOAT(&savedregs),
             vecOrigin: v1,
             &vecU,
             lengthU: (float)(lengthU[1] + lengthU[0]) * 0.5,
             vecV: (const Vector *)&t[8],
             lengthV: (float)(lengthV_4 + lengthV) * 0.5,
             pt: point,
             vecUV: uv);
  }
  return result;
}

} // namespace vrad_dll

// ============================================================
// Overlay from vvis_dll (Missing functions)
// ============================================================
namespace vvis_dll {

//------------------------------------------------------------------------------
// Address: 0x1000B260
// Name: bool IsBoxIntersectingBox(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsBoxIntersectingBox(
        const Vector *boxMin1,
        const Vector *boxMax1,
        const Vector *boxMin2,
        const Vector *boxMax2)
{
  return boxMin1->x <= boxMax2->x
      && boxMin2->x <= boxMax1->x
      && boxMin1->y <= boxMax2->y
      && boxMin2->y <= boxMax1->y
      && boxMin1->z <= boxMax2->z
      && boxMin2->z <= boxMax1->z;
}

} // namespace vvis_dll

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x100C1D10
// Name: bool ComputeIntersectionBarycentricCoordinates(struct Ray_t const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float __near &,float __near &,float __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ComputeIntersectionBarycentricCoordinates(
        const Ray_t *ray,
        const Vector *v1,
        const Vector *v2,
        const Vector *v3,
        float *u,
        float *v,
        float *t)
{
  float v8; // xmm3_4
  float v9; // xmm6_4
  float v10; // xmm5_4
  float v11; // xmm2_4
  float v12; // xmm7_4
  float x; // xmm1_4
  float v14; // xmm4_4
  float v15; // xmm6_4
  float v16; // xmm0_4
  float v18; // xmm3_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm4_4
  float v23; // xmm2_4
  float v24; // xmm7_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm4_4
  float v28; // xmm2_4
  float v29; // xmm2_4
  float v30; // xmm3_4
  double v31; // xmm3_8
  float v32; // xmm1_4
  float dirCrossEdge2_8; // [esp+8h] [ebp-1Ch]
  float edge1_4; // [esp+10h] [ebp-14h]
  float edge2; // [esp+18h] [ebp-Ch]
  float edge2_4; // [esp+1Ch] [ebp-8h]
  float edge2_8; // [esp+20h] [ebp-4h]
  float denoma; // [esp+30h] [ebp+Ch]
  float denom; // [esp+30h] [ebp+Ch]

  v8 = v3->x - v1->x;
  v9 = v3->z - v1->z;
  v10 = v2->x - v1->x;
  v11 = v2->z - v1->z;
  edge1_4 = v2->y - v1->y;
  v12 = ray->m_Delta.z * (float)(v3->y - v1->y);
  edge2_4 = v3->y - v1->y;
  x = ray->m_Delta.x;
  denoma = ray->m_Delta.y;
  v14 = (float)(denoma * v9) - v12;
  edge2_8 = v9;
  v15 = (float)(ray->m_Delta.z * v8) - (float)(x * v9);
  edge2 = v8;
  dirCrossEdge2_8 = (float)(x * edge2_4) - (float)(denoma * v8);
  v16 = (float)((float)(v15 * edge1_4) + (float)(v14 * v10)) + (float)(dirCrossEdge2_8 * v11);
  if ( fabs(v16) < 0.000001 )
    return false;
  v18 = ray->m_Start.y - v1->y;
  v19 = 1.0 / v16;
  v20 = ray->m_Start.x - v1->x;
  denom = v19;
  v21 = ray->m_Start.z - v1->z;
  *u = (float)((float)((float)(v18 * v15) + (float)(v20 * v14)) + (float)(v21 * dirCrossEdge2_8)) * denom;
  v22 = v18 * v11;
  v23 = v11 * v20;
  v24 = v21 * edge1_4;
  v25 = (float)(v20 * edge1_4) - (float)(v18 * v10);
  v26 = (float)(v21 * v10) - v23;
  v27 = v22 - v24;
  *v = (float)((float)((float)(ray->m_Delta.x * v27) + (float)(ray->m_Delta.y * v26)) + (float)(v25 * ray->m_Delta.z))
     * denom;
  if ( t == nullptr )
    return true;
  if ( ray->m_IsRay )
  {
    v28 = 0.001;
  }
  else
  {
    v29 = (float)(fabs(ray->m_Extents.y * ray->m_Delta.y) + fabs(ray->m_Extents.x * ray->m_Delta.x))
        + fabs(ray->m_Extents.z * ray->m_Delta.z);
    v30 = ray->m_Delta.x * ray->m_Delta.x;
    v31 = (float)((float)((float)(ray->m_Delta.y * ray->m_Delta.y) + v30) + (float)(ray->m_Delta.z * ray->m_Delta.z)) >= 1.0
        ? (float)((float)((float)(ray->m_Delta.y * ray->m_Delta.y) + v30) + (float)(ray->m_Delta.z * ray->m_Delta.z))
        : 1.0;
    v28 = (float)((float)(1.0 / v31) * v29) + 0.001;
  }
  v32 = (float)((float)((float)(v26 * edge2_4) + (float)(v27 * edge2)) + (float)(v25 * edge2_8)) * denom;
  *t = v32;
  return COERCE_FLOAT(LODWORD(v28) ^ _mask__NegFloat_) <= v32 && v32 <= (float)(v28 + 1.0);
}

//------------------------------------------------------------------------------
// Address: 0x100C1FD0
// Name: bool IsSphereIntersectingSphere(class Vector const __near &,float,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsSphereIntersectingSphere(const Vector *center1, float radius1, const Vector *center2, float radius2)
{
  return (float)((float)(radius1 + radius2) * (float)(radius1 + radius2)) >= (float)((float)((float)((float)(center2->x - center1->x) * (float)(center2->x - center1->x))
                                                                                           + (float)((float)(center2->y - center1->y) * (float)(center2->y - center1->y)))
                                                                                   + (float)((float)(center2->z - center1->z)
                                                                                           * (float)(center2->z - center1->z)));
}

//------------------------------------------------------------------------------
// Address: 0x100C2030
// Name: bool IsBoxIntersectingSphere(class Vector const __near &,class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsBoxIntersectingSphere(const Vector *boxMin, const Vector *boxMax, const Vector *center, float radius)
{
  float x; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float y; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm2_4
  float z; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm2_4

  x = center->x;
  v5 = 0.0;
  if ( boxMin->x <= center->x )
  {
    if ( x <= boxMax->x )
      goto LABEL_6;
    v6 = boxMax->x - x;
  }
  else
  {
    v6 = x - boxMin->x;
  }
  v5 = v6 * v6;
LABEL_6:
  y = center->y;
  v8 = boxMin->y;
  if ( v8 <= y )
  {
    v9 = boxMax->y;
    if ( y > v9 )
      v5 = (float)((float)(v9 - y) * (float)(v9 - y)) + v5;
  }
  else
  {
    v5 = (float)((float)(y - v8) * (float)(y - v8)) + v5;
  }
  z = center->z;
  v11 = boxMin->z;
  if ( v11 <= z )
  {
    v12 = boxMax->z;
    if ( z > v12 )
      v5 = v5 + (float)((float)(v12 - z) * (float)(v12 - z));
  }
  else
  {
    v5 = v5 + (float)((float)(z - v11) * (float)(z - v11));
  }
  return (float)(radius * radius) > v5;
}

//------------------------------------------------------------------------------
// Address: 0x100C20F0
// Name: bool IntersectInfiniteRayWithSphere(class Vector const __near &,class Vector const __near &,class Vector const __near &,float,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IntersectInfiniteRayWithSphere(
        const Vector *vecRayOrigin,
        const Vector *vecRayDelta,
        const Vector *vecSphereCenter,
        float flRadius,
        float *pT1,
        float *pT2)
{
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  float x; // xmm5_4
  float v10; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm5_4
  float v14; // xmm2_4

  v6 = vecRayOrigin->x - vecSphereCenter->x;
  v7 = vecRayOrigin->y - vecSphereCenter->y;
  v8 = vecRayOrigin->z - vecSphereCenter->z;
  x = vecRayDelta->x;
  v10 = (float)((float)(x * x) + (float)(vecRayDelta->y * vecRayDelta->y)) + (float)(vecRayDelta->z * vecRayDelta->z);
  if ( v10 == 0.0 )
  {
    *pT2 = 0.0;
    *pT1 = 0.0;
    return (float)(flRadius * flRadius) >= (float)((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(v8 * v8));
  }
  else
  {
    v12 = (float)((float)((float)(vecRayDelta->y * v7) + (float)(x * v6)) + (float)(vecRayDelta->z * v8)) * 2.0;
    v13 = (float)(v12 * v12)
        - (float)((float)((float)((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(v8 * v8))
                        - (float)(flRadius * flRadius))
                * (float)(v10 * 4.0));
    if ( v13 >= 0.0 )
    {
      v14 = fsqrt(v13);
      *pT1 = (float)(COERCE_FLOAT(LODWORD(v12) ^ _mask__NegFloat_) - v14) * (float)(0.5 / v10);
      *pT2 = (float)(v14 - v12) * (float)(0.5 / v10);
      return true;
    }
    else
    {
      return false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C2240
// Name: bool IsPointInBox(class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsPointInBox(const Vector *pt, const Vector *boxMin, const Vector *boxMax)
{
  float y; // xmm0_4
  float z; // xmm0_4
  bool result; // al

  result = false;
  if ( pt->x <= boxMax->x && boxMin->x <= pt->x )
  {
    y = pt->y;
    if ( y <= boxMax->y && boxMin->y <= y )
    {
      z = pt->z;
      if ( z <= boxMax->z && boxMin->z <= z )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C2290
// Name: bool IsBoxIntersectingBox(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsBoxIntersectingBox(
        const Vector *boxMin1,
        const Vector *boxMax1,
        const Vector *boxMin2,
        const Vector *boxMax2)
{
  return boxMin1->x <= boxMax2->x
      && boxMin2->x <= boxMax1->x
      && boxMin1->y <= boxMax2->y
      && boxMin2->y <= boxMax1->y
      && boxMin1->z <= boxMax2->z
      && boxMin2->z <= boxMax1->z;
}

//------------------------------------------------------------------------------
// Address: 0x100C22F0
// Name: bool IsBoxIntersectingRay(union __m128 const __near &,union __m128 const __near &,union __m128 const __near &,union __m128 const __near &,union __m128 const __near &,union __m128 const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __fastcall IsBoxIntersectingRay(
        const __m128 *inBoxMin,
        const __m128 *inBoxMax,
        const __m128 *origin,
        const __m128 *delta,
        const __m128 *invDelta,
        const __m128 *vTolerance)
{
  __m128 v6; // xmm3
  __m128 v7; // xmm0
  __m128 v9; // xmm0
  __m128 v10; // xmm2
  __m128 v11; // xmm1
  __m128 v12; // xmm0
  __m128 v13; // xmm2
  __m128 v14; // xmm1

  v6 = _mm_sub_ps(*inBoxMax, *origin);
  v7 = _mm_sub_ps(*inBoxMin, *origin);
  if ( _mm_movemask_ps(
         _mm_and_ps(
           _mm_or_ps(
             _mm_and_ps(_mm_cmplt_ps(v6, *delta), _mm_cmplt_ps(v6, Four_Zeros)),
             _mm_and_ps(_mm_cmplt_ps(*delta, v7), _mm_cmplt_ps(Four_Zeros, v7))),
           *(__m128 *)g_SIMD_clear_wmask)) != 0 )
    return false;
  v9 = _mm_mul_ps(_mm_sub_ps(v7, *vTolerance), *invDelta);
  v10 = _mm_mul_ps(_mm_add_ps(*vTolerance, v6), *invDelta);
  v11 = _mm_max_ps(v9, v10);
  v12 = _mm_min_ps(v9, v10);
  v13 = _mm_min_ps(_mm_min_ps(v11, _mm_shuffle_ps(v11, v11, 57)), _mm_shuffle_ps(v11, v11, 78));
  v14 = _mm_max_ps(_mm_max_ps(v12, _mm_shuffle_ps(v12, v12, 57)), _mm_shuffle_ps(v12, v12, 78));
  return _mm_movemask_ps(
           _mm_cmpeq_ps(
             _mm_cmplt_ps(
               _mm_min_ps(_mm_shuffle_ps(v13, v13, 0), Four_Ones),
               _mm_max_ps(_mm_shuffle_ps(v14, v14, 0), Four_Zeros)),
             Four_Zeros)) == 15;
}

//------------------------------------------------------------------------------
// Address: 0x100C23C0
// Name: bool IntersectRayWithRay(struct Ray_t const __near &,struct Ray_t const __near &,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IntersectRayWithRay(const Ray_t *ray0, const Ray_t *ray1, float *t, float *s)
{
  float z; // eax
  float v6; // ecx
  __int64 v7; // xmm0_8
  float v8; // xmm6_4
  float v9; // xmm2_4
  float v10; // xmm4_4
  float v12; // xmm5_4
  float v13; // xmm7_4
  float v14; // xmm3_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm3_4
  float y; // xmm2_4
  float v19; // xmm4_4
  float v20; // xmm5_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm3_4
  float x; // xmm4_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  float v27; // xmm5_4
  float v28; // xmm0_4
  float v29; // xmm6_4
  float v0xv1; // [esp+10h] [ebp-28h]
  Vector v1; // [esp+1Ch] [ebp-1Ch] BYREF
  Vector v0; // [esp+28h] [ebp-10h] BYREF
  float lengthSq; // [esp+34h] [ebp-4h]
  float ray1a; // [esp+44h] [ebp+Ch]

  z = ray0->m_Delta.z;
  v6 = ray1->m_Delta.z;
  *(_QWORD *)&v0.x = *(_QWORD *)&ray0->m_Delta.x;
  v7 = *(_QWORD *)&ray1->m_Delta.x;
  v0.z = z;
  *(_QWORD *)&v1.x = v7;
  v1.z = v6;
  VectorNormalize(vec: &v0);
  VectorNormalize(vec: &v1);
  v8 = v1.z;
  v0xv1 = (float)(v1.z * v0.y) - (float)(v1.y * v0.z);
  v9 = (float)(v0.z * v1.x) - (float)(v1.z * v0.x);
  v10 = (float)(v1.y * v0.x) - (float)(v1.x * v0.y);
  lengthSq = (float)((float)(v9 * v9) + (float)(v0xv1 * v0xv1)) + (float)(v10 * v10);
  if ( lengthSq == 0.0 )
  {
    *t = 0.0;
    *s = 0.0;
    return false;
  }
  v12 = ray1->m_Start.x - ray0->m_Start.x;
  v13 = ray1->m_Start.z - ray0->m_Start.z;
  v14 = ray1->m_Start.y - ray0->m_Start.y;
  v15 = v14 * v0xv1;
  v16 = (float)(v13 * v0xv1) - (float)(v10 * v12);
  v17 = (float)(v14 * v10) - (float)(v13 * v9);
  ray1a = (float)(v9 * v12) - v15;
  y = v1.y;
  v19 = (float)((float)((float)-v16 * v1.y) + (float)((float)-v17 * v1.x)) + (float)((float)-ray1a * v1.z);
  v20 = (float)-v16 * v0.y;
  v21 = 1.0 / lengthSq;
  v22 = -v17;
  v23 = (float)(1.0 / lengthSq) * v19;
  x = v0.x;
  v25 = v22 * v0.x;
  *t = v23;
  v26 = v25 + v20;
  v27 = v0.z;
  v28 = (float)(v26 + (float)((float)-ray1a * v0.z)) * v21;
  *s = v28;
  v29 = v8 * v28;
  return (float)(ray0->m_Start.x + (float)(x * *t)) == (float)(ray1->m_Start.x + (float)(v1.x * v28))
      && (float)((float)(*t * v0.y) + ray0->m_Start.y) == (float)(ray1->m_Start.y + (float)(y * v28))
      && (float)(ray0->m_Start.z + (float)(v27 * *t)) == (float)(ray1->m_Start.z + v29);
}

//------------------------------------------------------------------------------
// Address: 0x100C2600
// Name: bool IntersectRayWithBox(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,struct BoxTraceInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IntersectRayWithBox(
        const Vector *vecRayStart,
        const Vector *vecRayDelta,
        const Vector *boxMins,
        const Vector *boxMaxs,
        float flTolerance,
        BoxTraceInfo_t *pTrace)
{
  const Vector *v6; // ecx
  const Vector *v7; // edi
  int v8; // esi
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm1_4

  v6 = vecRayStart;
  v7 = boxMaxs - 1;
  v8 = 0;
  pTrace->t1 = -1.0;
  pTrace->t2 = 1.0;
  pTrace->hitside = -1;
  pTrace->startsolid = true;
  do
  {
    if ( v8 < 3 )
    {
      v9 = *(float *)((char *)&v6->x + (char *)boxMins - (char *)vecRayStart) - v6->x;
      v10 = v9 - *(float *)((char *)&v6->x + (char *)vecRayDelta - (char *)vecRayStart);
    }
    else
    {
      v9 = *(float *)((char *)&v7->x + (char *)vecRayStart - (char *)boxMaxs) - v7->x;
      v10 = *(float *)((char *)&v7->x + (char *)vecRayDelta - (char *)boxMaxs) + v9;
    }
    if ( v9 > 0.0 && v10 > 0.0 )
    {
      pTrace->startsolid = false;
      return false;
    }
    if ( v9 > 0.0 || v10 > 0.0 )
    {
      if ( v9 > 0.0 )
        pTrace->startsolid = false;
      if ( v9 <= v10 )
      {
        v13 = (float)(v9 + flTolerance) / (float)(v9 - v10);
        if ( pTrace->t2 > v13 )
          pTrace->t2 = v13;
      }
      else
      {
        v11 = v9 - flTolerance;
        if ( (float)(v9 - flTolerance) < 0.0 )
          v11 = 0.0;
        v12 = v11 / (float)(v9 - v10);
        if ( v12 > pTrace->t1 )
        {
          pTrace->t1 = v12;
          pTrace->hitside = v8;
        }
      }
    }
    ++v8;
    v7 = (const Vector *)((char *)v7 + 4);
    v6 = (const Vector *)((char *)v6 + 4);
  }
  while ( v8 < 6 );
  return pTrace->startsolid || pTrace->t2 > pTrace->t1 && pTrace->t1 >= 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x100C2750
// Name: bool IntersectRayWithBox(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,class CBaseTrace __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IntersectRayWithBox(
        const Vector *vecRayStart,
        const Vector *vecRayDelta,
        const Vector *boxMins,
        const Vector *boxMaxs,
        float flTolerance,
        CBaseTrace *pTrace,
        float *pFractionLeftSolid)
{
  bool startsolid; // al
  float t2; // xmm0_4
  float t1; // xmm2_4
  bool v10; // cc
  int hitside; // eax
  double v12; // st7
  bool v14; // al
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm3_4
  float y; // xmm1_4
  BoxTraceInfo_t trace; // [esp+14h] [ebp-10h] BYREF

  pTrace->startpos = *vecRayStart;
  pTrace->endpos = *vecRayStart;
  pTrace->endpos.x = vecRayDelta->x + pTrace->endpos.x;
  pTrace->endpos.y = pTrace->endpos.y + vecRayDelta->y;
  pTrace->endpos.z = pTrace->endpos.z + vecRayDelta->z;
  *(_WORD *)&pTrace->allsolid = 0;
  *(_QWORD *)&pTrace->fraction = 1065353216;
  if ( IntersectRayWithBox(vecRayStart, vecRayDelta, boxMins, boxMaxs, flTolerance, pTrace: &trace) )
  {
    startsolid = trace.startsolid;
    t2 = trace.t2;
    t1 = trace.t1;
    v10 = trace.t2 <= trace.t1;
    pTrace->startsolid = trace.startsolid;
    if ( !v10 && t1 >= 0.0 )
    {
      hitside = trace.hitside;
      pTrace->fraction = t1;
      pTrace->endpos.x = (float)(vecRayDelta->x * t1) + pTrace->startpos.x;
      pTrace->endpos.y = (float)(vecRayDelta->y * t1) + pTrace->startpos.y;
      pTrace->endpos.z = (float)(t1 * vecRayDelta->z) + pTrace->startpos.z;
      pTrace->contents = 1;
      pTrace->plane.normal = vec3_origin;
      if ( hitside < 3 )
      {
        LODWORD(pTrace->plane.dist) = *((_DWORD *)&boxMins->x + hitside) ^ _mask__NegFloat_;
        *((_DWORD *)&pTrace->plane.normal.x + hitside) = -1082130432;
      }
      else
      {
        v12 = *(&boxMaxs[-1].x + hitside);
        hitside -= 3;
        pTrace->plane.dist = v12;
        *((_DWORD *)&pTrace->plane.normal.x + hitside) = 1065353216;
      }
      pTrace->plane.type = hitside;
      return 1;
    }
    if ( startsolid )
    {
      v14 = t2 <= 0.0 || t2 >= 1.0;
      pTrace->allsolid = v14;
      pTrace->fraction = 0.0;
      if ( pFractionLeftSolid != nullptr )
        *pFractionLeftSolid = t2;
      pTrace->endpos = pTrace->startpos;
      pTrace->contents = 1;
      pTrace->plane.dist = pTrace->startpos.x;
      pTrace->plane.normal.y = 0.0;
      pTrace->plane.normal.z = 0.0;
      pTrace->plane.normal.x = 1.0;
      pTrace->plane.type = 0;
      v15 = vecRayDelta->x * t2;
      v16 = vecRayDelta->y * t2;
      v17 = (float)(t2 * vecRayDelta->z) + vecRayStart->z;
      v18 = vecRayStart->x + v15;
      y = vecRayStart->y;
      pTrace->startpos.x = v18;
      pTrace->startpos.y = y + v16;
      pTrace->startpos.z = v17;
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100C2980
// Name: void ComputeSupportMap(class Vector const __near &,class Vector const __near &,class Vector const __near &,float __near * const)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeSupportMap(
        const Vector *vecDirection,
        const Vector *vecBoxMins,
        const Vector *vecBoxMaxs,
        float *pDist)
{
  unsigned int v4; // edx
  unsigned int v5; // edx
  unsigned int v6; // edx

  v4 = 4 * (vecDirection->x > 0.0);
  pDist[v4 / 4] = vecBoxMaxs->x * vecDirection->x;
  pDist[v4 / 0xFFFFFFFC + 1] = vecDirection->x * vecBoxMins->x;
  v5 = 4 * (vecDirection->y > 0.0);
  pDist[v5 / 4] = (float)(vecBoxMaxs->y * vecDirection->y) + pDist[v5 / 4];
  pDist[v5 / 0xFFFFFFFC + 1] = (float)(vecBoxMins->y * vecDirection->y) + pDist[v5 / 0xFFFFFFFC + 1];
  v6 = 4 * (vecDirection->z > 0.0);
  pDist[v6 / 4] = (float)(vecBoxMaxs->z * vecDirection->z) + pDist[v6 / 4];
  pDist[v6 / 0xFFFFFFFC + 1] = (float)(vecBoxMins->z * vecDirection->z) + pDist[v6 / 0xFFFFFFFC + 1];
}

//------------------------------------------------------------------------------
// Address: 0x100C2A60
// Name: ComputeSeparatingPlane
// Source: json
//------------------------------------------------------------------------------
char __usercall ComputeSeparatingPlane@<al>(
        const matrix3x4_t *worldToBox1@<edi>,
        cplane_t *pPlane@<esi>,
        const matrix3x4_t *box2ToWorld,
        const Vector *box1Size,
        const Vector *box2Size,
        float tolerance)
{
  float x; // xmm6_4
  float z; // xmm7_4
  float y; // xmm5_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  const float *v15; // eax
  float v16; // xmm5_4
  float v17; // xmm6_4
  matrix3x4_t box2ToBox1; // [esp+4h] [ebp-8Ch] BYREF
  matrix3x4_t absBox2ToBox1; // [esp+34h] [ebp-5Ch]
  Vector tmp; // [esp+64h] [ebp-2Ch] BYREF
  float v21; // [esp+70h] [ebp-20h]
  float v22; // [esp+74h] [ebp-1Ch]
  Vector box2Origin; // [esp+78h] [ebp-18h] BYREF
  float v24; // [esp+84h] [ebp-Ch]
  float v25; // [esp+88h] [ebp-8h]
  unsigned int v26; // [esp+8Ch] [ebp-4h]
  float box1Sizea; // [esp+9Ch] [ebp+Ch]
  float tolerancea; // [esp+A4h] [ebp+14h]

  ConcatTransforms(in1: worldToBox1, in2: box2ToWorld, out: &box2ToBox1);
  MatrixGetColumn(in: &box2ToBox1, column: 3, out: &box2Origin);
  x = box2Size->x;
  z = box2Size->z;
  *(_QWORD *)&absBox2ToBox1.m_flMatVal[1][0] = *(_QWORD *)&box2ToBox1.m_flMatVal[1][0] & 0x7FFFFFFF7FFFFFFFLL;
  absBox2ToBox1.m_flMatVal[1][2] = fabs(box2ToBox1.m_flMatVal[1][2]);
  *(_QWORD *)&absBox2ToBox1.m_flMatVal[2][0] = *(_QWORD *)&box2ToBox1.m_flMatVal[2][0] & 0x7FFFFFFF7FFFFFFFLL;
  absBox2ToBox1.m_flMatVal[2][2] = fabs(box2ToBox1.m_flMatVal[2][2]);
  y = box2Size->y;
  v24 = box1Size->x;
  v11 = fabs(box2ToBox1.m_flMatVal[0][0]);
  v22 = x;
  v12 = fabs(box2ToBox1.m_flMatVal[0][1]);
  v21 = y;
  v13 = fabs(box2ToBox1.m_flMatVal[0][2]);
  if ( COERCE_UNSIGNED_INT(fabs(box2Origin.x) + tolerance) > COERCE_UNSIGNED_INT(
                                                               (float)((float)((float)(v11 * x) + (float)(v12 * y))
                                                                     + (float)(v13 * z))
                                                             + v24) )
  {
    pPlane->normal.x = worldToBox1->m_flMatVal[0][0];
    pPlane->normal.y = worldToBox1->m_flMatVal[0][1];
    pPlane->normal.z = worldToBox1->m_flMatVal[0][2];
    return 1;
  }
  box1Sizea = box1Size->y;
  v25 = (float)((float)((float)(absBox2ToBox1.m_flMatVal[1][0] * v22) + (float)(absBox2ToBox1.m_flMatVal[1][1] * v21))
              + (float)(absBox2ToBox1.m_flMatVal[1][2] * z))
      + box1Sizea;
  if ( COERCE_UNSIGNED_INT(fabs(box2Origin.y) + tolerance) > LODWORD(v25) )
  {
    pPlane->normal = *(Vector *)&worldToBox1->m_flMatVal[1][0];
    return 1;
  }
  v25 = fabs(box2Origin.z) + tolerance;
  tolerancea = box1Size->z;
  *(float *)&v26 = (float)((float)((float)(absBox2ToBox1.m_flMatVal[2][0] * v22)
                                 + (float)(absBox2ToBox1.m_flMatVal[2][1] * v21))
                         + (float)(absBox2ToBox1.m_flMatVal[2][2] * z))
                 + tolerancea;
  if ( COERCE_UNSIGNED_INT(fabs(box2Origin.z) + tolerance) > v26 )
  {
    pPlane->normal = *(Vector *)&worldToBox1->m_flMatVal[2][0];
    return 1;
  }
  *(float *)&v26 = fabs(
                     (float)((float)(box2ToBox1.m_flMatVal[1][0] * box2Origin.y)
                           + (float)(box2ToBox1.m_flMatVal[0][0] * box2Origin.x))
                   + (float)(box2ToBox1.m_flMatVal[2][0] * box2Origin.z))
                 + tolerance;
  v25 = (float)((float)((float)(absBox2ToBox1.m_flMatVal[1][0] * box1Sizea) + (float)(v11 * v24))
              + (float)(absBox2ToBox1.m_flMatVal[2][0] * tolerancea))
      + v22;
  if ( v26 > LODWORD(v25) )
  {
    MatrixGetColumn(in: box2ToWorld, column: 0, out: &pPlane->normal);
    return 1;
  }
  *(float *)&v26 = fabs(
                     (float)((float)(box2ToBox1.m_flMatVal[1][1] * box2Origin.y)
                           + (float)(box2ToBox1.m_flMatVal[0][1] * box2Origin.x))
                   + (float)(box2ToBox1.m_flMatVal[2][1] * box2Origin.z))
                 + tolerance;
  v25 = (float)((float)((float)(absBox2ToBox1.m_flMatVal[1][1] * box1Sizea) + (float)(v12 * v24))
              + (float)(absBox2ToBox1.m_flMatVal[2][1] * tolerancea))
      + v21;
  if ( v26 > LODWORD(v25) )
  {
    MatrixGetColumn(in: box2ToWorld, column: 1, out: &pPlane->normal);
    return 1;
  }
  *(float *)&v26 = fabs(
                     (float)((float)(box2ToBox1.m_flMatVal[1][2] * box2Origin.y)
                           + (float)(box2ToBox1.m_flMatVal[0][2] * box2Origin.x))
                   + (float)(box2ToBox1.m_flMatVal[2][2] * box2Origin.z))
                 + tolerance;
  v25 = (float)((float)((float)(absBox2ToBox1.m_flMatVal[1][2] * box1Sizea) + (float)(v13 * v24))
              + (float)(absBox2ToBox1.m_flMatVal[2][2] * tolerancea))
      + z;
  if ( v26 > LODWORD(v25) )
  {
    MatrixGetColumn(in: box2ToWorld, column: 2, out: &pPlane->normal);
    return 1;
  }
  if ( v11 < 0.99900001 )
  {
    *(float *)&v26 = fabs(
                       (float)(box2ToBox1.m_flMatVal[1][0] * box2Origin.z)
                     - (float)(box2ToBox1.m_flMatVal[2][0] * box2Origin.y))
                   + tolerance;
    v25 = (float)((float)((float)(absBox2ToBox1.m_flMatVal[1][0] * tolerancea)
                        + (float)(absBox2ToBox1.m_flMatVal[2][0] * box1Sizea))
                + (float)(v13 * v21))
        + (float)(v12 * z);
    if ( v26 > LODWORD(v25) )
    {
      MatrixGetColumn(in: box2ToWorld, column: 0, out: &tmp);
      CrossProduct(v1: (const float *)worldToBox1, v2: &tmp.x, cross: &pPlane->normal.x);
      return 1;
    }
  }
  if ( v12 < 0.99900001 )
  {
    *(float *)&v26 = fabs(
                       (float)(box2ToBox1.m_flMatVal[1][1] * box2Origin.z)
                     - (float)(box2ToBox1.m_flMatVal[2][1] * box2Origin.y))
                   + tolerance;
    v25 = (float)((float)((float)(absBox2ToBox1.m_flMatVal[1][1] * tolerancea)
                        + (float)(absBox2ToBox1.m_flMatVal[2][1] * box1Sizea))
                + (float)(v13 * v22))
        + (float)(v11 * z);
    if ( v26 > LODWORD(v25) )
    {
      MatrixGetColumn(in: box2ToWorld, column: 1, out: &tmp);
      CrossProduct(v1: (const float *)worldToBox1, v2: &tmp.x, cross: &pPlane->normal.x);
      return 1;
    }
  }
  if ( v13 < 0.99900001 )
  {
    *(float *)&v26 = fabs(
                       (float)(box2ToBox1.m_flMatVal[1][2] * box2Origin.z)
                     - (float)(box2ToBox1.m_flMatVal[2][2] * box2Origin.y))
                   + tolerance;
    v25 = (float)((float)((float)(absBox2ToBox1.m_flMatVal[1][2] * tolerancea)
                        + (float)(absBox2ToBox1.m_flMatVal[2][2] * box1Sizea))
                + (float)(v12 * v22))
        + (float)(v11 * v21);
    if ( v26 > LODWORD(v25) )
    {
      MatrixGetColumn(in: box2ToWorld, column: 2, out: &tmp);
      CrossProduct(v1: (const float *)worldToBox1, v2: &tmp.x, cross: &pPlane->normal.x);
      return 1;
    }
  }
  if ( absBox2ToBox1.m_flMatVal[1][0] < 0.99900001 )
  {
    *(float *)&v26 = fabs(
                       (float)(box2ToBox1.m_flMatVal[2][0] * box2Origin.x)
                     - (float)(box2ToBox1.m_flMatVal[0][0] * box2Origin.z))
                   + tolerance;
    v25 = (float)((float)((float)(v11 * tolerancea) + (float)(absBox2ToBox1.m_flMatVal[2][0] * v24))
                + (float)(absBox2ToBox1.m_flMatVal[1][2] * v21))
        + (float)(absBox2ToBox1.m_flMatVal[1][1] * z);
    if ( v26 > LODWORD(v25) )
    {
      MatrixGetColumn(in: box2ToWorld, column: 0, out: &tmp);
      v15 = worldToBox1->m_flMatVal[1];
LABEL_25:
      CrossProduct(v1: v15, v2: &tmp.x, cross: &pPlane->normal.x);
      return 1;
    }
  }
  if ( absBox2ToBox1.m_flMatVal[1][1] >= 0.99900001
    || (*(float *)&v26 = fabs(
                           (float)(box2ToBox1.m_flMatVal[2][1] * box2Origin.x)
                         - (float)(box2ToBox1.m_flMatVal[0][1] * box2Origin.z))
                       + tolerance,
        v25 = (float)((float)((float)(v12 * tolerancea) + (float)(absBox2ToBox1.m_flMatVal[2][1] * v24))
                    + (float)(absBox2ToBox1.m_flMatVal[1][2] * v22))
            + (float)(absBox2ToBox1.m_flMatVal[1][0] * z),
        v26 <= LODWORD(v25)) )
  {
    if ( absBox2ToBox1.m_flMatVal[1][2] >= 0.99900001
      || (*(float *)&v26 = fabs(
                             (float)(box2ToBox1.m_flMatVal[2][2] * box2Origin.x)
                           - (float)(box2ToBox1.m_flMatVal[0][2] * box2Origin.z))
                         + tolerance,
          v26 <= COERCE_UNSIGNED_INT(
                   (float)((float)((float)(v13 * tolerancea) + (float)(absBox2ToBox1.m_flMatVal[2][2] * v24))
                         + (float)(absBox2ToBox1.m_flMatVal[1][1] * v22))
                 + (float)(absBox2ToBox1.m_flMatVal[1][0] * v21))) )
    {
      v16 = absBox2ToBox1.m_flMatVal[2][0];
      if ( absBox2ToBox1.m_flMatVal[2][0] >= 0.99900001 )
      {
        v17 = absBox2ToBox1.m_flMatVal[2][1];
      }
      else
      {
        v17 = absBox2ToBox1.m_flMatVal[2][1];
        *(float *)&v26 = (float)((float)((float)(v11 * box1Sizea) + (float)(absBox2ToBox1.m_flMatVal[1][0] * v24))
                               + (float)(absBox2ToBox1.m_flMatVal[2][2] * v21))
                       + (float)(absBox2ToBox1.m_flMatVal[2][1] * z);
        if ( COERCE_UNSIGNED_INT(
               fabs(
                 (float)(box2ToBox1.m_flMatVal[0][0] * box2Origin.y)
               - (float)(box2ToBox1.m_flMatVal[1][0] * box2Origin.x))
             + tolerance) > v26 )
        {
          MatrixGetColumn(in: box2ToWorld, column: 0, out: &tmp);
          v15 = worldToBox1->m_flMatVal[2];
          goto LABEL_25;
        }
        v16 = absBox2ToBox1.m_flMatVal[2][0];
      }
      if ( v17 < 0.99900001 )
      {
        if ( COERCE_UNSIGNED_INT(
               fabs(
                 (float)(box2ToBox1.m_flMatVal[0][1] * box2Origin.y)
               - (float)(box2ToBox1.m_flMatVal[1][1] * box2Origin.x))
             + tolerance) > COERCE_UNSIGNED_INT(
                              (float)((float)((float)(v12 * box1Sizea) + (float)(absBox2ToBox1.m_flMatVal[1][1] * v24))
                                    + (float)(absBox2ToBox1.m_flMatVal[2][2] * v22))
                            + (float)(v16 * z)) )
        {
          MatrixGetColumn(in: box2ToWorld, column: 1, out: &tmp);
          v15 = worldToBox1->m_flMatVal[2];
          goto LABEL_25;
        }
        v17 = absBox2ToBox1.m_flMatVal[2][1];
      }
      if ( absBox2ToBox1.m_flMatVal[2][2] < 0.99900001
        && COERCE_UNSIGNED_INT(
             fabs((float)(box2ToBox1.m_flMatVal[0][2] * box2Origin.y) - (float)(box2ToBox1.m_flMatVal[1][2]
                                                                              * box2Origin.x))
           + tolerance) > COERCE_UNSIGNED_INT(
                            (float)((float)((float)(v13 * box1Sizea) + (float)(absBox2ToBox1.m_flMatVal[1][2] * v24))
                                  + (float)(v17 * v22))
                          + (float)(v16 * v21)) )
      {
        MatrixGetColumn(in: box2ToWorld, column: 2, out: &tmp);
        v15 = worldToBox1->m_flMatVal[2];
        goto LABEL_25;
      }
      return 0;
    }
    else
    {
      MatrixGetColumn(in: box2ToWorld, column: 2, out: &tmp);
      CrossProduct(v1: worldToBox1->m_flMatVal[1], v2: &tmp.x, cross: &pPlane->normal.x);
      return 1;
    }
  }
  else
  {
    MatrixGetColumn(in: box2ToWorld, column: 1, out: &tmp);
    CrossProduct(v1: worldToBox1->m_flMatVal[1], v2: &tmp.x, cross: &pPlane->normal.x);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C3310
// Name: bool ComputeSeparatingPlane(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,float,struct cplane_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ComputeSeparatingPlane(
        const Vector *org1,
        const QAngle *angles1,
        const Vector *min1,
        const Vector *max1,
        const Vector *org2,
        const QAngle *angles2,
        const Vector *min2,
        const Vector *max2,
        float tolerance,
        cplane_t *pPlane)
{
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm4_4
  float v17; // xmm5_4
  float v18; // xmm6_4
  matrix3x4_t worldToBox1; // [esp+10h] [ebp-78h] BYREF
  matrix3x4_t box2ToWorld; // [esp+40h] [ebp-48h] BYREF
  Vector box2Size; // [esp+70h] [ebp-18h] BYREF
  Vector box1Size; // [esp+7Ch] [ebp-Ch] BYREF

  v10 = (float)(max1->y + min1->y) * -0.5;
  v11 = (float)(max1->z + min1->z) * -0.5;
  box1Size.x = (float)(max1->x + min1->x) * -0.5;
  box1Size.y = v10;
  box1Size.z = v11;
  AngleIMatrix(angles: angles1, matrix: &worldToBox1);
  VectorRotate(in1: &org1->x, in2: &worldToBox1, out: &box2Size.x);
  box1Size.x = box1Size.x - box2Size.x;
  box1Size.y = box1Size.y - box2Size.y;
  box1Size.z = box1Size.z - box2Size.z;
  MatrixSetColumn(in: &box1Size, column: 3, out: &worldToBox1);
  v12 = (float)(max2->y + min2->y) * 0.5;
  v13 = (float)(max2->z + min2->z) * 0.5;
  box2Size.x = (float)(min2->x + max2->x) * 0.5;
  box2Size.y = v12;
  box2Size.z = v13;
  AngleMatrix(angles: angles2, matrix: &box2ToWorld);
  VectorRotate(in1: &box2Size.x, in2: &box2ToWorld, out: &box1Size.x);
  box1Size.x = org2->x + box1Size.x;
  box1Size.y = org2->y + box1Size.y;
  box1Size.z = org2->z + box1Size.z;
  MatrixSetColumn(in: &box1Size, column: 3, out: &box2ToWorld);
  v14 = (float)(max1->y - min1->y) * 0.5;
  v15 = (float)(max1->z - min1->z) * 0.5;
  v16 = (float)(max2->x - min2->x) * 0.5;
  v17 = (float)(max2->y - min2->y) * 0.5;
  v18 = (float)(max2->z - min2->z) * 0.5;
  box1Size.x = (float)(max1->x - min1->x) * 0.5;
  box1Size.y = v14;
  box1Size.z = v15;
  box2Size.x = v16;
  box2Size.y = v17;
  box2Size.z = v18;
  return ComputeSeparatingPlane(&worldToBox1, pPlane, &box2ToWorld, &box1Size, &box2Size, tolerance);
}

//------------------------------------------------------------------------------
// Address: 0x100C3510
// Name: bool IsBoxIntersectingRay(union __m128 const __near &,union __m128 const __near &,struct Ray_t const __near &,union __m128 const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
bool __userpurge IsBoxIntersectingRay@<al>(
        const __m128 *boxMin@<ecx>,
        const __m128 *boxMax@<edx>,
        int a3@<ebp>,
        const Ray_t *ray,
        const __m128 *fl4Tolerance)
{
  bool v5; // zf
  VectorAligned m_Extents; // xmm0
  __m128 v7; // xmm1
  __m128 v8; // xmm0
  __m128 v9; // xmm3
  __m128 v10; // xmm0
  __m128 v11; // xmm2
  __m128 v13; // xmm1
  __m128 v14; // xmm0
  _BYTE v15[88]; // [esp-Ch] [ebp-5Ch] OVERLAPPED BYREF
  _UNKNOWN *retaddr; // [esp+50h] [ebp+0h]

  *(_DWORD *)&v15[80] = a3;
  *(_DWORD *)&v15[84] = retaddr;
  v5 = !ray->m_IsSwept;
  m_Extents = ray->m_Extents;
  v7 = _mm_and_ps((__m128)ray->m_Start, *(__m128 *)g_SIMD_clear_wmask);
  *(__m128 *)&v15[48] = v7;
  v8 = _mm_and_ps((__m128)m_Extents, *(__m128 *)g_SIMD_clear_wmask);
  if ( v5 )
  {
    v9 = _mm_add_ps(_mm_sub_ps(v7, v8), *fl4Tolerance);
    v10 = _mm_add_ps(_mm_add_ps(v8, v7), *fl4Tolerance);
    *(__m128 *)&v15[64] = *boxMin;
    v11 = *boxMax;
    *(__m128 *)&v15[48] = v10;
    *(__m128 *)&v15[16] = v11;
    *(__m128 *)&v15[32] = v9;
    return *(float *)&v15[64] <= v10.m128_f32[0]
        && *(float *)&v15[32] <= *(float *)&v15[16]
        && *(float *)&v15[68] <= *(float *)&v15[52]
        && *(float *)&v15[36] <= *(float *)&v15[20]
        && *(float *)&v15[72] <= *(float *)&v15[56]
        && *(float *)&v15[40] <= *(float *)&v15[24];
  }
  else
  {
    v13 = _mm_and_ps((__m128)ray->m_Delta, *(__m128 *)g_SIMD_clear_wmask);
    *(__m128 *)v15 = _mm_sub_ps(*boxMin, v8);
    *(__m128 *)&v15[64] = _mm_add_ps(*boxMax, v8);
    v14 = _mm_rcp_ps(v13);
    *(__m128 *)&v15[32] = v13;
    *(__m128 *)&v15[16] = _mm_sub_ps(_mm_add_ps(v14, v14), _mm_mul_ps(_mm_mul_ps(v14, v14), v13));
    return IsBoxIntersectingRay(
             inBoxMin: (const __m128 *)v15,
             inBoxMax: (const __m128 *)&v15[64],
             origin: (const __m128 *)&v15[48],
             delta: (const __m128 *)&v15[32],
             invDelta: (const __m128 *)&v15[16],
             vTolerance: fl4Tolerance);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C3630
// Name: bool IntersectRayWithOBB(class Vector const __near &,class Vector const __near &,struct matrix3x4_t const __near &,class Vector const __near &,class Vector const __near &,float,class CBaseTrace __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IntersectRayWithOBB(
        const Vector *vecRayStart,
        const Vector *vecRayDelta,
        const matrix3x4_t *matOBBToWorld,
        const Vector *vecOBBMins,
        const Vector *vecOBBMaxs,
        float flTolerance,
        CBaseTrace *pTrace)
{
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v11; // xmm1_4
  float x; // xmm2_4
  float y; // xmm7_4
  float z; // xmm3_4
  float v15; // xmm6_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  float *v19; // edx
  int v20; // eax
  float v21; // xmm3_4
  float v22; // xmm0_4
  float v23; // xmm4_4
  float v24; // xmm1_4
  float v25; // xmm7_4
  float v26; // xmm0_4
  float v27; // xmm3_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm3_4
  float v31; // xmm0_4
  float v32; // xmm4_4
  float v33; // xmm2_4
  float v34; // xmm3_4
  float v35; // xmm1_4
  float v36; // xmm4_4
  int type; // eax
  float v38; // xmm0_4
  double v39; // st7
  float v40; // xmm0_4
  Vector start; // [esp+18h] [ebp-60h] BYREF
  Vector vecTemp; // [esp+24h] [ebp-54h] BYREF
  Vector vecBoxCenter; // [esp+30h] [ebp-48h] BYREF
  float v45; // [esp+3Ch] [ebp-3Ch]
  float v46; // [esp+40h] [ebp-38h]
  Vector uextent; // [esp+48h] [ebp-30h]
  Vector extent; // [esp+54h] [ebp-24h] BYREF
  Vector segmentCenter; // [esp+60h] [ebp-18h]
  Vector vecBoxExtents; // [esp+6Ch] [ebp-Ch] BYREF
  const Vector *vecRayStarta; // [esp+80h] [ebp+8h]
  const Vector *vecRayDeltaa; // [esp+84h] [ebp+Ch]

  pTrace->startpos = *vecRayStart;
  pTrace->endpos = *vecRayStart;
  pTrace->endpos.x = vecRayDelta->x + pTrace->endpos.x;
  pTrace->endpos.y = vecRayDelta->y + pTrace->endpos.y;
  pTrace->endpos.z = pTrace->endpos.z + vecRayDelta->z;
  pTrace->fraction = 1.0;
  *(_WORD *)&pTrace->allsolid = 0;
  pTrace->contents = 0;
  v8 = (float)(vecOBBMins->y + vecOBBMaxs->y) * 0.5;
  v9 = (float)(vecOBBMins->z + vecOBBMaxs->z) * 0.5;
  vecBoxExtents.x = (float)(vecOBBMins->x + vecOBBMaxs->x) * 0.5;
  vecBoxExtents.y = v8;
  vecBoxExtents.z = v9;
  VectorTransform(in1: &vecBoxExtents.x, in2: matOBBToWorld, out: &vecBoxCenter.x);
  v11 = vecOBBMaxs->y - vecBoxExtents.y;
  x = vecRayDelta->x;
  y = vecRayDelta->y;
  z = vecRayDelta->z;
  v15 = vecOBBMaxs->z - vecBoxExtents.z;
  v45 = vecOBBMaxs->x - vecBoxExtents.x;
  vecBoxExtents.x = v45;
  v16 = vecRayStart->x;
  v46 = v11;
  vecBoxExtents.y = v11;
  v17 = (float)(vecRayStart->y + y) - vecBoxCenter.y;
  *(float *)&vecRayStarta = z;
  v18 = z + vecRayStart->z;
  vecBoxExtents.z = v15;
  vecRayDeltaa = (const Vector *)LODWORD(y);
  segmentCenter.x = (float)(v16 + x) - vecBoxCenter.x;
  v19 = matOBBToWorld->m_flMatVal[2];
  segmentCenter.y = v17;
  segmentCenter.z = v18 - vecBoxCenter.z;
  memset((void *)&extent, 0, sizeof(extent));
  v20 = 0;
  while ( 1 )
  {
    v21 = *(v19 - 4);
    v22 = *(v19 - 8);
    v23 = *v19 * segmentCenter.z;
    v24 = (float)((float)(x * v22) + (float)(y * v21)) + (float)(*(float *)&vecRayStarta * *v19);
    v25 = segmentCenter.y;
    v26 = (float)(v22 * segmentCenter.x) + (float)(v21 * segmentCenter.y);
    v27 = *(float *)((char *)&vecBoxExtents.x + v20);
    *(float *)((char *)&extent.x + v20) = v24;
    v28 = fabs(v24);
    *(float *)((char *)&uextent.x + v20) = v28;
    if ( fabs(v26 + v23) > (float)(v27 + v28) )
      break;
    v20 += 4;
    ++v19;
    if ( v20 >= 12 )
    {
      v29 = vecRayDelta->y;
      v30 = v29 * segmentCenter.x;
      v31 = (float)(v29 * segmentCenter.z) - (float)(vecRayDelta->z * v25);
      v32 = x * segmentCenter.z;
      v33 = (float)(x * v25) - v30;
      v34 = matOBBToWorld->m_flMatVal[1][0];
      v35 = (float)(vecRayDelta->z * segmentCenter.x) - v32;
      v36 = matOBBToWorld->m_flMatVal[0][0];
      segmentCenter.z = v33;
      if ( fabs((float)((float)(v34 * v35) + (float)(v36 * v31)) + (float)(v33 * matOBBToWorld->m_flMatVal[2][0])) <= (float)((float)(uextent.y * v15) + (float)(uextent.z * v46))
        && fabs(
             (float)((float)(matOBBToWorld->m_flMatVal[1][1] * v35) + (float)(matOBBToWorld->m_flMatVal[0][1] * v31))
           + (float)(matOBBToWorld->m_flMatVal[2][1] * segmentCenter.z)) <= (float)((float)(uextent.x * v15)
                                                                                  + (float)(uextent.z * v45))
        && fabs(
             (float)((float)(matOBBToWorld->m_flMatVal[1][2] * v35) + (float)(matOBBToWorld->m_flMatVal[0][2] * v31))
           + (float)(matOBBToWorld->m_flMatVal[2][2] * segmentCenter.z)) <= (float)((float)(uextent.x * v46)
                                                                                  + (float)(uextent.y * v45)) )
      {
        VectorITransform(in1: &vecRayStart->x, in2: matOBBToWorld, out: &start.x);
        extent.x = extent.x * 2.0;
        extent.y = extent.y * 2.0;
        extent.z = extent.z * 2.0;
        if ( IntersectRayWithBox(
               vecRayStart: &start,
               vecRayDelta: &extent,
               boxMins: vecOBBMins,
               boxMaxs: vecOBBMaxs,
               flTolerance,
               pTrace,
               pFractionLeftSolid: nullptr) != 0 )
        {
          VectorTransform(in1: &pTrace->endpos.x, in2: matOBBToWorld, out: &vecTemp.x);
          pTrace->endpos = vecTemp;
          type = pTrace->plane.type;
          pTrace->startpos.x = vecRayStart->x;
          v38 = pTrace->fraction * 2.0;
          pTrace->startpos.y = vecRayStart->y;
          v39 = vecRayStart->z;
          pTrace->fraction = v38;
          pTrace->startpos.z = v39;
          v40 = *(&pTrace->plane.normal.x + type);
          pTrace->plane.normal.x = matOBBToWorld->m_flMatVal[0][type] * v40;
          pTrace->plane.normal.y = matOBBToWorld->m_flMatVal[1][pTrace->plane.type] * v40;
          pTrace->plane.normal.z = matOBBToWorld->m_flMatVal[2][pTrace->plane.type] * v40;
          pTrace->plane.dist = (float)((float)(pTrace->plane.normal.y * pTrace->endpos.y)
                                     + (float)(pTrace->plane.normal.x * pTrace->endpos.x))
                             + (float)(pTrace->plane.normal.z * pTrace->endpos.z);
          pTrace->plane.type = 3;
          return 1;
        }
      }
      return 0;
    }
    y = *(float *)&vecRayDeltaa;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100C3A90
// Name: bool IntersectRayWithOBB(struct Ray_t const __near &,struct matrix3x4_t const __near &,class Vector const __near &,class Vector const __near &,float,class CBaseTrace __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __usercall IntersectRayWithOBB@<al>(
        int a1@<ebp>,
        const Ray_t *ray,
        const matrix3x4_t *matOBBToWorld,
        const Vector *vecOBBMins,
        const Vector *vecOBBMaxs,
        float flTolerance,
        CBaseTrace *pTrace)
{
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float y; // xmm5_4
  float z; // xmm6_4
  float v13; // xmm7_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm5_4
  float v18; // xmm2_4
  float v19; // xmm6_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm7_4
  float v23; // xmm0_4
  __int128 v24; // xmm1
  float x; // xmm4_4
  __int128 v26; // xmm1
  float v27; // xmm5_4
  float v28; // xmm4_4
  float v29; // xmm6_4
  float v30; // xmm3_4
  float v31; // xmm0_4
  float v32; // xmm2_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm2_4
  const Vector *v36; // ecx
  float v37; // xmm0_4
  float *v38; // eax
  float *p_y; // esi
  unsigned int v40; // edi
  _DWORD *v41; // edx
  float v42; // xmm1_4
  float v43; // xmm0_4
  float v44; // edx
  float *v45; // eax
  float v46; // xmm1_4
  int v47; // xmm0_4
  float v48; // xmm4_4
  float v49; // xmm5_4
  int v50; // eax
  int v51; // ecx
  int v52; // xmm6_4
  float v53; // xmm3_4
  float v54; // xmm0_4
  float *v55; // eax
  int v56; // ecx
  float v57; // xmm1_4
  float *v58; // edx
  float v59; // xmm1_4
  int v60; // ecx
  float v61; // xmm1_4
  float v62; // xmm7_4
  float v63; // xmm1_4
  float v64; // xmm7_4
  float v65; // xmm1_4
  float v66; // xmm1_4
  int v67; // ecx
  float v68; // xmm6_4
  float v69; // xmm1_4
  float *v70; // edx
  float v71; // xmm1_4
  int v72; // ecx
  float v73; // xmm6_4
  float v74; // xmm1_4
  float v75; // xmm1_4
  float v76; // xmm6_4
  float v77; // xmm1_4
  float v78; // xmm3_4
  int v79; // ecx
  float *v80; // eax
  float v81; // xmm1_4
  float v82; // xmm1_4
  int v83; // ecx
  float v84; // xmm3_4
  float v85; // xmm1_4
  float *v86; // edx
  float v87; // ecx
  float v88; // xmm1_4
  float v89; // xmm3_4
  float v90; // xmm7_4
  float v91; // xmm1_4
  int v92; // edi
  float v93; // eax
  int v94; // esi
  float v95; // xmm1_4
  float v96; // xmm2_4
  float v97; // xmm3_4
  float v98; // xmm4_4
  float v99; // xmm3_4
  float v100; // edx
  float v101; // xmm1_4
  float v102; // xmm3_4
  float v103; // xmm2_4
  float v104; // xmm1_4
  int v105; // xmm1_4
  float v106; // xmm1_4
  int v107; // xmm1_4
  VectorAligned *v108; // edx
  float v109; // eax
  float v110; // xmm0_4
  float v111; // xmm1_4
  float v112; // xmm2_4
  float v113; // xmm0_4
  float v114; // xmm3_4
  bool v115; // al
  double v116; // st7
  _BYTE v117[8]; // [esp+18h] [ebp-1DCh] BYREF
  int v118; // [esp+20h] [ebp-1D4h] BYREF
  Vector pPlaneNormal[15]; // [esp+24h] [ebp-1D0h] BYREF
  _BYTE ppPlaneDist_12[112]; // [esp+E8h] [ebp-10Ch] OVERLAPPED BYREF
  Vector vecLocalRayDirection; // [esp+158h] [ebp-9Ch]
  float v122; // [esp+164h] [ebp-90h]
  int v123; // [esp+168h] [ebp-8Ch]
  float v124[3]; // [esp+16Ch] [ebp-88h] BYREF
  _BYTE temp[32]; // [esp+178h] [ebp-7Ch] OVERLAPPED BYREF
  Vector vecLocalRayEnd; // [esp+198h] [ebp-5Ch] BYREF
  float v127; // [esp+1A4h] [ebp-50h]
  const float *pMatRow0; // [esp+1A8h] [ebp-4Ch]
  float v129; // [esp+1ACh] [ebp-48h]
  float v130; // [esp+1B0h] [ebp-44h]
  float v131; // [esp+1B4h] [ebp-40h]
  VectorAligned *p_m_Delta; // [esp+1B8h] [ebp-3Ch]
  float *v133; // [esp+1BCh] [ebp-38h]
  const Vector *v134; // [esp+1C0h] [ebp-34h]
  float *v135; // [esp+1C4h] [ebp-30h]
  const float *pMatRow1; // [esp+1C8h] [ebp-2Ch]
  float v137; // [esp+1CCh] [ebp-28h] BYREF
  float v138; // [esp+1D0h] [ebp-24h]
  float v139; // [esp+1D4h] [ebp-20h]
  Vector vecOBBCenter; // [esp+1D8h] [ebp-1Ch]
  int hitside; // [esp+1E4h] [ebp-10h]
  int v142; // [esp+1E8h] [ebp-Ch]
  float leavefrac; // [esp+1ECh] [ebp-8h]
  float retaddr; // [esp+1F4h] [ebp+0h]

  v142 = a1;
  leavefrac = retaddr;
  if ( ray->m_IsRay )
    return IntersectRayWithOBB(
             vecRayStart: &ray->m_Start,
             vecRayDelta: &ray->m_Delta,
             matOBBToWorld,
             vecOBBMins,
             vecOBBMaxs,
             flTolerance,
             pTrace);
  v8 = ray->m_StartOffset.y + ray->m_Start.y;
  v9 = ray->m_Start.x + ray->m_StartOffset.x;
  v10 = ray->m_StartOffset.z + ray->m_Start.z;
  pTrace->startpos.y = v8;
  pTrace->startpos.x = v9;
  pTrace->startpos.z = v10;
  pTrace->endpos.y = v8;
  pTrace->endpos.x = v9;
  pTrace->endpos.z = v10;
  pTrace->endpos.x = v9 + ray->m_Delta.x;
  pTrace->endpos.y = ray->m_Delta.y + pTrace->endpos.y;
  pTrace->endpos.z = ray->m_Delta.z + pTrace->endpos.z;
  pTrace->fraction = 1.0;
  *(_WORD *)&pTrace->allsolid = 0;
  pTrace->contents = 0;
  y = vecOBBMaxs->y;
  z = vecOBBMaxs->z;
  v13 = matOBBToWorld->m_flMatVal[0][3];
  v14 = (float)(vecOBBMaxs->x - vecOBBMins->x) * 0.5;
  v15 = (float)(vecOBBMaxs->x + vecOBBMins->x) * 0.5;
  v16 = y + vecOBBMins->y;
  v17 = y - vecOBBMins->y;
  v18 = z + vecOBBMins->z;
  v19 = z - vecOBBMins->z;
  v139 = v18 * 0.5;
  v20 = matOBBToWorld->m_flMatVal[2][3] + (float)(v18 * 0.5);
  v21 = ray->m_Extents.y;
  v22 = v13 + v15;
  v23 = matOBBToWorld->m_flMatVal[1][3] + (float)(v16 * 0.5);
  v24 = 0;
  v138 = v23;
  v139 = v20;
  *(float *)&v24 = (float)((float)(v14 * v14) + (float)((float)(v17 * 0.5) * (float)(v17 * 0.5)))
                 + (float)((float)(v19 * 0.5) * (float)(v19 * 0.5));
  x = ray->m_Extents.x;
  *(float *)&v24 = fsqrt(*(float *)&v24);
  *(_OWORD *)&ppPlaneDist_12[96] = v24;
  v26 = 0;
  *(float *)&v26 = fsqrt((float)((float)(x * x) + (float)(v21 * v21)) + (float)(ray->m_Extents.z * ray->m_Extents.z));
  *(_OWORD *)&temp[16] = v26;
  p_m_Delta = &ray->m_Delta;
  v27 = ray->m_Start.x;
  v28 = ray->m_Delta.x;
  v29 = ray->m_Delta.y;
  v30 = (float)(*(float *)&v26 + *(float *)&ppPlaneDist_12[96]) + flTolerance;
  v31 = (float)((float)((float)(v23 - ray->m_Start.y) * v29) + (float)((float)(v22 - ray->m_Start.x) * v28))
      + (float)((float)(v20 - ray->m_Start.z) * ray->m_Delta.z);
  v32 = 0.0;
  if ( v31 > 0.0 )
  {
    vecOBBCenter.y = (float)(v29 * v29) + (float)(v28 * v28);
    vecOBBCenter.x = ray->m_Delta.z * ray->m_Delta.z;
    if ( v31 <= (float)(vecOBBCenter.y + vecOBBCenter.x) )
      v32 = v31 / (float)(vecOBBCenter.y + vecOBBCenter.x);
    else
      v32 = 1.0;
  }
  v33 = (float)((float)(v32 * v29) + ray->m_Start.y) - v138;
  v34 = v32 * v28;
  v35 = (float)((float)(v32 * ray->m_Delta.z) + ray->m_Start.z) - v139;
  if ( (float)(v30 * v30) >= (float)((float)((float)(v33 * v33)
                                           + (float)((float)((float)(v34 + v27) - v22)
                                                   * (float)((float)(v34 + v27) - v22)))
                                   + (float)(v35 * v35)) )
  {
    VectorITransform(in1: &ray->m_Start.x, in2: matOBBToWorld, out: &v137);
    VectorIRotate(in1: &p_m_Delta->x, in2: matOBBToWorld, out: (float *)&ppPlaneDist_12[100]);
    v36 = vecOBBMaxs;
    vecLocalRayDirection.y = ray->m_Extents.y;
    v122 = ray->m_Extents.x;
    vecLocalRayDirection.z = ray->m_Extents.z;
    v130 = vecOBBMaxs->z;
    pMatRow0 = (const float *)LODWORD(vecOBBMins->z);
    v127 = vecOBBMaxs->x;
    v131 = vecOBBMins->x;
    vecOBBCenter.x = vecOBBMaxs->y;
    v37 = vecOBBMins->y;
    *(float *)&hitside = COERCE_FLOAT(v117);
    pMatRow1 = &ray->m_Extents.x;
    v38 = matOBBToWorld->m_flMatVal[2];
    vecOBBCenter.y = v37;
    LODWORD(vecLocalRayDirection.x) = (char *)vecOBBMins - (char *)vecOBBMaxs;
    v134 = vecOBBMaxs;
    LODWORD(vecOBBCenter.z) = &matOBBToWorld->m_flMatVal[0][1];
    p_y = &pPlaneNormal[5].y;
    v135 = matOBBToWorld->m_flMatVal[2];
    v40 = 0;
    while ( 1 )
    {
      v41 = (_DWORD *)hitside;
      v42 = *(v38 - 4) * vecLocalRayDirection.y;
      *(p_y - 19) = 0.0;
      *(p_y - 18) = 0.0;
      *(p_y - 17) = 0.0;
      *v41 = 1065353216;
      v43 = (float)(fabs(*(v38 - 8) * v122) + fabs(v42)) + fabs(vecLocalRayDirection.z * *v38);
      v44 = vecOBBCenter.z;
      v45 = (float *)&ppPlaneDist_12[v40];
      *(v45 - 6) = *(float *)((char *)&v36->x + LODWORD(vecLocalRayDirection.x)) - v43;
      v46 = v36->x + v43;
      v129 = *(float *)(LODWORD(v44) - 4);
      *(p_y - 10) = v129;
      v47 = *(_DWORD *)LODWORD(v44);
      *(v45 - 5) = v46;
      *(_DWORD *)&temp[12] = v47;
      *((_DWORD *)p_y - 9) = v47;
      v123 = *(_DWORD *)(LODWORD(v44) + 4);
      *((_DWORD *)p_y - 8) = v123;
      ComputeSupportMap(
        vecDirection: (const Vector *)(p_y - 10),
        vecBoxMins: vecOBBMins,
        vecBoxMaxs: vecOBBMaxs,
        pDist: (float *)&ppPlaneDist_12[v40]);
      v48 = *(&ray->m_Extents.x + s_ExtIndices[v40 / 8][0]);
      v49 = *(&ray->m_Extents.x + s_ExtIndices[v40 / 8][1]);
      v50 = s_MatIndices[v40 / 8][0];
      v51 = s_MatIndices[v40 / 8][1];
      v52 = v123;
      v53 = *(float *)&temp[12];
      v54 = *pMatRow1 + *(float *)&ppPlaneDist_12[v40 + 4];
      *(float *)&ppPlaneDist_12[v40] = *(float *)&ppPlaneDist_12[v40] - *pMatRow1;
      *(float *)&ppPlaneDist_12[v40 + 4] = v54;
      v55 = matOBBToWorld->m_flMatVal[v50];
      LODWORD(vecLocalRayEnd.z) = v55;
      v133 = matOBBToWorld->m_flMatVal[v51];
      *(p_y - 1) = 0.0;
      *(_DWORD *)p_y = v52 ^ _mask__NegFloat_;
      p_y[1] = v53;
      v56 = 4 * (COERCE_FLOAT(v52 ^ _mask__NegFloat_) > 0.0);
      v57 = COERCE_FLOAT(v52 ^ _mask__NegFloat_) * vecOBBCenter.y;
      v58 = (float *)&ppPlaneDist_12[v40 + 24];
      v58[v56 / 4u] = COERCE_FLOAT(v52 ^ _mask__NegFloat_) * vecOBBCenter.x;
      v58[v56 / 0xFFFFFFFC + 1] = v57;
      v59 = p_y[1];
      v60 = v59 > 0.0;
      v61 = v59 * *(float *)&pMatRow0;
      v60 *= 4;
      *(float *)((char *)v58 + v60) = (float)(p_y[1] * v130) + *(float *)((char *)v58 + v60);
      v62 = *v133;
      *(float *)((char *)v58 - v60 + 4) = v61 + *(float *)((char *)v58 - v60 + 4);
      v63 = (float)(fabs(*v55) * v48) + (float)(fabs(v62) * v49);
      v64 = *(float *)&ppPlaneDist_12[v40 + 24] - v63;
      *(float *)&ppPlaneDist_12[v40 + 28] = v63 + *(float *)&ppPlaneDist_12[v40 + 28];
      v65 = v129;
      *((_DWORD *)p_y + 8) = v52;
      p_y[9] = 0.0;
      p_y[10] = -v65;
      v66 = p_y[8];
      *v58 = v64;
      v67 = 4 * (v66 > 0.0);
      v68 = v66 * v127;
      v69 = v66 * v131;
      v70 = (float *)&ppPlaneDist_12[v40 + 48];
      v70[v67 / 4u] = v68;
      v70[v67 / 0xFFFFFFFC + 1] = v69;
      v71 = p_y[10];
      v72 = v71 > 0.0;
      v73 = v71 * v130;
      v74 = v71 * *(float *)&pMatRow0;
      v72 *= 4;
      *(float *)((char *)v70 + v72) = v73 + *(float *)((char *)v70 + v72);
      *(float *)((char *)v70 - v72 + 4) = v74 + *(float *)((char *)v70 - v72 + 4);
      v75 = (float)(fabs(v55[1]) * v48) + (float)(fabs(v133[1]) * v49);
      *v70 = *v70 - v75;
      v76 = *(float *)&ppPlaneDist_12[v40 + 52] + v75;
      v77 = v129;
      *(float *)&ppPlaneDist_12[v40 + 52] = v76;
      v78 = -v53;
      p_y[18] = v77;
      p_y[17] = v78;
      p_y[19] = 0.0;
      v79 = 4 * (v78 > 0.0);
      v80 = (float *)&ppPlaneDist_12[v40 + 72];
      v81 = v78 * v131;
      v80[v79 / 4u] = v78 * v127;
      v80[v79 / 0xFFFFFFFC + 1] = v81;
      v82 = p_y[18];
      v83 = v82 > 0.0;
      v84 = v82 * vecOBBCenter.x;
      v85 = v82 * vecOBBCenter.y;
      v83 *= 4;
      *(float *)((char *)v80 + v83) = v84 + *(float *)((char *)v80 + v83);
      v86 = (float *)&ppPlaneDist_12[v40 + 72 - v83];
      v87 = vecLocalRayEnd.z;
      v86[1] = v85 + v86[1];
      v88 = (float)(fabs(*(float *)(LODWORD(v87) + 8)) * v48) + (float)(fabs(v133[2]) * v49);
      *v80 = *v80 - v88;
      v89 = *(float *)&ppPlaneDist_12[v40 + 76];
      ++v135;
      v134 = (const Vector *)((char *)v134 + 4);
      ++pMatRow1;
      hitside += 16;
      LODWORD(vecOBBCenter.z) += 16;
      *(float *)&ppPlaneDist_12[v40 + 76] = v89 + v88;
      v40 += 8;
      p_y += 3;
      if ( (int)v40 >= 24 )
        break;
      v38 = v135;
      v36 = v134;
    }
    v90 = *(float *)&ppPlaneDist_12[100] + v137;
    *(float *)&hitside = -1.0;
    vecOBBCenter.z = 1.0;
    *(float *)&temp[24] = *(float *)&ppPlaneDist_12[104] + v138;
    v91 = *(float *)&ppPlaneDist_12[108] + v139;
    v92 = -1;
    v93 = COERCE_FLOAT(&v118);
    vecOBBCenter.x = NAN;
    pTrace->startsolid = true;
    *(float *)&temp[28] = v91;
    v94 = 0;
    LODWORD(vecOBBCenter.y) = &v118;
LABEL_12:
    v95 = (float)((float)(v138 * *(float *)(LODWORD(v93) - 4)) + (float)(v137 * *(float *)(LODWORD(v93) - 8)))
        + (float)(v139 * *(float *)LODWORD(v93));
    v96 = (float)((float)(*(float *)&temp[24] * *(float *)(LODWORD(v93) - 4))
                + (float)(v90 * *(float *)(LODWORD(v93) - 8)))
        + (float)(*(float *)&temp[28] * *(float *)LODWORD(v93));
    v97 = *(&pPlaneNormal[14].y + 2 * v94);
    *(float *)&temp[8] = -(float)(v95 - v97);
    v98 = v96 - v97;
    v99 = *(&pPlaneNormal[14].z + 2 * v94);
    vecLocalRayEnd.y = -v98;
    *(float *)&temp[12] = v95 - v99;
    vecLocalRayEnd.z = v96 - v99;
    v100 = 0.0;
    while ( 1 )
    {
      v101 = *(float *)&temp[4 * LODWORD(v100) + 8];
      if ( v101 > 0.0 && *(&vecLocalRayEnd.y + LODWORD(v100)) > 0.0 )
        break;
      if ( v101 > 0.0 || *(&vecLocalRayEnd.y + LODWORD(v100)) > 0.0 )
      {
        if ( v101 > 0.0 )
          pTrace->startsolid = false;
        v102 = *(&vecLocalRayEnd.y + LODWORD(v100));
        v103 = 1.0 / (float)(v101 - v102);
        if ( v101 <= v102 )
        {
          v106 = (float)(v101 + flTolerance) * v103;
          if ( vecOBBCenter.z > v106 )
            vecOBBCenter.z = v106;
        }
        else
        {
          v104 = v101 - flTolerance;
          if ( v104 < 0.0 )
            v104 = 0.0;
          *(float *)&v105 = v104 * v103;
          if ( *(float *)&v105 > *(float *)&hitside )
          {
            v93 = vecOBBCenter.y;
            hitside = v105;
            v92 = v94;
            vecOBBCenter.x = v100;
          }
        }
      }
      ++LODWORD(v100);
      if ( SLODWORD(v100) >= 2 )
      {
        ++v94;
        LODWORD(v93) += 12;
        vecOBBCenter.y = v93;
        if ( v94 < 15 )
          goto LABEL_12;
        v107 = hitside;
        if ( vecOBBCenter.z <= *(float *)&hitside || *(float *)&hitside < 0.0 )
        {
          if ( !pTrace->startsolid )
            return 0;
          v115 = vecOBBCenter.z <= 0.0 || vecOBBCenter.z >= 1.0;
          v116 = pTrace->startpos.x;
          pTrace->allsolid = v115;
          pTrace->fraction = 0.0;
          pTrace->endpos.x = v116;
          pTrace->endpos.y = pTrace->startpos.y;
          pTrace->endpos.z = pTrace->startpos.z;
          pTrace->contents = 1;
          pTrace->plane.dist = pTrace->startpos.x;
          pTrace->plane.normal.x = 1.0;
          pTrace->plane.normal.y = 0.0;
          pTrace->plane.normal.z = 0.0;
          pTrace->plane.type = 0;
          return 1;
        }
        else
        {
          v108 = p_m_Delta;
          v109 = vecOBBCenter.x;
          pTrace->fraction = *(float *)&hitside;
          pTrace->endpos.x = (float)(*(float *)&v107 * v108->x) + pTrace->startpos.x;
          pTrace->endpos.y = (float)(v108->y * *(float *)&v107) + pTrace->startpos.y;
          v110 = (float)(v108->z * *(float *)&v107) + pTrace->startpos.z;
          v111 = *(float *)&v117[12 * v92 + 4];
          v112 = *((float *)&v118 + 3 * v92);
          pTrace->endpos.z = v110;
          v113 = *(float *)&v117[12 * v92];
          v114 = *(&pPlaneNormal[14].y + 2 * v92 + LODWORD(v109));
          pTrace->contents = 1;
          v124[0] = v113;
          v124[1] = v111;
          v124[2] = v112;
          *(float *)temp = v114;
          if ( v109 == 0.0 )
          {
            v124[0] = v113 * -1.0;
            v124[1] = v111 * -1.0;
            v124[2] = v112 * -1.0;
            *(float *)temp = v114 * -1.0;
          }
          temp[4] = 3;
          MatrixGetColumn(in: matOBBToWorld, column: 3, out: &vecLocalRayEnd);
          VectorIRotate(in1: &vecLocalRayEnd.x, in2: matOBBToWorld, out: (float *)&temp[20]);
          VectorIRotate(in1: v124, in2: matOBBToWorld, out: &pTrace->plane.normal.x);
          pTrace->plane.dist = (float)((float)((float)((float)(pTrace->plane.normal.x * pTrace->plane.normal.x)
                                                     + (float)(pTrace->plane.normal.y * pTrace->plane.normal.y))
                                             + (float)(pTrace->plane.normal.z * pTrace->plane.normal.z))
                                     * *(float *)temp)
                             - (float)((float)((float)(*(float *)&temp[20] * pTrace->plane.normal.x)
                                             + (float)(*(float *)&temp[24] * pTrace->plane.normal.y))
                                     + (float)(*(float *)&temp[28] * pTrace->plane.normal.z));
          return 1;
        }
      }
    }
  }
  return 0;
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x100F04F0
// Name: ComputeBoxOffset
// Source: json
//------------------------------------------------------------------------------
__m128 __usercall ComputeBoxOffset@<xmm0>(const Ray_t *ray@<eax>)
{
  __m128d v2; // xmm4
  float v3; // xmm0_4
  float v4; // xmm1_4
  double v5; // xmm1_8
  __m128 v6; // xmm1
  __m128d v7; // xmm0

  if ( ray->m_IsRay )
  {
    return (__m128)0x3A83126Fu;
  }
  else
  {
    v2 = (__m128d)0x3FF0000000000000uLL;
    v3 = (float)(fabs(ray->m_Extents.y * ray->m_Delta.y) + fabs(ray->m_Extents.x * ray->m_Delta.x))
       + fabs(ray->m_Extents.z * ray->m_Delta.z);
    v4 = ray->m_Delta.x * ray->m_Delta.x;
    if ( (float)((float)((float)(ray->m_Delta.y * ray->m_Delta.y) + v4) + (float)(ray->m_Delta.z * ray->m_Delta.z)) >= 1.0 )
      v5 = (float)((float)((float)(ray->m_Delta.y * ray->m_Delta.y) + v4) + (float)(ray->m_Delta.z * ray->m_Delta.z));
    else
      v5 = 1.0;
    v2.m128d_f64[0] = 1.0 / v5;
    v6 = _mm_cvtpd_ps(v2);
    v6.m128_f32[0] = v6.m128_f32[0] * v3;
    v7 = _mm_cvtps_pd(v6);
    v7.m128d_f64[0] = v7.m128d_f64[0] + 0.001;
    return _mm_cvtpd_ps(v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F05B0
// Name: bool IsBoxIntersectingSphere(class Vector const __near &,class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsBoxIntersectingSphere(const Vector *boxMin, const Vector *boxMax, const Vector *center, float radius)
{
  float x; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float y; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm2_4
  float z; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm2_4

  x = center->x;
  v5 = 0.0;
  if ( boxMin->x <= center->x )
  {
    if ( x <= boxMax->x )
      goto LABEL_6;
    v6 = boxMax->x - x;
  }
  else
  {
    v6 = x - boxMin->x;
  }
  v5 = v6 * v6;
LABEL_6:
  y = center->y;
  v8 = boxMin->y;
  if ( v8 <= y )
  {
    v9 = boxMax->y;
    if ( y > v9 )
      v5 = (float)((float)(v9 - y) * (float)(v9 - y)) + v5;
  }
  else
  {
    v5 = (float)((float)(y - v8) * (float)(y - v8)) + v5;
  }
  z = center->z;
  v11 = boxMin->z;
  if ( v11 <= z )
  {
    v12 = boxMax->z;
    if ( z > v12 )
      v5 = v5 + (float)((float)(v12 - z) * (float)(v12 - z));
  }
  else
  {
    v5 = v5 + (float)((float)(z - v11) * (float)(z - v11));
  }
  return (float)(radius * radius) > v5;
}

//------------------------------------------------------------------------------
// Address: 0x100F0670
// Name: bool IsPointInBox(class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsPointInBox(const Vector *pt, const Vector *boxMin, const Vector *boxMax)
{
  float y; // xmm0_4
  float z; // xmm0_4
  bool result; // al

  result = false;
  if ( pt->x <= boxMax->x && boxMin->x <= pt->x )
  {
    y = pt->y;
    if ( y <= boxMax->y && boxMin->y <= y )
    {
      z = pt->z;
      if ( z <= boxMax->z && boxMin->z <= z )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F06C0
// Name: bool IsBoxIntersectingBox(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsBoxIntersectingBox(
        const Vector *boxMin1,
        const Vector *boxMax1,
        const Vector *boxMin2,
        const Vector *boxMax2)
{
  return boxMin1->x <= boxMax2->x
      && boxMin2->x <= boxMax1->x
      && boxMin1->y <= boxMax2->y
      && boxMin2->y <= boxMax1->y
      && boxMin1->z <= boxMax2->z
      && boxMin2->z <= boxMax1->z;
}

//------------------------------------------------------------------------------
// Address: 0x100F0720
// Name: bool IsBoxIntersectingRay(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
bool __fastcall IsBoxIntersectingRay(
        const Vector *boxMin,
        const Vector *boxMax,
        const Vector *origin,
        const Vector *vecDelta,
        unsigned int flTolerance)
{
  __m128 v5; // xmm0
  __m128 v6; // xmm5
  __m128 v7; // xmm4
  __m128 v8; // xmm2
  __m128 v9; // xmm3
  __m128 v11; // xmm1
  __m128 v12; // xmm0
  __m128 v13; // xmm7
  __m128 v14; // xmm1
  __m128 v15; // xmm0
  __m128 v16; // xmm2
  __m128 v17; // xmm0
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm0
  __m128 v22; // xmm2
  __m128 v23; // [esp-Ch] [ebp-3Ch]
  __m128 startOutMins_4; // [esp+4h] [ebp-2Ch]

  v5 = _mm_shuffle_ps((__m128)flTolerance, (__m128)flTolerance, 0);
  v6 = _mm_add_ps(_mm_sub_ps(*(__m128 *)&boxMax->x, *(__m128 *)&origin->x), v5);
  v7 = _mm_sub_ps(_mm_sub_ps(*(__m128 *)&boxMin->x, *(__m128 *)&origin->x), v5);
  v8 = _mm_cmplt_ps(v6, *(__m128 *)&vecDelta->x);
  startOutMins_4 = _mm_cmplt_ps(v6, Four_Zeros);
  v9 = _mm_cmplt_ps(*(__m128 *)&vecDelta->x, v7);
  v23 = _mm_cmplt_ps(Four_Zeros, v7);
  if ( _mm_movemask_ps(_mm_and_ps(_mm_or_ps(_mm_and_ps(v8, startOutMins_4), _mm_and_ps(v9, v23)), *(__m128 *)g_SIMD_clear_wmask)) != 0 )
    return false;
  v11 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(Four_Zeros, *(__m128 *)&vecDelta->x), Four_Epsilons), *(__m128 *)&vecDelta->x);
  v12 = _mm_rcp_ps(v11);
  v13 = _mm_mul_ps(_mm_mul_ps(v12, v12), v11);
  v14 = _mm_or_ps(_mm_xor_ps(v8, startOutMins_4), _mm_xor_ps(v9, v23));
  v15 = _mm_sub_ps(_mm_add_ps(v12, v12), v13);
  v16 = _mm_mul_ps(v15, v7);
  v17 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v15, v6), v14), _mm_andnot_ps(v14, Four_FLT_MAX));
  v18 = _mm_or_ps(_mm_and_ps(v16, v14), _mm_andnot_ps(v14, Four_Negative_FLT_MAX));
  v19 = _mm_max_ps(v18, v17);
  v20 = _mm_min_ps(v18, v17);
  v21 = _mm_min_ps(_mm_min_ps(v19, _mm_shuffle_ps(v19, v19, 57)), _mm_shuffle_ps(v19, v19, 78));
  v22 = _mm_max_ps(_mm_max_ps(v20, _mm_shuffle_ps(v20, v20, 57)), _mm_shuffle_ps(v20, v20, 78));
  return _mm_movemask_ps(
           _mm_cmpeq_ps(
             _mm_cmplt_ps(
               _mm_min_ps(_mm_shuffle_ps(v21, v21, 0), Four_Ones),
               _mm_max_ps(_mm_shuffle_ps(v22, v22, 0), Four_Zeros)),
             Four_Zeros)) == 15;
}

//------------------------------------------------------------------------------
// Address: 0x100F0880
// Name: bool IntersectRayWithBox(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,struct BoxTraceInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IntersectRayWithBox(
        const Vector *vecRayStart,
        const Vector *vecRayDelta,
        const Vector *boxMins,
        const Vector *boxMaxs,
        float flTolerance,
        BoxTraceInfo_t *pTrace)
{
  const Vector *v6; // ecx
  const Vector *v7; // edi
  int v8; // esi
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm1_4

  v6 = vecRayStart;
  v7 = boxMaxs - 1;
  v8 = 0;
  pTrace->t1 = -1.0;
  pTrace->t2 = 1.0;
  pTrace->hitside = -1;
  pTrace->startsolid = true;
  do
  {
    if ( v8 < 3 )
    {
      v9 = *(float *)((char *)&v6->x + (char *)boxMins - (char *)vecRayStart) - v6->x;
      v10 = v9 - *(float *)((char *)&v6->x + (char *)vecRayDelta - (char *)vecRayStart);
    }
    else
    {
      v9 = *(float *)((char *)&v7->x + (char *)vecRayStart - (char *)boxMaxs) - v7->x;
      v10 = *(float *)((char *)&v7->x + (char *)vecRayDelta - (char *)boxMaxs) + v9;
    }
    if ( v9 > 0.0 && v10 > 0.0 )
    {
      pTrace->startsolid = false;
      return false;
    }
    if ( v9 > 0.0 || v10 > 0.0 )
    {
      if ( v9 > 0.0 )
        pTrace->startsolid = false;
      if ( v9 <= v10 )
      {
        v13 = (float)(v9 + flTolerance) / (float)(v9 - v10);
        if ( pTrace->t2 > v13 )
          pTrace->t2 = v13;
      }
      else
      {
        v11 = v9 - flTolerance;
        if ( (float)(v9 - flTolerance) < 0.0 )
          v11 = 0.0;
        v12 = v11 / (float)(v9 - v10);
        if ( v12 > pTrace->t1 )
        {
          pTrace->t1 = v12;
          pTrace->hitside = v8;
        }
      }
    }
    ++v8;
    v7 = (const Vector *)((char *)v7 + 4);
    v6 = (const Vector *)((char *)v6 + 4);
  }
  while ( v8 < 6 );
  return pTrace->startsolid || pTrace->t2 > pTrace->t1 && pTrace->t1 >= 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x100F09D0
// Name: bool IntersectRayWithBox(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,class CBaseTrace __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IntersectRayWithBox(
        const Vector *vecRayStart,
        const Vector *vecRayDelta,
        const Vector *boxMins,
        const Vector *boxMaxs,
        float flTolerance,
        CBaseTrace *pTrace,
        float *pFractionLeftSolid)
{
  bool startsolid; // al
  float t2; // xmm0_4
  float t1; // xmm2_4
  bool v10; // cc
  int hitside; // eax
  double v12; // st7
  bool v14; // al
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm3_4
  float y; // xmm1_4
  BoxTraceInfo_t trace; // [esp+14h] [ebp-10h] BYREF

  pTrace->startpos = *vecRayStart;
  pTrace->endpos = *vecRayStart;
  pTrace->endpos.x = vecRayDelta->x + pTrace->endpos.x;
  pTrace->endpos.y = pTrace->endpos.y + vecRayDelta->y;
  pTrace->endpos.z = pTrace->endpos.z + vecRayDelta->z;
  *(_WORD *)&pTrace->allsolid = 0;
  *(_QWORD *)&pTrace->fraction = 1065353216;
  if ( IntersectRayWithBox(vecRayStart, vecRayDelta, boxMins, boxMaxs, flTolerance, pTrace: &trace) )
  {
    startsolid = trace.startsolid;
    t2 = trace.t2;
    t1 = trace.t1;
    v10 = trace.t2 <= trace.t1;
    pTrace->startsolid = trace.startsolid;
    if ( !v10 && t1 >= 0.0 )
    {
      hitside = trace.hitside;
      pTrace->fraction = t1;
      pTrace->endpos.x = (float)(vecRayDelta->x * t1) + pTrace->startpos.x;
      pTrace->endpos.y = (float)(vecRayDelta->y * t1) + pTrace->startpos.y;
      pTrace->endpos.z = (float)(t1 * vecRayDelta->z) + pTrace->startpos.z;
      pTrace->contents = 1;
      pTrace->plane.normal = vec3_origin;
      if ( hitside < 3 )
      {
        LODWORD(pTrace->plane.dist) = *((_DWORD *)&boxMins->x + hitside) ^ _mask__NegFloat_;
        *((_DWORD *)&pTrace->plane.normal.x + hitside) = -1082130432;
      }
      else
      {
        v12 = *(&boxMaxs[-1].x + hitside);
        hitside -= 3;
        pTrace->plane.dist = v12;
        *((_DWORD *)&pTrace->plane.normal.x + hitside) = 1065353216;
      }
      pTrace->plane.type = hitside;
      return 1;
    }
    if ( startsolid )
    {
      v14 = t2 <= 0.0 || t2 >= 1.0;
      pTrace->allsolid = v14;
      pTrace->fraction = 0.0;
      if ( pFractionLeftSolid != nullptr )
        *pFractionLeftSolid = t2;
      pTrace->endpos = pTrace->startpos;
      pTrace->contents = 1;
      pTrace->plane.dist = pTrace->startpos.x;
      pTrace->plane.normal.y = 0.0;
      pTrace->plane.normal.z = 0.0;
      pTrace->plane.normal.x = 1.0;
      pTrace->plane.type = 0;
      v15 = vecRayDelta->x * t2;
      v16 = vecRayDelta->y * t2;
      v17 = (float)(t2 * vecRayDelta->z) + vecRayStart->z;
      v18 = vecRayStart->x + v15;
      y = vecRayStart->y;
      pTrace->startpos.x = v18;
      pTrace->startpos.y = y + v16;
      pTrace->startpos.z = v17;
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100F0C00
// Name: void ComputeSupportMap(class Vector const __near &,class Vector const __near &,class Vector const __near &,float __near * const)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeSupportMap(
        const Vector *vecDirection,
        const Vector *vecBoxMins,
        const Vector *vecBoxMaxs,
        float *pDist)
{
  unsigned int v4; // edx
  unsigned int v5; // edx
  unsigned int v6; // edx

  v4 = 4 * (vecDirection->x > 0.0);
  pDist[v4 / 4] = vecBoxMaxs->x * vecDirection->x;
  pDist[v4 / 0xFFFFFFFC + 1] = vecDirection->x * vecBoxMins->x;
  v5 = 4 * (vecDirection->y > 0.0);
  pDist[v5 / 4] = (float)(vecBoxMaxs->y * vecDirection->y) + pDist[v5 / 4];
  pDist[v5 / 0xFFFFFFFC + 1] = (float)(vecBoxMins->y * vecDirection->y) + pDist[v5 / 0xFFFFFFFC + 1];
  v6 = 4 * (vecDirection->z > 0.0);
  pDist[v6 / 4] = (float)(vecBoxMaxs->z * vecDirection->z) + pDist[v6 / 4];
  pDist[v6 / 0xFFFFFFFC + 1] = (float)(vecBoxMins->z * vecDirection->z) + pDist[v6 / 0xFFFFFFFC + 1];
}

//------------------------------------------------------------------------------
// Address: 0x100F0CE0
// Name: ComputeSeparatingPlane
// Source: json
//------------------------------------------------------------------------------
char __usercall ComputeSeparatingPlane@<al>(
        const matrix3x4_t *worldToBox1@<edi>,
        cplane_t *pPlane@<esi>,
        const matrix3x4_t *box2ToWorld,
        const Vector *box1Size,
        const Vector *box2Size,
        float tolerance)
{
  float x; // xmm6_4
  float z; // xmm7_4
  float y; // xmm5_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  const float *v15; // eax
  float v16; // xmm5_4
  float v17; // xmm6_4
  matrix3x4_t box2ToBox1; // [esp+4h] [ebp-8Ch] BYREF
  matrix3x4_t absBox2ToBox1; // [esp+34h] [ebp-5Ch]
  Vector tmp; // [esp+64h] [ebp-2Ch] BYREF
  float v21; // [esp+70h] [ebp-20h]
  float v22; // [esp+74h] [ebp-1Ch]
  Vector box2Origin; // [esp+78h] [ebp-18h] BYREF
  float v24; // [esp+84h] [ebp-Ch]
  float v25; // [esp+88h] [ebp-8h]
  unsigned int v26; // [esp+8Ch] [ebp-4h]
  float box1Sizea; // [esp+9Ch] [ebp+Ch]
  float tolerancea; // [esp+A4h] [ebp+14h]

  ConcatTransforms(in1: worldToBox1, in2: box2ToWorld, out: &box2ToBox1);
  MatrixGetColumn(in: &box2ToBox1, column: 3, out: &box2Origin);
  x = box2Size->x;
  z = box2Size->z;
  *(_QWORD *)&absBox2ToBox1.m_flMatVal[1][0] = *(_QWORD *)&box2ToBox1.m_flMatVal[1][0] & 0x7FFFFFFF7FFFFFFFLL;
  absBox2ToBox1.m_flMatVal[1][2] = fabs(box2ToBox1.m_flMatVal[1][2]);
  *(_QWORD *)&absBox2ToBox1.m_flMatVal[2][0] = *(_QWORD *)&box2ToBox1.m_flMatVal[2][0] & 0x7FFFFFFF7FFFFFFFLL;
  absBox2ToBox1.m_flMatVal[2][2] = fabs(box2ToBox1.m_flMatVal[2][2]);
  y = box2Size->y;
  v24 = box1Size->x;
  v11 = fabs(box2ToBox1.m_flMatVal[0][0]);
  v22 = x;
  v12 = fabs(box2ToBox1.m_flMatVal[0][1]);
  v21 = y;
  v13 = fabs(box2ToBox1.m_flMatVal[0][2]);
  if ( COERCE_UNSIGNED_INT(fabs(box2Origin.x) + tolerance) > COERCE_UNSIGNED_INT(
                                                               (float)((float)((float)(v11 * x) + (float)(v12 * y))
                                                                     + (float)(v13 * z))
                                                             + v24) )
  {
    pPlane->normal.x = worldToBox1->m_flMatVal[0][0];
    pPlane->normal.y = worldToBox1->m_flMatVal[0][1];
    pPlane->normal.z = worldToBox1->m_flMatVal[0][2];
    return 1;
  }
  box1Sizea = box1Size->y;
  v25 = (float)((float)((float)(absBox2ToBox1.m_flMatVal[1][0] * v22) + (float)(absBox2ToBox1.m_flMatVal[1][1] * v21))
              + (float)(absBox2ToBox1.m_flMatVal[1][2] * z))
      + box1Sizea;
  if ( COERCE_UNSIGNED_INT(fabs(box2Origin.y) + tolerance) > LODWORD(v25) )
  {
    pPlane->normal = *(Vector *)&worldToBox1->m_flMatVal[1][0];
    return 1;
  }
  v25 = fabs(box2Origin.z) + tolerance;
  tolerancea = box1Size->z;
  *(float *)&v26 = (float)((float)((float)(absBox2ToBox1.m_flMatVal[2][0] * v22)
                                 + (float)(absBox2ToBox1.m_flMatVal[2][1] * v21))
                         + (float)(absBox2ToBox1.m_flMatVal[2][2] * z))
                 + tolerancea;
  if ( COERCE_UNSIGNED_INT(fabs(box2Origin.z) + tolerance) > v26 )
  {
    pPlane->normal = *(Vector *)&worldToBox1->m_flMatVal[2][0];
    return 1;
  }
  *(float *)&v26 = fabs(
                     (float)((float)(box2ToBox1.m_flMatVal[1][0] * box2Origin.y)
                           + (float)(box2ToBox1.m_flMatVal[0][0] * box2Origin.x))
                   + (float)(box2ToBox1.m_flMatVal[2][0] * box2Origin.z))
                 + tolerance;
  v25 = (float)((float)((float)(absBox2ToBox1.m_flMatVal[1][0] * box1Sizea) + (float)(v11 * v24))
              + (float)(absBox2ToBox1.m_flMatVal[2][0] * tolerancea))
      + v22;
  if ( v26 > LODWORD(v25) )
  {
    MatrixGetColumn(in: box2ToWorld, column: 0, out: &pPlane->normal);
    return 1;
  }
  *(float *)&v26 = fabs(
                     (float)((float)(box2ToBox1.m_flMatVal[1][1] * box2Origin.y)
                           + (float)(box2ToBox1.m_flMatVal[0][1] * box2Origin.x))
                   + (float)(box2ToBox1.m_flMatVal[2][1] * box2Origin.z))
                 + tolerance;
  v25 = (float)((float)((float)(absBox2ToBox1.m_flMatVal[1][1] * box1Sizea) + (float)(v12 * v24))
              + (float)(absBox2ToBox1.m_flMatVal[2][1] * tolerancea))
      + v21;
  if ( v26 > LODWORD(v25) )
  {
    MatrixGetColumn(in: box2ToWorld, column: 1, out: &pPlane->normal);
    return 1;
  }
  *(float *)&v26 = fabs(
                     (float)((float)(box2ToBox1.m_flMatVal[1][2] * box2Origin.y)
                           + (float)(box2ToBox1.m_flMatVal[0][2] * box2Origin.x))
                   + (float)(box2ToBox1.m_flMatVal[2][2] * box2Origin.z))
                 + tolerance;
  v25 = (float)((float)((float)(absBox2ToBox1.m_flMatVal[1][2] * box1Sizea) + (float)(v13 * v24))
              + (float)(absBox2ToBox1.m_flMatVal[2][2] * tolerancea))
      + z;
  if ( v26 > LODWORD(v25) )
  {
    MatrixGetColumn(in: box2ToWorld, column: 2, out: &pPlane->normal);
    return 1;
  }
  if ( v11 < 0.99900001 )
  {
    *(float *)&v26 = fabs(
                       (float)(box2ToBox1.m_flMatVal[1][0] * box2Origin.z)
                     - (float)(box2ToBox1.m_flMatVal[2][0] * box2Origin.y))
                   + tolerance;
    v25 = (float)((float)((float)(absBox2ToBox1.m_flMatVal[1][0] * tolerancea)
                        + (float)(absBox2ToBox1.m_flMatVal[2][0] * box1Sizea))
                + (float)(v13 * v21))
        + (float)(v12 * z);
    if ( v26 > LODWORD(v25) )
    {
      MatrixGetColumn(in: box2ToWorld, column: 0, out: &tmp);
      CrossProduct(v1: (const float *)worldToBox1, v2: &tmp.x, cross: &pPlane->normal.x);
      return 1;
    }
  }
  if ( v12 < 0.99900001 )
  {
    *(float *)&v26 = fabs(
                       (float)(box2ToBox1.m_flMatVal[1][1] * box2Origin.z)
                     - (float)(box2ToBox1.m_flMatVal[2][1] * box2Origin.y))
                   + tolerance;
    v25 = (float)((float)((float)(absBox2ToBox1.m_flMatVal[1][1] * tolerancea)
                        + (float)(absBox2ToBox1.m_flMatVal[2][1] * box1Sizea))
                + (float)(v13 * v22))
        + (float)(v11 * z);
    if ( v26 > LODWORD(v25) )
    {
      MatrixGetColumn(in: box2ToWorld, column: 1, out: &tmp);
      CrossProduct(v1: (const float *)worldToBox1, v2: &tmp.x, cross: &pPlane->normal.x);
      return 1;
    }
  }
  if ( v13 < 0.99900001 )
  {
    *(float *)&v26 = fabs(
                       (float)(box2ToBox1.m_flMatVal[1][2] * box2Origin.z)
                     - (float)(box2ToBox1.m_flMatVal[2][2] * box2Origin.y))
                   + tolerance;
    v25 = (float)((float)((float)(absBox2ToBox1.m_flMatVal[1][2] * tolerancea)
                        + (float)(absBox2ToBox1.m_flMatVal[2][2] * box1Sizea))
                + (float)(v12 * v22))
        + (float)(v11 * v21);
    if ( v26 > LODWORD(v25) )
    {
      MatrixGetColumn(in: box2ToWorld, column: 2, out: &tmp);
      CrossProduct(v1: (const float *)worldToBox1, v2: &tmp.x, cross: &pPlane->normal.x);
      return 1;
    }
  }
  if ( absBox2ToBox1.m_flMatVal[1][0] < 0.99900001 )
  {
    *(float *)&v26 = fabs(
                       (float)(box2ToBox1.m_flMatVal[2][0] * box2Origin.x)
                     - (float)(box2ToBox1.m_flMatVal[0][0] * box2Origin.z))
                   + tolerance;
    v25 = (float)((float)((float)(v11 * tolerancea) + (float)(absBox2ToBox1.m_flMatVal[2][0] * v24))
                + (float)(absBox2ToBox1.m_flMatVal[1][2] * v21))
        + (float)(absBox2ToBox1.m_flMatVal[1][1] * z);
    if ( v26 > LODWORD(v25) )
    {
      MatrixGetColumn(in: box2ToWorld, column: 0, out: &tmp);
      v15 = worldToBox1->m_flMatVal[1];
LABEL_25:
      CrossProduct(v1: v15, v2: &tmp.x, cross: &pPlane->normal.x);
      return 1;
    }
  }
  if ( absBox2ToBox1.m_flMatVal[1][1] >= 0.99900001
    || (*(float *)&v26 = fabs(
                           (float)(box2ToBox1.m_flMatVal[2][1] * box2Origin.x)
                         - (float)(box2ToBox1.m_flMatVal[0][1] * box2Origin.z))
                       + tolerance,
        v25 = (float)((float)((float)(v12 * tolerancea) + (float)(absBox2ToBox1.m_flMatVal[2][1] * v24))
                    + (float)(absBox2ToBox1.m_flMatVal[1][2] * v22))
            + (float)(absBox2ToBox1.m_flMatVal[1][0] * z),
        v26 <= LODWORD(v25)) )
  {
    if ( absBox2ToBox1.m_flMatVal[1][2] >= 0.99900001
      || (*(float *)&v26 = fabs(
                             (float)(box2ToBox1.m_flMatVal[2][2] * box2Origin.x)
                           - (float)(box2ToBox1.m_flMatVal[0][2] * box2Origin.z))
                         + tolerance,
          v26 <= COERCE_UNSIGNED_INT(
                   (float)((float)((float)(v13 * tolerancea) + (float)(absBox2ToBox1.m_flMatVal[2][2] * v24))
                         + (float)(absBox2ToBox1.m_flMatVal[1][1] * v22))
                 + (float)(absBox2ToBox1.m_flMatVal[1][0] * v21))) )
    {
      v16 = absBox2ToBox1.m_flMatVal[2][0];
      if ( absBox2ToBox1.m_flMatVal[2][0] >= 0.99900001 )
      {
        v17 = absBox2ToBox1.m_flMatVal[2][1];
      }
      else
      {
        v17 = absBox2ToBox1.m_flMatVal[2][1];
        *(float *)&v26 = (float)((float)((float)(v11 * box1Sizea) + (float)(absBox2ToBox1.m_flMatVal[1][0] * v24))
                               + (float)(absBox2ToBox1.m_flMatVal[2][2] * v21))
                       + (float)(absBox2ToBox1.m_flMatVal[2][1] * z);
        if ( COERCE_UNSIGNED_INT(
               fabs(
                 (float)(box2ToBox1.m_flMatVal[0][0] * box2Origin.y)
               - (float)(box2ToBox1.m_flMatVal[1][0] * box2Origin.x))
             + tolerance) > v26 )
        {
          MatrixGetColumn(in: box2ToWorld, column: 0, out: &tmp);
          v15 = worldToBox1->m_flMatVal[2];
          goto LABEL_25;
        }
        v16 = absBox2ToBox1.m_flMatVal[2][0];
      }
      if ( v17 < 0.99900001 )
      {
        if ( COERCE_UNSIGNED_INT(
               fabs(
                 (float)(box2ToBox1.m_flMatVal[0][1] * box2Origin.y)
               - (float)(box2ToBox1.m_flMatVal[1][1] * box2Origin.x))
             + tolerance) > COERCE_UNSIGNED_INT(
                              (float)((float)((float)(v12 * box1Sizea) + (float)(absBox2ToBox1.m_flMatVal[1][1] * v24))
                                    + (float)(absBox2ToBox1.m_flMatVal[2][2] * v22))
                            + (float)(v16 * z)) )
        {
          MatrixGetColumn(in: box2ToWorld, column: 1, out: &tmp);
          v15 = worldToBox1->m_flMatVal[2];
          goto LABEL_25;
        }
        v17 = absBox2ToBox1.m_flMatVal[2][1];
      }
      if ( absBox2ToBox1.m_flMatVal[2][2] < 0.99900001
        && COERCE_UNSIGNED_INT(
             fabs((float)(box2ToBox1.m_flMatVal[0][2] * box2Origin.y) - (float)(box2ToBox1.m_flMatVal[1][2]
                                                                              * box2Origin.x))
           + tolerance) > COERCE_UNSIGNED_INT(
                            (float)((float)((float)(v13 * box1Sizea) + (float)(absBox2ToBox1.m_flMatVal[1][2] * v24))
                                  + (float)(v17 * v22))
                          + (float)(v16 * v21)) )
      {
        MatrixGetColumn(in: box2ToWorld, column: 2, out: &tmp);
        v15 = worldToBox1->m_flMatVal[2];
        goto LABEL_25;
      }
      return 0;
    }
    else
    {
      MatrixGetColumn(in: box2ToWorld, column: 2, out: &tmp);
      CrossProduct(v1: worldToBox1->m_flMatVal[1], v2: &tmp.x, cross: &pPlane->normal.x);
      return 1;
    }
  }
  else
  {
    MatrixGetColumn(in: box2ToWorld, column: 1, out: &tmp);
    CrossProduct(v1: worldToBox1->m_flMatVal[1], v2: &tmp.x, cross: &pPlane->normal.x);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F1590
// Name: bool ComputeSeparatingPlane(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,float,struct cplane_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ComputeSeparatingPlane(
        const Vector *org1,
        const QAngle *angles1,
        const Vector *min1,
        const Vector *max1,
        const Vector *org2,
        const QAngle *angles2,
        const Vector *min2,
        const Vector *max2,
        float tolerance,
        cplane_t *pPlane)
{
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm4_4
  float v17; // xmm5_4
  float v18; // xmm6_4
  matrix3x4_t worldToBox1; // [esp+10h] [ebp-78h] BYREF
  matrix3x4_t box2ToWorld; // [esp+40h] [ebp-48h] BYREF
  Vector box2Size; // [esp+70h] [ebp-18h] BYREF
  Vector box1Size; // [esp+7Ch] [ebp-Ch] BYREF

  v10 = (float)(max1->y + min1->y) * -0.5;
  v11 = (float)(max1->z + min1->z) * -0.5;
  box1Size.x = (float)(max1->x + min1->x) * -0.5;
  box1Size.y = v10;
  box1Size.z = v11;
  AngleIMatrix(angles: angles1, matrix: &worldToBox1);
  VectorRotate(in1: &org1->x, in2: &worldToBox1, out: &box2Size.x);
  box1Size.x = box1Size.x - box2Size.x;
  box1Size.y = box1Size.y - box2Size.y;
  box1Size.z = box1Size.z - box2Size.z;
  MatrixSetColumn(in: &box1Size, column: 3, out: &worldToBox1);
  v12 = (float)(max2->y + min2->y) * 0.5;
  v13 = (float)(max2->z + min2->z) * 0.5;
  box2Size.x = (float)(min2->x + max2->x) * 0.5;
  box2Size.y = v12;
  box2Size.z = v13;
  AngleMatrix(angles: angles2, matrix: &box2ToWorld);
  VectorRotate(in1: &box2Size.x, in2: &box2ToWorld, out: &box1Size.x);
  box1Size.x = org2->x + box1Size.x;
  box1Size.y = org2->y + box1Size.y;
  box1Size.z = org2->z + box1Size.z;
  MatrixSetColumn(in: &box1Size, column: 3, out: &box2ToWorld);
  v14 = (float)(max1->y - min1->y) * 0.5;
  v15 = (float)(max1->z - min1->z) * 0.5;
  v16 = (float)(max2->x - min2->x) * 0.5;
  v17 = (float)(max2->y - min2->y) * 0.5;
  v18 = (float)(max2->z - min2->z) * 0.5;
  box1Size.x = (float)(max1->x - min1->x) * 0.5;
  box1Size.y = v14;
  box1Size.z = v15;
  box2Size.x = v16;
  box2Size.y = v17;
  box2Size.z = v18;
  return ComputeSeparatingPlane(&worldToBox1, pPlane, &box2ToWorld, &box1Size, &box2Size, tolerance);
}

//------------------------------------------------------------------------------
// Address: 0x100F1790
// Name: float IntersectRayWithTriangle(struct Ray_t const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
double __cdecl IntersectRayWithTriangle(const Ray_t *ray, const Vector *v1, float v2, const Vector *v3, int oneSided)
{
  float y; // xmm0_4
  float z; // xmm5_4
  float v7; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm7_4
  float v12; // xmm5_4
  float x; // xmm2_4
  float v14; // xmm6_4
  float v15; // xmm3_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm4_4
  float v19; // xmm5_4
  float v20; // xmm7_4
  float v21; // xmm6_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm6_4
  float dirCrossEdge2_4; // [esp+4h] [ebp-20h]
  float edge2; // [esp+Ch] [ebp-18h]
  float edge2_4; // [esp+10h] [ebp-14h]
  float edge2_8; // [esp+14h] [ebp-10h]
  float edge1; // [esp+18h] [ebp-Ch]
  float edge1_4; // [esp+1Ch] [ebp-8h]
  float edge1_8; // [esp+20h] [ebp-4h]

  y = v1->y;
  z = v1->z;
  v7 = v3->x - v1->x;
  v8 = v3->y - y;
  v9 = v3->z - z;
  edge1 = *(float *)LODWORD(v2) - v1->x;
  edge1_4 = *(float *)(LODWORD(v2) + 4) - y;
  edge1_8 = *(float *)(LODWORD(v2) + 8) - z;
  edge2 = v7;
  edge2_4 = v8;
  edge2_8 = v9;
  if ( (_BYTE)oneSided != 0
    && (float)((float)((float)(ray->m_Delta.y
                             * (float)((float)((float)(*(float *)(LODWORD(v2) + 8) - z) * v7)
                                     - (float)(v9 * (float)(*(float *)LODWORD(v2) - v1->x))))
                     + (float)((float)((float)(v9 * (float)(*(float *)(LODWORD(v2) + 4) - y))
                                     - (float)(v8 * (float)(*(float *)(LODWORD(v2) + 8) - z)))
                             * ray->m_Delta.x))
             + (float)(ray->m_Delta.z
                     * (float)((float)(v8 * (float)(*(float *)LODWORD(v2) - v1->x))
                             - (float)(v7 * (float)(*(float *)(LODWORD(v2) + 4) - y))))) >= 0.0 )
  {
    return -1.0;
  }
  v10 = ray->m_Delta.y;
  v11 = v10 * v7;
  v12 = (float)(v10 * v9) - (float)(ray->m_Delta.z * v8);
  x = ray->m_Delta.x;
  dirCrossEdge2_4 = (float)(ray->m_Delta.z * v7) - (float)(x * v9);
  v14 = (float)(x * v8) - v11;
  if ( fabs((float)((float)(dirCrossEdge2_4 * edge1_4) + (float)(v12 * edge1)) + (float)(v14 * edge1_8)) < 0.000001 )
    return -1.0;
  v15 = ray->m_Start.y - v1->y;
  v16 = ray->m_Start.x - v1->x;
  *(float *)&oneSided = 1.0
                      / (float)((float)((float)(dirCrossEdge2_4 * edge1_4) + (float)(v12 * edge1))
                              + (float)(v14 * edge1_8));
  v17 = ray->m_Start.z - v1->z;
  v18 = (float)((float)((float)(v15 * dirCrossEdge2_4) + (float)(v16 * v12)) + (float)(v17 * v14)) * *(float *)&oneSided;
  if ( v18 < 0.0 )
    return -1.0;
  if ( v18 > 1.0 )
    return -1.0;
  v19 = (float)(v15 * edge1_8) - (float)(v17 * edge1_4);
  v20 = (float)(v16 * edge1_4) - (float)(v15 * edge1);
  v21 = (float)(v17 * edge1) - (float)(v16 * edge1_8);
  v22 = (float)((float)((float)(x * v19) + (float)(v21 * ray->m_Delta.y)) + (float)(v20 * ray->m_Delta.z))
      * *(float *)&oneSided;
  if ( v22 < 0.0 )
    return -1.0;
  if ( (float)(v22 + v18) > 1.0 )
    return -1.0;
  v23 = ComputeBoxOffset(ray).m128_f32[0];
  v24 = (float)((float)((float)(v21 * edge2_4) + (float)(v19 * edge2)) + (float)(v20 * edge2_8)) * *(float *)&oneSided;
  v2 = v24;
  if ( COERCE_FLOAT(LODWORD(v23) ^ _mask__NegFloat_) > v24 || v24 > (float)(v23 + 1.0) )
    return -1.0;
  oneSided = 1;
  v1 = nullptr;
  return clamp<float,int,int>(val: &v2, minVal: (const int *)&v1, maxVal: &oneSided);
}

//------------------------------------------------------------------------------
// Address: 0x100F1A40
// Name: bool IsRayIntersectingSphere(class Vector const __near &,class Vector const __near &,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsRayIntersectingSphere(
        const Vector *vecRayOrigin,
        const Vector *vecRayDelta,
        const Vector *vecCenter,
        float flRadius,
        float flTolerance)
{
  float v6; // xmm4_4
  float y; // xmm2_4
  float z; // xmm3_4
  float v9; // xmm5_4
  float v10; // xmm0_4
  float v11; // xmm6_4
  float x; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm5_4
  float v17; // [esp+0h] [ebp-8h]
  float vecRayOrigina; // [esp+10h] [ebp+8h]
  float flRadiusa; // [esp+1Ch] [ebp+14h]
  float flTolerancea; // [esp+20h] [ebp+18h]

  v6 = flRadius + flTolerance;
  y = vecRayDelta->y;
  z = vecRayDelta->z;
  v9 = vecCenter->x - vecRayOrigin->x;
  flRadiusa = vecRayOrigin->x;
  v10 = vecRayOrigin->y;
  vecRayOrigina = vecCenter->y;
  v11 = vecRayOrigina - v10;
  flTolerancea = v10;
  v17 = vecCenter->z;
  x = vecRayDelta->x;
  v13 = (float)((float)(vecRayDelta->x * v9) + (float)(y * v11)) + (float)(z * (float)(v17 - vecRayOrigin->z));
  if ( v13 > 0.0 )
  {
    v15 = (float)((float)(vecRayDelta->y * vecRayDelta->y) + (float)(x * x)) + (float)(vecRayDelta->z * vecRayDelta->z);
    if ( v13 <= v15 )
      v14 = v13 / v15;
    else
      v14 = 1.0;
  }
  else
  {
    v14 = 0.0;
  }
  return (float)(v6 * v6) >= (float)((float)((float)((float)((float)((float)(y * v14) + flTolerancea) - vecRayOrigina)
                                                   * (float)((float)((float)(y * v14) + flTolerancea) - vecRayOrigina))
                                           + (float)((float)((float)((float)(x * v14) + flRadiusa) - vecCenter->x)
                                                   * (float)((float)((float)(x * v14) + flRadiusa) - vecCenter->x)))
                                   + (float)((float)((float)((float)(z * v14) + vecRayOrigin->z) - v17)
                                           * (float)((float)((float)(z * v14) + vecRayOrigin->z) - v17)));
}

//------------------------------------------------------------------------------
// Address: 0x100F1B70
// Name: bool IsOBBIntersectingOBB(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsOBBIntersectingOBB(
        const Vector *vecOrigin1,
        const QAngle *vecAngles1,
        const Vector *boxMin1,
        const Vector *boxMax1,
        const Vector *vecOrigin2,
        const QAngle *vecAngles2,
        const Vector *boxMin2,
        const Vector *boxMax2,
        float flTolerance)
{
  cplane_t plane; // [esp+8h] [ebp-14h] BYREF

  return ComputeSeparatingPlane(
           org1: vecOrigin1,
           angles1: vecAngles1,
           min1: boxMin1,
           max1: boxMax1,
           org2: vecOrigin2,
           angles2: vecAngles2,
           min2: boxMin2,
           max2: boxMax2,
           tolerance: flTolerance,
           pPlane: &plane) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x100F1BC0
// Name: bool IntersectRayWithOBB(class Vector const __near &,class Vector const __near &,struct matrix3x4_t const __near &,class Vector const __near &,class Vector const __near &,float,class CBaseTrace __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IntersectRayWithOBB(
        const Vector *vecRayStart,
        const Vector *vecRayDelta,
        const matrix3x4_t *matOBBToWorld,
        const Vector *vecOBBMins,
        const Vector *vecOBBMaxs,
        float flTolerance,
        CBaseTrace *pTrace)
{
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v11; // xmm1_4
  float x; // xmm2_4
  float y; // xmm7_4
  float z; // xmm3_4
  float v15; // xmm6_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  float *v19; // edx
  int v20; // eax
  float v21; // xmm3_4
  float v22; // xmm0_4
  float v23; // xmm4_4
  float v24; // xmm1_4
  float v25; // xmm7_4
  float v26; // xmm0_4
  float v27; // xmm3_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm3_4
  float v31; // xmm0_4
  float v32; // xmm4_4
  float v33; // xmm2_4
  float v34; // xmm3_4
  float v35; // xmm1_4
  float v36; // xmm4_4
  int type; // eax
  float v38; // xmm0_4
  double v39; // st7
  float v40; // xmm0_4
  Vector start; // [esp+18h] [ebp-60h] BYREF
  Vector vecTemp; // [esp+24h] [ebp-54h] BYREF
  Vector vecBoxCenter; // [esp+30h] [ebp-48h] BYREF
  float v45; // [esp+3Ch] [ebp-3Ch]
  float v46; // [esp+40h] [ebp-38h]
  Vector uextent; // [esp+48h] [ebp-30h]
  Vector extent; // [esp+54h] [ebp-24h] BYREF
  Vector segmentCenter; // [esp+60h] [ebp-18h]
  Vector vecBoxExtents; // [esp+6Ch] [ebp-Ch] BYREF
  const Vector *vecRayStarta; // [esp+80h] [ebp+8h]
  const Vector *vecRayDeltaa; // [esp+84h] [ebp+Ch]

  pTrace->startpos = *vecRayStart;
  pTrace->endpos = *vecRayStart;
  pTrace->endpos.x = vecRayDelta->x + pTrace->endpos.x;
  pTrace->endpos.y = vecRayDelta->y + pTrace->endpos.y;
  pTrace->endpos.z = pTrace->endpos.z + vecRayDelta->z;
  pTrace->fraction = 1.0;
  *(_WORD *)&pTrace->allsolid = 0;
  pTrace->contents = 0;
  v8 = (float)(vecOBBMins->y + vecOBBMaxs->y) * 0.5;
  v9 = (float)(vecOBBMins->z + vecOBBMaxs->z) * 0.5;
  vecBoxExtents.x = (float)(vecOBBMins->x + vecOBBMaxs->x) * 0.5;
  vecBoxExtents.y = v8;
  vecBoxExtents.z = v9;
  VectorTransform(in1: &vecBoxExtents.x, in2: matOBBToWorld, out: &vecBoxCenter.x);
  v11 = vecOBBMaxs->y - vecBoxExtents.y;
  x = vecRayDelta->x;
  y = vecRayDelta->y;
  z = vecRayDelta->z;
  v15 = vecOBBMaxs->z - vecBoxExtents.z;
  v45 = vecOBBMaxs->x - vecBoxExtents.x;
  vecBoxExtents.x = v45;
  v16 = vecRayStart->x;
  v46 = v11;
  vecBoxExtents.y = v11;
  v17 = (float)(vecRayStart->y + y) - vecBoxCenter.y;
  *(float *)&vecRayStarta = z;
  v18 = z + vecRayStart->z;
  vecBoxExtents.z = v15;
  vecRayDeltaa = (const Vector *)LODWORD(y);
  segmentCenter.x = (float)(v16 + x) - vecBoxCenter.x;
  v19 = matOBBToWorld->m_flMatVal[2];
  segmentCenter.y = v17;
  segmentCenter.z = v18 - vecBoxCenter.z;
  memset((void *)&extent, 0, sizeof(extent));
  v20 = 0;
  while ( 1 )
  {
    v21 = *(v19 - 4);
    v22 = *(v19 - 8);
    v23 = *v19 * segmentCenter.z;
    v24 = (float)((float)(x * v22) + (float)(y * v21)) + (float)(*(float *)&vecRayStarta * *v19);
    v25 = segmentCenter.y;
    v26 = (float)(v22 * segmentCenter.x) + (float)(v21 * segmentCenter.y);
    v27 = *(float *)((char *)&vecBoxExtents.x + v20);
    *(float *)((char *)&extent.x + v20) = v24;
    v28 = fabs(v24);
    *(float *)((char *)&uextent.x + v20) = v28;
    if ( fabs(v26 + v23) > (float)(v27 + v28) )
      break;
    v20 += 4;
    ++v19;
    if ( v20 >= 12 )
    {
      v29 = vecRayDelta->y;
      v30 = v29 * segmentCenter.x;
      v31 = (float)(v29 * segmentCenter.z) - (float)(vecRayDelta->z * v25);
      v32 = x * segmentCenter.z;
      v33 = (float)(x * v25) - v30;
      v34 = matOBBToWorld->m_flMatVal[1][0];
      v35 = (float)(vecRayDelta->z * segmentCenter.x) - v32;
      v36 = matOBBToWorld->m_flMatVal[0][0];
      segmentCenter.z = v33;
      if ( fabs((float)((float)(v34 * v35) + (float)(v36 * v31)) + (float)(v33 * matOBBToWorld->m_flMatVal[2][0])) <= (float)((float)(uextent.y * v15) + (float)(uextent.z * v46))
        && fabs(
             (float)((float)(matOBBToWorld->m_flMatVal[1][1] * v35) + (float)(matOBBToWorld->m_flMatVal[0][1] * v31))
           + (float)(matOBBToWorld->m_flMatVal[2][1] * segmentCenter.z)) <= (float)((float)(uextent.x * v15)
                                                                                  + (float)(uextent.z * v45))
        && fabs(
             (float)((float)(matOBBToWorld->m_flMatVal[1][2] * v35) + (float)(matOBBToWorld->m_flMatVal[0][2] * v31))
           + (float)(matOBBToWorld->m_flMatVal[2][2] * segmentCenter.z)) <= (float)((float)(uextent.x * v46)
                                                                                  + (float)(uextent.y * v45)) )
      {
        VectorITransform(in1: &vecRayStart->x, in2: matOBBToWorld, out: &start.x);
        extent.x = extent.x * 2.0;
        extent.y = extent.y * 2.0;
        extent.z = extent.z * 2.0;
        if ( IntersectRayWithBox(
               vecRayStart: &start,
               vecRayDelta: &extent,
               boxMins: vecOBBMins,
               boxMaxs: vecOBBMaxs,
               flTolerance,
               pTrace,
               pFractionLeftSolid: nullptr) != 0 )
        {
          VectorTransform(in1: &pTrace->endpos.x, in2: matOBBToWorld, out: &vecTemp.x);
          pTrace->endpos = vecTemp;
          type = pTrace->plane.type;
          pTrace->startpos.x = vecRayStart->x;
          v38 = pTrace->fraction * 2.0;
          pTrace->startpos.y = vecRayStart->y;
          v39 = vecRayStart->z;
          pTrace->fraction = v38;
          pTrace->startpos.z = v39;
          v40 = *(&pTrace->plane.normal.x + type);
          pTrace->plane.normal.x = matOBBToWorld->m_flMatVal[0][type] * v40;
          pTrace->plane.normal.y = matOBBToWorld->m_flMatVal[1][pTrace->plane.type] * v40;
          pTrace->plane.normal.z = matOBBToWorld->m_flMatVal[2][pTrace->plane.type] * v40;
          pTrace->plane.dist = (float)((float)(pTrace->plane.normal.y * pTrace->endpos.y)
                                     + (float)(pTrace->plane.normal.x * pTrace->endpos.x))
                             + (float)(pTrace->plane.normal.z * pTrace->endpos.z);
          pTrace->plane.type = 3;
          return 1;
        }
      }
      return 0;
    }
    y = *(float *)&vecRayDeltaa;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100F2020
// Name: bool IntersectRayWithOBB(struct Ray_t const __near &,struct matrix3x4_t const __near &,class Vector const __near &,class Vector const __near &,float,class CBaseTrace __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __usercall IntersectRayWithOBB@<al>(
        int a1@<ebp>,
        const Ray_t *ray,
        const matrix3x4_t *matOBBToWorld,
        const Vector *vecOBBMins,
        const Vector *vecOBBMaxs,
        float flTolerance,
        CBaseTrace *pTrace)
{
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float y; // xmm5_4
  float z; // xmm6_4
  float v13; // xmm7_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm5_4
  float v18; // xmm2_4
  float v19; // xmm6_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm7_4
  float v23; // xmm0_4
  __int128 v24; // xmm1
  float x; // xmm4_4
  __int128 v26; // xmm1
  float v27; // xmm5_4
  float v28; // xmm4_4
  float v29; // xmm6_4
  float v30; // xmm3_4
  float v31; // xmm0_4
  float v32; // xmm2_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm2_4
  const Vector *v36; // ecx
  float v37; // xmm0_4
  float *v38; // eax
  float *p_y; // esi
  unsigned int v40; // edi
  _DWORD *v41; // edx
  float v42; // xmm1_4
  float v43; // xmm0_4
  float v44; // edx
  float *v45; // eax
  float v46; // xmm1_4
  int v47; // xmm0_4
  float v48; // xmm4_4
  float v49; // xmm5_4
  int v50; // eax
  int v51; // ecx
  int v52; // xmm6_4
  float v53; // xmm3_4
  float v54; // xmm0_4
  float *v55; // eax
  int v56; // ecx
  float v57; // xmm1_4
  float *v58; // edx
  float v59; // xmm1_4
  int v60; // ecx
  float v61; // xmm1_4
  float v62; // xmm7_4
  float v63; // xmm1_4
  float v64; // xmm7_4
  float v65; // xmm1_4
  float v66; // xmm1_4
  int v67; // ecx
  float v68; // xmm6_4
  float v69; // xmm1_4
  float *v70; // edx
  float v71; // xmm1_4
  int v72; // ecx
  float v73; // xmm6_4
  float v74; // xmm1_4
  float v75; // xmm1_4
  float v76; // xmm6_4
  float v77; // xmm1_4
  float v78; // xmm3_4
  int v79; // ecx
  float *v80; // eax
  float v81; // xmm1_4
  float v82; // xmm1_4
  int v83; // ecx
  float v84; // xmm3_4
  float v85; // xmm1_4
  float *v86; // edx
  float v87; // ecx
  float v88; // xmm1_4
  float v89; // xmm3_4
  float v90; // xmm7_4
  float v91; // xmm1_4
  int v92; // edi
  float v93; // eax
  int v94; // esi
  float v95; // xmm1_4
  float v96; // xmm2_4
  float v97; // xmm3_4
  float v98; // xmm4_4
  float v99; // xmm3_4
  float v100; // edx
  float v101; // xmm1_4
  float v102; // xmm3_4
  float v103; // xmm2_4
  float v104; // xmm1_4
  int v105; // xmm1_4
  float v106; // xmm1_4
  int v107; // xmm1_4
  VectorAligned *v108; // edx
  float v109; // eax
  float v110; // xmm0_4
  float v111; // xmm1_4
  float v112; // xmm2_4
  float v113; // xmm0_4
  float v114; // xmm3_4
  bool v115; // al
  double v116; // st7
  _BYTE v117[8]; // [esp+18h] [ebp-1DCh] BYREF
  int v118; // [esp+20h] [ebp-1D4h] BYREF
  Vector pPlaneNormal[15]; // [esp+24h] [ebp-1D0h] BYREF
  _BYTE ppPlaneDist_12[112]; // [esp+E8h] [ebp-10Ch] OVERLAPPED BYREF
  Vector vecLocalRayDirection; // [esp+158h] [ebp-9Ch]
  float v122; // [esp+164h] [ebp-90h]
  int v123; // [esp+168h] [ebp-8Ch]
  float v124[3]; // [esp+16Ch] [ebp-88h] BYREF
  _BYTE temp[32]; // [esp+178h] [ebp-7Ch] OVERLAPPED BYREF
  Vector vecLocalRayEnd; // [esp+198h] [ebp-5Ch] BYREF
  float v127; // [esp+1A4h] [ebp-50h]
  const float *pMatRow0; // [esp+1A8h] [ebp-4Ch]
  float v129; // [esp+1ACh] [ebp-48h]
  float v130; // [esp+1B0h] [ebp-44h]
  float v131; // [esp+1B4h] [ebp-40h]
  VectorAligned *p_m_Delta; // [esp+1B8h] [ebp-3Ch]
  float *v133; // [esp+1BCh] [ebp-38h]
  const Vector *v134; // [esp+1C0h] [ebp-34h]
  float *v135; // [esp+1C4h] [ebp-30h]
  const float *pMatRow1; // [esp+1C8h] [ebp-2Ch]
  float v137; // [esp+1CCh] [ebp-28h] BYREF
  float v138; // [esp+1D0h] [ebp-24h]
  float v139; // [esp+1D4h] [ebp-20h]
  Vector vecOBBCenter; // [esp+1D8h] [ebp-1Ch]
  int hitside; // [esp+1E4h] [ebp-10h]
  int v142; // [esp+1E8h] [ebp-Ch]
  float leavefrac; // [esp+1ECh] [ebp-8h]
  float retaddr; // [esp+1F4h] [ebp+0h]

  v142 = a1;
  leavefrac = retaddr;
  if ( ray->m_IsRay )
    return IntersectRayWithOBB(
             vecRayStart: &ray->m_Start,
             vecRayDelta: &ray->m_Delta,
             matOBBToWorld,
             vecOBBMins,
             vecOBBMaxs,
             flTolerance,
             pTrace);
  v8 = ray->m_StartOffset.y + ray->m_Start.y;
  v9 = ray->m_Start.x + ray->m_StartOffset.x;
  v10 = ray->m_StartOffset.z + ray->m_Start.z;
  pTrace->startpos.y = v8;
  pTrace->startpos.x = v9;
  pTrace->startpos.z = v10;
  pTrace->endpos.y = v8;
  pTrace->endpos.x = v9;
  pTrace->endpos.z = v10;
  pTrace->endpos.x = v9 + ray->m_Delta.x;
  pTrace->endpos.y = ray->m_Delta.y + pTrace->endpos.y;
  pTrace->endpos.z = ray->m_Delta.z + pTrace->endpos.z;
  pTrace->fraction = 1.0;
  *(_WORD *)&pTrace->allsolid = 0;
  pTrace->contents = 0;
  y = vecOBBMaxs->y;
  z = vecOBBMaxs->z;
  v13 = matOBBToWorld->m_flMatVal[0][3];
  v14 = (float)(vecOBBMaxs->x - vecOBBMins->x) * 0.5;
  v15 = (float)(vecOBBMaxs->x + vecOBBMins->x) * 0.5;
  v16 = y + vecOBBMins->y;
  v17 = y - vecOBBMins->y;
  v18 = z + vecOBBMins->z;
  v19 = z - vecOBBMins->z;
  v139 = v18 * 0.5;
  v20 = matOBBToWorld->m_flMatVal[2][3] + (float)(v18 * 0.5);
  v21 = ray->m_Extents.y;
  v22 = v13 + v15;
  v23 = matOBBToWorld->m_flMatVal[1][3] + (float)(v16 * 0.5);
  v24 = 0;
  v138 = v23;
  v139 = v20;
  *(float *)&v24 = (float)((float)(v14 * v14) + (float)((float)(v17 * 0.5) * (float)(v17 * 0.5)))
                 + (float)((float)(v19 * 0.5) * (float)(v19 * 0.5));
  x = ray->m_Extents.x;
  *(float *)&v24 = fsqrt(*(float *)&v24);
  *(_OWORD *)&ppPlaneDist_12[96] = v24;
  v26 = 0;
  *(float *)&v26 = fsqrt((float)((float)(x * x) + (float)(v21 * v21)) + (float)(ray->m_Extents.z * ray->m_Extents.z));
  *(_OWORD *)&temp[16] = v26;
  p_m_Delta = &ray->m_Delta;
  v27 = ray->m_Start.x;
  v28 = ray->m_Delta.x;
  v29 = ray->m_Delta.y;
  v30 = (float)(*(float *)&v26 + *(float *)&ppPlaneDist_12[96]) + flTolerance;
  v31 = (float)((float)((float)(v23 - ray->m_Start.y) * v29) + (float)((float)(v22 - ray->m_Start.x) * v28))
      + (float)((float)(v20 - ray->m_Start.z) * ray->m_Delta.z);
  v32 = 0.0;
  if ( v31 > 0.0 )
  {
    vecOBBCenter.y = (float)(v29 * v29) + (float)(v28 * v28);
    vecOBBCenter.x = ray->m_Delta.z * ray->m_Delta.z;
    if ( v31 <= (float)(vecOBBCenter.y + vecOBBCenter.x) )
      v32 = v31 / (float)(vecOBBCenter.y + vecOBBCenter.x);
    else
      v32 = 1.0;
  }
  v33 = (float)((float)(v32 * v29) + ray->m_Start.y) - v138;
  v34 = v32 * v28;
  v35 = (float)((float)(v32 * ray->m_Delta.z) + ray->m_Start.z) - v139;
  if ( (float)(v30 * v30) >= (float)((float)((float)(v33 * v33)
                                           + (float)((float)((float)(v34 + v27) - v22)
                                                   * (float)((float)(v34 + v27) - v22)))
                                   + (float)(v35 * v35)) )
  {
    VectorITransform(in1: &ray->m_Start.x, in2: matOBBToWorld, out: &v137);
    VectorIRotate(in1: &p_m_Delta->x, in2: matOBBToWorld, out: (float *)&ppPlaneDist_12[100]);
    v36 = vecOBBMaxs;
    vecLocalRayDirection.y = ray->m_Extents.y;
    v122 = ray->m_Extents.x;
    vecLocalRayDirection.z = ray->m_Extents.z;
    v130 = vecOBBMaxs->z;
    pMatRow0 = (const float *)LODWORD(vecOBBMins->z);
    v127 = vecOBBMaxs->x;
    v131 = vecOBBMins->x;
    vecOBBCenter.x = vecOBBMaxs->y;
    v37 = vecOBBMins->y;
    *(float *)&hitside = COERCE_FLOAT(v117);
    pMatRow1 = &ray->m_Extents.x;
    v38 = matOBBToWorld->m_flMatVal[2];
    vecOBBCenter.y = v37;
    LODWORD(vecLocalRayDirection.x) = (char *)vecOBBMins - (char *)vecOBBMaxs;
    v134 = vecOBBMaxs;
    LODWORD(vecOBBCenter.z) = &matOBBToWorld->m_flMatVal[0][1];
    p_y = &pPlaneNormal[5].y;
    v135 = matOBBToWorld->m_flMatVal[2];
    v40 = 0;
    while ( 1 )
    {
      v41 = (_DWORD *)hitside;
      v42 = *(v38 - 4) * vecLocalRayDirection.y;
      *(p_y - 19) = 0.0;
      *(p_y - 18) = 0.0;
      *(p_y - 17) = 0.0;
      *v41 = 1065353216;
      v43 = (float)(fabs(*(v38 - 8) * v122) + fabs(v42)) + fabs(vecLocalRayDirection.z * *v38);
      v44 = vecOBBCenter.z;
      v45 = (float *)&ppPlaneDist_12[v40];
      *(v45 - 6) = *(float *)((char *)&v36->x + LODWORD(vecLocalRayDirection.x)) - v43;
      v46 = v36->x + v43;
      v129 = *(float *)(LODWORD(v44) - 4);
      *(p_y - 10) = v129;
      v47 = *(_DWORD *)LODWORD(v44);
      *(v45 - 5) = v46;
      *(_DWORD *)&temp[12] = v47;
      *((_DWORD *)p_y - 9) = v47;
      v123 = *(_DWORD *)(LODWORD(v44) + 4);
      *((_DWORD *)p_y - 8) = v123;
      ComputeSupportMap(
        vecDirection: (const Vector *)(p_y - 10),
        vecBoxMins: vecOBBMins,
        vecBoxMaxs: vecOBBMaxs,
        pDist: (float *)&ppPlaneDist_12[v40]);
      v48 = *(&ray->m_Extents.x + s_ExtIndices[v40 / 8][0]);
      v49 = *(&ray->m_Extents.x + s_ExtIndices[v40 / 8][1]);
      v50 = s_MatIndices[v40 / 8][0];
      v51 = s_MatIndices[v40 / 8][1];
      v52 = v123;
      v53 = *(float *)&temp[12];
      v54 = *pMatRow1 + *(float *)&ppPlaneDist_12[v40 + 4];
      *(float *)&ppPlaneDist_12[v40] = *(float *)&ppPlaneDist_12[v40] - *pMatRow1;
      *(float *)&ppPlaneDist_12[v40 + 4] = v54;
      v55 = matOBBToWorld->m_flMatVal[v50];
      LODWORD(vecLocalRayEnd.z) = v55;
      v133 = matOBBToWorld->m_flMatVal[v51];
      *(p_y - 1) = 0.0;
      *(_DWORD *)p_y = v52 ^ _mask__NegFloat_;
      p_y[1] = v53;
      v56 = 4 * (COERCE_FLOAT(v52 ^ _mask__NegFloat_) > 0.0);
      v57 = COERCE_FLOAT(v52 ^ _mask__NegFloat_) * vecOBBCenter.y;
      v58 = (float *)&ppPlaneDist_12[v40 + 24];
      v58[v56 / 4u] = COERCE_FLOAT(v52 ^ _mask__NegFloat_) * vecOBBCenter.x;
      v58[v56 / 0xFFFFFFFC + 1] = v57;
      v59 = p_y[1];
      v60 = v59 > 0.0;
      v61 = v59 * *(float *)&pMatRow0;
      v60 *= 4;
      *(float *)((char *)v58 + v60) = (float)(p_y[1] * v130) + *(float *)((char *)v58 + v60);
      v62 = *v133;
      *(float *)((char *)v58 - v60 + 4) = v61 + *(float *)((char *)v58 - v60 + 4);
      v63 = (float)(fabs(*v55) * v48) + (float)(fabs(v62) * v49);
      v64 = *(float *)&ppPlaneDist_12[v40 + 24] - v63;
      *(float *)&ppPlaneDist_12[v40 + 28] = v63 + *(float *)&ppPlaneDist_12[v40 + 28];
      v65 = v129;
      *((_DWORD *)p_y + 8) = v52;
      p_y[9] = 0.0;
      p_y[10] = -v65;
      v66 = p_y[8];
      *v58 = v64;
      v67 = 4 * (v66 > 0.0);
      v68 = v66 * v127;
      v69 = v66 * v131;
      v70 = (float *)&ppPlaneDist_12[v40 + 48];
      v70[v67 / 4u] = v68;
      v70[v67 / 0xFFFFFFFC + 1] = v69;
      v71 = p_y[10];
      v72 = v71 > 0.0;
      v73 = v71 * v130;
      v74 = v71 * *(float *)&pMatRow0;
      v72 *= 4;
      *(float *)((char *)v70 + v72) = v73 + *(float *)((char *)v70 + v72);
      *(float *)((char *)v70 - v72 + 4) = v74 + *(float *)((char *)v70 - v72 + 4);
      v75 = (float)(fabs(v55[1]) * v48) + (float)(fabs(v133[1]) * v49);
      *v70 = *v70 - v75;
      v76 = *(float *)&ppPlaneDist_12[v40 + 52] + v75;
      v77 = v129;
      *(float *)&ppPlaneDist_12[v40 + 52] = v76;
      v78 = -v53;
      p_y[18] = v77;
      p_y[17] = v78;
      p_y[19] = 0.0;
      v79 = 4 * (v78 > 0.0);
      v80 = (float *)&ppPlaneDist_12[v40 + 72];
      v81 = v78 * v131;
      v80[v79 / 4u] = v78 * v127;
      v80[v79 / 0xFFFFFFFC + 1] = v81;
      v82 = p_y[18];
      v83 = v82 > 0.0;
      v84 = v82 * vecOBBCenter.x;
      v85 = v82 * vecOBBCenter.y;
      v83 *= 4;
      *(float *)((char *)v80 + v83) = v84 + *(float *)((char *)v80 + v83);
      v86 = (float *)&ppPlaneDist_12[v40 + 72 - v83];
      v87 = vecLocalRayEnd.z;
      v86[1] = v85 + v86[1];
      v88 = (float)(fabs(*(float *)(LODWORD(v87) + 8)) * v48) + (float)(fabs(v133[2]) * v49);
      *v80 = *v80 - v88;
      v89 = *(float *)&ppPlaneDist_12[v40 + 76];
      ++v135;
      v134 = (const Vector *)((char *)v134 + 4);
      ++pMatRow1;
      hitside += 16;
      LODWORD(vecOBBCenter.z) += 16;
      *(float *)&ppPlaneDist_12[v40 + 76] = v89 + v88;
      v40 += 8;
      p_y += 3;
      if ( (int)v40 >= 24 )
        break;
      v38 = v135;
      v36 = v134;
    }
    v90 = *(float *)&ppPlaneDist_12[100] + v137;
    *(float *)&hitside = -1.0;
    vecOBBCenter.z = 1.0;
    *(float *)&temp[24] = *(float *)&ppPlaneDist_12[104] + v138;
    v91 = *(float *)&ppPlaneDist_12[108] + v139;
    v92 = -1;
    v93 = COERCE_FLOAT(&v118);
    vecOBBCenter.x = NAN;
    pTrace->startsolid = true;
    *(float *)&temp[28] = v91;
    v94 = 0;
    LODWORD(vecOBBCenter.y) = &v118;
LABEL_12:
    v95 = (float)((float)(v138 * *(float *)(LODWORD(v93) - 4)) + (float)(v137 * *(float *)(LODWORD(v93) - 8)))
        + (float)(v139 * *(float *)LODWORD(v93));
    v96 = (float)((float)(*(float *)&temp[24] * *(float *)(LODWORD(v93) - 4))
                + (float)(v90 * *(float *)(LODWORD(v93) - 8)))
        + (float)(*(float *)&temp[28] * *(float *)LODWORD(v93));
    v97 = *(&pPlaneNormal[14].y + 2 * v94);
    *(float *)&temp[8] = -(float)(v95 - v97);
    v98 = v96 - v97;
    v99 = *(&pPlaneNormal[14].z + 2 * v94);
    vecLocalRayEnd.y = -v98;
    *(float *)&temp[12] = v95 - v99;
    vecLocalRayEnd.z = v96 - v99;
    v100 = 0.0;
    while ( 1 )
    {
      v101 = *(float *)&temp[4 * LODWORD(v100) + 8];
      if ( v101 > 0.0 && *(&vecLocalRayEnd.y + LODWORD(v100)) > 0.0 )
        break;
      if ( v101 > 0.0 || *(&vecLocalRayEnd.y + LODWORD(v100)) > 0.0 )
      {
        if ( v101 > 0.0 )
          pTrace->startsolid = false;
        v102 = *(&vecLocalRayEnd.y + LODWORD(v100));
        v103 = 1.0 / (float)(v101 - v102);
        if ( v101 <= v102 )
        {
          v106 = (float)(v101 + flTolerance) * v103;
          if ( vecOBBCenter.z > v106 )
            vecOBBCenter.z = v106;
        }
        else
        {
          v104 = v101 - flTolerance;
          if ( v104 < 0.0 )
            v104 = 0.0;
          *(float *)&v105 = v104 * v103;
          if ( *(float *)&v105 > *(float *)&hitside )
          {
            v93 = vecOBBCenter.y;
            hitside = v105;
            v92 = v94;
            vecOBBCenter.x = v100;
          }
        }
      }
      ++LODWORD(v100);
      if ( SLODWORD(v100) >= 2 )
      {
        ++v94;
        LODWORD(v93) += 12;
        vecOBBCenter.y = v93;
        if ( v94 < 15 )
          goto LABEL_12;
        v107 = hitside;
        if ( vecOBBCenter.z <= *(float *)&hitside || *(float *)&hitside < 0.0 )
        {
          if ( !pTrace->startsolid )
            return 0;
          v115 = vecOBBCenter.z <= 0.0 || vecOBBCenter.z >= 1.0;
          v116 = pTrace->startpos.x;
          pTrace->allsolid = v115;
          pTrace->fraction = 0.0;
          pTrace->endpos.x = v116;
          pTrace->endpos.y = pTrace->startpos.y;
          pTrace->endpos.z = pTrace->startpos.z;
          pTrace->contents = 1;
          pTrace->plane.dist = pTrace->startpos.x;
          pTrace->plane.normal.x = 1.0;
          pTrace->plane.normal.y = 0.0;
          pTrace->plane.normal.z = 0.0;
          pTrace->plane.type = 0;
          return 1;
        }
        else
        {
          v108 = p_m_Delta;
          v109 = vecOBBCenter.x;
          pTrace->fraction = *(float *)&hitside;
          pTrace->endpos.x = (float)(*(float *)&v107 * v108->x) + pTrace->startpos.x;
          pTrace->endpos.y = (float)(v108->y * *(float *)&v107) + pTrace->startpos.y;
          v110 = (float)(v108->z * *(float *)&v107) + pTrace->startpos.z;
          v111 = *(float *)&v117[12 * v92 + 4];
          v112 = *((float *)&v118 + 3 * v92);
          pTrace->endpos.z = v110;
          v113 = *(float *)&v117[12 * v92];
          v114 = *(&pPlaneNormal[14].y + 2 * v92 + LODWORD(v109));
          pTrace->contents = 1;
          v124[0] = v113;
          v124[1] = v111;
          v124[2] = v112;
          *(float *)temp = v114;
          if ( v109 == 0.0 )
          {
            v124[0] = v113 * -1.0;
            v124[1] = v111 * -1.0;
            v124[2] = v112 * -1.0;
            *(float *)temp = v114 * -1.0;
          }
          temp[4] = 3;
          MatrixGetColumn(in: matOBBToWorld, column: 3, out: &vecLocalRayEnd);
          VectorIRotate(in1: &vecLocalRayEnd.x, in2: matOBBToWorld, out: (float *)&temp[20]);
          VectorIRotate(in1: v124, in2: matOBBToWorld, out: &pTrace->plane.normal.x);
          pTrace->plane.dist = (float)((float)((float)((float)(pTrace->plane.normal.x * pTrace->plane.normal.x)
                                                     + (float)(pTrace->plane.normal.y * pTrace->plane.normal.y))
                                             + (float)(pTrace->plane.normal.z * pTrace->plane.normal.z))
                                     * *(float *)temp)
                             - (float)((float)((float)(*(float *)&temp[20] * pTrace->plane.normal.x)
                                             + (float)(*(float *)&temp[24] * pTrace->plane.normal.y))
                                     + (float)(*(float *)&temp[28] * pTrace->plane.normal.z));
          return 1;
        }
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x104071E0
// Name: _dynamic_initializer_for__collision_shake_amp__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__collision_shake_amp__()
{
  ConVar::ConVar(this: &collision_shake_amp, pName: "collision_shake_amp", pDefaultValue: "0.2", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__collision_shake_amp__);
}

//------------------------------------------------------------------------------
// Address: 0x10407210
// Name: _dynamic_initializer_for__collision_shake_freq__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__collision_shake_freq__()
{
  ConVar::ConVar(this: &collision_shake_freq, pName: "collision_shake_freq", pDefaultValue: "0.5", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__collision_shake_freq__);
}

//------------------------------------------------------------------------------
// Address: 0x10407240
// Name: _dynamic_initializer_for__collision_shake_time__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__collision_shake_time__()
{
  ConVar::ConVar(this: &collision_shake_time, pName: "collision_shake_time", pDefaultValue: "0.5", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__collision_shake_time__);
}

//------------------------------------------------------------------------------
// Address: 0x1040C2B0
// Name: _dynamic_initializer_for__collision_test__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__collision_test__()
{
  ConCommand::ConCommand(
    this: &collision_test,
    pName: "collision_test",
    callback: (void (__cdecl *)())CC_CollisionTest,
    pHelpString: "Tests collision system",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__collision_test__);
}

//------------------------------------------------------------------------------
// Address: 0x1041CB00
// Name: _dynamic_atexit_destructor_for__collision_shake_amp__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__collision_shake_amp__()
{
  ConVar::~ConVar(this: &collision_shake_amp);
}

//------------------------------------------------------------------------------
// Address: 0x1041CB10
// Name: _dynamic_atexit_destructor_for__collision_shake_freq__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__collision_shake_freq__()
{
  ConVar::~ConVar(this: &collision_shake_freq);
}

//------------------------------------------------------------------------------
// Address: 0x1041CB20
// Name: _dynamic_atexit_destructor_for__collision_shake_time__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__collision_shake_time__()
{
  ConVar::~ConVar(this: &collision_shake_time);
}

//------------------------------------------------------------------------------
// Address: 0x1041ECC0
// Name: _dynamic_atexit_destructor_for__collision_test__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__collision_test__()
{
  ConCommand::~ConCommand(this: &collision_test);
}

//------------------------------------------------------------------------------
// Address: 0x10407270
// Name: _dynamic_initializer_for__air_density__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__air_density__()
{
  ConCommand::ConCommand(
    this: &air_density,
    pName: "air_density",
    callback: (void (__cdecl *)())CC_AirDensity,
    pHelpString: "Changes the density of air for drag computations.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__air_density__);
}

//------------------------------------------------------------------------------
// Address: 0x1040C2E0
// Name: _dynamic_initializer_for__r_visualizetraces__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_visualizetraces__()
{
  ConVar::ConVar(this: &r_visualizetraces, pName: "r_visualizetraces", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_visualizetraces__);
}

//------------------------------------------------------------------------------
// Address: 0x1040C310
// Name: _dynamic_initializer_for__developer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__developer__()
{
  ConVar::ConVar(
    this: &developer,
    pName: "developer",
    pDefaultValue: "0",
    flags: 0x80000,
    pHelpString: "Set developer message level");
  return atexit(func: dynamic_atexit_destructor_for__developer__);
}

//------------------------------------------------------------------------------
// Address: 0x1040C340
// Name: _dynamic_initializer_for__violence_hblood__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__violence_hblood__()
{
  ConVar::ConVar(
    this: &violence_hblood,
    pName: "violence_hblood",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Draw human blood");
  return atexit(func: dynamic_atexit_destructor_for__violence_hblood__);
}

//------------------------------------------------------------------------------
// Address: 0x1040C370
// Name: _dynamic_initializer_for__violence_hgibs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__violence_hgibs__()
{
  ConVar::ConVar(
    this: &violence_hgibs,
    pName: "violence_hgibs",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Show human gib entities");
  return atexit(func: dynamic_atexit_destructor_for__violence_hgibs__);
}

//------------------------------------------------------------------------------
// Address: 0x1040C3A0
// Name: _dynamic_initializer_for__violence_ablood__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__violence_ablood__()
{
  ConVar::ConVar(
    this: &violence_ablood,
    pName: "violence_ablood",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Draw alien blood");
  return atexit(func: dynamic_atexit_destructor_for__violence_ablood__);
}

//------------------------------------------------------------------------------
// Address: 0x1040C3D0
// Name: _dynamic_initializer_for__violence_agibs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__violence_agibs__()
{
  ConVar::ConVar(
    this: &violence_agibs,
    pName: "violence_agibs",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Show alien gib entities");
  return atexit(func: dynamic_atexit_destructor_for__violence_agibs__);
}

//------------------------------------------------------------------------------
// Address: 0x1041CB30
// Name: _dynamic_atexit_destructor_for__air_density__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__air_density__()
{
  ConCommand::~ConCommand(this: &air_density);
}

//------------------------------------------------------------------------------
// Address: 0x1041CB40
// Name: _dynamic_atexit_destructor_for__g_Collisions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Collisions__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_Collisions.m_removeObjects);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_Collisions.m_fluidEvents);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_Collisions.m_penetrateEvents);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_Collisions.m_damageInflictors);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_Collisions.m_damageEvents);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_Collisions.m_touchEvents);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_Collisions.m_triggerEvents);
}

//------------------------------------------------------------------------------
// Address: 0x1041CB90
// Name: _dynamic_atexit_destructor_for__g_PostSimulationQueue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PostSimulationQueue__()
{
  CTSQueue<CFunctor *,0,1>::Purge(this: &g_PostSimulationQueue.m_queue);
  free(pMem: g_PostSimulationQueue.m_queue.m_Head.value.pNode);
  CTSListBase::Detach(this: &g_PostSimulationQueue.m_queue.m_FreeNodes);
}

//------------------------------------------------------------------------------
// Address: 0x1041CBC0
// Name: _dynamic_atexit_destructor_for__g_PhysicsHook__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PhysicsHook__()
{
  CUtlVector<vehiclescript_t,CUtlMemory<vehiclescript_t,int>>::~CUtlVector<vehiclescript_t,CUtlMemory<vehiclescript_t,int>>(this: &g_PhysicsHook.m_vehicleScripts);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_PhysicsHook.m_massCenterOverrides);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_PhysicsHook.m_breakSounds);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_PhysicsHook.m_impactSounds);
  IGameSystemPerFrame::~IGameSystemPerFrame(this: &g_PhysicsHook);
}

//------------------------------------------------------------------------------
// Address: 0x1041ECD0
// Name: _dynamic_atexit_destructor_for__g_PrecacheOtherList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PrecacheOtherList__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_PrecacheOtherList.m_list);
  IGameSystem::~IGameSystem(this: &g_PrecacheOtherList);
}

//------------------------------------------------------------------------------
// Address: 0x1041ECF0
// Name: _dynamic_atexit_destructor_for__g_CheckClient__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CheckClient__()
{
  IGameSystem::~IGameSystem(this: &g_CheckClient);
}

//------------------------------------------------------------------------------
// Address: 0x1041ED00
// Name: _EntityFactoryDictionary_::_2_::_dynamic_atexit_destructor_for__s_EntityFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl EntityFactoryDictionary_::_2_::_dynamic_atexit_destructor_for__s_EntityFactory__()
{
  CUtlDict<IEntityFactory *,unsigned short>::RemoveAll(this: &s_EntityFactory.m_Factories);
  CUtlRBTree<CUtlMap<char const *,IEntityFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IEntityFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IEntityFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,IEntityFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IEntityFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IEntityFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &s_EntityFactory.m_Factories.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1041ED20
// Name: _dynamic_atexit_destructor_for__r_visualizetraces__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_visualizetraces__()
{
  ConVar::~ConVar(this: &r_visualizetraces);
}

//------------------------------------------------------------------------------
// Address: 0x1041ED30
// Name: _dynamic_atexit_destructor_for__developer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__developer__()
{
  ConVar::~ConVar(this: &developer);
}

//------------------------------------------------------------------------------
// Address: 0x1041ED40
// Name: _dynamic_atexit_destructor_for__violence_hblood__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__violence_hblood__()
{
  ConVar::~ConVar(this: &violence_hblood);
}

//------------------------------------------------------------------------------
// Address: 0x1041ED50
// Name: _dynamic_atexit_destructor_for__violence_hgibs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__violence_hgibs__()
{
  ConVar::~ConVar(this: &violence_hgibs);
}

//------------------------------------------------------------------------------
// Address: 0x1041ED60
// Name: _dynamic_atexit_destructor_for__violence_ablood__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__violence_ablood__()
{
  ConVar::~ConVar(this: &violence_ablood);
}

//------------------------------------------------------------------------------
// Address: 0x1041ED70
// Name: _dynamic_atexit_destructor_for__violence_agibs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__violence_agibs__()
{
  ConVar::~ConVar(this: &violence_agibs);
}

} // namespace server
