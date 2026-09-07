// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vbsp/map.cpp
// Functions: 78
// ============================================================

#include "utils\vbsp\map.h"

//------------------------------------------------------------------------------
// Address: 0x00418620
// Name: public: static bool CInstancingHelper::ResolveInstancePath(class IFileSystem __near *,char const __near *,char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CInstancingHelper::ResolveInstancePath(
        IFileSystem *pFileSystem,
        const char *pBaseFilename,
        const char *pInstanceFilename,
        const char *pInstanceDirectory,
        char *pResolvedInstanceFilename,
        int nBufferSize)
{
  IBaseFileSystem *v6; // edi
  int v8; // eax
  char *v9; // ecx
  char instanceDirectoryRelativeFilename[260]; // [esp+Ch] [ebp-20Ch] BYREF
  char fixedInstanceFilename[260]; // [esp+110h] [ebp-108h] BYREF
  char *pMapPathPosition; // [esp+214h] [ebp-4h]

  V_strncpy(pDest: fixedInstanceFilename, pSrc: pInstanceFilename, maxLen: 260);
  V_SetExtension(path: fixedInstanceFilename, extension: ".vmf", pathStringLength: 260);
  V_FixSlashes(pname: fixedInstanceFilename, separator: 92);
  V_FixDoubleSlashes(pStr: fixedInstanceFilename);
  V_strncpy(pDest: pResolvedInstanceFilename, pSrc: pBaseFilename, maxLen: nBufferSize);
  V_StripFilename(path: pResolvedInstanceFilename);
  V_strncat(pDest: pResolvedInstanceFilename, pSrc: "\\", destBufferSize: nBufferSize, max_chars_to_copy: -1);
  V_strncat(
    pDest: pResolvedInstanceFilename,
    pSrc: fixedInstanceFilename,
    destBufferSize: nBufferSize,
    max_chars_to_copy: -1);
  V_RemoveDotSlashes(pFilename: pResolvedInstanceFilename, separator: 92);
  V_FixDoubleSlashes(pStr: pResolvedInstanceFilename);
  V_FixSlashes(pname: pResolvedInstanceFilename, separator: 92);
  v6 = &pFileSystem->IBaseFileSystem;
  if ( pFileSystem->FileExists(this: &pFileSystem->IBaseFileSystem, a2: pResolvedInstanceFilename, a3: nullptr) )
    return 1;
  pMapPathPosition = V_stristr(pStr: pResolvedInstanceFilename, pSearch: "\\maps\\");
  if ( pMapPathPosition != nullptr )
  {
    v8 = _V_strlen(str: "\\maps\\");
    v9 = &pMapPathPosition[v8];
  }
  else
  {
    if ( V_strnicmp(s1: pResolvedInstanceFilename, s2: "maps\\", n: 5) != 0 )
      goto LABEL_9;
    v9 = pResolvedInstanceFilename + 5;
  }
  if ( v9 != nullptr )
  {
    *v9 = 0;
    V_strncat(
      pDest: pResolvedInstanceFilename,
      pSrc: fixedInstanceFilename,
      destBufferSize: nBufferSize,
      max_chars_to_copy: -1);
    if ( v6->FileExists(this: v6, a2: pResolvedInstanceFilename, a3: nullptr) )
      return 1;
  }
LABEL_9:
  if ( *pInstanceDirectory != 0 )
  {
    V_snprintf(
      pDest: instanceDirectoryRelativeFilename,
      maxLen: nBufferSize,
      pFormat: "%s/%s",
      pInstanceDirectory,
      fixedInstanceFilename);
    V_SetExtension(path: instanceDirectoryRelativeFilename, extension: ".vmf", pathStringLength: 260);
    V_FixSlashes(pname: instanceDirectoryRelativeFilename, separator: 92);
    V_RemoveDotSlashes(pFilename: instanceDirectoryRelativeFilename, separator: 92);
    V_FixDoubleSlashes(pStr: instanceDirectoryRelativeFilename);
    pFileSystem->RelativePathToFullPath(
      this: pFileSystem,
      a2: instanceDirectoryRelativeFilename,
      a3: "GAME",
      a4: pResolvedInstanceFilename,
      a5: nBufferSize,
      a6: FILTER_NONE,
      a7: nullptr);
    if ( v6->FileExists(this: v6, a2: instanceDirectoryRelativeFilename, a3: "GAME") )
      return 1;
  }
  pFileSystem->RelativePathToFullPath(
    this: pFileSystem,
    a2: fixedInstanceFilename,
    a3: "GAME",
    a4: pResolvedInstanceFilename,
    a5: nBufferSize,
    a6: FILTER_NONE,
    a7: nullptr);
  if ( v6->FileExists(this: v6, a2: fixedInstanceFilename, a3: "GAME") )
    return 1;
  if ( nBufferSize > 0 )
    *pResolvedInstanceFilename = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00418840
// Name: int PlaneTypeForNormal(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl PlaneTypeForNormal(Vector *normal)
{
  float x; // xmm2_4
  float y; // xmm1_4
  float z; // xmm0_4
  float v4; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm0_4

  x = normal->x;
  if ( normal->x == 1.0 || x == -1.0 )
    return 0;
  y = normal->y;
  if ( y == 1.0 || y == -1.0 )
    return 1;
  z = normal->z;
  if ( z == 1.0 || z == -1.0 )
    return 2;
  v4 = fabs(x);
  v5 = fabs(y);
  v6 = fabs(z);
  if ( v4 >= v5 && v4 >= v6 )
    return 3;
  if ( v5 < v4 || v5 < v6 )
    return 5;
  return 4;
}

//------------------------------------------------------------------------------
// Address: 0x004188F0
// Name: bool SnapVector(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SnapVector(Vector *normal)
{
  int v1; // ecx

  v1 = 0;
  while ( 1 )
  {
    if ( fabs(*(&normal->x + v1) - 1.0) < 0.00001 )
    {
      *(_QWORD *)&normal->y = 0;
      normal->x = 0.0;
      *((_DWORD *)&normal->x + v1) = 1065353216;
      return 1;
    }
    if ( fabs(*(&normal->x + v1) - -1.0) < 0.00001 )
      break;
    if ( ++v1 >= 3 )
      return 0;
  }
  *(_QWORD *)&normal->y = 0;
  normal->x = 0.0;
  *((_DWORD *)&normal->x + v1) = -1082130432;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00418990
// Name: void SnapPlane(class Vector __near &,float __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SnapPlane(Vector *normal, float *dist, const Vector *p0, const Vector *p1, const Vector *p2)
{
  int v5; // edx
  __m128 v6; // xmm3
  __m128 v7; // xmm0
  __m128 v8; // xmm4
  __m128 v9; // xmm2
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm4
  float v14; // xmm3_4
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  float v17; // xmm1_4

  v6.m128_i32[0] = 1258291200;
  if ( SnapVector(normal) != 0 )
  {
    v7 = (__m128)*(unsigned int *)(v5 + 4);
    v7.m128_f32[0] = (float)((float)(v7.m128_f32[0] * (float)((float)(p2->y + (float)(p0->y + p1->y)) * 0.33333334))
                           + (float)(*(float *)v5 * (float)((float)(p2->x + (float)(p0->x + p1->x)) * 0.33333334)))
                   + (float)(*(float *)(v5 + 8) * (float)((float)(p2->z + (float)(p0->z + p1->z)) * 0.33333334));
    *dist = v7.m128_f32[0];
    if ( g_snapAxialPlanes )
    {
      v7.m128_f32[0] = v7.m128_f32[0] + 0.5;
      v8 = _mm_and_ps((__m128)0x80000000, v7);
      v9.m128_i32[0] = 1258291200;
      v9.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v7, v8), v9).m128_f32[0]) & 0x4B000000
                     | v8.m128_i32[0];
      v10 = v7;
      v10.m128_f32[0] = (float)(v7.m128_f32[0] + v9.m128_f32[0]) - v9.m128_f32[0];
      v11 = v10;
      v11.m128_f32[0] = v10.m128_f32[0] - v7.m128_f32[0];
      *dist = v10.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v11, v8).m128_u32[0] & 0x3F800000);
    }
  }
  v12 = (__m128)*(unsigned int *)dist;
  v12.m128_f32[0] = v12.m128_f32[0] + 0.5;
  v13 = _mm_and_ps((__m128)0x80000000, v12);
  LODWORD(v14) = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v12, v13), v6).m128_f32[0]) & 0x4B000000 | v13.m128_i32[0];
  v15 = v12;
  v15.m128_f32[0] = (float)(v12.m128_f32[0] + v14) - v14;
  v16 = v15;
  v16.m128_f32[0] = v15.m128_f32[0] - v12.m128_f32[0];
  v17 = v15.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v16, v13).m128_u32[0] & 0x3F800000);
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(*dist - v17) & _mask__AbsFloat_) < 0.0099999998 )
    *dist = v17;
}

//------------------------------------------------------------------------------
// Address: 0x00418B00
// Name: int BrushContents(struct mapbrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl BrushContents(mapbrush_t *b)
{
  side_t *original_sides; // edx
  int numsides; // esi
  unsigned int result; // eax
  unsigned int v4; // ecx
  int *p_contents; // edx
  int v6; // esi

  original_sides = b->original_sides;
  numsides = b->numsides;
  result = original_sides->contents;
  v4 = result;
  if ( numsides > 1 )
  {
    p_contents = &original_sides[1].contents;
    v6 = numsides - 1;
    do
    {
      v4 |= *p_contents;
      p_contents += 23;
      --v6;
    }
    while ( v6 != 0 );
  }
  if ( (v4 & 0x3A) != 0 )
    result = v4 & 0x3A | result & 0xEFFFFFFE | 0x10000000;
  if ( (v4 & 0x20000000) != 0 )
    result |= 0x20000000u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00418B50
// Name: bool IsAreaPortal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsAreaPortal(const char *pClassName)
{
  const char *v1; // eax
  char v2; // cl

  v1 = "func_areaportal";
  do
  {
    v2 = v1[pClassName - "func_areaportal"];
    if ( v2 == 0 )
      break;
    if ( *v1 != v2 )
      break;
    ++v1;
  }
  while ( *v1 != 0 );
  return *v1 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00418B80
// Name: public: struct brush_texture_t __near & brush_texture_t::operator=(struct brush_texture_t const __near &)
// Source: json
//------------------------------------------------------------------------------
brush_texture_t *__thiscall brush_texture_t::operator=(brush_texture_t *this, const brush_texture_t *__that)
{
  brush_texture_t *result; // eax
  char *name; // esi
  int v4; // edx

  result = this;
  this->UAxis = __that->UAxis;
  name = this->name;
  v4 = 128;
  this->VAxis = __that->VAxis;
  *(_QWORD *)this->shift = *(_QWORD *)__that->shift;
  this->rotate = __that->rotate;
  *(_QWORD *)this->textureWorldUnitsPerTexel = *(_QWORD *)__that->textureWorldUnitsPerTexel;
  this->lightmapWorldUnitsPerLuxel = __that->lightmapWorldUnitsPerLuxel;
  do
  {
    *name = name[(char *)__that - (char *)this];
    ++name;
    --v4;
  }
  while ( v4 != 0 );
  this->flags = __that->flags;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00418C00
// Name: void SetBrushSideThickness(struct side_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetBrushSideThickness(side_t *side)
{
  winding_t *winding; // ecx
  float *p_x; // ebx
  int numpoints; // edi
  int v4; // esi
  float *v5; // ecx
  bool v6; // dl
  bool v7; // zf
  bool v8; // dl
  bool v9; // dl
  float *v10; // ecx
  bool v11; // dl
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm4_4

  winding = side->winding;
  p_x = &winding->p->x;
  numpoints = winding->numpoints;
  v4 = 1;
  side->thin = false;
  if ( numpoints > 1 )
  {
    if ( numpoints - 1 < 4 )
    {
LABEL_9:
      if ( v4 < numpoints )
      {
        v10 = &p_x[3 * v4 - 1];
        do
        {
          if ( side->thin )
            break;
          v11 = (float)((float)((float)((float)((float)(v10[1] - *(v10 - 2)) * (float)(v10[1] - *(v10 - 2)))
                                      + (float)((float)(v10[2] - *(v10 - 1)) * (float)(v10[2] - *(v10 - 1))))
                              + (float)((float)(v10[3] - *v10) * (float)(v10[3] - *v10)))
                      - 256.0) < 0.001;
          ++v4;
          v10 += 3;
          side->thin = v11;
        }
        while ( v4 < numpoints );
      }
    }
    else
    {
      v5 = p_x + 7;
      while ( !side->thin )
      {
        v6 = (float)((float)((float)((float)((float)(*(v5 - 4) - *(v5 - 7)) * (float)(*(v5 - 4) - *(v5 - 7)))
                                   + (float)((float)(*(v5 - 3) - *(v5 - 6)) * (float)(*(v5 - 3) - *(v5 - 6))))
                           + (float)((float)(*(v5 - 2) - *(v5 - 5)) * (float)(*(v5 - 2) - *(v5 - 5))))
                   - 256.0) < 0.001;
        v7 = !v6 && !side->thin;
        side->thin |= v6;
        if ( !v7 )
          break;
        v8 = (float)((float)((float)((float)((float)(*(v5 - 1) - *(v5 - 4)) * (float)(*(v5 - 1) - *(v5 - 4)))
                                   + (float)((float)(*v5 - *(v5 - 3)) * (float)(*v5 - *(v5 - 3))))
                           + (float)((float)(v5[1] - *(v5 - 2)) * (float)(v5[1] - *(v5 - 2))))
                   - 256.0) < 0.001;
        v7 = !v8 && !side->thin;
        side->thin |= v8;
        if ( !v7 )
          break;
        v9 = (float)((float)((float)((float)((float)(v5[2] - *(v5 - 1)) * (float)(v5[2] - *(v5 - 1)))
                                   + (float)((float)(v5[3] - *v5) * (float)(v5[3] - *v5)))
                           + (float)((float)(v5[4] - v5[1]) * (float)(v5[4] - v5[1])))
                   - 256.0) < 0.001;
        v7 = !v9 && !side->thin;
        side->thin |= v9;
        if ( !v7 )
          break;
        side->thin |= (float)((float)((float)((float)((float)(v5[5] - v5[2]) * (float)(v5[5] - v5[2]))
                                            + (float)((float)(v5[6] - v5[3]) * (float)(v5[6] - v5[3])))
                                    + (float)((float)(v5[7] - v5[4]) * (float)(v5[7] - v5[4])))
                            - 256.0) < 0.001;
        v4 += 4;
        v5 += 12;
        if ( v4 >= numpoints - 3 )
          goto LABEL_9;
      }
    }
  }
  v12 = *p_x - p_x[3 * numpoints - 3];
  v13 = p_x[1] - p_x[3 * numpoints - 2];
  v14 = p_x[2] - p_x[3 * numpoints - 1];
  if ( (float)((float)((float)((float)(v12 * v12) + (float)(v13 * v13)) + (float)(v14 * v14)) - 256.0) >= 0.001 )
    side->thin = side->thin;
  else
    side->thin |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x00418E60
// Name: public: int CMapFile::MakeBrushWindings(struct mapbrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapFile::MakeBrushWindings(CMapFile *this, winding_t *ob)
{
  mapbrush_t *v2; // edi
  mapbrush_t *v3; // eax
  int v4; // esi
  int v5; // ebx
  side_t *original_sides; // ecx
  side_t *v7; // ecx
  mapbrush_t *v8; // eax
  int v9; // esi
  int v10; // ebx
  float *p_x; // esi
  side_t *side; // [esp+14h] [ebp-10h]
  int j; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]
  int v17; // [esp+20h] [ebp-4h]

  v2 = (mapbrush_t *)ob;
  ClearBounds(mins: (Vector *)&ob[1], maxs: (Vector *)&ob[1].next);
  i = 0;
  if ( v2->numsides > 0 )
  {
    v17 = 0;
    do
    {
      v3 = (mapbrush_t *)BaseWindingForPlane(
                           normal: &this->mapplanes[v2->original_sides[v17].planenum].normal,
                           dist: this->mapplanes[v2->original_sides[v17].planenum].dist);
      v4 = 0;
      ob = (winding_t *)v3;
      if ( v2->numsides > 0 )
      {
        v5 = 0;
        do
        {
          if ( v3 == nullptr )
            break;
          if ( i != v4 )
          {
            original_sides = v2->original_sides;
            if ( !original_sides[v5].bevel )
            {
              ChopWindingInPlace(
                inout: &ob,
                normal: &this->mapplanes[original_sides[v5].planenum ^ 1].normal,
                dist: this->mapplanes[original_sides[v5].planenum ^ 1].dist,
                epsilon: 0.0099999998);
              v3 = (mapbrush_t *)ob;
            }
          }
          ++v4;
          ++v5;
        }
        while ( v4 < v2->numsides );
      }
      v7 = &v2->original_sides[v17];
      v7->winding = (winding_t *)v3;
      side = v7;
      if ( ob != nullptr )
      {
        v7->visible = true;
        v8 = (mapbrush_t *)ob;
        v9 = 0;
        if ( ob->numpoints > 0 )
        {
          v10 = 0;
          do
          {
            AddPointToBounds(v: (const Vector *)(v10 + v8->brushnum), mins: &v2->mins, maxs: &v2->maxs);
            v8 = (mapbrush_t *)ob;
            ++v9;
            v10 += 12;
          }
          while ( v9 < ob->numpoints );
          v7 = side;
        }
        SetBrushSideThickness(side: v7);
      }
      ++v17;
      ++i;
    }
    while ( i < v2->numsides );
  }
  p_x = &v2->maxs.x;
  for ( j = 3; j != 0; --j )
  {
    if ( *(p_x - 3) < -16384.0 || *p_x > 16384.0 )
      _Msg(a1: "Brush %i: bounds out of range\n", v2->id);
    if ( *(p_x - 3) > 16384.0 || *p_x < -16384.0 )
      _Msg(a1: "Brush %i: no visible sides on brush\n", v2->id);
    ++p_x;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00419000
// Name: public: void CMapFile::MoveBrushesToWorld(struct entity_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFile::MoveBrushesToWorld(CMapFile *this, entity_t *mapent)
{
  int numbrushes; // edi
  int v4; // ecx
  int v5; // ecx
  _DWORD *v6; // eax
  unsigned __int8 *dst; // [esp+Ch] [ebp-8h]
  unsigned __int8 *temp; // [esp+10h] [ebp-4h]

  numbrushes = mapent->numbrushes;
  temp = (unsigned __int8 *)MemAlloc_Alloc(nSize: 48 * numbrushes);
  memcpy(dst: temp, src: (unsigned __int8 *)&this->mapbrushes[mapent->firstbrush], count: 48 * numbrushes);
  v4 = *(_DWORD *)((char *)&unk_12E1038 + (_DWORD)this);
  dst = (unsigned __int8 *)&this->mapbrushes[v4];
  memmove(
    dst: (unsigned __int8 *)&this->mapbrushes[v4 + numbrushes],
    src: dst,
    count: 48 * (this->nummapbrushes - v4 - numbrushes));
  memcpy(dst, src: temp, count: 48 * numbrushes);
  *(_DWORD *)((char *)&unk_12E1038 + (_DWORD)this) += numbrushes;
  v5 = 1;
  if ( *(int *)((char *)&unk_12E1024 + (_DWORD)this) > 1 )
  {
    v6 = (_DWORD *)((char *)&unk_12E1060 + (_DWORD)this);
    do
    {
      *v6 += numbrushes;
      ++v5;
      v6 += 11;
    }
    while ( v5 < *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)this) );
  }
  free(pMem: temp);
  mapent->numbrushes = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004190D0
// Name: public: void CMapFile::MoveBrushesToWorldGeneral(struct entity_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFile::MoveBrushesToWorldGeneral(CMapFile *this, entity_t *mapent)
{
  int v2; // edi
  int v4; // eax
  _DWORD *v5; // ecx
  unsigned __int8 *v6; // eax
  int firstbrush; // ebx
  int v8; // eax
  int v9; // eax
  int *v10; // ecx
  unsigned __int8 *dst; // [esp+Ch] [ebp-Ch]
  int newbrushes; // [esp+10h] [ebp-8h]
  unsigned __int8 *temp; // [esp+14h] [ebp-4h]

  v2 = nummapdispinfo;
  if ( nummapdispinfo > 0 )
  {
    v4 = ((char *)mapent - (char *)this - (int)&unk_12E1028) / 44;
    v5 = &unk_5468A0;
    do
    {
      if ( *v5 == v4 )
        *v5 = 0;
      v5 += 8417;
      --v2;
    }
    while ( v2 != 0 );
  }
  newbrushes = mapent->numbrushes;
  v6 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 48 * newbrushes);
  firstbrush = mapent->firstbrush;
  temp = v6;
  memcpy(dst: v6, src: (unsigned __int8 *)&this->mapbrushes[firstbrush], count: 48 * newbrushes);
  v8 = *(_DWORD *)((char *)&unk_12E1038 + (_DWORD)this);
  dst = (unsigned __int8 *)&this->mapbrushes[v8];
  memmove(dst: (unsigned __int8 *)&this->mapbrushes[newbrushes + v8], src: dst, count: 48 * (firstbrush - v8));
  memcpy(dst, src: temp, count: 48 * newbrushes);
  *(_DWORD *)((char *)&unk_12E1038 + (_DWORD)this) += newbrushes;
  v9 = 1;
  if ( *(int *)((char *)&unk_12E1024 + (_DWORD)this) > 1 )
  {
    v10 = (int *)((char *)&unk_12E1060 + (_DWORD)this);
    do
    {
      if ( *v10 < mapent->firstbrush )
        *v10 += newbrushes;
      ++v9;
      v10 += 11;
    }
    while ( v9 < *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)this) );
  }
  free(pMem: temp);
  mapent->numbrushes = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004191E0
// Name: public: void CMapFile::RemoveContentsDetailFromEntity(struct entity_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFile::RemoveContentsDetailFromEntity(CMapFile *this, entity_t *mapent)
{
  int i; // ebx
  mapbrush_t *v3; // edx
  int v4; // edi
  int *p_contents; // esi

  for ( i = 0; i < mapent->numbrushes; ++i )
  {
    v3 = &this->mapbrushes[i + mapent->firstbrush];
    v4 = 0;
    if ( this->mapbrushes[i + mapent->firstbrush].numsides > 0 )
    {
      p_contents = &this->mapbrushes[i + mapent->firstbrush].original_sides->contents;
      do
      {
        if ( ((unsigned int)&g_WaterOverlays[7253].aFaces[48] & *p_contents) != 0 )
          *p_contents &= ~0x8000000u;
        ++v4;
        p_contents += 23;
      }
      while ( v4 < v3->numsides );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419240
// Name: enum ChunkFileResult_t LoadDispDistancesKeyCallback(char const __near *,char const __near *,struct mapdispinfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadDispDistancesKeyCallback(
        const char *szKey,
        const char *szValue,
        mapdispinfo_t *pMapDispInfo)
{
  int v3; // esi
  int v4; // edi
  const char *v5; // eax
  int v6; // edi
  float *v7; // esi
  char szBuf[1024]; // [esp+4h] [ebp-400h] BYREF

  if ( V_strncasecmp(s1: szKey, s2: "row", n: 3) != 0 )
    return ChunkFile_Ok;
  strcpy(szBuf, szValue);
  v3 = (1 << pMapDispInfo->power) + 1;
  v4 = atoi(nptr: szKey + 3);
  v5 = strtok(string: szBuf, control: " ");
  v6 = v3 * v4;
  if ( v5 != nullptr )
  {
    v7 = &pMapDispInfo->dispDists[v6];
    do
    {
      *v7 = atof(nptr: v5);
      v5 = strtok(string: nullptr, control: " ");
      ++v7;
    }
    while ( v5 != nullptr );
  }
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x004192F0
// Name: enum ChunkFileResult_t LoadDispInfoKeyCallback(char const __near *,char const __near *,struct mapdispinfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadDispInfoKeyCallback(const char *szKey, const char *szValue, mapdispinfo_t *pMapDispInfo)
{
  int nFlags; // [esp+4h] [ebp-4h] BYREF

  if ( _V_stricmp(s1: szKey, s2: "power") != 0 )
  {
    if ( _V_stricmp(s1: szKey, s2: "uaxis") != 0 )
    {
      if ( _V_stricmp(s1: szKey, s2: "vaxis") != 0 )
      {
        if ( _V_stricmp(s1: szKey, s2: "startposition") != 0 )
        {
          if ( _V_stricmp(s1: szKey, s2: "flags") != 0 )
          {
            if ( _V_stricmp(s1: szKey, s2: "mintess") != 0 )
            {
              if ( _V_stricmp(s1: szKey, s2: "smooth") == 0 )
                CChunkFile::ReadKeyValueFloat(pszValue: szValue, flFloat: &pMapDispInfo->smoothingAngle);
              return ChunkFile_Ok;
            }
            else
            {
              CChunkFile::ReadKeyValueInt(pszValue: szValue, nInt: &pMapDispInfo->minTess);
              return ChunkFile_Ok;
            }
          }
          else
          {
            CChunkFile::ReadKeyValueInt(pszValue: szValue, nInt: &nFlags);
            pMapDispInfo->flags |= nFlags;
            return ChunkFile_Ok;
          }
        }
        else
        {
          CChunkFile::ReadKeyValueVector3(pszValue: szValue, vec: &pMapDispInfo->startPosition);
          return ChunkFile_Ok;
        }
      }
      else
      {
        CChunkFile::ReadKeyValueVector3(pszValue: szValue, vec: &pMapDispInfo->vAxis);
        return ChunkFile_Ok;
      }
    }
    else
    {
      CChunkFile::ReadKeyValueVector3(pszValue: szValue, vec: &pMapDispInfo->uAxis);
      return ChunkFile_Ok;
    }
  }
  else
  {
    CChunkFile::ReadKeyValueInt(pszValue: szValue, nInt: &pMapDispInfo->power);
    return ChunkFile_Ok;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419450
// Name: enum ChunkFileResult_t LoadDispNormalsKeyCallback(char const __near *,char const __near *,struct mapdispinfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadDispNormalsKeyCallback(
        const char *szKey,
        const char *szValue,
        mapdispinfo_t *pMapDispInfo)
{
  int v3; // edi
  int v4; // ebx
  const char *v5; // esi
  int v6; // ebx
  float *p_y; // edi
  char *v8; // ebx
  char szBuf[1024]; // [esp+4h] [ebp-408h] BYREF
  char *pszNext1; // [esp+404h] [ebp-8h]
  char *pszNext2; // [esp+408h] [ebp-4h]

  if ( V_strncasecmp(s1: szKey, s2: "row", n: 3) != 0 )
    return ChunkFile_Ok;
  strcpy(szBuf, szValue);
  v3 = (1 << pMapDispInfo->power) + 1;
  v4 = atoi(nptr: szKey + 3);
  v5 = strtok(string: szBuf, control: " ");
  pszNext1 = strtok(string: nullptr, control: " ");
  v6 = v3 * v4;
  pszNext2 = strtok(string: nullptr, control: " ");
  if ( v5 != nullptr )
  {
    p_y = &pMapDispInfo->vectorDisps[v6].y;
    do
    {
      v8 = pszNext1;
      if ( pszNext1 == nullptr )
        break;
      if ( pszNext2 == nullptr )
        break;
      *(p_y - 1) = atof(nptr: v5);
      *p_y = atof(nptr: v8);
      p_y[1] = atof(nptr: pszNext2);
      v5 = strtok(string: nullptr, control: " ");
      pszNext1 = strtok(string: nullptr, control: " ");
      p_y += 3;
      pszNext2 = strtok(string: nullptr, control: " ");
    }
    while ( v5 != nullptr );
  }
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x00419560
// Name: enum ChunkFileResult_t LoadDispOffsetsKeyCallback(char const __near *,char const __near *,struct mapdispinfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadDispOffsetsKeyCallback(
        const char *szKey,
        const char *szValue,
        mapdispinfo_t *pMapDispInfo)
{
  int v3; // edi
  int v4; // ebx
  const char *v5; // esi
  int v6; // ebx
  float *p_y; // edi
  char *v8; // ebx
  char szBuf[1024]; // [esp+4h] [ebp-408h] BYREF
  char *pszNext1; // [esp+404h] [ebp-8h]
  char *pszNext2; // [esp+408h] [ebp-4h]

  if ( V_strncasecmp(s1: szKey, s2: "row", n: 3) != 0 )
    return ChunkFile_Ok;
  strcpy(szBuf, szValue);
  v3 = (1 << pMapDispInfo->power) + 1;
  v4 = atoi(nptr: szKey + 3);
  v5 = strtok(string: szBuf, control: " ");
  pszNext1 = strtok(string: nullptr, control: " ");
  v6 = v3 * v4;
  pszNext2 = strtok(string: nullptr, control: " ");
  if ( v5 != nullptr )
  {
    p_y = &pMapDispInfo->vectorOffsets[v6].y;
    do
    {
      v8 = pszNext1;
      if ( pszNext1 == nullptr )
        break;
      if ( pszNext2 == nullptr )
        break;
      *(p_y - 1) = atof(nptr: v5);
      *p_y = atof(nptr: v8);
      p_y[1] = atof(nptr: pszNext2);
      v5 = strtok(string: nullptr, control: " ");
      pszNext1 = strtok(string: nullptr, control: " ");
      p_y += 3;
      pszNext2 = strtok(string: nullptr, control: " ");
    }
    while ( v5 != nullptr );
  }
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x00419670
// Name: enum ChunkFileResult_t LoadDispAlphasKeyCallback(char const __near *,char const __near *,struct mapdispinfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadDispAlphasKeyCallback(
        const char *szKey,
        const char *szValue,
        mapdispinfo_t *pMapDispInfo)
{
  int v3; // esi
  int v4; // edi
  const char *v5; // eax
  int v6; // edi
  float *v7; // esi
  char szBuf[1024]; // [esp+4h] [ebp-400h] BYREF

  if ( V_strncasecmp(s1: szKey, s2: "row", n: 3) != 0 )
    return ChunkFile_Ok;
  strcpy(szBuf, szValue);
  v3 = (1 << pMapDispInfo->power) + 1;
  v4 = atoi(nptr: szKey + 3);
  v5 = strtok(string: szBuf, control: " ");
  v6 = v3 * v4;
  if ( v5 != nullptr )
  {
    v7 = &pMapDispInfo->alphaValues[v6];
    do
    {
      *v7 = atof(nptr: v5);
      v5 = strtok(string: nullptr, control: " ");
      ++v7;
    }
    while ( v5 != nullptr );
  }
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x00419720
// Name: enum ChunkFileResult_t LoadDispTriangleTagsKeyCallback(char const __near *,char const __near *,struct mapdispinfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadDispTriangleTagsKeyCallback(
        const char *szKey,
        const char *szValue,
        mapdispinfo_t *pMapDispInfo)
{
  int v3; // edi
  int v4; // esi
  const char *v5; // eax
  int v6; // esi
  unsigned __int16 *v7; // esi
  char v8; // al
  char v9; // cl
  bool v10; // dl
  __int16 v11; // ax
  char szBuf[1024]; // [esp+4h] [ebp-400h] BYREF

  if ( V_strncasecmp(s1: szKey, s2: "row", n: 3) != 0 )
    return ChunkFile_Ok;
  strcpy(szBuf, szValue);
  v3 = 1 << pMapDispInfo->power;
  v4 = atoi(nptr: szKey + 3);
  v5 = strtok(string: szBuf, control: " ");
  v6 = 2 * v3 * v4;
  if ( v5 != nullptr )
  {
    v7 = &pMapDispInfo->triTags[v6];
    do
    {
      v8 = atoi(nptr: v5);
      v9 = v8 & 1;
      if ( (v8 & 2) != 0 )
        v9 = (v8 & 4) != 0;
      v10 = (v8 & 8) != 0;
      if ( (v8 & 0x10) != 0 )
        v10 = (v8 & 0x20) != 0;
      v11 = 0;
      if ( v9 != 0 )
        v11 = 2;
      if ( v10 )
        v11 |= 4u;
      *v7 = v11;
      v5 = strtok(string: nullptr, control: " ");
      ++v7;
    }
    while ( v5 != nullptr );
  }
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x00419810
// Name: enum ChunkFileResult_t LoadDispMultiBlendKeyCallback(char const __near *,char const __near *,struct mapdispinfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadDispMultiBlendKeyCallback(
        const char *szKey,
        const char *szValue,
        mapdispinfo_t *pMapDispInfo)
{
  int v3; // esi
  int v4; // edi
  const char *v5; // eax
  int v6; // edi
  float *p_z; // esi
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  char szBuf[1024]; // [esp+4h] [ebp-410h] BYREF
  Vector4D vMultiBlend; // [esp+404h] [ebp-10h]

  if ( V_strncasecmp(s1: szKey, s2: "row", n: 3) != 0 )
    return ChunkFile_Ok;
  strcpy(szBuf, szValue);
  v3 = (1 << pMapDispInfo->power) + 1;
  v4 = atoi(nptr: szKey + 3);
  v5 = strtok(string: szBuf, control: " ");
  v6 = v3 * v4;
  if ( v5 != nullptr )
  {
    p_z = &pMapDispInfo->m_vMultiBlends[v6].m_vMultiBlend.z;
    do
    {
      vMultiBlend.x = atof(nptr: v5);
      v8 = strtok(string: nullptr, control: " ");
      vMultiBlend.y = atof(nptr: v8);
      v9 = strtok(string: nullptr, control: " ");
      vMultiBlend.z = atof(nptr: v9);
      v10 = strtok(string: nullptr, control: " ");
      vMultiBlend.w = atof(nptr: v10);
      v5 = strtok(string: nullptr, control: " ");
      *(p_z - 2) = vMultiBlend.x;
      p_z += 20;
      *(p_z - 21) = vMultiBlend.y;
      *(p_z - 20) = vMultiBlend.z;
      *(p_z - 19) = vMultiBlend.w;
    }
    while ( v5 != nullptr );
  }
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x00419920
// Name: enum ChunkFileResult_t LoadDispAlphaBlendKeyCallback(char const __near *,char const __near *,struct mapdispinfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadDispAlphaBlendKeyCallback(
        const char *szKey,
        const char *szValue,
        mapdispinfo_t *pMapDispInfo)
{
  int v3; // esi
  int v4; // edi
  const char *v5; // eax
  int v6; // edi
  float *p_z; // esi
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  char szBuf[1024]; // [esp+4h] [ebp-410h] BYREF
  Vector4D vAlphaBlend; // [esp+404h] [ebp-10h]

  if ( V_strncasecmp(s1: szKey, s2: "row", n: 3) != 0 )
    return ChunkFile_Ok;
  strcpy(szBuf, szValue);
  v3 = (1 << pMapDispInfo->power) + 1;
  v4 = atoi(nptr: szKey + 3);
  v5 = strtok(string: szBuf, control: " ");
  v6 = v3 * v4;
  if ( v5 != nullptr )
  {
    p_z = &pMapDispInfo->m_vMultiBlends[v6].m_vAlphaBlend.z;
    do
    {
      vAlphaBlend.x = atof(nptr: v5);
      v8 = strtok(string: nullptr, control: " ");
      vAlphaBlend.y = atof(nptr: v8);
      v9 = strtok(string: nullptr, control: " ");
      vAlphaBlend.z = atof(nptr: v9);
      v10 = strtok(string: nullptr, control: " ");
      vAlphaBlend.w = atof(nptr: v10);
      v5 = strtok(string: nullptr, control: " ");
      *(p_z - 2) = vAlphaBlend.x;
      p_z += 20;
      *(p_z - 21) = vAlphaBlend.y;
      *(p_z - 20) = vAlphaBlend.z;
      *(p_z - 19) = vAlphaBlend.w;
    }
    while ( v5 != nullptr );
  }
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x00419A30
// Name: enum ChunkFileResult_t LoadDispMultiBlendColorKeyCallback(char const __near *,char const __near *,struct mapdispinfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadDispMultiBlendColorKeyCallback(
        const char *szKey,
        const char *szValue,
        mapdispinfo_t *pMapDispInfo)
{
  int v3; // esi
  int v4; // edi
  const char *v5; // eax
  int v6; // edi
  int v7; // esi
  const char *v8; // eax
  const char *v9; // eax
  char szBuf[1024]; // [esp+4h] [ebp-40Ch] BYREF
  Vector vMultiBlendColor; // [esp+404h] [ebp-Ch]

  if ( V_strncasecmp(s1: szKey, s2: "row", n: 3) != 0 )
    return ChunkFile_Ok;
  strcpy(szBuf, szValue);
  v3 = (1 << pMapDispInfo->power) + 1;
  v4 = atoi(nptr: szKey + 3);
  v5 = strtok(string: szBuf, control: " ");
  v6 = v3 * v4;
  if ( v5 != nullptr )
  {
    v7 = 80 * v6;
    do
    {
      vMultiBlendColor.x = atof(nptr: v5);
      v8 = strtok(string: nullptr, control: " ");
      vMultiBlendColor.y = atof(nptr: v8);
      v9 = strtok(string: nullptr, control: " ");
      vMultiBlendColor.z = atof(nptr: v9);
      v5 = strtok(string: nullptr, control: " ");
      *(Vector *)((char *)&pMapDispInfo->m_vMultiBlends[0].m_vMultiBlendColors[nMultiBlendColorIndex] + v7) = vMultiBlendColor;
      v7 += 80;
    }
    while ( v5 != nullptr );
  }
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x00419B30
// Name: void ConvertSideList(struct entity_t __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConvertSideList(entity_t *mapent, char *key)
{
  const char *v2; // eax
  const char *v3; // esi
  void *v4; // esp
  char v5; // bl
  const char *v6; // eax
  int nummapbrushsides; // edx
  int v8; // eax
  int *p_id; // ecx
  char *v10; // edi
  char v11; // cl
  unsigned int v12; // eax
  char *v13; // edi
  char v14; // cl
  char v15[11]; // [esp+0h] [ebp-420h] BYREF
  char v16; // [esp+Bh] [ebp-415h] BYREF
  char szNewValue[1024]; // [esp+Ch] [ebp-414h] BYREF
  char szIndex[16]; // [esp+40Ch] [ebp-14h] BYREF
  int nSideID; // [esp+41Ch] [ebp-4h] BYREF

  v2 = ValueForKey(ent: mapent, key);
  v3 = v2;
  if ( v2 != nullptr )
  {
    v4 = alloca(strlen(v2) + 1);
    strcpy(v15, v3);
    v5 = 1;
    szNewValue[0] = 0;
    v6 = strtok(string: v15, control: " ");
    if ( v6 != nullptr )
    {
      do
      {
        if ( sscanf(string: v6, format: "%d", &nSideID) == 1 )
        {
          nummapbrushsides = g_LoadingMap->nummapbrushsides;
          v8 = 0;
          if ( nummapbrushsides > 0 )
          {
            p_id = &g_LoadingMap->brushsides[0].id;
            while ( *p_id != nSideID )
            {
              ++v8;
              p_id += 23;
              if ( v8 >= nummapbrushsides )
                goto LABEL_18;
            }
            if ( v8 != -1 )
            {
              if ( v5 != 0 )
              {
                v5 = 0;
              }
              else
              {
                v10 = &v16;
                do
                  v11 = *++v10;
                while ( v11 != 0 );
                strcpy(v10, " ");
              }
              itoa(val: v8, buf: szIndex, radix: 10);
              v12 = strlen(szIndex) + 1;
              v13 = &v16;
              do
                v14 = *++v13;
              while ( v14 != 0 );
              qmemcpy(v13, szIndex, v12);
            }
          }
        }
LABEL_18:
        v6 = strtok(string: nullptr, control: " ");
      }
      while ( v6 != nullptr );
      SetKeyValue(ent: mapent, key, value: szNewValue, bAllowDuplicates: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419C90
// Name: public: void CMapFile::AddLadderKeys(struct entity_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFile::AddLadderKeys(CMapFile *this, entity_t *mapent)
{
  CMapFile *v3; // edi
  int v4; // ecx
  int v5; // ebx
  _DWORD *v6; // eax
  int v7; // ecx
  float *p_x; // edi
  char buf[128]; // [esp+14h] [ebp-8Ch] BYREF
  CMapFile *v10; // [esp+94h] [ebp-Ch]
  int j; // [esp+98h] [ebp-8h]
  int i; // [esp+9Ch] [ebp-4h]
  entity_t *mapenta; // [esp+A8h] [ebp+8h]

  v3 = this;
  v10 = this;
  SetKeyValue(ent: mapent, key: "team", value: "0", bAllowDuplicates: false);
  SetKeyValue(ent: mapent, key: "normal.x", value: "0", bAllowDuplicates: false);
  SetKeyValue(ent: mapent, key: "normal.y", value: "0", bAllowDuplicates: false);
  SetKeyValue(ent: mapent, key: "normal.z", value: "1", bAllowDuplicates: false);
  v4 = 0;
  for ( i = 0; v4 < mapent->numbrushes; i = v4 )
  {
    v5 = (int)&v3->mapbrushes[v4 + mapent->firstbrush];
    j = 0;
    if ( *(int *)(v5 + 40) > 0 )
    {
      mapenta = nullptr;
      do
      {
        v6 = (_DWORD *)((char *)&mapenta->origin.x + *(_DWORD *)(v5 + 44));
        v7 = v6[5];
        if ( (v7 & 0x20000000) != 0 )
        {
          p_x = &v3->mapplanes[*v6].normal.x;
          if ( (v7 & 0x800) != 0 )
          {
            SetKeyValue(ent: mapent, key: "team", value: "1", bAllowDuplicates: false);
          }
          else if ( (v7 & 0x1000) != 0 )
          {
            SetKeyValue(ent: mapent, key: "team", value: "2", bAllowDuplicates: false);
          }
          V_snprintf(pDest: buf, maxLen: 128, pFormat: "%f", *p_x);
          SetKeyValue(ent: mapent, key: "normal.x", value: buf, bAllowDuplicates: false);
          V_snprintf(pDest: buf, maxLen: 128, pFormat: "%f", p_x[1]);
          SetKeyValue(ent: mapent, key: "normal.y", value: buf, bAllowDuplicates: false);
          V_snprintf(pDest: buf, maxLen: 128, pFormat: "%f", p_x[2]);
          SetKeyValue(ent: mapent, key: "normal.z", value: buf, bAllowDuplicates: false);
          v3 = v10;
        }
        mapenta = (entity_t *)((char *)mapenta + 92);
        ++j;
      }
      while ( j < *(_DWORD *)(v5 + 40) );
      v4 = i;
    }
    ++v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419E50
// Name: public: virtual void CVmfMeshDataSupport_SaveLoadHandler::SetCurrentEntity(class IMapEntity_Type_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVmfMeshDataSupport_SaveLoadHandler::SetCurrentEntity(
        CVmfMeshDataSupport_SaveLoadHandler *this,
        struct IMapEntity_Type_t *pEntity)
{
  this->m_pEntity = pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x00419E60
// Name: public: virtual char const __near * CSyncMesh_SaveLoadHandler::GetCustomSectionName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CSyncMesh_SaveLoadHandler::GetCustomSectionName(CSyncMesh_SaveLoadHandler *this)
{
  return "meshdata";
}

//------------------------------------------------------------------------------
// Address: 0x00419E70
// Name: struct entity_t __near * EntityByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
entity_t *__cdecl EntityByName(const char *pTestName)
{
  CMapFile *v2; // eax
  int v3; // ebx
  int i; // edi
  entity_t *v5; // esi
  const char *v6; // eax

  if ( pTestName == nullptr )
    return nullptr;
  v2 = g_MainMap;
  v3 = 0;
  if ( *(int *)((char *)&unk_12E1024 + (_DWORD)g_MainMap) <= 0 )
    return nullptr;
  for ( i = 0; ; i += 44 )
  {
    v5 = (entity_t *)((char *)&unk_12E1028 + (_DWORD)v2 + i);
    v6 = ValueForKey(ent: v5, key: "targetname");
    if ( _V_stricmp(s1: v6, s2: pTestName) == 0 )
      break;
    v2 = g_MainMap;
    if ( ++v3 >= *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)g_MainMap) )
      return nullptr;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00419EE0
// Name: public: void CMapFile::ForceFuncAreaPortalWindowContents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFile::ForceFuncAreaPortalWindowContents(CMapFile *this)
{
  bool v2; // cc
  entity_t *v3; // ebx
  const char *v4; // eax
  const char *v5; // ecx
  char v6; // dl
  int j; // edi
  const char *v8; // eax
  entity_t *v9; // eax
  int k; // edx
  char *targets[2]; // [esp+4h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-4h]

  v2 = *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)this) <= 0;
  targets[0] = "target";
  targets[1] = "BackgroundBModel";
  i = 0;
  if ( !v2 )
  {
    v3 = (entity_t *)((char *)&unk_12E1028 + (_DWORD)this);
    do
    {
      v4 = ValueForKey(ent: v3, key: "classname");
      v5 = "func_areaportal";
      while ( 1 )
      {
        v6 = v5[v4 - "func_areaportal"];
        if ( v6 == 0 || *v5 != v6 )
          break;
        if ( *++v5 == 0 )
          goto LABEL_9;
      }
      if ( *v5 != 0 )
        goto LABEL_16;
LABEL_9:
      if ( _V_stricmp(s1: v4, s2: "func_areaportal") != 0 )
      {
        for ( j = 0; j < 2; ++j )
        {
          v8 = ValueForKey(ent: v3, key: targets[j]);
          if ( *v8 != 0 )
          {
            v9 = EntityByName(pTestName: v8);
            if ( v9 != nullptr )
            {
              for ( k = 0; k < v9->numbrushes; ++k )
              {
                this->mapbrushes[k + v9->firstbrush].contents &= ~1u;
                this->mapbrushes[k + v9->firstbrush].contents |= 0x10000002u;
              }
            }
          }
        }
      }
LABEL_16:
      ++v3;
      ++i;
    }
    while ( i < *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)this) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00419FF0
// Name: public: static void CMapFile::SetInstancePath(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMapFile::SetInstancePath(const char *pszInstancePath)
{
  strcpy(CMapFile::m_InstancePath, pszInstancePath);
  _V_strlower(start: CMapFile::m_InstancePath);
  V_FixSlashes(pname: CMapFile::m_InstancePath, separator: 92);
}

//------------------------------------------------------------------------------
// Address: 0x0041A030
// Name: public: void CMapFile::PreLoadInstances(class GameData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFile::PreLoadInstances(CMapFile *this, GameData *pGD)
{
  CMapFile *v2; // esi
  bool v3; // cc
  entity_t *v4; // ebx
  const char *v5; // eax
  GDclass *v6; // eax
  GDclass *v7; // edi
  char *m_szName; // esi
  char *v9; // eax
  char temp[2048]; // [esp+0h] [ebp-8A4h] BYREF
  char NameFixup[128]; // [esp+800h] [ebp-A4h] BYREF
  Vector InstanceOrigin; // [esp+880h] [ebp-24h] BYREF
  QAngle InstanceAngle; // [esp+88Ch] [ebp-18h] BYREF
  CMapFile *v14; // [esp+898h] [ebp-Ch]
  int i; // [esp+89Ch] [ebp-8h]
  int iIndex; // [esp+8A0h] [ebp-4h]

  v2 = this;
  InstanceOrigin = vec3_origin;
  v14 = this;
  InstanceAngle = vec3_angle;
  memset(NameFixup, 0, sizeof(NameFixup));
  GameData::BeginInstancing(this: &GD, nPass: 2);
  v3 = *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)v2) <= 0;
  i = 0;
  if ( !v3 )
  {
    v4 = (entity_t *)((char *)&unk_12E1028 + (_DWORD)v2);
    do
    {
      v5 = ValueForKey(ent: v4, key: "classname");
      v6 = GameData::BeginInstanceRemap(
             this: pGD,
             pszClassName: v5,
             pszInstancePrefix: NameFixup,
             Origin: &InstanceOrigin,
             Angle: &InstanceAngle);
      v7 = v6;
      if ( v6 != nullptr )
      {
        v3 = v6->m_nVariables <= 0;
        iIndex = 0;
        if ( !v3 )
        {
          do
          {
            m_szName = GDclass::GetVariableAt(this: v7, iIndex)->m_szName;
            v9 = ValueForKey(ent: v4, key: m_szName);
            if ( GameData::RemapKeyValue(
                   this: pGD,
                   pszKey: m_szName,
                   pszInValue: v9,
                   pszOutValue: temp,
                   NameFixup: NAME_FIXUP_NONE) )
            {
              SetKeyValue(ent: v4, key: m_szName, value: temp, bAllowDuplicates: false);
            }
            ++iIndex;
          }
          while ( iIndex < v7->m_nVariables );
          v2 = v14;
        }
      }
      ++v4;
      ++i;
    }
    while ( i < *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)v2) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A160
// Name: public: void CMapFile::PostLoadInstances(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFile::PostLoadInstances(CMapFile *this)
{
  CMapFile *v1; // edi
  entity_t *v2; // esi
  const char *v3; // edi
  unsigned __int8 v4; // al
  int i; // [esp+8h] [ebp-4h]

  v1 = this;
  i = 0;
  if ( *(int *)((char *)&unk_12E1024 + (_DWORD)this) > 0 )
  {
    v2 = (entity_t *)((char *)&unk_12E1028 + (_DWORD)this);
    do
    {
      if ( strcmp("env_cubemap", ValueForKey(ent: v2, key: "classname")) == 0 )
      {
        v3 = ValueForKey(ent: v2, key: "sides");
        v4 = IntForKey(ent: v2, key: "cubemapsize");
        Cubemap_InsertSample(origin: &v2->origin, size: v4);
        Cubemap_SaveBrushSides(pSideListStr: v3);
        v1 = this;
        v2->epairs = nullptr;
      }
      ++v2;
      ++i;
    }
    while ( i < *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)v1) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A220
// Name: public: void CMapFile::ReplaceInstancePair(struct epair_t __near *,struct entity_t __near *,struct entity_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFile::ReplaceInstancePair(
        CMapFile *this,
        epair_t *pPair,
        entity_t *pInstanceEntity,
        entity_t *pParmsEntity)
{
  char *v4; // eax
  char *v5; // edx
  char v6; // cl
  epair_t *epairs; // esi
  char *v8; // eax
  char *v9; // edx
  char v10; // cl
  _BYTE *v11; // eax
  const char *v12; // eax
  int v13; // ecx
  char v14; // dl
  char Value[1024]; // [esp+8h] [ebp-C00h] BYREF
  char InstanceVariable[1024]; // [esp+408h] [ebp-800h] BYREF
  char NewValue[1024]; // [esp+808h] [ebp-400h] BYREF

  v4 = pPair->value;
  v5 = (char *)(NewValue - v4);
  do
  {
    v6 = *v4;
    v4[(_DWORD)v5] = *v4;
    ++v4;
  }
  while ( v6 != 0 );
  epairs = pInstanceEntity->epairs;
  if ( epairs != nullptr )
  {
    while ( 1 )
    {
      if ( V_strncasecmp(s1: epairs->key, s2: "replace", n: 7) == 0 )
      {
        v8 = epairs->value;
        v9 = (char *)(InstanceVariable - v8);
        do
        {
          v10 = *v8;
          v8[(_DWORD)v9] = *v8;
          ++v8;
        }
        while ( v10 != 0 );
        strchr(string: (unsigned __int8 *)InstanceVariable, chr: 0x20u);
        if ( v11 != nullptr )
        {
          *v11 = 0;
          v12 = v11 + 1;
          v13 = 0;
          do
          {
            v14 = NewValue[v13];
            Value[v13++] = v14;
          }
          while ( v14 != 0 );
          if ( !V_StrSubst(
                  pIn: Value,
                  pMatch: InstanceVariable,
                  pReplaceWith: v12,
                  pOut: NewValue,
                  outLen: 1024,
                  bCaseSensitive: false) )
            break;
        }
      }
      epairs = epairs->next;
      if ( epairs == nullptr )
        goto LABEL_12;
    }
  }
  else
  {
LABEL_12:
    if ( strcmp(pPair->value, NewValue) != 0 )
    {
      free(pMem: pPair->value);
      pPair->value = copystring(s: NewValue);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A350
// Name: enum ChunkFileResult_t LoadSideKeyCallback(char const __near *,char const __near *,struct LoadSide_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadSideKeyCallback(const char *szKey, const char *szValue, LoadSide_t *pSideInfo)
{
  const char *v3; // eax
  int Miptex; // eax
  side_t *v5; // edx
  int v7; // eax
  float v8; // xmm0_4
  side_t *pSide; // esi

  if ( _V_stricmp(s1: szKey, s2: "plane") == 0 )
  {
    if ( sscanf(
           string: szValue,
           format: "(%f %f %f) (%f %f %f) (%f %f %f)",
           pSideInfo->planepts,
           &pSideInfo->planepts[0].y,
           &pSideInfo->planepts[0].z,
           &pSideInfo->planepts[1],
           &pSideInfo->planepts[1].y,
           &pSideInfo->planepts[1].z,
           &pSideInfo->planepts[2],
           &pSideInfo->planepts[2].y,
           &pSideInfo->planepts[2].z) != 9 )
    {
      _Error(
        a1: "Brush %i: %s\nSide %i\nTexture: %s\n",
        g_MapError.m_brushID,
        "parsing plane definition",
        g_MapError.m_sideIndex,
        g_MapError.m_textureName);
      return ChunkFile_Ok;
    }
    return ChunkFile_Ok;
  }
  if ( _V_stricmp(s1: szKey, s2: "material") != 0 )
  {
    if ( _V_stricmp(s1: szKey, s2: "uaxis") != 0 )
    {
      if ( _V_stricmp(s1: szKey, s2: "vaxis") != 0 )
      {
        if ( _V_stricmp(s1: szKey, s2: "lightmapscale") != 0 )
        {
          if ( _V_stricmp(s1: szKey, s2: "contents") == 0 )
          {
            pSide = pSideInfo->pSide;
            pSide->contents |= atoi(nptr: szValue);
            return ChunkFile_Ok;
          }
          if ( _V_stricmp(s1: szKey, s2: "flags") == 0 )
          {
            pSideInfo->td.flags |= atoi(nptr: szValue);
            pSideInfo->pSide->surf = pSideInfo->td.flags;
            return ChunkFile_Ok;
          }
          if ( _V_stricmp(s1: szKey, s2: "id") == 0 )
          {
            pSideInfo->pSide->id = atoi(nptr: szValue);
            return ChunkFile_Ok;
          }
          if ( _V_stricmp(s1: szKey, s2: "smoothing_groups") == 0 )
            pSideInfo->pSide->smoothingGroups = atoi(nptr: szValue);
        }
        else
        {
          v7 = atoi(nptr: szValue);
          pSideInfo->td.lightmapWorldUnitsPerLuxel = (float)v7;
          if ( (float)v7 == 0.0 )
          {
            printf(format: "Brush %i, Side %i: %s\n", g_MapError.m_brushID, g_MapError.m_sideIndex, "luxel size of 0");
            pSideInfo->td.lightmapWorldUnitsPerLuxel = g_defaultLuxelSize;
          }
          v8 = pSideInfo->td.lightmapWorldUnitsPerLuxel * g_luxelScale;
          pSideInfo->td.lightmapWorldUnitsPerLuxel = v8;
          if ( g_minLuxelScale > v8 )
          {
            pSideInfo->td.lightmapWorldUnitsPerLuxel = g_minLuxelScale;
            return ChunkFile_Ok;
          }
        }
      }
      else if ( sscanf(
                  string: szValue,
                  format: "[%f %f %f %f] %f",
                  &pSideInfo->td.VAxis,
                  &pSideInfo->td.VAxis.y,
                  &pSideInfo->td.VAxis.z,
                  &pSideInfo->td.shift[1],
                  &pSideInfo->td.textureWorldUnitsPerTexel[1]) != 5 )
      {
        CMapError::ReportError(this: &g_MapError, pErrorString: "parsing V axis definition");
        return ChunkFile_Ok;
      }
    }
    else if ( sscanf(
                string: szValue,
                format: "[%f %f %f %f] %f",
                &pSideInfo->td,
                &pSideInfo->td.UAxis.y,
                &pSideInfo->td.UAxis.z,
                pSideInfo->td.shift,
                pSideInfo->td.textureWorldUnitsPerTexel) != 5 )
    {
      _Error(
        a1: "Brush %i: %s\nSide %i\nTexture: %s\n",
        g_MapError.m_brushID,
        "parsing U axis definition",
        g_MapError.m_sideIndex,
        g_MapError.m_textureName);
      return ChunkFile_Ok;
    }
    return ChunkFile_Ok;
  }
  v3 = szValue;
  if ( g_ReplaceMaterials )
    v3 = ReplaceMaterialName(name: szValue);
  strcpy(pSideInfo->td.name, v3);
  V_strncpy(pDest: g_MapError.m_textureName, pSrc: v3, maxLen: 80);
  Miptex = FindMiptex(name: pSideInfo->td.name);
  v5 = pSideInfo->pSide;
  pSideInfo->td.flags = textureref[Miptex].flags;
  pSideInfo->td.lightmapWorldUnitsPerLuxel = textureref[Miptex].lightmapWorldUnitsPerLuxel;
  v5->contents = textureref[Miptex].contents;
  pSideInfo->pSide->surf = pSideInfo->td.flags;
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x0041A670
// Name: public: enum ChunkFileResult_t CMapFile::LoadConnectionsKeyCallback(char const __near *,char const __near *,struct LoadEntity_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CMapFile::LoadConnectionsKeyCallback(
        CMapFile *this,
        const char *szKey,
        const char *szValue,
        LoadEntity_t *pLoadEntity)
{
  epair_t *v4; // esi
  char *v5; // eax
  char *key; // edx
  const char *v7; // ecx
  char v8; // al
  char *value; // edx
  const char *v10; // ecx
  char v11; // al
  epair_t **v12; // eax
  epair_t *v13; // ecx
  epair_t *epairs; // ecx
  epair_t *i; // eax

  v4 = (epair_t *)MemAlloc_Alloc(nSize: 0xCu);
  v4->key = (char *)MemAlloc_Alloc(nSize: strlen(szKey) + 1);
  v5 = (char *)MemAlloc_Alloc(nSize: strlen(szValue) + 1);
  key = v4->key;
  v4->value = v5;
  v7 = szKey;
  do
  {
    v8 = *v7;
    *key++ = *v7++;
  }
  while ( v8 != 0 );
  value = v4->value;
  v10 = szValue;
  do
  {
    v11 = *v10;
    *value++ = *v10++;
  }
  while ( v11 != 0 );
  v12 = (epair_t **)MemAlloc_Alloc(nSize: 8u);
  if ( v12 != nullptr )
  {
    v13 = *(epair_t **)((char *)&unk_1391038 + (_DWORD)this);
    *v12 = v4;
    v12[1] = v13;
  }
  else
  {
    v12 = nullptr;
  }
  *(_DWORD *)((char *)&unk_1391038 + (_DWORD)this) = v12;
  v4->next = nullptr;
  epairs = pLoadEntity->pEntity->epairs;
  if ( epairs != nullptr )
  {
    for ( i = epairs->next; i != nullptr; i = i->next )
      epairs = i;
    epairs->next = v4;
    return ChunkFile_Ok;
  }
  else
  {
    pLoadEntity->pEntity->epairs = v4;
    return ChunkFile_Ok;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A750
// Name: enum ChunkFileResult_t LoadSolidKeyCallback(char const __near *,char const __near *,struct mapbrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadSolidKeyCallback(const char *szKey, const char *szValue, mapbrush_t *pLoadBrush)
{
  int v3; // eax

  if ( _V_stricmp(s1: szKey, s2: "id") == 0 )
  {
    v3 = atoi(nptr: szValue);
    pLoadBrush->id = v3;
    g_MapError.m_brushID = v3;
  }
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x0041A790
// Name: public: void CMapFile::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFile::Init(CMapFile *this)
{
  int m_Size; // edx

  entity_num = 0;
  *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)this) = 0;
  this->nummapplanes = 0;
  memset(dst: (unsigned __int8 *)this, value: 0, count: 0x180000u);
  this->nummapbrushes = 0;
  memset(dst: (unsigned __int8 *)this->mapbrushes, value: 0, count: sizeof(this->mapbrushes));
  this->nummapbrushsides = 0;
  memset(dst: (unsigned __int8 *)this->brushsides, value: 0, count: (unsigned int)&unk_5C0000);
  memset(dst: &byte_7A1024[(_DWORD)this], value: 0, count: (unsigned int)&unk_B40000);
  memset(dst: (unsigned __int8 *)this->planehash, value: 0, count: sizeof(this->planehash));
  *(_DWORD *)((char *)&unk_1391038 + (_DWORD)this) = 0;
  *(_DWORD *)((char *)&unk_139103C + (_DWORD)this) = g_aMapOverlays.m_Size;
  m_Size = g_aMapWaterOverlays.m_Size;
  *(_DWORD *)((char *)&unk_1391028 + (_DWORD)this) = 0;
  *(_DWORD *)((char *)&unk_139102C + (_DWORD)this) = 0;
  *(_DWORD *)((char *)&unk_1391030 + (_DWORD)this) = 0;
  *(_DWORD *)((char *)&unk_1391040 + (_DWORD)this) = m_Size;
  *(_DWORD *)((char *)&unk_1391034 + (_DWORD)this) = -1;
}

//------------------------------------------------------------------------------
// Address: 0x0041A850
// Name: enum ChunkFileResult_t LoadDispDistancesCallback(class CChunkFile __near *,struct mapdispinfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadDispDistancesCallback(CChunkFile *pFile, mapdispinfo_t *pMapDispInfo)
{
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))LoadDispDistancesKeyCallback,
           pData: pMapDispInfo);
}

//------------------------------------------------------------------------------
// Address: 0x0041A870
// Name: enum ChunkFileResult_t LoadDispNormalsCallback(class CChunkFile __near *,struct mapdispinfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadDispNormalsCallback(CChunkFile *pFile, mapdispinfo_t *pMapDispInfo)
{
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))LoadDispNormalsKeyCallback,
           pData: pMapDispInfo);
}

//------------------------------------------------------------------------------
// Address: 0x0041A890
// Name: enum ChunkFileResult_t LoadDispOffsetsCallback(class CChunkFile __near *,struct mapdispinfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadDispOffsetsCallback(CChunkFile *pFile, mapdispinfo_t *pMapDispInfo)
{
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))LoadDispOffsetsKeyCallback,
           pData: pMapDispInfo);
}

//------------------------------------------------------------------------------
// Address: 0x0041A8B0
// Name: enum ChunkFileResult_t LoadDispAlphasCallback(class CChunkFile __near *,struct mapdispinfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadDispAlphasCallback(CChunkFile *pFile, mapdispinfo_t *pMapDispInfo)
{
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))LoadDispAlphasKeyCallback,
           pData: pMapDispInfo);
}

//------------------------------------------------------------------------------
// Address: 0x0041A8D0
// Name: enum ChunkFileResult_t LoadDispTriangleTagsCallback(class CChunkFile __near *,struct mapdispinfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadDispTriangleTagsCallback(CChunkFile *pFile, mapdispinfo_t *pMapDispInfo)
{
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))LoadDispTriangleTagsKeyCallback,
           pData: pMapDispInfo);
}

//------------------------------------------------------------------------------
// Address: 0x0041A8F0
// Name: enum ChunkFileResult_t LoadDispMultiBlendCallback(class CChunkFile __near *,struct mapdispinfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadDispMultiBlendCallback(CChunkFile *pFile, mapdispinfo_t *pMapDispInfo)
{
  pMapDispInfo->flags |= 0x40000000u;
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))LoadDispMultiBlendKeyCallback,
           pData: pMapDispInfo);
}

//------------------------------------------------------------------------------
// Address: 0x0041A910
// Name: enum ChunkFileResult_t LoadDispAlphaBlendCallback(class CChunkFile __near *,struct mapdispinfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadDispAlphaBlendCallback(CChunkFile *pFile, mapdispinfo_t *pMapDispInfo)
{
  pMapDispInfo->flags |= 0x40000000u;
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))LoadDispAlphaBlendKeyCallback,
           pData: pMapDispInfo);
}

//------------------------------------------------------------------------------
// Address: 0x0041A930
// Name: enum ChunkFileResult_t LoadDispMultiBlendColorCallback0(class CChunkFile __near *,struct mapdispinfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadDispMultiBlendColorCallback0(CChunkFile *pFile, mapdispinfo_t *pMapDispInfo)
{
  nMultiBlendColorIndex = 0;
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))LoadDispMultiBlendColorKeyCallback,
           pData: pMapDispInfo);
}

//------------------------------------------------------------------------------
// Address: 0x0041A950
// Name: enum ChunkFileResult_t LoadDispMultiBlendColorCallback1(class CChunkFile __near *,struct mapdispinfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadDispMultiBlendColorCallback1(CChunkFile *pFile, mapdispinfo_t *pMapDispInfo)
{
  nMultiBlendColorIndex = 1;
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))LoadDispMultiBlendColorKeyCallback,
           pData: pMapDispInfo);
}

//------------------------------------------------------------------------------
// Address: 0x0041A970
// Name: enum ChunkFileResult_t LoadDispMultiBlendColorCallback2(class CChunkFile __near *,struct mapdispinfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadDispMultiBlendColorCallback2(CChunkFile *pFile, mapdispinfo_t *pMapDispInfo)
{
  nMultiBlendColorIndex = 2;
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))LoadDispMultiBlendColorKeyCallback,
           pData: pMapDispInfo);
}

//------------------------------------------------------------------------------
// Address: 0x0041A990
// Name: enum ChunkFileResult_t LoadDispMultiBlendColorCallback3(class CChunkFile __near *,struct mapdispinfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadDispMultiBlendColorCallback3(CChunkFile *pFile, mapdispinfo_t *pMapDispInfo)
{
  nMultiBlendColorIndex = 3;
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))LoadDispMultiBlendColorKeyCallback,
           pData: pMapDispInfo);
}

//------------------------------------------------------------------------------
// Address: 0x0041A9B0
// Name: public: void CMapFile::MergeBrushes(struct entity_t __near *,class CMapFile __near *,class Vector __near &,class QAngle __near &,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFile::MergeBrushes(
        CMapFile *this,
        entity_t *pInstanceEntity,
        CMapFile *Instance,
        Vector *InstanceOrigin,
        QAngle *InstanceAngle,
        matrix3x4_t *InstanceMatrix)
{
  bool v7; // cc
  int nummapbrushes; // edx
  int *p_id; // ecx
  CMapFile *v10; // edx
  int v11; // ecx
  float *p_z; // esi
  int v13; // eax
  mapbrush_t *v14; // eax
  mapbrush_t *v15; // edi
  __int64 v16; // xmm0_8
  float z; // edx
  __int64 v18; // xmm0_8
  side_t *original_sides; // ecx
  unsigned int v20; // edx
  int v21; // eax
  Vector minsIn; // [esp+4h] [ebp-20h] BYREF
  Vector maxsIn; // [esp+10h] [ebp-14h] BYREF
  int i; // [esp+1Ch] [ebp-8h]
  int max_brush_id; // [esp+20h] [ebp-4h]

  v7 = this->nummapbrushes <= 0;
  max_brush_id = 0;
  if ( !v7 )
  {
    nummapbrushes = this->nummapbrushes;
    p_id = &this->mapbrushes[0].id;
    do
    {
      if ( *p_id > max_brush_id )
        max_brush_id = *p_id;
      p_id += 12;
      --nummapbrushes;
    }
    while ( nummapbrushes != 0 );
  }
  v10 = Instance;
  v11 = 0;
  i = 0;
  if ( Instance->nummapbrushes <= 0 )
  {
    this->nummapbrushes += Instance->nummapbrushes;
  }
  else
  {
    p_z = &Instance->mapbrushes[0].mins.z;
    while ( 1 )
    {
      v13 = v11 + this->nummapbrushes;
      this->mapbrushes[v13].entitynum = *(int *)(p_z - 6);
      this->mapbrushes[v13].brushnum = *(int *)(p_z - 5);
      v14 = &this->mapbrushes[v13];
      v14->id = *(int *)(p_z - 4);
      v14->contents = *(int *)(p_z - 3);
      v14->mins.x = *(p_z - 2);
      v14->mins.y = *(p_z - 1);
      v14->mins.z = *p_z;
      v14->maxs.x = p_z[1];
      v14->maxs.y = p_z[2];
      v14->maxs.z = p_z[3];
      v14->numsides = (int)p_z[4];
      v14->original_sides = (side_t *)p_z[5];
      v15 = &this->mapbrushes[v11 + this->nummapbrushes];
      v15->entitynum += *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)this);
      v15->brushnum += this->nummapbrushes;
      if ( v11 < *(_DWORD *)((char *)&unk_12E1038 + (_DWORD)v10) || (v15->contents & 0x20000000) != 0 )
      {
        v16 = *(_QWORD *)&v15->mins.x;
        z = v15->maxs.z;
        minsIn.z = v15->mins.z;
        *(_QWORD *)&minsIn.x = v16;
        v18 = *(_QWORD *)&v15->maxs.x;
        maxsIn.z = z;
        *(_QWORD *)&maxsIn.x = v18;
        TransformAABB(
          transform: InstanceMatrix,
          vecMinsIn: &minsIn,
          vecMaxsIn: &maxsIn,
          vecMinsOut: &v15->mins,
          vecMaxsOut: &v15->maxs);
        v10 = Instance;
      }
      original_sides = v15->original_sides;
      v15->id += max_brush_id;
      v20 = (int)((unsigned __int64)(2987803337LL * ((char *)original_sides - (char *)v10 - 1970212)) >> 32) >> 6;
      v21 = i + 1;
      v15->original_sides = &this->brushsides[this->nummapbrushsides + v20 + (v20 >> 31)];
      p_z += 12;
      i = v21;
      if ( v21 >= Instance->nummapbrushes )
        break;
      v11 = i;
      v10 = Instance;
    }
    this->nummapbrushes += Instance->nummapbrushes;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041AB60
// Name: public: void CMapFile::MergeEntities(struct entity_t __near *,class CMapFile __near *,class Vector __near &,class QAngle __near &,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFile::MergeEntities(
        CMapFile *this,
        entity_t *pInstanceEntity,
        CMapFile *Instance,
        Vector *InstanceOrigin,
        QAngle *InstanceAngle,
        matrix3x4_t *InstanceMatrix)
{
  entity_t *v6; // edi
  char *v8; // esi
  char *v9; // eax
  int v10; // esi
  entity_t *v11; // edi
  const char *v12; // eax
  int v13; // eax
  CMapFile *v14; // ebx
  int v15; // esi
  entity_t *v16; // edi
  const char *v17; // eax
  entity_t *v18; // esi
  int epairs; // esi
  char *v20; // eax
  char *v21; // edx
  char v22; // cl
  _BYTE *v23; // eax
  int v24; // eax
  const char *v25; // ebx
  epair_t *v26; // edi
  char *v27; // eax
  char *v28; // edx
  char v29; // cl
  _BYTE *v30; // eax
  const char *v31; // esi
  int v32; // esi
  epair_t *v33; // esi
  char *v34; // eax
  char *key; // edx
  char *v36; // ecx
  char v37; // al
  char *v38; // edx
  char *v39; // ecx
  char v40; // al
  bool v41; // cc
  _DWORD *v42; // edi
  CMapFile *v43; // ecx
  int v44; // edx
  int v45; // eax
  _DWORD *v46; // eax
  entity_t *v47; // esi
  const char *v48; // eax
  int v49; // eax
  float z; // edx
  epair_t *i; // ebx
  GDclass *v52; // eax
  char *m_szName; // ebx
  char *v54; // eax
  CMapFile *v55; // edx
  int v56; // esi
  CMapFile *v57; // edi
  entity_t *v58; // ebx
  char *v59; // ebx
  unsigned int v60; // esi
  int v61; // eax
  int v62; // edi
  char *v63; // eax
  char *v64; // edx
  char *v65; // ecx
  char *v66; // esi
  char v67; // dl
  QAngle *v68; // eax
  char *v69; // edx
  char x_low; // cl
  int v71; // eax
  const char *v72; // edi
  int v73; // eax
  int v74; // esi
  unsigned __int8 *v75; // esi
  const char *v76; // eax
  const char *v77; // ebx
  int v78; // edi
  int v79; // eax
  unsigned __int8 v80; // cl
  char *v81; // eax
  int v82; // esi
  unsigned __int8 v83; // cl
  unsigned int v84; // eax
  char *v85; // edi
  char v86; // cl
  char *v87; // eax
  int v88; // eax
  entity_t *v89; // esi
  GameData::TNameFixup v90; // [esp-4h] [ebp-34C0h]
  char pszInValue[4096]; // [esp+Ch] [ebp-34B0h] BYREF
  char v92[1023]; // [esp+100Ch] [ebp-24B0h] BYREF
  char v93; // [esp+140Bh] [ebp-20B1h] BYREF
  char dest[4096]; // [esp+140Ch] [ebp-20B0h] BYREF
  char s1[1024]; // [esp+240Ch] [ebp-10B0h] BYREF
  char value[2048]; // [esp+280Ch] [ebp-CB0h] BYREF
  char s2[1024]; // [esp+300Ch] [ebp-4B0h] BYREF
  char string[128]; // [esp+340Ch] [ebp-B0h] BYREF
  __int64 in1; // [esp+348Ch] [ebp-30h] BYREF
  float v100; // [esp+3494h] [ebp-28h]
  char *pszClassName; // [esp+3498h] [ebp-24h]
  entity_t *mapent; // [esp+349Ch] [ebp-20h]
  GameData::TNameFixup NameFixup; // [esp+34A0h] [ebp-1Ch]
  int v104; // [esp+34A4h] [ebp-18h]
  entity_t *pParmsEntity; // [esp+34A8h] [ebp-14h]
  GDclass *v106; // [esp+34ACh] [ebp-10h]
  CMapFile *v107; // [esp+34B0h] [ebp-Ch]
  int v108; // [esp+34B4h] [ebp-8h]
  int iIndex; // [esp+34B8h] [ebp-4h]
  QAngle *Angle; // [esp+34D0h] [ebp+14h]
  matrix3x4_t *in2; // [esp+34D4h] [ebp+18h]

  v6 = pInstanceEntity;
  v107 = this;
  v104 = 0;
  mapent = nullptr;
  pParmsEntity = nullptr;
  v8 = ValueForKey(ent: pInstanceEntity, key: "targetname");
  v9 = ValueForKey(ent: pInstanceEntity, key: "name");
  if ( *v8 != 0 )
  {
    sprintf(string, format: "%s", v8);
  }
  else if ( *v9 != 0 )
  {
    sprintf(string, format: "%s", v9);
  }
  else
  {
    sprintf(string, format: "InstanceAuto%d", CMapFile::m_InstanceCount);
  }
  v10 = 0;
  if ( *(int *)((char *)&unk_12E1024 + (_DWORD)this) > 0 )
  {
    v11 = (entity_t *)((char *)&unk_12E1028 + (_DWORD)this);
    do
    {
      v12 = ValueForKey(ent: v11, key: "hammerid");
      if ( *v12 != 0 )
      {
        v13 = atoi(nptr: v12);
        if ( v13 > v104 )
          v104 = v13;
      }
      ++v10;
      ++v11;
    }
    while ( v10 < *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)this) );
    v6 = pInstanceEntity;
  }
  v14 = Instance;
  v15 = 0;
  NameFixup = IntForKey(ent: v6, key: "fixup_style");
  if ( *(int *)((char *)&unk_12E1024 + (_DWORD)Instance) > 0 )
  {
    v16 = (entity_t *)((char *)&unk_12E1028 + (_DWORD)Instance);
    while ( 1 )
    {
      v17 = ValueForKey(ent: v16, key: "classname");
      if ( _V_stricmp(s1: v17, s2: "func_instance_parms") == 0 )
        break;
      ++v15;
      ++v16;
      if ( v15 >= *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)Instance) )
        goto LABEL_42;
    }
    v18 = (entity_t *)((char *)&unk_12E1028 + (_DWORD)Instance + 44 * v15);
    pParmsEntity = v18;
    if ( v18 != nullptr )
    {
      epairs = (int)v18->epairs;
      v108 = 1;
      for ( iIndex = epairs; epairs != 0; iIndex = epairs )
      {
        if ( V_strncasecmp(s1: *(const char **)(epairs + 4), s2: "parm", n: 4) != 0 )
          goto LABEL_41;
        v20 = *(char **)(epairs + 8);
        v21 = (char *)(s1 - v20);
        do
        {
          v22 = *v20;
          v20[(_DWORD)v21] = *v20;
          ++v20;
        }
        while ( v22 != 0 );
        strchr(string: (unsigned __int8 *)s1, chr: 0x20u);
        if ( v23 == nullptr )
          goto LABEL_41;
        *v23 = 0;
        strchr(string: v23 + 1, chr: 0x20u);
        if ( v24 == 0 )
          goto LABEL_41;
        v25 = (const char *)(v24 + 1);
        v26 = pInstanceEntity->epairs;
        if ( v26 != nullptr )
        {
          while ( 1 )
          {
            if ( V_strncasecmp(s1: v26->key, s2: "replace", n: 7) == 0 )
            {
              v27 = v26->value;
              v28 = (char *)(s2 - v27);
              do
              {
                v29 = *v27;
                v27[(_DWORD)v28] = *v27;
                ++v27;
              }
              while ( v29 != 0 );
              strchr(string: (unsigned __int8 *)s2, chr: 0x20u);
              if ( v30 != nullptr )
              {
                *v30 = 0;
                v31 = v30 + 1;
                if ( _V_stricmp(s1, s2) == 0 )
                  break;
              }
            }
            v26 = v26->next;
            if ( v26 == nullptr )
              goto LABEL_35;
          }
          if ( _V_stricmp(s1: v31, s2: "???") != 0 )
            goto LABEL_40;
          *v26->key = 0;
          *v26->value = 0;
        }
LABEL_35:
        v32 = v108;
        sprintf(string: s2, format: "%stemp%d", "replace", v108);
        v108 = v32 + 1;
        sprintf(string: v92, format: "%s %s", s1, v25);
        v33 = (epair_t *)MemAlloc_Alloc(nSize: 0xCu);
        v33->key = (char *)MemAlloc_Alloc(nSize: strlen(s2) + 1);
        v34 = (char *)MemAlloc_Alloc(nSize: strlen(v92) + 1);
        key = v33->key;
        v33->value = v34;
        v36 = s2;
        do
        {
          v37 = *v36;
          *key++ = *v36++;
        }
        while ( v37 != 0 );
        v38 = v33->value;
        v39 = v92;
        do
        {
          v40 = *v39;
          *v38++ = *v39++;
        }
        while ( v40 != 0 );
        v33->next = pInstanceEntity->epairs;
        pInstanceEntity->epairs = v33;
LABEL_40:
        v14 = Instance;
        epairs = iIndex;
LABEL_41:
        epairs = *(_DWORD *)epairs;
      }
    }
  }
LABEL_42:
  v41 = *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)v14) <= 0;
  v108 = 0;
  if ( !v41 )
  {
    v42 = (_DWORD *)((char *)&unk_12E1030 + (_DWORD)Instance);
    do
    {
      v43 = v107;
      v44 = v108;
      v45 = v108 + *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)v107);
      v107->entities[v45].origin = *(Vector *)(v42 - 2);
      v46 = (_DWORD *)((char *)&unk_12E1028 + (_DWORD)v43 + v45 * 44);
      v46[3] = v42[1];
      v46[4] = v42[2];
      v46[5] = v42[3];
      v46[6] = v42[4];
      v46[7] = v42[5];
      v46[8] = v42[6];
      v46[9] = v42[7];
      v46[10] = v42[8];
      v47 = (entity_t *)((char *)&unk_12E1028
                       + (_DWORD)v43
                       + 44 * v44
                       + 44 * *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)v43));
      v47->firstbrush += v43->nummapbrushes - Instance->nummapbrushes;
      v48 = ValueForKey(ent: v47, key: "hammerid");
      if ( *v48 != 0 )
      {
        v49 = atoi(nptr: v48);
        sprintf(string: value, format: "%d", v104 + v49);
        SetKeyValue(ent: v47, key: "hammerid", value, bAllowDuplicates: false);
      }
      pszClassName = ValueForKey(ent: v47, key: "classname");
      if ( _V_stricmp(s1: pszClassName, s2: "worldspawn") != 0 )
      {
        z = v47->origin.z;
        in1 = *(_QWORD *)&v47->origin.x;
        v100 = z;
        VectorTransform((const float *)&in1, in2: InstanceMatrix, out: &v47->origin.x);
        for ( i = v47->epairs; i != nullptr; i = i->next )
          CMapFile::ReplaceInstancePair(this: v107, pPair: i, pInstanceEntity, pParmsEntity);
        v52 = GameData::BeginInstanceRemap(
                this: &GD,
                pszClassName,
                pszInstancePrefix: string,
                Origin: InstanceOrigin,
                Angle: InstanceAngle);
        v106 = v52;
        if ( v52 != nullptr )
        {
          v41 = v52->m_nVariables <= 0;
          iIndex = 0;
          if ( !v41 )
          {
            do
            {
              m_szName = GDclass::GetVariableAt(this: v106, iIndex)->m_szName;
              v54 = ValueForKey(ent: v47, key: m_szName);
              if ( GameData::RemapKeyValue(this: &GD, pszKey: m_szName, pszInValue: v54, pszOutValue: value, NameFixup) )
                SetKeyValue(ent: v47, key: m_szName, value, bAllowDuplicates: false);
              ++iIndex;
            }
            while ( iIndex < v106->m_nVariables );
          }
        }
        if ( _V_stricmp(s1: pszClassName, s2: "func_simpleladder") == 0 )
          CMapFile::AddLadderKeys(this: v107, mapent: v47);
      }
      else
      {
        mapent = v47;
      }
      v42 += 11;
      ++v108;
    }
    while ( v108 < *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)Instance) );
  }
  v55 = Instance;
  v56 = *(_DWORD *)((char *)&unk_1391038 + (_DWORD)Instance);
  v57 = v107;
  if ( v56 != 0 )
  {
    v58 = pParmsEntity;
    do
    {
      CMapFile::ReplaceInstancePair(this: v57, pPair: *(epair_t **)v56, pInstanceEntity, pParmsEntity: v58);
      v56 = *(_DWORD *)(v56 + 4);
    }
    while ( v56 != 0 );
    v55 = Instance;
  }
  in2 = *(matrix3x4_t **)((char *)&unk_1391038 + (_DWORD)v55);
  if ( in2 != nullptr )
  {
    do
    {
      v59 = *(char **)(LODWORD(in2->m_flMatVal[0][0]) + 8);
      v60 = 0;
      strcpy(pszInValue, v59);
      strchr(string: (unsigned __int8 *)pszInValue, chr: 0x1Bu);
      v62 = v61;
      if ( v61 != 0 )
      {
        *(_BYTE *)v61 = 0;
        v60 = strlen((const char *)(v61 + 1)) + 1;
      }
      if ( GameData::RemapNameField(this: &GD, pszInValue, pszOutValue: value, NameFixup) )
      {
        v63 = (char *)MemAlloc_Alloc(nSize: strlen(value) + v60 + 1);
        strcpy(v63, value);
        if ( v62 != 0 )
        {
          v64 = &v63[strlen(v63)];
          v65 = (char *)(v62 + 1);
          *v64 = 27;
          v66 = &v64[-v62];
          do
          {
            v67 = *v65;
            v65[(_DWORD)v66] = *v65;
            ++v65;
          }
          while ( v67 != 0 );
        }
        *(_DWORD *)(LODWORD(in2->m_flMatVal[0][0]) + 8) = v63;
        free(pMem: v59);
      }
      v68 = *(QAngle **)(LODWORD(in2->m_flMatVal[0][0]) + 8);
      Angle = v68;
      v69 = (char *)(pszInValue - (char *)v68);
      do
      {
        x_low = LOBYTE(v68->x);
        *((_BYTE *)&v68->x + (_DWORD)v69) = LOBYTE(v68->x);
        v68 = (QAngle *)((char *)v68 + 1);
      }
      while ( x_low != 0 );
      strchr(string: (unsigned __int8 *)pszInValue, chr: 0x1Bu);
      if ( v71 != 0 )
      {
        v72 = (const char *)(v71 + 1);
        strchr(string: (unsigned __int8 *)(v71 + 1), chr: 0x1Bu);
        v74 = v73;
        if ( v73 != 0 && V_strncasecmp(s1: v72, s2: "setparent", n: v73 - (_DWORD)v72) == 0 )
        {
          v75 = (unsigned __int8 *)(v74 + 1);
          strchr(string: v75, chr: 0x1Bu);
          v77 = v76;
          if ( v76 != nullptr )
          {
            v78 = v76 - (const char *)v75;
            strncpy((unsigned __int8 *)dest, source: v75, count: v76 - (const char *)v75);
            v90 = NameFixup;
            dest[v78] = 0;
            if ( GameData::RemapNameField(this: &GD, pszInValue: dest, pszOutValue: value, NameFixup: v90) )
            {
              v79 = 0;
              do
              {
                v80 = pszInValue[v79];
                dest[v79++] = v80;
              }
              while ( v80 != 0 );
              v81 = value;
              v82 = v75 - (unsigned __int8 *)pszInValue - (_DWORD)value;
              do
              {
                v83 = *v81;
                dest[v82 + (_DWORD)v81] = *v81;
                ++v81;
              }
              while ( v83 != 0 );
              v84 = strlen(v77) + 1;
              v85 = &v93;
              do
                v86 = *++v85;
              while ( v86 != 0 );
              qmemcpy(v85, v77, v84);
              v87 = (char *)MemAlloc_Alloc(nSize: strlen(dest) + 1);
              strcpy(v87, dest);
              *(_DWORD *)(LODWORD(in2->m_flMatVal[0][0]) + 8) = v87;
              free(pMem: Angle);
            }
          }
        }
      }
      in2 = (matrix3x4_t *)LODWORD(in2->m_flMatVal[0][1]);
    }
    while ( in2 != nullptr );
    v57 = v107;
    v55 = Instance;
  }
  *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)v57) += *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)v55);
  v88 = *(_DWORD *)((char *)&unk_1391038 + (_DWORD)v57);
  if ( v88 != 0 )
  {
    while ( *(_DWORD *)(v88 + 4) != 0 )
      v88 = *(_DWORD *)(v88 + 4);
    *(_DWORD *)(v88 + 4) = *(_DWORD *)((char *)&unk_1391038 + (_DWORD)v55);
  }
  else
  {
    *(_DWORD *)((char *)&unk_1391038 + (_DWORD)v57) = *(_DWORD *)((char *)&unk_1391038 + (_DWORD)v55);
  }
  v89 = mapent;
  CMapFile::MoveBrushesToWorldGeneral(this: v57, mapent);
  if ( IntForKey(ent: pInstanceEntity, key: "toplevel") == 1 )
    *(_DWORD *)((char *)&unk_12E103C + (_DWORD)v57) = v89->epairs;
  v89->epairs = nullptr;
  v89->numbrushes = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041B3C0
// Name: enum ChunkFileResult_t LoadConnectionsKeyCallback(char const __near *,char const __near *,struct LoadEntity_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadConnectionsKeyCallback(const char *szKey, const char *szValue, LoadEntity_t *pLoadEntity)
{
  return CMapFile::LoadConnectionsKeyCallback(this: g_LoadingMap, szKey, szValue, pLoadEntity);
}

//------------------------------------------------------------------------------
// Address: 0x0041B480
// Name: public: int CMapFile::CreateNewFloatPlane(class Vector __near &,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapFile::CreateNewFloatPlane(CMapFile *this, Vector *normal, float dist)
{
  plane_t *v4; // esi
  double z; // st7
  int v6; // eax
  float *v7; // edx
  plane_t *v8; // ecx
  int type; // eax
  float x; // xmm0_4
  float y; // xmm1_4
  plane_t *hash_chain; // edx
  float v13; // xmm2_4
  float v14; // xmm3_4
  int v15; // eax
  int v16; // eax
  int v18; // eax
  int v19; // eax

  if ( fsqrt((float)((float)(normal->x * normal->x) + (float)(normal->y * normal->y)) + (float)(normal->z * normal->z)) < 0.5 )
    _Error(
      a1: "Brush %i: %s\nSide %i\nTexture: %s\n",
      g_MapError.m_brushID,
      "FloatPlane: bad normal",
      g_MapError.m_sideIndex,
      g_MapError.m_textureName);
  if ( this->nummapplanes + 2 > 0x10000 )
    _Error(
      a1: "Brush %i: %s\nSide %i\nTexture: %s\n",
      g_MapError.m_brushID,
      "MAX_MAP_PLANES",
      g_MapError.m_sideIndex,
      g_MapError.m_textureName);
  v4 = &this->mapplanes[this->nummapplanes];
  v4->normal.x = normal->x;
  v4->normal.y = normal->y;
  z = normal->z;
  v4->dist = dist;
  v4->normal.z = z;
  v6 = PlaneTypeForNormal(normal: &v4->normal);
  v4[1].type = v6;
  v4->type = v6;
  v4[1].normal.x = vec3_origin.x - *v7;
  v8 = v4 + 1;
  v4[1].normal.y = vec3_origin.y - v7[1];
  v4[1].normal.z = vec3_origin.z - v7[2];
  LODWORD(v4[1].dist) = LODWORD(dist) ^ _mask__NegFloat_;
  this->nummapplanes += 2;
  type = v4->type;
  if ( type >= 3 || v4->normal.x >= 0.0 && v4->normal.y >= 0.0 && v4->normal.z >= 0.0 )
  {
    v18 = ((int)fabs(v4->dist) / 8) & 0x3FF;
    v4->hash_chain = this->planehash[v18];
    this->planehash[v18] = v4;
    v19 = ((int)fabs(v4[1].dist) / 8) & 0x3FF;
    v4[1].hash_chain = this->planehash[v19];
    this->planehash[v19] = v8;
    return this->nummapplanes - 2;
  }
  else
  {
    x = v4->normal.x;
    y = v4->normal.y;
    v4->normal.x = v8->normal.x;
    hash_chain = v4->hash_chain;
    v13 = v4->normal.z;
    v4->normal.y = v4[1].normal.y;
    v14 = v4->dist;
    v4->normal.z = v4[1].normal.z;
    v4->dist = v4[1].dist;
    v4->type = v4[1].type;
    v4->hash_chain = v4[1].hash_chain;
    v4[1].type = type;
    v4[1].hash_chain = hash_chain;
    v4[1].normal.y = y;
    v8->normal.x = x;
    v4[1].normal.z = v13;
    v4[1].dist = v14;
    v15 = ((int)fabs(v4->dist) / 8) & 0x3FF;
    v4->hash_chain = this->planehash[v15];
    this->planehash[v15] = v4;
    v16 = ((int)fabs(v4[1].dist) / 8) & 0x3FF;
    v4[1].hash_chain = this->planehash[v16];
    this->planehash[v16] = v8;
    return this->nummapplanes - 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B720
// Name: public: int CMapFile::FindFloatPlane(class Vector __near &,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapFile::FindFloatPlane(CMapFile *this, Vector *normal, unsigned int dist)
{
  float v4; // xmm4_4
  __m128 v5; // xmm2
  __m128 v6; // xmm0
  __m128 v7; // xmm1
  __m128 v8; // xmm3
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  float v11; // xmm1_4
  int v12; // eax
  int v13; // edx
  plane_t *v14; // ecx

  SnapVector(normal);
  v4 = *(float *)&dist;
  v5.m128_i32[0] = 1258291200;
  v6 = (__m128)dist;
  v6.m128_f32[0] = *(float *)&dist + 0.5;
  v7 = _mm_and_ps((__m128)0x80000000, v6);
  v8.m128_i32[0] = v7.m128_i32[0];
  v5.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v6, v7), v5).m128_f32[0]) & 0x4B000000 | v7.m128_i32[0];
  v9 = v6;
  v9.m128_f32[0] = (float)((float)(*(float *)&dist + 0.5) + v5.m128_f32[0]) - v5.m128_f32[0];
  v10 = v9;
  v10.m128_f32[0] = v9.m128_f32[0] - (float)(*(float *)&dist + 0.5);
  v11 = v9.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v10, v8).m128_f32[0]) & 0x3F800000);
  if ( fabs(*(float *)&dist - v11) < 0.0099999998 )
    v4 = v11;
  v12 = ((int)fabs(v4) / 8) & 0x3FF;
  v13 = -1;
  while ( 1 )
  {
    v14 = this->planehash[((_WORD)v13 + (_WORD)v12) & 0x3FF];
    if ( v14 != nullptr )
      break;
LABEL_10:
    if ( ++v13 > 1 )
      return CMapFile::CreateNewFloatPlane(this, normal, dist: v4);
  }
  while ( fabs(v14->normal.x - normal->x) >= 0.0000099999997
       || fabs(v14->normal.y - normal->y) >= 0.0000099999997
       || fabs(v14->normal.z - normal->z) >= 0.0000099999997
       || fabs(v14->dist - v4) >= 0.0099999998 )
  {
    v14 = v14->hash_chain;
    if ( v14 == nullptr )
      goto LABEL_10;
  }
  return ((char *)v14 - (char *)this) / 24;
}

//------------------------------------------------------------------------------
// Address: 0x0041B880
// Name: public: int CMapFile::PlaneFromPoints(class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapFile::PlaneFromPoints(CMapFile *this, const Vector *p0, float p1, const Vector *p2)
{
  const Vector *v4; // ebx
  const Vector *v5; // edi
  float v6; // xmm5_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  Vector normal; // [esp+10h] [ebp-10h] BYREF
  CMapFile *v14; // [esp+1Ch] [ebp-4h]

  v14 = this;
  v4 = p2;
  v5 = (const Vector *)LODWORD(p1);
  v6 = p2->y - *(float *)(LODWORD(p1) + 4);
  v7 = p2->z - *(float *)(LODWORD(p1) + 8);
  v8 = p0->y - *(float *)(LODWORD(p1) + 4);
  v9 = p0->z - *(float *)(LODWORD(p1) + 8);
  v10 = p0->x - *(float *)LODWORD(p1);
  v11 = p2->x - *(float *)LODWORD(p1);
  normal.x = (float)(v7 * v8) - (float)(v6 * v9);
  normal.y = (float)(v11 * v9) - (float)(v7 * v10);
  normal.z = (float)(v10 * v6) - (float)(v11 * v8);
  VectorNormalize(vec: &normal);
  p1 = (float)((float)(p0->x * normal.x) + (float)(p0->y * normal.y)) + (float)(normal.z * p0->z);
  SnapPlane(&normal, dist: &p1, p0, p1: v5, p2: v4);
  return CMapFile::FindFloatPlane(this: v14, &normal, dist: LODWORD(p1));
}

//------------------------------------------------------------------------------
// Address: 0x0041B970
// Name: enum ChunkFileResult_t LoadDispInfoCallback(class CChunkFile __near *,struct mapdispinfo_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadDispInfoCallback(CChunkFile *pFile, mapdispinfo_t **ppMapDispInfo)
{
  mapdispinfo_t *v2; // esi
  ChunkFileResult_t Chunk; // ebx
  CChunkHandlerMap Handlers; // [esp+0h] [ebp-Ch] BYREF

  if ( nummapdispinfo > 2048 )
    _Error(
      a1: "Brush %i: %s\nSide %i\nTexture: %s\n",
      g_MapError.m_brushID,
      "ParseDispInfoChunk: nummapdispinfo > MAX_MAP_DISPINFO",
      g_MapError.m_sideIndex,
      g_MapError.m_textureName);
  v2 = (mapdispinfo_t *)((char *)&mapdispinfo + 33668 * nummapdispinfo++);
  v2->flags = 0;
  CExpressionEvaluator::CExpressionEvaluator(this: (CExpressionEvaluator *)&Handlers);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "normals",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))LoadDispNormalsCallback,
    pData: v2);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "distances",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))LoadDispDistancesCallback,
    pData: v2);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "offsets",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))LoadDispOffsetsCallback,
    pData: v2);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "alphas",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))LoadDispAlphasCallback,
    pData: v2);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "triangle_tags",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))LoadDispTriangleTagsCallback,
    pData: v2);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "multiblend",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))LoadDispMultiBlendCallback,
    pData: v2);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "alphablend",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))LoadDispAlphaBlendCallback,
    pData: v2);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "multiblend_color_0",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))LoadDispMultiBlendColorCallback0,
    pData: v2);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "multiblend_color_1",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))LoadDispMultiBlendColorCallback1,
    pData: v2);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "multiblend_color_2",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))LoadDispMultiBlendColorCallback2,
    pData: v2);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "multiblend_color_3",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))LoadDispMultiBlendColorCallback3,
    pData: v2);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &Handlers);
  Chunk = CChunkFile::ReadChunk(
            this: pFile,
            pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))LoadDispInfoKeyCallback,
            pData: v2);
  CChunkFile::PopHandlers(this: pFile);
  if ( Chunk == ChunkFile_Ok )
    *ppMapDispInfo = v2;
  CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
  return Chunk;
}

//------------------------------------------------------------------------------
// Address: 0x0041BAF0
// Name: public: void CMapFile::MergePlanes(struct entity_t __near *,class CMapFile __near *,class Vector __near &,class QAngle __near &,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFile::MergePlanes(
        CMapFile *this,
        entity_t *pInstanceEntity,
        CMapFile *Instance,
        Vector *InstanceOrigin,
        QAngle *InstanceAngle,
        matrix3x4_t *InstanceMatrix)
{
  CMapFile *v6; // esi
  int i; // ebx
  __m128 dist; // xmm6
  int v10; // eax
  float *v11; // ecx
  __m128 v12; // xmm2
  __m128 v13; // xmm0
  __m128 v14; // xmm3
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  float v17; // xmm1_4
  int v18; // eax
  int v19; // edx
  plane_t *v20; // ecx

  v6 = Instance;
  for ( i = 0; i < Instance->nummapplanes; v6 = (CMapFile *)((char *)v6 + 48) )
  {
    dist = (__m128)LODWORD(v6->mapplanes[0].dist);
    v10 = 0;
    v11 = (float *)v6;
    while ( 1 )
    {
      if ( fabs(*v11 - 1.0) < 0.00001 )
      {
        *(_QWORD *)&v6->mapplanes[0].normal.y = 0;
        v6->mapplanes[0].normal.x = 0.0;
        *((_DWORD *)&v6->mapplanes[0].normal.x + v10) = 1065353216;
        goto LABEL_9;
      }
      if ( fabs(*v11 - -1.0) < 0.00001 )
        break;
      ++v10;
      ++v11;
      if ( v10 >= 3 )
        goto LABEL_9;
    }
    *(_QWORD *)&v6->mapplanes[0].normal.y = 0;
    v6->mapplanes[0].normal.x = 0.0;
    *((_DWORD *)&v6->mapplanes[0].normal.x + v10) = -1082130432;
LABEL_9:
    v12.m128_i32[0] = 1258291200;
    v13 = dist;
    v13.m128_f32[0] = dist.m128_f32[0] + 0.5;
    v14 = _mm_and_ps((__m128)0x80000000, v13);
    v12.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v13, v14), v12).m128_f32[0]) & 0x4B000000
                    | v14.m128_i32[0];
    v15 = v13;
    v15.m128_f32[0] = (float)((float)(dist.m128_f32[0] + 0.5) + v12.m128_f32[0]) - v12.m128_f32[0];
    v16 = v15;
    v16.m128_f32[0] = v15.m128_f32[0] - (float)(dist.m128_f32[0] + 0.5);
    v17 = v15.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v16, v14).m128_u32[0] & 0x3F800000);
    if ( fabs(dist.m128_f32[0] - v17) < 0.0099999998 )
      dist.m128_f32[0] = v17;
    v18 = ((int)fabs(dist.m128_f32[0]) / 8) & 0x3FF;
    v19 = -1;
    while ( 1 )
    {
      v20 = this->planehash[((_WORD)v19 + (_WORD)v18) & 0x3FF];
      if ( v20 != nullptr )
        break;
LABEL_18:
      if ( ++v19 > 1 )
      {
        CMapFile::CreateNewFloatPlane(this, normal: (Vector *)v6, dist: dist.m128_f32[0]);
        goto LABEL_20;
      }
    }
    while ( fabs(v20->normal.x - v6->mapplanes[0].normal.x) >= 0.0000099999997
         || fabs(v20->normal.y - v6->mapplanes[0].normal.y) >= 0.0000099999997
         || fabs(v20->normal.z - v6->mapplanes[0].normal.z) >= 0.0000099999997
         || fabs(v20->dist - dist.m128_f32[0]) >= 0.0099999998 )
    {
      v20 = v20->hash_chain;
      if ( v20 == nullptr )
        goto LABEL_18;
    }
LABEL_20:
    i += 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041BCF0
// Name: public: void CMapFile::MergeOverlays(struct entity_t __near *,class CMapFile __near *,class Vector __near &,class QAngle __near &,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFile::MergeOverlays(
        CMapFile *this,
        entity_t *pInstanceEntity,
        CMapFile *Instance,
        Vector *InstanceOrigin,
        QAngle *InstanceAngle,
        matrix3x4_t *InstanceMatrix)
{
  int v6; // esi
  int v7; // edi
  int v8; // esi
  int v9; // edi

  v6 = *(_DWORD *)((char *)&unk_139103C + (_DWORD)Instance);
  if ( v6 < g_aMapOverlays.m_Size )
  {
    v7 = v6;
    do
    {
      Overlay_Translate(
        pOverlay: &g_aMapOverlays.m_Memory.m_pMemory[v7],
        OriginOffset: InstanceOrigin,
        AngleOffset: InstanceAngle,
        Matrix: InstanceMatrix);
      ++v6;
      ++v7;
    }
    while ( v6 < g_aMapOverlays.m_Size );
  }
  v8 = *(_DWORD *)((char *)&unk_1391040 + (_DWORD)Instance);
  if ( v8 < g_aMapWaterOverlays.m_Size )
  {
    v9 = v8;
    do
    {
      Overlay_Translate(
        pOverlay: &g_aMapWaterOverlays.m_Memory.m_pMemory[v9],
        OriginOffset: InstanceOrigin,
        AngleOffset: InstanceAngle,
        Matrix: InstanceMatrix);
      ++v8;
      ++v9;
    }
    while ( v8 < g_aMapWaterOverlays.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041BD90
// Name: public: enum ChunkFileResult_t CMapFile::LoadSideCallback(class CChunkFile __near *,struct LoadSide_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CMapFile::LoadSideCallback(CMapFile *this, CChunkFile *pFile, LoadSide_t *pSideInfo)
{
  bool v4; // zf
  int nummapbrushsides; // edx
  int nSideIndex; // eax
  side_t *v8; // esi
  int contents; // eax
  int v11; // eax
  int v12; // esi
  mapbrush_t *v13; // ebx
  int v14; // ecx
  int numsides; // eax
  side_t *v16; // eax
  int v17; // edx
  CMapFile *v18; // esi
  CChunkHandlerMap Handlers; // [esp+Ch] [ebp-14h] BYREF
  mapbrush_t *b; // [esp+18h] [ebp-8h]
  CMapFile *v22; // [esp+1Ch] [ebp-4h]
  ChunkFileResult_t eResult; // [esp+28h] [ebp+8h]
  side_t *k; // [esp+2Ch] [ebp+Ch]
  int ka; // [esp+2Ch] [ebp+Ch]

  v4 = this->nummapbrushsides == 0x10000;
  v22 = this;
  if ( v4 )
    _Error(
      a1: "Brush %i: %s\nSide %i\nTexture: %s\n",
      g_MapError.m_brushID,
      "MAX_MAP_BRUSHSIDES",
      g_MapError.m_sideIndex,
      g_MapError.m_textureName);
  nummapbrushsides = this->nummapbrushsides;
  b = pSideInfo->pBrush;
  nSideIndex = pSideInfo->nSideIndex;
  v8 = &this->brushsides[nummapbrushsides];
  pSideInfo->pSide = v8;
  pSideInfo->nSideIndex = nSideIndex + 1;
  g_MapError.m_sideIndex = nSideIndex;
  pSideInfo->pSide->pMapDisp = nullptr;
  CExpressionEvaluator::CExpressionEvaluator(this: (CExpressionEvaluator *)&Handlers);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "dispinfo",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))LoadDispInfoCallback,
    pData: &v8->pMapDisp);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &Handlers);
  eResult = CChunkFile::ReadChunk(
              this: pFile,
              pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))LoadSideKeyCallback,
              pData: pSideInfo);
  CChunkFile::PopHandlers(this: pFile);
  if ( eResult != ChunkFile_Ok )
    goto LABEL_33;
  v8->contents |= pSideInfo->nBaseContents;
  v8->surf |= pSideInfo->nBaseFlags;
  pSideInfo->td.flags |= pSideInfo->nBaseFlags;
  contents = v8->contents;
  if ( (contents & 0x30000) != 0 )
    v8->contents = (unsigned int)&g_WaterOverlays[7253].aFaces[48] | contents;
  if ( fulldetail != 0 )
    v8->contents &= ~0x8000000u;
  if ( g_bConvertStructureToDetail && pSideInfo->pEntity == (entity_t *)((char *)&unk_12E1028 + (_DWORD)v22) )
    v8->contents |= (unsigned int)&g_WaterOverlays[7253].aFaces[48];
  v11 = v8->contents;
  if ( (v11 & 0x300FF) == 0 )
    v8->contents = v11 | 1;
  if ( (v8->surf & 0x300) != 0 )
    v8->contents = 0;
  v12 = CMapFile::PlaneFromPoints(
          this: v22,
          p0: pSideInfo->planepts,
          p1: COERCE_FLOAT((LoadSide_t *)&pSideInfo->planepts[1]),
          p2: &pSideInfo->planepts[2]);
  if ( v12 == -1 )
  {
    printf(format: "Brush %i, Side %i: %s\n", g_MapError.m_brushID, g_MapError.m_sideIndex, "plane with no normal");
LABEL_33:
    CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
    return eResult;
  }
  v13 = b;
  v14 = 0;
  if ( b->numsides > 0 )
  {
    k = b->original_sides;
    while ( 1 )
    {
      if ( k->planenum == v12 )
      {
        ka = v14;
        printf(format: "Brush %i, Side %i: %s\n", g_MapError.m_brushID, g_MapError.m_sideIndex, "duplicate plane");
        goto LABEL_24;
      }
      if ( k->planenum == (v12 ^ 1) )
        break;
      ++k;
      if ( ++v14 >= b->numsides )
        goto LABEL_25;
    }
    ka = v14;
    printf(format: "Brush %i, Side %i: %s\n", g_MapError.m_brushID, g_MapError.m_sideIndex, "mirrored plane");
LABEL_24:
    v14 = ka;
  }
LABEL_25:
  numsides = v13->numsides;
  if ( v14 != numsides )
    goto LABEL_33;
  v16 = &v13->original_sides[numsides];
  v16->planenum = v12;
  if ( onlyents != 0 )
  {
    v18 = v22;
  }
  else
  {
    v17 = v12;
    v18 = v22;
    v16->texinfo = TexinfoForBrushTexture(plane: &v22->mapplanes[v17], bt: &pSideInfo->td, origin: &vec3_origin);
  }
  if ( v18->nummapbrushsides == 0x10000 )
    _Error(
      a1: "Brush %i: %s\nSide %i\nTexture: %s\n",
      g_MapError.m_brushID,
      "MAX_MAP_BRUSHSIDES",
      g_MapError.m_sideIndex,
      g_MapError.m_textureName);
  brush_texture_t::operator=(
    this: (brush_texture_t *)&byte_7A1024[(_DWORD)v18 + 180 * v18->nummapbrushsides],
    __that: &pSideInfo->td);
  ++v18->nummapbrushsides;
  ++v13->numsides;
  CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
  return ChunkFile_Ok;
}

//------------------------------------------------------------------------------
// Address: 0x0041C040
// Name: enum ChunkFileResult_t LoadConnectionsCallback(class CChunkFile __near *,struct LoadEntity_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadConnectionsCallback(CChunkFile *pFile, LoadEntity_t *pLoadEntity)
{
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))LoadConnectionsKeyCallback,
           pData: pLoadEntity);
}

//------------------------------------------------------------------------------
// Address: 0x0041C060
// Name: public: virtual bool CMapDataFilesMgr::ReadRegisteredFile(char const __near *,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapDataFilesMgr::ReadRegisteredFile(
        CMapDataFilesMgr *this,
        const char *szFileName,
        CUtlBuffer *bufRead)
{
  int m_Id; // eax
  CUtlBuffer *v6; // eax

  m_Id = CUtlSymbolTable::Find(
           this: &this->m_map.m_SymbolTable,
           result: (CUtlSymbol *)&szFileName + 1,
           pString: szFileName)->m_Id;
  if ( (_WORD)m_Id == 0xFFFF )
    return 0;
  v6 = this->m_map.m_Vector.m_Memory.m_pMemory[m_Id];
  CUtlBuffer::Put(this: bufRead, pMem: v6->m_Memory.m_pMemory, size: v6->m_Put);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041C0B0
// Name: public: virtual void CMapDataFilesMgr::AddAllRegisteredFilesToPak(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDataFilesMgr::AddAllRegisteredFilesToPak(CMapDataFilesMgr *this)
{
  int v2; // esi
  char *v3; // eax
  CUtlBuffer *v4; // ecx
  CZip *PakFile; // eax
  const char *v6; // [esp-10h] [ebp-1Ch]
  unsigned __int8 *m_pMemory; // [esp-Ch] [ebp-18h]
  int m_Put; // [esp-8h] [ebp-14h]

  v2 = 0;
  if ( this->m_map.m_SymbolTable.m_Lookup.m_NumElements != 0 )
  {
    do
    {
      v3 = CUtlSymbolTable::String(this: &this->m_map.m_SymbolTable, id: (CUtlSymbol)v2);
      v4 = this->m_map.m_Vector.m_Memory.m_pMemory[(unsigned __int16)v2];
      m_Put = v4->m_Put;
      m_pMemory = v4->m_Memory.m_pMemory;
      v6 = v3;
      PakFile = GetPakFile();
      AddBufferToPak(pak: PakFile, pRelativeName: v6, data: m_pMemory, length: m_Put, bTextMode: false);
      ++v2;
    }
    while ( v2 < this->m_map.m_SymbolTable.m_Lookup.m_NumElements );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C100
// Name: enum ChunkFileResult_t LoadSideCallback(class CChunkFile __near *,struct LoadSide_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadSideCallback(CChunkFile *pFile, LoadSide_t *pSideInfo)
{
  return CMapFile::LoadSideCallback(this: g_LoadingMap, pFile, pSideInfo);
}

//------------------------------------------------------------------------------
// Address: 0x0041C230
// Name: enum ChunkFileResult_t HandleNoDynamicShadowsEnt(struct entity_t __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl HandleNoDynamicShadowsEnt(entity_t *pMapEnt)
{
  char *v1; // eax
  const char *result; // eax
  int m_Size; // eax
  int *m_pMemory; // edx
  int v5; // ecx
  int v6; // esi
  int v7; // eax
  int *v8; // eax
  int brushSideID; // [esp+4h] [ebp-4h] BYREF

  v1 = ValueForKey(ent: pMapEnt, key: "sides");
  result = strtok(string: v1, control: " ");
  if ( result != nullptr )
  {
    do
    {
      if ( sscanf(string: result, format: "%d", &brushSideID) == 1 )
      {
        m_Size = g_NoDynamicShadowSides.m_Size;
        m_pMemory = g_NoDynamicShadowSides.m_Memory.m_pMemory;
        v5 = 0;
        if ( g_NoDynamicShadowSides.m_Size <= 0 )
          goto LABEL_8;
        while ( g_NoDynamicShadowSides.m_Memory.m_pMemory[v5] != brushSideID )
        {
          if ( ++v5 >= g_NoDynamicShadowSides.m_Size )
            goto LABEL_8;
        }
        if ( v5 == -1 )
        {
LABEL_8:
          v6 = g_NoDynamicShadowSides.m_Size;
          if ( g_NoDynamicShadowSides.m_Size + 1 > g_NoDynamicShadowSides.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CClassInput *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&g_NoDynamicShadowSides,
              num: g_NoDynamicShadowSides.m_Size - g_NoDynamicShadowSides.m_Memory.m_nAllocationCount + 1);
            m_Size = g_NoDynamicShadowSides.m_Size;
            m_pMemory = g_NoDynamicShadowSides.m_Memory.m_pMemory;
          }
          g_NoDynamicShadowSides.m_Size = m_Size + 1;
          v7 = m_Size - v6;
          g_NoDynamicShadowSides.m_pElements = m_pMemory;
          if ( v7 > 0 )
          {
            _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * v7);
            m_pMemory = g_NoDynamicShadowSides.m_Memory.m_pMemory;
          }
          v8 = &m_pMemory[v6];
          if ( v8 != nullptr )
            *v8 = brushSideID;
        }
      }
      result = strtok(string: nullptr, control: " ");
    }
    while ( result != nullptr );
    pMapEnt->epairs = nullptr;
  }
  else
  {
    pMapEnt->epairs = nullptr;
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041C340
// Name: LoadOverlayDataTransitionKeyCallback
// Source: json
//------------------------------------------------------------------------------
int __cdecl LoadOverlayDataTransitionKeyCallback(const char *szKey, const char *szValue, mapoverlay_t *pOverlay)
{
  const char *v3; // eax
  int v5; // edx
  char v6; // cl
  void *v7; // esp
  const char *v8; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v12; // eax
  int *v13; // eax
  char v14[12]; // [esp+0h] [ebp-10h] BYREF
  int nSideId; // [esp+Ch] [ebp-4h] BYREF

  if ( _V_stricmp(s1: szKey, s2: "material") != 0 )
  {
    if ( _V_stricmp(s1: szKey, s2: "StartU") != 0 )
    {
      if ( _V_stricmp(s1: szKey, s2: "EndU") != 0 )
      {
        if ( _V_stricmp(s1: szKey, s2: "StartV") != 0 )
        {
          if ( _V_stricmp(s1: szKey, s2: "EndV") != 0 )
          {
            if ( _V_stricmp(s1: szKey, s2: "BasisOrigin") != 0 )
            {
              if ( _V_stricmp(s1: szKey, s2: "BasisU") != 0 )
              {
                if ( _V_stricmp(s1: szKey, s2: "BasisV") != 0 )
                {
                  if ( _V_stricmp(s1: szKey, s2: "BasisNormal") != 0 )
                  {
                    if ( _V_stricmp(s1: szKey, s2: "uv0") != 0 )
                    {
                      if ( _V_stricmp(s1: szKey, s2: "uv1") != 0 )
                      {
                        if ( _V_stricmp(s1: szKey, s2: "uv2") != 0 )
                        {
                          if ( _V_stricmp(s1: szKey, s2: "uv3") != 0 )
                          {
                            if ( _V_stricmp(s1: szKey, s2: "sides") == 0 )
                            {
                              v7 = alloca(strlen(szValue) + 1);
                              strcpy(v14, szValue);
                              v8 = strtok(string: v14, control: " ");
                              if ( v8 == nullptr )
                                return 1;
                              CUtlVector<int,CUtlMemory<int,int>>::Purge(this: &pOverlay->aSideList);
                              CUtlVector<int,CUtlMemory<int,int>>::Purge(this: &pOverlay->aFaceList);
                              do
                              {
                                if ( sscanf(string: v8, format: "%d", &nSideId) == 1 )
                                {
                                  m_Size = pOverlay->aSideList.m_Size;
                                  m_nAllocationCount = pOverlay->aSideList.m_Memory.m_nAllocationCount;
                                  if ( m_Size + 1 > m_nAllocationCount )
                                    CUtlMemory<CClassInput *,int>::Grow(
                                      this: (CUtlMemory<S3RGBA,int> *)&pOverlay->aSideList,
                                      num: m_Size - m_nAllocationCount + 1);
                                  ++pOverlay->aSideList.m_Size;
                                  m_pMemory = pOverlay->aSideList.m_Memory.m_pMemory;
                                  v12 = pOverlay->aSideList.m_Size - m_Size - 1;
                                  pOverlay->aSideList.m_pElements = m_pMemory;
                                  if ( v12 > 0 )
                                    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
                                  v13 = &pOverlay->aSideList.m_Memory.m_pMemory[m_Size];
                                  if ( v13 != nullptr )
                                    *v13 = nSideId;
                                }
                                v8 = strtok(string: nullptr, control: " ");
                              }
                              while ( v8 != nullptr );
                            }
                            return 0;
                          }
                          else
                          {
                            CChunkFile::ReadKeyValueVector3(pszValue: szValue, vec: &pOverlay->vecUVPoints[3]);
                            return 0;
                          }
                        }
                        else
                        {
                          CChunkFile::ReadKeyValueVector3(pszValue: szValue, vec: &pOverlay->vecUVPoints[2]);
                          return 0;
                        }
                      }
                      else
                      {
                        CChunkFile::ReadKeyValueVector3(pszValue: szValue, vec: &pOverlay->vecUVPoints[1]);
                        return 0;
                      }
                    }
                    else
                    {
                      CChunkFile::ReadKeyValueVector3(pszValue: szValue, vec: pOverlay->vecUVPoints);
                      return 0;
                    }
                  }
                  else
                  {
                    CChunkFile::ReadKeyValueVector3(pszValue: szValue, vec: &pOverlay->vecBasis[2]);
                    return 0;
                  }
                }
                else
                {
                  CChunkFile::ReadKeyValueVector3(pszValue: szValue, vec: &pOverlay->vecBasis[1]);
                  return 0;
                }
              }
              else
              {
                CChunkFile::ReadKeyValueVector3(pszValue: szValue, vec: pOverlay->vecBasis);
                return 0;
              }
            }
            else
            {
              CChunkFile::ReadKeyValueVector3(pszValue: szValue, vec: &pOverlay->vecOrigin);
              return 0;
            }
          }
          else
          {
            CChunkFile::ReadKeyValueFloat(pszValue: szValue, flFloat: &pOverlay->flV[1]);
            return 0;
          }
        }
        else
        {
          CChunkFile::ReadKeyValueFloat(pszValue: szValue, flFloat: pOverlay->flV);
          return 0;
        }
      }
      else
      {
        CChunkFile::ReadKeyValueFloat(pszValue: szValue, flFloat: &pOverlay->flU[1]);
        return 0;
      }
    }
    else
    {
      CChunkFile::ReadKeyValueFloat(pszValue: szValue, flFloat: pOverlay->flU);
      return 0;
    }
  }
  else
  {
    v3 = szValue;
    if ( g_ReplaceMaterials )
      v3 = ReplaceMaterialName(name: szValue);
    if ( strlen(v3) >= 0x100 )
    {
      _Error(a1: "Overlay Material Name (%s) > OVERLAY_MAP_STRLEN (%d)", v3, 256);
      return 1;
    }
    v5 = (char *)pOverlay - v3;
    do
    {
      v6 = *v3;
      v3[v5 + 6] = *v3;
      ++v3;
    }
    while ( v6 != 0 );
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C750
// Name: public: CMapFile::~CMapFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFile::~CMapFile(CMapFile *this)
{
  int v1; // ebx
  int *v2; // esi
  void *v3; // eax
  void *v4; // eax

  v1 = 0xFFFF;
  v2 = (int *)((char *)&unk_7A1070 + (_DWORD)this);
  do
  {
    v2 -= 23;
    v2[1] = 0;
    if ( *v2 >= 0 )
    {
      if ( *(v2 - 2) != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)*(v2 - 2));
        *(v2 - 2) = 0;
      }
      *(v2 - 1) = 0;
    }
    v3 = (void *)*(v2 - 2);
    v2[2] = (int)v3;
    if ( *v2 >= 0 )
    {
      if ( v3 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
        *(v2 - 2) = 0;
      }
      *(v2 - 1) = 0;
    }
    *(v2 - 4) = 0;
    if ( *(v2 - 5) >= 0 )
    {
      if ( *(v2 - 7) != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)*(v2 - 7));
        *(v2 - 7) = 0;
      }
      *(v2 - 6) = 0;
    }
    v4 = (void *)*(v2 - 7);
    *(v2 - 3) = (int)v4;
    if ( *(v2 - 5) >= 0 )
    {
      if ( v4 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
        *(v2 - 7) = 0;
      }
      *(v2 - 6) = 0;
    }
    --v1;
  }
  while ( v1 >= 0 );
}

//------------------------------------------------------------------------------
// Address: 0x0041C800
// Name: public: void CMapFile::MergeIOProxy(struct entity_t __near *,class CMapFile __near *,class Vector __near &,class QAngle __near &,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFile::MergeIOProxy(
        CMapFile *this,
        entity_t *pInstanceEntity,
        CMapFile *Instance,
        Vector *InstanceOrigin,
        QAngle *InstanceAngle,
        matrix3x4_t *InstanceMatrix)
{
  char *v7; // eax
  bool v8; // zf
  int v9; // eax
  int v10; // esi
  const char *v11; // eax
  GameData::TNameFixup v12; // eax
  epair_t *epairs; // esi
  int v14; // ebx
  char *v15; // edi
  char *v16; // eax
  char *v17; // ecx
  char *v18; // edx
  char v19; // al
  char *v20; // ecx
  char *v21; // edx
  char v22; // al
  _BYTE *v23; // eax
  _BYTE *v24; // esi
  unsigned __int8 *v25; // esi
  int v26; // eax
  char *v27; // eax
  char v28; // cl
  _BYTE *v29; // eax
  _BYTE *v30; // esi
  _BYTE *v31; // eax
  _BYTE *v32; // ebx
  unsigned int v33; // eax
  char *v34; // edi
  char v35; // cl
  epair_t *v36; // esi
  int v37; // eax
  _DWORD *v38; // edi
  void *v39; // esi
  _BYTE *v40; // ecx
  char *v41; // eax
  char v42; // dl
  _DWORD *v43; // eax
  epair_t *v44; // ebx
  const char *v45; // esi
  char *v46; // eax
  char v47; // cl
  _BYTE *v48; // eax
  _BYTE *v49; // edi
  int v50; // eax
  int v51; // esi
  CMapFile *v52; // ebx
  const char *v53; // eax
  epair_t *next; // esi
  int v55; // ebx
  int v56; // edi
  char *v57; // eax
  char *v58; // edx
  char v59; // cl
  _BYTE *v60; // eax
  const char *v61; // eax
  const char *v62; // esi
  epair_t *v63; // esi
  S3RGBA *m_pMemory; // ecx
  int v65; // ebx
  int j; // ecx
  const char *v67; // esi
  int v68; // ecx
  S3RGBA *v69; // edx
  int k; // eax
  _BYTE *v71; // esi
  char *v72; // [esp-Ch] [ebp-185Ch]
  GameData::TNameFixup v73; // [esp-Ch] [ebp-185Ch]
  GameData::TNameFixup v74; // [esp-Ch] [ebp-185Ch]
  char key[1024]; // [esp+4h] [ebp-184Ch] BYREF
  char value[1024]; // [esp+404h] [ebp-144Ch] BYREF
  char pszOutValue[1024]; // [esp+804h] [ebp-104Ch] BYREF
  char pszInValue[1024]; // [esp+C04h] [ebp-C4Ch] BYREF
  char s1[1023]; // [esp+1004h] [ebp-84Ch] BYREF
  char v80; // [esp+1403h] [ebp-44Dh] BYREF
  char string[1024]; // [esp+1404h] [ebp-44Ch] BYREF
  char *v82; // [esp+1804h] [ebp-4Ch]
  GameData::TNameFixup NameFixup; // [esp+1808h] [ebp-48h]
  entity_t *v84; // [esp+180Ch] [ebp-44h]
  CUtlMemory<S3RGBA,int> v85; // [esp+1810h] [ebp-40h] BYREF
  int v86; // [esp+181Ch] [ebp-34h]
  S3RGBA *v87; // [esp+1820h] [ebp-30h]
  int v88; // [esp+1824h] [ebp-2Ch]
  CMapFile *v89; // [esp+1828h] [ebp-28h]
  epair_t *v90; // [esp+182Ch] [ebp-24h]
  CUtlMemory<S3RGBA,int> v91; // [esp+1830h] [ebp-20h] BYREF
  int v92; // [esp+183Ch] [ebp-14h]
  S3RGBA *v93; // [esp+1840h] [ebp-10h]
  entity_t *v94; // [esp+1844h] [ebp-Ch]
  char *s2; // [esp+1848h] [ebp-8h]
  _DWORD *i; // [esp+184Ch] [ebp-4h]

  v89 = this;
  v7 = ValueForKey(ent: pInstanceEntity, key: "targetname");
  v8 = *v7 == 0;
  s2 = v7;
  if ( !v8 )
  {
    v9 = *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)Instance);
    v10 = 0;
    if ( v9 > 0 )
    {
      while ( 1 )
      {
        v84 = (entity_t *)((char *)&unk_12E1028
                         + (_DWORD)this
                         + 44 * v10
                         + 44 * (*(_DWORD *)((char *)&unk_12E1024 + (_DWORD)this) - v9));
        v11 = ValueForKey(ent: v84, key: "classname");
        if ( _V_stricmp(s1: v11, s2: "func_instance_io_proxy") == 0 )
          break;
        v9 = *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)Instance);
        if ( ++v10 >= v9 )
          return;
      }
      if ( v84 != nullptr )
      {
        v94 = (entity_t *)ValueForKey(ent: v84, key: "targetname");
        v12 = IntForKey(ent: pInstanceEntity, key: "fixup_style");
        epairs = v84->epairs;
        v14 = 0;
        NameFixup = v12;
        v88 = 0;
        if ( epairs != nullptr )
        {
          do
          {
            if ( _V_stricmp(s1: epairs->key, s2: "OnProxyRelay") == 0 )
            {
              v15 = epairs->key;
              sprintf(string, format: "%s%d", v15, ++v14);
              v16 = (char *)MemAlloc_Alloc(nSize: strlen(string) + 1);
              epairs->key = v16;
              v17 = string;
              v18 = v16;
              do
              {
                v19 = *v17;
                *v18++ = *v17++;
              }
              while ( v19 != 0 );
              free(pMem: v15);
            }
            epairs = epairs->next;
          }
          while ( epairs != nullptr );
          v88 = v14;
        }
        for ( i = *(_DWORD **)((char *)&unk_1391038 + (_DWORD)v89);
              i != *(_DWORD **)((char *)&unk_1391038 + (_DWORD)Instance);
              i = (_DWORD *)i[1] )
        {
          v20 = *(char **)(*i + 8);
          v21 = s1;
          do
          {
            v22 = *v20;
            *v21++ = *v20++;
          }
          while ( v22 != 0 );
          strchr(string: (unsigned __int8 *)s1, chr: 0x1Bu);
          v24 = v23;
          if ( v23 != nullptr )
          {
            v72 = s2;
            *v23 = 0;
            if ( _V_stricmp(s1, s2: v72) == 0 )
            {
              v25 = v24 + 1;
              strchr(string: v25, chr: 0x1Bu);
              if ( v26 != 0 && V_strncasecmp(s1: (const char *)v25, s2: "instance:", n: 9) == 0 )
              {
                v27 = (char *)(v25 + 9);
                do
                {
                  v28 = *v27;
                  v27[pszInValue - (char *)(v25 + 9)] = *v27;
                  ++v27;
                }
                while ( v28 != 0 );
                strchr(string: (unsigned __int8 *)pszInValue, chr: 0x3Bu);
                v30 = v29;
                v73 = NameFixup;
                *v29 = 0;
                GameData::RemapNameField(this: &GD, pszInValue, pszOutValue: string, NameFixup: v73);
                *v30 = 27;
                strchr(string: v30 + 1, chr: 0x1Bu);
                v32 = v31;
                *v31 = 0;
                v33 = strlen(v30) + 1;
                v34 = &v80;
                do
                  v35 = *++v34;
                while ( v35 != 0 );
                qmemcpy(v34, v30, v33);
                v36 = v84->epairs;
                if ( v36 != nullptr )
                {
                  while ( V_strncasecmp(s1: v36->key, s2: "OnProxyRelay", n: 12) != 0
                       || V_strncasecmp(s1: v36->value, s2: string, n: strlen(string)) != 0 )
                  {
                    v36 = v36->next;
                    if ( v36 == nullptr )
                      goto LABEL_33;
                  }
                  v37 = sprintf(string, format: "%s%c%s%c%s", (const char *)v94, 27, v36->key, 27, v32 + 1);
                  v38 = i;
                  v39 = *(void **)(*i + 8);
                  *(_DWORD *)(*v38 + 8) = MemAlloc_Alloc(nSize: v37 + 1);
                  v40 = *(_BYTE **)(*v38 + 8);
                  v41 = string;
                  do
                  {
                    v42 = *v41;
                    *v40++ = *v41++;
                  }
                  while ( v42 != 0 );
                  free(pMem: v39);
                }
              }
            }
          }
LABEL_33:
          ;
        }
        memset(&v85, 0, sizeof(v85));
        v86 = 0;
        v87 = nullptr;
        memset(&v91, 0, sizeof(v91));
        v92 = 0;
        v93 = nullptr;
        v43 = *(_DWORD **)((char *)&unk_1391038 + (_DWORD)v89);
        for ( i = v43; v43 != *(_DWORD **)((char *)&unk_1391038 + (_DWORD)Instance); i = v43 )
        {
          v44 = pInstanceEntity->epairs;
          for ( s2 = (char *)v44; v44 != nullptr; s2 = (char *)v44 )
          {
            if ( v44 == (epair_t *)*v43 )
            {
              v45 = v44->key;
              if ( V_strncasecmp(s1: v45, s2: "instance:", n: 9) == 0 )
              {
                v46 = (char *)(v45 + 9);
                do
                {
                  v47 = *v46;
                  v46[pszInValue - (v45 + 9)] = *v46;
                  ++v46;
                }
                while ( v47 != 0 );
                strchr(string: (unsigned __int8 *)pszInValue, chr: 0x3Bu);
                v74 = NameFixup;
                v49 = v48;
                *v48 = 0;
                GameData::RemapNameField(this: &GD, pszInValue, pszOutValue, NameFixup: v74);
                sprintf(string: s1, format: "%s%d", "OnProxyRelay", ++v88);
                SetKeyValue(ent: v84, key: s1, value: v44->value, bAllowDuplicates: false);
                v50 = *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)Instance);
                v51 = 0;
                if ( v50 > 0 )
                {
                  v52 = v89;
                  while ( 1 )
                  {
                    v94 = (entity_t *)((char *)&unk_12E1028
                                     + (_DWORD)v52
                                     + 44 * v51
                                     + 44 * (*(_DWORD *)((char *)&unk_12E1024 + (_DWORD)v52) - v50));
                    v53 = ValueForKey(ent: v94, key: "targetname");
                    if ( _V_stricmp(s1: v53, s2: pszOutValue) == 0 )
                      break;
                    v50 = *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)Instance);
                    if ( ++v51 >= v50 )
                      goto LABEL_65;
                  }
                  next = v94->epairs;
                  v90 = next;
                  if ( next != nullptr )
                  {
                    v55 = v92;
                    v82 = v49 + 1;
                    v56 = v86;
                    do
                    {
                      if ( _V_stricmp(s1: next->key, s2: v82) == 0 )
                      {
                        v57 = next->value;
                        v58 = (char *)(string - v57);
                        do
                        {
                          v59 = *v57;
                          v58[(_DWORD)v57] = *v57;
                          ++v57;
                        }
                        while ( v59 != 0 );
                        strchr((unsigned __int8 *)string, chr: 0x1Bu);
                        if ( v60 != nullptr )
                        {
                          *v60 = 0;
                          strchr(string: v60 + 1, chr: 0x1Bu);
                          v62 = v61;
                          if ( v61 != nullptr )
                          {
                            sprintf(string: key, format: "%s_NEW", v82);
                            sprintf(string: value, format: "%s%c%s%s", string, 27, s1, v62);
                            v63 = SetKeyValue(ent: v94, key, value, bAllowDuplicates: true);
                            if ( v56 + 1 > v85.m_nAllocationCount )
                            {
                              CUtlMemory<CClassInput *,int>::Grow(this: &v85, num: v56 - v85.m_nAllocationCount + 1);
                              v56 = v86;
                            }
                            m_pMemory = v85.m_pMemory;
                            v86 = ++v56;
                            v87 = v85.m_pMemory;
                            if ( v56 - 1 > 0 )
                            {
                              _V_memmove(dest: &v85.m_pMemory[1], src: v85.m_pMemory, count: 4 * (v56 - 1));
                              m_pMemory = v85.m_pMemory;
                            }
                            if ( m_pMemory != nullptr )
                              *m_pMemory = (S3RGBA)v63;
                            if ( v55 + 1 > v91.m_nAllocationCount )
                            {
                              CUtlMemory<CClassInput *,int>::Grow(this: &v91, num: v55 - v91.m_nAllocationCount + 1);
                              v55 = v92;
                            }
                            v92 = ++v55;
                            v93 = v91.m_pMemory;
                            if ( v55 - 1 > 0 )
                              _V_memmove(dest: &v91.m_pMemory[1], src: v91.m_pMemory, count: 4 * (v55 - 1));
                            if ( v91.m_pMemory != nullptr )
                              *v91.m_pMemory = (S3RGBA)v90;
                          }
                        }
                      }
                      next = v90->next;
                      v90 = next;
                    }
                    while ( next != nullptr );
                  }
                }
              }
            }
LABEL_65:
            v44 = *(epair_t **)s2;
            v43 = i;
          }
          v43 = (_DWORD *)v43[1];
        }
        v65 = v86;
        for ( j = 0; j < v65; v67[strlen(v67) - 4] = 0 )
          v67 = *(const char **)(*(_DWORD *)&v85.m_pMemory[j++] + 4);
        v68 = v92;
        v69 = v91.m_pMemory;
        for ( k = 0; k < v68; *v71 = 0 )
        {
          **(_BYTE **)(*(_DWORD *)&v69[k] + 4) = 0;
          v71 = *(_BYTE **)(*(_DWORD *)&v69[k++] + 8);
        }
        if ( v91.m_nGrowSize >= 0 && v69 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v69);
        if ( v85.m_nGrowSize >= 0 && v85.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v85.m_pMemory);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041CF60
// Name: public: virtual void CMapDataFilesMgr::RegisterFile(char const __near *,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDataFilesMgr::RegisterFile(CMapDataFilesMgr *this, char *szFileName, CUtlBuffer *bufData)
{
  int m_Id; // eax
  CUtlBuffer *v5; // ebx
  CUtlBuffer *v6; // esi
  CUtlBuffer *v7; // eax
  CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *p_m_map; // esi
  int v9; // edi
  int m_Size; // ecx
  CUtlSymbol result; // [esp+Eh] [ebp-2h] BYREF

  m_Id = CUtlSymbolTable::Find(this: &this->m_map.m_SymbolTable, &result, pString: szFileName)->m_Id;
  v5 = nullptr;
  if ( (_WORD)m_Id != 0xFFFF )
  {
    v6 = this->m_map.m_Vector.m_Memory.m_pMemory[m_Id];
    if ( v6 != nullptr )
    {
      if ( v6->m_Memory.m_nGrowSize >= 0 )
      {
        if ( v6->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6->m_Memory.m_pMemory);
          v6->m_Memory.m_pMemory = nullptr;
        }
        v6->m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v6);
    }
  }
  v7 = (CUtlBuffer *)MemAlloc_Alloc(nSize: 0x30u);
  if ( v7 != nullptr )
    v5 = CUtlBuffer::CUtlBuffer(this: v7, growSize: 0, initSize: 0, nFlags: 0);
  CUtlBuffer::Put(this: v5, pMem: bufData->m_Memory.m_pMemory, size: bufData->m_Put);
  p_m_map = (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&this->m_map;
  CUtlSymbolTable::AddString(this: &this->m_map.m_SymbolTable, result: (CUtlSymbol *)&szFileName, pString: szFileName);
  v9 = (unsigned __int16)szFileName;
  m_Size = p_m_map->m_Size;
  if ( m_Size > (unsigned __int16)szFileName )
  {
    p_m_map->m_Memory.m_pMemory[(unsigned __int16)szFileName] = (S3RGBA)v5;
  }
  else if ( m_Size >= (unsigned __int16)szFileName + 1 )
  {
    p_m_map->m_Memory.m_pMemory[(unsigned __int16)szFileName] = (S3RGBA)v5;
  }
  else
  {
    CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
      this: p_m_map,
      elem: m_Size,
      num: (unsigned __int16)szFileName + 1 - m_Size);
    p_m_map->m_Memory.m_pMemory[v9] = (S3RGBA)v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D040
// Name: public: void CMapFile::MergeBrushSides(struct entity_t __near *,class CMapFile __near *,class Vector __near &,class QAngle __near &,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFile::MergeBrushSides(
        CMapFile *this,
        entity_t *pInstanceEntity,
        CMapFile *Instance,
        Vector *InstanceOrigin,
        QAngle *InstanceAngle,
        matrix3x4_t *InstanceMatrix)
{
  CMapFile *v6; // ebx
  int v7; // edi
  int nummapbrushsides; // edx
  int *p_id; // ecx
  CMapFile *v10; // esi
  int v11; // ecx
  int planenum; // eax
  side_t *v13; // ebx
  mapdispinfo_t *pMapDisp; // eax
  bool v15; // cc
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int *p_numpoints; // eax
  int v20; // edi
  int v21; // esi
  winding_t *winding; // ecx
  Vector *v23; // eoff
  CMapFile *v24; // edi
  Vector *p_normal; // eax
  int FloatPlane; // eax
  brush_texture_t *v27; // esi
  float *v28; // esi
  float v29; // xmm0_4
  mapdispinfo_t *v30; // esi
  __int64 v31; // xmm0_8
  CMapFile *v32; // eax
  winding_t *w; // edx
  int v34; // ebx
  winding_t *v35; // ecx
  Vector *v36; // eoff
  int *v37; // ecx
  brush_texture_t bt; // [esp+10h] [ebp-11Ch] BYREF
  __int64 v39; // [esp+C4h] [ebp-68h] BYREF
  float z; // [esp+CCh] [ebp-60h]
  __int64 v41; // [esp+D0h] [ebp-5Ch] BYREF
  float v42; // [esp+D8h] [ebp-54h]
  Vector inPoint; // [esp+DCh] [ebp-50h] BYREF
  cplane_t inPlane; // [esp+E8h] [ebp-44h] BYREF
  cplane_t outPlane; // [esp+FCh] [ebp-30h] BYREF
  int i; // [esp+110h] [ebp-1Ch]
  int max_side_id; // [esp+114h] [ebp-18h]
  side_t *__that; // [esp+118h] [ebp-14h]
  float *in1; // [esp+11Ch] [ebp-10h]
  CMapFile *v50; // [esp+120h] [ebp-Ch]
  int point; // [esp+124h] [ebp-8h]
  int *p_numsides; // [esp+128h] [ebp-4h]

  v6 = this;
  v7 = 0;
  v50 = this;
  max_side_id = 0;
  if ( this->nummapbrushsides > 0 )
  {
    nummapbrushsides = this->nummapbrushsides;
    p_id = &this->brushsides[0].id;
    do
    {
      if ( *p_id > max_side_id )
        max_side_id = *p_id;
      p_id += 23;
      --nummapbrushsides;
    }
    while ( nummapbrushsides != 0 );
  }
  v10 = Instance;
  i = 0;
  if ( Instance->nummapbrushsides > 0 )
  {
    in1 = (float *)&byte_7A1024[(_DWORD)Instance];
    __that = Instance->brushsides;
    while ( 1 )
    {
      side_t::operator=(this: &v6->brushsides[v7 + v6->nummapbrushsides], __that);
      v11 = v7 + v6->nummapbrushsides;
      planenum = v6->brushsides[v11].planenum;
      v13 = &v6->brushsides[v11];
      v13->planenum = CMapFile::FindFloatPlane(
                        this: v50,
                        normal: &v10->mapplanes[planenum].normal,
                        dist: LODWORD(v10->mapplanes[planenum].dist));
      v13->id += max_side_id;
      pMapDisp = v13->pMapDisp;
      if ( pMapDisp == nullptr || pMapDisp->entitynum != 0 )
      {
        v15 = *(_DWORD *)((char *)&unk_12E1038 + (_DWORD)v10) <= 0;
        point = 0;
        if ( v15 )
        {
LABEL_16:
          v17 = *(_DWORD *)((char *)&unk_12E1038 + (_DWORD)v10);
          point = v17;
          if ( v17 >= v10->nummapbrushes )
            goto LABEL_30;
          p_numsides = &v10->mapbrushes[v17].numsides;
          while ( 1 )
          {
            v18 = (p_numsides[1] - (int)v10 - 1970212) / 92;
            if ( v7 >= v18 && v7 < v18 + *p_numsides && (*(p_numsides - 7) & 0x20000000) != 0 )
              break;
            p_numsides += 12;
            if ( ++point >= v10->nummapbrushes )
              goto LABEL_30;
          }
        }
        else
        {
          p_numsides = &v10->mapbrushes[0].numsides;
          while ( 1 )
          {
            v16 = (p_numsides[1] - (int)v10 - 1970212) / 92;
            if ( v7 >= v16 && v7 < v16 + *p_numsides )
              break;
            p_numsides += 12;
            if ( ++point >= *(_DWORD *)((char *)&unk_12E1038 + (_DWORD)v10) )
              goto LABEL_16;
          }
        }
      }
      p_numpoints = &v13->winding->numpoints;
      if ( p_numpoints != nullptr )
      {
        v20 = 0;
        if ( *p_numpoints > 0 )
        {
          v21 = 0;
          do
          {
            winding = v13->winding;
            v23 = &winding->p[v21];
            inPoint = *v23;
            VectorTransform(in1: &inPoint.x, in2: InstanceMatrix, out: &winding->p[v21].x);
            ++v20;
            ++v21;
          }
          while ( v20 < v13->winding->numpoints );
        }
      }
      v24 = v50;
      p_normal = &v50->mapplanes[v13->planenum].normal;
      inPlane.normal = *p_normal;
      inPlane.dist = p_normal[1].x;
      VectorRotate(in1: &inPlane.normal.x, in2: InstanceMatrix, out: &outPlane.normal.x);
      outPlane.dist = (float)((float)((float)(InstanceMatrix->m_flMatVal[1][3] * outPlane.normal.y)
                                    + (float)(InstanceMatrix->m_flMatVal[0][3] * outPlane.normal.x))
                            + (float)(InstanceMatrix->m_flMatVal[2][3] * outPlane.normal.z))
                    + (float)((float)((float)((float)(outPlane.normal.y * outPlane.normal.y)
                                            + (float)(outPlane.normal.x * outPlane.normal.x))
                                    + (float)(outPlane.normal.z * outPlane.normal.z))
                            * inPlane.dist);
      FloatPlane = CMapFile::FindFloatPlane(this: v24, normal: &outPlane.normal, dist: LODWORD(outPlane.dist));
      v27 = (brush_texture_t *)in1;
      v13->planenum = FloatPlane;
      bt = *v27;
      v28 = in1;
      VectorRotate(in1, in2: InstanceMatrix, out: &bt.UAxis.x);
      VectorRotate(in1: v28 + 3, in2: InstanceMatrix, out: &bt.VAxis.x);
      v29 = (float)((float)((float)(InstanceOrigin->y * bt.VAxis.y) + (float)(InstanceOrigin->x * bt.VAxis.x))
                  + (float)(InstanceOrigin->z * bt.VAxis.z))
          / bt.textureWorldUnitsPerTexel[1];
      bt.shift[0] = bt.shift[0]
                  - (float)((float)((float)((float)(InstanceOrigin->y * bt.UAxis.y)
                                          + (float)(InstanceOrigin->x * bt.UAxis.x))
                                  + (float)(InstanceOrigin->z * bt.UAxis.z))
                          / bt.textureWorldUnitsPerTexel[0]);
      bt.shift[1] = bt.shift[1] - v29;
      if ( onlyents == 0 )
        v13->texinfo = TexinfoForBrushTexture(plane: &v50->mapplanes[v13->planenum], &bt, origin: &vec3_origin);
      v7 = i;
LABEL_30:
      v30 = v13->pMapDisp;
      if ( v30 != nullptr )
      {
        v31 = *(_QWORD *)&v30->startPosition.x;
        v30->brushSideID = v13->id;
        v39 = v31;
        z = v30->startPosition.z;
        VectorTransform(in1: (const float *)&v39, in2: InstanceMatrix, out: &v30->startPosition.x);
        v32 = v50;
        v30->face.originalface = v13;
        v30->face.texinfo = v13->texinfo;
        v30->face.planenum = v13->planenum;
        w = v30->face.w;
        v30->entitynum += *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)v32);
        v15 = w->numpoints <= 0;
        point = 0;
        if ( !v15 )
        {
          v34 = 0;
          do
          {
            v35 = v30->face.w;
            v36 = &v35->p[v34];
            v41 = *(_QWORD *)&v36->x;
            v42 = v36->z;
            VectorTransform(in1: (const float *)&v41, in2: InstanceMatrix, out: &v35->p[v34].x);
            v37 = &v30->face.w->numpoints;
            ++v34;
            ++point;
          }
          while ( point < *v37 );
        }
      }
      ++__that;
      in1 += 45;
      i = ++v7;
      if ( v7 >= Instance->nummapbrushsides )
      {
        v50->nummapbrushsides += Instance->nummapbrushsides;
        return;
      }
      v6 = v50;
      v10 = Instance;
    }
  }
  v6->nummapbrushsides += Instance->nummapbrushsides;
}

//------------------------------------------------------------------------------
// Address: 0x0041D500
// Name: class IMapDataFilesMgr __near * GetMapDataFilesMgr(void)
// Source: json
//------------------------------------------------------------------------------
CMapDataFilesMgr *__cdecl GetMapDataFilesMgr()
{
  if ( (_S1 & 1) == 0 )
  {
    _S1 |= 1u;
    s_mgr.__vftable = (CMapDataFilesMgr_vtbl *)&CMapDataFilesMgr::`vftable';
    s_mgr.m_map.m_Vector.m_Memory.m_pMemory = nullptr;
    s_mgr.m_map.m_Vector.m_Memory.m_nAllocationCount = 0;
    s_mgr.m_map.m_Vector.m_Memory.m_nGrowSize = 32;
    s_mgr.m_map.m_Vector.m_Size = 0;
    s_mgr.m_map.m_Vector.m_pElements = nullptr;
    CUtlSymbolTable::CUtlSymbolTable(this: &s_mgr.m_map.m_SymbolTable, growSize: 0, initSize: 32, caseInsensitive: true);
    atexit(func: GetMapDataFilesMgr_::_2_::_dynamic_atexit_destructor_for__s_mgr__);
  }
  return &s_mgr;
}

//------------------------------------------------------------------------------
// Address: 0x0041D560
// Name: public: void CMapFile::AddBrushBevels(struct mapbrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFile::AddBrushBevels(CMapFile *this, mapbrush_t *b)
{
  mapbrush_t *v2; // ebx
  int v3; // edi
  int v4; // edx
  side_t *original_sides; // esi
  bool v6; // zf
  unsigned int x_low; // xmm0_4
  CMapFile *v8; // eax
  int v9; // esi
  brush_texture_t *v10; // ebx
  brush_texture_t *v11; // esi
  int numsides; // ebx
  int *m_pMemory; // eax
  IMemAlloc *v14; // ecx
  int numpoints; // esi
  int v16; // eax
  Vector *p; // ecx
  int v18; // eax
  float v19; // xmm0_4
  Vector *v20; // eax
  int v21; // eax
  int m; // ecx
  float v23; // xmm1_4
  mapbrush_t *v24; // ebx
  int v25; // eax
  float y; // xmm3_4
  float z; // xmm1_4
  float *v28; // eax
  float v29; // xmm0_4
  float v30; // xmm3_4
  float v31; // xmm4_4
  int v32; // eax
  float v33; // xmm0_4
  _DWORD *v34; // ecx
  float *p_x; // eax
  int *v36; // edi
  int v37; // esi
  int v38; // eax
  int v39; // ecx
  float *v40; // edx
  float *v41; // ecx
  bool v42; // zf
  float *v43; // ecx
  CMapFile *v44; // edi
  int v45; // esi
  brush_texture_t tdtemp; // [esp+10h] [ebp-168h] BYREF
  side_t sidetemp; // [esp+C4h] [ebp-B4h] BYREF
  float dist; // [esp+120h] [ebp-58h]
  int v49; // [esp+124h] [ebp-54h]
  int v50; // [esp+128h] [ebp-50h]
  Vector vec2; // [esp+12Ch] [ebp-4Ch] BYREF
  int i; // [esp+138h] [ebp-40h]
  int v53; // [esp+13Ch] [ebp-3Ch]
  unsigned int v54; // [esp+140h] [ebp-38h]
  Vector *p_vec2; // [esp+144h] [ebp-34h]
  Vector normal; // [esp+148h] [ebp-30h] BYREF
  Vector vec; // [esp+154h] [ebp-24h] BYREF
  int j; // [esp+160h] [ebp-18h]
  int dir; // [esp+164h] [ebp-14h]
  int k; // [esp+168h] [ebp-10h]
  Vector *p_mins; // [esp+16Ch] [ebp-Ch]
  winding_t *w; // [esp+170h] [ebp-8h]
  CMapFile *v63; // [esp+174h] [ebp-4h]

  v2 = b;
  v3 = 0;
  p_mins = &b->mins;
  v4 = -1;
  v63 = this;
  memset(&sidetemp.aOverlayIds, 0, 40);
  memset(&tdtemp, 0, 24);
  k = 0;
  w = nullptr;
  dir = -1;
  for ( j = 0; ; j = 92 * k )
  {
    while ( 1 )
    {
      original_sides = v2->original_sides;
      v6 = v2->numsides == 0;
      if ( v2->numsides > 0 )
      {
        do
        {
          if ( *(&v63->mapplanes[0].normal.x + (_DWORD)w + 6 * original_sides->planenum) == (float)v4 )
            break;
          ++v3;
          ++original_sides;
        }
        while ( v3 < v2->numsides );
        v6 = v3 == v2->numsides;
      }
      if ( v6 )
      {
        if ( v63->nummapbrushsides == 0x10000 )
        {
          _Error(
            a1: "Brush %i: %s\nSide %i\nTexture: %s\n",
            g_MapError.m_brushID,
            "MAX_MAP_BRUSHSIDES",
            g_MapError.m_sideIndex,
            g_MapError.m_textureName);
          v4 = dir;
        }
        ++v63->nummapbrushsides;
        ++v2->numsides;
        memset(&normal, 0, sizeof(normal));
        *(&normal.x + (_DWORD)w) = (float)v4;
        if ( v4 == 1 )
          x_low = LODWORD(p_mins[1].x);
        else
          x_low = LODWORD(p_mins->x) ^ _mask__NegFloat_;
        original_sides->planenum = CMapFile::FindFloatPlane(this: v63, &normal, dist: x_low);
        original_sides->texinfo = v2->original_sides->texinfo;
        v8 = v63;
        v4 = dir;
        original_sides->contents = v2->original_sides->contents;
        original_sides->bevel = true;
        ++*(_DWORD *)((char *)&unk_1391028 + (_DWORD)v8);
      }
      if ( v3 != k )
      {
        side_t::operator=(this: &sidetemp, __that: (const side_t *)((char *)b->original_sides + j));
        side_t::operator=(this: (side_t *)((char *)b->original_sides + j), __that: &b->original_sides[v3]);
        side_t::operator=(this: &b->original_sides[v3], __that: &sidetemp);
        v9 = ((char *)b->original_sides - (char *)v63 - 1970212) / 92;
        v10 = (brush_texture_t *)&byte_7A1024[(_DWORD)v63 + 180 * v9 + 180 * k];
        brush_texture_t::operator=(this: &tdtemp, __that: v10);
        v11 = (brush_texture_t *)&byte_7A1024[(_DWORD)v63 + 180 * v3 + 180 * v9];
        brush_texture_t::operator=(this: v10, __that: v11);
        brush_texture_t::operator=(this: v11, __that: &tdtemp);
        v2 = b;
        v4 = dir;
      }
      ++k;
      j += 92;
      v4 += 2;
      dir = v4;
      if ( v4 > 1 )
        break;
      v3 = 0;
    }
    p_mins = (Vector *)((char *)p_mins + 4);
    w = (winding_t *)((char *)w + 1);
    if ( (int)w >= 3 )
      break;
    v4 = -1;
    v3 = 0;
    dir = -1;
  }
  numsides = v2->numsides;
  if ( numsides == 6 )
  {
    if ( sidetemp.aWaterOverlayIds.m_Memory.m_nGrowSize >= 0 )
    {
      m_pMemory = sidetemp.aWaterOverlayIds.m_Memory.m_pMemory;
      if ( sidetemp.aWaterOverlayIds.m_Memory.m_pMemory != nullptr )
      {
        v14 = _g_pMemAlloc;
LABEL_81:
        v14->Free_2(this: v14, a2: m_pMemory);
        goto LABEL_82;
      }
    }
    goto LABEL_82;
  }
  i = 6;
  if ( numsides > 6 )
  {
    v54 = 552;
    while ( 1 )
    {
      w = b->original_sides[v54 / 0x5C].winding;
      if ( w != nullptr )
      {
        numpoints = w->numpoints;
        v16 = 0;
        if ( w->numpoints > 0 )
          break;
      }
LABEL_77:
      v54 += 92;
      if ( ++i >= b->numsides )
        goto LABEL_78;
    }
    p_mins = nullptr;
    while ( 1 )
    {
      p = w->p;
      v49 = v16 + 1;
      v18 = (v16 + 1) % numpoints;
      v19 = *(float *)((char *)&p->x + (_DWORD)p_mins) - p[v18].x;
      v20 = &p[v18];
      vec.x = v19;
      vec.y = *(float *)((char *)&p->y + (_DWORD)p_mins) - v20->y;
      vec.z = *(float *)((char *)&p->z + (_DWORD)p_mins) - v20->z;
      if ( VectorNormalize(&vec) >= 0.5 )
      {
        v21 = 0;
        while ( 1 )
        {
          if ( fabs(*(&vec.x + v21) - 1.0) < 0.00001 )
          {
            memset(&vec, 0, sizeof(vec));
            *((_DWORD *)&vec.x + v21) = 1065353216;
            goto LABEL_36;
          }
          if ( fabs(*(&vec.x + v21) - -1.0) < 0.00001 )
            break;
          if ( ++v21 >= 3 )
            goto LABEL_36;
        }
        memset(&vec, 0, sizeof(vec));
        *((_DWORD *)&vec.x + v21) = -1082130432;
LABEL_36:
        for ( m = 0; m < 3; ++m )
        {
          v23 = *(&vec.x + m);
          if ( v23 == -1.0 )
            break;
          if ( v23 == 1.0 )
            break;
        }
        if ( m == 3 )
          break;
      }
LABEL_76:
      v16 = v49;
      numpoints = w->numpoints;
      ++p_mins;
      if ( v49 >= numpoints )
        goto LABEL_77;
    }
    v24 = b;
    dir = -1;
    v25 = -1;
    p_vec2 = &vec2;
    v53 = 3;
    while ( 1 )
    {
      y = vec.y;
      z = vec.z;
      memset(&vec2, 0, sizeof(vec2));
      p_vec2->x = (float)v25;
      normal.x = (float)(vec2.z * y) - (float)(vec2.y * z);
      normal.y = (float)(z * vec2.x) - (float)(vec2.z * vec.x);
      normal.z = (float)(vec2.y * vec.x) - (float)(y * vec2.x);
      if ( VectorNormalize(vec: &normal) >= 0.5 )
      {
        v28 = (float *)((char *)&p_mins->x + (unsigned int)w->p);
        v29 = v28[1];
        v30 = *v28;
        v31 = v28[2];
        v32 = v24->numsides;
        v33 = (float)((float)(v29 * normal.y) + (float)(v30 * normal.x)) + (float)(v31 * normal.z);
        dist = v33;
        k = 0;
        v50 = v32;
        if ( v32 > 0 )
        {
          j = (int)v24->original_sides;
          v34 = (_DWORD *)j;
          while ( 1 )
          {
            p_x = &v63->mapplanes[*v34].normal.x;
            if ( fabs(*p_x - normal.x) < 0.0099999998
              && fabs(p_x[1] - normal.y) < 0.0099999998
              && fabs(p_x[2] - normal.z) < 0.0099999998
              && fabs(p_x[3] - v33) < 0.0099999998 )
            {
              goto LABEL_70;
            }
            v36 = (int *)v34[3];
            if ( v36 != nullptr )
              break;
LABEL_69:
            v34 += 23;
            ++k;
            j = (int)v34;
            if ( k >= v24->numsides )
              goto LABEL_70;
          }
          v37 = *v36;
          v38 = 0;
          if ( *v36 < 4 )
          {
LABEL_58:
            v42 = v38 == v37;
            if ( v38 < v37 )
            {
              v43 = (float *)(v36[1] + 12 * v38);
              do
              {
                if ( (float)((float)((float)((float)(v43[1] * normal.y) + (float)(*v43 * normal.x))
                                   + (float)(v43[2] * normal.z))
                           - v33) > 0.1 )
                  break;
                ++v38;
                v43 += 3;
              }
              while ( v38 < v37 );
              goto LABEL_66;
            }
          }
          else
          {
            v39 = v36[1];
            v40 = (float *)(v39 + 8);
            v41 = (float *)(v39 + 20);
            while ( (float)((float)((float)((float)(*(v40 - 2) * normal.x) + (float)(*(v40 - 1) * normal.y))
                                  + (float)(*v40 * normal.z))
                          - v33) <= 0.1 )
            {
              if ( (float)((float)((float)((float)(v40[1] * normal.x) + (float)(*(v41 - 1) * normal.y))
                                 + (float)(*v41 * normal.z))
                         - v33) > 0.1 )
              {
                ++v38;
                break;
              }
              if ( (float)((float)((float)((float)(v40[4] * normal.x) + (float)(v41[2] * normal.y))
                                 + (float)(v41[3] * normal.z))
                         - v33) > 0.1 )
              {
                v38 += 2;
                break;
              }
              if ( (float)((float)((float)((float)(v40[7] * normal.x) + (float)(v41[5] * normal.y))
                                 + (float)(v41[6] * normal.z))
                         - v33) > 0.1 )
              {
                v38 += 3;
                break;
              }
              v38 += 4;
              v40 += 12;
              v41 += 12;
              v24 = b;
              if ( v38 >= v37 - 3 )
                goto LABEL_58;
            }
LABEL_66:
            v42 = v38 == v37;
          }
          if ( !v42 )
            goto LABEL_70;
          v34 = (_DWORD *)j;
          goto LABEL_69;
        }
LABEL_70:
        if ( k == v50 )
        {
          if ( v63->nummapbrushsides == 0x10000 )
          {
            _Error(
              a1: "Brush %i: %s\nSide %i\nTexture: %s\n",
              g_MapError.m_brushID,
              "MAX_MAP_BRUSHSIDES",
              g_MapError.m_sideIndex,
              g_MapError.m_textureName);
            v33 = dist;
          }
          v44 = v63;
          ++v63->nummapbrushsides;
          v45 = (int)&v24->original_sides[v24->numsides];
          *(_DWORD *)v45 = CMapFile::FindFloatPlane(this: v44, &normal, dist: LODWORD(v33));
          *(_DWORD *)(v45 + 4) = v24->original_sides->texinfo;
          *(_DWORD *)(v45 + 20) = v24->original_sides->contents;
          *(_BYTE *)(v45 + 30) = 1;
          ++*(_DWORD *)((char *)&unk_139102C + (_DWORD)v44);
          ++v24->numsides;
        }
      }
      v25 = dir + 2;
      dir = v25;
      if ( v25 > 1 )
      {
        p_vec2 = (Vector *)((char *)p_vec2 + 4);
        if ( --v53 == 0 )
          goto LABEL_76;
        v24 = b;
        dir = -1;
        v25 = -1;
      }
    }
  }
LABEL_78:
  if ( sidetemp.aWaterOverlayIds.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = sidetemp.aWaterOverlayIds.m_Memory.m_pMemory;
    if ( sidetemp.aWaterOverlayIds.m_Memory.m_pMemory != nullptr )
    {
      v14 = _g_pMemAlloc;
      goto LABEL_81;
    }
  }
LABEL_82:
  if ( sidetemp.aOverlayIds.m_Memory.m_nGrowSize >= 0 && sidetemp.aOverlayIds.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sidetemp.aOverlayIds.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0041DDB0
// Name: LoadOverlayDataTransitionCallback
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadOverlayDataTransitionCallback(CChunkFile *pFile)
{
  mapoverlay_t *v1; // eax

  v1 = &g_aMapWaterOverlays.m_Memory.m_pMemory[CUtlVector<mapoverlay_t,CUtlMemory<mapoverlay_t,int>>::InsertBefore(
                                                 this: &g_aMapWaterOverlays,
                                                 elem: g_aMapWaterOverlays.m_Size)];
  if ( v1 == nullptr )
    return ChunkFile_Fail;
  v1->nId = g_aMapWaterOverlays.m_Size + 512;
  v1->m_nRenderOrder = 0;
  return CChunkFile::ReadChunk(
           this: pFile,
           pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))LoadOverlayDataTransitionKeyCallback,
           pData: v1);
}

//------------------------------------------------------------------------------
// Address: 0x0041DE00
// Name: LoadOverlayTransitionCallback
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadOverlayTransitionCallback(CChunkFile *pFile)
{
  ChunkFileResult_t Chunk; // edi
  CChunkHandlerMap Handlers; // [esp+8h] [ebp-Ch] BYREF

  CExpressionEvaluator::CExpressionEvaluator(this: (CExpressionEvaluator *)&Handlers);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "overlaydata",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))LoadOverlayDataTransitionCallback,
    pData: nullptr);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &Handlers);
  Chunk = CChunkFile::ReadChunk(this: pFile, pfnKeyHandler: nullptr, pData: nullptr);
  CChunkFile::PopHandlers(this: pFile);
  CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
  return Chunk;
}

//------------------------------------------------------------------------------
// Address: 0x0041DE60
// Name: protected: virtual enum ChunkFileResult_t CSyncMesh_SaveLoadHandler::OnFileDataLoaded(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSyncMesh_SaveLoadHandler::OnFileDataLoaded(CSyncMesh_SaveLoadHandler *this, CUtlBuffer *bufData)
{
  int v3; // esi
  const char *v5; // esi
  char sSaveFileName[260]; // [esp+Ch] [ebp-13Ch] BYREF
  const char *arrNames[7]; // [esp+110h] [ebp-38h]
  const char *arrFiles[7]; // [esp+12Ch] [ebp-1Ch]

  arrFiles[0] = ".ma";
  arrFiles[1] = ".dmx";
  arrFiles[2] = ".mdl";
  arrFiles[3] = aVvd;
  arrFiles[4] = ".dx90.vtx";
  arrFiles[5] = ".phy";
  arrFiles[6] = ".ss2";
  arrNames[0] = "maa";
  arrNames[1] = "dmx";
  arrNames[2] = "mdl";
  arrNames[3] = "vvd";
  arrNames[4] = "vtx";
  arrNames[5] = "phy";
  arrNames[6] = "ss2";
  v3 = 0;
  while ( _V_stricmp(s1: this->m_hLoadHeader.sPrefix, s2: arrNames[v3]) != 0 )
  {
    if ( (unsigned int)++v3 >= 7 )
      return 1;
  }
  v5 = arrFiles[v3];
  if ( v5 == nullptr )
    return 1;
  memset(sSaveFileName, 0, sizeof(sSaveFileName));
  sprintf(string: sSaveFileName, format: "models/.hammer.mdlcache/%s%s", this->m_hLoadHeader.sHash, v5);
  if ( (_S1 & 1) == 0 )
  {
    _S1 |= 1u;
    s_mgr.__vftable = (CMapDataFilesMgr_vtbl *)&CMapDataFilesMgr::`vftable';
    s_mgr.m_map.m_Vector.m_Memory.m_pMemory = nullptr;
    s_mgr.m_map.m_Vector.m_Memory.m_nAllocationCount = 0;
    s_mgr.m_map.m_Vector.m_Memory.m_nGrowSize = 32;
    s_mgr.m_map.m_Vector.m_Size = 0;
    s_mgr.m_map.m_Vector.m_pElements = nullptr;
    CUtlSymbolTable::CUtlSymbolTable(this: &s_mgr.m_map.m_SymbolTable, growSize: 0, initSize: 32, caseInsensitive: true);
    atexit(func: GetMapDataFilesMgr_::_2_::_dynamic_atexit_destructor_for__s_mgr__);
  }
  s_mgr.RegisterFile(this: &s_mgr, a2: sSaveFileName, a3: bufData);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041DFD0
// Name: public: void CMapFile::MergeInstance(struct entity_t __near *,class CMapFile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFile::MergeInstance(CMapFile *this, entity_t *pInstanceEntity, CMapFile *Instance)
{
  float z; // eax
  __int64 v4; // xmm0_8
  matrix3x4_t mat; // [esp+8h] [ebp-48h] BYREF
  QAngle angles; // [esp+38h] [ebp-18h] BYREF
  Vector OriginOffset; // [esp+44h] [ebp-Ch] BYREF

  z = pInstanceEntity->origin.z;
  v4 = *(_QWORD *)&pInstanceEntity->origin.x;
  ++CMapFile::m_InstanceCount;
  *(_QWORD *)&OriginOffset.x = v4;
  OriginOffset.z = z;
  GameData::BeginMapInstance(this: &GD);
  GetVectorForKey(ent: pInstanceEntity, key: "angles", angle: &angles);
  AngleMatrix(&angles, position: &OriginOffset, matrix: &mat);
  CMapFile::MergePlanes(
    this,
    pInstanceEntity,
    Instance,
    InstanceOrigin: &OriginOffset,
    InstanceAngle: &angles,
    InstanceMatrix: &mat);
  CMapFile::MergeBrushes(
    this,
    pInstanceEntity,
    Instance,
    InstanceOrigin: &OriginOffset,
    InstanceAngle: &angles,
    InstanceMatrix: &mat);
  CMapFile::MergeBrushSides(
    this,
    pInstanceEntity,
    Instance,
    InstanceOrigin: &OriginOffset,
    InstanceAngle: &angles,
    InstanceMatrix: &mat);
  CMapFile::MergeEntities(
    this,
    pInstanceEntity,
    Instance,
    InstanceOrigin: &OriginOffset,
    InstanceAngle: &angles,
    InstanceMatrix: &mat);
  CMapFile::MergeOverlays(
    this,
    pInstanceEntity,
    Instance,
    InstanceOrigin: &OriginOffset,
    InstanceAngle: &angles,
    InstanceMatrix: &mat);
  CMapFile::MergeIOProxy(
    this,
    pInstanceEntity,
    Instance,
    InstanceOrigin: &OriginOffset,
    InstanceAngle: &angles,
    InstanceMatrix: &mat);
}

//------------------------------------------------------------------------------
// Address: 0x0041E0B0
// Name: public: enum ChunkFileResult_t CMapFile::LoadSolidCallback(class CChunkFile __near *,struct LoadEntity_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __thiscall CMapFile::LoadSolidCallback(CMapFile *this, CChunkFile *pFile, LoadEntity_t *pLoadEntity)
{
  mapbrush_t *v4; // esi
  int nBaseContents; // edx
  int nBaseFlags; // eax
  unsigned int v8; // eax
  int v9; // eax
  int v10; // ecx
  float v11; // xmm2_4
  float v12; // xmm1_4
  LoadSide_t SideInfo; // [esp+Ch] [ebp-128h] BYREF
  char string[32]; // [esp+FCh] [ebp-38h] BYREF
  Vector origin; // [esp+11Ch] [ebp-18h]
  CChunkHandlerMap Handlers; // [esp+128h] [ebp-Ch] BYREF
  ChunkFileResult_t eResult; // [esp+13Ch] [ebp+8h]

  if ( this->nummapbrushes == 0x2000 )
    _Error(
      a1: "Brush %i: %s\nSide %i\nTexture: %s\n",
      g_MapError.m_brushID,
      "nummapbrushes == MAX_MAP_BRUSHES",
      g_MapError.m_sideIndex,
      g_MapError.m_textureName);
  v4 = &this->mapbrushes[this->nummapbrushes];
  v4->original_sides = &this->brushsides[this->nummapbrushsides];
  v4->entitynum = *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)this) - 1;
  v4->brushnum = this->nummapbrushes - pLoadEntity->pEntity->firstbrush;
  nBaseContents = pLoadEntity->nBaseContents;
  nBaseFlags = pLoadEntity->nBaseFlags;
  SideInfo.pEntity = pLoadEntity->pEntity;
  memset(&SideInfo.td, 0, 24);
  SideInfo.pBrush = v4;
  SideInfo.nSideIndex = 0;
  SideInfo.nBaseContents = nBaseContents;
  SideInfo.nBaseFlags = nBaseFlags;
  CExpressionEvaluator::CExpressionEvaluator(this: (CExpressionEvaluator *)&Handlers);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "side",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))LoadSideCallback,
    pData: &SideInfo);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &Handlers);
  eResult = CChunkFile::ReadChunk(
              this: pFile,
              pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))LoadSolidKeyCallback,
              pData: v4);
  CChunkFile::PopHandlers(this: pFile);
  if ( eResult != ChunkFile_Ok )
  {
    CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
    return eResult;
  }
  else
  {
    v8 = BrushContents(b: v4);
    v4->contents = v8;
    if ( nodetail != 0 && ((unsigned int)&g_WaterOverlays[7253].aFaces[48] & v8) != 0 && HasDispInfo(pBrush: v4) == 0
      || nowater != 0 && (v4->contents & 0x4030) != 0 )
    {
      goto LABEL_20;
    }
    CMapFile::MakeBrushWindings(this, ob: (winding_t *)v4);
    if ( v4->entitynum == 0 && (v4->contents & 0x30000) != 0 )
    {
      if ( *(int *)((char *)&unk_1391034 + (_DWORD)this) < 0 )
        *(_DWORD *)((char *)&unk_1391034 + (_DWORD)this) = v4->original_sides->texinfo;
      ++*(_DWORD *)((char *)&unk_1391030 + (_DWORD)this);
      v9 = 0;
      if ( v4->numsides > 0 )
      {
        v10 = 0;
        do
        {
          v4->original_sides[v10].texinfo = -1;
          ++v9;
          ++v10;
        }
        while ( v9 < v4->numsides );
      }
    }
    if ( ((unsigned int)&unk_1000000 & v4->contents) != 0 )
    {
      if ( *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)this) == 1 )
        _Error(a1: "Brush %i: origin brushes not allowed in world", v4->id);
      v11 = (float)(v4->mins.z + v4->maxs.z) * 0.5;
      v12 = (float)(v4->mins.y + v4->maxs.y) * 0.5;
      origin.x = (float)(v4->maxs.x + v4->mins.x) * 0.5;
      origin.y = v12;
      origin.z = v11;
      sprintf(string, format: "%i %i %i", (int)origin.x, (int)v12, (int)v11);
      SetKeyValue(
        ent: (entity_t *)((char *)&unk_12E1028 + (_DWORD)this + 44 * v4->entitynum),
        key: "origin",
        value: string,
        bAllowDuplicates: false);
      *(Vector *)((char *)&unk_12E1028 + (_DWORD)this + 44 * v4->entitynum) = origin;
LABEL_20:
      v4->numsides = 0;
      CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
      return ChunkFile_Ok;
    }
    if ( HasDispInfo(pBrush: v4) != 0 )
    {
      DispGetFaceInfo(pBrush: v4);
      v4->numsides = 0;
    }
    else
    {
      CMapFile::AddBrushBevels(this, b: v4);
      ++this->nummapbrushes;
      ++pLoadEntity->pEntity->numbrushes;
    }
    CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
    return ChunkFile_Ok;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041E3C0
// Name: public: void CMapFile::CheckForInstances(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapFile::CheckForInstances(CMapFile *this, const char *pszFileName)
{
  KeyValues *KeyValuesFile; // eax
  KeyValues *v4; // esi
  const char *String; // eax
  const char *v6; // esi
  bool v7; // cc
  entity_t *v8; // edi
  const char *v9; // esi
  CMapFile *v10; // esi
  int v11; // edi
  _DWORD *v12; // esi
  const char *v13; // eax
  char InstancePath[260]; // [esp+4h] [ebp-314h] BYREF
  char FDGPath[260]; // [esp+108h] [ebp-210h] BYREF
  char GameInfoPath[260]; // [esp+20Ch] [ebp-10Ch] BYREF
  int i; // [esp+310h] [ebp-8h]
  bool bFoundInstances; // [esp+317h] [ebp-1h]

  if ( this == g_MainMap )
  {
    g_pFullFileSystem->RelativePathToFullPath(
      this: g_pFullFileSystem,
      a2: "gameinfo.txt",
      a3: "MOD",
      a4: GameInfoPath,
      a5: 260,
      a6: FILTER_NONE,
      a7: nullptr);
    KeyValuesFile = ReadKeyValuesFile(pFilename: GameInfoPath);
    v4 = KeyValuesFile;
    if ( KeyValuesFile != nullptr )
    {
      String = KeyValues::GetString(this: KeyValuesFile, keyName: "InstancePath", defaultValue: nullptr);
      if ( String != nullptr )
        CMapFile::SetInstancePath(pszInstancePath: String);
      v6 = KeyValues::GetString(this: v4, keyName: "GameData", defaultValue: nullptr);
      if ( v6 != nullptr )
      {
        if ( g_pFullFileSystem->RelativePathToFullPath(
               this: g_pFullFileSystem,
               a2: v6,
               a3: "EXECUTABLE_PATH",
               a4: FDGPath,
               a5: 260,
               a6: 0,
               a7: 0) == nullptr
          && g_pFullFileSystem->RelativePathToFullPath(
               this: g_pFullFileSystem,
               a2: v6,
               a3: &defaultValue,
               a4: FDGPath,
               a5: 260,
               a6: 0,
               a7: 0) == nullptr )
        {
          _Msg(a1: "Could not locate GameData file %s\n", v6);
        }
        bFoundInstances = false;
        GameData::Load(this: &GD, pszFilename: FDGPath);
        CMapFile::PreLoadInstances(this, pGD: &GD);
        GameData::BeginInstancing(this: &GD, nPass: 1);
        v7 = *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)this) <= 0;
        i = 0;
        if ( !v7 )
        {
          v8 = (entity_t *)((char *)&unk_12E1028 + (_DWORD)this);
          do
          {
            if ( strcmp(ValueForKey(ent: v8, key: "classname"), "func_instance") == 0 )
            {
              v9 = ValueForKey(ent: v8, key: "file");
              if ( *v9 != 0 )
              {
                if ( CInstancingHelper::ResolveInstancePath(
                       pFileSystem: g_pFullFileSystem,
                       pBaseFilename: pszFileName,
                       pInstanceFilename: v9,
                       pInstanceDirectory: CMapFile::m_InstancePath,
                       pResolvedInstanceFilename: InstancePath,
                       nBufferSize: 260) != 0
                  && LoadMapFile(pszFileName: InstancePath) )
                {
                  CMapFile::MergeInstance(this, pInstanceEntity: v8, Instance: g_LoadingMap);
                  v10 = g_LoadingMap;
                  if ( g_LoadingMap != nullptr )
                  {
                    CMapFile::~CMapFile(this: g_LoadingMap);
                    free(pMem: v10);
                  }
                  bFoundInstances = true;
                }
                else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_GENERAL, a2: 3) != 0 )
                {
                  _LoggingSystem_Log(a1: LOG_GENERAL, a2: 3, a3: "Could not open instance file %s\n", v9);
                }
              }
              v8->numbrushes = 0;
              v8->epairs = nullptr;
            }
            ++v8;
            ++i;
          }
          while ( i < *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)this) );
          if ( bFoundInstances )
            CMapFile::PreLoadInstances(this, pGD: &GD);
        }
        v11 = 0;
        if ( *(int *)((char *)&unk_12E1024 + (_DWORD)this) > 0 )
        {
          v12 = (_DWORD *)((char *)&unk_12E1038 + (_DWORD)this);
          do
          {
            v13 = ValueForKey(ent: (entity_t *)(v12 - 4), key: "classname");
            if ( _V_stricmp(s1: v13, s2: "func_instance_parms") == 0 )
            {
              *v12 = 0;
              v12[1] = 0;
            }
            ++v11;
            v12 += 11;
          }
          while ( v11 < *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)this) );
        }
        g_LoadingMap = this;
      }
      else
      {
        _Msg(a1: "Could not locate 'GameData' key in %s\n", GameInfoPath);
      }
    }
    else
    {
      _Msg(a1: "Could not locate gameinfo.txt for Instance Remapping at %s\n", GameInfoPath);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041E6A0
// Name: enum ChunkFileResult_t LoadSolidCallback(class CChunkFile __near *,struct LoadEntity_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadSolidCallback(CChunkFile *pFile, LoadEntity_t *pLoadEntity)
{
  return CMapFile::LoadSolidCallback(this: g_LoadingMap, pFile, pLoadEntity);
}

//------------------------------------------------------------------------------
// Address: 0x0041E6C0
// Name: public: enum ChunkFileResult_t CMapFile::LoadEntityCallback(class CChunkFile __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMapFile::LoadEntityCallback(CMapFile *this, CChunkFile *pFile, int nParam)
{
  CMapFile *v3; // ebx
  bool v4; // zf
  unsigned __int8 *v5; // edi
  const char *v7; // esi
  const char *v8; // eax
  const char *v9; // eax
  int v11; // esi
  mapbrush_t *v12; // eax
  side_t *v13; // esi
  int FloatPlane; // ebx
  bool v15; // cc
  int v16; // esi
  char str[128]; // [esp+10h] [ebp-318h] BYREF
  CSyncMesh_SaveLoadHandler hdlrEntityMeshData; // [esp+90h] [ebp-298h] BYREF
  char buf[16]; // [esp+2E8h] [ebp-40h] BYREF
  LoadEntity_t LoadEntity; // [esp+2F8h] [ebp-30h] BYREF
  int j; // [esp+308h] [ebp-20h]
  int i; // [esp+30Ch] [ebp-1Ch]
  const char *pClassName; // [esp+310h] [ebp-18h]
  mapbrush_t *b; // [esp+314h] [ebp-14h]
  CMapFile *v25; // [esp+318h] [ebp-10h]
  CChunkHandlerMap Handlers; // [esp+31Ch] [ebp-Ch] BYREF
  ChunkFileResult_t eResulta; // [esp+330h] [ebp+8h]
  ChunkFileResult_t eResult; // [esp+330h] [ebp+8h]

  v3 = this;
  v4 = *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)this) == 0x4000;
  v25 = this;
  if ( v4 )
    _Error(
      a1: "Brush %i: %s\nSide %i\nTexture: %s\n",
      g_MapError.m_brushID,
      "num_entities == MAX_MAP_ENTITIES",
      g_MapError.m_sideIndex,
      g_MapError.m_textureName);
  v5 = (unsigned __int8 *)&byte_12E1028[(_DWORD)v3 + 44 * (*(_DWORD *)((char *)&unk_12E1024 + (_DWORD)v3))++];
  memset(dst: v5, value: 0, count: 0x2Cu);
  *((_DWORD *)v5 + 3) = v3->nummapbrushes;
  *((_DWORD *)v5 + 4) = 0;
  LoadEntity.pEntity = (entity_t *)v5;
  LoadEntity.nBaseFlags = 0;
  LoadEntity.nBaseContents = 0;
  CExpressionEvaluator::CExpressionEvaluator(this: (CExpressionEvaluator *)&Handlers);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "solid",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))LoadSolidCallback,
    pData: &LoadEntity);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "connections",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))LoadConnectionsCallback,
    pData: &LoadEntity);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "overlaytransition",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))LoadOverlayTransitionCallback,
    pData: nullptr);
  CVmfMeshDataSupport_SaveLoadHandler::CVmfMeshDataSupport_SaveLoadHandler(this: &hdlrEntityMeshData);
  hdlrEntityMeshData.__vftable = (CSyncMesh_SaveLoadHandler_vtbl *)&CSyncMesh_SaveLoadHandler::`vftable';
  VmfInstallMapEntitySaveLoadHandler(pHandler: &hdlrEntityMeshData);
  VmfAddMapEntityHandlers(pHandlerMap: &Handlers, pEntity: nullptr);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &Handlers);
  eResulta = CChunkFile::ReadChunk(
               this: pFile,
               pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))LoadEntityKeyCallback,
               pData: &LoadEntity);
  CChunkFile::PopHandlers(this: pFile);
  VmfUninstallMapEntitySaveLoadHandler(pHandler: &hdlrEntityMeshData);
  v7 = (const char *)eResulta;
  if ( eResulta == ChunkFile_Ok )
  {
    GetVectorForKey(ent: (entity_t *)v5, key: "origin", angle: (QAngle *)v5);
    v8 = ValueForKey(ent: (entity_t *)v5, key: "classname");
    pClassName = v8;
    if ( g_bConvertStructureToDetail && _V_strcmp(s1: "func_brush", s2: v8) == 0 )
    {
      v9 = ValueForKey(ent: (entity_t *)v5, key: "targetname");
      if ( V_strncmp(s1: v9, s2: "structure_", count: 10) == 0 )
        goto LABEL_7;
    }
    if ( *(float *)v5 != 0.0 || *((float *)v5 + 1) != 0.0 || *((float *)v5 + 2) != 0.0 )
    {
      v11 = 0;
      for ( i = 0; v11 < *((_DWORD *)v5 + 4); i = v11 )
      {
        v12 = &v3->mapbrushes[v11 + *((_DWORD *)v5 + 3)];
        b = v12;
        j = 0;
        if ( v12->numsides > 0 )
        {
          eResult = ChunkFile_Ok;
          do
          {
            v13 = &v12->original_sides[eResult];
            FloatPlane = CMapFile::FindFloatPlane(
                           this: v3,
                           normal: &v3->mapplanes[v13->planenum].normal,
                           dist: COERCE_UNSIGNED_INT(
                             v3->mapplanes[v13->planenum].dist
                           - (float)((float)((float)(v3->mapplanes[v13->planenum].normal.y * *((float *)v5 + 1))
                                           + (float)(v3->mapplanes[v13->planenum].normal.x * *(float *)v5))
                                   + (float)(v3->mapplanes[v13->planenum].normal.z * *((float *)v5 + 2)))));
            v13->planenum = FloatPlane;
            if ( onlyents == 0 )
              v13->texinfo = TexinfoForBrushTexture(
                               plane: &v25->mapplanes[FloatPlane],
                               bt: (brush_texture_t *)&byte_7A1024[(_DWORD)v25
                                                             + 180 * (((char *)v13 - (char *)v25 - 1970212) / 92)],
                               origin: (const Vector *)v5);
            ++eResult;
            v3 = v25;
            v15 = ++j < b->numsides;
            v12 = b;
          }
          while ( v15 );
          v11 = i;
        }
        CMapFile::MakeBrushWindings(this: v3, ob: (winding_t *)v12);
        ++v11;
      }
    }
    if ( strcmp("func_detail", pClassName) == 0 )
    {
LABEL_7:
      CMapFile::MoveBrushesToWorld(this: v3, mapent: (entity_t *)v5);
      *((_DWORD *)v5 + 4) = 0;
      *((_DWORD *)v5 + 5) = 0;
LABEL_8:
      CVmfMeshDataSupport_SaveLoadHandler::~CVmfMeshDataSupport_SaveLoadHandler(this: &hdlrEntityMeshData);
      CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
      return nullptr;
    }
    if ( strcmp("func_viscluster", pClassName) == 0 )
    {
      AddVisCluster(pFuncVisCluster: (entity_t *)v5);
      goto LABEL_8;
    }
    if ( strcmp("func_ladder", pClassName) == 0 )
    {
      CMapFile::AddLadderKeys(this: v3, mapent: (entity_t *)v5);
      SetKeyValue(ent: (entity_t *)v5, key: "classname", value: "func_simpleladder", bAllowDuplicates: false);
      goto LABEL_8;
    }
    if ( strcmp("test_sidelist", pClassName) == 0 )
    {
      ConvertSideList(mapent: (entity_t *)v5, key: "sides");
      goto LABEL_8;
    }
    if ( strcmp("info_overlay", pClassName) == 0 )
    {
      v16 = Overlay_GetFromEntity(pMapEnt: (entity_t *)v5);
      if ( v16 >= 0 )
      {
        SetKeyValue(ent: (entity_t *)v5, key: "classname", value: "info_overlay_accessor", bAllowDuplicates: false);
        V_snprintf(pDest: buf, maxLen: 16, pFormat: "%i", v16);
        SetKeyValue(ent: (entity_t *)v5, key: "OverlayID", value: buf, bAllowDuplicates: false);
        goto LABEL_8;
      }
      goto LABEL_29;
    }
    if ( strcmp("info_overlay_transition", pClassName) == 0 )
    {
LABEL_29:
      *((_DWORD *)v5 + 5) = 0;
      goto LABEL_8;
    }
    if ( _V_stricmp(s1: pClassName, s2: "info_no_dynamic_shadow") != 0 )
    {
      if ( IsAreaPortal(pClassName) )
      {
        if ( *((_DWORD *)v5 + 4) != 1 )
          _Error(
            a1: "Entity %i: func_areaportal can only be a single brush",
            *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)v3) - 1);
        v3->planehash[12 * v3->nummapbrushes + 1016] = (plane_t *)0x8000;
        *((_DWORD *)v5 + 6) = ++CMapFile::c_areaportals;
        sprintf(string: str, format: "%i", CMapFile::c_areaportals);
        SetKeyValue(ent: (entity_t *)v5, key: "portalnumber", value: str, bAllowDuplicates: false);
        CMapFile::MoveBrushesToWorld(this: v3, mapent: (entity_t *)v5);
      }
      else if ( v5 != (unsigned __int8 *)&byte_12E1028[(_DWORD)v3] )
      {
        CMapFile::RemoveContentsDetailFromEntity(this: v3, mapent: (entity_t *)v5);
      }
      goto LABEL_8;
    }
    v7 = HandleNoDynamicShadowsEnt(pMapEnt: (entity_t *)v5);
  }
  CVmfMeshDataSupport_SaveLoadHandler::~CVmfMeshDataSupport_SaveLoadHandler(this: &hdlrEntityMeshData);
  CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x0041EC80
// Name: enum ChunkFileResult_t LoadEntityCallback(class CChunkFile __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl LoadEntityCallback(CChunkFile *pFile, int nParam)
{
  return CMapFile::LoadEntityCallback(this: g_LoadingMap, pFile, nParam);
}

//------------------------------------------------------------------------------
// Address: 0x0041ECA0
// Name: bool LoadMapFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl LoadMapFile(const char *pszFileName)
{
  __int64 v1; // rdi
  const char *FileExtension; // eax
  CManifest *v3; // eax
  ChunkFileResult_t v4; // ebx
  ChunkFileResult_t v5; // eax
  CMapFile *v6; // eax
  CMapFile *v7; // ebx
  int m_Size; // eax
  int v9; // esi
  CMapFile **m_pMemory; // ecx
  int v11; // eax
  CMapFile **v12; // eax
  CMapFile *v13; // ecx
  const char *ErrorText; // eax
  const char *v15; // eax
  CMapFile *v16; // ecx
  int v17; // edi
  CMapFile *v18; // eax
  int v19; // esi
  CChunkFile File; // [esp+3Ch] [ebp-354h] BYREF
  CChunkHandlerMap Handlers; // [esp+380h] [ebp-10h] BYREF
  CManifest *pMainManifest; // [esp+38Ch] [ebp-4h]

  v1 = (unsigned int)pszFileName;
  pMainManifest = nullptr;
  g_nMapFileVersion = 400;
  FileExtension = V_GetFileExtension(path: pszFileName);
  if ( FileExtension != nullptr && _V_stricmp(s1: FileExtension, s2: "vmm") == 0 )
  {
    v3 = (CManifest *)MemAlloc_Alloc(nSize: 0x134u);
    if ( v3 != nullptr )
      HIDWORD(v1) = CManifest::CManifest(this: v3);
    if ( !CManifest::LoadVMFManifest(this: (CManifest *)HIDWORD(v1), pszFileName: (const char *)v1) )
    {
      v4 = ChunkFile_Fail;
      goto LABEL_39;
    }
    v4 = ChunkFile_Ok;
    LODWORD(v1) = HIDWORD(v1) + 20;
    goto LABEL_29;
  }
  CChunkFile::CChunkFile(this: &File);
  v5 = CChunkFile::Open(this: &File, pszFileName, eMode: ChunkFile_Read);
  v4 = v5;
  if ( v5 == ChunkFile_Ok )
  {
    v6 = (CMapFile *)MemAlloc_Alloc(nSize: (unsigned int)&unk_1391044);
    if ( v6 != nullptr )
      v7 = CMapFile::CMapFile(this: v6);
    else
      v7 = nullptr;
    m_Size = g_Maps.m_Size;
    v9 = g_Maps.m_Size;
    if ( g_Maps.m_Size + 1 > g_Maps.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CClassInput *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&g_Maps,
        num: g_Maps.m_Size - g_Maps.m_Memory.m_nAllocationCount + 1);
      m_Size = g_Maps.m_Size;
    }
    m_pMemory = g_Maps.m_Memory.m_pMemory;
    g_Maps.m_Size = m_Size + 1;
    v11 = m_Size - v9;
    g_Maps.m_pElements = g_Maps.m_Memory.m_pMemory;
    if ( v11 > 0 )
    {
      _V_memmove(dest: &g_Maps.m_Memory.m_pMemory[v9 + 1], src: &g_Maps.m_Memory.m_pMemory[v9], count: 4 * v11);
      m_pMemory = g_Maps.m_Memory.m_pMemory;
    }
    v12 = &m_pMemory[v9];
    if ( v12 != nullptr )
    {
      *v12 = v7;
      m_pMemory = g_Maps.m_Memory.m_pMemory;
    }
    v13 = m_pMemory[v9];
    g_LoadingMap = v13;
    if ( g_MainMap != nullptr )
    {
      if ( g_MainMap != v13 && verbose == 0 )
        goto LABEL_23;
    }
    else
    {
      g_MainMap = v13;
    }
    _Msg(a1: "Loading %s\n", pszFileName);
LABEL_23:
    CExpressionEvaluator::CExpressionEvaluator(this: (CExpressionEvaluator *)&Handlers);
    CChunkHandlerMap::AddHandler(
      this: &Handlers,
      pszChunkName: "world",
      pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))LoadEntityCallback,
      pData: nullptr);
    CChunkHandlerMap::AddHandler(
      this: &Handlers,
      pszChunkName: "entity",
      pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))LoadEntityCallback,
      pData: nullptr);
    CChunkFile::PushHandlers(this: &File, pHandlerMap: &Handlers);
    do
      v4 = CChunkFile::ReadChunk(this: &File, pfnKeyHandler: nullptr, pData: nullptr);
    while ( v4 == ChunkFile_Ok );
    CChunkFile::PopHandlers(this: &File);
    CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
    goto LABEL_27;
  }
  ErrorText = CChunkFile::GetErrorText(this: &File, eResult: v5);
  _Error(a1: "Error opening %s: %s.\n", pszFileName, ErrorText);
  v15 = CChunkFile::GetErrorText(this: &File, eResult: v4);
  _Error(
    a1: "Brush %i: %s\nSide %i\nTexture: %s\n",
    g_MapError.m_brushID,
    v15,
    g_MapError.m_sideIndex,
    g_MapError.m_textureName);
LABEL_27:
  CChunkFile::~CChunkFile(this: &File);
  if ( v4 != ChunkFile_EOF )
    goto LABEL_39;
  HIDWORD(v1) = pMainManifest;
LABEL_29:
  Overlay_UpdateSideLists(StartIndex: *(_DWORD *)((char *)&unk_139103C + (_DWORD)g_LoadingMap));
  OverlayTransition_UpdateSideLists(StartIndex: *(_DWORD *)((char *)&unk_1391040 + (_DWORD)g_LoadingMap));
  CMapFile::CheckForInstances(this: g_LoadingMap, pszFileName: (const char *)v1);
  v16 = g_LoadingMap;
  if ( g_LoadingMap == g_MainMap )
  {
    CMapFile::PostLoadInstances(this: g_LoadingMap);
    v16 = g_LoadingMap;
  }
  if ( HIDWORD(v1) != 0 )
  {
    CManifest::CordonWorld(this: (CManifest *)HIDWORD(v1));
    v16 = g_LoadingMap;
  }
  ClearBounds(mins: &v16->map_mins, maxs: &v16->map_maxs);
  v17 = 0;
  v18 = g_LoadingMap;
  if ( *(int *)((char *)&unk_12E1038 + (_DWORD)g_MainMap) > 0 )
  {
    v19 = 0;
    do
    {
      if ( v18->mapbrushes[v19].mins.x <= 16384.0 )
      {
        AddPointToBounds(v: &v18->mapbrushes[v19].mins, mins: &v18->map_mins, maxs: &v18->map_maxs);
        AddPointToBounds(
          v: &g_LoadingMap->mapbrushes[v19].maxs,
          mins: &g_LoadingMap->map_mins,
          maxs: &g_LoadingMap->map_maxs);
        v18 = g_LoadingMap;
      }
      ++v17;
      ++v19;
    }
    while ( v17 < *(_DWORD *)((char *)&unk_12E1038 + (_DWORD)g_MainMap) );
  }
  qprintf(format: "%5i brushes\n", v18->nummapbrushes);
  qprintf(format: "%5i clipbrushes\n", *(_DWORD *)((char *)&unk_1391030 + (_DWORD)g_LoadingMap));
  qprintf(format: "%5i total sides\n", g_LoadingMap->nummapbrushsides);
  qprintf(format: "%5i boxbevels\n", *(_DWORD *)((char *)&unk_1391028 + (_DWORD)g_LoadingMap));
  qprintf(format: "%5i edgebevels\n", *(_DWORD *)((char *)&unk_139102C + (_DWORD)g_LoadingMap));
  qprintf(format: "%5i entities\n", *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)g_LoadingMap));
  qprintf(format: "%5i planes\n", g_LoadingMap->nummapplanes);
  qprintf(format: "%5i areaportals\n", CMapFile::c_areaportals);
  qprintf(
    format: "size: %5.0f,%5.0f,%5.0f to %5.0f,%5.0f,%5.0f\n",
    g_LoadingMap->map_mins.x,
    g_LoadingMap->map_mins.y,
    g_LoadingMap->map_mins.z,
    g_LoadingMap->map_maxs.x,
    g_LoadingMap->map_maxs.y,
    g_LoadingMap->map_maxs.z);
  g_MapError.m_brushID = 0;
  g_MapError.m_sideIndex = 0;
  V_strncpy(pDest: g_MapError.m_textureName, pSrc: "Not a Parse error!", maxLen: 80);
LABEL_39:
  if ( g_MainMap == g_LoadingMap )
  {
    num_entities = *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)g_MainMap);
    memcpy(dst: (unsigned __int8 *)&entities, src: (unsigned __int8 *)&byte_12E1028[(_DWORD)g_MainMap], count: 0xB0000u);
  }
  CMapFile::ForceFuncAreaPortalWindowContents(this: g_LoadingMap);
  return v4 == ChunkFile_Ok || v4 == ChunkFile_EOF;
}
