// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/common/polylib.cpp
// Functions: 15
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0044A9D0
// Name: struct winding_t __near * AllocWinding(int)
// Source: json
//------------------------------------------------------------------------------
winding_t *__cdecl AllocWinding(unsigned int points)
{
  int v1; // eax
  winding_t *v2; // esi

  if ( numthreads == 1 )
  {
    ++c_winding_allocs;
    c_winding_points += points;
    v1 = c_active_windings + 1;
    c_active_windings = v1;
    if ( v1 > c_peak_windings )
      c_peak_windings = v1;
  }
  ThreadLock();
  v2 = winding_pool[points];
  if ( v2 != nullptr )
  {
    winding_pool[points] = v2->next;
  }
  else
  {
    v2 = (winding_t *)MemAlloc_Alloc(nSize: 0x10u);
    v2->p = (Vector *)calloc(count: points, size: 0xCu);
  }
  ThreadUnlock();
  v2->maxpoints = points;
  v2->numpoints = 0;
  v2->next = nullptr;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0044AA60
// Name: void FreeWinding(struct winding_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FreeWinding(winding_t *w)
{
  int maxpoints; // eax

  if ( w->numpoints == -559030611 )
    _Error(a1: "FreeWinding: freed a freed winding");
  ThreadLock();
  maxpoints = w->maxpoints;
  w->numpoints = -559030611;
  w->next = winding_pool[maxpoints];
  winding_pool[maxpoints] = w;
  ThreadUnlock();
}

//------------------------------------------------------------------------------
// Address: 0x0044AAB0
// Name: void WindingPlane(struct winding_t __near *,class Vector __near &,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WindingPlane(winding_t *w, Vector *normal, float *dist)
{
  Vector *p; // eax
  float v4; // xmm4_4
  float v5; // xmm5_4
  float v6; // xmm3_4
  float x; // xmm0_4
  float y; // xmm2_4
  float z; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm0_4

  p = w->p;
  v4 = p[1].x - p->x;
  v5 = p[1].y - p->y;
  v6 = p[1].z - p->z;
  if ( w->numpoints <= 3 )
  {
    x = p[2].x;
    y = p[2].y;
    z = p[2].z;
  }
  else
  {
    x = p[3].x;
    y = p[3].y;
    z = p[3].z;
  }
  v10 = y - p->y;
  v11 = z - p->z;
  v12 = x - p->x;
  normal->x = (float)(v10 * v6) - (float)(v11 * v5);
  normal->y = (float)(v11 * v4) - (float)(v6 * v12);
  normal->z = (float)(v12 * v5) - (float)(v10 * v4);
  VectorNormalize(vec: normal);
  *dist = (float)((float)(w->p->y * normal->y) + (float)(w->p->x * normal->x)) + (float)(w->p->z * normal->z);
}

//------------------------------------------------------------------------------
// Address: 0x0044AB90
// Name: float WindingArea(struct winding_t __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl WindingArea(winding_t *w)
{
  Vector *p; // ecx
  float *p_z; // eax
  int v3; // edx
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm5_4
  float v9; // xmm6_4
  float v11; // [esp-4h] [ebp-10h]

  v11 = 0.0;
  if ( w->numpoints > 2 )
  {
    p = w->p;
    p_z = &p[1].z;
    v3 = w->numpoints - 2;
    do
    {
      v4 = p_z[2] - p->y;
      v5 = *p_z - p->z;
      v6 = p_z[1] - p->x;
      v7 = p_z[3] - p->z;
      v8 = *(p_z - 2) - p->x;
      v9 = *(p_z - 1) - p->y;
      p_z += 3;
      --v3;
      v11 = fsqrt(
              (float)((float)((float)((float)(v5 * v6) - (float)(v7 * v8)) * (float)((float)(v5 * v6) - (float)(v7 * v8)))
                    + (float)((float)((float)(v4 * v8) - (float)(v6 * v9)) * (float)((float)(v4 * v8) - (float)(v6 * v9))))
            + (float)((float)((float)(v7 * v9) - (float)(v4 * v5)) * (float)((float)(v7 * v9) - (float)(v4 * v5))))
          + v11;
    }
    while ( v3 != 0 );
  }
  return v11 * 0.5;
}

//------------------------------------------------------------------------------
// Address: 0x0044AC80
// Name: void WindingCenter(struct winding_t __near *,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WindingCenter(winding_t *w, Vector *center)
{
  int v2; // edi
  float y; // xmm0_4
  float z; // xmm1_4
  int v5; // esi
  Vector *p; // ecx
  float v7; // xmm0_4

  *center = vec3_origin;
  v2 = 0;
  if ( w->numpoints > 0 )
  {
    y = center->y;
    z = center->z;
    v5 = 0;
    do
    {
      p = w->p;
      center->x = p[v5].x + center->x;
      y = y + p[v5].y;
      center->y = y;
      z = z + p[v5].z;
      ++v2;
      center->z = z;
      ++v5;
    }
    while ( v2 < w->numpoints );
  }
  v7 = 1.0 / (double)w->numpoints;
  center->x = center->x * v7;
  center->y = center->y * v7;
  center->z = center->z * v7;
}

//------------------------------------------------------------------------------
// Address: 0x0044AD40
// Name: struct winding_t __near * BaseWindingForPlane(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
winding_t *__cdecl BaseWindingForPlane(const Vector *normal, float dist)
{
  float v2; // xmm1_4
  int v3; // edi
  float v4; // xmm0_4
  float v5; // xmm0_4
  float x; // xmm5_4
  float z; // xmm4_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm3_4
  float v11; // xmm4_4
  float y; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  winding_t *result; // eax
  Vector *p; // ecx
  Vector *v18; // ecx
  Vector *v19; // ecx
  Vector *v20; // ecx
  Vector *v21; // ecx
  Vector *v22; // ecx
  Vector *v23; // ecx
  Vector *v24; // ecx
  float org; // [esp+0h] [ebp-24h]
  float org_4; // [esp+4h] [ebp-20h]
  Vector vup; // [esp+18h] [ebp-Ch] BYREF

  v2 = -1.0;
  v3 = -1;
  v4 = fabs(normal->x);
  if ( v4 > -1.0 )
  {
    v3 = 0;
    v2 = v4;
  }
  v5 = fabs(normal->y);
  if ( v5 > v2 )
  {
    v3 = 1;
    v2 = v5;
  }
  if ( fabs(normal->z) <= v2 )
  {
    if ( v3 == -1 )
      _Error(a1: "BaseWindingForPlane: no axis found");
  }
  else
  {
    v3 = 2;
  }
  x = vec3_origin.x;
  z = vec3_origin.z;
  if ( v3 >= 0 )
  {
    if ( v3 <= 1 )
      z = 1.0;
    else
      x = 1.0;
  }
  LODWORD(v8) = COERCE_UNSIGNED_INT((float)((float)(normal->y * vec3_origin.y) + (float)(normal->x * x)) + (float)(normal->z * z))
              ^ _mask__NegFloat_;
  v9 = (float)(normal->y * v8) + vec3_origin.y;
  v10 = (float)(normal->z * v8) + z;
  vup.x = (float)(normal->x * v8) + x;
  vup.y = v9;
  vup.z = v10;
  VectorNormalize(vec: &vup);
  v11 = normal->z;
  org = normal->x * dist;
  y = normal->y;
  org_4 = y * dist;
  v13 = (float)(v11 * vup.y) - (float)(y * vup.z);
  v14 = (float)(y * vup.x) - (float)(normal->x * vup.y);
  v15 = (float)((float)(normal->x * vup.z) - (float)(v11 * vup.x)) * 65536.0;
  vup.x = vup.x * 65536.0;
  vup.y = vup.y * 65536.0;
  vup.z = vup.z * 65536.0;
  result = AllocWinding(points: 4u);
  p = result->p;
  p->x = org - (float)(v13 * 65536.0);
  p->y = org_4 - v15;
  p->z = (float)(v11 * dist) - (float)(v14 * 65536.0);
  v18 = result->p;
  v18->x = v18->x + vup.x;
  v18->y = v18->y + vup.y;
  v18->z = v18->z + vup.z;
  v19 = result->p;
  v19[1].x = org + (float)(v13 * 65536.0);
  v19[1].y = v15 + org_4;
  v19[1].z = (float)(v14 * 65536.0) + (float)(v11 * dist);
  v20 = result->p;
  v20[1].x = v20[1].x + vup.x;
  v20[1].y = v20[1].y + vup.y;
  v20[1].z = v20[1].z + vup.z;
  v21 = result->p;
  v21[2].x = org + (float)(v13 * 65536.0);
  v21[2].y = v15 + org_4;
  v21[2].z = (float)(v14 * 65536.0) + (float)(v11 * dist);
  v22 = result->p;
  v22[2].x = v22[2].x - vup.x;
  v22[2].y = v22[2].y - vup.y;
  v22[2].z = v22[2].z - vup.z;
  v23 = result->p;
  v23[3].x = org - (float)(v13 * 65536.0);
  v23[3].y = org_4 - v15;
  v23[3].z = (float)(v11 * dist) - (float)(v14 * 65536.0);
  v24 = result->p;
  v24[3].x = v24[3].x - vup.x;
  v24[3].y = v24[3].y - vup.y;
  v24[3].z = v24[3].z - vup.z;
  result->numpoints = 4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044B050
// Name: struct winding_t __near * CopyWinding(struct winding_t __near *)
// Source: json
//------------------------------------------------------------------------------
winding_t *__cdecl CopyWinding(winding_t *w)
{
  winding_t *v1; // edi

  v1 = AllocWinding(points: w->numpoints);
  v1->numpoints = w->numpoints;
  memcpy(dst: (unsigned __int8 *)v1->p, src: (unsigned __int8 *)w->p, count: 12 * w->numpoints);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0044B090
// Name: struct winding_t __near * ReverseWinding(struct winding_t __near *)
// Source: json
//------------------------------------------------------------------------------
winding_t *__cdecl ReverseWinding(winding_t *w)
{
  winding_t *result; // eax
  int numpoints; // edx
  int v4; // esi
  int v5; // ebx
  Vector *p; // ecx
  Vector *v7; // eax
  int v8; // edx
  double v9; // st7
  float *v10; // edx
  winding_t *c; // [esp+10h] [ebp+8h]

  result = AllocWinding(points: w->numpoints);
  numpoints = w->numpoints;
  v4 = 0;
  c = result;
  if ( numpoints > 0 )
  {
    v5 = 0;
    do
    {
      p = result->p;
      v7 = w->p;
      v8 = 3 * (numpoints - v4) - 3;
      v9 = *(&v7->x + v8);
      v10 = &v7->x + v8;
      result = c;
      p[v5].x = v9;
      ++v4;
      p[v5++].y = v10[1];
      p[v5 - 1].z = v10[2];
      numpoints = w->numpoints;
    }
    while ( v4 < w->numpoints );
  }
  result->numpoints = w->numpoints;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044B0F0
// Name: void ClipWindingEpsilon(struct winding_t __near *,class Vector const __near &,float,float,struct winding_t __near * __near *,struct winding_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClipWindingEpsilon(
        winding_t *in,
        Vector *normal,
        float dist,
        float epsilon,
        winding_t **front,
        winding_t **back)
{
  float *v6; // esi
  float *v7; // edi
  float *v8; // eax
  float v9; // [esp+8h] [ebp-280h]
  Vector *v10; // [esp+18h] [ebp-270h]
  Vector *v11; // [esp+1Ch] [ebp-26Ch]
  Vector *v12; // [esp+20h] [ebp-268h]
  Vector *v13; // [esp+24h] [ebp-264h]
  Vector *p1; // [esp+2Ch] [ebp-25Ch]
  Vector *p2; // [esp+30h] [ebp-258h]
  int j; // [esp+34h] [ebp-254h]
  float dists[68]; // [esp+38h] [ebp-250h]
  winding_t *b; // [esp+148h] [ebp-140h]
  int counts[3]; // [esp+14Ch] [ebp-13Ch] BYREF
  int sides[69]; // [esp+158h] [ebp-130h]
  winding_t *f; // [esp+26Ch] [ebp-1Ch]
  int i; // [esp+270h] [ebp-18h]
  int maxpts; // [esp+274h] [ebp-14h]
  float dot; // [esp+278h] [ebp-10h]
  Vector mid; // [esp+27Ch] [ebp-Ch] BYREF

  mid = vec3_origin;
  memset(counts, 0, sizeof(counts));
  for ( i = 0; i < in->numpoints; ++i )
  {
    dot = (float)((float)((float)(in->p[i].x * normal->x) + (float)(in->p[i].y * normal->y))
                + (float)(in->p[i].z * normal->z))
        - dist;
    dists[i] = dot;
    if ( dot <= epsilon )
    {
      if ( COERCE_FLOAT(LODWORD(epsilon) ^ _mask__NegFloat_) <= dot )
        sides[i] = 2;
      else
        sides[i] = 1;
    }
    else
    {
      sides[i] = 0;
    }
    ++counts[sides[i]];
  }
  sides[i] = sides[0];
  dists[i] = dists[0];
  *back = nullptr;
  *front = nullptr;
  if ( counts[0] != 0 )
  {
    if ( counts[1] != 0 )
    {
      maxpts = in->numpoints + 4;
      f = AllocWinding(points: maxpts);
      *front = f;
      b = AllocWinding(points: maxpts);
      *back = b;
      for ( i = 0; i < in->numpoints; ++i )
      {
        p1 = &in->p[i];
        if ( sides[i] == 2 )
        {
          v13 = &f->p[f->numpoints];
          v13->x = p1->x;
          v13->y = p1->y;
          v13->z = p1->z;
          ++f->numpoints;
          v12 = &b->p[b->numpoints];
          v12->x = p1->x;
          v12->y = p1->y;
          v12->z = p1->z;
          ++b->numpoints;
        }
        else
        {
          if ( sides[i] == 0 )
          {
            v11 = &f->p[f->numpoints];
            v11->x = p1->x;
            v11->y = p1->y;
            v11->z = p1->z;
            ++f->numpoints;
          }
          if ( sides[i] == 1 )
          {
            v10 = &b->p[b->numpoints];
            v10->x = p1->x;
            v10->y = p1->y;
            v10->z = p1->z;
            ++b->numpoints;
          }
          if ( sides[i + 1] != 2 && sides[i + 1] != sides[i] )
          {
            p2 = &in->p[(i + 1) % in->numpoints];
            dot = dists[i] / (float)(dists[i] - dists[i + 1]);
            for ( j = 0; j < 3; ++j )
            {
              if ( Vector::operator[](this: normal, i: j) == 1.0 )
              {
                *Vector::operator[](this: &mid, i: j) = dist;
              }
              else if ( Vector::operator[](this: normal, i: j) == -1.0 )
              {
                *(_DWORD *)Vector::operator[](this: &mid, i: j) = LODWORD(dist) ^ _mask__NegFloat_;
              }
              else
              {
                v6 = Vector::operator[](this: p1, i: j);
                v7 = Vector::operator[](this: p2, i: j);
                v8 = Vector::operator[](this: p1, i: j);
                v9 = (float)((float)(*v7 - *v8) * dot) + *v6;
                *Vector::operator[](this: &mid, i: j) = v9;
              }
            }
            f->p[f->numpoints++] = mid;
            b->p[b->numpoints++] = mid;
          }
        }
      }
      if ( f->numpoints > maxpts || b->numpoints > maxpts )
        _Error(a1: "ClipWinding: points exceeded estimate");
      if ( f->numpoints > 64 || b->numpoints > 64 )
        _Error(a1: "ClipWinding: MAX_POINTS_ON_WINDING");
    }
    else
    {
      *front = CopyWinding(w: in);
    }
  }
  else
  {
    *back = CopyWinding(w: in);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044B760
// Name: void ClassifyWindingEpsilon(struct winding_t __near *,class Vector const __near &,float,float,struct winding_t __near * __near *,struct winding_t __near * __near *,struct winding_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClassifyWindingEpsilon(
        winding_t *in,
        const Vector *normal,
        float dist,
        float epsilon,
        winding_t **front,
        winding_t **back,
        winding_t **on)
{
  winding_t *v7; // ebx
  int numpoints; // edx
  int v9; // ecx
  int v10; // eax
  float y; // xmm2_4
  float x; // xmm3_4
  float z; // xmm4_4
  Vector *p; // esi
  float v15; // xmm0_4
  bool v16; // zf
  float v17; // xmm0_4
  winding_t *v18; // esi
  winding_t *v19; // esi
  winding_t *v20; // esi
  unsigned int v21; // edi
  winding_t *v22; // esi
  winding_t *v23; // edi
  int v24; // eax
  int v25; // eax
  float *v26; // ecx
  int v27; // edx
  Vector *v28; // eax
  Vector *v29; // eax
  int v30; // edx
  Vector *v31; // eax
  Vector *v32; // eax
  int v33; // edx
  Vector *v34; // eax
  Vector *v35; // eax
  Vector *v36; // edx
  int v37; // eax
  Vector *v38; // eax
  int v39; // eax
  int v40; // ebx
  const Vector *v41; // edx
  float v42; // xmm0_4
  float v43; // xmm1_4
  int v44; // ebx
  float v45; // xmm1_4
  int v46; // ecx
  float v47; // xmm0_4
  float v48; // xmm1_4
  float v49; // xmm2_4
  float *p_x; // eax
  float dists[68]; // [esp+0h] [ebp-240h]
  int sides[68]; // [esp+110h] [ebp-130h]
  int v53; // [esp+220h] [ebp-20h]
  int maxpts; // [esp+224h] [ebp-1Ch]
  Vector mid; // [esp+228h] [ebp-18h] BYREF
  int counts[3]; // [esp+234h] [ebp-Ch] BYREF
  int i; // [esp+258h] [ebp+18h]
  winding_t **backa; // [esp+25Ch] [ebp+1Ch]
  int ona; // [esp+260h] [ebp+20h]

  v7 = in;
  numpoints = in->numpoints;
  mid = vec3_origin;
  v9 = 0;
  v10 = 0;
  memset(counts, 0, sizeof(counts));
  if ( numpoints > 0 )
  {
    y = normal->y;
    x = normal->x;
    z = normal->z;
    p = in->p;
    do
    {
      v15 = (float)((float)((float)(p->y * y) + (float)(x * p->x)) + (float)(p->z * z)) - dist;
      dists[v10] = v15;
      if ( v15 <= epsilon )
      {
        if ( (float)-epsilon <= v15 )
          sides[v10] = 2;
        else
          sides[v10] = 1;
      }
      else
      {
        sides[v10] = 0;
      }
      ++counts[sides[v10++]];
      ++p;
    }
    while ( v10 < numpoints );
    v9 = counts[1];
  }
  v16 = counts[0] == 0;
  v17 = dists[0];
  sides[v10] = sides[0];
  dists[v10] = v17;
  *on = nullptr;
  *back = nullptr;
  *front = nullptr;
  if ( v16 )
  {
    if ( v9 != 0 )
    {
      v19 = AllocWinding(points: in->numpoints);
      v19->numpoints = in->numpoints;
      memcpy(dst: (unsigned __int8 *)v19->p, src: (unsigned __int8 *)in->p, count: 12 * in->numpoints);
      *back = v19;
    }
    else
    {
      v18 = AllocWinding(points: in->numpoints);
      v18->numpoints = in->numpoints;
      memcpy(dst: (unsigned __int8 *)v18->p, src: (unsigned __int8 *)in->p, count: 12 * in->numpoints);
      *on = v18;
    }
    return;
  }
  if ( v9 == 0 )
  {
    v20 = AllocWinding(points: in->numpoints);
    v20->numpoints = in->numpoints;
    memcpy(dst: (unsigned __int8 *)v20->p, src: (unsigned __int8 *)in->p, count: 12 * in->numpoints);
    *front = v20;
    return;
  }
  maxpts = in->numpoints + 4;
  v21 = maxpts;
  v22 = AllocWinding(points: maxpts);
  *front = v22;
  v23 = AllocWinding(points: v21);
  *back = v23;
  v24 = 0;
  i = 0;
  if ( in->numpoints > 0 )
  {
    backa = nullptr;
    do
    {
      v25 = sides[v24];
      v26 = (float *)((char *)backa + (unsigned int)v7->p);
      if ( v25 == 2 )
      {
        v27 = v22->numpoints;
        v28 = v22->p;
        v28[v27].x = *v26;
        v29 = &v28[v27];
        v29->y = v26[1];
        v29->z = v26[2];
        ++v22->numpoints;
        v30 = v23->numpoints;
        v31 = v23->p;
        v31[v30].x = *v26;
        v32 = &v31[v30];
        v32->y = v26[1];
        v32->z = v26[2];
      }
      else
      {
        if ( v25 == 0 )
        {
          v33 = v22->numpoints;
          v34 = v22->p;
          v34[v33].x = *v26;
          v35 = &v34[v33];
          v35->y = v26[1];
          v35->z = v26[2];
          ++v22->numpoints;
        }
        if ( sides[i] == 1 )
        {
          v36 = v23->p;
          v37 = v23->numpoints;
          v36[v37].x = *v26;
          v38 = &v36[v37];
          v38->y = v26[1];
          v38->z = v26[2];
          ++v23->numpoints;
        }
        v39 = sides[i + 1];
        if ( v39 == 2 || v39 == sides[i] )
          goto LABEL_35;
        ona = 3;
        v40 = (int)&v7->p[(i + 1) % v7->numpoints];
        v41 = normal;
        v42 = dists[i];
        v43 = v42 - dists[i + 1];
        v53 = (char *)v26 - (char *)normal;
        v44 = v40 - (_DWORD)normal;
        v45 = v42 / v43;
        v46 = (char *)&mid - (char *)normal;
        do
        {
          if ( v41->x == 1.0 )
          {
            *(float *)((char *)&v41->x + v46) = dist;
          }
          else if ( v41->x == -1.0 )
          {
            *(float *)((char *)&v41->x + v46) = -dist;
          }
          else
          {
            *(float *)((char *)&v41->x + v46) = (float)((float)(*(float *)((char *)&v41->x + v44)
                                                              - *(float *)((char *)&v41->x + v53))
                                                      * v45)
                                              + *(float *)((char *)&v41->x + v53);
          }
          v41 = (const Vector *)((char *)v41 + 4);
          --ona;
        }
        while ( ona != 0 );
        v47 = mid.x;
        v48 = mid.y;
        v49 = mid.z;
        v7 = in;
        v22->p[v22->numpoints++] = mid;
        p_x = &v23->p[v23->numpoints].x;
        *p_x = v47;
        p_x[1] = v48;
        p_x[2] = v49;
      }
      ++v23->numpoints;
LABEL_35:
      backa += 3;
      v24 = i + 1;
      i = v24;
    }
    while ( v24 < v7->numpoints );
  }
  if ( v22->numpoints > maxpts || v23->numpoints > maxpts )
    _Error(a1: "ClipWinding: points exceeded estimate");
  if ( v22->numpoints > 64 || v23->numpoints > 64 )
    _Error(a1: "ClipWinding: MAX_POINTS_ON_WINDING");
}

//------------------------------------------------------------------------------
// Address: 0x0044BB60
// Name: void ChopWindingInPlace(struct winding_t __near * __near *,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ChopWindingInPlace(winding_t **inout, const Vector *normal, float dist, float epsilon)
{
  winding_t *v4; // esi
  winding_t *v5; // ebx
  int numpoints; // edi
  int v7; // eax
  float y; // xmm2_4
  float x; // xmm3_4
  float z; // xmm4_4
  float *p_x; // edx
  float v12; // xmm0_4
  float v13; // xmm0_4
  winding_t *v14; // eax
  int v15; // edi
  int v16; // eax
  float *v17; // ecx
  float *v18; // eax
  Vector *p; // edx
  int v20; // eax
  Vector *v21; // eax
  int v22; // eax
  int v23; // edx
  float v24; // xmm1_4
  int v25; // eax
  const Vector *v26; // edx
  int v27; // ecx
  int v28; // edi
  int maxpoints; // eax
  float dists[68]; // [esp+0h] [ebp-24Ch]
  int sides[68]; // [esp+110h] [ebp-13Ch]
  int counts[3]; // [esp+220h] [ebp-2Ch] BYREF
  int v33; // [esp+22Ch] [ebp-20h]
  Vector mid; // [esp+230h] [ebp-1Ch] BYREF
  int maxpts; // [esp+23Ch] [ebp-10h]
  int i; // [esp+240h] [ebp-Ch]
  int v37; // [esp+244h] [ebp-8h]
  unsigned int v38; // [esp+248h] [ebp-4h]

  v4 = *inout;
  v5 = nullptr;
  numpoints = (*inout)->numpoints;
  mid = vec3_origin;
  v7 = 0;
  memset(counts, 0, sizeof(counts));
  if ( numpoints > 0 )
  {
    y = normal->y;
    x = normal->x;
    z = normal->z;
    p_x = &v4->p->x;
    do
    {
      v12 = (float)((float)((float)(p_x[1] * y) + (float)(x * *p_x)) + (float)(p_x[2] * z)) - dist;
      dists[v7] = v12;
      if ( v12 <= epsilon )
      {
        if ( (float)-epsilon <= v12 )
          sides[v7] = 2;
        else
          sides[v7] = 1;
      }
      else
      {
        sides[v7] = 0;
      }
      ++counts[sides[v7++]];
      p_x += 3;
    }
    while ( v7 < numpoints );
    v5 = nullptr;
  }
  v13 = dists[0];
  sides[v7] = sides[0];
  dists[v7] = v13;
  if ( counts[0] != 0 )
  {
    if ( counts[1] == 0 )
      return;
    maxpts = numpoints + 4;
    v14 = AllocWinding(points: numpoints + 4);
    v15 = 0;
    v5 = v14;
    i = 0;
    if ( v4->numpoints <= 0 )
    {
LABEL_32:
      if ( v5->numpoints > maxpts )
        _Error(a1: "ClipWinding: points exceeded estimate");
      if ( v5->numpoints > 64 )
        _Error(a1: "ClipWinding: MAX_POINTS_ON_WINDING");
      if ( v4->numpoints != -559030611 )
        goto LABEL_38;
      goto LABEL_37;
    }
    v38 = 0;
    while ( 1 )
    {
      v16 = sides[v15];
      v17 = &v4->p[v38 / 0xC].x;
      if ( v16 == 2 )
      {
        v18 = &v5->p[v5->numpoints].x;
        *v18 = *v17;
        v18[1] = v17[1];
        v18[2] = v17[2];
      }
      else
      {
        if ( v16 == 0 )
        {
          p = v5->p;
          v20 = v5->numpoints;
          p[v20].x = *v17;
          v21 = &p[v20];
          v21->y = v17[1];
          v21->z = v17[2];
          ++v5->numpoints;
        }
        v22 = sides[v15 + 1];
        if ( v22 == 2 || v22 == sides[v15] )
          goto LABEL_31;
        v23 = (v15 + 1) % v4->numpoints;
        v24 = dists[v15] / (float)(dists[v15] - dists[v15 + 1]);
        v37 = 3;
        v25 = (int)&v4->p[v23];
        v26 = normal;
        v33 = v25 - (_DWORD)normal;
        v27 = (char *)v17 - (char *)normal;
        v28 = (char *)&mid - (char *)normal;
        do
        {
          if ( v26->x == 1.0 )
          {
            *(float *)((char *)&v26->x + v28) = dist;
          }
          else if ( v26->x == -1.0 )
          {
            *(float *)((char *)&v26->x + v28) = -dist;
          }
          else
          {
            *(float *)((char *)&v26->x + v28) = (float)((float)(*(float *)((char *)&v26->x + v33)
                                                              - *(float *)((char *)&v26->x + v27))
                                                      * v24)
                                              + *(float *)((char *)&v26->x + v27);
          }
          v26 = (const Vector *)((char *)v26 + 4);
          --v37;
        }
        while ( v37 != 0 );
        v15 = i;
        v5->p[v5->numpoints] = mid;
      }
      ++v5->numpoints;
LABEL_31:
      v38 += 12;
      i = ++v15;
      if ( v15 >= v4->numpoints )
        goto LABEL_32;
    }
  }
  if ( numpoints == -559030611 )
LABEL_37:
    _Error(a1: "FreeWinding: freed a freed winding");
LABEL_38:
  ThreadLock();
  maxpoints = v4->maxpoints;
  v4->numpoints = -559030611;
  v4->next = winding_pool[maxpoints];
  winding_pool[maxpoints] = v4;
  ThreadUnlock();
  *inout = v5;
}

//------------------------------------------------------------------------------
// Address: 0x0044BE80
// Name: int WindingOnPlaneSide(struct winding_t __near *,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
int __cdecl WindingOnPlaneSide(winding_t *w, const Vector *normal, float dist)
{
  int v3; // ebx
  int v4; // edi
  int v5; // eax
  Vector *p; // edx
  float v7; // xmm0_4

  v3 = 0;
  v4 = 0;
  v5 = 0;
  if ( w->numpoints <= 0 )
    return 2;
  p = w->p;
  do
  {
    v7 = (float)((float)((float)(p->y * normal->y) + (float)(p->x * normal->x)) + (float)(p->z * normal->z)) - dist;
    if ( v7 >= -0.1 )
    {
      if ( v7 > 0.1 )
      {
        if ( v4 != 0 )
          return -2;
        v3 = 1;
      }
    }
    else
    {
      if ( v3 != 0 )
        return -2;
      v4 = 1;
    }
    ++v5;
    ++p;
  }
  while ( v5 < w->numpoints );
  if ( v4 != 0 )
    return 1;
  if ( v3 != 0 )
    return 0;
  else
    return 2;
}

//------------------------------------------------------------------------------
// Address: 0x0044BF50
// Name: void TranslateWinding(struct winding_t __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TranslateWinding(winding_t *pWinding, const Vector *offset)
{
  int v2; // esi
  int v3; // edx
  Vector *p; // eax
  float v5; // xmm0_4
  float *p_x; // eax

  v2 = 0;
  if ( pWinding->numpoints > 0 )
  {
    v3 = 0;
    do
    {
      p = pWinding->p;
      v5 = p[v3].x + offset->x;
      p_x = &p[v3].x;
      *p_x = v5;
      p_x[1] = offset->y + p_x[1];
      ++v2;
      p_x[2] = offset->z + p_x[2];
      ++v3;
    }
    while ( v2 < pWinding->numpoints );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044BFA0
// Name: void ClipWindingEpsilon_Offset(struct winding_t __near *,class Vector const __near &,float,float,struct winding_t __near * __near *,struct winding_t __near * __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClipWindingEpsilon_Offset(
        winding_t *in,
        Vector *normal,
        float dist,
        float epsilon,
        winding_t **front,
        winding_t **back,
        const Vector *offset)
{
  int v7; // ecx
  int v8; // edx
  Vector *p; // eax
  float v10; // xmm0_4
  float *p_x; // eax
  int v12; // ecx
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  int v16; // edx
  Vector *v17; // eax
  float x; // xmm4_4
  float *v19; // eax
  winding_t *v20; // ecx
  int v21; // edx
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  int v25; // edi
  Vector *v26; // eax
  float v27; // xmm4_4
  float *v28; // eax
  winding_t *v29; // ecx
  int v30; // edx
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm3_4
  int v34; // esi
  Vector *v35; // eax
  float v36; // xmm0_4
  float *v37; // eax

  v7 = 0;
  if ( in->numpoints > 0 )
  {
    v8 = 0;
    do
    {
      p = in->p;
      v10 = p[v8].x + offset->x;
      p_x = &p[v8].x;
      *p_x = v10;
      p_x[1] = offset->y + p_x[1];
      ++v7;
      p_x[2] = offset->z + p_x[2];
      ++v8;
    }
    while ( v7 < in->numpoints );
  }
  ClipWindingEpsilon(
    in,
    normal,
    dist: (float)((float)((float)(normal->y * offset->y) + (float)(normal->x * offset->x)) + (float)(normal->z * offset->z))
  + dist,
    epsilon,
    front,
    back);
  v12 = 0;
  v13 = -offset->x;
  v14 = -offset->y;
  v15 = -offset->z;
  if ( in->numpoints > 0 )
  {
    v16 = 0;
    do
    {
      v17 = in->p;
      x = v17[v16].x;
      v19 = &v17[v16].x;
      *v19 = x + v13;
      v19[1] = v19[1] + v14;
      ++v12;
      v19[2] = v19[2] + v15;
      ++v16;
    }
    while ( v12 < in->numpoints );
  }
  if ( front != nullptr )
  {
    v20 = *front;
    if ( *front != nullptr )
    {
      v21 = 0;
      v22 = -offset->x;
      v23 = -offset->y;
      v24 = -offset->z;
      if ( v20->numpoints > 0 )
      {
        v25 = 0;
        do
        {
          v26 = v20->p;
          v27 = v26[v25].x;
          v28 = &v26[v25].x;
          *v28 = v27 + v22;
          v28[1] = v28[1] + v23;
          ++v21;
          v28[2] = v28[2] + v24;
          ++v25;
        }
        while ( v21 < v20->numpoints );
      }
    }
  }
  if ( back != nullptr )
  {
    v29 = *back;
    if ( *back != nullptr )
    {
      v30 = 0;
      v31 = -offset->x;
      v32 = -offset->y;
      v33 = -offset->z;
      if ( v29->numpoints > 0 )
      {
        v34 = 0;
        do
        {
          v35 = v29->p;
          v36 = v35[v34].x;
          v37 = &v35[v34].x;
          *v37 = v36 + v31;
          v37[1] = v37[1] + v32;
          ++v30;
          v37[2] = v37[2] + v33;
          ++v34;
        }
        while ( v30 < v29->numpoints );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044C160
// Name: void ClassifyWindingEpsilon_Offset(struct winding_t __near *,class Vector const __near &,float,float,struct winding_t __near * __near *,struct winding_t __near * __near *,struct winding_t __near * __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClassifyWindingEpsilon_Offset(
        winding_t *in,
        const Vector *normal,
        float dist,
        float epsilon,
        winding_t **front,
        winding_t **back,
        winding_t **on,
        const Vector *offset)
{
  int v8; // ecx
  int v9; // edx
  Vector *p; // eax
  float v11; // xmm0_4
  float *p_x; // eax
  int v13; // ecx
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  int v17; // edx
  Vector *v18; // eax
  float x; // xmm4_4
  float *v20; // eax
  winding_t *v21; // ecx
  int v22; // edx
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  int v26; // edi
  Vector *v27; // eax
  float v28; // xmm4_4
  float *v29; // eax
  winding_t *v30; // ecx
  int v31; // edx
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm3_4
  int v35; // edi
  Vector *v36; // eax
  float v37; // xmm4_4
  float *v38; // eax
  winding_t *v39; // ecx
  int v40; // edx
  float v41; // xmm1_4
  float v42; // xmm2_4
  float v43; // xmm3_4
  int v44; // esi
  Vector *v45; // eax
  float v46; // xmm0_4
  float *v47; // eax

  v8 = 0;
  if ( in->numpoints > 0 )
  {
    v9 = 0;
    do
    {
      p = in->p;
      v11 = offset->x + p[v9].x;
      p_x = &p[v9].x;
      *p_x = v11;
      p_x[1] = offset->y + p_x[1];
      ++v8;
      p_x[2] = offset->z + p_x[2];
      ++v9;
    }
    while ( v8 < in->numpoints );
  }
  ClassifyWindingEpsilon(
    in,
    normal,
    dist: (float)((float)((float)(normal->y * offset->y) + (float)(normal->x * offset->x)) + (float)(normal->z * offset->z))
  + dist,
    epsilon,
    front,
    back,
    on);
  v13 = 0;
  v14 = -offset->x;
  v15 = -offset->y;
  v16 = -offset->z;
  if ( in->numpoints > 0 )
  {
    v17 = 0;
    do
    {
      v18 = in->p;
      x = v18[v17].x;
      v20 = &v18[v17].x;
      *v20 = x + v14;
      v20[1] = v20[1] + v15;
      ++v13;
      v20[2] = v20[2] + v16;
      ++v17;
    }
    while ( v13 < in->numpoints );
  }
  if ( front != nullptr )
  {
    v21 = *front;
    if ( *front != nullptr )
    {
      v22 = 0;
      v23 = -offset->x;
      v24 = -offset->y;
      v25 = -offset->z;
      if ( v21->numpoints > 0 )
      {
        v26 = 0;
        do
        {
          v27 = v21->p;
          v28 = v27[v26].x;
          v29 = &v27[v26].x;
          *v29 = v28 + v23;
          v29[1] = v29[1] + v24;
          ++v22;
          v29[2] = v29[2] + v25;
          ++v26;
        }
        while ( v22 < v21->numpoints );
      }
    }
  }
  if ( back != nullptr )
  {
    v30 = *back;
    if ( *back != nullptr )
    {
      v31 = 0;
      v32 = -offset->x;
      v33 = -offset->y;
      v34 = -offset->z;
      if ( v30->numpoints > 0 )
      {
        v35 = 0;
        do
        {
          v36 = v30->p;
          v37 = v36[v35].x;
          v38 = &v36[v35].x;
          *v38 = v37 + v32;
          v38[1] = v38[1] + v33;
          ++v31;
          v38[2] = v38[2] + v34;
          ++v35;
        }
        while ( v31 < v30->numpoints );
      }
    }
  }
  if ( on != nullptr )
  {
    v39 = *on;
    if ( *on != nullptr )
    {
      v40 = 0;
      v41 = -offset->x;
      v42 = -offset->y;
      v43 = -offset->z;
      if ( v39->numpoints > 0 )
      {
        v44 = 0;
        do
        {
          v45 = v39->p;
          v46 = v45[v44].x;
          v47 = &v45[v44].x;
          *v47 = v46 + v41;
          v47[1] = v42 + v47[1];
          ++v40;
          v47[2] = v43 + v47[2];
          ++v44;
        }
        while ( v40 < v39->numpoints );
      }
    }
  }
}

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00455D60
// Name: struct winding_t __near * AllocWinding(int)
// Source: json
//------------------------------------------------------------------------------
winding_t *__cdecl AllocWinding(unsigned int points)
{
  int v1; // eax
  winding_t *v2; // esi

  if ( numthreads == 1 )
  {
    ++c_winding_allocs;
    c_winding_points += points;
    v1 = c_active_windings + 1;
    c_active_windings = v1;
    if ( v1 > c_peak_windings )
      c_peak_windings = v1;
  }
  ThreadLock();
  v2 = winding_pool[points];
  if ( v2 != nullptr )
  {
    winding_pool[points] = v2->next;
  }
  else
  {
    v2 = (winding_t *)MemAlloc_Alloc(nSize: 0x10u);
    v2->p = (Vector *)calloc(count: points, size: 0xCu);
  }
  ThreadUnlock();
  v2->maxpoints = points;
  v2->numpoints = 0;
  v2->next = nullptr;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00455DF0
// Name: void FreeWinding(struct winding_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FreeWinding(winding_t *w)
{
  int maxpoints; // eax

  if ( w->numpoints == -559030611 )
    _Error(a1: "FreeWinding: freed a freed winding");
  ThreadLock();
  maxpoints = w->maxpoints;
  w->numpoints = -559030611;
  w->next = winding_pool[maxpoints];
  winding_pool[maxpoints] = w;
  ThreadUnlock();
}

//------------------------------------------------------------------------------
// Address: 0x00455E40
// Name: void WindingPlane(struct winding_t __near *,class Vector __near &,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WindingPlane(winding_t *w, Vector *normal, float *dist)
{
  Vector *p; // eax
  float v4; // xmm4_4
  float v5; // xmm5_4
  float v6; // xmm3_4
  float x; // xmm0_4
  float y; // xmm2_4
  float z; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm0_4

  p = w->p;
  v4 = p[1].x - p->x;
  v5 = p[1].y - p->y;
  v6 = p[1].z - p->z;
  if ( w->numpoints <= 3 )
  {
    x = p[2].x;
    y = p[2].y;
    z = p[2].z;
  }
  else
  {
    x = p[3].x;
    y = p[3].y;
    z = p[3].z;
  }
  v10 = y - p->y;
  v11 = z - p->z;
  v12 = x - p->x;
  normal->x = (float)(v10 * v6) - (float)(v11 * v5);
  normal->y = (float)(v11 * v4) - (float)(v6 * v12);
  normal->z = (float)(v12 * v5) - (float)(v10 * v4);
  VectorNormalize(vec: normal);
  *dist = (float)((float)(w->p->y * normal->y) + (float)(w->p->x * normal->x)) + (float)(w->p->z * normal->z);
}

//------------------------------------------------------------------------------
// Address: 0x00455F20
// Name: float WindingArea(struct winding_t __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl WindingArea(winding_t *w)
{
  Vector *p; // ecx
  float *p_z; // eax
  int v3; // edx
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm5_4
  float v9; // xmm6_4
  float v11; // [esp-4h] [ebp-10h]

  v11 = 0.0;
  if ( w->numpoints > 2 )
  {
    p = w->p;
    p_z = &p[1].z;
    v3 = w->numpoints - 2;
    do
    {
      v4 = p_z[2] - p->y;
      v5 = *p_z - p->z;
      v6 = p_z[1] - p->x;
      v7 = p_z[3] - p->z;
      v8 = *(p_z - 2) - p->x;
      v9 = *(p_z - 1) - p->y;
      p_z += 3;
      --v3;
      v11 = fsqrt(
              (float)((float)((float)((float)(v5 * v6) - (float)(v7 * v8)) * (float)((float)(v5 * v6) - (float)(v7 * v8)))
                    + (float)((float)((float)(v4 * v8) - (float)(v6 * v9)) * (float)((float)(v4 * v8) - (float)(v6 * v9))))
            + (float)((float)((float)(v7 * v9) - (float)(v4 * v5)) * (float)((float)(v7 * v9) - (float)(v4 * v5))))
          + v11;
    }
    while ( v3 != 0 );
  }
  return v11 * 0.5;
}

//------------------------------------------------------------------------------
// Address: 0x00456010
// Name: void WindingCenter(struct winding_t __near *,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WindingCenter(winding_t *w, Vector *center)
{
  int v2; // edi
  float y; // xmm0_4
  float z; // xmm1_4
  int v5; // esi
  Vector *p; // ecx
  float v7; // xmm0_4

  *center = vec3_origin;
  v2 = 0;
  if ( w->numpoints > 0 )
  {
    y = center->y;
    z = center->z;
    v5 = 0;
    do
    {
      p = w->p;
      center->x = p[v5].x + center->x;
      y = y + p[v5].y;
      center->y = y;
      z = z + p[v5].z;
      ++v2;
      center->z = z;
      ++v5;
    }
    while ( v2 < w->numpoints );
  }
  v7 = 1.0 / (double)w->numpoints;
  center->x = center->x * v7;
  center->y = center->y * v7;
  center->z = center->z * v7;
}

//------------------------------------------------------------------------------
// Address: 0x004560D0
// Name: struct winding_t __near * BaseWindingForPlane(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
winding_t *__cdecl BaseWindingForPlane(const Vector *normal, float dist)
{
  float v2; // xmm1_4
  int v3; // edi
  float v4; // xmm0_4
  float v5; // xmm0_4
  float x; // xmm5_4
  float z; // xmm4_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm3_4
  float v11; // xmm4_4
  float y; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  winding_t *result; // eax
  Vector *p; // ecx
  Vector *v18; // ecx
  Vector *v19; // ecx
  Vector *v20; // ecx
  Vector *v21; // ecx
  Vector *v22; // ecx
  Vector *v23; // ecx
  Vector *v24; // ecx
  float org; // [esp+0h] [ebp-24h]
  float org_4; // [esp+4h] [ebp-20h]
  Vector vup; // [esp+18h] [ebp-Ch] BYREF

  v2 = -1.0;
  v3 = -1;
  v4 = fabs(normal->x);
  if ( v4 > -1.0 )
  {
    v3 = 0;
    v2 = v4;
  }
  v5 = fabs(normal->y);
  if ( v5 > v2 )
  {
    v3 = 1;
    v2 = v5;
  }
  if ( fabs(normal->z) <= v2 )
  {
    if ( v3 == -1 )
      _Error(a1: "BaseWindingForPlane: no axis found");
  }
  else
  {
    v3 = 2;
  }
  x = vec3_origin.x;
  z = vec3_origin.z;
  if ( v3 >= 0 )
  {
    if ( v3 <= 1 )
      z = 1.0;
    else
      x = 1.0;
  }
  LODWORD(v8) = COERCE_UNSIGNED_INT((float)((float)(normal->y * vec3_origin.y) + (float)(normal->x * x)) + (float)(normal->z * z))
              ^ _mask__NegFloat_;
  v9 = (float)(normal->y * v8) + vec3_origin.y;
  v10 = (float)(normal->z * v8) + z;
  vup.x = (float)(normal->x * v8) + x;
  vup.y = v9;
  vup.z = v10;
  VectorNormalize(vec: &vup);
  v11 = normal->z;
  org = normal->x * dist;
  y = normal->y;
  org_4 = y * dist;
  v13 = (float)(v11 * vup.y) - (float)(y * vup.z);
  v14 = (float)(y * vup.x) - (float)(normal->x * vup.y);
  v15 = (float)((float)(normal->x * vup.z) - (float)(v11 * vup.x)) * 65536.0;
  vup.x = vup.x * 65536.0;
  vup.y = vup.y * 65536.0;
  vup.z = vup.z * 65536.0;
  result = AllocWinding(points: 4u);
  p = result->p;
  p->x = org - (float)(v13 * 65536.0);
  p->y = org_4 - v15;
  p->z = (float)(v11 * dist) - (float)(v14 * 65536.0);
  v18 = result->p;
  v18->x = v18->x + vup.x;
  v18->y = v18->y + vup.y;
  v18->z = v18->z + vup.z;
  v19 = result->p;
  v19[1].x = org + (float)(v13 * 65536.0);
  v19[1].y = v15 + org_4;
  v19[1].z = (float)(v14 * 65536.0) + (float)(v11 * dist);
  v20 = result->p;
  v20[1].x = v20[1].x + vup.x;
  v20[1].y = v20[1].y + vup.y;
  v20[1].z = v20[1].z + vup.z;
  v21 = result->p;
  v21[2].x = org + (float)(v13 * 65536.0);
  v21[2].y = v15 + org_4;
  v21[2].z = (float)(v14 * 65536.0) + (float)(v11 * dist);
  v22 = result->p;
  v22[2].x = v22[2].x - vup.x;
  v22[2].y = v22[2].y - vup.y;
  v22[2].z = v22[2].z - vup.z;
  v23 = result->p;
  v23[3].x = org - (float)(v13 * 65536.0);
  v23[3].y = org_4 - v15;
  v23[3].z = (float)(v11 * dist) - (float)(v14 * 65536.0);
  v24 = result->p;
  v24[3].x = v24[3].x - vup.x;
  v24[3].y = v24[3].y - vup.y;
  v24[3].z = v24[3].z - vup.z;
  result->numpoints = 4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004563E0
// Name: struct winding_t __near * CopyWinding(struct winding_t __near *)
// Source: json
//------------------------------------------------------------------------------
winding_t *__cdecl CopyWinding(winding_t *w)
{
  winding_t *v1; // edi

  v1 = AllocWinding(points: w->numpoints);
  v1->numpoints = w->numpoints;
  memcpy(dst: (unsigned __int8 *)v1->p, src: (unsigned __int8 *)w->p, count: 12 * w->numpoints);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x00456420
// Name: struct winding_t __near * ReverseWinding(struct winding_t __near *)
// Source: json
//------------------------------------------------------------------------------
winding_t *__cdecl ReverseWinding(winding_t *w)
{
  winding_t *result; // eax
  int numpoints; // edx
  int v4; // esi
  int v5; // ebx
  Vector *p; // ecx
  Vector *v7; // eax
  int v8; // edx
  double v9; // st7
  float *v10; // edx
  winding_t *c; // [esp+10h] [ebp+8h]

  result = AllocWinding(points: w->numpoints);
  numpoints = w->numpoints;
  v4 = 0;
  c = result;
  if ( numpoints > 0 )
  {
    v5 = 0;
    do
    {
      p = result->p;
      v7 = w->p;
      v8 = 3 * (numpoints - v4) - 3;
      v9 = *(&v7->x + v8);
      v10 = &v7->x + v8;
      result = c;
      p[v5].x = v9;
      ++v4;
      p[v5++].y = v10[1];
      p[v5 - 1].z = v10[2];
      numpoints = w->numpoints;
    }
    while ( v4 < w->numpoints );
  }
  result->numpoints = w->numpoints;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00456480
// Name: void ClipWindingEpsilon(struct winding_t __near *,class Vector const __near &,float,float,struct winding_t __near * __near *,struct winding_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClipWindingEpsilon(
        winding_t *in,
        Vector *normal,
        float dist,
        float epsilon,
        winding_t **front,
        winding_t **back)
{
  float *v6; // esi
  float *v7; // edi
  float *v8; // eax
  float v9; // [esp+8h] [ebp-280h]
  Vector *v10; // [esp+18h] [ebp-270h]
  Vector *v11; // [esp+1Ch] [ebp-26Ch]
  Vector *v12; // [esp+20h] [ebp-268h]
  Vector *v13; // [esp+24h] [ebp-264h]
  Vector *p1; // [esp+2Ch] [ebp-25Ch]
  Vector *p2; // [esp+30h] [ebp-258h]
  int j; // [esp+34h] [ebp-254h]
  float dists[68]; // [esp+38h] [ebp-250h]
  winding_t *b; // [esp+148h] [ebp-140h]
  int counts[3]; // [esp+14Ch] [ebp-13Ch] BYREF
  int sides[69]; // [esp+158h] [ebp-130h]
  winding_t *f; // [esp+26Ch] [ebp-1Ch]
  int i; // [esp+270h] [ebp-18h]
  int maxpts; // [esp+274h] [ebp-14h]
  float dot; // [esp+278h] [ebp-10h]
  Vector mid; // [esp+27Ch] [ebp-Ch] BYREF

  mid = vec3_origin;
  memset(counts, 0, sizeof(counts));
  for ( i = 0; i < in->numpoints; ++i )
  {
    dot = (float)((float)((float)(in->p[i].x * normal->x) + (float)(in->p[i].y * normal->y))
                + (float)(in->p[i].z * normal->z))
        - dist;
    dists[i] = dot;
    if ( dot <= epsilon )
    {
      if ( COERCE_FLOAT(LODWORD(epsilon) ^ _mask__NegFloat_) <= dot )
        sides[i] = 2;
      else
        sides[i] = 1;
    }
    else
    {
      sides[i] = 0;
    }
    ++counts[sides[i]];
  }
  sides[i] = sides[0];
  dists[i] = dists[0];
  *back = nullptr;
  *front = nullptr;
  if ( counts[0] != 0 )
  {
    if ( counts[1] != 0 )
    {
      maxpts = in->numpoints + 4;
      f = AllocWinding(points: maxpts);
      *front = f;
      b = AllocWinding(points: maxpts);
      *back = b;
      for ( i = 0; i < in->numpoints; ++i )
      {
        p1 = &in->p[i];
        if ( sides[i] == 2 )
        {
          v13 = &f->p[f->numpoints];
          v13->x = p1->x;
          v13->y = p1->y;
          v13->z = p1->z;
          ++f->numpoints;
          v12 = &b->p[b->numpoints];
          v12->x = p1->x;
          v12->y = p1->y;
          v12->z = p1->z;
          ++b->numpoints;
        }
        else
        {
          if ( sides[i] == 0 )
          {
            v11 = &f->p[f->numpoints];
            v11->x = p1->x;
            v11->y = p1->y;
            v11->z = p1->z;
            ++f->numpoints;
          }
          if ( sides[i] == 1 )
          {
            v10 = &b->p[b->numpoints];
            v10->x = p1->x;
            v10->y = p1->y;
            v10->z = p1->z;
            ++b->numpoints;
          }
          if ( sides[i + 1] != 2 && sides[i + 1] != sides[i] )
          {
            p2 = &in->p[(i + 1) % in->numpoints];
            dot = dists[i] / (float)(dists[i] - dists[i + 1]);
            for ( j = 0; j < 3; ++j )
            {
              if ( Vector::operator[](this: normal, i: j) == 1.0 )
              {
                *Vector::operator[](this: &mid, i: j) = dist;
              }
              else if ( Vector::operator[](this: normal, i: j) == -1.0 )
              {
                *(_DWORD *)Vector::operator[](this: &mid, i: j) = LODWORD(dist) ^ _mask__NegFloat_;
              }
              else
              {
                v6 = Vector::operator[](this: p1, i: j);
                v7 = Vector::operator[](this: p2, i: j);
                v8 = Vector::operator[](this: p1, i: j);
                v9 = (float)((float)(*v7 - *v8) * dot) + *v6;
                *Vector::operator[](this: &mid, i: j) = v9;
              }
            }
            f->p[f->numpoints++] = mid;
            b->p[b->numpoints++] = mid;
          }
        }
      }
      if ( f->numpoints > maxpts || b->numpoints > maxpts )
        _Error(a1: "ClipWinding: points exceeded estimate");
      if ( f->numpoints > 64 || b->numpoints > 64 )
        _Error(a1: "ClipWinding: MAX_POINTS_ON_WINDING");
    }
    else
    {
      *front = CopyWinding(w: in);
    }
  }
  else
  {
    *back = CopyWinding(w: in);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00456AF0
// Name: void ClassifyWindingEpsilon(struct winding_t __near *,class Vector const __near &,float,float,struct winding_t __near * __near *,struct winding_t __near * __near *,struct winding_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClassifyWindingEpsilon(
        winding_t *in,
        const Vector *normal,
        float dist,
        float epsilon,
        winding_t **front,
        winding_t **back,
        winding_t **on)
{
  winding_t *v7; // ebx
  int numpoints; // edx
  int v9; // ecx
  int v10; // eax
  float y; // xmm2_4
  float x; // xmm3_4
  float z; // xmm4_4
  Vector *p; // esi
  float v15; // xmm0_4
  bool v16; // zf
  float v17; // xmm0_4
  winding_t *v18; // esi
  winding_t *v19; // esi
  winding_t *v20; // esi
  unsigned int v21; // edi
  winding_t *v22; // esi
  winding_t *v23; // edi
  int v24; // eax
  int v25; // eax
  float *v26; // ecx
  int v27; // edx
  Vector *v28; // eax
  Vector *v29; // eax
  int v30; // edx
  Vector *v31; // eax
  Vector *v32; // eax
  int v33; // edx
  Vector *v34; // eax
  Vector *v35; // eax
  Vector *v36; // edx
  int v37; // eax
  Vector *v38; // eax
  int v39; // eax
  int v40; // ebx
  const Vector *v41; // edx
  float v42; // xmm0_4
  float v43; // xmm1_4
  int v44; // ebx
  float v45; // xmm1_4
  int v46; // ecx
  float v47; // xmm0_4
  float v48; // xmm1_4
  float v49; // xmm2_4
  float *p_x; // eax
  float dists[68]; // [esp+0h] [ebp-240h]
  int sides[68]; // [esp+110h] [ebp-130h]
  int v53; // [esp+220h] [ebp-20h]
  int maxpts; // [esp+224h] [ebp-1Ch]
  Vector mid; // [esp+228h] [ebp-18h] BYREF
  int counts[3]; // [esp+234h] [ebp-Ch] BYREF
  int i; // [esp+258h] [ebp+18h]
  winding_t **backa; // [esp+25Ch] [ebp+1Ch]
  int ona; // [esp+260h] [ebp+20h]

  v7 = in;
  numpoints = in->numpoints;
  mid = vec3_origin;
  v9 = 0;
  v10 = 0;
  memset(counts, 0, sizeof(counts));
  if ( numpoints > 0 )
  {
    y = normal->y;
    x = normal->x;
    z = normal->z;
    p = in->p;
    do
    {
      v15 = (float)((float)((float)(p->y * y) + (float)(x * p->x)) + (float)(p->z * z)) - dist;
      dists[v10] = v15;
      if ( v15 <= epsilon )
      {
        if ( (float)-epsilon <= v15 )
          sides[v10] = 2;
        else
          sides[v10] = 1;
      }
      else
      {
        sides[v10] = 0;
      }
      ++counts[sides[v10++]];
      ++p;
    }
    while ( v10 < numpoints );
    v9 = counts[1];
  }
  v16 = counts[0] == 0;
  v17 = dists[0];
  sides[v10] = sides[0];
  dists[v10] = v17;
  *on = nullptr;
  *back = nullptr;
  *front = nullptr;
  if ( v16 )
  {
    if ( v9 != 0 )
    {
      v19 = AllocWinding(points: in->numpoints);
      v19->numpoints = in->numpoints;
      memcpy(dst: (unsigned __int8 *)v19->p, src: (unsigned __int8 *)in->p, count: 12 * in->numpoints);
      *back = v19;
    }
    else
    {
      v18 = AllocWinding(points: in->numpoints);
      v18->numpoints = in->numpoints;
      memcpy(dst: (unsigned __int8 *)v18->p, src: (unsigned __int8 *)in->p, count: 12 * in->numpoints);
      *on = v18;
    }
    return;
  }
  if ( v9 == 0 )
  {
    v20 = AllocWinding(points: in->numpoints);
    v20->numpoints = in->numpoints;
    memcpy(dst: (unsigned __int8 *)v20->p, src: (unsigned __int8 *)in->p, count: 12 * in->numpoints);
    *front = v20;
    return;
  }
  maxpts = in->numpoints + 4;
  v21 = maxpts;
  v22 = AllocWinding(points: maxpts);
  *front = v22;
  v23 = AllocWinding(points: v21);
  *back = v23;
  v24 = 0;
  i = 0;
  if ( in->numpoints > 0 )
  {
    backa = nullptr;
    do
    {
      v25 = sides[v24];
      v26 = (float *)((char *)backa + (unsigned int)v7->p);
      if ( v25 == 2 )
      {
        v27 = v22->numpoints;
        v28 = v22->p;
        v28[v27].x = *v26;
        v29 = &v28[v27];
        v29->y = v26[1];
        v29->z = v26[2];
        ++v22->numpoints;
        v30 = v23->numpoints;
        v31 = v23->p;
        v31[v30].x = *v26;
        v32 = &v31[v30];
        v32->y = v26[1];
        v32->z = v26[2];
      }
      else
      {
        if ( v25 == 0 )
        {
          v33 = v22->numpoints;
          v34 = v22->p;
          v34[v33].x = *v26;
          v35 = &v34[v33];
          v35->y = v26[1];
          v35->z = v26[2];
          ++v22->numpoints;
        }
        if ( sides[i] == 1 )
        {
          v36 = v23->p;
          v37 = v23->numpoints;
          v36[v37].x = *v26;
          v38 = &v36[v37];
          v38->y = v26[1];
          v38->z = v26[2];
          ++v23->numpoints;
        }
        v39 = sides[i + 1];
        if ( v39 == 2 || v39 == sides[i] )
          goto LABEL_35;
        ona = 3;
        v40 = (int)&v7->p[(i + 1) % v7->numpoints];
        v41 = normal;
        v42 = dists[i];
        v43 = v42 - dists[i + 1];
        v53 = (char *)v26 - (char *)normal;
        v44 = v40 - (_DWORD)normal;
        v45 = v42 / v43;
        v46 = (char *)&mid - (char *)normal;
        do
        {
          if ( v41->x == 1.0 )
          {
            *(float *)((char *)&v41->x + v46) = dist;
          }
          else if ( v41->x == -1.0 )
          {
            *(float *)((char *)&v41->x + v46) = -dist;
          }
          else
          {
            *(float *)((char *)&v41->x + v46) = (float)((float)(*(float *)((char *)&v41->x + v44)
                                                              - *(float *)((char *)&v41->x + v53))
                                                      * v45)
                                              + *(float *)((char *)&v41->x + v53);
          }
          v41 = (const Vector *)((char *)v41 + 4);
          --ona;
        }
        while ( ona != 0 );
        v47 = mid.x;
        v48 = mid.y;
        v49 = mid.z;
        v7 = in;
        v22->p[v22->numpoints++] = mid;
        p_x = &v23->p[v23->numpoints].x;
        *p_x = v47;
        p_x[1] = v48;
        p_x[2] = v49;
      }
      ++v23->numpoints;
LABEL_35:
      backa += 3;
      v24 = i + 1;
      i = v24;
    }
    while ( v24 < v7->numpoints );
  }
  if ( v22->numpoints > maxpts || v23->numpoints > maxpts )
    _Error(a1: "ClipWinding: points exceeded estimate");
  if ( v22->numpoints > 64 || v23->numpoints > 64 )
    _Error(a1: "ClipWinding: MAX_POINTS_ON_WINDING");
}

//------------------------------------------------------------------------------
// Address: 0x00456EF0
// Name: void ChopWindingInPlace(struct winding_t __near * __near *,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ChopWindingInPlace(winding_t **inout, const Vector *normal, float dist, float epsilon)
{
  winding_t *v4; // esi
  winding_t *v5; // ebx
  int numpoints; // edi
  int v7; // eax
  float y; // xmm2_4
  float x; // xmm3_4
  float z; // xmm4_4
  float *p_x; // edx
  float v12; // xmm0_4
  float v13; // xmm0_4
  winding_t *v14; // eax
  int v15; // edi
  int v16; // eax
  float *v17; // ecx
  float *v18; // eax
  Vector *p; // edx
  int v20; // eax
  Vector *v21; // eax
  int v22; // eax
  int v23; // edx
  float v24; // xmm1_4
  int v25; // eax
  const Vector *v26; // edx
  int v27; // ecx
  int v28; // edi
  int maxpoints; // eax
  float dists[68]; // [esp+0h] [ebp-24Ch]
  int sides[68]; // [esp+110h] [ebp-13Ch]
  int counts[3]; // [esp+220h] [ebp-2Ch] BYREF
  int v33; // [esp+22Ch] [ebp-20h]
  Vector mid; // [esp+230h] [ebp-1Ch] BYREF
  int maxpts; // [esp+23Ch] [ebp-10h]
  int i; // [esp+240h] [ebp-Ch]
  int v37; // [esp+244h] [ebp-8h]
  unsigned int v38; // [esp+248h] [ebp-4h]

  v4 = *inout;
  v5 = nullptr;
  numpoints = (*inout)->numpoints;
  mid = vec3_origin;
  v7 = 0;
  memset(counts, 0, sizeof(counts));
  if ( numpoints > 0 )
  {
    y = normal->y;
    x = normal->x;
    z = normal->z;
    p_x = &v4->p->x;
    do
    {
      v12 = (float)((float)((float)(p_x[1] * y) + (float)(x * *p_x)) + (float)(p_x[2] * z)) - dist;
      dists[v7] = v12;
      if ( v12 <= epsilon )
      {
        if ( (float)-epsilon <= v12 )
          sides[v7] = 2;
        else
          sides[v7] = 1;
      }
      else
      {
        sides[v7] = 0;
      }
      ++counts[sides[v7++]];
      p_x += 3;
    }
    while ( v7 < numpoints );
    v5 = nullptr;
  }
  v13 = dists[0];
  sides[v7] = sides[0];
  dists[v7] = v13;
  if ( counts[0] != 0 )
  {
    if ( counts[1] == 0 )
      return;
    maxpts = numpoints + 4;
    v14 = AllocWinding(points: numpoints + 4);
    v15 = 0;
    v5 = v14;
    i = 0;
    if ( v4->numpoints <= 0 )
    {
LABEL_32:
      if ( v5->numpoints > maxpts )
        _Error(a1: "ClipWinding: points exceeded estimate");
      if ( v5->numpoints > 64 )
        _Error(a1: "ClipWinding: MAX_POINTS_ON_WINDING");
      if ( v4->numpoints != -559030611 )
        goto LABEL_38;
      goto LABEL_37;
    }
    v38 = 0;
    while ( 1 )
    {
      v16 = sides[v15];
      v17 = &v4->p[v38 / 0xC].x;
      if ( v16 == 2 )
      {
        v18 = &v5->p[v5->numpoints].x;
        *v18 = *v17;
        v18[1] = v17[1];
        v18[2] = v17[2];
      }
      else
      {
        if ( v16 == 0 )
        {
          p = v5->p;
          v20 = v5->numpoints;
          p[v20].x = *v17;
          v21 = &p[v20];
          v21->y = v17[1];
          v21->z = v17[2];
          ++v5->numpoints;
        }
        v22 = sides[v15 + 1];
        if ( v22 == 2 || v22 == sides[v15] )
          goto LABEL_31;
        v23 = (v15 + 1) % v4->numpoints;
        v24 = dists[v15] / (float)(dists[v15] - dists[v15 + 1]);
        v37 = 3;
        v25 = (int)&v4->p[v23];
        v26 = normal;
        v33 = v25 - (_DWORD)normal;
        v27 = (char *)v17 - (char *)normal;
        v28 = (char *)&mid - (char *)normal;
        do
        {
          if ( v26->x == 1.0 )
          {
            *(float *)((char *)&v26->x + v28) = dist;
          }
          else if ( v26->x == -1.0 )
          {
            *(float *)((char *)&v26->x + v28) = -dist;
          }
          else
          {
            *(float *)((char *)&v26->x + v28) = (float)((float)(*(float *)((char *)&v26->x + v33)
                                                              - *(float *)((char *)&v26->x + v27))
                                                      * v24)
                                              + *(float *)((char *)&v26->x + v27);
          }
          v26 = (const Vector *)((char *)v26 + 4);
          --v37;
        }
        while ( v37 != 0 );
        v15 = i;
        v5->p[v5->numpoints] = mid;
      }
      ++v5->numpoints;
LABEL_31:
      v38 += 12;
      i = ++v15;
      if ( v15 >= v4->numpoints )
        goto LABEL_32;
    }
  }
  if ( numpoints == -559030611 )
LABEL_37:
    _Error(a1: "FreeWinding: freed a freed winding");
LABEL_38:
  ThreadLock();
  maxpoints = v4->maxpoints;
  v4->numpoints = -559030611;
  v4->next = winding_pool[maxpoints];
  winding_pool[maxpoints] = v4;
  ThreadUnlock();
  *inout = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00457210
// Name: void TranslateWinding(struct winding_t __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TranslateWinding(winding_t *pWinding, const Vector *offset)
{
  int v2; // esi
  int v3; // edx
  Vector *p; // eax
  float v5; // xmm0_4
  float *p_x; // eax

  v2 = 0;
  if ( pWinding->numpoints > 0 )
  {
    v3 = 0;
    do
    {
      p = pWinding->p;
      v5 = p[v3].x + offset->x;
      p_x = &p[v3].x;
      *p_x = v5;
      p_x[1] = offset->y + p_x[1];
      ++v2;
      p_x[2] = offset->z + p_x[2];
      ++v3;
    }
    while ( v2 < pWinding->numpoints );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00457260
// Name: void ClipWindingEpsilon_Offset(struct winding_t __near *,class Vector const __near &,float,float,struct winding_t __near * __near *,struct winding_t __near * __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClipWindingEpsilon_Offset(
        winding_t *in,
        Vector *normal,
        float dist,
        float epsilon,
        winding_t **front,
        winding_t **back,
        const Vector *offset)
{
  int v7; // ecx
  int v8; // edx
  Vector *p; // eax
  float v10; // xmm0_4
  float *p_x; // eax
  int v12; // ecx
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  int v16; // edx
  Vector *v17; // eax
  float x; // xmm4_4
  float *v19; // eax
  winding_t *v20; // ecx
  int v21; // edx
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  int v25; // edi
  Vector *v26; // eax
  float v27; // xmm4_4
  float *v28; // eax
  winding_t *v29; // ecx
  int v30; // edx
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm3_4
  int v34; // esi
  Vector *v35; // eax
  float v36; // xmm0_4
  float *v37; // eax

  v7 = 0;
  if ( in->numpoints > 0 )
  {
    v8 = 0;
    do
    {
      p = in->p;
      v10 = p[v8].x + offset->x;
      p_x = &p[v8].x;
      *p_x = v10;
      p_x[1] = offset->y + p_x[1];
      ++v7;
      p_x[2] = offset->z + p_x[2];
      ++v8;
    }
    while ( v7 < in->numpoints );
  }
  ClipWindingEpsilon(
    in,
    normal,
    dist: (float)((float)((float)(normal->y * offset->y) + (float)(normal->x * offset->x)) + (float)(normal->z * offset->z))
  + dist,
    epsilon,
    front,
    back);
  v12 = 0;
  v13 = -offset->x;
  v14 = -offset->y;
  v15 = -offset->z;
  if ( in->numpoints > 0 )
  {
    v16 = 0;
    do
    {
      v17 = in->p;
      x = v17[v16].x;
      v19 = &v17[v16].x;
      *v19 = x + v13;
      v19[1] = v19[1] + v14;
      ++v12;
      v19[2] = v19[2] + v15;
      ++v16;
    }
    while ( v12 < in->numpoints );
  }
  if ( front != nullptr )
  {
    v20 = *front;
    if ( *front != nullptr )
    {
      v21 = 0;
      v22 = -offset->x;
      v23 = -offset->y;
      v24 = -offset->z;
      if ( v20->numpoints > 0 )
      {
        v25 = 0;
        do
        {
          v26 = v20->p;
          v27 = v26[v25].x;
          v28 = &v26[v25].x;
          *v28 = v27 + v22;
          v28[1] = v28[1] + v23;
          ++v21;
          v28[2] = v28[2] + v24;
          ++v25;
        }
        while ( v21 < v20->numpoints );
      }
    }
  }
  if ( back != nullptr )
  {
    v29 = *back;
    if ( *back != nullptr )
    {
      v30 = 0;
      v31 = -offset->x;
      v32 = -offset->y;
      v33 = -offset->z;
      if ( v29->numpoints > 0 )
      {
        v34 = 0;
        do
        {
          v35 = v29->p;
          v36 = v35[v34].x;
          v37 = &v35[v34].x;
          *v37 = v36 + v31;
          v37[1] = v37[1] + v32;
          ++v30;
          v37[2] = v37[2] + v33;
          ++v34;
        }
        while ( v30 < v29->numpoints );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00457420
// Name: void ClassifyWindingEpsilon_Offset(struct winding_t __near *,class Vector const __near &,float,float,struct winding_t __near * __near *,struct winding_t __near * __near *,struct winding_t __near * __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClassifyWindingEpsilon_Offset(
        winding_t *in,
        const Vector *normal,
        float dist,
        float epsilon,
        winding_t **front,
        winding_t **back,
        winding_t **on,
        const Vector *offset)
{
  int v8; // ecx
  int v9; // edx
  Vector *p; // eax
  float v11; // xmm0_4
  float *p_x; // eax
  int v13; // ecx
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  int v17; // edx
  Vector *v18; // eax
  float x; // xmm4_4
  float *v20; // eax
  winding_t *v21; // ecx
  int v22; // edx
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  int v26; // edi
  Vector *v27; // eax
  float v28; // xmm4_4
  float *v29; // eax
  winding_t *v30; // ecx
  int v31; // edx
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm3_4
  int v35; // edi
  Vector *v36; // eax
  float v37; // xmm4_4
  float *v38; // eax
  winding_t *v39; // ecx
  int v40; // edx
  float v41; // xmm1_4
  float v42; // xmm2_4
  float v43; // xmm3_4
  int v44; // esi
  Vector *v45; // eax
  float v46; // xmm0_4
  float *v47; // eax

  v8 = 0;
  if ( in->numpoints > 0 )
  {
    v9 = 0;
    do
    {
      p = in->p;
      v11 = offset->x + p[v9].x;
      p_x = &p[v9].x;
      *p_x = v11;
      p_x[1] = offset->y + p_x[1];
      ++v8;
      p_x[2] = offset->z + p_x[2];
      ++v9;
    }
    while ( v8 < in->numpoints );
  }
  ClassifyWindingEpsilon(
    in,
    normal,
    dist: (float)((float)((float)(normal->y * offset->y) + (float)(normal->x * offset->x)) + (float)(normal->z * offset->z))
  + dist,
    epsilon,
    front,
    back,
    on);
  v13 = 0;
  v14 = -offset->x;
  v15 = -offset->y;
  v16 = -offset->z;
  if ( in->numpoints > 0 )
  {
    v17 = 0;
    do
    {
      v18 = in->p;
      x = v18[v17].x;
      v20 = &v18[v17].x;
      *v20 = x + v14;
      v20[1] = v20[1] + v15;
      ++v13;
      v20[2] = v20[2] + v16;
      ++v17;
    }
    while ( v13 < in->numpoints );
  }
  if ( front != nullptr )
  {
    v21 = *front;
    if ( *front != nullptr )
    {
      v22 = 0;
      v23 = -offset->x;
      v24 = -offset->y;
      v25 = -offset->z;
      if ( v21->numpoints > 0 )
      {
        v26 = 0;
        do
        {
          v27 = v21->p;
          v28 = v27[v26].x;
          v29 = &v27[v26].x;
          *v29 = v28 + v23;
          v29[1] = v29[1] + v24;
          ++v22;
          v29[2] = v29[2] + v25;
          ++v26;
        }
        while ( v22 < v21->numpoints );
      }
    }
  }
  if ( back != nullptr )
  {
    v30 = *back;
    if ( *back != nullptr )
    {
      v31 = 0;
      v32 = -offset->x;
      v33 = -offset->y;
      v34 = -offset->z;
      if ( v30->numpoints > 0 )
      {
        v35 = 0;
        do
        {
          v36 = v30->p;
          v37 = v36[v35].x;
          v38 = &v36[v35].x;
          *v38 = v37 + v32;
          v38[1] = v38[1] + v33;
          ++v31;
          v38[2] = v38[2] + v34;
          ++v35;
        }
        while ( v31 < v30->numpoints );
      }
    }
  }
  if ( on != nullptr )
  {
    v39 = *on;
    if ( *on != nullptr )
    {
      v40 = 0;
      v41 = -offset->x;
      v42 = -offset->y;
      v43 = -offset->z;
      if ( v39->numpoints > 0 )
      {
        v44 = 0;
        do
        {
          v45 = v39->p;
          v46 = v45[v44].x;
          v47 = &v45[v44].x;
          *v47 = v46 + v41;
          v47[1] = v42 + v47[1];
          ++v40;
          v47[2] = v43 + v47[2];
          ++v44;
        }
        while ( v40 < v39->numpoints );
      }
    }
  }
}

} // namespace vmap

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x10049580
// Name: struct winding_t __near * AllocWinding(int)
// Source: json
//------------------------------------------------------------------------------
winding_t *__cdecl AllocWinding(unsigned int points)
{
  int v1; // eax
  winding_t *v2; // esi

  if ( numthreads == 1 )
  {
    ++c_winding_allocs;
    c_winding_points += points;
    v1 = c_active_windings + 1;
    c_active_windings = v1;
    if ( v1 > c_peak_windings )
      c_peak_windings = v1;
  }
  ThreadLock();
  v2 = winding_pool[points];
  if ( v2 != nullptr )
  {
    winding_pool[points] = v2->next;
  }
  else
  {
    v2 = (winding_t *)MemAlloc_Alloc(nSize: 0x10u);
    v2->p = (Vector *)calloc(count: points, size: 0xCu);
  }
  ThreadUnlock();
  v2->maxpoints = points;
  v2->numpoints = 0;
  v2->next = nullptr;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10049610
// Name: void FreeWinding(struct winding_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FreeWinding(winding_t *w)
{
  int maxpoints; // eax

  if ( w->numpoints == -559030611 )
    _Error(a1: "FreeWinding: freed a freed winding");
  ThreadLock();
  maxpoints = w->maxpoints;
  w->numpoints = -559030611;
  w->next = winding_pool[maxpoints];
  winding_pool[maxpoints] = w;
  ThreadUnlock();
}

//------------------------------------------------------------------------------
// Address: 0x10049660
// Name: void RemoveColinearPoints(struct winding_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemoveColinearPoints(winding_t *w)
{
  int eax1; // eax
  int v3; // esi
  int numpoints; // edi
  Vector *v5; // ecx
  float *p_x; // eax
  float *v7; // eax
  Vector *v8; // eax
  double x; // st7
  unsigned __int8 *v10; // ecx
  Vector p[64]; // [esp+4h] [ebp-324h] BYREF
  int v12; // [esp+304h] [ebp-24h]
  Vector v2; // [esp+308h] [ebp-20h] BYREF
  Vector v1; // [esp+314h] [ebp-14h] BYREF
  int i; // [esp+320h] [ebp-8h]
  int nump; // [esp+324h] [ebp-4h]
  float *wa; // [esp+330h] [ebp+8h]

  eax1 = 0;
  nump = 0;
  i = 0;
  if ( w->numpoints > 0 )
  {
    v3 = 0;
    wa = &p[0].z;
    do
    {
      numpoints = w->numpoints;
      v12 = i + 1;
      v5 = w->p;
      p_x = &v5[(i + 1) % numpoints].x;
      v1.x = *p_x - v5[v3].x;
      v1.y = p_x[1] - v5[v3].y;
      v1.z = p_x[2] - v5[v3].z;
      v7 = &v5[(numpoints + i - 1) % numpoints].x;
      v2.x = v5[v3].x - *v7;
      v2.y = v5[v3].y - v7[1];
      v2.z = v5[v3].z - v7[2];
      VectorNormalize(vec: &v1);
      VectorNormalize(vec: &v2);
      if ( (float)((float)((float)(v2.y * v1.y) + (float)(v2.x * v1.x)) + (float)(v2.z * v1.z)) < 0.999 )
      {
        v8 = w->p;
        x = v8[v3].x;
        ++nump;
        *(wa - 2) = x;
        *(wa - 1) = v8[v3].y;
        wa += 3;
        *(wa - 3) = v8[v3].z;
      }
      ++v3;
      i = v12;
    }
    while ( v12 < w->numpoints );
    eax1 = nump;
  }
  if ( eax1 != w->numpoints )
  {
    if ( numthreads == 1 )
      c_removed += w->numpoints - eax1;
    v10 = (unsigned __int8 *)w->p;
    w->numpoints = eax1;
    memcpy(dst: v10, src: (unsigned __int8 *)p, count: 12 * eax1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100497E0
// Name: float WindingArea(struct winding_t __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl WindingArea(winding_t *w)
{
  Vector *p; // ecx
  float *p_z; // eax
  int v3; // edx
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm5_4
  float v9; // xmm6_4
  float v11; // [esp-4h] [ebp-10h]

  v11 = 0.0;
  if ( w->numpoints > 2 )
  {
    p = w->p;
    p_z = &p[1].z;
    v3 = w->numpoints - 2;
    do
    {
      v4 = p_z[2] - p->y;
      v5 = *p_z - p->z;
      v6 = p_z[1] - p->x;
      v7 = p_z[3] - p->z;
      v8 = *(p_z - 2) - p->x;
      v9 = *(p_z - 1) - p->y;
      p_z += 3;
      --v3;
      v11 = fsqrt(
              (float)((float)((float)((float)(v5 * v6) - (float)(v7 * v8)) * (float)((float)(v5 * v6) - (float)(v7 * v8)))
                    + (float)((float)((float)(v4 * v8) - (float)(v6 * v9)) * (float)((float)(v4 * v8) - (float)(v6 * v9))))
            + (float)((float)((float)(v7 * v9) - (float)(v4 * v5)) * (float)((float)(v7 * v9) - (float)(v4 * v5))))
          + v11;
    }
    while ( v3 != 0 );
  }
  return v11 * 0.5;
}

//------------------------------------------------------------------------------
// Address: 0x100498D0
// Name: void WindingBounds(struct winding_t __near *,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WindingBounds(winding_t *w, Vector *mins, Vector *maxs)
{
  int v3; // edi
  int v4; // edx
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4

  mins->z = 99999.0;
  mins->y = 99999.0;
  mins->x = 99999.0;
  v3 = 0;
  maxs->z = -99999.0;
  maxs->y = -99999.0;
  maxs->x = -99999.0;
  if ( w->numpoints > 0 )
  {
    v4 = 0;
    do
    {
      x = w->p[v4].x;
      if ( mins->x > x )
        mins->x = x;
      if ( x > maxs->x )
        maxs->x = x;
      y = w->p[v4].y;
      if ( mins->y > y )
        mins->y = y;
      if ( y > maxs->y )
        maxs->y = y;
      z = w->p[v4].z;
      if ( mins->z > z )
        mins->z = z;
      if ( z > maxs->z )
        maxs->z = z;
      ++v3;
      ++v4;
    }
    while ( v3 < w->numpoints );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049990
// Name: void WindingCenter(struct winding_t __near *,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WindingCenter(winding_t *w, Vector *center)
{
  int v2; // edi
  float y; // xmm0_4
  float z; // xmm1_4
  int v5; // esi
  Vector *p; // ecx
  float v7; // xmm0_4

  *center = vec3_origin;
  v2 = 0;
  if ( w->numpoints > 0 )
  {
    y = center->y;
    z = center->z;
    v5 = 0;
    do
    {
      p = w->p;
      center->x = p[v5].x + center->x;
      y = y + p[v5].y;
      center->y = y;
      z = z + p[v5].z;
      ++v2;
      center->z = z;
      ++v5;
    }
    while ( v2 < w->numpoints );
  }
  v7 = 1.0 / (double)w->numpoints;
  center->x = center->x * v7;
  center->y = center->y * v7;
  center->z = center->z * v7;
}

//------------------------------------------------------------------------------
// Address: 0x10049A50
// Name: float WindingAreaAndBalancePoint(struct winding_t __near *,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl WindingAreaAndBalancePoint(winding_t *w, Vector *center)
{
  int v3; // edi
  int v4; // edx
  Vector *p; // eax
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm5_4
  float v9; // xmm6_4
  float v10; // xmm4_4
  float *p_x; // eax
  float v12; // xmm1_4
  float v13; // xmm2_4
  Vector *v14; // eax
  float v15; // xmm4_4
  float v16; // xmm3_4
  float v17; // xmm1_4
  Vector *v18; // eax
  float v19; // xmm2_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // [esp-20h] [ebp-2Ch]
  float z; // [esp-Ch] [ebp-18h]
  float y; // [esp-8h] [ebp-14h]
  float v25; // [esp-4h] [ebp-10h]

  *center = vec3_origin;
  if ( w == nullptr )
    return 0.0;
  v3 = 2;
  v25 = 0.0;
  if ( w->numpoints > 2 )
  {
    y = center->y;
    z = center->z;
    v4 = 2;
    do
    {
      p = w->p;
      v6 = p[v4].y - p->y;
      v7 = p[v4 - 1].z - p->z;
      v8 = p[v4 - 1].x - p->x;
      v9 = p[v4 - 1].y - p->y;
      v10 = p[v4].z - p->z;
      v22 = fsqrt(
              (float)((float)((float)((float)(v7 * (float)(p[v4].x - p->x)) - (float)(v10 * v8))
                            * (float)((float)(v7 * (float)(p[v4].x - p->x)) - (float)(v10 * v8)))
                    + (float)((float)((float)(v6 * v8) - (float)((float)(p[v4].x - p->x) * v9))
                            * (float)((float)(v6 * v8) - (float)((float)(p[v4].x - p->x) * v9))))
            + (float)((float)((float)(v10 * v9) - (float)(v6 * v7)) * (float)((float)(v10 * v9) - (float)(v6 * v7))));
      p_x = &p[v4 - 1].x;
      center->x = (float)((float)(v22 * 0.33333334) * *p_x) + center->x;
      v12 = (float)(p_x[1] * (float)(v22 * 0.33333334)) + y;
      center->y = v12;
      v13 = (float)(p_x[2] * (float)(v22 * 0.33333334)) + z;
      center->z = v13;
      v14 = w->p;
      v15 = v22 + v25;
      center->x = (float)(v14[v4].x * (float)(v22 * 0.33333334)) + center->x;
      v16 = (float)(v14[v4].y * (float)(v22 * 0.33333334)) + v12;
      center->y = v16;
      v17 = (float)(v14[v4].z * (float)(v22 * 0.33333334)) + v13;
      center->z = v17;
      v18 = w->p;
      center->x = (float)(v18->x * (float)(v22 * 0.33333334)) + center->x;
      v19 = (float)(v18->y * (float)(v22 * 0.33333334)) + v16;
      center->y = v19;
      v20 = (float)((float)(v22 * 0.33333334) * v18->z) + v17;
      ++v3;
      center->z = v20;
      ++v4;
      v25 = v22 + v25;
      y = v19;
      z = v20;
    }
    while ( v3 < w->numpoints );
    if ( v15 != 0.0 )
    {
      v21 = 1.0 / v15;
      center->x = center->x * v21;
      center->y = v19 * v21;
      center->z = v20 * v21;
    }
  }
  return v25 * 0.5;
}

//------------------------------------------------------------------------------
// Address: 0x10049CA0
// Name: struct winding_t __near * BaseWindingForPlane(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
winding_t *__cdecl BaseWindingForPlane(const Vector *normal, float dist)
{
  float v2; // xmm1_4
  int v3; // edi
  float v4; // xmm0_4
  float v5; // xmm0_4
  float x; // xmm5_4
  float z; // xmm4_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm3_4
  float v11; // xmm4_4
  float y; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  winding_t *result; // eax
  Vector *p; // ecx
  Vector *v18; // ecx
  Vector *v19; // ecx
  Vector *v20; // ecx
  Vector *v21; // ecx
  Vector *v22; // ecx
  Vector *v23; // ecx
  Vector *v24; // ecx
  float org; // [esp+0h] [ebp-24h]
  float org_4; // [esp+4h] [ebp-20h]
  Vector vup; // [esp+18h] [ebp-Ch] BYREF

  v2 = -1.0;
  v3 = -1;
  v4 = fabs(normal->x);
  if ( v4 > -1.0 )
  {
    v3 = 0;
    v2 = v4;
  }
  v5 = fabs(normal->y);
  if ( v5 > v2 )
  {
    v3 = 1;
    v2 = v5;
  }
  if ( fabs(normal->z) <= v2 )
  {
    if ( v3 == -1 )
      _Error(a1: "BaseWindingForPlane: no axis found");
  }
  else
  {
    v3 = 2;
  }
  x = vec3_origin.x;
  z = vec3_origin.z;
  if ( v3 >= 0 )
  {
    if ( v3 <= 1 )
      z = 1.0;
    else
      x = 1.0;
  }
  LODWORD(v8) = COERCE_UNSIGNED_INT((float)((float)(normal->y * vec3_origin.y) + (float)(normal->x * x)) + (float)(normal->z * z))
              ^ _mask__NegFloat_;
  v9 = (float)(normal->y * v8) + vec3_origin.y;
  v10 = (float)(normal->z * v8) + z;
  vup.x = (float)(normal->x * v8) + x;
  vup.y = v9;
  vup.z = v10;
  VectorNormalize(vec: &vup);
  v11 = normal->z;
  org = normal->x * dist;
  y = normal->y;
  org_4 = y * dist;
  v13 = (float)(v11 * vup.y) - (float)(y * vup.z);
  v14 = (float)(y * vup.x) - (float)(normal->x * vup.y);
  v15 = (float)((float)(normal->x * vup.z) - (float)(v11 * vup.x)) * 65536.0;
  vup.x = vup.x * 65536.0;
  vup.y = vup.y * 65536.0;
  vup.z = vup.z * 65536.0;
  result = AllocWinding(points: 4u);
  p = result->p;
  p->x = org - (float)(v13 * 65536.0);
  p->y = org_4 - v15;
  p->z = (float)(v11 * dist) - (float)(v14 * 65536.0);
  v18 = result->p;
  v18->x = v18->x + vup.x;
  v18->y = v18->y + vup.y;
  v18->z = v18->z + vup.z;
  v19 = result->p;
  v19[1].x = org + (float)(v13 * 65536.0);
  v19[1].y = v15 + org_4;
  v19[1].z = (float)(v14 * 65536.0) + (float)(v11 * dist);
  v20 = result->p;
  v20[1].x = v20[1].x + vup.x;
  v20[1].y = v20[1].y + vup.y;
  v20[1].z = v20[1].z + vup.z;
  v21 = result->p;
  v21[2].x = org + (float)(v13 * 65536.0);
  v21[2].y = v15 + org_4;
  v21[2].z = (float)(v14 * 65536.0) + (float)(v11 * dist);
  v22 = result->p;
  v22[2].x = v22[2].x - vup.x;
  v22[2].y = v22[2].y - vup.y;
  v22[2].z = v22[2].z - vup.z;
  v23 = result->p;
  v23[3].x = org - (float)(v13 * 65536.0);
  v23[3].y = org_4 - v15;
  v23[3].z = (float)(v11 * dist) - (float)(v14 * 65536.0);
  v24 = result->p;
  v24[3].x = v24[3].x - vup.x;
  v24[3].y = v24[3].y - vup.y;
  v24[3].z = v24[3].z - vup.z;
  result->numpoints = 4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10049FB0
// Name: struct winding_t __near * CopyWinding(struct winding_t __near *)
// Source: json
//------------------------------------------------------------------------------
winding_t *__cdecl CopyWinding(winding_t *w)
{
  winding_t *v1; // edi

  v1 = AllocWinding(points: w->numpoints);
  v1->numpoints = w->numpoints;
  memcpy(dst: (unsigned __int8 *)v1->p, src: (unsigned __int8 *)w->p, count: 12 * w->numpoints);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10049FF0
// Name: void ClipWindingEpsilon(struct winding_t __near *,class Vector const __near &,float,float,struct winding_t __near * __near *,struct winding_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClipWindingEpsilon(
        winding_t *in,
        Vector *normal,
        float dist,
        float epsilon,
        winding_t **front,
        winding_t **back)
{
  float *v6; // esi
  float *v7; // edi
  float *v8; // eax
  float v9; // [esp+8h] [ebp-280h]
  Vector *v10; // [esp+18h] [ebp-270h]
  Vector *v11; // [esp+1Ch] [ebp-26Ch]
  Vector *v12; // [esp+20h] [ebp-268h]
  Vector *v13; // [esp+24h] [ebp-264h]
  Vector *p1; // [esp+2Ch] [ebp-25Ch]
  Vector *p2; // [esp+30h] [ebp-258h]
  int j; // [esp+34h] [ebp-254h]
  float dists[68]; // [esp+38h] [ebp-250h]
  winding_t *b; // [esp+148h] [ebp-140h]
  int counts[3]; // [esp+14Ch] [ebp-13Ch] BYREF
  int sides[69]; // [esp+158h] [ebp-130h]
  winding_t *f; // [esp+26Ch] [ebp-1Ch]
  int i; // [esp+270h] [ebp-18h]
  int maxpts; // [esp+274h] [ebp-14h]
  float dot; // [esp+278h] [ebp-10h]
  Vector mid; // [esp+27Ch] [ebp-Ch] BYREF

  mid = vec3_origin;
  memset(counts, 0, sizeof(counts));
  for ( i = 0; i < in->numpoints; ++i )
  {
    dot = (float)((float)((float)(in->p[i].x * normal->x) + (float)(in->p[i].y * normal->y))
                + (float)(in->p[i].z * normal->z))
        - dist;
    dists[i] = dot;
    if ( dot <= epsilon )
    {
      if ( COERCE_FLOAT(LODWORD(epsilon) ^ _mask__NegFloat_) <= dot )
        sides[i] = 2;
      else
        sides[i] = 1;
    }
    else
    {
      sides[i] = 0;
    }
    ++counts[sides[i]];
  }
  sides[i] = sides[0];
  dists[i] = dists[0];
  *back = nullptr;
  *front = nullptr;
  if ( counts[0] != 0 )
  {
    if ( counts[1] != 0 )
    {
      maxpts = in->numpoints + 4;
      f = AllocWinding(points: maxpts);
      *front = f;
      b = AllocWinding(points: maxpts);
      *back = b;
      for ( i = 0; i < in->numpoints; ++i )
      {
        p1 = &in->p[i];
        if ( sides[i] == 2 )
        {
          v13 = &f->p[f->numpoints];
          v13->x = p1->x;
          v13->y = p1->y;
          v13->z = p1->z;
          ++f->numpoints;
          v12 = &b->p[b->numpoints];
          v12->x = p1->x;
          v12->y = p1->y;
          v12->z = p1->z;
          ++b->numpoints;
        }
        else
        {
          if ( sides[i] == 0 )
          {
            v11 = &f->p[f->numpoints];
            v11->x = p1->x;
            v11->y = p1->y;
            v11->z = p1->z;
            ++f->numpoints;
          }
          if ( sides[i] == 1 )
          {
            v10 = &b->p[b->numpoints];
            v10->x = p1->x;
            v10->y = p1->y;
            v10->z = p1->z;
            ++b->numpoints;
          }
          if ( sides[i + 1] != 2 && sides[i + 1] != sides[i] )
          {
            p2 = &in->p[(i + 1) % in->numpoints];
            dot = dists[i] / (float)(dists[i] - dists[i + 1]);
            for ( j = 0; j < 3; ++j )
            {
              if ( Vector::operator[](this: normal, i: j) == 1.0 )
              {
                *Vector::operator[](this: &mid, i: j) = dist;
              }
              else if ( Vector::operator[](this: normal, i: j) == -1.0 )
              {
                *(_DWORD *)Vector::operator[](this: &mid, i: j) = LODWORD(dist) ^ _mask__NegFloat_;
              }
              else
              {
                v6 = Vector::operator[](this: p1, i: j);
                v7 = Vector::operator[](this: p2, i: j);
                v8 = Vector::operator[](this: p1, i: j);
                v9 = (float)((float)(*v7 - *v8) * dot) + *v6;
                *Vector::operator[](this: &mid, i: j) = v9;
              }
            }
            f->p[f->numpoints++] = mid;
            b->p[b->numpoints++] = mid;
          }
        }
      }
      if ( f->numpoints > maxpts || b->numpoints > maxpts )
        _Error(a1: "ClipWinding: points exceeded estimate");
      if ( f->numpoints > 64 || b->numpoints > 64 )
        _Error(a1: "ClipWinding: MAX_POINTS_ON_WINDING");
    }
    else
    {
      *front = CopyWinding(w: in);
    }
  }
  else
  {
    *back = CopyWinding(w: in);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A660
// Name: void ChopWindingInPlace(struct winding_t __near * __near *,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ChopWindingInPlace(winding_t **inout, const Vector *normal, float dist, float epsilon)
{
  winding_t *v4; // esi
  winding_t *v5; // ebx
  int numpoints; // edi
  int v7; // eax
  float y; // xmm2_4
  float x; // xmm3_4
  float z; // xmm4_4
  float *p_x; // edx
  float v12; // xmm0_4
  float v13; // xmm0_4
  winding_t *v14; // eax
  int v15; // edi
  int v16; // eax
  float *v17; // ecx
  float *v18; // eax
  Vector *p; // edx
  int v20; // eax
  Vector *v21; // eax
  int v22; // eax
  int v23; // edx
  float v24; // xmm1_4
  int v25; // eax
  const Vector *v26; // edx
  int v27; // ecx
  int v28; // edi
  int maxpoints; // eax
  float dists[68]; // [esp+0h] [ebp-24Ch]
  int sides[68]; // [esp+110h] [ebp-13Ch]
  int counts[3]; // [esp+220h] [ebp-2Ch] BYREF
  int v33; // [esp+22Ch] [ebp-20h]
  Vector mid; // [esp+230h] [ebp-1Ch] BYREF
  int maxpts; // [esp+23Ch] [ebp-10h]
  int i; // [esp+240h] [ebp-Ch]
  int v37; // [esp+244h] [ebp-8h]
  unsigned int v38; // [esp+248h] [ebp-4h]

  v4 = *inout;
  v5 = nullptr;
  numpoints = (*inout)->numpoints;
  mid = vec3_origin;
  v7 = 0;
  memset(counts, 0, sizeof(counts));
  if ( numpoints > 0 )
  {
    y = normal->y;
    x = normal->x;
    z = normal->z;
    p_x = &v4->p->x;
    do
    {
      v12 = (float)((float)((float)(p_x[1] * y) + (float)(x * *p_x)) + (float)(p_x[2] * z)) - dist;
      dists[v7] = v12;
      if ( v12 <= epsilon )
      {
        if ( (float)-epsilon <= v12 )
          sides[v7] = 2;
        else
          sides[v7] = 1;
      }
      else
      {
        sides[v7] = 0;
      }
      ++counts[sides[v7++]];
      p_x += 3;
    }
    while ( v7 < numpoints );
    v5 = nullptr;
  }
  v13 = dists[0];
  sides[v7] = sides[0];
  dists[v7] = v13;
  if ( counts[0] != 0 )
  {
    if ( counts[1] == 0 )
      return;
    maxpts = numpoints + 4;
    v14 = AllocWinding(points: numpoints + 4);
    v15 = 0;
    v5 = v14;
    i = 0;
    if ( v4->numpoints <= 0 )
    {
LABEL_32:
      if ( v5->numpoints > maxpts )
        _Error(a1: "ClipWinding: points exceeded estimate");
      if ( v5->numpoints > 64 )
        _Error(a1: "ClipWinding: MAX_POINTS_ON_WINDING");
      if ( v4->numpoints != -559030611 )
        goto LABEL_38;
      goto LABEL_37;
    }
    v38 = 0;
    while ( 1 )
    {
      v16 = sides[v15];
      v17 = &v4->p[v38 / 0xC].x;
      if ( v16 == 2 )
      {
        v18 = &v5->p[v5->numpoints].x;
        *v18 = *v17;
        v18[1] = v17[1];
        v18[2] = v17[2];
      }
      else
      {
        if ( v16 == 0 )
        {
          p = v5->p;
          v20 = v5->numpoints;
          p[v20].x = *v17;
          v21 = &p[v20];
          v21->y = v17[1];
          v21->z = v17[2];
          ++v5->numpoints;
        }
        v22 = sides[v15 + 1];
        if ( v22 == 2 || v22 == sides[v15] )
          goto LABEL_31;
        v23 = (v15 + 1) % v4->numpoints;
        v24 = dists[v15] / (float)(dists[v15] - dists[v15 + 1]);
        v37 = 3;
        v25 = (int)&v4->p[v23];
        v26 = normal;
        v33 = v25 - (_DWORD)normal;
        v27 = (char *)v17 - (char *)normal;
        v28 = (char *)&mid - (char *)normal;
        do
        {
          if ( v26->x == 1.0 )
          {
            *(float *)((char *)&v26->x + v28) = dist;
          }
          else if ( v26->x == -1.0 )
          {
            *(float *)((char *)&v26->x + v28) = -dist;
          }
          else
          {
            *(float *)((char *)&v26->x + v28) = (float)((float)(*(float *)((char *)&v26->x + v33)
                                                              - *(float *)((char *)&v26->x + v27))
                                                      * v24)
                                              + *(float *)((char *)&v26->x + v27);
          }
          v26 = (const Vector *)((char *)v26 + 4);
          --v37;
        }
        while ( v37 != 0 );
        v15 = i;
        v5->p[v5->numpoints] = mid;
      }
      ++v5->numpoints;
LABEL_31:
      v38 += 12;
      i = ++v15;
      if ( v15 >= v4->numpoints )
        goto LABEL_32;
    }
  }
  if ( numpoints == -559030611 )
LABEL_37:
    _Error(a1: "FreeWinding: freed a freed winding");
LABEL_38:
  ThreadLock();
  maxpoints = v4->maxpoints;
  v4->numpoints = -559030611;
  v4->next = winding_pool[maxpoints];
  winding_pool[maxpoints] = v4;
  ThreadUnlock();
  *inout = v5;
}

//------------------------------------------------------------------------------
// Address: 0x1004A980
// Name: bool PointInWinding(class Vector const __near &,struct winding_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl PointInWinding(const Vector *pt, winding_t *pWinding)
{
  Vector *p; // eax
  float v4; // xmm3_4
  float v5; // xmm1_4
  float v6; // xmm5_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  int numpoints; // ebx
  int v11; // eax
  int i; // esi
  Vector *v13; // ecx
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm4_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm5_4
  Vector testCross; // [esp+4h] [ebp-1Ch] BYREF
  Vector cross; // [esp+10h] [ebp-10h] BYREF
  int v22; // [esp+1Ch] [ebp-4h]

  if ( pWinding == nullptr )
    return 0;
  p = pWinding->p;
  v4 = p[1].y - p->y;
  v5 = p[1].z - p->z;
  v6 = p[1].x - p->x;
  v7 = pt->x - p->x;
  v8 = pt->y - p->y;
  v9 = pt->z - p->z;
  testCross.x = (float)(v4 * v9) - (float)(v5 * v8);
  testCross.y = (float)(v5 * v7) - (float)(v9 * v6);
  testCross.z = (float)(v8 * v6) - (float)(v4 * v7);
  VectorNormalize(vec: &testCross);
  numpoints = pWinding->numpoints;
  v11 = 1;
  if ( pWinding->numpoints <= 1 )
    return 1;
  for ( i = 1; ; ++i )
  {
    v22 = v11 + 1;
    v13 = pWinding->p;
    v14 = pt->y - v13[i].y;
    v15 = pt->z - v13[i].z;
    v16 = pt->x - v13[i].x;
    v17 = v13[(v11 + 1) % numpoints].z - v13[i].z;
    v18 = v13[(v11 + 1) % numpoints].y - v13[i].y;
    v19 = v13[(v11 + 1) % numpoints].x - v13[i].x;
    cross.x = (float)(v18 * v15) - (float)(v17 * v14);
    cross.y = (float)(v17 * v16) - (float)(v15 * v19);
    cross.z = (float)(v14 * v19) - (float)(v18 * v16);
    VectorNormalize(vec: &cross);
    if ( (float)((float)((float)(cross.y * testCross.y) + (float)(cross.x * testCross.x))
               + (float)(cross.z * testCross.z)) < 0.0 )
      break;
    v11 = v22;
    numpoints = pWinding->numpoints;
    if ( v22 >= pWinding->numpoints )
      return 1;
  }
  return 0;
}

} // namespace vrad_dll
