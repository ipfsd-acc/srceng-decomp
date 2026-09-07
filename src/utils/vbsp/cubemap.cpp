// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vbsp/cubemap.cpp
// Functions: 14
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00404540
// Name: void VectorScale(class Vector const __near &,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VectorScale(const Vector *in, float scale, Vector *result)
{
  result->x = in->x * scale;
  result->y = in->y * scale;
  result->z = in->z * scale;
}

//------------------------------------------------------------------------------
// Address: 0x004045A0
// Name: void Cubemap_InsertSample(class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cubemap_InsertSample(const Vector *origin, unsigned __int8 size)
{
  int v2; // edx
  dcubemapsample_t *v3; // eax

  v2 = g_nCubemapSamples;
  v3 = &g_CubemapSamples[g_nCubemapSamples];
  v3->origin[0] = (int)origin->x;
  v3->origin[1] = (int)origin->y;
  v3->origin[2] = (int)origin->z;
  v3->size = size;
  g_nCubemapSamples = v2 + 1;
}

//------------------------------------------------------------------------------
// Address: 0x004045E0
// Name: FindDependentMaterial
// Source: json
//------------------------------------------------------------------------------
char *__usercall FindDependentMaterial@<eax>(const char *pMaterialName@<edi>, const char **ppMaterialVar)
{
  int v2; // ebx
  const char **v3; // esi

  v2 = 0;
  if ( *s_pDependentMaterialVar[0] == 0 )
    return nullptr;
  v3 = s_pDependentMaterialVar;
  while ( !GetValueFromMaterial(pMaterialName, pKey: *v3, pValue: pDependentMaterialName, len: 511) )
  {
LABEL_6:
    v3 = &s_pDependentMaterialVar[++v2];
    if ( **v3 == 0 )
      return nullptr;
  }
  if ( _V_stricmp(s1: pDependentMaterialName, s2: pMaterialName) == 0 )
  {
    _Warning(a1: "Material %s is depending on itself through materialvar %s! Ignoring...\n", pMaterialName, *v3);
    goto LABEL_6;
  }
  if ( ppMaterialVar != nullptr )
    *ppMaterialVar = s_pDependentMaterialVar[v2];
  return pDependentMaterialName;
}

//------------------------------------------------------------------------------
// Address: 0x00404680
// Name: PatchEnvmapForMaterialAndDependents
// Source: json
//------------------------------------------------------------------------------
char __cdecl PatchEnvmapForMaterialAndDependents(
        const char *pMaterialName,
        const PatchInfo_t *info,
        const char *pCubemapTexture)
{
  char *DependentMaterial; // eax
  const char *v4; // ebx
  char *i; // eax
  int v7; // edi
  char *j; // eax
  int v9; // eax
  char pPatchedMaterialName[1024]; // [esp+Ch] [ebp-820h] BYREF
  char pDependentPatchedMaterialName[1024]; // [esp+40Ch] [ebp-420h] BYREF
  MaterialPatchInfo_t pPatchInfo[2]; // [esp+80Ch] [ebp-20h] BYREF
  const char *pDependentMaterialVar; // [esp+824h] [ebp-8h] BYREF
  bool bShouldPatchEnvCubemap; // [esp+82Ah] [ebp-2h]
  bool bDependentMaterialPatched; // [esp+82Bh] [ebp-1h]

  bShouldPatchEnvCubemap = DoesMaterialHaveKeyValuePair(pMaterialName, pKeyName: "$envmap", pSearchValue: "env_cubemap");
  bDependentMaterialPatched = false;
  pDependentMaterialVar = nullptr;
  DependentMaterial = FindDependentMaterial(pMaterialName, ppMaterialVar: &pDependentMaterialVar);
  v4 = DependentMaterial;
  if ( DependentMaterial != nullptr )
    bDependentMaterialPatched = PatchEnvmapForMaterialAndDependents(
                                  pMaterialName: DependentMaterial,
                                  info,
                                  pCubemapTexture);
  if ( !bShouldPatchEnvCubemap && !bDependentMaterialPatched )
    return 0;
  if ( V_snprintf(
         pDest: pPatchedMaterialName,
         maxLen: 1024,
         pFormat: "maps/%s/%s%s%d_%d_%d",
         info->m_pMapName,
         pMaterialName,
         "_",
         info->m_pOrigin[0],
         info->m_pOrigin[1],
         info->m_pOrigin[2]) >= 127 )
    _Error(a1: "Generated env_cubemap patch name : %s too long! (max = %d)\n", pPatchedMaterialName, 128);
  for ( i = pPatchedMaterialName; *i != 0; ++i )
  {
    if ( *i == 92 )
      *i = 47;
  }
  _V_strlower(start: pPatchedMaterialName);
  v7 = 0;
  memset(pPatchInfo, 0, sizeof(pPatchInfo));
  if ( bShouldPatchEnvCubemap )
  {
    pPatchInfo[0].m_pKey = "$envmap";
    pPatchInfo[0].m_pRequiredOriginalValue = "env_cubemap";
    pPatchInfo[0].m_pValue = pCubemapTexture;
    v7 = 1;
  }
  if ( bDependentMaterialPatched )
  {
    if ( V_snprintf(
           pDest: pDependentPatchedMaterialName,
           maxLen: 1024,
           pFormat: "maps/%s/%s%s%d_%d_%d",
           info->m_pMapName,
           v4,
           "_",
           info->m_pOrigin[0],
           info->m_pOrigin[1],
           info->m_pOrigin[2]) >= 127 )
      _Error(a1: "Generated env_cubemap patch name : %s too long! (max = %d)\n", pDependentPatchedMaterialName, 128);
    for ( j = pDependentPatchedMaterialName; *j != 0; ++j )
    {
      if ( *j == 92 )
        *j = 47;
    }
    _V_strlower(start: pDependentPatchedMaterialName);
    v9 = v7;
    pPatchInfo[v9].m_pKey = pDependentMaterialVar;
    pPatchInfo[v9].m_pValue = pDependentPatchedMaterialName;
    ++v7;
  }
  CreateMaterialPatch(
    pOriginalMaterialName: pMaterialName,
    pNewMaterialName: pPatchedMaterialName,
    nKeys: v7,
    pInfo: pPatchInfo,
    nPatchType: PATCH_REPLACE);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404860
// Name: bool DoesMaterialOrDependentsUseEnvmap(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl DoesMaterialOrDependentsUseEnvmap(const char *pPatchedMaterialName)
{
  const char *OriginalMaterialNameForPatchedMaterial; // edi
  char *DependentMaterial; // eax

  OriginalMaterialNameForPatchedMaterial = GetOriginalMaterialNameForPatchedMaterial(pPatchMaterialName: pPatchedMaterialName);
  if ( DoesMaterialHaveKey(pMaterialName: OriginalMaterialNameForPatchedMaterial, pKeyName: "$envmap") )
    return 1;
  while ( 1 )
  {
    DependentMaterial = FindDependentMaterial(
                          pMaterialName: OriginalMaterialNameForPatchedMaterial,
                          ppMaterialVar: nullptr);
    if ( DependentMaterial == nullptr )
      break;
    OriginalMaterialNameForPatchedMaterial = GetOriginalMaterialNameForPatchedMaterial(pPatchMaterialName: DependentMaterial);
    if ( DoesMaterialHaveKey(pMaterialName: OriginalMaterialNameForPatchedMaterial, pKeyName: "$envmap") )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004048C0
// Name: int Cubemap_FindClosestCubemap(class Vector const __near &,struct side_t __near *)
// Source: json
//------------------------------------------------------------------------------
winding_t *__usercall Cubemap_FindClosestCubemap@<eax>(plane_t *a1@<ebp>, const Vector *entityOrigin, side_t *pSide)
{
  side_t *v3; // edx
  winding_t *result; // eax
  int numpoints; // esi
  float v6; // xmm0_4
  int v7; // edi
  float v8; // xmm3_4
  float v9; // xmm1_4
  Vector *p; // ecx
  float *p_z; // eax
  float *v12; // ecx
  unsigned int v13; // edx
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm3_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm3_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float *p_x; // eax
  int v25; // ecx
  float v26; // xmm6_4
  float v27; // xmm2_4
  float v28; // xmm5_4
  float x; // xmm3_4
  float v30; // xmm4_4
  float z; // xmm5_4
  int v32; // eax
  int v33; // esi
  float y; // xmm3_4
  float v35; // xmm5_4
  int *v36; // edi
  unsigned int v37; // xmm1_4
  unsigned int v38; // xmm2_4
  float v39; // ecx
  int *v40; // edx
  __int128 v41; // xmm0
  __int128 v42; // [esp-10h] [ebp-3Ch] BYREF
  Vector vecDelta; // [esp+0h] [ebp-2Ch]
  float v44; // [esp+Ch] [ebp-20h]
  Vector vecCenter; // [esp+10h] [ebp-1Ch]
  float flDist; // [esp+1Ch] [ebp-10h]
  plane_t *pPlane; // [esp+20h] [ebp-Ch]
  float flMinDist; // [esp+24h] [ebp-8h]
  float retaddr; // [esp+2Ch] [ebp+0h]

  pPlane = a1;
  flMinDist = retaddr;
  v3 = pSide;
  if ( pSide == nullptr )
    return (winding_t *)-1;
  result = pSide->winding;
  if ( result != nullptr )
  {
    numpoints = result->numpoints;
    v6 = 0.0;
    v7 = 0;
    v8 = 0.0;
    v9 = 0.0;
    if ( result->numpoints >= 4 )
    {
      p = result->p;
      p_z = &p->z;
      v12 = &p[1].z;
      v13 = ((unsigned int)(numpoints - 4) >> 2) + 1;
      v7 = 4 * v13;
      do
      {
        v14 = *(p_z - 2) + v6;
        v15 = *(p_z - 1) + v8;
        v16 = *p_z + v9;
        v17 = p_z[1] + v14;
        v18 = *(v12 - 1) + v15;
        v19 = *v12 + v16;
        v20 = p_z[4] + v17;
        v21 = v12[2] + v18;
        v22 = v12[3] + v19;
        v6 = p_z[7] + v20;
        v8 = v12[5] + v21;
        v23 = v12[6];
        p_z += 12;
        v12 += 12;
        --v13;
        v9 = v23 + v22;
      }
      while ( v13 != 0 );
      v3 = pSide;
    }
    if ( v7 < numpoints )
    {
      p_x = &v3->winding->p[v7].x;
      v25 = numpoints - v7;
      do
      {
        v6 = v6 + *p_x;
        v8 = v8 + p_x[1];
        v9 = v9 + p_x[2];
        p_x += 3;
        --v25;
      }
      while ( v25 != 0 );
    }
    v26 = 3.4028235e38;
    v27 = 1.0 / (float)numpoints;
    v28 = v27 * v8;
    x = entityOrigin->x;
    v30 = entityOrigin->y + v28;
    z = entityOrigin->z;
    LODWORD(vecCenter.y) = &g_MainMap->mapplanes[v3->planenum];
    v32 = g_nCubemapSamples;
    v33 = 0;
    y = x + (float)(v6 * v27);
    v35 = z + (float)(v9 * v27);
    vecDelta.y = y;
    vecDelta.z = v30;
    v44 = v35;
    flDist = NAN;
    vecCenter.z = 3.4028235e38;
    if ( g_nCubemapSamples > 0 )
    {
      v36 = &g_CubemapSamples[0].origin[2];
      while ( 1 )
      {
        *(float *)&v37 = (float)*(v36 - 1) - v30;
        *(float *)&v38 = (float)*v36 - v35;
        *((float *)&v42 + 1) = (float)*(v36 - 2) - y;
        *((_QWORD *)&v42 + 1) = __PAIR64__(v38, v37);
        vecCenter.x = VectorNormalize(vec: (Vector *)((char *)&v42 + 4));
        v26 = vecCenter.z;
        if ( (float)((float)((float)(*(float *)(LODWORD(vecCenter.y) + 4) * *((float *)&v42 + 2))
                           + (float)(*(float *)LODWORD(vecCenter.y) * *((float *)&v42 + 1)))
                   + (float)(*(float *)(LODWORD(vecCenter.y) + 8) * *((float *)&v42 + 3))) >= 0.0
          && vecCenter.z > vecCenter.x )
        {
          v26 = vecCenter.x;
          vecCenter.z = vecCenter.x;
          LODWORD(flDist) = v33;
        }
        v32 = g_nCubemapSamples;
        ++v33;
        v36 += 4;
        if ( v33 >= g_nCubemapSamples )
          break;
        v35 = v44;
        v30 = vecDelta.z;
        y = vecDelta.y;
      }
      if ( LODWORD(flDist) != -1 )
        return (winding_t *)LODWORD(flDist);
      v35 = v44;
      v30 = vecDelta.z;
      y = vecDelta.y;
    }
    v39 = 0.0;
    if ( v32 > 0 )
    {
      v40 = &g_CubemapSamples[0].origin[2];
      do
      {
        v41 = 0;
        *(float *)&v41 = fsqrt(
                           (float)((float)((float)((float)*(v40 - 1) - v30) * (float)((float)*(v40 - 1) - v30))
                                 + (float)((float)((float)*v40 - v35) * (float)((float)*v40 - v35)))
                         + (float)((float)((float)*(v40 - 2) - y) * (float)((float)*(v40 - 2) - y)));
        v42 = v41;
        if ( v26 > *(float *)&v41 )
        {
          v26 = *(float *)&v42;
          flDist = v39;
        }
        ++LODWORD(v39);
        v40 += 4;
      }
      while ( SLODWORD(v39) < v32 );
    }
    return (winding_t *)LODWORD(flDist);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004059C0
// Name: void CreateDefaultCubemaps(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateDefaultCubemaps(bool bHDR)
{
  IVTFTexture *VTFTexture; // esi
  int (__thiscall *FrameCount)(IVTFTexture *); // edx
  int i; // edi
  unsigned __int8 *v4; // ebx
  unsigned int v5; // eax
  int (__thiscall *v6)(IVTFTexture *); // eax
  int j; // edi
  char *v9; // eax
  char dstVTFFileName[1024]; // [esp+Ch] [ebp-53Ch] BYREF
  char vtfName[260]; // [esp+40Ch] [ebp-13Ch] BYREF
  CUtlBuffer outputBuf; // [esp+510h] [ebp-38h] BYREF
  int iFrame; // [esp+540h] [ebp-8h]
  int iFace; // [esp+544h] [ebp-4h]
  IZip *pak; // [esp+550h] [ebp+8h]

  memset(dst: (unsigned __int8 *)g_IsCubemapTexData, value: 0, count: sizeof(g_IsCubemapTexData));
  VTFTexture = CreateVTFTexture();
  VTFTexture->Init(this: VTFTexture, a2: 32, a3: 32, a4: 1, a5: IMAGE_FORMAT_DEFAULT, a6: 0x4000, a7: 1, a8: -1);
  FrameCount = VTFTexture->FrameCount;
  iFrame = 0;
  if ( FrameCount(this: VTFTexture) > 0 )
  {
    do
    {
      for ( iFace = 0; iFace < 6; ++iFace )
      {
        for ( i = 0; i < VTFTexture->MipCount(this: VTFTexture); ++i )
        {
          v4 = VTFTexture->ImageData_2(this: VTFTexture, a2: iFrame, a3: iFace, a4: i);
          v5 = VTFTexture->ComputeMipSize(this: VTFTexture, a2: i);
          memset(dst: v4, value: 0, count: v5);
        }
      }
      v6 = VTFTexture->FrameCount;
      ++iFrame;
    }
    while ( iFrame < v6(this: VTFTexture) );
  }
  VTFTexture->GenerateSpheremap(this: VTFTexture, a2: LOOK_DOWN_Z);
  VTFTexture->ConvertImageFormat(
    this: VTFTexture,
    a2: (ImageFormat)(bHDR ? IMAGE_FORMAT_RGBA16161616F : IMAGE_FORMAT_DXT5),
    a3: false,
    a4: false);
  if ( bHDR )
    sprintf(string: dstVTFFileName, format: "materials/maps/%s/cubemapdefault.hdr.vtf", mapbase);
  else
    sprintf(string: dstVTFFileName, format: "materials/maps/%s/cubemapdefault.vtf", mapbase);
  CUtlBuffer::CUtlBuffer(this: &outputBuf, growSize: 0, initSize: 0, nFlags: 0);
  if ( VTFTexture->Serialize(this: VTFTexture, a2: &outputBuf) )
  {
    pak = GetPakFile();
    AddBufferToPak(
      pak,
      pRelativeName: dstVTFFileName,
      data: outputBuf.m_Memory.m_pMemory,
      length: outputBuf.m_Put,
      bTextMode: false);
    for ( j = 0; j < s_DefaultCubemapNames.m_Size; ++j )
    {
      V_strncpy(pDest: vtfName, pSrc: s_DefaultCubemapNames.m_Memory.m_pMemory[j], maxLen: 260);
      if ( bHDR )
      {
        v9 = V_stristr(pStr: vtfName, pSearch: ".vtf");
        if ( v9 != nullptr )
          V_strncpy(pDest: v9, pSrc: ".hdr.vtf", maxLen: (char *)&outputBuf - v9);
      }
      if ( !FileExistsInPak(pak, pRelativeName: vtfName) )
        AddBufferToPak(
          pak,
          pRelativeName: vtfName,
          data: outputBuf.m_Memory.m_pMemory,
          length: outputBuf.m_Put,
          bTextMode: false);
    }
    DestroyVTFTexture(pTexture: VTFTexture);
    if ( outputBuf.m_Memory.m_nGrowSize >= 0 && outputBuf.m_Memory.m_pMemory != nullptr )
      goto LABEL_23;
  }
  else
  {
    _Warning(a1: "Error serializing default cubemap %s\n", dstVTFFileName);
    if ( outputBuf.m_Memory.m_nGrowSize >= 0 && outputBuf.m_Memory.m_pMemory != nullptr )
LABEL_23:
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: outputBuf.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405C40
// Name: void Cubemap_CreateDefaultCubemaps(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cubemap_CreateDefaultCubemaps()
{
  CreateDefaultCubemaps(bHDR: false);
  CreateDefaultCubemaps(bHDR: true);
}

//------------------------------------------------------------------------------
// Address: 0x00405E30
// Name: void Cubemap_AddUnreferencedCubemaps(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cubemap_AddUnreferencedCubemaps()
{
  int *v0; // ebx
  char *j; // eax
  int v2; // esi
  bool v3; // zf
  int v4; // edi
  int m_Size; // eax
  int v6; // esi
  int v7; // eax
  char *v8; // edx
  char *v9; // ecx
  char v10; // al
  char pFileName[1024]; // [esp+0h] [ebp-804h] BYREF
  char pTextureName[1024]; // [esp+400h] [ebp-404h] BYREF
  int i; // [esp+800h] [ebp-4h]

  i = 0;
  if ( g_nCubemapSamples > 0 )
  {
    v0 = &g_CubemapSamples[0].origin[2];
    do
    {
      V_snprintf(
        pDest: pTextureName,
        maxLen: 1024,
        pFormat: "maps/%s/%s%s%d_%d_%d",
        mapbase,
        "c",
        &defaultValue,
        *(v0 - 2),
        *(v0 - 1),
        *v0);
      for ( j = pTextureName; *j != 0; ++j )
      {
        if ( *j == 92 )
          *j = 47;
      }
      _V_strlower(start: pTextureName);
      v2 = 0;
      v3 = s_DefaultCubemapNames.m_Size == 0;
      if ( s_DefaultCubemapNames.m_Size > 0 )
      {
        do
        {
          if ( _V_stricmp(s1: s_DefaultCubemapNames.m_Memory.m_pMemory[v2], s2: pTextureName) == 0 )
            break;
          ++v2;
        }
        while ( v2 < s_DefaultCubemapNames.m_Size );
        v3 = v2 == s_DefaultCubemapNames.m_Size;
      }
      if ( v3 )
      {
        v4 = V_snprintf(pDest: pFileName, maxLen: 1024, pFormat: "materials/%s.vtf", pTextureName);
        m_Size = s_DefaultCubemapNames.m_Size;
        v6 = s_DefaultCubemapNames.m_Size;
        if ( s_DefaultCubemapNames.m_Size + 1 > s_DefaultCubemapNames.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CClassInput *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)&s_DefaultCubemapNames,
            num: s_DefaultCubemapNames.m_Size - s_DefaultCubemapNames.m_Memory.m_nAllocationCount + 1);
          m_Size = s_DefaultCubemapNames.m_Size;
        }
        s_DefaultCubemapNames.m_Size = m_Size + 1;
        v7 = m_Size - v6;
        s_DefaultCubemapNames.m_pElements = s_DefaultCubemapNames.m_Memory.m_pMemory;
        if ( v7 > 0 )
          _V_memmove(
            dest: &s_DefaultCubemapNames.m_Memory.m_pMemory[v6 + 1],
            src: &s_DefaultCubemapNames.m_Memory.m_pMemory[v6],
            count: 4 * v7);
        s_DefaultCubemapNames.m_Memory.m_pMemory[v6] = (char *)MemAlloc_Alloc(nSize: v4 + 1);
        v8 = s_DefaultCubemapNames.m_Memory.m_pMemory[v6];
        v9 = pFileName;
        do
        {
          v10 = *v9;
          *v8++ = *v9++;
        }
        while ( v10 != 0 );
      }
      v0 += 4;
      ++i;
    }
    while ( i < g_nCubemapSamples );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405FC0
// Name: void Cubemap_SaveBrushSides(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cubemap_SaveBrushSides(const char *pSideListStr)
{
  CUtlMemory<S3RGBA,int> *v1; // esi
  void *v2; // esp
  const char *i; // eax
  S3RGBA *m_pMemory; // edi
  int m_nAllocationCount; // eax
  S3RGBA *v6; // ecx
  int v7; // eax
  S3RGBA *v8; // eax
  char v9[12]; // [esp+0h] [ebp-Ch] BYREF

  v1 = (CUtlMemory<S3RGBA,int> *)&s_EnvCubemapToBrushSides.m_Memory.m_pMemory[CUtlVector<CUtlVector<int,CUtlMemory<int,int>>,CUtlMemory<CUtlVector<int,CUtlMemory<int,int>>,int>>::InsertBefore(
                                                                                this: &s_EnvCubemapToBrushSides,
                                                                                elem: s_EnvCubemapToBrushSides.m_Size)];
  v2 = alloca(strlen(pSideListStr) + 1);
  strcpy(v9, pSideListStr);
  for ( i = strtok(string: v9, control: " "); i != nullptr; i = strtok(string: nullptr, control: " ") )
  {
    if ( sscanf(string: i, format: "%d", &pSideListStr) == 1 )
    {
      m_pMemory = v1[1].m_pMemory;
      m_nAllocationCount = v1->m_nAllocationCount;
      if ( (int)&m_pMemory->g > m_nAllocationCount )
        CUtlMemory<CClassInput *,int>::Grow(this: v1, num: (int)(&m_pMemory->g - m_nAllocationCount));
      ++v1[1].m_pMemory;
      v6 = v1->m_pMemory;
      v7 = (char *)v1[1].m_pMemory - (char *)m_pMemory - 1;
      v1[1].m_nAllocationCount = (int)v1->m_pMemory;
      if ( v7 > 0 )
        _V_memmove(dest: &v6[(_DWORD)m_pMemory + 1], src: &v6[(_DWORD)m_pMemory], count: 4 * v7);
      v8 = &v1->m_pMemory[(_DWORD)m_pMemory];
      if ( v8 != nullptr )
        *v8 = (S3RGBA)pSideListStr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004060B0
// Name: Cubemap_CreateTexInfo
// Source: json
//------------------------------------------------------------------------------
int __usercall Cubemap_CreateTexInfo@<eax>(int *origin@<eax>, int originalTexInfo)
{
  int result; // eax
  int texdata; // edx
  const char *String; // eax
  const char *v6; // esi
  char *i; // eax
  int v8; // eax
  char v9; // bl
  char *v10; // eax
  unsigned int v11; // esi
  int v12; // edi
  char *v13; // edx
  char *v14; // ecx
  char v15; // al
  int v16; // [esp-10h] [ebp-E78h]
  int v17; // [esp-Ch] [ebp-E74h]
  int v18; // [esp-8h] [ebp-E70h]
  char pFileName[1024]; // [esp+8h] [ebp-E60h] BYREF
  char pStringToSearchFor[512]; // [esp+408h] [ebp-A60h] BYREF
  char pTextureName[1024]; // [esp+608h] [ebp-860h] BYREF
  char pGeneratedTexDataName[1024]; // [esp+A08h] [ebp-460h] BYREF
  texinfo_s newTexInfo; // [esp+E08h] [ebp-60h] BYREF
  dtexdata_t *pTexData; // [esp+E50h] [ebp-18h]
  PatchInfo_t info; // [esp+E54h] [ebp-14h] BYREF
  texinfo_s *pTexInfo; // [esp+E64h] [ebp-4h]

  if ( originalTexInfo == -1 )
    return -1;
  texdata = texinfo.m_Memory.m_pMemory[originalTexInfo].texdata;
  pTexInfo = &texinfo.m_Memory.m_pMemory[originalTexInfo];
  pTexData = GetTexData(index: texdata);
  String = TexDataStringTable_GetString(stringID: pTexData->nameStringTableID);
  v6 = String;
  if ( g_IsCubemapTexData[pTexInfo->texdata] != 0 )
  {
    _Warning(a1: "Multiple references for cubemap on texture %s!!!\n", String);
    return originalTexInfo;
  }
  V_snprintf(pDest: pStringToSearchFor, maxLen: 512, pFormat: "_%d_%d_%d", *origin, origin[1], origin[2]);
  if ( V_stristr(pStr: v6, pSearch: pStringToSearchFor) != nullptr )
    return originalTexInfo;
  v18 = origin[2];
  v17 = origin[1];
  v16 = *origin;
  info.m_pMapName = mapbase;
  info.m_pOrigin[0] = v16;
  info.m_pOrigin[1] = v17;
  info.m_pOrigin[2] = v18;
  if ( V_snprintf(
         pDest: pGeneratedTexDataName,
         maxLen: 1024,
         pFormat: "maps/%s/%s%s%d_%d_%d",
         mapbase,
         v6,
         "_",
         v16,
         v17,
         v18) >= 127 )
    _Error(a1: "Generated env_cubemap patch name : %s too long! (max = %d)\n", pGeneratedTexDataName, 128);
  for ( i = pGeneratedTexDataName; *i != 0; ++i )
  {
    if ( *i == 92 )
      *i = 47;
  }
  _V_strlower(start: pGeneratedTexDataName);
  v8 = FindTexData(pName: pGeneratedTexDataName);
  v9 = v8 != -1;
  if ( v8 == -1 )
  {
    V_snprintf(
      pDest: pTextureName,
      maxLen: 1024,
      pFormat: "maps/%s/%s%s%d_%d_%d",
      info.m_pMapName,
      "c",
      &defaultValue,
      info.m_pOrigin[0],
      info.m_pOrigin[1],
      info.m_pOrigin[2]);
    v10 = pTextureName;
    if ( pTextureName[0] != v9 )
    {
      do
      {
        if ( *v10 == 92 )
          *v10 = 47;
        ++v10;
      }
      while ( *v10 != 0 );
    }
    _V_strlower(start: pTextureName);
    if ( PatchEnvmapForMaterialAndDependents(pMaterialName: v6, &info, pCubemapTexture: pTextureName) == 0 )
      return originalTexInfo;
    v11 = V_snprintf(pDest: pFileName, maxLen: 1024, pFormat: "materials/%s.vtf", pTextureName) + 1;
    v12 = CUtlVector<char *,CUtlMemory<char *,int>>::AddToTail(this: &s_DefaultCubemapNames);
    s_DefaultCubemapNames.m_Memory.m_pMemory[v12] = (char *)MemAlloc_Alloc(nSize: v11);
    v13 = s_DefaultCubemapNames.m_Memory.m_pMemory[v12];
    v14 = pFileName;
    do
    {
      v15 = *v14;
      *v13++ = *v14++;
    }
    while ( v15 != 0 );
    v8 = AddCloneTexData(pExistingTexData: pTexData, cloneTexDataName: pGeneratedTexDataName);
    g_IsCubemapTexData[v8] = 1;
  }
  newTexInfo = *pTexInfo;
  newTexInfo.texdata = v8;
  if ( v9 == 0 )
    return CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int>>::InsertBefore(
             this: &texinfo,
             elem: texinfo.m_Size,
             src: &newTexInfo);
  result = FindTexInfo(searchTexInfo: &newTexInfo);
  if ( result == -1 )
    return CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int>>::InsertBefore(
             this: &texinfo,
             elem: texinfo.m_Size,
             src: &newTexInfo);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406340
// Name: void Cubemap_FixupBrushSidesMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cubemap_FixupBrushSidesMaterials()
{
  int v0; // eax
  CUtlVector<int,CUtlMemory<int,int> > *v1; // eax
  int v2; // ebx
  int nummapbrushsides; // ecx
  int v4; // edi
  int v5; // eax
  int *p_id; // edx
  int v7; // eax
  side_t *v8; // esi
  int TexInfo; // eax
  mapdispinfo_t *pMapDisp; // esi
  int v11; // [esp+0h] [ebp-10h]
  int cubemapID; // [esp+4h] [ebp-Ch]
  CUtlVector<int,CUtlMemory<int,int> > *brushSidesVector; // [esp+8h] [ebp-8h]
  int v14; // [esp+Ch] [ebp-4h]

  _Msg(a1: "fixing up env_cubemap materials on brush sides...\n");
  v0 = 0;
  cubemapID = 0;
  if ( g_nCubemapSamples > 0 )
  {
    v14 = 0;
    v11 = 0;
    do
    {
      v1 = (CUtlVector<int,CUtlMemory<int,int> > *)((char *)s_EnvCubemapToBrushSides.m_Memory.m_pMemory + v0);
      v2 = 0;
      brushSidesVector = v1;
      if ( v1->m_Size > 0 )
      {
        while ( 1 )
        {
          nummapbrushsides = g_MainMap->nummapbrushsides;
          v4 = v1->m_Memory.m_pMemory[v2];
          v5 = 0;
          if ( nummapbrushsides <= 0 )
            goto LABEL_12;
          p_id = &g_MainMap->brushsides[0].id;
          while ( *p_id != v4 )
          {
            ++v5;
            p_id += 23;
            if ( v5 >= nummapbrushsides )
              goto LABEL_12;
          }
          if ( v5 >= 0 )
          {
            v7 = v5;
            v8 = &g_MainMap->brushsides[v7];
            TexInfo = Cubemap_CreateTexInfo(
                        origin: g_CubemapSamples[v14].origin,
                        originalTexInfo: g_MainMap->brushsides[v7].texinfo);
            v8->texinfo = TexInfo;
            pMapDisp = v8->pMapDisp;
            if ( pMapDisp != nullptr )
              pMapDisp->face.texinfo = TexInfo;
          }
          else
          {
LABEL_12:
            _Warning(
              a1: "env_cubemap pointing at deleted brushside near (%d, %d, %d)\n",
              g_CubemapSamples[v14].origin[0],
              g_CubemapSamples[v14].origin[1],
              g_CubemapSamples[v14].origin[2]);
          }
          if ( ++v2 >= brushSidesVector->m_Size )
            break;
          v1 = brushSidesVector;
        }
      }
      ++v14;
      v0 = v11 + 20;
      ++cubemapID;
      v11 += 20;
    }
    while ( cubemapID < g_nCubemapSamples );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004064C0
// Name: void Cubemap_InitCubemapSideData(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cubemap_InitCubemapSideData()
{
  CMapFile *v0; // ebx
  int nummapbrushsides; // eax
  int v2; // edi
  UtlRBTreeNode_t<CubemapInfo_t,unsigned short> *v3; // eax
  int *p_m_Size; // eax
  int v5; // eax
  int v6; // eax
  texinfo_s *v7; // eax
  dtexdata_t *TexData; // eax
  dtexdata_t *v9; // esi
  unsigned __int16 v10; // ax
  const char *String; // eax
  int v12; // esi
  int v13; // ecx
  int v14; // eax
  int *p_id; // edx
  CUtlRBTree<CubemapInfo_t,unsigned short,bool (__cdecl*)(CubemapInfo_t const &,CubemapInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CubemapInfo_t,unsigned short>,unsigned short> > lookup; // [esp+Ch] [ebp-2Ch] BYREF
  int nSideCount; // [esp+28h] [ebp-10h] BYREF
  int m_Size; // [esp+2Ch] [ebp-Ch]
  int v19; // [esp+30h] [ebp-8h]
  CUtlVector<int,CUtlMemory<int,int> > *m_pMemory; // [esp+34h] [ebp-4h]

  v0 = g_MainMap;
  nummapbrushsides = g_MainMap->nummapbrushsides;
  v2 = 0;
  lookup.m_LessFunc = (bool (__cdecl *)(const CubemapInfo_t *, const CubemapInfo_t *))CDefOps<int>::LessFunc;
  lookup.m_Elements.m_pMemory = nullptr;
  lookup.m_Elements.m_nAllocationCount = nummapbrushsides;
  lookup.m_Elements.m_nGrowSize = 0;
  if ( nummapbrushsides != 0 )
  {
    v3 = (UtlRBTreeNode_t<CubemapInfo_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: 16 * nummapbrushsides);
    v0 = g_MainMap;
    lookup.m_Elements.m_pMemory = v3;
  }
  *(_DWORD *)&lookup.m_Root = 0xFFFF;
  *(_DWORD *)&lookup.m_FirstFree = -1;
  lookup.m_pElements = lookup.m_Elements.m_pMemory;
  if ( v0->nummapbrushsides > 0 )
  {
    p_m_Size = nullptr;
    m_pMemory = nullptr;
    do
    {
      v5 = (int)v0->brushsides + (_DWORD)p_m_Size;
      if ( v5 != 0 )
      {
        v6 = *(_DWORD *)(v5 + 4);
        if ( v6 != -1 )
        {
          v7 = &texinfo.m_Memory.m_pMemory[v6];
          if ( v7 != nullptr )
          {
            TexData = GetTexData(index: v7->texdata);
            v9 = TexData;
            if ( TexData != nullptr )
            {
              nSideCount = TexData->nameStringTableID;
              v10 = CUtlRBTree<CubemapInfo_t,unsigned short,bool (__cdecl *)(CubemapInfo_t const &,CubemapInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CubemapInfo_t,unsigned short>,unsigned short>>::Find(
                      this: &lookup,
                      search: (const CubemapInfo_t *)&nSideCount);
              if ( v10 == 0xFFFF )
              {
                String = TexDataStringTable_GetString(stringID: v9->nameStringTableID);
                LOBYTE(m_Size) = DoesMaterialOrDependentsUseEnvmap(pPatchedMaterialName: String);
                s_aCubemapSideData[v2].bHasEnvMapInMaterial = m_Size;
                CUtlRBTree<CubemapInfo_t,unsigned short,bool (__cdecl *)(CubemapInfo_t const &,CubemapInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CubemapInfo_t,unsigned short>,unsigned short>>::Insert(
                  this: &lookup,
                  insert: (const CubemapInfo_t *)&nSideCount);
              }
              else
              {
                s_aCubemapSideData[v2].bHasEnvMapInMaterial = lookup.m_Elements.m_pMemory[v10].m_Data.m_bSpecular;
              }
            }
            v0 = g_MainMap;
          }
        }
      }
      ++v2;
      p_m_Size = &m_pMemory[4].m_Size;
      m_pMemory = (CUtlVector<int,CUtlMemory<int,int> > *)((char *)m_pMemory + 92);
    }
    while ( v2 < v0->nummapbrushsides );
  }
  if ( g_nCubemapSamples > 0 )
  {
    m_pMemory = s_EnvCubemapToBrushSides.m_Memory.m_pMemory;
    v19 = g_nCubemapSamples;
    do
    {
      v12 = 0;
      m_Size = m_pMemory->m_Size;
      if ( m_Size > 0 )
      {
        do
        {
          v13 = v0->nummapbrushsides;
          v14 = 0;
          if ( v13 > 0 )
          {
            p_id = &v0->brushsides[0].id;
            while ( *p_id != m_pMemory->m_Memory.m_pMemory[v12] )
            {
              ++v14;
              p_id += 23;
              if ( v14 >= v13 )
                goto LABEL_24;
            }
            if ( v14 >= 0 )
              s_aCubemapSideData[v14].bManuallyPickedByAnEnvCubemap = true;
          }
LABEL_24:
          ++v12;
        }
        while ( v12 < m_Size );
      }
      ++m_pMemory;
      --v19;
    }
    while ( v19 != 0 );
  }
  CUtlRBTree<CubemapInfo_t,unsigned short,bool (__cdecl *)(CubemapInfo_t const &,CubemapInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CubemapInfo_t,unsigned short>,unsigned short>>::RemoveAll(this: &lookup);
  if ( lookup.m_Elements.m_nGrowSize >= 0 && lookup.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: lookup.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00406690
// Name: void Cubemap_AttachDefaultCubemapToSpecularSides(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cubemap_AttachDefaultCubemapToSpecularSides()
{
  bool *p_bManuallyPickedByAnEnvCubemap; // eax
  int v1; // edi
  CMapFile *v2; // eax
  int j; // ecx
  int v4; // esi
  int v5; // ebx
  int v6; // ebx
  int v7; // esi
  winding_t *ClosestCubemap; // eax
  int TexInfo; // eax
  int v10; // esi
  int nummapbrushsides; // [esp-8h] [ebp-24h]
  CUtlVector<int,CUtlMemory<int,int> > sideToEntityIndex; // [esp+0h] [ebp-1Ch] BYREF
  int entityIndex; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  p_bManuallyPickedByAnEnvCubemap = &s_aCubemapSideData[0].bManuallyPickedByAnEnvCubemap;
  do
  {
    *(_WORD *)(p_bManuallyPickedByAnEnvCubemap - 1) = 0;
    p_bManuallyPickedByAnEnvCubemap += 2;
  }
  while ( (int)p_bManuallyPickedByAnEnvCubemap < (int)((bool *)&vec2_origin_3.x + 1) );
  Cubemap_InitCubemapSideData();
  v1 = 0;
  nummapbrushsides = g_MainMap->nummapbrushsides;
  memset(&sideToEntityIndex, 0, sizeof(sideToEntityIndex));
  CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&sideToEntityIndex,
    elem: 0,
    num: nummapbrushsides);
  v2 = g_MainMap;
  for ( j = 0; j < g_MainMap->nummapbrushsides; ++j )
  {
    sideToEntityIndex.m_Memory.m_pMemory[j] = -1;
    v2 = g_MainMap;
  }
  i = 0;
  if ( v2->nummapbrushes > 0 )
  {
    v4 = 0;
    do
    {
      entityIndex = v2->mapbrushes[v4].entitynum;
      if ( v2->mapbrushes[v4].numsides > 0 )
      {
        v5 = 0;
        do
        {
          sideToEntityIndex.m_Memory.m_pMemory[((char *)v2->mapbrushes[v4].original_sides - (char *)v2 + v5 - 1970212)
                                             / 92] = entityIndex;
          v2 = g_MainMap;
          ++v1;
          v5 += 92;
        }
        while ( v1 < g_MainMap->mapbrushes[v4].numsides );
        v1 = 0;
      }
      ++v4;
      ++i;
    }
    while ( i < v2->nummapbrushes );
  }
  if ( v2->nummapbrushsides > 0 )
  {
    v6 = 0;
    do
    {
      v7 = (int)&v2->brushsides[v6];
      if ( s_aCubemapSideData[v1].bHasEnvMapInMaterial && !s_aCubemapSideData[v1].bManuallyPickedByAnEnvCubemap )
      {
        ClosestCubemap = Cubemap_FindClosestCubemap(
                           a1: (plane_t *)&savedregs,
                           entityOrigin: (const Vector *)((char *)&unk_12E1028
                                          + (_DWORD)v2
                                          + 44 * sideToEntityIndex.m_Memory.m_pMemory[v1]),
                           pSide: &v2->brushsides[v6]);
        if ( ClosestCubemap != (winding_t *)-1 )
        {
          TexInfo = Cubemap_CreateTexInfo(
                      origin: g_CubemapSamples[(_DWORD)ClosestCubemap].origin,
                      originalTexInfo: *(_DWORD *)(v7 + 4));
          *(_DWORD *)(v7 + 4) = TexInfo;
          v10 = *(_DWORD *)(v7 + 8);
          if ( v10 != 0 )
            *(_DWORD *)(v10 + 24) = TexInfo;
        }
        v2 = g_MainMap;
      }
      ++v1;
      ++v6;
    }
    while ( v1 < v2->nummapbrushsides );
  }
  if ( sideToEntityIndex.m_Memory.m_nGrowSize >= 0 && sideToEntityIndex.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sideToEntityIndex.m_Memory.m_pMemory);
}
