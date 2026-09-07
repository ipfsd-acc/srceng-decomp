// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/gl_matsysiface.cpp
// Functions: 29
// ============================================================

#include "engine\gl_matsysiface.h"

//------------------------------------------------------------------------------
// Address: 0x100C7350
// Name: int SortMapCompareFunc(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SortMapCompareFunc(const void *pElem0, const void *pElem1)
{
  return pSortMapRenderContext->CompareMaterialCombos(
           this: pSortMapRenderContext,
           a2: *(IMaterial **)pElem0,
           a3: *(IMaterial **)pElem1,
           a4: *((_DWORD *)pElem0 + 1),
           a5: *((_DWORD *)pElem1 + 1));
}

//------------------------------------------------------------------------------
// Address: 0x100C7380
// Name: void MaterialSystem_RegisterPaintSurfaces(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MaterialSystem_RegisterPaintSurfaces()
{
  CPaintmapDataManager *v0; // eax

  v0 = nullptr;
  if ( g_PaintManager.m_bShouldRegister )
    v0 = &g_PaintManager;
  materials->RegisterPaintmapDataManager(this: materials, a2: v0);
}

//------------------------------------------------------------------------------
// Address: 0x100C73B0
// Name: void ForceMatSysRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ForceMatSysRestore()
{
  ReleaseMaterialSystemObjects(nChangeFlags: 0);
  RestoreMaterialSystemObjects(nChangeFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100C73D0
// Name: LightmapLess
// Source: json
//------------------------------------------------------------------------------
bool __cdecl LightmapLess(msurface2_t *const *surfID1, msurface2_t *const *surfID2)
{
  unsigned __int8 v2; // al
  unsigned __int8 v3; // cl
  bool v4; // cf
  mtexinfo_t *texinfo; // edx
  IMaterial *material; // ecx
  IMaterial *v8; // esi
  int v9; // edi
  int v10; // eax
  unsigned __int8 v11; // cl
  unsigned __int8 v12; // dl
  msurface2_t *surfaces2; // ecx
  msurfacelighting_t *surfacelighting; // edx

  v2 = (**(_BYTE **)surfID1 & 1) == 0;
  v3 = (**(_BYTE **)surfID2 & 1) == 0;
  v4 = v3 < v2;
  if ( v3 != v2 )
    return v4;
  texinfo = host_state.worldbrush->texinfo;
  material = texinfo[*((unsigned __int16 *)*surfID1 + 11) >> 1].material;
  v8 = texinfo[*((unsigned __int16 *)*surfID2 + 11) >> 1].material;
  v9 = material->GetEnumerationID(this: material);
  v10 = v8->GetEnumerationID(this: v8);
  if ( v9 != v10 )
    return v9 < v10;
  v11 = (**(_DWORD **)surfID1 & 0x400) == 0;
  v12 = (**(_DWORD **)surfID2 & 0x400) == 0;
  v4 = v12 < v11;
  if ( v12 != v11 )
    return v4;
  surfaces2 = host_state.worldbrush->surfaces2;
  surfacelighting = host_state.worldbrush->surfacelighting;
  return *(__int16 *)((char *)surfacelighting->m_LightmapExtents + (((char *)*surfID2 - (char *)surfaces2) & 0xFFFFFFE0))
       * *(__int16 *)((char *)&surfacelighting->m_LightmapExtents[1]
                    + (((char *)*surfID2 - (char *)surfaces2) & 0xFFFFFFE0)) < *(__int16 *)((char *)surfacelighting->m_LightmapExtents
                                                                                          + (((char *)*surfID1
                                                                                            - (char *)surfaces2)
                                                                                           & 0xFFFFFFE0))
                                                                             * *(__int16 *)((char *)&surfacelighting->m_LightmapExtents[1]
                                                                                          + (((char *)*surfID1
                                                                                            - (char *)surfaces2)
                                                                                           & 0xFFFFFFE0));
}

//------------------------------------------------------------------------------
// Address: 0x100C74B0
// Name: GenerateTexCoordsForPrimVerts
// Source: json
//------------------------------------------------------------------------------
int GenerateTexCoordsForPrimVerts()
{
  worldbrushdata_t *worldbrush; // ecx
  int result; // eax
  msurface2_t *v2; // edi
  int i; // esi
  unsigned int flags; // eax
  bool v5; // zf
  bool v6; // dl
  unsigned __int16 numPrims; // ax
  unsigned __int16 firstPrimID; // ax
  int v9; // ebx
  IMaterialSystem_vtbl *v10; // esi
  int v11; // eax
  float v12; // xmm0_4
  __int16 *v13; // eax
  int v14; // edx
  float v15; // xmm1_4
  int v16; // edx
  int v17; // eax
  float v18; // xmm0_4
  int v19; // esi
  int v20; // edx
  IMaterial *material; // ecx
  int v22; // ecx
  IMaterial *v23; // ecx
  float v24; // xmm0_4
  int v25; // edx
  float v26; // xmm0_4
  float v27; // xmm0_4
  int v28; // ecx
  float v29; // xmm0_4
  float v30; // xmm0_4
  int v31; // eax
  bool v32; // cc
  int v33; // edx
  int lightmapPageSize[2]; // [esp+0h] [ebp-2Ch] BYREF
  float tScale; // [esp+8h] [ebp-24h]
  float sScale; // [esp+Ch] [ebp-20h]
  int surfaceIndex; // [esp+10h] [ebp-1Ch]
  int j; // [esp+14h] [ebp-18h]
  int k; // [esp+18h] [ebp-14h]
  float tOffset; // [esp+1Ch] [ebp-10h]
  float sOffset; // [esp+20h] [ebp-Ch]
  unsigned int v42; // [esp+24h] [ebp-8h]
  int l; // [esp+28h] [ebp-4h]

  worldbrush = host_state.worldbrush;
  result = 0;
  surfaceIndex = 0;
  if ( host_state.worldbrush->numsurfaces > 0 )
  {
    v42 = 0;
    do
    {
      v2 = &worldbrush->surfaces2[v42 / 0x20];
      for ( i = 0; ; ++i )
      {
        flags = v2->flags;
        v6 = (v2->flags & 0x800) != 0;
        v5 = (v2->flags & 0x800) == 0;
        j = i;
        if ( v5 && (flags & 0x8000) != 0 )
          numPrims = worldbrush->surfaces1[v2 - worldbrush->surfaces2].prims.numPrims;
        else
          numPrims = 0;
        if ( i >= numPrims )
          break;
        if ( v6 )
          firstPrimID = 0;
        else
          firstPrimID = worldbrush->surfaces1[v2 - worldbrush->surfaces2].prims.firstPrimID;
        v9 = (int)&worldbrush->primitives[i + firstPrimID];
        k = 0;
        if ( *(_WORD *)(v9 + 10) != 0 )
        {
          do
          {
            v10 = materials->__vftable;
            v11 = SortInfoToLightmapPage(sortID: v2->materialSortID);
            v10->GetLightmapPageSize(this: materials, a2: v11, a3: lightmapPageSize, a4: &lightmapPageSize[1]);
            worldbrush = host_state.worldbrush;
            v12 = 1.0 / (float)lightmapPageSize[0];
            v13 = (__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapMins
                            + (((char *)v2 - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
            l = 0;
            v14 = v13[2];
            sOffset = (float)v13[4] * v12;
            v15 = (float)v14;
            v16 = v13[5];
            v17 = v13[3];
            sScale = v15 * v12;
            v18 = 1.0 / (float)lightmapPageSize[1];
            tOffset = (float)v16 * v18;
            tScale = (float)v17 * v18;
            if ( *(_WORD *)(v9 + 10) != 0 )
            {
              do
              {
                v19 = (int)&worldbrush->primverts[l + *(unsigned __int16 *)(v9 + 8)];
                v20 = *((unsigned __int16 *)v2 + 11) >> 1;
                *(float *)(v19 + 12) = (float)((float)((float)(worldbrush->texinfo[v20].textureVecsTexelsPerWorldUnits[0].y
                                                             * *(float *)(v19 + 4))
                                                     + (float)(worldbrush->texinfo[v20].textureVecsTexelsPerWorldUnits[0].x
                                                             * *(float *)v19))
                                             + (float)(worldbrush->texinfo[v20].textureVecsTexelsPerWorldUnits[0].z
                                                     * *(float *)(v19 + 8)))
                                     + worldbrush->texinfo[v20].textureVecsTexelsPerWorldUnits[0].w;
                material = host_state.worldbrush->texinfo[*((unsigned __int16 *)v2 + 11) >> 1].material;
                *(float *)(v19 + 12) = *(float *)(v19 + 12) / (float)material->GetMappingWidth(this: material);
                v22 = *((unsigned __int16 *)v2 + 11) >> 1;
                *(float *)(v19 + 16) = (float)((float)((float)(host_state.worldbrush->texinfo[v22].textureVecsTexelsPerWorldUnits[1].y
                                                             * *(float *)(v19 + 4))
                                                     + (float)(host_state.worldbrush->texinfo[v22].textureVecsTexelsPerWorldUnits[1].x
                                                             * *(float *)v19))
                                             + (float)(host_state.worldbrush->texinfo[v22].textureVecsTexelsPerWorldUnits[1].z
                                                     * *(float *)(v19 + 8)))
                                     + host_state.worldbrush->texinfo[v22].textureVecsTexelsPerWorldUnits[1].w;
                v23 = host_state.worldbrush->texinfo[*((unsigned __int16 *)v2 + 11) >> 1].material;
                *(float *)(v19 + 16) = *(float *)(v19 + 16) / (float)v23->GetMappingHeight(this: v23);
                if ( (v2->flags & 1) != 0 )
                {
                  v24 = 0.5;
                  *(_DWORD *)(v19 + 20) = 1056964608;
                }
                else if ( *(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapExtents
                                     + (((char *)v2 - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0)) != 0 )
                {
                  v25 = *((unsigned __int16 *)v2 + 11) >> 1;
                  v26 = (float)((float)((float)(host_state.worldbrush->texinfo[v25].lightmapVecsLuxelsPerWorldUnits[0].y
                                              * *(float *)(v19 + 4))
                                      + (float)(host_state.worldbrush->texinfo[v25].lightmapVecsLuxelsPerWorldUnits[0].x
                                              * *(float *)v19))
                              + (float)(host_state.worldbrush->texinfo[v25].lightmapVecsLuxelsPerWorldUnits[0].z
                                      * *(float *)(v19 + 8)))
                      + host_state.worldbrush->texinfo[v25].lightmapVecsLuxelsPerWorldUnits[0].w;
                  *(float *)(v19 + 20) = v26;
                  v27 = (float)(v26
                              - (float)*(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapMins
                                                  + (((char *)v2 - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0)))
                      + 0.5;
                  *(float *)(v19 + 20) = v27;
                  *(float *)(v19 + 20) = v27
                                       / (float)*(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapExtents
                                                           + (((char *)v2 - (char *)host_state.worldbrush->surfaces2)
                                                            & 0xFFFFFFE0));
                  v28 = *((unsigned __int16 *)v2 + 11) >> 1;
                  v29 = (float)((float)((float)(host_state.worldbrush->texinfo[v28].lightmapVecsLuxelsPerWorldUnits[1].y
                                              * *(float *)(v19 + 4))
                                      + (float)(host_state.worldbrush->texinfo[v28].lightmapVecsLuxelsPerWorldUnits[1].x
                                              * *(float *)v19))
                              + (float)(host_state.worldbrush->texinfo[v28].lightmapVecsLuxelsPerWorldUnits[1].z
                                      * *(float *)(v19 + 8)))
                      + host_state.worldbrush->texinfo[v28].lightmapVecsLuxelsPerWorldUnits[1].w;
                  *(float *)(v19 + 24) = v29;
                  v30 = (float)(v29
                              - (float)*(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_LightmapMins[1]
                                                  + (((char *)v2 - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0)))
                      + 0.5;
                  *(float *)(v19 + 24) = v30;
                  *(float *)(v19 + 24) = v30
                                       / (float)*(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_LightmapExtents[1]
                                                           + (((char *)v2 - (char *)host_state.worldbrush->surfaces2)
                                                            & 0xFFFFFFE0));
                  *(float *)(v19 + 20) = (float)(*(float *)(v19 + 20) * sScale) + sOffset;
                  v24 = (float)(*(float *)(v19 + 24) * tScale) + tOffset;
                }
                else
                {
                  *(float *)(v19 + 20) = sOffset;
                  v24 = tOffset;
                }
                v31 = l;
                *(float *)(v19 + 24) = v24;
                v32 = ++v31 < *(unsigned __int16 *)(v9 + 10);
                worldbrush = host_state.worldbrush;
                l = v31;
              }
              while ( v32 );
            }
            v33 = *(unsigned __int16 *)(v9 + 10);
            ++k;
          }
          while ( k < v33 );
          i = j;
        }
      }
      v42 += 32;
      result = surfaceIndex + 1;
      surfaceIndex = result;
    }
    while ( result < worldbrush->numsurfaces );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C7930
// Name: bool SurfHasBumpedLightmaps(struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl SurfHasBumpedLightmaps(msurface2_t *surfID)
{
  bool result; // al

  result = false;
  if ( (host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1].flags & 0x800) != 0
    && (host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1].flags & 0x400) == 0
    && host_state.worldbrush->lightdata != nullptr )
  {
    return *(_DWORD *)&host_state.worldbrush->surfacelighting->m_nStyles[(((char *)surfID
                                                                         - (char *)host_state.worldbrush->surfaces2)
                                                                        & 0xFFFFFFE0)
                                                                       + 4] != 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C7990
// Name: bool SurfNeedsBumpedLightmaps(struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl SurfNeedsBumpedLightmaps(msurface2_t *surfID)
{
  IMaterial *material; // ecx

  material = host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1].material;
  return material->GetPropertyFlag(this: material, a2: MATERIAL_PROPERTY_NEEDS_BUMPED_LIGHTMAPS);
}

//------------------------------------------------------------------------------
// Address: 0x100C79C0
// Name: bool SurfHasLightmap(struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl SurfHasLightmap(msurface2_t *surfID)
{
  bool result; // al

  result = false;
  if ( (host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1].flags & 0x400) == 0
    && host_state.worldbrush->lightdata != nullptr )
  {
    return *(_DWORD *)&host_state.worldbrush->surfacelighting->m_nStyles[(((char *)surfID
                                                                         - (char *)host_state.worldbrush->surfaces2)
                                                                        & 0xFFFFFFE0)
                                                                       + 4] != 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C7A10
// Name: bool SurfNeedsLightmap(struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl SurfNeedsLightmap(msurface2_t *surfID)
{
  mtexinfo_t *v1; // eax

  v1 = &host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1];
  return (v1->flags & 0x400) == 0
      && v1->material->GetPropertyFlag(this: v1->material, a2: MATERIAL_PROPERTY_NEEDS_LIGHTMAP);
}

//------------------------------------------------------------------------------
// Address: 0x100C7A50
// Name: void BuildMSurfacePrimIndices(struct worldbrushdata_t __near *,struct mprimitive_t __near *,class CMeshBuilder __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildMSurfacePrimIndices(worldbrushdata_t *pBrushData, mprimitive_t *prim, CMeshBuilder *builder)
{
  int v3; // esi
  int m_nCurrentIndex; // edx

  v3 = 0;
  if ( prim->indexCount != 0 )
  {
    do
    {
      builder->m_IndexBuilder.m_pIndices[builder->m_IndexBuilder.m_nCurrentIndex] = LOWORD(builder->m_IndexBuilder.m_nIndexOffset)
                                                                                  + pBrushData->primindices[v3 + prim->firstIndex]
                                                                                  - prim->firstVert;
      builder->m_IndexBuilder.m_nCurrentIndex += builder->m_IndexBuilder.m_nIndexSize;
      m_nCurrentIndex = builder->m_IndexBuilder.m_nCurrentIndex;
      if ( m_nCurrentIndex > builder->m_IndexBuilder.m_nIndexCount )
        builder->m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
      ++v3;
    }
    while ( v3 < prim->indexCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C7AD0
// Name: void BuildBrushModelVertexArray(struct worldbrushdata_t __near *,struct msurface2_t __near *,struct BrushVertex_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildBrushModelVertexArray(worldbrushdata_t *pBrushData, int surfID, BrushVertex_t *pVerts)
{
  bool v4; // zf
  float *p_z; // esi
  mvertex_t *v6; // edi
  int v7; // edi
  Vector *v8; // eax
  SurfaceCtx_t ctx; // [esp+4h] [ebp-4Ch] BYREF
  Vector tVect; // [esp+28h] [ebp-28h] BYREF
  Vector tangentT; // [esp+34h] [ebp-1Ch] BYREF
  Vector tangentS; // [esp+40h] [ebp-10h] BYREF
  BOOL negate; // [esp+4Ch] [ebp-4h]
  int i; // [esp+5Ch] [ebp+Ch]

  SurfSetupSurfaceContext(&ctx, (msurface2_t *)surfID);
  v4 = (*(_DWORD *)surfID & 0x100) == 0;
  LOBYTE(negate) = 0;
  if ( !v4 )
    LOBYTE(negate) = TangentSpaceSurfaceSetup((msurface2_t *)surfID, &tVect);
  i = 0;
  if ( *(_BYTE *)(surfID + 3) != 0 )
  {
    p_z = &pVerts->m_Normal.z;
    do
    {
      v6 = &pBrushData->vertexes[pBrushData->vertindices[i + *(_DWORD *)(surfID + 8)]];
      *(p_z - 5) = v6->position.x;
      *(p_z - 4) = v6->position.y;
      *(p_z - 3) = v6->position.z;
      SurfComputeTextureCoordinate((msurface2_t *)surfID, vec: &v6->position, pUV: p_z + 7);
      SurfComputeLightmapCoordinate(&ctx, (msurface2_t *)surfID, vec: &v6->position, uv: (Vector2D *)(p_z + 9));
      v7 = i;
      v8 = &pBrushData->vertnormals[pBrushData->vertnormalindices[i
                                                                + host_state.worldbrush->surfacenormals[(signed int)(surfID - (unsigned int)host_state.worldbrush->surfaces2) >> 5].firstvertnormal]];
      *(p_z - 2) = v8->x;
      *(p_z - 1) = v8->y;
      *p_z = v8->z;
      if ( (*(_DWORD *)surfID & 0x100) != 0 )
      {
        TangentSpaceComputeBasis(&tangentS, &tangentT, normal: v8, &tVect, negateTangent: negate);
        *(Vector *)(p_z + 1) = tangentS;
        *(Vector *)(p_z + 4) = tangentT;
      }
      p_z += 16;
      ++i;
    }
    while ( v7 + 1 < *(unsigned __int8 *)(surfID + 3) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C7C20
// Name: class IMaterial __near * GetMaterialAtCrossHair(void)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__cdecl GetMaterialAtCrossHair()
{
  msurface2_t *v0; // eax
  Vector lightmapColor; // [esp+0h] [ebp-18h] BYREF
  Vector endPoint; // [esp+Ch] [ebp-Ch] BYREF

  endPoint.x = (float)(g_MainViewForward[0].x * 57016.32) + g_MainViewOrigin[0].x;
  endPoint.y = (float)(*(float *)&dword_104F1BF8 * 57016.32) + g_MainViewOrigin[0].y;
  endPoint.z = (float)(*(float *)&dword_104F1BFC * 57016.32) + g_MainViewOrigin[0].z;
  v0 = R_LightVec(
         start: g_MainViewOrigin,
         end: &endPoint,
         bUseLightStyles: false,
         c: &lightmapColor,
         textureS: nullptr,
         textureT: nullptr,
         lightmapS: nullptr,
         lightmapT: nullptr);
  if ( v0 != nullptr )
    return host_state.worldbrush->texinfo[*((unsigned __int16 *)v0 + 11) >> 1].material;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100C7CC0
// Name: mat_edit
// Source: json
//------------------------------------------------------------------------------
void __usercall mat_edit(int a1@<ebx>, int a2@<edi>, const CCommand *args)
{
  IMaterial *MaterialAtCrossHair; // eax
  const char *v4; // eax
  IMaterial *v5; // esi
  IToolSystem *v6; // ebx
  const char *v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  const char *v10; // eax

  if ( toolframework->InToolMode(this: toolframework) )
  {
    if ( args->m_nArgc >= 2 )
    {
      v4 = defaultValue;
      if ( args->m_nArgc > 1 )
        v4 = args->m_ppArgv[1];
      MaterialAtCrossHair = materials->FindMaterial(this: materials, a2: v4, a3: "edited materials", a4: 0, a5: 0);
    }
    else
    {
      MaterialAtCrossHair = GetMaterialAtCrossHair();
    }
    v5 = MaterialAtCrossHair;
    if ( MaterialAtCrossHair != nullptr )
    {
      v6 = toolframework->SwitchToTool(this: toolframework, a2: "Material Editor");
      if ( v6 != nullptr )
      {
        v7 = (const char *)((int (__thiscall *)(IMaterial *, int, int))v5->GetName)(a1: v5, a2, a3: a1);
        ConMsg(a1: "editing material \"%s\"\n", v7);
        v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v8 != nullptr )
          v9 = KeyValues::KeyValues(this: v8, setName: "EditMaterial");
        else
          v9 = nullptr;
        v10 = (const char *)v5->GetName(this: v5);
        KeyValues::SetString(this: v9, keyName: "material", value: v10);
        v6->PostToolMessage(this: v6, a2: 0, a3: v9);
        KeyValues::deleteThis(this: v9);
      }
    }
    else
    {
      ConMsg(a1: "no/bad material\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C7DB0
// Name: mat_crosshair
// Source: json
//------------------------------------------------------------------------------
void __cdecl mat_crosshair()
{
  IMaterial *MaterialAtCrossHair; // eax
  const char *v1; // eax

  MaterialAtCrossHair = GetMaterialAtCrossHair();
  if ( MaterialAtCrossHair != nullptr )
  {
    v1 = (const char *)MaterialAtCrossHair->GetName(this: MaterialAtCrossHair);
    ConMsg(a1: "hit material \"%s\"\n", v1);
  }
  else
  {
    ConMsg(a1: "no/bad material\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C7DE0
// Name: mat_crosshair_explorer
// Source: json
//------------------------------------------------------------------------------
void __cdecl mat_crosshair_explorer()
{
  IMaterial *MaterialAtCrossHair; // esi
  const char *v1; // eax
  const char *v2; // eax
  char params[256]; // [esp+4h] [ebp-300h] BYREF
  char chResolveName[256]; // [esp+104h] [ebp-200h] BYREF
  char chResolveNameArg[256]; // [esp+204h] [ebp-100h] BYREF

  MaterialAtCrossHair = GetMaterialAtCrossHair();
  if ( MaterialAtCrossHair != nullptr )
  {
    memset(chResolveName, 0, sizeof(chResolveName));
    memset(chResolveNameArg, 0, sizeof(chResolveNameArg));
    v1 = (const char *)MaterialAtCrossHair->GetName(this: MaterialAtCrossHair);
    V_snprintf(pDest: chResolveNameArg, maxLen: 255, pFormat: "materials/%s.vmt", v1);
    v2 = g_pFileSystem->RelativePathToFullPath(
           this: g_pFileSystem,
           a2: chResolveNameArg,
           a3: "game",
           a4: chResolveName,
           a5: 255,
           a6: 0,
           a7: 0);
    V_snprintf(pDest: params, maxLen: 255, pFormat: "/E,/SELECT,%s", v2);
    g_pVGuiSystem->ShellExecuteEx(this: g_pVGuiSystem, a2: "open", a3: "explorer.exe", a4: params);
  }
  else
  {
    ConMsg(a1: "no/bad material\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C7ED0
// Name: mat_crosshair_reloadmaterial
// Source: json
//------------------------------------------------------------------------------
void __cdecl mat_crosshair_reloadmaterial()
{
  IMaterial *MaterialAtCrossHair; // eax
  IMaterialSystem_vtbl *v1; // esi
  int v2; // eax

  MaterialAtCrossHair = GetMaterialAtCrossHair();
  if ( MaterialAtCrossHair != nullptr )
  {
    v1 = materials->__vftable;
    v2 = MaterialAtCrossHair->GetName(this: MaterialAtCrossHair);
    v1->ReloadMaterials(this: materials, a2: (const char *)v2);
  }
  else
  {
    ConMsg(a1: "no/bad material\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C7F10
// Name: mat_crosshair_printmaterial
// Source: json
//------------------------------------------------------------------------------
void __cdecl mat_crosshair_printmaterial()
{
  IMaterial *MaterialAtCrossHair; // eax
  IMaterialSystem_vtbl *v1; // esi
  int v2; // eax

  MaterialAtCrossHair = GetMaterialAtCrossHair();
  if ( MaterialAtCrossHair != nullptr )
  {
    v1 = materials->__vftable;
    v2 = ((int (__thiscall *)(IMaterial *, int))MaterialAtCrossHair->GetName)(a1: MaterialAtCrossHair, a2: 1);
    ((void (__thiscall *)(IMaterialSystem *, int))v1->DebugPrintUsedMaterials)(a1: materials, a2: v2);
  }
  else
  {
    ConMsg(a1: "no/bad material\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C7F50
// Name: RegisterLightmappedSurface
// Source: json
//------------------------------------------------------------------------------
void __usercall RegisterLightmappedSurface(msurface2_t *surfID@<eax>)
{
  msurfacelighting_t *surfacelighting; // edx
  unsigned int v3; // eax
  IMaterial *material; // ecx
  int v5; // edi
  int v6; // ebx
  int offsetIntoLightmapPage[2]; // [esp+Ch] [ebp-8h] BYREF

  surfacelighting = host_state.worldbrush->surfacelighting;
  v3 = ((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0;
  material = host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1].material;
  v5 = *(__int16 *)((char *)surfacelighting->m_LightmapExtents + v3) + 1;
  v6 = *(__int16 *)((char *)&surfacelighting->m_LightmapExtents[1] + v3) + 1;
  if ( material->GetPropertyFlag(this: material, a2: MATERIAL_PROPERTY_NEEDS_BUMPED_LIGHTMAPS) )
  {
    surfID->flags |= 8u;
    v5 *= 4;
  }
  else
  {
    surfID->flags &= ~8u;
  }
  surfID->materialSortID = materials->AllocateLightmap(
                             this: materials,
                             a2: v5,
                             a3: v6,
                             a4: offsetIntoLightmapPage,
                             a5: host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1].material);
  *(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_OffsetIntoLightmapPage
             + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0)) = offsetIntoLightmapPage[0];
  *(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_OffsetIntoLightmapPage[1]
             + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0)) = offsetIntoLightmapPage[1];
}

//------------------------------------------------------------------------------
// Address: 0x100C8020
// Name: void MaterialSytsem_DoBumpWarnings(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MaterialSytsem_DoBumpWarnings()
{
  IMaterial *v0; // eax
  int v1; // edx
  worldbrushdata_t *worldbrush; // ecx
  int numsurfaces; // edx
  int v4; // eax
  msurface2_t *surfaces2; // esi
  IMaterial *material; // ecx
  bool v7; // al
  bool v8; // bl
  IMaterial *v9; // ecx
  const char *v10; // eax
  int sortID; // [esp+0h] [ebp-4h]

  v0 = nullptr;
  v1 = 0;
  sortID = 0;
  if ( g_WorldStaticMeshes.m_Size > 0 )
  {
    worldbrush = host_state.worldbrush;
    do
    {
      if ( v0 != materialSortInfoArray[v1].material )
      {
        numsurfaces = worldbrush->numsurfaces;
        v4 = 0;
        if ( numsurfaces > 0 )
        {
          surfaces2 = worldbrush->surfaces2;
          while ( surfaces2->materialSortID != sortID )
          {
            ++v4;
            ++surfaces2;
            if ( v4 >= numsurfaces )
              goto LABEL_17;
          }
          material = worldbrush->texinfo[*((unsigned __int16 *)surfaces2 + 11) >> 1].material;
          v7 = material->GetPropertyFlag(this: material, a2: MATERIAL_PROPERTY_NEEDS_BUMPED_LIGHTMAPS);
          worldbrush = host_state.worldbrush;
          v8 = false;
          if ( (host_state.worldbrush->texinfo[*((unsigned __int16 *)surfaces2 + 11) >> 1].flags & 0x800) != 0
            && (host_state.worldbrush->texinfo[*((unsigned __int16 *)surfaces2 + 11) >> 1].flags & 0x400) == 0
            && host_state.worldbrush->lightdata != nullptr )
          {
            v8 = *(_DWORD *)&host_state.worldbrush->surfacelighting->m_nStyles[(((char *)surfaces2
                                                                               - (char *)host_state.worldbrush->surfaces2)
                                                                              & 0xFFFFFFE0)
                                                                             + 4] != 0;
          }
          if ( v7
            && !v8
            && *(_DWORD *)&host_state.worldbrush->surfacelighting->m_nStyles[(((char *)surfaces2
                                                                             - (char *)host_state.worldbrush->surfaces2)
                                                                            & 0xFFFFFFE0)
                                                                           + 4] != 0 )
          {
            v9 = materialSortInfoArray[surfaces2->materialSortID].material;
            v10 = (const char *)v9->GetName(this: v9);
            _Warning(a1: "Need to rebuild map to get bumped lighting on material %s\n", v10);
            worldbrush = host_state.worldbrush;
          }
        }
LABEL_17:
        v1 = sortID;
        v0 = materialSortInfoArray[sortID].material;
      }
      sortID = ++v1;
    }
    while ( v1 < g_WorldStaticMeshes.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C8150
// Name: void BuildMSurfaceVerts(struct worldbrushdata_t const __near *,struct msurface2_t __near *,class Vector __near *,class Vector2D __near *,class Vector2D (__near * const)[4])
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildMSurfaceVerts(
        const worldbrushdata_t *pBrushData,
        msurface2_t *surfID,
        Vector *verts,
        Vector2D *texCoords,
        Vector2D (*lightCoords)[4])
{
  int flags_high; // eax
  int firstvertindex; // ecx
  float *p_z; // edx
  Vector2D *v8; // esi
  Vector2D *v9; // edi
  mvertex_t *v10; // ebx
  float m_BumpSTexCoordOffset; // xmm0_4
  bool v12; // zf
  SurfaceCtx_t ctx; // [esp+4h] [ebp-34h] BYREF
  int v14; // [esp+28h] [ebp-10h]
  float *v15; // [esp+2Ch] [ebp-Ch]
  float *pUV; // [esp+30h] [ebp-8h]
  unsigned int v17; // [esp+34h] [ebp-4h]

  SurfSetupSurfaceContext(&ctx, surfID);
  flags_high = HIBYTE(surfID->flags);
  firstvertindex = surfID->firstvertindex;
  if ( HIBYTE(surfID->flags) != 0 )
  {
    pUV = &texCoords->x;
    p_z = &verts->z;
    v8 = (Vector2D *)lightCoords;
    v17 = 2 * firstvertindex;
    v15 = &verts->z;
    v9 = &(*lightCoords)[2];
    v14 = flags_high;
    do
    {
      v10 = &pBrushData->vertexes[pBrushData->vertindices[v17 / 2]];
      if ( verts != nullptr )
      {
        *(p_z - 2) = v10->position.x;
        *(p_z - 1) = v10->position.y;
        *p_z = v10->position.z;
      }
      if ( texCoords != nullptr )
        SurfComputeTextureCoordinate(surfID, vec: &v10->position, pUV);
      if ( lightCoords != nullptr )
      {
        SurfComputeLightmapCoordinate(&ctx, surfID, vec: &v10->position, uv: v8);
        if ( (surfID->flags & 8) != 0 )
        {
          m_BumpSTexCoordOffset = ctx.m_BumpSTexCoordOffset;
          v9[-1].x = ctx.m_BumpSTexCoordOffset + v8->x;
          v9[-1].y = v8->y;
          v9->x = (float)(m_BumpSTexCoordOffset * 2.0) + v8->x;
          v9->y = v8->y;
          v9[1].x = (float)(m_BumpSTexCoordOffset * 3.0) + v8->x;
          v9[1].y = v8->y;
        }
      }
      v17 += 2;
      pUV += 2;
      p_z = v15 + 3;
      v8 += 4;
      v9 += 4;
      v12 = v14-- == 1;
      v15 += 3;
    }
    while ( !v12 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C8280
// Name: void BuildMSurfacePrimVerts(struct worldbrushdata_t __near *,struct mprimitive_t __near *,class CMeshBuilder __near &,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildMSurfacePrimVerts(
        worldbrushdata_t *pBrushData,
        mprimitive_t *prim,
        CMeshBuilder *builder,
        msurface2_t *surfID)
{
  float *m_pCurrNormal; // edx
  mprimvert_t *v6; // eax
  float *m_pCurrPosition; // ecx
  cplane_t *plane; // ecx
  double z; // st7
  float *v10; // ecx
  float *v11; // ecx
  Vector tVect; // [esp+4h] [ebp-24h] BYREF
  Vector tangentT; // [esp+10h] [ebp-18h] BYREF
  Vector tangentS; // [esp+1Ch] [ebp-Ch] BYREF
  int i; // [esp+3Ch] [ebp+14h]

  if ( (surfID->flags & 0x100) != 0 )
    TangentSpaceSurfaceSetup(surfID, &tVect);
  i = 0;
  if ( prim->vertCount != 0 )
  {
    do
    {
      m_pCurrNormal = builder->m_VertexBuilder.m_pCurrNormal;
      v6 = &pBrushData->primverts[i + prim->firstVert];
      m_pCurrPosition = builder->m_VertexBuilder.m_pCurrPosition;
      *m_pCurrPosition = v6->pos.x;
      m_pCurrPosition[1] = v6->pos.y;
      m_pCurrPosition[2] = v6->pos.z;
      plane = surfID->plane;
      *m_pCurrNormal = plane->normal.x;
      m_pCurrNormal[1] = plane->normal.y;
      z = plane->normal.z;
      v10 = builder->m_VertexBuilder.m_pCurrTexCoord[0];
      m_pCurrNormal[2] = z;
      *v10 = v6->texCoord[0];
      v10[1] = v6->texCoord[1];
      v11 = builder->m_VertexBuilder.m_pCurrTexCoord[1];
      *v11 = v6->lightCoord[0];
      v11[1] = v6->lightCoord[1];
      if ( (surfID->flags & 0x100) != 0 )
      {
        TangentSpaceComputeBasis(&tangentS, &tangentT, normal: &surfID->plane->normal, &tVect, negateTangent: false);
        *(Vector *)((char *)builder->m_VertexBuilder.m_pTangentS
                  + builder->m_VertexBuilder.m_nCurrentVertex * builder->m_VertexBuilder.m_VertexSize_TangentS) = tangentS;
        *(Vector *)((char *)builder->m_VertexBuilder.m_pTangentT
                  + builder->m_VertexBuilder.m_nCurrentVertex * builder->m_VertexBuilder.m_VertexSize_TangentT) = tangentT;
      }
      CVertexBuilder::AdvanceVertex(this: &builder->m_VertexBuilder);
      ++i;
    }
    while ( i < prim->vertCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C83E0
// Name: public: struct msurface2_t __near * CMSurfaceSortList::GetSurfaceAtHead(struct surfacesortgroup_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
msurface2_t *__thiscall CMSurfaceSortList::GetSurfaceAtHead(CMSurfaceSortList *this, const surfacesortgroup_t *group)
{
  if ( group->listHead == -1 )
    return nullptr;
  else
    return this->m_list.m_Memory.m_pMemory[group->listHead].pSurfaces[0];
}

//------------------------------------------------------------------------------
// Address: 0x100C8A30
// Name: mat_crosshair_edit
// Source: json
//------------------------------------------------------------------------------
void __usercall mat_crosshair_edit(int a1@<edi>)
{
  IMaterial *MaterialAtCrossHair; // esi
  const char *v2; // eax
  const char *v3; // eax
  CP4File *v4; // esi
  char chResolveName[256]; // [esp+4h] [ebp-200h] BYREF
  char chResolveNameArg[256]; // [esp+104h] [ebp-100h] BYREF

  MaterialAtCrossHair = GetMaterialAtCrossHair();
  if ( MaterialAtCrossHair != nullptr )
  {
    memset(chResolveName, 0, sizeof(chResolveName));
    memset(chResolveNameArg, 0, sizeof(chResolveNameArg));
    v2 = (const char *)((int (__thiscall *)(IMaterial *, int))MaterialAtCrossHair->GetName)(
                         a1: MaterialAtCrossHair,
                         a2: a1);
    V_snprintf(pDest: chResolveNameArg, maxLen: 255, pFormat: "materials/%s.vmt", v2);
    v3 = g_pFileSystem->RelativePathToFullPath(
           this: g_pFileSystem,
           a2: chResolveNameArg,
           a3: "game",
           a4: chResolveName,
           a5: 255,
           a6: 0,
           a7: 0);
    if ( p4 != nullptr )
    {
      v4 = CP4Factory::AccessFile(this: g_p4factory, szFilename: v3);
      v4->Edit(this: v4);
      v4->Add(this: v4);
      ((void (__thiscall *)(CP4File *, int))v4->dtr_CP4File)(a1: v4, a2: 1);
    }
    else
    {
      _Warning(a1: "run with -p4 to get p4 operations upon mat_crosshair_edit\n");
    }
    ((void (__thiscall *)(vgui::ISystem *, const char *))g_pVGuiSystem->ShellExecute)(a1: g_pVGuiSystem, a2: "open");
  }
  else
  {
    ConMsg(a1: "no/bad material\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C8B40
// Name: void MaterialSystem_CreateSortinfo(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MaterialSystem_CreateSortinfo()
{
  signed int v0; // esi
  void *v1; // esp
  signed int v2; // eax
  IMaterial **v3; // ecx
  MaterialSystem_SortInfo_t *v4; // edx
  int lightmapPageID; // edx
  IMatRenderContext *m_pObject; // ebx
  void *v7; // esp
  signed int v8; // eax
  IMaterial **v9; // ecx
  worldbrushdata_t *worldbrush; // eax
  int v11; // ecx
  int v12; // esi
  _DWORD v13[3]; // [esp+0h] [ebp-10h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+Ch] [ebp-4h]

  v0 = materials->GetNumSortIDs(this: materials);
  materialSortInfoArray = (MaterialSystem_SortInfo_t *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)v0 >> 29 != 0 ? -1 : 8 * v0);
  materials->GetSortInfo(this: materials, a2: materialSortInfoArray);
  v1 = alloca(12 * v0);
  v2 = 0;
  if ( v0 > 0 )
  {
    v3 = (IMaterial **)v13;
    do
    {
      v4 = materialSortInfoArray;
      *v3 = materialSortInfoArray[v2].material;
      lightmapPageID = v4[v2].lightmapPageID;
      v3[2] = (IMaterial *)v2;
      v3[1] = (IMaterial *)lightmapPageID;
      ++v2;
      v3 += 3;
    }
    while ( v2 < v0 );
  }
  m_pObject = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  pSortMapRenderContext = m_pObject;
  qsort(base: v13, num: v0, width: 0xCu, comp: SortMapCompareFunc);
  v7 = alloca(4 * v0);
  v8 = 0;
  if ( v0 > 0 )
  {
    v9 = (IMaterial **)v13;
    do
    {
      materialSortInfoArray[v8].material = *v9;
      materialSortInfoArray[v8].lightmapPageID = (int)v9[1];
      v13[(_DWORD)v9[2]] = v8++;
      v9 += 3;
    }
    while ( v8 < v0 );
    m_pObject = pRenderContext.m_pObject;
  }
  worldbrush = host_state.worldbrush;
  v11 = 0;
  if ( host_state.worldbrush->numsurfaces > 0 )
  {
    v12 = 0;
    do
    {
      worldbrush->surfaces2[v12].materialSortID = v13[worldbrush->surfaces2[v12].materialSortID];
      worldbrush = host_state.worldbrush;
      ++v11;
      ++v12;
    }
    while ( v11 < host_state.worldbrush->numsurfaces );
  }
  GenerateTexCoordsForPrimVerts();
  WorldStaticMeshCreate();
  if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue != 0 )
    MaterialSytsem_DoBumpWarnings();
  if ( m_pObject != nullptr )
  {
    m_pObject->EndRender(this: m_pObject);
    m_pObject->Release(this: m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C94D0
// Name: public: void CMSurfaceSortList::AddSurfaceToTail(struct msurface2_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMSurfaceSortList::AddSurfaceToTail(
        CMSurfaceSortList *this,
        msurface2_t *pSurface,
        int sortGroup,
        int sortID)
{
  unsigned __int8 *m_pMemory; // edx
  int v6; // edi
  char v7; // cl
  surfacesortgroup_t *v8; // esi
  int v9; // edi
  int flags_high; // eax
  __int16 v11; // di
  int v12; // ecx
  int listTail; // eax
  materiallist_t *v14; // eax
  int v15; // eax
  bool v16; // zf
  int v17; // eax
  int v18; // ecx
  CUtlMemory<S3RGBA,int> *v19; // edi
  int m_nAllocationCount; // eax
  S3RGBA *v21; // edx
  int v22; // eax
  surfacesortgroup_t **v23; // edx
  materiallist_t *v24; // eax
  int sortGroupa; // [esp+18h] [ebp+Ch]
  int sortIDa; // [esp+1Ch] [ebp+10h]

  m_pMemory = this->m_groupUsed.m_Memory.m_pMemory;
  v6 = sortID + this->groupOffset[sortGroup];
  v7 = (sortID + LOBYTE(this->groupOffset[sortGroup])) & 7;
  v8 = &this->m_groups.m_Memory.m_pMemory[v6];
  v9 = v6 >> 3;
  if ( ((unsigned __int8)(1 << v7) & m_pMemory[v9]) == 0 )
  {
    v8->listHead = -1;
    v8->listTail = -1;
    m_pMemory[v9] |= 1 << v7;
    v8->vertexCount = 0;
    v8->groupListIndex = -1;
    v8->vertexCountNoDetail = 0;
    v8->indexCountNoDetail = 0;
    v8->triangleCount = 0;
    v8->surfaceCount = 0;
  }
  flags_high = HIBYTE(pSurface->flags);
  v8->vertexCount += flags_high;
  v11 = -1;
  v12 = flags_high - 2;
  if ( (pSurface->flags & 2) != 0 )
  {
    v8->vertexCountNoDetail += flags_high;
    v8->indexCountNoDetail += 3 * v12;
  }
  v8->triangleCount += v12;
  listTail = v8->listTail;
  ++v8->surfaceCount;
  if ( listTail != -1 )
  {
    v14 = &this->m_list.m_Memory.m_pMemory[listTail];
    if ( v14->count < 0xEu )
    {
      v14->pSurfaces[v14->count++] = pSurface;
      return;
    }
    v11 = v8->listTail;
  }
  LOWORD(v15) = CUtlVector<materiallist_t,CUtlMemory<materiallist_t,int>>::AddToTail(this: &this->m_list);
  if ( v11 >= 0 )
    this->m_list.m_Memory.m_pMemory[v11].nextBlock = (__int16)v15;
  v16 = v8->listHead == -1;
  v15 = (__int16)v15;
  sortIDa = v15;
  v8->listTail = (__int16)v15;
  if ( v16 )
  {
    v17 = 5 * sortGroup + 15;
    v18 = *(&this->m_list.m_Size + v17);
    v19 = (CUtlMemory<S3RGBA,int> *)(&this->m_list.m_Memory.m_pMemory + v17);
    m_nAllocationCount = v19->m_nAllocationCount;
    sortGroupa = v18;
    if ( v18 + 1 > m_nAllocationCount )
    {
      CUtlMemory<INetMessage *,int>::Grow(this: v19, num: v18 - m_nAllocationCount + 1);
      v18 = sortGroupa;
    }
    ++v19[1].m_pMemory;
    v21 = v19->m_pMemory;
    v22 = (int)v19[1].m_pMemory - v18 - 1;
    v19[1].m_nAllocationCount = (int)v19->m_pMemory;
    if ( v22 > 0 )
    {
      _V_memmove(dest: &v21[v18 + 1], src: &v21[v18], count: 4 * v22);
      v18 = sortGroupa;
    }
    v15 = sortIDa;
    v23 = (surfacesortgroup_t **)&v19->m_pMemory[v18];
    if ( v23 != nullptr )
      *v23 = v8;
    v8->groupListIndex = v18;
    v8->listHead = sortIDa;
  }
  v24 = &this->m_list.m_Memory.m_pMemory[v15];
  v24->nextBlock = -1;
  v24->count = 1;
  v24->pSurfaces[0] = pSurface;
}

//------------------------------------------------------------------------------
// Address: 0x100C9630
// Name: public: void CMSurfaceSortList::GetSurfaceListForGroup(class CUtlVector<struct msurface2_t __near *,class CUtlMemory<struct msurface2_t __near *,int>> __near &,struct surfacesortgroup_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMSurfaceSortList::GetSurfaceListForGroup(
        CMSurfaceSortList *this,
        CUtlMemory<S3RGBA,int> *list,
        const surfacesortgroup_t *group)
{
  __int16 listHead; // ax
  int v5; // eax
  char *v6; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  msurface2_t **v9; // ecx
  int v10; // eax
  msurface2_t **v11; // eax
  CMSurfaceSortList *i; // [esp+0h] [ebp-Ch]
  int v13; // [esp+4h] [ebp-8h]
  msurface2_t *surfID; // [esp+8h] [ebp-4h]
  int _index; // [esp+14h] [ebp+8h]
  const surfacesortgroup_t *groupa; // [esp+18h] [ebp+Ch]

  listHead = group->listHead;
  for ( i = this; listHead != -1; listHead = *(_WORD *)((char *)&this->m_list.m_Memory.m_pMemory->nextBlock + v5) )
  {
    v5 = listHead << 6;
    v6 = (char *)this->m_list.m_Memory.m_pMemory + v5;
    v13 = v5;
    _index = 0;
    if ( *((int *)v6 + 1) > 0 )
    {
      groupa = (const surfacesortgroup_t *)(v6 + 8);
      do
      {
        m_pMemory = (int)list[1].m_pMemory;
        surfID = (msurface2_t *)groupa->listHead;
        m_nAllocationCount = list->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<INetMessage *,int>::Grow(this: list, num: m_pMemory - m_nAllocationCount + 1);
        ++list[1].m_pMemory;
        v9 = (msurface2_t **)list->m_pMemory;
        v10 = (int)list[1].m_pMemory - m_pMemory - 1;
        list[1].m_nAllocationCount = (int)list->m_pMemory;
        if ( v10 > 0 )
          _V_memmove(dest: &v9[m_pMemory + 1], src: &v9[m_pMemory], count: 4 * v10);
        v11 = (msurface2_t **)&list->m_pMemory[m_pMemory];
        if ( v11 != nullptr )
          *v11 = surfID;
        groupa = (const surfacesortgroup_t *)((char *)groupa + 4);
        ++_index;
      }
      while ( _index < *((_DWORD *)v6 + 1) );
      v5 = v13;
      this = i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C9700
// Name: void MaterialSystem_RegisterLightmapSurfaces(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MaterialSystem_RegisterLightmapSurfaces()
{
  worldbrushdata_t *worldbrush; // edi
  int numsurfaces; // eax
  UtlRBTreeNode_t<msurface2_t *,int> *v2; // eax
  int v3; // ebx
  msurface2_t *v4; // eax
  int v5; // eax
  UtlRBTreeNode_t<msurface2_t *,int> *m_pMemory; // ecx
  int v7; // edx
  int v8; // esi
  int v9; // edx
  int v10; // ebx
  msurface2_t *m_Data; // esi
  CUtlRBTree<msurface2_t *,int,bool (__cdecl*)(msurface2_t * const &,msurface2_t * const &),CUtlMemory<UtlRBTreeNode_t<msurface2_t *,int>,int> > surfaces; // [esp+8h] [ebp-34h] BYREF
  int surfaceIndex; // [esp+2Ch] [ebp-10h]
  int parent; // [esp+30h] [ebp-Ch] BYREF
  msurface2_t *surfID; // [esp+34h] [ebp-8h] BYREF
  bool leftchild; // [esp+3Bh] [ebp-1h] BYREF

  surfID = nullptr;
  materials->BeginLightmapAllocation(this: materials);
  worldbrush = host_state.worldbrush;
  numsurfaces = host_state.worldbrush->numsurfaces;
  surfaces.m_LessFunc = LightmapLess;
  surfaces.m_Elements.m_pMemory = nullptr;
  surfaces.m_Elements.m_nAllocationCount = numsurfaces;
  surfaces.m_Elements.m_nGrowSize = 0;
  if ( numsurfaces != 0 )
  {
    v2 = (UtlRBTreeNode_t<msurface2_t *,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 20 * numsurfaces);
    worldbrush = host_state.worldbrush;
    surfaces.m_Elements.m_pMemory = v2;
  }
  surfaces.m_Root = -1;
  surfaces.m_NumElements = 0;
  surfaces.m_FirstFree = -1;
  surfaces.m_LastAlloc.index = -1;
  surfaces.m_pElements = surfaces.m_Elements.m_pMemory;
  surfaceIndex = 0;
  if ( worldbrush->numsurfaces > 0 )
  {
    v3 = 0;
    do
    {
      v4 = &worldbrush->surfaces2[v3];
      surfID = v4;
      if ( (worldbrush->texinfo[*((unsigned __int16 *)v4 + 11) >> 1].flags & 0x400) != 0 || (v4->flags & 1) != 0 )
        v4->flags |= 1u;
      else
        v4->flags &= ~1u;
      parent = -1;
      leftchild = false;
      CUtlRBTree<msurface2_t *,int,bool (__cdecl *)(msurface2_t * const &,msurface2_t * const &),CUtlMemory<UtlRBTreeNode_t<msurface2_t *,int>,int>>::FindInsertionPosition(
        this: &surfaces,
        insert: &surfID,
        &parent,
        &leftchild);
      v5 = CUtlRBTree<msurface2_t *,int,bool (__cdecl *)(msurface2_t * const &,msurface2_t * const &),CUtlMemory<UtlRBTreeNode_t<msurface2_t *,int>,int>>::NewNode(this: (CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *)&surfaces);
      m_pMemory = surfaces.m_Elements.m_pMemory;
      v7 = parent;
      v8 = v5;
      surfaces.m_Elements.m_pMemory[v8].m_Parent = parent;
      m_pMemory[v8].m_Right = -1;
      m_pMemory[v8].m_Left = -1;
      m_pMemory[v8].m_Tag = 0;
      if ( v7 == -1 )
      {
        surfaces.m_Root = v5;
      }
      else
      {
        v9 = v7;
        if ( leftchild )
          m_pMemory[v9].m_Left = v5;
        else
          m_pMemory[v9].m_Right = v5;
      }
      CUtlRBTree<msurface2_t *,int,bool (__cdecl *)(msurface2_t * const &,msurface2_t * const &),CUtlMemory<UtlRBTreeNode_t<msurface2_t *,int>,int>>::InsertRebalance(
        this: &surfaces,
        elem: v5);
      ++surfaces.m_NumElements;
      if ( &surfaces.m_Elements.m_pMemory[v8] != (UtlRBTreeNode_t<msurface2_t *,int> *)-16 )
        surfaces.m_Elements.m_pMemory[v8].m_Data = surfID;
      worldbrush = host_state.worldbrush;
      ++v3;
      ++surfaceIndex;
    }
    while ( surfaceIndex < host_state.worldbrush->numsurfaces );
  }
  surfID = nullptr;
  v10 = CUtlRBTree<msurface2_t *,int,bool (__cdecl *)(msurface2_t * const &,msurface2_t * const &),CUtlMemory<UtlRBTreeNode_t<msurface2_t *,int>,int>>::FirstInorder(this: &surfaces);
  if ( v10 != -1 )
  {
    while ( 1 )
    {
      m_Data = surfaces.m_Elements.m_pMemory[v10].m_Data;
      if ( (m_Data->flags & 1) != 0 )
      {
        m_Data->materialSortID = materials->AllocateWhiteLightmap(
                                   this: materials,
                                   a2: worldbrush->texinfo[*((unsigned __int16 *)m_Data + 11) >> 1].material);
        *(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_OffsetIntoLightmapPage
                   + (((char *)m_Data - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0)) = 0;
        *(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_OffsetIntoLightmapPage[1]
                   + (((char *)m_Data - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0)) = 0;
      }
      else
      {
        RegisterLightmappedSurface(surfID: surfaces.m_Elements.m_pMemory[v10].m_Data);
      }
      v10 = CUtlRBTree<msurface2_t *,int,bool (__cdecl *)(msurface2_t * const &,msurface2_t * const &),CUtlMemory<UtlRBTreeNode_t<msurface2_t *,int>,int>>::NextInorder(
              this: &surfaces,
              i: v10);
      if ( v10 == -1 )
        break;
      worldbrush = host_state.worldbrush;
    }
  }
  materials->EndLightmapAllocation(this: materials);
  CUtlRBTree<msurface2_t *,int,bool (__cdecl *)(msurface2_t * const &,msurface2_t * const &),CUtlMemory<UtlRBTreeNode_t<msurface2_t *,int>,int>>::RemoveAll(this: &surfaces);
  if ( surfaces.m_Elements.m_nGrowSize >= 0 && surfaces.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: surfaces.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100C9960
// Name: public: void CMSurfaceSortList::Init(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMSurfaceSortList::Init(CMSurfaceSortList *this, int maxSortIDs, int minMaterialLists)
{
  materiallist_t *m_pMemory; // edx
  materiallist_t *v5; // eax
  int v6; // esi
  int m_Size; // ecx
  int v8; // eax
  int v9; // ebx
  int m_nAllocationCount; // eax
  unsigned __int8 *v11; // edx
  int v12; // eax
  int v13; // ebx
  CUtlVector<surfacesortgroup_t *,CUtlMemory<surfacesortgroup_t *,int> > *m_sortGroupLists; // esi
  int v15; // eax
  surfacesortgroup_t **v16; // eax
  unsigned int v17; // [esp-4h] [ebp-10h]
  unsigned int v18; // [esp-4h] [ebp-10h]
  int maxSortIDsa; // [esp+14h] [ebp+8h]
  int groupBytes; // [esp+18h] [ebp+Ch]
  int *groupBytesa; // [esp+18h] [ebp+Ch]

  this->m_list.m_Size = 0;
  if ( this->m_list.m_Memory.m_nAllocationCount < minMaterialLists && this->m_list.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_list.m_Memory.m_pMemory;
    this->m_list.m_Memory.m_nAllocationCount = minMaterialLists;
    v17 = minMaterialLists << 6;
    if ( m_pMemory != nullptr )
      v5 = (materiallist_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v17);
    else
      v5 = (materiallist_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v17);
    this->m_list.m_Memory.m_pMemory = v5;
  }
  this->m_list.m_pElements = this->m_list.m_Memory.m_pMemory;
  v6 = 4 * maxSortIDs;
  this->m_maxSortIDs = maxSortIDs;
  this->m_groups.m_Size = 0;
  if ( 4 * maxSortIDs > 0 )
    CUtlVector<surfacesortgroup_t,CUtlMemory<surfacesortgroup_t,int>>::InsertMultipleBefore(
      this: &this->m_groups,
      elem: 0,
      num: v6);
  m_Size = this->m_groupUsed.m_Size;
  v8 = (v6 + 7) >> 3;
  groupBytes = v8;
  maxSortIDsa = m_Size;
  if ( m_Size < v8 )
  {
    v9 = v8 - m_Size;
    if ( v8 != m_Size )
    {
      m_nAllocationCount = this->m_groupUsed.m_Memory.m_nAllocationCount;
      if ( m_Size + v9 > m_nAllocationCount )
      {
        CUtlMemory<bool,int>::Grow(
          this: (CUtlMemory<char,int> *)&this->m_groupUsed,
          num: v9 + m_Size - m_nAllocationCount);
        m_Size = maxSortIDsa;
      }
      this->m_groupUsed.m_Size += v9;
      v11 = this->m_groupUsed.m_Memory.m_pMemory;
      v12 = this->m_groupUsed.m_Size - m_Size - v9;
      this->m_groupUsed.m_pElements = v11;
      if ( v12 > 0 && v9 > 0 )
        _V_memmove(dest: &v11[m_Size + v9], src: &v11[m_Size], count: v12);
      v8 = groupBytes;
    }
  }
  _V_memset(dest: this->m_groupUsed.m_Memory.m_pMemory, fill: 0, count: v8);
  v13 = 0;
  groupBytesa = this->groupOffset;
  m_sortGroupLists = this->m_sortGroupLists;
  do
  {
    v15 = v13 != 0 ? 16 : 128;
    m_sortGroupLists->m_Size = 0;
    if ( m_sortGroupLists->m_Memory.m_nAllocationCount < v15 && m_sortGroupLists->m_Memory.m_nGrowSize >= 0 )
    {
      m_sortGroupLists->m_Memory.m_nAllocationCount = v15;
      v18 = 4 * v15;
      if ( m_sortGroupLists->m_Memory.m_pMemory != nullptr )
        v16 = (surfacesortgroup_t **)_g_pMemAlloc->Realloc_2(
                                       this: _g_pMemAlloc,
                                       a2: m_sortGroupLists->m_Memory.m_pMemory,
                                       a3: v18);
      else
        v16 = (surfacesortgroup_t **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v18);
      m_sortGroupLists->m_Memory.m_pMemory = v16;
    }
    m_sortGroupLists->m_pElements = m_sortGroupLists->m_Memory.m_pMemory;
    *groupBytesa = v13 * this->m_maxSortIDs;
    ++v13;
    ++m_sortGroupLists;
    ++groupBytesa;
  }
  while ( v13 < 4 );
  this->m_emptyGroup.listHead = -1;
  this->m_emptyGroup.listTail = -1;
  this->m_emptyGroup.vertexCount = 0;
  this->m_emptyGroup.groupListIndex = -1;
  this->m_emptyGroup.vertexCountNoDetail = 0;
  this->m_emptyGroup.indexCountNoDetail = 0;
  this->m_emptyGroup.triangleCount = 0;
  this->m_emptyGroup.surfaceCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100C9B00
// Name: public: void CMSurfaceSortList::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMSurfaceSortList::Reset(CMSurfaceSortList *this)
{
  CMSurfaceSortList::Init(
    this,
    maxSortIDs: this->m_maxSortIDs,
    minMaterialLists: this->m_list.m_Memory.m_nAllocationCount);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100C6F80
// Name: int SortMapCompareFunc(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SortMapCompareFunc(const void *pElem0, const void *pElem1)
{
  return pSortMapRenderContext->CompareMaterialCombos(
           this: pSortMapRenderContext,
           a2: *(IMaterial **)pElem0,
           a3: *(IMaterial **)pElem1,
           a4: *((_DWORD *)pElem0 + 1),
           a5: *((_DWORD *)pElem1 + 1));
}

//------------------------------------------------------------------------------
// Address: 0x100C6FB0
// Name: void MaterialSystem_RegisterPaintSurfaces(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MaterialSystem_RegisterPaintSurfaces()
{
  CPaintmapDataManager *v0; // eax

  v0 = nullptr;
  if ( g_PaintManager.m_bShouldRegister )
    v0 = &g_PaintManager;
  materials->RegisterPaintmapDataManager(this: materials, a2: v0);
}

//------------------------------------------------------------------------------
// Address: 0x100C6FE0
// Name: void ForceMatSysRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ForceMatSysRestore()
{
  ReleaseMaterialSystemObjects(nChangeFlags: 0);
  RestoreMaterialSystemObjects(nChangeFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100C7000
// Name: LightmapLess
// Source: json
//------------------------------------------------------------------------------
bool __cdecl LightmapLess(msurface2_t *const *surfID1, msurface2_t *const *surfID2)
{
  unsigned __int8 v2; // al
  unsigned __int8 v3; // cl
  bool v4; // cf
  mtexinfo_t *texinfo; // edx
  IMaterial *material; // ecx
  IMaterial *v8; // esi
  int v9; // edi
  int v10; // eax
  unsigned __int8 v11; // cl
  unsigned __int8 v12; // dl
  msurface2_t *surfaces2; // ecx
  msurfacelighting_t *surfacelighting; // edx

  v2 = (**(_BYTE **)surfID1 & 1) == 0;
  v3 = (**(_BYTE **)surfID2 & 1) == 0;
  v4 = v3 < v2;
  if ( v3 != v2 )
    return v4;
  texinfo = host_state.worldbrush->texinfo;
  material = texinfo[*((unsigned __int16 *)*surfID1 + 11) >> 1].material;
  v8 = texinfo[*((unsigned __int16 *)*surfID2 + 11) >> 1].material;
  v9 = material->GetEnumerationID(this: material);
  v10 = v8->GetEnumerationID(this: v8);
  if ( v9 != v10 )
    return v9 < v10;
  v11 = (**(_DWORD **)surfID1 & 0x400) == 0;
  v12 = (**(_DWORD **)surfID2 & 0x400) == 0;
  v4 = v12 < v11;
  if ( v12 != v11 )
    return v4;
  surfaces2 = host_state.worldbrush->surfaces2;
  surfacelighting = host_state.worldbrush->surfacelighting;
  return *(__int16 *)((char *)surfacelighting->m_LightmapExtents + (((char *)*surfID2 - (char *)surfaces2) & 0xFFFFFFE0))
       * *(__int16 *)((char *)&surfacelighting->m_LightmapExtents[1]
                    + (((char *)*surfID2 - (char *)surfaces2) & 0xFFFFFFE0)) < *(__int16 *)((char *)surfacelighting->m_LightmapExtents
                                                                                          + (((char *)*surfID1
                                                                                            - (char *)surfaces2)
                                                                                           & 0xFFFFFFE0))
                                                                             * *(__int16 *)((char *)&surfacelighting->m_LightmapExtents[1]
                                                                                          + (((char *)*surfID1
                                                                                            - (char *)surfaces2)
                                                                                           & 0xFFFFFFE0));
}

//------------------------------------------------------------------------------
// Address: 0x100C70E0
// Name: GenerateTexCoordsForPrimVerts
// Source: json
//------------------------------------------------------------------------------
int GenerateTexCoordsForPrimVerts()
{
  worldbrushdata_t *worldbrush; // ecx
  int result; // eax
  msurface2_t *v2; // edi
  int i; // esi
  unsigned int flags; // eax
  bool v5; // zf
  bool v6; // dl
  unsigned __int16 numPrims; // ax
  unsigned __int16 firstPrimID; // ax
  int v9; // ebx
  IMaterialSystem_vtbl *v10; // esi
  int v11; // eax
  float v12; // xmm0_4
  __int16 *v13; // eax
  int v14; // edx
  float v15; // xmm1_4
  int v16; // edx
  int v17; // eax
  float v18; // xmm0_4
  int v19; // esi
  int v20; // edx
  IMaterial *material; // ecx
  int v22; // ecx
  IMaterial *v23; // ecx
  float v24; // xmm0_4
  int v25; // edx
  float v26; // xmm0_4
  float v27; // xmm0_4
  int v28; // ecx
  float v29; // xmm0_4
  float v30; // xmm0_4
  int v31; // eax
  bool v32; // cc
  int v33; // edx
  int lightmapPageSize[2]; // [esp+0h] [ebp-2Ch] BYREF
  float tScale; // [esp+8h] [ebp-24h]
  float sScale; // [esp+Ch] [ebp-20h]
  int surfaceIndex; // [esp+10h] [ebp-1Ch]
  int j; // [esp+14h] [ebp-18h]
  int k; // [esp+18h] [ebp-14h]
  float tOffset; // [esp+1Ch] [ebp-10h]
  float sOffset; // [esp+20h] [ebp-Ch]
  unsigned int v42; // [esp+24h] [ebp-8h]
  int l; // [esp+28h] [ebp-4h]

  worldbrush = host_state.worldbrush;
  result = 0;
  surfaceIndex = 0;
  if ( host_state.worldbrush->numsurfaces > 0 )
  {
    v42 = 0;
    do
    {
      v2 = &worldbrush->surfaces2[v42 / 0x20];
      for ( i = 0; ; ++i )
      {
        flags = v2->flags;
        v6 = (v2->flags & 0x800) != 0;
        v5 = (v2->flags & 0x800) == 0;
        j = i;
        if ( v5 && (flags & 0x8000) != 0 )
          numPrims = worldbrush->surfaces1[v2 - worldbrush->surfaces2].prims.numPrims;
        else
          numPrims = 0;
        if ( i >= numPrims )
          break;
        if ( v6 )
          firstPrimID = 0;
        else
          firstPrimID = worldbrush->surfaces1[v2 - worldbrush->surfaces2].prims.firstPrimID;
        v9 = (int)&worldbrush->primitives[i + firstPrimID];
        k = 0;
        if ( *(_WORD *)(v9 + 10) != 0 )
        {
          do
          {
            v10 = materials->__vftable;
            v11 = SortInfoToLightmapPage(sortID: v2->materialSortID);
            v10->GetLightmapPageSize(this: materials, a2: v11, a3: lightmapPageSize, a4: &lightmapPageSize[1]);
            worldbrush = host_state.worldbrush;
            v12 = 1.0 / (float)lightmapPageSize[0];
            v13 = (__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapMins
                            + (((char *)v2 - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
            l = 0;
            v14 = v13[2];
            sOffset = (float)v13[4] * v12;
            v15 = (float)v14;
            v16 = v13[5];
            v17 = v13[3];
            sScale = v15 * v12;
            v18 = 1.0 / (float)lightmapPageSize[1];
            tOffset = (float)v16 * v18;
            tScale = (float)v17 * v18;
            if ( *(_WORD *)(v9 + 10) != 0 )
            {
              do
              {
                v19 = (int)&worldbrush->primverts[l + *(unsigned __int16 *)(v9 + 8)];
                v20 = *((unsigned __int16 *)v2 + 11) >> 1;
                *(float *)(v19 + 12) = (float)((float)((float)(worldbrush->texinfo[v20].textureVecsTexelsPerWorldUnits[0].y
                                                             * *(float *)(v19 + 4))
                                                     + (float)(worldbrush->texinfo[v20].textureVecsTexelsPerWorldUnits[0].x
                                                             * *(float *)v19))
                                             + (float)(worldbrush->texinfo[v20].textureVecsTexelsPerWorldUnits[0].z
                                                     * *(float *)(v19 + 8)))
                                     + worldbrush->texinfo[v20].textureVecsTexelsPerWorldUnits[0].w;
                material = host_state.worldbrush->texinfo[*((unsigned __int16 *)v2 + 11) >> 1].material;
                *(float *)(v19 + 12) = *(float *)(v19 + 12) / (float)material->GetMappingWidth(this: material);
                v22 = *((unsigned __int16 *)v2 + 11) >> 1;
                *(float *)(v19 + 16) = (float)((float)((float)(host_state.worldbrush->texinfo[v22].textureVecsTexelsPerWorldUnits[1].y
                                                             * *(float *)(v19 + 4))
                                                     + (float)(host_state.worldbrush->texinfo[v22].textureVecsTexelsPerWorldUnits[1].x
                                                             * *(float *)v19))
                                             + (float)(host_state.worldbrush->texinfo[v22].textureVecsTexelsPerWorldUnits[1].z
                                                     * *(float *)(v19 + 8)))
                                     + host_state.worldbrush->texinfo[v22].textureVecsTexelsPerWorldUnits[1].w;
                v23 = host_state.worldbrush->texinfo[*((unsigned __int16 *)v2 + 11) >> 1].material;
                *(float *)(v19 + 16) = *(float *)(v19 + 16) / (float)v23->GetMappingHeight(this: v23);
                if ( (v2->flags & 1) != 0 )
                {
                  v24 = 0.5;
                  *(_DWORD *)(v19 + 20) = 1056964608;
                }
                else if ( *(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapExtents
                                     + (((char *)v2 - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0)) != 0 )
                {
                  v25 = *((unsigned __int16 *)v2 + 11) >> 1;
                  v26 = (float)((float)((float)(host_state.worldbrush->texinfo[v25].lightmapVecsLuxelsPerWorldUnits[0].y
                                              * *(float *)(v19 + 4))
                                      + (float)(host_state.worldbrush->texinfo[v25].lightmapVecsLuxelsPerWorldUnits[0].x
                                              * *(float *)v19))
                              + (float)(host_state.worldbrush->texinfo[v25].lightmapVecsLuxelsPerWorldUnits[0].z
                                      * *(float *)(v19 + 8)))
                      + host_state.worldbrush->texinfo[v25].lightmapVecsLuxelsPerWorldUnits[0].w;
                  *(float *)(v19 + 20) = v26;
                  v27 = (float)(v26
                              - (float)*(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapMins
                                                  + (((char *)v2 - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0)))
                      + 0.5;
                  *(float *)(v19 + 20) = v27;
                  *(float *)(v19 + 20) = v27
                                       / (float)*(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapExtents
                                                           + (((char *)v2 - (char *)host_state.worldbrush->surfaces2)
                                                            & 0xFFFFFFE0));
                  v28 = *((unsigned __int16 *)v2 + 11) >> 1;
                  v29 = (float)((float)((float)(host_state.worldbrush->texinfo[v28].lightmapVecsLuxelsPerWorldUnits[1].y
                                              * *(float *)(v19 + 4))
                                      + (float)(host_state.worldbrush->texinfo[v28].lightmapVecsLuxelsPerWorldUnits[1].x
                                              * *(float *)v19))
                              + (float)(host_state.worldbrush->texinfo[v28].lightmapVecsLuxelsPerWorldUnits[1].z
                                      * *(float *)(v19 + 8)))
                      + host_state.worldbrush->texinfo[v28].lightmapVecsLuxelsPerWorldUnits[1].w;
                  *(float *)(v19 + 24) = v29;
                  v30 = (float)(v29
                              - (float)*(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_LightmapMins[1]
                                                  + (((char *)v2 - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0)))
                      + 0.5;
                  *(float *)(v19 + 24) = v30;
                  *(float *)(v19 + 24) = v30
                                       / (float)*(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_LightmapExtents[1]
                                                           + (((char *)v2 - (char *)host_state.worldbrush->surfaces2)
                                                            & 0xFFFFFFE0));
                  *(float *)(v19 + 20) = (float)(*(float *)(v19 + 20) * sScale) + sOffset;
                  v24 = (float)(*(float *)(v19 + 24) * tScale) + tOffset;
                }
                else
                {
                  *(float *)(v19 + 20) = sOffset;
                  v24 = tOffset;
                }
                v31 = l;
                *(float *)(v19 + 24) = v24;
                v32 = ++v31 < *(unsigned __int16 *)(v9 + 10);
                worldbrush = host_state.worldbrush;
                l = v31;
              }
              while ( v32 );
            }
            v33 = *(unsigned __int16 *)(v9 + 10);
            ++k;
          }
          while ( k < v33 );
          i = j;
        }
      }
      v42 += 32;
      result = surfaceIndex + 1;
      surfaceIndex = result;
    }
    while ( result < worldbrush->numsurfaces );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C7560
// Name: bool SurfHasBumpedLightmaps(struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl SurfHasBumpedLightmaps(msurface2_t *surfID)
{
  bool result; // al

  result = false;
  if ( (host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1].flags & 0x800) != 0
    && (host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1].flags & 0x400) == 0
    && host_state.worldbrush->lightdata != nullptr )
  {
    return *(_DWORD *)&host_state.worldbrush->surfacelighting->m_nStyles[(((char *)surfID
                                                                         - (char *)host_state.worldbrush->surfaces2)
                                                                        & 0xFFFFFFE0)
                                                                       + 4] != 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C75C0
// Name: bool SurfNeedsBumpedLightmaps(struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl SurfNeedsBumpedLightmaps(msurface2_t *surfID)
{
  IMaterial *material; // ecx

  material = host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1].material;
  return material->GetPropertyFlag(this: material, a2: MATERIAL_PROPERTY_NEEDS_BUMPED_LIGHTMAPS);
}

//------------------------------------------------------------------------------
// Address: 0x100C75F0
// Name: bool SurfHasLightmap(struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl SurfHasLightmap(msurface2_t *surfID)
{
  bool result; // al

  result = false;
  if ( (host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1].flags & 0x400) == 0
    && host_state.worldbrush->lightdata != nullptr )
  {
    return *(_DWORD *)&host_state.worldbrush->surfacelighting->m_nStyles[(((char *)surfID
                                                                         - (char *)host_state.worldbrush->surfaces2)
                                                                        & 0xFFFFFFE0)
                                                                       + 4] != 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C7640
// Name: bool SurfNeedsLightmap(struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl SurfNeedsLightmap(msurface2_t *surfID)
{
  mtexinfo_t *v1; // eax

  v1 = &host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1];
  return (v1->flags & 0x400) == 0
      && v1->material->GetPropertyFlag(this: v1->material, a2: MATERIAL_PROPERTY_NEEDS_LIGHTMAP);
}

//------------------------------------------------------------------------------
// Address: 0x100C7680
// Name: void BuildMSurfacePrimIndices(struct worldbrushdata_t __near *,struct mprimitive_t __near *,class CMeshBuilder __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildMSurfacePrimIndices(worldbrushdata_t *pBrushData, mprimitive_t *prim, CMeshBuilder *builder)
{
  int v3; // esi
  int m_nCurrentIndex; // edx

  v3 = 0;
  if ( prim->indexCount != 0 )
  {
    do
    {
      builder->m_IndexBuilder.m_pIndices[builder->m_IndexBuilder.m_nCurrentIndex] = LOWORD(builder->m_IndexBuilder.m_nIndexOffset)
                                                                                  + pBrushData->primindices[v3 + prim->firstIndex]
                                                                                  - prim->firstVert;
      builder->m_IndexBuilder.m_nCurrentIndex += builder->m_IndexBuilder.m_nIndexSize;
      m_nCurrentIndex = builder->m_IndexBuilder.m_nCurrentIndex;
      if ( m_nCurrentIndex > builder->m_IndexBuilder.m_nIndexCount )
        builder->m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
      ++v3;
    }
    while ( v3 < prim->indexCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C7700
// Name: void BuildBrushModelVertexArray(struct worldbrushdata_t __near *,struct msurface2_t __near *,struct BrushVertex_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildBrushModelVertexArray(worldbrushdata_t *pBrushData, int surfID, BrushVertex_t *pVerts)
{
  bool v4; // zf
  float *p_z; // esi
  mvertex_t *v6; // edi
  int v7; // edi
  Vector *v8; // eax
  SurfaceCtx_t ctx; // [esp+4h] [ebp-4Ch] BYREF
  Vector tVect; // [esp+28h] [ebp-28h] BYREF
  Vector tangentT; // [esp+34h] [ebp-1Ch] BYREF
  Vector tangentS; // [esp+40h] [ebp-10h] BYREF
  BOOL negate; // [esp+4Ch] [ebp-4h]
  int i; // [esp+5Ch] [ebp+Ch]

  SurfSetupSurfaceContext(&ctx, (msurface2_t *)surfID);
  v4 = (*(_DWORD *)surfID & 0x100) == 0;
  LOBYTE(negate) = 0;
  if ( !v4 )
    LOBYTE(negate) = TangentSpaceSurfaceSetup((msurface2_t *)surfID, &tVect);
  i = 0;
  if ( *(_BYTE *)(surfID + 3) != 0 )
  {
    p_z = &pVerts->m_Normal.z;
    do
    {
      v6 = &pBrushData->vertexes[pBrushData->vertindices[i + *(_DWORD *)(surfID + 8)]];
      *(p_z - 5) = v6->position.x;
      *(p_z - 4) = v6->position.y;
      *(p_z - 3) = v6->position.z;
      SurfComputeTextureCoordinate((msurface2_t *)surfID, vec: &v6->position, pUV: p_z + 7);
      SurfComputeLightmapCoordinate(&ctx, (msurface2_t *)surfID, vec: &v6->position, uv: (Vector2D *)(p_z + 9));
      v7 = i;
      v8 = &pBrushData->vertnormals[pBrushData->vertnormalindices[i
                                                                + host_state.worldbrush->surfacenormals[(signed int)(surfID - (unsigned int)host_state.worldbrush->surfaces2) >> 5].firstvertnormal]];
      *(p_z - 2) = v8->x;
      *(p_z - 1) = v8->y;
      *p_z = v8->z;
      if ( (*(_DWORD *)surfID & 0x100) != 0 )
      {
        TangentSpaceComputeBasis(&tangentS, &tangentT, normal: v8, &tVect, negateTangent: negate);
        *(Vector *)(p_z + 1) = tangentS;
        *(Vector *)(p_z + 4) = tangentT;
      }
      p_z += 16;
      ++i;
    }
    while ( v7 + 1 < *(unsigned __int8 *)(surfID + 3) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C7850
// Name: class IMaterial __near * GetMaterialAtCrossHair(void)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__cdecl GetMaterialAtCrossHair()
{
  msurface2_t *v0; // eax
  Vector lightmapColor; // [esp+0h] [ebp-18h] BYREF
  Vector endPoint; // [esp+Ch] [ebp-Ch] BYREF

  endPoint.x = (float)(g_MainViewForward[0].x * 57016.32) + g_MainViewOrigin[0].x;
  endPoint.y = (float)(*(float *)dword_104F1BF8 * 57016.32) + g_MainViewOrigin[0].y;
  endPoint.z = (float)(*(float *)dword_104F1BFC * 57016.32) + g_MainViewOrigin[0].z;
  v0 = R_LightVec(
         start: g_MainViewOrigin,
         end: &endPoint,
         bUseLightStyles: false,
         c: &lightmapColor,
         textureS: nullptr,
         textureT: nullptr,
         lightmapS: nullptr,
         lightmapT: nullptr);
  if ( v0 != nullptr )
    return host_state.worldbrush->texinfo[*((unsigned __int16 *)v0 + 11) >> 1].material;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100C78F0
// Name: mat_edit
// Source: json
//------------------------------------------------------------------------------
void __usercall mat_edit(int a1@<ebx>, int a2@<edi>, const CCommand *args)
{
  IMaterial *MaterialAtCrossHair; // eax
  const char *v4; // eax
  IMaterial *v5; // esi
  IToolSystem *v6; // ebx
  const char *v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  const char *v10; // eax

  if ( toolframework->InToolMode(this: toolframework) )
  {
    if ( args->m_nArgc >= 2 )
    {
      v4 = defaultValue;
      if ( args->m_nArgc > 1 )
        v4 = args->m_ppArgv[1];
      MaterialAtCrossHair = materials->FindMaterial(this: materials, a2: v4, a3: "edited materials", a4: 0, a5: 0);
    }
    else
    {
      MaterialAtCrossHair = GetMaterialAtCrossHair();
    }
    v5 = MaterialAtCrossHair;
    if ( MaterialAtCrossHair != nullptr )
    {
      v6 = toolframework->SwitchToTool(this: toolframework, a2: "Material Editor");
      if ( v6 != nullptr )
      {
        v7 = (const char *)((int (__thiscall *)(IMaterial *, int, int))v5->GetName)(a1: v5, a2, a3: a1);
        ConMsg(a1: "editing material \"%s\"\n", v7);
        v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v8 != nullptr )
          v9 = KeyValues::KeyValues(this: v8, setName: "EditMaterial");
        else
          v9 = nullptr;
        v10 = (const char *)v5->GetName(this: v5);
        KeyValues::SetString(this: v9, keyName: "material", value: v10);
        v6->PostToolMessage(this: v6, a2: 0, a3: v9);
        KeyValues::deleteThis(this: v9);
      }
    }
    else
    {
      ConMsg(a1: "no/bad material\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C79E0
// Name: mat_crosshair
// Source: json
//------------------------------------------------------------------------------
void __cdecl mat_crosshair()
{
  IMaterial *MaterialAtCrossHair; // eax
  const char *v1; // eax

  MaterialAtCrossHair = GetMaterialAtCrossHair();
  if ( MaterialAtCrossHair != nullptr )
  {
    v1 = (const char *)MaterialAtCrossHair->GetName(this: MaterialAtCrossHair);
    ConMsg(a1: "hit material \"%s\"\n", v1);
  }
  else
  {
    ConMsg(a1: "no/bad material\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C7B00
// Name: mat_crosshair_reloadmaterial
// Source: json
//------------------------------------------------------------------------------
void __cdecl mat_crosshair_reloadmaterial()
{
  IMaterial *MaterialAtCrossHair; // eax
  IMaterialSystem_vtbl *v1; // esi
  int v2; // eax

  MaterialAtCrossHair = GetMaterialAtCrossHair();
  if ( MaterialAtCrossHair != nullptr )
  {
    v1 = materials->__vftable;
    v2 = MaterialAtCrossHair->GetName(this: MaterialAtCrossHair);
    v1->ReloadMaterials(this: materials, a2: (const char *)v2);
  }
  else
  {
    ConMsg(a1: "no/bad material\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C7B40
// Name: mat_crosshair_printmaterial
// Source: json
//------------------------------------------------------------------------------
void __cdecl mat_crosshair_printmaterial()
{
  IMaterial *MaterialAtCrossHair; // eax
  IMaterialSystem_vtbl *v1; // esi
  int v2; // eax

  MaterialAtCrossHair = GetMaterialAtCrossHair();
  if ( MaterialAtCrossHair != nullptr )
  {
    v1 = materials->__vftable;
    v2 = ((int (__thiscall *)(IMaterial *, int))MaterialAtCrossHair->GetName)(a1: MaterialAtCrossHair, a2: 1);
    ((void (__thiscall *)(IMaterialSystem *, int))v1->DebugPrintUsedMaterials)(a1: materials, a2: v2);
  }
  else
  {
    ConMsg(a1: "no/bad material\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C7B80
// Name: RegisterLightmappedSurface
// Source: json
//------------------------------------------------------------------------------
void __usercall RegisterLightmappedSurface(msurface2_t *surfID@<eax>)
{
  msurfacelighting_t *surfacelighting; // edx
  unsigned int v3; // eax
  IMaterial *material; // ecx
  int v5; // edi
  int v6; // ebx
  int offsetIntoLightmapPage[2]; // [esp+Ch] [ebp-8h] BYREF

  surfacelighting = host_state.worldbrush->surfacelighting;
  v3 = ((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0;
  material = host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1].material;
  v5 = *(__int16 *)((char *)surfacelighting->m_LightmapExtents + v3) + 1;
  v6 = *(__int16 *)((char *)&surfacelighting->m_LightmapExtents[1] + v3) + 1;
  if ( material->GetPropertyFlag(this: material, a2: MATERIAL_PROPERTY_NEEDS_BUMPED_LIGHTMAPS) )
  {
    surfID->flags |= 8u;
    v5 *= 4;
  }
  else
  {
    surfID->flags &= ~8u;
  }
  surfID->materialSortID = materials->AllocateLightmap(
                             this: materials,
                             a2: v5,
                             a3: v6,
                             a4: offsetIntoLightmapPage,
                             a5: host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1].material);
  *(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_OffsetIntoLightmapPage
             + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0)) = offsetIntoLightmapPage[0];
  *(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_OffsetIntoLightmapPage[1]
             + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0)) = offsetIntoLightmapPage[1];
}

//------------------------------------------------------------------------------
// Address: 0x100C7C50
// Name: void MaterialSytsem_DoBumpWarnings(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MaterialSytsem_DoBumpWarnings()
{
  IMaterial *v0; // eax
  int v1; // edx
  worldbrushdata_t *worldbrush; // ecx
  int numsurfaces; // edx
  int v4; // eax
  msurface2_t *surfaces2; // esi
  IMaterial *material; // ecx
  bool v7; // al
  bool v8; // bl
  IMaterial *v9; // ecx
  const char *v10; // eax
  int sortID; // [esp+0h] [ebp-4h]

  v0 = nullptr;
  v1 = 0;
  sortID = 0;
  if ( g_WorldStaticMeshes.m_Size > 0 )
  {
    worldbrush = host_state.worldbrush;
    do
    {
      if ( v0 != materialSortInfoArray[v1].material )
      {
        numsurfaces = worldbrush->numsurfaces;
        v4 = 0;
        if ( numsurfaces > 0 )
        {
          surfaces2 = worldbrush->surfaces2;
          while ( surfaces2->materialSortID != sortID )
          {
            ++v4;
            ++surfaces2;
            if ( v4 >= numsurfaces )
              goto LABEL_17;
          }
          material = worldbrush->texinfo[*((unsigned __int16 *)surfaces2 + 11) >> 1].material;
          v7 = material->GetPropertyFlag(this: material, a2: MATERIAL_PROPERTY_NEEDS_BUMPED_LIGHTMAPS);
          worldbrush = host_state.worldbrush;
          v8 = false;
          if ( (host_state.worldbrush->texinfo[*((unsigned __int16 *)surfaces2 + 11) >> 1].flags & 0x800) != 0
            && (host_state.worldbrush->texinfo[*((unsigned __int16 *)surfaces2 + 11) >> 1].flags & 0x400) == 0
            && host_state.worldbrush->lightdata != nullptr )
          {
            v8 = *(_DWORD *)&host_state.worldbrush->surfacelighting->m_nStyles[(((char *)surfaces2
                                                                               - (char *)host_state.worldbrush->surfaces2)
                                                                              & 0xFFFFFFE0)
                                                                             + 4] != 0;
          }
          if ( v7
            && !v8
            && *(_DWORD *)&host_state.worldbrush->surfacelighting->m_nStyles[(((char *)surfaces2
                                                                             - (char *)host_state.worldbrush->surfaces2)
                                                                            & 0xFFFFFFE0)
                                                                           + 4] != 0 )
          {
            v9 = materialSortInfoArray[surfaces2->materialSortID].material;
            v10 = (const char *)v9->GetName(this: v9);
            _Warning(a1: "Need to rebuild map to get bumped lighting on material %s\n", v10);
            worldbrush = host_state.worldbrush;
          }
        }
LABEL_17:
        v1 = sortID;
        v0 = materialSortInfoArray[sortID].material;
      }
      sortID = ++v1;
    }
    while ( v1 < g_WorldStaticMeshes.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C7D80
// Name: void BuildMSurfaceVerts(struct worldbrushdata_t const __near *,struct msurface2_t __near *,class Vector __near *,class Vector2D __near *,class Vector2D (__near * const)[4])
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildMSurfaceVerts(
        const worldbrushdata_t *pBrushData,
        msurface2_t *surfID,
        Vector *verts,
        Vector2D *texCoords,
        Vector2D (*lightCoords)[4])
{
  int flags_high; // eax
  int firstvertindex; // ecx
  float *p_z; // edx
  Vector2D *v8; // esi
  Vector2D *v9; // edi
  mvertex_t *v10; // ebx
  float m_BumpSTexCoordOffset; // xmm0_4
  bool v12; // zf
  SurfaceCtx_t ctx; // [esp+4h] [ebp-34h] BYREF
  int v14; // [esp+28h] [ebp-10h]
  float *v15; // [esp+2Ch] [ebp-Ch]
  float *pUV; // [esp+30h] [ebp-8h]
  unsigned int v17; // [esp+34h] [ebp-4h]

  SurfSetupSurfaceContext(&ctx, surfID);
  flags_high = HIBYTE(surfID->flags);
  firstvertindex = surfID->firstvertindex;
  if ( HIBYTE(surfID->flags) != 0 )
  {
    pUV = &texCoords->x;
    p_z = &verts->z;
    v8 = (Vector2D *)lightCoords;
    v17 = 2 * firstvertindex;
    v15 = &verts->z;
    v9 = &(*lightCoords)[2];
    v14 = flags_high;
    do
    {
      v10 = &pBrushData->vertexes[pBrushData->vertindices[v17 / 2]];
      if ( verts != nullptr )
      {
        *(p_z - 2) = v10->position.x;
        *(p_z - 1) = v10->position.y;
        *p_z = v10->position.z;
      }
      if ( texCoords != nullptr )
        SurfComputeTextureCoordinate(surfID, vec: &v10->position, pUV);
      if ( lightCoords != nullptr )
      {
        SurfComputeLightmapCoordinate(&ctx, surfID, vec: &v10->position, uv: v8);
        if ( (surfID->flags & 8) != 0 )
        {
          m_BumpSTexCoordOffset = ctx.m_BumpSTexCoordOffset;
          v9[-1].x = ctx.m_BumpSTexCoordOffset + v8->x;
          v9[-1].y = v8->y;
          v9->x = (float)(m_BumpSTexCoordOffset * 2.0) + v8->x;
          v9->y = v8->y;
          v9[1].x = (float)(m_BumpSTexCoordOffset * 3.0) + v8->x;
          v9[1].y = v8->y;
        }
      }
      v17 += 2;
      pUV += 2;
      p_z = v15 + 3;
      v8 += 4;
      v9 += 4;
      v12 = v14-- == 1;
      v15 += 3;
    }
    while ( !v12 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C7EB0
// Name: void BuildMSurfacePrimVerts(struct worldbrushdata_t __near *,struct mprimitive_t __near *,class CMeshBuilder __near &,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildMSurfacePrimVerts(
        worldbrushdata_t *pBrushData,
        mprimitive_t *prim,
        CMeshBuilder *builder,
        msurface2_t *surfID)
{
  float *m_pCurrNormal; // edx
  mprimvert_t *v6; // eax
  float *m_pCurrPosition; // ecx
  cplane_t *plane; // ecx
  double z; // st7
  float *v10; // ecx
  float *v11; // ecx
  Vector tVect; // [esp+4h] [ebp-24h] BYREF
  Vector tangentT; // [esp+10h] [ebp-18h] BYREF
  Vector tangentS; // [esp+1Ch] [ebp-Ch] BYREF
  int i; // [esp+3Ch] [ebp+14h]

  if ( (surfID->flags & 0x100) != 0 )
    TangentSpaceSurfaceSetup(surfID, &tVect);
  i = 0;
  if ( prim->vertCount != 0 )
  {
    do
    {
      m_pCurrNormal = builder->m_VertexBuilder.m_pCurrNormal;
      v6 = &pBrushData->primverts[i + prim->firstVert];
      m_pCurrPosition = builder->m_VertexBuilder.m_pCurrPosition;
      *m_pCurrPosition = v6->pos.x;
      m_pCurrPosition[1] = v6->pos.y;
      m_pCurrPosition[2] = v6->pos.z;
      plane = surfID->plane;
      *m_pCurrNormal = plane->normal.x;
      m_pCurrNormal[1] = plane->normal.y;
      z = plane->normal.z;
      v10 = builder->m_VertexBuilder.m_pCurrTexCoord[0];
      m_pCurrNormal[2] = z;
      *v10 = v6->texCoord[0];
      v10[1] = v6->texCoord[1];
      v11 = builder->m_VertexBuilder.m_pCurrTexCoord[1];
      *v11 = v6->lightCoord[0];
      v11[1] = v6->lightCoord[1];
      if ( (surfID->flags & 0x100) != 0 )
      {
        TangentSpaceComputeBasis(&tangentS, &tangentT, normal: &surfID->plane->normal, &tVect, negateTangent: false);
        *(Vector *)((char *)builder->m_VertexBuilder.m_pTangentS
                  + builder->m_VertexBuilder.m_nCurrentVertex * builder->m_VertexBuilder.m_VertexSize_TangentS) = tangentS;
        *(Vector *)((char *)builder->m_VertexBuilder.m_pTangentT
                  + builder->m_VertexBuilder.m_nCurrentVertex * builder->m_VertexBuilder.m_VertexSize_TangentT) = tangentT;
      }
      CVertexBuilder::AdvanceVertex(this: &builder->m_VertexBuilder);
      ++i;
    }
    while ( i < prim->vertCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C8010
// Name: public: struct msurface2_t __near * CMSurfaceSortList::GetSurfaceAtHead(struct surfacesortgroup_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
msurface2_t *__thiscall CMSurfaceSortList::GetSurfaceAtHead(CMSurfaceSortList *this, const surfacesortgroup_t *group)
{
  if ( group->listHead == -1 )
    return nullptr;
  else
    return this->m_list.m_Memory.m_pMemory[group->listHead].pSurfaces[0];
}

//------------------------------------------------------------------------------
// Address: 0x100C8660
// Name: mat_crosshair_edit
// Source: json
//------------------------------------------------------------------------------
void __usercall mat_crosshair_edit(int a1@<edi>)
{
  IMaterial *MaterialAtCrossHair; // esi
  const char *v2; // eax
  const char *v3; // eax
  CP4File *v4; // esi
  char chResolveName[256]; // [esp+4h] [ebp-200h] BYREF
  char chResolveNameArg[256]; // [esp+104h] [ebp-100h] BYREF

  MaterialAtCrossHair = GetMaterialAtCrossHair();
  if ( MaterialAtCrossHair != nullptr )
  {
    memset(chResolveName, 0, sizeof(chResolveName));
    memset(chResolveNameArg, 0, sizeof(chResolveNameArg));
    v2 = (const char *)((int (__thiscall *)(IMaterial *, int))MaterialAtCrossHair->GetName)(
                         a1: MaterialAtCrossHair,
                         a2: a1);
    V_snprintf(pDest: chResolveNameArg, maxLen: 255, pFormat: "materials/%s.vmt", v2);
    v3 = g_pFileSystem->RelativePathToFullPath(
           this: g_pFileSystem,
           a2: chResolveNameArg,
           a3: "game",
           a4: chResolveName,
           a5: 255,
           a6: 0,
           a7: 0);
    if ( p4 != nullptr )
    {
      v4 = CP4Factory::AccessFile(this: g_p4factory, szFilename: v3);
      v4->Edit(this: v4);
      v4->Add(this: v4);
      ((void (__thiscall *)(CP4File *, int))v4->dtr_CP4File)(a1: v4, a2: 1);
    }
    else
    {
      _Warning(a1: "run with -p4 to get p4 operations upon mat_crosshair_edit\n");
    }
    ((void (__thiscall *)(vgui::ISystem *, const char *))g_pVGuiSystem->ShellExecute)(a1: g_pVGuiSystem, a2: "open");
  }
  else
  {
    ConMsg(a1: "no/bad material\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C8770
// Name: void MaterialSystem_CreateSortinfo(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MaterialSystem_CreateSortinfo()
{
  signed int v0; // esi
  void *v1; // esp
  signed int v2; // eax
  IMaterial **v3; // ecx
  MaterialSystem_SortInfo_t *v4; // edx
  int lightmapPageID; // edx
  IMatRenderContext *m_pObject; // ebx
  void *v7; // esp
  signed int v8; // eax
  IMaterial **v9; // ecx
  worldbrushdata_t *worldbrush; // eax
  int v11; // ecx
  int v12; // esi
  _DWORD v13[3]; // [esp+0h] [ebp-10h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+Ch] [ebp-4h]

  v0 = materials->GetNumSortIDs(this: materials);
  materialSortInfoArray = (MaterialSystem_SortInfo_t *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)v0 >> 29 != 0 ? -1 : 8 * v0);
  materials->GetSortInfo(this: materials, a2: materialSortInfoArray);
  v1 = alloca(12 * v0);
  v2 = 0;
  if ( v0 > 0 )
  {
    v3 = (IMaterial **)v13;
    do
    {
      v4 = materialSortInfoArray;
      *v3 = materialSortInfoArray[v2].material;
      lightmapPageID = v4[v2].lightmapPageID;
      v3[2] = (IMaterial *)v2;
      v3[1] = (IMaterial *)lightmapPageID;
      ++v2;
      v3 += 3;
    }
    while ( v2 < v0 );
  }
  m_pObject = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  pSortMapRenderContext = m_pObject;
  qsort(base: v13, num: v0, width: 0xCu, comp: SortMapCompareFunc);
  v7 = alloca(4 * v0);
  v8 = 0;
  if ( v0 > 0 )
  {
    v9 = (IMaterial **)v13;
    do
    {
      materialSortInfoArray[v8].material = *v9;
      materialSortInfoArray[v8].lightmapPageID = (int)v9[1];
      v13[(_DWORD)v9[2]] = v8++;
      v9 += 3;
    }
    while ( v8 < v0 );
    m_pObject = pRenderContext.m_pObject;
  }
  worldbrush = host_state.worldbrush;
  v11 = 0;
  if ( host_state.worldbrush->numsurfaces > 0 )
  {
    v12 = 0;
    do
    {
      worldbrush->surfaces2[v12].materialSortID = v13[worldbrush->surfaces2[v12].materialSortID];
      worldbrush = host_state.worldbrush;
      ++v11;
      ++v12;
    }
    while ( v11 < host_state.worldbrush->numsurfaces );
  }
  GenerateTexCoordsForPrimVerts();
  WorldStaticMeshCreate();
  if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue != 0 )
    MaterialSytsem_DoBumpWarnings();
  if ( m_pObject != nullptr )
  {
    m_pObject->EndRender(this: m_pObject);
    m_pObject->Release(this: m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C90D0
// Name: public: void CMSurfaceSortList::AddSurfaceToTail(struct msurface2_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMSurfaceSortList::AddSurfaceToTail(
        CMSurfaceSortList *this,
        msurface2_t *pSurface,
        int sortGroup,
        int sortID)
{
  unsigned __int8 *m_pMemory; // edx
  int v6; // edi
  char v7; // cl
  surfacesortgroup_t *v8; // esi
  int v9; // edi
  int flags_high; // eax
  __int16 v11; // di
  int v12; // ecx
  int listTail; // eax
  materiallist_t *v14; // eax
  int v15; // eax
  bool v16; // zf
  int v17; // eax
  int v18; // ecx
  CUtlMemory<S3RGBA,int> *v19; // edi
  int m_nAllocationCount; // eax
  S3RGBA *v21; // edx
  int v22; // eax
  surfacesortgroup_t **v23; // edx
  materiallist_t *v24; // eax
  int sortGroupa; // [esp+18h] [ebp+Ch]
  int sortIDa; // [esp+1Ch] [ebp+10h]

  m_pMemory = this->m_groupUsed.m_Memory.m_pMemory;
  v6 = sortID + this->groupOffset[sortGroup];
  v7 = (sortID + LOBYTE(this->groupOffset[sortGroup])) & 7;
  v8 = &this->m_groups.m_Memory.m_pMemory[v6];
  v9 = v6 >> 3;
  if ( ((unsigned __int8)(1 << v7) & m_pMemory[v9]) == 0 )
  {
    v8->listHead = -1;
    v8->listTail = -1;
    m_pMemory[v9] |= 1 << v7;
    v8->vertexCount = 0;
    v8->groupListIndex = -1;
    v8->vertexCountNoDetail = 0;
    v8->indexCountNoDetail = 0;
    v8->triangleCount = 0;
    v8->surfaceCount = 0;
  }
  flags_high = HIBYTE(pSurface->flags);
  v8->vertexCount += flags_high;
  v11 = -1;
  v12 = flags_high - 2;
  if ( (pSurface->flags & 2) != 0 )
  {
    v8->vertexCountNoDetail += flags_high;
    v8->indexCountNoDetail += 3 * v12;
  }
  v8->triangleCount += v12;
  listTail = v8->listTail;
  ++v8->surfaceCount;
  if ( listTail != -1 )
  {
    v14 = &this->m_list.m_Memory.m_pMemory[listTail];
    if ( v14->count < 0xEu )
    {
      v14->pSurfaces[v14->count++] = pSurface;
      return;
    }
    v11 = v8->listTail;
  }
  LOWORD(v15) = CUtlVector<materiallist_t,CUtlMemory<materiallist_t,int>>::AddToTail(this: &this->m_list);
  if ( v11 >= 0 )
    this->m_list.m_Memory.m_pMemory[v11].nextBlock = (__int16)v15;
  v16 = v8->listHead == -1;
  v15 = (__int16)v15;
  sortIDa = v15;
  v8->listTail = (__int16)v15;
  if ( v16 )
  {
    v17 = 5 * sortGroup + 15;
    v18 = *(&this->m_list.m_Size + v17);
    v19 = (CUtlMemory<S3RGBA,int> *)(&this->m_list.m_Memory.m_pMemory + v17);
    m_nAllocationCount = v19->m_nAllocationCount;
    sortGroupa = v18;
    if ( v18 + 1 > m_nAllocationCount )
    {
      CUtlMemory<INetMessage *,int>::Grow(this: v19, num: v18 - m_nAllocationCount + 1);
      v18 = sortGroupa;
    }
    ++v19[1].m_pMemory;
    v21 = v19->m_pMemory;
    v22 = (int)v19[1].m_pMemory - v18 - 1;
    v19[1].m_nAllocationCount = (int)v19->m_pMemory;
    if ( v22 > 0 )
    {
      _V_memmove(dest: &v21[v18 + 1], src: &v21[v18], count: 4 * v22);
      v18 = sortGroupa;
    }
    v15 = sortIDa;
    v23 = (surfacesortgroup_t **)&v19->m_pMemory[v18];
    if ( v23 != nullptr )
      *v23 = v8;
    v8->groupListIndex = v18;
    v8->listHead = sortIDa;
  }
  v24 = &this->m_list.m_Memory.m_pMemory[v15];
  v24->nextBlock = -1;
  v24->count = 1;
  v24->pSurfaces[0] = pSurface;
}

//------------------------------------------------------------------------------
// Address: 0x100C9230
// Name: public: void CMSurfaceSortList::GetSurfaceListForGroup(class CUtlVector<struct msurface2_t __near *,class CUtlMemory<struct msurface2_t __near *,int>> __near &,struct surfacesortgroup_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMSurfaceSortList::GetSurfaceListForGroup(
        CMSurfaceSortList *this,
        CUtlMemory<S3RGBA,int> *list,
        const surfacesortgroup_t *group)
{
  __int16 listHead; // ax
  int v5; // eax
  char *v6; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  msurface2_t **v9; // ecx
  int v10; // eax
  msurface2_t **v11; // eax
  CMSurfaceSortList *i; // [esp+0h] [ebp-Ch]
  int v13; // [esp+4h] [ebp-8h]
  msurface2_t *surfID; // [esp+8h] [ebp-4h]
  int _index; // [esp+14h] [ebp+8h]
  const surfacesortgroup_t *groupa; // [esp+18h] [ebp+Ch]

  listHead = group->listHead;
  for ( i = this; listHead != -1; listHead = *(_WORD *)((char *)&this->m_list.m_Memory.m_pMemory->nextBlock + v5) )
  {
    v5 = listHead << 6;
    v6 = (char *)this->m_list.m_Memory.m_pMemory + v5;
    v13 = v5;
    _index = 0;
    if ( *((int *)v6 + 1) > 0 )
    {
      groupa = (const surfacesortgroup_t *)(v6 + 8);
      do
      {
        m_pMemory = (int)list[1].m_pMemory;
        surfID = (msurface2_t *)groupa->listHead;
        m_nAllocationCount = list->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<INetMessage *,int>::Grow(this: list, num: m_pMemory - m_nAllocationCount + 1);
        ++list[1].m_pMemory;
        v9 = (msurface2_t **)list->m_pMemory;
        v10 = (int)list[1].m_pMemory - m_pMemory - 1;
        list[1].m_nAllocationCount = (int)list->m_pMemory;
        if ( v10 > 0 )
          _V_memmove(dest: &v9[m_pMemory + 1], src: &v9[m_pMemory], count: 4 * v10);
        v11 = (msurface2_t **)&list->m_pMemory[m_pMemory];
        if ( v11 != nullptr )
          *v11 = surfID;
        groupa = (const surfacesortgroup_t *)((char *)groupa + 4);
        ++_index;
      }
      while ( _index < *((_DWORD *)v6 + 1) );
      v5 = v13;
      this = i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C9300
// Name: void MaterialSystem_RegisterLightmapSurfaces(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MaterialSystem_RegisterLightmapSurfaces()
{
  worldbrushdata_t *worldbrush; // edi
  int numsurfaces; // eax
  UtlRBTreeNode_t<msurface2_t *,int> *v2; // eax
  int v3; // ebx
  msurface2_t *v4; // eax
  int v5; // eax
  UtlRBTreeNode_t<msurface2_t *,int> *m_pMemory; // ecx
  int v7; // edx
  int v8; // esi
  int v9; // edx
  int v10; // ebx
  msurface2_t *m_Data; // esi
  CUtlRBTree<msurface2_t *,int,bool (__cdecl*)(msurface2_t * const &,msurface2_t * const &),CUtlMemory<UtlRBTreeNode_t<msurface2_t *,int>,int> > surfaces; // [esp+8h] [ebp-34h] BYREF
  int surfaceIndex; // [esp+2Ch] [ebp-10h]
  int parent; // [esp+30h] [ebp-Ch] BYREF
  msurface2_t *surfID; // [esp+34h] [ebp-8h] BYREF
  bool leftchild; // [esp+3Bh] [ebp-1h] BYREF

  surfID = nullptr;
  materials->BeginLightmapAllocation(this: materials);
  worldbrush = host_state.worldbrush;
  numsurfaces = host_state.worldbrush->numsurfaces;
  surfaces.m_LessFunc = LightmapLess;
  surfaces.m_Elements.m_pMemory = nullptr;
  surfaces.m_Elements.m_nAllocationCount = numsurfaces;
  surfaces.m_Elements.m_nGrowSize = 0;
  if ( numsurfaces != 0 )
  {
    v2 = (UtlRBTreeNode_t<msurface2_t *,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 20 * numsurfaces);
    worldbrush = host_state.worldbrush;
    surfaces.m_Elements.m_pMemory = v2;
  }
  surfaces.m_Root = -1;
  surfaces.m_NumElements = 0;
  surfaces.m_FirstFree = -1;
  surfaces.m_LastAlloc.index = -1;
  surfaces.m_pElements = surfaces.m_Elements.m_pMemory;
  surfaceIndex = 0;
  if ( worldbrush->numsurfaces > 0 )
  {
    v3 = 0;
    do
    {
      v4 = &worldbrush->surfaces2[v3];
      surfID = v4;
      if ( (worldbrush->texinfo[*((unsigned __int16 *)v4 + 11) >> 1].flags & 0x400) != 0 || (v4->flags & 1) != 0 )
        v4->flags |= 1u;
      else
        v4->flags &= ~1u;
      parent = -1;
      leftchild = false;
      CUtlRBTree<msurface2_t *,int,bool (__cdecl *)(msurface2_t * const &,msurface2_t * const &),CUtlMemory<UtlRBTreeNode_t<msurface2_t *,int>,int>>::FindInsertionPosition(
        this: &surfaces,
        insert: &surfID,
        &parent,
        &leftchild);
      v5 = CUtlRBTree<msurface2_t *,int,bool (__cdecl *)(msurface2_t * const &,msurface2_t * const &),CUtlMemory<UtlRBTreeNode_t<msurface2_t *,int>,int>>::NewNode(this: (CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *)&surfaces);
      m_pMemory = surfaces.m_Elements.m_pMemory;
      v7 = parent;
      v8 = v5;
      surfaces.m_Elements.m_pMemory[v8].m_Parent = parent;
      m_pMemory[v8].m_Right = -1;
      m_pMemory[v8].m_Left = -1;
      m_pMemory[v8].m_Tag = 0;
      if ( v7 == -1 )
      {
        surfaces.m_Root = v5;
      }
      else
      {
        v9 = v7;
        if ( leftchild )
          m_pMemory[v9].m_Left = v5;
        else
          m_pMemory[v9].m_Right = v5;
      }
      CUtlRBTree<msurface2_t *,int,bool (__cdecl *)(msurface2_t * const &,msurface2_t * const &),CUtlMemory<UtlRBTreeNode_t<msurface2_t *,int>,int>>::InsertRebalance(
        this: &surfaces,
        elem: v5);
      ++surfaces.m_NumElements;
      if ( &surfaces.m_Elements.m_pMemory[v8] != (UtlRBTreeNode_t<msurface2_t *,int> *)-16 )
        surfaces.m_Elements.m_pMemory[v8].m_Data = surfID;
      worldbrush = host_state.worldbrush;
      ++v3;
      ++surfaceIndex;
    }
    while ( surfaceIndex < host_state.worldbrush->numsurfaces );
  }
  surfID = nullptr;
  v10 = CUtlRBTree<msurface2_t *,int,bool (__cdecl *)(msurface2_t * const &,msurface2_t * const &),CUtlMemory<UtlRBTreeNode_t<msurface2_t *,int>,int>>::FirstInorder(this: &surfaces);
  if ( v10 != -1 )
  {
    while ( 1 )
    {
      m_Data = surfaces.m_Elements.m_pMemory[v10].m_Data;
      if ( (m_Data->flags & 1) != 0 )
      {
        m_Data->materialSortID = materials->AllocateWhiteLightmap(
                                   this: materials,
                                   a2: worldbrush->texinfo[*((unsigned __int16 *)m_Data + 11) >> 1].material);
        *(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_OffsetIntoLightmapPage
                   + (((char *)m_Data - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0)) = 0;
        *(__int16 *)((char *)&host_state.worldbrush->surfacelighting->m_OffsetIntoLightmapPage[1]
                   + (((char *)m_Data - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0)) = 0;
      }
      else
      {
        RegisterLightmappedSurface(surfID: surfaces.m_Elements.m_pMemory[v10].m_Data);
      }
      v10 = CUtlRBTree<msurface2_t *,int,bool (__cdecl *)(msurface2_t * const &,msurface2_t * const &),CUtlMemory<UtlRBTreeNode_t<msurface2_t *,int>,int>>::NextInorder(
              this: &surfaces,
              i: v10);
      if ( v10 == -1 )
        break;
      worldbrush = host_state.worldbrush;
    }
  }
  materials->EndLightmapAllocation(this: materials);
  CUtlRBTree<msurface2_t *,int,bool (__cdecl *)(msurface2_t * const &,msurface2_t * const &),CUtlMemory<UtlRBTreeNode_t<msurface2_t *,int>,int>>::RemoveAll(this: &surfaces);
  if ( surfaces.m_Elements.m_nGrowSize >= 0 && surfaces.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: surfaces.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100C9560
// Name: public: void CMSurfaceSortList::Init(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMSurfaceSortList::Init(CMSurfaceSortList *this, int maxSortIDs, int minMaterialLists)
{
  materiallist_t *m_pMemory; // edx
  materiallist_t *v5; // eax
  int v6; // esi
  int m_Size; // ecx
  int v8; // eax
  int v9; // ebx
  int m_nAllocationCount; // eax
  unsigned __int8 *v11; // edx
  int v12; // eax
  int v13; // ebx
  CUtlVector<surfacesortgroup_t *,CUtlMemory<surfacesortgroup_t *,int> > *m_sortGroupLists; // esi
  int v15; // eax
  surfacesortgroup_t **v16; // eax
  unsigned int v17; // [esp-4h] [ebp-10h]
  unsigned int v18; // [esp-4h] [ebp-10h]
  int maxSortIDsa; // [esp+14h] [ebp+8h]
  int groupBytes; // [esp+18h] [ebp+Ch]
  int *groupBytesa; // [esp+18h] [ebp+Ch]

  this->m_list.m_Size = 0;
  if ( this->m_list.m_Memory.m_nAllocationCount < minMaterialLists && this->m_list.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_list.m_Memory.m_pMemory;
    this->m_list.m_Memory.m_nAllocationCount = minMaterialLists;
    v17 = minMaterialLists << 6;
    if ( m_pMemory != nullptr )
      v5 = (materiallist_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v17);
    else
      v5 = (materiallist_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v17);
    this->m_list.m_Memory.m_pMemory = v5;
  }
  this->m_list.m_pElements = this->m_list.m_Memory.m_pMemory;
  v6 = 4 * maxSortIDs;
  this->m_maxSortIDs = maxSortIDs;
  this->m_groups.m_Size = 0;
  if ( 4 * maxSortIDs > 0 )
    CUtlVector<surfacesortgroup_t,CUtlMemory<surfacesortgroup_t,int>>::InsertMultipleBefore(
      this: &this->m_groups,
      elem: 0,
      num: v6);
  m_Size = this->m_groupUsed.m_Size;
  v8 = (v6 + 7) >> 3;
  groupBytes = v8;
  maxSortIDsa = m_Size;
  if ( m_Size < v8 )
  {
    v9 = v8 - m_Size;
    if ( v8 != m_Size )
    {
      m_nAllocationCount = this->m_groupUsed.m_Memory.m_nAllocationCount;
      if ( m_Size + v9 > m_nAllocationCount )
      {
        CUtlMemory<bool,int>::Grow(
          this: (CUtlMemory<char,int> *)&this->m_groupUsed,
          num: v9 + m_Size - m_nAllocationCount);
        m_Size = maxSortIDsa;
      }
      this->m_groupUsed.m_Size += v9;
      v11 = this->m_groupUsed.m_Memory.m_pMemory;
      v12 = this->m_groupUsed.m_Size - m_Size - v9;
      this->m_groupUsed.m_pElements = v11;
      if ( v12 > 0 && v9 > 0 )
        _V_memmove(dest: &v11[m_Size + v9], src: &v11[m_Size], count: v12);
      v8 = groupBytes;
    }
  }
  _V_memset(dest: this->m_groupUsed.m_Memory.m_pMemory, fill: 0, count: v8);
  v13 = 0;
  groupBytesa = this->groupOffset;
  m_sortGroupLists = this->m_sortGroupLists;
  do
  {
    v15 = v13 != 0 ? 16 : 128;
    m_sortGroupLists->m_Size = 0;
    if ( m_sortGroupLists->m_Memory.m_nAllocationCount < v15 && m_sortGroupLists->m_Memory.m_nGrowSize >= 0 )
    {
      m_sortGroupLists->m_Memory.m_nAllocationCount = v15;
      v18 = 4 * v15;
      if ( m_sortGroupLists->m_Memory.m_pMemory != nullptr )
        v16 = (surfacesortgroup_t **)_g_pMemAlloc->Realloc_2(
                                       this: _g_pMemAlloc,
                                       a2: m_sortGroupLists->m_Memory.m_pMemory,
                                       a3: v18);
      else
        v16 = (surfacesortgroup_t **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v18);
      m_sortGroupLists->m_Memory.m_pMemory = v16;
    }
    m_sortGroupLists->m_pElements = m_sortGroupLists->m_Memory.m_pMemory;
    *groupBytesa = v13 * this->m_maxSortIDs;
    ++v13;
    ++m_sortGroupLists;
    ++groupBytesa;
  }
  while ( v13 < 4 );
  this->m_emptyGroup.listHead = -1;
  this->m_emptyGroup.listTail = -1;
  this->m_emptyGroup.vertexCount = 0;
  this->m_emptyGroup.groupListIndex = -1;
  this->m_emptyGroup.vertexCountNoDetail = 0;
  this->m_emptyGroup.indexCountNoDetail = 0;
  this->m_emptyGroup.triangleCount = 0;
  this->m_emptyGroup.surfaceCount = 0;
}

} // namespace engine_xlsp
