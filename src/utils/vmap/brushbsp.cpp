// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmap/brushbsp.cpp
// Functions: 27
// ============================================================

#include "utils\vmap\brushbsp.h"

//------------------------------------------------------------------------------
// Address: 0x00413EB0
// Name: public: float __near & Vector::operator[](int)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector::operator[](Vector *this, int i)
{
  return (Vector *)((char *)this + 4 * i);
}

//------------------------------------------------------------------------------
// Address: 0x00413EC0
// Name: public: float Vector::operator[](int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall Vector::operator[](Vector *this, int i)
{
  return *(&this->x + i);
}

//------------------------------------------------------------------------------
// Address: 0x00413ED0
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
      p_winding += 25;
      ++i;
    }
    while ( i < v1->numsides );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413F50
// Name: class Vector PointInsideBrush(struct bspbrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
Vector *__cdecl PointInsideBrush(Vector *result, bspbrush_t *brush)
{
  Vector *v2; // eax
  char v3; // bl
  bspbrush_t *v4; // edx
  int numsides; // edi
  int v6; // ecx
  float y; // xmm0_4
  float z; // xmm1_4
  side_t *v9; // edx
  unsigned int v10; // esi
  float v11; // xmm3_4
  float v12; // xmm6_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm6_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm6_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm6_4
  float v22; // xmm2_4
  float v23; // xmm5_4
  float v24; // xmm6_4
  side_t *v25; // edx
  int v26; // edi
  float v27; // xmm1_4
  float v28; // xmm3_4
  float v29; // xmm4_4
  float v30; // xmm0_4
  int i; // [esp+0h] [ebp-4h]
  int k; // [esp+Ch] [ebp+8h]

  v2 = result;
  *result = vec3_origin;
  v3 = 0;
  for ( k = 0; k < 4; ++k )
  {
    if ( v3 != 0 )
      break;
    v4 = brush;
    numsides = brush->numsides;
    v6 = 0;
    v3 = 1;
    if ( numsides >= 4 )
    {
      y = v2->y;
      z = v2->z;
      v9 = &brush->sides[1];
      v10 = ((unsigned int)(numsides - 4) >> 2) + 1;
      i = 4 * v10;
      do
      {
        v11 = *(&mapplanes.y + 6 * v9[-1].planenum);
        v12 = *(&mapplanes.z + 6 * v9[-1].planenum);
        v13 = (float)((float)((float)(v11 * y) + (float)(*(&mapplanes.x + 6 * v9[-1].planenum) * v2->x))
                    + (float)(v12 * z))
            - *((float *)&mapplanes + 6 * v9[-1].planenum + 3);
        if ( v13 < 0.0 )
        {
          v3 = 0;
          v2->x = v2->x - (float)(*(&mapplanes.x + 6 * v9[-1].planenum) * v13);
          y = y - (float)(v11 * v13);
          z = z - (float)(v12 * v13);
        }
        v14 = *(&mapplanes.y + 6 * v9->planenum);
        v15 = *(&mapplanes.z + 6 * v9->planenum);
        v16 = (float)((float)((float)(v14 * y) + (float)(*(&mapplanes.x + 6 * v9->planenum) * v2->x)) + (float)(v15 * z))
            - *((float *)&mapplanes + 6 * v9->planenum + 3);
        if ( v16 < 0.0 )
        {
          v3 = 0;
          v2->x = v2->x - (float)(*(&mapplanes.x + 6 * v9->planenum) * v16);
          y = y - (float)(v14 * v16);
          z = z - (float)(v15 * v16);
        }
        v17 = *(&mapplanes.y + 6 * v9[1].planenum);
        v18 = *(&mapplanes.z + 6 * v9[1].planenum);
        v19 = (float)((float)((float)(v17 * y) + (float)(*(&mapplanes.x + 6 * v9[1].planenum) * v2->x))
                    + (float)(v18 * z))
            - *((float *)&mapplanes + 6 * v9[1].planenum + 3);
        if ( v19 < 0.0 )
        {
          v3 = 0;
          v2->x = v2->x - (float)(*(&mapplanes.x + 6 * v9[1].planenum) * v19);
          y = y - (float)(v17 * v19);
          z = z - (float)(v18 * v19);
        }
        v20 = *(&mapplanes.y + 6 * v9[2].planenum);
        v21 = *(&mapplanes.z + 6 * v9[2].planenum);
        v22 = (float)((float)((float)(v20 * y) + (float)(*(&mapplanes.x + 6 * v9[2].planenum) * v2->x))
                    + (float)(v21 * z))
            - *((float *)&mapplanes + 6 * v9[2].planenum + 3);
        if ( v22 < 0.0 )
        {
          v3 = 0;
          v2->x = v2->x - (float)(*(&mapplanes.x + 6 * v9[2].planenum) * v22);
          y = y - (float)(v20 * v22);
          z = z - (float)(v21 * v22);
        }
        v9 += 4;
        --v10;
      }
      while ( v10 != 0 );
      v6 = i;
      v4 = brush;
      v2->y = y;
      v2->z = z;
    }
    if ( v6 < numsides )
    {
      v23 = v2->y;
      v24 = v2->z;
      v25 = &v4->sides[v6];
      v26 = numsides - v6;
      do
      {
        v27 = *(&mapplanes.y + 6 * v25->planenum);
        v28 = *(&mapplanes.x + 6 * v25->planenum);
        v29 = *(&mapplanes.z + 6 * v25->planenum);
        v30 = (float)((float)((float)(v2->x * v28) + (float)(v27 * v23)) + (float)(v29 * v24))
            - *((float *)&mapplanes + 6 * v25->planenum + 3);
        if ( v30 < 0.0 )
        {
          v3 = 0;
          v2->x = v2->x - (float)(v28 * v30);
          v23 = v23 - (float)(v27 * v30);
          v24 = v24 - (float)(v29 * v30);
        }
        ++v25;
        --v26;
      }
      while ( v26 != 0 );
      v2->y = v23;
      v2->z = v24;
    }
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00414260
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
  Vector insidePoint; // [esp+14h] [ebp-2Ch] BYREF
  Vector offset; // [esp+20h] [ebp-20h]
  float v12; // [esp+2Ch] [ebp-14h]
  float v13; // [esp+30h] [ebp-10h]
  float v14; // [esp+34h] [ebp-Ch]
  side_t *v15; // [esp+38h] [ebp-8h]
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
    v14 = -(float)-insidePoint.x;
    v13 = -(float)-insidePoint.y;
    sides = v1->sides;
    v12 = -z;
    v15 = v1->sides;
    while ( 1 )
    {
      v7 = (bspbrush_t *)BaseWindingForPlane(
                           normal: &mapplanes + 2 * sides->planenum,
                           dist: *((float *)&mapplanes + 6 * sides->planenum + 3)
                         + (float)((float)((float)(*(&mapplanes.y + 6 * sides->planenum) * y)
                                         + (float)(*(&mapplanes.x + 6 * sides->planenum) * x))
                                 + (float)(*(&mapplanes.z + 6 * sides->planenum) * z)));
      v8 = 0;
      brush = (winding_t *)v7;
      if ( v1->numsides > 0 )
      {
        v9 = v1->sides;
        do
        {
          if ( v7 == nullptr )
            break;
          if ( i != v8 && v9->bevel == 0 )
          {
            ChopWindingInPlace(
              inout: &brush,
              normal: &mapplanes + 2 * (v9->planenum ^ 1),
              dist: (float)((float)((float)(*(&mapplanes.y + 6 * (v9->planenum ^ 1)) * offset.y)
                            + (float)(*(&mapplanes.x + 6 * (v9->planenum ^ 1)) * offset.x))
                    + (float)(*(&mapplanes.z + 6 * (v9->planenum ^ 1)) * offset.z))
            + *((float *)&mapplanes + 6 * (v9->planenum ^ 1) + 3),
              epsilon: 0.0);
            v7 = (bspbrush_t *)brush;
          }
          ++v8;
          ++v9;
        }
        while ( v8 < v1->numsides );
        sides = v15;
      }
      insidePoint.x = v14;
      insidePoint.y = v13;
      insidePoint.z = v12;
      TranslateWinding(pWinding: (winding_t *)v7, offset: &insidePoint);
      sides->winding = brush;
      ++sides;
      ++i;
      v15 = sides;
      if ( i >= v1->numsides )
        break;
      x = offset.x;
      y = offset.y;
      z = offset.z;
    }
  }
  BoundBrush(brush: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00414440
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
  for ( i = &brush->sides[0].winding; *i == nullptr; i += 25 )
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
        d = -(*(&mapplanes.y + 6 * v7->planenum) * corner_4
            + *(&mapplanes.x + 6 * v7->planenum) * corner
            + *(&mapplanes.z + 6 * v7->planenum) * corner_8
            - *((float *)&mapplanes + 6 * v7->planenum + 3));
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
// Address: 0x00414510
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
// Address: 0x00414530
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
// Address: 0x00414560
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
// Address: 0x00414590
// Name: struct bspbrush_t __near * AllocBrush(int)
// Source: json
//------------------------------------------------------------------------------
bspbrush_t *__cdecl AllocBrush(int numsides)
{
  unsigned __int8 *v1; // edi
  int v2; // eax
  bspbrush_t *result; // eax

  v1 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 100 * numsides + 48);
  memset(dst: v1, value: 0, count: 100 * numsides + 48);
  v2 = s_BrushId;
  *(_DWORD *)v1 = s_BrushId;
  s_BrushId = v2 + 1;
  result = (bspbrush_t *)v1;
  if ( numthreads == 1 )
    ++c_active_brushes;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004145E0
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
      p_winding += 25;
    }
    while ( v1 < brushes->numsides );
  }
  free(pMem: brushes);
  if ( numthreads == 1 )
    --c_active_brushes;
}

//------------------------------------------------------------------------------
// Address: 0x00414630
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
          p_winding += 25;
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
// Address: 0x00414690
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

  v2 = 100 * brush->numsides + 48;
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
      p_winding += 25;
    }
    while ( v6 < brush->numsides );
    return brusha;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00414720
// Name: struct node_t __near * PointInLeaf(struct node_t __near *,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
node_t *__cdecl PointInLeaf(node_t *node, Vector *point)
{
  node_t *result; // eax
  int i; // ecx
  int v4; // ecx
  int v5; // edx
  float *v6; // ecx
  float v7; // xmm0_4

  result = node;
  for ( i = node->planenum; i != -1; i = result->planenum )
  {
    v4 = 3 * i;
    v5 = dword_31FE378[2 * v4];
    v6 = &mapplanes.x + 2 * v4;
    if ( v5 >= 3 )
      v7 = (float)((float)(v6[1] * point->y) + (float)(*v6 * point->x)) + (float)(v6[2] * point->z);
    else
      v7 = *(&point->x + v5);
    if ( (float)(v7 - v6[3]) < 0.0 )
      result = result->children[1];
    else
      result = result->children[0];
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004147A0
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
// Address: 0x004148E0
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
  int v10; // ecx
  Vector *v11; // edi
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
  float v24; // xmm4_4
  float v25; // xmm1_4
  int *p_visible; // ecx
  int *v27; // eax
  int v28; // esi
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
  int v48; // esi
  float v49; // xmm0_4
  float v50; // [esp+Ch] [ebp-30h]
  int j; // [esp+24h] [ebp-18h]
  int *v52; // [esp+28h] [ebp-14h]
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
    v10 = dword_31FE378[6 * v6];
    v11 = &mapplanes + 2 * v6;
    if ( v10 >= 3 )
    {
      if ( v11->x >= 0.0 )
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
      if ( v11->y >= 0.0 )
      {
        y = v5->mins.y;
        v18 = v5->maxs.y;
      }
      else
      {
        v18 = v5->mins.y;
        y = v5->maxs.y;
      }
      if ( v11->z >= 0.0 )
      {
        z = v5->mins.z;
        v20 = v5->maxs.z;
      }
      else
      {
        v20 = v5->mins.z;
        z = v5->maxs.z;
      }
      v22 = v11->y;
      v23 = v11->z;
      v24 = v11[1].x;
      result = (float)((float)((float)((float)(v11->x * v50) + (float)(v22 * v18)) + (float)(v23 * v20)) - v24) >= 0.001;
      v15 = (float)((float)((float)((float)(v11->x * x) + (float)(v22 * y)) + (float)(v23 * z)) - v24) >= 0.001;
    }
    else
    {
      v12 = v11[1].x;
      v13 = 4 * v10;
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
          if ( *(p_visible - 6) != -1 && *p_visible != 0 )
          {
            v27 = (int *)*(p_visible - 4);
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
                v32 = v11->y;
                v33 = v11->x;
                v34 = v11->z;
                v35 = v11[1].x;
                v36 = (float *)(v31 + 8);
                v37 = (float *)(v31 + 20);
                v38 = ((unsigned int)(v28 - 4) >> 2) + 1;
                j = 4 * v38;
                do
                {
                  v39 = (float)((float)((float)(*(v36 - 2) * v33) + (float)(*(v36 - 1) * v32)) + (float)(v34 * *v36))
                      - v35;
                  if ( v39 > v25 )
                    v25 = (float)((float)((float)(*(v36 - 2) * v33) + (float)(*(v36 - 1) * v32)) + (float)(v34 * *v36))
                        - v35;
                  if ( d_back > v39 )
                    d_back = (float)((float)((float)(*(v36 - 2) * v33) + (float)(*(v36 - 1) * v32)) + (float)(v34 * *v36))
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
                v47 = (float *)(*(_DWORD *)(*(p_visible - 4) + 4) + 12 * v30);
                v29 = front;
                v48 = v28 - v30;
                do
                {
                  v43 = v11->y;
                  v44 = v11->x;
                  v45 = v11->z;
                  v46 = v11[1].x;
                  v49 = (float)((float)((float)(v47[1] * v43) + (float)(v11->x * *v47)) + (float)(v47[2] * v45)) - v46;
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
              if ( v29 != 0 && back != 0 && (*(p_visible - 1) & 0x200) == 0 )
              {
                ++*numsplits;
                if ( (*(p_visible - 1) & 0x100) != 0 )
                  *hintsplit = 1;
              }
            }
          }
          p_visible += 25;
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
// Address: 0x00414E00
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
// Address: 0x00414ED0
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
            p_texinfo += 25;
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
// Address: 0x00414F40
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
// Address: 0x00414F90
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
      p_winding = brusha + 25;
      v29 = v31-- == 1;
      brusha += 25;
    }
    while ( !v29 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004151D0
// Name: struct bspbrush_t __near * BrushFromBounds(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
bspbrush_t *__cdecl BrushFromBounds(Vector *mins, Vector *maxs)
{
  bspbrush_t *v2; // edi
  int v3; // eax
  int v4; // esi
  side_t *v5; // edi
  int FloatPlane; // eax
  int v7; // ecx
  bspbrush_t *v8; // esi
  Vector normal; // [esp+10h] [ebp-14h] BYREF
  bspbrush_t *brush; // [esp+1Ch] [ebp-8h]
  int v12; // [esp+20h] [ebp-4h]

  v2 = (bspbrush_t *)MemAlloc_Alloc(nSize: 0x288u);
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
  v12 = (char *)mins - (char *)&normal;
  do
  {
    memset(&normal, 0, sizeof(normal));
    *((_DWORD *)&normal.x + v4) = 1065353216;
    FloatPlane = FindFloatPlane(&normal, dist: *(float *)((char *)&normal.x + 4 * v4 + (char *)maxs - (char *)&normal));
    v7 = v12;
    v5[-3].planenum = FloatPlane;
    *((_DWORD *)&normal.x + v4) = -1082130432;
    v5->planenum = FindFloatPlane(
                     &normal,
                     dist: COERCE_FLOAT(*(_DWORD *)((char *)&normal.x + 4 * v4++ + v7) ^ _mask__NegFloat_));
    ++v5;
  }
  while ( v4 < 3 );
  v8 = brush;
  CreateBrushWindings((winding_t *)brush);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x004152E0
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
// Address: 0x004153C0
// Name: void SplitBrush(struct bspbrush_t __near *,int,struct bspbrush_t __near * __near *,struct bspbrush_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SplitBrush(bspbrush_t *brush, int planenum, bspbrush_t **front, bspbrush_t **back)
{
  winding_t *numsides; // eax
  plane_t *v5; // ebx
  float v6; // xmm6_4
  winding_t *v7; // eax
  int numpoints; // esi
  int v9; // edi
  float y; // xmm2_4
  float x; // xmm3_4
  float z; // xmm4_4
  float v13; // xmm5_4
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
  float v30; // xmm4_4
  float v31; // xmm0_4
  float v32; // xmm2_4
  float dist; // xmm0_4
  winding_t *v34; // eax
  int v35; // edi
  side_t *sides; // esi
  int v37; // edx
  Vector *v38; // esi
  int v39; // eax
  float *p_x; // ecx
  unsigned int v41; // esi
  unsigned __int8 *v42; // edi
  int v43; // eax
  int v44; // eax
  bspbrush_t *v45; // ecx
  mapbrush_t *original; // edx
  bool v47; // cc
  winding_t *winding; // eax
  int j; // edi
  int v50; // eax
  side_t *v51; // esi
  int v52; // ebx
  bspbrush_t *v53; // edi
  int v54; // esi
  float *v55; // eax
  int v56; // esi
  winding_t **p_winding; // ebx
  float v58; // ebx
  int k; // edi
  int v60; // eax
  int *v61; // esi
  int v62; // ebx
  bspbrush_t *v63; // esi
  int v64; // edi
  winding_t **v65; // ebx
  float v66; // edx
  int v67; // esi
  winding_t **v68; // edi
  int v69; // esi
  float v70; // ebx
  winding_t **v71; // edi
  int v72; // eax
  Vector offset; // [esp+20h] [ebp-30h] BYREF
  winding_t *cw[2]; // [esp+2Ch] [ebp-24h] BYREF
  Vector v75; // [esp+34h] [ebp-1Ch] BYREF
  winding_t *midwinding; // [esp+40h] [ebp-10h]
  side_t *__that; // [esp+44h] [ebp-Ch]
  int i; // [esp+48h] [ebp-8h]
  winding_t *w; // [esp+4Ch] [ebp-4h] BYREF
  bspbrush_t *brusha; // [esp+58h] [ebp+8h]

  *back = nullptr;
  *front = nullptr;
  numsides = (winding_t *)brush->numsides;
  v5 = (plane_t *)(&mapplanes + 2 * planenum);
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
          y = v5->normal.y;
          x = v5->normal.x;
          z = v5->normal.z;
          v13 = v5->dist;
          p = v7->p;
          p_z = &p->z;
          v16 = &p[1].z;
          v17 = ((unsigned int)(numpoints - 4) >> 2) + 1;
          v9 = 4 * v17;
          do
          {
            v18 = (float)((float)((float)(*(p_z - 2) * x) + (float)(*(p_z - 1) * y)) + (float)(z * *p_z)) - v13;
            if ( v18 > 0.0 && v18 > v6 )
              v6 = (float)((float)((float)(*(p_z - 2) * x) + (float)(*(p_z - 1) * y)) + (float)(z * *p_z)) - v13;
            if ( v18 < 0.0 && *(float *)&i > v18 )
              *(float *)&i = (float)((float)((float)(*(p_z - 2) * x) + (float)(*(p_z - 1) * y)) + (float)(z * *p_z))
                           - v13;
            v19 = (float)((float)((float)(p_z[1] * x) + (float)(*(v16 - 1) * y)) + (float)(z * *v16)) - v13;
            if ( v19 > 0.0 && v19 > v6 )
              v6 = (float)((float)((float)(p_z[1] * x) + (float)(*(v16 - 1) * y)) + (float)(z * *v16)) - v13;
            if ( v19 < 0.0 && *(float *)&i > v19 )
              *(float *)&i = (float)((float)((float)(p_z[1] * x) + (float)(*(v16 - 1) * y)) + (float)(z * *v16)) - v13;
            v20 = (float)((float)((float)(p_z[4] * x) + (float)(v16[2] * y)) + (float)(v16[3] * z)) - v13;
            if ( v20 > 0.0 && v20 > v6 )
              v6 = (float)((float)((float)(p_z[4] * x) + (float)(v16[2] * y)) + (float)(v16[3] * z)) - v13;
            if ( v20 < 0.0 && *(float *)&i > v20 )
              *(float *)&i = (float)((float)((float)(p_z[4] * x) + (float)(v16[2] * y)) + (float)(v16[3] * z)) - v13;
            v21 = (float)((float)((float)(p_z[7] * x) + (float)(v16[5] * y)) + (float)(v16[6] * z)) - v13;
            if ( v21 > 0.0 && v21 > v6 )
              v6 = (float)((float)((float)(p_z[7] * x) + (float)(v16[5] * y)) + (float)(v16[6] * z)) - v13;
            if ( v21 < 0.0 && *(float *)&i > v21 )
              *(float *)&i = (float)((float)((float)(p_z[7] * x) + (float)(v16[5] * y)) + (float)(v16[6] * z)) - v13;
            p_z += 12;
            v16 += 12;
            --v17;
          }
          while ( v17 != 0 );
        }
        if ( v9 < numpoints )
        {
          v22 = v5->normal.y;
          v23 = v5->normal.x;
          v24 = v5->normal.z;
          v25 = v5->dist;
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
  {
    *back = CopyBrush(brush);
    return;
  }
  if ( *(float *)&i > -0.1 )
  {
    *front = CopyBrush(brush);
    return;
  }
  v29 = brush->maxs.z + brush->mins.z;
  v30 = (float)(brush->maxs.x + brush->mins.x) * -0.5;
  v31 = v5->normal.y;
  offset.y = (float)(brush->maxs.y + brush->mins.y) * -0.5;
  v32 = v29 * -0.5;
  dist = (float)((float)((float)(v31 * offset.y) + (float)(v5->normal.x * v30)) + (float)(v5->normal.z * v32))
       + v5->dist;
  offset.x = v30;
  offset.z = v32;
  v34 = BaseWindingForPlane(normal: &v5->normal, dist);
  v35 = 0;
  w = v34;
  if ( brush->numsides > 0 )
  {
    sides = brush->sides;
    while ( v34 != nullptr )
    {
      ChopWindingInPlace(
        inout: &w,
        normal: &mapplanes + 2 * (sides->planenum ^ 1),
        dist: (float)((float)((float)(*(&mapplanes.y + 6 * (sides->planenum ^ 1)) * offset.y)
                      + (float)(*(&mapplanes.x + 6 * (sides->planenum ^ 1)) * offset.x))
              + (float)(*(&mapplanes.z + 6 * (sides->planenum ^ 1)) * offset.z))
      + *((float *)&mapplanes + 6 * (sides->planenum ^ 1) + 3),
        epsilon: 0.0);
      ++v35;
      ++sides;
      v34 = w;
      if ( v35 >= brush->numsides )
        goto LABEL_49;
    }
    goto LABEL_132;
  }
LABEL_49:
  if ( v34 == nullptr || WindingIsTiny(w: v34) != 0 )
  {
LABEL_132:
    v72 = BrushMostlyOnSide(brush, plane: v5);
    if ( v72 == 1 )
    {
      *front = CopyBrush(brush);
    }
    else if ( v72 == 2 )
    {
      *back = CopyBrush(brush);
    }
    return;
  }
  v37 = 0;
  if ( w->numpoints > 0 )
  {
    v38 = w->p;
    while ( 2 )
    {
      v39 = 0;
      p_x = &v38->x;
      do
      {
        if ( *p_x < -16384.0 || *p_x > 16384.0 )
        {
          qprintf(format: "WARNING: huge winding\n");
          goto LABEL_60;
        }
        ++v39;
        ++p_x;
      }
      while ( v39 < 3 );
      ++v37;
      ++v38;
      if ( v37 < w->numpoints )
        continue;
      break;
    }
  }
LABEL_60:
  v75.x = -offset.x;
  v75.y = -offset.y;
  v75.z = -offset.z;
  TranslateWinding(pWinding: w, offset: &v75);
  midwinding = w;
  *(float *)&i = 0.0;
  do
  {
    v41 = 100 * brush->numsides + 148;
    v42 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v41);
    memset(dst: v42, value: 0, count: v41);
    v43 = s_BrushId;
    *(_DWORD *)v42 = s_BrushId;
    s_BrushId = v43 + 1;
    if ( numthreads == 1 )
      ++c_active_brushes;
    v44 = i;
    v45 = brush;
    original = brush->original;
    *((_DWORD *)&v75.y + i) = v42;
    *((_DWORD *)v42 + 10) = original;
    i = v44 + 1;
  }
  while ( v44 + 1 < 2 );
  v47 = brush->numsides <= 0;
  *(float *)&i = 0.0;
  if ( !v47 )
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
          normal: &v5->normal,
          dist: v5->dist,
          epsilon: 0.0,
          front: cw,
          back: &cw[1],
          &offset);
        for ( j = 0; j < 2; ++j )
        {
          if ( cw[j] != nullptr )
          {
            v50 = *(_DWORD *)((char *)&v75.y + j * 4);
            v51 = (side_t *)(100 * (*(_DWORD *)(v50 + 44))++ + v50 + 48);
            side_t::operator=(this: v51, __that);
            v51->winding = cw[j];
            v51->tested = 0;
          }
        }
        v45 = brush;
      }
      ++__that;
      ++i;
    }
    while ( i < v45->numsides );
  }
  *(float *)&v52 = 0.0;
  *(float *)&i = 0.0;
  do
  {
    v53 = *((bspbrush_t **)&v75.y + v52);
    BoundBrush(brush: v53);
    v54 = 0;
    v55 = &v53->maxs.x;
    while ( *(v55 - 3) >= -16384.0 && *v55 <= 16384.0 )
    {
      ++v54;
      ++v55;
      if ( v54 >= 3 )
        goto LABEL_80;
    }
    qprintf(format: "bogus brush after clip\n");
LABEL_80:
    if ( v53->numsides < 3 || v54 < 3 )
    {
      v56 = 0;
      if ( v53->numsides > 0 )
      {
        p_winding = &v53->sides[0].winding;
        do
        {
          if ( *p_winding != nullptr )
            FreeWinding(w: *p_winding);
          ++v56;
          p_winding += 25;
        }
        while ( v56 < v53->numsides );
        v52 = i;
      }
      free(pMem: v53);
      if ( numthreads == 1 )
        --c_active_brushes;
      *((_DWORD *)&v75.y + v52) = 0;
    }
    i = ++v52;
  }
  while ( v52 < 2 );
  v58 = v75.y;
  if ( LODWORD(v75.y) != 0 )
  {
    if ( LODWORD(v75.z) != 0 )
    {
      for ( k = 0; k < 2; ++k )
      {
        v60 = *((_DWORD *)&v75.y + k);
        v61 = (int *)(100 * (*(_DWORD *)(v60 + 44))++ + v60 + 48);
        *v61 = planenum ^ k ^ 1;
        v61[1] = -1;
        v61[2] = 0;
        v61[7] = 0;
        v61[8] = 0;
        if ( k != 0 )
          v61[3] = (int)midwinding;
        else
          v61[3] = (int)CopyWinding(w: midwinding);
      }
      v62 = 0;
      brusha = nullptr;
      do
      {
        v63 = *((bspbrush_t **)&v75.y + v62);
        if ( BrushVolume(brush: v63) < 1.0 )
        {
          v64 = 0;
          if ( v63->numsides > 0 )
          {
            v65 = &v63->sides[0].winding;
            do
            {
              if ( *v65 != nullptr )
                FreeWinding(w: *v65);
              ++v64;
              v65 += 25;
            }
            while ( v64 < v63->numsides );
            v62 = (int)brusha;
          }
          free(pMem: v63);
          if ( numthreads == 1 )
            --c_active_brushes;
          *((_DWORD *)&v75.y + v62) = 0;
        }
        brusha = (bspbrush_t *)++v62;
      }
      while ( v62 < 2 );
      v66 = v75.z;
      *front = (bspbrush_t *)LODWORD(v75.y);
      *(float *)back = v66;
      return;
    }
  }
  else if ( LODWORD(v75.z) == 0 )
  {
    qprintf(format: "split removed brush\n");
    return;
  }
  qprintf(format: "split not on both sides\n");
  if ( v58 != 0.0 )
  {
    v67 = 0;
    if ( *(int *)(LODWORD(v58) + 44) > 0 )
    {
      v68 = (winding_t **)(LODWORD(v58) + 60);
      do
      {
        if ( *v68 != nullptr )
          FreeWinding(w: *v68);
        ++v67;
        v68 += 25;
      }
      while ( v67 < *(_DWORD *)(LODWORD(v58) + 44) );
    }
    free(pMem: (void *)LODWORD(v58));
    if ( numthreads == 1 )
      --c_active_brushes;
    *front = CopyBrush(brush);
  }
  if ( LODWORD(v75.z) != 0 )
  {
    v69 = 0;
    v70 = v75.z;
    if ( *(int *)(LODWORD(v75.z) + 44) > 0 )
    {
      v71 = (winding_t **)(LODWORD(v75.z) + 60);
      do
      {
        if ( *v71 != nullptr )
          FreeWinding(w: *v71);
        ++v69;
        v71 += 25;
      }
      while ( v69 < *(_DWORD *)(LODWORD(v70) + 44) );
    }
    free(pMem: (void *)LODWORD(v70));
    if ( numthreads == 1 )
      --c_active_brushes;
    *back = CopyBrush(brush);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415BF0
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
// Address: 0x00415CD0
// Name: struct side_t __near * SelectSplitSide(struct bspbrush_t __near *,struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
side_t *__cdecl SelectSplitSide(bspbrush_t *brushes, node_t *node)
{
  side_t *v2; // esi
  bspbrush_t *v3; // ecx
  int *p_bevel; // ebx
  node_t *parent; // esi
  unsigned int j; // edi
  BOOL v7; // esi
  bspbrush_t *v8; // esi
  int v9; // ebx
  int v10; // ecx
  int *p_tested; // eax
  unsigned int v12; // eax
  int v13; // eax
  int v14; // ecx
  bspbrush_t *v15; // eax
  bspbrush_t *k; // edx
  int v17; // eax
  int *v18; // ecx
  int bsplits; // [esp+Ch] [ebp-3Ch] BYREF
  bspbrush_t *v21; // [esp+10h] [ebp-38h] BYREF
  side_t *bestside; // [esp+14h] [ebp-34h]
  int i; // [esp+18h] [ebp-30h]
  int bestvalue; // [esp+1Ch] [ebp-2Ch]
  int hintsplit; // [esp+20h] [ebp-28h] BYREF
  int epsilonbrush; // [esp+24h] [ebp-24h] BYREF
  bspbrush_t *v27; // [esp+28h] [ebp-20h] BYREF
  bspbrush_t *brush; // [esp+2Ch] [ebp-1Ch]
  int splits; // [esp+30h] [ebp-18h]
  int facing; // [esp+34h] [ebp-14h]
  int back; // [esp+38h] [ebp-10h]
  int front; // [esp+3Ch] [ebp-Ch]
  int pass; // [esp+40h] [ebp-8h]
  int *v34; // [esp+44h] [ebp-4h]

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
          p_bevel = &brush->sides[0].bevel;
          v34 = &brush->sides[0].bevel;
          do
          {
            if ( *p_bevel == 0
              && *(p_bevel - 6) != 0
              && *(p_bevel - 8) != -1
              && *(p_bevel - 1) == 0
              && (*(p_bevel - 3) & 0x200) == 0
              && *(p_bevel - 2) == pass < 1 )
            {
              parent = node->parent;
              for ( j = *(p_bevel - 9) & 0xFFFFFFFE; parent != nullptr; parent = parent->parent )
              {
                if ( parent->planenum == j )
                  _Error(a1: "Tried parent");
              }
              SplitBrush(brush: node->volume, planenum: j, front: &v21, back: &v27);
              v7 = v21 != nullptr && v27 != nullptr;
              if ( v21 != nullptr )
                FreeBrush(brushes: v21);
              if ( v27 != nullptr )
                FreeBrush(brushes: v27);
              if ( v7 )
              {
                v8 = brushes;
                front = 0;
                back = 0;
                facing = 0;
                splits = 0;
                epsilonbrush = 0;
                do
                {
                  v9 = TestBrushToPlanenum(brush: v8, planenum: j, numsplits: &bsplits, &hintsplit, &epsilonbrush);
                  splits += bsplits;
                  if ( bsplits != 0 && (v9 & 4) != 0 )
                    _Error(a1: "PSIDE_FACING with splits");
                  v8->testside = v9;
                  if ( (v9 & 4) != 0 )
                  {
                    ++facing;
                    v10 = 0;
                    if ( v8->numsides > 0 )
                    {
                      p_tested = &v8->sides[0].tested;
                      do
                      {
                        if ( (*(p_tested - 8) & 0xFFFFFFFE) == j )
                          *p_tested = 1;
                        ++v10;
                        p_tested += 25;
                      }
                      while ( v10 < v8->numsides );
                    }
                  }
                  if ( (v9 & 1) != 0 )
                    ++front;
                  if ( (v9 & 2) != 0 )
                    ++back;
                  v8 = v8->next;
                }
                while ( v8 != nullptr );
                v12 = 5 * (facing - splits) - abs32(front - back);
                if ( dword_31FE378[6 * j] < 3 )
                  v12 += 5;
                v13 = -1000 * epsilonbrush + v12;
                v14 = *(v34 - 3);
                if ( (v14 & 0x10) != 0 )
                  v13 -= 500;
                if ( hintsplit != 0 && (v14 & 0x100) == 0 )
                  v13 = -9999999;
                if ( (*(_BYTE *)(v34 - 4) & 0x30) != 0 )
                  v13 = (int)&unk_98967F;
                if ( v13 > bestvalue )
                {
                  bestvalue = v13;
                  v15 = brushes;
                  bestside = (side_t *)(v34 - 9);
                  do
                  {
                    v15->side = v15->testside;
                    v15 = v15->next;
                  }
                  while ( v15 != nullptr );
                }
                p_bevel = v34;
              }
            }
            v3 = brush;
            p_bevel += 25;
            ++i;
            v34 = p_bevel;
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
    v17 = 0;
    if ( k->numsides > 0 )
    {
      v18 = &k->sides[0].tested;
      do
      {
        *v18 = 0;
        ++v17;
        v18 += 25;
      }
      while ( v17 < k->numsides );
    }
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00415F80
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
// Address: 0x00416090
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
        if ( p_winding[6] == nullptr && *p_winding != nullptr && *(p_winding - 2) != (winding_t *)-1 )
        {
          if ( p_winding[4] != nullptr )
            ++c_faces;
          else
            ++c_nonvisfaces;
        }
        p_winding += 25;
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
