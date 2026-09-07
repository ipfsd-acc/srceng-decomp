// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/disp_mapload.cpp
// Functions: 27
// ============================================================

#include "engine\disp_mapload.h"

//------------------------------------------------------------------------------
// Address: 0x100C0C30
// Name: void Vector2DCopy(class Vector2D const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector2DCopy(const Vector2D *src, Vector2D *dst)
{
  *dst = *src;
}

//------------------------------------------------------------------------------
// Address: 0x100C0C50
// Name: public: class Vector4D __near & Vector4D::operator=(class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
Vector4D *__thiscall Vector4D::operator=(Vector4D *this, const Vector4D *vOther)
{
  *this = *vOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C0C80
// Name: public: void CDispNeighbor::SetInvalid(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispNeighbor::SetInvalid(CDispNeighbor *this)
{
  this->m_SubNeighbors[0].m_iNeighbor = -1;
  this->m_SubNeighbors[1].m_iNeighbor = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100C0C90
// Name: public: void CDispCornerNeighbors::SetInvalid(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCornerNeighbors::SetInvalid(CDispCornerNeighbors *this)
{
  this->m_nNeighbors = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100C0CA0
// Name: public: void CCoreDispSurface::GetTexCoord(int,class Vector2D __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCoreDispSurface::GetTexCoord(CCoreDispSurface *this, int index, Vector2D *texCoord)
{
  *texCoord = this->m_TexCoords[index];
}

//------------------------------------------------------------------------------
// Address: 0x100C0CC0
// Name: public: void CCoreDispSurface::SetFlags(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCoreDispSurface::SetFlags(CCoreDispSurface *this, int flag)
{
  this->m_Flags = flag;
}

//------------------------------------------------------------------------------
// Address: 0x100C0CD0
// Name: public: void CCoreDispInfo::GetMultiBlend(int,class Vector4D __near &,class Vector4D __near &,class Vector __near &,class Vector __near &,class Vector __near &,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCoreDispInfo::GetMultiBlend(
        CCoreDispInfo *this,
        int index,
        Vector4D *vBlend,
        Vector4D *vAlphaBlend,
        Vector *vColor1,
        Vector *vColor2,
        Vector *vColor3,
        Vector *vColor4)
{
  CoreDispVert_t *v8; // eax

  v8 = &this->m_pVerts[index];
  *vBlend = v8->m_MultiBlend;
  *vAlphaBlend = v8->m_AlphaBlend;
  *vColor1 = v8->m_vBlendColors[0];
  *vColor2 = v8->m_vBlendColors[1];
  *vColor3 = v8->m_vBlendColors[2];
  *vColor4 = v8->m_vBlendColors[3];
}

//------------------------------------------------------------------------------
// Address: 0x100C0DE0
// Name: void DispInfo_LinkToParentFaces(struct model_t __near *,class ddispinfo_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispInfo_LinkToParentFaces(model_t *pWorld, const ddispinfo_t *pMapDisps, int nDisplacements)
{
  int v3; // esi
  unsigned __int16 *p_m_iMapFace; // edi
  IDispInfo *v5; // eax
  msurface2_t *v6; // edx

  v3 = 0;
  if ( nDisplacements > 0 )
  {
    p_m_iMapFace = &pMapDisps->m_iMapFace;
    do
    {
      v5 = DispInfo_IndexArray(hArray: *(_DWORD **)(pWorld->sprite.numframes + 112), iElement: v3);
      v6 = &host_state.worldbrush->surfaces2[*p_m_iMapFace];
      v6->pDispInfo = v5;
      v5->SetParent(this: v5, a2: v6);
      ++v3;
      p_m_iMapFace += 88;
    }
    while ( v3 < nDisplacements );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0E50
// Name: public: int CDispInfo::NumLightMaps(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDispInfo::NumLightMaps(CDispInfo *this)
{
  return (this->m_ParentSurfID->flags & 8) != 0 ? 4 : 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C0E70
// Name: void BuildTagData(class CCoreDispInfo __near *,class CDispInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildTagData(CCoreDispInfo *pCoreDisp, CDispInfo *pDisp)
{
  int v2; // ebx
  int i; // edi
  unsigned __int16 m_uiTags; // ax
  unsigned __int16 *v6; // eax
  int v7; // edi
  int nBuildCount; // [esp+Ch] [ebp-4h]
  int nBuildCounta; // [esp+Ch] [ebp-4h]
  int nWalkCount; // [esp+1Ch] [ebp+Ch]

  v2 = 0;
  nBuildCount = 0;
  for ( i = 0; v2 < CCoreDispInfo::GetTriCount(this: pCoreDisp); ++v2 )
  {
    m_uiTags = pCoreDisp->m_pTris[v2].m_uiTags;
    if ( (m_uiTags & 2) != 0 )
      ++nBuildCount;
    if ( (m_uiTags & 4) != 0 )
      ++i;
  }
  pDisp->m_pWalkIndices = (unsigned __int16 *)MemAlloc_Alloc(
                                                nSize: (unsigned __int64)(unsigned int)(3 * nBuildCount) >> 31 != 0
                                              ? -1
                                              : 6 * nBuildCount);
  v6 = (unsigned __int16 *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)(3 * i) >> 31 != 0 ? -1 : 6 * i);
  v7 = 0;
  pDisp->m_pBuildIndices = v6;
  nWalkCount = 0;
  nBuildCounta = 0;
  if ( CCoreDispInfo::GetTriCount(this: pCoreDisp) <= 0 )
  {
    pDisp->m_nWalkIndexCount = 0;
    pDisp->m_nBuildIndexCount = 0;
  }
  else
  {
    do
    {
      if ( (pCoreDisp->m_pTris[v7].m_uiTags & 2) != 0 )
      {
        CCoreDispInfo::GetTriIndices(
          this: pCoreDisp,
          iTri: v7,
          v1: &pDisp->m_pWalkIndices[nWalkCount],
          v2: &pDisp->m_pWalkIndices[nWalkCount + 1],
          v3: &pDisp->m_pWalkIndices[nWalkCount + 2]);
        nWalkCount += 3;
      }
      if ( (pCoreDisp->m_pTris[v7].m_uiTags & 4) != 0 )
      {
        CCoreDispInfo::GetTriIndices(
          this: pCoreDisp,
          iTri: v7,
          v1: &pDisp->m_pBuildIndices[nBuildCounta],
          v2: &pDisp->m_pBuildIndices[nBuildCounta + 1],
          v3: &pDisp->m_pBuildIndices[nBuildCounta + 2]);
        nBuildCounta += 3;
      }
      ++v7;
    }
    while ( v7 < CCoreDispInfo::GetTriCount(this: pCoreDisp) );
    pDisp->m_nWalkIndexCount = nWalkCount;
    pDisp->m_nBuildIndexCount = nBuildCounta;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C1060
// Name: BuildDispSurfInit
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildDispSurfInit(model_t *pWorld, CCoreDispInfo *pBuildDisp, msurface2_t *worldSurfID)
{
  msurface2_t *v3; // ebx
  bool v4; // zf
  int v5; // edx
  Vector2D *m_TexCoords; // ecx
  float *p_z; // eax
  int v8; // edi
  bool v9; // cc
  float *v10; // eax
  float *v11; // ecx
  unsigned int v12; // edx
  double v13; // st7
  int v14; // ecx
  int v15; // ebx
  Vector2D *v16; // edx
  float *p_x; // ecx
  double v18; // st7
  mtexinfo_t *texinfo; // eax
  unsigned int v20; // ecx
  Vector4D *v21; // eax
  int v22; // eax
  msurfacelighting_t *surfacelighting; // edx
  float y; // xmm6_4
  float x; // xmm7_4
  unsigned int v26; // ebx
  int v27; // ecx
  int v28; // edx
  float v29; // xmm0_4
  float v30; // xmm1_4
  int k; // eax
  Vector2D surfLightCoords[4][4]; // [esp+4h] [ebp-164h] BYREF
  Vector2D surfTexCoords[4]; // [esp+84h] [ebp-E4h] BYREF
  SurfaceCtx_t ctx; // [esp+A4h] [ebp-C4h] BYREF
  Vector surfPoints[4]; // [esp+C8h] [ebp-A0h] BYREF
  Vector surfNormals[4]; // [esp+F8h] [ebp-70h]
  Vector vecS; // [esp+128h] [ebp-40h] BYREF
  Vector vecT; // [esp+134h] [ebp-34h] BYREF
  Vector vec; // [esp+140h] [ebp-28h] BYREF
  int i; // [esp+14Ch] [ebp-1Ch]
  Vector2D *v41; // [esp+150h] [ebp-18h]
  int surfFlag; // [esp+154h] [ebp-14h]
  float *p_y; // [esp+158h] [ebp-10h]
  float *v44; // [esp+15Ch] [ebp-Ch]
  int j; // [esp+160h] [ebp-8h]
  int nLMVects; // [esp+164h] [ebp-4h]

  v3 = worldSurfID;
  if ( worldSurfID != nullptr && HIBYTE(worldSurfID->flags) == 4 )
  {
    BuildMSurfaceVerts(
      pBrushData: pWorld->brush.pShared,
      surfID: worldSurfID,
      verts: surfPoints,
      texCoords: surfTexCoords,
      lightCoords: surfLightCoords);
    vec.x = (float)((float)(surfPoints[3].y - surfPoints[0].y) * (float)(surfPoints[1].z - surfPoints[0].z))
          - (float)((float)(surfPoints[3].z - surfPoints[0].z) * (float)(surfPoints[1].y - surfPoints[0].y));
    vec.y = (float)((float)(surfPoints[3].z - surfPoints[0].z) * (float)(surfPoints[1].x - surfPoints[0].x))
          - (float)((float)(surfPoints[1].z - surfPoints[0].z) * (float)(surfPoints[3].x - surfPoints[0].x));
    vec.z = (float)((float)(surfPoints[1].y - surfPoints[0].y) * (float)(surfPoints[3].x - surfPoints[0].x))
          - (float)((float)(surfPoints[3].y - surfPoints[0].y) * (float)(surfPoints[1].x - surfPoints[0].x));
    VectorNormalize(&vec);
    surfFlag = pBuildDisp->m_Surf.m_Flags;
    v4 = (worldSurfID->flags & 8) == 0;
    surfNormals[0] = vec;
    surfNormals[1] = vec;
    surfNormals[2] = vec;
    surfNormals[3] = vec;
    nLMVects = 1;
    if ( !v4 )
    {
      surfFlag |= 1u;
      nLMVects = 4;
    }
    v5 = 0;
    p_y = &surfLightCoords[0][1].y;
    m_TexCoords = pBuildDisp->m_Surf.m_TexCoords;
    p_z = &pBuildDisp->m_Surf.m_Points[0].z;
    pBuildDisp->m_Surf.m_PointCount = 4;
    i = 0;
    v41 = pBuildDisp->m_Surf.m_TexCoords;
    v44 = &pBuildDisp->m_Surf.m_Points[0].z;
    v8 = 0;
    do
    {
      v9 = nLMVects < 4;
      *(p_z - 2) = surfPoints[v8].x;
      j = 0;
      *(p_z - 1) = surfPoints[v8].y;
      *p_z = surfPoints[v8].z;
      p_z[10] = surfNormals[v8].x;
      p_z[11] = surfNormals[v8].y;
      p_z[12] = surfNormals[v8].z;
      m_TexCoords->x = surfTexCoords[v5].x;
      m_TexCoords->y = surfTexCoords[v5].y;
      if ( !v9 )
      {
        v10 = p_y;
        v11 = &v41[8].y;
        v12 = ((unsigned int)(nLMVects - 4) >> 2) + 1;
        j = 4 * v12;
        do
        {
          v13 = *(v10 - 3);
          v10 += 8;
          *(v11 - 9) = v13;
          v11 += 32;
          --v12;
          *(v11 - 40) = *(v10 - 10);
          *(v11 - 33) = *(v10 - 9);
          *(v11 - 32) = *(v10 - 8);
          *(v11 - 25) = *(v10 - 7);
          *(v11 - 24) = *(v10 - 6);
          *(v11 - 17) = *(v10 - 5);
          *(v11 - 16) = *(v10 - 4);
        }
        while ( v12 != 0 );
        p_z = v44;
        v5 = i;
        v3 = worldSurfID;
      }
      if ( j < nLMVects )
      {
        v14 = j + 4 * v5;
        v15 = nLMVects - j;
        v16 = &pBuildDisp->m_Surf.m_LuxelCoords[j][v5];
        p_x = &surfLightCoords[0][v14].x;
        v44 = &v16->x;
        do
        {
          v18 = *p_x;
          p_x += 2;
          v16->x = v18;
          v16 += 4;
          --v15;
          v16[-4].y = *(p_x - 1);
        }
        while ( v15 != 0 );
        v5 = i;
        v3 = worldSurfID;
      }
      p_y += 8;
      ++v5;
      ++v8;
      p_z += 3;
      m_TexCoords = v41 + 1;
      i = v5;
      v44 = p_z;
      ++v41;
    }
    while ( v8 < 4 );
    texinfo = host_state.worldbrush->texinfo;
    v20 = *((unsigned __int16 *)v3 + 11) >> 1;
    vecS.x = texinfo[*((unsigned __int16 *)v3 + 11) >> 1].textureVecsTexelsPerWorldUnits[0].x;
    vecS.y = texinfo[v20].textureVecsTexelsPerWorldUnits[0].y;
    vecS.z = texinfo[v20].textureVecsTexelsPerWorldUnits[0].z;
    v21 = &host_state.worldbrush->texinfo[v20].textureVecsTexelsPerWorldUnits[1];
    vecT.x = v21->x;
    vecT.y = v21->y;
    vecT.z = v21->z;
    VectorNormalize(vec: &vecS);
    VectorNormalize(vec: &vecT);
    v22 = surfFlag;
    pBuildDisp->m_Surf.sAxis = vecS;
    pBuildDisp->m_Surf.tAxis = vecT;
    pBuildDisp->m_Surf.m_Flags = v22;
    CCoreDispSurface::FindSurfPointStartIndex(this: &pBuildDisp->m_Surf);
    CCoreDispSurface::AdjustSurfPointData(this: &pBuildDisp->m_Surf);
    SurfSetupSurfaceContext(&ctx, surfID: v3);
    surfacelighting = host_state.worldbrush->surfacelighting;
    y = ctx.m_Scale.y;
    x = ctx.m_Scale.x;
    v26 = ((char *)v3 - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0;
    v27 = *(__int16 *)((char *)surfacelighting->m_LightmapExtents + v26);
    v28 = *(__int16 *)((char *)&surfacelighting->m_LightmapExtents[1] + v26);
    v29 = 0.0;
    v30 = 0.0;
    for ( k = 0; k < 4; ++k )
    {
      switch ( k )
      {
        case 0:
          v29 = 0.0;
          goto LABEL_21;
        case 1:
          v29 = 0.0;
          v30 = (float)v28;
          break;
        case 2:
          v29 = (float)v27;
          v30 = (float)v28;
          break;
        case 3:
          v29 = (float)v27;
LABEL_21:
          v30 = 0.0;
          break;
        default:
          break;
      }
      v29 = ctx.m_Offset.x + (float)(x * (float)(v29 + 0.5));
      v30 = ctx.m_Offset.y + (float)(y * (float)(v30 + 0.5));
      pBuildDisp->m_Surf.m_LuxelCoords[0][k].x = v29;
      pBuildDisp->m_Surf.m_LuxelCoords[0][k].y = v30;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C14B0
// Name: void FillStaticBuffer(class CGroupMesh __near *,class CDispInfo __near *,class CCoreDispInfo const __near *,class CDispVert const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FillStaticBuffer(
        CGroupMesh *pMesh,
        CDispInfo *pDisp,
        CCoreDispInfo *pCoreDisp,
        const CDispVert *pVerts,
        int nLightmaps)
{
  int Power; // eax
  int v6; // ebx
  msurface2_t *v7; // eax
  int v8; // edi
  CoreDispVert_t *m_pVerts; // ecx
  float y; // xmm0_4
  double x; // st7
  float z; // xmm1_4
  float *m_pCurrPosition; // ecx
  CoreDispVert_t *v14; // edx
  float v15; // xmm0_4
  float v16; // xmm1_4
  float *m_pCurrNormal; // ecx
  CoreDispVert_t *v18; // eax
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float *v22; // eax
  CoreDispVert_t *v23; // ecx
  float v24; // xmm1_4
  float v25; // xmm2_4
  float *v26; // eax
  CoreDispVert_t *v27; // edx
  float v28; // xmm1_4
  float *v29; // eax
  float *v30; // eax
  float *v31; // eax
  float *v32; // eax
  float *v33; // eax
  float v34; // xmm0_4
  int v35; // xmm1_4
  msurface2_t *v36; // eax
  float *v37; // eax
  CDispRenderVert *v38; // [esp-Ch] [ebp-294h]
  CMeshBuilder builder; // [esp+8h] [ebp-280h] BYREF
  SurfaceCtx_t ctx; // [esp+1F0h] [ebp-98h] BYREF
  int nIndices; // [esp+214h] [ebp-74h] BYREF
  Vector4D vMultiBlend; // [esp+218h] [ebp-70h] BYREF
  Vector4D vAlphaBlend; // [esp+228h] [ebp-60h] BYREF
  Vector vMultiBlendColor[4]; // [esp+238h] [ebp-50h] BYREF
  Vector2D lightCoord; // [esp+268h] [ebp-20h] BYREF
  int v46; // [esp+270h] [ebp-18h]
  int v47; // [esp+274h] [ebp-14h]
  float v48; // [esp+278h] [ebp-10h]
  int v49; // [esp+27Ch] [ebp-Ch]
  int nVerts; // [esp+280h] [ebp-8h] BYREF
  unsigned int v51; // [esp+284h] [ebp-4h]

  Power = CDispUtilsHelper::GetPower(this: &pDisp->CDispUtilsHelper);
  CalcMaxNumVertsAndIndices(power: Power, &nVerts, &nIndices);
  CMeshBuilder::CMeshBuilder(this: &builder);
  v6 = 0;
  CMeshBuilder::BeginModify(
    this: &builder,
    pMesh: pMesh->m_pMesh,
    nFirstVertex: pDisp->m_iVertOffset,
    nVertexCount: nVerts,
    nFirstIndex: 0,
    nIndexCount: 0);
  v7 = pDisp->GetParent(this: pDisp);
  SurfSetupSurfaceContext(&ctx, surfID: v7);
  if ( nVerts > 0 )
  {
    v51 = 0;
    v8 = 0;
    do
    {
      m_pVerts = pCoreDisp->m_pVerts;
      y = m_pVerts[v8].m_Vert.y;
      x = m_pVerts[v8].m_Vert.x;
      z = m_pVerts[v8].m_Vert.z;
      m_pCurrPosition = builder.m_VertexBuilder.m_pCurrPosition;
      *builder.m_VertexBuilder.m_pCurrPosition = x;
      m_pCurrPosition[1] = y;
      m_pCurrPosition[2] = z;
      v14 = pCoreDisp->m_pVerts;
      v15 = v14[v8].m_Normal.y;
      v16 = v14[v8].m_Normal.z;
      m_pCurrNormal = builder.m_VertexBuilder.m_pCurrNormal;
      *builder.m_VertexBuilder.m_pCurrNormal = v14[v8].m_Normal.x;
      m_pCurrNormal[1] = v15;
      m_pCurrNormal[2] = v16;
      v18 = pCoreDisp->m_pVerts;
      v19 = v18[v8].m_TangentS.x;
      v20 = v18[v8].m_TangentS.y;
      v21 = v18[v8].m_TangentS.z;
      v22 = (float *)((char *)builder.m_VertexBuilder.m_pTangentS
                    + builder.m_VertexBuilder.m_nCurrentVertex * builder.m_VertexBuilder.m_VertexSize_TangentS);
      *v22 = v19;
      v22[1] = v20;
      v22[2] = v21;
      v23 = pCoreDisp->m_pVerts;
      v24 = v23[v8].m_TangentT.y;
      v25 = v23[v8].m_TangentT.z;
      v26 = (float *)((char *)builder.m_VertexBuilder.m_pTangentT
                    + builder.m_VertexBuilder.m_nCurrentVertex * builder.m_VertexBuilder.m_VertexSize_TangentT);
      *v26 = v23[v8].m_TangentT.x;
      v26[1] = v24;
      v26[2] = v25;
      v27 = pCoreDisp->m_pVerts;
      v28 = v27[v8].m_TexCoord.y;
      v29 = builder.m_VertexBuilder.m_pCurrTexCoord[0];
      *builder.m_VertexBuilder.m_pCurrTexCoord[0] = v27[v8].m_TexCoord.x;
      v29[1] = v28;
      lightCoord = pCoreDisp->m_pVerts[v8].m_LuxelCoords[0];
      *(Vector2D *)builder.m_VertexBuilder.m_pCurrTexCoord[1] = lightCoord;
      if ( (pCoreDisp->m_nFlags & 0x40000000) != 0 )
      {
        CCoreDispInfo::GetMultiBlend(
          this: pCoreDisp,
          index: v6,
          vBlend: &vMultiBlend,
          &vAlphaBlend,
          vColor1: vMultiBlendColor,
          vColor2: &vMultiBlendColor[1],
          vColor3: &vMultiBlendColor[2],
          vColor4: &vMultiBlendColor[3]);
        *(Vector4D *)builder.m_VertexBuilder.m_pCurrTexCoord[3] = vAlphaBlend;
        v30 = builder.m_VertexBuilder.m_pCurrTexCoord[4];
        *(Vector *)builder.m_VertexBuilder.m_pCurrTexCoord[4] = vMultiBlendColor[0];
        v30[3] = vMultiBlend.x;
        v31 = builder.m_VertexBuilder.m_pCurrTexCoord[5];
        *(Vector *)builder.m_VertexBuilder.m_pCurrTexCoord[5] = vMultiBlendColor[1];
        v31[3] = vMultiBlend.y;
        v32 = builder.m_VertexBuilder.m_pCurrTexCoord[6];
        *(Vector *)builder.m_VertexBuilder.m_pCurrTexCoord[6] = vMultiBlendColor[2];
        v32[3] = vMultiBlend.z;
        v33 = builder.m_VertexBuilder.m_pCurrTexCoord[7];
        *(Vector *)builder.m_VertexBuilder.m_pCurrTexCoord[7] = vMultiBlendColor[3];
        v33[3] = vMultiBlend.w;
      }
      v34 = pCoreDisp->m_pVerts[v8].m_Alpha * 0.0039215689;
      *(float *)&v35 = 0.0;
      if ( v34 < 0.0 || (*(float *)&v35 = 1.0, v34 > 1.0) )
        v34 = *(float *)&v35;
      v46 = 1258291455;
      v49 = 1258291455;
      v47 = 1258291455;
      v48 = (float)(v34 * 255.0) + 8388608.0;
      *(_DWORD *)builder.m_VertexBuilder.m_pCurrColor = (((((LOBYTE(v48) << 8) | 0xFF) << 8) | 0xFF) << 8) | 0xFF;
      if ( nLightmaps > 1 )
      {
        v38 = &pDisp->m_Verts.m_Memory.m_pMemory[v51 / 0x40];
        v36 = pDisp->GetParent(this: pDisp);
        SurfComputeLightmapCoordinate(&ctx, surfID: v36, vec: &v38->m_vPos, uv: &lightCoord);
        v37 = builder.m_VertexBuilder.m_pCurrTexCoord[2];
        *builder.m_VertexBuilder.m_pCurrTexCoord[2] = ctx.m_BumpSTexCoordOffset;
        v37[1] = 0.0;
      }
      CVertexBuilder::AdvanceVertex(this: &builder.m_VertexBuilder);
      v51 += 64;
      ++v6;
      ++v8;
    }
    while ( v6 < nVerts );
  }
  builder.m_pMesh->ModifyEnd(this: builder.m_pMesh, a2: &builder);
}

//------------------------------------------------------------------------------
// Address: 0x100C1880
// Name: void SetupMeshReaders(struct model_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupMeshReaders(model_t *pWorld, int nDisplacements)
{
  IDispInfo *v2; // esi
  float *v3; // eax
  float *v4; // ecx
  unsigned __int16 *v5; // edx
  IDispInfo_vtbl *v6; // eax
  IDispInfo_vtbl *v7; // ecx
  IDispInfo_vtbl *ComputeShadowFragments; // edx
  IDispInfo_vtbl *v9; // edx
  bool v10; // zf
  MeshDesc_t desc; // [esp+0h] [ebp-BCh] BYREF
  IDispInfo_vtbl *v12; // [esp+B4h] [ebp-8h]
  int iDisp; // [esp+B8h] [ebp-4h]

  for ( iDisp = 0; iDisp < nDisplacements; ++iDisp )
  {
    v2 = DispInfo_IndexArray(hArray: *(_DWORD **)(pWorld->sprite.numframes + 112), iElement: iDisp);
    memset(dst: (unsigned __int8 *)&desc, value: 0, count: sizeof(desc));
    v3 = (float *)v2[66].__vftable;
    desc.m_pTexCoord[0] = v3 + 12;
    desc.m_pTexCoord[1] = v3 + 14;
    v4 = v3 + 6;
    desc.m_pPosition = v3;
    desc.m_pNormal = v3 + 3;
    v5 = (unsigned __int16 *)v2[61].__vftable;
    desc.m_pTangentT = v3 + 9;
    v6 = v2[119].__vftable;
    desc.m_pTangentS = v4;
    v7 = v2[8].__vftable;
    desc.m_pIndices = v5;
    ComputeShadowFragments = (IDispInfo_vtbl *)v6->ComputeShadowFragments;
    v12 = v7;
    v2[59].__vftable = ComputeShadowFragments;
    v9 = v12;
    v10 = desc.m_CompressionType == VERTEX_COMPRESSION_NONE;
    desc.m_VertexSize_Position = 64;
    desc.m_VertexSize_TexCoord[0] = 64;
    desc.m_VertexSize_TexCoord[1] = 64;
    desc.m_VertexSize_Normal = 64;
    desc.m_VertexSize_TangentS = 64;
    desc.m_VertexSize_TangentT = 64;
    desc.m_nIndexSize = 1;
    *(MeshDesc_t *)&v2[13].__vftable = desc;
    v2[60].__vftable = v9;
    if ( !v10 )
      _Warning(a1: "Cannot use CBaseMeshReader with compressed vertices!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C1A00
// Name: public: CBitVec<289>::CBitVec<289>(void)
// Source: json
//------------------------------------------------------------------------------
CBitVec<289> *__thiscall CBitVec<289>::CBitVec<289>(CBitVec<289> *this)
{
  CBitVec<289> *result; // eax

  result = this;
  if ( this != nullptr )
  {
    this->m_Ints[0] = 0;
    this->m_Ints[1] = 0;
    this->m_Ints[2] = 0;
    this->m_Ints[3] = 0;
    this->m_Ints[4] = 0;
    this->m_Ints[5] = 0;
    this->m_Ints[6] = 0;
    this->m_Ints[7] = 0;
    this->m_Ints[8] = 0;
    this->m_Ints[9] = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C1AA0
// Name: public: CDispInfo::CDispInfo(void)
// Source: json
//------------------------------------------------------------------------------
CDispInfo *__thiscall CDispInfo::CDispInfo(CDispInfo *this)
{
  CDispInfo *result; // eax

  result = this;
  this->CDispUtilsHelper::__vftable = (CDispUtilsHelper_vtbl *)&CDispUtilsHelper::`vftable';
  this->IDispInfo::__vftable = (CDispInfo_vtbl *)&CDispInfo::`vftable'{for `IDispInfo'};
  this->CDispUtilsHelper::__vftable = (CDispUtilsHelper_vtbl *)&CDispInfo::`vftable'{for `CDispUtilsHelper'};
  this->m_MeshReader.m_pMesh = nullptr;
  this->m_Indices.m_Memory.m_pMemory = nullptr;
  this->m_Indices.m_Memory.m_nAllocationCount = 0;
  this->m_Indices.m_Memory.m_nGrowSize = 0;
  this->m_Indices.m_Size = 0;
  this->m_Indices.m_pElements = nullptr;
  this->m_Verts.m_Memory.m_pMemory = nullptr;
  this->m_Verts.m_Memory.m_nAllocated = 0;
  this->m_Verts.m_Size = 0;
  this->m_Verts.m_pElements = nullptr;
  if ( this != (CDispInfo *)-280 )
  {
    this->m_ActiveVerts.m_Ints[0] = 0;
    this->m_ActiveVerts.m_Ints[1] = 0;
    this->m_ActiveVerts.m_Ints[2] = 0;
    this->m_ActiveVerts.m_Ints[3] = 0;
    this->m_ActiveVerts.m_Ints[4] = 0;
    this->m_ActiveVerts.m_Ints[5] = 0;
    this->m_ActiveVerts.m_Ints[6] = 0;
    this->m_ActiveVerts.m_Ints[7] = 0;
    this->m_ActiveVerts.m_Ints[8] = 0;
    this->m_ActiveVerts.m_Ints[9] = 0;
  }
  if ( this != (CDispInfo *)-320 )
  {
    this->m_AllowedVerts.m_Ints[0] = 0;
    this->m_AllowedVerts.m_Ints[1] = 0;
    this->m_AllowedVerts.m_Ints[2] = 0;
    this->m_AllowedVerts.m_Ints[3] = 0;
    this->m_AllowedVerts.m_Ints[4] = 0;
    this->m_AllowedVerts.m_Ints[5] = 0;
    this->m_AllowedVerts.m_Ints[6] = 0;
    this->m_AllowedVerts.m_Ints[7] = 0;
    this->m_AllowedVerts.m_Ints[8] = 0;
    this->m_AllowedVerts.m_Ints[9] = 0;
  }
  this->m_ParentSurfID = nullptr;
  this->m_bTouched = false;
  ++g_ConstructorChecker.m_nConstructedObjects;
  this->m_BBoxMin.x = 0.0;
  this->m_BBoxMin.y = 0.0;
  this->m_BBoxMin.z = 0.0;
  this->m_BBoxMax.x = 0.0;
  this->m_BBoxMax.y = 0.0;
  this->m_BBoxMax.z = 0.0;
  this->m_idLMPage = -1;
  this->m_pPowerInfo = nullptr;
  this->m_ViewerSphereCenter.x = 1.0e24;
  this->m_ViewerSphereCenter.y = 1.0e24;
  this->m_ViewerSphereCenter.z = 1.0e24;
  this->m_bInUse = false;
  this->m_pNodeInfo = nullptr;
  this->m_pMesh = nullptr;
  this->m_pDispArray = nullptr;
  this->m_Tag = 0;
  this->m_FirstDecal = -1;
  this->m_FirstShadowDecal = -1;
  this->m_EdgeNeighbors[0].m_SubNeighbors[0].m_iNeighbor = -1;
  this->m_EdgeNeighbors[0].m_SubNeighbors[1].m_iNeighbor = -1;
  this->m_CornerNeighbors[0].m_nNeighbors = 0;
  this->m_EdgeNeighbors[1].m_SubNeighbors[0].m_iNeighbor = -1;
  this->m_EdgeNeighbors[1].m_SubNeighbors[1].m_iNeighbor = -1;
  this->m_CornerNeighbors[1].m_nNeighbors = 0;
  this->m_EdgeNeighbors[2].m_SubNeighbors[0].m_iNeighbor = -1;
  this->m_EdgeNeighbors[2].m_SubNeighbors[1].m_iNeighbor = -1;
  this->m_CornerNeighbors[2].m_nNeighbors = 0;
  this->m_EdgeNeighbors[3].m_SubNeighbors[0].m_iNeighbor = -1;
  this->m_EdgeNeighbors[3].m_SubNeighbors[1].m_iNeighbor = -1;
  this->m_CornerNeighbors[3].m_nNeighbors = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C1C30
// Name: public: virtual CDispInfo::~CDispInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::~CDispInfo(CDispInfo *this)
{
  DispNodeInfo_t *m_pNodeInfo; // eax
  CDispRenderVert *m_pMemory; // edx

  m_pNodeInfo = this->m_pNodeInfo;
  this->IDispInfo::__vftable = (CDispInfo_vtbl *)&CDispInfo::`vftable'{for `IDispInfo'};
  this->CDispUtilsHelper::__vftable = (CDispUtilsHelper_vtbl *)&CDispInfo::`vftable'{for `CDispUtilsHelper'};
  if ( m_pNodeInfo != nullptr )
    free(pMem: m_pNodeInfo);
  free(pMem: this->m_pWalkIndices);
  free(pMem: this->m_pBuildIndices);
  --g_ConstructorChecker.m_nConstructedObjects;
  m_pMemory = this->m_Verts.m_Memory.m_pMemory;
  this->m_Verts.m_Size = 0;
  this->m_Verts.m_Memory.m_nAllocated = 0;
  this->m_Verts.m_pElements = m_pMemory;
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Indices);
  this->IDispInfo::__vftable = (CDispInfo_vtbl *)&IDispInfo::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100C1CB0
// Name: AddCombo
// Source: json
//------------------------------------------------------------------------------
CDispGroup *__usercall AddCombo@<eax>(CUtlMemory<S3RGBA,int> *combos@<esi>, int idLMPage, IMaterial *pMaterial)
{
  CDispGroup *v3; // eax
  CDispGroup *v4; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDispGroup **v7; // ecx
  int v8; // eax
  CDispGroup **v9; // edi
  CDispGroup *result; // eax

  v3 = (CDispGroup *)MemAlloc_Alloc(nSize: 0x34u);
  if ( v3 != nullptr )
  {
    v3->m_Meshes.m_Memory.m_pMemory = nullptr;
    v3->m_Meshes.m_Memory.m_nAllocationCount = 0;
    v3->m_Meshes.m_Memory.m_nGrowSize = 0;
    v3->m_Meshes.m_Size = 0;
    v3->m_Meshes.m_pElements = nullptr;
    v3->m_DispInfos.m_Memory.m_pMemory = nullptr;
    v3->m_DispInfos.m_Memory.m_nAllocationCount = 0;
    v3->m_DispInfos.m_Memory.m_nGrowSize = 0;
    v3->m_DispInfos.m_Size = 0;
    v3->m_DispInfos.m_pElements = nullptr;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  v4->m_pMaterial = pMaterial;
  v4->m_LightmapPageID = idLMPage;
  v4->m_nVisible = 0;
  m_pMemory = (int)combos[1].m_pMemory;
  m_nAllocationCount = combos->m_nAllocationCount;
  if ( m_pMemory + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow(this: combos, num: m_pMemory - m_nAllocationCount + 1);
  ++combos[1].m_pMemory;
  v7 = (CDispGroup **)combos->m_pMemory;
  v8 = (int)combos[1].m_pMemory - m_pMemory - 1;
  combos[1].m_nAllocationCount = (int)combos->m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &v7[m_pMemory + 1], src: &v7[m_pMemory], count: 4 * v8);
  v9 = (CDispGroup **)&combos->m_pMemory[m_pMemory];
  result = v4;
  if ( v9 != nullptr )
    *v9 = v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C1D50
// Name: public: void CDispInfo::CopyMapDispData(class ddispinfo_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::CopyMapDispData(CDispInfo *this, const ddispinfo_t *pBuildDisp)
{
  const CPowerInfo *PowerInfo; // eax
  int power; // [esp-4h] [ebp-8h]
  int v5; // [esp-4h] [ebp-8h]

  this->m_iLightmapAlphaStart = pBuildDisp->m_iLightmapAlphaStart;
  power = pBuildDisp->power;
  this->m_Power = power;
  PowerInfo = GetPowerInfo(iPower: power);
  this->m_pPowerInfo = PowerInfo;
  v5 = (PowerInfo->m_SideLength - 1) * (6 * PowerInfo->m_SideLength - 6);
  this->m_Indices.m_Size = 0;
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
    this: (CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *)&this->m_Indices,
    elem: 0,
    num: v5);
  if ( this->m_pNodeInfo != nullptr )
    free(pMem: this->m_pNodeInfo);
  this->m_pNodeInfo = (DispNodeInfo_t *)MemAlloc_Alloc(
                                          nSize: (28 * (unsigned __int64)(unsigned int)this->m_pPowerInfo->m_NodeCount) >> 32 != 0
                                        ? -1
                                        : 28 * this->m_pPowerInfo->m_NodeCount);
}

//------------------------------------------------------------------------------
// Address: 0x100C1DE0
// Name: void DispInfo_CreateMaterialGroups(struct model_t __near *,struct MaterialSystem_SortInfo_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispInfo_CreateMaterialGroups(model_t *pWorld, const MaterialSystem_SortInfo_t *pSortInfos)
{
  worldbrushdata_t *pShared; // eax
  int v3; // ecx
  IDispInfo_vtbl *v4; // edx
  int lightmapPageID; // edi
  int v6; // ecx
  CDispGroup *v7; // esi
  CDispGroup *v8; // eax
  int m_Size; // edi
  CUtlMemory<S3RGBA,int> *p_m_DispInfos; // esi
  int m_nAllocationCount; // eax
  S3RGBA *m_pMemory; // ecx
  int v13; // eax
  int *v14; // edi
  int iDisp; // [esp+0h] [ebp-4h]

  pShared = pWorld->brush.pShared;
  v3 = 0;
  for ( iDisp = 0; v3 < pShared->numDispInfos; iDisp = v3 )
  {
    v4 = DispInfo_IndexArray(hArray: (_DWORD *)pShared->hDispInfos, iElement: v3)[91].__vftable;
    lightmapPageID = pSortInfos[SHIWORD(v4->SetParent)].lightmapPageID;
    v6 = 0;
    if ( g_DispGroups.m_Size <= 0 )
      goto LABEL_8;
    while ( 1 )
    {
      v7 = g_DispGroups.m_Memory.m_pMemory[v6];
      if ( v7->m_LightmapPageID == lightmapPageID
        && v7->m_pMaterial == host_state.worldbrush->texinfo[HIWORD(v4->GetParent) >> 1].material )
      {
        break;
      }
      if ( ++v6 >= g_DispGroups.m_Size )
        goto LABEL_8;
    }
    v8 = g_DispGroups.m_Memory.m_pMemory[v6];
    if ( v8 == nullptr )
LABEL_8:
      v8 = AddCombo(
             combos: (CUtlMemory<S3RGBA,int> *)&g_DispGroups,
             idLMPage: lightmapPageID,
             pMaterial: host_state.worldbrush->texinfo[HIWORD(v4->GetParent) >> 1].material);
    m_Size = v8->m_DispInfos.m_Size;
    p_m_DispInfos = (CUtlMemory<S3RGBA,int> *)&v8->m_DispInfos;
    m_nAllocationCount = v8->m_DispInfos.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(this: p_m_DispInfos, num: m_Size - m_nAllocationCount + 1);
    ++p_m_DispInfos[1].m_pMemory;
    m_pMemory = p_m_DispInfos->m_pMemory;
    v13 = (int)p_m_DispInfos[1].m_pMemory - m_Size - 1;
    p_m_DispInfos[1].m_nAllocationCount = (int)p_m_DispInfos->m_pMemory;
    if ( v13 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v13);
    v14 = (int *)&p_m_DispInfos->m_pMemory[m_Size];
    if ( v14 != nullptr )
      *v14 = iDisp;
    pShared = pWorld->brush.pShared;
    v3 = iDisp + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C1F10
// Name: public: void CDispInfo::CopyCoreDispVertData(class CCoreDispInfo const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::CopyCoreDispVertData(
        CDispInfo *this,
        const CCoreDispInfo *pCoreDisp,
        float bumpSTexCoordOffset)
{
  int v4; // eax
  int m_MaxVerts; // edi
  const CPowerInfo *m_pPowerInfo; // ecx
  int v7; // edi
  int v8; // ecx
  float *p_z; // eax
  CDispRenderVert *m_pMemory; // edx
  double v11; // st7
  Vector2D *p_m_vTexCoord; // edx
  Vector2D *p_m_LMCoords; // edx
  Vector *p_m_vNormal; // edx
  Vector *p_m_vSVector; // edx
  Vector *p_m_vTVector; // edx
  int v17; // eax

  if ( ((this->m_ParentSurfID->flags & 8) != 0 ? 4 : 1) <= 1u )
    bumpSTexCoordOffset = 0.0;
  v4 = CHunkAllocCredit::s_DbgInfoStackDepth + 1;
  CHunkAllocCredit::s_DbgInfoStackDepth = v4;
  if ( v4 < 8 )
    CHunkAllocCredit::s_DbgInfoStack[v4] = "CopyCoreDispVertData";
  m_MaxVerts = this->m_pPowerInfo->m_MaxVerts;
  this->m_Verts.m_Size = 0;
  if ( m_MaxVerts != 0 )
  {
    CUtlVector<CDispRenderVert,CHunkMemory<CDispRenderVert>>::GrowVector(this: &this->m_Verts, num: m_MaxVerts);
    if ( this->m_Verts.m_Size - m_MaxVerts > 0 && m_MaxVerts > 0 )
      _V_memmove(
        dest: &this->m_Verts.m_Memory.m_pMemory[m_MaxVerts],
        src: this->m_Verts.m_Memory.m_pMemory,
        count: (this->m_Verts.m_Size - m_MaxVerts) << 6);
  }
  m_pPowerInfo = this->m_pPowerInfo;
  v7 = 0;
  this->m_BumpSTexCoordOffset = bumpSTexCoordOffset;
  if ( m_pPowerInfo->m_MaxVerts > 0 )
  {
    v8 = 0;
    p_z = &pCoreDisp->m_pVerts->m_Vert.z;
    do
    {
      m_pMemory = this->m_Verts.m_Memory.m_pMemory;
      m_pMemory[v8].m_vPos.x = *(p_z - 2);
      ++v7;
      v11 = *(p_z - 1);
      p_z += 56;
      m_pMemory[v8].m_vPos.y = v11;
      m_pMemory[v8].m_vPos.z = *(p_z - 56);
      p_m_vTexCoord = &this->m_Verts.m_Memory.m_pMemory[v8].m_vTexCoord;
      p_m_vTexCoord->x = *(p_z - 43);
      p_m_vTexCoord->y = *(p_z - 42);
      p_m_LMCoords = &this->m_Verts.m_Memory.m_pMemory[v8].m_LMCoords;
      p_m_LMCoords->x = *(p_z - 41);
      p_m_LMCoords->y = *(p_z - 40);
      p_m_vNormal = &this->m_Verts.m_Memory.m_pMemory[v8].m_vNormal;
      p_m_vNormal->x = *(p_z - 52);
      p_m_vNormal->y = *(p_z - 51);
      p_m_vNormal->z = *(p_z - 50);
      p_m_vSVector = &this->m_Verts.m_Memory.m_pMemory[v8].m_vSVector;
      p_m_vSVector->x = *(p_z - 49);
      p_m_vSVector->y = *(p_z - 48);
      p_m_vSVector->z = *(p_z - 47);
      p_m_vTVector = &this->m_Verts.m_Memory.m_pMemory[v8].m_vTVector;
      p_m_vTVector->x = *(p_z - 46);
      ++v8;
      p_m_vTVector->y = *(p_z - 45);
      p_m_vTVector->z = *(p_z - 44);
    }
    while ( v7 < this->m_pPowerInfo->m_MaxVerts );
  }
  v17 = CHunkAllocCredit::s_DbgInfoStackDepth;
  if ( CHunkAllocCredit::s_DbgInfoStackDepth >= 0 )
  {
    CHunkAllocCredit::s_DbgInfoStack[CHunkAllocCredit::s_DbgInfoStackDepth] = nullptr;
    CHunkAllocCredit::s_DbgInfoStackDepth = v17 - 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C20D0
// Name: public: bool CDispInfo::CopyCoreDispData(struct model_t __near *,struct MaterialSystem_SortInfo_t const __near *,class CCoreDispInfo const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispInfo::CopyCoreDispData(
        CDispInfo *this,
        model_t *pWorld,
        model_t *pSortInfos,
        const MaterialSystem_SortInfo_t *pCoreDisp,
        bool bRestoring)
{
  int v6; // edx
  CDispInfo_vtbl *v7; // eax
  msurface2_t *v8; // eax
  float m_BumpSTexCoordOffset; // xmm0_4
  const CPowerInfo *m_pPowerInfo; // ecx
  int v11; // edi
  int v12; // edx
  Vector2D *v13; // eax
  Vector2D *p_m_LMCoords; // ecx
  SurfaceCtx_t ctx; // [esp+Ch] [ebp-24h] BYREF

  v6 = *(_DWORD *)&pSortInfos->szPathName[8 * this->GetParent(this)->materialSortID];
  v7 = this->IDispInfo::__vftable;
  this->m_idLMPage = v6;
  v8 = v7->GetParent(this);
  SurfSetupSurfaceContext(&ctx, surfID: v8);
  if ( !bRestoring )
  {
    this->m_BaseSurfaceTexCoords[0].x = *(float *)&pCoreDisp[15].material;
    this->m_BaseSurfaceTexCoords[0].y = *(float *)&pCoreDisp[15].lightmapPageID;
    this->m_BaseSurfacePositions[0].x = *(float *)&pCoreDisp[3].material;
    this->m_BaseSurfacePositions[0].y = *(float *)&pCoreDisp[3].lightmapPageID;
    this->m_BaseSurfacePositions[0].z = *(float *)&pCoreDisp[4].material;
    this->m_BaseSurfaceTexCoords[1] = (Vector2D)pCoreDisp[16];
    this->m_BaseSurfacePositions[1] = *(Vector *)&pCoreDisp[4].lightmapPageID;
    this->m_BaseSurfaceTexCoords[2] = (Vector2D)pCoreDisp[17];
    this->m_BaseSurfacePositions[2] = *(Vector *)&pCoreDisp[6].material;
    this->m_BaseSurfaceTexCoords[3] = (Vector2D)pCoreDisp[18];
    this->m_BaseSurfacePositions[3] = *(Vector *)&pCoreDisp[7].lightmapPageID;
    CDispInfo::CopyCoreDispVertData(
      this,
      (const CCoreDispInfo *)pCoreDisp,
      bumpSTexCoordOffset: ctx.m_BumpSTexCoordOffset);
    *(_DWORD *)&this->m_EdgeNeighbors[0].m_SubNeighbors[0].m_iNeighbor = pCoreDisp[78].material;
    *(_DWORD *)&this->m_EdgeNeighbors[0].m_SubNeighbors[0].m_NeighborSpan = pCoreDisp[78].lightmapPageID;
    *(_DWORD *)&this->m_EdgeNeighbors[0].m_SubNeighbors[1].m_NeighborOrientation = pCoreDisp[79].material;
    *(_DWORD *)this->m_CornerNeighbors[0].m_Neighbors = pCoreDisp[84].material;
    *(_DWORD *)&this->m_CornerNeighbors[0].m_Neighbors[2] = pCoreDisp[84].lightmapPageID;
    *(_WORD *)&this->m_CornerNeighbors[0].m_nNeighbors = pCoreDisp[85].material;
    this->m_EdgeNeighbors[1] = *(CDispNeighbor *)&pCoreDisp[79].lightmapPageID;
    this->m_CornerNeighbors[1] = *(CDispCornerNeighbors *)((char *)&pCoreDisp[85].material + 2);
    this->m_EdgeNeighbors[2] = *(CDispNeighbor *)&pCoreDisp[81].material;
    this->m_CornerNeighbors[2] = *(CDispCornerNeighbors *)&pCoreDisp[86].lightmapPageID;
    this->m_EdgeNeighbors[3] = *(CDispNeighbor *)&pCoreDisp[82].lightmapPageID;
    this->m_CornerNeighbors[3] = *(CDispCornerNeighbors *)((char *)&pCoreDisp[87].lightmapPageID + 2);
    memcpy(
      dst: (unsigned __int8 *)&this->m_AllowedVerts,
      src: (unsigned __int8 *)&pCoreDisp[100],
      count: sizeof(this->m_AllowedVerts));
    this->m_nIndices = 0;
    return 1;
  }
  if ( ((this->m_ParentSurfID->flags & 8) != 0 ? 4 : 1) <= 1u )
    m_BumpSTexCoordOffset = 0.0;
  else
    m_BumpSTexCoordOffset = ctx.m_BumpSTexCoordOffset;
  m_pPowerInfo = this->m_pPowerInfo;
  v11 = 0;
  this->m_BumpSTexCoordOffset = m_BumpSTexCoordOffset;
  if ( m_pPowerInfo->m_MaxVerts <= 0 )
    return 1;
  v12 = 0;
  v13 = (Vector2D *)&pCoreDisp[95].material[27];
  do
  {
    p_m_LMCoords = &this->m_Verts.m_Memory.m_pMemory[v12].m_LMCoords;
    p_m_LMCoords->x = v13->x;
    ++v11;
    ++v12;
    p_m_LMCoords->y = v13->y;
    v13 += 28;
  }
  while ( v11 < this->m_pPowerInfo->m_MaxVerts );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C2640
// Name: void AddEmptyMesh(struct model_t __near *,class CDispGroup __near *,class ddispinfo_t const __near *,int __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall AddEmptyMesh(
        int a1@<edi>,
        model_t *pWorld,
        CDispGroup *pCombo,
        const ddispinfo_t *pMapDisps,
        int *pDispInfos,
        int nDisps,
        int nTotalVerts,
        int nTotalIndices)
{
  IMatRenderContext *v8; // eax
  int v9; // ebx
  CGroupMesh *v10; // eax
  CGroupMesh *v11; // edi
  int v12; // ecx
  int m_nAllocationCount; // eax
  CGroupMesh **m_pMemory; // edx
  int v15; // eax
  CGroupMesh **v16; // ecx
  __int64 v17; // rax
  int v18; // esi
  signed int v19; // eax
  int m_nVertexCount; // eax
  int v21; // esi
  CDispInfo *v22; // edi
  const ddispinfo_t *v23; // eax
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder builder; // [esp+8h] [ebp-1F4h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F0h] [ebp-Ch]
  CGroupMesh *pMesh; // [esp+1F4h] [ebp-8h]
  int nIndices; // [esp+1F8h] [ebp-4h] BYREF
  int iIndexOffset; // [esp+208h] [ebp+Ch]

  v8 = materials->GetRenderContext(this: materials);
  v9 = 0;
  pRenderContext.m_pObject = v8;
  if ( v8 != nullptr )
    v8->BeginRender(this: v8);
  v10 = (CGroupMesh *)MemAlloc_Alloc(nSize: 0x48u);
  if ( v10 != nullptr )
  {
    v10->m_DispInfos.m_Memory.m_pMemory = nullptr;
    v10->m_DispInfos.m_Memory.m_nAllocationCount = 0;
    v10->m_DispInfos.m_Memory.m_nGrowSize = 0;
    v10->m_DispInfos.m_Size = 0;
    v10->m_DispInfos.m_pElements = nullptr;
    v10->m_VisibleDisps.m_Memory.m_pMemory = nullptr;
    v10->m_VisibleDisps.m_Memory.m_nAllocationCount = 0;
    v10->m_VisibleDisps.m_Memory.m_nGrowSize = 0;
    v10->m_VisibleDisps.m_Size = 0;
    v10->m_VisibleDisps.m_pElements = nullptr;
    v11 = v10;
    v10->m_Visible.m_Memory.m_pMemory = nullptr;
    v10->m_Visible.m_Memory.m_nAllocationCount = 0;
    v10->m_Visible.m_Memory.m_nGrowSize = 0;
    v10->m_Visible.m_Size = 0;
    v10->m_Visible.m_pElements = nullptr;
    pMesh = v10;
  }
  else
  {
    pMesh = nullptr;
    v11 = nullptr;
  }
  m_nAllocationCount = pCombo->m_Meshes.m_Memory.m_nAllocationCount;
  nIndices = pCombo->m_Meshes.m_Size;
  v12 = nIndices;
  if ( nIndices + 1 > m_nAllocationCount )
  {
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&pCombo->m_Meshes,
      num: nIndices - m_nAllocationCount + 1);
    v12 = nIndices;
  }
  ++pCombo->m_Meshes.m_Size;
  m_pMemory = pCombo->m_Meshes.m_Memory.m_pMemory;
  v15 = pCombo->m_Meshes.m_Size - v12 - 1;
  pCombo->m_Meshes.m_pElements = m_pMemory;
  if ( v15 > 0 )
  {
    _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * v15);
    v12 = nIndices;
  }
  v16 = &pCombo->m_Meshes.m_Memory.m_pMemory[v12];
  if ( v16 != nullptr )
    *v16 = v11;
  v17 = ((__int64 (__thiscall *)(IMaterial *, int))pCombo->m_pMaterial->GetVertexFormat)(
          a1: pCombo->m_pMaterial,
          a2: a1);
  v11->m_pMesh = (IMesh *)((int (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, const char *, _DWORD, _DWORD))pRenderContext.m_pObject->CreateStaticMesh)(
                            a1: pRenderContext.m_pObject,
                            a2: v17 & 0xFFFFFBFF,
                            a3: HIDWORD(v17),
                            a4: "Displacement Verts",
                            a5: 0,
                            a6: 0);
  v11->m_pGroup = pCombo;
  v11->m_nVisible = 0;
  CMeshBuilder::CMeshBuilder(this: &builder);
  v18 = nTotalIndices;
  CMeshBuilder::Begin(
    this: &builder,
    pMesh: v11->m_pMesh,
    type: MATERIAL_TRIANGLES,
    nVertexCount: nTotalVerts,
    nIndexCount: nTotalIndices,
    pMeshSettings: nullptr);
  v19 = v18 * builder.m_IndexBuilder.m_nIndexSize + builder.m_IndexBuilder.m_nCurrentIndex;
  builder.m_IndexBuilder.m_nCurrentIndex = v19;
  if ( v19 > builder.m_IndexBuilder.m_nIndexCount )
    builder.m_IndexBuilder.m_nIndexCount = v19;
  CVertexBuilder::AdvanceVertices(this: &builder.m_VertexBuilder, nVerts: nTotalVerts);
  if ( builder.m_bGenerateIndices )
  {
    switch ( builder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * builder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * builder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * builder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * builder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = builder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &builder.m_IndexBuilder,
      primitiveType: builder.m_Type,
      nIndexCount: m_nVertexCount);
  }
  ((void (__thiscall *)(IMesh *, int, int))builder.m_pMesh->UnlockMesh)(
    a1: builder.m_pMesh,
    a2: builder.m_VertexBuilder.m_nVertexCount,
    a3: builder.m_IndexBuilder.m_nIndexCount);
  builder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  builder.m_IndexBuilder.m_nMaxIndexCount = 0;
  builder.m_VertexBuilder.m_nMaxVertexCount = 0;
  builder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  builder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  builder.m_pMesh = nullptr;
  v11->m_DispInfos.m_Size = 0;
  CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&v11->m_DispInfos,
    elem: 0,
    num: nDisps);
  v11->m_Visible.m_Size = 0;
  CUtlVector<CPrimList,CUtlMemory<CPrimList,int>>::InsertMultipleBefore(
    this: (CUtlVector<ResourceEntryInfo,CUtlMemory<ResourceEntryInfo,int> > *)&v11->m_Visible,
    elem: 0,
    num: nDisps);
  v11->m_VisibleDisps.m_Size = 0;
  CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&v11->m_VisibleDisps,
    elem: 0,
    num: nDisps);
  v21 = 0;
  for ( iIndexOffset = 0; v21 < nDisps; ++v21 )
  {
    v22 = (CDispInfo *)DispInfo_IndexArray(
                         hArray: *(_DWORD **)(pWorld->sprite.numframes + 112),
                         iElement: pDispInfos[v21]);
    v23 = &pMapDisps[pDispInfos[v21]];
    v22->m_pMesh = pMesh;
    v22->m_iIndexOffset = iIndexOffset;
    v22->m_iVertOffset = v9;
    CalcMaxNumVertsAndIndices(power: v23->power, nVerts: &nTotalIndices, &nIndices);
    v9 += nTotalIndices;
    iIndexOffset += nIndices;
    pMesh->m_DispInfos.m_Memory.m_pMemory[v21] = v22;
  }
  if ( builder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && builder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: builder.m_VertexBuilder.m_pVertexBuffer) )
  {
    builder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: builder.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( builder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && builder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: builder.m_IndexBuilder.m_pIndexBuffer) )
  {
    builder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: builder.m_IndexBuilder.m_pIndexBuffer);
  }
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x100C2950
// Name: void DispInfo_CreateEmptyStaticBuffers(struct model_t __near *,class ddispinfo_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispInfo_CreateEmptyStaticBuffers(model_t *pWorld, const ddispinfo_t *pMapDisps)
{
  int v2; // esi
  int v3; // eax
  CDispGroup *v4; // edi
  int v5; // ebx
  int v6; // eax
  int i; // [esp+4h] [ebp-14h]
  int nVerts; // [esp+8h] [ebp-10h] BYREF
  int nIndices; // [esp+Ch] [ebp-Ch] BYREF
  int iStart; // [esp+10h] [ebp-8h]
  int nTotalIndices; // [esp+14h] [ebp-4h]

  v2 = 0;
  v3 = 0;
  i = 0;
  if ( g_DispGroups.m_Size <= 0 )
    return;
  while ( 2 )
  {
    v4 = g_DispGroups.m_Memory.m_pMemory[v3];
    v5 = 0;
    nTotalIndices = 0;
    iStart = 0;
    if ( v4->m_DispInfos.m_Size <= 0 )
      goto LABEL_13;
    while ( 1 )
    {
      CalcMaxNumVertsAndIndices(power: pMapDisps[v4->m_DispInfos.m_Memory.m_pMemory[v2]].power, &nVerts, &nIndices);
      v6 = nTotalIndices;
      if ( v5 + nVerts > 0x2000 || (nTotalIndices += nIndices, v6 + nIndices > 0x2000) )
      {
        AddEmptyMesh(
          a1: (int)v4,
          pWorld,
          pCombo: v4,
          pMapDisps,
          pDispInfos: &v4->m_DispInfos.m_Memory.m_pMemory[iStart],
          nDisps: v2 - iStart,
          nTotalVerts: v5,
          nTotalIndices: v6);
        v5 = 0;
        iStart = v2;
        nTotalIndices = 0;
        --v2;
        goto LABEL_10;
      }
      if ( v2 == v4->m_DispInfos.m_Size - 1 )
        break;
      v5 += nVerts;
LABEL_10:
      if ( ++v2 >= v4->m_DispInfos.m_Size )
        goto LABEL_13;
    }
    AddEmptyMesh(
      a1: (int)v4,
      pWorld,
      pCombo: v4,
      pMapDisps,
      pDispInfos: &v4->m_DispInfos.m_Memory.m_pMemory[iStart],
      nDisps: v2 - iStart + 1,
      nTotalVerts: v5 + nVerts,
      nTotalIndices: v6 + nIndices);
LABEL_13:
    v3 = i + 1;
    i = v3;
    if ( v3 < g_DispGroups.m_Size )
    {
      v2 = 0;
      continue;
    }
    break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C2A70
// Name: bool DispInfo_CreateFromMapDisp(struct model_t __near *,int,class ddispinfo_t const __near *,class CCoreDispInfo __near *,class CDispVert const __near *,class CDispTri const __near *,class CDispMultiBlend const __near *,struct MaterialSystem_SortInfo_t const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl DispInfo_CreateFromMapDisp(
        model_t *pWorld,
        int iDisp,
        const ddispinfo_t *pMapDisp,
        CCoreDispInfo *pCoreDisp,
        const CDispVert *pVerts,
        model_t *pTris,
        const CDispMultiBlend *pMultiBlend,
        model_t *pSortInfos,
        bool bRestoring)
{
  IDispInfo *v9; // eax
  CDispInfo *v10; // ebx
  msurface2_t *v11; // eax

  v9 = DispInfo_IndexArray(hArray: *(_DWORD **)(pWorld->sprite.numframes + 112), iElement: iDisp);
  pCoreDisp->m_Surf.m_PointStart = pMapDisp->startPosition;
  v10 = (CDispInfo *)v9;
  CCoreDispInfo::InitDispInfo(
    this: pCoreDisp,
    power: pMapDisp->power,
    minTess: pMapDisp->minTess,
    smoothingAngle: pMapDisp->smoothingAngle,
    pVerts,
    (const CDispTri *)pTris,
    nFlags: pMapDisp->minTess,
    pvMultiBlends: pMultiBlend);
  CCoreDispSurface::SetNeighborData(
    this: &pCoreDisp->m_Surf,
    edgeNeighbors: pMapDisp->m_EdgeNeighbors,
    cornerNeighbors: pMapDisp->m_CornerNeighbors);
  pCoreDisp->m_AllowedVerts = *(CBitVec<289> *)pMapDisp->m_AllowedVerts;
  v11 = v10->GetParent(this: v10);
  BuildDispSurfInit(pWorld, pBuildDisp: pCoreDisp, worldSurfID: v11);
  if ( CCoreDispInfo::Create(this: pCoreDisp) == 0 )
    return 0;
  v10->m_iPointStart = pCoreDisp->m_Surf.m_PointStartIndex;
  v10->m_Index = iDisp;
  CDispInfo::CopyMapDispData(this: v10, pBuildDisp: pMapDisp);
  if ( CDispInfo::CopyCoreDispData(
         this: v10,
         pWorld,
         pSortInfos,
         (const MaterialSystem_SortInfo_t *)pCoreDisp,
         bRestoring) == 0 )
    return 0;
  CDispInfo::InitializeActiveVerts(this: v10);
  v10->m_iLightmapSamplePositionStart = pMapDisp->m_iLightmapSamplePositionStart;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C2BE0
// Name: void DispInfo_ReleaseMaterialSystemObjects(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispInfo_ReleaseMaterialSystemObjects(model_t *pWorld)
{
  IMatRenderContext *v1; // ebx
  CDispGroup *v2; // edi
  int i; // esi
  worldbrushdata_t *pShared; // eax
  int j; // esi
  IDispInfo *v6; // eax
  int iGroup; // [esp+4h] [ebp-4h]

  v1 = materials->GetRenderContext(this: materials);
  if ( v1 != nullptr )
    v1->BeginRender(this: v1);
  for ( iGroup = 0; iGroup < g_DispGroups.m_Size; ++iGroup )
  {
    v2 = g_DispGroups.m_Memory.m_pMemory[iGroup];
    for ( i = 0; i < v2->m_Meshes.m_Size; ++i )
      v1->DestroyStaticMesh(this: v1, a2: v2->m_Meshes.m_Memory.m_pMemory[i]->m_pMesh);
    CUtlVector<CGroupMesh *,CUtlMemory<CGroupMesh *,int>>::PurgeAndDeleteElements(this: &v2->m_Meshes);
  }
  CUtlVector<CDispGroup *,CUtlMemory<CDispGroup *,int>>::PurgeAndDeleteElements(this: &g_DispGroups);
  if ( pWorld != nullptr )
  {
    pShared = pWorld->brush.pShared;
    for ( j = 0; j < pShared->numDispInfos; ++j )
    {
      v6 = DispInfo_IndexArray(hArray: (_DWORD *)pShared->hDispInfos, iElement: j);
      if ( v6 != nullptr )
      {
        v6[10].__vftable = nullptr;
        v6[9].__vftable = nullptr;
        v6[11].__vftable = nullptr;
      }
      pShared = pWorld->brush.pShared;
    }
  }
  if ( v1 != nullptr )
  {
    v1->EndRender(this: v1);
    v1->Release(this: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C2CD0
// Name: bool DispInfo_LoadDisplacements(struct model_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl DispInfo_LoadDisplacements(model_t *pWorld, bool bRestoring)
{
  signed int v2; // ebx
  int v3; // esi
  model_t *v4; // esi
  S3RGBA *m_pMemory; // edi
  int v6; // eax
  _DWORD *Array; // eax
  bool v8; // zf
  int v9; // eax
  int v10; // eax
  CCoreDispInfo *v11; // eax
  S3RGBA *v12; // esi
  S3RGBA *v13; // ecx
  int *v14; // esi
  int *p_power; // edi
  int v16; // esi
  int v17; // esi
  int j; // esi
  CDispInfo *v19; // edi
  CDispInfo *v20; // eax
  int k; // esi
  IDispInfo *v22; // eax
  int m; // esi
  CDispInfo *v24; // eax
  int n; // esi
  CDispInfo *v26; // eax
  ddispinfo_t pMapDisps; // [esp+10h] [ebp-5FAD8h] BYREF
  CDispMultiBlend pMultiBlend; // [esp+58010h] [ebp-7AD8h] BYREF
  _BYTE pData[12]; // [esp+5DA60h] [ebp-2088h] BYREF
  model_t v31[3]; // [esp+5F0F4h] [ebp-9F4h] BYREF
  CMapLoadHelper v32; // [esp+5F4F4h] [ebp-5F4h] BYREF
  CMapLoadHelper v33; // [esp+5F61Ch] [ebp-4CCh] BYREF
  CMapLoadHelper v34; // [esp+5F744h] [ebp-3A4h] BYREF
  CMapLoadHelper v35; // [esp+5F86Ch] [ebp-27Ch] BYREF
  CMapLoadHelper v36; // [esp+5F994h] [ebp-154h] BYREF
  MaterialSystem_SortInfo_t *v37; // [esp+5FABCh] [ebp-2Ch]
  signed int i; // [esp+5FAC0h] [ebp-28h]
  int v39; // [esp+5FAC4h] [ebp-24h]
  MaterialSystem_SortInfo_t *pSortInfos; // [esp+5FAC8h] [ebp-20h]
  int v41; // [esp+5FACCh] [ebp-1Ch]
  CUtlMemory<S3RGBA,int> v42; // [esp+5FAD0h] [ebp-18h] BYREF
  CUtlMemory<S3RGBA,int> v43; // [esp+5FADCh] [ebp-Ch]
  CCoreDispInfo *v44; // [esp+5FAF4h] [ebp+Ch]

  v37 = materialSortInfoArray;
  v2 = CMapLoadHelper::LumpSize(lumpId: 26) / 0xB0u;
  v3 = CMapLoadHelper::LumpSize(lumpId: 34);
  if ( bRestoring )
  {
    v4 = pWorld;
    m_pMemory = nullptr;
    if ( *(_DWORD *)(pWorld->sprite.numframes + 108) != v2 )
      v43.m_nGrowSize = 1;
    v6 = *(_DWORD *)(pWorld->sprite.numframes + 108);
    if ( v6 == 0 && v2 != 0 )
      return 0;
    if ( v6 != v2 )
      _Error(a1: "DispInfo_LoadDisplacments: dispcounts (%d and %d) don't match.", v6, v2);
  }
  else
  {
    *(_DWORD *)(pWorld->sprite.numframes + 108) = v2;
    Array = DispInfo_CreateArray(nElements: *(_DWORD *)(pWorld->sprite.numframes + 108));
    v8 = (_S1_5 & 1) == 0;
    *(_DWORD *)(pWorld->sprite.numframes + 112) = Array;
    if ( v8 )
    {
      _S1_5 |= 1u;
      ConVarRef::ConVarRef(this: &r_dlightsenable, pName: "r_dlightsenable");
    }
    if ( r_dlightsenable.m_pConVarState->m_Value.m_nValue != 0 )
    {
      v9 = CHunkAllocCredit::s_DbgInfoStackDepth + 1;
      CHunkAllocCredit::s_DbgInfoStackDepth = v9;
      if ( v9 < 8 )
        CHunkAllocCredit::s_DbgInfoStack[v9] = "g_DispLightmapSamplePositions";
      g_DispLightmapSamplePositions.m_Size = 0;
      if ( v3 != 0 )
      {
        CUtlVector<unsigned char,CHunkMemory<unsigned char>>::GrowVector(this: &g_DispLightmapSamplePositions, num: v3);
        if ( g_DispLightmapSamplePositions.m_Size - v3 > 0 && v3 > 0 )
          _V_memmove(
            dest: &g_DispLightmapSamplePositions.m_Memory.m_pMemory[v3],
            src: g_DispLightmapSamplePositions.m_Memory.m_pMemory,
            count: g_DispLightmapSamplePositions.m_Size - v3);
      }
      CMapLoadHelper::CMapLoadHelper(this: &v32, lumpToLoad: 0x22u, bUncompress: true);
      CMapLoadHelper::LoadLumpData(
        this: &v32,
        offset: 0,
        size: v3,
        pData: g_DispLightmapSamplePositions.m_Memory.m_pMemory);
      CMapLoadHelper::~CMapLoadHelper(this: &v32);
      v10 = CHunkAllocCredit::s_DbgInfoStackDepth;
      if ( CHunkAllocCredit::s_DbgInfoStackDepth >= 0 )
      {
        CHunkAllocCredit::s_DbgInfoStack[CHunkAllocCredit::s_DbgInfoStackDepth] = nullptr;
        CHunkAllocCredit::s_DbgInfoStackDepth = v10 - 1;
      }
    }
    v4 = pWorld;
    m_pMemory = nullptr;
  }
  DispInfo_ReleaseMaterialSystemObjects(pWorld: v4);
  if ( v2 > 2048 )
    _Error(a1: "DispInfo_LoadDisplacements: nDisplacements (%d) > MAX_MAP_DISPINFO (%d)", v2, 2048);
  CMapLoadHelper::CMapLoadHelper(this: &v33, lumpToLoad: 0x1Au, bUncompress: true);
  CMapLoadHelper::LoadLumpData(this: &v33, offset: 0, size: 176 * v2, pData: &pMapDisps);
  DispInfo_LinkToParentFaces(pWorld: v4, &pMapDisps, nDisplacements: v2);
  DispInfo_CreateMaterialGroups(pWorld: v4, pSortInfos: v37);
  if ( g_VBAllocTracker != nullptr )
    g_VBAllocTracker->TrackMeshAllocations(this: g_VBAllocTracker, a2: "DispInfo_LoadDisplacements");
  DispInfo_CreateEmptyStaticBuffers(pWorld: v4, &pMapDisps);
  if ( g_VBAllocTracker != nullptr )
    g_VBAllocTracker->TrackMeshAllocations(this: g_VBAllocTracker, a2: nullptr);
  v39 = 0;
  pSortInfos = nullptr;
  v41 = 0;
  memset(&v42, 0, sizeof(v42));
  v43.m_pMemory = nullptr;
  v43.m_nAllocationCount = 0;
  if ( v2 > 0 )
  {
    for ( i = v2; i != 0; --i )
    {
      v11 = (CCoreDispInfo *)MemAlloc_Alloc(nSize: 0x34Cu);
      if ( v11 != nullptr )
        v43.m_nGrowSize = (int)CCoreDispInfo::CCoreDispInfo(this: v11);
      else
        v43.m_nGrowSize = 0;
      v12 = m_pMemory;
      if ( (int)&m_pMemory->g > v42.m_nAllocationCount )
      {
        CUtlMemory<INetMessage *,int>::Grow(this: &v42, num: (int)(&m_pMemory->g - v42.m_nAllocationCount));
        m_pMemory = v43.m_pMemory;
      }
      v13 = v42.m_pMemory;
      m_pMemory = (S3RGBA *)((char *)m_pMemory + 1);
      v43.m_pMemory = m_pMemory;
      v43.m_nAllocationCount = (int)v42.m_pMemory;
      if ( (char *)m_pMemory - (char *)v12 - 1 > 0 )
      {
        _V_memmove(
          dest: &v42.m_pMemory[(_DWORD)v12 + 1],
          src: &v42.m_pMemory[(_DWORD)v12],
          count: 4 * ((char *)m_pMemory - (char *)v12 - 1));
        v13 = v42.m_pMemory;
      }
      v14 = (int *)&v13[(_DWORD)v12];
      if ( v14 != nullptr )
        *v14 = v43.m_nGrowSize;
    }
  }
  CMapLoadHelper::CMapLoadHelper(this: &v35, lumpToLoad: 0x21u, bUncompress: true);
  CMapLoadHelper::CMapLoadHelper(this: &v34, lumpToLoad: 0x30u, bUncompress: true);
  CMapLoadHelper::CMapLoadHelper(this: &v36, lumpToLoad: 0x3Fu, bUncompress: true);
  v43.m_nGrowSize = 0;
  if ( v2 > 0 )
  {
    p_power = &pMapDisps.power;
    while ( 1 )
    {
      if ( p_power != (int *)20 )
      {
        v16 = ((1 << *p_power) + 1) * ((1 << *p_power) + 1);
        if ( v16 > 289 )
          _Error(
            a1: "DispInfo_LoadDisplacements: invalid vertex count (%d)",
            ((1 << *p_power) + 1) * ((1 << *p_power) + 1));
        CMapLoadHelper::LoadLumpData(this: &v35, offset: 20 * v39, size: 20 * v16, pData);
        if ( (p_power[1] & 0x40000000) != 0 )
        {
          CMapLoadHelper::LoadLumpData(this: &v36, offset: 80 * v41, size: 80 * v16, pData: &pMultiBlend);
          v41 += v16;
        }
        v39 += v16;
        v17 = 2 * (1 << *p_power) * (1 << *p_power);
        if ( v17 > 512 )
          _Error(a1: "DispInfo_LoadDisplacements: invalid tri count (%d)", 2 * (1 << *p_power) * (1 << *p_power));
        CMapLoadHelper::LoadLumpData(this: &v34, offset: 2 * (_DWORD)pSortInfos, size: 2 * v17, pData: v31);
        pSortInfos = (MaterialSystem_SortInfo_t *)((char *)pSortInfos + v17);
        if ( DispInfo_CreateFromMapDisp(
               pWorld,
               iDisp: v43.m_nGrowSize,
               pMapDisp: (const ddispinfo_t *)(p_power - 5),
               pCoreDisp: *(CCoreDispInfo **)&v42.m_pMemory[v43.m_nGrowSize],
               pVerts: (const CDispVert *)pData,
               pTris: v31,
               &pMultiBlend,
               pSortInfos: (model_t *)v37,
               bRestoring) == 0 )
          break;
      }
      p_power += 44;
      if ( ++v43.m_nGrowSize >= v2 )
        goto LABEL_49;
    }
    CMapLoadHelper::~CMapLoadHelper(this: &v36);
    CMapLoadHelper::~CMapLoadHelper(this: &v34);
    CMapLoadHelper::~CMapLoadHelper(this: &v35);
    if ( v42.m_nGrowSize >= 0 && v42.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v42.m_pMemory);
    CMapLoadHelper::~CMapLoadHelper(this: &v33);
    return 0;
  }
LABEL_49:
  SmoothDispSurfNormals(ppListBase: (CCoreDispInfo **)v42.m_pMemory, nListSize: v2);
  for ( j = 0; j < v2; ++j )
  {
    v44 = (CCoreDispInfo *)v42.m_pMemory[j];
    v19 = (CDispInfo *)DispInfo_IndexArray(hArray: *(_DWORD **)(pWorld->sprite.numframes + 112), iElement: j);
    FillStaticBuffer(
      pMesh: v19->m_pMesh,
      pDisp: v19,
      pCoreDisp: v44,
      pVerts: (const CDispVert *)pData,
      nLightmaps: (v19->m_ParentSurfID->flags & 8) != 0 ? 4 : 1);
    BuildTagData(pCoreDisp: v44, pDisp: v19);
    v20 = (CDispInfo *)DispInfo_IndexArray(hArray: *(_DWORD **)(pWorld->sprite.numframes + 112), iElement: j);
    CDispInfo::CopyCoreDispVertData(
      this: v20,
      pCoreDisp: *(const CCoreDispInfo **)&v42.m_pMemory[j],
      bumpSTexCoordOffset: v20->m_BumpSTexCoordOffset);
  }
  CUtlVector<CCoreDispInfo *,CUtlMemory<CCoreDispInfo *,int>>::PurgeAndDeleteElements(this: (CUtlVector<CCoreDispInfo *,CUtlMemory<CCoreDispInfo *,int> > *)&v42);
  for ( k = 0; k < v2; ++k )
  {
    v22 = DispInfo_IndexArray(hArray: *(_DWORD **)(pWorld->sprite.numframes + 112), iElement: k);
    memcpy(dst: (unsigned __int8 *)&v22[70], src: (unsigned __int8 *)&v22[80], count: 0x28u);
  }
  for ( m = 0; m < v2; ++m )
  {
    v24 = (CDispInfo *)DispInfo_IndexArray(hArray: *(_DWORD **)(pWorld->sprite.numframes + 112), iElement: m);
    CDispInfo::TesselateDisplacement(this: v24);
  }
  SetupMeshReaders(pWorld, nDisplacements: v2);
  for ( n = 0; n < v2; ++n )
  {
    v26 = (CDispInfo *)DispInfo_IndexArray(hArray: *(_DWORD **)(pWorld->sprite.numframes + 112), iElement: n);
    CDispInfo::UpdateBoundingBox(this: v26);
  }
  CMapLoadHelper::~CMapLoadHelper(this: &v36);
  CMapLoadHelper::~CMapLoadHelper(this: &v34);
  CMapLoadHelper::~CMapLoadHelper(this: &v35);
  if ( v42.m_nGrowSize >= 0 && v42.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v42.m_pMemory);
  CMapLoadHelper::~CMapLoadHelper(this: &v33);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101336C0
// Name: public: virtual class CBitVec<2048> const __near * CVEngineServer::GetEntityTransmitBitsForClient(int)
// Source: json
//------------------------------------------------------------------------------
const CBitVec<2048> *__thiscall CVEngineServer::GetEntityTransmitBitsForClient(CVEngineServer *this, int iClientIndex)
{
  CClientFrame *ClientFrame; // eax

  if ( iClientIndex >= 0
    && iClientIndex < sv.m_Clients.m_Size
    && (ClientFrame = CClientFrameManager::GetClientFrame(
                        this: (CClientFrameManager *)&sv.m_Clients.m_Memory.m_pMemory[iClientIndex][1],
                        nTick: sv.m_Clients.m_Memory.m_pMemory[iClientIndex]->m_nDeltaTick,
                        bExact: true)) != nullptr )
  {
    return &ClientFrame->transmit_entity;
  }
  else
  {
    return nullptr;
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100C0800
// Name: void Vector2DCopy(class Vector2D const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector2DCopy(const Vector2D *src, Vector2D *dst)
{
  *dst = *src;
}

//------------------------------------------------------------------------------
// Address: 0x100C0820
// Name: public: class Vector4D __near & Vector4D::operator=(class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
Vector4D *__thiscall Vector4D::operator=(Vector4D *this, const Vector4D *vOther)
{
  *this = *vOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C0850
// Name: public: void CDispNeighbor::SetInvalid(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispNeighbor::SetInvalid(CDispNeighbor *this)
{
  this->m_SubNeighbors[0].m_iNeighbor = -1;
  this->m_SubNeighbors[1].m_iNeighbor = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100C0860
// Name: public: void CDispCornerNeighbors::SetInvalid(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispCornerNeighbors::SetInvalid(CDispCornerNeighbors *this)
{
  this->m_nNeighbors = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100C0870
// Name: public: void CCoreDispSurface::GetTexCoord(int,class Vector2D __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCoreDispSurface::GetTexCoord(CCoreDispSurface *this, int index, Vector2D *texCoord)
{
  *texCoord = this->m_TexCoords[index];
}

//------------------------------------------------------------------------------
// Address: 0x100C0890
// Name: public: void CCoreDispSurface::SetFlags(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCoreDispSurface::SetFlags(CCoreDispSurface *this, int flag)
{
  this->m_Flags = flag;
}

//------------------------------------------------------------------------------
// Address: 0x100C08B0
// Name: public: void CCoreDispInfo::GetMultiBlend(int,class Vector4D __near &,class Vector4D __near &,class Vector __near &,class Vector __near &,class Vector __near &,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCoreDispInfo::GetMultiBlend(
        CCoreDispInfo *this,
        int index,
        Vector4D *vBlend,
        Vector4D *vAlphaBlend,
        Vector *vColor1,
        Vector *vColor2,
        Vector *vColor3,
        Vector *vColor4)
{
  CoreDispVert_t *v8; // eax

  v8 = &this->m_pVerts[index];
  *vBlend = v8->m_MultiBlend;
  *vAlphaBlend = v8->m_AlphaBlend;
  *vColor1 = v8->m_vBlendColors[0];
  *vColor2 = v8->m_vBlendColors[1];
  *vColor3 = v8->m_vBlendColors[2];
  *vColor4 = v8->m_vBlendColors[3];
}

//------------------------------------------------------------------------------
// Address: 0x100C09C0
// Name: void DispInfo_LinkToParentFaces(struct model_t __near *,class ddispinfo_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispInfo_LinkToParentFaces(model_t *pWorld, const ddispinfo_t *pMapDisps, int nDisplacements)
{
  int v3; // esi
  unsigned __int16 *p_m_iMapFace; // edi
  IDispInfo *v5; // eax
  msurface2_t *v6; // edx

  v3 = 0;
  if ( nDisplacements > 0 )
  {
    p_m_iMapFace = &pMapDisps->m_iMapFace;
    do
    {
      v5 = DispInfo_IndexArray(hArray: *(_DWORD **)(pWorld->sprite.numframes + 112), iElement: v3);
      v6 = &host_state.worldbrush->surfaces2[*p_m_iMapFace];
      v6->pDispInfo = v5;
      v5->SetParent(this: v5, a2: v6);
      ++v3;
      p_m_iMapFace += 88;
    }
    while ( v3 < nDisplacements );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0A30
// Name: public: int CDispInfo::NumLightMaps(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDispInfo::NumLightMaps(CDispInfo *this)
{
  return (this->m_ParentSurfID->flags & 8) != 0 ? 4 : 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C0A50
// Name: void BuildTagData(class CCoreDispInfo __near *,class CDispInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildTagData(CCoreDispInfo *pCoreDisp, CDispInfo *pDisp)
{
  int v2; // ebx
  int i; // edi
  unsigned __int16 m_uiTags; // ax
  unsigned __int16 *v6; // eax
  int v7; // edi
  int nBuildCount; // [esp+Ch] [ebp-4h]
  int nBuildCounta; // [esp+Ch] [ebp-4h]
  int nWalkCount; // [esp+1Ch] [ebp+Ch]

  v2 = 0;
  nBuildCount = 0;
  for ( i = 0; v2 < CCoreDispInfo::GetTriCount(this: pCoreDisp); ++v2 )
  {
    m_uiTags = pCoreDisp->m_pTris[v2].m_uiTags;
    if ( (m_uiTags & 2) != 0 )
      ++nBuildCount;
    if ( (m_uiTags & 4) != 0 )
      ++i;
  }
  pDisp->m_pWalkIndices = (unsigned __int16 *)MemAlloc_Alloc(
                                                nSize: (unsigned __int64)(unsigned int)(3 * nBuildCount) >> 31 != 0
                                              ? -1
                                              : 6 * nBuildCount);
  v6 = (unsigned __int16 *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)(3 * i) >> 31 != 0 ? -1 : 6 * i);
  v7 = 0;
  pDisp->m_pBuildIndices = v6;
  nWalkCount = 0;
  nBuildCounta = 0;
  if ( CCoreDispInfo::GetTriCount(this: pCoreDisp) <= 0 )
  {
    pDisp->m_nWalkIndexCount = 0;
    pDisp->m_nBuildIndexCount = 0;
  }
  else
  {
    do
    {
      if ( (pCoreDisp->m_pTris[v7].m_uiTags & 2) != 0 )
      {
        CCoreDispInfo::GetTriIndices(
          this: pCoreDisp,
          iTri: v7,
          v1: &pDisp->m_pWalkIndices[nWalkCount],
          v2: &pDisp->m_pWalkIndices[nWalkCount + 1],
          v3: &pDisp->m_pWalkIndices[nWalkCount + 2]);
        nWalkCount += 3;
      }
      if ( (pCoreDisp->m_pTris[v7].m_uiTags & 4) != 0 )
      {
        CCoreDispInfo::GetTriIndices(
          this: pCoreDisp,
          iTri: v7,
          v1: &pDisp->m_pBuildIndices[nBuildCounta],
          v2: &pDisp->m_pBuildIndices[nBuildCounta + 1],
          v3: &pDisp->m_pBuildIndices[nBuildCounta + 2]);
        nBuildCounta += 3;
      }
      ++v7;
    }
    while ( v7 < CCoreDispInfo::GetTriCount(this: pCoreDisp) );
    pDisp->m_nWalkIndexCount = nWalkCount;
    pDisp->m_nBuildIndexCount = nBuildCounta;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0C20
// Name: BuildDispSurfInit
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildDispSurfInit(model_t *pWorld, CCoreDispInfo *pBuildDisp, msurface2_t *worldSurfID)
{
  msurface2_t *v3; // ebx
  bool v4; // zf
  int v5; // edx
  Vector2D *m_TexCoords; // ecx
  float *p_z; // eax
  int v8; // edi
  bool v9; // cc
  float *v10; // eax
  float *v11; // ecx
  unsigned int v12; // edx
  double v13; // st7
  int v14; // ecx
  int v15; // ebx
  Vector2D *v16; // edx
  float *p_x; // ecx
  double v18; // st7
  mtexinfo_t *texinfo; // eax
  unsigned int v20; // ecx
  Vector4D *v21; // eax
  int v22; // eax
  msurfacelighting_t *surfacelighting; // edx
  float y; // xmm6_4
  float x; // xmm7_4
  unsigned int v26; // ebx
  int v27; // ecx
  int v28; // edx
  float v29; // xmm0_4
  float v30; // xmm1_4
  int k; // eax
  Vector2D surfLightCoords[4][4]; // [esp+4h] [ebp-164h] BYREF
  Vector2D surfTexCoords[4]; // [esp+84h] [ebp-E4h] BYREF
  SurfaceCtx_t ctx; // [esp+A4h] [ebp-C4h] BYREF
  Vector surfPoints[4]; // [esp+C8h] [ebp-A0h] BYREF
  Vector surfNormals[4]; // [esp+F8h] [ebp-70h]
  Vector vecS; // [esp+128h] [ebp-40h] BYREF
  Vector vecT; // [esp+134h] [ebp-34h] BYREF
  Vector vec; // [esp+140h] [ebp-28h] BYREF
  int i; // [esp+14Ch] [ebp-1Ch]
  Vector2D *v41; // [esp+150h] [ebp-18h]
  int surfFlag; // [esp+154h] [ebp-14h]
  float *p_y; // [esp+158h] [ebp-10h]
  float *v44; // [esp+15Ch] [ebp-Ch]
  int j; // [esp+160h] [ebp-8h]
  int nLMVects; // [esp+164h] [ebp-4h]

  v3 = worldSurfID;
  if ( worldSurfID != nullptr && HIBYTE(worldSurfID->flags) == 4 )
  {
    BuildMSurfaceVerts(
      pBrushData: pWorld->brush.pShared,
      surfID: worldSurfID,
      verts: surfPoints,
      texCoords: surfTexCoords,
      lightCoords: surfLightCoords);
    vec.x = (float)((float)(surfPoints[3].y - surfPoints[0].y) * (float)(surfPoints[1].z - surfPoints[0].z))
          - (float)((float)(surfPoints[3].z - surfPoints[0].z) * (float)(surfPoints[1].y - surfPoints[0].y));
    vec.y = (float)((float)(surfPoints[3].z - surfPoints[0].z) * (float)(surfPoints[1].x - surfPoints[0].x))
          - (float)((float)(surfPoints[1].z - surfPoints[0].z) * (float)(surfPoints[3].x - surfPoints[0].x));
    vec.z = (float)((float)(surfPoints[1].y - surfPoints[0].y) * (float)(surfPoints[3].x - surfPoints[0].x))
          - (float)((float)(surfPoints[3].y - surfPoints[0].y) * (float)(surfPoints[1].x - surfPoints[0].x));
    VectorNormalize(&vec);
    surfFlag = pBuildDisp->m_Surf.m_Flags;
    v4 = (worldSurfID->flags & 8) == 0;
    surfNormals[0] = vec;
    surfNormals[1] = vec;
    surfNormals[2] = vec;
    surfNormals[3] = vec;
    nLMVects = 1;
    if ( !v4 )
    {
      surfFlag |= 1u;
      nLMVects = 4;
    }
    v5 = 0;
    p_y = &surfLightCoords[0][1].y;
    m_TexCoords = pBuildDisp->m_Surf.m_TexCoords;
    p_z = &pBuildDisp->m_Surf.m_Points[0].z;
    pBuildDisp->m_Surf.m_PointCount = 4;
    i = 0;
    v41 = pBuildDisp->m_Surf.m_TexCoords;
    v44 = &pBuildDisp->m_Surf.m_Points[0].z;
    v8 = 0;
    do
    {
      v9 = nLMVects < 4;
      *(p_z - 2) = surfPoints[v8].x;
      j = 0;
      *(p_z - 1) = surfPoints[v8].y;
      *p_z = surfPoints[v8].z;
      p_z[10] = surfNormals[v8].x;
      p_z[11] = surfNormals[v8].y;
      p_z[12] = surfNormals[v8].z;
      m_TexCoords->x = surfTexCoords[v5].x;
      m_TexCoords->y = surfTexCoords[v5].y;
      if ( !v9 )
      {
        v10 = p_y;
        v11 = &v41[8].y;
        v12 = ((unsigned int)(nLMVects - 4) >> 2) + 1;
        j = 4 * v12;
        do
        {
          v13 = *(v10 - 3);
          v10 += 8;
          *(v11 - 9) = v13;
          v11 += 32;
          --v12;
          *(v11 - 40) = *(v10 - 10);
          *(v11 - 33) = *(v10 - 9);
          *(v11 - 32) = *(v10 - 8);
          *(v11 - 25) = *(v10 - 7);
          *(v11 - 24) = *(v10 - 6);
          *(v11 - 17) = *(v10 - 5);
          *(v11 - 16) = *(v10 - 4);
        }
        while ( v12 != 0 );
        p_z = v44;
        v5 = i;
        v3 = worldSurfID;
      }
      if ( j < nLMVects )
      {
        v14 = j + 4 * v5;
        v15 = nLMVects - j;
        v16 = &pBuildDisp->m_Surf.m_LuxelCoords[j][v5];
        p_x = &surfLightCoords[0][v14].x;
        v44 = &v16->x;
        do
        {
          v18 = *p_x;
          p_x += 2;
          v16->x = v18;
          v16 += 4;
          --v15;
          v16[-4].y = *(p_x - 1);
        }
        while ( v15 != 0 );
        v5 = i;
        v3 = worldSurfID;
      }
      p_y += 8;
      ++v5;
      ++v8;
      p_z += 3;
      m_TexCoords = v41 + 1;
      i = v5;
      v44 = p_z;
      ++v41;
    }
    while ( v8 < 4 );
    texinfo = host_state.worldbrush->texinfo;
    v20 = *((unsigned __int16 *)v3 + 11) >> 1;
    vecS.x = texinfo[*((unsigned __int16 *)v3 + 11) >> 1].textureVecsTexelsPerWorldUnits[0].x;
    vecS.y = texinfo[v20].textureVecsTexelsPerWorldUnits[0].y;
    vecS.z = texinfo[v20].textureVecsTexelsPerWorldUnits[0].z;
    v21 = &host_state.worldbrush->texinfo[v20].textureVecsTexelsPerWorldUnits[1];
    vecT.x = v21->x;
    vecT.y = v21->y;
    vecT.z = v21->z;
    VectorNormalize(vec: &vecS);
    VectorNormalize(vec: &vecT);
    v22 = surfFlag;
    pBuildDisp->m_Surf.sAxis = vecS;
    pBuildDisp->m_Surf.tAxis = vecT;
    pBuildDisp->m_Surf.m_Flags = v22;
    CCoreDispSurface::FindSurfPointStartIndex(this: &pBuildDisp->m_Surf);
    CCoreDispSurface::AdjustSurfPointData(this: &pBuildDisp->m_Surf);
    SurfSetupSurfaceContext(&ctx, surfID: v3);
    surfacelighting = host_state.worldbrush->surfacelighting;
    y = ctx.m_Scale.y;
    x = ctx.m_Scale.x;
    v26 = ((char *)v3 - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0;
    v27 = *(__int16 *)((char *)surfacelighting->m_LightmapExtents + v26);
    v28 = *(__int16 *)((char *)&surfacelighting->m_LightmapExtents[1] + v26);
    v29 = 0.0;
    v30 = 0.0;
    for ( k = 0; k < 4; ++k )
    {
      switch ( k )
      {
        case 0:
          v29 = 0.0;
          goto LABEL_21;
        case 1:
          v29 = 0.0;
          v30 = (float)v28;
          break;
        case 2:
          v29 = (float)v27;
          v30 = (float)v28;
          break;
        case 3:
          v29 = (float)v27;
LABEL_21:
          v30 = 0.0;
          break;
        default:
          break;
      }
      v29 = ctx.m_Offset.x + (float)(x * (float)(v29 + 0.5));
      v30 = ctx.m_Offset.y + (float)(y * (float)(v30 + 0.5));
      pBuildDisp->m_Surf.m_LuxelCoords[0][k].x = v29;
      pBuildDisp->m_Surf.m_LuxelCoords[0][k].y = v30;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C1070
// Name: void FillStaticBuffer(class CGroupMesh __near *,class CDispInfo __near *,class CCoreDispInfo const __near *,class CDispVert const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FillStaticBuffer(
        CGroupMesh *pMesh,
        CDispInfo *pDisp,
        CCoreDispInfo *pCoreDisp,
        const CDispVert *pVerts,
        int nLightmaps)
{
  int Power; // eax
  int v6; // ebx
  msurface2_t *v7; // eax
  int v8; // edi
  CoreDispVert_t *m_pVerts; // ecx
  float y; // xmm0_4
  double x; // st7
  float z; // xmm1_4
  float *m_pCurrPosition; // ecx
  CoreDispVert_t *v14; // edx
  float v15; // xmm0_4
  float v16; // xmm1_4
  float *m_pCurrNormal; // ecx
  CoreDispVert_t *v18; // eax
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float *v22; // eax
  CoreDispVert_t *v23; // ecx
  float v24; // xmm1_4
  float v25; // xmm2_4
  float *v26; // eax
  CoreDispVert_t *v27; // edx
  float v28; // xmm1_4
  float *v29; // eax
  float *v30; // eax
  float *v31; // eax
  float *v32; // eax
  float *v33; // eax
  float v34; // xmm0_4
  int v35; // xmm1_4
  msurface2_t *v36; // eax
  float *v37; // eax
  CDispRenderVert *v38; // [esp-Ch] [ebp-294h]
  CMeshBuilder builder; // [esp+8h] [ebp-280h] BYREF
  SurfaceCtx_t ctx; // [esp+1F0h] [ebp-98h] BYREF
  int nIndices; // [esp+214h] [ebp-74h] BYREF
  Vector4D vMultiBlend; // [esp+218h] [ebp-70h] BYREF
  Vector4D vAlphaBlend; // [esp+228h] [ebp-60h] BYREF
  Vector vMultiBlendColor[4]; // [esp+238h] [ebp-50h] BYREF
  Vector2D lightCoord; // [esp+268h] [ebp-20h] BYREF
  int v46; // [esp+270h] [ebp-18h]
  int v47; // [esp+274h] [ebp-14h]
  float v48; // [esp+278h] [ebp-10h]
  int v49; // [esp+27Ch] [ebp-Ch]
  int nVerts; // [esp+280h] [ebp-8h] BYREF
  unsigned int v51; // [esp+284h] [ebp-4h]

  Power = CDispUtilsHelper::GetPower(this: &pDisp->CDispUtilsHelper);
  CalcMaxNumVertsAndIndices(power: Power, &nVerts, &nIndices);
  CMeshBuilder::CMeshBuilder(this: &builder);
  v6 = 0;
  CMeshBuilder::BeginModify(
    this: &builder,
    pMesh: pMesh->m_pMesh,
    nFirstVertex: pDisp->m_iVertOffset,
    nVertexCount: nVerts,
    nFirstIndex: 0,
    nIndexCount: 0);
  v7 = pDisp->GetParent(this: pDisp);
  SurfSetupSurfaceContext(&ctx, surfID: v7);
  if ( nVerts > 0 )
  {
    v51 = 0;
    v8 = 0;
    do
    {
      m_pVerts = pCoreDisp->m_pVerts;
      y = m_pVerts[v8].m_Vert.y;
      x = m_pVerts[v8].m_Vert.x;
      z = m_pVerts[v8].m_Vert.z;
      m_pCurrPosition = builder.m_VertexBuilder.m_pCurrPosition;
      *builder.m_VertexBuilder.m_pCurrPosition = x;
      m_pCurrPosition[1] = y;
      m_pCurrPosition[2] = z;
      v14 = pCoreDisp->m_pVerts;
      v15 = v14[v8].m_Normal.y;
      v16 = v14[v8].m_Normal.z;
      m_pCurrNormal = builder.m_VertexBuilder.m_pCurrNormal;
      *builder.m_VertexBuilder.m_pCurrNormal = v14[v8].m_Normal.x;
      m_pCurrNormal[1] = v15;
      m_pCurrNormal[2] = v16;
      v18 = pCoreDisp->m_pVerts;
      v19 = v18[v8].m_TangentS.x;
      v20 = v18[v8].m_TangentS.y;
      v21 = v18[v8].m_TangentS.z;
      v22 = (float *)((char *)builder.m_VertexBuilder.m_pTangentS
                    + builder.m_VertexBuilder.m_nCurrentVertex * builder.m_VertexBuilder.m_VertexSize_TangentS);
      *v22 = v19;
      v22[1] = v20;
      v22[2] = v21;
      v23 = pCoreDisp->m_pVerts;
      v24 = v23[v8].m_TangentT.y;
      v25 = v23[v8].m_TangentT.z;
      v26 = (float *)((char *)builder.m_VertexBuilder.m_pTangentT
                    + builder.m_VertexBuilder.m_nCurrentVertex * builder.m_VertexBuilder.m_VertexSize_TangentT);
      *v26 = v23[v8].m_TangentT.x;
      v26[1] = v24;
      v26[2] = v25;
      v27 = pCoreDisp->m_pVerts;
      v28 = v27[v8].m_TexCoord.y;
      v29 = builder.m_VertexBuilder.m_pCurrTexCoord[0];
      *builder.m_VertexBuilder.m_pCurrTexCoord[0] = v27[v8].m_TexCoord.x;
      v29[1] = v28;
      lightCoord = pCoreDisp->m_pVerts[v8].m_LuxelCoords[0];
      *(Vector2D *)builder.m_VertexBuilder.m_pCurrTexCoord[1] = lightCoord;
      if ( (pCoreDisp->m_nFlags & 0x40000000) != 0 )
      {
        CCoreDispInfo::GetMultiBlend(
          this: pCoreDisp,
          index: v6,
          vBlend: &vMultiBlend,
          &vAlphaBlend,
          vColor1: vMultiBlendColor,
          vColor2: &vMultiBlendColor[1],
          vColor3: &vMultiBlendColor[2],
          vColor4: &vMultiBlendColor[3]);
        *(Vector4D *)builder.m_VertexBuilder.m_pCurrTexCoord[3] = vAlphaBlend;
        v30 = builder.m_VertexBuilder.m_pCurrTexCoord[4];
        *(Vector *)builder.m_VertexBuilder.m_pCurrTexCoord[4] = vMultiBlendColor[0];
        v30[3] = vMultiBlend.x;
        v31 = builder.m_VertexBuilder.m_pCurrTexCoord[5];
        *(Vector *)builder.m_VertexBuilder.m_pCurrTexCoord[5] = vMultiBlendColor[1];
        v31[3] = vMultiBlend.y;
        v32 = builder.m_VertexBuilder.m_pCurrTexCoord[6];
        *(Vector *)builder.m_VertexBuilder.m_pCurrTexCoord[6] = vMultiBlendColor[2];
        v32[3] = vMultiBlend.z;
        v33 = builder.m_VertexBuilder.m_pCurrTexCoord[7];
        *(Vector *)builder.m_VertexBuilder.m_pCurrTexCoord[7] = vMultiBlendColor[3];
        v33[3] = vMultiBlend.w;
      }
      v34 = pCoreDisp->m_pVerts[v8].m_Alpha * 0.0039215689;
      *(float *)&v35 = 0.0;
      if ( v34 < 0.0 || (*(float *)&v35 = 1.0, v34 > 1.0) )
        v34 = *(float *)&v35;
      v46 = 1258291455;
      v49 = 1258291455;
      v47 = 1258291455;
      v48 = (float)(v34 * 255.0) + 8388608.0;
      *(_DWORD *)builder.m_VertexBuilder.m_pCurrColor = (((((LOBYTE(v48) << 8) | 0xFF) << 8) | 0xFF) << 8) | 0xFF;
      if ( nLightmaps > 1 )
      {
        v38 = &pDisp->m_Verts.m_Memory.m_pMemory[v51 / 0x40];
        v36 = pDisp->GetParent(this: pDisp);
        SurfComputeLightmapCoordinate(&ctx, surfID: v36, vec: &v38->m_vPos, uv: &lightCoord);
        v37 = builder.m_VertexBuilder.m_pCurrTexCoord[2];
        *builder.m_VertexBuilder.m_pCurrTexCoord[2] = ctx.m_BumpSTexCoordOffset;
        v37[1] = 0.0;
      }
      CVertexBuilder::AdvanceVertex(this: &builder.m_VertexBuilder);
      v51 += 64;
      ++v6;
      ++v8;
    }
    while ( v6 < nVerts );
  }
  builder.m_pMesh->ModifyEnd(this: builder.m_pMesh, a2: &builder);
}

//------------------------------------------------------------------------------
// Address: 0x100C1440
// Name: void SetupMeshReaders(struct model_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupMeshReaders(model_t *pWorld, int nDisplacements)
{
  IDispInfo *v2; // esi
  float *v3; // eax
  float *v4; // ecx
  unsigned __int16 *v5; // edx
  IDispInfo_vtbl *v6; // eax
  IDispInfo_vtbl *v7; // ecx
  IDispInfo_vtbl *ComputeShadowFragments; // edx
  IDispInfo_vtbl *v9; // edx
  bool v10; // zf
  MeshDesc_t desc; // [esp+0h] [ebp-BCh] BYREF
  IDispInfo_vtbl *v12; // [esp+B4h] [ebp-8h]
  int iDisp; // [esp+B8h] [ebp-4h]

  for ( iDisp = 0; iDisp < nDisplacements; ++iDisp )
  {
    v2 = DispInfo_IndexArray(hArray: *(_DWORD **)(pWorld->sprite.numframes + 112), iElement: iDisp);
    memset(dst: (unsigned __int8 *)&desc, value: 0, count: sizeof(desc));
    v3 = (float *)v2[66].__vftable;
    desc.m_pTexCoord[0] = v3 + 12;
    desc.m_pTexCoord[1] = v3 + 14;
    v4 = v3 + 6;
    desc.m_pPosition = v3;
    desc.m_pNormal = v3 + 3;
    v5 = (unsigned __int16 *)v2[61].__vftable;
    desc.m_pTangentT = v3 + 9;
    v6 = v2[119].__vftable;
    desc.m_pTangentS = v4;
    v7 = v2[8].__vftable;
    desc.m_pIndices = v5;
    ComputeShadowFragments = (IDispInfo_vtbl *)v6->ComputeShadowFragments;
    v12 = v7;
    v2[59].__vftable = ComputeShadowFragments;
    v9 = v12;
    v10 = desc.m_CompressionType == VERTEX_COMPRESSION_NONE;
    desc.m_VertexSize_Position = 64;
    desc.m_VertexSize_TexCoord[0] = 64;
    desc.m_VertexSize_TexCoord[1] = 64;
    desc.m_VertexSize_Normal = 64;
    desc.m_VertexSize_TangentS = 64;
    desc.m_VertexSize_TangentT = 64;
    desc.m_nIndexSize = 1;
    *(MeshDesc_t *)&v2[13].__vftable = desc;
    v2[60].__vftable = v9;
    if ( !v10 )
      _Warning(a1: "Cannot use CBaseMeshReader with compressed vertices!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C1630
// Name: public: CBitVec<289>::CBitVec<289>(void)
// Source: json
//------------------------------------------------------------------------------
CBitVec<289> *__thiscall CBitVec<289>::CBitVec<289>(CBitVec<289> *this)
{
  CBitVec<289> *result; // eax

  result = this;
  if ( this != nullptr )
  {
    this->m_Ints[0] = 0;
    this->m_Ints[1] = 0;
    this->m_Ints[2] = 0;
    this->m_Ints[3] = 0;
    this->m_Ints[4] = 0;
    this->m_Ints[5] = 0;
    this->m_Ints[6] = 0;
    this->m_Ints[7] = 0;
    this->m_Ints[8] = 0;
    this->m_Ints[9] = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C16D0
// Name: public: CDispInfo::CDispInfo(void)
// Source: json
//------------------------------------------------------------------------------
CDispInfo *__thiscall CDispInfo::CDispInfo(CDispInfo *this)
{
  CDispInfo *result; // eax

  result = this;
  this->CDispUtilsHelper::__vftable = (CDispUtilsHelper_vtbl *)&CDispUtilsHelper::`vftable';
  this->IDispInfo::__vftable = (CDispInfo_vtbl *)&CDispInfo::`vftable'{for `IDispInfo'};
  this->CDispUtilsHelper::__vftable = (CDispUtilsHelper_vtbl *)&CDispInfo::`vftable'{for `CDispUtilsHelper'};
  this->m_MeshReader.m_pMesh = nullptr;
  this->m_Indices.m_Memory.m_pMemory = nullptr;
  this->m_Indices.m_Memory.m_nAllocationCount = 0;
  this->m_Indices.m_Memory.m_nGrowSize = 0;
  this->m_Indices.m_Size = 0;
  this->m_Indices.m_pElements = nullptr;
  this->m_Verts.m_Memory.m_pMemory = nullptr;
  this->m_Verts.m_Memory.m_nAllocated = 0;
  this->m_Verts.m_Size = 0;
  this->m_Verts.m_pElements = nullptr;
  if ( this != (CDispInfo *)-280 )
  {
    this->m_ActiveVerts.m_Ints[0] = 0;
    this->m_ActiveVerts.m_Ints[1] = 0;
    this->m_ActiveVerts.m_Ints[2] = 0;
    this->m_ActiveVerts.m_Ints[3] = 0;
    this->m_ActiveVerts.m_Ints[4] = 0;
    this->m_ActiveVerts.m_Ints[5] = 0;
    this->m_ActiveVerts.m_Ints[6] = 0;
    this->m_ActiveVerts.m_Ints[7] = 0;
    this->m_ActiveVerts.m_Ints[8] = 0;
    this->m_ActiveVerts.m_Ints[9] = 0;
  }
  if ( this != (CDispInfo *)-320 )
  {
    this->m_AllowedVerts.m_Ints[0] = 0;
    this->m_AllowedVerts.m_Ints[1] = 0;
    this->m_AllowedVerts.m_Ints[2] = 0;
    this->m_AllowedVerts.m_Ints[3] = 0;
    this->m_AllowedVerts.m_Ints[4] = 0;
    this->m_AllowedVerts.m_Ints[5] = 0;
    this->m_AllowedVerts.m_Ints[6] = 0;
    this->m_AllowedVerts.m_Ints[7] = 0;
    this->m_AllowedVerts.m_Ints[8] = 0;
    this->m_AllowedVerts.m_Ints[9] = 0;
  }
  this->m_ParentSurfID = nullptr;
  this->m_bTouched = false;
  ++g_ConstructorChecker.m_nConstructedObjects;
  this->m_BBoxMin.x = 0.0;
  this->m_BBoxMin.y = 0.0;
  this->m_BBoxMin.z = 0.0;
  this->m_BBoxMax.x = 0.0;
  this->m_BBoxMax.y = 0.0;
  this->m_BBoxMax.z = 0.0;
  this->m_idLMPage = -1;
  this->m_pPowerInfo = nullptr;
  this->m_ViewerSphereCenter.x = 1.0e24;
  this->m_ViewerSphereCenter.y = 1.0e24;
  this->m_ViewerSphereCenter.z = 1.0e24;
  this->m_bInUse = false;
  this->m_pNodeInfo = nullptr;
  this->m_pMesh = nullptr;
  this->m_pDispArray = nullptr;
  this->m_Tag = 0;
  this->m_FirstDecal = -1;
  this->m_FirstShadowDecal = -1;
  this->m_EdgeNeighbors[0].m_SubNeighbors[0].m_iNeighbor = -1;
  this->m_EdgeNeighbors[0].m_SubNeighbors[1].m_iNeighbor = -1;
  this->m_CornerNeighbors[0].m_nNeighbors = 0;
  this->m_EdgeNeighbors[1].m_SubNeighbors[0].m_iNeighbor = -1;
  this->m_EdgeNeighbors[1].m_SubNeighbors[1].m_iNeighbor = -1;
  this->m_CornerNeighbors[1].m_nNeighbors = 0;
  this->m_EdgeNeighbors[2].m_SubNeighbors[0].m_iNeighbor = -1;
  this->m_EdgeNeighbors[2].m_SubNeighbors[1].m_iNeighbor = -1;
  this->m_CornerNeighbors[2].m_nNeighbors = 0;
  this->m_EdgeNeighbors[3].m_SubNeighbors[0].m_iNeighbor = -1;
  this->m_EdgeNeighbors[3].m_SubNeighbors[1].m_iNeighbor = -1;
  this->m_CornerNeighbors[3].m_nNeighbors = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C1860
// Name: public: virtual CDispInfo::~CDispInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::~CDispInfo(CDispInfo *this)
{
  DispNodeInfo_t *m_pNodeInfo; // eax
  CDispRenderVert *m_pMemory; // edx

  m_pNodeInfo = this->m_pNodeInfo;
  this->IDispInfo::__vftable = (CDispInfo_vtbl *)&CDispInfo::`vftable'{for `IDispInfo'};
  this->CDispUtilsHelper::__vftable = (CDispUtilsHelper_vtbl *)&CDispInfo::`vftable'{for `CDispUtilsHelper'};
  if ( m_pNodeInfo != nullptr )
    free(pMem: m_pNodeInfo);
  free(pMem: this->m_pWalkIndices);
  free(pMem: this->m_pBuildIndices);
  --g_ConstructorChecker.m_nConstructedObjects;
  m_pMemory = this->m_Verts.m_Memory.m_pMemory;
  this->m_Verts.m_Size = 0;
  this->m_Verts.m_Memory.m_nAllocated = 0;
  this->m_Verts.m_pElements = m_pMemory;
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Indices);
  this->IDispInfo::__vftable = (CDispInfo_vtbl *)&IDispInfo::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100C18E0
// Name: AddCombo
// Source: json
//------------------------------------------------------------------------------
CDispGroup *__usercall AddCombo@<eax>(CUtlMemory<S3RGBA,int> *combos@<esi>, int idLMPage, IMaterial *pMaterial)
{
  CDispGroup *v3; // eax
  CDispGroup *v4; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDispGroup **v7; // ecx
  int v8; // eax
  CDispGroup **v9; // edi
  CDispGroup *result; // eax

  v3 = (CDispGroup *)MemAlloc_Alloc(nSize: 0x34u);
  if ( v3 != nullptr )
  {
    v3->m_Meshes.m_Memory.m_pMemory = nullptr;
    v3->m_Meshes.m_Memory.m_nAllocationCount = 0;
    v3->m_Meshes.m_Memory.m_nGrowSize = 0;
    v3->m_Meshes.m_Size = 0;
    v3->m_Meshes.m_pElements = nullptr;
    v3->m_DispInfos.m_Memory.m_pMemory = nullptr;
    v3->m_DispInfos.m_Memory.m_nAllocationCount = 0;
    v3->m_DispInfos.m_Memory.m_nGrowSize = 0;
    v3->m_DispInfos.m_Size = 0;
    v3->m_DispInfos.m_pElements = nullptr;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  v4->m_pMaterial = pMaterial;
  v4->m_LightmapPageID = idLMPage;
  v4->m_nVisible = 0;
  m_pMemory = (int)combos[1].m_pMemory;
  m_nAllocationCount = combos->m_nAllocationCount;
  if ( m_pMemory + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow(this: combos, num: m_pMemory - m_nAllocationCount + 1);
  ++combos[1].m_pMemory;
  v7 = (CDispGroup **)combos->m_pMemory;
  v8 = (int)combos[1].m_pMemory - m_pMemory - 1;
  combos[1].m_nAllocationCount = (int)combos->m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &v7[m_pMemory + 1], src: &v7[m_pMemory], count: 4 * v8);
  v9 = (CDispGroup **)&combos->m_pMemory[m_pMemory];
  result = v4;
  if ( v9 != nullptr )
    *v9 = v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C1980
// Name: public: void CDispInfo::CopyMapDispData(class ddispinfo_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::CopyMapDispData(CDispInfo *this, const ddispinfo_t *pBuildDisp)
{
  const CPowerInfo *PowerInfo; // eax
  int power; // [esp-4h] [ebp-8h]
  int v5; // [esp-4h] [ebp-8h]

  this->m_iLightmapAlphaStart = pBuildDisp->m_iLightmapAlphaStart;
  power = pBuildDisp->power;
  this->m_Power = power;
  PowerInfo = GetPowerInfo(iPower: power);
  this->m_pPowerInfo = PowerInfo;
  v5 = (PowerInfo->m_SideLength - 1) * (6 * PowerInfo->m_SideLength - 6);
  this->m_Indices.m_Size = 0;
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
    this: (CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *)&this->m_Indices,
    elem: 0,
    num: v5);
  if ( this->m_pNodeInfo != nullptr )
    free(pMem: this->m_pNodeInfo);
  this->m_pNodeInfo = (DispNodeInfo_t *)MemAlloc_Alloc(
                                          nSize: (28 * (unsigned __int64)(unsigned int)this->m_pPowerInfo->m_NodeCount) >> 32 != 0
                                        ? -1
                                        : 28 * this->m_pPowerInfo->m_NodeCount);
}

//------------------------------------------------------------------------------
// Address: 0x100C1A10
// Name: void DispInfo_CreateMaterialGroups(struct model_t __near *,struct MaterialSystem_SortInfo_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispInfo_CreateMaterialGroups(model_t *pWorld, const MaterialSystem_SortInfo_t *pSortInfos)
{
  worldbrushdata_t *pShared; // eax
  int v3; // ecx
  IDispInfo_vtbl *v4; // edx
  int lightmapPageID; // edi
  int v6; // ecx
  CDispGroup *v7; // esi
  CDispGroup *v8; // eax
  int m_Size; // edi
  CUtlMemory<S3RGBA,int> *p_m_DispInfos; // esi
  int m_nAllocationCount; // eax
  S3RGBA *m_pMemory; // ecx
  int v13; // eax
  int *v14; // edi
  int iDisp; // [esp+0h] [ebp-4h]

  pShared = pWorld->brush.pShared;
  v3 = 0;
  for ( iDisp = 0; v3 < pShared->numDispInfos; iDisp = v3 )
  {
    v4 = DispInfo_IndexArray(hArray: (_DWORD *)pShared->hDispInfos, iElement: v3)[91].__vftable;
    lightmapPageID = pSortInfos[SHIWORD(v4->SetParent)].lightmapPageID;
    v6 = 0;
    if ( g_DispGroups.m_Size <= 0 )
      goto LABEL_8;
    while ( 1 )
    {
      v7 = g_DispGroups.m_Memory.m_pMemory[v6];
      if ( v7->m_LightmapPageID == lightmapPageID
        && v7->m_pMaterial == host_state.worldbrush->texinfo[HIWORD(v4->GetParent) >> 1].material )
      {
        break;
      }
      if ( ++v6 >= g_DispGroups.m_Size )
        goto LABEL_8;
    }
    v8 = g_DispGroups.m_Memory.m_pMemory[v6];
    if ( v8 == nullptr )
LABEL_8:
      v8 = AddCombo(
             combos: (CUtlMemory<S3RGBA,int> *)&g_DispGroups,
             idLMPage: lightmapPageID,
             pMaterial: host_state.worldbrush->texinfo[HIWORD(v4->GetParent) >> 1].material);
    m_Size = v8->m_DispInfos.m_Size;
    p_m_DispInfos = (CUtlMemory<S3RGBA,int> *)&v8->m_DispInfos;
    m_nAllocationCount = v8->m_DispInfos.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(this: p_m_DispInfos, num: m_Size - m_nAllocationCount + 1);
    ++p_m_DispInfos[1].m_pMemory;
    m_pMemory = p_m_DispInfos->m_pMemory;
    v13 = (int)p_m_DispInfos[1].m_pMemory - m_Size - 1;
    p_m_DispInfos[1].m_nAllocationCount = (int)p_m_DispInfos->m_pMemory;
    if ( v13 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v13);
    v14 = (int *)&p_m_DispInfos->m_pMemory[m_Size];
    if ( v14 != nullptr )
      *v14 = iDisp;
    pShared = pWorld->brush.pShared;
    v3 = iDisp + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C1B40
// Name: public: void CDispInfo::CopyCoreDispVertData(class CCoreDispInfo const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispInfo::CopyCoreDispVertData(
        CDispInfo *this,
        const CCoreDispInfo *pCoreDisp,
        float bumpSTexCoordOffset)
{
  int v4; // eax
  int m_MaxVerts; // edi
  const CPowerInfo *m_pPowerInfo; // ecx
  int v7; // edi
  int v8; // ecx
  float *p_z; // eax
  CDispRenderVert *m_pMemory; // edx
  double v11; // st7
  Vector2D *p_m_vTexCoord; // edx
  Vector2D *p_m_LMCoords; // edx
  Vector *p_m_vNormal; // edx
  Vector *p_m_vSVector; // edx
  Vector *p_m_vTVector; // edx
  int v17; // eax

  if ( ((this->m_ParentSurfID->flags & 8) != 0 ? 4 : 1) <= 1u )
    bumpSTexCoordOffset = 0.0;
  v4 = CHunkAllocCredit::s_DbgInfoStackDepth + 1;
  CHunkAllocCredit::s_DbgInfoStackDepth = v4;
  if ( v4 < 8 )
    CHunkAllocCredit::s_DbgInfoStack[v4] = "CopyCoreDispVertData";
  m_MaxVerts = this->m_pPowerInfo->m_MaxVerts;
  this->m_Verts.m_Size = 0;
  if ( m_MaxVerts != 0 )
  {
    CUtlVector<CDispRenderVert,CHunkMemory<CDispRenderVert>>::GrowVector(this: &this->m_Verts, num: m_MaxVerts);
    if ( this->m_Verts.m_Size - m_MaxVerts > 0 && m_MaxVerts > 0 )
      _V_memmove(
        dest: &this->m_Verts.m_Memory.m_pMemory[m_MaxVerts],
        src: this->m_Verts.m_Memory.m_pMemory,
        count: (this->m_Verts.m_Size - m_MaxVerts) << 6);
  }
  m_pPowerInfo = this->m_pPowerInfo;
  v7 = 0;
  this->m_BumpSTexCoordOffset = bumpSTexCoordOffset;
  if ( m_pPowerInfo->m_MaxVerts > 0 )
  {
    v8 = 0;
    p_z = &pCoreDisp->m_pVerts->m_Vert.z;
    do
    {
      m_pMemory = this->m_Verts.m_Memory.m_pMemory;
      m_pMemory[v8].m_vPos.x = *(p_z - 2);
      ++v7;
      v11 = *(p_z - 1);
      p_z += 56;
      m_pMemory[v8].m_vPos.y = v11;
      m_pMemory[v8].m_vPos.z = *(p_z - 56);
      p_m_vTexCoord = &this->m_Verts.m_Memory.m_pMemory[v8].m_vTexCoord;
      p_m_vTexCoord->x = *(p_z - 43);
      p_m_vTexCoord->y = *(p_z - 42);
      p_m_LMCoords = &this->m_Verts.m_Memory.m_pMemory[v8].m_LMCoords;
      p_m_LMCoords->x = *(p_z - 41);
      p_m_LMCoords->y = *(p_z - 40);
      p_m_vNormal = &this->m_Verts.m_Memory.m_pMemory[v8].m_vNormal;
      p_m_vNormal->x = *(p_z - 52);
      p_m_vNormal->y = *(p_z - 51);
      p_m_vNormal->z = *(p_z - 50);
      p_m_vSVector = &this->m_Verts.m_Memory.m_pMemory[v8].m_vSVector;
      p_m_vSVector->x = *(p_z - 49);
      p_m_vSVector->y = *(p_z - 48);
      p_m_vSVector->z = *(p_z - 47);
      p_m_vTVector = &this->m_Verts.m_Memory.m_pMemory[v8].m_vTVector;
      p_m_vTVector->x = *(p_z - 46);
      ++v8;
      p_m_vTVector->y = *(p_z - 45);
      p_m_vTVector->z = *(p_z - 44);
    }
    while ( v7 < this->m_pPowerInfo->m_MaxVerts );
  }
  v17 = CHunkAllocCredit::s_DbgInfoStackDepth;
  if ( CHunkAllocCredit::s_DbgInfoStackDepth >= 0 )
  {
    CHunkAllocCredit::s_DbgInfoStack[CHunkAllocCredit::s_DbgInfoStackDepth] = nullptr;
    CHunkAllocCredit::s_DbgInfoStackDepth = v17 - 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C1D00
// Name: public: bool CDispInfo::CopyCoreDispData(struct model_t __near *,struct MaterialSystem_SortInfo_t const __near *,class CCoreDispInfo const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispInfo::CopyCoreDispData(
        CDispInfo *this,
        model_t *pWorld,
        const MaterialSystem_SortInfo_t *pSortInfos,
        const CCoreDispInfo *pCoreDisp,
        bool bRestoring)
{
  int lightmapPageID; // edx
  CDispInfo_vtbl *v7; // eax
  msurface2_t *v8; // eax
  float m_BumpSTexCoordOffset; // xmm0_4
  const CPowerInfo *m_pPowerInfo; // ecx
  int v11; // edi
  int v12; // edx
  Vector2D *m_LuxelCoords; // eax
  Vector2D *p_m_LMCoords; // ecx
  SurfaceCtx_t ctx; // [esp+Ch] [ebp-24h] BYREF

  lightmapPageID = pSortInfos[this->GetParent(this)->materialSortID].lightmapPageID;
  v7 = this->IDispInfo::__vftable;
  this->m_idLMPage = lightmapPageID;
  v8 = v7->GetParent(this);
  SurfSetupSurfaceContext(&ctx, surfID: v8);
  if ( !bRestoring )
  {
    this->m_BaseSurfaceTexCoords[0].x = pCoreDisp->m_Surf.m_TexCoords[0].x;
    this->m_BaseSurfaceTexCoords[0].y = pCoreDisp->m_Surf.m_TexCoords[0].y;
    this->m_BaseSurfacePositions[0].x = pCoreDisp->m_Surf.m_Points[0].x;
    this->m_BaseSurfacePositions[0].y = pCoreDisp->m_Surf.m_Points[0].y;
    this->m_BaseSurfacePositions[0].z = pCoreDisp->m_Surf.m_Points[0].z;
    this->m_BaseSurfaceTexCoords[1] = pCoreDisp->m_Surf.m_TexCoords[1];
    this->m_BaseSurfacePositions[1] = pCoreDisp->m_Surf.m_Points[1];
    this->m_BaseSurfaceTexCoords[2] = pCoreDisp->m_Surf.m_TexCoords[2];
    this->m_BaseSurfacePositions[2] = pCoreDisp->m_Surf.m_Points[2];
    this->m_BaseSurfaceTexCoords[3] = pCoreDisp->m_Surf.m_TexCoords[3];
    this->m_BaseSurfacePositions[3] = pCoreDisp->m_Surf.m_Points[3];
    CDispInfo::CopyCoreDispVertData(this, pCoreDisp, bumpSTexCoordOffset: ctx.m_BumpSTexCoordOffset);
    *(_DWORD *)&this->m_EdgeNeighbors[0].m_SubNeighbors[0].m_iNeighbor = *(_DWORD *)&pCoreDisp->m_Surf.m_EdgeNeighbors[0].m_SubNeighbors[0].m_iNeighbor;
    *(_DWORD *)&this->m_EdgeNeighbors[0].m_SubNeighbors[0].m_NeighborSpan = *(_DWORD *)&pCoreDisp->m_Surf.m_EdgeNeighbors[0].m_SubNeighbors[0].m_NeighborSpan;
    *(_DWORD *)&this->m_EdgeNeighbors[0].m_SubNeighbors[1].m_NeighborOrientation = *(_DWORD *)&pCoreDisp->m_Surf.m_EdgeNeighbors[0].m_SubNeighbors[1].m_NeighborOrientation;
    *(_DWORD *)this->m_CornerNeighbors[0].m_Neighbors = *(_DWORD *)pCoreDisp->m_Surf.m_CornerNeighbors[0].m_Neighbors;
    *(_DWORD *)&this->m_CornerNeighbors[0].m_Neighbors[2] = *(_DWORD *)&pCoreDisp->m_Surf.m_CornerNeighbors[0].m_Neighbors[2];
    *(_WORD *)&this->m_CornerNeighbors[0].m_nNeighbors = *(_WORD *)&pCoreDisp->m_Surf.m_CornerNeighbors[0].m_nNeighbors;
    this->m_EdgeNeighbors[1] = pCoreDisp->m_Surf.m_EdgeNeighbors[1];
    this->m_CornerNeighbors[1] = pCoreDisp->m_Surf.m_CornerNeighbors[1];
    this->m_EdgeNeighbors[2] = pCoreDisp->m_Surf.m_EdgeNeighbors[2];
    this->m_CornerNeighbors[2] = pCoreDisp->m_Surf.m_CornerNeighbors[2];
    this->m_EdgeNeighbors[3] = pCoreDisp->m_Surf.m_EdgeNeighbors[3];
    this->m_CornerNeighbors[3] = pCoreDisp->m_Surf.m_CornerNeighbors[3];
    memcpy(
      dst: (unsigned __int8 *)&this->m_AllowedVerts,
      src: (unsigned __int8 *)&pCoreDisp->m_AllowedVerts,
      count: sizeof(this->m_AllowedVerts));
    this->m_nIndices = 0;
    return 1;
  }
  if ( ((this->m_ParentSurfID->flags & 8) != 0 ? 4 : 1) <= 1u )
    m_BumpSTexCoordOffset = 0.0;
  else
    m_BumpSTexCoordOffset = ctx.m_BumpSTexCoordOffset;
  m_pPowerInfo = this->m_pPowerInfo;
  v11 = 0;
  this->m_BumpSTexCoordOffset = m_BumpSTexCoordOffset;
  if ( m_pPowerInfo->m_MaxVerts <= 0 )
    return 1;
  v12 = 0;
  m_LuxelCoords = pCoreDisp->m_pVerts->m_LuxelCoords;
  do
  {
    p_m_LMCoords = &this->m_Verts.m_Memory.m_pMemory[v12].m_LMCoords;
    p_m_LMCoords->x = m_LuxelCoords->x;
    ++v11;
    ++v12;
    p_m_LMCoords->y = m_LuxelCoords->y;
    m_LuxelCoords += 28;
  }
  while ( v11 < this->m_pPowerInfo->m_MaxVerts );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C2270
// Name: void AddEmptyMesh(struct model_t __near *,class CDispGroup __near *,class ddispinfo_t const __near *,int __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall AddEmptyMesh(
        int a1@<edi>,
        model_t *pWorld,
        CDispGroup *pCombo,
        const ddispinfo_t *pMapDisps,
        int *pDispInfos,
        int nDisps,
        int nTotalVerts,
        int nTotalIndices)
{
  IMatRenderContext *v8; // eax
  int v9; // ebx
  CGroupMesh *v10; // eax
  CGroupMesh *v11; // edi
  int v12; // ecx
  int m_nAllocationCount; // eax
  CGroupMesh **m_pMemory; // edx
  int v15; // eax
  CGroupMesh **v16; // ecx
  __int64 v17; // rax
  int v18; // esi
  signed int v19; // eax
  int m_nVertexCount; // eax
  int v21; // esi
  CDispInfo *v22; // edi
  const ddispinfo_t *v23; // eax
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder builder; // [esp+8h] [ebp-1F4h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F0h] [ebp-Ch]
  CGroupMesh *pMesh; // [esp+1F4h] [ebp-8h]
  int nIndices; // [esp+1F8h] [ebp-4h] BYREF
  int iIndexOffset; // [esp+208h] [ebp+Ch]

  v8 = materials->GetRenderContext(this: materials);
  v9 = 0;
  pRenderContext.m_pObject = v8;
  if ( v8 != nullptr )
    v8->BeginRender(this: v8);
  v10 = (CGroupMesh *)MemAlloc_Alloc(nSize: 0x48u);
  if ( v10 != nullptr )
  {
    v10->m_DispInfos.m_Memory.m_pMemory = nullptr;
    v10->m_DispInfos.m_Memory.m_nAllocationCount = 0;
    v10->m_DispInfos.m_Memory.m_nGrowSize = 0;
    v10->m_DispInfos.m_Size = 0;
    v10->m_DispInfos.m_pElements = nullptr;
    v10->m_VisibleDisps.m_Memory.m_pMemory = nullptr;
    v10->m_VisibleDisps.m_Memory.m_nAllocationCount = 0;
    v10->m_VisibleDisps.m_Memory.m_nGrowSize = 0;
    v10->m_VisibleDisps.m_Size = 0;
    v10->m_VisibleDisps.m_pElements = nullptr;
    v11 = v10;
    v10->m_Visible.m_Memory.m_pMemory = nullptr;
    v10->m_Visible.m_Memory.m_nAllocationCount = 0;
    v10->m_Visible.m_Memory.m_nGrowSize = 0;
    v10->m_Visible.m_Size = 0;
    v10->m_Visible.m_pElements = nullptr;
    pMesh = v10;
  }
  else
  {
    pMesh = nullptr;
    v11 = nullptr;
  }
  m_nAllocationCount = pCombo->m_Meshes.m_Memory.m_nAllocationCount;
  nIndices = pCombo->m_Meshes.m_Size;
  v12 = nIndices;
  if ( nIndices + 1 > m_nAllocationCount )
  {
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&pCombo->m_Meshes,
      num: nIndices - m_nAllocationCount + 1);
    v12 = nIndices;
  }
  ++pCombo->m_Meshes.m_Size;
  m_pMemory = pCombo->m_Meshes.m_Memory.m_pMemory;
  v15 = pCombo->m_Meshes.m_Size - v12 - 1;
  pCombo->m_Meshes.m_pElements = m_pMemory;
  if ( v15 > 0 )
  {
    _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * v15);
    v12 = nIndices;
  }
  v16 = &pCombo->m_Meshes.m_Memory.m_pMemory[v12];
  if ( v16 != nullptr )
    *v16 = v11;
  v17 = ((__int64 (__thiscall *)(IMaterial *, int))pCombo->m_pMaterial->GetVertexFormat)(
          a1: pCombo->m_pMaterial,
          a2: a1);
  v11->m_pMesh = (IMesh *)((int (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, const char *, _DWORD, _DWORD))pRenderContext.m_pObject->CreateStaticMesh)(
                            a1: pRenderContext.m_pObject,
                            a2: v17 & 0xFFFFFBFF,
                            a3: HIDWORD(v17),
                            a4: "Displacement Verts",
                            a5: 0,
                            a6: 0);
  v11->m_pGroup = pCombo;
  v11->m_nVisible = 0;
  CMeshBuilder::CMeshBuilder(this: &builder);
  v18 = nTotalIndices;
  CMeshBuilder::Begin(
    this: &builder,
    pMesh: v11->m_pMesh,
    type: MATERIAL_TRIANGLES,
    nVertexCount: nTotalVerts,
    nIndexCount: nTotalIndices,
    pMeshSettings: nullptr);
  v19 = v18 * builder.m_IndexBuilder.m_nIndexSize + builder.m_IndexBuilder.m_nCurrentIndex;
  builder.m_IndexBuilder.m_nCurrentIndex = v19;
  if ( v19 > builder.m_IndexBuilder.m_nIndexCount )
    builder.m_IndexBuilder.m_nIndexCount = v19;
  CVertexBuilder::AdvanceVertices(this: &builder.m_VertexBuilder, nVerts: nTotalVerts);
  if ( builder.m_bGenerateIndices )
  {
    switch ( builder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * builder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * builder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * builder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * builder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = builder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &builder.m_IndexBuilder,
      primitiveType: builder.m_Type,
      nIndexCount: m_nVertexCount);
  }
  ((void (__thiscall *)(IMesh *, int, int))builder.m_pMesh->UnlockMesh)(
    a1: builder.m_pMesh,
    a2: builder.m_VertexBuilder.m_nVertexCount,
    a3: builder.m_IndexBuilder.m_nIndexCount);
  builder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  builder.m_IndexBuilder.m_nMaxIndexCount = 0;
  builder.m_VertexBuilder.m_nMaxVertexCount = 0;
  builder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  builder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  builder.m_pMesh = nullptr;
  v11->m_DispInfos.m_Size = 0;
  CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&v11->m_DispInfos,
    elem: 0,
    num: nDisps);
  v11->m_Visible.m_Size = 0;
  CUtlVector<CPrimList,CUtlMemory<CPrimList,int>>::InsertMultipleBefore(
    this: (CUtlVector<ResourceEntryInfo,CUtlMemory<ResourceEntryInfo,int> > *)&v11->m_Visible,
    elem: 0,
    num: nDisps);
  v11->m_VisibleDisps.m_Size = 0;
  CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&v11->m_VisibleDisps,
    elem: 0,
    num: nDisps);
  v21 = 0;
  for ( iIndexOffset = 0; v21 < nDisps; ++v21 )
  {
    v22 = (CDispInfo *)DispInfo_IndexArray(
                         hArray: *(_DWORD **)(pWorld->sprite.numframes + 112),
                         iElement: pDispInfos[v21]);
    v23 = &pMapDisps[pDispInfos[v21]];
    v22->m_pMesh = pMesh;
    v22->m_iIndexOffset = iIndexOffset;
    v22->m_iVertOffset = v9;
    CalcMaxNumVertsAndIndices(power: v23->power, nVerts: &nTotalIndices, &nIndices);
    v9 += nTotalIndices;
    iIndexOffset += nIndices;
    pMesh->m_DispInfos.m_Memory.m_pMemory[v21] = v22;
  }
  if ( builder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && builder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: builder.m_VertexBuilder.m_pVertexBuffer) )
  {
    builder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: builder.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( builder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && builder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: builder.m_IndexBuilder.m_pIndexBuffer) )
  {
    builder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: builder.m_IndexBuilder.m_pIndexBuffer);
  }
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x100C2580
// Name: void DispInfo_CreateEmptyStaticBuffers(struct model_t __near *,class ddispinfo_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispInfo_CreateEmptyStaticBuffers(model_t *pWorld, const ddispinfo_t *pMapDisps)
{
  int v2; // esi
  int v3; // eax
  CDispGroup *v4; // edi
  int v5; // ebx
  int v6; // eax
  int i; // [esp+4h] [ebp-14h]
  int nVerts; // [esp+8h] [ebp-10h] BYREF
  int nIndices; // [esp+Ch] [ebp-Ch] BYREF
  int iStart; // [esp+10h] [ebp-8h]
  int nTotalIndices; // [esp+14h] [ebp-4h]

  v2 = 0;
  v3 = 0;
  i = 0;
  if ( g_DispGroups.m_Size <= 0 )
    return;
  while ( 2 )
  {
    v4 = g_DispGroups.m_Memory.m_pMemory[v3];
    v5 = 0;
    nTotalIndices = 0;
    iStart = 0;
    if ( v4->m_DispInfos.m_Size <= 0 )
      goto LABEL_13;
    while ( 1 )
    {
      CalcMaxNumVertsAndIndices(power: pMapDisps[v4->m_DispInfos.m_Memory.m_pMemory[v2]].power, &nVerts, &nIndices);
      v6 = nTotalIndices;
      if ( v5 + nVerts > 0x2000 || (nTotalIndices += nIndices, v6 + nIndices > 0x2000) )
      {
        AddEmptyMesh(
          a1: (int)v4,
          pWorld,
          pCombo: v4,
          pMapDisps,
          pDispInfos: &v4->m_DispInfos.m_Memory.m_pMemory[iStart],
          nDisps: v2 - iStart,
          nTotalVerts: v5,
          nTotalIndices: v6);
        v5 = 0;
        iStart = v2;
        nTotalIndices = 0;
        --v2;
        goto LABEL_10;
      }
      if ( v2 == v4->m_DispInfos.m_Size - 1 )
        break;
      v5 += nVerts;
LABEL_10:
      if ( ++v2 >= v4->m_DispInfos.m_Size )
        goto LABEL_13;
    }
    AddEmptyMesh(
      a1: (int)v4,
      pWorld,
      pCombo: v4,
      pMapDisps,
      pDispInfos: &v4->m_DispInfos.m_Memory.m_pMemory[iStart],
      nDisps: v2 - iStart + 1,
      nTotalVerts: v5 + nVerts,
      nTotalIndices: v6 + nIndices);
LABEL_13:
    v3 = i + 1;
    i = v3;
    if ( v3 < g_DispGroups.m_Size )
    {
      v2 = 0;
      continue;
    }
    break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C26A0
// Name: bool DispInfo_CreateFromMapDisp(struct model_t __near *,int,class ddispinfo_t const __near *,class CCoreDispInfo __near *,class CDispVert const __near *,class CDispTri const __near *,class CDispMultiBlend const __near *,struct MaterialSystem_SortInfo_t const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl DispInfo_CreateFromMapDisp(
        model_t *pWorld,
        int iDisp,
        const ddispinfo_t *pMapDisp,
        CCoreDispInfo *pCoreDisp,
        const CDispVert *pVerts,
        const CDispTri *pTris,
        const CDispMultiBlend *pMultiBlend,
        const MaterialSystem_SortInfo_t *pSortInfos,
        bool bRestoring)
{
  IDispInfo *v9; // eax
  CDispInfo *v10; // ebx
  msurface2_t *v11; // eax

  v9 = DispInfo_IndexArray(hArray: *(_DWORD **)(pWorld->sprite.numframes + 112), iElement: iDisp);
  pCoreDisp->m_Surf.m_PointStart = pMapDisp->startPosition;
  v10 = (CDispInfo *)v9;
  CCoreDispInfo::InitDispInfo(
    this: pCoreDisp,
    power: pMapDisp->power,
    minTess: pMapDisp->minTess,
    smoothingAngle: pMapDisp->smoothingAngle,
    pVerts,
    pTris,
    nFlags: pMapDisp->minTess,
    pvMultiBlends: pMultiBlend);
  CCoreDispSurface::SetNeighborData(
    this: &pCoreDisp->m_Surf,
    edgeNeighbors: pMapDisp->m_EdgeNeighbors,
    cornerNeighbors: pMapDisp->m_CornerNeighbors);
  pCoreDisp->m_AllowedVerts = *(CBitVec<289> *)pMapDisp->m_AllowedVerts;
  v11 = v10->GetParent(this: v10);
  BuildDispSurfInit(pWorld, pBuildDisp: pCoreDisp, worldSurfID: v11);
  if ( !CCoreDispInfo::Create(this: pCoreDisp) )
    return 0;
  v10->m_iPointStart = pCoreDisp->m_Surf.m_PointStartIndex;
  v10->m_Index = iDisp;
  CDispInfo::CopyMapDispData(this: v10, pBuildDisp: pMapDisp);
  if ( CDispInfo::CopyCoreDispData(this: v10, pWorld, pSortInfos, pCoreDisp, bRestoring) == 0 )
    return 0;
  CDispInfo::InitializeActiveVerts(this: v10);
  v10->m_iLightmapSamplePositionStart = pMapDisp->m_iLightmapSamplePositionStart;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C2810
// Name: void DispInfo_ReleaseMaterialSystemObjects(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DispInfo_ReleaseMaterialSystemObjects(model_t *pWorld)
{
  IMatRenderContext *v1; // ebx
  CDispGroup *v2; // edi
  int i; // esi
  worldbrushdata_t *pShared; // eax
  int j; // esi
  IDispInfo *v6; // eax
  int iGroup; // [esp+4h] [ebp-4h]

  v1 = materials->GetRenderContext(this: materials);
  if ( v1 != nullptr )
    v1->BeginRender(this: v1);
  for ( iGroup = 0; iGroup < g_DispGroups.m_Size; ++iGroup )
  {
    v2 = g_DispGroups.m_Memory.m_pMemory[iGroup];
    for ( i = 0; i < v2->m_Meshes.m_Size; ++i )
      v1->DestroyStaticMesh(this: v1, a2: v2->m_Meshes.m_Memory.m_pMemory[i]->m_pMesh);
    CUtlVector<CGroupMesh *,CUtlMemory<CGroupMesh *,int>>::PurgeAndDeleteElements(this: &v2->m_Meshes);
  }
  CUtlVector<CDispGroup *,CUtlMemory<CDispGroup *,int>>::PurgeAndDeleteElements(this: &g_DispGroups);
  if ( pWorld != nullptr )
  {
    pShared = pWorld->brush.pShared;
    for ( j = 0; j < pShared->numDispInfos; ++j )
    {
      v6 = DispInfo_IndexArray(hArray: (_DWORD *)pShared->hDispInfos, iElement: j);
      if ( v6 != nullptr )
      {
        v6[10].__vftable = nullptr;
        v6[9].__vftable = nullptr;
        v6[11].__vftable = nullptr;
      }
      pShared = pWorld->brush.pShared;
    }
  }
  if ( v1 != nullptr )
  {
    v1->EndRender(this: v1);
    v1->Release(this: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C2900
// Name: bool DispInfo_LoadDisplacements(struct model_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl DispInfo_LoadDisplacements(model_t *pWorld, bool bRestoring)
{
  signed int v2; // ebx
  int v3; // esi
  model_t *v4; // esi
  int m_Size; // edi
  int v6; // eax
  _DWORD *Array; // eax
  bool v8; // zf
  int v9; // eax
  int v10; // eax
  CCoreDispInfo *v11; // eax
  int v12; // esi
  CCoreDispInfo **m_pMemory; // ecx
  int *v14; // esi
  int *p_power; // edi
  int v16; // esi
  int v17; // esi
  int j; // esi
  CDispInfo *v19; // edi
  CDispInfo *v20; // eax
  int k; // esi
  IDispInfo *v22; // eax
  int m; // esi
  CDispInfo *v24; // eax
  int n; // esi
  CDispInfo *v26; // eax
  ddispinfo_t pData[2048]; // [esp+18h] [ebp-5FAD8h] BYREF
  CDispMultiBlend pMultiBlend; // [esp+58018h] [ebp-7AD8h] BYREF
  CDispVert pVerts; // [esp+5DA68h] [ebp-2088h] BYREF
  CDispTri pTris; // [esp+5F0FCh] [ebp-9F4h] BYREF
  CMapLoadHelper v32; // [esp+5F4FCh] [ebp-5F4h] BYREF
  CMapLoadHelper v33; // [esp+5F624h] [ebp-4CCh] BYREF
  CMapLoadHelper v34; // [esp+5F74Ch] [ebp-3A4h] BYREF
  CMapLoadHelper v35; // [esp+5F874h] [ebp-27Ch] BYREF
  CMapLoadHelper v36; // [esp+5F99Ch] [ebp-154h] BYREF
  MaterialSystem_SortInfo_t *pSortInfos; // [esp+5FAC4h] [ebp-2Ch]
  signed int i; // [esp+5FAC8h] [ebp-28h]
  int v39; // [esp+5FACCh] [ebp-24h]
  int v40; // [esp+5FAD0h] [ebp-20h]
  int v41; // [esp+5FAD4h] [ebp-1Ch]
  CUtlVector<CCoreDispInfo *,CUtlMemory<CCoreDispInfo *,int> > v42; // [esp+5FAD8h] [ebp-18h] BYREF
  int iDisp; // [esp+5FAECh] [ebp-4h]
  CCoreDispInfo *bRestoringa; // [esp+5FAFCh] [ebp+Ch]

  pSortInfos = materialSortInfoArray;
  v2 = CMapLoadHelper::LumpSize(lumpId: 26) / 0xB0u;
  v3 = CMapLoadHelper::LumpSize(lumpId: 34);
  if ( bRestoring )
  {
    v4 = pWorld;
    m_Size = 0;
    if ( *(_DWORD *)(pWorld->sprite.numframes + 108) != v2 )
      iDisp = 1;
    v6 = *(_DWORD *)(pWorld->sprite.numframes + 108);
    if ( v6 == 0 && v2 != 0 )
      return 0;
    if ( v6 != v2 )
      _Error(a1: "DispInfo_LoadDisplacments: dispcounts (%d and %d) don't match.", v6, v2);
  }
  else
  {
    *(_DWORD *)(pWorld->sprite.numframes + 108) = v2;
    Array = DispInfo_CreateArray(nElements: *(_DWORD *)(pWorld->sprite.numframes + 108));
    v8 = (_S1_5 & 1) == 0;
    *(_DWORD *)(pWorld->sprite.numframes + 112) = Array;
    if ( v8 )
    {
      _S1_5 |= 1u;
      ConVarRef::ConVarRef(this: &r_dlightsenable, pName: "r_dlightsenable");
    }
    if ( r_dlightsenable.m_pConVarState->m_Value.m_nValue != 0 )
    {
      v9 = CHunkAllocCredit::s_DbgInfoStackDepth + 1;
      CHunkAllocCredit::s_DbgInfoStackDepth = v9;
      if ( v9 < 8 )
        CHunkAllocCredit::s_DbgInfoStack[v9] = "g_DispLightmapSamplePositions";
      g_DispLightmapSamplePositions.m_Size = 0;
      if ( v3 != 0 )
      {
        CUtlVector<unsigned char,CHunkMemory<unsigned char>>::GrowVector(this: &g_DispLightmapSamplePositions, num: v3);
        if ( g_DispLightmapSamplePositions.m_Size - v3 > 0 && v3 > 0 )
          _V_memmove(
            dest: &g_DispLightmapSamplePositions.m_Memory.m_pMemory[v3],
            src: g_DispLightmapSamplePositions.m_Memory.m_pMemory,
            count: g_DispLightmapSamplePositions.m_Size - v3);
      }
      CMapLoadHelper::CMapLoadHelper(this: &v32, lumpToLoad: 34, bUncompress: true);
      CMapLoadHelper::LoadLumpData(
        this: &v32,
        offset: 0,
        size: v3,
        pData: g_DispLightmapSamplePositions.m_Memory.m_pMemory);
      CMapLoadHelper::~CMapLoadHelper(this: &v32);
      v10 = CHunkAllocCredit::s_DbgInfoStackDepth;
      if ( CHunkAllocCredit::s_DbgInfoStackDepth >= 0 )
      {
        CHunkAllocCredit::s_DbgInfoStack[CHunkAllocCredit::s_DbgInfoStackDepth] = nullptr;
        CHunkAllocCredit::s_DbgInfoStackDepth = v10 - 1;
      }
    }
    v4 = pWorld;
    m_Size = 0;
  }
  DispInfo_ReleaseMaterialSystemObjects(pWorld: v4);
  if ( v2 > 2048 )
    _Error(a1: "DispInfo_LoadDisplacements: nDisplacements (%d) > MAX_MAP_DISPINFO (%d)", v2, 2048);
  CMapLoadHelper::CMapLoadHelper(this: &v33, lumpToLoad: 26, bUncompress: true);
  CMapLoadHelper::LoadLumpData(this: &v33, offset: 0, size: 176 * v2, pData);
  DispInfo_LinkToParentFaces(pWorld: v4, pMapDisps: pData, nDisplacements: v2);
  DispInfo_CreateMaterialGroups(pWorld: v4, pSortInfos);
  if ( g_VBAllocTracker != nullptr )
    g_VBAllocTracker->TrackMeshAllocations(this: g_VBAllocTracker, a2: "DispInfo_LoadDisplacements");
  DispInfo_CreateEmptyStaticBuffers(pWorld: v4, pMapDisps: pData);
  if ( g_VBAllocTracker != nullptr )
    g_VBAllocTracker->TrackMeshAllocations(this: g_VBAllocTracker, a2: nullptr);
  v39 = 0;
  v40 = 0;
  v41 = 0;
  memset(&v42, 0, sizeof(v42));
  if ( v2 > 0 )
  {
    for ( i = v2; i != 0; --i )
    {
      v11 = (CCoreDispInfo *)MemAlloc_Alloc(nSize: 0x34Cu);
      if ( v11 != nullptr )
        iDisp = (int)CCoreDispInfo::CCoreDispInfo(this: v11);
      else
        iDisp = 0;
      v12 = m_Size;
      if ( m_Size + 1 > v42.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<INetMessage *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&v42,
          num: m_Size - v42.m_Memory.m_nAllocationCount + 1);
        m_Size = v42.m_Size;
      }
      m_pMemory = v42.m_Memory.m_pMemory;
      v42.m_Size = ++m_Size;
      v42.m_pElements = v42.m_Memory.m_pMemory;
      if ( m_Size - v12 - 1 > 0 )
      {
        _V_memmove(
          dest: &v42.m_Memory.m_pMemory[v12 + 1],
          src: &v42.m_Memory.m_pMemory[v12],
          count: 4 * (m_Size - v12 - 1));
        m_pMemory = v42.m_Memory.m_pMemory;
      }
      v14 = (int *)&m_pMemory[v12];
      if ( v14 != nullptr )
        *v14 = iDisp;
    }
  }
  CMapLoadHelper::CMapLoadHelper(this: &v35, lumpToLoad: 33, bUncompress: true);
  CMapLoadHelper::CMapLoadHelper(this: &v34, lumpToLoad: 48, bUncompress: true);
  CMapLoadHelper::CMapLoadHelper(this: &v36, lumpToLoad: 63, bUncompress: true);
  iDisp = 0;
  if ( v2 > 0 )
  {
    p_power = &pData[0].power;
    while ( 1 )
    {
      if ( p_power != (int *)20 )
      {
        v16 = ((1 << *p_power) + 1) * ((1 << *p_power) + 1);
        if ( v16 > 289 )
          _Error(
            a1: "DispInfo_LoadDisplacements: invalid vertex count (%d)",
            ((1 << *p_power) + 1) * ((1 << *p_power) + 1));
        CMapLoadHelper::LoadLumpData(this: &v35, offset: 20 * v39, size: 20 * v16, pData: &pVerts);
        if ( (p_power[1] & 0x40000000) != 0 )
        {
          CMapLoadHelper::LoadLumpData(this: &v36, offset: 80 * v41, size: 80 * v16, pData: &pMultiBlend);
          v41 += v16;
        }
        v39 += v16;
        v17 = 2 * (1 << *p_power) * (1 << *p_power);
        if ( v17 > 512 )
          _Error(a1: "DispInfo_LoadDisplacements: invalid tri count (%d)", 2 * (1 << *p_power) * (1 << *p_power));
        CMapLoadHelper::LoadLumpData(this: &v34, offset: 2 * v40, size: 2 * v17, pData: &pTris);
        v40 += v17;
        if ( DispInfo_CreateFromMapDisp(
               pWorld,
               iDisp,
               pMapDisp: (const ddispinfo_t *)(p_power - 5),
               pCoreDisp: v42.m_Memory.m_pMemory[iDisp],
               &pVerts,
               &pTris,
               &pMultiBlend,
               pSortInfos,
               bRestoring) == 0 )
          break;
      }
      p_power += 44;
      if ( ++iDisp >= v2 )
        goto LABEL_49;
    }
    CMapLoadHelper::~CMapLoadHelper(this: &v36);
    CMapLoadHelper::~CMapLoadHelper(this: &v34);
    CMapLoadHelper::~CMapLoadHelper(this: &v35);
    if ( v42.m_Memory.m_nGrowSize >= 0 && v42.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v42.m_Memory.m_pMemory);
    CMapLoadHelper::~CMapLoadHelper(this: &v33);
    return 0;
  }
LABEL_49:
  SmoothDispSurfNormals(ppListBase: v42.m_Memory.m_pMemory, nListSize: v2);
  for ( j = 0; j < v2; ++j )
  {
    bRestoringa = v42.m_Memory.m_pMemory[j];
    v19 = (CDispInfo *)DispInfo_IndexArray(hArray: *(_DWORD **)(pWorld->sprite.numframes + 112), iElement: j);
    FillStaticBuffer(
      pMesh: v19->m_pMesh,
      pDisp: v19,
      pCoreDisp: bRestoringa,
      &pVerts,
      nLightmaps: (v19->m_ParentSurfID->flags & 8) != 0 ? 4 : 1);
    BuildTagData(pCoreDisp: bRestoringa, pDisp: v19);
    v20 = (CDispInfo *)DispInfo_IndexArray(hArray: *(_DWORD **)(pWorld->sprite.numframes + 112), iElement: j);
    CDispInfo::CopyCoreDispVertData(
      this: v20,
      pCoreDisp: v42.m_Memory.m_pMemory[j],
      bumpSTexCoordOffset: v20->m_BumpSTexCoordOffset);
  }
  CUtlVector<CCoreDispInfo *,CUtlMemory<CCoreDispInfo *,int>>::PurgeAndDeleteElements(this: &v42);
  for ( k = 0; k < v2; ++k )
  {
    v22 = DispInfo_IndexArray(hArray: *(_DWORD **)(pWorld->sprite.numframes + 112), iElement: k);
    memcpy(dst: (unsigned __int8 *)&v22[70], src: (unsigned __int8 *)&v22[80], count: 0x28u);
  }
  for ( m = 0; m < v2; ++m )
  {
    v24 = (CDispInfo *)DispInfo_IndexArray(hArray: *(_DWORD **)(pWorld->sprite.numframes + 112), iElement: m);
    CDispInfo::TesselateDisplacement(this: v24);
  }
  SetupMeshReaders(pWorld, nDisplacements: v2);
  for ( n = 0; n < v2; ++n )
  {
    v26 = (CDispInfo *)DispInfo_IndexArray(hArray: *(_DWORD **)(pWorld->sprite.numframes + 112), iElement: n);
    CDispInfo::UpdateBoundingBox(this: v26);
  }
  CMapLoadHelper::~CMapLoadHelper(this: &v36);
  CMapLoadHelper::~CMapLoadHelper(this: &v34);
  CMapLoadHelper::~CMapLoadHelper(this: &v35);
  if ( v42.m_Memory.m_nGrowSize >= 0 && v42.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v42.m_Memory.m_pMemory);
  CMapLoadHelper::~CMapLoadHelper(this: &v33);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10133700
// Name: public: virtual class CBitVec<2048> const __near * CVEngineServer::GetEntityTransmitBitsForClient(int)
// Source: json
//------------------------------------------------------------------------------
const CBitVec<2048> *__thiscall CVEngineServer::GetEntityTransmitBitsForClient(CVEngineServer *this, int iClientIndex)
{
  CClientFrame *ClientFrame; // eax

  if ( iClientIndex >= 0
    && iClientIndex < sv.m_Clients.m_Size
    && (ClientFrame = CClientFrameManager::GetClientFrame(
                        this: (CClientFrameManager *)&sv.m_Clients.m_Memory.m_pMemory[iClientIndex][1],
                        nTick: sv.m_Clients.m_Memory.m_pMemory[iClientIndex]->m_nDeltaTick,
                        bExact: true)) != nullptr )
  {
    return &ClientFrame->transmit_entity;
  }
  else
  {
    return nullptr;
  }
}

} // namespace engine_xlsp
