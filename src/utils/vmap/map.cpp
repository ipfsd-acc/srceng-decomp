// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmap/map.cpp
// Functions: 47
// ============================================================

#include "utils\vmap\map.h"

//------------------------------------------------------------------------------
// Address: 0x00423710
// Name: public: void CMapError::ReportError(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapError::ReportError(CMapError *this, const char *pErrorString)
{
  _Error(
    a1: "Brush %i: %s\nSide %i\nTexture: %s\n",
    this->m_brushID,
    pErrorString,
    this->m_sideIndex,
    this->m_textureName);
}

//------------------------------------------------------------------------------
// Address: 0x00423740
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
// Address: 0x004237F0
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
// Address: 0x00423890
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
// Address: 0x00423A00
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
// Address: 0x00423A30
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
// Address: 0x00423AB0
// Name: int MakeBrushWindings(struct mapbrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl MakeBrushWindings(winding_t *ob)
{
  mapbrush_t *v1; // ebx
  mapbrush_t *v2; // eax
  int v3; // esi
  int v4; // edi
  side_t *original_sides; // ecx
  side_t *v6; // ecx
  mapbrush_t *v7; // eax
  int v8; // esi
  int v9; // edi
  float *p_x; // esi
  int i; // [esp+14h] [ebp-8h]
  int ia; // [esp+14h] [ebp-8h]
  int v14; // [esp+18h] [ebp-4h]

  v1 = (mapbrush_t *)ob;
  ClearBounds(mins: (Vector *)&ob[1], maxs: (Vector *)&ob[1].next);
  i = 0;
  if ( v1->numsides > 0 )
  {
    v14 = 0;
    do
    {
      v2 = (mapbrush_t *)BaseWindingForPlane(
                           normal: &mapplanes + 2 * v1->original_sides[v14].planenum,
                           dist: *(&dist + 6 * v1->original_sides[v14].planenum));
      v3 = 0;
      ob = (winding_t *)v2;
      if ( v1->numsides > 0 )
      {
        v4 = 0;
        do
        {
          if ( v2 == nullptr )
            break;
          if ( i != v3 )
          {
            original_sides = v1->original_sides;
            if ( original_sides[v4].bevel == 0 )
            {
              ChopWindingInPlace(
                inout: &ob,
                normal: &mapplanes + 2 * (original_sides[v4].planenum ^ 1),
                dist: *((float *)&mapplanes + 6 * (original_sides[v4].planenum ^ 1) + 3),
                epsilon: 0.0099999998);
              v2 = (mapbrush_t *)ob;
            }
          }
          ++v3;
          ++v4;
        }
        while ( v3 < v1->numsides );
      }
      v6 = &v1->original_sides[v14];
      v6->winding = (winding_t *)v2;
      if ( ob != nullptr )
      {
        v6->visible = 1;
        v7 = (mapbrush_t *)ob;
        v8 = 0;
        if ( ob->numpoints > 0 )
        {
          v9 = 0;
          do
          {
            AddPointToBounds(v: (const Vector *)(v9 + v7->brushnum), mins: &v1->mins, maxs: &v1->maxs);
            v7 = (mapbrush_t *)ob;
            ++v8;
            v9 += 12;
          }
          while ( v8 < ob->numpoints );
        }
      }
      ++v14;
      ++i;
    }
    while ( i < v1->numsides );
  }
  p_x = &v1->maxs.x;
  for ( ia = 3; ia != 0; --ia )
  {
    if ( *(p_x - 3) < -16384.0 || *p_x > 16384.0 )
      _Msg(a1: "Brush %i: bounds out of range\n", v1->id);
    if ( *(p_x - 3) > 16384.0 || *p_x < -16384.0 )
      _Msg(a1: "Brush %i: no visible sides on brush\n", v1->id);
    ++p_x;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00423C50
// Name: void MoveBrushesToWorld(struct entity_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MoveBrushesToWorld(entity_t *mapent)
{
  int v1; // ebx
  int numbrushes; // esi
  int *p_firstbrush; // eax
  int v4; // ecx
  unsigned __int8 *temp; // [esp+10h] [ebp-4h]

  v1 = unk_5CD4960;
  numbrushes = mapent->numbrushes;
  temp = (unsigned __int8 *)MemAlloc_Alloc(nSize: 48 * numbrushes);
  memcpy(dst: temp, src: (unsigned __int8 *)&mapbrushes[mapent->firstbrush], count: 48 * numbrushes);
  memmove(
    dst: (unsigned __int8 *)&mapbrushes[numbrushes + v1],
    src: (unsigned __int8 *)&mapbrushes[v1],
    count: 48 * (nummapbrushes - v1 - numbrushes));
  memcpy(dst: (unsigned __int8 *)&mapbrushes[v1], src: temp, count: 48 * numbrushes);
  unk_5CD4960 += numbrushes;
  if ( num_entities > 1 )
  {
    p_firstbrush = &ent.firstbrush;
    v4 = num_entities - 1;
    do
    {
      *p_firstbrush += numbrushes;
      p_firstbrush += 11;
      --v4;
    }
    while ( v4 != 0 );
  }
  free(pMem: temp);
  mapent->numbrushes = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00423D20
// Name: void RemoveContentsDetailFromEntity(struct entity_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemoveContentsDetailFromEntity(entity_t *mapent)
{
  int i; // edi
  mapbrush_t *v2; // eax
  int v3; // esi
  int *p_contents; // edx

  for ( i = 0; i < mapent->numbrushes; ++i )
  {
    v2 = &mapbrushes[i + mapent->firstbrush];
    v3 = 0;
    if ( v2->numsides > 0 )
    {
      p_contents = &v2->original_sides->contents;
      do
      {
        if ( (*p_contents & 0x8000000) != 0 )
          *p_contents &= ~0x8000000u;
        ++v3;
        p_contents += 25;
      }
      while ( v3 < v2->numsides );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00423D80
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
// Address: 0x00423E30
// Name: enum ChunkFileResult_t LoadDispInfoKeyCallback(char const __near *,char const __near *,struct mapdispinfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadDispInfoKeyCallback(const char *szKey, const char *szValue, mapdispinfo_t *pMapDispInfo)
{
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
            CChunkFile::ReadKeyValueInt(pszValue: szValue, nInt: &pMapDispInfo->flags);
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
// Address: 0x00423F70
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
// Address: 0x00424080
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
// Address: 0x00424190
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
// Address: 0x00424240
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
// Address: 0x00424330
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
  int v7; // eax
  int *p_id; // ecx
  char *v9; // edi
  char v10; // cl
  unsigned int v11; // eax
  char *v12; // edi
  char v13; // cl
  char v14[11]; // [esp+0h] [ebp-420h] BYREF
  char v15; // [esp+Bh] [ebp-415h] BYREF
  char szNewValue[1024]; // [esp+Ch] [ebp-414h] BYREF
  char szIndex[16]; // [esp+40Ch] [ebp-14h] BYREF
  int nSideID; // [esp+41Ch] [ebp-4h] BYREF

  v2 = ValueForKey(ent: mapent, key);
  v3 = v2;
  if ( v2 != nullptr )
  {
    v4 = alloca(strlen(v2) + 1);
    strcpy(v14, v3);
    v5 = 1;
    szNewValue[0] = 0;
    v6 = strtok(string: v14, control: " ");
    if ( v6 != nullptr )
    {
      do
      {
        if ( sscanf(string: v6, format: "%d", &nSideID) == 1 )
        {
          v7 = 0;
          if ( nummapbrushsides > 0 )
          {
            p_id = &brushsides[0].id;
            while ( *p_id != nSideID )
            {
              ++v7;
              p_id += 25;
              if ( v7 >= nummapbrushsides )
                goto LABEL_18;
            }
            if ( v7 != -1 )
            {
              if ( v5 != 0 )
              {
                v5 = 0;
              }
              else
              {
                v9 = &v15;
                do
                  v10 = *++v9;
                while ( v10 != 0 );
                strcpy(v9, " ");
              }
              itoa(val: v7, buf: szIndex, radix: 10);
              v11 = strlen(szIndex) + 1;
              v12 = &v15;
              do
                v13 = *++v12;
              while ( v13 != 0 );
              qmemcpy(v12, szIndex, v11);
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
// Address: 0x00424490
// Name: void AddLadderKeys(struct entity_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddLadderKeys(entity_t *mapent)
{
  int i; // ebx
  mapbrush_t *v2; // esi
  char buf[16]; // [esp+10h] [ebp-28h] BYREF
  Vector maxs; // [esp+20h] [ebp-18h] BYREF
  Vector mins; // [esp+2Ch] [ebp-Ch] BYREF

  ClearBounds(&mins, &maxs);
  for ( i = 0; i < mapent->numbrushes; ++i )
  {
    v2 = &mapbrushes[i + mapent->firstbrush];
    AddPointToBounds(v: &v2->mins, &mins, &maxs);
    AddPointToBounds(v: &v2->maxs, &mins, &maxs);
  }
  V_snprintf(pDest: buf, maxLen: 16, pFormat: "%2.2f", mins.x);
  SetKeyValue(ent: mapent, key: "mins.x", value: buf, bAllowDuplicates: false);
  V_snprintf(pDest: buf, maxLen: 16, pFormat: "%2.2f", mins.y);
  SetKeyValue(ent: mapent, key: "mins.y", value: buf, bAllowDuplicates: false);
  V_snprintf(pDest: buf, maxLen: 16, pFormat: "%2.2f", mins.z);
  SetKeyValue(ent: mapent, key: "mins.z", value: buf, bAllowDuplicates: false);
  V_snprintf(pDest: buf, maxLen: 16, pFormat: "%2.2f", maxs.x);
  SetKeyValue(ent: mapent, key: "maxs.x", value: buf, bAllowDuplicates: false);
  V_snprintf(pDest: buf, maxLen: 16, pFormat: "%2.2f", maxs.y);
  SetKeyValue(ent: mapent, key: "maxs.y", value: buf, bAllowDuplicates: false);
  V_snprintf(pDest: buf, maxLen: 16, pFormat: "%2.2f", maxs.z);
  SetKeyValue(ent: mapent, key: "maxs.z", value: buf, bAllowDuplicates: false);
}

//------------------------------------------------------------------------------
// Address: 0x00424620
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
// Address: 0x00424630
// Name: public: virtual char const __near * CSyncMesh_SaveLoadHandler::GetCustomSectionName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CSyncMesh_SaveLoadHandler::GetCustomSectionName(CSyncMesh_SaveLoadHandler *this)
{
  return "meshdata";
}

//------------------------------------------------------------------------------
// Address: 0x00424640
// Name: struct entity_t __near * EntityByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
entity_t *__cdecl EntityByName(const char *pTestName)
{
  int v2; // edi
  entity_t *i; // esi
  const char *v4; // eax

  if ( pTestName == nullptr )
    return nullptr;
  v2 = 0;
  if ( num_entities <= 0 )
    return nullptr;
  for ( i = (entity_t *)&entities; ; ++i )
  {
    v4 = ValueForKey(ent: i, key: "targetname");
    if ( _V_stricmp(s1: v4, s2: pTestName) == 0 )
      break;
    if ( ++v2 >= num_entities )
      return nullptr;
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x004246A0
// Name: void ForceFuncAreaPortalWindowContents(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ForceFuncAreaPortalWindowContents()
{
  int v0; // ebx
  entity_t *v1; // edi
  const char *v2; // eax
  const char *v3; // ecx
  char v4; // dl
  int i; // esi
  const char *v6; // eax
  entity_t *v7; // eax
  int j; // edx
  char *targets[2]; // [esp+4h] [ebp-8h]

  v0 = 0;
  targets[0] = "target";
  targets[1] = "BackgroundBModel";
  if ( num_entities > 0 )
  {
    v1 = (entity_t *)&entities;
    do
    {
      v2 = ValueForKey(ent: v1, key: "classname");
      v3 = "func_areaportal";
      while ( 1 )
      {
        v4 = v3[v2 - "func_areaportal"];
        if ( v4 == 0 || *v3 != v4 )
          break;
        if ( *++v3 == 0 )
          goto LABEL_9;
      }
      if ( *v3 != 0 )
        goto LABEL_16;
LABEL_9:
      if ( _V_stricmp(s1: v2, s2: "func_areaportal") != 0 )
      {
        for ( i = 0; i < 2; ++i )
        {
          v6 = ValueForKey(ent: v1, key: targets[i]);
          if ( *v6 != 0 )
          {
            v7 = EntityByName(pTestName: v6);
            if ( v7 != nullptr )
            {
              for ( j = 0; j < v7->numbrushes; ++j )
              {
                mapbrushes[j + v7->firstbrush].contents &= ~1u;
                mapbrushes[j + v7->firstbrush].contents |= 0x10000002u;
              }
            }
          }
        }
      }
LABEL_16:
      ++v0;
      ++v1;
    }
    while ( v0 < num_entities );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004247A0
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
// Address: 0x00424AC0
// Name: enum ChunkFileResult_t LoadConnectionsKeyCallback(char const __near *,char const __near *,struct LoadEntity_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadConnectionsKeyCallback(const char *szKey, const char *szValue, LoadEntity_t *pLoadEntity)
{
  epair_t *v3; // esi
  char *v4; // eax
  char *key; // edx
  const char *v6; // ecx
  char v7; // al
  char *value; // edx
  const char *v9; // ecx
  char v10; // al
  epair_t *epairs; // ecx
  epair_t *i; // eax

  v3 = (epair_t *)MemAlloc_Alloc(nSize: 0xCu);
  v3->key = (char *)MemAlloc_Alloc(nSize: strlen(szKey) + 1);
  v4 = (char *)MemAlloc_Alloc(nSize: strlen(szValue) + 1);
  key = v3->key;
  v3->value = v4;
  v6 = szKey;
  do
  {
    v7 = *v6;
    *key++ = *v6++;
  }
  while ( v7 != 0 );
  value = v3->value;
  v9 = szValue;
  do
  {
    v10 = *v9;
    *value++ = *v9++;
  }
  while ( v10 != 0 );
  v3->next = nullptr;
  epairs = pLoadEntity->pEntity->epairs;
  if ( epairs != nullptr )
  {
    for ( i = epairs->next; i != nullptr; i = i->next )
      epairs = i;
    epairs->next = v3;
    return ChunkFile_Ok;
  }
  else
  {
    pLoadEntity->pEntity->epairs = v3;
    return ChunkFile_Ok;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424B70
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
// Address: 0x00424BB0
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
// Address: 0x00424BD0
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
// Address: 0x00424BF0
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
// Address: 0x00424C10
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
// Address: 0x00424C30
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
// Address: 0x00424C50
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
// Address: 0x00424D10
// Name: int CreateNewFloatPlane(class Vector __near &,float)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CreateNewFloatPlane(Vector *normal, float dist)
{
  int v2; // edx
  Vector *v3; // esi
  double z; // st7
  int v5; // eax
  float x; // xmm0_4
  plane_t *v7; // ecx
  int y_low; // eax
  int v9; // edx
  float v10; // xmm0_4
  float y; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // edx
  int v15; // eax
  plane_t *v16; // edx
  int v17; // eax
  plane_t *v18; // edx
  int result; // eax
  int v20; // eax
  plane_t *v21; // edx
  int v22; // eax
  plane_t *v23; // edx

  if ( fsqrt((float)((float)(normal->x * normal->x) + (float)(normal->y * normal->y)) + (float)(normal->z * normal->z)) < 0.5 )
    _Error(
      a1: "Brush %i: %s\nSide %i\nTexture: %s\n",
      g_MapError.m_brushID,
      "FloatPlane: bad normal",
      g_MapError.m_sideIndex,
      g_MapError.m_textureName);
  v2 = nummapplanes;
  if ( nummapplanes + 2 > 0x10000 )
  {
    _Error(
      a1: "Brush %i: %s\nSide %i\nTexture: %s\n",
      g_MapError.m_brushID,
      "MAX_MAP_PLANES",
      g_MapError.m_sideIndex,
      g_MapError.m_textureName);
    v2 = nummapplanes;
  }
  v3 = &mapplanes + 2 * v2;
  v3->x = normal->x;
  v3->y = normal->y;
  z = normal->z;
  v3[1].x = dist;
  v3->z = z;
  v5 = PlaneTypeForNormal(normal: v3);
  x = vec3_origin.x;
  LODWORD(v3[3].y) = v5;
  LODWORD(v3[1].y) = v5;
  v3[2].x = x - normal->x;
  v7 = (plane_t *)&v3[2];
  v3[2].y = vec3_origin.y - normal->y;
  v3[2].z = vec3_origin.z - normal->z;
  y_low = LODWORD(v3[1].y);
  LODWORD(v3[3].x) = LODWORD(dist) ^ _mask__NegFloat_;
  nummapplanes = v9 + 2;
  if ( y_low >= 3 || v3->x >= 0.0 && v3->y >= 0.0 && v3->z >= 0.0 )
  {
    v20 = ((int)COERCE_FLOAT(LODWORD(v3[1].x) & _mask__AbsFloat_) / 8) & 0x3FF;
    v21 = planehash[v20];
    planehash[v20] = (plane_t *)v3;
    LODWORD(v3[1].z) = v21;
    v22 = ((int)COERCE_FLOAT(LODWORD(v3[3].x) & _mask__AbsFloat_) / 8) & 0x3FF;
    v23 = planehash[v22];
    planehash[v22] = v7;
    result = nummapplanes - 2;
    LODWORD(v3[3].z) = v23;
  }
  else
  {
    v10 = v3->x;
    y = v3->y;
    v3->x = v7->normal.x;
    v12 = v3->z;
    v13 = v3[1].x;
    v3->y = v3[2].y;
    v14 = v3[1].z;
    v3->z = v3[2].z;
    v3[1].x = v3[3].x;
    v3[1].y = v3[3].y;
    LODWORD(v3[3].y) = y_low;
    v3[3].z = v14;
    v3[2].y = y;
    v7->normal.x = v10;
    v3[2].z = v12;
    v3[3].x = v13;
    v15 = ((int)COERCE_FLOAT(LODWORD(v3[1].x) & _mask__AbsFloat_) / 8) & 0x3FF;
    v16 = planehash[v15];
    planehash[v15] = (plane_t *)v3;
    LODWORD(v3[1].z) = v16;
    v17 = ((int)COERCE_FLOAT(LODWORD(v3[3].x) & _mask__AbsFloat_) / 8) & 0x3FF;
    v18 = planehash[v17];
    planehash[v17] = v7;
    result = nummapplanes - 1;
    LODWORD(v3[3].z) = v18;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00424FA0
// Name: int FindFloatPlane(class Vector __near &,float)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindFloatPlane(Vector *normal, unsigned int dist)
{
  float v2; // xmm4_4
  __m128 v3; // xmm2
  __m128 v4; // xmm0
  __m128 v5; // xmm1
  __m128 v6; // xmm3
  __m128 v7; // xmm1
  __m128 v8; // xmm2
  float v9; // xmm1_4
  int v10; // eax
  int v11; // edx
  plane_t *v12; // ecx

  SnapVector(normal);
  v2 = *(float *)&dist;
  v3.m128_i32[0] = 1258291200;
  v4 = (__m128)dist;
  v4.m128_f32[0] = *(float *)&dist + 0.5;
  v5 = _mm_and_ps((__m128)0x80000000, v4);
  v6.m128_i32[0] = v5.m128_i32[0];
  v3.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v4, v5), v3).m128_f32[0]) & 0x4B000000 | v5.m128_i32[0];
  v7 = v4;
  v7.m128_f32[0] = (float)((float)(*(float *)&dist + 0.5) + v3.m128_f32[0]) - v3.m128_f32[0];
  v8 = v7;
  v8.m128_f32[0] = v7.m128_f32[0] - (float)(*(float *)&dist + 0.5);
  v9 = v7.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v8, v6).m128_f32[0]) & 0x3F800000);
  if ( fabs(*(float *)&dist - v9) < 0.0099999998 )
    v2 = v9;
  v10 = ((int)fabs(v2) / 8) & 0x3FF;
  v11 = -1;
  while ( 1 )
  {
    v12 = planehash[((_WORD)v11 + (_WORD)v10) & 0x3FF];
    if ( v12 != nullptr )
      break;
LABEL_10:
    if ( ++v11 > 1 )
      return CreateNewFloatPlane(normal, dist: v2);
  }
  while ( fabs(v12->normal.x - normal->x) >= 0.0000099999997
       || fabs(v12->normal.y - normal->y) >= 0.0000099999997
       || fabs(v12->normal.z - normal->z) >= 0.0000099999997
       || fabs(v12->dist - v2) >= 0.0099999998 )
  {
    v12 = v12->hash_chain;
    if ( v12 == nullptr )
      goto LABEL_10;
  }
  return ((char *)v12 - (char *)&mapplanes) / 24;
}

//------------------------------------------------------------------------------
// Address: 0x00425100
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
  v2 = (mapdispinfo_t *)((char *)&mapdispinfo + 10544 * nummapdispinfo++);
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
// Address: 0x00425200
// Name: enum ChunkFileResult_t LoadSideCallback(class CChunkFile __near *,struct LoadSide_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadSideCallback(CChunkFile *pFile, int pSideInfo)
{
  int v2; // eax
  LoadSide_t *v3; // esi
  mapbrush_t *v4; // edx
  side_t *v5; // edi
  int v6; // eax
  int contents; // eax
  int v8; // eax
  float v9; // xmm5_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  int FloatPlane; // edi
  mapbrush_t *v16; // ebx
  LoadSide_t *v17; // ecx
  int numsides; // eax
  LoadSide_t *v19; // eax
  side_t *v20; // eax
  CChunkHandlerMap Handlers; // [esp+10h] [ebp-20h] BYREF
  Vector vec; // [esp+1Ch] [ebp-14h] BYREF
  mapbrush_t *b; // [esp+28h] [ebp-8h]
  ChunkFileResult_t eResult; // [esp+2Ch] [ebp-4h]

  v2 = nummapbrushsides;
  if ( nummapbrushsides == 0x10000 )
  {
    _Error(
      a1: "Brush %i: %s\nSide %i\nTexture: %s\n",
      g_MapError.m_brushID,
      "MAX_MAP_BRUSHSIDES",
      g_MapError.m_sideIndex,
      g_MapError.m_textureName);
    v2 = nummapbrushsides;
  }
  v3 = (LoadSide_t *)pSideInfo;
  v4 = *(mapbrush_t **)pSideInfo;
  v5 = &brushsides[v2];
  v6 = *(_DWORD *)(pSideInfo + 8);
  *(_DWORD *)(pSideInfo + 4) = v5;
  v3->nSideIndex = v6 + 1;
  g_MapError.m_sideIndex = v6;
  b = v4;
  v3->pSide->pMapDisp = nullptr;
  CExpressionEvaluator::CExpressionEvaluator(this: (CExpressionEvaluator *)&Handlers);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "dispinfo",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))LoadDispInfoCallback,
    pData: &v5->pMapDisp);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &Handlers);
  eResult = CChunkFile::ReadChunk(
              this: pFile,
              pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))LoadSideKeyCallback,
              pData: v3);
  CChunkFile::PopHandlers(this: pFile);
  if ( eResult != ChunkFile_Ok )
    goto LABEL_29;
  v5->contents |= v3->nBaseContents;
  v5->surf |= v3->nBaseFlags;
  v3->td.flags |= v3->nBaseFlags;
  contents = v5->contents;
  if ( (contents & 0x30000) != 0 )
    v5->contents = contents | 0x8000000;
  if ( fulldetail != 0 )
    v5->contents &= ~0x8000000u;
  v8 = v5->contents;
  if ( (v8 & 0x300FF) == 0 )
    v5->contents = v8 | 1;
  if ( (v5->surf & 0x300) != 0 )
    v5->contents = 0;
  v9 = v3->planepts[2].y - v3->planepts[1].y;
  v10 = v3->planepts[2].z - v3->planepts[1].z;
  v11 = v3->planepts[0].y - v3->planepts[1].y;
  v12 = v3->planepts[0].z - v3->planepts[1].z;
  v13 = v3->planepts[0].x - v3->planepts[1].x;
  v14 = v3->planepts[2].x - v3->planepts[1].x;
  vec.x = (float)(v10 * v11) - (float)(v9 * v12);
  vec.y = (float)(v14 * v12) - (float)(v10 * v13);
  vec.z = (float)(v13 * v9) - (float)(v14 * v11);
  VectorNormalize(&vec);
  *(float *)&pSideInfo = (float)((float)(v3->planepts[0].x * vec.x) + (float)(vec.y * v3->planepts[0].y))
                       + (float)(v3->planepts[0].z * vec.z);
  SnapPlane(normal: &vec, dist: (float *)&pSideInfo, p0: v3->planepts, p1: &v3->planepts[1], p2: &v3->planepts[2]);
  FloatPlane = FindFloatPlane(normal: &vec, dist: pSideInfo);
  if ( FloatPlane == -1 )
  {
    printf(format: "Brush %i, Side %i: %s\n", g_MapError.m_brushID, g_MapError.m_sideIndex, "plane with no normal");
LABEL_29:
    CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
    return eResult;
  }
  v16 = b;
  v17 = nullptr;
  if ( b->numsides > 0 )
  {
    pSideInfo = (int)b->original_sides;
    while ( 1 )
    {
      if ( *(_DWORD *)pSideInfo == FloatPlane )
      {
        pSideInfo = (int)v17;
        printf(format: "Brush %i, Side %i: %s\n", g_MapError.m_brushID, g_MapError.m_sideIndex, "duplicate plane");
        goto LABEL_21;
      }
      if ( *(_DWORD *)pSideInfo == (FloatPlane ^ 1) )
        break;
      pSideInfo += 100;
      v17 = (LoadSide_t *)((char *)v17 + 1);
      if ( (int)v17 >= b->numsides )
        goto LABEL_22;
    }
    pSideInfo = (int)v17;
    printf(format: "Brush %i, Side %i: %s\n", g_MapError.m_brushID, g_MapError.m_sideIndex, "mirrored plane");
LABEL_21:
    v17 = (LoadSide_t *)pSideInfo;
  }
LABEL_22:
  numsides = v16->numsides;
  if ( v17 != (LoadSide_t *)numsides )
    goto LABEL_29;
  v19 = (LoadSide_t *)&v16->original_sides[numsides];
  v19->pBrush = (mapbrush_t *)FloatPlane;
  pSideInfo = (int)v19;
  if ( onlyents == 0 )
  {
    v20 = (side_t *)TexinfoForBrushTexture(plane: (plane_t *)&mapplanes + FloatPlane, bt: &v3->td, origin: &vec3_origin);
    *(_DWORD *)(pSideInfo + 4) = v20;
  }
  if ( nummapbrushsides == 0x10000 )
    _Error(
      a1: "Brush %i: %s\nSide %i\nTexture: %s\n",
      g_MapError.m_brushID,
      "MAX_MAP_BRUSHSIDES",
      g_MapError.m_sideIndex,
      g_MapError.m_textureName);
  brush_texture_t::operator=(this: &side_brushtextures[nummapbrushsides], __that: &v3->td);
  ++nummapbrushsides;
  ++v16->numsides;
  CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
  return eResult;
}

//------------------------------------------------------------------------------
// Address: 0x00425550
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
// Address: 0x004255A0
// Name: public: virtual void CMapDataFilesMgr::AddAllRegisteredFilesToPak(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDataFilesMgr::AddAllRegisteredFilesToPak(CMapDataFilesMgr *this)
{
  int v2; // esi
  const char *v3; // eax
  CUtlBuffer *v4; // ecx
  IZip *PakFile; // eax
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
// Address: 0x00425690
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
            CUtlMemory<HemiLightData_t *,int>::Grow(
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
// Address: 0x004257A0
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
                                    CUtlMemory<HemiLightData_t *,int>::Grow(
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
// Address: 0x00425C60
// Name: public: virtual void CMapDataFilesMgr::RegisterFile(char const __near *,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDataFilesMgr::RegisterFile(CMapDataFilesMgr *this, const char *szFileName, CUtlBuffer *bufData)
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
// Address: 0x00425D40
// Name: class IMapDataFilesMgr __near * GetMapDataFilesMgr(void)
// Source: json
//------------------------------------------------------------------------------
CMapDataFilesMgr *__cdecl GetMapDataFilesMgr()
{
  if ( (_S1_0 & 1) == 0 )
  {
    _S1_0 |= 1u;
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
// Address: 0x00425DA0
// Name: void AddBrushBevels(struct mapbrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddBrushBevels(mapbrush_t *b)
{
  winding_t *v1; // edx
  mapbrush_t *v2; // ebx
  int v3; // ecx
  side_t *original_sides; // esi
  int v5; // edi
  bool v6; // zf
  unsigned int x_low; // xmm0_4
  int v8; // esi
  brush_texture_t *v9; // ebx
  brush_texture_t *v10; // esi
  int numsides; // ebx
  int numpoints; // esi
  int v13; // eax
  Vector *p; // ecx
  int v15; // eax
  float v16; // xmm0_4
  Vector *v17; // eax
  int v18; // eax
  int j; // ecx
  float v20; // xmm1_4
  mapbrush_t *v21; // ebx
  int v22; // eax
  float y; // xmm3_4
  float z; // xmm1_4
  float *v25; // eax
  float v26; // xmm0_4
  float v27; // xmm3_4
  float v28; // xmm4_4
  int v29; // eax
  float v30; // xmm0_4
  _DWORD *v31; // ecx
  Vector *v32; // eax
  int *v33; // edi
  int v34; // esi
  int v35; // eax
  int v36; // ecx
  float *v37; // edx
  float *v38; // ecx
  bool v39; // zf
  float *v40; // ecx
  side_t *v41; // esi
  brush_texture_t tdtemp; // [esp+10h] [ebp-16Ch] BYREF
  side_t sidetemp; // [esp+C4h] [ebp-B8h] BYREF
  float dist; // [esp+128h] [ebp-54h]
  int v45; // [esp+12Ch] [ebp-50h]
  int v46; // [esp+130h] [ebp-4Ch]
  Vector vec2; // [esp+134h] [ebp-48h] BYREF
  int v48; // [esp+140h] [ebp-3Ch]
  int i; // [esp+144h] [ebp-38h]
  unsigned int v50; // [esp+148h] [ebp-34h]
  Vector *p_vec2; // [esp+14Ch] [ebp-30h]
  Vector normal; // [esp+150h] [ebp-2Ch] BYREF
  Vector vec; // [esp+15Ch] [ebp-20h] BYREF
  int dir; // [esp+168h] [ebp-14h]
  int v55; // [esp+16Ch] [ebp-10h]
  int k; // [esp+170h] [ebp-Ch]
  winding_t *w; // [esp+174h] [ebp-8h]
  Vector *p_mins; // [esp+178h] [ebp-4h]

  v1 = nullptr;
  v2 = b;
  memset(&sidetemp.aOverlayIds, 0, 40);
  memset(&tdtemp, 0, 24);
  k = 0;
  w = nullptr;
  p_mins = &b->mins;
  do
  {
    v3 = -1;
    dir = -1;
    v55 = 100 * k;
    do
    {
      original_sides = v2->original_sides;
      v5 = 0;
      v6 = v2->numsides == 0;
      if ( v2->numsides > 0 )
      {
        do
        {
          if ( *(&mapplanes.x + (_DWORD)v1 + 6 * original_sides->planenum) == (float)v3 )
            break;
          ++v5;
          ++original_sides;
        }
        while ( v5 < v2->numsides );
        v6 = v5 == v2->numsides;
      }
      if ( v6 )
      {
        if ( nummapbrushsides == 0x10000 )
        {
          _Error(
            a1: "Brush %i: %s\nSide %i\nTexture: %s\n",
            g_MapError.m_brushID,
            "MAX_MAP_BRUSHSIDES",
            g_MapError.m_sideIndex,
            g_MapError.m_textureName);
          v3 = dir;
          v1 = w;
        }
        ++nummapbrushsides;
        ++v2->numsides;
        memset(&normal, 0, sizeof(normal));
        *(&normal.x + (_DWORD)v1) = (float)v3;
        if ( v3 == 1 )
          x_low = LODWORD(p_mins[1].x);
        else
          x_low = LODWORD(p_mins->x) ^ _mask__NegFloat_;
        original_sides->planenum = FindFloatPlane(&normal, dist: x_low);
        original_sides->texinfo = v2->original_sides->texinfo;
        v3 = dir;
        v1 = w;
        original_sides->contents = v2->original_sides->contents;
        original_sides->bevel = 1;
        ++c_boxbevels;
      }
      if ( v5 != k )
      {
        side_t::operator=(this: &sidetemp, __that: (const side_t *)((char *)b->original_sides + v55));
        side_t::operator=(this: (side_t *)((char *)b->original_sides + v55), __that: &b->original_sides[v5]);
        side_t::operator=(this: &b->original_sides[v5], __that: &sidetemp);
        v8 = b->original_sides - brushsides;
        v9 = &side_brushtextures[v8 + k];
        brush_texture_t::operator=(this: &tdtemp, __that: v9);
        v10 = &side_brushtextures[v5 + v8];
        brush_texture_t::operator=(this: v9, __that: v10);
        brush_texture_t::operator=(this: v10, __that: &tdtemp);
        v2 = b;
        v3 = dir;
        v1 = w;
      }
      ++k;
      v55 += 100;
      v3 += 2;
      dir = v3;
    }
    while ( v3 <= 1 );
    p_mins = (Vector *)((char *)p_mins + 4);
    v1 = (winding_t *)((char *)v1 + 1);
    w = v1;
  }
  while ( (int)v1 < 3 );
  numsides = v2->numsides;
  if ( numsides != 6 )
  {
    i = 6;
    if ( numsides > 6 )
    {
      v50 = 600;
      while ( 1 )
      {
        w = b->original_sides[v50 / 0x64].winding;
        if ( w != nullptr )
        {
          numpoints = w->numpoints;
          v13 = 0;
          if ( w->numpoints > 0 )
            break;
        }
LABEL_73:
        v50 += 100;
        if ( ++i >= b->numsides )
          goto LABEL_74;
      }
      p_mins = nullptr;
      while ( 1 )
      {
        p = w->p;
        v45 = v13 + 1;
        v15 = (v13 + 1) % numpoints;
        v16 = *(float *)((char *)&p->x + (_DWORD)p_mins) - p[v15].x;
        v17 = &p[v15];
        vec.x = v16;
        vec.y = *(float *)((char *)&p->y + (_DWORD)p_mins) - v17->y;
        vec.z = *(float *)((char *)&p->z + (_DWORD)p_mins) - v17->z;
        if ( VectorNormalize(&vec) >= 0.5 )
        {
          v18 = 0;
          while ( 1 )
          {
            if ( fabs(*(&vec.x + v18) - 1.0) < 0.00001 )
            {
              memset(&vec, 0, sizeof(vec));
              *((_DWORD *)&vec.x + v18) = 1065353216;
              goto LABEL_32;
            }
            if ( fabs(*(&vec.x + v18) - -1.0) < 0.00001 )
              break;
            if ( ++v18 >= 3 )
              goto LABEL_32;
          }
          memset(&vec, 0, sizeof(vec));
          *((_DWORD *)&vec.x + v18) = -1082130432;
LABEL_32:
          for ( j = 0; j < 3; ++j )
          {
            v20 = *(&vec.x + j);
            if ( v20 == -1.0 )
              break;
            if ( v20 == 1.0 )
              break;
          }
          if ( j == 3 )
            break;
        }
LABEL_72:
        v13 = v45;
        numpoints = w->numpoints;
        ++p_mins;
        if ( v45 >= numpoints )
          goto LABEL_73;
      }
      v21 = b;
      dir = -1;
      v22 = -1;
      p_vec2 = &vec2;
      v48 = 3;
      while ( 1 )
      {
        y = vec.y;
        z = vec.z;
        memset(&vec2, 0, sizeof(vec2));
        p_vec2->x = (float)v22;
        normal.x = (float)(vec2.z * y) - (float)(vec2.y * z);
        normal.y = (float)(z * vec2.x) - (float)(vec2.z * vec.x);
        normal.z = (float)(vec2.y * vec.x) - (float)(y * vec2.x);
        if ( VectorNormalize(vec: &normal) >= 0.5 )
        {
          v25 = (float *)((char *)&p_mins->x + (unsigned int)w->p);
          v26 = v25[1];
          v27 = *v25;
          v28 = v25[2];
          v29 = v21->numsides;
          v30 = (float)((float)(v26 * normal.y) + (float)(v27 * normal.x)) + (float)(v28 * normal.z);
          dist = v30;
          k = 0;
          v46 = v29;
          if ( v29 > 0 )
          {
            v55 = (int)v21->original_sides;
            v31 = (_DWORD *)v55;
            while ( 1 )
            {
              v32 = &mapplanes + 2 * *v31;
              if ( fabs(v32->x - normal.x) < 0.0099999998
                && fabs(v32->y - normal.y) < 0.0099999998
                && fabs(v32->z - normal.z) < 0.0099999998
                && fabs(v32[1].x - v30) < 0.0099999998 )
              {
                goto LABEL_66;
              }
              v33 = (int *)v31[3];
              if ( v33 != nullptr )
                break;
LABEL_65:
              v31 += 25;
              ++k;
              v55 = (int)v31;
              if ( k >= v21->numsides )
                goto LABEL_66;
            }
            v34 = *v33;
            v35 = 0;
            if ( *v33 < 4 )
            {
LABEL_54:
              v39 = v35 == v34;
              if ( v35 < v34 )
              {
                v40 = (float *)(v33[1] + 12 * v35);
                do
                {
                  if ( (float)((float)((float)((float)(v40[1] * normal.y) + (float)(*v40 * normal.x))
                                     + (float)(v40[2] * normal.z))
                             - v30) > 0.1 )
                    break;
                  ++v35;
                  v40 += 3;
                }
                while ( v35 < v34 );
                goto LABEL_62;
              }
            }
            else
            {
              v36 = v33[1];
              v37 = (float *)(v36 + 8);
              v38 = (float *)(v36 + 20);
              while ( (float)((float)((float)((float)(*(v37 - 2) * normal.x) + (float)(*(v37 - 1) * normal.y))
                                    + (float)(normal.z * *v37))
                            - v30) <= 0.1 )
              {
                if ( (float)((float)((float)((float)(v37[1] * normal.x) + (float)(*(v38 - 1) * normal.y))
                                   + (float)(*v38 * normal.z))
                           - v30) > 0.1 )
                {
                  ++v35;
                  break;
                }
                if ( (float)((float)((float)((float)(v37[4] * normal.x) + (float)(v38[2] * normal.y))
                                   + (float)(v38[3] * normal.z))
                           - v30) > 0.1 )
                {
                  v35 += 2;
                  break;
                }
                if ( (float)((float)((float)((float)(v37[7] * normal.x) + (float)(v38[5] * normal.y))
                                   + (float)(v38[6] * normal.z))
                           - v30) > 0.1 )
                {
                  v35 += 3;
                  break;
                }
                v35 += 4;
                v37 += 12;
                v38 += 12;
                v21 = b;
                if ( v35 >= v34 - 3 )
                  goto LABEL_54;
              }
LABEL_62:
              v39 = v35 == v34;
            }
            if ( !v39 )
              goto LABEL_66;
            v31 = (_DWORD *)v55;
            goto LABEL_65;
          }
LABEL_66:
          if ( k == v46 )
          {
            if ( nummapbrushsides == 0x10000 )
            {
              _Error(
                a1: "Brush %i: %s\nSide %i\nTexture: %s\n",
                g_MapError.m_brushID,
                "MAX_MAP_BRUSHSIDES",
                g_MapError.m_sideIndex,
                g_MapError.m_textureName);
              v30 = dist;
            }
            ++nummapbrushsides;
            v41 = &v21->original_sides[v21->numsides];
            v41->planenum = FindFloatPlane(&normal, dist: LODWORD(v30));
            v41->texinfo = v21->original_sides->texinfo;
            v41->contents = v21->original_sides->contents;
            v41->bevel = 1;
            ++c_edgebevels;
            ++v21->numsides;
          }
        }
        v22 = dir + 2;
        dir = v22;
        if ( v22 > 1 )
        {
          p_vec2 = (Vector *)((char *)p_vec2 + 4);
          if ( --v48 == 0 )
            goto LABEL_72;
          v21 = b;
          dir = -1;
          v22 = -1;
        }
      }
    }
  }
LABEL_74:
  if ( sidetemp.aWaterOverlayIds.m_Memory.m_nGrowSize >= 0 && sidetemp.aWaterOverlayIds.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sidetemp.aWaterOverlayIds.m_Memory.m_pMemory);
  if ( sidetemp.aOverlayIds.m_Memory.m_nGrowSize >= 0 && sidetemp.aOverlayIds.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sidetemp.aOverlayIds.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004265A0
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
// Address: 0x004265F0
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
// Address: 0x00426650
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
  arrFiles[4] = aDx9;
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
  if ( (_S1_0 & 1) == 0 )
  {
    _S1_0 |= 1u;
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
// Address: 0x004267C0
// Name: enum ChunkFileResult_t LoadSolidCallback(class CChunkFile __near *,struct LoadEntity_t __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl LoadSolidCallback(CChunkFile *pFile, LoadEntity_t *pLoadEntity)
{
  int v2; // eax
  int v3; // edx
  mapbrush_t *v4; // esi
  int nBaseContents; // eax
  ChunkFileResult_t Chunk; // ebx
  side_t *original_sides; // ecx
  unsigned int contents; // ebx
  unsigned int v9; // eax
  int *p_contents; // ecx
  int v11; // edx
  int v12; // eax
  bool v13; // zf
  int v14; // eax
  int v15; // ecx
  float v16; // xmm2_4
  float v17; // xmm1_4
  LoadSide_t SideInfo; // [esp+0h] [ebp-124h] BYREF
  char string[32]; // [esp+ECh] [ebp-38h] BYREF
  Vector origin; // [esp+10Ch] [ebp-18h]
  CChunkHandlerMap Handlers; // [esp+118h] [ebp-Ch] BYREF

  v2 = nummapbrushes;
  if ( nummapbrushes == 0x2000 )
  {
    _Error(
      a1: "Brush %i: %s\nSide %i\nTexture: %s\n",
      g_MapError.m_brushID,
      "nummapbrushes == MAX_MAP_BRUSHES",
      g_MapError.m_sideIndex,
      g_MapError.m_textureName);
    v2 = nummapbrushes;
  }
  v3 = nummapbrushsides;
  v4 = &mapbrushes[v2];
  v4->entitynum = num_entities - 1;
  v4->original_sides = &brushsides[v3];
  v4->brushnum = v2 - pLoadEntity->pEntity->firstbrush;
  nBaseContents = pLoadEntity->nBaseContents;
  SideInfo.nBaseFlags = pLoadEntity->nBaseFlags;
  memset(&SideInfo.td, 0, 24);
  SideInfo.pBrush = v4;
  SideInfo.nSideIndex = 0;
  SideInfo.nBaseContents = nBaseContents;
  CExpressionEvaluator::CExpressionEvaluator(this: (CExpressionEvaluator *)&Handlers);
  CChunkHandlerMap::AddHandler(
    this: &Handlers,
    pszChunkName: "side",
    pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))LoadSideCallback,
    pData: &SideInfo);
  CChunkFile::PushHandlers(this: pFile, pHandlerMap: &Handlers);
  Chunk = CChunkFile::ReadChunk(
            this: pFile,
            pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))LoadSolidKeyCallback,
            pData: v4);
  CChunkFile::PopHandlers(this: pFile);
  if ( Chunk != ChunkFile_Ok )
  {
    CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
    return Chunk;
  }
  else
  {
    original_sides = v4->original_sides;
    contents = original_sides->contents;
    v9 = contents;
    if ( v4->numsides > 1 )
    {
      p_contents = &original_sides[1].contents;
      v11 = v4->numsides - 1;
      do
      {
        v9 |= *p_contents;
        p_contents += 25;
        --v11;
      }
      while ( v11 != 0 );
    }
    v12 = v9 & 0x3A;
    if ( v12 != 0 )
      contents = (v12 | contents) & 0xEFFFFFFE | 0x10000000;
    v13 = nodetail == 0;
    v4->contents = contents;
    if ( !v13 && (contents & 0x8000000) != 0 && HasDispInfo(pBrush: v4) == 0
      || nowater != 0 && (v4->contents & 0x4030) != 0 )
    {
      goto LABEL_25;
    }
    MakeBrushWindings(ob: (winding_t *)v4);
    if ( v4->entitynum == 0 && (v4->contents & 0x30000) != 0 )
    {
      if ( g_ClipTexinfo < 0 )
        g_ClipTexinfo = v4->original_sides->texinfo;
      ++c_clipbrushes;
      v14 = 0;
      if ( v4->numsides > 0 )
      {
        v15 = 0;
        do
        {
          v4->original_sides[v15].texinfo = -1;
          ++v14;
          ++v15;
        }
        while ( v14 < v4->numsides );
      }
    }
    if ( ((unsigned int)&unk_1000000 & v4->contents) != 0 )
    {
      if ( num_entities == 1 )
        _Error(a1: "Brush %i: origin brushes not allowed in world", v4->id);
      v16 = (float)(v4->mins.z + v4->maxs.z) * 0.5;
      v17 = (float)(v4->mins.y + v4->maxs.y) * 0.5;
      origin.x = (float)(v4->mins.x + v4->maxs.x) * 0.5;
      origin.y = v17;
      origin.z = v16;
      sprintf(string, format: "%i %i %i", (int)origin.x, (int)v17, (int)v16);
      SetKeyValue(ent: (entity_t *)&entities + v4->entitynum, key: "origin", value: string, bAllowDuplicates: false);
      *(Vector *)((char *)&entities + 44 * v4->entitynum) = origin;
      goto LABEL_25;
    }
    if ( HasDispInfo(pBrush: v4) != 0 )
    {
      DispGetFaceInfo(pBrush: v4);
LABEL_25:
      v4->numsides = 0;
      CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
      return ChunkFile_Ok;
    }
    AddBrushBevels(b: v4);
    ++nummapbrushes;
    ++pLoadEntity->pEntity->numbrushes;
    CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
    return ChunkFile_Ok;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426AD0
// Name: enum ChunkFileResult_t LoadEntityCallback(class CChunkFile __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl LoadEntityCallback(CChunkFile *pFile)
{
  unsigned __int8 *v1; // edi
  ChunkFileResult_t v2; // ebx
  char *v3; // ebx
  char *v4; // ecx
  char v5; // al
  int v6; // ecx
  int v7; // esi
  int v8; // eax
  bool v9; // cc
  int v10; // ebx
  winding_t *v11; // ebx
  int *v12; // esi
  int v13; // eax
  int FloatPlane; // ecx
  const char *v15; // esi
  int v16; // ebx
  mapbrush_t *v17; // eax
  int v18; // edx
  int v19; // esi
  int v21; // esi
  const char *v22; // esi
  int v23; // edx
  int dist; // [esp+0h] [ebp-320h]
  char str[128]; // [esp+10h] [ebp-310h] BYREF
  CSyncMesh_SaveLoadHandler hdlrEntityMeshData; // [esp+90h] [ebp-290h] BYREF
  char buf[16]; // [esp+2E8h] [ebp-38h] BYREF
  LoadEntity_t LoadEntity; // [esp+2F8h] [ebp-28h] BYREF
  int j; // [esp+308h] [ebp-18h]
  CChunkHandlerMap Handlers; // [esp+30Ch] [ebp-14h] BYREF
  int i; // [esp+318h] [ebp-8h]
  int max; // [esp+31Ch] [ebp-4h]

  if ( num_entities == 0x4000 )
    _Error(
      a1: "Brush %i: %s\nSide %i\nTexture: %s\n",
      g_MapError.m_brushID,
      "num_entities == MAX_MAP_ENTITIES",
      g_MapError.m_sideIndex,
      g_MapError.m_textureName);
  v1 = (unsigned __int8 *)&entities + 44 * num_entities++;
  memset(dst: v1, value: 0, count: 0x2Cu);
  *((_DWORD *)v1 + 3) = nummapbrushes;
  *((_DWORD *)v1 + 4) = 0;
  LoadEntity.pEntity = (entity_t *)v1;
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
  v2 = CChunkFile::ReadChunk(
         this: pFile,
         pfnKeyHandler: (ChunkFileResult_t (__cdecl *)(const char *, const char *, void *))LoadEntityKeyCallback,
         pData: &LoadEntity);
  CChunkFile::PopHandlers(this: pFile);
  VmfUninstallMapEntitySaveLoadHandler(pHandler: &hdlrEntityMeshData);
  if ( v2 != ChunkFile_Ok )
  {
    CVmfMeshDataSupport_SaveLoadHandler::~CVmfMeshDataSupport_SaveLoadHandler(this: &hdlrEntityMeshData);
    CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
    return (const char *)v2;
  }
  else
  {
    GetVectorForKey(ent: (entity_t *)v1, key: "origin", angle: (QAngle *)v1);
    v3 = ValueForKey(ent: (entity_t *)v1, key: "mindxlevel");
    v4 = ValueForKey(ent: (entity_t *)v1, key: "maxdxlevel");
    v5 = *v3;
    i = (int)v4;
    if ( v5 != 0 || *v4 != 0 )
    {
      v6 = 0;
      v7 = 0;
      max = 0;
      if ( v5 != 0 )
      {
        v8 = atoi(nptr: v3);
        v6 = max;
        v7 = v8;
      }
      if ( *(_BYTE *)i != 0 )
      {
        max = atoi(nptr: (const char *)i);
        v6 = max;
      }
      if ( v7 == 0 )
        v7 = g_nDXLevel;
      if ( v6 == 0 )
        v6 = g_nDXLevel;
      if ( g_nDXLevel != 0 && (g_nDXLevel < v7 || g_nDXLevel > v6) )
        goto LABEL_37;
    }
    if ( *(float *)v1 != 0.0 || *((float *)v1 + 1) != 0.0 || *((float *)v1 + 2) != 0.0 )
    {
      v9 = *((_DWORD *)v1 + 4) <= 0;
      i = 0;
      if ( !v9 )
      {
        do
        {
          v10 = i + *((_DWORD *)v1 + 3);
          j = 0;
          v11 = (winding_t *)&mapbrushes[v10];
          if ( v11[2].maxpoints > 0 )
          {
            max = 0;
            do
            {
              v12 = (int *)((char *)&v11[2].next->numpoints + max);
              v13 = 24 * *v12;
              FloatPlane = FindFloatPlane(
                             normal: (Vector *)((char *)&mapplanes + v13),
                             dist: COERCE_UNSIGNED_INT(
                               *(float *)((char *)&::dist + v13)
                             - (float)((float)((float)(*(float *)((char *)&mapplanes.y + v13) * *((float *)v1 + 1))
                                             + (float)(*(float *)((char *)&mapplanes.x + v13) * *(float *)v1))
                                     + (float)(*(float *)((char *)&mapplanes.z + v13) * *((float *)v1 + 2)))));
              *v12 = FloatPlane;
              if ( onlyents == 0 )
                v12[1] = TexinfoForBrushTexture(
                           plane: (plane_t *)&mapplanes + FloatPlane,
                           bt: &side_brushtextures[((char *)v12 - (char *)brushsides) / 100],
                           origin: (const Vector *)v1);
              max += 100;
              ++j;
            }
            while ( j < v11[2].maxpoints );
          }
          MakeBrushWindings(ob: v11);
          ++i;
        }
        while ( i < *((_DWORD *)v1 + 4) );
      }
    }
    v15 = ValueForKey(ent: (entity_t *)v1, key: "classname");
    v16 = 0;
    if ( strcmp("func_detail", v15) == 0 )
    {
      MoveBrushesToWorld(mapent: (entity_t *)v1);
      *((_DWORD *)v1 + 4) = 0;
      goto LABEL_29;
    }
    if ( _V_stricmp(s1: "func_lod", s2: v15) == 0 )
    {
      if ( *((int *)v1 + 4) > 0 )
      {
        do
        {
          v17 = &mapbrushes[v16 + *((_DWORD *)v1 + 3)];
          v17->contents |= 0x8000000u;
          v18 = 0;
          if ( v17->numsides > 0 )
          {
            v19 = 0;
            do
            {
              v17->original_sides[v19].contents |= 0x8000000u;
              ++v18;
              ++v19;
            }
            while ( v18 < v17->numsides );
          }
          ++v16;
        }
        while ( v16 < *((_DWORD *)v1 + 4) );
      }
      MoveBrushesToWorld(mapent: (entity_t *)v1);
LABEL_37:
      *((_DWORD *)v1 + 4) = 0;
      *((_DWORD *)v1 + 5) = 0;
      goto LABEL_38;
    }
    if ( strcmp("func_viscluster", v15) == 0 )
    {
      AddVisCluster(pFuncVisCluster: (entity_t *)v1);
      goto LABEL_38;
    }
    if ( strcmp("func_ladder", v15) == 0 )
    {
      AddLadderKeys(mapent: (entity_t *)v1);
      MoveBrushesToWorld(mapent: (entity_t *)v1);
      SetKeyValue(ent: (entity_t *)v1, key: "classname", value: "info_ladder", bAllowDuplicates: false);
      goto LABEL_38;
    }
    if ( strcmp("test_sidelist", v15) == 0 )
    {
      ConvertSideList(mapent: (entity_t *)v1, key: "sides");
      goto LABEL_38;
    }
    if ( strcmp("info_overlay", v15) == 0 )
    {
      v21 = Overlay_GetFromEntity(pMapEnt: (entity_t *)v1);
      if ( v21 >= 0 )
      {
        SetKeyValue(ent: (entity_t *)v1, key: "classname", value: "info_overlay_accessor", bAllowDuplicates: false);
        V_snprintf(pDest: buf, maxLen: 16, pFormat: "%i", v21);
        SetKeyValue(ent: (entity_t *)v1, key: "OverlayID", value: buf, bAllowDuplicates: false);
        goto LABEL_38;
      }
      goto LABEL_29;
    }
    if ( strcmp("info_overlay_transition", v15) == 0 )
    {
LABEL_29:
      *((_DWORD *)v1 + 5) = 0;
LABEL_38:
      CVmfMeshDataSupport_SaveLoadHandler::~CVmfMeshDataSupport_SaveLoadHandler(this: &hdlrEntityMeshData);
      CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
      return nullptr;
    }
    if ( _V_stricmp(s1: v15, s2: "info_no_dynamic_shadow") != 0 )
    {
      if ( IsAreaPortal(pClassName: v15) )
      {
        if ( *((_DWORD *)v1 + 4) != 1 )
          _Error(a1: "Entity %i: func_areaportal can only be a single brush", num_entities - 1);
        v23 = 3 * nummapbrushes;
        dist = ++c_areaportals;
        *((_DWORD *)v1 + 6) = c_areaportals;
        *(_DWORD *)&side_brushtextures[0xFFFF].name[16 * v23 + 96] = 0x8000;
        sprintf(string: str, format: "%i", dist);
        SetKeyValue(ent: (entity_t *)v1, key: "portalnumber", value: str, bAllowDuplicates: false);
        MoveBrushesToWorld(mapent: (entity_t *)v1);
      }
      else if ( v1 != (unsigned __int8 *)&entities )
      {
        RemoveContentsDetailFromEntity(mapent: (entity_t *)v1);
      }
      goto LABEL_38;
    }
    v22 = HandleNoDynamicShadowsEnt(pMapEnt: (entity_t *)v1);
    CVmfMeshDataSupport_SaveLoadHandler::~CVmfMeshDataSupport_SaveLoadHandler(this: &hdlrEntityMeshData);
    CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
    return v22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427130
// Name: void LoadMapFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadMapFile(const char *pszFileName)
{
  ChunkFileResult_t v1; // eax
  ChunkFileResult_t v2; // esi
  int v3; // edi
  const char *ErrorText; // eax
  const char *v5; // eax
  Vector *p_mins; // esi
  CChunkFile File; // [esp+3Ch] [ebp-350h] BYREF
  CChunkHandlerMap Handlers; // [esp+380h] [ebp-Ch] BYREF

  g_nMapFileVersion = 400;
  CChunkFile::CChunkFile(this: &File);
  v1 = CChunkFile::Open(this: &File, pszFileName, eMode: ChunkFile_Read);
  v2 = v1;
  if ( v1 != ChunkFile_Ok )
  {
    ErrorText = CChunkFile::GetErrorText(this: &File, eResult: v1);
    _Error(a1: "Error opening %s: %s.\n", pszFileName, ErrorText);
    v3 = 0;
  }
  else
  {
    _Msg(a1: "Loading %s\n", pszFileName);
    v3 = 0;
    nummapbrushsides = 0;
    num_entities = 0;
    nummapdispinfo = 0;
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
      v2 = CChunkFile::ReadChunk(this: &File, pfnKeyHandler: nullptr, pData: nullptr);
    while ( v2 == ChunkFile_Ok );
    CChunkFile::PopHandlers(this: &File);
    CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
  }
  if ( v2 == ChunkFile_EOF )
  {
    ClearBounds(mins: &map_mins, maxs: &map_maxs);
    if ( unk_5CD4960 > 0 )
    {
      p_mins = &mapbrushes[0].mins;
      do
      {
        if ( p_mins->x <= 16384.0 )
        {
          AddPointToBounds(v: p_mins, mins: &map_mins, maxs: &map_maxs);
          AddPointToBounds(v: p_mins + 1, mins: &map_mins, maxs: &map_maxs);
        }
        ++v3;
        p_mins += 4;
      }
      while ( v3 < unk_5CD4960 );
    }
    qprintf(format: "%5i brushes\n", nummapbrushes);
    qprintf(format: "%5i clipbrushes\n", c_clipbrushes);
    qprintf(format: "%5i total sides\n", nummapbrushsides);
    qprintf(format: "%5i boxbevels\n", c_boxbevels);
    qprintf(format: "%5i edgebevels\n", c_edgebevels);
    qprintf(format: "%5i entities\n", num_entities);
    qprintf(format: "%5i planes\n", nummapplanes);
    qprintf(format: "%5i areaportals\n", c_areaportals);
    qprintf(
      format: "size: %5.0f,%5.0f,%5.0f to %5.0f,%5.0f,%5.0f\n",
      map_mins.x,
      map_mins.y,
      map_mins.z,
      map_maxs.x,
      map_maxs.y,
      map_maxs.z);
    g_MapError.m_brushID = 0;
    g_MapError.m_sideIndex = 0;
    V_strncpy(pDest: g_MapError.m_textureName, pSrc: "Not a Parse error!", maxLen: 80);
    Overlay_UpdateSideLists();
    OverlayTransition_UpdateSideLists();
    ForceFuncAreaPortalWindowContents();
    CChunkFile::~CChunkFile(this: &File);
  }
  else
  {
    v5 = CChunkFile::GetErrorText(this: &File, eResult: v2);
    _Error(
      a1: "Brush %i: %s\nSide %i\nTexture: %s\n",
      g_MapError.m_brushID,
      v5,
      g_MapError.m_sideIndex,
      g_MapError.m_textureName);
    ForceFuncAreaPortalWindowContents();
    CChunkFile::~CChunkFile(this: &File);
  }
}
