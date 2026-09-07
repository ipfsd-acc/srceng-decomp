// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vrad/trace.cpp
// Functions: 14
// ============================================================

#include "utils\vrad\trace.h"

//------------------------------------------------------------------------------
// Address: 0x10019490
// Name: int PointLeafnum_r(class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl PointLeafnum_r(const Vector *point, int ndxNode)
{
  int v2; // ecx
  dnode_t *v3; // ecx
  int v4; // edx
  float *v5; // eax
  float v6; // xmm0_4

  v2 = ndxNode;
  while ( v2 >= 0 )
  {
    v3 = &dnodes[v2];
    v4 = dword_13DEFFD8[5 * v3->planenum];
    v5 = &dplanes.x + 5 * v3->planenum;
    if ( v4 >= 3 )
      v6 = (float)((float)(v5[1] * point->y) + (float)(*v5 * point->x)) + (float)(v5[2] * point->z);
    else
      v6 = *(&point->x + v4);
    if ( (float)(v6 - v5[3]) >= 0.0 )
      v2 = v3->children[0];
    else
      v2 = v3->children[1];
  }
  return -1 - v2;
}

//------------------------------------------------------------------------------
// Address: 0x10019510
// Name: int PointLeafnum(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl PointLeafnum(const Vector *point)
{
  return PointLeafnum_r(point, ndxNode: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10019530
// Name: public: class CBaseTrace __near & CBaseTrace::operator=(class CBaseTrace const __near &)
// Source: json
//------------------------------------------------------------------------------
CBaseTrace *__thiscall CBaseTrace::operator=(CBaseTrace *this, const CBaseTrace *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100195C0
// Name: public: virtual bool CCoverageCountTexture::VisitTriangle_ShouldContinue(struct TriIntersectData_t const __near &,class FourRays const __near &,union __m128 __near *,union __m128 __near *,union __m128 __near *,union __m128 __near *,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCoverageCountTexture::VisitTriangle_ShouldContinue(
        CCoverageCountTexture *this,
        const TriIntersectData_t *triangle,
        const FourRays *rays,
        __m128 *pHitMask,
        __m128 *b0,
        __m128 *b1,
        __m128 *b2,
        int hitID)
{
  __m128 v8; // xmm0
  __m128 *v9; // esi
  int v10; // ecx
  char *v11; // edi
  int v12; // edx
  CCoverageCountTexture *v13; // eax
  __m128 v14; // xmm0
  __m128 v15; // xmm0
  __m128 addedCoverage; // [esp+18h] [ebp-1Ch] BYREF
  CCoverageCountTexture *v18; // [esp+28h] [ebp-Ch]
  int sign; // [esp+2Ch] [ebp-8h]
  int s; // [esp+30h] [ebp-4h]
  __m128 *b1a; // [esp+4Ch] [ebp+18h]
  __m128 *b2a; // [esp+50h] [ebp+1Ch]

  v8 = *pHitMask;
  v9 = b1;
  v18 = this;
  b1a = (__m128 *)((char *)b2 - (char *)b1);
  sign = _mm_movemask_ps(v8);
  v10 = 0;
  s = 0;
  b2a = (__m128 *)((char *)b0 - (char *)v9);
  v11 = (char *)((char *)&addedCoverage - (char *)v9);
  do
  {
    v12 = sign >> v10;
    *(int *)((char *)v9->m128_i32 + (_DWORD)v11) = 0;
    if ( (v12 & 1) != 0 )
    {
      *(float *)((char *)v9->m128_f32 + (_DWORD)v11) = ComputeCoverageFromTexture(
                                                         b0: *(float *)((char *)v9->m128_f32 + (_DWORD)b2a),
                                                         b1: v9->m128_f32[0],
                                                         b2: *(float *)((char *)v9->m128_f32 + (_DWORD)b1a),
                                                         hitID);
      v10 = s;
    }
    ++v10;
    v9 = (__m128 *)((char *)v9 + 4);
    s = v10;
  }
  while ( v10 < 4 );
  v13 = v18;
  v14 = _mm_add_ps(addedCoverage, v18->m_coverage);
  v18->m_coverage = v14;
  v15 = _mm_min_ps(v14, Four_Ones);
  v13->m_coverage = v15;
  return _mm_movemask_ps(_mm_cmpeq_ps(_mm_and_ps(_mm_cmpeq_ps(v15, Four_Ones), *pHitMask), *pHitMask)) != 15;
}

//------------------------------------------------------------------------------
// Address: 0x100196A0
// Name: void TestLine(class FourVectors const __near &,class FourVectors const __near &,union __m128 __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TestLine(const FourVectors *start, const FourVectors *stop, __m128 *pFractionVisible)
{
  __m128 v3; // xmm2
  __m128 v4; // xmm3
  __m128 v5; // xmm4
  int rt_result_36; // [esp+84h] [ebp-6Ch]
  int rt_result_40; // [esp+88h] [ebp-68h]
  int rt_result_44; // [esp+8Ch] [ebp-64h]
  int rt_result_48; // [esp+90h] [ebp-60h]
  float rt_result_52; // [esp+94h] [ebp-5Ch]
  float rt_result_56; // [esp+98h] [ebp-58h]
  float rt_result_60; // [esp+9Ch] [ebp-54h]
  float rt_result_64; // [esp+A0h] [ebp-50h]
  __m128 coverageCallback_20; // [esp+C4h] [ebp-2Ch]
  __m128 len_4; // [esp+D4h] [ebp-1Ch]

  v3 = _mm_sub_ps(stop->x, start->x);
  v4 = _mm_sub_ps(stop->y, start->y);
  v5 = _mm_sub_ps(stop->z, start->z);
  coverageCallback_20 = _mm_sqrt_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v4, v4), _mm_mul_ps(v3, v3)), _mm_mul_ps(v5, v5)));
  RayTracingEnvironment::Trace4Rays(this: &g_RtEnv, TMin: Four_Zeros, TMax: coverageCallback_20);
  len_4.m128_i32[0] = 1065353216;
  if ( rt_result_36 != -1 && coverageCallback_20.m128_f32[0] > rt_result_52 )
    len_4.m128_i32[0] = 0;
  len_4.m128_i32[1] = 1065353216;
  if ( rt_result_40 != -1 && coverageCallback_20.m128_f32[1] > rt_result_56 )
    len_4.m128_i32[1] = 0;
  len_4.m128_i32[2] = 1065353216;
  if ( rt_result_44 != -1 && coverageCallback_20.m128_f32[2] > rt_result_60 )
    len_4.m128_i32[2] = 0;
  len_4.m128_i32[3] = 1065353216;
  if ( rt_result_48 != -1 && coverageCallback_20.m128_f32[3] > rt_result_64 )
    len_4.m128_i32[3] = 0;
  *pFractionVisible = len_4;
  if ( g_bTextureShadows )
    *pFractionVisible = _mm_min_ps(len_4, _mm_sub_ps(Four_Ones, Four_Zeros));
}

//------------------------------------------------------------------------------
// Address: 0x10019830
// Name: void DM_ClipBoxToBrush(class CToolTrace __near *,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,struct dbrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DM_ClipBoxToBrush(
        CToolTrace *trace,
        const Vector *mins,
        const Vector *maxs,
        const Vector *p1,
        const Vector *p2,
        dbrush_t *brush)
{
  int numsides; // eax
  dplane_t *v7; // esi
  float v8; // xmm7_4
  CToolTrace *v9; // ebx
  int v10; // edx
  dbrushside_t *v11; // ecx
  const Vector *v12; // edi
  float v13; // xmm5_4
  float *v14; // eax
  float v15; // xmm4_4
  float x; // xmm2_4
  const Vector *v17; // edi
  float v18; // xmm3_4
  float v19; // xmm1_4
  const Vector *v20; // edi
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  bool v25; // cc
  float v26; // xmm0_4
  float v27; // xmm2_4
  float v28; // xmm2_4
  dbrushside_t *v29; // ecx
  float *v30; // eax
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm0_4
  float v35; // xmm2_4
  float v36; // xmm2_4
  __int16 texinfo; // ax
  float z; // [esp+10h] [ebp-24h]
  float y; // [esp+18h] [ebp-1Ch]
  int v40; // [esp+1Ch] [ebp-18h]
  dbrushside_t *leadside; // [esp+20h] [ebp-14h]
  dplane_t *clipplane; // [esp+24h] [ebp-10h]
  float leavefrac; // [esp+28h] [ebp-Ch]
  float enterfrac; // [esp+2Ch] [ebp-8h]
  bool getout; // [esp+32h] [ebp-2h]
  bool startout; // [esp+33h] [ebp-1h]

  numsides = brush->numsides;
  v7 = nullptr;
  v40 = numsides;
  if ( numsides == 0 )
    return;
  v8 = -9999.0;
  v9 = trace;
  enterfrac = -9999.0;
  leavefrac = 1.0;
  clipplane = nullptr;
  getout = false;
  startout = false;
  leadside = nullptr;
  if ( trace->ispoint == 0 )
  {
    v10 = 0;
    if ( numsides <= 0 )
      goto LABEL_46;
    y = p1->y;
    v11 = &dbrushsides[brush->firstside];
    while ( 1 )
    {
      v12 = maxs;
      v13 = *(&dplanes.x + 5 * v11->planenum);
      v14 = &dplanes.x + 5 * v11->planenum;
      if ( v13 >= 0.0 )
        v12 = mins;
      v15 = v14[1];
      x = v12->x;
      v17 = maxs;
      if ( v15 >= 0.0 )
        v17 = mins;
      v18 = v14[2];
      v19 = v17->y;
      v20 = maxs;
      if ( v18 >= 0.0 )
        v20 = mins;
      v21 = v14[3] - (float)((float)((float)(v15 * v19) + (float)(v13 * x)) + (float)(v18 * v20->z));
      z = p1->z;
      v22 = (float)((float)((float)(y * v15) + (float)(p1->x * v13)) + (float)(z * v18)) - v21;
      v23 = (float)((float)((float)(p2->y * v15) + (float)(p2->x * v13)) + (float)(p2->z * v18)) - v21;
      if ( v22 <= 0.0 )
      {
        if ( v23 > 0.0 )
          getout = true;
      }
      else if ( v23 > 0.0 )
      {
        return;
      }
      if ( v22 > 0.0 )
        break;
      if ( v23 > 0.0 )
        goto LABEL_19;
      v8 = enterfrac;
LABEL_25:
      ++v10;
      ++v11;
      if ( v10 >= v40 )
        goto LABEL_45;
    }
    startout = true;
LABEL_19:
    v8 = enterfrac;
    v24 = (float)((float)((float)(y * v15) + (float)(p1->x * v13)) + (float)(z * v18)) - v21;
    v25 = v22 <= v23;
    v26 = v22 - v23;
    if ( v25 )
    {
      v28 = (float)(v24 + 0.03125) / v26;
      if ( leavefrac > v28 )
        leavefrac = v28;
    }
    else
    {
      v27 = (float)(v24 - 0.03125) / v26;
      if ( v27 > enterfrac )
      {
        v8 = v27;
        enterfrac = v27;
        leadside = v11;
        v7 = (dplane_t *)((char *)&dplanes + 20 * v11->planenum);
      }
    }
    goto LABEL_25;
  }
  if ( numsides <= 0 )
    goto LABEL_46;
  v29 = &dbrushsides[brush->firstside];
  do
  {
    v30 = &dplanes.x + 5 * v29->planenum;
    if ( v29->bevel == 1 )
      goto LABEL_43;
    v31 = (float)((float)((float)(p1->y * v30[1]) + (float)(p1->x * *v30)) + (float)(p1->z * v30[2])) - v30[3];
    v32 = (float)((float)((float)(p2->y * v30[1]) + (float)(*v30 * p2->x)) + (float)(p2->z * v30[2])) - v30[3];
    if ( v31 <= 0.0 )
    {
      if ( v32 > 0.0 )
      {
        v9 = trace;
        getout = true;
      }
    }
    else if ( v32 > 0.0 )
    {
      return;
    }
    if ( v31 <= 0.0 )
    {
      if ( v32 <= 0.0 )
        goto LABEL_43;
    }
    else
    {
      v9 = trace;
      startout = true;
    }
    v33 = (float)((float)((float)(p1->y * v30[1]) + (float)(p1->x * *v30)) + (float)(p1->z * v30[2])) - v30[3];
    v25 = v31 <= v32;
    v34 = v31 - v32;
    if ( v25 )
    {
      v36 = (float)(v33 + 0.03125) / v34;
      if ( leavefrac > v36 )
        leavefrac = v36;
    }
    else
    {
      v35 = (float)(v33 - 0.03125) / v34;
      if ( v35 > v8 )
      {
        v8 = v35;
        clipplane = (dplane_t *)((char *)&dplanes + 20 * v29->planenum);
        leadside = v29;
      }
    }
LABEL_43:
    v7 = (dplane_t *)((char *)v7 + 1);
    ++v29;
  }
  while ( (int)v7 < v40 );
  v7 = clipplane;
LABEL_45:
  if ( startout )
  {
    if ( leavefrac > v8 && v8 > -9999.0 && v9->fraction > v8 )
    {
      if ( v8 < 0.0 )
        v8 = 0.0;
      v9->fraction = v8;
      v9->plane.dist = v7->dist;
      v9->plane.normal.x = v7->normal.x;
      v9->plane.normal.y = v7->normal.y;
      v9->plane.normal.z = v7->normal.z;
      v9->plane.type = v7->type;
      texinfo = leadside->texinfo;
      if ( texinfo == -1 )
        v9->surface = nullptr;
      else
        v9->surface = &::texinfo.m_Memory.m_pMemory[texinfo];
      v9->contents = brush->contents;
    }
  }
  else
  {
LABEL_46:
    v9->startsolid = true;
    if ( !getout )
      v9->allsolid = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019BF0
// Name: void AddTexturedBrushWinding(struct winding_t __near *,class VMatrix const __near &,struct texinfo_s __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddTexturedBrushWinding(winding_t *w, const VMatrix *xform, texinfo_s *tx, int shadowMaterialIndex)
{
  winding_t *v4; // ecx
  int numpoints; // edi
  int v6; // eax
  float v7; // xmm6_4
  Vector *p; // edx
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm4_4
  float v12; // xmm0_4
  float v13; // xmm5_4
  float v14; // xmm5_4
  float *p_z; // ecx
  float v16; // xmm1_4
  float *v17; // edx
  float v18; // xmm7_4
  float v19; // xmm7_4
  float v20; // xmm7_4
  float v21; // xmm0_4
  Vector *v22; // ecx
  float v23; // xmm2_4
  float v24; // xmm3_4
  float v25; // xmm4_4
  float v26; // xmm6_4
  float v27; // xmm0_4
  float v28; // xmm5_4
  float v29; // xmm5_4
  float v30; // xmm1_4
  float *p_x; // ecx
  int v32; // edi
  const Vector2D *v33; // ebx
  Vector *v34; // eax
  float x; // xmm6_4
  float y; // xmm7_4
  float v37; // xmm0_4
  float v38; // xmm1_4
  float v39; // xmm5_4
  float v40; // xmm2_4
  float v41; // xmm4_4
  float v42; // xmm3_4
  float v43; // xmm1_4
  float v44; // xmm3_4
  float v45; // xmm4_4
  float v46; // xmm2_4
  float v47; // xmm5_4
  float v48; // xmm6_4
  float v49; // xmm7_4
  float v50; // xmm4_4
  float v51; // xmm5_4
  float v52; // xmm7_4
  float z; // xmm5_4
  float v54; // xmm3_4
  float v55; // xmm4_4
  float v56; // xmm5_4
  float v57; // xmm4_4
  float v58; // xmm5_4
  float v59; // xmm1_4
  float v60; // xmm2_4
  double v61; // st7
  int v62; // ecx
  unsigned __int16 v63; // dx
  Vector2D uv[64]; // [esp+Ch] [ebp-26Ch] BYREF
  float v65; // [esp+214h] [ebp-64h]
  Vector v1; // [esp+218h] [ebp-60h] BYREF
  Vector v2; // [esp+224h] [ebp-54h] BYREF
  Vector v0; // [esp+230h] [ebp-48h] BYREF
  float v69; // [esp+23Ch] [ebp-3Ch]
  float v70; // [esp+244h] [ebp-34h]
  Vector fullCoverage; // [esp+248h] [ebp-30h] BYREF
  float coverage; // [esp+254h] [ebp-24h]
  float v73; // [esp+258h] [ebp-20h]
  int mappingHeight; // [esp+25Ch] [ebp-1Ch] BYREF
  int mappingWidth; // [esp+260h] [ebp-18h] BYREF
  int j; // [esp+264h] [ebp-14h]
  float v77; // [esp+268h] [ebp-10h]
  float v78; // [esp+26Ch] [ebp-Ch]
  float v79; // [esp+270h] [ebp-8h]
  float v80; // [esp+274h] [ebp-4h]

  mappingWidth = 32;
  mappingHeight = 32;
  GetShadowTextureMapping(shadowTextureIndex: shadowMaterialIndex, pWidth: &mappingWidth, pHeight: &mappingHeight);
  v4 = w;
  numpoints = w->numpoints;
  v6 = 0;
  if ( w->numpoints >= 4 )
  {
    v7 = tx->textureVecsTexelsPerWorldUnits[1][3];
    p = w->p;
    v9 = tx->textureVecsTexelsPerWorldUnits[0][1];
    v10 = tx->textureVecsTexelsPerWorldUnits[0][0];
    v11 = tx->textureVecsTexelsPerWorldUnits[0][2];
    v78 = tx->textureVecsTexelsPerWorldUnits[0][3];
    v12 = 1.0 / (float)mappingWidth;
    v80 = tx->textureVecsTexelsPerWorldUnits[1][1];
    v13 = tx->textureVecsTexelsPerWorldUnits[1][0];
    v79 = v7;
    v77 = v13;
    v14 = tx->textureVecsTexelsPerWorldUnits[1][2];
    p_z = &p->z;
    v16 = 1.0 / (float)mappingHeight;
    v17 = &p[1].z;
    do
    {
      uv[v6].x = (float)((float)((float)((float)(*(p_z - 2) * v10) + (float)(*(p_z - 1) * v9)) + (float)(*p_z * v11))
                       + v78)
               * v12;
      uv[v6].y = (float)((float)((float)((float)(v77 * *(p_z - 2)) + (float)(v80 * *(p_z - 1))) + (float)(*p_z * v14))
                       + v79)
               * v16;
      v18 = v80;
      uv[v6 + 1].x = (float)((float)((float)((float)(p_z[1] * v10) + (float)(*(v17 - 1) * v9)) + (float)(*v17 * v11))
                           + v78)
                   * v12;
      uv[v6 + 1].y = (float)((float)((float)((float)(v77 * p_z[1]) + (float)(v18 * *(v17 - 1))) + (float)(v14 * *v17))
                           + v79)
                   * v16;
      v19 = v80;
      uv[v6 + 2].x = (float)((float)((float)((float)(p_z[4] * v10) + (float)(v17[2] * v9)) + (float)(v17[3] * v11)) + v78)
                   * v12;
      uv[v6 + 2].y = (float)((float)((float)((float)(v77 * p_z[4]) + (float)(v19 * v17[2])) + (float)(v14 * v17[3]))
                           + v79)
                   * v16;
      v20 = v80;
      uv[v6 + 3].x = (float)((float)((float)((float)(p_z[7] * v10) + (float)(v17[5] * v9)) + (float)(v17[6] * v11)) + v78)
                   * v12;
      uv[v6 + 3].y = (float)((float)((float)((float)(v77 * p_z[7]) + (float)(v20 * v17[5])) + (float)(v14 * v17[6]))
                           + v79)
                   * v16;
      v6 += 4;
      p_z += 12;
      v17 += 12;
    }
    while ( v6 < numpoints - 3 );
    v4 = w;
  }
  if ( v6 < numpoints )
  {
    v21 = tx->textureVecsTexelsPerWorldUnits[0][3];
    v22 = v4->p;
    v23 = tx->textureVecsTexelsPerWorldUnits[0][1];
    v24 = tx->textureVecsTexelsPerWorldUnits[0][0];
    v25 = tx->textureVecsTexelsPerWorldUnits[0][2];
    j = SLODWORD(tx->textureVecsTexelsPerWorldUnits[1][2]);
    v26 = tx->textureVecsTexelsPerWorldUnits[1][3];
    v78 = v21;
    v27 = 1.0 / (float)mappingWidth;
    v28 = tx->textureVecsTexelsPerWorldUnits[1][1];
    v79 = v26;
    v80 = v28;
    v29 = tx->textureVecsTexelsPerWorldUnits[1][0];
    v30 = 1.0 / (float)mappingHeight;
    p_x = &v22[v6].x;
    do
    {
      uv[v6].x = (float)((float)((float)((float)(p_x[1] * v23) + (float)(*p_x * v24)) + (float)(p_x[2] * v25)) + v78)
               * v27;
      uv[v6++].y = (float)((float)((float)((float)(p_x[1] * v80) + (float)(*p_x * v29)) + (float)(*(float *)&j * p_x[2]))
                         + v79)
                 * v30;
      p_x += 3;
    }
    while ( v6 < numpoints );
  }
  j = 2;
  if ( numpoints > 2 )
  {
    v32 = 2;
    v33 = &uv[2];
    do
    {
      v34 = w->p;
      x = v34->x;
      y = v34->y;
      v37 = xform->m[0][0];
      v38 = xform->m[0][1];
      v39 = xform->m[1][1];
      v40 = xform->m[2][1];
      v78 = xform->m[0][2];
      v41 = v78 * v34->z;
      v73 = v39;
      v42 = (float)(v37 * x) + (float)(v38 * y);
      v43 = xform->m[1][0];
      v44 = (float)(v42 + v41) + xform->m[0][3];
      v77 = xform->m[1][2];
      v45 = (float)((float)((float)(v43 * x) + (float)(v39 * y)) + (float)(v77 * v34->z)) + xform->m[1][3];
      v80 = xform->m[2][2];
      v79 = v40;
      v46 = xform->m[2][0];
      v47 = v46 * x;
      v48 = v79 * y;
      v49 = v80 * v34->z;
      v0.y = v45;
      v50 = xform->m[0][1];
      v51 = (float)((float)(v47 + v48) + v49) + xform->m[2][3];
      v0.x = v44;
      v0.z = v51;
      v52 = v34[v32 - 1].y;
      z = v34[v32 - 1].z;
      v69 = v34[v32 - 1].x;
      v54 = (float)((float)((float)(v37 * v69) + (float)(v50 * v52)) + (float)(v78 * z)) + xform->m[0][3];
      v70 = z;
      v55 = (float)((float)((float)(v43 * v69) + (float)(v73 * v52)) + (float)(v77 * z)) + xform->m[1][3];
      v56 = (float)((float)((float)(v46 * v69) + (float)(v79 * v52)) + (float)(v80 * z)) + xform->m[2][3];
      v1.x = v54;
      v1.y = v55;
      v1.z = v56;
      v57 = v34[v32].x;
      v58 = v34[v32].y;
      v65 = v34[v32].z;
      v59 = (float)((float)((float)(v43 * v57) + (float)(v73 * v58)) + (float)(v77 * v65)) + xform->m[1][3];
      v60 = (float)((float)((float)(v46 * v57) + (float)(v79 * v58)) + (float)(v80 * v65)) + xform->m[2][3];
      v2.x = (float)((float)((float)(v37 * v57) + (float)(v58 * xform->m[0][1])) + (float)(v78 * v65)) + xform->m[0][3];
      v2.y = v59;
      v2.z = v60;
      v61 = ComputeCoverageForTriangle(shadowTextureIndex: shadowMaterialIndex, t0: uv, t1: v33 - 1, t2: v33);
      coverage = v61;
      v62 = -1;
      v63 = 0;
      fullCoverage.x = 0.0;
      fullCoverage.y = 0.0;
      fullCoverage.z = 1.0;
      if ( v61 < 1.0 )
      {
        v62 = AddShadowTextureTriangle(shadowTextureIndex: shadowMaterialIndex, t0: uv, t1: v33 - 1, t2: v33);
        v63 = 1;
        fullCoverage.x = coverage;
      }
      RayTracingEnvironment::AddTriangle(
        this: &g_RtEnv,
        id: 0x2000000,
        v1: &v0,
        v2: &v1,
        v3: &v2,
        color: &fullCoverage,
        flags: v63,
        materialIndex: v62);
      ++v32;
      ++v33;
      ++j;
    }
    while ( j < w->numpoints );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A200
// Name: void AddBrushToRaytraceEnvironment(struct dbrush_t __near *,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddBrushToRaytraceEnvironment(dbrush_t *pBrush, const VMatrix *xform)
{
  dbrush_t *edi1; // edi
  int contents; // eax
  int numsides; // eax
  int v5; // esi
  const char *String; // eax
  int ShadowTexture; // eax
  bool v8; // cc
  int v9; // ebx
  int v10; // ecx
  int planenum; // eax
  dbrushside_t *v12; // ebx
  float dist; // xmm0_4
  winding_t *v14; // eax
  int v15; // ebx
  int v16; // ecx
  bool v17; // zf
  dbrushside_t *v18; // ecx
  int v19; // ebx
  int v20; // edi
  float *p_x; // ecx
  float v22; // xmm6_4
  float v23; // xmm7_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm5_4
  float v27; // xmm2_4
  float v28; // xmm4_4
  float v29; // xmm3_4
  float v30; // xmm1_4
  float v31; // xmm3_4
  float v32; // xmm4_4
  float v33; // xmm2_4
  float v34; // xmm5_4
  float v35; // xmm6_4
  float v36; // xmm7_4
  float v37; // xmm5_4
  Vector *p; // ecx
  float y; // xmm7_4
  float z; // xmm5_4
  float v41; // xmm3_4
  float v42; // xmm4_4
  float v43; // xmm5_4
  Vector *v44; // eax
  float v45; // xmm4_4
  float v46; // xmm5_4
  float v47; // xmm7_4
  float v48; // xmm1_4
  float v49; // xmm2_4
  int materialIndexList[256]; // [esp+14h] [ebp-464h]
  Vector v2; // [esp+414h] [ebp-64h] BYREF
  Vector v0; // [esp+420h] [ebp-58h] BYREF
  float x; // [esp+42Ch] [ebp-4Ch]
  float v54; // [esp+434h] [ebp-44h]
  Vector v1; // [esp+438h] [ebp-40h] BYREF
  Vector fullCoverage; // [esp+444h] [ebp-34h] BYREF
  float v57; // [esp+450h] [ebp-28h]
  texinfo_s *tx; // [esp+454h] [ebp-24h]
  float v59; // [esp+458h] [ebp-20h]
  float v60; // [esp+45Ch] [ebp-1Ch]
  float v61; // [esp+460h] [ebp-18h]
  float v62; // [esp+464h] [ebp-14h]
  float v63; // [esp+468h] [ebp-10h]
  winding_t *w; // [esp+46Ch] [ebp-Ch] BYREF
  int i; // [esp+470h] [ebp-8h]
  bool bTextureShadows; // [esp+477h] [ebp-1h]

  edi1 = pBrush;
  contents = pBrush->contents;
  bTextureShadows = false;
  if ( ((contents & 0x4081) != 0 || g_bTextureShadows && (contents & 8) != 0) && (contents & 0x20000000) == 0 )
  {
    if ( g_bTextureShadows && (contents & 8) != 0 )
    {
      numsides = pBrush->numsides;
      if ( (unsigned int)numsides < 0x100 )
      {
        v5 = 0;
        if ( numsides > 0 )
        {
          do
          {
            String = TexDataStringTable_GetString(stringID: dtexdata[texinfo.m_Memory.m_pMemory[word_11A6C4FA[4 * v5 + 4 * pBrush->firstside]].texdata].nameStringTableID);
            ShadowTexture = LoadShadowTexture(pMaterialName: String);
            materialIndexList[v5] = ShadowTexture;
            if ( ShadowTexture >= 0 )
              bTextureShadows = true;
            ++v5;
          }
          while ( v5 < pBrush->numsides );
        }
      }
    }
    v8 = pBrush->numsides <= 0;
    i = 0;
    if ( !v8 )
    {
      do
      {
        v9 = i + edi1->firstside;
        v10 = word_11A6C4FA[4 * v9];
        planenum = dbrushsides[v9].planenum;
        v12 = &dbrushsides[v9];
        planenum *= 5;
        dist = *(&::dist + planenum);
        tx = &texinfo.m_Memory.m_pMemory[v10];
        v14 = BaseWindingForPlane(normal: (Vector *)((char *)&dplanes + 4 * planenum), dist);
        w = v14;
        if ( (tx->flags & 4) == 0 && v12->dispinfo == 0 )
        {
          v15 = 0;
          if ( edi1->numsides <= 0 )
          {
LABEL_21:
            if ( v14 != nullptr )
            {
              if ( bTextureShadows && materialIndexList[i] >= 0 )
              {
                AddTexturedBrushWinding(w: v14, xform, tx, shadowMaterialIndex: materialIndexList[i]);
                v14 = w;
              }
              else
              {
                v19 = 2;
                fullCoverage.x = 1.0;
                fullCoverage.y = 1.0;
                fullCoverage.z = 1.0;
                if ( v14->numpoints > 2 )
                {
                  v20 = 2;
                  do
                  {
                    p_x = &v14->p->x;
                    v22 = *p_x;
                    v23 = p_x[1];
                    v24 = xform->m[0][1];
                    v25 = xform->m[0][0];
                    v26 = xform->m[1][1];
                    v27 = xform->m[2][1];
                    v59 = xform->m[0][2];
                    v28 = v59 * p_x[2];
                    v57 = v26;
                    v60 = v24;
                    v29 = (float)(v25 * v22) + (float)(v24 * v23);
                    v30 = xform->m[1][0];
                    v31 = (float)(v29 + v28) + xform->m[0][3];
                    v62 = xform->m[1][2];
                    v32 = (float)((float)((float)(v30 * v22) + (float)(v26 * v23)) + (float)(v62 * p_x[2]))
                        + xform->m[1][3];
                    v61 = xform->m[2][2];
                    v63 = v27;
                    v33 = xform->m[2][0];
                    v34 = v33 * v22;
                    v35 = v63 * v23;
                    v36 = v61 * p_x[2];
                    v0.y = v32;
                    v37 = (float)((float)(v34 + v35) + v36) + xform->m[2][3];
                    v0.x = v31;
                    v0.z = v37;
                    p = v14->p;
                    y = p[v20 - 1].y;
                    z = p[v20 - 1].z;
                    x = p[v20 - 1].x;
                    v41 = (float)((float)((float)(v25 * x) + (float)(v60 * y)) + (float)(v59 * z)) + xform->m[0][3];
                    v54 = z;
                    v42 = (float)((float)((float)(v30 * x) + (float)(v57 * y)) + (float)(v62 * z)) + xform->m[1][3];
                    v43 = (float)((float)((float)(v33 * x) + (float)(v63 * y)) + (float)(v61 * z)) + xform->m[2][3];
                    v1.x = v41;
                    v1.y = v42;
                    v1.z = v43;
                    v44 = v14->p;
                    v45 = v44[v20].x;
                    v46 = v44[v20].y;
                    v47 = v44[v20].z;
                    v48 = (float)((float)((float)(v30 * v45) + (float)(v57 * v46)) + (float)(v62 * v47))
                        + xform->m[1][3];
                    v49 = (float)((float)((float)(v33 * v45) + (float)(v63 * v46)) + (float)(v61 * v47))
                        + xform->m[2][3];
                    v2.x = (float)((float)((float)(v25 * v45) + (float)(v60 * v46)) + (float)(v59 * v47))
                         + xform->m[0][3];
                    v2.y = v48;
                    v2.z = v49;
                    RayTracingEnvironment::AddTriangle(
                      this: &g_RtEnv,
                      id: 0x2000000,
                      v1: &v0,
                      v2: &v1,
                      v3: &v2,
                      color: &fullCoverage);
                    v14 = w;
                    ++v19;
                    ++v20;
                  }
                  while ( v19 < w->numpoints );
                  edi1 = pBrush;
                }
              }
              FreeWinding(w: v14);
            }
          }
          else
          {
            while ( v14 != nullptr )
            {
              if ( i != v15 )
              {
                v16 = v15 + edi1->firstside;
                v17 = byte_11A6C4FE[8 * v16] == 0;
                v18 = &dbrushsides[v16];
                if ( v17 )
                {
                  ChopWindingInPlace(
                    inout: &w,
                    normal: (Vector *)((char *)&dplanes + 20 * (v18->planenum ^ 1)),
                    dist: *((float *)&dplanes + 5 * (v18->planenum ^ 1) + 3),
                    epsilon: 0.0);
                  v14 = w;
                }
              }
              if ( ++v15 >= edi1->numsides )
                goto LABEL_21;
            }
          }
        }
        ++i;
      }
      while ( i < edi1->numsides );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A630
// Name: float TraceLeafBrushes(int,class Vector const __near &,class Vector const __near &,class CBaseTrace __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl TraceLeafBrushes(int leafIndex, const Vector *start, const Vector *end, CBaseTrace *traceOut)
{
  dleaf_t *v4; // esi
  float fraction; // xmm0_4
  bool startsolid; // cl
  int v7; // edi
  unsigned __int8 type; // dl
  float x; // xmm1_4
  unsigned __int8 signbits; // dl
  float y; // xmm1_4
  __int16 v13; // dx
  dbrush_t *v14; // [esp-4h] [ebp-80h]
  CToolTrace trace; // [esp+Ch] [ebp-70h] BYREF
  Vector zeroExtents; // [esp+70h] [ebp-Ch] BYREF

  v4 = &dleafs[leafIndex];
  memset(dst: (unsigned __int8 *)&trace, value: 0, count: sizeof(trace));
  fraction = 1.0;
  startsolid = false;
  v7 = 0;
  trace.ispoint = 1;
  trace.startsolid = false;
  trace.fraction = 1.0;
  if ( v4->numleafbrushes == 0 )
  {
LABEL_6:
    type = trace.plane.type;
    traceOut->startpos = trace.startpos;
    traceOut->endpos = trace.endpos;
    x = trace.plane.normal.x;
    traceOut->plane.type = type;
    signbits = trace.plane.signbits;
    traceOut->plane.normal.x = x;
    y = trace.plane.normal.y;
    traceOut->plane.signbits = signbits;
    v13 = *(_WORD *)trace.plane.pad;
    traceOut->plane.normal.y = y;
    traceOut->plane.normal.z = trace.plane.normal.z;
    traceOut->plane.dist = trace.plane.dist;
    *(_WORD *)traceOut->plane.pad = v13;
    traceOut->contents = trace.contents;
    traceOut->dispFlags = trace.dispFlags;
    LOBYTE(v13) = trace.allsolid;
    traceOut->fraction = fraction;
    traceOut->allsolid = v13;
    traceOut->startsolid = startsolid;
    return 1.0;
  }
  while ( 1 )
  {
    if ( (dbrushes[dleafbrushes[v7 + v4->firstleafbrush]].contents & 0x4081) != 0 )
    {
      v14 = &dbrushes[dleafbrushes[v7 + v4->firstleafbrush]];
      zeroExtents = vec3_origin;
      DM_ClipBoxToBrush(&trace, mins: &zeroExtents, maxs: &zeroExtents, p1: start, p2: end, brush: v14);
      fraction = trace.fraction;
      if ( trace.fraction != 1.0 )
        break;
      startsolid = trace.startsolid;
      if ( trace.startsolid )
        goto LABEL_8;
    }
    if ( ++v7 >= v4->numleafbrushes )
      goto LABEL_6;
  }
  if ( trace.startsolid )
LABEL_8:
    trace.fraction = 0.0;
  CBaseTrace::operator=(this: traceOut, __that: &trace);
  return trace.fraction;
}

//------------------------------------------------------------------------------
// Address: 0x1001A7D0
// Name: void TestLine_DoesHitSky(class FourVectors const __near &,class FourVectors const __near &,union __m128 __near *,bool,int,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall TestLine_DoesHitSky(
        int a1@<ebp>,
        const FourVectors *start,
        const FourVectors *stop,
        __m128 *pFractionVisible,
        bool canRecurse,
        int static_prop_to_skip,
        bool bDoDebug)
{
  __m128 y; // xmm3
  __m128 z; // xmm4
  __m128 v9; // xmm1
  __m128 v10; // xmm5
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  __m128 v13; // xmm4
  __m128 v14; // xmm1
  __m128 v15; // xmm0
  __m128 v16; // xmm0
  __m128 v17; // xmm3
  __m128 v18; // xmm4
  __m128 v19; // xmm5
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  __m128 v22; // xmm0
  __m128 v23; // xmm6
  __m128 v24; // xmm6
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  __m128 v27; // xmm6
  int v28; // eax
  int v29; // eax
  __m128 v30; // xmm0
  int *v31; // esi
  __m128 v32; // xmm5
  __m128 v33; // xmm6
  __m128 v34; // xmm3
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  __m128 v37; // xmm1
  _BYTE v38[208]; // [esp-Ch] [ebp-18Ch] OVERLAPPED BYREF
  int v39; // [esp+C4h] [ebp-BCh] BYREF
  RayTracingResult rt_result; // [esp+D0h] [ebp-B0h]
  CCoverageCountTexture coverageCallback_4; // [esp+124h] [ebp-5Ch] OVERLAPPED
  __m128 v42; // [esp+144h] [ebp-3Ch] OVERLAPPED
  int v43; // [esp+160h] [ebp-20h]
  _BYTE v44[24]; // [esp+164h] [ebp-1Ch] OVERLAPPED BYREF
  _UNKNOWN *retaddr; // [esp+180h] [ebp+0h]

  *(_DWORD *)&v44[16] = a1;
  *(_DWORD *)&v44[20] = retaddr;
  y = stop->y;
  z = stop->z;
  v9 = start->y;
  v10 = start->z;
  v11 = _mm_sub_ps(stop->x, start->x);
  *(__m128 *)v38 = start->x;
  v12 = _mm_sub_ps(y, v9);
  *(__m128 *)&v38[16] = v9;
  v13 = _mm_sub_ps(z, v10);
  v14 = _mm_sqrt_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v12, v12), _mm_mul_ps(v11, v11)), _mm_mul_ps(v13, v13)));
  *(__m128 *)&v38[32] = v10;
  v15 = _mm_rcp_ps(v14);
  v16 = _mm_sub_ps(_mm_add_ps(v15, v15), _mm_mul_ps(_mm_mul_ps(v15, v15), v14));
  v42 = v14;
  *(__m128 *)&v38[48] = _mm_mul_ps(v11, v16);
  *(__m128 *)&v38[64] = _mm_mul_ps(v12, v16);
  *(__m128 *)&v38[80] = _mm_mul_ps(v13, v16);
  *(__m128 *)&coverageCallback_4.__vftable = Four_Zeros;
  rt_result.HitDistance.m128_i32[1] = (int)&CCoverageCountTexture::`vftable';
  RayTracingEnvironment::Trace4Rays(this: &g_RtEnv, TMin: Four_Zeros, TMax: v14);
  if ( bDoDebug )
    WriteTrace(pFileName: "trace.txt", rays: (const FourRays *)v38, result: (const RayTracingResult *)&v39);
  *(_DWORD *)v44 = 0;
  if ( rt_result.surface_normal.z.m128_i32[1] != -1
    && v42.m128_f32[0] > *(float *)&rt_result.HitIds[1]
    && (g_RtEnv.OptimizedTriangleList.m_Memory.m_pMemory[rt_result.surface_normal.z.m128_i32[1] >> (*((int *)&g_RtEnv.OptimizedTriangleList.m_Memory + 2) >> 27)][rt_result.surface_normal.z.m128_i32[1] & ((32 * *((_DWORD *)&g_RtEnv.OptimizedTriangleList.m_Memory + 2)) >> 5)].m_Data.m_IntersectData.m_nTriangleID
      & 0x1000000) == 0 )
  {
    *(_DWORD *)v44 = 1065353216;
  }
  *(_DWORD *)&v44[4] = 0;
  if ( rt_result.surface_normal.z.m128_i32[2] != -1
    && v42.m128_f32[1] > *(float *)&rt_result.HitIds[2]
    && (g_RtEnv.OptimizedTriangleList.m_Memory.m_pMemory[rt_result.surface_normal.z.m128_i32[2] >> (*((int *)&g_RtEnv.OptimizedTriangleList.m_Memory + 2) >> 27)][rt_result.surface_normal.z.m128_i32[2] & ((32 * *((_DWORD *)&g_RtEnv.OptimizedTriangleList.m_Memory + 2)) >> 5)].m_Data.m_IntersectData.m_nTriangleID
      & 0x1000000) == 0 )
  {
    *(_DWORD *)&v44[4] = 1065353216;
  }
  *(_DWORD *)&v44[8] = 0;
  if ( rt_result.surface_normal.z.m128_i32[3] != -1
    && v42.m128_f32[2] > *(float *)&rt_result.HitIds[3]
    && (g_RtEnv.OptimizedTriangleList.m_Memory.m_pMemory[rt_result.surface_normal.z.m128_i32[3] >> (*((int *)&g_RtEnv.OptimizedTriangleList.m_Memory + 2) >> 27)][rt_result.surface_normal.z.m128_i32[3] & ((32 * *((_DWORD *)&g_RtEnv.OptimizedTriangleList.m_Memory + 2)) >> 5)].m_Data.m_IntersectData.m_nTriangleID
      & 0x1000000) == 0 )
  {
    *(_DWORD *)&v44[8] = 1065353216;
  }
  *(_DWORD *)&v44[12] = 0;
  if ( rt_result.HitIds[0] != -1
    && v42.m128_f32[3] > rt_result.HitDistance.m128_f32[0]
    && (g_RtEnv.OptimizedTriangleList.m_Memory.m_pMemory[rt_result.HitIds[0] >> (*((int *)&g_RtEnv.OptimizedTriangleList.m_Memory
                                                                                 + 2) >> 27)][rt_result.HitIds[0]
                                                                                            & ((32
                                                                                              * *((_DWORD *)&g_RtEnv.OptimizedTriangleList.m_Memory
                                                                                                + 2)) >> 5)].m_Data.m_IntersectData.m_nTriangleID
      & 0x1000000) == 0 )
  {
    *(_DWORD *)&v44[12] = 1065353216;
  }
  v17 = *(__m128 *)v44;
  v42 = *(__m128 *)v44;
  if ( g_bTextureShadows )
  {
    v17 = _mm_max_ps(*(__m128 *)v44, *(__m128 *)&coverageCallback_4.__vftable);
    v42 = v17;
  }
  v18 = Four_Ones;
  if ( _mm_movemask_ps(_mm_cmple_ps(Four_Ones, v17)) != 15 && canRecurse && !g_bNoSkyRecurse )
  {
    v19 = _mm_sub_ps(stop->x, start->x);
    v20 = _mm_sub_ps(stop->y, start->y);
    v21 = _mm_sub_ps(stop->z, start->z);
    v22 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v19, v19), _mm_mul_ps(v20, v20)), _mm_mul_ps(v21, v21));
    v23 = _mm_rsqrt_ps(v22);
    v24 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(Four_Threes, _mm_mul_ps(_mm_mul_ps(v23, v23), v22)), v23), Four_PointFives);
    v25 = _mm_mul_ps(v20, v24);
    v26 = _mm_mul_ps(v21, v24);
    *(_DWORD *)&v44[4] = start->x.m128_i32[0];
    *(_DWORD *)&v44[8] = start->y.m128_i32[0];
    v27 = _mm_mul_ps(v24, v19);
    *(_DWORD *)&v44[12] = start->z.m128_i32[0];
    v28 = PointLeafnum_r(point: (const Vector *)&v44[4], ndxNode: 0);
    if ( v28 >= 0 )
    {
      v29 = (__int16)(word_1135AAB6[16 * v28] << 7) >> 7;
      if ( v29 >= 0 && v29 < numareas && area_sky_cameras[v29] < 0 )
      {
        v43 = 0;
        if ( num_sky_cameras > 0 )
        {
          v30 = _mm_shuffle_ps((__m128)0x475DB3D7u, (__m128)0x475DB3D7u, 0);
          *(__m128 *)v44 = _mm_mul_ps(v30, v27);
          *(__m128 *)&v38[192] = _mm_mul_ps(v25, v30);
          coverageCallback_4.m_coverage = _mm_mul_ps(v26, v30);
          v31 = &dword_11358EC0;
          do
          {
            v32 = _mm_shuffle_ps((__m128)(unsigned int)*(v31 - 1), (__m128)(unsigned int)*(v31 - 1), 0);
            v33 = _mm_shuffle_ps((__m128)(unsigned int)*v31, (__m128)(unsigned int)*v31, 0);
            v34 = _mm_shuffle_ps((__m128)(unsigned int)v31[1], (__m128)(unsigned int)v31[1], 0);
            v35 = _mm_mul_ps(start->y, v34);
            v36 = _mm_mul_ps(start->z, v34);
            *(__m128 *)&v38[96] = _mm_add_ps(
                                    _mm_mul_ps(v34, start->x),
                                    _mm_shuffle_ps(
                                      (__m128)(unsigned int)*(v31 - 2),
                                      (__m128)(unsigned int)*(v31 - 2),
                                      0));
            v37 = _mm_add_ps(v35, v32);
            *(__m128 *)&v38[160] = _mm_add_ps(*(__m128 *)&v38[192], v37);
            *(__m128 *)&v38[112] = v37;
            *(__m128 *)&v38[128] = _mm_add_ps(v36, v33);
            *(__m128 *)&v38[144] = _mm_add_ps(*(__m128 *)v44, *(__m128 *)&v38[96]);
            *(__m128 *)&v38[176] = _mm_add_ps(coverageCallback_4.m_coverage, *(__m128 *)&v38[128]);
            TestLine_DoesHitSky(
              start: (const FourVectors *)&v38[96],
              stop: (const FourVectors *)&v38[144],
              pFractionVisible,
              canRecurse: false,
              static_prop_to_skip,
              bDoDebug);
            v18 = Four_Ones;
            v17 = _mm_sub_ps(_mm_add_ps(Four_Ones, v42), *pFractionVisible);
            v31 += 6;
            v42 = v17;
            ++v43;
          }
          while ( v43 < num_sky_cameras );
        }
      }
    }
  }
  *pFractionVisible = _mm_sub_ps(v18, _mm_min_ps(_mm_max_ps(v17, Four_Zeros), v18));
}

//------------------------------------------------------------------------------
// Address: 0x1001AC60
// Name: void GetBrushes_r(int,class CUtlVector<int,class CUtlMemory<int,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetBrushes_r(int node, CUtlVector<int,CUtlMemory<int,int> > *list)
{
  int j; // edi
  dnode_t *v3; // edi
  int v4; // edx
  int m_Size; // edi
  int v6; // ebx
  int v7; // eax
  int *m_pMemory; // ecx
  int m_nAllocationCount; // eax
  int *v10; // ecx
  int v11; // eax
  int *v12; // eax
  int v13; // [esp+8h] [ebp-4h]
  int i; // [esp+14h] [ebp+8h]

  for ( j = node; j >= 0; j = v3->children[1] )
  {
    v3 = &dnodes[j];
    GetBrushes_r(node: v3->children[0], list);
  }
  v4 = 32 * (-1 - j);
  i = 0;
  v13 = v4;
  if ( *(__int16 *)((char *)&word_1135AACA + v4) != 0 )
  {
    do
    {
      m_Size = list->m_Size;
      v6 = dleafbrushes[i + *(unsigned __int16 *)((char *)&word_1135AAC8 + v4)];
      v7 = 0;
      if ( m_Size <= 0 )
        goto LABEL_10;
      m_pMemory = list->m_Memory.m_pMemory;
      while ( *m_pMemory != v6 )
      {
        ++v7;
        ++m_pMemory;
        if ( v7 >= m_Size )
          goto LABEL_10;
      }
      if ( v7 < 0 )
      {
LABEL_10:
        m_nAllocationCount = list->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
        {
          CUtlMemory<int,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)list, num: m_Size - m_nAllocationCount + 1);
          v4 = v13;
        }
        ++list->m_Size;
        v10 = list->m_Memory.m_pMemory;
        v11 = list->m_Size - m_Size - 1;
        list->m_pElements = list->m_Memory.m_pMemory;
        if ( v11 > 0 )
        {
          _V_memmove(dest: &v10[m_Size + 1], src: &v10[m_Size], count: 4 * v11);
          v4 = v13;
        }
        v12 = &list->m_Memory.m_pMemory[m_Size];
        if ( v12 != nullptr )
          *v12 = v6;
      }
      ++i;
    }
    while ( i < *(unsigned __int16 *)((char *)&word_1135AACA + v4) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001AD50
// Name: void AddBrushes(struct dmodel_t __near *,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddBrushes(dmodel_t *pModel, const VMatrix *xform)
{
  int i; // esi
  int *m_pMemory; // eax
  int headnode; // [esp-Ch] [ebp-24h]
  CUtlVector<int,CUtlMemory<int,int> > brushList; // [esp+4h] [ebp-14h] BYREF

  if ( pModel != nullptr )
  {
    headnode = pModel->headnode;
    memset(&brushList, 0, sizeof(brushList));
    GetBrushes_r(node: headnode, list: &brushList);
    for ( i = 0; i < brushList.m_Size; ++i )
      AddBrushToRaytraceEnvironment(pBrush: &dbrushes[brushList.m_Memory.m_pMemory[i]], xform);
    m_pMemory = brushList.m_Memory.m_pMemory;
    brushList.m_Size = 0;
    if ( brushList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( brushList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: brushList.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        brushList.m_Memory.m_pMemory = nullptr;
      }
      brushList.m_Memory.m_nAllocationCount = 0;
    }
    brushList.m_pElements = m_pMemory;
    if ( brushList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001AE00
// Name: void ExtractBrushEntityShadowCasters(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ExtractBrushEntityShadowCasters()
{
  int v0; // ebx
  entity_t *v1; // esi
  char *v2; // edi
  int v3; // eax
  dmodel_t *v4; // eax
  VMatrix xform; // [esp+4h] [ebp-58h] BYREF
  Vector origin; // [esp+44h] [ebp-18h] BYREF
  QAngle angles; // [esp+50h] [ebp-Ch] BYREF

  v0 = 0;
  if ( num_entities > 0 )
  {
    v1 = entities;
    do
    {
      if ( IntForKey(ent: v1, key: "vrad_brush_cast_shadows") != 0 )
      {
        GetVectorForKey(ent: v1, key: "origin", angle: (QAngle *)&origin);
        GetVectorForKey(ent: v1, key: "angles", angle: &angles);
        VMatrix::SetupMatrixOrgAngles(this: &xform, &origin, vAngles: &angles);
        v2 = ValueForKey(ent: v1, key: "model");
        if ( _V_strlen(str: v2) <= 1 || (v3 = atol(nptr: v2 + 1)) <= 0 || v3 >= nummodels )
          v4 = nullptr;
        else
          v4 = &dmodels[v3];
        AddBrushes(pModel: v4, &xform);
      }
      ++v0;
      ++v1;
    }
    while ( v0 < num_entities );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001AED0
// Name: void AddBrushesForRayTrace(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddBrushesForRayTrace()
{
  int j; // esi
  int v1; // eax
  dface_t *v2; // esi
  int v3; // edx
  float *p_z; // ecx
  int v5; // eax
  signed __int16 v6; // ax
  dvertex_t *v7; // eax
  int v8; // ebx
  const Vector *v9; // edi
  int *m_pMemory; // eax
  Vector points[64]; // [esp+4h] [ebp-364h] BYREF
  VMatrix identity; // [esp+304h] [ebp-64h] BYREF
  Vector fullCoverage; // [esp+344h] [ebp-24h] BYREF
  int i; // [esp+350h] [ebp-18h]
  CUtlVector<int,CUtlMemory<int,int> > brushList; // [esp+354h] [ebp-14h] BYREF

  if ( nummodels != 0 )
  {
    MatrixSetIdentity(dst: &identity);
    memset(&brushList, 0, sizeof(brushList));
    GetBrushes_r(node: dmodels[0].headnode, list: &brushList);
    for ( j = 0; j < brushList.m_Size; ++j )
      AddBrushToRaytraceEnvironment(pBrush: &dbrushes[brushList.m_Memory.m_pMemory[j]], xform: &identity);
    v1 = 0;
    for ( i = 0; v1 < dmodels[0].numfaces; i = v1 )
    {
      v2 = &g_pFaces[dmodels[0].firstface + v1];
      if ( (texinfo.m_Memory.m_pMemory[v2->texinfo].flags & 4) != 0 )
      {
        v3 = 0;
        if ( v2->numedges > 0 )
        {
          p_z = &points[0].z;
          do
          {
            v5 = dsurfedges[v3 + v2->firstedge];
            if ( v5 >= 0 )
              v6 = dedges[v5].v[0];
            else
              v6 = *((_WORD *)&unk_1157EAB2 - 2 * v5);
            v7 = &dvertexes[v6];
            ++v3;
            p_z += 3;
            *(p_z - 5) = v7->point.x;
            *(p_z - 4) = v7->point.y;
            *(p_z - 3) = v7->point.z;
          }
          while ( v3 < v2->numedges );
        }
        v8 = 2;
        if ( v2->numedges > 2 )
        {
          v9 = &points[2];
          do
          {
            fullCoverage.x = 1.0;
            RayTracingEnvironment::AddTriangle(
              this: &g_RtEnv,
              id: 0x1000000,
              v1: points,
              v2: v9 - 1,
              v3: v9,
              color: &fullCoverage);
            ++v8;
            ++v9;
          }
          while ( v8 < v2->numedges );
        }
      }
      v1 = i + 1;
    }
    m_pMemory = brushList.m_Memory.m_pMemory;
    brushList.m_Size = 0;
    if ( brushList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( brushList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: brushList.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        brushList.m_Memory.m_pMemory = nullptr;
      }
      brushList.m_Memory.m_nAllocationCount = 0;
    }
    brushList.m_pElements = m_pMemory;
    if ( brushList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}
