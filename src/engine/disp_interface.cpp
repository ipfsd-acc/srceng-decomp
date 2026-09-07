// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/disp_interface.cpp
// Functions: 40
// ============================================================

#include "engine\disp_interface.h"

//------------------------------------------------------------------------------
// Address: 0x100BD030
// Name: public: virtual void CDispInfo::GetBoundingBox(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::GetBoundingBox(CDispInfo *this, Vector *bbMin, Vector *bbMax)
{
  *bbMin = this->m_BBoxMin;
  *bbMax = this->m_BBoxMax;
}

//------------------------------------------------------------------------------
// Address: 0x100BD060
// Name: public: virtual void CDispInfo::SetParent(struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::SetParent(vgui::ImagePanel *this, Color drawColor)
{
  this->m_DrawColor = drawColor;
}

//------------------------------------------------------------------------------
// Address: 0x100BD080
// Name: public: virtual void CDispInfo::AddDynamicLights(struct dlight_t __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::AddDynamicLights(CDispInfo *this, dlight_t *pLights, unsigned int mask)
{
  int v5; // edi
  CDispInfo *v6; // [esp+0h] [ebp-4h]

  v6 = this;
  if ( this->m_ParentSurfID != nullptr )
  {
    v5 = 0;
    while ( mask != 0 )
    {
      if ( (mask & 1) != 0 )
      {
        if ( (pLights->flags & 0xC) != 0 )
        {
          CDispInfo::AddSingleDynamicAlphaLight(this, dl: pLights);
        }
        else if ( CDispInfo::NumLightMaps(this) == 1 )
        {
          CDispInfo::AddSingleDynamicLight(this: v6, dl: pLights);
        }
        else
        {
          CDispInfo::AddSingleDynamicLightBumped(this: v6, dl: pLights);
        }
      }
      ++v5;
      ++pLights;
      mask >>= 1;
      if ( v5 >= 32 )
        break;
      this = v6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BD0F0
// Name: private: void CDispInfo::FindNodesInShadowFrustum(class Frustum_t const __near &,unsigned short __near *,int __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::FindNodesInShadowFrustum(
        CDispInfo *this,
        Frustum_t *frustum,
        unsigned __int16 *pNodeArray,
        int *pNumNodes,
        int iNodeBit,
        int iLevel)
{
  int v6; // ecx
  int v7; // esi
  int v8; // edi
  int v9; // ebx
  int v10; // edx
  float v11; // xmm0_4
  int v12; // edx
  unsigned __int8 v13; // al
  unsigned __int8 v14; // al
  VisitedNodeData_t nodeList[85]; // [esp+Ch] [ebp-B8h]
  Vector *mins; // [esp+B8h] [ebp-Ch]
  CDispInfo *v17; // [esp+BCh] [ebp-8h]
  int listIndex; // [esp+C0h] [ebp-4h]

  v17 = this;
  v6 = 0;
  nodeList[0] = 0;
  v7 = 0;
  do
  {
    v8 = nodeList[v6].iNodeBit;
    v9 = nodeList[v6].iLevel;
    v10 = (int)&v17->m_pNodeInfo[v8];
    v11 = *(float *)(v10 + 4);
    ++v6;
    mins = (Vector *)(v10 + 4);
    listIndex = v6;
    if ( v11 != 3.4028235e38 )
    {
      if ( !Frustum_t::CullBox(this: frustum, mins, maxs: (const Vector *)(v10 + 16)) )
      {
        if ( v9 + 1 >= v17->m_Power )
        {
          pNodeArray[(*pNumNodes)++] = v8;
        }
        else
        {
          v12 = v17->m_pPowerInfo->m_NodeIndexIncrements[v9];
          nodeList[v7 + 1].iNodeBit = v8 + 1;
          v13 = v12 + v8 + 1;
          nodeList[v7 + 2].iNodeBit = v13;
          v14 = v12 + v13;
          nodeList[v7 + 1].iLevel = v9 + 1;
          nodeList[v7 + 2].iLevel = v9 + 1;
          nodeList[v7 + 3].iNodeBit = v14;
          nodeList[v7 + 3].iLevel = v9 + 1;
          nodeList[v7 + 4].iNodeBit = v14 + v12;
          nodeList[v7 + 4].iLevel = v9 + 1;
          v7 += 4;
        }
      }
      v6 = listIndex;
    }
  }
  while ( v6 <= v7 );
}

//------------------------------------------------------------------------------
// Address: 0x100BD1F0
// Name: private: void CDispInfo::AddNodeTrisToDecal(class CDispShadowDecal __near *,unsigned short,unsigned short __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::AddNodeTrisToDecal(
        CDispInfo *this,
        CDispShadowDecal *pDispDecal,
        unsigned __int16 decalHandle,
        unsigned __int16 *pNodeIndices,
        int nNumIndices)
{
  int v5; // ecx
  DispNodeInfo_t *m_pNodeInfo; // eax
  int m_FirstTesselationIndex; // ebx
  DispNodeInfo_t *v8; // edi
  int v9; // esi
  int j; // [esp+0h] [ebp-8h]

  v5 = 0;
  for ( j = 0; v5 < nNumIndices; j = v5 )
  {
    m_pNodeInfo = this->m_pNodeInfo;
    m_FirstTesselationIndex = m_pNodeInfo[pNodeIndices[v5]].m_FirstTesselationIndex;
    v8 = &m_pNodeInfo[pNodeIndices[v5]];
    v9 = 0;
    if ( v8->m_Count != 0 )
    {
      do
      {
        CDispInfo::TestAddDecalTri(
          this,
          iIndexStart: (ShadowVertex_t **)(v9 + m_FirstTesselationIndex),
          decalHandle,
          pDecal: pDispDecal);
        v9 += 3;
      }
      while ( v9 < v8->m_Count );
      v5 = j;
    }
    ++v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BD270
// Name: public: virtual bool CDispInfo::GetTag(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDispInfo::GetTag(CDispInfo *this)
{
  return this->m_Tag == this->m_pDispArray->m_CurTag;
}

//------------------------------------------------------------------------------
// Address: 0x100BD290
// Name: public: virtual void CDispInfo::SetTag(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::SetTag(CDispInfo *this)
{
  this->m_Tag = this->m_pDispArray->m_CurTag;
}

//------------------------------------------------------------------------------
// Address: 0x100BD2B0
// Name: void DispInfo_BuildPrimLists(int,struct msurface2_t __near * __near *,int,bool,class CDispInfo __near * __near * const,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispInfo_BuildPrimLists(
        int nSortGroup,
        msurface2_t **pList,
        int listCount,
        bool bDepthOnly,
        CDispInfo **visibleDisps,
        int *nVisibleDisps)
{
  int v6; // ebx
  CDispInfo *pDispInfo; // esi

  v6 = 0;
  for ( *nVisibleDisps = 0; v6 < listCount; ++v6 )
  {
    pDispInfo = (CDispInfo *)pList[v6]->pDispInfo;
    if ( CDispInfo::Render(this: pDispInfo, pGroup: pDispInfo->m_pMesh, bAllowDebugModes: false) != 0
      && *nVisibleDisps < 2048 )
    {
      visibleDisps[(*nVisibleDisps)++] = pDispInfo;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BD300
// Name: void __near * DispInfo_CreateArray(int)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__cdecl DispInfo_CreateArray(unsigned int nElements)
{
  int v1; // edi
  _DWORD *v2; // esi
  CDispInfo *v3; // ebx
  int v4; // ecx
  unsigned int *v5; // eax
  int v6; // eax
  CDispInfo *v8; // [esp+Ch] [ebp-4h]
  int nElementsa; // [esp+18h] [ebp+8h]

  v1 = nElements;
  v2 = MemAlloc_Alloc(nSize: 0xCu);
  v3 = nullptr;
  *(_WORD *)v2 = 1;
  v2[2] = nElements;
  if ( nElements != 0 )
  {
    v4 = (620 * (unsigned __int64)nElements) >> 32 != 0 ? -1 : 620 * nElements;
    v5 = (unsigned int *)MemAlloc_Alloc(nSize: __CFADD__(v4, 4) ? -1 : v4 + 4);
    if ( v5 != nullptr )
    {
      v3 = (CDispInfo *)(v5 + 1);
      *v5 = nElements;
      v8 = (CDispInfo *)(v5 + 1);
      nElementsa = nElements - 1;
      if ( v1 - 1 >= 0 )
      {
        do
        {
          CDispInfo::CDispInfo(this: v3++);
          --nElementsa;
        }
        while ( nElementsa >= 0 );
        v3 = v8;
      }
    }
  }
  v2[1] = v3;
  if ( v1 > 0 )
  {
    v6 = 0;
    do
    {
      *(_DWORD *)(v6 + v2[1] + 616) = v2;
      v6 += 620;
      --v1;
    }
    while ( v1 != 0 );
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100BD3B0
// Name: void DispInfo_DeleteArray(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispInfo_DeleteArray(_DWORD *hArray)
{
  void (__thiscall ***v1)(_DWORD, int); // ecx

  if ( hArray != nullptr )
  {
    v1 = (void (__thiscall ***)(_DWORD, int))hArray[1];
    if ( v1 != nullptr )
    {
      if ( *(v1 - 1) != nullptr )
      {
        (**v1)(a1: v1, a2: 3);
        free(pMem: hArray);
        return;
      }
      free(pMem: v1 - 1);
    }
    free(pMem: hArray);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BD400
// Name: class IDispInfo __near * DispInfo_IndexArray(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
IDispInfo *__cdecl DispInfo_IndexArray(_DWORD *hArray, int iElement)
{
  if ( hArray != nullptr )
    return (IDispInfo *)(hArray[1] + 620 * iElement);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100BD420
// Name: int DispInfo_ComputeIndex(void __near *,class IDispInfo __near *)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__cdecl DispInfo_ComputeIndex(_DWORD *hArray, IDispInfo *pInfo)
{
  _DWORD *result; // eax

  result = hArray;
  if ( hArray != nullptr )
    return (_DWORD *)(((unsigned int)pInfo - hArray[1]) / 0x26C);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BD440
// Name: void DispInfo_ClearAllTags(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispInfo_ClearAllTags(_DWORD *hArray)
{
  int v1; // ecx
  int v2; // edx

  if ( hArray != nullptr && ++*(_WORD *)hArray == 0xFFFF )
  {
    *(_WORD *)hArray = 1;
    v1 = 0;
    if ( (int)hArray[2] > 0 )
    {
      v2 = 0;
      do
      {
        *(_WORD *)(hArray[1] + v2 + 612) = 0;
        ++v1;
        v2 += 620;
      }
      while ( v1 < hArray[2] );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BD490
// Name: public: virtual void CDispInfo::GetIntersectingSurfaces(class GetIntersectingSurfaces_Struct __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::GetIntersectingSurfaces(CDispInfo *this, GetIntersectingSurfaces_Struct *pStruct)
{
  CDispInfo *v2; // eax
  bool v3; // zf
  GetIntersectingSurfaces_Struct *v4; // edx
  SurfInfo *v5; // edi
  int v6; // ecx
  float *p_z; // edi
  unsigned __int16 *m_pIndices; // ebx
  float v9; // edx
  int v10; // esi
  int v11; // esi
  double v12; // st7
  float *v13; // ecx
  int v14; // edx
  double v15; // st6
  double v16; // rt0
  double v17; // st6
  double v18; // st7
  float *v19; // edx
  double v20; // st6
  double v21; // st5
  double v22; // rt1
  double v23; // st5
  double v24; // st6
  double v25; // st5
  double v26; // st3
  double v27; // st4
  double v28; // st3
  double v29; // st7
  double v30; // st3
  double v31; // rt0
  double v32; // st4
  double v33; // st6
  double v34; // st4
  double v35; // st6
  double v36; // st4
  double v37; // st3
  double v38; // st2
  double v39; // st5
  double v40; // rtt
  double v41; // st3
  double v42; // st7
  double v43; // rt0
  double v44; // st5
  double v45; // st7
  float m_Radius; // xmm1_4
  const Vector *v47; // eax
  float v48; // xmm3_4
  float v49; // xmm1_4
  float v50; // xmm0_4
  float v51; // xmm2_4
  float v52; // xmm4_4
  float v53; // xmm5_4
  float v54; // xmm0_4
  float v55; // xmm1_4
  Vector vMax; // [esp+0h] [ebp-3Ch] BYREF
  Vector vMin; // [esp+Ch] [ebp-30h] BYREF
  CDispInfo *v58; // [esp+18h] [ebp-24h]
  const Vector *m_pCenter; // [esp+1Ch] [ebp-20h]
  int v60; // [esp+20h] [ebp-1Ch]
  float v61; // [esp+24h] [ebp-18h]
  float v62; // [esp+28h] [ebp-14h]
  int iVert; // [esp+2Ch] [ebp-10h]
  SurfInfo *pOut; // [esp+30h] [ebp-Ch]
  int iDim; // [esp+34h] [ebp-8h]
  float v66; // [esp+38h] [ebp-4h]

  v2 = this;
  v3 = this->m_Verts.m_Size == 0;
  v58 = this;
  if ( !v3 && this->m_nIndices != 0 )
  {
    v4 = pStruct;
    v5 = &pStruct->m_pInfos[pStruct->m_nSetInfos];
    v6 = 0;
    pOut = v5;
    iVert = 0;
    if ( v2->m_MeshReader.m_MaxIndices > 0 )
    {
      p_z = &v5->m_Verts[1].z;
      do
      {
        if ( v4->m_nSetInfos >= v4->m_nMaxInfos )
          break;
        m_pIndices = v2->m_MeshReader.m_pIndices;
        v9 = *(float *)&v2->m_iVertOffset;
        v66 = *(float *)&v2->m_MeshReader.m_VertexSize_Position;
        iDim = (int)v2->m_MeshReader.m_pPosition;
        v10 = m_pIndices[v6 * v2->m_MeshReader.m_nIndexSize];
        LODWORD(v62) = v6 + 2;
        v11 = iDim + LODWORD(v66) * (v10 - LODWORD(v9));
        v12 = *(float *)v11;
        v13 = (float *)(iDim + LODWORD(v66) * (m_pIndices[v2->m_MeshReader.m_nIndexSize * (v6 + 1)] - LODWORD(v9)));
        v61 = v9;
        v14 = m_pIndices[LODWORD(v62) * v2->m_MeshReader.m_nIndexSize] - LODWORD(v9);
        v61 = v12;
        v15 = *v13;
        v62 = *v13;
        v16 = v15;
        v17 = v12;
        v18 = v16;
        v19 = (float *)(iDim + LODWORD(v66) * v14);
        if ( v17 <= v16 )
          v18 = v17;
        v20 = *(float *)(v11 + 4);
        iDim = *(int *)(v11 + 4);
        v21 = v13[1];
        v66 = v13[1];
        v22 = v21;
        v23 = v20;
        v24 = v22;
        if ( v23 <= v22 )
          v24 = v23;
        v25 = *(float *)(v11 + 8);
        v26 = v13[2];
        v60 = *((int *)v13 + 2);
        v27 = v26;
        if ( v25 <= v26 )
          v27 = v25;
        if ( *v19 <= v18 )
          v18 = *v19;
        v28 = v18;
        v29 = *v19;
        vMin.x = v28;
        v30 = v19[1];
        m_pCenter = *((const Vector **)v19 + 1);
        if ( v30 <= v24 )
          v24 = v30;
        v31 = v27;
        v32 = v24;
        v33 = v31;
        vMin.y = v32;
        if ( v19[2] <= v31 )
          v33 = v19[2];
        v34 = v33;
        v35 = v19[2];
        vMin.z = v34;
        v36 = v62;
        if ( v61 >= (double)v62 )
          v36 = v61;
        v37 = v66;
        if ( *(float *)&iDim >= (double)v66 )
          v37 = *(float *)&iDim;
        v38 = v25;
        v39 = *(float *)&v60;
        if ( v38 >= *(float *)&v60 )
          v39 = v38;
        v40 = v37;
        v41 = v29;
        v42 = v40;
        if ( v41 >= v36 )
          v36 = v41;
        vMax.x = v36;
        if ( *(float *)&m_pCenter >= v42 )
          v42 = *(float *)&m_pCenter;
        v43 = v39;
        v44 = v42;
        v45 = v43;
        vMax.y = v44;
        if ( v35 >= v43 )
          v45 = v35;
        vMax.z = v45;
        m_Radius = pStruct->m_Radius;
        m_pCenter = pStruct->m_pCenter;
        LODWORD(v61) = (char *)&vMax - (char *)m_pCenter;
        v47 = m_pCenter;
        *(float *)&iDim = 0.0;
        v60 = (char *)&vMin - (char *)m_pCenter;
        do
        {
          if ( *(float *)((char *)&v47->x + v60) > (float)(m_Radius + v47->x) )
            break;
          if ( (float)(v47->x - m_Radius) > *(float *)((char *)&v47->x + LODWORD(v61)) )
            break;
          v47 = (const Vector *)((char *)v47 + 4);
          ++iDim;
        }
        while ( iDim < 3 );
        if ( iDim == 3 )
        {
          *((_DWORD *)p_z + 43) = 3;
          pOut->m_Verts[0].x = *(float *)v11;
          *(p_z - 4) = *(float *)(v11 + 4);
          *(p_z - 3) = *(float *)(v11 + 8);
          *(p_z - 2) = *v13;
          *(p_z - 1) = v13[1];
          *p_z = v13[2];
          p_z[1] = *v19;
          p_z[2] = v19[1];
          p_z[3] = v19[2];
          v48 = v19[1] - *(float *)(v11 + 4);
          v49 = v19[2] - *(float *)(v11 + 8);
          v50 = v13[1] - *(float *)(v11 + 4);
          v51 = v13[2] - *(float *)(v11 + 8);
          v52 = *v13 - *(float *)v11;
          v53 = *v19 - *(float *)v11;
          p_z[44] = (float)(v48 * v51) - (float)(v49 * v50);
          p_z[45] = (float)(v49 * v52) - (float)(v51 * v53);
          p_z[46] = (float)(v50 * v53) - (float)(v48 * v52);
          VectorNormalize(vec: (Vector *)(p_z + 44));
          v54 = *(float *)(v11 + 4) * p_z[45];
          v55 = p_z[44] * *(float *)v11;
          v4 = pStruct;
          ++pOut;
          p_z[47] = (float)(v54 + v55) + (float)(p_z[46] * *(float *)(v11 + 8));
          ++pStruct->m_nSetInfos;
          p_z += 54;
        }
        else
        {
          v4 = pStruct;
        }
        v2 = v58;
        v6 = iVert + 3;
        iVert = v6;
      }
      while ( v6 < v58->m_MeshReader.m_MaxIndices );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BD7D0
// Name: public: virtual void CDispInfo::RenderWireframeInLightmapPage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::RenderWireframeInLightmapPage(CDispInfo *this, int pageId)
{
  msurface2_t *v2; // eax

  v2 = this->GetParent(this);
  if ( materialSortInfoArray[v2->materialSortID].lightmapPageID == pageId )
    Shader_DrawLightmapPageSurface(surfID: v2, red: 0.0, green: 0.0, blue: 1.0);
}

//------------------------------------------------------------------------------
// Address: 0x100BD810
// Name: public: virtual unsigned int CDispInfo::ComputeDynamicLightMask(struct dlight_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDispInfo::ComputeDynamicLightMask(CDispInfo *this, dlight_t *pLights)
{
  int v2; // edi
  int v4; // ebx
  int v5; // esi
  CDispInfo *v6; // [esp+4h] [ebp-8h]
  int lightMask; // [esp+8h] [ebp-4h]

  v2 = 0;
  v6 = this;
  lightMask = 0;
  if ( this->m_ParentSurfID == nullptr )
    return 0;
  v4 = r_dlightactive;
  v5 = 1;
  while ( v4 != 0 )
  {
    if ( (v4 & 1) != 0
      && (v5
        & *(int *)((_BYTE *)&host_state.worldbrush->surfacelighting->m_fDLightBits
                 + (((char *)this->m_ParentSurfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0))) != 0
      && (pLights->flags & 1) == 0
      && R_CanUseVisibleDLight(dlight: v2) )
    {
      lightMask |= v5;
    }
    ++pLights;
    ++v2;
    v4 >>= 1;
    v5 *= 2;
    if ( v2 >= 32 )
      break;
    this = v6;
  }
  return lightMask;
}

//------------------------------------------------------------------------------
// Address: 0x100BD8A0
// Name: void DispInfo_GetVisibleDispsAndAddOverlayFragmentsToRenderList(int,struct msurface2_t __near * __near *,int,class CDispInfo __near * __near * const,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispInfo_GetVisibleDispsAndAddOverlayFragmentsToRenderList(
        int nSortGroup,
        msurface2_t **pList,
        int listCount,
        CDispInfo **visibleDisps,
        int *nVisibleDisps)
{
  int v5; // esi
  IOverlayMgr *v6; // eax

  v5 = 0;
  for ( *nVisibleDisps = 0; v5 < listCount; ++v5 )
  {
    if ( *nVisibleDisps < 2048 )
      visibleDisps[(*nVisibleDisps)++] = (CDispInfo *)pList[v5]->pDispInfo;
    v6 = OverlayMgr();
    v6->AddFragmentListToRenderList(this: v6, a2: nSortGroup, a3: pList[v5]->m_nFirstOverlayFragment, a4: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BDB00
// Name: public: void CVertexBuilder::AdvanceVertices(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBuilder::AdvanceVertices(CVertexBuilder *this, int nVerts)
{
  int m_nCurrentVertex; // edx

  this->m_nCurrentVertex += nVerts;
  m_nCurrentVertex = this->m_nCurrentVertex;
  if ( m_nCurrentVertex > this->m_nVertexCount )
    this->m_nVertexCount = m_nCurrentVertex;
  this->m_pCurrPosition = (float *)((char *)this->m_pCurrPosition + nVerts * this->m_VertexSize_Position);
  this->m_pCurrNormal = (float *)((char *)this->m_pCurrNormal + nVerts * this->m_VertexSize_Normal);
  this->m_pCurrColor += nVerts * this->m_VertexSize_Color;
  this->m_pCurrTexCoord[0] = (float *)((char *)this->m_pCurrTexCoord[0] + nVerts * this->m_VertexSize_TexCoord[0]);
  this->m_pCurrTexCoord[1] = (float *)((char *)this->m_pCurrTexCoord[1] + nVerts * this->m_VertexSize_TexCoord[1]);
  this->m_pCurrTexCoord[2] = (float *)((char *)this->m_pCurrTexCoord[2] + nVerts * this->m_VertexSize_TexCoord[2]);
  this->m_pCurrTexCoord[3] = (float *)((char *)this->m_pCurrTexCoord[3] + nVerts * this->m_VertexSize_TexCoord[3]);
  this->m_pCurrTexCoord[4] = (float *)((char *)this->m_pCurrTexCoord[4] + nVerts * this->m_VertexSize_TexCoord[4]);
  this->m_pCurrTexCoord[5] = (float *)((char *)this->m_pCurrTexCoord[5] + nVerts * this->m_VertexSize_TexCoord[5]);
  this->m_pCurrTexCoord[6] = (float *)((char *)this->m_pCurrTexCoord[6] + nVerts * this->m_VertexSize_TexCoord[6]);
  this->m_pCurrTexCoord[7] = (float *)((char *)this->m_pCurrTexCoord[7] + nVerts * this->m_VertexSize_TexCoord[7]);
}

//------------------------------------------------------------------------------
// Address: 0x100BDBB0
// Name: private: void CDispInfo::GenerateDecalFragments_R(class CVertIndex const __near &,int,unsigned short,class CDispDecalBase __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::GenerateDecalFragments_R(
        CDispInfo *this,
        const CVertIndex *nodeIndex,
        const DispNodeInfo_t *iNodeBitIndex,
        unsigned __int16 decalHandle,
        CDispShadowDecal *pDispDecal,
        int iLevel)
{
  CDispShadowDecal *v8; // ebx
  int v9; // edi
  int v10; // eax
  const CPowerInfo *m_pPowerInfo; // ecx
  const CVertIndex *v12; // edx
  bool v13; // zf
  int m_FirstTesselationIndex; // edi
  bool v15; // al
  int v16; // [esp+Ch] [ebp-4h]
  const CVertIndex *nodeIndexa; // [esp+18h] [ebp+8h]
  const DispNodeInfo_t *nodeInfo; // [esp+1Ch] [ebp+Ch]
  bool isShadow_3; // [esp+27h] [ebp+17h]
  int i; // [esp+28h] [ebp+18h]

  v8 = pDispDecal;
  nodeInfo = &this->m_pNodeInfo[(_DWORD)iNodeBitIndex];
  if ( ((1 << ((unsigned __int8)iNodeBitIndex & 0x1F))
      & pDispDecal->m_NodeIntersect.m_Ints[(unsigned int)iNodeBitIndex >> 5]) != 0 )
  {
    if ( iLevel + 1 < this->m_Power && (nodeInfo->m_Flags & 1) != 0 )
    {
      v9 = (int)&iNodeBitIndex->m_FirstTesselationIndex + 1;
      v10 = 16 * (nodeIndex->x + this->m_pPowerInfo->m_SideLength * nodeIndex->y);
      nodeIndexa = (const CVertIndex *)v10;
      v16 = 4;
      do
      {
        m_pPowerInfo = this->m_pPowerInfo;
        v12 = (CVertIndex *)((char *)m_pPowerInfo->m_pChildVerts->m_Verts + v10);
        v8 = pDispDecal;
        if ( ((1 << ((v12->x + LOBYTE(m_pPowerInfo->m_SideLength) * v12->y) & 0x1F))
            & this->m_ActiveVerts.m_Ints[(unsigned int)(v12->x + m_pPowerInfo->m_SideLength * v12->y) >> 5]) != 0 )
          CDispInfo::GenerateDecalFragments_R(
            this,
            nodeIndex: v12,
            iNodeBitIndex: v9,
            decalHandle,
            pDispDecal,
            iLevel: iLevel + 1);
        v9 += this->m_pPowerInfo->m_NodeIndexIncrements[iLevel];
        v10 = (int)&nodeIndexa[1];
        v13 = v16-- == 1;
        ++nodeIndexa;
      }
      while ( !v13 );
    }
    m_FirstTesselationIndex = nodeInfo->m_FirstTesselationIndex;
    v15 = (v8->m_Flags & 2) != 0;
    isShadow_3 = v15;
    i = 0;
    if ( nodeInfo->m_Count != 0 )
    {
      while ( 1 )
      {
        if ( v15 )
          CDispInfo::TestAddDecalTri(
            this,
            iIndexStart: (ShadowVertex_t **)m_FirstTesselationIndex,
            decalHandle,
            pDecal: v8);
        else
          CDispInfo::TestAddDecalTri(this, iIndexStart: m_FirstTesselationIndex, decalHandle, pDispDecal: (decal_t *)v8);
        m_FirstTesselationIndex += 3;
        i += 3;
        if ( i >= nodeInfo->m_Count )
          break;
        v15 = isShadow_3;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BDD00
// Name: public: virtual bool CDispInfo::ComputeShadowFragments(unsigned short,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
char __userpurge CDispInfo::ComputeShadowFragments@<al>(
        CDispInfo *this@<ecx>,
        int a2@<ebp>,
        unsigned __int16 h,
        int *vertexCount,
        int *indexCount)
{
  UtlLinkedListElem_t<CDispShadowDecal,unsigned short> *v5; // esi
  const VMatrix *v7; // edi
  float v8; // xmm0_4
  CDispInfo *v9; // edi
  int m_nVerts; // ecx
  _BYTE v11[12]; // [esp-Ch] [ebp-2DCh] BYREF
  Frustum_t shadowFrustum; // [esp+0h] [ebp-2D0h] BYREF
  unsigned __int16 pIntersectingNodes[85]; // [esp+148h] [ebp-188h] BYREF
  VMatrix normalizedWorldToShadow; // [esp+1F8h] [ebp-D8h] BYREF
  VMatrix shadowToWorld; // [esp+238h] [ebp-98h] BYREF
  VMatrix matZScale; // [esp+278h] [ebp-58h] BYREF
  CDispInfo *v17; // [esp+2BCh] [ebp-14h]
  int v18[3]; // [esp+2C0h] [ebp-10h] BYREF
  int retaddr; // [esp+2D0h] [ebp+0h]

  v18[1] = a2;
  v18[2] = retaddr;
  v17 = this;
  v5 = &s_DispShadowDecals.m_Memory.m_pMemory[h];
  if ( (v5->m_Element.m_Flags & 8) != 0 )
  {
    *vertexCount = v5->m_Element.m_nVerts;
    *indexCount = 3 * v5->m_Element.m_nTris;
    return 1;
  }
  else
  {
    v7 = (const VMatrix *)((int (__cdecl *)(_DWORD))g_pShadowMgr->GetInfo)(a1: v5->m_Element.m_Shadow);
    v17 = (CDispInfo *)&matZScale.m[3][2];
    *(_QWORD *)&matZScale.m[3][2] = 0x3F8000003F800000LL;
    v8 = 1.0 / v7[1].m[0][1];
    v18[0] = 0;
    SetupMatrixScale(result: (VMatrix *)LODWORD(v8), vScale: (const Vector *)&matZScale.m[3][2]);
    MatrixMultiply(src1: (VMatrix *)&shadowToWorld.m[3][1], src2: v7, dst: (VMatrix *)&pIntersectingNodes[82]);
    Frustum_t::Frustum_t(this: (Frustum_t *)v11);
    MatrixInverseGeneral(
      src: (const VMatrix *)&pIntersectingNodes[82],
      dst: (VMatrix *)&normalizedWorldToShadow.m[3][1]);
    FrustumPlanesFromMatrix(clipToWorld: (VMatrix *)&normalizedWorldToShadow.m[3][1], frustum: (Frustum_t *)v11);
    v9 = v17;
    CDispInfo::FindNodesInShadowFrustum(
      this: v17,
      frustum: (const Frustum_t *)v11,
      pNodeArray: &shadowFrustum.planes[1].nZAbs.m128_u16[6],
      pNumNodes: v18,
      iNodeBit: 0,
      iLevel: 0);
    if ( v18[0] != 0 )
    {
      CDispInfo::AddNodeTrisToDecal(
        this: v9,
        pDispDecal: &v5->m_Element,
        decalHandle: h,
        pNodeIndices: &shadowFrustum.planes[1].nZAbs.m128_u16[6],
        nNumIndices: v18[0]);
      m_nVerts = v5->m_Element.m_nVerts;
      v5->m_Element.m_Flags |= 8u;
      *vertexCount = m_nVerts;
      *indexCount = 3 * v5->m_Element.m_nTris;
      return 1;
    }
    else
    {
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BDE60
// Name: void DispInfo_DrawPrimLists(class IMatRenderContext __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall DispInfo_DrawPrimLists(
        int a1@<ebx>,
        int m_LightmapPageID@<edi>,
        IMaterial *a3@<esi>,
        IMatRenderContext *pRenderContext,
        bool bShadowDepth)
{
  int v5; // eax
  CDispGroup *v6; // edi
  int v7; // ebx
  IMaterial *v8; // esi
  IMaterialVar *v9; // ebx
  IMaterialVar *v10; // ecx
  IMaterialVar_vtbl *v11; // edx
  int v12; // eax
  int v13; // eax
  IMatRenderContext *v14; // ebx
  int v15; // edx
  int v16; // ecx
  CGroupMesh *v17; // esi
  int m_nVisible; // eax
  int v19; // ebx
  float v23; // [esp+0h] [ebp-24h]
  int m_Size; // [esp+4h] [ebp-20h]
  int nFullbright; // [esp+8h] [ebp-1Ch]
  int v26; // [esp+Ch] [ebp-18h]
  int v27; // [esp+Ch] [ebp-18h]
  int v28; // [esp+10h] [ebp-14h]
  int v29; // [esp+14h] [ebp-10h]
  IMaterialVar *v30; // [esp+18h] [ebp-Ch]
  void (__thiscall **p_SetTextureValue)(IMaterialVar *, int); // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]
  int v33; // [esp+20h] [ebp-4h]
  int j; // [esp+20h] [ebp-4h]

  v5 = 0;
  m_Size = g_DispGroups.m_Size;
  nFullbright = g_pMaterialSystemConfig->nFullbright;
  for ( i = 0; v5 < m_Size; i = v5 )
  {
    v6 = g_DispGroups.m_Memory.m_pMemory[v5];
    if ( v6->m_nVisible != 0 )
    {
      if ( bShadowDepth )
      {
        v7 = ((unsigned __int8 (__thiscall *)(IMaterial *, int, IMaterial *, int))v6->m_pMaterial->IsAlphaTested)(
               a1: v6->m_pMaterial,
               a2: m_LightmapPageID,
               a3,
               a4: a1);
        v8 = g_pMaterialDepthWrite[v7][(unsigned __int8)v6->m_pMaterial->IsTwoSided(this: v6->m_pMaterial)];
        if ( v7 == 1 )
        {
          v30 = v6->m_pMaterial->FindVarFast(this: v6->m_pMaterial, a2: "$basetexture", a3: &originalTextureVarCache_1);
          v28 = (int)v6->m_pMaterial->FindVarFast(
                       this: v6->m_pMaterial,
                       a2: "$frame",
                       a3: &originalTextureFrameVarCache_1);
          v26 = (int)v6->m_pMaterial->FindVarFast(
                       this: v6->m_pMaterial,
                       a2: "$AlphaTestReference",
                       a3: &originalAlphaRefCache_1);
          v9 = v8->FindVarFast(this: v8, a2: "$basetexture", a3: &textureVarCache_1);
          v29 = (int)v8->FindVarFast(this: v8, a2: "$frame", a3: &textureFrameVarCache_1);
          v33 = (int)v8->FindVarFast(this: v8, a2: "$AlphaTestReference", a3: &alphaRefCache_1);
          if ( v9 != nullptr )
          {
            v10 = v30;
            if ( v30 != nullptr )
            {
              v11 = v30->__vftable;
              p_SetTextureValue = (void (__thiscall **)(IMaterialVar *, int))&v9->SetTextureValue;
              v12 = (int)v11->GetTextureValue(this: v10);
              (*p_SetTextureValue)(a1: v9, a2: v12);
            }
          }
          if ( v29 != 0 && v28 != 0 )
          {
            v13 = (*(int (__thiscall **)(int))(*(_DWORD *)v28 + 108))(a1: v28);
            (*(void (__thiscall **)(int, int))(*(_DWORD *)v29 + 20))(a1: v29, a2: v13);
          }
          if ( v33 != 0 && v26 != 0 )
          {
            v23 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v26 + 112))(a1: v26);
            (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v33 + 16))(a1: LODWORD(v23));
          }
        }
        v14 = pRenderContext;
        a1 = 0;
        a3 = v8;
        ((void (__thiscall *)(IMatRenderContext *))pRenderContext->Bind)(a1: pRenderContext);
      }
      else
      {
        ((void (__thiscall *)(IMatRenderContext *, IMaterial *, _DWORD, int))pRenderContext->Bind)(
          a1: pRenderContext,
          a2: v6->m_pMaterial,
          a3: 0,
          a4: m_LightmapPageID);
        v14 = pRenderContext;
      }
      if ( nFullbright == 1 || bShadowDepth )
      {
        if ( v6->m_pMaterial->GetPropertyFlag(this: v6->m_pMaterial, a2: MATERIAL_PROPERTY_NEEDS_BUMPED_LIGHTMAPS) )
          m_LightmapPageID = -2;
        else
          m_LightmapPageID = -1;
      }
      else
      {
        m_LightmapPageID = v6->m_LightmapPageID;
      }
      ((void (__thiscall *)(IMatRenderContext *))v14->BindLightmapPage)(a1: v14);
      v15 = v6->m_Meshes.m_Size;
      v16 = 0;
      v27 = v15;
      for ( j = 0; v16 < v15; j = v16 )
      {
        v17 = v6->m_Meshes.m_Memory.m_pMemory[v16];
        m_nVisible = v17->m_nVisible;
        if ( m_nVisible != 0 )
        {
          if ( disp_dynamic.m_pParent != nullptr && disp_dynamic.m_pParent->m_Value.m_nValue != 0 )
          {
            v19 = 0;
            if ( m_nVisible > 0 )
            {
              do
                CDispInfo::SpecifyDynamicMesh(this: v17->m_VisibleDisps.m_Memory.m_pMemory[v19++]);
              while ( v19 < v17->m_nVisible );
            }
          }
          else
          {
            v17->m_pMesh->Draw(this: v17->m_pMesh, a2: v17->m_Visible.m_Memory.m_pMemory, a3: v17->m_nVisible);
          }
          v16 = j;
          v15 = v27;
          v17->m_nVisible = 0;
        }
        ++v16;
      }
    }
    v5 = i + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BE0B0
// Name: void DispInfo_RenderListWorld(class IMatRenderContext __near *,int,struct msurface2_t __near * __near *,int,bool,unsigned long,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall DispInfo_RenderListWorld(
        int a1@<ebx>,
        int a2@<edi>,
        IMatRenderContext *pRenderContext,
        int nSortGroup,
        msurface2_t **pList,
        int listCount,
        bool bOrtho,
        __int16 flags,
        IMaterial *bShadowDepth)
{
  CDispInfo *visibleDisps; // [esp+0h] [ebp-2004h] BYREF
  int nVisibleDisps; // [esp+2000h] [ebp-4h] BYREF

  if ( r_DrawDisp.m_pParent != nullptr
    && r_DrawDisp.m_pParent->m_Value.m_nValue != 0
    && listCount != 0
    && (flags & 0x200) != 0 )
  {
    g_bDispOrthoRender = bOrtho;
    DispInfo_BuildPrimLists(nSortGroup, pList, listCount, bDepthOnly: (bool)bShadowDepth, &visibleDisps, &nVisibleDisps);
    DispInfo_DrawPrimLists(a1, m_LightmapPageID: a2, a3: bShadowDepth, pRenderContext, (bool)bShadowDepth);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BEBD0
// Name: int DispInfo_AddShadowsToMeshBuilder(class CMeshBuilder __near &,unsigned short,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DispInfo_AddShadowsToMeshBuilder(CMeshBuilder *meshBuilder, unsigned __int16 h, int baseIndex)
{
  UtlLinkedListElem_t<CDispShadowDecal,unsigned short> *v3; // esi
  unsigned __int16 m_FirstFragment; // ax
  int v6; // edx
  UtlLinkedListElem_t<CDispShadowFragment,unsigned short> *m_pMemory; // ecx
  unsigned int m_nIndexSize; // ebx
  int v9; // eax
  ShadowVertex_t *m_ShadowVerts; // edi
  const CDispShadowFragment *p_m_Element; // eax
  int v12; // eax
  unsigned __int16 *v13; // eax
  unsigned __int16 *m_pIndices; // ecx
  __int16 v15; // bx
  unsigned __int16 v16; // cx
  int v17; // ecx
  int v18; // ebx
  float *p_z; // eax
  float *v20; // ecx
  float v21; // xmm1_4
  float v22; // xmm2_4
  float y; // xmm0_4
  float v24; // xmm0_4
  int v25; // ebx
  int v26; // xmm1_4
  float *v27; // ecx
  float *v28; // ecx
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm0_4
  float v32; // xmm0_4
  int v33; // xmm1_4
  float *v34; // ecx
  Vector *v35; // ecx
  unsigned __int16 *v36; // ebx
  float *v37; // ecx
  float v38; // xmm1_4
  float v39; // xmm2_4
  float v40; // xmm0_4
  float v41; // xmm0_4
  double v42; // st7
  int v43; // xmm1_4
  float *v44; // ecx
  Vector *v45; // ecx
  float *v46; // ecx
  float v47; // xmm1_4
  float v48; // xmm2_4
  float v49; // xmm0_4
  float v50; // xmm0_4
  int v51; // xmm1_4
  float *v52; // ecx
  float *v53; // ecx
  unsigned __int16 *v54; // ebx
  bool v55; // zf
  int v56; // ebx
  float *v57; // ecx
  float *v58; // eax
  float v59; // xmm1_4
  float v60; // xmm2_4
  float v61; // xmm0_4
  float v62; // xmm0_4
  double v63; // st7
  int v64; // xmm1_4
  float *v65; // eax
  Vector *v66; // eax
  float *v67; // eax
  float v68; // xmm1_4
  float v69; // xmm2_4
  float v70; // xmm0_4
  float v71; // xmm0_4
  float z; // xmm1_4
  float *v73; // eax
  Vector *v74; // eax
  int v75; // edx
  float *v76; // eax
  float v77; // xmm1_4
  float v78; // xmm2_4
  float v79; // xmm0_4
  float v80; // xmm0_4
  float v81; // xmm1_4
  float *v82; // eax
  Vector *v83; // eax
  int m_nCurrentIndex; // eax
  ShadowDecalRenderInfo_t info; // [esp+4h] [ebp-40h] BYREF
  int v87; // [esp+30h] [ebp-14h]
  const CDispShadowFragment *fragment; // [esp+34h] [ebp-10h]
  unsigned int v89; // [esp+38h] [ebp-Ch]
  int i; // [esp+3Ch] [ebp-8h]
  unsigned __int16 *v91; // [esp+40h] [ebp-4h]
  int nIndices; // [esp+4Ch] [ebp+8h]
  int triangleCount; // [esp+50h] [ebp+Ch]

  v3 = &s_DispShadowDecals.m_Memory.m_pMemory[h];
  ((void (__stdcall *)(ShadowDecalRenderInfo_t *, _DWORD))g_pShadowMgr->ComputeRenderInfo)(
    a1: &info,
    a2: v3->m_Element.m_Shadow);
  m_FirstFragment = v3->m_Element.m_FirstFragment;
  v6 = 0;
  nIndices = 0;
  if ( m_FirstFragment != 0xFFFF )
  {
    m_pMemory = s_DispShadowFragments.m_Memory.m_pMemory;
    do
    {
      m_nIndexSize = meshBuilder->m_IndexBuilder.m_nIndexSize;
      v9 = m_FirstFragment;
      m_ShadowVerts = m_pMemory[v9].m_Element.m_ShadowVerts;
      v87 = v9 * 12;
      p_m_Element = &m_pMemory[v9].m_Element;
      m_pIndices = meshBuilder->m_IndexBuilder.m_pIndices;
      fragment = p_m_Element;
      triangleCount = p_m_Element->m_nVerts - 2;
      v12 = nIndices + meshBuilder->m_IndexBuilder.m_nCurrentIndex;
      i = triangleCount * m_nIndexSize;
      v13 = &m_pIndices[v12];
      v89 = baseIndex + meshBuilder->m_IndexBuilder.m_nIndexOffset;
      LOWORD(m_pIndices) = 0;
      v91 = nullptr;
      if ( (int)(triangleCount * m_nIndexSize) > 0 )
      {
        do
        {
          v15 = v89;
          v16 = v89 + (_WORD)m_pIndices + 1;
          *v13 = v89;
          v13[1] = v16;
          v13[2] = v15 + (_WORD)v91 + 2;
          m_pIndices = (unsigned __int16 *)((char *)v91 + 1);
          v13 += 3;
          v91 = m_pIndices;
        }
        while ( (int)m_pIndices < i );
      }
      v17 = triangleCount;
      nIndices += triangleCount + 2 * triangleCount;
      i = 0;
      if ( triangleCount >= 4 )
      {
        v89 = ((unsigned int)(triangleCount - 4) >> 2) + 1;
        v18 = v6 + 2;
        v91 = (unsigned __int16 *)(v6 + 2);
        p_z = &m_ShadowVerts[2].m_Position.z;
        i = 4 * v89;
        do
        {
          v20 = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                        + v6 * meshBuilder->m_VertexBuilder.m_VertexSize_Position);
          v21 = *(p_z - 10) * info.m_vTexSize.y;
          v22 = info.m_vTexOrigin.x + (float)(*(p_z - 11) * info.m_vTexSize.x);
          y = info.m_vTexOrigin.y;
          *v20 = m_ShadowVerts->m_Position.x;
          v24 = y + v21;
          v20[1] = *(p_z - 13);
          v25 = v18 - 1;
          v20[2] = *(p_z - 12);
          v26 = *((_DWORD *)p_z - 9);
          v27 = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0]
                        + v6 * meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[0]);
          *v27 = v22;
          v27[1] = v24;
          *((_DWORD *)v27 + 2) = v26;
          *(Vector *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1]
                    + v6 * meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[1]) = info.m_vShadowFalloffParams;
          v28 = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                        + v25 * meshBuilder->m_VertexBuilder.m_VertexSize_Position);
          v29 = *(p_z - 4) * info.m_vTexSize.y;
          v30 = info.m_vTexOrigin.x + (float)(*(p_z - 5) * info.m_vTexSize.x);
          v31 = info.m_vTexOrigin.y;
          *v28 = *(p_z - 8);
          v32 = v31 + v29;
          v28[1] = *(p_z - 7);
          v28[2] = *(p_z - 6);
          v33 = *((_DWORD *)p_z - 3);
          v34 = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0]
                        + v25 * meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[0]);
          *v34 = v30;
          v34[1] = v32;
          *((_DWORD *)v34 + 2) = v33;
          v35 = (Vector *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1]
                         + v25 * meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[1]);
          v36 = v91;
          *v35 = info.m_vShadowFalloffParams;
          v37 = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                        + (_DWORD)v36 * meshBuilder->m_VertexBuilder.m_VertexSize_Position);
          v38 = p_z[2] * info.m_vTexSize.y;
          v39 = info.m_vTexOrigin.x + (float)(p_z[1] * info.m_vTexSize.x);
          v40 = info.m_vTexOrigin.y;
          *v37 = *(p_z - 2);
          v41 = v40 + v38;
          v6 += 4;
          v37[1] = *(p_z - 1);
          m_ShadowVerts += 4;
          v42 = *p_z;
          p_z += 24;
          v37[2] = v42;
          v43 = *((_DWORD *)p_z - 21);
          v44 = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0]
                        + (_DWORD)v36 * meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[0]);
          *v44 = v39;
          v44[1] = v41;
          *((_DWORD *)v44 + 2) = v43;
          v45 = (Vector *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1]
                         + (_DWORD)v36 * meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[1]);
          v36 = (unsigned __int16 *)((char *)v36 + 1);
          *v45 = info.m_vShadowFalloffParams;
          v46 = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                        + (_DWORD)v36 * meshBuilder->m_VertexBuilder.m_VertexSize_Position);
          v47 = *(p_z - 16) * info.m_vTexSize.y;
          v48 = info.m_vTexOrigin.x + (float)(*(p_z - 17) * info.m_vTexSize.x);
          v49 = info.m_vTexOrigin.y;
          *v46 = *(p_z - 20);
          v50 = v49 + v47;
          v46[1] = *(p_z - 19);
          v46[2] = *(p_z - 18);
          v51 = *((_DWORD *)p_z - 15);
          v52 = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0]
                        + (_DWORD)v36 * meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[0]);
          *v52 = v48;
          v52[1] = v50;
          *((_DWORD *)v52 + 2) = v51;
          v53 = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1]
                        + (_DWORD)v36 * meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[1]);
          v54 = v91;
          *v53 = info.m_vShadowFalloffParams.x;
          v53[1] = info.m_vShadowFalloffParams.y;
          v18 = (int)(v54 + 2);
          v55 = v89-- == 1;
          v53[2] = info.m_vShadowFalloffParams.z;
          v91 = (unsigned __int16 *)v18;
        }
        while ( !v55 );
        v17 = triangleCount;
      }
      if ( i < v17 )
      {
        v56 = triangleCount - i;
        v57 = &m_ShadowVerts->m_Position.z;
        do
        {
          v58 = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                        + v6 * meshBuilder->m_VertexBuilder.m_VertexSize_Position);
          v59 = v57[2] * info.m_vTexSize.y;
          v60 = info.m_vTexOrigin.x + (float)(v57[1] * info.m_vTexSize.x);
          v61 = info.m_vTexOrigin.y;
          *v58 = m_ShadowVerts->m_Position.x;
          v62 = v61 + v59;
          v58[1] = *(v57 - 1);
          ++m_ShadowVerts;
          v63 = *v57;
          v57 += 6;
          v58[2] = v63;
          v64 = *((_DWORD *)v57 - 3);
          v65 = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0]
                        + v6 * meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[0]);
          *v65 = v60;
          v65[1] = v62;
          *((_DWORD *)v65 + 2) = v64;
          v66 = (Vector *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1]
                         + v6 * meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[1]);
          ++v6;
          --v56;
          *v66 = info.m_vShadowFalloffParams;
        }
        while ( v56 != 0 );
      }
      v67 = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                    + v6 * meshBuilder->m_VertexBuilder.m_VertexSize_Position);
      v68 = m_ShadowVerts->m_ShadowSpaceTexCoord.y * info.m_vTexSize.y;
      v69 = info.m_vTexOrigin.x + (float)(m_ShadowVerts->m_ShadowSpaceTexCoord.x * info.m_vTexSize.x);
      v70 = info.m_vTexOrigin.y;
      *v67 = m_ShadowVerts->m_Position.x;
      v71 = v70 + v68;
      v67[1] = m_ShadowVerts->m_Position.y;
      v67[2] = m_ShadowVerts->m_Position.z;
      z = m_ShadowVerts->m_ShadowSpaceTexCoord.z;
      v73 = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0]
                    + v6 * meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[0]);
      *v73 = v69;
      v73[1] = v71;
      v73[2] = z;
      v74 = (Vector *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1]
                     + v6 * meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[1]);
      v75 = v6 + 1;
      *v74 = info.m_vShadowFalloffParams;
      v76 = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                    + v75 * meshBuilder->m_VertexBuilder.m_VertexSize_Position);
      v77 = m_ShadowVerts[1].m_ShadowSpaceTexCoord.y * info.m_vTexSize.y;
      v78 = info.m_vTexOrigin.x + (float)(m_ShadowVerts[1].m_ShadowSpaceTexCoord.x * info.m_vTexSize.x);
      v79 = info.m_vTexOrigin.y;
      *v76 = m_ShadowVerts[1].m_Position.x;
      v80 = v79 + v77;
      v76[1] = m_ShadowVerts[1].m_Position.y;
      v76[2] = m_ShadowVerts[1].m_Position.z;
      v81 = m_ShadowVerts[1].m_ShadowSpaceTexCoord.z;
      v82 = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0]
                    + v75 * meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[0]);
      *v82 = v78;
      v82[1] = v80;
      v82[2] = v81;
      v83 = (Vector *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1]
                     + v75 * meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[1]);
      v6 = v75 + 1;
      *v83 = info.m_vShadowFalloffParams;
      baseIndex += fragment->m_nVerts;
      m_pMemory = s_DispShadowFragments.m_Memory.m_pMemory;
      m_FirstFragment = *(unsigned __int16 *)((char *)&s_DispShadowFragments.m_Memory.m_pMemory->m_Next + v87);
    }
    while ( m_FirstFragment != 0xFFFF );
  }
  CVertexBuilder::AdvanceVertices(this: &meshBuilder->m_VertexBuilder, nVerts: v6);
  meshBuilder->m_IndexBuilder.m_nCurrentIndex += nIndices * meshBuilder->m_IndexBuilder.m_nIndexSize;
  m_nCurrentIndex = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
  if ( m_nCurrentIndex > meshBuilder->m_IndexBuilder.m_nIndexCount )
    meshBuilder->m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
  return baseIndex;
}

//------------------------------------------------------------------------------
// Address: 0x100BF1A0
// Name: DispInfo_DrawChainNormals
// Source: json
//------------------------------------------------------------------------------
void __usercall DispInfo_DrawChainNormals(
        CMeshBuilder *p_meshBuilder@<edi>,
        IMatRenderContext *pRenderContext,
        msurface2_t **pList,
        int listCount)
{
  IMatRenderContext *v4; // esi
  IMatRenderContext_vtbl *v5; // edx
  int v6; // edi
  IMesh *(__thiscall *GetDynamicMesh)(IMatRenderContext *, bool, IMesh *, IMesh *, IMaterial *); // eax
  IMesh *v8; // esi
  void (__thiscall *SetPrimitiveType)(IMesh *, MaterialPrimitiveType_t); // eax
  int m_nVertexCount; // edx
  float *m_pPosition; // eax
  int v12; // edi
  CDispRenderVert *m_pMemory; // esi
  double x; // st7
  float *p_x; // esi
  float *m_pCurrPosition; // eax
  float v17; // xmm1_4
  float v18; // xmm2_4
  float *v19; // eax
  float *v20; // eax
  float v21; // xmm1_4
  float v22; // xmm2_4
  float *v23; // eax
  float v24; // xmm1_4
  float v25; // xmm2_4
  float *v26; // eax
  int v27; // eax
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1FCh] BYREF
  CDispInfo *pDisp; // [esp+1F0h] [ebp-14h]
  IMesh *pMesh; // [esp+1F4h] [ebp-10h]
  int nVerts; // [esp+1F8h] [ebp-Ch]
  int i; // [esp+1FCh] [ebp-8h]
  int v34; // [esp+200h] [ebp-4h]

  v4 = pRenderContext;
  pRenderContext->Bind(this: pRenderContext, a2: g_pMaterialWireframeVertexColor, a3: nullptr);
  i = 0;
  if ( listCount > 0 )
  {
    while ( 1 )
    {
      v5 = v4->__vftable;
      pDisp = (CDispInfo *)pList[i]->pDispInfo;
      GetDynamicMesh = v5->GetDynamicMesh;
      nVerts = pDisp->m_pPowerInfo->m_MaxVerts;
      v6 = nVerts;
      v8 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, CMeshBuilder *))GetDynamicMesh)(
                      a1: v4,
                      a2: 1,
                      a3: 0,
                      a4: 0,
                      a5: 0,
                      a6: p_meshBuilder);
      meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
      meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
      meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
      memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
      meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
      meshBuilder.m_pMesh = v8;
      meshBuilder.m_bGenerateIndices = true;
      meshBuilder.m_Type = MATERIAL_LINES;
      v6 *= 6;
      SetPrimitiveType = v8->SetPrimitiveType;
      pMesh = v8;
      v34 = v6;
      SetPrimitiveType(this: v8, a2: MATERIAL_LINES);
      meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v6, a3: v6, a4: &meshBuilder, a5: nullptr);
      meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v8->IIndexBuffer;
      meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v6;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = v8;
      meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_bModify = false;
      meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
      meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
      meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
      m_nVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = v34;
      meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_bModify = false;
      if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
      {
        meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
        meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
      }
      meshBuilder.m_VertexBuilder.m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pNormal;
      qmemcpy(
        meshBuilder.m_VertexBuilder.m_pCurrTexCoord,
        meshBuilder.m_VertexBuilder.m_pTexCoord,
        sizeof(meshBuilder.m_VertexBuilder.m_pCurrTexCoord));
      m_pPosition = meshBuilder.m_VertexBuilder.m_pPosition;
      meshBuilder.m_VertexBuilder.m_pCurrColor = meshBuilder.m_VertexBuilder.m_pColor;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      meshBuilder.m_VertexBuilder.m_nCurrentVertex = 0;
      meshBuilder.m_VertexBuilder.m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pPosition;
      if ( nVerts > 0 )
      {
        v12 = 0;
        v34 = nVerts;
        while ( 1 )
        {
          m_pMemory = pDisp->m_Verts.m_Memory.m_pMemory;
          x = m_pMemory[v12].m_vPos.x;
          p_x = &m_pMemory[v12].m_vPos.x;
          *m_pPosition = x;
          m_pPosition[1] = p_x[1];
          m_pPosition[2] = p_x[2];
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          v17 = (float)(p_x[4] * 5.0) + p_x[1];
          v18 = (float)(p_x[5] * 5.0) + p_x[2];
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(p_x[3] * 5.0) + *p_x;
          m_pCurrPosition[1] = v17;
          m_pCurrPosition[2] = v18;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v19 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = *p_x;
          v19[1] = p_x[1];
          v19[2] = p_x[2];
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v20 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          v21 = (float)(p_x[7] * 5.0) + p_x[1];
          v22 = (float)(p_x[8] * 5.0) + p_x[2];
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(p_x[6] * 5.0) + *p_x;
          v20[1] = v21;
          v20[2] = v22;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v23 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = *p_x;
          v23[1] = p_x[1];
          v23[2] = p_x[2];
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v24 = (float)(p_x[10] * 5.0) + p_x[1];
          v25 = (float)(p_x[11] * 5.0) + p_x[2];
          v26 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(p_x[9] * 5.0) + *p_x;
          v26[1] = v24;
          v26[2] = v25;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          ++v12;
          if ( --v34 == 0 )
            break;
          m_pPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        }
        m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
      }
      if ( meshBuilder.m_bGenerateIndices )
      {
        switch ( meshBuilder.m_Type )
        {
          case MATERIAL_LINE_STRIP:
            v27 = 2 * m_nVertexCount - 2;
            break;
          case MATERIAL_LINE_LOOP:
            v27 = 2 * m_nVertexCount;
            break;
          case MATERIAL_POLYGON:
            v27 = 3 * m_nVertexCount - 6;
            break;
          case MATERIAL_QUADS:
            v27 = 6 * m_nVertexCount / 4;
            break;
          case MATERIAL_INSTANCED_QUADS:
            v27 = 0;
            break;
          default:
            v27 = m_nVertexCount;
            break;
        }
        CIndexBuilder::GenerateIndices(
          this: &meshBuilder.m_IndexBuilder,
          primitiveType: meshBuilder.m_Type,
          nIndexCount: v27);
        m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
      }
      p_meshBuilder = &meshBuilder;
      ((void (__thiscall *)(IMesh *, int, int))meshBuilder.m_pMesh->UnlockMesh)(
        a1: meshBuilder.m_pMesh,
        a2: m_nVertexCount,
        a3: meshBuilder.m_IndexBuilder.m_nIndexCount);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      meshBuilder.m_pMesh = nullptr;
      pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
      if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
        && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
      {
        meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
      }
      if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
        && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
      {
        meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
      }
      if ( ++i >= listCount )
        break;
      v4 = pRenderContext;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BF650
// Name: void DispInfo_RenderListDebug(class IMatRenderContext __near *,struct msurface2_t __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispInfo_RenderListDebug(IMatRenderContext *pRenderContext, msurface2_t **pList, CMeshBuilder *listCount)
{
  CMeshBuilder *i; // esi
  CDispInfo *pDispInfo; // ecx

  if ( DispInfoRenderDebugModes() )
  {
    for ( i = nullptr; (int)i < (int)listCount; i = (CMeshBuilder *)((char *)i + 1) )
    {
      pDispInfo = (CDispInfo *)pList[(_DWORD)i]->pDispInfo;
      CDispInfo::Render(this: pDispInfo, pGroup: pDispInfo->m_pMesh, bAllowDebugModes: true);
    }
  }
  if ( mat_normals.m_pParent != nullptr && mat_normals.m_pParent->m_Value.m_nValue != 0 )
    DispInfo_DrawChainNormals(p_meshBuilder: listCount, pRenderContext, pList, (int)listCount);
}

//------------------------------------------------------------------------------
// Address: 0x100BF920
// Name: void DispInfo_BatchDecals(class CDispInfo __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispInfo_BatchDecals(CDispInfo **pVisibleDisps, int nVisibleDisps)
{
  int v2; // edi
  int v3; // esi
  UtlLinkedListElem_t<CDispDecal,unsigned short> *m_pMemory; // ecx
  CDispInfo *v5; // edx
  unsigned __int16 m_FirstDecal; // ax
  int v7; // edi
  int v8; // ebx
  UtlLinkedListElem_t<CDispDecal,unsigned short> *v9; // esi
  IMaterial *material; // ecx
  int v11; // edi
  decal_t **v12; // eax
  decal_t *m_pDecal; // esi
  int m_iSortTree; // ecx
  int m_iSortMaterial; // esi
  DecalMaterialBucket_t *v16; // ecx
  int m_nCheckCount; // edx
  int *p_m_iHead; // esi
  decal_t **v19; // [esp+4h] [ebp-Ch]
  CDispInfo *pDisp; // [esp+8h] [ebp-8h]
  int iDisp; // [esp+Ch] [ebp-4h]

  CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::RemoveAll(this: &g_aDispDecalSortPool);
  v2 = nVisibleDisps;
  ++g_nDispDecalSortCheckCount;
  if ( nVisibleDisps != 0 )
  {
    v3 = 0;
    iDisp = 0;
    if ( nVisibleDisps > 0 )
    {
      m_pMemory = s_DispDecals.m_Memory.m_pMemory;
      do
      {
        v5 = pVisibleDisps[v3];
        m_FirstDecal = v5->m_FirstDecal;
        pDisp = v5;
        if ( m_FirstDecal != 0xFFFF )
        {
          while ( 1 )
          {
            v7 = m_FirstDecal;
            v8 = m_FirstDecal;
            v9 = &m_pMemory[m_FirstDecal];
            if ( (v9->m_Element.m_Flags & 8) == 0 )
            {
              CDispInfo::GenerateDecalFragments_R(
                this: v5,
                nodeIndex: &v5->m_pPowerInfo->m_RootNode,
                iNodeBitIndex: nullptr,
                decalHandle: m_FirstDecal,
                pDispDecal: (CDispShadowDecal *)v9,
                iLevel: 0);
              v9->m_Element.m_Flags |= 8u;
              m_pMemory = s_DispDecals.m_Memory.m_pMemory;
            }
            if ( v9->m_Element.m_nTris != 0 )
            {
              material = v9->m_Element.m_pDecal->material;
              if ( material != nullptr )
              {
                if ( material->GetPropertyFlag(this: material, a2: MATERIAL_PROPERTY_NEEDS_LIGHTMAP) )
                  v11 = (v9->m_Element.m_pDecal->flags & 1) == 0;
                else
                  v11 = 2;
                v12 = (decal_t **)CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int>>>::AllocInternal(
                                    this: &g_aDispDecalSortPool,
                                    multilist: true);
                *v12 = v9->m_Element.m_pDecal;
                m_pDecal = v9->m_Element.m_pDecal;
                m_iSortTree = m_pDecal->m_iSortTree;
                m_iSortMaterial = m_pDecal->m_iSortMaterial;
                v16 = g_aDispDecalSortTrees.m_Memory.m_pMemory[m_iSortTree].m_aDecalSortBuckets[0][v11].m_Memory.m_pMemory;
                m_nCheckCount = v16[m_iSortMaterial].m_nCheckCount;
                p_m_iHead = &v16[m_iSortMaterial].m_iHead;
                v19 = v12;
                if ( m_nCheckCount == g_nDispDecalSortCheckCount )
                {
                  CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::LinkBefore(
                    this: &g_aDispDecalSortPool,
                    before: *p_m_iHead,
                    elem: (int)v12);
                  v12 = v19;
                }
                *p_m_iHead = (int)v12;
                p_m_iHead[1] = g_nDispDecalSortCheckCount;
              }
              else
              {
                DevMsg(a1: "DispInfo_BatchDecals: material is NULL, decal %i.\n", v7);
              }
              m_pMemory = s_DispDecals.m_Memory.m_pMemory;
            }
            m_FirstDecal = m_pMemory[v8].m_Next;
            if ( m_FirstDecal == 0xFFFF )
              break;
            v5 = pDisp;
          }
          v3 = iDisp;
          v2 = nVisibleDisps;
        }
        iDisp = ++v3;
      }
      while ( v3 < v2 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BFAA0
// Name: void DispInfo_DrawDecalMeshList(class IMatRenderContext __near *,struct DecalMeshList_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispInfo_DrawDecalMeshList(IMatRenderContext *pRenderContext, DecalMeshList_t *meshList)
{
  char *v3; // esi
  bool bMatFullbright; // [esp+7h] [ebp-1h]
  DecalMeshList_t *meshLista; // [esp+14h] [ebp+Ch]

  bMatFullbright = g_pMaterialSystemConfig->nFullbright == 1;
  if ( meshList->m_aBatches.m_Size > 0 )
  {
    v3 = &meshList->m_aBatches.m_Memory.m_Memory[4];
    meshLista = (DecalMeshList_t *)meshList->m_aBatches.m_Size;
    do
    {
      if ( bMatFullbright )
        ((void (__stdcall *)(int))pRenderContext->BindLightmapPage)(a1: -1);
      else
        ((void (__stdcall *)(_DWORD))pRenderContext->BindLightmapPage)(a1: *((_DWORD *)v3 + 1));
      pRenderContext->Bind(this: pRenderContext, a2: *((IMaterial **)v3 - 1), a3: *(void **)v3);
      ((void (__stdcall *)(_DWORD, _DWORD))meshList->m_pMesh->Draw_2)(
        a1: *((unsigned __int16 *)v3 + 4),
        a2: *((unsigned __int16 *)v3 + 5));
      v3 += 16;
      meshLista = (DecalMeshList_t *)((char *)meshLista - 1);
    }
    while ( meshLista != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BFD60
// Name: private: class CDispDecalFragment __near * CDispInfo::AllocateDispDecalFragment(unsigned short,int)
// Source: json
//------------------------------------------------------------------------------
UtlLinkedListElem_t<CDispDecalFragment,unsigned short> *__thiscall CDispInfo::AllocateDispDecalFragment(
        CDispInfo *this,
        unsigned __int16 h,
        int nVerts)
{
  unsigned __int16 v3; // ax
  unsigned __int16 v4; // di
  UtlLinkedListElem_t<CDispDecalFragment,unsigned short> *v5; // esi

  v3 = CUtlLinkedList<CDispDecalFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecalFragment,unsigned short>,unsigned short>>::AllocInternal(
         this: &s_DispDecalFragments,
         multilist: true);
  v4 = -1;
  if ( v3 != 0xFFFF )
    v4 = v3;
  CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::LinkBefore(
    this: &s_DispDecalFragments,
    before: s_DispDecals.m_Memory.m_pMemory[h].m_Element.m_FirstFragment,
    elem: v4);
  s_DispDecals.m_Memory.m_pMemory[h].m_Element.m_FirstFragment = v4;
  v5 = &s_DispDecalFragments.m_Memory.m_pMemory[v4];
  v5->m_Element.m_nVerts = nVerts;
  v5->m_Element.m_pVerts = (CDecalVert *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)nVerts >> 27 != 0 ? -1 : 32 * nVerts);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100BFDF0
// Name: private: void CDispInfo::ClearDecalFragments(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::ClearDecalFragments(CDispInfo *this, unsigned __int16 h)
{
  UtlLinkedListElem_t<CDispDecal,unsigned short> *v2; // eax
  unsigned __int16 m_FirstFragment; // di
  int v4; // esi
  unsigned __int16 m_Next; // bx
  UtlLinkedListElem_t<CDispDecalFragment,unsigned short> *v6; // esi
  CDispDecal *decal; // [esp+Ch] [ebp+8h]

  v2 = &s_DispDecals.m_Memory.m_pMemory[h];
  m_FirstFragment = v2->m_Element.m_FirstFragment;
  decal = &v2->m_Element;
  if ( m_FirstFragment != 0xFFFF )
  {
    do
    {
      v4 = m_FirstFragment;
      m_Next = s_DispDecalFragments.m_Memory.m_pMemory[v4].m_Next;
      CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::Unlink(
        this: &s_DispDecalFragments,
        elem: m_FirstFragment);
      v6 = &s_DispDecalFragments.m_Memory.m_pMemory[v4];
      free(pMem: v6->m_Element.m_pVerts);
      v6->m_Element.m_pVerts = nullptr;
      v6->m_Next = s_DispDecalFragments.m_FirstFree;
      s_DispDecalFragments.m_FirstFree = m_FirstFragment;
      m_FirstFragment = m_Next;
    }
    while ( m_Next != 0xFFFF );
    v2 = (UtlLinkedListElem_t<CDispDecal,unsigned short> *)decal;
  }
  v2->m_Element.m_Flags &= ~8u;
  v2->m_Element.m_FirstFragment = -1;
  *(_DWORD *)&v2->m_Element.m_nVerts = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100BFE90
// Name: private: void CDispInfo::ClearAllDecalFragments(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::ClearAllDecalFragments(CDispInfo *this)
{
  unsigned __int16 i; // si

  for ( i = this->m_FirstDecal; i != 0xFFFF; i = s_DispDecals.m_Memory.m_pMemory[i].m_Next )
    CDispInfo::ClearDecalFragments(this, h: i);
}

//------------------------------------------------------------------------------
// Address: 0x100BFED0
// Name: public: virtual void CDispInfo::NotifyRemoveDecal(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::NotifyRemoveDecal(CDispInfo *this, unsigned __int16 h)
{
  CDispInfo::ClearDecalFragments(this, h);
  if ( this->m_FirstDecal == h )
    this->m_FirstDecal = s_DispDecals.m_Memory.m_pMemory[h].m_Next;
  CUtlLinkedList<CDispDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short>>::Unlink(
    this: &s_DispDecals,
    elem: h);
  s_DispDecals.m_Memory.m_pMemory[h].m_Next = s_DispDecals.m_FirstFree;
  s_DispDecals.m_FirstFree = h;
}

//------------------------------------------------------------------------------
// Address: 0x100BFF40
// Name: private: class CDispShadowFragment __near * CDispInfo::AllocateShadowDecalFragment(unsigned short,int)
// Source: json
//------------------------------------------------------------------------------
UtlLinkedListElem_t<CDispShadowFragment,unsigned short> *__thiscall CDispInfo::AllocateShadowDecalFragment(
        CDispInfo *this,
        unsigned __int16 h,
        unsigned int nCount)
{
  DWORD CurrentThreadId; // ecx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // di
  int v6; // esi
  UtlLinkedListElem_t<CDispShadowFragment,unsigned short> *v7; // esi

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != s_ShadowFragmentAllocLock.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&s_ShadowFragmentAllocLock, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &s_ShadowFragmentAllocLock, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++s_ShadowFragmentAllocLock.m_depth;
  }
  v4 = CUtlLinkedList<CDispShadowFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowFragment,unsigned short>,unsigned short>>::AllocInternal(
         this: &s_DispShadowFragments,
         multilist: true);
  v5 = -1;
  if ( v4 != 0xFFFF )
    v5 = v4;
  v6 = h;
  CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::LinkBefore(
    this: &s_DispShadowFragments,
    before: s_DispShadowDecals.m_Memory.m_pMemory[v6].m_Element.m_FirstFragment,
    elem: v5);
  s_DispShadowDecals.m_Memory.m_pMemory[v6].m_Element.m_FirstFragment = v5;
  v7 = &s_DispShadowFragments.m_Memory.m_pMemory[v5];
  v7->m_Element.m_nVerts = nCount;
  v7->m_Element.m_ShadowVerts = (ShadowVertex_t *)MemAlloc_Alloc(nSize: (24 * (unsigned __int64)nCount) >> 32 != 0 ? -1 : 24 * nCount);
  if ( --s_ShadowFragmentAllocLock.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&s_ShadowFragmentAllocLock, 0);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x100C0020
// Name: private: void CDispInfo::ClearShadowDecalFragments(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::ClearShadowDecalFragments(CDispInfo *this, unsigned __int16 h)
{
  UtlLinkedListElem_t<CDispShadowDecal,unsigned short> *v2; // eax
  unsigned __int16 m_FirstFragment; // di
  int v4; // esi
  unsigned __int16 m_Next; // bx
  UtlLinkedListElem_t<CDispShadowFragment,unsigned short> *v6; // esi
  CDispShadowDecal *decal; // [esp+Ch] [ebp+8h]

  v2 = &s_DispShadowDecals.m_Memory.m_pMemory[h];
  m_FirstFragment = v2->m_Element.m_FirstFragment;
  decal = &v2->m_Element;
  if ( m_FirstFragment != 0xFFFF )
  {
    do
    {
      v4 = m_FirstFragment;
      m_Next = s_DispShadowFragments.m_Memory.m_pMemory[v4].m_Next;
      CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::Unlink(
        this: &s_DispShadowFragments,
        elem: m_FirstFragment);
      v6 = &s_DispShadowFragments.m_Memory.m_pMemory[v4];
      free(pMem: v6->m_Element.m_ShadowVerts);
      v6->m_Element.m_ShadowVerts = nullptr;
      v6->m_Next = s_DispShadowFragments.m_FirstFree;
      s_DispShadowFragments.m_FirstFree = m_FirstFragment;
      m_FirstFragment = m_Next;
    }
    while ( m_Next != 0xFFFF );
    v2 = (UtlLinkedListElem_t<CDispShadowDecal,unsigned short> *)decal;
  }
  v2->m_Element.m_Flags &= ~8u;
  v2->m_Element.m_FirstFragment = -1;
  *(_DWORD *)&v2->m_Element.m_nVerts = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100C00D0
// Name: private: void CDispInfo::ClearAllShadowDecalFragments(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::ClearAllShadowDecalFragments(CDispInfo *this)
{
  unsigned __int16 i; // si

  for ( i = this->m_FirstShadowDecal; i != 0xFFFF; i = s_DispShadowDecals.m_Memory.m_pMemory[i].m_Next )
    CDispInfo::ClearShadowDecalFragments(this, h: i);
}

//------------------------------------------------------------------------------
// Address: 0x100C0120
// Name: public: virtual void CDispInfo::RemoveShadowDecal(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::RemoveShadowDecal(CDispInfo *this, unsigned __int16 h)
{
  CDispInfo::ClearShadowDecalFragments(this, h);
  if ( this->m_FirstShadowDecal == h )
    this->m_FirstShadowDecal = s_DispShadowDecals.m_Memory.m_pMemory[h].m_Next;
  CUtlLinkedList<CDispShadowDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowDecal,unsigned short>,unsigned short>>::Unlink(
    this: &s_DispShadowDecals,
    elem: h);
  s_DispShadowDecals.m_Memory.m_pMemory[h].m_Next = s_DispShadowDecals.m_FirstFree;
  s_DispShadowDecals.m_FirstFree = h;
}

//------------------------------------------------------------------------------
// Address: 0x100C01D0
// Name: public: virtual unsigned short CDispInfo::NotifyAddDecal(struct decal_t __near *,float)
// Source: json
//------------------------------------------------------------------------------
__int16 __thiscall CDispInfo::NotifyAddDecal(CDispInfo *this, decal_t *pDecal, float flSize)
{
  int v4; // esi
  __int16 result; // ax
  UtlLinkedListElem_t<CDispDecal,unsigned short> *v6; // eax
  CDecalVert *m_FirstDecal; // eax
  int v8; // ecx
  UtlLinkedListElem_t<CDispDecal,unsigned short> *v9; // esi
  __int16 h; // [esp+8h] [ebp-8h]
  CDecalVert *pOutVerts; // [esp+Ch] [ebp-4h] BYREF

  v4 = CUtlLinkedList<CDispDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short>>::AllocInternal(
         this: &s_DispDecals,
         multilist: true);
  result = -1;
  if ( (_WORD)v4 != 0xFFFF )
  {
    v6 = &s_DispDecals.m_Memory.m_pMemory[v4];
    if ( v6 != nullptr )
    {
      v6->m_Element.m_NodeIntersect.m_Ints[0] = 0;
      v6->m_Element.m_NodeIntersect.m_Ints[1] = 0;
      v6->m_Element.m_NodeIntersect.m_Ints[2] = 0;
      v6->m_Element.m_Flags = 0;
    }
    m_FirstDecal = (CDecalVert *)this->m_FirstDecal;
    v8 = 0;
    h = v4;
    if ( m_FirstDecal != (CDecalVert *)0xFFFF )
    {
      do
      {
        pOutVerts = m_FirstDecal;
        m_FirstDecal = (CDecalVert *)s_DispDecals.m_Memory.m_pMemory[(unsigned __int16)m_FirstDecal].m_Next;
        ++v8;
      }
      while ( m_FirstDecal != (CDecalVert *)0xFFFF );
      if ( v8 >= 32 )
        R_DecalUnlink(
          pdecal: s_DispDecals.m_Memory.m_pMemory[(unsigned __int16)pOutVerts].m_Element.m_pDecal,
          pData: host_state.worldbrush);
    }
    CUtlLinkedList<CDispDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short>>::LinkBefore(
      this: &s_DispDecals,
      before: this->m_FirstDecal,
      elem: v4);
    this->m_FirstDecal = v4;
    v9 = &s_DispDecals.m_Memory.m_pMemory[v4];
    v9->m_Element.m_pDecal = pDecal;
    *(_DWORD *)&v9->m_Element.m_nVerts = 0;
    v9->m_Element.m_FirstFragment = -1;
    v9->m_Element.m_flSize = flSize;
    pOutVerts = nullptr;
    R_SetupDecalClip(
      &pOutVerts,
      pDecal: v9->m_Element.m_pDecal,
      vSurfNormal: &this->m_ParentSurfID->plane->normal,
      pMaterial: v9->m_Element.m_pDecal->material,
      textureSpaceBasis: v9->m_Element.m_TextureSpaceBasis,
      decalWorldScale: v9->m_Element.m_DecalWorldScale);
    CDispInfo::SetupDecalNodeIntersect(
      this,
      nodeIndex: &this->m_pPowerInfo->m_RootNode,
      iNodeBitIndex: 0,
      pDispDecal: &v9->m_Element,
      pInfo: nullptr);
    return h;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C0300
// Name: public: virtual unsigned short CDispInfo::AddShadowDecal(unsigned short)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CDispInfo::AddShadowDecal(CDispInfo *this, unsigned __int16 shadowHandle)
{
  unsigned __int16 v3; // ax
  unsigned __int16 v4; // cx
  unsigned __int16 v5; // si
  UtlLinkedListElem_t<CDispShadowDecal,unsigned short> *v6; // eax
  UtlLinkedListElem_t<CDispShadowDecal,unsigned short> *v7; // eax

  v3 = CUtlLinkedList<CDispShadowDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowDecal,unsigned short>,unsigned short>>::AllocInternal(
         this: &s_DispShadowDecals,
         multilist: true);
  v4 = v3;
  if ( v3 == 0xFFFF )
  {
    v5 = -1;
  }
  else
  {
    v6 = &s_DispShadowDecals.m_Memory.m_pMemory[v3];
    if ( v6 != nullptr )
    {
      v6->m_Element.m_NodeIntersect.m_Ints[0] = 0;
      v6->m_Element.m_NodeIntersect.m_Ints[1] = 0;
      v6->m_Element.m_NodeIntersect.m_Ints[2] = 0;
      v6->m_Element.m_Flags = 2;
    }
    v5 = v4;
  }
  CUtlLinkedList<CDispShadowDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowDecal,unsigned short>,unsigned short>>::LinkBefore(
    this: &s_DispShadowDecals,
    before: this->m_FirstShadowDecal,
    elem: v5);
  this->m_FirstShadowDecal = v5;
  v7 = &s_DispShadowDecals.m_Memory.m_pMemory[v5];
  *(_DWORD *)&v7->m_Element.m_nVerts = 0;
  v7->m_Element.m_Shadow = shadowHandle;
  v7->m_Element.m_FirstFragment = -1;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100C03A0
// Name: void DispInfo_DrawDecalsGroup(class IMatRenderContext __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispInfo_DrawDecalsGroup(IMatRenderContext *pRenderContext, int iGroup, int iTreeType)
{
  int v3; // ebx
  int (__thiscall *GetMaxVerticesToRender)(IMatRenderContext *, IMaterial *); // edx
  int v5; // esi
  int (__thiscall *GetMaxIndicesToRender)(IMatRenderContext *); // edx
  int v7; // eax
  int v8; // edi
  DecalMaterialBucket_t *v9; // eax
  decal_t **m_iHead; // esi
  decal_t *v11; // eax
  bool v12; // zf
  int v13; // eax
  int v14; // ecx
  UtlLinkedListElem_t<CDispDecal,unsigned short> *v15; // eax
  UtlLinkedListElem_t<CDispDecalFragment,unsigned short> *v16; // esi
  int m_nVerts; // eax
  int m_nVertexCount; // eax
  IMatRenderContext *v19; // ebx
  IMaterial *material; // ecx
  int v21; // edi
  DecalBatchList_t *v22; // edi
  decal_t *v23; // eax
  int v24; // edi
  float *m_pCurrPosition; // ecx
  int v26; // eax
  float *p_x; // ecx
  float *m_pCurrNormal; // edx
  float *v29; // ecx
  int v30; // xmm0_4
  float *v31; // ecx
  int v32; // xmm0_4
  int v33; // eax
  unsigned __int16 v34; // si
  unsigned __int16 *v35; // eax
  int v36; // edi
  signed int v37; // ecx
  signed int v38; // edx
  signed int v39; // eax
  int v40; // eax
  DecalMeshList_t meshList; // [esp+4h] [ebp-A38h] BYREF
  CMeshBuilder meshBuilder; // [esp+810h] [ebp-22Ch] BYREF
  const CUtlVector<DecalMaterialBucket_t,CUtlMemory<DecalMaterialBucket_t,int> > *materialBucketList; // [esp+9F8h] [ebp-44h]
  int nBucketCount; // [esp+9FCh] [ebp-40h]
  float flOffset; // [esp+A00h] [ebp-3Ch]
  int nCount; // [esp+A04h] [ebp-38h]
  decal_t *pDecalHead; // [esp+A08h] [ebp-34h]
  int iBucket; // [esp+A0Ch] [ebp-30h]
  int hFrag; // [esp+A10h] [ebp-2Ch]
  int nDecalSortMaxIndices; // [esp+A14h] [ebp-28h]
  int v51; // [esp+A18h] [ebp-24h]
  int nDecalSortMaxVerts; // [esp+A1Ch] [ebp-20h]
  int iElement; // [esp+A20h] [ebp-1Ch]
  int nSortTreeCount; // [esp+A24h] [ebp-18h]
  int nIndexCount; // [esp+A28h] [ebp-14h]
  DecalBatchList_t *pBatch; // [esp+A2Ch] [ebp-10h]
  int nTriCount; // [esp+A30h] [ebp-Ch]
  int nVertCount; // [esp+A34h] [ebp-8h]
  bool bMeshInit; // [esp+A39h] [ebp-3h]
  bool bMatWireframe; // [esp+A3Ah] [ebp-2h]
  bool bBatchInit; // [esp+A3Bh] [ebp-1h]

  v3 = 0;
  nSortTreeCount = g_aDecalSortTrees.m_Size;
  if ( g_aDecalSortTrees.m_Size == 0 )
    return;
  meshList.m_aBatches.m_Size = 0;
  meshList.m_aBatches.m_pElements = (DecalBatchList_t *)&meshList.m_aBatches;
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  GetMaxVerticesToRender = pRenderContext->GetMaxVerticesToRender;
  v5 = 5 * g_nMaxDecals;
  nVertCount = 0;
  nIndexCount = 0;
  nDecalSortMaxVerts = 5 * g_nMaxDecals;
  if ( v5 >= GetMaxVerticesToRender(this: pRenderContext, a2: g_materialDecalWireframe) / 4 )
  {
    v5 = pRenderContext->GetMaxVerticesToRender(this: pRenderContext, a2: g_materialDecalWireframe) / 4;
    nDecalSortMaxVerts = v5;
  }
  GetMaxIndicesToRender = pRenderContext->GetMaxIndicesToRender;
  nDecalSortMaxIndices = 3 * v5;
  if ( 3 * v5 >= GetMaxIndicesToRender(this: pRenderContext) )
    nDecalSortMaxIndices = pRenderContext->GetMaxIndicesToRender(this: pRenderContext);
  bMatWireframe = (sv_cheats.m_pParent != nullptr && sv_cheats.m_pParent->m_Value.m_nValue != 0 || Cmd_IsRptActive())
               && mat_wireframe.m_pParent != nullptr
               && mat_wireframe.m_pParent->m_Value.m_nValue != 0;
  if ( nSortTreeCount > 0 )
  {
    v51 = 20 * (iGroup + iTreeType + 2 * iGroup);
    while ( 1 )
    {
      materialBucketList = (CUtlVector<DecalMaterialBucket_t,CUtlMemory<DecalMaterialBucket_t,int> > *)((char *)g_aDispDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets[0] + v51);
      v7 = *(int *)((char *)&g_aDispDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets[0][0].m_Size + v51);
      v8 = 0;
      bMeshInit = true;
      nBucketCount = v7;
      iBucket = 0;
      if ( v7 > 0 )
        break;
LABEL_79:
      v51 += 312;
      if ( --nSortTreeCount == 0 )
        goto LABEL_80;
    }
    while ( 1 )
    {
      v9 = &materialBucketList->m_Memory.m_pMemory[v8];
      if ( v9->m_nCheckCount != g_nDispDecalSortCheckCount )
        goto LABEL_67;
      m_iHead = (decal_t **)v9->m_iHead;
      if ( v9->m_iHead == 0 || m_iHead[1] == (decal_t *)m_iHead && m_iHead[2] != (decal_t *)m_iHead )
        goto LABEL_67;
      v11 = *m_iHead;
      v12 = (*m_iHead)->material == nullptr;
      pDecalHead = *m_iHead;
      if ( v12 || (__int64)v11->material->GetVertexFormat(this: v11->material) == 0 )
        goto LABEL_67;
      pBatch = nullptr;
      bBatchInit = true;
      iElement = (int)m_iHead;
      do
      {
        v13 = *(_DWORD *)iElement;
        iElement = *(_DWORD *)(iElement + 8);
        v14 = *(unsigned __int16 *)(v13 + 76);
        v15 = &s_DispDecals.m_Memory.m_pMemory[v14];
        if ( v15->m_Element.m_pDecal->material == nullptr )
        {
          DevMsg(a1: "DispInfo_DrawDecalsGroup: material is NULL decal %i.\n", v14);
          continue;
        }
        hFrag = v15->m_Element.m_FirstFragment;
        if ( (_WORD)hFrag != 0xFFFF )
        {
          while ( 1 )
          {
            v16 = &s_DispDecalFragments.m_Memory.m_pMemory[(unsigned __int16)hFrag];
            m_nVerts = v16->m_Element.m_nVerts;
            hFrag = v16->m_Next;
            nCount = m_nVerts;
            if ( m_nVerts + nVertCount >= nDecalSortMaxVerts || m_nVerts + v3 - 2 >= nDecalSortMaxIndices )
              break;
            if ( bMeshInit )
            {
              v19 = pRenderContext;
LABEL_42:
              meshList.m_pMesh = nullptr;
              meshList.m_aBatches.m_Size = 0;
              if ( bMatWireframe )
                material = g_materialDecalWireframe;
              else
                material = pDecalHead->material;
              meshList.m_pMesh = v19->GetDynamicMesh(this: v19, a2: false, a3: nullptr, a4: nullptr, a5: material);
              CMeshBuilder::Begin(
                this: &meshBuilder,
                pMesh: meshList.m_pMesh,
                type: MATERIAL_TRIANGLES,
                nVertexCount: nDecalSortMaxVerts,
                nIndexCount: nDecalSortMaxIndices,
                pMeshSettings: nullptr);
              v3 = 0;
              nVertCount = 0;
              nIndexCount = 0;
              bMeshInit = false;
            }
            if ( bBatchInit )
            {
              v21 = meshList.m_aBatches.m_Size++;
              meshList.m_aBatches.m_pElements = (DecalBatchList_t *)&meshList.m_aBatches;
              if ( meshList.m_aBatches.m_Size - v21 - 1 > 0 )
                _V_memmove(
                  dest: &meshList.m_aBatches.m_Memory.m_Memory[16 * v21 + 16],
                  src: (char *)&meshList.m_aBatches + 16 * v21,
                  count: 16 * (meshList.m_aBatches.m_Size - v21 - 1));
              v12 = !bMatWireframe;
              v22 = (DecalBatchList_t *)((char *)&meshList.m_aBatches + 16 * v21);
              pBatch = v22;
              v22->m_iStartIndex = v3;
              if ( v12 )
              {
                v23 = pDecalHead;
                v22->m_pMaterial = pDecalHead->material;
                v22->m_pProxy = v23->userdata;
                v22->m_iLightmapPage = materialSortInfoArray[v23->surfID->materialSortID].lightmapPageID;
              }
              else
              {
                v22->m_pMaterial = g_materialDecalWireframe;
              }
              bBatchInit = false;
            }
            v24 = 0;
            v12 = v16->m_Element.m_nVerts == 0;
            flOffset = v16->m_Element.m_pDecal->lightmapOffset;
            if ( !v12 )
            {
              nTriCount = 0;
              do
              {
                m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
                v26 = (int)v16->m_Element.m_pVerts + nTriCount;
                *meshBuilder.m_VertexBuilder.m_pCurrPosition = *(float *)v26;
                m_pCurrPosition[1] = *(float *)(v26 + 4);
                m_pCurrPosition[2] = *(float *)(v26 + 8);
                p_x = &v16->m_Element.m_pDecal->surfID->plane->normal.x;
                m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
                *meshBuilder.m_VertexBuilder.m_pCurrNormal = *p_x;
                m_pCurrNormal[1] = p_x[1];
                m_pCurrNormal[2] = p_x[2];
                *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
                v29 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                v30 = *(_DWORD *)(v26 + 20);
                *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = *(float *)(v26 + 16);
                *((_DWORD *)v29 + 1) = v30;
                v31 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
                v32 = *(_DWORD *)(v26 + 28);
                *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = *(float *)(v26 + 24);
                *((_DWORD *)v31 + 1) = v32;
                *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = flOffset;
                CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
                v33 = v16->m_Element.m_nVerts;
                nTriCount += 32;
                ++v24;
              }
              while ( v24 < v33 );
              v3 = nIndexCount;
            }
            v34 = nVertCount + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
            v35 = &meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex];
            v36 = nCount - 2;
            v37 = (nCount - 2) * meshBuilder.m_IndexBuilder.m_nIndexSize;
            v38 = 0;
            nTriCount = nCount - 2;
            if ( v37 > 0 )
            {
              do
              {
                *v35 = v34;
                v35[1] = v38 + v34 + 1;
                v35[2] = v38++ + v34 + 2;
                v35 += 3;
              }
              while ( v38 < v37 );
              v36 = nTriCount;
              v3 = nIndexCount;
            }
            v39 = v37 * meshBuilder.m_IndexBuilder.m_nIndexSize
                + meshBuilder.m_IndexBuilder.m_nCurrentIndex
                + 2 * v37 * meshBuilder.m_IndexBuilder.m_nIndexSize;
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = v39;
            if ( v39 > meshBuilder.m_IndexBuilder.m_nIndexCount )
              meshBuilder.m_IndexBuilder.m_nIndexCount = v39;
            nVertCount += nCount;
            v3 += v36 + 2 * v36;
            nIndexCount = v3;
            if ( (_WORD)hFrag == 0xFFFF )
              goto LABEL_63;
          }
          if ( pBatch != nullptr )
            pBatch->m_nIndexCount = v3 - pBatch->m_iStartIndex;
          if ( meshBuilder.m_bGenerateIndices )
          {
            switch ( meshBuilder.m_Type )
            {
              case MATERIAL_LINE_STRIP:
                m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
                break;
              case MATERIAL_LINE_LOOP:
                m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
                break;
              case MATERIAL_POLYGON:
                m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
                break;
              case MATERIAL_QUADS:
                m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
                break;
              case MATERIAL_INSTANCED_QUADS:
                m_nVertexCount = 0;
                break;
              default:
                m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
                break;
            }
            CIndexBuilder::GenerateIndices(
              this: &meshBuilder.m_IndexBuilder,
              primitiveType: meshBuilder.m_Type,
              nIndexCount: m_nVertexCount);
          }
          meshBuilder.m_pMesh->UnlockMesh(
            this: meshBuilder.m_pMesh,
            a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
            a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
            a4: &meshBuilder);
          v19 = pRenderContext;
          meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
          meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
          meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
          meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
          meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
          meshBuilder.m_pMesh = nullptr;
          DispInfo_DrawDecalMeshList(pRenderContext, &meshList);
          pBatch = nullptr;
          bBatchInit = true;
          goto LABEL_42;
        }
LABEL_63:
        if ( pBatch != nullptr )
          pBatch->m_nIndexCount = v3 - pBatch->m_iStartIndex;
      }
      while ( iElement != 0 );
      v8 = iBucket;
LABEL_67:
      iBucket = ++v8;
      if ( v8 >= nBucketCount )
      {
        if ( !bMeshInit )
        {
          if ( meshBuilder.m_bGenerateIndices )
          {
            switch ( meshBuilder.m_Type )
            {
              case MATERIAL_LINE_STRIP:
                v40 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
                break;
              case MATERIAL_LINE_LOOP:
                v40 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
                break;
              case MATERIAL_POLYGON:
                v40 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
                break;
              case MATERIAL_QUADS:
                v40 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
                break;
              case MATERIAL_INSTANCED_QUADS:
                v40 = 0;
                break;
              default:
                v40 = meshBuilder.m_VertexBuilder.m_nVertexCount;
                break;
            }
            CIndexBuilder::GenerateIndices(
              this: &meshBuilder.m_IndexBuilder,
              primitiveType: meshBuilder.m_Type,
              nIndexCount: v40);
          }
          meshBuilder.m_pMesh->UnlockMesh(
            this: meshBuilder.m_pMesh,
            a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
            a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
            a4: &meshBuilder);
          meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
          meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
          meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
          meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
          meshBuilder.m_pMesh = nullptr;
          meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
          DispInfo_DrawDecalMeshList(pRenderContext, &meshList);
        }
        goto LABEL_79;
      }
    }
  }
LABEL_80:
  if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
  {
    meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
  {
    meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0A70
// Name: void DispInfo_DrawDecals(class IMatRenderContext __near *,class CDispInfo __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispInfo_DrawDecals(IMatRenderContext *pRenderContext)
{
  DispInfo_DrawDecalsGroup(pRenderContext, iGroup: 0, iTreeType: 0);
  DispInfo_DrawDecalsGroup(pRenderContext, iGroup: 0, iTreeType: 1);
  DispInfo_DrawDecalsGroup(pRenderContext, iGroup: 0, iTreeType: 2);
}

//------------------------------------------------------------------------------
// Address: 0x100C0AA0
// Name: void DispInfo_RenderListDecalsAndOverlays(class IMatRenderContext __near *,int,struct msurface2_t __near * __near *,int,bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispInfo_RenderListDecalsAndOverlays(
        IMatRenderContext *pRenderContext,
        int nSortGroup,
        msurface2_t **pList,
        int listCount,
        bool bOrtho,
        __int16 flags)
{
  int i; // esi
  int m_ShadowDecals; // eax
  BOOL v8; // edi
  IOverlayMgr *v9; // eax
  IOverlayMgr *v10; // eax
  CDispInfo *visibleDisps[2048]; // [esp+0h] [ebp-2008h] BYREF
  BOOL v12; // [esp+2000h] [ebp-8h]
  int nVisibleDisps; // [esp+2004h] [ebp-4h] BYREF

  if ( r_DrawDisp.m_pParent != nullptr
    && r_DrawDisp.m_pParent->m_Value.m_nValue != 0
    && listCount != 0
    && (flags & 0x400) != 0 )
  {
    g_bDispOrthoRender = bOrtho;
    DispInfo_GetVisibleDispsAndAddOverlayFragmentsToRenderList(
      nSortGroup,
      pList,
      listCount,
      visibleDisps,
      &nVisibleDisps);
    for ( i = 0; i < listCount; ++i )
    {
      m_ShadowDecals = pList[i]->m_ShadowDecals;
      if ( (_WORD)m_ShadowDecals != 0xFFFF )
        g_pShadowMgr->AddShadowsOnSurfaceToRenderList(this: g_pShadowMgr, a2: m_ShadowDecals);
    }
    if ( (flags & 0x80u) != 0 || (LOBYTE(v12) = 1, (flags & 0x100) != 0) )
      LOBYTE(v12) = 0;
    v8 = v12;
    g_pShadowMgr->RenderFlashlights(this: g_pShadowMgr, a2: v12, a3: false, a4: nullptr);
    v9 = OverlayMgr();
    v9->RenderOverlays(this: v9, a2: pRenderContext, a3: nSortGroup);
    g_pShadowMgr->DrawFlashlightOverlays(this: g_pShadowMgr, a2: pRenderContext, a3: nSortGroup, a4: v8);
    v10 = OverlayMgr();
    v10->ClearRenderLists(this: v10, a2: nSortGroup);
    DispInfo_BatchDecals(pVisibleDisps: visibleDisps, nVisibleDisps);
    DispInfo_DrawDecalsGroup(pRenderContext, iGroup: 0, iTreeType: 0);
    DispInfo_DrawDecalsGroup(pRenderContext, iGroup: 0, iTreeType: 1);
    DispInfo_DrawDecalsGroup(pRenderContext, iGroup: 0, iTreeType: 2);
    g_pShadowMgr->DrawFlashlightDecalsOnDisplacements(
      this: g_pShadowMgr,
      a2: pRenderContext,
      a3: nSortGroup,
      a4: visibleDisps,
      a5: nVisibleDisps,
      a6: v8);
    g_pShadowMgr->RenderFlashlights(this: g_pShadowMgr, a2: v8, a3: true, a4: nullptr);
    g_pShadowMgr->RenderShadows(this: g_pShadowMgr, a2: pRenderContext, a3: nullptr);
    g_pShadowMgr->ClearShadowRenderList(this: g_pShadowMgr);
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100BCD00
// Name: public: virtual void CDispInfo::GetBoundingBox(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::GetBoundingBox(CDispInfo *this, Vector *bbMin, Vector *bbMax)
{
  *bbMin = this->m_BBoxMin;
  *bbMax = this->m_BBoxMax;
}

//------------------------------------------------------------------------------
// Address: 0x100BCD30
// Name: public: virtual void CDispInfo::AddDynamicLights(struct dlight_t __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::AddDynamicLights(CDispInfo *this, dlight_t *pLights, unsigned int mask)
{
  int v5; // edi
  CDispInfo *v6; // [esp+0h] [ebp-4h]

  v6 = this;
  if ( this->m_ParentSurfID != nullptr )
  {
    v5 = 0;
    while ( mask != 0 )
    {
      if ( (mask & 1) != 0 )
      {
        if ( (pLights->flags & 0xC) != 0 )
        {
          CDispInfo::AddSingleDynamicAlphaLight(this, dl: pLights);
        }
        else if ( CDispInfo::NumLightMaps(this) == 1 )
        {
          CDispInfo::AddSingleDynamicLight(this: v6, dl: pLights);
        }
        else
        {
          CDispInfo::AddSingleDynamicLightBumped(this: v6, dl: pLights);
        }
      }
      ++v5;
      ++pLights;
      mask >>= 1;
      if ( v5 >= 32 )
        break;
      this = v6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BCDA0
// Name: private: void CDispInfo::FindNodesInShadowFrustum(class Frustum_t const __near &,unsigned short __near *,int __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::FindNodesInShadowFrustum(
        CDispInfo *this,
        Frustum_t *frustum,
        unsigned __int16 *pNodeArray,
        int *pNumNodes,
        int iNodeBit,
        int iLevel)
{
  int v6; // ecx
  int v7; // esi
  int v8; // edi
  int v9; // ebx
  int v10; // edx
  float v11; // xmm0_4
  int v12; // edx
  unsigned __int8 v13; // al
  unsigned __int8 v14; // al
  VisitedNodeData_t nodeList[85]; // [esp+Ch] [ebp-B8h]
  Vector *mins; // [esp+B8h] [ebp-Ch]
  CDispInfo *v17; // [esp+BCh] [ebp-8h]
  int listIndex; // [esp+C0h] [ebp-4h]

  v17 = this;
  v6 = 0;
  nodeList[0] = 0;
  v7 = 0;
  do
  {
    v8 = nodeList[v6].iNodeBit;
    v9 = nodeList[v6].iLevel;
    v10 = (int)&v17->m_pNodeInfo[v8];
    v11 = *(float *)(v10 + 4);
    ++v6;
    mins = (Vector *)(v10 + 4);
    listIndex = v6;
    if ( v11 != 3.4028235e38 )
    {
      if ( !Frustum_t::CullBox(this: frustum, mins, maxs: (const Vector *)(v10 + 16)) )
      {
        if ( v9 + 1 >= v17->m_Power )
        {
          pNodeArray[(*pNumNodes)++] = v8;
        }
        else
        {
          v12 = v17->m_pPowerInfo->m_NodeIndexIncrements[v9];
          nodeList[v7 + 1].iNodeBit = v8 + 1;
          v13 = v12 + v8 + 1;
          nodeList[v7 + 2].iNodeBit = v13;
          v14 = v12 + v13;
          nodeList[v7 + 1].iLevel = v9 + 1;
          nodeList[v7 + 2].iLevel = v9 + 1;
          nodeList[v7 + 3].iNodeBit = v14;
          nodeList[v7 + 3].iLevel = v9 + 1;
          nodeList[v7 + 4].iNodeBit = v14 + v12;
          nodeList[v7 + 4].iLevel = v9 + 1;
          v7 += 4;
        }
      }
      v6 = listIndex;
    }
  }
  while ( v6 <= v7 );
}

//------------------------------------------------------------------------------
// Address: 0x100BCEA0
// Name: private: void CDispInfo::AddNodeTrisToDecal(class CDispShadowDecal __near *,unsigned short,unsigned short __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::AddNodeTrisToDecal(
        CDispInfo *this,
        CDispShadowDecal *pDispDecal,
        unsigned __int16 decalHandle,
        unsigned __int16 *pNodeIndices,
        int nNumIndices)
{
  int v5; // ecx
  DispNodeInfo_t *m_pNodeInfo; // eax
  int m_FirstTesselationIndex; // ebx
  DispNodeInfo_t *v8; // edi
  int v9; // esi
  int j; // [esp+0h] [ebp-8h]

  v5 = 0;
  for ( j = 0; v5 < nNumIndices; j = v5 )
  {
    m_pNodeInfo = this->m_pNodeInfo;
    m_FirstTesselationIndex = m_pNodeInfo[pNodeIndices[v5]].m_FirstTesselationIndex;
    v8 = &m_pNodeInfo[pNodeIndices[v5]];
    v9 = 0;
    if ( v8->m_Count != 0 )
    {
      do
      {
        CDispInfo::TestAddDecalTri(
          this,
          iIndexStart: (ShadowVertex_t **)(v9 + m_FirstTesselationIndex),
          decalHandle,
          pDecal: pDispDecal);
        v9 += 3;
      }
      while ( v9 < v8->m_Count );
      v5 = j;
    }
    ++v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BCF20
// Name: public: virtual bool CDispInfo::GetTag(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDispInfo::GetTag(CDispInfo *this)
{
  return this->m_Tag == this->m_pDispArray->m_CurTag;
}

//------------------------------------------------------------------------------
// Address: 0x100BCF40
// Name: public: virtual void CDispInfo::SetTag(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::SetTag(CDispInfo *this)
{
  this->m_Tag = this->m_pDispArray->m_CurTag;
}

//------------------------------------------------------------------------------
// Address: 0x100BCF60
// Name: void DispInfo_BuildPrimLists(int,struct msurface2_t __near * __near *,int,bool,class CDispInfo __near * __near * const,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispInfo_BuildPrimLists(
        int nSortGroup,
        msurface2_t **pList,
        int listCount,
        bool bDepthOnly,
        CDispInfo **visibleDisps,
        int *nVisibleDisps)
{
  int v6; // ebx
  CDispInfo *pDispInfo; // esi

  v6 = 0;
  for ( *nVisibleDisps = 0; v6 < listCount; ++v6 )
  {
    pDispInfo = (CDispInfo *)pList[v6]->pDispInfo;
    if ( CDispInfo::Render(this: pDispInfo, pGroup: pDispInfo->m_pMesh, bAllowDebugModes: false) != 0
      && *nVisibleDisps < 2048 )
    {
      visibleDisps[(*nVisibleDisps)++] = pDispInfo;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BCFB0
// Name: void __near * DispInfo_CreateArray(int)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__cdecl DispInfo_CreateArray(unsigned int nElements)
{
  int v1; // edi
  _DWORD *v2; // esi
  CDispInfo *v3; // ebx
  int v4; // ecx
  unsigned int *v5; // eax
  int v6; // eax
  CDispInfo *v8; // [esp+Ch] [ebp-4h]
  int nElementsa; // [esp+18h] [ebp+8h]

  v1 = nElements;
  v2 = MemAlloc_Alloc(nSize: 0xCu);
  v3 = nullptr;
  *(_WORD *)v2 = 1;
  v2[2] = nElements;
  if ( nElements != 0 )
  {
    v4 = (620 * (unsigned __int64)nElements) >> 32 != 0 ? -1 : 620 * nElements;
    v5 = (unsigned int *)MemAlloc_Alloc(nSize: __CFADD__(v4, 4) ? -1 : v4 + 4);
    if ( v5 != nullptr )
    {
      v3 = (CDispInfo *)(v5 + 1);
      *v5 = nElements;
      v8 = (CDispInfo *)(v5 + 1);
      nElementsa = nElements - 1;
      if ( v1 - 1 >= 0 )
      {
        do
        {
          CDispInfo::CDispInfo(this: v3++);
          --nElementsa;
        }
        while ( nElementsa >= 0 );
        v3 = v8;
      }
    }
  }
  v2[1] = v3;
  if ( v1 > 0 )
  {
    v6 = 0;
    do
    {
      *(_DWORD *)(v6 + v2[1] + 616) = v2;
      v6 += 620;
      --v1;
    }
    while ( v1 != 0 );
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100BD0B0
// Name: class IDispInfo __near * DispInfo_IndexArray(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
IDispInfo *__cdecl DispInfo_IndexArray(_DWORD *hArray, int iElement)
{
  if ( hArray != nullptr )
    return (IDispInfo *)(hArray[1] + 620 * iElement);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100BD0D0
// Name: int DispInfo_ComputeIndex(void __near *,class IDispInfo __near *)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__cdecl DispInfo_ComputeIndex(_DWORD *hArray, IDispInfo *pInfo)
{
  _DWORD *result; // eax

  result = hArray;
  if ( hArray != nullptr )
    return (_DWORD *)(((unsigned int)pInfo - hArray[1]) / 0x26C);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BD140
// Name: public: virtual void CDispInfo::GetIntersectingSurfaces(class GetIntersectingSurfaces_Struct __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::GetIntersectingSurfaces(CDispInfo *this, GetIntersectingSurfaces_Struct *pStruct)
{
  CDispInfo *v2; // eax
  bool v3; // zf
  GetIntersectingSurfaces_Struct *v4; // edx
  SurfInfo *v5; // edi
  int v6; // ecx
  float *p_z; // edi
  unsigned __int16 *m_pIndices; // ebx
  float v9; // edx
  int v10; // esi
  int v11; // esi
  double v12; // st7
  float *v13; // ecx
  int v14; // edx
  double v15; // st6
  double v16; // rt0
  double v17; // st6
  double v18; // st7
  float *v19; // edx
  double v20; // st6
  double v21; // st5
  double v22; // rt1
  double v23; // st5
  double v24; // st6
  double v25; // st5
  double v26; // st3
  double v27; // st4
  double v28; // st3
  double v29; // st7
  double v30; // st3
  double v31; // rt0
  double v32; // st4
  double v33; // st6
  double v34; // st4
  double v35; // st6
  double v36; // st4
  double v37; // st3
  double v38; // st2
  double v39; // st5
  double v40; // rtt
  double v41; // st3
  double v42; // st7
  double v43; // rt0
  double v44; // st5
  double v45; // st7
  float m_Radius; // xmm1_4
  const Vector *v47; // eax
  float v48; // xmm3_4
  float v49; // xmm1_4
  float v50; // xmm0_4
  float v51; // xmm2_4
  float v52; // xmm4_4
  float v53; // xmm5_4
  float v54; // xmm0_4
  float v55; // xmm1_4
  Vector vMax; // [esp+0h] [ebp-3Ch] BYREF
  Vector vMin; // [esp+Ch] [ebp-30h] BYREF
  CDispInfo *v58; // [esp+18h] [ebp-24h]
  const Vector *m_pCenter; // [esp+1Ch] [ebp-20h]
  int v60; // [esp+20h] [ebp-1Ch]
  float v61; // [esp+24h] [ebp-18h]
  float v62; // [esp+28h] [ebp-14h]
  int iVert; // [esp+2Ch] [ebp-10h]
  SurfInfo *pOut; // [esp+30h] [ebp-Ch]
  int iDim; // [esp+34h] [ebp-8h]
  float v66; // [esp+38h] [ebp-4h]

  v2 = this;
  v3 = this->m_Verts.m_Size == 0;
  v58 = this;
  if ( !v3 && this->m_nIndices != 0 )
  {
    v4 = pStruct;
    v5 = &pStruct->m_pInfos[pStruct->m_nSetInfos];
    v6 = 0;
    pOut = v5;
    iVert = 0;
    if ( v2->m_MeshReader.m_MaxIndices > 0 )
    {
      p_z = &v5->m_Verts[1].z;
      do
      {
        if ( v4->m_nSetInfos >= v4->m_nMaxInfos )
          break;
        m_pIndices = v2->m_MeshReader.m_pIndices;
        v9 = *(float *)&v2->m_iVertOffset;
        v66 = *(float *)&v2->m_MeshReader.m_VertexSize_Position;
        iDim = (int)v2->m_MeshReader.m_pPosition;
        v10 = m_pIndices[v6 * v2->m_MeshReader.m_nIndexSize];
        LODWORD(v62) = v6 + 2;
        v11 = iDim + LODWORD(v66) * (v10 - LODWORD(v9));
        v12 = *(float *)v11;
        v13 = (float *)(iDim + LODWORD(v66) * (m_pIndices[v2->m_MeshReader.m_nIndexSize * (v6 + 1)] - LODWORD(v9)));
        v61 = v9;
        v14 = m_pIndices[LODWORD(v62) * v2->m_MeshReader.m_nIndexSize] - LODWORD(v9);
        v61 = v12;
        v15 = *v13;
        v62 = *v13;
        v16 = v15;
        v17 = v12;
        v18 = v16;
        v19 = (float *)(iDim + LODWORD(v66) * v14);
        if ( v17 <= v16 )
          v18 = v17;
        v20 = *(float *)(v11 + 4);
        iDim = *(int *)(v11 + 4);
        v21 = v13[1];
        v66 = v13[1];
        v22 = v21;
        v23 = v20;
        v24 = v22;
        if ( v23 <= v22 )
          v24 = v23;
        v25 = *(float *)(v11 + 8);
        v26 = v13[2];
        v60 = *((int *)v13 + 2);
        v27 = v26;
        if ( v25 <= v26 )
          v27 = v25;
        if ( *v19 <= v18 )
          v18 = *v19;
        v28 = v18;
        v29 = *v19;
        vMin.x = v28;
        v30 = v19[1];
        m_pCenter = *((const Vector **)v19 + 1);
        if ( v30 <= v24 )
          v24 = v30;
        v31 = v27;
        v32 = v24;
        v33 = v31;
        vMin.y = v32;
        if ( v19[2] <= v31 )
          v33 = v19[2];
        v34 = v33;
        v35 = v19[2];
        vMin.z = v34;
        v36 = v62;
        if ( v61 >= (double)v62 )
          v36 = v61;
        v37 = v66;
        if ( *(float *)&iDim >= (double)v66 )
          v37 = *(float *)&iDim;
        v38 = v25;
        v39 = *(float *)&v60;
        if ( v38 >= *(float *)&v60 )
          v39 = v38;
        v40 = v37;
        v41 = v29;
        v42 = v40;
        if ( v41 >= v36 )
          v36 = v41;
        vMax.x = v36;
        if ( *(float *)&m_pCenter >= v42 )
          v42 = *(float *)&m_pCenter;
        v43 = v39;
        v44 = v42;
        v45 = v43;
        vMax.y = v44;
        if ( v35 >= v43 )
          v45 = v35;
        vMax.z = v45;
        m_Radius = pStruct->m_Radius;
        m_pCenter = pStruct->m_pCenter;
        LODWORD(v61) = (char *)&vMax - (char *)m_pCenter;
        v47 = m_pCenter;
        *(float *)&iDim = 0.0;
        v60 = (char *)&vMin - (char *)m_pCenter;
        do
        {
          if ( *(float *)((char *)&v47->x + v60) > (float)(m_Radius + v47->x) )
            break;
          if ( (float)(v47->x - m_Radius) > *(float *)((char *)&v47->x + LODWORD(v61)) )
            break;
          v47 = (const Vector *)((char *)v47 + 4);
          ++iDim;
        }
        while ( iDim < 3 );
        if ( iDim == 3 )
        {
          *((_DWORD *)p_z + 43) = 3;
          pOut->m_Verts[0].x = *(float *)v11;
          *(p_z - 4) = *(float *)(v11 + 4);
          *(p_z - 3) = *(float *)(v11 + 8);
          *(p_z - 2) = *v13;
          *(p_z - 1) = v13[1];
          *p_z = v13[2];
          p_z[1] = *v19;
          p_z[2] = v19[1];
          p_z[3] = v19[2];
          v48 = v19[1] - *(float *)(v11 + 4);
          v49 = v19[2] - *(float *)(v11 + 8);
          v50 = v13[1] - *(float *)(v11 + 4);
          v51 = v13[2] - *(float *)(v11 + 8);
          v52 = *v13 - *(float *)v11;
          v53 = *v19 - *(float *)v11;
          p_z[44] = (float)(v48 * v51) - (float)(v49 * v50);
          p_z[45] = (float)(v49 * v52) - (float)(v51 * v53);
          p_z[46] = (float)(v50 * v53) - (float)(v48 * v52);
          VectorNormalize(vec: (Vector *)(p_z + 44));
          v54 = *(float *)(v11 + 4) * p_z[45];
          v55 = p_z[44] * *(float *)v11;
          v4 = pStruct;
          ++pOut;
          p_z[47] = (float)(v54 + v55) + (float)(p_z[46] * *(float *)(v11 + 8));
          ++pStruct->m_nSetInfos;
          p_z += 54;
        }
        else
        {
          v4 = pStruct;
        }
        v2 = v58;
        v6 = iVert + 3;
        iVert = v6;
      }
      while ( v6 < v58->m_MeshReader.m_MaxIndices );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BD480
// Name: public: virtual void CDispInfo::RenderWireframeInLightmapPage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::RenderWireframeInLightmapPage(CDispInfo *this, int pageId)
{
  msurface2_t *v2; // eax

  v2 = this->GetParent(this);
  if ( materialSortInfoArray[v2->materialSortID].lightmapPageID == pageId )
    Shader_DrawLightmapPageSurface(surfID: v2, red: 0.0, green: 0.0, blue: 1.0);
}

//------------------------------------------------------------------------------
// Address: 0x100BD4C0
// Name: public: virtual unsigned int CDispInfo::ComputeDynamicLightMask(struct dlight_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDispInfo::ComputeDynamicLightMask(CDispInfo *this, dlight_t *pLights)
{
  int v2; // edi
  int v4; // ebx
  int v5; // esi
  CDispInfo *v6; // [esp+4h] [ebp-8h]
  int lightMask; // [esp+8h] [ebp-4h]

  v2 = 0;
  v6 = this;
  lightMask = 0;
  if ( this->m_ParentSurfID == nullptr )
    return 0;
  v4 = r_dlightactive;
  v5 = 1;
  while ( v4 != 0 )
  {
    if ( (v4 & 1) != 0
      && (v5
        & *(int *)((_BYTE *)&host_state.worldbrush->surfacelighting->m_fDLightBits
                 + (((char *)this->m_ParentSurfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0))) != 0
      && (pLights->flags & 1) == 0
      && R_CanUseVisibleDLight(dlight: v2) != 0 )
    {
      lightMask |= v5;
    }
    ++pLights;
    ++v2;
    v4 >>= 1;
    v5 *= 2;
    if ( v2 >= 32 )
      break;
    this = v6;
  }
  return lightMask;
}

//------------------------------------------------------------------------------
// Address: 0x100BD550
// Name: void DispInfo_GetVisibleDispsAndAddOverlayFragmentsToRenderList(int,struct msurface2_t __near * __near *,int,class CDispInfo __near * __near * const,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispInfo_GetVisibleDispsAndAddOverlayFragmentsToRenderList(
        int nSortGroup,
        msurface2_t **pList,
        int listCount,
        CDispInfo **visibleDisps,
        int *nVisibleDisps)
{
  int v5; // esi
  IOverlayMgr *v6; // eax

  v5 = 0;
  for ( *nVisibleDisps = 0; v5 < listCount; ++v5 )
  {
    if ( *nVisibleDisps < 2048 )
      visibleDisps[(*nVisibleDisps)++] = (CDispInfo *)pList[v5]->pDispInfo;
    v6 = OverlayMgr();
    v6->AddFragmentListToRenderList(this: v6, a2: nSortGroup, a3: pList[v5]->m_nFirstOverlayFragment, a4: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BD760
// Name: public: void CVertexBuilder::AdvanceVertices(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBuilder::AdvanceVertices(CVertexBuilder *this, int nVerts)
{
  int m_nCurrentVertex; // edx

  this->m_nCurrentVertex += nVerts;
  m_nCurrentVertex = this->m_nCurrentVertex;
  if ( m_nCurrentVertex > this->m_nVertexCount )
    this->m_nVertexCount = m_nCurrentVertex;
  this->m_pCurrPosition = (float *)((char *)this->m_pCurrPosition + nVerts * this->m_VertexSize_Position);
  this->m_pCurrNormal = (float *)((char *)this->m_pCurrNormal + nVerts * this->m_VertexSize_Normal);
  this->m_pCurrColor += nVerts * this->m_VertexSize_Color;
  this->m_pCurrTexCoord[0] = (float *)((char *)this->m_pCurrTexCoord[0] + nVerts * this->m_VertexSize_TexCoord[0]);
  this->m_pCurrTexCoord[1] = (float *)((char *)this->m_pCurrTexCoord[1] + nVerts * this->m_VertexSize_TexCoord[1]);
  this->m_pCurrTexCoord[2] = (float *)((char *)this->m_pCurrTexCoord[2] + nVerts * this->m_VertexSize_TexCoord[2]);
  this->m_pCurrTexCoord[3] = (float *)((char *)this->m_pCurrTexCoord[3] + nVerts * this->m_VertexSize_TexCoord[3]);
  this->m_pCurrTexCoord[4] = (float *)((char *)this->m_pCurrTexCoord[4] + nVerts * this->m_VertexSize_TexCoord[4]);
  this->m_pCurrTexCoord[5] = (float *)((char *)this->m_pCurrTexCoord[5] + nVerts * this->m_VertexSize_TexCoord[5]);
  this->m_pCurrTexCoord[6] = (float *)((char *)this->m_pCurrTexCoord[6] + nVerts * this->m_VertexSize_TexCoord[6]);
  this->m_pCurrTexCoord[7] = (float *)((char *)this->m_pCurrTexCoord[7] + nVerts * this->m_VertexSize_TexCoord[7]);
}

//------------------------------------------------------------------------------
// Address: 0x100BD960
// Name: public: virtual bool CDispInfo::ComputeShadowFragments(unsigned short,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
char __userpurge CDispInfo::ComputeShadowFragments@<al>(
        CDispInfo *this@<ecx>,
        int a2@<ebp>,
        unsigned __int16 h,
        int *vertexCount,
        int *indexCount)
{
  UtlLinkedListElem_t<CDispShadowDecal,unsigned short> *v5; // esi
  const VMatrix *v7; // edi
  float v8; // xmm0_4
  CDispInfo *v9; // edi
  int m_nVerts; // ecx
  _BYTE v11[12]; // [esp-Ch] [ebp-2DCh] BYREF
  Frustum_t shadowFrustum; // [esp+0h] [ebp-2D0h] BYREF
  unsigned __int16 pIntersectingNodes[85]; // [esp+148h] [ebp-188h] BYREF
  VMatrix normalizedWorldToShadow; // [esp+1F8h] [ebp-D8h] BYREF
  VMatrix shadowToWorld; // [esp+238h] [ebp-98h] BYREF
  VMatrix matZScale; // [esp+278h] [ebp-58h] BYREF
  CDispInfo *v17; // [esp+2BCh] [ebp-14h]
  int v18[3]; // [esp+2C0h] [ebp-10h] BYREF
  int retaddr; // [esp+2D0h] [ebp+0h]

  v18[1] = a2;
  v18[2] = retaddr;
  v17 = this;
  v5 = &s_DispShadowDecals.m_Memory.m_pMemory[h];
  if ( (v5->m_Element.m_Flags & 8) != 0 )
  {
    *vertexCount = v5->m_Element.m_nVerts;
    *indexCount = 3 * v5->m_Element.m_nTris;
    return 1;
  }
  else
  {
    v7 = (const VMatrix *)((int (__cdecl *)(_DWORD))g_pShadowMgr->GetInfo)(a1: v5->m_Element.m_Shadow);
    v17 = (CDispInfo *)&matZScale.m[3][2];
    *(_QWORD *)&matZScale.m[3][2] = 0x3F8000003F800000LL;
    v8 = 1.0 / v7[1].m[0][1];
    v18[0] = 0;
    SetupMatrixScale(result: (VMatrix *)LODWORD(v8), vScale: (const Vector *)&matZScale.m[3][2]);
    MatrixMultiply(src1: (VMatrix *)&shadowToWorld.m[3][1], src2: v7, dst: (VMatrix *)&pIntersectingNodes[82]);
    Frustum_t::Frustum_t(this: (Frustum_t *)v11);
    MatrixInverseGeneral(
      src: (const VMatrix *)&pIntersectingNodes[82],
      dst: (VMatrix *)&normalizedWorldToShadow.m[3][1]);
    FrustumPlanesFromMatrix(clipToWorld: (VMatrix *)&normalizedWorldToShadow.m[3][1], frustum: (Frustum_t *)v11);
    v9 = v17;
    CDispInfo::FindNodesInShadowFrustum(
      this: v17,
      frustum: (Frustum_t *)v11,
      pNodeArray: &shadowFrustum.planes[1].nZAbs.m128_u16[6],
      pNumNodes: v18,
      iNodeBit: 0,
      iLevel: 0);
    if ( v18[0] != 0 )
    {
      CDispInfo::AddNodeTrisToDecal(
        this: v9,
        pDispDecal: &v5->m_Element,
        decalHandle: h,
        pNodeIndices: &shadowFrustum.planes[1].nZAbs.m128_u16[6],
        nNumIndices: v18[0]);
      m_nVerts = v5->m_Element.m_nVerts;
      v5->m_Element.m_Flags |= 8u;
      *vertexCount = m_nVerts;
      *indexCount = 3 * v5->m_Element.m_nTris;
      return 1;
    }
    else
    {
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BDAC0
// Name: void DispInfo_DrawPrimLists(class IMatRenderContext __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall DispInfo_DrawPrimLists(
        int a1@<ebx>,
        int m_LightmapPageID@<edi>,
        IMaterial *a3@<esi>,
        IMatRenderContext *pRenderContext,
        bool bShadowDepth)
{
  int v5; // eax
  CDispGroup *v6; // edi
  int v7; // ebx
  IMaterial *v8; // esi
  IMaterialVar *v9; // ebx
  IMaterialVar *v10; // ecx
  IMaterialVar_vtbl *v11; // edx
  int v12; // eax
  int v13; // eax
  IMatRenderContext *v14; // ebx
  IMaterialVar *m_Size; // edx
  int v16; // ecx
  CGroupMesh *v17; // esi
  int m_nVisible; // eax
  int v19; // ebx
  float v23; // [esp+44h] [ebp-24h]
  int nDispGroupsSize; // [esp+48h] [ebp-20h]
  int nFullbright; // [esp+4Ch] [ebp-1Ch]
  IMaterialVar *pOriginalAlphaRefVar; // [esp+50h] [ebp-18h]
  IMaterialVar *pOriginalAlphaRefVara; // [esp+50h] [ebp-18h]
  IMaterialVar *pOriginalTextureFrameVar; // [esp+54h] [ebp-14h]
  IMaterialVar *pTextureFrameVar; // [esp+58h] [ebp-10h]
  IMaterialVar *pOriginalTextureVar; // [esp+5Ch] [ebp-Ch]
  IMaterialVar *pOriginalTextureVara; // [esp+5Ch] [ebp-Ch]
  int iGroup; // [esp+60h] [ebp-8h]
  int iMesh; // [esp+64h] [ebp-4h]
  int iMesha; // [esp+64h] [ebp-4h]

  v5 = 0;
  nDispGroupsSize = g_DispGroups.m_Size;
  nFullbright = g_pMaterialSystemConfig->nFullbright;
  for ( iGroup = 0; v5 < nDispGroupsSize; iGroup = v5 )
  {
    v6 = g_DispGroups.m_Memory.m_pMemory[v5];
    if ( v6->m_nVisible != 0 )
    {
      if ( bShadowDepth )
      {
        v7 = ((unsigned __int8 (__thiscall *)(IMaterial *, int, IMaterial *, int))v6->m_pMaterial->IsAlphaTested)(
               a1: v6->m_pMaterial,
               a2: m_LightmapPageID,
               a3,
               a4: a1);
        v8 = g_pMaterialDepthWrite[v7][(unsigned __int8)v6->m_pMaterial->IsTwoSided(this: v6->m_pMaterial)];
        if ( v7 == 1 )
        {
          pOriginalTextureVar = v6->m_pMaterial->FindVarFast(
                                  this: v6->m_pMaterial,
                                  a2: "$basetexture",
                                  a3: &originalTextureVarCache_1);
          pOriginalTextureFrameVar = v6->m_pMaterial->FindVarFast(
                                       this: v6->m_pMaterial,
                                       a2: "$frame",
                                       a3: &originalTextureFrameVarCache_1);
          pOriginalAlphaRefVar = v6->m_pMaterial->FindVarFast(
                                   this: v6->m_pMaterial,
                                   a2: "$AlphaTestReference",
                                   a3: &originalAlphaRefCache_1);
          v9 = v8->FindVarFast(this: v8, a2: "$basetexture", a3: &textureVarCache_1);
          pTextureFrameVar = v8->FindVarFast(this: v8, a2: "$frame", a3: &textureFrameVarCache_1);
          iMesh = (int)v8->FindVarFast(this: v8, a2: "$AlphaTestReference", a3: &alphaRefCache_1);
          if ( v9 != nullptr )
          {
            v10 = pOriginalTextureVar;
            if ( pOriginalTextureVar != nullptr )
            {
              v11 = pOriginalTextureVar->__vftable;
              pOriginalTextureVara = (IMaterialVar *)&v9->SetTextureValue;
              v12 = v11->GetTextureValue(this: v10);
              ((void (__thiscall *)(IMaterialVar *, int))pOriginalTextureVara->__vftable)(a1: v9, a2: v12);
            }
          }
          if ( pTextureFrameVar != nullptr && pOriginalTextureFrameVar != nullptr )
          {
            v13 = pOriginalTextureFrameVar->GetIntValueInternal(this: pOriginalTextureFrameVar);
            pTextureFrameVar->SetIntValue(this: pTextureFrameVar, a2: v13);
          }
          if ( iMesh != 0 && pOriginalAlphaRefVar != nullptr )
          {
            v23 = pOriginalAlphaRefVar->GetFloatValueInternal(this: pOriginalAlphaRefVar);
            (*(void (__stdcall **)(_DWORD))(*(_DWORD *)iMesh + 16))(a1: LODWORD(v23));
          }
        }
        v14 = pRenderContext;
        a1 = 0;
        a3 = v8;
        ((void (__thiscall *)(IMatRenderContext *))pRenderContext->Bind)(a1: pRenderContext);
      }
      else
      {
        ((void (__thiscall *)(IMatRenderContext *, IMaterial *, _DWORD, int))pRenderContext->Bind)(
          a1: pRenderContext,
          a2: v6->m_pMaterial,
          a3: 0,
          a4: m_LightmapPageID);
        v14 = pRenderContext;
      }
      if ( nFullbright == 1 || bShadowDepth )
      {
        if ( v6->m_pMaterial->GetPropertyFlag(this: v6->m_pMaterial, a2: MATERIAL_PROPERTY_NEEDS_BUMPED_LIGHTMAPS) )
          m_LightmapPageID = -2;
        else
          m_LightmapPageID = -1;
      }
      else
      {
        m_LightmapPageID = v6->m_LightmapPageID;
      }
      ((void (__thiscall *)(IMatRenderContext *))v14->BindLightmapPage)(a1: v14);
      m_Size = (IMaterialVar *)v6->m_Meshes.m_Size;
      v16 = 0;
      pOriginalAlphaRefVara = m_Size;
      for ( iMesha = 0; v16 < (int)m_Size; iMesha = v16 )
      {
        v17 = v6->m_Meshes.m_Memory.m_pMemory[v16];
        m_nVisible = v17->m_nVisible;
        if ( m_nVisible != 0 )
        {
          if ( disp_dynamic.m_pParent != nullptr && disp_dynamic.m_pParent->m_Value.m_nValue != 0 )
          {
            v19 = 0;
            if ( m_nVisible > 0 )
            {
              do
                CDispInfo::SpecifyDynamicMesh(this: v17->m_VisibleDisps.m_Memory.m_pMemory[v19++]);
              while ( v19 < v17->m_nVisible );
            }
          }
          else
          {
            v17->m_pMesh->Draw(this: v17->m_pMesh, a2: v17->m_Visible.m_Memory.m_pMemory, a3: v17->m_nVisible);
          }
          v16 = iMesha;
          m_Size = pOriginalAlphaRefVara;
          v17->m_nVisible = 0;
        }
        ++v16;
      }
    }
    v5 = iGroup + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BDD10
// Name: void DispInfo_RenderListWorld(class IMatRenderContext __near *,int,struct msurface2_t __near * __near *,int,bool,unsigned long,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall DispInfo_RenderListWorld(
        int a1@<ebx>,
        int a2@<edi>,
        IMatRenderContext *pRenderContext,
        int nSortGroup,
        msurface2_t **pList,
        int listCount,
        bool bOrtho,
        __int16 flags,
        IMaterial *bShadowDepth)
{
  CDispInfo *visibleDisps; // [esp+0h] [ebp-2004h] BYREF
  int nVisibleDisps; // [esp+2000h] [ebp-4h] BYREF

  if ( r_DrawDisp.m_pParent != nullptr
    && r_DrawDisp.m_pParent->m_Value.m_nValue != 0
    && listCount != 0
    && (flags & 0x200) != 0 )
  {
    g_bDispOrthoRender = bOrtho;
    DispInfo_BuildPrimLists(nSortGroup, pList, listCount, bDepthOnly: (bool)bShadowDepth, &visibleDisps, &nVisibleDisps);
    DispInfo_DrawPrimLists(a1, m_LightmapPageID: a2, a3: bShadowDepth, pRenderContext, (bool)bShadowDepth);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BE8B0
// Name: int DispInfo_AddShadowsToMeshBuilder(class CMeshBuilder __near &,unsigned short,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DispInfo_AddShadowsToMeshBuilder(CMeshBuilder *meshBuilder, unsigned __int16 h, int baseIndex)
{
  UtlLinkedListElem_t<CDispShadowDecal,unsigned short> *v3; // esi
  unsigned __int16 m_FirstFragment; // ax
  int v6; // edx
  UtlLinkedListElem_t<CDispShadowFragment,unsigned short> *m_pMemory; // ecx
  unsigned int m_nIndexSize; // ebx
  int v9; // eax
  ShadowVertex_t *m_ShadowVerts; // edi
  const CDispShadowFragment *p_m_Element; // eax
  int v12; // eax
  unsigned __int16 *v13; // eax
  unsigned __int16 *m_pIndices; // ecx
  __int16 v15; // bx
  unsigned __int16 v16; // cx
  int v17; // ecx
  int v18; // ebx
  float *p_z; // eax
  float *v20; // ecx
  float v21; // xmm1_4
  float v22; // xmm2_4
  float y; // xmm0_4
  float v24; // xmm0_4
  int v25; // ebx
  int v26; // xmm1_4
  float *v27; // ecx
  float *v28; // ecx
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm0_4
  float v32; // xmm0_4
  int v33; // xmm1_4
  float *v34; // ecx
  Vector *v35; // ecx
  unsigned __int16 *v36; // ebx
  float *v37; // ecx
  float v38; // xmm1_4
  float v39; // xmm2_4
  float v40; // xmm0_4
  float v41; // xmm0_4
  double v42; // st7
  int v43; // xmm1_4
  float *v44; // ecx
  Vector *v45; // ecx
  float *v46; // ecx
  float v47; // xmm1_4
  float v48; // xmm2_4
  float v49; // xmm0_4
  float v50; // xmm0_4
  int v51; // xmm1_4
  float *v52; // ecx
  float *v53; // ecx
  unsigned __int16 *v54; // ebx
  bool v55; // zf
  int v56; // ebx
  float *v57; // ecx
  float *v58; // eax
  float v59; // xmm1_4
  float v60; // xmm2_4
  float v61; // xmm0_4
  float v62; // xmm0_4
  double v63; // st7
  int v64; // xmm1_4
  float *v65; // eax
  Vector *v66; // eax
  float *v67; // eax
  float v68; // xmm1_4
  float v69; // xmm2_4
  float v70; // xmm0_4
  float v71; // xmm0_4
  float z; // xmm1_4
  float *v73; // eax
  Vector *v74; // eax
  int v75; // edx
  float *v76; // eax
  float v77; // xmm1_4
  float v78; // xmm2_4
  float v79; // xmm0_4
  float v80; // xmm0_4
  float v81; // xmm1_4
  float *v82; // eax
  Vector *v83; // eax
  int m_nCurrentIndex; // eax
  ShadowDecalRenderInfo_t info; // [esp+4h] [ebp-40h] BYREF
  int v87; // [esp+30h] [ebp-14h]
  const CDispShadowFragment *fragment; // [esp+34h] [ebp-10h]
  unsigned int v89; // [esp+38h] [ebp-Ch]
  int i; // [esp+3Ch] [ebp-8h]
  unsigned __int16 *v91; // [esp+40h] [ebp-4h]
  int nIndices; // [esp+4Ch] [ebp+8h]
  int triangleCount; // [esp+50h] [ebp+Ch]

  v3 = &s_DispShadowDecals.m_Memory.m_pMemory[h];
  ((void (__stdcall *)(ShadowDecalRenderInfo_t *, _DWORD))g_pShadowMgr->ComputeRenderInfo)(
    a1: &info,
    a2: v3->m_Element.m_Shadow);
  m_FirstFragment = v3->m_Element.m_FirstFragment;
  v6 = 0;
  nIndices = 0;
  if ( m_FirstFragment != 0xFFFF )
  {
    m_pMemory = s_DispShadowFragments.m_Memory.m_pMemory;
    do
    {
      m_nIndexSize = meshBuilder->m_IndexBuilder.m_nIndexSize;
      v9 = m_FirstFragment;
      m_ShadowVerts = m_pMemory[v9].m_Element.m_ShadowVerts;
      v87 = v9 * 12;
      p_m_Element = &m_pMemory[v9].m_Element;
      m_pIndices = meshBuilder->m_IndexBuilder.m_pIndices;
      fragment = p_m_Element;
      triangleCount = p_m_Element->m_nVerts - 2;
      v12 = nIndices + meshBuilder->m_IndexBuilder.m_nCurrentIndex;
      i = triangleCount * m_nIndexSize;
      v13 = &m_pIndices[v12];
      v89 = baseIndex + meshBuilder->m_IndexBuilder.m_nIndexOffset;
      LOWORD(m_pIndices) = 0;
      v91 = nullptr;
      if ( (int)(triangleCount * m_nIndexSize) > 0 )
      {
        do
        {
          v15 = v89;
          v16 = v89 + (_WORD)m_pIndices + 1;
          *v13 = v89;
          v13[1] = v16;
          v13[2] = v15 + (_WORD)v91 + 2;
          m_pIndices = (unsigned __int16 *)((char *)v91 + 1);
          v13 += 3;
          v91 = m_pIndices;
        }
        while ( (int)m_pIndices < i );
      }
      v17 = triangleCount;
      nIndices += triangleCount + 2 * triangleCount;
      i = 0;
      if ( triangleCount >= 4 )
      {
        v89 = ((unsigned int)(triangleCount - 4) >> 2) + 1;
        v18 = v6 + 2;
        v91 = (unsigned __int16 *)(v6 + 2);
        p_z = &m_ShadowVerts[2].m_Position.z;
        i = 4 * v89;
        do
        {
          v20 = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                        + v6 * meshBuilder->m_VertexBuilder.m_VertexSize_Position);
          v21 = *(p_z - 10) * info.m_vTexSize.y;
          v22 = info.m_vTexOrigin.x + (float)(*(p_z - 11) * info.m_vTexSize.x);
          y = info.m_vTexOrigin.y;
          *v20 = m_ShadowVerts->m_Position.x;
          v24 = y + v21;
          v20[1] = *(p_z - 13);
          v25 = v18 - 1;
          v20[2] = *(p_z - 12);
          v26 = *((_DWORD *)p_z - 9);
          v27 = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0]
                        + v6 * meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[0]);
          *v27 = v22;
          v27[1] = v24;
          *((_DWORD *)v27 + 2) = v26;
          *(Vector *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1]
                    + v6 * meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[1]) = info.m_vShadowFalloffParams;
          v28 = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                        + v25 * meshBuilder->m_VertexBuilder.m_VertexSize_Position);
          v29 = *(p_z - 4) * info.m_vTexSize.y;
          v30 = info.m_vTexOrigin.x + (float)(*(p_z - 5) * info.m_vTexSize.x);
          v31 = info.m_vTexOrigin.y;
          *v28 = *(p_z - 8);
          v32 = v31 + v29;
          v28[1] = *(p_z - 7);
          v28[2] = *(p_z - 6);
          v33 = *((_DWORD *)p_z - 3);
          v34 = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0]
                        + v25 * meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[0]);
          *v34 = v30;
          v34[1] = v32;
          *((_DWORD *)v34 + 2) = v33;
          v35 = (Vector *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1]
                         + v25 * meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[1]);
          v36 = v91;
          *v35 = info.m_vShadowFalloffParams;
          v37 = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                        + (_DWORD)v36 * meshBuilder->m_VertexBuilder.m_VertexSize_Position);
          v38 = p_z[2] * info.m_vTexSize.y;
          v39 = info.m_vTexOrigin.x + (float)(p_z[1] * info.m_vTexSize.x);
          v40 = info.m_vTexOrigin.y;
          *v37 = *(p_z - 2);
          v41 = v40 + v38;
          v6 += 4;
          v37[1] = *(p_z - 1);
          m_ShadowVerts += 4;
          v42 = *p_z;
          p_z += 24;
          v37[2] = v42;
          v43 = *((_DWORD *)p_z - 21);
          v44 = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0]
                        + (_DWORD)v36 * meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[0]);
          *v44 = v39;
          v44[1] = v41;
          *((_DWORD *)v44 + 2) = v43;
          v45 = (Vector *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1]
                         + (_DWORD)v36 * meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[1]);
          v36 = (unsigned __int16 *)((char *)v36 + 1);
          *v45 = info.m_vShadowFalloffParams;
          v46 = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                        + (_DWORD)v36 * meshBuilder->m_VertexBuilder.m_VertexSize_Position);
          v47 = *(p_z - 16) * info.m_vTexSize.y;
          v48 = info.m_vTexOrigin.x + (float)(*(p_z - 17) * info.m_vTexSize.x);
          v49 = info.m_vTexOrigin.y;
          *v46 = *(p_z - 20);
          v50 = v49 + v47;
          v46[1] = *(p_z - 19);
          v46[2] = *(p_z - 18);
          v51 = *((_DWORD *)p_z - 15);
          v52 = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0]
                        + (_DWORD)v36 * meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[0]);
          *v52 = v48;
          v52[1] = v50;
          *((_DWORD *)v52 + 2) = v51;
          v53 = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1]
                        + (_DWORD)v36 * meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[1]);
          v54 = v91;
          *v53 = info.m_vShadowFalloffParams.x;
          v53[1] = info.m_vShadowFalloffParams.y;
          v18 = (int)(v54 + 2);
          v55 = v89-- == 1;
          v53[2] = info.m_vShadowFalloffParams.z;
          v91 = (unsigned __int16 *)v18;
        }
        while ( !v55 );
        v17 = triangleCount;
      }
      if ( i < v17 )
      {
        v56 = triangleCount - i;
        v57 = &m_ShadowVerts->m_Position.z;
        do
        {
          v58 = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                        + v6 * meshBuilder->m_VertexBuilder.m_VertexSize_Position);
          v59 = v57[2] * info.m_vTexSize.y;
          v60 = info.m_vTexOrigin.x + (float)(v57[1] * info.m_vTexSize.x);
          v61 = info.m_vTexOrigin.y;
          *v58 = m_ShadowVerts->m_Position.x;
          v62 = v61 + v59;
          v58[1] = *(v57 - 1);
          ++m_ShadowVerts;
          v63 = *v57;
          v57 += 6;
          v58[2] = v63;
          v64 = *((_DWORD *)v57 - 3);
          v65 = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0]
                        + v6 * meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[0]);
          *v65 = v60;
          v65[1] = v62;
          *((_DWORD *)v65 + 2) = v64;
          v66 = (Vector *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1]
                         + v6 * meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[1]);
          ++v6;
          --v56;
          *v66 = info.m_vShadowFalloffParams;
        }
        while ( v56 != 0 );
      }
      v67 = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                    + v6 * meshBuilder->m_VertexBuilder.m_VertexSize_Position);
      v68 = m_ShadowVerts->m_ShadowSpaceTexCoord.y * info.m_vTexSize.y;
      v69 = info.m_vTexOrigin.x + (float)(m_ShadowVerts->m_ShadowSpaceTexCoord.x * info.m_vTexSize.x);
      v70 = info.m_vTexOrigin.y;
      *v67 = m_ShadowVerts->m_Position.x;
      v71 = v70 + v68;
      v67[1] = m_ShadowVerts->m_Position.y;
      v67[2] = m_ShadowVerts->m_Position.z;
      z = m_ShadowVerts->m_ShadowSpaceTexCoord.z;
      v73 = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0]
                    + v6 * meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[0]);
      *v73 = v69;
      v73[1] = v71;
      v73[2] = z;
      v74 = (Vector *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1]
                     + v6 * meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[1]);
      v75 = v6 + 1;
      *v74 = info.m_vShadowFalloffParams;
      v76 = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                    + v75 * meshBuilder->m_VertexBuilder.m_VertexSize_Position);
      v77 = m_ShadowVerts[1].m_ShadowSpaceTexCoord.y * info.m_vTexSize.y;
      v78 = info.m_vTexOrigin.x + (float)(m_ShadowVerts[1].m_ShadowSpaceTexCoord.x * info.m_vTexSize.x);
      v79 = info.m_vTexOrigin.y;
      *v76 = m_ShadowVerts[1].m_Position.x;
      v80 = v79 + v77;
      v76[1] = m_ShadowVerts[1].m_Position.y;
      v76[2] = m_ShadowVerts[1].m_Position.z;
      v81 = m_ShadowVerts[1].m_ShadowSpaceTexCoord.z;
      v82 = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0]
                    + v75 * meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[0]);
      *v82 = v78;
      v82[1] = v80;
      v82[2] = v81;
      v83 = (Vector *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1]
                     + v75 * meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[1]);
      v6 = v75 + 1;
      *v83 = info.m_vShadowFalloffParams;
      baseIndex += fragment->m_nVerts;
      m_pMemory = s_DispShadowFragments.m_Memory.m_pMemory;
      m_FirstFragment = *(unsigned __int16 *)((char *)&s_DispShadowFragments.m_Memory.m_pMemory->m_Next + v87);
    }
    while ( m_FirstFragment != 0xFFFF );
  }
  CVertexBuilder::AdvanceVertices(this: &meshBuilder->m_VertexBuilder, nVerts: v6);
  meshBuilder->m_IndexBuilder.m_nCurrentIndex += nIndices * meshBuilder->m_IndexBuilder.m_nIndexSize;
  m_nCurrentIndex = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
  if ( m_nCurrentIndex > meshBuilder->m_IndexBuilder.m_nIndexCount )
    meshBuilder->m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
  return baseIndex;
}

//------------------------------------------------------------------------------
// Address: 0x100BEE80
// Name: DispInfo_DrawChainNormals
// Source: json
//------------------------------------------------------------------------------
void __usercall DispInfo_DrawChainNormals(
        CMeshBuilder *p_meshBuilder@<edi>,
        IMatRenderContext *pRenderContext,
        msurface2_t **pList,
        int listCount)
{
  IMatRenderContext *v4; // esi
  IMatRenderContext_vtbl *v5; // edx
  int v6; // edi
  IMesh *(__thiscall *GetDynamicMesh)(IMatRenderContext *, bool, IMesh *, IMesh *, IMaterial *); // eax
  IMesh *v8; // esi
  void (__thiscall *SetPrimitiveType)(IMesh *, MaterialPrimitiveType_t); // eax
  int m_nVertexCount; // edx
  float *m_pPosition; // eax
  int v12; // edi
  CDispRenderVert *m_pMemory; // esi
  double x; // st7
  float *p_x; // esi
  float *m_pCurrPosition; // eax
  float v17; // xmm1_4
  float v18; // xmm2_4
  float *v19; // eax
  float *v20; // eax
  float v21; // xmm1_4
  float v22; // xmm2_4
  float *v23; // eax
  float v24; // xmm1_4
  float v25; // xmm2_4
  float *v26; // eax
  int v27; // eax
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1FCh] BYREF
  CDispInfo *pDisp; // [esp+1F0h] [ebp-14h]
  IMesh *pMesh; // [esp+1F4h] [ebp-10h]
  int nVerts; // [esp+1F8h] [ebp-Ch]
  int i; // [esp+1FCh] [ebp-8h]
  int v34; // [esp+200h] [ebp-4h]

  v4 = pRenderContext;
  pRenderContext->Bind(this: pRenderContext, a2: g_pMaterialWireframeVertexColor, a3: nullptr);
  i = 0;
  if ( listCount > 0 )
  {
    while ( 1 )
    {
      v5 = v4->__vftable;
      pDisp = (CDispInfo *)pList[i]->pDispInfo;
      GetDynamicMesh = v5->GetDynamicMesh;
      nVerts = pDisp->m_pPowerInfo->m_MaxVerts;
      v6 = nVerts;
      v8 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, CMeshBuilder *))GetDynamicMesh)(
                      a1: v4,
                      a2: 1,
                      a3: 0,
                      a4: 0,
                      a5: 0,
                      a6: p_meshBuilder);
      meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
      meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
      meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
      memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
      meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
      meshBuilder.m_pMesh = v8;
      meshBuilder.m_bGenerateIndices = true;
      meshBuilder.m_Type = MATERIAL_LINES;
      v6 *= 6;
      SetPrimitiveType = v8->SetPrimitiveType;
      pMesh = v8;
      v34 = v6;
      SetPrimitiveType(this: v8, a2: MATERIAL_LINES);
      meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v6, a3: v6, a4: &meshBuilder, a5: nullptr);
      meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v8->IIndexBuffer;
      meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v6;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = v8;
      meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_bModify = false;
      meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
      meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
      meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
      m_nVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = v34;
      meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_bModify = false;
      if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
      {
        meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
        meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
      }
      meshBuilder.m_VertexBuilder.m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pNormal;
      qmemcpy(
        meshBuilder.m_VertexBuilder.m_pCurrTexCoord,
        meshBuilder.m_VertexBuilder.m_pTexCoord,
        sizeof(meshBuilder.m_VertexBuilder.m_pCurrTexCoord));
      m_pPosition = meshBuilder.m_VertexBuilder.m_pPosition;
      meshBuilder.m_VertexBuilder.m_pCurrColor = meshBuilder.m_VertexBuilder.m_pColor;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      meshBuilder.m_VertexBuilder.m_nCurrentVertex = 0;
      meshBuilder.m_VertexBuilder.m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pPosition;
      if ( nVerts > 0 )
      {
        v12 = 0;
        v34 = nVerts;
        while ( 1 )
        {
          m_pMemory = pDisp->m_Verts.m_Memory.m_pMemory;
          x = m_pMemory[v12].m_vPos.x;
          p_x = &m_pMemory[v12].m_vPos.x;
          *m_pPosition = x;
          m_pPosition[1] = p_x[1];
          m_pPosition[2] = p_x[2];
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          v17 = (float)(p_x[4] * 5.0) + p_x[1];
          v18 = (float)(p_x[5] * 5.0) + p_x[2];
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(p_x[3] * 5.0) + *p_x;
          m_pCurrPosition[1] = v17;
          m_pCurrPosition[2] = v18;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v19 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = *p_x;
          v19[1] = p_x[1];
          v19[2] = p_x[2];
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v20 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          v21 = (float)(p_x[7] * 5.0) + p_x[1];
          v22 = (float)(p_x[8] * 5.0) + p_x[2];
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(p_x[6] * 5.0) + *p_x;
          v20[1] = v21;
          v20[2] = v22;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v23 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = *p_x;
          v23[1] = p_x[1];
          v23[2] = p_x[2];
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v24 = (float)(p_x[10] * 5.0) + p_x[1];
          v25 = (float)(p_x[11] * 5.0) + p_x[2];
          v26 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(p_x[9] * 5.0) + *p_x;
          v26[1] = v24;
          v26[2] = v25;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          ++v12;
          if ( --v34 == 0 )
            break;
          m_pPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        }
        m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
      }
      if ( meshBuilder.m_bGenerateIndices )
      {
        switch ( meshBuilder.m_Type )
        {
          case MATERIAL_LINE_STRIP:
            v27 = 2 * m_nVertexCount - 2;
            break;
          case MATERIAL_LINE_LOOP:
            v27 = 2 * m_nVertexCount;
            break;
          case MATERIAL_POLYGON:
            v27 = 3 * m_nVertexCount - 6;
            break;
          case MATERIAL_QUADS:
            v27 = 6 * m_nVertexCount / 4;
            break;
          case MATERIAL_INSTANCED_QUADS:
            v27 = 0;
            break;
          default:
            v27 = m_nVertexCount;
            break;
        }
        CIndexBuilder::GenerateIndices(
          this: &meshBuilder.m_IndexBuilder,
          primitiveType: meshBuilder.m_Type,
          nIndexCount: v27);
        m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
      }
      p_meshBuilder = &meshBuilder;
      ((void (__thiscall *)(IMesh *, int, int))meshBuilder.m_pMesh->UnlockMesh)(
        a1: meshBuilder.m_pMesh,
        a2: m_nVertexCount,
        a3: meshBuilder.m_IndexBuilder.m_nIndexCount);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      meshBuilder.m_pMesh = nullptr;
      pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
      if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
        && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
      {
        meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
      }
      if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
        && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
      {
        meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
      }
      if ( ++i >= listCount )
        break;
      v4 = pRenderContext;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BF330
// Name: void DispInfo_RenderListDebug(class IMatRenderContext __near *,struct msurface2_t __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispInfo_RenderListDebug(IMatRenderContext *pRenderContext, msurface2_t **pList, CMeshBuilder *listCount)
{
  CMeshBuilder *i; // esi
  CDispInfo *pDispInfo; // ecx

  if ( DispInfoRenderDebugModes() )
  {
    for ( i = nullptr; (int)i < (int)listCount; i = (CMeshBuilder *)((char *)i + 1) )
    {
      pDispInfo = (CDispInfo *)pList[(_DWORD)i]->pDispInfo;
      CDispInfo::Render(this: pDispInfo, pGroup: pDispInfo->m_pMesh, bAllowDebugModes: true);
    }
  }
  if ( mat_normals.m_pParent != nullptr && mat_normals.m_pParent->m_Value.m_nValue != 0 )
    DispInfo_DrawChainNormals(p_meshBuilder: listCount, pRenderContext, pList, (int)listCount);
}

//------------------------------------------------------------------------------
// Address: 0x100BF570
// Name: void DispInfo_BatchDecals(class CDispInfo __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispInfo_BatchDecals(CDispInfo **pVisibleDisps, int nVisibleDisps)
{
  int v2; // edi
  int v3; // esi
  UtlLinkedListElem_t<CDispDecal,unsigned short> *m_pMemory; // ecx
  CDispInfo *v5; // edx
  unsigned __int16 m_FirstDecal; // ax
  int v7; // edi
  int v8; // ebx
  CDispDecalBase *p_m_Element; // esi
  int v10; // ecx
  int v11; // edi
  _DWORD *v12; // eax
  unsigned int v13; // esi
  int v14; // ecx
  int v15; // esi
  DecalMaterialBucket_t *v16; // ecx
  int m_nCheckCount; // edx
  int *p_m_iHead; // esi
  _DWORD *v19; // [esp+4h] [ebp-Ch]
  CDispInfo *pDisp; // [esp+8h] [ebp-8h]
  int iDisp; // [esp+Ch] [ebp-4h]

  CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::RemoveAll(this: &g_aDispDecalSortPool);
  v2 = nVisibleDisps;
  ++g_nDispDecalSortCheckCount;
  if ( nVisibleDisps != 0 )
  {
    v3 = 0;
    iDisp = 0;
    if ( nVisibleDisps > 0 )
    {
      m_pMemory = s_DispDecals.m_Memory.m_pMemory;
      do
      {
        v5 = pVisibleDisps[v3];
        m_FirstDecal = v5->m_FirstDecal;
        pDisp = v5;
        if ( m_FirstDecal != 0xFFFF )
        {
          while ( 1 )
          {
            v7 = m_FirstDecal;
            v8 = m_FirstDecal;
            p_m_Element = &m_pMemory[m_FirstDecal].m_Element;
            if ( (p_m_Element->m_Flags & 8) == 0 )
            {
              CDispInfo::GenerateDecalFragments_R(
                this: v5,
                nodeIndex: &v5->m_pPowerInfo->m_RootNode,
                iNodeBitIndex: 0,
                decalHandle: m_FirstDecal,
                pDispDecal: p_m_Element,
                iLevel: 0);
              p_m_Element->m_Flags |= 8u;
              m_pMemory = s_DispDecals.m_Memory.m_pMemory;
            }
            if ( p_m_Element->m_nTris != 0 )
            {
              v10 = *(_DWORD *)(p_m_Element[1].m_NodeIntersect.m_Ints[0] + 12);
              if ( v10 != 0 )
              {
                if ( (*(unsigned __int8 (__thiscall **)(int, _DWORD))(*(_DWORD *)v10 + 128))(a1: v10, a2: 0) != 0 )
                  v11 = (*(_BYTE *)(p_m_Element[1].m_NodeIntersect.m_Ints[0] + 84) & 1) == 0;
                else
                  v11 = 2;
                v12 = (_DWORD *)CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int>>>::AllocInternal(
                                  this: &g_aDispDecalSortPool,
                                  multilist: true);
                *v12 = p_m_Element[1].m_NodeIntersect.m_Ints[0];
                v13 = p_m_Element[1].m_NodeIntersect.m_Ints[0];
                v14 = *(_DWORD *)(v13 + 88);
                v15 = *(_DWORD *)(v13 + 92);
                v16 = g_aDispDecalSortTrees.m_Memory.m_pMemory[v14].m_aDecalSortBuckets[0][v11].m_Memory.m_pMemory;
                m_nCheckCount = v16[v15].m_nCheckCount;
                p_m_iHead = &v16[v15].m_iHead;
                v19 = v12;
                if ( m_nCheckCount == g_nDispDecalSortCheckCount )
                {
                  CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::LinkBefore(
                    this: &g_aDispDecalSortPool,
                    before: *p_m_iHead,
                    elem: (int)v12);
                  v12 = v19;
                }
                *p_m_iHead = (int)v12;
                p_m_iHead[1] = g_nDispDecalSortCheckCount;
              }
              else
              {
                DevMsg(a1: "DispInfo_BatchDecals: material is NULL, decal %i.\n", v7);
              }
              m_pMemory = s_DispDecals.m_Memory.m_pMemory;
            }
            m_FirstDecal = m_pMemory[v8].m_Next;
            if ( m_FirstDecal == 0xFFFF )
              break;
            v5 = pDisp;
          }
          v3 = iDisp;
          v2 = nVisibleDisps;
        }
        iDisp = ++v3;
      }
      while ( v3 < v2 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BF6F0
// Name: void DispInfo_DrawDecalMeshList(class IMatRenderContext __near *,struct DecalMeshList_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispInfo_DrawDecalMeshList(IMatRenderContext *pRenderContext, DecalMeshList_t *meshList)
{
  char *v3; // esi
  bool bMatFullbright; // [esp+7h] [ebp-1h]
  DecalMeshList_t *meshLista; // [esp+14h] [ebp+Ch]

  bMatFullbright = g_pMaterialSystemConfig->nFullbright == 1;
  if ( meshList->m_aBatches.m_Size > 0 )
  {
    v3 = &meshList->m_aBatches.m_Memory.m_Memory[4];
    meshLista = (DecalMeshList_t *)meshList->m_aBatches.m_Size;
    do
    {
      if ( bMatFullbright )
        ((void (__stdcall *)(int))pRenderContext->BindLightmapPage)(a1: -1);
      else
        ((void (__stdcall *)(_DWORD))pRenderContext->BindLightmapPage)(a1: *((_DWORD *)v3 + 1));
      pRenderContext->Bind(this: pRenderContext, a2: *((IMaterial **)v3 - 1), a3: *(void **)v3);
      ((void (__stdcall *)(_DWORD, _DWORD))meshList->m_pMesh->Draw_2)(
        a1: *((unsigned __int16 *)v3 + 4),
        a2: *((unsigned __int16 *)v3 + 5));
      v3 += 16;
      meshLista = (DecalMeshList_t *)((char *)meshLista - 1);
    }
    while ( meshLista != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BF930
// Name: private: class CDispDecalFragment __near * CDispInfo::AllocateDispDecalFragment(unsigned short,int)
// Source: json
//------------------------------------------------------------------------------
UtlLinkedListElem_t<CDispDecalFragment,unsigned short> *__thiscall CDispInfo::AllocateDispDecalFragment(
        CDispInfo *this,
        unsigned __int16 h,
        int nVerts)
{
  unsigned __int16 v3; // ax
  unsigned __int16 v4; // di
  UtlLinkedListElem_t<CDispDecalFragment,unsigned short> *v5; // esi

  v3 = CUtlLinkedList<CDispDecalFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecalFragment,unsigned short>,unsigned short>>::AllocInternal(
         this: &s_DispDecalFragments,
         multilist: true);
  v4 = -1;
  if ( v3 != 0xFFFF )
    v4 = v3;
  CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::LinkBefore(
    this: &s_DispDecalFragments,
    before: s_DispDecals.m_Memory.m_pMemory[h].m_Element.m_FirstFragment,
    elem: v4);
  s_DispDecals.m_Memory.m_pMemory[h].m_Element.m_FirstFragment = v4;
  v5 = &s_DispDecalFragments.m_Memory.m_pMemory[v4];
  v5->m_Element.m_nVerts = nVerts;
  v5->m_Element.m_pVerts = (CDecalVert *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)nVerts >> 27 != 0 ? -1 : 32 * nVerts);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100BF9C0
// Name: private: void CDispInfo::ClearDecalFragments(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::ClearDecalFragments(CDispInfo *this, unsigned __int16 h)
{
  UtlLinkedListElem_t<CDispDecal,unsigned short> *v2; // eax
  unsigned __int16 m_FirstFragment; // di
  int v4; // esi
  unsigned __int16 m_Next; // bx
  UtlLinkedListElem_t<CDispDecalFragment,unsigned short> *v6; // esi
  CDispDecal *decal; // [esp+Ch] [ebp+8h]

  v2 = &s_DispDecals.m_Memory.m_pMemory[h];
  m_FirstFragment = v2->m_Element.m_FirstFragment;
  decal = &v2->m_Element;
  if ( m_FirstFragment != 0xFFFF )
  {
    do
    {
      v4 = m_FirstFragment;
      m_Next = s_DispDecalFragments.m_Memory.m_pMemory[v4].m_Next;
      CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::Unlink(
        this: &s_DispDecalFragments,
        elem: m_FirstFragment);
      v6 = &s_DispDecalFragments.m_Memory.m_pMemory[v4];
      free(pMem: v6->m_Element.m_pVerts);
      v6->m_Element.m_pVerts = nullptr;
      v6->m_Next = s_DispDecalFragments.m_FirstFree;
      s_DispDecalFragments.m_FirstFree = m_FirstFragment;
      m_FirstFragment = m_Next;
    }
    while ( m_Next != 0xFFFF );
    v2 = (UtlLinkedListElem_t<CDispDecal,unsigned short> *)decal;
  }
  v2->m_Element.m_Flags &= ~8u;
  v2->m_Element.m_FirstFragment = -1;
  *(_DWORD *)&v2->m_Element.m_nVerts = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100BFA60
// Name: private: void CDispInfo::ClearAllDecalFragments(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::ClearAllDecalFragments(CDispInfo *this)
{
  unsigned __int16 i; // si

  for ( i = this->m_FirstDecal; i != 0xFFFF; i = s_DispDecals.m_Memory.m_pMemory[i].m_Next )
    CDispInfo::ClearDecalFragments(this, h: i);
}

//------------------------------------------------------------------------------
// Address: 0x100BFB10
// Name: private: class CDispShadowFragment __near * CDispInfo::AllocateShadowDecalFragment(unsigned short,int)
// Source: json
//------------------------------------------------------------------------------
UtlLinkedListElem_t<CDispShadowFragment,unsigned short> *__thiscall CDispInfo::AllocateShadowDecalFragment(
        CDispInfo *this,
        unsigned __int16 h,
        unsigned int nCount)
{
  DWORD CurrentThreadId; // ecx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // di
  int v6; // esi
  UtlLinkedListElem_t<CDispShadowFragment,unsigned short> *v7; // esi

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != s_ShadowFragmentAllocLock.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&s_ShadowFragmentAllocLock, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &s_ShadowFragmentAllocLock, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++s_ShadowFragmentAllocLock.m_depth;
  }
  v4 = CUtlLinkedList<CDispShadowFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowFragment,unsigned short>,unsigned short>>::AllocInternal(
         this: &s_DispShadowFragments,
         multilist: true);
  v5 = -1;
  if ( v4 != 0xFFFF )
    v5 = v4;
  v6 = h;
  CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::LinkBefore(
    this: &s_DispShadowFragments,
    before: s_DispShadowDecals.m_Memory.m_pMemory[v6].m_Element.m_FirstFragment,
    elem: v5);
  s_DispShadowDecals.m_Memory.m_pMemory[v6].m_Element.m_FirstFragment = v5;
  v7 = &s_DispShadowFragments.m_Memory.m_pMemory[v5];
  v7->m_Element.m_nVerts = nCount;
  v7->m_Element.m_ShadowVerts = (ShadowVertex_t *)MemAlloc_Alloc(nSize: (24 * (unsigned __int64)nCount) >> 32 != 0 ? -1 : 24 * nCount);
  if ( --s_ShadowFragmentAllocLock.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&s_ShadowFragmentAllocLock, 0);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x100BFBF0
// Name: private: void CDispInfo::ClearShadowDecalFragments(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::ClearShadowDecalFragments(CDispInfo *this, unsigned __int16 h)
{
  UtlLinkedListElem_t<CDispShadowDecal,unsigned short> *v2; // eax
  unsigned __int16 m_FirstFragment; // di
  int v4; // esi
  unsigned __int16 m_Next; // bx
  UtlLinkedListElem_t<CDispShadowFragment,unsigned short> *v6; // esi
  CDispShadowDecal *decal; // [esp+Ch] [ebp+8h]

  v2 = &s_DispShadowDecals.m_Memory.m_pMemory[h];
  m_FirstFragment = v2->m_Element.m_FirstFragment;
  decal = &v2->m_Element;
  if ( m_FirstFragment != 0xFFFF )
  {
    do
    {
      v4 = m_FirstFragment;
      m_Next = s_DispShadowFragments.m_Memory.m_pMemory[v4].m_Next;
      CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::Unlink(
        this: &s_DispShadowFragments,
        elem: m_FirstFragment);
      v6 = &s_DispShadowFragments.m_Memory.m_pMemory[v4];
      free(pMem: v6->m_Element.m_ShadowVerts);
      v6->m_Element.m_ShadowVerts = nullptr;
      v6->m_Next = s_DispShadowFragments.m_FirstFree;
      s_DispShadowFragments.m_FirstFree = m_FirstFragment;
      m_FirstFragment = m_Next;
    }
    while ( m_Next != 0xFFFF );
    v2 = (UtlLinkedListElem_t<CDispShadowDecal,unsigned short> *)decal;
  }
  v2->m_Element.m_Flags &= ~8u;
  v2->m_Element.m_FirstFragment = -1;
  *(_DWORD *)&v2->m_Element.m_nVerts = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100BFCA0
// Name: private: void CDispInfo::ClearAllShadowDecalFragments(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::ClearAllShadowDecalFragments(CDispInfo *this)
{
  unsigned __int16 i; // si

  for ( i = this->m_FirstShadowDecal; i != 0xFFFF; i = s_DispShadowDecals.m_Memory.m_pMemory[i].m_Next )
    CDispInfo::ClearShadowDecalFragments(this, h: i);
}

//------------------------------------------------------------------------------
// Address: 0x100BFCF0
// Name: public: virtual void CDispInfo::RemoveShadowDecal(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::RemoveShadowDecal(CDispInfo *this, unsigned __int16 h)
{
  CDispInfo::ClearShadowDecalFragments(this, h);
  if ( this->m_FirstShadowDecal == h )
    this->m_FirstShadowDecal = s_DispShadowDecals.m_Memory.m_pMemory[h].m_Next;
  CUtlLinkedList<CDispShadowDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowDecal,unsigned short>,unsigned short>>::Unlink(
    this: &s_DispShadowDecals,
    elem: h);
  s_DispShadowDecals.m_Memory.m_pMemory[h].m_Next = s_DispShadowDecals.m_FirstFree;
  s_DispShadowDecals.m_FirstFree = h;
}

//------------------------------------------------------------------------------
// Address: 0x100BFDA0
// Name: public: virtual unsigned short CDispInfo::NotifyAddDecal(struct decal_t __near *,float)
// Source: json
//------------------------------------------------------------------------------
__int16 __thiscall CDispInfo::NotifyAddDecal(CDispInfo *this, decal_t *pDecal, float flSize)
{
  int v4; // esi
  __int16 result; // ax
  UtlLinkedListElem_t<CDispDecal,unsigned short> *v6; // eax
  CDecalVert *m_FirstDecal; // eax
  int v8; // ecx
  UtlLinkedListElem_t<CDispDecal,unsigned short> *v9; // esi
  __int16 h; // [esp+8h] [ebp-8h]
  CDecalVert *pOutVerts; // [esp+Ch] [ebp-4h] BYREF

  v4 = (unsigned __int16)CUtlLinkedList<CDispDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short>>::AllocInternal(
                           this: &s_DispDecals,
                           multilist: true);
  result = -1;
  if ( (_WORD)v4 != 0xFFFF )
  {
    v6 = &s_DispDecals.m_Memory.m_pMemory[v4];
    if ( v6 != nullptr )
    {
      v6->m_Element.m_NodeIntersect.m_Ints[0] = 0;
      v6->m_Element.m_NodeIntersect.m_Ints[1] = 0;
      v6->m_Element.m_NodeIntersect.m_Ints[2] = 0;
      v6->m_Element.m_Flags = 0;
    }
    m_FirstDecal = (CDecalVert *)this->m_FirstDecal;
    v8 = 0;
    h = v4;
    if ( m_FirstDecal != (CDecalVert *)0xFFFF )
    {
      do
      {
        pOutVerts = m_FirstDecal;
        m_FirstDecal = (CDecalVert *)s_DispDecals.m_Memory.m_pMemory[(unsigned __int16)m_FirstDecal].m_Next;
        ++v8;
      }
      while ( m_FirstDecal != (CDecalVert *)0xFFFF );
      if ( v8 >= 32 )
        R_DecalUnlink(
          pdecal: s_DispDecals.m_Memory.m_pMemory[(unsigned __int16)pOutVerts].m_Element.m_pDecal,
          pData: host_state.worldbrush);
    }
    CUtlLinkedList<CDispDecal,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecal,unsigned short>,unsigned short>>::LinkBefore(
      this: &s_DispDecals,
      before: this->m_FirstDecal,
      elem: v4);
    this->m_FirstDecal = v4;
    v9 = &s_DispDecals.m_Memory.m_pMemory[v4];
    v9->m_Element.m_pDecal = pDecal;
    *(_DWORD *)&v9->m_Element.m_nVerts = 0;
    v9->m_Element.m_FirstFragment = -1;
    v9->m_Element.m_flSize = flSize;
    pOutVerts = nullptr;
    R_SetupDecalClip(
      &pOutVerts,
      pDecal: v9->m_Element.m_pDecal,
      vSurfNormal: &this->m_ParentSurfID->plane->normal,
      pMaterial: v9->m_Element.m_pDecal->material,
      textureSpaceBasis: v9->m_Element.m_TextureSpaceBasis,
      decalWorldScale: v9->m_Element.m_DecalWorldScale);
    CDispInfo::SetupDecalNodeIntersect(
      this,
      nodeIndex: &this->m_pPowerInfo->m_RootNode,
      iNodeBitIndex: 0,
      pDispDecal: &v9->m_Element,
      pInfo: nullptr);
    return h;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BFF70
// Name: void DispInfo_DrawDecalsGroup(class IMatRenderContext __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispInfo_DrawDecalsGroup(IMatRenderContext *pRenderContext, int iGroup, int iTreeType)
{
  int v3; // ebx
  int (__thiscall *GetMaxVerticesToRender)(IMatRenderContext *, IMaterial *); // edx
  int v5; // esi
  int (__thiscall *GetMaxIndicesToRender)(IMatRenderContext *); // edx
  int v7; // eax
  int v8; // edi
  DecalMaterialBucket_t *v9; // eax
  decal_t **m_iHead; // esi
  decal_t *v11; // eax
  bool v12; // zf
  int v13; // eax
  int v14; // ecx
  UtlLinkedListElem_t<CDispDecal,unsigned short> *v15; // eax
  UtlLinkedListElem_t<CDispDecalFragment,unsigned short> *v16; // esi
  int m_nVerts; // eax
  int m_nVertexCount; // eax
  IMatRenderContext *v19; // ebx
  IMaterial *material; // ecx
  int v21; // edi
  DecalBatchList_t *v22; // edi
  decal_t *v23; // eax
  int v24; // edi
  float *m_pCurrPosition; // ecx
  int v26; // eax
  float *p_x; // ecx
  float *m_pCurrNormal; // edx
  float *v29; // ecx
  int v30; // xmm0_4
  float *v31; // ecx
  int v32; // xmm0_4
  int v33; // eax
  unsigned __int16 v34; // si
  unsigned __int16 *v35; // eax
  int v36; // edi
  signed int v37; // ecx
  signed int v38; // edx
  signed int v39; // eax
  int v40; // eax
  DecalMeshList_t meshList; // [esp+4h] [ebp-A38h] BYREF
  CMeshBuilder meshBuilder; // [esp+810h] [ebp-22Ch] BYREF
  const CUtlVector<DecalMaterialBucket_t,CUtlMemory<DecalMaterialBucket_t,int> > *materialBucketList; // [esp+9F8h] [ebp-44h]
  int nBucketCount; // [esp+9FCh] [ebp-40h]
  float flOffset; // [esp+A00h] [ebp-3Ch]
  int nCount; // [esp+A04h] [ebp-38h]
  decal_t *pDecalHead; // [esp+A08h] [ebp-34h]
  int iBucket; // [esp+A0Ch] [ebp-30h]
  int hFrag; // [esp+A10h] [ebp-2Ch]
  int nDecalSortMaxIndices; // [esp+A14h] [ebp-28h]
  int v51; // [esp+A18h] [ebp-24h]
  int nDecalSortMaxVerts; // [esp+A1Ch] [ebp-20h]
  int iElement; // [esp+A20h] [ebp-1Ch]
  int nSortTreeCount; // [esp+A24h] [ebp-18h]
  int nIndexCount; // [esp+A28h] [ebp-14h]
  DecalBatchList_t *pBatch; // [esp+A2Ch] [ebp-10h]
  int nTriCount; // [esp+A30h] [ebp-Ch]
  int nVertCount; // [esp+A34h] [ebp-8h]
  bool bMeshInit; // [esp+A39h] [ebp-3h]
  bool bMatWireframe; // [esp+A3Ah] [ebp-2h]
  bool bBatchInit; // [esp+A3Bh] [ebp-1h]

  v3 = 0;
  nSortTreeCount = g_aDecalSortTrees.m_Size;
  if ( g_aDecalSortTrees.m_Size == 0 )
    return;
  meshList.m_aBatches.m_Size = 0;
  meshList.m_aBatches.m_pElements = (DecalBatchList_t *)&meshList.m_aBatches;
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  GetMaxVerticesToRender = pRenderContext->GetMaxVerticesToRender;
  v5 = 5 * g_nMaxDecals;
  nVertCount = 0;
  nIndexCount = 0;
  nDecalSortMaxVerts = 5 * g_nMaxDecals;
  if ( v5 >= GetMaxVerticesToRender(this: pRenderContext, a2: g_materialDecalWireframe) / 4 )
  {
    v5 = pRenderContext->GetMaxVerticesToRender(this: pRenderContext, a2: g_materialDecalWireframe) / 4;
    nDecalSortMaxVerts = v5;
  }
  GetMaxIndicesToRender = pRenderContext->GetMaxIndicesToRender;
  nDecalSortMaxIndices = 3 * v5;
  if ( 3 * v5 >= GetMaxIndicesToRender(this: pRenderContext) )
    nDecalSortMaxIndices = pRenderContext->GetMaxIndicesToRender(this: pRenderContext);
  bMatWireframe = (sv_cheats.m_pParent != nullptr && sv_cheats.m_pParent->m_Value.m_nValue != 0 || Cmd_IsRptActive())
               && mat_wireframe.m_pParent != nullptr
               && mat_wireframe.m_pParent->m_Value.m_nValue != 0;
  if ( nSortTreeCount > 0 )
  {
    v51 = 20 * (iGroup + iTreeType + 2 * iGroup);
    while ( 1 )
    {
      materialBucketList = (CUtlVector<DecalMaterialBucket_t,CUtlMemory<DecalMaterialBucket_t,int> > *)((char *)g_aDispDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets[0] + v51);
      v7 = *(int *)((char *)&g_aDispDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets[0][0].m_Size + v51);
      v8 = 0;
      bMeshInit = true;
      nBucketCount = v7;
      iBucket = 0;
      if ( v7 > 0 )
        break;
LABEL_79:
      v51 += 312;
      if ( --nSortTreeCount == 0 )
        goto LABEL_80;
    }
    while ( 1 )
    {
      v9 = &materialBucketList->m_Memory.m_pMemory[v8];
      if ( v9->m_nCheckCount != g_nDispDecalSortCheckCount )
        goto LABEL_67;
      m_iHead = (decal_t **)v9->m_iHead;
      if ( v9->m_iHead == 0 || m_iHead[1] == (decal_t *)m_iHead && m_iHead[2] != (decal_t *)m_iHead )
        goto LABEL_67;
      v11 = *m_iHead;
      v12 = (*m_iHead)->material == nullptr;
      pDecalHead = *m_iHead;
      if ( v12 || (__int64)v11->material->GetVertexFormat(this: v11->material) == 0 )
        goto LABEL_67;
      pBatch = nullptr;
      bBatchInit = true;
      iElement = (int)m_iHead;
      do
      {
        v13 = *(_DWORD *)iElement;
        iElement = *(_DWORD *)(iElement + 8);
        v14 = *(unsigned __int16 *)(v13 + 76);
        v15 = &s_DispDecals.m_Memory.m_pMemory[v14];
        if ( v15->m_Element.m_pDecal->material == nullptr )
        {
          DevMsg(a1: "DispInfo_DrawDecalsGroup: material is NULL decal %i.\n", v14);
          continue;
        }
        hFrag = v15->m_Element.m_FirstFragment;
        if ( (_WORD)hFrag != 0xFFFF )
        {
          while ( 1 )
          {
            v16 = &s_DispDecalFragments.m_Memory.m_pMemory[(unsigned __int16)hFrag];
            m_nVerts = v16->m_Element.m_nVerts;
            hFrag = v16->m_Next;
            nCount = m_nVerts;
            if ( m_nVerts + nVertCount >= nDecalSortMaxVerts || m_nVerts + v3 - 2 >= nDecalSortMaxIndices )
              break;
            if ( bMeshInit )
            {
              v19 = pRenderContext;
LABEL_42:
              meshList.m_pMesh = nullptr;
              meshList.m_aBatches.m_Size = 0;
              if ( bMatWireframe )
                material = g_materialDecalWireframe;
              else
                material = pDecalHead->material;
              meshList.m_pMesh = v19->GetDynamicMesh(this: v19, a2: false, a3: nullptr, a4: nullptr, a5: material);
              CMeshBuilder::Begin(
                this: &meshBuilder,
                pMesh: meshList.m_pMesh,
                type: MATERIAL_TRIANGLES,
                nVertexCount: nDecalSortMaxVerts,
                nIndexCount: nDecalSortMaxIndices,
                pMeshSettings: nullptr);
              v3 = 0;
              nVertCount = 0;
              nIndexCount = 0;
              bMeshInit = false;
            }
            if ( bBatchInit )
            {
              v21 = meshList.m_aBatches.m_Size++;
              meshList.m_aBatches.m_pElements = (DecalBatchList_t *)&meshList.m_aBatches;
              if ( meshList.m_aBatches.m_Size - v21 - 1 > 0 )
                _V_memmove(
                  dest: &meshList.m_aBatches.m_Memory.m_Memory[16 * v21 + 16],
                  src: (char *)&meshList.m_aBatches + 16 * v21,
                  count: 16 * (meshList.m_aBatches.m_Size - v21 - 1));
              v12 = !bMatWireframe;
              v22 = (DecalBatchList_t *)((char *)&meshList.m_aBatches + 16 * v21);
              pBatch = v22;
              v22->m_iStartIndex = v3;
              if ( v12 )
              {
                v23 = pDecalHead;
                v22->m_pMaterial = pDecalHead->material;
                v22->m_pProxy = v23->userdata;
                v22->m_iLightmapPage = materialSortInfoArray[v23->surfID->materialSortID].lightmapPageID;
              }
              else
              {
                v22->m_pMaterial = g_materialDecalWireframe;
              }
              bBatchInit = false;
            }
            v24 = 0;
            v12 = v16->m_Element.m_nVerts == 0;
            flOffset = v16->m_Element.m_pDecal->lightmapOffset;
            if ( !v12 )
            {
              nTriCount = 0;
              do
              {
                m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
                v26 = (int)v16->m_Element.m_pVerts + nTriCount;
                *meshBuilder.m_VertexBuilder.m_pCurrPosition = *(float *)v26;
                m_pCurrPosition[1] = *(float *)(v26 + 4);
                m_pCurrPosition[2] = *(float *)(v26 + 8);
                p_x = &v16->m_Element.m_pDecal->surfID->plane->normal.x;
                m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
                *meshBuilder.m_VertexBuilder.m_pCurrNormal = *p_x;
                m_pCurrNormal[1] = p_x[1];
                m_pCurrNormal[2] = p_x[2];
                *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
                v29 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                v30 = *(_DWORD *)(v26 + 20);
                *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = *(float *)(v26 + 16);
                *((_DWORD *)v29 + 1) = v30;
                v31 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
                v32 = *(_DWORD *)(v26 + 28);
                *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = *(float *)(v26 + 24);
                *((_DWORD *)v31 + 1) = v32;
                *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = flOffset;
                CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
                v33 = v16->m_Element.m_nVerts;
                nTriCount += 32;
                ++v24;
              }
              while ( v24 < v33 );
              v3 = nIndexCount;
            }
            v34 = nVertCount + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
            v35 = &meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex];
            v36 = nCount - 2;
            v37 = (nCount - 2) * meshBuilder.m_IndexBuilder.m_nIndexSize;
            v38 = 0;
            nTriCount = nCount - 2;
            if ( v37 > 0 )
            {
              do
              {
                *v35 = v34;
                v35[1] = v38 + v34 + 1;
                v35[2] = v38++ + v34 + 2;
                v35 += 3;
              }
              while ( v38 < v37 );
              v36 = nTriCount;
              v3 = nIndexCount;
            }
            v39 = v37 * meshBuilder.m_IndexBuilder.m_nIndexSize
                + meshBuilder.m_IndexBuilder.m_nCurrentIndex
                + 2 * v37 * meshBuilder.m_IndexBuilder.m_nIndexSize;
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = v39;
            if ( v39 > meshBuilder.m_IndexBuilder.m_nIndexCount )
              meshBuilder.m_IndexBuilder.m_nIndexCount = v39;
            nVertCount += nCount;
            v3 += v36 + 2 * v36;
            nIndexCount = v3;
            if ( (_WORD)hFrag == 0xFFFF )
              goto LABEL_63;
          }
          if ( pBatch != nullptr )
            pBatch->m_nIndexCount = v3 - pBatch->m_iStartIndex;
          if ( meshBuilder.m_bGenerateIndices )
          {
            switch ( meshBuilder.m_Type )
            {
              case MATERIAL_LINE_STRIP:
                m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
                break;
              case MATERIAL_LINE_LOOP:
                m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
                break;
              case MATERIAL_POLYGON:
                m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
                break;
              case MATERIAL_QUADS:
                m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
                break;
              case MATERIAL_INSTANCED_QUADS:
                m_nVertexCount = 0;
                break;
              default:
                m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
                break;
            }
            CIndexBuilder::GenerateIndices(
              this: &meshBuilder.m_IndexBuilder,
              primitiveType: meshBuilder.m_Type,
              nIndexCount: m_nVertexCount);
          }
          meshBuilder.m_pMesh->UnlockMesh(
            this: meshBuilder.m_pMesh,
            a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
            a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
            a4: &meshBuilder);
          v19 = pRenderContext;
          meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
          meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
          meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
          meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
          meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
          meshBuilder.m_pMesh = nullptr;
          DispInfo_DrawDecalMeshList(pRenderContext, &meshList);
          pBatch = nullptr;
          bBatchInit = true;
          goto LABEL_42;
        }
LABEL_63:
        if ( pBatch != nullptr )
          pBatch->m_nIndexCount = v3 - pBatch->m_iStartIndex;
      }
      while ( iElement != 0 );
      v8 = iBucket;
LABEL_67:
      iBucket = ++v8;
      if ( v8 >= nBucketCount )
      {
        if ( !bMeshInit )
        {
          if ( meshBuilder.m_bGenerateIndices )
          {
            switch ( meshBuilder.m_Type )
            {
              case MATERIAL_LINE_STRIP:
                v40 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
                break;
              case MATERIAL_LINE_LOOP:
                v40 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
                break;
              case MATERIAL_POLYGON:
                v40 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
                break;
              case MATERIAL_QUADS:
                v40 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
                break;
              case MATERIAL_INSTANCED_QUADS:
                v40 = 0;
                break;
              default:
                v40 = meshBuilder.m_VertexBuilder.m_nVertexCount;
                break;
            }
            CIndexBuilder::GenerateIndices(
              this: &meshBuilder.m_IndexBuilder,
              primitiveType: meshBuilder.m_Type,
              nIndexCount: v40);
          }
          meshBuilder.m_pMesh->UnlockMesh(
            this: meshBuilder.m_pMesh,
            a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
            a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
            a4: &meshBuilder);
          meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
          meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
          meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
          meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
          meshBuilder.m_pMesh = nullptr;
          meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
          DispInfo_DrawDecalMeshList(pRenderContext, &meshList);
        }
        goto LABEL_79;
      }
    }
  }
LABEL_80:
  if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
  {
    meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
  {
    meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0640
// Name: void DispInfo_DrawDecals(class IMatRenderContext __near *,class CDispInfo __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispInfo_DrawDecals(IMatRenderContext *pRenderContext)
{
  DispInfo_DrawDecalsGroup(pRenderContext, iGroup: 0, iTreeType: 0);
  DispInfo_DrawDecalsGroup(pRenderContext, iGroup: 0, iTreeType: 1);
  DispInfo_DrawDecalsGroup(pRenderContext, iGroup: 0, iTreeType: 2);
}

//------------------------------------------------------------------------------
// Address: 0x100C0670
// Name: void DispInfo_RenderListDecalsAndOverlays(class IMatRenderContext __near *,int,struct msurface2_t __near * __near *,int,bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispInfo_RenderListDecalsAndOverlays(
        IMatRenderContext *pRenderContext,
        int nSortGroup,
        msurface2_t **pList,
        int listCount,
        bool bOrtho,
        __int16 flags)
{
  int i; // esi
  int m_ShadowDecals; // eax
  BOOL v8; // edi
  IOverlayMgr *v9; // eax
  IOverlayMgr *v10; // eax
  CDispInfo *visibleDisps[2048]; // [esp+0h] [ebp-2008h] BYREF
  BOOL v12; // [esp+2000h] [ebp-8h]
  int nVisibleDisps; // [esp+2004h] [ebp-4h] BYREF

  if ( r_DrawDisp.m_pParent != nullptr
    && r_DrawDisp.m_pParent->m_Value.m_nValue != 0
    && listCount != 0
    && (flags & 0x400) != 0 )
  {
    g_bDispOrthoRender = bOrtho;
    DispInfo_GetVisibleDispsAndAddOverlayFragmentsToRenderList(
      nSortGroup,
      pList,
      listCount,
      visibleDisps,
      &nVisibleDisps);
    for ( i = 0; i < listCount; ++i )
    {
      m_ShadowDecals = pList[i]->m_ShadowDecals;
      if ( (_WORD)m_ShadowDecals != 0xFFFF )
        g_pShadowMgr->AddShadowsOnSurfaceToRenderList(this: g_pShadowMgr, a2: m_ShadowDecals);
    }
    if ( (flags & 0x80u) != 0 || (LOBYTE(v12) = 1, (flags & 0x100) != 0) )
      LOBYTE(v12) = 0;
    v8 = v12;
    g_pShadowMgr->RenderFlashlights(this: g_pShadowMgr, a2: v12, a3: false, a4: nullptr);
    v9 = OverlayMgr();
    v9->RenderOverlays(this: v9, a2: pRenderContext, a3: nSortGroup);
    g_pShadowMgr->DrawFlashlightOverlays(this: g_pShadowMgr, a2: pRenderContext, a3: nSortGroup, a4: v8);
    v10 = OverlayMgr();
    v10->ClearRenderLists(this: v10, a2: nSortGroup);
    DispInfo_BatchDecals(pVisibleDisps: visibleDisps, nVisibleDisps);
    DispInfo_DrawDecalsGroup(pRenderContext, iGroup: 0, iTreeType: 0);
    DispInfo_DrawDecalsGroup(pRenderContext, iGroup: 0, iTreeType: 1);
    DispInfo_DrawDecalsGroup(pRenderContext, iGroup: 0, iTreeType: 2);
    g_pShadowMgr->DrawFlashlightDecalsOnDisplacements(
      this: g_pShadowMgr,
      a2: pRenderContext,
      a3: nSortGroup,
      a4: visibleDisps,
      a5: nVisibleDisps,
      a6: v8);
    g_pShadowMgr->RenderFlashlights(this: g_pShadowMgr, a2: v8, a3: true, a4: nullptr);
    g_pShadowMgr->RenderShadows(this: g_pShadowMgr, a2: pRenderContext, a3: nullptr);
    g_pShadowMgr->ClearShadowRenderList(this: g_pShadowMgr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BF100
// Name: public: virtual void CDispInfo::SetParent(struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::SetParent(vgui::ImagePanel *this, Color drawColor)
{
  this->m_DrawColor = drawColor;
}

} // namespace engine_xlsp
