// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vrad/vradstaticprops.cpp
// Functions: 53
// ============================================================

#include "utils\vrad\vradstaticprops.h"

//------------------------------------------------------------------------------
// Address: 0x10007D80
// Name: public: void CUtlMemory<struct CVradStaticPropMgr::MeshData_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CVradStaticPropMgr::MeshData_t,int>::Grow(
        CUtlMemory<dleafambientlighting_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  dleafambientlighting_t *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (dleafambientlighting_t *)_g_pMemAlloc->Realloc_2(
                                                    this: _g_pMemAlloc,
                                                    a2: m_pMemory,
                                                    a3: 28 * m_nAllocationCount);
    else
      this->m_pMemory = (dleafambientlighting_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 28 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012110
// Name: public: void CUtlDict<class CMacroTextureData __near *,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CMacroTextureData *,int>::RemoveAll(CUtlDict<CMacroTextureData *,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CMacroTextureData *,int>::Node_t,int,CUtlMap<char const *,CMacroTextureData *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMacroTextureData *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CMacroTextureData *,int>::Node_t,int,CUtlMap<char const *,CMacroTextureData *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMacroTextureData *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CMacroTextureData *,int>::Node_t,int,CUtlMap<char const *,CMacroTextureData *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CMacroTextureData *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1002A3A0
// Name: void Vector2DAdd(class Vector2D const __near &,class Vector2D const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector2DAdd(const Vector2D *a, const Vector2D *b, Vector2D *c)
{
  c->x = a->x + b->x;
  c->y = a->y + b->y;
}

//------------------------------------------------------------------------------
// Address: 0x1002A3D0
// Name: void Vector2DMultiply(class Vector2D const __near &,float,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector2DMultiply(const Vector2D *a, float b, Vector2D *c)
{
  c->x = a->x * b;
  c->y = a->y * b;
}

//------------------------------------------------------------------------------
// Address: 0x1002A400
// Name: bool Studio_ConvertStudioHdrToNewVersion(struct studiohdr_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Studio_ConvertStudioHdrToNewVersion(studiohdr_t *pStudioHdr)
{
  int v2; // ebx
  int v4; // edx
  int v5; // ecx
  unsigned __int8 *v6; // edi
  int k; // edx
  int v8; // ecx
  char *v9; // ecx
  int m; // edi
  int v11; // ecx
  char *v12; // ecx
  int v13; // edx
  int j; // edx
  int v15; // ecx
  char *v16; // ecx
  int version; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]
  char bResult_3; // [esp+1Bh] [ebp+Bh]

  v2 = pStudioHdr->version;
  version = v2;
  if ( v2 == 49 )
    return 1;
  bResult_3 = 1;
  if ( v2 < 46 )
  {
    v4 = 0;
    for ( i = 0; v4 < pStudioHdr->numlocalanim; i = v4 )
    {
      v5 = v4;
      if ( v4 < 0 || v4 >= pStudioHdr->numlocalanim )
        v5 = 0;
      v6 = (unsigned __int8 *)pStudioHdr + 100 * v5 + pStudioHdr->localanimindex;
      if ( *((_DWORD *)v6 + 21) != 0 )
      {
        memset(dst: v6 + 16, value: 0, count: 0x54u);
        v4 = i;
        *((_DWORD *)v6 + 4) = 1;
        v2 = version;
        *((_DWORD *)v6 + 13) = -1;
        bResult_3 = 0;
      }
      ++v4;
    }
  }
  if ( v2 >= 47 )
  {
    if ( v2 == 47 )
    {
      for ( j = 0; j < pStudioHdr->numlocalanim; ++j )
      {
        v15 = j;
        if ( j < 0 || j >= pStudioHdr->numlocalanim )
          v15 = 0;
        v16 = (char *)pStudioHdr + 100 * v15 + pStudioHdr->localanimindex;
        if ( *((_DWORD *)v16 + 23) != 0 )
        {
          *((_DWORD *)v16 + 23) = 0;
          *((_WORD *)v16 + 44) = 0;
          bResult_3 = 0;
        }
      }
      goto LABEL_20;
    }
  }
  else
  {
    if ( pStudioHdr->unused4 != 0 )
    {
      pStudioHdr->unused4 = 0;
      bResult_3 = 0;
    }
    for ( k = 0; k < pStudioHdr->numlocalanim; *((_WORD *)v9 + 44) = 0 )
    {
      v8 = k;
      if ( k < 0 || k >= pStudioHdr->numlocalanim )
        v8 = 0;
      v9 = (char *)pStudioHdr + 100 * v8 + pStudioHdr->localanimindex;
      ++k;
      *((_DWORD *)v9 + 23) = 0;
    }
  }
  if ( v2 < 49 )
  {
LABEL_20:
    for ( m = 0; m < pStudioHdr->numlocalanim; ++m )
    {
      v11 = m;
      if ( m < 0 || m >= pStudioHdr->numlocalanim )
        v11 = 0;
      v12 = (char *)pStudioHdr + 100 * v11 + pStudioHdr->localanimindex;
      v13 = *((_DWORD *)v12 + 3);
      if ( (v13 & 0x40) != 0 )
      {
        *((_DWORD *)v12 + 3) = v13 & 0xFFFFFFBF;
        bResult_3 = 0;
      }
    }
  }
  pStudioHdr->version = 49;
  return bResult_3;
}

//------------------------------------------------------------------------------
// Address: 0x1002A580
// Name: int Studio_LoadVertexes(struct vertexFileHeader_t const __near *,struct vertexFileHeader_t __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Studio_LoadVertexes(
        vertexFileHeader_t *pTempVvdHdr,
        vertexFileHeader_t *pNewVvdHdr,
        int rootLOD,
        bool bNeedsTangentS)
{
  int j; // ecx
  int *numLODVertexes; // eax
  int result; // eax
  _DWORD *v9; // ebx
  unsigned int vertexDataStart; // [esp-4h] [ebp-10h]
  int numVertexes; // [esp+14h] [ebp+8h]
  int numVertexesa; // [esp+14h] [ebp+8h]
  int i; // [esp+18h] [ebp+Ch]

  vertexDataStart = pTempVvdHdr->vertexDataStart;
  numVertexes = pTempVvdHdr->numLODVertexes[rootLOD];
  memcpy(dst: (unsigned __int8 *)pNewVvdHdr, src: (unsigned __int8 *)pTempVvdHdr, count: vertexDataStart);
  j = 0;
  if ( rootLOD > 0 )
  {
    numLODVertexes = pNewVvdHdr->numLODVertexes;
    for ( j = rootLOD; j != 0; --j )
      *numLODVertexes++ = pNewVvdHdr->numLODVertexes[rootLOD];
  }
  if ( bNeedsTangentS )
    pNewVvdHdr->tangentDataStart = pNewVvdHdr->vertexDataStart + 48 * numVertexes;
  else
    pNewVvdHdr->tangentDataStart = j;
  if ( pNewVvdHdr->numFixups == j )
  {
    memcpy(
      dst: (unsigned __int8 *)pNewVvdHdr + pNewVvdHdr->vertexDataStart,
      src: (unsigned __int8 *)pTempVvdHdr + pTempVvdHdr->vertexDataStart,
      count: 48 * numVertexes);
    if ( bNeedsTangentS )
      memcpy(
        dst: (unsigned __int8 *)pNewVvdHdr + pNewVvdHdr->tangentDataStart,
        src: (unsigned __int8 *)pTempVvdHdr + pTempVvdHdr->tangentDataStart,
        count: 16 * numVertexes);
    return numVertexes;
  }
  else
  {
    result = 0;
    numVertexesa = 0;
    i = j;
    if ( pTempVvdHdr->numFixups > j )
    {
      v9 = (int *)((char *)&pTempVvdHdr->checksum + pTempVvdHdr->fixupTableStart);
      do
      {
        if ( *(v9 - 2) >= rootLOD )
        {
          memcpy(
            dst: (unsigned __int8 *)pNewVvdHdr + 48 * result + pNewVvdHdr->vertexDataStart,
            src: (unsigned __int8 *)pTempVvdHdr + 48 * *(v9 - 1) + pTempVvdHdr->vertexDataStart,
            count: 48 * *v9);
          if ( bNeedsTangentS )
            memcpy(
              dst: (unsigned __int8 *)pNewVvdHdr + 16 * numVertexesa + pNewVvdHdr->tangentDataStart,
              src: (unsigned __int8 *)pTempVvdHdr + 16 * *(v9 - 1) + pTempVvdHdr->tangentDataStart,
              count: 16 * *v9);
          numVertexesa += *v9;
          result = numVertexesa;
        }
        v9 += 3;
        ++i;
      }
      while ( i < pTempVvdHdr->numFixups );
      j = 0;
    }
    pNewVvdHdr->numFixups = j;
    pNewVvdHdr->fixupTableStart = j;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002A6C0
// Name: void GetStaticPropBumpNormals(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector __near * const)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetStaticPropBumpNormals(
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
  v6 = g_localUpBumpBasis;
  do
  {
    VectorIRotate(
      in1: &v6->x,
      in2: &smoothBasis,
      out: (float *)((char *)&v6->x + (char *)bumpNormals - (char *)g_localUpBumpBasis));
    ++v6;
  }
  while ( (int)v6 < (int)"models/" );
}

//------------------------------------------------------------------------------
// Address: 0x1002A800
// Name: void NormalizeVertexBumpedLighting(class Vector const __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NormalizeVertexBumpedLighting(const Vector *pColorNormal, Vector *pColorBumps)
{
  float v2; // xmm4_4
  float v3; // xmm5_4
  float v4; // xmm3_4
  float z; // xmm0_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  Vector linearBump1; // 0:^0.12
  Vector linearBump3; // 0:^C.12
  Vector linearBump2; // 0:^18.12

  linearBump1 = *pColorBumps;
  linearBump2 = pColorBumps[1];
  linearBump3 = pColorBumps[2];
  v2 = (float)(linearBump3.x + (float)(linearBump2.x + pColorBumps->x)) * 0.33333334;
  v3 = (float)(linearBump3.y + (float)(linearBump2.y + pColorBumps->y)) * 0.33333334;
  v4 = (float)(linearBump3.z + (float)(linearBump2.z + pColorBumps->z)) * 0.33333334;
  if ( v2 != 0.0
    && COERCE_INT((float)(linearBump3.y + (float)(linearBump2.y + pColorBumps->y)) * 0.33333334) != 0
    && COERCE_INT((float)(linearBump3.z + (float)(linearBump2.z + pColorBumps->z)) * 0.33333334) != 0 )
  {
    z = pColorNormal->z;
    v6 = pColorNormal->x / v2;
    v7 = pColorNormal->y / v3;
LABEL_11:
    v8 = z / v4;
    goto LABEL_12;
  }
  v8 = 0.0;
  v6 = 0.0;
  v7 = 0.0;
  if ( v2 != 0.0 )
    v6 = pColorNormal->x / v2;
  if ( v3 != 0.0 )
    v7 = pColorNormal->y / v3;
  if ( v4 != 0.0 )
  {
    z = pColorNormal->z;
    goto LABEL_11;
  }
LABEL_12:
  pColorBumps->x = linearBump1.x * v6;
  pColorBumps->y = linearBump1.y * v7;
  pColorBumps->z = linearBump1.z * v8;
  pColorBumps[1].x = v6 * linearBump2.x;
  pColorBumps[1].y = v7 * linearBump2.y;
  pColorBumps[1].z = v8 * linearBump2.z;
  pColorBumps[2].x = v6 * linearBump3.x;
  pColorBumps[2].y = v7 * linearBump3.y;
  pColorBumps[2].z = v8 * linearBump3.z;
}

//------------------------------------------------------------------------------
// Address: 0x1002A9B0
// Name: class IVradStaticPropMgr __near * StaticPropMgr(void)
// Source: json
//------------------------------------------------------------------------------
CVradStaticPropMgr *__cdecl StaticPropMgr()
{
  return &g_StaticPropMgr;
}

//------------------------------------------------------------------------------
// Address: 0x1002A9C0
// Name: public: void CShadowTextureList::alphatexture_t::InitFromRGB8888(int,int,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowTextureList::alphatexture_t::InitFromRGB8888(
        CShadowTextureList::alphatexture_t *this,
        int w,
        int h,
        unsigned __int8 *pTexels)
{
  CShadowTextureList::alphatexture_t *v6; // ebx
  unsigned __int8 *v7; // ecx
  int v8; // eax
  int i; // esi
  bool v10; // zf
  int wa; // [esp+18h] [ebp+8h]
  unsigned __int8 *ha; // [esp+1Ch] [ebp+Ch]
  unsigned __int8 *pTexelsa; // [esp+20h] [ebp+10h]

  v6 = this;
  this->width = w;
  this->height = h;
  this->pAlphaTexels = (unsigned __int8 *)MemAlloc_Alloc(nSize: h * w);
  if ( h > 0 )
  {
    v7 = pTexels + 3;
    wa = 0;
    ha = pTexels + 3;
    pTexelsa = (unsigned __int8 *)h;
    do
    {
      if ( w > 0 )
      {
        v8 = wa;
        for ( i = w; i != 0; --i )
        {
          v6->pAlphaTexels[v8] = *v7;
          v6 = this;
          ++v8;
          v7 += 4;
        }
      }
      wa += w;
      v7 = &ha[4 * w];
      v10 = pTexelsa-- == (unsigned __int8 *)1;
      ha = v7;
    }
    while ( !v10 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002AA50
// Name: void ForceTextureShadowsOnModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ForceTextureShadowsOnModel(const char *pModelName)
{
  const char *v1; // esi
  int v2; // edi
  _BYTE *v3; // eax
  char buf[1024]; // [esp+8h] [ebp-400h] BYREF

  v1 = pModelName;
  v2 = _V_strlen(str: "models/");
  if ( V_strnicmp(s1: v1, s2: "models/", n: v2) == 0 )
    v1 += v2;
  V_strncpy(pDest: buf, pSrc: v1, maxLen: 1024);
  strchr(string: (unsigned __int8 *)buf, chr: 0x2Eu);
  if ( v3 != nullptr )
    *v3 = 0;
  if ( CUtlSymbolTable::Find(this: &g_ForcedTextureShadowsModels, result: (CUtlSymbol *)&pModelName + 1, pString: buf)->m_Id == 0xFFFF )
    CUtlSymbolTable::AddString(this: &g_ForcedTextureShadowsModels, result: (CUtlSymbol *)&pModelName + 1, pString: buf);
}

//------------------------------------------------------------------------------
// Address: 0x1002AAF0
// Name: bool IsModelTextureShadowsForced(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsModelTextureShadowsForced(const char *pModelName)
{
  const char *v1; // esi
  int v2; // edi
  _BYTE *v3; // eax
  char buf[1024]; // [esp+8h] [ebp-400h] BYREF

  v1 = pModelName;
  v2 = _V_strlen(str: "models/");
  if ( V_strnicmp(s1: v1, s2: "models/", n: v2) == 0 )
    v1 += v2;
  V_strncpy(pDest: buf, pSrc: v1, maxLen: 1024);
  strchr(string: (unsigned __int8 *)buf, chr: 0x2Eu);
  if ( v3 != nullptr )
    *v3 = 0;
  return CUtlSymbolTable::Find(this: &g_ForcedTextureShadowsModels, result: (CUtlSymbol *)&pModelName + 1, pString: buf)->m_Id != 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1002AB80
// Name: void ComputeDirectLightingAtPoint(class Vector __near &,class Vector __near *,class Vector __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall ComputeDirectLightingAtPoint(
        float a1@<ebp>,
        Vector *position,
        Vector *normals,
        Vector *outColors,
        int numNormals,
        int iThread,
        int static_prop_id_to_skip,
        char nLFlags)
{
  int v8; // edi
  float *p_z; // eax
  int i; // ecx
  int v11; // eax
  directlight_t *v12; // esi
  unsigned __int8 *pvs; // edi
  bool v14; // zf
  __int64 v15; // xmm1_8
  emittype_t type; // eax
  float v17; // xmm3_4
  float v18; // xmm2_4
  int v19; // xmm1_4
  float v20; // xmm1_4
  int v21; // xmm2_4
  Vector *v22; // ecx
  float v23; // xmm4_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm2_4
  __m128 v27; // xmm3
  __m128 v28; // xmm0
  __m128 v29; // xmm0
  float z; // xmm1_4
  __m128 v31; // xmm0
  __m128 v32; // xmm3
  __m128 v33; // xmm4
  __m128 v34; // xmm0
  __m128 v35; // xmm1
  __m128 v36; // xmm3
  __m128 v37; // xmm2
  __m128 v38; // xmm0
  __m128 v39; // xmm1
  __m128 v40; // xmm4
  __m128 v41; // xmm0
  __m128 v42; // xmm1
  __m128 v43; // xmm4
  __m128 v44; // xmm3
  int v45; // ecx
  float *v46; // eax
  float v47; // xmm0_4
  float v48; // xmm0_4
  float v49; // xmm1_4
  float v50; // xmm0_4
  float v51; // xmm1_4
  float v52; // xmm0_4
  float *v53; // eax
  float v54; // xmm0_4
  _BYTE v55[57]; // [esp+14h] [ebp-ECh] OVERLAPPED BYREF
  _BYTE sampleOutput[144]; // [esp+50h] [ebp-B0h] OVERLAPPED BYREF
  int cluster; // [esp+E0h] [ebp-20h]
  Vector fudge; // [esp+E4h] [ebp-1Ch]
  Vector adjusted_pos; // [esp+F0h] [ebp-10h]
  float retaddr; // [esp+100h] [ebp+0h]

  adjusted_pos.y = a1;
  adjusted_pos.z = retaddr;
  v8 = numNormals;
  if ( numNormals > 0 )
  {
    p_z = &outColors->z;
    for ( i = numNormals; i != 0; --i )
    {
      *(p_z - 2) = 0.0;
      *(p_z - 1) = 0.0;
      *p_z = 0.0;
      p_z += 3;
    }
  }
  v11 = ClusterFromPoint(point: position);
  v12 = activelights;
  *(_DWORD *)&sampleOutput[132] = v11;
  if ( activelights != nullptr )
  {
    while ( 1 )
    {
      if ( v12->light.style != 0 )
        goto LABEL_28;
      if ( v11 >= 0 )
      {
        pvs = v12->pvs;
        HIBYTE(adjusted_pos.x) = 1 << (v11 & 7);
        v14 = (HIBYTE(adjusted_pos.x) & pvs[v11 >> 3]) == 0;
        v8 = numNormals;
        if ( v14 )
          goto LABEL_28;
      }
      v15 = *(_QWORD *)&position->x;
      fudge.z = position->z;
      type = v12->light.type;
      *(_QWORD *)&fudge.x = v15;
      if ( type == emit_skyambient )
      {
        v22 = normals;
        v24 = (float)(normals->y * 4.0) + fudge.y;
        v26 = (float)(normals->z * 4.0) + fudge.z;
        v25 = (float)(normals->x * 4.0) + fudge.x;
      }
      else
      {
        if ( type == emit_skylight )
        {
          v17 = -v12->light.normal.x;
          v18 = -v12->light.normal.y;
          *(float *)&v19 = -v12->light.normal.z;
        }
        else
        {
          v20 = v12->light.origin.y - position->y;
          *(float *)&v21 = v12->light.origin.z - position->z;
          *(float *)&sampleOutput[136] = v12->light.origin.x - position->x;
          *(float *)&sampleOutput[140] = v20;
          cluster = v21;
          VectorNormalize(vec: (Vector *)&sampleOutput[136]);
          v19 = cluster;
          v18 = *(float *)&sampleOutput[140];
          v17 = *(float *)&sampleOutput[136];
        }
        v22 = normals;
        v23 = *(float *)&v19 * 4.0;
        v24 = fudge.y + (float)(v18 * 4.0);
        v25 = fudge.x + (float)(v17 * 4.0);
        v26 = fudge.z + v23;
      }
      v27 = 0;
      v27.m128_f32[0] = v25;
      *(__m128 *)v55 = _mm_shuffle_ps(v27, v27, 0);
      v28 = 0;
      v28.m128_f32[0] = v24;
      *(__m128 *)&v55[16] = _mm_shuffle_ps(v28, v28, 0);
      v29 = 0;
      v29.m128_f32[0] = v26;
      *(__m128 *)&v55[32] = _mm_shuffle_ps(v29, v29, 0);
      if ( v8 == 3 )
        break;
      if ( v8 == 4 )
      {
        v32 = *(__m128 *)&v22[1].x;
        v33 = *(__m128 *)&v22[3].x;
        v34 = _mm_shuffle_ps(*(__m128 *)&v22->x, v32, 68);
        v35 = _mm_shuffle_ps(*(__m128 *)&v22->x, v32, 238);
        v36 = _mm_shuffle_ps(*(__m128 *)&v22[2].x, v33, 68);
        v37 = _mm_shuffle_ps(*(__m128 *)&v22[2].x, v33, 238);
        *(__m128 *)&sampleOutput[84] = _mm_shuffle_ps(v34, v36, 136);
        v38 = _mm_shuffle_ps(v34, v36, 221);
        v39 = _mm_shuffle_ps(v35, v37, 136);
LABEL_21:
        *(__m128 *)&sampleOutput[116] = v39;
        *(__m128 *)&sampleOutput[100] = v38;
        goto LABEL_22;
      }
      z = v22->z;
      *(__m128 *)&sampleOutput[84] = _mm_shuffle_ps((__m128)LODWORD(v22->x), (__m128)LODWORD(v22->x), 0);
      *(__m128 *)&sampleOutput[100] = _mm_shuffle_ps((__m128)LODWORD(v22->y), (__m128)LODWORD(v22->y), 0);
      v31 = 0;
      v31.m128_f32[0] = z;
      *(__m128 *)&sampleOutput[116] = _mm_shuffle_ps(v31, v31, 0);
LABEL_22:
      GatherSampleLightSSE(
        out: (SSE_sampleLightOutput_t *)&v55[48],
        dl: v12,
        facenum: -1,
        pos: (const FourVectors *)v55,
        pNormals: (FourVectors *)&sampleOutput[84],
        normalCount: 1,
        iThread,
        nLFlags: nLFlags | 1,
        static_prop_index_to_ignore: static_prop_id_to_skip,
        flEpsilon: 0.0);
      v45 = 0;
      if ( v8 >= 4 )
      {
        v46 = &outColors[1].z;
        do
        {
          v47 = *(float *)&sampleOutput[4 * v45 + 52] * *(float *)&v55[4 * v45 + 48];
          *(v46 - 5) = (float)(v12->light.intensity.x * v47) + *(v46 - 5);
          *(v46 - 4) = (float)(v12->light.intensity.y * v47) + *(v46 - 4);
          *(v46 - 3) = (float)(v12->light.intensity.z * v47) + *(v46 - 3);
          v48 = *(float *)&v55[4 * v45 + 52] * *(float *)&sampleOutput[4 * v45 + 56];
          *(v46 - 2) = (float)(v12->light.intensity.x * v48) + *(v46 - 2);
          *(v46 - 1) = (float)(v12->light.intensity.y * v48) + *(v46 - 1);
          v49 = (float)(v12->light.intensity.z * v48) + *v46;
          v50 = *(float *)&v55[4 * v45 + 56] * *(float *)&sampleOutput[4 * v45 + 60];
          *v46 = v49;
          v46[1] = (float)(v12->light.intensity.x * v50) + v46[1];
          v46[2] = (float)(v12->light.intensity.y * v50) + v46[2];
          v51 = (float)(v12->light.intensity.z * v50) + v46[3];
          v52 = *(float *)&sampleOutput[4 * v45] * *(float *)&sampleOutput[4 * v45 + 64];
          v46[3] = v51;
          v46[4] = (float)(v12->light.intensity.x * v52) + v46[4];
          v46[5] = (float)(v12->light.intensity.y * v52) + v46[5];
          v46[6] = (float)(v12->light.intensity.z * v52) + v46[6];
          v45 += 4;
          v46 += 12;
        }
        while ( v45 < v8 - 3 );
      }
      if ( v45 < v8 )
      {
        v53 = &outColors[v45].z;
        do
        {
          v54 = *(float *)&sampleOutput[4 * v45 + 52] * *(float *)&v55[4 * v45 + 48];
          *(v53 - 2) = (float)(v12->light.intensity.x * v54) + *(v53 - 2);
          *(v53 - 1) = (float)(v12->light.intensity.y * v54) + *(v53 - 1);
          *v53 = (float)(v12->light.intensity.z * v54) + *v53;
          ++v45;
          v53 += 3;
        }
        while ( v45 < v8 );
      }
LABEL_28:
      v12 = v12->next;
      if ( v12 == nullptr )
        return;
      v11 = *(_DWORD *)&sampleOutput[132];
    }
    v40 = *(__m128 *)&v22[1].x;
    v41 = _mm_shuffle_ps(*(__m128 *)&v22->x, v40, 68);
    v42 = _mm_shuffle_ps(*(__m128 *)&v22->x, v40, 238);
    v43 = _mm_shuffle_ps(*(__m128 *)&v22[2].x, *(__m128 *)&v22->x, 68);
    v44 = _mm_shuffle_ps(*(__m128 *)&v22[2].x, *(__m128 *)&v22->x, 238);
    *(__m128 *)&sampleOutput[84] = _mm_shuffle_ps(v41, v43, 136);
    v38 = _mm_shuffle_ps(v41, v43, 221);
    v39 = _mm_shuffle_ps(v42, v44, 136);
    goto LABEL_21;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B010
// Name: float clamp<float,int,int>(float const __near &,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl clamp<float,int,int>(float *val, const int *minVal, const int *maxVal)
{
  float v3; // xmm1_4
  float vala; // [esp+8h] [ebp+8h]

  v3 = (float)*minVal;
  vala = *val;
  if ( v3 > vala )
    return v3;
  if ( vala <= (float)*maxVal )
    return vala;
  return (float)*maxVal;
}

//------------------------------------------------------------------------------
// Address: 0x1002B060
// Name: public: void CUtlMemory<struct CVradStaticPropMgr::StaticPropDict_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CVradStaticPropMgr::StaticPropDict_t,int>::Grow(
        CUtlMemory<CVradStaticPropMgr::StaticPropDict_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CVradStaticPropMgr::StaticPropDict_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 136 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CVradStaticPropMgr::StaticPropDict_t *)_g_pMemAlloc->Realloc_2(
                                                                  this: _g_pMemAlloc,
                                                                  a2: m_pMemory,
                                                                  a3: v7);
    else
      this->m_pMemory = (CVradStaticPropMgr::StaticPropDict_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B100
// Name: public: void CUtlMemory<struct CVradStaticPropMgr::CStaticProp,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CVradStaticPropMgr::CStaticProp,int>::Grow(
        CUtlMemory<CVradStaticPropMgr::CStaticProp,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CVradStaticPropMgr::CStaticProp *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 96 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CVradStaticPropMgr::CStaticProp *)_g_pMemAlloc->Realloc_2(
                                                             this: _g_pMemAlloc,
                                                             a2: m_pMemory,
                                                             a3: v7);
    else
      this->m_pMemory = (CVradStaticPropMgr::CStaticProp *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B230
// Name: bool LoadStudioModel(char const __near *,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadStudioModel(const char *pModelName, CUtlBuffer *buf)
{
  IZip *PakFile; // eax
  unsigned __int8 *v4; // edi

  PakFile = GetPakFile();
  if ( ReadFileFromPak(pak: PakFile, pRelativeName: pModelName, bTextMode: false, buf)
    || g_pFullFileSystem != nullptr
    && g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: pModelName,
         a3: nullptr,
         a4: buf,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    if ( strncmp(first: (const char *)&buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset], last: "IDST", count: 4u) == 0
      || strncmp(first: (const char *)&buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset], last: "IDAG", count: 4u) == 0 )
    {
      v4 = &buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
      Studio_ConvertStudioHdrToNewVersion(pStudioHdr: (studiohdr_t *)v4);
      if ( *((_DWORD *)v4 + 1) == 49 )
      {
        if ( (v4[152] & 0x10) != 0 )
        {
          *((_DWORD *)v4 + 92) = 0;
          *((_DWORD *)v4 + 93) = 0;
          return 1;
        }
        else
        {
          _Warning(
            a1: "Error! To use model \"%s\"\n      as a static prop, it must be compiled with $staticprop!\n",
            pModelName);
          return 0;
        }
      }
      else
      {
        _Warning(a1: "Error! Invalid model version \"%s\"\n", pModelName);
        return 0;
      }
    }
    else
    {
      _Warning(a1: "Error! Invalid model file \"%s\"\n", pModelName);
      return 0;
    }
  }
  else
  {
    _Warning(a1: "Error! Unable to load model \"%s\"\n", pModelName);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B340
// Name: bool LoadStudioCollisionModel(char const __near *,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl LoadStudioCollisionModel(const char *pModelName, CUtlBuffer *buf)
{
  IZip *PakFile; // eax
  unsigned __int8 *v3; // eax
  bool result; // al
  char tmp[1024]; // [esp+4h] [ebp-400h] BYREF

  V_strncpy(pDest: tmp, pSrc: pModelName, maxLen: 1024);
  V_SetExtension(path: tmp, extension: ".phy", pathStringLength: 1024);
  PakFile = GetPakFile();
  result = false;
  if ( ReadFileFromPak(pak: PakFile, pRelativeName: tmp, bTextMode: false, buf)
    || g_pFullFileSystem != nullptr
    && g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: tmp,
         a3: nullptr,
         a4: buf,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    v3 = &buf->m_Memory.m_pMemory[buf->m_Get - buf->m_nOffset];
    if ( *(_DWORD *)v3 == 16 && *((int *)v3 + 2) > 0 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002B3E0
// Name: bool LoadVTXFile(char const __near *,struct studiohdr_t const __near *,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadVTXFile(const char *pModelName, const studiohdr_t *pStudioHdr, CUtlBuffer *buf)
{
  char *v3; // eax
  char v4; // cl
  IZip *PakFile; // eax
  int v7; // ecx
  int v8; // eax
  int checksum; // ecx
  char v10; // [esp-1h] [ebp-105h] BYREF
  char filename[260]; // [esp+0h] [ebp-104h] BYREF

  V_StripExtension(in: pModelName, out: filename, outSize: 260);
  v3 = &v10;
  do
    v4 = *++v3;
  while ( v4 != 0 );
  strcpy(v3, ".dx90.vtx");
  PakFile = GetPakFile();
  if ( ReadFileFromPak(pak: PakFile, pRelativeName: filename, bTextMode: false, buf)
    || g_pFullFileSystem != nullptr
    && g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: filename,
         a3: nullptr,
         a4: buf,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    v7 = *(_DWORD *)buf->m_Memory.m_pMemory;
    if ( v7 == 7 )
    {
      v8 = *((_DWORD *)buf->m_Memory.m_pMemory + 4);
      checksum = pStudioHdr->checksum;
      if ( v8 == checksum )
      {
        return 1;
      }
      else
      {
        _Warning(a1: "Error! Invalid VTX file checksum: %d, expected %d \"%s\"\n", v8, checksum, filename);
        return 0;
      }
    }
    else
    {
      _Warning(a1: "Error! Invalid VTX file version: %d, expected %d \"%s\"\n", v7, 7, filename);
      return 0;
    }
  }
  else
  {
    _Warning(a1: "Error! Unable to load file \"%s\"\n", filename);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B4F0
// Name: bool LoadFileIntoBuffer(class CUtlBuffer __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadFileIntoBuffer(CUtlBuffer *buf, const char *pFilename)
{
  void *v2; // edi
  int v4; // ebx
  int v5; // ebx

  v2 = g_pFileSystem->Open(this: g_pFileSystem, a2: pFilename, a3: "rb", a4: 0);
  if ( v2 == nullptr )
    return 0;
  v4 = g_pFileSystem->Size_2(this: g_pFileSystem, a2: v2);
  CUtlBuffer::EnsureCapacity(this: buf, num: v4);
  v5 = g_pFileSystem->Read(this: g_pFileSystem, a2: buf->m_Memory.m_pMemory, a3: v4, a4: v2);
  g_pFileSystem->Close(this: g_pFileSystem, a2: v2);
  CUtlBuffer::SeekPut(this: buf, type: SEEK_HEAD, offset: v5);
  CUtlBuffer::SeekGet(this: buf, type: SEEK_HEAD, offset: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002BC10
// Name: private: void CVradStaticPropMgr::SerializeLighting(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVradStaticPropMgr::SerializeLighting(CVradStaticPropMgr *this)
{
  CVradStaticPropMgr *v1; // edi
  int m_Size; // esi
  int v3; // eax
  int v4; // ecx
  int v5; // ebx
  int v6; // eax
  int v7; // edx
  int v8; // esi
  _DWORD *v9; // ecx
  unsigned int v10; // edi
  int v11; // edi
  int v12; // esi
  CVradStaticPropMgr *v13; // eax
  unsigned __int8 *m_pMemory; // ebx
  unsigned int v15; // edx
  int v16; // esi
  unsigned __int8 *v17; // esi
  BOOL v18; // ecx
  unsigned int v19; // edi
  int v20; // eax
  CVradStaticPropMgr *v21; // ecx
  unsigned int v22; // eax
  CUtlVector<CVradStaticPropMgr::MeshData_t,CUtlMemory<CVradStaticPropMgr::MeshData_t,int> > *p_m_MeshData; // eax
  CVradStaticPropMgr::MeshData_t *v24; // ecx
  unsigned __int8 v25; // al
  unsigned __int8 v26; // cl
  unsigned __int8 v27; // dl
  CVradStaticPropMgr *v28; // eax
  int v29; // ecx
  CVradStaticPropMgr::MeshData_t *v30; // edx
  IZip *PakFile; // eax
  char mapName[260]; // [esp+8h] [ebp-25Ch] BYREF
  char filename[260]; // [esp+10Ch] [ebp-158h] BYREF
  CUtlBuffer utlBuf; // [esp+210h] [ebp-54h] BYREF
  int count; // [esp+240h] [ebp-24h]
  ColorRGBExp32 rgbColor; // [esp+244h] [ebp-20h] BYREF
  int k; // [esp+248h] [ebp-1Ch]
  unsigned __int8 dstColor[4]; // [esp+24Ch] [ebp-18h] BYREF
  int i; // [esp+250h] [ebp-14h]
  int n; // [esp+254h] [ebp-10h]
  CVradStaticPropMgr *v41; // [esp+258h] [ebp-Ch]
  unsigned int v42; // [esp+25Ch] [ebp-8h]
  int totalVertexes; // [esp+260h] [ebp-4h]

  v1 = this;
  v41 = this;
  CUtlBuffer::CUtlBuffer(this: &utlBuf, growSize: 0, initSize: 0, nFlags: 0);
  m_Size = v1->m_StaticProps.m_Size;
  count = m_Size;
  if ( m_Size != 0 )
  {
    V_FileBase(in: source, out: mapName, maxlen: 260);
    v3 = 0;
    i = 0;
    if ( m_Size > 0 )
    {
      v42 = 0;
      while ( 1 )
      {
        if ( g_bHDR )
          sprintf(string: filename, format: "sp_hdr_%d.vhv", v3);
        else
          sprintf(string: filename, format: "sp_%d.vhv", v3);
        v4 = (int)&v1->m_StaticProps.m_Memory.m_pMemory[v42 / 0x60];
        v5 = 0;
        v6 = *(_DWORD *)(v4 + 80);
        v7 = 0;
        v8 = 0;
        totalVertexes = 0;
        n = v4;
        if ( v6 >= 2 )
        {
          v9 = (_DWORD *)(*(_DWORD *)(v4 + 68) + 48);
          v10 = ((unsigned int)(v6 - 2) >> 1) + 1;
          v5 = 2 * v10;
          do
          {
            v7 += *(v9 - 7);
            v8 += *v9;
            v9 += 14;
            --v10;
          }
          while ( v10 != 0 );
          v4 = n;
        }
        if ( v5 < v6 )
          totalVertexes = *(_DWORD *)(*(_DWORD *)(v4 + 68) + 28 * v5 + 20);
        v11 = g_numVradStaticPropsLightingStreams;
        totalVertexes += v8 + v7;
        v12 = 4 * (totalVertexes * g_numVradStaticPropsLightingStreams + 7 * (v6 + 38));
        CUtlBuffer::EnsureCapacity(this: &utlBuf, num: v12);
        _V_memset(dest: utlBuf.m_Memory.m_pMemory, fill: 0, count: v12);
        v13 = v41;
        m_pMemory = utlBuf.m_Memory.m_pMemory;
        v15 = v42;
        v16 = 7 * v41->m_StaticProps.m_Memory.m_pMemory[v42 / 0x60].m_MeshData.m_Size;
        *(_DWORD *)utlBuf.m_Memory.m_pMemory = 2;
        v17 = &m_pMemory[(4 * v16 + 551) & 0xFFFFFE00];
        v18 = v11 <= 1;
        *((_DWORD *)m_pMemory + 1) = v13->m_StaticPropDict.m_Memory.m_pMemory[*(int *)((char *)&v13->m_StaticProps.m_Memory.m_pMemory->m_ModelIdx
                                                                                     + v15)].m_pStudioHdr->checksum;
        *((_DWORD *)m_pMemory + 3) = 4 * v11;
        v19 = 0;
        n = 0;
        *((_DWORD *)m_pMemory + 2) = 2 * v18 + 2;
        *((_DWORD *)m_pMemory + 4) = totalVertexes;
        v20 = v13->m_StaticProps.m_Memory.m_pMemory[v42 / 0x60].m_MeshData.m_Size;
        *((_DWORD *)m_pMemory + 5) = v20;
        if ( v20 > 0 )
        {
          do
          {
            v21 = v41;
            v22 = v42;
            *(_DWORD *)&m_pMemory[v19 * 28 + 40] = v41->m_StaticProps.m_Memory.m_pMemory[v42 / 0x60].m_MeshData.m_Memory.m_pMemory[v19].m_nLod;
            *(_DWORD *)&m_pMemory[v19 * 28 + 44] = (*(CVradStaticPropMgr::MeshData_t **)((char *)&v21->m_StaticProps.m_Memory.m_pMemory->m_MeshData.m_Memory.m_pMemory
                                                                                       + v22))[v19].m_numVerts;
            *(_DWORD *)&m_pMemory[v19 * 28 + 48] = v17 - m_pMemory;
            p_m_MeshData = (CUtlVector<CVradStaticPropMgr::MeshData_t,CUtlMemory<CVradStaticPropMgr::MeshData_t,int> > *)((char *)&v21->m_StaticProps.m_Memory.m_pMemory->m_MeshData + v22);
            v24 = p_m_MeshData->m_Memory.m_pMemory;
            k = 0;
            if ( v24[v19].m_VertColorData.m_Size > 0 )
            {
              totalVertexes = 0;
              do
              {
                VectorToColorRGBExp32(
                  vin: (const Vector *)((char *)p_m_MeshData->m_Memory.m_pMemory[v19].m_VertColorData.m_Memory.m_pMemory
                                 + totalVertexes),
                  c: &rgbColor);
                ConvertRGBExp32ToRGBA8888(pSrc: &rgbColor, pDst: dstColor);
                v25 = dstColor[0];
                v26 = dstColor[2];
                v27 = dstColor[3];
                totalVertexes += 12;
                v17[1] = dstColor[1];
                v17[2] = v25;
                v28 = v41;
                *v17 = v26;
                v29 = k;
                v17[3] = v27;
                p_m_MeshData = &v28->m_StaticProps.m_Memory.m_pMemory[v42 / 0x60].m_MeshData;
                v30 = p_m_MeshData->m_Memory.m_pMemory;
                v17 += 4;
                k = v29 + 1;
              }
              while ( v29 + 1 < v30[v19].m_VertColorData.m_Size );
            }
            ++v19;
            ++n;
          }
          while ( n < *((_DWORD *)m_pMemory + 5) );
        }
        PakFile = GetPakFile();
        AddBufferToPak(
          pak: PakFile,
          pRelativeName: filename,
          data: m_pMemory,
          length: (v17 - m_pMemory + 511) & 0xFFFFFE00,
          bTextMode: false);
        v42 += 96;
        if ( ++i >= count )
          break;
        v1 = v41;
        v3 = i;
      }
    }
  }
  if ( utlBuf.m_Memory.m_nGrowSize >= 0 && utlBuf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: utlBuf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1002BEC0
// Name: public: struct vertexFileHeader_t const __near * mstudiomodel_t::CacheVertexData(void __near *)
// Source: json
//------------------------------------------------------------------------------
const vertexFileHeader_t *__thiscall mstudiomodel_t::CacheVertexData(mstudiomodel_t *this, _DWORD *pModelData)
{
  const vertexFileHeader_t *result; // eax
  int v3; // eax
  int v4; // ecx
  char *v5; // eax
  int v6; // ecx
  const char *v7; // eax
  const char *v8; // edx
  unsigned int v9; // eax
  char *v10; // edi
  char v11; // cl
  char *v12; // eax
  char v13; // cl
  IZip *PakFile; // eax
  unsigned int m_Put; // esi
  vertexFileHeader_t *m_pMemory; // edi
  int version; // eax
  int checksum; // eax
  vertexFileHeader_t *v19; // esi
  bool v20; // sf
  char v21; // [esp-1h] [ebp-139h] BYREF
  char fileName[260]; // [esp+0h] [ebp-138h] BYREF
  CUtlBuffer bufData; // [esp+104h] [ebp-34h] BYREF
  int vvdSize; // [esp+134h] [ebp-4h]

  result = (const vertexFileHeader_t *)pModelData[92];
  if ( result == nullptr )
  {
    strcpy(fileName, "models/");
    v3 = pModelData[100];
    if ( v3 != 0
      && (v4 = *(_DWORD *)((char *)pModelData + v3 + 20), v5 = (char *)pModelData + v3, v4 != 0)
      && &v5[v4] != nullptr )
    {
      v6 = *((_DWORD *)v5 + 5);
      if ( v6 != 0 )
        v7 = &v5[v6];
      else
        v7 = nullptr;
    }
    else
    {
      v7 = (const char *)(pModelData + 3);
    }
    v8 = v7;
    v9 = strlen(v7) + 1;
    v10 = &v21;
    do
      v11 = *++v10;
    while ( v11 != 0 );
    qmemcpy(v10, v8, v9);
    V_StripExtension(in: fileName, out: fileName, outSize: 260);
    v12 = &v21;
    do
      v13 = *++v12;
    while ( v13 != 0 );
    strcpy(v12, ".vvd");
    CUtlBuffer::CUtlBuffer(this: &bufData, growSize: 0, initSize: 0, nFlags: 0);
    PakFile = GetPakFile();
    if ( !ReadFileFromPak(pak: PakFile, pRelativeName: fileName, bTextMode: false, buf: &bufData)
      && (g_pFullFileSystem == nullptr
       || !g_pFullFileSystem->ReadFile(
             this: &g_pFullFileSystem->IBaseFileSystem,
             a2: fileName,
             a3: nullptr,
             a4: &bufData,
             a5: 0,
             a6: 0,
             a7: nullptr)) )
    {
      _Error(a1: "Unable to load vertex data \"%s\"\n", fileName);
    }
    m_Put = bufData.m_Put;
    vvdSize = bufData.m_Put;
    if ( bufData.m_Put == 0 )
      _Error(a1: "Bad size for vertex data \"%s\"\n", fileName);
    m_pMemory = (vertexFileHeader_t *)bufData.m_Memory.m_pMemory;
    if ( *(_DWORD *)bufData.m_Memory.m_pMemory != 1448297545 )
      _Error(
        a1: "Error Vertex File %s id %d should be %d\n",
        fileName,
        *(_DWORD *)bufData.m_Memory.m_pMemory,
        1448297545);
    version = m_pMemory->version;
    if ( version != 4 )
      _Error(a1: "Error Vertex File %s version %d should be %d\n", fileName, version, 4);
    checksum = m_pMemory->checksum;
    if ( checksum != pModelData[2] )
      _Error(a1: "Error Vertex File %s checksum %d should be %d\n", fileName, checksum, pModelData[2]);
    v19 = (vertexFileHeader_t *)MemAlloc_Alloc(nSize: m_Put);
    if ( v19 == nullptr )
      _Error(a1: "Error allocating %d bytes for Vertex File '%s'\n", vvdSize, fileName);
    Studio_LoadVertexes(pTempVvdHdr: m_pMemory, pNewVvdHdr: v19, rootLOD: 0, bNeedsTangentS: true);
    v20 = bufData.m_Memory.m_nGrowSize < 0;
    pModelData[92] = v19;
    if ( !v20 && bufData.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufData.m_Memory.m_pMemory);
    return v19;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002CAC0
// Name: public: struct mstudio_modelvertexdata_t const __near * mstudiomodel_t::GetVertexData(void __near *)
// Source: json
//------------------------------------------------------------------------------
const vertexFileHeader_t *__thiscall mstudiomodel_t::GetVertexData(mstudiomodel_t *this, _DWORD *pModelData)
{
  const vertexFileHeader_t *result; // eax
  int vertexDataStart; // ecx
  char *v5; // edx
  mstudio_modelvertexdata_t *p_vertexdata; // ecx
  int tangentDataStart; // esi

  result = mstudiomodel_t::CacheVertexData(this, pModelData);
  if ( result != nullptr )
  {
    if ( result->id == 1448297545 && (vertexDataStart = result->vertexDataStart) != 0 )
      v5 = (char *)result + vertexDataStart;
    else
      v5 = nullptr;
    p_vertexdata = &this->vertexdata;
    this->vertexdata.pVertexData = v5;
    if ( result->id == 1448297545 && (tangentDataStart = result->tangentDataStart) != 0 )
    {
      this->vertexdata.pTangentData = (char *)result + tangentDataStart;
      return v5 != nullptr ? (const vertexFileHeader_t *)p_vertexdata : nullptr;
    }
    else
    {
      this->vertexdata.pTangentData = nullptr;
      return v5 != nullptr ? (const vertexFileHeader_t *)p_vertexdata : nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002CB30
// Name: public: unsigned char __near * CShadowTextureList::LoadVTFRGB8888(char const __near *,int __near *,int __near *,bool __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__userpurge CShadowTextureList::LoadVTFRGB8888@<eax>(
        CShadowTextureList *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const char *pName,
        int *pWidth,
        int *pHeight,
        bool *pClampU,
        bool *pClampV)
{
  IVTFTexture *VTFTexture; // esi
  unsigned __int8 *v11; // eax
  IVTFTexture_vtbl *v12; // edx
  int v13; // edi
  int v14; // ebx
  unsigned int MemRequired; // eax
  void *v16; // esi
  bool v17; // sf
  char szPath[260]; // [esp+0h] [ebp-138h] BYREF
  CUtlBuffer buf; // [esp+104h] [ebp-34h] BYREF
  unsigned __int8 *pSrcImage; // [esp+134h] [ebp-4h]
  ImageFormat srcFormat; // [esp+140h] [ebp+8h]

  V_strncpy(pDest: szPath, pSrc: "materials/", maxLen: 260);
  V_strncat(pDest: szPath, pSrc: pName, destBufferSize: 0x104u, max_chars_to_copy: -1);
  V_strncat(pDest: szPath, pSrc: ".vtf", destBufferSize: 0x104u, max_chars_to_copy: -1);
  V_FixSlashes(pname: szPath, separator: 92);
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  if ( LoadFileIntoBuffer(&buf, pFilename: szPath) != 0 )
  {
    VTFTexture = CreateVTFTexture();
    if ( ((unsigned __int8 (__thiscall *)(IVTFTexture *, CUtlBuffer *, _DWORD, _DWORD, int))VTFTexture->Unserialize)(
           a1: VTFTexture,
           a2: &buf,
           a3: 0,
           a4: 0,
           a5: a4) != 0 )
    {
      _Msg(a1: "Loaded alpha texture %s\n", szPath);
      v11 = (unsigned __int8 *)((int (__thiscall *)(IVTFTexture *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, int))VTFTexture->ImageData)(
                                 a1: VTFTexture,
                                 a2: 0,
                                 a3: 0,
                                 a4: 0,
                                 a5: 0,
                                 a6: 0,
                                 a7: 0,
                                 a8: a3,
                                 a9: a2);
      v12 = VTFTexture->__vftable;
      pSrcImage = v11;
      v13 = v12->Width(this: VTFTexture);
      v14 = VTFTexture->Height(this: VTFTexture);
      srcFormat = VTFTexture->Format(this: VTFTexture);
      *pClampU = (VTFTexture->Flags(this: VTFTexture) & 4) != 0;
      *pClampV = (VTFTexture->Flags(this: VTFTexture) & 8) != 0;
      MemRequired = ImageLoader::GetMemRequired(
                      width: v13,
                      height: v14,
                      depth: 1,
                      imageFormat: IMAGE_FORMAT_RGBA8888,
                      mipmap: false,
                      pAdjustedHeight: nullptr);
      v16 = MemAlloc_Alloc(nSize: MemRequired);
      if ( ImageLoader::ConvertImageFormat(
             src: pSrcImage,
             srcImageFormat: srcFormat,
             dst: (unsigned __int8 *)v16,
             dstImageFormat: IMAGE_FORMAT_RGBA8888,
             width: v13,
             height: v14,
             srcStride: 0,
             dstStride: 0) )
      {
        v17 = buf.m_Memory.m_nGrowSize < 0;
        *pWidth = v13;
        *pHeight = v14;
        if ( !v17 && buf.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
        return (unsigned __int8 *)v16;
      }
      else
      {
        free(pMem: v16);
        if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
        return nullptr;
      }
    }
    else
    {
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      return nullptr;
    }
  }
  else
  {
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002CD30
// Name: public: float CShadowTextureList::ComputeCoverageForTriangle(int,class Vector2D const __near &,class Vector2D const __near &,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CShadowTextureList::ComputeCoverageForTriangle(
        CShadowTextureList *this,
        unsigned __int16 shadowTextureIndex,
        const Vector2D *t0,
        const Vector2D *t1,
        const Vector2D *t2)
{
  float x; // xmm5_4
  float v6; // xmm4_4
  float y; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  UtlRBTreeNode_t<CUtlMap<char const *,CShadowTextureList::alphatexture_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // ecx
  int width; // esi
  CShadowTextureList::alphatexture_t *p_elem; // edi
  float v15; // xmm3_4
  int v16; // ebx
  float v17; // xmm0_4
  int v18; // edx
  int v19; // ecx
  int v20; // esi
  int v21; // eax
  unsigned int v22; // eax
  unsigned __int8 *v23; // ecx
  bool v24; // zf
  int u; // [esp+0h] [ebp-10h]
  int v27; // [esp+8h] [ebp-8h]
  int v28; // [esp+Ch] [ebp-4h]
  int shadowTextureIndexa; // [esp+18h] [ebp+8h]
  int count; // [esp+1Ch] [ebp+Ch]
  int total; // [esp+20h] [ebp+10h]
  const Vector2D *t2a; // [esp+24h] [ebp+14h]

  if ( t1->x <= t0->x )
    x = t1->x;
  else
    x = t0->x;
  if ( t2->x <= x )
    x = t2->x;
  if ( t0->x <= t1->x )
    v6 = t1->x;
  else
    v6 = t0->x;
  if ( v6 <= t2->x )
    v6 = t2->x;
  y = t0->y;
  v8 = t1->y;
  if ( v8 <= y )
    v9 = t1->y;
  else
    v9 = t0->y;
  v10 = t2->y;
  if ( v10 <= v9 )
    v9 = t2->y;
  if ( y > v8 )
    v8 = t0->y;
  if ( v8 <= v10 )
    v8 = t2->y;
  v11 = 1.0;
  if ( x >= 0.0 )
  {
    if ( x > 1.0 )
      x = 1.0;
  }
  else
  {
    x = 0.0;
  }
  if ( v6 >= 0.0 )
  {
    if ( v6 > 1.0 )
      v6 = 1.0;
  }
  else
  {
    v6 = 0.0;
  }
  if ( v9 >= 0.0 )
  {
    if ( v9 > 1.0 )
      v9 = 1.0;
  }
  else
  {
    v9 = 0.0;
  }
  if ( v8 >= 0.0 )
  {
    if ( v8 <= 1.0 )
      v11 = v8;
  }
  else
  {
    v11 = 0.0;
  }
  m_pMemory = this->m_Textures.m_Elements.m_Tree.m_Elements.m_pMemory;
  width = m_pMemory[shadowTextureIndex].m_Data.elem.width;
  p_elem = &m_pMemory[shadowTextureIndex].m_Data.elem;
  v15 = (float)(width - 1);
  v16 = (int)(float)(v15 * v6);
  v17 = (float)(m_pMemory[shadowTextureIndex].m_Data.elem.height - 1);
  v18 = (int)(float)(v15 * x);
  total = 0;
  count = 0;
  v19 = (int)(float)(v17 * v9);
  if ( v19 > (int)(float)(v17 * v11) )
    return 1.0;
  v20 = v19 * width;
  v28 = v20;
  v27 = (int)(float)(v17 * v11) - v19 + 1;
  do
  {
    t2a = nullptr;
    shadowTextureIndexa = 0;
    v21 = (int)(float)(v15 * x);
    if ( v18 <= v16 )
    {
      if ( v16 - v18 + 1 >= 2 )
      {
        v22 = ((unsigned int)(v16 - v18 - 1) >> 1) + 1;
        count += 2 * v22;
        v23 = &p_elem->pAlphaTexels[v20 + v18];
        u = v18 + 2 * v22;
        do
        {
          t2a = (const Vector2D *)((char *)t2a + *v23);
          shadowTextureIndexa += v23[1];
          v23 += 2;
          --v22;
        }
        while ( v22 != 0 );
        v16 = (int)(float)(v15 * v6);
        v21 = u;
        v20 = v28;
      }
      if ( v21 <= v16 )
      {
        total += p_elem->pAlphaTexels[v20 + v21];
        ++count;
      }
      total += (int)t2a + shadowTextureIndexa;
    }
    v20 += p_elem->width;
    v24 = v27-- == 1;
    v28 = v20;
  }
  while ( !v24 );
  if ( count != 0 )
    return (double)total / ((double)count * 255.0);
  else
    return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1002CF10
// Name: public: int CShadowTextureList::SampleMaterial(int,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShadowTextureList::SampleMaterial(
        CShadowTextureList *this,
        int materialIndex,
        const Vector *coords,
        bool bBackface)
{
  float *p_textureIndex; // eax
  CShadowTextureList::alphatexture_t *p_elem; // esi
  float v7; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm5_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm4_4
  int width; // eax
  float v14; // xmm0_4
  __m128 v15; // xmm4
  float v16; // xmm3_4
  float v17; // xmm2_4
  __m128 v18; // xmm0
  __m128 v19; // xmm1
  __m128 v20; // xmm3
  __m128 v21; // xmm5
  __m128 v22; // xmm3
  __m128 v23; // xmm4
  int v24; // ecx
  __m128 v25; // xmm3
  __m128 v26; // xmm3
  __m128 v27; // xmm4
  int v28; // edx
  int v29; // ebx
  int v30; // ecx
  int v31; // ebx
  int v32; // edi
  int v33; // edx
  unsigned __int8 *pAlphaTexels; // esi
  int u1; // [esp+Ch] [ebp+8h]

  p_textureIndex = (float *)&this->m_MaterialEntries.m_Memory.m_pMemory[materialIndex].textureIndex;
  p_elem = &this->m_Textures.m_Elements.m_Tree.m_Elements.m_pMemory[*(unsigned __int16 *)p_textureIndex].m_Data.elem;
  if ( bBackface
    && !this->m_Textures.m_Elements.m_Tree.m_Elements.m_pMemory[*(unsigned __int16 *)p_textureIndex].m_Data.elem.allowBackface )
  {
    return 0;
  }
  v7 = p_textureIndex[2] * coords->x;
  v8 = p_textureIndex[6] * coords->z;
  v9 = p_textureIndex[4] * coords->y;
  v10 = p_textureIndex[1] * coords->x;
  v11 = p_textureIndex[5] * coords->z;
  v12 = p_textureIndex[3] * coords->y;
  width = p_elem->width;
  v14 = v10 + v12;
  v15.m128_i32[0] = 1258291200;
  v16 = v8 + (float)(v7 + v9);
  v17 = v11 + v14;
  v18 = 0;
  v19 = 0;
  v19.m128_f32[0] = (float)p_elem->height * v16;
  v18.m128_f32[0] = (float)width * v17;
  v20 = _mm_and_ps((__m128)0x80000000, v18);
  v21.m128_i32[0] = v20.m128_i32[0];
  v15.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v18, v20), v15).m128_f32[0]) & 0x4B000000
                  | v20.m128_i32[0];
  v22 = v18;
  v22.m128_f32[0] = (float)(v18.m128_f32[0] + v15.m128_f32[0]) - v15.m128_f32[0];
  v23 = v22;
  v23.m128_f32[0] = v22.m128_f32[0] - v18.m128_f32[0];
  v22.m128_f32[0] = v22.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v23, v21).m128_f32[0]) & 0x3F800000);
  v23.m128_i32[0] = 1258291200;
  v24 = (int)v22.m128_f32[0];
  v25 = _mm_and_ps((__m128)0x80000000, v19);
  v21.m128_i32[0] = v25.m128_i32[0];
  v23.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v19, v25), v23).m128_f32[0]) & 0x4B000000
                  | v25.m128_i32[0];
  v26 = v19;
  v26.m128_f32[0] = (float)(v19.m128_f32[0] + v23.m128_f32[0]) - v23.m128_f32[0];
  v27 = v26;
  v27.m128_f32[0] = v26.m128_f32[0] - v19.m128_f32[0];
  v28 = (int)(float)(v26.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v27, v21).m128_f32[0]) & 0x3F800000));
  v29 = (width - 1) & (v24 + 1);
  v30 = (width - 1) & v24;
  u1 = v29;
  v31 = v28 + 1;
  v32 = p_elem->height - 1;
  v33 = v32 & v28;
  v18.m128_f32[0] = v18.m128_f32[0] - (float)v30;
  pAlphaTexels = p_elem->pAlphaTexels;
  return (int)(float)((float)((float)(int)(float)((float)((float)pAlphaTexels[width * v33 + u1] * v18.m128_f32[0])
                                                + (float)((float)pAlphaTexels[width * v33 + v30]
                                                        * (float)(1.0 - v18.m128_f32[0])))
                            * (float)(1.0 - (float)(v19.m128_f32[0] - (float)v33)))
                    + (float)((float)(int)(float)((float)((float)pAlphaTexels[(v32 & v31) * width + u1] * v18.m128_f32[0])
                                                + (float)((float)pAlphaTexels[(v32 & v31) * width + v30]
                                                        * (float)(1.0 - v18.m128_f32[0])))
                            * (float)(v19.m128_f32[0] - (float)v33)));
}

//------------------------------------------------------------------------------
// Address: 0x1002D110
// Name: float ComputeCoverageFromTexture(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
double __cdecl ComputeCoverageFromTexture(float b0, float b1, float b2, int hitID)
{
  int v4; // eax
  Vector coords; // [esp+0h] [ebp-Ch] BYREF

  coords.x = b0;
  v4 = g_RtEnv.TriangleMaterials.m_Memory.m_pMemory[hitID];
  coords.y = b1;
  coords.z = b2;
  return (double)CShadowTextureList::SampleMaterial(
                   this: &g_ShadowTextureList,
                   materialIndex: v4,
                   &coords,
                   bBackface: false)
       * 0.0039215689;
}

//------------------------------------------------------------------------------
// Address: 0x1002D170
// Name: float ComputeCoverageForTriangle(int,class Vector2D const __near &,class Vector2D const __near &,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl ComputeCoverageForTriangle(
        unsigned __int16 shadowTextureIndex,
        const Vector2D *t0,
        const Vector2D *t1,
        const Vector2D *t2)
{
  return CShadowTextureList::ComputeCoverageForTriangle(this: &g_ShadowTextureList, shadowTextureIndex, t0, t1, t2);
}

//------------------------------------------------------------------------------
// Address: 0x1002D190
// Name: void GetShadowTextureMapping(int,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetShadowTextureMapping(unsigned __int16 shadowTextureIndex, int *pWidth, int *pHeight)
{
  int v3; // eax

  v3 = shadowTextureIndex;
  *pWidth = g_ShadowTextureList.m_Textures.m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem.width;
  *pHeight = g_ShadowTextureList.m_Textures.m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem.height;
}

//------------------------------------------------------------------------------
// Address: 0x1002D250
// Name: ComputeConvexHull
// Source: json
//------------------------------------------------------------------------------
CPhysConvex *__usercall ComputeConvexHull@<eax>(mstudiomesh_t *pMesh@<edi>, studiohdr_t *pStudioHdr@<eax>)
{
  int numvertices; // ebx
  const mstudio_modelvertexdata_t *v3; // eax
  mstudio_meshvertexdata_t *v4; // esi
  void *v5; // esp
  int v6; // ecx
  _DWORD v8[2]; // [esp+0h] [ebp-Ch] BYREF
  Vector **ppVerts; // [esp+8h] [ebp-4h]

  mstudiomodel_t::GetVertexData(this: (mstudiomodel_t *)((char *)pMesh + pMesh->modelindex), pModelData: pStudioHdr);
  numvertices = pMesh->numvertices;
  v3 = (const mstudio_modelvertexdata_t *)((char *)&pMesh->unused[6] + pMesh->modelindex);
  pMesh->vertexdata.modelvertexdata = v3;
  v4 = v3->pVertexData != nullptr ? &pMesh->vertexdata : nullptr;
  v5 = alloca(4 * numvertices);
  v6 = 0;
  ppVerts = (Vector **)v8;
  if ( numvertices > 0 )
  {
    do
    {
      v8[v6] = (char *)v4->modelvertexdata->pVertexData
             + 48 * ((int)v4[-1].modelvertexdata + (unsigned int)v4->modelvertexdata[-3].pVertexData / 0x30 + v6)
             + 16;
      ++v6;
    }
    while ( v6 < pMesh->numvertices );
  }
  return s_pPhysCollision->ConvexFromVerts(this: s_pPhysCollision, a2: ppVerts, a3: pMesh->numvertices);
}

//------------------------------------------------------------------------------
// Address: 0x1002D2E0
// Name: class CPhysCollide __near * ComputeConvexHull(struct studiohdr_t __near *)
// Source: json
//------------------------------------------------------------------------------
CPhysCollide *__cdecl ComputeConvexHull(studiohdr_t *pStudioHdr)
{
  studiohdr_t *v1; // eax
  CPhysConvex **v2; // ebx
  int m_Size; // esi
  int v4; // ecx
  mstudiobodyparts_t *v5; // ecx
  int v6; // ebx
  int v7; // ebx
  int v8; // edi
  CPhysConvex **m_pMemory; // ecx
  CPhysConvex **v10; // edi
  bool v11; // cc
  CPhysCollide *v12; // esi
  CUtlVector<CPhysConvex *,CUtlMemory<CPhysConvex *,int> > convexHulls; // [esp+Ch] [ebp-34h] BYREF
  mstudiobodyparts_t *pBodyPart; // [esp+20h] [ebp-20h]
  CPhysConvex *v16; // [esp+24h] [ebp-1Ch]
  int body; // [esp+28h] [ebp-18h]
  int v18; // [esp+2Ch] [ebp-14h]
  int model; // [esp+30h] [ebp-10h]
  int mesh; // [esp+34h] [ebp-Ch]
  int v21; // [esp+38h] [ebp-8h]
  int v22; // [esp+3Ch] [ebp-4h]

  v1 = pStudioHdr;
  v2 = nullptr;
  m_Size = 0;
  memset(&convexHulls, 0, sizeof(convexHulls));
  body = 0;
  if ( pStudioHdr->numbodyparts > 0 )
  {
    v21 = 0;
    do
    {
      v4 = v21 + v1->bodypartindex;
      model = 0;
      v5 = (mstudiobodyparts_t *)((char *)v1 + v4);
      pBodyPart = v5;
      if ( v5->nummodels > 0 )
      {
        v6 = 0;
        v18 = 0;
        do
        {
          v7 = (int)v5 + v6 + v5->modelindex;
          mesh = 0;
          if ( *(int *)(v7 + 72) > 0 )
          {
            v22 = 0;
            do
            {
              v16 = ComputeConvexHull(pMesh: (mstudiomesh_t *)(v7 + v22 + *(_DWORD *)(v7 + 76)), pStudioHdr: v1);
              v8 = m_Size;
              if ( m_Size + 1 > convexHulls.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<int,int>::Grow(
                  this: (CUtlMemory<S3RGBA,int> *)&convexHulls,
                  num: m_Size - convexHulls.m_Memory.m_nAllocationCount + 1);
                m_Size = convexHulls.m_Size;
              }
              m_pMemory = convexHulls.m_Memory.m_pMemory;
              convexHulls.m_Size = ++m_Size;
              convexHulls.m_pElements = convexHulls.m_Memory.m_pMemory;
              if ( m_Size - v8 - 1 > 0 )
              {
                _V_memmove(
                  dest: &convexHulls.m_Memory.m_pMemory[v8 + 1],
                  src: &convexHulls.m_Memory.m_pMemory[v8],
                  count: 4 * (m_Size - v8 - 1));
                m_pMemory = convexHulls.m_Memory.m_pMemory;
              }
              v10 = &m_pMemory[v8];
              if ( v10 != nullptr )
                *v10 = v16;
              v22 += 116;
              v11 = ++mesh < *(_DWORD *)(v7 + 72);
              v1 = pStudioHdr;
            }
            while ( v11 );
            v5 = pBodyPart;
          }
          v6 = v18 + 148;
          ++model;
          v18 += 148;
        }
        while ( model < v5->nummodels );
        v2 = convexHulls.m_Memory.m_pMemory;
      }
      v21 += 16;
      ++body;
    }
    while ( body < v1->numbodyparts );
  }
  v12 = s_pPhysCollision->ConvertConvexToCollide(this: s_pPhysCollision, a2: v2, a3: m_Size);
  if ( convexHulls.m_Memory.m_nGrowSize >= 0 && v2 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v2);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x1002D430
// Name: int AddShadowTextureTriangle(int,class Vector2D const __near &,class Vector2D const __near &,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AddShadowTextureTriangle(
        int shadowTextureIndex,
        const Vector2D *t0,
        const Vector2D *t1,
        const Vector2D *t2)
{
  int result; // eax
  Vector2D *uv; // edx
  Vector2D *v6; // edx
  Vector2D *v7; // ecx

  result = CUtlVector<CShadowTextureList::materialentry_t,CUtlMemory<CShadowTextureList::materialentry_t,int>>::InsertBefore(
             this: &g_ShadowTextureList.m_MaterialEntries,
             elem: g_ShadowTextureList.m_MaterialEntries.m_Size);
  g_ShadowTextureList.m_MaterialEntries.m_Memory.m_pMemory[result].textureIndex = shadowTextureIndex;
  uv = g_ShadowTextureList.m_MaterialEntries.m_Memory.m_pMemory[result].uv;
  uv->x = t0->x;
  uv->y = t0->y;
  v6 = &g_ShadowTextureList.m_MaterialEntries.m_Memory.m_pMemory[result].uv[1];
  v6->x = t1->x;
  v6->y = t1->y;
  v7 = &g_ShadowTextureList.m_MaterialEntries.m_Memory.m_pMemory[result].uv[2];
  v7->x = t2->x;
  v7->y = t2->y;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002D4B0
// Name: private: void CVradStaticPropMgr::ComputeLighting(struct CVradStaticPropMgr::CStaticProp __near &,int,int,class CComputeStaticPropLightingResults __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CVradStaticPropMgr::ComputeLighting(
        CVradStaticPropMgr *this@<ecx>,
        const mstudio_meshvertexdata_t *a2@<ebp>,
        CVradStaticPropMgr::CStaticProp *prop,
        int iThread,
        int prop_index,
        CComputeStaticPropLightingResults *pResults)
{
  CVradStaticPropMgr::StaticPropDict_t *v6; // eax
  float z; // esi
  int v8; // eax
  int v9; // eax
  bool v10; // cc
  CUtlMemory<colorVertex_t,int> *v11; // eax
  float x; // esi
  int m_Size; // edx
  int m_nAllocationCount; // eax
  CUtlVector<colorVertex_t,CUtlMemory<colorVertex_t,int> > **m_pMemory; // ecx
  int v16; // eax
  CUtlVector<colorVertex_t,CUtlMemory<colorVertex_t,int> > **v17; // edx
  int v18; // ecx
  int v19; // edi
  int v20; // ecx
  int v21; // edx
  colorVertex_t *v22; // edx
  int v23; // eax
  char *v24; // edi
  int v25; // ecx
  char *v26; // edi
  const vertexFileHeader_t *v27; // eax
  int vertexDataStart; // ecx
  float v29; // ecx
  badVertex_t *m_pElements; // edx
  int tangentDataStart; // ecx
  char *v32; // eax
  char *v33; // eax
  badVertex_t *v34; // edi
  float v35; // xmm2_4
  badVertex_t *v36; // eax
  badVertex_t *v37; // ecx
  int v38; // eax
  void *v39; // eax
  int v40; // edx
  int v41; // eax
  badVertex_t *v42; // ecx
  unsigned int v43; // eax
  colorVertex_t *v44; // ecx
  char *v45; // edx
  colorVertex_t *v46; // ecx
  float *v47; // ecx
  float v48; // xmm0_4
  float *v49; // ecx
  bool v50; // zf
  int v51; // eax
  int v52; // edx
  float v53; // xmm0_4
  float *v54; // ecx
  float *v55; // edi
  float v56; // xmm1_4
  float y; // xmm2_4
  int z_low; // xmm3_4
  float v59; // xmm3_4
  int v60; // eax
  int v61; // ecx
  int v62; // eax
  float v63; // xmm0_4
  float v64; // xmm1_4
  __int128 v65; // xmm0
  int v66; // eax
  int v67; // eax
  float v68; // xmm0_4
  Vector *v69; // edi
  int v70; // edx
  float *v71; // eax
  int v72; // ecx
  int v73; // eax
  colorVertex_t *v74; // ecx
  int v75; // edi
  colorVertex_t *v76; // ecx
  float *v77; // ecx
  float v78; // xmm0_4
  float *v79; // ecx
  int v80; // eax
  int v81; // edi
  float v82; // xmm0_4
  float *v83; // ecx
  _BYTE v84[12]; // [esp-Ch] [ebp-1CCh] BYREF
  __int128 matrix_36; // [esp+24h] [ebp-19Ch] OVERLAPPED
  Vector v86; // [esp+40h] [ebp-180h] BYREF
  unsigned __int8 direct_pos[48]; // [esp+4Ch] [ebp-174h] OVERLAPPED BYREF
  unsigned int v88; // [esp+7Ch] [ebp-144h]
  _BYTE v89[60]; // [esp+80h] [ebp-140h] OVERLAPPED BYREF
  _BYTE vecTexS[112]; // [esp+BCh] [ebp-104h] OVERLAPPED BYREF
  Vector v91; // [esp+130h] [ebp-90h] BYREF
  __int128 midPosition; // [esp+13Ch] [ebp-84h] OVERLAPPED BYREF
  mstudiobodyparts_t *pBodyPart; // [esp+14Ch] [ebp-74h]
  Vector samplePosition; // [esp+150h] [ebp-70h] BYREF
  Vector vecTexT; // [esp+15Ch] [ebp-64h]
  CUtlVector<colorVertex_t,CUtlMemory<colorVertex_t,int> > *pColorVertsArray; // [esp+168h] [ebp-58h]
  int bodyID; // [esp+16Ch] [ebp-54h]
  studiohdr_t *pStudioHdr; // [esp+170h] [ebp-50h]
  float v99; // [esp+174h] [ebp-4Ch] BYREF
  mstudiomesh_t *pStudioMesh; // [esp+178h] [ebp-48h]
  int modelID; // [esp+17Ch] [ebp-44h]
  Vector bestPosition; // [esp+180h] [ebp-40h] BYREF
  mstudiomodel_t *pStudioModel; // [esp+18Ch] [ebp-34h]
  CUtlVector<badVertex_t,CUtlMemory<badVertex_t,int> > badVerts; // [esp+190h] [ebp-30h]
  int numVertexes; // [esp+1A4h] [ebp-1Ch]
  int vertexID; // [esp+1A8h] [ebp-18h]
  int k; // [esp+1ACh] [ebp-14h]
  int skip_prop; // [esp+1B0h] [ebp-10h]
  const mstudio_meshvertexdata_t *vertData; // [esp+1B4h] [ebp-Ch] BYREF
  int best; // [esp+1B8h] [ebp-8h]
  int retaddr; // [esp+1C0h] [ebp+0h]

  vertData = a2;
  best = retaddr;
  v6 = &this->m_StaticPropDict.m_Memory.m_pMemory[prop->m_ModelIdx];
  z = *(float *)&v6->m_pStudioHdr;
  bestPosition.y = 0.0;
  bestPosition.z = 0.0;
  pStudioModel = nullptr;
  badVerts.m_Memory.m_pMemory = nullptr;
  badVerts.m_Memory.m_nAllocationCount = 0;
  vecTexT.z = z;
  if ( z != 0.0 && v6->m_VtxBuf.m_Memory.m_pMemory != nullptr )
  {
    v88 = (prop->m_Flags & 8 | ((unsigned int)prop->m_Flags >> 2) & 0x10) >> 2;
    VMPI_SetCurrentStage(pCurStage: "ComputeLighting");
    vecTexT.y = 0.0;
    if ( *(int *)(LODWORD(z) + 232) > 0 )
    {
      while ( 1 )
      {
        v8 = *(_DWORD *)(LODWORD(z) + 236) + 16 * LODWORD(vecTexT.y);
        pStudioHdr = nullptr;
        v9 = LODWORD(z) + v8;
        v10 = *(_DWORD *)(v9 + 4) <= 0;
        DWORD1(midPosition) = v9;
        if ( !v10 )
        {
          do
          {
            LODWORD(bestPosition.x) = DWORD1(midPosition)
                                    + *(_DWORD *)(DWORD1(midPosition) + 12)
                                    + 148 * (_DWORD)pStudioHdr;
            skip_prop = g_numVradStaticPropsLightingStreams <= 1 ? 1 : 4;
            v11 = (CUtlMemory<colorVertex_t,int> *)MemAlloc_Alloc(nSize: 0x14u);
            if ( v11 != nullptr )
            {
              x = *(float *)&v11;
              v11->m_pMemory = nullptr;
              v11->m_nAllocationCount = 0;
              v11->m_nGrowSize = 0;
              v11[1].m_pMemory = nullptr;
              v11[1].m_nAllocationCount = 0;
              LODWORD(vecTexT.x) = v11;
            }
            else
            {
              vecTexT.x = 0.0;
              x = 0.0;
            }
            m_nAllocationCount = pResults->m_ColorVertsArrays.m_Memory.m_nAllocationCount;
            badVerts.m_Size = pResults->m_ColorVertsArrays.m_Size;
            m_Size = badVerts.m_Size;
            if ( badVerts.m_Size + 1 > m_nAllocationCount )
            {
              CUtlMemory<int,int>::Grow(
                this: (CUtlMemory<S3RGBA,int> *)pResults,
                num: badVerts.m_Size - m_nAllocationCount + 1);
              m_Size = badVerts.m_Size;
            }
            ++pResults->m_ColorVertsArrays.m_Size;
            m_pMemory = pResults->m_ColorVertsArrays.m_Memory.m_pMemory;
            v16 = pResults->m_ColorVertsArrays.m_Size - m_Size - 1;
            pResults->m_ColorVertsArrays.m_pElements = pResults->m_ColorVertsArrays.m_Memory.m_pMemory;
            if ( v16 > 0 )
            {
              _V_memmove(dest: &m_pMemory[badVerts.m_Size + 1], src: &m_pMemory[badVerts.m_Size], count: 4 * v16);
              m_Size = badVerts.m_Size;
            }
            v17 = &pResults->m_ColorVertsArrays.m_Memory.m_pMemory[m_Size];
            if ( v17 != nullptr )
              *(float *)v17 = x;
            v18 = *(_DWORD *)(LODWORD(bestPosition.x) + 80);
            v19 = *(_DWORD *)(LODWORD(x) + 12);
            if ( v19 < v18 )
            {
              v20 = v18 - v19;
              k = v20;
              if ( v20 != 0 )
              {
                v21 = *(_DWORD *)(LODWORD(x) + 4);
                badVerts.m_pElements = (badVertex_t *)(v20 + v19);
                if ( v20 + v19 > v21 )
                {
                  CUtlMemory<colorVertex_t,int>::Grow(
                    this: (CUtlMemory<colorVertex_t,int> *)LODWORD(x),
                    num: v19 + v20 - v21);
                  v20 = k;
                }
                *(_DWORD *)(LODWORD(x) + 12) += v20;
                v22 = *(colorVertex_t **)LODWORD(x);
                v23 = *(_DWORD *)(LODWORD(x) + 12) - v19 - v20;
                *(_DWORD *)(LODWORD(x) + 16) = *(_DWORD *)LODWORD(x);
                if ( v23 > 0 && v20 > 0 )
                  _V_memmove(dest: &v22[(int)badVerts.m_pElements], src: &v22[v19], count: v23 << 6);
              }
            }
            memset(dst: *(unsigned __int8 **)LODWORD(x), value: 0, count: *(_DWORD *)(LODWORD(x) + 12) << 6);
            badVerts.m_Memory.m_nGrowSize = 0;
            k = 0;
            if ( *(int *)(LODWORD(bestPosition.x) + 72) > 0 )
            {
              pColorVertsArray = nullptr;
              do
              {
                v24 = (char *)pColorVertsArray + *(_DWORD *)(LODWORD(bestPosition.x) + 76);
                v25 = *(_DWORD *)&v24[LODWORD(bestPosition.x) + 4];
                v26 = &v24[LODWORD(bestPosition.x)];
                bodyID = (int)v26;
                badVerts.m_pElements = (badVertex_t *)&v26[v25];
                v27 = mstudiomodel_t::CacheVertexData(
                        this: (mstudiomodel_t *)&v26[v25],
                        pModelData: (_DWORD *)LODWORD(vecTexT.z));
                if ( v27 != nullptr )
                {
                  if ( v27->id == 1448297545 && (vertexDataStart = v27->vertexDataStart) != 0 )
                    LODWORD(v29) = (char *)v27 + vertexDataStart;
                  else
                    v29 = 0.0;
                  m_pElements = badVerts.m_pElements;
                  badVerts.m_pElements[1].m_Normals[2].y = v29;
                  if ( v27->id == 1448297545 && (tangentDataStart = v27->tangentDataStart) != 0 )
                    v32 = (char *)v27 + tangentDataStart;
                  else
                    v32 = nullptr;
                  LODWORD(m_pElements[1].m_Normals[2].z) = v32;
                }
                v33 = &v26[*((_DWORD *)v26 + 1) + 108];
                *((_DWORD *)v26 + 12) = v33;
                v10 = *((_DWORD *)v26 + 2) <= 0;
                vertexID = *(_DWORD *)v33 != 0 ? (unsigned int)(v26 + 48) : 0;
                badVerts.m_Size = 0;
                if ( !v10 )
                {
                  v34 = (badVertex_t *)(badVerts.m_Memory.m_nGrowSize << 6);
                  LODWORD(midPosition) = &prop->m_Angles;
                  badVerts.m_pElements = (badVertex_t *)(badVerts.m_Memory.m_nGrowSize << 6);
                  do
                  {
                    AngleMatrix(
                      angles: (const QAngle *)midPosition,
                      position: &prop->m_Origin,
                      matrix: (matrix3x4_t *)v84);
                    VectorTransform(
                      in1: (const float *)(**(_DWORD **)vertexID
                                    + 48
                                    * (badVerts.m_Size
                                     + *(_DWORD *)(vertexID - 36)
                                     + *(_DWORD *)(*(_DWORD *)vertexID - 24) / 0x30u)
                                    + 16),
                      in2: (const matrix3x4_t *)v84,
                      out: (float *)&midPosition + 2);
                    AngleMatrix(angles: (const QAngle *)midPosition, matrix: (matrix3x4_t *)v84);
                    VectorTransform(
                      in1: (const float *)(**(_DWORD **)vertexID
                                    + 48
                                    * (badVerts.m_Size
                                     + *(_DWORD *)(vertexID - 36)
                                     + *(_DWORD *)(*(_DWORD *)vertexID - 24) / 0x30u)
                                    + 28),
                      in2: (const matrix3x4_t *)v84,
                      out: (float *)vecTexS);
                    if ( skip_prop > 1 )
                    {
                      if ( *(_DWORD *)(*(_DWORD *)vertexID + 4) != 0
                        && (numVertexes = *(_DWORD *)(*(_DWORD *)vertexID + 4)
                                        + 16
                                        * (badVerts.m_Size
                                         + *(_DWORD *)(vertexID - 36)
                                         + (*(_DWORD *)(*(_DWORD *)vertexID - 20) >> 4))) != 0 )
                      {
                        VectorTransform(
                          in1: (const float *)numVertexes,
                          in2: (const matrix3x4_t *)v84,
                          out: (float *)&v89[48]);
                        samplePosition.x = (float)(*(float *)&v89[56] * *(float *)&vecTexS[4])
                                         - (float)(*(float *)&v89[52] * *(float *)&vecTexS[8]);
                        samplePosition.y = (float)(*(float *)&vecTexS[8] * *(float *)&v89[48])
                                         - (float)(*(float *)&v89[56] * *(float *)vecTexS);
                        samplePosition.z = (float)(*(float *)&v89[52] * *(float *)vecTexS)
                                         - (float)(*(float *)&vecTexS[4] * *(float *)&v89[48]);
                        VectorNormalize(vec: &samplePosition);
                        *(float *)&v89[48] = (float)(samplePosition.y * *(float *)&vecTexS[8])
                                           - (float)(samplePosition.z * *(float *)&vecTexS[4]);
                        *(float *)&v89[56] = (float)(*(float *)&vecTexS[4] * samplePosition.x)
                                           - (float)(samplePosition.y * *(float *)vecTexS);
                        v35 = *(float *)(numVertexes + 12);
                        *(float *)&v89[52] = (float)(samplePosition.z * *(float *)vecTexS)
                                           - (float)(*(float *)&vecTexS[8] * samplePosition.x);
                        samplePosition.x = samplePosition.x * v35;
                        samplePosition.y = samplePosition.y * v35;
                        samplePosition.z = samplePosition.z * v35;
                        GetStaticPropBumpNormals(
                          sVect: (const Vector *)&v89[48],
                          tVect: &samplePosition,
                          flatNormal: (const Vector *)vecTexS,
                          phongNormal: (const Vector *)vecTexS,
                          bumpNormals: (Vector *)&vecTexS[12]);
                      }
                      else
                      {
                        *(_DWORD *)&vecTexS[12] = *(_DWORD *)vecTexS;
                        *(_DWORD *)&vecTexS[16] = *(_DWORD *)&vecTexS[4];
                        *(_DWORD *)&vecTexS[20] = *(_DWORD *)&vecTexS[8];
                        *(_DWORD *)&vecTexS[24] = *(_DWORD *)vecTexS;
                        *(_DWORD *)&vecTexS[28] = *(_DWORD *)&vecTexS[4];
                        *(_QWORD *)&vecTexS[32] = __PAIR64__(*(unsigned int *)vecTexS, *(unsigned int *)&vecTexS[8]);
                        *(_DWORD *)&vecTexS[40] = *(_DWORD *)&vecTexS[4];
                        *(_DWORD *)&vecTexS[44] = *(_DWORD *)&vecTexS[8];
                      }
                    }
                    if ( (dleafs[PointLeafnum(point: (const Vector *)((char *)&midPosition + 8))].contents & 1) != 0 )
                    {
                      v36 = badVerts.m_Memory.m_pMemory;
                      *(_QWORD *)&vecTexS[52] = *((_QWORD *)&midPosition + 1);
                      *(_DWORD *)&vecTexS[60] = pBodyPart;
                      qmemcpy(&vecTexS[64], vecTexS, 48);
                      *(_DWORD *)&vecTexS[48] = badVerts.m_Memory.m_nGrowSize;
                      v37 = badVerts.m_Memory.m_pMemory;
                      numVertexes = (int)badVerts.m_Memory.m_pMemory;
                      if ( (int)&badVerts.m_Memory.m_pMemory->m_ColorVertex + 1 > SLODWORD(bestPosition.z) )
                      {
                        CUtlMemory<colorVertex_t,int>::Grow(
                          this: (CUtlMemory<colorVertex_t,int> *)&bestPosition.y,
                          num: (int)&badVerts.m_Memory.m_pMemory->m_ColorVertex - LODWORD(bestPosition.z) + 1);
                        v36 = badVerts.m_Memory.m_pMemory;
                        v37 = (badVertex_t *)numVertexes;
                      }
                      badVerts.m_Memory.m_pMemory = (badVertex_t *)((char *)&v36->m_ColorVertex + 1);
                      v38 = (char *)v36 - (char *)v37;
                      badVerts.m_Memory.m_nAllocationCount = LODWORD(bestPosition.y);
                      if ( v38 > 0 )
                      {
                        _V_memmove(
                          dest: (void *)(LODWORD(bestPosition.y) + (numVertexes << 6) + 64),
                          src: (const void *)(LODWORD(bestPosition.y) + (numVertexes << 6)),
                          count: v38 << 6);
                        v37 = (badVertex_t *)numVertexes;
                      }
                      v39 = (void *)(LODWORD(bestPosition.y) + ((_DWORD)v37 << 6));
                      if ( v39 != nullptr )
                      {
                        qmemcpy(v39, &vecTexS[48], 64);
                        x = vecTexT.x;
                        v34 = badVerts.m_pElements;
                      }
                    }
                    else
                    {
                      *(_QWORD *)&v86.x = *((_QWORD *)&midPosition + 1);
                      LODWORD(v86.z) = pBodyPart;
                      numVertexes = -1;
                      if ( g_bDisablePropSelfShadowing || SLOBYTE(prop->m_Flags) < 0 )
                        numVertexes = prop_index;
                      memset(dst: v89, value: 0, count: 0x30u);
                      ComputeDirectLightingAtPoint(
                        a1: COERCE_FLOAT(&vertData),
                        position: &v86,
                        normals: (Vector *)vecTexS,
                        outColors: (Vector *)v89,
                        numNormals: skip_prop,
                        iThread,
                        static_prop_id_to_skip: numVertexes,
                        nLFlags: v88);
                      memset(dst: &vecTexS[64], value: 0, count: 0x30u);
                      if ( g_bShowStaticPropNormals )
                      {
                        *(float *)v89 = (float)(*(float *)vecTexS + 1.0) * 50.0;
                        *(float *)&v89[4] = (float)(*(float *)&vecTexS[4] + 1.0) * 50.0;
                        *(float *)&v89[8] = (float)(*(float *)&vecTexS[8] + 1.0) * 50.0;
                        *(float *)&v89[12] = *(float *)v89;
                        *(float *)&v89[16] = *(float *)&v89[4];
                        *(float *)&v89[20] = *(float *)&v89[8];
                        *(float *)&v89[24] = *(float *)v89;
                        *(float *)&v89[28] = *(float *)&v89[4];
                        *(float *)&v89[32] = *(float *)&v89[8];
                        *(float *)&v89[36] = *(float *)v89;
                        *(float *)&v89[40] = *(float *)&v89[4];
                        *(float *)&v89[44] = *(float *)&v89[8];
                      }
                      else if ( numbounce != 0 )
                      {
                        ComputeIndirectLightingAtPoint(
                          position: (Vector *)((char *)&midPosition + 8),
                          normals: (Vector *)vecTexS,
                          outColors: (Vector *)&vecTexS[64],
                          numNormals: skip_prop,
                          iThread,
                          force_fast: true,
                          bIgnoreNormals: (prop->m_Flags & 8) != 0);
                      }
                      *((_BYTE *)&v34->m_Normals[3].z + *(_DWORD *)LODWORD(x)) = 1;
                      v40 = skip_prop;
                      v41 = (int)&v34->m_Normals[2].z + *(_DWORD *)LODWORD(x);
                      *(_QWORD *)v41 = *((_QWORD *)&midPosition + 1);
                      v42 = nullptr;
                      *(_DWORD *)(v41 + 8) = pBodyPart;
                      if ( v40 >= 4 )
                      {
                        numVertexes = ((unsigned int)(v40 - 4) >> 2) + 1;
                        v43 = 0;
                        badVerts.m_pElements = (badVertex_t *)(4 * numVertexes);
                        do
                        {
                          v44 = *(colorVertex_t **)LODWORD(x);
                          v45 = (char *)v34 + v43;
                          *(float *)&v45[(_DWORD)v44] = *(float *)&vecTexS[v43 + 64] + *(float *)&v89[v43];
                          *(float *)&v45[(_DWORD)v44 + 4] = *(float *)&v89[v43 + 4] + *(float *)&vecTexS[v43 + 68];
                          *(float *)&v45[(_DWORD)v44 + 8] = *(float *)&v89[v43 + 8] + *(float *)&vecTexS[v43 + 72];
                          v46 = *(colorVertex_t **)LODWORD(x);
                          *(float *)((char *)&v46->m_Colors[1].x + (_DWORD)v45) = *(float *)&vecTexS[v43 + 76]
                                                                                + *(float *)&v89[v43 + 12];
                          *(float *)((char *)&v46->m_Colors[1].y + (_DWORD)v45) = *(float *)&vecTexS[v43 + 80]
                                                                                + *(float *)&v89[v43 + 16];
                          *(float *)((char *)&v46->m_Colors[1].z + (_DWORD)v45) = *(float *)&vecTexS[v43 + 84]
                                                                                + *(float *)&v89[v43 + 20];
                          v47 = (float *)((char *)&v34->m_Normals[v43 / 0xC].z + *(_DWORD *)LODWORD(x));
                          *v47 = *(float *)&vecTexS[v43 + 88] + *(float *)&v89[v43 + 24];
                          v47[1] = *(float *)&vecTexS[v43 + 92] + *(float *)&v89[v43 + 28];
                          v47[2] = *(float *)&vecTexS[v43 + 96] + *(float *)&v89[v43 + 32];
                          v48 = *(float *)&vecTexS[v43 + 100] + *(float *)&v89[v43 + 36];
                          v49 = (float *)((char *)&v34->m_Normals[v43 / 0xC + 1].z + *(_DWORD *)LODWORD(x));
                          v43 += 48;
                          v50 = numVertexes-- == 1;
                          *v49 = v48;
                          v49[1] = *(float *)&vecTexS[v43 + 56] + *(float *)&direct_pos[v43 + 44];
                          v49[2] = *(float *)&vecTexS[v43 + 60] + *(float *)&v89[v43 - 4];
                        }
                        while ( !v50 );
                        v40 = skip_prop;
                        v42 = badVerts.m_pElements;
                      }
                      if ( (int)v42 < v40 )
                      {
                        v51 = 12 * (_DWORD)v42;
                        v52 = v40 - (_DWORD)v42;
                        do
                        {
                          v53 = *(float *)&vecTexS[v51 + 64] + *(float *)&v89[v51];
                          v54 = (float *)((char *)&v34->m_ColorVertex + v51 + *(_DWORD *)LODWORD(x));
                          v51 += 12;
                          --v52;
                          *v54 = v53;
                          v54[1] = *(float *)&direct_pos[v51 + 44] + *(float *)&vecTexS[v51 + 56];
                          v54[2] = *(float *)&v89[v51 - 4] + *(float *)&vecTexS[v51 + 60];
                        }
                        while ( v52 != 0 );
                        v40 = skip_prop;
                      }
                      if ( v40 > 1 )
                        NormalizeVertexBumpedLighting(
                          pColorNormal: (const Vector *)((char *)v34 + *(_DWORD *)LODWORD(x)),
                          pColorBumps: (Vector *)((char *)&v34->m_Position.z + *(_DWORD *)LODWORD(x)));
                    }
                    ++badVerts.m_Memory.m_nGrowSize;
                    badVerts.m_pElements = ++v34;
                    ++badVerts.m_Size;
                  }
                  while ( badVerts.m_Size < *(_DWORD *)(bodyID + 8) );
                }
                pColorVertsArray = (CUtlVector<colorVertex_t,CUtlMemory<colorVertex_t,int> > *)((char *)pColorVertsArray
                                                                                              + 116);
                ++k;
              }
              while ( k < *(_DWORD *)(LODWORD(bestPosition.x) + 72) );
              if ( badVerts.m_Memory.m_pMemory != nullptr
                && (prop->m_bLightingOriginValid
                 || badVerts.m_Memory.m_pMemory != (badVertex_t *)badVerts.m_Memory.m_nGrowSize)
                && (int)badVerts.m_Memory.m_pMemory > 0 )
              {
                vertexID = LODWORD(bestPosition.y) + 12;
                badVerts.m_pElements = badVerts.m_Memory.m_pMemory;
                do
                {
                  v55 = (float *)vertexID;
                  if ( prop->m_bLightingOriginValid )
                  {
                    v56 = prop->m_LightingOrigin.x;
                    y = prop->m_LightingOrigin.y;
                    z_low = SLODWORD(prop->m_LightingOrigin.z);
                    v99 = v56;
                    pStudioMesh = (mstudiomesh_t *)LODWORD(y);
                  }
                  else
                  {
                    v59 = 3.4028235e38;
                    v60 = 0;
                    v61 = 0;
                    k = 0;
                    if ( badVerts.m_Memory.m_nGrowSize > 0 )
                    {
                      v62 = *(_DWORD *)LODWORD(x) + 56;
                      do
                      {
                        if ( *(_BYTE *)(v62 + 4) != 0 )
                        {
                          v63 = *(float *)(v62 - 8) - *(float *)(vertexID - 8);
                          v64 = (float)((float)((float)(*(float *)(v62 - 4) - *(float *)(vertexID - 4))
                                              * (float)(*(float *)(v62 - 4) - *(float *)(vertexID - 4)))
                                      + (float)((float)(*(float *)v62 - *(float *)vertexID)
                                              * (float)(*(float *)v62 - *(float *)vertexID)))
                              + (float)(v63 * v63);
                          v65 = 0;
                          *(float *)&v65 = fsqrt(v64);
                          matrix_36 = v65;
                          if ( v59 > *(float *)&v65 )
                          {
                            v59 = *(float *)&matrix_36;
                            k = v61;
                          }
                        }
                        ++v61;
                        v62 += 64;
                      }
                      while ( v61 < badVerts.m_Memory.m_nGrowSize );
                      v60 = k;
                    }
                    v66 = v60 << 6;
                    v56 = *(float *)(v66 + *(_DWORD *)LODWORD(x) + 48);
                    v67 = v66 + *(_DWORD *)LODWORD(x) + 48;
                    v99 = v56;
                    y = *(float *)(v67 + 4);
                    pStudioMesh = (mstudiomesh_t *)LODWORD(y);
                    z_low = *(int *)(v67 + 8);
                  }
                  modelID = z_low;
                  for ( k = 19; k > 0; --k )
                  {
                    v91.x = v56 + *(v55 - 2);
                    v91.y = y + *(v55 - 1);
                    v68 = *v55 + *(float *)&z_low;
                    v91.x = v91.x * 0.5;
                    v91.y = v91.y * 0.5;
                    v91.z = v68 * 0.5;
                    if ( (dleafs[PointLeafnum(point: &v91)].contents & 1) != 0 )
                      break;
                    v56 = v91.x;
                    y = v91.y;
                    z_low = SLODWORD(v91.z);
                    v99 = v91.x;
                    pStudioMesh = (mstudiomesh_t *)LODWORD(v91.y);
                    modelID = LODWORD(v91.z);
                  }
                  memset(dst: direct_pos, value: 0, count: sizeof(direct_pos));
                  memset(dst: &vecTexS[64], value: 0, count: 0x30u);
                  v69 = (Vector *)(vertexID + 4);
                  ComputeDirectLightingAtPoint(
                    a1: COERCE_FLOAT(&vertData),
                    position: (Vector *)&v99,
                    normals: (Vector *)(vertexID + 4),
                    outColors: (Vector *)direct_pos,
                    numNormals: skip_prop,
                    iThread,
                    static_prop_id_to_skip: -1,
                    nLFlags: 0);
                  ComputeIndirectLightingAtPoint(
                    position: (Vector *)&v99,
                    normals: v69,
                    outColors: (Vector *)&vecTexS[64],
                    numNormals: skip_prop,
                    iThread,
                    force_fast: true,
                    bIgnoreNormals: false);
                  v70 = *(_DWORD *)(vertexID - 12) << 6;
                  v71 = (float *)(v70 + *(_DWORD *)LODWORD(x) + 48);
                  *v71 = v99;
                  *((_DWORD *)v71 + 1) = pStudioMesh;
                  v72 = 0;
                  v10 = skip_prop < 4;
                  *((_DWORD *)v71 + 2) = modelID;
                  if ( !v10 )
                  {
                    k = ((unsigned int)(skip_prop - 4) >> 2) + 1;
                    v73 = 0;
                    bodyID = 4 * k;
                    do
                    {
                      v74 = *(colorVertex_t **)LODWORD(x);
                      v75 = v73 + v70;
                      *(float *)((char *)&v74->m_Colors[0].x + v75) = *(float *)&vecTexS[v73 + 64]
                                                                    + *(float *)&direct_pos[v73];
                      *(float *)((char *)&v74->m_Colors[0].y + v75) = *(float *)&vecTexS[v73 + 68]
                                                                    + *(float *)&direct_pos[v73 + 4];
                      *(float *)((char *)&v74->m_Colors[0].z + v75) = *(float *)&direct_pos[v73 + 8]
                                                                    + *(float *)&vecTexS[v73 + 72];
                      v76 = *(colorVertex_t **)LODWORD(x);
                      *(float *)((char *)&v76->m_Colors[1].x + v75) = *(float *)&direct_pos[v73 + 12]
                                                                    + *(float *)&vecTexS[v73 + 76];
                      *(float *)((char *)&v76->m_Colors[1].y + v75) = *(float *)&direct_pos[v73 + 16]
                                                                    + *(float *)&vecTexS[v73 + 80];
                      *(float *)((char *)&v76->m_Colors[1].z + v75) = *(float *)&direct_pos[v73 + 20]
                                                                    + *(float *)&vecTexS[v73 + 84];
                      v77 = (float *)(*(_DWORD *)LODWORD(x) + v70 + v73 + 24);
                      *v77 = *(float *)&direct_pos[v73 + 24] + *(float *)&vecTexS[v73 + 88];
                      v77[1] = *(float *)&direct_pos[v73 + 28] + *(float *)&vecTexS[v73 + 92];
                      v77[2] = *(float *)&direct_pos[v73 + 32] + *(float *)&vecTexS[v73 + 96];
                      v78 = *(float *)&direct_pos[v73 + 36] + *(float *)&vecTexS[v73 + 100];
                      v79 = (float *)(*(_DWORD *)LODWORD(x) + v70 + v73 + 36);
                      v73 += 48;
                      v50 = k-- == 1;
                      *v79 = v78;
                      v79[1] = *(float *)((char *)&v86.y + v73) + *(float *)&vecTexS[v73 + 56];
                      v79[2] = *(float *)((char *)&v86.z + v73) + *(float *)&vecTexS[v73 + 60];
                    }
                    while ( !v50 );
                    v72 = bodyID;
                  }
                  if ( v72 < skip_prop )
                  {
                    v80 = 12 * v72;
                    v81 = skip_prop - v72;
                    do
                    {
                      v82 = *(float *)&vecTexS[v80 + 64] + *(float *)&direct_pos[v80];
                      v83 = (float *)(*(_DWORD *)LODWORD(x) + v70 + v80);
                      v80 += 12;
                      --v81;
                      *v83 = v82;
                      v83[1] = *(float *)((char *)&v86.y + v80) + *(float *)&vecTexS[v80 + 56];
                      v83[2] = *(float *)((char *)&v86.z + v80) + *(float *)&vecTexS[v80 + 60];
                    }
                    while ( v81 != 0 );
                  }
                  if ( skip_prop > 1 )
                    NormalizeVertexBumpedLighting(
                      pColorNormal: (const Vector *)(v70 + *(_DWORD *)LODWORD(x)),
                      pColorBumps: (Vector *)(v70 + *(_DWORD *)LODWORD(x) + 12));
                  vertexID += 64;
                  --badVerts.m_pElements;
                }
                while ( badVerts.m_pElements != nullptr );
              }
            }
            badVerts.m_Memory.m_pMemory = nullptr;
            if ( (int)pStudioModel >= 0 )
            {
              if ( LODWORD(bestPosition.y) != 0 )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)LODWORD(bestPosition.y));
                bestPosition.y = 0.0;
              }
              bestPosition.z = 0.0;
            }
            badVerts.m_Memory.m_nAllocationCount = LODWORD(bestPosition.y);
            pStudioHdr = (studiohdr_t *)((char *)pStudioHdr + 1);
          }
          while ( (int)pStudioHdr < *(_DWORD *)(DWORD1(midPosition) + 4) );
        }
        ++LODWORD(vecTexT.y);
        if ( SLODWORD(vecTexT.y) >= *(_DWORD *)(LODWORD(vecTexT.z) + 232) )
          break;
        z = vecTexT.z;
      }
    }
  }
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&bestPosition.y);
}

//------------------------------------------------------------------------------
// Address: 0x1002E2F0
// Name: private: virtual void CVradStaticPropMgr::AddPolysForRayTrace(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVradStaticPropMgr::AddPolysForRayTrace(CVradStaticPropMgr *this)
{
  int m_Size; // eax
  int v2; // edx
  CVradStaticPropMgr::CStaticProp *v3; // eax
  CVradStaticPropMgr::StaticPropDict_t *v4; // esi
  bool v5; // zf
  ICollisionQuery *v6; // esi
  int j; // ebx
  int v8; // edi
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  unsigned int v13; // xmm2_4
  unsigned int v14; // xmm0_4
  studiohdr_t *m_pStudioHdr; // ebx
  OptimizedModel::FileHeader_t *m_pMemory; // edi
  int v17; // eax
  OptimizedModel::BodyPartHeader_t *v18; // esi
  mstudiobodyparts_t *v19; // edx
  int v20; // edi
  OptimizedModel::ModelLODHeader_t *v21; // eax
  mstudiomodel_t *v22; // ebx
  int v23; // esi
  int v24; // edi
  studiohdr_t *v25; // ecx
  char *v26; // esi
  char *v27; // edi
  mstudiomodel_t *v28; // ebx
  OptimizedModel::MeshHeader_t *v29; // edi
  const vertexFileHeader_t *v30; // eax
  int vertexDataStart; // ecx
  char *v32; // ecx
  int tangentDataStart; // ecx
  char *v34; // eax
  char *v35; // eax
  char **v36; // esi
  _DWORD **v37; // ebx
  bool v38; // cc
  int v39; // ecx
  _DWORD *v40; // edi
  OptimizedModel::StripHeader_t *v41; // ecx
  int v42; // edx
  int v43; // eax
  int v44; // ecx
  int v45; // esi
  int v46; // eax
  int v47; // edx
  _DWORD *v48; // esi
  double v49; // st7
  int v50; // ecx
  int v51; // eax
  int v52; // esi
  CShadowTextureList::materialentry_t *v53; // ecx
  int v54; // eax
  int v55; // edx
  Vector2D *uv; // ecx
  float v57; // xmm0_4
  Vector2D *v58; // ecx
  int v59; // edx
  Vector2D *v60; // eax
  int v61; // ecx
  double v62; // st7
  CVradStaticPropMgr::StaticPropDict_t *v63; // esi
  int v64; // ecx
  int m_nAllocationCount; // eax
  int *v66; // edx
  int v67; // eax
  int *v68; // ecx
  const char *name; // eax
  matrix3x4_t matrix; // [esp+Ch] [ebp-16Ch] BYREF
  Vector position1; // [esp+3Ch] [ebp-13Ch] BYREF
  Vector position2; // [esp+48h] [ebp-130h] BYREF
  Vector position3; // [esp+54h] [ebp-124h] BYREF
  Vector fullCoverage; // [esp+60h] [ebp-118h] BYREF
  Vector color; // [esp+6Ch] [ebp-10Ch] BYREF
  CVradStaticPropMgr *v76; // [esp+78h] [ebp-100h]
  OptimizedModel::FileHeader_t *pVtxHdr; // [esp+7Ch] [ebp-FCh]
  CVradStaticPropMgr::CStaticProp *prop; // [esp+80h] [ebp-F8h]
  mstudiobodyparts_t *pBodyPart; // [esp+84h] [ebp-F4h]
  OptimizedModel::StripHeader_t *pStrip; // [esp+88h] [ebp-F0h]
  int count; // [esp+8Ch] [ebp-ECh]
  OptimizedModel::BodyPartHeader_t *pVtxBodyPart; // [esp+90h] [ebp-E8h]
  float coverage; // [esp+94h] [ebp-E4h]
  VMatrix xform; // [esp+98h] [ebp-E0h] BYREF
  matrix3x4_t in2; // [esp+D8h] [ebp-A0h] BYREF
  int bodyID; // [esp+108h] [ebp-70h]
  int v87; // [esp+10Ch] [ebp-6Ch]
  int modelID; // [esp+110h] [ebp-68h]
  int nGroup; // [esp+114h] [ebp-64h]
  int nMesh; // [esp+118h] [ebp-60h]
  OptimizedModel::ModelLODHeader_t *pVtxLOD; // [esp+11Ch] [ebp-5Ch]
  int triangleIndex; // [esp+120h] [ebp-58h]
  int i; // [esp+124h] [ebp-54h]
  mstudiomodel_t *pStudioModel; // [esp+128h] [ebp-50h]
  int nStrip; // [esp+12Ch] [ebp-4Ch]
  int id; // [esp+130h] [ebp-48h]
  int vertex1; // [esp+134h] [ebp-44h]
  CVradStaticPropMgr::StaticPropDict_t *dict; // [esp+138h] [ebp-40h]
  int v99; // [esp+13Ch] [ebp-3Ch]
  unsigned int v100; // [esp+140h] [ebp-38h]
  int v101; // [esp+144h] [ebp-34h]
  int v102; // [esp+148h] [ebp-30h]
  OptimizedModel::MeshHeader_t *pVtxMesh; // [esp+14Ch] [ebp-2Ch]
  studiohdr_t *pStudioHdr; // [esp+150h] [ebp-28h]
  int v105; // [esp+154h] [ebp-24h]
  int v106; // [esp+158h] [ebp-20h]
  int flags; // [esp+15Ch] [ebp-1Ch]
  int nProp; // [esp+160h] [ebp-18h]
  int vertex3; // [esp+164h] [ebp-14h]
  bool bInitTriangles; // [esp+16Bh] [ebp-Dh]
  int vertex2; // [esp+16Ch] [ebp-Ch]
  int materialIndex; // [esp+170h] [ebp-8h]
  int check; // [esp+174h] [ebp-4h]

  m_Size = this->m_StaticProps.m_Size;
  v2 = 0;
  v76 = this;
  count = m_Size;
  if ( m_Size != 0 )
  {
    fullCoverage.x = 1.0;
    nProp = 0;
    if ( m_Size > 0 )
    {
      v100 = 0;
      while ( 1 )
      {
        v3 = &this->m_StaticProps.m_Memory.m_pMemory[v100 / 0x60];
        v4 = &this->m_StaticPropDict.m_Memory.m_pMemory[v3->m_ModelIdx];
        v5 = (v3->m_Flags & 0x10) == 0;
        prop = v3;
        dict = v4;
        if ( !v5 )
          goto LABEL_79;
        if ( g_bStaticPropPolys )
        {
          m_pStudioHdr = v4->m_pStudioHdr;
          m_pMemory = (OptimizedModel::FileHeader_t *)v4->m_VtxBuf.m_Memory.m_pMemory;
          pStudioHdr = m_pStudioHdr;
          pVtxHdr = m_pMemory;
          if ( m_pStudioHdr == nullptr )
          {
            name = "***unknown***";
            goto LABEL_78;
          }
          if ( m_pMemory == nullptr )
          {
            name = m_pStudioHdr->name;
LABEL_78:
            printf(format: "Can't get studio header (%p) and vertex data (%p) for %s\n", m_pStudioHdr, m_pMemory, name);
            goto LABEL_79;
          }
          bInitTriangles = v4->m_triangleMaterialIndex.m_Size == 0;
          triangleIndex = 0;
          AngleMatrix(angles: &v3->m_Angles, position: &v3->m_Origin, &matrix);
          v17 = 0;
          bodyID = 0;
          if ( m_pStudioHdr->numbodyparts > 0 )
          {
            v102 = 0;
            while ( 1 )
            {
              v18 = (OptimizedModel::BodyPartHeader_t *)((char *)m_pMemory + 8 * v17 + m_pMemory->bodyPartOffset);
              v19 = (mstudiobodyparts_t *)((char *)m_pStudioHdr + v102 + m_pStudioHdr->bodypartindex);
              v20 = 0;
              pVtxBodyPart = v18;
              pBodyPart = v19;
              modelID = 0;
              if ( v19->nummodels > 0 )
              {
                v105 = 0;
                do
                {
                  v21 = (OptimizedModel::ModelLODHeader_t *)((char *)&v18[v20]
                                                           + v18->modelOffset
                                                           + *(int *)((char *)&v18[v20].modelOffset + v18->modelOffset));
                  v22 = (mstudiomodel_t *)((char *)v19 + v105 + v19->modelindex);
                  pStudioModel = v22;
                  pVtxLOD = v21;
                  nMesh = 0;
                  if ( v22->nummeshes > 0 )
                  {
                    v101 = 0;
                    v99 = 0;
                    while ( 1 )
                    {
                      v23 = v99 + v22->meshindex;
                      v24 = *(_DWORD *)&v22->name[v23];
                      v25 = pStudioHdr;
                      v26 = &v22->name[v23];
                      v27 = (char *)pStudioHdr + 64 * v24 + pStudioHdr->textureindex;
                      check = 0;
                      if ( g_NonShadowCastingMaterialStrings.m_Size <= 0 )
                      {
LABEL_29:
                        v5 = dict->m_textureShadowIndex.m_Size == 0;
                        check = -1;
                        if ( !v5 )
                          check = dict->m_textureShadowIndex.m_Memory.m_pMemory[*(_DWORD *)v26];
                        v28 = (mstudiomodel_t *)&v26[*((_DWORD *)v26 + 1)];
                        v29 = (OptimizedModel::MeshHeader_t *)((char *)v21 + v101 + v21->meshOffset);
                        pVtxMesh = v29;
                        v30 = mstudiomodel_t::CacheVertexData(this: v28, pModelData: v25);
                        if ( v30 != nullptr )
                        {
                          if ( v30->id == 1448297545 && (vertexDataStart = v30->vertexDataStart) != 0 )
                            v32 = (char *)v30 + vertexDataStart;
                          else
                            v32 = nullptr;
                          v28->vertexdata.pVertexData = v32;
                          if ( v30->id == 1448297545 && (tangentDataStart = v30->tangentDataStart) != 0 )
                            v34 = (char *)v30 + tangentDataStart;
                          else
                            v34 = nullptr;
                          v28->vertexdata.pTangentData = v34;
                        }
                        v35 = &v26[*((_DWORD *)v26 + 1) + 108];
                        v36 = (char **)(v26 + 48);
                        *v36 = v35;
                        v37 = *(_DWORD *)v35 != 0 ? (_DWORD **)v36 : nullptr;
                        v38 = v29->numStripGroups <= 0;
                        nGroup = 0;
                        if ( !v38 )
                        {
                          v106 = 0;
                          while ( 1 )
                          {
                            v39 = 0;
                            v40 = (int *)((char *)&pVtxMesh->numStripGroups + v106 + v29->stripGroupHeaderOffset);
                            nStrip = 0;
                            if ( (int)v40[4] > 0 )
                            {
                              v87 = 0;
                              do
                              {
                                v41 = (OptimizedModel::StripHeader_t *)((char *)v40 + v39 + v40[5]);
                                v42 = 0;
                                pStrip = v41;
                                i = 0;
                                if ( v41->numIndices > 0 )
                                {
                                  id = nProp | 0x4000000;
                                  do
                                  {
                                    v43 = v42 + v41->indexOffset;
                                    v44 = v40[1];
                                    flags = (int)v40 + 2 * v43 + v40[3];
                                    vertex1 = *(unsigned __int16 *)((char *)&v40[2 * *(unsigned __int16 *)flags + 1]
                                                                  + *(unsigned __int16 *)flags
                                                                  + v44);
                                    v45 = *(unsigned __int16 *)((char *)&v40[2 * *(unsigned __int16 *)(flags + 2) + 1]
                                                              + *(unsigned __int16 *)(flags + 2)
                                                              + v44);
                                    v46 = *(unsigned __int16 *)((char *)v40 + 2 * v43 + v40[3] + 4);
                                    v47 = *(unsigned __int16 *)((char *)&v40[2 * v46 + 1] + v46 + v44);
                                    vertex2 = v45;
                                    vertex3 = v47;
                                    AngleMatrix(angles: &prop->m_Angles, position: &prop->m_Origin, matrix: &in2);
                                    VectorTransform(
                                      in1: (const float *)(**v37
                                                    + 48 * ((_DWORD)*(v37 - 9) + *(*v37 - 6) / 0x30u + vertex1)
                                                    + 16),
                                      &in2,
                                      out: &position1.x);
                                    VectorTransform(
                                      in1: (const float *)(**v37 + 48 * ((_DWORD)*(v37 - 9) + *(*v37 - 6) / 0x30u + v45) + 16),
                                      &in2,
                                      out: &position2.x);
                                    VectorTransform(
                                      in1: (const float *)(**v37
                                                    + 48 * ((_DWORD)*(v37 - 9) + *(*v37 - 6) / 0x30u + vertex3)
                                                    + 16),
                                      &in2,
                                      out: &position3.x);
                                    flags = 0;
                                    materialIndex = -1;
                                    color = vec3_origin;
                                    if ( check >= 0 )
                                    {
                                      if ( bInitTriangles )
                                      {
                                        v48 = *v37;
                                        v49 = CShadowTextureList::ComputeCoverageForTriangle(
                                                this: &g_ShadowTextureList,
                                                shadowTextureIndex: check,
                                                t0: (const Vector2D *)(**v37
                                                                 + 48
                                                                 * ((_DWORD)*(v37 - 9) + *(*v37 - 6) / 0x30u + vertex1)
                                                                 + 40),
                                                t1: (const Vector2D *)(*v48
                                                                 + 48
                                                                 * ((_DWORD)*(v37 - 9) + *(v48 - 6) / 0x30u + vertex2)
                                                                 + 40),
                                                t2: (const Vector2D *)(**v37
                                                                 + 48
                                                                 * ((_DWORD)*(v37 - 9) + *(*v37 - 6) / 0x30u + vertex3)
                                                                 + 40));
                                        coverage = v49;
                                        if ( v49 >= 1.0 )
                                        {
                                          materialIndex = -1;
                                        }
                                        else
                                        {
                                          v50 = (int)*(v37 - 9);
                                          materialIndex = *v48 + 48 * (vertex3 + v50 + *(v48 - 6) / 0x30u) + 40;
                                          vertex3 = *v48 + 48 * (vertex2 + v50 + *(v48 - 6) / 0x30u) + 40;
                                          vertex2 = *v48 + 48 * (vertex1 + v50 + *(v48 - 6) / 0x30u) + 40;
                                          v51 = g_ShadowTextureList.m_MaterialEntries.m_Size;
                                          v52 = g_ShadowTextureList.m_MaterialEntries.m_Size;
                                          if ( g_ShadowTextureList.m_MaterialEntries.m_Size + 1 > g_ShadowTextureList.m_MaterialEntries.m_Memory.m_nAllocationCount )
                                          {
                                            CUtlMemory<CVradStaticPropMgr::MeshData_t,int>::Grow(
                                              this: (CUtlMemory<dleafambientlighting_t,int> *)&g_ShadowTextureList.m_MaterialEntries,
                                              num: g_ShadowTextureList.m_MaterialEntries.m_Size
                                            - g_ShadowTextureList.m_MaterialEntries.m_Memory.m_nAllocationCount
                                            + 1);
                                            v51 = g_ShadowTextureList.m_MaterialEntries.m_Size;
                                          }
                                          v53 = g_ShadowTextureList.m_MaterialEntries.m_Memory.m_pMemory;
                                          g_ShadowTextureList.m_MaterialEntries.m_Size = v51 + 1;
                                          v54 = v51 - v52;
                                          g_ShadowTextureList.m_MaterialEntries.m_pElements = g_ShadowTextureList.m_MaterialEntries.m_Memory.m_pMemory;
                                          if ( v54 > 0 )
                                          {
                                            _V_memmove(
                                              dest: &g_ShadowTextureList.m_MaterialEntries.m_Memory.m_pMemory[v52 + 1],
                                              src: &g_ShadowTextureList.m_MaterialEntries.m_Memory.m_pMemory[v52],
                                              count: 28 * v54);
                                            v53 = g_ShadowTextureList.m_MaterialEntries.m_Memory.m_pMemory;
                                          }
                                          v53[v52].textureIndex = check;
                                          v55 = vertex2;
                                          uv = g_ShadowTextureList.m_MaterialEntries.m_Memory.m_pMemory[v52].uv;
                                          uv->x = *(float *)vertex2;
                                          v57 = coverage;
                                          uv->y = *(float *)(v55 + 4);
                                          v58 = &g_ShadowTextureList.m_MaterialEntries.m_Memory.m_pMemory[v52].uv[1];
                                          v59 = vertex3;
                                          v58->x = *(float *)vertex3;
                                          v58->y = *(float *)(v59 + 4);
                                          v60 = &g_ShadowTextureList.m_MaterialEntries.m_Memory.m_pMemory[v52].uv[2];
                                          v61 = materialIndex;
                                          v62 = *(float *)materialIndex;
                                          materialIndex = v52;
                                          v60->x = v62;
                                          v60->y = *(float *)(v61 + 4);
                                          color.x = v57;
                                        }
                                        v63 = dict;
                                        m_nAllocationCount = dict->m_triangleMaterialIndex.m_Memory.m_nAllocationCount;
                                        vertex2 = dict->m_triangleMaterialIndex.m_Size;
                                        v64 = vertex2;
                                        if ( vertex2 + 1 > m_nAllocationCount )
                                        {
                                          CUtlMemory<int,int>::Grow(
                                            this: (CUtlMemory<S3RGBA,int> *)&dict->m_triangleMaterialIndex,
                                            num: vertex2 - m_nAllocationCount + 1);
                                          v64 = vertex2;
                                        }
                                        ++v63->m_triangleMaterialIndex.m_Size;
                                        v66 = v63->m_triangleMaterialIndex.m_Memory.m_pMemory;
                                        v67 = v63->m_triangleMaterialIndex.m_Size - v64 - 1;
                                        v63->m_triangleMaterialIndex.m_pElements = v66;
                                        if ( v67 > 0 )
                                        {
                                          _V_memmove(dest: &v66[v64 + 1], src: &v66[v64], count: 4 * v67);
                                          v64 = vertex2;
                                        }
                                        v68 = &v63->m_triangleMaterialIndex.m_Memory.m_pMemory[v64];
                                        if ( v68 != nullptr )
                                          *v68 = materialIndex;
                                      }
                                      else
                                      {
                                        materialIndex = dict->m_triangleMaterialIndex.m_Memory.m_pMemory[triangleIndex++];
                                      }
                                      if ( materialIndex >= 0 )
                                        flags = 1;
                                    }
                                    RayTracingEnvironment::AddTriangle(
                                      this: &g_RtEnv,
                                      id,
                                      v1: &position1,
                                      v2: &position2,
                                      v3: &position3,
                                      &color,
                                      flags,
                                      materialIndex);
                                    v41 = pStrip;
                                    v42 = i + 3;
                                    i = v42;
                                  }
                                  while ( v42 < pStrip->numIndices );
                                }
                                v39 = v87 + 35;
                                ++nStrip;
                                v87 += 35;
                              }
                              while ( nStrip < v40[4] );
                            }
                            v106 += 33;
                            if ( ++nGroup >= pVtxMesh->numStripGroups )
                              break;
                            v29 = pVtxMesh;
                          }
                        }
                        v22 = pStudioModel;
                      }
                      else
                      {
                        while ( V_stristr(
                                  pStr: &v27[*(_DWORD *)v27],
                                  pSearch: g_NonShadowCastingMaterialStrings.m_Memory.m_pMemory[check]) == nullptr )
                        {
                          if ( ++check >= g_NonShadowCastingMaterialStrings.m_Size )
                          {
                            v25 = pStudioHdr;
                            v21 = pVtxLOD;
                            goto LABEL_29;
                          }
                        }
                      }
                      v99 += 116;
                      v101 += 9;
                      if ( ++nMesh >= v22->nummeshes )
                        break;
                      v21 = pVtxLOD;
                    }
                    v19 = pBodyPart;
                    v18 = pVtxBodyPart;
                    v20 = modelID;
                  }
                  v105 += 148;
                  modelID = ++v20;
                }
                while ( v20 < v19->nummodels );
                m_pStudioHdr = pStudioHdr;
                v17 = bodyID;
              }
              v102 += 16;
              bodyID = ++v17;
              if ( v17 >= m_pStudioHdr->numbodyparts )
                break;
              m_pMemory = pVtxHdr;
            }
          }
        }
        else if ( v4->m_pModel != nullptr )
        {
          VMatrix::SetupMatrixOrgAngles(this: &xform, origin: &v3->m_Origin, vAngles: &v3->m_Angles);
          v6 = s_pPhysCollision->CreateQueryModel(this: s_pPhysCollision, a2: v4->m_pModel);
          for ( j = 0; j < v6->ConvexCount(this: v6); ++j )
          {
            v8 = 0;
            if ( v6->TriangleCount(this: v6, a2: j) > 0 )
            {
              id = nProp | 0x4000000;
              do
              {
                v6->GetTriangleVerts(this: v6, a2: j, a3: v8, a4: (Vector *)&in2.m_flMatVal[0][3]);
                v9 = (float)((float)((float)(in2.m_flMatVal[1][0] * xform.m[0][1])
                                   + (float)(in2.m_flMatVal[0][3] * xform.m[0][0]))
                           + (float)(in2.m_flMatVal[1][1] * xform.m[0][2]))
                   + xform.m[0][3];
                v10 = (float)((float)((float)(in2.m_flMatVal[1][0] * xform.m[2][1])
                                    + (float)(in2.m_flMatVal[0][3] * xform.m[2][0]))
                            + (float)(in2.m_flMatVal[1][1] * xform.m[2][2]))
                    + xform.m[2][3];
                in2.m_flMatVal[1][0] = (float)((float)((float)(in2.m_flMatVal[1][0] * xform.m[1][1])
                                                     + (float)(in2.m_flMatVal[0][3] * xform.m[1][0]))
                                             + (float)(in2.m_flMatVal[1][1] * xform.m[1][2]))
                                     + xform.m[1][3];
                in2.m_flMatVal[0][3] = v9;
                in2.m_flMatVal[1][1] = v10;
                v11 = (float)((float)((float)(in2.m_flMatVal[1][3] * xform.m[1][1])
                                    + (float)(in2.m_flMatVal[1][2] * xform.m[1][0]))
                            + (float)(in2.m_flMatVal[2][0] * xform.m[1][2]))
                    + xform.m[1][3];
                v12 = (float)((float)((float)(in2.m_flMatVal[1][3] * xform.m[2][1])
                                    + (float)(in2.m_flMatVal[1][2] * xform.m[2][0]))
                            + (float)(in2.m_flMatVal[2][0] * xform.m[2][2]))
                    + xform.m[2][3];
                in2.m_flMatVal[1][2] = (float)((float)((float)(in2.m_flMatVal[1][3] * xform.m[0][1])
                                                     + (float)(in2.m_flMatVal[1][2] * xform.m[0][0]))
                                             + (float)(in2.m_flMatVal[2][0] * xform.m[0][2]))
                                     + xform.m[0][3];
                in2.m_flMatVal[1][3] = v11;
                in2.m_flMatVal[2][0] = v12;
                *(float *)&v13 = (float)((float)((float)(in2.m_flMatVal[2][2] * xform.m[1][1])
                                               + (float)(in2.m_flMatVal[2][1] * xform.m[1][0]))
                                       + (float)(in2.m_flMatVal[2][3] * xform.m[1][2]))
                               + xform.m[1][3];
                *(float *)&v14 = (float)((float)((float)(in2.m_flMatVal[2][2] * xform.m[2][1])
                                               + (float)(in2.m_flMatVal[2][1] * xform.m[2][0]))
                                       + (float)(in2.m_flMatVal[2][3] * xform.m[2][2]))
                               + xform.m[2][3];
                in2.m_flMatVal[2][1] = (float)((float)((float)(in2.m_flMatVal[2][2] * xform.m[0][1])
                                                     + (float)(in2.m_flMatVal[2][1] * xform.m[0][0]))
                                             + (float)(in2.m_flMatVal[2][3] * xform.m[0][2]))
                                     + xform.m[0][3];
                *(_QWORD *)&in2.m_flMatVal[2][2] = __PAIR64__(v14, v13);
                RayTracingEnvironment::AddTriangle(
                  this: &g_RtEnv,
                  id,
                  v1: (const Vector *)&in2.m_flMatVal[0][3],
                  v2: (const Vector *)&in2.m_flMatVal[1][2],
                  v3: (const Vector *)&in2.m_flMatVal[2][1],
                  color: &fullCoverage);
                ++v8;
              }
              while ( v8 < v6->TriangleCount(this: v6, a2: j) );
            }
          }
          s_pPhysCollision->DestroyQueryModel(this: s_pPhysCollision, a2: v6);
        }
        else
        {
          v3->m_mins.x = v3->m_Origin.x + v4->m_Mins.x;
          v3->m_mins.y = v4->m_Mins.y + v3->m_Origin.y;
          v3->m_mins.z = v4->m_Mins.z + v3->m_Origin.z;
          v3->m_maxs.x = v3->m_Origin.x + v4->m_Maxs.x;
          v3->m_maxs.y = v4->m_Maxs.y + v3->m_Origin.y;
          v3->m_maxs.z = v4->m_Maxs.z + v3->m_Origin.z;
          RayTracingEnvironment::AddAxisAlignedRectangularSolid(
            this: &g_RtEnv,
            id: v2 | 0x4000000,
            minc: v3->m_mins,
            maxc: v3->m_maxs,
            color: &fullCoverage);
        }
LABEL_79:
        v100 += 96;
        v2 = nProp + 1;
        nProp = v2;
        if ( v2 >= count )
          return;
        this = v76;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EF50
// Name: public: void CUtlDict<struct CShadowTextureList::alphatexture_t,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CShadowTextureList::alphatexture_t,unsigned short>::RemoveAll(
        CUtlDict<CShadowTextureList::alphatexture_t,unsigned short> *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,CShadowTextureList::alphatexture_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CShadowTextureList::alphatexture_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CShadowTextureList::alphatexture_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,CShadowTextureList::alphatexture_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CShadowTextureList::alphatexture_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CShadowTextureList::alphatexture_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CShadowTextureList::alphatexture_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CShadowTextureList::alphatexture_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CShadowTextureList::alphatexture_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1002EFB0
// Name: private: void CVradStaticPropMgr::VMPI_ProcessStaticProp(int,int,class MessageBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVradStaticPropMgr::VMPI_ProcessStaticProp(
        CVradStaticPropMgr *this,
        int iThread,
        int iStaticProp,
        MessageBuffer *pBuf)
{
  int v4; // edi
  MessageBuffer *v5; // ebx
  CUtlVector<colorVertex_t,CUtlMemory<colorVertex_t,int> > *v6; // esi
  CVradStaticPropMgr::CStaticProp *v7; // [esp-10h] [ebp-2Ch]
  CComputeStaticPropLightingResults results; // [esp+8h] [ebp-14h] BYREF
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  v4 = 0;
  v7 = &this->m_StaticProps.m_Memory.m_pMemory[iStaticProp];
  memset(&results, 0, sizeof(results));
  CVradStaticPropMgr::ComputeLighting(
    this,
    a2: (const mstudio_meshvertexdata_t *)&savedregs,
    prop: v7,
    iThread,
    prop_index: iStaticProp,
    pResults: &results);
  VMPI_SetCurrentStage(pCurStage: "EncodeLightingResults");
  v5 = pBuf;
  iStaticProp = results.m_ColorVertsArrays.m_Size;
  MessageBuffer::write(this: pBuf, p: &iStaticProp, bytes: 4);
  if ( iStaticProp > 0 )
  {
    do
    {
      v6 = results.m_ColorVertsArrays.m_Memory.m_pMemory[v4];
      iThread = v6->m_Size;
      MessageBuffer::write(this: v5, p: &iThread, bytes: 4);
      MessageBuffer::write(this: v5, p: v6->m_Memory.m_pMemory, bytes: v6->m_Size << 6);
      ++v4;
    }
    while ( v4 < iStaticProp );
  }
  CUtlVector<CUtlVector<colorVertex_t,CUtlMemory<colorVertex_t,int>> *,CUtlMemory<CUtlVector<colorVertex_t,CUtlMemory<colorVertex_t,int>> *,int>>::PurgeAndDeleteElements(this: &results.m_ColorVertsArrays);
  if ( results.m_ColorVertsArrays.m_Memory.m_nGrowSize >= 0 && results.m_ColorVertsArrays.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: results.m_ColorVertsArrays.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1002F200
// Name: private: static void CVradStaticPropMgr::VMPI_ProcessStaticProp_Static(int,unsigned __int64,class MessageBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CVradStaticPropMgr::VMPI_ProcessStaticProp_Static(
        int iThread,
        unsigned __int64 iStaticProp,
        MessageBuffer *pBuf)
{
  CVradStaticPropMgr::VMPI_ProcessStaticProp(this: &g_StaticPropMgr, iThread, iStaticProp, pBuf);
}

//------------------------------------------------------------------------------
// Address: 0x1002F2C0
// Name: private: void CVradStaticPropMgr::ApplyLightingToStaticProp(struct CVradStaticPropMgr::CStaticProp __near &,class CComputeStaticPropLightingResults const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVradStaticPropMgr::ApplyLightingToStaticProp(
        CVradStaticPropMgr *this,
        CVradStaticPropMgr::CStaticProp *prop,
        const CComputeStaticPropLightingResults *pResults)
{
  int v3; // ebx
  CVradStaticPropMgr::StaticPropDict_t *v4; // eax
  studiohdr_t *m_pStudioHdr; // esi
  OptimizedModel::FileHeader_t *m_pMemory; // ecx
  int v7; // edx
  int v8; // edi
  OptimizedModel::BodyPartHeader_t *v9; // eax
  int v10; // ecx
  int v11; // esi
  int v12; // ecx
  OptimizedModel::ModelHeader_t *v13; // esi
  OptimizedModel::ModelLODHeader_t *v14; // edx
  int *p_numStripGroups; // eax
  int m_Size; // esi
  OptimizedModel::StripGroupHeader_t *v17; // ecx
  int m_nAllocationCount; // eax
  CVradStaticPropMgr::MeshData_t *v19; // ecx
  int v20; // eax
  int v21; // ebx
  CVradStaticPropMgr::MeshData_t *v22; // eax
  int v23; // eax
  CVradStaticPropMgr::MeshData_t *v24; // esi
  int v25; // edx
  CUtlMemory<CVTFTexture::ResourceMemorySection,int> *v26; // esi
  int v27; // ecx
  int v28; // edx
  CVTFTexture::ResourceMemorySection *v29; // edx
  CVTFTexture::ResourceMemorySection *v30; // ecx
  int v31; // ecx
  OptimizedModel::StripGroupHeader_t *v32; // edx
  int v33; // esi
  int v34; // eax
  float *v35; // eax
  Vector *v36; // ecx
  int v37; // ecx
  int v38; // esi
  int v39; // eax
  int v40; // edx
  int v41; // eax
  Vector *v42; // ecx
  Vector *v43; // ecx
  int v44; // ecx
  Vector *v45; // ecx
  int v46; // ecx
  float *v47; // ecx
  bool v48; // zf
  int v49; // edx
  int v50; // esi
  int p_z; // ecx
  Vector *v52; // eax
  studiohdr_t *pStudioHdr; // [esp+4h] [ebp-84h]
  mstudiomodel_t *pStudioModel; // [esp+8h] [ebp-80h]
  int iCurColorVertsArray; // [esp+Ch] [ebp-7Ch]
  mstudiomesh_t *pMesh; // [esp+10h] [ebp-78h]
  OptimizedModel::BodyPartHeader_t *pVtxBodyPart; // [esp+14h] [ebp-74h]
  OptimizedModel::ModelLODHeader_t *pVtxLOD; // [esp+18h] [ebp-70h]
  mstudiobodyparts_t *pBodyPart; // [esp+1Ch] [ebp-6Ch]
  int nIndex; // [esp+20h] [ebp-68h]
  OptimizedModel::ModelHeader_t *pVtxModel; // [esp+24h] [ebp-64h]
  int bodyID; // [esp+2Ch] [ebp-5Ch]
  int nGroup; // [esp+30h] [ebp-58h]
  int modelID; // [esp+34h] [ebp-54h]
  int nMesh; // [esp+38h] [ebp-50h]
  OptimizedModel::MeshHeader_t *pVtxMesh; // [esp+3Ch] [ebp-4Ch]
  int v67; // [esp+40h] [ebp-48h]
  int k; // [esp+44h] [ebp-44h]
  int v69; // [esp+48h] [ebp-40h]
  int v70; // [esp+4Ch] [ebp-3Ch]
  int v71; // [esp+50h] [ebp-38h]
  int v72; // [esp+54h] [ebp-34h]
  OptimizedModel::FileHeader_t *pVtxHdr; // [esp+58h] [ebp-30h]
  int v74; // [esp+5Ch] [ebp-2Ch]
  int v75; // [esp+60h] [ebp-28h]
  const CUtlVector<colorVertex_t,CUtlMemory<colorVertex_t,int> > *colorVerts; // [esp+64h] [ebp-24h]
  int nLod; // [esp+68h] [ebp-20h]
  int v78; // [esp+6Ch] [ebp-1Ch]
  int v79; // [esp+70h] [ebp-18h]
  int v80; // [esp+74h] [ebp-14h]
  unsigned int v81; // [esp+74h] [ebp-14h]
  OptimizedModel::StripGroupHeader_t *pStripGroup; // [esp+78h] [ebp-10h]
  int numVertexLightComponents; // [esp+7Ch] [ebp-Ch]
  int v84; // [esp+80h] [ebp-8h]
  int v85; // [esp+80h] [ebp-8h]
  int nVertex; // [esp+84h] [ebp-4h]
  int nVertexa; // [esp+84h] [ebp-4h]

  v3 = 0;
  if ( pResults->m_ColorVertsArrays.m_Size == 0 )
    return;
  v4 = &this->m_StaticPropDict.m_Memory.m_pMemory[prop->m_ModelIdx];
  m_pStudioHdr = v4->m_pStudioHdr;
  m_pMemory = (OptimizedModel::FileHeader_t *)v4->m_VtxBuf.m_Memory.m_pMemory;
  v7 = 0;
  pStudioHdr = m_pStudioHdr;
  pVtxHdr = m_pMemory;
  numVertexLightComponents = g_numVradStaticPropsLightingStreams;
  bodyID = 0;
  if ( m_pStudioHdr->numbodyparts <= 0 )
    return;
  v79 = 0;
  while ( 1 )
  {
    v8 = (int)m_pStudioHdr + v79 + m_pStudioHdr->bodypartindex;
    v9 = (OptimizedModel::BodyPartHeader_t *)((char *)m_pMemory + 8 * v3 + m_pMemory->bodyPartOffset);
    v10 = 0;
    pVtxBodyPart = v9;
    pBodyPart = (mstudiobodyparts_t *)v8;
    modelID = 0;
    if ( *(int *)(v8 + 4) <= 0 )
      goto LABEL_48;
    v71 = 0;
    do
    {
      v11 = v9->modelOffset + 8 * v10;
      v12 = *(_DWORD *)(v8 + 12) + v8 + v71;
      colorVerts = pResults->m_ColorVertsArrays.m_Memory.m_pMemory[v7];
      v13 = (OptimizedModel::ModelHeader_t *)((char *)v9 + v11);
      ++v7;
      pVtxModel = v13;
      pStudioModel = (mstudiomodel_t *)v12;
      iCurColorVertsArray = v7;
      nLod = 0;
      if ( pVtxHdr->numLODs <= 0 )
        goto LABEL_46;
      v75 = 0;
      do
      {
        v14 = (OptimizedModel::ModelLODHeader_t *)((char *)v13 + v75 + v13->lodOffset);
        pVtxLOD = v14;
        nMesh = 0;
        if ( *(int *)(v12 + 72) <= 0 )
          goto LABEL_44;
        v78 = 0;
        v70 = 0;
        do
        {
          pMesh = (mstudiomesh_t *)(v12 + v70 + *(_DWORD *)(v12 + 76));
          nGroup = 0;
          p_numStripGroups = (int *)((char *)&v14->numMeshes + v78 + v14->meshOffset);
          pVtxMesh = (OptimizedModel::MeshHeader_t *)p_numStripGroups;
          if ( *p_numStripGroups <= 0 )
            goto LABEL_42;
          v74 = 0;
          while ( 1 )
          {
            m_Size = prop->m_MeshData.m_Size;
            v17 = (OptimizedModel::StripGroupHeader_t *)((char *)p_numStripGroups + v74 + p_numStripGroups[1]);
            m_nAllocationCount = prop->m_MeshData.m_Memory.m_nAllocationCount;
            pStripGroup = v17;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<CVradStaticPropMgr::MeshData_t,int>::Grow(
                this: (CUtlMemory<dleafambientlighting_t,int> *)&prop->m_MeshData,
                num: m_Size - m_nAllocationCount + 1);
            ++prop->m_MeshData.m_Size;
            v19 = prop->m_MeshData.m_Memory.m_pMemory;
            v20 = prop->m_MeshData.m_Size - m_Size - 1;
            prop->m_MeshData.m_pElements = v19;
            if ( v20 > 0 )
              _V_memmove(dest: &v19[m_Size + 1], src: &v19[m_Size], count: 28 * v20);
            v21 = m_Size;
            v22 = &prop->m_MeshData.m_Memory.m_pMemory[m_Size];
            if ( v22 != nullptr )
            {
              v22->m_VertColorData.m_Memory.m_pMemory = nullptr;
              v22->m_VertColorData.m_Memory.m_nAllocationCount = 0;
              v22->m_VertColorData.m_Memory.m_nGrowSize = 0;
              v22->m_VertColorData.m_Size = 0;
              v22->m_VertColorData.m_pElements = nullptr;
            }
            v23 = numVertexLightComponents * pStripGroup->numVerts;
            v24 = prop->m_MeshData.m_Memory.m_pMemory;
            v25 = v24[v21].m_VertColorData.m_Size;
            v26 = (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&v24[v21];
            v80 = v23;
            nVertex = v25;
            if ( v23 != 0 )
            {
              v27 = v25 + v23;
              v28 = v26->m_nAllocationCount;
              v84 = v27;
              if ( v27 > v28 )
              {
                CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>::Grow(
                  this: v26,
                  num: v23 + nVertex - v28);
                v23 = v80;
              }
              v26[1].m_pMemory = (CVTFTexture::ResourceMemorySection *)((char *)v26[1].m_pMemory + v23);
              v29 = v26->m_pMemory;
              v30 = v26[1].m_pMemory;
              v26[1].m_nAllocationCount = (int)v26->m_pMemory;
              v31 = (int)v30 - nVertex - v23;
              if ( v31 > 0 && v23 > 0 )
                _V_memmove(dest: &v29[v84], src: &v29[nVertex], count: 12 * v31);
            }
            v32 = pStripGroup;
            prop->m_MeshData.m_Memory.m_pMemory[v21].m_numVerts = pStripGroup->numVerts;
            prop->m_MeshData.m_Memory.m_pMemory[v21].m_nLod = nLod;
            nVertexa = 0;
            if ( pStripGroup->numVerts > 0 )
            {
              v33 = numVertexLightComponents;
              v72 = 0;
              v67 = 0;
              v69 = 0;
              v85 = 0;
              do
              {
                v34 = pMesh->vertexoffset + *(unsigned __int16 *)((char *)&v32->vertOffset + v69 + v32->vertOffset);
                nIndex = v34;
                if ( v33 > 1 )
                {
                  v37 = 0;
                  k = 0;
                  if ( v33 >= 4 )
                  {
                    v38 = v85;
                    v39 = (int)&colorVerts->m_Memory.m_pMemory[v34];
                    v81 = ((unsigned int)(numVertexLightComponents - 4) >> 2) + 1;
                    v40 = v39 + 24;
                    v41 = v39 + 20;
                    k = 4 * v81;
                    do
                    {
                      v42 = prop->m_MeshData.m_Memory.m_pMemory[v21].m_VertColorData.m_Memory.m_pMemory;
                      *(float *)((char *)&v42->x + v38) = *(float *)(v40 - 12);
                      v41 += 48;
                      v40 += 48;
                      *(float *)((char *)&v42->y + v38) = *(float *)(v41 - 52);
                      *(float *)((char *)&v42->z + v38) = *(float *)(v41 - 48);
                      v43 = prop->m_MeshData.m_Memory.m_pMemory[v21].m_VertColorData.m_Memory.m_pMemory;
                      *(float *)((char *)&v43[1].x + v38) = *(float *)(v40 - 48);
                      v44 = (int)&v43[1] + v38;
                      *(float *)(v44 + 4) = *(float *)(v41 - 40);
                      *(float *)(v44 + 8) = *(float *)(v41 - 36);
                      v45 = prop->m_MeshData.m_Memory.m_pMemory[v21].m_VertColorData.m_Memory.m_pMemory;
                      *(float *)((char *)&v45[2].x + v38) = *(float *)(v40 - 36);
                      v46 = (int)&v45[2] + v38;
                      *(float *)(v46 + 4) = *(float *)(v41 - 28);
                      *(float *)(v46 + 8) = *(float *)(v41 - 24);
                      v47 = (float *)((char *)&prop->m_MeshData.m_Memory.m_pMemory[v21].m_VertColorData.m_Memory.m_pMemory[3].x
                                    + v38);
                      *v47 = *(float *)(v40 - 24);
                      v38 += 48;
                      v48 = v81-- == 1;
                      v47[1] = *(float *)(v41 - 16);
                      v47[2] = *(float *)(v41 - 12);
                    }
                    while ( !v48 );
                    v37 = k;
                    v34 = nIndex;
                    v32 = pStripGroup;
                    v33 = numVertexLightComponents;
                  }
                  if ( v37 >= v33 )
                    goto LABEL_39;
                  v49 = v37 + v72;
                  v50 = v33 - k;
                  p_z = (int)&colorVerts->m_Memory.m_pMemory[v34].m_Colors[v37 + 1].z;
                  do
                  {
                    v52 = prop->m_MeshData.m_Memory.m_pMemory[v21].m_VertColorData.m_Memory.m_pMemory;
                    v52[v49].x = *(float *)(p_z - 8);
                    p_z += 12;
                    ++v49;
                    --v50;
                    v52[v49 - 1].y = *(float *)(p_z - 16);
                    v52[v49 - 1].z = *(float *)(p_z - 12);
                  }
                  while ( v50 != 0 );
                  v33 = numVertexLightComponents;
                }
                else
                {
                  v35 = (float *)&colorVerts->m_Memory.m_pMemory[v34];
                  v36 = &prop->m_MeshData.m_Memory.m_pMemory[v21].m_VertColorData.m_Memory.m_pMemory[v67];
                  v36->x = *v35;
                  v36->y = v35[1];
                  v36->z = v35[2];
                }
                v32 = pStripGroup;
LABEL_39:
                ++nVertexa;
                v69 += 9;
                ++v67;
                v72 += v33;
                v85 += 12 * numVertexLightComponents;
              }
              while ( nVertexa < v32->numVerts );
            }
            v74 += 33;
            if ( ++nGroup >= pVtxMesh->numStripGroups )
              break;
            p_numStripGroups = &pVtxMesh->numStripGroups;
          }
          v14 = pVtxLOD;
          v12 = (int)pStudioModel;
          v13 = pVtxModel;
          v8 = (int)pBodyPart;
LABEL_42:
          v70 += 116;
          v78 += 9;
          ++nMesh;
        }
        while ( nMesh < *(_DWORD *)(v12 + 72) );
        v9 = pVtxBodyPart;
LABEL_44:
        v75 += 12;
        ++nLod;
      }
      while ( nLod < pVtxHdr->numLODs );
      v7 = iCurColorVertsArray;
LABEL_46:
      v71 += 148;
      v10 = modelID + 1;
      modelID = v10;
    }
    while ( v10 < *(_DWORD *)(v8 + 4) );
    v3 = bodyID;
    m_pStudioHdr = pStudioHdr;
LABEL_48:
    v79 += 16;
    bodyID = ++v3;
    if ( v3 >= m_pStudioHdr->numbodyparts )
      break;
    m_pMemory = pVtxHdr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F710
// Name: private: void CVradStaticPropMgr::VMPI_ReceiveStaticPropResults(int,class MessageBuffer __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVradStaticPropMgr::VMPI_ReceiveStaticPropResults(
        CVradStaticPropMgr *this,
        int iStaticProp,
        MessageBuffer *pBuf,
        int iWorker)
{
  CUtlMemory<colorVertex_t,int> *v4; // edi
  CVradStaticPropMgr *v5; // esi
  int m_Size; // ebx
  CUtlMemory<colorVertex_t,int> *v7; // eax
  int v8; // esi
  CUtlVector<colorVertex_t,CUtlMemory<colorVertex_t,int> > **m_pMemory; // ecx
  CUtlMemory<colorVertex_t,int> **v10; // eax
  int v11; // esi
  int m_nAllocationCount; // eax
  colorVertex_t *v13; // ecx
  int v14; // eax
  CComputeStaticPropLightingResults results; // [esp+Ch] [ebp-24h] BYREF
  CVradStaticPropMgr *v16; // [esp+20h] [ebp-10h]
  int nLists; // [esp+24h] [ebp-Ch] BYREF
  int i; // [esp+28h] [ebp-8h]
  int count; // [esp+2Ch] [ebp-4h] BYREF

  v4 = nullptr;
  v5 = this;
  m_Size = 0;
  v16 = this;
  memset(&results, 0, sizeof(results));
  MessageBuffer::read(this: pBuf, p: &nLists, bytes: 4);
  i = 0;
  if ( nLists > 0 )
  {
    do
    {
      v7 = (CUtlMemory<colorVertex_t,int> *)MemAlloc_Alloc(nSize: 0x14u);
      if ( v7 != nullptr )
      {
        v7->m_pMemory = nullptr;
        v7->m_nAllocationCount = 0;
        v7->m_nGrowSize = 0;
        v7[1].m_pMemory = nullptr;
        v7[1].m_nAllocationCount = 0;
        v4 = v7;
      }
      v8 = m_Size;
      if ( m_Size + 1 > results.m_ColorVertsArrays.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<int,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&results,
          num: m_Size - results.m_ColorVertsArrays.m_Memory.m_nAllocationCount + 1);
        m_Size = results.m_ColorVertsArrays.m_Size;
      }
      m_pMemory = results.m_ColorVertsArrays.m_Memory.m_pMemory;
      results.m_ColorVertsArrays.m_Size = ++m_Size;
      results.m_ColorVertsArrays.m_pElements = results.m_ColorVertsArrays.m_Memory.m_pMemory;
      if ( m_Size - v8 - 1 > 0 )
      {
        _V_memmove(
          dest: &results.m_ColorVertsArrays.m_Memory.m_pMemory[v8 + 1],
          src: &results.m_ColorVertsArrays.m_Memory.m_pMemory[v8],
          count: 4 * (m_Size - v8 - 1));
        m_pMemory = results.m_ColorVertsArrays.m_Memory.m_pMemory;
      }
      v10 = (CUtlMemory<colorVertex_t,int> **)&m_pMemory[v8];
      if ( v10 != nullptr )
        *v10 = v4;
      MessageBuffer::read(this: pBuf, p: &count, bytes: 4);
      v11 = count;
      v4[1].m_pMemory = nullptr;
      if ( v11 != 0 )
      {
        m_nAllocationCount = v4->m_nAllocationCount;
        if ( v11 > m_nAllocationCount )
          CUtlMemory<colorVertex_t,int>::Grow(this: v4, num: v11 - m_nAllocationCount);
        v4[1].m_pMemory = (colorVertex_t *)((char *)v4[1].m_pMemory + v11);
        v13 = v4->m_pMemory;
        v14 = (int)v4[1].m_pMemory - v11;
        v4[1].m_nAllocationCount = (int)v4->m_pMemory;
        if ( v14 > 0 && v11 > 0 )
          _V_memmove(dest: &v13[v11], src: v13, count: v14 << 6);
      }
      MessageBuffer::read(this: pBuf, p: v4->m_pMemory, bytes: count << 6);
      v4 = nullptr;
      ++i;
    }
    while ( i < nLists );
    v5 = v16;
  }
  CVradStaticPropMgr::ApplyLightingToStaticProp(
    this: v5,
    prop: &v5->m_StaticProps.m_Memory.m_pMemory[iStaticProp],
    pResults: &results);
  CUtlVector<CUtlVector<colorVertex_t,CUtlMemory<colorVertex_t,int>> *,CUtlMemory<CUtlVector<colorVertex_t,CUtlMemory<colorVertex_t,int>> *,int>>::PurgeAndDeleteElements(this: &results.m_ColorVertsArrays);
  if ( results.m_ColorVertsArrays.m_Memory.m_nGrowSize >= 0 && results.m_ColorVertsArrays.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: results.m_ColorVertsArrays.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1002F890
// Name: private: static void CVradStaticPropMgr::ThreadComputeStaticPropLighting(int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CVradStaticPropMgr::ThreadComputeStaticPropLighting(int iThread)
{
  int i; // eax
  int v2; // esi
  CComputeStaticPropLightingResults results; // [esp+0h] [ebp-28h] BYREF
  CComputeStaticPropLightingResults pResults; // [esp+14h] [ebp-14h] BYREF
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  for ( i = GetThreadWork(); i != -1; i = GetThreadWork() )
  {
    v2 = i;
    memset(&results, 0, sizeof(results));
    memset(&pResults, 0, sizeof(pResults));
    CVradStaticPropMgr::ComputeLighting(
      this: &g_StaticPropMgr,
      a2: (const mstudio_meshvertexdata_t *)&savedregs,
      prop: &g_StaticPropMgr.m_StaticProps.m_Memory.m_pMemory[i],
      iThread,
      prop_index: i,
      &pResults);
    CVradStaticPropMgr::ApplyLightingToStaticProp(
      this: &g_StaticPropMgr,
      prop: &g_StaticPropMgr.m_StaticProps.m_Memory.m_pMemory[v2],
      &pResults);
    CUtlVector<CUtlVector<colorVertex_t,CUtlMemory<colorVertex_t,int>> *,CUtlMemory<CUtlVector<colorVertex_t,CUtlMemory<colorVertex_t,int>> *,int>>::PurgeAndDeleteElements(this: &pResults.m_ColorVertsArrays);
    if ( pResults.m_ColorVertsArrays.m_Memory.m_nGrowSize >= 0
      && pResults.m_ColorVertsArrays.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pResults.m_ColorVertsArrays.m_Memory.m_pMemory);
    }
    CUtlVector<CUtlVector<colorVertex_t,CUtlMemory<colorVertex_t,int>> *,CUtlMemory<CUtlVector<colorVertex_t,CUtlMemory<colorVertex_t,int>> *,int>>::PurgeAndDeleteElements(this: &results.m_ColorVertsArrays);
    if ( results.m_ColorVertsArrays.m_Memory.m_nGrowSize >= 0
      && results.m_ColorVertsArrays.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: results.m_ColorVertsArrays.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F9C0
// Name: public: unsigned short CUtlDict<struct CShadowTextureList::alphatexture_t,unsigned short>::Insert(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlDict<CShadowTextureList::alphatexture_t,unsigned short>::Insert(
        CUtlDict<CShadowTextureList::alphatexture_t,unsigned short> *this,
        const char *pName)
{
  char *v3; // eax
  CUtlMap<char const *,CShadowTextureList::alphatexture_t,unsigned short>::Node_t insert; // [esp+8h] [ebp-10h] BYREF

  if ( pName != nullptr && (v3 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v3, pName);
  else
    v3 = nullptr;
  insert.key = v3;
  return CUtlRBTree<CUtlMap<char const *,CShadowTextureList::alphatexture_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CShadowTextureList::alphatexture_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CShadowTextureList::alphatexture_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
           this: &this->m_Elements.m_Tree,
           &insert);
}

//------------------------------------------------------------------------------
// Address: 0x1002FA30
// Name: public: bool CShadowTextureList::FindOrLoadIfValid(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShadowTextureList::FindOrLoadIfValid(CShadowTextureList *this, const char *pMaterialName, int *pIndex)
{
  unsigned __int16 v5; // ax
  KeyValues *v7; // eax
  KeyValues *v8; // esi
  KeyValues *Key; // eax
  const char *String; // eax
  int v11; // edi
  int v12; // esi
  unsigned __int8 *v13; // [esp-4h] [ebp-64h]
  CUtlBuffer buf; // [esp+Ch] [ebp-54h] BYREF
  CUtlMap<char const *,CShadowTextureList::alphatexture_t,unsigned short>::Node_t search; // [esp+3Ch] [ebp-24h] BYREF
  int w; // [esp+4Ch] [ebp-14h] BYREF
  int h; // [esp+50h] [ebp-10h] BYREF
  unsigned __int8 *pImageBits; // [esp+54h] [ebp-Ch]
  KeyValues *pVMT; // [esp+58h] [ebp-8h]
  bool bClampV; // [esp+5Eh] [ebp-2h] BYREF
  bool bClampU; // [esp+5Fh] [ebp-1h] BYREF
  char bFound_3; // [esp+6Bh] [ebp+Bh]

  *pIndex = -1;
  if ( pMaterialName != nullptr )
  {
    search.key = pMaterialName;
    v5 = CUtlRBTree<CUtlMap<char const *,CShadowTextureList::alphatexture_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CShadowTextureList::alphatexture_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CShadowTextureList::alphatexture_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: &this->m_Textures.m_Elements.m_Tree,
           &search);
  }
  else
  {
    v5 = -1;
  }
  bFound_3 = 0;
  if ( v5 == 0xFFFF )
  {
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
    {
      v8 = KeyValues::KeyValues(this: v7, setName: "vmt");
      pVMT = v8;
    }
    else
    {
      pVMT = nullptr;
      v8 = nullptr;
    }
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
    LoadFileIntoBuffer(&buf, pFilename: pMaterialName);
    if ( KeyValues::LoadFromBuffer(
           this: v8,
           resourceName: pMaterialName,
           &buf,
           pFileSystem: nullptr,
           pPathID: nullptr,
           pfnEvaluateSymbolProc: nullptr) )
    {
      bFound_3 = 1;
      if ( KeyValues::FindKey(this: v8, keyName: "$translucent", bCreate: false) != nullptr
        || KeyValues::FindKey(this: v8, keyName: "$alphatest", bCreate: false) != nullptr )
      {
        Key = KeyValues::FindKey(this: v8, keyName: "$basetexture", bCreate: false);
        if ( Key != nullptr )
        {
          String = KeyValues::GetString(this: Key, keyName: nullptr, defaultValue: defaultValue);
          if ( String != nullptr )
          {
            bClampU = false;
            bClampV = false;
            pImageBits = CShadowTextureList::LoadVTFRGB8888(
                           this,
                           a2: (int)this,
                           a3: (int)pMaterialName,
                           a4: (int)v8,
                           pName: String,
                           pWidth: &w,
                           pHeight: &h,
                           pClampU: &bClampU,
                           pClampV: &bClampV);
            if ( pImageBits != nullptr )
            {
              v11 = CUtlDict<CShadowTextureList::alphatexture_t,unsigned short>::Insert(
                      this: &this->m_Textures,
                      pName: pMaterialName);
              v12 = v11;
              CShadowTextureList::alphatexture_t::InitFromRGB8888(
                this: &this->m_Textures.m_Elements.m_Tree.m_Elements.m_pMemory[v11].m_Data.elem,
                w,
                h,
                pTexels: pImageBits);
              *pIndex = v11;
              if ( KeyValues::FindKey(this: pVMT, keyName: "$nocull", bCreate: false) != nullptr )
                this->m_Textures.m_Elements.m_Tree.m_Elements.m_pMemory[v12].m_Data.elem.allowBackface = true;
              this->m_Textures.m_Elements.m_Tree.m_Elements.m_pMemory[v12].m_Data.elem.clampU = bClampU;
              v13 = pImageBits;
              this->m_Textures.m_Elements.m_Tree.m_Elements.m_pMemory[v12].m_Data.elem.clampV = bClampV;
              free(pMem: v13);
              v8 = pVMT;
            }
          }
        }
      }
    }
    KeyValues::deleteThis(this: v8);
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return bFound_3;
  }
  else
  {
    *pIndex = v5;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002FC00
// Name: public: void CShadowTextureList::LoadAllTexturesForModel(struct studiohdr_t __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowTextureList::LoadAllTexturesForModel(CShadowTextureList *this, int pHdr, int *pTextureList)
{
  studiohdr_t *v3; // esi
  int v4; // ebx
  int v5; // edi
  int v6; // ebx
  char szPath[260]; // [esp+8h] [ebp-10Ch] BYREF
  CShadowTextureList *v8; // [esp+10Ch] [ebp-8h]
  int i; // [esp+110h] [ebp-4h]

  v3 = (studiohdr_t *)pHdr;
  v4 = 0;
  v8 = this;
  i = 0;
  if ( *(int *)(pHdr + 204) > 0 )
  {
    do
    {
      v5 = 0;
      pHdr = -1;
      if ( v3->numcdtextures > 0 )
      {
        v6 = v4 << 6;
        do
        {
          V_strncpy(pDest: szPath, pSrc: "materials/", maxLen: 260);
          V_strncat(
            pDest: szPath,
            pSrc: (const char *)v3 + *(int *)((char *)&v3->id + 4 * v5 + v3->cdtextureindex),
            destBufferSize: 0x104u,
            max_chars_to_copy: -1);
          V_strncat(
            pDest: szPath,
            pSrc: (const char *)v3 + v6 + v3->textureindex + *(int *)((char *)&v3->id + v6 + v3->textureindex),
            destBufferSize: 0x104u,
            max_chars_to_copy: -1);
          V_strncat(pDest: szPath, pSrc: ".vmt", destBufferSize: 0x104u, max_chars_to_copy: -1);
          V_FixSlashes(pname: szPath, separator: 92);
          if ( CShadowTextureList::FindOrLoadIfValid(this: v8, pMaterialName: szPath, pIndex: &pHdr) != 0 )
            break;
          ++v5;
        }
        while ( v5 < v3->numcdtextures );
        v4 = i;
      }
      pTextureList[v4++] = pHdr;
      i = v4;
    }
    while ( v4 < v3->numtextures );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002FD20
// Name: int LoadShadowTexture(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LoadShadowTexture(const char *pMaterialName)
{
  char szPath[260]; // [esp+0h] [ebp-108h] BYREF
  int textureIndex; // [esp+104h] [ebp-4h] BYREF

  textureIndex = -1;
  V_strncpy(pDest: szPath, pSrc: "materials/", maxLen: 260);
  V_strncat(pDest: szPath, pSrc: pMaterialName, destBufferSize: 0x104u, max_chars_to_copy: -1);
  V_strncat(pDest: szPath, pSrc: ".vmt", destBufferSize: 0x104u, max_chars_to_copy: -1);
  V_FixSlashes(pname: szPath, separator: 92);
  CShadowTextureList::FindOrLoadIfValid(this: &g_ShadowTextureList, pMaterialName: szPath, pIndex: &textureIndex);
  return textureIndex;
}

//------------------------------------------------------------------------------
// Address: 0x1002FDB0
// Name: private: void CVradStaticPropMgr::CreateCollisionModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVradStaticPropMgr::CreateCollisionModel(CVradStaticPropMgr *this, const char *pModelName)
{
  int v3; // edi
  CVradStaticPropMgr::StaticPropDict_t *v4; // edi
  unsigned __int8 *v5; // eax
  bool v6; // zf
  studiohdr_t *m_pMemory; // ebx
  CVradStaticPropMgr::StaticPropDict_t *v8; // ecx
  float *v9; // eax
  double z; // st7
  CPhysCollide *v11; // eax
  CVradStaticPropMgr::StaticPropDict_t *v12; // ecx
  int p_m_VtxBuf; // ebx
  phyheader_s header; // [esp+Ch] [ebp-A8h] BYREF
  CUtlBuffer bufvtx; // [esp+1Ch] [ebp-98h] BYREF
  CUtlBuffer buf; // [esp+4Ch] [ebp-68h] BYREF
  CUtlBuffer bufphy; // [esp+7Ch] [ebp-38h] BYREF
  CVradStaticPropMgr::StaticPropDict_t *v18; // [esp+ACh] [ebp-8h]
  studiohdr_t *pHdr; // [esp+B0h] [ebp-4h]

  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  CUtlBuffer::CUtlBuffer(this: &bufvtx, growSize: 0, initSize: 0, nFlags: 0);
  CUtlBuffer::CUtlBuffer(this: &bufphy, growSize: 0, initSize: 0, nFlags: 0);
  v3 = CUtlVector<CVradStaticPropMgr::StaticPropDict_t,CUtlMemory<CVradStaticPropMgr::StaticPropDict_t,int>>::InsertBefore(
         this: &this->m_StaticPropDict,
         elem: this->m_StaticPropDict.m_Size);
  this->m_StaticPropDict.m_Memory.m_pMemory[v3].m_pModel = nullptr;
  this->m_StaticPropDict.m_Memory.m_pMemory[v3].m_pStudioHdr = nullptr;
  if ( LoadStudioModel(pModelName, &buf) != 0 )
  {
    m_pMemory = (studiohdr_t *)buf.m_Memory.m_pMemory;
    v8 = this->m_StaticPropDict.m_Memory.m_pMemory;
    v8[v3].m_Mins.x = *((float *)buf.m_Memory.m_pMemory + 26);
    v9 = (float *)&v8[v3];
    v9[6] = m_pMemory->hull_min.y;
    z = m_pMemory->hull_min.z;
    pHdr = m_pMemory;
    v9[7] = z;
    v9[8] = m_pMemory->hull_max.x;
    v9[9] = m_pMemory->hull_max.y;
    v9[10] = m_pMemory->hull_max.z;
    if ( LoadStudioCollisionModel(pModelName, buf: &bufphy) )
    {
      CUtlBuffer::Get(this: &bufphy, pMem: &header, size: 16);
      s_pPhysCollision->VCollideLoad(
        this: s_pPhysCollision,
        a2: (vcollide_t *)&this->m_StaticPropDict.m_Memory.m_pMemory[v3],
        a3: header.solidCount,
        a4: (const char *)&bufphy.m_Memory.m_pMemory[bufphy.m_Get - bufphy.m_nOffset],
        a5: bufphy.m_Put - bufphy.m_Get,
        a6: false);
      this->m_StaticPropDict.m_Memory.m_pMemory[v3].m_pModel = *this->m_StaticPropDict.m_Memory.m_pMemory[v3].m_loadedModel.solids;
    }
    else
    {
      *(_WORD *)&this->m_StaticPropDict.m_Memory.m_pMemory[v3].m_loadedModel &= 0x8000u;
      v18 = &this->m_StaticPropDict.m_Memory.m_pMemory[v3];
      v11 = ComputeConvexHull(pStudioHdr: m_pMemory);
      v18->m_pModel = v11;
    }
    this->m_StaticPropDict.m_Memory.m_pMemory[v3].m_pStudioHdr = (studiohdr_t *)MemAlloc_Alloc(nSize: buf.m_Memory.m_nAllocationCount);
    memcpy(
      dst: (unsigned __int8 *)this->m_StaticPropDict.m_Memory.m_pMemory[v3].m_pStudioHdr,
      src: buf.m_Memory.m_pMemory,
      count: buf.m_Memory.m_nAllocationCount);
    if ( LoadVTXFile(
           pModelName,
           pStudioHdr: this->m_StaticPropDict.m_Memory.m_pMemory[v3].m_pStudioHdr,
           buf: &this->m_StaticPropDict.m_Memory.m_pMemory[v3].m_VtxBuf) == 0 )
    {
      v12 = this->m_StaticPropDict.m_Memory.m_pMemory;
      p_m_VtxBuf = (int)&v12[v3].m_VtxBuf;
      *(_DWORD *)(p_m_VtxBuf + 12) = 0;
      *(_DWORD *)(p_m_VtxBuf + 16) = 0;
      *(_DWORD *)(p_m_VtxBuf + 32) = 0;
      *(_DWORD *)(p_m_VtxBuf + 28) = 0;
      *(_BYTE *)(p_m_VtxBuf + 20) = 0;
      if ( v12[v3].m_VtxBuf.m_Memory.m_nGrowSize >= 0 )
      {
        if ( *(_DWORD *)p_m_VtxBuf != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)p_m_VtxBuf);
          *(_DWORD *)p_m_VtxBuf = 0;
        }
        *(_DWORD *)(p_m_VtxBuf + 4) = 0;
      }
      m_pMemory = pHdr;
    }
    if ( g_bTextureShadows && ((m_pMemory->flags & 0x40000) != 0 || IsModelTextureShadowsForced(pModelName)) )
    {
      this->m_StaticPropDict.m_Memory.m_pMemory[v3].m_textureShadowIndex.m_Size = 0;
      this->m_StaticPropDict.m_Memory.m_pMemory[v3].m_triangleMaterialIndex.m_Size = 0;
      CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
        this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&this->m_StaticPropDict.m_Memory.m_pMemory[v3].m_textureShadowIndex,
        elem: this->m_StaticPropDict.m_Memory.m_pMemory[v3].m_textureShadowIndex.m_Size,
        num: m_pMemory->numtextures);
      CShadowTextureList::LoadAllTexturesForModel(
        this: &g_ShadowTextureList,
        pHdr: (int)m_pMemory,
        pTextureList: this->m_StaticPropDict.m_Memory.m_pMemory[v3].m_textureShadowIndex.m_Memory.m_pMemory);
    }
    if ( bufphy.m_Memory.m_nGrowSize >= 0 )
    {
      if ( bufphy.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufphy.m_Memory.m_pMemory);
        bufphy.m_Memory.m_pMemory = nullptr;
      }
      bufphy.m_Memory.m_nAllocationCount = 0;
    }
    if ( bufvtx.m_Memory.m_nGrowSize >= 0 )
    {
      if ( bufvtx.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufvtx.m_Memory.m_pMemory);
        bufvtx.m_Memory.m_pMemory = nullptr;
      }
      bufvtx.m_Memory.m_nAllocationCount = 0;
    }
    if ( buf.m_Memory.m_nGrowSize >= 0 )
    {
      v5 = buf.m_Memory.m_pMemory;
      v6 = buf.m_Memory.m_pMemory == nullptr;
LABEL_35:
      if ( !v6 )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
    }
  }
  else
  {
    v4 = &this->m_StaticPropDict.m_Memory.m_pMemory[v3];
    v4->m_Mins = vec3_origin;
    v4->m_Maxs = vec3_origin;
    if ( bufphy.m_Memory.m_nGrowSize >= 0 )
    {
      if ( bufphy.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufphy.m_Memory.m_pMemory);
        bufphy.m_Memory.m_pMemory = nullptr;
      }
      bufphy.m_Memory.m_nAllocationCount = 0;
    }
    if ( bufvtx.m_Memory.m_nGrowSize >= 0 )
    {
      if ( bufvtx.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufvtx.m_Memory.m_pMemory);
        bufvtx.m_Memory.m_pMemory = nullptr;
      }
      bufvtx.m_Memory.m_nAllocationCount = 0;
    }
    if ( buf.m_Memory.m_nGrowSize >= 0 )
    {
      v5 = buf.m_Memory.m_pMemory;
      v6 = buf.m_Memory.m_pMemory == nullptr;
      goto LABEL_35;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030100
// Name: private: void CVradStaticPropMgr::UnserializeModelDict(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVradStaticPropMgr::UnserializeModelDict(CVradStaticPropMgr *this, CUtlBuffer *buf)
{
  int i; // esi
  StaticPropDictLump_t lump; // [esp+Ch] [ebp-80h] BYREF

  for ( i = CUtlBuffer::GetInt(this: buf) - 1; i >= 0; --i )
  {
    CUtlBuffer::Get(this: buf, pMem: &lump, size: 128);
    CVradStaticPropMgr::CreateCollisionModel(this, pModelName: lump.m_Name);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030150
// Name: private: static void CVradStaticPropMgr::VMPI_ReceiveStaticPropResults_Static(unsigned __int64,class MessageBuffer __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CVradStaticPropMgr::VMPI_ReceiveStaticPropResults_Static(
        unsigned __int64 iStaticProp,
        MessageBuffer *pBuf,
        int iWorker)
{
  CVradStaticPropMgr::VMPI_ReceiveStaticPropResults(this: &g_StaticPropMgr, iStaticProp, pBuf, iWorker);
}

//------------------------------------------------------------------------------
// Address: 0x10030170
// Name: public: virtual void CVradStaticPropMgr::ComputeLighting(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVradStaticPropMgr::ComputeLighting(CVradStaticPropMgr *this, int iThread)
{
  int m_Size; // edi

  m_Size = this->m_StaticProps.m_Size;
  if ( m_Size != 0 )
  {
    StartPacifier(pPrefix: "Computing static prop lighting : ");
    this->m_bIgnoreStaticPropTrace = true;
    if ( g_bUseMPI )
    {
      VMPI_SetCurrentStage(pCurStage: "CVradStaticPropMgr::ComputeLighting");
      DistributeWork(
        nWorkUnits: m_Size,
        processFn: CVradStaticPropMgr::VMPI_ProcessStaticProp_Static,
        receiveFn: CVradStaticPropMgr::VMPI_ReceiveStaticPropResults_Static);
    }
    else
    {
      printf(format: "%-20s ", "ThreadComputeStaticPropLighting:");
      RunThreadsOn(
        workcnt: m_Size,
        showpacifier: 1,
        fn: (void (__cdecl *)(int, void *))CVradStaticPropMgr::ThreadComputeStaticPropLighting,
        pUserData: nullptr);
    }
    this->m_bIgnoreStaticPropTrace = false;
    CVradStaticPropMgr::SerializeLighting(this);
    EndPacifier(bCarriageReturn: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030350
// Name: private: void CVradStaticPropMgr::UnserializeModels(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVradStaticPropMgr::UnserializeModels(CVradStaticPropMgr *this, CUtlBuffer *buf)
{
  int Int; // ebx
  int v4; // esi
  CVradStaticPropMgr::CStaticProp *m_pMemory; // edx
  CVradStaticPropMgr::CStaticProp *v6; // eax
  StaticPropLump_t lump; // [esp+Ch] [ebp-48h] BYREF

  Int = CUtlBuffer::GetInt(this: buf);
  CUtlVector<CVradStaticPropMgr::CStaticProp,CUtlMemory<CVradStaticPropMgr::CStaticProp,int>>::InsertMultipleBefore(
    this: &this->m_StaticProps,
    elem: this->m_StaticProps.m_Size,
    num: Int);
  if ( Int > 0 )
  {
    v4 = 0;
    do
    {
      CUtlBuffer::Get(this: buf, pMem: &lump, size: 72);
      m_pMemory = this->m_StaticProps.m_Memory.m_pMemory;
      m_pMemory[v4].m_Origin = lump.m_Origin;
      v6 = &m_pMemory[v4];
      v6->m_Angles = lump.m_Angles;
      v6->m_LightingOrigin = lump.m_LightingOrigin;
      m_pMemory[v4].m_bLightingOriginValid = (lump.m_Flags & 2) != 0;
      this->m_StaticProps.m_Memory.m_pMemory[v4].m_ModelIdx = lump.m_PropType;
      this->m_StaticProps.m_Memory.m_pMemory[v4].m_Handle = -1;
      this->m_StaticProps.m_Memory.m_pMemory[v4++].m_Flags = lump.m_Flags;
      --Int;
    }
    while ( Int != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030440
// Name: private: void CVradStaticPropMgr::UnserializeStaticProps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVradStaticPropMgr::UnserializeStaticProps(CVradStaticPropMgr *this)
{
  unsigned __int16 GameLumpHandle; // si
  int v3; // ebx
  const void *GameLump; // eax
  int Int; // eax
  CUtlBuffer buf; // [esp+Ch] [ebp-30h] BYREF

  GameLumpHandle = CGameLump::GetGameLumpHandle(this: &g_GameLumps, id: 1936749168);
  v3 = CGameLump::GameLumpSize(this: &g_GameLumps, id: GameLumpHandle);
  if ( v3 != 0 )
  {
    if ( CGameLump::GetGameLumpVersion(this: &g_GameLumps, handle: GameLumpHandle) != 9 )
      _Error(a1: "Cannot load the static props... encountered a stale map version. Re-vbsp the map.");
    if ( CGameLump::GetGameLump(this: &g_GameLumps, id: GameLumpHandle) != nullptr )
    {
      GameLump = CGameLump::GetGameLump(this: &g_GameLumps, id: GameLumpHandle);
      CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: GameLump, nSize: v3, nFlags: 8);
      CVradStaticPropMgr::UnserializeModelDict(this, &buf);
      Int = CUtlBuffer::GetInt(this: &buf);
      CUtlBuffer::SeekGet(this: &buf, type: SEEK_CURRENT, offset: 2 * Int);
      CVradStaticPropMgr::UnserializeModels(this, &buf);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030510
// Name: public: virtual void CVradStaticPropMgr::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVradStaticPropMgr::Init(CVradStaticPropMgr *this)
{
  void *(__cdecl *PhysicsFactory)(const char *, int *); // esi

  PhysicsFactory = GetPhysicsFactory();
  if ( PhysicsFactory == nullptr )
    _Error(a1: "Unable to load vphysics DLL.");
  s_pPhysCollision = (IPhysicsCollision *)PhysicsFactory(a1: "VPhysicsCollision007", a2: nullptr);
  if ( s_pPhysCollision != nullptr )
    CVradStaticPropMgr::UnserializeStaticProps(this);
  else
    _Error(a1: "Unable to get '%s' for physics interface.", "VPhysicsCollision007");
}

//------------------------------------------------------------------------------
// Address: 0x10030570
// Name: public: virtual void CVradStaticPropMgr::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVradStaticPropMgr::Shutdown(CVradStaticPropMgr *this)
{
  CVradStaticPropMgr *v1; // edi
  int v2; // esi
  int v3; // ebx
  void **m_pStudioHdr; // edi
  CVradStaticPropMgr::StaticPropDict_t *m_pMemory; // ecx

  v1 = this;
  v2 = this->m_StaticPropDict.m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      m_pStudioHdr = (void **)v1->m_StaticPropDict.m_Memory.m_pMemory[v3].m_pStudioHdr;
      if ( m_pStudioHdr != nullptr )
      {
        if ( m_pStudioHdr[92] != nullptr )
          free(pMem: m_pStudioHdr[92]);
        free(pMem: m_pStudioHdr);
      }
      v1 = this;
      --v3;
      --v2;
    }
    while ( v2 >= 0 );
  }
  CUtlVector<CVradStaticPropMgr::CStaticProp,CUtlMemory<CVradStaticPropMgr::CStaticProp,int>>::RemoveAll(this: &v1->m_StaticProps);
  if ( v1->m_StaticProps.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v1->m_StaticProps.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_StaticProps.m_Memory.m_pMemory);
      v1->m_StaticProps.m_Memory.m_pMemory = nullptr;
    }
    v1->m_StaticProps.m_Memory.m_nAllocationCount = 0;
  }
  v1->m_StaticProps.m_pElements = v1->m_StaticProps.m_Memory.m_pMemory;
  CUtlVector<CVradStaticPropMgr::StaticPropDict_t,CUtlMemory<CVradStaticPropMgr::StaticPropDict_t,int>>::RemoveAll(this: &v1->m_StaticPropDict);
  if ( v1->m_StaticPropDict.m_Memory.m_nGrowSize < 0 )
  {
    v1->m_StaticPropDict.m_pElements = v1->m_StaticPropDict.m_Memory.m_pMemory;
  }
  else
  {
    if ( v1->m_StaticPropDict.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_StaticPropDict.m_Memory.m_pMemory);
      v1->m_StaticPropDict.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = v1->m_StaticPropDict.m_Memory.m_pMemory;
    v1->m_StaticPropDict.m_Memory.m_nAllocationCount = 0;
    v1->m_StaticPropDict.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100931C0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}
