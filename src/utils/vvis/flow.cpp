// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vvis/flow.cpp
// Functions: 12
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1000B2C0
// Name: int CountBits(unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CountBits(unsigned __int8 *bits, int numbits)
{
  int result; // eax
  int v3; // ecx
  char i; // dl

  result = 0;
  v3 = 0;
  for ( i = 1; v3 < numbits; i = __ROL1__(i, 1) )
  {
    if ( ((unsigned __int8)i & bits[v3 >> 3]) != 0 )
      ++result;
    ++v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000B2F0
// Name: struct winding_t __near * AllocStackWinding(struct pstack_t __near *)
// Source: json
//------------------------------------------------------------------------------
winding_t *__cdecl AllocStackWinding(pstack_t *stack)
{
  int v1; // eax
  int *i; // ecx

  v1 = 0;
  for ( i = stack->freewindings; *i == 0; ++i )
  {
    if ( ++v1 >= 3 )
    {
      _Error(a1: "Out of memory. AllocStackWinding: failed");
      return nullptr;
    }
  }
  stack->freewindings[v1] = 0;
  return &stack->windings[v1];
}

//------------------------------------------------------------------------------
// Address: 0x1000B340
// Name: void FreeStackWinding(struct winding_t __near *,struct pstack_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FreeStackWinding(winding_t *w, pstack_t *stack)
{
  unsigned int v2; // esi

  v2 = ((char *)w - (char *)stack - 8212) / 152;
  if ( v2 <= 2 )
  {
    if ( stack->freewindings[v2] != 0 )
      _Error(a1: "FreeStackWinding: allready free");
    stack->freewindings[v2] = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B390
// Name: struct winding_t __near * ChopWinding(struct winding_t __near *,struct pstack_t __near *,struct plane_t __near *)
// Source: json
//------------------------------------------------------------------------------
winding_t *__cdecl ChopWinding(winding_t *in, pstack_t *stack, plane_t *split)
{
  int numpoints; // esi
  int v4; // ebx
  int v5; // eax
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // xmm3_4
  float dist; // xmm4_4
  float *p_z; // edx
  float v11; // xmm0_4
  unsigned int v12; // esi
  float v14; // xmm0_4
  winding_t *v15; // esi
  float *v16; // ecx
  int v17; // eax
  int v18; // edx
  float *p_x; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  float v23; // xmm4_4
  float v24; // xmm2_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  float *v29; // eax
  unsigned int v30; // edi
  unsigned int v31; // esi
  float dists[128]; // [esp+Ch] [ebp-40Ch]
  int sides[128]; // [esp+20Ch] [ebp-20Ch]
  int counts[3]; // [esp+40Ch] [ebp-Ch] BYREF

  numpoints = in->numpoints;
  v4 = 0;
  v5 = 0;
  memset(counts, 0, sizeof(counts));
  if ( numpoints <= 0 )
    return in;
  y = split->normal.y;
  x = split->normal.x;
  z = split->normal.z;
  dist = split->dist;
  p_z = &in->points[0].z;
  do
  {
    v11 = (float)((float)((float)(*(p_z - 2) * x) + (float)(*(p_z - 1) * y)) + (float)(z * *p_z)) - dist;
    dists[v5] = v11;
    if ( v11 <= 0.01 )
    {
      if ( v11 >= -0.01 )
        sides[v5] = 2;
      else
        sides[v5] = 1;
    }
    else
    {
      sides[v5] = 0;
    }
    ++counts[sides[v5++]];
    p_z += 3;
  }
  while ( v5 < numpoints );
  if ( counts[1] == 0 )
    return in;
  if ( counts[0] == 0 )
  {
    v12 = ((char *)in - (char *)stack - 8212) / 152;
    if ( v12 <= 2 )
    {
      if ( stack->freewindings[v12] != 0 )
        _Error(a1: "FreeStackWinding: allready free");
      stack->freewindings[v12] = 1;
    }
    return nullptr;
  }
  v14 = dists[0];
  sides[v5] = sides[0];
  dists[v5] = v14;
  v15 = AllocStackWinding(stack);
  v15->numpoints = 0;
  if ( in->numpoints <= 0 )
  {
LABEL_44:
    v30 = ((char *)in - (char *)stack - 8212) / 152;
    if ( v30 <= 2 )
    {
      if ( stack->freewindings[v30] != 0 )
        _Error(a1: "FreeStackWinding: allready free");
      stack->freewindings[v30] = 1;
    }
    return v15;
  }
  v16 = &in->points[0].z;
  while ( 1 )
  {
    v17 = v15->numpoints;
    if ( v17 == 12 )
      break;
    v18 = sides[v4];
    if ( v18 == 2 )
    {
      p_x = &v15->points[v17].x;
      *p_x = *(v16 - 2);
      p_x[1] = *(v16 - 1);
      p_x[2] = *v16;
    }
    else
    {
      if ( v18 == 0 )
      {
        v20 = v17;
        v15->points[v20].x = *(v16 - 2);
        v21 = (int)&v15->points[v20];
        *(float *)(v21 + 4) = *(v16 - 1);
        *(float *)(v21 + 8) = *v16;
        ++v15->numpoints;
      }
      v22 = sides[v4 + 1];
      if ( v22 == 2 || v22 == v18 )
        goto LABEL_43;
      if ( v15->numpoints == 12 )
      {
        FreeStackWinding(w: v15, stack);
        return in;
      }
      v23 = dists[v4] / (float)(dists[v4] - dists[v4 + 1]);
      if ( split->normal.x == 1.0 )
      {
        v24 = split->dist;
      }
      else if ( split->normal.x == -1.0 )
      {
        v24 = -split->dist;
      }
      else
      {
        v24 = (float)((float)(in->points[(v4 + 1) % in->numpoints].x - *(v16 - 2)) * v23) + *(v16 - 2);
      }
      v25 = split->normal.y;
      if ( v25 == 1.0 )
      {
        v26 = split->dist;
      }
      else if ( v25 == -1.0 )
      {
        v26 = -split->dist;
      }
      else
      {
        v26 = (float)((float)(in->points[(v4 + 1) % in->numpoints].y - *(v16 - 1)) * v23) + *(v16 - 1);
      }
      v27 = split->normal.z;
      if ( v27 == 1.0 )
      {
        v28 = split->dist;
      }
      else if ( v27 == -1.0 )
      {
        v28 = -split->dist;
      }
      else
      {
        v28 = (float)((float)(in->points[(v4 + 1) % in->numpoints].z - *v16) * v23) + *v16;
      }
      v29 = &v15->points[v15->numpoints].x;
      *v29 = v24;
      v29[1] = v26;
      v29[2] = v28;
    }
    ++v15->numpoints;
LABEL_43:
    ++v4;
    v16 += 3;
    if ( v4 >= in->numpoints )
      goto LABEL_44;
  }
  v31 = ((char *)v15 - (char *)stack - 8212) / 152;
  if ( v31 <= 2 )
  {
    if ( stack->freewindings[v31] != 0 )
      _Error(a1: "FreeStackWinding: allready free");
    stack->freewindings[v31] = 1;
  }
  return in;
}

//------------------------------------------------------------------------------
// Address: 0x1000B750
// Name: struct winding_t __near * ClipToSeperators(struct winding_t __near *,struct winding_t __near *,struct winding_t __near *,bool,struct pstack_t __near *)
// Source: json
//------------------------------------------------------------------------------
winding_t *__cdecl ClipToSeperators(
        winding_t *source,
        winding_t *pass,
        winding_t *target,
        bool flipclip,
        pstack_t *stack)
{
  winding_t *v5; // esi
  int numpoints; // ecx
  int v7; // edx
  float *p_z; // ebx
  int v9; // edx
  int v10; // edi
  float v11; // xmm0_4
  float y; // xmm7_4
  float z; // xmm1_4
  int v14; // esi
  float *v15; // eax
  float v16; // xmm6_4
  float v17; // xmm2_4
  float v18; // xmm5_4
  float v19; // xmm0_4
  float v20; // xmm4_4
  float v21; // xmm1_4
  float v22; // xmm3_4
  float v23; // xmm4_4
  int v24; // edx
  float v25; // xmm4_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm3_4
  char v29; // bl
  int v30; // eax
  float v31; // xmm2_4
  float *v32; // ecx
  float v33; // xmm4_4
  int v34; // eax
  int v35; // edx
  float *v36; // ecx
  float v37; // xmm4_4
  float v38; // xmm4_4
  float v39; // xmm4_4
  float v40; // xmm4_4
  bool v41; // zf
  float *v42; // ecx
  int v43; // edx
  float v44; // xmm4_4
  plane_t plane; // [esp+Ch] [ebp-40h] BYREF
  Vector v1; // [esp+1Ch] [ebp-30h]
  int counts[3]; // [esp+28h] [ebp-24h]
  int v49; // [esp+34h] [ebp-18h]
  int l; // [esp+38h] [ebp-14h]
  float v51; // [esp+3Ch] [ebp-10h]
  int i; // [esp+40h] [ebp-Ch]
  float *v53; // [esp+44h] [ebp-8h]
  float *v54; // [esp+48h] [ebp-4h]

  v5 = source;
  numpoints = source->numpoints;
  v7 = 0;
  i = 0;
  if ( numpoints <= 0 )
    return target;
  p_z = &source->points[0].z;
  v54 = &source->points[0].z;
  while ( 1 )
  {
    v49 = v7 + 1;
    v9 = (v7 + 1) % numpoints;
    v10 = 0;
    v11 = v5->points[v9].x - *(p_z - 2);
    y = v5->points[v9].y - *(p_z - 1);
    z = v5->points[v9].z - *p_z;
    v14 = pass->numpoints;
    l = v9;
    v1.x = v11;
    v1.y = y;
    v1.z = z;
    if ( v14 > 0 )
      break;
LABEL_56:
    v7 = v49;
    numpoints = source->numpoints;
    p_z += 3;
    i = v49;
    v54 = p_z;
    if ( v49 >= numpoints )
      return target;
    v5 = source;
  }
  v15 = &pass->points[0].z;
  v53 = &pass->points[0].z;
  while ( 1 )
  {
    v16 = *(v15 - 1);
    v17 = *(v15 - 2);
    v51 = *v15;
    v18 = v51 - *p_z;
    v19 = (float)(v18 * y) - (float)((float)(v16 - *(p_z - 1)) * z);
    v20 = v17 - *(p_z - 2);
    v21 = (float)(z * v20) - (float)(v18 * v1.x);
    v22 = (float)((float)(v16 - *(p_z - 1)) * v1.x) - (float)(v20 * v1.y);
    v23 = (float)((float)(v21 * v21) + (float)(v19 * v19)) + (float)(v22 * v22);
    if ( v23 < 0.01 )
      goto LABEL_55;
    v24 = source->numpoints;
    v25 = 1.0 / fsqrt(v23);
    v26 = v19 * v25;
    v27 = v21 * v25;
    v28 = v22 * v25;
    v29 = 0;
    v30 = 0;
    v31 = (float)((float)(v17 * v26) + (float)(v16 * v27)) + (float)(v51 * v28);
    plane.normal.x = v26;
    plane.normal.y = v27;
    plane.normal.z = v28;
    plane.dist = v31;
    if ( v24 > 0 )
    {
      v32 = &source->points[0].z;
      while ( 1 )
      {
        if ( v30 != i && v30 != l )
        {
          v33 = (float)((float)((float)(*(v32 - 2) * v26) + (float)(*(v32 - 1) * v27)) + (float)(*v32 * v28)) - v31;
          if ( v33 < -0.01 )
          {
            v29 = 0;
            goto LABEL_18;
          }
          if ( v33 > 0.01 )
            break;
        }
        ++v30;
        v32 += 3;
        if ( v30 >= v24 )
          goto LABEL_18;
      }
      v29 = 1;
    }
LABEL_18:
    if ( v30 != v24 )
    {
      if ( v29 != 0 )
      {
        LODWORD(v31) ^= _mask__NegFloat_;
        v26 = vec3_origin.x - v26;
        v27 = vec3_origin.y - v27;
        v28 = vec3_origin.z - v28;
        plane.normal.x = v26;
        plane.normal.y = v27;
        plane.normal.z = v28;
        plane.dist = v31;
      }
      v34 = 0;
      counts[0] = 0;
      if ( v14 >= 4 )
      {
        v35 = 2;
        v36 = &pass->points[0].z;
        do
        {
          if ( v34 != v10 )
          {
            v37 = (float)((float)((float)(*(v36 - 1) * v27) + (float)(*(v36 - 2) * v26)) + (float)(*v36 * v28)) - v31;
            if ( v37 < -0.01 )
              goto LABEL_48;
            if ( v37 > 0.01 )
              ++counts[0];
          }
          if ( v35 - 1 != v10 )
          {
            v38 = (float)((float)((float)(v36[2] * v27) + (float)(v36[1] * v26)) + (float)(v36[3] * v28)) - v31;
            if ( v38 < -0.01 )
            {
              ++v34;
              goto LABEL_48;
            }
            if ( v38 > 0.01 )
              ++counts[0];
          }
          if ( v35 != v10 )
          {
            v39 = (float)((float)((float)(v36[5] * v27) + (float)(v36[4] * v26)) + (float)(v36[6] * v28)) - v31;
            if ( v39 < -0.01 )
            {
              v34 += 2;
              goto LABEL_48;
            }
            if ( v39 > 0.01 )
              ++counts[0];
          }
          if ( v35 + 1 != v10 )
          {
            v40 = (float)((float)((float)(v36[8] * v27) + (float)(v36[7] * v26)) + (float)(v36[9] * v28)) - v31;
            if ( v40 < -0.01 )
            {
              v34 += 3;
              goto LABEL_48;
            }
            if ( v40 > 0.01 )
              ++counts[0];
          }
          v34 += 4;
          v35 += 4;
          v36 += 12;
        }
        while ( v34 < v14 - 3 );
      }
      v41 = v34 == v14;
      if ( v34 < v14 )
      {
        v42 = &pass->points[v34].z;
        v43 = counts[0];
        do
        {
          if ( v34 != v10 )
          {
            v44 = (float)((float)((float)(*(v42 - 1) * v27) + (float)(*(v42 - 2) * v26)) + (float)(v28 * *v42)) - v31;
            if ( v44 < -0.01 )
              break;
            if ( v44 > 0.01 )
              ++v43;
          }
          ++v34;
          v42 += 3;
        }
        while ( v34 < v14 );
        counts[0] = v43;
LABEL_48:
        v41 = v34 == v14;
      }
      if ( v41 && counts[0] != 0 )
      {
        if ( flipclip )
        {
          plane.normal.y = vec3_origin.y - v27;
          plane.normal.x = vec3_origin.x - v26;
          plane.normal.z = vec3_origin.z - v28;
          plane.dist = -v31;
        }
        target = ChopWinding(in: target, stack, split: &plane);
        if ( target == nullptr )
          return nullptr;
      }
    }
    p_z = v54;
LABEL_55:
    v14 = pass->numpoints;
    z = v1.z;
    ++v10;
    v15 = v53 + 3;
    v53 += 3;
    if ( v10 >= v14 )
      goto LABEL_56;
    y = v1.y;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BC00
// Name: class Vector ClusterCenter(int)
// Source: json
//------------------------------------------------------------------------------
Vector *__cdecl ClusterCenter(Vector *result, int cluster)
{
  int v2; // eax
  int m_Size; // edx
  int v4; // ecx
  winding_t *winding; // edi
  int v6; // esi
  const Vector *points; // ebx
  float v9; // xmm1_4
  float v10; // xmm2_4
  Vector mins; // [esp+0h] [ebp-20h] BYREF
  Vector maxs; // [esp+Ch] [ebp-14h] BYREF
  int v13; // [esp+18h] [ebp-8h]
  int count; // [esp+1Ch] [ebp-4h]
  int i; // [esp+2Ch] [ebp+Ch]

  ClearBounds(&mins, &maxs);
  v2 = 20 * cluster;
  m_Size = leafs[cluster].portals.m_Size;
  v4 = 0;
  v13 = 20 * cluster;
  count = m_Size;
  for ( i = 0; v4 < m_Size; i = v4 )
  {
    winding = (*(portal_t ***)((char *)&leafs->portals.m_Memory.m_pMemory + v2))[v4]->winding;
    v6 = 0;
    if ( winding->numpoints > 0 )
    {
      points = winding->points;
      do
      {
        AddPointToBounds(v: points, &mins, &maxs);
        ++v6;
        ++points;
      }
      while ( v6 < winding->numpoints );
      m_Size = count;
      v4 = i;
      v2 = v13;
    }
    ++v4;
  }
  v9 = (float)(mins.y + maxs.y) * 0.5;
  v10 = (float)(maxs.z + mins.z) * 0.5;
  result->x = (float)(maxs.x + mins.x) * 0.5;
  result->y = v9;
  result->z = v10;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000BCE0
// Name: void WritePortalTrace(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WritePortalTrace(const char *source)
{
  _iobuf *v1; // ebx
  int v2; // edi
  int v3; // esi
  float z; // eax
  char filename[1024]; // [esp+24h] [ebp-40Ch] BYREF
  Vector p; // [esp+424h] [ebp-Ch]

  if ( g_PortalTrace.m_list.m_Size != 0 )
  {
    sprintf(string: filename, format: "%s.lin", source);
    v1 = fopen(file: filename, mode: "w");
    if ( v1 == nullptr )
      _Error(a1: "Couldn't open %s\n", filename);
    v2 = 0;
    if ( g_PortalTrace.m_list.m_Size > 0 )
    {
      v3 = 0;
      do
      {
        z = g_PortalTrace.m_list.m_Memory.m_pMemory[v3].z;
        *(_QWORD *)&p.x = *(_QWORD *)&g_PortalTrace.m_list.m_Memory.m_pMemory[v3].x;
        p.z = z;
        fprintf(str: v1, format: "%f %f %f\n", p.x, p.y, z);
        ++v2;
        ++v3;
      }
      while ( v2 < g_PortalTrace.m_list.m_Size );
    }
    fclose(stream: v1);
    _Warning(a1: "Wrote %s!!!\n", filename);
  }
  else
  {
    _Warning(a1: "No trace generated from %d to %d\n", g_TraceClusterStart, g_TraceClusterStop);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BDF0
// Name: void SimpleFlood(struct portal_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SimpleFlood(portal_t *srcportal, int leafnum)
{
  bool v2; // cc
  leaf_t *v3; // eax
  portal_t *v4; // edi
  int v5; // edx
  char v6; // si
  int v7; // eax
  int v8; // edx
  unsigned __int8 *portalflood; // ecx
  leaf_t *leaf; // [esp+0h] [ebp-4h]
  int i; // [esp+10h] [ebp+Ch]

  v2 = leafs[leafnum].portals.m_Size <= 0;
  v3 = &leafs[leafnum];
  leaf = v3;
  i = 0;
  if ( !v2 )
  {
    while ( 1 )
    {
      v4 = v3->portals.m_Memory.m_pMemory[i];
      v5 = v4 - portals;
      v6 = v5 & 7;
      v7 = 1 << (v5 & 7);
      v8 = v5 >> 3;
      if ( ((unsigned __int8)v7 & srcportal->portalfront[v8]) != 0 )
      {
        portalflood = srcportal->portalflood;
        if ( ((unsigned __int8)v7 & portalflood[v8]) == 0 )
        {
          portalflood[v8] |= 1 << v6;
          SimpleFlood(srcportal, leafnum: v4->leaf);
        }
      }
      if ( ++i >= leaf->portals.m_Size )
        break;
      v3 = leaf;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BEA0
// Name: void BasePortalVis(int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BasePortalVis(int iThread, int portalnum)
{
  int v2; // edi
  portal_t *v3; // esi
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // eax
  portal_t *v7; // ebx
  int v8; // eax
  winding_t *winding; // ecx
  int numpoints; // edx
  int v11; // eax
  float y; // xmm0_4
  float x; // xmm1_4
  float z; // xmm2_4
  float dist; // xmm3_4
  float *v16; // ecx
  bool v17; // zf
  float *p_z; // ecx
  winding_t *v19; // edi
  int v20; // edx
  int v21; // eax
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  float *v26; // ecx
  bool v27; // zf
  float *v28; // ecx
  winding_t *v29; // eax
  int v30; // edx
  double v31; // xmm0_8
  int v32; // edi
  float v33; // xmm4_4
  float v34; // xmm5_4
  float v35; // xmm6_4
  float *v36; // eax
  unsigned int v37; // ecx
  float *v38; // eax
  int v39; // edx
  int v40; // eax
  char v41; // cl
  portal_t *tp; // [esp+Ch] [ebp-Ch]
  int j; // [esp+10h] [ebp-8h]
  char v44; // [esp+17h] [ebp-1h]
  int portalnuma; // [esp+24h] [ebp+Ch]

  v2 = portalnum;
  v3 = &portals[portalnum];
  v4 = (unsigned __int8 *)malloc(size: portalbytes);
  v3->portalfront = v4;
  memset(dst: v4, value: 0, count: portalbytes);
  v5 = (unsigned __int8 *)malloc(size: portalbytes);
  v3->portalflood = v5;
  memset(dst: v5, value: 0, count: portalbytes);
  v6 = (unsigned __int8 *)malloc(size: portalbytes);
  v3->portalvis = v6;
  memset(dst: v6, value: 0, count: portalbytes);
  v7 = portals;
  v8 = 0;
  j = 0;
  tp = portals;
  v44 = 1;
  if ( 2 * g_numportals > 0 )
  {
    while ( 1 )
    {
      if ( v8 == v2 )
        goto LABEL_58;
      winding = v7->winding;
      numpoints = winding->numpoints;
      v11 = 0;
      if ( numpoints < 4 )
      {
LABEL_12:
        v17 = v11 == numpoints;
        if ( v11 >= numpoints )
          goto LABEL_21;
        p_z = &v7->winding->points[v11].z;
        do
        {
          if ( (float)((float)((float)((float)(*(p_z - 2) * v3->plane.normal.x)
                                     + (float)(*(p_z - 1) * v3->plane.normal.y))
                             + (float)(v3->plane.normal.z * *p_z))
                     - v3->plane.dist) > 0.01 )
            break;
          ++v11;
          p_z += 3;
        }
        while ( v11 < numpoints );
      }
      else
      {
        y = v3->plane.normal.y;
        x = v3->plane.normal.x;
        z = v3->plane.normal.z;
        dist = v3->plane.dist;
        v16 = &winding->points[0].z;
        while ( (float)((float)((float)((float)(*(v16 - 2) * x) + (float)(*(v16 - 1) * y)) + (float)(z * *v16)) - dist) <= 0.01 )
        {
          if ( (float)((float)((float)((float)(v16[1] * x) + (float)(v16[2] * y)) + (float)(v16[3] * z)) - dist) > 0.01 )
          {
            ++v11;
            break;
          }
          if ( (float)((float)((float)((float)(v16[4] * x) + (float)(v16[5] * y)) + (float)(v16[6] * z)) - dist) > 0.01 )
          {
            v11 += 2;
            break;
          }
          if ( (float)((float)((float)((float)(v16[7] * x) + (float)(v16[8] * y)) + (float)(v16[9] * z)) - dist) > 0.01 )
          {
            v11 += 3;
            break;
          }
          v11 += 4;
          v16 += 12;
          if ( v11 >= numpoints - 3 )
            goto LABEL_12;
        }
      }
      v17 = v11 == numpoints;
LABEL_21:
      if ( v17 )
        goto LABEL_58;
      v19 = v3->winding;
      v20 = v19->numpoints;
      v21 = 0;
      if ( v20 >= 4 )
      {
        v22 = v7->plane.normal.y;
        v23 = v7->plane.normal.x;
        v24 = v7->plane.normal.z;
        v25 = v7->plane.dist;
        v26 = &v19->points[0].z;
        while ( (float)((float)((float)((float)(*(v26 - 2) * v23) + (float)(*(v26 - 1) * v22)) + (float)(v24 * *v26))
                      - v25) >= -0.01 )
        {
          if ( (float)((float)((float)((float)(v26[1] * v23) + (float)(v26[2] * v22)) + (float)(v26[3] * v24)) - v25) < -0.01 )
          {
            ++v21;
            goto LABEL_37;
          }
          if ( (float)((float)((float)((float)(v26[4] * v23) + (float)(v26[5] * v22)) + (float)(v26[6] * v24)) - v25) < -0.01 )
          {
            v21 += 2;
            goto LABEL_37;
          }
          if ( (float)((float)((float)((float)(v26[7] * v23) + (float)(v26[8] * v22)) + (float)(v26[9] * v24)) - v25) < -0.01 )
          {
            v21 += 3;
            goto LABEL_37;
          }
          v21 += 4;
          v26 += 12;
          v7 = tp;
          if ( v21 >= v20 - 3 )
            goto LABEL_29;
        }
        goto LABEL_37;
      }
LABEL_29:
      v27 = v21 == v20;
      if ( v21 < v20 )
      {
        v28 = &v19->points[v21].z;
        do
        {
          if ( (float)((float)((float)((float)(*(v28 - 2) * v7->plane.normal.x)
                                     + (float)(*(v28 - 1) * v7->plane.normal.y))
                             + (float)(v7->plane.normal.z * *v28))
                     - v7->plane.dist) < -0.01 )
            break;
          ++v21;
          v28 += 3;
        }
        while ( v21 < v20 );
LABEL_37:
        v27 = v21 == v20;
      }
      if ( !v27 )
      {
        if ( !g_bUseRadius )
          goto LABEL_57;
        v29 = v7->winding;
        v30 = v29->numpoints;
        v31 = 1024000000.0;
        v32 = 0;
        if ( v30 >= 4 )
        {
          v33 = v3->origin.x;
          v34 = v3->origin.y;
          v35 = v3->origin.z;
          v36 = &v29->points[0].z;
          v37 = ((unsigned int)(v30 - 4) >> 2) + 1;
          v32 = 4 * v37;
          do
          {
            if ( v31 > (float)((float)((float)((float)(*(v36 - 2) - v33) * (float)(*(v36 - 2) - v33))
                                     + (float)((float)(*(v36 - 1) - v34) * (float)(*(v36 - 1) - v34)))
                             + (float)((float)(*v36 - v35) * (float)(*v36 - v35))) )
              v31 = (float)((float)((float)((float)(*(v36 - 2) - v33) * (float)(*(v36 - 2) - v33))
                                  + (float)((float)(*(v36 - 1) - v34) * (float)(*(v36 - 1) - v34)))
                          + (float)((float)(*v36 - v35) * (float)(*v36 - v35)));
            if ( v31 > (float)((float)((float)((float)(v36[1] - v33) * (float)(v36[1] - v33))
                                     + (float)((float)(v36[2] - v34) * (float)(v36[2] - v34)))
                             + (float)((float)(v36[3] - v35) * (float)(v36[3] - v35))) )
              v31 = (float)((float)((float)((float)(v36[1] - v33) * (float)(v36[1] - v33))
                                  + (float)((float)(v36[2] - v34) * (float)(v36[2] - v34)))
                          + (float)((float)(v36[3] - v35) * (float)(v36[3] - v35)));
            if ( v31 > (float)((float)((float)((float)(v36[4] - v33) * (float)(v36[4] - v33))
                                     + (float)((float)(v36[5] - v34) * (float)(v36[5] - v34)))
                             + (float)((float)(v36[6] - v35) * (float)(v36[6] - v35))) )
              v31 = (float)((float)((float)((float)(v36[4] - v33) * (float)(v36[4] - v33))
                                  + (float)((float)(v36[5] - v34) * (float)(v36[5] - v34)))
                          + (float)((float)(v36[6] - v35) * (float)(v36[6] - v35)));
            if ( v31 > (float)((float)((float)((float)(v36[7] - v33) * (float)(v36[7] - v33))
                                     + (float)((float)(v36[8] - v34) * (float)(v36[8] - v34)))
                             + (float)((float)(v36[9] - v35) * (float)(v36[9] - v35))) )
              v31 = (float)((float)((float)((float)(v36[7] - v33) * (float)(v36[7] - v33))
                                  + (float)((float)(v36[8] - v34) * (float)(v36[8] - v34)))
                          + (float)((float)(v36[9] - v35) * (float)(v36[9] - v35)));
            v36 += 12;
            --v37;
          }
          while ( v37 != 0 );
        }
        if ( v32 < v30 )
        {
          v38 = &v7->winding->points[v32].z;
          v39 = v30 - v32;
          do
          {
            if ( v31 > (float)((float)((float)((float)(*(v38 - 2) - v3->origin.x) * (float)(*(v38 - 2) - v3->origin.x))
                                     + (float)((float)(*(v38 - 1) - v3->origin.y) * (float)(*(v38 - 1) - v3->origin.y)))
                             + (float)((float)(*v38 - v3->origin.z) * (float)(*v38 - v3->origin.z))) )
              v31 = (float)((float)((float)((float)(*(v38 - 2) - v3->origin.x) * (float)(*(v38 - 2) - v3->origin.x))
                                  + (float)((float)(*(v38 - 1) - v3->origin.y) * (float)(*(v38 - 1) - v3->origin.y)))
                          + (float)((float)(*v38 - v3->origin.z) * (float)(*v38 - v3->origin.z)));
            v38 += 3;
            --v39;
          }
          while ( v39 != 0 );
        }
        if ( v31 <= g_VisRadius )
LABEL_57:
          v3->portalfront[j >> 3] |= v44;
      }
LABEL_58:
      v8 = j + 1;
      v44 = __ROL1__(v44, 1);
      ++v7;
      j = v8;
      tp = v7;
      if ( v8 >= 2 * g_numportals )
        break;
      v2 = portalnum;
    }
  }
  SimpleFlood(srcportal: v3, leafnum: v3->leaf);
  v40 = 0;
  portalnuma = 0;
  v41 = 1;
  if ( 2 * g_numportals <= 0 )
  {
    v3->nummightsee = 0;
  }
  else
  {
    do
    {
      if ( ((unsigned __int8)v41 & v3->portalflood[v40 >> 3]) != 0 )
        ++portalnuma;
      ++v40;
      v41 = __ROL1__(v41, 1);
    }
    while ( v40 < 2 * g_numportals );
    v3->nummightsee = portalnuma;
    c_flood += portalnuma;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C4B0
// Name: void DumpPortalTrace(struct pstack_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DumpPortalTrace(pstack_t *pStack)
{
  DWORD CurrentThreadId; // ecx
  pstack_t *v2; // edx
  int m_Size; // eax
  winding_t *pass; // ebx
  int numpoints; // edi
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  int v9; // esi
  unsigned int v10; // edx
  float *p_z; // ecx
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm0_4
  float v21; // xmm3_4
  float *v22; // ecx
  int v23; // edx
  int v24; // esi
  float v25; // xmm0_4
  int v26; // eax
  Vector *v27; // ecx
  int v28; // ebx
  Vector *points; // edi
  int v30; // esi
  int v31; // eax
  Vector *v32; // ecx
  int v33; // esi
  Vector *v34; // ecx
  int v35; // ebx
  Vector *v36; // edi
  int v37; // esi
  Vector *m_pMemory; // edx
  Vector *v39; // ecx
  int v40; // esi
  int v41; // eax
  Vector *v42; // ecx
  int v43; // esi
  Vector *v44; // ecx
  Vector *v45; // eax
  float v46; // xmm0_4
  int v47; // eax
  int v48; // esi
  Vector *v49; // ecx
  int v50; // eax
  Vector *v51; // eax
  Vector v52; // [esp+4h] [ebp-28h] BYREF
  Vector result; // [esp+10h] [ebp-1Ch] BYREF
  Vector mid; // [esp+1Ch] [ebp-10h] BYREF
  winding_t *w; // [esp+28h] [ebp-4h]

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != g_PortalTrace.m_mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&g_PortalTrace.m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &g_PortalTrace.m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++g_PortalTrace.m_mutex.m_depth;
  }
  if ( g_PortalTrace.m_list.m_Size != 0 )
  {
    if ( --g_PortalTrace.m_mutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&g_PortalTrace.m_mutex, 0);
  }
  else
  {
    _Warning(a1: "Dumped cluster trace!!!\n");
    mid = *ClusterCenter(&result, cluster: g_TraceClusterStart);
    CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int>>::InsertBefore(
      this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&g_PortalTrace,
      elem: g_PortalTrace.m_list.m_Size,
      src: (const CFileResponse *)&mid);
    v2 = pStack;
    if ( pStack != nullptr )
    {
      m_Size = g_PortalTrace.m_list.m_Size;
      while ( 1 )
      {
        if ( v2->pass != nullptr )
        {
          pass = v2->pass;
          w = pass;
        }
        else
        {
          w = v2->portal->winding;
          pass = w;
        }
        numpoints = pass->numpoints;
        x = vec3_origin.x;
        y = vec3_origin.y;
        z = vec3_origin.z;
        v9 = 0;
        if ( numpoints >= 4 )
        {
          v10 = ((unsigned int)(numpoints - 4) >> 2) + 1;
          p_z = &pass->points[0].z;
          v9 = 4 * v10;
          do
          {
            v12 = *(p_z - 2) + x;
            v13 = *(p_z - 1) + y;
            v14 = *p_z + z;
            v15 = p_z[1] + v12;
            v16 = p_z[2] + v13;
            v17 = p_z[3] + v14;
            v18 = p_z[4] + v15;
            v19 = p_z[5] + v16;
            v20 = p_z[6] + v17;
            x = p_z[7] + v18;
            y = p_z[8] + v19;
            v21 = p_z[9];
            p_z += 12;
            --v10;
            z = v21 + v20;
          }
          while ( v10 != 0 );
        }
        if ( v9 < numpoints )
        {
          v22 = &pass->points[v9].z;
          v23 = numpoints - v9;
          do
          {
            x = x + *(v22 - 2);
            y = y + *(v22 - 1);
            z = z + *v22;
            v22 += 3;
            --v23;
          }
          while ( v23 != 0 );
        }
        v24 = m_Size;
        v25 = 1.0 / (double)numpoints;
        mid.x = v25 * x;
        mid.y = y * v25;
        mid.z = z * v25;
        if ( m_Size + 1 > g_PortalTrace.m_list.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>::Grow(
            this: (CUtlMemory<UtlLinkedListElem_t<CWorkerFile *,int>,int> *)&g_PortalTrace,
            num: m_Size - g_PortalTrace.m_list.m_Memory.m_nAllocationCount + 1);
          m_Size = g_PortalTrace.m_list.m_Size;
        }
        v26 = m_Size + 1;
        g_PortalTrace.m_list.m_Size = v26;
        g_PortalTrace.m_list.m_pElements = g_PortalTrace.m_list.m_Memory.m_pMemory;
        if ( v26 - v24 - 1 > 0 )
        {
          _V_memmove(
            dest: &g_PortalTrace.m_list.m_Memory.m_pMemory[v24 + 1],
            src: &g_PortalTrace.m_list.m_Memory.m_pMemory[v24],
            count: 12 * (v26 - v24 - 1));
          v26 = g_PortalTrace.m_list.m_Size;
        }
        v27 = &g_PortalTrace.m_list.m_Memory.m_pMemory[v24];
        if ( v27 != nullptr )
        {
          *v27 = mid;
          v26 = g_PortalTrace.m_list.m_Size;
        }
        v28 = 0;
        if ( w->numpoints > 0 )
        {
          points = w->points;
          do
          {
            v30 = v26;
            if ( v26 + 1 > g_PortalTrace.m_list.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>::Grow(
                this: (CUtlMemory<UtlLinkedListElem_t<CWorkerFile *,int>,int> *)&g_PortalTrace,
                num: v26 - g_PortalTrace.m_list.m_Memory.m_nAllocationCount + 1);
              v26 = g_PortalTrace.m_list.m_Size;
            }
            v31 = v26 + 1;
            g_PortalTrace.m_list.m_Size = v31;
            g_PortalTrace.m_list.m_pElements = g_PortalTrace.m_list.m_Memory.m_pMemory;
            if ( v31 - v30 - 1 > 0 )
            {
              _V_memmove(
                dest: &g_PortalTrace.m_list.m_Memory.m_pMemory[v30 + 1],
                src: &g_PortalTrace.m_list.m_Memory.m_pMemory[v30],
                count: 12 * (v31 - v30 - 1));
              v31 = g_PortalTrace.m_list.m_Size;
            }
            v32 = &g_PortalTrace.m_list.m_Memory.m_pMemory[v30];
            if ( v32 != nullptr )
            {
              *(_QWORD *)&v32->x = *(_QWORD *)&points->x;
              v32->z = points->z;
              v31 = g_PortalTrace.m_list.m_Size;
            }
            v33 = v31;
            if ( v31 + 1 > g_PortalTrace.m_list.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>::Grow(
                this: (CUtlMemory<UtlLinkedListElem_t<CWorkerFile *,int>,int> *)&g_PortalTrace,
                num: v31 - g_PortalTrace.m_list.m_Memory.m_nAllocationCount + 1);
              v31 = g_PortalTrace.m_list.m_Size;
            }
            v26 = v31 + 1;
            g_PortalTrace.m_list.m_Size = v26;
            g_PortalTrace.m_list.m_pElements = g_PortalTrace.m_list.m_Memory.m_pMemory;
            if ( v26 - v33 - 1 > 0 )
            {
              _V_memmove(
                dest: &g_PortalTrace.m_list.m_Memory.m_pMemory[v33 + 1],
                src: &g_PortalTrace.m_list.m_Memory.m_pMemory[v33],
                count: 12 * (v26 - v33 - 1));
              v26 = g_PortalTrace.m_list.m_Size;
            }
            v34 = &g_PortalTrace.m_list.m_Memory.m_pMemory[v33];
            if ( v34 != nullptr )
            {
              *v34 = mid;
              v26 = g_PortalTrace.m_list.m_Size;
            }
            ++v28;
            ++points;
          }
          while ( v28 < w->numpoints );
        }
        v35 = 0;
        if ( w->numpoints > 0 )
        {
          v36 = w->points;
          do
          {
            v37 = v26;
            if ( v26 + 1 > g_PortalTrace.m_list.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>::Grow(
                this: (CUtlMemory<UtlLinkedListElem_t<CWorkerFile *,int>,int> *)&g_PortalTrace,
                num: v26 - g_PortalTrace.m_list.m_Memory.m_nAllocationCount + 1);
              v26 = g_PortalTrace.m_list.m_Size;
            }
            m_pMemory = g_PortalTrace.m_list.m_Memory.m_pMemory;
            g_PortalTrace.m_list.m_Size = ++v26;
            g_PortalTrace.m_list.m_pElements = g_PortalTrace.m_list.m_Memory.m_pMemory;
            if ( v26 - v37 - 1 > 0 )
            {
              _V_memmove(
                dest: &g_PortalTrace.m_list.m_Memory.m_pMemory[v37 + 1],
                src: &g_PortalTrace.m_list.m_Memory.m_pMemory[v37],
                count: 12 * (v26 - v37 - 1));
              v26 = g_PortalTrace.m_list.m_Size;
              m_pMemory = g_PortalTrace.m_list.m_Memory.m_pMemory;
            }
            v39 = &m_pMemory[v37];
            if ( v39 != nullptr )
            {
              *(_QWORD *)&v39->x = *(_QWORD *)&v36->x;
              v39->z = v36->z;
              v26 = g_PortalTrace.m_list.m_Size;
            }
            ++v35;
            ++v36;
          }
          while ( v35 < w->numpoints );
        }
        v40 = v26;
        if ( v26 + 1 > g_PortalTrace.m_list.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>::Grow(
            this: (CUtlMemory<UtlLinkedListElem_t<CWorkerFile *,int>,int> *)&g_PortalTrace,
            num: v26 - g_PortalTrace.m_list.m_Memory.m_nAllocationCount + 1);
          v26 = g_PortalTrace.m_list.m_Size;
        }
        v41 = v26 + 1;
        g_PortalTrace.m_list.m_Size = v41;
        g_PortalTrace.m_list.m_pElements = g_PortalTrace.m_list.m_Memory.m_pMemory;
        if ( v41 - v40 - 1 > 0 )
        {
          _V_memmove(
            dest: &g_PortalTrace.m_list.m_Memory.m_pMemory[v40 + 1],
            src: &g_PortalTrace.m_list.m_Memory.m_pMemory[v40],
            count: 12 * (v41 - v40 - 1));
          v41 = g_PortalTrace.m_list.m_Size;
        }
        v42 = &g_PortalTrace.m_list.m_Memory.m_pMemory[v40];
        if ( v42 != nullptr )
        {
          *v42 = w->points[0];
          v41 = g_PortalTrace.m_list.m_Size;
        }
        v43 = v41;
        if ( v41 + 1 > g_PortalTrace.m_list.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>::Grow(
            this: (CUtlMemory<UtlLinkedListElem_t<CWorkerFile *,int>,int> *)&g_PortalTrace,
            num: v41 - g_PortalTrace.m_list.m_Memory.m_nAllocationCount + 1);
          v41 = g_PortalTrace.m_list.m_Size;
        }
        m_Size = v41 + 1;
        g_PortalTrace.m_list.m_Size = m_Size;
        g_PortalTrace.m_list.m_pElements = g_PortalTrace.m_list.m_Memory.m_pMemory;
        if ( m_Size - v43 - 1 > 0 )
        {
          _V_memmove(
            dest: &g_PortalTrace.m_list.m_Memory.m_pMemory[v43 + 1],
            src: &g_PortalTrace.m_list.m_Memory.m_pMemory[v43],
            count: 12 * (m_Size - v43 - 1));
          m_Size = g_PortalTrace.m_list.m_Size;
        }
        v44 = &g_PortalTrace.m_list.m_Memory.m_pMemory[v43];
        if ( v44 != nullptr )
        {
          *v44 = mid;
          m_Size = g_PortalTrace.m_list.m_Size;
        }
        pStack = pStack->next;
        if ( pStack == nullptr )
          break;
        v2 = pStack;
      }
    }
    v45 = ClusterCenter(result: &v52, cluster: g_TraceClusterStop);
    mid.x = v45->x;
    mid.y = v45->y;
    v46 = v45->z;
    v47 = g_PortalTrace.m_list.m_Size;
    mid.z = v46;
    v48 = g_PortalTrace.m_list.m_Size;
    if ( g_PortalTrace.m_list.m_Size + 1 > g_PortalTrace.m_list.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>::Grow(
        this: (CUtlMemory<UtlLinkedListElem_t<CWorkerFile *,int>,int> *)&g_PortalTrace,
        num: g_PortalTrace.m_list.m_Size - g_PortalTrace.m_list.m_Memory.m_nAllocationCount + 1);
      v47 = g_PortalTrace.m_list.m_Size;
    }
    v49 = g_PortalTrace.m_list.m_Memory.m_pMemory;
    g_PortalTrace.m_list.m_Size = v47 + 1;
    v50 = v47 - v48;
    g_PortalTrace.m_list.m_pElements = g_PortalTrace.m_list.m_Memory.m_pMemory;
    if ( v50 > 0 )
    {
      _V_memmove(
        dest: &g_PortalTrace.m_list.m_Memory.m_pMemory[v48 + 1],
        src: &g_PortalTrace.m_list.m_Memory.m_pMemory[v48],
        count: 12 * v50);
      v49 = g_PortalTrace.m_list.m_Memory.m_pMemory;
    }
    v51 = &v49[v48];
    if ( v51 != nullptr )
      *v51 = mid;
    if ( --g_PortalTrace.m_mutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&g_PortalTrace.m_mutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CAF0
// Name: void RecursiveLeafFlow(int,struct threaddata_t __near *,struct pstack_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecursiveLeafFlow(int leafnum, threaddata_t *thread, pstack_t *prevstack)
{
  pstack_t *v3; // ebx
  threaddata_t *v4; // edi
  leaf_t *v5; // eax
  portal_t *base; // edx
  unsigned __int8 *portalvis; // edx
  portal_t *v8; // esi
  int v9; // edx
  int v10; // eax
  unsigned __int8 *portalflood; // ecx
  int v12; // edx
  int v13; // edi
  pstack_t *v14; // eax
  int v15; // ecx
  int v16; // ebx
  float v17; // xmm0_4
  float y; // xmm0_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  float radius; // xmm1_4
  winding_t *source; // eax
  winding_t *pass; // ecx
  unsigned __int8 *v24; // eax
  winding_t *v25; // eax
  pstack_t stack; // [esp+0h] [ebp-222Ch] BYREF
  plane_t split; // [esp+21F8h] [ebp-34h] BYREF
  unsigned __int8 *v28; // [esp+2208h] [ebp-24h]
  int v29; // [esp+220Ch] [ebp-20h]
  int v30; // [esp+2210h] [ebp-1Ch]
  int v31; // [esp+2214h] [ebp-18h]
  int v32; // [esp+2218h] [ebp-14h]
  leaf_t *v33; // [esp+221Ch] [ebp-10h]
  int v34; // [esp+2220h] [ebp-Ch]
  int v35; // [esp+2224h] [ebp-8h]
  int v36; // [esp+2228h] [ebp-4h]

  if ( !g_bVMPIEarlyExit )
  {
    if ( leafnum == g_TraceClusterStop )
    {
      DumpPortalTrace(pStack: &thread->pstack_head);
      return;
    }
    v3 = prevstack;
    v4 = thread;
    ++thread->c_chains;
    v5 = &leafs[leafnum];
    prevstack->next = &stack;
    base = thread->base;
    stack.next = nullptr;
    stack.leaf = v5;
    stack.portal = nullptr;
    portalvis = base->portalvis;
    v33 = v5;
    v28 = portalvis;
    v34 = 0;
    if ( v5->portals.m_Size > 0 )
    {
      while ( 1 )
      {
        v8 = v5->portals.m_Memory.m_pMemory[v34];
        v9 = 1 << ((v8 - portals) & 7);
        v10 = (v8 - portals) >> 3;
        v32 = (v8 - portals) & 7;
        v36 = v10;
        v29 = v9;
        if ( ((unsigned __int8)v9 & v3->mightsee[v10]) == 0 )
          goto LABEL_31;
        if ( v8->status == stat_done )
          portalflood = v8->portalvis;
        else
          portalflood = v8->portalflood;
        v35 = 0;
        if ( portallongs > 0 )
        {
          v12 = portalflood - (unsigned __int8 *)v3;
          v13 = (char *)&stack - (char *)v3;
          v30 = v28 - (unsigned __int8 *)v3;
          v14 = v3;
          v31 = portallongs;
          do
          {
            v15 = *(_DWORD *)v14->mightsee & *(_DWORD *)&v14->mightsee[v12];
            v16 = v30;
            *(_DWORD *)&v14->mightsee[v13] = v15;
            v35 |= v15 & ~*(_DWORD *)&v14->mightsee[v16];
            v14 = (pstack_t *)((char *)v14 + 4);
            --v31;
          }
          while ( v31 != 0 );
          v4 = thread;
          v3 = prevstack;
          if ( v35 != 0 )
            goto LABEL_17;
          LOBYTE(v9) = v29;
          v10 = v36;
        }
        if ( ((unsigned __int8)v9 & v4->base->portalvis[v10]) != 0 )
          goto LABEL_31;
LABEL_17:
        stack.portalplane = v8->plane;
        split.normal.x = vec3_origin.x - v8->plane.normal.x;
        split.normal.y = vec3_origin.y - v8->plane.normal.y;
        split.normal.z = vec3_origin.z - v8->plane.normal.z;
        v17 = -v8->plane.dist;
        stack.freewindings[0] = 1;
        stack.freewindings[1] = 1;
        stack.freewindings[2] = 1;
        split.dist = v17;
        y = v4->pstack_head.portalplane.normal.y;
        stack.portal = v8;
        stack.next = nullptr;
        v19 = (float)((float)((float)(y * v8->origin.y) + (float)(v8->origin.x * v4->pstack_head.portalplane.normal.x))
                    + (float)(v4->pstack_head.portalplane.normal.z * v8->origin.z))
            - v4->pstack_head.portalplane.dist;
        if ( (float)-v8->radius > v19 )
          goto LABEL_31;
        if ( v19 <= v8->radius )
        {
          stack.pass = ChopWinding(in: v8->winding, &stack, split: &v4->pstack_head.portalplane);
          if ( stack.pass == nullptr )
            goto LABEL_31;
        }
        else
        {
          stack.pass = v8->winding;
        }
        v20 = (float)((float)((float)(v4->base->origin.y * v8->plane.normal.y)
                            + (float)(v4->base->origin.x * v8->plane.normal.x))
                    + (float)(v4->base->origin.z * v8->plane.normal.z))
            - v8->plane.dist;
        radius = v4->base->radius;
        if ( v20 <= radius )
        {
          if ( (float)-radius <= v20 )
          {
            source = ChopWinding(in: v3->source, &stack, &split);
            stack.source = source;
            if ( source == nullptr )
              goto LABEL_31;
          }
          else
          {
            source = v3->source;
            stack.source = source;
          }
          pass = v3->pass;
          if ( pass == nullptr )
          {
            v24 = &v4->base->portalvis[v36];
LABEL_30:
            *v24 |= 1 << v32;
            RecursiveLeafFlow(leafnum: v8->leaf, thread: v4, prevstack: &stack);
            goto LABEL_31;
          }
          v25 = ClipToSeperators(source, pass, target: stack.pass, flipclip: false, &stack);
          stack.pass = v25;
          if ( v25 != nullptr )
          {
            stack.pass = ClipToSeperators(source: v3->pass, pass: stack.source, target: v25, flipclip: true, &stack);
            if ( stack.pass != nullptr )
            {
              v24 = &v4->base->portalvis[v36];
              goto LABEL_30;
            }
          }
        }
LABEL_31:
        if ( ++v34 >= v33->portals.m_Size )
          return;
        v5 = v33;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CE80
// Name: void PortalFlow(int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PortalFlow(int iThread, int portalnum)
{
  portal_t *v2; // esi
  int v3; // eax
  char v4; // cl
  unsigned __int8 *portalflood; // edi
  int v6; // ecx
  int i; // eax
  int v8; // eax
  char j; // cl
  threaddata_t dst; // [esp+Ch] [ebp-2204h] BYREF
  int v11; // [esp+220Ch] [ebp-4h]
  int v12; // [esp+221Ch] [ebp+Ch]

  v2 = sorted_portals[portalnum];
  v2->status = stat_working;
  v3 = 0;
  v11 = 0;
  v4 = 1;
  if ( 2 * g_numportals > 0 )
  {
    portalflood = v2->portalflood;
    do
    {
      if ( ((unsigned __int8)v4 & portalflood[v3 >> 3]) != 0 )
        ++v11;
      ++v3;
      v4 = __ROL1__(v4, 1);
    }
    while ( v3 < 2 * g_numportals );
  }
  memset((unsigned __int8 *)&dst, value: 0, count: sizeof(dst));
  v6 = portallongs;
  dst.base = v2;
  dst.pstack_head.portal = v2;
  dst.pstack_head.source = v2->winding;
  dst.pstack_head.portalplane = v2->plane;
  for ( i = 0; i < v6; ++i )
    *(_DWORD *)&dst.pstack_head.mightsee[4 * i] = *(_DWORD *)&v2->portalflood[4 * i];
  RecursiveLeafFlow(leafnum: v2->leaf, thread: &dst, prevstack: &dst.pstack_head);
  v2->status = stat_done;
  v8 = 0;
  v12 = 0;
  for ( j = 1; v8 < 2 * g_numportals; j = __ROL1__(j, 1) )
  {
    if ( ((unsigned __int8)j & v2->portalvis[v8 >> 3]) != 0 )
      ++v12;
    ++v8;
  }
  qprintf(format: "portal:%4i  mightsee:%4i  cansee:%4i (%i chains)\n", v2 - portals, v11, v12, dst.c_chains);
}
