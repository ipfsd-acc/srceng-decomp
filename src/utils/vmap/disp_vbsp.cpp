// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmap/disp_vbsp.cpp
// Functions: 17
// ============================================================

#include "utils\vmap\disp_vbsp.h"

//------------------------------------------------------------------------------
// Address: 0x0041E570
// Name: void Vector2DCopy(class Vector2D const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector2DCopy(const Vector2D *src, Vector2D *dst)
{
  *dst = *src;
}

//------------------------------------------------------------------------------
// Address: 0x0041E590
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
// Address: 0x0041E5E0
// Name: public: int CCoreDispInfo::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCoreDispInfo::GetSize(CCoreDispInfo *this)
{
  return ((1 << this->m_Power) + 1) * ((1 << this->m_Power) + 1);
}

//------------------------------------------------------------------------------
// Address: 0x0041E5F0
// Name: int GetDispInfoEntityNum(struct mapdispinfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetDispInfoEntityNum(mapdispinfo_t *pDisp)
{
  return pDisp->entitynum;
}

//------------------------------------------------------------------------------
// Address: 0x0041E600
// Name: void DispGetFaceInfo(struct mapbrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispGetFaceInfo(mapbrush_t *pBrush)
{
  int v2; // ebx
  const char *v3; // eax
  side_t *v4; // esi
  int i; // [esp+10h] [ebp+8h]

  v2 = 0;
  if ( pBrush->entitynum != 0 )
  {
    v3 = ValueForKey(ent: (entity_t *)&entities + pBrush->entitynum, key: "classname");
    _Error(
      a1: "Error: displacement found on a(n) %s entity - not supported (entity %d, brush %d)\n",
      v3,
      pBrush->entitynum,
      pBrush->brushnum);
  }
  for ( i = 0; i < pBrush->numsides; ++i )
  {
    v4 = &pBrush->original_sides[v2];
    if ( v4->pMapDisp != nullptr )
    {
      if ( v4->winding->numpoints != 4 )
        _Error(
          a1: "Trying to create a non-quad displacement! (entity %d, brush %d)\n",
          pBrush->entitynum,
          pBrush->brushnum);
      v4->pMapDisp->face.originalface = v4;
      v4->pMapDisp->face.texinfo = v4->texinfo;
      v4->pMapDisp->face.dispinfo = -1;
      v4->pMapDisp->face.planenum = v4->planenum;
      v4->pMapDisp->face.numpoints = v4->winding->numpoints;
      v4->pMapDisp->face.w = CopyWinding(w: v4->winding);
      v4->pMapDisp->face.contents = pBrush->contents;
      v4->pMapDisp->face.merged = nullptr;
      v4->pMapDisp->face.split[0] = nullptr;
      v4->pMapDisp->face.split[1] = nullptr;
      v4->pMapDisp->entitynum = pBrush->entitynum;
      v4->pMapDisp->brushSideID = v4->id;
    }
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041E700
// Name: bool HasDispInfo(struct mapbrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl HasDispInfo(mapbrush_t *pBrush)
{
  int numsides; // edx
  int v2; // eax
  mapdispinfo_t **i; // ecx

  numsides = pBrush->numsides;
  v2 = 0;
  if ( numsides <= 0 )
    return 0;
  for ( i = &pBrush->original_sides->pMapDisp; *i == nullptr; i += 25 )
  {
    if ( ++v2 >= numsides )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041E730
// Name: public: void CUtlMemory<bool,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<bool,int>::Grow(CUtlMemory<bool,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  bool *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 32;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (bool *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: m_nAllocationCount);
    else
      this->m_pMemory = (bool *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041E8F0
// Name: void ExportNeighborData(class CCoreDispInfo __near * __near *,class ddispinfo_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ExportNeighborData(CCoreDispInfo **ppListBase, ddispinfo_t *pBSPDispInfos, int listSize)
{
  int v3; // edx
  CDispCornerNeighbors *m_CornerNeighbors; // eax
  CCoreDispInfo *v5; // ecx

  FindNeighboringDispSurfs(ppListBase, nListSize: listSize);
  v3 = 0;
  if ( nummapdispinfo > 0 )
  {
    m_CornerNeighbors = pBSPDispInfos->m_CornerNeighbors;
    do
    {
      v5 = g_CoreDispInfos.m_Memory.m_pMemory[v3];
      *(_QWORD *)&m_CornerNeighbors[-5].m_Neighbors[1] = *(_QWORD *)&v5->m_Surf.m_EdgeNeighbors[0].m_SubNeighbors[0].m_iNeighbor;
      *(_DWORD *)m_CornerNeighbors[-4].m_Neighbors = *(_DWORD *)&v5->m_Surf.m_EdgeNeighbors[0].m_SubNeighbors[1].m_NeighborOrientation;
      *(_QWORD *)m_CornerNeighbors->m_Neighbors = *(_QWORD *)v5->m_Surf.m_CornerNeighbors[0].m_Neighbors;
      *(_WORD *)&m_CornerNeighbors->m_nNeighbors = *(_WORD *)&v5->m_Surf.m_CornerNeighbors[0].m_nNeighbors;
      *(_QWORD *)&m_CornerNeighbors[-4].m_Neighbors[2] = *(_QWORD *)&v5->m_Surf.m_EdgeNeighbors[1].m_SubNeighbors[0].m_iNeighbor;
      *(_DWORD *)&m_CornerNeighbors[-3].m_Neighbors[1] = *(_DWORD *)&v5->m_Surf.m_EdgeNeighbors[1].m_SubNeighbors[1].m_NeighborOrientation;
      *(_QWORD *)m_CornerNeighbors[1].m_Neighbors = *(_QWORD *)v5->m_Surf.m_CornerNeighbors[1].m_Neighbors;
      *(_WORD *)&m_CornerNeighbors[1].m_nNeighbors = *(_WORD *)&v5->m_Surf.m_CornerNeighbors[1].m_nNeighbors;
      *(_QWORD *)&m_CornerNeighbors[-3].m_Neighbors[3] = *(_QWORD *)&v5->m_Surf.m_EdgeNeighbors[2].m_SubNeighbors[0].m_iNeighbor;
      *(_DWORD *)&m_CornerNeighbors[-2].m_Neighbors[2] = *(_DWORD *)&v5->m_Surf.m_EdgeNeighbors[2].m_SubNeighbors[1].m_NeighborOrientation;
      *(_QWORD *)m_CornerNeighbors[2].m_Neighbors = *(_QWORD *)v5->m_Surf.m_CornerNeighbors[2].m_Neighbors;
      *(_WORD *)&m_CornerNeighbors[2].m_nNeighbors = *(_WORD *)&v5->m_Surf.m_CornerNeighbors[2].m_nNeighbors;
      *(_QWORD *)&m_CornerNeighbors[-2].m_nNeighbors = *(_QWORD *)&v5->m_Surf.m_EdgeNeighbors[3].m_SubNeighbors[0].m_iNeighbor;
      *(_DWORD *)&m_CornerNeighbors[-1].m_Neighbors[3] = *(_DWORD *)&v5->m_Surf.m_EdgeNeighbors[3].m_SubNeighbors[1].m_NeighborOrientation;
      *(_QWORD *)m_CornerNeighbors[3].m_Neighbors = *(_QWORD *)v5->m_Surf.m_CornerNeighbors[3].m_Neighbors;
      *(_WORD *)&m_CornerNeighbors[3].m_nNeighbors = *(_WORD *)&v5->m_Surf.m_CornerNeighbors[3].m_nNeighbors;
      ++v3;
      m_CornerNeighbors = (CDispCornerNeighbors *)((char *)m_CornerNeighbors + 176);
    }
    while ( v3 < nummapdispinfo );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041EA00
// Name: void ExportAllowedVertLists(class CCoreDispInfo __near * __near *,class ddispinfo_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ExportAllowedVertLists(CCoreDispInfo **ppListBase, ddispinfo_t *pBSPDispInfos, int listSize)
{
  int v3; // edx
  unsigned int *v4; // eax
  CCoreDispInfo *v5; // ecx

  SetupAllowedVerts(ppListBase, nListSize: listSize);
  v3 = 0;
  if ( listSize > 0 )
  {
    v4 = &pBSPDispInfos->m_AllowedVerts[1];
    do
    {
      v5 = ppListBase[v3];
      *(v4 - 1) = v5->m_AllowedVerts.m_Ints[0];
      *v4 = v5->m_AllowedVerts.m_Ints[1];
      v4[1] = v5->m_AllowedVerts.m_Ints[2];
      v4[2] = v5->m_AllowedVerts.m_Ints[3];
      v4[3] = v5->m_AllowedVerts.m_Ints[4];
      v4[4] = v5->m_AllowedVerts.m_Ints[5];
      v4[5] = v5->m_AllowedVerts.m_Ints[6];
      v4[6] = v5->m_AllowedVerts.m_Ints[7];
      v4[7] = v5->m_AllowedVerts.m_Ints[8];
      v4[8] = v5->m_AllowedVerts.m_Ints[9];
      ++v3;
      v4 += 44;
    }
    while ( v3 < listSize );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041EA90
// Name: bool FindEnclosingTri(class Vector2D const __near &,class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>> __near &,class CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>> __near &,int __near *,float __near * const)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FindEnclosingTri(
        const Vector2D *vert,
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *vertCoords,
        CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *indices,
        int *pStartVert,
        float *bcCoords)
{
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *v5; // eax
  int v6; // esi
  Vector2D *m_pMemory; // ebx
  unsigned __int16 *v8; // eax
  int v9; // edx
  int v10; // esi
  float x; // xmm3_4
  float y; // xmm1_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  float *p_x; // edx
  float *v16; // esi
  float *v17; // eax
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  Vector2D *v23; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v5 = indices;
  v6 = 0;
  i = 0;
  if ( indices->m_Size <= 0 )
    return 0;
  m_pMemory = vertCoords->m_Memory.m_pMemory;
  v23 = vertCoords->m_Memory.m_pMemory;
  while ( 1 )
  {
    v8 = v5->m_Memory.m_pMemory;
    v9 = v8[v6 + 2];
    v10 = v8[v6 + 1];
    x = m_pMemory[v10].x;
    y = m_pMemory[v9].y;
    v13 = m_pMemory[v10].y;
    v14 = m_pMemory[v9].x;
    p_x = &m_pMemory[v9].x;
    v16 = &m_pMemory[v10].x;
    m_pMemory = v23;
    v17 = &v23[v8[i]].x;
    v18 = 1.0
        / (float)((float)((float)(x - *v17) * (float)(y - v17[1])) - (float)((float)(v14 - *v17) * (float)(v13 - v17[1])));
    *bcCoords = (float)((float)((float)(v14 - x) * (float)(vert->y - v13))
                      - (float)((float)(y - v13) * (float)(vert->x - x)))
              * v18;
    v19 = (float)((float)((float)(*v17 - *p_x) * (float)(vert->y - p_x[1]))
                - (float)((float)(vert->x - *p_x) * (float)(v17[1] - p_x[1])))
        * v18;
    bcCoords[1] = v19;
    v20 = *bcCoords;
    v21 = (float)((float)((float)(*v16 - *v17) * (float)(vert->y - v17[1]))
                - (float)((float)(v16[1] - v17[1]) * (float)(vert->x - *v17)))
        * v18;
    bcCoords[2] = v21;
    if ( v20 >= 0.0 && v20 <= 1.0 && v19 >= 0.0 && v19 <= 1.0 && v21 >= 0.0 && v21 <= 1.0 )
      break;
    v5 = indices;
    v6 = i + 3;
    i = v6;
    if ( v6 >= indices->m_Size )
      return 0;
  }
  *pStartVert = i;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041EE90
// Name: void DispMapToCoreDispInfo(struct mapdispinfo_t __near *,class CCoreDispInfo __near *,struct dface_t __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall DispMapToCoreDispInfo(
        int a1@<ebp>,
        mapdispinfo_t *pMapDisp,
        CCoreDispInfo *pCoreDispInfo,
        dface_t *pFace,
        int *pSwappedTexInfos)
{
  void *v5; // esp
  mapdispinfo_t *v6; // esi
  winding_t *winding; // ecx
  texinfo_s *v8; // edx
  int contents; // eax
  CCoreDispSurface *p_m_Surf; // edi
  Vector *p; // eax
  float z; // xmm0_4
  Vector *v13; // eax
  float x; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  __int128 v21; // xmm4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  bool v25; // al
  int *v26; // eax
  __int64 v27; // xmm0_8
  __int64 v28; // xmm0_8
  int m_Size; // eax
  int v30; // esi
  texinfo_s *m_pMemory; // ecx
  int v32; // eax
  texinfo_s *v33; // edi
  int power; // ecx
  float *p_z; // edi
  float v36; // xmm3_4
  float v37; // xmm0_4
  float v38; // xmm2_4
  float v39; // xmm1_4
  __int128 v40; // xmm0
  float *v41; // eax
  int v42; // ecx
  Vector v43[2048]; // [esp+28h] [ebp-80CCh] BYREF
  float v44[2048]; // [esp+6028h] [ebp-20CCh] BYREF
  __int128 v45; // [esp+8028h] [ebp-CCh]
  Vector v46; // [esp+8038h] [ebp-BCh] BYREF
  Vector v47; // [esp+8044h] [ebp-B0h] BYREF
  Vector v48[6]; // [esp+8050h] [ebp-A4h] BYREF
  Vector2D v49; // [esp+8098h] [ebp-5Ch] BYREF
  float v50; // [esp+80A0h] [ebp-54h]
  float v51; // [esp+80A4h] [ebp-50h]
  int v52; // [esp+80A8h] [ebp-4Ch]
  float v53; // [esp+80ACh] [ebp-48h]
  int v54; // [esp+80B0h] [ebp-44h]
  float v55; // [esp+80B4h] [ebp-40h]
  __int128 v56; // [esp+80B8h] [ebp-3Ch] BYREF
  int v57; // [esp+80D4h] [ebp-20h] BYREF
  int v58; // [esp+80D8h] [ebp-1Ch]
  int v59; // [esp+80DCh] [ebp-18h]
  float *p_numpoints; // [esp+80E0h] [ebp-14h]
  float *dispDists; // [esp+80E4h] [ebp-10h]
  int v62; // [esp+80E8h] [ebp-Ch]
  void *v63; // [esp+80ECh] [ebp-8h]
  void *retaddr; // [esp+80F4h] [ebp+0h]

  v62 = a1;
  v63 = retaddr;
  v5 = alloca(32968);
  v6 = pMapDisp;
  winding = pMapDisp->face.originalface->winding;
  v8 = &texinfo.m_Memory.m_pMemory[pMapDisp->face.texinfo];
  contents = pMapDisp->face.contents;
  p_m_Surf = &pCoreDispInfo->m_Surf;
  p_numpoints = (float *)&winding->numpoints;
  dispDists = (float *)v8;
  pMapDisp->contents = contents;
  if ( (contents & 0x300FF) == 0 )
    pMapDisp->contents = contents | 1;
  pCoreDispInfo->m_Surf.m_Contents = pMapDisp->contents;
  v49.x = 0.0;
  v49.y = 0.0;
  v50 = 0.0;
  v51 = 1.0;
  *(float *)&v52 = 1.0;
  v53 = 0.0;
  *(float *)&v54 = 1.0;
  v55 = 1.0;
  if ( pFace != nullptr )
  {
    p = winding->p;
    v48[2] = *p;
    v48[3] = p[1];
    v48[4] = p[2];
    v48[5].x = p[3].x;
    v48[5].y = p[3].y;
    z = p[3].z;
    v57 = 0;
    v58 = 0;
    v48[5].z = z;
    CalcTextureCoordsAtPoints(
      texelsPerWorldUnits: v8->textureVecsTexelsPerWorldUnits,
      subtractOffset: &v57,
      pPoints: &v48[2],
      nPoints: 4,
      pCoords: &v49);
    winding = (winding_t *)p_numpoints;
  }
  pCoreDispInfo->m_Surf.m_PointCount = 4;
  v13 = winding->p;
  x = v49.x;
  pCoreDispInfo->m_Surf.m_Points[0].x = v13->x;
  pCoreDispInfo->m_Surf.m_Points[0].y = v13->y;
  pCoreDispInfo->m_Surf.m_Points[0].z = v13->z;
  pCoreDispInfo->m_Surf.m_TexCoords[0] = (Vector2D)__PAIR64__(LODWORD(v49.y), LODWORD(x));
  pCoreDispInfo->m_Surf.m_Points[1].x = v13[1].x;
  v15 = v50;
  pCoreDispInfo->m_Surf.m_Points[1].y = v13[1].y;
  pCoreDispInfo->m_Surf.m_Points[1].z = v13[1].z;
  pCoreDispInfo->m_Surf.m_TexCoords[1].x = v15;
  pCoreDispInfo->m_Surf.m_TexCoords[1].y = v51;
  v16 = *(float *)&v52;
  pCoreDispInfo->m_Surf.m_Points[2] = v13[2];
  pCoreDispInfo->m_Surf.m_TexCoords[2].x = v16;
  pCoreDispInfo->m_Surf.m_TexCoords[2].y = v53;
  v17 = *(float *)&v54;
  pCoreDispInfo->m_Surf.m_Points[3] = v13[3];
  pCoreDispInfo->m_Surf.m_TexCoords[3].x = v17;
  pCoreDispInfo->m_Surf.m_TexCoords[3].y = v55;
  pCoreDispInfo->m_Surf.m_PointStart = pMapDisp->startPosition;
  CCoreDispSurface::FindSurfPointStartIndex(this: p_m_Surf);
  CCoreDispSurface::AdjustSurfPointData(this: p_m_Surf);
  v18 = dispDists[9];
  v19 = dispDists[10];
  v20 = (float)((float)(v18 * v18) + (float)(v19 * v19)) + (float)(dispDists[8] * dispDists[8]);
  v21 = 0;
  v46.x = dispDists[8];
  v46.y = v18;
  v46.z = v19;
  v22 = dispDists[13];
  v23 = dispDists[14];
  v24 = dispDists[12];
  *(float *)&v21 = fsqrt(v20);
  v56 = v21;
  v47.x = v24;
  v47.y = v22;
  v47.z = v23;
  v25 = CCoreDispSurface::CalcLuxelCoords(
          this: p_m_Surf,
          nLuxels: (int)(float)(1.0 / *(float *)&v21),
          bAdjust: false,
          vecU: &v46,
          vecV: &v47);
  if ( pFace != nullptr )
  {
    pFace->m_LightmapTextureSizeInLuxels[0] = pCoreDispInfo->m_Surf.m_nLuxelU;
    pFace->m_LightmapTextureSizeInLuxels[1] = pCoreDispInfo->m_Surf.m_nLuxelV;
    if ( v25 )
    {
      v26 = pSwappedTexInfos;
      if ( pSwappedTexInfos[pMapDisp->face.texinfo] < 0 )
      {
        v27 = *((_QWORD *)dispDists + 6);
        qmemcpy(v48, dispDists, sizeof(v48));
        *(_QWORD *)&v48[2].z = v27;
        *(_QWORD *)&v48[3].y = *((_QWORD *)dispDists + 7);
        *(_QWORD *)&v48[4].x = *((_QWORD *)dispDists + 4);
        v28 = *((_QWORD *)dispDists + 5);
        m_Size = texinfo.m_Size;
        v48[4].x = v48[4].x * -1.0;
        v48[4].y = v48[4].y * -1.0;
        v48[4].z = *(float *)&v28 * -1.0;
        v30 = texinfo.m_Size;
        v48[5].x = *((float *)&v28 + 1) * -1.0;
        p_numpoints = (float *)texinfo.m_Size;
        if ( texinfo.m_Size + 1 > texinfo.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<StaticPropLump_t,int>::Grow(
            this: &texinfo.m_Memory,
            num: texinfo.m_Size - texinfo.m_Memory.m_nAllocationCount + 1);
          m_Size = texinfo.m_Size;
        }
        m_pMemory = texinfo.m_Memory.m_pMemory;
        texinfo.m_Size = m_Size + 1;
        v32 = m_Size - v30;
        texinfo.m_pElements = texinfo.m_Memory.m_pMemory;
        if ( v32 > 0 )
        {
          _V_memmove(dest: &texinfo.m_Memory.m_pMemory[v30 + 1], src: &texinfo.m_Memory.m_pMemory[v30], count: 72 * v32);
          m_pMemory = texinfo.m_Memory.m_pMemory;
        }
        v33 = &m_pMemory[v30];
        if ( v33 != nullptr )
        {
          qmemcpy(v33, v48, sizeof(texinfo_s));
          v30 = (int)p_numpoints;
        }
        v26 = pSwappedTexInfos;
        pSwappedTexInfos[pMapDisp->face.texinfo] = v30;
        v6 = pMapDisp;
      }
      v6->face.texinfo = v26[v6->face.texinfo];
    }
  }
  power = v6->power;
  v59 = 0;
  v58 = ((1 << power) + 1) * ((1 << power) + 1);
  if ( v58 > 0 )
  {
    p_numpoints = &v43[0].z;
    dispDists = v6->dispDists;
    p_z = &v6->vectorDisps[0].z;
    do
    {
      v36 = *p_z * *dispDists;
      v37 = p_z[865] + (float)(*(p_z - 2) * *dispDists);
      v38 = p_z[867];
      *((float *)&v56 + 2) = p_z[866] + (float)(*(p_z - 1) * *dispDists);
      *((float *)&v56 + 1) = v37;
      *((float *)&v56 + 3) = v38 + v36;
      v39 = (float)((float)(*((float *)&v56 + 2) * *((float *)&v56 + 2))
                  + (float)(*((float *)&v56 + 3) * *((float *)&v56 + 3)))
          + (float)(v37 * v37);
      v40 = 0;
      *(float *)&v40 = fsqrt(v39);
      v45 = v40;
      VectorNormalize(vec: (Vector *)((char *)&v56 + 4));
      v41 = p_numpoints;
      v42 = v59;
      ++dispDists;
      *((_QWORD *)p_numpoints - 1) = *(_QWORD *)((char *)&v56 + 4);
      *v41 = *((float *)&v56 + 3);
      LODWORD(v44[v42]) = v45;
      p_z += 3;
      v59 = v42 + 1;
      p_numpoints = v41 + 3;
    }
    while ( v42 + 1 < v58 );
  }
  CCoreDispInfo::InitDispInfo(
    this: pCoreDispInfo,
    power: v6->power,
    minTess: v6->minTess,
    smoothingAngle: v6->smoothingAngle,
    alphas: v6->alphaValues,
    dispVectorField: v43,
    dispDistances: v44,
    nFlags: 0,
    pvMultiBlends: nullptr);
  CCoreDispInfo::Create(this: pCoreDispInfo);
}

//------------------------------------------------------------------------------
// Address: 0x0041F400
// Name: void TesselateDisplacementNode<class CVBSPTesselateHelper>(class CVBSPTesselateHelper __near *,class CVertIndex const __near &,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TesselateDisplacementNode<CVBSPTesselateHelper>(
        CVBSPTesselateHelper *pHelper,
        const CVertIndex *nodeIndex,
        char iLevel,
        int *pActiveChildren)
{
  int v5; // eax
  __int16 v6; // dx
  __int16 v7; // di
  int m_iNode; // ecx
  CUtlMemory<short,int> *m_pIndices; // edi
  __int16 *m_pMemory; // ebx
  int m_nAllocationCount; // eax
  __int16 *v12; // ecx
  int v13; // eax
  __int16 *v14; // ebx
  CUtlMemory<short,int> *v15; // edi
  __int16 *v16; // ebx
  int v17; // eax
  __int16 *v18; // ecx
  int v19; // eax
  __int16 *v20; // eax
  CUtlMemory<short,int> *v21; // edi
  __int16 *v22; // ebx
  int v23; // eax
  __int16 *v24; // ecx
  int v25; // eax
  __int16 *v26; // eax
  int iVert; // [esp+Ch] [ebp-8h]
  int vertInc; // [esp+10h] [ebp-4h]
  int iCurTriVert; // [esp+1Ch] [ebp+8h]
  int iLevela; // [esp+24h] [ebp+10h]

  vertInc = 1 << (pHelper->m_pPowerInfo->m_Power - iLevel - 1);
  v5 = 0;
  iCurTriVert = 0;
  iVert = 0;
  if ( g_TWinding.m_nVerts > 0 )
  {
    iLevela = 0;
    do
    {
      v6 = nodeIndex->x + vertInc * g_TWinding.m_Verts[iLevela].m_Index.x;
      v7 = nodeIndex->y + vertInc * g_TWinding.m_Verts[iLevela].m_Index.y;
      m_iNode = g_TWinding.m_Verts[iLevela].m_iNode;
      if ( m_iNode == -1 || pActiveChildren[m_iNode] == 0 )
      {
        if ( ((1 << ((v6 + LOBYTE(pHelper->m_pPowerInfo->m_SideLength) * v7) & 0x1F))
            & pHelper->m_pActiveVerts[(v6 + pHelper->m_pPowerInfo->m_SideLength * v7) >> 5]) != 0 )
        {
          pHelper->m_TempIndices[iCurTriVert] = v6 + v7 * LOWORD(pHelper->m_pPowerInfo->m_SideLength);
          v5 = iCurTriVert + 1;
          iCurTriVert = v5;
          if ( v5 == 2 )
          {
            pHelper->m_TempIndices[2] = nodeIndex->x + nodeIndex->y * LOWORD(pHelper->m_pPowerInfo->m_SideLength);
            CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertBefore(
              this: pHelper->m_pIndices,
              elem: pHelper->m_pIndices->m_Size,
              src: pHelper->m_TempIndices);
            CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertBefore(
              this: pHelper->m_pIndices,
              elem: pHelper->m_pIndices->m_Size,
              src: &pHelper->m_TempIndices[1]);
            CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertBefore(
              this: pHelper->m_pIndices,
              elem: pHelper->m_pIndices->m_Size,
              src: &pHelper->m_TempIndices[2]);
            pHelper->m_TempIndices[0] = pHelper->m_TempIndices[1];
            v5 = 1;
            iCurTriVert = 1;
          }
        }
        else
        {
          v5 = iCurTriVert;
        }
      }
      else
      {
        if ( v5 == 2 )
        {
          m_pIndices = (CUtlMemory<short,int> *)pHelper->m_pIndices;
          pHelper->m_TempIndices[2] = nodeIndex->x + nodeIndex->y * LOWORD(pHelper->m_pPowerInfo->m_SideLength);
          m_pMemory = m_pIndices[1].m_pMemory;
          m_nAllocationCount = m_pIndices->m_nAllocationCount;
          if ( (int)m_pMemory + 1 > m_nAllocationCount )
            CUtlMemory<CFaceMacroTextureInfo,int>::Grow(this: m_pIndices, num: (int)m_pMemory - m_nAllocationCount + 1);
          ++m_pIndices[1].m_pMemory;
          v12 = m_pIndices->m_pMemory;
          v13 = (char *)m_pIndices[1].m_pMemory - (char *)m_pMemory - 1;
          m_pIndices[1].m_nAllocationCount = (int)m_pIndices->m_pMemory;
          if ( v13 > 0 )
            _V_memmove(dest: &v12[(_DWORD)m_pMemory + 1], src: &v12[(_DWORD)m_pMemory], count: 2 * v13);
          v14 = &m_pIndices->m_pMemory[(_DWORD)m_pMemory];
          if ( v14 != nullptr )
            *v14 = pHelper->m_TempIndices[0];
          v15 = (CUtlMemory<short,int> *)pHelper->m_pIndices;
          v16 = v15[1].m_pMemory;
          v17 = v15->m_nAllocationCount;
          if ( (int)v16 + 1 > v17 )
            CUtlMemory<CFaceMacroTextureInfo,int>::Grow(this: v15, num: (int)v16 - v17 + 1);
          ++v15[1].m_pMemory;
          v18 = v15->m_pMemory;
          v19 = (char *)v15[1].m_pMemory - (char *)v16 - 1;
          v15[1].m_nAllocationCount = (int)v15->m_pMemory;
          if ( v19 > 0 )
            _V_memmove(dest: &v18[(_DWORD)v16 + 1], src: &v18[(_DWORD)v16], count: 2 * v19);
          v20 = &v15->m_pMemory[(_DWORD)v16];
          if ( v20 != nullptr )
            *v20 = pHelper->m_TempIndices[1];
          v21 = (CUtlMemory<short,int> *)pHelper->m_pIndices;
          v22 = v21[1].m_pMemory;
          v23 = v21->m_nAllocationCount;
          if ( (int)v22 + 1 > v23 )
            CUtlMemory<CFaceMacroTextureInfo,int>::Grow(this: v21, num: (int)v22 - v23 + 1);
          ++v21[1].m_pMemory;
          v24 = v21->m_pMemory;
          v25 = (char *)v21[1].m_pMemory - (char *)v22 - 1;
          v21[1].m_nAllocationCount = (int)v21->m_pMemory;
          if ( v25 > 0 )
            _V_memmove(dest: &v24[(_DWORD)v22 + 1], src: &v24[(_DWORD)v22], count: 2 * v25);
          v26 = &v21->m_pMemory[(_DWORD)v22];
          if ( v26 != nullptr )
            *v26 = pHelper->m_TempIndices[2];
          pHelper->m_TempIndices[0] = pHelper->m_TempIndices[1];
        }
        v5 = 0;
        iCurTriVert = 0;
      }
      ++iLevela;
      ++iVert;
    }
    while ( iVert < g_TWinding.m_nVerts );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041F680
// Name: void ComputeDispInfoBounds(int,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeDispInfoBounds(int dispinfo, Vector *mins, Vector *maxs)
{
  CCoreDispInfo coreDispInfo; // [esp+0h] [ebp-364h] BYREF
  CDispBox box; // [esp+34Ch] [ebp-18h] BYREF
  int savedregs; // [esp+364h] [ebp+0h] BYREF

  CCoreDispInfo::CCoreDispInfo(this: &coreDispInfo);
  DispMapToCoreDispInfo(
    a1: (int)&savedregs,
    pMapDisp: (mapdispinfo_t *)&mapdispinfo + dispinfo,
    pCoreDispInfo: &coreDispInfo,
    pFace: nullptr,
    pSwappedTexInfos: nullptr);
  GetDispBox(pDisp: &coreDispInfo, &box);
  *mins = box.m_Min;
  *maxs = box.m_Max;
  CCoreDispInfo::~CCoreDispInfo(this: &coreDispInfo);
}

//------------------------------------------------------------------------------
// Address: 0x0041F720
// Name: void TesselateDisplacement_R<class CVBSPTesselateHelper>(class CVBSPTesselateHelper __near *,class CVertIndex const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TesselateDisplacement_R<CVBSPTesselateHelper>(
        CVBSPTesselateHelper *pHelper,
        const CVertIndex *nodeIndex,
        int iNodeBitIndex,
        int iLevel)
{
  const CPowerInfo *m_pPowerInfo; // ecx
  int v6; // edx
  int v7; // ebx
  const CPowerInfo *v8; // ecx
  const CVertIndex *v9; // esi
  unsigned int v10; // edx
  int bActiveChildren[4]; // [esp+0h] [ebp-18h] BYREF
  int oldIndexCount; // [esp+10h] [ebp-8h]
  int v13; // [esp+14h] [ebp-4h]
  int iChildNodeBit; // [esp+20h] [ebp+8h]

  if ( (`CVBSPTesselateHelper::GetNodeInfo'::`2'::`local static guard' & 1) == 0 )
    `CVBSPTesselateHelper::GetNodeInfo'::`2'::`local static guard' |= 1u;
  m_pPowerInfo = pHelper->m_pPowerInfo;
  v6 = m_pPowerInfo->m_Power - 1;
  oldIndexCount = pHelper->m_nIndices;
  if ( iLevel < v6 )
  {
    v7 = 0;
    iChildNodeBit = iNodeBitIndex + 1;
    v13 = 16 * (nodeIndex->x + m_pPowerInfo->m_SideLength * nodeIndex->y);
    do
    {
      v8 = pHelper->m_pPowerInfo;
      v9 = &v8->m_pChildVerts->m_Verts[v13 / 4u];
      v10 = pHelper->m_pActiveVerts[(v9->x + v8->m_SideLength * v9->y) >> 5]
          & (1 << ((v9->x + LOBYTE(v8->m_SideLength) * v9->y) & 0x1F));
      bActiveChildren[v7] = v10;
      if ( v10 != 0 )
      {
        TesselateDisplacement_R<CVBSPTesselateHelper>(
          pHelper,
          nodeIndex: v9,
          iNodeBitIndex: iChildNodeBit,
          iLevel: iLevel + 1);
      }
      else
      {
        if ( (`CVBSPTesselateHelper::GetNodeInfo'::`2'::`local static guard' & 1) == 0 )
          `CVBSPTesselateHelper::GetNodeInfo'::`2'::`local static guard' |= 1u;
        word_1C289FA = 0;
      }
      iChildNodeBit += pHelper->m_pPowerInfo->m_NodeIndexIncrements[iLevel];
      v13 += 4;
      ++v7;
    }
    while ( v7 < 4 );
  }
  else
  {
    memset(bActiveChildren, 0, sizeof(bActiveChildren));
  }
  if ( pHelper->m_nIndices == oldIndexCount )
  {
    HIBYTE(word_1C289FA) = 0;
  }
  else
  {
    HIBYTE(word_1C289FA) = 1;
    oldIndexCount = pHelper->m_nIndices;
  }
  TesselateDisplacementNode<CVBSPTesselateHelper>(pHelper, nodeIndex, iLevel, pActiveChildren: bActiveChildren);
  LOBYTE(word_1C289FA) = LOBYTE(pHelper->m_nIndices) - oldIndexCount;
  `CVBSPTesselateHelper::GetNodeInfo'::`2'::dummy = oldIndexCount;
}

//------------------------------------------------------------------------------
// Address: 0x0041F850
// Name: void EmitInitialDispInfos(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall EmitInitialDispInfos(int a1@<ebp>)
{
  int v1; // edx
  CDispTri *v2; // eax
  int v3; // esi
  int v4; // edi
  int v5; // ecx
  _DWORD *v6; // edx
  int v7; // eax
  int v8; // eax
  bool v9; // zf
  int v10; // ecx
  int v11; // edi
  int m_nAllocationCount; // ecx
  int m_Size; // eax
  int v14; // esi
  int v15; // eax
  int v16; // eax
  int v17; // edx
  int v18; // eax
  int v19; // edx
  char *v20; // edi
  char *v21; // esi
  CDispTri *m_pMemory; // ecx
  int v23; // eax
  int v24; // eax
  double v25; // st7
  int v26; // ecx
  double v27; // st7
  int v28; // eax
  float *v29; // ecx
  float v30; // xmm0_4
  float v31; // xmm2_4
  float v32; // xmm3_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  float z; // eax
  float *v37; // ecx
  int v38; // eax
  __int16 v39; // cx
  int v40; // eax
  float v41; // [esp-1Ch] [ebp-4Ch]
  Vector v42; // [esp-Ch] [ebp-3Ch] BYREF
  Vector v; // [esp+0h] [ebp-30h]
  CDispTri *pOutTris; // [esp+Ch] [ebp-24h]
  int nTriCount; // [esp+10h] [ebp-20h]
  int v46; // [esp+14h] [ebp-1Ch]
  float *v47; // [esp+18h] [ebp-18h]
  int iCurVert; // [esp+1Ch] [ebp-14h]
  int iCurTri; // [esp+20h] [ebp-10h]
  int v50; // [esp+24h] [ebp-Ch]
  int i; // [esp+28h] [ebp-8h]
  int retaddr; // [esp+30h] [ebp+0h]

  v50 = a1;
  i = retaddr;
  v1 = nummapdispinfo;
  v2 = nullptr;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  pOutTris = nullptr;
  v47 = nullptr;
  v46 = 0;
  iCurTri = 0;
  if ( nummapdispinfo >= 2 )
  {
    nTriCount = ((unsigned int)(nummapdispinfo - 2) >> 1) + 1;
    v6 = &unk_7933F8;
    iCurVert = 2 * nTriCount;
    do
    {
      v7 = 1 << *(v6 - 2636);
      v6 += 5272;
      v47 = (float *)((char *)v47 + (v7 + 1) * (v7 + 1));
      v3 += v7 * v7;
      v8 = 1 << *(v6 - 5272);
      v46 += (v8 + 1) * (v8 + 1);
      v9 = nTriCount-- == 1;
      v2 = &pOutTris[v8 * v8];
      pOutTris = v2;
    }
    while ( !v9 );
    v5 = iCurVert;
    v1 = nummapdispinfo;
  }
  if ( v5 < v1 )
  {
    v10 = *((_DWORD *)&unk_790AC8 + 2636 * v5);
    v4 = ((1 << v10) + 1) * ((1 << v10) + 1);
    iCurTri = 2 * (1 << v10) * (1 << v10);
    v1 = nummapdispinfo;
  }
  iCurTri += (int)&v2[v3];
  v11 = (int)v47 + v46 + v4;
  g_dispinfo.m_Size = 0;
  if ( g_dispinfo.m_Memory.m_nGrowSize < 0 )
  {
    m_nAllocationCount = g_dispinfo.m_Memory.m_nAllocationCount;
  }
  else
  {
    if ( g_dispinfo.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_dispinfo.m_Memory.m_pMemory);
      v1 = nummapdispinfo;
      g_dispinfo.m_Memory.m_pMemory = nullptr;
    }
    m_nAllocationCount = 0;
    g_dispinfo.m_Memory.m_nAllocationCount = 0;
  }
  g_dispinfo.m_pElements = g_dispinfo.m_Memory.m_pMemory;
  m_Size = 0;
  v14 = v1;
  g_dispinfo.m_Size = 0;
  if ( v1 != 0 )
  {
    if ( v1 > m_nAllocationCount )
    {
      CUtlMemory<ddispinfo_t,int>::Grow(this: &g_dispinfo.m_Memory, num: v1 - m_nAllocationCount);
      m_Size = g_dispinfo.m_Size;
    }
    g_dispinfo.m_Size = v14 + m_Size;
    g_dispinfo.m_pElements = g_dispinfo.m_Memory.m_pMemory;
    if ( m_Size > 0 && v14 > 0 )
      _V_memmove(dest: &g_dispinfo.m_Memory.m_pMemory[v14], src: g_dispinfo.m_Memory.m_pMemory, count: 176 * m_Size);
  }
  v15 = 0;
  g_DispVerts.m_Size = 0;
  if ( v11 != 0 )
  {
    if ( v11 > g_DispVerts.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CVertVisit,int>::Grow(
        this: (CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> *)&g_DispVerts,
        num: v11 - g_DispVerts.m_Memory.m_nAllocationCount);
      v15 = g_DispVerts.m_Size;
    }
    g_DispVerts.m_Size = v11 + v15;
    g_DispVerts.m_pElements = g_DispVerts.m_Memory.m_pMemory;
    if ( v15 > 0 && v11 > 0 )
      _V_memmove(dest: &g_DispVerts.m_Memory.m_pMemory[v11], src: g_DispVerts.m_Memory.m_pMemory, count: 20 * v15);
  }
  v16 = 0;
  g_DispTris.m_Size = 0;
  if ( iCurTri != 0 )
  {
    v17 = iCurTri;
    if ( iCurTri > g_DispTris.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CFaceMacroTextureInfo,int>::Grow(
        this: (CUtlMemory<short,int> *)&g_DispTris,
        num: iCurTri - g_DispTris.m_Memory.m_nAllocationCount);
      v16 = g_DispTris.m_Size;
      v17 = iCurTri;
    }
    g_DispTris.m_Size = v17 + v16;
    v18 = v17 + v16 - iCurTri;
    g_DispTris.m_pElements = g_DispTris.m_Memory.m_pMemory;
    if ( v18 > 0 && iCurTri > 0 )
      _V_memmove(dest: &g_DispTris.m_Memory.m_pMemory[iCurTri], src: g_DispTris.m_Memory.m_pMemory, count: 2 * v18);
  }
  v19 = 0;
  nTriCount = 0;
  v46 = 0;
  iCurVert = 0;
  if ( nummapdispinfo > 0 )
  {
    pOutTris = nullptr;
    v20 = (char *)&unk_790AF4;
    do
    {
      v21 = (char *)g_dispinfo.m_Memory.m_pMemory + (unsigned int)pOutTris;
      m_pMemory = g_DispTris.m_Memory.m_pMemory;
      LODWORD(v.y) = &g_DispVerts.m_Memory.m_pMemory[v19];
      v23 = v46;
      *((_DWORD *)v21 + 4) = v46;
      *((_DWORD *)v21 + 3) = v19;
      LODWORD(v.x) = &m_pMemory[v23];
      v24 = 1 << *((_DWORD *)v20 - 11);
      v19 = (v24 + 1) * (v24 + 1) + nTriCount;
      v46 += 2 * v24 * v24;
      *((_DWORD *)v21 + 5) = *((_DWORD *)v20 - 11);
      *((_DWORD *)v21 + 6) = *((_DWORD *)v20 + 2572) | 0x80000000;
      v25 = *((float *)v20 - 9);
      *((_WORD *)v21 + 18) = -2;
      *((float *)v21 + 7) = v25;
      *((_DWORD *)v21 + 8) = *((_DWORD *)v20 - 53);
      v26 = *((_DWORD *)v21 + 5);
      *(float *)v21 = *((float *)v20 - 2);
      v27 = *((float *)v20 - 1);
      nTriCount = v19;
      *((float *)v21 + 1) = v27;
      *((float *)v21 + 2) = *(float *)v20;
      v28 = ((1 << v26) + 1) * ((1 << v26) + 1);
      if ( v28 > 0 )
      {
        LODWORD(v.z) = LODWORD(v.y) + 8;
        v29 = (float *)(v20 + 2328);
        v47 = (float *)(v20 + 4);
        iCurTri = (int)(v20 + 2328);
        LODWORD(v.y) = v28;
        while ( 1 )
        {
          v30 = v47[290];
          v31 = *(v29 - 1) * v30;
          v32 = *v29 * v30;
          v33 = v29[865] + (float)(*(v29 - 2) * v30);
          v34 = v29[866] + v31;
          v35 = v29[867];
          v42.y = v34;
          v42.x = v33;
          v42.z = v35 + v32;
          v41 = fsqrt((float)((float)(v34 * v34) + (float)(v42.z * v42.z)) + (float)(v33 * v33));
          VectorNormalize(vec: &v42);
          z = v.z;
          v37 = v47;
          iCurTri += 12;
          *(Vector *)(LODWORD(v.z) - 8) = v42;
          *(float *)(LODWORD(z) + 4) = v41;
          *(float *)(LODWORD(z) + 8) = *v37;
          v9 = LODWORD(v.y)-- == 1;
          v47 = v37 + 1;
          LODWORD(v.z) = LODWORD(z) + 20;
          if ( v9 )
            break;
          v29 = (float *)iCurTri;
        }
        v19 = nTriCount;
      }
      v38 = 0;
      LODWORD(v.y) = 2 * (1 << *((_DWORD *)v21 + 5)) * (1 << *((_DWORD *)v21 + 5));
      if ( SLODWORD(v.y) > 0 )
      {
        v47 = (float *)(v20 + 9264);
        do
        {
          v39 = *(_WORD *)v47;
          v47 = (float *)((char *)v47 + 2);
          *(_WORD *)(LODWORD(v.x) + 2 * v38++) = v39;
        }
        while ( v38 < SLODWORD(v.y) );
      }
      v40 = iCurVert;
      pOutTris += 88;
      *((_DWORD *)v20 - 56) = iCurVert;
      v20 += 10544;
      iCurVert = v40 + 1;
    }
    while ( v40 + 1 < nummapdispinfo );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041FCD0
// Name: void SnapRemainingVertsToSurface(class CCoreDispInfo __near * __near *,class ddispinfo_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SnapRemainingVertsToSurface(CCoreDispInfo **ppListBase, ddispinfo_t *pBSPDispInfos, int listSize)
{
  Vector2D *v3; // ebx
  CCoreDispInfo *v4; // edi
  CCoreDispInfo_vtbl *v5; // edx
  const CPowerInfo *(__thiscall *GetPowerInfo)(struct CCoreDispInfo *); // eax
  int m_Power; // ecx
  bool *m_pMemory; // edx
  int v9; // esi
  int j; // eax
  int v11; // edx
  int v12; // ecx
  int m_Size; // eax
  int v14; // esi
  int v15; // edx
  int v16; // ecx
  int k; // eax
  float *p_x; // ecx
  int v19; // ecx
  int v20; // ebx
  int v21; // eax
  int v22; // esi
  int v23; // eax
  bool v24; // zf
  int v25; // ecx
  int v26; // edx
  CoreDispVert_t *m_pVerts; // eax
  int v28; // esi
  float y; // xmm1_4
  float z; // xmm2_4
  float v31; // xmm4_4
  float v32; // xmm5_4
  float *v33; // edx
  float v34; // xmm3_4
  float v35; // xmm6_4
  float *v36; // ecx
  float v37; // xmm0_4
  float v38; // xmm1_4
  int v39; // ecx
  float v40; // xmm7_4
  float v41; // xmm1_4
  float v42; // xmm2_4
  float v43; // xmm4_4
  float v44; // xmm5_4
  float v45; // xmm3_4
  float m_flDist; // xmm6_4
  float x; // xmm0_4
  CDispVert *v48; // eax
  float v49; // xmm1_4
  float v50; // xmm2_4
  float v51; // xmm0_4
  int p_m_Vert; // eax
  float v53; // xmm0_4
  int v54; // ecx
  int v55; // ecx
  unsigned __int16 *v56; // eax
  CVBSPTesselateHelper pHelper; // [esp+4h] [ebp-94h] BYREF
  float v58; // [esp+24h] [ebp-74h]
  float v59; // [esp+28h] [ebp-70h]
  float v60; // [esp+30h] [ebp-68h]
  float v61; // [esp+34h] [ebp-64h]
  float bcCoords; // [esp+38h] [ebp-60h] BYREF
  float v63; // [esp+3Ch] [ebp-5Ch]
  float v64; // [esp+40h] [ebp-58h]
  int v65; // [esp+44h] [ebp-54h]
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > v66; // [esp+48h] [ebp-50h] BYREF
  int m; // [esp+5Ch] [ebp-3Ch]
  CUtlMemory<bool,int> v68; // [esp+60h] [ebp-38h] BYREF
  unsigned int count; // [esp+6Ch] [ebp-2Ch]
  int v70; // [esp+70h] [ebp-28h]
  int pStartVert; // [esp+74h] [ebp-24h] BYREF
  int v72; // [esp+78h] [ebp-20h]
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > indices; // [esp+7Ch] [ebp-1Ch] BYREF
  int i; // [esp+90h] [ebp-8h]
  int *p_m_iDispVertStart; // [esp+94h] [ebp-4h]

  v3 = nullptr;
  i = 0;
  if ( listSize > 0 )
  {
    p_m_iDispVertStart = &pBSPDispInfos->m_iDispVertStart;
    while ( 1 )
    {
      v4 = ppListBase[i];
      v5 = v4->__vftable;
      pHelper.m_pIndices = &indices;
      GetPowerInfo = v5->GetPowerInfo;
      pHelper.m_pActiveVerts = v4->m_AllowedVerts.m_Ints;
      memset(&indices, 0, sizeof(indices));
      pHelper.m_pPowerInfo = GetPowerInfo(this: v4);
      pHelper.m_nIndices = 0;
      TesselateDisplacement_R<CVBSPTesselateHelper>(
        &pHelper,
        nodeIndex: &pHelper.m_pPowerInfo->m_RootNode,
        iNodeBitIndex: 0,
        iLevel: 0);
      m_Power = v4->m_Power;
      m_pMemory = nullptr;
      memset(&v68, 0, sizeof(v68));
      v9 = ((1 << m_Power) + 1) * ((1 << m_Power) + 1);
      v70 = 0;
      count = 0;
      if ( v9 != 0 )
      {
        if ( v9 > 0 )
        {
          CUtlMemory<bool,int>::Grow(this: &v68, num: ((1 << m_Power) + 1) * ((1 << m_Power) + 1));
          m_pMemory = v68.m_pMemory;
        }
        count += v9;
        if ( (int)(count - v9) > 0 && v9 > 0 )
        {
          _V_memmove(dest: &m_pMemory[v9], src: m_pMemory, count: count - v9);
          m_pMemory = v68.m_pMemory;
        }
      }
      memset(dst: (unsigned __int8 *)m_pMemory, value: 0, count);
      for ( j = 0; j < indices.m_Size; v68.m_pMemory[v11] = true )
        v11 = indices.m_Memory.m_pMemory[j++];
      v12 = v4->m_Power;
      m_Size = 0;
      memset(&v66, 0, sizeof(v66));
      v14 = ((1 << v12) + 1) * ((1 << v12) + 1);
      if ( v14 != 0 )
      {
        if ( v14 > 0 )
        {
          CUtlMemory<CacheOptimizedKDNode,int>::Grow(
            this: (CUtlMemory<ResourceEntryInfo,int> *)&v66,
            num: ((1 << v12) + 1) * ((1 << v12) + 1));
          m_Size = v66.m_Size;
          v3 = v66.m_Memory.m_pMemory;
        }
        v66.m_Size = v14 + m_Size;
        v66.m_pElements = v3;
        if ( m_Size > 0 && v14 > 0 )
          _V_memmove(dest: &v3[v14], src: v3, count: 8 * m_Size);
      }
      v15 = 0;
      v16 = (1 << v4->m_Power) + 1;
      if ( v16 > 0 )
      {
        do
        {
          for ( k = 0; k < v16; v16 = (1 << v4->m_Power) + 1 )
          {
            p_x = &v3[k + v15 * v16].x;
            *p_x = (float)k;
            p_x[1] = (float)v15;
            ++k;
          }
          ++v15;
          v16 = (1 << v4->m_Power) + 1;
        }
        while ( v15 < v16 );
      }
      v19 = v4->m_Power;
      v20 = 0;
      v72 = 0;
      v21 = (1 << v19) + 1;
      if ( v21 > 0 )
      {
        do
        {
          v22 = 0;
          for ( m = 0; v22 < v21; v21 = (1 << v54) + 1 )
          {
            v23 = v22 + v20 * v21;
            v24 = !v68.m_pMemory[v23];
            v65 = v23;
            if ( v24 )
            {
              pStartVert = -1;
              if ( FindEnclosingTri(
                     vert: &v66.m_Memory.m_pMemory[v23],
                     vertCoords: &v66,
                     &indices,
                     &pStartVert,
                     &bcCoords) != 0 )
              {
                v25 = indices.m_Memory.m_pMemory[pStartVert];
                v26 = indices.m_Memory.m_pMemory[pStartVert + 1];
                m_pVerts = v4->m_pVerts;
                v28 = indices.m_Memory.m_pMemory[pStartVert + 2];
                y = m_pVerts[v26].m_Vert.y;
                z = m_pVerts[v25].m_Vert.z;
                v31 = m_pVerts[v28].m_Vert.y * v64;
                v32 = m_pVerts[v28].m_Vert.z * v64;
                v33 = &m_pVerts[v26].m_Vert.x;
                v34 = m_pVerts[v28].m_Vert.x * v64;
                v35 = v63 * *v33;
                v36 = &m_pVerts[v25].m_Vert.x;
                v60 = y * v63;
                v37 = *v36;
                v61 = v33[2] * v63;
                v38 = v36[1];
                v39 = v65;
                v40 = (float)((float)(v37 * bcCoords) + v35) + v34;
                v41 = (float)((float)(v38 * bcCoords) + v60) + v31;
                v42 = (float)((float)(z * bcCoords) + v61) + v32;
                v43 = v41 - m_pVerts[v65].m_Vert.y;
                v44 = v42 - m_pVerts[v65].m_Vert.z;
                v45 = v40 - m_pVerts[v65].m_Vert.x;
                m_flDist = g_DispVerts.m_Memory.m_pMemory[v65 + *p_m_iDispVertStart].m_flDist;
                x = g_DispVerts.m_Memory.m_pMemory[v65 + *p_m_iDispVertStart].m_vVector.x;
                v48 = &g_DispVerts.m_Memory.m_pMemory[v65 + *p_m_iDispVertStart];
                v58 = v41;
                v49 = v48->m_vVector.y;
                v59 = v42;
                v50 = v48->m_vVector.z;
                v48->m_vVector.x = (float)(x * m_flDist) + v45;
                v48->m_flDist = 1.0;
                v51 = v58;
                v48->m_vVector.y = (float)(v49 * m_flDist) + v43;
                v48->m_vVector.z = (float)(v50 * m_flDist) + v44;
                p_m_Vert = (int)&v4->m_pVerts[v39].m_Vert;
                *(float *)(p_m_Vert + 4) = v51;
                v53 = v59;
                *(float *)p_m_Vert = v40;
                *(float *)(p_m_Vert + 8) = v53;
                v22 = m;
                v20 = v72;
              }
            }
            v54 = v4->m_Power;
            m = ++v22;
          }
          v55 = v4->m_Power;
          v72 = ++v20;
          v21 = (1 << v55) + 1;
        }
        while ( v20 < v21 );
      }
      if ( v66.m_Memory.m_nGrowSize >= 0 && v66.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v66.m_Memory.m_pMemory);
      if ( v68.m_nGrowSize >= 0 && v68.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v68.m_pMemory);
      v56 = indices.m_Memory.m_pMemory;
      indices.m_Size = 0;
      if ( indices.m_Memory.m_nGrowSize >= 0 )
      {
        if ( indices.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: indices.m_Memory.m_pMemory);
          v56 = nullptr;
          indices.m_Memory.m_pMemory = nullptr;
        }
        indices.m_Memory.m_nAllocationCount = 0;
      }
      indices.m_pElements = v56;
      if ( indices.m_Memory.m_nGrowSize >= 0 && v56 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v56);
      p_m_iDispVertStart += 44;
      if ( ++i >= listSize )
        break;
      v3 = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420130
// Name: void EmitDispLMAlphaAndNeighbors(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EmitDispLMAlphaAndNeighbors()
{
  int v0; // eax
  int v1; // ebx
  int v2; // edi
  CCoreDispInfo *v3; // eax
  CCoreDispInfo *v4; // ebx
  int v5; // eax
  int v6; // esi
  int v7; // eax
  int v8; // esi
  int m_Size; // ecx
  int v10; // esi
  void *v11; // esp
  __int16 *p_dispinfo; // esi
  __int16 v13; // ax
  int v14; // esi
  int v15; // eax
  int v16; // ebx
  int v17; // eax
  int v18; // edx
  __int16 *v19; // eax
  CCoreDispInfo **m_pMemory; // eax
  unsigned __int8 v21[12]; // [esp+0h] [ebp-24h] BYREF
  CUtlVector<dface_t *,CUtlMemory<dface_t *,int> > faces; // [esp+Ch] [ebp-18h] BYREF
  int *pSwappedTexInfos; // [esp+20h] [ebp-4h]
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  _Msg(a1: "Finding displacement neighbors...\n");
  v0 = nummapdispinfo;
  v1 = 0;
  v2 = 0;
  memset(&faces, 0, sizeof(faces));
  if ( nummapdispinfo <= 0 )
  {
LABEL_9:
    v8 = 0;
    if ( v0 > 0 )
    {
      do
      {
        CCoreDispInfo::SetDispUtilsHelperInfo(
          this: g_CoreDispInfos.m_Memory.m_pMemory[v8],
          ppListBase: g_CoreDispInfos.m_Memory.m_pMemory,
          listSize: v0);
        v0 = nummapdispinfo;
        ++v8;
      }
      while ( v8 < nummapdispinfo );
    }
    m_Size = 0;
    v10 = v0;
    faces.m_Size = 0;
    if ( v0 != 0 )
    {
      if ( v0 > 0 )
      {
        CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&faces, num: v0);
        m_Size = faces.m_Size;
      }
      if ( m_Size > 0 && v10 > 0 )
        _V_memmove(dest: &faces.m_Memory.m_pMemory[v10], src: faces.m_Memory.m_pMemory, count: 4 * m_Size);
    }
    v11 = alloca(4 * texinfo.m_Size);
    pSwappedTexInfos = (int *)v21;
    memset(dst: v21, value: 0xFFu, count: 4 * texinfo.m_Size);
    if ( numfaces > 0 )
    {
      p_dispinfo = &dfaces[0].dispinfo;
      do
      {
        v13 = *p_dispinfo;
        if ( *p_dispinfo != -1 )
        {
          g_dispinfo.m_Memory.m_pMemory[v13].m_iMapFace = v1;
          DispMapToCoreDispInfo(
            a1: (int)&savedregs,
            pMapDisp: (mapdispinfo_t *)&mapdispinfo + v13,
            pCoreDispInfo: g_CoreDispInfos.m_Memory.m_pMemory[*p_dispinfo],
            pFace: (dface_t *)(p_dispinfo - 6),
            pSwappedTexInfos);
          faces.m_Memory.m_pMemory[*p_dispinfo] = (dface_t *)(p_dispinfo - 6);
        }
        ++v1;
        p_dispinfo += 28;
      }
      while ( v1 < numfaces );
    }
    ExportNeighborData(
      ppListBase: g_CoreDispInfos.m_Memory.m_pMemory,
      pBSPDispInfos: g_dispinfo.m_Memory.m_pMemory,
      listSize: nummapdispinfo);
    ExportAllowedVertLists(
      ppListBase: g_CoreDispInfos.m_Memory.m_pMemory,
      pBSPDispInfos: g_dispinfo.m_Memory.m_pMemory,
      listSize: nummapdispinfo);
    SnapRemainingVertsToSurface(
      ppListBase: g_CoreDispInfos.m_Memory.m_pMemory,
      pBSPDispInfos: g_dispinfo.m_Memory.m_pMemory,
      listSize: nummapdispinfo);
    v14 = g_CoreDispInfos.m_Size;
    v15 = g_CoreDispTexInfos.m_Size;
    v16 = g_CoreDispTexInfos.m_Size;
    if ( g_CoreDispInfos.m_Size != 0 )
    {
      if ( g_CoreDispTexInfos.m_Size + g_CoreDispInfos.m_Size > g_CoreDispTexInfos.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<HemiLightData_t *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&g_CoreDispTexInfos,
          num: g_CoreDispInfos.m_Size + g_CoreDispTexInfos.m_Size - g_CoreDispTexInfos.m_Memory.m_nAllocationCount);
        v15 = g_CoreDispTexInfos.m_Size;
      }
      g_CoreDispTexInfos.m_Size = v14 + v15;
      v17 = v15 - v16;
      g_CoreDispTexInfos.m_pElements = g_CoreDispTexInfos.m_Memory.m_pMemory;
      if ( v17 > 0 && v14 > 0 )
        _V_memmove(
          dest: &g_CoreDispTexInfos.m_Memory.m_pMemory[v14 + v16],
          src: &g_CoreDispTexInfos.m_Memory.m_pMemory[v16],
          count: 4 * v17);
    }
    v18 = 0;
    if ( numfaces > 0 )
    {
      v19 = &dfaces[0].dispinfo;
      do
      {
        if ( *v19 != -1 )
          g_CoreDispTexInfos.m_Memory.m_pMemory[*v19] = *(v19 - 1);
        ++v18;
        v19 += 28;
      }
      while ( v18 < numfaces );
    }
    if ( faces.m_Memory.m_nGrowSize >= 0 && faces.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: faces.m_Memory.m_pMemory);
  }
  else
  {
    while ( 1 )
    {
      v3 = (CCoreDispInfo *)MemAlloc_Alloc(nSize: 0x34Cu);
      if ( v3 == nullptr )
        break;
      v4 = CCoreDispInfo::CCoreDispInfo(this: v3);
      if ( v4 == nullptr )
        break;
      v5 = g_CoreDispInfos.m_Size;
      v6 = g_CoreDispInfos.m_Size;
      if ( g_CoreDispInfos.m_Size + 1 > g_CoreDispInfos.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<HemiLightData_t *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&g_CoreDispInfos,
          num: g_CoreDispInfos.m_Size - g_CoreDispInfos.m_Memory.m_nAllocationCount + 1);
        v5 = g_CoreDispInfos.m_Size;
      }
      g_CoreDispInfos.m_Size = v5 + 1;
      v7 = v5 - v6;
      g_CoreDispInfos.m_pElements = g_CoreDispInfos.m_Memory.m_pMemory;
      if ( v7 > 0 )
        _V_memmove(
          dest: &g_CoreDispInfos.m_Memory.m_pMemory[v6 + 1],
          src: &g_CoreDispInfos.m_Memory.m_pMemory[v6],
          count: 4 * v7);
      v4->m_nListIndex = v6;
      g_CoreDispInfos.m_Memory.m_pMemory[v6] = v4;
      v0 = nummapdispinfo;
      ++v2;
      v1 = 0;
      if ( v2 >= nummapdispinfo )
        goto LABEL_9;
    }
    m_pMemory = g_CoreDispInfos.m_Memory.m_pMemory;
    g_CoreDispInfos.m_Size = 0;
    if ( g_CoreDispInfos.m_Memory.m_nGrowSize >= 0 )
    {
      if ( g_CoreDispInfos.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_CoreDispInfos.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        g_CoreDispInfos.m_Memory.m_pMemory = nullptr;
      }
      g_CoreDispInfos.m_Memory.m_nAllocationCount = 0;
    }
    g_CoreDispInfos.m_pElements = m_pMemory;
  }
}
