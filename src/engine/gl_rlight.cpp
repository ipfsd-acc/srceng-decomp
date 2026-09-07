// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/gl_rlight.cpp
// Functions: 19
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100C9B20
// Name: void R_AnimateLight(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_AnimateLight()
{
  INetworkStringTable *m_pLightStyleTable; // ebx
  CClientState *BaseLocalClient; // eax
  int j; // esi
  _BYTE *v3; // eax
  int v4; // edi
  int v5; // eax
  int i; // [esp+4h] [ebp-8h]
  int length; // [esp+8h] [ebp-4h] BYREF

  m_pLightStyleTable = GetBaseLocalClient()->m_pLightStyleTable;
  if ( m_pLightStyleTable != nullptr )
  {
    BaseLocalClient = GetBaseLocalClient();
    i = (int)(CClientState::GetTime(this: BaseLocalClient) * 10.0);
    for ( j = 0; j < 64; ++j )
    {
      v3 = m_pLightStyleTable->GetStringUserData(this: m_pLightStyleTable, a2: j, a3: &length);
      v4 = --length;
      if ( v3 != nullptr && *v3 != 0 )
      {
        d_lightstylenumframes[j] = v4;
        v5 = 22 * ((char)v3[i % v4] - 97);
        if ( d_lightstylevalue[j] != v5 )
        {
          d_lightstylevalue[j] = v5;
          d_lightstyleframe[j] = r_framecount;
        }
      }
      else
      {
        d_lightstylevalue[j] = 256;
        d_lightstylenumframes[j] = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C9BD0
// Name: ComputeLightmapCoordsAtIntersection
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeLightmapCoordsAtIntersection(
        msurfacelighting_t *pLighting@<edx>,
        float *lightmapS@<ecx>,
        float *lightmapT@<esi>,
        float a4@<xmm1>,
        float dt)
{
  __int16 v6; // ax
  __int16 v7; // ax

  if ( lightmapS != nullptr && lightmapT != nullptr )
  {
    v6 = pLighting->m_LightmapExtents[0];
    if ( v6 != 0 )
      *lightmapS = (float)(a4 + 0.5) / (float)v6;
    else
      *lightmapS = 0.5;
    v7 = pLighting->m_LightmapExtents[1];
    if ( v7 != 0 )
      *lightmapT = (float)(dt + 0.5) / (float)v7;
    else
      *lightmapT = 0.5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C9C40
// Name: void R_LightVecUseModel(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_LightVecUseModel(model_t *pModel)
{
  s_pLightVecModel = pModel;
}

//------------------------------------------------------------------------------
// Address: 0x100C9C50
// Name: int R_TryLightMarkSurface(struct dlight_t __near *,struct msurfacelighting_t __near *,struct msurface2_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl R_TryLightMarkSurface(dlight_t *light, msurfacelighting_t *pLighting, msurface2_t *surfID, dlight_t *bit)
{
  float x; // xmm3_4
  float y; // xmm2_4
  float z; // xmm4_4
  float v7; // xmm0_4
  float v9; // xmm1_4
  int v10; // edx
  float *v11; // eax
  int v12; // ecx
  float v13; // xmm5_4
  int v14; // ecx
  int v15; // edx
  float v16; // [esp+0h] [ebp-24h]
  Vector2D radius; // [esp+Ch] [ebp-18h] BYREF
  Vector2D boxMax; // [esp+14h] [ebp-10h] BYREF
  Vector2D center; // [esp+1Ch] [ebp-8h] BYREF

  x = light->origin.x;
  y = light->origin.y;
  z = light->origin.z;
  v7 = (float)((float)((float)(surfID->plane->normal.y * y) + (float)(x * surfID->plane->normal.x))
             + (float)(surfID->plane->normal.z * z))
     - surfID->plane->dist;
  if ( v7 < -15.0 )
    return 0;
  v9 = (float)(light->radius * light->radius) - (float)(v7 * v7);
  if ( v9 <= 0.0 )
    return 0;
  v10 = pLighting->m_LightmapExtents[0];
  v11 = (float *)&host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1];
  v12 = pLighting->m_LightmapMins[1];
  radius.x = (float)pLighting->m_LightmapMins[0];
  v13 = (float)v12;
  v14 = pLighting->m_LightmapExtents[1];
  radius.y = v13;
  boxMax.y = (float)v14 + v13;
  boxMax.x = (float)v10 + radius.x;
  center.x = (float)((float)((float)(v11[9] * y) + (float)(v11[8] * x)) + (float)(v11[10] * z)) + v11[11];
  center.y = (float)((float)((float)(v11[13] * y) + (float)(v11[12] * x)) + (float)(v11[14] * z)) + v11[15];
  v16 = sqrt((float)((float)(v11[16] * v9) * v11[16]));
  if ( !IsCircleIntersectingRectangle(boxMin: &radius, &boxMax, &center, radius: v16) )
    return 0;
  v15 = r_framecount;
  pLighting->m_fDLightBits |= (unsigned int)bit;
  pLighting->m_nDLightFrame = v15;
  surfID->flags |= 0x80000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C9DE0
// Name: int R_MarkLightsLeaf(struct dlight_t __near *,int,struct mleaf_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl R_MarkLightsLeaf(dlight_t *light, dlight_t *bit, mleaf_t *pLeaf)
{
  mleaf_t *v3; // eax
  int v4; // ebx
  bool v5; // cf
  worldbrushdata_t *worldbrush; // ecx
  IDispInfo *v7; // eax
  int v8; // eax
  _DWORD *v9; // edi
  char *v10; // esi
  int v11; // edx
  int v12; // ebx
  msurface2_t *v13; // edx
  msurfacelighting_t *v14; // eax
  float v15; // xmm0_4
  float radius; // xmm1_4
  int v17; // eax
  Vector boxMin; // [esp+10h] [ebp-20h] BYREF
  Vector bmin; // [esp+1Ch] [ebp-14h] BYREF
  Vector bmax; // [esp+28h] [ebp-8h]

  v3 = pLeaf;
  v4 = 0;
  v5 = pLeaf->dispCount != 0;
  worldbrush = host_state.worldbrush;
  bmax.y = 0.0;
  if ( v5 )
  {
    do
    {
      v7 = DispInfo_IndexArray(
             hArray: (_DWORD *)worldbrush->hDispInfos,
             iElement: worldbrush->m_pDispInfoReferences[v4 + v3->dispListStart]);
      v8 = (int)v7->GetParent(this: v7);
      v9 = (_DWORD *)v8;
      if ( v8 != 0 )
      {
        worldbrush = host_state.worldbrush;
        v10 = (char *)host_state.worldbrush->surfacelighting
            + ((v8 - (unsigned int)host_state.worldbrush->surfaces2) & 0xFFFFFFE0);
        if ( *((_DWORD *)v10 + 5) == r_framecount && ((unsigned int)bit & *((_DWORD *)v10 + 4)) != 0 )
          goto LABEL_8;
        (*(void (__thiscall **)(_DWORD, Vector *, Vector *))(**(_DWORD **)(v8 + 24) + 12))(
          a1: *(_DWORD *)(v8 + 24),
          a2: &boxMin,
          a3: &bmin);
        if ( IsBoxIntersectingSphere(&boxMin, boxMax: &bmin, center: &light->origin, radius: light->radius) )
        {
          v11 = r_framecount;
          *((_DWORD *)v10 + 4) |= (unsigned int)bit;
          *((_DWORD *)v10 + 5) = v11;
          *v9 |= 0x80000u;
          ++LODWORD(bmax.y);
        }
      }
      worldbrush = host_state.worldbrush;
LABEL_8:
      v3 = pLeaf;
      ++v4;
    }
    while ( v4 < pLeaf->dispCount );
  }
  LODWORD(bmax.x) = &worldbrush->marksurfaces[v3->firstmarksurface];
  v12 = 0;
  if ( v3->nummarksurfaces != 0 )
  {
    do
    {
      v13 = *(msurface2_t **)(LODWORD(bmax.x) + 4 * v12);
      if ( (v13->flags & 2) == 0 )
      {
        v14 = (msurfacelighting_t *)((char *)worldbrush->surfacelighting
                                   + (((char *)v13 - (char *)worldbrush->surfaces2) & 0xFFFFFFE0));
        if ( v14->m_nDLightFrame != r_framecount || ((unsigned int)bit & v14->m_fDLightBits) == 0 )
        {
          v15 = (float)((float)((float)(light->origin.y * v13->plane->normal.y)
                              + (float)(v13->plane->normal.x * light->origin.x))
                      + (float)(light->origin.z * v13->plane->normal.z))
              - v13->plane->dist;
          radius = light->radius;
          if ( v15 <= radius && COERCE_FLOAT(LODWORD(radius) ^ _mask__NegFloat_) <= v15 )
          {
            v17 = R_TryLightMarkSurface(light, pLighting: v14, surfID: v13, bit);
            worldbrush = host_state.worldbrush;
            LODWORD(bmax.y) += v17;
          }
        }
      }
      ++v12;
    }
    while ( v12 < pLeaf->nummarksurfaces );
  }
  return LODWORD(bmax.y);
}

//------------------------------------------------------------------------------
// Address: 0x100C9F80
// Name: int R_MarkLights(struct dlight_t __near *,int,struct mnode_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl R_MarkLights(dlight_t *light, int bit, mnode_t *node)
{
  mnode_t *v3; // edi
  int v4; // ebx
  dlight_t *v5; // edx
  float radius; // xmm1_4
  float v7; // xmm0_4
  worldbrushdata_t *worldbrush; // ecx
  msurface2_t *v10; // esi
  msurfacelighting_t *v11; // eax
  int v12; // eax
  int v13; // ebx
  int i; // [esp+18h] [ebp+10h]

  v3 = node;
  v4 = 0;
  if ( node->contents >= 0 )
    return R_MarkLightsLeaf(light, (dlight_t *)bit, pLeaf: (mleaf_t *)v3);
  v5 = light;
  radius = light->radius;
  while ( 1 )
  {
    v7 = (float)((float)((float)(v3->plane->normal.y * light->origin.y) + (float)(v3->plane->normal.x * light->origin.x))
               + (float)(v3->plane->normal.z * light->origin.z))
       - v3->plane->dist;
    if ( v7 <= radius )
      break;
    v3 = v3->children[0];
LABEL_7:
    if ( v3->contents >= 0 )
      return R_MarkLightsLeaf(light, (dlight_t *)bit, pLeaf: (mleaf_t *)v3);
  }
  if ( (float)-radius > v7 )
  {
    v3 = v3->children[1];
    goto LABEL_7;
  }
  worldbrush = host_state.worldbrush;
  v10 = &host_state.worldbrush->surfaces2[v3->firstsurface];
  i = 0;
  if ( v3->numsurfaces != 0 )
  {
    do
    {
      v11 = (msurfacelighting_t *)((char *)worldbrush->surfacelighting
                                 + (((char *)v10 - (char *)worldbrush->surfaces2) & 0xFFFFFFE0));
      if ( v11->m_nDLightFrame != r_framecount || (bit & v11->m_fDLightBits) == 0 )
      {
        v12 = R_TryLightMarkSurface(light, pLighting: v11, surfID: v10, (dlight_t *)bit);
        worldbrush = host_state.worldbrush;
        v4 += v12;
      }
      ++i;
      ++v10;
    }
    while ( i < v3->numsurfaces );
    v5 = light;
  }
  v13 = R_MarkLights(light: v5, bit, node: v3->children[0]) + v4;
  return v13 + R_MarkLights(light, bit, node: v3->children[1]);
}

//------------------------------------------------------------------------------
// Address: 0x100CA0A0
// Name: void R_MarkDLightsOnSurface(struct mnode_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_MarkDLightsOnSurface(mnode_t *pNode)
{
  int v1; // edi
  dlight_t *v2; // esi
  int i; // ebx
  CClientState *BaseLocalClient; // eax

  if ( pNode != nullptr && g_bActiveDlights )
  {
    v1 = 1;
    v2 = cl_dlights;
    for ( i = 32; i != 0; --i )
    {
      BaseLocalClient = GetBaseLocalClient();
      if ( CClientState::GetTime(this: BaseLocalClient) <= v2->die
        && (float)(v2->radius > 0.0) != 0.0
        && (v2->flags & 1) == 0 )
      {
        R_MarkLights(light: v2, bit: v1, node: pNode);
      }
      v1 = __ROL4__(v1, 1);
      ++v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CA120
// Name: void R_PushDlights(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_PushDlights()
{
  R_MarkDLightsOnSurface(pNode: host_state.worldbrush->nodes);
  MarkDLightsOnStaticProps();
}

//------------------------------------------------------------------------------
// Address: 0x100CA140
// Name: ComputeTextureCoordsAtIntersection
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeTextureCoordsAtIntersection(
        mtexinfo_t *pTex@<esi>,
        const Vector *pt@<eax>,
        float *textureT@<edi>,
        float *textureS)
{
  if ( pTex->material != nullptr && textureS != nullptr && textureT != nullptr )
  {
    *textureS = (float)((float)((float)(pTex->textureVecsTexelsPerWorldUnits[0].y * pt->y)
                              + (float)(pTex->textureVecsTexelsPerWorldUnits[0].x * pt->x))
                      + (float)(pTex->textureVecsTexelsPerWorldUnits[0].z * pt->z))
              + pTex->textureVecsTexelsPerWorldUnits[0].w;
    *textureT = (float)((float)((float)(pTex->textureVecsTexelsPerWorldUnits[1].y * pt->y)
                              + (float)(pTex->textureVecsTexelsPerWorldUnits[1].x * pt->x))
                      + (float)(pTex->textureVecsTexelsPerWorldUnits[1].z * pt->z))
              + pTex->textureVecsTexelsPerWorldUnits[1].w;
    *textureS = *textureS / (float)pTex->material->GetMappingWidth(this: pTex->material);
    *textureT = *textureT / (float)pTex->material->GetMappingHeight(this: pTex->material);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CA200
// Name: ComputeLightmapColor
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeLightmapColor(msurface2_t *surfID@<ecx>, Vector *c@<esi>, int ds, int dt, bool bUseLightStyles)
{
  char *v5; // edi
  int v6; // ebx
  ColorRGBExp32 *v7; // eax
  int v8; // edx
  int v9; // ecx
  unsigned __int8 v10; // dl
  float v11; // xmm0_4
  float v12; // xmm2_4
  unsigned __int8 *v13; // eax
  unsigned __int8 v14; // dl
  float v15; // xmm0_4
  float v16; // xmm2_4
  unsigned __int8 *v17; // eax
  unsigned __int8 v18; // dl
  float v19; // xmm0_4
  float v20; // xmm2_4
  unsigned __int8 *v21; // eax
  unsigned __int8 v22; // dl
  float v23; // xmm0_4
  float v24; // xmm2_4
  char *v25; // ecx
  float v26; // xmm0_4
  float v27; // xmm2_4
  ColorRGBExp32 *pLightmap; // [esp+4h] [ebp-8h]
  ColorRGBExp32 *pLightmapa; // [esp+4h] [ebp-8h]
  int offset; // [esp+8h] [ebp-4h]

  v5 = (char *)host_state.worldbrush->surfacelighting
     + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0);
  pLightmap = *((ColorRGBExp32 **)v5 + 7);
  if ( pLightmap != nullptr )
  {
    v6 = *((__int16 *)v5 + 2) + 1;
    offset = v6 * (*((__int16 *)v5 + 3) + 1);
    if ( SurfHasBumpedLightmaps(surfID) )
      offset *= 4;
    v7 = &pLightmap[ds + dt * v6];
    v8 = bUseLightStyles ? 4 : 1;
    v9 = 0;
    pLightmapa = (ColorRGBExp32 *)v8;
    if ( (unsigned int)v8 < 4 )
    {
LABEL_12:
      if ( v9 < v8 )
      {
        v25 = &v5[v9 + 24];
        do
        {
          if ( *v25 == -1 )
            break;
          v26 = (float)d_lightstylevalue[(unsigned __int8)*v25] * 0.0037878789;
          c->x = (float)((float)((float)v7->r * dword_10425B80[v7->exponent]) * v26) + c->x;
          c->y = (float)((float)((float)v7->g * dword_10425B80[v7->exponent]) * v26) + c->y;
          v27 = (float)v7->b * dword_10425B80[v7->exponent];
          v7 += offset;
          ++v25;
          c->z = (float)(v27 * v26) + c->z;
        }
        while ( (int)&v25[-24 - (_DWORD)v5] < v8 );
      }
    }
    else
    {
      while ( 1 )
      {
        v10 = v5[v9 + 24];
        if ( v10 == 0xFF )
          break;
        v11 = (float)d_lightstylevalue[v10] * 0.0037878789;
        c->x = (float)((float)((float)v7->r * dword_10425B80[v7->exponent]) * v11) + c->x;
        c->y = (float)((float)((float)v7->g * dword_10425B80[v7->exponent]) * v11) + c->y;
        v12 = (float)((float)((float)v7->b * dword_10425B80[v7->exponent]) * v11) + c->z;
        v13 = (unsigned __int8 *)&v7[offset];
        c->z = v12;
        v14 = v5[v9 + 25];
        if ( v14 == 0xFF )
          break;
        v15 = (float)d_lightstylevalue[v14] * 0.0037878789;
        c->x = (float)((float)((float)*v13 * dword_10425B80[(char)v13[3]]) * v15) + c->x;
        c->y = (float)((float)((float)v13[1] * dword_10425B80[(char)v13[3]]) * v15) + c->y;
        v16 = (float)((float)((float)v13[2] * dword_10425B80[(char)v13[3]]) * v15) + c->z;
        v17 = &v13[4 * offset];
        c->z = v16;
        v18 = v5[v9 + 26];
        if ( v18 == 0xFF )
          break;
        v19 = (float)d_lightstylevalue[v18] * 0.0037878789;
        c->x = (float)((float)((float)*v17 * dword_10425B80[(char)v17[3]]) * v19) + c->x;
        c->y = (float)((float)((float)v17[1] * dword_10425B80[(char)v17[3]]) * v19) + c->y;
        v20 = (float)((float)((float)v17[2] * dword_10425B80[(char)v17[3]]) * v19) + c->z;
        v21 = &v17[4 * offset];
        c->z = v20;
        v22 = v5[v9 + 27];
        if ( v22 == 0xFF )
          break;
        v23 = (float)d_lightstylevalue[v22] * 0.0037878789;
        c->x = (float)((float)((float)*v21 * dword_10425B80[(char)v21[3]]) * v23) + c->x;
        c->y = (float)((float)((float)v21[1] * dword_10425B80[(char)v21[3]]) * v23) + c->y;
        v24 = (float)v21[2] * dword_10425B80[(char)v21[3]];
        v7 = (ColorRGBExp32 *)&v21[4 * offset];
        v8 = (int)pLightmapa;
        v9 += 4;
        c->z = (float)(v24 * v23) + c->z;
        if ( v9 >= (int)&pLightmapa[-1].g )
          goto LABEL_12;
      }
    }
  }
  else if ( ++messagecount < 10 )
  {
    ConMsg(a1: "hit surface has no samples\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CA5F0
// Name: ComputeLightmapColorFromAverage
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeLightmapColorFromAverage(
        bool bUseLightStyles@<dl>,
        Vector *c@<eax>,
        msurfacelighting_t *pLighting)
{
  int v3; // edx
  int v4; // esi
  msurfacelighting_t *v5; // edi
  unsigned __int8 v6; // cl
  ColorRGBExp32 *m_pSamples; // edx
  float v8; // xmm0_4
  unsigned __int8 v9; // cl
  float v10; // xmm0_4
  unsigned __int8 v11; // cl
  float v12; // xmm0_4
  unsigned __int8 v13; // cl
  ColorRGBExp32 *v14; // edx
  float v15; // xmm0_4
  float v16; // xmm2_4
  unsigned __int8 *v17; // esi
  ColorRGBExp32 *v18; // ecx
  float v19; // xmm0_4
  float v20; // xmm2_4
  int v21; // ecx
  int nMaxMaps; // [esp+4h] [ebp-8h]
  int nMaxMapsa; // [esp+4h] [ebp-8h]
  int v24; // [esp+8h] [ebp-4h]
  int v25; // [esp+8h] [ebp-4h]

  v3 = bUseLightStyles ? 4 : 1;
  v4 = 0;
  v5 = pLighting;
  nMaxMaps = v3;
  if ( (unsigned int)v3 < 4 )
  {
LABEL_8:
    if ( v4 < v3 )
    {
      v25 = 4 * v4;
      v17 = &v5->m_nStyles[v4];
      nMaxMapsa = (int)v17;
      do
      {
        if ( *v17 == 0xFF )
          break;
        v18 = &v5->m_pSamples[v25 / 0xFFFFFFFC];
        v25 += 4;
        v19 = (float)d_lightstylevalue[*v17] * 0.0037878789;
        c->x = (float)((float)((float)v18[-1].r * dword_10425B80[v18[-1].exponent]) * v19) + c->x;
        c->y = (float)((float)((float)v18[-1].g * dword_10425B80[v18[-1].exponent]) * v19) + c->y;
        v20 = (float)v18[-1].b * dword_10425B80[v18[-1].exponent];
        v17 = (unsigned __int8 *)(nMaxMapsa + 1);
        v21 = nMaxMapsa + 1 + -24 - (_DWORD)v5;
        c->z = (float)(v20 * v19) + c->z;
        ++nMaxMapsa;
      }
      while ( v21 < v3 );
    }
  }
  else
  {
    v24 = 12;
    while ( 1 )
    {
      v6 = v5->m_nStyles[v4];
      if ( v6 == 0xFF )
        break;
      m_pSamples = v5->m_pSamples;
      v8 = (float)d_lightstylevalue[v6] * 0.0037878789;
      c->x = (float)((float)((float)m_pSamples[v24 / 0xFFFFFFFC + 2].r
                           * dword_10425B80[m_pSamples[v24 / 0xFFFFFFFC + 2].exponent])
                   * v8)
           + c->x;
      c->y = (float)((float)((float)m_pSamples[v24 / 0xFFFFFFFC + 2].g
                           * dword_10425B80[m_pSamples[v24 / 0xFFFFFFFC + 2].exponent])
                   * v8)
           + c->y;
      c->z = (float)((float)((float)m_pSamples[v24 / 0xFFFFFFFC + 2].b
                           * dword_10425B80[m_pSamples[v24 / 0xFFFFFFFC + 2].exponent])
                   * v8)
           + c->z;
      v9 = pLighting->m_nStyles[v4 + 1];
      if ( v9 == 0xFF )
        break;
      v10 = (float)d_lightstylevalue[v9] * 0.0037878789;
      c->x = (float)((float)((float)m_pSamples[v24 / 0xFFFFFFFC + 1].r
                           * dword_10425B80[m_pSamples[v24 / 0xFFFFFFFC + 1].exponent])
                   * v10)
           + c->x;
      c->y = (float)((float)((float)m_pSamples[v24 / 0xFFFFFFFC + 1].g
                           * dword_10425B80[m_pSamples[v24 / 0xFFFFFFFC + 1].exponent])
                   * v10)
           + c->y;
      c->z = (float)((float)((float)m_pSamples[v24 / 0xFFFFFFFC + 1].b
                           * dword_10425B80[m_pSamples[v24 / 0xFFFFFFFC + 1].exponent])
                   * v10)
           + c->z;
      v11 = pLighting->m_nStyles[v4 + 2];
      if ( v11 == 0xFF )
        break;
      v12 = (float)d_lightstylevalue[v11] * 0.0037878789;
      c->x = (float)((float)((float)m_pSamples[v24 / 0xFFFFFFFC].r
                           * dword_10425B80[m_pSamples[v24 / 0xFFFFFFFC].exponent])
                   * v12)
           + c->x;
      c->y = (float)((float)((float)m_pSamples[v24 / 0xFFFFFFFC].g
                           * dword_10425B80[m_pSamples[v24 / 0xFFFFFFFC].exponent])
                   * v12)
           + c->y;
      v5 = pLighting;
      c->z = (float)((float)((float)m_pSamples[v24 / 0xFFFFFFFC].b
                           * dword_10425B80[m_pSamples[v24 / 0xFFFFFFFC].exponent])
                   * v12)
           + c->z;
      v13 = pLighting->m_nStyles[v4 + 3];
      if ( v13 == 0xFF )
        break;
      v14 = &m_pSamples[v24 / 0xFFFFFFFC];
      v24 += 16;
      v15 = (float)d_lightstylevalue[v13] * 0.0037878789;
      c->x = (float)((float)((float)v14[-1].r * dword_10425B80[v14[-1].exponent]) * v15) + c->x;
      c->y = (float)((float)((float)v14[-1].g * dword_10425B80[v14[-1].exponent]) * v15) + c->y;
      v16 = (float)v14[-1].b * dword_10425B80[v14[-1].exponent];
      v3 = nMaxMaps;
      v4 += 4;
      c->z = (float)(v16 * v15) + c->z;
      if ( v4 >= nMaxMaps - 3 )
        goto LABEL_8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CA980
// Name: FindIntersectionAtSurface
// Source: json
//------------------------------------------------------------------------------
char __stdcall FindIntersectionAtSurface(msurface2_t *f, LightVecState_t *state, Vector *a3, int a4)
{
  LightVecState_t *v7; // xmm6_4
  float v8; // xmm4_4
  mtexinfo_t *v9; // esi
  float v10; // xmm2_4
  float w; // xmm5_4
  float v12; // xmm3_4
  float x; // xmm0_4
  float y; // xmm7_4
  float v15; // xmm5_4
  float v16; // xmm4_4
  float v17; // xmm0_4
  unsigned int v18; // ebx
  msurfacelighting_t *v19; // ebx
  int v20; // edi
  float v21; // xmm1_4
  float v22; // xmm5_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  __int16 v25; // di
  float v26; // xmm0_4
  float v27; // xmm1_4
  int flags_high; // edi
  float v29; // xmm6_4
  mvertex_t *vertexes; // edi
  unsigned __int16 *v31; // edx
  float v32; // xmm3_4
  float v33; // xmm2_4
  float *p_x; // ecx
  float v35; // xmm1_4
  float v36; // xmm0_4
  float *v37; // edx
  float *v38; // edi
  Vector v39; // [esp+0h] [ebp-40h] BYREF
  Vector pt; // [esp+10h] [ebp-30h]
  float lightMaxs[2]; // [esp+1Ch] [ebp-24h]
  float v42; // [esp+24h] [ebp-1Ch]
  int v43; // [esp+28h] [ebp-18h]
  float v44; // [esp+2Ch] [ebp-14h]
  float z; // [esp+30h] [ebp-10h]
  float v46; // [esp+34h] [ebp-Ch]
  float v47; // [esp+38h] [ebp-8h]
  float v48; // [esp+3Ch] [ebp-4h]

  if ( (f->flags & 1) != 0 )
    return 0;
  v7 = state;
  v8 = *(float *)(a4 + 24);
  v9 = &host_state.worldbrush->texinfo[*((unsigned __int16 *)f + 11) >> 1];
  v10 = (float)(*(float *)(a4 + 16) * *(float *)&state) + *(float *)a4;
  w = v9->lightmapVecsLuxelsPerWorldUnits[0].w;
  v12 = (float)(*(float *)(a4 + 20) * *(float *)&state) + *(float *)(a4 + 4);
  x = v9->lightmapVecsLuxelsPerWorldUnits[0].x;
  y = v9->lightmapVecsLuxelsPerWorldUnits[0].y;
  lightMaxs[0] = v9->lightmapVecsLuxelsPerWorldUnits[0].z;
  v47 = w;
  lightMaxs[1] = x;
  v15 = v9->lightmapVecsLuxelsPerWorldUnits[1].y;
  v16 = (float)(v8 * *(float *)&state) + *(float *)(a4 + 8);
  v17 = (float)((float)((float)(x * v10) + (float)(y * v12)) + (float)(lightMaxs[0] * v16)) + v47;
  v46 = v9->lightmapVecsLuxelsPerWorldUnits[1].x;
  v18 = (char *)f - (char *)host_state.worldbrush->surfaces2;
  z = v9->lightmapVecsLuxelsPerWorldUnits[1].z;
  v19 = (msurfacelighting_t *)((char *)host_state.worldbrush->surfacelighting + (v18 & 0xFFFFFFE0));
  v44 = v9->lightmapVecsLuxelsPerWorldUnits[1].w;
  pt.z = v15;
  v20 = v19->m_LightmapMins[0];
  v21 = (float)(v46 * v10) + (float)(v15 * v12);
  v39.x = v10;
  v22 = (float)v20;
  v23 = (float)(v21 + (float)(z * v16)) + v44;
  v39.y = v12;
  v39.z = v16;
  if ( (float)v20 > v17 )
    return 0;
  v24 = (float)v19->m_LightmapMins[1];
  pt.y = v24;
  if ( v24 > v23 )
    return 0;
  v25 = v19->m_LightmapExtents[0];
  v26 = v17 - v22;
  v27 = v23 - v24;
  v42 = v26;
  v48 = v27;
  if ( v25 != 0 || v19->m_LightmapExtents[1] != 0 )
  {
    if ( v26 > (float)v25 || v27 > (float)v19->m_LightmapExtents[1] )
      return 0;
  }
  else
  {
    flags_high = HIBYTE(f->flags);
    v29 = v22;
    pt.x = v24;
    v43 = flags_high;
    if ( flags_high != 0 )
    {
      vertexes = host_state.worldbrush->vertexes;
      v31 = &host_state.worldbrush->vertindices[f->firstvertindex];
      do
      {
        v32 = pt.z * vertexes[*v31].position.y;
        v33 = z * vertexes[*v31].position.z;
        p_x = &vertexes[*v31].position.x;
        v35 = (float)((float)((float)((float)(v46 * *p_x) + v32) + v33) + v44) - pt.y;
        v36 = (float)((float)((float)((float)(lightMaxs[1] * *p_x) + (float)(y * p_x[1]))
                            + (float)(lightMaxs[0] * p_x[2]))
                    + v47)
            - v22;
        if ( v36 > v29 )
          v29 = (float)((float)((float)((float)(lightMaxs[1] * vertexes[*v31].position.x) + (float)(y * p_x[1]))
                              + (float)(lightMaxs[0] * p_x[2]))
                      + v47)
              - v22;
        if ( v35 > pt.x )
          pt.x = (float)((float)((float)((float)(v46 * *p_x) + v32) + v33) + v44) - pt.y;
        if ( v36 > v29 )
          v29 = v36;
        if ( v35 > pt.x )
          pt.x = v35;
        ++v31;
        --v43;
      }
      while ( v43 != 0 );
      v26 = v42;
      v27 = v48;
    }
    if ( v26 > v29 || v27 > pt.x )
      return 0;
    v7 = state;
  }
  v37 = *(float **)(a4 + 84);
  v38 = *(float **)(a4 + 88);
  *(_DWORD *)(a4 + 80) = v7;
  ComputeTextureCoordsAtIntersection(pTex: v9, pt: &v39, textureT: v38, textureS: v37);
  if ( r_avglight.m_pParent != nullptr && r_avglight.m_pParent->m_Value.m_nValue != 0 )
  {
    ComputeLightmapColorFromAverage(bUseLightStyles: *(_BYTE *)(a4 + 104), c: a3, pLighting: v19);
    return 1;
  }
  else
  {
    ComputeLightmapCoordsAtIntersection(
      pLighting: v19,
      lightmapS: *(float **)(a4 + 92),
      lightmapT: *(float **)(a4 + 96),
      a4: v42,
      dt: v48);
    ComputeLightmapColor(surfID: f, c: a3, ds: (int)v42, dt: (int)v48, bUseLightStyles: *(_BYTE *)(a4 + 104));
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CAC80
// Name: FindIntersectionSurfaceAtNode
// Source: json
//------------------------------------------------------------------------------
msurface2_t *__cdecl FindIntersectionSurfaceAtNode(mnode_t *node, float t, Vector *c, LightVecState_t *state)
{
  worldbrushdata_t *worldbrush; // edx
  mnode_t *v5; // edi
  msurface2_t *v6; // ecx
  unsigned int flags; // eax
  float v8; // xmm6_4
  float y; // xmm3_4
  float z; // xmm4_4
  int v11; // esi
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm5_4
  float v15; // xmm7_4
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  int v20; // ebx
  float v21; // xmm5_4
  float v22; // xmm5_4
  msurfacelighting_t *v23; // ebx
  int v24; // eax
  float v25; // xmm1_4
  float v26; // xmm5_4
  float v27; // xmm2_4
  __int16 v28; // ax
  float v29; // xmm0_4
  float v30; // xmm1_4
  int flags_high; // eax
  float v32; // xmm6_4
  mvertex_t *vertexes; // edi
  unsigned __int16 *vertindices; // edx
  unsigned __int16 *v35; // edx
  float v36; // xmm3_4
  float v37; // xmm2_4
  float *p_x; // eax
  float v39; // xmm1_4
  float v40; // xmm0_4
  float *m_pTextureT; // edi
  float *m_pTextureS; // ecx
  int numsurfaces; // esi
  Vector pt; // [esp+10h] [ebp-48h] BYREF
  float v46; // [esp+20h] [ebp-38h]
  float v47; // [esp+24h] [ebp-34h]
  float v48; // [esp+28h] [ebp-30h]
  float v49; // [esp+2Ch] [ebp-2Ch]
  float v50; // [esp+30h] [ebp-28h]
  float v51; // [esp+34h] [ebp-24h]
  mvertex_t *v52; // [esp+38h] [ebp-20h]
  float v53; // [esp+3Ch] [ebp-1Ch]
  int v54; // [esp+40h] [ebp-18h]
  int i; // [esp+44h] [ebp-14h]
  float v56; // [esp+48h] [ebp-10h]
  float v57; // [esp+4Ch] [ebp-Ch]
  float v58; // [esp+50h] [ebp-8h]
  msurface2_t *v59; // [esp+54h] [ebp-4h]

  worldbrush = host_state.worldbrush;
  v5 = node;
  v6 = &host_state.worldbrush->surfaces2[node->firstsurface];
  v54 = 0;
  if ( node->numsurfaces == 0 )
    return nullptr;
  while ( 1 )
  {
    flags = v6->flags;
    if ( (v6->flags & 4) != 0 )
    {
      state->m_nSkySurfID = v6;
      worldbrush = host_state.worldbrush;
      goto LABEL_30;
    }
    if ( (flags & 0x10000) == 0 )
    {
      if ( (flags & 1) != 0 )
        goto LABEL_30;
      v8 = t;
      y = state->m_Ray.m_Delta.y;
      z = state->m_Ray.m_Delta.z;
      v11 = (int)&worldbrush->texinfo[*((unsigned __int16 *)v6 + 11) >> 1];
      v12 = (float)(state->m_Ray.m_Delta.x * t) + state->m_Ray.m_Start.x;
      v13 = *(float *)(v11 + 44);
      v14 = *(float *)(v11 + 40);
      v15 = *(float *)(v11 + 36);
      v51 = *(float *)(v11 + 32);
      *(float *)&v59 = v13;
      v50 = v14;
      v16 = (float)(y * t) + state->m_Ray.m_Start.y;
      v17 = (float)(z * t) + state->m_Ray.m_Start.z;
      v18 = *(float *)(v11 + 52);
      v19 = (float)((float)((float)(v15 * v16) + (float)(v51 * v12)) + (float)(v14 * v17)) + v13;
      v20 = (char *)v6 - (char *)worldbrush->surfaces2;
      v57 = *(float *)(v11 + 48);
      v21 = *(float *)(v11 + 56);
      v49 = v18;
      v56 = v21;
      v22 = *(float *)(v11 + 60);
      v23 = (msurfacelighting_t *)((char *)worldbrush->surfacelighting + (v20 & 0xFFFFFFE0));
      pt.y = v16;
      v24 = v23->m_LightmapMins[0];
      pt.x = v12;
      v48 = v22;
      v25 = (float)((float)((float)(v18 * v16) + (float)(v57 * v12)) + (float)(v56 * v17)) + v22;
      v26 = (float)v24;
      pt.z = v17;
      if ( (float)v24 > v19 )
        goto LABEL_30;
      v27 = (float)v23->m_LightmapMins[1];
      v47 = v27;
      if ( v27 > v25 )
        goto LABEL_30;
      v28 = v23->m_LightmapExtents[0];
      v29 = v19 - v26;
      v30 = v25 - v27;
      v53 = v29;
      v58 = v30;
      if ( v28 == 0 && v23->m_LightmapExtents[1] == 0 )
        break;
      if ( v29 <= (float)v28 && v30 <= (float)v23->m_LightmapExtents[1] )
        goto LABEL_25;
    }
LABEL_30:
    numsurfaces = v5->numsurfaces;
    ++v6;
    if ( ++v54 >= numsurfaces )
      return nullptr;
  }
  flags_high = HIBYTE(v6->flags);
  v32 = v26;
  v46 = v27;
  if ( flags_high != 0 )
  {
    vertexes = worldbrush->vertexes;
    vertindices = worldbrush->vertindices;
    v52 = vertexes;
    v35 = &vertindices[v6->firstvertindex];
    for ( i = flags_high; i != 0; --i )
    {
      v36 = v49 * vertexes[*v35].position.y;
      v37 = v56 * vertexes[*v35].position.z;
      p_x = &vertexes[*v35].position.x;
      v39 = (float)((float)((float)((float)(v57 * *p_x) + v36) + v37) + v48) - v47;
      v40 = (float)((float)((float)((float)(v51 * *p_x) + (float)(v15 * p_x[1])) + (float)(v50 * p_x[2]))
                  + *(float *)&v59)
          - v26;
      if ( v40 > v32 )
        v32 = (float)((float)((float)((float)(v51 * vertexes[*v35].position.x) + (float)(v15 * p_x[1]))
                            + (float)(v50 * p_x[2]))
                    + *(float *)&v59)
            - v26;
      if ( v39 > v46 )
        v46 = (float)((float)((float)((float)(v57 * *p_x) + v36) + v37) + v48) - v47;
      if ( v40 > v32 )
        v32 = v40;
      if ( v39 > v46 )
        v46 = v39;
      ++v35;
    }
    v30 = v58;
    v29 = v53;
    worldbrush = host_state.worldbrush;
    v5 = node;
  }
  if ( v29 > v32 || v30 > v46 )
    goto LABEL_30;
  v8 = t;
LABEL_25:
  m_pTextureT = state->m_pTextureT;
  v59 = v6;
  m_pTextureS = state->m_pTextureS;
  state->m_HitFrac = v8;
  ComputeTextureCoordsAtIntersection(pTex: (mtexinfo_t *)v11, &pt, textureT: m_pTextureT, textureS: m_pTextureS);
  if ( r_avglight.m_pParent != nullptr && r_avglight.m_pParent->m_Value.m_nValue != 0 )
  {
    ComputeLightmapColorFromAverage(bUseLightStyles: state->m_bUseLightStyles, c, pLighting: v23);
    return v59;
  }
  else
  {
    ComputeLightmapCoordsAtIntersection(
      pLighting: v23,
      lightmapS: state->m_pLightmapS,
      lightmapT: state->m_pLightmapT,
      a4: v53,
      dt: v58);
    ComputeLightmapColor(surfID: v59, c, ds: (int)v53, dt: (int)v58, bUseLightStyles: state->m_bUseLightStyles);
    return v59;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CAFD0
// Name: R_LightVecDisplacementChain
// Source: json
//------------------------------------------------------------------------------
msurface2_t *__usercall R_LightVecDisplacementChain@<eax>(
        LightVecState_t *state@<edi>,
        bool bUseLightStyles,
        Vector *c)
{
  msurface2_t *v3; // ebx
  IDispInfo *v4; // esi
  float *m_pLightmapS; // ecx
  float *m_pLightmapT; // esi
  char *v7; // eax
  float v8; // xmm0_4
  __int16 v9; // dx
  __int16 v10; // ax
  float *m_pTextureS; // eax
  float v13[2]; // [esp+1Ch] [ebp-1Ch] BYREF
  float v14; // [esp+24h] [ebp-14h] BYREF
  float v15; // [esp+28h] [ebp-10h]
  float *v16; // [esp+2Ch] [ebp-Ch]
  float v17; // [esp+30h] [ebp-8h] BYREF
  Vector2D tuv; // [esp+34h] [ebp-4h]

  v3 = nullptr;
  tuv.x = 0.0;
  if ( state->m_LightTestDisps.m_Size > 0 )
  {
    do
    {
      v4 = state->m_LightTestDisps.m_Memory.m_pMemory[LODWORD(tuv.x)];
      if ( ((unsigned __int8 (__thiscall *)(IDispInfo *, LightVecState_t *, _DWORD, float, float *, float *, float *))v4->TestRay)(
             a1: v4,
             a2: state,
             a3: 0.0,
             a4: state->m_HitFrac,
             a5: &v17,
             a6: &v14,
             a7: v13) != 0 )
      {
        state->m_HitFrac = v17;
        v3 = v4->GetParent(this: v4);
        ComputeLightmapColor(surfID: v3, c, ds: (int)v14, dt: (int)v15, bUseLightStyles);
        m_pLightmapS = state->m_pLightmapS;
        if ( m_pLightmapS != nullptr )
        {
          m_pLightmapT = state->m_pLightmapT;
          v16 = m_pLightmapT;
          if ( m_pLightmapT != nullptr )
          {
            v7 = (char *)host_state.worldbrush->surfacelighting
               + (((char *)v3 - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0);
            v8 = (float)(int)v15;
            v9 = *((_WORD *)v7 + 2);
            if ( v9 != 0 )
            {
              m_pLightmapT = v16;
              *m_pLightmapS = (float)((float)(int)v14 + 0.5) / (float)v9;
            }
            else
            {
              *m_pLightmapS = 0.5;
            }
            v10 = *((_WORD *)v7 + 3);
            if ( v10 != 0 )
              *m_pLightmapT = (float)(v8 + 0.5) / (float)v10;
            else
              *m_pLightmapT = 0.5;
          }
        }
        m_pTextureS = state->m_pTextureS;
        if ( m_pTextureS != nullptr && state->m_pTextureT != nullptr )
        {
          *m_pTextureS = v13[0];
          *state->m_pTextureT = v13[1];
        }
      }
      ++LODWORD(tuv.x);
    }
    while ( SLODWORD(tuv.x) < state->m_LightTestDisps.m_Size );
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100CB120
// Name: AddDisplacementsInLeafToTestList
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddDisplacementsInLeafToTestList(mleaf_t *pLeaf, LightVecState_t *state)
{
  mleaf_t *v2; // ecx
  int v3; // eax
  IDispInfo *v4; // ebx
  int v5; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  IDispInfo **m_pMemory; // ecx
  int v9; // eax
  IDispInfo **v10; // edi
  int i; // [esp+0h] [ebp-4h]

  v2 = pLeaf;
  v3 = 0;
  i = 0;
  if ( pLeaf->dispCount != 0 )
  {
    do
    {
      v4 = DispInfo_IndexArray(
             hArray: (_DWORD *)host_state.worldbrush->hDispInfos,
             iElement: host_state.worldbrush->m_pDispInfoReferences[v3 + v2->dispListStart]);
      v5 = (int)v4->GetParent(this: v4);
      if ( *(_DWORD *)(v5 + 28) != r_surfacevisframe )
      {
        *(_DWORD *)(v5 + 28) = r_surfacevisframe;
        m_Size = state->m_LightTestDisps.m_Size;
        m_nAllocationCount = state->m_LightTestDisps.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<INetMessage *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)&state->m_LightTestDisps,
            num: m_Size - m_nAllocationCount + 1);
        ++state->m_LightTestDisps.m_Size;
        m_pMemory = state->m_LightTestDisps.m_Memory.m_pMemory;
        v9 = state->m_LightTestDisps.m_Size - m_Size - 1;
        state->m_LightTestDisps.m_pElements = m_pMemory;
        if ( v9 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
        v10 = &state->m_LightTestDisps.m_Memory.m_pMemory[m_Size];
        if ( v10 != nullptr )
          *v10 = v4;
      }
      v2 = pLeaf;
      v3 = i + 1;
      i = v3;
    }
    while ( v3 < pLeaf->dispCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CB1F0
// Name: FindIntersectionSurfaceAtLeaf
// Source: json
//------------------------------------------------------------------------------
msurface2_t *__userpurge FindIntersectionSurfaceAtLeaf@<eax>(
        LightVecState_t *state@<esi>,
        mleaf_t *pLeaf,
        float start,
        float end,
        Vector *c)
{
  int nummarknodesurfaces; // ebx
  msurface2_t *v6; // edi
  float *p_x; // eax
  float y; // xmm1_4
  float z; // xmm3_4
  float v10; // xmm6_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm3_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  LightVecState_t *v18; // [esp+0h] [ebp-14h]
  msurface2_t **i; // [esp+Ch] [ebp-8h]
  msurface2_t *v20; // [esp+10h] [ebp-4h]

  v20 = nullptr;
  AddDisplacementsInLeafToTestList(pLeaf, state: v18);
  nummarknodesurfaces = pLeaf->nummarknodesurfaces;
  for ( i = &host_state.worldbrush->marksurfaces[pLeaf->firstmarksurface];
        nummarknodesurfaces < pLeaf->nummarksurfaces;
        ++nummarknodesurfaces )
  {
    v6 = i[nummarknodesurfaces];
    if ( (v6->flags & 0x800) == 0 && (v6->flags & 0x10012) == 0 )
    {
      p_x = &v6->plane->normal.x;
      y = state->m_Ray.m_Delta.y;
      z = state->m_Ray.m_Delta.z;
      v10 = *p_x * state->m_Ray.m_Delta.x;
      if ( (float)((float)((float)(p_x[1] * y) + v10) + (float)(p_x[2] * z)) <= 0.0 )
      {
        v11 = (float)((float)(state->m_Ray.m_Start.y * p_x[1]) + (float)(*p_x * state->m_Ray.m_Start.x))
            + (float)(state->m_Ray.m_Start.z * p_x[2]);
        v12 = (float)((float)(y * p_x[1]) + v10) + (float)(z * p_x[2]);
        v13 = p_x[3];
        v14 = (float)((float)(v12 * start) + v11) - v13;
        v15 = (float)((float)(v12 * end) + v11) - v13;
        if ( v15 < 0.0 != v14 < 0.0 )
        {
          v16 = v14 / (float)(v14 - v15);
          if ( v16 < state->m_HitFrac
            && FindIntersectionAtSurface(
                 f: v6,
                 state: COERCE_LIGHTVECSTATE_T_((float)((float)(1.0 - v16) * start) + (float)(v16 * end)),
                 a3: c,
                 a4: (int)state) != 0 )
          {
            v20 = v6;
          }
        }
      }
    }
  }
  return v20;
}

//------------------------------------------------------------------------------
// Address: 0x100CB370
// Name: struct msurface2_t __near * RecursiveLightPoint(struct mnode_t __near *,float,float,class Vector __near &,struct LightVecState_t __near &)
// Source: json
//------------------------------------------------------------------------------
msurface2_t *__cdecl RecursiveLightPoint(mleaf_t *node, float start, float end, Vector *c, LightVecState_t *state)
{
  msurface2_t *result; // eax
  cplane_t *v7; // eax
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  int v12; // ecx
  float v13; // [esp+1Ch] [ebp-4h]
  int pLeaf; // [esp+28h] [ebp+8h]

  if ( node->contents >= 0 )
    return FindIntersectionSurfaceAtLeaf(state, pLeaf: node, start, end, c);
  v7 = *(cplane_t **)&node->cluster;
  v8 = (float)((float)(state->m_Ray.m_Start.y * v7->normal.y) + (float)(v7->normal.x * state->m_Ray.m_Start.x))
     + (float)(state->m_Ray.m_Start.z * v7->normal.z);
  v9 = (float)((float)(state->m_Ray.m_Delta.y * v7->normal.y) + (float)(v7->normal.x * state->m_Ray.m_Delta.x))
     + (float)(state->m_Ray.m_Delta.z * v7->normal.z);
  v10 = (float)((float)(v9 * start) + v8) - v7->dist;
  v11 = (float)((float)(v9 * end) + v8) - v7->dist;
  if ( v10 >= 0.0 )
  {
    pLeaf = 0;
    v12 = 0;
  }
  else
  {
    v12 = 1;
    pLeaf = 1;
  }
  if ( v11 < 0.0 == v12 )
    return RecursiveLightPoint(node: *((mnode_t **)&node->firstmarksurface + v12), start, end, c, state);
  v13 = (float)((float)(1.0 - (float)(v10 / (float)(v10 - v11))) * start)
      + (float)((float)(v10 / (float)(v10 - v11)) * end);
  result = RecursiveLightPoint(node: *((mnode_t **)&node->firstmarksurface + pLeaf), start, end: v13, c, state);
  if ( result == nullptr )
  {
    result = FindIntersectionSurfaceAtNode((mnode_t *)node, t: v13, c, state);
    if ( result == nullptr )
      return RecursiveLightPoint(node: *((mnode_t **)&node->firstmarksurface + (pLeaf == 0)), start: v13, end, c, state);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100CB500
// Name: struct msurface2_t __near * R_LightVec(class Vector const __near &,class Vector const __near &,bool,class Vector __near &,float __near *,float __near *,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
msurface2_t *__usercall R_LightVec@<eax>(
        int a1@<ebp>,
        const Vector *start,
        const Vector *end,
        bool bUseLightStyles,
        Vector *c,
        float *textureS,
        float *textureT,
        float *lightmapS,
        float *lightmapT)
{
  float y; // xmm1_4
  float x; // xmm3_4
  float v11; // xmm4_4
  float z; // xmm2_4
  float v13; // xmm5_4
  float v14; // xmm0_4
  model_t *worldmodel; // eax
  msurface2_t *v16; // edi
  float v17; // xmm4_4
  float v18; // xmm5_4
  int v19; // esi
  _DWORD v21[5]; // [esp+20h] [ebp-9Ch] BYREF
  float v22; // [esp+34h] [ebp-88h]
  float v23; // [esp+38h] [ebp-84h]
  float flDuration; // [esp+40h] [ebp-7Ch]
  int v25; // [esp+44h] [ebp-78h]
  int v26; // [esp+48h] [ebp-74h]
  int v27; // [esp+50h] [ebp-6Ch]
  int v28; // [esp+54h] [ebp-68h]
  int v29; // [esp+58h] [ebp-64h]
  _BYTE state[88]; // [esp+60h] [ebp-5Ch] OVERLAPPED BYREF
  int state_92; // [esp+BCh] [ebp+0h]

  *(_DWORD *)&state[80] = a1;
  *(_DWORD *)&state[84] = state_92;
  if ( (_S1_7 & 1) == 0 )
  {
    _S1_7 |= 1u;
    counter.m_pCounter = CVProfile::FindOrCreateCounter(
                           this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                           a2: "R_LightVec",
                           a3: COUNTER_GROUP_DEFAULT);
    atexit(func: R_LightVec_::_4_::_dynamic_atexit_destructor_for___counter__);
  }
  ++*counter.m_pCounter;
  ++r_surfacevisframe;
  y = end->y;
  x = start->x;
  v11 = start->y;
  z = end->z;
  v13 = start->z;
  *(_DWORD *)&state[16] = 1065353216;
  v14 = end->x - x;
  v22 = y - v11;
  *(float *)&v21[4] = v14;
  v23 = z - v13;
  memset(&state[44], 0, 20);
  state[5] = (float)((float)((float)(v22 * v22) + (float)(v14 * v14)) + (float)(v23 * v23)) != 0.0;
  *(_DWORD *)&state[20] = textureS;
  *(_DWORD *)&state[28] = lightmapS;
  state[4] = 1;
  state[40] = bUseLightStyles;
  worldmodel = s_pLightVecModel;
  *(_DWORD *)&state[24] = textureT;
  v29 = 0;
  v28 = 0;
  v27 = 0;
  *(_DWORD *)state = 0;
  v26 = 0;
  v25 = 0;
  flDuration = 0.0;
  *(float *)v21 = x;
  *(float *)&v21[1] = v11;
  *(float *)&v21[2] = v13;
  *(_DWORD *)&state[32] = lightmapT;
  *(_DWORD *)&state[36] = 0;
  c->z = 0.0;
  c->y = 0.0;
  c->x = 0.0;
  if ( worldmodel == nullptr )
    worldmodel = host_state.worldmodel;
  *(_DWORD *)&state[76] = RecursiveLightPoint(
                            node: (mleaf_t *)(*(_DWORD *)(worldmodel->sprite.numframes + 84)
                                      + (worldmodel->brush.firstnode << 6)),
                            start: 0.0,
                            end: 1.0,
                            c,
                            state: (LightVecState_t *)v21);
  v16 = R_LightVecDisplacementChain(state: (LightVecState_t *)v21, bUseLightStyles, c);
  if ( r_visualizelighttraces.m_pParent != nullptr && r_visualizelighttraces.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( r_visualizelighttracesshowfulltrace.m_pParent != nullptr
      && r_visualizelighttracesshowfulltrace.m_pParent->m_Value.m_nValue != 0 )
    {
      CDebugOverlay::AddLineOverlay(
        origin: start,
        dest: end,
        r: 0,
        g: 255,
        b: 0,
        a: 255,
        noDepthTest: true,
        flDuration: -1.0);
    }
    else
    {
      v17 = start->y + (float)((float)(end->y - start->y) * *(float *)&state[16]);
      v18 = start->z + (float)((float)(end->z - start->z) * *(float *)&state[16]);
      *(float *)&state[64] = start->x + (float)((float)(end->x - start->x) * *(float *)&state[16]);
      *(float *)&state[68] = v17;
      *(float *)&state[72] = v18;
      CDebugOverlay::AddLineOverlay(
        origin: start,
        dest: (const Vector *)&state[64],
        r: 0,
        g: 255,
        b: 0,
        a: 255,
        noDepthTest: true,
        flDuration: -1.0);
    }
  }
  if ( v16 != nullptr
    || (v16 = *(msurface2_t **)&state[76], *(_DWORD *)&state[76] != 0)
    || (v19 = *(_DWORD *)&state[36], *(_DWORD *)&state[36] == 0) )
  {
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&state[44]);
    return v16;
  }
  else
  {
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&state[44]);
    return (msurface2_t *)v19;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CB7B0
// Name: struct colorVec R_LightPoint(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
colorVec *__cdecl R_LightPoint(colorVec *result, Vector *p)
{
  int v2; // eax
  int v3; // eax
  float v5; // [esp-8h] [ebp-20h]
  float x; // [esp-8h] [ebp-20h]
  float f[2]; // [esp+0h] [ebp-18h] BYREF
  Vector color; // [esp+8h] [ebp-10h] BYREF
  _BYTE end[5]; // [esp+14h] [ebp-4h] OVERLAPPED BYREF

  color.y = p->x;
  color.z = p->y;
  *(float *)end = p->z - 2048.0;
  if ( R_LightVec(
         a1: (int)&end[4],
         start: p,
         end: (Vector *)&color.y,
         bUseLightStyles: true,
         c: (Vector *)f,
         textureS: nullptr,
         textureT: nullptr,
         lightmapS: nullptr,
         lightmapT: nullptr) != nullptr )
  {
    v2 = LinearToScreenGamma(f: f[0]);
    v5 = f[1];
    result->r = 255 * v2;
    v3 = LinearToScreenGamma(f: v5);
    x = color.x;
    result->g = 255 * v3;
    result->b = 255 * LinearToScreenGamma(f: x);
    result->a = 1;
    return result;
  }
  else
  {
    result->a = 0;
    result->b = 0;
    result->g = 0;
    result->r = 0;
    return result;
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100C9720
// Name: void R_AnimateLight(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_AnimateLight()
{
  INetworkStringTable *m_pLightStyleTable; // ebx
  CClientState *BaseLocalClient; // eax
  int j; // esi
  _BYTE *v3; // eax
  int v4; // edi
  int v5; // eax
  int i; // [esp+4h] [ebp-8h]
  int length; // [esp+8h] [ebp-4h] BYREF

  m_pLightStyleTable = GetBaseLocalClient()->m_pLightStyleTable;
  if ( m_pLightStyleTable != nullptr )
  {
    BaseLocalClient = GetBaseLocalClient();
    i = (int)(CClientState::GetTime(this: BaseLocalClient) * 10.0);
    for ( j = 0; j < 64; ++j )
    {
      v3 = m_pLightStyleTable->GetStringUserData(this: m_pLightStyleTable, a2: j, a3: &length);
      v4 = --length;
      if ( v3 != nullptr && *v3 != 0 )
      {
        d_lightstylenumframes[j] = v4;
        v5 = 22 * ((char)v3[i % v4] - 97);
        if ( d_lightstylevalue[j] != v5 )
        {
          d_lightstylevalue[j] = v5;
          d_lightstyleframe[j] = r_framecount;
        }
      }
      else
      {
        d_lightstylevalue[j] = 256;
        d_lightstylenumframes[j] = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C97D0
// Name: ComputeLightmapCoordsAtIntersection
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeLightmapCoordsAtIntersection(
        msurfacelighting_t *pLighting@<edx>,
        float *lightmapS@<ecx>,
        float *lightmapT@<esi>,
        float a4@<xmm1>,
        float dt)
{
  __int16 v6; // ax
  __int16 v7; // ax

  if ( lightmapS != nullptr && lightmapT != nullptr )
  {
    v6 = pLighting->m_LightmapExtents[0];
    if ( v6 != 0 )
      *lightmapS = (float)(a4 + 0.5) / (float)v6;
    else
      *lightmapS = 0.5;
    v7 = pLighting->m_LightmapExtents[1];
    if ( v7 != 0 )
      *lightmapT = (float)(dt + 0.5) / (float)v7;
    else
      *lightmapT = 0.5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C9840
// Name: void R_LightVecUseModel(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_LightVecUseModel(model_t *pModel)
{
  s_pLightVecModel = pModel;
}

//------------------------------------------------------------------------------
// Address: 0x100C9850
// Name: int R_TryLightMarkSurface(struct dlight_t __near *,struct msurfacelighting_t __near *,struct msurface2_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl R_TryLightMarkSurface(dlight_t *light, msurfacelighting_t *pLighting, msurface2_t *surfID, int bit)
{
  float x; // xmm3_4
  float y; // xmm2_4
  float z; // xmm4_4
  float v7; // xmm0_4
  float v9; // xmm1_4
  int v10; // edx
  float *v11; // eax
  int v12; // ecx
  float v13; // xmm5_4
  int v14; // ecx
  int v15; // edx
  float radius; // [esp+0h] [ebp-24h]
  Vector2D mins; // [esp+Ch] [ebp-18h] BYREF
  Vector2D maxs; // [esp+14h] [ebp-10h] BYREF
  Vector2D vecCircleCenter; // [esp+1Ch] [ebp-8h] BYREF

  x = light->origin.x;
  y = light->origin.y;
  z = light->origin.z;
  v7 = (float)((float)((float)(surfID->plane->normal.y * y) + (float)(x * surfID->plane->normal.x))
             + (float)(surfID->plane->normal.z * z))
     - surfID->plane->dist;
  if ( v7 < -15.0 )
    return 0;
  v9 = (float)(light->radius * light->radius) - (float)(v7 * v7);
  if ( v9 <= 0.0 )
    return 0;
  v10 = pLighting->m_LightmapExtents[0];
  v11 = (float *)&host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1];
  v12 = pLighting->m_LightmapMins[1];
  mins.x = (float)pLighting->m_LightmapMins[0];
  v13 = (float)v12;
  v14 = pLighting->m_LightmapExtents[1];
  mins.y = v13;
  maxs.y = (float)v14 + v13;
  maxs.x = (float)v10 + mins.x;
  vecCircleCenter.x = (float)((float)((float)(v11[9] * y) + (float)(v11[8] * x)) + (float)(v11[10] * z)) + v11[11];
  vecCircleCenter.y = (float)((float)((float)(v11[13] * y) + (float)(v11[12] * x)) + (float)(v11[14] * z)) + v11[15];
  radius = sqrt((float)((float)(v11[16] * v9) * v11[16]));
  if ( !IsCircleIntersectingRectangle(boxMin: &mins, boxMax: &maxs, center: &vecCircleCenter, radius) )
    return 0;
  v15 = r_framecount;
  pLighting->m_fDLightBits |= bit;
  pLighting->m_nDLightFrame = v15;
  surfID->flags |= 0x80000u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C99E0
// Name: int R_MarkLightsLeaf(struct dlight_t __near *,int,struct mleaf_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl R_MarkLightsLeaf(dlight_t *light, int bit, mleaf_t *pLeaf)
{
  mleaf_t *v3; // eax
  int v4; // ebx
  bool v5; // cf
  worldbrushdata_t *worldbrush; // ecx
  IDispInfo *v7; // eax
  int v8; // eax
  _DWORD *v9; // edi
  char *v10; // esi
  int v11; // edx
  int v12; // ebx
  msurface2_t *v13; // edx
  msurfacelighting_t *v14; // eax
  float v15; // xmm0_4
  float radius; // xmm1_4
  int v17; // eax
  Vector bmin; // [esp+18h] [ebp-20h] BYREF
  Vector bmax; // [esp+24h] [ebp-14h] BYREF
  msurface2_t **pHandle; // [esp+30h] [ebp-8h]
  int countMarked; // [esp+34h] [ebp-4h]

  v3 = pLeaf;
  v4 = 0;
  v5 = pLeaf->dispCount != 0;
  worldbrush = host_state.worldbrush;
  countMarked = 0;
  if ( v5 )
  {
    do
    {
      v7 = DispInfo_IndexArray(
             hArray: (_DWORD *)worldbrush->hDispInfos,
             iElement: worldbrush->m_pDispInfoReferences[v4 + v3->dispListStart]);
      v8 = (int)v7->GetParent(this: v7);
      v9 = (_DWORD *)v8;
      if ( v8 != 0 )
      {
        worldbrush = host_state.worldbrush;
        v10 = (char *)host_state.worldbrush->surfacelighting
            + ((v8 - (unsigned int)host_state.worldbrush->surfaces2) & 0xFFFFFFE0);
        if ( *((_DWORD *)v10 + 5) == r_framecount && (bit & *((_DWORD *)v10 + 4)) != 0 )
          goto LABEL_8;
        (*(void (__thiscall **)(_DWORD, Vector *, Vector *))(**(_DWORD **)(v8 + 24) + 12))(
          a1: *(_DWORD *)(v8 + 24),
          a2: &bmin,
          a3: &bmax);
        if ( IsBoxIntersectingSphere(boxMin: &bmin, boxMax: &bmax, center: &light->origin, radius: light->radius) )
        {
          v11 = r_framecount;
          *((_DWORD *)v10 + 4) |= bit;
          *((_DWORD *)v10 + 5) = v11;
          *v9 |= 0x80000u;
          ++countMarked;
        }
      }
      worldbrush = host_state.worldbrush;
LABEL_8:
      v3 = pLeaf;
      ++v4;
    }
    while ( v4 < pLeaf->dispCount );
  }
  pHandle = &worldbrush->marksurfaces[v3->firstmarksurface];
  v12 = 0;
  if ( v3->nummarksurfaces != 0 )
  {
    do
    {
      v13 = pHandle[v12];
      if ( (v13->flags & 2) == 0 )
      {
        v14 = (msurfacelighting_t *)((char *)worldbrush->surfacelighting
                                   + (((char *)v13 - (char *)worldbrush->surfaces2) & 0xFFFFFFE0));
        if ( v14->m_nDLightFrame != r_framecount || (bit & v14->m_fDLightBits) == 0 )
        {
          v15 = (float)((float)((float)(light->origin.y * v13->plane->normal.y)
                              + (float)(v13->plane->normal.x * light->origin.x))
                      + (float)(light->origin.z * v13->plane->normal.z))
              - v13->plane->dist;
          radius = light->radius;
          if ( v15 <= radius && COERCE_FLOAT(LODWORD(radius) ^ _mask__NegFloat_) <= v15 )
          {
            v17 = R_TryLightMarkSurface(light, pLighting: v14, surfID: v13, bit);
            worldbrush = host_state.worldbrush;
            countMarked += v17;
          }
        }
      }
      ++v12;
    }
    while ( v12 < pLeaf->nummarksurfaces );
  }
  return countMarked;
}

//------------------------------------------------------------------------------
// Address: 0x100C9B80
// Name: int R_MarkLights(struct dlight_t __near *,int,struct mnode_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl R_MarkLights(dlight_t *light, int bit, mnode_t *node)
{
  mnode_t *v3; // edi
  int v4; // ebx
  dlight_t *v5; // edx
  float radius; // xmm1_4
  float v7; // xmm0_4
  worldbrushdata_t *worldbrush; // ecx
  msurface2_t *v10; // esi
  msurfacelighting_t *v11; // eax
  int v12; // eax
  int v13; // ebx
  int i; // [esp+18h] [ebp+10h]

  v3 = node;
  v4 = 0;
  if ( node->contents >= 0 )
    return R_MarkLightsLeaf(light, bit, pLeaf: (mleaf_t *)v3);
  v5 = light;
  radius = light->radius;
  while ( 1 )
  {
    v7 = (float)((float)((float)(v3->plane->normal.y * light->origin.y) + (float)(v3->plane->normal.x * light->origin.x))
               + (float)(v3->plane->normal.z * light->origin.z))
       - v3->plane->dist;
    if ( v7 <= radius )
      break;
    v3 = v3->children[0];
LABEL_7:
    if ( v3->contents >= 0 )
      return R_MarkLightsLeaf(light, bit, pLeaf: (mleaf_t *)v3);
  }
  if ( (float)-radius > v7 )
  {
    v3 = v3->children[1];
    goto LABEL_7;
  }
  worldbrush = host_state.worldbrush;
  v10 = &host_state.worldbrush->surfaces2[v3->firstsurface];
  i = 0;
  if ( v3->numsurfaces != 0 )
  {
    do
    {
      v11 = (msurfacelighting_t *)((char *)worldbrush->surfacelighting
                                 + (((char *)v10 - (char *)worldbrush->surfaces2) & 0xFFFFFFE0));
      if ( v11->m_nDLightFrame != r_framecount || (bit & v11->m_fDLightBits) == 0 )
      {
        v12 = R_TryLightMarkSurface(light, pLighting: v11, surfID: v10, bit);
        worldbrush = host_state.worldbrush;
        v4 += v12;
      }
      ++i;
      ++v10;
    }
    while ( i < v3->numsurfaces );
    v5 = light;
  }
  v13 = R_MarkLights(light: v5, bit, node: v3->children[0]) + v4;
  return v13 + R_MarkLights(light, bit, node: v3->children[1]);
}

//------------------------------------------------------------------------------
// Address: 0x100C9CA0
// Name: void R_MarkDLightsOnSurface(struct mnode_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_MarkDLightsOnSurface(mnode_t *pNode)
{
  int v1; // edi
  dlight_t *v2; // esi
  int i; // ebx
  CClientState *BaseLocalClient; // eax

  if ( pNode != nullptr && g_bActiveDlights )
  {
    v1 = 1;
    v2 = cl_dlights;
    for ( i = 32; i != 0; --i )
    {
      BaseLocalClient = GetBaseLocalClient();
      if ( CClientState::GetTime(this: BaseLocalClient) <= v2->die
        && (float)(v2->radius > 0.0) != 0.0
        && (v2->flags & 1) == 0 )
      {
        R_MarkLights(light: v2, bit: v1, node: pNode);
      }
      v1 = __ROL4__(v1, 1);
      ++v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C9D20
// Name: void R_PushDlights(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_PushDlights()
{
  R_MarkDLightsOnSurface(pNode: host_state.worldbrush->nodes);
  MarkDLightsOnStaticProps();
}

//------------------------------------------------------------------------------
// Address: 0x100C9D40
// Name: ComputeTextureCoordsAtIntersection
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeTextureCoordsAtIntersection(
        mtexinfo_t *pTex@<esi>,
        const Vector *pt@<eax>,
        float *textureT@<edi>,
        float *textureS)
{
  if ( pTex->material != nullptr && textureS != nullptr && textureT != nullptr )
  {
    *textureS = (float)((float)((float)(pTex->textureVecsTexelsPerWorldUnits[0].y * pt->y)
                              + (float)(pTex->textureVecsTexelsPerWorldUnits[0].x * pt->x))
                      + (float)(pTex->textureVecsTexelsPerWorldUnits[0].z * pt->z))
              + pTex->textureVecsTexelsPerWorldUnits[0].w;
    *textureT = (float)((float)((float)(pTex->textureVecsTexelsPerWorldUnits[1].y * pt->y)
                              + (float)(pTex->textureVecsTexelsPerWorldUnits[1].x * pt->x))
                      + (float)(pTex->textureVecsTexelsPerWorldUnits[1].z * pt->z))
              + pTex->textureVecsTexelsPerWorldUnits[1].w;
    *textureS = *textureS / (float)pTex->material->GetMappingWidth(this: pTex->material);
    *textureT = *textureT / (float)pTex->material->GetMappingHeight(this: pTex->material);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C9E00
// Name: ComputeLightmapColor
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeLightmapColor(msurface2_t *surfID@<ecx>, Vector *c@<esi>, int ds, int dt, bool bUseLightStyles)
{
  char *v5; // edi
  int v6; // ebx
  ColorRGBExp32 *v7; // eax
  int v8; // edx
  int v9; // ecx
  unsigned __int8 v10; // dl
  float v11; // xmm0_4
  float v12; // xmm2_4
  unsigned __int8 *v13; // eax
  unsigned __int8 v14; // dl
  float v15; // xmm0_4
  float v16; // xmm2_4
  unsigned __int8 *v17; // eax
  unsigned __int8 v18; // dl
  float v19; // xmm0_4
  float v20; // xmm2_4
  unsigned __int8 *v21; // eax
  unsigned __int8 v22; // dl
  float v23; // xmm0_4
  float v24; // xmm2_4
  char *v25; // ecx
  float v26; // xmm0_4
  float v27; // xmm2_4
  ColorRGBExp32 *pLightmap; // [esp+4h] [ebp-8h]
  ColorRGBExp32 *pLightmapa; // [esp+4h] [ebp-8h]
  int offset; // [esp+8h] [ebp-4h]

  v5 = (char *)host_state.worldbrush->surfacelighting
     + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0);
  pLightmap = *((ColorRGBExp32 **)v5 + 7);
  if ( pLightmap != nullptr )
  {
    v6 = *((__int16 *)v5 + 2) + 1;
    offset = v6 * (*((__int16 *)v5 + 3) + 1);
    if ( SurfHasBumpedLightmaps(surfID) )
      offset *= 4;
    v7 = &pLightmap[ds + dt * v6];
    v8 = bUseLightStyles ? 4 : 1;
    v9 = 0;
    pLightmapa = (ColorRGBExp32 *)v8;
    if ( (unsigned int)v8 < 4 )
    {
LABEL_12:
      if ( v9 < v8 )
      {
        v25 = &v5[v9 + 24];
        do
        {
          if ( *v25 == -1 )
            break;
          v26 = (float)d_lightstylevalue[(unsigned __int8)*v25] * 0.0037878789;
          c->x = (float)((float)((float)v7->r * dword_10425B80[v7->exponent]) * v26) + c->x;
          c->y = (float)((float)((float)v7->g * dword_10425B80[v7->exponent]) * v26) + c->y;
          v27 = (float)v7->b * dword_10425B80[v7->exponent];
          v7 += offset;
          ++v25;
          c->z = (float)(v27 * v26) + c->z;
        }
        while ( (int)&v25[-24 - (_DWORD)v5] < v8 );
      }
    }
    else
    {
      while ( 1 )
      {
        v10 = v5[v9 + 24];
        if ( v10 == 0xFF )
          break;
        v11 = (float)d_lightstylevalue[v10] * 0.0037878789;
        c->x = (float)((float)((float)v7->r * dword_10425B80[v7->exponent]) * v11) + c->x;
        c->y = (float)((float)((float)v7->g * dword_10425B80[v7->exponent]) * v11) + c->y;
        v12 = (float)((float)((float)v7->b * dword_10425B80[v7->exponent]) * v11) + c->z;
        v13 = (unsigned __int8 *)&v7[offset];
        c->z = v12;
        v14 = v5[v9 + 25];
        if ( v14 == 0xFF )
          break;
        v15 = (float)d_lightstylevalue[v14] * 0.0037878789;
        c->x = (float)((float)((float)*v13 * dword_10425B80[(char)v13[3]]) * v15) + c->x;
        c->y = (float)((float)((float)v13[1] * dword_10425B80[(char)v13[3]]) * v15) + c->y;
        v16 = (float)((float)((float)v13[2] * dword_10425B80[(char)v13[3]]) * v15) + c->z;
        v17 = &v13[4 * offset];
        c->z = v16;
        v18 = v5[v9 + 26];
        if ( v18 == 0xFF )
          break;
        v19 = (float)d_lightstylevalue[v18] * 0.0037878789;
        c->x = (float)((float)((float)*v17 * dword_10425B80[(char)v17[3]]) * v19) + c->x;
        c->y = (float)((float)((float)v17[1] * dword_10425B80[(char)v17[3]]) * v19) + c->y;
        v20 = (float)((float)((float)v17[2] * dword_10425B80[(char)v17[3]]) * v19) + c->z;
        v21 = &v17[4 * offset];
        c->z = v20;
        v22 = v5[v9 + 27];
        if ( v22 == 0xFF )
          break;
        v23 = (float)d_lightstylevalue[v22] * 0.0037878789;
        c->x = (float)((float)((float)*v21 * dword_10425B80[(char)v21[3]]) * v23) + c->x;
        c->y = (float)((float)((float)v21[1] * dword_10425B80[(char)v21[3]]) * v23) + c->y;
        v24 = (float)v21[2] * dword_10425B80[(char)v21[3]];
        v7 = (ColorRGBExp32 *)&v21[4 * offset];
        v8 = (int)pLightmapa;
        v9 += 4;
        c->z = (float)(v24 * v23) + c->z;
        if ( v9 >= (int)&pLightmapa[-1].g )
          goto LABEL_12;
      }
    }
  }
  else if ( ++messagecount < 10 )
  {
    ConMsg(a1: "hit surface has no samples\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CA1F0
// Name: ComputeLightmapColorFromAverage
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeLightmapColorFromAverage(
        bool bUseLightStyles@<dl>,
        Vector *c@<eax>,
        msurfacelighting_t *pLighting)
{
  int v3; // edx
  int v4; // esi
  msurfacelighting_t *v5; // edi
  unsigned __int8 v6; // cl
  ColorRGBExp32 *m_pSamples; // edx
  float v8; // xmm0_4
  unsigned __int8 v9; // cl
  float v10; // xmm0_4
  unsigned __int8 v11; // cl
  float v12; // xmm0_4
  unsigned __int8 v13; // cl
  ColorRGBExp32 *v14; // edx
  float v15; // xmm0_4
  float v16; // xmm2_4
  unsigned __int8 *v17; // esi
  ColorRGBExp32 *v18; // ecx
  float v19; // xmm0_4
  float v20; // xmm2_4
  int v21; // ecx
  int nMaxMaps; // [esp+4h] [ebp-8h]
  int nMaxMapsa; // [esp+4h] [ebp-8h]
  int v24; // [esp+8h] [ebp-4h]
  int v25; // [esp+8h] [ebp-4h]

  v3 = bUseLightStyles ? 4 : 1;
  v4 = 0;
  v5 = pLighting;
  nMaxMaps = v3;
  if ( (unsigned int)v3 < 4 )
  {
LABEL_8:
    if ( v4 < v3 )
    {
      v25 = 4 * v4;
      v17 = &v5->m_nStyles[v4];
      nMaxMapsa = (int)v17;
      do
      {
        if ( *v17 == 0xFF )
          break;
        v18 = &v5->m_pSamples[v25 / 0xFFFFFFFC];
        v25 += 4;
        v19 = (float)d_lightstylevalue[*v17] * 0.0037878789;
        c->x = (float)((float)((float)v18[-1].r * dword_10425B80[v18[-1].exponent]) * v19) + c->x;
        c->y = (float)((float)((float)v18[-1].g * dword_10425B80[v18[-1].exponent]) * v19) + c->y;
        v20 = (float)v18[-1].b * dword_10425B80[v18[-1].exponent];
        v17 = (unsigned __int8 *)(nMaxMapsa + 1);
        v21 = nMaxMapsa + 1 + -24 - (_DWORD)v5;
        c->z = (float)(v20 * v19) + c->z;
        ++nMaxMapsa;
      }
      while ( v21 < v3 );
    }
  }
  else
  {
    v24 = 12;
    while ( 1 )
    {
      v6 = v5->m_nStyles[v4];
      if ( v6 == 0xFF )
        break;
      m_pSamples = v5->m_pSamples;
      v8 = (float)d_lightstylevalue[v6] * 0.0037878789;
      c->x = (float)((float)((float)m_pSamples[v24 / 0xFFFFFFFC + 2].r
                           * dword_10425B80[m_pSamples[v24 / 0xFFFFFFFC + 2].exponent])
                   * v8)
           + c->x;
      c->y = (float)((float)((float)m_pSamples[v24 / 0xFFFFFFFC + 2].g
                           * dword_10425B80[m_pSamples[v24 / 0xFFFFFFFC + 2].exponent])
                   * v8)
           + c->y;
      c->z = (float)((float)((float)m_pSamples[v24 / 0xFFFFFFFC + 2].b
                           * dword_10425B80[m_pSamples[v24 / 0xFFFFFFFC + 2].exponent])
                   * v8)
           + c->z;
      v9 = pLighting->m_nStyles[v4 + 1];
      if ( v9 == 0xFF )
        break;
      v10 = (float)d_lightstylevalue[v9] * 0.0037878789;
      c->x = (float)((float)((float)m_pSamples[v24 / 0xFFFFFFFC + 1].r
                           * dword_10425B80[m_pSamples[v24 / 0xFFFFFFFC + 1].exponent])
                   * v10)
           + c->x;
      c->y = (float)((float)((float)m_pSamples[v24 / 0xFFFFFFFC + 1].g
                           * dword_10425B80[m_pSamples[v24 / 0xFFFFFFFC + 1].exponent])
                   * v10)
           + c->y;
      c->z = (float)((float)((float)m_pSamples[v24 / 0xFFFFFFFC + 1].b
                           * dword_10425B80[m_pSamples[v24 / 0xFFFFFFFC + 1].exponent])
                   * v10)
           + c->z;
      v11 = pLighting->m_nStyles[v4 + 2];
      if ( v11 == 0xFF )
        break;
      v12 = (float)d_lightstylevalue[v11] * 0.0037878789;
      c->x = (float)((float)((float)m_pSamples[v24 / 0xFFFFFFFC].r
                           * dword_10425B80[m_pSamples[v24 / 0xFFFFFFFC].exponent])
                   * v12)
           + c->x;
      c->y = (float)((float)((float)m_pSamples[v24 / 0xFFFFFFFC].g
                           * dword_10425B80[m_pSamples[v24 / 0xFFFFFFFC].exponent])
                   * v12)
           + c->y;
      v5 = pLighting;
      c->z = (float)((float)((float)m_pSamples[v24 / 0xFFFFFFFC].b
                           * dword_10425B80[m_pSamples[v24 / 0xFFFFFFFC].exponent])
                   * v12)
           + c->z;
      v13 = pLighting->m_nStyles[v4 + 3];
      if ( v13 == 0xFF )
        break;
      v14 = &m_pSamples[v24 / 0xFFFFFFFC];
      v24 += 16;
      v15 = (float)d_lightstylevalue[v13] * 0.0037878789;
      c->x = (float)((float)((float)v14[-1].r * dword_10425B80[v14[-1].exponent]) * v15) + c->x;
      c->y = (float)((float)((float)v14[-1].g * dword_10425B80[v14[-1].exponent]) * v15) + c->y;
      v16 = (float)v14[-1].b * dword_10425B80[v14[-1].exponent];
      v3 = nMaxMaps;
      v4 += 4;
      c->z = (float)(v16 * v15) + c->z;
      if ( v4 >= nMaxMaps - 3 )
        goto LABEL_8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CA580
// Name: FindIntersectionAtSurface
// Source: json
//------------------------------------------------------------------------------
char __stdcall FindIntersectionAtSurface(msurface2_t *f, LightVecState_t *state, Vector *ca, LightVecState_t *statea)
{
  LightVecState_t *v7; // xmm6_4
  float z; // xmm4_4
  mtexinfo_t *v9; // esi
  float v10; // xmm2_4
  float w; // xmm5_4
  float v12; // xmm3_4
  float x; // xmm0_4
  float y; // xmm7_4
  float v15; // xmm5_4
  float v16; // xmm4_4
  float v17; // xmm0_4
  unsigned int v18; // ebx
  msurfacelighting_t *v19; // ebx
  int v20; // edi
  float v21; // xmm1_4
  float v22; // xmm5_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  __int16 v25; // di
  float v26; // xmm0_4
  float v27; // xmm1_4
  int flags_high; // edi
  float v29; // xmm6_4
  mvertex_t *vertexes; // edi
  unsigned __int16 *v31; // edx
  float v32; // xmm3_4
  float v33; // xmm2_4
  float *p_x; // ecx
  float v35; // xmm1_4
  float v36; // xmm0_4
  float *m_pTextureS; // edx
  float *m_pTextureT; // edi
  Vector pt; // [esp+10h] [ebp-40h] BYREF
  float lightMaxs[2]; // [esp+1Ch] [ebp-34h]
  float v41; // [esp+24h] [ebp-2Ch]
  float v42; // [esp+28h] [ebp-28h]
  float v43; // [esp+2Ch] [ebp-24h]
  float v44; // [esp+30h] [ebp-20h]
  float v45; // [esp+34h] [ebp-1Ch]
  int v46; // [esp+38h] [ebp-18h]
  float v47; // [esp+3Ch] [ebp-14h]
  float v48; // [esp+40h] [ebp-10h]
  float v49; // [esp+44h] [ebp-Ch]
  float v50; // [esp+48h] [ebp-8h]
  float dt; // [esp+4Ch] [ebp-4h]

  if ( (f->flags & 1) != 0 )
    return 0;
  v7 = state;
  z = statea->m_Ray.m_Delta.z;
  v9 = &host_state.worldbrush->texinfo[*((unsigned __int16 *)f + 11) >> 1];
  v10 = (float)(statea->m_Ray.m_Delta.x * *(float *)&state) + statea->m_Ray.m_Start.x;
  w = v9->lightmapVecsLuxelsPerWorldUnits[0].w;
  v12 = (float)(statea->m_Ray.m_Delta.y * *(float *)&state) + statea->m_Ray.m_Start.y;
  x = v9->lightmapVecsLuxelsPerWorldUnits[0].x;
  y = v9->lightmapVecsLuxelsPerWorldUnits[0].y;
  v43 = v9->lightmapVecsLuxelsPerWorldUnits[0].z;
  v50 = w;
  v44 = x;
  v15 = v9->lightmapVecsLuxelsPerWorldUnits[1].y;
  v16 = (float)(z * *(float *)&state) + statea->m_Ray.m_Start.z;
  v17 = (float)((float)((float)(x * v10) + (float)(y * v12)) + (float)(v43 * v16)) + v50;
  v49 = v9->lightmapVecsLuxelsPerWorldUnits[1].x;
  v18 = (char *)f - (char *)host_state.worldbrush->surfaces2;
  v48 = v9->lightmapVecsLuxelsPerWorldUnits[1].z;
  v19 = (msurfacelighting_t *)((char *)host_state.worldbrush->surfacelighting + (v18 & 0xFFFFFFE0));
  v47 = v9->lightmapVecsLuxelsPerWorldUnits[1].w;
  v42 = v15;
  v20 = v19->m_LightmapMins[0];
  v21 = (float)(v49 * v10) + (float)(v15 * v12);
  pt.x = v10;
  v22 = (float)v20;
  v23 = (float)(v21 + (float)(v48 * v16)) + v47;
  pt.y = v12;
  pt.z = v16;
  if ( (float)v20 > v17 )
    return 0;
  v24 = (float)v19->m_LightmapMins[1];
  v41 = v24;
  if ( v24 > v23 )
    return 0;
  v25 = v19->m_LightmapExtents[0];
  v26 = v17 - v22;
  v27 = v23 - v24;
  v45 = v26;
  dt = v27;
  if ( v25 != 0 || v19->m_LightmapExtents[1] != 0 )
  {
    if ( v26 > (float)v25 || v27 > (float)v19->m_LightmapExtents[1] )
      return 0;
  }
  else
  {
    flags_high = HIBYTE(f->flags);
    v29 = v22;
    lightMaxs[1] = v24;
    v46 = flags_high;
    if ( flags_high != 0 )
    {
      vertexes = host_state.worldbrush->vertexes;
      v31 = &host_state.worldbrush->vertindices[f->firstvertindex];
      do
      {
        v32 = v42 * vertexes[*v31].position.y;
        v33 = v48 * vertexes[*v31].position.z;
        p_x = &vertexes[*v31].position.x;
        v35 = (float)((float)((float)((float)(v49 * *p_x) + v32) + v33) + v47) - v41;
        v36 = (float)((float)((float)((float)(v44 * *p_x) + (float)(y * p_x[1])) + (float)(v43 * p_x[2])) + v50) - v22;
        if ( v36 > v29 )
          v29 = (float)((float)((float)((float)(v44 * vertexes[*v31].position.x) + (float)(y * p_x[1]))
                              + (float)(v43 * p_x[2]))
                      + v50)
              - v22;
        if ( v35 > lightMaxs[1] )
          lightMaxs[1] = (float)((float)((float)((float)(v49 * *p_x) + v32) + v33) + v47) - v41;
        if ( v36 > v29 )
          v29 = v36;
        if ( v35 > lightMaxs[1] )
          lightMaxs[1] = v35;
        ++v31;
        --v46;
      }
      while ( v46 != 0 );
      v26 = v45;
      v27 = dt;
    }
    if ( v26 > v29 || v27 > lightMaxs[1] )
      return 0;
    v7 = state;
  }
  m_pTextureS = statea->m_pTextureS;
  m_pTextureT = statea->m_pTextureT;
  LODWORD(statea->m_HitFrac) = v7;
  ComputeTextureCoordsAtIntersection(pTex: v9, &pt, textureT: m_pTextureT, textureS: m_pTextureS);
  if ( r_avglight.m_pParent != nullptr && r_avglight.m_pParent->m_Value.m_nValue != 0 )
  {
    ComputeLightmapColorFromAverage(bUseLightStyles: statea->m_bUseLightStyles, c: ca, pLighting: v19);
    return 1;
  }
  else
  {
    ComputeLightmapCoordsAtIntersection(
      pLighting: v19,
      lightmapS: statea->m_pLightmapS,
      lightmapT: statea->m_pLightmapT,
      a4: v45,
      dt);
    ComputeLightmapColor(surfID: f, c: ca, ds: (int)v45, (int)dt, bUseLightStyles: statea->m_bUseLightStyles);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CA880
// Name: FindIntersectionSurfaceAtNode
// Source: json
//------------------------------------------------------------------------------
msurface2_t *__cdecl FindIntersectionSurfaceAtNode(mnode_t *node, float t, Vector *c, LightVecState_t *state)
{
  worldbrushdata_t *worldbrush; // edx
  mnode_t *v5; // edi
  msurface2_t *v6; // ecx
  unsigned int flags; // eax
  float v8; // xmm6_4
  float y; // xmm3_4
  float z; // xmm4_4
  int v11; // esi
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm5_4
  float v15; // xmm7_4
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  int v20; // ebx
  float v21; // xmm5_4
  float v22; // xmm5_4
  msurfacelighting_t *v23; // ebx
  int v24; // eax
  float v25; // xmm1_4
  float v26; // xmm5_4
  float v27; // xmm2_4
  __int16 v28; // ax
  float v29; // xmm0_4
  float v30; // xmm1_4
  int flags_high; // eax
  float v32; // xmm6_4
  mvertex_t *vertexes; // edi
  unsigned __int16 *vertindices; // edx
  unsigned __int16 *v35; // edx
  float v36; // xmm3_4
  float v37; // xmm2_4
  float *p_x; // eax
  float v39; // xmm1_4
  float v40; // xmm0_4
  float *m_pTextureT; // edi
  float *m_pTextureS; // ecx
  int numsurfaces; // esi
  Vector pt; // [esp+10h] [ebp-48h] BYREF
  float v46; // [esp+20h] [ebp-38h]
  float v47; // [esp+24h] [ebp-34h]
  float v48; // [esp+28h] [ebp-30h]
  float v49; // [esp+2Ch] [ebp-2Ch]
  float v50; // [esp+30h] [ebp-28h]
  float v51; // [esp+34h] [ebp-24h]
  mvertex_t *v52; // [esp+38h] [ebp-20h]
  float v53; // [esp+3Ch] [ebp-1Ch]
  int i; // [esp+40h] [ebp-18h]
  int j; // [esp+44h] [ebp-14h]
  float v56; // [esp+48h] [ebp-10h]
  float v57; // [esp+4Ch] [ebp-Ch]
  float dt; // [esp+50h] [ebp-8h]
  msurface2_t *surfID; // [esp+54h] [ebp-4h]

  worldbrush = host_state.worldbrush;
  v5 = node;
  v6 = &host_state.worldbrush->surfaces2[node->firstsurface];
  i = 0;
  if ( node->numsurfaces == 0 )
    return nullptr;
  while ( 1 )
  {
    flags = v6->flags;
    if ( (v6->flags & 4) != 0 )
    {
      state->m_nSkySurfID = v6;
      worldbrush = host_state.worldbrush;
      goto LABEL_30;
    }
    if ( (flags & 0x10000) == 0 )
    {
      if ( (flags & 1) != 0 )
        goto LABEL_30;
      v8 = t;
      y = state->m_Ray.m_Delta.y;
      z = state->m_Ray.m_Delta.z;
      v11 = (int)&worldbrush->texinfo[*((unsigned __int16 *)v6 + 11) >> 1];
      v12 = (float)(state->m_Ray.m_Delta.x * t) + state->m_Ray.m_Start.x;
      v13 = *(float *)(v11 + 44);
      v14 = *(float *)(v11 + 40);
      v15 = *(float *)(v11 + 36);
      v51 = *(float *)(v11 + 32);
      *(float *)&surfID = v13;
      v50 = v14;
      v16 = (float)(y * t) + state->m_Ray.m_Start.y;
      v17 = (float)(z * t) + state->m_Ray.m_Start.z;
      v18 = *(float *)(v11 + 52);
      v19 = (float)((float)((float)(v15 * v16) + (float)(v51 * v12)) + (float)(v14 * v17)) + v13;
      v20 = (char *)v6 - (char *)worldbrush->surfaces2;
      v57 = *(float *)(v11 + 48);
      v21 = *(float *)(v11 + 56);
      v49 = v18;
      v56 = v21;
      v22 = *(float *)(v11 + 60);
      v23 = (msurfacelighting_t *)((char *)worldbrush->surfacelighting + (v20 & 0xFFFFFFE0));
      pt.y = v16;
      v24 = v23->m_LightmapMins[0];
      pt.x = v12;
      v48 = v22;
      v25 = (float)((float)((float)(v18 * v16) + (float)(v57 * v12)) + (float)(v56 * v17)) + v22;
      v26 = (float)v24;
      pt.z = v17;
      if ( (float)v24 > v19 )
        goto LABEL_30;
      v27 = (float)v23->m_LightmapMins[1];
      v47 = v27;
      if ( v27 > v25 )
        goto LABEL_30;
      v28 = v23->m_LightmapExtents[0];
      v29 = v19 - v26;
      v30 = v25 - v27;
      v53 = v29;
      dt = v30;
      if ( v28 == 0 && v23->m_LightmapExtents[1] == 0 )
        break;
      if ( v29 <= (float)v28 && v30 <= (float)v23->m_LightmapExtents[1] )
        goto LABEL_25;
    }
LABEL_30:
    numsurfaces = v5->numsurfaces;
    ++v6;
    if ( ++i >= numsurfaces )
      return nullptr;
  }
  flags_high = HIBYTE(v6->flags);
  v32 = v26;
  v46 = v27;
  if ( flags_high != 0 )
  {
    vertexes = worldbrush->vertexes;
    vertindices = worldbrush->vertindices;
    v52 = vertexes;
    v35 = &vertindices[v6->firstvertindex];
    for ( j = flags_high; j != 0; --j )
    {
      v36 = v49 * vertexes[*v35].position.y;
      v37 = v56 * vertexes[*v35].position.z;
      p_x = &vertexes[*v35].position.x;
      v39 = (float)((float)((float)((float)(v57 * *p_x) + v36) + v37) + v48) - v47;
      v40 = (float)((float)((float)((float)(v51 * *p_x) + (float)(v15 * p_x[1])) + (float)(v50 * p_x[2]))
                  + *(float *)&surfID)
          - v26;
      if ( v40 > v32 )
        v32 = (float)((float)((float)((float)(v51 * vertexes[*v35].position.x) + (float)(v15 * p_x[1]))
                            + (float)(v50 * p_x[2]))
                    + *(float *)&surfID)
            - v26;
      if ( v39 > v46 )
        v46 = (float)((float)((float)((float)(v57 * *p_x) + v36) + v37) + v48) - v47;
      if ( v40 > v32 )
        v32 = v40;
      if ( v39 > v46 )
        v46 = v39;
      ++v35;
    }
    v30 = dt;
    v29 = v53;
    worldbrush = host_state.worldbrush;
    v5 = node;
  }
  if ( v29 > v32 || v30 > v46 )
    goto LABEL_30;
  v8 = t;
LABEL_25:
  m_pTextureT = state->m_pTextureT;
  surfID = v6;
  m_pTextureS = state->m_pTextureS;
  state->m_HitFrac = v8;
  ComputeTextureCoordsAtIntersection(pTex: (mtexinfo_t *)v11, &pt, textureT: m_pTextureT, textureS: m_pTextureS);
  if ( r_avglight.m_pParent != nullptr && r_avglight.m_pParent->m_Value.m_nValue != 0 )
  {
    ComputeLightmapColorFromAverage(bUseLightStyles: state->m_bUseLightStyles, c, pLighting: v23);
    return surfID;
  }
  else
  {
    ComputeLightmapCoordsAtIntersection(
      pLighting: v23,
      lightmapS: state->m_pLightmapS,
      lightmapT: state->m_pLightmapT,
      a4: v53,
      dt);
    ComputeLightmapColor(surfID, c, ds: (int)v53, (int)dt, bUseLightStyles: state->m_bUseLightStyles);
    return surfID;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CABD0
// Name: R_LightVecDisplacementChain
// Source: json
//------------------------------------------------------------------------------
msurface2_t *__usercall R_LightVecDisplacementChain@<eax>(
        LightVecState_t *state@<edi>,
        bool bUseLightStyles,
        Vector *c)
{
  msurface2_t *v3; // ebx
  IDispInfo *v4; // esi
  float *m_pLightmapS; // ecx
  float *m_pLightmapT; // esi
  char *v7; // eax
  float y; // xmm0_4
  __int16 v9; // dx
  __int16 v10; // ax
  float *m_pTextureS; // eax
  Vector2D tuv; // [esp+1Ch] [ebp-1Ch] BYREF
  Vector2D luv; // [esp+24h] [ebp-14h] BYREF
  float *v15; // [esp+2Ch] [ebp-Ch]
  float dist; // [esp+30h] [ebp-8h] BYREF
  int i; // [esp+34h] [ebp-4h]

  v3 = nullptr;
  for ( i = 0; i < state->m_LightTestDisps.m_Size; ++i )
  {
    v4 = state->m_LightTestDisps.m_Memory.m_pMemory[i];
    if ( ((unsigned __int8 (__thiscall *)(IDispInfo *, LightVecState_t *, _DWORD, float, float *, Vector2D *, Vector2D *))v4->TestRay)(
           a1: v4,
           a2: state,
           a3: 0.0,
           a4: state->m_HitFrac,
           a5: &dist,
           a6: &luv,
           a7: &tuv) != 0 )
    {
      state->m_HitFrac = dist;
      v3 = v4->GetParent(this: v4);
      ComputeLightmapColor(surfID: v3, c, ds: (int)luv.x, dt: (int)luv.y, bUseLightStyles);
      m_pLightmapS = state->m_pLightmapS;
      if ( m_pLightmapS != nullptr )
      {
        m_pLightmapT = state->m_pLightmapT;
        v15 = m_pLightmapT;
        if ( m_pLightmapT != nullptr )
        {
          v7 = (char *)host_state.worldbrush->surfacelighting
             + (((char *)v3 - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0);
          y = (float)(int)luv.y;
          v9 = *((_WORD *)v7 + 2);
          if ( v9 != 0 )
          {
            m_pLightmapT = v15;
            *m_pLightmapS = (float)((float)(int)luv.x + 0.5) / (float)v9;
          }
          else
          {
            *m_pLightmapS = 0.5;
          }
          v10 = *((_WORD *)v7 + 3);
          if ( v10 != 0 )
            *m_pLightmapT = (float)(y + 0.5) / (float)v10;
          else
            *m_pLightmapT = 0.5;
        }
      }
      m_pTextureS = state->m_pTextureS;
      if ( m_pTextureS != nullptr && state->m_pTextureT != nullptr )
      {
        *m_pTextureS = tuv.x;
        *state->m_pTextureT = tuv.y;
      }
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100CAD20
// Name: AddDisplacementsInLeafToTestList
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddDisplacementsInLeafToTestList(mleaf_t *pLeaf, LightVecState_t *state)
{
  mleaf_t *v2; // ecx
  int v3; // eax
  IDispInfo *v4; // ebx
  int v5; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  IDispInfo **m_pMemory; // ecx
  int v9; // eax
  IDispInfo **v10; // edi
  int i; // [esp+0h] [ebp-4h]

  v2 = pLeaf;
  v3 = 0;
  i = 0;
  if ( pLeaf->dispCount != 0 )
  {
    do
    {
      v4 = DispInfo_IndexArray(
             hArray: (_DWORD *)host_state.worldbrush->hDispInfos,
             iElement: host_state.worldbrush->m_pDispInfoReferences[v3 + v2->dispListStart]);
      v5 = (int)v4->GetParent(this: v4);
      if ( *(_DWORD *)(v5 + 28) != r_surfacevisframe )
      {
        *(_DWORD *)(v5 + 28) = r_surfacevisframe;
        m_Size = state->m_LightTestDisps.m_Size;
        m_nAllocationCount = state->m_LightTestDisps.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<INetMessage *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)&state->m_LightTestDisps,
            num: m_Size - m_nAllocationCount + 1);
        ++state->m_LightTestDisps.m_Size;
        m_pMemory = state->m_LightTestDisps.m_Memory.m_pMemory;
        v9 = state->m_LightTestDisps.m_Size - m_Size - 1;
        state->m_LightTestDisps.m_pElements = m_pMemory;
        if ( v9 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
        v10 = &state->m_LightTestDisps.m_Memory.m_pMemory[m_Size];
        if ( v10 != nullptr )
          *v10 = v4;
      }
      v2 = pLeaf;
      v3 = i + 1;
      i = v3;
    }
    while ( v3 < pLeaf->dispCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CADF0
// Name: FindIntersectionSurfaceAtLeaf
// Source: json
//------------------------------------------------------------------------------
msurface2_t *__userpurge FindIntersectionSurfaceAtLeaf@<eax>(
        LightVecState_t *state@<esi>,
        mleaf_t *pLeaf,
        float start,
        float end,
        Vector *c)
{
  int nummarknodesurfaces; // ebx
  msurface2_t *v6; // edi
  float *p_x; // eax
  float y; // xmm1_4
  float z; // xmm3_4
  float v10; // xmm6_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm3_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  LightVecState_t *v18; // [esp+8h] [ebp-14h]
  msurface2_t **pHandle; // [esp+14h] [ebp-8h]
  msurface2_t *closestSurfID; // [esp+18h] [ebp-4h]

  closestSurfID = nullptr;
  AddDisplacementsInLeafToTestList(pLeaf, state: v18);
  nummarknodesurfaces = pLeaf->nummarknodesurfaces;
  for ( pHandle = &host_state.worldbrush->marksurfaces[pLeaf->firstmarksurface];
        nummarknodesurfaces < pLeaf->nummarksurfaces;
        ++nummarknodesurfaces )
  {
    v6 = pHandle[nummarknodesurfaces];
    if ( (v6->flags & 0x800) == 0 && (v6->flags & 0x10012) == 0 )
    {
      p_x = &v6->plane->normal.x;
      y = state->m_Ray.m_Delta.y;
      z = state->m_Ray.m_Delta.z;
      v10 = *p_x * state->m_Ray.m_Delta.x;
      if ( (float)((float)((float)(p_x[1] * y) + v10) + (float)(p_x[2] * z)) <= 0.0 )
      {
        v11 = (float)((float)(state->m_Ray.m_Start.y * p_x[1]) + (float)(*p_x * state->m_Ray.m_Start.x))
            + (float)(state->m_Ray.m_Start.z * p_x[2]);
        v12 = (float)((float)(y * p_x[1]) + v10) + (float)(z * p_x[2]);
        v13 = p_x[3];
        v14 = (float)((float)(v12 * start) + v11) - v13;
        v15 = (float)((float)(v12 * end) + v11) - v13;
        if ( v15 < 0.0 != v14 < 0.0 )
        {
          v16 = v14 / (float)(v14 - v15);
          if ( v16 < state->m_HitFrac
            && FindIntersectionAtSurface(
                 f: v6,
                 state: COERCE_LIGHTVECSTATE_T_((float)((float)(1.0 - v16) * start) + (float)(v16 * end)),
                 ca: c,
                 statea: state) != 0 )
          {
            closestSurfID = v6;
          }
        }
      }
    }
  }
  return closestSurfID;
}

//------------------------------------------------------------------------------
// Address: 0x100CAF70
// Name: struct msurface2_t __near * RecursiveLightPoint(struct mnode_t __near *,float,float,class Vector __near &,struct LightVecState_t __near &)
// Source: json
//------------------------------------------------------------------------------
msurface2_t *__cdecl RecursiveLightPoint(mleaf_t *node, float start, float end, Vector *c, LightVecState_t *state)
{
  msurface2_t *result; // eax
  cplane_t *v7; // eax
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  int v12; // ecx
  float mid; // [esp+1Ch] [ebp-4h]
  int side; // [esp+28h] [ebp+8h]

  if ( node->contents >= 0 )
    return FindIntersectionSurfaceAtLeaf(state, pLeaf: node, start, end, c);
  v7 = *(cplane_t **)&node->cluster;
  v8 = (float)((float)(state->m_Ray.m_Start.y * v7->normal.y) + (float)(v7->normal.x * state->m_Ray.m_Start.x))
     + (float)(state->m_Ray.m_Start.z * v7->normal.z);
  v9 = (float)((float)(state->m_Ray.m_Delta.y * v7->normal.y) + (float)(v7->normal.x * state->m_Ray.m_Delta.x))
     + (float)(state->m_Ray.m_Delta.z * v7->normal.z);
  v10 = (float)((float)(v9 * start) + v8) - v7->dist;
  v11 = (float)((float)(v9 * end) + v8) - v7->dist;
  if ( v10 >= 0.0 )
  {
    side = 0;
    v12 = 0;
  }
  else
  {
    v12 = 1;
    side = 1;
  }
  if ( v11 < 0.0 == v12 )
    return RecursiveLightPoint(node: *((mnode_t **)&node->firstmarksurface + v12), start, end, c, state);
  mid = (float)((float)(1.0 - (float)(v10 / (float)(v10 - v11))) * start)
      + (float)((float)(v10 / (float)(v10 - v11)) * end);
  result = RecursiveLightPoint(node: *((mnode_t **)&node->firstmarksurface + side), start, end: mid, c, state);
  if ( result == nullptr )
  {
    result = FindIntersectionSurfaceAtNode((mnode_t *)node, t: mid, c, state);
    if ( result == nullptr )
      return RecursiveLightPoint(node: *((mnode_t **)&node->firstmarksurface + (side == 0)), start: mid, end, c, state);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100CB100
// Name: struct msurface2_t __near * R_LightVec(class Vector const __near &,class Vector const __near &,bool,class Vector __near &,float __near *,float __near *,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
msurface2_t *__usercall R_LightVec@<eax>(
        int a1@<ebp>,
        const Vector *start,
        const Vector *end,
        bool bUseLightStyles,
        Vector *c,
        float *textureS,
        float *textureT,
        float *lightmapS,
        float *lightmapT)
{
  float y; // xmm1_4
  float x; // xmm3_4
  float v11; // xmm4_4
  float z; // xmm2_4
  float v13; // xmm5_4
  float v14; // xmm0_4
  model_t *worldmodel; // eax
  msurface2_t *v16; // edi
  int v17; // xmm4_4
  float v18; // xmm5_4
  float *m_pTextureT; // esi
  _DWORD v21[3]; // [esp+28h] [ebp-9Ch] BYREF
  LightVecState_t state; // [esp+34h] [ebp-90h] BYREF
  msurface2_t *v23; // [esp+B4h] [ebp-10h]
  int v24; // [esp+B8h] [ebp-Ch]
  void *v25; // [esp+BCh] [ebp-8h]
  void *retaddr; // [esp+C4h] [ebp+0h]

  v24 = a1;
  v25 = retaddr;
  if ( (_S1_7 & 1) == 0 )
  {
    _S1_7 |= 1u;
    counter.m_pCounter = CVProfile::FindOrCreateCounter(
                           this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                           a2: "R_LightVec",
                           a3: COUNTER_GROUP_DEFAULT);
    atexit(func: R_LightVec_::_4_::_dynamic_atexit_destructor_for___counter__);
  }
  ++*counter.m_pCounter;
  ++r_surfacevisframe;
  y = end->y;
  x = start->x;
  v11 = start->y;
  z = end->z;
  v13 = start->z;
  *(_DWORD *)&state.m_Ray.m_IsRay = 1065353216;
  v14 = end->x - x;
  state.m_Ray.m_Start.z = y - v11;
  state.m_Ray.m_Start.y = v14;
  state.m_Ray.m_Start.w = z - v13;
  memset(&state.m_pLightmapT, 0, 20);
  BYTE1(state.m_Ray.m_Extents.z) = (float)((float)((float)(state.m_Ray.m_Start.z * state.m_Ray.m_Start.z)
                                                 + (float)(v14 * v14))
                                         + (float)(state.m_Ray.m_Start.w * state.m_Ray.m_Start.w)) != 0.0;
  *(_DWORD *)(&state.m_Ray.m_IsSwept + 3) = textureS;
  LODWORD(state.m_HitFrac) = lightmapS;
  LOBYTE(state.m_Ray.m_Extents.z) = 1;
  LOBYTE(state.m_pLightmapS) = bUseLightStyles;
  worldmodel = s_pLightVecModel;
  *(_DWORD *)(&state.m_Ray.m_IsSwept + 7) = textureT;
  memset(&state.m_Ray.m_StartOffset.y, 0, 12);
  state.m_Ray.m_Extents.y = 0.0;
  memset(&state.m_Ray.m_Delta.y, 0, 12);
  *(float *)v21 = x;
  *(float *)&v21[1] = v11;
  *(float *)&v21[2] = v13;
  state.m_pTextureS = lightmapT;
  state.m_pTextureT = nullptr;
  c->z = 0.0;
  c->y = 0.0;
  c->x = 0.0;
  if ( worldmodel == nullptr )
    worldmodel = host_state.worldmodel;
  v23 = RecursiveLightPoint(
          node: (mleaf_t *)(*(_DWORD *)(worldmodel->sprite.numframes + 84) + (worldmodel->brush.firstnode << 6)),
          start: 0.0,
          end: 1.0,
          c,
          state: (LightVecState_t *)v21);
  v16 = R_LightVecDisplacementChain(state: (LightVecState_t *)v21, bUseLightStyles, c);
  if ( r_visualizelighttraces.m_pParent != nullptr && r_visualizelighttraces.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( r_visualizelighttracesshowfulltrace.m_pParent != nullptr
      && r_visualizelighttracesshowfulltrace.m_pParent->m_Value.m_nValue != 0 )
    {
      CDebugOverlay::AddLineOverlay(
        origin: start,
        dest: end,
        r: 0,
        g: 255,
        b: 0,
        a: 255,
        noDepthTest: true,
        flDuration: -1.0);
    }
    else
    {
      *(float *)&v17 = start->y + (float)((float)(end->y - start->y) * *(float *)&state.m_Ray.m_IsRay);
      v18 = start->z + (float)((float)(end->z - start->z) * *(float *)&state.m_Ray.m_IsRay);
      *(float *)&state.m_LightTestDisps.m_Memory.m_nGrowSize = start->x
                                                             + (float)((float)(end->x - start->x)
                                                                     * *(float *)&state.m_Ray.m_IsRay);
      state.m_LightTestDisps.m_Size = v17;
      *(float *)&state.m_LightTestDisps.m_pElements = v18;
      CDebugOverlay::AddLineOverlay(
        origin: start,
        dest: (const Vector *)&state.m_LightTestDisps.m_Memory.m_nGrowSize,
        r: 0,
        g: 255,
        b: 0,
        a: 255,
        noDepthTest: true,
        flDuration: -1.0);
    }
  }
  if ( v16 != nullptr || (v16 = v23, v23 != nullptr) || (m_pTextureT = state.m_pTextureT, state.m_pTextureT == nullptr) )
  {
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&state.m_pLightmapT);
    return v16;
  }
  else
  {
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&state.m_pLightmapT);
    return (msurface2_t *)m_pTextureT;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CB3B0
// Name: struct colorVec R_LightPoint(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
colorVec *__cdecl R_LightPoint(colorVec *result, Vector *p)
{
  int v2; // eax
  int v3; // eax
  float f; // [esp+0h] [ebp-20h]
  float fa; // [esp+0h] [ebp-20h]
  Vector color; // [esp+8h] [ebp-18h] BYREF
  Vector end; // [esp+14h] [ebp-Ch] BYREF
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  end.x = p->x;
  end.y = p->y;
  end.z = p->z - 2048.0;
  if ( R_LightVec(
         a1: (int)&savedregs,
         start: p,
         &end,
         bUseLightStyles: true,
         c: &color,
         textureS: nullptr,
         textureT: nullptr,
         lightmapS: nullptr,
         lightmapT: nullptr) != nullptr )
  {
    v2 = LinearToScreenGamma(f: color.x);
    f = color.y;
    result->r = 255 * v2;
    v3 = LinearToScreenGamma(f);
    fa = color.z;
    result->g = 255 * v3;
    result->b = 255 * LinearToScreenGamma(f: fa);
    result->a = 1;
    return result;
  }
  else
  {
    result->a = 0;
    result->b = 0;
    result->g = 0;
    result->r = 0;
    return result;
  }
}

} // namespace engine_xlsp
