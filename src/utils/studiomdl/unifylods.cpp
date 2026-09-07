// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/studiomdl/unifylods.cpp
// Functions: 31
// ============================================================

#include "utils\studiomdl\unifylods.h"

//------------------------------------------------------------------------------
// Address: 0x00465250
// Name: SortBoneWeightByWeight
// Source: json
//------------------------------------------------------------------------------
void __cdecl SortBoneWeightByWeight(s_boneweight_t *boneWeight)
{
  s_boneweight_t *v1; // ebx
  int numbones; // ecx
  int v3; // esi
  int v4; // edi
  unsigned int v5; // ecx
  float *v6; // eax
  float v7; // xmm0_4
  int v8; // edx
  float v9; // xmm0_4
  int v10; // edx
  float v11; // xmm0_4
  int v12; // edx
  float v13; // xmm0_4
  int v14; // edx
  float *v15; // eax
  int v16; // ecx
  float v17; // xmm0_4
  int v18; // edx

  v1 = boneWeight;
  numbones = boneWeight->numbones;
  if ( boneWeight->numbones > 1 )
  {
    do
    {
      v3 = 0;
      v4 = numbones - 1;
      if ( numbones >= 5 )
      {
        v5 = ((unsigned int)(numbones - 5) >> 2) + 1;
        v6 = &v1->weight[1];
        v3 = 4 * v5;
        do
        {
          v7 = *(v6 - 1);
          if ( v7 < *v6 )
          {
            v8 = *((_DWORD *)v6 - 4);
            *(v6 - 4) = *(v6 - 3);
            *(v6 - 1) = *v6;
            *((_DWORD *)v6 - 3) = v8;
            *v6 = v7;
          }
          v9 = *v6;
          if ( *v6 < v6[1] )
          {
            v10 = *((_DWORD *)v6 - 3);
            *(v6 - 3) = *(v6 - 2);
            *v6 = v6[1];
            *((_DWORD *)v6 - 2) = v10;
            v6[1] = v9;
          }
          v11 = v6[1];
          if ( v11 < v6[2] )
          {
            v12 = *((_DWORD *)v6 - 2);
            *(v6 - 2) = *(v6 - 1);
            v6[1] = v6[2];
            *((_DWORD *)v6 - 1) = v12;
            v6[2] = v11;
          }
          v13 = v6[2];
          if ( v13 < v6[3] )
          {
            v14 = *((_DWORD *)v6 - 1);
            *(v6 - 1) = *v6;
            v6[2] = v6[3];
            *(_DWORD *)v6 = v14;
            v6[3] = v13;
          }
          v6 += 4;
          --v5;
        }
        while ( v5 != 0 );
        v1 = boneWeight;
      }
      if ( v3 < v4 )
      {
        v15 = &v1->weight[v3 + 1];
        v16 = v4 - v3;
        do
        {
          v17 = *(v15 - 1);
          if ( v17 < *v15 )
          {
            v18 = *((_DWORD *)v15 - 4);
            *(v15 - 4) = *(v15 - 3);
            *(v15 - 1) = *v15;
            *((_DWORD *)v15 - 3) = v18;
            *v15 = v17;
          }
          ++v15;
          --v16;
        }
        while ( v16 != 0 );
      }
      numbones = v4;
    }
    while ( v4 > 1 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00465360
// Name: SortBoneWeightByIndex
// Source: json
//------------------------------------------------------------------------------
void __cdecl SortBoneWeightByIndex(s_boneweight_t *boneWeight)
{
  s_boneweight_t *v1; // ebx
  int numbones; // ecx
  int v3; // esi
  int v4; // edi
  unsigned int v5; // ecx
  float *v6; // eax
  int v7; // edx
  int v8; // xmm0_4
  int v9; // edx
  float v10; // xmm0_4
  int v11; // edx
  int v12; // xmm0_4
  int v13; // edx
  int v14; // xmm0_4
  float *v15; // eax
  int v16; // ecx
  int v17; // edx
  int v18; // xmm0_4

  v1 = boneWeight;
  numbones = boneWeight->numbones;
  if ( boneWeight->numbones > 1 )
  {
    do
    {
      v3 = 0;
      v4 = numbones - 1;
      if ( numbones >= 5 )
      {
        v5 = ((unsigned int)(numbones - 5) >> 2) + 1;
        v6 = &v1->weight[1];
        v3 = 4 * v5;
        do
        {
          v7 = *((_DWORD *)v6 - 4);
          if ( v7 > *((_DWORD *)v6 - 3) )
          {
            v8 = *((_DWORD *)v6 - 1);
            *(v6 - 4) = *(v6 - 3);
            *(v6 - 1) = *v6;
            *((_DWORD *)v6 - 3) = v7;
            *(_DWORD *)v6 = v8;
          }
          v9 = *((_DWORD *)v6 - 3);
          if ( v9 > *((_DWORD *)v6 - 2) )
          {
            v10 = *v6;
            *(v6 - 3) = *(v6 - 2);
            *v6 = v6[1];
            *((_DWORD *)v6 - 2) = v9;
            v6[1] = v10;
          }
          v11 = *((_DWORD *)v6 - 2);
          if ( v11 > *((_DWORD *)v6 - 1) )
          {
            v12 = *((_DWORD *)v6 + 1);
            *(v6 - 2) = *(v6 - 1);
            v6[1] = v6[2];
            *((_DWORD *)v6 - 1) = v11;
            *((_DWORD *)v6 + 2) = v12;
          }
          v13 = *((_DWORD *)v6 - 1);
          if ( v13 > *(_DWORD *)v6 )
          {
            v14 = *((_DWORD *)v6 + 2);
            *(v6 - 1) = *v6;
            v6[2] = v6[3];
            *(_DWORD *)v6 = v13;
            *((_DWORD *)v6 + 3) = v14;
          }
          v6 += 4;
          --v5;
        }
        while ( v5 != 0 );
        v1 = boneWeight;
      }
      if ( v3 < v4 )
      {
        v15 = &v1->weight[v3 + 1];
        v16 = v4 - v3;
        do
        {
          v17 = *((_DWORD *)v15 - 4);
          if ( v17 > *((_DWORD *)v15 - 3) )
          {
            v18 = *((_DWORD *)v15 - 1);
            *(v15 - 4) = *(v15 - 3);
            *(v15 - 1) = *v15;
            *((_DWORD *)v15 - 3) = v17;
            *(_DWORD *)v15 = v18;
          }
          ++v15;
          --v16;
        }
        while ( v16 != 0 );
      }
      numbones = v4;
    }
    while ( v4 > 1 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00465470
// Name: bool CompareNormalFuzzy(class Vector const __near &,class Vector const __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CompareNormalFuzzy(const Vector *n1, const Vector *n2, float *flError)
{
  float v3; // xmm0_4
  bool v4; // cf
  Vector v1; // [esp+0h] [ebp-18h] BYREF
  Vector v2; // [esp+Ch] [ebp-Ch] BYREF

  if ( (_S1_2 & 1) == 0 )
  {
    _S1_2 |= 1u;
    __libm_sse2_cos(x: *(long double *)&v1.x);
    flEpsilon = 0.1745329201221466;
  }
  v1 = *n1;
  v2 = *n2;
  VectorNormalize(vec: &v1);
  VectorNormalize(vec: &v2);
  v3 = (float)((float)(v2.x * v1.x) + (float)(v2.y * v1.y)) + (float)(v2.z * v1.z);
  v4 = v3 < flEpsilon;
  *flError = 1.0 - v3;
  return !v4;
}

//------------------------------------------------------------------------------
// Address: 0x00465550
// Name: bool CompareTangentSFuzzy(class Vector4D const __near &,class Vector4D const __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CompareTangentSFuzzy(const Vector4D *n1, const Vector4D *n2, float *flError)
{
  float w; // xmm0_4
  float v4; // xmm1_4
  float v6; // xmm0_4
  bool v7; // cf
  Vector4D v1; // [esp+0h] [ebp-20h] BYREF
  Vector4D v2; // [esp+10h] [ebp-10h] BYREF

  if ( (_S2_0 & 1) == 0 )
  {
    _S2_0 |= 1u;
    __libm_sse2_cos(x: *(long double *)&v1.x);
    flEpsilon_0 = 0.1745329201221466;
  }
  v1.x = n1->x;
  v1.y = n1->y;
  v1.z = n1->z;
  w = n1->w;
  v2.x = n2->x;
  v2.y = n2->y;
  v2.z = n2->z;
  v4 = n2->w;
  v1.w = w;
  v2.w = v4;
  if ( w == v4 )
  {
    VectorNormalize(vec: (Vector *)&v1);
    VectorNormalize(vec: (Vector *)&v2);
    v6 = (float)((float)(v2.x * v1.x) + (float)(v2.y * v1.y)) + (float)(v2.z * v1.z);
    v7 = v6 < flEpsilon_0;
    *flError = 1.0 - v6;
    return !v7;
  }
  else
  {
    *flError = 2.0;
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00465660
// Name: bool CompareBoneWeightsFuzzy(struct s_boneweight_t const __near &,struct s_boneweight_t const __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CompareBoneWeightsFuzzy(const s_boneweight_t *b1, const s_boneweight_t *b2, float *flError)
{
  int numbones; // ebx
  int v4; // esi
  int *bone; // eax
  int v6; // ecx
  int *v7; // edx
  int v9; // ecx
  float *weight; // esi
  int v11; // edi
  float v12; // xmm0_4
  int v13; // ecx
  float *v14; // esi
  float v15; // xmm0_4
  int pBoneIndexMap2[3]; // [esp+Ch] [ebp-20h] BYREF
  int pBoneIndexMap1[3]; // [esp+18h] [ebp-14h]
  int v18; // [esp+24h] [ebp-8h]
  int nMatchingBones; // [esp+28h] [ebp-4h]

  numbones = b2->numbones;
  v4 = 0;
  nMatchingBones = 0;
  if ( numbones > 0 )
    memset(pBoneIndexMap2, 0xFFu, 4 * numbones);
  v18 = b1->numbones;
  if ( v18 <= 0 )
    goto LABEL_13;
  bone = b1->bone;
  do
  {
    v6 = 0;
    pBoneIndexMap1[v4] = -1;
    if ( numbones > 0 )
    {
      v7 = b2->bone;
      while ( *v7 != *bone )
      {
        ++v6;
        ++v7;
        if ( v6 >= numbones )
          goto LABEL_11;
      }
      ++nMatchingBones;
      pBoneIndexMap1[v4] = v6;
      pBoneIndexMap2[v6] = v4;
    }
LABEL_11:
    ++v4;
    ++bone;
  }
  while ( v4 < v18 );
  if ( nMatchingBones != 0 )
  {
    v9 = 0;
    *flError = 0.0;
    if ( b1->numbones > 0 )
    {
      weight = b1->weight;
      do
      {
        v11 = pBoneIndexMap1[v9];
        v12 = *weight;
        if ( v11 != -1 )
          v12 = fabs(v12 - b2->weight[v11]);
        ++v9;
        *flError = (float)(v12 * v12) + *flError;
        ++weight;
      }
      while ( v9 < b1->numbones );
    }
    v13 = 0;
    if ( b2->numbones > 0 )
    {
      v14 = b2->weight;
      do
      {
        if ( pBoneIndexMap2[v13] == -1 )
          *flError = (float)(*v14 * *v14) + *flError;
        ++v13;
        ++v14;
      }
      while ( v13 < b2->numbones );
    }
    v15 = *flError / fsqrt((float)(b2->numbones + b1->numbones));
    *flError = v15;
    return v15 <= 0.050000001;
  }
  else
  {
LABEL_13:
    *flError = 3.4028235e38;
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004657B0
// Name: int FindMaterialByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindMaterialByName(char *pMaterialName)
{
  unsigned int v1; // kr00_4
  void *v2; // esp
  int v3; // esi
  s_texture_t *i; // edi
  char v6[12]; // [esp+0h] [ebp-Ch] BYREF

  v1 = strlen(pMaterialName);
  v2 = alloca(v1 + 1);
  V_FileBase(in: pMaterialName, out: v6, maxlen: v1 + 1);
  v3 = 0;
  if ( g_numtextures <= 0 )
    return -1;
  for ( i = g_texture; _V_stricmp(s1: pMaterialName, s2: i->name) != 0; ++i )
  {
    if ( ++v3 >= g_numtextures )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00465830
// Name: CollapseBoneWeights
// Source: json
//------------------------------------------------------------------------------
void __usercall CollapseBoneWeights(s_boneweight_t *boneWeight@<esi>)
{
  int *v1; // eax
  int v2; // edx
  float *weight; // ecx
  float *v4; // edi
  int *v5; // eax
  int v6; // ebx
  s_boneweight_t *v7; // [esp+0h] [ebp-18h]
  int *v8; // [esp+4h] [ebp-14h]
  int j; // [esp+8h] [ebp-10h]
  int i; // [esp+Ch] [ebp-Ch]
  int *v11; // [esp+10h] [ebp-8h]
  int *bone; // [esp+14h] [ebp-4h]

  SortBoneWeightByIndex(boneWeight: v7);
  i = 0;
  if ( boneWeight->numbones - 1 > 0 )
  {
    bone = boneWeight->bone;
    v1 = &boneWeight->bone[1];
    v2 = 1;
    weight = boneWeight->weight;
    v4 = &boneWeight->weight[1];
    v8 = &boneWeight->bone[1];
    v11 = &boneWeight->bone[1];
    while ( 1 )
    {
      if ( *bone == *v1 )
      {
        *weight = *v4 + *weight;
        j = v2;
        if ( v2 < boneWeight->numbones - 1 )
        {
          v5 = v11;
          do
          {
            v6 = v5[1];
            ++j;
            v5[3] = v5[4];
            *v5++ = v6;
          }
          while ( j < boneWeight->numbones - 1 );
          v1 = v8;
        }
        --boneWeight->numbones;
        --i;
        --bone;
        --v1;
        --v4;
        --weight;
        --v2;
        --v11;
      }
      v8 = v1 + 1;
      ++bone;
      ++v11;
      ++v4;
      ++weight;
      ++v2;
      if ( ++i >= boneWeight->numbones - 1 )
        break;
      ++v1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00465900
// Name: AreBoneWeightsEqual
// Source: json
//------------------------------------------------------------------------------
char __cdecl AreBoneWeightsEqual(const s_boneweight_t *b1, const s_boneweight_t *b2)
{
  const s_boneweight_t *v2; // eax
  int numbones; // ebx
  const s_boneweight_t *v4; // edi
  int v5; // edx
  int v7; // esi
  int v8; // eax
  int *v9; // ecx
  int v10; // ecx
  float *i; // edx
  int pBoneIndexMap[3]; // [esp+8h] [ebp-14h]
  int nMatchingBones; // [esp+14h] [ebp-8h]
  int *bone; // [esp+18h] [ebp-4h]

  v2 = b1;
  numbones = b1->numbones;
  v4 = b2;
  v5 = b2->numbones;
  if ( b1->numbones != b2->numbones )
    return 0;
  v7 = 0;
  nMatchingBones = 0;
  if ( numbones > 0 )
  {
    bone = b1->bone;
    do
    {
      v8 = 0;
      pBoneIndexMap[v7] = -1;
      if ( v5 > 0 )
      {
        v9 = b2->bone;
        while ( *v9 != *bone )
        {
          ++v8;
          ++v9;
          if ( v8 >= v5 )
            goto LABEL_11;
        }
        ++nMatchingBones;
        pBoneIndexMap[v7] = v8;
      }
LABEL_11:
      ++bone;
      ++v7;
    }
    while ( v7 < numbones );
    v2 = b1;
    v4 = b2;
  }
  if ( nMatchingBones != numbones )
    return 0;
  v10 = 0;
  if ( numbones > 0 )
  {
    for ( i = v2->weight; *i == v4->weight[pBoneIndexMap[v10]]; ++i )
    {
      if ( ++v10 >= numbones )
        return 1;
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004659B0
// Name: SpewBoneInfo
// Source: json
//------------------------------------------------------------------------------
void __cdecl SpewBoneInfo(int globalBoneID, int depth)
{
  s_bonetable_t *v2; // edi
  int v3; // esi
  int i; // esi
  int v5; // esi
  int *p_parent; // edi

  v2 = &g_bonetable[globalBoneID];
  if ( g_bPrintBones )
  {
    if ( 2 * depth > 0 )
    {
      v3 = 2 * depth;
      do
      {
        printf(format: " ");
        --v3;
      }
      while ( v3 != 0 );
    }
    printf(format: "%d \"%s\" ", depth, v2->name);
  }
  for ( i = 0; i < 8; ++i )
  {
    if ( ((1024 << i) & v2->flags) != 0 )
    {
      if ( g_bPrintBones )
        printf(format: "lod%d ", i);
      ++g_NumBonesInLOD[i];
    }
  }
  if ( g_bPrintBones )
    printf(format: "\n");
  v5 = 0;
  if ( (int)g_numbones > 0 )
  {
    p_parent = &g_bonetable[0].parent;
    do
    {
      if ( *p_parent == globalBoneID )
        SpewBoneInfo(globalBoneID: v5, depth: depth + 1);
      ++v5;
      p_parent += 116;
    }
    while ( v5 < (int)g_numbones );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00465A90
// Name: void MarkParentBoneLODs(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MarkParentBoneLODs()
{
  int *p_parent; // edx
  unsigned int v1; // esi
  int parent; // eax
  int i; // ecx
  int v4; // eax

  if ( (int)g_numbones > 0 )
  {
    p_parent = &g_bonetable[0].parent;
    v1 = g_numbones;
    do
    {
      parent = *p_parent;
      for ( i = p_parent[72] & 0x3FC00; parent != -1; parent = g_bonetable[v4].parent )
      {
        v4 = parent;
        g_bonetable[v4].flags |= i;
      }
      p_parent += 116;
      --v1;
    }
    while ( v1 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00465AE0
// Name: public: VertexInfo_t::VertexInfo_t(struct VertexInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
VertexInfo_t *__thiscall VertexInfo_t::VertexInfo_t(VertexInfo_t *this, const VertexInfo_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00465B60
// Name: void SpewBoneUsageStats(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SpewBoneUsageStats()
{
  int i; // esi

  *(_QWORD *)g_NumBonesInLOD = 0;
  *(_QWORD *)&g_NumBonesInLOD[2] = 0;
  *(_QWORD *)&g_NumBonesInLOD[4] = 0;
  *(_QWORD *)&g_NumBonesInLOD[6] = 0;
  if ( g_numbones != 0 )
  {
    SpewBoneInfo(globalBoneID: 0, depth: 0);
    if ( g_bPrintBones )
    {
      for ( i = 0; i < g_ScriptLODs.m_Size; ++i )
        printf(format: "\t%d bones used in lod %d\n", g_NumBonesInLOD[i], i);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00465C80
// Name: struct s_source_t __near * GetModelLODSource(char const __near *,struct LodScriptData_t const __near &,bool __near *)
// Source: json
//------------------------------------------------------------------------------
s_source_t *__cdecl GetModelLODSource(char *pModelName, const LodScriptData_t *scriptLOD, bool *pFound)
{
  void *v3; // esp
  _BYTE *v4; // eax
  int v5; // esi
  int v6; // ebx
  char v8[12]; // [esp+0h] [ebp-Ch] BYREF
  char *str; // [esp+14h] [ebp+8h]

  v3 = alloca(_V_strlen(str: pModelName) + 1);
  str = strcpy(v8, pModelName);
  strrchr(string: (unsigned __int8 *)v8, chr: 0x2Eu);
  if ( v4 != nullptr )
    *v4 = 0;
  v5 = 0;
  if ( scriptLOD->modelReplacements.m_Size <= 0 )
  {
LABEL_7:
    *pFound = false;
    return nullptr;
  }
  else
  {
    v6 = 0;
    while ( _V_stricmp(s1: str, s2: scriptLOD->modelReplacements.m_Memory.m_pMemory[v6].m_pSrcName) != 0 )
    {
      ++v5;
      ++v6;
      if ( v5 >= scriptLOD->modelReplacements.m_Size )
        goto LABEL_7;
    }
    *pFound = true;
    return scriptLOD->modelReplacements.m_Memory.m_pMemory[v5].m_pSource;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00465D20
// Name: FindOrCullMesh
// Source: json
//------------------------------------------------------------------------------
s_mesh_t *__cdecl FindOrCullMesh(int nLodID, s_source_t *pSrc, int nMaterialID)
{
  int v3; // ebx
  int v4; // esi
  LodScriptData_t *m_pMemory; // eax
  int v6; // esi
  int v7; // edi
  int v8; // ebx
  int nummeshes; // edx
  int v10; // eax
  int *i; // ecx
  char baseRemovalName[260]; // [esp+Ch] [ebp-208h] BYREF
  char baseMeshName[260]; // [esp+110h] [ebp-104h] BYREF

  v3 = nMaterialID;
  v4 = MaterialToTexture(material: nMaterialID);
  if ( v4 == -1 )
    MdlError(fmt: "Unknown Texture for Material %d\n", nMaterialID);
  V_FileBase(in: g_texture[v4].name, out: baseMeshName, maxlen: 259);
  m_pMemory = g_ScriptLODs.m_Memory.m_pMemory;
  v6 = nLodID;
  v7 = 0;
  if ( g_ScriptLODs.m_Memory.m_pMemory[nLodID].meshRemovals.m_Size > 0 )
  {
    v8 = 0;
    while ( 1 )
    {
      V_FileBase(in: m_pMemory[v6].meshRemovals.m_Memory.m_pMemory[v8].m_pSrcName, out: baseRemovalName, maxlen: 259);
      if ( _V_stricmp(s1: baseRemovalName, s2: baseMeshName) == 0 )
        return nullptr;
      m_pMemory = g_ScriptLODs.m_Memory.m_pMemory;
      ++v7;
      ++v8;
      if ( v7 >= g_ScriptLODs.m_Memory.m_pMemory[v6].meshRemovals.m_Size )
      {
        v3 = nMaterialID;
        break;
      }
    }
  }
  nummeshes = pSrc->nummeshes;
  v10 = 0;
  if ( nummeshes <= 0 )
    return nullptr;
  for ( i = pSrc->meshindex; *i != v3; ++i )
  {
    if ( ++v10 >= nummeshes )
      return nullptr;
  }
  return &pSrc->mesh[pSrc->meshindex[v10]];
}

//------------------------------------------------------------------------------
// Address: 0x00465E10
// Name: FindVertexWithinVertexDictionary
// Source: json
//------------------------------------------------------------------------------
int __usercall FindVertexWithinVertexDictionary@<eax>(
        const VertexInfo_t *find@<edi>,
        int nStartVert@<ecx>,
        char fIgnore@<al>,
        const CVertexDictionary *vertexDict,
        int nEndVert)
{
  int v6; // ecx
  float v7; // xmm2_4
  float v8; // xmm3_4
  int i; // esi
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  bool v14; // al
  bool v15; // al
  float v16; // xmm0_4
  int v18; // [esp+0h] [ebp-44h]
  int v19; // [esp+4h] [ebp-40h]
  int v20; // [esp+8h] [ebp-3Ch]
  int v21; // [esp+Ch] [ebp-38h]
  int v22; // [esp+10h] [ebp-34h]
  int nBestIndex; // [esp+14h] [ebp-30h]
  int nVertexIndex; // [esp+18h] [ebp-2Ch]
  unsigned __int64 flMinTangentSError; // [esp+1Ch] [ebp-28h]
  float flMinBoneWeightError; // [esp+24h] [ebp-20h]
  float flMinTexcoordError; // [esp+28h] [ebp-1Ch]
  float flMinPositionError; // [esp+2Ch] [ebp-18h]
  float flTangentSError; // [esp+30h] [ebp-14h] BYREF
  float flNormalError; // [esp+34h] [ebp-10h] BYREF
  float flBoneWeightError; // [esp+38h] [ebp-Ch] BYREF
  float flTexcoordError; // [esp+3Ch] [ebp-8h]
  float flPositionError; // [esp+40h] [ebp-4h]

  v6 = fIgnore & 1;
  v7 = 0.0;
  v8 = 0.0;
  nBestIndex = -1;
  flPositionError = 0.0;
  flNormalError = 0.0;
  flTangentSError = 0.0;
  flTexcoordError = 0.0;
  flBoneWeightError = 0.0;
  flMinPositionError = 3.4028235e38;
  flMinTangentSError = 0x7F7FFFFF7F7FFFFFLL;
  flMinTexcoordError = 3.4028235e38;
  flMinBoneWeightError = 3.4028235e38;
  v22 = v6;
  if ( (fIgnore & 1) != 0 )
  {
    flMinPositionError = 0.0;
    flPositionError = 0.0;
  }
  v21 = fIgnore & 2;
  if ( (fIgnore & 2) != 0 )
  {
    v8 = 0.0;
    flMinTexcoordError = 0.0;
    flTexcoordError = 0.0;
  }
  v20 = fIgnore & 4;
  if ( (fIgnore & 4) != 0 )
  {
    flMinBoneWeightError = 0.0;
    flBoneWeightError = 0.0;
  }
  v19 = fIgnore & 8;
  if ( (fIgnore & 8) != 0 )
  {
    HIDWORD(flMinTangentSError) = 0;
    flNormalError = 0.0;
  }
  v18 = fIgnore & 0x10;
  if ( (fIgnore & 0x10) != 0 )
  {
    LODWORD(flMinTangentSError) = 0;
    flTangentSError = 0.0;
  }
  nVertexIndex = nStartVert;
  if ( nStartVert < nEndVert )
  {
    for ( i = nStartVert; ; ++i )
    {
      if ( v6 != 0
        || (v10 = find->m_Position.y - vertexDict->m_Verts.m_Memory.m_pMemory[i].m_Position.y,
            v11 = find->m_Position.z - vertexDict->m_Verts.m_Memory.m_pMemory[i].m_Position.z,
            v7 = (float)((float)((float)(find->m_Position.x - vertexDict->m_Verts.m_Memory.m_pMemory[i].m_Position.x)
                               * (float)(find->m_Position.x - vertexDict->m_Verts.m_Memory.m_pMemory[i].m_Position.x))
                       + (float)(v10 * v10))
               + (float)(v11 * v11),
            flPositionError = v7,
            v7 <= 0.0025000002) )
      {
        if ( v21 != 0
          || (v12 = fabs(vertexDict->m_Verts.m_Memory.m_pMemory[i].m_TexCoord.x - find->m_TexCoord.x),
              v13 = fabs(vertexDict->m_Verts.m_Memory.m_pMemory[i].m_TexCoord.y - find->m_TexCoord.y),
              v8 = (float)(v13 * v13) + (float)(v12 * v12),
              flTexcoordError = v8,
              v8 <= 0.000099999997) )
        {
          if ( v20 != 0
            || CompareBoneWeightsFuzzy(
                 b1: &find->m_BoneWeight,
                 b2: &vertexDict->m_Verts.m_Memory.m_pMemory[i].m_BoneWeight,
                 flError: &flBoneWeightError) )
          {
            if ( v19 != 0
              || (v14 = CompareNormalFuzzy(
                          n1: &find->m_Normal,
                          n2: &vertexDict->m_Verts.m_Memory.m_pMemory[i].m_Normal,
                          flError: &flNormalError),
                  v7 = flPositionError,
                  v8 = flTexcoordError,
                  v14) )
            {
              if ( v18 != 0
                || (v15 = CompareTangentSFuzzy(
                            n1: &find->m_TangentS,
                            n2: &vertexDict->m_Verts.m_Memory.m_pMemory[i].m_TangentS,
                            flError: &flTangentSError),
                    v7 = flPositionError,
                    v8 = flTexcoordError,
                    v15) )
              {
                if ( flMinPositionError > v7 )
                  goto LABEL_34;
                if ( flMinPositionError != v7 )
                  goto LABEL_36;
                if ( flMinTexcoordError > v8 )
                {
LABEL_34:
                  v16 = flBoneWeightError;
LABEL_35:
                  flMinBoneWeightError = v16;
                  flMinPositionError = v7;
                  flMinTexcoordError = v8;
                  flMinTangentSError = __PAIR64__(LODWORD(flNormalError), LODWORD(flTangentSError));
                  nBestIndex = nVertexIndex;
                  goto LABEL_36;
                }
                if ( flMinTexcoordError == v8 )
                {
                  v16 = flBoneWeightError;
                  if ( flMinBoneWeightError > flBoneWeightError
                    || flMinBoneWeightError == flBoneWeightError
                    && (*((float *)&flMinTangentSError + 1) > flNormalError
                     || *((float *)&flMinTangentSError + 1) == flNormalError
                     && *(float *)&flMinTangentSError >= flTangentSError) )
                  {
                    goto LABEL_35;
                  }
                }
              }
            }
          }
        }
      }
LABEL_36:
      if ( ++nVertexIndex >= nEndVert )
        return nBestIndex;
      v6 = v22;
    }
  }
  return nBestIndex;
}

//------------------------------------------------------------------------------
// Address: 0x004660C0
// Name: FindBoneWeightWithinModel
// Source: json
//------------------------------------------------------------------------------
void __usercall FindBoneWeightWithinModel(
        const VertexInfo_t *searchVertex@<edi>,
        char fIgnore@<al>,
        int a3@<esi>,
        const s_source_t *pSrc,
        s_boneweight_t *boneWeight)
{
  float v5; // xmm0_4
  int v6; // ecx
  float v7; // xmm2_4
  s_vertexinfo_t *v8; // esi
  float v9; // xmm3_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  s_vertexinfo_t *m_pMemory; // eax
  __int64 v13; // xmm0_8
  int p_boneweight; // eax
  __int128 v15; // [esp-4h] [ebp-58h] BYREF
  Vector normal; // [esp+Ch] [ebp-48h] BYREF
  int nVertexCount; // [esp+18h] [ebp-3Ch]
  int v18; // [esp+1Ch] [ebp-38h]
  int v19; // [esp+20h] [ebp-34h]
  int v20; // [esp+24h] [ebp-30h]
  float flMinPositionError; // [esp+28h] [ebp-2Ch]
  float flPositionError; // [esp+2Ch] [ebp-28h]
  unsigned int v23; // [esp+30h] [ebp-24h]
  int i; // [esp+34h] [ebp-20h]
  float flMinTangentSError; // [esp+38h] [ebp-1Ch]
  float flMinNormalError; // [esp+3Ch] [ebp-18h]
  float flMinTexcoordError; // [esp+40h] [ebp-14h]
  float flNormalError; // [esp+44h] [ebp-10h]
  int nBestIndex; // [esp+48h] [ebp-Ch]
  float flTangentSError; // [esp+4Ch] [ebp-8h] BYREF
  float flTexcoordError; // [esp+50h] [ebp-4h]

  v5 = 0.0;
  LODWORD(v15) = a3;
  v6 = fIgnore & 8;
  v7 = 0.0;
  nBestIndex = -1;
  flNormalError = 0.0;
  flTangentSError = 0.0;
  flTexcoordError = 0.0;
  flMinPositionError = 3.4028235e38;
  flMinNormalError = 3.4028235e38;
  flMinTangentSError = 3.4028235e38;
  flMinTexcoordError = 3.4028235e38;
  v20 = v6;
  if ( (fIgnore & 8) != 0 )
  {
    flMinNormalError = 0.0;
    flNormalError = 0.0;
  }
  v19 = fIgnore & 2;
  if ( (fIgnore & 2) != 0 )
  {
    v7 = 0.0;
    flMinTexcoordError = 0.0;
    flTexcoordError = 0.0;
  }
  v18 = fIgnore & 0x10;
  if ( (fIgnore & 0x10) != 0 )
  {
    flMinTangentSError = 0.0;
    flTangentSError = 0.0;
  }
  nVertexCount = pSrc->m_GlobalVertices.m_Size;
  i = 0;
  if ( nVertexCount <= 0 )
    goto LABEL_28;
  v23 = 0;
  while ( 1 )
  {
    v8 = &pSrc->m_GlobalVertices.m_Memory.m_pMemory[v23 / 0x54];
    v9 = (float)((float)((float)(searchVertex->m_Position.y - v8->position.y)
                       * (float)(searchVertex->m_Position.y - v8->position.y))
               + (float)((float)(searchVertex->m_Position.x - v8->position.x)
                       * (float)(searchVertex->m_Position.x - v8->position.x)))
       + (float)((float)(searchVertex->m_Position.z - v8->position.z)
               * (float)(searchVertex->m_Position.z - v8->position.z));
    flPositionError = v9;
    if ( v6 == 0 )
    {
      if ( (_S1_2 & 1) == 0 )
      {
        _S1_2 |= 1u;
        __libm_sse2_cos(x: *(long double *)&v15);
        flEpsilon = 0.1745329201221466;
      }
      *(Vector *)((char *)&v15 + 4) = searchVertex->m_Normal;
      normal = v8->normal;
      VectorNormalize(vec: (Vector *)((char *)&v15 + 4));
      VectorNormalize(vec: &normal);
      v7 = flTexcoordError;
      v9 = flPositionError;
      v5 = 1.0
         - (float)((float)((float)(normal.y * *((float *)&v15 + 2)) + (float)(normal.x * *((float *)&v15 + 1)))
                 + (float)(normal.z * *((float *)&v15 + 3)));
      flNormalError = v5;
    }
    if ( v19 == 0 )
    {
      LODWORD(v10) = COERCE_UNSIGNED_INT(v8->texcoord.y - searchVertex->m_TexCoord.y) & _mask__AbsFloat_;
      LODWORD(v11) = COERCE_UNSIGNED_INT(v8->texcoord.x - searchVertex->m_TexCoord.x) & _mask__AbsFloat_;
      v7 = (float)(v10 * v10) + (float)(v11 * v11);
      flTexcoordError = v7;
    }
    if ( v18 == 0 )
    {
      CompareTangentSFuzzy(n1: &searchVertex->m_TangentS, n2: &v8->tangentS, flError: &flTangentSError);
      v7 = flTexcoordError;
      v5 = flNormalError;
      v9 = flPositionError;
    }
    if ( flMinPositionError > v9
      || flMinPositionError == v9
      && (flMinTexcoordError > v7
       || flMinTexcoordError == v7
       && (flMinNormalError > v5 || flMinNormalError == v5 && flMinTangentSError >= flTangentSError)) )
    {
      flMinPositionError = v9;
      flMinTexcoordError = v7;
      flMinNormalError = v5;
      flMinTangentSError = flTangentSError;
      nBestIndex = i;
    }
    v23 += 84;
    if ( ++i >= nVertexCount )
      break;
    v6 = v20;
  }
  if ( nBestIndex == -1 )
LABEL_28:
    MdlError(fmt: "Encountered a mesh with no vertices!\n");
  m_pMemory = pSrc->m_GlobalVertices.m_Memory.m_pMemory;
  v13 = *(_QWORD *)&m_pMemory[nBestIndex].boneweight.numbones;
  p_boneweight = (int)&m_pMemory[nBestIndex].boneweight;
  *(_QWORD *)&boneWeight->numbones = v13;
  *(_QWORD *)&boneWeight->bone[1] = *(_QWORD *)(p_boneweight + 8);
  *(_QWORD *)boneWeight->weight = *(_QWORD *)(p_boneweight + 16);
  boneWeight->weight[2] = *(float *)(p_boneweight + 24);
}

//------------------------------------------------------------------------------
// Address: 0x004663A0
// Name: FindVertexInDictionaryExact
// Source: json
//------------------------------------------------------------------------------
int __usercall FindVertexInDictionaryExact@<eax>(
        CVertexDictionary *vertexDict@<ecx>,
        int nStartVert@<eax>,
        const VertexInfo_t *vertex@<edi>,
        int nEndVert)
{
  float x; // xmm1_4
  VertexInfo_t *v5; // ebx
  float *i; // esi
  int nVertID; // [esp+8h] [ebp-4h]

  nVertID = nStartVert;
  if ( nStartVert >= nEndVert )
    return -1;
  x = vertex->m_Position.x;
  v5 = &vertexDict->m_Verts.m_Memory.m_pMemory[nStartVert];
  for ( i = &v5->m_Normal.y;
        x != v5->m_Position.x
     || vertex->m_Position.y != *(i - 3)
     || vertex->m_Position.z != *(i - 2)
     || AreBoneWeightsEqual(b1: (const s_boneweight_t *)(i + 8), b2: &vertex->m_BoneWeight) == 0
     || vertex->m_TexCoord.x != i[2]
     || vertex->m_TexCoord.y != i[3]
     || vertex->m_Normal.x != *(i - 1)
     || vertex->m_Normal.y != *i
     || vertex->m_Normal.z != i[1]
     || vertex->m_TangentS.x != i[4]
     || vertex->m_TangentS.y != i[5]
     || vertex->m_TangentS.z != i[6]
     || vertex->m_TangentS.w != i[7];
        i += 20 )
  {
    ++v5;
    if ( ++nVertID >= nEndVert )
      return -1;
  }
  return nVertID;
}

//------------------------------------------------------------------------------
// Address: 0x004664C0
// Name: SetProcessedWithDictionary
// Source: json
//------------------------------------------------------------------------------
void __usercall SetProcessedWithDictionary(
        CVertexDictionary *vertexDict@<edi>,
        s_model_t *pSrcModel,
        CUtlVector<s_face_t,CUtlMemory<s_face_t,int> > *faces,
        CUtlVector<s_mesh_t,CUtlMemory<s_mesh_t,int> > *meshes,
        int **pMeshVertIndexMaps)
{
  void *v5; // esi
  signed int v6; // ebx
  signed int v7; // eax
  int v8; // edx
  VertexInfo_t *v9; // eax
  char *v10; // ecx
  VertexInfo_t *v11; // eax
  int v12; // ecx
  int v13; // ecx
  int v14; // ebx
  VertexInfo_t *v15; // eax
  int v16; // ecx
  char *v17; // ebx
  VertexInfo_t *v18; // eax
  int v19; // ecx
  char *v20; // ecx
  bool v21; // zf
  unsigned int v22; // edx
  VertexInfo_t *m_pMemory; // eax
  char *v24; // ecx
  float v25; // ebx
  VertexInfo_t *v26; // eax
  signed int nVertexCount; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]
  unsigned int v29; // [esp+10h] [ebp-4h]
  int v30; // [esp+10h] [ebp-4h]
  s_model_t *pSrcModela; // [esp+1Ch] [ebp+8h]
  s_model_t *pSrcModelb; // [esp+1Ch] [ebp+8h]

  v5 = MemAlloc_Alloc(nSize: 0x230u);
  memset(dst: (unsigned __int8 *)v5, value: 0, count: 0x230u);
  pSrcModel->m_pLodData = (s_loddata_t *)v5;
  nVertexCount = vertexDict->m_Verts.m_Size;
  v6 = nVertexCount;
  *((_DWORD *)v5 + 1) = calloc(count: nVertexCount, size: 0x58u);
  *(_DWORD *)v5 = nVertexCount;
  *((_DWORD *)v5 + 3) = calloc(count: faces->m_Size, size: 0x10u);
  v7 = 0;
  *((_DWORD *)v5 + 2) = faces->m_Size;
  if ( nVertexCount >= 4 )
  {
    v8 = 0;
    pSrcModela = nullptr;
    v29 = ((unsigned int)(nVertexCount - 4) >> 2) + 1;
    i = 4 * v29;
    do
    {
      v9 = &vertexDict->m_Verts.m_Memory.m_pMemory[v8];
      v10 = &pSrcModela->name[*((_DWORD *)v5 + 1)];
      *((_QWORD *)v10 + 7) = *(_QWORD *)&v9->m_BoneWeight.numbones;
      *((_QWORD *)v10 + 8) = *(_QWORD *)&v9->m_BoneWeight.bone[1];
      *((_QWORD *)v10 + 9) = *(_QWORD *)v9->m_BoneWeight.weight;
      *((_DWORD *)v10 + 20) = LODWORD(v9->m_BoneWeight.weight[2]);
      *((float *)v10 + 2) = v9->m_Position.x;
      *((float *)v10 + 3) = v9->m_Position.y;
      *((float *)v10 + 4) = v9->m_Position.z;
      *((float *)v10 + 5) = v9->m_Normal.x;
      *((float *)v10 + 6) = v9->m_Normal.y;
      *((float *)v10 + 7) = v9->m_Normal.z;
      *((float *)v10 + 12) = v9->m_TexCoord.x;
      *((float *)v10 + 13) = v9->m_TexCoord.y;
      *((float *)v10 + 8) = v9->m_TangentS.x;
      *((float *)v10 + 9) = v9->m_TangentS.y;
      *((float *)v10 + 10) = v9->m_TangentS.z;
      *((float *)v10 + 11) = v9->m_TangentS.w;
      *((_DWORD *)v10 + 21) = v9->m_nLodFlag;
      v11 = &vertexDict->m_Verts.m_Memory.m_pMemory[v8 + 1];
      v12 = *((_DWORD *)v5 + 1);
      *(_QWORD *)&pSrcModela->filename[v12 + 16] = *(_QWORD *)&vertexDict->m_Verts.m_Memory.m_pMemory[v8 + 1].m_BoneWeight.numbones;
      *(_QWORD *)&pSrcModela->filename[v12 + 24] = *(_QWORD *)&v11->m_BoneWeight.bone[1];
      *(_QWORD *)&pSrcModela->filename[v12 + 32] = *(_QWORD *)v11->m_BoneWeight.weight;
      v13 = (int)&pSrcModela->name[v12 + 88];
      *(float *)(v13 + 80) = v11->m_BoneWeight.weight[2];
      *(Vector *)(v13 + 8) = v11->m_Position;
      *(Vector *)(v13 + 20) = v11->m_Normal;
      *(Vector2D *)(v13 + 48) = v11->m_TexCoord;
      *(Vector4D *)(v13 + 32) = v11->m_TangentS;
      *(_DWORD *)(v13 + 84) = v11->m_nLodFlag;
      v14 = *((_DWORD *)v5 + 1);
      v15 = &vertexDict->m_Verts.m_Memory.m_pMemory[v8 + 2];
      v16 = (int)&pSrcModela->filename[v14 + 48];
      *(s_boneweight_t *)&pSrcModela->filename[v14 + 104] = vertexDict->m_Verts.m_Memory.m_pMemory[v8 + 2].m_BoneWeight;
      *(Vector *)(v16 + 8) = v15->m_Position;
      v17 = &pSrcModela->filename[136];
      pSrcModela = (s_model_t *)((char *)pSrcModela + 352);
      *(Vector *)(v16 + 20) = v15->m_Normal;
      *(Vector2D *)(v16 + 48) = v15->m_TexCoord;
      *(Vector4D *)(v16 + 32) = v15->m_TangentS;
      *(_DWORD *)(v16 + 84) = v15->m_nLodFlag;
      v18 = &vertexDict->m_Verts.m_Memory.m_pMemory[v8 + 3];
      v19 = *((_DWORD *)v5 + 1);
      *(_QWORD *)&v17[v19 + 56] = *(_QWORD *)&v18->m_BoneWeight.numbones;
      *(_QWORD *)&v17[v19 + 64] = *(_QWORD *)&v18->m_BoneWeight.bone[1];
      *(_QWORD *)&v17[v19 + 72] = *(_QWORD *)v18->m_BoneWeight.weight;
      v20 = &v17[v19];
      *((_DWORD *)v20 + 20) = LODWORD(v18->m_BoneWeight.weight[2]);
      *((float *)v20 + 2) = v18->m_Position.x;
      v8 += 4;
      v21 = v29-- == 1;
      *((float *)v20 + 3) = v18->m_Position.y;
      *((float *)v20 + 4) = v18->m_Position.z;
      *((float *)v20 + 5) = v18->m_Normal.x;
      *((float *)v20 + 6) = v18->m_Normal.y;
      *((float *)v20 + 7) = v18->m_Normal.z;
      *((float *)v20 + 12) = v18->m_TexCoord.x;
      *((float *)v20 + 13) = v18->m_TexCoord.y;
      *((float *)v20 + 8) = v18->m_TangentS.x;
      *((float *)v20 + 9) = v18->m_TangentS.y;
      *((float *)v20 + 10) = v18->m_TangentS.z;
      *((float *)v20 + 11) = v18->m_TangentS.w;
      *((_DWORD *)v20 + 21) = v18->m_nLodFlag;
    }
    while ( !v21 );
    v7 = i;
    v6 = nVertexCount;
  }
  if ( v7 < v6 )
  {
    v22 = v7;
    pSrcModelb = (s_model_t *)(88 * v7);
    v30 = v6 - v7;
    do
    {
      m_pMemory = vertexDict->m_Verts.m_Memory.m_pMemory;
      v24 = &pSrcModelb->name[*((_DWORD *)v5 + 1)];
      *((_QWORD *)v24 + 7) = *(_QWORD *)&vertexDict->m_Verts.m_Memory.m_pMemory[v22].m_BoneWeight.numbones;
      *((_QWORD *)v24 + 8) = *(_QWORD *)&m_pMemory[v22].m_BoneWeight.bone[1];
      *((_QWORD *)v24 + 9) = *(_QWORD *)m_pMemory[v22].m_BoneWeight.weight;
      v25 = m_pMemory[v22].m_BoneWeight.weight[2];
      v26 = &m_pMemory[v22];
      *((float *)v24 + 20) = v25;
      *((float *)v24 + 2) = v26->m_Position.x;
      pSrcModelb = (s_model_t *)((char *)pSrcModelb + 88);
      ++v22;
      v21 = v30-- == 1;
      *((float *)v24 + 3) = v26->m_Position.y;
      *((float *)v24 + 4) = v26->m_Position.z;
      *((float *)v24 + 5) = v26->m_Normal.x;
      *((float *)v24 + 6) = v26->m_Normal.y;
      *((float *)v24 + 7) = v26->m_Normal.z;
      *((float *)v24 + 12) = v26->m_TexCoord.x;
      *((float *)v24 + 13) = v26->m_TexCoord.y;
      *((float *)v24 + 8) = v26->m_TangentS.x;
      *((float *)v24 + 9) = v26->m_TangentS.y;
      *((float *)v24 + 10) = v26->m_TangentS.z;
      *((float *)v24 + 11) = v26->m_TangentS.w;
      *((_DWORD *)v24 + 21) = v26->m_nLodFlag;
    }
    while ( !v21 );
  }
  memcpy(
    dst: *((unsigned __int8 **)v5 + 3),
    src: (unsigned __int8 *)faces->m_Memory.m_pMemory,
    count: 16 * faces->m_Size);
  memcpy(
    dst: (unsigned __int8 *)v5 + 16,
    src: (unsigned __int8 *)meshes->m_Memory.m_pMemory,
    count: 16 * meshes->m_Size);
  *((_DWORD *)v5 + 132) = *pMeshVertIndexMaps;
  *((_DWORD *)v5 + 133) = pMeshVertIndexMaps[1];
  *((_DWORD *)v5 + 134) = pMeshVertIndexMaps[2];
  *((_DWORD *)v5 + 135) = pMeshVertIndexMaps[3];
  *((_DWORD *)v5 + 136) = pMeshVertIndexMaps[4];
  *((_DWORD *)v5 + 137) = pMeshVertIndexMaps[5];
  *((_DWORD *)v5 + 138) = pMeshVertIndexMaps[6];
  *((_DWORD *)v5 + 139) = pMeshVertIndexMaps[7];
}

//------------------------------------------------------------------------------
// Address: 0x004668C0
// Name: void FixupReplacedBones(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FixupReplacedBones()
{
  int v0; // ebx
  char *v1; // ebx
  int v2; // eax
  int v3; // edi
  int v4; // ecx
  int v5; // esi
  int v6; // eax
  const char *v7; // edi
  void **v8; // esi
  void *v9; // eax
  const char *v10; // ecx
  _BYTE *v11; // edx
  char v12; // al
  int v13; // [esp+4h] [ebp-1Ch]
  int i; // [esp+8h] [ebp-18h]
  int v15; // [esp+Ch] [ebp-14h]
  int v16; // [esp+10h] [ebp-10h]
  int v17; // [esp+14h] [ebp-Ch]
  int v18; // [esp+18h] [ebp-8h]
  char v19; // [esp+1Fh] [ebp-1h]

  v0 = 0;
  i = 0;
  if ( g_ScriptLODs.m_Size > 0 )
  {
    v13 = 0;
    do
    {
      v1 = (char *)g_ScriptLODs.m_Memory.m_pMemory + v0;
      do
      {
        v2 = *((_DWORD *)v1 + 9);
        v3 = 0;
        v19 = 0;
        v18 = 0;
        if ( v2 <= 0 )
          break;
        v15 = 0;
        do
        {
          v4 = 0;
          v17 = 0;
          if ( v2 > 0 )
          {
            v5 = 0;
            v16 = 0;
            do
            {
              if ( v18 != v4
                && _V_stricmp(
                     s1: *(const char **)(v3 + *((_DWORD *)v1 + 6) + 4),
                     s2: *(const char **)(v5 + *((_DWORD *)v1 + 6) + 8)) == 0 )
              {
                v6 = *((_DWORD *)v1 + 6);
                v7 = *(const char **)(v3 + v6 + 8);
                v8 = (void **)(v5 + v6 + 8);
                if ( *v8 != nullptr )
                  free(pMem: *v8);
                v9 = MemAlloc_Alloc(nSize: strlen(v7) + 1);
                *v8 = v9;
                v10 = v7;
                v11 = v9;
                do
                {
                  v12 = *v10;
                  *v11++ = *v10++;
                }
                while ( v12 != 0 );
                v5 = v16;
                v3 = v15;
                v19 = 1;
              }
              v4 = v17 + 1;
              v5 += 12;
              v17 = v4;
              v16 = v5;
            }
            while ( v4 < *((_DWORD *)v1 + 9) );
          }
          v2 = *((_DWORD *)v1 + 9);
          v3 += 12;
          ++v18;
          v15 = v3;
        }
        while ( v18 < v2 );
      }
      while ( v19 != 0 );
      v0 = v13 + 108;
      ++i;
      v13 += 108;
    }
    while ( i < g_ScriptLODs.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004669E0
// Name: CopyVerts
// Source: json
//------------------------------------------------------------------------------
void __usercall CopyVerts(
        char nLodID@<cl>,
        CVertexDictionary *vertexDict@<edi>,
        const s_source_t *pSrc,
        const s_mesh_t *pSrcMesh,
        s_mesh_t *pDstMesh,
        int *pMeshVertIndexMap)
{
  const s_mesh_t *v6; // eax
  int vertexoffset; // ebx
  int m_Size; // esi
  int m_nAllocationCount; // eax
  int v10; // ebx
  VertexInfo_t *m_pMemory; // ecx
  int v12; // eax
  s_vertexinfo_t *v13; // eax
  VertexInfo_t *v14; // ecx
  int v15; // [esp+0h] [ebp-8h]
  int srcVertID; // [esp+4h] [ebp-4h]

  v6 = pSrcMesh;
  srcVertID = 0;
  if ( pSrcMesh->numvertices <= 0 )
  {
    pDstMesh->numvertices = pSrcMesh->numvertices;
  }
  else
  {
    v15 = 1 << nLodID;
    while ( 1 )
    {
      vertexoffset = v6->vertexoffset;
      m_Size = vertexDict->m_Verts.m_Size;
      m_nAllocationCount = vertexDict->m_Verts.m_Memory.m_nAllocationCount;
      v10 = srcVertID + vertexoffset;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<VertexInfo_t,int>::Grow(this: &vertexDict->m_Verts.m_Memory, num: m_Size - m_nAllocationCount + 1);
      ++vertexDict->m_Verts.m_Size;
      m_pMemory = vertexDict->m_Verts.m_Memory.m_pMemory;
      v12 = vertexDict->m_Verts.m_Size - m_Size - 1;
      vertexDict->m_Verts.m_pElements = vertexDict->m_Verts.m_Memory.m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 80 * v12);
      v13 = &pSrc->m_GlobalVertices.m_Memory.m_pMemory[v10];
      v14 = &vertexDict->m_Verts.m_Memory.m_pMemory[m_Size];
      v14->m_Position.x = v13->position.x;
      v14->m_Position.y = v13->position.y;
      v14->m_Position.z = v13->position.z;
      v14->m_Normal.x = v13->normal.x;
      v14->m_Normal.y = v13->normal.y;
      v14->m_Normal.z = v13->normal.z;
      v14->m_TexCoord.x = v13->texcoord.x;
      v14->m_TexCoord.y = v13->texcoord.y;
      v14->m_TangentS.x = v13->tangentS.x;
      v14->m_TangentS.y = v13->tangentS.y;
      v14->m_TangentS.z = v13->tangentS.z;
      v14->m_TangentS.w = v13->tangentS.w;
      *(_QWORD *)&v14->m_BoneWeight.numbones = *(_QWORD *)&v13->boneweight.numbones;
      *(_QWORD *)&v14->m_BoneWeight.bone[1] = *(_QWORD *)&v13->boneweight.bone[1];
      *(_QWORD *)v14->m_BoneWeight.weight = *(_QWORD *)v13->boneweight.weight;
      v14->m_BoneWeight.weight[2] = v13->boneweight.weight[2];
      v14->m_nLodFlag = v15;
      SortBoneWeightByIndex(boneWeight: &v14->m_BoneWeight);
      pMeshVertIndexMap[v10] = m_Size - pDstMesh->vertexoffset;
      if ( ++srcVertID >= pSrcMesh->numvertices )
        break;
      v6 = pSrcMesh;
    }
    pDstMesh->numvertices = pSrcMesh->numvertices;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466B30
// Name: CopyFaces
// Source: json
//------------------------------------------------------------------------------
void __usercall CopyFaces(
        CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *faces@<esi>,
        const s_source_t *pSrc,
        const s_mesh_t *pSrcMesh,
        s_mesh_t *pDstMesh)
{
  const s_mesh_t *v4; // ecx
  int v5; // eax
  int m_pMemory; // ebx
  s_face_t *v7; // edi
  int m_nAllocationCount; // eax
  s_face_t *v9; // ecx
  int v10; // eax
  int v11; // ebx
  s_face_t *v12; // eax
  s_face_t *v13; // eax
  int srcFaceID; // [esp+0h] [ebp-4h]

  v4 = pSrcMesh;
  v5 = 0;
  for ( srcFaceID = 0; v5 < pSrcMesh->numfaces; srcFaceID = v5 )
  {
    m_pMemory = (int)faces[1].m_pMemory;
    v7 = &pSrc->face[v5 + v4->faceoffset];
    m_nAllocationCount = faces->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(this: faces, num: m_pMemory - m_nAllocationCount + 1);
    ++faces[1].m_pMemory;
    v9 = (s_face_t *)faces->m_pMemory;
    v10 = (int)faces[1].m_pMemory - m_pMemory - 1;
    faces[1].m_nAllocationCount = (int)faces->m_pMemory;
    if ( v10 > 0 )
      _V_memmove(dest: &v9[m_pMemory + 1], src: &v9[m_pMemory], count: 16 * v10);
    v11 = m_pMemory;
    v12 = (s_face_t *)&faces->m_pMemory[v11];
    if ( v12 != nullptr )
    {
      v12->d = -1;
      v12->c = -1;
      v12->b = -1;
      v12->a = -1;
    }
    v13 = (s_face_t *)&faces->m_pMemory[v11];
    v13->a = v7->a;
    v13->b = v7->b;
    v13->c = v7->c;
    v4 = pSrcMesh;
    v13->d = v7->d;
    ++pDstMesh->numfaces;
    v5 = srcFaceID + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466BF0
// Name: BuildBoneLODMapping
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildBoneLODMapping(int lodID@<eax>, CUtlVector<int,CUtlMemory<int,int> > *boneMap)
{
  LodScriptData_t *v3; // esi
  signed int v4; // eax
  CLodScriptReplacement_t *m_pMemory; // eax
  const char *m_pSrcName; // esi
  const char *m_pDstName; // edi
  int GlobalBone; // ebx
  int v9; // eax
  LodScriptData_t *scriptLOD; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]
  int v12; // [esp+10h] [ebp-4h]

  CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)boneMap,
    elem: boneMap->m_Size,
    num: g_numbones);
  v3 = &g_ScriptLODs.m_Memory.m_pMemory[lodID];
  v4 = 0;
  for ( scriptLOD = v3; v4 < (int)g_numbones; ++v4 )
    boneMap->m_Memory.m_pMemory[v4] = v4;
  i = 0;
  if ( v3->boneReplacements.m_Size > 0 )
  {
    v12 = 0;
    while ( 1 )
    {
      m_pMemory = v3->boneReplacements.m_Memory.m_pMemory;
      m_pSrcName = m_pMemory[v12].m_pSrcName;
      m_pDstName = m_pMemory[v12].m_pDstName;
      GlobalBone = findGlobalBone(name: m_pSrcName);
      v9 = findGlobalBone(name: m_pDstName);
      if ( GlobalBone == -1 )
      {
        if ( g_verbose )
          MdlWarning(fmt: "Couldn't replace unknown bone \"%s\" with \"%s\"\n", m_pSrcName, m_pDstName);
      }
      else if ( v9 == -1 )
      {
        if ( g_verbose )
          MdlWarning(fmt: "Couldn't replace bone \"%s\" with unknown \"%s\"\n", m_pSrcName, m_pDstName);
      }
      else
      {
        boneMap->m_Memory.m_pMemory[GlobalBone] = v9;
      }
      ++v12;
      if ( ++i >= scriptLOD->boneReplacements.m_Size )
        break;
      v3 = scriptLOD;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466CC0
// Name: MarkRootLODBones
// Source: json
//------------------------------------------------------------------------------
void __cdecl MarkRootLODBones(CVertexDictionary *vertexDictionary)
{
  CVertexDictionary *v1; // eax
  int m_nRootLODStart; // ebx
  int *m_pMemory; // edi
  int v4; // esi
  s_boneweight_t *v5; // esi
  int v6; // ecx
  int *bone; // eax
  int v8; // ecx
  int *v9; // edx
  CUtlVector<int,CUtlMemory<int,int> > boneMap; // [esp+Ch] [ebp-18h] BYREF
  int i; // [esp+20h] [ebp-4h]

  memset(&boneMap, 0, sizeof(boneMap));
  BuildBoneLODMapping(lodID: 0, &boneMap);
  v1 = vertexDictionary;
  m_nRootLODStart = vertexDictionary->m_nRootLODStart;
  m_pMemory = boneMap.m_Memory.m_pMemory;
  if ( m_nRootLODStart < vertexDictionary->m_nRootLODEnd )
  {
    v4 = 80 * m_nRootLODStart;
    for ( i = 80 * m_nRootLODStart; ; v4 = i )
    {
      v5 = (s_boneweight_t *)((char *)&v1->m_Verts.m_Memory.m_pMemory->m_BoneWeight + v4);
      v6 = 0;
      if ( v5->numbones > 0 )
      {
        bone = v5->bone;
        do
        {
          *bone = m_pMemory[*bone];
          ++v6;
          ++bone;
        }
        while ( v6 < v5->numbones );
      }
      CollapseBoneWeights(boneWeight: v5);
      SortBoneWeightByWeight(boneWeight: v5);
      v8 = 0;
      if ( v5->numbones > 0 )
      {
        v9 = v5->bone;
        do
        {
          g_bonetable[*v9].flags |= 0x400u;
          ++v8;
          ++v9;
        }
        while ( v8 < v5->numbones );
      }
      v1 = vertexDictionary;
      i += 80;
      if ( ++m_nRootLODStart >= vertexDictionary->m_nRootLODEnd )
        break;
    }
  }
  if ( boneMap.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00466D90
// Name: ReplaceBonesRecursive
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReplaceBonesRecursive(
        int globalBoneID,
        bool replaceThis,
        CUtlVector<CLodScriptReplacement_t,CUtlMemory<CLodScriptReplacement_t,int> > *boneReplacements,
        const char *replacementName)
{
  CLodScriptReplacement_t *v4; // esi
  int v5; // esi
  int *p_parent; // ebx

  if ( replaceThis )
  {
    v4 = &boneReplacements->m_Memory.m_pMemory[CUtlVector<CLodScriptReplacement_t,CUtlMemory<CLodScriptReplacement_t,int>>::InsertBefore(
                                                 this: boneReplacements,
                                                 elem: boneReplacements->m_Size)];
    CLodScriptReplacement_t::SetSrcName(this: v4, pSrcName: g_bonetable[globalBoneID].name);
    CLodScriptReplacement_t::SetDstName(this: v4, pDstName: replacementName);
  }
  v5 = 0;
  if ( (int)g_numbones > 0 )
  {
    p_parent = &g_bonetable[0].parent;
    do
    {
      if ( *p_parent == globalBoneID )
        ReplaceBonesRecursive(globalBoneID: v5, replaceThis: true, boneReplacements, replacementName);
      ++v5;
      p_parent += 116;
    }
    while ( v5 < (int)g_numbones );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466E10
// Name: ConvertSingleBoneTreeCollapseToReplaceBones
// Source: json
//------------------------------------------------------------------------------
void __usercall ConvertSingleBoneTreeCollapseToReplaceBones(
        CLodScriptReplacement_t *boneTreeCollapse@<eax>,
        CUtlVector<CLodScriptReplacement_t,CUtlMemory<CLodScriptReplacement_t,int> > *boneReplacements)
{
  int GlobalBone; // eax
  int v4; // esi
  s_bonetable_t *v5; // ebx
  int *p_parent; // edi
  int i; // [esp+4h] [ebp-4h]

  GlobalBone = findGlobalBone(name: boneTreeCollapse->m_pSrcName);
  i = GlobalBone;
  if ( GlobalBone == -1 )
  {
    MdlWarning(fmt: "Couldn't find bone %s for bonetreecollapse, skipping\n", boneTreeCollapse->m_pSrcName);
  }
  else
  {
    v4 = 0;
    v5 = &g_bonetable[GlobalBone];
    if ( (int)g_numbones > 0 )
    {
      p_parent = &g_bonetable[0].parent;
      do
      {
        if ( *p_parent == GlobalBone )
        {
          ReplaceBonesRecursive(globalBoneID: v4, replaceThis: true, boneReplacements, replacementName: v5->name);
          GlobalBone = i;
        }
        ++v4;
        p_parent += 116;
      }
      while ( v4 < (int)g_numbones );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466EA0
// Name: void ConvertBoneTreeCollapsesToReplaceBones(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConvertBoneTreeCollapsesToReplaceBones()
{
  int v0; // eax
  LodScriptData_t *m_pMemory; // ecx
  int v2; // edi
  int *v3; // ebx
  int v4; // esi
  _DWORD *v5; // [esp+0h] [ebp-10h]
  CUtlVector<CLodScriptReplacement_t,CUtlMemory<CLodScriptReplacement_t,int> > *boneReplacements; // [esp+4h] [ebp-Ch]
  int v7; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v0 = 0;
  i = 0;
  if ( g_ScriptLODs.m_Size > 0 )
  {
    m_pMemory = g_ScriptLODs.m_Memory.m_pMemory;
    v7 = 0;
    do
    {
      v2 = 0;
      v3 = (int *)((char *)&m_pMemory->boneTreeCollapses.m_Size + v0);
      if ( *v3 > 0 )
      {
        boneReplacements = (CUtlVector<CLodScriptReplacement_t,CUtlMemory<CLodScriptReplacement_t,int> > *)((char *)&m_pMemory->boneReplacements + v0);
        v5 = (CLodScriptReplacement_t **)((char *)&m_pMemory->boneTreeCollapses.m_Memory.m_pMemory + v0);
        v4 = 0;
        do
        {
          ConvertSingleBoneTreeCollapseToReplaceBones(
            boneTreeCollapse: (CLodScriptReplacement_t *)(v4 + *v5),
            boneReplacements);
          ++v2;
          v4 += 12;
        }
        while ( v2 < *v3 );
        m_pMemory = g_ScriptLODs.m_Memory.m_pMemory;
        v0 = v7;
      }
      v0 += 108;
      ++i;
      v7 = v0;
    }
    while ( i < g_ScriptLODs.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466F20
// Name: CreateLODVertsInDictionary
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateLODVertsInDictionary(
        int nLodID,
        const s_source_t *pRootLODSrc,
        s_source_t *pCurrentLODSrc,
        const s_mesh_t *pCurrLODMesh,
        s_mesh_t *pVertexDictMesh,
        CVertexDictionary *vertexDict,
        int *pMeshVertIndexMap)
{
  int v8; // edi
  s_vertexinfo_t *v9; // eax
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v16; // xmm6_4
  float w; // xmm7_4
  float v18; // edx
  int m_nRootLODEnd; // edx
  int m_nLodFlag; // esi
  int m_nRootLODStart; // ecx
  int VertexWithinVertexDictionary; // eax
  VertexInfo_t *v23; // eax
  float v24; // ecx
  int m_nPrevLODCount; // eax
  int vertexoffset; // ecx
  int v27; // eax
  VertexInfo_t *v28; // eax
  float v29; // ecx
  int v30; // edx
  __int64 v31; // xmm0_8
  int v32; // eax
  int numbones; // edi
  int i; // edx
  s_bonetable_t *v35; // eax
  int v36; // eax
  int v37; // edx
  int VertexInDictionaryExact; // eax
  int v39; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  VertexInfo_t *m_pMemory; // ecx
  int v43; // eax
  int v44; // eax
  bool v45; // zf
  VertexInfo_t *v46; // ecx
  int v47; // ebx
  CUtlVector<int,CUtlMemory<int,int> > boneMap; // [esp+Ch] [ebp-C4h] BYREF
  int v49; // [esp+20h] [ebp-B0h]
  int nSrcID; // [esp+24h] [ebp-ACh]
  int v51; // [esp+28h] [ebp-A8h]
  int nNumCurrentVerts; // [esp+2Ch] [ebp-A4h]
  VertexInfo_t vertex; // [esp+30h] [ebp-A0h] BYREF
  VertexInfo_t idealVertex; // [esp+80h] [ebp-50h] BYREF
  int nSrcVertID; // [esp+ECh] [ebp+1Ch]

  nNumCurrentVerts = vertexDict->m_Verts.m_Size;
  vertexDict->m_nPrevLODCount = nNumCurrentVerts;
  v8 = nLodID;
  memset(&boneMap, 0, sizeof(boneMap));
  BuildBoneLODMapping(lodID: nLodID, &boneMap);
  nSrcVertID = 0;
  if ( pCurrLODMesh->numvertices > 0 )
  {
    v51 = 1 << nLodID;
    do
    {
      nSrcID = nSrcVertID + pCurrLODMesh->vertexoffset;
      v9 = &pCurrentLODSrc->m_GlobalVertices.m_Memory.m_pMemory[nSrcID];
      x = v9->position.x;
      y = v9->position.y;
      z = v9->position.z;
      v13 = v9->normal.x;
      v14 = v9->normal.y;
      v15 = v9->normal.z;
      v16 = v9->texcoord.x;
      vertex.m_TexCoord.y = v9->texcoord.y;
      vertex.m_TangentS.x = v9->tangentS.x;
      vertex.m_TangentS.y = v9->tangentS.y;
      vertex.m_TangentS.z = v9->tangentS.z;
      w = v9->tangentS.w;
      vertex.m_Position.x = x;
      vertex.m_Position.y = y;
      vertex.m_Position.z = z;
      vertex.m_Normal.x = v13;
      vertex.m_Normal.y = v14;
      vertex.m_Normal.z = v15;
      vertex.m_TexCoord.x = v16;
      vertex.m_TangentS.w = w;
      if ( g_bSkinnedLODs )
      {
        v18 = v9->boneweight.weight[2];
        *(_QWORD *)&vertex.m_BoneWeight.numbones = *(_QWORD *)&v9->boneweight.numbones;
        *(_QWORD *)&vertex.m_BoneWeight.bone[1] = *(_QWORD *)&v9->boneweight.bone[1];
        *(_QWORD *)vertex.m_BoneWeight.weight = *(_QWORD *)v9->boneweight.weight;
        vertex.m_BoneWeight.weight[2] = v18;
      }
      m_nRootLODEnd = vertexDict->m_nRootLODEnd;
      m_nLodFlag = vertex.m_nLodFlag;
      idealVertex.m_Position.x = x;
      idealVertex.m_TexCoord.y = vertex.m_TexCoord.y;
      idealVertex.m_TangentS.x = vertex.m_TangentS.x;
      idealVertex.m_BoneWeight.weight[2] = vertex.m_BoneWeight.weight[2];
      idealVertex.m_TangentS.y = vertex.m_TangentS.y;
      m_nRootLODStart = vertexDict->m_nRootLODStart;
      idealVertex.m_TangentS.z = vertex.m_TangentS.z;
      idealVertex.m_TangentS.w = vertex.m_TangentS.w;
      *(_QWORD *)&idealVertex.m_BoneWeight.numbones = *(_QWORD *)&vertex.m_BoneWeight.numbones;
      *(_QWORD *)&idealVertex.m_BoneWeight.bone[1] = *(_QWORD *)&vertex.m_BoneWeight.bone[1];
      idealVertex.m_Position.y = y;
      idealVertex.m_Position.z = z;
      idealVertex.m_Normal.x = v13;
      idealVertex.m_Normal.y = v14;
      idealVertex.m_Normal.z = v15;
      idealVertex.m_TexCoord.x = v16;
      *(_QWORD *)idealVertex.m_BoneWeight.weight = *(_QWORD *)vertex.m_BoneWeight.weight;
      idealVertex.m_nLodFlag = vertex.m_nLodFlag;
      VertexWithinVertexDictionary = FindVertexWithinVertexDictionary(
                                       find: &vertex,
                                       nStartVert: m_nRootLODStart,
                                       fIgnore: 4 * !g_bSkinnedLODs + 16,
                                       vertexDict,
                                       nEndVert: m_nRootLODEnd);
      if ( VertexWithinVertexDictionary == -1 )
      {
        if ( !g_bSkinnedLODs )
        {
          FindBoneWeightWithinModel(
            searchVertex: &vertex,
            fIgnore: 20,
            a3: m_nLodFlag,
            pSrc: pRootLODSrc,
            boneWeight: &idealVertex.m_BoneWeight);
          m_nLodFlag = idealVertex.m_nLodFlag;
        }
      }
      else
      {
        v23 = &vertexDict->m_Verts.m_Memory.m_pMemory[VertexWithinVertexDictionary];
        idealVertex.m_Position = v23->m_Position;
        v24 = v23->m_BoneWeight.weight[2];
        idealVertex.m_Normal.x = v23->m_Normal.x;
        m_nLodFlag = v23->m_nLodFlag;
        idealVertex.m_Normal.y = v23->m_Normal.y;
        idealVertex.m_Normal.z = v23->m_Normal.z;
        idealVertex.m_TexCoord = v23->m_TexCoord;
        idealVertex.m_TangentS = v23->m_TangentS;
        *(_QWORD *)&idealVertex.m_BoneWeight.numbones = *(_QWORD *)&v23->m_BoneWeight.numbones;
        *(_QWORD *)&idealVertex.m_BoneWeight.bone[1] = *(_QWORD *)&v23->m_BoneWeight.bone[1];
        *(_QWORD *)idealVertex.m_BoneWeight.weight = *(_QWORD *)v23->m_BoneWeight.weight;
        idealVertex.m_BoneWeight.weight[2] = v24;
      }
      vertex.m_Position.x = idealVertex.m_Position.x;
      vertex.m_Position.y = idealVertex.m_Position.y;
      m_nPrevLODCount = vertexDict->m_nPrevLODCount;
      vertex.m_Position.z = idealVertex.m_Position.z;
      vertex.m_Normal = idealVertex.m_Normal;
      vertex.m_TexCoord = idealVertex.m_TexCoord;
      vertex.m_TangentS = idealVertex.m_TangentS;
      *(_QWORD *)&vertex.m_BoneWeight.numbones = *(_QWORD *)&idealVertex.m_BoneWeight.numbones;
      *(_QWORD *)&vertex.m_BoneWeight.bone[1] = *(_QWORD *)&idealVertex.m_BoneWeight.bone[1];
      vertex.m_BoneWeight.weight[2] = idealVertex.m_BoneWeight.weight[2];
      vertexoffset = pVertexDictMesh->vertexoffset;
      *(_QWORD *)vertex.m_BoneWeight.weight = *(_QWORD *)idealVertex.m_BoneWeight.weight;
      vertex.m_nLodFlag = m_nLodFlag;
      v27 = FindVertexWithinVertexDictionary(
              find: &vertex,
              nStartVert: vertexoffset,
              fIgnore: 0,
              vertexDict,
              nEndVert: m_nPrevLODCount);
      if ( v27 == -1 )
      {
        idealVertex.m_Position = vertex.m_Position;
        idealVertex.m_Normal = vertex.m_Normal;
        idealVertex.m_TexCoord = vertex.m_TexCoord;
        idealVertex.m_TangentS = vertex.m_TangentS;
        *(_QWORD *)&idealVertex.m_BoneWeight.numbones = *(_QWORD *)&vertex.m_BoneWeight.numbones;
        *(_QWORD *)&idealVertex.m_BoneWeight.bone[1] = *(_QWORD *)&vertex.m_BoneWeight.bone[1];
        v31 = *(_QWORD *)vertex.m_BoneWeight.weight;
        idealVertex.m_BoneWeight.weight[2] = vertex.m_BoneWeight.weight[2];
        idealVertex.m_nLodFlag = vertex.m_nLodFlag;
      }
      else
      {
        v28 = &vertexDict->m_Verts.m_Memory.m_pMemory[v27];
        idealVertex.m_Position = v28->m_Position;
        v29 = v28->m_BoneWeight.weight[2];
        v30 = v28->m_nLodFlag;
        idealVertex.m_Normal = v28->m_Normal;
        idealVertex.m_TexCoord = v28->m_TexCoord;
        idealVertex.m_TangentS = v28->m_TangentS;
        *(_QWORD *)&idealVertex.m_BoneWeight.numbones = *(_QWORD *)&v28->m_BoneWeight.numbones;
        *(_QWORD *)&idealVertex.m_BoneWeight.bone[1] = *(_QWORD *)&v28->m_BoneWeight.bone[1];
        v31 = *(_QWORD *)v28->m_BoneWeight.weight;
        idealVertex.m_BoneWeight.weight[2] = v29;
        idealVertex.m_nLodFlag = v30;
      }
      v32 = 0;
      for ( *(_QWORD *)idealVertex.m_BoneWeight.weight = v31; v32 < idealVertex.m_BoneWeight.numbones; ++v32 )
        idealVertex.m_BoneWeight.bone[v32] = boneMap.m_Memory.m_pMemory[idealVertex.m_BoneWeight.bone[v32]];
      CollapseBoneWeights(boneWeight: &idealVertex.m_BoneWeight);
      SortBoneWeightByWeight(boneWeight: &idealVertex.m_BoneWeight);
      numbones = idealVertex.m_BoneWeight.numbones;
      for ( i = 0; i < numbones; ++i )
      {
        v35 = &g_bonetable[idealVertex.m_BoneWeight.bone[i]];
        v35->flags |= 1024 << nLodID;
      }
      v36 = pVertexDictMesh->vertexoffset;
      v37 = v36 + pVertexDictMesh->numvertices;
      idealVertex.m_nLodFlag = v51;
      VertexInDictionaryExact = FindVertexInDictionaryExact(
                                  vertexDict,
                                  nStartVert: v36,
                                  vertex: &idealVertex,
                                  nEndVert: v37);
      if ( VertexInDictionaryExact == -1 )
      {
        m_Size = vertexDict->m_Verts.m_Size;
        m_nAllocationCount = vertexDict->m_Verts.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<VertexInfo_t,int>::Grow(this: &vertexDict->m_Verts.m_Memory, num: m_Size - m_nAllocationCount + 1);
        ++vertexDict->m_Verts.m_Size;
        m_pMemory = vertexDict->m_Verts.m_Memory.m_pMemory;
        v43 = vertexDict->m_Verts.m_Size - m_Size - 1;
        vertexDict->m_Verts.m_pElements = vertexDict->m_Verts.m_Memory.m_pMemory;
        if ( v43 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 80 * v43);
        v44 = 80 * m_Size;
        v45 = &vertexDict->m_Verts.m_Memory.m_pMemory[m_Size] == nullptr;
        v46 = &vertexDict->m_Verts.m_Memory.m_pMemory[m_Size];
        v49 = 80 * m_Size;
        if ( !v45 )
        {
          VertexInfo_t::VertexInfo_t(this: v46, __that: &idealVertex);
          v44 = v49;
        }
        SortBoneWeightByIndex(boneWeight: (s_boneweight_t *)((char *)&vertexDict->m_Verts.m_Memory.m_pMemory->m_BoneWeight
                                                           + v44));
        ++pVertexDictMesh->numvertices;
        v39 = m_Size - pVertexDictMesh->vertexoffset;
      }
      else
      {
        vertexDict->m_Verts.m_Memory.m_pMemory[VertexInDictionaryExact].m_nLodFlag |= idealVertex.m_nLodFlag;
        v39 = VertexInDictionaryExact - pVertexDictMesh->vertexoffset;
      }
      pMeshVertIndexMap[nSrcID] = v39;
      ++nSrcVertID;
    }
    while ( nSrcVertID < pCurrLODMesh->numvertices );
    v8 = nLodID;
  }
  v47 = vertexDict->m_Verts.m_Size;
  if ( !g_quiet && v47 != nNumCurrentVerts )
    printf(format: "Lod %d: vertexes: %d (%d new)\n", v8, v47, v47 - nNumCurrentVerts);
  if ( boneMap.m_Memory.m_nGrowSize >= 0 && boneMap.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: boneMap.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004675C0
// Name: UnifyModelLODs
// Source: json
//------------------------------------------------------------------------------
void __cdecl UnifyModelLODs(s_model_t *pSrcModel)
{
  int i; // edi
  s_source_t **v2; // eax
  __int64 v3; // rax
  unsigned __int8 *m_pMemory; // ebx
  int v5; // edi
  int m_Size; // eax
  s_source_t *source; // eax
  int v8; // ecx
  int v9; // ebx
  int v10; // eax
  s_mesh_t *v11; // ebx
  s_source_t **v12; // eax
  s_source_t *v13; // edi
  int v14; // edx
  int v15; // eax
  int *meshindex; // ecx
  const s_mesh_t *v17; // esi
  int j; // esi
  s_source_t *v19; // edi
  const s_mesh_t *v20; // eax
  int *pMeshVertIndexMaps[8]; // [esp+4h] [ebp-80h] BYREF
  CVertexDictionary vertexDictionary; // [esp+24h] [ebp-60h] BYREF
  CUtlVector<s_face_t,CUtlMemory<s_face_t,int> > faces; // [esp+44h] [ebp-40h] BYREF
  CUtlVector<s_mesh_t,CUtlMemory<s_mesh_t,int> > meshes; // [esp+58h] [ebp-2Ch] BYREF
  int nStart; // [esp+6Ch] [ebp-18h]
  int v26; // [esp+70h] [ebp-14h]
  int nMeshID; // [esp+74h] [ebp-10h]
  s_source_t *pLOD0Source; // [esp+78h] [ebp-Ch]
  int nNumLODs; // [esp+7Ch] [ebp-8h]
  int nMaterialID; // [esp+80h] [ebp-4h]

  if ( _V_stricmp(s1: pSrcModel->name, s2: "blank") != 0 )
  {
    nNumLODs = pSrcModel->m_LodSources.m_Size;
    for ( i = 0; i < 8; ++i )
    {
      if ( i < nNumLODs && *(v2 = &pSrcModel->m_LodSources.m_Memory.m_pMemory[i]) != nullptr )
      {
        v3 = 4LL * (unsigned int)(*v2)->m_GlobalVertices.m_Size;
        pMeshVertIndexMaps[i] = (int *)MemAlloc_Alloc(nSize: HIDWORD(v3) != 0 ? -1 : v3);
      }
      else
      {
        pMeshVertIndexMaps[i] = nullptr;
      }
    }
    memset(&vertexDictionary, 0, 24);
    memset(&faces, 0, sizeof(faces));
    memset(&meshes, 0, sizeof(meshes));
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
      this: (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)&meshes,
      num: 32);
    m_pMemory = (unsigned __int8 *)meshes.m_Memory.m_pMemory;
    v5 = meshes.m_Size + 32;
    m_Size = meshes.m_Size;
    meshes.m_Size += 32;
    meshes.m_pElements = meshes.m_Memory.m_pMemory;
    if ( m_Size > 0 )
      _V_memmove(dest: &meshes.m_Memory.m_pMemory[32], src: meshes.m_Memory.m_pMemory, count: 16 * m_Size);
    memset(dst: m_pMemory, value: 0, count: 16 * v5);
    source = pSrcModel->source;
    nMeshID = 0;
    if ( source->nummeshes > 0 )
    {
      v8 = 201488;
      v26 = 201488;
      do
      {
        v9 = *(_DWORD *)&source->filename[v8];
        v10 = faces.m_Size;
        v11 = &meshes.m_Memory.m_pMemory[v9];
        v11->vertexoffset = vertexDictionary.m_Verts.m_Size;
        v11->numvertices = 0;
        v11->numfaces = 0;
        v11->faceoffset = v10;
        v12 = pSrcModel->m_LodSources.m_Memory.m_pMemory;
        if ( *v12 != nullptr )
        {
          v13 = *v12;
          v14 = *(_DWORD *)&(*v12)->filename[v8];
          pLOD0Source = *v12;
          nMaterialID = v14;
          if ( !g_quiet )
          {
            printf(format: "Processing LOD for material: %s\n", g_texture[v14].name);
            v14 = nMaterialID;
          }
          v15 = 0;
          if ( v13->nummeshes > 0 )
          {
            meshindex = v13->meshindex;
            while ( *meshindex != v14 )
            {
              ++v15;
              ++meshindex;
              if ( v15 >= v13->nummeshes )
                goto LABEL_27;
              v14 = nMaterialID;
            }
            v17 = &v13->mesh[v13->meshindex[v15]];
            if ( v17 != nullptr )
            {
              nStart = vertexDictionary.m_Verts.m_Size;
              CopyVerts(
                nLodID: 0,
                vertexDict: &vertexDictionary,
                pSrc: v13,
                pSrcMesh: v17,
                pDstMesh: v11,
                pMeshVertIndexMap: pMeshVertIndexMaps[0]);
              vertexDictionary.m_nRootLODStart = nStart;
              vertexDictionary.m_nRootLODEnd = vertexDictionary.m_Verts.m_Size;
              MarkRootLODBones(&vertexDictionary);
              CopyFaces(
                (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)&faces,
                pSrc: pLOD0Source,
                pSrcMesh: v17,
                pDstMesh: v11);
              for ( j = 1; j < nNumLODs; ++j )
              {
                v19 = pSrcModel->m_LodSources.m_Memory.m_pMemory[j];
                if ( v19 != nullptr )
                {
                  v20 = FindOrCullMesh(nLodID: j, pSrc: v19, nMaterialID);
                  if ( v20 != nullptr )
                    CreateLODVertsInDictionary(
                      nLodID: j,
                      pRootLODSrc: pLOD0Source,
                      pCurrentLODSrc: v19,
                      pCurrLODMesh: v20,
                      pVertexDictMesh: v11,
                      vertexDict: &vertexDictionary,
                      pMeshVertIndexMap: pMeshVertIndexMaps[j]);
                }
              }
            }
          }
        }
LABEL_27:
        source = pSrcModel->source;
        v8 = v26 + 4;
        ++nMeshID;
        v26 += 4;
      }
      while ( nMeshID < source->nummeshes );
      m_pMemory = (unsigned __int8 *)meshes.m_Memory.m_pMemory;
    }
    SetProcessedWithDictionary(vertexDict: &vertexDictionary, pSrcModel, &faces, &meshes, pMeshVertIndexMaps);
    if ( meshes.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    if ( faces.m_Memory.m_nGrowSize >= 0 && faces.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: faces.m_Memory.m_pMemory);
    if ( vertexDictionary.m_Verts.m_Memory.m_nGrowSize >= 0 && vertexDictionary.m_Verts.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vertexDictionary.m_Verts.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004678A0
// Name: void UnifyLODs(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UnifyLODs()
{
  int i; // ebx
  int m_Size; // eax
  int v2; // esi
  int v3; // edi
  int v4; // edx
  s_model_t **m_pMemory; // ecx
  int v6; // eax
  int v7; // [esp+4h] [ebp-4h]

  if ( g_nummodelsbeforeLOD > 0 )
  {
    v7 = 0;
    for ( i = 1; i - 1 < g_nummodelsbeforeLOD; ++i )
    {
      m_Size = g_model.m_Size;
      if ( g_model.m_Size < i )
      {
        v2 = i - g_model.m_Size;
        v3 = g_model.m_Size;
        if ( i != g_model.m_Size )
        {
          v4 = i;
          if ( i > g_model.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&g_model,
              num: v2 + g_model.m_Size - g_model.m_Memory.m_nAllocationCount);
            m_Size = g_model.m_Size;
            v4 = i;
          }
          m_pMemory = g_model.m_Memory.m_pMemory;
          g_model.m_Size = v2 + m_Size;
          v6 = m_Size - v3;
          g_model.m_pElements = g_model.m_Memory.m_pMemory;
          if ( v6 <= 0 || v2 <= 0 )
            goto LABEL_11;
          _V_memmove(dest: &g_model.m_Memory.m_pMemory[v4], src: &g_model.m_Memory.m_pMemory[v3], count: 4 * v6);
        }
      }
      m_pMemory = g_model.m_Memory.m_pMemory;
LABEL_11:
      UnifyModelLODs(pSrcModel: m_pMemory[v7++]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00467960
// Name: GetLODSources
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetLODSources(CUtlVector<s_source_t *,CUtlMemory<s_source_t *,int> > *lods, const s_model_t *pSrcModel)
{
  int m_Size; // ebx
  int v3; // esi
  int v4; // edi
  s_source_t *ModelLODSource; // eax
  bool bFound; // [esp+Bh] [ebp-1h] BYREF

  m_Size = g_ScriptLODs.m_Size;
  if ( lods->m_Size < g_ScriptLODs.m_Size )
    CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
      this: (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)lods,
      elem: lods->m_Size,
      num: g_ScriptLODs.m_Size - lods->m_Size);
  v3 = 0;
  if ( m_Size > 0 )
  {
    v4 = 0;
    do
    {
      ModelLODSource = GetModelLODSource(
                         pModelName: pSrcModel->filename,
                         scriptLOD: &g_ScriptLODs.m_Memory.m_pMemory[v4],
                         pFound: &bFound);
      if ( ModelLODSource == nullptr && !bFound )
        ModelLODSource = pSrcModel->source;
      lods->m_Memory.m_pMemory[v3++] = ModelLODSource;
      ++v4;
    }
    while ( v3 < m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004679E0
// Name: void LoadLODSources(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadLODSources()
{
  int v0; // ebx
  int m_Size; // eax
  int v2; // esi
  int v3; // edi
  int v4; // edx
  s_model_t **m_pMemory; // ecx
  int v6; // eax
  bool v7; // zf
  int v8; // eax
  int v9; // edi
  int v10; // esi
  int v11; // ebx
  int v12; // edx
  s_model_t **v13; // ecx
  int v14; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v15; // esi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v17; // ecx
  int v18; // eax
  int i; // ebx
  int v20; // eax
  int v21; // esi
  int v22; // edi
  int v23; // edx
  s_model_t **v24; // ecx
  int v25; // eax
  int v26; // esi
  int v27; // edi
  s_model_t **v28; // ecx
  int v29; // esi
  int v30; // edi
  int v31; // edx
  int v32; // eax
  int v33; // [esp+0h] [ebp-10h]
  int nNumLODs; // [esp+4h] [ebp-Ch]
  const s_model_t **nNumLODsa; // [esp+4h] [ebp-Ch]
  int v36; // [esp+8h] [ebp-8h]
  int v37; // [esp+Ch] [ebp-4h]

  g_nummodelsbeforeLOD = g_nummodels;
  if ( g_nummodels > 0 )
  {
    v0 = 1;
    v37 = 0;
    v36 = 1;
    while ( 1 )
    {
      m_Size = g_model.m_Size;
      if ( g_model.m_Size >= v0 )
        goto LABEL_10;
      v2 = v0 - g_model.m_Size;
      v3 = g_model.m_Size;
      if ( v0 == g_model.m_Size )
        goto LABEL_10;
      v4 = v0;
      if ( v0 > g_model.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&g_model,
          num: v2 + g_model.m_Size - g_model.m_Memory.m_nAllocationCount);
        m_Size = g_model.m_Size;
        v4 = v0;
      }
      m_pMemory = g_model.m_Memory.m_pMemory;
      g_model.m_Size = v2 + m_Size;
      v6 = m_Size - v3;
      g_model.m_pElements = g_model.m_Memory.m_pMemory;
      if ( v6 > 0 && v2 > 0 )
        break;
LABEL_11:
      v7 = _V_stricmp(s1: m_pMemory[v37]->name, s2: "blank") == 0;
      v8 = g_model.m_Size;
      if ( !v7 )
      {
        if ( g_model.m_Size >= v0 || (v26 = v0 - g_model.m_Size, v27 = g_model.m_Size, v0 == g_model.m_Size) )
        {
          v28 = g_model.m_Memory.m_pMemory;
        }
        else
        {
          if ( v0 > g_model.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&g_model,
              num: g_model.m_Size + v26 - g_model.m_Memory.m_nAllocationCount);
            v8 = g_model.m_Size;
          }
          v28 = g_model.m_Memory.m_pMemory;
          v8 += v26;
          g_model.m_Size = v8;
          g_model.m_pElements = g_model.m_Memory.m_pMemory;
          if ( v8 - v27 - v26 > 0 && v26 > 0 )
          {
            _V_memmove(
              dest: &g_model.m_Memory.m_pMemory[v0],
              src: &g_model.m_Memory.m_pMemory[v27],
              count: 4 * (v8 - v27 - v26));
            v8 = g_model.m_Size;
            v28 = g_model.m_Memory.m_pMemory;
          }
          v0 = v36;
        }
        nNumLODsa = (const s_model_t **)&v28[v37];
        if ( v8 < v0 )
        {
          v29 = v0 - v8;
          v30 = v8;
          if ( v0 != v8 )
          {
            v31 = v0;
            if ( v0 > g_model.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&g_model,
                num: v0 - g_model.m_Memory.m_nAllocationCount);
              v8 = g_model.m_Size;
              v28 = g_model.m_Memory.m_pMemory;
              v31 = v0;
            }
            g_model.m_Size = v29 + v8;
            v32 = v8 - v30;
            g_model.m_pElements = v28;
            if ( v32 > 0 && v29 > 0 )
            {
              _V_memmove(dest: &v28[v31], src: &v28[v30], count: 4 * v32);
              v28 = g_model.m_Memory.m_pMemory;
            }
          }
        }
        GetLODSources(lods: &v28[v37]->m_LodSources, pSrcModel: *nNumLODsa);
        goto LABEL_37;
      }
      v9 = g_ScriptLODs.m_Size;
      nNumLODs = g_ScriptLODs.m_Size;
      if ( g_model.m_Size < v0 )
      {
        v10 = v0 - g_model.m_Size;
        v7 = v0 == g_model.m_Size;
        v11 = g_model.m_Size;
        if ( !v7 )
        {
          v12 = g_model.m_Size + v10;
          v33 = g_model.m_Size + v10;
          if ( g_model.m_Size + v10 > g_model.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&g_model,
              num: v10 + g_model.m_Size - g_model.m_Memory.m_nAllocationCount);
            v8 = g_model.m_Size;
            v12 = v33;
          }
          v13 = g_model.m_Memory.m_pMemory;
          g_model.m_Size = v10 + v8;
          v14 = v8 - v11;
          g_model.m_pElements = g_model.m_Memory.m_pMemory;
          if ( v14 <= 0 || v10 <= 0 )
            goto LABEL_20;
          _V_memmove(dest: &g_model.m_Memory.m_pMemory[v12], src: &g_model.m_Memory.m_pMemory[v11], count: 4 * v14);
        }
      }
      v13 = g_model.m_Memory.m_pMemory;
LABEL_20:
      v15 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)v13[v37];
      v15[3007].m_pMemory = nullptr;
      if ( v9 != 0 )
      {
        m_nAllocationCount = v15[3006].m_nAllocationCount;
        if ( v9 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v15 + 3006, num: v9 - m_nAllocationCount);
        v15[3007].m_pMemory = (CUtlSymbolTable::StringPool_t **)((char *)v15[3007].m_pMemory + v9);
        v17 = v15[3006].m_pMemory;
        v18 = (int)v15[3007].m_pMemory - v9;
        v15[3007].m_nAllocationCount = (int)v17;
        if ( v18 > 0 && v9 > 0 )
          _V_memmove(dest: &v17[v9], src: v17, count: 4 * v18);
      }
      for ( i = 0; i < v9; v24[v37]->m_LodSources.m_Memory.m_pMemory[i++] = nullptr )
      {
        v20 = g_model.m_Size;
        if ( g_model.m_Size < v36 )
        {
          v21 = v36 - g_model.m_Size;
          v22 = g_model.m_Size;
          if ( v36 != g_model.m_Size )
          {
            v23 = v36;
            if ( v36 > g_model.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&g_model,
                num: g_model.m_Size + v21 - g_model.m_Memory.m_nAllocationCount);
              v20 = g_model.m_Size;
              v23 = v36;
            }
            v24 = g_model.m_Memory.m_pMemory;
            g_model.m_Size = v21 + v20;
            v25 = v20 - v22;
            g_model.m_pElements = g_model.m_Memory.m_pMemory;
            if ( v25 > 0 && v21 > 0 )
            {
              _V_memmove(dest: &g_model.m_Memory.m_pMemory[v23], src: &g_model.m_Memory.m_pMemory[v22], count: 4 * v25);
              v24 = g_model.m_Memory.m_pMemory;
            }
            v9 = nNumLODs;
            continue;
          }
          v9 = nNumLODs;
        }
        v24 = g_model.m_Memory.m_pMemory;
      }
      v0 = v36;
LABEL_37:
      ++v37;
      v36 = ++v0;
      if ( v0 - 1 >= g_nummodelsbeforeLOD )
        return;
    }
    _V_memmove(dest: &g_model.m_Memory.m_pMemory[v4], src: &g_model.m_Memory.m_pMemory[v3], count: 4 * v6);
LABEL_10:
    m_pMemory = g_model.m_Memory.m_pMemory;
    goto LABEL_11;
  }
}

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x0045E480
// Name: SortBoneWeightByWeight
// Source: json
//------------------------------------------------------------------------------
void __cdecl SortBoneWeightByWeight(s_boneweight_t *boneWeight)
{
  s_boneweight_t *v1; // ebx
  int numbones; // ecx
  int v3; // esi
  int v4; // edi
  unsigned int v5; // ecx
  float *v6; // eax
  float v7; // xmm0_4
  int v8; // edx
  float v9; // xmm0_4
  int v10; // edx
  float v11; // xmm0_4
  int v12; // edx
  float v13; // xmm0_4
  int v14; // edx
  float *v15; // eax
  int v16; // ecx
  float v17; // xmm0_4
  int v18; // edx

  v1 = boneWeight;
  numbones = boneWeight->numbones;
  if ( boneWeight->numbones > 1 )
  {
    do
    {
      v3 = 0;
      v4 = numbones - 1;
      if ( numbones >= 5 )
      {
        v5 = ((unsigned int)(numbones - 5) >> 2) + 1;
        v6 = &v1->weight[1];
        v3 = 4 * v5;
        do
        {
          v7 = *(v6 - 1);
          if ( v7 < *v6 )
          {
            v8 = *((_DWORD *)v6 - 4);
            *(v6 - 4) = *(v6 - 3);
            *(v6 - 1) = *v6;
            *((_DWORD *)v6 - 3) = v8;
            *v6 = v7;
          }
          v9 = *v6;
          if ( *v6 < v6[1] )
          {
            v10 = *((_DWORD *)v6 - 3);
            *(v6 - 3) = *(v6 - 2);
            *v6 = v6[1];
            *((_DWORD *)v6 - 2) = v10;
            v6[1] = v9;
          }
          v11 = v6[1];
          if ( v11 < v6[2] )
          {
            v12 = *((_DWORD *)v6 - 2);
            *(v6 - 2) = *(v6 - 1);
            v6[1] = v6[2];
            *((_DWORD *)v6 - 1) = v12;
            v6[2] = v11;
          }
          v13 = v6[2];
          if ( v13 < v6[3] )
          {
            v14 = *((_DWORD *)v6 - 1);
            *(v6 - 1) = *v6;
            v6[2] = v6[3];
            *(_DWORD *)v6 = v14;
            v6[3] = v13;
          }
          v6 += 4;
          --v5;
        }
        while ( v5 != 0 );
        v1 = boneWeight;
      }
      if ( v3 < v4 )
      {
        v15 = &v1->weight[v3 + 1];
        v16 = v4 - v3;
        do
        {
          v17 = *(v15 - 1);
          if ( v17 < *v15 )
          {
            v18 = *((_DWORD *)v15 - 4);
            *(v15 - 4) = *(v15 - 3);
            *(v15 - 1) = *v15;
            *((_DWORD *)v15 - 3) = v18;
            *v15 = v17;
          }
          ++v15;
          --v16;
        }
        while ( v16 != 0 );
      }
      numbones = v4;
    }
    while ( v4 > 1 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045E590
// Name: SortBoneWeightByIndex
// Source: json
//------------------------------------------------------------------------------
void __cdecl SortBoneWeightByIndex(s_boneweight_t *boneWeight)
{
  s_boneweight_t *v1; // ebx
  int numbones; // ecx
  int v3; // esi
  int v4; // edi
  unsigned int v5; // ecx
  float *v6; // eax
  int v7; // edx
  int v8; // xmm0_4
  int v9; // edx
  float v10; // xmm0_4
  int v11; // edx
  int v12; // xmm0_4
  int v13; // edx
  int v14; // xmm0_4
  float *v15; // eax
  int v16; // ecx
  int v17; // edx
  int v18; // xmm0_4

  v1 = boneWeight;
  numbones = boneWeight->numbones;
  if ( boneWeight->numbones > 1 )
  {
    do
    {
      v3 = 0;
      v4 = numbones - 1;
      if ( numbones >= 5 )
      {
        v5 = ((unsigned int)(numbones - 5) >> 2) + 1;
        v6 = &v1->weight[1];
        v3 = 4 * v5;
        do
        {
          v7 = *((_DWORD *)v6 - 4);
          if ( v7 > *((_DWORD *)v6 - 3) )
          {
            v8 = *((_DWORD *)v6 - 1);
            *(v6 - 4) = *(v6 - 3);
            *(v6 - 1) = *v6;
            *((_DWORD *)v6 - 3) = v7;
            *(_DWORD *)v6 = v8;
          }
          v9 = *((_DWORD *)v6 - 3);
          if ( v9 > *((_DWORD *)v6 - 2) )
          {
            v10 = *v6;
            *(v6 - 3) = *(v6 - 2);
            *v6 = v6[1];
            *((_DWORD *)v6 - 2) = v9;
            v6[1] = v10;
          }
          v11 = *((_DWORD *)v6 - 2);
          if ( v11 > *((_DWORD *)v6 - 1) )
          {
            v12 = *((_DWORD *)v6 + 1);
            *(v6 - 2) = *(v6 - 1);
            v6[1] = v6[2];
            *((_DWORD *)v6 - 1) = v11;
            *((_DWORD *)v6 + 2) = v12;
          }
          v13 = *((_DWORD *)v6 - 1);
          if ( v13 > *(_DWORD *)v6 )
          {
            v14 = *((_DWORD *)v6 + 2);
            *(v6 - 1) = *v6;
            v6[2] = v6[3];
            *(_DWORD *)v6 = v13;
            *((_DWORD *)v6 + 3) = v14;
          }
          v6 += 4;
          --v5;
        }
        while ( v5 != 0 );
        v1 = boneWeight;
      }
      if ( v3 < v4 )
      {
        v15 = &v1->weight[v3 + 1];
        v16 = v4 - v3;
        do
        {
          v17 = *((_DWORD *)v15 - 4);
          if ( v17 > *((_DWORD *)v15 - 3) )
          {
            v18 = *((_DWORD *)v15 - 1);
            *(v15 - 4) = *(v15 - 3);
            *(v15 - 1) = *v15;
            *((_DWORD *)v15 - 3) = v17;
            *(_DWORD *)v15 = v18;
          }
          ++v15;
          --v16;
        }
        while ( v16 != 0 );
      }
      numbones = v4;
    }
    while ( v4 > 1 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045E6A0
// Name: bool CompareNormalFuzzy(class Vector const __near &,class Vector const __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CompareNormalFuzzy(const Vector *n1, const Vector *n2, float *flError)
{
  float v3; // xmm0_4
  bool v4; // cf
  Vector v1; // [esp+0h] [ebp-18h] BYREF
  Vector v2; // [esp+Ch] [ebp-Ch] BYREF

  if ( (_S1_2 & 1) == 0 )
  {
    _S1_2 |= 1u;
    __libm_sse2_cos(x: *(long double *)&v1.x);
    flEpsilon = 0.1745329201221466;
  }
  v1 = *n1;
  v2 = *n2;
  VectorNormalize(vec: &v1);
  VectorNormalize(vec: &v2);
  v3 = (float)((float)(v2.x * v1.x) + (float)(v2.y * v1.y)) + (float)(v2.z * v1.z);
  v4 = v3 < flEpsilon;
  *flError = 1.0 - v3;
  return !v4;
}

//------------------------------------------------------------------------------
// Address: 0x0045E780
// Name: bool CompareTangentSFuzzy(class Vector4D const __near &,class Vector4D const __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CompareTangentSFuzzy(const Vector4D *n1, const Vector4D *n2, float *flError)
{
  float w; // xmm0_4
  float v4; // xmm1_4
  float v6; // xmm0_4
  bool v7; // cf
  Vector4D v1; // [esp+0h] [ebp-20h] BYREF
  Vector4D v2; // [esp+10h] [ebp-10h] BYREF

  if ( (_S2_0 & 1) == 0 )
  {
    _S2_0 |= 1u;
    __libm_sse2_cos(x: *(long double *)&v1.x);
    flEpsilon_0 = 0.1745329201221466;
  }
  v1.x = n1->x;
  v1.y = n1->y;
  v1.z = n1->z;
  w = n1->w;
  v2.x = n2->x;
  v2.y = n2->y;
  v2.z = n2->z;
  v4 = n2->w;
  v1.w = w;
  v2.w = v4;
  if ( w == v4 )
  {
    VectorNormalize(vec: (Vector *)&v1);
    VectorNormalize(vec: (Vector *)&v2);
    v6 = (float)((float)(v2.x * v1.x) + (float)(v2.y * v1.y)) + (float)(v2.z * v1.z);
    v7 = v6 < flEpsilon_0;
    *flError = 1.0 - v6;
    return !v7;
  }
  else
  {
    *flError = 2.0;
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045E890
// Name: bool CompareBoneWeightsFuzzy(struct s_boneweight_t const __near &,struct s_boneweight_t const __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CompareBoneWeightsFuzzy(const s_boneweight_t *b1, const s_boneweight_t *b2, float *flError)
{
  int numbones; // ebx
  int v4; // esi
  int *bone; // eax
  int v6; // ecx
  int *v7; // edx
  int v9; // ecx
  float *weight; // esi
  int v11; // edi
  float v12; // xmm0_4
  int v13; // ecx
  float *v14; // esi
  float v15; // xmm0_4
  int pBoneIndexMap2[3]; // [esp+Ch] [ebp-20h] BYREF
  int pBoneIndexMap1[3]; // [esp+18h] [ebp-14h]
  int v18; // [esp+24h] [ebp-8h]
  int nMatchingBones; // [esp+28h] [ebp-4h]

  numbones = b2->numbones;
  v4 = 0;
  nMatchingBones = 0;
  if ( numbones > 0 )
    memset(pBoneIndexMap2, 0xFFu, 4 * numbones);
  v18 = b1->numbones;
  if ( v18 <= 0 )
    goto LABEL_13;
  bone = b1->bone;
  do
  {
    v6 = 0;
    pBoneIndexMap1[v4] = -1;
    if ( numbones > 0 )
    {
      v7 = b2->bone;
      while ( *v7 != *bone )
      {
        ++v6;
        ++v7;
        if ( v6 >= numbones )
          goto LABEL_11;
      }
      ++nMatchingBones;
      pBoneIndexMap1[v4] = v6;
      pBoneIndexMap2[v6] = v4;
    }
LABEL_11:
    ++v4;
    ++bone;
  }
  while ( v4 < v18 );
  if ( nMatchingBones != 0 )
  {
    v9 = 0;
    *flError = 0.0;
    if ( b1->numbones > 0 )
    {
      weight = b1->weight;
      do
      {
        v11 = pBoneIndexMap1[v9];
        v12 = *weight;
        if ( v11 != -1 )
          v12 = fabs(v12 - b2->weight[v11]);
        ++v9;
        *flError = (float)(v12 * v12) + *flError;
        ++weight;
      }
      while ( v9 < b1->numbones );
    }
    v13 = 0;
    if ( b2->numbones > 0 )
    {
      v14 = b2->weight;
      do
      {
        if ( pBoneIndexMap2[v13] == -1 )
          *flError = (float)(*v14 * *v14) + *flError;
        ++v13;
        ++v14;
      }
      while ( v13 < b2->numbones );
    }
    v15 = *flError / fsqrt((float)(b2->numbones + b1->numbones));
    *flError = v15;
    return v15 <= 0.050000001;
  }
  else
  {
LABEL_13:
    *flError = 3.4028235e38;
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045E9E0
// Name: int FindMaterialByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindMaterialByName(char *pMaterialName)
{
  unsigned int v1; // kr00_4
  void *v2; // esp
  int v3; // esi
  s_texture_t *i; // edi
  char v6[12]; // [esp+0h] [ebp-Ch] BYREF

  v1 = strlen(pMaterialName);
  v2 = alloca(v1 + 1);
  V_FileBase(in: pMaterialName, out: v6, maxlen: v1 + 1);
  v3 = 0;
  if ( g_numtextures <= 0 )
    return -1;
  for ( i = g_texture; _V_stricmp(s1: pMaterialName, s2: i->name) != 0; ++i )
  {
    if ( ++v3 >= g_numtextures )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0045EA60
// Name: CollapseBoneWeights
// Source: json
//------------------------------------------------------------------------------
void __usercall CollapseBoneWeights(s_boneweight_t *boneWeight@<esi>)
{
  int *v1; // eax
  int v2; // edx
  float *weight; // ecx
  float *v4; // edi
  int *v5; // eax
  int v6; // ebx
  s_boneweight_t *v7; // [esp+0h] [ebp-18h]
  int *v8; // [esp+4h] [ebp-14h]
  int j; // [esp+8h] [ebp-10h]
  int i; // [esp+Ch] [ebp-Ch]
  int *v11; // [esp+10h] [ebp-8h]
  int *bone; // [esp+14h] [ebp-4h]

  SortBoneWeightByIndex(boneWeight: v7);
  i = 0;
  if ( boneWeight->numbones - 1 > 0 )
  {
    bone = boneWeight->bone;
    v1 = &boneWeight->bone[1];
    v2 = 1;
    weight = boneWeight->weight;
    v4 = &boneWeight->weight[1];
    v8 = &boneWeight->bone[1];
    v11 = &boneWeight->bone[1];
    while ( 1 )
    {
      if ( *bone == *v1 )
      {
        *weight = *v4 + *weight;
        j = v2;
        if ( v2 < boneWeight->numbones - 1 )
        {
          v5 = v11;
          do
          {
            v6 = v5[1];
            ++j;
            v5[3] = v5[4];
            *v5++ = v6;
          }
          while ( j < boneWeight->numbones - 1 );
          v1 = v8;
        }
        --boneWeight->numbones;
        --i;
        --bone;
        --v1;
        --v4;
        --weight;
        --v2;
        --v11;
      }
      v8 = v1 + 1;
      ++bone;
      ++v11;
      ++v4;
      ++weight;
      ++v2;
      if ( ++i >= boneWeight->numbones - 1 )
        break;
      ++v1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045EB30
// Name: AreBoneWeightsEqual
// Source: json
//------------------------------------------------------------------------------
char __cdecl AreBoneWeightsEqual(const s_boneweight_t *b1, const s_boneweight_t *b2)
{
  const s_boneweight_t *v2; // eax
  int numbones; // ebx
  const s_boneweight_t *v4; // edi
  int v5; // edx
  int v7; // esi
  int v8; // eax
  int *v9; // ecx
  int v10; // ecx
  float *i; // edx
  int pBoneIndexMap[3]; // [esp+8h] [ebp-14h]
  int nMatchingBones; // [esp+14h] [ebp-8h]
  int *bone; // [esp+18h] [ebp-4h]

  v2 = b1;
  numbones = b1->numbones;
  v4 = b2;
  v5 = b2->numbones;
  if ( b1->numbones != b2->numbones )
    return 0;
  v7 = 0;
  nMatchingBones = 0;
  if ( numbones > 0 )
  {
    bone = b1->bone;
    do
    {
      v8 = 0;
      pBoneIndexMap[v7] = -1;
      if ( v5 > 0 )
      {
        v9 = b2->bone;
        while ( *v9 != *bone )
        {
          ++v8;
          ++v9;
          if ( v8 >= v5 )
            goto LABEL_11;
        }
        ++nMatchingBones;
        pBoneIndexMap[v7] = v8;
      }
LABEL_11:
      ++bone;
      ++v7;
    }
    while ( v7 < numbones );
    v2 = b1;
    v4 = b2;
  }
  if ( nMatchingBones != numbones )
    return 0;
  v10 = 0;
  if ( numbones > 0 )
  {
    for ( i = v2->weight; *i == v4->weight[pBoneIndexMap[v10]]; ++i )
    {
      if ( ++v10 >= numbones )
        return 1;
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045EBE0
// Name: SpewBoneInfo
// Source: json
//------------------------------------------------------------------------------
void __cdecl SpewBoneInfo(int globalBoneID, int depth)
{
  s_bonetable_t *v2; // edi
  int v3; // esi
  int i; // esi
  int v5; // esi
  int *p_parent; // edi

  v2 = &g_bonetable[globalBoneID];
  if ( g_bPrintBones )
  {
    if ( 2 * depth > 0 )
    {
      v3 = 2 * depth;
      do
      {
        printf(format: " ");
        --v3;
      }
      while ( v3 != 0 );
    }
    printf(format: "%d \"%s\" ", depth, v2->name);
  }
  for ( i = 0; i < 8; ++i )
  {
    if ( ((1024 << i) & v2->flags) != 0 )
    {
      if ( g_bPrintBones )
        printf(format: "lod%d ", i);
      ++g_NumBonesInLOD[i];
    }
  }
  if ( g_bPrintBones )
    printf(format: "\n");
  v5 = 0;
  if ( (int)g_numbones > 0 )
  {
    p_parent = &g_bonetable[0].parent;
    do
    {
      if ( *p_parent == globalBoneID )
        SpewBoneInfo(globalBoneID: v5, depth: depth + 1);
      ++v5;
      p_parent += 116;
    }
    while ( v5 < (int)g_numbones );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045ECC0
// Name: void MarkParentBoneLODs(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MarkParentBoneLODs()
{
  int *p_parent; // edx
  unsigned int v1; // esi
  int parent; // eax
  int i; // ecx
  int v4; // eax

  if ( (int)g_numbones > 0 )
  {
    p_parent = &g_bonetable[0].parent;
    v1 = g_numbones;
    do
    {
      parent = *p_parent;
      for ( i = p_parent[72] & 0x3FC00; parent != -1; parent = g_bonetable[v4].parent )
      {
        v4 = parent;
        g_bonetable[v4].flags |= i;
      }
      p_parent += 116;
      --v1;
    }
    while ( v1 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045ED10
// Name: public: VertexInfo_t::VertexInfo_t(struct VertexInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
VertexInfo_t *__thiscall VertexInfo_t::VertexInfo_t(VertexInfo_t *this, const VertexInfo_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0045ED90
// Name: void SpewBoneUsageStats(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SpewBoneUsageStats()
{
  int i; // esi

  *(_QWORD *)g_NumBonesInLOD = 0;
  *(_QWORD *)&g_NumBonesInLOD[2] = 0;
  *(_QWORD *)&g_NumBonesInLOD[4] = 0;
  *(_QWORD *)&g_NumBonesInLOD[6] = 0;
  if ( g_numbones != 0 )
  {
    SpewBoneInfo(globalBoneID: 0, depth: 0);
    if ( g_bPrintBones )
    {
      for ( i = 0; i < g_ScriptLODs.m_Size; ++i )
        printf(format: "\t%d bones used in lod %d\n", g_NumBonesInLOD[i], i);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045EEB0
// Name: struct s_source_t __near * GetModelLODSource(char const __near *,struct LodScriptData_t const __near &,bool __near *)
// Source: json
//------------------------------------------------------------------------------
s_source_t *__cdecl GetModelLODSource(char *pModelName, const LodScriptData_t *scriptLOD, bool *pFound)
{
  void *v3; // esp
  _BYTE *v4; // eax
  int v5; // esi
  int v6; // ebx
  char v8[12]; // [esp+0h] [ebp-Ch] BYREF
  char *str; // [esp+14h] [ebp+8h]

  v3 = alloca(_V_strlen(str: pModelName) + 1);
  str = strcpy(v8, pModelName);
  strrchr(string: (unsigned __int8 *)v8, chr: 0x2Eu);
  if ( v4 != nullptr )
    *v4 = 0;
  v5 = 0;
  if ( scriptLOD->modelReplacements.m_Size <= 0 )
  {
LABEL_7:
    *pFound = false;
    return nullptr;
  }
  else
  {
    v6 = 0;
    while ( _V_stricmp(s1: str, s2: scriptLOD->modelReplacements.m_Memory.m_pMemory[v6].m_pSrcName) != 0 )
    {
      ++v5;
      ++v6;
      if ( v5 >= scriptLOD->modelReplacements.m_Size )
        goto LABEL_7;
    }
    *pFound = true;
    return scriptLOD->modelReplacements.m_Memory.m_pMemory[v5].m_pSource;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045EF50
// Name: FindOrCullMesh
// Source: json
//------------------------------------------------------------------------------
s_mesh_t *__cdecl FindOrCullMesh(int nLodID, s_source_t *pSrc, int nMaterialID)
{
  int v3; // ebx
  int v4; // esi
  LodScriptData_t *m_pMemory; // eax
  int v6; // esi
  int v7; // edi
  int v8; // ebx
  int nummeshes; // edx
  int v10; // eax
  int *i; // ecx
  char baseRemovalName[260]; // [esp+Ch] [ebp-208h] BYREF
  char baseMeshName[260]; // [esp+110h] [ebp-104h] BYREF

  v3 = nMaterialID;
  v4 = MaterialToTexture(material: nMaterialID);
  if ( v4 == -1 )
    MdlError(fmt: "Unknown Texture for Material %d\n", nMaterialID);
  V_FileBase(in: g_texture[v4].name, out: baseMeshName, maxlen: 259);
  m_pMemory = g_ScriptLODs.m_Memory.m_pMemory;
  v6 = nLodID;
  v7 = 0;
  if ( g_ScriptLODs.m_Memory.m_pMemory[nLodID].meshRemovals.m_Size > 0 )
  {
    v8 = 0;
    while ( 1 )
    {
      V_FileBase(in: m_pMemory[v6].meshRemovals.m_Memory.m_pMemory[v8].m_pSrcName, out: baseRemovalName, maxlen: 259);
      if ( _V_stricmp(s1: baseRemovalName, s2: baseMeshName) == 0 )
        return nullptr;
      m_pMemory = g_ScriptLODs.m_Memory.m_pMemory;
      ++v7;
      ++v8;
      if ( v7 >= g_ScriptLODs.m_Memory.m_pMemory[v6].meshRemovals.m_Size )
      {
        v3 = nMaterialID;
        break;
      }
    }
  }
  nummeshes = pSrc->nummeshes;
  v10 = 0;
  if ( nummeshes <= 0 )
    return nullptr;
  for ( i = pSrc->meshindex; *i != v3; ++i )
  {
    if ( ++v10 >= nummeshes )
      return nullptr;
  }
  return &pSrc->mesh[pSrc->meshindex[v10]];
}

//------------------------------------------------------------------------------
// Address: 0x0045F040
// Name: FindVertexWithinVertexDictionary
// Source: json
//------------------------------------------------------------------------------
int __usercall FindVertexWithinVertexDictionary@<eax>(
        const VertexInfo_t *find@<edi>,
        int nStartVert@<ecx>,
        char fIgnore@<al>,
        const CVertexDictionary *vertexDict,
        int nEndVert)
{
  int v6; // ecx
  float v7; // xmm2_4
  float v8; // xmm3_4
  int i; // esi
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  bool v14; // al
  bool v15; // al
  float v16; // xmm0_4
  int v18; // [esp+0h] [ebp-44h]
  int v19; // [esp+4h] [ebp-40h]
  int v20; // [esp+8h] [ebp-3Ch]
  int v21; // [esp+Ch] [ebp-38h]
  int v22; // [esp+10h] [ebp-34h]
  int nBestIndex; // [esp+14h] [ebp-30h]
  int nVertexIndex; // [esp+18h] [ebp-2Ch]
  unsigned __int64 flMinTangentSError; // [esp+1Ch] [ebp-28h]
  float flMinBoneWeightError; // [esp+24h] [ebp-20h]
  float flMinTexcoordError; // [esp+28h] [ebp-1Ch]
  float flMinPositionError; // [esp+2Ch] [ebp-18h]
  float flTangentSError; // [esp+30h] [ebp-14h] BYREF
  float flNormalError; // [esp+34h] [ebp-10h] BYREF
  float flBoneWeightError; // [esp+38h] [ebp-Ch] BYREF
  float flTexcoordError; // [esp+3Ch] [ebp-8h]
  float flPositionError; // [esp+40h] [ebp-4h]

  v6 = fIgnore & 1;
  v7 = 0.0;
  v8 = 0.0;
  nBestIndex = -1;
  flPositionError = 0.0;
  flNormalError = 0.0;
  flTangentSError = 0.0;
  flTexcoordError = 0.0;
  flBoneWeightError = 0.0;
  flMinPositionError = 3.4028235e38;
  flMinTangentSError = 0x7F7FFFFF7F7FFFFFLL;
  flMinTexcoordError = 3.4028235e38;
  flMinBoneWeightError = 3.4028235e38;
  v22 = v6;
  if ( (fIgnore & 1) != 0 )
  {
    flMinPositionError = 0.0;
    flPositionError = 0.0;
  }
  v21 = fIgnore & 2;
  if ( (fIgnore & 2) != 0 )
  {
    v8 = 0.0;
    flMinTexcoordError = 0.0;
    flTexcoordError = 0.0;
  }
  v20 = fIgnore & 4;
  if ( (fIgnore & 4) != 0 )
  {
    flMinBoneWeightError = 0.0;
    flBoneWeightError = 0.0;
  }
  v19 = fIgnore & 8;
  if ( (fIgnore & 8) != 0 )
  {
    HIDWORD(flMinTangentSError) = 0;
    flNormalError = 0.0;
  }
  v18 = fIgnore & 0x10;
  if ( (fIgnore & 0x10) != 0 )
  {
    LODWORD(flMinTangentSError) = 0;
    flTangentSError = 0.0;
  }
  nVertexIndex = nStartVert;
  if ( nStartVert < nEndVert )
  {
    for ( i = nStartVert; ; ++i )
    {
      if ( v6 != 0
        || (v10 = find->m_Position.y - vertexDict->m_Verts.m_Memory.m_pMemory[i].m_Position.y,
            v11 = find->m_Position.z - vertexDict->m_Verts.m_Memory.m_pMemory[i].m_Position.z,
            v7 = (float)((float)((float)(find->m_Position.x - vertexDict->m_Verts.m_Memory.m_pMemory[i].m_Position.x)
                               * (float)(find->m_Position.x - vertexDict->m_Verts.m_Memory.m_pMemory[i].m_Position.x))
                       + (float)(v10 * v10))
               + (float)(v11 * v11),
            flPositionError = v7,
            v7 <= 0.0025000002) )
      {
        if ( v21 != 0
          || (v12 = fabs(vertexDict->m_Verts.m_Memory.m_pMemory[i].m_TexCoord.x - find->m_TexCoord.x),
              v13 = fabs(vertexDict->m_Verts.m_Memory.m_pMemory[i].m_TexCoord.y - find->m_TexCoord.y),
              v8 = (float)(v13 * v13) + (float)(v12 * v12),
              flTexcoordError = v8,
              v8 <= 0.000099999997) )
        {
          if ( v20 != 0
            || CompareBoneWeightsFuzzy(
                 b1: &find->m_BoneWeight,
                 b2: &vertexDict->m_Verts.m_Memory.m_pMemory[i].m_BoneWeight,
                 flError: &flBoneWeightError) )
          {
            if ( v19 != 0
              || (v14 = CompareNormalFuzzy(
                          n1: &find->m_Normal,
                          n2: &vertexDict->m_Verts.m_Memory.m_pMemory[i].m_Normal,
                          flError: &flNormalError),
                  v7 = flPositionError,
                  v8 = flTexcoordError,
                  v14) )
            {
              if ( v18 != 0
                || (v15 = CompareTangentSFuzzy(
                            n1: &find->m_TangentS,
                            n2: &vertexDict->m_Verts.m_Memory.m_pMemory[i].m_TangentS,
                            flError: &flTangentSError),
                    v7 = flPositionError,
                    v8 = flTexcoordError,
                    v15) )
              {
                if ( flMinPositionError > v7 )
                  goto LABEL_34;
                if ( flMinPositionError != v7 )
                  goto LABEL_36;
                if ( flMinTexcoordError > v8 )
                {
LABEL_34:
                  v16 = flBoneWeightError;
LABEL_35:
                  flMinBoneWeightError = v16;
                  flMinPositionError = v7;
                  flMinTexcoordError = v8;
                  flMinTangentSError = __PAIR64__(LODWORD(flNormalError), LODWORD(flTangentSError));
                  nBestIndex = nVertexIndex;
                  goto LABEL_36;
                }
                if ( flMinTexcoordError == v8 )
                {
                  v16 = flBoneWeightError;
                  if ( flMinBoneWeightError > flBoneWeightError
                    || flMinBoneWeightError == flBoneWeightError
                    && (*((float *)&flMinTangentSError + 1) > flNormalError
                     || *((float *)&flMinTangentSError + 1) == flNormalError
                     && *(float *)&flMinTangentSError >= flTangentSError) )
                  {
                    goto LABEL_35;
                  }
                }
              }
            }
          }
        }
      }
LABEL_36:
      if ( ++nVertexIndex >= nEndVert )
        return nBestIndex;
      v6 = v22;
    }
  }
  return nBestIndex;
}

//------------------------------------------------------------------------------
// Address: 0x0045F2F0
// Name: FindBoneWeightWithinModel
// Source: json
//------------------------------------------------------------------------------
void __usercall FindBoneWeightWithinModel(
        const VertexInfo_t *searchVertex@<edi>,
        char fIgnore@<al>,
        int a3@<esi>,
        const s_source_t *pSrc,
        s_boneweight_t *boneWeight)
{
  float v5; // xmm0_4
  int v6; // ecx
  float v7; // xmm2_4
  s_vertexinfo_t *v8; // esi
  float v9; // xmm3_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  s_vertexinfo_t *m_pMemory; // eax
  __int64 v13; // xmm0_8
  int p_boneweight; // eax
  __int128 v15; // [esp-4h] [ebp-58h] BYREF
  Vector normal; // [esp+Ch] [ebp-48h] BYREF
  int nVertexCount; // [esp+18h] [ebp-3Ch]
  int v18; // [esp+1Ch] [ebp-38h]
  int v19; // [esp+20h] [ebp-34h]
  int v20; // [esp+24h] [ebp-30h]
  float flMinPositionError; // [esp+28h] [ebp-2Ch]
  float flPositionError; // [esp+2Ch] [ebp-28h]
  unsigned int v23; // [esp+30h] [ebp-24h]
  int i; // [esp+34h] [ebp-20h]
  float flMinTangentSError; // [esp+38h] [ebp-1Ch]
  float flMinNormalError; // [esp+3Ch] [ebp-18h]
  float flMinTexcoordError; // [esp+40h] [ebp-14h]
  float flNormalError; // [esp+44h] [ebp-10h]
  int nBestIndex; // [esp+48h] [ebp-Ch]
  float flTangentSError; // [esp+4Ch] [ebp-8h] BYREF
  float flTexcoordError; // [esp+50h] [ebp-4h]

  v5 = 0.0;
  LODWORD(v15) = a3;
  v6 = fIgnore & 8;
  v7 = 0.0;
  nBestIndex = -1;
  flNormalError = 0.0;
  flTangentSError = 0.0;
  flTexcoordError = 0.0;
  flMinPositionError = 3.4028235e38;
  flMinNormalError = 3.4028235e38;
  flMinTangentSError = 3.4028235e38;
  flMinTexcoordError = 3.4028235e38;
  v20 = v6;
  if ( (fIgnore & 8) != 0 )
  {
    flMinNormalError = 0.0;
    flNormalError = 0.0;
  }
  v19 = fIgnore & 2;
  if ( (fIgnore & 2) != 0 )
  {
    v7 = 0.0;
    flMinTexcoordError = 0.0;
    flTexcoordError = 0.0;
  }
  v18 = fIgnore & 0x10;
  if ( (fIgnore & 0x10) != 0 )
  {
    flMinTangentSError = 0.0;
    flTangentSError = 0.0;
  }
  nVertexCount = pSrc->m_GlobalVertices.m_Size;
  i = 0;
  if ( nVertexCount <= 0 )
    goto LABEL_28;
  v23 = 0;
  while ( 1 )
  {
    v8 = &pSrc->m_GlobalVertices.m_Memory.m_pMemory[v23 / 0x54];
    v9 = (float)((float)((float)(searchVertex->m_Position.y - v8->position.y)
                       * (float)(searchVertex->m_Position.y - v8->position.y))
               + (float)((float)(searchVertex->m_Position.x - v8->position.x)
                       * (float)(searchVertex->m_Position.x - v8->position.x)))
       + (float)((float)(searchVertex->m_Position.z - v8->position.z)
               * (float)(searchVertex->m_Position.z - v8->position.z));
    flPositionError = v9;
    if ( v6 == 0 )
    {
      if ( (_S1_2 & 1) == 0 )
      {
        _S1_2 |= 1u;
        __libm_sse2_cos(x: *(long double *)&v15);
        flEpsilon = 0.1745329201221466;
      }
      *(Vector *)((char *)&v15 + 4) = searchVertex->m_Normal;
      normal = v8->normal;
      VectorNormalize(vec: (Vector *)((char *)&v15 + 4));
      VectorNormalize(vec: &normal);
      v7 = flTexcoordError;
      v9 = flPositionError;
      v5 = 1.0
         - (float)((float)((float)(normal.y * *((float *)&v15 + 2)) + (float)(normal.x * *((float *)&v15 + 1)))
                 + (float)(normal.z * *((float *)&v15 + 3)));
      flNormalError = v5;
    }
    if ( v19 == 0 )
    {
      LODWORD(v10) = COERCE_UNSIGNED_INT(v8->texcoord.y - searchVertex->m_TexCoord.y) & _mask__AbsFloat_;
      LODWORD(v11) = COERCE_UNSIGNED_INT(v8->texcoord.x - searchVertex->m_TexCoord.x) & _mask__AbsFloat_;
      v7 = (float)(v10 * v10) + (float)(v11 * v11);
      flTexcoordError = v7;
    }
    if ( v18 == 0 )
    {
      CompareTangentSFuzzy(n1: &searchVertex->m_TangentS, n2: &v8->tangentS, flError: &flTangentSError);
      v7 = flTexcoordError;
      v5 = flNormalError;
      v9 = flPositionError;
    }
    if ( flMinPositionError > v9
      || flMinPositionError == v9
      && (flMinTexcoordError > v7
       || flMinTexcoordError == v7
       && (flMinNormalError > v5 || flMinNormalError == v5 && flMinTangentSError >= flTangentSError)) )
    {
      flMinPositionError = v9;
      flMinTexcoordError = v7;
      flMinNormalError = v5;
      flMinTangentSError = flTangentSError;
      nBestIndex = i;
    }
    v23 += 84;
    if ( ++i >= nVertexCount )
      break;
    v6 = v20;
  }
  if ( nBestIndex == -1 )
LABEL_28:
    MdlError(fmt: "Encountered a mesh with no vertices!\n");
  m_pMemory = pSrc->m_GlobalVertices.m_Memory.m_pMemory;
  v13 = *(_QWORD *)&m_pMemory[nBestIndex].boneweight.numbones;
  p_boneweight = (int)&m_pMemory[nBestIndex].boneweight;
  *(_QWORD *)&boneWeight->numbones = v13;
  *(_QWORD *)&boneWeight->bone[1] = *(_QWORD *)(p_boneweight + 8);
  *(_QWORD *)boneWeight->weight = *(_QWORD *)(p_boneweight + 16);
  boneWeight->weight[2] = *(float *)(p_boneweight + 24);
}

//------------------------------------------------------------------------------
// Address: 0x0045F5D0
// Name: FindVertexInDictionaryExact
// Source: json
//------------------------------------------------------------------------------
int __usercall FindVertexInDictionaryExact@<eax>(
        CVertexDictionary *vertexDict@<ecx>,
        int nStartVert@<eax>,
        const VertexInfo_t *vertex@<edi>,
        int nEndVert)
{
  float x; // xmm1_4
  VertexInfo_t *v5; // ebx
  float *i; // esi
  int nVertID; // [esp+8h] [ebp-4h]

  nVertID = nStartVert;
  if ( nStartVert >= nEndVert )
    return -1;
  x = vertex->m_Position.x;
  v5 = &vertexDict->m_Verts.m_Memory.m_pMemory[nStartVert];
  for ( i = &v5->m_Normal.y;
        x != v5->m_Position.x
     || vertex->m_Position.y != *(i - 3)
     || vertex->m_Position.z != *(i - 2)
     || AreBoneWeightsEqual(b1: (const s_boneweight_t *)(i + 8), b2: &vertex->m_BoneWeight) == 0
     || vertex->m_TexCoord.x != i[2]
     || vertex->m_TexCoord.y != i[3]
     || vertex->m_Normal.x != *(i - 1)
     || vertex->m_Normal.y != *i
     || vertex->m_Normal.z != i[1]
     || vertex->m_TangentS.x != i[4]
     || vertex->m_TangentS.y != i[5]
     || vertex->m_TangentS.z != i[6]
     || vertex->m_TangentS.w != i[7];
        i += 20 )
  {
    ++v5;
    if ( ++nVertID >= nEndVert )
      return -1;
  }
  return nVertID;
}

//------------------------------------------------------------------------------
// Address: 0x0045F6F0
// Name: SetProcessedWithDictionary
// Source: json
//------------------------------------------------------------------------------
void __usercall SetProcessedWithDictionary(
        CVertexDictionary *vertexDict@<edi>,
        s_model_t *pSrcModel,
        CUtlVector<s_face_t,CUtlMemory<s_face_t,int> > *faces,
        CUtlVector<s_mesh_t,CUtlMemory<s_mesh_t,int> > *meshes,
        int **pMeshVertIndexMaps)
{
  void *v5; // esi
  signed int v6; // ebx
  signed int v7; // eax
  int v8; // edx
  VertexInfo_t *v9; // eax
  char *v10; // ecx
  VertexInfo_t *v11; // eax
  int v12; // ecx
  int v13; // ecx
  int v14; // ebx
  VertexInfo_t *v15; // eax
  int v16; // ecx
  char *v17; // ebx
  VertexInfo_t *v18; // eax
  int v19; // ecx
  char *v20; // ecx
  bool v21; // zf
  unsigned int v22; // edx
  VertexInfo_t *m_pMemory; // eax
  char *v24; // ecx
  float v25; // ebx
  VertexInfo_t *v26; // eax
  signed int nVertexCount; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]
  unsigned int v29; // [esp+10h] [ebp-4h]
  int v30; // [esp+10h] [ebp-4h]
  s_model_t *pSrcModela; // [esp+1Ch] [ebp+8h]
  s_model_t *pSrcModelb; // [esp+1Ch] [ebp+8h]

  v5 = MemAlloc_Alloc(nSize: 0x230u);
  memset(dst: (unsigned __int8 *)v5, value: 0, count: 0x230u);
  pSrcModel->m_pLodData = (s_loddata_t *)v5;
  nVertexCount = vertexDict->m_Verts.m_Size;
  v6 = nVertexCount;
  *((_DWORD *)v5 + 1) = calloc(count: nVertexCount, size: 0x58u);
  *(_DWORD *)v5 = nVertexCount;
  *((_DWORD *)v5 + 3) = calloc(count: faces->m_Size, size: 0x10u);
  v7 = 0;
  *((_DWORD *)v5 + 2) = faces->m_Size;
  if ( nVertexCount >= 4 )
  {
    v8 = 0;
    pSrcModela = nullptr;
    v29 = ((unsigned int)(nVertexCount - 4) >> 2) + 1;
    i = 4 * v29;
    do
    {
      v9 = &vertexDict->m_Verts.m_Memory.m_pMemory[v8];
      v10 = &pSrcModela->name[*((_DWORD *)v5 + 1)];
      *((_QWORD *)v10 + 7) = *(_QWORD *)&v9->m_BoneWeight.numbones;
      *((_QWORD *)v10 + 8) = *(_QWORD *)&v9->m_BoneWeight.bone[1];
      *((_QWORD *)v10 + 9) = *(_QWORD *)v9->m_BoneWeight.weight;
      *((_DWORD *)v10 + 20) = LODWORD(v9->m_BoneWeight.weight[2]);
      *((float *)v10 + 2) = v9->m_Position.x;
      *((float *)v10 + 3) = v9->m_Position.y;
      *((float *)v10 + 4) = v9->m_Position.z;
      *((float *)v10 + 5) = v9->m_Normal.x;
      *((float *)v10 + 6) = v9->m_Normal.y;
      *((float *)v10 + 7) = v9->m_Normal.z;
      *((float *)v10 + 12) = v9->m_TexCoord.x;
      *((float *)v10 + 13) = v9->m_TexCoord.y;
      *((float *)v10 + 8) = v9->m_TangentS.x;
      *((float *)v10 + 9) = v9->m_TangentS.y;
      *((float *)v10 + 10) = v9->m_TangentS.z;
      *((float *)v10 + 11) = v9->m_TangentS.w;
      *((_DWORD *)v10 + 21) = v9->m_nLodFlag;
      v11 = &vertexDict->m_Verts.m_Memory.m_pMemory[v8 + 1];
      v12 = *((_DWORD *)v5 + 1);
      *(_QWORD *)&pSrcModela->filename[v12 + 16] = *(_QWORD *)&vertexDict->m_Verts.m_Memory.m_pMemory[v8 + 1].m_BoneWeight.numbones;
      *(_QWORD *)&pSrcModela->filename[v12 + 24] = *(_QWORD *)&v11->m_BoneWeight.bone[1];
      *(_QWORD *)&pSrcModela->filename[v12 + 32] = *(_QWORD *)v11->m_BoneWeight.weight;
      v13 = (int)&pSrcModela->name[v12 + 88];
      *(float *)(v13 + 80) = v11->m_BoneWeight.weight[2];
      *(Vector *)(v13 + 8) = v11->m_Position;
      *(Vector *)(v13 + 20) = v11->m_Normal;
      *(Vector2D *)(v13 + 48) = v11->m_TexCoord;
      *(Vector4D *)(v13 + 32) = v11->m_TangentS;
      *(_DWORD *)(v13 + 84) = v11->m_nLodFlag;
      v14 = *((_DWORD *)v5 + 1);
      v15 = &vertexDict->m_Verts.m_Memory.m_pMemory[v8 + 2];
      v16 = (int)&pSrcModela->filename[v14 + 48];
      *(s_boneweight_t *)&pSrcModela->filename[v14 + 104] = vertexDict->m_Verts.m_Memory.m_pMemory[v8 + 2].m_BoneWeight;
      *(Vector *)(v16 + 8) = v15->m_Position;
      v17 = &pSrcModela->filename[136];
      pSrcModela = (s_model_t *)((char *)pSrcModela + 352);
      *(Vector *)(v16 + 20) = v15->m_Normal;
      *(Vector2D *)(v16 + 48) = v15->m_TexCoord;
      *(Vector4D *)(v16 + 32) = v15->m_TangentS;
      *(_DWORD *)(v16 + 84) = v15->m_nLodFlag;
      v18 = &vertexDict->m_Verts.m_Memory.m_pMemory[v8 + 3];
      v19 = *((_DWORD *)v5 + 1);
      *(_QWORD *)&v17[v19 + 56] = *(_QWORD *)&v18->m_BoneWeight.numbones;
      *(_QWORD *)&v17[v19 + 64] = *(_QWORD *)&v18->m_BoneWeight.bone[1];
      *(_QWORD *)&v17[v19 + 72] = *(_QWORD *)v18->m_BoneWeight.weight;
      v20 = &v17[v19];
      *((_DWORD *)v20 + 20) = LODWORD(v18->m_BoneWeight.weight[2]);
      *((float *)v20 + 2) = v18->m_Position.x;
      v8 += 4;
      v21 = v29-- == 1;
      *((float *)v20 + 3) = v18->m_Position.y;
      *((float *)v20 + 4) = v18->m_Position.z;
      *((float *)v20 + 5) = v18->m_Normal.x;
      *((float *)v20 + 6) = v18->m_Normal.y;
      *((float *)v20 + 7) = v18->m_Normal.z;
      *((float *)v20 + 12) = v18->m_TexCoord.x;
      *((float *)v20 + 13) = v18->m_TexCoord.y;
      *((float *)v20 + 8) = v18->m_TangentS.x;
      *((float *)v20 + 9) = v18->m_TangentS.y;
      *((float *)v20 + 10) = v18->m_TangentS.z;
      *((float *)v20 + 11) = v18->m_TangentS.w;
      *((_DWORD *)v20 + 21) = v18->m_nLodFlag;
    }
    while ( !v21 );
    v7 = i;
    v6 = nVertexCount;
  }
  if ( v7 < v6 )
  {
    v22 = v7;
    pSrcModelb = (s_model_t *)(88 * v7);
    v30 = v6 - v7;
    do
    {
      m_pMemory = vertexDict->m_Verts.m_Memory.m_pMemory;
      v24 = &pSrcModelb->name[*((_DWORD *)v5 + 1)];
      *((_QWORD *)v24 + 7) = *(_QWORD *)&vertexDict->m_Verts.m_Memory.m_pMemory[v22].m_BoneWeight.numbones;
      *((_QWORD *)v24 + 8) = *(_QWORD *)&m_pMemory[v22].m_BoneWeight.bone[1];
      *((_QWORD *)v24 + 9) = *(_QWORD *)m_pMemory[v22].m_BoneWeight.weight;
      v25 = m_pMemory[v22].m_BoneWeight.weight[2];
      v26 = &m_pMemory[v22];
      *((float *)v24 + 20) = v25;
      *((float *)v24 + 2) = v26->m_Position.x;
      pSrcModelb = (s_model_t *)((char *)pSrcModelb + 88);
      ++v22;
      v21 = v30-- == 1;
      *((float *)v24 + 3) = v26->m_Position.y;
      *((float *)v24 + 4) = v26->m_Position.z;
      *((float *)v24 + 5) = v26->m_Normal.x;
      *((float *)v24 + 6) = v26->m_Normal.y;
      *((float *)v24 + 7) = v26->m_Normal.z;
      *((float *)v24 + 12) = v26->m_TexCoord.x;
      *((float *)v24 + 13) = v26->m_TexCoord.y;
      *((float *)v24 + 8) = v26->m_TangentS.x;
      *((float *)v24 + 9) = v26->m_TangentS.y;
      *((float *)v24 + 10) = v26->m_TangentS.z;
      *((float *)v24 + 11) = v26->m_TangentS.w;
      *((_DWORD *)v24 + 21) = v26->m_nLodFlag;
    }
    while ( !v21 );
  }
  memcpy(
    dst: *((unsigned __int8 **)v5 + 3),
    src: (unsigned __int8 *)faces->m_Memory.m_pMemory,
    count: 16 * faces->m_Size);
  memcpy(
    dst: (unsigned __int8 *)v5 + 16,
    src: (unsigned __int8 *)meshes->m_Memory.m_pMemory,
    count: 16 * meshes->m_Size);
  *((_DWORD *)v5 + 132) = *pMeshVertIndexMaps;
  *((_DWORD *)v5 + 133) = pMeshVertIndexMaps[1];
  *((_DWORD *)v5 + 134) = pMeshVertIndexMaps[2];
  *((_DWORD *)v5 + 135) = pMeshVertIndexMaps[3];
  *((_DWORD *)v5 + 136) = pMeshVertIndexMaps[4];
  *((_DWORD *)v5 + 137) = pMeshVertIndexMaps[5];
  *((_DWORD *)v5 + 138) = pMeshVertIndexMaps[6];
  *((_DWORD *)v5 + 139) = pMeshVertIndexMaps[7];
}

//------------------------------------------------------------------------------
// Address: 0x0045FAF0
// Name: void FixupReplacedBones(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FixupReplacedBones()
{
  int v0; // ebx
  char *v1; // ebx
  int v2; // eax
  int v3; // edi
  int v4; // ecx
  int v5; // esi
  int v6; // eax
  const char *v7; // edi
  void **v8; // esi
  void *v9; // eax
  const char *v10; // ecx
  _BYTE *v11; // edx
  char v12; // al
  int v13; // [esp+4h] [ebp-1Ch]
  int i; // [esp+8h] [ebp-18h]
  int v15; // [esp+Ch] [ebp-14h]
  int v16; // [esp+10h] [ebp-10h]
  int v17; // [esp+14h] [ebp-Ch]
  int v18; // [esp+18h] [ebp-8h]
  char v19; // [esp+1Fh] [ebp-1h]

  v0 = 0;
  i = 0;
  if ( g_ScriptLODs.m_Size > 0 )
  {
    v13 = 0;
    do
    {
      v1 = (char *)g_ScriptLODs.m_Memory.m_pMemory + v0;
      do
      {
        v2 = *((_DWORD *)v1 + 9);
        v3 = 0;
        v19 = 0;
        v18 = 0;
        if ( v2 <= 0 )
          break;
        v15 = 0;
        do
        {
          v4 = 0;
          v17 = 0;
          if ( v2 > 0 )
          {
            v5 = 0;
            v16 = 0;
            do
            {
              if ( v18 != v4
                && _V_stricmp(
                     s1: *(const char **)(v3 + *((_DWORD *)v1 + 6) + 4),
                     s2: *(const char **)(v5 + *((_DWORD *)v1 + 6) + 8)) == 0 )
              {
                v6 = *((_DWORD *)v1 + 6);
                v7 = *(const char **)(v3 + v6 + 8);
                v8 = (void **)(v5 + v6 + 8);
                if ( *v8 != nullptr )
                  free(pMem: *v8);
                v9 = MemAlloc_Alloc(nSize: strlen(v7) + 1);
                *v8 = v9;
                v10 = v7;
                v11 = v9;
                do
                {
                  v12 = *v10;
                  *v11++ = *v10++;
                }
                while ( v12 != 0 );
                v5 = v16;
                v3 = v15;
                v19 = 1;
              }
              v4 = v17 + 1;
              v5 += 12;
              v17 = v4;
              v16 = v5;
            }
            while ( v4 < *((_DWORD *)v1 + 9) );
          }
          v2 = *((_DWORD *)v1 + 9);
          v3 += 12;
          ++v18;
          v15 = v3;
        }
        while ( v18 < v2 );
      }
      while ( v19 != 0 );
      v0 = v13 + 108;
      ++i;
      v13 += 108;
    }
    while ( i < g_ScriptLODs.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045FC10
// Name: CopyVerts
// Source: json
//------------------------------------------------------------------------------
void __usercall CopyVerts(
        char nLodID@<cl>,
        CVertexDictionary *vertexDict@<edi>,
        const s_source_t *pSrc,
        const s_mesh_t *pSrcMesh,
        s_mesh_t *pDstMesh,
        int *pMeshVertIndexMap)
{
  const s_mesh_t *v6; // eax
  int vertexoffset; // ebx
  int m_Size; // esi
  int m_nAllocationCount; // eax
  int v10; // ebx
  VertexInfo_t *m_pMemory; // ecx
  int v12; // eax
  s_vertexinfo_t *v13; // eax
  VertexInfo_t *v14; // ecx
  int v15; // [esp+0h] [ebp-8h]
  int srcVertID; // [esp+4h] [ebp-4h]

  v6 = pSrcMesh;
  srcVertID = 0;
  if ( pSrcMesh->numvertices <= 0 )
  {
    pDstMesh->numvertices = pSrcMesh->numvertices;
  }
  else
  {
    v15 = 1 << nLodID;
    while ( 1 )
    {
      vertexoffset = v6->vertexoffset;
      m_Size = vertexDict->m_Verts.m_Size;
      m_nAllocationCount = vertexDict->m_Verts.m_Memory.m_nAllocationCount;
      v10 = srcVertID + vertexoffset;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<VertexInfo_t,int>::Grow(this: &vertexDict->m_Verts.m_Memory, num: m_Size - m_nAllocationCount + 1);
      ++vertexDict->m_Verts.m_Size;
      m_pMemory = vertexDict->m_Verts.m_Memory.m_pMemory;
      v12 = vertexDict->m_Verts.m_Size - m_Size - 1;
      vertexDict->m_Verts.m_pElements = vertexDict->m_Verts.m_Memory.m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 80 * v12);
      v13 = &pSrc->m_GlobalVertices.m_Memory.m_pMemory[v10];
      v14 = &vertexDict->m_Verts.m_Memory.m_pMemory[m_Size];
      v14->m_Position.x = v13->position.x;
      v14->m_Position.y = v13->position.y;
      v14->m_Position.z = v13->position.z;
      v14->m_Normal.x = v13->normal.x;
      v14->m_Normal.y = v13->normal.y;
      v14->m_Normal.z = v13->normal.z;
      v14->m_TexCoord.x = v13->texcoord.x;
      v14->m_TexCoord.y = v13->texcoord.y;
      v14->m_TangentS.x = v13->tangentS.x;
      v14->m_TangentS.y = v13->tangentS.y;
      v14->m_TangentS.z = v13->tangentS.z;
      v14->m_TangentS.w = v13->tangentS.w;
      *(_QWORD *)&v14->m_BoneWeight.numbones = *(_QWORD *)&v13->boneweight.numbones;
      *(_QWORD *)&v14->m_BoneWeight.bone[1] = *(_QWORD *)&v13->boneweight.bone[1];
      *(_QWORD *)v14->m_BoneWeight.weight = *(_QWORD *)v13->boneweight.weight;
      v14->m_BoneWeight.weight[2] = v13->boneweight.weight[2];
      v14->m_nLodFlag = v15;
      SortBoneWeightByIndex(boneWeight: &v14->m_BoneWeight);
      pMeshVertIndexMap[v10] = m_Size - pDstMesh->vertexoffset;
      if ( ++srcVertID >= pSrcMesh->numvertices )
        break;
      v6 = pSrcMesh;
    }
    pDstMesh->numvertices = pSrcMesh->numvertices;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045FD60
// Name: CopyFaces
// Source: json
//------------------------------------------------------------------------------
void __usercall CopyFaces(
        CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *faces@<esi>,
        const s_source_t *pSrc,
        const s_mesh_t *pSrcMesh,
        s_mesh_t *pDstMesh)
{
  const s_mesh_t *v4; // ecx
  int v5; // eax
  int m_pMemory; // ebx
  s_face_t *v7; // edi
  int m_nAllocationCount; // eax
  s_face_t *v9; // ecx
  int v10; // eax
  int v11; // ebx
  s_face_t *v12; // eax
  s_face_t *v13; // eax
  int srcFaceID; // [esp+0h] [ebp-4h]

  v4 = pSrcMesh;
  v5 = 0;
  for ( srcFaceID = 0; v5 < pSrcMesh->numfaces; srcFaceID = v5 )
  {
    m_pMemory = (int)faces[1].m_pMemory;
    v7 = &pSrc->face[v5 + v4->faceoffset];
    m_nAllocationCount = faces->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(this: faces, num: m_pMemory - m_nAllocationCount + 1);
    ++faces[1].m_pMemory;
    v9 = (s_face_t *)faces->m_pMemory;
    v10 = (int)faces[1].m_pMemory - m_pMemory - 1;
    faces[1].m_nAllocationCount = (int)faces->m_pMemory;
    if ( v10 > 0 )
      _V_memmove(dest: &v9[m_pMemory + 1], src: &v9[m_pMemory], count: 16 * v10);
    v11 = m_pMemory;
    v12 = (s_face_t *)&faces->m_pMemory[v11];
    if ( v12 != nullptr )
    {
      v12->d = -1;
      v12->c = -1;
      v12->b = -1;
      v12->a = -1;
    }
    v13 = (s_face_t *)&faces->m_pMemory[v11];
    v13->a = v7->a;
    v13->b = v7->b;
    v13->c = v7->c;
    v4 = pSrcMesh;
    v13->d = v7->d;
    ++pDstMesh->numfaces;
    v5 = srcFaceID + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045FE20
// Name: BuildBoneLODMapping
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildBoneLODMapping(int lodID@<eax>, CUtlVector<int,CUtlMemory<int,int> > *boneMap)
{
  LodScriptData_t *v3; // esi
  signed int v4; // eax
  CLodScriptReplacement_t *m_pMemory; // eax
  const char *m_pSrcName; // esi
  const char *m_pDstName; // edi
  int GlobalBone; // ebx
  int v9; // eax
  LodScriptData_t *scriptLOD; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]
  int v12; // [esp+10h] [ebp-4h]

  CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)boneMap,
    elem: boneMap->m_Size,
    num: g_numbones);
  v3 = &g_ScriptLODs.m_Memory.m_pMemory[lodID];
  v4 = 0;
  for ( scriptLOD = v3; v4 < (int)g_numbones; ++v4 )
    boneMap->m_Memory.m_pMemory[v4] = v4;
  i = 0;
  if ( v3->boneReplacements.m_Size > 0 )
  {
    v12 = 0;
    while ( 1 )
    {
      m_pMemory = v3->boneReplacements.m_Memory.m_pMemory;
      m_pSrcName = m_pMemory[v12].m_pSrcName;
      m_pDstName = m_pMemory[v12].m_pDstName;
      GlobalBone = findGlobalBone(name: m_pSrcName);
      v9 = findGlobalBone(name: m_pDstName);
      if ( GlobalBone == -1 )
      {
        if ( g_verbose )
          MdlWarning(fmt: "Couldn't replace unknown bone \"%s\" with \"%s\"\n", m_pSrcName, m_pDstName);
      }
      else if ( v9 == -1 )
      {
        if ( g_verbose )
          MdlWarning(fmt: "Couldn't replace bone \"%s\" with unknown \"%s\"\n", m_pSrcName, m_pDstName);
      }
      else
      {
        boneMap->m_Memory.m_pMemory[GlobalBone] = v9;
      }
      ++v12;
      if ( ++i >= scriptLOD->boneReplacements.m_Size )
        break;
      v3 = scriptLOD;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045FEF0
// Name: MarkRootLODBones
// Source: json
//------------------------------------------------------------------------------
void __cdecl MarkRootLODBones(CVertexDictionary *vertexDictionary)
{
  CVertexDictionary *v1; // eax
  int m_nRootLODStart; // ebx
  int *m_pMemory; // edi
  int v4; // esi
  s_boneweight_t *v5; // esi
  int v6; // ecx
  int *bone; // eax
  int v8; // ecx
  int *v9; // edx
  CUtlVector<int,CUtlMemory<int,int> > boneMap; // [esp+Ch] [ebp-18h] BYREF
  int i; // [esp+20h] [ebp-4h]

  memset(&boneMap, 0, sizeof(boneMap));
  BuildBoneLODMapping(lodID: 0, &boneMap);
  v1 = vertexDictionary;
  m_nRootLODStart = vertexDictionary->m_nRootLODStart;
  m_pMemory = boneMap.m_Memory.m_pMemory;
  if ( m_nRootLODStart < vertexDictionary->m_nRootLODEnd )
  {
    v4 = 80 * m_nRootLODStart;
    for ( i = 80 * m_nRootLODStart; ; v4 = i )
    {
      v5 = (s_boneweight_t *)((char *)&v1->m_Verts.m_Memory.m_pMemory->m_BoneWeight + v4);
      v6 = 0;
      if ( v5->numbones > 0 )
      {
        bone = v5->bone;
        do
        {
          *bone = m_pMemory[*bone];
          ++v6;
          ++bone;
        }
        while ( v6 < v5->numbones );
      }
      CollapseBoneWeights(boneWeight: v5);
      SortBoneWeightByWeight(boneWeight: v5);
      v8 = 0;
      if ( v5->numbones > 0 )
      {
        v9 = v5->bone;
        do
        {
          g_bonetable[*v9].flags |= 0x400u;
          ++v8;
          ++v9;
        }
        while ( v8 < v5->numbones );
      }
      v1 = vertexDictionary;
      i += 80;
      if ( ++m_nRootLODStart >= vertexDictionary->m_nRootLODEnd )
        break;
    }
  }
  if ( boneMap.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0045FFC0
// Name: ReplaceBonesRecursive
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReplaceBonesRecursive(
        int globalBoneID,
        bool replaceThis,
        CUtlVector<CLodScriptReplacement_t,CUtlMemory<CLodScriptReplacement_t,int> > *boneReplacements,
        const char *replacementName)
{
  CLodScriptReplacement_t *v4; // esi
  int v5; // esi
  int *p_parent; // ebx

  if ( replaceThis )
  {
    v4 = &boneReplacements->m_Memory.m_pMemory[CUtlVector<CLodScriptReplacement_t,CUtlMemory<CLodScriptReplacement_t,int>>::InsertBefore(
                                                 this: boneReplacements,
                                                 elem: boneReplacements->m_Size)];
    CLodScriptReplacement_t::SetSrcName(this: v4, pSrcName: g_bonetable[globalBoneID].name);
    CLodScriptReplacement_t::SetDstName(this: v4, pDstName: replacementName);
  }
  v5 = 0;
  if ( (int)g_numbones > 0 )
  {
    p_parent = &g_bonetable[0].parent;
    do
    {
      if ( *p_parent == globalBoneID )
        ReplaceBonesRecursive(globalBoneID: v5, replaceThis: true, boneReplacements, replacementName);
      ++v5;
      p_parent += 116;
    }
    while ( v5 < (int)g_numbones );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00460040
// Name: ConvertSingleBoneTreeCollapseToReplaceBones
// Source: json
//------------------------------------------------------------------------------
void __usercall ConvertSingleBoneTreeCollapseToReplaceBones(
        CLodScriptReplacement_t *boneTreeCollapse@<eax>,
        CUtlVector<CLodScriptReplacement_t,CUtlMemory<CLodScriptReplacement_t,int> > *boneReplacements)
{
  int GlobalBone; // eax
  int v4; // esi
  s_bonetable_t *v5; // ebx
  int *p_parent; // edi
  int i; // [esp+4h] [ebp-4h]

  GlobalBone = findGlobalBone(name: boneTreeCollapse->m_pSrcName);
  i = GlobalBone;
  if ( GlobalBone == -1 )
  {
    MdlWarning(fmt: "Couldn't find bone %s for bonetreecollapse, skipping\n", boneTreeCollapse->m_pSrcName);
  }
  else
  {
    v4 = 0;
    v5 = &g_bonetable[GlobalBone];
    if ( (int)g_numbones > 0 )
    {
      p_parent = &g_bonetable[0].parent;
      do
      {
        if ( *p_parent == GlobalBone )
        {
          ReplaceBonesRecursive(globalBoneID: v4, replaceThis: true, boneReplacements, replacementName: v5->name);
          GlobalBone = i;
        }
        ++v4;
        p_parent += 116;
      }
      while ( v4 < (int)g_numbones );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004600D0
// Name: void ConvertBoneTreeCollapsesToReplaceBones(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConvertBoneTreeCollapsesToReplaceBones()
{
  int v0; // eax
  LodScriptData_t *m_pMemory; // ecx
  int v2; // edi
  int *v3; // ebx
  int v4; // esi
  _DWORD *v5; // [esp+0h] [ebp-10h]
  CUtlVector<CLodScriptReplacement_t,CUtlMemory<CLodScriptReplacement_t,int> > *boneReplacements; // [esp+4h] [ebp-Ch]
  int v7; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v0 = 0;
  i = 0;
  if ( g_ScriptLODs.m_Size > 0 )
  {
    m_pMemory = g_ScriptLODs.m_Memory.m_pMemory;
    v7 = 0;
    do
    {
      v2 = 0;
      v3 = (int *)((char *)&m_pMemory->boneTreeCollapses.m_Size + v0);
      if ( *v3 > 0 )
      {
        boneReplacements = (CUtlVector<CLodScriptReplacement_t,CUtlMemory<CLodScriptReplacement_t,int> > *)((char *)&m_pMemory->boneReplacements + v0);
        v5 = (CLodScriptReplacement_t **)((char *)&m_pMemory->boneTreeCollapses.m_Memory.m_pMemory + v0);
        v4 = 0;
        do
        {
          ConvertSingleBoneTreeCollapseToReplaceBones(
            boneTreeCollapse: (CLodScriptReplacement_t *)(v4 + *v5),
            boneReplacements);
          ++v2;
          v4 += 12;
        }
        while ( v2 < *v3 );
        m_pMemory = g_ScriptLODs.m_Memory.m_pMemory;
        v0 = v7;
      }
      v0 += 108;
      ++i;
      v7 = v0;
    }
    while ( i < g_ScriptLODs.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00460150
// Name: CreateLODVertsInDictionary
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateLODVertsInDictionary(
        int nLodID,
        const s_source_t *pRootLODSrc,
        s_source_t *pCurrentLODSrc,
        const s_mesh_t *pCurrLODMesh,
        s_mesh_t *pVertexDictMesh,
        CVertexDictionary *vertexDict,
        int *pMeshVertIndexMap)
{
  int v8; // edi
  s_vertexinfo_t *v9; // eax
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v16; // xmm6_4
  float w; // xmm7_4
  float v18; // edx
  int m_nRootLODEnd; // edx
  int m_nLodFlag; // esi
  int m_nRootLODStart; // ecx
  int VertexWithinVertexDictionary; // eax
  VertexInfo_t *v23; // eax
  float v24; // ecx
  int m_nPrevLODCount; // eax
  int vertexoffset; // ecx
  int v27; // eax
  VertexInfo_t *v28; // eax
  float v29; // ecx
  int v30; // edx
  __int64 v31; // xmm0_8
  int v32; // eax
  int numbones; // edi
  int i; // edx
  s_bonetable_t *v35; // eax
  int v36; // eax
  int v37; // edx
  int VertexInDictionaryExact; // eax
  int v39; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  VertexInfo_t *m_pMemory; // ecx
  int v43; // eax
  int v44; // eax
  bool v45; // zf
  VertexInfo_t *v46; // ecx
  int v47; // ebx
  CUtlVector<int,CUtlMemory<int,int> > boneMap; // [esp+Ch] [ebp-C4h] BYREF
  int v49; // [esp+20h] [ebp-B0h]
  int nSrcID; // [esp+24h] [ebp-ACh]
  int v51; // [esp+28h] [ebp-A8h]
  int nNumCurrentVerts; // [esp+2Ch] [ebp-A4h]
  VertexInfo_t vertex; // [esp+30h] [ebp-A0h] BYREF
  VertexInfo_t idealVertex; // [esp+80h] [ebp-50h] BYREF
  int nSrcVertID; // [esp+ECh] [ebp+1Ch]

  nNumCurrentVerts = vertexDict->m_Verts.m_Size;
  vertexDict->m_nPrevLODCount = nNumCurrentVerts;
  v8 = nLodID;
  memset(&boneMap, 0, sizeof(boneMap));
  BuildBoneLODMapping(lodID: nLodID, &boneMap);
  nSrcVertID = 0;
  if ( pCurrLODMesh->numvertices > 0 )
  {
    v51 = 1 << nLodID;
    do
    {
      nSrcID = nSrcVertID + pCurrLODMesh->vertexoffset;
      v9 = &pCurrentLODSrc->m_GlobalVertices.m_Memory.m_pMemory[nSrcID];
      x = v9->position.x;
      y = v9->position.y;
      z = v9->position.z;
      v13 = v9->normal.x;
      v14 = v9->normal.y;
      v15 = v9->normal.z;
      v16 = v9->texcoord.x;
      vertex.m_TexCoord.y = v9->texcoord.y;
      vertex.m_TangentS.x = v9->tangentS.x;
      vertex.m_TangentS.y = v9->tangentS.y;
      vertex.m_TangentS.z = v9->tangentS.z;
      w = v9->tangentS.w;
      vertex.m_Position.x = x;
      vertex.m_Position.y = y;
      vertex.m_Position.z = z;
      vertex.m_Normal.x = v13;
      vertex.m_Normal.y = v14;
      vertex.m_Normal.z = v15;
      vertex.m_TexCoord.x = v16;
      vertex.m_TangentS.w = w;
      if ( g_bSkinnedLODs )
      {
        v18 = v9->boneweight.weight[2];
        *(_QWORD *)&vertex.m_BoneWeight.numbones = *(_QWORD *)&v9->boneweight.numbones;
        *(_QWORD *)&vertex.m_BoneWeight.bone[1] = *(_QWORD *)&v9->boneweight.bone[1];
        *(_QWORD *)vertex.m_BoneWeight.weight = *(_QWORD *)v9->boneweight.weight;
        vertex.m_BoneWeight.weight[2] = v18;
      }
      m_nRootLODEnd = vertexDict->m_nRootLODEnd;
      m_nLodFlag = vertex.m_nLodFlag;
      idealVertex.m_Position.x = x;
      idealVertex.m_TexCoord.y = vertex.m_TexCoord.y;
      idealVertex.m_TangentS.x = vertex.m_TangentS.x;
      idealVertex.m_BoneWeight.weight[2] = vertex.m_BoneWeight.weight[2];
      idealVertex.m_TangentS.y = vertex.m_TangentS.y;
      m_nRootLODStart = vertexDict->m_nRootLODStart;
      idealVertex.m_TangentS.z = vertex.m_TangentS.z;
      idealVertex.m_TangentS.w = vertex.m_TangentS.w;
      *(_QWORD *)&idealVertex.m_BoneWeight.numbones = *(_QWORD *)&vertex.m_BoneWeight.numbones;
      *(_QWORD *)&idealVertex.m_BoneWeight.bone[1] = *(_QWORD *)&vertex.m_BoneWeight.bone[1];
      idealVertex.m_Position.y = y;
      idealVertex.m_Position.z = z;
      idealVertex.m_Normal.x = v13;
      idealVertex.m_Normal.y = v14;
      idealVertex.m_Normal.z = v15;
      idealVertex.m_TexCoord.x = v16;
      *(_QWORD *)idealVertex.m_BoneWeight.weight = *(_QWORD *)vertex.m_BoneWeight.weight;
      idealVertex.m_nLodFlag = vertex.m_nLodFlag;
      VertexWithinVertexDictionary = FindVertexWithinVertexDictionary(
                                       find: &vertex,
                                       nStartVert: m_nRootLODStart,
                                       fIgnore: 4 * !g_bSkinnedLODs + 16,
                                       vertexDict,
                                       nEndVert: m_nRootLODEnd);
      if ( VertexWithinVertexDictionary == -1 )
      {
        if ( !g_bSkinnedLODs )
        {
          FindBoneWeightWithinModel(
            searchVertex: &vertex,
            fIgnore: 20,
            a3: m_nLodFlag,
            pSrc: pRootLODSrc,
            boneWeight: &idealVertex.m_BoneWeight);
          m_nLodFlag = idealVertex.m_nLodFlag;
        }
      }
      else
      {
        v23 = &vertexDict->m_Verts.m_Memory.m_pMemory[VertexWithinVertexDictionary];
        idealVertex.m_Position = v23->m_Position;
        v24 = v23->m_BoneWeight.weight[2];
        idealVertex.m_Normal.x = v23->m_Normal.x;
        m_nLodFlag = v23->m_nLodFlag;
        idealVertex.m_Normal.y = v23->m_Normal.y;
        idealVertex.m_Normal.z = v23->m_Normal.z;
        idealVertex.m_TexCoord = v23->m_TexCoord;
        idealVertex.m_TangentS = v23->m_TangentS;
        *(_QWORD *)&idealVertex.m_BoneWeight.numbones = *(_QWORD *)&v23->m_BoneWeight.numbones;
        *(_QWORD *)&idealVertex.m_BoneWeight.bone[1] = *(_QWORD *)&v23->m_BoneWeight.bone[1];
        *(_QWORD *)idealVertex.m_BoneWeight.weight = *(_QWORD *)v23->m_BoneWeight.weight;
        idealVertex.m_BoneWeight.weight[2] = v24;
      }
      vertex.m_Position.x = idealVertex.m_Position.x;
      vertex.m_Position.y = idealVertex.m_Position.y;
      m_nPrevLODCount = vertexDict->m_nPrevLODCount;
      vertex.m_Position.z = idealVertex.m_Position.z;
      vertex.m_Normal = idealVertex.m_Normal;
      vertex.m_TexCoord = idealVertex.m_TexCoord;
      vertex.m_TangentS = idealVertex.m_TangentS;
      *(_QWORD *)&vertex.m_BoneWeight.numbones = *(_QWORD *)&idealVertex.m_BoneWeight.numbones;
      *(_QWORD *)&vertex.m_BoneWeight.bone[1] = *(_QWORD *)&idealVertex.m_BoneWeight.bone[1];
      vertex.m_BoneWeight.weight[2] = idealVertex.m_BoneWeight.weight[2];
      vertexoffset = pVertexDictMesh->vertexoffset;
      *(_QWORD *)vertex.m_BoneWeight.weight = *(_QWORD *)idealVertex.m_BoneWeight.weight;
      vertex.m_nLodFlag = m_nLodFlag;
      v27 = FindVertexWithinVertexDictionary(
              find: &vertex,
              nStartVert: vertexoffset,
              fIgnore: 0,
              vertexDict,
              nEndVert: m_nPrevLODCount);
      if ( v27 == -1 )
      {
        idealVertex.m_Position = vertex.m_Position;
        idealVertex.m_Normal = vertex.m_Normal;
        idealVertex.m_TexCoord = vertex.m_TexCoord;
        idealVertex.m_TangentS = vertex.m_TangentS;
        *(_QWORD *)&idealVertex.m_BoneWeight.numbones = *(_QWORD *)&vertex.m_BoneWeight.numbones;
        *(_QWORD *)&idealVertex.m_BoneWeight.bone[1] = *(_QWORD *)&vertex.m_BoneWeight.bone[1];
        v31 = *(_QWORD *)vertex.m_BoneWeight.weight;
        idealVertex.m_BoneWeight.weight[2] = vertex.m_BoneWeight.weight[2];
        idealVertex.m_nLodFlag = vertex.m_nLodFlag;
      }
      else
      {
        v28 = &vertexDict->m_Verts.m_Memory.m_pMemory[v27];
        idealVertex.m_Position = v28->m_Position;
        v29 = v28->m_BoneWeight.weight[2];
        v30 = v28->m_nLodFlag;
        idealVertex.m_Normal = v28->m_Normal;
        idealVertex.m_TexCoord = v28->m_TexCoord;
        idealVertex.m_TangentS = v28->m_TangentS;
        *(_QWORD *)&idealVertex.m_BoneWeight.numbones = *(_QWORD *)&v28->m_BoneWeight.numbones;
        *(_QWORD *)&idealVertex.m_BoneWeight.bone[1] = *(_QWORD *)&v28->m_BoneWeight.bone[1];
        v31 = *(_QWORD *)v28->m_BoneWeight.weight;
        idealVertex.m_BoneWeight.weight[2] = v29;
        idealVertex.m_nLodFlag = v30;
      }
      v32 = 0;
      for ( *(_QWORD *)idealVertex.m_BoneWeight.weight = v31; v32 < idealVertex.m_BoneWeight.numbones; ++v32 )
        idealVertex.m_BoneWeight.bone[v32] = boneMap.m_Memory.m_pMemory[idealVertex.m_BoneWeight.bone[v32]];
      CollapseBoneWeights(boneWeight: &idealVertex.m_BoneWeight);
      SortBoneWeightByWeight(boneWeight: &idealVertex.m_BoneWeight);
      numbones = idealVertex.m_BoneWeight.numbones;
      for ( i = 0; i < numbones; ++i )
      {
        v35 = &g_bonetable[idealVertex.m_BoneWeight.bone[i]];
        v35->flags |= 1024 << nLodID;
      }
      v36 = pVertexDictMesh->vertexoffset;
      v37 = v36 + pVertexDictMesh->numvertices;
      idealVertex.m_nLodFlag = v51;
      VertexInDictionaryExact = FindVertexInDictionaryExact(
                                  vertexDict,
                                  nStartVert: v36,
                                  vertex: &idealVertex,
                                  nEndVert: v37);
      if ( VertexInDictionaryExact == -1 )
      {
        m_Size = vertexDict->m_Verts.m_Size;
        m_nAllocationCount = vertexDict->m_Verts.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<VertexInfo_t,int>::Grow(this: &vertexDict->m_Verts.m_Memory, num: m_Size - m_nAllocationCount + 1);
        ++vertexDict->m_Verts.m_Size;
        m_pMemory = vertexDict->m_Verts.m_Memory.m_pMemory;
        v43 = vertexDict->m_Verts.m_Size - m_Size - 1;
        vertexDict->m_Verts.m_pElements = vertexDict->m_Verts.m_Memory.m_pMemory;
        if ( v43 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 80 * v43);
        v44 = 80 * m_Size;
        v45 = &vertexDict->m_Verts.m_Memory.m_pMemory[m_Size] == nullptr;
        v46 = &vertexDict->m_Verts.m_Memory.m_pMemory[m_Size];
        v49 = 80 * m_Size;
        if ( !v45 )
        {
          VertexInfo_t::VertexInfo_t(this: v46, __that: &idealVertex);
          v44 = v49;
        }
        SortBoneWeightByIndex(boneWeight: (s_boneweight_t *)((char *)&vertexDict->m_Verts.m_Memory.m_pMemory->m_BoneWeight
                                                           + v44));
        ++pVertexDictMesh->numvertices;
        v39 = m_Size - pVertexDictMesh->vertexoffset;
      }
      else
      {
        vertexDict->m_Verts.m_Memory.m_pMemory[VertexInDictionaryExact].m_nLodFlag |= idealVertex.m_nLodFlag;
        v39 = VertexInDictionaryExact - pVertexDictMesh->vertexoffset;
      }
      pMeshVertIndexMap[nSrcID] = v39;
      ++nSrcVertID;
    }
    while ( nSrcVertID < pCurrLODMesh->numvertices );
    v8 = nLodID;
  }
  v47 = vertexDict->m_Verts.m_Size;
  if ( !g_quiet && v47 != nNumCurrentVerts )
    printf(format: "Lod %d: vertexes: %d (%d new)\n", v8, v47, v47 - nNumCurrentVerts);
  if ( boneMap.m_Memory.m_nGrowSize >= 0 && boneMap.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: boneMap.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004607F0
// Name: UnifyModelLODs
// Source: json
//------------------------------------------------------------------------------
void __cdecl UnifyModelLODs(s_model_t *pSrcModel)
{
  int i; // edi
  s_source_t **v2; // eax
  __int64 v3; // rax
  unsigned __int8 *m_pMemory; // ebx
  int v5; // edi
  int m_Size; // eax
  s_source_t *source; // eax
  int v8; // ecx
  int v9; // ebx
  int v10; // eax
  s_mesh_t *v11; // ebx
  s_source_t **v12; // eax
  s_source_t *v13; // edi
  int v14; // edx
  int v15; // eax
  int *meshindex; // ecx
  const s_mesh_t *v17; // esi
  int j; // esi
  s_source_t *v19; // edi
  const s_mesh_t *v20; // eax
  int *pMeshVertIndexMaps[8]; // [esp+4h] [ebp-80h] BYREF
  CVertexDictionary vertexDictionary; // [esp+24h] [ebp-60h] BYREF
  CUtlVector<s_face_t,CUtlMemory<s_face_t,int> > faces; // [esp+44h] [ebp-40h] BYREF
  CUtlVector<s_mesh_t,CUtlMemory<s_mesh_t,int> > meshes; // [esp+58h] [ebp-2Ch] BYREF
  int nStart; // [esp+6Ch] [ebp-18h]
  int v26; // [esp+70h] [ebp-14h]
  int nMeshID; // [esp+74h] [ebp-10h]
  s_source_t *pLOD0Source; // [esp+78h] [ebp-Ch]
  int nNumLODs; // [esp+7Ch] [ebp-8h]
  int nMaterialID; // [esp+80h] [ebp-4h]

  if ( _V_stricmp(s1: pSrcModel->name, s2: "blank") != 0 )
  {
    nNumLODs = pSrcModel->m_LodSources.m_Size;
    for ( i = 0; i < 8; ++i )
    {
      if ( i < nNumLODs && *(v2 = &pSrcModel->m_LodSources.m_Memory.m_pMemory[i]) != nullptr )
      {
        v3 = 4LL * (unsigned int)(*v2)->m_GlobalVertices.m_Size;
        pMeshVertIndexMaps[i] = (int *)MemAlloc_Alloc(nSize: HIDWORD(v3) != 0 ? -1 : v3);
      }
      else
      {
        pMeshVertIndexMaps[i] = nullptr;
      }
    }
    memset(&vertexDictionary, 0, 24);
    memset(&faces, 0, sizeof(faces));
    memset(&meshes, 0, sizeof(meshes));
    CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
      this: (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)&meshes,
      num: 32);
    m_pMemory = (unsigned __int8 *)meshes.m_Memory.m_pMemory;
    v5 = meshes.m_Size + 32;
    m_Size = meshes.m_Size;
    meshes.m_Size += 32;
    meshes.m_pElements = meshes.m_Memory.m_pMemory;
    if ( m_Size > 0 )
      _V_memmove(dest: &meshes.m_Memory.m_pMemory[32], src: meshes.m_Memory.m_pMemory, count: 16 * m_Size);
    memset(dst: m_pMemory, value: 0, count: 16 * v5);
    source = pSrcModel->source;
    nMeshID = 0;
    if ( source->nummeshes > 0 )
    {
      v8 = 201488;
      v26 = 201488;
      do
      {
        v9 = *(_DWORD *)&source->filename[v8];
        v10 = faces.m_Size;
        v11 = &meshes.m_Memory.m_pMemory[v9];
        v11->vertexoffset = vertexDictionary.m_Verts.m_Size;
        v11->numvertices = 0;
        v11->numfaces = 0;
        v11->faceoffset = v10;
        v12 = pSrcModel->m_LodSources.m_Memory.m_pMemory;
        if ( *v12 != nullptr )
        {
          v13 = *v12;
          v14 = *(_DWORD *)&(*v12)->filename[v8];
          pLOD0Source = *v12;
          nMaterialID = v14;
          if ( !g_quiet )
          {
            printf(format: "Processing LOD for material: %s\n", g_texture[v14].name);
            v14 = nMaterialID;
          }
          v15 = 0;
          if ( v13->nummeshes > 0 )
          {
            meshindex = v13->meshindex;
            while ( *meshindex != v14 )
            {
              ++v15;
              ++meshindex;
              if ( v15 >= v13->nummeshes )
                goto LABEL_27;
              v14 = nMaterialID;
            }
            v17 = &v13->mesh[v13->meshindex[v15]];
            if ( v17 != nullptr )
            {
              nStart = vertexDictionary.m_Verts.m_Size;
              CopyVerts(
                nLodID: 0,
                vertexDict: &vertexDictionary,
                pSrc: v13,
                pSrcMesh: v17,
                pDstMesh: v11,
                pMeshVertIndexMap: pMeshVertIndexMaps[0]);
              vertexDictionary.m_nRootLODStart = nStart;
              vertexDictionary.m_nRootLODEnd = vertexDictionary.m_Verts.m_Size;
              MarkRootLODBones(&vertexDictionary);
              CopyFaces(
                (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)&faces,
                pSrc: pLOD0Source,
                pSrcMesh: v17,
                pDstMesh: v11);
              for ( j = 1; j < nNumLODs; ++j )
              {
                v19 = pSrcModel->m_LodSources.m_Memory.m_pMemory[j];
                if ( v19 != nullptr )
                {
                  v20 = FindOrCullMesh(nLodID: j, pSrc: v19, nMaterialID);
                  if ( v20 != nullptr )
                    CreateLODVertsInDictionary(
                      nLodID: j,
                      pRootLODSrc: pLOD0Source,
                      pCurrentLODSrc: v19,
                      pCurrLODMesh: v20,
                      pVertexDictMesh: v11,
                      vertexDict: &vertexDictionary,
                      pMeshVertIndexMap: pMeshVertIndexMaps[j]);
                }
              }
            }
          }
        }
LABEL_27:
        source = pSrcModel->source;
        v8 = v26 + 4;
        ++nMeshID;
        v26 += 4;
      }
      while ( nMeshID < source->nummeshes );
      m_pMemory = (unsigned __int8 *)meshes.m_Memory.m_pMemory;
    }
    SetProcessedWithDictionary(vertexDict: &vertexDictionary, pSrcModel, &faces, &meshes, pMeshVertIndexMaps);
    if ( meshes.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    if ( faces.m_Memory.m_nGrowSize >= 0 && faces.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: faces.m_Memory.m_pMemory);
    if ( vertexDictionary.m_Verts.m_Memory.m_nGrowSize >= 0 && vertexDictionary.m_Verts.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vertexDictionary.m_Verts.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00460AD0
// Name: void UnifyLODs(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UnifyLODs()
{
  int i; // ebx
  int m_Size; // eax
  int v2; // esi
  int v3; // edi
  int v4; // edx
  s_model_t **m_pMemory; // ecx
  int v6; // eax
  int v7; // [esp+4h] [ebp-4h]

  if ( g_nummodelsbeforeLOD > 0 )
  {
    v7 = 0;
    for ( i = 1; i - 1 < g_nummodelsbeforeLOD; ++i )
    {
      m_Size = g_model.m_Size;
      if ( g_model.m_Size < i )
      {
        v2 = i - g_model.m_Size;
        v3 = g_model.m_Size;
        if ( i != g_model.m_Size )
        {
          v4 = i;
          if ( i > g_model.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&g_model,
              num: v2 + g_model.m_Size - g_model.m_Memory.m_nAllocationCount);
            m_Size = g_model.m_Size;
            v4 = i;
          }
          m_pMemory = g_model.m_Memory.m_pMemory;
          g_model.m_Size = v2 + m_Size;
          v6 = m_Size - v3;
          g_model.m_pElements = g_model.m_Memory.m_pMemory;
          if ( v6 <= 0 || v2 <= 0 )
            goto LABEL_11;
          _V_memmove(dest: &g_model.m_Memory.m_pMemory[v4], src: &g_model.m_Memory.m_pMemory[v3], count: 4 * v6);
        }
      }
      m_pMemory = g_model.m_Memory.m_pMemory;
LABEL_11:
      UnifyModelLODs(pSrcModel: m_pMemory[v7++]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00460B90
// Name: GetLODSources
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetLODSources(CUtlVector<s_source_t *,CUtlMemory<s_source_t *,int> > *lods, const s_model_t *pSrcModel)
{
  int m_Size; // ebx
  int v3; // esi
  int v4; // edi
  s_source_t *ModelLODSource; // eax
  bool bFound; // [esp+Bh] [ebp-1h] BYREF

  m_Size = g_ScriptLODs.m_Size;
  if ( lods->m_Size < g_ScriptLODs.m_Size )
    CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
      this: (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)lods,
      elem: lods->m_Size,
      num: g_ScriptLODs.m_Size - lods->m_Size);
  v3 = 0;
  if ( m_Size > 0 )
  {
    v4 = 0;
    do
    {
      ModelLODSource = GetModelLODSource(
                         pModelName: pSrcModel->filename,
                         scriptLOD: &g_ScriptLODs.m_Memory.m_pMemory[v4],
                         pFound: &bFound);
      if ( ModelLODSource == nullptr && !bFound )
        ModelLODSource = pSrcModel->source;
      lods->m_Memory.m_pMemory[v3++] = ModelLODSource;
      ++v4;
    }
    while ( v3 < m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00460C10
// Name: void LoadLODSources(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadLODSources()
{
  int v0; // ebx
  int m_Size; // eax
  int v2; // esi
  int v3; // edi
  int v4; // edx
  s_model_t **m_pMemory; // ecx
  int v6; // eax
  bool v7; // zf
  int v8; // eax
  int v9; // edi
  int v10; // esi
  int v11; // ebx
  int v12; // edx
  s_model_t **v13; // ecx
  int v14; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v15; // esi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v17; // ecx
  int v18; // eax
  int i; // ebx
  int v20; // eax
  int v21; // esi
  int v22; // edi
  int v23; // edx
  s_model_t **v24; // ecx
  int v25; // eax
  int v26; // esi
  int v27; // edi
  s_model_t **v28; // ecx
  int v29; // esi
  int v30; // edi
  int v31; // edx
  int v32; // eax
  int v33; // [esp+0h] [ebp-10h]
  int nNumLODs; // [esp+4h] [ebp-Ch]
  const s_model_t **nNumLODsa; // [esp+4h] [ebp-Ch]
  int v36; // [esp+8h] [ebp-8h]
  int v37; // [esp+Ch] [ebp-4h]

  g_nummodelsbeforeLOD = g_nummodels;
  if ( g_nummodels > 0 )
  {
    v0 = 1;
    v37 = 0;
    v36 = 1;
    while ( 1 )
    {
      m_Size = g_model.m_Size;
      if ( g_model.m_Size >= v0 )
        goto LABEL_10;
      v2 = v0 - g_model.m_Size;
      v3 = g_model.m_Size;
      if ( v0 == g_model.m_Size )
        goto LABEL_10;
      v4 = v0;
      if ( v0 > g_model.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&g_model,
          num: v2 + g_model.m_Size - g_model.m_Memory.m_nAllocationCount);
        m_Size = g_model.m_Size;
        v4 = v0;
      }
      m_pMemory = g_model.m_Memory.m_pMemory;
      g_model.m_Size = v2 + m_Size;
      v6 = m_Size - v3;
      g_model.m_pElements = g_model.m_Memory.m_pMemory;
      if ( v6 > 0 && v2 > 0 )
        break;
LABEL_11:
      v7 = _V_stricmp(s1: m_pMemory[v37]->name, s2: "blank") == 0;
      v8 = g_model.m_Size;
      if ( !v7 )
      {
        if ( g_model.m_Size >= v0 || (v26 = v0 - g_model.m_Size, v27 = g_model.m_Size, v0 == g_model.m_Size) )
        {
          v28 = g_model.m_Memory.m_pMemory;
        }
        else
        {
          if ( v0 > g_model.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&g_model,
              num: g_model.m_Size + v26 - g_model.m_Memory.m_nAllocationCount);
            v8 = g_model.m_Size;
          }
          v28 = g_model.m_Memory.m_pMemory;
          v8 += v26;
          g_model.m_Size = v8;
          g_model.m_pElements = g_model.m_Memory.m_pMemory;
          if ( v8 - v27 - v26 > 0 && v26 > 0 )
          {
            _V_memmove(
              dest: &g_model.m_Memory.m_pMemory[v0],
              src: &g_model.m_Memory.m_pMemory[v27],
              count: 4 * (v8 - v27 - v26));
            v8 = g_model.m_Size;
            v28 = g_model.m_Memory.m_pMemory;
          }
          v0 = v36;
        }
        nNumLODsa = (const s_model_t **)&v28[v37];
        if ( v8 < v0 )
        {
          v29 = v0 - v8;
          v30 = v8;
          if ( v0 != v8 )
          {
            v31 = v0;
            if ( v0 > g_model.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&g_model,
                num: v0 - g_model.m_Memory.m_nAllocationCount);
              v8 = g_model.m_Size;
              v28 = g_model.m_Memory.m_pMemory;
              v31 = v0;
            }
            g_model.m_Size = v29 + v8;
            v32 = v8 - v30;
            g_model.m_pElements = v28;
            if ( v32 > 0 && v29 > 0 )
            {
              _V_memmove(dest: &v28[v31], src: &v28[v30], count: 4 * v32);
              v28 = g_model.m_Memory.m_pMemory;
            }
          }
        }
        GetLODSources(lods: &v28[v37]->m_LodSources, pSrcModel: *nNumLODsa);
        goto LABEL_37;
      }
      v9 = g_ScriptLODs.m_Size;
      nNumLODs = g_ScriptLODs.m_Size;
      if ( g_model.m_Size < v0 )
      {
        v10 = v0 - g_model.m_Size;
        v7 = v0 == g_model.m_Size;
        v11 = g_model.m_Size;
        if ( !v7 )
        {
          v12 = g_model.m_Size + v10;
          v33 = g_model.m_Size + v10;
          if ( g_model.m_Size + v10 > g_model.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&g_model,
              num: v10 + g_model.m_Size - g_model.m_Memory.m_nAllocationCount);
            v8 = g_model.m_Size;
            v12 = v33;
          }
          v13 = g_model.m_Memory.m_pMemory;
          g_model.m_Size = v10 + v8;
          v14 = v8 - v11;
          g_model.m_pElements = g_model.m_Memory.m_pMemory;
          if ( v14 <= 0 || v10 <= 0 )
            goto LABEL_20;
          _V_memmove(dest: &g_model.m_Memory.m_pMemory[v12], src: &g_model.m_Memory.m_pMemory[v11], count: 4 * v14);
        }
      }
      v13 = g_model.m_Memory.m_pMemory;
LABEL_20:
      v15 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)v13[v37];
      v15[3007].m_pMemory = nullptr;
      if ( v9 != 0 )
      {
        m_nAllocationCount = v15[3006].m_nAllocationCount;
        if ( v9 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v15 + 3006, num: v9 - m_nAllocationCount);
        v15[3007].m_pMemory = (CUtlSymbolTable::StringPool_t **)((char *)v15[3007].m_pMemory + v9);
        v17 = v15[3006].m_pMemory;
        v18 = (int)v15[3007].m_pMemory - v9;
        v15[3007].m_nAllocationCount = (int)v17;
        if ( v18 > 0 && v9 > 0 )
          _V_memmove(dest: &v17[v9], src: v17, count: 4 * v18);
      }
      for ( i = 0; i < v9; v24[v37]->m_LodSources.m_Memory.m_pMemory[i++] = nullptr )
      {
        v20 = g_model.m_Size;
        if ( g_model.m_Size < v36 )
        {
          v21 = v36 - g_model.m_Size;
          v22 = g_model.m_Size;
          if ( v36 != g_model.m_Size )
          {
            v23 = v36;
            if ( v36 > g_model.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&g_model,
                num: g_model.m_Size + v21 - g_model.m_Memory.m_nAllocationCount);
              v20 = g_model.m_Size;
              v23 = v36;
            }
            v24 = g_model.m_Memory.m_pMemory;
            g_model.m_Size = v21 + v20;
            v25 = v20 - v22;
            g_model.m_pElements = g_model.m_Memory.m_pMemory;
            if ( v25 > 0 && v21 > 0 )
            {
              _V_memmove(dest: &g_model.m_Memory.m_pMemory[v23], src: &g_model.m_Memory.m_pMemory[v22], count: 4 * v25);
              v24 = g_model.m_Memory.m_pMemory;
            }
            v9 = nNumLODs;
            continue;
          }
          v9 = nNumLODs;
        }
        v24 = g_model.m_Memory.m_pMemory;
      }
      v0 = v36;
LABEL_37:
      ++v37;
      v36 = ++v0;
      if ( v0 - 1 >= g_nummodelsbeforeLOD )
        return;
    }
    _V_memmove(dest: &g_model.m_Memory.m_pMemory[v4], src: &g_model.m_Memory.m_pMemory[v3], count: 4 * v6);
LABEL_10:
    m_pMemory = g_model.m_Memory.m_pMemory;
    goto LABEL_11;
  }
}

} // namespace studiomdl
