// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmap/detail.cpp
// Functions: 11
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00417060
// Name: void MergeBrush_r(struct node_t __near *,struct bspbrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MergeBrush_r(bspbrush_t *node, bspbrush_t *brush)
{
  bspbrush_t *v2; // edi
  int next; // eax
  bspbrush_t *v4; // eax
  bspbrush_t *v5; // esi
  bspbrush_t *back; // [esp+4h] [ebp-4h] BYREF

  v2 = node;
  next = (int)node->next;
  if ( next == -1 )
  {
    v4 = brush;
    if ( ((int)node->sides[0].original & 1) != 0 )
    {
      FreeBrush(brushes: brush);
    }
    else
    {
      brush->next = (bspbrush_t *)node->sides[0].pMapDisp;
      v2->sides[0].pMapDisp = (mapdispinfo_t *)v4;
    }
  }
  else
  {
    v5 = brush;
    SplitBrush(brush, planenum: next, front: &node, &back);
    FreeBrush(brushes: v5);
    if ( node != nullptr )
      MergeBrush_r(node: (node_t *)v2->numsides, brush: node);
    if ( back != nullptr )
      MergeBrush_r(node: (node_t *)v2->sides[0].planenum, brush: back);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004170E0
// Name: bool MergeFace_r(struct node_t __near *,struct face_t __near *,struct face_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl MergeFace_r(winding_t *node, face_t *face, face_t *original)
{
  node_t *v3; // esi
  int p; // eax
  bool v5; // bl
  face_t *v6; // edi
  leafface_t *v8; // eax
  plane_t *v9; // ecx
  winding_t *w; // eax
  winding_t *v11; // edx
  face_t *v12; // eax
  face_t *v13; // eax
  bool v14; // al
  float dist; // [esp+0h] [ebp-48h]
  face_t *v16; // [esp+10h] [ebp-38h]
  face_t *v17; // [esp+10h] [ebp-38h]
  Vector v18; // [esp+24h] [ebp-24h] BYREF
  Vector offset; // [esp+30h] [ebp-18h] BYREF
  winding_t *onwinding; // [esp+3Ch] [ebp-Ch] BYREF
  plane_t *plane; // [esp+40h] [ebp-8h]
  winding_t *backwinding; // [esp+44h] [ebp-4h] BYREF

  v3 = (node_t *)node;
  p = (int)node->p;
  v5 = false;
  v6 = face;
  if ( p == -1 )
  {
    if ( (node[4].numpoints & 1) != 0 )
    {
      FreeFace(f: face);
      return 0;
    }
    else
    {
      v8 = (leafface_t *)MemAlloc_Alloc(nSize: 8u);
      v8->pFace = original;
      v8->pNext = v3->leaffacelist;
      v3->leaffacelist = v8;
      FreeFace(f: v6);
      return 1;
    }
  }
  else
  {
    v9 = (plane_t *)(&mapplanes + 2 * p);
    w = face->w;
    plane = v9;
    WindingCenter(w, center: &offset);
    v18.x = -offset.x;
    v11 = v6->w;
    v18.y = -offset.y;
    dist = plane->dist;
    v18.z = -offset.z;
    ClassifyWindingEpsilon_Offset(
      in: v11,
      normal: &plane->normal,
      dist,
      epsilon: 0.001,
      front: &node,
      back: &backwinding,
      on: &onwinding,
      offset: &v18);
    if ( onwinding != nullptr )
    {
      if ( (float)((float)((float)(*(&mapplanes.y + 6 * v3->planenum) * *(&mapplanes.y + 6 * v6->planenum))
                         + (float)(*(&mapplanes.x + 6 * v3->planenum) * *(&mapplanes.x + 6 * v6->planenum)))
                 + (float)(*(&mapplanes.z + 6 * v3->planenum) * *(&mapplanes.z + 6 * v6->planenum))) <= 0.0 )
        backwinding = onwinding;
      else
        node = onwinding;
    }
    if ( node != nullptr )
    {
      v12 = NewFaceFromFace(f: v6);
      v16 = original;
      v12->w = node;
      v5 = MergeFace_r(node: v3->children[0], face: v12, original: v16);
    }
    if ( backwinding != nullptr )
    {
      v13 = NewFaceFromFace(f: v6);
      v17 = original;
      v13->w = backwinding;
      v14 = MergeFace_r(node: v3->children[1], face: v13, original: v17);
      if ( v5 || v14 )
        v5 = true;
    }
    FreeFace(f: v6);
    return v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004172B0
// Name: struct face_t __near * FilterFacesIntoTree(struct tree_t __near *,struct face_t __near *)
// Source: json
//------------------------------------------------------------------------------
face_t *__cdecl FilterFacesIntoTree(tree_t *out, face_t *pFaces)
{
  face_t *v2; // esi
  face_t *result; // eax
  face_t *v4; // ebx
  face_t *v5; // edi
  face_t *pLeafFaceList; // [esp+4h] [ebp-4h]

  v2 = pFaces;
  result = nullptr;
  pLeafFaceList = nullptr;
  if ( pFaces != nullptr )
  {
    do
    {
      if ( v2->merged == nullptr && v2->split[0] == nullptr && v2->split[1] == nullptr )
      {
        v4 = NewFaceFromFace(f: v2);
        v4->w = CopyWinding(w: v2->w);
        v5 = NewFaceFromFace(f: v2);
        v5->w = CopyWinding(w: v2->w);
        if ( MergeFace_r(node: (winding_t *)out->headnode, face: v4, original: v5) != 0 )
        {
          v5->portal = nullptr;
          v5->next = pLeafFaceList;
          pLeafFaceList = v5;
        }
        else
        {
          FreeFace(f: v5);
        }
      }
      v2 = v2->next;
    }
    while ( v2 != nullptr );
    return pLeafFaceList;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00417340
// Name: void TryMergeFaceList(struct face_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TryMergeFaceList(face_t **pFaceList)
{
  _DWORD *v1; // eax
  face_t *v2; // edi
  _DWORD *v3; // esi
  unsigned __int8 *v4; // ecx
  int v5; // edx
  int v6; // ebx
  face_t **v7; // esi
  face_t *v8; // eax
  face_t *next; // ecx
  int merged; // [esp+Ch] [ebp-8h]
  unsigned __int8 *pPlaneList; // [esp+10h] [ebp-4h]

  pPlaneList = (unsigned __int8 *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)nummapplanes >> 30 != 0 ? -1 : 4 * nummapplanes);
  memset(dst: pPlaneList, value: 0, count: 4 * nummapplanes);
  v1 = *pFaceList;
  v2 = nullptr;
  if ( *pFaceList != nullptr )
  {
    do
    {
      v3 = (_DWORD *)v1[1];
      if ( v1[2] != 0 || v1[3] != 0 || v1[4] != 0 )
      {
        _Error(a1: "Split face in merge list!");
      }
      else
      {
        v4 = &pPlaneList[4 * v1[9]];
        v1[1] = *(_DWORD *)v4;
        *(_DWORD *)v4 = v1;
      }
      v1 = v3;
    }
    while ( v3 != nullptr );
  }
  v5 = 0;
  v6 = 0;
  merged = 0;
  if ( nummapplanes > 0 )
  {
    v7 = (face_t **)pPlaneList;
    do
    {
      if ( *v7 != nullptr )
      {
        MergeFaceList(pList: v7);
        v5 = merged;
      }
      v8 = *v7;
      if ( *v7 != nullptr )
      {
        do
        {
          next = v8->next;
          if ( v8->merged != nullptr )
            ++v5;
          v8->next = v2;
          v2 = v8;
          v8 = next;
        }
        while ( next != nullptr );
        merged = v5;
      }
      ++v6;
      ++v7;
    }
    while ( v6 < nummapplanes );
    if ( v5 != 0 )
      _Msg(a1: "\nMerged %d detail faces...", v5);
  }
  free(pMem: pPlaneList);
  *pFaceList = v2;
}

//------------------------------------------------------------------------------
// Address: 0x00417440
// Name: void FilterBrushesIntoTree(struct tree_t __near *,struct bspbrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FilterBrushesIntoTree(tree_t *out, bspbrush_t *brushes)
{
  bspbrush_t *i; // ebx
  bspbrush_t *v3; // edi
  node_t *headnode; // esi
  int planenum; // eax
  bspbrush_t *back; // [esp+4h] [ebp-4h] BYREF

  for ( i = brushes; i != nullptr; i = i->next )
  {
    v3 = CopyBrush(brush: i);
    headnode = out->headnode;
    planenum = out->headnode->planenum;
    if ( planenum == -1 )
    {
      if ( (headnode->contents & 1) != 0 )
      {
        FreeBrush(brushes: v3);
      }
      else
      {
        v3->next = headnode->brushlist;
        headnode->brushlist = v3;
      }
    }
    else
    {
      SplitBrush(brush: v3, planenum, front: &brushes, &back);
      FreeBrush(brushes: v3);
      if ( brushes != nullptr )
        MergeBrush_r(node: (bspbrush_t *)headnode->children[0], brush: brushes);
      if ( back != nullptr )
        MergeBrush_r(node: (bspbrush_t *)headnode->children[1], brush: back);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004174E0
// Name: struct side_t __near * FindOriginalSide(struct mapbrush_t __near *,struct side_t __near *)
// Source: json
//------------------------------------------------------------------------------
side_t *__cdecl FindOriginalSide(mapbrush_t *mb, plane_t *pBspSide)
{
  float v2; // xmm1_4
  int x_low; // esi
  int numsides; // edi
  side_t *v5; // ebx
  int v6; // eax
  side_t *v7; // edx
  unsigned int v8; // ecx
  side_t *bestside; // [esp+0h] [ebp-4h]
  side_t *mba; // [esp+Ch] [ebp+8h]
  plane_t *p1; // [esp+10h] [ebp+Ch]

  v2 = 0.0;
  x_low = LODWORD(pBspSide->normal.x);
  numsides = mb->numsides;
  v5 = nullptr;
  v6 = 0;
  bestside = nullptr;
  p1 = (plane_t *)(&mapplanes + 2 * LODWORD(pBspSide->normal.x));
  if ( numsides > 0 )
  {
    mba = mb->original_sides;
    v7 = mba;
    do
    {
      if ( v7->bevel == 0 && v7->texinfo != -1 )
      {
        v8 = v7->planenum & 0xFFFFFFFE;
        if ( v8 == (x_low & 0xFFFFFFFE) )
          return &mba[v6];
        if ( (float)((float)((float)(*(&mapplanes.y + 6 * v8) * p1->normal.y)
                           + (float)(p1->normal.x * *(&mapplanes.x + 6 * v8)))
                   + (float)(*(&mapplanes.z + 6 * v8) * p1->normal.z)) > v2 )
        {
          v2 = (float)((float)(*(&mapplanes.y + 6 * v8) * p1->normal.y)
                     + (float)(p1->normal.x * *(&mapplanes.x + 6 * v8)))
             + (float)(*(&mapplanes.z + 6 * v8) * p1->normal.z);
          bestside = v7;
        }
      }
      ++v6;
      ++v7;
    }
    while ( v6 < numsides );
    v5 = bestside;
    if ( bestside != nullptr )
      return v5;
  }
  _Error(a1: "Bad detail brush side\n");
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004175B0
// Name: bool ClipFaceToBrush(struct face_t __near *,struct bspbrush_t __near *,struct face_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ClipFaceToBrush(face_t *pFace, winding_t *pbrush, face_t **pOutputList)
{
  face_t *v3; // esi
  winding_t *v4; // edi
  int next; // edx
  int v6; // ecx
  int *m_pMemory; // ebx
  unsigned int v8; // eax
  float v9; // xmm1_4
  float v10; // xmm2_4
  int m_Size; // esi
  _DWORD *p_numpoints; // eax
  int v13; // edi
  int *v14; // edi
  int v15; // ecx
  int v16; // eax
  Vector *v17; // eax
  face_t *v18; // eax
  face_t **v19; // ecx
  face_t **v20; // edi
  CUtlVector<int,CUtlMemory<int,int> > sortedSides; // [esp+20h] [ebp-30h] BYREF
  Vector offset; // [esp+34h] [ebp-1Ch] BYREF
  winding_t *backwinding; // [esp+40h] [ebp-10h] BYREF
  int foundSide; // [esp+44h] [ebp-Ch]
  face_t *f; // [esp+48h] [ebp-8h]
  int i; // [esp+4Ch] [ebp-4h]

  v3 = pFace;
  v4 = pbrush;
  next = (int)pbrush[2].next;
  v6 = 0;
  m_pMemory = nullptr;
  v8 = pFace->planenum & 0xFFFFFFFE;
  foundSide = -1;
  memset(&sortedSides, 0, sizeof(sortedSides));
  if ( next > 0 )
  {
    f = (face_t *)&pbrush[3];
    do
    {
      if ( foundSide >= 0 )
        break;
      if ( (f->id & 0xFFFFFFFE) == v8 )
        foundSide = v6;
      f = (face_t *)((char *)f + 100);
      ++v6;
    }
    while ( v6 < next );
    v3 = pFace;
  }
  v9 = (float)(*(float *)&pbrush->next + *(float *)&pbrush[1].maxpoints) * -0.5;
  v10 = (float)(*(float *)&pbrush[1].numpoints + *(float *)&pbrush[1].next) * -0.5;
  offset.x = (float)(*(float *)&pbrush->maxpoints + *(float *)&pbrush[1].p) * -0.5;
  offset.y = v9;
  offset.z = v10;
  f = NewFaceFromFace(f: v3);
  f->w = CopyWinding(w: v3->w);
  if ( foundSide < 0 )
    goto LABEL_45;
  m_Size = 0;
  sortedSides.m_Size = 0;
  i = 0;
  if ( (int)v4[2].next > 0 )
  {
    p_numpoints = &v4[3].numpoints;
    backwinding = v4 + 3;
    do
    {
      if ( p_numpoints[9] == 0 )
      {
        if ( dword_31FE378[6 * *p_numpoints] > 2 )
        {
          v13 = m_Size;
          if ( m_Size + 1 > sortedSides.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<HemiLightData_t *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&sortedSides,
              num: m_Size - sortedSides.m_Memory.m_nAllocationCount + 1);
            m_Size = sortedSides.m_Size;
            m_pMemory = sortedSides.m_Memory.m_pMemory;
          }
          sortedSides.m_Size = ++m_Size;
          sortedSides.m_pElements = m_pMemory;
          if ( m_Size - v13 - 1 > 0 )
            _V_memmove(dest: &m_pMemory[v13 + 1], src: &m_pMemory[v13], count: 4 * (m_Size - v13 - 1));
          v14 = &m_pMemory[v13];
          if ( v14 != nullptr )
            *v14 = i;
          v4 = pbrush;
        }
        else
        {
          if ( m_Size + 1 > sortedSides.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<HemiLightData_t *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&sortedSides,
              num: m_Size - sortedSides.m_Memory.m_nAllocationCount + 1);
            m_Size = sortedSides.m_Size;
            m_pMemory = sortedSides.m_Memory.m_pMemory;
          }
          sortedSides.m_Size = ++m_Size;
          sortedSides.m_pElements = m_pMemory;
          if ( m_Size - 1 > 0 )
            _V_memmove(dest: m_pMemory + 1, src: m_pMemory, count: 4 * (m_Size - 1));
          if ( m_pMemory != nullptr )
            *m_pMemory = i;
        }
      }
      p_numpoints = &backwinding[6].p;
      ++i;
      backwinding = (winding_t *)((char *)backwinding + 100);
    }
    while ( i < (int)v4[2].next );
  }
  v15 = 0;
  for ( i = 0; v15 < m_Size; i = ++v15 )
  {
    v16 = m_pMemory[v15];
    if ( v16 != foundSide )
    {
      v17 = &mapplanes + 2 * *(&v4[3].numpoints + 25 * v16);
      ClipWindingEpsilon_Offset(
        in: f->w,
        normal: v17,
        dist: v17[1].x,
        epsilon: 0.001,
        front: &pbrush,
        back: &backwinding,
        &offset);
      if ( backwinding == nullptr || WindingIsTiny(w: backwinding) != 0 )
      {
        v20 = pOutputList;
        FreeFaceList(pFaces: *pOutputList);
        *v20 = nullptr;
        break;
      }
      if ( pbrush != nullptr && WindingIsTiny(w: pbrush) == 0 )
      {
        v18 = NewFaceFromFace(f: pFace);
        v18->w = pbrush;
        v19 = pOutputList;
        v18->next = *pOutputList;
        *v19 = v18;
      }
      FreeWinding(w: f->w);
      v15 = i;
      f->w = backwinding;
    }
  }
  FreeFace(f);
  if ( *pOutputList != nullptr || i != m_Size )
  {
LABEL_45:
    if ( sortedSides.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return 0;
  }
  else
  {
    if ( sortedSides.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004178B0
// Name: int GetListOfCutBrushes(class CUtlVector<struct bspbrush_t __near *,class CUtlMemory<struct bspbrush_t __near *,int>> __near &,struct bspbrush_t __near *,struct bspbrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetListOfCutBrushes(
        CUtlVector<bspbrush_t *,CUtlMemory<bspbrush_t *,int> > *out,
        bspbrush_t *pSourceBrush,
        bspbrush_t *pBrushList)
{
  bspbrush_t *v3; // ebx
  bspbrush_t *v4; // edi
  int contents; // eax
  float *p_x; // eax
  int v7; // ecx
  float *v8; // edx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  bspbrush_t **m_pMemory; // ecx
  int v12; // eax
  bspbrush_t **v13; // edi
  mapbrush_t *mb; // [esp+8h] [ebp-4h]

  v3 = pBrushList;
  v4 = pSourceBrush;
  mb = pSourceBrush->original;
  if ( pBrushList == nullptr )
    return out->m_Size;
  while ( 1 )
  {
    if ( v3 != v4 )
    {
      contents = v3->original->contents;
      if ( ((contents & 0xA) == 0 || (mb->contents & 0xA) != 0) && (_BYTE)contents != 0 )
      {
        p_x = &v4->maxs.x;
        v7 = 0;
        v8 = &v3->mins.x;
        while ( *(p_x - 3) <= *(float *)((char *)p_x + (char *)v3 - (char *)pSourceBrush) && *v8 <= *p_x )
        {
          ++v7;
          ++p_x;
          ++v8;
          if ( v7 >= 3 )
          {
            m_Size = out->m_Size;
            m_nAllocationCount = out->m_Memory.m_nAllocationCount;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<HemiLightData_t *,int>::Grow(
                this: (CUtlMemory<S3RGBA,int> *)out,
                num: m_Size - m_nAllocationCount + 1);
            ++out->m_Size;
            m_pMemory = out->m_Memory.m_pMemory;
            v12 = out->m_Size - m_Size - 1;
            out->m_pElements = out->m_Memory.m_pMemory;
            if ( v12 > 0 )
              _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
            v13 = &out->m_Memory.m_pMemory[m_Size];
            if ( v13 != nullptr )
              *v13 = v3;
            break;
          }
        }
      }
    }
    v3 = v3->next;
    if ( v3 == nullptr )
      return out->m_Size;
    v4 = pSourceBrush;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004179A0
// Name: ClipFaceToBrushList
// Source: json
//------------------------------------------------------------------------------
void __usercall ClipFaceToBrushList(
        face_t *f@<eax>,
        const CUtlVector<bspbrush_t *,CUtlMemory<bspbrush_t *,int> > *cutBrushes,
        face_t **pOutputList)
{
  face_t *v4; // edi
  winding_t *v5; // eax
  const CUtlVector<bspbrush_t *,CUtlMemory<bspbrush_t *,int> > *v6; // ecx
  int v7; // eax
  char v8; // bl
  face_t *v9; // esi
  bool v10; // zf
  face_t *v11; // eax
  face_t *next; // ecx
  winding_t *cut; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  face_t *pClip; // [esp+Ch] [ebp-4h] BYREF

  *pOutputList = nullptr;
  if ( f->split[0] == nullptr )
  {
    v4 = NewFaceFromFace(f);
    v5 = CopyWinding(w: f->w);
    v6 = cutBrushes;
    v4->w = v5;
    v7 = 0;
    v4->next = nullptr;
    v8 = 0;
    i = 0;
    if ( cutBrushes->m_Size <= 0 )
      goto LABEL_15;
    do
    {
      cut = (winding_t *)v6->m_Memory.m_pMemory[v7];
      v9 = v4;
      if ( v4 != nullptr )
      {
        do
        {
          v10 = v9->split[0] == nullptr;
          pClip = nullptr;
          if ( v10 )
          {
            if ( ClipFaceToBrush(pFace: v9, pbrush: cut, pOutputList: &pClip) != 0 )
            {
              v8 = 1;
              v9->split[0] = v9;
            }
            else
            {
              v11 = pClip;
              if ( pClip != nullptr )
              {
                v8 = 1;
                v9->split[0] = v9;
                do
                {
                  next = v11->next;
                  v11->next = v4;
                  v4 = v11;
                  v11 = next;
                }
                while ( next != nullptr );
              }
            }
          }
          v9 = v9->next;
        }
        while ( v9 != nullptr );
        v7 = i;
        v6 = cutBrushes;
      }
      i = ++v7;
    }
    while ( v7 < v6->m_Size );
    if ( v8 != 0 )
      *pOutputList = v4;
    else
LABEL_15:
      FreeFaceList(pFaces: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417A80
// Name: struct face_t __near * ComputeVisibleBrushSides(struct bspbrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
face_t *__cdecl ComputeVisibleBrushSides(bspbrush_t *list)
{
  bspbrush_t *v1; // esi
  face_t *v2; // ecx
  bspbrush_t **m_pMemory; // eax
  mapbrush_t *original; // ecx
  face_t *v5; // ebx
  face_t *p_contents; // eax
  side_t *OriginalSide; // edi
  face_t *v8; // esi
  int contents; // eax
  face_t *v10; // esi
  face_t *v11; // eax
  face_t *v12; // ecx
  int v13; // edx
  face_t *next; // ecx
  face_t *v15; // esi
  CUtlVector<bspbrush_t *,CUtlMemory<bspbrush_t *,int> > cutBrushes; // [esp+8h] [ebp-2Ch] BYREF
  mapbrush_t *mb; // [esp+1Ch] [ebp-18h]
  winding_t *winding; // [esp+20h] [ebp-14h]
  face_t *pClip; // [esp+24h] [ebp-10h] BYREF
  int i; // [esp+28h] [ebp-Ch]
  face_t *pTotalFaces; // [esp+2Ch] [ebp-8h]
  bspbrush_t *pbrush; // [esp+30h] [ebp-4h]

  v1 = list;
  v2 = nullptr;
  m_pMemory = nullptr;
  pTotalFaces = nullptr;
  memset(&cutBrushes, 0, sizeof(cutBrushes));
  pbrush = list;
  if ( list != nullptr )
  {
    while ( 1 )
    {
      original = v1->original;
      v5 = nullptr;
      mb = original;
      if ( LOBYTE(original->contents) == 0 )
        goto LABEL_31;
      i = 0;
      if ( v1->numsides > 0 )
      {
        p_contents = (face_t *)&v1->sides[0].contents;
        pClip = (face_t *)&v1->sides[0].contents;
        do
        {
          winding = (winding_t *)p_contents[-1].numPrims;
          if ( winding != nullptr && LOBYTE(p_contents->id) != 0 )
          {
            OriginalSide = FindOriginalSide(mb: original, pBspSide: (plane_t *)&p_contents[-1].vertexnums[31]);
            v8 = AllocFace();
            v8->merged = nullptr;
            v8->split[1] = nullptr;
            v8->split[0] = nullptr;
            v8->w = CopyWinding(w: winding);
            v8->originalface = OriginalSide;
            v8->texinfo = OriginalSide->texinfo;
            original = mb;
            v8->dispinfo = -1;
            v8->planenum = OriginalSide->planenum;
            contents = OriginalSide->contents;
            v8->next = v5;
            v8->contents = contents;
            p_contents = pClip;
            v5 = v8;
            v1 = pbrush;
          }
          p_contents = (face_t *)((char *)p_contents + 100);
          ++i;
          pClip = p_contents;
        }
        while ( i < v1->numsides );
      }
      cutBrushes.m_Size = 0;
      if ( GetListOfCutBrushes(out: &cutBrushes, pSourceBrush: v1, pBrushList: list) != 0 )
      {
        v10 = v5;
        if ( v5 == nullptr )
          goto LABEL_30;
        do
        {
          pClip = nullptr;
          ClipFaceToBrushList(f: v10, &cutBrushes, pOutputList: &pClip);
          v11 = pClip;
          if ( pClip != nullptr )
          {
            v12 = pClip;
            v13 = 0;
            do
            {
              if ( v12->split[0] == nullptr )
                ++v13;
              v12 = v12->next;
            }
            while ( v12 != nullptr );
            if ( v13 > 1 )
            {
              FreeFaceList(pFaces: pClip);
            }
            else
            {
              v10->split[0] = v10;
              do
              {
                next = v11->next;
                v11->next = v5;
                v5 = v11;
                v11 = next;
              }
              while ( next != nullptr );
            }
          }
          v10 = v10->next;
        }
        while ( v10 != nullptr );
        v1 = pbrush;
      }
      if ( v5 != nullptr )
      {
        do
        {
          v15 = v5->next;
          if ( v5->split[0] != nullptr )
          {
            FreeFace(f: v5);
          }
          else
          {
            v5->next = pTotalFaces;
            pTotalFaces = v5;
          }
          v5 = v15;
        }
        while ( v15 != nullptr );
LABEL_30:
        v1 = pbrush;
      }
LABEL_31:
      pbrush = v1->next;
      if ( pbrush == nullptr )
      {
        m_pMemory = cutBrushes.m_Memory.m_pMemory;
        v2 = pTotalFaces;
        break;
      }
      v1 = pbrush;
    }
  }
  if ( cutBrushes.m_Memory.m_nGrowSize < 0 || m_pMemory == nullptr )
    return v2;
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return pTotalFaces;
}

//------------------------------------------------------------------------------
// Address: 0x00417C40
// Name: struct face_t __near * MergeDetailTree(struct tree_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
face_t *__cdecl MergeDetailTree(tree_t *worldtree, int brush_start, int brush_end)
{
  bspbrush_t *BspBrushList; // edi
  double v4; // st7
  double v5; // st7
  double v6; // st7
  double v8; // [esp+8h] [ebp-10h]
  int start; // [esp+10h] [ebp-8h]
  int starta; // [esp+10h] [ebp-8h]
  face_t *pFaces; // [esp+14h] [ebp-4h] BYREF

  pFaces = nullptr;
  BspBrushList = MakeBspBrushList(
                   startbrush: brush_start,
                   endbrush: brush_end,
                   clipmins: &map_mins,
                   clipmaxs: &map_maxs,
                   detailScreen: 1);
  if ( BspBrushList == nullptr )
    return nullptr;
  start = (int)_Plat_FloatTime();
  _Msg(a1: "Chop Details...");
  if ( nocsg == 0 )
    BspBrushList = ChopBrushes(head: BspBrushList);
  v8 = (double)start;
  v4 = _Plat_FloatTime() - v8;
  _Msg(a1: "done (%d)\n", (int)v4);
  _Msg(a1: "Find Visible Detail Sides...");
  pFaces = ComputeVisibleBrushSides(list: BspBrushList);
  TryMergeFaceList(pFaceList: &pFaces);
  SubdivideFaceList(pFaceList: &pFaces);
  v5 = _Plat_FloatTime() - v8;
  _Msg(a1: "done (%d)\n", (int)v5);
  starta = (int)_Plat_FloatTime();
  _Msg(a1: "Merging details...");
  HIDWORD(v8) = FilterFacesIntoTree(out: worldtree, pFaces);
  FilterBrushesIntoTree(out: worldtree, brushes: BspBrushList);
  FreeFaceList(pFaces);
  FreeBrushList(brushes: BspBrushList);
  v6 = _Plat_FloatTime() - (double)starta;
  _Msg(a1: "done (%d)\n", (int)v6);
  return (face_t *)HIDWORD(v8);
}
