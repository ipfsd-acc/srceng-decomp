// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/gl_lightmap.cpp
// Functions: 30
// ============================================================

#include "engine\gl_lightmap.h"

//------------------------------------------------------------------------------
// Address: 0x1006B9F0
// Name: R_ComputeSurfaceBasis
// Source: json
//------------------------------------------------------------------------------
void __usercall R_ComputeSurfaceBasis(
        msurface2_t *surfID@<eax>,
        Vector *luxelBasePosition@<edx>,
        Vector *tVect@<ecx>,
        Vector *sVect)
{
  int v5; // eax
  float v6; // xmm0_4
  float z; // xmm2_4
  float v8; // xmm3_4
  float *v9; // edx
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float y; // xmm5_4
  float v16; // xmm6_4
  int v17; // eax

  CalculateLuxelToWorldTransform(
    vFaceNormal: &surfID->plane->normal,
    pLuxelOrigin: luxelBasePosition,
    pS: sVect,
    pT: tVect,
    pTexInfo: &host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1],
    flFaceDistance: surfID->plane->dist);
  v6 = (float)*(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapMins
                         + ((v5 - (unsigned int)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  z = sVect->z;
  v8 = sVect->x * v6;
  v10 = (float)(sVect->y * v6) + v9[1];
  v9[1] = v10;
  v11 = z * v6;
  v12 = *v9;
  v13 = v11 + v9[2];
  v9[2] = v13;
  v14 = v12 + v8;
  *v9 = v14;
  y = tVect->y;
  v16 = tVect->z;
  v17 = *(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_LightmapMins[1]
                   + ((v5 - (unsigned int)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  *v9 = v14 + (float)(tVect->x * (float)v17);
  v9[1] = v10 + (float)(y * (float)v17);
  v9[2] = v13 + (float)(v16 * (float)v17);
}

//------------------------------------------------------------------------------
// Address: 0x100C47F0
// Name: void R_MarkDLightNotVisible(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_MarkDLightNotVisible(char dlight)
{
  if ( ((1 << dlight) & r_dlightvisible) != 0 )
  {
    --s_nVisibleDLightCount;
    r_dlightvisible &= ~(1 << dlight);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C4820
// Name: void R_DLightEndView(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DLightEndView()
{
  int v0; // ecx
  int v1; // edx
  int v2; // eax
  int i; // esi

  if ( g_bActiveDlights )
  {
    v0 = r_dlightvisible;
    v1 = s_nVisibleDLightCount;
    v2 = 1;
    for ( i = 32; i != 0; --i )
    {
      if ( (v2 & r_dlightvisiblethisframe) == 0 && (v2 & v0) != 0 )
      {
        --v1;
        v0 &= ~v2;
      }
      v2 = __ROL4__(v2, 1);
    }
    r_dlightvisible = v0;
    s_nVisibleDLightCount = v1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C4870
// Name: bool R_CanUseVisibleDLight(int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl R_CanUseVisibleDLight(char dlight)
{
  r_dlightvisiblethisframe |= 1 << dlight;
  if ( ((1 << dlight) & r_dlightvisible) == 0 )
  {
    if ( s_nVisibleDLightCount >= s_nMaxVisibleDLightCount )
      return 0;
    ++s_nVisibleDLightCount;
    r_dlightvisible |= 1 << dlight;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C48B0
// Name: void CacheAndUnloadLightmapData(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CacheAndUnloadLightmapData()
{
  msurfacelighting_t *surfacelighting; // esi
  int numsurfaces; // edi
  ColorRGBExp32 *v2; // ebx
  unsigned __int8 *v3; // esi
  int v4; // eax
  int v5; // edi
  unsigned __int8 *pDestBase; // [esp+0h] [ebp-8h]
  int i; // [esp+4h] [ebp-4h]

  if ( !g_bHunkAllocLightmaps )
  {
    surfacelighting = host_state.worldbrush->surfacelighting;
    numsurfaces = host_state.worldbrush->numsurfaces;
    v2 = (ColorRGBExp32 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 16 * numsurfaces);
    pDestBase = (unsigned __int8 *)v2;
    if ( numsurfaces > 0 )
    {
      v3 = &surfacelighting->m_nStyles[1];
      for ( i = numsurfaces; i != 0; --i )
      {
        v4 = *(v3 - 1) != 0xFF;
        if ( *v3 != 0xFF )
          ++v4;
        if ( v3[1] != 0xFF )
          ++v4;
        if ( v3[2] != 0xFF )
          ++v4;
        v5 = 4 * v4;
        _V_memcpy(dest: v2, src: (const void *)(*(_DWORD *)(v3 + 3) - 4 * v4), count: 4 * v4);
        v2 = (ColorRGBExp32 *)((char *)v2 + v5);
        *(_DWORD *)(v3 + 3) = v2;
        v3 += 32;
      }
      v2 = (ColorRGBExp32 *)pDestBase;
    }
    DeallocateLightingData(pBrushData: host_state.worldbrush);
    host_state.worldbrush->lightdata = v2;
    host_state.worldbrush->m_bUnloadedAllLightmaps = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C4970
// Name: void GL_RebuildLightmaps(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GL_RebuildLightmaps()
{
  g_RebuildLightmaps = true;
}

//------------------------------------------------------------------------------
// Address: 0x100C49E0
// Name: void R_DLightStartView(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DLightStartView()
{
  r_dlightvisiblethisframe = 0;
  if ( r_maxdlights.m_pParent != nullptr )
    s_nMaxVisibleDLightCount = r_maxdlights.m_pParent->m_Value.m_nValue;
  else
    s_nMaxVisibleDLightCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100C4A10
// Name: AddSingleDynamicLight
// Source: json
//------------------------------------------------------------------------------
char __usercall AddSingleDynamicLight@<al>(
        dlight_t *dl@<edx>,
        msurface2_t *surfID@<ecx>,
        const Vector *lightOrigin@<eax>,
        float perpDistSq,
        float lightRadiusSq)
{
  float m_OuterAngle; // xmm0_4
  double minlight; // st7
  float y; // xmm3_4
  float z; // xmm4_4
  float *v12; // edx
  __int16 *v13; // eax
  float v14; // xmm7_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  msurfacelighting_t *surfacelighting; // eax
  unsigned int v18; // ecx
  int v19; // edi
  float v20; // xmm1_4
  int v21; // ebx
  int v22; // esi
  float v23; // xmm3_4
  int v24; // ecx
  float v25; // xmm6_4
  float v26; // xmm0_4
  float v27; // xmm0_4
  float v28; // xmm2_4
  float v29; // xmm1_4
  unsigned int v30; // eax
  int v31; // xmm0_4
  float v32; // xmm0_4
  float v33; // xmm0_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  unsigned int v36; // eax
  int v37; // xmm0_4
  float v38; // xmm0_4
  float v39; // xmm0_4
  float v40; // xmm2_4
  float v41; // xmm1_4
  unsigned int v42; // eax
  int v43; // xmm0_4
  float v44; // xmm0_4
  float v45; // xmm0_4
  float v46; // xmm2_4
  float v47; // xmm1_4
  unsigned int v48; // eax
  int v49; // xmm0_4
  float v50; // xmm3_4
  float v51; // xmm0_4
  float v52; // xmm0_4
  float v53; // xmm2_4
  float v54; // xmm1_4
  unsigned int v55; // eax
  int v56; // xmm0_4
  float local_4; // [esp+4h] [ebp-28h]
  float intensity; // [esp+Ch] [ebp-20h]
  float intensity_4; // [esp+10h] [ebp-1Ch]
  float intensity_8; // [esp+14h] [ebp-18h]
  int tmax; // [esp+18h] [ebp-14h]
  int t; // [esp+20h] [ebp-Ch]
  float ooQuadraticAttn; // [esp+28h] [ebp-4h]

  m_OuterAngle = dl->m_OuterAngle;
  if ( m_OuterAngle != 0.0
    && m_OuterAngle < 180.0
    && (float)((float)((float)(dl->m_Direction.y * surfID->plane->normal.y)
                     + (float)(surfID->plane->normal.x * dl->m_Direction.x))
             + (float)(dl->m_Direction.z * surfID->plane->normal.z)) >= 0.0 )
  {
    return 0;
  }
  minlight = dl->minlight;
  y = lightOrigin->y;
  z = lightOrigin->z;
  v12 = (float *)&host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1];
  v13 = (__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapMins
                  + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  v14 = (float)((float)((float)((float)(v12[9] * y) + (float)(lightOrigin->x * v12[8])) + (float)(v12[10] * z)) + v12[11])
      - (float)*v13;
  local_4 = (float)((float)((float)((float)(v12[13] * y) + (float)(lightOrigin->x * v12[12])) + (float)(v12[14] * z))
                  + v12[15])
          - (float)v13[1];
  v15 = dword_10425B80[dl->color.exponent];
  v16 = (float)d_lightstylevalue[dl->style] * 0.0037878789;
  intensity = (float)((float)dl->color.r * v15) * v16;
  intensity_4 = (float)((float)dl->color.g * v15) * v16;
  intensity_8 = (float)((float)dl->color.b * v15) * v16;
  if ( g_flMinLightingValue >= minlight )
    minlight = g_flMinLightingValue;
  surfacelighting = host_state.worldbrush->surfacelighting;
  v18 = ((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0;
  ooQuadraticAttn = minlight * lightRadiusSq;
  v19 = 0;
  v20 = 1.0 / lightRadiusSq;
  v21 = *(__int16 *)((char *)surfacelighting->m_LightmapExtents + v18) + 1;
  tmax = *(__int16 *)((char *)&surfacelighting->m_LightmapExtents[1] + v18) + 1;
  t = 0;
  if ( tmax > 0 )
  {
    v22 = 2;
    do
    {
      v23 = (float)(local_4 - (float)v19) * v12[17];
      v24 = 0;
      if ( v21 >= 4 )
      {
        v25 = v23 * v23;
        do
        {
          v26 = (float)(v14 - (float)v24) * v12[17];
          v27 = (float)((float)(v26 * v26) + v25) + perpDistSq;
          if ( lightRadiusSq > v27 )
          {
            if ( v27 == 0.0 )
              v28 = 1.0;
            else
              v28 = ooQuadraticAttn / v27;
            v29 = (float)(1.0 - (float)(v27 * v20)) * v28;
            if ( v29 > 2.0 )
              v29 = 2.0;
            v30 = 4 * (v22 + v24 - 2);
            blocklights[0][v30 / 4].x = (float)(intensity * v29) + blocklights[0][v30 / 4].x;
            *(float *)&dword_104F1D84[v30] = (float)(intensity_4 * v29) + *(float *)&dword_104F1D84[v30];
            *(float *)&v31 = (float)(intensity_8 * v29) + *(float *)&dword_104F1D88[v30];
            v20 = 1.0 / lightRadiusSq;
            dword_104F1D88[v30] = v31;
          }
          v32 = (float)(v14 - (float)(v24 + 1)) * v12[17];
          v33 = (float)((float)(v32 * v32) + v25) + perpDistSq;
          if ( lightRadiusSq > v33 )
          {
            if ( v33 == 0.0 )
              v34 = 1.0;
            else
              v34 = ooQuadraticAttn / v33;
            v35 = (float)(1.0 - (float)(v33 * v20)) * v34;
            if ( v35 > 2.0 )
              v35 = 2.0;
            v36 = 4 * (v22 + v24 - 1);
            blocklights[0][v36 / 4].x = (float)(intensity * v35) + blocklights[0][v36 / 4].x;
            *(float *)&dword_104F1D84[v36] = (float)(intensity_4 * v35) + *(float *)&dword_104F1D84[v36];
            *(float *)&v37 = (float)(intensity_8 * v35) + *(float *)&dword_104F1D88[v36];
            v20 = 1.0 / lightRadiusSq;
            dword_104F1D88[v36] = v37;
          }
          v38 = (float)(v14 - (float)(v24 + 2)) * v12[17];
          v39 = (float)((float)(v38 * v38) + v25) + perpDistSq;
          if ( lightRadiusSq > v39 )
          {
            if ( v39 == 0.0 )
              v40 = 1.0;
            else
              v40 = ooQuadraticAttn / v39;
            v41 = (float)(1.0 - (float)(v39 * v20)) * v40;
            if ( v41 > 2.0 )
              v41 = 2.0;
            v42 = 4 * (v22 + v24);
            blocklights[0][v42 / 4].x = (float)(intensity * v41) + blocklights[0][v42 / 4].x;
            *(float *)&dword_104F1D84[v42] = (float)(intensity_4 * v41) + *(float *)&dword_104F1D84[v42];
            *(float *)&v43 = (float)(intensity_8 * v41) + *(float *)&dword_104F1D88[v42];
            v20 = 1.0 / lightRadiusSq;
            dword_104F1D88[v42] = v43;
          }
          v44 = (float)(v14 - (float)(v24 + 3)) * v12[17];
          v45 = (float)((float)(v44 * v44) + v25) + perpDistSq;
          if ( lightRadiusSq > v45 )
          {
            if ( v45 == 0.0 )
              v46 = 1.0;
            else
              v46 = ooQuadraticAttn / v45;
            v47 = (float)(1.0 - (float)(v45 * v20)) * v46;
            if ( v47 > 2.0 )
              v47 = 2.0;
            v48 = 4 * (v22 + v24 + 1);
            blocklights[0][v48 / 4].x = (float)(intensity * v47) + blocklights[0][v48 / 4].x;
            *(float *)&dword_104F1D84[v48] = (float)(intensity_4 * v47) + *(float *)&dword_104F1D84[v48];
            *(float *)&v49 = (float)(intensity_8 * v47) + *(float *)&dword_104F1D88[v48];
            v20 = 1.0 / lightRadiusSq;
            dword_104F1D88[v48] = v49;
          }
          v24 += 4;
        }
        while ( v24 < v21 - 3 );
        v19 = t;
      }
      if ( v24 < v21 )
      {
        v50 = v23 * v23;
        do
        {
          v51 = (float)(v14 - (float)v24) * v12[17];
          v52 = (float)((float)(v51 * v51) + v50) + perpDistSq;
          if ( lightRadiusSq > v52 )
          {
            if ( v52 == 0.0 )
              v53 = 1.0;
            else
              v53 = ooQuadraticAttn / v52;
            v54 = (float)(1.0 - (float)(v52 * v20)) * v53;
            if ( v54 > 2.0 )
              v54 = 2.0;
            v55 = 4 * (v22 + v24 - 2);
            blocklights[0][v55 / 4].x = (float)(intensity * v54) + blocklights[0][v55 / 4].x;
            *(float *)&dword_104F1D84[v55] = (float)(intensity_4 * v54) + *(float *)&dword_104F1D84[v55];
            *(float *)&v56 = (float)(intensity_8 * v54) + *(float *)&dword_104F1D88[v55];
            v20 = 1.0 / lightRadiusSq;
            dword_104F1D88[v55] = v56;
          }
          ++v24;
        }
        while ( v24 < v21 );
      }
      ++v19;
      v22 += v21;
      t = v19;
    }
    while ( v19 < tmax );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C5000
// Name: AddSingleDynamicLightToBumpLighting
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddSingleDynamicLightToBumpLighting(
        msurface2_t *surfID,
        const Vector *lightOrigin,
        float perpDistSq,
        float lightRadiusSq,
        Vector *pBumpBasis,
        const Vector *luxelBasePosition)
{
  dlight_t *dl; // ecx
  const Vector *v7; // edx
  double minlight; // st7
  float y; // xmm2_4
  float z; // xmm3_4
  float *v11; // esi
  __int16 *v12; // eax
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm3_4
  float v16; // xmm4_4
  float v17; // xmm5_4
  float m_OuterAngle; // xmm0_4
  double v19; // st7
  double x; // st6
  float v21; // xmm0_4
  char *v22; // eax
  int v23; // ecx
  int v24; // eax
  int v25; // edi
  int v26; // ecx
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm6_4
  float v31; // xmm7_4
  int v32; // ebx
  float v33; // xmm0_4
  float v34; // xmm0_4
  float v35; // xmm2_4
  float v36; // xmm1_4
  int v37; // edi
  bool v38; // zf
  float *p_x; // eax
  double v40; // st7
  float v41; // xmm0_4
  float v42; // xmm1_4
  float v43; // xmm0_4
  float *v44; // eax
  float v45; // xmm0_4
  float v46; // xmm0_4
  float *v47; // eax
  float v48; // xmm0_4
  float v49; // xmm0_4
  float v50; // xmm0_4
  int v51; // edi
  float local; // [esp+0h] [ebp-5Ch]
  float local_4; // [esp+4h] [ebp-58h]
  float intensity; // [esp+Ch] [ebp-50h]
  float intensity_4; // [esp+10h] [ebp-4Ch]
  float intensity_8; // [esp+14h] [ebp-48h]
  float texelWorldPosition; // [esp+18h] [ebp-44h]
  float texelWorldPosition_4; // [esp+1Ch] [ebp-40h]
  float texelWorldPosition_8; // [esp+20h] [ebp-3Ch]
  Vector lightDirection; // [esp+24h] [ebp-38h] BYREF
  int tmax; // [esp+30h] [ebp-2Ch]
  float lDotN; // [esp+34h] [ebp-28h]
  float ooRadiusSq; // [esp+38h] [ebp-24h]
  float ooQuadraticAttn; // [esp+3Ch] [ebp-20h]
  float v65; // [esp+40h] [ebp-1Ch]
  float fixupFactor; // [esp+44h] [ebp-18h]
  int t; // [esp+48h] [ebp-14h]
  int smax; // [esp+4Ch] [ebp-10h]
  float scale; // [esp+50h] [ebp-Ch]
  int v70; // [esp+54h] [ebp-8h]
  bool useLightDirection; // [esp+5Bh] [ebp-1h]

  v7 = lightOrigin;
  minlight = dl->minlight;
  y = lightOrigin->y;
  z = lightOrigin->z;
  v11 = (float *)&host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1];
  v12 = (__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapMins
                  + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  local = (float)((float)((float)((float)(v11[9] * y) + (float)(lightOrigin->x * v11[8])) + (float)(v11[10] * z))
                + v11[11])
        - (float)*v12;
  local_4 = (float)((float)((float)((float)(lightOrigin->x * v11[12]) + (float)(y * v11[13])) + (float)(z * v11[14]))
                  + v11[15])
          - (float)v12[1];
  v13 = dword_10425B80[dl->color.exponent];
  v14 = (float)d_lightstylevalue[dl->style] * 0.0037878789;
  v15 = (float)((float)dl->color.r * v13) * v14;
  v16 = (float)((float)dl->color.g * v13) * v14;
  v17 = (float)((float)dl->color.b * v13) * v14;
  intensity = v15;
  intensity_4 = v16;
  intensity_8 = v17;
  if ( g_flMinLightingValue >= minlight )
    minlight = g_flMinLightingValue;
  ooRadiusSq = 1.0 / lightRadiusSq;
  m_OuterAngle = dl->m_OuterAngle;
  ooQuadraticAttn = minlight * lightRadiusSq;
  if ( m_OuterAngle == 0.0
    || (v19 = dl->m_Direction.y,
        x = dl->m_Direction.x,
        t = SLODWORD(dl->m_Direction.x),
        fabs(v19 * v19 + x * x + dl->m_Direction.z * dl->m_Direction.z - 1.0) >= 0.001) )
  {
    useLightDirection = false;
  }
  else
  {
    lightDirection.x = *(float *)&t * -1.0;
    lightDirection.y = dl->m_Direction.y * -1.0;
    v21 = dl->m_Direction.z * -1.0;
    useLightDirection = true;
    lightDirection.z = v21;
  }
  v22 = (char *)host_state.worldbrush->surfacelighting
      + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0);
  v23 = *((__int16 *)v22 + 2);
  v24 = *((__int16 *)v22 + 3) + 1;
  v25 = 0;
  v26 = v23 + 1;
  v27 = v11[17] * v11[17];
  fixupFactor = v27;
  smax = v26;
  tmax = v24;
  *(float *)&t = 0.0;
  if ( v24 > 0 )
  {
    v70 = 0;
    while ( 1 )
    {
      v29 = (float)v25 * v27;
      v30 = (float)(v11[12] * v29) + luxelBasePosition->x;
      v31 = (float)(v11[13] * v29) + luxelBasePosition->y;
      v32 = 0;
      texelWorldPosition = v30;
      texelWorldPosition_4 = v31;
      texelWorldPosition_8 = (float)(v11[14] * v29) + luxelBasePosition->z;
      if ( v26 > 0 )
      {
        v28 = (float)(local_4 - (float)v25) * v11[17];
        v65 = v28 * v28;
        do
        {
          v33 = (float)(local - (float)v32) * v11[17];
          v34 = (float)((float)(v33 * v33) + v65) + perpDistSq;
          if ( lightRadiusSq > v34 )
          {
            if ( v34 == 0.0 )
              v35 = 1.0;
            else
              v35 = ooQuadraticAttn / v34;
            v36 = (float)(1.0 - (float)(v34 * ooRadiusSq)) * v35;
            scale = v36;
            if ( v36 > 2.0 )
            {
              v36 = 2.0;
              scale = 2.0;
            }
            v37 = v32 + v70;
            v38 = !useLightDirection;
            p_x = &blocklights[0][v32 + v70].x;
            *p_x = (float)(v15 * v36) + *p_x;
            p_x[1] = (float)(v16 * v36) + p_x[1];
            p_x[2] = (float)(v17 * v36) + p_x[2];
            if ( v38 )
            {
              lightDirection.x = v7->x - v30;
              lightDirection.y = v7->y - v31;
              lightDirection.z = v7->z - texelWorldPosition_8;
              VectorNormalize(vec: &lightDirection);
              v36 = scale;
              v30 = texelWorldPosition;
              v17 = intensity_8;
              v16 = intensity_4;
              v15 = intensity;
              v7 = lightOrigin;
            }
            v40 = surfID->plane->normal.y * lightDirection.y
                + surfID->plane->normal.x * lightDirection.x
                + surfID->plane->normal.z * lightDirection.z;
            lDotN = v40;
            if ( v40 >= 0.001 )
              v41 = lDotN;
            else
              v41 = 0.001;
            v42 = v36 * v41;
            v43 = (float)((float)(pBumpBasis->y * lightDirection.y) + (float)(pBumpBasis->x * lightDirection.x))
                + (float)(pBumpBasis->z * lightDirection.z);
            if ( v43 > 0.0 )
            {
              v44 = &flt_10531D80[4 * v37];
              v45 = v43 * v42;
              *v44 = (float)(v15 * v45) + *v44;
              v44[1] = (float)(v16 * v45) + v44[1];
              v44[2] = (float)(v17 * v45) + v44[2];
            }
            v46 = (float)((float)(pBumpBasis[1].y * lightDirection.y) + (float)(pBumpBasis[1].x * lightDirection.x))
                + (float)(pBumpBasis[1].z * lightDirection.z);
            if ( v46 > 0.0 )
            {
              v47 = &flt_10571D80[4 * v37];
              v48 = v46 * v42;
              *v47 = (float)(v15 * v48) + *v47;
              v47[1] = (float)(v16 * v48) + v47[1];
              v47[2] = (float)(v17 * v48) + v47[2];
            }
            v31 = texelWorldPosition_4;
            v26 = smax;
            v49 = (float)((float)(pBumpBasis[2].y * lightDirection.y) + (float)(pBumpBasis[2].x * lightDirection.x))
                + (float)(pBumpBasis[2].z * lightDirection.z);
            if ( v49 > 0.0 )
            {
              v50 = v49 * v42;
              v51 = 4 * v37;
              *(float *)&dword_105B1D80[v51] = (float)(v15 * v50) + *(float *)&dword_105B1D80[v51];
              *(float *)&dword_105B1D84[v51] = (float)(v16 * v50) + *(float *)&dword_105B1D84[v51];
              *(float *)&dword_105B1D88[v51] = (float)(v17 * v50) + *(float *)&dword_105B1D88[v51];
            }
          }
          ++v32;
        }
        while ( v32 < v26 );
        v25 = t;
      }
      v70 += v26;
      t = ++v25;
      if ( v25 >= tmax )
        break;
      v27 = fixupFactor;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C5560
// Name: R_ComputeSurfaceBasis_0
// Source: json
//------------------------------------------------------------------------------
void __usercall R_ComputeSurfaceBasis_0(
        msurface2_t *surfID@<eax>,
        Vector *luxelBasePosition@<esi>,
        Vector *pBumpNormals)
{
  mtexinfo_t *texinfo; // edx
  int v5; // eax
  float x; // xmm0_4
  int lightmapVecsLuxelsPerWorldUnits; // eax
  mtexinfo_t *v8; // eax
  float v9; // xmm0_4
  int v10; // eax
  mtexinfo_t *v11; // eax
  int v12; // edx
  float worldUnitsPerLuxel; // xmm1_4
  float *v14; // eax
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  float *v18; // eax
  float v19; // xmm0_4
  cplane_t *plane; // edi
  float dist; // xmm0_4
  Vector sVect; // [esp+4h] [ebp-18h] BYREF
  Vector tVect; // [esp+10h] [ebp-Ch] BYREF

  texinfo = host_state.worldbrush->texinfo;
  v5 = *((unsigned __int16 *)surfID + 11) >> 1;
  x = texinfo[v5].lightmapVecsLuxelsPerWorldUnits[0].x;
  lightmapVecsLuxelsPerWorldUnits = (int)texinfo[v5].lightmapVecsLuxelsPerWorldUnits;
  sVect.x = x;
  sVect.y = *(float *)(lightmapVecsLuxelsPerWorldUnits + 4);
  sVect.z = *(float *)(lightmapVecsLuxelsPerWorldUnits + 8);
  VectorNormalize(vec: &sVect);
  v8 = host_state.worldbrush->texinfo;
  v9 = v8[*((unsigned __int16 *)surfID + 11) >> 1].lightmapVecsLuxelsPerWorldUnits[1].x;
  v10 = (int)&v8[*((unsigned __int16 *)surfID + 11) >> 1].lightmapVecsLuxelsPerWorldUnits[1];
  tVect.x = v9;
  tVect.y = *(float *)(v10 + 4);
  tVect.z = *(float *)(v10 + 8);
  VectorNormalize(vec: &tVect);
  GetBumpNormals(
    &sVect,
    &tVect,
    flatNormal: &surfID->plane->normal,
    phongNormal: &surfID->plane->normal,
    bumpNormals: pBumpNormals);
  v11 = host_state.worldbrush->texinfo;
  v12 = *((unsigned __int16 *)surfID + 11) >> 1;
  worldUnitsPerLuxel = v11[v12].worldUnitsPerLuxel;
  v14 = (float *)&v11[v12];
  v15 = worldUnitsPerLuxel * worldUnitsPerLuxel;
  v16 = (float)((float)*(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapMins
                                  + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0))
              - v14[11])
      * v15;
  luxelBasePosition->x = v16 * v14[8];
  luxelBasePosition->y = v14[9] * v16;
  v17 = v14[10] * v16;
  luxelBasePosition->z = v17;
  v18 = (float *)&host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1];
  v19 = (float)((float)*(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_LightmapMins[1]
                                  + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0))
              - v18[15])
      * v15;
  luxelBasePosition->x = (float)(v18[12] * v19) + luxelBasePosition->x;
  luxelBasePosition->y = (float)(v18[13] * v19) + luxelBasePosition->y;
  luxelBasePosition->z = (float)(v18[14] * v19) + v17;
  plane = surfID->plane;
  dist = plane->dist;
  luxelBasePosition->x = (float)(plane->normal.x * dist) + luxelBasePosition->x;
  luxelBasePosition->y = (float)(plane->normal.y * dist) + luxelBasePosition->y;
  luxelBasePosition->z = (float)(plane->normal.z * dist) + luxelBasePosition->z;
}

//------------------------------------------------------------------------------
// Address: 0x100C5730
// Name: unsigned int R_ComputeDynamicLightMask(struct dlight_t __near *,struct msurface2_t __near *,struct msurfacelighting_t __near *,struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl R_ComputeDynamicLightMask(
        dlight_t *pLights,
        msurface2_t *surfID,
        msurfacelighting_t *pLighting,
        const matrix3x4_t *entityToWorld)
{
  int v5; // ebx
  int v6; // esi
  float *p_radius; // edi
  float v8; // xmm0_4
  Vector lightOrigin; // [esp+0h] [ebp-14h] BYREF
  int lightMask; // [esp+Ch] [ebp-8h]
  int mask; // [esp+10h] [ebp-4h]

  if ( (surfID->flags & 0x800) != 0 )
    return surfID->pDispInfo->ComputeDynamicLightMask(this: surfID->pDispInfo, a2: pLights);
  v5 = 0;
  if ( !g_bActiveDlights )
    return 0;
  lightMask = 0;
  v6 = 1;
  mask = r_dlightactive;
  p_radius = &pLights->radius;
  do
  {
    if ( (mask & 1) != 0
      && (v6 & pLighting->m_fDLightBits) != 0
      && (*(_BYTE *)(p_radius - 4) & 0xD) == 0
      && R_CanUseVisibleDLight(dlight: v5) != 0 )
    {
      VectorITransform(in1: p_radius - 3, in2: entityToWorld, out: &lightOrigin.x);
      v8 = (float)((float)((float)(surfID->plane->normal.y * lightOrigin.y)
                         + (float)(lightOrigin.x * surfID->plane->normal.x))
                 + (float)(surfID->plane->normal.z * lightOrigin.z))
         - surfID->plane->dist;
      if ( v8 >= -15.0 )
      {
        if ( (float)(v8 * v8) < (float)(*p_radius * *p_radius) )
          lightMask |= v6;
        else
          pLighting->m_fDLightBits &= ~v6;
      }
      else
      {
        pLighting->m_fDLightBits &= ~v6;
      }
    }
    mask >>= 1;
    ++v5;
    p_radius += 17;
    v6 *= 2;
  }
  while ( v5 < 32 );
  return lightMask;
}

//------------------------------------------------------------------------------
// Address: 0x100C5850
// Name: ComputeLightmapSize
// Source: json
//------------------------------------------------------------------------------
int __fastcall ComputeLightmapSize(int a1, msurface2_t *surfID)
{
  char *v2; // ecx
  int result; // eax
  int v4; // ecx
  IMaterial *material; // ecx
  const char *v6; // eax

  v2 = (char *)host_state.worldbrush->surfacelighting
     + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0);
  result = (*((__int16 *)v2 + 2) + 1) * (*((__int16 *)v2 + 3) + 1);
  v4 = (surfID->flags & 0x800) != 0 ? 128 : 35;
  if ( result > v4 * v4 )
  {
    material = materialSortInfoArray[surfID->materialSortID].material;
    v6 = (const char *)material->GetName(this: material);
    ConMsg(a1: "Bad lightmap extents on material \"%s\"\n", v6);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C58C0
// Name: AccumulateLightstyles
// Source: json
//------------------------------------------------------------------------------
void __usercall AccumulateLightstyles(float a1@<xmm0>, ColorRGBExp32 *pLightmap, int lightmapSize)
{
  int v3; // edx
  int v4; // esi
  char *p_exponent; // ecx
  unsigned int v6; // edx
  float *v7; // eax
  float *v8; // eax
  char *v9; // ecx
  int v10; // edx

  v3 = lightmapSize;
  v4 = 0;
  if ( lightmapSize >= 4 )
  {
    p_exponent = &pLightmap->exponent;
    v6 = ((unsigned int)(lightmapSize - 4) >> 2) + 1;
    v7 = (float *)dword_104F1D84;
    v4 = 4 * v6;
    do
    {
      *(v7 - 1) = (float)((float)((float)(unsigned __int8)*(p_exponent - 3) * dword_10425B80[*p_exponent]) * a1)
                + *(v7 - 1);
      *v7 = (float)((float)((float)(unsigned __int8)*(p_exponent - 2) * dword_10425B80[*p_exponent]) * a1) + *v7;
      v7[1] = (float)((float)((float)(unsigned __int8)*(p_exponent - 1) * dword_10425B80[*p_exponent]) * a1) + v7[1];
      v7[3] = (float)((float)((float)(unsigned __int8)p_exponent[1] * dword_10425B80[p_exponent[4]]) * a1) + v7[3];
      v7[4] = (float)((float)((float)(unsigned __int8)p_exponent[2] * dword_10425B80[p_exponent[4]]) * a1) + v7[4];
      v7[5] = (float)((float)((float)(unsigned __int8)p_exponent[3] * dword_10425B80[p_exponent[4]]) * a1) + v7[5];
      v7[7] = (float)((float)((float)(unsigned __int8)p_exponent[5] * dword_10425B80[p_exponent[8]]) * a1) + v7[7];
      v7[8] = (float)((float)((float)(unsigned __int8)p_exponent[6] * dword_10425B80[p_exponent[8]]) * a1) + v7[8];
      v7[9] = (float)((float)((float)(unsigned __int8)p_exponent[7] * dword_10425B80[p_exponent[8]]) * a1) + v7[9];
      v7[11] = (float)((float)((float)(unsigned __int8)p_exponent[9] * dword_10425B80[p_exponent[12]]) * a1) + v7[11];
      v7[12] = (float)((float)((float)(unsigned __int8)p_exponent[10] * dword_10425B80[p_exponent[12]]) * a1) + v7[12];
      v7[13] = (float)((float)((float)(unsigned __int8)p_exponent[11] * dword_10425B80[p_exponent[12]]) * a1) + v7[13];
      v7 += 16;
      p_exponent += 16;
      --v6;
    }
    while ( v6 != 0 );
    v3 = lightmapSize;
  }
  if ( v4 < v3 )
  {
    v8 = (float *)&dword_104F1D84[4 * v4];
    v9 = &pLightmap[v4].exponent;
    v10 = v3 - v4;
    do
    {
      *(v8 - 1) = (float)((float)((float)(unsigned __int8)*(v9 - 3) * dword_10425B80[*v9]) * a1) + *(v8 - 1);
      *v8 = (float)((float)((float)(unsigned __int8)*(v9 - 2) * dword_10425B80[*v9]) * a1) + *v8;
      v8[1] = (float)((float)((float)(unsigned __int8)*(v9 - 1) * dword_10425B80[*v9]) * a1) + v8[1];
      v8 += 4;
      v9 += 4;
      --v10;
    }
    while ( v10 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C5B60
// Name: AccumulateLightstylesFlat
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__usercall AccumulateLightstylesFlat@<eax>(
        unsigned __int8 *result@<eax>,
        int a2@<ecx>,
        float a3@<xmm0>)
{
  int v4; // edx
  unsigned int v5; // edx
  float *v6; // ecx
  float *v7; // ecx
  int v8; // esi
  int i; // [esp+8h] [ebp-4h]

  v4 = 0;
  if ( a2 >= 4 )
  {
    v5 = ((unsigned int)(a2 - 4) >> 2) + 1;
    v6 = (float *)dword_104F1D84;
    i = 4 * v5;
    do
    {
      *(v6 - 1) = (float)((float)((float)*result * dword_10425B80[(char)result[3]]) * a3) + *(v6 - 1);
      *v6 = (float)((float)((float)result[1] * dword_10425B80[(char)result[3]]) * a3) + *v6;
      v6[1] = (float)((float)((float)result[2] * dword_10425B80[(char)result[3]]) * a3) + v6[1];
      v6[3] = (float)((float)((float)*result * dword_10425B80[(char)result[3]]) * a3) + v6[3];
      v6[4] = (float)((float)((float)result[1] * dword_10425B80[(char)result[3]]) * a3) + v6[4];
      v6[5] = (float)((float)((float)result[2] * dword_10425B80[(char)result[3]]) * a3) + v6[5];
      v6[7] = (float)((float)((float)*result * dword_10425B80[(char)result[3]]) * a3) + v6[7];
      v6[8] = (float)((float)((float)result[1] * dword_10425B80[(char)result[3]]) * a3) + v6[8];
      v6[9] = (float)((float)((float)result[2] * dword_10425B80[(char)result[3]]) * a3) + v6[9];
      v6[11] = (float)((float)((float)*result * dword_10425B80[(char)result[3]]) * a3) + v6[11];
      v6[12] = (float)((float)((float)result[1] * dword_10425B80[(char)result[3]]) * a3) + v6[12];
      v6[13] = (float)((float)((float)result[2] * dword_10425B80[(char)result[3]]) * a3) + v6[13];
      v6 += 16;
      --v5;
    }
    while ( v5 != 0 );
    v4 = i;
  }
  if ( v4 < a2 )
  {
    v7 = (float *)&dword_104F1D84[4 * v4];
    v8 = a2 - v4;
    do
    {
      *(v7 - 1) = (float)((float)((float)*result * dword_10425B80[(char)result[3]]) * a3) + *(v7 - 1);
      *v7 = (float)((float)((float)result[1] * dword_10425B80[(char)result[3]]) * a3) + *v7;
      v7[1] = (float)((float)((float)result[2] * dword_10425B80[(char)result[3]]) * a3) + v7[1];
      v7 += 4;
      --v8;
    }
    while ( v8 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C5DF0
// Name: AccumulateBumpedLightstyles
// Source: json
//------------------------------------------------------------------------------
float *__usercall AccumulateBumpedLightstyles@<eax>(int a1@<eax>, float a2@<xmm0>, int lightmapSize)
{
  float *result; // eax
  unsigned __int8 *v5; // edx
  float *v6; // eax
  char *v7; // ecx
  int v8; // edi
  unsigned __int8 *v9; // edx
  char *v10; // ecx
  int v11; // esi
  float *pBumpedLightmaps_4; // [esp+10h] [ebp-Ch]
  int pBumpedLightmaps_8; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  result = (float *)(a1 + 8 * lightmapSize);
  pBumpedLightmaps_4 = result;
  pBumpedLightmaps_8 = a1 + 12 * lightmapSize;
  if ( lightmapSize > 0 )
  {
    v5 = (unsigned __int8 *)(a1 + 4 * lightmapSize + 2);
    v6 = (float *)dword_104F1D84;
    v7 = (char *)(a1 + 3);
    v8 = 4 * lightmapSize;
    for ( i = lightmapSize; i != 0; --i )
    {
      *(v6 - 1) = (float)((float)((float)(unsigned __int8)*(v7 - 3) * dword_10425B80[*v7]) * a2) + *(v6 - 1);
      *v6 = (float)((float)((float)(unsigned __int8)*(v7 - 2) * dword_10425B80[*v7]) * a2) + *v6;
      v6[1] = (float)((float)((float)(unsigned __int8)*(v7 - 1) * dword_10425B80[*v7]) * a2) + v6[1];
      v6[0xFFFF] = (float)((float)((float)*(v5 - 2) * dword_10425B80[v7[v8]]) * a2) + v6[0xFFFF];
      v6[0x10000] = (float)((float)((float)*(v5 - 1) * dword_10425B80[v7[v8]]) * a2) + v6[0x10000];
      v6[65537] = (float)((float)((float)*v5 * dword_10425B80[v7[v8]]) * a2) + v6[65537];
      v6 += 4;
      v7 += 4;
      v5 += 4;
    }
    v9 = (unsigned __int8 *)(pBumpedLightmaps_8 + 2);
    v10 = (char *)pBumpedLightmaps_4 + 3;
    v11 = pBumpedLightmaps_8 - (_DWORD)pBumpedLightmaps_4;
    result = flt_10571D84;
    do
    {
      *(result - 1) = (float)((float)((float)(unsigned __int8)*(v10 - 3) * dword_10425B80[*v10]) * a2) + *(result - 1);
      *result = (float)((float)((float)(unsigned __int8)*(v10 - 2) * dword_10425B80[*v10]) * a2) + *result;
      result[1] = (float)((float)((float)(unsigned __int8)*(v10 - 1) * dword_10425B80[*v10]) * a2) + result[1];
      result[0xFFFF] = (float)((float)((float)*(v9 - 2) * dword_10425B80[v10[v11]]) * a2) + result[0xFFFF];
      result[0x10000] = (float)((float)((float)*(v9 - 1) * dword_10425B80[v10[v11]]) * a2) + result[0x10000];
      result[65537] = (float)((float)((float)*v9 * dword_10425B80[v10[v11]]) * a2) + result[65537];
      result += 4;
      v10 += 4;
      v9 += 4;
      --lightmapSize;
    }
    while ( lightmapSize != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C6070
// Name: ComputeLightmapFromLightstyle
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeLightmapFromLightstyle(
        msurfacelighting_t *pLighting,
        bool computeLightmap,
        bool computeBumpmap,
        int lightmapSize,
        bool hasBumpmapLightmapData)
{
  ColorRGBExp32 *m_pSamples; // esi
  int m_nValue; // eax
  unsigned int v7; // ebx
  unsigned __int8 *i; // edi
  unsigned __int8 v9; // cl
  int v10; // eax
  float v11; // xmm0_4
  int v12; // eax
  int maxmap; // [esp+8h] [ebp-4h]

  m_pSamples = pLighting->m_pSamples;
  if ( r_lightmap.m_pParent != nullptr )
  {
    m_nValue = r_lightmap.m_pParent->m_Value.m_nValue;
    if ( m_nValue == -1 )
    {
      m_nValue = 0;
      maxmap = 4;
      goto LABEL_4;
    }
  }
  else
  {
    m_nValue = 0;
  }
  maxmap = m_nValue + 1;
LABEL_4:
  if ( m_nValue < maxmap )
  {
    v7 = 4 * m_nValue;
    for ( i = &pLighting->m_nStyles[m_nValue]; (int)&i[-24 - (_DWORD)pLighting] < maxmap; ++i )
    {
      v9 = *i;
      if ( *i == 0xFF )
        return;
      if ( r_lightstyle.m_pParent != nullptr )
      {
        v10 = r_lightstyle.m_pParent->m_Value.m_nValue;
        if ( v10 == -1 )
          goto LABEL_14;
      }
      else
      {
        v10 = 0;
      }
      if ( v9 == v10 )
      {
LABEL_14:
        v11 = (float)d_lightstylevalue[v9] * 0.0037878789;
        if ( v11 > 0.0 )
        {
          if ( computeBumpmap )
          {
            AccumulateBumpedLightstyles(a1: (int)m_pSamples, a2: v11, lightmapSize);
          }
          else if ( computeLightmap )
          {
            if ( r_avglightmap.m_pParent != nullptr && r_avglightmap.m_pParent->m_Value.m_nValue != 0 )
            {
              m_pSamples = &pLighting->m_pSamples[v7 / 0xFFFFFFFC - 1];
              AccumulateLightstylesFlat(result: (unsigned __int8 *)m_pSamples, a2: lightmapSize, a3: v11);
            }
            else
            {
              AccumulateLightstyles(a1: v11, pLightmap: m_pSamples, lightmapSize);
            }
          }
        }
        v12 = lightmapSize;
        if ( hasBumpmapLightmapData )
          v12 = 4 * lightmapSize;
        m_pSamples += v12;
      }
      v7 += 4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C6190
// Name: UpdateLightmapTextures
// Source: json
//------------------------------------------------------------------------------
void __usercall UpdateLightmapTextures(msurface2_t *surfID@<edx>, bool needsBumpmap)
{
  int v2; // ecx
  int materialSortID; // edx
  int lightmapPageID; // edx
  void (__thiscall *UpdateLightmap)(IMaterialSystem *, int, int *, int *, float *, float *, float *, float *); // eax
  int lightmapSize[2]; // [esp+4h] [ebp-10h] BYREF
  int offsetIntoLightmapPage[2]; // [esp+Ch] [ebp-8h] BYREF

  if ( materialSortInfoArray != nullptr )
  {
    lightmapSize[0] = *(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapExtents
                                 + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0))
                    + 1;
    lightmapSize[1] = *(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_LightmapExtents[1]
                                 + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0))
                    + 1;
    offsetIntoLightmapPage[0] = *(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_OffsetIntoLightmapPage
                                           + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
    v2 = (char *)surfID - (char *)host_state.worldbrush->surfaces2;
    materialSortID = surfID->materialSortID;
    offsetIntoLightmapPage[1] = *(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_OffsetIntoLightmapPage[1]
                                           + (v2 & 0xFFFFFFE0));
    lightmapPageID = materialSortInfoArray[materialSortID].lightmapPageID;
    UpdateLightmap = materials->UpdateLightmap;
    if ( needsBumpmap )
      ((void (__stdcall *)(int, int *, int *, Vector4D *, float *, float *, int *))UpdateLightmap)(
        a1: lightmapPageID,
        a2: lightmapSize,
        a3: offsetIntoLightmapPage,
        a4: (Vector4D *)blocklights,
        a5: flt_10531D80,
        a6: flt_10571D80,
        a7: dword_105B1D80);
    else
      ((void (__stdcall *)(int, int *, int *, Vector4D *, _DWORD, _DWORD, _DWORD))UpdateLightmap)(
        a1: lightmapPageID,
        a2: lightmapSize,
        a3: offsetIntoLightmapPage,
        a4: (Vector4D *)blocklights,
        a5: 0,
        a6: 0,
        a7: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C6260
// Name: unsigned int R_UpdateDlightState(struct dlight_t __near *,struct msurface2_t __near *,struct matrix3x4_t const __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl R_UpdateDlightState(
        dlight_t *pLights,
        msurface2_t *surfID,
        const matrix3x4_t *entityToWorld,
        bool bOnlyUseLightStyles,
        bool bLightmap)
{
  int result; // eax
  msurfacelighting_t *v6; // esi

  result = 0;
  v6 = (msurfacelighting_t *)((char *)host_state.worldbrush->surfacelighting
                            + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  v6->m_fDLightBits &= r_dlightactive;
  v6->m_nLastComputedFrame = r_framecount;
  if ( !bOnlyUseLightStyles
    && (!bLightmap
     || v6->m_nDLightFrame != r_framecount
     || (result = R_ComputeDynamicLightMask(pLights, surfID, pLighting: v6, entityToWorld)) == 0
     || v6->m_fDLightBits == 0) )
  {
    v6->m_fDLightBits = 0;
    surfID->flags &= ~0x80000u;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C62E0
// Name: SortSurfacesByLightmapID
// Source: json
//------------------------------------------------------------------------------
void __cdecl SortSurfacesByLightmapID(msurface2_t **pToSort, int iSurfaceCount)
{
  int v2; // esi
  void *v3; // esp
  int v4; // ebx
  msurface2_t **v5; // eax
  msurface2_t **v6; // edi
  int i; // eax
  int v8; // edx
  int j; // eax
  int v10; // ecx
  int v11; // eax
  msurface2_t *v12; // esi
  int v13; // ecx
  int v14; // edx
  int v15; // [esp+0h] [ebp-814h] BYREF
  _DWORD v16[256]; // [esp+Ch] [ebp-808h]
  _DWORD v17[256]; // [esp+40Ch] [ebp-408h] BYREF
  msurface2_t **v18; // [esp+80Ch] [ebp-8h]
  int v19; // [esp+810h] [ebp-4h]

  v2 = iSurfaceCount;
  v3 = alloca(4 * iSurfaceCount);
  v4 = 0;
  v5 = (msurface2_t **)&v15;
  v19 = 0;
  while ( 1 )
  {
    v6 = pToSort;
    pToSort = v5;
    v18 = v6;
    memset(v17, 0, sizeof(v17));
    for ( i = 0; i != v2; ++v17[(unsigned __int8)v8] )
      v8 = materialSortInfoArray[v6[i++]->materialSortID].lightmapPageID >> v4;
    v16[0] = 0;
    for ( j = 0; j != 255; v16[j] = v10 )
    {
      v10 = v17[j] + v16[j];
      ++j;
    }
    v11 = 0;
    if ( v2 != 0 )
    {
      do
      {
        v12 = v6[v11++];
        v13 = (unsigned __int8)(materialSortInfoArray[v12->materialSortID].lightmapPageID >> v4);
        v14 = v16[v13];
        pToSort[v14] = v12;
        v2 = iSurfaceCount;
        v4 = v19;
        v16[v13] = v14 + 1;
      }
      while ( v11 != iSurfaceCount );
    }
    v4 += 8;
    v19 = v4;
    if ( v4 == 32 )
      break;
    v5 = v18;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C6410
// Name: int LightmapPageCompareFunc(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LightmapPageCompareFunc(const void *pElem0, const void *pElem1)
{
  return materialSortInfoArray[*(__int16 *)(*(_DWORD *)pElem0 + 18)].lightmapPageID
       - materialSortInfoArray[*(__int16 *)(*(_DWORD *)pElem1 + 18)].lightmapPageID;
}

//------------------------------------------------------------------------------
// Address: 0x100C6440
// Name: void R_AddDynamicLights(struct dlight_t __near *,struct msurface2_t __near *,struct matrix3x4_t const __near &,bool,unsigned int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl R_AddDynamicLights(
        dlight_t *pLights,
        msurface2_t *surfID,
        const matrix3x4_t *entityToWorld,
        bool needsBumpmap,
        float lightMask)
{
  bool v5; // zf
  int v6; // eax
  dlight_t *v7; // edi
  float v8; // xmm0_4
  float v9; // xmm1_4
  Vector pBumpNormals; // [esp+1Ch] [ebp-50h] BYREF
  Vector bumpNormals[3]; // [esp+38h] [ebp-34h] BYREF
  Vector luxelBasePosition; // [esp+5Ch] [ebp-10h]
  char lightOrigin_3; // [esp+6Bh] [ebp-1h] OVERLAPPED

  if ( r_dlightsenable.m_pParent != nullptr && r_dlightsenable.m_pParent->m_Value.m_nValue != 0 )
  {
    v5 = (surfID->flags & 0x800) == 0;
    v6 = LODWORD(lightMask);
    lightOrigin_3 = 0;
    if ( v5 )
    {
      v7 = pLights;
      luxelBasePosition.x = 0.0;
      bumpNormals[2].z = lightMask;
      do
      {
        if ( v6 == 0 )
          break;
        if ( (v6 & 1) != 0 )
        {
          VectorITransform(in1: &v7->origin.x, in2: entityToWorld, out: &bumpNormals[1].z);
          v8 = (float)((float)((float)(surfID->plane->normal.y * bumpNormals[2].x)
                             + (float)(surfID->plane->normal.x * bumpNormals[1].z))
                     + (float)(surfID->plane->normal.z * bumpNormals[2].y))
             - surfID->plane->dist;
          if ( v8 >= -15.0 )
          {
            v9 = v7->radius * v7->radius;
            luxelBasePosition.y = v8 * v8;
            luxelBasePosition.z = v9;
            if ( (float)(v8 * v8) < v9 )
            {
              if ( needsBumpmap )
              {
                if ( lightOrigin_3 == 0 )
                {
                  R_ComputeSurfaceBasis_0(surfID, luxelBasePosition: (Vector *)&bumpNormals[0].z, &pBumpNormals);
                  lightOrigin_3 = 1;
                }
                AddSingleDynamicLightToBumpLighting(
                  surfID,
                  lightOrigin: (Vector *)&bumpNormals[1].z,
                  perpDistSq: luxelBasePosition.y,
                  lightRadiusSq: luxelBasePosition.z,
                  pBumpBasis: &pBumpNormals,
                  luxelBasePosition: (Vector *)&bumpNormals[0].z);
              }
              else
              {
                AddSingleDynamicLight(
                  dl: v7,
                  surfID,
                  lightOrigin: (Vector *)&bumpNormals[1].z,
                  perpDistSq: luxelBasePosition.y,
                  lightRadiusSq: luxelBasePosition.z);
              }
            }
          }
        }
        v6 = SLODWORD(bumpNormals[2].z) >> 1;
        ++v7;
        ++LODWORD(luxelBasePosition.x);
        SLODWORD(bumpNormals[2].z) >>= 1;
      }
      while ( SLODWORD(luxelBasePosition.x) < 32 );
    }
    else
    {
      surfID->pDispInfo->AddDynamicLights(this: surfID->pDispInfo, a2: pLights, a3: LODWORD(lightMask));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C65A0
// Name: void R_BuildLightMapGuts(struct dlight_t __near *,struct msurface2_t __near *,struct matrix3x4_t const __near &,unsigned int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_BuildLightMapGuts(
        dlight_t *pLights,
        msurface2_t *surfID,
        const matrix3x4_t *entityToWorld,
        float dlightMask,
        bool needsBumpmap,
        bool needsLightmap)
{
  int v6; // ecx
  msurface2_t *v7; // esi
  msurfacelighting_t *v8; // ebx
  int v9; // edi
  bool v10; // al
  bool v11; // dl
  int v12; // xmm1_4
  int *v13; // ecx
  int i; // edx
  float *v15; // esi
  bool v16; // al
  float m_fValue; // xmm1_4
  float *v18; // ecx
  int j; // edx
  bool v20; // cl
  bool v21; // al
  int *v22; // ebx
  int v23; // esi
  unsigned int v24; // edx
  int *v25; // eax
  int *v26; // ecx
  double v27; // st7
  int *v28; // eax
  int *v29; // ecx
  int v30; // edx
  double v31; // st7
  float *v32; // eax
  int m; // ecx
  float *v34; // eax
  int n; // ecx
  int *v36; // eax
  int k; // [esp+Ch] [ebp-Ch]
  bool hasBumpmap; // [esp+10h] [ebp-8h]
  int hasBumpmapa; // [esp+10h] [ebp-8h]
  bool hasLightmap; // [esp+17h] [ebp-1h]

  v7 = surfID;
  v8 = (msurfacelighting_t *)((char *)host_state.worldbrush->surfacelighting
                            + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  v9 = ComputeLightmapSize(a1: v6, surfID);
  if ( v9 == 0 )
    return;
  hasBumpmap = SurfHasBumpedLightmaps(surfID);
  v10 = SurfHasLightmap(surfID);
  v11 = v10;
  hasLightmap = v10;
  if ( needsLightmap )
  {
    v12 = v10 ? 0 : LODWORD(mat_defaultlightmap.m_pParent->m_Value.m_fValue);
    if ( v9 > 0 )
    {
      v13 = dword_104F1D84;
      for ( i = v9; i != 0; --i )
      {
        v13[1] = v12;
        *v13 = v12;
        *(v13 - 1) = v12;
        v13[2] = 1065353216;
        v13 += 4;
      }
      v11 = v10;
    }
  }
  if ( needsBumpmap )
  {
    v15 = flt_10531D84;
    do
    {
      v16 = hasBumpmap;
      if ( hasBumpmap )
        m_fValue = 0.0;
      else
        m_fValue = mat_defaultlightmap.m_pParent->m_Value.m_fValue;
      if ( v9 > 0 )
      {
        v18 = v15;
        for ( j = v9; j != 0; --j )
        {
          v18[1] = m_fValue;
          *v18 = m_fValue;
          *(v18 - 1) = m_fValue;
          v18[2] = 1.0;
          v18 += 4;
        }
        v11 = hasLightmap;
      }
      v15 += 0x10000;
    }
    while ( (int)v15 < (int)&r_avglightmap.m_pNext );
    v7 = surfID;
  }
  else
  {
    v16 = hasBumpmap;
  }
  if ( v11 && needsLightmap )
    goto LABEL_27;
  if ( !v16 )
  {
    if ( needsBumpmap )
    {
      if ( v11 )
      {
        ComputeLightmapFromLightstyle(
          pLighting: v8,
          computeLightmap: true,
          computeBumpmap: false,
          lightmapSize: v9,
          hasBumpmapLightmapData: false);
        hasBumpmapa = 0;
        v22 = dword_104F1D88;
        for ( k = 1; k != 0; --k )
        {
          v23 = 0;
          if ( v9 >= 4 )
          {
            v24 = ((unsigned int)(v9 - 4) >> 2) + 1;
            v25 = dword_104F1D88;
            v26 = v22;
            v23 = 4 * v24;
            do
            {
              v27 = *((float *)v25 - 2);
              v25 += 16;
              *((float *)v26 - 2) = v27;
              v26 += 16;
              --v24;
              *(v26 - 17) = *(v25 - 17);
              *(v26 - 16) = *(v25 - 16);
              *(v26 - 14) = *(v25 - 14);
              *(v26 - 13) = *(v25 - 13);
              *(v26 - 12) = *(v25 - 12);
              *(v26 - 10) = *(v25 - 10);
              *(v26 - 9) = *(v25 - 9);
              *(v26 - 8) = *(v25 - 8);
              *(v26 - 6) = *(v25 - 6);
              *(v26 - 5) = *(v25 - 5);
              *(v26 - 4) = *(v25 - 4);
            }
            while ( v24 != 0 );
          }
          if ( v23 < v9 )
          {
            v28 = &dword_104F1D88[4 * v23];
            v29 = &dword_104F1D88[4 * v23 + 4 * hasBumpmapa];
            v30 = v9 - v23;
            do
            {
              v31 = *((float *)v28 - 2);
              v28 += 4;
              *((float *)v29 - 2) = v31;
              v29 += 4;
              --v30;
              *(v29 - 5) = *(v28 - 5);
              *(v29 - 4) = *(v28 - 4);
            }
            while ( v30 != 0 );
          }
          hasBumpmapa += 0x4000;
          v22 += 0x10000;
        }
        v7 = surfID;
      }
      else if ( v9 > 0 )
      {
        v32 = flt_10531D84;
        for ( m = v9; m != 0; --m )
        {
          v32[1] = 0.0;
          *v32 = 0.0;
          *(v32 - 1) = 0.0;
          v32[2] = 1.0;
          v32 += 4;
        }
        v34 = flt_10571D84;
        for ( n = v9; n != 0; --n )
        {
          v34[1] = 0.0;
          *v34 = 0.0;
          *(v34 - 1) = 0.0;
          v34[2] = 1.0;
          v34 += 4;
        }
        v36 = dword_105B1D84;
        do
        {
          v36[1] = 0;
          *v36 = 0;
          *(v36 - 1) = 0;
          v36[2] = 1065353216;
          v36 += 4;
          --v9;
        }
        while ( v9 != 0 );
      }
    }
    goto LABEL_53;
  }
  if ( needsBumpmap )
  {
LABEL_27:
    v20 = v16 && needsBumpmap;
    v21 = v11 && needsLightmap;
    ComputeLightmapFromLightstyle(
      pLighting: v8,
      computeLightmap: v21,
      computeBumpmap: v20,
      lightmapSize: v9,
      hasBumpmapLightmapData: hasBumpmap);
  }
LABEL_53:
  if ( dlightMask != 0.0 && (needsLightmap || needsBumpmap) )
    R_AddDynamicLights(pLights, surfID: v7, entityToWorld, needsBumpmap, lightMask: dlightMask);
  UpdateLightmapTextures(surfID: v7, needsBumpmap);
}

//------------------------------------------------------------------------------
// Address: 0x100C68A0
// Name: public: virtual void CFunctor6<void (*)(struct dlight_t __near *,struct msurface2_t __near *,struct matrix3x4_t const __near &,unsigned int,bool,bool),struct dlight_t __near *,struct msurface2_t __near *,struct matrix3x4_t,unsigned int,bool,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor6<void (__cdecl *)(dlight_t *,msurface2_t *,matrix3x4_t const &,unsigned int,bool,bool),dlight_t *,msurface2_t *,matrix3x4_t,unsigned int,bool,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor6<void (__cdecl*)(dlight_t *,msurface2_t *,matrix3x4_t const &,unsigned int,bool,bool),dlight_t *,msurface2_t *,matrix3x4_t,int,bool,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  this->m_pfnProxied(
    a1: this->m_arg1,
    a2: this->m_arg2,
    a3: &this->m_arg3,
    a4: this->m_arg4,
    a5: this->m_arg5,
    a6: this->m_arg6);
}

//------------------------------------------------------------------------------
// Address: 0x100C68D0
// Name: void R_BuildLightMap(struct dlight_t __near *,class ICallQueue __near *,struct msurface2_t __near *,struct matrix3x4_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_BuildLightMap(
        dlight_t *pLights,
        ICallQueue *pCallQueue,
        msurface2_t *surfID,
        const matrix3x4_t *entityToWorld,
        bool bOnlyUseLightStyles)
{
  bool v5; // al
  int lightmapPageID; // ecx
  CFunctor *v7; // eax
  const matrix3x4_t v8; // [esp+4h] [ebp-3Ch]
  bool needsLightmap; // [esp+34h] [ebp-Ch]
  bool needsBumpmap; // [esp+38h] [ebp-8h]
  bool bDlightsInLightmap; // [esp+3Ch] [ebp-4h]
  int bDlightsInLightmapa; // [esp+3Ch] [ebp-4h]

  needsBumpmap = SurfNeedsBumpedLightmaps(surfID);
  v5 = SurfNeedsLightmap(surfID);
  needsLightmap = v5;
  if ( (needsBumpmap || v5)
    && (materialSortInfoArray == nullptr
     || (lightmapPageID = materialSortInfoArray[surfID->materialSortID].lightmapPageID) != -1 && lightmapPageID != -2) )
  {
    if ( v5 || (bDlightsInLightmap = false, needsBumpmap) )
      bDlightsInLightmap = true;
    bDlightsInLightmapa = R_UpdateDlightState(
                            pLights,
                            surfID,
                            entityToWorld,
                            bOnlyUseLightStyles,
                            bLightmap: bDlightsInLightmap);
    if ( bOnlyUseLightStyles )
      bDlightsInLightmapa = 0;
    if ( pCallQueue != nullptr )
    {
      v8 = *entityToWorld;
      v7 = (CFunctor *)MemAlloc_Alloc(nSize: 0x54u);
      if ( v7 != nullptr )
      {
        v7[1].m_nUserID = 1;
        qmemcpy(&v7[3].m_nUserID, &v8, 48);
        v7[9].m_nUserID = bDlightsInLightmapa;
        v7[2].m_nUserID = (unsigned int)pLights;
        BYTE1(v7[10].__vftable) = needsLightmap;
        v7->__vftable = (CFunctor_vtbl *)&CFunctor6<void (__cdecl *)(dlight_t *,msurface2_t *,matrix3x4_t const &,unsigned int,bool,bool),dlight_t *,msurface2_t *,matrix3x4_t,unsigned int,bool,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
        v7[1].__vftable = (CFunctor_vtbl *)&CFunctor6<void (__cdecl *)(dlight_t *,msurface2_t *,matrix3x4_t const &,unsigned int,bool,bool),dlight_t *,msurface2_t *,matrix3x4_t,unsigned int,bool,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
        v7[2].__vftable = (CFunctor_vtbl *)R_BuildLightMapGuts;
        v7[3].__vftable = (CFunctor_vtbl *)surfID;
        LOBYTE(v7[10].__vftable) = needsBumpmap;
        pCallQueue->QueueFunctorInternal(this: pCallQueue, a2: v7);
      }
      else
      {
        pCallQueue->QueueFunctorInternal(this: pCallQueue, a2: nullptr);
      }
    }
    else
    {
      R_BuildLightMapGuts(
        pLights,
        surfID,
        entityToWorld,
        dlightMask: *(float *)&bDlightsInLightmapa,
        needsBumpmap,
        needsLightmap);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C6A00
// Name: void DiscardStaticLightmapData(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DiscardStaticLightmapData()
{
  int v0; // ebx
  msurfacelighting_t *surfacelighting; // esi
  void *v2; // esp
  int v3; // esi
  CDmxAttribute **m_pMemory; // edi
  ColorRGBExp32 *m_pSamples; // edx
  int v6; // ecx
  ColorRGBExp32 *v7; // eax
  worldbrushdata_t *v8; // eax
  msurfacelighting_t *lightdata; // esi
  unsigned int v10; // edi
  msurface2_t *v11; // esi
  char *v12; // eax
  int v13; // ecx
  int v14; // eax
  IMaterial *material; // ecx
  const char *v16; // eax
  int j; // eax
  int v18; // ebx
  msurfacelighting_t *v19; // ecx
  ColorRGBExp32 **p_m_pSamples; // esi
  int v21; // edi
  unsigned __int8 *v22; // eax
  msurfacelighting_t *v23; // ecx
  unsigned int v24; // esi
  const char *v25; // edi
  _BYTE v26[12]; // [esp+8h] [ebp-48h] BYREF
  CUtlSortVector<CDmxAttribute *,CDmxAttributeLess> v27; // [esp+14h] [ebp-3Ch] BYREF
  int v28; // [esp+30h] [ebp-20h]
  worldbrushdata_t *worldbrush; // [esp+34h] [ebp-1Ch]
  int numSurfaces; // [esp+38h] [ebp-18h] BYREF
  worldbrushdata_t *pBrushData; // [esp+3Ch] [ebp-14h] BYREF
  msurfacelighting_t *context; // [esp+40h] [ebp-10h]
  int i; // [esp+44h] [ebp-Ch]
  msurfacelighting_t *pLighting; // [esp+48h] [ebp-8h]
  int offset; // [esp+4Ch] [ebp-4h] BYREF

  if ( !g_bHunkAllocLightmaps )
  {
    v0 = host_state.worldbrush->numsurfaces;
    surfacelighting = host_state.worldbrush->surfacelighting;
    worldbrush = host_state.worldbrush;
    context = surfacelighting;
    v28 = v0;
    if ( v0 != 0 && host_state.worldbrush->m_pLightingDataStack != nullptr )
    {
      v2 = alloca(4 * v0);
      v27.m_pLessContext = surfacelighting;
      v3 = 0;
      m_pMemory = (CDmxAttribute **)v26;
      v27.m_Memory.m_pMemory = (CDmxAttribute **)v26;
      v27.m_Memory.m_nAllocationCount = v0;
      v27.m_Memory.m_nGrowSize = -1;
      v27.m_Size = 0;
      v27.m_pElements = (CDmxAttribute **)v26;
      v27.m_bNeedsSort = false;
      pBrushData = nullptr;
      if ( v0 > 0 )
      {
        do
        {
          CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::InsertNoSort(
            this: &v27,
            src: (CDmxAttribute *const *)&pBrushData);
          pBrushData = (worldbrushdata_t *)++v3;
        }
        while ( v3 < v0 );
        if ( v27.m_bNeedsSort )
        {
          v27.m_bNeedsSort = false;
          if ( v27.m_Size > 1 )
          {
            numSurfaces = (int)v27.m_pLessContext;
            pBrushData = (worldbrushdata_t *)((char *)&offset + 3);
            qsort_s(
              base: v27.m_Memory.m_pMemory,
              num: v27.m_Size,
              width: 4u,
              comp: (int (__cdecl *)(void *, const void *, const void *))CUtlSortVector<int,SurfaceLessFunc>::CompareHelper,
              context: &numSurfaces);
          }
        }
        m_pMemory = v27.m_Memory.m_pMemory;
      }
      m_pSamples = context[(_DWORD)*m_pMemory].m_pSamples;
      v6 = 1;
      if ( v0 <= 1 )
      {
LABEL_16:
        v8 = worldbrush;
        lightdata = (msurfacelighting_t *)worldbrush->lightdata;
        pLighting = lightdata;
        pBrushData = nullptr;
        if ( v0 > 0 )
        {
          while ( 1 )
          {
            v10 = (unsigned int)m_pMemory[(_DWORD)pBrushData];
            v11 = &host_state.worldbrush->surfaces2[v10];
            if ( SurfHasLightmap(surfID: v11) )
            {
              v12 = (char *)host_state.worldbrush->surfacelighting
                  + (((char *)v11 - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0);
              v13 = (*((__int16 *)v12 + 2) + 1) * (*((__int16 *)v12 + 3) + 1);
              v14 = (v11->flags & 0x800) != 0 ? 128 : 35;
              if ( v13 <= v14 * v14 )
              {
                i = v13;
              }
              else
              {
                material = materialSortInfoArray[v11->materialSortID].material;
                v16 = (const char *)material->GetName(this: material);
                ConMsg(a1: "Bad lightmap extents on material \"%s\"\n", v16);
                i = 0;
              }
              if ( SurfHasBumpedLightmaps(surfID: v11) )
                i *= 4;
              for ( j = 0; j < 4; ++j )
              {
                if ( context[v10].m_nStyles[j] == 0xFF )
                  break;
              }
              if ( j != 0 )
              {
                v18 = j;
                if ( j > 1 && (v11->flags & 0x400) != 0 )
                  v18 = j * (i + 1);
                v19 = pLighting;
                p_m_pSamples = &context[v10].m_pSamples;
                v21 = 4 * j;
                v22 = (unsigned __int8 *)&(*p_m_pSamples)[-j];
                if ( v22 != (unsigned __int8 *)pLighting )
                {
                  memmove(dst: (unsigned __int8 *)pLighting, src: v22, count: 4 * v18);
                  v19 = pLighting;
                  *p_m_pSamples = (ColorRGBExp32 *)((char *)pLighting + v21);
                }
                v23 = (msurfacelighting_t *)((char *)v19 + 4 * v18);
                v0 = v28;
                pLighting = v23;
              }
            }
            pBrushData = (worldbrushdata_t *)((char *)pBrushData + 1);
            if ( (int)pBrushData >= v0 )
              break;
            m_pMemory = v27.m_Memory.m_pMemory;
          }
          lightdata = pLighting;
          v8 = worldbrush;
        }
        v24 = (char *)lightdata - (char *)v8->lightdata;
        CMemoryStack::FreeToAllocPoint(this: v8->m_pLightingDataStack, mark: v24, bDecommit: true);
        v25 = modelloader->GetName(this: modelloader, a2: host_state.worldmodel);
        _Msg(
          a1: "(%s) Original Full Lighting Data:           %.2f MB\n",
          v25,
          (double)worldbrush->m_nLightingDataSize * 0.00000095367432);
        v28 = v24;
        _Msg(a1: "(%s) Reduced To Only Dynamic Lighting Data: %.2f MB\n", v25, (double)v24 * 0.00000095367432);
        if ( v27.m_Memory.m_nGrowSize >= 0 )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v27.m_Memory.m_pMemory);
      }
      else
      {
        while ( 1 )
        {
          v7 = context[(_DWORD)m_pMemory[v6]].m_pSamples;
          if ( v7 != nullptr && m_pSamples != nullptr && v7 == m_pSamples )
          {
            DevMsg(a1: "DiscardStaticLightmapData: Surface Lighting data aliased.\n");
            CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v27);
            return;
          }
          if ( v7 < m_pSamples )
            break;
          ++v6;
          m_pSamples = v7;
          if ( v6 >= v0 )
            goto LABEL_16;
        }
        DevMsg(a1: "DiscardStaticLightmapData: Surface Lighting data out of order.\n");
        if ( v27.m_Memory.m_nGrowSize >= 0 )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C6D40
// Name: void R_BuildLightmapUpdateList(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_BuildLightmapUpdateList()
{
  IMatRenderContext *m_pObject; // esi
  ICallQueue *v1; // eax
  ICallQueue *v2; // edi
  int v3; // ecx
  const IClientRenderable **p_m_pExclusiveLightReceiver; // eax
  LightmapUpdateInfo_t *v5; // ebx
  CFunctor *v6; // eax
  dlight_t *v7; // ecx
  _BYTE v8[48]; // [esp+Ch] [ebp-44h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+3Ch] [ebp-14h]
  int i; // [esp+40h] [ebp-10h]
  ICallQueue *pCallQueue; // [esp+44h] [ebp-Ch]
  unsigned int v12; // [esp+48h] [ebp-8h]
  dlight_t *pLights; // [esp+4Ch] [ebp-4h]

  m_pObject = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  v1 = m_pObject->GetCallQueue(this: m_pObject);
  v2 = v1;
  pCallQueue = v1;
  pLights = cl_dlights;
  if ( g_bActiveDlights && v1 != nullptr )
  {
    if ( (_S1_6 & 1) == 0 )
    {
      _S1_6 |= 1u;
      v3 = 63;
      p_m_pExclusiveLightReceiver = &threadDlights[0].m_pExclusiveLightReceiver;
      do
      {
        *p_m_pExclusiveLightReceiver = nullptr;
        p_m_pExclusiveLightReceiver += 17;
        --v3;
      }
      while ( v3 >= 0 );
    }
    pLights = &threadDlights[32 * threadFrameCount];
    _V_memcpy(dest: pLights, src: cl_dlights, count: 2176);
    threadFrameCount = ((_BYTE)threadFrameCount - 1) & 1;
  }
  qsort(
    base: g_LightmapUpdateList.m_Memory.m_pMemory,
    num: g_LightmapUpdateList.m_Size,
    width: 0xCu,
    comp: LightmapPageCompareFunc);
  i = 0;
  if ( g_LightmapUpdateList.m_Size > 0 )
  {
    v12 = 0;
    do
    {
      v5 = &g_LightmapUpdateList.m_Memory.m_pMemory[v12 / 0xC];
      if ( v2 != nullptr )
      {
        qmemcpy(v8, &g_LightmapTransformList.m_Memory.m_pMemory[v5->m_nTransformIndex].xform, sizeof(v8));
        v6 = (CFunctor *)MemAlloc_Alloc(nSize: 0x54u);
        if ( v6 != nullptr )
        {
          v7 = pLights;
          v6[1].m_nUserID = 1;
          v6[2].m_nUserID = (unsigned int)v7;
          v6->__vftable = (CFunctor_vtbl *)&CFunctor6<void (__cdecl *)(dlight_t *,msurface2_t *,matrix3x4_t const &,unsigned int,bool,bool),dlight_t *,msurface2_t *,matrix3x4_t,int,bool,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
          v6[1].__vftable = (CFunctor_vtbl *)&CFunctor6<void (__cdecl *)(dlight_t *,msurface2_t *,matrix3x4_t const &,unsigned int,bool,bool),dlight_t *,msurface2_t *,matrix3x4_t,int,bool,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
          v6[2].__vftable = (CFunctor_vtbl *)R_BuildLightMapGuts;
          v6[3].__vftable = (CFunctor_vtbl *)v5->m_SurfHandle;
          qmemcpy(&v6[3].m_nUserID, v8, 48);
          v6[9].m_nUserID = v5->m_nDlightMask;
          LOBYTE(v6[10].__vftable) = v5->m_bNeedsBumpmap;
          BYTE1(v6[10].__vftable) = v5->m_bNeedsLightmap;
        }
        else
        {
          v6 = nullptr;
        }
        pCallQueue->QueueFunctorInternal(this: pCallQueue, a2: v6);
        v2 = pCallQueue;
        m_pObject = pRenderContext.m_pObject;
      }
      else
      {
        R_BuildLightMapGuts(
          pLights,
          surfID: v5->m_SurfHandle,
          entityToWorld: &g_LightmapTransformList.m_Memory.m_pMemory[v5->m_nTransformIndex].xform,
          dlightMask: *(float *)&v5->m_nDlightMask,
          needsBumpmap: v5->m_bNeedsBumpmap,
          needsLightmap: v5->m_bNeedsLightmap);
      }
      v12 += 12;
      ++i;
    }
    while ( i < g_LightmapUpdateList.m_Size );
  }
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x100C6F20
// Name: void R_CheckForLightmapUpdates(struct msurface2_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_CheckForLightmapUpdates(msurface2_t *surfID, int nTransformIndex)
{
  _DWORD *v2; // eax
  int v3; // ebx
  _BYTE *v4; // ecx
  bool v5; // cl
  bool v6; // bl
  bool v7; // al
  int lightmapPageID; // ecx
  int updated; // edi
  int v10; // eax
  bool bOnlyUseLightStyles; // [esp+Bh] [ebp-9h]
  bool bDlightsInLightmap; // [esp+Fh] [ebp-5h]
  char bNeedsLightmap; // [esp+13h] [ebp-1h]
  bool bNeedsLightmapa; // [esp+13h] [ebp-1h]

  v2 = (_DWORD *)((char *)host_state.worldbrush->surfacelighting->m_LightmapMins
                + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  v3 = v2[3];
  if ( v3 != r_framecount && (surfID->flags & 1) == 0 )
  {
    bNeedsLightmap = 0;
    if ( (surfID->flags & 0x400) != 0 )
    {
      v4 = v2 + 6;
      while ( *v4 != 0xFF )
      {
        if ( d_lightstyleframe[(unsigned __int8)*v4] > v3 )
        {
          bNeedsLightmap = 1;
          break;
        }
        ++v4;
        if ( (int)&v4[-24 - (_DWORD)v2] >= 4 )
          break;
      }
    }
    v5 = v2[5] == r_framecount || v2[4] != 0;
    bOnlyUseLightStyles = false;
    if ( r_dynamic.m_pParent == nullptr
      || r_dynamic.m_pParent->m_Value.m_nValue == 0
      || r_keepstyledlightmapsonly.m_pParent != nullptr && r_keepstyledlightmapsonly.m_pParent->m_Value.m_nValue != 0 )
    {
      bOnlyUseLightStyles = true;
    }
    else
    {
      bNeedsLightmap |= v5;
    }
    if ( bNeedsLightmap != 0 )
    {
      v6 = SurfNeedsBumpedLightmaps(surfID);
      v7 = SurfNeedsLightmap(surfID);
      bNeedsLightmapa = v7;
      if ( (v6 || v7)
        && (materialSortInfoArray == nullptr
         || (lightmapPageID = materialSortInfoArray[surfID->materialSortID].lightmapPageID) != -1
         && lightmapPageID != -2) )
      {
        if ( v7 || (bDlightsInLightmap = false, v6) )
          bDlightsInLightmap = true;
        updated = R_UpdateDlightState(
                    pLights: cl_dlights,
                    surfID,
                    entityToWorld: &g_LightmapTransformList.m_Memory.m_pMemory[nTransformIndex].xform,
                    bOnlyUseLightStyles,
                    bLightmap: bDlightsInLightmap);
        v10 = CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::AddToTail(this: (CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int> > *)&g_LightmapUpdateList);
        g_LightmapUpdateList.m_Memory.m_pMemory[v10].m_SurfHandle = surfID;
        g_LightmapUpdateList.m_Memory.m_pMemory[v10].m_nTransformIndex = nTransformIndex;
        g_LightmapUpdateList.m_Memory.m_pMemory[v10].m_nDlightMask = updated;
        g_LightmapUpdateList.m_Memory.m_pMemory[v10].m_bNeedsLightmap = bNeedsLightmapa;
        g_LightmapUpdateList.m_Memory.m_pMemory[v10].m_bNeedsBumpmap = v6;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C70B0
// Name: void R_RedownloadAllLightmaps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall R_RedownloadAllLightmaps(CStatTime *this)
{
  CStatTime *v1; // ecx
  IMatRenderContext *v2; // eax
  IMatRenderContext *v3; // esi
  int v4; // eax
  int numsurfaces; // esi
  int v6; // edi
  void *v7; // esp
  int v8; // eax
  int v9; // ecx
  IMaterialSystem *v10; // edi
  _DWORD *v11; // eax
  void (__thiscall ***v12)(_DWORD, _DWORD *); // ecx
  int i; // edi
  void (__thiscall ***v14)(_DWORD, _DWORD *); // edi
  IMaterialSystem *v15; // esi
  _DWORD *v16; // eax
  _DWORD *v17; // eax
  IMatRenderContext *v18; // esi
  double v19; // st7
  msurface2_t *v20[3]; // [esp+8h] [ebp-50h] BYREF
  matrix3x4_t matrix; // [esp+14h] [ebp-44h] BYREF
  double v22; // [esp+44h] [ebp-14h]
  IMatRenderContext *v23; // [esp+4Ch] [ebp-Ch]
  long double st; // [esp+50h] [ebp-8h]

  v22 = _Plat_FloatTime(this);
  if ( !host_state.worldbrush->m_bUnloadedAllLightmaps )
  {
    LOBYTE(st) = 0;
    if ( r_dynamic.m_pParent == nullptr
      || r_dynamic.m_pParent->m_Value.m_nValue == 0
      || r_keepstyledlightmapsonly.m_pParent != nullptr && r_keepstyledlightmapsonly.m_pParent->m_Value.m_nValue != 0 )
    {
      LOBYTE(st) = 1;
    }
    v2 = materials->GetRenderContext(this: materials);
    v3 = v2;
    v23 = v2;
    if ( v2 != nullptr )
      v2->BeginRender(this: v2);
    v4 = (int)v3->GetCallQueue(this: v3);
    numsurfaces = host_state.worldbrush->numsurfaces;
    v6 = v4;
    HIDWORD(st) = v4;
    v7 = alloca(4 * numsurfaces);
    v8 = 0;
    if ( numsurfaces > 0 )
    {
      v9 = 0;
      do
        v20[v8++] = &host_state.worldbrush->surfaces2[v9++];
      while ( v8 < numsurfaces );
    }
    SortSurfacesByLightmapID(pToSort: v20, iSurfaceCount: numsurfaces);
    if ( v6 != 0 )
    {
      v10 = materials;
      v11 = MemAlloc_Alloc(nSize: 0x18u);
      if ( v11 != nullptr )
      {
        v12 = (void (__thiscall ***)(_DWORD, _DWORD *))HIDWORD(st);
        v11[3] = 1;
        *v11 = &CMemberFunctor0<IMaterialSystem *,void (__thiscall IMaterialSystem::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
        v11[2] = &CMemberFunctor0<IMaterialSystem *,void (__thiscall IMaterialSystem::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
        v11[4] =  __thiscall IMaterialSystem::`vcall'{448,{flat}};
        v11[5] = v10;
        (**v12)(a1: v12, a2: v11);
      }
      else
      {
        (**(void (__thiscall ***)(_DWORD, _DWORD))HIDWORD(st))(a1: HIDWORD(st), a2: 0);
      }
    }
    else
    {
      materials->BeginUpdateLightmaps(this: materials);
    }
    SetIdentityMatrix(&matrix);
    for ( i = 0; i < numsurfaces; ++i )
      R_BuildLightMap(
        pLights: cl_dlights,
        pCallQueue: (ICallQueue *)HIDWORD(st),
        surfID: v20[i],
        entityToWorld: &matrix,
        bOnlyUseLightStyles: SLOBYTE(st));
    v14 = (void (__thiscall ***)(_DWORD, _DWORD *))HIDWORD(st);
    if ( HIDWORD(st) != 0 )
    {
      v15 = materials;
      v16 = MemAlloc_Alloc(nSize: 0x18u);
      if ( v16 != nullptr )
      {
        v16[3] = 1;
        *v16 = &CMemberFunctor0<IMaterialSystem *,void (__thiscall IMaterialSystem::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
        v16[2] = &CMemberFunctor0<IMaterialSystem *,void (__thiscall IMaterialSystem::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
        v16[4] =  __thiscall IMaterialSystem::`vcall'{452,{flat}};
        v16[5] = v15;
        (**v14)(a1: v14, a2: v16);
      }
      else
      {
        (**v14)(a1: v14, a2: nullptr);
      }
    }
    else
    {
      materials->EndUpdateLightmaps(this: materials);
    }
    if ( g_bHunkAllocLightmaps )
      goto LABEL_39;
    if ( r_unloadlightmaps.m_pParent != nullptr && r_unloadlightmaps.m_pParent->m_Value.m_nValue == 1 )
    {
      if ( v14 == nullptr )
      {
        CacheAndUnloadLightmapData();
LABEL_39:
        v18 = v23;
        v23->EndRender(this: v23);
        v18->Release(this: v18);
        goto LABEL_40;
      }
      v17 = MemAlloc_Alloc(nSize: 0x14u);
      if ( v17 != nullptr )
      {
        v17[3] = 1;
        *v17 = &CFunctor0<void (__cdecl *)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
        v17[2] = &CFunctor0<void (__cdecl *)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
        v17[4] = CacheAndUnloadLightmapData;
LABEL_38:
        (**v14)(a1: v14, a2: v17);
        goto LABEL_39;
      }
    }
    else
    {
      if ( r_keepstyledlightmapsonly.m_pParent == nullptr || r_keepstyledlightmapsonly.m_pParent->m_Value.m_nValue == 0 )
        goto LABEL_39;
      if ( v14 == nullptr )
      {
        DiscardStaticLightmapData();
        goto LABEL_39;
      }
      v17 = MemAlloc_Alloc(nSize: 0x14u);
      if ( v17 != nullptr )
      {
        v17[3] = 1;
        *v17 = &CFunctor0<void (__cdecl *)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
        v17[2] = &CFunctor0<void (__cdecl *)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
        v17[4] = DiscardStaticLightmapData;
        goto LABEL_38;
      }
    }
    v17 = nullptr;
    goto LABEL_38;
  }
LABEL_40:
  v19 = _Plat_FloatTime(this: v1);
  DevMsg(a1: "R_RedownloadAllLightmaps took %.3f msec!\n", (v19 - v22) * 1000.0);
  g_RebuildLightmaps = false;
}

//------------------------------------------------------------------------------
// Address: 0x1027B730
// Name: public: virtual void CFunctor6<void (*)(class Vector const __near &,float,int,int,class Color,bool),class Vector,float,int,int,class Color,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor6<void (__cdecl *)(Vector const &,float,int,int,Color,bool),Vector,float,int,int,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor6<void (__cdecl*)(Vector const &,float,int,int,Color,bool),Vector,float,int,int,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  ((void (__cdecl *)(Vector *, _DWORD, int, int, _DWORD, bool))this->m_pfnProxied)(
    a1: &this->m_arg1,
    a2: LODWORD(this->m_arg2),
    a3: this->m_arg3,
    a4: this->m_arg4,
    a5: *(_DWORD *)&this->m_arg5,
    a6: this->m_arg6);
}

//------------------------------------------------------------------------------
// Address: 0x1027B790
// Name: public: virtual void CFunctor6<void (*)(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,bool),class Vector,class QAngle,class Vector,class Vector,class Color,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor6<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,bool),Vector,QAngle,Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor6<void (__cdecl*)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,bool),Vector,QAngle,Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  ((void (__cdecl *)(Vector *, QAngle *, Vector *, Vector *, _DWORD, bool))this->m_pfnProxied)(
    a1: &this->m_arg1,
    a2: &this->m_arg2,
    a3: &this->m_arg3,
    a4: &this->m_arg4,
    a5: *(_DWORD *)&this->m_arg5,
    a6: this->m_arg6);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1006B690
// Name: R_ComputeSurfaceBasis
// Source: json
//------------------------------------------------------------------------------
void __usercall R_ComputeSurfaceBasis(
        msurface2_t *surfID@<eax>,
        Vector *luxelBasePosition@<edx>,
        Vector *tVect@<ecx>,
        Vector *sVect)
{
  int v5; // eax
  float v6; // xmm0_4
  float z; // xmm2_4
  float v8; // xmm3_4
  float *v9; // edx
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float y; // xmm5_4
  float v16; // xmm6_4
  int v17; // eax

  CalculateLuxelToWorldTransform(
    vFaceNormal: &surfID->plane->normal,
    pLuxelOrigin: luxelBasePosition,
    pS: sVect,
    pT: tVect,
    pTexInfo: &host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1],
    flFaceDistance: surfID->plane->dist);
  v6 = (float)*(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapMins
                         + ((v5 - (unsigned int)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  z = sVect->z;
  v8 = sVect->x * v6;
  v10 = (float)(sVect->y * v6) + v9[1];
  v9[1] = v10;
  v11 = z * v6;
  v12 = *v9;
  v13 = v11 + v9[2];
  v9[2] = v13;
  v14 = v12 + v8;
  *v9 = v14;
  y = tVect->y;
  v16 = tVect->z;
  v17 = *(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_LightmapMins[1]
                   + ((v5 - (unsigned int)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  *v9 = v14 + (float)(tVect->x * (float)v17);
  v9[1] = v10 + (float)(y * (float)v17);
  v9[2] = v13 + (float)(v16 * (float)v17);
}

//------------------------------------------------------------------------------
// Address: 0x100C4420
// Name: void R_MarkDLightNotVisible(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_MarkDLightNotVisible(char dlight)
{
  if ( ((1 << dlight) & r_dlightvisible) != 0 )
  {
    --s_nVisibleDLightCount;
    r_dlightvisible &= ~(1 << dlight);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C4450
// Name: void R_DLightEndView(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DLightEndView()
{
  int v0; // ecx
  int v1; // edx
  int v2; // eax
  int i; // esi

  if ( g_bActiveDlights )
  {
    v0 = r_dlightvisible;
    v1 = s_nVisibleDLightCount;
    v2 = 1;
    for ( i = 32; i != 0; --i )
    {
      if ( (v2 & r_dlightvisiblethisframe) == 0 && (v2 & v0) != 0 )
      {
        --v1;
        v0 &= ~v2;
      }
      v2 = __ROL4__(v2, 1);
    }
    r_dlightvisible = v0;
    s_nVisibleDLightCount = v1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C44A0
// Name: bool R_CanUseVisibleDLight(int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl R_CanUseVisibleDLight(char dlight)
{
  r_dlightvisiblethisframe |= 1 << dlight;
  if ( ((1 << dlight) & r_dlightvisible) == 0 )
  {
    if ( s_nVisibleDLightCount >= s_nMaxVisibleDLightCount )
      return 0;
    ++s_nVisibleDLightCount;
    r_dlightvisible |= 1 << dlight;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C44E0
// Name: void CacheAndUnloadLightmapData(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CacheAndUnloadLightmapData()
{
  msurfacelighting_t *surfacelighting; // esi
  int numsurfaces; // edi
  ColorRGBExp32 *v2; // ebx
  unsigned __int8 *v3; // esi
  int v4; // eax
  int v5; // edi
  unsigned __int8 *pDestBase; // [esp+0h] [ebp-8h]
  int i; // [esp+4h] [ebp-4h]

  if ( !g_bHunkAllocLightmaps )
  {
    surfacelighting = host_state.worldbrush->surfacelighting;
    numsurfaces = host_state.worldbrush->numsurfaces;
    v2 = (ColorRGBExp32 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 16 * numsurfaces);
    pDestBase = (unsigned __int8 *)v2;
    if ( numsurfaces > 0 )
    {
      v3 = &surfacelighting->m_nStyles[1];
      for ( i = numsurfaces; i != 0; --i )
      {
        v4 = *(v3 - 1) != 0xFF;
        if ( *v3 != 0xFF )
          ++v4;
        if ( v3[1] != 0xFF )
          ++v4;
        if ( v3[2] != 0xFF )
          ++v4;
        v5 = 4 * v4;
        _V_memcpy(dest: v2, src: (const void *)(*(_DWORD *)(v3 + 3) - 4 * v4), count: 4 * v4);
        v2 = (ColorRGBExp32 *)((char *)v2 + v5);
        *(_DWORD *)(v3 + 3) = v2;
        v3 += 32;
      }
      v2 = (ColorRGBExp32 *)pDestBase;
    }
    DeallocateLightingData(pBrushData: host_state.worldbrush);
    host_state.worldbrush->lightdata = v2;
    host_state.worldbrush->m_bUnloadedAllLightmaps = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C45A0
// Name: void GL_RebuildLightmaps(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GL_RebuildLightmaps()
{
  g_RebuildLightmaps = true;
}

//------------------------------------------------------------------------------
// Address: 0x100C4610
// Name: void R_DLightStartView(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DLightStartView()
{
  r_dlightvisiblethisframe = 0;
  if ( r_maxdlights.m_pParent != nullptr )
    s_nMaxVisibleDLightCount = r_maxdlights.m_pParent->m_Value.m_nValue;
  else
    s_nMaxVisibleDLightCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100C4640
// Name: AddSingleDynamicLight
// Source: json
//------------------------------------------------------------------------------
char __usercall AddSingleDynamicLight@<al>(
        dlight_t *dl@<edx>,
        msurface2_t *surfID@<ecx>,
        const Vector *lightOrigin@<eax>,
        float perpDistSq,
        float lightRadiusSq)
{
  float m_OuterAngle; // xmm0_4
  double minlight; // st7
  float y; // xmm3_4
  float z; // xmm4_4
  float *v12; // edx
  __int16 *v13; // eax
  float v14; // xmm7_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  msurfacelighting_t *surfacelighting; // eax
  unsigned int v18; // ecx
  int v19; // edi
  float v20; // xmm1_4
  int v21; // ebx
  int v22; // esi
  float v23; // xmm3_4
  int v24; // ecx
  float v25; // xmm6_4
  float v26; // xmm0_4
  float v27; // xmm0_4
  float v28; // xmm2_4
  float v29; // xmm1_4
  unsigned int v30; // eax
  int v31; // xmm0_4
  float v32; // xmm0_4
  float v33; // xmm0_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  unsigned int v36; // eax
  int v37; // xmm0_4
  float v38; // xmm0_4
  float v39; // xmm0_4
  float v40; // xmm2_4
  float v41; // xmm1_4
  unsigned int v42; // eax
  int v43; // xmm0_4
  float v44; // xmm0_4
  float v45; // xmm0_4
  float v46; // xmm2_4
  float v47; // xmm1_4
  unsigned int v48; // eax
  int v49; // xmm0_4
  float v50; // xmm3_4
  float v51; // xmm0_4
  float v52; // xmm0_4
  float v53; // xmm2_4
  float v54; // xmm1_4
  unsigned int v55; // eax
  int v56; // xmm0_4
  float local_4; // [esp+4h] [ebp-28h]
  float intensity; // [esp+Ch] [ebp-20h]
  float intensity_4; // [esp+10h] [ebp-1Ch]
  float intensity_8; // [esp+14h] [ebp-18h]
  int tmax; // [esp+18h] [ebp-14h]
  int t; // [esp+20h] [ebp-Ch]
  float ooQuadraticAttn; // [esp+28h] [ebp-4h]

  m_OuterAngle = dl->m_OuterAngle;
  if ( m_OuterAngle != 0.0
    && m_OuterAngle < 180.0
    && (float)((float)((float)(dl->m_Direction.y * surfID->plane->normal.y)
                     + (float)(surfID->plane->normal.x * dl->m_Direction.x))
             + (float)(dl->m_Direction.z * surfID->plane->normal.z)) >= 0.0 )
  {
    return 0;
  }
  minlight = dl->minlight;
  y = lightOrigin->y;
  z = lightOrigin->z;
  v12 = (float *)&host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1];
  v13 = (__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapMins
                  + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  v14 = (float)((float)((float)((float)(v12[9] * y) + (float)(lightOrigin->x * v12[8])) + (float)(v12[10] * z)) + v12[11])
      - (float)*v13;
  local_4 = (float)((float)((float)((float)(v12[13] * y) + (float)(lightOrigin->x * v12[12])) + (float)(v12[14] * z))
                  + v12[15])
          - (float)v13[1];
  v15 = dword_10425B80[dl->color.exponent];
  v16 = (float)d_lightstylevalue[dl->style] * 0.0037878789;
  intensity = (float)((float)dl->color.r * v15) * v16;
  intensity_4 = (float)((float)dl->color.g * v15) * v16;
  intensity_8 = (float)((float)dl->color.b * v15) * v16;
  if ( g_flMinLightingValue >= minlight )
    minlight = g_flMinLightingValue;
  surfacelighting = host_state.worldbrush->surfacelighting;
  v18 = ((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0;
  ooQuadraticAttn = minlight * lightRadiusSq;
  v19 = 0;
  v20 = 1.0 / lightRadiusSq;
  v21 = *(__int16 *)((char *)surfacelighting->m_LightmapExtents + v18) + 1;
  tmax = *(__int16 *)((char *)&surfacelighting->m_LightmapExtents[1] + v18) + 1;
  t = 0;
  if ( tmax > 0 )
  {
    v22 = 2;
    do
    {
      v23 = (float)(local_4 - (float)v19) * v12[17];
      v24 = 0;
      if ( v21 >= 4 )
      {
        v25 = v23 * v23;
        do
        {
          v26 = (float)(v14 - (float)v24) * v12[17];
          v27 = (float)((float)(v26 * v26) + v25) + perpDistSq;
          if ( lightRadiusSq > v27 )
          {
            if ( v27 == 0.0 )
              v28 = 1.0;
            else
              v28 = ooQuadraticAttn / v27;
            v29 = (float)(1.0 - (float)(v27 * v20)) * v28;
            if ( v29 > 2.0 )
              v29 = 2.0;
            v30 = 4 * (v22 + v24 - 2);
            blocklights[0][v30 / 4].x = (float)(intensity * v29) + blocklights[0][v30 / 4].x;
            *(float *)&dword_104F1D84[v30] = (float)(intensity_4 * v29) + *(float *)&dword_104F1D84[v30];
            *(float *)&v31 = (float)(intensity_8 * v29) + *(float *)&dword_104F1D88[v30];
            v20 = 1.0 / lightRadiusSq;
            dword_104F1D88[v30] = v31;
          }
          v32 = (float)(v14 - (float)(v24 + 1)) * v12[17];
          v33 = (float)((float)(v32 * v32) + v25) + perpDistSq;
          if ( lightRadiusSq > v33 )
          {
            if ( v33 == 0.0 )
              v34 = 1.0;
            else
              v34 = ooQuadraticAttn / v33;
            v35 = (float)(1.0 - (float)(v33 * v20)) * v34;
            if ( v35 > 2.0 )
              v35 = 2.0;
            v36 = 4 * (v22 + v24 - 1);
            blocklights[0][v36 / 4].x = (float)(intensity * v35) + blocklights[0][v36 / 4].x;
            *(float *)&dword_104F1D84[v36] = (float)(intensity_4 * v35) + *(float *)&dword_104F1D84[v36];
            *(float *)&v37 = (float)(intensity_8 * v35) + *(float *)&dword_104F1D88[v36];
            v20 = 1.0 / lightRadiusSq;
            dword_104F1D88[v36] = v37;
          }
          v38 = (float)(v14 - (float)(v24 + 2)) * v12[17];
          v39 = (float)((float)(v38 * v38) + v25) + perpDistSq;
          if ( lightRadiusSq > v39 )
          {
            if ( v39 == 0.0 )
              v40 = 1.0;
            else
              v40 = ooQuadraticAttn / v39;
            v41 = (float)(1.0 - (float)(v39 * v20)) * v40;
            if ( v41 > 2.0 )
              v41 = 2.0;
            v42 = 4 * (v22 + v24);
            blocklights[0][v42 / 4].x = (float)(intensity * v41) + blocklights[0][v42 / 4].x;
            *(float *)&dword_104F1D84[v42] = (float)(intensity_4 * v41) + *(float *)&dword_104F1D84[v42];
            *(float *)&v43 = (float)(intensity_8 * v41) + *(float *)&dword_104F1D88[v42];
            v20 = 1.0 / lightRadiusSq;
            dword_104F1D88[v42] = v43;
          }
          v44 = (float)(v14 - (float)(v24 + 3)) * v12[17];
          v45 = (float)((float)(v44 * v44) + v25) + perpDistSq;
          if ( lightRadiusSq > v45 )
          {
            if ( v45 == 0.0 )
              v46 = 1.0;
            else
              v46 = ooQuadraticAttn / v45;
            v47 = (float)(1.0 - (float)(v45 * v20)) * v46;
            if ( v47 > 2.0 )
              v47 = 2.0;
            v48 = 4 * (v22 + v24 + 1);
            blocklights[0][v48 / 4].x = (float)(intensity * v47) + blocklights[0][v48 / 4].x;
            *(float *)&dword_104F1D84[v48] = (float)(intensity_4 * v47) + *(float *)&dword_104F1D84[v48];
            *(float *)&v49 = (float)(intensity_8 * v47) + *(float *)&dword_104F1D88[v48];
            v20 = 1.0 / lightRadiusSq;
            dword_104F1D88[v48] = v49;
          }
          v24 += 4;
        }
        while ( v24 < v21 - 3 );
        v19 = t;
      }
      if ( v24 < v21 )
      {
        v50 = v23 * v23;
        do
        {
          v51 = (float)(v14 - (float)v24) * v12[17];
          v52 = (float)((float)(v51 * v51) + v50) + perpDistSq;
          if ( lightRadiusSq > v52 )
          {
            if ( v52 == 0.0 )
              v53 = 1.0;
            else
              v53 = ooQuadraticAttn / v52;
            v54 = (float)(1.0 - (float)(v52 * v20)) * v53;
            if ( v54 > 2.0 )
              v54 = 2.0;
            v55 = 4 * (v22 + v24 - 2);
            blocklights[0][v55 / 4].x = (float)(intensity * v54) + blocklights[0][v55 / 4].x;
            *(float *)&dword_104F1D84[v55] = (float)(intensity_4 * v54) + *(float *)&dword_104F1D84[v55];
            *(float *)&v56 = (float)(intensity_8 * v54) + *(float *)&dword_104F1D88[v55];
            v20 = 1.0 / lightRadiusSq;
            dword_104F1D88[v55] = v56;
          }
          ++v24;
        }
        while ( v24 < v21 );
      }
      ++v19;
      v22 += v21;
      t = v19;
    }
    while ( v19 < tmax );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C4C30
// Name: AddSingleDynamicLightToBumpLighting
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddSingleDynamicLightToBumpLighting(
        msurface2_t *surfID,
        const Vector *lightOrigin,
        float perpDistSq,
        float lightRadiusSq,
        Vector *pBumpBasis,
        const Vector *luxelBasePosition)
{
  dlight_t *dl; // ecx
  const Vector *v7; // edx
  double minlight; // st7
  float y; // xmm2_4
  float z; // xmm3_4
  float *v11; // esi
  __int16 *v12; // eax
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm3_4
  float v16; // xmm4_4
  float v17; // xmm5_4
  float m_OuterAngle; // xmm0_4
  double v19; // st7
  double x; // st6
  float v21; // xmm0_4
  char *v22; // eax
  int v23; // ecx
  int v24; // eax
  int v25; // edi
  int v26; // ecx
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm6_4
  float v31; // xmm7_4
  int v32; // ebx
  float v33; // xmm0_4
  float v34; // xmm0_4
  float v35; // xmm2_4
  float v36; // xmm1_4
  int v37; // edi
  bool v38; // zf
  float *p_x; // eax
  double v40; // st7
  float v41; // xmm0_4
  float v42; // xmm1_4
  float v43; // xmm0_4
  float *v44; // eax
  float v45; // xmm0_4
  float v46; // xmm0_4
  float *v47; // eax
  float v48; // xmm0_4
  float v49; // xmm0_4
  float v50; // xmm0_4
  int v51; // edi
  float local; // [esp+0h] [ebp-5Ch]
  float local_4; // [esp+4h] [ebp-58h]
  float intensity; // [esp+Ch] [ebp-50h]
  float intensity_4; // [esp+10h] [ebp-4Ch]
  float intensity_8; // [esp+14h] [ebp-48h]
  float texelWorldPosition; // [esp+18h] [ebp-44h]
  float texelWorldPosition_4; // [esp+1Ch] [ebp-40h]
  float texelWorldPosition_8; // [esp+20h] [ebp-3Ch]
  Vector lightDirection; // [esp+24h] [ebp-38h] BYREF
  int tmax; // [esp+30h] [ebp-2Ch]
  float lDotN; // [esp+34h] [ebp-28h]
  float ooRadiusSq; // [esp+38h] [ebp-24h]
  float ooQuadraticAttn; // [esp+3Ch] [ebp-20h]
  float v65; // [esp+40h] [ebp-1Ch]
  float fixupFactor; // [esp+44h] [ebp-18h]
  int t; // [esp+48h] [ebp-14h]
  int smax; // [esp+4Ch] [ebp-10h]
  float scale; // [esp+50h] [ebp-Ch]
  int v70; // [esp+54h] [ebp-8h]
  bool useLightDirection; // [esp+5Bh] [ebp-1h]

  v7 = lightOrigin;
  minlight = dl->minlight;
  y = lightOrigin->y;
  z = lightOrigin->z;
  v11 = (float *)&host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1];
  v12 = (__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapMins
                  + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  local = (float)((float)((float)((float)(v11[9] * y) + (float)(lightOrigin->x * v11[8])) + (float)(v11[10] * z))
                + v11[11])
        - (float)*v12;
  local_4 = (float)((float)((float)((float)(lightOrigin->x * v11[12]) + (float)(y * v11[13])) + (float)(z * v11[14]))
                  + v11[15])
          - (float)v12[1];
  v13 = dword_10425B80[dl->color.exponent];
  v14 = (float)d_lightstylevalue[dl->style] * 0.0037878789;
  v15 = (float)((float)dl->color.r * v13) * v14;
  v16 = (float)((float)dl->color.g * v13) * v14;
  v17 = (float)((float)dl->color.b * v13) * v14;
  intensity = v15;
  intensity_4 = v16;
  intensity_8 = v17;
  if ( g_flMinLightingValue >= minlight )
    minlight = g_flMinLightingValue;
  ooRadiusSq = 1.0 / lightRadiusSq;
  m_OuterAngle = dl->m_OuterAngle;
  ooQuadraticAttn = minlight * lightRadiusSq;
  if ( m_OuterAngle == 0.0
    || (v19 = dl->m_Direction.y,
        x = dl->m_Direction.x,
        t = SLODWORD(dl->m_Direction.x),
        fabs(v19 * v19 + x * x + dl->m_Direction.z * dl->m_Direction.z - 1.0) >= 0.001) )
  {
    useLightDirection = false;
  }
  else
  {
    lightDirection.x = *(float *)&t * -1.0;
    lightDirection.y = dl->m_Direction.y * -1.0;
    v21 = dl->m_Direction.z * -1.0;
    useLightDirection = true;
    lightDirection.z = v21;
  }
  v22 = (char *)host_state.worldbrush->surfacelighting
      + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0);
  v23 = *((__int16 *)v22 + 2);
  v24 = *((__int16 *)v22 + 3) + 1;
  v25 = 0;
  v26 = v23 + 1;
  v27 = v11[17] * v11[17];
  fixupFactor = v27;
  smax = v26;
  tmax = v24;
  *(float *)&t = 0.0;
  if ( v24 > 0 )
  {
    v70 = 0;
    while ( 1 )
    {
      v29 = (float)v25 * v27;
      v30 = (float)(v11[12] * v29) + luxelBasePosition->x;
      v31 = (float)(v11[13] * v29) + luxelBasePosition->y;
      v32 = 0;
      texelWorldPosition = v30;
      texelWorldPosition_4 = v31;
      texelWorldPosition_8 = (float)(v11[14] * v29) + luxelBasePosition->z;
      if ( v26 > 0 )
      {
        v28 = (float)(local_4 - (float)v25) * v11[17];
        v65 = v28 * v28;
        do
        {
          v33 = (float)(local - (float)v32) * v11[17];
          v34 = (float)((float)(v33 * v33) + v65) + perpDistSq;
          if ( lightRadiusSq > v34 )
          {
            if ( v34 == 0.0 )
              v35 = 1.0;
            else
              v35 = ooQuadraticAttn / v34;
            v36 = (float)(1.0 - (float)(v34 * ooRadiusSq)) * v35;
            scale = v36;
            if ( v36 > 2.0 )
            {
              v36 = 2.0;
              scale = 2.0;
            }
            v37 = v32 + v70;
            v38 = !useLightDirection;
            p_x = &blocklights[0][v32 + v70].x;
            *p_x = (float)(v15 * v36) + *p_x;
            p_x[1] = (float)(v16 * v36) + p_x[1];
            p_x[2] = (float)(v17 * v36) + p_x[2];
            if ( v38 )
            {
              lightDirection.x = v7->x - v30;
              lightDirection.y = v7->y - v31;
              lightDirection.z = v7->z - texelWorldPosition_8;
              VectorNormalize(vec: &lightDirection);
              v36 = scale;
              v30 = texelWorldPosition;
              v17 = intensity_8;
              v16 = intensity_4;
              v15 = intensity;
              v7 = lightOrigin;
            }
            v40 = surfID->plane->normal.y * lightDirection.y
                + surfID->plane->normal.x * lightDirection.x
                + surfID->plane->normal.z * lightDirection.z;
            lDotN = v40;
            if ( v40 >= 0.001 )
              v41 = lDotN;
            else
              v41 = 0.001;
            v42 = v36 * v41;
            v43 = (float)((float)(pBumpBasis->y * lightDirection.y) + (float)(pBumpBasis->x * lightDirection.x))
                + (float)(pBumpBasis->z * lightDirection.z);
            if ( v43 > 0.0 )
            {
              v44 = &flt_10531D80[4 * v37];
              v45 = v43 * v42;
              *v44 = (float)(v15 * v45) + *v44;
              v44[1] = (float)(v16 * v45) + v44[1];
              v44[2] = (float)(v17 * v45) + v44[2];
            }
            v46 = (float)((float)(pBumpBasis[1].y * lightDirection.y) + (float)(pBumpBasis[1].x * lightDirection.x))
                + (float)(pBumpBasis[1].z * lightDirection.z);
            if ( v46 > 0.0 )
            {
              v47 = &flt_10571D80[4 * v37];
              v48 = v46 * v42;
              *v47 = (float)(v15 * v48) + *v47;
              v47[1] = (float)(v16 * v48) + v47[1];
              v47[2] = (float)(v17 * v48) + v47[2];
            }
            v31 = texelWorldPosition_4;
            v26 = smax;
            v49 = (float)((float)(pBumpBasis[2].y * lightDirection.y) + (float)(pBumpBasis[2].x * lightDirection.x))
                + (float)(pBumpBasis[2].z * lightDirection.z);
            if ( v49 > 0.0 )
            {
              v50 = v49 * v42;
              v51 = 4 * v37;
              *(float *)&dword_105B1D80[v51] = (float)(v15 * v50) + *(float *)&dword_105B1D80[v51];
              *(float *)&dword_105B1D84[v51] = (float)(v16 * v50) + *(float *)&dword_105B1D84[v51];
              *(float *)&dword_105B1D88[v51] = (float)(v17 * v50) + *(float *)&dword_105B1D88[v51];
            }
          }
          ++v32;
        }
        while ( v32 < v26 );
        v25 = t;
      }
      v70 += v26;
      t = ++v25;
      if ( v25 >= tmax )
        break;
      v27 = fixupFactor;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C5190
// Name: R_ComputeSurfaceBasis_0
// Source: json
//------------------------------------------------------------------------------
void __usercall R_ComputeSurfaceBasis_0(
        msurface2_t *surfID@<eax>,
        Vector *luxelBasePosition@<esi>,
        Vector *pBumpNormals)
{
  mtexinfo_t *texinfo; // edx
  int v5; // eax
  float x; // xmm0_4
  int lightmapVecsLuxelsPerWorldUnits; // eax
  mtexinfo_t *v8; // eax
  float v9; // xmm0_4
  int v10; // eax
  mtexinfo_t *v11; // eax
  int v12; // edx
  float worldUnitsPerLuxel; // xmm1_4
  float *v14; // eax
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  float *v18; // eax
  float v19; // xmm0_4
  cplane_t *plane; // edi
  float dist; // xmm0_4
  Vector sVect; // [esp+4h] [ebp-18h] BYREF
  Vector tVect; // [esp+10h] [ebp-Ch] BYREF

  texinfo = host_state.worldbrush->texinfo;
  v5 = *((unsigned __int16 *)surfID + 11) >> 1;
  x = texinfo[v5].lightmapVecsLuxelsPerWorldUnits[0].x;
  lightmapVecsLuxelsPerWorldUnits = (int)texinfo[v5].lightmapVecsLuxelsPerWorldUnits;
  sVect.x = x;
  sVect.y = *(float *)(lightmapVecsLuxelsPerWorldUnits + 4);
  sVect.z = *(float *)(lightmapVecsLuxelsPerWorldUnits + 8);
  VectorNormalize(vec: &sVect);
  v8 = host_state.worldbrush->texinfo;
  v9 = v8[*((unsigned __int16 *)surfID + 11) >> 1].lightmapVecsLuxelsPerWorldUnits[1].x;
  v10 = (int)&v8[*((unsigned __int16 *)surfID + 11) >> 1].lightmapVecsLuxelsPerWorldUnits[1];
  tVect.x = v9;
  tVect.y = *(float *)(v10 + 4);
  tVect.z = *(float *)(v10 + 8);
  VectorNormalize(vec: &tVect);
  GetBumpNormals(
    &sVect,
    &tVect,
    flatNormal: &surfID->plane->normal,
    phongNormal: &surfID->plane->normal,
    bumpNormals: pBumpNormals);
  v11 = host_state.worldbrush->texinfo;
  v12 = *((unsigned __int16 *)surfID + 11) >> 1;
  worldUnitsPerLuxel = v11[v12].worldUnitsPerLuxel;
  v14 = (float *)&v11[v12];
  v15 = worldUnitsPerLuxel * worldUnitsPerLuxel;
  v16 = (float)((float)*(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapMins
                                  + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0))
              - v14[11])
      * v15;
  luxelBasePosition->x = v16 * v14[8];
  luxelBasePosition->y = v14[9] * v16;
  v17 = v14[10] * v16;
  luxelBasePosition->z = v17;
  v18 = (float *)&host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1];
  v19 = (float)((float)*(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_LightmapMins[1]
                                  + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0))
              - v18[15])
      * v15;
  luxelBasePosition->x = (float)(v18[12] * v19) + luxelBasePosition->x;
  luxelBasePosition->y = (float)(v18[13] * v19) + luxelBasePosition->y;
  luxelBasePosition->z = (float)(v18[14] * v19) + v17;
  plane = surfID->plane;
  dist = plane->dist;
  luxelBasePosition->x = (float)(plane->normal.x * dist) + luxelBasePosition->x;
  luxelBasePosition->y = (float)(plane->normal.y * dist) + luxelBasePosition->y;
  luxelBasePosition->z = (float)(plane->normal.z * dist) + luxelBasePosition->z;
}

//------------------------------------------------------------------------------
// Address: 0x100C5360
// Name: unsigned int R_ComputeDynamicLightMask(struct dlight_t __near *,struct msurface2_t __near *,struct msurfacelighting_t __near *,struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl R_ComputeDynamicLightMask(
        dlight_t *pLights,
        msurface2_t *surfID,
        msurfacelighting_t *pLighting,
        const matrix3x4_t *entityToWorld)
{
  int v5; // ebx
  int v6; // esi
  float *p_radius; // edi
  float v8; // xmm0_4
  Vector lightOrigin; // [esp+0h] [ebp-14h] BYREF
  int lightMask; // [esp+Ch] [ebp-8h]
  int mask; // [esp+10h] [ebp-4h]

  if ( (surfID->flags & 0x800) != 0 )
    return surfID->pDispInfo->ComputeDynamicLightMask(this: surfID->pDispInfo, a2: pLights);
  v5 = 0;
  if ( !g_bActiveDlights )
    return 0;
  lightMask = 0;
  v6 = 1;
  mask = r_dlightactive;
  p_radius = &pLights->radius;
  do
  {
    if ( (mask & 1) != 0
      && (v6 & pLighting->m_fDLightBits) != 0
      && (*(_BYTE *)(p_radius - 4) & 0xD) == 0
      && R_CanUseVisibleDLight(dlight: v5) != 0 )
    {
      VectorITransform(in1: p_radius - 3, in2: entityToWorld, out: &lightOrigin.x);
      v8 = (float)((float)((float)(surfID->plane->normal.y * lightOrigin.y)
                         + (float)(lightOrigin.x * surfID->plane->normal.x))
                 + (float)(surfID->plane->normal.z * lightOrigin.z))
         - surfID->plane->dist;
      if ( v8 >= -15.0 )
      {
        if ( (float)(v8 * v8) < (float)(*p_radius * *p_radius) )
          lightMask |= v6;
        else
          pLighting->m_fDLightBits &= ~v6;
      }
      else
      {
        pLighting->m_fDLightBits &= ~v6;
      }
    }
    mask >>= 1;
    ++v5;
    p_radius += 17;
    v6 *= 2;
  }
  while ( v5 < 32 );
  return lightMask;
}

//------------------------------------------------------------------------------
// Address: 0x100C5480
// Name: ComputeLightmapSize
// Source: json
//------------------------------------------------------------------------------
int __fastcall ComputeLightmapSize(int a1, msurface2_t *surfID)
{
  char *v2; // ecx
  int result; // eax
  int v4; // ecx
  IMaterial *material; // ecx
  const char *v6; // eax

  v2 = (char *)host_state.worldbrush->surfacelighting
     + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0);
  result = (*((__int16 *)v2 + 2) + 1) * (*((__int16 *)v2 + 3) + 1);
  v4 = (surfID->flags & 0x800) != 0 ? 128 : 35;
  if ( result > v4 * v4 )
  {
    material = materialSortInfoArray[surfID->materialSortID].material;
    v6 = (const char *)material->GetName(this: material);
    ConMsg(a1: "Bad lightmap extents on material \"%s\"\n", v6);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C54F0
// Name: AccumulateLightstyles
// Source: json
//------------------------------------------------------------------------------
void __usercall AccumulateLightstyles(float a1@<xmm0>, ColorRGBExp32 *pLightmap, int lightmapSize)
{
  int v3; // edx
  int v4; // esi
  char *p_exponent; // ecx
  unsigned int v6; // edx
  float *v7; // eax
  float *v8; // eax
  char *v9; // ecx
  int v10; // edx

  v3 = lightmapSize;
  v4 = 0;
  if ( lightmapSize >= 4 )
  {
    p_exponent = &pLightmap->exponent;
    v6 = ((unsigned int)(lightmapSize - 4) >> 2) + 1;
    v7 = (float *)dword_104F1D84;
    v4 = 4 * v6;
    do
    {
      *(v7 - 1) = (float)((float)((float)(unsigned __int8)*(p_exponent - 3) * dword_10425B80[*p_exponent]) * a1)
                + *(v7 - 1);
      *v7 = (float)((float)((float)(unsigned __int8)*(p_exponent - 2) * dword_10425B80[*p_exponent]) * a1) + *v7;
      v7[1] = (float)((float)((float)(unsigned __int8)*(p_exponent - 1) * dword_10425B80[*p_exponent]) * a1) + v7[1];
      v7[3] = (float)((float)((float)(unsigned __int8)p_exponent[1] * dword_10425B80[p_exponent[4]]) * a1) + v7[3];
      v7[4] = (float)((float)((float)(unsigned __int8)p_exponent[2] * dword_10425B80[p_exponent[4]]) * a1) + v7[4];
      v7[5] = (float)((float)((float)(unsigned __int8)p_exponent[3] * dword_10425B80[p_exponent[4]]) * a1) + v7[5];
      v7[7] = (float)((float)((float)(unsigned __int8)p_exponent[5] * dword_10425B80[p_exponent[8]]) * a1) + v7[7];
      v7[8] = (float)((float)((float)(unsigned __int8)p_exponent[6] * dword_10425B80[p_exponent[8]]) * a1) + v7[8];
      v7[9] = (float)((float)((float)(unsigned __int8)p_exponent[7] * dword_10425B80[p_exponent[8]]) * a1) + v7[9];
      v7[11] = (float)((float)((float)(unsigned __int8)p_exponent[9] * dword_10425B80[p_exponent[12]]) * a1) + v7[11];
      v7[12] = (float)((float)((float)(unsigned __int8)p_exponent[10] * dword_10425B80[p_exponent[12]]) * a1) + v7[12];
      v7[13] = (float)((float)((float)(unsigned __int8)p_exponent[11] * dword_10425B80[p_exponent[12]]) * a1) + v7[13];
      v7 += 16;
      p_exponent += 16;
      --v6;
    }
    while ( v6 != 0 );
    v3 = lightmapSize;
  }
  if ( v4 < v3 )
  {
    v8 = (float *)&dword_104F1D84[4 * v4];
    v9 = &pLightmap[v4].exponent;
    v10 = v3 - v4;
    do
    {
      *(v8 - 1) = (float)((float)((float)(unsigned __int8)*(v9 - 3) * dword_10425B80[*v9]) * a1) + *(v8 - 1);
      *v8 = (float)((float)((float)(unsigned __int8)*(v9 - 2) * dword_10425B80[*v9]) * a1) + *v8;
      v8[1] = (float)((float)((float)(unsigned __int8)*(v9 - 1) * dword_10425B80[*v9]) * a1) + v8[1];
      v8 += 4;
      v9 += 4;
      --v10;
    }
    while ( v10 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C5790
// Name: AccumulateLightstylesFlat
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__usercall AccumulateLightstylesFlat@<eax>(
        unsigned __int8 *result@<eax>,
        int a2@<ecx>,
        float a3@<xmm0>)
{
  int v4; // edx
  unsigned int v5; // edx
  float *v6; // ecx
  float *v7; // ecx
  int v8; // esi
  int i; // [esp+8h] [ebp-4h]

  v4 = 0;
  if ( a2 >= 4 )
  {
    v5 = ((unsigned int)(a2 - 4) >> 2) + 1;
    v6 = (float *)dword_104F1D84;
    i = 4 * v5;
    do
    {
      *(v6 - 1) = (float)((float)((float)*result * dword_10425B80[(char)result[3]]) * a3) + *(v6 - 1);
      *v6 = (float)((float)((float)result[1] * dword_10425B80[(char)result[3]]) * a3) + *v6;
      v6[1] = (float)((float)((float)result[2] * dword_10425B80[(char)result[3]]) * a3) + v6[1];
      v6[3] = (float)((float)((float)*result * dword_10425B80[(char)result[3]]) * a3) + v6[3];
      v6[4] = (float)((float)((float)result[1] * dword_10425B80[(char)result[3]]) * a3) + v6[4];
      v6[5] = (float)((float)((float)result[2] * dword_10425B80[(char)result[3]]) * a3) + v6[5];
      v6[7] = (float)((float)((float)*result * dword_10425B80[(char)result[3]]) * a3) + v6[7];
      v6[8] = (float)((float)((float)result[1] * dword_10425B80[(char)result[3]]) * a3) + v6[8];
      v6[9] = (float)((float)((float)result[2] * dword_10425B80[(char)result[3]]) * a3) + v6[9];
      v6[11] = (float)((float)((float)*result * dword_10425B80[(char)result[3]]) * a3) + v6[11];
      v6[12] = (float)((float)((float)result[1] * dword_10425B80[(char)result[3]]) * a3) + v6[12];
      v6[13] = (float)((float)((float)result[2] * dword_10425B80[(char)result[3]]) * a3) + v6[13];
      v6 += 16;
      --v5;
    }
    while ( v5 != 0 );
    v4 = i;
  }
  if ( v4 < a2 )
  {
    v7 = (float *)&dword_104F1D84[4 * v4];
    v8 = a2 - v4;
    do
    {
      *(v7 - 1) = (float)((float)((float)*result * dword_10425B80[(char)result[3]]) * a3) + *(v7 - 1);
      *v7 = (float)((float)((float)result[1] * dword_10425B80[(char)result[3]]) * a3) + *v7;
      v7[1] = (float)((float)((float)result[2] * dword_10425B80[(char)result[3]]) * a3) + v7[1];
      v7 += 4;
      --v8;
    }
    while ( v8 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C5A20
// Name: AccumulateBumpedLightstyles
// Source: json
//------------------------------------------------------------------------------
float *__usercall AccumulateBumpedLightstyles@<eax>(int a1@<eax>, float a2@<xmm0>, int lightmapSize)
{
  float *result; // eax
  unsigned __int8 *v5; // edx
  float *v6; // eax
  char *v7; // ecx
  int v8; // edi
  unsigned __int8 *v9; // edx
  char *v10; // ecx
  int v11; // esi
  float *pBumpedLightmaps_4; // [esp+10h] [ebp-Ch]
  int pBumpedLightmaps_8; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  result = (float *)(a1 + 8 * lightmapSize);
  pBumpedLightmaps_4 = result;
  pBumpedLightmaps_8 = a1 + 12 * lightmapSize;
  if ( lightmapSize > 0 )
  {
    v5 = (unsigned __int8 *)(a1 + 4 * lightmapSize + 2);
    v6 = (float *)dword_104F1D84;
    v7 = (char *)(a1 + 3);
    v8 = 4 * lightmapSize;
    for ( i = lightmapSize; i != 0; --i )
    {
      *(v6 - 1) = (float)((float)((float)(unsigned __int8)*(v7 - 3) * dword_10425B80[*v7]) * a2) + *(v6 - 1);
      *v6 = (float)((float)((float)(unsigned __int8)*(v7 - 2) * dword_10425B80[*v7]) * a2) + *v6;
      v6[1] = (float)((float)((float)(unsigned __int8)*(v7 - 1) * dword_10425B80[*v7]) * a2) + v6[1];
      v6[0xFFFF] = (float)((float)((float)*(v5 - 2) * dword_10425B80[v7[v8]]) * a2) + v6[0xFFFF];
      v6[0x10000] = (float)((float)((float)*(v5 - 1) * dword_10425B80[v7[v8]]) * a2) + v6[0x10000];
      v6[65537] = (float)((float)((float)*v5 * dword_10425B80[v7[v8]]) * a2) + v6[65537];
      v6 += 4;
      v7 += 4;
      v5 += 4;
    }
    v9 = (unsigned __int8 *)(pBumpedLightmaps_8 + 2);
    v10 = (char *)pBumpedLightmaps_4 + 3;
    v11 = pBumpedLightmaps_8 - (_DWORD)pBumpedLightmaps_4;
    result = &flt_10571D84;
    do
    {
      *(result - 1) = (float)((float)((float)(unsigned __int8)*(v10 - 3) * dword_10425B80[*v10]) * a2) + *(result - 1);
      *result = (float)((float)((float)(unsigned __int8)*(v10 - 2) * dword_10425B80[*v10]) * a2) + *result;
      result[1] = (float)((float)((float)(unsigned __int8)*(v10 - 1) * dword_10425B80[*v10]) * a2) + result[1];
      result[0xFFFF] = (float)((float)((float)*(v9 - 2) * dword_10425B80[v10[v11]]) * a2) + result[0xFFFF];
      result[0x10000] = (float)((float)((float)*(v9 - 1) * dword_10425B80[v10[v11]]) * a2) + result[0x10000];
      result[65537] = (float)((float)((float)*v9 * dword_10425B80[v10[v11]]) * a2) + result[65537];
      result += 4;
      v10 += 4;
      v9 += 4;
      --lightmapSize;
    }
    while ( lightmapSize != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C5CA0
// Name: ComputeLightmapFromLightstyle
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeLightmapFromLightstyle(
        msurfacelighting_t *pLighting,
        bool computeLightmap,
        bool computeBumpmap,
        int lightmapSize,
        bool hasBumpmapLightmapData)
{
  ColorRGBExp32 *m_pSamples; // esi
  int m_nValue; // eax
  unsigned int v7; // ebx
  unsigned __int8 *i; // edi
  unsigned __int8 v9; // cl
  int v10; // eax
  float v11; // xmm0_4
  int v12; // eax
  int maxmap; // [esp+8h] [ebp-4h]

  m_pSamples = pLighting->m_pSamples;
  if ( r_lightmap.m_pParent != nullptr )
  {
    m_nValue = r_lightmap.m_pParent->m_Value.m_nValue;
    if ( m_nValue == -1 )
    {
      m_nValue = 0;
      maxmap = 4;
      goto LABEL_4;
    }
  }
  else
  {
    m_nValue = 0;
  }
  maxmap = m_nValue + 1;
LABEL_4:
  if ( m_nValue < maxmap )
  {
    v7 = 4 * m_nValue;
    for ( i = &pLighting->m_nStyles[m_nValue]; (int)&i[-24 - (_DWORD)pLighting] < maxmap; ++i )
    {
      v9 = *i;
      if ( *i == 0xFF )
        return;
      if ( r_lightstyle.m_pParent != nullptr )
      {
        v10 = r_lightstyle.m_pParent->m_Value.m_nValue;
        if ( v10 == -1 )
          goto LABEL_14;
      }
      else
      {
        v10 = 0;
      }
      if ( v9 == v10 )
      {
LABEL_14:
        v11 = (float)d_lightstylevalue[v9] * 0.0037878789;
        if ( v11 > 0.0 )
        {
          if ( computeBumpmap )
          {
            AccumulateBumpedLightstyles(a1: (int)m_pSamples, a2: v11, lightmapSize);
          }
          else if ( computeLightmap )
          {
            if ( r_avglightmap.m_pParent != nullptr && r_avglightmap.m_pParent->m_Value.m_nValue != 0 )
            {
              m_pSamples = &pLighting->m_pSamples[v7 / 0xFFFFFFFC - 1];
              AccumulateLightstylesFlat(result: (unsigned __int8 *)m_pSamples, a2: lightmapSize, a3: v11);
            }
            else
            {
              AccumulateLightstyles(a1: v11, pLightmap: m_pSamples, lightmapSize);
            }
          }
        }
        v12 = lightmapSize;
        if ( hasBumpmapLightmapData )
          v12 = 4 * lightmapSize;
        m_pSamples += v12;
      }
      v7 += 4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C5DC0
// Name: UpdateLightmapTextures
// Source: json
//------------------------------------------------------------------------------
void __usercall UpdateLightmapTextures(msurface2_t *surfID@<edx>, bool needsBumpmap)
{
  int v2; // ecx
  int materialSortID; // edx
  int lightmapPageID; // edx
  void (__thiscall *UpdateLightmap)(IMaterialSystem *, int, int *, int *, float *, float *, float *, float *); // eax
  int lightmapSize[2]; // [esp+4h] [ebp-10h] BYREF
  int offsetIntoLightmapPage[2]; // [esp+Ch] [ebp-8h] BYREF

  if ( materialSortInfoArray != nullptr )
  {
    lightmapSize[0] = *(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapExtents
                                 + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0))
                    + 1;
    lightmapSize[1] = *(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_LightmapExtents[1]
                                 + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0))
                    + 1;
    offsetIntoLightmapPage[0] = *(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_OffsetIntoLightmapPage
                                           + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
    v2 = (char *)surfID - (char *)host_state.worldbrush->surfaces2;
    materialSortID = surfID->materialSortID;
    offsetIntoLightmapPage[1] = *(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_OffsetIntoLightmapPage[1]
                                           + (v2 & 0xFFFFFFE0));
    lightmapPageID = materialSortInfoArray[materialSortID].lightmapPageID;
    UpdateLightmap = materials->UpdateLightmap;
    if ( needsBumpmap )
      ((void (__stdcall *)(int, int *, int *, Vector4D *, float *, float *, int *))UpdateLightmap)(
        a1: lightmapPageID,
        a2: lightmapSize,
        a3: offsetIntoLightmapPage,
        a4: (Vector4D *)blocklights,
        a5: flt_10531D80,
        a6: flt_10571D80,
        a7: dword_105B1D80);
    else
      ((void (__stdcall *)(int, int *, int *, Vector4D *, _DWORD, _DWORD, _DWORD))UpdateLightmap)(
        a1: lightmapPageID,
        a2: lightmapSize,
        a3: offsetIntoLightmapPage,
        a4: (Vector4D *)blocklights,
        a5: 0,
        a6: 0,
        a7: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C5E90
// Name: unsigned int R_UpdateDlightState(struct dlight_t __near *,struct msurface2_t __near *,struct matrix3x4_t const __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl R_UpdateDlightState(
        dlight_t *pLights,
        msurface2_t *surfID,
        const matrix3x4_t *entityToWorld,
        bool bOnlyUseLightStyles,
        bool bLightmap)
{
  int result; // eax
  msurfacelighting_t *v6; // esi

  result = 0;
  v6 = (msurfacelighting_t *)((char *)host_state.worldbrush->surfacelighting
                            + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  v6->m_fDLightBits &= r_dlightactive;
  v6->m_nLastComputedFrame = r_framecount;
  if ( !bOnlyUseLightStyles
    && (!bLightmap
     || v6->m_nDLightFrame != r_framecount
     || (result = R_ComputeDynamicLightMask(pLights, surfID, pLighting: v6, entityToWorld)) == 0
     || v6->m_fDLightBits == 0) )
  {
    v6->m_fDLightBits = 0;
    surfID->flags &= ~0x80000u;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C5F10
// Name: SortSurfacesByLightmapID
// Source: json
//------------------------------------------------------------------------------
void __cdecl SortSurfacesByLightmapID(msurface2_t **pToSort, int iSurfaceCount)
{
  int v2; // esi
  void *v3; // esp
  int v4; // ebx
  msurface2_t **v5; // eax
  msurface2_t **v6; // edi
  int i; // eax
  int v8; // edx
  int j; // eax
  int v10; // ecx
  int v11; // eax
  msurface2_t *v12; // esi
  int v13; // ecx
  int v14; // edx
  int v15; // [esp+0h] [ebp-814h] BYREF
  _DWORD v16[256]; // [esp+Ch] [ebp-808h]
  _DWORD v17[256]; // [esp+40Ch] [ebp-408h] BYREF
  msurface2_t **v18; // [esp+80Ch] [ebp-8h]
  int v19; // [esp+810h] [ebp-4h]

  v2 = iSurfaceCount;
  v3 = alloca(4 * iSurfaceCount);
  v4 = 0;
  v5 = (msurface2_t **)&v15;
  v19 = 0;
  while ( 1 )
  {
    v6 = pToSort;
    pToSort = v5;
    v18 = v6;
    memset(v17, 0, sizeof(v17));
    for ( i = 0; i != v2; ++v17[(unsigned __int8)v8] )
      v8 = materialSortInfoArray[v6[i++]->materialSortID].lightmapPageID >> v4;
    v16[0] = 0;
    for ( j = 0; j != 255; v16[j] = v10 )
    {
      v10 = v17[j] + v16[j];
      ++j;
    }
    v11 = 0;
    if ( v2 != 0 )
    {
      do
      {
        v12 = v6[v11++];
        v13 = (unsigned __int8)(materialSortInfoArray[v12->materialSortID].lightmapPageID >> v4);
        v14 = v16[v13];
        pToSort[v14] = v12;
        v2 = iSurfaceCount;
        v4 = v19;
        v16[v13] = v14 + 1;
      }
      while ( v11 != iSurfaceCount );
    }
    v4 += 8;
    v19 = v4;
    if ( v4 == 32 )
      break;
    v5 = v18;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C6040
// Name: int LightmapPageCompareFunc(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LightmapPageCompareFunc(const void *pElem0, const void *pElem1)
{
  return materialSortInfoArray[*(__int16 *)(*(_DWORD *)pElem0 + 18)].lightmapPageID
       - materialSortInfoArray[*(__int16 *)(*(_DWORD *)pElem1 + 18)].lightmapPageID;
}

//------------------------------------------------------------------------------
// Address: 0x100C61D0
// Name: void R_BuildLightMapGuts(struct dlight_t __near *,struct msurface2_t __near *,struct matrix3x4_t const __near &,unsigned int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_BuildLightMapGuts(
        dlight_t *pLights,
        msurface2_t *surfID,
        const matrix3x4_t *entityToWorld,
        unsigned int dlightMask,
        bool needsBumpmap,
        bool needsLightmap)
{
  int v6; // ecx
  msurface2_t *v7; // esi
  msurfacelighting_t *v8; // ebx
  int v9; // edi
  bool v10; // al
  bool v11; // dl
  int v12; // xmm1_4
  int *v13; // ecx
  int i; // edx
  float *v15; // esi
  bool v16; // al
  float m_fValue; // xmm1_4
  float *v18; // ecx
  int j; // edx
  bool v20; // cl
  bool v21; // al
  int *v22; // ebx
  int v23; // esi
  unsigned int v24; // edx
  int *v25; // eax
  int *v26; // ecx
  double v27; // st7
  int *v28; // eax
  int *v29; // ecx
  int v30; // edx
  double v31; // st7
  float *v32; // eax
  int m; // ecx
  float *v34; // eax
  int n; // ecx
  int *v36; // eax
  int k; // [esp+Ch] [ebp-Ch]
  bool hasBumpmap; // [esp+10h] [ebp-8h]
  int hasBumpmapa; // [esp+10h] [ebp-8h]
  bool hasLightmap; // [esp+17h] [ebp-1h]

  v7 = surfID;
  v8 = (msurfacelighting_t *)((char *)host_state.worldbrush->surfacelighting
                            + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  v9 = ComputeLightmapSize(a1: v6, surfID);
  if ( v9 == 0 )
    return;
  hasBumpmap = SurfHasBumpedLightmaps(surfID);
  v10 = SurfHasLightmap(surfID);
  v11 = v10;
  hasLightmap = v10;
  if ( needsLightmap )
  {
    v12 = v10 ? 0 : LODWORD(mat_defaultlightmap.m_pParent->m_Value.m_fValue);
    if ( v9 > 0 )
    {
      v13 = dword_104F1D84;
      for ( i = v9; i != 0; --i )
      {
        v13[1] = v12;
        *v13 = v12;
        *(v13 - 1) = v12;
        v13[2] = 1065353216;
        v13 += 4;
      }
      v11 = v10;
    }
  }
  if ( needsBumpmap )
  {
    v15 = &flt_10531D84;
    do
    {
      v16 = hasBumpmap;
      if ( hasBumpmap )
        m_fValue = 0.0;
      else
        m_fValue = mat_defaultlightmap.m_pParent->m_Value.m_fValue;
      if ( v9 > 0 )
      {
        v18 = v15;
        for ( j = v9; j != 0; --j )
        {
          v18[1] = m_fValue;
          *v18 = m_fValue;
          *(v18 - 1) = m_fValue;
          v18[2] = 1.0;
          v18 += 4;
        }
        v11 = hasLightmap;
      }
      v15 += 0x10000;
    }
    while ( (int)v15 < (int)&r_avglightmap.m_pNext );
    v7 = surfID;
  }
  else
  {
    v16 = hasBumpmap;
  }
  if ( v11 && needsLightmap )
    goto LABEL_27;
  if ( !v16 )
  {
    if ( needsBumpmap )
    {
      if ( v11 )
      {
        ComputeLightmapFromLightstyle(
          pLighting: v8,
          computeLightmap: true,
          computeBumpmap: false,
          lightmapSize: v9,
          hasBumpmapLightmapData: false);
        hasBumpmapa = 0;
        v22 = dword_104F1D88;
        for ( k = 1; k != 0; --k )
        {
          v23 = 0;
          if ( v9 >= 4 )
          {
            v24 = ((unsigned int)(v9 - 4) >> 2) + 1;
            v25 = dword_104F1D88;
            v26 = v22;
            v23 = 4 * v24;
            do
            {
              v27 = *((float *)v25 - 2);
              v25 += 16;
              *((float *)v26 - 2) = v27;
              v26 += 16;
              --v24;
              *(v26 - 17) = *(v25 - 17);
              *(v26 - 16) = *(v25 - 16);
              *(v26 - 14) = *(v25 - 14);
              *(v26 - 13) = *(v25 - 13);
              *(v26 - 12) = *(v25 - 12);
              *(v26 - 10) = *(v25 - 10);
              *(v26 - 9) = *(v25 - 9);
              *(v26 - 8) = *(v25 - 8);
              *(v26 - 6) = *(v25 - 6);
              *(v26 - 5) = *(v25 - 5);
              *(v26 - 4) = *(v25 - 4);
            }
            while ( v24 != 0 );
          }
          if ( v23 < v9 )
          {
            v28 = &dword_104F1D88[4 * v23];
            v29 = &dword_104F1D88[4 * v23 + 4 * hasBumpmapa];
            v30 = v9 - v23;
            do
            {
              v31 = *((float *)v28 - 2);
              v28 += 4;
              *((float *)v29 - 2) = v31;
              v29 += 4;
              --v30;
              *(v29 - 5) = *(v28 - 5);
              *(v29 - 4) = *(v28 - 4);
            }
            while ( v30 != 0 );
          }
          hasBumpmapa += 0x4000;
          v22 += 0x10000;
        }
        v7 = surfID;
      }
      else if ( v9 > 0 )
      {
        v32 = &flt_10531D84;
        for ( m = v9; m != 0; --m )
        {
          v32[1] = 0.0;
          *v32 = 0.0;
          *(v32 - 1) = 0.0;
          v32[2] = 1.0;
          v32 += 4;
        }
        v34 = &flt_10571D84;
        for ( n = v9; n != 0; --n )
        {
          v34[1] = 0.0;
          *v34 = 0.0;
          *(v34 - 1) = 0.0;
          v34[2] = 1.0;
          v34 += 4;
        }
        v36 = dword_105B1D84;
        do
        {
          v36[1] = 0;
          *v36 = 0;
          *(v36 - 1) = 0;
          v36[2] = 1065353216;
          v36 += 4;
          --v9;
        }
        while ( v9 != 0 );
      }
    }
    goto LABEL_53;
  }
  if ( needsBumpmap )
  {
LABEL_27:
    v20 = v16 && needsBumpmap;
    v21 = v11 && needsLightmap;
    ComputeLightmapFromLightstyle(
      pLighting: v8,
      computeLightmap: v21,
      computeBumpmap: v20,
      lightmapSize: v9,
      hasBumpmapLightmapData: hasBumpmap);
  }
LABEL_53:
  if ( dlightMask != 0 && (needsLightmap || needsBumpmap) )
    R_AddDynamicLights(pLights, surfID: v7, entityToWorld, needsBumpmap, lightMask: dlightMask);
  UpdateLightmapTextures(surfID: v7, needsBumpmap);
}

//------------------------------------------------------------------------------
// Address: 0x100C64D0
// Name: public: virtual void CFunctor6<void (*)(struct dlight_t __near *,struct msurface2_t __near *,struct matrix3x4_t const __near &,unsigned int,bool,bool),struct dlight_t __near *,struct msurface2_t __near *,struct matrix3x4_t,unsigned int,bool,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor6<void (__cdecl *)(dlight_t *,msurface2_t *,matrix3x4_t const &,unsigned int,bool,bool),dlight_t *,msurface2_t *,matrix3x4_t,unsigned int,bool,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor6<void (__cdecl*)(dlight_t *,msurface2_t *,matrix3x4_t const &,unsigned int,bool,bool),dlight_t *,msurface2_t *,matrix3x4_t,int,bool,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  this->m_pfnProxied(
    a1: this->m_arg1,
    a2: this->m_arg2,
    a3: &this->m_arg3,
    a4: this->m_arg4,
    a5: this->m_arg5,
    a6: this->m_arg6);
}

//------------------------------------------------------------------------------
// Address: 0x100C6500
// Name: void R_BuildLightMap(struct dlight_t __near *,class ICallQueue __near *,struct msurface2_t __near *,struct matrix3x4_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_BuildLightMap(
        dlight_t *pLights,
        ICallQueue *pCallQueue,
        msurface2_t *surfID,
        const matrix3x4_t *entityToWorld,
        bool bOnlyUseLightStyles)
{
  bool v5; // al
  int lightmapPageID; // ecx
  CFunctor *v7; // eax
  const matrix3x4_t v8; // [esp+4h] [ebp-3Ch]
  bool needsLightmap; // [esp+34h] [ebp-Ch]
  bool needsBumpmap; // [esp+38h] [ebp-8h]
  bool bDlightsInLightmap; // [esp+3Ch] [ebp-4h]
  unsigned int bDlightsInLightmapa; // [esp+3Ch] [ebp-4h]

  needsBumpmap = SurfNeedsBumpedLightmaps(surfID);
  v5 = SurfNeedsLightmap(surfID);
  needsLightmap = v5;
  if ( (needsBumpmap || v5)
    && (materialSortInfoArray == nullptr
     || (lightmapPageID = materialSortInfoArray[surfID->materialSortID].lightmapPageID) != -1 && lightmapPageID != -2) )
  {
    if ( v5 || (bDlightsInLightmap = false, needsBumpmap) )
      bDlightsInLightmap = true;
    bDlightsInLightmapa = R_UpdateDlightState(
                            pLights,
                            surfID,
                            entityToWorld,
                            bOnlyUseLightStyles,
                            bLightmap: bDlightsInLightmap);
    if ( bOnlyUseLightStyles )
      bDlightsInLightmapa = 0;
    if ( pCallQueue != nullptr )
    {
      v8 = *entityToWorld;
      v7 = (CFunctor *)MemAlloc_Alloc(nSize: 0x54u);
      if ( v7 != nullptr )
      {
        v7[1].m_nUserID = 1;
        qmemcpy(&v7[3].m_nUserID, &v8, 48);
        v7[9].m_nUserID = bDlightsInLightmapa;
        v7[2].m_nUserID = (unsigned int)pLights;
        BYTE1(v7[10].__vftable) = needsLightmap;
        v7->__vftable = (CFunctor_vtbl *)&CFunctor6<void (__cdecl *)(dlight_t *,msurface2_t *,matrix3x4_t const &,unsigned int,bool,bool),dlight_t *,msurface2_t *,matrix3x4_t,unsigned int,bool,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
        v7[1].__vftable = (CFunctor_vtbl *)&CFunctor6<void (__cdecl *)(dlight_t *,msurface2_t *,matrix3x4_t const &,unsigned int,bool,bool),dlight_t *,msurface2_t *,matrix3x4_t,unsigned int,bool,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
        v7[2].__vftable = (CFunctor_vtbl *)R_BuildLightMapGuts;
        v7[3].__vftable = (CFunctor_vtbl *)surfID;
        LOBYTE(v7[10].__vftable) = needsBumpmap;
        pCallQueue->QueueFunctorInternal(this: pCallQueue, a2: v7);
      }
      else
      {
        pCallQueue->QueueFunctorInternal(this: pCallQueue, a2: nullptr);
      }
    }
    else
    {
      R_BuildLightMapGuts(pLights, surfID, entityToWorld, dlightMask: bDlightsInLightmapa, needsBumpmap, needsLightmap);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C6630
// Name: void DiscardStaticLightmapData(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DiscardStaticLightmapData()
{
  int v0; // ebx
  msurfacelighting_t *surfacelighting; // esi
  void *v2; // esp
  int v3; // esi
  int *m_pMemory; // edi
  ColorRGBExp32 *m_pSamples; // edx
  int v6; // ecx
  ColorRGBExp32 *v7; // eax
  worldbrushdata_t *v8; // eax
  ColorRGBExp32 *lightdata; // esi
  int v10; // edi
  msurface2_t *v11; // esi
  char *v12; // eax
  int v13; // ecx
  int v14; // eax
  IMaterial *material; // ecx
  const char *v16; // eax
  int j; // eax
  int v18; // ebx
  int v19; // ecx
  ColorRGBExp32 **p_m_pSamples; // esi
  int v21; // edi
  const __m128i *v22; // eax
  int v23; // ecx
  unsigned int v24; // esi
  const char *v25; // edi
  _BYTE v26[12]; // [esp+8h] [ebp-48h] BYREF
  CUtlSortVector<int,SurfaceLessFunc> surfaceSort; // [esp+14h] [ebp-3Ch] BYREF
  int numSurfaces; // [esp+30h] [ebp-20h]
  worldbrushdata_t *pBrushData; // [esp+34h] [ebp-1Ch]
  void *context; // [esp+38h] [ebp-18h] BYREF
  int i; // [esp+3Ch] [ebp-14h] BYREF
  msurfacelighting_t *pLighting; // [esp+40h] [ebp-10h]
  int offset; // [esp+44h] [ebp-Ch]
  double pTarget; // [esp+48h] [ebp-8h] BYREF

  if ( !g_bHunkAllocLightmaps )
  {
    v0 = host_state.worldbrush->numsurfaces;
    surfacelighting = host_state.worldbrush->surfacelighting;
    pBrushData = host_state.worldbrush;
    pLighting = surfacelighting;
    numSurfaces = v0;
    if ( v0 != 0 && host_state.worldbrush->m_pLightingDataStack != nullptr )
    {
      v2 = alloca(4 * v0);
      surfaceSort.m_pLessContext = surfacelighting;
      v3 = 0;
      m_pMemory = (int *)v26;
      surfaceSort.m_Memory.m_pMemory = (int *)v26;
      surfaceSort.m_Memory.m_nAllocationCount = v0;
      surfaceSort.m_Memory.m_nGrowSize = -1;
      surfaceSort.m_Size = 0;
      surfaceSort.m_pElements = (int *)v26;
      surfaceSort.m_bNeedsSort = false;
      i = 0;
      if ( v0 > 0 )
      {
        do
        {
          CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::InsertNoSort(
            this: (CUtlSortVector<CDmxAttribute *,CDmxAttributeLess> *)&surfaceSort,
            src: (CDmxAttribute **)&i);
          i = ++v3;
        }
        while ( v3 < v0 );
        if ( surfaceSort.m_bNeedsSort )
        {
          surfaceSort.m_bNeedsSort = false;
          if ( surfaceSort.m_Size > 1 )
          {
            context = surfaceSort.m_pLessContext;
            i = (int)&pTarget + 7;
            qsort_s(
              base: (char *)surfaceSort.m_Memory.m_pMemory,
              num: surfaceSort.m_Size,
              width: 4u,
              comp: (int (__cdecl *)(void *, const void *, const void *))CUtlSortVector<int,SurfaceLessFunc>::CompareHelper,
              &context);
          }
        }
        m_pMemory = surfaceSort.m_Memory.m_pMemory;
      }
      m_pSamples = pLighting[*m_pMemory].m_pSamples;
      v6 = 1;
      if ( v0 <= 1 )
      {
LABEL_16:
        v8 = pBrushData;
        lightdata = pBrushData->lightdata;
        LODWORD(pTarget) = lightdata;
        i = 0;
        if ( v0 > 0 )
        {
          while ( 1 )
          {
            v10 = m_pMemory[i];
            v11 = &host_state.worldbrush->surfaces2[v10];
            if ( SurfHasLightmap(surfID: v11) )
            {
              v12 = (char *)host_state.worldbrush->surfacelighting
                  + (((char *)v11 - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0);
              v13 = (*((__int16 *)v12 + 2) + 1) * (*((__int16 *)v12 + 3) + 1);
              v14 = (v11->flags & 0x800) != 0 ? 128 : 35;
              if ( v13 <= v14 * v14 )
              {
                offset = v13;
              }
              else
              {
                material = materialSortInfoArray[v11->materialSortID].material;
                v16 = (const char *)material->GetName(this: material);
                ConMsg(a1: "Bad lightmap extents on material \"%s\"\n", v16);
                offset = 0;
              }
              if ( SurfHasBumpedLightmaps(surfID: v11) )
                offset *= 4;
              for ( j = 0; j < 4; ++j )
              {
                if ( pLighting[v10].m_nStyles[j] == 0xFF )
                  break;
              }
              if ( j != 0 )
              {
                v18 = j;
                if ( j > 1 && (v11->flags & 0x400) != 0 )
                  v18 = j * (offset + 1);
                v19 = LODWORD(pTarget);
                p_m_pSamples = &pLighting[v10].m_pSamples;
                v21 = 4 * j;
                v22 = (const __m128i *)&(*p_m_pSamples)[-j];
                if ( v22 != (const __m128i *)LODWORD(pTarget) )
                {
                  memmove(dst: (__m128i *)LODWORD(pTarget), src: v22, count: 4 * v18);
                  v19 = LODWORD(pTarget);
                  *p_m_pSamples = (ColorRGBExp32 *)(LODWORD(pTarget) + v21);
                }
                v23 = v19 + 4 * v18;
                v0 = numSurfaces;
                LODWORD(pTarget) = v23;
              }
            }
            if ( ++i >= v0 )
              break;
            m_pMemory = surfaceSort.m_Memory.m_pMemory;
          }
          lightdata = (ColorRGBExp32 *)LODWORD(pTarget);
          v8 = pBrushData;
        }
        v24 = (char *)lightdata - (char *)v8->lightdata;
        CMemoryStack::FreeToAllocPoint(this: v8->m_pLightingDataStack, mark: v24, bDecommit: true);
        v25 = modelloader->GetName(this: modelloader, a2: host_state.worldmodel);
        _Msg(
          a1: "(%s) Original Full Lighting Data:           %.2f MB\n",
          v25,
          (double)pBrushData->m_nLightingDataSize * 0.00000095367432);
        numSurfaces = v24;
        _Msg(a1: "(%s) Reduced To Only Dynamic Lighting Data: %.2f MB\n", v25, (double)v24 * 0.00000095367432);
        if ( surfaceSort.m_Memory.m_nGrowSize >= 0 )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: surfaceSort.m_Memory.m_pMemory);
      }
      else
      {
        while ( 1 )
        {
          v7 = pLighting[m_pMemory[v6]].m_pSamples;
          if ( v7 != nullptr && m_pSamples != nullptr && v7 == m_pSamples )
          {
            DevMsg(a1: "DiscardStaticLightmapData: Surface Lighting data aliased.\n");
            CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&surfaceSort);
            return;
          }
          if ( v7 < m_pSamples )
            break;
          ++v6;
          m_pSamples = v7;
          if ( v6 >= v0 )
            goto LABEL_16;
        }
        DevMsg(a1: "DiscardStaticLightmapData: Surface Lighting data out of order.\n");
        if ( surfaceSort.m_Memory.m_nGrowSize >= 0 )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C6970
// Name: void R_BuildLightmapUpdateList(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_BuildLightmapUpdateList()
{
  IMatRenderContext *m_pObject; // esi
  ICallQueue *v1; // eax
  ICallQueue *v2; // edi
  int v3; // ecx
  const IClientRenderable **p_m_pExclusiveLightReceiver; // eax
  LightmapUpdateInfo_t *v5; // ebx
  CFunctor *v6; // eax
  dlight_t *v7; // ecx
  _BYTE v8[48]; // [esp+Ch] [ebp-44h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+3Ch] [ebp-14h]
  int i; // [esp+40h] [ebp-10h]
  ICallQueue *pCallQueue; // [esp+44h] [ebp-Ch]
  unsigned int v12; // [esp+48h] [ebp-8h]
  dlight_t *pLights; // [esp+4Ch] [ebp-4h]

  m_pObject = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  v1 = m_pObject->GetCallQueue(this: m_pObject);
  v2 = v1;
  pCallQueue = v1;
  pLights = cl_dlights;
  if ( g_bActiveDlights && v1 != nullptr )
  {
    if ( (_S1_6 & 1) == 0 )
    {
      _S1_6 |= 1u;
      v3 = 63;
      p_m_pExclusiveLightReceiver = &threadDlights[0].m_pExclusiveLightReceiver;
      do
      {
        *p_m_pExclusiveLightReceiver = nullptr;
        p_m_pExclusiveLightReceiver += 17;
        --v3;
      }
      while ( v3 >= 0 );
    }
    pLights = &threadDlights[32 * threadFrameCount];
    _V_memcpy(dest: pLights, src: cl_dlights, count: 2176);
    threadFrameCount = ((_BYTE)threadFrameCount - 1) & 1;
  }
  qsort(
    base: g_LightmapUpdateList.m_Memory.m_pMemory,
    num: g_LightmapUpdateList.m_Size,
    width: 0xCu,
    comp: LightmapPageCompareFunc);
  i = 0;
  if ( g_LightmapUpdateList.m_Size > 0 )
  {
    v12 = 0;
    do
    {
      v5 = &g_LightmapUpdateList.m_Memory.m_pMemory[v12 / 0xC];
      if ( v2 != nullptr )
      {
        qmemcpy(v8, &g_LightmapTransformList.m_Memory.m_pMemory[v5->m_nTransformIndex].xform, sizeof(v8));
        v6 = (CFunctor *)MemAlloc_Alloc(nSize: 0x54u);
        if ( v6 != nullptr )
        {
          v7 = pLights;
          v6[1].m_nUserID = 1;
          v6[2].m_nUserID = (unsigned int)v7;
          v6->__vftable = (CFunctor_vtbl *)&CFunctor6<void (__cdecl *)(dlight_t *,msurface2_t *,matrix3x4_t const &,unsigned int,bool,bool),dlight_t *,msurface2_t *,matrix3x4_t,int,bool,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
          v6[1].__vftable = (CFunctor_vtbl *)&CFunctor6<void (__cdecl *)(dlight_t *,msurface2_t *,matrix3x4_t const &,unsigned int,bool,bool),dlight_t *,msurface2_t *,matrix3x4_t,int,bool,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
          v6[2].__vftable = (CFunctor_vtbl *)R_BuildLightMapGuts;
          v6[3].__vftable = (CFunctor_vtbl *)v5->m_SurfHandle;
          qmemcpy(&v6[3].m_nUserID, v8, 48);
          v6[9].m_nUserID = v5->m_nDlightMask;
          LOBYTE(v6[10].__vftable) = v5->m_bNeedsBumpmap;
          BYTE1(v6[10].__vftable) = v5->m_bNeedsLightmap;
        }
        else
        {
          v6 = nullptr;
        }
        pCallQueue->QueueFunctorInternal(this: pCallQueue, a2: v6);
        v2 = pCallQueue;
        m_pObject = pRenderContext.m_pObject;
      }
      else
      {
        R_BuildLightMapGuts(
          pLights,
          surfID: v5->m_SurfHandle,
          entityToWorld: &g_LightmapTransformList.m_Memory.m_pMemory[v5->m_nTransformIndex].xform,
          dlightMask: v5->m_nDlightMask,
          needsBumpmap: v5->m_bNeedsBumpmap,
          needsLightmap: v5->m_bNeedsLightmap);
      }
      v12 += 12;
      ++i;
    }
    while ( i < g_LightmapUpdateList.m_Size );
  }
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x100C6B50
// Name: void R_CheckForLightmapUpdates(struct msurface2_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_CheckForLightmapUpdates(msurface2_t *surfID, int nTransformIndex)
{
  _DWORD *v2; // eax
  int v3; // ebx
  _BYTE *v4; // ecx
  bool v5; // cl
  bool v6; // bl
  bool v7; // al
  int lightmapPageID; // ecx
  int updated; // edi
  int v10; // eax
  bool bOnlyUseLightStyles; // [esp+Bh] [ebp-9h]
  bool bDlightsInLightmap; // [esp+Fh] [ebp-5h]
  char bNeedsLightmap; // [esp+13h] [ebp-1h]
  bool bNeedsLightmapa; // [esp+13h] [ebp-1h]

  v2 = (_DWORD *)((char *)host_state.worldbrush->surfacelighting->m_LightmapMins
                + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
  v3 = v2[3];
  if ( v3 != r_framecount && (surfID->flags & 1) == 0 )
  {
    bNeedsLightmap = 0;
    if ( (surfID->flags & 0x400) != 0 )
    {
      v4 = v2 + 6;
      while ( *v4 != 0xFF )
      {
        if ( d_lightstyleframe[(unsigned __int8)*v4] > v3 )
        {
          bNeedsLightmap = 1;
          break;
        }
        ++v4;
        if ( (int)&v4[-24 - (_DWORD)v2] >= 4 )
          break;
      }
    }
    v5 = v2[5] == r_framecount || v2[4] != 0;
    bOnlyUseLightStyles = false;
    if ( r_dynamic.m_pParent == nullptr
      || r_dynamic.m_pParent->m_Value.m_nValue == 0
      || r_keepstyledlightmapsonly.m_pParent != nullptr && r_keepstyledlightmapsonly.m_pParent->m_Value.m_nValue != 0 )
    {
      bOnlyUseLightStyles = true;
    }
    else
    {
      bNeedsLightmap |= v5;
    }
    if ( bNeedsLightmap != 0 )
    {
      v6 = SurfNeedsBumpedLightmaps(surfID);
      v7 = SurfNeedsLightmap(surfID);
      bNeedsLightmapa = v7;
      if ( (v6 || v7)
        && (materialSortInfoArray == nullptr
         || (lightmapPageID = materialSortInfoArray[surfID->materialSortID].lightmapPageID) != -1
         && lightmapPageID != -2) )
      {
        if ( v7 || (bDlightsInLightmap = false, v6) )
          bDlightsInLightmap = true;
        updated = R_UpdateDlightState(
                    pLights: cl_dlights,
                    surfID,
                    entityToWorld: &g_LightmapTransformList.m_Memory.m_pMemory[nTransformIndex].xform,
                    bOnlyUseLightStyles,
                    bLightmap: bDlightsInLightmap);
        v10 = CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::AddToTail(this: (CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int> > *)&g_LightmapUpdateList);
        g_LightmapUpdateList.m_Memory.m_pMemory[v10].m_SurfHandle = surfID;
        g_LightmapUpdateList.m_Memory.m_pMemory[v10].m_nTransformIndex = nTransformIndex;
        g_LightmapUpdateList.m_Memory.m_pMemory[v10].m_nDlightMask = updated;
        g_LightmapUpdateList.m_Memory.m_pMemory[v10].m_bNeedsLightmap = bNeedsLightmapa;
        g_LightmapUpdateList.m_Memory.m_pMemory[v10].m_bNeedsBumpmap = v6;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C6CE0
// Name: void R_RedownloadAllLightmaps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall R_RedownloadAllLightmaps(void *this)
{
  int v1; // ecx
  IMatRenderContext *v2; // eax
  IMatRenderContext *v3; // esi
  ICallQueue *v4; // eax
  int numsurfaces; // esi
  ICallQueue *v6; // edi
  void *v7; // esp
  int v8; // eax
  int v9; // ecx
  IMaterialSystem *v10; // edi
  CFunctor *v11; // eax
  ICallQueue *v12; // ecx
  int i; // edi
  ICallQueue *v14; // edi
  IMaterialSystem *v15; // esi
  CFunctor *v16; // eax
  CFunctor *v17; // eax
  IMatRenderContext *m_pObject; // esi
  double v19; // st7
  msurface2_t *v20[3]; // [esp+Ch] [ebp-50h] BYREF
  matrix3x4_t xform; // [esp+18h] [ebp-44h] BYREF
  double st; // [esp+48h] [ebp-14h]
  CMatRenderContextPtr pRenderContext; // [esp+50h] [ebp-Ch]
  BOOL bOnlyUseLightStyles; // [esp+54h] [ebp-8h]
  ICallQueue *pCallQueue; // [esp+58h] [ebp-4h]

  st = _Plat_FloatTime(a1: this);
  if ( !host_state.worldbrush->m_bUnloadedAllLightmaps )
  {
    LOBYTE(bOnlyUseLightStyles) = 0;
    if ( r_dynamic.m_pParent == nullptr
      || r_dynamic.m_pParent->m_Value.m_nValue == 0
      || r_keepstyledlightmapsonly.m_pParent != nullptr && r_keepstyledlightmapsonly.m_pParent->m_Value.m_nValue != 0 )
    {
      LOBYTE(bOnlyUseLightStyles) = 1;
    }
    v2 = materials->GetRenderContext(this: materials);
    v3 = v2;
    pRenderContext.m_pObject = v2;
    if ( v2 != nullptr )
      v2->BeginRender(this: v2);
    v4 = v3->GetCallQueue(this: v3);
    numsurfaces = host_state.worldbrush->numsurfaces;
    v6 = v4;
    pCallQueue = v4;
    v7 = alloca(4 * numsurfaces);
    v8 = 0;
    if ( numsurfaces > 0 )
    {
      v9 = 0;
      do
        v20[v8++] = &host_state.worldbrush->surfaces2[v9++];
      while ( v8 < numsurfaces );
    }
    SortSurfacesByLightmapID(pToSort: v20, iSurfaceCount: numsurfaces);
    if ( v6 != nullptr )
    {
      v10 = materials;
      v11 = (CFunctor *)MemAlloc_Alloc(nSize: 0x18u);
      if ( v11 != nullptr )
      {
        v12 = pCallQueue;
        v11[1].m_nUserID = 1;
        v11->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<IMaterialSystem *,void (__thiscall IMaterialSystem::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
        v11[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<IMaterialSystem *,void (__thiscall IMaterialSystem::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
        v11[2].__vftable = (CFunctor_vtbl *) __thiscall IMaterialSystem::`vcall'{448,{flat}};
        v11[2].m_nUserID = (unsigned int)v10;
        v12->QueueFunctorInternal(this: v12, a2: v11);
      }
      else
      {
        pCallQueue->QueueFunctorInternal(this: pCallQueue, a2: nullptr);
      }
    }
    else
    {
      materials->BeginUpdateLightmaps(this: materials);
    }
    SetIdentityMatrix(matrix: &xform);
    for ( i = 0; i < numsurfaces; ++i )
      R_BuildLightMap(pLights: cl_dlights, pCallQueue, surfID: v20[i], entityToWorld: &xform, bOnlyUseLightStyles);
    v14 = pCallQueue;
    if ( pCallQueue != nullptr )
    {
      v15 = materials;
      v16 = (CFunctor *)MemAlloc_Alloc(nSize: 0x18u);
      if ( v16 != nullptr )
      {
        v16[1].m_nUserID = 1;
        v16->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<IMaterialSystem *,void (__thiscall IMaterialSystem::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
        v16[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<IMaterialSystem *,void (__thiscall IMaterialSystem::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
        v16[2].__vftable = (CFunctor_vtbl *) __thiscall IMaterialSystem::`vcall'{452,{flat}};
        v16[2].m_nUserID = (unsigned int)v15;
        v14->QueueFunctorInternal(this: v14, a2: v16);
      }
      else
      {
        v14->QueueFunctorInternal(this: v14, a2: nullptr);
      }
    }
    else
    {
      materials->EndUpdateLightmaps(this: materials);
    }
    if ( g_bHunkAllocLightmaps )
      goto LABEL_39;
    if ( r_unloadlightmaps.m_pParent != nullptr && r_unloadlightmaps.m_pParent->m_Value.m_nValue == 1 )
    {
      if ( v14 == nullptr )
      {
        CacheAndUnloadLightmapData();
LABEL_39:
        m_pObject = pRenderContext.m_pObject;
        pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
        m_pObject->Release(this: m_pObject);
        goto LABEL_40;
      }
      v17 = (CFunctor *)MemAlloc_Alloc(nSize: 0x14u);
      if ( v17 != nullptr )
      {
        v17[1].m_nUserID = 1;
        v17->__vftable = (CFunctor_vtbl *)&CFunctor0<void (__cdecl *)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
        v17[1].__vftable = (CFunctor_vtbl *)&CFunctor0<void (__cdecl *)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
        v17[2].__vftable = (CFunctor_vtbl *)CacheAndUnloadLightmapData;
LABEL_38:
        v14->QueueFunctorInternal(this: v14, a2: v17);
        goto LABEL_39;
      }
    }
    else
    {
      if ( r_keepstyledlightmapsonly.m_pParent == nullptr || r_keepstyledlightmapsonly.m_pParent->m_Value.m_nValue == 0 )
        goto LABEL_39;
      if ( v14 == nullptr )
      {
        DiscardStaticLightmapData();
        goto LABEL_39;
      }
      v17 = (CFunctor *)MemAlloc_Alloc(nSize: 0x14u);
      if ( v17 != nullptr )
      {
        v17[1].m_nUserID = 1;
        v17->__vftable = (CFunctor_vtbl *)&CFunctor0<void (__cdecl *)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
        v17[1].__vftable = (CFunctor_vtbl *)&CFunctor0<void (__cdecl *)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
        v17[2].__vftable = (CFunctor_vtbl *)DiscardStaticLightmapData;
        goto LABEL_38;
      }
    }
    v17 = nullptr;
    goto LABEL_38;
  }
LABEL_40:
  v19 = _Plat_FloatTime(a1: v1);
  DevMsg(a1: "R_RedownloadAllLightmaps took %.3f msec!\n", (v19 - st) * 1000.0);
  g_RebuildLightmaps = false;
}

//------------------------------------------------------------------------------
// Address: 0x1027B870
// Name: public: virtual void CFunctor6<void (*)(class Vector const __near &,float,int,int,class Color,bool),class Vector,float,int,int,class Color,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor6<void (__cdecl *)(Vector const &,float,int,int,Color,bool),Vector,float,int,int,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor6<void (__cdecl*)(Vector const &,float,int,int,Color,bool),Vector,float,int,int,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  ((void (__cdecl *)(Vector *, _DWORD, int, int, _DWORD, bool))this->m_pfnProxied)(
    a1: &this->m_arg1,
    a2: LODWORD(this->m_arg2),
    a3: this->m_arg3,
    a4: this->m_arg4,
    a5: *(_DWORD *)&this->m_arg5,
    a6: this->m_arg6);
}

//------------------------------------------------------------------------------
// Address: 0x1027B8D0
// Name: public: virtual void CFunctor6<void (*)(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class Color,bool),class Vector,class QAngle,class Vector,class Vector,class Color,bool,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor6<void (__cdecl *)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,bool),Vector,QAngle,Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor6<void (__cdecl*)(Vector const &,QAngle const &,Vector const &,Vector const &,Color,bool),Vector,QAngle,Vector,Vector,Color,bool,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  ((void (__cdecl *)(Vector *, QAngle *, Vector *, Vector *, _DWORD, bool))this->m_pfnProxied)(
    a1: &this->m_arg1,
    a2: &this->m_arg2,
    a3: &this->m_arg3,
    a4: &this->m_arg4,
    a5: *(_DWORD *)&this->m_arg5,
    a6: this->m_arg6);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1031B190
// Name: _dynamic_initializer_for__light_crosshair__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__light_crosshair__()
{
  ConCommand::ConCommand(
    this: &light_crosshair,
    pName: "light_crosshair",
    callback: Host_LightCrosshair,
    pHelpString: "Show texture color at crosshair",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__light_crosshair__);
}

//------------------------------------------------------------------------------
// Address: 0x103259F0
// Name: _dynamic_atexit_destructor_for__light_crosshair__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__light_crosshair__()
{
  ConCommand::~ConCommand(this: &light_crosshair);
}

//------------------------------------------------------------------------------
// Address: 0x1031B1C0
// Name: _dynamic_initializer_for__status_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__status_command__()
{
  ConCommand::ConCommand(
    this: &status_command,
    pName: "status",
    callback: status,
    pHelpString: "Display map and connection status.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__status_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B1F0
// Name: _dynamic_initializer_for__ping_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ping_command__()
{
  ConCommand::ConCommand(
    this: &ping_command,
    pName: "ping",
    callback: ping,
    pHelpString: "Display ping to server.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ping_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B220
// Name: _dynamic_initializer_for__map_edit_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__map_edit_command__()
{
  ConCommand::ConCommand(
    this: &map_edit_command,
    pName: "map_edit",
    callback: map_edit,
    pHelpString: defaultValue,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__map_edit_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B250
// Name: _dynamic_initializer_for__restart_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__restart_command__()
{
  ConCommand::ConCommand(
    this: &restart_command,
    pName: "restart",
    callback: restart,
    pHelpString: "Restart the game on the same level (add setpos to jump to current view position on restart).",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__restart_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B280
// Name: _dynamic_initializer_for__reload_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__reload_command__()
{
  ConCommand::ConCommand(
    this: &reload_command,
    pName: "reload",
    callback: reload,
    pHelpString: "Reload the most recent saved game (add setpos to jump to current view position on reload).",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__reload_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B2B0
// Name: _dynamic_initializer_for__disconnect_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__disconnect_command__()
{
  ConCommand::ConCommand(
    this: &disconnect_command,
    pName: "disconnect",
    callback: disconnect,
    pHelpString: "Disconnect game from server.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__disconnect_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10325A00
// Name: _dynamic_atexit_destructor_for__status_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__status_command__()
{
  ConCommand::~ConCommand(this: &status_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325A10
// Name: _dynamic_atexit_destructor_for__ping_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ping_command__()
{
  ConCommand::~ConCommand(this: &ping_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325A20
// Name: _dynamic_atexit_destructor_for__map_edit_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__map_edit_command__()
{
  ConCommand::~ConCommand(this: &map_edit_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325A30
// Name: _dynamic_atexit_destructor_for__restart_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__restart_command__()
{
  ConCommand::~ConCommand(this: &restart_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325A40
// Name: _dynamic_atexit_destructor_for__reload_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__reload_command__()
{
  ConCommand::~ConCommand(this: &reload_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325A50
// Name: _dynamic_atexit_destructor_for__disconnect_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__disconnect_command__()
{
  ConCommand::~ConCommand(this: &disconnect_command);
}

} // namespace engine_xlsp
