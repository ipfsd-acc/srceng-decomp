// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vrad/radial.cpp
// Functions: 15
// ============================================================

#include "utils\vrad\radial.h"

//------------------------------------------------------------------------------
// Address: 0x100152C0
// Name: public: void Vector2D::Init(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Vector2D::Init(Vector2D *this, float ix, float iy)
{
  this->x = ix;
  this->y = iy;
}

//------------------------------------------------------------------------------
// Address: 0x100152E0
// Name: void WorldToLuxelSpace(struct lightinfo_t const __near *,class Vector const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WorldToLuxelSpace(const lightinfo_t *l, const Vector *world, Vector2D *coord)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  dface_t *face; // ecx

  v3 = world->x - l->luxelOrigin.x;
  v4 = world->y - l->luxelOrigin.y;
  v5 = world->z - l->luxelOrigin.z;
  face = l->face;
  coord->x = (float)((float)((float)(l->worldToLuxelSpace[0].y * v4) + (float)(l->worldToLuxelSpace[0].x * v3))
                   + (float)(l->worldToLuxelSpace[0].z * v5))
           - (float)face->m_LightmapTextureMinsInLuxels[0];
  coord->y = (float)((float)((float)(l->worldToLuxelSpace[1].y * v4) + (float)(l->worldToLuxelSpace[1].x * v3))
                   + (float)(l->worldToLuxelSpace[1].z * v5))
           - (float)face->m_LightmapTextureMinsInLuxels[1];
}

//------------------------------------------------------------------------------
// Address: 0x10015380
// Name: void LuxelSpaceToWorld(struct lightinfo_t const __near *,float,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LuxelSpaceToWorld(const lightinfo_t *l, float s, float t, Vector *world)
{
  float v4; // xmm0_4
  float v5; // xmm3_4
  float v6; // xmm4_4
  float v7; // xmm1_4

  v4 = (float)l->face->m_LightmapTextureMinsInLuxels[0] + s;
  v5 = (float)(l->luxelToWorldSpace[0].y * v4) + l->luxelOrigin.y;
  v6 = (float)(l->luxelToWorldSpace[0].z * v4) + l->luxelOrigin.z;
  v7 = (float)l->face->m_LightmapTextureMinsInLuxels[1] + t;
  world->x = (float)(v7 * l->luxelToWorldSpace[1].x)
           + (float)((float)(l->luxelToWorldSpace[0].x * v4) + l->luxelOrigin.x);
  world->y = (float)(l->luxelToWorldSpace[1].y * v7) + v5;
  world->z = (float)(l->luxelToWorldSpace[1].z * v7) + v6;
}

//------------------------------------------------------------------------------
// Address: 0x10015410
// Name: void LuxelSpaceToWorld(struct lightinfo_t const __near *,union __m128,union __m128,class FourVectors __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall LuxelSpaceToWorld(__m128 s@<xmm0>, __m128 t@<xmm1>, unsigned int *a3, __m128 *a4)
{
  __m128 v5; // xmm3
  __m128 v6; // xmm4
  __m128 v7; // xmm5
  __m128 v8; // xmm6
  __m128 v9; // xmm7
  __m128 v10; // xmm2
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm0
  __m128 v14; // xmm2
  __m128 v15; // xmm3

  v5 = _mm_shuffle_ps((__m128)a3[10], (__m128)a3[10], 0);
  *a4 = v5;
  v6 = _mm_shuffle_ps((__m128)a3[11], (__m128)a3[11], 0);
  a4[1] = v6;
  v7 = _mm_shuffle_ps((__m128)a3[12], (__m128)a3[12], 0);
  a4[2] = v7;
  v8 = (__m128)a3[20];
  v9 = (__m128)a3[21];
  v10 = 0;
  v10.m128_f32[0] = (float)*(int *)(a3[26] + 28);
  v11 = _mm_add_ps(_mm_shuffle_ps(v10, v10, 0), s);
  *a4 = _mm_add_ps(v5, _mm_mul_ps(_mm_shuffle_ps((__m128)a3[19], (__m128)a3[19], 0), v11));
  a4[1] = _mm_add_ps(v6, _mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), v11));
  a4[2] = _mm_add_ps(v7, _mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), v11));
  v12 = 0;
  v12.m128_f32[0] = (float)*(int *)(a3[26] + 32);
  v13 = _mm_add_ps(_mm_shuffle_ps(v12, v12, 0), t);
  v14 = _mm_mul_ps(_mm_shuffle_ps((__m128)a3[23], (__m128)a3[23], 0), v13);
  v15 = _mm_mul_ps(_mm_shuffle_ps((__m128)a3[24], (__m128)a3[24], 0), v13);
  *a4 = _mm_add_ps(*a4, _mm_mul_ps(_mm_shuffle_ps((__m128)a3[22], (__m128)a3[22], 0), v13));
  a4[1] = _mm_add_ps(a4[1], v14);
  a4[2] = _mm_add_ps(a4[2], v15);
}

//------------------------------------------------------------------------------
// Address: 0x10015520
// Name: void AddDirectToRadial(struct radial_s __near *,class Vector const __near &,class Vector2D const __near &,class Vector2D const __near &,struct LightingValue_t const __near * const,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddDirectToRadial(
        radial_s *rad,
        const Vector *pnt,
        const Vector2D *coordmins,
        const Vector2D *coordmaxs,
        const LightingValue_t *light,
        bool hasBumpmap,
        bool neighborHasBumpmap)
{
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  int v12; // ebx
  int v13; // edx
  int v14; // esi
  float v15; // xmm5_4
  float v16; // xmm0_4
  double v17; // xmm0_8
  float v18; // xmm4_4
  float v19; // xmm3_4
  float v20; // xmm0_4
  double v21; // xmm0_8
  float v22; // xmm2_4
  float v23; // xmm0_4
  double v24; // xmm0_8
  float v25; // xmm1_4
  float v26; // xmm0_4
  double v27; // xmm0_8
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  int v31; // esi
  float z; // xmm3_4
  int v33; // edi
  float v34; // xmm4_4
  float *v35; // edi
  float v36; // xmm4_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm3_4
  int v40; // edi
  float v41; // xmm1_4
  float *v42; // edi
  float v43; // xmm2_4
  float v44; // xmm3_4
  int v45; // edi
  float v46; // xmm1_4
  float *v47; // edi
  float v48; // xmm2_4
  float v49; // xmm3_4
  int v50; // edi
  float v51; // xmm1_4
  float m_flDirectSunAmount; // xmm1_4
  float y; // xmm3_4
  float v54; // xmm4_4
  int v55; // edi
  float v56; // xmm7_4
  float *v57; // edi
  float v58; // xmm2_4
  float v59; // xmm3_4
  float v60; // xmm4_4
  int v61; // edi
  float v62; // xmm2_4
  float *v63; // edi
  float v64; // xmm3_4
  float v65; // xmm4_4
  int v66; // edi
  float v67; // xmm7_4
  float v68; // xmm1_4
  float coord; // [esp+Ch] [ebp-10h]
  float coord_4; // [esp+10h] [ebp-Ch]
  int t_min; // [esp+14h] [ebp-8h]
  int s; // [esp+18h] [ebp-4h]
  int s_max; // [esp+24h] [ebp+8h]
  int t_max; // [esp+28h] [ebp+Ch]

  v8 = pnt->x - rad->l.luxelOrigin.x;
  v9 = pnt->y - rad->l.luxelOrigin.y;
  v10 = pnt->z - rad->l.luxelOrigin.z;
  coord = (float)((float)((float)(rad->l.worldToLuxelSpace[0].y * v9) + (float)(rad->l.worldToLuxelSpace[0].x * v8))
                + (float)(rad->l.worldToLuxelSpace[0].z * v10))
        - (float)rad->l.face->m_LightmapTextureMinsInLuxels[0];
  v11 = (float)((float)((float)(rad->l.worldToLuxelSpace[1].y * v9) + (float)(v8 * rad->l.worldToLuxelSpace[1].x))
              + (float)(rad->l.worldToLuxelSpace[1].z * v10))
      - (float)rad->l.face->m_LightmapTextureMinsInLuxels[1];
  s_max = (int)(float)(coordmaxs->x + 0.99989998) + 1;
  v12 = (int)(float)(coordmaxs->y + 0.99989998) + 1;
  coord_4 = v11;
  t_max = v12;
  v13 = (int)coordmins->y <= 0 ? 0 : (int)coordmins->y;
  t_min = v13;
  if ( s_max >= rad->w )
    s_max = rad->w;
  if ( v12 >= rad->h )
  {
    t_max = rad->h;
    v12 = t_max;
  }
  v14 = (int)coordmins->x <= 0 ? 0 : (int)coordmins->x;
  s = v14;
  if ( v14 >= s_max )
    return;
  do
  {
    if ( v13 >= v12 )
      goto LABEL_35;
    v15 = (float)v14;
    do
    {
      v16 = coordmins->x - v15;
      if ( v16 <= -1.0 )
        v17 = -1.0;
      else
        v17 = v16;
      v18 = v17;
      v19 = (float)v13;
      v20 = coordmins->y - (float)v13;
      if ( v20 <= -1.0 )
        v21 = -1.0;
      else
        v21 = v20;
      v22 = v21;
      v23 = coordmaxs->x - v15;
      if ( v23 >= 1.0 )
        v24 = 1.0;
      else
        v24 = v23;
      v25 = v24;
      v26 = coordmaxs->y - v19;
      if ( v26 >= 1.0 )
        v27 = 1.0;
      else
        v27 = v26;
      v28 = (float)((float)v27 - v22) * (float)(v25 - v18);
      if ( v28 > 0.001 )
      {
        LODWORD(v29) = COERCE_UNSIGNED_INT(coord - v15) & _mask__AbsFloat_;
        if ( v29 <= COERCE_FLOAT(COERCE_UNSIGNED_INT(coord_4 - v19) & _mask__AbsFloat_) )
          LODWORD(v29) = COERCE_UNSIGNED_INT(coord_4 - v19) & _mask__AbsFloat_;
        if ( v29 >= 0.1 )
          v30 = v28 / v29;
        else
          v30 = v28 * 10.0;
        v31 = s + v13 * rad->w;
        z = light->m_vecLighting.z;
        v33 = 16 * (v31 + 4104);
        v34 = *(float *)((char *)&rad->facenum + v33);
        v35 = (float *)((char *)&rad->facenum + v33);
        v36 = v34 + (float)(light->m_vecLighting.x * v30);
        v35[1] = v35[1] + (float)(light->m_vecLighting.y * v30);
        v37 = v35[2] + (float)(z * v30);
        *v35 = v36;
        v35[2] = v37;
        if ( hasBumpmap )
        {
          if ( !neighborHasBumpmap )
          {
            v35[3] = (float)(v30 * light->m_flDirectSunAmount) + v35[3];
            y = light->m_vecLighting.y;
            v54 = light->m_vecLighting.z;
            v55 = 16 * (v31 + 20488);
            v56 = *(float *)((char *)&rad->facenum + v55);
            v57 = (float *)((char *)&rad->facenum + v55);
            v58 = v57[1];
            *v57 = v56 + (float)(light->m_vecLighting.x * (float)(v30 * 0.57735026));
            v57[1] = v58 + (float)(y * (float)(v30 * 0.57735026));
            v57[2] = v57[2] + (float)(v54 * (float)(v30 * 0.57735026));
            v57[3] = (float)((float)(v30 * 0.57735026) * light->m_flDirectSunAmount) + v57[3];
            v59 = light->m_vecLighting.y;
            v60 = light->m_vecLighting.z;
            v61 = 16 * (v31 + 36872);
            *(float *)((char *)&rad->facenum + v61) = *(float *)((char *)&rad->facenum + v61)
                                                    + (float)(light->m_vecLighting.x * (float)(v30 * 0.57735026));
            v62 = *(float *)((char *)&rad->l.facedist + v61);
            v63 = (float *)((char *)&rad->facenum + v61);
            v63[1] = v62 + (float)(v59 * (float)(v30 * 0.57735026));
            v63[2] = v63[2] + (float)(v60 * (float)(v30 * 0.57735026));
            v63[3] = (float)((float)(v30 * 0.57735026) * light->m_flDirectSunAmount) + v63[3];
            v64 = light->m_vecLighting.y;
            v65 = light->m_vecLighting.z;
            v66 = 16 * (v31 + 53256);
            v67 = *(float *)((char *)&rad->facenum + v66);
            v35 = (float *)((char *)&rad->facenum + v66);
            *v35 = v67 + (float)(light->m_vecLighting.x * (float)(v30 * 0.57735026));
            v35[1] = v35[1] + (float)(v64 * (float)(v30 * 0.57735026));
            v35[2] = v35[2] + (float)(v65 * (float)(v30 * 0.57735026));
            v68 = (float)(v30 * 0.57735026) * light->m_flDirectSunAmount;
LABEL_32:
            v12 = t_max;
            v35[3] = v68 + v35[3];
            rad->weight[v31] = rad->weight[v31] + v30;
            goto LABEL_33;
          }
          v35[3] = (float)(light->m_flDirectSunAmount * v30) + v35[3];
          v38 = light[1].m_vecLighting.y;
          v39 = light[1].m_vecLighting.z;
          v40 = 16 * (v31 + 20488);
          *(float *)((char *)&rad->facenum + v40) = (float)(light[1].m_vecLighting.x * v30)
                                                  + *(float *)((char *)&rad->facenum + v40);
          v41 = *(float *)((char *)&rad->l.facedist + v40);
          v42 = (float *)((char *)&rad->facenum + v40);
          v42[1] = v41 + (float)(v38 * v30);
          v42[2] = v42[2] + (float)(v39 * v30);
          v42[3] = (float)(light[1].m_flDirectSunAmount * v30) + v42[3];
          v43 = light[2].m_vecLighting.y;
          v44 = light[2].m_vecLighting.z;
          v45 = 16 * (v31 + 36872);
          *(float *)((char *)&rad->facenum + v45) = (float)(light[2].m_vecLighting.x * v30)
                                                  + *(float *)((char *)&rad->facenum + v45);
          v46 = *(float *)((char *)&rad->l.facedist + v45);
          v47 = (float *)((char *)&rad->facenum + v45);
          v47[1] = v46 + (float)(v43 * v30);
          v47[2] = v47[2] + (float)(v44 * v30);
          v47[3] = (float)(light[2].m_flDirectSunAmount * v30) + v47[3];
          v48 = light[3].m_vecLighting.y;
          v49 = light[3].m_vecLighting.z;
          v50 = 16 * (v31 + 53256);
          v51 = (float)(light[3].m_vecLighting.x * v30) + *(float *)((char *)&rad->facenum + v50);
          v35 = (float *)((char *)&rad->facenum + v50);
          *v35 = v51;
          v35[1] = v35[1] + (float)(v48 * v30);
          v35[2] = v35[2] + (float)(v49 * v30);
          m_flDirectSunAmount = light[3].m_flDirectSunAmount;
        }
        else
        {
          m_flDirectSunAmount = light->m_flDirectSunAmount;
        }
        v68 = m_flDirectSunAmount * v30;
        goto LABEL_32;
      }
LABEL_33:
      ++v13;
    }
    while ( v13 < v12 );
    v13 = t_min;
    v14 = s;
LABEL_35:
    s = ++v14;
  }
  while ( v14 < s_max );
}

//------------------------------------------------------------------------------
// Address: 0x10015A80
// Name: void AddBouncedToRadial(struct radial_s __near *,class Vector const __near &,class Vector2D const __near &,class Vector2D const __near &,class Vector const __near * const,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddBouncedToRadial(
        radial_s *rad,
        const Vector *pnt,
        const Vector2D *coordmins,
        const Vector2D *coordmaxs,
        const Vector *light,
        bool hasBumpmap,
        bool neighborHasBumpmap)
{
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm7_4
  float v12; // xmm5_4
  float v13; // xmm1_4
  float v14; // xmm5_4
  float v15; // xmm0_4
  float v16; // xmm7_4
  double v17; // xmm0_8
  float v18; // xmm6_4
  double v19; // xmm0_8
  float v20; // xmm4_4
  double v21; // xmm0_8
  double v22; // xmm1_8
  int v23; // edi
  int v24; // ecx
  int w; // eax
  int v26; // ebx
  int v27; // edi
  float v28; // xmm0_4
  float v29; // xmm6_4
  float v30; // xmm4_4
  float v31; // xmm0_4
  int v32; // ecx
  float *p_x; // edx
  float v34; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  int v39; // edx
  float v40; // xmm7_4
  float *v41; // edx
  float v42; // xmm1_4
  float v43; // xmm2_4
  int v44; // edx
  float v45; // xmm7_4
  float *v46; // edx
  float v47; // xmm1_4
  float v48; // xmm2_4
  int v49; // edx
  float v50; // xmm7_4
  float *v51; // edx
  float v52; // xmm2_4
  float v53; // xmm2_4
  float v54; // xmm3_4
  int v55; // edx
  float v56; // xmm7_4
  float *v57; // edx
  float v58; // xmm7_4
  float v59; // xmm4_4
  float v60; // xmm2_4
  int v61; // edx
  float v62; // xmm7_4
  float *v63; // edx
  float v64; // xmm3_4
  float v65; // xmm4_4
  int v66; // edx
  float v67; // xmm4_4
  float v68; // xmm3_4
  float v69; // xmm1_4
  float v70; // xmm2_4
  float v71; // xmm3_4
  float coord; // [esp+Ch] [ebp-14h]
  int t_min; // [esp+14h] [ebp-Ch]
  float dists; // [esp+18h] [ebp-8h]
  float distt; // [esp+1Ch] [ebp-4h]
  int t_max; // [esp+28h] [ebp+8h]
  int s_max; // [esp+2Ch] [ebp+Ch]
  float coordminsa; // [esp+30h] [ebp+10h]

  v8 = pnt->x - rad->l.luxelOrigin.x;
  v9 = pnt->y - rad->l.luxelOrigin.y;
  v10 = pnt->z - rad->l.luxelOrigin.z;
  v11 = (float)(rad->l.worldToLuxelSpace[0].y * v9) + (float)(rad->l.worldToLuxelSpace[0].x * v8);
  v12 = (float)((float)(rad->l.worldToLuxelSpace[1].y * v9) + (float)(rad->l.worldToLuxelSpace[1].x * v8))
      + (float)(rad->l.worldToLuxelSpace[1].z * v10);
  v13 = coordmaxs->y - coordmins->y;
  v14 = v12 - (float)rad->l.face->m_LightmapTextureMinsInLuxels[1];
  v15 = coordmaxs->x - coordmins->x;
  v16 = (float)(v11 + (float)(rad->l.worldToLuxelSpace[0].z * v10))
      - (float)rad->l.face->m_LightmapTextureMinsInLuxels[0];
  coord = v16;
  if ( v15 >= 1.0 )
    v17 = v15;
  else
    v17 = 1.0;
  v18 = v17;
  dists = v18;
  if ( v13 >= 1.0 )
    v19 = v13;
  else
    v19 = 1.0;
  v20 = v19;
  v21 = v18 * 1.42;
  distt = v20;
  v22 = v20 * 1.42;
  v23 = (int)(v16 + v21 + 1.0);
  v24 = (int)(v14 - v22) <= 0 ? 0 : (int)(v14 - v22);
  w = rad->w;
  s_max = v23;
  t_max = (int)(v14 + v22 + 1.0);
  t_min = v24;
  if ( v23 >= w )
  {
    s_max = w;
    v23 = w;
  }
  if ( (int)(v14 + v22 + 1.0) >= rad->h )
    t_max = rad->h;
  v26 = (int)(v16 - v21) <= 0 ? 0 : (int)(v16 - v21);
  if ( v26 < v23 )
  {
    do
    {
      v27 = v24;
      if ( v24 < t_max )
      {
        v28 = (float)(v16 - (float)v26) / v18;
        v29 = 1.0 / v20;
        v30 = v28 * v28;
        coordminsa = v28 * v28;
        do
        {
          v31 = 2.0
              - (float)((float)((float)((float)(v14 - (float)v27) * v29) * (float)((float)(v14 - (float)v27) * v29))
                      + v30);
          v32 = v26 + v27 * rad->w;
          if ( v31 > 0.0 )
          {
            p_x = &rad->light[0][v32].m_vecLighting.x;
            v34 = (float)(light->x * v31) + *p_x;
            if ( hasBumpmap )
            {
              if ( neighborHasBumpmap )
              {
                y = light->y;
                z = light->z;
                *p_x = v34;
                p_x[1] = p_x[1] + (float)(y * v31);
                p_x[2] = p_x[2] + (float)(z * v31);
                v37 = light[1].y;
                v38 = light[1].z;
                v39 = 16 * (v32 + 20488);
                v40 = *(float *)((char *)&rad->facenum + v39);
                v41 = (float *)((char *)&rad->facenum + v39);
                *v41 = v40 + (float)(light[1].x * v31);
                v41[1] = (float)(v37 * v31) + v41[1];
                v41[2] = (float)(v38 * v31) + v41[2];
                v42 = light[2].y;
                v43 = light[2].z;
                v44 = 16 * (v32 + 36872);
                v45 = *(float *)((char *)&rad->facenum + v44);
                v46 = (float *)((char *)&rad->facenum + v44);
                *v46 = v45 + (float)(light[2].x * v31);
                v46[1] = (float)(v42 * v31) + v46[1];
                v46[2] = (float)(v43 * v31) + v46[2];
                v47 = light[3].y;
                v48 = light[3].z;
                v49 = 16 * (v32 + 53256);
                v50 = *(float *)((char *)&rad->facenum + v49);
                v51 = (float *)((char *)&rad->facenum + v49);
                *v51 = v50 + (float)(light[3].x * v31);
                v16 = coord;
                v51[1] = (float)(v47 * v31) + v51[1];
                v52 = (float)(v48 * v31) + v51[2];
              }
              else
              {
                v53 = v31 * light->y;
                v54 = v31 * light->z;
                *p_x = v34;
                p_x[1] = p_x[1] + v53;
                p_x[2] = p_x[2] + v54;
                v55 = 16 * (v32 + 20488);
                v56 = *(float *)((char *)&rad->facenum + v55);
                v57 = (float *)((char *)&rad->facenum + v55);
                v58 = v56 + (float)((float)(v31 * 0.57735026) * light->x);
                v59 = (float)(v31 * 0.57735026) * light->z;
                v57[1] = v57[1] + (float)((float)(v31 * 0.57735026) * light->y);
                v60 = v57[2];
                *v57 = v58;
                v57[2] = v60 + v59;
                v61 = 16 * (v32 + 36872);
                v62 = *(float *)((char *)&rad->facenum + v61);
                v63 = (float *)((char *)&rad->facenum + v61);
                v64 = (float)(v31 * 0.57735026) * light->y;
                v65 = (float)(v31 * 0.57735026) * light->z;
                *v63 = v62 + (float)((float)(v31 * 0.57735026) * light->x);
                v16 = coord;
                v63[1] = v63[1] + v64;
                v63[2] = v63[2] + v65;
                v66 = 16 * (v32 + 53256);
                v67 = *(float *)((char *)&rad->facenum + v66);
                v51 = (float *)((char *)&rad->facenum + v66);
                v68 = (float)(v31 * 0.57735026) * light->y;
                v69 = (float)(v31 * 0.57735026) * light->z;
                *v51 = v67 + (float)((float)(v31 * 0.57735026) * light->x);
                v30 = coordminsa;
                v51[1] = v51[1] + v68;
                v52 = v51[2] + v69;
              }
              v51[2] = v52;
            }
            else
            {
              v70 = light->y;
              v71 = light->z;
              *p_x = v34;
              p_x[1] = p_x[1] + (float)(v70 * v31);
              p_x[2] = p_x[2] + (float)(v71 * v31);
            }
            rad->weight[v32] = rad->weight[v32] + v31;
          }
          ++v27;
        }
        while ( v27 < t_max );
        v20 = distt;
        v18 = dists;
        v24 = t_min;
      }
      ++v26;
    }
    while ( v26 < s_max );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015F50
// Name: struct radial_s __near * AllocateRadial(int)
// Source: json
//------------------------------------------------------------------------------
radial_s *__cdecl AllocateRadial(int facenum)
{
  unsigned __int8 *v1; // esi
  int v2; // eax

  v1 = calloc(count: 1u, size: 0x110080u);
  *(_DWORD *)v1 = facenum;
  InitLightinfo(pl: (lightinfo_t *)(v1 + 4), facenum);
  v2 = *((_DWORD *)v1 + 27);
  *((_DWORD *)v1 + 30) = *(_DWORD *)(v2 + 36) + 1;
  *((_DWORD *)v1 + 31) = *(_DWORD *)(v2 + 40) + 1;
  return (radial_s *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10015F90
// Name: bool SampleRadial(struct radial_s __near *,class Vector __near &,struct LightingValue_t __near * const,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SampleRadial(radial_s *rad, Vector *pnt, LightingValue_t *light, int bumpSampleCount)
{
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  int v8; // ecx
  int v9; // eax
  int v10; // esi
  int v11; // eax
  int v12; // edi
  LightingValue_t *v13; // ecx
  int v14; // ebx
  double v15; // st7
  float *v16; // ebx
  float v17; // xmm1_4
  int v18; // ebx
  double v19; // st7
  float *v20; // ebx
  float v21; // xmm1_4
  LightingValue_t *v22; // ecx
  int v23; // ebx
  double v24; // st7
  float *v25; // ebx
  float v26; // xmm1_4
  LightingValue_t *v27; // ecx
  int v28; // ebx
  double v29; // st7
  float *v30; // ebx
  float v31; // xmm1_4
  LightingValue_t *v32; // ecx
  int v33; // ebx
  double v34; // st7
  float *v35; // ebx
  float v36; // xmm1_4
  float v37; // xmm5_4
  float v38; // xmm1_4
  bool v39; // zf
  int v41; // ecx
  float *p_z; // eax
  char baseSampleOk_3; // [esp+13h] [ebp+Bh]

  v5 = pnt->x - rad->l.luxelOrigin.x;
  v6 = pnt->y - rad->l.luxelOrigin.y;
  v7 = pnt->z - rad->l.luxelOrigin.z;
  v8 = (int)(float)((float)((float)((float)((float)(rad->l.worldToLuxelSpace[1].y * v6)
                                          + (float)(rad->l.worldToLuxelSpace[1].x * v5))
                                  + (float)(rad->l.worldToLuxelSpace[1].z * v7))
                          - (float)rad->l.face->m_LightmapTextureMinsInLuxels[1])
                  + 0.5);
  v9 = (int)(float)((float)((float)((float)((float)(rad->l.worldToLuxelSpace[0].y * v6)
                                          + (float)(rad->l.worldToLuxelSpace[0].x * v5))
                                  + (float)(rad->l.worldToLuxelSpace[0].z * v7))
                          - (float)rad->l.face->m_LightmapTextureMinsInLuxels[0])
                  + 0.5);
  v10 = v9 + v8 * rad->w;
  if ( v9 < 0 || v9 > rad->w || v8 < 0 || v8 > rad->h )
  {
    if ( !warning )
    {
      _Warning(a1: "SampleRadial: Punting, Waiting for fix\n");
      warning = true;
    }
    v41 = bumpSampleCount;
    if ( bumpSampleCount > 0 )
    {
      p_z = &light->m_vecLighting.z;
      do
      {
        *(p_z - 2) = 2550.0;
        *(p_z - 1) = 0.0;
        *p_z = 0.0;
        p_z += 4;
        --v41;
      }
      while ( v41 != 0 );
    }
    return 0;
  }
  else
  {
    v11 = bumpSampleCount;
    v12 = 0;
    baseSampleOk_3 = 1;
    if ( bumpSampleCount >= 4 )
    {
      do
      {
        v13 = &light[v12];
        v13->m_vecLighting.x = 0.0;
        v13->m_vecLighting.y = 0.0;
        v13->m_vecLighting.z = 0.0;
        v13->m_flDirectSunAmount = 0.0;
        if ( rad->weight[v10] <= 0.0000099999997 )
        {
          if ( bRed2Black )
            v13->m_vecLighting.x = 0.0;
          else
            v13->m_vecLighting.x = 2550.0;
          v13->m_vecLighting.y = 0.0;
          v13->m_vecLighting.z = 0.0;
          if ( v12 == 0 )
            baseSampleOk_3 = 0;
        }
        else
        {
          v14 = 16 * ((v12 << 14) + v10 + 4104);
          v15 = *(float *)((char *)&rad->facenum + v14);
          v16 = (float *)((char *)&rad->facenum + v14);
          v13->m_vecLighting.x = v15;
          v13->m_vecLighting.y = v16[1];
          v13->m_vecLighting.z = v16[2];
          v13->m_flDirectSunAmount = v16[3];
          v17 = 1.0 / rad->weight[v10];
          v13->m_vecLighting.x = v13->m_vecLighting.x * v17;
          v13->m_vecLighting.y = v17 * v13->m_vecLighting.y;
          v13->m_vecLighting.z = v17 * v13->m_vecLighting.z;
          v13->m_flDirectSunAmount = v17 * v13->m_flDirectSunAmount;
        }
        v13[1].m_vecLighting.x = 0.0;
        v13[1].m_vecLighting.y = 0.0;
        v13[1].m_vecLighting.z = 0.0;
        v13[1].m_flDirectSunAmount = 0.0;
        if ( rad->weight[v10] <= 0.0000099999997 )
        {
          if ( bRed2Black )
            v13[1].m_vecLighting.x = 0.0;
          else
            v13[1].m_vecLighting.x = 2550.0;
          v13[1].m_vecLighting.y = 0.0;
          v13[1].m_vecLighting.z = 0.0;
          if ( v12 == -1 )
            baseSampleOk_3 = 0;
        }
        else
        {
          v18 = 16 * ((v12 << 14) + v10 + 20488);
          v19 = *(float *)((char *)&rad->facenum + v18);
          v20 = (float *)((char *)&rad->facenum + v18);
          v13[1].m_vecLighting.x = v19;
          v13[1].m_vecLighting.y = v20[1];
          v13[1].m_vecLighting.z = v20[2];
          v13[1].m_flDirectSunAmount = v20[3];
          v21 = 1.0 / rad->weight[v10];
          v13[1].m_vecLighting.x = v13[1].m_vecLighting.x * v21;
          v13[1].m_vecLighting.y = v21 * v13[1].m_vecLighting.y;
          v13[1].m_vecLighting.z = v21 * v13[1].m_vecLighting.z;
          v13[1].m_flDirectSunAmount = v21 * v13[1].m_flDirectSunAmount;
        }
        v22 = &light[v12 + 2];
        v22->m_vecLighting.x = 0.0;
        v22->m_vecLighting.y = 0.0;
        v22->m_vecLighting.z = 0.0;
        v22->m_flDirectSunAmount = 0.0;
        if ( rad->weight[v10] <= 0.0000099999997 )
        {
          if ( bRed2Black )
            v22->m_vecLighting.x = 0.0;
          else
            v22->m_vecLighting.x = 2550.0;
          v22->m_vecLighting.y = 0.0;
          v22->m_vecLighting.z = 0.0;
          if ( v12 == -2 )
            baseSampleOk_3 = 0;
        }
        else
        {
          v23 = 16 * ((v12 << 14) + v10 + 36872);
          v24 = *(float *)((char *)&rad->facenum + v23);
          v25 = (float *)((char *)&rad->facenum + v23);
          v22->m_vecLighting.x = v24;
          v22->m_vecLighting.y = v25[1];
          v22->m_vecLighting.z = v25[2];
          v22->m_flDirectSunAmount = v25[3];
          v26 = 1.0 / rad->weight[v10];
          v22->m_vecLighting.x = v22->m_vecLighting.x * v26;
          v22->m_vecLighting.y = v26 * v22->m_vecLighting.y;
          v22->m_vecLighting.z = v26 * v22->m_vecLighting.z;
          v22->m_flDirectSunAmount = v26 * v22->m_flDirectSunAmount;
        }
        v27 = &light[v12 + 3];
        v27->m_vecLighting.x = 0.0;
        v27->m_vecLighting.y = 0.0;
        v27->m_vecLighting.z = 0.0;
        v27->m_flDirectSunAmount = 0.0;
        if ( rad->weight[v10] <= 0.0000099999997 )
        {
          if ( bRed2Black )
            v27->m_vecLighting.x = 0.0;
          else
            v27->m_vecLighting.x = 2550.0;
          v27->m_vecLighting.y = 0.0;
          v27->m_vecLighting.z = 0.0;
          if ( v12 == -3 )
            baseSampleOk_3 = 0;
        }
        else
        {
          v28 = 16 * ((v12 << 14) + v10 + 53256);
          v29 = *(float *)((char *)&rad->facenum + v28);
          v30 = (float *)((char *)&rad->facenum + v28);
          v27->m_vecLighting.x = v29;
          v27->m_vecLighting.y = v30[1];
          v27->m_vecLighting.z = v30[2];
          v27->m_flDirectSunAmount = v30[3];
          v31 = 1.0 / rad->weight[v10];
          v27->m_vecLighting.x = v31 * v27->m_vecLighting.x;
          v27->m_vecLighting.y = v31 * v27->m_vecLighting.y;
          v27->m_vecLighting.z = v31 * v27->m_vecLighting.z;
          v27->m_flDirectSunAmount = v31 * v27->m_flDirectSunAmount;
        }
        v11 = bumpSampleCount;
        v12 += 4;
      }
      while ( v12 < bumpSampleCount - 3 );
    }
    for ( ; v12 < v11; ++v12 )
    {
      v32 = &light[v12];
      v32->m_vecLighting.x = 0.0;
      v32->m_vecLighting.y = 0.0;
      v32->m_vecLighting.z = 0.0;
      v32->m_flDirectSunAmount = 0.0;
      if ( rad->weight[v10] <= 0.0000099999997 )
      {
        v39 = !bRed2Black;
        v32->m_vecLighting.y = 0.0;
        v32->m_vecLighting.z = 0.0;
        if ( v39 )
          v32->m_vecLighting.x = 2550.0;
        else
          v32->m_vecLighting.x = 0.0;
        if ( v12 == 0 )
          baseSampleOk_3 = 0;
      }
      else
      {
        v33 = 16 * ((v12 << 14) + v10 + 4104);
        v34 = *(float *)((char *)&rad->facenum + v33);
        v35 = (float *)((char *)&rad->facenum + v33);
        v32->m_vecLighting.x = v34;
        v32->m_vecLighting.y = v35[1];
        v32->m_vecLighting.z = v35[2];
        v32->m_flDirectSunAmount = v35[3];
        v36 = 1.0 / rad->weight[v10];
        v32->m_vecLighting.x = v32->m_vecLighting.x * v36;
        v32->m_vecLighting.y = v36 * v32->m_vecLighting.y;
        v37 = v36 * v32->m_vecLighting.z;
        v38 = v36 * v32->m_flDirectSunAmount;
        v32->m_vecLighting.z = v37;
        v32->m_flDirectSunAmount = v38;
      }
    }
    return baseSampleOk_3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100164E0
// Name: bool FloatLess(float const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl FloatLess(const float *src1, const float *src2)
{
  return *src2 > *src1;
}

//------------------------------------------------------------------------------
// Address: 0x10016500
// Name: void DumpDispLuxels(int,class Vector __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DumpDispLuxels(int iFace, Vector *color, int iLuxel, int nBump)
{
  int i; // esi
  char szFileName[512]; // [esp+8h] [ebp-200h] BYREF

  ThreadLock();
  for ( i = 0; i < 4; ++i )
  {
    if ( pFileLuxels[i] == nullptr )
    {
      sprintf(string: szFileName, format: "luxels_bump%d.txt", i);
      pFileLuxels[i] = g_pFileSystem->Open(this: g_pFileSystem, a2: szFileName, a3: "w", a4: 0);
    }
  }
  WriteWinding(out: pFileLuxels[nBump], w: facelight[iFace].sample[iLuxel].w, color);
  ThreadUnlock();
}

//------------------------------------------------------------------------------
// Address: 0x100165A0
// Name: void CloseDispLuxels(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CloseDispLuxels()
{
  void **v0; // esi

  v0 = pFileLuxels;
  do
  {
    if ( *v0 != nullptr )
      g_pFileSystem->Close(this: g_pFileSystem, a2: *v0);
    ++v0;
  }
  while ( (int)v0 < (int)&vec2_origin_14 );
}

//------------------------------------------------------------------------------
// Address: 0x100165D0
// Name: void PatchLightmapCoordRange(struct radial_s __near *,int,class Vector2D __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PatchLightmapCoordRange(radial_s *rad, int ndxPatch, Vector2D *mins, Vector2D *maxs)
{
  winding_t *winding; // esi
  dface_t *face; // ecx
  int v8; // edi
  Vector *p; // ecx
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float x; // xmm2_4
  float y; // xmm0_4
  float v17; // xmm0_4
  int *ndxPatcha; // [esp+Ch] [ebp+Ch]
  int i; // [esp+10h] [ebp+10h]
  Vector2D *maxsa; // [esp+14h] [ebp+14h]

  mins->x = 1.0e30;
  mins->y = 1.0e30;
  maxs->x = -1.0e30;
  maxs->y = -1.0e30;
  winding = g_Patches.m_Memory.m_pMemory[ndxPatch].winding;
  i = 0;
  if ( winding->numpoints > 0 )
  {
    face = rad->l.face;
    maxsa = (Vector2D *)face->m_LightmapTextureMinsInLuxels;
    ndxPatcha = &face->m_LightmapTextureMinsInLuxels[1];
    v8 = 0;
    do
    {
      p = winding->p;
      v10 = p[v8].x - rad->l.luxelOrigin.x;
      v11 = p[v8].y - rad->l.luxelOrigin.y;
      v12 = p[v8].z - rad->l.luxelOrigin.z;
      v13 = (float)((float)((float)(rad->l.worldToLuxelSpace[0].x * v10) + (float)(v11 * rad->l.worldToLuxelSpace[0].y))
                  + (float)(v12 * rad->l.worldToLuxelSpace[0].z))
          - (float)SLODWORD(maxsa->x);
      v14 = (float)((float)((float)(rad->l.worldToLuxelSpace[1].y * v11) + (float)(rad->l.worldToLuxelSpace[1].x * v10))
                  + (float)(rad->l.worldToLuxelSpace[1].z * v12))
          - (float)*ndxPatcha;
      x = mins->x;
      if ( v13 <= mins->x )
        x = v13;
      mins->x = x;
      if ( maxs->x > v13 )
        v13 = maxs->x;
      maxs->x = v13;
      y = mins->y;
      if ( v14 <= y )
        y = v14;
      mins->y = y;
      v17 = maxs->y;
      if ( v17 <= v14 )
        v17 = v14;
      maxs->y = v17;
      ++v8;
      ++i;
    }
    while ( i < winding->numpoints );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016720
// Name: struct radial_s __near * BuildPatchRadial(int)
// Source: json
//------------------------------------------------------------------------------
radial_s *__cdecl BuildPatchRadial(int facenum)
{
  int v1; // edi
  radial_s *v2; // esi
  dface_t *face; // eax
  int v4; // eax
  CPatch *m_pMemory; // edx
  faceneighbor_t *v6; // ecx
  CPatch *v7; // ebx
  int ndxNext; // eax
  unsigned int v9; // edx
  dface_t *v10; // eax
  int i; // ebx
  int v12; // edi
  CPatch *v13; // edi
  int v14; // eax
  unsigned int v15; // edx
  dface_t *v16; // eax
  Vector patchOrigin; // [esp+Ch] [ebp-24h] BYREF
  Vector2D mins; // [esp+18h] [ebp-18h] BYREF
  Vector2D maxs; // [esp+20h] [ebp-10h] BYREF
  faceneighbor_t *fn; // [esp+28h] [ebp-8h]
  BOOL needsBumpmap; // [esp+2Ch] [ebp-4h]
  CPatch *pNextPatch; // [esp+38h] [ebp+8h]
  CPatch *pNextPatcha; // [esp+38h] [ebp+8h]

  v1 = facenum;
  LOBYTE(needsBumpmap) = (texinfo.m_Memory.m_pMemory[g_pFaces[facenum].texinfo].flags & 0x800) != 0;
  v2 = (radial_s *)calloc(count: 1u, size: 0x110080u);
  v2->facenum = facenum;
  InitLightinfo(pl: &v2->l, facenum);
  face = v2->l.face;
  v2->w = face->m_LightmapTextureSizeInLuxels[0] + 1;
  v2->h = face->m_LightmapTextureSizeInLuxels[1] + 1;
  v4 = g_FacePatches.m_Memory.m_pMemory[v2->facenum];
  m_pMemory = g_Patches.m_Memory.m_pMemory;
  v6 = &faceneighbor[v2->facenum];
  fn = v6;
  if ( v4 != -1 )
  {
    v7 = &g_Patches.m_Memory.m_pMemory[v4];
    if ( v7 != nullptr )
    {
      do
      {
        ndxNext = v7->ndxNext;
        pNextPatch = nullptr;
        if ( ndxNext != -1 )
          pNextPatch = &m_pMemory[ndxNext];
        if ( v7->child1 == -1 )
        {
          v9 = (int)((unsigned __int64)(1041204193LL * ((char *)v7 - (char *)m_pMemory)) >> 32) >> 6;
          PatchLightmapCoordRange(rad: v2, ndxPatch: v9 + (v9 >> 31), &mins, &maxs);
          v10 = &g_pFaces[v1];
          if ( &g_pFaces[v1] != nullptr && v10->dispinfo != -1 && v10->numedges == 4 )
          {
            WindingCenter(w: v7->winding, center: &patchOrigin);
            AddBouncedToRadial(
              rad: v2,
              pnt: &patchOrigin,
              coordmins: &mins,
              coordmaxs: &maxs,
              light: v7->totallight.light,
              hasBumpmap: needsBumpmap,
              neighborHasBumpmap: needsBumpmap);
          }
          else
          {
            AddBouncedToRadial(
              rad: v2,
              pnt: &v7->origin,
              coordmins: &mins,
              coordmaxs: &maxs,
              light: v7->totallight.light,
              hasBumpmap: needsBumpmap,
              neighborHasBumpmap: needsBumpmap);
          }
          m_pMemory = g_Patches.m_Memory.m_pMemory;
        }
        v7 = pNextPatch;
      }
      while ( pNextPatch != nullptr );
      v6 = fn;
    }
  }
  for ( i = 0; i < v6->numneighbors; ++i )
  {
    v12 = g_FacePatches.m_Memory.m_pMemory[v6->neighbor[i]];
    if ( v12 != -1 )
    {
      v13 = &m_pMemory[v12];
      if ( v13 != nullptr )
      {
        do
        {
          v14 = v13->ndxNext;
          pNextPatcha = nullptr;
          if ( v14 != -1 )
            pNextPatcha = &m_pMemory[v14];
          if ( v13->child1 == -1 )
          {
            v15 = (int)((unsigned __int64)(1041204193LL * ((char *)v13 - (char *)m_pMemory)) >> 32) >> 6;
            PatchLightmapCoordRange(rad: v2, ndxPatch: v15 + (v15 >> 31), &mins, &maxs);
            v16 = &g_pFaces[fn->neighbor[i]];
            if ( v16 != nullptr && v16->dispinfo != -1 && v16->numedges == 4 )
            {
              WindingCenter(w: v13->winding, center: &patchOrigin);
              AddBouncedToRadial(
                rad: v2,
                pnt: &patchOrigin,
                coordmins: &mins,
                coordmaxs: &maxs,
                light: v13->totallight.light,
                hasBumpmap: needsBumpmap,
                neighborHasBumpmap: needsBumpmap);
            }
            else
            {
              AddBouncedToRadial(
                rad: v2,
                pnt: &v13->origin,
                coordmins: &mins,
                coordmaxs: &maxs,
                light: v13->totallight.light,
                hasBumpmap: needsBumpmap,
                neighborHasBumpmap: needsBumpmap);
            }
            m_pMemory = g_Patches.m_Memory.m_pMemory;
          }
          v13 = pNextPatcha;
        }
        while ( pNextPatcha != nullptr );
        v6 = fn;
      }
    }
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100169C0
// Name: struct radial_s __near * BuildLuxelRadial(int,int)
// Source: json
//------------------------------------------------------------------------------
radial_s *__cdecl BuildLuxelRadial(int facenum, int style)
{
  facelight_t *v2; // edi
  radial_s *v3; // eax
  lightinfo_t *p_l; // esi
  radial_s *v5; // ecx
  dface_t *face; // eax
  dface_t *v7; // ebx
  int v8; // ecx
  bool v9; // dl
  int v10; // ebx
  LightingValue_t *v11; // eax
  float y; // xmm0_4
  LightingValue_t *v13; // eax
  float m_flDirectSunAmount; // xmm0_4
  LightingValue_t *v15; // eax
  float x; // xmm0_4
  float *p_x; // eax
  float v18; // xmm0_4
  LightingValue_t *v19; // eax
  float v20; // xmm0_4
  float *v21; // eax
  float v22; // xmm0_4
  LightingValue_t *v23; // eax
  float v24; // xmm0_4
  float *v25; // eax
  faceneighbor_t *v26; // edx
  int v27; // eax
  facelight_t *v28; // edi
  int v29; // edx
  char v30; // al
  _BYTE *v31; // eax
  int v32; // ebx
  LightingValue_t *v33; // eax
  float v34; // xmm0_4
  LightingValue_t *v35; // eax
  float v36; // xmm0_4
  LightingValue_t *v37; // eax
  float v38; // xmm0_4
  float *v39; // eax
  float v40; // xmm0_4
  LightingValue_t *v41; // eax
  float v42; // xmm0_4
  float *v43; // eax
  float v44; // xmm0_4
  LightingValue_t *v45; // eax
  float v46; // xmm0_4
  float *v47; // eax
  const Vector *v48; // eax
  float v49; // xmm3_4
  float v50; // xmm0_4
  dface_t *v51; // ecx
  float v52; // xmm3_4
  float v53; // xmm7_4
  float v54; // xmm2_4
  float v55; // xmm0_4
  float v56; // xmm1_4
  float v57; // xmm2_4
  float v58; // xmm3_4
  float v59; // xmm1_4
  float v60; // xmm0_4
  float v61; // xmm5_4
  float v62; // xmm6_4
  float v63; // xmm0_4
  float v64; // xmm2_4
  float v65; // xmm1_4
  lightinfo_t l; // [esp+Ch] [ebp-F4h] BYREF
  Vector2D mins; // [esp+80h] [ebp-80h] BYREF
  Vector2D maxs; // [esp+88h] [ebp-78h] BYREF
  float v70; // [esp+90h] [ebp-70h]
  int v71; // [esp+94h] [ebp-6Ch]
  int v72; // [esp+98h] [ebp-68h]
  float v73; // [esp+9Ch] [ebp-64h]
  LightingValue_t light[4]; // [esp+A0h] [ebp-60h] BYREF
  int j; // [esp+E0h] [ebp-20h]
  faceneighbor_t *fn; // [esp+E4h] [ebp-1Ch]
  int v77; // [esp+E8h] [ebp-18h]
  BOOL needsBumpmap; // [esp+ECh] [ebp-14h]
  int k; // [esp+F0h] [ebp-10h]
  radial_s *rad; // [esp+F4h] [ebp-Ch]
  int neighborHasBumpmap; // [esp+F8h] [ebp-8h]
  int nstyle; // [esp+FCh] [ebp-4h]
  int facenuma; // [esp+108h] [ebp+8h]
  int *facenumc; // [esp+108h] [ebp+8h]
  int facenumb; // [esp+108h] [ebp+8h]
  unsigned __int8 facenum_3; // [esp+10Bh] [ebp+Bh]

  v2 = &facelight[facenum];
  fn = &faceneighbor[facenum];
  v3 = (radial_s *)calloc(count: 1u, size: 0x110080u);
  p_l = &v3->l;
  rad = v3;
  v3->facenum = facenum;
  InitLightinfo(pl: &v3->l, facenum);
  v5 = rad;
  face = rad->l.face;
  rad->w = face->m_LightmapTextureSizeInLuxels[0] + 1;
  v5->h = face->m_LightmapTextureSizeInLuxels[1] + 1;
  v7 = g_pFaces;
  v8 = 56 * facenum;
  v9 = (texinfo.m_Memory.m_pMemory[g_pFaces[facenum].texinfo].flags & 0x800) != 0;
  v77 = 56 * facenum;
  LOBYTE(needsBumpmap) = v9;
  neighborHasBumpmap = 0;
  if ( v2->numsamples > 0 )
  {
    facenuma = 0;
    v10 = 0;
    do
    {
      v11 = v2->light[style][0];
      if ( needsBumpmap )
      {
        light[0].m_vecLighting.x = v11[v10].m_vecLighting.x;
        y = v11[v10].m_vecLighting.y;
        v13 = &v11[v10];
        light[0].m_vecLighting.y = y;
        light[0].m_vecLighting.z = v13->m_vecLighting.z;
        m_flDirectSunAmount = v13->m_flDirectSunAmount;
        v15 = v2->light[style][1];
        light[0].m_flDirectSunAmount = m_flDirectSunAmount;
        x = v15[v10].m_vecLighting.x;
        p_x = &v15[v10].m_vecLighting.x;
        light[1].m_vecLighting.x = x;
        light[1].m_vecLighting.y = p_x[1];
        light[1].m_vecLighting.z = p_x[2];
        v18 = p_x[3];
        v19 = v2->light[style][2];
        light[1].m_flDirectSunAmount = v18;
        v20 = v19[v10].m_vecLighting.x;
        v21 = &v19[v10].m_vecLighting.x;
        light[2].m_vecLighting.x = v20;
        light[2].m_vecLighting.y = v21[1];
        light[2].m_vecLighting.z = v21[2];
        v22 = v21[3];
        v23 = &v2->light[style][3][v10];
        light[2].m_flDirectSunAmount = v22;
        light[3] = *v23;
      }
      else
      {
        v24 = v11[v10].m_vecLighting.x;
        v25 = &v11[v10].m_vecLighting.x;
        light[0].m_vecLighting.x = v24;
        light[0].m_vecLighting.y = v25[1];
        light[0].m_vecLighting.z = v25[2];
        light[0].m_flDirectSunAmount = v25[3];
      }
      AddDirectToRadial(
        rad,
        pnt: &v2->sample[facenuma].pos,
        coordmins: &v2->sample[facenuma].mins,
        coordmaxs: &v2->sample[facenuma].maxs,
        light,
        hasBumpmap: needsBumpmap,
        neighborHasBumpmap: needsBumpmap);
      ++facenuma;
      ++v10;
      ++neighborHasBumpmap;
    }
    while ( neighborHasBumpmap < v2->numsamples );
    v7 = g_pFaces;
    v8 = v77;
  }
  v26 = fn;
  v27 = 0;
  j = 0;
  if ( fn->numneighbors > 0 )
  {
    v72 = v8 + style + 16;
    do
    {
      facenumc = &v26->neighbor[v27];
      v28 = &facelight[*facenumc];
      LOBYTE(neighborHasBumpmap) = (texinfo.m_Memory.m_pMemory[v7[*facenumc].texinfo].flags & 0x800) != 0;
      v29 = *facenumc;
      v71 = *facenumc;
      k = (int)&v7[v29];
      v30 = *(_BYTE *)(k + 16);
      nstyle = 0;
      if ( v30 != *((_BYTE *)&v7->planenum + v72) )
      {
        facenum_3 = v7->styles[v8 + style];
        nstyle = 1;
        v31 = (_BYTE *)(k + 17);
        while ( *v31 != facenum_3 )
        {
          ++nstyle;
          ++v31;
          if ( nstyle >= 4 )
            goto LABEL_22;
        }
      }
      InitLightinfo(pl: &l, facenum: v71);
      v32 = 0;
      k = 0;
      if ( v28->numsamples > 0 )
      {
        facenumb = 0;
        do
        {
          v33 = v28->light[nstyle][0];
          if ( (_BYTE)neighborHasBumpmap != 0 )
          {
            light[0].m_vecLighting.x = v33[v32].m_vecLighting.x;
            v34 = v33[v32].m_vecLighting.y;
            v35 = &v33[v32];
            light[0].m_vecLighting.y = v34;
            light[0].m_vecLighting.z = v35->m_vecLighting.z;
            v36 = v35->m_flDirectSunAmount;
            v37 = v28->light[nstyle][1];
            light[0].m_flDirectSunAmount = v36;
            v38 = v37[v32].m_vecLighting.x;
            v39 = &v37[v32].m_vecLighting.x;
            light[1].m_vecLighting.x = v38;
            light[1].m_vecLighting.y = v39[1];
            light[1].m_vecLighting.z = v39[2];
            v40 = v39[3];
            v41 = v28->light[nstyle][2];
            light[1].m_flDirectSunAmount = v40;
            v42 = v41[v32].m_vecLighting.x;
            v43 = &v41[v32].m_vecLighting.x;
            light[2].m_vecLighting.x = v42;
            light[2].m_vecLighting.y = v43[1];
            light[2].m_vecLighting.z = v43[2];
            v44 = v43[3];
            v45 = &v28->light[nstyle][3][v32];
            light[2].m_flDirectSunAmount = v44;
            light[3] = *v45;
          }
          else
          {
            v46 = v33[v32].m_vecLighting.x;
            v47 = &v33[v32].m_vecLighting.x;
            light[0].m_vecLighting.x = v46;
            light[0].m_vecLighting.y = v47[1];
            light[0].m_vecLighting.z = v47[2];
            light[0].m_flDirectSunAmount = v47[3];
          }
          v48 = (const Vector *)&v28->sample[facenumb];
          v49 = v48[2].x;
          v50 = v48[1].z + (float)l.face->m_LightmapTextureMinsInLuxels[0];
          v70 = (float)l.face->m_LightmapTextureMinsInLuxels[0];
          v51 = p_l->face;
          v52 = v49 + (float)l.face->m_LightmapTextureMinsInLuxels[1];
          v73 = (float)l.face->m_LightmapTextureMinsInLuxels[1];
          v53 = (float)(l.luxelToWorldSpace[0].z * v50) + l.luxelOrigin.z;
          v54 = (float)(l.luxelToWorldSpace[0].y * v50) + l.luxelOrigin.y;
          v55 = (float)((float)(l.luxelToWorldSpace[1].x * v52)
                      + (float)((float)(l.luxelToWorldSpace[0].x * v50) + l.luxelOrigin.x))
              - p_l->luxelOrigin.x;
          v56 = (float)((float)(l.luxelToWorldSpace[1].y * v52) + v54) - p_l->luxelOrigin.y;
          v57 = (float)((float)(l.luxelToWorldSpace[1].z * v52) + v53) - p_l->luxelOrigin.z;
          mins.x = (float)((float)((float)(p_l->worldToLuxelSpace[0].y * v56)
                                 + (float)(p_l->worldToLuxelSpace[0].x * v55))
                         + (float)(p_l->worldToLuxelSpace[0].z * v57))
                 - (float)v51->m_LightmapTextureMinsInLuxels[0];
          v58 = (float)(p_l->worldToLuxelSpace[1].y * v56) + (float)(p_l->worldToLuxelSpace[1].x * v55);
          v59 = v48[2].z + v73;
          v60 = v48[2].y + v70;
          v61 = (float)(l.luxelToWorldSpace[0].y * v60) + l.luxelOrigin.y;
          v62 = (float)(l.luxelToWorldSpace[0].z * v60) + l.luxelOrigin.z;
          v63 = (float)((float)(l.luxelToWorldSpace[1].x * v59)
                      + (float)((float)(l.luxelToWorldSpace[0].x * v60) + l.luxelOrigin.x))
              - p_l->luxelOrigin.x;
          mins.y = (float)(v58 + (float)(p_l->worldToLuxelSpace[1].z * v57))
                 - (float)v51->m_LightmapTextureMinsInLuxels[1];
          v64 = (float)((float)(l.luxelToWorldSpace[1].y * v59) + v61) - p_l->luxelOrigin.y;
          v65 = (float)((float)(v59 * l.luxelToWorldSpace[1].z) + v62) - p_l->luxelOrigin.z;
          maxs.x = (float)((float)((float)(p_l->worldToLuxelSpace[0].x * v63)
                                 + (float)(v64 * p_l->worldToLuxelSpace[0].y))
                         + (float)(v65 * p_l->worldToLuxelSpace[0].z))
                 - (float)v51->m_LightmapTextureMinsInLuxels[0];
          maxs.y = (float)((float)((float)(p_l->worldToLuxelSpace[1].x * v63)
                                 + (float)(p_l->worldToLuxelSpace[1].y * v64))
                         + (float)(p_l->worldToLuxelSpace[1].z * v65))
                 - (float)v51->m_LightmapTextureMinsInLuxels[1];
          AddDirectToRadial(
            rad,
            pnt: v48 + 3,
            coordmins: &mins,
            coordmaxs: &maxs,
            light,
            hasBumpmap: needsBumpmap,
            neighborHasBumpmap);
          ++facenumb;
          ++v32;
          ++k;
        }
        while ( k < v28->numsamples );
      }
      v8 = v77;
      v7 = g_pFaces;
LABEL_22:
      v26 = fn;
      v27 = j + 1;
      j = v27;
    }
    while ( v27 < fn->numneighbors );
  }
  return rad;
}

//------------------------------------------------------------------------------
// Address: 0x10017E20
// Name: void FinalLightFace(int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FinalLightFace(int iThread, int facenum)
{
  dface_t *v2; // edx
  bool v3; // zf
  int i; // eax
  double v5; // st7
  int texinfo; // eax
  IMemAlloc_vtbl *v7; // edx
  int v8; // ebx
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  UtlRBTreeNode_t<float,int> *v10; // eax
  IMemAlloc_vtbl *v11; // edx
  void *(__thiscall *v12)(IMemAlloc *, unsigned int); // eax
  UtlRBTreeNode_t<float,int> *v13; // eax
  IMemAlloc_vtbl *v14; // edx
  void *(__thiscall *v15)(IMemAlloc *, unsigned int); // eax
  int v16; // esi
  radial_s *v17; // eax
  IVRadDispMgr *v18; // eax
  radial_s *v19; // eax
  IVRadDispMgr *v20; // eax
  int v21; // ecx
  int numluxels; // eax
  int v23; // edx
  unsigned __int8 *v24; // eax
  IVRadDispMgr *v25; // eax
  int v26; // edi
  unsigned int v27; // esi
  int v28; // ebx
  LightingValue_t **v29; // edx
  int v30; // esi
  float *p_z; // eax
  int v32; // ecx
  double v33; // st7
  float *v34; // ecx
  double v35; // st7
  int v36; // ecx
  float *v37; // ecx
  double v38; // st7
  int v39; // ecx
  float *v40; // ecx
  double v41; // st7
  int v42; // ecx
  float *v43; // ecx
  int v44; // eax
  LightingValue_t **v45; // edx
  int v46; // esi
  int v47; // edi
  float *v48; // ecx
  float *v49; // eax
  radial_s *v50; // esi
  IVRadDispMgr *v51; // eax
  int v52; // edx
  int v53; // eax
  unsigned int v54; // ecx
  int v55; // eax
  int v56; // ecx
  int v57; // esi
  LightingValue_t *v58; // edi
  float *v59; // eax
  int m; // ecx
  int v61; // ecx
  float v62; // xmm0_4
  int v63; // eax
  float x; // xmm1_4
  float y; // xmm1_4
  float z; // xmm1_4
  float *v67; // eax
  const Vector *v68; // edx
  int v69; // eax
  UtlRBTreeNode_t<float,int> *m_pMemory; // ecx
  int v71; // edx
  int v72; // esi
  int v73; // edx
  int v74; // eax
  UtlRBTreeNode_t<float,int> *v75; // ecx
  int v76; // edx
  int v77; // esi
  int v78; // edx
  int v79; // eax
  UtlRBTreeNode_t<float,int> *v80; // ecx
  int v81; // edx
  int v82; // esi
  int v83; // edx
  ColorRGBExp32 *v84; // edi
  _DWORD *v85; // esi
  int v86; // eax
  ColorRGBExp32 *v87; // eax
  int v88; // esi
  int v89; // edi
  int v90; // ebx
  float m_Data; // xmm0_4
  float v92; // xmm1_4
  unsigned __int8 *pdata[4]; // [esp+8h] [ebp-164h] BYREF
  Vector vin; // [esp+18h] [ebp-154h] BYREF
  Vector median; // [esp+24h] [ebp-148h] BYREF
  Vector v96; // [esp+30h] [ebp-13Ch] BYREF
  LightingValue_t v[4]; // [esp+3Ch] [ebp-130h] BYREF
  float minlight; // [esp+7Ch] [ebp-F0h]
  CUtlRBTree<float,int,bool (__cdecl*)(float const &,float const &),CUtlMemory<UtlRBTreeNode_t<float,int>,int> > m_Red; // [esp+80h] [ebp-ECh] BYREF
  CUtlRBTree<float,int,bool (__cdecl*)(float const &,float const &),CUtlMemory<UtlRBTreeNode_t<float,int>,int> > m_Green; // [esp+A4h] [ebp-C8h] BYREF
  CUtlRBTree<float,int,bool (__cdecl*)(float const &,float const &),CUtlMemory<UtlRBTreeNode_t<float,int>,int> > m_Blue; // [esp+C8h] [ebp-A4h] BYREF
  int bumpSampleCount; // [esp+ECh] [ebp-80h]
  BOOL needsBumpmap; // [esp+F0h] [ebp-7Ch]
  LightingValue_t lb[4]; // [esp+F4h] [ebp-78h] BYREF
  ColorRGBExp32 *pAvgColor; // [esp+134h] [ebp-38h]
  int k; // [esp+138h] [ebp-34h]
  int bumpSample; // [esp+13Ch] [ebp-30h]
  dface_t *f; // [esp+140h] [ebp-2Ch]
  int lightstyles; // [esp+144h] [ebp-28h]
  int v110; // [esp+148h] [ebp-24h]
  int j; // [esp+14Ch] [ebp-20h]
  radial_s *prad; // [esp+150h] [ebp-1Ch]
  radial_s *rad; // [esp+154h] [ebp-18h]
  unsigned int v114; // [esp+158h] [ebp-14h]
  int avgCount; // [esp+15Ch] [ebp-10h]
  int parent; // [esp+160h] [ebp-Ch] BYREF
  facelight_t *fl; // [esp+164h] [ebp-8h]
  bool baseSampleOk; // [esp+169h] [ebp-3h]
  bool bDisp; // [esp+16Ah] [ebp-2h]
  bool leftchild; // [esp+16Bh] [ebp-1h] BYREF

  v2 = &g_pFaces[facenum];
  v3 = (::texinfo.m_Memory.m_pMemory[v2->texinfo].flags & 0x404) == 0;
  rad = nullptr;
  prad = nullptr;
  f = v2;
  if ( v3 )
  {
    fl = &facelight[facenum];
    for ( i = 0; i < 4; ++i )
    {
      if ( v2->styles[i] == 0xFF )
        break;
    }
    lightstyles = i;
    if ( i != 0 )
    {
      v5 = FloatForKey(ent: face_entity[facenum], key: "_minlight");
      texinfo = f->texinfo;
      minlight = v5 * 128.0;
      v7 = _g_pMemAlloc->__vftable;
      LOBYTE(needsBumpmap) = (::texinfo.m_Memory.m_pMemory[texinfo].flags & 0x800) != 0;
      v8 = needsBumpmap ? 4 : 1;
      v3 = f->dispinfo == 0xFFFF;
      Alloc_2 = v7->Alloc_2;
      bumpSampleCount = v8;
      bDisp = !v3;
      m_Red.m_LessFunc = (bool (__cdecl *)(const float *, const float *))FloatLess;
      m_Red.m_Elements.m_nAllocationCount = 256;
      m_Red.m_Elements.m_nGrowSize = 0;
      v10 = (UtlRBTreeNode_t<float,int> *)Alloc_2(this: _g_pMemAlloc, a2: 5120u);
      v11 = _g_pMemAlloc->__vftable;
      m_Red.m_Elements.m_pMemory = v10;
      m_Red.m_pElements = v10;
      v12 = v11->Alloc_2;
      m_Red.m_Root = -1;
      m_Red.m_NumElements = 0;
      m_Red.m_FirstFree = -1;
      m_Red.m_LastAlloc.index = -1;
      m_Green.m_LessFunc = (bool (__cdecl *)(const float *, const float *))FloatLess;
      m_Green.m_Elements.m_nAllocationCount = 256;
      m_Green.m_Elements.m_nGrowSize = 0;
      v13 = (UtlRBTreeNode_t<float,int> *)v12(this: _g_pMemAlloc, a2: 5120u);
      v14 = _g_pMemAlloc->__vftable;
      m_Green.m_Elements.m_pMemory = v13;
      m_Green.m_pElements = v13;
      v15 = v14->Alloc_2;
      m_Green.m_Root = -1;
      m_Green.m_NumElements = 0;
      m_Green.m_FirstFree = -1;
      m_Green.m_LastAlloc.index = -1;
      m_Blue.m_LessFunc = (bool (__cdecl *)(const float *, const float *))FloatLess;
      m_Blue.m_Elements.m_nAllocationCount = 256;
      m_Blue.m_Elements.m_nGrowSize = 0;
      m_Blue.m_Root = -1;
      m_Blue.m_FirstFree = -1;
      m_Blue.m_LastAlloc.index = -1;
      v16 = 0;
      m_Blue.m_Elements.m_pMemory = (UtlRBTreeNode_t<float,int> *)v15(this: _g_pMemAlloc, a2: 5120u);
      m_Blue.m_NumElements = 0;
      m_Blue.m_pElements = m_Blue.m_Elements.m_pMemory;
      for ( k = 0; v16 < lightstyles; k = v16 )
      {
        CUtlRBTree<float,int,bool (__cdecl *)(float const &,float const &),CUtlMemory<UtlRBTreeNode_t<float,int>,int>>::RemoveAll(this: &m_Red);
        CUtlRBTree<float,int,bool (__cdecl *)(float const &,float const &),CUtlMemory<UtlRBTreeNode_t<float,int>,int>>::RemoveAll(this: &m_Green);
        CUtlRBTree<float,int,bool (__cdecl *)(float const &,float const &),CUtlMemory<UtlRBTreeNode_t<float,int>,int>>::RemoveAll(this: &m_Blue);
        if ( do_fast == 0 )
        {
          if ( bDisp )
          {
            v18 = StaticDispMgr();
            v17 = v18->BuildLuxelRadial(this: v18, a2: facenum, a3: v16, a4: needsBumpmap);
          }
          else
          {
            v17 = BuildLuxelRadial(facenum, style: v16);
          }
          rad = v17;
        }
        if ( numbounce != 0 && v16 == 0 )
        {
          if ( bDisp )
          {
            v20 = StaticDispMgr();
            v19 = v20->BuildPatchRadial(this: v20, a2: facenum, a3: needsBumpmap);
          }
          else
          {
            v19 = BuildPatchRadial(facenum);
          }
          prad = v19;
        }
        v21 = 0;
        if ( v8 > 0 )
        {
          numluxels = fl->numluxels;
          v23 = 4 * numluxels;
          v24 = &pdlightdata->m_Memory.m_pMemory[4 * v8 * v16 * numluxels + f->lightofs];
          do
          {
            pdata[v21++] = v24;
            v24 += v23;
          }
          while ( v21 < v8 );
        }
        avgCount = 0;
        j = 0;
        if ( fl->numluxels > 0 )
        {
          v114 = 0;
          v110 = 0;
          do
          {
            baseSampleOk = true;
            if ( do_fast != 0 )
            {
              v26 = 0;
              if ( v8 >= 4 )
              {
                v27 = v8 - 4;
                v28 = v110;
                v29 = &fl->light[0][1];
                v30 = (v27 >> 2) + 1;
                p_z = &lb[0].m_vecLighting.z;
                v26 = 4 * v30;
                do
                {
                  v32 = (int)*(v29 - 1);
                  v33 = *(float *)(v32 + v28);
                  v34 = (float *)(v28 + v32);
                  *(p_z - 2) = v33;
                  v29 += 4;
                  p_z += 16;
                  *(p_z - 17) = v34[1];
                  *(p_z - 16) = v34[2];
                  v35 = v34[3];
                  v36 = (int)*(v29 - 4);
                  *(p_z - 15) = v35;
                  v37 = (float *)(v28 + v36);
                  *(p_z - 14) = *v37;
                  *(p_z - 13) = v37[1];
                  *(p_z - 12) = v37[2];
                  v38 = v37[3];
                  v39 = (int)*(v29 - 3);
                  *(p_z - 11) = v38;
                  v40 = (float *)(v28 + v39);
                  *(p_z - 10) = *v40;
                  *(p_z - 9) = v40[1];
                  *(p_z - 8) = v40[2];
                  v41 = v40[3];
                  v42 = (int)*(v29 - 2);
                  *(p_z - 7) = v41;
                  v43 = (float *)(v28 + v42);
                  --v30;
                  *(p_z - 6) = *v43;
                  *(p_z - 5) = v43[1];
                  *(p_z - 4) = v43[2];
                  *(p_z - 3) = v43[3];
                }
                while ( v30 != 0 );
                v8 = bumpSampleCount;
              }
              if ( v26 < v8 )
              {
                v44 = v26;
                v45 = fl->light[v26 / 4u];
                v46 = v8 - v26;
                v47 = v110;
                v48 = &lb[v44].m_vecLighting.z;
                do
                {
                  v49 = (float *)((char *)&(*v45)->m_vecLighting.x + v47);
                  *(v48 - 2) = *v49;
                  ++v45;
                  v48 += 4;
                  --v46;
                  *(v48 - 5) = v49[1];
                  *(v48 - 4) = v49[2];
                  *(v48 - 3) = v49[3];
                }
                while ( v46 != 0 );
              }
            }
            else if ( bDisp )
            {
              v25 = StaticDispMgr();
              baseSampleOk = v25->SampleRadial(
                               this: v25,
                               a2: facenum,
                               a3: rad,
                               a4: &fl->luxel[v114 / 0xC],
                               a5: j,
                               a6: lb,
                               a7: v8,
                               a8: false);
            }
            else
            {
              baseSampleOk = SampleRadial(rad, pnt: &fl->luxel[v114 / 0xC], light: lb, bumpSampleCount: v8);
            }
            v50 = prad;
            if ( prad != nullptr )
            {
              if ( bDisp )
              {
                v51 = StaticDispMgr();
                v51->SampleRadial(
                  this: v51,
                  a2: facenum,
                  a3: v50,
                  a4: &fl->luxel[v114 / 0xC],
                  a5: j,
                  a6: v,
                  a7: v8,
                  a8: true);
              }
              else
              {
                SampleRadial(rad: prad, pnt: &fl->luxel[v114 / 0xC], light: v, bumpSampleCount: v8);
              }
              v52 = 0;
              if ( v8 >= 4 )
              {
                v53 = 0;
                v54 = ((unsigned int)(v8 - 4) >> 2) + 1;
                v52 = 4 * v54;
                do
                {
                  lb[v53].m_vecLighting.x = v[v53].m_vecLighting.x + lb[v53].m_vecLighting.x;
                  lb[v53].m_vecLighting.y = v[v53].m_vecLighting.y + lb[v53].m_vecLighting.y;
                  lb[v53].m_vecLighting.z = v[v53].m_vecLighting.z + lb[v53].m_vecLighting.z;
                  lb[v53].m_flDirectSunAmount = v[v53].m_flDirectSunAmount + lb[v53].m_flDirectSunAmount;
                  lb[v53 + 1].m_vecLighting.x = v[v53 + 1].m_vecLighting.x + lb[v53 + 1].m_vecLighting.x;
                  lb[v53 + 1].m_vecLighting.y = v[v53 + 1].m_vecLighting.y + lb[v53 + 1].m_vecLighting.y;
                  lb[v53 + 1].m_vecLighting.z = v[v53 + 1].m_vecLighting.z + lb[v53 + 1].m_vecLighting.z;
                  lb[v53 + 1].m_flDirectSunAmount = v[v53 + 1].m_flDirectSunAmount + lb[v53 + 1].m_flDirectSunAmount;
                  lb[v53 + 2].m_vecLighting.x = v[v53 + 2].m_vecLighting.x + lb[v53 + 2].m_vecLighting.x;
                  lb[v53 + 2].m_vecLighting.y = v[v53 + 2].m_vecLighting.y + lb[v53 + 2].m_vecLighting.y;
                  lb[v53 + 2].m_vecLighting.z = v[v53 + 2].m_vecLighting.z + lb[v53 + 2].m_vecLighting.z;
                  lb[v53 + 2].m_flDirectSunAmount = v[v53 + 2].m_flDirectSunAmount + lb[v53 + 2].m_flDirectSunAmount;
                  lb[v53 + 3].m_vecLighting.x = v[v53 + 3].m_vecLighting.x + lb[v53 + 3].m_vecLighting.x;
                  lb[v53 + 3].m_vecLighting.y = v[v53 + 3].m_vecLighting.y + lb[v53 + 3].m_vecLighting.y;
                  lb[v53 + 3].m_vecLighting.z = v[v53 + 3].m_vecLighting.z + lb[v53 + 3].m_vecLighting.z;
                  lb[v53 + 3].m_flDirectSunAmount = v[v53 + 3].m_flDirectSunAmount + lb[v53 + 3].m_flDirectSunAmount;
                  v53 += 4;
                  --v54;
                }
                while ( v54 != 0 );
              }
              if ( v52 < v8 )
              {
                v55 = v52;
                v56 = v8 - v52;
                do
                {
                  lb[v55].m_vecLighting.x = v[v55].m_vecLighting.x + lb[v55].m_vecLighting.x;
                  lb[v55].m_vecLighting.y = v[v55].m_vecLighting.y + lb[v55].m_vecLighting.y;
                  lb[v55].m_vecLighting.z = v[v55].m_vecLighting.z + lb[v55].m_vecLighting.z;
                  lb[v55].m_flDirectSunAmount = v[v55].m_flDirectSunAmount + lb[v55].m_flDirectSunAmount;
                  ++v55;
                  --v56;
                }
                while ( v56 != 0 );
              }
            }
            if ( bDisp && g_bDumpPatches != 0 )
            {
              v57 = 0;
              if ( v8 > 0 )
              {
                v58 = lb;
                do
                {
                  DumpDispLuxels(iFace: facenum, color: &v58->m_vecLighting, iLuxel: j, nBump: v57++);
                  ++v58;
                }
                while ( v57 < v8 );
              }
            }
            if ( fl->numsamples == 0 )
            {
              if ( v8 > 0 )
              {
                v59 = &lb[0].m_vecLighting.z;
                for ( m = v8; m != 0; --m )
                {
                  *(v59 - 2) = 255.0;
                  *(v59 - 1) = 0.0;
                  *v59 = 0.0;
                  v59[1] = 0.0;
                  v59 += 4;
                }
              }
              baseSampleOk = false;
            }
            bumpSample = 0;
            if ( v8 > 0 )
            {
              do
              {
                v61 = bumpSample;
                v62 = minlight;
                v63 = bumpSample;
                x = lb[bumpSample].m_vecLighting.x;
                pAvgColor = (ColorRGBExp32 *)(4 * bumpSample);
                if ( x <= minlight )
                  x = minlight;
                lb[bumpSample].m_vecLighting.x = x;
                y = lb[v63].m_vecLighting.y;
                if ( y <= v62 )
                  y = v62;
                lb[v63].m_vecLighting.y = y;
                z = lb[v63].m_vecLighting.z;
                v67 = &lb[v63].m_vecLighting.z;
                if ( z > v62 )
                  v62 = z;
                *v67 = v62;
                if ( v61 == 0 && baseSampleOk )
                {
                  v68 = &fl->luxel[v114 / 0xC];
                  ++avgCount;
                  ApplyMacroTextures(iFace: facenum, vWorldPos: v68, outLuxel: &lb[0].m_vecLighting);
                  parent = -1;
                  leftchild = false;
                  CUtlRBTree<float,int,bool (__cdecl *)(float const &,float const &),CUtlMemory<UtlRBTreeNode_t<float,int>,int>>::FindInsertionPosition(
                    this: &m_Red,
                    insert: &lb[0].m_vecLighting.x,
                    &parent,
                    &leftchild);
                  v69 = CUtlRBTree<float,int,bool (__cdecl *)(float const &,float const &),CUtlMemory<UtlRBTreeNode_t<float,int>,int>>::NewNode(this: &m_Red);
                  m_pMemory = m_Red.m_Elements.m_pMemory;
                  v71 = parent;
                  v72 = v69;
                  m_Red.m_Elements.m_pMemory[v72].m_Parent = parent;
                  m_pMemory[v72].m_Right = -1;
                  m_pMemory[v72].m_Left = -1;
                  m_pMemory[v72].m_Tag = 0;
                  if ( v71 == -1 )
                  {
                    m_Red.m_Root = v69;
                  }
                  else
                  {
                    v73 = v71;
                    if ( leftchild )
                      m_pMemory[v73].m_Left = v69;
                    else
                      m_pMemory[v73].m_Right = v69;
                  }
                  CUtlRBTree<float,int,bool (__cdecl *)(float const &,float const &),CUtlMemory<UtlRBTreeNode_t<float,int>,int>>::InsertRebalance(
                    this: &m_Red,
                    elem: v69);
                  ++m_Red.m_NumElements;
                  if ( &m_Red.m_Elements.m_pMemory[v72] != (UtlRBTreeNode_t<float,int> *)-16 )
                    m_Red.m_Elements.m_pMemory[v72].m_Data = lb[0].m_vecLighting.x;
                  parent = -1;
                  leftchild = false;
                  CUtlRBTree<float,int,bool (__cdecl *)(float const &,float const &),CUtlMemory<UtlRBTreeNode_t<float,int>,int>>::FindInsertionPosition(
                    this: &m_Green,
                    insert: &lb[0].m_vecLighting.y,
                    &parent,
                    &leftchild);
                  v74 = CUtlRBTree<float,int,bool (__cdecl *)(float const &,float const &),CUtlMemory<UtlRBTreeNode_t<float,int>,int>>::NewNode(this: &m_Green);
                  v75 = m_Green.m_Elements.m_pMemory;
                  v76 = parent;
                  v77 = v74;
                  m_Green.m_Elements.m_pMemory[v77].m_Parent = parent;
                  v75[v77].m_Right = -1;
                  v75[v77].m_Left = -1;
                  v75[v77].m_Tag = 0;
                  if ( v76 == -1 )
                  {
                    m_Green.m_Root = v74;
                  }
                  else
                  {
                    v78 = v76;
                    if ( leftchild )
                      v75[v78].m_Left = v74;
                    else
                      v75[v78].m_Right = v74;
                  }
                  CUtlRBTree<float,int,bool (__cdecl *)(float const &,float const &),CUtlMemory<UtlRBTreeNode_t<float,int>,int>>::InsertRebalance(
                    this: &m_Green,
                    elem: v74);
                  ++m_Green.m_NumElements;
                  if ( &m_Green.m_Elements.m_pMemory[v77] != (UtlRBTreeNode_t<float,int> *)-16 )
                    m_Green.m_Elements.m_pMemory[v77].m_Data = lb[0].m_vecLighting.y;
                  parent = -1;
                  leftchild = false;
                  CUtlRBTree<float,int,bool (__cdecl *)(float const &,float const &),CUtlMemory<UtlRBTreeNode_t<float,int>,int>>::FindInsertionPosition(
                    this: &m_Blue,
                    insert: &lb[0].m_vecLighting.z,
                    &parent,
                    &leftchild);
                  v79 = CUtlRBTree<float,int,bool (__cdecl *)(float const &,float const &),CUtlMemory<UtlRBTreeNode_t<float,int>,int>>::NewNode(this: &m_Blue);
                  v80 = m_Blue.m_Elements.m_pMemory;
                  v81 = parent;
                  v82 = v79;
                  m_Blue.m_Elements.m_pMemory[v82].m_Parent = parent;
                  v80[v82].m_Right = -1;
                  v80[v82].m_Left = -1;
                  v80[v82].m_Tag = 0;
                  if ( v81 == -1 )
                  {
                    m_Blue.m_Root = v79;
                  }
                  else
                  {
                    v83 = v81;
                    if ( leftchild )
                      v80[v83].m_Left = v79;
                    else
                      v80[v83].m_Right = v79;
                  }
                  CUtlRBTree<float,int,bool (__cdecl *)(float const &,float const &),CUtlMemory<UtlRBTreeNode_t<float,int>,int>>::InsertRebalance(
                    this: &m_Blue,
                    elem: v79);
                  ++m_Blue.m_NumElements;
                  if ( &m_Blue.m_Elements.m_pMemory[v82] != (UtlRBTreeNode_t<float,int> *)-16 )
                    m_Blue.m_Elements.m_pMemory[v82].m_Data = lb[0].m_vecLighting.z;
                }
                v84 = *(ColorRGBExp32 **)((char *)pdata + (_DWORD)pAvgColor);
                v85 = (unsigned __int8 **)((char *)pdata + (_DWORD)pAvgColor);
                vin.x = lb[bumpSample].m_vecLighting.x;
                vin.y = lb[bumpSample].m_vecLighting.y;
                vin.z = lb[bumpSample].m_vecLighting.z;
                VectorToColorRGBExp32(&vin, c: v84);
                v86 = bumpSample + 1;
                *v85 = v84 + 1;
                bumpSample = v86;
              }
              while ( v86 < v8 );
            }
            v110 += 16;
            v114 += 12;
            ++j;
          }
          while ( j < fl->numluxels );
          v16 = k;
        }
        if ( rad != nullptr )
          free(pMem: rad);
        if ( prad != nullptr )
        {
          free(pMem: prad);
          prad = nullptr;
        }
        v87 = (ColorRGBExp32 *)&pdlightdata->m_Memory.m_pMemory[f->lightofs - 4 + -4 * v16];
        pAvgColor = v87;
        if ( avgCount != 0 )
        {
          v88 = CUtlRBTree<float,int,bool (__cdecl *)(float const &,float const &),CUtlMemory<UtlRBTreeNode_t<float,int>,int>>::FirstInorder(this: &m_Red);
          v89 = CUtlRBTree<float,int,bool (__cdecl *)(float const &,float const &),CUtlMemory<UtlRBTreeNode_t<float,int>,int>>::FirstInorder(this: &m_Green);
          v90 = CUtlRBTree<float,int,bool (__cdecl *)(float const &,float const &),CUtlMemory<UtlRBTreeNode_t<float,int>,int>>::FirstInorder(this: &m_Blue);
          for ( avgCount >>= 1; avgCount > 0; --avgCount )
          {
            v88 = CUtlRBTree<float,int,bool (__cdecl *)(float const &,float const &),CUtlMemory<UtlRBTreeNode_t<float,int>,int>>::NextInorder(
                    this: &m_Red,
                    i: v88);
            v89 = CUtlRBTree<float,int,bool (__cdecl *)(float const &,float const &),CUtlMemory<UtlRBTreeNode_t<float,int>,int>>::NextInorder(
                    this: &m_Green,
                    i: v89);
            v90 = CUtlRBTree<float,int,bool (__cdecl *)(float const &,float const &),CUtlMemory<UtlRBTreeNode_t<float,int>,int>>::NextInorder(
                    this: &m_Blue,
                    i: v90);
          }
          m_Data = m_Green.m_Elements.m_pMemory[v89].m_Data;
          v92 = m_Blue.m_Elements.m_pMemory[v90].m_Data;
          v96.x = m_Red.m_Elements.m_pMemory[v88].m_Data;
          v96.y = m_Data;
          v96.z = v92;
          VectorToColorRGBExp32(vin: &v96, c: pAvgColor);
          v8 = bumpSampleCount;
          v16 = k;
        }
        else
        {
          memset(&median, 0, sizeof(median));
          VectorToColorRGBExp32(vin: &median, c: v87);
        }
        ++v16;
      }
      CUtlRBTree<float,int,bool (__cdecl *)(float const &,float const &),CUtlMemory<UtlRBTreeNode_t<float,int>,int>>::RemoveAll(this: &m_Blue);
      if ( m_Blue.m_Elements.m_nGrowSize >= 0 && m_Blue.m_Elements.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_Blue.m_Elements.m_pMemory);
      CUtlRBTree<float,int,bool (__cdecl *)(float const &,float const &),CUtlMemory<UtlRBTreeNode_t<float,int>,int>>::RemoveAll(this: &m_Green);
      if ( m_Green.m_Elements.m_nGrowSize >= 0 && m_Green.m_Elements.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_Green.m_Elements.m_pMemory);
      CUtlRBTree<float,int,bool (__cdecl *)(float const &,float const &),CUtlMemory<UtlRBTreeNode_t<float,int>,int>>::RemoveAll(this: &m_Red);
      if ( m_Red.m_Elements.m_nGrowSize >= 0 && m_Red.m_Elements.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_Red.m_Elements.m_pMemory);
    }
  }
}
