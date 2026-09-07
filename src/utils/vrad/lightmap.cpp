// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vrad/lightmap.cpp
// Functions: 56
// ============================================================

#include "utils\vrad\lightmap.h"

//------------------------------------------------------------------------------
// Address: 0x100022D0
// Name: public: Vector2D::Vector2D(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector2D::Vector2D(Vector *this)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10009830
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
// Address: 0x10009870
// Name: union __m128 PowSIMD(union __m128 const __near &,float)
// Source: json
//------------------------------------------------------------------------------
__m128 *__cdecl PowSIMD(__m128 *result, const __m128 *x)
{
  int savedregs; // [esp+0h] [ebp+0h]

  return Pow_FixedPoint_Exponent_SIMD(result, x: (const __m128 *)(int)(float)(*(float *)&x * 4.0), exponent: savedregs);
}

//------------------------------------------------------------------------------
// Address: 0x100098A0
// Name: void GetBumpNormals(float const __near *,float const __near *,class Vector const __near &,class Vector const __near &,class Vector __near * const)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetBumpNormals(
        float *sVect,
        float *tVect,
        const Vector *flatNormal,
        const Vector *phongNormal,
        Vector *bumpNormals)
{
  Vector stmp; // [esp+0h] [ebp-18h] BYREF
  Vector ttmp; // [esp+Ch] [ebp-Ch] BYREF

  stmp.x = *sVect;
  stmp.y = sVect[1];
  stmp.z = sVect[2];
  ttmp.x = *tVect;
  ttmp.y = tVect[1];
  ttmp.z = tVect[2];
  GetBumpNormals(sVect: &stmp, tVect: &ttmp, flatNormal, phongNormal, bumpNormals);
}

//------------------------------------------------------------------------------
// Address: 0x10009910
// Name: void PairEdges(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PairEdges()
{
  __int16 *p_numedges; // edi
  int v1; // esi
  int m; // ecx
  int v3; // edx
  int v4; // eax
  int v5; // eax
  int v6; // edi
  int n; // esi
  __int16 *v8; // ebx
  int ii; // edi
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  int v13; // esi
  int v14; // eax
  int *v15; // ecx
  int *v16; // edx
  dface_t *v17; // ecx
  int v18; // ebx
  unsigned int v19; // edi
  float *v20; // eax
  float *v21; // edx
  float *v22; // edx
  float *v23; // edx
  float *v24; // edx
  int v25; // edi
  __int16 *v26; // ecx
  int v27; // esi
  float *v28; // eax
  float *v29; // edx
  __int16 *v30; // edi
  float *v31; // esi
  int v32; // ebx
  int v33; // edx
  int v34; // ecx
  int v35; // eax
  int v36; // eax
  int v37; // ecx
  int v38; // ecx
  char v39; // dl
  float v40; // xmm0_4
  int *v41; // eax
  float *v42; // ecx
  int v43; // edx
  unsigned int v44; // ecx
  float v45; // xmm0_4
  int v46; // eax
  int v47; // edx
  int jj; // eax
  int v49; // ebx
  int v50; // edi
  float *v51; // eax
  unsigned int v52; // [esp-8h] [ebp-134h]
  int tmpneighbor[64]; // [esp+Ch] [ebp-120h]
  int *v54; // [esp+10Ch] [ebp-20h]
  int numneighbors; // [esp+110h] [ebp-1Ch]
  int k; // [esp+114h] [ebp-18h]
  int v57; // [esp+118h] [ebp-14h]
  int **v58; // [esp+11Ch] [ebp-10h]
  int j; // [esp+120h] [ebp-Ch]
  int i; // [esp+124h] [ebp-8h]
  __int16 *v61; // [esp+128h] [ebp-4h]

  if ( (int)numfaces > 0 )
  {
    p_numedges = &g_pFaces->numedges;
    v58 = (int **)numfaces;
    do
    {
      v1 = *p_numedges;
      for ( m = 0; m < v1; ++m )
      {
        v3 = m;
        if ( m >= 0 )
        {
          if ( m >= v1 )
            v3 = m % v1;
        }
        else
        {
          v3 = v1 + m;
        }
        v4 = dsurfedges[v3 + *((_DWORD *)p_numedges - 1)];
        if ( v4 >= 0 )
          v5 = dedges[v4].v[0];
        else
          v5 = *((unsigned __int16 *)&unk_1157EAB2 - 2 * v4);
        ++vertexref[v5];
        v1 = *p_numedges;
      }
      p_numedges += 28;
      v58 = (int **)((char *)v58 - 1);
    }
    while ( v58 != nullptr );
  }
  v6 = numvertexes;
  for ( n = 0; n < v6; ++n )
  {
    vertexface[n] = (int *)calloc(count: vertexref[n], size: 4u);
    vertexref[n] = 0;
  }
  i = 0;
  if ( (int)numfaces > 0 )
  {
    v8 = &g_pFaces->numedges;
    j = (int)&g_pFaces->numedges;
    do
    {
      for ( ii = 0; ii < *v8; ++ii )
      {
        v10 = ii;
        if ( ii >= 0 )
        {
          v11 = *v8;
          if ( ii >= v11 )
            v10 = ii % v11;
        }
        else
        {
          v10 = ii + *v8;
        }
        v12 = dsurfedges[v10 + *((_DWORD *)v8 - 1)];
        if ( v12 >= 0 )
          v13 = dedges[v12].v[0];
        else
          v13 = *((unsigned __int16 *)&unk_1157EAB2 - 2 * v12);
        v14 = 0;
        v15 = &vertexref[v13];
        if ( *v15 <= 0 )
          goto LABEL_30;
        v16 = vertexface[v13];
        do
        {
          if ( *v16 == i )
            break;
          ++v14;
          ++v16;
        }
        while ( v14 < *v15 );
        v8 = (__int16 *)j;
        if ( v14 >= *v15 )
        {
LABEL_30:
          vertexface[v13][v14] = i;
          ++*v15;
        }
      }
      v8 += 28;
      ++i;
      j = (int)v8;
    }
    while ( i < (int)numfaces );
  }
  v17 = g_pFaces;
  v18 = 0;
  if ( (int)numfaces >= 4 )
  {
    v19 = ((unsigned int)(numfaces - 4) >> 2) + 1;
    v20 = (float *)&unk_10A33264;
    v18 = 4 * v19;
    do
    {
      v21 = &dplanes.x + 5 * v17->planenum;
      *(v20 - 2) = *v21;
      *(v20 - 1) = v21[1];
      *v20 = v21[2];
      *((_BYTE *)v20 + 4) = 0;
      if ( v17->dispinfo != -1 && v17->numedges == 4 )
        *((_BYTE *)v20 + 4) = 1;
      v22 = &dplanes.x + 5 * v17[1].planenum;
      v20[5] = *v22;
      v20[6] = v22[1];
      v20[7] = v22[2];
      *((_BYTE *)v20 + 32) = 0;
      if ( v17 != (dface_t *)-56 && v17[1].dispinfo != -1 && v17[1].numedges == 4 )
        *((_BYTE *)v20 + 32) = 1;
      v23 = &dplanes.x + 5 * v17[2].planenum;
      v20[12] = *v23;
      v20[13] = v23[1];
      v20[14] = v23[2];
      *((_BYTE *)v20 + 60) = 0;
      if ( v17 != (dface_t *)-112 && v17[2].dispinfo != -1 && v17[2].numedges == 4 )
        *((_BYTE *)v20 + 60) = 1;
      v24 = &dplanes.x + 5 * v17[3].planenum;
      v20[19] = *v24;
      v20[20] = v24[1];
      v20[21] = v24[2];
      *((_BYTE *)v20 + 88) = 0;
      if ( v17 != (dface_t *)-168 && v17[3].dispinfo != -1 && v17[3].numedges == 4 )
        *((_BYTE *)v20 + 88) = 1;
      v17 += 4;
      v20 += 28;
      --v19;
    }
    while ( v19 != 0 );
  }
  v25 = numfaces;
  if ( v18 < (int)numfaces )
  {
    v26 = &v17->numedges;
    v27 = numfaces - v18;
    v28 = (float *)((char *)&unk_10A33264 + 28 * v18);
    do
    {
      v29 = &dplanes.x + 5 * (unsigned __int16)*(v26 - 4);
      *(v28 - 2) = *v29;
      *(v28 - 1) = v29[1];
      *v28 = v29[2];
      *((_BYTE *)v28 + 4) = 0;
      if ( v26[2] != -1 && *v26 == 4 )
        *((_BYTE *)v28 + 4) = 1;
      v26 += 28;
      v28 += 7;
      --v27;
    }
    while ( v27 != 0 );
  }
  i = 0;
  if ( v25 <= 0 )
    return;
  v30 = &g_pFaces->numedges;
  v61 = &g_pFaces->numedges;
  v31 = (float *)&unk_10A33258;
  while ( 1 )
  {
    v32 = 0;
    v52 = *v30;
    numneighbors = 0;
    *(_DWORD *)v31 = calloc(count: v52, size: 0xCu);
    j = 0;
    if ( *v30 <= 0 )
      goto LABEL_95;
    v57 = 0;
    do
    {
      v33 = j;
      if ( j >= 0 )
      {
        v34 = *v61;
        if ( j >= v34 )
          v33 = j % v34;
      }
      else
      {
        v33 = j + *v61;
      }
      v35 = dsurfedges[v33 + *((_DWORD *)v61 - 1)];
      if ( v35 >= 0 )
        v36 = dedges[v35].v[0];
      else
        v36 = *((unsigned __int16 *)&unk_1157EAB2 - 2 * v35);
      v37 = 0;
      k = 0;
      v54 = &vertexref[v36];
      if ( *v54 > 0 )
      {
        v58 = &vertexface[v36];
        do
        {
          v38 = (*v58)[v37];
          if ( v38 != i )
          {
            v39 = *((_BYTE *)v31 + 16);
            if ( v39 != 0 || byte_10A33268[28 * v38] == 0 )
            {
              v40 = *(float *)&dword_10A3325C[7 * v38];
              v41 = &dword_10A3325C[7 * v38];
              if ( v39 != 0 )
              {
                v42 = (float *)(v57 + *(_DWORD *)v31);
LABEL_83:
                *v42 = v40 + *v42;
                v42[1] = v42[1] + *((float *)v41 + 1);
                v45 = v42[2] + *((float *)v41 + 2);
                v46 = 0;
                v42[2] = v45;
                if ( v32 <= 0 )
                  goto LABEL_88;
                while ( tmpneighbor[v46] != (*v58)[k] )
                {
                  if ( ++v46 >= v32 )
                    goto LABEL_88;
                }
                if ( v46 >= v32 )
                {
LABEL_88:
                  ++v32;
                  tmpneighbor[v46] = (*v58)[k];
                  numneighbors = v32;
                  if ( (unsigned int)v32 > 0x40 )
                    _Error(a1: "Stack overflow in neighbors\n");
                }
                goto LABEL_90;
              }
              v43 = *((_DWORD *)v61 + 11);
              if ( v43 != 0 || (v32 = numneighbors, g_pFaces[v38].smoothingGroups != 0) )
              {
                v44 = v43 & g_pFaces[v38].smoothingGroups;
                if ( (v44 & 0xFF000000) == 0 && v44 != 0 )
                {
                  v42 = (float *)(*(_DWORD *)v31 + v57);
                  goto LABEL_83;
                }
              }
              else if ( (float)((float)((float)(v31[2] * *(float *)&dword_10A33260[7 * v38])
                                      + (float)(*(float *)&dword_10A3325C[7 * v38] * v31[1]))
                              + (float)(v31[3] * *((float *)v41 + 2))) >= (double)smoothing_threshold )
              {
                v42 = (float *)(v57 + *(_DWORD *)v31);
                goto LABEL_83;
              }
            }
          }
LABEL_90:
          v37 = k + 1;
          k = v37;
        }
        while ( v37 < *v54 );
      }
      v47 = *v61;
      v57 += 12;
      ++j;
    }
    while ( j < v47 );
    if ( v32 != 0 )
    {
      *((_DWORD *)v31 - 2) = v32;
      *((_DWORD *)v31 - 1) = calloc(count: v32, size: 4u);
      for ( jj = 0; jj < v32; ++jj )
        *(_DWORD *)(*((_DWORD *)v31 - 1) + 4 * jj) = tmpneighbor[jj];
    }
LABEL_95:
    v49 = 0;
    if ( *v61 > 0 )
    {
      v50 = 0;
      do
      {
        v51 = (float *)(v50 + *(_DWORD *)v31);
        *v51 = v31[1] + *v51;
        v51[1] = v51[1] + v31[2];
        v51[2] = v51[2] + v31[3];
        VectorNormalize(vec: (Vector *)(v50 + *(_DWORD *)v31));
        ++v49;
        v50 += 12;
      }
      while ( v49 < *v61 );
    }
    v61 += 28;
    v31 += 7;
    if ( ++i >= (int)numfaces )
      break;
    v30 = v61;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009F40
// Name: struct winding_t __near * LightmapCoordWindingForFace(struct lightinfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
winding_t *__cdecl LightmapCoordWindingForFace(lightinfo_t *l)
{
  winding_t *result; // eax
  winding_t *v2; // esi
  int v3; // ebx
  int v4; // edi
  Vector2D coord; // [esp+8h] [ebp-8h] BYREF

  result = WindingFromFace(f: l->face, origin: &l->modelorg);
  v2 = result;
  v3 = 0;
  if ( result->numpoints > 0 )
  {
    v4 = 0;
    do
    {
      WorldToLuxelSpace(l, world: &v2->p[v4], &coord);
      *(Vector2D *)&v2->p[v4].x = coord;
      v2->p[v4].z = 0.0;
      ++v3;
      ++v4;
    }
    while ( v3 < v2->numpoints );
    return v2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10009FC0
// Name: void DumpFaces(struct lightinfo_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DumpFaces(lightinfo_t *pLightInfo, int ndxFace)
{
  dface_t *face; // ebx
  int v3; // esi
  int v4; // edx
  int v5; // ecx
  int v6; // eax
  int v7; // eax
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  dvertex_t *v11; // eax
  int v12; // ecx
  int v13; // edx
  int v14; // esi
  int v15; // eax
  int v16; // eax
  Vector *normal; // esi
  int v18; // eax
  float v19; // xmm0_4
  dvertex_t *v20; // eax
  float *p_x; // ebx
  float p2_4; // [esp+4Ch] [ebp-24h]
  float p2_8; // [esp+50h] [ebp-20h]
  float p1; // [esp+54h] [ebp-1Ch]
  float p1_4; // [esp+58h] [ebp-18h]
  float p1_8; // [esp+5Ch] [ebp-14h]
  int v27; // [esp+60h] [ebp-10h]
  Vector *centroid; // [esp+64h] [ebp-Ch]
  int numedges; // [esp+68h] [ebp-8h]
  faceneighbor_t *fn; // [esp+6Ch] [ebp-4h]
  int ndxFacea; // [esp+7Ch] [ebp+Ch]

  fn = &faceneighbor[ndxFace];
  centroid = &face_centroids[ndxFace];
  ThreadLock();
  if ( out != nullptr
    || (out = g_pFileSystem->Open(this: g_pFileSystem, a2: "face.txt", a3: "w", a4: 0), out != nullptr) )
  {
    face = pLightInfo->face;
    v3 = 0;
    numedges = face->numedges;
    if ( numedges > 0 )
    {
      ndxFacea = 0;
      do
      {
        v4 = v3;
        if ( v3 >= 0 )
        {
          v5 = face->numedges;
          if ( v3 >= v5 )
            v4 = v3 % v5;
        }
        else
        {
          v4 = v3 + face->numedges;
        }
        v6 = dsurfedges[v4 + face->firstedge];
        if ( v6 >= 0 )
          v7 = dedges[v6].v[0];
        else
          v7 = *((unsigned __int16 *)&unk_1157EAB2 - 2 * v6);
        x = pLightInfo->modelorg.x;
        y = pLightInfo->modelorg.y;
        z = pLightInfo->modelorg.z;
        v11 = &dvertexes[v7];
        p1 = x + v11->point.x;
        v12 = v3 + 1;
        p1_4 = v11->point.y + y;
        p1_8 = v11->point.z + z;
        v27 = v3 + 1;
        v13 = v3 + 1;
        if ( v3 + 1 >= 0 )
        {
          v14 = face->numedges;
          if ( v12 >= v14 )
            v13 = v12 % v14;
        }
        else
        {
          v13 = v12 + face->numedges;
        }
        v15 = dsurfedges[v13 + face->firstedge];
        if ( v15 >= 0 )
          v16 = dedges[v15].v[0];
        else
          v16 = *((unsigned __int16 *)&unk_1157EAB2 - 2 * v15);
        normal = fn->normal;
        v18 = v16;
        v19 = dvertexes[v18].point.x;
        v20 = &dvertexes[v18];
        p2_4 = v20->point.y + y;
        p2_8 = v20->point.z + z;
        p_x = &normal[v12 % numedges].x;
        CmdLib_FPrintf(hFile: out, pFormat: "3\n");
        CmdLib_FPrintf(
          hFile: out,
          pFormat: "%f %f %f %f %f %f\n",
          p1,
          p1_4,
          p1_8,
          (float)((float)(normal[ndxFacea].x + 1.0) * 0.5),
          (float)((float)(normal[ndxFacea].y + 1.0) * 0.5),
          (float)((float)(normal[ndxFacea].z + 1.0) * 0.5));
        CmdLib_FPrintf(
          hFile: out,
          pFormat: "%f %f %f %f %f %f\n",
          (float)(v19 + x),
          p2_4,
          p2_8,
          (float)((float)(*p_x + 1.0) * 0.5),
          (float)((float)(p_x[1] + 1.0) * 0.5),
          (float)((float)(p_x[2] + 1.0) * 0.5));
        CmdLib_FPrintf(
          hFile: out,
          pFormat: "%f %f %f %f %f %f\n",
          (float)(centroid->x + pLightInfo->modelorg.x),
          (float)(pLightInfo->modelorg.y + centroid->y),
          (float)(pLightInfo->modelorg.z + centroid->z),
          (float)((float)(fn->facenormal.x + 1.0) * 0.5),
          (float)((float)(fn->facenormal.y + 1.0) * 0.5),
          (float)((float)(fn->facenormal.z + 1.0) * 0.5));
        face = pLightInfo->face;
        v3 = v27;
        ++ndxFacea;
        numedges = face->numedges;
      }
      while ( v27 < numedges );
    }
    ThreadUnlock();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A360
// Name: void FreeSampleWindings(struct facelight_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FreeSampleWindings(facelight_t *fl)
{
  int v1; // ebx
  int v2; // esi

  v1 = 0;
  if ( fl->numsamples > 0 )
  {
    v2 = 0;
    do
    {
      if ( fl->sample[v2].w != nullptr )
      {
        FreeWinding(w: fl->sample[v2].w);
        fl->sample[v2].w = nullptr;
      }
      ++v1;
      ++v2;
    }
    while ( v1 < fl->numsamples );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A3A0
// Name: bool BuildFaceLuxels(struct lightinfo_t __near *,struct facelight_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl BuildFaceLuxels(lightinfo_t *pLightInfo, facelight_t *pFaceLight)
{
  dface_t *face; // eax
  int v3; // ebx
  int v4; // edi
  Vector *v5; // eax
  int v7; // eax
  int v8; // ecx
  int v9; // esi
  int v10; // ebx
  int height; // [esp+1Ch] [ebp-10h]
  float v12; // [esp+20h] [ebp-Ch]
  int t; // [esp+24h] [ebp-8h]
  int v14; // [esp+28h] [ebp-4h]

  face = pLightInfo->face;
  v3 = face->m_LightmapTextureSizeInLuxels[1] + 1;
  v4 = face->m_LightmapTextureSizeInLuxels[0] + 1;
  height = v3;
  pFaceLight->numluxels = v4 * v3;
  v5 = (Vector *)calloc(count: v4 * v3, size: 0xCu);
  pFaceLight->luxel = v5;
  if ( v5 == nullptr )
    return 0;
  v7 = 0;
  t = 0;
  if ( v3 > 0 )
  {
    v8 = 12 * v4;
    v14 = 0;
    do
    {
      v9 = 0;
      if ( v4 > 0 )
      {
        v10 = v14;
        v12 = (float)v7;
        do
        {
          LuxelSpaceToWorld(l: pLightInfo, s: (float)v9++, t: v12, world: (Vector *)((char *)pFaceLight->luxel + v10));
          v10 += 12;
        }
        while ( v9 < v4 );
        v3 = height;
        v7 = t;
        v8 = 12 * v4;
      }
      v14 += v8;
      t = ++v7;
    }
    while ( v7 < v3 );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000A470
// Name: struct entity_t __near * FindTargetEntity(char __near *)
// Source: json
//------------------------------------------------------------------------------
entity_t *__cdecl FindTargetEntity(char *target)
{
  int v1; // edi
  entity_t *i; // esi

  v1 = 0;
  if ( num_entities <= 0 )
    return nullptr;
  for ( i = entities; strcmp(ValueForKey(ent: i, key: "targetname"), target) != 0; ++i )
  {
    if ( ++v1 >= num_entities )
      return nullptr;
  }
  return &entities[v1];
}

//------------------------------------------------------------------------------
// Address: 0x1000A4F0
// Name: int LightForString(char __near *,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __usercall LightForString@<eax>(long double a1@<esi:edi>, char *pLight, Vector *intensity)
{
  int v3; // edi
  double v4; // xmm0_8
  float v5; // xmm0_4
  double v6; // xmm0_8
  double v7; // xmm0_8
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  long double v16; // [esp-Ch] [ebp-4Ch]
  long double v17; // [esp-Ch] [ebp-4Ch]
  _BYTE v18[12]; // [esp-4h] [ebp-44h] OVERLAPPED BYREF
  double b_hdr; // [esp+8h] [ebp-38h] BYREF
  double g_hdr; // [esp+10h] [ebp-30h] BYREF
  double r_hdr; // [esp+18h] [ebp-28h] BYREF
  double r; // [esp+20h] [ebp-20h] BYREF
  double scaler; // [esp+28h] [ebp-18h] BYREF
  double b; // [esp+30h] [ebp-10h] BYREF
  double g; // [esp+38h] [ebp-8h] BYREF

  intensity->z = 0.0;
  intensity->y = 0.0;
  intensity->x = 0.0;
  scaler = 0.0;
  b = 0.0;
  g = 0.0;
  r = 0.0;
  v3 = sscanf(
         string: pLight,
         format: "%lf %lf %lf %lf %lf %lf %lf %lf",
         &r,
         &g,
         &b,
         &scaler,
         &r_hdr,
         &g_hdr,
         &b_hdr,
         &v18[4]);
  if ( v3 == 8 )
  {
    if ( g_bHDR )
    {
      r = r_hdr;
      g = g_hdr;
      b = b_hdr;
      scaler = *(double *)&v18[4];
    }
    v3 = 4;
  }
  if ( r < 0.0 || g < 0.0 || b < 0.0 || scaler < 0.0 )
  {
    intensity->x = 0.0;
    intensity->y = 0.0;
    intensity->z = 0.0;
    return 0;
  }
  else
  {
    v4 = r * 0.00392156862745098;
    __libm_sse2_pow(x: a1, y: *(long double *)v18);
    v5 = v4 * 255.0;
    intensity->x = v5;
    if ( v3 == 1 )
    {
      intensity->z = v5;
      intensity->y = v5;
    }
    else
    {
      if ( v3 <= 2 || v3 > 4 )
      {
        printf(format: "unknown light specifier type - %s\n", pLight);
        return 0;
      }
      v6 = g * 0.00392156862745098;
      __libm_sse2_pow(x: v16, y: *(long double *)v18);
      *(float *)&v6 = v6 * 255.0;
      intensity->y = *(float *)&v6;
      v7 = b * 0.00392156862745098;
      __libm_sse2_pow(x: v17, y: *(long double *)v18);
      *(float *)&v7 = v7 * 255.0;
      intensity->z = *(float *)&v7;
      if ( v3 == 4 )
      {
        v8 = scaler * 0.00392156862745098;
        intensity->x = intensity->x * v8;
        v9 = intensity->y * v8;
        v10 = v8 * intensity->z;
        intensity->y = v9;
        intensity->z = v10;
      }
    }
    v12 = lightscale;
    intensity->x = intensity->x * lightscale;
    v13 = intensity->y * v12;
    v14 = v12 * intensity->z;
    intensity->y = v13;
    intensity->z = v14;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A710
// Name: SetLightFalloffParams
// Source: json
//------------------------------------------------------------------------------
void __usercall SetLightFalloffParams(entity_t *e@<edi>, directlight_t *dl@<esi>)
{
  double v2; // st7
  double v3; // st7
  double v4; // st7
  float x2; // xmm2_4
  float x3; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float c; // [esp+28h] [ebp-14h] BYREF
  float b; // [esp+2Ch] [ebp-10h] BYREF
  float a; // [esp+30h] [ebp-Ch] BYREF
  float d0; // [esp+34h] [ebp-8h]
  float d50; // [esp+38h] [ebp-4h]

  dl->m_flStartFadeDistance = 0.0;
  dl->m_flEndFadeDistance = -1.0;
  dl->m_flCapDist = 9.9999998e21;
  if ( g_bFiniteFalloffModel )
  {
    v2 = FloatForKey(ent: e, key: "_zero_percent_distance");
    dl->light.constant_attn = 1.0;
    dl->light.linear_attn = 0.0;
    dl->light.quadratic_attn = -1.0 / (v2 * v2);
  }
  else
  {
    v3 = FloatForKey(ent: e, key: "_fifty_percent_distance");
    d50 = v3;
    if ( v3 == 0.0 )
    {
      dl->light.constant_attn = FloatForKey(ent: e, key: "_constant_attn");
      dl->light.linear_attn = FloatForKey(ent: e, key: "_linear_attn");
      dl->light.quadratic_attn = FloatForKey(ent: e, key: "_quadratic_attn");
      dl->light.radius = FloatForKey(ent: e, key: "_distance");
      if ( dl->light.constant_attn < 0.001 )
        dl->light.constant_attn = 0.0;
      if ( dl->light.linear_attn < 0.001 )
        dl->light.linear_attn = 0.0;
      if ( dl->light.quadratic_attn < 0.001 )
        dl->light.quadratic_attn = 0.0;
      if ( dl->light.constant_attn < 0.001 && dl->light.linear_attn < 0.001 && dl->light.quadratic_attn < 0.001 )
        dl->light.constant_attn = 1.0;
      v14 = (float)((float)(dl->light.linear_attn * 100.0) + dl->light.constant_attn)
          + (float)(dl->light.quadratic_attn * 10000.0);
      if ( v14 > 0.0 )
      {
        dl->light.intensity.x = v14 * dl->light.intensity.x;
        dl->light.intensity.y = v14 * dl->light.intensity.y;
        dl->light.intensity.z = v14 * dl->light.intensity.z;
      }
    }
    else
    {
      v4 = FloatForKey(ent: e, key: "_zero_percent_distance");
      d0 = v4;
      x2 = d50;
      if ( d50 <= v4 )
      {
        x3 = d0;
      }
      else
      {
        _Warning(a1: "light has _fifty_percent_distance of %f but _zero_percent_distance of %f\n", d50, d0);
        x2 = d50;
        x3 = d50 * 2.0;
        d0 = d50 * 2.0;
      }
      a = 0.0;
      b = 1.0;
      c = 0.0;
      if ( !SolveInverseQuadraticMonotonic(x1: 0.0, y1: 1.0, x2, y2: 2.0, x3, y3: 256.0, &a, &b, &c) )
        _Warning(a1: "can't solve quadratic for light %f %f\n", d50, d0);
      v7 = 2.0 / (float)((float)((float)((float)(a * d50) + b) * d50) + c);
      v8 = v7 * a;
      v9 = v7 * b;
      v10 = v7 * c;
      a = v8;
      b = v9;
      c = v10;
      dl->light.quadratic_attn = v8;
      dl->light.linear_attn = v9;
      dl->light.constant_attn = v10;
      if ( IntForKey(ent: e, key: "_hardfalloff") != 0 )
      {
        v11 = d0;
        v12 = d50 * 0.25;
        dl->m_flEndFadeDistance = d0;
        dl->m_flStartFadeDistance = (float)(v11 * 0.75) + v12;
      }
      else if ( COERCE_FLOAT(LODWORD(a) & _mask__AbsFloat_) > 0.0 )
      {
        v13 = b / (float)(a * -2.0);
        if ( v13 > 0.0 )
        {
          dl->m_flCapDist = v13;
          dl->m_flStartFadeDistance = v13;
          dl->m_flEndFadeDistance = v13 * 10.0;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AAA0
// Name: bool CanLeafTraceToSky(int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __usercall CanLeafTraceToSky@<al>(int a1@<ebp>)
{
  __m128 v1; // xmm5
  int v2; // esi
  __m128 *i; // edi
  int v4; // edx
  int v5; // ecx
  int v6; // eax
  __m128 v7; // xmm3
  __m128 v8; // xmm0
  __m128 v9; // xmm4
  __m128 v10; // xmm2
  __m128 v11; // xmm6
  __m128 v12; // xmm3
  _BYTE v14[128]; // [esp-Ch] [ebp-8Ch] OVERLAPPED BYREF
  int v15; // [esp+74h] [ebp-Ch]
  void *v16; // [esp+78h] [ebp-8h]
  void *retaddr; // [esp+80h] [ebp+0h]

  v15 = a1;
  v16 = retaddr;
  v1 = _mm_shuffle_ps((__m128)0xC75DB3D7, (__m128)0xC75DB3D7, 0);
  *(__m128 *)&v14[112] = v1;
  v2 = 2;
  for ( i = (__m128 *)g_anorms; ; i += 3 )
  {
    v4 = v2 + 1;
    if ( v2 + 1 >= 161 )
      v4 = 161;
    v5 = v2;
    if ( v2 >= 161 )
      v5 = 161;
    v6 = v2 - 1;
    if ( v2 - 1 >= 161 )
      v6 = 161;
    v7 = *(__m128 *)&g_anorms[v6].x;
    v8 = _mm_shuffle_ps(*i, v7, 68);
    v9 = _mm_shuffle_ps(*i, v7, 238);
    v10 = *(__m128 *)&g_anorms[v5].x;
    v11 = *(__m128 *)&g_anorms[v4].x;
    v12 = _mm_shuffle_ps(v10, v11, 68);
    *(__m128 *)&v14[64] = _mm_add_ps(*(__m128 *)&v14[16], _mm_mul_ps(v1, _mm_shuffle_ps(v8, v12, 221)));
    *(__m128 *)&v14[48] = _mm_add_ps(*(__m128 *)v14, _mm_mul_ps(_mm_shuffle_ps(v8, v12, 136), v1));
    *(__m128 *)&v14[80] = _mm_add_ps(
                            *(__m128 *)&v14[32],
                            _mm_mul_ps(v1, _mm_shuffle_ps(v9, _mm_shuffle_ps(v10, v11, 238), 136)));
    TestLine_DoesHitSky(
      start: (const FourVectors *)v14,
      stop: (const FourVectors *)&v14[48],
      pFractionVisible: (__m128 *)&v14[96],
      canRecurse: true,
      static_prop_to_skip: -1,
      bDoDebug: false);
    if ( _mm_movemask_ps(_mm_cmplt_ps(Four_Zeros, *(__m128 *)&v14[96])) != 0 )
      break;
    v2 += 4;
    if ( v2 - 2 >= 162 )
      return 0;
    v1 = *(__m128 *)&v14[112];
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000ABF0
// Name: ValueForKeyWithDefault
// Source: json
//------------------------------------------------------------------------------
char *__usercall ValueForKeyWithDefault@<eax>(entity_t *ent@<eax>, char *key@<edi>, char *default_value)
{
  epair_t *epairs; // esi

  epairs = ent->epairs;
  if ( epairs == nullptr )
    return default_value;
  while ( strcmp(epairs->key, key) != 0 )
  {
    epairs = epairs->next;
    if ( epairs == nullptr )
      return default_value;
  }
  return epairs->value;
}

//------------------------------------------------------------------------------
// Address: 0x1000AC40
// Name: void ExportDirectLightsToWorldLights(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ExportDirectLightsToWorldLights()
{
  directlight_t *i; // edi
  dworldlight_t *v1; // esi

  *pNumworldlights = 0;
  for ( i = activelights; i != nullptr; i = i->next )
  {
    v1 = &dworldlights[(*pNumworldlights)++];
    if ( *pNumworldlights > 0x2000 )
      _Error(a1: "too many lights %d / %d\n", *pNumworldlights, 0x2000);
    v1->cluster = i->light.cluster;
    v1->type = i->light.type;
    v1->style = i->light.style;
    v1->origin.x = i->light.origin.x;
    v1->origin.y = i->light.origin.y;
    v1->origin.z = i->light.origin.z;
    v1->intensity.x = i->light.intensity.x * 0.0039215689;
    v1->intensity.y = i->light.intensity.y * 0.0039215689;
    v1->intensity.z = i->light.intensity.z * 0.0039215689;
    v1->normal.x = i->light.normal.x;
    v1->normal.y = i->light.normal.y;
    v1->normal.z = i->light.normal.z;
    v1->shadow_cast_offset.x = i->light.shadow_cast_offset.x;
    v1->shadow_cast_offset.y = i->light.shadow_cast_offset.y;
    v1->shadow_cast_offset.z = i->light.shadow_cast_offset.z;
    v1->stopdot = i->light.stopdot;
    v1->stopdot2 = i->light.stopdot2;
    v1->exponent = i->light.exponent;
    v1->radius = i->light.radius;
    v1->constant_attn = i->light.constant_attn;
    v1->linear_attn = i->light.linear_attn;
    v1->quadratic_attn = i->light.quadratic_attn;
    v1->flags = i->light.flags;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AD60
// Name: void GatherSampleSkyLightSSE(struct SSE_sampleLightOutput_t __near &,struct directlight_t __near *,int,class FourVectors const __near &,class FourVectors __near *,int,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall GatherSampleSkyLightSSE(
        int a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        SSE_sampleLightOutput_t *out,
        directlight_t *dl,
        int facenum,
        const FourVectors *pos,
        FourVectors *pNormals,
        int normalCount,
        int iThread,
        char nLFlags,
        int static_prop_index_to_ignore)
{
  float m_flSkyLightSunAngularExtent; // xmm4_4
  unsigned int *v13; // esi
  bool v14; // zf
  __m128 v15; // xmm0
  int v16; // edi
  float v17; // xmm2_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  double Element; // st7
  double v21; // st7
  double x; // xmm0_8
  double v23; // xmm0_8
  double v24; // xmm0_8
  float v25; // xmm1_4
  __m128 v26; // xmm3
  __m128 v27; // xmm2
  __m128 v28; // xmm3
  __m128 v29; // xmm0
  __m128 v30; // xmm3
  __m128 v31; // xmm1
  __m128 v32; // xmm3
  __m128 v33; // xmm2
  __m128 v34; // xmm0
  __m128 v35; // xmm0
  __m128 v36; // xmm0
  __m128 *v37; // ecx
  __m128 *p_z; // eax
  int v39; // edx
  __m128 v40; // xmm1
  __m128 v41; // xmm1
  int v42; // [esp-20h] [ebp-D0h]
  int v43; // [esp-20h] [ebp-D0h]
  long double v44; // [esp-1Ch] [ebp-CCh]
  long double v45; // [esp-1Ch] [ebp-CCh]
  long double v46; // [esp-1Ch] [ebp-CCh]
  long double v47; // [esp-1Ch] [ebp-CCh]
  _BYTE v48[72]; // [esp-Ch] [ebp-BCh] OVERLAPPED BYREF
  _BYTE ofs[40]; // [esp+44h] [ebp-6Ch] OVERLAPPED BYREF
  DirectionalSampler_t sampler; // [esp+74h] [ebp-3Ch] BYREF
  Vector delta; // [esp+8Ch] [ebp-24h]
  float v52; // [esp+98h] [ebp-18h]
  int v53; // [esp+9Ch] [ebp-14h]
  float fSunAngularExtent; // [esp+A0h] [ebp-10h]
  int v55; // [esp+A4h] [ebp-Ch]
  int nsamples; // [esp+A8h] [ebp-8h]
  int retaddr; // [esp+B0h] [ebp+0h]

  v55 = a1;
  nsamples = retaddr;
  m_flSkyLightSunAngularExtent = g_SunAngularExtent;
  HIDWORD(v44) = a3;
  v13 = (unsigned int *)dl;
  v14 = !dl->m_bSkyLightIsDirectionalLight;
  LODWORD(v44) = a2;
  HIBYTE(fSunAngularExtent) = (nLFlags & 2) != 0;
  delta.z = g_SunAngularExtent;
  if ( !v14 )
  {
    m_flSkyLightSunAngularExtent = dl->m_flSkyLightSunAngularExtent;
    delta.z = m_flSkyLightSunAngularExtent;
  }
  if ( (nLFlags & 2) != 0 )
    v15 = _mm_shuffle_ps((__m128)0x3EB33333u, (__m128)0x3EB33333u, 0);
  else
    v15 = _mm_sub_ps(
            Four_Zeros,
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps((__m128)LODWORD(dl->light.normal.y), (__m128)LODWORD(dl->light.normal.y), 0),
                  pNormals->y),
                _mm_mul_ps(
                  _mm_shuffle_ps((__m128)LODWORD(dl->light.normal.x), (__m128)LODWORD(dl->light.normal.x), 0),
                  pNormals->x)),
              _mm_mul_ps(
                _mm_shuffle_ps((__m128)LODWORD(dl->light.normal.z), (__m128)LODWORD(dl->light.normal.z), 0),
                pNormals->z)));
  *(__m128 *)&v48[48] = _mm_max_ps(v15, Four_Zeros);
  if ( _mm_movemask_ps(_mm_cmpeq_ps(Four_Zeros, *(__m128 *)&v48[48])) != 15 )
  {
    v53 = 1;
    if ( m_flSkyLightSunAngularExtent > 0.0 )
    {
      v53 = 300;
      if ( do_fast != 0 || (nLFlags & 1) != 0 )
        v53 = 75;
    }
    *(__m128 *)&ofs[16] = Four_Zeros;
    *(__m128 *)ofs = Four_Zeros;
    HaltonSequenceGenerator_t::HaltonSequenceGenerator_t(this: (HaltonSequenceGenerator_t *)&ofs[36], b: 2);
    HaltonSequenceGenerator_t::HaltonSequenceGenerator_t(this: &sampler.zdot, b: 3);
    v16 = 0;
    if ( v53 > 0 )
    {
      do
      {
        v17 = dl->light.normal.x * -56755.84;
        v18 = dl->light.normal.y * -56755.84;
        v19 = dl->light.normal.z * -56755.84;
        *(float *)&sampler.vrot.seed = v17;
        *(float *)&sampler.vrot.base = v18;
        sampler.vrot.fbase = v19;
        if ( v16 != 0 )
        {
          v42 = (*(_DWORD *)&ofs[36])++;
          Element = HaltonSequenceGenerator_t::GetElement(this: (HaltonSequenceGenerator_t *)&ofs[36], elem: v42);
          v43 = sampler.zdot.seed++;
          delta.x = Element + Element - 1.0;
          v21 = HaltonSequenceGenerator_t::GetElement(this: &sampler.zdot, elem: v43);
          x = delta.x;
          v52 = v21 * 6.283185307179586;
          __libm_sse2_acos(x: v44);
          *(float *)&x = x;
          __libm_sse2_sin(x: v45);
          delta.y = *(float *)&x;
          v23 = v52;
          __libm_sse2_cos(x: v46);
          *(float *)&v23 = v23;
          *(float *)&v48[68] = *(float *)&v23 * delta.y;
          v24 = v52;
          __libm_sse2_sin(x: v47);
          *(float *)&v24 = v24;
          v25 = delta.z * 56755.84086242099;
          v17 = (float)(*(float *)&v48[68] * v25) + *(float *)&sampler.vrot.seed;
          v18 = (float)((float)(*(float *)&v24 * delta.y) * v25) + *(float *)&sampler.vrot.base;
          v19 = (float)(v25 * delta.x) + sampler.vrot.fbase;
        }
        v26 = 0;
        v26.m128_f32[0] = v17;
        v27 = v26;
        v28 = 0;
        v28.m128_f32[0] = v18;
        v29 = v28;
        v30 = 0;
        v30.m128_f32[0] = v19;
        v31 = v30;
        v32 = _mm_add_ps(pos->x, _mm_shuffle_ps(v27, v27, 0));
        v33 = _mm_add_ps(pos->y, _mm_shuffle_ps(v29, v29, 0));
        v34 = _mm_add_ps(pos->z, _mm_shuffle_ps(v31, v31, 0));
        *(__m128 *)v48 = v32;
        *(__m128 *)&v48[16] = v33;
        *(__m128 *)&v48[32] = v34;
        TestLine_DoesHitSky(
          start: pos,
          stop: (const FourVectors *)v48,
          pFractionVisible: (__m128 *)ofs,
          canRecurse: true,
          static_prop_to_skip: static_prop_index_to_ignore,
          bDoDebug: false);
        ++v16;
        *(__m128 *)&ofs[16] = _mm_add_ps(*(__m128 *)ofs, *(__m128 *)&ofs[16]);
      }
      while ( v16 < v53 );
      v13 = (unsigned int *)dl;
    }
    v35 = 0;
    v35.m128_f32[0] = 1.0 / (float)v53;
    v36 = _mm_mul_ps(_mm_shuffle_ps(v35, v35, 0), *(__m128 *)&ofs[16]);
    out->m_flDot[0] = _mm_mul_ps(v36, *(__m128 *)&v48[48]);
    out->m_flFalloff = Four_Ones;
    out->m_flSunAmount = _mm_mul_ps(_mm_shuffle_ps((__m128)0x461C4000u, (__m128)0x461C4000u, 0), v36);
    if ( normalCount > 1 )
    {
      v37 = &out->m_flDot[1];
      p_z = &pNormals[1].z;
      v39 = normalCount - 1;
      do
      {
        if ( HIBYTE(fSunAngularExtent) != 0 )
        {
          v40 = 0;
          v40.m128_f32[0] = 0.34999999;
          v41 = _mm_shuffle_ps(v40, v40, 0);
        }
        else
        {
          v41 = _mm_mul_ps(
                  _mm_sub_ps(
                    Four_Zeros,
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps((__m128)v13[9], (__m128)v13[9], 0), p_z[-1]),
                        _mm_mul_ps(_mm_shuffle_ps((__m128)v13[8], (__m128)v13[8], 0), p_z[-2])),
                      _mm_mul_ps(_mm_shuffle_ps((__m128)v13[10], (__m128)v13[10], 0), *p_z))),
                  v36);
        }
        *v37 = v41;
        p_z += 3;
        ++v37;
        --v39;
      }
      while ( v39 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B0D0
// Name: void GatherSampleAmbientSkySSE(struct SSE_sampleLightOutput_t __near &,struct directlight_t __near *,int,class FourVectors const __near &,class FourVectors __near *,int,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall GatherSampleAmbientSkySSE(
        int a1@<ebp>,
        double a2@<esi:edi>,
        SSE_sampleLightOutput_t *out,
        directlight_t *dl,
        int facenum,
        const FourVectors *pos,
        FourVectors *pNormals,
        int normalCount,
        int iThread,
        char nLFlags,
        int static_prop_index_to_ignore,
        float flEpsilon)
{
  int v12; // eax
  double Element; // st7
  double v14; // st7
  double v15; // xmm0_8
  double v16; // xmm0_8
  double v17; // xmm0_8
  bool v18; // cl
  float v19; // xmm1_4
  __m128 v20; // xmm7
  __m128 v21; // xmm4
  __m128 v22; // xmm5
  __m128 v23; // xmm4
  __m128 v24; // xmm5
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  __m128 *p_z; // esi
  int v28; // eax
  __m128 v29; // xmm3
  int v30; // edi
  __m128 v31; // xmm1
  __m128 v32; // xmm0
  __m128 v33; // xmm1
  __m128 v34; // xmm0
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  __m128 v37; // xmm3
  __m128 x; // xmm0
  __m128 v39; // xmm6
  __m128 y; // xmm1
  __m128 v41; // xmm6
  __m128 z; // xmm2
  __m128 v43; // xmm6
  __m128 v44; // xmm3
  int v45; // ecx
  __m128 v46; // xmm0
  int v47; // eax
  int v48; // edx
  __m128 v49; // xmm3
  __m128 v50; // xmm2
  __m128 v51; // xmm2
  int v52; // eax
  __m128 v53; // xmm1
  __m128 v54; // xmm0
  int v55; // [esp-20h] [ebp-1B0h]
  int v56; // [esp-20h] [ebp-1B0h]
  long double v57; // [esp-1Ch] [ebp-1ACh]
  long double v58; // [esp-1Ch] [ebp-1ACh]
  long double v59; // [esp-1Ch] [ebp-1ACh]
  long double v60; // [esp-1Ch] [ebp-1ACh]
  _BYTE v61[240]; // [esp-Ch] [ebp-19Ch] OVERLAPPED BYREF
  _BYTE v62[72]; // [esp+E4h] [ebp-ACh] OVERLAPPED BYREF
  _BYTE v63[40]; // [esp+134h] [ebp-5Ch] OVERLAPPED BYREF
  DirectionalSampler_t sampler; // [esp+164h] [ebp-2Ch] BYREF
  float v65; // [esp+17Ch] [ebp-14h]
  char v66; // [esp+182h] [ebp-Eh]
  bool v67; // [esp+183h] [ebp-Dh]
  int v68; // [esp+184h] [ebp-Ch]
  void *v69; // [esp+188h] [ebp-8h]
  void *retaddr; // [esp+190h] [ebp+0h]

  v68 = a1;
  v69 = retaddr;
  v66 = nLFlags & 1;
  v57 = a2;
  v67 = (nLFlags & 2) != 0;
  *(__m128 *)&v63[16] = Four_Zeros;
  if ( normalCount > 0 )
  {
    *(__m128 *)v62 = Four_Zeros;
    qmemcpy(&v62[16], v62, 4 * ((unsigned int)(16 * normalCount - 16) >> 2));
    *(__m128 *)&v61[96] = Four_Zeros;
    qmemcpy(&v61[112], &v61[96], 4 * ((unsigned int)(16 * normalCount - 16) >> 2));
  }
  HaltonSequenceGenerator_t::HaltonSequenceGenerator_t(this: (HaltonSequenceGenerator_t *)&v63[36], b: 2);
  HaltonSequenceGenerator_t::HaltonSequenceGenerator_t(this: &sampler.zdot, b: 3);
  if ( do_fast != 0 || v66 != 0 )
    v12 = 40;
  else
    v12 = (int)(float)(g_flSkySampleScale * 162.0);
  if ( v12 > 0 )
  {
    *(_OWORD *)&v61[224] = 0x3A83126Fu;
    sampler.vrot.base = v12;
    do
    {
      v55 = (*(_DWORD *)&v63[36])++;
      Element = HaltonSequenceGenerator_t::GetElement(this: (HaltonSequenceGenerator_t *)&v63[36], elem: v55);
      v56 = sampler.zdot.seed++;
      v65 = Element + Element - 1.0;
      v14 = HaltonSequenceGenerator_t::GetElement(this: &sampler.zdot, elem: v56);
      v15 = v65;
      *(float *)&sampler.vrot.seed = v14 * 6.283185307179586;
      __libm_sse2_acos(x: v57);
      *(float *)&v15 = v15;
      __libm_sse2_sin(x: v58);
      sampler.vrot.fbase = *(float *)&v15;
      v16 = *(float *)&sampler.vrot.seed;
      __libm_sse2_cos(x: v59);
      *(float *)&v16 = v16;
      *(float *)&v62[68] = *(float *)&v16 * sampler.vrot.fbase;
      v17 = *(float *)&sampler.vrot.seed;
      __libm_sse2_sin(x: v60);
      v18 = v67;
      v19 = v17;
      v20 = _mm_shuffle_ps((__m128)*(unsigned int *)&v62[68], (__m128)*(unsigned int *)&v62[68], 0);
      v21 = 0;
      v22 = 0;
      v21.m128_f32[0] = v19 * sampler.vrot.fbase;
      v22.m128_f32[0] = v65;
      v23 = _mm_shuffle_ps(v21, v21, 0);
      v24 = _mm_shuffle_ps(v22, v22, 0);
      if ( v67 )
        v25 = _mm_shuffle_ps((__m128)0x3EB33333u, (__m128)0x3EB33333u, 0);
      else
        v25 = _mm_sub_ps(
                Four_Zeros,
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(pNormals->y, v23), _mm_mul_ps(pNormals->x, v20)),
                  _mm_mul_ps(pNormals->z, v24)));
      v26 = _mm_cmplt_ps(_mm_shuffle_ps(*(__m128 *)&v61[224], *(__m128 *)&v61[224], 0), v25);
      *(__m128 *)&v61[160] = v25;
      if ( _mm_movemask_ps(v26) != 0 )
      {
        *(__m128 *)&v61[160] = _mm_and_ps(v26, v25);
        *(__m128 *)&v63[16] = _mm_add_ps(*(__m128 *)&v61[160], *(__m128 *)&v63[16]);
        *(__m128 *)v62 = _mm_add_ps(_mm_and_ps(Four_Ones, v26), *(__m128 *)v62);
        if ( normalCount > 1 )
        {
          p_z = &pNormals[1].z;
          v28 = 0;
          v29 = _mm_shuffle_ps(*(__m128 *)&v61[224], *(__m128 *)&v61[224], 0);
          v30 = normalCount - 1;
          do
          {
            if ( v18 )
              *(__m128 *)&v61[v28 + 176] = _mm_shuffle_ps((__m128)0x3EB33333u, (__m128)0x3EB33333u, 0);
            else
              *(__m128 *)&v61[v28 + 176] = _mm_sub_ps(
                                             Four_Zeros,
                                             _mm_add_ps(
                                               _mm_add_ps(_mm_mul_ps(p_z[-1], v23), _mm_mul_ps(p_z[-2], v20)),
                                               _mm_mul_ps(*p_z, v24)));
            v31 = *(__m128 *)&v61[v28 + 176];
            v32 = _mm_cmplt_ps(v29, v31);
            v33 = _mm_and_ps(v31, v32);
            v34 = _mm_add_ps(_mm_and_ps(_mm_and_ps(v32, v26), Four_Ones), *(__m128 *)&v62[v28 + 16]);
            *(__m128 *)&v61[v28 + 176] = v33;
            *(__m128 *)&v62[v28 + 16] = v34;
            p_z += 3;
            v28 += 16;
            --v30;
          }
          while ( v30 != 0 );
        }
        v35 = _mm_shuffle_ps((__m128)0xC75DB3D7, (__m128)0xC75DB3D7, 0);
        v36 = _mm_mul_ps(v23, v35);
        v37 = _mm_mul_ps(v24, v35);
        x = pos->x;
        v39 = _mm_add_ps(pos->x, _mm_mul_ps(v35, v20));
        y = pos->y;
        *(__m128 *)&v61[48] = v39;
        v41 = _mm_add_ps(y, v36);
        z = pos->z;
        *(__m128 *)&v61[64] = v41;
        *(__m128 *)&v61[80] = _mm_add_ps(z, v37);
        v43 = 0;
        v43.m128_i32[0] = LODWORD(flEpsilon) ^ _mask__NegFloat_;
        v44 = _mm_shuffle_ps(v43, v43, 0);
        *(__m128 *)v61 = _mm_sub_ps(x, _mm_mul_ps(v44, v20));
        *(__m128 *)&v61[16] = _mm_sub_ps(y, _mm_mul_ps(v23, v44));
        *(__m128 *)&v61[32] = _mm_sub_ps(z, _mm_mul_ps(v24, v44));
        *(__m128 *)v63 = Four_Ones;
        TestLine_DoesHitSky(
          start: (const FourVectors *)v61,
          stop: (const FourVectors *)&v61[48],
          pFractionVisible: (__m128 *)v63,
          canRecurse: true,
          static_prop_to_skip: static_prop_index_to_ignore,
          bDoDebug: false);
        v45 = normalCount;
        if ( normalCount > 0 )
        {
          v46 = *(__m128 *)v63;
          v47 = 0;
          do
          {
            *(__m128 *)&v61[v47 + 96] = _mm_add_ps(
                                          _mm_mul_ps(*(__m128 *)&v61[v47 + 160], v46),
                                          *(__m128 *)&v61[v47 + 96]);
            v47 += 16;
            --v45;
          }
          while ( v45 != 0 );
        }
      }
      --sampler.vrot.base;
    }
    while ( sampler.vrot.base != 0 );
  }
  v48 = normalCount;
  out->m_flFalloff = Four_Ones;
  if ( normalCount > 0 )
  {
    v49 = *(__m128 *)&v63[16];
    v50 = _mm_rcp_ps(*(__m128 *)v62);
    v51 = _mm_sub_ps(_mm_add_ps(v50, v50), _mm_mul_ps(_mm_mul_ps(v50, v50), *(__m128 *)v62));
    v52 = 0;
    do
    {
      out->m_flDot[v52] = _mm_mul_ps(_mm_mul_ps(*(__m128 *)&v62[v52 * 16], v51), v49);
      v53 = out->m_flDot[v52];
      v54 = _mm_rcp_ps(v53);
      out->m_flDot[v52] = _mm_mul_ps(
                            _mm_sub_ps(_mm_add_ps(v54, v54), _mm_mul_ps(_mm_mul_ps(v54, v54), v53)),
                            *(__m128 *)&v61[v52 * 16 + 96]);
      ++v52;
      --v48;
    }
    while ( v48 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B500
// Name: void GatherSampleStandardLightSSE(struct SSE_sampleLightOutput_t __near &,struct directlight_t __near *,int,class FourVectors const __near &,class FourVectors __near *,int,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall GatherSampleStandardLightSSE(
        int a1@<ebp>,
        SSE_sampleLightOutput_t *out,
        directlight_t *dl,
        int facenum,
        const FourVectors *pos,
        FourVectors *pNormals,
        int normalCount,
        int iThread,
        char nLFlags,
        int static_prop_index_to_ignore)
{
  bool v10; // dl
  bool v11; // zf
  __m128 v12; // xmm7
  __m128 x_low; // xmm7
  __m128 v14; // xmm0
  const FourVectors *v15; // ecx
  __m128 v16; // xmm2
  __m128 v17; // xmm3
  __m128 v18; // xmm1
  __m128 v19; // xmm0
  __m128 v20; // xmm5
  __m128 v21; // xmm4
  __m128 v22; // xmm2
  __m128 v23; // xmm1
  __m128 v24; // xmm3
  __m128 v25; // xmm6
  __m128 v26; // xmm5
  __m128 v27; // xmm4
  float m_flEndFadeDistance; // xmm3_4
  __m128 v29; // xmm2
  __m128 v30; // xmm5
  emittype_t type; // eax
  __m128 v32; // xmm3
  __m128 v33; // xmm6
  __m128 v34; // xmm5
  __int32 v35; // eax
  __m128 v36; // xmm4
  __m128 v37; // xmm0
  __m128 linear_attn_low; // xmm2
  __m128 constant_attn_low; // xmm1
  __m128 v40; // xmm0
  __m128 v41; // xmm1
  __m128 v42; // xmm0
  __m128 v43; // xmm5
  __m128 v44; // xmm2
  __m128 v45; // xmm2
  __m128 v46; // xmm0
  __m128 v47; // xmm6
  __m128 v48; // xmm0
  float x; // xmm1_4
  __m128 v50; // xmm0
  __m128 v51; // xmm1
  __m128 v52; // xmm0
  __m128 m_flFalloff; // xmm4
  __m128 v54; // xmm0
  __m128 v55; // xmm5
  __m128 v56; // xmm4
  __m128 v57; // xmm6
  __m128 v58; // xmm4
  __m128 v59; // xmm5
  float m_flStartFadeDistance; // xmm6_4
  __m128 v61; // xmm1
  __m128 v62; // xmm0
  __m128 v63; // xmm5
  __m128 v64; // xmm1
  __m128 v65; // xmm4
  __m128 v66; // xmm0
  __m128 *v67; // edi
  __m128 *p_z; // eax
  int v69; // esi
  __m128 v70; // xmm0
  _BYTE inFringe_4[128]; // [esp+24h] [ebp-BCh] OVERLAPPED BYREF
  _BYTE v72[32]; // [esp+A4h] [ebp-3Ch] OVERLAPPED BYREF
  char v73; // [esp+D2h] [ebp-Eh]
  bool v74; // [esp+D3h] [ebp-Dh]
  int v75; // [esp+D4h] [ebp-Ch]
  void *v76; // [esp+D8h] [ebp-8h]
  void *retaddr; // [esp+E0h] [ebp+0h]

  v75 = a1;
  v76 = retaddr;
  *(__m128 *)&inFringe_4[32] = _mm_shuffle_ps((__m128)LODWORD(vec3_origin.y), (__m128)LODWORD(vec3_origin.y), 0);
  v10 = (nLFlags & 2) != 0;
  v11 = dl->facenum == -1;
  v12 = _mm_shuffle_ps((__m128)LODWORD(vec3_origin.x), (__m128)LODWORD(vec3_origin.x), 0);
  v74 = v10;
  *(__m128 *)&inFringe_4[16] = v12;
  *(__m128 *)&inFringe_4[48] = _mm_shuffle_ps((__m128)LODWORD(vec3_origin.z), (__m128)LODWORD(vec3_origin.z), 0);
  if ( v11 )
  {
    x_low = (__m128)LODWORD(dl->light.origin.x);
    *(__m128 *)&inFringe_4[32] = _mm_shuffle_ps(
                                   (__m128)LODWORD(dl->light.origin.y),
                                   (__m128)LODWORD(dl->light.origin.y),
                                   0);
    v12 = _mm_shuffle_ps(x_low, x_low, 0);
    v14 = _mm_shuffle_ps((__m128)LODWORD(dl->light.origin.z), (__m128)LODWORD(dl->light.origin.z), 0);
    *(__m128 *)&inFringe_4[16] = v12;
    *(__m128 *)&inFringe_4[48] = v14;
  }
  v15 = pos;
  v16 = _mm_sub_ps(*(__m128 *)&inFringe_4[32], pos->y);
  v17 = _mm_sub_ps(*(__m128 *)&inFringe_4[48], pos->z);
  v18 = _mm_sub_ps(v12, pos->x);
  v19 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v18, v18), _mm_mul_ps(v16, v16)), _mm_mul_ps(v17, v17));
  v20 = _mm_rsqrt_ps(v19);
  v21 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(Four_Threes, _mm_mul_ps(_mm_mul_ps(v20, v20), v19)), v20), Four_PointFives);
  *(__m128 *)&inFringe_4[80] = _mm_mul_ps(v16, v21);
  v22 = (__m128)0x3EB33333u;
  v23 = _mm_mul_ps(v18, v21);
  v24 = _mm_mul_ps(v17, v21);
  *(__m128 *)&inFringe_4[64] = v23;
  *(__m128 *)&inFringe_4[96] = v24;
  v25 = _mm_sqrt_ps(v19);
  *(_OWORD *)&inFringe_4[112] = 0x3EB33333u;
  v26 = _mm_shuffle_ps(v22, v22, 0);
  if ( (nLFlags & 2) == 0 )
    v26 = _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(pNormals->y, *(__m128 *)&inFringe_4[80]), _mm_mul_ps(pNormals->x, v23)),
            _mm_mul_ps(pNormals->z, v24));
  v27 = Four_Zeros;
  *(__m128 *)&v72[16] = _mm_max_ps(Four_Zeros, v26);
  m_flEndFadeDistance = dl->m_flEndFadeDistance;
  if ( m_flEndFadeDistance <= dl->m_flStartFadeDistance )
  {
    v73 = 0;
  }
  else
  {
    v29 = 0;
    v29.m128_f32[0] = m_flEndFadeDistance;
    v30 = _mm_cmple_ps(v25, _mm_shuffle_ps(v29, v29, 0));
    v73 = 1;
    *(__m128 *)&v72[16] = _mm_and_ps(v30, *(__m128 *)&v72[16]);
    if ( _mm_movemask_ps(v30) == 0 )
      return;
    v22 = *(__m128 *)&inFringe_4[112];
  }
  type = dl->light.type;
  v32 = _mm_max_ps(v25, Four_Ones);
  v33 = _mm_shuffle_ps((__m128)LODWORD(dl->m_flCapDist), (__m128)LODWORD(dl->m_flCapDist), 0);
  *(__m128 *)v72 = v32;
  v34 = _mm_min_ps(v32, v33);
  if ( type == emit_surface )
  {
    v55 = _mm_max_ps(
            Four_Zeros,
            _mm_sub_ps(
              Four_Zeros,
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_shuffle_ps((__m128)LODWORD(dl->light.normal.x), (__m128)LODWORD(dl->light.normal.x), 0),
                    v23),
                  _mm_mul_ps(
                    _mm_shuffle_ps((__m128)LODWORD(dl->light.normal.y), (__m128)LODWORD(dl->light.normal.y), 0),
                    *(__m128 *)&inFringe_4[80])),
                _mm_mul_ps(
                  _mm_shuffle_ps((__m128)LODWORD(dl->light.normal.z), (__m128)LODWORD(dl->light.normal.z), 0),
                  *(__m128 *)&inFringe_4[96]))));
    if ( _mm_movemask_ps(_mm_cmpeq_ps(Four_Zeros, *(__m128 *)&v72[16])) == 15 )
      return;
    v56 = _mm_rcp_ps(v19);
    v32 = *(__m128 *)v72;
    out->m_flFalloff = _mm_mul_ps(_mm_sub_ps(_mm_add_ps(v56, v56), _mm_mul_ps(_mm_mul_ps(v56, v56), v19)), v55);
    v57 = _mm_shuffle_ps((__m128)0x3D000000u, (__m128)0x3D000000u, 0);
    v58 = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(dl->light.normal.y), (__m128)LODWORD(dl->light.normal.y), 0), v57),
            *(__m128 *)&inFringe_4[32]);
    v59 = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(dl->light.normal.z), (__m128)LODWORD(dl->light.normal.z), 0), v57),
            *(__m128 *)&inFringe_4[48]);
    *(__m128 *)&inFringe_4[16] = _mm_add_ps(
                                   _mm_mul_ps(
                                     v57,
                                     _mm_shuffle_ps(
                                       (__m128)LODWORD(dl->light.normal.x),
                                       (__m128)LODWORD(dl->light.normal.x),
                                       0)),
                                   v12);
    *(__m128 *)&inFringe_4[32] = v58;
    *(__m128 *)&inFringe_4[48] = v59;
    goto LABEL_25;
  }
  v35 = type - 1;
  if ( v35 == 0 )
  {
    v52 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_shuffle_ps((__m128)LODWORD(dl->light.quadratic_attn), (__m128)LODWORD(dl->light.quadratic_attn), 0),
                _mm_mul_ps(v34, v34)),
              _mm_mul_ps(
                _mm_shuffle_ps((__m128)LODWORD(dl->light.linear_attn), (__m128)LODWORD(dl->light.linear_attn), 0),
                v34)),
            _mm_shuffle_ps((__m128)LODWORD(dl->light.constant_attn), (__m128)LODWORD(dl->light.constant_attn), 0));
    out->m_flFalloff = v52;
    if ( g_bFiniteFalloffModel )
    {
      out->m_flFalloff = _mm_max_ps(Four_Zeros, v52);
    }
    else
    {
      m_flFalloff = out->m_flFalloff;
      v54 = _mm_rcp_ps(m_flFalloff);
      out->m_flFalloff = _mm_sub_ps(_mm_add_ps(v54, v54), _mm_mul_ps(_mm_mul_ps(v54, v54), m_flFalloff));
    }
    goto LABEL_26;
  }
  if ( v35 == 1 )
  {
    v36 = _mm_sub_ps(
            Four_Zeros,
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps((__m128)LODWORD(dl->light.normal.x), (__m128)LODWORD(dl->light.normal.x), 0),
                  v23),
                _mm_mul_ps(
                  _mm_shuffle_ps((__m128)LODWORD(dl->light.normal.y), (__m128)LODWORD(dl->light.normal.y), 0),
                  *(__m128 *)&inFringe_4[80])),
              _mm_mul_ps(
                _mm_shuffle_ps((__m128)LODWORD(dl->light.normal.z), (__m128)LODWORD(dl->light.normal.z), 0),
                *(__m128 *)&inFringe_4[96])));
    v37 = _mm_cmplt_ps(_mm_shuffle_ps((__m128)LODWORD(dl->light.stopdot2), (__m128)LODWORD(dl->light.stopdot2), 0), v36);
    if ( _mm_movemask_ps(v37) == 0 )
      return;
    linear_attn_low = (__m128)LODWORD(dl->light.linear_attn);
    constant_attn_low = (__m128)LODWORD(dl->light.constant_attn);
    *(__m128 *)&v72[16] = _mm_and_ps(v37, *(__m128 *)&v72[16]);
    v40 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_shuffle_ps((__m128)LODWORD(dl->light.quadratic_attn), (__m128)LODWORD(dl->light.quadratic_attn), 0),
                _mm_mul_ps(v34, v34)),
              _mm_mul_ps(_mm_shuffle_ps(linear_attn_low, linear_attn_low, 0), v34)),
            _mm_shuffle_ps(constant_attn_low, constant_attn_low, 0));
    out->m_flFalloff = v40;
    if ( g_bFiniteFalloffModel )
    {
      out->m_flFalloff = _mm_max_ps(Four_Zeros, v40);
    }
    else
    {
      v41 = out->m_flFalloff;
      v42 = _mm_rcp_ps(v41);
      out->m_flFalloff = _mm_sub_ps(_mm_add_ps(v42, v42), _mm_mul_ps(_mm_mul_ps(v42, v42), v41));
    }
    out->m_flFalloff = _mm_mul_ps(out->m_flFalloff, v36);
    v43 = 0;
    v43.m128_f32[0] = dl->light.stopdot;
    v44 = 0;
    v44.m128_f32[0] = v43.m128_f32[0] - dl->light.stopdot2;
    v45 = _mm_shuffle_ps(v44, v44, 0);
    v46 = _mm_rcp_ps(v45);
    v47 = _mm_cmple_ps(v36, _mm_shuffle_ps(v43, v43, 0));
    v48 = _mm_max_ps(
            _mm_min_ps(
              _mm_mul_ps(
                _mm_sub_ps(_mm_add_ps(v46, v46), _mm_mul_ps(_mm_mul_ps(v46, v46), v45)),
                _mm_sub_ps(
                  v36,
                  _mm_shuffle_ps((__m128)LODWORD(dl->light.stopdot2), (__m128)LODWORD(dl->light.stopdot2), 0))),
              Four_Ones),
            Four_Zeros);
    x = dl->light.exponent;
    *(__m128 *)inFringe_4 = v48;
    if ( x != 0.0 && x != 1.0 )
    {
      PowSIMD(result: (__m128 *)inFringe_4, x: (const __m128 *)LODWORD(x));
      v32 = *(__m128 *)v72;
      v10 = v74;
      v15 = pos;
    }
    v50 = _mm_add_ps(_mm_and_ps(v48, v47), _mm_andnot_ps(v47, Four_Ones));
    v51 = _mm_mul_ps(out->m_flFalloff, v50);
    *(__m128 *)inFringe_4 = v50;
    out->m_flFalloff = v51;
LABEL_25:
    v22 = *(__m128 *)&inFringe_4[112];
    v23 = *(__m128 *)&inFringe_4[64];
LABEL_26:
    v27 = Four_Zeros;
  }
  if ( v73 != 0 )
  {
    m_flStartFadeDistance = dl->m_flStartFadeDistance;
    v61 = 0;
    v61.m128_f32[0] = dl->m_flEndFadeDistance - m_flStartFadeDistance;
    v62 = _mm_shuffle_ps(v61, v61, 0);
    v63 = _mm_rcp_ps(v62);
    v64 = 0;
    v64.m128_f32[0] = m_flStartFadeDistance;
    v65 = _mm_sub_ps(
            Four_Ones,
            _mm_max_ps(
              _mm_min_ps(
                _mm_mul_ps(
                  _mm_sub_ps(_mm_add_ps(v63, v63), _mm_mul_ps(_mm_mul_ps(v63, v63), v62)),
                  _mm_sub_ps(v32, _mm_shuffle_ps(v64, v64, 0))),
                Four_Ones),
              v27));
    v66 = _mm_mul_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps((__m128)0x40C00000u, (__m128)0x40C00000u, 0), v65),
                    _mm_shuffle_ps((__m128)0x41700000u, (__m128)0x41700000u, 0)),
                  v65),
                _mm_shuffle_ps((__m128)0x41200000u, (__m128)0x41200000u, 0)),
              _mm_mul_ps(v65, v65)),
            v65);
    out->m_flFalloff = _mm_mul_ps(out->m_flFalloff, v66);
    v23 = *(__m128 *)&inFringe_4[64];
    *(__m128 *)inFringe_4 = v66;
  }
  if ( (nLFlags & 4) == 0 )
  {
    *(__m128 *)v72 = Four_Ones;
    TestLine(
      start: v15,
      stop: (const FourVectors *)&inFringe_4[16],
      pFractionVisible: (__m128 *)v72,
      static_prop_index_to_ignore);
    v23 = *(__m128 *)&inFringe_4[64];
    v22 = *(__m128 *)&inFringe_4[112];
    v10 = v74;
    *(__m128 *)&v72[16] = _mm_mul_ps(*(__m128 *)v72, *(__m128 *)&v72[16]);
  }
  out->m_flDot[0] = *(__m128 *)&v72[16];
  if ( normalCount > 1 )
  {
    v67 = &out->m_flDot[1];
    p_z = &pNormals[1].z;
    v69 = normalCount - 1;
    do
    {
      if ( v10 )
      {
        *v67 = _mm_shuffle_ps(v22, v22, 0);
      }
      else
      {
        v70 = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(p_z[-2], v23), _mm_mul_ps(p_z[-1], *(__m128 *)&inFringe_4[80])),
                _mm_mul_ps(*(__m128 *)&inFringe_4[96], *p_z));
        *v67 = v70;
        *v67 = _mm_max_ps(Four_Zeros, v70);
      }
      p_z += 3;
      ++v67;
      --v69;
    }
    while ( v69 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BB10
// Name: void GatherSampleLightSSE(struct SSE_sampleLightOutput_t __near &,struct directlight_t __near *,int,class FourVectors const __near &,class FourVectors __near *,int,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GatherSampleLightSSE(
        SSE_sampleLightOutput_t *out,
        directlight_t *dl,
        int facenum,
        const FourVectors *pos,
        FourVectors *pNormals,
        int normalCount,
        int iThread,
        char nLFlags,
        int static_prop_index_to_ignore,
        float flEpsilon)
{
  SSE_sampleLightOutput_t *v10; // eax
  int i; // ecx
  __m128 v12; // xmm0
  __m128 v13; // xmm1
  __m128 *v14; // eax
  int v15; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  if ( normalCount > 0 )
  {
    v10 = out;
    for ( i = normalCount; i != 0; --i )
    {
      v10->m_flDot[0] = Four_Zeros;
      v10 = (SSE_sampleLightOutput_t *)((char *)v10 + 16);
    }
  }
  out->m_flFalloff = Four_Zeros;
  out->m_flSunAmount = Four_Zeros;
  switch ( dl->light.type )
  {
    case emit_surface:
    case emit_point:
    case emit_spotlight:
      GatherSampleStandardLightSSE(
        a1: (int)&savedregs,
        out,
        dl,
        facenum,
        pos,
        pNormals,
        normalCount,
        iThread,
        nLFlags,
        static_prop_index_to_ignore);
      goto LABEL_8;
    case emit_skylight:
      GatherSampleSkyLightSSE(
        a1: (int)&savedregs,
        a2: normalCount,
        a3: (int)out,
        out,
        dl,
        facenum,
        pos,
        pNormals,
        normalCount,
        iThread,
        nLFlags,
        static_prop_index_to_ignore);
      goto LABEL_8;
    case emit_skyambient:
      GatherSampleAmbientSkySSE(
        a1: (int)&savedregs,
        a2: COERCE_DOUBLE(__PAIR64__((unsigned int)out, normalCount)),
        out,
        dl,
        facenum,
        pos,
        pNormals,
        normalCount,
        iThread,
        nLFlags,
        static_prop_index_to_ignore,
        flEpsilon);
LABEL_8:
      v12 = _mm_max_ps(out->m_flDot[0], Four_Zeros);
      out->m_flDot[0] = v12;
      v13 = _mm_cmplt_ps(Four_Zeros, v12);
      if ( normalCount > 1 )
      {
        v14 = &out->m_flDot[1];
        v15 = normalCount - 1;
        do
        {
          *v14 = _mm_and_ps(_mm_max_ps(*v14, Four_Zeros), v13);
          ++v14;
          --v15;
        }
        while ( v15 != 0 );
      }
      break;
    default:
      _Error(a1: "Bad dl->light.type");
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BC60
// Name: void GetPhongNormal(int,class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetPhongNormal(int facenum, const Vector *spot, Vector *phongnormal)
{
  dface_t *v3; // edx
  float v4; // xmm1_4
  float v5; // xmm2_4
  int numedges; // esi
  faceneighbor_t *v8; // eax
  float x; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  int v12; // ecx
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // edx
  float v18; // xmm4_4
  float v19; // xmm5_4
  unsigned int v20; // edx
  float v21; // xmm0_4
  float v22; // xmm7_4
  float v23; // xmm6_4
  float v24; // xmm3_4
  float v25; // xmm2_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  float v32; // xmm4_4
  float z; // xmm0_4
  float y; // xmm2_4
  float v35; // xmm3_4
  float v36; // xmm0_4
  float v2_8; // [esp+8h] [ebp-30h]
  float vspot; // [esp+Ch] [ebp-2Ch]
  float vspot_4; // [esp+10h] [ebp-28h]
  float vspot_8; // [esp+14h] [ebp-24h]
  Vector *n2; // [esp+18h] [ebp-20h]
  faceneighbor_t *fn; // [esp+1Ch] [ebp-1Ch]
  Vector *normal; // [esp+20h] [ebp-18h]
  float v44; // [esp+24h] [ebp-14h]
  float v45; // [esp+28h] [ebp-10h]
  float v46; // [esp+2Ch] [ebp-Ch]
  int vert1; // [esp+30h] [ebp-8h]
  int firstedge; // [esp+34h] [ebp-4h]
  int facenuma; // [esp+40h] [ebp+8h]
  Vector *phongnormala; // [esp+48h] [ebp+10h]

  v3 = &g_pFaces[facenum];
  v4 = *(&dplanes.y + 5 * v3->planenum);
  v5 = *(&dplanes.z + 5 * v3->planenum);
  phongnormal->x = *(&dplanes.x + 5 * v3->planenum);
  phongnormal->y = v4;
  phongnormal->z = v5;
  if ( smoothing_threshold != 1.0 )
  {
    numedges = v3->numedges;
    v8 = &faceneighbor[facenum];
    fn = v8;
    if ( numedges > 0 )
    {
      firstedge = v3->firstedge;
      x = face_centroids[facenum].x;
      v10 = *(float *)&dword_10745254[3 * facenum];
      v11 = dword_10745258[3 * facenum];
      vspot = spot->x - x;
      vspot_4 = spot->y - v10;
      normal = v8->normal;
      v46 = x;
      v44 = v10;
      v45 = v11;
      vspot_8 = spot->z - v11;
      v12 = 1;
      facenuma = v3->numedges;
      phongnormala = normal;
      while ( 1 )
      {
        v13 = v12 - 1;
        n2 = &normal[v12 % numedges];
        if ( v12 - 1 >= 0 )
        {
          if ( v13 >= numedges )
            v13 %= numedges;
        }
        else
        {
          v13 = facenuma;
        }
        v14 = dsurfedges[v13 + firstedge];
        vert1 = v14 >= 0 ? dedges[v14].v[0] : *((unsigned __int16 *)&unk_1157EAB2 - 2 * v14);
        v15 = v12;
        if ( v12 >= 0 )
        {
          if ( v12 >= numedges )
            v15 = v12 % numedges;
        }
        else
        {
          v15 = v12 + numedges;
        }
        v16 = dsurfedges[v15 + firstedge];
        v17 = v16 >= 0 ? dedges[v16].v[0] : *((unsigned __int16 *)&unk_1157EAB2 - 2 * v16);
        v18 = dvertexes[vert1].point.x - x;
        v19 = *(float *)&dword_1518407C[3 * vert1] - v10;
        v20 = 3 * v17;
        v21 = dvertexes[v20 / 3].point.x - x;
        v22 = *(float *)&dword_1518407C[v20] - v10;
        v2_8 = dword_15184080[v20] - v11;
        v23 = dword_15184080[3 * vert1] - v11;
        v24 = (float)((float)(v22 * v22) + (float)(v21 * v21)) + (float)(v2_8 * v2_8);
        v25 = (float)((float)(v22 * v19) + (float)(v21 * v18)) + (float)(v2_8 * v23);
        v26 = (float)((float)(vspot_4 * v22) + (float)(vspot * v21)) + (float)(vspot_8 * v2_8);
        v27 = (float)((float)((float)((float)((float)(vspot_4 * v19) + (float)(vspot * v18)) + (float)(vspot_8 * v23))
                            * v24)
                    - (float)(v26 * v25))
            / (float)((float)((float)((float)((float)(v19 * v19) + (float)(v18 * v18)) + (float)(v23 * v23)) * v24)
                    - (float)(v25 * v25));
        v28 = (float)(v26 - (float)(v27 * v25)) / v24;
        if ( v27 >= 0.0 && v28 >= 0.0 )
          break;
        ++phongnormala;
        ++facenuma;
        if ( v12++ >= numedges )
          return;
        x = v46;
        v11 = v45;
        v10 = v44;
      }
      v29 = (float)(1.0 - v27) - v28;
      phongnormal->x = fn->facenormal.x * v29;
      phongnormal->y = fn->facenormal.y * v29;
      phongnormal->z = fn->facenormal.z * v29;
      v30 = (float)(phongnormala->x * v27) + phongnormal->x;
      v31 = (float)(phongnormala->y * v27) + phongnormal->y;
      v32 = phongnormala->z * v27;
      z = phongnormal->z;
      phongnormal->x = v30;
      phongnormal->z = z + v32;
      phongnormal->y = v31;
      y = n2->y;
      v35 = n2->z;
      phongnormal->x = (float)(n2->x * v28) + phongnormal->x;
      v36 = phongnormal->z + (float)(v35 * v28);
      phongnormal->y = (float)(y * v28) + phongnormal->y;
      phongnormal->z = v36;
      VectorNormalize(vec: phongnormal);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C020
// Name: void GetPhongNormal(int,class FourVectors const __near &,class FourVectors __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetPhongNormal(int facenum, const FourVectors *spot, FourVectors *phongnormal)
{
  dface_t *v4; // edi
  float v5; // xmm1_4
  float v6; // xmm2_4
  __m128 v7; // xmm0
  __m128 v8; // xmm0
  __m128 v9; // xmm0
  int numedges; // edi
  int v11; // esi
  faceneighbor_t *v12; // eax
  int v13; // eax
  int v14; // esi
  int v15; // eax
  int v16; // eax
  int v17; // edi
  float v18; // xmm6_4
  float x; // xmm0_4
  float v20; // xmm7_4
  float v21; // xmm2_4
  float v22; // xmm4_4
  float v23; // xmm3_4
  unsigned int v24; // edi
  float v25; // xmm1_4
  float v26; // xmm5_4
  float v27; // xmm0_4
  __m128 v28; // xmm7
  __m128 v29; // xmm7
  __m128 v30; // xmm6
  __m128 v31; // xmm0
  __m128 v32; // xmm1
  __m128 v33; // xmm0
  __m128 v34; // xmm5
  __m128 v35; // xmm0
  __m128 v36; // xmm2
  __m128 v37; // xmm2
  __m128 v38; // xmm0
  __m128 v39; // xmm5
  __m128 v40; // xmm2
  __m128 v41; // xmm0
  __m128 v42; // xmm1
  __m128 v43; // xmm2
  Vector *v44; // esi
  __m128 v45; // xmm4
  __m128 v46; // xmm3
  __m128 v47; // xmm6
  __m128 v48; // xmm5
  __m128 v49; // xmm7
  __m128 v50; // xmm5
  __m128 v51; // xmm3
  __m128 v52; // xmm7
  Vector *v53; // esi
  __m128 v54; // xmm0
  __m128 v55; // xmm3
  __m128 v56; // xmm1
  __m128 y; // xmm1
  __m128 z; // xmm3
  __m128 v59; // xmm0
  __m128 v60; // xmm4
  __m128 v61; // xmm0
  __m128 temp_4; // [esp+44h] [ebp-10Ch]
  __m128 temp_36; // [esp+64h] [ebp-ECh]
  __m128 v64; // [esp+74h] [ebp-DCh]
  __m128 faceCentroid_4; // [esp+84h] [ebp-CCh]
  __m128 faceCentroid_20; // [esp+94h] [ebp-BCh]
  __m128 faceCentroid_36; // [esp+A4h] [ebp-ACh]
  unsigned int v68; // [esp+C0h] [ebp-90h]
  __m128 v2; // [esp+C4h] [ebp-8Ch]
  __m128 v70; // [esp+D4h] [ebp-7Ch]
  __m128 v71; // [esp+E4h] [ebp-6Ch]
  __m128 vspot_4; // [esp+F4h] [ebp-5Ch]
  __m128 vspot_20; // [esp+104h] [ebp-4Ch]
  int v74; // [esp+120h] [ebp-30h]
  int v75; // [esp+12Ch] [ebp-24h]
  unsigned int *v76; // [esp+130h] [ebp-20h]
  Vector *n2; // [esp+134h] [ebp-1Ch]
  unsigned int v78; // [esp+138h] [ebp-18h]
  faceneighbor_t *fn; // [esp+13Ch] [ebp-14h]
  int v80; // [esp+140h] [ebp-10h]
  FourVectors v81; // 0:^10.48

  v4 = &g_pFaces[facenum];
  v5 = *(&dplanes.y + 5 * v4->planenum);
  v6 = *(&dplanes.z + 5 * v4->planenum);
  v7 = (__m128)*((unsigned int *)&dplanes.x + 5 * v4->planenum);
  phongnormal->x = _mm_shuffle_ps(v7, v7, 0);
  v8 = 0;
  v8.m128_f32[0] = v5;
  phongnormal->y = _mm_shuffle_ps(v8, v8, 0);
  v9 = 0;
  v9.m128_f32[0] = v6;
  phongnormal->z = _mm_shuffle_ps(v9, v9, 0);
  v64 = _mm_shuffle_ps((__m128)LODWORD(face_centroids[facenum].x), (__m128)LODWORD(face_centroids[facenum].x), 0);
  faceCentroid_4 = _mm_shuffle_ps(
                     (__m128)(unsigned int)dword_10745254[3 * facenum],
                     (__m128)(unsigned int)dword_10745254[3 * facenum],
                     0);
  faceCentroid_20 = _mm_shuffle_ps(
                      (__m128)LODWORD(dword_10745258[3 * facenum]),
                      (__m128)LODWORD(dword_10745258[3 * facenum]),
                      0);
  fn = (faceneighbor_t *)v4;
  if ( smoothing_threshold != 1.0 )
  {
    numedges = v4->numedges;
    v11 = 0;
    v12 = &faceneighbor[facenum];
    v76 = (unsigned int *)v12;
    if ( numedges > 0 )
    {
      v80 = 0;
      do
      {
        v75 = v11 + 1;
        n2 = v12->normal;
        v74 = (v11 + 1) % numedges;
        if ( v11 >= 0 )
        {
          if ( v11 >= numedges )
            v11 %= numedges;
        }
        else
        {
          v11 += numedges;
        }
        v13 = dsurfedges[(int)fn->neighbor + v11];
        if ( v13 >= 0 )
          v14 = dedges[v13].v[0];
        else
          v14 = *((unsigned __int16 *)&unk_1157EAB2 - 2 * v13);
        v15 = v75;
        if ( v75 >= 0 )
        {
          if ( v75 >= numedges )
            v15 = v74;
        }
        else
        {
          v15 = v75 + numedges;
        }
        v16 = dsurfedges[(int)fn->neighbor + v15];
        if ( v16 >= 0 )
          v17 = dedges[v16].v[0];
        else
          v17 = *((unsigned __int16 *)&unk_1157EAB2 - 2 * v16);
        v18 = *(float *)&dword_10745254[3 * facenum];
        x = face_centroids[facenum].x;
        v20 = dword_10745258[3 * facenum];
        v21 = dvertexes[v14].point.x - x;
        v22 = dword_15184080[3 * v14] - v20;
        v23 = *(float *)&dword_1518407C[3 * v14] - v18;
        v24 = 3 * v17;
        v25 = dvertexes[v24 / 3].point.x - x;
        v26 = *(float *)&dword_1518407C[v24] - v18;
        v71 = _mm_sub_ps(spot->x, v64);
        vspot_4 = _mm_sub_ps(spot->y, faceCentroid_4);
        vspot_20 = _mm_sub_ps(spot->z, faceCentroid_20);
        *(float *)&v68 = dword_15184080[v24] - v20;
        *(float *)&v78 = (float)((float)(v26 * v26) + (float)(v25 * v25)) + (float)(*(float *)&v68 * *(float *)&v68);
        v27 = (float)((float)(v26 * v23) + (float)(v25 * v21)) + (float)(*(float *)&v68 * v22);
        v28 = 0;
        v28.m128_f32[0] = (float)((float)((float)((float)(v23 * v23) + (float)(v21 * v21)) + (float)(v22 * v22))
                                * *(float *)&v78)
                        - (float)(v27 * v27);
        temp_36 = _mm_shuffle_ps(v28, v28, 0);
        v29 = _mm_rcp_ps(temp_36);
        v30 = 0;
        v30.m128_f32[0] = v27;
        v31 = 0;
        v31.m128_f32[0] = v25;
        v32 = v31;
        v33 = 0;
        v33.m128_f32[0] = v26;
        v34 = (__m128)v78;
        v70 = v33;
        v2 = (__m128)v68;
        v35 = 0;
        v35.m128_f32[0] = v21;
        v36 = 0;
        v36.m128_f32[0] = v23;
        faceCentroid_36 = v36;
        v37 = 0;
        v37.m128_f32[0] = v22;
        v38 = _mm_sub_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v35, v35, 0), v71),
                      _mm_mul_ps(_mm_shuffle_ps(faceCentroid_36, faceCentroid_36, 0), vspot_4)),
                    _mm_mul_ps(_mm_shuffle_ps(v37, v37, 0), vspot_20)),
                  _mm_shuffle_ps(v34, v34, 0)),
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v32, v32, 0), v71),
                      _mm_mul_ps(_mm_shuffle_ps(v70, v70, 0), vspot_4)),
                    _mm_mul_ps(_mm_shuffle_ps(v2, v2, 0), vspot_20)),
                  _mm_shuffle_ps(v30, v30, 0)));
        v39 = _mm_shuffle_ps(v34, v34, 0);
        v40 = _mm_rcp_ps(v39);
        v41 = _mm_mul_ps(v38, _mm_sub_ps(_mm_add_ps(v29, v29), _mm_mul_ps(_mm_mul_ps(v29, v29), temp_36)));
        v42 = _mm_mul_ps(
                _mm_sub_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v32, v32, 0), v71),
                      _mm_mul_ps(_mm_shuffle_ps(v70, v70, 0), vspot_4)),
                    _mm_mul_ps(_mm_shuffle_ps(v2, v2, 0), vspot_20)),
                  _mm_mul_ps(_mm_shuffle_ps(v30, v30, 0), v41)),
                _mm_sub_ps(_mm_add_ps(v40, v40), _mm_mul_ps(_mm_mul_ps(v40, v40), v39)));
        v43 = _mm_and_ps(_mm_cmple_ps(Four_Zeros, v42), _mm_cmple_ps(Four_Zeros, v41));
        v12 = &faceneighbor[facenum];
        if ( _mm_movemask_ps(v43) != 0 )
        {
          v44 = n2;
          v81 = *phongnormal;
          v45 = _mm_sub_ps(_mm_sub_ps(Four_Ones, v41), v42);
          v46 = _mm_shuffle_ps((__m128)v76[3], (__m128)v76[3], 0);
          phongnormal->x = v46;
          v47 = _mm_mul_ps(v46, v45);
          v48 = _mm_shuffle_ps((__m128)v76[4], (__m128)v76[4], 0);
          phongnormal->y = v48;
          v49 = (__m128)v76[5];
          v50 = _mm_mul_ps(v48, v45);
          phongnormal->x = v47;
          phongnormal->y = v50;
          v51 = _mm_mul_ps(_mm_shuffle_ps(v49, v49, 0), v45);
          phongnormal->z = v51;
          v52 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v44[v80].x), (__m128)LODWORD(v44[v80].x), 0), v41);
          temp_4 = _mm_shuffle_ps((__m128)LODWORD(v44[v80].y), (__m128)LODWORD(v44[v80].y), 0);
          v53 = &n2[v74];
          phongnormal->z = _mm_add_ps(
                             v51,
                             _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(n2[v80].z), (__m128)LODWORD(n2[v80].z), 0), v41));
          phongnormal->x = _mm_add_ps(v47, v52);
          phongnormal->y = _mm_add_ps(v50, _mm_mul_ps(temp_4, v41));
          v54 = _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v53->x), (__m128)LODWORD(v53->x), 0), v42),
                  phongnormal->x);
          v55 = _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v53->y), (__m128)LODWORD(v53->y), 0), v42),
                  phongnormal->y);
          v56 = _mm_add_ps(
                  _mm_mul_ps(v42, _mm_shuffle_ps((__m128)LODWORD(v53->z), (__m128)LODWORD(v53->z), 0)),
                  phongnormal->z);
          phongnormal->x = _mm_add_ps(_mm_and_ps(v54, v43), _mm_andnot_ps(v43, v81.x));
          phongnormal->y = _mm_add_ps(_mm_and_ps(v55, v43), _mm_andnot_ps(v43, v81.y));
          phongnormal->z = _mm_add_ps(_mm_and_ps(v56, v43), _mm_andnot_ps(v43, v81.z));
        }
        v11 = v75;
        ++v80;
        numedges = SLOWORD(fn->normal);
      }
      while ( v75 < numedges );
    }
    y = phongnormal->y;
    z = phongnormal->z;
    v59 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(y, y), _mm_mul_ps(phongnormal->x, phongnormal->x)), _mm_mul_ps(z, z));
    v60 = _mm_rsqrt_ps(v59);
    v61 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(Four_Threes, _mm_mul_ps(_mm_mul_ps(v60, v60), v59)), v60), Four_PointFives);
    phongnormal->x = _mm_mul_ps(v61, phongnormal->x);
    phongnormal->y = _mm_mul_ps(v61, y);
    phongnormal->z = _mm_mul_ps(v61, z);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C600
// Name: int GetVisCache(int,int,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetVisCache(int lastoffset, int cluster, unsigned __int8 *pvs)
{
  int v4; // esi

  if ( visdatasize != 0 && cluster >= 0 )
  {
    v4 = dvis->bitofs[cluster][0];
    if ( v4 != lastoffset )
    {
      if ( v4 == -1 )
        _Error(a1: "visofs == -1");
      DecompressVis(in: &dvisdata[v4], decompressed: pvs);
    }
    return v4;
  }
  else
  {
    memset(dst: pvs, value: 0xFFu, count: (dvis->numclusters + 7) / 8);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C6B0
// Name: FindOrAllocateLightstyleSamples
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindOrAllocateLightstyleSamples(dface_t *f, facelight_t *fl, int lightstyle, int numnormals)
{
  int v4; // ebx
  int v5; // edi
  unsigned __int8 v6; // al
  LightingValue_t **v8; // esi

  v4 = numnormals;
  v5 = 0;
  while ( 1 )
  {
    v6 = f->styles[v5];
    if ( v6 == lightstyle )
      break;
    if ( v6 == 0xFF )
    {
      if ( numnormals > 0 )
      {
        v8 = fl->light[v5];
        do
        {
          *v8++ = (LightingValue_t *)calloc(count: fl->numsamples, size: 0x10u);
          --v4;
        }
        while ( v4 != 0 );
      }
      f->styles[v5] = lightstyle;
      return v5;
    }
    if ( ++v5 >= 4 )
      return -1;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1000C730
// Name: ComputeIlluminationPointAndNormalsSSE
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall ComputeIlluminationPointAndNormalsSSE(
        const FourVectors *pos@<eax>,
        SSE_SampleInfo_t *pInfo@<ecx>,
        int a3@<ebp>,
        int a4,
        FourVectors *a5)
{
  __m128 *p_z; // edx
  bool v7; // cc
  __m128 v8; // xmm2
  __m128 v9; // xmm3
  __m128 v10; // xmm0
  bool v11; // zf
  __m128 v12; // xmm4
  __m128 v13; // xmm5
  __m128 *v14; // edi
  texinfo_s *m_pTexInfo; // eax
  _OWORD *v16; // ecx
  __m128 *p_y; // eax
  int j; // edx
  __m128 v19; // xmm1
  __m128 v20; // xmm4
  __m128 v21; // xmm0
  __m128 v22; // xmm0
  __m128 v23; // xmm1
  __m128 v24; // xmm3
  __m128 v25; // xmm2
  int *m_Clusters; // esi
  float *v27; // edi
  int m_FaceNum; // [esp-28h] [ebp-138h]
  int v29; // [esp-Ch] [ebp-11Ch] BYREF
  _BYTE bv_24[168]; // [esp+18h] [ebp-F8h] OVERLAPPED BYREF
  Vector v31; // [esp+C0h] [ebp-50h] BYREF
  const Vector *v32; // [esp+CCh] [ebp-44h]
  Vector v33; // [esp+D0h] [ebp-40h] BYREF
  int i; // [esp+DCh] [ebp-34h]
  Vector *v35; // [esp+E0h] [ebp-30h]
  int k; // [esp+E4h] [ebp-2Ch]
  bool v37; // [esp+103h] [ebp-Dh]
  int v38; // [esp+104h] [ebp-Ch]
  void *v39; // [esp+108h] [ebp-8h]
  void *retaddr; // [esp+110h] [ebp+0h]

  v38 = a3;
  v39 = retaddr;
  pInfo->m_Points = *pos;
  p_z = &pos->z;
  v7 = pInfo->m_NormalCount <= 1;
  k = (int)&pos->z;
  v37 = !v7 && (pInfo->m_IsDispFace || *(_DWORD *)(a4 + 108) == 0);
  v8 = (__m128)*(unsigned int *)(a4 + 12);
  v9 = _mm_add_ps(
         pInfo->m_Points.x,
         _mm_shuffle_ps((__m128)*(unsigned int *)(a4 + 4), (__m128)*(unsigned int *)(a4 + 4), 0));
  pInfo->m_Points.y = _mm_add_ps(
                        pInfo->m_Points.y,
                        _mm_shuffle_ps((__m128)*(unsigned int *)(a4 + 8), (__m128)*(unsigned int *)(a4 + 8), 0));
  v10 = _mm_add_ps(pInfo->m_Points.z, _mm_shuffle_ps(v8, v8, 0));
  pInfo->m_Points.x = v9;
  pInfo->m_Points.z = v10;
  v11 = !pInfo->m_IsDispFace;
  v32 = (const Vector *)(a4 + 4);
  if ( v11 )
  {
    if ( *(_DWORD *)(a4 + 108) == 0 )
    {
      v12 = _mm_sub_ps(
              pos->y,
              _mm_shuffle_ps((__m128)*(unsigned int *)(a4 + 32), (__m128)*(unsigned int *)(a4 + 32), 0));
      v13 = _mm_sub_ps(*p_z, _mm_shuffle_ps((__m128)*(unsigned int *)(a4 + 36), (__m128)*(unsigned int *)(a4 + 36), 0));
      m_FaceNum = pInfo->m_FaceNum;
      *(__m128 *)&bv_24[108] = _mm_sub_ps(
                                 pos->x,
                                 _mm_shuffle_ps(
                                   (__m128)*(unsigned int *)(a4 + 28),
                                   (__m128)*(unsigned int *)(a4 + 28),
                                   0));
      *(__m128 *)&bv_24[124] = v12;
      *(__m128 *)&bv_24[140] = v13;
      GetPhongNormal(facenum: m_FaceNum, spot: (const FourVectors *)&bv_24[108], phongnormal: pInfo->m_PointNormals);
      p_z = (__m128 *)k;
    }
  }
  else
  {
    pInfo->m_PointNormals[0] = *a5;
  }
  if ( v37 )
  {
    v35 = (Vector *)&v29;
    v14 = &pInfo->m_PointNormals[0].z;
    for ( i = 4; i != 0; --i )
    {
      m_pTexInfo = pInfo->m_pTexInfo;
      LODWORD(v31.x) = v14[-2].m128_i32[0];
      LODWORD(v31.y) = v14[-1].m128_i32[0];
      LODWORD(v31.z) = v14->m128_i32[0];
      v33 = *(Vector *)&m_pTexInfo->textureVecsTexelsPerWorldUnits[0][0];
      *(_QWORD *)&bv_24[156] = *(_QWORD *)&m_pTexInfo->textureVecsTexelsPerWorldUnits[1][0];
      *(float *)&bv_24[164] = m_pTexInfo->textureVecsTexelsPerWorldUnits[1][2];
      GetBumpNormals(
        sVect: &v33,
        tVect: (const Vector *)&bv_24[156],
        flatNormal: v32,
        phongNormal: &v31,
        bumpNormals: v35);
      v35 += 3;
      v14 = (__m128 *)((char *)v14 + 4);
    }
    v16 = bv_24;
    p_y = &pInfo->m_PointNormals[1].y;
    for ( j = 3; j != 0; --j )
    {
      v19 = *(__m128 *)((char *)v16 - 36);
      v20 = *(__m128 *)((char *)v16 + 72);
      *p_y = *(__m128 *)v16;
      v21 = *(__m128 *)((char *)v16 + 36);
      p_y[-1] = v19;
      p_y[1] = v21;
      v22 = _mm_shuffle_ps(v19, *p_y, 68);
      v23 = _mm_shuffle_ps(v19, *p_y, 238);
      v24 = _mm_shuffle_ps(p_y[1], v20, 68);
      v25 = _mm_shuffle_ps(p_y[1], v20, 238);
      p_y[-1] = _mm_shuffle_ps(v22, v24, 136);
      *p_y = _mm_shuffle_ps(v22, v24, 221);
      p_y[1] = _mm_shuffle_ps(v23, v25, 136);
      p_y += 3;
      v16 = (_OWORD *)((char *)v16 + 12);
    }
    p_z = (__m128 *)k;
  }
  m_Clusters = pInfo->m_Clusters;
  v27 = (float *)p_z;
  for ( k = 4; k != 0; --k )
  {
    v33.x = *(v27 - 8);
    v33.y = *(v27 - 4);
    v33.z = *v27;
    *m_Clusters = ClusterFromPoint(point: &v33);
    ++v27;
    ++m_Clusters;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C9C0
// Name: GatherSampleLightAt4Points
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall GatherSampleLightAt4Points(int a1@<ebp>, SSE_SampleInfo_t *info, int sampleIdx, int numSamples)
{
  directlight_t *v4; // esi
  SSE_SampleInfo_t *i; // edi
  __m128 v6; // xmm2
  int v7; // ecx
  unsigned __int8 *pvs; // edx
  LightingValue_t **m_NormalCount; // ecx
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  unsigned int v12; // eax
  __m128 v13; // xmm0
  int LightstyleSamples; // eax
  int v15; // eax
  int v16; // edx
  int v17; // ecx
  int v18; // eax
  float *v19; // edx
  float *v20; // eax
  LightingValue_t **v21; // edi
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  float *v27; // eax
  float *v28; // edi
  float v29; // xmm0_4
  int v30; // [esp+2Ch] [ebp-E8h] BYREF
  __m128 fxdot[4]; // [esp+34h] [ebp-E0h] BYREF
  _BYTE out_52[60]; // [esp+A8h] [ebp-6Ch] OVERLAPPED
  LightingValue_t **pLightmaps; // [esp+E4h] [ebp-30h]
  int n; // [esp+E8h] [ebp-2Ch]
  char v35; // [esp+107h] [ebp-Dh]
  _DWORD v36[2]; // [esp+108h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+114h] [ebp+0h]

  v36[0] = a1;
  v36[1] = retaddr;
  v4 = activelights;
  for ( i = info; v4 != nullptr; v4 = v4->next )
  {
    v6 = Four_Zeros;
    v35 = 1;
    if ( numSamples > 0 )
    {
      n = (int)g_SIMD_ComponentMask;
      *(_DWORD *)&out_52[48] = i->m_Clusters;
      for ( pLightmaps = (LightingValue_t **)numSamples;
            pLightmaps != nullptr;
            pLightmaps = (LightingValue_t **)((char *)pLightmaps - 1) )
      {
        v7 = **(_DWORD **)&out_52[48];
        if ( (int)**(_DWORD **)&out_52[48] < 0
          || (pvs = v4->pvs, out_52[59] = 1 << (v7 & 7), i = info, (out_52[59] & pvs[v7 >> 3]) != 0) )
        {
          v6 = _mm_or_ps(
                 _mm_and_ps(_mm_shuffle_ps((__m128)0x3F800000u, (__m128)0x3F800000u, 0), *(__m128 *)n),
                 _mm_andnot_ps(*(__m128 *)n, v6));
          v35 = 0;
        }
        *(_DWORD *)&out_52[48] += 4;
        n += 16;
      }
      *(__m128 *)&out_52[32] = v6;
      if ( v35 == 0 )
      {
        GatherSampleLightSSE(
          out: (SSE_sampleLightOutput_t *)&fxdot[3].m128_i16[2],
          dl: v4,
          facenum: i->m_FaceNum,
          pos: &i->m_Points,
          pNormals: i->m_PointNormals,
          normalCount: i->m_NormalCount,
          iThread: i->m_iThread,
          nLFlags: 0,
          static_prop_index_to_ignore: -1,
          flEpsilon: 0.0);
        m_NormalCount = (LightingValue_t **)i->m_NormalCount;
        v35 = 1;
        if ( (int)m_NormalCount > 0 )
        {
          v10 = *(__m128 *)out_52;
          v11 = *(__m128 *)&out_52[32];
          v12 = 0;
          for ( pLightmaps = m_NormalCount; pLightmaps != nullptr; pLightmaps = (LightingValue_t **)((char *)pLightmaps - 1) )
          {
            v13 = _mm_mul_ps(_mm_mul_ps(*(__m128 *)((char *)&fxdot[v12 / 4 + 3] + 4), v11), v10);
            *(__m128 *)&v36[v12 - 56] = v13;
            if ( _mm_movemask_ps(_mm_cmpeq_ps(v13, Four_Zeros)) != 15 )
              v35 = 0;
            v12 += 4;
          }
          if ( v35 == 0 )
          {
            LightstyleSamples = FindOrAllocateLightstyleSamples(
                                  f: i->m_pFace,
                                  fl: i->m_pFaceLight,
                                  lightstyle: v4->light.style,
                                  numnormals: (int)m_NormalCount);
            if ( LightstyleSamples >= 0 )
            {
              *(_DWORD *)&out_52[48] = i->m_pFaceLight->light[LightstyleSamples];
              if ( g_pIncremental != nullptr && v4->light.style == 0 )
              {
                v15 = 0;
                for ( n = 0; ; v15 = n )
                {
                  ((void (__thiscall *)(IIncremental *, _DWORD, int, int, int, _DWORD, int))g_pIncremental->AddLightToFace)(
                    a1: g_pIncremental,
                    a2: v4->m_IncrementalID,
                    a3: i->m_FaceNum,
                    a4: sampleIdx + v15,
                    a5: i->m_LightmapSize,
                    a6: v36[v15 - 56],
                    a7: i->m_iThread);
                  if ( ++n >= numSamples )
                    break;
                }
              }
              v16 = 0;
              *(_DWORD *)&out_52[52] = 0;
              if ( i->m_NormalCount > 0 )
              {
                n = (int)&v30;
                do
                {
                  v17 = 0;
                  if ( numSamples >= 4 )
                  {
                    v18 = *(_DWORD *)(*(_DWORD *)&out_52[48] + 4 * v16);
                    pLightmaps = (LightingValue_t **)n;
                    v19 = (float *)(v18 + 16 * (sampleIdx + 2));
                    v20 = (float *)(v18 + 16 * sampleIdx + 24);
                    do
                    {
                      v21 = pLightmaps;
                      v22 = *((float *)pLightmaps - 1);
                      *(v19 - 8) = (float)(v4->light.intensity.x * v22) + *(v19 - 8);
                      *(v20 - 5) = (float)(v4->light.intensity.y * v22) + *(v20 - 5);
                      *(v20 - 4) = (float)(v22 * v4->light.intensity.z) + *(v20 - 4);
                      *(v20 - 3) = *(float *)&out_52[4 * v17 + 16] + *(v20 - 3);
                      v23 = *(float *)v21;
                      *(v20 - 2) = (float)(v4->light.intensity.x * *(float *)v21) + *(v20 - 2);
                      *(v20 - 1) = (float)(v4->light.intensity.y * v23) + *(v20 - 1);
                      *v20 = (float)(v23 * v4->light.intensity.z) + *v20;
                      v20[1] = *(float *)&out_52[4 * v17 + 20] + v20[1];
                      v24 = *((float *)v21 + 1);
                      *v19 = (float)(v4->light.intensity.x * v24) + *v19;
                      v20[3] = (float)(v4->light.intensity.y * v24) + v20[3];
                      v20[4] = (float)(v24 * v4->light.intensity.z) + v20[4];
                      v20[5] = *(float *)&out_52[4 * v17 + 24] + v20[5];
                      v25 = *((float *)v21 + 2);
                      v19[4] = (float)(v4->light.intensity.x * v25) + v19[4];
                      v20[7] = (float)(v4->light.intensity.y * v25) + v20[7];
                      v20[8] = (float)(v25 * v4->light.intensity.z) + v20[8];
                      v26 = *(float *)&out_52[4 * v17 + 28] + v20[9];
                      pLightmaps = v21 + 4;
                      v20[9] = v26;
                      v17 += 4;
                      v20 += 16;
                      v19 += 16;
                    }
                    while ( v17 < numSamples - 3 );
                    v16 = *(_DWORD *)&out_52[52];
                    i = info;
                  }
                  if ( v17 < numSamples )
                  {
                    *(_DWORD *)&out_52[52] = &v36[4 * v16 - 56 + v17];
                    v27 = (float *)(*(_DWORD *)(*(_DWORD *)&out_52[48] + 4 * v16) + 16 * (v17 + sampleIdx));
                    v28 = *(float **)&out_52[52];
                    do
                    {
                      v29 = *v28;
                      *v27 = (float)(v4->light.intensity.x * *v28) + *v27;
                      v27[1] = (float)(v4->light.intensity.y * v29) + v27[1];
                      v27[2] = (float)(v29 * v4->light.intensity.z) + v27[2];
                      v27[3] = *(float *)&out_52[4 * v17++ + 16] + v27[3];
                      v27 += 4;
                      ++v28;
                    }
                    while ( v17 < numSamples );
                    i = info;
                  }
                  n += 16;
                  *(_DWORD *)&out_52[52] = ++v16;
                }
                while ( v16 < i->m_NormalCount );
              }
            }
            else if ( i->m_WarnFace != i->m_FaceNum )
            {
              _Warning(
                a1: "\nWARNING: Too many light styles on a face at (%f, %f, %f)\n",
                i->m_Points.x.m128_f32[0],
                i->m_Points.y.m128_f32[0],
                i->m_Points.z.m128_f32[0]);
              i->m_WarnFace = i->m_FaceNum;
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CE10
// Name: ResampleLightAt4Points
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall ResampleLightAt4Points(LightingValue_t (*pLightmap)[4]@<eax>, int a2@<ebp>, int a3, int a4, char a5)
{
  int v5; // edi
  int v6; // ecx
  float *v7; // esi
  int v8; // edx
  float *v9; // eax
  directlight_t *v10; // esi
  int v11; // eax
  __m128 v12; // xmm2
  unsigned __int8 *pvs; // edi
  int v14; // edx
  bool v15; // zf
  __m128 v16; // xmm1
  int v17; // ecx
  __m128 v18; // xmm0
  __m128 v19; // xmm1
  unsigned int v20; // eax
  float *v21; // eax
  int v22; // ecx
  int v23; // edx
  float v24; // xmm1_4
  float *v25; // ecx
  float v26; // xmm0_4
  float v27; // xmm2_4
  float v28; // xmm0_4
  __m128 fxdot[4]; // [esp+20h] [ebp-F0h] BYREF
  _BYTE out_52[48]; // [esp+94h] [ebp-7Ch] OVERLAPPED
  float *p_z; // [esp+D0h] [ebp-40h]
  int j; // [esp+D8h] [ebp-38h]
  int *v33; // [esp+DCh] [ebp-34h]
  unsigned __int8 v34; // [esp+E3h] [ebp-2Dh]
  int i; // [esp+E4h] [ebp-2Ch]
  char v36; // [esp+103h] [ebp-Dh]
  _DWORD v37[2]; // [esp+104h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+110h] [ebp+0h]

  v37[0] = a2;
  v37[1] = retaddr;
  v5 = a3;
  v6 = *(_DWORD *)(a3 + 28);
  p_z = &(*pLightmap)[0].m_vecLighting.z;
  v7 = &(*pLightmap)[0].m_vecLighting.z;
  for ( i = 4; i != 0; --i )
  {
    v8 = 0;
    if ( v6 > 0 )
    {
      v9 = v7;
      do
      {
        *(v9 - 2) = 0.0;
        *(v9 - 1) = 0.0;
        *v9 = 0.0;
        v9[1] = 0.0;
        v6 = *(_DWORD *)(a3 + 28);
        ++v8;
        v9 += 4;
      }
      while ( v8 < v6 );
    }
    v7 += 16;
  }
  v10 = activelights;
  if ( activelights != nullptr )
  {
    v11 = a5 & 1;
    for ( j = v11; ; v11 = j )
    {
      if ( (v11 == 0 || v10->light.type == emit_skyambient)
        && ((a5 & 2) == 0 || v10->light.type != emit_skyambient)
        && v10->light.style == *(unsigned __int8 *)(*(_DWORD *)(v5 + 8) + a4 + 16) )
      {
        v12 = Four_Zeros;
        v36 = 1;
        i = (int)g_SIMD_ComponentMask;
        v33 = (int *)(v5 + 52);
        do
        {
          if ( *v33 < 0
            || (pvs = v10->pvs, v14 = *v33 >> 3, v34 = 1 << (*v33 & 7), v15 = (v34 & pvs[v14]) == 0, v5 = a3, !v15) )
          {
            v16 = 0;
            v16.m128_f32[0] = 1.0;
            v12 = _mm_or_ps(_mm_and_ps(_mm_shuffle_ps(v16, v16, 0), *(__m128 *)i), _mm_andnot_ps(*(__m128 *)i, v12));
            v36 = 0;
          }
          ++v33;
          i += 16;
        }
        while ( i < (int)g_SIMD_Identity );
        *(__m128 *)&out_52[32] = v12;
        if ( v36 == 0 )
        {
          GatherSampleLightSSE(
            out: (SSE_sampleLightOutput_t *)&fxdot[3].m128_i16[2],
            dl: v10,
            facenum: *(_DWORD *)v5,
            pos: (const FourVectors *)(v5 + 80),
            pNormals: (FourVectors *)(v5 + 128),
            normalCount: *(_DWORD *)(v5 + 28),
            iThread: *(_DWORD *)(v5 + 32),
            nLFlags: 0,
            static_prop_index_to_ignore: -1,
            flEpsilon: 0.0);
          v17 = *(_DWORD *)(v5 + 28);
          if ( v17 > 0 )
          {
            v18 = *(__m128 *)out_52;
            v19 = *(__m128 *)&out_52[32];
            v20 = 0;
            do
            {
              *(__m128 *)&v37[v20 / 4 - 60] = _mm_mul_ps(
                                                _mm_mul_ps(*(__m128 *)((char *)&fxdot[v20 / 0x10 + 3] + 4), v18),
                                                v19);
              v20 += 16;
              --v17;
            }
            while ( v17 != 0 );
          }
          v21 = p_z;
          v22 = 0;
          i = (int)p_z;
          v33 = nullptr;
          do
          {
            v23 = 0;
            if ( *(int *)(v5 + 28) > 0 )
            {
              v24 = *(float *)&out_52[v22 + 16];
              v25 = (float *)((char *)&v37[-60] + v22);
              do
              {
                v26 = *v25;
                *(v21 - 2) = (float)(v10->light.intensity.x * *v25) + *(v21 - 2);
                *(v21 - 1) = (float)(v10->light.intensity.y * v26) + *(v21 - 1);
                v27 = v10->light.intensity.z * v26;
                v28 = v21[1];
                *v21 = v27 + *v21;
                v21[1] = v28 + v24;
                ++v23;
                v21 += 4;
                v25 += 4;
              }
              while ( v23 < *(_DWORD *)(v5 + 28) );
              v22 = (int)v33;
            }
            v22 += 4;
            v21 = (float *)(i + 64);
            i += 64;
            v33 = (int *)v22;
          }
          while ( v22 < 16 );
        }
      }
      v10 = v10->next;
      if ( v10 == nullptr )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D060
// Name: bool PointsInWinding(class FourVectors const __near &,struct winding_t __near *,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl PointsInWinding(const FourVectors *point, winding_t *w, int *invalidBits)
{
  winding_t *v3; // ecx
  unsigned int *p; // eax
  __m128 v5; // xmm7
  __m128 v6; // xmm3
  __m128 v7; // xmm4
  __m128 v8; // xmm0
  __m128 v9; // xmm6
  __m128 v10; // xmm5
  __m128 v11; // xmm0
  __m128 v12; // xmm4
  __m128 v13; // xmm1
  __m128 v14; // xmm6
  __m128 v15; // xmm2
  __m128 v16; // xmm0
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  int numpoints; // edi
  int v20; // eax
  int i; // esi
  Vector *v22; // ecx
  __m128 v23; // xmm6
  __m128 v24; // xmm7
  int v25; // eax
  __m128 y_low; // xmm0
  __m128 v27; // xmm4
  __m128 z_low; // xmm0
  __m128 v29; // xmm3
  __m128 v30; // xmm2
  __m128 v31; // xmm0
  __m128 v32; // xmm5
  __m128 v33; // xmm6
  __m128 v34; // xmm1
  __m128 v35; // xmm4
  __m128 v36; // xmm1
  __m128 v37; // xmm5
  __m128 v38; // xmm2
  __m128 v39; // xmm3
  __m128 v40; // xmm1
  __m128 v41; // xmm4
  __m128 v42; // xmm0
  int v43; // eax
  __m128 v45; // [esp-Ch] [ebp-BCh]
  __m128 v46; // [esp-Ch] [ebp-BCh]
  __m128 p0_20; // [esp+44h] [ebp-6Ch]
  __m128 p0_20a; // [esp+44h] [ebp-6Ch]
  __m128 p0_36; // [esp+54h] [ebp-5Ch]
  __m128 invalidMask_4; // [esp+64h] [ebp-4Ch]
  __m128 testCross_4; // [esp+74h] [ebp-3Ch]
  __m128 testCross_20; // [esp+84h] [ebp-2Ch]
  int v53; // [esp+A0h] [ebp-10h]

  v3 = w;
  p = (unsigned int *)w->p;
  v5 = _mm_shuffle_ps((__m128)p[1], (__m128)p[1], 0);
  p0_20 = _mm_shuffle_ps((__m128)p[2], (__m128)p[2], 0);
  v6 = _mm_sub_ps(point->z, p0_20);
  v7 = _mm_sub_ps(_mm_shuffle_ps((__m128)p[4], (__m128)p[4], 0), v5);
  v8 = _mm_shuffle_ps((__m128)*p, (__m128)*p, 0);
  v9 = _mm_sub_ps(point->x, v8);
  v10 = _mm_sub_ps(_mm_shuffle_ps((__m128)p[3], (__m128)p[3], 0), v8);
  v11 = _mm_mul_ps(v7, v6);
  v45 = v9;
  v12 = _mm_mul_ps(v7, v9);
  v13 = _mm_sub_ps(point->y, v5);
  v14 = _mm_sub_ps(_mm_shuffle_ps((__m128)p[5], (__m128)p[5], 0), p0_20);
  v15 = _mm_sub_ps(_mm_mul_ps(v14, v45), _mm_mul_ps(v6, v10));
  v16 = _mm_sub_ps(v11, _mm_mul_ps(v14, v13));
  v17 = _mm_sub_ps(_mm_mul_ps(v13, v10), v12);
  v18 = _mm_rsqrt_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v16, v16), _mm_mul_ps(v15, v15)), _mm_mul_ps(v17, v17)));
  numpoints = w->numpoints;
  v20 = 1;
  invalidMask_4 = _mm_mul_ps(v18, v16);
  testCross_4 = _mm_mul_ps(v15, v18);
  testCross_20 = _mm_mul_ps(v17, v18);
  if ( w->numpoints <= 1 )
    return 1;
  for ( i = 1; ; ++i )
  {
    v53 = v20 + 1;
    v22 = v3->p;
    v23 = _mm_shuffle_ps((__m128)LODWORD(v22[i].x), (__m128)LODWORD(v22[i].x), 0);
    v24 = _mm_shuffle_ps((__m128)LODWORD(v22[i].y), (__m128)LODWORD(v22[i].y), 0);
    p0_20a = _mm_shuffle_ps((__m128)LODWORD(v22[i].z), (__m128)LODWORD(v22[i].z), 0);
    v25 = (v20 + 1) % numpoints;
    y_low = (__m128)LODWORD(v22[v25].y);
    v27 = _mm_shuffle_ps(y_low, y_low, 0);
    z_low = (__m128)LODWORD(v22[v25].z);
    v29 = _mm_sub_ps(point->z, p0_20a);
    v30 = _mm_sub_ps(_mm_shuffle_ps(z_low, z_low, 0), p0_20a);
    v31 = _mm_sub_ps(point->y, v24);
    v32 = _mm_sub_ps(point->x, v23);
    v33 = _mm_sub_ps(_mm_shuffle_ps((__m128)LODWORD(v22[v25].x), (__m128)LODWORD(v22[v25].x), 0), v23);
    v34 = _mm_sub_ps(v27, v24);
    v46 = v32;
    v35 = _mm_mul_ps(v34, v32);
    v36 = _mm_mul_ps(v34, v29);
    v37 = v30;
    v38 = _mm_sub_ps(_mm_mul_ps(v30, v46), _mm_mul_ps(v29, v33));
    v39 = _mm_sub_ps(_mm_mul_ps(v31, v33), v35);
    v40 = _mm_sub_ps(v36, _mm_mul_ps(v37, v31));
    v41 = _mm_rsqrt_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v40, v40), _mm_mul_ps(v38, v38)), _mm_mul_ps(v39, v39)));
    v42 = _mm_or_ps(
            _mm_cmplt_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_mul_ps(v41, v40), invalidMask_4),
                  _mm_mul_ps(_mm_mul_ps(v38, v41), testCross_4)),
                _mm_mul_ps(_mm_mul_ps(v39, v41), testCross_20)),
              Four_Zeros),
            p0_36);
    v43 = _mm_movemask_ps(v42);
    p0_36 = v42;
    *invalidBits = v43;
    if ( v43 == 15 )
      break;
    v3 = w;
    v20 = v53;
    numpoints = w->numpoints;
    if ( v53 >= w->numpoints )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000D2A0
// Name: ComputeLightmapGradients
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeLightmapGradients(SSE_SampleInfo_t *info, const bool *pHasProcessedSample, float *gradient)
{
  float *pIntensity; // ecx
  facelight_t *m_pFaceLight; // esi
  int m_LightmapWidth; // edi
  int v6; // eax
  sample_t *v8; // esi
  int v9; // ebx
  int t; // esi
  int s; // edi
  int v12; // eax
  bool v13; // cc
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  int h; // [esp+8h] [ebp-20h]
  int v25; // [esp+Ch] [ebp-1Ch]
  int i; // [esp+10h] [ebp-18h]
  facelight_t *fl; // [esp+14h] [ebp-14h]
  int n; // [esp+18h] [ebp-10h]
  int v29; // [esp+1Ch] [ebp-Ch]
  int w; // [esp+20h] [ebp-8h]
  sample_t *sample; // [esp+24h] [ebp-4h]

  m_pFaceLight = info->m_pFaceLight;
  m_LightmapWidth = info->m_LightmapWidth;
  v6 = 0;
  w = m_LightmapWidth;
  h = info->m_LightmapHeight;
  fl = m_pFaceLight;
  i = 0;
  if ( m_pFaceLight->numsamples > 0 )
  {
    v29 = 0;
    do
    {
      if ( !pHasProcessedSample[v6] )
      {
        *gradient = 0.0;
        v8 = &m_pFaceLight->sample[v29];
        v9 = 0;
        sample = v8;
        for ( n = 0; v9 < info->m_NormalCount; n = v9 )
        {
          t = v8->t;
          v25 = m_LightmapWidth * t;
          s = sample->s;
          v12 = s + v25 + v9 * info->m_LightmapSize;
          if ( t <= 0 )
          {
            v8 = sample;
            m_LightmapWidth = w;
          }
          else
          {
            v13 = s <= 0;
            m_LightmapWidth = w;
            if ( !v13 )
            {
              v14 = fabs(pIntensity[v12] - pIntensity[v12 - w - 1]);
              if ( *gradient > v14 )
                v14 = *gradient;
              *gradient = v14;
            }
            v15 = *gradient;
            v16 = fabs(pIntensity[v12] - pIntensity[v12 - w]);
            if ( *gradient <= v16 )
              v15 = v16;
            v8 = sample;
            *gradient = v15;
            if ( sample->s < w - 1 )
            {
              v17 = fabs(pIntensity[v12] - pIntensity[v12 - w + 1]);
              if ( v15 > v17 )
                v17 = v15;
              *gradient = v17;
            }
          }
          if ( v8->t < h - 1 )
          {
            if ( v8->s > 0 )
            {
              v18 = fabs(pIntensity[v12] - pIntensity[v12 - 1 + m_LightmapWidth]);
              if ( *gradient > v18 )
                v18 = *gradient;
              *gradient = v18;
            }
            v19 = *gradient;
            v20 = fabs(pIntensity[v12] - pIntensity[v12 + m_LightmapWidth]);
            if ( *gradient <= v20 )
              v19 = v20;
            *gradient = v19;
            if ( v8->s < m_LightmapWidth - 1 )
            {
              v21 = fabs(pIntensity[v12] - pIntensity[v12 + 1 + m_LightmapWidth]);
              if ( v19 > v21 )
                v21 = v19;
              *gradient = v21;
            }
          }
          if ( v8->s > 0 )
          {
            v22 = fabs(pIntensity[v12] - pIntensity[v12 - 1]);
            if ( *gradient > v22 )
              v22 = *gradient;
            *gradient = v22;
          }
          if ( v8->s < m_LightmapWidth - 1 )
          {
            v23 = fabs(pIntensity[v12] - pIntensity[v12 + 1]);
            if ( *gradient > v23 )
              v23 = *gradient;
            *gradient = v23;
          }
          v9 = n + 1;
        }
        m_pFaceLight = fl;
      }
      ++v29;
      v6 = i + 1;
      ++gradient;
      i = v6;
    }
    while ( v6 < m_pFaceLight->numsamples );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D4B0
// Name: ComputeSampleIntensities
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeSampleIntensities(
        double a1@<esi:edi>,
        SSE_SampleInfo_t *info,
        LightingValue_t **ppLightSamples,
        float *pSampleIntensity)
{
  facelight_t *m_pFaceLight; // ecx
  int v6; // edx
  int m_NormalCount; // eax
  int v8; // esi
  int v9; // edi
  int v10; // ecx
  float v11; // xmm0_4
  long double v12; // [esp-8h] [ebp-14h]
  long double v13; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]
  SSE_SampleInfo_t *infoa; // [esp+14h] [ebp+8h]

  m_pFaceLight = info->m_pFaceLight;
  v6 = 0;
  i = 0;
  if ( m_pFaceLight->numsamples > 0 )
  {
    m_NormalCount = info->m_NormalCount;
    v12 = a1;
    infoa = nullptr;
    do
    {
      v8 = 0;
      v9 = *(int *)((char *)&infoa->m_WarnFace + (unsigned int)m_pFaceLight->sample)
         + info->m_LightmapWidth * *(int *)((char *)&infoa->m_pFace + (unsigned int)m_pFaceLight->sample);
      if ( m_NormalCount > 0 )
      {
        v10 = 16 * v6;
        for ( HIDWORD(v13) = 16 * v6; ; v10 = HIDWORD(v13) )
        {
          v11 = (float)((float)(*(float *)((char *)&ppLightSamples[v8]->m_vecLighting.y + v10)
                              + *(float *)((char *)&ppLightSamples[v8]->m_vecLighting.x + v10))
                      + *(float *)((char *)&ppLightSamples[v8]->m_vecLighting.z + v10))
              * 0.00390625;
          __libm_sse2_pow(x: v12, y: v13);
          pSampleIntensity[v9 + v8 * info->m_LightmapSize] = v11;
          m_NormalCount = info->m_NormalCount;
          if ( ++v8 >= m_NormalCount )
            break;
        }
        v6 = i;
      }
      m_pFaceLight = info->m_pFaceLight;
      infoa = (SSE_SampleInfo_t *)((char *)infoa + 64);
      i = ++v6;
    }
    while ( v6 < m_pFaceLight->numsamples );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D560
// Name: void ConvertRGBExp32ToRGBA8888(struct ColorRGBExp32 const __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConvertRGBExp32ToRGBA8888(const ColorRGBExp32 *pSrc, unsigned __int8 *pDst)
{
  float v2; // xmm3_4
  float v3; // xmm1_4
  float v4; // xmm2_4
  int v5; // eax
  float v6; // xmm3_4
  int v7; // eax
  float v8; // xmm0_4
  int v9; // eax
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm4_4

  v2 = dword_10135B00[pSrc->exponent];
  v3 = (float)pSrc->g * v2;
  v4 = (float)pSrc->b * v2;
  v5 = (int)(float)((float)((float)pSrc->r * v2) * 1024.0);
  if ( (unsigned int)v5 > 0xFFF )
    v5 = v5 < 0 ? 0 : 0xFFF;
  v6 = lineartovertex[v5];
  v7 = (int)(float)(v3 * 1024.0);
  if ( (unsigned int)v7 > 0xFFF )
    v7 = v7 < 0 ? 0 : 0xFFF;
  v8 = lineartovertex[v7];
  v9 = (int)(float)(v4 * 1024.0);
  if ( (unsigned int)v9 > 0xFFF )
    v9 = v9 < 0 ? 0 : 0xFFF;
  v10 = lineartovertex[v9];
  if ( v8 <= v10 )
    v11 = lineartovertex[v9];
  else
    v11 = v8;
  if ( v6 <= v11 )
  {
    if ( v8 <= v10 )
      v12 = lineartovertex[v9];
    else
      v12 = v8;
  }
  else
  {
    v12 = v6;
  }
  if ( v12 > 1.0 )
  {
    v6 = v6 * (float)(1.0 / v12);
    v8 = v8 * (float)(1.0 / v12);
    v10 = v10 * (float)(1.0 / v12);
  }
  if ( v6 < 0.0 )
    v6 = 0.0;
  if ( v8 < 0.0 )
    v8 = 0.0;
  if ( v10 < 0.0 )
    v10 = 0.0;
  *pDst = (int)(float)(v6 * 255.0);
  pDst[1] = (int)(float)(v8 * 255.0);
  pDst[2] = (int)(float)(v10 * 255.0);
  pDst[3] = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1000D6F0
// Name: void MergeDLightVis(struct directlight_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MergeDLightVis(directlight_t *dl, int cluster)
{
  unsigned __int8 *v2; // eax
  int i; // ecx
  unsigned __int8 pvs[8192]; // [esp+4h] [ebp-2000h] BYREF

  if ( dl->pvs != nullptr )
  {
    GetVisCache(lastoffset: -1, cluster, pvs);
    for ( i = 0; i < dvis->numclusters / 8 + 1; ++i )
      dl->pvs[i] |= pvs[i];
  }
  else
  {
    v2 = (unsigned __int8 *)calloc(count: 1u, size: dvis->numclusters / 8 + 1);
    dl->pvs = v2;
    GetVisCache(lastoffset: -1, cluster, pvs: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D7A0
// Name: ParseLightGeneric
// Source: json
//------------------------------------------------------------------------------
void __usercall ParseLightGeneric(long double e@<esi:edi>)
{
  char *v1; // eax
  float *v2; // ebx
  char *v3; // eax
  char *v4; // eax
  entity_t *TargetEntity; // eax
  double v6; // st7
  QAngle v7; // [esp+10h] [ebp-38h] BYREF
  Vector angles; // [esp+1Ch] [ebp-2Ch] BYREF
  Vector dest; // [esp+28h] [ebp-20h] BYREF
  Vector shadowOffset; // [esp+34h] [ebp-14h] BYREF
  float angle; // [esp+40h] [ebp-8h]
  float pitch; // [esp+44h] [ebp-4h]

  *(_DWORD *)(HIDWORD(e) + 64) = (int)FloatForKey(ent: (entity_t *)LODWORD(e), key: "style");
  *(_BYTE *)(HIDWORD(e) + 160) = 0;
  if ( (int)FloatForKeyWithDefault(ent: (entity_t *)LODWORD(e), key: "_castentityshadow", default_value: 1.0) != 0 )
    *(_DWORD *)(HIDWORD(e) + 96) |= 2u;
  else
    *(_DWORD *)(HIDWORD(e) + 96) &= ~2u;
  memset(&shadowOffset, 0, sizeof(shadowOffset));
  GetVectorForKey(ent: (entity_t *)LODWORD(e), key: "_shadoworiginoffset", angle: (QAngle *)&shadowOffset);
  *(Vector *)(HIDWORD(e) + 44) = shadowOffset;
  if ( !g_bHDR
    || (v1 = ValueForKey(ent: (entity_t *)LODWORD(e), key: "_lightHDR"),
        v2 = (float *)(HIDWORD(e) + 20),
        LightForString(a1: e, pLight: v1, intensity: (Vector *)(HIDWORD(e) + 20)) == 0) )
  {
    v3 = ValueForKey(ent: (entity_t *)LODWORD(e), key: "_light");
    v2 = (float *)(HIDWORD(e) + 20);
    LightForString(a1: e, pLight: v3, intensity: (Vector *)(HIDWORD(e) + 20));
  }
  v4 = ValueForKey(ent: (entity_t *)LODWORD(e), key: "target");
  if ( *v4 != 0 )
  {
    TargetEntity = FindTargetEntity(target: v4);
    if ( TargetEntity != nullptr )
    {
      GetVectorForKey(ent: TargetEntity, key: "origin", angle: (QAngle *)&dest);
      *(float *)(HIDWORD(e) + 32) = dest.x - *(float *)(HIDWORD(e) + 8);
      *(float *)(HIDWORD(e) + 36) = dest.y - *(float *)(HIDWORD(e) + 12);
      *(float *)(HIDWORD(e) + 40) = dest.z - *(float *)(HIDWORD(e) + 16);
      VectorNormalize(vec: (Vector *)(HIDWORD(e) + 32));
    }
    else
    {
      _Warning(
        a1: "WARNING: light at (%i %i %i) has missing target\n",
        (int)*(float *)(HIDWORD(e) + 8),
        (int)*(float *)(HIDWORD(e) + 12),
        (int)*(float *)(HIDWORD(e) + 16));
    }
  }
  else
  {
    GetVectorForKey(ent: (entity_t *)LODWORD(e), key: "angles", angle: (QAngle *)&angles);
    pitch = FloatForKey(ent: (entity_t *)LODWORD(e), key: "pitch");
    angle = FloatForKey(ent: (entity_t *)LODWORD(e), key: "angle");
    v7 = (QAngle)angles;
    SetupLightNormalFromProps(angles: &v7, angle, pitch, output: (Vector *)(HIDWORD(e) + 32));
  }
  if ( g_bHDR )
  {
    v6 = FloatForKeyWithDefault(ent: (entity_t *)LODWORD(e), key: "_lightscaleHDR", default_value: 1.0);
    *v2 = *v2 * v6;
    v2[1] = v6 * v2[1];
    v2[2] = v6 * v2[2];
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D9B0
// Name: SupersampleLightAtPoint
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __usercall SupersampleLightAtPoint@<eax>(
        SSE_SampleInfo_t *info@<esi>,
        int sampleIndex@<eax>,
        int a3@<ebp>,
        const lightinfo_t *a4,
        int a5,
        int a6,
        char a7)
{
  sample_t *v7; // edi
  int v8; // ecx
  int v9; // eax
  float v10; // xmm2_4
  float v11; // xmm1_4
  _DWORD *v12; // eax
  __m128 v13; // xmm0
  winding_t *w; // eax
  float *v15; // edx
  int v16; // edi
  int v17; // ecx
  float *v18; // eax
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  winding_t *v22; // edi
  float *v23; // edx
  int v24; // edi
  int v25; // ecx
  float *v26; // eax
  _BYTE v27[305]; // [esp-Ch] [ebp-1CCh] OVERLAPPED BYREF
  __m128 superSamplePosition_36; // [esp+154h] [ebp-6Ch] OVERLAPPED
  _BYTE v29[32]; // [esp+164h] [ebp-5Ch] OVERLAPPED
  sample_t *v30; // [esp+188h] [ebp-38h]
  Vector2D v31; // [esp+18Ch] [ebp-34h] BYREF
  _BYTE sample[28]; // [esp+194h] [ebp-2Ch] OVERLAPPED BYREF
  int s; // [esp+1B0h] [ebp-10h]
  int invalidBits; // [esp+1B4h] [ebp-Ch] BYREF
  void *v35; // [esp+1B8h] [ebp-8h]
  void *retaddr; // [esp+1C0h] [ebp+0h]

  invalidBits = a3;
  v35 = retaddr;
  v30 = &info->m_pFaceLight->sample[sampleIndex];
  v7 = v30;
  WorldToLuxelSpace(l: a4, world: &v30->pos, coord: &v31);
  v8 = 0;
  v9 = 2 * ((a7 & 2) != 0) + 2;
  v10 = 1.0 / (float)v9;
  v11 = (float)((float)((float)v9 - 1.0) * v10) * -0.5;
  if ( info->m_NormalCount > 0 )
  {
    v12 = (_DWORD *)(a6 + 8);
    do
    {
      *(v12 - 2) = 0;
      *(v12 - 1) = 0;
      *v12 = 0;
      v12[1] = 0;
      ++v8;
      v12 += 4;
    }
    while ( v8 < info->m_NormalCount );
  }
  *(__m128 *)&v27[256] = _mm_shuffle_ps((__m128)LODWORD(v7->normal.x), (__m128)LODWORD(v7->normal.x), 0);
  *(__m128 *)&v27[272] = _mm_shuffle_ps((__m128)LODWORD(v7->normal.y), (__m128)LODWORD(v7->normal.y), 0);
  v13 = _mm_shuffle_ps((__m128)LODWORD(v7->normal.z), (__m128)LODWORD(v7->normal.z), 0);
  s = 0;
  *(__m128 *)&v27[288] = v13;
  if ( (a7 & 2) != 0 )
  {
    *(float *)sample = (float)(v10 * 0.0) + v11;
    *(float *)&sample[4] = v11 + v10;
    *(float *)&sample[8] = (float)(v10 * 2.0) + v11;
    *(float *)&sample[12] = (float)(v10 * 3.0) + v11;
    *(_OWORD *)v29 = *(_OWORD *)sample;
    superSamplePosition_36 = _mm_shuffle_ps((__m128)LODWORD(v31.x), (__m128)LODWORD(v31.x), 0);
    *(_DWORD *)&sample[16] = 0;
    *(__m128 *)&v29[16] = _mm_shuffle_ps((__m128)LODWORD(v31.y), (__m128)LODWORD(v31.y), 0);
    do
    {
      LuxelSpaceToWorld(
        s: _mm_add_ps(
          _mm_shuffle_ps(
            (__m128)*(unsigned int *)&sample[4 * *(_DWORD *)&sample[16]],
            (__m128)*(unsigned int *)&sample[4 * *(_DWORD *)&sample[16]],
            0),
          superSamplePosition_36),
        t: _mm_add_ps(*(__m128 *)&v29[16], *(__m128 *)v29));
      w = v7->w;
      *(_DWORD *)&sample[20] = 0;
      if ( w == nullptr
        || PointsInWinding(point: (const FourVectors *)&v27[304], w, invalidBits: (int *)&sample[20]) != 0 )
      {
        ComputeIlluminationPointAndNormalsSSE(
          pos: (const FourVectors *)&v27[304],
          pInfo: info,
          a3: (int)&invalidBits,
          (int)a4,
          a5: (FourVectors *)&v27[256]);
        ResampleLightAt4Points(
          pLightmap: (LightingValue_t (*)[4])v27,
          a2: (int)&invalidBits,
          a3: (int)info,
          a4: a5,
          a5: 2);
        v15 = (float *)&v27[8];
        v16 = 0;
        *(_DWORD *)&sample[24] = &v27[8];
        do
        {
          if ( ((*(int *)&sample[20] >> v16) & 1) == 0 )
          {
            v17 = 0;
            if ( info->m_NormalCount > 0 )
            {
              v18 = (float *)(a6 + 8);
              do
              {
                *(v18 - 2) = *(v15 - 2) + *(v18 - 2);
                *(v18 - 1) = *(v15 - 1) + *(v18 - 1);
                *v18 = *v18 + *v15;
                v18[1] = v15[1] + v18[1];
                ++v17;
                v15 += 4;
                v18 += 4;
              }
              while ( v17 < info->m_NormalCount );
            }
            ++s;
          }
          ++v16;
          v15 = (float *)(*(_DWORD *)&sample[24] + 64);
          *(_DWORD *)&sample[24] += 64;
        }
        while ( v16 < 4 );
        v7 = v30;
      }
      ++*(_DWORD *)&sample[16];
    }
    while ( *(int *)&sample[16] < 4 );
    return s;
  }
  else
  {
    superSamplePosition_36.m128_f32[0] = v11 + v10;
    superSamplePosition_36.m128_f32[1] = v11 + v10;
    *(float *)&v29[4] = v11 + v10;
    *(float *)&v29[16] = v11 + v10;
    *(_QWORD *)&v29[20] = LODWORD(v11);
    *(float *)v29 = v11;
    *(_DWORD *)&v29[8] = 0;
    *(float *)sample = v11;
    *(float *)&sample[4] = v11;
    *(_DWORD *)&sample[8] = 0;
    v20 = _mm_shuffle_ps(*(__m128 *)sample, *(__m128 *)v29, 68);
    superSamplePosition_36.m128_i32[2] = 0;
    v21 = _mm_shuffle_ps(*(__m128 *)&v29[16], superSamplePosition_36, 68);
    LuxelSpaceToWorld(
      s: _mm_add_ps(_mm_shuffle_ps(v20, v21, 136), _mm_shuffle_ps((__m128)LODWORD(v31.x), (__m128)LODWORD(v31.x), 0)),
      t: _mm_add_ps(_mm_shuffle_ps(v20, v21, 221), _mm_shuffle_ps((__m128)LODWORD(v31.y), (__m128)LODWORD(v31.y), 0)));
    v22 = v7->w;
    *(_DWORD *)&sample[24] = 0;
    if ( v22 == nullptr
      || PointsInWinding(point: (const FourVectors *)&v27[304], w: v22, invalidBits: (int *)&sample[24]) != 0 )
    {
      ComputeIlluminationPointAndNormalsSSE(
        pos: (const FourVectors *)&v27[304],
        pInfo: info,
        a3: (int)&invalidBits,
        (int)a4,
        a5: (FourVectors *)&v27[256]);
      ResampleLightAt4Points(
        pLightmap: (LightingValue_t (*)[4])v27,
        a2: (int)&invalidBits,
        a3: (int)info,
        a4: a5,
        a5: 1);
      v23 = (float *)&v27[8];
      v24 = 0;
      *(_DWORD *)&sample[20] = &v27[8];
      do
      {
        if ( ((*(int *)&sample[24] >> v24) & 1) == 0 )
        {
          v25 = 0;
          if ( info->m_NormalCount > 0 )
          {
            v26 = (float *)(a6 + 8);
            do
            {
              *(v26 - 2) = *(v23 - 2) + *(v26 - 2);
              *(v26 - 1) = *(v23 - 1) + *(v26 - 1);
              *v26 = *v23 + *v26;
              v26[1] = v23[1] + v26[1];
              ++v25;
              v23 += 4;
              v26 += 4;
            }
            while ( v25 < info->m_NormalCount );
          }
          ++s;
        }
        ++v24;
        v23 = (float *)(*(_DWORD *)&sample[20] + 64);
        *(_DWORD *)&sample[20] += 64;
      }
      while ( v24 < 4 );
      return s;
    }
    else
    {
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DDB0
// Name: BuildSupersampleFaceLights
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildSupersampleFaceLights(SSE_SampleInfo_t *info@<eax>, lightinfo_t *l, int lightstyleIndex)
{
  void *v3; // esp
  const bool *v4; // ebx
  void *v5; // esp
  unsigned int v6; // eax
  void *v7; // esp
  double v8; // rdi
  _DWORD *v9; // edx
  void *v10; // esp
  int v11; // edi
  int *v12; // ecx
  int v13; // ebx
  float *v14; // eax
  int v15; // eax
  int v16; // edx
  float v17; // xmm2_4
  float v18; // xmm3_4
  unsigned int v19; // ecx
  int v20; // eax
  float *v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm6_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm4_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  int v29; // eax
  int v30; // ebx
  float v31; // xmm0_4
  int v32; // eax
  int *v33; // edx
  int v34; // ebx
  int v35; // eax
  float *v36; // ecx
  int i; // edx
  int v38; // eax
  unsigned int v39; // [esp-4h] [ebp-BCh]
  long double v40; // [esp+0h] [ebp-B8h] BYREF
  long double v41[8]; // [esp+8h] [ebp-B0h] BYREF
  float *v42[16]; // [esp+4Ch] [ebp-6Ch] BYREF
  float *gradient; // [esp+8Ch] [ebp-2Ch]
  float *pIntensity; // [esp+90h] [ebp-28h]
  long double *v45; // [esp+94h] [ebp-24h]
  float *v46; // [esp+98h] [ebp-20h]
  int v47; // [esp+9Ch] [ebp-1Ch]
  int v48; // [esp+A0h] [ebp-18h]
  int v49; // [esp+A4h] [ebp-14h]
  int v50; // [esp+A8h] [ebp-10h]
  long double *v51; // [esp+ACh] [ebp-Ch]
  int v52; // [esp+B0h] [ebp-8h]
  char v53; // [esp+B7h] [ebp-1h]
  int savedregs; // [esp+B8h] [ebp+0h] BYREF

  HIDWORD(v8) = info;
  LODWORD(v8) = info->m_LightmapSize;
  v3 = alloca(SLODWORD(v8));
  v4 = (const bool *)&v40;
  v45 = &v40;
  memset(dst: (unsigned __int8 *)&v40, value: 0, count: LODWORD(v8));
  LODWORD(v8) = *(_DWORD *)(HIDWORD(v8) + 12);
  v5 = alloca(4 * *(_DWORD *)LODWORD(v8));
  v6 = (4 * *(_DWORD *)(HIDWORD(v8) + 24) * *(_DWORD *)(HIDWORD(v8) + 28) + 15) & 0xFFFFFFF0;
  gradient = (float *)&v40;
  v7 = alloca(v6);
  LODWORD(v8) += 16 * lightstyleIndex + 8;
  pIntensity = (float *)&v40;
  v50 = LODWORD(v8);
  ComputeSampleIntensities(
    a1: v8,
    info: (SSE_SampleInfo_t *)HIDWORD(v8),
    ppLightSamples: (LightingValue_t **)LODWORD(v8),
    pSampleIntensity: (float *)&v40);
  v51 = nullptr;
  if ( debug_extra )
  {
    v9 = *(_DWORD **)(HIDWORD(v8) + 12);
    v10 = alloca(12 * *v9);
    v39 = 12 * *v9;
    v51 = &v40;
    memset(dst: (unsigned __int8 *)&v40, value: 0, count: v39);
  }
  v11 = 1;
  v49 = 1;
  while ( v11 <= extrapasses )
  {
    ComputeLightmapGradients(info: (SSE_SampleInfo_t *)HIDWORD(v8), pHasProcessedSample: v4, gradient);
    v12 = *(int **)(HIDWORD(v8) + 12);
    v13 = 0;
    v53 = 0;
    v48 = 0;
    if ( *v12 > 0 )
    {
      v52 = 0;
      v47 = 0;
      v14 = (float *)(v51 + 1);
      v46 = (float *)(v51 + 1);
      do
      {
        if ( *((_BYTE *)v45 + v13) == 0 && gradient[v13] >= 0.0625 )
        {
          *((_BYTE *)v45 + v13) = 1;
          v53 = 1;
          if ( debug_extra )
          {
            *(v14 - 2) = (float)(255 * (v11 & 1));
            *(v14 - 1) = (float)((unsigned __int8)(v11 & 2) << 7);
            *v14 = (float)((unsigned __int8)(v11 & 4) << 6);
          }
          LODWORD(v8) = SupersampleLightAtPoint(
                          info: (SSE_SampleInfo_t *)HIDWORD(v8),
                          sampleIndex: v13,
                          a3: (int)&savedregs,
                          a4: l,
                          a5: lightstyleIndex,
                          a6: (int)v41 + 4,
                          a7: 1);
          v15 = SupersampleLightAtPoint(
                  info: (SSE_SampleInfo_t *)HIDWORD(v8),
                  sampleIndex: v13,
                  a3: (int)&savedregs,
                  a4: l,
                  a5: lightstyleIndex,
                  a6: (int)v42,
                  a7: 2);
          if ( SLODWORD(v8) > 0 && v15 > 0 )
          {
            v16 = 0;
            if ( *(int *)(HIDWORD(v8) + 28) > 0 )
            {
              v17 = 1.0 / (float)v15;
              v18 = 1.0 / (float)SLODWORD(v8);
              v19 = 0;
              do
              {
                v20 = v52 + *(_DWORD *)(v50 + 4 * v16);
                v21 = v42[v19 / 4 + 1];
                v22 = *(float *)&v42[v19 / 4] * v17;
                *(_DWORD *)(v20 + 4) = 0;
                *(_DWORD *)(v20 + 8) = 0;
                *(_DWORD *)(v20 + 12) = 0;
                v23 = v22 + 0.0;
                v24 = (float)(*(float *)&v21 * v17) + 0.0;
                v25 = *((float *)&v41[v19 / 8 + 1] + 1);
                *(float *)(v20 + 4) = v24;
                v26 = *((float *)&v41[v19 / 8] + 1);
                *(float *)(v20 + 8) = *(float *)(v20 + 8) + (float)(v17 * *(float *)&v42[v19 / 4 + 2]);
                *(float *)(v20 + 12) = (float)(*(float *)&v42[v19 / 4 + 3] * v17) + *(float *)(v20 + 12);
                *(float *)(v20 + 4) = (float)(*(float *)&v41[v19 / 8 + 1] * v18) + *(float *)(v20 + 4);
                v27 = (float)(v25 * v18) + *(float *)(v20 + 8);
                v28 = (float)(*(float *)&v41[v19 / 8 + 2] * v18) + *(float *)(v20 + 12);
                ++v16;
                *(float *)v20 = v23 + (float)(v26 * v18);
                *(float *)(v20 + 8) = v27;
                *(float *)(v20 + 12) = v28;
                v19 += 16;
              }
              while ( v16 < *(_DWORD *)(HIDWORD(v8) + 28) );
            }
            v29 = v47 + *(_DWORD *)(*(_DWORD *)(HIDWORD(v8) + 12) + 4);
            LODWORD(v8) = 0;
            v30 = *(_DWORD *)(v29 + 4) + *(_DWORD *)(HIDWORD(v8) + 16) * *(_DWORD *)(v29 + 8);
            if ( *(int *)(HIDWORD(v8) + 28) > 0 )
            {
              do
              {
                v31 = (float)((float)(*(float *)(v52 + *(_DWORD *)(v50 + 4 * LODWORD(v8)) + 4)
                                    + *(float *)(v52 + *(_DWORD *)(v50 + 4 * LODWORD(v8))))
                            + *(float *)(v52 + *(_DWORD *)(v50 + 4 * LODWORD(v8)) + 8))
                    * 0.00390625;
                __libm_sse2_pow(x: v40, y: v41[0]);
                v32 = v30 + LODWORD(v8) * *(_DWORD *)(HIDWORD(v8) + 24);
                ++LODWORD(v8);
                pIntensity[v32] = v31;
              }
              while ( SLODWORD(v8) < *(_DWORD *)(HIDWORD(v8) + 28) );
            }
            v13 = v48;
          }
          v14 = v46;
          v11 = v49;
        }
        v33 = *(int **)(HIDWORD(v8) + 12);
        v47 += 64;
        v52 += 16;
        ++v13;
        v14 += 3;
        v48 = v13;
        v46 = v14;
      }
      while ( v13 < *v33 );
    }
    v49 = ++v11;
    if ( v53 == 0 )
      break;
    v4 = (const bool *)v45;
  }
  if ( debug_extra )
  {
    v34 = 0;
    if ( **(int **)(HIDWORD(v8) + 12) > 0 )
    {
      v35 = *(_DWORD *)(HIDWORD(v8) + 28);
      v36 = (float *)(v51 + 1);
      do
      {
        for ( i = 0; i < v35; v35 = *(_DWORD *)(HIDWORD(v8) + 28) )
        {
          v38 = *(_DWORD *)(v50 + 4 * i);
          *(float *)(v38 + 16 * v34) = *(v36 - 2);
          ++i;
          *(float *)(v38 + 16 * v34 + 4) = *(v36 - 1);
          *(float *)(v38 + 16 * v34 + 8) = *v36;
        }
        ++v34;
        v36 += 3;
      }
      while ( v34 < **(_DWORD **)(HIDWORD(v8) + 12) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E170
// Name: void CalcFaceVectors(struct lightinfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalcFaceVectors(lightinfo_t *l)
{
  texinfo_s *v2; // eax
  float v3; // xmm2_4
  float v4; // xmm3_4
  float v5; // xmm6_4
  float v6; // xmm1_4
  float z; // xmm4_4
  float y; // xmm5_4
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm3_4
  float v12; // xmm1_4
  float x; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm6_4
  float v16; // xmm4_4
  float v17; // xmm6_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  float luxelSpaceCross_4; // [esp+8h] [ebp-8h]
  float luxelSpaceCross_8; // [esp+Ch] [ebp-4h]
  lightinfo_t *la; // [esp+18h] [ebp+8h]

  v2 = &texinfo.m_Memory.m_pMemory[l->face->texinfo];
  l->worldToLuxelSpace[0] = *(Vector *)&v2->lightmapVecsLuxelsPerWorldUnits[0][0];
  l->worldToLuxelSpace[1] = *(Vector *)&v2->lightmapVecsLuxelsPerWorldUnits[1][0];
  v3 = (float)(v2->lightmapVecsLuxelsPerWorldUnits[0][2] * v2->lightmapVecsLuxelsPerWorldUnits[1][1])
     - (float)(v2->lightmapVecsLuxelsPerWorldUnits[0][1] * v2->lightmapVecsLuxelsPerWorldUnits[1][2]);
  v4 = v2->lightmapVecsLuxelsPerWorldUnits[0][0];
  v5 = v2->lightmapVecsLuxelsPerWorldUnits[1][0];
  luxelSpaceCross_4 = (float)(v4 * v2->lightmapVecsLuxelsPerWorldUnits[1][2])
                    - (float)(v5 * v2->lightmapVecsLuxelsPerWorldUnits[0][2]);
  luxelSpaceCross_8 = (float)(v5 * v2->lightmapVecsLuxelsPerWorldUnits[0][1])
                    - (float)(v4 * v2->lightmapVecsLuxelsPerWorldUnits[1][1]);
  LODWORD(v6) = COERCE_UNSIGNED_INT(
                  (float)((float)(l->facenormal.y * luxelSpaceCross_4) + (float)(v3 * l->facenormal.x))
                + (float)(l->facenormal.z * luxelSpaceCross_8))
              ^ _mask__NegFloat_;
  if ( COERCE_FLOAT(LODWORD(v6) & _mask__AbsFloat_) >= 9.999999999999999e-21 )
  {
    z = l->facenormal.z;
    y = l->facenormal.y;
    v9 = 1.0 / v6;
    v10 = l->worldToLuxelSpace[0].z;
    l->luxelToWorldSpace[0].x = (float)((float)(z * l->worldToLuxelSpace[1].y) - (float)(y * l->worldToLuxelSpace[1].z))
                              * (float)(1.0 / v6);
    l->luxelToWorldSpace[1].x = (float)((float)(v10 * y) - (float)(l->worldToLuxelSpace[0].y * z)) * (float)(1.0 / v6);
    v11 = -1.0 / v6;
    v12 = l->facedist * v3;
    x = l->worldToLuxelSpace[1].x;
    l->luxelOrigin.x = v12 * v11;
    v14 = l->facenormal.x;
    v15 = l->worldToLuxelSpace[0].x;
    l->luxelToWorldSpace[0].y = (float)((float)(v14 * l->worldToLuxelSpace[1].z) - (float)(x * z)) * v9;
    *(float *)&la = v15;
    l->luxelToWorldSpace[1].y = (float)((float)(v15 * z) - (float)(v14 * l->worldToLuxelSpace[0].z)) * v9;
    v16 = l->facedist * luxelSpaceCross_4;
    v17 = v14 * l->worldToLuxelSpace[1].y;
    v18 = v14 * l->worldToLuxelSpace[0].y;
    l->luxelToWorldSpace[0].z = (float)((float)(x * y) - v17) * v9;
    l->luxelToWorldSpace[1].z = (float)(v18 - (float)(*(float *)&la * y)) * v9;
    l->luxelOrigin.y = v16 * v11;
    l->luxelOrigin.z = (float)(l->facedist * luxelSpaceCross_8) * v11;
    v19 = -v2->lightmapVecsLuxelsPerWorldUnits[0][3];
    l->luxelOrigin.x = (float)(l->luxelToWorldSpace[0].x * v19) + l->luxelOrigin.x;
    l->luxelOrigin.y = (float)(l->luxelToWorldSpace[0].y * v19) + l->luxelOrigin.y;
    l->luxelOrigin.z = (float)(l->luxelToWorldSpace[0].z * v19) + l->luxelOrigin.z;
    v20 = -v2->lightmapVecsLuxelsPerWorldUnits[1][3];
    l->luxelOrigin.x = (float)(v20 * l->luxelToWorldSpace[1].x) + l->luxelOrigin.x;
    l->luxelOrigin.y = (float)(l->luxelToWorldSpace[1].y * v20) + l->luxelOrigin.y;
    l->luxelOrigin.z = (float)(l->luxelToWorldSpace[1].z * v20) + l->luxelOrigin.z;
  }
  else
  {
    _Warning(a1: " warning - face vectors parallel to face normal. bad lighting will be produced\n");
    l->luxelOrigin = vec3_origin;
  }
  l->luxelOrigin.x = l->luxelOrigin.x + l->modelorg.x;
  l->luxelOrigin.y = l->modelorg.y + l->luxelOrigin.y;
  l->luxelOrigin.z = l->modelorg.z + l->luxelOrigin.z;
}

//------------------------------------------------------------------------------
// Address: 0x1000E450
// Name: bool BuildFacesamplesAndLuxels_DoFast(struct lightinfo_t __near *,struct facelight_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl BuildFacesamplesAndLuxels_DoFast(lightinfo_t *pLightInfo, facelight_t *pFaceLight)
{
  dface_t *face; // eax
  int v3; // ecx
  int v4; // esi
  int texinfo; // edx
  float v6; // xmm3_4
  texinfo_s *v7; // eax
  int v8; // esi
  int v9; // edi
  sample_t *v10; // ebx
  Vector *v12; // eax
  sample_t *v13; // ecx
  float *p_x; // ebx
  int v15; // eax
  int v16; // edi
  float *p_z; // esi
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm2_4
  int height; // [esp+18h] [ebp-1Ch]
  sample_t *pSamples; // [esp+1Ch] [ebp-18h]
  float v23; // [esp+20h] [ebp-14h]
  float v24; // [esp+24h] [ebp-10h]
  float v25; // [esp+28h] [ebp-Ch]
  int t; // [esp+2Ch] [ebp-8h]
  int width; // [esp+30h] [ebp-4h]

  face = pLightInfo->face;
  v3 = face->m_LightmapTextureSizeInLuxels[0];
  v4 = face->m_LightmapTextureSizeInLuxels[1];
  texinfo = face->texinfo;
  v6 = ::texinfo.m_Memory.m_pMemory[face->texinfo].lightmapVecsLuxelsPerWorldUnits[1][0];
  v7 = &::texinfo.m_Memory.m_pMemory[face->texinfo];
  v8 = v4 + 1;
  v9 = ++v3 * v8;
  width = v3;
  height = v8;
  pFaceLight->worldAreaPerLuxel = 1.0
                                / (float)(fsqrt(
                                            (float)((float)(::texinfo.m_Memory.m_pMemory[texinfo].lightmapVecsLuxelsPerWorldUnits[0][0]
                                                          * ::texinfo.m_Memory.m_pMemory[texinfo].lightmapVecsLuxelsPerWorldUnits[0][0])
                                                  + (float)(::texinfo.m_Memory.m_pMemory[texinfo].lightmapVecsLuxelsPerWorldUnits[0][1]
                                                          * ::texinfo.m_Memory.m_pMemory[texinfo].lightmapVecsLuxelsPerWorldUnits[0][1]))
                                          + (float)(::texinfo.m_Memory.m_pMemory[texinfo].lightmapVecsLuxelsPerWorldUnits[0][2]
                                                  * ::texinfo.m_Memory.m_pMemory[texinfo].lightmapVecsLuxelsPerWorldUnits[0][2]))
                                        * fsqrt(
                                            (float)((float)(v7->lightmapVecsLuxelsPerWorldUnits[1][1]
                                                          * v7->lightmapVecsLuxelsPerWorldUnits[1][1])
                                                  + (float)(v6 * v6))
                                          + (float)(v7->lightmapVecsLuxelsPerWorldUnits[1][2]
                                                  * v7->lightmapVecsLuxelsPerWorldUnits[1][2])));
  pFaceLight->numsamples = v3 * v8;
  v10 = (sample_t *)calloc(count: v3 * v8, size: 0x40u);
  pFaceLight->sample = v10;
  if ( v10 == nullptr )
    return 0;
  pFaceLight->numluxels = v9;
  v12 = (Vector *)calloc(count: v9, size: 0xCu);
  pFaceLight->luxel = v12;
  if ( v12 == nullptr )
    return 0;
  v13 = v10;
  p_x = &v12->x;
  v15 = 0;
  for ( t = 0; v15 < v8; t = v15 )
  {
    v16 = 0;
    if ( width > 0 )
    {
      v25 = (float)v15;
      p_z = &v13->pos.z;
      v18 = (double)v15 - 0.5;
      v24 = v18;
      v23 = (double)v15 + 0.5;
      pSamples = &v13[width];
      do
      {
        *((_DWORD *)p_z - 9) = v15;
        *((_DWORD *)p_z - 10) = v16;
        *(p_z - 8) = (float)v16;
        *(p_z - 7) = v25;
        v19 = (double)v16 + 0.5;
        *(p_z - 4) = v19;
        v20 = (double)v16 - 0.5;
        *(p_z - 6) = v20;
        *(p_z - 3) = v23;
        *(p_z - 5) = v24;
        p_z[4] = pFaceLight->worldAreaPerLuxel;
        LuxelSpaceToWorld(l: pLightInfo, s: *(p_z - 8), t: *(p_z - 7), world: (Vector *)(p_z - 2));
        *p_x = *(p_z - 2);
        v15 = t;
        p_x[1] = *(p_z - 1);
        ++v16;
        p_x[2] = *p_z;
        p_z += 16;
        p_x += 3;
      }
      while ( v16 < width );
      v13 = pSamples;
      v8 = height;
    }
    ++v15;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000E660
// Name: bool BuildFacesamples(struct lightinfo_t __near *,struct facelight_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl BuildFacesamples(lightinfo_t *pLightInfo, facelight_t *pFaceLight)
{
  lightinfo_t *v2; // edi
  dface_t *face; // eax
  facelight_t *v4; // ebx
  int v5; // ecx
  int texinfo; // eax
  float v7; // xmm3_4
  unsigned __int8 *v8; // esi
  winding_t *v9; // eax
  double v10; // xmm0_8
  int v11; // edi
  winding_t *v12; // eax
  int v13; // edx
  double v14; // st7
  float x; // xmm0_4
  winding_t *v16; // ecx
  winding_t *v17; // eax
  int v18; // ebx
  int v19; // edi
  unsigned int v20; // esi
  unsigned __int8 *v21; // eax
  int v23; // ecx
  int v24; // edx
  float *p_x; // eax
  winding_t *t; // [esp+8h] [ebp-26504h]
  winding_t *v27; // [esp+Ch] [ebp-26500h]
  unsigned __int8 src[156800]; // [esp+1Ch] [ebp-264F0h] BYREF
  Vector mins; // [esp+2649Ch] [ebp-70h] BYREF
  Vector maxs; // [esp+264A8h] [ebp-64h] BYREF
  Vector center; // [esp+264B4h] [ebp-58h] BYREF
  Vector normal; // [esp+264C0h] [ebp-4Ch] BYREF
  Vector v33; // [esp+264CCh] [ebp-40h] BYREF
  Vector world; // [esp+264D8h] [ebp-34h] BYREF
  winding_t *front; // [esp+264E4h] [ebp-28h] BYREF
  winding_t *v36; // [esp+264E8h] [ebp-24h] BYREF
  int v37; // [esp+264ECh] [ebp-20h]
  float v38; // [esp+264F0h] [ebp-1Ch]
  int v39; // [esp+264F4h] [ebp-18h]
  int v40; // [esp+264F8h] [ebp-14h]
  winding_t *v41; // [esp+264FCh] [ebp-10h]
  int v42; // [esp+26500h] [ebp-Ch]
  winding_t *back; // [esp+26504h] [ebp-8h] BYREF
  winding_t *w; // [esp+26508h] [ebp-4h] BYREF

  v2 = pLightInfo;
  face = pLightInfo->face;
  v4 = pFaceLight;
  v39 = face->m_LightmapTextureSizeInLuxels[0] + 1;
  v5 = face->m_LightmapTextureSizeInLuxels[1];
  texinfo = face->texinfo;
  v37 = v5 + 1;
  texinfo *= 9;
  v7 = ::texinfo.m_Memory.m_pMemory->lightmapVecsLuxelsPerWorldUnits[1][2 * texinfo];
  pFaceLight->worldAreaPerLuxel = 1.0
                                / (float)(fsqrt(
                                            (float)((float)(::texinfo.m_Memory.m_pMemory->lightmapVecsLuxelsPerWorldUnits[0][2 * texinfo]
                                                          * ::texinfo.m_Memory.m_pMemory->lightmapVecsLuxelsPerWorldUnits[0][2 * texinfo])
                                                  + (float)(::texinfo.m_Memory.m_pMemory->lightmapVecsLuxelsPerWorldUnits[0][2 * texinfo + 1]
                                                          * ::texinfo.m_Memory.m_pMemory->lightmapVecsLuxelsPerWorldUnits[0][2 * texinfo + 1]))
                                          + (float)(::texinfo.m_Memory.m_pMemory->lightmapVecsLuxelsPerWorldUnits[0][2 * texinfo + 2]
                                                  * ::texinfo.m_Memory.m_pMemory->lightmapVecsLuxelsPerWorldUnits[0][2 * texinfo + 2]))
                                        * fsqrt(
                                            (float)((float)(::texinfo.m_Memory.m_pMemory->lightmapVecsLuxelsPerWorldUnits[1][2 * texinfo + 1]
                                                          * ::texinfo.m_Memory.m_pMemory->lightmapVecsLuxelsPerWorldUnits[1][2 * texinfo + 1])
                                                  + (float)(v7 * v7))
                                          + (float)(::texinfo.m_Memory.m_pMemory->lightmapVecsLuxelsPerWorldUnits[1][2 * texinfo + 2]
                                                  * ::texinfo.m_Memory.m_pMemory->lightmapVecsLuxelsPerWorldUnits[1][2 * texinfo + 2])));
  v8 = src;
  v9 = LightmapCoordWindingForFace(l: pLightInfo);
  v41 = v9;
  v33.x = 1.0;
  v33.y = 0.0;
  v33.z = 0.0;
  normal.x = 0.0;
  normal.y = 1.0;
  normal.z = 0.0;
  if ( do_centersamples != 0 )
    v10 = 0.5;
  else
    v10 = 1.0;
  v38 = v10;
  v42 = 0;
  if ( v37 > 0 )
  {
    while ( v9 != nullptr )
    {
      ClipWindingEpsilon(in: v9, &normal, dist: (float)v42 + v38, epsilon: 0.0062500001, &front, &back);
      v11 = 0;
      v40 = 0;
      if ( v39 > 0 )
      {
        v12 = back;
        do
        {
          if ( v12 == nullptr )
            break;
          ClipWindingEpsilon(
            in: v12,
            normal: &v33,
            dist: (float)v11 + v38,
            epsilon: 0.0062500001,
            front: &v36,
            back: &w);
          if ( w != nullptr )
          {
            v13 = v42;
            t = w;
            *((_DWORD *)v8 + 1) = v11;
            *((_DWORD *)v8 + 2) = v13;
            v14 = WindingAreaAndBalancePoint(w: t, &center);
            x = center.x;
            v16 = w;
            *((float *)v8 + 15) = v14 * v4->worldAreaPerLuxel;
            *((float *)v8 + 3) = x;
            *((_DWORD *)v8 + 4) = LODWORD(center.y);
            WindingBounds(w: v16, &mins, &maxs);
            *((_DWORD *)v8 + 5) = LODWORD(mins.x);
            *((_DWORD *)v8 + 6) = LODWORD(mins.y);
            *((_DWORD *)v8 + 7) = LODWORD(maxs.x);
            *((_DWORD *)v8 + 8) = LODWORD(maxs.y);
            LuxelSpaceToWorld(l: pLightInfo, s: *((float *)v8 + 3), t: *((float *)v8 + 4), world: (Vector *)v8 + 3);
            if ( g_bDumpPatches != 0 || do_extra != 0 && v4->worldAreaPerLuxel - 0.001 > *((float *)v8 + 15) )
            {
              v17 = w;
              v18 = 0;
              if ( w->numpoints > 0 )
              {
                v19 = 0;
                do
                {
                  LuxelSpaceToWorld(l: pLightInfo, s: v17->p[v19].x, t: v17->p[v19].y, &world);
                  w->p[v19] = world;
                  v17 = w;
                  ++v18;
                  ++v19;
                }
                while ( v18 < w->numpoints );
                v11 = v40;
              }
              v4 = pFaceLight;
              *(_DWORD *)v8 = v17;
            }
            else
            {
              v27 = w;
              *(_DWORD *)v8 = 0;
              FreeWinding(w: v27);
            }
            v8 += 64;
          }
          if ( back != nullptr )
            FreeWinding(w: back);
          v12 = v36;
          ++v11;
          back = v36;
          v40 = v11;
        }
        while ( v11 < v39 );
      }
      FreeWinding(w: v41);
      if ( back != nullptr )
        FreeWinding(w: back);
      v2 = pLightInfo;
      v41 = front;
      if ( ++v42 >= v37 )
        break;
      v9 = front;
    }
  }
  v20 = (v8 - src) >> 6;
  v4->numsamples = v20;
  v21 = (unsigned __int8 *)calloc(count: v20, size: 0x40u);
  v4->sample = (sample_t *)v21;
  if ( v21 == nullptr )
    return 0;
  memcpy(dst: v21, src, count: v20 << 6);
  v23 = 0;
  if ( v4->numsamples > 0 )
  {
    v24 = 0;
    do
    {
      p_x = &v4->sample[v24].normal.x;
      *p_x = v2->facenormal.x;
      ++v23;
      ++v24;
      p_x[1] = v2->facenormal.y;
      p_x[2] = v2->facenormal.z;
    }
    while ( v23 < v4->numsamples );
  }
  if ( v4->numsamples == 0 )
    _Msg(a1: "no samples %d\n", v2->face - g_pFaces);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000EA60
// Name: void CalcPoints(struct lightinfo_t __near *,struct facelight_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalcPoints(lightinfo_t *pLightInfo, facelight_t *pFaceLight, int ndxFace)
{
  dface_t *face; // eax
  char v4; // al
  IVRadDispMgr *v5; // eax
  facelight_t *v6; // edi
  char v7; // al
  IVRadDispMgr *v8; // eax
  char v9; // al
  IVRadDispMgr *v10; // eax

  if ( g_bDumpPatches != 0 )
    DumpFaces(pLightInfo, ndxFace);
  face = pLightInfo->face;
  if ( do_fast != 0 )
  {
    if ( face->dispinfo == -1 )
    {
      v4 = BuildFacesamplesAndLuxels_DoFast(pLightInfo, pFaceLight);
    }
    else
    {
      v5 = StaticDispMgr();
      v4 = v5->BuildDispSamplesAndLuxels_DoFast(this: v5, a2: pLightInfo, a3: pFaceLight, a4: ndxFace);
    }
    if ( v4 == 0 )
      _Msg(a1: "Face %d: (Fast)Error Building Samples and Luxels\n", ndxFace);
  }
  else
  {
    if ( face->dispinfo == -1 )
    {
      v6 = pFaceLight;
      v7 = BuildFacesamples(pLightInfo, pFaceLight);
    }
    else
    {
      v8 = StaticDispMgr();
      v6 = pFaceLight;
      v7 = v8->BuildDispSamples(this: v8, a2: pLightInfo, a3: pFaceLight, a4: ndxFace);
    }
    if ( v7 == 0 )
      _Msg(a1: "Face %d: Error Building Samples\n", ndxFace);
    if ( pLightInfo->face->dispinfo == -1 )
    {
      v9 = BuildFaceLuxels(pLightInfo, pFaceLight: v6);
    }
    else
    {
      v10 = StaticDispMgr();
      v9 = v10->BuildDispLuxels(this: v10, a2: pLightInfo, a3: v6, a4: ndxFace);
    }
    if ( v9 == 0 )
      _Msg(a1: "Face %d: Error Building Luxels\n", ndxFace);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EB50
// Name: struct directlight_t __near * AllocDLight(class Vector __near &,bool)
// Source: json
//------------------------------------------------------------------------------
directlight_t *__cdecl AllocDLight(Vector *origin, bool bAddToList)
{
  directlight_t *v2; // esi
  int v3; // eax
  bool v4; // zf
  int v5; // edi

  v2 = (directlight_t *)calloc(count: 1u, size: 0xBCu);
  v2->index = numdlights++;
  v2->light.origin = *origin;
  v3 = ClusterFromPoint(point: &v2->light.origin);
  v4 = v2->pvs == nullptr;
  v5 = v3;
  v2->light.cluster = v3;
  if ( v4 )
    v2->pvs = (unsigned __int8 *)calloc(count: 1u, size: dvis->numclusters / 8 + 1);
  GetVisCache(lastoffset: -1, cluster: v5, pvs: v2->pvs);
  v2->facenum = -1;
  if ( bAddToList )
  {
    v2->next = activelights;
    activelights = v2;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1000EBF0
// Name: ParseLightSpot
// Source: json
//------------------------------------------------------------------------------
void __usercall ParseLightSpot(entity_t *e@<eax>, int a2@<ebx>)
{
  long double v2; // rdi
  double v3; // st7
  double v4; // st7
  float v5; // xmm0_4
  double v6; // xmm0_8
  double v7; // xmm0_8
  long double v8; // [esp-4h] [ebp-18h]
  long double v9; // [esp-4h] [ebp-18h]
  Vector dest; // [esp+8h] [ebp-Ch] BYREF

  LODWORD(v2) = e;
  GetVectorForKey(ent: e, key: "origin", angle: (QAngle *)&dest);
  HIDWORD(v2) = AllocDLight(origin: &dest, bAddToList: true);
  ParseLightGeneric(e: v2);
  *(_DWORD *)(HIDWORD(v2) + 60) = 2;
  v3 = FloatForKey(ent: (entity_t *)LODWORD(v2), key: "_inner_cone");
  *(float *)(HIDWORD(v2) + 68) = v3;
  if ( v3 == 0.0 )
    *(_DWORD *)(HIDWORD(v2) + 68) = 1092616192;
  v4 = FloatForKey(ent: (entity_t *)LODWORD(v2), key: "_cone");
  *(float *)(HIDWORD(v2) + 72) = v4;
  if ( v4 == 0.0 )
    *(float *)(HIDWORD(v2) + 72) = *(float *)(HIDWORD(v2) + 68);
  v5 = *(float *)(HIDWORD(v2) + 68);
  if ( v5 > *(float *)(HIDWORD(v2) + 72) )
    *(float *)(HIDWORD(v2) + 72) = v5;
  if ( v5 == 180.0 && *(float *)(HIDWORD(v2) + 72) == 180.0 )
  {
    *(_QWORD *)(HIDWORD(v2) + 68) = 0;
    *(_DWORD *)(HIDWORD(v2) + 60) = 1;
    *(_DWORD *)(HIDWORD(v2) + 76) = 0;
    SetLightFalloffParams(e: (entity_t *)LODWORD(v2), dl: (directlight_t *)HIDWORD(v2));
  }
  else
  {
    LODWORD(v8) = a2;
    if ( v5 > 90.0 )
    {
      _Warning(
        a1: "WARNING: light_spot at (%i %i %i) has inner angle larger than 90 degrees! Clamping to 90...\n",
        (int)*(float *)(HIDWORD(v2) + 8),
        (int)*(float *)(HIDWORD(v2) + 12),
        (int)*(float *)(HIDWORD(v2) + 16));
      *(_DWORD *)(HIDWORD(v2) + 68) = 1119092736;
    }
    if ( *(float *)(HIDWORD(v2) + 72) > 90.0 )
    {
      _Warning(
        a1: "WARNING: light_spot at (%i %i %i) has outer angle larger than 90 degrees! Clamping to 90...\n",
        (int)*(float *)(HIDWORD(v2) + 8),
        (int)*(float *)(HIDWORD(v2) + 12),
        (int)*(float *)(HIDWORD(v2) + 16));
      *(_DWORD *)(HIDWORD(v2) + 72) = 1119092736;
    }
    v6 = (float)(*(float *)(HIDWORD(v2) + 72) * 0.0055555557) * 3.141592653589793;
    __libm_sse2_cos(x: v8);
    *(float *)&v6 = v6;
    *(_DWORD *)(HIDWORD(v2) + 72) = LODWORD(v6);
    v7 = (float)(*(float *)(HIDWORD(v2) + 68) * 0.0055555557) * 3.141592653589793;
    __libm_sse2_cos(x: v9);
    *(float *)&v7 = v7;
    *(_DWORD *)(HIDWORD(v2) + 68) = LODWORD(v7);
    *(float *)(HIDWORD(v2) + 76) = FloatForKey(ent: (entity_t *)LODWORD(v2), key: "_exponent");
    SetLightFalloffParams(e: (entity_t *)LODWORD(v2), dl: (directlight_t *)HIDWORD(v2));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EDA0
// Name: void BuildVisForLightEnvironment(int,struct directlight_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildVisForLightEnvironment(int nNumLights, directlight_t **pLights)
{
  int v2; // eax
  __int16 *v3; // esi
  int v4; // edx
  __int16 v5; // di
  unsigned __int16 *v6; // ecx
  __int16 v7; // di
  int i; // edi
  int v9; // esi
  void *v10; // esp
  void *v11; // esp
  int v12; // ecx
  int v13; // edi
  dleaf_t *v14; // eax
  int v15; // esi
  char v16; // cl
  int v17; // edi
  int v18; // esi
  int v19; // ebx
  __int16 *v20; // eax
  __int16 v21; // cx
  int v22; // eax
  int v23; // edi
  __int16 *v24; // esi
  int v25; // eax
  unsigned __int8 v26[12]; // [esp+0h] [ebp-2024h] BYREF
  unsigned __int8 pvs[8192]; // [esp+Ch] [ebp-2018h] BYREF
  __int16 *v28; // [esp+200Ch] [ebp-18h]
  unsigned __int8 *v29; // [esp+2010h] [ebp-14h]
  unsigned __int8 *v30; // [esp+2014h] [ebp-10h]
  dleaf_t *v31; // [esp+2018h] [ebp-Ch]
  __int16 v32; // [esp+201Eh] [ebp-6h]
  int v33; // [esp+2020h] [ebp-4h]
  int savedregs; // [esp+2024h] [ebp+0h] BYREF

  v2 = numleafs;
  v33 = 0;
  if ( (int)numleafs > 0 )
  {
    v3 = &word_1135AAB6;
    do
    {
      v4 = 0;
      v5 = *v3 & 0xF5FF;
      *v3 = v5;
      if ( v3[8] != 0 )
      {
        v6 = &dleaffaces[(unsigned __int16)v3[7]];
        while ( (texinfo.m_Memory.m_pMemory[g_pFaces[*v6].texinfo].flags & 4) == 0 )
        {
          ++v4;
          ++v6;
          if ( v4 >= (unsigned __int16)v3[8] )
            goto LABEL_13;
        }
        if ( (texinfo.m_Memory.m_pMemory[g_pFaces[*v6].texinfo].flags & 2) != 0 )
          v7 = v5 | 0x800;
        else
          v7 = v5 | 0x200;
        *v3 = v7;
        for ( i = 0; i < nNumLights; ++i )
          MergeDLightVis(dl: pLights[i], cluster: *(v3 - 1));
      }
LABEL_13:
      v2 = numleafs;
      v3 += 16;
      ++v33;
    }
    while ( v33 < (int)numleafs );
  }
  v9 = (v2 >> 3) + 1;
  v10 = alloca(v9);
  v29 = v26;
  v11 = alloca(v9);
  v30 = v26;
  memset(dst: v26, value: 0, count: v9);
  memset(dst: v26, value: 0, count: v9);
  v12 = numleafs;
  v13 = 0;
  v33 = 0;
  if ( (int)numleafs > 0 )
  {
    v14 = dleafs;
    v31 = dleafs;
    while ( 1 )
    {
      if ( (*(_WORD *)&v14->___u2 & 0x200) == 0 && (v14->contents & 1) == 0 )
      {
        GetVisCache(lastoffset: -1, cluster: v14->cluster, pvs);
        v15 = v13;
        v16 = v13 & 7;
        v17 = 0;
        v18 = v15 >> 3;
        v19 = 1 << v16;
        if ( (int)numleafs > 0 )
          break;
      }
LABEL_31:
      v12 = numleafs;
      v13 = v33 + 1;
      v14 = v31 + 1;
      v33 = v13;
      ++v31;
      if ( v13 >= (int)numleafs )
        goto LABEL_32;
    }
    v20 = &word_1135AAB6;
    v28 = &word_1135AAB6;
    while ( 1 )
    {
      if ( v17 == v33 )
        goto LABEL_28;
      v21 = *v20 >> 9;
      v32 = v21;
      if ( (v21 & 5) != 0 )
      {
        v22 = *(v20 - 1);
        if ( v22 >= 0 )
        {
          if ( (pvs[v22 >> 3] & (unsigned __int8)(1 << (v22 & 7))) == 0 )
            goto LABEL_28;
          LOBYTE(v21) = v32;
        }
        if ( (v21 & 4) != 0 )
          v30[v18] |= v19;
        if ( (v21 & 1) != 0 )
        {
          v29[v18] |= v19;
          goto LABEL_31;
        }
      }
LABEL_28:
      ++v17;
      v20 = v28 + 16;
      v28 += 16;
      if ( v17 >= (int)numleafs )
        goto LABEL_31;
    }
  }
LABEL_32:
  v23 = 0;
  if ( v12 > 0 )
  {
    v24 = &word_1135AAB6;
    do
    {
      if ( (*v24 & 0x200) == 0 && (*(_BYTE *)(v24 - 3) & 1) == 0 )
      {
        v25 = 1 << (v23 & 7);
        if ( ((unsigned __int8)v25 & v30[v23 >> 3]) != 0 )
          *v24 |= 0x800u;
        if ( ((unsigned __int8)v25 & v29[v23 >> 3]) != 0 )
        {
          *v24 = *v24 & 0xF5FF | 0x200;
        }
        else if ( (*v24 & 0x400) != 0 && CanLeafTraceToSky(a1: (int)&savedregs) != 0 )
        {
          *v24 |= 0x200u;
        }
      }
      ++v23;
      v24 += 16;
    }
    while ( v23 < (int)numleafs );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F050
// Name: ParseLightEnvironment
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParseLightEnvironment(entity_t *e)
{
  long double v1; // rdi
  const char *v2; // eax
  directlight_t *v3; // eax
  char *v4; // eax
  char *v5; // eax
  directlight_t *v6; // eax
  float *p_x; // esi
  double v8; // st7
  directlight_t *v9; // ecx
  directlight_t *v10; // eax
  directlight_t *v11; // ecx
  Vector dest; // [esp+14h] [ebp-14h] BYREF
  directlight_t *lights[2]; // [esp+20h] [ebp-8h] BYREF

  GetVectorForKey(ent: e, key: "origin", angle: (QAngle *)&dest);
  HIDWORD(v1) = AllocDLight(origin: &dest, bAddToList: false);
  ParseLightGeneric(e: COERCE_LONG_DOUBLE(__PAIR64__(HIDWORD(v1), (unsigned int)e)));
  if ( gSkyLight != nullptr )
    return;
  v2 = ValueForKeyWithDefault(ent: e, key: "SunSpreadAngle", default_value: nullptr);
  if ( v2 != nullptr )
  {
    g_SunAngularExtent = sin(atof(nptr: v2) * 0.0174532925199433);
    *(float *)(HIDWORD(v1) + 164) = g_SunAngularExtent;
    printf(format: "sun extent from map=%f\n", g_SunAngularExtent);
  }
  gSkyLight = (directlight_t *)HIDWORD(v1);
  *(_DWORD *)(HIDWORD(v1) + 60) = 3;
  v3 = AllocDLight(origin: (Vector *)(HIDWORD(v1) + 8), bAddToList: false);
  v3->light.type = emit_skyambient;
  gAmbient = v3;
  if ( g_bHDR )
  {
    LODWORD(v1) = &v3->light.intensity;
    v4 = ValueForKey(ent: e, key: "_ambientHDR");
    if ( LightForString(a1: v1, pLight: v4, intensity: (Vector *)LODWORD(v1)) != 0 )
    {
LABEL_9:
      v6 = gAmbient;
      goto LABEL_10;
    }
    v3 = gAmbient;
  }
  LODWORD(v1) = &v3->light.intensity;
  v5 = ValueForKey(ent: e, key: "_ambient");
  if ( LightForString(a1: v1, pLight: v5, intensity: (Vector *)LODWORD(v1)) != 0 )
    goto LABEL_9;
  v6 = gAmbient;
  gAmbient->light.intensity.x = *(float *)(HIDWORD(v1) + 20) * 0.5;
  v6->light.intensity.y = *(float *)(HIDWORD(v1) + 24) * 0.5;
  v6->light.intensity.z = *(float *)(HIDWORD(v1) + 28) * 0.5;
LABEL_10:
  if ( g_bHDR )
  {
    p_x = &v6->light.intensity.x;
    v8 = FloatForKeyWithDefault(ent: e, key: "_AmbientScaleHDR", default_value: 1.0);
    v6 = gAmbient;
    *p_x = gAmbient->light.intensity.x * v8;
    p_x[1] = v6->light.intensity.y * v8;
    p_x[2] = v8 * v6->light.intensity.z;
  }
  v9 = gSkyLight;
  gSkyLight->light.flags &= ~2u;
  v6->light.flags &= ~2u;
  lights[1] = v6;
  lights[0] = v9;
  BuildVisForLightEnvironment(nNumLights: 2, pLights: lights);
  v10 = gSkyLight;
  gSkyLight->next = activelights;
  v11 = gAmbient;
  gAmbient->next = v10;
  activelights = v11;
}

//------------------------------------------------------------------------------
// Address: 0x1000F210
// Name: ParseLightDirectional
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParseLightDirectional(entity_t *e, directlight_t *dl)
{
  directlight_t *v2; // esi
  const char *v3; // eax
  long double v4; // st7
  Vector dest; // [esp+Ch] [ebp-Ch] BYREF

  GetVectorForKey(ent: e, key: "origin", angle: (QAngle *)&dest);
  v2 = AllocDLight(origin: &dest, bAddToList: true);
  dl = v2;
  ParseLightGeneric(e: COERCE_LONG_DOUBLE(__PAIR64__((unsigned int)v2, (unsigned int)e)));
  v3 = ValueForKeyWithDefault(ent: e, key: "SunSpreadAngle", default_value: nullptr);
  if ( v3 != nullptr )
  {
    v4 = atof(nptr: v3);
    v2->m_flSkyLightSunAngularExtent = v4;
    v2->m_flSkyLightSunAngularExtent = sin(v4 * 0.0174532925199433);
  }
  v2->light.type = emit_skylight;
  v2->m_bSkyLightIsDirectionalLight = true;
  v2->light.flags &= ~2u;
  BuildVisForLightEnvironment(nNumLights: 1, pLights: &dl);
}

//------------------------------------------------------------------------------
// Address: 0x1000F2A0
// Name: void CreateDirectLights(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateDirectLights()
{
  directlight_t *v0; // eax
  int v1; // edi
  directlight_t *v2; // ebx
  directlight_t *next; // esi
  int m_Size; // ebx
  CPatch *v5; // esi
  directlight_t *v6; // eax
  float v7; // xmm0_4
  long double v8; // rdi
  const char *v9; // esi
  QAngle angle; // [esp+Ch] [ebp-10h] BYREF
  unsigned int i; // [esp+18h] [ebp-4h]

  v0 = activelights;
  v1 = 0;
  v2 = nullptr;
  i = 0;
  numdlights = 0;
  gSkyLight = nullptr;
  gAmbient = nullptr;
  if ( activelights != nullptr )
  {
    do
    {
      next = v0->next;
      free(pMem: v0);
      v0 = next;
    }
    while ( next != nullptr );
  }
  activelights = nullptr;
  if ( g_Patches.m_Size != 0 )
  {
    m_Size = g_Patches.m_Size;
    do
    {
      v5 = &g_Patches.m_Memory.m_pMemory[v1];
      if ( g_Patches.m_Memory.m_pMemory[v1].child1 == -1
        && v5->basearea >= 0.000001
        && (float)((float)((float)(v5->baselight.y + v5->baselight.x) + v5->baselight.z) * 0.33333334) >= dlight_threshold )
      {
        v6 = AllocDLight(origin: &v5->origin, bAddToList: true);
        v6->light.type = emit_surface;
        v6->light.flags &= ~2u;
        v6->light.normal.x = v5->normal.x;
        i = (unsigned int)v6;
        v6->light.normal.y = v5->normal.y;
        v6->light.normal.z = v5->normal.z;
        v7 = (float)((float)((float)(v5->area * lightscale) * v5->scale[0]) * v5->scale[1]) / v5->basearea;
        v6->light.intensity.x = v5->baselight.x * v7;
        v6->light.intensity.y = v5->baselight.y * v7;
        v6->light.intensity.z = v5->baselight.z * v7;
        v6->light.intensity.x = v6->light.intensity.x * 10000.0;
        v6->light.intensity.y = v6->light.intensity.y * 10000.0;
        v6->light.intensity.z = v6->light.intensity.z * 10000.0;
      }
      ++v1;
      --m_Size;
    }
    while ( m_Size != 0 );
    v2 = (directlight_t *)i;
  }
  i = 0;
  if ( num_entities != 0 )
  {
    LODWORD(v8) = entities;
    do
    {
      v9 = ValueForKey(ent: (entity_t *)LODWORD(v8), key: "classname");
      if ( strncmp(first: v9, last: "light", count: 5u) == 0 && strcmp(v9, "light_dynamic") != 0 )
      {
        if ( strcmp(v9, "light_spot") == 0 )
        {
          ParseLightSpot(e: (entity_t *)LODWORD(v8), a2: (int)v2);
        }
        else if ( strcmp(v9, "light_environment") == 0 )
        {
          ParseLightEnvironment(e: (entity_t *)LODWORD(v8));
        }
        else if ( strcmp(v9, "light_directional") == 0 )
        {
          ParseLightDirectional(e: (entity_t *)LODWORD(v8), dl: v2);
        }
        else if ( strcmp(v9, "light") == 0 )
        {
          GetVectorForKey(ent: (entity_t *)LODWORD(v8), key: "origin", &angle);
          HIDWORD(v8) = AllocDLight(origin: (Vector *)&angle, bAddToList: true);
          ParseLightGeneric(e: v8);
          *(_DWORD *)(HIDWORD(v8) + 60) = 1;
          SetLightFalloffParams(e: (entity_t *)LODWORD(v8), dl: (directlight_t *)HIDWORD(v8));
        }
        else
        {
          qprintf(format: "unsupported light entity: \"%s\"\n", v9);
        }
      }
      LODWORD(v8) += 44;
      ++i;
    }
    while ( i < num_entities );
  }
  qprintf(format: "%i direct lights\n", numdlights);
}

//------------------------------------------------------------------------------
// Address: 0x1000F600
// Name: void AddSampleToPatch(struct sample_t __near *,struct LightingValue_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddSampleToPatch(sample_t *s, LightingValue_t *light, int facenum)
{
  int v3; // esi
  int v4; // esi
  bool v5; // zf
  CPatch *v6; // esi
  int ndxNext; // eax
  CPatch *v8; // edi
  Vector *p_pos; // ecx
  int v10; // eax
  float area; // xmm0_4
  Vector maxs; // [esp+0h] [ebp-1Ch] BYREF
  Vector mins; // [esp+Ch] [ebp-10h] BYREF
  float radius; // [esp+18h] [ebp-4h]

  if ( numbounce != 0
    && (float)((float)((float)(light->m_vecLighting.y + light->m_vecLighting.x) + light->m_vecLighting.z) * 0.33333334) >= 1.0 )
  {
    v3 = g_FacePatches.m_Memory.m_pMemory[facenum];
    if ( v3 != -1 )
    {
      v4 = v3;
      v5 = &g_Patches.m_Memory.m_pMemory[v4] == nullptr;
      v6 = &g_Patches.m_Memory.m_pMemory[v4];
      radius = fsqrt(s->area) * 0.5;
      if ( !v5 )
      {
        do
        {
          ndxNext = v6->ndxNext;
          v8 = nullptr;
          if ( ndxNext != -1 )
            v8 = &g_Patches.m_Memory.m_pMemory[ndxNext];
          if ( (*((_BYTE *)v6 + 72) & 4) == 0 && v6->child1 == -1 )
          {
            WindingBounds(w: v6->winding, &mins, &maxs);
            p_pos = &s->pos;
            v10 = 0;
            while ( *(float *)((char *)&mins.x + v10) <= (float)(p_pos->x + radius)
                 && (float)(p_pos->x - radius) <= *(float *)((char *)&maxs.x + v10) )
            {
              v10 += 4;
              p_pos = (Vector *)((char *)p_pos + 4);
              if ( v10 >= 12 )
              {
                v6->samplearea = s->area + v6->samplearea;
                area = s->area;
                v6->samplelight.x = (float)(light->m_vecLighting.x * area) + v6->samplelight.x;
                v6->samplelight.y = (float)(light->m_vecLighting.y * area) + v6->samplelight.y;
                v6->samplelight.z = (float)(light->m_vecLighting.z * area) + v6->samplelight.z;
                break;
              }
            }
          }
          v6 = v8;
        }
        while ( v8 != nullptr );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F780
// Name: void DumpSamples(int,struct facelight_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DumpSamples(int ndxFace, facelight_t *pFaceLight)
{
  dface_t *v2; // ecx
  int v3; // edx
  int v4; // eax
  int v5; // edi
  facelight_t *v6; // ecx
  int v7; // eax
  int v8; // ebx
  sample_t *sample; // esi
  winding_t *w; // edx
  const Vector *v11; // esi
  void *v12; // [esp-Ch] [ebp-40h]
  Vector color; // [esp+14h] [ebp-20h] BYREF
  dface_t *pFace; // [esp+20h] [ebp-14h]
  int iStyle; // [esp+24h] [ebp-10h]
  int iBump; // [esp+28h] [ebp-Ch]
  int iSample; // [esp+2Ch] [ebp-8h]
  int v18; // [esp+30h] [ebp-4h]
  bool bBumpped_3; // [esp+3Fh] [ebp+Bh]

  ThreadLock();
  v2 = &g_pFaces[ndxFace];
  pFace = v2;
  if ( v2 != nullptr )
  {
    v3 = 0;
    bBumpped_3 = (texinfo.m_Memory.m_pMemory[v2->texinfo].flags & 0x800) != 0;
    iStyle = 0;
    do
    {
      if ( v2->styles[v3] != 0xFF )
      {
        v4 = 0;
        iBump = 0;
        do
        {
          v5 = 0;
          if ( v4 == 0 || v4 > 0 && bBumpped_3 )
          {
            v6 = pFaceLight;
            iSample = 0;
            if ( pFaceLight->numsamples > 0 )
            {
              v7 = v4 + 4 * v3;
              v18 = v7;
              v8 = 0;
              while ( 1 )
              {
                sample = v6->sample;
                w = sample[v5].w;
                v11 = (const Vector *)&sample[v5];
                WriteWinding(out: pFileSamples[0][v7], w, color: &v6->light[0][v7][v8].m_vecLighting);
                if ( bDumpNormals )
                {
                  color.x = v11[4].x * 255.0;
                  color.y = v11[4].y * 255.0;
                  v12 = pFileSamples[0][v18];
                  color.z = v11[4].z * 255.0;
                  WriteNormal(out: v12, nPos: v11 + 3, nDir: v11 + 4, length: 15.0, &color);
                }
                v6 = pFaceLight;
                ++v5;
                ++v8;
                if ( ++iSample >= pFaceLight->numsamples )
                  break;
                v7 = v18;
              }
              v3 = iStyle;
              v4 = iBump;
            }
          }
          iBump = ++v4;
        }
        while ( v4 < 4 );
        v2 = pFace;
      }
      iStyle = ++v3;
    }
    while ( v3 < 4 );
  }
  ThreadUnlock();
}

//------------------------------------------------------------------------------
// Address: 0x1000F8F0
// Name: void InitLightinfo(struct lightinfo_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitLightinfo(lightinfo_t *pl, int facenum)
{
  dface_t *v2; // ebx
  int numedges; // ecx
  int v4; // eax
  Vector *i; // edx

  v2 = &g_pFaces[facenum];
  memset(dst: (unsigned __int8 *)pl, value: 0, count: sizeof(lightinfo_t));
  pl->facenum = facenum;
  pl->face = v2;
  pl->facenormal = *(Vector *)((char *)&dplanes + 20 * v2->planenum);
  pl->facedist = *(&dist + 5 * v2->planenum);
  pl->modelorg = face_offset[facenum];
  CalcFaceVectors(l: pl);
  pl->isflat = 1;
  if ( smoothing_threshold != 1.0 )
  {
    numedges = v2->numedges;
    v4 = 0;
    if ( numedges > 0 )
    {
      for ( i = faceneighbor[facenum].normal;
            (float)((float)((float)(i->y * pl->facenormal.y) + (float)(i->x * pl->facenormal.x))
                  + (float)(i->z * pl->facenormal.z)) >= 0.999;
            ++i )
      {
        if ( ++v4 >= numedges )
          return;
      }
      pl->isflat = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000FA10
// Name: InitSampleInfo
// Source: json
//------------------------------------------------------------------------------
void __usercall InitSampleInfo(const lightinfo_t *l@<ecx>, SSE_SampleInfo_t *info@<esi>, int iThread)
{
  int v3; // edx
  int v4; // eax
  texinfo_s *v5; // eax
  int facenum; // eax
  facelight_t *v7; // edi
  dface_t *face; // eax
  bool v9; // al
  int numsamples; // eax
  int v11; // eax
  __m128 x_low; // xmm0
  Vector *p_facenormal; // ecx
  texinfo_s *m_pTexInfo; // eax
  float *p_z; // eax
  __m128 *v16; // ecx
  int i; // edx
  Vector bumpVects[3]; // [esp+4h] [ebp-3Ch] BYREF
  Vector sVect; // [esp+28h] [ebp-18h] BYREF
  Vector tVect; // [esp+34h] [ebp-Ch] BYREF

  v3 = l->face->m_LightmapTextureSizeInLuxels[0] + 1;
  info->m_LightmapWidth = v3;
  v4 = l->face->m_LightmapTextureSizeInLuxels[1] + 1;
  info->m_LightmapSize = v4 * v3;
  info->m_LightmapHeight = v4;
  v5 = &texinfo.m_Memory.m_pMemory[l->face->texinfo];
  info->m_pTexInfo = v5;
  info->m_NormalCount = (v5->flags & 0x800) != 0 ? 4 : 1;
  facenum = l->facenum;
  info->m_FaceNum = facenum;
  v7 = &facelight[facenum];
  face = l->face;
  info->m_pFace = face;
  info->m_pFaceLight = v7;
  v9 = face != nullptr && face->dispinfo != -1 && face->numedges == 4;
  info->m_IsDispFace = v9;
  info->m_iThread = iThread;
  info->m_WarnFace = -1;
  numsamples = v7->numsamples;
  info->m_NumSamples = v7->numsamples;
  if ( (numsamples & 3) != 0 )
    v11 = numsamples / 4 + 1;
  else
    v11 = numsamples / 4;
  info->m_NumSampleGroups = v11;
  if ( l->isflat != 0 )
  {
    x_low = (__m128)LODWORD(l->facenormal.x);
    p_facenormal = &l->facenormal;
    info->m_PointNormals[0].x = _mm_shuffle_ps(x_low, x_low, 0);
    info->m_PointNormals[0].y = _mm_shuffle_ps((__m128)LODWORD(p_facenormal->y), (__m128)LODWORD(p_facenormal->y), 0);
    info->m_PointNormals[0].z = _mm_shuffle_ps((__m128)LODWORD(p_facenormal->z), (__m128)LODWORD(p_facenormal->z), 0);
    if ( info->m_NormalCount > 1 )
    {
      m_pTexInfo = info->m_pTexInfo;
      sVect.x = m_pTexInfo->textureVecsTexelsPerWorldUnits[0][0];
      sVect.y = m_pTexInfo->textureVecsTexelsPerWorldUnits[0][1];
      sVect.z = m_pTexInfo->textureVecsTexelsPerWorldUnits[0][2];
      tVect = *(Vector *)&m_pTexInfo->textureVecsTexelsPerWorldUnits[1][0];
      GetBumpNormals(&sVect, &tVect, flatNormal: p_facenormal, phongNormal: p_facenormal, bumpNormals: bumpVects);
      p_z = &bumpVects[0].z;
      v16 = &info->m_PointNormals[1].z;
      for ( i = 3; i != 0; --i )
      {
        v16[-2] = _mm_shuffle_ps((__m128)*((unsigned int *)p_z - 2), (__m128)*((unsigned int *)p_z - 2), 0);
        v16[-1] = _mm_shuffle_ps((__m128)*((unsigned int *)p_z - 1), (__m128)*((unsigned int *)p_z - 1), 0);
        *v16 = _mm_shuffle_ps((__m128)*(unsigned int *)p_z, (__m128)*(unsigned int *)p_z, 0);
        p_z += 3;
        v16 += 3;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000FBB0
// Name: void BuildPatchLights(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildPatchLights(int facenum)
{
  int v1; // edx
  dface_t *v2; // edi
  facelight_t *v3; // ecx
  int v4; // eax
  int v5; // ebx
  int v6; // edi
  int v7; // esi
  int v8; // ecx
  CPatch *m_pMemory; // esi
  CPatch *v10; // ecx
  int ndxNext; // eax
  CPatch *v12; // edi
  int parent; // eax
  int v14; // eax
  float v15; // xmm0_4
  float *v16; // eax
  CPatch *v17; // ecx
  int v18; // eax
  CPatch *v19; // edx
  float samplearea; // xmm0_4
  float v21; // xmm3_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  CPatch *v25; // eax
  int v26; // ecx
  CPatch *v27; // edi
  int child1; // ecx
  int v29; // ecx
  float area; // xmm3_4
  float *v31; // edx
  int child2; // ecx
  float v33; // xmm2_4
  float *v34; // ecx
  float v35; // xmm1_4
  float v36; // xmm0_4
  float x; // xmm0_4
  int i; // eax
  unsigned __int8 v39; // cl
  int v40; // ebx
  int v41; // eax
  LightingValue_t *v42; // edx
  int *v43; // edi
  unsigned int v44; // ecx
  float *p_z; // esi
  int v46; // eax
  int v47; // eax
  float v48; // xmm0_4
  int v49; // eax
  int v50; // eax
  float v51; // xmm0_4
  float *v52; // eax
  LightingValue_t **v53; // [esp+4h] [ebp-Ch]
  facelight_t *fl; // [esp+8h] [ebp-8h]
  dface_t *f; // [esp+Ch] [ebp-4h]
  bool needsBumpmap_3; // [esp+1Bh] [ebp+Bh]

  v1 = facenum;
  v2 = &g_pFaces[facenum];
  v3 = &facelight[facenum];
  f = v2;
  fl = v3;
  v4 = 0;
  while ( v2->styles[v4] != 0 )
  {
    if ( ++v4 >= 4 )
      return;
  }
  v5 = 0;
  if ( v3->numsamples > 0 )
  {
    v6 = 0;
    v53 = v3->light[v4];
    v7 = 0;
    while ( 1 )
    {
      AddSampleToPatch(s: &v3->sample[v6], light: &(*v53)[v7], facenum: v1);
      ++v5;
      ++v7;
      ++v6;
      v1 = facenum;
      if ( v5 >= fl->numsamples )
        break;
      v3 = &facelight[facenum];
    }
    v2 = f;
  }
  v8 = g_FacePatches.m_Memory.m_pMemory[v1];
  if ( v8 != -1 )
  {
    m_pMemory = g_Patches.m_Memory.m_pMemory;
    v10 = &g_Patches.m_Memory.m_pMemory[v8];
    if ( v10 != nullptr )
    {
      do
      {
        ndxNext = v10->ndxNext;
        v12 = nullptr;
        if ( ndxNext != -1 )
          v12 = &m_pMemory[ndxNext];
        parent = v10->parent;
        if ( parent != -1 )
        {
          v14 = parent;
          v15 = v10->samplearea + m_pMemory[v14].samplearea;
          v16 = (float *)&m_pMemory[v14];
          v16[53] = v15;
          v16[50] = v10->samplelight.x + v16[50];
          v16[51] = v10->samplelight.y + v16[51];
          v16[52] = v10->samplelight.z + v16[52];
          m_pMemory = g_Patches.m_Memory.m_pMemory;
        }
        v10 = v12;
      }
      while ( v12 != nullptr );
      v2 = f;
    }
    if ( numbounce != 0 )
    {
      v17 = &m_pMemory[g_FacePatches.m_Memory.m_pMemory[v1]];
      if ( v17 != nullptr )
      {
        do
        {
          v18 = v17->ndxNext;
          v19 = nullptr;
          if ( v18 != -1 )
            v19 = &m_pMemory[v18];
          samplearea = v17->samplearea;
          if ( samplearea != 0.0 )
          {
            v21 = 1.0 / samplearea;
            v22 = v17->samplelight.x * v21;
            v23 = v17->samplelight.y * v21;
            v24 = v17->samplelight.z * v21;
            v17->totallight.light[0].x = v17->totallight.light[0].x + v22;
            v17->totallight.light[0].y = v17->totallight.light[0].y + v23;
            v17->totallight.light[0].z = v17->totallight.light[0].z + v24;
            v17->directlight.x = v22 + v17->directlight.x;
            v17->directlight.y = v17->directlight.y + v23;
            v17->directlight.z = v17->directlight.z + v24;
            m_pMemory = g_Patches.m_Memory.m_pMemory;
          }
          v17 = v19;
        }
        while ( v19 != nullptr );
        v1 = facenum;
        v2 = f;
      }
    }
    v25 = &m_pMemory[g_FacePatches.m_Memory.m_pMemory[v1]];
    if ( v25 != nullptr )
    {
      do
      {
        v26 = v25->ndxNext;
        v27 = nullptr;
        if ( v26 != -1 )
          v27 = &m_pMemory[v26];
        child1 = v25->child1;
        if ( child1 != -1 )
        {
          v29 = child1;
          area = m_pMemory[v29].area;
          v31 = (float *)&m_pMemory[v29];
          child2 = v25->child2;
          v33 = m_pMemory[child2].area;
          v34 = (float *)&m_pMemory[child2];
          v35 = (float)(1.0 / (float)(area + v33)) * area;
          v36 = (float)(1.0 / (float)(area + v33)) * v33;
          v25->totallight.light[0].x = v31[27] * v35;
          v25->totallight.light[0].y = v31[28] * v35;
          v25->totallight.light[0].z = v31[29] * v35;
          v25->totallight.light[0].x = (float)(v34[27] * v36) + v25->totallight.light[0].x;
          v25->totallight.light[0].y = (float)(v34[28] * v36) + v25->totallight.light[0].y;
          v25->totallight.light[0].z = (float)(v34[29] * v36) + v25->totallight.light[0].z;
          v25->directlight.x = v25->totallight.light[0].x;
          v25->directlight.y = v25->totallight.light[0].y;
          v25->directlight.z = v25->totallight.light[0].z;
          m_pMemory = g_Patches.m_Memory.m_pMemory;
        }
        v25 = v27;
      }
      while ( v27 != nullptr );
      v2 = f;
    }
    needsBumpmap_3 = (texinfo.m_Memory.m_pMemory[v2->texinfo].flags & 0x800) != 0;
    x = ambient.x;
    if ( ambient.x != 0.0 || ambient.y != 0.0 || ambient.z != 0.0 )
    {
      for ( i = 0; i < 4; ++i )
      {
        v39 = v2->styles[i];
        if ( v39 == 0xFF )
          break;
        if ( v39 == 0 )
        {
          v40 = 0;
          if ( fl->numsamples > 0 )
          {
            v41 = i;
            v42 = fl->light[v41][0];
            v43 = &fl->numsamples + 1 * v41;
            v44 = 0;
            p_z = &v42->m_vecLighting.z;
            while ( 1 )
            {
              v42[v44 / 0x10].m_vecLighting.x = x + v42[v44 / 0x10].m_vecLighting.x;
              *(p_z - 1) = *(p_z - 1) + ambient.y;
              *p_z = *p_z + ambient.z;
              if ( needsBumpmap_3 )
              {
                v46 = v43[3];
                *(float *)(v46 + v44) = *(float *)(v46 + v44) + ambient.x;
                *(float *)(v46 + v44 + 4) = ambient.y + *(float *)(v46 + v44 + 4);
                *(float *)(v46 + v44 + 8) = ambient.z + *(float *)(v46 + v44 + 8);
                v47 = v43[4];
                *(float *)(v47 + v44) = *(float *)(v47 + v44) + ambient.x;
                v48 = *(float *)(v47 + v44 + 4) + ambient.y;
                v49 = v44 + v47;
                *(float *)(v49 + 4) = v48;
                *(float *)(v49 + 8) = *(float *)(v49 + 8) + ambient.z;
                v50 = v43[5];
                v51 = *(float *)(v50 + v44) + ambient.x;
                v52 = (float *)(v44 + v50);
                *v52 = v51;
                v52[1] = v52[1] + ambient.y;
                v52[2] = v52[2] + ambient.z;
              }
              ++v40;
              v44 += 16;
              p_z += 4;
              if ( v40 >= fl->numsamples )
                break;
              x = ambient.x;
            }
          }
          return;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100100D0
// Name: void BuildFacelights(int,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall BuildFacelights(dface_t *a1@<ebp>, int iThread, int facenum)
{
  dface_t *v3; // edi
  unsigned __int8 v4; // al
  facelight_t *v5; // edi
  int v6; // eax
  LightingValue_t **v7; // esi
  int v8; // esi
  char *v9; // edi
  int v10; // eax
  char *v11; // eax
  char *v12; // eax
  char *v13; // eax
  char *v14; // eax
  char *v15; // eax
  char *v16; // eax
  char *v17; // eax
  __m128 v18; // xmm3
  __m128 v19; // xmm4
  __m128 v20; // xmm0
  __m128 v21; // xmm3
  int v22; // eax
  _DWORD *v23; // ecx
  int v24; // xmm1_4
  int v25; // xmm2_4
  int v26; // xmm1_4
  int v27; // xmm2_4
  int v28; // xmm1_4
  int v29; // xmm2_4
  int v30; // xmm1_4
  int v31; // xmm2_4
  char *v32; // ecx
  int v33; // xmm1_4
  int v34; // xmm2_4
  int v35; // esi
  bool v36; // zf
  IIncremental *v37; // ecx
  directlight_t *i; // esi
  int j; // esi
  int v40; // [esp-18h] [ebp-2B0h]
  _BYTE v41[12]; // [esp-Ch] [ebp-2A4h] BYREF
  lightinfo_t l; // [esp+0h] [ebp-298h] BYREF
  _BYTE sampleInfo[520]; // [esp+78h] [ebp-220h] OVERLAPPED BYREF
  dface_t *v44; // [esp+280h] [ebp-18h]
  facelight_t *fl; // [esp+284h] [ebp-14h]
  int v46; // [esp+288h] [ebp-10h]
  dface_t *f; // [esp+28Ch] [ebp-Ch] BYREF
  void *v48; // [esp+290h] [ebp-8h]
  void *retaddr; // [esp+298h] [ebp+0h]

  f = a1;
  v48 = retaddr;
  if ( !g_bInterrupt )
  {
    if ( g_pIncremental != nullptr )
    {
      ThreadLock();
      ++g_iCurFace;
      ThreadUnlock();
    }
    v3 = &g_pFaces[facenum];
    v3->lightofs = -1;
    *(_DWORD *)v3->styles = -1;
    v4 = g_FacesVisibleToLights.m_Memory.m_pMemory[facenum >> 3];
    v44 = v3;
    if ( ((unsigned __int8)(1 << (facenum & 7)) & v4) != 0
      && (texinfo.m_Memory.m_pMemory[v3->texinfo].flags & 0x404) == 0
      && g_FacePatches.m_Memory.m_pMemory[facenum] != -1 )
    {
      v5 = &facelight[facenum];
      *(_DWORD *)&sampleInfo[512] = v5;
      InitLightinfo(pl: (lightinfo_t *)v41, facenum);
      CalcPoints(pLightInfo: (lightinfo_t *)v41, pFaceLight: v5, ndxFace: facenum);
      InitSampleInfo(l: (const lightinfo_t *)v41, info: (SSE_SampleInfo_t *)&l.isflat, iThread);
      if ( (v5->numsamples & 3) != 0 )
        v6 = v5->numsamples / 4 + 1;
      else
        v6 = v5->numsamples / 4;
      v44->styles[0] = 0;
      v46 = v6;
      if ( *(int *)&sampleInfo[16] > 0 )
      {
        v7 = v5->light[0];
        for ( fl = *(facelight_t **)&sampleInfo[16]; fl != nullptr; fl = (facelight_t *)((char *)fl - 1) )
          *v7++ = (LightingValue_t *)calloc(count: v5->numsamples, size: 0x10u);
        v6 = v46;
      }
      if ( v6 > 0 )
      {
        v46 = 0;
        fl = nullptr;
        *(_DWORD *)&sampleInfo[516] = v6;
        do
        {
          v8 = **(_DWORD **)sampleInfo - v46;
          v9 = (char *)fl + *(_DWORD *)(*(_DWORD *)sampleInfo + 4);
          if ( v8 <= 4 )
          {
            if ( v8 <= 0 )
              v10 = (int)&v9[64 * v8 - 28];
            else
              v10 = (int)(v9 + 36);
          }
          else
          {
            v8 = 4;
            v10 = (int)(v9 + 36);
          }
          *(_QWORD *)&sampleInfo[408] = *(_QWORD *)v10;
          *(_DWORD *)&sampleInfo[416] = *(_DWORD *)(v10 + 8);
          if ( v8 <= 0 )
            v11 = &v9[64 * v8 - 16];
          else
            v11 = v9 + 48;
          *(_DWORD *)&sampleInfo[460] = *(_DWORD *)v11;
          *(_DWORD *)&sampleInfo[464] = *((_DWORD *)v11 + 1);
          *(_DWORD *)&sampleInfo[468] = *((_DWORD *)v11 + 2);
          if ( v8 <= 1 )
            v12 = &v9[64 * v8 - 28];
          else
            v12 = v9 + 100;
          *(_DWORD *)&sampleInfo[420] = *(_DWORD *)v12;
          *(_DWORD *)&sampleInfo[424] = *((_DWORD *)v12 + 1);
          *(_DWORD *)&sampleInfo[428] = *((_DWORD *)v12 + 2);
          if ( v8 <= 1 )
            v13 = &v9[64 * v8 - 16];
          else
            v13 = v9 + 112;
          *(_DWORD *)&sampleInfo[472] = *(_DWORD *)v13;
          *(_DWORD *)&sampleInfo[476] = *((_DWORD *)v13 + 1);
          *(_DWORD *)&sampleInfo[480] = *((_DWORD *)v13 + 2);
          if ( v8 <= 2 )
            v14 = &v9[64 * v8 - 28];
          else
            v14 = v9 + 164;
          *(_DWORD *)&sampleInfo[432] = *(_DWORD *)v14;
          *(_DWORD *)&sampleInfo[436] = *((_DWORD *)v14 + 1);
          *(_DWORD *)&sampleInfo[440] = *((_DWORD *)v14 + 2);
          if ( v8 <= 2 )
            v15 = &v9[64 * v8 - 16];
          else
            v15 = v9 + 176;
          *(_DWORD *)&sampleInfo[484] = *(_DWORD *)v15;
          *(_DWORD *)&sampleInfo[488] = *((_DWORD *)v15 + 1);
          *(_DWORD *)&sampleInfo[492] = *((_DWORD *)v15 + 2);
          if ( v8 <= 3 )
            v16 = &v9[64 * v8 - 28];
          else
            v16 = v9 + 228;
          *(_DWORD *)&sampleInfo[444] = *(_DWORD *)v16;
          *(_DWORD *)&sampleInfo[448] = *((_DWORD *)v16 + 1);
          *(_DWORD *)&sampleInfo[452] = *((_DWORD *)v16 + 2);
          if ( v8 <= 3 )
            v17 = &v9[64 * v8 - 16];
          else
            v17 = v9 + 240;
          *(_DWORD *)&sampleInfo[496] = *(_DWORD *)v17;
          *(_DWORD *)&sampleInfo[500] = *((_DWORD *)v17 + 1);
          *(_DWORD *)&sampleInfo[504] = *((_DWORD *)v17 + 2);
          v18 = _mm_shuffle_ps(*(__m128 *)&sampleInfo[432], *(__m128 *)&sampleInfo[444], 68);
          v19 = _mm_shuffle_ps(*(__m128 *)&sampleInfo[408], *(__m128 *)&sampleInfo[420], 68);
          *(__m128 *)&sampleInfo[340] = _mm_shuffle_ps(
                                          _mm_shuffle_ps(*(__m128 *)&sampleInfo[408], *(__m128 *)&sampleInfo[420], 238),
                                          _mm_shuffle_ps(*(__m128 *)&sampleInfo[432], *(__m128 *)&sampleInfo[444], 238),
                                          136);
          *(__m128 *)&sampleInfo[324] = _mm_shuffle_ps(v19, v18, 221);
          v20 = _mm_shuffle_ps(*(__m128 *)&sampleInfo[460], *(__m128 *)&sampleInfo[472], 68);
          *(__m128 *)&sampleInfo[308] = _mm_shuffle_ps(v19, v18, 136);
          v21 = _mm_shuffle_ps(*(__m128 *)&sampleInfo[484], *(__m128 *)&sampleInfo[496], 68);
          *(__m128 *)&sampleInfo[356] = _mm_shuffle_ps(v20, v21, 136);
          *(__m128 *)&sampleInfo[372] = _mm_shuffle_ps(v20, v21, 221);
          *(__m128 *)&sampleInfo[388] = _mm_shuffle_ps(
                                          _mm_shuffle_ps(*(__m128 *)&sampleInfo[460], *(__m128 *)&sampleInfo[472], 238),
                                          _mm_shuffle_ps(*(__m128 *)&sampleInfo[484], *(__m128 *)&sampleInfo[496], 238),
                                          136);
          ComputeIlluminationPointAndNormalsSSE(
            pos: (const FourVectors *)&sampleInfo[308],
            pInfo: (SSE_SampleInfo_t *)&l.isflat,
            a3: (int)&f,
            a4: (int)v41,
            a5: (FourVectors *)&sampleInfo[356]);
          if ( LODWORD(l.luxelToWorldSpace[1].z) == 0 )
          {
            v22 = 0;
            if ( v8 >= 4 )
            {
              v23 = v9 + 56;
              do
              {
                v24 = *(_DWORD *)&sampleInfo[4 * v22 + 132];
                v25 = *(_DWORD *)&sampleInfo[4 * v22 + 148];
                *(v23 - 2) = *(_DWORD *)&sampleInfo[4 * v22 + 116];
                *(v23 - 1) = v24;
                *v23 = v25;
                v26 = *(_DWORD *)&sampleInfo[4 * v22 + 136];
                v27 = *(_DWORD *)&sampleInfo[4 * v22 + 152];
                v23[14] = *(_DWORD *)&sampleInfo[4 * v22 + 120];
                v23[15] = v26;
                v23[16] = v27;
                v28 = *(_DWORD *)&sampleInfo[4 * v22 + 140];
                v29 = *(_DWORD *)&sampleInfo[4 * v22 + 156];
                v23[30] = *(_DWORD *)&sampleInfo[4 * v22 + 124];
                v23[31] = v28;
                v23[32] = v29;
                v30 = *(_DWORD *)&sampleInfo[4 * v22 + 144];
                v31 = *(_DWORD *)&sampleInfo[4 * v22 + 160];
                v23[46] = *(_DWORD *)&sampleInfo[4 * v22 + 128];
                v23[47] = v30;
                v23[48] = v31;
                v22 += 4;
                v23 += 64;
              }
              while ( v22 < v8 - 3 );
            }
            if ( v22 < v8 )
            {
              v32 = &v9[64 * v22 + 56];
              do
              {
                v33 = *(_DWORD *)&sampleInfo[4 * v22 + 132];
                v34 = *(_DWORD *)&sampleInfo[4 * v22 + 148];
                *((_DWORD *)v32 - 2) = *(_DWORD *)&sampleInfo[4 * v22 + 116];
                *((_DWORD *)v32 - 1) = v33;
                *(_DWORD *)v32 = v34;
                ++v22;
                v32 += 64;
              }
              while ( v22 < v8 );
            }
          }
          v40 = v8;
          v35 = v46;
          GatherSampleLightAt4Points(a1: (int)&f, info: (SSE_SampleInfo_t *)&l.isflat, sampleIdx: v46, numSamples: v40);
          fl = (facelight_t *)((char *)fl + 256);
          v36 = (*(_DWORD *)&sampleInfo[516])-- == 1;
          v46 = v35 + 4;
        }
        while ( !v36 );
        v5 = *(facelight_t **)&sampleInfo[512];
      }
      v37 = g_pIncremental;
      if ( g_pIncremental != nullptr )
      {
        for ( i = activelights; i != nullptr; i = i->next )
        {
          if ( i->light.style == 0 )
          {
            v37->FinishFace(this: v37, a2: i->m_IncrementalID, a3: facenum, a4: iThread);
            v37 = g_pIncremental;
          }
        }
      }
      else
      {
        if ( do_extra != 0 && sampleInfo[28] == 0 )
        {
          for ( j = 0; j < 4; ++j )
          {
            if ( v44->styles[j] == 0xFF )
              break;
            BuildSupersampleFaceLights(info: (SSE_SampleInfo_t *)&l.isflat, l: (lightinfo_t *)v41, lightstyleIndex: j);
          }
        }
        if ( !g_bUseMPI )
          BuildPatchLights(facenum);
        if ( g_bDumpPatches != 0 )
          DumpSamples(ndxFace: facenum, pFaceLight: v5);
        else
          FreeSampleWindings(fl: v5);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100106A0
// Name: public: CNormalList::~CNormalList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNormalList::~CNormalList(CNormalList *this)
{
  CNormalList *v1; // esi
  int i; // ebx
  Vector *m_pMemory; // eax

  v1 = this + 1;
  for ( i = 511; i >= 0; --i )
  {
    v1 = (CNormalList *)((char *)v1 - 20);
    v1->m_Normals.m_Size = 0;
    if ( v1->m_Normals.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v1->m_Normals.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_Normals.m_Memory.m_pMemory);
        v1->m_Normals.m_Memory.m_pMemory = nullptr;
      }
      v1->m_Normals.m_Memory.m_nAllocationCount = 0;
    }
    m_pMemory = v1->m_Normals.m_Memory.m_pMemory;
    v1->m_Normals.m_pElements = v1->m_Normals.m_Memory.m_pMemory;
    if ( v1->m_Normals.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        v1->m_Normals.m_Memory.m_pMemory = nullptr;
      }
      v1->m_Normals.m_Memory.m_nAllocationCount = 0;
    }
  }
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>((CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10010720
// Name: public: CNormalList::CNormalList(void)
// Source: json
//------------------------------------------------------------------------------
CNormalList *__thiscall CNormalList::CNormalList(CNormalList *this)
{
  CNormalList *result; // eax
  CUtlVector<int,CUtlMemory<int,int> > *v2; // edx
  int i; // ecx
  int *p_m_nGrowSize; // edx
  int j; // ecx

  result = this;
  this->m_Normals.m_Memory.m_pMemory = nullptr;
  this->m_Normals.m_Memory.m_nAllocationCount = 0;
  this->m_Normals.m_Memory.m_nGrowSize = 128;
  this->m_Normals.m_Size = 0;
  this->m_Normals.m_pElements = nullptr;
  v2 = this->m_NormalGrid[0][0];
  for ( i = 511; i >= 0; --i )
  {
    v2->m_Memory.m_pMemory = nullptr;
    v2->m_Memory.m_nAllocationCount = 0;
    v2->m_Memory.m_nGrowSize = 0;
    v2->m_Size = 0;
    v2->m_pElements = nullptr;
    ++v2;
  }
  p_m_nGrowSize = &result->m_NormalGrid[0][0][0].m_Memory.m_nGrowSize;
  for ( j = 512; j != 0; --j )
  {
    *p_m_nGrowSize = 16;
    p_m_nGrowSize += 5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10010770
// Name: public: int CNormalList::FindOrAddNormal(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNormalList::FindOrAddNormal(CNormalList *this, const Vector *vNormal)
{
  int j; // ecx
  int v4; // eax
  int v5; // eax
  int v6; // ebx
  CUtlMemory<S3RGBA,int> *v7; // esi
  float x; // xmm0_4
  Vector *v9; // ecx
  int m_nAllocationCount; // eax
  S3RGBA *m_pMemory; // ecx
  int v12; // eax
  int *v13; // ebx
  int m_Size; // esi
  int v15; // eax
  Vector *v16; // ecx
  int v17; // eax
  Vector *v18; // eax
  int gi[3]; // [esp+4h] [ebp-14h] BYREF
  int i; // [esp+10h] [ebp-8h]
  S3RGBA *v23; // [esp+14h] [ebp-4h]

  for ( j = 0; j < 3; gi[j - 1] = v4 <= 0 ? 0 : v4 )
  {
    v4 = (int)(float)((float)((float)((float)(*(float *)((char *)&gi[j] + (char *)vNormal - (char *)gi) + 1.0) * 0.5)
                            * 8.0)
                    - 0.000001);
    gi[j] = v4;
    if ( v4 >= 8 )
      v4 = 8;
    ++j;
  }
  v5 = gi[2] + 8 * (gi[1] + 8 * gi[0]) + 1;
  v6 = *(&this->m_Normals.m_Size + 5 * v5);
  v7 = (CUtlMemory<S3RGBA,int> *)(&this->m_Normals + v5);
  i = 0;
  if ( v6 <= 0 )
  {
LABEL_11:
    m_nAllocationCount = v7->m_nAllocationCount;
    i = this->m_Normals.m_Size;
    if ( v6 + 1 > m_nAllocationCount )
      CUtlMemory<int,int>::Grow(this: v7, num: v6 - m_nAllocationCount + 1);
    ++v7[1].m_pMemory;
    m_pMemory = v7->m_pMemory;
    v12 = (int)v7[1].m_pMemory - v6 - 1;
    v7[1].m_nAllocationCount = (int)v7->m_pMemory;
    if ( v12 > 0 )
      _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * v12);
    v13 = (int *)&v7->m_pMemory[v6];
    if ( v13 != nullptr )
      *v13 = i;
    m_Size = this->m_Normals.m_Size;
    v15 = this->m_Normals.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > v15 )
      CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>::Grow(
        (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
        num: m_Size - v15 + 1);
    ++this->m_Normals.m_Size;
    v16 = this->m_Normals.m_Memory.m_pMemory;
    v17 = this->m_Normals.m_Size - m_Size - 1;
    this->m_Normals.m_pElements = this->m_Normals.m_Memory.m_pMemory;
    if ( v17 > 0 )
      _V_memmove(dest: &v16[m_Size + 1], src: &v16[m_Size], count: 12 * v17);
    v18 = &this->m_Normals.m_Memory.m_pMemory[m_Size];
    if ( v18 != nullptr )
      *v18 = *vNormal;
    return m_Size;
  }
  else
  {
    x = vNormal->x;
    v23 = v7->m_pMemory;
    while ( 1 )
    {
      v9 = &this->m_Normals.m_Memory.m_pMemory[*(_DWORD *)v23];
      if ( x == v9->x && vNormal->y == v9->y && vNormal->z == v9->z )
        return (int)*v23;
      ++v23;
      if ( ++i >= v6 )
        goto LABEL_11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010940
// Name: void SaveVertexNormals(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SaveVertexNormals()
{
  int v0; // ebx
  int v1; // ecx
  float v2; // xmm0_4
  __int16 *v3; // ebx
  int v4; // esi
  int v5; // edi
  int v6; // eax
  unsigned __int16 v7; // ax
  int v8; // ecx
  int m_Size; // esi
  CNormalList v10; // [esp+8h] [ebp-282Ch] BYREF
  Vector vNormal; // [esp+281Ch] [ebp-18h] BYREF
  int v12; // [esp+2828h] [ebp-Ch]
  int v13; // [esp+282Ch] [ebp-8h]
  int *v14; // [esp+2830h] [ebp-4h]

  CNormalList::CNormalList(this: &v10);
  v0 = 0;
  v1 = 0;
  g_numvertnormalindices = 0;
  v12 = 0;
  if ( (int)numfaces > 0 )
  {
    v2 = 0.0;
    v13 = 0;
    v14 = (int *)&unk_10A33258;
    do
    {
      v3 = (__int16 *)((char *)&g_pFaces->numedges + v0);
      v4 = 0;
      if ( *v3 > 0 )
      {
        v5 = 0;
        do
        {
          v6 = *v14;
          if ( *v14 != 0 )
          {
            vNormal.x = *(float *)(v6 + v5);
            vNormal.y = *(float *)(v6 + v5 + 4);
            v2 = *(float *)(v6 + v5 + 8);
          }
          else
          {
            vNormal.x = 0.0;
            vNormal.y = 0.0;
          }
          vNormal.z = v2;
          if ( v1 == 256000 )
            _Error(a1: "g_numvertnormalindices == MAX_MAP_VERTNORMALINDICES");
          v7 = CNormalList::FindOrAddNormal(this: &v10, &vNormal);
          v8 = g_numvertnormalindices;
          v2 = 0.0;
          g_vertnormalindices[g_numvertnormalindices] = v7;
          v1 = v8 + 1;
          g_numvertnormalindices = v1;
          ++v4;
          v5 += 12;
        }
        while ( v4 < *v3 );
      }
      v14 += 7;
      v0 = v13 + 56;
      ++v12;
      v13 += 56;
    }
    while ( v12 < (int)numfaces );
  }
  m_Size = v10.m_Normals.m_Size;
  if ( v10.m_Normals.m_Size > 256000 )
    _Error(a1: "g_numvertnormals > MAX_MAP_VERTNORMALS");
  g_numvertnormals = m_Size;
  memcpy(
    dst: (unsigned __int8 *)g_vertnormals,
    src: (unsigned __int8 *)v10.m_Normals.m_Memory.m_pMemory,
    count: 12 * m_Size);
  CNormalList::~CNormalList(this: &v10);
}

//------------------------------------------------------------------------------
// Address: 0x10010A90
// Name: void PrecompLightmapOffsets(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrecompLightmapOffsets()
{
  int v0; // edx
  int v1; // esi
  char *v2; // edx
  int v3; // edi
  int i; // ecx
  int v5; // esi
  int v6; // eax
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *v7; // edi
  int m_Size; // ecx
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // edx
  int v11; // eax
  int v12; // [esp+Ch] [ebp-8h]
  int v13; // [esp+Ch] [ebp-8h]
  int facenum; // [esp+10h] [ebp-4h]

  v0 = 0;
  v1 = 0;
  facenum = 0;
  if ( (int)numfaces > 0 )
  {
    v12 = 0;
    do
    {
      v2 = (char *)g_pFaces + v0;
      v3 = *((__int16 *)v2 + 5);
      if ( (texinfo.m_Memory.m_pMemory[v3].flags & 0x404) == 0 )
      {
        if ( dlight_map != 0 )
          v2[17] = 0;
        for ( i = 0; i < 4; ++i )
        {
          if ( v2[i + 16] == -1 )
            break;
        }
        if ( i != 0 )
        {
          v5 = v1 + 4 * i;
          *((_DWORD *)v2 + 5) = v5;
          v6 = i * (*((_DWORD *)v2 + 9) + 1) * (*((_DWORD *)v2 + 10) + 1);
          if ( (texinfo.m_Memory.m_pMemory[v3].flags & 0x800) != 0 )
            v1 = 16 * v6 + v5;
          else
            v1 = v5 + 4 * v6;
        }
      }
      v0 = v12 + 56;
      ++facenum;
      v12 += 56;
    }
    while ( facenum < (int)numfaces );
  }
  v7 = pdlightdata;
  if ( g_pIncremental == nullptr || pdlightdata->m_Size == 0 )
  {
    pdlightdata->m_Size = 0;
    m_Size = v7->m_Size;
    v13 = m_Size;
    if ( v1 != 0 )
    {
      m_nAllocationCount = v7->m_Memory.m_nAllocationCount;
      if ( m_Size + v1 > m_nAllocationCount )
      {
        CUtlMemory<char,int>::Grow(this: &v7->m_Memory, num: v1 + m_Size - m_nAllocationCount);
        m_Size = v13;
      }
      v7->m_Size += v1;
      m_pMemory = v7->m_Memory.m_pMemory;
      v11 = v7->m_Size - m_Size - v1;
      v7->m_pElements = v7->m_Memory.m_pMemory;
      if ( v11 > 0 && v1 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + v1], src: &m_pMemory[m_Size], count: v11);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100780D0
// Name: void GetBumpNormals(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector __near * const)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetBumpNormals(
        const Vector *sVect,
        const Vector *tVect,
        const Vector *flatNormal,
        const Vector *phongNormal,
        Vector *bumpNormals)
{
  bool v5; // bl
  const TableVector *v6; // esi
  matrix3x4_t smoothBasis; // [esp+Ch] [ebp-30h] BYREF

  v5 = (float)((float)((float)(flatNormal->y * (float)((float)(tVect->x * sVect->z) - (float)(sVect->x * tVect->z)))
                     + (float)(flatNormal->x * (float)((float)(tVect->z * sVect->y) - (float)(tVect->y * sVect->z))))
             + (float)(flatNormal->z * (float)((float)(sVect->x * tVect->y) - (float)(tVect->x * sVect->y)))) < 0.0;
  CrossProduct(v1: &phongNormal->x, v2: &sVect->x, cross: smoothBasis.m_flMatVal[1]);
  VectorNormalize(vec: (Vector *)smoothBasis.m_flMatVal[1]);
  CrossProduct(v1: smoothBasis.m_flMatVal[1], v2: &phongNormal->x, cross: (float *)&smoothBasis);
  VectorNormalize(vec: (Vector *)&smoothBasis);
  *(Vector *)&smoothBasis.m_flMatVal[2][0] = *phongNormal;
  if ( v5 )
  {
    *(_QWORD *)&smoothBasis.m_flMatVal[1][0] ^= 0x8000000080000000uLL;
    smoothBasis.m_flMatVal[1][2] = -smoothBasis.m_flMatVal[1][2];
  }
  v6 = g_localBumpBasis;
  do
  {
    VectorIRotate(
      in1: &v6->x,
      in2: &smoothBasis,
      out: (float *)((char *)&v6->x + (char *)bumpNormals - (char *)g_localBumpBasis));
    ++v6;
  }
  while ( (int)v6 < (int)&unk_1010A8C4 );
}
