// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vrad/vrad.cpp
// Functions: 41
// ============================================================

#include "utils\vrad\vrad.h"

//------------------------------------------------------------------------------
// Address: 0x1001C200
// Name: public: float Vector::Dot(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall Vector::Dot(Vector *this, const Vector *vOther)
{
  return vOther->y * this->y + vOther->x * this->x + vOther->z * this->z;
}

//------------------------------------------------------------------------------
// Address: 0x1001C220
// Name: void MakeParents(int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MakeParents(int nodenum, int parent)
{
  int *children; // esi
  int i; // ebx
  int v4; // eax

  nodeparents[nodenum] = parent;
  children = dnodes[nodenum].children;
  for ( i = 2; i != 0; --i )
  {
    v4 = *children;
    if ( *children >= 0 )
      MakeParents(nodenum: v4, parent: nodenum);
    else
      leafparents[-v4 - 1] = nodenum;
    ++children;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C280
// Name: void LightForTexture(char const __near *,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LightForTexture(char *name, Vector *result)
{
  char *v2; // ebx
  int v3; // eax
  const char *v4; // eax
  char *v5; // eax
  char *v6; // edx
  char v7; // cl
  char v8; // bl
  int i; // esi
  char *v10; // eax
  int v11; // esi
  texlight_t *j; // edi
  char baseFilename[260]; // [esp+0h] [ebp-104h] BYREF

  v2 = name;
  *(_QWORD *)&result->y = 0;
  result->x = 0.0;
  if ( V_strncmp(s1: "maps/", s2: name, count: 5) == 0 )
  {
    v3 = _V_strlen(str: level_name);
    if ( V_strncmp(s1: level_name, s2: name + 5, count: v3) == 0 )
    {
      v4 = &name[_V_strlen(str: level_name) + 5];
      if ( *v4 == 47 )
      {
        v5 = (char *)(v4 + 1);
        v6 = (char *)(baseFilename - v5);
        do
        {
          v7 = *v5;
          v5[(_DWORD)v6] = *v5;
          ++v5;
        }
        while ( v7 != 0 );
        v8 = 1;
        for ( i = 3; i != 0; --i )
        {
          v10 = _V_strrchr(s: baseFilename, c: 95);
          if ( v10 != nullptr && *v10 != 0 )
            *v10 = 0;
          else
            v8 = 0;
        }
        if ( v8 != 0 )
          v2 = baseFilename;
        else
          v2 = name;
      }
    }
  }
  v11 = 0;
  if ( num_texlights > 0 )
  {
    for ( j = texlights; V_strcasecmp(s1: v2, s2: j->name) != 0; ++j )
    {
      if ( ++v11 >= num_texlights )
        return;
    }
    *result = texlights[v11].value;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C3A0
// Name: struct winding_t __near * WindingFromFace(struct dface_t __near *,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
winding_t *__cdecl WindingFromFace(winding_t *f, Vector *origin)
{
  winding_t *v3; // eax
  int v4; // esi
  int v5; // edi
  int v6; // eax
  int v7; // eax
  int v8; // ecx
  float v9; // xmm0_4
  Vector *p; // eax
  dvertex_t *v11; // ecx
  winding_t *w; // [esp+10h] [ebp+8h]

  v3 = AllocWinding(points: SLOWORD(f->maxpoints));
  v3->numpoints = SLOWORD(f->maxpoints);
  v4 = 0;
  w = v3;
  if ( SLOWORD(f->maxpoints) > 0 )
  {
    v5 = 0;
    do
    {
      v6 = dsurfedges[(int)f->p + v4];
      if ( v6 >= 0 )
        v7 = dedges[v6].v[0];
      else
        v7 = *((unsigned __int16 *)&unk_1157EAB2 - 2 * v6);
      v8 = v7;
      v9 = dvertexes[v7].point.x + origin->x;
      p = w->p;
      v11 = &dvertexes[v8];
      p[v5].x = v9;
      p[v5].y = v11->point.y + origin->y;
      p[v5].z = v11->point.z + origin->z;
      ++v4;
      ++v5;
    }
    while ( v4 < SLOWORD(f->maxpoints) );
    v3 = w;
  }
  RemoveColinearPoints(w: v3);
  return w;
}

//------------------------------------------------------------------------------
// Address: 0x1001C460
// Name: void ProcessSkyCameras(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProcessSkyCameras()
{
  int v0; // ebx
  entity_t *v1; // edi
  const char *v2; // eax
  int v3; // eax
  int v4; // esi
  double v5; // st7
  int v6; // ecx
  unsigned int v7; // eax
  float v8; // xmm0_4
  Vector origin; // [esp+8h] [ebp-10h] BYREF
  int scale; // [esp+14h] [ebp-4h]

  v0 = 0;
  num_sky_cameras = 0;
  if ( numareas > 0 )
    memset(area_sky_cameras, 0xFFu, 4 * numareas);
  if ( num_entities > 0 )
  {
    v1 = entities;
    do
    {
      v2 = ValueForKey(ent: v1, key: "classname");
      if ( _V_stricmp(s1: v2, s2: "sky_camera") == 0 )
      {
        GetVectorForKey(ent: v1, key: "origin", angle: (QAngle *)&origin);
        v3 = PointLeafnum(point: &origin);
        v4 = -1;
        if ( v3 >= 0 && v3 < (int)numleafs )
          v4 = (__int16)(word_1135AAB6[16 * v3] << 7) >> 7;
        v5 = FloatForKey(ent: v1, key: "scale");
        *(float *)&scale = v5;
        if ( v5 > 0.0 )
        {
          v6 = num_sky_cameras;
          v7 = 6 * num_sky_cameras;
          sky_cameras[v7 / 6].origin.x = origin.x;
          dword_11358EBC[v7] = LODWORD(origin.y);
          dword_11358EC0[v7] = LODWORD(origin.z);
          v8 = *(float *)&scale;
          dword_11358EC8[v7] = scale;
          *(float *)&dword_11358EC4[v7] = 1.0 / v8;
          dword_11358ECC[v7] = v4;
          if ( v4 >= 0 && v4 < numareas )
            area_sky_cameras[v4] = v6;
          num_sky_cameras = v6 + 1;
        }
      }
      ++v0;
      ++v1;
    }
    while ( v0 < num_entities );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C5B0
// Name: struct entity_t __near * EntityForModel(int)
// Source: json
//------------------------------------------------------------------------------
entity_t *__cdecl EntityForModel(int modnum)
{
  int v1; // edi
  entity_t *i; // esi
  char name[16]; // [esp+8h] [ebp-10h] BYREF

  sprintf(string: name, format: "*%i", modnum);
  v1 = 0;
  if ( num_entities <= 0 )
    return entities;
  for ( i = entities; strcmp(ValueForKey(ent: i, key: "model"), name) != 0; ++i )
  {
    if ( ++v1 >= num_entities )
      return entities;
  }
  return &entities[v1];
}

//------------------------------------------------------------------------------
// Address: 0x1001C650
// Name: float FormFactorPolyToDiff(struct CPatch __near *,struct CPatch __near *)
// Source: json
//------------------------------------------------------------------------------
double __usercall FormFactorPolyToDiff@<st0>(double a1@<esi:edi>, CPatch *pPolygon, CPatch *pDifferential)
{
  winding_t *winding; // edx
  int numpoints; // eax
  int v5; // ebx
  int v6; // edi
  int v7; // ecx
  Vector *p; // eax
  int v9; // ecx
  float v10; // xmm3_4
  Vector *v11; // eax
  double v12; // st7
  double v13; // xmm0_8
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm2_4
  long double v19; // [esp-Ch] [ebp-3Ch]
  Vector vVector1; // [esp+0h] [ebp-30h] BYREF
  Vector vVector2; // [esp+Ch] [ebp-24h] BYREF
  Vector vGammaVector; // [esp+18h] [ebp-18h] BYREF
  float flSinAlpha; // [esp+24h] [ebp-Ch]
  winding_t *pWinding; // [esp+28h] [ebp-8h]
  float flFormFactor; // [esp+2Ch] [ebp-4h]

  winding = pPolygon->winding;
  numpoints = pPolygon->winding->numpoints;
  v5 = 0;
  v19 = a1;
  pWinding = pPolygon->winding;
  flFormFactor = 0.0;
  if ( numpoints <= 0 )
    return 0.5 / pPolygon->area * flFormFactor;
  v6 = 0;
  while ( 1 )
  {
    v7 = v5 >= numpoints - 1 ? 0 : v5 + 1;
    p = winding->p;
    vVector1.x = p[v6].x - pDifferential->origin.x;
    vVector1.y = p[v6].y - pDifferential->origin.y;
    vVector1.z = p[v6].z - pDifferential->origin.z;
    v9 = v7;
    v10 = p[v9].x - pDifferential->origin.x;
    v11 = &p[v9];
    vVector2.x = v10;
    vVector2.y = v11->y - pDifferential->origin.y;
    vVector2.z = v11->z - pDifferential->origin.z;
    VectorNormalize(vec: &vVector1);
    VectorNormalize(vec: &vVector2);
    vGammaVector.x = (float)(vVector2.z * vVector1.y) - (float)(vVector2.y * vVector1.z);
    vGammaVector.y = (float)(vVector1.z * vVector2.x) - (float)(vVector2.z * vVector1.x);
    vGammaVector.z = (float)(vVector2.y * vVector1.x) - (float)(vVector1.y * vVector2.x);
    v12 = VectorNormalize(vec: &vGammaVector);
    flSinAlpha = v12;
    if ( v12 < -1.0 || flSinAlpha > 1.0 )
      break;
    v13 = flSinAlpha;
    __libm_sse2_asin(x: v19);
    winding = pWinding;
    numpoints = pWinding->numpoints;
    *(float *)&v13 = v13;
    v14 = vGammaVector.x * *(float *)&v13;
    v15 = vGammaVector.y * *(float *)&v13;
    v16 = vGammaVector.z * *(float *)&v13;
    *(float *)&v13 = pDifferential->normal.y * (float)(vGammaVector.y * *(float *)&v13);
    vGammaVector.y = v15;
    v17 = pDifferential->normal.x * v14;
    vGammaVector.x = v14;
    ++v5;
    *(float *)&v13 = (float)((float)(*(float *)&v13 + v17) + (float)(pDifferential->normal.z * v16)) + flFormFactor;
    ++v6;
    vGammaVector.z = v16;
    flFormFactor = *(float *)&v13;
    if ( v5 >= numpoints )
      return 0.5 / pPolygon->area * flFormFactor;
  }
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1001C820
// Name: float FormFactorDiffToDiff(struct CPatch __near *,struct CPatch __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl FormFactorDiffToDiff(CPatch *pDiff1, CPatch *pDiff2)
{
  double v2; // st7
  Vector vDelta; // [esp+8h] [ebp-Ch] BYREF

  vDelta.x = pDiff1->origin.x - pDiff2->origin.x;
  vDelta.y = pDiff1->origin.y - pDiff2->origin.y;
  vDelta.z = pDiff1->origin.z - pDiff2->origin.z;
  v2 = VectorNormalize(vec: &vDelta);
  return -((vDelta.x * pDiff1->normal.x + vDelta.y * pDiff1->normal.y + vDelta.z * pDiff1->normal.z)
         * (pDiff2->normal.z * vDelta.z + pDiff2->normal.x * vDelta.x + pDiff2->normal.y * vDelta.y)
         / (v2
          * v2));
}

//------------------------------------------------------------------------------
// Address: 0x1001C8A0
// Name: void WriteWinding(void __near *,struct winding_t __near *,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteWinding(void *out, winding_t *w, Vector *color)
{
  int v4; // ebx
  int i; // [esp+48h] [ebp+Ch]

  CmdLib_FPrintf(hFile: out, pFormat: "%i\n", w->numpoints);
  v4 = 0;
  for ( i = 0; i < w->numpoints; ++i )
  {
    CmdLib_FPrintf(
      hFile: out,
      pFormat: "%5.2f %5.2f %5.2f %5.3f %5.3f %5.3f\n",
      w->p[v4].x,
      w->p[v4].y,
      w->p[v4].z,
      (float)(color->x * 0.00390625),
      (float)(color->y * 0.00390625),
      (float)(color->z * 0.00390625));
    ++v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C970
// Name: void WriteNormal(void __near *,class Vector const __near &,class Vector const __near &,float,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteNormal(void *out, const Vector *nPos, const Vector *nDir, float length, const Vector *color)
{
  CmdLib_FPrintf(hFile: out, pFormat: "2\n");
  CmdLib_FPrintf(
    hFile: out,
    pFormat: "%5.2f %5.2f %5.2f %5.3f %5.3f %5.3f\n",
    nPos->x,
    nPos->y,
    nPos->z,
    (float)(color->x * 0.00390625),
    (float)(color->y * 0.00390625),
    (float)(color->z * 0.00390625));
  CmdLib_FPrintf(
    hFile: out,
    pFormat: "%5.2f %5.2f %5.2f %5.3f %5.3f %5.3f\n",
    (float)((float)(nDir->x * length) + nPos->x),
    (float)((float)(nDir->y * length) + nPos->y),
    (float)((float)(nDir->z * length) + nPos->z),
    (float)(color->x * 0.00390625),
    (float)(color->y * 0.00390625),
    (float)(color->z * 0.00390625));
}

//------------------------------------------------------------------------------
// Address: 0x1001CAA0
// Name: void WriteTrace(char const __near *,class FourRays const __near &,struct RayTracingResult const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteTrace(const char *pFileName, const FourRays *rays, const RayTracingResult *result)
{
  void *v3; // edi
  const FourRays *v4; // eax
  __m128 *p_y; // ebx
  int v6; // ecx
  __m128 *p_z; // esi
  float v8; // xmm2_4
  float v9; // [esp+48h] [ebp-38h]
  float v10; // [esp+4Ch] [ebp-34h]
  float v11; // [esp+50h] [ebp-30h]
  float vecOrigin; // [esp+54h] [ebp-2Ch]
  float vecOrigin_4; // [esp+58h] [ebp-28h]
  float vecOrigin_8; // [esp+5Ch] [ebp-24h]
  Vector vecEnd; // [esp+60h] [ebp-20h] BYREF
  int v16; // [esp+6Ch] [ebp-14h]
  int v17; // [esp+70h] [ebp-10h]
  int v18; // [esp+74h] [ebp-Ch]
  int v19; // [esp+78h] [ebp-8h]
  int v20; // [esp+7Ch] [ebp-4h]

  v3 = g_pFileSystem->Open(this: g_pFileSystem, a2: pFileName, a3: "a", a4: 0);
  if ( v3 == nullptr )
    _Error(a1: "Couldn't open %s", pFileName);
  v4 = rays;
  p_y = &result->surface_normal.y;
  v16 = (char *)result - (char *)rays;
  v18 = -32 - (_DWORD)rays;
  v6 = -16 - (_DWORD)rays;
  p_z = &rays->origin.z;
  v19 = -16 - (_DWORD)rays;
  v17 = 16 - (_DWORD)result;
  v20 = 4;
  while ( 1 )
  {
    vecOrigin = p_z[-2].m128_f32[0];
    vecOrigin_4 = p_z[-1].m128_f32[0];
    vecOrigin_8 = p_z->m128_f32[0];
    LODWORD(vecEnd.x) = *(int *)((char *)v4->direction.x.m128_i32 + (_DWORD)p_z + v18);
    LODWORD(vecEnd.y) = *(int *)((char *)v4->direction.x.m128_i32 + (_DWORD)p_z + v6);
    LODWORD(vecEnd.z) = *(int *)((char *)v4->direction.x.m128_i32 + (_DWORD)p_y + v17);
    VectorNormalize(vec: &vecEnd);
    v8 = p_y[3].m128_f32[0];
    vecEnd.x = (float)(vecEnd.x * v8) + vecOrigin;
    vecEnd.y = vecOrigin_4 + (float)(v8 * vecEnd.y);
    vecEnd.z = (float)(vecEnd.z * v8) + vecOrigin_8;
    CmdLib_FPrintf(hFile: v3, pFormat: "2\n");
    CmdLib_FPrintf(
      hFile: v3,
      pFormat: "%5.2f %5.2f %5.2f %5.3f %5.3f %5.3f\n",
      vecOrigin,
      vecOrigin_4,
      vecOrigin_8,
      1.0,
      0.0,
      0.0);
    CmdLib_FPrintf(
      hFile: v3,
      pFormat: "%5.2f %5.2f %5.2f %5.3f %5.3f %5.3f\n",
      vecEnd.x,
      vecEnd.y,
      vecEnd.z,
      1.0,
      0.0,
      0.0);
    v9 = p_y[-1].m128_f32[0];
    v10 = p_y->m128_f32[0];
    v11 = *(float *)((char *)p_z->m128_f32 + v16);
    CmdLib_FPrintf(hFile: v3, pFormat: "2\n");
    CmdLib_FPrintf(
      hFile: v3,
      pFormat: "%5.2f %5.2f %5.2f %5.3f %5.3f %5.3f\n",
      vecEnd.x,
      vecEnd.y,
      vecEnd.z,
      1.0,
      1.03515625,
      0.0);
    CmdLib_FPrintf(
      hFile: v3,
      pFormat: "%5.2f %5.2f %5.2f %5.3f %5.3f %5.3f\n",
      (float)((float)(v9 * 10.0) + vecEnd.x),
      (float)((float)(v10 * 10.0) + vecEnd.y),
      (float)((float)(v11 * 10.0) + vecEnd.z),
      1.0,
      1.03515625,
      0.0);
    p_y = (__m128 *)((char *)p_y + 4);
    p_z = (__m128 *)((char *)p_z + 4);
    if ( --v20 == 0 )
      break;
    v4 = rays;
    v6 = v19;
  }
  g_pFileSystem->Close(this: g_pFileSystem, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1001CD90
// Name: void PreGetBumpNormalsForDisp(struct texinfo_s __near *,class Vector __near &,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PreGetBumpNormalsForDisp(texinfo_s *pTexinfo, Vector *vecU, Vector *vecV, Vector *vecNormal)
{
  float y; // xmm4_4
  float z; // xmm5_4
  float v6; // xmm1_4
  float x; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  matrix3x4_t matTmp; // [esp+0h] [ebp-C0h] BYREF
  matrix3x4_t matLight; // [esp+30h] [ebp-90h] BYREF
  matrix3x4_t matTex; // [esp+60h] [ebp-60h] BYREF
  Vector vecTexU; // [esp+90h] [ebp-30h] BYREF
  Vector vecTexV; // [esp+9Ch] [ebp-24h] BYREF
  Vector vecLightV; // [esp+A8h] [ebp-18h] BYREF
  Vector vecLightU; // [esp+B4h] [ebp-Ch] BYREF

  vecTexU = *(Vector *)&pTexinfo->textureVecsTexelsPerWorldUnits[0][0];
  vecTexV = *(Vector *)&pTexinfo->textureVecsTexelsPerWorldUnits[1][0];
  vecLightU = *(Vector *)&pTexinfo->lightmapVecsLuxelsPerWorldUnits[0][0];
  vecLightV = *(Vector *)&pTexinfo->lightmapVecsLuxelsPerWorldUnits[1][0];
  VectorNormalize(vec: &vecTexU);
  VectorNormalize(vec: &vecTexV);
  VectorNormalize(vec: &vecLightU);
  VectorNormalize(vec: &vecLightV);
  y = vecTexU.y;
  z = vecTexU.z;
  v6 = vecTexV.y;
  x = vecTexV.x;
  v8 = vecTexV.z;
  if ( COERCE_FLOAT(
         COERCE_UNSIGNED_INT(
           (float)((float)(vecLightV.y * vecTexV.y) + (float)(vecLightV.x * vecTexV.x))
         + (float)(vecLightV.z * vecTexV.z))
       & _mask__AbsFloat_) >= 0.99900001
    && COERCE_FLOAT(
         COERCE_UNSIGNED_INT(
           (float)((float)(vecTexU.y * vecLightU.y) + (float)(vecLightU.x * vecTexU.x))
         + (float)(vecLightU.z * vecTexU.z))
       & _mask__AbsFloat_) >= 0.99900001 )
  {
    vecU->x = vecTexU.x;
    vecU->y = y;
    vecU->z = z;
    vecV->x = x;
    vecV->y = v6;
    vecV->z = v8;
  }
  else
  {
    matTex.m_flMatVal[0][2] = vecNormal->x;
    *(_QWORD *)&matLight.m_flMatVal[1][0] = __PAIR64__(LODWORD(vecLightV.y), LODWORD(vecLightU.y));
    *(_QWORD *)&matTex.m_flMatVal[0][0] = __PAIR64__(LODWORD(vecTexV.x), LODWORD(vecTexU.x));
    *(_QWORD *)&matTex.m_flMatVal[1][0] = __PAIR64__(LODWORD(vecTexV.y), LODWORD(vecTexU.y));
    v9 = vecNormal->y;
    *(_QWORD *)&matTex.m_flMatVal[2][0] = __PAIR64__(LODWORD(vecTexV.z), LODWORD(vecTexU.z));
    v10 = vecNormal->z;
    matLight.m_flMatVal[0][0] = vecLightU.x;
    *(_QWORD *)&matLight.m_flMatVal[2][0] = __PAIR64__(LODWORD(vecLightV.z), LODWORD(vecLightU.z));
    matTex.m_flMatVal[0][3] = vec3_origin.x;
    *(_QWORD *)&matTex.m_flMatVal[1][2] = __PAIR64__(LODWORD(vec3_origin.y), LODWORD(v9));
    *(_QWORD *)&matTex.m_flMatVal[2][2] = __PAIR64__(LODWORD(vec3_origin.z), LODWORD(v10));
    *(_QWORD *)&matLight.m_flMatVal[0][1] = __PAIR64__(LODWORD(matTex.m_flMatVal[0][2]), LODWORD(vecLightV.x));
    matLight.m_flMatVal[0][3] = vec3_origin.x;
    *(_QWORD *)&matLight.m_flMatVal[1][2] = __PAIR64__(LODWORD(vec3_origin.y), LODWORD(v9));
    *(_QWORD *)&matLight.m_flMatVal[2][2] = __PAIR64__(LODWORD(vec3_origin.z), LODWORD(v10));
    ConcatTransforms(in1: &matLight, in2: &matTex, out: &matTmp);
    MatrixGetColumn(in: &matTmp, column: 0, out: vecU);
    MatrixGetColumn(in: &matTmp, column: 1, out: vecV);
    MatrixGetColumn(in: &matTmp, column: 2, out: vecNormal);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D020
// Name: void InitDumpPatchesFiles(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitDumpPatchesFiles()
{
  int v0; // ebx
  void **v1; // esi
  int i; // edi
  void *v3; // eax
  char szFilename[260]; // [esp+Ch] [ebp-104h] BYREF

  v0 = 0;
  v1 = pFileSamples[0];
  do
  {
    for ( i = 0; i < 4; ++i )
    {
      sprintf(string: szFilename, format: "samples_style%d_bump%d.txt", v0, i);
      v3 = g_pFileSystem->Open(this: g_pFileSystem, a2: szFilename, a3: "w", a4: 0);
      *v1 = v3;
      if ( v3 == nullptr )
        _Error(a1: "Can't open %s for -dump.\n", szFilename);
      ++v1;
    }
    ++v0;
  }
  while ( (int)v1 < (int)&num_sky_cameras );
}

//------------------------------------------------------------------------------
// Address: 0x1001D0A0
// Name: void VRAD_Finish(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VRAD_Finish()
{
  _iobuf *v0; // eax
  void **v1; // esi
  int i; // edi
  CVradStaticPropMgr *v3; // eax
  char str[512]; // [esp+4h] [ebp-208h] BYREF
  double end; // [esp+204h] [ebp-8h]

  _Msg(a1: "Ready to Finish\n");
  v0 = __iob_func();
  fflush(stream: v0 + 1);
  if ( verbose != 0 )
    PrintBSPFileSizes();
  _Msg(a1: "Writing %s\n", platformPath);
  VMPI_SetCurrentStage(pCurStage: "WriteBSPFile");
  WriteBSPFile(filename: platformPath, pUnused: nullptr);
  if ( g_bDumpPatches != 0 )
  {
    v1 = pFileSamples[0];
    do
    {
      for ( i = 4; i != 0; --i )
        g_pFileSystem->Close(this: g_pFileSystem, a2: *v1++);
    }
    while ( (int)v1 < (int)&num_sky_cameras );
  }
  CloseDispLuxels();
  v3 = StaticPropMgr();
  v3->Shutdown(this: v3);
  end = _Plat_FloatTime();
  GetHourMinuteSecondsString(nInputSeconds: (int)(end - g_flStartTime), pOut: str, outLen: 512);
  _Msg(a1: "%s elapsed\n", str);
  ReleasePakFileLumps();
}

//------------------------------------------------------------------------------
// Address: 0x1001D190
// Name: void VRAD_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VRAD_Init()
{
  MathLib_Init(
    gamma: 2.2,
    texGamma: 2.2,
    brightness: 0.0,
    overbright: 2,
    bAllow3DNow: false,
    bAllowSSE: false,
    bAllowSSE2: false,
    bAllowMMX: false);
  InstallAllocationFunctions();
  InstallSpewFunction();
}

//------------------------------------------------------------------------------
// Address: 0x1001D1D0
// Name: int ParseCommandLine(int,char __near * __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ParseCommandLine(int argc, char **argv, bool *onlydetail)
{
  int v3; // esi
  char *v5; // ecx
  char *v6; // edx
  char v7; // al
  long double v8; // st7
  long double v9; // st7
  long double v10; // st7
  long double v11; // st7
  long double v12; // st7
  long double v13; // st7

  *onlydetail = false;
  SetHDRMode(bHDR: false);
  v3 = 1;
  if ( argc <= 1 )
    return v3;
  while ( 1 )
  {
    if ( _V_stricmp(s1: argv[v3], s2: "-StaticPropLighting") == 0 )
    {
      g_bStaticPropLighting = true;
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-StaticPropLighting3") == 0 )
    {
      g_bStaticPropLighting = true;
      g_numVradStaticPropsLightingStreams = 3;
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-StaticPropNormals") == 0 )
    {
      g_bShowStaticPropNormals = true;
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-OnlyStaticProps") == 0 )
    {
      g_bOnlyStaticProps = true;
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-StaticPropPolys") == 0 )
    {
      g_bStaticPropPolys = true;
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-nossprops") == 0 )
    {
      g_bDisablePropSelfShadowing = true;
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-textureshadows") == 0 )
    {
      g_bTextureShadows = true;
      goto LABEL_124;
    }
    if ( strcmp(argv[v3], "-dump") == 0 )
    {
      g_bDumpPatches = 1;
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-nodetaillight") == 0 )
    {
      g_bNoDetailLighting = true;
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-rederrors") == 0 )
    {
      bRed2Black = false;
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-dumpnormals") == 0 )
    {
      bDumpNormals = true;
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-dumptrace") == 0 )
    {
      g_bDumpRtEnv = true;
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-LargeDispSampleRadius") == 0 )
    {
      g_bLargeDispSampleRadius = true;
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-bounce") == 0 )
    {
      if ( ++v3 >= argc )
      {
        _Warning(a1: "Error: expected a value after '-bounce'\n");
        return 1;
      }
      numbounce = atoi(nptr: argv[v3]);
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-verbose") == 0 || _V_stricmp(s1: argv[v3], s2: "-v") == 0 )
    {
      verbose = 1;
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-threads") == 0 )
    {
      if ( ++v3 >= argc )
      {
        _Warning(a1: "Error: expected a value after '-threads'\n");
        return 1;
      }
      numthreads = atoi(nptr: argv[v3]);
      if ( (int)numthreads <= 0 )
      {
        _Warning(a1: "Error: expected positive value after '-threads'\n");
        return 1;
      }
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-lights") == 0 )
    {
      if ( ++v3 >= argc || *(v5 = argv[v3]) == 0 )
      {
        _Warning(a1: "Error: expected a filepath after '-lights'\n");
        return 1;
      }
      v6 = designer_lights;
      do
      {
        v7 = *v5;
        *v6++ = *v5++;
      }
      while ( v7 != 0 );
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-noextra") == 0 )
    {
      do_extra = 0;
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-debugextra") == 0 )
    {
      debug_extra = true;
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-fastambient") == 0 )
    {
      g_bFastAmbient = true;
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-fast") == 0 )
    {
      do_fast = 1;
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-noskyboxrecurse") == 0 )
    {
      g_bNoSkyRecurse = true;
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-final") == 0 )
    {
      g_flSkySampleScale = 16.0;
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-finitefalloff") == 0 )
    {
      g_bFiniteFalloffModel = true;
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-extrasky") == 0 )
    {
      if ( ++v3 >= argc || *argv[v3] == 0 )
      {
        _Warning(a1: "Error: expected a scale factor after '-extrasky'\n");
        return 1;
      }
      g_flSkySampleScale = atof(nptr: argv[v3]);
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-centersamples") == 0 )
    {
      do_centersamples = 1;
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-smooth") == 0 )
    {
      if ( ++v3 >= argc )
      {
        _Warning(a1: "Error: expected an angle after '-smooth'\n");
        return 1;
      }
      smoothing_threshold = cos(atof(nptr: argv[v3]) * 0.0174532925199433);
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-dlightmap") == 0 )
    {
      dlight_map = 1;
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-luxeldensity") == 0 )
    {
      if ( ++v3 >= argc )
      {
        _Warning(a1: "Error: expected a value after '-luxeldensity'\n");
        return 1;
      }
      v8 = atof(nptr: argv[v3]);
      luxeldensity = v8;
      if ( v8 > 1.0 )
        luxeldensity = 1.0 / luxeldensity;
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-low") == 0 )
    {
      g_bLowPriority = 1;
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-loghash") == 0 )
    {
      g_bLogHashData = 1;
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-onlydetail") == 0 )
    {
      *onlydetail = true;
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-softsun") == 0 )
    {
      if ( ++v3 >= argc )
      {
        _Warning(a1: "Error: expected an angular extent value (0..180) '-softsun'\n");
        return 1;
      }
      v9 = sin(atof(nptr: argv[v3]) * 0.0174532925199433);
      g_SunAngularExtent = v9;
      printf(format: "sun extent=%f\n", (double)v9);
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-maxdispsamplesize") == 0 )
    {
      if ( ++v3 >= argc )
      {
        _Warning(a1: "Error: expected a sample size after '-maxdispsamplesize'\n");
        return 1;
      }
      g_flMaxDispSampleSize = atof(nptr: argv[v3]);
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-StopOnExit") == 0 )
    {
      g_bStopOnExit = true;
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-steam") == 0
      || _V_stricmp(s1: argv[v3], s2: "-allowdebug") == 0
      || _V_stricmp(s1: argv[v3], s2: "-NoVConfig") == 0 )
    {
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-vproject") == 0 || _V_stricmp(s1: argv[v3], s2: "-game") == 0 )
    {
      ++v3;
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-FullMinidumps") == 0 )
    {
      EnableFullMinidumps(bFull: true);
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-hdr") == 0 )
    {
      SetHDRMode(bHDR: true);
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-ldr") == 0 )
    {
      SetHDRMode(bHDR: false);
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-maxchop") == 0 )
    {
      if ( ++v3 >= argc )
      {
        _Warning(a1: "Error: expected a value after '-maxchop'\n");
        return 1;
      }
      v10 = atof(nptr: argv[v3]);
      maxchop = v10;
      if ( v10 < 1.0 )
      {
        _Warning(a1: "Error: expected positive value after '-maxchop'\n");
        return 1;
      }
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-chop") == 0 )
    {
      if ( ++v3 >= argc )
      {
        _Warning(a1: "Error: expected a value after '-chop'\n");
        return 1;
      }
      v11 = atof(nptr: argv[v3]);
      minchop = v11;
      if ( v11 < 1.0 )
      {
        _Warning(a1: "Error: expected positive value after '-chop'\n");
        return 1;
      }
      if ( maxchop <= minchop )
        minchop = maxchop;
      goto LABEL_124;
    }
    if ( _V_stricmp(s1: argv[v3], s2: "-dispchop") != 0 )
      break;
    if ( ++v3 >= argc )
    {
      _Warning(a1: "Error: expected a value after '-dispchop'\n");
      return 1;
    }
    v12 = atof(nptr: argv[v3]);
    dispchop = v12;
    if ( v12 < 1.0 )
    {
      _Warning(a1: "Error: expected positive value after '-dipschop'\n");
      return 1;
    }
LABEL_124:
    if ( ++v3 >= argc )
      return v3;
  }
  if ( _V_stricmp(s1: argv[v3], s2: "-disppatchradius") != 0 )
  {
    if ( _V_stricmp(s1: argv[v3], s2: "-tempcontent") != 0 )
    {
      if ( V_strncasecmp(s1: argv[v3], s2: "-mpi", n: 4) != 0 && V_strncasecmp(s1: argv[v3 - 1], s2: "-mpi", n: 4) != 0 )
        return v3;
      if ( _V_stricmp(s1: argv[v3], s2: "-mpi") == 0 )
        g_bUseMPI = true;
      if ( v3 == argc - 1 && _V_stricmp(s1: argv[v3], s2: "-mpi_ListParams") != 0 )
        return v3;
    }
    goto LABEL_124;
  }
  if ( ++v3 < argc )
  {
    v13 = atof(nptr: argv[v3]);
    g_MaxDispPatchRadius = v13;
    if ( v13 < 10.0 )
    {
      _Warning(a1: "Error: g_MaxDispPatchRadius < 10.0\n");
      return 1;
    }
    goto LABEL_124;
  }
  _Warning(a1: "Error: expected a value after '-disppatchradius'\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001DC20
// Name: void PrintCommandLine(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrintCommandLine(int argc, char **argv)
{
  int i; // esi

  _Warning(a1: "Command line: ");
  for ( i = 0; i < argc; ++i )
    _Warning(a1: "\"%s\" ", argv[i]);
  _Warning(a1: "\n\n");
}

//------------------------------------------------------------------------------
// Address: 0x1001DC70
// Name: public: void CUtlBlockMemory<struct CacheOptimizedTriangle,int>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBlockMemory<CacheOptimizedTriangle,int>::Purge(CUtlBlockMemory<CacheOptimizedTriangle,int> *this)
{
  int i; // edi

  if ( this->m_pMemory != nullptr )
  {
    for ( i = 0; i < this->m_nBlocks; ++i )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pMemory[i]);
    this->m_nBlocks = 0;
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pMemory);
    this->m_pMemory = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001DCC0
// Name: protected: void CUtlBlockMemory<struct CacheOptimizedTriangle,int>::ChangeSize(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBlockMemory<CacheOptimizedTriangle,int>::ChangeSize(
        CUtlBlockMemory<CacheOptimizedTriangle,int> *this,
        int nBlocks)
{
  int v2; // ebx
  int m_nBlocks; // edi
  IMemAlloc_vtbl *v5; // edx
  CacheOptimizedTriangle **v6; // eax
  unsigned int v7; // ebx

  v2 = nBlocks;
  m_nBlocks = this->m_nBlocks;
  this->m_nBlocks = nBlocks;
  if ( nBlocks < m_nBlocks )
  {
    do
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pMemory[v2++]);
    while ( v2 < m_nBlocks );
  }
  v5 = _g_pMemAlloc->__vftable;
  if ( this->m_pMemory != nullptr )
    v6 = (CacheOptimizedTriangle **)((int (__stdcall *)(CacheOptimizedTriangle **, int))v5->Realloc_2)(
                                      a1: this->m_pMemory,
                                      a2: 4 * this->m_nBlocks);
  else
    v6 = (CacheOptimizedTriangle **)((int (__stdcall *)(int))v5->Alloc_2)(a1: 4 * this->m_nBlocks);
  this->m_pMemory = v6;
  if ( v6 == nullptr )
    _Error(a1: "CUtlBlockMemory overflow!\n");
  if ( m_nBlocks < this->m_nBlocks )
  {
    v7 = 16 * (3 * ((32 * *((_DWORD *)this + 2)) >> 5) + 3);
    do
      this->m_pMemory[m_nBlocks++] = (CacheOptimizedTriangle *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
    while ( m_nBlocks < this->m_nBlocks );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001DE10
// Name: public: struct CPatch __near & CPatch::operator=(struct CPatch const __near &)
// Source: json
//------------------------------------------------------------------------------
CPatch *__thiscall CPatch::operator=(CPatch *this, const CPatch *__that)
{
  CPatch *result; // eax
  int v3; // edx
  int v4; // esi

  result = this;
  this->winding = __that->winding;
  this->mins = __that->mins;
  this->maxs = __that->maxs;
  this->face_mins = __that->face_mins;
  this->face_maxs = __that->face_maxs;
  this->origin = __that->origin;
  this->plane = __that->plane;
  this->m_IterationKey = __that->m_IterationKey;
  *((_DWORD *)this + 18) ^= (*((_DWORD *)__that + 18) ^ *((_DWORD *)this + 18)) & 3;
  v3 = *((_DWORD *)result + 18)
     ^ ((unsigned __int8)*((_DWORD *)result + 18)
      ^ (unsigned __int8)*((_DWORD *)__that + 18))
     & 4;
  *((_DWORD *)this + 18) = v3;
  v4 = v3 ^ ((unsigned __int8)v3 ^ (unsigned __int8)*((_DWORD *)__that + 18)) & 8;
  *((_DWORD *)this + 18) = v4;
  *((_DWORD *)this + 18) = *((_DWORD *)__that + 18)
                         ^ ((unsigned __int8)v4
                          ^ (unsigned __int8)*((_DWORD *)__that + 18))
                         & 0xF;
  this->normal = __that->normal;
  this->planeDist = __that->planeDist;
  this->chop = __that->chop;
  this->luxscale = __that->luxscale;
  *(_QWORD *)this->scale = *(_QWORD *)__that->scale;
  this->totallight = __that->totallight;
  this->baselight = __that->baselight;
  this->basearea = __that->basearea;
  this->directlight = __that->directlight;
  this->area = __that->area;
  this->reflectivity = __that->reflectivity;
  this->samplelight = __that->samplelight;
  this->samplearea = __that->samplearea;
  this->faceNumber = __that->faceNumber;
  this->clusterNumber = __that->clusterNumber;
  this->parent = __that->parent;
  this->child1 = __that->child1;
  this->child2 = __that->child2;
  this->ndxNext = __that->ndxNext;
  this->ndxNextParent = __that->ndxNextParent;
  this->ndxNextClusterChild = __that->ndxNextClusterChild;
  this->numtransfers = __that->numtransfers;
  this->transfers = __that->transfers;
  this->indices[0] = __that->indices[0];
  this->indices[1] = __that->indices[1];
  this->indices[2] = __that->indices[2];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001E160
// Name: void BaseLightForFace(struct dface_t __near *,class Vector __near &,float __near *,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BaseLightForFace(dface_t *f, Vector *light, float *parea, Vector *reflectivity)
{
  dtexdata_t *v4; // esi
  char *String; // eax
  float v6; // xmm0_4

  v4 = &dtexdata[texinfo.m_Memory.m_pMemory[f->texinfo].texdata];
  String = (char *)TexDataStringTable_GetString(stringID: v4->nameStringTableID);
  LightForTexture(name: String, result: light);
  *parea = (float)(v4->width * v4->height);
  v6 = reflectivityScale;
  reflectivity->x = v4->reflectivity.x * reflectivityScale;
  reflectivity->y = v4->reflectivity.y * v6;
  reflectivity->z = v4->reflectivity.z * v6;
  if ( reflectivity->x > 0.99 )
    reflectivity->x = 0.99000001;
  if ( reflectivity->y > 0.99 )
    reflectivity->y = 0.99000001;
  if ( reflectivity->z > 0.99 )
    reflectivity->z = 0.99000001;
}

//------------------------------------------------------------------------------
// Address: 0x1001E230
// Name: void MakeTransfer(int,int,struct transfer_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MakeTransfer(int ndxPatch1, int ndxPatch2, transfer_t *all_transfers)
{
  double v3; // rdi
  int v4; // ebx
  double v5; // st7
  float v6; // xmm1_4
  double v7; // st7
  float v8; // xmm0_4
  float scale; // [esp+Ch] [ebp+8h]

  if ( ndxPatch1 != -1 && ndxPatch2 != -1 )
  {
    HIDWORD(v3) = &g_Patches.m_Memory.m_pMemory[ndxPatch2];
    LODWORD(v3) = &g_Patches.m_Memory.m_pMemory[ndxPatch1];
    if ( (texinfo.m_Memory.m_pMemory[g_pFaces[*(_DWORD *)(HIDWORD(v3) + 216)].texinfo].flags & 4) == 0 )
    {
      v4 = *(_DWORD *)(LODWORD(v3) + 248);
      if ( v4 < 0x40000 && *(float *)(HIDWORD(v3) + 184) > 0.0 )
      {
        v5 = FormFactorDiffToDiff(pDiff1: (CPatch *)HIDWORD(v3), pDiff2: (CPatch *)LODWORD(v3));
        scale = v5;
        if ( v5 > 0.0 )
        {
          v6 = *(float *)(LODWORD(v3) + 56) - *(float *)(HIDWORD(v3) + 56);
          if ( *(float *)(HIDWORD(v3) + 184) <= (float)((float)((float)((float)((float)(*(float *)(LODWORD(v3) + 52)
                                                                                      - *(float *)(HIDWORD(v3) + 52))
                                                                              * (float)(*(float *)(LODWORD(v3) + 52)
                                                                                      - *(float *)(HIDWORD(v3) + 52)))
                                                                      + (float)(v6 * v6))
                                                              + (float)((float)(*(float *)(LODWORD(v3) + 60)
                                                                              - *(float *)(HIDWORD(v3) + 60))
                                                                      * (float)(*(float *)(LODWORD(v3) + 60)
                                                                              - *(float *)(HIDWORD(v3) + 60))))
                                                      * 0.1256637061435917)
            || (v7 = FormFactorPolyToDiff(a1: v3, pPolygon: (CPatch *)HIDWORD(v3), pDifferential: (CPatch *)LODWORD(v3)),
                scale = v7,
                v7 > 0.0) )
          {
            v8 = *(float *)(HIDWORD(v3) + 184) * scale;
            if ( v8 > 0.0000001 )
            {
              all_transfers[v4].patch = (signed int)(HIDWORD(v3) - (unsigned int)g_Patches.m_Memory.m_pMemory) / 264;
              all_transfers[v4].transfer = v8;
              ++*(_DWORD *)(LODWORD(v3) + 248);
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E380
// Name: void MakeScales(int,struct transfer_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MakeScales(int ndxPatch, transfer_t *all_transfers)
{
  CPatch *v2; // esi
  int numtransfers; // eax
  unsigned __int8 *v4; // eax
  transfer_t *v5; // ecx
  float v6; // xmm1_4
  int v7; // edi
  float *p_transfer; // eax
  int v9; // edx
  float v10; // xmm0_4
  transfer_t *transfers; // eax
  int v12; // edx

  if ( ndxPatch != -1 )
  {
    v2 = &g_Patches.m_Memory.m_pMemory[ndxPatch];
    numtransfers = v2->numtransfers;
    if ( numtransfers != 0 )
    {
      if ( numtransfers > max_transfer )
        max_transfer = v2->numtransfers;
      v4 = calloc(count: 1u, size: 8 * v2->numtransfers);
      v2->transfers = (transfer_t *)v4;
      if ( v4 == nullptr )
        _Error(a1: "Memory allocation failure");
      v5 = all_transfers;
      v6 = 0.0;
      v7 = v2->numtransfers;
      if ( v7 > 0 )
      {
        p_transfer = &all_transfers->transfer;
        v9 = v2->numtransfers;
        do
        {
          v6 = v6 + *p_transfer;
          p_transfer += 2;
          --v9;
        }
        while ( v9 != 0 );
      }
      if ( v6 <= 3.141592653589793 )
        v10 = 0.31830987;
      else
        v10 = 1.0 / v6;
      transfers = v2->transfers;
      v12 = 0;
      if ( v7 > 0 )
      {
        do
        {
          transfers->transfer = v5->transfer * v10;
          transfers->patch = v5->patch;
          ++v12;
          ++transfers;
          ++v5;
        }
        while ( v12 < v2->numtransfers );
      }
      if ( v2->numtransfers > max_transfer )
        max_transfer = v2->numtransfers;
    }
    ThreadLock();
    total_transfer += v2->numtransfers;
    ThreadUnlock();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E4A0
// Name: void WriteWorld(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteWorld(char *name, int iBump)
{
  void *v2; // ebx
  int v3; // esi
  char *v4; // esi
  winding_t *v5; // edx
  int v6; // eax
  float v7; // xmm0_4
  char *v8; // eax
  float *v9; // edi
  bool v10; // zf
  double v11; // [esp+Ch] [ebp-74h]
  double v12; // [esp+14h] [ebp-6Ch]
  double v13; // [esp+1Ch] [ebp-64h]
  Vector light; // [esp+48h] [ebp-38h] BYREF
  Vector vGreen; // [esp+54h] [ebp-2Ch] BYREF
  float v16; // [esp+60h] [ebp-20h]
  float v17; // [esp+64h] [ebp-1Ch]
  float v18; // [esp+68h] [ebp-18h]
  float v19; // [esp+6Ch] [ebp-14h]
  float v20; // [esp+70h] [ebp-10h]
  float v21; // [esp+74h] [ebp-Ch]
  int m_Size; // [esp+78h] [ebp-8h]
  int v23; // [esp+7Ch] [ebp-4h]

  v2 = g_pFileSystem->Open(this: g_pFileSystem, a2: name, a3: "w", a4: 0);
  if ( v2 == nullptr )
    _Error(a1: "Couldn't open %s", name);
  if ( g_Patches.m_Size != 0 )
  {
    v3 = 0;
    v23 = 0;
    m_Size = g_Patches.m_Size;
    do
    {
      v4 = (char *)g_Patches.m_Memory.m_pMemory + v3;
      if ( *((_DWORD *)v4 + 57) == -1 )
      {
        v5 = *(winding_t **)v4;
        if ( *((_DWORD *)v4 + 55) == -1 )
        {
          vGreen.z = 0.0;
          vGreen.x = 0.0;
          vGreen.y = 256.0;
          WriteWinding(out: v2, w: v5, color: &vGreen);
        }
        else
        {
          v6 = 3 * iBump + 27;
          v7 = *(float *)&v4[4 * v6] + *((float *)v4 + 43);
          v8 = &v4[4 * v6];
          light.x = v7;
          light.y = *((float *)v8 + 1) + *((float *)v4 + 44);
          light.z = *((float *)v8 + 2) + *((float *)v4 + 45);
          WriteWinding(out: v2, w: v5, color: &light);
          if ( bDumpNormals )
          {
            v9 = *((float **)v4 + 16);
            v16 = *v9 * 255.0;
            v17 = v9[1] * 255.0;
            v18 = v9[2] * 255.0;
            CmdLib_FPrintf(hFile: v2, pFormat: "2\n");
            v19 = v16 * 0.00390625;
            v13 = *((float *)v4 + 15);
            v12 = *((float *)v4 + 14);
            v11 = *((float *)v4 + 13);
            v21 = v18 * 0.00390625;
            v20 = v17 * 0.00390625;
            CmdLib_FPrintf(
              hFile: v2,
              pFormat: "%5.2f %5.2f %5.2f %5.3f %5.3f %5.3f\n",
              v11,
              v12,
              v13,
              (float)(v16 * 0.00390625),
              (float)(v17 * 0.00390625),
              (float)(v18 * 0.00390625));
            CmdLib_FPrintf(
              hFile: v2,
              pFormat: "%5.2f %5.2f %5.2f %5.3f %5.3f %5.3f\n",
              (float)((float)(*v9 * 15.0) + *((float *)v4 + 13)),
              (float)((float)(v9[1] * 15.0) + *((float *)v4 + 14)),
              (float)((float)(v9[2] * 15.0) + *((float *)v4 + 15)),
              v19,
              v20,
              v21);
          }
        }
      }
      v3 = v23 + 264;
      v10 = m_Size-- == 1;
      v23 += 264;
    }
    while ( !v10 );
  }
  g_pFileSystem->Close(this: g_pFileSystem, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1001E720
// Name: void CollectLight(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollectLight(Vector *total)
{
  int v1; // edx
  int v2; // ebx
  int v3; // ecx
  int v4; // edi
  _DWORD *v5; // edi
  int v6; // esi
  Vector *m_pMemory; // eax
  int v8; // eax
  int v9; // eax
  unsigned int v10; // ecx
  unsigned int v11; // ebx
  float *v12; // eax
  bumplights_t *v13; // edx
  bumplights_t *v14; // edx
  bumplights_t *v15; // edx
  float *v16; // edx
  int v17; // edx
  float *v18; // edi
  int v19; // esi
  bumplights_t *v20; // eax
  float *v21; // eax
  bumplights_t *v22; // edx
  Vector *v23; // eax
  CPatch *v24; // edx
  CPatch *v25; // ebx
  float area; // xmm2_4
  float v27; // xmm1_4
  int v28; // eax
  float v29; // xmm0_4
  float v30; // xmm1_4
  float *p_z; // ecx
  float *v32; // eax
  float *p_y; // edx
  float *p_x; // ebx
  int v35; // ecx
  int v36; // esi
  float *v37; // eax
  Vector *v38; // edx
  float *v39; // eax
  int v40; // esi
  float *v41; // eax
  Vector *v42; // edx
  bumplights_t *v43; // eax
  bumplights_t *v44; // eax
  _DWORD *v45; // eax
  _DWORD *v46; // eax
  _DWORD *v47; // eax
  unsigned int v48; // [esp+4h] [ebp-30h]
  int v49; // [esp+8h] [ebp-2Ch]
  int v50; // [esp+Ch] [ebp-28h]
  int v51; // [esp+14h] [ebp-20h]
  int v52; // [esp+14h] [ebp-20h]
  CPatch *child2; // [esp+18h] [ebp-1Ch]
  int v54; // [esp+1Ch] [ebp-18h]
  int v55; // [esp+20h] [ebp-14h]
  unsigned int v56; // [esp+24h] [ebp-10h]
  int i; // [esp+28h] [ebp-Ch]
  CPatch *child1; // [esp+2Ch] [ebp-8h]
  int j; // [esp+30h] [ebp-4h]
  int ja; // [esp+30h] [ebp-4h]

  *(_QWORD *)&total->y = 0;
  total->x = 0.0;
  v1 = g_Patches.m_Size - 1;
  i = g_Patches.m_Size - 1;
  if ( g_Patches.m_Size - 1 >= 0 )
  {
    v2 = 48 * v1;
    v3 = 12 * v1;
    v4 = 264 * v1;
    v55 = 12 * v1;
    v56 = v1;
    v49 = 264 * v1;
    v54 = 48 * v1;
    while ( 1 )
    {
      v5 = (winding_t **)((char *)&g_Patches.m_Memory.m_pMemory->winding + v4);
      v6 = (v5[18] & 8) != 0 ? 4 : 1;
      if ( (v5[18] & 4) != 0 )
      {
        m_pMemory = emitlight.m_Memory.m_pMemory;
        *(float *)((char *)&emitlight.m_Memory.m_pMemory->z + v3) = 0.0;
        *(float *)((char *)&m_pMemory->y + v3) = 0.0;
        *(float *)((char *)&m_pMemory->x + v3) = 0.0;
      }
      else
      {
        v8 = v5[57];
        if ( v8 == -1 )
        {
          v9 = 0;
          if ( ((v5[18] & 8) != 0 ? 4 : 1) >= 4u )
          {
            v10 = v56 * 48;
            v11 = ((unsigned int)((v5[18] & 8) != 0 ? 0 : -3) >> 2) + 1;
            v12 = (float *)(v5 + 29);
            j = 4 * v11;
            do
            {
              v13 = addlight.m_Memory.m_pMemory;
              *(v12 - 2) = *(v12 - 2) + *(float *)((char *)&addlight.m_Memory.m_pMemory->light[0].x + v10);
              *(v12 - 1) = *(float *)((char *)&v13->light[0].y + v10) + *(v12 - 1);
              *v12 = *(float *)((char *)&v13->light[0].z + v10) + *v12;
              v14 = addlight.m_Memory.m_pMemory;
              v12[1] = *(float *)((char *)&addlight.m_Memory.m_pMemory->light[1].x + v10) + v12[1];
              v12[2] = *(float *)((char *)&v14->light[1].y + v10) + v12[2];
              v12[3] = *(float *)((char *)&v14->light[1].z + v10) + v12[3];
              v15 = addlight.m_Memory.m_pMemory;
              v12[4] = v12[4] + *(float *)((char *)&addlight.m_Memory.m_pMemory->light[2].x + v10);
              v12[5] = *(float *)((char *)&v15->light[2].y + v10) + v12[5];
              v12[6] = *(float *)((char *)&v15->light[2].z + v10) + v12[6];
              v16 = (float *)((char *)&addlight.m_Memory.m_pMemory->light[3].x + v10);
              v12[7] = *v16 + v12[7];
              v12[8] = v16[1] + v12[8];
              v12[9] = v16[2] + v12[9];
              v12 += 12;
              v10 += 48;
              --v11;
            }
            while ( v11 != 0 );
            v9 = j;
            v3 = v55;
            v2 = v54;
            v1 = i;
          }
          if ( v9 < v6 )
          {
            v17 = v9 + 4 * v1;
            v18 = (float *)&v5[3 * v9 + 29];
            v19 = v6 - v9;
            do
            {
              v20 = addlight.m_Memory.m_pMemory;
              *(v18 - 2) = addlight.m_Memory.m_pMemory->light[v17].x + *(v18 - 2);
              *(v18 - 1) = v20->light[v17].y + *(v18 - 1);
              *v18 = v20->light[v17++].z + *v18;
              v18 += 3;
              --v19;
            }
            while ( v19 != 0 );
            v2 = v54;
          }
          v21 = (float *)((char *)&emitlight.m_Memory.m_pMemory->x + v3);
          v22 = addlight.m_Memory.m_pMemory;
          *v21 = addlight.m_Memory.m_pMemory[v56].light[0].x;
          v21[1] = v22[v56].light[0].y;
          v21[2] = v22[v56].light[0].z;
          v23 = emitlight.m_Memory.m_pMemory;
          total->x = *(float *)((char *)&emitlight.m_Memory.m_pMemory->x + v3) + total->x;
          total->y = *(float *)((char *)&v23->y + v3) + total->y;
          total->z = *(float *)((char *)&v23->z + v3) + total->z;
        }
        else
        {
          v24 = &g_Patches.m_Memory.m_pMemory[v5[58]];
          v25 = &g_Patches.m_Memory.m_pMemory[v8];
          area = v24->area;
          v27 = 1.0 / (float)(v25->area + area);
          v28 = 0;
          child1 = v25;
          child2 = v24;
          v29 = v27 * v25->area;
          v30 = v27 * area;
          ja = 0;
          if ( ((v5[18] & 8) != 0 ? 4 : 1) >= 4u )
          {
            p_z = &v25->totallight.light[1].z;
            v32 = (float *)(v5 + 29);
            v51 = (char *)v25 - (char *)v5;
            p_y = &v24->totallight.light[2].y;
            v50 = (char *)child2 - (char *)v25;
            v48 = ((unsigned int)((v5[18] & 8) != 0 ? 0 : -3) >> 2) + 1;
            ja = 4 * v48;
            do
            {
              *(v32 - 2) = *(p_z - 5) * v29;
              *(v32 - 1) = *(float *)((char *)v32 + v51 - 4) * v29;
              *v32 = v29 * *(float *)((char *)v32 + v51);
              *(v32 - 2) = (float)(*(p_y - 7) * v30) + *(v32 - 2);
              *(v32 - 1) = (float)(*(float *)((char *)v32 + (char *)child2 - (char *)v5 - 4) * v30) + *(v32 - 1);
              *v32 = (float)(*(float *)((char *)v32 + v51 + v50) * v30) + *v32;
              v32[1] = *(p_z - 2) * v29;
              v32[2] = *(p_z - 1) * v29;
              v32[3] = *p_z * v29;
              v32[1] = (float)(*(p_y - 4) * v30) + v32[1];
              v32[2] = (float)(*(p_y - 3) * v30) + v32[2];
              v32[3] = (float)(*(float *)((char *)p_z + v50) * v30) + v32[3];
              v32[4] = p_z[1] * v29;
              v32[5] = p_z[2] * v29;
              v32[6] = p_z[3] * v29;
              v32[4] = (float)(*(p_y - 1) * v30) + v32[4];
              v32[5] = (float)(v30 * *p_y) + v32[5];
              v32[6] = (float)(p_y[1] * v30) + v32[6];
              v32[7] = p_z[4] * v29;
              v32[8] = p_z[5] * v29;
              v32[9] = p_z[6] * v29;
              v32[7] = (float)(p_y[2] * v30) + v32[7];
              v32[8] = (float)(p_y[3] * v30) + v32[8];
              v32[9] = (float)(p_y[4] * v30) + v32[9];
              v32 += 12;
              p_z += 12;
              p_y += 12;
              --v48;
            }
            while ( v48 != 0 );
            v24 = child2;
            v28 = ja;
            v3 = v55;
          }
          if ( v28 < v6 )
          {
            p_x = &v24->totallight.light[v28].x;
            v52 = (char *)child1 - (char *)v5;
            v35 = (char *)child1 - (char *)v24;
            v36 = v6 - ja;
            v37 = (float *)&v5[3 * v28 + 29];
            while ( 1 )
            {
              *(v37 - 2) = *(float *)((char *)p_x + v35) * v29;
              *(v37 - 1) = *(float *)((char *)v37 + v52 - 4) * v29;
              *v37 = *(float *)((char *)v37 + v52) * v29;
              *(v37 - 2) = (float)(v30 * *p_x) + *(v37 - 2);
              *(v37 - 1) = (float)(*(float *)((char *)v37 + (char *)v24 - (char *)v5 - 4) * v30) + *(v37 - 1);
              *v37 = (float)(*(float *)((char *)&v24->winding + (char *)v37 - (char *)v5) * v30) + *v37;
              p_x += 3;
              v37 += 3;
              if ( --v36 == 0 )
                break;
              v35 = (char *)child1 - (char *)v24;
            }
            v3 = v55;
          }
          v38 = emitlight.m_Memory.m_pMemory;
          v39 = (float *)((char *)&emitlight.m_Memory.m_pMemory->x + v3);
          v2 = v54;
          v40 = v5[57];
          *v39 = emitlight.m_Memory.m_pMemory[v5[57]].x * v29;
          v39[1] = v38[v40].y * v29;
          v39[2] = v38[v40].z * v29;
          v41 = (float *)((char *)&emitlight.m_Memory.m_pMemory->x + v3);
          v42 = &emitlight.m_Memory.m_pMemory[v5[58]];
          *v41 = (float)(v42->x * v30) + *(float *)((char *)&emitlight.m_Memory.m_pMemory->x + v3);
          v41[1] = (float)(v42->y * v30) + v41[1];
          v41[2] = (float)(v42->z * v30) + v41[2];
        }
        v1 = i;
      }
      v43 = addlight.m_Memory.m_pMemory;
      *(float *)((char *)&addlight.m_Memory.m_pMemory->light[0].x + v2) = 0.0;
      v49 -= 264;
      --v56;
      *(float *)((char *)&v43->light[0].z + v2) = 0.0;
      *(float *)((char *)&v43->light[0].y + v2) = 0.0;
      v44 = addlight.m_Memory.m_pMemory;
      *(float *)((char *)&addlight.m_Memory.m_pMemory->light[1].z + v2) = 0.0;
      v45 = (_DWORD *)((char *)&v44->light[1].x + v2);
      v45[1] = 0;
      *v45 = 0;
      v46 = (_DWORD *)((char *)&addlight.m_Memory.m_pMemory->light[2].x + v2);
      v46[2] = 0;
      v46[1] = 0;
      *v46 = 0;
      v47 = (_DWORD *)((char *)&addlight.m_Memory.m_pMemory->light[3].x + v2);
      --v1;
      v47[2] = 0;
      v3 -= 12;
      v2 -= 48;
      v47[1] = 0;
      *v47 = 0;
      i = v1;
      v55 = v3;
      v54 = v2;
      if ( v1 < 0 )
        break;
      v4 = v49;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001EDD0
// Name: void GatherLight(int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GatherLight()
{
  int ThreadWork; // edx
  float v1; // xmm2_4
  int numtransfers; // edi
  transfer_t *transfers; // esi
  CPatch *v4; // ebx
  bool v5; // zf
  int faceNumber; // eax
  CPatch *v7; // edi
  float y; // xmm4_4
  float z; // xmm5_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  int v18; // eax
  int v19; // ecx
  int v20; // ebx
  float v21; // xmm7_4
  float v22; // xmm3_4
  unsigned int v23; // ebx
  float transfer; // xmm5_4
  float v25; // xmm6_4
  float v26; // xmm3_4
  float v27; // xmm0_4
  float v28; // xmm6_4
  float v29; // xmm3_4
  float v30; // xmm4_4
  float v31; // xmm6_4
  float v32; // xmm4_4
  int v33; // edi
  float v34; // xmm5_4
  float v35; // xmm4_4
  float v36; // xmm0_4
  float v37; // xmm1_4
  bumplights_t *v38; // eax
  Vector vecTexV; // [esp+0h] [ebp-90h] BYREF
  Vector vecTexU; // [esp+Ch] [ebp-84h] BYREF
  int k; // [esp+18h] [ebp-78h]
  Vector normals[4]; // [esp+1Ch] [ebp-74h] BYREF
  Vector bumpSum[4]; // [esp+4Ch] [ebp-44h] BYREF
  Vector delta; // [esp+7Ch] [ebp-14h] BYREF
  int num; // [esp+88h] [ebp-8h]
  int j; // [esp+8Ch] [ebp-4h]

  ThreadWork = GetThreadWork();
  j = ThreadWork;
  if ( ThreadWork != -1 )
  {
    while ( 1 )
    {
      v1 = 0.0;
      numtransfers = g_Patches.m_Memory.m_pMemory[ThreadWork].numtransfers;
      transfers = g_Patches.m_Memory.m_pMemory[ThreadWork].transfers;
      v4 = &g_Patches.m_Memory.m_pMemory[ThreadWork];
      v5 = (*((_BYTE *)v4 + 72) & 8) == 0;
      num = numtransfers;
      if ( v5 )
      {
        v20 = 0;
        v21 = 0.0;
        v22 = 0.0;
        if ( numtransfers >= 4 )
        {
          v23 = ((unsigned int)(numtransfers - 4) >> 2) + 1;
          k = 4 * v23;
          do
          {
            transfer = transfers->transfer;
            v25 = transfers[1].transfer;
            v26 = (float)(v22
                        + (float)((float)(g_Patches.m_Memory.m_pMemory[transfers->patch].reflectivity.y
                                        * emitlight.m_Memory.m_pMemory[transfers->patch].y)
                                * transfer))
                + (float)((float)(g_Patches.m_Memory.m_pMemory[transfers[1].patch].reflectivity.y
                                * emitlight.m_Memory.m_pMemory[transfers[1].patch].y)
                        * v25);
            v27 = (float)(v21
                        + (float)((float)(g_Patches.m_Memory.m_pMemory[transfers->patch].reflectivity.z
                                        * emitlight.m_Memory.m_pMemory[transfers->patch].z)
                                * transfer))
                + (float)((float)(emitlight.m_Memory.m_pMemory[transfers[1].patch].z
                                * g_Patches.m_Memory.m_pMemory[transfers[1].patch].reflectivity.z)
                        * v25);
            v28 = transfers[2].transfer;
            v29 = v26
                + (float)((float)(g_Patches.m_Memory.m_pMemory[transfers[2].patch].reflectivity.y
                                * emitlight.m_Memory.m_pMemory[transfers[2].patch].y)
                        * v28);
            v30 = (float)((float)(emitlight.m_Memory.m_pMemory[transfers[2].patch].z
                                * g_Patches.m_Memory.m_pMemory[transfers[2].patch].reflectivity.z)
                        * v28)
                + v27;
            v31 = transfers[3].transfer;
            v1 = (float)((float)((float)(v1
                                       + (float)(transfer
                                               * (float)(g_Patches.m_Memory.m_pMemory[transfers->patch].reflectivity.x
                                                       * emitlight.m_Memory.m_pMemory[transfers->patch].x)))
                               + (float)(transfers[1].transfer
                                       * (float)(g_Patches.m_Memory.m_pMemory[transfers[1].patch].reflectivity.x
                                               * emitlight.m_Memory.m_pMemory[transfers[1].patch].x)))
                       + (float)(transfers[2].transfer
                               * (float)(g_Patches.m_Memory.m_pMemory[transfers[2].patch].reflectivity.x
                                       * emitlight.m_Memory.m_pMemory[transfers[2].patch].x)))
               + (float)(v31
                       * (float)(g_Patches.m_Memory.m_pMemory[transfers[3].patch].reflectivity.x
                               * emitlight.m_Memory.m_pMemory[transfers[3].patch].x));
            v22 = v29
                + (float)((float)(g_Patches.m_Memory.m_pMemory[transfers[3].patch].reflectivity.y
                                * emitlight.m_Memory.m_pMemory[transfers[3].patch].y)
                        * v31);
            v32 = v30
                + (float)((float)(emitlight.m_Memory.m_pMemory[transfers[3].patch].z
                                * g_Patches.m_Memory.m_pMemory[transfers[3].patch].reflectivity.z)
                        * v31);
            transfers += 4;
            --v23;
            v21 = v32;
          }
          while ( v23 != 0 );
          numtransfers = num;
          v20 = k;
          ThreadWork = j;
        }
        if ( v20 < numtransfers )
        {
          v33 = numtransfers - v20;
          do
          {
            v34 = transfers->transfer;
            v35 = g_Patches.m_Memory.m_pMemory[transfers->patch].reflectivity.x
                * emitlight.m_Memory.m_pMemory[transfers->patch].x;
            v36 = g_Patches.m_Memory.m_pMemory[transfers->patch].reflectivity.y
                * emitlight.m_Memory.m_pMemory[transfers->patch].y;
            v37 = g_Patches.m_Memory.m_pMemory[transfers->patch].reflectivity.z
                * emitlight.m_Memory.m_pMemory[transfers->patch].z;
            ++transfers;
            --v33;
            v1 = v1 + (float)(v34 * v35);
            v22 = v22 + (float)(v36 * v34);
            v21 = v21 + (float)(v37 * v34);
          }
          while ( v33 != 0 );
          ThreadWork = j;
        }
        v38 = &addlight.m_Memory.m_pMemory[ThreadWork];
        v38->light[0].x = v1;
        v38->light[0].y = v22;
        v38->light[0].z = v21;
      }
      else
      {
        faceNumber = v4->faceNumber;
        if ( g_pFaces[faceNumber].dispinfo == -1 )
        {
          GetPhongNormal(facenum: faceNumber, spot: &v4->origin, phongnormal: normals);
          GetBumpNormals(
            sVect: (float *)&texinfo.m_Memory.m_pMemory[g_pFaces[v4->faceNumber].texinfo],
            tVect: texinfo.m_Memory.m_pMemory[g_pFaces[v4->faceNumber].texinfo].textureVecsTexelsPerWorldUnits[1],
            flatNormal: &v4->normal,
            phongNormal: normals,
            bumpNormals: &normals[1]);
        }
        else
        {
          normals[0] = v4->normal;
          PreGetBumpNormalsForDisp(
            pTexinfo: &texinfo.m_Memory.m_pMemory[g_pFaces[faceNumber].texinfo],
            vecU: &vecTexU,
            vecV: &vecTexV,
            vecNormal: normals);
          GetBumpNormals(
            sVect: &vecTexU,
            tVect: &vecTexV,
            flatNormal: normals,
            phongNormal: normals,
            bumpNormals: &normals[1]);
        }
        normals[0] = v4->normal;
        memset(bumpSum, 0, sizeof(bumpSum));
        if ( numtransfers > 0 )
        {
          for ( num = numtransfers; num != 0; --num )
          {
            v7 = &g_Patches.m_Memory.m_pMemory[transfers->patch];
            delta.x = v7->origin.x - v4->origin.x;
            delta.y = v7->origin.y - v4->origin.y;
            delta.z = v7->origin.z - v4->origin.z;
            VectorNormalize(vec: &delta);
            y = delta.y;
            z = delta.z;
            v10 = (float)(1.0
                        / (float)((float)((float)(v4->normal.x * delta.x) + (float)(delta.y * v4->normal.y))
                                + (float)(v4->normal.z * delta.z)))
                * transfers->transfer;
            v11 = (float)(v7->reflectivity.x * emitlight.m_Memory.m_pMemory[transfers->patch].x) * v10;
            v12 = (float)(emitlight.m_Memory.m_pMemory[transfers->patch].y * v7->reflectivity.y) * v10;
            v13 = (float)(emitlight.m_Memory.m_pMemory[transfers->patch].z * v7->reflectivity.z) * v10;
            v14 = (float)((float)(delta.y * normals[0].y) + (float)(delta.x * normals[0].x))
                + (float)(delta.z * normals[0].z);
            if ( v14 > 0.0 )
            {
              y = delta.y;
              bumpSum[0].x = bumpSum[0].x + (float)(v11 * v14);
              z = delta.z;
              bumpSum[0].y = bumpSum[0].y + (float)(v12 * v14);
              bumpSum[0].z = bumpSum[0].z + (float)(v13 * v14);
            }
            v15 = (float)((float)(normals[1].y * y) + (float)(normals[1].x * delta.x)) + (float)(normals[1].z * z);
            if ( v15 > 0.0 )
            {
              y = delta.y;
              bumpSum[1].x = bumpSum[1].x + (float)(v11 * v15);
              z = delta.z;
              bumpSum[1].y = bumpSum[1].y + (float)(v12 * v15);
              bumpSum[1].z = bumpSum[1].z + (float)(v13 * v15);
            }
            v16 = (float)((float)(normals[2].y * y) + (float)(normals[2].x * delta.x)) + (float)(normals[2].z * z);
            if ( v16 > 0.0 )
            {
              y = delta.y;
              bumpSum[2].x = bumpSum[2].x + (float)(v11 * v16);
              z = delta.z;
              bumpSum[2].y = bumpSum[2].y + (float)(v12 * v16);
              bumpSum[2].z = bumpSum[2].z + (float)(v13 * v16);
            }
            v17 = (float)((float)(normals[3].y * y) + (float)(normals[3].x * delta.x)) + (float)(normals[3].z * z);
            if ( v17 > 0.0 )
            {
              bumpSum[3].x = bumpSum[3].x + (float)(v11 * v17);
              bumpSum[3].y = bumpSum[3].y + (float)(v12 * v17);
              bumpSum[3].z = bumpSum[3].z + (float)(v13 * v17);
            }
            ++transfers;
          }
        }
        v18 = j;
        v19 = j;
        addlight.m_Memory.m_pMemory[v19].light[0] = bumpSum[0];
        addlight.m_Memory.m_pMemory[v19].light[1] = bumpSum[1];
        addlight.m_Memory.m_pMemory[v18].light[2] = bumpSum[2];
        addlight.m_Memory.m_pMemory[v18].light[3] = bumpSum[3];
      }
      j = GetThreadWork();
      if ( j == -1 )
        break;
      ThreadWork = j;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F500
// Name: void BounceLight(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BounceLight()
{
  unsigned int v0; // eax
  unsigned int m_Size; // ebx
  int v2; // ecx
  int v3; // ecx
  unsigned int v4; // edi
  CPatch *m_pMemory; // esi
  Vector *v6; // edx
  int v7; // esi
  CPatch *v8; // edx
  CPatch *v9; // esi
  Vector *v10; // edx
  int v11; // edx
  CPatch *v12; // edx
  CPatch *v13; // esi
  Vector *v14; // edx
  int v15; // edx
  CPatch *v16; // edx
  CPatch *v17; // esi
  Vector *v18; // edx
  int v19; // edx
  _DWORD *v20; // edx
  unsigned int v21; // edx
  unsigned int v22; // esi
  unsigned int v23; // edi
  CPatch *v24; // ecx
  Vector *v25; // eax
  int p_totallight; // ecx
  bumplights_t *v27; // eax
  int v28; // ebx
  int v29; // esi
  int v30; // edi
  int v31; // eax
  char name[64]; // [esp+24h] [ebp-54h] BYREF
  Vector added; // [esp+64h] [ebp-14h] BYREF
  unsigned int i; // [esp+70h] [ebp-8h]
  int bouncing; // [esp+74h] [ebp-4h]

  v0 = 0;
  m_Size = g_Patches.m_Size;
  v2 = numbounce != 0;
  bouncing = v2;
  if ( g_Patches.m_Size >= 4 )
  {
    v3 = 0;
    v4 = ((unsigned int)(g_Patches.m_Size - 4) >> 2) + 1;
    i = 4 * v4;
    do
    {
      m_pMemory = g_Patches.m_Memory.m_pMemory;
      v6 = emitlight.m_Memory.m_pMemory;
      emitlight.m_Memory.m_pMemory[v3].x = *(float *)((char *)&g_Patches.m_Memory.m_pMemory->totallight.light[0].x + v0);
      v7 = (int)&m_pMemory->totallight + v0;
      v6[v3].y = *(float *)(v7 + 4);
      v6[v3].z = *(float *)(v7 + 8);
      v8 = g_Patches.m_Memory.m_pMemory;
      *(float *)((char *)&g_Patches.m_Memory.m_pMemory->totallight.light[0].z + v0) = 0.0;
      *(float *)((char *)&v8->totallight.light[0].y + v0) = 0.0;
      *(float *)((char *)&v8->totallight.light[0].x + v0) = 0.0;
      v9 = g_Patches.m_Memory.m_pMemory;
      v10 = emitlight.m_Memory.m_pMemory;
      emitlight.m_Memory.m_pMemory[v3 + 1].x = *(float *)((char *)&g_Patches.m_Memory.m_pMemory[1].totallight.light[0].x
                                                        + v0);
      v11 = (int)&v10[v3 + 1];
      *(float *)(v11 + 4) = *(float *)((char *)&v9[1].totallight.light[0].y + v0);
      *(float *)(v11 + 8) = *(float *)((char *)&v9[1].totallight.light[0].z + v0);
      v12 = g_Patches.m_Memory.m_pMemory;
      *(float *)((char *)&g_Patches.m_Memory.m_pMemory[1].totallight.light[0].z + v0) = 0.0;
      *(float *)((char *)&v12[1].totallight.light[0].y + v0) = 0.0;
      *(float *)((char *)&v12[1].totallight.light[0].x + v0) = 0.0;
      v13 = g_Patches.m_Memory.m_pMemory;
      v14 = emitlight.m_Memory.m_pMemory;
      emitlight.m_Memory.m_pMemory[v3 + 2].x = *(float *)((char *)&g_Patches.m_Memory.m_pMemory[2].totallight.light[0].x
                                                        + v0);
      v15 = (int)&v14[v3 + 2];
      *(float *)(v15 + 4) = *(float *)((char *)&v13[2].totallight.light[0].y + v0);
      *(float *)(v15 + 8) = *(float *)((char *)&v13[2].totallight.light[0].z + v0);
      v16 = g_Patches.m_Memory.m_pMemory;
      *(float *)((char *)&g_Patches.m_Memory.m_pMemory[2].totallight.light[0].z + v0) = 0.0;
      *(float *)((char *)&v16[2].totallight.light[0].y + v0) = 0.0;
      *(float *)((char *)&v16[2].totallight.light[0].x + v0) = 0.0;
      v17 = g_Patches.m_Memory.m_pMemory;
      v18 = emitlight.m_Memory.m_pMemory;
      emitlight.m_Memory.m_pMemory[v3 + 3].x = *(float *)((char *)&g_Patches.m_Memory.m_pMemory[3].totallight.light[0].x
                                                        + v0);
      v19 = (int)&v18[v3 + 3];
      *(float *)(v19 + 4) = *(float *)((char *)&v17[3].totallight.light[0].y + v0);
      v3 += 4;
      *(float *)(v19 + 8) = *(float *)((char *)&v17[3].totallight.light[0].z + v0);
      v20 = (_DWORD *)((char *)&g_Patches.m_Memory.m_pMemory[3].totallight + v0);
      v20[2] = 0;
      v0 += 1056;
      --v4;
      v20[1] = 0;
      *v20 = 0;
    }
    while ( v4 != 0 );
    v0 = i;
    v2 = bouncing;
  }
  if ( v0 < m_Size )
  {
    v21 = v0;
    v22 = v0;
    v23 = m_Size - v0;
    do
    {
      v24 = g_Patches.m_Memory.m_pMemory;
      v25 = emitlight.m_Memory.m_pMemory;
      emitlight.m_Memory.m_pMemory[v22].x = g_Patches.m_Memory.m_pMemory[v21].totallight.light[0].x;
      p_totallight = (int)&v24[v21].totallight;
      v25[v22++].y = *(float *)(p_totallight + 4);
      v25[v22 - 1].z = *(float *)(p_totallight + 8);
      v27 = &g_Patches.m_Memory.m_pMemory[v21++].totallight;
      --v23;
      v27->light[0].z = 0.0;
      v27->light[0].y = 0.0;
      v27->light[0].x = 0.0;
    }
    while ( v23 != 0 );
    v2 = bouncing;
  }
  v28 = 0;
  if ( v2 != 0 )
  {
    v29 = 1;
    do
    {
      while ( 1 )
      {
        v30 = g_Patches.m_Size;
        printf(format: "%-20s ", "GatherLight:");
        RunThreadsOn(workcnt: v30, showpacifier: 1, fn: (void (__cdecl *)(int, void *))GatherLight, pUserData: nullptr);
        CollectLight(total: &added);
        qprintf(format: "\tBounce #%i added RGB(%.0f, %.0f, %.0f)\n", v29, added.x, added.y, added.z);
        if ( v29 == numbounce || added.x < 1.0 && added.y < 1.0 && added.z < 1.0 )
        {
          v31 = 0;
          bouncing = 0;
        }
        else
        {
          v31 = bouncing;
        }
        ++v28;
        ++v29;
        if ( g_bDumpPatches != 0 )
          break;
        if ( v31 == 0 )
          return;
      }
    }
    while ( v31 != 0 );
    if ( v28 != 1 )
    {
      sprintf(string: name, format: "bounce%i.txt", v28);
      WriteWorld(name, iBump: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F870
// Name: void WriteRTEnv(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteRTEnv(char *name)
{
  void *v1; // ebx
  winding_t *v2; // edi
  int v3; // esi
  float *p_x; // ecx
  float *p_m_flNy; // eax
  double v6; // st7
  float *v7; // ecx
  float *v8; // eax
  double v9; // st7
  float *v10; // ecx
  float *v11; // eax
  int m_nTriangleID; // eax
  Vector color; // [esp+Ch] [ebp-Ch] BYREF

  v1 = g_pFileSystem->Open(this: g_pFileSystem, a2: name, a3: "w", a4: 0);
  if ( v1 == nullptr )
    _Error(a1: "Couldn't open %s", name);
  v2 = AllocWinding(points: 3);
  v3 = 0;
  for ( v2->numpoints = 3; v3 < g_RtEnv.OptimizedTriangleList.m_Size; ++v3 )
  {
    p_x = &v2->p->x;
    p_m_flNy = &g_RtEnv.OptimizedTriangleList.m_Memory.m_pMemory[v3 >> (*((int *)&g_RtEnv.OptimizedTriangleList.m_Memory
                                                                        + 2) >> 27)][v3
                                                                                   & ((32
                                                                                     * *((_DWORD *)&g_RtEnv.OptimizedTriangleList.m_Memory
                                                                                       + 2)) >> 5)].m_Data.m_IntersectData.m_flNy;
    *p_x = *p_m_flNy;
    p_x[1] = p_m_flNy[1];
    color.x = 0.0;
    v6 = p_m_flNy[2];
    color.y = 0.0;
    p_x[2] = v6;
    v7 = &g_RtEnv.OptimizedTriangleList.m_Memory.m_pMemory[v3 >> (*((int *)&g_RtEnv.OptimizedTriangleList.m_Memory + 2) >> 27)][v3 & ((32 * *((_DWORD *)&g_RtEnv.OptimizedTriangleList.m_Memory + 2)) >> 5)].m_Data.m_GeometryData.m_VertexCoordData[3];
    v8 = &v2->p->x;
    v8[3] = *v7;
    v9 = v7[1];
    color.z = 0.0;
    v8[4] = v9;
    v8[5] = v7[2];
    v10 = &g_RtEnv.OptimizedTriangleList.m_Memory.m_pMemory[v3 >> (*((int *)&g_RtEnv.OptimizedTriangleList.m_Memory + 2) >> 27)][v3 & ((32 * *((_DWORD *)&g_RtEnv.OptimizedTriangleList.m_Memory + 2)) >> 5)].m_Data.m_IntersectData.m_ProjectedEdgeEquations[2];
    v11 = &v2->p->x;
    v11[6] = *v10;
    v11[7] = v10[1];
    v11[8] = v10[2];
    m_nTriangleID = g_RtEnv.OptimizedTriangleList.m_Memory.m_pMemory[v3 >> (*((int *)&g_RtEnv.OptimizedTriangleList.m_Memory
                                                                            + 2) >> 27)][v3
                                                                                       & ((32
                                                                                         * *((_DWORD *)&g_RtEnv.OptimizedTriangleList.m_Memory
                                                                                           + 2)) >> 5)].m_Data.m_GeometryData.m_nTriangleID;
    if ( (m_nTriangleID & 0x2000000) != 0 )
    {
      color.x = 0.0;
      color.y = 255.0;
      color.z = 0.0;
    }
    if ( (m_nTriangleID & 0x1000000) != 0 )
    {
      color.x = 0.0;
      color.y = 0.0;
      color.z = 255.0;
    }
    if ( (m_nTriangleID & 0x4000000) != 0 )
    {
      color.x = 255.0;
      color.y = 0.0;
      color.z = 0.0;
    }
    WriteWinding(out: v1, w: v2, &color);
  }
  FreeWinding(w: v2);
  g_pFileSystem->Close(this: g_pFileSystem, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1001FAA0
// Name: void ReadLightFile(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReadLightFile(char *filename)
{
  void *(__thiscall *Open)(IBaseFileSystem *, const char *, const char *, const char *); // edx
  long double v2; // rdi
  void *v3; // ebx
  char *v4; // esi
  int v5; // eax
  _BYTE *v6; // eax
  char *v7; // edi
  int m_Size; // eax
  int v9; // esi
  const char **m_pMemory; // ecx
  int v11; // eax
  char **v12; // eax
  int v13; // ebx
  texlight_t *v14; // esi
  int v15; // ecx
  char *v16; // edi
  char *v17; // ecx
  char v18; // dl
  int v19; // eax
  char buf[1024]; // [esp+8h] [ebp-914h] BYREF
  char NoShadName[1024]; // [esp+408h] [ebp-514h] BYREF
  char szTexlight[256]; // [esp+808h] [ebp-114h] BYREF
  Vector value; // [esp+908h] [ebp-14h] BYREF
  void *f; // [esp+914h] [ebp-8h]
  int file_texlights; // [esp+918h] [ebp-4h]

  Open = g_pFileSystem->Open;
  LODWORD(v2) = filename;
  file_texlights = 0;
  v3 = Open(this: g_pFileSystem, a2: filename, a3: "r", a4: nullptr);
  f = v3;
  if ( v3 != nullptr )
  {
    _Msg(a1: "[Reading texlights from '%s']\n", filename);
    for ( ; CmdLib_FGets(pOut: buf, outSize: 1024, hFile: v3) != nullptr; LODWORD(v2) = filename )
    {
      v4 = buf;
      if ( V_strncasecmp(s1: "hdr:", s2: buf, n: 4) == 0 )
      {
        v4 = &buf[4];
        if ( !g_bHDR )
          continue;
      }
      if ( V_strncasecmp(s1: "ldr:", s2: v4, n: 4) == 0 )
      {
        v4 += 4;
        if ( g_bHDR )
          continue;
      }
      strspn(string: (unsigned __int8 *)v4, control: " \t");
      HIDWORD(v2) = &v4[v5];
      if ( sscanf(string: (const char *)HIDWORD(v2), format: "noshadow %s", NoShadName) == 1 )
      {
        strchr(string: (unsigned __int8 *)NoShadName, chr: 0x2Eu);
        if ( v6 != nullptr )
          *v6 = 0;
        v7 = MemAlloc_StrDup(pString: NoShadName);
        m_Size = g_NonShadowCastingMaterialStrings.m_Size;
        v9 = g_NonShadowCastingMaterialStrings.m_Size;
        if ( g_NonShadowCastingMaterialStrings.m_Size + 1 > g_NonShadowCastingMaterialStrings.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<int,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)&g_NonShadowCastingMaterialStrings,
            num: g_NonShadowCastingMaterialStrings.m_Size - g_NonShadowCastingMaterialStrings.m_Memory.m_nAllocationCount + 1);
          m_Size = g_NonShadowCastingMaterialStrings.m_Size;
        }
        m_pMemory = g_NonShadowCastingMaterialStrings.m_Memory.m_pMemory;
        g_NonShadowCastingMaterialStrings.m_Size = m_Size + 1;
        v11 = m_Size - v9;
        g_NonShadowCastingMaterialStrings.m_pElements = g_NonShadowCastingMaterialStrings.m_Memory.m_pMemory;
        if ( v11 > 0 )
        {
          _V_memmove(
            dest: &g_NonShadowCastingMaterialStrings.m_Memory.m_pMemory[v9 + 1],
            src: &g_NonShadowCastingMaterialStrings.m_Memory.m_pMemory[v9],
            count: 4 * v11);
          m_pMemory = g_NonShadowCastingMaterialStrings.m_Memory.m_pMemory;
        }
        v12 = (char **)&m_pMemory[v9];
        if ( v12 != nullptr )
          *v12 = v7;
      }
      else if ( sscanf(string: (const char *)HIDWORD(v2), format: "forcetextureshadow %s", NoShadName) == 1 )
      {
        ForceTextureShadowsOnModel(pModelName: NoShadName);
      }
      else
      {
        if ( num_texlights == 128 )
          _Error(a1: "Too many texlights, max = %d", 128);
        if ( sscanf(string: (const char *)HIDWORD(v2), format: "%s ", szTexlight) == 1 )
        {
          LightForString(a1: v2, pLight: (char *)(strlen(szTexlight) + HIDWORD(v2) + 1), intensity: &value);
          v13 = 0;
          if ( num_texlights > 0 )
          {
            v14 = texlights;
            while ( strcmp(v14->name, szTexlight) != 0 )
            {
              ++v13;
              ++v14;
              if ( v13 >= num_texlights )
                goto LABEL_36;
            }
            v15 = v13;
            v16 = texlights[v13].filename;
            if ( strcmp(v16, filename) == 0 )
            {
              _Msg(a1: "ERROR\a: Duplication of '%s' in file '%s'!\n", texlights[v13].name, texlights[v13].filename);
            }
            else if ( texlights[v13].value.x == value.x
                   && texlights[v13].value.y == value.y
                   && texlights[v13].value.z == value.z )
            {
              _Warning(a1: "Warning: Redundant '%s' def in '%s' AND '%s'!\n", &texlights[v15], v16, filename);
            }
            else
            {
              _Warning(a1: "Warning: Overriding '%s' from '%s' with '%s'!\n", &texlights[v15], v16, filename);
            }
          }
LABEL_36:
          v17 = szTexlight;
          do
          {
            v18 = *v17;
            v17[(_DWORD)texlights + 272 * v13 - (_DWORD)szTexlight] = *v17;
            ++v17;
          }
          while ( v18 != 0 );
          ++file_texlights;
          texlights[v13].value.x = value.x;
          texlights[v13].value.y = value.y;
          texlights[v13].value.z = value.z;
          texlights[v13].filename = filename;
          v19 = v13 + 1;
          v3 = f;
          if ( num_texlights <= v19 )
            num_texlights = v19;
        }
        else if ( strlen((const char *)HIDWORD(v2)) > 4 )
        {
          _Msg(a1: "ignoring bad texlight '%s' in %s", (const char *)HIDWORD(v2), (const char *)LODWORD(v2));
        }
      }
    }
    qprintf(format: "[%i texlights parsed from '%s']\n\n", file_texlights, (const char *)LODWORD(v2));
    g_pFileSystem->Close(this: g_pFileSystem, a2: v3);
  }
  else
  {
    _Warning(a1: "Warning: Couldn't open texlight file %s.\n", filename);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001FEA0
// Name: void MakePatchForFace(int,struct winding_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MakePatchForFace(int fn, winding_t *w)
{
  double v3; // st7
  int v4; // edi
  CPatch *v5; // esi
  texinfo_s *v6; // ecx
  float v7; // xmm0_4
  int v8; // edx
  float *scale; // eax
  float *v10; // ecx
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  int v16; // eax
  dplane_t *plane; // ecx
  dplane_t *v18; // eax
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float *p_x; // eax
  dtexdata_t *v25; // edi
  char *String; // eax
  float v27; // xmm0_4
  float chopscale[2]; // [esp+4h] [ebp-10h]
  texinfo_s *tx; // [esp+Ch] [ebp-8h]
  float area; // [esp+10h] [ebp-4h]
  dface_t *f; // [esp+1Ch] [ebp+8h]

  f = &g_pFaces[fn];
  tx = &texinfo.m_Memory.m_pMemory[f->texinfo];
  v3 = WindingArea(w);
  area = v3;
  if ( v3 > 0.0 )
  {
    totalarea = totalarea + area;
    v4 = CUtlVector<CPatch,CUtlMemory<CPatch,int>>::AddToTail(this: &g_Patches);
    v5 = &g_Patches.m_Memory.m_pMemory[v4];
    memset(dst: (unsigned __int8 *)v5, value: 0, count: sizeof(CPatch));
    v6 = tx;
    v5->ndxNext = -1;
    v5->ndxNextParent = -1;
    v5->ndxNextClusterChild = -1;
    v5->child1 = -1;
    v5->child2 = -1;
    v5->parent = -1;
    v7 = 16.0;
    *((_DWORD *)v5 + 18) ^= (*((_DWORD *)v5 + 18) ^ (8 * (unsigned __int8)((unsigned int)v6->flags >> 11))) & 8;
    v5->ndxNext = g_FacePatches.m_Memory.m_pMemory[fn];
    g_FacePatches.m_Memory.m_pMemory[fn] = v4;
    chopscale[1] = 16.0;
    chopscale[0] = 16.0;
    if ( texscale != 0 )
    {
      v8 = 0;
      scale = v5->scale;
      v10 = &v6->textureVecsTexelsPerWorldUnits[0][1];
      do
      {
        *scale = 0.0;
        v11 = (float)(*(v10 - 1) * *(v10 - 1)) + 0.0;
        *scale = v11;
        chopscale[v8] = (float)(v10[7] * v10[7]) + 0.0;
        v12 = (float)(*v10 * *v10) + v11;
        *scale = v12;
        chopscale[v8] = (float)(v10[8] * v10[8]) + chopscale[v8];
        *scale = (float)(v10[1] * v10[1]) + v12;
        chopscale[v8] = (float)(v10[9] * v10[9]) + chopscale[v8];
        *scale = fsqrt(*scale);
        chopscale[v8] = fsqrt(chopscale[v8]);
        ++v8;
        v10 += 4;
        ++scale;
      }
      while ( v8 < 2 );
      v7 = chopscale[0];
    }
    else
    {
      v5->scale[1] = 1.0;
      v5->scale[0] = 1.0;
    }
    v13 = (float)(v7 + chopscale[1]) * 0.5;
    v5->area = area;
    *((_DWORD *)v5 + 18) ^= (*((_DWORD *)v5 + 18) ^ (4 * ((texinfo.m_Memory.m_pMemory[f->texinfo].flags & 4) != 0))) & 4;
    v5->luxscale = v13;
    v14 = maxchop;
    v5->winding = w;
    v5->chop = v14;
    v5->plane = (dplane_t *)((char *)&dplanes + 20 * f->planenum);
    if ( face_offset[fn].x != 0.0 || *(float *)&dword_11298E94[3 * fn] != 0.0 || dword_11298E98[3 * fn] != 0.0 )
    {
      if ( numplanes + fakeplanes >= 0x10000 )
        _Error(a1: "numplanes + fakeplanes >= MAX_MAP_PLANES");
      v15 = *(float *)&dword_11298E94[3 * fn];
      v16 = fakeplanes + numplanes;
      ++fakeplanes;
      plane = v5->plane;
      v18 = (dplane_t *)((char *)&dplanes + 20 * v16);
      v18->normal.x = plane->normal.x;
      v19 = v18->normal.x * face_offset[fn].x;
      v18->normal.y = plane->normal.y;
      v20 = (float)(v15 * v18->normal.y) + v19;
      v21 = dword_11298E98[3 * fn];
      v18->normal.z = plane->normal.z;
      v22 = v21 * v18->normal.z;
      v18->dist = plane->dist;
      v23 = (float)(v20 + v22) + v18->dist;
      v18->type = plane->type;
      v18->dist = v23;
      v5->plane = v18;
    }
    v5->faceNumber = fn;
    WindingCenter(w, center: &v5->origin);
    face_centroids[fn].x = v5->origin.x - face_offset[fn].x;
    *(float *)&dword_10745254[3 * fn] = v5->origin.y - *(float *)&dword_11298E94[3 * fn];
    dword_10745258[3 * fn] = v5->origin.z - dword_11298E98[3 * fn];
    p_x = &v5->plane->normal.x;
    v5->normal.x = *p_x;
    v5->normal.y = p_x[1];
    v5->normal.z = p_x[2];
    WindingBounds(w, mins: &v5->face_mins, maxs: &v5->face_maxs);
    v5->mins.x = v5->face_mins.x;
    v5->mins.y = v5->face_mins.y;
    v5->mins.z = v5->face_mins.z;
    v5->maxs.x = v5->face_maxs.x;
    v5->maxs.y = v5->face_maxs.y;
    v5->maxs.z = v5->face_maxs.z;
    v25 = &dtexdata[texinfo.m_Memory.m_pMemory[f->texinfo].texdata];
    String = (char *)TexDataStringTable_GetString(stringID: v25->nameStringTableID);
    LightForTexture(name: String, result: &v5->baselight);
    v5->basearea = (float)(v25->width * v25->height);
    v27 = reflectivityScale;
    v5->reflectivity.x = v25->reflectivity.x * reflectivityScale;
    v5->reflectivity.y = v25->reflectivity.y * v27;
    v5->reflectivity.z = v25->reflectivity.z * v27;
    if ( v5->reflectivity.x > 0.99 )
      v5->reflectivity.x = 0.99000001;
    if ( v5->reflectivity.y > 0.99 )
      v5->reflectivity.y = 0.99000001;
    if ( v5->reflectivity.z > 0.99 )
      v5->reflectivity.z = 0.99000001;
    if ( vec3_origin.x != v5->baselight.x || vec3_origin.y != v5->baselight.y || vec3_origin.z != v5->baselight.z )
      tx->flags |= 1u;
    if ( f->dispinfo != -1 && f->numedges == 4 )
      v5->chop = maxchop;
  }
  else
  {
    ++num_degenerate_faces;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100203A0
// Name: void MakePatches(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MakePatches()
{
  int v0; // esi
  int *p_numfaces; // ebx
  entity_t *v2; // eax
  int v3; // edi
  dface_t *v4; // ecx
  entity_t *v5; // edx
  int v6; // esi
  winding_t *v7; // eax
  IVRadDispMgr *v8; // eax
  Vector origin; // [esp+8h] [ebp-14h] BYREF
  entity_t *ent; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  ParseEntities();
  qprintf(format: "%i faces\n", (_DWORD)numfaces);
  v0 = 0;
  i = 0;
  if ( nummodels > 0 )
  {
    p_numfaces = &dmodels[0].numfaces;
    do
    {
      v2 = EntityForModel(modnum: v0);
      origin = vec3_origin;
      ent = v2;
      GetVectorForKey(ent: v2, key: "origin", angle: (QAngle *)&origin);
      v3 = 0;
      if ( *p_numfaces > 0 )
      {
        do
        {
          v4 = g_pFaces;
          v5 = ent;
          v6 = v3 + *(p_numfaces - 1);
          face_offset[v6] = origin;
          face_entity[v6] = v5;
          if ( v4[v6].dispinfo == -1 )
          {
            v7 = WindingFromFace(f: (winding_t *)&v4[v6], &origin);
            MakePatchForFace(fn: v6, w: v7);
          }
          ++v3;
        }
        while ( v3 < *p_numfaces );
        v0 = i;
      }
      ++v0;
      p_numfaces += 12;
      i = v0;
    }
    while ( v0 < nummodels );
  }
  if ( num_degenerate_faces != 0 )
    qprintf(format: "%d degenerate faces\n", num_degenerate_faces);
  qprintf(format: "%i square feet [%.2f square inches]\n", (int)(float)(totalarea * 0.0069444445), totalarea);
  v8 = StaticDispMgr();
  v8->MakePatches(this: v8);
}

//------------------------------------------------------------------------------
// Address: 0x10020500
// Name: int CreateChildPatch(int,struct winding_t __near *,float,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CreateChildPatch(int nParentIndex, winding_t *pWinding, float flArea, const Vector *vecCenter)
{
  int m_Size; // eax
  int v5; // esi
  CPatch *m_pMemory; // ecx
  int v7; // eax
  CPatch *v8; // esi
  int faceNumber; // eax
  dface_t *v10; // edx
  IVRadDispMgr *v11; // eax
  winding_t *winding; // eax
  float v13; // xmm4_4
  float chop; // xmm1_4
  float v15; // xmm5_4
  float v16; // xmm0_4
  int v17; // edx
  float *i; // ecx
  float v20; // xmm1_4
  Vector total; // [esp+Ch] [ebp-10h]
  int v22; // [esp+18h] [ebp-4h]

  m_Size = g_Patches.m_Size;
  v5 = g_Patches.m_Size;
  v22 = g_Patches.m_Size;
  if ( g_Patches.m_Size + 1 > g_Patches.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CPatch,int>::Grow(
      this: &g_Patches.m_Memory,
      num: g_Patches.m_Size - g_Patches.m_Memory.m_nAllocationCount + 1);
    m_Size = g_Patches.m_Size;
  }
  m_pMemory = g_Patches.m_Memory.m_pMemory;
  g_Patches.m_Size = m_Size + 1;
  v7 = m_Size - v5;
  g_Patches.m_pElements = g_Patches.m_Memory.m_pMemory;
  if ( v7 > 0 )
  {
    _V_memmove(dest: &g_Patches.m_Memory.m_pMemory[v5 + 1], src: &g_Patches.m_Memory.m_pMemory[v5], count: 264 * v7);
    m_pMemory = g_Patches.m_Memory.m_pMemory;
  }
  v8 = &m_pMemory[v5];
  CPatch::operator=(this: v8, __that: &m_pMemory[nParentIndex]);
  v8->winding = pWinding;
  v8->parent = nParentIndex;
  v8->ndxNext = -1;
  v8->ndxNextParent = -1;
  v8->ndxNextClusterChild = -1;
  v8->child1 = -1;
  v8->child2 = -1;
  v8->m_IterationKey = 0;
  v8->area = flArea;
  v8->origin = *vecCenter;
  faceNumber = v8->faceNumber;
  v10 = &g_pFaces[faceNumber];
  if ( v10 != nullptr && v10->dispinfo != -1 && v10->numedges == 4 )
  {
    _Msg(a1: "SubdividePatch: Error - Should not be here!\n");
    v11 = StaticDispMgr();
    v11->GetDispSurfNormal(this: v11, a2: v8->faceNumber, a3: &v8->origin, a4: &v8->normal, a5: true);
  }
  else
  {
    GetPhongNormal(facenum: faceNumber, spot: &v8->origin, phongnormal: &v8->normal);
  }
  winding = v8->winding;
  v8->planeDist = v8->plane->dist;
  WindingBounds(w: winding, mins: &v8->mins, maxs: &v8->maxs);
  if ( vec3_origin.x == v8->baselight.x && vec3_origin.y == v8->baselight.y && vec3_origin.z == v8->baselight.z )
  {
    v13 = v8->luxscale * (float)(v8->maxs.x - v8->mins.x);
    chop = v8->chop;
    v15 = v8->luxscale * (float)(v8->maxs.y - v8->mins.y);
    v16 = (float)(v8->maxs.z - v8->mins.z) * v8->luxscale;
    total.x = v13;
    total.y = v15;
    total.z = v16;
    if ( chop > minchop && chop > v13 && chop > v15 && chop > v16 )
    {
      v17 = 0;
      for ( i = &v8->maxs.x; i[6] != *i && i[3] != *(i - 3) || *(&total.x + v17) <= minchop; ++i )
      {
        if ( ++v17 >= 3 )
          return v22;
      }
      v20 = chop * 0.5;
      if ( minchop > v20 )
        v20 = minchop;
      v8->chop = v20;
    }
  }
  return v22;
}

//------------------------------------------------------------------------------
// Address: 0x10020780
// Name: void SubdividePatch(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SubdividePatch(int ndxPatch)
{
  float v1; // xmm5_4
  int v2; // ebx
  int v3; // esi
  int v4; // edi
  char v5; // al
  CPatch *v6; // ecx
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  float chop; // xmm4_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  int v14; // edi
  int v15; // eax
  CPatch *m_pMemory; // ecx
  int v17; // ebx
  Vector center2; // [esp+1Ch] [ebp-30h] BYREF
  Vector center1; // [esp+28h] [ebp-24h] BYREF
  Vector total; // [esp+34h] [ebp-18h] BYREF
  winding_t *o2; // [esp+40h] [ebp-Ch] BYREF
  winding_t *w; // [esp+44h] [ebp-8h]
  winding_t *o1; // [esp+48h] [ebp-4h] BYREF
  float area1; // [esp+54h] [ebp+8h]

  v1 = -1.0;
  v2 = ndxPatch;
  v3 = ndxPatch;
  v4 = -1;
  v5 = 0;
  v6 = &g_Patches.m_Memory.m_pMemory[ndxPatch];
  if ( v6 != nullptr && (*((_BYTE *)v6 + 72) & 4) == 0 )
  {
    v7 = v6->luxscale * (float)(v6->maxs.x - v6->mins.x);
    v8 = v6->luxscale * (float)(v6->maxs.y - v6->mins.y);
    v9 = (float)(v6->maxs.z - v6->mins.z) * v6->luxscale;
    w = v6->winding;
    total.x = v7;
    total.y = v8;
    total.z = v9;
    if ( v7 > -1.0 )
    {
      v4 = 0;
      v1 = v7;
    }
    chop = v6->chop;
    if ( v7 >= chop && v7 >= minchop )
      v5 = 1;
    if ( v8 > v1 )
    {
      v4 = 1;
      v1 = v8;
    }
    if ( v8 >= chop && v8 >= minchop )
      v5 = 1;
    if ( v9 > v1 )
      v4 = 2;
    if ( (v9 < chop || v9 < minchop) && v5 == 0 )
    {
      if ( v4 == -1 )
        return;
      v11 = *(&total.x + v4);
      if ( v11 <= (float)(*(&total.x + (v4 + 1) % 3) * 2.0) )
        return;
      if ( v11 <= (float)(*(&total.x + (v4 + 2) % 3) * 2.0) )
        return;
      v12 = v6->chop;
      if ( v12 <= minchop )
        return;
      v13 = v12 * 0.5;
      if ( minchop > v13 )
        v13 = minchop;
      v2 = ndxPatch;
      v6->chop = v13;
    }
    total = vec3_origin;
    *((_DWORD *)&total.x + v4) = 1065353216;
    ClipWindingEpsilon(
      in: w,
      normal: &total,
      dist: (float)(*(&v6->maxs.x + v4) + *(&v6->mins.x + v4)) * 0.5,
      epsilon: 0.1,
      front: &o1,
      back: &o2);
    area1 = WindingAreaAndBalancePoint(w: o1, center: &center1);
    *(float *)&w = WindingAreaAndBalancePoint(w: o2, center: &center2);
    if ( area1 == 0.0 || *(float *)&w == 0.0 )
    {
      _Msg(a1: "zero area child patch\n");
    }
    else
    {
      v14 = CreateChildPatch(nParentIndex: v2, pWinding: o1, flArea: area1, vecCenter: &center1);
      v15 = CreateChildPatch(nParentIndex: v2, pWinding: o2, flArea: *(float *)&w, vecCenter: &center2);
      m_pMemory = g_Patches.m_Memory.m_pMemory;
      v17 = v15;
      g_Patches.m_Memory.m_pMemory[v3].child1 = v14;
      m_pMemory[v3].child2 = v15;
      SubdividePatch(ndxPatch: v14);
      SubdividePatch(ndxPatch: v17);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020A00
// Name: void SubdividePatches(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SubdividePatches()
{
  int m_Size; // edi
  unsigned int v1; // ebx
  int v2; // esi
  unsigned int v3; // edi
  CPatch *v4; // ecx
  CPatch *v5; // ecx
  CPatch *v6; // ecx
  CPatch *v7; // ecx
  unsigned int v8; // esi
  unsigned int v9; // edi
  int faceNumber; // ecx
  CPatch *v11; // eax
  unsigned int v12; // edi
  int v13; // esi
  CPatch *m_pMemory; // eax
  dface_t *v15; // ecx
  int flags; // eax
  IVRadDispMgr *v17; // eax
  unsigned int i; // eax
  int v19; // edi
  int v20; // esi
  int v21; // ebx
  CPatch *v22; // eax
  int v23; // ecx
  CPatch *v24; // ecx
  int v25; // esi
  int v26; // ebx
  int v27; // edi
  int v28; // eax
  int v29; // ebx
  int v30; // eax
  int v31; // esi
  int j; // [esp+0h] [ebp-8h]
  unsigned int uiPatchCount; // [esp+4h] [ebp-4h]
  unsigned int uiPatchCounta; // [esp+4h] [ebp-4h]

  if ( numbounce != 0 )
  {
    m_Size = g_Patches.m_Size;
    uiPatchCount = g_Patches.m_Size;
    qprintf(format: "%i patches before subdivision\n", g_Patches.m_Size);
    v1 = 0;
    if ( m_Size >= 4 )
    {
      v2 = 0;
      v3 = ((unsigned int)(m_Size - 4) >> 2) + 1;
      v1 = 4 * v3;
      do
      {
        v4 = &g_Patches.m_Memory.m_pMemory[v2];
        v4->planeDist = g_Patches.m_Memory.m_pMemory[v2].plane->dist;
        v4->ndxNextParent = faceParents.m_Memory.m_pMemory[v4->faceNumber];
        faceParents.m_Memory.m_pMemory[v4->faceNumber] = v4 - g_Patches.m_Memory.m_pMemory;
        v5 = &g_Patches.m_Memory.m_pMemory[v2 + 1];
        v5->planeDist = g_Patches.m_Memory.m_pMemory[v2 + 1].plane->dist;
        v5->ndxNextParent = faceParents.m_Memory.m_pMemory[v5->faceNumber];
        faceParents.m_Memory.m_pMemory[v5->faceNumber] = v5 - g_Patches.m_Memory.m_pMemory;
        v6 = &g_Patches.m_Memory.m_pMemory[v2 + 2];
        v6->planeDist = g_Patches.m_Memory.m_pMemory[v2 + 2].plane->dist;
        v6->ndxNextParent = faceParents.m_Memory.m_pMemory[v6->faceNumber];
        faceParents.m_Memory.m_pMemory[v6->faceNumber] = v6 - g_Patches.m_Memory.m_pMemory;
        v7 = &g_Patches.m_Memory.m_pMemory[v2 + 3];
        v7->planeDist = g_Patches.m_Memory.m_pMemory[v2 + 3].plane->dist;
        v7->ndxNextParent = faceParents.m_Memory.m_pMemory[v7->faceNumber];
        faceParents.m_Memory.m_pMemory[v7->faceNumber] = v7 - g_Patches.m_Memory.m_pMemory;
        v2 += 4;
        --v3;
      }
      while ( v3 != 0 );
      m_Size = uiPatchCount;
    }
    if ( v1 < m_Size )
    {
      v8 = v1;
      v9 = m_Size - v1;
      do
      {
        faceNumber = g_Patches.m_Memory.m_pMemory[v8].faceNumber;
        v11 = &g_Patches.m_Memory.m_pMemory[v8];
        v11->planeDist = g_Patches.m_Memory.m_pMemory[v8].plane->dist;
        faceNumber *= 4;
        v11->ndxNextParent = *(int *)((char *)faceParents.m_Memory.m_pMemory + faceNumber);
        ++v8;
        --v9;
        *(int *)((char *)faceParents.m_Memory.m_pMemory + faceNumber) = v11 - g_Patches.m_Memory.m_pMemory;
      }
      while ( v9 != 0 );
    }
    v12 = 0;
    if ( uiPatchCount != 0 )
    {
      v13 = 0;
      do
      {
        m_pMemory = g_Patches.m_Memory.m_pMemory;
        g_Patches.m_Memory.m_pMemory[v13].parent = -1;
        v15 = &g_pFaces[m_pMemory[v13].faceNumber];
        flags = texinfo.m_Memory.m_pMemory[v15->texinfo].flags;
        if ( (flags & 0x4000) == 0 && ((flags & 0x400) == 0 || (flags & 1) != 0) && do_fast == 0 )
        {
          if ( v15->dispinfo == -1 )
          {
            SubdividePatch(ndxPatch: v12);
          }
          else
          {
            v17 = StaticDispMgr();
            v17->SubdividePatch(this: v17, a2: v12);
          }
        }
        ++v12;
        ++v13;
      }
      while ( v12 < uiPatchCount );
    }
    for ( i = 0; i < (unsigned int)numfaces; ++i )
      g_FacePatches.m_Memory.m_pMemory[i] = -1;
    v19 = g_Patches.m_Size;
    uiPatchCounta = g_Patches.m_Size;
    if ( g_Patches.m_Size == 0 )
      goto LABEL_36;
    v20 = 0;
    v21 = g_Patches.m_Size;
    do
    {
      v22 = &g_Patches.m_Memory.m_pMemory[v20];
      v23 = g_Patches.m_Memory.m_pMemory[v20].faceNumber;
      v22->ndxNext = g_FacePatches.m_Memory.m_pMemory[v23];
      ++v20;
      --v21;
      g_FacePatches.m_Memory.m_pMemory[v23] = v22 - g_Patches.m_Memory.m_pMemory;
    }
    while ( v21 != 0 );
    if ( v19 != 0 )
    {
      v24 = g_Patches.m_Memory.m_pMemory;
      v25 = 0;
      for ( j = v19; j != 0; --j )
      {
        v24[v25].clusterNumber = ClusterFromPoint(point: &v24[v25].origin);
        v24 = g_Patches.m_Memory.m_pMemory;
        if ( g_Patches.m_Memory.m_pMemory[v25].clusterNumber == -1 )
        {
          v26 = 0;
          if ( g_Patches.m_Memory.m_pMemory[v25].winding->numpoints > 0 )
          {
            v27 = 0;
            while ( 1 )
            {
              v28 = ClusterFromPoint(point: &v24[v25].winding->p[v27]);
              v24 = g_Patches.m_Memory.m_pMemory;
              if ( v28 != -1 )
                break;
              ++v26;
              ++v27;
              if ( v26 >= g_Patches.m_Memory.m_pMemory[v25].winding->numpoints )
                goto LABEL_33;
            }
            g_Patches.m_Memory.m_pMemory[v25].clusterNumber = v28;
            v24 = g_Patches.m_Memory.m_pMemory;
LABEL_33:
            v19 = uiPatchCounta;
          }
        }
        ++v25;
      }
    }
    else
    {
LABEL_36:
      v24 = g_Patches.m_Memory.m_pMemory;
    }
    if ( v19 != 0 )
    {
      v29 = v19;
      do
      {
        v30 = (int)&v24[v29 - 1];
        if ( v24[v29 - 1].child1 == -1 )
        {
          v31 = *(_DWORD *)(v30 + 220);
          if ( v31 != -1 )
          {
            *(_DWORD *)(v30 + 244) = clusterChildren.m_Memory.m_pMemory[v31];
            clusterChildren.m_Memory.m_pMemory[v31] = (signed int)(v30 - (unsigned int)g_Patches.m_Memory.m_pMemory)
                                                    / 264;
            v24 = g_Patches.m_Memory.m_pMemory;
          }
        }
        --v29;
        --v19;
      }
      while ( v19 != 0 );
      v19 = uiPatchCounta;
    }
    qprintf(format: "%i patches after subdivision\n", v19);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020E60
// Name: void RadWorld_Start(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RadWorld_Start()
{
  int m_Size; // esi
  int v1; // ebx
  float *v2; // ecx
  float *v3; // eax
  int v4; // edx
  double v5; // st7
  float *v6; // esi
  int i; // edi
  long double v8; // st7
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  int *children; // esi
  int v13; // eax
  char v14; // [esp+4h] [ebp-60010h] BYREF
  float v15; // [esp+60000h] [ebp-14h]
  Vector vec; // [esp+60004h] [ebp-10h] BYREF
  unsigned int v17; // [esp+60010h] [ebp-4h]

  if ( luxeldensity < 1.0 )
  {
    m_Size = texinfo.m_Size;
    v1 = 0;
    if ( texinfo.m_Size != 0 )
    {
      v2 = (float *)&v14;
      v3 = &texinfo.m_Memory.m_pMemory->lightmapVecsLuxelsPerWorldUnits[0][1];
      v4 = texinfo.m_Size;
      do
      {
        v5 = *(v3 - 1);
        v3 += 18;
        *(v2 - 1) = v5;
        v2 += 8;
        --v4;
        *(v2 - 8) = *(v3 - 18);
        *(v2 - 7) = *(v3 - 17);
        *(v2 - 5) = *(v3 - 15);
        *(v2 - 4) = *(v3 - 14);
        *(v2 - 3) = *(v3 - 13);
      }
      while ( v4 != 0 );
    }
    v17 = 0;
    if ( m_Size != 0 )
    {
      do
      {
        v6 = &texinfo.m_Memory.m_pMemory[v1].lightmapVecsLuxelsPerWorldUnits[0][1];
        for ( i = 2; i != 0; --i )
        {
          vec = *(Vector *)(v6 - 1);
          v8 = VectorNormalize(&vec);
          v15 = v8;
          if ( fabs(v8) > luxeldensity )
          {
            v9 = luxeldensity;
            if ( v15 < 0.0 )
              LODWORD(v9) = LODWORD(luxeldensity) ^ _mask__NegFloat_;
            v10 = vec.y * v9;
            v11 = vec.z * v9;
            *(v6 - 1) = vec.x * v9;
            *v6 = v10;
            v6[1] = v11;
          }
          v6 += 4;
        }
        ++v1;
        ++v17;
      }
      while ( v17 < texinfo.m_Size );
    }
    UpdateAllFaceLightmapExtents();
  }
  nodeparents[0] = -1;
  children = dnodes[0].children;
  do
  {
    v13 = *children;
    if ( *children >= 0 )
      MakeParents(nodenum: v13, parent: 0);
    else
      leafparents[-v13 - 1] = 0;
    ++children;
  }
  while ( (int)children < (int)dnodes[0].mins );
  BuildClusterTable();
  MakePatches();
  PairEdges();
  SaveVertexNormals();
  SubdividePatches();
  AddDispsToClusterTable();
  CreateDirectLights();
  ProcessSkyCameras();
}

//------------------------------------------------------------------------------
// Address: 0x10021010
// Name: public: RayTracingEnvironment::RayTracingEnvironment(void)
// Source: json
//------------------------------------------------------------------------------
RayTracingEnvironment *__thiscall RayTracingEnvironment::RayTracingEnvironment(RayTracingEnvironment *this)
{
  CUtlBlockVector<CacheOptimizedTriangle> *p_OptimizedTriangleList; // ecx
  unsigned int v3; // eax
  int v4; // ecx
  __m128 v5; // xmm1

  p_OptimizedTriangleList = &this->OptimizedTriangleList;
  this->OptimizedKDTree.m_Memory.m_pMemory = nullptr;
  this->OptimizedKDTree.m_Memory.m_nAllocationCount = 0;
  this->OptimizedKDTree.m_Memory.m_nGrowSize = 0;
  this->OptimizedKDTree.m_Size = 0;
  this->OptimizedKDTree.m_pElements = nullptr;
  p_OptimizedTriangleList->m_Memory.m_pMemory = nullptr;
  p_OptimizedTriangleList->m_Memory.m_nBlocks = 0;
  *((_DWORD *)&p_OptimizedTriangleList->m_Memory + 2) = 0;
  CUtlBlockMemory<CacheOptimizedTriangle,int>::Purge(this: &p_OptimizedTriangleList->m_Memory);
  v3 = 1023;
  v4 = 1024;
  *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2) = 1023;
  do
  {
    v4 >>= 1;
    v3 = ((v3 & 0xF8000000) + 0x8000000) ^ v3 & 0x7FFFFFF;
  }
  while ( v4 > 1 );
  *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2) = v3;
  this->OptimizedTriangleList.m_Size = 0;
  this->OptimizedTriangleList.m_pElements = nullptr;
  this->TriangleIndexList.m_Memory.m_pMemory = nullptr;
  this->TriangleIndexList.m_Memory.m_nAllocationCount = 0;
  this->TriangleIndexList.m_Memory.m_nGrowSize = 0;
  this->TriangleIndexList.m_Size = 0;
  this->TriangleIndexList.m_pElements = nullptr;
  this->LightList.m_Memory.m_pMemory = nullptr;
  this->LightList.m_Memory.m_nAllocationCount = 0;
  this->LightList.m_Memory.m_nGrowSize = 0;
  this->LightList.m_Size = 0;
  this->LightList.m_pElements = nullptr;
  this->TriangleColors.m_Memory.m_pMemory = nullptr;
  this->TriangleColors.m_Memory.m_nAllocationCount = 0;
  this->TriangleColors.m_Memory.m_nGrowSize = 0;
  this->TriangleColors.m_Size = 0;
  this->TriangleColors.m_pElements = nullptr;
  this->TriangleMaterials.m_Memory.m_pMemory = nullptr;
  this->TriangleMaterials.m_Memory.m_nAllocationCount = 0;
  this->TriangleMaterials.m_Memory.m_nGrowSize = 0;
  this->TriangleMaterials.m_Size = 0;
  this->TriangleMaterials.m_pElements = nullptr;
  this->BackgroundColor.x = _mm_shuffle_ps((__m128)0x3F800000u, (__m128)0x3F800000u, 0);
  v5 = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  this->BackgroundColor.y = v5;
  this->BackgroundColor.z = v5;
  this->Flags = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10021110
// Name: void BuildFacesVisibleToLights(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildFacesVisibleToLights(bool bAllVisible)
{
  int v1; // esi
  signed int m_Size; // edi
  unsigned __int8 *m_pMemory; // ecx
  int numclusters; // eax
  unsigned __int8 *v5; // ebx
  int v6; // esi
  int v7; // eax
  directlight_t *v8; // edi
  unsigned __int8 *pvs; // edx
  unsigned __int8 *v10; // ecx
  int i; // esi
  int v12; // esi
  int v13; // edx
  int v14; // eax
  clusterlist_t *v15; // esi
  int v16; // ebx
  int v17; // edi
  int v18; // edx
  int v19; // edi
  int v20; // eax
  int v21; // esi
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > aggregate; // [esp+8h] [ebp-18h] BYREF
  int nBytes; // [esp+1Ch] [ebp-4h]
  directlight_t *iCluster; // [esp+28h] [ebp+8h]
  int iClustera; // [esp+28h] [ebp+8h]

  v1 = (int)numfaces / 8 + 1;
  m_Size = 0;
  g_FacesVisibleToLights.m_Size = 0;
  if ( (int)numfaces / 8 == -1 )
    goto LABEL_7;
  if ( v1 > g_FacesVisibleToLights.m_Memory.m_nAllocationCount )
    CUtlMemory<char,int>::Grow(
      this: &g_FacesVisibleToLights.m_Memory,
      num: v1 - g_FacesVisibleToLights.m_Memory.m_nAllocationCount);
  m_pMemory = g_FacesVisibleToLights.m_Memory.m_pMemory;
  g_FacesVisibleToLights.m_Size += v1;
  g_FacesVisibleToLights.m_pElements = g_FacesVisibleToLights.m_Memory.m_pMemory;
  if ( g_FacesVisibleToLights.m_Size - v1 > 0 && v1 > 0 )
  {
    _V_memmove(
      dest: &g_FacesVisibleToLights.m_Memory.m_pMemory[v1],
      src: g_FacesVisibleToLights.m_Memory.m_pMemory,
      count: g_FacesVisibleToLights.m_Size - v1);
LABEL_7:
    m_pMemory = g_FacesVisibleToLights.m_Memory.m_pMemory;
  }
  if ( bAllVisible )
  {
    memset(dst: m_pMemory, value: 0xFFu, count: g_FacesVisibleToLights.m_Size);
  }
  else
  {
    numclusters = dvis->numclusters;
    v5 = nullptr;
    v6 = dvis->numclusters / 8 + 1;
    memset(&aggregate, 0, sizeof(aggregate));
    if ( numclusters / 8 != -1 )
    {
      if ( v6 > 0 )
      {
        CUtlMemory<char,int>::Grow(this: &aggregate.m_Memory, num: numclusters / 8 + 1);
        m_Size = aggregate.m_Size;
        v5 = aggregate.m_Memory.m_pMemory;
      }
      m_Size += v6;
      if ( m_Size - v6 > 0 && v6 > 0 )
        _V_memmove(dest: &v5[v6], src: v5, count: m_Size - v6);
    }
    memset(dst: v5, value: 0, count: m_Size);
    v7 = m_Size / 4;
    nBytes = m_Size % 4;
    v8 = activelights;
    for ( iCluster = activelights; v8 != nullptr; iCluster = v8 )
    {
      pvs = v8->pvs;
      v10 = v5;
      if ( v7 > 0 )
      {
        for ( i = v7; i != 0; --i )
        {
          *(_DWORD *)v10 |= *(_DWORD *)pvs;
          pvs += 4;
          v10 += 4;
        }
        v8 = iCluster;
      }
      v12 = nBytes;
      if ( nBytes > 0 )
      {
        v13 = pvs - v10;
        do
        {
          *v10 |= v10[v13];
          ++v10;
          --v12;
        }
        while ( v12 != 0 );
        v5 = aggregate.m_Memory.m_pMemory;
      }
      v8 = v8->next;
    }
    v14 = 0;
    iClustera = 0;
    if ( dvis->numclusters > 0 )
    {
      v15 = g_ClusterLeaves.m_Memory.m_pMemory;
      v16 = 0;
      nBytes = 0;
      do
      {
        v17 = *(int *)((char *)&v15->leafCount + v16);
        if ( v17 != 0 )
        {
          if ( ((unsigned __int8)(1 << (v14 & 7)) & aggregate.m_Memory.m_pMemory[v14 >> 3]) != 0 )
          {
            v18 = 0;
            if ( v17 > 0 )
            {
              do
              {
                v19 = 16 * (*(int **)((char *)&v15->leafs.m_Memory.m_pMemory + v16))[v18];
                v20 = 0;
                if ( word_1135AAC6[v19] != 0 )
                {
                  do
                  {
                    v21 = dleaffaces[v20 + (unsigned __int16)word_1135AAC4[v19]];
                    ++v20;
                    g_FacesVisibleToLights.m_Memory.m_pMemory[v21 >> 3] |= 1 << (v21 & 7);
                  }
                  while ( v20 < (unsigned __int16)word_1135AAC6[v19] );
                  v15 = g_ClusterLeaves.m_Memory.m_pMemory;
                  v16 = nBytes;
                }
                ++v18;
              }
              while ( v18 < *(int *)((char *)&v15->leafCount + v16) );
            }
          }
          v14 = iClustera;
        }
        ++v14;
        v16 += 24;
        iClustera = v14;
        nBytes = v16;
      }
      while ( v14 < dvis->numclusters );
      v5 = aggregate.m_Memory.m_pMemory;
    }
    if ( aggregate.m_Memory.m_nGrowSize >= 0 && v5 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021350
// Name: bool RadWorld_Go(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall RadWorld_Go@<al>(int a1@<ebx>, int a2@<edi>, entity_t *a3@<esi>)
{
  int i; // esi
  CFileSystemPassThru *v5; // ecx
  IVRadDispMgr *v6; // eax
  IVRadDispMgr *v7; // eax
  IVRadDispMgr *v8; // eax
  IVRadDispMgr *v9; // eax
  _iobuf *v10; // eax
  char szName[64]; // [esp+Ch] [ebp-40h] BYREF

  g_iCurFace = 0;
  InitMacroTexture(a1, a2: a3, pBSPFilename: source);
  if ( g_pIncremental != nullptr )
  {
    g_pIncremental->PrepareForLighting(this: g_pIncremental);
    BuildFacesVisibleToLights(bAllVisible: false);
  }
  else
  {
    BuildFacesVisibleToLights(bAllVisible: true);
  }
  if ( g_bUseMPI )
  {
    RunMPIBuildFacelights();
  }
  else
  {
    printf(format: "%-20s ", "BuildFacelights:");
    RunThreadsOnIndividual(workcnt: numfaces, showpacifier: 1, func: (void (__cdecl *)(int, int))BuildFacelights);
  }
  if ( g_pIncremental != nullptr && g_iCurFace != (_DWORD)numfaces )
    return 0;
  PrecompLightmapOffsets();
  if ( g_pIncremental != nullptr )
  {
    g_pIncremental->Finalize(this: g_pIncremental);
    return 1;
  }
  else
  {
    ExportDirectLightsToWorldLights();
    if ( g_bDumpPatches != 0 )
    {
      for ( i = 0; i < 4; ++i )
      {
        sprintf(string: szName, format: "bounce0_%d.txt", i);
        WriteWorld(name: szName, iBump: i);
      }
    }
    if ( numbounce != 0 )
    {
      emitlight.m_Size = 0;
      CUtlVector<doccluderpolydata_t,CUtlMemory<doccluderpolydata_t,int>>::InsertMultipleBefore(
        this: &emitlight,
        elem: 0,
        num: g_Patches.m_Size);
      memset(dst: (unsigned __int8 *)emitlight.m_Memory.m_pMemory, value: 0, count: 12 * g_Patches.m_Size);
      addlight.m_Size = 0;
      CUtlVector<bumplights_t,CUtlMemory<bumplights_t,int>>::InsertMultipleBefore(
        this: &addlight,
        elem: 0,
        num: g_Patches.m_Size);
      memset(dst: (unsigned __int8 *)addlight.m_Memory.m_pMemory, value: 0, count: 48 * g_Patches.m_Size);
      BuildVisMatrix();
      CVRadDLL::Release(this: v5);
      _Msg(a1: "transfers %d, max %d\n", total_transfer, max_transfer);
      qprintf(format: "transfer lists: %5.1f megs\n", (float)((float)((float)total_transfer * 8.0) * 0.00000095367432));
      BounceLight();
    }
    v6 = StaticDispMgr();
    ((void (__thiscall *)(IVRadDispMgr *, const char *, entity_t *))v6->StartTimer)(
      a1: v6,
      a2: "Build Patch/Sample Hash Table(s).....",
      a3);
    v7 = StaticDispMgr();
    v7->InsertSamplesDataIntoHashTable(this: v7);
    v8 = StaticDispMgr();
    v8->InsertPatchSampleDataIntoHashTable(this: v8);
    v9 = StaticDispMgr();
    v9->EndTimer(this: v9);
    VMPI_SetCurrentStage(pCurStage: "FinalLightFace");
    if ( !g_bUseMPI || g_bMPIMaster )
    {
      printf(format: "%-20s ", "FinalLightFace:");
      RunThreadsOnIndividual(workcnt: numfaces, showpacifier: 1, func: FinalLightFace);
    }
    VMPI_DistributeLightData(a1: a2);
    _Msg(a1: "FinalLightFace Done\n");
    v10 = __iob_func();
    fflush(stream: v10 + 1);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100215C0
// Name: void VRAD_LoadBSP(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall VRAD_LoadBSP(int a1@<esi>)
{
  int v1; // eax
  char v2; // cl
  char *v3; // eax
  char *v4; // edx
  char v5; // cl
  int v6; // eax
  char v7; // cl
  int v8; // eax
  char v9; // cl
  CVradStaticPropMgr *v10; // eax
  IVRadDispMgr *v11; // eax
  int v12; // edx
  __int16 *v13; // ecx
  int v14; // esi
  int i; // eax
  int j; // eax
  IVRadDispMgr *v17; // eax
  CVradStaticPropMgr *v18; // eax
  double v19; // st7
  char logFile[512]; // [esp+1Ch] [ebp-204h] BYREF
  float start; // [esp+21Ch] [ebp-4h]

  ThreadSetDefault();
  g_flStartTime = _Plat_FloatTime();
  if ( g_bLowPriority != 0 )
    SetLowPriority();
  v1 = 0;
  do
  {
    v2 = source[v1];
    level_name[v1++] = v2;
  }
  while ( v2 != 0 );
  if ( g_bDumpPatches != 0 )
    InitDumpPatchesFiles();
  v3 = ExpandPath(path: source);
  v4 = (char *)(source - v3);
  do
  {
    v5 = *v3;
    v3[(_DWORD)v4] = *v3;
    ++v3;
  }
  while ( v5 != 0 );
  if ( !g_bUseMPI )
  {
    _snprintf(string: logFile, count: 0x200u, format: "%s.log", source);
    CCmdLibFileLoggingListener::Open(this: &g_CmdLibFileLoggingListener, pFilename: logFile);
  }
  PhysicsDLLPath(pPathname: "VPHYSICS.DLL");
  strcpy(global_lights, "lights.rad");
  if ( ((unsigned __int8 (__thiscall *)(IBaseFileSystem *, char *, _DWORD, int))g_pFileSystem->FileExists)(
         a1: g_pFileSystem,
         a2: global_lights,
         a3: 0,
         a4: a1) == 0 )
  {
    _Msg(a1: "Could not find lights.rad in %s.\nTrying VRAD BIN directory instead...\n", global_lights);
    GetModuleFileNameA(hModule: nullptr, lpFilename: global_lights, nSize: 0x104u);
    V_ExtractFilePath(path: global_lights, dest: global_lights, destSize: 260);
    strcat(global_lights, "lights.rad");
  }
  v6 = 0;
  do
  {
    v7 = source[v6];
    level_lights[v6++] = v7;
  }
  while ( v7 != 0 );
  V_DefaultExtension(path: level_lights, extension: ".rad", pathStringLength: 260);
  if ( ((unsigned __int8 (__thiscall *)(IBaseFileSystem *, char *))g_pFileSystem->FileExists)(
         a1: g_pFileSystem,
         a2: level_lights) == 0 )
    level_lights[0] = 0;
  ReadLightFile(filename: global_lights);
  if ( designer_lights[0] != 0 )
    ReadLightFile(filename: designer_lights);
  if ( level_lights[0] != 0 )
    ReadLightFile(filename: level_lights);
  v8 = 0;
  do
  {
    v9 = source[v8];
    incrementfile[v8++] = v9;
  }
  while ( v9 != 0 );
  V_DefaultExtension(path: incrementfile, extension: ".r0", pathStringLength: 260);
  V_DefaultExtension(path: source, extension: ".bsp", pathStringLength: 260);
  GetPlatformMapPath(pMapPath: source, pPlatformMapPath: platformPath, dxlevel: 0, maxLength: 260);
  _Msg(a1: "Loading %s\n", platformPath);
  VMPI_SetCurrentStage(pCurStage: "LoadBSPFile");
  LoadBSPFile(filename: platformPath);
  if ( g_bStaticPropLighting )
    g_LevelFlags |= g_bHDR + 1;
  else
    g_LevelFlags &= 0xFFFFFFFC;
  if ( g_bHDR )
  {
    g_pFaces = dfaces_hdr;
    if ( numfaces_hdr == 0 )
    {
      numfaces_hdr = numfaces;
      memcpy(dst: (unsigned __int8 *)dfaces_hdr, src: (unsigned __int8 *)dfaces, count: 56 * numfaces);
    }
  }
  else
  {
    g_pFaces = dfaces;
  }
  ParseEntities();
  ExtractBrushEntityShadowCasters();
  v10 = StaticPropMgr();
  v10->Init(this: v10);
  v11 = StaticDispMgr();
  v11->Init(this: v11);
  if ( visdatasize == 0 )
  {
    _Msg(a1: "No vis information, direct lighting only.\n");
    v12 = 0;
    numbounce = 0;
    ambient.z = 0.1;
    ambient.y = 0.1;
    ambient.x = 0.1;
    if ( (int)numleafs > 0 )
    {
      v13 = (__int16 *)&unk_1135AAB4;
      v14 = numleafs;
      do
      {
        if ( *v13 > v12 )
          v12 = *v13;
        v13 += 16;
        --v14;
      }
      while ( v14 != 0 );
    }
    dvis->numclusters = v12 + 1;
  }
  g_FacePatches.m_Size = 0;
  if ( g_FacePatches.m_Memory.m_nAllocationCount < 0x10000 )
    CUtlMemory<int,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&g_FacePatches,
      num: 0x10000 - g_FacePatches.m_Memory.m_nAllocationCount);
  g_FacePatches.m_Size += 0x10000;
  g_FacePatches.m_pElements = g_FacePatches.m_Memory.m_pMemory;
  if ( g_FacePatches.m_Size - 0x10000 > 0 )
    _V_memmove(
      dest: g_FacePatches.m_Memory.m_pMemory + 0x10000,
      src: g_FacePatches.m_Memory.m_pMemory,
      count: 4 * (g_FacePatches.m_Size - 0x10000));
  faceParents.m_Size = 0;
  if ( faceParents.m_Memory.m_nAllocationCount < 0x10000 )
    CUtlMemory<int,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&faceParents,
      num: 0x10000 - faceParents.m_Memory.m_nAllocationCount);
  faceParents.m_Size += 0x10000;
  faceParents.m_pElements = faceParents.m_Memory.m_pMemory;
  if ( faceParents.m_Size - 0x10000 > 0 )
    _V_memmove(
      dest: faceParents.m_Memory.m_pMemory + 0x10000,
      src: faceParents.m_Memory.m_pMemory,
      count: 4 * (faceParents.m_Size - 0x10000));
  clusterChildren.m_Size = 0;
  if ( clusterChildren.m_Memory.m_nAllocationCount < 0x10000 )
    CUtlMemory<int,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&clusterChildren,
      num: 0x10000 - clusterChildren.m_Memory.m_nAllocationCount);
  clusterChildren.m_Size += 0x10000;
  clusterChildren.m_pElements = clusterChildren.m_Memory.m_pMemory;
  if ( clusterChildren.m_Size - 0x10000 > 0 )
    _V_memmove(
      dest: clusterChildren.m_Memory.m_pMemory + 0x10000,
      src: clusterChildren.m_Memory.m_pMemory,
      count: 4 * (clusterChildren.m_Size - 0x10000));
  for ( i = 0; i < 0x10000; ++i )
  {
    g_FacePatches.m_Memory.m_pMemory[i] = -1;
    faceParents.m_Memory.m_pMemory[i] = -1;
  }
  for ( j = 0; j < 0x10000; ++j )
    clusterChildren.m_Memory.m_pMemory[j] = -1;
  AddBrushesForRayTrace();
  v17 = StaticDispMgr();
  v17->AddPolysForRayTrace(this: v17);
  v18 = StaticPropMgr();
  v18->AddPolysForRayTrace(this: v18);
  if ( g_bDumpRtEnv )
    WriteRTEnv(name: "trace.txt");
  printf(format: "Setting up ray-trace acceleration structure... ");
  start = _Plat_FloatTime();
  RayTracingEnvironment::SetupAccelerationStructure(this: &g_RtEnv);
  v19 = _Plat_FloatTime();
  printf(format: "Done (%.2f seconds)\n", v19 - start);
  RadWorld_Start();
  if ( g_pIncremental != nullptr && !g_pIncremental->Init(this: g_pIncremental, a2: source, a3: incrementfile) )
    _Error(a1: "Unable to load incremental lighting file in %s.\n", incrementfile);
}

//------------------------------------------------------------------------------
// Address: 0x10021B30
// Name: int RunVRAD(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl RunVRAD(entity_t *argc, char **argv)
{
  char **v2; // edi
  int v3; // ebx
  CVradStaticPropMgr *v4; // eax

  _Msg(a1: "Valve Software - vrad.exe SSE (Jul 15 2011)\n");
  _Msg(a1: "\n      Valve Radiosity Simulator     \n");
  v2 = argv;
  verbose = 1;
  v3 = ParseCommandLine((int)argc, argv, onlydetail: (bool *)&argv + 3);
  if ( (entity_t *)v3 != (entity_t *)((char *)&argc[-1].m_pPortalsLeadingIntoAreas[1] + 3) )
  {
    PrintCommandLine((int)argc, argv: v2);
    _Warning(
      a1: "usage  : vrad [options...] bspfile\n"
      "example: vrad c:\\hl2\\hl2\\maps\\test\n"
      "\n"
      "Common options:\n"
      "\n"
      "  -v (or -verbose): Turn on verbose output (also shows more command\n"
      "  -bounce #       : Set max number of bounces (default: 100).\n"
      "  -fast           : Quick and dirty lighting.\n"
      "  -fastambient    : Per-leaf ambient sampling is lower quality to save compute time.\n"
      "  -final          : High quality processing. equivalent to -extrasky 16.\n"
      "  -finitefalloff  : use an alternative falloff model that falls off to exactly zero at the zero_percent_distance.\n"
      "  -extrasky n     : trace N times as many rays for indirect light and sky ambient.\n"
      "  -low            : Run as an idle-priority process.\n"
      "  -mpi            : Use VMPI to distribute computations.\n"
      "  -rederror       : Show errors in red.\n"
      "\n"
      "  -vproject <directory> : Override the VPROJECT environment variable.\n"
      "  -game <directory>     : Same as -vproject.\n"
      "\n"
      "Other options:\n"
      "  -novconfig      : Don't bring up graphical UI on vproject errors.\n"
      "  -dump           : Write debugging .txt files.\n"
      "  -dumpnormals    : Write normals to debug files.\n"
      "  -dumptrace      : Write ray-tracing environment to debug files.\n"
      "  -threads        : Control the number of threads vbsp uses (defaults to the #\n"
      "                    or processors on your machine).\n"
      "  -lights <file>  : Load a lights file in addition to lights.rad and the\n"
      "                    level lights file.\n"
      "  -noextra        : Disable supersampling.\n"
      "  -debugextra     : Places debugging data in lightmaps to visualize\n"
      "                    supersampling.\n"
      "  -smooth #       : Set the threshold for smoothing groups, in degrees\n"
      "                    (default 45).\n");
    _Warning(
      a1: "  -dlightmap      : Force direct lighting into different lightmap than\n"
      "                    radiosity.\n"
      "  -stoponexit\t   : Wait for a keypress on exit.\n"
      "  -mpi_pw <pw>    : Use a password to choose a specific set of VMPI workers.\n"
      "  -nodetaillight  : Don't light detail props.\n"
      "  -centersamples  : Move sample centers.\n"
      "  -luxeldensity # : Rescale all luxels by the specified amount (default: 1.0).\n"
      "                    The number specified must be less than 1.0 or it will be\n"
      "                    ignored.\n"
      "  -loghash        : Log the sample hash table to samplehash.txt.\n"
      "  -onlydetail     : Only light detail props and per-leaf lighting.\n"
      "  -maxdispsamplesize #: Set max displacement sample size (default: 512).\n"
      "  -softsun <n>    : Treat the sun as an area light source of size <n> degrees.                    Produces soft sh"
      "adows.\n"
      "                    Recommended values are between 0 and 5. Default is 0.\n"
      "  -FullMinidumps  : Write large minidumps on crash.\n"
      "  -chop           : Smallest number of luxel widths for a bounce patch, used on edges\n"
      "  -maxchop\t: Coarsest allowed number of luxel widths for a patch, used in face interiors\n"
      "  -LargeDispSampleRadius: This can be used if there are splotches of bounced\n"
      "                          light on terrain. The compile will take longer, but\n"
      "                          it will gather light across a wider area.\n"
      "  -StaticPropLighting   : generate backed static prop vertex lighting\n"
      "  -StaticPropPolys   : Perform shadow tests of static props at polygon precision\n"
      "  -OnlyStaticProps   : Only perform direct static prop lighting (vrad debug option)\n"
      "  -StaticPropNormals : when lighting static props, just show their normal vector\n"
      "  -textureshadows : Allows texture alpha channels to block light - rays intersecting alpha surfaces will sample th"
      "e texture\n"
      "  -noskyboxrecurse : Turn off recursion into 3d skybox (skybox shadows on world)\n"
      "  -nossprops      : Globally disable self-shadowing on static props\n"
      "\n");
    DeleteCmdLine((int)argc, argv: v2);
    _Plat_ExitProcess(a1: 1);
  }
  VRAD_LoadBSP(a1: (int)argc);
  if ( HIBYTE(argv) == 0 && !g_bOnlyStaticProps )
    RadWorld_Go(a1: v3, a2: (int)v2, a3: argc);
  if ( !g_bNoDetailLighting )
    ComputeDetailPropLighting(iThread: 16);
  ComputePerLeafAmbientLighting();
  if ( do_fast == 0 && g_bStaticPropLighting )
  {
    v4 = StaticPropMgr();
    v4->ComputeLighting(this: v4, a2: 16);
  }
  VRAD_Finish();
  VMPI_SetCurrentStage(pCurStage: "master done");
  DeleteCmdLine((int)argc, argv: v2);
  CmdLib_Cleanup();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10021C20
// Name: int VRAD_Main(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VRAD_Main(entity_t *argc, char **argv)
{
  g_pFileSystem = nullptr;
  MathLib_Init(
    gamma: 2.2,
    texGamma: 2.2,
    brightness: 0.0,
    overbright: 2,
    bAllow3DNow: false,
    bAllowSSE: false,
    bAllowSSE2: false,
    bAllowMMX: false);
  InstallAllocationFunctions();
  InstallSpewFunction();
  VRAD_SetupMPI((int *)&argc, &argv);
  V_StripExtension(in: argv[(_DWORD)argc - 1], out: source, outSize: 260);
  CmdLib_InitFileSystem(pFilename: argv[(_DWORD)argc - 1], maxMemoryUsage: 0);
  V_FileBase(in: source, out: source, maxlen: 260);
  if ( !g_bUseMPI || g_bMPIMaster )
  {
    LoadCmdLineFromFile((int *)&argc, &argv, keyname: source, appname: "vrad");
    SetupDefaultToolsMinidumpHandler();
    return RunVRAD(argc, argv);
  }
  else
  {
    SetupToolsMinidumpHandler(fn: VMPI_ExceptionFilter);
    return RunVRAD(argc, argv);
  }
}
