// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/cmodel_bsp.cpp
// Functions: 24
// ============================================================

#include "engine\cmodel_bsp.h"

//------------------------------------------------------------------------------
// Address: 0x10150B30
// Name: class CDispCollTree __near * CollisionBSPData_GetCollisionTree(int)
// Source: json
//------------------------------------------------------------------------------
CDispCollTree *__cdecl CollisionBSPData_GetCollisionTree(int i)
{
  if ( i < 0 || i >= g_DispCollTreeCount )
    return nullptr;
  else
    return &g_pDispCollTrees[i];
}

//------------------------------------------------------------------------------
// Address: 0x10150B60
// Name: void CollisionBSPData_LinkPhysics(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LinkPhysics()
{
  IPhysicsCollision *v0; // eax

  if ( physprops == nullptr )
  {
    physprops = (IPhysicsSurfaceProps *)g_AppSystemFactory(a1: "VPhysicsSurfaceProps001", a2: nullptr);
    v0 = (IPhysicsCollision *)g_AppSystemFactory(a1: "VPhysicsCollision007", a2: nullptr);
    physcollision = v0;
    if ( physprops == nullptr || v0 == nullptr )
      Sys_Error(error: "CollisionBSPData_PreLoad: Can't link physics");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10150BB0
// Name: void CollisionBSPData_PreLoad(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_PreLoad(CCollisionBSPData *pBSPData)
{
  pBSPData->numleafs = 1;
  pBSPData->map_vis = nullptr;
  pBSPData->numareas = 1;
  pBSPData->numclusters = 1;
  pBSPData->map_nullname = "**empty**";
  pBSPData->numtextures = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10150BF0
// Name: void ExtractBoxBrush(struct cboxbrush_t __near *,struct cbrush_t const __near &,struct dbrushside_t __near *,struct cplane_t __near *,struct texinfo_s __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ExtractBoxBrush(
        cplane_t *pBox,
        const cbrush_t *brush,
        dbrushside_t *pSides,
        cplane_t *pPlanes,
        texinfo_s *pTexinfo)
{
  dbrushside_t *v6; // esi
  int texinfo; // eax
  int type; // ecx
  float v9; // xmm0_4
  int firstbrushside; // ecx
  dbrushside_t *v11; // esi
  int v12; // eax
  int v13; // ecx
  float v14; // xmm0_4
  int v15; // ecx
  dbrushside_t *v16; // esi
  int v17; // eax
  int v18; // ecx
  float v19; // xmm0_4
  int v20; // ecx
  dbrushside_t *v21; // esi
  int v22; // eax
  int v23; // ecx
  float v24; // xmm0_4
  int v25; // ecx
  dbrushside_t *v26; // esi
  int v27; // eax
  int v28; // ecx
  float v29; // xmm0_4
  int v30; // ecx
  dbrushside_t *v31; // esi
  cplane_t *v32; // edi
  int v33; // eax
  int texdata; // ebx
  int v35; // ecx
  float v36; // xmm0_4
  int surfaceIndex; // [esp+Ch] [ebp-4h]
  int surfaceIndexa; // [esp+Ch] [ebp-4h]
  int surfaceIndexb; // [esp+Ch] [ebp-4h]
  int surfaceIndexc; // [esp+Ch] [ebp-4h]
  int surfaceIndexd; // [esp+Ch] [ebp-4h]
  cplane_t *plane; // [esp+18h] [ebp+8h]
  cplane_t *planea; // [esp+18h] [ebp+8h]
  cplane_t *planeb; // [esp+18h] [ebp+8h]
  cplane_t *planec; // [esp+18h] [ebp+8h]
  cplane_t *planed; // [esp+18h] [ebp+8h]

  LOWORD(pBox[2].normal.y) = 0;
  v6 = &pSides[brush->firstbrushside];
  plane = &pPlanes[v6->planenum];
  texinfo = v6->texinfo;
  if ( texinfo >= 0 )
    surfaceIndex = pTexinfo[texinfo].texdata;
  else
    LOWORD(surfaceIndex) = -1;
  type = plane->type;
  v9 = *(&plane->normal.x + type);
  if ( v9 == 1.0 )
  {
    *((float *)&pBox->type + type) = plane->dist;
    *(_WORD *)&pBox[1].pad[2 * type] = surfaceIndex;
    LOBYTE(type) = type + 3;
  }
  else if ( v9 == -1.0 )
  {
    *(&pBox->normal.x + type) = -plane->dist;
    *((_WORD *)&pBox[1].dist + type) = surfaceIndex;
  }
  LOWORD(pBox[2].normal.y) |= v6->thin << type;
  firstbrushside = brush->firstbrushside;
  v11 = &pSides[firstbrushside + 1];
  planea = &pPlanes[v11->planenum];
  v12 = pSides[firstbrushside + 1].texinfo;
  if ( v12 >= 0 )
    surfaceIndexa = pTexinfo[v12].texdata;
  else
    LOWORD(surfaceIndexa) = -1;
  v13 = planea->type;
  v14 = *(&planea->normal.x + v13);
  if ( v14 == 1.0 )
  {
    *((float *)&pBox->type + v13) = planea->dist;
    *(_WORD *)&pBox[1].pad[2 * v13] = surfaceIndexa;
    LOBYTE(v13) = v13 + 3;
  }
  else if ( v14 == -1.0 )
  {
    *(&pBox->normal.x + v13) = -planea->dist;
    *((_WORD *)&pBox[1].dist + v13) = surfaceIndexa;
  }
  LOWORD(pBox[2].normal.y) |= v11->thin << v13;
  v15 = brush->firstbrushside;
  v16 = &pSides[v15 + 2];
  planeb = &pPlanes[v16->planenum];
  v17 = pSides[v15 + 2].texinfo;
  if ( v17 >= 0 )
    surfaceIndexb = pTexinfo[v17].texdata;
  else
    LOWORD(surfaceIndexb) = -1;
  v18 = planeb->type;
  v19 = *(&planeb->normal.x + v18);
  if ( v19 == 1.0 )
  {
    *((float *)&pBox->type + v18) = planeb->dist;
    *(_WORD *)&pBox[1].pad[2 * v18] = surfaceIndexb;
    LOBYTE(v18) = v18 + 3;
  }
  else if ( v19 == -1.0 )
  {
    *(&pBox->normal.x + v18) = -planeb->dist;
    *((_WORD *)&pBox[1].dist + v18) = surfaceIndexb;
  }
  LOWORD(pBox[2].normal.y) |= v16->thin << v18;
  v20 = brush->firstbrushside;
  v21 = &pSides[v20 + 3];
  planec = &pPlanes[v21->planenum];
  v22 = pSides[v20 + 3].texinfo;
  if ( v22 >= 0 )
    surfaceIndexc = pTexinfo[v22].texdata;
  else
    LOWORD(surfaceIndexc) = -1;
  v23 = planec->type;
  v24 = *(&planec->normal.x + v23);
  if ( v24 == 1.0 )
  {
    *((float *)&pBox->type + v23) = planec->dist;
    *(_WORD *)&pBox[1].pad[2 * v23] = surfaceIndexc;
    LOBYTE(v23) = v23 + 3;
  }
  else if ( v24 == -1.0 )
  {
    *(&pBox->normal.x + v23) = -planec->dist;
    *((_WORD *)&pBox[1].dist + v23) = surfaceIndexc;
  }
  LOWORD(pBox[2].normal.y) |= v21->thin << v23;
  v25 = brush->firstbrushside;
  v26 = &pSides[v25 + 4];
  planed = &pPlanes[v26->planenum];
  v27 = pSides[v25 + 4].texinfo;
  if ( v27 >= 0 )
    surfaceIndexd = pTexinfo[v27].texdata;
  else
    LOWORD(surfaceIndexd) = -1;
  v28 = planed->type;
  v29 = *(&planed->normal.x + v28);
  if ( v29 == 1.0 )
  {
    *((float *)&pBox->type + v28) = planed->dist;
    *(_WORD *)&pBox[1].pad[2 * v28] = surfaceIndexd;
    LOBYTE(v28) = v28 + 3;
  }
  else if ( v29 == -1.0 )
  {
    *(&pBox->normal.x + v28) = -planed->dist;
    *((_WORD *)&pBox[1].dist + v28) = surfaceIndexd;
  }
  LOWORD(pBox[2].normal.y) |= v26->thin << v28;
  v30 = brush->firstbrushside;
  v31 = &pSides[v30 + 5];
  v32 = &pPlanes[v31->planenum];
  v33 = pSides[v30 + 5].texinfo;
  if ( v33 >= 0 )
    texdata = pTexinfo[v33].texdata;
  else
    LOWORD(texdata) = -1;
  v35 = v32->type;
  v36 = *(&v32->normal.x + v35);
  if ( v36 == 1.0 )
  {
    v35 += 3;
    *(&pBox->normal.y + v35) = v32->dist;
    *((_WORD *)&pBox[1].dist + v35) = texdata;
  }
  else if ( v36 == -1.0 )
  {
    *(&pBox->normal.x + v35) = -v32->dist;
    *((_WORD *)&pBox[1].dist + v35) = texdata;
  }
  LOWORD(pBox[2].normal.y) |= v31->thin << v35;
  HIWORD(pBox[2].normal.y) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10150F80
// Name: void CollisionBSPData_LoadVisibility(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadVisibility(CCollisionBSPData *pBSPData)
{
  netadrtype_t Available; // esi
  const char *LoadName; // eax
  const char *v3; // eax
  unsigned __int8 *SamplePosition; // eax
  CMapLoadHelper lh; // [esp+8h] [ebp-128h] BYREF

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 4u, bUncompress: true);
  pBSPData->numvisibility = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh);
  if ( CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) > 0x1000000 )
    Sys_Error(error: "Map has too large visibility lump");
  Available = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh);
  if ( Available != NA_NULL )
  {
    LoadName = CMapLoadHelper::GetLoadName(this: &lh);
    v3 = va(format: "%s [%s]", LoadName, "Visibility");
    pBSPData->map_vis = (dvis_t *)Hunk_AllocName(size: Available, name: v3, bClear: false);
    SamplePosition = (unsigned __int8 *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&lh);
    memcpy(dst: (unsigned __int8 *)pBSPData->map_vis, src: SamplePosition, count: Available);
  }
  else
  {
    pBSPData->map_vis = nullptr;
  }
  CMapLoadHelper::~CMapLoadHelper(this: &lh);
}

//------------------------------------------------------------------------------
// Address: 0x10151060
// Name: void CollisionBSPData_LoadTextures(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadTextures(CCollisionBSPData *pBSPData)
{
  unsigned __int8 *SamplePosition; // ebx
  signed int v2; // edi
  CCollisionBSPData *v3; // esi
  const char *LoadName; // eax
  const char *v5; // eax
  const char *v6; // eax
  netadrtype_t Available; // eax
  netadrtype_t v8; // eax
  csurface_t *m_pArray; // eax
  int v10; // edi
  IMaterial *v11; // ebx
  int v12; // eax
  const char *v13; // eax
  csurface_t *v14; // ebx
  const char *v15; // [esp-8h] [ebp-39Ch]
  CMapLoadHelper lhStringTable; // [esp+Ch] [ebp-388h] BYREF
  CMapLoadHelper lhStringData; // [esp+134h] [ebp-260h] BYREF
  CMapLoadHelper lh; // [esp+25Ch] [ebp-138h] BYREF
  int *pStringTable; // [esp+384h] [ebp-10h]
  int count; // [esp+388h] [ebp-Ch]
  int i; // [esp+38Ch] [ebp-8h]
  dtexdata_t *in; // [esp+390h] [ebp-4h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 2u, bUncompress: true);
  CMapLoadHelper::CMapLoadHelper(this: &lhStringData, lumpToLoad: 0x2Bu, bUncompress: true);
  SamplePosition = (unsigned __int8 *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&lhStringData);
  CMapLoadHelper::CMapLoadHelper(this: &lhStringTable, lumpToLoad: 0x2Cu, bUncompress: true);
  if ( (CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lhStringTable) & 3) != 0 )
    Sys_Error(error: "CMod_LoadTextures: funny lump size");
  pStringTable = (int *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&lhStringTable);
  in = (dtexdata_t *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&lh);
  if ( (CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) & 0x1F) != 0 )
    Sys_Error(error: "CMod_LoadTextures: funny lump size");
  v2 = (unsigned int)CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) >> 5;
  count = v2;
  if ( v2 == 0 )
    Sys_Error(error: "Map with no textures");
  if ( v2 > 2048 )
    Sys_Error(error: "Map has too many textures");
  v3 = pBSPData;
  LoadName = CMapLoadHelper::GetLoadName(this: &lh);
  v5 = va(format: "%s [%s]", LoadName, "Textures");
  v3->map_surfaces.m_pArray = (csurface_t *)Hunk_AllocName(size: 8 * v2, name: v5, bClear: true);
  v3->numtextures = v2;
  v6 = CMapLoadHelper::GetLoadName(this: &lh);
  v15 = va(format: "%s [%s]", v6, "Textures");
  Available = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lhStringData);
  v3->map_texturenames = (char *)Hunk_AllocName(size: Available, name: v15, bClear: false);
  v8 = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lhStringData);
  memcpy(dst: (unsigned __int8 *)v3->map_texturenames, src: SamplePosition, count: v8);
  i = 0;
  if ( v2 > 0 )
  {
    in = (dtexdata_t *)((char *)in + 12);
    do
    {
      m_pArray = v3->map_surfaces.m_pArray;
      v10 = i;
      m_pArray[v10].name = &v3->map_texturenames[pStringTable[LODWORD(in->reflectivity.x)]];
      *(_DWORD *)&m_pArray[v10].surfaceProps = 0;
      v11 = materials->FindMaterial(
              this: materials,
              a2: v3->map_surfaces.m_pArray[v10].name,
              a3: "World textures",
              a4: 1,
              a5: 0);
      if ( v11 != nullptr && !v11->IsErrorMaterial(this: v11) )
      {
        v12 = (int)v11->FindVar(this: v11, a2: "$surfaceprop", a3: (bool *)&pBSPData + 3, a4: false);
        if ( HIBYTE(pBSPData) != 0 )
        {
          v13 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v12 + 28))(a1: v12);
          v14 = v3->map_surfaces.m_pArray;
          v14[v10].surfaceProps = physprops->GetSurfaceIndex(this: physprops, a2: v13);
        }
      }
      ++in;
      ++i;
    }
    while ( i < count );
  }
  CMapLoadHelper::~CMapLoadHelper(this: &lhStringTable);
  CMapLoadHelper::~CMapLoadHelper(this: &lhStringData);
  CMapLoadHelper::~CMapLoadHelper(this: &lh);
}

//------------------------------------------------------------------------------
// Address: 0x101512C0
// Name: void CollisionBSPData_LoadTexinfo(class CCollisionBSPData __near *,struct texinfo_s __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadTexinfo(CCollisionBSPData *pBSPData, texinfo_s *pTexinfo, int texinfoCount)
{
  int v3; // esi
  int *p_flags; // ecx
  int v5; // eax
  unsigned __int16 *v6; // eax

  v3 = texinfoCount;
  if ( texinfoCount > 0 )
  {
    p_flags = &pTexinfo->flags;
    do
    {
      v5 = *((unsigned __int16 *)p_flags + 2);
      if ( v5 >= pBSPData->numtextures )
        LOWORD(v5) = 0;
      v6 = &pBSPData->map_surfaces.m_pArray[(unsigned __int16)v5].flags;
      *v6 |= *(_WORD *)p_flags;
      p_flags += 18;
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10151310
// Name: void CollisionBSPData_LoadLeafs_Version_0(class CCollisionBSPData __near *,class CMapLoadHelper __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadLeafs_Version_0(CCollisionBSPData *pBSPData, CMapLoadHelper *lh)
{
  signed __int32 v2; // edi
  const char *LoadName; // eax
  const char *v5; // eax
  cleaf_t *v6; // eax
  int v7; // edx
  int v8; // eax
  $7CA033D54BBC683D0ECF5D922201D02D *v9; // ecx
  cleaf_t *v10; // eax
  int cluster; // eax
  bool v12; // zf
  int numleafs; // eax
  cleaf_t *v14; // eax
  dleaf_version_0_t *in; // [esp+Ch] [ebp-4h]
  dleaf_version_0_t *ina; // [esp+Ch] [ebp-4h]
  int allcontents; // [esp+18h] [ebp+8h]

  in = (dleaf_version_0_t *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)lh);
  if ( CCircularBuffer::GetReadAvailable(this: (netadr_s *)lh) % 0x38u != 0 )
    Sys_Error(error: "CollisionBSPData_LoadLeafs: funny lump size");
  v2 = CCircularBuffer::GetReadAvailable(this: (netadr_s *)lh) / 0x38u;
  if ( v2 == 0 )
    Sys_Error(error: "Map with no leafs");
  if ( v2 > 0x10000 )
    Sys_Error(error: "Map has too many planes");
  LoadName = CMapLoadHelper::GetLoadName(this: lh);
  v5 = va(format: "%s [%s]", LoadName, "Leafs");
  v6 = (cleaf_t *)Hunk_AllocName(size: 16 * (v2 + 1), name: v5, bClear: true);
  v7 = 0;
  pBSPData->map_leafs.m_pArray = v6;
  v8 = 0;
  pBSPData->numleafs = v2;
  pBSPData->numclusters = 0;
  allcontents = 0;
  if ( v2 > 0 )
  {
    v9 = ($7CA033D54BBC683D0ECF5D922201D02D *)&in->___u2;
    ina = (dleaf_version_0_t *)v2;
    do
    {
      v10 = &pBSPData->map_leafs.m_pArray[v7];
      v10->contents = *(_DWORD *)&v9[-3];
      v10->cluster = (__int16)v9[-1];
      *((_WORD *)v10 + 3) ^= (*((_WORD *)v10 + 3) ^ *(_WORD *)v9) & 0x1FF;
      *((_WORD *)v10 + 3) = *(_WORD *)v9 ^ (*((_WORD *)v10 + 3) ^ *(_WORD *)v9) & 0x1FF;
      v10->firstleafbrush = (unsigned __int16)v9[9];
      v10->numleafbrushes = (unsigned __int16)v9[10];
      v10->dispCount = 0;
      cluster = v10->cluster;
      if ( cluster >= pBSPData->numclusters )
        pBSPData->numclusters = cluster + 1;
      v8 = *(_DWORD *)&v9[-3] | allcontents;
      ++v7;
      v9 += 28;
      v12 = ina == (dleaf_version_0_t *)1;
      ina = (dleaf_version_0_t *)((char *)ina - 1);
      allcontents = v8;
    }
    while ( !v12 );
  }
  pBSPData->allcontents = v8;
  if ( pBSPData->map_leafs.m_pArray->contents != 1 )
    Sys_Error(error: "Map leaf 0 is not CONTENTS_SOLID");
  numleafs = pBSPData->numleafs;
  pBSPData->emptyleaf = numleafs;
  v14 = &pBSPData->map_leafs.m_pArray[numleafs];
  pBSPData->solidleaf = 0;
  v14->contents = 0;
  *(_DWORD *)&v14->cluster = 0;
  *(_DWORD *)&v14->firstleafbrush = 0;
  *(_DWORD *)&v14->dispListStart = 0;
  ++pBSPData->numleafs;
}

//------------------------------------------------------------------------------
// Address: 0x101514C0
// Name: void CollisionBSPData_LoadLeafs_Version_1(class CCollisionBSPData __near *,class CMapLoadHelper __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadLeafs_Version_1(CCollisionBSPData *pBSPData, CMapLoadHelper *lh)
{
  signed int v2; // edi
  const char *LoadName; // eax
  const char *v5; // eax
  cleaf_t *v6; // eax
  int v7; // edx
  int v8; // eax
  $7CA033D54BBC683D0ECF5D922201D02D *v9; // ecx
  cleaf_t *v10; // eax
  int cluster; // eax
  bool v12; // zf
  cleaf_t *m_pArray; // ecx
  int numleafs; // eax
  cleaf_t *v15; // eax
  dleaf_t *in; // [esp+Ch] [ebp-4h]
  dleaf_t *ina; // [esp+Ch] [ebp-4h]
  int allcontents; // [esp+18h] [ebp+8h]

  in = (dleaf_t *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)lh);
  if ( (CCircularBuffer::GetReadAvailable(this: (netadr_s *)lh) & 0x1F) != 0 )
    Sys_Error(error: "CollisionBSPData_LoadLeafs: funny lump size");
  v2 = (unsigned int)CCircularBuffer::GetReadAvailable(this: (netadr_s *)lh) >> 5;
  if ( v2 == 0 )
    Sys_Error(error: "Map with no leafs");
  if ( v2 > 0x10000 )
    Sys_Error(error: "Map has too many planes");
  LoadName = CMapLoadHelper::GetLoadName(this: lh);
  v5 = va(format: "%s [%s]", LoadName, "Leafs");
  v6 = (cleaf_t *)Hunk_AllocName(size: 16 * (v2 + 1), name: v5, bClear: true);
  v7 = 0;
  pBSPData->map_leafs.m_pArray = v6;
  v8 = 0;
  pBSPData->numleafs = v2;
  pBSPData->numclusters = 0;
  allcontents = 0;
  if ( v2 > 0 )
  {
    v9 = ($7CA033D54BBC683D0ECF5D922201D02D *)&in->___u2;
    ina = (dleaf_t *)v2;
    do
    {
      v10 = &pBSPData->map_leafs.m_pArray[v7];
      v10->contents = *(_DWORD *)&v9[-3];
      v10->cluster = (__int16)v9[-1];
      *((_WORD *)v10 + 3) ^= (*((_WORD *)v10 + 3) ^ *(_WORD *)v9) & 0x1FF;
      *((_WORD *)v10 + 3) = *(_WORD *)v9 ^ (*((_WORD *)v10 + 3) ^ *(_WORD *)v9) & 0x1FF;
      v10->firstleafbrush = (unsigned __int16)v9[9];
      v10->numleafbrushes = (unsigned __int16)v9[10];
      v10->dispCount = 0;
      cluster = v10->cluster;
      if ( cluster >= pBSPData->numclusters )
        pBSPData->numclusters = cluster + 1;
      v8 = *(_DWORD *)&v9[-3] | allcontents;
      ++v7;
      v9 += 16;
      v12 = ina == (dleaf_t *)1;
      ina = (dleaf_t *)((char *)ina - 1);
      allcontents = v8;
    }
    while ( !v12 );
  }
  m_pArray = pBSPData->map_leafs.m_pArray;
  pBSPData->allcontents = v8;
  if ( m_pArray->contents != 1 )
    Sys_Error(error: "Map leaf 0 is not CONTENTS_SOLID");
  numleafs = pBSPData->numleafs;
  pBSPData->emptyleaf = numleafs;
  v15 = &pBSPData->map_leafs.m_pArray[numleafs];
  pBSPData->solidleaf = 0;
  v15->contents = 0;
  *(_DWORD *)&v15->cluster = 0;
  *(_DWORD *)&v15->firstleafbrush = 0;
  *(_DWORD *)&v15->dispListStart = 0;
  ++pBSPData->numleafs;
}

//------------------------------------------------------------------------------
// Address: 0x10151660
// Name: void CollisionBSPData_LoadLeafs(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadLeafs(CCollisionBSPData *pBSPData)
{
  INetChannel *State; // eax
  CMapLoadHelper lh; // [esp+4h] [ebp-128h] BYREF

  pBSPData->allcontents = -1;
  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0xAu, bUncompress: true);
  State = CEngine::GetState(this: (CNetMessage *)&lh);
  if ( State != nullptr )
  {
    if ( State == (INetChannel *)1 )
      CollisionBSPData_LoadLeafs_Version_1(pBSPData, &lh);
    else
      _Error(a1: "Unknown LUMP_LEAFS version\n");
    CMapLoadHelper::~CMapLoadHelper(this: &lh);
  }
  else
  {
    CollisionBSPData_LoadLeafs_Version_0(pBSPData, &lh);
    CMapLoadHelper::~CMapLoadHelper(this: &lh);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10151700
// Name: void CollisionBSPData_LoadLeafBrushes(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadLeafBrushes(CCollisionBSPData *pBSPData)
{
  unsigned __int16 *SamplePosition; // edi
  signed int v2; // esi
  const char *LoadName; // eax
  const char *v4; // eax
  signed int v5; // eax
  CMapLoadHelper lh; // [esp+Ch] [ebp-128h] BYREF

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x11u, bUncompress: true);
  SamplePosition = (unsigned __int16 *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&lh);
  if ( (CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) & 1) != 0 )
    Sys_Error(error: "CMod_LoadLeafBrushes: funny lump size");
  v2 = (unsigned int)CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) >> 1;
  if ( v2 == 0 )
    Sys_Error(error: "Map with no planes");
  if ( v2 > 0x10000 )
    Sys_Error(error: "Map has too many leafbrushes");
  LoadName = CMapLoadHelper::GetLoadName(this: &lh);
  v4 = va(format: "%s [%s]", LoadName, "LeafBrushes");
  pBSPData->map_leafbrushes.m_pArray = (unsigned __int16 *)Hunk_AllocName(size: 2 * v2, name: v4, bClear: false);
  v5 = 0;
  for ( pBSPData->numleafbrushes = v2; v5 < v2; ++SamplePosition )
    pBSPData->map_leafbrushes.m_pArray[v5++] = *SamplePosition;
  CMapLoadHelper::~CMapLoadHelper(this: &lh);
}

//------------------------------------------------------------------------------
// Address: 0x101517F0
// Name: void CollisionBSPData_LoadPlanes(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadPlanes(CCollisionBSPData *pBSPData)
{
  int SamplePosition; // esi
  int v2; // edi
  CCollisionBSPData *v3; // ebx
  const char *LoadName; // eax
  const char *v5; // eax
  int v6; // eax
  cplane_t *v7; // eax
  float v8; // xmm1_4
  unsigned __int8 v9; // cl
  float v10; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  cplane_t *v13; // eax
  unsigned __int8 v14; // cl
  float v15; // xmm1_4
  float v16; // xmm1_4
  unsigned int v17; // edi
  float v18; // xmm1_4
  unsigned int v19; // edi
  float *v20; // eax
  char v21; // cl
  float v22; // xmm1_4
  float v23; // xmm1_4
  float v24; // xmm1_4
  float *v25; // eax
  char v26; // cl
  float v27; // xmm1_4
  float v28; // xmm1_4
  double v29; // st7
  char v30; // dl
  bool v31; // zf
  float *v32; // ecx
  int v33; // esi
  int v34; // edi
  float v35; // xmm1_4
  cplane_t *v36; // eax
  unsigned __int8 v37; // dl
  float v38; // xmm1_4
  float v39; // xmm1_4
  double v40; // st7
  CMapLoadHelper lh; // [esp+Ch] [ebp-138h] BYREF
  int i; // [esp+134h] [ebp-10h]
  int count; // [esp+138h] [ebp-Ch]
  unsigned int v44; // [esp+13Ch] [ebp-8h]
  unsigned int v45; // [esp+140h] [ebp-4h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 1u, bUncompress: true);
  SamplePosition = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&lh);
  if ( CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) % 0x14u != 0 )
    Sys_Error(error: "CollisionBSPData_LoadPlanes: funny lump size");
  v2 = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) / 0x14u;
  count = v2;
  if ( v2 == 0 )
    Sys_Error(error: "Map with no planes");
  if ( v2 > 0x10000 )
    Sys_Error(error: "Map has too many planes");
  v3 = pBSPData;
  LoadName = CMapLoadHelper::GetLoadName(this: &lh);
  v5 = va(format: "%s [%s]", LoadName, "Planes");
  pBSPData->map_planes.m_pArray = (cplane_t *)Hunk_AllocName(size: 20 * v2, name: v5, bClear: true);
  v6 = 0;
  pBSPData->numplanes = v2;
  if ( v2 >= 4 )
  {
    v45 = 0;
    v44 = ((unsigned int)(v2 - 4) >> 2) + 1;
    i = 4 * v44;
    do
    {
      v7 = &pBSPData->map_planes.m_pArray[v45 / 0x14];
      v8 = *(float *)SamplePosition;
      v7->normal.x = *(float *)SamplePosition;
      v9 = v8 < 0.0;
      v10 = *(float *)(SamplePosition + 4);
      v7->normal.y = v10;
      if ( v10 < 0.0 )
        v9 |= 2u;
      v11 = *(float *)(SamplePosition + 8);
      v7->normal.z = v11;
      if ( v11 < 0.0 )
        v9 |= 4u;
      v7->dist = *(float *)(SamplePosition + 12);
      v7->type = *(_BYTE *)(SamplePosition + 16);
      v7->signbits = v9;
      v12 = *(float *)(SamplePosition + 20);
      v13 = &pBSPData->map_planes.m_pArray[v45 / 0x14 + 1];
      v13->normal.x = v12;
      v14 = v12 < 0.0;
      v15 = *(float *)(SamplePosition + 24);
      v13->normal.y = v15;
      if ( v15 < 0.0 )
        v14 |= 2u;
      v16 = *(float *)(SamplePosition + 28);
      v13->normal.z = v16;
      if ( v16 < 0.0 )
        v14 |= 4u;
      v17 = v45;
      v13->dist = *(float *)(SamplePosition + 32);
      v13->type = *(_BYTE *)(SamplePosition + 36);
      v13->signbits = v14;
      v18 = *(float *)(SamplePosition + 40);
      v19 = v17 + 60;
      v20 = (float *)((char *)&pBSPData->map_planes.m_pArray[-1].normal.x + v19);
      *v20 = v18;
      v21 = v18 < 0.0;
      v22 = *(float *)(SamplePosition + 44);
      v20[1] = v22;
      if ( v22 < 0.0 )
        v21 |= 2u;
      v23 = *(float *)(SamplePosition + 48);
      v20[2] = v23;
      if ( v23 < 0.0 )
        v21 |= 4u;
      v20[3] = *(float *)(SamplePosition + 52);
      *((_BYTE *)v20 + 16) = *(_BYTE *)(SamplePosition + 56);
      *((_BYTE *)v20 + 17) = v21;
      v24 = *(float *)(SamplePosition + 60);
      v25 = (float *)((char *)&pBSPData->map_planes.m_pArray->normal.x + v19);
      *v25 = v24;
      v26 = v24 < 0.0;
      v27 = *(float *)(SamplePosition + 64);
      v25[1] = v27;
      if ( v27 < 0.0 )
        v26 |= 2u;
      v28 = *(float *)(SamplePosition + 68);
      v25[2] = v28;
      if ( v28 < 0.0 )
        v26 |= 4u;
      v29 = *(float *)(SamplePosition + 72);
      v45 += 80;
      v25[3] = v29;
      v30 = *(_BYTE *)(SamplePosition + 76);
      SamplePosition += 80;
      v31 = v44-- == 1;
      *((_BYTE *)v25 + 16) = v30;
      *((_BYTE *)v25 + 17) = v26;
    }
    while ( !v31 );
    v2 = count;
    v6 = i;
  }
  if ( v6 < v2 )
  {
    v32 = (float *)(SamplePosition + 8);
    v33 = v6;
    v34 = v2 - v6;
    while ( 1 )
    {
      v35 = *(v32 - 2);
      v36 = &v3->map_planes.m_pArray[v33];
      v36->normal.x = v35;
      v37 = v35 < 0.0;
      v38 = *(v32 - 1);
      v36->normal.y = v38;
      if ( v38 < 0.0 )
        v37 |= 2u;
      v39 = *v32;
      v36->normal.z = *v32;
      if ( v39 < 0.0 )
        v37 |= 4u;
      v40 = v32[1];
      v32 += 5;
      v36->dist = v40;
      ++v33;
      --v34;
      v36->type = *((_BYTE *)v32 - 12);
      v36->signbits = v37;
      if ( v34 == 0 )
        break;
      v3 = pBSPData;
    }
  }
  CMapLoadHelper::~CMapLoadHelper(this: &lh);
}

//------------------------------------------------------------------------------
// Address: 0x10151AC0
// Name: void CollisionBSPData_LoadBrushes(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadBrushes(CCollisionBSPData *pBSPData)
{
  int SamplePosition; // ebx
  signed __int32 v2; // esi
  const char *LoadName; // eax
  const char *v4; // eax
  cbrush_t *v5; // eax
  signed __int32 v6; // edx
  _DWORD *v7; // eax
  cbrush_t *v8; // ecx
  int v9; // ebx
  CMapLoadHelper lh; // [esp+Ch] [ebp-128h] BYREF

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x12u, bUncompress: true);
  SamplePosition = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&lh);
  if ( CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) % 0xCu != 0 )
    Sys_Error(error: "CMod_LoadBrushes: funny lump size");
  v2 = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) / 0xCu;
  if ( (unsigned int)v2 > 0x2000 )
    Sys_Error(error: "Map has too many brushes");
  LoadName = CMapLoadHelper::GetLoadName(this: &lh);
  v4 = va(format: "%s [%s]", LoadName, "Brushes");
  v5 = (cbrush_t *)Hunk_AllocName(size: 8 * v2, name: v4, bClear: true);
  v6 = 0;
  pBSPData->map_brushes.m_pArray = v5;
  pBSPData->numbrushes = v2;
  if ( v2 > 0 )
  {
    v7 = (_DWORD *)(SamplePosition + 8);
    do
    {
      v8 = &pBSPData->map_brushes.m_pArray[v6];
      v8->firstbrushside = *((_WORD *)v7 - 4);
      v8->numsides = *((_WORD *)v7 - 2);
      v9 = *v7;
      ++v6;
      v7 += 3;
      v8->contents = v9;
    }
    while ( v6 < v2 );
  }
  CMapLoadHelper::~CMapLoadHelper(this: &lh);
}

//------------------------------------------------------------------------------
// Address: 0x10151BD0
// Name: void CollisionBSPData_LoadBrushSides(class CCollisionBSPData __near *,struct texinfo_s __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadBrushSides(CCollisionBSPData *pBSPData, texinfo_s *pTexinfo, int texinfoCount)
{
  int v4; // eax
  int v5; // esi
  int v6; // edi
  cbrush_t *v7; // edx
  int v8; // eax
  dbrushside_t *v9; // ecx
  const char *LoadName; // eax
  const char *v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  cboxbrush_t *v14; // eax
  int v15; // esi
  cbrush_t *m_pArray; // edx
  unsigned __int16 numsides; // ax
  cbrush_t *v18; // edi
  int v19; // eax
  int firstbrushside; // ecx
  unsigned __int8 *p_bevel; // esi
  cbrushside_t *v22; // edi
  int v23; // eax
  int v24; // eax
  int texdata; // eax
  unsigned __int8 v26; // dl
  cbrush_t *v27; // ecx
  int v28; // eax
  int v29; // edx
  CMapLoadHelper lh; // [esp+0h] [ebp-140h] BYREF
  cbrush_t *pBrush; // [esp+128h] [ebp-18h]
  int j; // [esp+12Ch] [ebp-14h]
  dbrushside_t *in; // [esp+130h] [ebp-10h]
  int i; // [esp+134h] [ebp-Ch]
  int outBoxBrush; // [esp+138h] [ebp-8h]
  int brushSideCount; // [esp+13Ch] [ebp-4h]
  int outBrushSide; // [esp+148h] [ebp+8h]
  int outBrushSidea; // [esp+148h] [ebp+8h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x13u, bUncompress: true);
  in = (dbrushside_t *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&lh);
  if ( (CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) & 7) != 0 )
    Sys_Error(error: "CMod_LoadBrushSides: funny lump size");
  if ( (unsigned int)CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) >> 3 > 0x10000 )
    Sys_Error(error: "Map has too many planes");
  v4 = 0;
  v5 = 0;
  v6 = 0;
  outBoxBrush = 0;
  brushSideCount = 0;
  i = 0;
  if ( pBSPData->numbrushes > 0 )
  {
    do
    {
      v7 = &pBSPData->map_brushes.m_pArray[v4];
      outBrushSide = 0;
      if ( v7->numsides == 6 )
      {
        v8 = 0;
        v9 = &in[v7->firstbrushside];
        do
        {
          if ( pBSPData->map_planes.m_pArray[v9->planenum].type > 2u )
            break;
          ++outBrushSide;
          ++v8;
          ++v9;
        }
        while ( v8 < 6 );
      }
      if ( outBrushSide == v7->numsides )
      {
        ++outBoxBrush;
        v7->numsides = -1;
      }
      else
      {
        brushSideCount += v7->numsides;
      }
      v4 = i + 1;
      i = v4;
    }
    while ( v4 < pBSPData->numbrushes );
    v5 = outBoxBrush;
    v6 = brushSideCount;
  }
  LoadName = CMapLoadHelper::GetLoadName(this: &lh);
  v11 = va(format: "%s [%s]", LoadName, "BrushSides");
  pBSPData->map_brushsides.m_pArray = (cbrushside_t *)Hunk_AllocName(size: 8 * v6, name: v11, bClear: false);
  v12 = CMapLoadHelper::GetLoadName(this: &lh);
  v13 = va(format: "%s [%s]", v12, "BrushSides");
  v14 = (cboxbrush_t *)Hunk_AllocName(size: 48 * v5, name: v13, bClear: false);
  pBSPData->numboxbrushes = v5;
  v15 = 0;
  pBSPData->map_boxbrushes.m_pArray = v14;
  pBSPData->numbrushsides = v6;
  outBoxBrush = 0;
  outBrushSidea = 0;
  i = 0;
  if ( pBSPData->numbrushes > 0 )
  {
    brushSideCount = 0;
    do
    {
      m_pArray = pBSPData->map_brushes.m_pArray;
      numsides = m_pArray[v15].numsides;
      v18 = &m_pArray[v15];
      pBrush = v18;
      if ( numsides == 0xFFFF )
      {
        ExtractBoxBrush(
          pBox: (cplane_t *)((char *)pBSPData->map_boxbrushes.m_pArray + brushSideCount),
          brush: v18,
          pSides: in,
          pPlanes: pBSPData->map_planes.m_pArray,
          pTexinfo);
        v19 = outBoxBrush;
        v18->firstbrushside = outBoxBrush;
        brushSideCount += 48;
        v18->numsides = -1;
        outBoxBrush = v19 + 1;
      }
      else
      {
        firstbrushside = v18->firstbrushside;
        v18->firstbrushside = outBrushSidea;
        j = 0;
        if ( numsides != 0 )
        {
          p_bevel = &in[firstbrushside].bevel;
          do
          {
            v22 = &pBSPData->map_brushsides.m_pArray[outBrushSidea];
            v23 = *((__int16 *)p_bevel - 2);
            v22->plane = &pBSPData->map_planes.m_pArray[*((unsigned __int16 *)p_bevel - 3)];
            if ( v23 >= texinfoCount )
              Sys_Error(error: "Bad brushside texinfo");
            v24 = *((__int16 *)p_bevel - 2);
            if ( v24 >= 0 )
              texdata = pTexinfo[v24].texdata;
            else
              LOWORD(texdata) = -1;
            v26 = *p_bevel;
            v27 = pBrush;
            ++outBrushSidea;
            v22->surfaceIndex = texdata;
            v22->bThin = p_bevel[1];
            v28 = j;
            v22->bBevel = v26;
            v29 = v27->numsides;
            p_bevel += 8;
            j = v28 + 1;
          }
          while ( v28 + 1 < v29 );
          v15 = i;
        }
      }
      i = ++v15;
    }
    while ( v15 < pBSPData->numbrushes );
  }
  CMapLoadHelper::~CMapLoadHelper(this: &lh);
}

//------------------------------------------------------------------------------
// Address: 0x10151E80
// Name: void CollisionBSPData_LoadSubmodels(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadSubmodels(CCollisionBSPData *pBSPData)
{
  int SamplePosition; // esi
  int v2; // ebx
  const char *LoadName; // eax
  const char *v5; // eax
  int v6; // eax
  int v7; // ecx
  cmodel_t *m_pArray; // eax
  cmodel_t *v9; // eax
  cmodel_t *v10; // eax
  int v11; // eax
  cmodel_t *v12; // eax
  int v13; // eax
  double v14; // st7
  cmodel_t *v15; // eax
  bool v16; // zf
  int v17; // edx
  int v18; // ecx
  int v19; // ebx
  cmodel_t *v20; // eax
  int v21; // esi
  CMapLoadHelper lh; // [esp+Ch] [ebp-130h] BYREF
  int i; // [esp+134h] [ebp-8h]
  int count; // [esp+138h] [ebp-4h]
  CCollisionBSPData *pBSPDataa; // [esp+144h] [ebp+8h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0xEu, bUncompress: true);
  SamplePosition = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&lh);
  if ( CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) % 0x30u != 0 )
    Sys_Error(error: "CMod_LoadSubmodels: funny lump size");
  v2 = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) / 0x30u;
  count = v2;
  if ( v2 == 0 )
    Sys_Error(error: "Map with no models");
  if ( v2 > 1024 )
    Sys_Error(error: "Map has too many models");
  LoadName = CMapLoadHelper::GetLoadName(this: &lh);
  v5 = va(format: "%s [%s]", LoadName, "Submodels");
  pBSPData->map_cmodels.m_pArray = (cmodel_t *)Hunk_AllocName(size: 56 * v2, name: v5, bClear: true);
  v6 = 0;
  pBSPData->numcmodels = v2;
  if ( v2 >= 4 )
  {
    v7 = 0;
    pBSPDataa = (CCollisionBSPData *)(((unsigned int)(v2 - 4) >> 2) + 1);
    i = 4 * (_DWORD)pBSPDataa;
    do
    {
      m_pArray = pBSPData->map_cmodels.m_pArray;
      m_pArray[v7].mins.x = *(float *)SamplePosition - 1.0;
      m_pArray[v7].maxs.x = *(float *)(SamplePosition + 12) + 1.0;
      m_pArray[v7].origin.x = *(float *)(SamplePosition + 24);
      m_pArray[v7].mins.y = *(float *)(SamplePosition + 4) - 1.0;
      m_pArray[v7].maxs.y = *(float *)(SamplePosition + 16) + 1.0;
      m_pArray[v7].origin.y = *(float *)(SamplePosition + 28);
      v9 = &m_pArray[v7];
      v9->mins.z = *(float *)(SamplePosition + 8) - 1.0;
      v9->maxs.z = *(float *)(SamplePosition + 20) + 1.0;
      v9->origin.z = *(float *)(SamplePosition + 32);
      v9->headnode = *(_DWORD *)(SamplePosition + 36);
      v10 = pBSPData->map_cmodels.m_pArray;
      v10[v7 + 1].mins.x = *(float *)(SamplePosition + 48) - 1.0;
      v10[v7 + 1].maxs.x = *(float *)(SamplePosition + 60) + 1.0;
      v10[v7 + 1].origin.x = *(float *)(SamplePosition + 72);
      v11 = (int)&v10[v7 + 1];
      *(float *)(v11 + 4) = *(float *)(SamplePosition + 52) - 1.0;
      *(float *)(v11 + 16) = *(float *)(SamplePosition + 64) + 1.0;
      *(float *)(v11 + 28) = *(float *)(SamplePosition + 76);
      *(float *)(v11 + 8) = *(float *)(SamplePosition + 56) - 1.0;
      *(float *)(v11 + 20) = *(float *)(SamplePosition + 68) + 1.0;
      *(float *)(v11 + 32) = *(float *)(SamplePosition + 80);
      *(_DWORD *)(v11 + 36) = *(_DWORD *)(SamplePosition + 84);
      v12 = pBSPData->map_cmodels.m_pArray;
      v12[v7 + 2].mins.x = *(float *)(SamplePosition + 96) - 1.0;
      v13 = (int)&v12[v7 + 2];
      *(float *)(v13 + 12) = *(float *)(SamplePosition + 108) + 1.0;
      *(float *)(v13 + 24) = *(float *)(SamplePosition + 120);
      *(float *)(v13 + 4) = *(float *)(SamplePosition + 100) - 1.0;
      *(float *)(v13 + 16) = *(float *)(SamplePosition + 112) + 1.0;
      *(float *)(v13 + 28) = *(float *)(SamplePosition + 124);
      *(float *)(v13 + 8) = *(float *)(SamplePosition + 104) - 1.0;
      *(float *)(v13 + 20) = *(float *)(SamplePosition + 116) + 1.0;
      v14 = *(float *)(SamplePosition + 128);
      SamplePosition += 192;
      *(float *)(v13 + 32) = v14;
      *(_DWORD *)(v13 + 36) = *(_DWORD *)(SamplePosition - 60);
      v15 = &pBSPData->map_cmodels.m_pArray[v7 + 3];
      v15->mins.x = *(float *)(SamplePosition - 48) - 1.0;
      v15->maxs.x = *(float *)(SamplePosition - 36) + 1.0;
      v15->origin.x = *(float *)(SamplePosition - 24);
      v15->mins.y = *(float *)(SamplePosition - 44) - 1.0;
      v15->maxs.y = *(float *)(SamplePosition - 32) + 1.0;
      v15->origin.y = *(float *)(SamplePosition - 20);
      v15->mins.z = *(float *)(SamplePosition - 40) - 1.0;
      v15->maxs.z = *(float *)(SamplePosition - 28) + 1.0;
      v15->origin.z = *(float *)(SamplePosition - 16);
      v7 += 4;
      v16 = pBSPDataa == (CCollisionBSPData *)1;
      pBSPDataa = (CCollisionBSPData *)((char *)pBSPDataa - 1);
      v15->headnode = *(_DWORD *)(SamplePosition - 12);
    }
    while ( !v16 );
    v6 = i;
    v2 = count;
  }
  if ( v6 < v2 )
  {
    v17 = v6;
    v18 = SamplePosition + 24;
    v19 = v2 - v6;
    do
    {
      v20 = &pBSPData->map_cmodels.m_pArray[v17];
      v20->mins.x = *(float *)(v18 - 24) - 1.0;
      v20->maxs.x = *(float *)(v18 - 12) + 1.0;
      v20->origin.x = *(float *)v18;
      v20->mins.y = *(float *)(v18 - 20) - 1.0;
      v20->maxs.y = *(float *)(v18 - 8) + 1.0;
      v20->origin.y = *(float *)(v18 + 4);
      v20->mins.z = *(float *)(v18 - 16) - 1.0;
      v20->maxs.z = *(float *)(v18 - 4) + 1.0;
      v20->origin.z = *(float *)(v18 + 8);
      v21 = *(_DWORD *)(v18 + 12);
      v18 += 48;
      ++v17;
      --v19;
      v20->headnode = v21;
    }
    while ( v19 != 0 );
  }
  CMapLoadHelper::~CMapLoadHelper(this: &lh);
}

//------------------------------------------------------------------------------
// Address: 0x10152230
// Name: void CollisionBSPData_LoadNodes(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadNodes(CCollisionBSPData *pBSPData)
{
  int SamplePosition; // edi
  signed int v2; // ebx
  const char *LoadName; // eax
  const char *v4; // eax
  cnode_t *v5; // eax
  int *v7; // ecx
  int v8; // edi
  cnode_t *m_pArray; // eax
  CMapLoadHelper lh; // [esp+Ch] [ebp-128h] BYREF
  CCollisionBSPData *pBSPDataa; // [esp+13Ch] [ebp+8h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 5u, bUncompress: true);
  SamplePosition = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&lh);
  if ( (CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) & 0x1F) != 0 )
    Sys_Error(error: "CollisionBSPData_LoadNodes: funny lump size");
  v2 = (unsigned int)CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) >> 5;
  if ( v2 == 0 )
    Sys_Error(error: "Map has no nodes");
  if ( v2 > 0x10000 )
    Sys_Error(error: "Map has too many nodes");
  LoadName = CMapLoadHelper::GetLoadName(this: &lh);
  v4 = va(format: "%s [%s]", LoadName, "Nodes");
  v5 = (cnode_t *)Hunk_AllocName(size: 4 * (3 * v2 + 18), name: v4, bClear: true);
  pBSPData->map_nodes.m_pArray = v5;
  pBSPData->numnodes = v2;
  pBSPData->map_rootnode = v5;
  if ( v2 > 0 )
  {
    v7 = (int *)(SamplePosition + 8);
    v8 = 0;
    for ( pBSPDataa = (CCollisionBSPData *)v2;
          pBSPDataa != nullptr;
          pBSPDataa = (CCollisionBSPData *)((char *)pBSPDataa - 1) )
    {
      m_pArray = pBSPData->map_nodes.m_pArray;
      m_pArray[v8].plane = &pBSPData->map_planes.m_pArray[*(v7 - 2)];
      m_pArray[v8].children[0] = *(v7 - 1);
      m_pArray[v8++].children[1] = *v7;
      v7 += 8;
    }
  }
  CMapLoadHelper::~CMapLoadHelper(this: &lh);
}

//------------------------------------------------------------------------------
// Address: 0x10152340
// Name: void CollisionBSPData_LoadAreas(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadAreas(CCollisionBSPData *pBSPData)
{
  int *SamplePosition; // esi
  signed int v2; // ebx
  const char *LoadName; // eax
  const char *v4; // eax
  int v5; // ecx
  signed int i; // edx
  carea_t *v7; // eax
  CMapLoadHelper lh; // [esp+Ch] [ebp-128h] BYREF

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x14u, bUncompress: true);
  SamplePosition = (int *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&lh);
  if ( (CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) & 7) != 0 )
    Sys_Error(error: "CMod_LoadAreas: funny lump size");
  v2 = (unsigned int)CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) >> 3;
  if ( (unsigned int)v2 > 0x100 )
    Sys_Error(error: "Map has too many areas");
  LoadName = CMapLoadHelper::GetLoadName(this: &lh);
  v4 = va(format: "%s [%s]", LoadName, "Areas");
  pBSPData->map_areas.m_pArray = (carea_t *)Hunk_AllocName(size: 16 * v2, name: v4, bClear: true);
  pBSPData->numareas = v2;
  if ( v2 > 0 )
  {
    v5 = 0;
    for ( i = v2; i != 0; --i )
    {
      v7 = &pBSPData->map_areas.m_pArray[v5];
      v7->numareaportals = *SamplePosition;
      v7->firstareaportal = SamplePosition[1];
      ++v5;
      SamplePosition += 2;
      v7->floodvalid = 0;
      v7->floodnum = 0;
    }
  }
  CMapLoadHelper::~CMapLoadHelper(this: &lh);
}

//------------------------------------------------------------------------------
// Address: 0x10152430
// Name: void CollisionBSPData_LoadAreaPortals(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadAreaPortals(CCollisionBSPData *pBSPData)
{
  unsigned __int8 *SamplePosition; // ebx
  unsigned __int32 v2; // edi
  int v3; // edi
  const char *LoadName; // eax
  const char *v5; // eax
  int i; // eax
  const char *v7; // eax
  const char *v8; // eax
  dareaportal_t *v9; // edi
  netadrtype_t Available; // eax
  CMapLoadHelper lh; // [esp+Ch] [ebp-128h] BYREF

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x15u, bUncompress: true);
  SamplePosition = (unsigned __int8 *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&lh);
  if ( CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) % 0xCu != 0 )
    Sys_Error(error: "CMod_LoadAreaPortals: funny lump size");
  v2 = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) / 0xCu;
  if ( v2 > 0x400 )
    Sys_Error(error: "Map has too many area portals");
  v3 = v2 + 1;
  pBSPData->numportalopen = v3;
  LoadName = CMapLoadHelper::GetLoadName(this: &lh);
  v5 = va(format: "%s [%s]", LoadName, "AreaPortals");
  pBSPData->portalopen.m_pArray = (bool *)Hunk_AllocName(size: pBSPData->numportalopen, name: v5, bClear: false);
  for ( i = 0; i < pBSPData->numportalopen; ++i )
    pBSPData->portalopen.m_pArray[i] = false;
  pBSPData->numareaportals = v3;
  v7 = CMapLoadHelper::GetLoadName(this: &lh);
  v8 = va(format: "%s [%s]", v7, "AreaPortals");
  v9 = (dareaportal_t *)Hunk_AllocName(size: 12 * v3, name: v8, bClear: true);
  pBSPData->map_areaportals.m_pArray = v9;
  Available = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh);
  memcpy(dst: (unsigned __int8 *)v9, src: SamplePosition, count: Available);
  CMapLoadHelper::~CMapLoadHelper(this: &lh);
}

//------------------------------------------------------------------------------
// Address: 0x10152570
// Name: void CollisionBSPData_LoadPhysics(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadPhysics(CCollisionBSPData *pBSPData)
{
  int SamplePosition; // esi
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  int v5; // ecx
  int v6; // edi
  netadrtype_t Available; // eax
  CMapLoadHelper lh; // [esp+0h] [ebp-12Ch] BYREF
  unsigned __int8 *basePtr; // [esp+128h] [ebp-4h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0x1Du, bUncompress: true);
  if ( CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) != NA_NULL )
  {
    SamplePosition = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&lh);
    basePtr = (unsigned __int8 *)SamplePosition;
    do
    {
      v2 = *(_DWORD *)(SamplePosition + 4);
      v3 = *(_DWORD *)SamplePosition;
      v4 = *(_DWORD *)(SamplePosition + 8);
      v5 = *(_DWORD *)(SamplePosition + 12);
      SamplePosition += 16;
      if ( v2 > 0 )
      {
        v6 = v2 + v4;
        physcollision->VCollideLoad(
          this: physcollision,
          a2: &pBSPData->map_cmodels.m_pArray[v3].vcollisionData,
          a3: v5,
          a4: (const char *)SamplePosition,
          a5: v6,
          a6: false);
        SamplePosition += v6;
      }
      Available = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh);
    }
    while ( SamplePosition - (int)basePtr <= Available && v2 > 0 );
  }
  CMapLoadHelper::~CMapLoadHelper(this: &lh);
}

//------------------------------------------------------------------------------
// Address: 0x10152630
// Name: void CollisionBSPData_LoadDispInfo(class CCollisionBSPData __near *,struct texinfo_s __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadDispInfo(CCollisionBSPData *pBSPData, texinfo_s *pTexinfo)
{
  signed __int32 v2; // esi
  int SamplePosition; // edi
  int v4; // ebx
  HDRType_t (__thiscall *GetHDRType)(IMaterialSystemHardwareConfig *); // eax
  bool v6; // cc
  unsigned int v7; // eax
  const char *LoadName; // eax
  const char *v9; // eax
  void *v10; // esp
  signed __int32 v11; // eax
  __int16 v12; // cx
  int v13; // ecx
  int v14; // esi
  int v15; // esi
  _WORD *v16; // ecx
  __int16 v17; // ax
  int v18; // esi
  int v19; // edx
  int *v20; // edx
  float *v21; // eax
  int v22; // ecx
  int v23; // ecx
  int v24; // ecx
  double v25; // st7
  int v26; // ecx
  double v27; // st7
  int v28; // ecx
  int v29; // ecx
  int v30; // ecx
  double v31; // st7
  int v32; // ecx
  double v33; // st7
  int v34; // ecx
  int v35; // ecx
  int v36; // ecx
  double v37; // st7
  int v38; // ecx
  double v39; // st7
  int v40; // ecx
  int v41; // ecx
  int v42; // ecx
  double v43; // st7
  int v44; // ecx
  double v45; // st7
  bool v46; // zf
  float *v47; // eax
  int *v48; // edx
  int v49; // ecx
  int v50; // ecx
  int v51; // ecx
  double v52; // st7
  int v53; // ecx
  double v54; // st7
  CDispCollTree *v55; // esi
  char *v56; // eax
  int m_iCounter; // edx
  int m_nContents; // ecx
  float y; // xmm0_4
  float z; // xmm1_4
  float v61; // xmm0_4
  float v62; // xmm1_4
  int v63; // eax
  IMaterial *v64; // edi
  int v65; // eax
  int v66; // eax
  IPhysicsSurfaceProps_vtbl *v67; // edx
  int v68; // eax
  const char *v69; // eax
  dphysdisp_t *v70; // esi
  netadrtype_t Available; // eax
  unsigned __int8 smoothingAngle[12]; // [esp+14h] [ebp-2854h] BYREF
  CDispVert v73; // [esp+20h] [ebp-2848h] BYREF
  CDispTri v74; // [esp+16B4h] [ebp-11B4h] BYREF
  CMapLoadHelper v75; // [esp+1AB4h] [ebp-DB4h] BYREF
  CMapLoadHelper v76; // [esp+1BDCh] [ebp-C8Ch] BYREF
  CMapLoadHelper v77; // [esp+1D04h] [ebp-B64h] BYREF
  CMapLoadHelper v78; // [esp+1E2Ch] [ebp-A3Ch] BYREF
  CMapLoadHelper v79; // [esp+1F54h] [ebp-914h] BYREF
  netadr_s v80; // [esp+207Ch] [ebp-7ECh] BYREF
  CMapLoadHelper v81; // [esp+2090h] [ebp-7D8h] BYREF
  CMapLoadHelper v82; // [esp+21B8h] [ebp-6B0h] BYREF
  CMapLoadHelper v83; // [esp+22E0h] [ebp-588h] BYREF
  CCoreDispInfo v84; // [esp+2408h] [ebp-460h] BYREF
  int pData; // [esp+2754h] [ebp-114h]
  int v86; // [esp+2758h] [ebp-110h]
  float v87; // [esp+275Ch] [ebp-10Ch]
  int v88; // [esp+2760h] [ebp-108h]
  CCoreDispNode *v89; // [esp+27F0h] [ebp-78h]
  float v90; // [esp+27F4h] [ebp-74h]
  _DWORD v91[8]; // [esp+27F8h] [ebp-70h] BYREF
  _DWORD v92[5]; // [esp+2818h] [ebp-50h] BYREF
  _WORD *v93; // [esp+282Ch] [ebp-3Ch]
  int v94; // [esp+2830h] [ebp-38h]
  float *v95; // [esp+2834h] [ebp-34h]
  int v96; // [esp+2838h] [ebp-30h]
  signed __int32 v97; // [esp+283Ch] [ebp-2Ch]
  const char *v98; // [esp+2840h] [ebp-28h]
  int v99; // [esp+2844h] [ebp-24h]
  int v100; // [esp+2848h] [ebp-20h]
  int v101; // [esp+284Ch] [ebp-1Ch]
  unsigned int v102; // [esp+2850h] [ebp-18h]
  int v103; // [esp+2854h] [ebp-14h]
  signed __int32 v104; // [esp+2858h] [ebp-10h]
  unsigned int v105; // [esp+285Ch] [ebp-Ch]
  _WORD *v106; // [esp+2860h] [ebp-8h]
  _DWORD var18[2]; // [esp+2864h] [ebp-4h] BYREF

  CMapLoadHelper::CMapLoadHelper(
    this: (CMapLoadHelper *)&v82.m_szLumpFilename[240],
    lumpToLoad: 0x1Au,
    bUncompress: true);
  v2 = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&v82.m_szLumpFilename[240]) / 0xB0u;
  v97 = v2;
  if ( v2 != 0 )
  {
    CMapLoadHelper::CMapLoadHelper(this: &v79, lumpToLoad: 3u, bUncompress: true);
    SamplePosition = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&v79);
    v94 = SamplePosition;
    if ( CCircularBuffer::GetReadAvailable(this: (netadr_s *)&v79) % 0xCu != 0 )
      Sys_Error(error: "CMod_LoadDispInfo: bad vertex lump size!");
    CMapLoadHelper::CMapLoadHelper(this: (CMapLoadHelper *)&v80, lumpToLoad: 0xCu, bUncompress: true);
    v4 = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&v80);
    if ( (CCircularBuffer::GetReadAvailable(this: &v80) & 3) != 0 )
      Sys_Error(error: "CMod_LoadDispInfo: bad edge lump size!");
    CMapLoadHelper::CMapLoadHelper(this: &v78, lumpToLoad: 0xDu, bUncompress: true);
    v96 = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&v78);
    if ( (CCircularBuffer::GetReadAvailable(this: (netadr_s *)&v78) & 3) != 0 )
      Sys_Error(error: "CMod_LoadDispInfo: bad surf edge lump size!");
    GetHDRType = g_pMaterialSystemHardwareConfig->GetHDRType;
    v103 = 7;
    if ( GetHDRType(this: g_pMaterialSystemHardwareConfig) == HDR_TYPE_NONE
      || (v6 = CMapLoadHelper::LumpSize(lumpId: 58) <= 0, v7 = 58, v6) )
    {
      v7 = v103;
    }
    CMapLoadHelper::CMapLoadHelper(
      this: (CMapLoadHelper *)&v81.m_szLumpFilename[240],
      lumpToLoad: v7,
      bUncompress: true);
    v106 = (_WORD *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&v81.m_szLumpFilename[240]);
    if ( CCircularBuffer::GetReadAvailable(this: (netadr_s *)&v81.m_szLumpFilename[240]) % 0x38u != 0 )
      Sys_Error(error: "CMod_LoadDispInfo: bad face lump size!");
    v104 = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&v81.m_szLumpFilename[240]) / 0x38u;
    v93 = v106;
    if ( v106 != nullptr )
    {
      g_DispCollTreeCount = v2;
      g_pDispCollTrees = DispCollTrees_Alloc(count: v2);
      LoadName = CMapLoadHelper::GetLoadName(this: (CMapLoadHelper *)&v82.m_szLumpFilename[240]);
      v9 = va(format: "%s [%s]", LoadName, "DispInfo");
      g_pDispBounds = (alignedbbox_t *)Hunk_AllocName(size: 48 * g_DispCollTreeCount, name: v9, bClear: false);
      v10 = alloca(2 * v2);
      v95 = (float *)smoothingAngle;
      memset(dst: smoothingAngle, value: 0xFFu, count: 2 * v2);
      v11 = 0;
      if ( v104 > 0 )
      {
        v106 += 6;
        do
        {
          v12 = *v106;
          if ( *v106 != 0xFFFF && v12 < v2 )
            *((_WORD *)v95 + v12) = v11;
          v106 += 28;
          ++v11;
        }
        while ( v11 < v104 );
      }
      v100 = 0;
      v99 = 0;
      memset(&v92[2], 0, 12);
      CMapLoadHelper::CMapLoadHelper(this: &v76, lumpToLoad: 0x21u, bUncompress: true);
      CMapLoadHelper::CMapLoadHelper(this: &v75, lumpToLoad: 0x30u, bUncompress: true);
      v13 = 0;
      v103 = 0;
      if ( v2 > 0 )
      {
        v104 = 0;
        v102 = 0;
        do
        {
          v105 = *((unsigned __int16 *)v95 + v13);
          if ( (_WORD)v105 != 0xFFFF )
          {
            CMapLoadHelper::LoadLumpElement(
              this: (CMapLoadHelper *)&v82.m_szLumpFilename[240],
              nElemIndex: v13,
              nElemSize: 176,
              pData: &v84.m_AllowedVerts.m_Ints[6]);
            v14 = ((1 << pData) + 1) * ((1 << pData) + 1);
            CMapLoadHelper::LoadLumpData(this: &v76, offset: 20 * v100, size: 20 * v14, pData: &v73);
            v100 += v14;
            v15 = 2 * (1 << pData) * (1 << pData);
            CMapLoadHelper::LoadLumpData(
              this: &v75,
              offset: 2 * v99,
              size: 4 * (1 << pData) * (1 << pData),
              pData: &v74);
            v99 += v15;
            CCoreDispInfo::CCoreDispInfo(this: (CCoreDispInfo *)&v83.m_szLumpFilename[240]);
            *(_DWORD *)&v84.m_Surf.m_CornerNeighbors[2].m_Neighbors[2] = v88;
            LODWORD(v84.m_Surf.sAxis.z) = v84.m_AllowedVerts.m_Ints[6];
            LODWORD(v84.m_Surf.tAxis.x) = v84.m_AllowedVerts.m_Ints[7];
            LODWORD(v84.m_Surf.tAxis.y) = v84.m_AllowedVerts.m_Ints[8];
            CCoreDispInfo::InitDispInfo(
              this: (CCoreDispInfo *)&v83.m_szLumpFilename[240],
              power: pData,
              minTess: v86,
              smoothingAngle: v87,
              pVerts: &v73,
              pTris: &v74,
              nFlags: 0,
              pvMultiBlends: nullptr);
            v16 = &v93[28 * (unsigned __int16)v105];
            *(_DWORD *)&v83.m_szLumpFilename[256] = (unsigned __int16)v105;
            v17 = v16[4];
            v106 = v16;
            if ( v17 > 4 )
              goto LABEL_24;
            if ( v17 == 4 )
              v84.__vftable = (CCoreDispInfo_vtbl *)4;
            v18 = (__int16)v16[4];
            v19 = 0;
            v101 = 0;
            v98 = (const char *)v18;
            if ( v18 >= 4 )
            {
              v20 = (int *)(v96 + 4 * *((_DWORD *)v16 + 1) + 8);
              v105 = ((unsigned int)(v18 - 4) >> 2) + 1;
              v21 = (float *)v91;
              v101 = 4 * v105;
              do
              {
                v22 = *(v20 - 2);
                if ( v22 >= 0 )
                  v23 = *(unsigned __int16 *)(v4 + 4 * v22);
                else
                  v23 = *(unsigned __int16 *)(v4 - 4 * v22 + 2);
                v24 = 3 * v23;
                v25 = *(float *)(SamplePosition + 4 * v24);
                v26 = SamplePosition + 4 * v24;
                *(v21 - 2) = v25;
                *(v21 - 1) = *(float *)(v26 + 4);
                v27 = *(float *)(v26 + 8);
                v28 = *(v20 - 1);
                *v21 = v27;
                if ( v28 >= 0 )
                  v29 = *(unsigned __int16 *)(v4 + 4 * v28);
                else
                  v29 = *(unsigned __int16 *)(v4 - 4 * v28 + 2);
                v30 = 3 * v29;
                v31 = *(float *)(SamplePosition + 4 * v30);
                v32 = SamplePosition + 4 * v30;
                v21[1] = v31;
                v21[2] = *(float *)(v32 + 4);
                v33 = *(float *)(v32 + 8);
                v34 = *v20;
                v21[3] = v33;
                if ( v34 >= 0 )
                  v35 = *(unsigned __int16 *)(v4 + 4 * v34);
                else
                  v35 = *(unsigned __int16 *)(v4 - 4 * v34 + 2);
                v36 = 3 * v35;
                v37 = *(float *)(SamplePosition + 4 * v36);
                v38 = SamplePosition + 4 * v36;
                v21[4] = v37;
                v21[5] = *(float *)(v38 + 4);
                v39 = *(float *)(v38 + 8);
                v40 = v20[1];
                v21[6] = v39;
                if ( v40 >= 0 )
                  v41 = *(unsigned __int16 *)(v4 + 4 * v40);
                else
                  v41 = *(unsigned __int16 *)(v4 - 4 * v40 + 2);
                v42 = 3 * v41;
                v43 = *(float *)(SamplePosition + 4 * v42);
                v44 = SamplePosition + 4 * v42;
                v21[7] = v43;
                v20 += 4;
                v45 = *(float *)(v44 + 4);
                v21 += 12;
                v46 = v105-- == 1;
                *(v21 - 4) = v45;
                *(v21 - 3) = *(float *)(v44 + 8);
              }
              while ( !v46 );
              v18 = (int)v98;
              v16 = v106;
              v19 = v101;
            }
            if ( v19 < v18 )
            {
              v47 = (float *)&v91[3 * v19];
              v48 = (int *)(v96 + 4 * (v19 + *((_DWORD *)v16 + 1)));
              v105 = v18 - v101;
              do
              {
                v49 = *v48;
                if ( *v48 >= 0 )
                  v50 = *(unsigned __int16 *)(v4 + 4 * v49);
                else
                  v50 = *(unsigned __int16 *)(v4 - 4 * v49 + 2);
                v51 = 3 * v50;
                v52 = *(float *)(SamplePosition + 4 * v51);
                v53 = SamplePosition + 4 * v51;
                *(v47 - 2) = v52;
                ++v48;
                v54 = *(float *)(v53 + 4);
                v47 += 3;
                v46 = v105-- == 1;
                *(v47 - 4) = v54;
                *(v47 - 3) = *(float *)(v53 + 8);
              }
              while ( !v46 );
            }
            v84.m_Nodes = v89;
            v84.m_Elevation = v90;
            qmemcpy(&v84.m_Power, v91, 32);
            LODWORD(v84.m_Surf.m_Points[1].z) = v92[0];
            LODWORD(v84.m_Surf.m_Points[2].x) = v92[1];
            CCoreDispSurface::FindSurfPointStartIndex(this: (CCoreDispSurface *)&v83.m_szLumpFilename[256]);
            CCoreDispSurface::AdjustSurfPointData(this: (CCoreDispSurface *)&v83.m_szLumpFilename[256]);
            v55 = &g_pDispCollTrees[v102 / 0xF4];
            g_pDispCollTrees[v102 / 0xF4].m_nPower = 0;
            if ( v84.__vftable == (CCoreDispInfo_vtbl *)4 )
            {
              CCoreDispInfo::Create(this: (CCoreDispInfo *)&v83.m_szLumpFilename[240]);
              v55->Create(this: v55, a2: (CCoreDispInfo *)&v83.m_szLumpFilename[240]);
              v56 = (char *)g_pDispBounds + v104;
              m_iCounter = v55->m_iCounter;
              m_nContents = v55->m_nContents;
              y = v55->m_mins.y;
              z = v55->m_mins.z;
              *(float *)v56 = v55->m_mins.x;
              *((_DWORD *)v56 + 8) = m_iCounter;
              *((float *)v56 + 1) = y;
              *((float *)v56 + 2) = z;
              v61 = v55->m_maxs.y;
              v62 = v55->m_maxs.z;
              *((float *)v56 + 4) = v55->m_maxs.x;
              *((float *)v56 + 5) = v61;
              *((float *)v56 + 6) = v62;
              *((_DWORD *)v56 + 9) = m_nContents;
              ++v92[v55->m_nPower];
              v105 = (unsigned int)&pTexinfo[(__int16)v106[5]];
              v63 = *(_DWORD *)(v105 + 68);
              if ( v63 >= 0 )
              {
                v64 = materials->FindMaterial(
                        this: materials,
                        a2: pBSPData->map_surfaces.m_pArray[v63].name,
                        a3: "World textures",
                        a4: 1,
                        a5: 0);
                if ( v64 != nullptr && !v64->IsErrorMaterial(this: v64) )
                {
                  v65 = (int)v64->FindVar(this: v64, a2: "$surfaceprop", a3: (bool *)var18 + 3, a4: false);
                  if ( HIBYTE(var18[0]) != 0 )
                  {
                    v66 = (*(int (__thiscall **)(int))(*(_DWORD *)v65 + 28))(a1: v65);
                    v67 = physprops->__vftable;
                    v98 = (const char *)v66;
                    v55->m_nSurfaceProps[0] = v67->GetSurfaceIndex(this: physprops, a2: (const char *)v66);
                    v55->m_nSurfaceProps[1] = physprops->GetSurfaceIndex(this: physprops, a2: v98);
                  }
                  v68 = (int)v64->FindVar(this: v64, a2: "$surfaceprop2", a3: (bool *)var18 + 3, a4: false);
                  if ( HIBYTE(var18[0]) != 0 )
                  {
                    v69 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v68 + 28))(a1: v68);
                    v55->m_nSurfaceProps[1] = physprops->GetSurfaceIndex(this: physprops, a2: v69);
                  }
                }
                v55->m_nTexinfoFlags = pBSPData->map_surfaces.m_pArray[*(_DWORD *)(v105 + 68)].flags;
              }
              CCoreDispInfo::~CCoreDispInfo(this: (CCoreDispInfo *)&v83.m_szLumpFilename[240]);
              SamplePosition = v94;
            }
            else
            {
LABEL_24:
              CCoreDispInfo::~CCoreDispInfo(this: (CCoreDispInfo *)&v83.m_szLumpFilename[240]);
            }
            v2 = v97;
          }
          v102 += 244;
          v104 += 48;
          v13 = v103 + 1;
          v103 = v13;
        }
        while ( v13 < v2 );
      }
      CMapLoadHelper::CMapLoadHelper(this: &v77, lumpToLoad: 0x1Cu, bUncompress: true);
      v70 = (dphysdisp_t *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&v77);
      Available = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&v77);
      CM_CreateDispPhysCollide(pDispLump: v70, dispLumpSize: Available);
      CMapLoadHelper::~CMapLoadHelper(this: &v77);
      CMapLoadHelper::~CMapLoadHelper(this: &v75);
      CMapLoadHelper::~CMapLoadHelper(this: &v76);
    }
    CMapLoadHelper::~CMapLoadHelper(this: (CMapLoadHelper *)&v81.m_szLumpFilename[240]);
    CMapLoadHelper::~CMapLoadHelper(this: &v78);
    CMapLoadHelper::~CMapLoadHelper(this: (CMapLoadHelper *)&v80);
    CMapLoadHelper::~CMapLoadHelper(this: &v79);
  }
  CMapLoadHelper::~CMapLoadHelper(this: (CMapLoadHelper *)&v82.m_szLumpFilename[240]);
}

//------------------------------------------------------------------------------
// Address: 0x10152E80
// Name: void CollisionBSPData_Destroy(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_Destroy(CCollisionBSPData *pBSPData)
{
  int v2; // edi
  CCollisionBSPData *pBSPDataa; // [esp+14h] [ebp+8h]

  v2 = 0;
  if ( pBSPData->numcmodels > 0 )
  {
    pBSPDataa = nullptr;
    do
    {
      physcollision->VCollideUnload(
        this: physcollision,
        a2: (vcollide_t *)((char *)&pBSPData->map_cmodels.m_pArray->vcollisionData + (unsigned int)pBSPDataa));
      pBSPDataa = (CCollisionBSPData *)((char *)pBSPDataa + 56);
      ++v2;
    }
    while ( v2 < pBSPData->numcmodels );
  }
  DispCollTrees_FreeLeafList(pBSPData);
  CM_DestroyDispPhysCollide();
  DispCollTrees_Free(pTrees: g_pDispCollTrees);
  g_pDispCollTrees = nullptr;
  g_pDispBounds = nullptr;
  g_DispCollTreeCount = 0;
  if ( pBSPData->map_planes.m_pArray != nullptr )
    pBSPData->map_planes.m_pArray = nullptr;
  if ( pBSPData->map_texturenames != nullptr )
    pBSPData->map_texturenames = nullptr;
  if ( pBSPData->map_surfaces.m_pArray != nullptr )
    pBSPData->map_surfaces.m_pArray = nullptr;
  if ( pBSPData->map_areaportals.m_pArray != nullptr )
    pBSPData->map_areaportals.m_pArray = nullptr;
  if ( pBSPData->portalopen.m_pArray != nullptr )
    pBSPData->portalopen.m_pArray = nullptr;
  if ( pBSPData->map_areas.m_pArray != nullptr )
    pBSPData->map_areas.m_pArray = nullptr;
  pBSPData->map_entitystring.m_buf.m_Get = 0;
  pBSPData->map_entitystring.m_buf.m_Put = 0;
  pBSPData->map_entitystring.m_buf.m_nOffset = 0;
  pBSPData->map_entitystring.m_buf.m_nMaxPut = 0;
  pBSPData->map_entitystring.m_buf.m_Error = 0;
  if ( pBSPData->map_entitystring.m_buf.m_Memory.m_nGrowSize >= 0 )
  {
    if ( pBSPData->map_entitystring.m_buf.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pBSPData->map_entitystring.m_buf.m_Memory.m_pMemory);
      pBSPData->map_entitystring.m_buf.m_Memory.m_pMemory = nullptr;
    }
    pBSPData->map_entitystring.m_buf.m_Memory.m_nAllocationCount = 0;
  }
  if ( pBSPData->map_brushes.m_pArray != nullptr )
    pBSPData->map_brushes.m_pArray = nullptr;
  if ( pBSPData->map_dispList.m_pArray != nullptr )
    pBSPData->map_dispList.m_pArray = nullptr;
  if ( pBSPData->map_cmodels.m_pArray != nullptr )
    pBSPData->map_cmodels.m_pArray = nullptr;
  if ( pBSPData->map_leafbrushes.m_pArray != nullptr )
    pBSPData->map_leafbrushes.m_pArray = nullptr;
  if ( pBSPData->map_leafs.m_pArray != nullptr )
    pBSPData->map_leafs.m_pArray = nullptr;
  if ( pBSPData->map_nodes.m_pArray != nullptr )
    pBSPData->map_nodes.m_pArray = nullptr;
  if ( pBSPData->map_brushsides.m_pArray != nullptr )
    pBSPData->map_brushsides.m_pArray = nullptr;
  if ( pBSPData->map_boxbrushes.m_pArray != nullptr )
    pBSPData->map_boxbrushes.m_pArray = nullptr;
  if ( pBSPData->map_vis != nullptr )
    pBSPData->map_vis = nullptr;
  pBSPData->numplanes = 0;
  pBSPData->numbrushsides = 0;
  pBSPData->solidleaf = 0;
  pBSPData->emptyleaf = 0;
  pBSPData->numnodes = 0;
  pBSPData->numleafs = 0;
  pBSPData->numbrushes = 0;
  pBSPData->numboxbrushes = 0;
  pBSPData->numdisplist = 0;
  pBSPData->numleafbrushes = 0;
  pBSPData->numareas = 0;
  pBSPData->numtextures = 0;
  pBSPData->floodvalid = 0;
  pBSPData->numareaportals = 0;
  pBSPData->numclusters = 0;
  pBSPData->numcmodels = 0;
  pBSPData->numvisibility = 0;
  pBSPData->numentitychars = 0;
  pBSPData->numportalopen = 0;
  pBSPData->mapPathName[0] = 0;
  pBSPData->map_rootnode = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10153080
// Name: public: void CDiscardableArray<char>::Init(char __near *,int,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDiscardableArray<char>::Init(
        CDiscardableArray<char> *this,
        char *pFilename,
        int nOffset,
        int nCount,
        unsigned __int8 *pData)
{
  if ( this->m_buf.m_Put != 0 )
  {
    this->m_buf.m_Get = 0;
    this->m_buf.m_Put = 0;
    this->m_buf.m_nOffset = 0;
    this->m_buf.m_nMaxPut = 0;
    this->m_buf.m_Error = 0;
    if ( this->m_buf.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_buf.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_buf.m_Memory.m_pMemory);
        this->m_buf.m_Memory.m_pMemory = nullptr;
      }
      this->m_buf.m_Memory.m_nAllocationCount = 0;
    }
  }
  this->m_nCount = nCount;
  _V_strcpy(dest: this->m_pFilename, src: pFilename);
  this->m_nOffset = nOffset;
  if ( pData != nullptr )
    CUtlBuffer::Put(this: &this->m_buf, pMem: pData, size: nCount);
}

//------------------------------------------------------------------------------
// Address: 0x10153100
// Name: void CollisionBSPData_LoadEntityString(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadEntityString(CCollisionBSPData *pBSPData)
{
  char *DiskName; // eax
  char *v2; // [esp-Ch] [ebp-138h]
  netadrtype_t Available; // [esp-8h] [ebp-134h]
  unsigned __int8 *SamplePosition; // [esp-4h] [ebp-130h]
  CMapLoadHelper lh; // [esp+4h] [ebp-128h] BYREF

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0, bUncompress: true);
  pBSPData->numentitychars = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh);
  SamplePosition = (unsigned __int8 *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&lh);
  Available = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh);
  v2 = CWaveDataStreamAsync::Source(this: (vgui::Tooltip *)&lh);
  DiskName = CMapLoadHelper::GetDiskName(this: &lh);
  CDiscardableArray<char>::Init(
    this: &pBSPData->map_entitystring,
    pFilename: DiskName,
    nOffset: (int)v2,
    nCount: Available,
    pData: SamplePosition);
  CMapLoadHelper::~CMapLoadHelper(this: &lh);
}

//------------------------------------------------------------------------------
// Address: 0x10153180
// Name: bool CollisionBSPData_Load(char const __near *,class CCollisionBSPData __near *,struct texinfo_s __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CollisionBSPData_Load(
        const char *pPathName,
        CCollisionBSPData *pBSPData,
        texinfo_s *pTexinfo,
        int texinfoCount)
{
  V_strncpy(pDest: pBSPData->mapPathName, pSrc: pPathName, maxLen: 96);
  _COM_TimestampedLog(a1: "  CollisionBSPData_LoadTextures");
  CollisionBSPData_LoadTextures(pBSPData);
  _COM_TimestampedLog(a1: "  CollisionBSPData_LoadTexinfo");
  CollisionBSPData_LoadTexinfo(pBSPData, pTexinfo, texinfoCount);
  _COM_TimestampedLog(a1: "  CollisionBSPData_LoadLeafs");
  CollisionBSPData_LoadLeafs(pBSPData);
  _COM_TimestampedLog(a1: "  CollisionBSPData_LoadLeafBrushes");
  CollisionBSPData_LoadLeafBrushes(pBSPData);
  _COM_TimestampedLog(a1: "  CollisionBSPData_LoadPlanes");
  CollisionBSPData_LoadPlanes(pBSPData);
  _COM_TimestampedLog(a1: "  CollisionBSPData_LoadBrushes");
  CollisionBSPData_LoadBrushes(pBSPData);
  _COM_TimestampedLog(a1: "  CollisionBSPData_LoadBrushSides");
  CollisionBSPData_LoadBrushSides(pBSPData, pTexinfo, texinfoCount);
  _COM_TimestampedLog(a1: "  CollisionBSPData_LoadSubmodels");
  CollisionBSPData_LoadSubmodels(pBSPData);
  _COM_TimestampedLog(a1: "  CollisionBSPData_LoadPlanes");
  CollisionBSPData_LoadNodes(pBSPData);
  _COM_TimestampedLog(a1: "  CollisionBSPData_LoadAreas");
  CollisionBSPData_LoadAreas(pBSPData);
  _COM_TimestampedLog(a1: "  CollisionBSPData_LoadAreaPortals");
  CollisionBSPData_LoadAreaPortals(pBSPData);
  _COM_TimestampedLog(a1: "  CollisionBSPData_LoadVisibility");
  CollisionBSPData_LoadVisibility(pBSPData);
  _COM_TimestampedLog(a1: "  CollisionBSPData_LoadEntityString");
  CollisionBSPData_LoadEntityString(pBSPData);
  _COM_TimestampedLog(a1: "  CollisionBSPData_LoadPhysics");
  CollisionBSPData_LoadPhysics(pBSPData);
  _COM_TimestampedLog(a1: "  CollisionBSPData_LoadDispInfo");
  CollisionBSPData_LoadDispInfo(pBSPData, pTexinfo);
  return 1;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10150C90
// Name: class CDispCollTree __near * CollisionBSPData_GetCollisionTree(int)
// Source: json
//------------------------------------------------------------------------------
CDispCollTree *__cdecl CollisionBSPData_GetCollisionTree(int i)
{
  if ( i < 0 || i >= g_DispCollTreeCount )
    return nullptr;
  else
    return &g_pDispCollTrees[i];
}

//------------------------------------------------------------------------------
// Address: 0x10150CC0
// Name: void CollisionBSPData_LinkPhysics(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LinkPhysics()
{
  IPhysicsCollision *v0; // eax

  if ( physprops == nullptr )
  {
    physprops = (IPhysicsSurfaceProps *)g_AppSystemFactory(a1: "VPhysicsSurfaceProps001", a2: nullptr);
    v0 = (IPhysicsCollision *)g_AppSystemFactory(a1: "VPhysicsCollision007", a2: nullptr);
    physcollision = v0;
    if ( physprops == nullptr || v0 == nullptr )
      Sys_Error(error: "CollisionBSPData_PreLoad: Can't link physics");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10150D10
// Name: void CollisionBSPData_PreLoad(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_PreLoad(CCollisionBSPData *pBSPData)
{
  pBSPData->numleafs = 1;
  pBSPData->map_vis = nullptr;
  pBSPData->numareas = 1;
  pBSPData->numclusters = 1;
  pBSPData->map_nullname = "**empty**";
  pBSPData->numtextures = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10150D50
// Name: void ExtractBoxBrush(struct cboxbrush_t __near *,struct cbrush_t const __near &,struct dbrushside_t __near *,struct cplane_t __near *,struct texinfo_s __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ExtractBoxBrush(
        cplane_t *pBox,
        const cbrush_t *brush,
        dbrushside_t *pSides,
        cplane_t *pPlanes,
        texinfo_s *pTexinfo)
{
  dbrushside_t *v6; // esi
  int texinfo; // eax
  int type; // ecx
  float v9; // xmm0_4
  int firstbrushside; // ecx
  dbrushside_t *v11; // esi
  int v12; // eax
  int v13; // ecx
  float v14; // xmm0_4
  int v15; // ecx
  dbrushside_t *v16; // esi
  int v17; // eax
  int v18; // ecx
  float v19; // xmm0_4
  int v20; // ecx
  dbrushside_t *v21; // esi
  int v22; // eax
  int v23; // ecx
  float v24; // xmm0_4
  int v25; // ecx
  dbrushside_t *v26; // esi
  int v27; // eax
  int v28; // ecx
  float v29; // xmm0_4
  int v30; // ecx
  dbrushside_t *v31; // esi
  cplane_t *v32; // edi
  int v33; // eax
  int texdata; // ebx
  int v35; // ecx
  float v36; // xmm0_4
  int surfaceIndex; // [esp+Ch] [ebp-4h]
  int surfaceIndexa; // [esp+Ch] [ebp-4h]
  int surfaceIndexb; // [esp+Ch] [ebp-4h]
  int surfaceIndexc; // [esp+Ch] [ebp-4h]
  int surfaceIndexd; // [esp+Ch] [ebp-4h]
  cplane_t *plane; // [esp+18h] [ebp+8h]
  cplane_t *planea; // [esp+18h] [ebp+8h]
  cplane_t *planeb; // [esp+18h] [ebp+8h]
  cplane_t *planec; // [esp+18h] [ebp+8h]
  cplane_t *planed; // [esp+18h] [ebp+8h]

  LOWORD(pBox[2].normal.y) = 0;
  v6 = &pSides[brush->firstbrushside];
  plane = &pPlanes[v6->planenum];
  texinfo = v6->texinfo;
  if ( texinfo >= 0 )
    surfaceIndex = pTexinfo[texinfo].texdata;
  else
    LOWORD(surfaceIndex) = -1;
  type = plane->type;
  v9 = *(&plane->normal.x + type);
  if ( v9 == 1.0 )
  {
    *((float *)&pBox->type + type) = plane->dist;
    *(_WORD *)&pBox[1].pad[2 * type] = surfaceIndex;
    LOBYTE(type) = type + 3;
  }
  else if ( v9 == -1.0 )
  {
    *(&pBox->normal.x + type) = -plane->dist;
    *((_WORD *)&pBox[1].dist + type) = surfaceIndex;
  }
  LOWORD(pBox[2].normal.y) |= v6->thin << type;
  firstbrushside = brush->firstbrushside;
  v11 = &pSides[firstbrushside + 1];
  planea = &pPlanes[v11->planenum];
  v12 = pSides[firstbrushside + 1].texinfo;
  if ( v12 >= 0 )
    surfaceIndexa = pTexinfo[v12].texdata;
  else
    LOWORD(surfaceIndexa) = -1;
  v13 = planea->type;
  v14 = *(&planea->normal.x + v13);
  if ( v14 == 1.0 )
  {
    *((float *)&pBox->type + v13) = planea->dist;
    *(_WORD *)&pBox[1].pad[2 * v13] = surfaceIndexa;
    LOBYTE(v13) = v13 + 3;
  }
  else if ( v14 == -1.0 )
  {
    *(&pBox->normal.x + v13) = -planea->dist;
    *((_WORD *)&pBox[1].dist + v13) = surfaceIndexa;
  }
  LOWORD(pBox[2].normal.y) |= v11->thin << v13;
  v15 = brush->firstbrushside;
  v16 = &pSides[v15 + 2];
  planeb = &pPlanes[v16->planenum];
  v17 = pSides[v15 + 2].texinfo;
  if ( v17 >= 0 )
    surfaceIndexb = pTexinfo[v17].texdata;
  else
    LOWORD(surfaceIndexb) = -1;
  v18 = planeb->type;
  v19 = *(&planeb->normal.x + v18);
  if ( v19 == 1.0 )
  {
    *((float *)&pBox->type + v18) = planeb->dist;
    *(_WORD *)&pBox[1].pad[2 * v18] = surfaceIndexb;
    LOBYTE(v18) = v18 + 3;
  }
  else if ( v19 == -1.0 )
  {
    *(&pBox->normal.x + v18) = -planeb->dist;
    *((_WORD *)&pBox[1].dist + v18) = surfaceIndexb;
  }
  LOWORD(pBox[2].normal.y) |= v16->thin << v18;
  v20 = brush->firstbrushside;
  v21 = &pSides[v20 + 3];
  planec = &pPlanes[v21->planenum];
  v22 = pSides[v20 + 3].texinfo;
  if ( v22 >= 0 )
    surfaceIndexc = pTexinfo[v22].texdata;
  else
    LOWORD(surfaceIndexc) = -1;
  v23 = planec->type;
  v24 = *(&planec->normal.x + v23);
  if ( v24 == 1.0 )
  {
    *((float *)&pBox->type + v23) = planec->dist;
    *(_WORD *)&pBox[1].pad[2 * v23] = surfaceIndexc;
    LOBYTE(v23) = v23 + 3;
  }
  else if ( v24 == -1.0 )
  {
    *(&pBox->normal.x + v23) = -planec->dist;
    *((_WORD *)&pBox[1].dist + v23) = surfaceIndexc;
  }
  LOWORD(pBox[2].normal.y) |= v21->thin << v23;
  v25 = brush->firstbrushside;
  v26 = &pSides[v25 + 4];
  planed = &pPlanes[v26->planenum];
  v27 = pSides[v25 + 4].texinfo;
  if ( v27 >= 0 )
    surfaceIndexd = pTexinfo[v27].texdata;
  else
    LOWORD(surfaceIndexd) = -1;
  v28 = planed->type;
  v29 = *(&planed->normal.x + v28);
  if ( v29 == 1.0 )
  {
    *((float *)&pBox->type + v28) = planed->dist;
    *(_WORD *)&pBox[1].pad[2 * v28] = surfaceIndexd;
    LOBYTE(v28) = v28 + 3;
  }
  else if ( v29 == -1.0 )
  {
    *(&pBox->normal.x + v28) = -planed->dist;
    *((_WORD *)&pBox[1].dist + v28) = surfaceIndexd;
  }
  LOWORD(pBox[2].normal.y) |= v26->thin << v28;
  v30 = brush->firstbrushside;
  v31 = &pSides[v30 + 5];
  v32 = &pPlanes[v31->planenum];
  v33 = pSides[v30 + 5].texinfo;
  if ( v33 >= 0 )
    texdata = pTexinfo[v33].texdata;
  else
    LOWORD(texdata) = -1;
  v35 = v32->type;
  v36 = *(&v32->normal.x + v35);
  if ( v36 == 1.0 )
  {
    v35 += 3;
    *(&pBox->normal.y + v35) = v32->dist;
    *((_WORD *)&pBox[1].dist + v35) = texdata;
  }
  else if ( v36 == -1.0 )
  {
    *(&pBox->normal.x + v35) = -v32->dist;
    *((_WORD *)&pBox[1].dist + v35) = texdata;
  }
  LOWORD(pBox[2].normal.y) |= v31->thin << v35;
  HIWORD(pBox[2].normal.y) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101510E0
// Name: void CollisionBSPData_LoadVisibility(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadVisibility(CCollisionBSPData *pBSPData)
{
  netadrtype_t Available; // esi
  const char *LoadName; // eax
  const char *v3; // eax
  unsigned __int8 *SamplePosition; // eax
  CMapLoadHelper lh; // [esp+8h] [ebp-128h] BYREF

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 4, bUncompress: true);
  pBSPData->numvisibility = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh);
  if ( CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) > 0x1000000 )
    Sys_Error(error: "Map has too large visibility lump");
  Available = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh);
  if ( Available != NA_NULL )
  {
    LoadName = CMapLoadHelper::GetLoadName(this: &lh);
    v3 = va(format: "%s [%s]", LoadName, "Visibility");
    pBSPData->map_vis = (dvis_t *)Hunk_AllocName(size: Available, name: v3, bClear: false);
    SamplePosition = (unsigned __int8 *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&lh);
    memcpy(dst: (unsigned __int8 *)pBSPData->map_vis, src: SamplePosition, count: Available);
  }
  else
  {
    pBSPData->map_vis = nullptr;
  }
  CMapLoadHelper::~CMapLoadHelper(this: &lh);
}

//------------------------------------------------------------------------------
// Address: 0x101511C0
// Name: void CollisionBSPData_LoadTextures(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadTextures(CCollisionBSPData *pBSPData)
{
  unsigned __int8 *SamplePosition; // ebx
  signed int v2; // edi
  CCollisionBSPData *v3; // esi
  const char *LoadName; // eax
  const char *v5; // eax
  const char *v6; // eax
  netadrtype_t Available; // eax
  netadrtype_t v8; // eax
  csurface_t *m_pArray; // eax
  int v10; // edi
  IMaterial *v11; // ebx
  int v12; // eax
  const char *v13; // eax
  csurface_t *v14; // ebx
  const char *v15; // [esp-8h] [ebp-39Ch]
  CMapLoadHelper lhStringTable; // [esp+Ch] [ebp-388h] BYREF
  CMapLoadHelper lhStringData; // [esp+134h] [ebp-260h] BYREF
  CMapLoadHelper lh; // [esp+25Ch] [ebp-138h] BYREF
  int *pStringTable; // [esp+384h] [ebp-10h]
  int count; // [esp+388h] [ebp-Ch]
  int i; // [esp+38Ch] [ebp-8h]
  dtexdata_t *in; // [esp+390h] [ebp-4h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 2, bUncompress: true);
  CMapLoadHelper::CMapLoadHelper(this: &lhStringData, lumpToLoad: 43, bUncompress: true);
  SamplePosition = (unsigned __int8 *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&lhStringData);
  CMapLoadHelper::CMapLoadHelper(this: &lhStringTable, lumpToLoad: 44, bUncompress: true);
  if ( (CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lhStringTable) & 3) != 0 )
    Sys_Error(error: "CMod_LoadTextures: funny lump size");
  pStringTable = (int *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&lhStringTable);
  in = (dtexdata_t *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&lh);
  if ( (CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) & 0x1F) != 0 )
    Sys_Error(error: "CMod_LoadTextures: funny lump size");
  v2 = (unsigned int)CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) >> 5;
  count = v2;
  if ( v2 == 0 )
    Sys_Error(error: "Map with no textures");
  if ( v2 > 2048 )
    Sys_Error(error: "Map has too many textures");
  v3 = pBSPData;
  LoadName = CMapLoadHelper::GetLoadName(this: &lh);
  v5 = va(format: "%s [%s]", LoadName, "Textures");
  v3->map_surfaces.m_pArray = (csurface_t *)Hunk_AllocName(size: 8 * v2, name: v5, bClear: true);
  v3->numtextures = v2;
  v6 = CMapLoadHelper::GetLoadName(this: &lh);
  v15 = va(format: "%s [%s]", v6, "Textures");
  Available = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lhStringData);
  v3->map_texturenames = (char *)Hunk_AllocName(size: Available, name: v15, bClear: false);
  v8 = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lhStringData);
  memcpy(dst: (unsigned __int8 *)v3->map_texturenames, src: SamplePosition, count: v8);
  i = 0;
  if ( v2 > 0 )
  {
    in = (dtexdata_t *)((char *)in + 12);
    do
    {
      m_pArray = v3->map_surfaces.m_pArray;
      v10 = i;
      m_pArray[v10].name = &v3->map_texturenames[pStringTable[LODWORD(in->reflectivity.x)]];
      *(_DWORD *)&m_pArray[v10].surfaceProps = 0;
      v11 = materials->FindMaterial(
              this: materials,
              a2: v3->map_surfaces.m_pArray[v10].name,
              a3: "World textures",
              a4: 1,
              a5: 0);
      if ( v11 != nullptr && !v11->IsErrorMaterial(this: v11) )
      {
        v12 = (int)v11->FindVar(this: v11, a2: "$surfaceprop", a3: (bool *)&pBSPData + 3, a4: false);
        if ( HIBYTE(pBSPData) != 0 )
        {
          v13 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v12 + 28))(a1: v12);
          v14 = v3->map_surfaces.m_pArray;
          v14[v10].surfaceProps = physprops->GetSurfaceIndex(this: physprops, a2: v13);
        }
      }
      ++in;
      ++i;
    }
    while ( i < count );
  }
  CMapLoadHelper::~CMapLoadHelper(this: &lhStringTable);
  CMapLoadHelper::~CMapLoadHelper(this: &lhStringData);
  CMapLoadHelper::~CMapLoadHelper(this: &lh);
}

//------------------------------------------------------------------------------
// Address: 0x10151420
// Name: void CollisionBSPData_LoadTexinfo(class CCollisionBSPData __near *,struct texinfo_s __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadTexinfo(CCollisionBSPData *pBSPData, texinfo_s *pTexinfo, int texinfoCount)
{
  int v3; // esi
  int *p_flags; // ecx
  int v5; // eax
  unsigned __int16 *v6; // eax

  v3 = texinfoCount;
  if ( texinfoCount > 0 )
  {
    p_flags = &pTexinfo->flags;
    do
    {
      v5 = *((unsigned __int16 *)p_flags + 2);
      if ( v5 >= pBSPData->numtextures )
        LOWORD(v5) = 0;
      v6 = &pBSPData->map_surfaces.m_pArray[(unsigned __int16)v5].flags;
      *v6 |= *(_WORD *)p_flags;
      p_flags += 18;
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10151470
// Name: void CollisionBSPData_LoadLeafs_Version_0(class CCollisionBSPData __near *,class CMapLoadHelper __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadLeafs_Version_0(CCollisionBSPData *pBSPData, CMapLoadHelper *lh)
{
  signed __int32 v2; // edi
  const char *LoadName; // eax
  const char *v5; // eax
  cleaf_t *v6; // eax
  int v7; // edx
  int v8; // eax
  $7CA033D54BBC683D0ECF5D922201D02D *v9; // ecx
  cleaf_t *v10; // eax
  int cluster; // eax
  bool v12; // zf
  int numleafs; // eax
  cleaf_t *v14; // eax
  dleaf_version_0_t *in; // [esp+Ch] [ebp-4h]
  dleaf_version_0_t *ina; // [esp+Ch] [ebp-4h]
  int allcontents; // [esp+18h] [ebp+8h]

  in = (dleaf_version_0_t *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)lh);
  if ( CCircularBuffer::GetReadAvailable(this: (netadr_s *)lh) % 0x38u != 0 )
    Sys_Error(error: "CollisionBSPData_LoadLeafs: funny lump size");
  v2 = CCircularBuffer::GetReadAvailable(this: (netadr_s *)lh) / 0x38u;
  if ( v2 == 0 )
    Sys_Error(error: "Map with no leafs");
  if ( v2 > 0x10000 )
    Sys_Error(error: "Map has too many planes");
  LoadName = CMapLoadHelper::GetLoadName(this: lh);
  v5 = va(format: "%s [%s]", LoadName, "Leafs");
  v6 = (cleaf_t *)Hunk_AllocName(size: 16 * (v2 + 1), name: v5, bClear: true);
  v7 = 0;
  pBSPData->map_leafs.m_pArray = v6;
  v8 = 0;
  pBSPData->numleafs = v2;
  pBSPData->numclusters = 0;
  allcontents = 0;
  if ( v2 > 0 )
  {
    v9 = ($7CA033D54BBC683D0ECF5D922201D02D *)&in->___u2;
    ina = (dleaf_version_0_t *)v2;
    do
    {
      v10 = &pBSPData->map_leafs.m_pArray[v7];
      v10->contents = *(_DWORD *)&v9[-3];
      v10->cluster = (__int16)v9[-1];
      *((_WORD *)v10 + 3) ^= (*((_WORD *)v10 + 3) ^ *(_WORD *)v9) & 0x1FF;
      *((_WORD *)v10 + 3) = *(_WORD *)v9 ^ (*((_WORD *)v10 + 3) ^ *(_WORD *)v9) & 0x1FF;
      v10->firstleafbrush = (unsigned __int16)v9[9];
      v10->numleafbrushes = (unsigned __int16)v9[10];
      v10->dispCount = 0;
      cluster = v10->cluster;
      if ( cluster >= pBSPData->numclusters )
        pBSPData->numclusters = cluster + 1;
      v8 = *(_DWORD *)&v9[-3] | allcontents;
      ++v7;
      v9 += 28;
      v12 = ina == (dleaf_version_0_t *)1;
      ina = (dleaf_version_0_t *)((char *)ina - 1);
      allcontents = v8;
    }
    while ( !v12 );
  }
  pBSPData->allcontents = v8;
  if ( pBSPData->map_leafs.m_pArray->contents != 1 )
    Sys_Error(error: "Map leaf 0 is not CONTENTS_SOLID");
  numleafs = pBSPData->numleafs;
  pBSPData->emptyleaf = numleafs;
  v14 = &pBSPData->map_leafs.m_pArray[numleafs];
  pBSPData->solidleaf = 0;
  v14->contents = 0;
  *(_DWORD *)&v14->cluster = 0;
  *(_DWORD *)&v14->firstleafbrush = 0;
  *(_DWORD *)&v14->dispListStart = 0;
  ++pBSPData->numleafs;
}

//------------------------------------------------------------------------------
// Address: 0x10151620
// Name: void CollisionBSPData_LoadLeafs_Version_1(class CCollisionBSPData __near *,class CMapLoadHelper __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadLeafs_Version_1(CCollisionBSPData *pBSPData, CMapLoadHelper *lh)
{
  signed int v2; // edi
  const char *LoadName; // eax
  const char *v5; // eax
  cleaf_t *v6; // eax
  int v7; // edx
  int v8; // eax
  $7CA033D54BBC683D0ECF5D922201D02D *v9; // ecx
  cleaf_t *v10; // eax
  int cluster; // eax
  bool v12; // zf
  cleaf_t *m_pArray; // ecx
  int numleafs; // eax
  cleaf_t *v15; // eax
  dleaf_t *in; // [esp+Ch] [ebp-4h]
  dleaf_t *ina; // [esp+Ch] [ebp-4h]
  int allcontents; // [esp+18h] [ebp+8h]

  in = (dleaf_t *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)lh);
  if ( (CCircularBuffer::GetReadAvailable(this: (netadr_s *)lh) & 0x1F) != 0 )
    Sys_Error(error: "CollisionBSPData_LoadLeafs: funny lump size");
  v2 = (unsigned int)CCircularBuffer::GetReadAvailable(this: (netadr_s *)lh) >> 5;
  if ( v2 == 0 )
    Sys_Error(error: "Map with no leafs");
  if ( v2 > 0x10000 )
    Sys_Error(error: "Map has too many planes");
  LoadName = CMapLoadHelper::GetLoadName(this: lh);
  v5 = va(format: "%s [%s]", LoadName, "Leafs");
  v6 = (cleaf_t *)Hunk_AllocName(size: 16 * (v2 + 1), name: v5, bClear: true);
  v7 = 0;
  pBSPData->map_leafs.m_pArray = v6;
  v8 = 0;
  pBSPData->numleafs = v2;
  pBSPData->numclusters = 0;
  allcontents = 0;
  if ( v2 > 0 )
  {
    v9 = ($7CA033D54BBC683D0ECF5D922201D02D *)&in->___u2;
    ina = (dleaf_t *)v2;
    do
    {
      v10 = &pBSPData->map_leafs.m_pArray[v7];
      v10->contents = *(_DWORD *)&v9[-3];
      v10->cluster = (__int16)v9[-1];
      *((_WORD *)v10 + 3) ^= (*((_WORD *)v10 + 3) ^ *(_WORD *)v9) & 0x1FF;
      *((_WORD *)v10 + 3) = *(_WORD *)v9 ^ (*((_WORD *)v10 + 3) ^ *(_WORD *)v9) & 0x1FF;
      v10->firstleafbrush = (unsigned __int16)v9[9];
      v10->numleafbrushes = (unsigned __int16)v9[10];
      v10->dispCount = 0;
      cluster = v10->cluster;
      if ( cluster >= pBSPData->numclusters )
        pBSPData->numclusters = cluster + 1;
      v8 = *(_DWORD *)&v9[-3] | allcontents;
      ++v7;
      v9 += 16;
      v12 = ina == (dleaf_t *)1;
      ina = (dleaf_t *)((char *)ina - 1);
      allcontents = v8;
    }
    while ( !v12 );
  }
  m_pArray = pBSPData->map_leafs.m_pArray;
  pBSPData->allcontents = v8;
  if ( m_pArray->contents != 1 )
    Sys_Error(error: "Map leaf 0 is not CONTENTS_SOLID");
  numleafs = pBSPData->numleafs;
  pBSPData->emptyleaf = numleafs;
  v15 = &pBSPData->map_leafs.m_pArray[numleafs];
  pBSPData->solidleaf = 0;
  v15->contents = 0;
  *(_DWORD *)&v15->cluster = 0;
  *(_DWORD *)&v15->firstleafbrush = 0;
  *(_DWORD *)&v15->dispListStart = 0;
  ++pBSPData->numleafs;
}

//------------------------------------------------------------------------------
// Address: 0x101517C0
// Name: void CollisionBSPData_LoadLeafs(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadLeafs(CCollisionBSPData *pBSPData)
{
  INetChannel *State; // eax
  CMapLoadHelper lh; // [esp+4h] [ebp-128h] BYREF

  pBSPData->allcontents = -1;
  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 10, bUncompress: true);
  State = CEngine::GetState(this: (CNetMessage *)&lh);
  if ( State != nullptr )
  {
    if ( State == (INetChannel *)1 )
      CollisionBSPData_LoadLeafs_Version_1(pBSPData, &lh);
    else
      _Error(a1: "Unknown LUMP_LEAFS version\n");
    CMapLoadHelper::~CMapLoadHelper(this: &lh);
  }
  else
  {
    CollisionBSPData_LoadLeafs_Version_0(pBSPData, &lh);
    CMapLoadHelper::~CMapLoadHelper(this: &lh);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10151860
// Name: void CollisionBSPData_LoadLeafBrushes(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadLeafBrushes(CCollisionBSPData *pBSPData)
{
  unsigned __int16 *SamplePosition; // edi
  signed int v2; // esi
  const char *LoadName; // eax
  const char *v4; // eax
  signed int v5; // eax
  CMapLoadHelper lh; // [esp+Ch] [ebp-128h] BYREF

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 17, bUncompress: true);
  SamplePosition = (unsigned __int16 *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&lh);
  if ( (CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) & 1) != 0 )
    Sys_Error(error: "CMod_LoadLeafBrushes: funny lump size");
  v2 = (unsigned int)CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) >> 1;
  if ( v2 == 0 )
    Sys_Error(error: "Map with no planes");
  if ( v2 > 0x10000 )
    Sys_Error(error: "Map has too many leafbrushes");
  LoadName = CMapLoadHelper::GetLoadName(this: &lh);
  v4 = va(format: "%s [%s]", LoadName, "LeafBrushes");
  pBSPData->map_leafbrushes.m_pArray = (unsigned __int16 *)Hunk_AllocName(size: 2 * v2, name: v4, bClear: false);
  v5 = 0;
  for ( pBSPData->numleafbrushes = v2; v5 < v2; ++SamplePosition )
    pBSPData->map_leafbrushes.m_pArray[v5++] = *SamplePosition;
  CMapLoadHelper::~CMapLoadHelper(this: &lh);
}

//------------------------------------------------------------------------------
// Address: 0x10151950
// Name: void CollisionBSPData_LoadPlanes(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadPlanes(CCollisionBSPData *pBSPData)
{
  int SamplePosition; // esi
  int v2; // edi
  CCollisionBSPData *v3; // ebx
  const char *LoadName; // eax
  const char *v5; // eax
  int v6; // eax
  cplane_t *v7; // eax
  float v8; // xmm1_4
  unsigned __int8 v9; // cl
  float v10; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  cplane_t *v13; // eax
  unsigned __int8 v14; // cl
  float v15; // xmm1_4
  float v16; // xmm1_4
  unsigned int v17; // edi
  float v18; // xmm1_4
  unsigned int v19; // edi
  float *v20; // eax
  char v21; // cl
  float v22; // xmm1_4
  float v23; // xmm1_4
  float v24; // xmm1_4
  float *v25; // eax
  char v26; // cl
  float v27; // xmm1_4
  float v28; // xmm1_4
  double v29; // st7
  char v30; // dl
  bool v31; // zf
  float *v32; // ecx
  int v33; // esi
  int v34; // edi
  float v35; // xmm1_4
  cplane_t *v36; // eax
  unsigned __int8 v37; // dl
  float v38; // xmm1_4
  float v39; // xmm1_4
  double v40; // st7
  CMapLoadHelper lh; // [esp+Ch] [ebp-138h] BYREF
  int i; // [esp+134h] [ebp-10h]
  int count; // [esp+138h] [ebp-Ch]
  unsigned int v44; // [esp+13Ch] [ebp-8h]
  unsigned int v45; // [esp+140h] [ebp-4h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 1, bUncompress: true);
  SamplePosition = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&lh);
  if ( CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) % 0x14u != 0 )
    Sys_Error(error: "CollisionBSPData_LoadPlanes: funny lump size");
  v2 = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) / 0x14u;
  count = v2;
  if ( v2 == 0 )
    Sys_Error(error: "Map with no planes");
  if ( v2 > 0x10000 )
    Sys_Error(error: "Map has too many planes");
  v3 = pBSPData;
  LoadName = CMapLoadHelper::GetLoadName(this: &lh);
  v5 = va(format: "%s [%s]", LoadName, "Planes");
  pBSPData->map_planes.m_pArray = (cplane_t *)Hunk_AllocName(size: 20 * v2, name: v5, bClear: true);
  v6 = 0;
  pBSPData->numplanes = v2;
  if ( v2 >= 4 )
  {
    v45 = 0;
    v44 = ((unsigned int)(v2 - 4) >> 2) + 1;
    i = 4 * v44;
    do
    {
      v7 = &pBSPData->map_planes.m_pArray[v45 / 0x14];
      v8 = *(float *)SamplePosition;
      v7->normal.x = *(float *)SamplePosition;
      v9 = v8 < 0.0;
      v10 = *(float *)(SamplePosition + 4);
      v7->normal.y = v10;
      if ( v10 < 0.0 )
        v9 |= 2u;
      v11 = *(float *)(SamplePosition + 8);
      v7->normal.z = v11;
      if ( v11 < 0.0 )
        v9 |= 4u;
      v7->dist = *(float *)(SamplePosition + 12);
      v7->type = *(_BYTE *)(SamplePosition + 16);
      v7->signbits = v9;
      v12 = *(float *)(SamplePosition + 20);
      v13 = &pBSPData->map_planes.m_pArray[v45 / 0x14 + 1];
      v13->normal.x = v12;
      v14 = v12 < 0.0;
      v15 = *(float *)(SamplePosition + 24);
      v13->normal.y = v15;
      if ( v15 < 0.0 )
        v14 |= 2u;
      v16 = *(float *)(SamplePosition + 28);
      v13->normal.z = v16;
      if ( v16 < 0.0 )
        v14 |= 4u;
      v17 = v45;
      v13->dist = *(float *)(SamplePosition + 32);
      v13->type = *(_BYTE *)(SamplePosition + 36);
      v13->signbits = v14;
      v18 = *(float *)(SamplePosition + 40);
      v19 = v17 + 60;
      v20 = (float *)((char *)&pBSPData->map_planes.m_pArray[-1].normal.x + v19);
      *v20 = v18;
      v21 = v18 < 0.0;
      v22 = *(float *)(SamplePosition + 44);
      v20[1] = v22;
      if ( v22 < 0.0 )
        v21 |= 2u;
      v23 = *(float *)(SamplePosition + 48);
      v20[2] = v23;
      if ( v23 < 0.0 )
        v21 |= 4u;
      v20[3] = *(float *)(SamplePosition + 52);
      *((_BYTE *)v20 + 16) = *(_BYTE *)(SamplePosition + 56);
      *((_BYTE *)v20 + 17) = v21;
      v24 = *(float *)(SamplePosition + 60);
      v25 = (float *)((char *)&pBSPData->map_planes.m_pArray->normal.x + v19);
      *v25 = v24;
      v26 = v24 < 0.0;
      v27 = *(float *)(SamplePosition + 64);
      v25[1] = v27;
      if ( v27 < 0.0 )
        v26 |= 2u;
      v28 = *(float *)(SamplePosition + 68);
      v25[2] = v28;
      if ( v28 < 0.0 )
        v26 |= 4u;
      v29 = *(float *)(SamplePosition + 72);
      v45 += 80;
      v25[3] = v29;
      v30 = *(_BYTE *)(SamplePosition + 76);
      SamplePosition += 80;
      v31 = v44-- == 1;
      *((_BYTE *)v25 + 16) = v30;
      *((_BYTE *)v25 + 17) = v26;
    }
    while ( !v31 );
    v2 = count;
    v6 = i;
  }
  if ( v6 < v2 )
  {
    v32 = (float *)(SamplePosition + 8);
    v33 = v6;
    v34 = v2 - v6;
    while ( 1 )
    {
      v35 = *(v32 - 2);
      v36 = &v3->map_planes.m_pArray[v33];
      v36->normal.x = v35;
      v37 = v35 < 0.0;
      v38 = *(v32 - 1);
      v36->normal.y = v38;
      if ( v38 < 0.0 )
        v37 |= 2u;
      v39 = *v32;
      v36->normal.z = *v32;
      if ( v39 < 0.0 )
        v37 |= 4u;
      v40 = v32[1];
      v32 += 5;
      v36->dist = v40;
      ++v33;
      --v34;
      v36->type = *((_BYTE *)v32 - 12);
      v36->signbits = v37;
      if ( v34 == 0 )
        break;
      v3 = pBSPData;
    }
  }
  CMapLoadHelper::~CMapLoadHelper(this: &lh);
}

//------------------------------------------------------------------------------
// Address: 0x10151C20
// Name: void CollisionBSPData_LoadBrushes(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadBrushes(CCollisionBSPData *pBSPData)
{
  int SamplePosition; // ebx
  signed __int32 v2; // esi
  const char *LoadName; // eax
  const char *v4; // eax
  cbrush_t *v5; // eax
  signed __int32 v6; // edx
  _DWORD *v7; // eax
  cbrush_t *v8; // ecx
  int v9; // ebx
  CMapLoadHelper lh; // [esp+Ch] [ebp-128h] BYREF

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 18, bUncompress: true);
  SamplePosition = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&lh);
  if ( CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) % 0xCu != 0 )
    Sys_Error(error: "CMod_LoadBrushes: funny lump size");
  v2 = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) / 0xCu;
  if ( (unsigned int)v2 > 0x2000 )
    Sys_Error(error: "Map has too many brushes");
  LoadName = CMapLoadHelper::GetLoadName(this: &lh);
  v4 = va(format: "%s [%s]", LoadName, "Brushes");
  v5 = (cbrush_t *)Hunk_AllocName(size: 8 * v2, name: v4, bClear: true);
  v6 = 0;
  pBSPData->map_brushes.m_pArray = v5;
  pBSPData->numbrushes = v2;
  if ( v2 > 0 )
  {
    v7 = (_DWORD *)(SamplePosition + 8);
    do
    {
      v8 = &pBSPData->map_brushes.m_pArray[v6];
      v8->firstbrushside = *((_WORD *)v7 - 4);
      v8->numsides = *((_WORD *)v7 - 2);
      v9 = *v7;
      ++v6;
      v7 += 3;
      v8->contents = v9;
    }
    while ( v6 < v2 );
  }
  CMapLoadHelper::~CMapLoadHelper(this: &lh);
}

//------------------------------------------------------------------------------
// Address: 0x10151D30
// Name: void CollisionBSPData_LoadBrushSides(class CCollisionBSPData __near *,struct texinfo_s __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadBrushSides(CCollisionBSPData *pBSPData, texinfo_s *pTexinfo, int texinfoCount)
{
  int v4; // eax
  int v5; // esi
  int v6; // edi
  cbrush_t *v7; // edx
  int v8; // eax
  dbrushside_t *v9; // ecx
  const char *LoadName; // eax
  const char *v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  cboxbrush_t *v14; // eax
  int v15; // esi
  cbrush_t *m_pArray; // edx
  unsigned __int16 numsides; // ax
  cbrush_t *v18; // edi
  int v19; // eax
  int firstbrushside; // ecx
  unsigned __int8 *p_bevel; // esi
  cbrushside_t *v22; // edi
  int v23; // eax
  int v24; // eax
  int texdata; // eax
  unsigned __int8 v26; // dl
  cbrush_t *v27; // ecx
  int v28; // eax
  int v29; // edx
  CMapLoadHelper lh; // [esp+0h] [ebp-140h] BYREF
  cbrush_t *pBrush; // [esp+128h] [ebp-18h]
  int j; // [esp+12Ch] [ebp-14h]
  dbrushside_t *in; // [esp+130h] [ebp-10h]
  int i; // [esp+134h] [ebp-Ch]
  int outBoxBrush; // [esp+138h] [ebp-8h]
  int brushSideCount; // [esp+13Ch] [ebp-4h]
  int outBrushSide; // [esp+148h] [ebp+8h]
  int outBrushSidea; // [esp+148h] [ebp+8h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 19, bUncompress: true);
  in = (dbrushside_t *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&lh);
  if ( (CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) & 7) != 0 )
    Sys_Error(error: "CMod_LoadBrushSides: funny lump size");
  if ( (unsigned int)CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) >> 3 > 0x10000 )
    Sys_Error(error: "Map has too many planes");
  v4 = 0;
  v5 = 0;
  v6 = 0;
  outBoxBrush = 0;
  brushSideCount = 0;
  i = 0;
  if ( pBSPData->numbrushes > 0 )
  {
    do
    {
      v7 = &pBSPData->map_brushes.m_pArray[v4];
      outBrushSide = 0;
      if ( v7->numsides == 6 )
      {
        v8 = 0;
        v9 = &in[v7->firstbrushside];
        do
        {
          if ( pBSPData->map_planes.m_pArray[v9->planenum].type > 2u )
            break;
          ++outBrushSide;
          ++v8;
          ++v9;
        }
        while ( v8 < 6 );
      }
      if ( outBrushSide == v7->numsides )
      {
        ++outBoxBrush;
        v7->numsides = -1;
      }
      else
      {
        brushSideCount += v7->numsides;
      }
      v4 = i + 1;
      i = v4;
    }
    while ( v4 < pBSPData->numbrushes );
    v5 = outBoxBrush;
    v6 = brushSideCount;
  }
  LoadName = CMapLoadHelper::GetLoadName(this: &lh);
  v11 = va(format: "%s [%s]", LoadName, "BrushSides");
  pBSPData->map_brushsides.m_pArray = (cbrushside_t *)Hunk_AllocName(size: 8 * v6, name: v11, bClear: false);
  v12 = CMapLoadHelper::GetLoadName(this: &lh);
  v13 = va(format: "%s [%s]", v12, "BrushSides");
  v14 = (cboxbrush_t *)Hunk_AllocName(size: 48 * v5, name: v13, bClear: false);
  pBSPData->numboxbrushes = v5;
  v15 = 0;
  pBSPData->map_boxbrushes.m_pArray = v14;
  pBSPData->numbrushsides = v6;
  outBoxBrush = 0;
  outBrushSidea = 0;
  i = 0;
  if ( pBSPData->numbrushes > 0 )
  {
    brushSideCount = 0;
    do
    {
      m_pArray = pBSPData->map_brushes.m_pArray;
      numsides = m_pArray[v15].numsides;
      v18 = &m_pArray[v15];
      pBrush = v18;
      if ( numsides == 0xFFFF )
      {
        ExtractBoxBrush(
          pBox: (cplane_t *)((char *)pBSPData->map_boxbrushes.m_pArray + brushSideCount),
          brush: v18,
          pSides: in,
          pPlanes: pBSPData->map_planes.m_pArray,
          pTexinfo);
        v19 = outBoxBrush;
        v18->firstbrushside = outBoxBrush;
        brushSideCount += 48;
        v18->numsides = -1;
        outBoxBrush = v19 + 1;
      }
      else
      {
        firstbrushside = v18->firstbrushside;
        v18->firstbrushside = outBrushSidea;
        j = 0;
        if ( numsides != 0 )
        {
          p_bevel = &in[firstbrushside].bevel;
          do
          {
            v22 = &pBSPData->map_brushsides.m_pArray[outBrushSidea];
            v23 = *((__int16 *)p_bevel - 2);
            v22->plane = &pBSPData->map_planes.m_pArray[*((unsigned __int16 *)p_bevel - 3)];
            if ( v23 >= texinfoCount )
              Sys_Error(error: "Bad brushside texinfo");
            v24 = *((__int16 *)p_bevel - 2);
            if ( v24 >= 0 )
              texdata = pTexinfo[v24].texdata;
            else
              LOWORD(texdata) = -1;
            v26 = *p_bevel;
            v27 = pBrush;
            ++outBrushSidea;
            v22->surfaceIndex = texdata;
            v22->bThin = p_bevel[1];
            v28 = j;
            v22->bBevel = v26;
            v29 = v27->numsides;
            p_bevel += 8;
            j = v28 + 1;
          }
          while ( v28 + 1 < v29 );
          v15 = i;
        }
      }
      i = ++v15;
    }
    while ( v15 < pBSPData->numbrushes );
  }
  CMapLoadHelper::~CMapLoadHelper(this: &lh);
}

//------------------------------------------------------------------------------
// Address: 0x10151FE0
// Name: void CollisionBSPData_LoadSubmodels(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadSubmodels(CCollisionBSPData *pBSPData)
{
  int SamplePosition; // esi
  int v2; // ebx
  const char *LoadName; // eax
  const char *v5; // eax
  int v6; // eax
  int v7; // ecx
  cmodel_t *m_pArray; // eax
  cmodel_t *v9; // eax
  cmodel_t *v10; // eax
  int v11; // eax
  cmodel_t *v12; // eax
  int v13; // eax
  double v14; // st7
  cmodel_t *v15; // eax
  bool v16; // zf
  int v17; // edx
  int v18; // ecx
  int v19; // ebx
  cmodel_t *v20; // eax
  int v21; // esi
  CMapLoadHelper lh; // [esp+Ch] [ebp-130h] BYREF
  int i; // [esp+134h] [ebp-8h]
  int count; // [esp+138h] [ebp-4h]
  CCollisionBSPData *pBSPDataa; // [esp+144h] [ebp+8h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 14, bUncompress: true);
  SamplePosition = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&lh);
  if ( CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) % 0x30u != 0 )
    Sys_Error(error: "CMod_LoadSubmodels: funny lump size");
  v2 = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) / 0x30u;
  count = v2;
  if ( v2 == 0 )
    Sys_Error(error: "Map with no models");
  if ( v2 > 1024 )
    Sys_Error(error: "Map has too many models");
  LoadName = CMapLoadHelper::GetLoadName(this: &lh);
  v5 = va(format: "%s [%s]", LoadName, "Submodels");
  pBSPData->map_cmodels.m_pArray = (cmodel_t *)Hunk_AllocName(size: 56 * v2, name: v5, bClear: true);
  v6 = 0;
  pBSPData->numcmodels = v2;
  if ( v2 >= 4 )
  {
    v7 = 0;
    pBSPDataa = (CCollisionBSPData *)(((unsigned int)(v2 - 4) >> 2) + 1);
    i = 4 * (_DWORD)pBSPDataa;
    do
    {
      m_pArray = pBSPData->map_cmodels.m_pArray;
      m_pArray[v7].mins.x = *(float *)SamplePosition - 1.0;
      m_pArray[v7].maxs.x = *(float *)(SamplePosition + 12) + 1.0;
      m_pArray[v7].origin.x = *(float *)(SamplePosition + 24);
      m_pArray[v7].mins.y = *(float *)(SamplePosition + 4) - 1.0;
      m_pArray[v7].maxs.y = *(float *)(SamplePosition + 16) + 1.0;
      m_pArray[v7].origin.y = *(float *)(SamplePosition + 28);
      v9 = &m_pArray[v7];
      v9->mins.z = *(float *)(SamplePosition + 8) - 1.0;
      v9->maxs.z = *(float *)(SamplePosition + 20) + 1.0;
      v9->origin.z = *(float *)(SamplePosition + 32);
      v9->headnode = *(_DWORD *)(SamplePosition + 36);
      v10 = pBSPData->map_cmodels.m_pArray;
      v10[v7 + 1].mins.x = *(float *)(SamplePosition + 48) - 1.0;
      v10[v7 + 1].maxs.x = *(float *)(SamplePosition + 60) + 1.0;
      v10[v7 + 1].origin.x = *(float *)(SamplePosition + 72);
      v11 = (int)&v10[v7 + 1];
      *(float *)(v11 + 4) = *(float *)(SamplePosition + 52) - 1.0;
      *(float *)(v11 + 16) = *(float *)(SamplePosition + 64) + 1.0;
      *(float *)(v11 + 28) = *(float *)(SamplePosition + 76);
      *(float *)(v11 + 8) = *(float *)(SamplePosition + 56) - 1.0;
      *(float *)(v11 + 20) = *(float *)(SamplePosition + 68) + 1.0;
      *(float *)(v11 + 32) = *(float *)(SamplePosition + 80);
      *(_DWORD *)(v11 + 36) = *(_DWORD *)(SamplePosition + 84);
      v12 = pBSPData->map_cmodels.m_pArray;
      v12[v7 + 2].mins.x = *(float *)(SamplePosition + 96) - 1.0;
      v13 = (int)&v12[v7 + 2];
      *(float *)(v13 + 12) = *(float *)(SamplePosition + 108) + 1.0;
      *(float *)(v13 + 24) = *(float *)(SamplePosition + 120);
      *(float *)(v13 + 4) = *(float *)(SamplePosition + 100) - 1.0;
      *(float *)(v13 + 16) = *(float *)(SamplePosition + 112) + 1.0;
      *(float *)(v13 + 28) = *(float *)(SamplePosition + 124);
      *(float *)(v13 + 8) = *(float *)(SamplePosition + 104) - 1.0;
      *(float *)(v13 + 20) = *(float *)(SamplePosition + 116) + 1.0;
      v14 = *(float *)(SamplePosition + 128);
      SamplePosition += 192;
      *(float *)(v13 + 32) = v14;
      *(_DWORD *)(v13 + 36) = *(_DWORD *)(SamplePosition - 60);
      v15 = &pBSPData->map_cmodels.m_pArray[v7 + 3];
      v15->mins.x = *(float *)(SamplePosition - 48) - 1.0;
      v15->maxs.x = *(float *)(SamplePosition - 36) + 1.0;
      v15->origin.x = *(float *)(SamplePosition - 24);
      v15->mins.y = *(float *)(SamplePosition - 44) - 1.0;
      v15->maxs.y = *(float *)(SamplePosition - 32) + 1.0;
      v15->origin.y = *(float *)(SamplePosition - 20);
      v15->mins.z = *(float *)(SamplePosition - 40) - 1.0;
      v15->maxs.z = *(float *)(SamplePosition - 28) + 1.0;
      v15->origin.z = *(float *)(SamplePosition - 16);
      v7 += 4;
      v16 = pBSPDataa == (CCollisionBSPData *)1;
      pBSPDataa = (CCollisionBSPData *)((char *)pBSPDataa - 1);
      v15->headnode = *(_DWORD *)(SamplePosition - 12);
    }
    while ( !v16 );
    v6 = i;
    v2 = count;
  }
  if ( v6 < v2 )
  {
    v17 = v6;
    v18 = SamplePosition + 24;
    v19 = v2 - v6;
    do
    {
      v20 = &pBSPData->map_cmodels.m_pArray[v17];
      v20->mins.x = *(float *)(v18 - 24) - 1.0;
      v20->maxs.x = *(float *)(v18 - 12) + 1.0;
      v20->origin.x = *(float *)v18;
      v20->mins.y = *(float *)(v18 - 20) - 1.0;
      v20->maxs.y = *(float *)(v18 - 8) + 1.0;
      v20->origin.y = *(float *)(v18 + 4);
      v20->mins.z = *(float *)(v18 - 16) - 1.0;
      v20->maxs.z = *(float *)(v18 - 4) + 1.0;
      v20->origin.z = *(float *)(v18 + 8);
      v21 = *(_DWORD *)(v18 + 12);
      v18 += 48;
      ++v17;
      --v19;
      v20->headnode = v21;
    }
    while ( v19 != 0 );
  }
  CMapLoadHelper::~CMapLoadHelper(this: &lh);
}

//------------------------------------------------------------------------------
// Address: 0x10152390
// Name: void CollisionBSPData_LoadNodes(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadNodes(CCollisionBSPData *pBSPData)
{
  int SamplePosition; // edi
  signed int v2; // ebx
  const char *LoadName; // eax
  const char *v4; // eax
  cnode_t *v5; // eax
  int *v7; // ecx
  int v8; // edi
  cnode_t *m_pArray; // eax
  CMapLoadHelper lh; // [esp+Ch] [ebp-128h] BYREF
  CCollisionBSPData *pBSPDataa; // [esp+13Ch] [ebp+8h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 5, bUncompress: true);
  SamplePosition = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&lh);
  if ( (CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) & 0x1F) != 0 )
    Sys_Error(error: "CollisionBSPData_LoadNodes: funny lump size");
  v2 = (unsigned int)CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) >> 5;
  if ( v2 == 0 )
    Sys_Error(error: "Map has no nodes");
  if ( v2 > 0x10000 )
    Sys_Error(error: "Map has too many nodes");
  LoadName = CMapLoadHelper::GetLoadName(this: &lh);
  v4 = va(format: "%s [%s]", LoadName, "Nodes");
  v5 = (cnode_t *)Hunk_AllocName(size: 4 * (3 * v2 + 18), name: v4, bClear: true);
  pBSPData->map_nodes.m_pArray = v5;
  pBSPData->numnodes = v2;
  pBSPData->map_rootnode = v5;
  if ( v2 > 0 )
  {
    v7 = (int *)(SamplePosition + 8);
    v8 = 0;
    for ( pBSPDataa = (CCollisionBSPData *)v2;
          pBSPDataa != nullptr;
          pBSPDataa = (CCollisionBSPData *)((char *)pBSPDataa - 1) )
    {
      m_pArray = pBSPData->map_nodes.m_pArray;
      m_pArray[v8].plane = &pBSPData->map_planes.m_pArray[*(v7 - 2)];
      m_pArray[v8].children[0] = *(v7 - 1);
      m_pArray[v8++].children[1] = *v7;
      v7 += 8;
    }
  }
  CMapLoadHelper::~CMapLoadHelper(this: &lh);
}

//------------------------------------------------------------------------------
// Address: 0x101524A0
// Name: void CollisionBSPData_LoadAreas(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadAreas(CCollisionBSPData *pBSPData)
{
  int *SamplePosition; // esi
  signed int v2; // ebx
  const char *LoadName; // eax
  const char *v4; // eax
  int v5; // ecx
  signed int i; // edx
  carea_t *v7; // eax
  CMapLoadHelper lh; // [esp+Ch] [ebp-128h] BYREF

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 20, bUncompress: true);
  SamplePosition = (int *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&lh);
  if ( (CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) & 7) != 0 )
    Sys_Error(error: "CMod_LoadAreas: funny lump size");
  v2 = (unsigned int)CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) >> 3;
  if ( (unsigned int)v2 > 0x100 )
    Sys_Error(error: "Map has too many areas");
  LoadName = CMapLoadHelper::GetLoadName(this: &lh);
  v4 = va(format: "%s [%s]", LoadName, "Areas");
  pBSPData->map_areas.m_pArray = (carea_t *)Hunk_AllocName(size: 16 * v2, name: v4, bClear: true);
  pBSPData->numareas = v2;
  if ( v2 > 0 )
  {
    v5 = 0;
    for ( i = v2; i != 0; --i )
    {
      v7 = &pBSPData->map_areas.m_pArray[v5];
      v7->numareaportals = *SamplePosition;
      v7->firstareaportal = SamplePosition[1];
      ++v5;
      SamplePosition += 2;
      v7->floodvalid = 0;
      v7->floodnum = 0;
    }
  }
  CMapLoadHelper::~CMapLoadHelper(this: &lh);
}

//------------------------------------------------------------------------------
// Address: 0x10152590
// Name: void CollisionBSPData_LoadAreaPortals(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadAreaPortals(CCollisionBSPData *pBSPData)
{
  unsigned __int8 *SamplePosition; // ebx
  unsigned __int32 v2; // edi
  int v3; // edi
  const char *LoadName; // eax
  const char *v5; // eax
  int i; // eax
  const char *v7; // eax
  const char *v8; // eax
  dareaportal_t *v9; // edi
  netadrtype_t Available; // eax
  CMapLoadHelper lh; // [esp+Ch] [ebp-128h] BYREF

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 21, bUncompress: true);
  SamplePosition = (unsigned __int8 *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&lh);
  if ( CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) % 0xCu != 0 )
    Sys_Error(error: "CMod_LoadAreaPortals: funny lump size");
  v2 = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) / 0xCu;
  if ( v2 > 0x400 )
    Sys_Error(error: "Map has too many area portals");
  v3 = v2 + 1;
  pBSPData->numportalopen = v3;
  LoadName = CMapLoadHelper::GetLoadName(this: &lh);
  v5 = va(format: "%s [%s]", LoadName, "AreaPortals");
  pBSPData->portalopen.m_pArray = (bool *)Hunk_AllocName(size: pBSPData->numportalopen, name: v5, bClear: false);
  for ( i = 0; i < pBSPData->numportalopen; ++i )
    pBSPData->portalopen.m_pArray[i] = false;
  pBSPData->numareaportals = v3;
  v7 = CMapLoadHelper::GetLoadName(this: &lh);
  v8 = va(format: "%s [%s]", v7, "AreaPortals");
  v9 = (dareaportal_t *)Hunk_AllocName(size: 12 * v3, name: v8, bClear: true);
  pBSPData->map_areaportals.m_pArray = v9;
  Available = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh);
  memcpy(dst: (unsigned __int8 *)v9, src: SamplePosition, count: Available);
  CMapLoadHelper::~CMapLoadHelper(this: &lh);
}

//------------------------------------------------------------------------------
// Address: 0x101526D0
// Name: void CollisionBSPData_LoadPhysics(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadPhysics(CCollisionBSPData *pBSPData)
{
  int SamplePosition; // esi
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  int v5; // ecx
  int v6; // edi
  netadrtype_t Available; // eax
  CMapLoadHelper lh; // [esp+0h] [ebp-12Ch] BYREF
  unsigned __int8 *basePtr; // [esp+128h] [ebp-4h]

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 29, bUncompress: true);
  if ( CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh) != NA_NULL )
  {
    SamplePosition = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&lh);
    basePtr = (unsigned __int8 *)SamplePosition;
    do
    {
      v2 = *(_DWORD *)(SamplePosition + 4);
      v3 = *(_DWORD *)SamplePosition;
      v4 = *(_DWORD *)(SamplePosition + 8);
      v5 = *(_DWORD *)(SamplePosition + 12);
      SamplePosition += 16;
      if ( v2 > 0 )
      {
        v6 = v2 + v4;
        physcollision->VCollideLoad(
          this: physcollision,
          a2: &pBSPData->map_cmodels.m_pArray[v3].vcollisionData,
          a3: v5,
          a4: (const char *)SamplePosition,
          a5: v6,
          a6: false);
        SamplePosition += v6;
      }
      Available = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh);
    }
    while ( SamplePosition - (int)basePtr <= Available && v2 > 0 );
  }
  CMapLoadHelper::~CMapLoadHelper(this: &lh);
}

//------------------------------------------------------------------------------
// Address: 0x10152790
// Name: void CollisionBSPData_LoadDispInfo(class CCollisionBSPData __near *,struct texinfo_s __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadDispInfo(CCollisionBSPData *pBSPData, texinfo_s *pTexinfo)
{
  signed __int32 v2; // esi
  int SamplePosition; // edi
  int v4; // ebx
  HDRType_t (__thiscall *GetHDRType)(IMaterialSystemHardwareConfig *); // eax
  bool v6; // cc
  int v7; // eax
  const char *LoadName; // eax
  const char *v9; // eax
  void *v10; // esp
  signed __int32 v11; // eax
  __int16 v12; // cx
  int v13; // ecx
  int v14; // esi
  int v15; // esi
  _WORD *v16; // ecx
  __int16 v17; // ax
  int v18; // esi
  int v19; // edx
  int *v20; // edx
  float *v21; // eax
  int v22; // ecx
  int v23; // ecx
  int v24; // ecx
  double v25; // st7
  int v26; // ecx
  double v27; // st7
  int v28; // ecx
  int v29; // ecx
  int v30; // ecx
  double v31; // st7
  int v32; // ecx
  double v33; // st7
  int v34; // ecx
  int v35; // ecx
  int v36; // ecx
  double v37; // st7
  int v38; // ecx
  double v39; // st7
  int v40; // ecx
  int v41; // ecx
  int v42; // ecx
  double v43; // st7
  int v44; // ecx
  double v45; // st7
  bool v46; // zf
  float *v47; // eax
  int *v48; // edx
  int v49; // ecx
  int v50; // ecx
  int v51; // ecx
  double v52; // st7
  int v53; // ecx
  double v54; // st7
  CDispCollTree *v55; // esi
  char *v56; // eax
  int m_iCounter; // edx
  int m_nContents; // ecx
  float y; // xmm0_4
  float z; // xmm1_4
  float v61; // xmm0_4
  float v62; // xmm1_4
  int v63; // eax
  IMaterial *v64; // edi
  int v65; // eax
  int v66; // eax
  IPhysicsSurfaceProps_vtbl *v67; // edx
  int v68; // eax
  const char *v69; // eax
  dphysdisp_t *v70; // esi
  netadrtype_t Available; // eax
  unsigned __int8 smoothingAngle[12]; // [esp+14h] [ebp-2854h] BYREF
  CDispVert v73; // [esp+20h] [ebp-2848h] BYREF
  CDispTri v74; // [esp+16B4h] [ebp-11B4h] BYREF
  CMapLoadHelper v75; // [esp+1AB4h] [ebp-DB4h] BYREF
  CMapLoadHelper v76; // [esp+1BDCh] [ebp-C8Ch] BYREF
  CMapLoadHelper v77; // [esp+1D04h] [ebp-B64h] BYREF
  CMapLoadHelper v78; // [esp+1E2Ch] [ebp-A3Ch] BYREF
  CMapLoadHelper v79; // [esp+1F54h] [ebp-914h] BYREF
  netadr_s v80; // [esp+207Ch] [ebp-7ECh] BYREF
  CMapLoadHelper v81; // [esp+2090h] [ebp-7D8h] BYREF
  CMapLoadHelper v82; // [esp+21B8h] [ebp-6B0h] BYREF
  CMapLoadHelper v83; // [esp+22E0h] [ebp-588h] BYREF
  CCoreDispInfo v84; // [esp+2408h] [ebp-460h] BYREF
  int pData; // [esp+2754h] [ebp-114h]
  int v86; // [esp+2758h] [ebp-110h]
  float v87; // [esp+275Ch] [ebp-10Ch]
  int v88; // [esp+2760h] [ebp-108h]
  CCoreDispNode *v89; // [esp+27F0h] [ebp-78h]
  float v90; // [esp+27F4h] [ebp-74h]
  _DWORD v91[8]; // [esp+27F8h] [ebp-70h] BYREF
  _DWORD v92[5]; // [esp+2818h] [ebp-50h] BYREF
  _WORD *v93; // [esp+282Ch] [ebp-3Ch]
  int v94; // [esp+2830h] [ebp-38h]
  float *v95; // [esp+2834h] [ebp-34h]
  int v96; // [esp+2838h] [ebp-30h]
  signed __int32 v97; // [esp+283Ch] [ebp-2Ch]
  const char *v98; // [esp+2840h] [ebp-28h]
  int v99; // [esp+2844h] [ebp-24h]
  int v100; // [esp+2848h] [ebp-20h]
  int v101; // [esp+284Ch] [ebp-1Ch]
  unsigned int v102; // [esp+2850h] [ebp-18h]
  int v103; // [esp+2854h] [ebp-14h]
  signed __int32 v104; // [esp+2858h] [ebp-10h]
  unsigned int v105; // [esp+285Ch] [ebp-Ch]
  _WORD *v106; // [esp+2860h] [ebp-8h]
  _DWORD var18[2]; // [esp+2864h] [ebp-4h] BYREF

  CMapLoadHelper::CMapLoadHelper(this: (CMapLoadHelper *)&v82.m_szLumpFilename[240], lumpToLoad: 26, bUncompress: true);
  v2 = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&v82.m_szLumpFilename[240]) / 0xB0u;
  v97 = v2;
  if ( v2 != 0 )
  {
    CMapLoadHelper::CMapLoadHelper(this: &v79, lumpToLoad: 3, bUncompress: true);
    SamplePosition = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&v79);
    v94 = SamplePosition;
    if ( CCircularBuffer::GetReadAvailable(this: (netadr_s *)&v79) % 0xCu != 0 )
      Sys_Error(error: "CMod_LoadDispInfo: bad vertex lump size!");
    CMapLoadHelper::CMapLoadHelper(this: (CMapLoadHelper *)&v80, lumpToLoad: 12, bUncompress: true);
    v4 = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&v80);
    if ( (CCircularBuffer::GetReadAvailable(this: &v80) & 3) != 0 )
      Sys_Error(error: "CMod_LoadDispInfo: bad edge lump size!");
    CMapLoadHelper::CMapLoadHelper(this: &v78, lumpToLoad: 13, bUncompress: true);
    v96 = CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&v78);
    if ( (CCircularBuffer::GetReadAvailable(this: (netadr_s *)&v78) & 3) != 0 )
      Sys_Error(error: "CMod_LoadDispInfo: bad surf edge lump size!");
    GetHDRType = g_pMaterialSystemHardwareConfig->GetHDRType;
    v103 = 7;
    if ( GetHDRType(this: g_pMaterialSystemHardwareConfig) == HDR_TYPE_NONE
      || (v6 = CMapLoadHelper::LumpSize(lumpId: 58) <= 0, v7 = 58, v6) )
    {
      v7 = v103;
    }
    CMapLoadHelper::CMapLoadHelper(
      this: (CMapLoadHelper *)&v81.m_szLumpFilename[240],
      lumpToLoad: v7,
      bUncompress: true);
    v106 = (_WORD *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&v81.m_szLumpFilename[240]);
    if ( CCircularBuffer::GetReadAvailable(this: (netadr_s *)&v81.m_szLumpFilename[240]) % 0x38u != 0 )
      Sys_Error(error: "CMod_LoadDispInfo: bad face lump size!");
    v104 = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&v81.m_szLumpFilename[240]) / 0x38u;
    v93 = v106;
    if ( v106 != nullptr )
    {
      g_DispCollTreeCount = v2;
      g_pDispCollTrees = DispCollTrees_Alloc(count: v2);
      LoadName = CMapLoadHelper::GetLoadName(this: (CMapLoadHelper *)&v82.m_szLumpFilename[240]);
      v9 = va(format: "%s [%s]", LoadName, "DispInfo");
      g_pDispBounds = (alignedbbox_t *)Hunk_AllocName(size: 48 * g_DispCollTreeCount, name: v9, bClear: false);
      v10 = alloca(2 * v2);
      v95 = (float *)smoothingAngle;
      memset(dst: smoothingAngle, value: 0xFFu, count: 2 * v2);
      v11 = 0;
      if ( v104 > 0 )
      {
        v106 += 6;
        do
        {
          v12 = *v106;
          if ( *v106 != 0xFFFF && v12 < v2 )
            *((_WORD *)v95 + v12) = v11;
          v106 += 28;
          ++v11;
        }
        while ( v11 < v104 );
      }
      v100 = 0;
      v99 = 0;
      memset(&v92[2], 0, 12);
      CMapLoadHelper::CMapLoadHelper(this: &v76, lumpToLoad: 33, bUncompress: true);
      CMapLoadHelper::CMapLoadHelper(this: &v75, lumpToLoad: 48, bUncompress: true);
      v13 = 0;
      v103 = 0;
      if ( v2 > 0 )
      {
        v104 = 0;
        v102 = 0;
        do
        {
          v105 = *((unsigned __int16 *)v95 + v13);
          if ( (_WORD)v105 != 0xFFFF )
          {
            CMapLoadHelper::LoadLumpElement(
              this: (CMapLoadHelper *)&v82.m_szLumpFilename[240],
              nElemIndex: v13,
              nElemSize: 176,
              pData: &v84.m_AllowedVerts.m_Ints[6]);
            v14 = ((1 << pData) + 1) * ((1 << pData) + 1);
            CMapLoadHelper::LoadLumpData(this: &v76, offset: 20 * v100, size: 20 * v14, pData: &v73);
            v100 += v14;
            v15 = 2 * (1 << pData) * (1 << pData);
            CMapLoadHelper::LoadLumpData(
              this: &v75,
              offset: 2 * v99,
              size: 4 * (1 << pData) * (1 << pData),
              pData: &v74);
            v99 += v15;
            CCoreDispInfo::CCoreDispInfo(this: (CCoreDispInfo *)&v83.m_szLumpFilename[240]);
            *(_DWORD *)&v84.m_Surf.m_CornerNeighbors[2].m_Neighbors[2] = v88;
            LODWORD(v84.m_Surf.sAxis.z) = v84.m_AllowedVerts.m_Ints[6];
            LODWORD(v84.m_Surf.tAxis.x) = v84.m_AllowedVerts.m_Ints[7];
            LODWORD(v84.m_Surf.tAxis.y) = v84.m_AllowedVerts.m_Ints[8];
            CCoreDispInfo::InitDispInfo(
              this: (CCoreDispInfo *)&v83.m_szLumpFilename[240],
              power: pData,
              minTess: v86,
              smoothingAngle: v87,
              pVerts: &v73,
              pTris: &v74,
              nFlags: 0,
              pvMultiBlends: nullptr);
            v16 = &v93[28 * (unsigned __int16)v105];
            *(_DWORD *)&v83.m_szLumpFilename[256] = (unsigned __int16)v105;
            v17 = v16[4];
            v106 = v16;
            if ( v17 > 4 )
              goto LABEL_24;
            if ( v17 == 4 )
              v84.__vftable = (CCoreDispInfo_vtbl *)4;
            v18 = (__int16)v16[4];
            v19 = 0;
            v101 = 0;
            v98 = (const char *)v18;
            if ( v18 >= 4 )
            {
              v20 = (int *)(v96 + 4 * *((_DWORD *)v16 + 1) + 8);
              v105 = ((unsigned int)(v18 - 4) >> 2) + 1;
              v21 = (float *)v91;
              v101 = 4 * v105;
              do
              {
                v22 = *(v20 - 2);
                if ( v22 >= 0 )
                  v23 = *(unsigned __int16 *)(v4 + 4 * v22);
                else
                  v23 = *(unsigned __int16 *)(v4 - 4 * v22 + 2);
                v24 = 3 * v23;
                v25 = *(float *)(SamplePosition + 4 * v24);
                v26 = SamplePosition + 4 * v24;
                *(v21 - 2) = v25;
                *(v21 - 1) = *(float *)(v26 + 4);
                v27 = *(float *)(v26 + 8);
                v28 = *(v20 - 1);
                *v21 = v27;
                if ( v28 >= 0 )
                  v29 = *(unsigned __int16 *)(v4 + 4 * v28);
                else
                  v29 = *(unsigned __int16 *)(v4 - 4 * v28 + 2);
                v30 = 3 * v29;
                v31 = *(float *)(SamplePosition + 4 * v30);
                v32 = SamplePosition + 4 * v30;
                v21[1] = v31;
                v21[2] = *(float *)(v32 + 4);
                v33 = *(float *)(v32 + 8);
                v34 = *v20;
                v21[3] = v33;
                if ( v34 >= 0 )
                  v35 = *(unsigned __int16 *)(v4 + 4 * v34);
                else
                  v35 = *(unsigned __int16 *)(v4 - 4 * v34 + 2);
                v36 = 3 * v35;
                v37 = *(float *)(SamplePosition + 4 * v36);
                v38 = SamplePosition + 4 * v36;
                v21[4] = v37;
                v21[5] = *(float *)(v38 + 4);
                v39 = *(float *)(v38 + 8);
                v40 = v20[1];
                v21[6] = v39;
                if ( v40 >= 0 )
                  v41 = *(unsigned __int16 *)(v4 + 4 * v40);
                else
                  v41 = *(unsigned __int16 *)(v4 - 4 * v40 + 2);
                v42 = 3 * v41;
                v43 = *(float *)(SamplePosition + 4 * v42);
                v44 = SamplePosition + 4 * v42;
                v21[7] = v43;
                v20 += 4;
                v45 = *(float *)(v44 + 4);
                v21 += 12;
                v46 = v105-- == 1;
                *(v21 - 4) = v45;
                *(v21 - 3) = *(float *)(v44 + 8);
              }
              while ( !v46 );
              v18 = (int)v98;
              v16 = v106;
              v19 = v101;
            }
            if ( v19 < v18 )
            {
              v47 = (float *)&v91[3 * v19];
              v48 = (int *)(v96 + 4 * (v19 + *((_DWORD *)v16 + 1)));
              v105 = v18 - v101;
              do
              {
                v49 = *v48;
                if ( *v48 >= 0 )
                  v50 = *(unsigned __int16 *)(v4 + 4 * v49);
                else
                  v50 = *(unsigned __int16 *)(v4 - 4 * v49 + 2);
                v51 = 3 * v50;
                v52 = *(float *)(SamplePosition + 4 * v51);
                v53 = SamplePosition + 4 * v51;
                *(v47 - 2) = v52;
                ++v48;
                v54 = *(float *)(v53 + 4);
                v47 += 3;
                v46 = v105-- == 1;
                *(v47 - 4) = v54;
                *(v47 - 3) = *(float *)(v53 + 8);
              }
              while ( !v46 );
            }
            v84.m_Nodes = v89;
            v84.m_Elevation = v90;
            qmemcpy(&v84.m_Power, v91, 32);
            LODWORD(v84.m_Surf.m_Points[1].z) = v92[0];
            LODWORD(v84.m_Surf.m_Points[2].x) = v92[1];
            CCoreDispSurface::FindSurfPointStartIndex(this: (CCoreDispSurface *)&v83.m_szLumpFilename[256]);
            CCoreDispSurface::AdjustSurfPointData(this: (CCoreDispSurface *)&v83.m_szLumpFilename[256]);
            v55 = &g_pDispCollTrees[v102 / 0xF4];
            g_pDispCollTrees[v102 / 0xF4].m_nPower = 0;
            if ( v84.__vftable == (CCoreDispInfo_vtbl *)4 )
            {
              CCoreDispInfo::Create(this: (CCoreDispInfo *)&v83.m_szLumpFilename[240]);
              v55->Create(this: v55, a2: (CCoreDispInfo *)&v83.m_szLumpFilename[240]);
              v56 = (char *)g_pDispBounds + v104;
              m_iCounter = v55->m_iCounter;
              m_nContents = v55->m_nContents;
              y = v55->m_mins.y;
              z = v55->m_mins.z;
              *(float *)v56 = v55->m_mins.x;
              *((_DWORD *)v56 + 8) = m_iCounter;
              *((float *)v56 + 1) = y;
              *((float *)v56 + 2) = z;
              v61 = v55->m_maxs.y;
              v62 = v55->m_maxs.z;
              *((float *)v56 + 4) = v55->m_maxs.x;
              *((float *)v56 + 5) = v61;
              *((float *)v56 + 6) = v62;
              *((_DWORD *)v56 + 9) = m_nContents;
              ++v92[v55->m_nPower];
              v105 = (unsigned int)&pTexinfo[(__int16)v106[5]];
              v63 = *(_DWORD *)(v105 + 68);
              if ( v63 >= 0 )
              {
                v64 = materials->FindMaterial(
                        this: materials,
                        a2: pBSPData->map_surfaces.m_pArray[v63].name,
                        a3: "World textures",
                        a4: 1,
                        a5: 0);
                if ( v64 != nullptr && !v64->IsErrorMaterial(this: v64) )
                {
                  v65 = (int)v64->FindVar(this: v64, a2: "$surfaceprop", a3: (bool *)var18 + 3, a4: false);
                  if ( HIBYTE(var18[0]) != 0 )
                  {
                    v66 = (*(int (__thiscall **)(int))(*(_DWORD *)v65 + 28))(a1: v65);
                    v67 = physprops->__vftable;
                    v98 = (const char *)v66;
                    v55->m_nSurfaceProps[0] = v67->GetSurfaceIndex(this: physprops, a2: (const char *)v66);
                    v55->m_nSurfaceProps[1] = physprops->GetSurfaceIndex(this: physprops, a2: v98);
                  }
                  v68 = (int)v64->FindVar(this: v64, a2: "$surfaceprop2", a3: (bool *)var18 + 3, a4: false);
                  if ( HIBYTE(var18[0]) != 0 )
                  {
                    v69 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v68 + 28))(a1: v68);
                    v55->m_nSurfaceProps[1] = physprops->GetSurfaceIndex(this: physprops, a2: v69);
                  }
                }
                v55->m_nTexinfoFlags = pBSPData->map_surfaces.m_pArray[*(_DWORD *)(v105 + 68)].flags;
              }
              CCoreDispInfo::~CCoreDispInfo(this: (CCoreDispInfo *)&v83.m_szLumpFilename[240]);
              SamplePosition = v94;
            }
            else
            {
LABEL_24:
              CCoreDispInfo::~CCoreDispInfo(this: (CCoreDispInfo *)&v83.m_szLumpFilename[240]);
            }
            v2 = v97;
          }
          v102 += 244;
          v104 += 48;
          v13 = v103 + 1;
          v103 = v13;
        }
        while ( v13 < v2 );
      }
      CMapLoadHelper::CMapLoadHelper(this: &v77, lumpToLoad: 28, bUncompress: true);
      v70 = (dphysdisp_t *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&v77);
      Available = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&v77);
      CM_CreateDispPhysCollide(pDispLump: v70, dispLumpSize: Available);
      CMapLoadHelper::~CMapLoadHelper(this: &v77);
      CMapLoadHelper::~CMapLoadHelper(this: &v75);
      CMapLoadHelper::~CMapLoadHelper(this: &v76);
    }
    CMapLoadHelper::~CMapLoadHelper(this: (CMapLoadHelper *)&v81.m_szLumpFilename[240]);
    CMapLoadHelper::~CMapLoadHelper(this: &v78);
    CMapLoadHelper::~CMapLoadHelper(this: (CMapLoadHelper *)&v80);
    CMapLoadHelper::~CMapLoadHelper(this: &v79);
  }
  CMapLoadHelper::~CMapLoadHelper(this: (CMapLoadHelper *)&v82.m_szLumpFilename[240]);
}

//------------------------------------------------------------------------------
// Address: 0x10152FE0
// Name: void CollisionBSPData_Destroy(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_Destroy(CCollisionBSPData *pBSPData)
{
  int v2; // edi
  CCollisionBSPData *pBSPDataa; // [esp+14h] [ebp+8h]

  v2 = 0;
  if ( pBSPData->numcmodels > 0 )
  {
    pBSPDataa = nullptr;
    do
    {
      physcollision->VCollideUnload(
        this: physcollision,
        a2: (vcollide_t *)((char *)&pBSPData->map_cmodels.m_pArray->vcollisionData + (unsigned int)pBSPDataa));
      pBSPDataa = (CCollisionBSPData *)((char *)pBSPDataa + 56);
      ++v2;
    }
    while ( v2 < pBSPData->numcmodels );
  }
  DispCollTrees_FreeLeafList(pBSPData);
  CM_DestroyDispPhysCollide();
  DispCollTrees_Free(pTrees: g_pDispCollTrees);
  g_pDispCollTrees = nullptr;
  g_pDispBounds = nullptr;
  g_DispCollTreeCount = 0;
  if ( pBSPData->map_planes.m_pArray != nullptr )
    pBSPData->map_planes.m_pArray = nullptr;
  if ( pBSPData->map_texturenames != nullptr )
    pBSPData->map_texturenames = nullptr;
  if ( pBSPData->map_surfaces.m_pArray != nullptr )
    pBSPData->map_surfaces.m_pArray = nullptr;
  if ( pBSPData->map_areaportals.m_pArray != nullptr )
    pBSPData->map_areaportals.m_pArray = nullptr;
  if ( pBSPData->portalopen.m_pArray != nullptr )
    pBSPData->portalopen.m_pArray = nullptr;
  if ( pBSPData->map_areas.m_pArray != nullptr )
    pBSPData->map_areas.m_pArray = nullptr;
  pBSPData->map_entitystring.m_buf.m_Get = 0;
  pBSPData->map_entitystring.m_buf.m_Put = 0;
  pBSPData->map_entitystring.m_buf.m_nOffset = 0;
  pBSPData->map_entitystring.m_buf.m_nMaxPut = 0;
  pBSPData->map_entitystring.m_buf.m_Error = 0;
  if ( pBSPData->map_entitystring.m_buf.m_Memory.m_nGrowSize >= 0 )
  {
    if ( pBSPData->map_entitystring.m_buf.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pBSPData->map_entitystring.m_buf.m_Memory.m_pMemory);
      pBSPData->map_entitystring.m_buf.m_Memory.m_pMemory = nullptr;
    }
    pBSPData->map_entitystring.m_buf.m_Memory.m_nAllocationCount = 0;
  }
  if ( pBSPData->map_brushes.m_pArray != nullptr )
    pBSPData->map_brushes.m_pArray = nullptr;
  if ( pBSPData->map_dispList.m_pArray != nullptr )
    pBSPData->map_dispList.m_pArray = nullptr;
  if ( pBSPData->map_cmodels.m_pArray != nullptr )
    pBSPData->map_cmodels.m_pArray = nullptr;
  if ( pBSPData->map_leafbrushes.m_pArray != nullptr )
    pBSPData->map_leafbrushes.m_pArray = nullptr;
  if ( pBSPData->map_leafs.m_pArray != nullptr )
    pBSPData->map_leafs.m_pArray = nullptr;
  if ( pBSPData->map_nodes.m_pArray != nullptr )
    pBSPData->map_nodes.m_pArray = nullptr;
  if ( pBSPData->map_brushsides.m_pArray != nullptr )
    pBSPData->map_brushsides.m_pArray = nullptr;
  if ( pBSPData->map_boxbrushes.m_pArray != nullptr )
    pBSPData->map_boxbrushes.m_pArray = nullptr;
  if ( pBSPData->map_vis != nullptr )
    pBSPData->map_vis = nullptr;
  pBSPData->numplanes = 0;
  pBSPData->numbrushsides = 0;
  pBSPData->solidleaf = 0;
  pBSPData->emptyleaf = 0;
  pBSPData->numnodes = 0;
  pBSPData->numleafs = 0;
  pBSPData->numbrushes = 0;
  pBSPData->numboxbrushes = 0;
  pBSPData->numdisplist = 0;
  pBSPData->numleafbrushes = 0;
  pBSPData->numareas = 0;
  pBSPData->numtextures = 0;
  pBSPData->floodvalid = 0;
  pBSPData->numareaportals = 0;
  pBSPData->numclusters = 0;
  pBSPData->numcmodels = 0;
  pBSPData->numvisibility = 0;
  pBSPData->numentitychars = 0;
  pBSPData->numportalopen = 0;
  pBSPData->mapPathName[0] = 0;
  pBSPData->map_rootnode = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101531E0
// Name: public: void CDiscardableArray<char>::Init(char __near *,int,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDiscardableArray<char>::Init(
        CDiscardableArray<char> *this,
        char *pFilename,
        int nOffset,
        int nCount,
        void *pData)
{
  if ( this->m_buf.m_Put != 0 )
  {
    this->m_buf.m_Get = 0;
    this->m_buf.m_Put = 0;
    this->m_buf.m_nOffset = 0;
    this->m_buf.m_nMaxPut = 0;
    this->m_buf.m_Error = 0;
    if ( this->m_buf.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_buf.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_buf.m_Memory.m_pMemory);
        this->m_buf.m_Memory.m_pMemory = nullptr;
      }
      this->m_buf.m_Memory.m_nAllocationCount = 0;
    }
  }
  this->m_nCount = nCount;
  _V_strcpy(dest: this->m_pFilename, src: pFilename);
  this->m_nOffset = nOffset;
  if ( pData != nullptr )
    CUtlBuffer::Put(this: &this->m_buf, pMem: pData, size: nCount);
}

//------------------------------------------------------------------------------
// Address: 0x10153260
// Name: void CollisionBSPData_LoadEntityString(class CCollisionBSPData __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionBSPData_LoadEntityString(CCollisionBSPData *pBSPData)
{
  char *DiskName; // eax
  char *v2; // [esp-Ch] [ebp-138h]
  netadrtype_t Available; // [esp-8h] [ebp-134h]
  void *SamplePosition; // [esp-4h] [ebp-130h]
  CMapLoadHelper lh; // [esp+4h] [ebp-128h] BYREF

  CMapLoadHelper::CMapLoadHelper(this: &lh, lumpToLoad: 0, bUncompress: true);
  pBSPData->numentitychars = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh);
  SamplePosition = (void *)CAudioMixerWave::GetSamplePosition(this: (CVTFTexture *)&lh);
  Available = CCircularBuffer::GetReadAvailable(this: (netadr_s *)&lh);
  v2 = CWaveDataStreamAsync::Source(this: (vgui::Tooltip *)&lh);
  DiskName = CMapLoadHelper::GetDiskName(this: &lh);
  CDiscardableArray<char>::Init(
    this: &pBSPData->map_entitystring,
    pFilename: DiskName,
    nOffset: (int)v2,
    nCount: Available,
    pData: SamplePosition);
  CMapLoadHelper::~CMapLoadHelper(this: &lh);
}

//------------------------------------------------------------------------------
// Address: 0x101532E0
// Name: bool CollisionBSPData_Load(char const __near *,class CCollisionBSPData __near *,struct texinfo_s __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CollisionBSPData_Load(
        const char *pPathName,
        CCollisionBSPData *pBSPData,
        texinfo_s *pTexinfo,
        int texinfoCount)
{
  V_strncpy(pDest: pBSPData->mapPathName, pSrc: pPathName, maxLen: 96);
  _COM_TimestampedLog(a1: "  CollisionBSPData_LoadTextures");
  CollisionBSPData_LoadTextures(pBSPData);
  _COM_TimestampedLog(a1: "  CollisionBSPData_LoadTexinfo");
  CollisionBSPData_LoadTexinfo(pBSPData, pTexinfo, texinfoCount);
  _COM_TimestampedLog(a1: "  CollisionBSPData_LoadLeafs");
  CollisionBSPData_LoadLeafs(pBSPData);
  _COM_TimestampedLog(a1: "  CollisionBSPData_LoadLeafBrushes");
  CollisionBSPData_LoadLeafBrushes(pBSPData);
  _COM_TimestampedLog(a1: "  CollisionBSPData_LoadPlanes");
  CollisionBSPData_LoadPlanes(pBSPData);
  _COM_TimestampedLog(a1: "  CollisionBSPData_LoadBrushes");
  CollisionBSPData_LoadBrushes(pBSPData);
  _COM_TimestampedLog(a1: "  CollisionBSPData_LoadBrushSides");
  CollisionBSPData_LoadBrushSides(pBSPData, pTexinfo, texinfoCount);
  _COM_TimestampedLog(a1: "  CollisionBSPData_LoadSubmodels");
  CollisionBSPData_LoadSubmodels(pBSPData);
  _COM_TimestampedLog(a1: "  CollisionBSPData_LoadPlanes");
  CollisionBSPData_LoadNodes(pBSPData);
  _COM_TimestampedLog(a1: "  CollisionBSPData_LoadAreas");
  CollisionBSPData_LoadAreas(pBSPData);
  _COM_TimestampedLog(a1: "  CollisionBSPData_LoadAreaPortals");
  CollisionBSPData_LoadAreaPortals(pBSPData);
  _COM_TimestampedLog(a1: "  CollisionBSPData_LoadVisibility");
  CollisionBSPData_LoadVisibility(pBSPData);
  _COM_TimestampedLog(a1: "  CollisionBSPData_LoadEntityString");
  CollisionBSPData_LoadEntityString(pBSPData);
  _COM_TimestampedLog(a1: "  CollisionBSPData_LoadPhysics");
  CollisionBSPData_LoadPhysics(pBSPData);
  _COM_TimestampedLog(a1: "  CollisionBSPData_LoadDispInfo");
  CollisionBSPData_LoadDispInfo(pBSPData, pTexinfo);
  return 1;
}

} // namespace engine_xlsp
