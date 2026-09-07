// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vbsp/brushbsp.cpp
// Functions: 28
// ============================================================

#include "utils\vbsp\brushbsp.h"

//------------------------------------------------------------------------------
// Address: 0x00401190
// Name: void __near * MemAlloc_Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl MemAlloc_Alloc(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x004011B0
// Name: float VectorLength(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl VectorLength(const Vector *v)
{
  return fsqrt((float)((float)(v->x * v->x) + (float)(v->y * v->y)) + (float)(v->z * v->z));
}

//------------------------------------------------------------------------------
// Address: 0x00401210
// Name: public: class Vector Vector::operator*(float)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector::operator*(Vector *this, Vector *result, float fl)
{
  result->x = this->x * fl;
  result->y = this->y * fl;
  result->z = this->z * fl;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401250
// Name: void BoundBrush(struct bspbrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BoundBrush(bspbrush_t *brush)
{
  bspbrush_t *v1; // ebx
  winding_t *v2; // esi
  int v3; // edi
  int v4; // ebx
  int i; // [esp+4h] [ebp-8h]
  winding_t **p_winding; // [esp+8h] [ebp-4h]

  v1 = brush;
  ClearBounds(mins: &brush->mins, maxs: &brush->maxs);
  i = 0;
  if ( brush->numsides > 0 )
  {
    p_winding = &brush->sides[0].winding;
    do
    {
      v2 = *p_winding;
      if ( *p_winding != nullptr )
      {
        v3 = 0;
        if ( v2->numpoints > 0 )
        {
          v4 = 0;
          do
          {
            AddPointToBounds(v: &v2->p[v4], mins: &brush->mins, maxs: &brush->maxs);
            ++v3;
            ++v4;
          }
          while ( v3 < v2->numpoints );
          v1 = brush;
        }
      }
      p_winding += 23;
      ++i;
    }
    while ( i < v1->numsides );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004012D0
// Name: class Vector PointInsideBrush(struct bspbrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
Vector *__cdecl PointInsideBrush(Vector *result, bspbrush_t *brush)
{
  Vector *v2; // eax
  CMapFile *v3; // esi
  bool v4; // cl
  bspbrush_t *v5; // edx
  int numsides; // ebx
  int v7; // ecx
  float y; // xmm0_4
  float z; // xmm1_4
  side_t *v10; // edx
  unsigned int v11; // edi
  float v12; // xmm3_4
  float v13; // xmm6_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm6_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm6_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm6_4
  float v23; // xmm2_4
  float v24; // xmm5_4
  float v25; // xmm6_4
  side_t *v26; // edx
  int v27; // edi
  float v28; // xmm1_4
  float x; // xmm3_4
  float v30; // xmm4_4
  float v31; // xmm0_4
  int i; // [esp+0h] [ebp-8h]
  int k; // [esp+4h] [ebp-4h]
  bool bInside; // [esp+13h] [ebp+Bh]

  v2 = result;
  v3 = g_MainMap;
  *result = vec3_origin;
  v4 = false;
  k = 0;
  while ( !v4 )
  {
    v5 = brush;
    numsides = brush->numsides;
    v7 = 0;
    bInside = true;
    if ( numsides >= 4 )
    {
      y = v2->y;
      z = v2->z;
      v10 = &brush->sides[1];
      v11 = ((unsigned int)(numsides - 4) >> 2) + 1;
      i = 4 * v11;
      do
      {
        v12 = v3->mapplanes[v10[-1].planenum].normal.y;
        v13 = v3->mapplanes[v10[-1].planenum].normal.z;
        v14 = (float)((float)((float)(v12 * y) + (float)(v3->mapplanes[v10[-1].planenum].normal.x * v2->x))
                    + (float)(v13 * z))
            - v3->mapplanes[v10[-1].planenum].dist;
        if ( v14 < 0.0 )
        {
          bInside = false;
          v2->x = v2->x - (float)(v3->mapplanes[v10[-1].planenum].normal.x * v14);
          y = y - (float)(v12 * v14);
          z = z - (float)(v13 * v14);
        }
        v15 = v3->mapplanes[v10->planenum].normal.y;
        v16 = v3->mapplanes[v10->planenum].normal.z;
        v17 = (float)((float)((float)(v15 * y) + (float)(v3->mapplanes[v10->planenum].normal.x * v2->x))
                    + (float)(v16 * z))
            - v3->mapplanes[v10->planenum].dist;
        if ( v17 < 0.0 )
        {
          bInside = false;
          v2->x = v2->x - (float)(v3->mapplanes[v10->planenum].normal.x * v17);
          y = y - (float)(v15 * v17);
          z = z - (float)(v16 * v17);
        }
        v18 = v3->mapplanes[v10[1].planenum].normal.y;
        v19 = v3->mapplanes[v10[1].planenum].normal.z;
        v20 = (float)((float)((float)(v18 * y) + (float)(v3->mapplanes[v10[1].planenum].normal.x * v2->x))
                    + (float)(v19 * z))
            - v3->mapplanes[v10[1].planenum].dist;
        if ( v20 < 0.0 )
        {
          bInside = false;
          v2->x = v2->x - (float)(v3->mapplanes[v10[1].planenum].normal.x * v20);
          y = y - (float)(v18 * v20);
          z = z - (float)(v19 * v20);
        }
        v21 = v3->mapplanes[v10[2].planenum].normal.y;
        v22 = v3->mapplanes[v10[2].planenum].normal.z;
        v23 = (float)((float)((float)(v21 * y) + (float)(v3->mapplanes[v10[2].planenum].normal.x * v2->x))
                    + (float)(v22 * z))
            - v3->mapplanes[v10[2].planenum].dist;
        if ( v23 < 0.0 )
        {
          bInside = false;
          v2->x = v2->x - (float)(v3->mapplanes[v10[2].planenum].normal.x * v23);
          y = y - (float)(v21 * v23);
          z = z - (float)(v22 * v23);
        }
        v10 += 4;
        --v11;
      }
      while ( v11 != 0 );
      v7 = i;
      v5 = brush;
      v2->y = y;
      v2->z = z;
    }
    if ( v7 < numsides )
    {
      v24 = v2->y;
      v25 = v2->z;
      v26 = &v5->sides[v7];
      v27 = numsides - v7;
      do
      {
        v28 = v3->mapplanes[v26->planenum].normal.y;
        x = v3->mapplanes[v26->planenum].normal.x;
        v30 = v3->mapplanes[v26->planenum].normal.z;
        v31 = (float)((float)((float)(v2->x * x) + (float)(v28 * v24)) + (float)(v30 * v25))
            - v3->mapplanes[v26->planenum].dist;
        if ( v31 < 0.0 )
        {
          bInside = false;
          v2->x = v2->x - (float)(x * v31);
          v24 = v24 - (float)(v28 * v31);
          v25 = v25 - (float)(v30 * v31);
        }
        ++v26;
        --v27;
      }
      while ( v27 != 0 );
      v2->y = v24;
      v2->z = v25;
    }
    if ( ++k >= 4 )
      break;
    v4 = bInside;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x004015B0
// Name: void CreateBrushWindings(struct bspbrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateBrushWindings(winding_t *brush)
{
  bspbrush_t *v1; // ebx
  bool v2; // cc
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  side_t *sides; // esi
  bspbrush_t *v7; // eax
  int v8; // edi
  side_t *v9; // esi
  int v10; // eax
  Vector insidePoint; // [esp+14h] [ebp-2Ch] BYREF
  Vector offset; // [esp+20h] [ebp-20h]
  float v13; // [esp+2Ch] [ebp-14h]
  float v14; // [esp+30h] [ebp-10h]
  float v15; // [esp+34h] [ebp-Ch]
  side_t *v16; // [esp+38h] [ebp-8h]
  int i; // [esp+3Ch] [ebp-4h]

  v1 = (bspbrush_t *)brush;
  PointInsideBrush(result: &insidePoint, (bspbrush_t *)brush);
  v2 = v1->numsides <= 0;
  x = -insidePoint.x;
  y = -insidePoint.y;
  z = -insidePoint.z;
  offset.x = -insidePoint.x;
  offset.y = -insidePoint.y;
  offset.z = -insidePoint.z;
  i = 0;
  if ( !v2 )
  {
    v15 = -(float)-insidePoint.x;
    v14 = -(float)-insidePoint.y;
    sides = v1->sides;
    v13 = -z;
    v16 = v1->sides;
    while ( 1 )
    {
      v7 = (bspbrush_t *)BaseWindingForPlane(
                           normal: &g_MainMap->mapplanes[sides->planenum].normal,
                           dist: g_MainMap->mapplanes[sides->planenum].dist
                         + (float)((float)((float)(g_MainMap->mapplanes[sides->planenum].normal.y * y)
                                         + (float)(g_MainMap->mapplanes[sides->planenum].normal.x * x))
                                 + (float)(g_MainMap->mapplanes[sides->planenum].normal.z * z)));
      v8 = 0;
      brush = (winding_t *)v7;
      if ( v1->numsides > 0 )
      {
        v9 = v1->sides;
        do
        {
          if ( v7 == nullptr )
            break;
          if ( i != v8 && !v9->bevel )
          {
            ChopWindingInPlace(
              inout: &brush,
              normal: &g_MainMap->mapplanes[v9->planenum ^ 1].normal,
              dist: (float)((float)((float)(g_MainMap->mapplanes[v9->planenum ^ 1].normal.y * offset.y)
                            + (float)(g_MainMap->mapplanes[v9->planenum ^ 1].normal.x * offset.x))
                    + (float)(g_MainMap->mapplanes[v9->planenum ^ 1].normal.z * offset.z))
            + g_MainMap->mapplanes[v9->planenum ^ 1].dist,
              epsilon: 0.0);
            v7 = (bspbrush_t *)brush;
          }
          ++v8;
          ++v9;
        }
        while ( v8 < v1->numsides );
        sides = v16;
      }
      insidePoint.x = v15;
      insidePoint.y = v14;
      insidePoint.z = v13;
      TranslateWinding(pWinding: (winding_t *)v7, offset: &insidePoint);
      v10 = i;
      sides->winding = brush;
      ++sides;
      i = v10 + 1;
      v16 = sides;
      if ( v10 + 1 >= v1->numsides )
        break;
      x = offset.x;
      y = offset.y;
      z = offset.z;
    }
  }
  BoundBrush(brush: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00401780
// Name: float BrushVolume(struct bspbrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl BrushVolume(bspbrush_t *brush)
{
  int numsides; // ecx
  int v4; // esi
  winding_t **i; // eax
  float *p_x; // eax
  side_t *v7; // edi
  float corner; // [esp+4h] [ebp-10h]
  float corner_4; // [esp+8h] [ebp-Ch]
  float corner_8; // [esp+Ch] [ebp-8h]
  float d; // [esp+10h] [ebp-4h]
  float volume; // [esp+1Ch] [ebp+8h]

  if ( brush == nullptr )
    return 0.0;
  numsides = brush->numsides;
  v4 = 0;
  if ( numsides <= 0 )
    return 0.0;
  for ( i = &brush->sides[0].winding; *i == nullptr; i += 23 )
  {
    if ( ++v4 >= numsides )
      return 0.0;
  }
  p_x = &(*i)->p->x;
  corner = *p_x;
  corner_4 = p_x[1];
  corner_8 = p_x[2];
  volume = 0.0;
  if ( v4 < numsides )
  {
    v7 = &brush->sides[v4];
    do
    {
      if ( v7->winding != nullptr )
      {
        d = -(g_MainMap->mapplanes[v7->planenum].normal.y * corner_4
            + g_MainMap->mapplanes[v7->planenum].normal.x * corner
            + g_MainMap->mapplanes[v7->planenum].normal.z * corner_8
            - g_MainMap->mapplanes[v7->planenum].dist);
        volume = WindingArea(w: v7->winding) * d + volume;
      }
      ++v4;
      ++v7;
    }
    while ( v4 < brush->numsides );
  }
  return volume * 0.33333334;
}

//------------------------------------------------------------------------------
// Address: 0x00401850
// Name: int CountBrushList(struct bspbrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CountBrushList(bspbrush_t *brushes)
{
  bspbrush_t *v1; // ecx
  int result; // eax

  v1 = brushes;
  for ( result = 0; v1 != nullptr; ++result )
    v1 = v1->next;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401870
// Name: struct tree_t __near * AllocTree(void)
// Source: json
//------------------------------------------------------------------------------
tree_t *__cdecl AllocTree()
{
  void *v0; // esi

  v0 = MemAlloc_Alloc(nSize: 0x7Cu);
  memset(dst: (unsigned __int8 *)v0, value: 0, count: 0x7Cu);
  ClearBounds(mins: (Vector *)v0 + 8, maxs: (Vector *)v0 + 9);
  return (tree_t *)v0;
}

//------------------------------------------------------------------------------
// Address: 0x004018A0
// Name: struct node_t __near * AllocNode(void)
// Source: json
//------------------------------------------------------------------------------
node_t *__cdecl AllocNode()
{
  unsigned __int8 *v0; // esi
  int v1; // eax

  v0 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0x5Cu);
  memset(dst: v0, value: 0, count: 0x5Cu);
  v1 = s_NodeCount;
  *(_DWORD *)v0 = s_NodeCount;
  s_NodeCount = v1 + 1;
  *((_DWORD *)v0 + 22) = -1;
  return (node_t *)v0;
}

//------------------------------------------------------------------------------
// Address: 0x004018D0
// Name: struct bspbrush_t __near * AllocBrush(int)
// Source: json
//------------------------------------------------------------------------------
bspbrush_t *__cdecl AllocBrush(int numsides)
{
  unsigned __int8 *v1; // edi
  int v2; // eax
  bspbrush_t *result; // eax

  v1 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 92 * numsides + 48);
  memset(dst: v1, value: 0, count: 92 * numsides + 48);
  v2 = s_BrushId;
  *(_DWORD *)v1 = s_BrushId;
  s_BrushId = v2 + 1;
  result = (bspbrush_t *)v1;
  if ( numthreads == 1 )
    ++c_active_brushes;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401920
// Name: void FreeBrush(struct bspbrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FreeBrush(bspbrush_t *brushes)
{
  int v1; // esi
  winding_t **p_winding; // edi

  v1 = 0;
  if ( brushes->numsides > 0 )
  {
    p_winding = &brushes->sides[0].winding;
    do
    {
      if ( *p_winding != nullptr )
        FreeWinding(w: *p_winding);
      ++v1;
      p_winding += 23;
    }
    while ( v1 < brushes->numsides );
  }
  free(pMem: brushes);
  if ( numthreads == 1 )
    --c_active_brushes;
}

//------------------------------------------------------------------------------
// Address: 0x00401970
// Name: void FreeBrushList(struct bspbrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FreeBrushList(bspbrush_t *brushes)
{
  bspbrush_t *v1; // esi
  int v2; // edi
  winding_t **p_winding; // ebx
  bspbrush_t *next; // [esp+Ch] [ebp+8h]

  v1 = brushes;
  if ( brushes != nullptr )
  {
    do
    {
      v2 = 0;
      next = v1->next;
      if ( v1->numsides > 0 )
      {
        p_winding = &v1->sides[0].winding;
        do
        {
          if ( *p_winding != nullptr )
            FreeWinding(w: *p_winding);
          ++v2;
          p_winding += 23;
        }
        while ( v2 < v1->numsides );
      }
      free(pMem: v1);
      if ( numthreads == 1 )
        --c_active_brushes;
      v1 = next;
    }
    while ( next != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004019D0
// Name: struct bspbrush_t __near * CopyBrush(struct bspbrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
bspbrush_t *__cdecl CopyBrush(bspbrush_t *brush)
{
  unsigned int v2; // edi
  unsigned __int8 *v3; // ebx
  int v4; // eax
  bspbrush_t *result; // eax
  int v6; // ebx
  winding_t **p_winding; // edi
  bspbrush_t *brusha; // [esp+18h] [ebp+8h]

  v2 = 92 * brush->numsides + 48;
  v3 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v2);
  brusha = (bspbrush_t *)v3;
  memset(dst: v3, value: 0, count: v2);
  v4 = s_BrushId;
  *(_DWORD *)v3 = s_BrushId;
  s_BrushId = v4 + 1;
  if ( numthreads == 1 )
    ++c_active_brushes;
  memcpy(dst: v3, src: (unsigned __int8 *)brush, count: v2);
  result = (bspbrush_t *)v3;
  v6 = 0;
  if ( brush->numsides > 0 )
  {
    p_winding = &brush->sides[0].winding;
    do
    {
      if ( *p_winding != nullptr )
        *(winding_t **)((char *)p_winding + (char *)brusha - (char *)brush) = CopyWinding(w: *p_winding);
      ++v6;
      p_winding += 23;
    }
    while ( v6 < brush->numsides );
    return brusha;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401A60
// Name: struct node_t __near * PointInLeaf(struct node_t __near *,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
node_t *__cdecl PointInLeaf(node_t *node, Vector *point)
{
  node_t *result; // eax
  int i; // ecx
  unsigned int v4; // ecx
  int type; // edx
  float *v6; // ecx
  float v7; // xmm0_4

  result = node;
  for ( i = node->planenum; i != -1; i = result->planenum )
  {
    v4 = 3 * i;
    type = g_MainMap->mapplanes[v4 / 3].type;
    v6 = (float *)((char *)g_MainMap + 8 * v4);
    if ( type >= 3 )
      v7 = (float)((float)(v6[1] * point->y) + (float)(*v6 * point->x)) + (float)(v6[2] * point->z);
    else
      v7 = *(&point->x + type);
    if ( (float)(v7 - v6[3]) < 0.0 )
      result = result->children[1];
    else
      result = result->children[0];
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401AE0
// Name: int BrushBspBoxOnPlaneSide(class Vector const __near &,class Vector const __near &,struct dplane_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl BrushBspBoxOnPlaneSide(const Vector *mins, const Vector *maxs, dplane_t *plane)
{
  int type; // ecx
  float dist; // xmm0_4
  int result; // eax
  bool v6; // cc
  float v7; // xmm1_4
  float x; // xmm7_4
  float v9; // xmm1_4
  float y; // xmm6_4
  float v11; // xmm0_4
  float z; // xmm5_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float corners; // [esp+0h] [ebp-18h]

  type = plane->type;
  if ( type >= 3 )
  {
    if ( plane->normal.x >= 0.0 )
    {
      x = mins->x;
      v7 = maxs->x;
    }
    else
    {
      v7 = mins->x;
      x = maxs->x;
    }
    corners = v7;
    if ( plane->normal.y >= 0.0 )
    {
      y = mins->y;
      v9 = maxs->y;
    }
    else
    {
      v9 = mins->y;
      y = maxs->y;
    }
    if ( plane->normal.z >= 0.0 )
    {
      z = mins->z;
      v11 = maxs->z;
    }
    else
    {
      v11 = mins->z;
      z = maxs->z;
    }
    v13 = plane->normal.y;
    v14 = plane->normal.z;
    result = (float)((float)((float)((float)(plane->normal.x * corners) + (float)(v13 * v9)) + (float)(v14 * v11))
                   - plane->dist) >= 0.001;
    v6 = (float)((float)((float)((float)(plane->normal.x * x) + (float)(v13 * y)) + (float)(v14 * z)) - plane->dist) >= 0.001;
  }
  else
  {
    dist = plane->dist;
    result = *(&maxs->x + type) > dist + 0.001;
    v6 = dist - 0.001 <= *(&mins->x + type);
  }
  if ( !v6 )
    return result | 2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401C20
// Name: int TestBrushToPlanenum(struct bspbrush_t __near *,int,int __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl TestBrushToPlanenum(bspbrush_t *brush, int planenum, int *numsplits, int *hintsplit, int *epsilonbrush)
{
  bspbrush_t *v5; // edx
  int v6; // eax
  int v7; // edi
  side_t *sides; // ebx
  int v9; // esi
  plane_t *v10; // esi
  int type; // ecx
  float v12; // xmm0_4
  int v13; // ecx
  int result; // eax
  bool v15; // cc
  float v16; // xmm1_4
  float x; // xmm7_4
  float v18; // xmm1_4
  float y; // xmm6_4
  float v20; // xmm0_4
  float z; // xmm5_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float dist; // xmm4_4
  float v25; // xmm1_4
  bool *p_visible; // ecx
  int *v27; // eax
  int v28; // edi
  int v29; // ebx
  int v30; // edx
  int v31; // eax
  float v32; // xmm2_4
  float v33; // xmm3_4
  float v34; // xmm4_4
  float v35; // xmm5_4
  float *v36; // edx
  float *v37; // ecx
  unsigned int v38; // eax
  float v39; // xmm0_4
  float v40; // xmm0_4
  float v41; // xmm0_4
  float v42; // xmm0_4
  float v43; // xmm2_4
  float v44; // xmm3_4
  float v45; // xmm4_4
  float v46; // xmm5_4
  float *v47; // eax
  int v48; // edi
  float v49; // xmm0_4
  float v50; // [esp+Ch] [ebp-30h]
  int j; // [esp+24h] [ebp-18h]
  bool *v52; // [esp+28h] [ebp-14h]
  int i; // [esp+2Ch] [ebp-10h]
  int back; // [esp+30h] [ebp-Ch]
  int front; // [esp+34h] [ebp-8h]
  float d_back; // [esp+38h] [ebp-4h]

  v5 = brush;
  *numsplits = 0;
  v6 = planenum;
  v7 = 0;
  *hintsplit = 0;
  if ( brush->numsides <= 0 )
  {
LABEL_8:
    v10 = &g_MainMap->mapplanes[v6];
    type = v10->type;
    if ( type >= 3 )
    {
      if ( v10->normal.x >= 0.0 )
      {
        x = v5->mins.x;
        v16 = v5->maxs.x;
      }
      else
      {
        v16 = v5->mins.x;
        x = v5->maxs.x;
      }
      v50 = v16;
      if ( v10->normal.y >= 0.0 )
      {
        y = v5->mins.y;
        v18 = v5->maxs.y;
      }
      else
      {
        v18 = v5->mins.y;
        y = v5->maxs.y;
      }
      if ( v10->normal.z >= 0.0 )
      {
        z = v5->mins.z;
        v20 = v5->maxs.z;
      }
      else
      {
        v20 = v5->mins.z;
        z = v5->maxs.z;
      }
      v22 = v10->normal.y;
      v23 = v10->normal.z;
      dist = v10->dist;
      result = (float)((float)((float)((float)(v10->normal.x * v50) + (float)(v22 * v18)) + (float)(v23 * v20)) - dist) >= 0.001;
      v15 = (float)((float)((float)((float)(v10->normal.x * x) + (float)(v22 * y)) + (float)(v23 * z)) - dist) >= 0.001;
    }
    else
    {
      v12 = v10->dist;
      v13 = 4 * type;
      result = *(float *)((char *)&v5->maxs.x + v13) > v12 + 0.001;
      v15 = v12 - 0.001 <= *(float *)((char *)&v5->mins.x + v13);
    }
    if ( !v15 )
      result |= 2u;
    if ( result == 3 )
    {
      v25 = 0.0;
      d_back = 0.0;
      i = 0;
      if ( v5->numsides > 0 )
      {
        p_visible = &v5->sides[0].visible;
        v52 = &v5->sides[0].visible;
        do
        {
          if ( *((_DWORD *)p_visible - 6) != -1 && *p_visible )
          {
            v27 = *((int **)p_visible - 4);
            if ( v27 != nullptr )
            {
              v28 = *v27;
              v29 = 0;
              v30 = 0;
              back = 0;
              front = 0;
              if ( *v27 >= 4 )
              {
                v31 = v27[1];
                v32 = v10->normal.y;
                v33 = v10->normal.x;
                v34 = v10->normal.z;
                v35 = v10->dist;
                v36 = (float *)(v31 + 8);
                v37 = (float *)(v31 + 20);
                v38 = ((unsigned int)(v28 - 4) >> 2) + 1;
                j = 4 * v38;
                do
                {
                  v39 = (float)((float)((float)(*(v36 - 1) * v32) + (float)(*(v36 - 2) * v33)) + (float)(v34 * *v36))
                      - v35;
                  if ( v39 > v25 )
                    v25 = (float)((float)((float)(*(v36 - 1) * v32) + (float)(*(v36 - 2) * v33)) + (float)(v34 * *v36))
                        - v35;
                  if ( d_back > v39 )
                    d_back = (float)((float)((float)(*(v36 - 1) * v32) + (float)(*(v36 - 2) * v33)) + (float)(v34 * *v36))
                           - v35;
                  if ( v39 > 0.1 )
                    front = 1;
                  if ( v39 < -0.1 )
                    back = 1;
                  v40 = (float)((float)((float)(*(v37 - 1) * v32) + (float)(v36[1] * v33)) + (float)(v34 * *v37)) - v35;
                  if ( v40 > v25 )
                    v25 = (float)((float)((float)(*(v37 - 1) * v32) + (float)(v36[1] * v33)) + (float)(v34 * *v37))
                        - v35;
                  if ( d_back > v40 )
                    d_back = (float)((float)((float)(*(v37 - 1) * v32) + (float)(v36[1] * v33)) + (float)(v34 * *v37))
                           - v35;
                  if ( v40 > 0.1 )
                    front = 1;
                  if ( v40 < -0.1 )
                    back = 1;
                  v41 = (float)((float)((float)(v37[2] * v32) + (float)(v36[4] * v33)) + (float)(v37[3] * v34)) - v35;
                  if ( v41 > v25 )
                    v25 = (float)((float)((float)(v37[2] * v32) + (float)(v36[4] * v33)) + (float)(v37[3] * v34)) - v35;
                  if ( d_back > v41 )
                    d_back = (float)((float)((float)(v37[2] * v32) + (float)(v36[4] * v33)) + (float)(v37[3] * v34))
                           - v35;
                  if ( v41 > 0.1 )
                    front = 1;
                  if ( v41 < -0.1 )
                    back = 1;
                  v42 = (float)((float)((float)(v37[5] * v32) + (float)(v36[7] * v33)) + (float)(v37[6] * v34)) - v35;
                  if ( v42 > v25 )
                    v25 = (float)((float)((float)(v37[5] * v32) + (float)(v36[7] * v33)) + (float)(v37[6] * v34)) - v35;
                  if ( d_back > v42 )
                    d_back = (float)((float)((float)(v37[5] * v32) + (float)(v36[7] * v33)) + (float)(v37[6] * v34))
                           - v35;
                  if ( v42 > 0.1 )
                    front = 1;
                  if ( v42 < -0.1 )
                    back = 1;
                  v36 += 12;
                  v37 += 12;
                  --v38;
                }
                while ( v38 != 0 );
                p_visible = v52;
                v30 = j;
                v29 = front;
              }
              if ( v30 < v28 )
              {
                v47 = (float *)(*(_DWORD *)(*((_DWORD *)p_visible - 4) + 4) + 12 * v30);
                v29 = front;
                v48 = v28 - v30;
                do
                {
                  v43 = v10->normal.y;
                  v44 = v10->normal.x;
                  v45 = v10->normal.z;
                  v46 = v10->dist;
                  v49 = (float)((float)((float)(v47[1] * v43) + (float)(v10->normal.x * *v47)) + (float)(v47[2] * v45))
                      - v46;
                  if ( v49 > v25 )
                    v25 = (float)((float)((float)(v47[1] * v43) + (float)(v44 * *v47)) + (float)(v47[2] * v45)) - v46;
                  if ( d_back > v49 )
                    d_back = (float)((float)((float)(v47[1] * v43) + (float)(v44 * *v47)) + (float)(v47[2] * v45)) - v46;
                  if ( v49 > 0.1 )
                    v29 = 1;
                  if ( v49 < -0.1 )
                    back = 1;
                  v47 += 3;
                  --v48;
                }
                while ( v48 != 0 );
              }
              if ( v29 != 0 && back != 0 && (*((_DWORD *)p_visible - 1) & 0x200) == 0 )
              {
                ++*numsplits;
                if ( (*((_DWORD *)p_visible - 1) & 0x100) != 0 )
                  *hintsplit = 1;
              }
            }
          }
          p_visible += 92;
          ++i;
          v52 = p_visible;
        }
        while ( i < brush->numsides );
        if ( v25 > 0.0 && v25 < 1.0 || d_back < 0.0 && d_back > -1.0 )
          ++*epsilonbrush;
      }
      return 3;
    }
  }
  else
  {
    sides = brush->sides;
    while ( 1 )
    {
      v9 = sides->planenum;
      if ( sides->planenum >= 0x10000 )
      {
        _Error(a1: "bad planenum");
        v5 = brush;
        v6 = planenum;
      }
      if ( v9 == v6 )
        return 6;
      if ( v9 == (v6 ^ 1) )
        return 5;
      ++v7;
      ++sides;
      if ( v7 >= v5->numsides )
        goto LABEL_8;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00402140
// Name: int WindingIsTiny(struct winding_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl WindingIsTiny(winding_t *w)
{
  int numpoints; // esi
  int v2; // edx
  Vector *p; // edi
  float *i; // ecx
  int v5; // eax
  int v6; // eax
  float v7; // xmm0_4
  int v9; // [esp-4h] [ebp-10h]

  numpoints = w->numpoints;
  v2 = 0;
  v9 = 0;
  if ( w->numpoints <= 0 )
    return 1;
  p = w->p;
  for ( i = &p->z; ; i += 3 )
  {
    v5 = v2 == numpoints - 1 ? 0 : v2 + 1;
    v6 = v5;
    v7 = p[v6].x - *(i - 2);
    if ( fsqrt(
           (float)((float)((float)(p[v6].y - *(i - 1)) * (float)(p[v6].y - *(i - 1)))
                 + (float)((float)(p[v6].z - *i) * (float)(p[v6].z - *i)))
         + (float)(v7 * v7)) > 0.2
      && ++v9 == 3 )
    {
      break;
    }
    if ( ++v2 >= numpoints )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00402210
// Name: void LeafNode(struct node_t __near *,struct bspbrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LeafNode(node_t *node, bspbrush_t *brushes)
{
  bspbrush_t *v2; // edx
  bspbrush_t *v3; // esi
  int contents; // ebx
  int numsides; // ecx
  int v6; // eax
  int *p_texinfo; // edx

  v2 = brushes;
  node->planenum = -1;
  node->contents = 0;
  v3 = brushes;
  if ( brushes != nullptr )
  {
    while ( 1 )
    {
      contents = v3->original->contents;
      if ( (contents & 1) != 0 )
      {
        numsides = v3->numsides;
        v6 = 0;
        if ( numsides > 0 )
        {
          p_texinfo = &v3->sides[0].texinfo;
          do
          {
            if ( *p_texinfo != -1 )
              break;
            ++v6;
            p_texinfo += 23;
          }
          while ( v6 < numsides );
          v2 = brushes;
        }
        if ( v6 == numsides )
          break;
      }
      node->contents |= contents;
      v3 = v3->next;
      if ( v3 == nullptr )
      {
        node->brushlist = v2;
        return;
      }
    }
    node->contents = 1;
  }
  node->brushlist = v2;
}

//------------------------------------------------------------------------------
// Address: 0x00402280
// Name: void RemoveAreaPortalBrushes_R(struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemoveAreaPortalBrushes_R(node_t *node)
{
  node_t *i; // esi
  bspbrush_t *brushlist; // eax
  bspbrush_t **j; // ecx
  mapbrush_t *original; // esi
  bspbrush_t **p_next; // eax

  for ( i = node; i->planenum != -1; i = i->children[1] )
    RemoveAreaPortalBrushes_R(node: i->children[0]);
  brushlist = i->brushlist;
  for ( j = &i->brushlist; brushlist != nullptr; brushlist = *p_next )
  {
    original = brushlist->original;
    p_next = &brushlist->next;
    if ( original->contents == 0x8000 )
      *j = *p_next;
    else
      j = p_next;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004022D0
// Name: int BrushMostlyOnSide(struct bspbrush_t __near *,struct plane_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl BrushMostlyOnSide(bspbrush_t *brush, plane_t *plane)
{
  int numsides; // ecx
  float v3; // xmm0_4
  int result; // eax
  winding_t **p_winding; // edx
  winding_t *v6; // ecx
  int numpoints; // ebx
  int v8; // edx
  Vector *p; // ecx
  float y; // xmm2_4
  float x; // xmm3_4
  float z; // xmm4_4
  float dist; // xmm5_4
  float *p_z; // esi
  float *v15; // edx
  unsigned int v16; // ecx
  float v17; // xmm1_4
  float v18; // xmm1_4
  float v19; // xmm1_4
  float v20; // xmm1_4
  float v21; // xmm1_4
  float v22; // xmm1_4
  float v23; // xmm1_4
  float v24; // xmm1_4
  float *p_x; // ecx
  int v26; // ebx
  float v27; // xmm1_4
  float v28; // xmm1_4
  bool v29; // zf
  int j; // [esp+0h] [ebp-Ch]
  int v31; // [esp+4h] [ebp-8h]
  int side; // [esp+8h] [ebp-4h]
  winding_t **brusha; // [esp+14h] [ebp+8h]

  numsides = brush->numsides;
  v3 = 0.0;
  result = 1;
  side = 1;
  if ( numsides > 0 )
  {
    p_winding = &brush->sides[0].winding;
    brusha = &brush->sides[0].winding;
    v31 = numsides;
    do
    {
      v6 = *p_winding;
      if ( *p_winding != nullptr )
      {
        numpoints = v6->numpoints;
        v8 = 0;
        if ( v6->numpoints >= 4 )
        {
          p = v6->p;
          y = plane->normal.y;
          x = plane->normal.x;
          z = plane->normal.z;
          dist = plane->dist;
          p_z = &p->z;
          v15 = &p[1].z;
          v16 = ((unsigned int)(numpoints - 4) >> 2) + 1;
          j = 4 * v16;
          result = side;
          do
          {
            v17 = (float)((float)((float)(*(p_z - 2) * x) + (float)(*(p_z - 1) * y)) + (float)(z * *p_z)) - dist;
            if ( v17 > v3 )
            {
              v3 = (float)((float)((float)(*(p_z - 2) * x) + (float)(*(p_z - 1) * y)) + (float)(z * *p_z)) - dist;
              result = 1;
            }
            v18 = -v17;
            if ( v18 > v3 )
            {
              v3 = v18;
              result = 2;
            }
            v19 = (float)((float)((float)(*(v15 - 1) * y) + (float)(p_z[1] * x)) + (float)(z * *v15)) - dist;
            if ( v19 > v3 )
            {
              v3 = (float)((float)((float)(*(v15 - 1) * y) + (float)(p_z[1] * x)) + (float)(z * *v15)) - dist;
              result = 1;
            }
            v20 = -v19;
            if ( v20 > v3 )
            {
              v3 = v20;
              result = 2;
            }
            v21 = (float)((float)((float)(v15[2] * y) + (float)(p_z[4] * x)) + (float)(v15[3] * z)) - dist;
            if ( v21 > v3 )
            {
              v3 = (float)((float)((float)(v15[2] * y) + (float)(p_z[4] * x)) + (float)(v15[3] * z)) - dist;
              result = 1;
            }
            v22 = -v21;
            if ( v22 > v3 )
            {
              v3 = v22;
              result = 2;
            }
            v23 = (float)((float)((float)(v15[5] * y) + (float)(p_z[7] * x)) + (float)(v15[6] * z)) - dist;
            if ( v23 > v3 )
            {
              v3 = (float)((float)((float)(v15[5] * y) + (float)(p_z[7] * x)) + (float)(v15[6] * z)) - dist;
              result = 1;
            }
            v24 = -v23;
            if ( v24 > v3 )
            {
              v3 = v24;
              result = 2;
            }
            p_z += 12;
            v15 += 12;
            --v16;
          }
          while ( v16 != 0 );
          v8 = j;
          side = result;
        }
        if ( v8 < numpoints )
        {
          p_x = &(*brusha)->p[v8].x;
          v26 = numpoints - v8;
          do
          {
            v27 = (float)((float)((float)(p_x[1] * plane->normal.y) + (float)(*p_x * plane->normal.x))
                        + (float)(p_x[2] * plane->normal.z))
                - plane->dist;
            if ( v27 > v3 )
            {
              v3 = (float)((float)((float)(p_x[1] * plane->normal.y) + (float)(*p_x * plane->normal.x))
                         + (float)(p_x[2] * plane->normal.z))
                 - plane->dist;
              result = 1;
            }
            v28 = -v27;
            if ( v28 > v3 )
            {
              v3 = v28;
              result = 2;
            }
            p_x += 3;
            --v26;
          }
          while ( v26 != 0 );
          side = result;
        }
      }
      p_winding = brusha + 23;
      v29 = v31-- == 1;
      brusha += 23;
    }
    while ( !v29 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00402510
// Name: struct bspbrush_t __near * BrushFromBounds(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
bspbrush_t *__cdecl BrushFromBounds(Vector *mins, Vector *maxs)
{
  bspbrush_t *v2; // edi
  int v3; // eax
  int v4; // esi
  side_t *v5; // edi
  CMapFile *v6; // ecx
  int FloatPlane; // eax
  int v8; // ecx
  bspbrush_t *v9; // esi
  Vector normal; // [esp+10h] [ebp-14h] BYREF
  bspbrush_t *brush; // [esp+1Ch] [ebp-8h]
  int v13; // [esp+20h] [ebp-4h]

  v2 = (bspbrush_t *)MemAlloc_Alloc(nSize: 0x258u);
  brush = v2;
  memset(dst: (unsigned __int8 *)v2, value: 0, count: sizeof(bspbrush_t));
  v3 = s_BrushId;
  v2->id = s_BrushId;
  s_BrushId = v3 + 1;
  if ( numthreads == 1 )
    ++c_active_brushes;
  v2->numsides = 6;
  v4 = 0;
  v5 = &v2->sides[3];
  v13 = (char *)mins - (char *)&normal;
  do
  {
    memset(&normal, 0, sizeof(normal));
    v6 = g_MainMap;
    *((_DWORD *)&normal.x + v4) = 1065353216;
    FloatPlane = CMapFile::FindFloatPlane(
                   this: v6,
                   &normal,
                   dist: *(float *)((char *)&normal.x + 4 * v4 + (char *)maxs - (char *)&normal));
    v8 = v13;
    v5[-3].planenum = FloatPlane;
    *((_DWORD *)&normal.x + v4) = -1082130432;
    v5->planenum = CMapFile::FindFloatPlane(
                     this: g_MainMap,
                     &normal,
                     dist: COERCE_FLOAT(*(_DWORD *)((char *)&normal.x + 4 * v4++ + v8) ^ _mask__NegFloat_));
    ++v5;
  }
  while ( v4 < 3 );
  v9 = brush;
  CreateBrushWindings((winding_t *)brush);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x00402620
// Name: public: struct side_t __near & side_t::operator=(struct side_t const __near &)
// Source: json
//------------------------------------------------------------------------------
side_t *__thiscall side_t::operator=(side_t *this, const side_t *__that)
{
  int i; // eax
  int j; // eax
  const side_t *__thata; // [esp+14h] [ebp+8h]
  const side_t *__thatb; // [esp+14h] [ebp+8h]

  this->planenum = __that->planenum;
  this->texinfo = __that->texinfo;
  this->pMapDisp = __that->pMapDisp;
  this->winding = __that->winding;
  this->original = __that->original;
  this->contents = __that->contents;
  this->surf = __that->surf;
  this->visible = __that->visible;
  this->tested = __that->tested;
  this->bevel = __that->bevel;
  this->thin = __that->thin;
  this->next = __that->next;
  this->origIndex = __that->origIndex;
  this->id = __that->id;
  this->smoothingGroups = __that->smoothingGroups;
  __thata = (const side_t *)__that->aOverlayIds.m_Size;
  this->aOverlayIds.m_Size = 0;
  CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&this->aOverlayIds,
    elem: 0,
    num: (int)__thata);
  for ( i = 0; i < (int)__thata; ++i )
    this->aOverlayIds.m_Memory.m_pMemory[i] = __that->aOverlayIds.m_Memory.m_pMemory[i];
  __thatb = (const side_t *)__that->aWaterOverlayIds.m_Size;
  this->aWaterOverlayIds.m_Size = 0;
  CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&this->aWaterOverlayIds,
    elem: 0,
    num: (int)__thatb);
  for ( j = 0; j < (int)__thatb; ++j )
    this->aWaterOverlayIds.m_Memory.m_pMemory[j] = __that->aWaterOverlayIds.m_Memory.m_pMemory[j];
  this->m_bDynamicShadowsEnabled = __that->m_bDynamicShadowsEnabled;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00402700
// Name: void SplitBrush(struct bspbrush_t __near *,int,struct bspbrush_t __near * __near *,struct bspbrush_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SplitBrush(bspbrush_t *brush, int planenum, bspbrush_t **front, bspbrush_t **back)
{
  plane_t *v4; // ebx
  winding_t *numsides; // eax
  float v6; // xmm6_4
  winding_t *v7; // eax
  int numpoints; // esi
  int v9; // edi
  float y; // xmm2_4
  float x; // xmm3_4
  float z; // xmm4_4
  float dist; // xmm5_4
  Vector *p; // eax
  float *p_z; // edx
  float *v16; // ecx
  unsigned int v17; // eax
  float v18; // xmm0_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm5_4
  Vector *v26; // eax
  int v27; // esi
  float v28; // xmm0_4
  float v29; // xmm2_4
  float v30; // xmm0_4
  winding_t *v31; // eax
  int v32; // esi
  side_t *sides; // edi
  const Vector *p_normal; // eax
  int v35; // edx
  Vector *v36; // esi
  int v37; // eax
  float *p_x; // ecx
  unsigned int v39; // esi
  unsigned __int8 *v40; // edi
  int v41; // eax
  int v42; // eax
  bspbrush_t *v43; // ecx
  mapbrush_t *original; // edx
  bool v45; // cc
  winding_t *winding; // eax
  int j; // edi
  int v48; // eax
  side_t *v49; // esi
  int v50; // ebx
  bspbrush_t *v51; // edi
  int v52; // esi
  float *v53; // eax
  int v54; // esi
  winding_t **p_winding; // ebx
  float v56; // ebx
  int k; // edi
  int v58; // eax
  int v59; // esi
  int v60; // ebx
  bspbrush_t *v61; // esi
  int v62; // edi
  winding_t **v63; // ebx
  float v64; // edx
  int v65; // esi
  winding_t **v66; // edi
  int v67; // esi
  float v68; // ebx
  winding_t **v69; // edi
  int v70; // eax
  Vector offset; // [esp+20h] [ebp-30h] BYREF
  winding_t *cw[2]; // [esp+2Ch] [ebp-24h] BYREF
  Vector v73; // [esp+34h] [ebp-1Ch] BYREF
  winding_t *midwinding; // [esp+40h] [ebp-10h]
  side_t *__that; // [esp+44h] [ebp-Ch]
  int i; // [esp+48h] [ebp-8h]
  winding_t *w; // [esp+4Ch] [ebp-4h] BYREF
  bspbrush_t *brusha; // [esp+58h] [ebp+8h]

  *back = nullptr;
  *front = nullptr;
  v4 = &g_MainMap->mapplanes[planenum];
  numsides = (winding_t *)brush->numsides;
  *(float *)&i = 0.0;
  v6 = 0.0;
  if ( (int)numsides > 0 )
  {
    __that = (side_t *)&brush->sides[0].winding;
    for ( midwinding = numsides; midwinding != nullptr; midwinding = (winding_t *)((char *)midwinding - 1) )
    {
      v7 = (winding_t *)__that->planenum;
      w = v7;
      if ( v7 != nullptr )
      {
        numpoints = v7->numpoints;
        v9 = 0;
        if ( v7->numpoints >= 4 )
        {
          y = v4->normal.y;
          x = v4->normal.x;
          z = v4->normal.z;
          dist = v4->dist;
          p = v7->p;
          p_z = &p->z;
          v16 = &p[1].z;
          v17 = ((unsigned int)(numpoints - 4) >> 2) + 1;
          v9 = 4 * v17;
          do
          {
            v18 = (float)((float)((float)(*(p_z - 2) * x) + (float)(*(p_z - 1) * y)) + (float)(z * *p_z)) - dist;
            if ( v18 > 0.0 && v18 > v6 )
              v6 = (float)((float)((float)(*(p_z - 2) * x) + (float)(*(p_z - 1) * y)) + (float)(z * *p_z)) - dist;
            if ( v18 < 0.0 && *(float *)&i > v18 )
              *(float *)&i = (float)((float)((float)(*(p_z - 2) * x) + (float)(*(p_z - 1) * y)) + (float)(z * *p_z))
                           - dist;
            v19 = (float)((float)((float)(p_z[1] * x) + (float)(*(v16 - 1) * y)) + (float)(z * *v16)) - dist;
            if ( v19 > 0.0 && v19 > v6 )
              v6 = (float)((float)((float)(p_z[1] * x) + (float)(*(v16 - 1) * y)) + (float)(z * *v16)) - dist;
            if ( v19 < 0.0 && *(float *)&i > v19 )
              *(float *)&i = (float)((float)((float)(p_z[1] * x) + (float)(*(v16 - 1) * y)) + (float)(z * *v16)) - dist;
            v20 = (float)((float)((float)(p_z[4] * x) + (float)(v16[2] * y)) + (float)(v16[3] * z)) - dist;
            if ( v20 > 0.0 && v20 > v6 )
              v6 = (float)((float)((float)(p_z[4] * x) + (float)(v16[2] * y)) + (float)(v16[3] * z)) - dist;
            if ( v20 < 0.0 && *(float *)&i > v20 )
              *(float *)&i = (float)((float)((float)(p_z[4] * x) + (float)(v16[2] * y)) + (float)(v16[3] * z)) - dist;
            v21 = (float)((float)((float)(p_z[7] * x) + (float)(v16[5] * y)) + (float)(v16[6] * z)) - dist;
            if ( v21 > 0.0 && v21 > v6 )
              v6 = (float)((float)((float)(p_z[7] * x) + (float)(v16[5] * y)) + (float)(v16[6] * z)) - dist;
            if ( v21 < 0.0 && *(float *)&i > v21 )
              *(float *)&i = (float)((float)((float)(p_z[7] * x) + (float)(v16[5] * y)) + (float)(v16[6] * z)) - dist;
            p_z += 12;
            v16 += 12;
            --v17;
          }
          while ( v17 != 0 );
        }
        if ( v9 < numpoints )
        {
          v22 = v4->normal.y;
          v23 = v4->normal.x;
          v24 = v4->normal.z;
          v25 = v4->dist;
          v26 = &w->p[v9];
          v27 = numpoints - v9;
          do
          {
            v28 = (float)((float)((float)(v26->y * v22) + (float)(v23 * v26->x)) + (float)(v26->z * v24)) - v25;
            if ( v28 > 0.0 && v28 > v6 )
              v6 = (float)((float)((float)(v26->y * v22) + (float)(v23 * v26->x)) + (float)(v26->z * v24)) - v25;
            if ( v28 < 0.0 && *(float *)&i > v28 )
              *(float *)&i = (float)((float)((float)(v26->y * v22) + (float)(v23 * v26->x)) + (float)(v26->z * v24))
                           - v25;
            ++v26;
            --v27;
          }
          while ( v27 != 0 );
        }
      }
      ++__that;
    }
  }
  if ( v6 < 0.1 )
    goto LABEL_130;
  if ( *(float *)&i > -0.1 )
  {
    *front = CopyBrush(brush);
    return;
  }
  v29 = brush->maxs.z + brush->mins.z;
  v30 = (float)(brush->maxs.x + brush->mins.x) * -0.5;
  offset.y = (float)(brush->maxs.y + brush->mins.y) * -0.5;
  offset.x = v30;
  offset.z = v29 * -0.5;
  v31 = BaseWindingForPlane(
          normal: &v4->normal,
          dist: (float)((float)((float)(v4->normal.y * offset.y) + (float)(v4->normal.x * v30))
                + (float)(v4->normal.z * (float)(v29 * -0.5)))
        + v4->dist);
  v32 = 0;
  w = v31;
  if ( brush->numsides > 0 )
  {
    sides = brush->sides;
    while ( v31 != nullptr )
    {
      p_normal = &g_MainMap->mapplanes[sides->planenum ^ 1].normal;
      ChopWindingInPlace(
        inout: &w,
        normal: p_normal,
        dist: (float)((float)((float)(p_normal->y * offset.y) + (float)(p_normal->x * offset.x))
              + (float)(p_normal->z * offset.z))
      + p_normal[1].x,
        epsilon: 0.0);
      v31 = w;
      ++v32;
      ++sides;
      if ( v32 >= brush->numsides )
        goto LABEL_48;
    }
    goto LABEL_131;
  }
LABEL_48:
  if ( v31 == nullptr || WindingIsTiny(w: v31) != 0 )
  {
LABEL_131:
    v70 = BrushMostlyOnSide(brush, plane: v4);
    if ( v70 == 1 )
    {
      *front = CopyBrush(brush);
    }
    else if ( v70 == 2 )
    {
      *back = CopyBrush(brush);
    }
    return;
  }
  v35 = 0;
  if ( w->numpoints > 0 )
  {
    v36 = w->p;
    while ( 2 )
    {
      v37 = 0;
      p_x = &v36->x;
      do
      {
        if ( *p_x < -16384.0 || *p_x > 16384.0 )
        {
          qprintf(format: "WARNING: huge winding\n");
          goto LABEL_59;
        }
        ++v37;
        ++p_x;
      }
      while ( v37 < 3 );
      ++v35;
      ++v36;
      if ( v35 < w->numpoints )
        continue;
      break;
    }
  }
LABEL_59:
  v73.x = -offset.x;
  v73.y = -offset.y;
  v73.z = -offset.z;
  TranslateWinding(pWinding: w, offset: &v73);
  midwinding = w;
  *(float *)&i = 0.0;
  do
  {
    v39 = 92 * brush->numsides + 140;
    v40 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v39);
    memset(dst: v40, value: 0, count: v39);
    v41 = s_BrushId;
    *(_DWORD *)v40 = s_BrushId;
    s_BrushId = v41 + 1;
    if ( numthreads == 1 )
      ++c_active_brushes;
    v42 = i;
    v43 = brush;
    original = brush->original;
    *((_DWORD *)&v73.y + i) = v40;
    *((_DWORD *)v40 + 10) = original;
    i = v42 + 1;
  }
  while ( v42 + 1 < 2 );
  v45 = brush->numsides <= 0;
  *(float *)&i = 0.0;
  if ( !v45 )
  {
    __that = brush->sides;
    do
    {
      winding = __that->winding;
      w = winding;
      if ( winding != nullptr )
      {
        ClipWindingEpsilon_Offset(
          in: winding,
          normal: &v4->normal,
          dist: v4->dist,
          epsilon: 0.0,
          front: cw,
          back: &cw[1],
          &offset);
        for ( j = 0; j < 2; ++j )
        {
          if ( cw[j] != nullptr )
          {
            v48 = *(_DWORD *)((char *)&v73.y + j * 4);
            v49 = (side_t *)(92 * (*(_DWORD *)(v48 + 44))++ + v48 + 48);
            side_t::operator=(this: v49, __that);
            v49->winding = cw[j];
            v49->tested = false;
          }
        }
        v43 = brush;
      }
      ++__that;
      ++i;
    }
    while ( i < v43->numsides );
  }
  *(float *)&v50 = 0.0;
  *(float *)&i = 0.0;
  do
  {
    v51 = *((bspbrush_t **)&v73.y + v50);
    BoundBrush(brush: v51);
    v52 = 0;
    v53 = &v51->maxs.x;
    while ( *(v53 - 3) >= -16384.0 && *v53 <= 16384.0 )
    {
      ++v52;
      ++v53;
      if ( v52 >= 3 )
        goto LABEL_79;
    }
    qprintf(format: "bogus brush after clip\n");
LABEL_79:
    if ( v51->numsides < 3 || v52 < 3 )
    {
      v54 = 0;
      if ( v51->numsides > 0 )
      {
        p_winding = &v51->sides[0].winding;
        do
        {
          if ( *p_winding != nullptr )
            FreeWinding(w: *p_winding);
          ++v54;
          p_winding += 23;
        }
        while ( v54 < v51->numsides );
        v50 = i;
      }
      free(pMem: v51);
      if ( numthreads == 1 )
        --c_active_brushes;
      *((_DWORD *)&v73.y + v50) = 0;
    }
    i = ++v50;
  }
  while ( v50 < 2 );
  v56 = v73.y;
  if ( LODWORD(v73.y) != 0 )
  {
    if ( LODWORD(v73.z) != 0 )
    {
      for ( k = 0; k < 2; ++k )
      {
        v58 = *((_DWORD *)&v73.y + k);
        v59 = 92 * (*(_DWORD *)(v58 + 44))++ + v58 + 48;
        *(_DWORD *)v59 = planenum ^ k ^ 1;
        *(_DWORD *)(v59 + 4) = -1;
        *(_DWORD *)(v59 + 8) = 0;
        *(_WORD *)(v59 + 28) = 0;
        if ( k != 0 )
          *(_DWORD *)(v59 + 12) = midwinding;
        else
          *(_DWORD *)(v59 + 12) = CopyWinding(w: midwinding);
      }
      v60 = 0;
      brusha = nullptr;
      do
      {
        v61 = *((bspbrush_t **)&v73.y + v60);
        if ( BrushVolume(brush: v61) < 1.0 )
        {
          v62 = 0;
          if ( v61->numsides > 0 )
          {
            v63 = &v61->sides[0].winding;
            do
            {
              if ( *v63 != nullptr )
                FreeWinding(w: *v63);
              ++v62;
              v63 += 23;
            }
            while ( v62 < v61->numsides );
            v60 = (int)brusha;
          }
          free(pMem: v61);
          if ( numthreads == 1 )
            --c_active_brushes;
          *((_DWORD *)&v73.y + v60) = 0;
        }
        brusha = (bspbrush_t *)++v60;
      }
      while ( v60 < 2 );
      v64 = v73.z;
      *front = (bspbrush_t *)LODWORD(v73.y);
      *(float *)back = v64;
      return;
    }
  }
  else if ( LODWORD(v73.z) == 0 )
  {
    qprintf(format: "split removed brush\n");
    return;
  }
  qprintf(format: "split not on both sides\n");
  if ( v56 != 0.0 )
  {
    v65 = 0;
    if ( *(int *)(LODWORD(v56) + 44) > 0 )
    {
      v66 = (winding_t **)(LODWORD(v56) + 60);
      do
      {
        if ( *v66 != nullptr )
          FreeWinding(w: *v66);
        ++v65;
        v66 += 23;
      }
      while ( v65 < *(_DWORD *)(LODWORD(v56) + 44) );
    }
    free(pMem: (void *)LODWORD(v56));
    if ( numthreads == 1 )
      --c_active_brushes;
    *front = CopyBrush(brush);
  }
  if ( LODWORD(v73.z) != 0 )
  {
    v67 = 0;
    v68 = v73.z;
    if ( *(int *)(LODWORD(v73.z) + 44) > 0 )
    {
      v69 = (winding_t **)(LODWORD(v73.z) + 60);
      do
      {
        if ( *v69 != nullptr )
          FreeWinding(w: *v69);
        ++v67;
        v69 += 23;
      }
      while ( v67 < *(_DWORD *)(LODWORD(v68) + 44) );
    }
    free(pMem: (void *)LODWORD(v68));
    if ( numthreads == 1 )
      --c_active_brushes;
LABEL_130:
    *back = CopyBrush(brush);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402F20
// Name: void SplitBrushList(struct bspbrush_t __near *,struct node_t __near *,struct bspbrush_t __near * __near *,struct bspbrush_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SplitBrushList(bspbrush_t *brushes, node_t *node, bspbrush_t **front, bspbrush_t **back)
{
  bspbrush_t **v4; // eax
  bspbrush_t **v5; // edi
  bspbrush_t *v6; // esi
  int side; // ebx
  bspbrush_t *v8; // eax
  bspbrush_t **v9; // ecx
  bspbrush_t *v10; // eax
  bool v11; // zf
  int v12; // edx
  side_t *sides; // ecx
  bspbrush_t **v14; // ecx
  bspbrush_t *newbrush2; // [esp+8h] [ebp-8h] BYREF
  bspbrush_t *brush; // [esp+Ch] [ebp-4h]

  v4 = front;
  v5 = back;
  *back = nullptr;
  *v4 = nullptr;
  v6 = brushes;
  brush = brushes;
  if ( brushes != nullptr )
  {
    while ( 1 )
    {
      side = v6->side;
      if ( side == 3 )
        break;
      v10 = CopyBrush(brush: v6);
      brushes = v10;
      if ( (side & 4) != 0 )
      {
        v12 = 0;
        if ( v10->numsides > 0 )
        {
          sides = v10->sides;
          do
          {
            if ( (sides->planenum & 0xFFFFFFFE) == node->planenum )
              sides->texinfo = -1;
            ++v12;
            ++sides;
          }
          while ( v12 < v10->numsides );
          v6 = brush;
          v5 = back;
        }
      }
      if ( (side & 1) == 0 )
      {
        v11 = (side & 2) == 0;
LABEL_16:
        if ( !v11 )
        {
          v10->next = *v5;
          *v5 = v10;
        }
        goto LABEL_18;
      }
      v14 = front;
      v10->next = *front;
      *v14 = v10;
LABEL_18:
      v6 = v6->next;
      brush = v6;
      if ( v6 == nullptr )
        return;
    }
    SplitBrush(brush: v6, planenum: node->planenum, front: &brushes, back: &newbrush2);
    v8 = brushes;
    if ( brushes != nullptr )
    {
      v9 = front;
      brushes->next = *front;
      *v9 = v8;
    }
    v10 = newbrush2;
    v11 = newbrush2 == nullptr;
    goto LABEL_16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403000
// Name: struct side_t __near * SelectSplitSide(struct bspbrush_t __near *,struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
side_t *__cdecl SelectSplitSide(bspbrush_t *brushes, node_t *node)
{
  side_t *v2; // esi
  bspbrush_t *v3; // edx
  winding_t **p_winding; // eax
  node_t *parent; // esi
  unsigned int j; // edi
  bspbrush_t *v7; // ebx
  BOOL v8; // esi
  bspbrush_t *v9; // esi
  int v10; // ebx
  int v11; // ecx
  bool *p_tested; // eax
  unsigned int v13; // eax
  int v14; // eax
  winding_t *v15; // ecx
  bspbrush_t *v16; // eax
  bspbrush_t *k; // edx
  int v18; // eax
  bool *v19; // ecx
  int bsplits; // [esp+Ch] [ebp-3Ch] BYREF
  bspbrush_t *v22; // [esp+10h] [ebp-38h] BYREF
  bspbrush_t *v23; // [esp+14h] [ebp-34h] BYREF
  side_t *bestside; // [esp+18h] [ebp-30h]
  int i; // [esp+1Ch] [ebp-2Ch]
  int bestvalue; // [esp+20h] [ebp-28h]
  int hintsplit; // [esp+24h] [ebp-24h] BYREF
  int epsilonbrush; // [esp+28h] [ebp-20h] BYREF
  bspbrush_t *brush; // [esp+2Ch] [ebp-1Ch]
  int splits; // [esp+30h] [ebp-18h]
  int facing; // [esp+34h] [ebp-14h]
  int back; // [esp+38h] [ebp-10h]
  int front; // [esp+3Ch] [ebp-Ch]
  int pass; // [esp+40h] [ebp-8h]
  winding_t **v35; // [esp+44h] [ebp-4h]

  v2 = nullptr;
  hintsplit = 0;
  bestside = nullptr;
  bestvalue = -99999;
  pass = 0;
  while ( 1 )
  {
    brush = brushes;
    if ( brushes != nullptr )
    {
      do
      {
        v3 = brush;
        i = 0;
        if ( brush->numsides > 0 )
        {
          p_winding = &brush->sides[0].winding;
          v35 = &brush->sides[0].winding;
          do
          {
            if ( *((_BYTE *)p_winding + 18) == 0
              && *p_winding != nullptr
              && *(p_winding - 2) != (winding_t *)-1
              && *((_BYTE *)p_winding + 17) == 0
              && ((unsigned int)p_winding[3] & 0x200) == 0
              && pass < 1 == *((_BYTE *)p_winding + 16) )
            {
              parent = node->parent;
              for ( j = (unsigned int)*(p_winding - 3) & 0xFFFFFFFE; parent != nullptr; parent = parent->parent )
              {
                if ( parent->planenum == j )
                  _Error(a1: "Tried parent");
              }
              SplitBrush(brush: node->volume, planenum: j, front: &v23, back: &v22);
              v7 = v22;
              v8 = v23 != nullptr && v22 != nullptr;
              if ( v23 != nullptr )
                FreeBrush(brushes: v23);
              if ( v7 != nullptr )
                FreeBrush(brushes: v7);
              if ( v8 )
              {
                v9 = brushes;
                front = 0;
                back = 0;
                facing = 0;
                splits = 0;
                epsilonbrush = 0;
                do
                {
                  v10 = TestBrushToPlanenum(brush: v9, planenum: j, numsplits: &bsplits, &hintsplit, &epsilonbrush);
                  splits += bsplits;
                  if ( bsplits != 0 && (v10 & 4) != 0 )
                    _Error(a1: "PSIDE_FACING with splits");
                  v9->testside = v10;
                  if ( (v10 & 4) != 0 )
                  {
                    ++facing;
                    v11 = 0;
                    if ( v9->numsides > 0 )
                    {
                      p_tested = &v9->sides[0].tested;
                      do
                      {
                        if ( (*(_DWORD *)(p_tested - 29) & 0xFFFFFFFE) == j )
                          *p_tested = true;
                        ++v11;
                        p_tested += 92;
                      }
                      while ( v11 < v9->numsides );
                    }
                  }
                  if ( (v10 & 1) != 0 )
                    ++front;
                  if ( (v10 & 2) != 0 )
                    ++back;
                  v9 = v9->next;
                }
                while ( v9 != nullptr );
                v13 = 5 * (facing - splits) - abs32(front - back);
                if ( g_MainMap->mapplanes[j].type < 3 )
                  v13 += 5;
                v14 = -1000 * epsilonbrush + v13;
                v15 = v35[3];
                if ( ((unsigned __int8)v15 & 0x10) != 0 )
                  v14 -= 500;
                if ( hintsplit != 0 && ((unsigned __int16)v15 & 0x100) == 0 )
                  v14 = -9999999;
                if ( ((_BYTE)v35[2] & 0x30) != 0 )
                  v14 = (int)&unk_98967F;
                if ( v14 > bestvalue )
                {
                  bestvalue = v14;
                  v16 = brushes;
                  bestside = (side_t *)(v35 - 3);
                  do
                  {
                    v16->side = v16->testside;
                    v16 = v16->next;
                  }
                  while ( v16 != nullptr );
                }
              }
              p_winding = v35;
            }
            v3 = brush;
            p_winding += 23;
            ++i;
            v35 = p_winding;
          }
          while ( i < brush->numsides );
        }
        brush = v3->next;
      }
      while ( brush != nullptr );
      v2 = bestside;
      if ( bestside != nullptr )
        break;
    }
    if ( ++pass >= 2 )
      goto LABEL_60;
  }
  if ( pass > 0 && numthreads == 1 )
    ++c_nonvis;
LABEL_60:
  for ( k = brushes; k != nullptr; k = k->next )
  {
    v18 = 0;
    if ( k->numsides > 0 )
    {
      v19 = &k->sides[0].tested;
      do
      {
        *v19 = false;
        ++v18;
        v19 += 92;
      }
      while ( v18 < k->numsides );
    }
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x004032B0
// Name: struct node_t __near * BuildTree_r(struct node_t __near *,struct bspbrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
node_t *__cdecl BuildTree_r(node_t *node, bspbrush_t *brushes)
{
  side_t *v2; // eax
  node_t **v4; // ebx
  unsigned __int8 *v5; // esi
  int v6; // eax
  bool v7; // zf
  node_t **v8; // ebx
  int i; // esi
  bspbrush_t *children[2]; // [esp+0h] [ebp-Ch] BYREF
  int v11; // [esp+8h] [ebp-4h]

  if ( numthreads == 1 )
    ++c_nodes;
  v2 = SelectSplitSide(brushes, node);
  if ( v2 != nullptr )
  {
    node->side = v2;
    node->planenum = v2->planenum & 0xFFFFFFFE;
    SplitBrushList(brushes, node, front: children, back: &children[1]);
    FreeBrushList(brushes);
    v4 = node->children;
    v11 = 2;
    do
    {
      v5 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0x5Cu);
      memset(dst: v5, value: 0, count: 0x5Cu);
      v6 = s_NodeCount;
      *(_DWORD *)v5 = s_NodeCount;
      *((_DWORD *)v5 + 22) = -1;
      *((_DWORD *)v5 + 2) = node;
      *v4++ = (node_t *)v5;
      v7 = v11-- == 1;
      s_NodeCount = v6 + 1;
    }
    while ( !v7 );
    v8 = node->children;
    SplitBrush(
      brush: node->volume,
      planenum: node->planenum,
      front: &node->children[0]->volume,
      back: &node->children[1]->volume);
    for ( i = 0; i < 2; ++i )
    {
      *v8 = BuildTree_r(node: *v8, brushes: children[i]);
      ++v8;
    }
    return node;
  }
  else
  {
    node->side = nullptr;
    node->planenum = -1;
    LeafNode(node, brushes);
    return node;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004033C0
// Name: struct tree_t __near * BrushBSP(struct bspbrush_t __near *,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
tree_t *__cdecl BrushBSP(bspbrush_t *brushlist, Vector *mins, Vector *maxs)
{
  void *v3; // edi
  bspbrush_t *i; // esi
  int numsides; // ecx
  winding_t **p_winding; // eax
  unsigned __int8 *v7; // esi
  int v8; // eax
  int c_nonvisfaces; // [esp+Ch] [ebp-Ch]
  int c_faces; // [esp+10h] [ebp-8h]
  int c_brushes; // [esp+14h] [ebp-4h]

  qprintf(format: "--- BrushBSP ---\n");
  v3 = MemAlloc_Alloc(nSize: 0x7Cu);
  memset(dst: (unsigned __int8 *)v3, value: 0, count: 0x7Cu);
  ClearBounds(mins: (Vector *)v3 + 8, maxs: (Vector *)v3 + 9);
  c_faces = 0;
  c_nonvisfaces = 0;
  c_brushes = 0;
  for ( i = brushlist; i != nullptr; i = i->next )
  {
    ++c_brushes;
    if ( microvolume > BrushVolume(brush: i) )
      _Warning(a1: "Brush %i: WARNING, microbrush\n", i->original->id);
    numsides = i->numsides;
    if ( numsides > 0 )
    {
      p_winding = &i->sides[0].winding;
      do
      {
        if ( *((_BYTE *)p_winding + 18) == 0 && *p_winding != nullptr && *(p_winding - 2) != (winding_t *)-1 )
        {
          if ( *((_BYTE *)p_winding + 16) != 0 )
            ++c_faces;
          else
            ++c_nonvisfaces;
        }
        p_winding += 23;
        --numsides;
      }
      while ( numsides != 0 );
    }
    AddPointToBounds(v: &i->mins, mins: (Vector *)v3 + 8, maxs: (Vector *)v3 + 9);
    AddPointToBounds(v: &i->maxs, mins: (Vector *)v3 + 8, maxs: (Vector *)v3 + 9);
  }
  qprintf(format: "%5i brushes\n", c_brushes);
  qprintf(format: "%5i visible faces\n", c_faces);
  qprintf(format: "%5i nonvisible faces\n", c_nonvisfaces);
  c_nodes = 0;
  c_nonvis = 0;
  v7 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0x5Cu);
  memset(dst: v7, value: 0, count: 0x5Cu);
  v8 = s_NodeCount;
  *(_DWORD *)v7 = s_NodeCount;
  *((_DWORD *)v7 + 22) = -1;
  s_NodeCount = v8 + 1;
  *((_DWORD *)v7 + 9) = BrushFromBounds(mins, maxs);
  *(_DWORD *)v3 = v7;
  BuildTree_r(node: (node_t *)v7, brushes: brushlist);
  qprintf(format: "%5i visible nodes\n", c_nodes / 2 - c_nonvis);
  qprintf(format: "%5i nonvis nodes\n", c_nonvis);
  qprintf(format: "%5i leafs\n", (c_nodes + 1) / 2);
  return (tree_t *)v3;
}
