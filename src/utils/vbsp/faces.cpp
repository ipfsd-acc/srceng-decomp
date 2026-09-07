// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vbsp/faces.cpp
// Functions: 30
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0040FFF0
// Name: int GetVertexnum(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetVertexnum(Vector *in)
{
  Vector *v1; // eax
  int v2; // ecx
  int i; // edx
  float x; // xmm3_4
  float y; // xmm4_4
  unsigned int v6; // edi
  unsigned int v7; // esi
  float z; // xmm2_4
  unsigned int v9; // esi
  int result; // eax
  Vector *v11; // ecx
  int v12; // ecx
  Vector vert; // [esp+0h] [ebp-Ch] BYREF

  v1 = in;
  ++c_totalverts;
  v2 = (char *)&vert - (char *)in;
  for ( i = 3; i != 0; --i )
  {
    if ( fabs(v1->x - (float)(int)(float)(v1->x + 0.5)) >= 0.01 )
      *(float *)((char *)&v1->x + v2) = v1->x;
    else
      *(float *)((char *)&v1->x + v2) = (float)(int)(float)(v1->x + 0.5);
    v1 = (Vector *)((char *)v1 + 4);
  }
  x = vert.x;
  y = vert.y;
  v6 = ((int)(float)(vert.x + 0.5) + 0x4000) >> 7;
  v7 = ((int)(float)(vert.y + 0.5) + 0x4000) >> 7;
  if ( v6 > 0xFF || v7 >= 0x100 )
  {
    _Error(a1: "HashVec: point outside valid range");
    x = vert.x;
    y = vert.y;
  }
  z = vert.z;
  v9 = v6 + (v7 << 8);
  result = hashverts[v9];
  if ( result != 0 )
  {
    while ( 1 )
    {
      v11 = &dvertexes + result;
      if ( fabs(v11->x - x) < 0.1 && fabs(v11->y - y) < 0.1 && fabs(v11->z - vert.z) < 0.1 )
        break;
      result = vertexchain[result];
      if ( result == 0 )
        goto LABEL_14;
    }
  }
  else
  {
LABEL_14:
    result = numvertexes;
    if ( numvertexes == 0x10000 )
    {
      _Error(a1: "Too many unique verts, max = %d (map has too much brush geometry)\n", 0x10000);
      result = numvertexes;
      x = vert.x;
      z = vert.z;
      y = vert.y;
    }
    ++c_uniqueverts;
    v12 = 12 * result;
    *(float *)((char *)&dvertexes.x + v12) = x;
    *(float *)((char *)&dvertexes.y + v12) = y;
    *(float *)((char *)&dvertexes.z + v12) = z;
    vertexchain[result] = hashverts[v9];
    hashverts[v9] = result;
    numvertexes = result + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004101D0
// Name: void FindEdgeVerts(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FindEdgeVerts(Vector *v1, Vector *v2)
{
  float y; // xmm1_4
  int v3; // edx
  int v4; // eax
  int v5; // esi
  int v6; // ebx
  int v7; // ecx
  int v8; // edi
  int *v9; // edi
  int v10; // edx
  int i; // eax
  int x2; // [esp+8h] [ebp+8h]
  int x; // [esp+Ch] [ebp+Ch]

  y = v1->y;
  v3 = ((int)(float)(v2->x + 0.5) + 0x4000) >> 7;
  v4 = ((int)(float)(v1->x + 0.5) + 0x4000) >> 7;
  v5 = ((int)(float)(y + 0.5) + 0x4000) >> 7;
  v6 = ((int)(float)(v2->y + 0.5) + 0x4000) >> 7;
  x2 = v3;
  if ( v4 > v3 )
  {
    x2 = v4;
    v4 = ((int)(float)(v2->x + 0.5) + 0x4000) >> 7;
    v3 = x2;
  }
  if ( v5 > v6 )
  {
    v5 = ((int)(float)(v2->y + 0.5) + 0x4000) >> 7;
    v6 = ((int)(float)(y + 0.5) + 0x4000) >> 7;
  }
  v7 = 0;
  num_edge_verts = 0;
  v8 = v4;
  x = v4;
  if ( v4 <= v3 )
  {
    do
    {
      if ( v5 <= v6 )
      {
        v9 = &hashverts[256 * v5 + v8];
        v10 = v6 - v5 + 1;
        do
        {
          for ( i = *v9; i != 0; ++v7 )
          {
            edge_verts[v7] = i;
            i = vertexchain[i];
          }
          v9 += 256;
          --v10;
        }
        while ( v10 != 0 );
        v3 = x2;
        v8 = x;
      }
      x = ++v8;
    }
    while ( v8 <= v3 );
    num_edge_verts = v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004102D0
// Name: void TestEdge(float,float,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TestEdge(float start, float end, int p1, int p2, int startvert)
{
  int v5; // edx
  int v6; // edi
  int v8; // esi
  float v9; // xmm0_4
  int v10; // edi
  int v11; // eax

  v5 = p2;
  v6 = p1;
  if ( p1 == p2 )
  {
    ++c_degenerate;
  }
  else
  {
    while ( startvert < num_edge_verts )
    {
      v8 = edge_verts[startvert];
      if ( v8 == v6
        || v8 == v5
        || (v9 = (float)((float)(edge_dir.y * (float)(*(&dvertexes.y + 3 * v8) - edge_start.y))
                       + (float)(edge_dir.x * (float)(*(&dvertexes.x + 3 * v8) - edge_start.x)))
               + (float)(edge_dir.z * (float)(*(&dvertexes.z + 3 * v8) - edge_start.z)),
            start >= v9)
        || v9 >= end
        || fsqrt(
             (float)((float)((float)(*(&dvertexes.y + 3 * v8) - (float)((float)(edge_dir.y * v9) + edge_start.y))
                           * (float)(*(&dvertexes.y + 3 * v8) - (float)((float)(edge_dir.y * v9) + edge_start.y)))
                   + (float)((float)(*(&dvertexes.z + 3 * v8) - (float)((float)(edge_dir.z * v9) + edge_start.z))
                           * (float)(*(&dvertexes.z + 3 * v8) - (float)((float)(edge_dir.z * v9) + edge_start.z))))
           + (float)((float)(*(&dvertexes.x + 3 * v8) - (float)((float)(edge_dir.x * v9) + edge_start.x))
                   * (float)(*(&dvertexes.x + 3 * v8) - (float)((float)(edge_dir.x * v9) + edge_start.x)))) > 0.25 )
      {
        ++startvert;
      }
      else
      {
        ++c_tjunctions;
        v10 = startvert + 1;
        TestEdge(start, end: v9, p1, p2: v8, startvert: startvert + 1);
        v5 = p2;
        startvert = v10;
        p1 = v8;
        start = v9;
        v6 = v8;
      }
    }
    if ( numsuperverts >= 512 )
      _Error(a1: "Edge with too many vertices due to t-junctions.  Max %d verts along an edge!\n", 512);
    v11 = numsuperverts;
    superverts[numsuperverts] = v6;
    numsuperverts = v11 + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004104C0
// Name: struct face_t __near * AllocFace(void)
// Source: json
//------------------------------------------------------------------------------
face_t *__cdecl AllocFace()
{
  unsigned __int8 *v0; // esi
  int v1; // eax

  v0 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0xD0u);
  memset(dst: v0, value: 0, count: 0xD0u);
  v1 = s_FaceId;
  ++c_faces;
  *(_DWORD *)v0 = s_FaceId;
  s_FaceId = v1 + 1;
  return (face_t *)v0;
}

//------------------------------------------------------------------------------
// Address: 0x00410500
// Name: struct face_t __near * NewFaceFromFace(struct face_t __near *)
// Source: json
//------------------------------------------------------------------------------
face_t *__cdecl NewFaceFromFace(face_t *f)
{
  unsigned __int8 *v1; // ebx
  int v2; // eax

  v1 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0xD0u);
  memset(dst: v1, value: 0, count: 0xD0u);
  v2 = s_FaceId;
  *(_DWORD *)v1 = s_FaceId;
  ++c_faces;
  qmemcpy(v1, f, 0xD0u);
  s_FaceId = v2 + 1;
  *((_DWORD *)v1 + 2) = 0;
  *((_DWORD *)v1 + 4) = 0;
  *((_DWORD *)v1 + 3) = 0;
  *((_DWORD *)v1 + 12) = 0;
  return (face_t *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x00410560
// Name: void FreeFace(struct face_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FreeFace(face_t *f)
{
  if ( f->w != nullptr )
    FreeWinding(w: f->w);
  free(pMem: f);
  --c_faces;
}

//------------------------------------------------------------------------------
// Address: 0x00410590
// Name: void FreeFaceList(struct face_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FreeFaceList(face_t *pFaces)
{
  face_t *v1; // esi
  face_t *next; // edi

  v1 = pFaces;
  if ( pFaces != nullptr )
  {
    do
    {
      next = v1->next;
      if ( v1->w != nullptr )
        FreeWinding(w: v1->w);
      free(pMem: v1);
      --c_faces;
      v1 = next;
    }
    while ( next != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004105D0
// Name: struct winding_t __near * TryMergeWinding(struct winding_t __near *,struct winding_t __near *,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
winding_t *__cdecl TryMergeWinding(winding_t *f1, winding_t *f2, Vector *planenormal)
{
  int numpoints; // eax
  Vector *v4; // ebx
  Vector *v5; // esi
  int v6; // edi
  int v7; // ecx
  Vector *v8; // ebx
  float *p_x; // eax
  int v10; // edx
  int v11; // ecx
  Vector *v13; // ecx
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm4_4
  float y; // xmm5_4
  float z; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  Vector *v21; // eax
  Vector *v22; // esi
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm2_4
  float v26; // xmm5_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  int v29; // ecx
  Vector *v30; // edx
  float v31; // xmm0_4
  winding_t *v32; // eax
  int v33; // esi
  winding_t *v34; // ecx
  int v35; // edx
  Vector *v36; // esi
  float *v37; // eax
  Vector *v38; // esi
  double x; // st7
  Vector *v40; // edx
  int v41; // ebx
  int j; // esi
  float *v43; // eax
  Vector *v44; // edx
  Vector normal; // [esp+0h] [ebp-38h] BYREF
  char *v46; // [esp+Ch] [ebp-2Ch]
  int v47; // [esp+10h] [ebp-28h]
  Vector *v48; // [esp+14h] [ebp-24h]
  Vector *p; // [esp+18h] [ebp-20h]
  Vector *p1; // [esp+1Ch] [ebp-1Ch]
  int keep1; // [esp+20h] [ebp-18h]
  Vector *p2; // [esp+24h] [ebp-14h]
  int i; // [esp+28h] [ebp-10h]
  Vector *v54; // [esp+2Ch] [ebp-Ch]
  Vector *v55; // [esp+30h] [ebp-8h]
  int v56; // [esp+34h] [ebp-4h]

  numpoints = f1->numpoints;
  v4 = nullptr;
  v5 = nullptr;
  v6 = 0;
  p2 = nullptr;
  i = 0;
  v56 = numpoints;
  if ( numpoints > 0 )
  {
    v7 = f2->numpoints;
    p = f1->p;
    keep1 = v7;
    v55 = p;
    do
    {
      v5 = v55;
      v6 = 0;
      p1 = v55;
      p2 = &p[((int)&v4->x + 1) % v56];
      if ( v7 > 0 )
      {
        v8 = f2->p;
        v48 = v8;
        v54 = v8;
        while ( 1 )
        {
          p_x = &v8[(v6 + 1) % v7].x;
          v10 = 0;
          v46 = (char *)((char *)p2 - (char *)p_x);
          v47 = (char *)v55 - (char *)p_x;
          v11 = (char *)v54 - (char *)p_x;
          do
          {
            if ( fabs(*(float *)((char *)p_x + v47) - *p_x) > 0.001 )
              break;
            if ( fabs(*(float *)((char *)p_x + (_DWORD)v46) - *(float *)((char *)p_x + v11)) > 0.001 )
              break;
            ++v10;
            ++p_x;
          }
          while ( v10 < 3 );
          v7 = keep1;
          if ( v10 == 3 )
            break;
          ++v54;
          if ( ++v6 >= keep1 )
            break;
          v8 = v48;
        }
        v5 = p1;
        v4 = (Vector *)i;
      }
      if ( v6 < v7 )
        break;
      ++v55;
      v4 = (Vector *)((char *)v4 + 1);
      i = (int)v4;
    }
    while ( (int)v4 < v56 );
    numpoints = v56;
  }
  if ( v4 == (Vector *)numpoints )
    return nullptr;
  v13 = f1->p;
  v14 = v5->x - v13[((int)v4 + numpoints - 1) % v56].x;
  v15 = v5->y - v13[((int)v4 + numpoints - 1) % v56].y;
  v16 = v5->z - v13[((int)v4 + numpoints - 1) % v56].z;
  y = planenormal->y;
  z = planenormal->z;
  normal.x = (float)(y * v16) - (float)(z * v15);
  v19 = (float)(planenormal->x * v15) - (float)(y * v14);
  normal.y = (float)(z * v14) - (float)(planenormal->x * v16);
  normal.z = v19;
  VectorNormalize(vec: &normal);
  v20 = (float)((float)(normal.y * (float)(f2->p[(v6 + 2) % f2->numpoints].y - v5->y))
              + (float)(normal.x * (float)(f2->p[(v6 + 2) % f2->numpoints].x - v5->x)))
      + (float)(normal.z * (float)(f2->p[(v6 + 2) % f2->numpoints].z - v5->z));
  if ( v20 > 0.001 )
    return nullptr;
  keep1 = v20 < -0.001;
  v21 = f1->p;
  v22 = p2;
  v23 = v21[((int)&v4->x + 2) % f1->numpoints].y - p2->y;
  v24 = v21[((int)&v4->x + 2) % f1->numpoints].z - p2->z;
  v25 = v21[((int)&v4->x + 2) % f1->numpoints].x - p2->x;
  v26 = planenormal->y;
  v27 = planenormal->z;
  normal.x = (float)(v26 * v24) - (float)(v27 * v23);
  v28 = (float)(planenormal->x * v23) - (float)(v26 * v25);
  normal.y = (float)(v27 * v25) - (float)(planenormal->x * v24);
  normal.z = v28;
  VectorNormalize(vec: &normal);
  v29 = f2->numpoints;
  v30 = f2->p;
  v31 = (float)((float)(normal.y * (float)(v30[(f2->numpoints + v6 - 1) % f2->numpoints].y - v22->y))
              + (float)(normal.x * (float)(v30[(f2->numpoints + v6 - 1) % f2->numpoints].x - v22->x)))
      + (float)(normal.z * (float)(v30[(f2->numpoints + v6 - 1) % f2->numpoints].z - v22->z));
  if ( v31 > 0.001 )
    return nullptr;
  p1 = (Vector *)(v31 < -0.001);
  v32 = AllocWinding(points: v29 + f1->numpoints);
  v33 = f1->numpoints;
  v34 = v32;
  p2 = (Vector *)(((int)&v4->x + 1) % f1->numpoints);
  if ( p2 != v4 )
  {
    while ( 1 )
    {
      v35 = ((int)&v4->x + 1) % v33;
      v36 = p2;
      if ( p2 != (Vector *)v35 || p1 != nullptr )
      {
        v37 = &v34->p[v34->numpoints].x;
        v38 = f1->p;
        x = v38[(_DWORD)p2].x;
        v40 = &v38[(_DWORD)p2];
        v36 = p2;
        *v37 = x;
        v37[1] = v40->y;
        v37[2] = v40->z;
        ++v34->numpoints;
      }
      v56 = f1->numpoints;
      p2 = (Vector *)(((int)&v36->x + 1) % v56);
      if ( p2 == v4 )
        break;
      v33 = v56;
    }
  }
  v41 = f2->numpoints;
  for ( j = (v6 + 1) % f2->numpoints; j != v6; j = (j + 1) % f2->numpoints )
  {
    if ( j != (v6 + 1) % v41 || keep1 != 0 )
    {
      v43 = &v34->p[v34->numpoints].x;
      v44 = &f2->p[j];
      *v43 = v44->x;
      v43[1] = v44->y;
      v43[2] = v44->z;
      ++v34->numpoints;
    }
    v41 = f2->numpoints;
  }
  return v34;
}

//------------------------------------------------------------------------------
// Address: 0x00410A00
// Name: bool FaceOnWaterBrush(struct face_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl FaceOnWaterBrush(face_t *face)
{
  side_t *originalface; // eax

  originalface = face->originalface;
  return originalface != nullptr && (originalface->contents & 0x30) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00410A20
// Name: void FaceFromSuperverts(struct face_t __near * __near *,struct face_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FaceFromSuperverts(face_t **pListHead, face_t *f, int base)
{
  int v3; // edi
  unsigned __int8 *v4; // ebx
  int v5; // eax
  int v6; // ecx
  char *v7; // ebx
  int v8; // edx
  unsigned __int8 *v9; // ebx
  int v10; // eax
  bool v11; // zf
  int v12; // ecx
  int *vertexnums; // esi
  int v14; // edx
  int remaining; // [esp+8h] [ebp-8h]
  unsigned int v16; // [esp+Ch] [ebp-4h]

  v3 = numsuperverts;
  if ( numsuperverts > 32 )
  {
    v16 = (numsuperverts - 33) / 0x1Eu + 1;
    remaining = numsuperverts - 30 * v16;
    do
    {
      ++c_faceoverflows;
      v4 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0xD0u);
      memset(dst: v4, value: 0, count: 0xD0u);
      v5 = s_FaceId;
      *(_DWORD *)v4 = s_FaceId;
      ++c_faces;
      s_FaceId = v5 + 1;
      qmemcpy(v4, f, 0xD0u);
      *((_DWORD *)v4 + 2) = 0;
      *((_DWORD *)v4 + 4) = 0;
      *((_DWORD *)v4 + 3) = 0;
      *((_DWORD *)v4 + 12) = 0;
      f->split[0] = (face_t *)v4;
      *((_DWORD *)v4 + 1) = *pListHead;
      *pListHead = (face_t *)v4;
      *((_DWORD *)v4 + 13) = 32;
      v6 = 0;
      v7 = (char *)(v4 + 60);
      do
      {
        v8 = (v6 + base) % numsuperverts;
        ++v6;
        v7 += 4;
        *((_DWORD *)v7 - 1) = superverts[v8];
      }
      while ( v6 < 32 );
      v9 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0xD0u);
      memset(dst: v9, value: 0, count: 0xD0u);
      v10 = s_FaceId;
      *(_DWORD *)v9 = s_FaceId;
      ++c_faces;
      s_FaceId = v10 + 1;
      qmemcpy(v9, f, 0xD0u);
      *((_DWORD *)v9 + 2) = 0;
      *((_DWORD *)v9 + 4) = 0;
      *((_DWORD *)v9 + 3) = 0;
      *((_DWORD *)v9 + 12) = 0;
      f->split[1] = (face_t *)v9;
      *((_DWORD *)v9 + 1) = *pListHead;
      *pListHead = (face_t *)v9;
      v11 = v16-- == 1;
      f = (face_t *)v9;
      base = (base + 31) % numsuperverts;
    }
    while ( !v11 );
    v3 = remaining;
  }
  v12 = 0;
  f->numpoints = v3;
  if ( v3 > 0 )
  {
    vertexnums = f->vertexnums;
    do
    {
      v14 = (v12 + base) % numsuperverts;
      ++v12;
      *vertexnums++ = superverts[v14];
    }
    while ( v12 < v3 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410BA0
// Name: void EmitFaceVertexes(struct face_t __near * __near *,struct face_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EmitFaceVertexes(face_t **pListHead, face_t *f)
{
  face_t *v2; // eax
  winding_t *w; // edi
  int v4; // esi
  int v5; // edx
  int v6; // ebx
  Vector *p; // eax
  Vector *v8; // ecx
  double z; // st7
  int Vertexnum; // eax

  v2 = f;
  if ( f->merged == nullptr && f->split[0] == nullptr && f->split[1] == nullptr )
  {
    w = f->w;
    v4 = 0;
    if ( w->numpoints > 0 )
    {
      v5 = numvertexes;
      v6 = 0;
      do
      {
        if ( noweld != 0 )
        {
          if ( v5 == 0x10000 )
          {
            _Error(a1: "Too many unique verts, max = %d (map has too much brush geometry)\n", 0x10000);
            v5 = numvertexes;
          }
          superverts[v4] = v5;
          p = w->p;
          v8 = &dvertexes + v5;
          v8->x = p[v6].x;
          v8->y = p[v6].y;
          z = p[v6].z;
          ++c_uniqueverts;
          v8->z = z;
          ++v5;
          ++c_totalverts;
          numvertexes = v5;
        }
        else
        {
          Vertexnum = GetVertexnum(in: &w->p[v6]);
          v5 = numvertexes;
          superverts[v4] = Vertexnum;
        }
        ++v4;
        ++v6;
      }
      while ( v4 < w->numpoints );
      v2 = f;
    }
    numsuperverts = w->numpoints;
    FaceFromSuperverts(pListHead, f: v2, base: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410C90
// Name: void EmitNodeFaceVertexes_r(struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EmitNodeFaceVertexes_r(node_t *node)
{
  node_t *v1; // esi
  face_t *faces; // eax
  winding_t *w; // edi
  int v4; // esi
  int v5; // edx
  int v6; // ebx
  Vector *p; // eax
  Vector *v8; // ecx
  double z; // st7
  int Vertexnum; // eax
  node_t **children; // esi
  int i; // edi
  face_t *f; // [esp+4h] [ebp-4h]

  v1 = node;
  if ( node->planenum != -1 )
  {
    faces = node->faces;
    f = faces;
    if ( faces != nullptr )
    {
      while ( 1 )
      {
        if ( faces->merged == nullptr && faces->split[0] == nullptr && faces->split[1] == nullptr )
        {
          w = faces->w;
          v4 = 0;
          if ( w->numpoints > 0 )
          {
            v5 = numvertexes;
            v6 = 0;
            do
            {
              if ( noweld != 0 )
              {
                if ( v5 == 0x10000 )
                {
                  _Error(a1: "Too many unique verts, max = %d (map has too much brush geometry)\n", 0x10000);
                  v5 = numvertexes;
                }
                superverts[v4] = v5;
                p = w->p;
                v8 = &dvertexes + v5;
                v8->x = p[v6].x;
                v8->y = p[v6].y;
                z = p[v6].z;
                ++c_uniqueverts;
                v8->z = z;
                ++v5;
                ++c_totalverts;
                numvertexes = v5;
              }
              else
              {
                Vertexnum = GetVertexnum(in: &w->p[v6]);
                v5 = numvertexes;
                superverts[v4] = Vertexnum;
              }
              ++v4;
              ++v6;
            }
            while ( v4 < w->numpoints );
            faces = f;
          }
          numsuperverts = w->numpoints;
          FaceFromSuperverts(pListHead: &node->faces, f: faces, base: 0);
          faces = f;
        }
        f = faces->next;
        if ( f == nullptr )
          break;
        faces = faces->next;
      }
      v1 = node;
    }
    children = v1->children;
    for ( i = 2; i != 0; --i )
      EmitNodeFaceVertexes_r(node: *children++);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410DE0
// Name: void EmitLeafFaceVertexes(struct face_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EmitLeafFaceVertexes(face_t **ppLeafFaceList)
{
  face_t *v1; // eax
  winding_t *w; // edi
  int v3; // esi
  int v4; // edx
  int v5; // ebx
  Vector *p; // eax
  Vector *v7; // ecx
  double z; // st7
  int Vertexnum; // eax
  face_t *f; // [esp+0h] [ebp-4h]

  v1 = *ppLeafFaceList;
  f = *ppLeafFaceList;
  if ( *ppLeafFaceList != nullptr )
  {
    while ( 1 )
    {
      if ( v1->merged == nullptr && v1->split[0] == nullptr && v1->split[1] == nullptr )
      {
        w = v1->w;
        v3 = 0;
        if ( w->numpoints > 0 )
        {
          v4 = numvertexes;
          v5 = 0;
          do
          {
            if ( noweld != 0 )
            {
              if ( v4 == 0x10000 )
              {
                _Error(a1: "Too many unique verts, max = %d (map has too much brush geometry)\n", 0x10000);
                v4 = numvertexes;
              }
              superverts[v3] = v4;
              p = w->p;
              v7 = &dvertexes + v4;
              v7->x = p[v5].x;
              v7->y = p[v5].y;
              z = p[v5].z;
              ++c_uniqueverts;
              v7->z = z;
              ++v4;
              ++c_totalverts;
              numvertexes = v4;
            }
            else
            {
              Vertexnum = GetVertexnum(in: &w->p[v5]);
              v4 = numvertexes;
              superverts[v3] = Vertexnum;
            }
            ++v3;
            ++v5;
          }
          while ( v3 < w->numpoints );
          v1 = f;
        }
        numsuperverts = w->numpoints;
        FaceFromSuperverts(pListHead: ppLeafFaceList, f: v1, base: 0);
        v1 = f;
      }
      f = v1->next;
      if ( f == nullptr )
        break;
      v1 = v1->next;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410F00
// Name: void IntSort(class CUtlVector<int,class CUtlMemory<int,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IntSort(CUtlVector<int,CUtlMemory<int,int> > *theList)
{
  int i; // eax
  int *v2; // ecx
  int v3; // edx
  int v4; // edi

  for ( i = 0; i < theList->m_Size - 1; ++i )
  {
    v2 = &theList->m_Memory.m_pMemory[i];
    v3 = v2[1];
    if ( *v2 > v3 )
    {
      v4 = *v2;
      *v2 = v3;
      theList->m_Memory.m_pMemory[i + 1] = v4;
      if ( i <= 0 )
        i = -1;
      else
        i -= 2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410F50
// Name: void SubdivideFace(struct face_t __near * __near *,struct face_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SubdivideFace(face_t **pFaceList, face_t *f)
{
  texinfo_s *v2; // eax
  winding_t *w; // ebx
  float *p_numpoints; // ecx
  float v5; // xmm2_4
  float v6; // xmm5_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  int numpoints; // esi
  int v10; // edi
  float v11; // xmm1_4
  Vector *p; // eax
  float *p_z; // edx
  float *v14; // ecx
  unsigned int v15; // eax
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  float *p_x; // eax
  int v21; // esi
  float v22; // xmm0_4
  double v23; // st7
  face_t *v24; // eax
  winding_t *v25; // ecx
  face_t *v26; // eax
  winding_t *v27; // edx
  float dist; // [esp+0h] [ebp-34h]
  Vector temp; // [esp+1Ch] [ebp-18h] BYREF
  winding_t *frontw; // [esp+28h] [ebp-Ch] BYREF
  winding_t *backw; // [esp+2Ch] [ebp-8h] BYREF
  float mins; // [esp+30h] [ebp-4h]

  if ( f->merged == nullptr && f->split[0] == nullptr && f->split[1] == nullptr )
  {
    v2 = &texinfo.m_Memory.m_pMemory[f->texinfo];
    if ( (v2->flags & 0x400) == 0 )
    {
      w = f->w;
      p_numpoints = &v2->lightmapVecsLuxelsPerWorldUnits[0][1];
      backw = nullptr;
      frontw = (winding_t *)&v2->lightmapVecsLuxelsPerWorldUnits[0][1];
      while ( 1 )
      {
        v5 = *(p_numpoints - 1);
        v6 = -999999.0;
        temp.x = v5;
        v7 = *p_numpoints;
        temp.y = *p_numpoints;
        v8 = p_numpoints[1];
        temp.z = v8;
        numpoints = w->numpoints;
        v10 = 0;
        v11 = 999999.0;
        mins = 999999.0;
        if ( numpoints >= 4 )
        {
          p = w->p;
          p_z = &p->z;
          v14 = &p[1].z;
          v15 = ((unsigned int)(numpoints - 4) >> 2) + 1;
          v10 = 4 * v15;
          do
          {
            v16 = (float)((float)(*(p_z - 2) * v5) + (float)(*(p_z - 1) * v7)) + (float)(*p_z * v8);
            if ( v11 > v16 )
              v11 = (float)((float)(*(p_z - 2) * v5) + (float)(*(p_z - 1) * v7)) + (float)(*p_z * v8);
            if ( v16 > v6 )
              v6 = (float)((float)(*(p_z - 2) * v5) + (float)(*(p_z - 1) * v7)) + (float)(*p_z * v8);
            v17 = (float)((float)(*(v14 - 1) * v7) + (float)(p_z[1] * v5)) + (float)(*v14 * v8);
            if ( v11 > v17 )
              v11 = (float)((float)(*(v14 - 1) * v7) + (float)(p_z[1] * v5)) + (float)(*v14 * v8);
            if ( v17 > v6 )
              v6 = (float)((float)(*(v14 - 1) * v7) + (float)(p_z[1] * v5)) + (float)(*v14 * v8);
            v18 = (float)((float)(v14[2] * v7) + (float)(p_z[4] * v5)) + (float)(v14[3] * v8);
            if ( v11 > v18 )
              v11 = (float)((float)(v14[2] * v7) + (float)(p_z[4] * v5)) + (float)(v14[3] * v8);
            if ( v18 > v6 )
              v6 = (float)((float)(v14[2] * v7) + (float)(p_z[4] * v5)) + (float)(v14[3] * v8);
            v19 = (float)((float)(v14[5] * v7) + (float)(p_z[7] * v5)) + (float)(v14[6] * v8);
            if ( v11 > v19 )
              v11 = (float)((float)(v14[5] * v7) + (float)(p_z[7] * v5)) + (float)(v14[6] * v8);
            if ( v19 > v6 )
              v6 = (float)((float)(v14[5] * v7) + (float)(p_z[7] * v5)) + (float)(v14[6] * v8);
            p_z += 12;
            v14 += 12;
            --v15;
          }
          while ( v15 != 0 );
          p_numpoints = (float *)&frontw->numpoints;
          mins = v11;
        }
        if ( v10 < numpoints )
        {
          p_x = &w->p[v10].x;
          v21 = numpoints - v10;
          do
          {
            v22 = (float)((float)(p_x[1] * v7) + (float)(*p_x * v5)) + (float)(p_x[2] * v8);
            if ( v11 > v22 )
              v11 = (float)((float)(p_x[1] * v7) + (float)(*p_x * v5)) + (float)(p_x[2] * v8);
            if ( v22 > v6 )
              v6 = (float)((float)(p_x[1] * v7) + (float)(*p_x * v5)) + (float)(p_x[2] * v8);
            p_x += 3;
            --v21;
          }
          while ( v21 != 0 );
          mins = v11;
        }
        if ( g_maxLightmapDimension < (float)(v6 - v11) )
          break;
        p_numpoints += 4;
        backw = (winding_t *)((char *)backw + 1);
        frontw = (winding_t *)p_numpoints;
        if ( (int)backw >= 2 )
          return;
      }
      ++c_subdivide;
      v23 = VectorNormalize(vec: &temp);
      dist = (g_maxLightmapDimension + mins - 1.0) / v23;
      ClipWindingEpsilon(in: w, normal: &temp, dist, epsilon: 0.1, front: &frontw, back: &backw);
      if ( frontw == nullptr || backw == nullptr )
        _Error(a1: "SubdivideFace: didn't split the polygon");
      v24 = NewFaceFromFace(f);
      v25 = frontw;
      f->split[0] = v24;
      v24->w = v25;
      f->split[0]->next = *pFaceList;
      *pFaceList = f->split[0];
      v26 = NewFaceFromFace(f);
      v27 = backw;
      f->split[1] = v26;
      v26->w = v27;
      f->split[1]->next = *pFaceList;
      *pFaceList = f->split[1];
      SubdivideFace(pFaceList, f: f->split[0]);
      SubdivideFace(pFaceList, f: f->split[1]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411220
// Name: void SubdivideFaceList(struct face_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SubdivideFaceList(face_t **pFaceList)
{
  face_t *i; // ebx
  winding_t *w; // ecx
  float *v3; // eax
  float v4; // xmm2_4
  float v5; // xmm5_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  int numpoints; // esi
  int v9; // edi
  float v10; // xmm1_4
  Vector *p; // eax
  float *p_z; // edx
  float *v13; // ecx
  unsigned int v14; // eax
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  float *p_x; // eax
  int v20; // esi
  float v21; // xmm0_4
  double v22; // st7
  face_t *v23; // eax
  winding_t *v24; // edx
  face_t *v25; // eax
  winding_t *v26; // ecx
  float dist; // [esp+0h] [ebp-40h]
  Vector vec; // [esp+1Ch] [ebp-24h] BYREF
  winding_t *back; // [esp+28h] [ebp-18h] BYREF
  winding_t *front; // [esp+2Ch] [ebp-14h] BYREF
  winding_t *in; // [esp+30h] [ebp-10h]
  int v32; // [esp+34h] [ebp-Ch]
  float v33; // [esp+38h] [ebp-8h]
  float *v34; // [esp+3Ch] [ebp-4h]

  for ( i = *pFaceList; i != nullptr; i = i->next )
  {
    if ( i->merged == nullptr
      && i->split[0] == nullptr
      && i->split[1] == nullptr
      && (texinfo.m_Memory.m_pMemory[i->texinfo].flags & 0x400) == 0 )
    {
      w = i->w;
      v3 = &texinfo.m_Memory.m_pMemory[i->texinfo].lightmapVecsLuxelsPerWorldUnits[0][1];
      v32 = 0;
      in = w;
      v34 = v3;
      while ( 1 )
      {
        v4 = *(v3 - 1);
        v5 = -999999.0;
        vec.x = v4;
        v6 = *v3;
        vec.y = *v3;
        v7 = v3[1];
        vec.z = v7;
        numpoints = w->numpoints;
        v9 = 0;
        v10 = 999999.0;
        v33 = 999999.0;
        if ( numpoints >= 4 )
        {
          p = w->p;
          p_z = &p->z;
          v13 = &p[1].z;
          v14 = ((unsigned int)(numpoints - 4) >> 2) + 1;
          v9 = 4 * v14;
          do
          {
            v15 = (float)((float)(*(p_z - 2) * v4) + (float)(*(p_z - 1) * v6)) + (float)(*p_z * v7);
            if ( v10 > v15 )
              v10 = (float)((float)(*(p_z - 2) * v4) + (float)(*(p_z - 1) * v6)) + (float)(*p_z * v7);
            if ( v15 > v5 )
              v5 = (float)((float)(*(p_z - 2) * v4) + (float)(*(p_z - 1) * v6)) + (float)(*p_z * v7);
            v16 = (float)((float)(*(v13 - 1) * v6) + (float)(p_z[1] * v4)) + (float)(*v13 * v7);
            if ( v10 > v16 )
              v10 = (float)((float)(*(v13 - 1) * v6) + (float)(p_z[1] * v4)) + (float)(*v13 * v7);
            if ( v16 > v5 )
              v5 = (float)((float)(*(v13 - 1) * v6) + (float)(p_z[1] * v4)) + (float)(*v13 * v7);
            v17 = (float)((float)(v13[2] * v6) + (float)(p_z[4] * v4)) + (float)(v13[3] * v7);
            if ( v10 > v17 )
              v10 = (float)((float)(v13[2] * v6) + (float)(p_z[4] * v4)) + (float)(v13[3] * v7);
            if ( v17 > v5 )
              v5 = (float)((float)(v13[2] * v6) + (float)(p_z[4] * v4)) + (float)(v13[3] * v7);
            v18 = (float)((float)(v13[5] * v6) + (float)(p_z[7] * v4)) + (float)(v13[6] * v7);
            if ( v10 > v18 )
              v10 = (float)((float)(v13[5] * v6) + (float)(p_z[7] * v4)) + (float)(v13[6] * v7);
            if ( v18 > v5 )
              v5 = (float)((float)(v13[5] * v6) + (float)(p_z[7] * v4)) + (float)(v13[6] * v7);
            p_z += 12;
            v13 += 12;
            --v14;
          }
          while ( v14 != 0 );
          v3 = v34;
          w = in;
          v33 = v10;
        }
        if ( v9 < numpoints )
        {
          p_x = &w->p[v9].x;
          v20 = numpoints - v9;
          do
          {
            v21 = (float)((float)(p_x[1] * v6) + (float)(*p_x * v4)) + (float)(p_x[2] * v7);
            if ( v10 > v21 )
              v10 = (float)((float)(p_x[1] * v6) + (float)(*p_x * v4)) + (float)(p_x[2] * v7);
            if ( v21 > v5 )
              v5 = (float)((float)(p_x[1] * v6) + (float)(*p_x * v4)) + (float)(p_x[2] * v7);
            p_x += 3;
            --v20;
          }
          while ( v20 != 0 );
          v3 = v34;
          v33 = v10;
        }
        if ( g_maxLightmapDimension < (float)(v5 - v10) )
          break;
        v3 += 4;
        ++v32;
        v34 = v3;
        if ( v32 >= 2 )
          goto LABEL_42;
      }
      ++c_subdivide;
      v22 = VectorNormalize(&vec);
      dist = (g_maxLightmapDimension + v33 - 1.0) / v22;
      ClipWindingEpsilon(in, normal: &vec, dist, epsilon: 0.1, &front, &back);
      if ( front == nullptr || back == nullptr )
        _Error(a1: "SubdivideFace: didn't split the polygon");
      v23 = NewFaceFromFace(f: i);
      v24 = front;
      i->split[0] = v23;
      v23->w = v24;
      i->split[0]->next = *pFaceList;
      *pFaceList = i->split[0];
      v25 = NewFaceFromFace(f: i);
      v26 = back;
      i->split[1] = v25;
      v25->w = v26;
      i->split[1]->next = *pFaceList;
      *pFaceList = i->split[1];
      SubdivideFace(pFaceList, f: i->split[0]);
      SubdivideFace(pFaceList, f: i->split[1]);
    }
LABEL_42:
    ;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411520
// Name: AssignBottomWaterMaterialToFace
// Source: json
//------------------------------------------------------------------------------
char __cdecl AssignBottomWaterMaterialToFace(face_t *f)
{
  texinfo_s *v1; // esi
  dtexdata_t *TexData; // eax
  char *String; // edi
  char pBottomMatName[512]; // [esp+Ch] [ebp-248h] BYREF
  texinfo_s newTexInfo; // [esp+20Ch] [ebp-48h] BYREF

  v1 = &texinfo.m_Memory.m_pMemory[f->texinfo];
  TexData = GetTexData(index: v1->texdata);
  String = TexDataStringTable_GetString(stringID: TexData->nameStringTableID);
  if ( GetValueFromPatchedMaterial(pMaterialName: String, pKey: "$bottommaterial", pValue: pBottomMatName, len: 512) )
  {
    newTexInfo.flags = v1->flags;
    newTexInfo.textureVecsTexelsPerWorldUnits[0][0] = v1->textureVecsTexelsPerWorldUnits[0][0];
    newTexInfo.lightmapVecsLuxelsPerWorldUnits[0][0] = v1->lightmapVecsLuxelsPerWorldUnits[0][0];
    newTexInfo.textureVecsTexelsPerWorldUnits[0][1] = v1->textureVecsTexelsPerWorldUnits[0][1];
    newTexInfo.lightmapVecsLuxelsPerWorldUnits[0][1] = v1->lightmapVecsLuxelsPerWorldUnits[0][1];
    newTexInfo.textureVecsTexelsPerWorldUnits[0][2] = v1->textureVecsTexelsPerWorldUnits[0][2];
    newTexInfo.lightmapVecsLuxelsPerWorldUnits[0][2] = v1->lightmapVecsLuxelsPerWorldUnits[0][2];
    newTexInfo.textureVecsTexelsPerWorldUnits[0][3] = v1->textureVecsTexelsPerWorldUnits[0][3];
    newTexInfo.lightmapVecsLuxelsPerWorldUnits[0][3] = v1->lightmapVecsLuxelsPerWorldUnits[0][3];
    newTexInfo.textureVecsTexelsPerWorldUnits[1][0] = v1->textureVecsTexelsPerWorldUnits[1][0];
    newTexInfo.lightmapVecsLuxelsPerWorldUnits[1][0] = v1->lightmapVecsLuxelsPerWorldUnits[1][0];
    newTexInfo.textureVecsTexelsPerWorldUnits[1][1] = v1->textureVecsTexelsPerWorldUnits[1][1];
    newTexInfo.lightmapVecsLuxelsPerWorldUnits[1][1] = v1->lightmapVecsLuxelsPerWorldUnits[1][1];
    newTexInfo.textureVecsTexelsPerWorldUnits[1][2] = v1->textureVecsTexelsPerWorldUnits[1][2];
    newTexInfo.lightmapVecsLuxelsPerWorldUnits[1][2] = v1->lightmapVecsLuxelsPerWorldUnits[1][2];
    newTexInfo.textureVecsTexelsPerWorldUnits[1][3] = v1->textureVecsTexelsPerWorldUnits[1][3];
    newTexInfo.lightmapVecsLuxelsPerWorldUnits[1][3] = v1->lightmapVecsLuxelsPerWorldUnits[1][3];
    newTexInfo.texdata = FindOrCreateTexData(pName_: pBottomMatName);
    f->texinfo = FindOrCreateTexInfo(searchTexInfo: &newTexInfo);
    return 1;
  }
  else
  {
    if ( V_stristr(pStr: String, pSearch: "nodraw") == nullptr
      && V_stristr(pStr: String, pSearch: "toolsskip") == nullptr )
    {
      _Warning(a1: "error: material %s doesn't have a $bottommaterial\n", String);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411680
// Name: struct face_t __near * FaceFromPortal(struct portal_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
face_t *__cdecl FaceFromPortal(portal_t *p, int pside)
{
  side_t *side; // edi
  void *v4; // esi
  int v5; // eax
  unsigned int smoothingGroups; // edx
  node_t **v7; // edi
  int v8; // eax
  node_t *v9; // edx
  int contents; // ecx
  node_t *v11; // edi
  portal_t *v12; // ecx

  side = p->side;
  if ( side == nullptr )
    return nullptr;
  v4 = MemAlloc_Alloc(nSize: 0xD0u);
  memset(dst: (unsigned __int8 *)v4, value: 0, count: 0xD0u);
  v5 = s_FaceId;
  *(_DWORD *)v4 = s_FaceId;
  ++c_faces;
  *((_DWORD *)v4 + 47) = side;
  *((_DWORD *)v4 + 6) = side->texinfo;
  *((_DWORD *)v4 + 7) = -1;
  smoothingGroups = side->smoothingGroups;
  s_FaceId = v5 + 1;
  *((_DWORD *)v4 + 50) = smoothingGroups;
  *((_DWORD *)v4 + 9) = pside | side->planenum & 0xFFFFFFFE;
  if ( entity_num != 0 )
  {
    if ( (p->nodes[pside]->contents & 0x30) != 0 )
      *((_DWORD *)v4 + 9) = pside | side->planenum & 0xFFFFFFFE;
    else
      *((_DWORD *)v4 + 9) = side->planenum;
  }
  *((_DWORD *)v4 + 5) = p;
  *((_DWORD *)v4 + 8) = 0;
  v7 = &p->nodes[pside == 0];
  v8 = VisibleContents(contents: (*v7)->contents ^ p->nodes[pside]->contents);
  v9 = p->nodes[pside];
  contents = v9->contents;
  if ( (contents & 2) != 0 && v8 == 2 || (contents & 8) != 0 && v8 == 8 )
  {
    if ( *((_DWORD *)v4 + 12) != 0 )
      FreeWinding(w: *((winding_t **)v4 + 12));
    free(pMem: v4);
    --c_faces;
    return nullptr;
  }
  else
  {
    if ( (contents & 0x4030) != 0 )
    {
      *((_DWORD *)v4 + 8) = v9;
    }
    else
    {
      v11 = *v7;
      if ( (v11->contents & 0x4030) != 0 )
        *((_DWORD *)v4 + 8) = v11;
    }
    v12 = p;
    if ( (p->nodes[pside]->contents & 0x20) != 0 && v8 == 32 )
    {
      if ( AssignBottomWaterMaterialToFace(f: (face_t *)v4) == 0 )
      {
        FreeFace(f: (face_t *)v4);
        return nullptr;
      }
      v12 = p;
    }
    if ( pside != 0 )
    {
      *((_DWORD *)v4 + 12) = ReverseWinding(w: v12->winding);
      *((_DWORD *)v4 + 10) = p->nodes[1]->contents;
    }
    else
    {
      *((_DWORD *)v4 + 12) = CopyWinding(w: v12->winding);
      *((_DWORD *)v4 + 10) = p->nodes[0]->contents;
    }
    *((_DWORD *)v4 + 49) = 0;
    *((_DWORD *)v4 + 48) = 0;
    return (face_t *)v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411820
// Name: void GetEdge2_InitOptimizedList(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetEdge2_InitOptimizedList()
{
  int *v0; // eax

  v0 = &dword_49BD044;
  do
  {
    *v0 = 0;
    v0 += 5;
  }
  while ( (int)v0 < (int)&s_FaceId );
}

//------------------------------------------------------------------------------
// Address: 0x00411850
// Name: bool OverlaysAreEqual(struct face_t __near *,struct face_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl OverlaysAreEqual(face_t *f1, face_t *f2)
{
  side_t *originalface; // eax
  int m_Size; // edx
  side_t *v4; // ecx
  int v6; // ebx
  int v7; // edx
  int *i; // edi
  int v9; // eax
  int *j; // ecx
  face_t *f1a; // [esp+8h] [ebp+8h]
  face_t *f2a; // [esp+Ch] [ebp+Ch]

  originalface = f1->originalface;
  m_Size = originalface->aOverlayIds.m_Size;
  v4 = f2->originalface;
  f1a = (face_t *)m_Size;
  f2a = (face_t *)v4;
  if ( m_Size != v4->aOverlayIds.m_Size )
    return 0;
  v6 = 0;
  if ( m_Size <= 0 )
    return 1;
  v7 = v4->aOverlayIds.m_Size;
  for ( i = originalface->aOverlayIds.m_Memory.m_pMemory; ; ++i )
  {
    v9 = 0;
    if ( v7 <= 0 )
      break;
    for ( j = v4->aOverlayIds.m_Memory.m_pMemory; *j != *i; ++j )
    {
      if ( ++v9 >= v7 )
        return 0;
    }
    if ( v9 == -1 )
      break;
    if ( ++v6 >= (int)f1a )
      return 1;
    v4 = (side_t *)f2a;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00411A50
// Name: void Triangulate_r(class CUtlVector<int,class CUtlMemory<int,int>> __near &,class CUtlVector<int,class CUtlMemory<int,int>> const __near &,class CUtlVector<struct face_vert_table_t,class CUtlMemory<struct face_vert_table_t,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Triangulate_r(
        CUtlVector<int,CUtlMemory<int,int> > *out,
        const CUtlVector<int,CUtlMemory<int,int> > *inIndices,
        const CUtlVector<face_vert_table_t,CUtlMemory<face_vert_table_t,int> > *poly)
{
  const CUtlVector<int,CUtlMemory<int,int> > *v3; // edx
  int m_Size; // ebx
  int v5; // ebx
  int v6; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v9; // eax
  int *v10; // edi
  int v11; // eax
  int v12; // edi
  int v13; // ecx
  int v14; // edx
  face_vert_table_t *v15; // ecx
  int edge0; // esi
  int v17; // edx
  int v18; // ebx
  int edge1; // eax
  int v20; // ecx
  int *v21; // esi
  int v22; // edi
  int *v23; // eax
  int v24; // edi
  int v25; // ecx
  int *v26; // esi
  int *v27; // ecx
  int j; // edi
  int v29; // esi
  int *v30; // ebx
  int *v31; // eax
  int *v32; // eax
  int *v33; // eax
  CUtlVector<int,CUtlMemory<int,int> > in1; // [esp+Ch] [ebp-40h] BYREF
  CUtlVector<int,CUtlMemory<int,int> > in2; // [esp+20h] [ebp-2Ch] BYREF
  int *v36; // [esp+34h] [ebp-18h]
  int nextArray; // [esp+38h] [ebp-14h]
  int index; // [esp+3Ch] [ebp-10h]
  int k; // [esp+40h] [ebp-Ch]
  int v40; // [esp+44h] [ebp-8h]
  int i; // [esp+48h] [ebp-4h]

  v3 = inIndices;
  m_Size = inIndices->m_Size;
  v40 = m_Size;
  if ( m_Size == 3 )
  {
    v5 = 0;
    do
    {
      v6 = out->m_Size;
      m_nAllocationCount = out->m_Memory.m_nAllocationCount;
      nextArray = (int)&v3->m_Memory.m_pMemory[v5];
      if ( v6 + 1 > m_nAllocationCount )
        CUtlMemory<CClassInput *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)out, num: v6 - m_nAllocationCount + 1);
      ++out->m_Size;
      m_pMemory = out->m_Memory.m_pMemory;
      v9 = out->m_Size - v6 - 1;
      out->m_pElements = out->m_Memory.m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * v9);
      v10 = &out->m_Memory.m_pMemory[v6];
      if ( v10 != nullptr )
        *v10 = *(_DWORD *)nextArray;
      v3 = inIndices;
      ++v5;
    }
    while ( v5 < inIndices->m_Size );
  }
  else
  {
    v11 = 0;
    i = 0;
    if ( m_Size > 0 )
    {
      while ( 1 )
      {
        v12 = 2;
        if ( m_Size - 1 > 2 )
          break;
LABEL_21:
        i = ++v11;
        if ( v11 >= m_Size )
          return;
        v3 = inIndices;
      }
      v13 = (int)v3->m_Memory.m_pMemory;
      v14 = v3->m_Memory.m_pMemory[v11];
      k = v13;
      v15 = poly->m_Memory.m_pMemory;
      edge0 = poly->m_Memory.m_pMemory[v14].edge0;
      index = v14;
      while ( 1 )
      {
        v17 = (v12 + v11) % m_Size;
        v18 = *(_DWORD *)(k + 4 * v17);
        nextArray = v17;
        if ( edge0 < 0 || v15[v18].edge0 != edge0 && v15[v18].edge1 != edge0 )
        {
          edge1 = v15[index].edge1;
          if ( edge1 < 0 || v15[v18].edge0 != edge1 && v15[v18].edge1 != edge1 )
            break;
        }
        m_Size = v40;
        ++v12;
        v11 = i;
        if ( v12 >= v40 - 1 )
          goto LABEL_21;
      }
      v20 = 0;
      v21 = nullptr;
      memset(&in1, 0, sizeof(in1));
      k = i;
      if ( i != v17 )
      {
        do
        {
          v36 = &inIndices->m_Memory.m_pMemory[k];
          v22 = v20;
          if ( v20 + 1 > in1.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CClassInput *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&in1,
              num: v20 - in1.m_Memory.m_nAllocationCount + 1);
            v20 = in1.m_Size;
            v21 = in1.m_Memory.m_pMemory;
          }
          in1.m_Size = ++v20;
          in1.m_pElements = v21;
          if ( v20 - v22 - 1 > 0 )
          {
            _V_memmove(dest: &v21[v22 + 1], src: &v21[v22], count: 4 * (v20 - v22 - 1));
            v20 = in1.m_Size;
            v21 = in1.m_Memory.m_pMemory;
          }
          v23 = &v21[v22];
          if ( v23 != nullptr )
          {
            *v23 = *v36;
            v20 = in1.m_Size;
            v21 = in1.m_Memory.m_pMemory;
          }
          k = (k + 1) % v40;
        }
        while ( k != nextArray );
      }
      v24 = v20;
      if ( v20 + 1 > in1.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CClassInput *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&in1,
          num: v20 - in1.m_Memory.m_nAllocationCount + 1);
        v20 = in1.m_Size;
        v21 = in1.m_Memory.m_pMemory;
      }
      in1.m_Size = v20 + 1;
      v25 = v20 - v24;
      in1.m_pElements = v21;
      if ( v25 > 0 )
      {
        _V_memmove(dest: &v21[v24 + 1], src: &v21[v24], count: 4 * v25);
        v21 = in1.m_Memory.m_pMemory;
      }
      v26 = &v21[v24];
      if ( v26 != nullptr )
        *v26 = v18;
      memset(&in2, 0, sizeof(in2));
      CUtlMemory<CClassInput *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&in2, num: 1);
      v27 = in2.m_Memory.m_pMemory;
      ++in2.m_Size;
      in2.m_pElements = in2.m_Memory.m_pMemory;
      if ( in2.m_Size - 1 > 0 )
      {
        _V_memmove(dest: in2.m_Memory.m_pMemory + 1, src: in2.m_Memory.m_pMemory, count: 4 * (in2.m_Size - 1));
        v27 = in2.m_Memory.m_pMemory;
      }
      if ( v27 != nullptr )
      {
        *v27 = index;
        v27 = in2.m_Memory.m_pMemory;
      }
      for ( j = nextArray; j != i; j = (j + 1) % v40 )
      {
        v29 = in2.m_Size;
        v30 = &inIndices->m_Memory.m_pMemory[j];
        if ( in2.m_Size + 1 > in2.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CClassInput *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)&in2,
            num: in2.m_Size - in2.m_Memory.m_nAllocationCount + 1);
          v27 = in2.m_Memory.m_pMemory;
        }
        ++in2.m_Size;
        in2.m_pElements = v27;
        if ( in2.m_Size - v29 - 1 > 0 )
        {
          _V_memmove(dest: &v27[v29 + 1], src: &v27[v29], count: 4 * (in2.m_Size - v29 - 1));
          v27 = in2.m_Memory.m_pMemory;
        }
        v31 = &v27[v29];
        if ( v31 != nullptr )
        {
          *v31 = *v30;
          v27 = in2.m_Memory.m_pMemory;
        }
      }
      Triangulate_r(out, inIndices: &in1, poly);
      Triangulate_r(out, inIndices: &in2, poly);
      v32 = in2.m_Memory.m_pMemory;
      in2.m_Size = 0;
      if ( in2.m_Memory.m_nGrowSize >= 0 )
      {
        if ( in2.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: in2.m_Memory.m_pMemory);
          v32 = nullptr;
          in2.m_Memory.m_pMemory = nullptr;
        }
        in2.m_Memory.m_nAllocationCount = 0;
      }
      in2.m_pElements = v32;
      if ( in2.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v32 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v32);
          in2.m_Memory.m_pMemory = nullptr;
        }
        in2.m_Memory.m_nAllocationCount = 0;
      }
      v33 = in1.m_Memory.m_pMemory;
      in1.m_Size = 0;
      if ( in1.m_Memory.m_nGrowSize >= 0 )
      {
        if ( in1.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: in1.m_Memory.m_pMemory);
          v33 = nullptr;
          in1.m_Memory.m_pMemory = nullptr;
        }
        in1.m_Memory.m_nAllocationCount = 0;
      }
      in1.m_pElements = v33;
      if ( in1.m_Memory.m_nGrowSize >= 0 && v33 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v33);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411DD0
// Name: void FixFaceEdges(struct face_t __near * __near *,struct face_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FixFaceEdges(face_t **pList, face_t *f)
{
  face_t *v2; // ecx
  int v3; // esi
  int v4; // edi
  float x; // xmm5_4
  float v6; // xmm6_4
  float v7; // xmm7_4
  int v8; // ebx
  int v9; // xmm2_4
  int v10; // xmm3_4
  float v11; // xmm4_4
  int v12; // eax
  int v13; // esi
  int i; // ecx
  int v15; // ecx
  int v16; // edi
  int m_Size; // ebx
  int v18; // ecx
  int v19; // eax
  int v20; // esi
  face_vert_table_t *v21; // eax
  int v22; // esi
  int *m_pMemory; // ecx
  int *v24; // eax
  int v25; // eax
  int v26; // esi
  int v27; // eax
  dprimitive_t *v28; // esi
  int v29; // ecx
  int v30; // eax
  int v31; // edx
  int *v32; // edx
  int v33; // eax
  unsigned __int16 *v34; // esi
  face_vert_table_t *v35; // eax
  float end; // [esp+4h] [ebp-1068h]
  _DWORD v37[1024]; // [esp+20h] [ebp-104Ch]
  int numpoints; // [esp+1020h] [ebp-4Ch]
  float v39; // [esp+1024h] [ebp-48h]
  int v40; // [esp+1028h] [ebp-44h]
  CUtlVector<int,CUtlMemory<int,int> > v41; // [esp+102Ch] [ebp-40h] BYREF
  CUtlVector<face_vert_table_t,CUtlMemory<face_vert_table_t,int> > poly; // [esp+1040h] [ebp-2Ch] BYREF
  int *vertexnums; // [esp+1054h] [ebp-18h]
  CUtlVector<int,CUtlMemory<int,int> > out; // [esp+1058h] [ebp-14h] BYREF

  v2 = f;
  v3 = 0;
  if ( f->merged == nullptr && f->split[0] == nullptr && f->split[1] == nullptr )
  {
    numsuperverts = 0;
    numpoints = f->numpoints;
    if ( numpoints <= 0 )
      goto LABEL_8;
    vertexnums = f->vertexnums;
    do
    {
      v4 = *vertexnums;
      v40 = v3 + 1;
      v6 = *(&dvertexes.y + 3 * v4);
      v7 = *(&dvertexes.z + 3 * v4);
      v8 = v2->vertexnums[(v3 + 1) % v2->numpoints];
      v9 = *((int *)&dvertexes.x + 3 * v8);
      v10 = *((int *)&dvertexes.y + 3 * v8);
      v11 = *(&dvertexes.z + 3 * v8);
      edge_start.x = *(&dvertexes.x + 3 * v4);
      x = edge_start.x;
      edge_start.y = v6;
      edge_start.z = v7;
      out.m_Memory.m_nGrowSize = v9;
      out.m_Size = v10;
      *(float *)&out.m_pElements = v11;
      FindEdgeVerts(v1: &edge_start, v2: (Vector *)&out.m_Memory.m_nGrowSize);
      edge_dir.x = *(float *)&v9 - x;
      edge_dir.y = *(float *)&v10 - v6;
      edge_dir.z = v11 - v7;
      v39 = VectorNormalize(vec: &edge_dir);
      end = v39;
      v37[v3] = numsuperverts;
      TestEdge(start: 0.0, end, p1: v4, p2: v8, startvert: 0);
      v12 = numsuperverts;
      v2 = f;
      ++vertexnums;
      v37[v3 + 512] = numsuperverts - v37[v3];
      v3 = v40;
    }
    while ( v40 < f->numpoints );
    if ( v12 >= 3 )
    {
      v13 = f->numpoints;
      for ( i = 0; i < v13; ++i )
      {
        if ( v37[i + 512] == 1 && v37[(v13 + i - 1) % v13 + 512] == 1 )
          break;
      }
      if ( i == v13 )
      {
        f->badstartvert = 1;
        ++c_badstartverts;
        v15 = 0;
      }
      else
      {
        v15 = v37[i];
      }
      FaceFromSuperverts(pListHead: pList, f, base: v15);
      if ( f->badstartvert != 0 && entity_num == 0 )
      {
        v16 = 0;
        memset(&poly, 0, sizeof(poly));
        memset(&v41, 0, sizeof(v41));
        m_Size = 0;
        memset(&out, 0, sizeof(out));
        CUtlVector<face_vert_table_t,CUtlMemory<face_vert_table_t,int>>::InsertMultipleBefore(
          this: &poly,
          elem: 0,
          num: numsuperverts);
        v18 = 0;
        do
        {
          v19 = v37[v18 + 512];
          if ( v19 != v16 && v19 >= v16 )
          {
            v20 = v37[v18];
            v16 = v19 + 1;
            do
            {
              v21 = &poly.m_Memory.m_pMemory[v20 % numsuperverts];
              if ( v21->edge0 == -1 )
                v21->edge0 = v18;
              else
                v21->edge1 = v18;
              ++v20;
              --v16;
            }
            while ( v16 != 0 );
          }
          ++v18;
        }
        while ( v18 < numpoints );
        for ( ; v16 < numsuperverts; ++v16 )
        {
          v22 = m_Size;
          if ( m_Size + 1 > v41.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CClassInput *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&v41,
              num: m_Size - v41.m_Memory.m_nAllocationCount + 1);
            m_Size = v41.m_Size;
          }
          m_pMemory = v41.m_Memory.m_pMemory;
          v41.m_Size = ++m_Size;
          v41.m_pElements = v41.m_Memory.m_pMemory;
          if ( m_Size - v22 - 1 > 0 )
          {
            _V_memmove(
              dest: &v41.m_Memory.m_pMemory[v22 + 1],
              src: &v41.m_Memory.m_pMemory[v22],
              count: 4 * (m_Size - v22 - 1));
            m_pMemory = v41.m_Memory.m_pMemory;
          }
          v24 = &m_pMemory[v22];
          if ( v24 != nullptr )
            *v24 = v16;
        }
        Triangulate_r(&out, inIndices: &v41, &poly);
        v25 = g_numprimitives;
        f->firstPrimID = g_numprimitives;
        v26 = v25;
        ++g_numprimitives;
        f->numPrims = 1;
        v27 = g_numprimindices;
        v28 = &g_primitives[v26];
        v28->firstVert = g_numprimverts;
        v29 = out.m_Size;
        v28->vertCount = 0;
        v28->type = 0;
        v28->firstIndex = v27;
        v30 = (unsigned __int16)v29 + v27;
        v31 = g_numprimitives;
        v28->indexCount = v29;
        g_numprimindices = v30;
        if ( v31 > 0x8000 || v30 > 0x10000 )
        {
          _Error(
            a1: "Too many t-junctions to fix up! (%d prims, max %d :: %d indices, max %d)\n",
            v31,
            0x8000,
            v30,
            0x10000);
          v29 = out.m_Size;
        }
        v32 = out.m_Memory.m_pMemory;
        v33 = 0;
        if ( v29 > 0 )
        {
          v34 = &g_primindices[v28->firstIndex];
          do
            *v34++ = v32[v33++];
          while ( v33 < v29 );
        }
        out.m_Size = 0;
        if ( out.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v32 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v32);
            v32 = nullptr;
            out.m_Memory.m_pMemory = nullptr;
          }
          out.m_Memory.m_nAllocationCount = 0;
        }
        out.m_pElements = v32;
        if ( out.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v32 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v32);
            out.m_Memory.m_pMemory = nullptr;
          }
          out.m_Memory.m_nAllocationCount = 0;
        }
        if ( v41.m_Memory.m_nGrowSize >= 0 && v41.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v41.m_Memory.m_pMemory);
        v35 = poly.m_Memory.m_pMemory;
        poly.m_Size = 0;
        if ( poly.m_Memory.m_nGrowSize >= 0 )
        {
          if ( poly.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: poly.m_Memory.m_pMemory);
            v35 = nullptr;
            poly.m_Memory.m_pMemory = nullptr;
          }
          poly.m_Memory.m_nAllocationCount = 0;
        }
        poly.m_pElements = v35;
        if ( poly.m_Memory.m_nGrowSize >= 0 && v35 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v35);
      }
    }
    else
    {
LABEL_8:
      v2->numpoints = 0;
      ++c_facecollapse;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412220
// Name: void FixEdges_r(struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FixEdges_r(node_t *node)
{
  face_t *i; // esi
  node_t **children; // esi
  int j; // edi

  if ( node->planenum != -1 )
  {
    for ( i = node->faces; i != nullptr; i = i->next )
      FixFaceEdges(pList: &node->faces, f: i);
    children = node->children;
    for ( j = 2; j != 0; --j )
      FixEdges_r(node: *children++);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412280
// Name: struct face_t __near * FixTjuncs(struct node_t __near *,struct face_t __near *)
// Source: json
//------------------------------------------------------------------------------
face_t *__cdecl FixTjuncs(node_t *headnode, face_t *pLeafFaceList)
{
  face_t *i; // esi
  face_t *j; // esi

  qprintf(format: "---- snap verts ----\n");
  memset(dst: (unsigned __int8 *)hashverts, value: 0, count: sizeof(hashverts));
  memset(dst: (unsigned __int8 *)vertexchain, value: 0, count: sizeof(vertexchain));
  c_totalverts = 0;
  c_uniqueverts = 0;
  c_faceoverflows = 0;
  EmitNodeFaceVertexes_r(node: headnode);
  qprintf(format: "---- tjunc ----\n");
  c_tryedges = 0;
  c_degenerate = 0;
  c_facecollapse = 0;
  c_tjunctions = 0;
  if ( g_bAllowDetailCracks )
  {
    FixEdges_r(node: headnode);
    EmitLeafFaceVertexes(ppLeafFaceList: &pLeafFaceList);
    for ( i = pLeafFaceList; i != nullptr; i = i->next )
      FixFaceEdges(pList: &pLeafFaceList, f: i);
  }
  else
  {
    EmitLeafFaceVertexes(ppLeafFaceList: &pLeafFaceList);
    if ( notjunc == 0 )
    {
      FixEdges_r(node: headnode);
      for ( j = pLeafFaceList; j != nullptr; j = j->next )
        FixFaceEdges(pList: &pLeafFaceList, f: j);
    }
  }
  qprintf(format: "%i unique from %i\n", c_uniqueverts, c_totalverts);
  qprintf(format: "%5i edges degenerated\n", c_degenerate);
  qprintf(format: "%5i faces degenerated\n", c_facecollapse);
  qprintf(format: "%5i edges added by tjunctions\n", c_tjunctions);
  qprintf(format: "%5i faces added by tjunctions\n", c_faceoverflows);
  qprintf(format: "%5i bad start verts\n", c_badstartverts);
  return pLeafFaceList;
}

//------------------------------------------------------------------------------
// Address: 0x004123E0
// Name: int AddEdge(int,int,struct face_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AddEdge(int v1, int v2, face_t *f)
{
  int v3; // esi
  CUtlVector<int,CUtlMemory<int,int> > *v4; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v7; // eax
  int *v8; // esi
  int v9; // ebx
  CUtlVector<int,CUtlMemory<int,int> > *v10; // esi
  int v11; // eax
  int *v12; // ecx
  int v13; // eax
  int *v14; // ebx
  int v15; // eax
  dedge_t *v16; // ecx

  if ( numedges >= 256000 )
    _Error(a1: "Too many edges in map, max == %d", 256000);
  v3 = dword_49BD044[5 * v1];
  v4 = (CUtlVector<int,CUtlMemory<int,int> > *)((char *)&g_VertEdgeList + 20 * v1);
  m_nAllocationCount = v4->m_Memory.m_nAllocationCount;
  if ( v3 + 1 > m_nAllocationCount )
    CUtlMemory<CClassInput *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)((char *)&g_VertEdgeList + 20 * v1),
      num: v3 - m_nAllocationCount + 1);
  ++v4->m_Size;
  m_pMemory = v4->m_Memory.m_pMemory;
  v7 = v4->m_Size - v3 - 1;
  v4->m_pElements = v4->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[v3 + 1], src: &m_pMemory[v3], count: 4 * v7);
  v8 = &v4->m_Memory.m_pMemory[v3];
  if ( v8 != nullptr )
    *v8 = numedges;
  v9 = dword_49BD044[5 * v2];
  v10 = (CUtlVector<int,CUtlMemory<int,int> > *)((char *)&g_VertEdgeList + 20 * v2);
  v11 = v10->m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v11 )
    CUtlMemory<CClassInput *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)((char *)&g_VertEdgeList + 20 * v2),
      num: v9 - v11 + 1);
  ++v10->m_Size;
  v12 = v10->m_Memory.m_pMemory;
  v13 = v10->m_Size - v9 - 1;
  v10->m_pElements = v10->m_Memory.m_pMemory;
  if ( v13 > 0 )
    _V_memmove(dest: &v12[v9 + 1], src: &v12[v9], count: 4 * v13);
  v14 = &v10->m_Memory.m_pMemory[v9];
  if ( v14 != nullptr )
    *v14 = numedges;
  IntSort(theList: v4);
  IntSort(theList: v10);
  v15 = numedges;
  v16 = &dedges[numedges];
  v16->v[0] = v1;
  ++v15;
  v16->v[1] = v2;
  numedges = v15;
  *(&c_facecollapse + 2 * v15) = (int)f;
  return v15 - 1;
}

//------------------------------------------------------------------------------
// Address: 0x00412510
// Name: int GetEdge2(int,int,struct face_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetEdge2(int v1, int v2, face_t *f)
{
  int v3; // ecx
  S3RGBA *v4; // edx
  S3RGBA v5; // eax
  int v6; // edi
  int v7; // eax
  CUtlMemory<S3RGBA,int> *v8; // esi
  S3RGBA *m_pMemory; // ecx
  int v10; // eax
  S3RGBA *v11; // edi
  int v12; // ebx
  S3RGBA **v13; // edi
  int v14; // eax
  S3RGBA *v15; // ecx
  int v16; // eax
  S3RGBA *v17; // ebx
  int i; // eax
  S3RGBA *v19; // ecx
  S3RGBA v20; // edx
  S3RGBA v21; // ebx
  int j; // eax
  S3RGBA *v24; // ecx
  S3RGBA v25; // edx
  S3RGBA v26; // esi
  int v27; // ecx
  dedge_t *v28; // eax
  int v29; // [esp+Ch] [ebp-4h]

  ++c_tryedges;
  if ( noshare != 0 || (v3 = 0, (v29 = dword_49BD044[5 * v1]) <= 0) )
  {
LABEL_9:
    if ( numedges >= 256000 )
      _Error(a1: "Too many edges in map, max == %d", 256000);
    v6 = dword_49BD044[5 * v1];
    v7 = *(&g_VertEdgeList.m_nAllocationCount + 5 * v1);
    v8 = (CUtlMemory<S3RGBA,int> *)((char *)&g_VertEdgeList + 20 * v1);
    if ( v6 + 1 > v7 )
      CUtlMemory<CClassInput *,int>::Grow(this: v8, num: v6 - v7 + 1);
    ++v8[1].m_pMemory;
    m_pMemory = v8->m_pMemory;
    v10 = (int)v8[1].m_pMemory - v6 - 1;
    v8[1].m_nAllocationCount = (int)v8->m_pMemory;
    if ( v10 > 0 )
      _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * v10);
    v11 = &v8->m_pMemory[v6];
    if ( v11 != nullptr )
      *v11 = (S3RGBA)numedges;
    v12 = dword_49BD044[5 * v2];
    v13 = &(&g_VertEdgeList.m_pMemory)[5 * v2];
    v14 = (int)v13[1];
    if ( v12 + 1 > v14 )
      CUtlMemory<CClassInput *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)((char *)&g_VertEdgeList + 20 * v2),
        num: v12 - v14 + 1);
    v13[3] = (S3RGBA *)((char *)v13[3] + 1);
    v15 = *v13;
    v16 = (int)v13[3] - v12 - 1;
    v13[4] = *v13;
    if ( v16 > 0 )
      _V_memmove(dest: &v15[v12 + 1], src: &v15[v12], count: 4 * v16);
    v17 = &(*v13)[v12];
    if ( v17 != nullptr )
      *v17 = (S3RGBA)numedges;
    for ( i = 0; i < (int)&v8[1].m_pMemory[-1].a; ++i )
    {
      v19 = &v8->m_pMemory[i];
      v20 = v19[1];
      if ( *(_DWORD *)v19 > *(_DWORD *)&v20 )
      {
        v21 = *v19;
        *v19 = v20;
        v8->m_pMemory[i + 1] = v21;
        if ( i <= 0 )
          i = -1;
        else
          i -= 2;
      }
    }
    for ( j = 0; j < (int)&v13[3][-1].a; ++j )
    {
      v24 = &(*v13)[j];
      v25 = v24[1];
      if ( *(_DWORD *)v24 > *(_DWORD *)&v25 )
      {
        v26 = *v24;
        *v24 = v25;
        (*v13)[j + 1] = v26;
        if ( j <= 0 )
          j = -1;
        else
          j -= 2;
      }
    }
    v27 = numedges;
    v28 = &dedges[numedges];
    v28->v[0] = v1;
    ++v27;
    v28->v[1] = v2;
    *(&c_facecollapse + 2 * v27) = (int)f;
    numedges = v27;
    return v27 - 1;
  }
  else
  {
    v4 = (&g_VertEdgeList.m_pMemory)[5 * v1];
    while ( 1 )
    {
      v5 = *v4;
      if ( v1 == (unsigned __int16)word_4DC75C2[2 * *(_DWORD *)v4]
        && v2 == dedges[*(_DWORD *)&v5].v[0]
        && edgefaces[*(_DWORD *)&v5][0]->contents == f->contents
        && dword_47487EC[2 * *(_DWORD *)&v5] == 0 )
      {
        break;
      }
      ++v3;
      ++v4;
      if ( v3 >= v29 )
        goto LABEL_9;
    }
    dword_47487EC[2 * *(_DWORD *)&v5] = (int)f;
    return -*(int *)&v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412730
// Name: struct face_t __near * TryMerge(struct face_t __near *,struct face_t __near *,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
face_t *__cdecl TryMerge(face_t *f1, face_t *f2, Vector *planenormal)
{
  winding_t *w; // ebx
  winding_t *v5; // ebx
  face_t *v6; // esi
  CUtlVector<side_t *,CUtlMemory<side_t *,int> > *v7; // eax
  CUtlVector<side_t *,CUtlMemory<side_t *,int> > *pMergedList; // ebx
  CUtlVector<side_t *,CUtlMemory<side_t *,int> > *v9; // ecx
  face_t *f1a; // [esp+14h] [ebp+8h]

  if ( f1->w == nullptr )
    return nullptr;
  w = f2->w;
  if ( w == nullptr
    || f1->texinfo != f2->texinfo
    || f1->planenum != f2->planenum
    || f1->contents != f2->contents
    || f1->originalface->smoothingGroups != f2->originalface->smoothingGroups
    || OverlaysAreEqual(f1, f2) == 0
    || nomergewater != 0 && (FaceOnWaterBrush(face: f1) || FaceOnWaterBrush(face: f2)) )
  {
    return nullptr;
  }
  v5 = TryMergeWinding(f1: f1->w, f2: w, planenormal);
  if ( v5 == nullptr )
    return nullptr;
  ++c_merge;
  v6 = NewFaceFromFace(f: f1);
  v6->w = v5;
  v7 = (CUtlVector<side_t *,CUtlMemory<side_t *,int> > *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v7 != nullptr )
  {
    v7->m_Memory.m_pMemory = nullptr;
    v7->m_Memory.m_nAllocationCount = 0;
    v7->m_Memory.m_nGrowSize = 0;
    v7->m_Size = 0;
    v7->m_pElements = nullptr;
  }
  else
  {
    v7 = nullptr;
  }
  v6->pMergedList = v7;
  CUtlVector<side_t *,CUtlMemory<side_t *,int>>::InsertBefore(this: v7, elem: v7->m_Size, src: &f1->originalface);
  CUtlVector<side_t *,CUtlMemory<side_t *,int>>::InsertBefore(
    this: v6->pMergedList,
    elem: v6->pMergedList->m_Size,
    src: &f2->originalface);
  if ( f1->pMergedList != nullptr )
  {
    CUtlVector<side_t *,CUtlMemory<side_t *,int>>::AddVectorToTail(this: v6->pMergedList, src: f1->pMergedList);
    pMergedList = f1->pMergedList;
    if ( pMergedList != nullptr )
    {
      CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)f1->pMergedList);
      free(pMem: pMergedList);
    }
    f1->pMergedList = nullptr;
  }
  if ( f2->pMergedList != nullptr )
  {
    CUtlVector<side_t *,CUtlMemory<side_t *,int>>::AddVectorToTail(this: v6->pMergedList, src: f2->pMergedList);
    v9 = f2->pMergedList;
    f1a = (face_t *)v9;
    if ( v9 != nullptr )
    {
      CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)v9);
      free(pMem: f1a);
    }
    f2->pMergedList = nullptr;
  }
  f1->merged = v6;
  f2->merged = v6;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x004128E0
// Name: void MergeFaceList(struct face_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MergeFaceList(face_t **pList)
{
  face_t *i; // edi
  face_t *v2; // esi
  face_t *v3; // eax
  face_t *v4; // edx
  face_t *j; // ecx

  for ( i = *pList; i != nullptr; i = i->next )
  {
    if ( i->merged == nullptr && i->split[0] == nullptr && i->split[1] == nullptr )
    {
      v2 = *pList;
      if ( *pList != i )
      {
        while ( 1 )
        {
          if ( v2->merged == nullptr && v2->split[0] == nullptr && v2->split[1] == nullptr )
          {
            v3 = TryMerge(f1: i, f2: v2, planenormal: &g_MainMap->mapplanes[i->planenum].normal);
            if ( v3 != nullptr )
              break;
          }
          v2 = v2->next;
          if ( v2 == i )
            goto LABEL_15;
        }
        v4 = *pList;
        for ( j = (*pList)->next; j != nullptr; j = j->next )
          v4 = j;
        v3->next = nullptr;
        v4->next = v3;
      }
    }
LABEL_15:
    ;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412980
// Name: void MakeFaces_r(struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MakeFaces_r(node_t *node)
{
  portal_t *i; // esi
  BOOL v2; // edi
  face_t *v3; // eax

  if ( node->planenum == -1 )
  {
    if ( (node->contents & 1) == 0 )
    {
      for ( i = node->portals; i != nullptr; i = i->next[v2] )
      {
        v2 = i->nodes[1] == node;
        v3 = FaceFromPortal(p: i, pside: v2);
        i->face[v2] = v3;
        if ( v3 != nullptr )
        {
          ++c_nodefaces;
          i->face[v2]->next = i->onnode->faces;
          i->onnode->faces = i->face[v2];
        }
      }
    }
  }
  else
  {
    MakeFaces_r(node: node->children[0]);
    MakeFaces_r(node: node->children[1]);
    if ( nomerge == 0 )
      MergeFaceList(pList: &node->faces);
    if ( nosubdiv == 0 )
      SubdivideFaceList(pFaceList: &node->faces);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412A30
// Name: void MakeFaces(struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MakeFaces(node_t *node)
{
  qprintf(format: "--- MakeFaces ---\n");
  c_merge = 0;
  c_subdivide = 0;
  c_nodefaces = 0;
  MakeFaces_r(node);
  qprintf(format: "%5i makefaces\n", c_nodefaces);
  qprintf(format: "%5i merged\n", c_merge);
  qprintf(format: "%5i subdivided\n", c_subdivide);
}
