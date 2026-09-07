// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_func_breakablesurf.cpp
// Functions: 33
// ============================================================

#include "game\client\c_func_breakablesurf.h"

//------------------------------------------------------------------------------
// Address: 0x1006BE80
// Name: public: virtual struct datamap_t __near * C_BreakableSurface::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_BreakableSurface::GetDataDescMap(C_BreakableSurface *this)
{
  return &C_BreakableSurface::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1006BE90
// Name: public: virtual class ClientClass __near * C_BreakableSurface::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_BreakableSurface::GetClientClass(C_BreakableSurface *this)
{
  return &__g_C_BreakableSurfaceClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1006BEA0
// Name: private: void C_BreakableSurface::FindCrackedMaterial(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BreakableSurface::FindCrackedMaterial(C_BreakableSurface *this)
{
  IVModelInfoClient_vtbl *v2; // ebx
  const struct model_t *v3; // eax
  IVModelInfoClient_vtbl *v4; // ebx
  int v5; // eax
  IMaterialVar *v6; // eax
  const char *v7; // eax
  IMaterial *pMaterial; // [esp+Ch] [ebp-8h] BYREF
  bool foundVar; // [esp+13h] [ebp-1h] BYREF

  CMaterialReference::Init(this: &this->m_pCrackedMaterial, pMaterial: nullptr);
  v2 = modelinfo->__vftable;
  v3 = this->GetModel(this: &this->IClientRenderable);
  if ( v2->GetModelMaterialCount(this: modelinfo, a2: v3) == 1 )
  {
    v4 = modelinfo->__vftable;
    v5 = ((int (__thiscall *)(IClientRenderable *, int, IMaterial **))this->GetModel)(
           a1: &this->IClientRenderable,
           a2: 1,
           a3: &pMaterial);
    ((void (__thiscall *)(IVModelInfoClient *, int))v4->GetModelMaterials)(a1: modelinfo, a2: v5);
    v6 = pMaterial->FindVar(this: pMaterial, a2: "$crackmaterial", a3: &foundVar, a4: 0);
    if ( foundVar )
    {
      v7 = v6->GetStringValue(this: v6);
      CMaterialReference::Init(
        this: &this->m_pCrackedMaterial,
        pMaterialName: v7,
        pTextureGroupName: "ClientEffect textures",
        bComplain: true);
    }
    else
    {
      CMaterialReference::Init(this: &this->m_pCrackedMaterial, pMaterial);
    }
  }
  else
  {
    _Warning(a1: "Encountered func_breakablesurf that has a material applied to more than one surface!\n");
    CMaterialReference::Init(
      this: &this->m_pCrackedMaterial,
      pMaterialName: "debug/debugempty",
      pTextureGroupName: "Other textures",
      bComplain: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006BF80
// Name: public: virtual enum RenderableTranslucencyType_t C_BreakableSurface::ComputeTranslucencyType(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BreakableSurface::ComputeTranslucencyType(C_BreakableSurface *this)
{
  if ( this->m_bIsBroken )
    return 1;
  else
    return C_BaseEntity::ComputeTranslucencyType(this);
}

//------------------------------------------------------------------------------
// Address: 0x1006BFB0
// Name: public: virtual int C_BreakableSurface::DrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BreakableSurface::DrawModel(
        C_BreakableSurface *this,
        unsigned int flags,
        const RenderableInstance_t *instance)
{
  IBrushRenderer *v4; // eax
  unsigned int v5; // eax

  if ( LOBYTE(this->m_VisibilityBits.m_Ints[0]) != 0 )
  {
    if ( LOBYTE(this->m_vCorner.z) != 0
      && (this == (C_BreakableSurface *)4 ? (v4 = nullptr) : (v4 = (IBrushRenderer *)(&this->m_bIsBlurred + 4)),
          render->InstallBrushSurfaceRenderer(this: render, a2: v4),
          LOBYTE(this->m_vCorner.z) != 0) )
    {
      v5 = flags | 0x80000000;
    }
    else
    {
      v5 = flags;
    }
    C_BaseEntity::DrawModel(this, a2: (int)this, flags: v5, instance);
    render->InstallBrushSurfaceRenderer(this: render, a2: nullptr);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1006C030
// Name: public: virtual bool CBreakableSurfaceProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBreakableSurfaceProxy::Init(CBreakableSurfaceProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  this->m_BaseTextureVar = pMaterial->FindVar(this: pMaterial, a2: "$basetexture", a3: (char *)&pMaterial + 3, a4: 0);
  return HIBYTE(pMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x1006C060
// Name: public: virtual void CBreakableSurfaceProxy::OnBind(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableSurfaceProxy::OnBind(CBreakableSurfaceProxy *this, C_BaseEntity *pC_BaseEntity)
{
  ITexture **v3; // eax

  v3 = (ITexture **)__RTDynamicCast(
                      inptr: pC_BaseEntity,
                      VfDelta: 0,
                      SrcType: &C_BaseEntity `RTTI Type Descriptor',
                      TargetType: &C_BreakableSurface `RTTI Type Descriptor',
                      isReference: 0);
  if ( v3 != nullptr )
    this->m_BaseTextureVar->SetTextureValue(this: this->m_BaseTextureVar, a2: v3[621]);
}

//------------------------------------------------------------------------------
// Address: 0x1006C270
// Name: public: void C_BreakableSurface::InitMaterial(enum WinEdge_t,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BreakableSurface::InitMaterial(
        C_BreakableSurface *this,
        WinEdge_t nEdgeType,
        int nEdgeStyle,
        const char *pMaterialName)
{
  int v4; // edx
  CTextureReference *v5; // esi
  CMaterialReference *p_m_pMaterialEdge; // edi
  IMaterialVar *v7; // eax
  ITexture *v8; // eax
  const char *v9; // [esp-Ch] [ebp-14h]

  v4 = nEdgeStyle;
  v5 = (CTextureReference *)((char *)this + 32 * nEdgeType + 16 * nEdgeType + 16 * nEdgeStyle);
  v9 = pMaterialName;
  p_m_pMaterialEdge = &this->m_pEdge[0][2 * nEdgeType + nEdgeType + nEdgeStyle].m_pMaterialEdge;
  v5[826].m_pTexture = (ITexture *)0xFFFF;
  v5[827].m_pTexture = (ITexture *)v4;
  CMaterialReference::Init(
    this: p_m_pMaterialEdge,
    pMaterialName: v9,
    pTextureGroupName: "ClientEffect textures",
    bComplain: true);
  v7 = p_m_pMaterialEdge->m_pMaterial->FindVar(
         this: p_m_pMaterialEdge->m_pMaterial,
         a2: "$basetexture",
         a3: (bool *)&nEdgeType + 3,
         a4: false);
  if ( HIBYTE(nEdgeType) != 0 )
  {
    v8 = (ITexture *)v7->GetTextureValue(this: v7);
    CTextureReference::Init(this: v5 + 829, pTexture: v8);
  }
  else
  {
    CTextureReference::Init(this: v5 + 829, pTexture: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006C300
// Name: public: virtual void C_BreakableSurface::OnPreDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BreakableSurface::OnPreDataChanged(C_BreakableSurface *this, DataUpdateType_t updateType)
{
  C_BreakableSurface *v2; // ebx
  CMaterialReference *p_m_pCrackedMaterial; // esi
  int v4; // edi
  CMaterialReference *v5; // edx
  int v6; // eax
  bool *v7; // ebx

  v2 = this;
  C_BaseEntity::OnPreDataChanged(this, type: updateType);
  if ( updateType == DATA_UPDATE_CREATED )
  {
    p_m_pCrackedMaterial = &v2[-1].m_pCrackedMaterial;
    *((_DWORD *)&v2->m_bIsBlurred + 1) = 16;
    v2->IBrushRenderer::__vftable = (IBrushRenderer_vtbl *)16;
    v4 = 0;
    v5 = &v2[-1].m_pCrackedMaterial;
    while ( 1 )
    {
      v6 = 0;
      v7 = &v2->m_RawPanelBitVec.m_Value[v4 + 24];
      do
      {
        if ( v4 < (int)p_m_pCrackedMaterial[609].m_pMaterial )
        {
          if ( v6 < (int)p_m_pCrackedMaterial[610].m_pMaterial && v4 >= 0 && v6 >= 0 )
            LOBYTE(v5[v6 / 4u + 757].m_pMaterial) |= 1u;
          if ( v4 < (int)p_m_pCrackedMaterial[609].m_pMaterial
            && v6 < (int)p_m_pCrackedMaterial[610].m_pMaterial
            && v4 >= 0
            && v6 >= 0 )
          {
            LOBYTE(v5[v6 / 4u + 757].m_pMaterial) &= ~2u;
          }
        }
        if ( !*(v7 - 32) )
          *(v7 - 32) = true;
        if ( v4 < (int)p_m_pCrackedMaterial[609].m_pMaterial )
        {
          if ( v6 + 1 < (int)p_m_pCrackedMaterial[610].m_pMaterial && v4 >= 0 && v6 + 1 >= 0 )
            BYTE1(v5[v6 / 4u + 757].m_pMaterial) |= 1u;
          if ( v4 < (int)p_m_pCrackedMaterial[609].m_pMaterial
            && v6 + 1 < (int)p_m_pCrackedMaterial[610].m_pMaterial
            && v4 >= 0
            && v6 + 1 >= 0 )
          {
            BYTE1(v5[v6 / 4u + 757].m_pMaterial) &= ~2u;
          }
        }
        if ( !*(v7 - 16) )
          *(v7 - 16) = true;
        if ( v4 < (int)p_m_pCrackedMaterial[609].m_pMaterial )
        {
          if ( v6 + 2 < (int)p_m_pCrackedMaterial[610].m_pMaterial && v4 >= 0 && v6 + 2 >= 0 )
            BYTE2(v5[v6 / 4u + 757].m_pMaterial) |= 1u;
          if ( v4 < (int)p_m_pCrackedMaterial[609].m_pMaterial
            && v6 + 2 < (int)p_m_pCrackedMaterial[610].m_pMaterial
            && v4 >= 0
            && v6 + 2 >= 0 )
          {
            BYTE2(v5[v6 / 4u + 757].m_pMaterial) &= ~2u;
          }
        }
        if ( !*v7 )
          *v7 = true;
        if ( v4 < (int)p_m_pCrackedMaterial[609].m_pMaterial )
        {
          if ( v6 + 3 < (int)p_m_pCrackedMaterial[610].m_pMaterial && v4 >= 0 && v6 + 3 >= 0 )
            HIBYTE(v5[v6 / 4u + 757].m_pMaterial) |= 1u;
          if ( v4 < (int)p_m_pCrackedMaterial[609].m_pMaterial
            && v6 + 3 < (int)p_m_pCrackedMaterial[610].m_pMaterial
            && v4 >= 0
            && v6 + 3 >= 0 )
          {
            HIBYTE(v5[v6 / 4u + 757].m_pMaterial) &= ~2u;
          }
        }
        if ( !v7[16] )
          v7[16] = true;
        v6 += 4;
        v7 += 64;
      }
      while ( v6 < 16 );
      ++v4;
      v5 += 4;
      if ( v4 >= 16 )
        break;
      v2 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006C4B0
// Name: private: void C_BreakableSurface::DrawOneBlock(class IBrushSurface __near *,class IMesh __near *,class CMeshBuilder __near *,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BreakableSurface::DrawOneBlock(
        C_BreakableSurface *this,
        IBrushSurface *pBrushSurface,
        IMesh *pMesh,
        CMeshBuilder *pMeshBuilder,
        const Vector *vCurPos,
        const Vector *vWidthStep,
        const Vector *vHeightStep)
{
  float *m_pCurrPosition; // eax
  float y; // xmm0_4
  float z; // xmm1_4
  float *v13; // eax
  void (__thiscall *ComputeTextureCoordinate)(IBrushSurface *, const Vector *, Vector2D *); // edx
  float *v15; // eax
  float v16; // xmm1_4
  float v17; // xmm2_4
  void (__thiscall *v18)(IBrushSurface *, const Vector *, Vector2D *); // edx
  float *v19; // eax
  float v20; // xmm1_4
  float v21; // xmm2_4
  void (__thiscall *v22)(IBrushSurface *, const Vector *, Vector2D *); // edx
  float *v23; // eax
  MaterialPrimitiveType_t m_Type; // ebx
  int v25; // eax
  Vector vNextPos; // [esp+Ch] [ebp-1Ch] BYREF
  Vector2D texCoord; // [esp+18h] [ebp-10h] BYREF
  Vector2D lightCoord; // [esp+20h] [ebp-8h] BYREF

  pMeshBuilder->m_pMesh = pMesh;
  pMeshBuilder->m_bGenerateIndices = true;
  pMeshBuilder->m_Type = MATERIAL_QUADS;
  pMesh->SetPrimitiveType(this: pMesh, a2: MATERIAL_TRIANGLES);
  pMeshBuilder->m_pMesh->LockMesh(this: pMeshBuilder->m_pMesh, a2: 4, a3: 6, a4: pMeshBuilder, a5: nullptr);
  pMeshBuilder->m_IndexBuilder.m_pIndexBuffer = &pMesh->IIndexBuffer;
  pMeshBuilder->m_IndexBuilder.m_nIndexCount = 0;
  pMeshBuilder->m_IndexBuilder.m_nMaxIndexCount = 6;
  pMeshBuilder->m_IndexBuilder.m_bModify = false;
  pMeshBuilder->m_IndexBuilder.m_nIndexOffset = pMeshBuilder->m_nFirstVertex;
  pMeshBuilder->m_IndexBuilder.m_pIndices = pMeshBuilder->m_pIndices;
  pMeshBuilder->m_IndexBuilder.m_nIndexSize = pMeshBuilder->m_nIndexSize;
  pMeshBuilder->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &pMeshBuilder->m_VertexBuilder, pMesh, nMaxVertexCount: 4, desc: pMeshBuilder);
  pMeshBuilder->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &pMeshBuilder->m_VertexBuilder);
  pBrushSurface->ComputeTextureCoordinate(this: pBrushSurface, a2: vCurPos, a3: &texCoord);
  pBrushSurface->ComputeLightmapCoordinate(this: pBrushSurface, a2: vCurPos, a3: &lightCoord);
  m_pCurrPosition = pMeshBuilder->m_VertexBuilder.m_pCurrPosition;
  y = vCurPos->y;
  z = vCurPos->z;
  *m_pCurrPosition = vCurPos->x;
  m_pCurrPosition[1] = y;
  m_pCurrPosition[2] = z;
  *(_DWORD *)pMeshBuilder->m_VertexBuilder.m_pCurrColor = -1;
  v13 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
  *v13 = 0.0;
  v13[1] = 1.0;
  *(Vector2D *)pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[1] = lightCoord;
  *(Vector2D *)pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[2] = texCoord;
  *(Vector *)pMeshBuilder->m_VertexBuilder.m_pCurrNormal = this->m_vNormal;
  CVertexBuilder::AdvanceVertex(this: &pMeshBuilder->m_VertexBuilder);
  ComputeTextureCoordinate = pBrushSurface->ComputeTextureCoordinate;
  vNextPos.x = vCurPos->x + vWidthStep->x;
  vNextPos.y = vCurPos->y + vWidthStep->y;
  vNextPos.z = vCurPos->z + vWidthStep->z;
  ComputeTextureCoordinate(this: pBrushSurface, a2: &vNextPos, a3: &texCoord);
  pBrushSurface->ComputeLightmapCoordinate(this: pBrushSurface, a2: &vNextPos, a3: &lightCoord);
  *(Vector *)pMeshBuilder->m_VertexBuilder.m_pCurrPosition = vNextPos;
  *(_DWORD *)pMeshBuilder->m_VertexBuilder.m_pCurrColor = -1;
  v15 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
  *v15 = 0.0;
  v15[1] = 0.0;
  *(Vector2D *)pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[1] = lightCoord;
  *(Vector2D *)pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[2] = texCoord;
  *(Vector *)pMeshBuilder->m_VertexBuilder.m_pCurrNormal = this->m_vNormal;
  CVertexBuilder::AdvanceVertex(this: &pMeshBuilder->m_VertexBuilder);
  v16 = vHeightStep->y + vNextPos.y;
  v17 = vHeightStep->z + vNextPos.z;
  vNextPos.x = vHeightStep->x + vNextPos.x;
  vNextPos.y = v16;
  v18 = pBrushSurface->ComputeTextureCoordinate;
  vNextPos.z = v17;
  v18(this: pBrushSurface, a2: &vNextPos, a3: &texCoord);
  pBrushSurface->ComputeLightmapCoordinate(this: pBrushSurface, a2: &vNextPos, a3: &lightCoord);
  *(Vector *)pMeshBuilder->m_VertexBuilder.m_pCurrPosition = vNextPos;
  *(_DWORD *)pMeshBuilder->m_VertexBuilder.m_pCurrColor = -1;
  v19 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
  *v19 = 1.0;
  v19[1] = 0.0;
  *(Vector2D *)pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[1] = lightCoord;
  *(Vector2D *)pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[2] = texCoord;
  *(Vector *)pMeshBuilder->m_VertexBuilder.m_pCurrNormal = this->m_vNormal;
  CVertexBuilder::AdvanceVertex(this: &pMeshBuilder->m_VertexBuilder);
  v20 = vNextPos.y - vWidthStep->y;
  v21 = vNextPos.z - vWidthStep->z;
  v22 = pBrushSurface->ComputeTextureCoordinate;
  vNextPos.x = vNextPos.x - vWidthStep->x;
  vNextPos.y = v20;
  vNextPos.z = v21;
  v22(this: pBrushSurface, a2: &vNextPos, a3: &texCoord);
  pBrushSurface->ComputeLightmapCoordinate(this: pBrushSurface, a2: &vNextPos, a3: &lightCoord);
  *(Vector *)pMeshBuilder->m_VertexBuilder.m_pCurrPosition = vNextPos;
  *(_DWORD *)pMeshBuilder->m_VertexBuilder.m_pCurrColor = -1;
  v23 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
  *v23 = 1.0;
  v23[1] = 1.0;
  *(Vector2D *)pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[1] = lightCoord;
  *(Vector2D *)pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[2] = texCoord;
  *(Vector *)pMeshBuilder->m_VertexBuilder.m_pCurrNormal = this->m_vNormal;
  CVertexBuilder::AdvanceVertex(this: &pMeshBuilder->m_VertexBuilder);
  if ( pMeshBuilder->m_bGenerateIndices )
  {
    m_Type = pMeshBuilder->m_Type;
    v25 = CMeshBuilder::IndicesFromVertices(
            this: pMeshBuilder,
            type: m_Type,
            nVertexCount: pMeshBuilder->m_VertexBuilder.m_nVertexCount);
    CIndexBuilder::GenerateIndices(this: &pMeshBuilder->m_IndexBuilder, primitiveType: m_Type, nIndexCount: v25);
  }
  pMeshBuilder->m_pMesh->UnlockMesh(
    this: pMeshBuilder->m_pMesh,
    a2: pMeshBuilder->m_VertexBuilder.m_nVertexCount,
    a3: pMeshBuilder->m_IndexBuilder.m_nIndexCount,
    a4: pMeshBuilder);
  pMeshBuilder->m_IndexBuilder.m_pIndexBuffer = nullptr;
  pMeshBuilder->m_IndexBuilder.m_nMaxIndexCount = 0;
  pMeshBuilder->m_VertexBuilder.m_nMaxVertexCount = 0;
  pMeshBuilder->m_VertexBuilder.m_pVertexBuffer = nullptr;
  pMeshBuilder->m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  pMeshBuilder->m_pMesh = nullptr;
  pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006C990
// Name: private: void C_BreakableSurface::DrawOneEdge(class IBrushSurface __near *,class IMesh __near *,class CMeshBuilder __near *,class Vector const __near &,class Vector const __near &,class Vector const __near &,enum WinSide_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BreakableSurface::DrawOneEdge(
        C_BreakableSurface *this,
        IBrushSurface *pBrushSurface,
        IMesh *pMesh,
        CMeshBuilder *pMeshBuilder,
        const Vector *vStartPos,
        const Vector *vWStep,
        const Vector *vHStep,
        WinSide_t nEdge)
{
  float *m_pCurrPosition; // eax
  float y; // xmm0_4
  float z; // xmm1_4
  float *v13; // eax
  float *v14; // eax
  float *v15; // eax
  void (__thiscall *ComputeTextureCoordinate)(IBrushSurface *, const Vector *, Vector2D *); // edx
  float *m_pCurrNormal; // eax
  float *v18; // eax
  int v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  void (__thiscall *v22)(IBrushSurface *, const Vector *, Vector2D *); // edx
  float *v23; // eax
  float *v24; // eax
  int v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  void (__thiscall *v28)(IBrushSurface *, const Vector *, Vector2D *); // edx
  float *v29; // eax
  float *v30; // eax
  int v31; // xmm0_4
  MaterialPrimitiveType_t m_Type; // ebx
  int v33; // eax
  Vector vNextPos; // [esp+Ch] [ebp-1Ch] BYREF
  Vector2D texCoord; // [esp+18h] [ebp-10h] BYREF
  Vector2D lightCoord; // [esp+20h] [ebp-8h] BYREF

  pMeshBuilder->m_pMesh = pMesh;
  pMeshBuilder->m_bGenerateIndices = true;
  pMeshBuilder->m_Type = MATERIAL_QUADS;
  pMesh->SetPrimitiveType(this: pMesh, a2: MATERIAL_TRIANGLES);
  pMeshBuilder->m_pMesh->LockMesh(this: pMeshBuilder->m_pMesh, a2: 4, a3: 6, a4: pMeshBuilder, a5: nullptr);
  pMeshBuilder->m_IndexBuilder.m_pIndexBuffer = &pMesh->IIndexBuffer;
  pMeshBuilder->m_IndexBuilder.m_nIndexCount = 0;
  pMeshBuilder->m_IndexBuilder.m_nMaxIndexCount = 6;
  pMeshBuilder->m_IndexBuilder.m_bModify = false;
  pMeshBuilder->m_IndexBuilder.m_nIndexOffset = pMeshBuilder->m_nFirstVertex;
  pMeshBuilder->m_IndexBuilder.m_pIndices = pMeshBuilder->m_pIndices;
  pMeshBuilder->m_IndexBuilder.m_nIndexSize = pMeshBuilder->m_nIndexSize;
  pMeshBuilder->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &pMeshBuilder->m_VertexBuilder, pMesh, nMaxVertexCount: 4, desc: pMeshBuilder);
  pMeshBuilder->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &pMeshBuilder->m_VertexBuilder);
  pBrushSurface->ComputeTextureCoordinate(this: pBrushSurface, a2: vStartPos, a3: &texCoord);
  pBrushSurface->ComputeLightmapCoordinate(this: pBrushSurface, a2: vStartPos, a3: &lightCoord);
  m_pCurrPosition = pMeshBuilder->m_VertexBuilder.m_pCurrPosition;
  y = vStartPos->y;
  z = vStartPos->z;
  *m_pCurrPosition = vStartPos->x;
  m_pCurrPosition[1] = y;
  m_pCurrPosition[2] = z;
  *(Vector *)pMeshBuilder->m_VertexBuilder.m_pCurrNormal = this->m_vNormal;
  *(_DWORD *)pMeshBuilder->m_VertexBuilder.m_pCurrColor = -1;
  *(Vector2D *)pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[1] = lightCoord;
  *(Vector2D *)pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[2] = texCoord;
  switch ( nEdge )
  {
    case WIN_SIDE_BOTTOM:
      v14 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      *v14 = 1.0;
      v14[1] = 1.0;
      break;
    case WIN_SIDE_RIGHT:
      v13 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      *v13 = 1.0;
      goto LABEL_6;
    case WIN_SIDE_TOP:
      v13 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      *v13 = 0.0;
LABEL_6:
      v13[1] = 0.0;
      break;
    case WIN_SIDE_LEFT:
      v15 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      *v15 = 0.0;
      v15[1] = 1.0;
      break;
    default:
      break;
  }
  CVertexBuilder::AdvanceVertex(this: &pMeshBuilder->m_VertexBuilder);
  ComputeTextureCoordinate = pBrushSurface->ComputeTextureCoordinate;
  vNextPos.x = vStartPos->x + vWStep->x;
  vNextPos.y = vStartPos->y + vWStep->y;
  vNextPos.z = vStartPos->z + vWStep->z;
  ComputeTextureCoordinate(this: pBrushSurface, a2: &vNextPos, a3: &texCoord);
  pBrushSurface->ComputeLightmapCoordinate(this: pBrushSurface, a2: &vNextPos, a3: &lightCoord);
  *(Vector *)pMeshBuilder->m_VertexBuilder.m_pCurrPosition = vNextPos;
  m_pCurrNormal = pMeshBuilder->m_VertexBuilder.m_pCurrNormal;
  *m_pCurrNormal = this->m_vNormal.x;
  m_pCurrNormal[1] = this->m_vNormal.y;
  m_pCurrNormal[2] = this->m_vNormal.z;
  *(_DWORD *)pMeshBuilder->m_VertexBuilder.m_pCurrColor = -1;
  *(Vector2D *)pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[1] = lightCoord;
  *(Vector2D *)pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[2] = texCoord;
  switch ( nEdge )
  {
    case WIN_SIDE_BOTTOM:
      v18 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      *v18 = 0.0;
      v19 = 1065353216;
      goto LABEL_12;
    case WIN_SIDE_RIGHT:
      v18 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      v19 = 1065353216;
      *v18 = 1.0;
      goto LABEL_12;
    case WIN_SIDE_TOP:
      v18 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      *v18 = 1.0;
      v19 = 0;
      goto LABEL_12;
    case WIN_SIDE_LEFT:
      v18 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      v19 = 0;
      *v18 = 0.0;
LABEL_12:
      *((_DWORD *)v18 + 1) = v19;
      break;
    default:
      break;
  }
  CVertexBuilder::AdvanceVertex(this: &pMeshBuilder->m_VertexBuilder);
  v20 = vHStep->y + vNextPos.y;
  v21 = vHStep->z + vNextPos.z;
  v22 = pBrushSurface->ComputeTextureCoordinate;
  vNextPos.x = vHStep->x + vNextPos.x;
  vNextPos.y = v20;
  vNextPos.z = v21;
  v22(this: pBrushSurface, a2: &vNextPos, a3: &texCoord);
  pBrushSurface->ComputeLightmapCoordinate(this: pBrushSurface, a2: &vNextPos, a3: &lightCoord);
  *(Vector *)pMeshBuilder->m_VertexBuilder.m_pCurrPosition = vNextPos;
  v23 = pMeshBuilder->m_VertexBuilder.m_pCurrNormal;
  *v23 = this->m_vNormal.x;
  v23[1] = this->m_vNormal.y;
  v23[2] = this->m_vNormal.z;
  *(_DWORD *)pMeshBuilder->m_VertexBuilder.m_pCurrColor = -1;
  *(Vector2D *)pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[1] = lightCoord;
  *(Vector2D *)pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[2] = texCoord;
  switch ( nEdge )
  {
    case WIN_SIDE_BOTTOM:
      v25 = 0;
      goto LABEL_18;
    case WIN_SIDE_RIGHT:
      v24 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      *v24 = 0.0;
      v25 = 1065353216;
      goto LABEL_19;
    case WIN_SIDE_TOP:
      v25 = 1065353216;
LABEL_18:
      v24 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      *(_DWORD *)v24 = v25;
      goto LABEL_19;
    case WIN_SIDE_LEFT:
      v24 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      *v24 = 1.0;
      v25 = 0;
LABEL_19:
      *((_DWORD *)v24 + 1) = v25;
      break;
    default:
      break;
  }
  CVertexBuilder::AdvanceVertex(this: &pMeshBuilder->m_VertexBuilder);
  v26 = vNextPos.y - vWStep->y;
  v27 = vNextPos.z - vWStep->z;
  v28 = pBrushSurface->ComputeTextureCoordinate;
  vNextPos.x = vNextPos.x - vWStep->x;
  vNextPos.y = v26;
  vNextPos.z = v27;
  v28(this: pBrushSurface, a2: &vNextPos, a3: &texCoord);
  pBrushSurface->ComputeLightmapCoordinate(this: pBrushSurface, a2: &vNextPos, a3: &lightCoord);
  *(Vector *)pMeshBuilder->m_VertexBuilder.m_pCurrPosition = vNextPos;
  v29 = pMeshBuilder->m_VertexBuilder.m_pCurrNormal;
  *v29 = this->m_vNormal.x;
  v29[1] = this->m_vNormal.y;
  v29[2] = this->m_vNormal.z;
  *(_DWORD *)pMeshBuilder->m_VertexBuilder.m_pCurrColor = -1;
  *(Vector2D *)pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[1] = lightCoord;
  *(Vector2D *)pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[2] = texCoord;
  switch ( nEdge )
  {
    case WIN_SIDE_BOTTOM:
      v30 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      *v30 = 1.0;
      v31 = 0;
      goto LABEL_25;
    case WIN_SIDE_RIGHT:
      v30 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      v31 = 0;
      *v30 = 0.0;
      goto LABEL_25;
    case WIN_SIDE_TOP:
      v30 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      *v30 = 0.0;
      v31 = 1065353216;
      goto LABEL_25;
    case WIN_SIDE_LEFT:
      v30 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      v31 = 1065353216;
      *v30 = 1.0;
LABEL_25:
      *((_DWORD *)v30 + 1) = v31;
      break;
    default:
      break;
  }
  CVertexBuilder::AdvanceVertex(this: &pMeshBuilder->m_VertexBuilder);
  if ( pMeshBuilder->m_bGenerateIndices )
  {
    m_Type = pMeshBuilder->m_Type;
    v33 = CMeshBuilder::IndicesFromVertices(
            this: pMeshBuilder,
            type: m_Type,
            nVertexCount: pMeshBuilder->m_VertexBuilder.m_nVertexCount);
    CIndexBuilder::GenerateIndices(this: &pMeshBuilder->m_IndexBuilder, primitiveType: m_Type, nIndexCount: v33);
  }
  pMeshBuilder->m_pMesh->UnlockMesh(
    this: pMeshBuilder->m_pMesh,
    a2: pMeshBuilder->m_VertexBuilder.m_nVertexCount,
    a3: pMeshBuilder->m_IndexBuilder.m_nIndexCount,
    a4: pMeshBuilder);
  pMeshBuilder->m_IndexBuilder.m_pIndexBuffer = nullptr;
  pMeshBuilder->m_IndexBuilder.m_nMaxIndexCount = 0;
  pMeshBuilder->m_VertexBuilder.m_nMaxVertexCount = 0;
  pMeshBuilder->m_VertexBuilder.m_pVertexBuffer = nullptr;
  pMeshBuilder->m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  pMeshBuilder->m_pMesh = nullptr;
  pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006CFD0
// Name: private: void C_BreakableSurface::DrawOneHighlight(class IBrushSurface __near *,class IMesh __near *,class CMeshBuilder __near *,class Vector const __near &,class Vector const __near &,class Vector const __near &,enum WinSide_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_BreakableSurface::DrawOneHighlight(
        C_BreakableSurface *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        IBrushSurface *pBrushSurface,
        IMesh *pMesh,
        CMeshBuilder *pMeshBuilder,
        const Vector *vStartPos,
        const Vector *vWStep,
        const Vector *vHStep,
        WinSide_t nEdge)
{
  float *m_pCurrPosition; // eax
  float y; // xmm0_4
  float z; // xmm1_4
  float *v16; // eax
  float *v17; // eax
  float *v18; // eax
  void (__thiscall *ComputeTextureCoordinate)(IBrushSurface *, const Vector *, Vector2D *); // edx
  float *m_pCurrNormal; // eax
  float *v21; // eax
  int v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  void (__thiscall *v25)(IBrushSurface *, const Vector *, Vector2D *); // edx
  float *v26; // eax
  float *v27; // eax
  int v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  void (__thiscall *v31)(IBrushSurface *, const Vector *, Vector2D *); // edx
  float *v32; // eax
  float *v33; // eax
  int v34; // xmm0_4
  MaterialPrimitiveType_t m_Type; // ebx
  int v36; // eax
  Vector vNextPos; // [esp+Ch] [ebp-24h] BYREF
  Vector2D texCoord; // [esp+18h] [ebp-18h] BYREF
  Vector2D lightCoord; // [esp+20h] [ebp-10h] BYREF
  int v42; // [esp+28h] [ebp-8h]
  int v43; // [esp+2Ch] [ebp-4h]

  pMeshBuilder->m_pMesh = pMesh;
  pMeshBuilder->m_bGenerateIndices = true;
  pMeshBuilder->m_Type = MATERIAL_QUADS;
  ((void (__thiscall *)(IMesh *, int, int, int, int))pMesh->SetPrimitiveType)(a1: pMesh, a2: 2, a3, a4, a5: a2);
  pMeshBuilder->m_pMesh->LockMesh(this: pMeshBuilder->m_pMesh, a2: 4, a3: 6, a4: pMeshBuilder, a5: nullptr);
  pMeshBuilder->m_IndexBuilder.m_pIndexBuffer = &pMesh->IIndexBuffer;
  pMeshBuilder->m_IndexBuilder.m_nIndexCount = 0;
  pMeshBuilder->m_IndexBuilder.m_nMaxIndexCount = 6;
  pMeshBuilder->m_IndexBuilder.m_bModify = false;
  pMeshBuilder->m_IndexBuilder.m_nIndexOffset = pMeshBuilder->m_nFirstVertex;
  pMeshBuilder->m_IndexBuilder.m_pIndices = pMeshBuilder->m_pIndices;
  pMeshBuilder->m_IndexBuilder.m_nIndexSize = pMeshBuilder->m_nIndexSize;
  pMeshBuilder->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &pMeshBuilder->m_VertexBuilder, pMesh, nMaxVertexCount: 4, desc: pMeshBuilder);
  pMeshBuilder->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &pMeshBuilder->m_VertexBuilder);
  pBrushSurface->ComputeTextureCoordinate(this: pBrushSurface, a2: vStartPos, a3: &texCoord);
  pBrushSurface->ComputeLightmapCoordinate(this: pBrushSurface, a2: vStartPos, a3: &lightCoord);
  m_pCurrPosition = pMeshBuilder->m_VertexBuilder.m_pCurrPosition;
  y = vStartPos->y;
  z = vStartPos->z;
  *m_pCurrPosition = vStartPos->x;
  m_pCurrPosition[1] = y;
  m_pCurrPosition[2] = z;
  *(Vector *)pMeshBuilder->m_VertexBuilder.m_pCurrNormal = this->m_vNormal;
  v42 = 1258291261;
  v43 = 1258291289;
  *(_DWORD *)pMeshBuilder->m_VertexBuilder.m_pCurrColor = -9873091;
  *(Vector2D *)pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[1] = lightCoord;
  switch ( nEdge )
  {
    case WIN_SIDE_BOTTOM:
      v17 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      *v17 = 1.0;
      v17[1] = 1.0;
      break;
    case WIN_SIDE_RIGHT:
      v16 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      *v16 = 1.0;
      goto LABEL_6;
    case WIN_SIDE_TOP:
      v16 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      *v16 = 0.0;
LABEL_6:
      v16[1] = 0.0;
      break;
    case WIN_SIDE_LEFT:
      v18 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      *v18 = 0.0;
      v18[1] = 1.0;
      break;
    default:
      break;
  }
  CVertexBuilder::AdvanceVertex(this: &pMeshBuilder->m_VertexBuilder);
  ComputeTextureCoordinate = pBrushSurface->ComputeTextureCoordinate;
  vNextPos.x = vStartPos->x + vWStep->x;
  vNextPos.y = vStartPos->y + vWStep->y;
  vNextPos.z = vWStep->z + vStartPos->z;
  ComputeTextureCoordinate(this: pBrushSurface, a2: &vNextPos, a3: &texCoord);
  pBrushSurface->ComputeLightmapCoordinate(this: pBrushSurface, a2: &vNextPos, a3: &lightCoord);
  *(Vector *)pMeshBuilder->m_VertexBuilder.m_pCurrPosition = vNextPos;
  m_pCurrNormal = pMeshBuilder->m_VertexBuilder.m_pCurrNormal;
  *m_pCurrNormal = this->m_vNormal.x;
  m_pCurrNormal[1] = this->m_vNormal.y;
  m_pCurrNormal[2] = this->m_vNormal.z;
  v42 = 1258291261;
  *(_DWORD *)pMeshBuilder->m_VertexBuilder.m_pCurrColor = -9873091;
  *(Vector2D *)pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[1] = lightCoord;
  switch ( nEdge )
  {
    case WIN_SIDE_BOTTOM:
      v21 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      *v21 = 0.0;
      v22 = 1065353216;
      goto LABEL_12;
    case WIN_SIDE_RIGHT:
      v21 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      v22 = 1065353216;
      *v21 = 1.0;
      goto LABEL_12;
    case WIN_SIDE_TOP:
      v21 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      *v21 = 1.0;
      v22 = 0;
      goto LABEL_12;
    case WIN_SIDE_LEFT:
      v21 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      v22 = 0;
      *v21 = 0.0;
LABEL_12:
      *((_DWORD *)v21 + 1) = v22;
      break;
    default:
      break;
  }
  CVertexBuilder::AdvanceVertex(this: &pMeshBuilder->m_VertexBuilder);
  v23 = vHStep->y + vNextPos.y;
  v24 = vHStep->z + vNextPos.z;
  v25 = pBrushSurface->ComputeTextureCoordinate;
  vNextPos.x = vHStep->x + vNextPos.x;
  vNextPos.y = v23;
  vNextPos.z = v24;
  v25(this: pBrushSurface, a2: &vNextPos, a3: &texCoord);
  pBrushSurface->ComputeLightmapCoordinate(this: pBrushSurface, a2: &vNextPos, a3: &lightCoord);
  *(Vector *)pMeshBuilder->m_VertexBuilder.m_pCurrPosition = vNextPos;
  v26 = pMeshBuilder->m_VertexBuilder.m_pCurrNormal;
  *v26 = this->m_vNormal.x;
  v26[1] = this->m_vNormal.y;
  v26[2] = this->m_vNormal.z;
  *(_DWORD *)pMeshBuilder->m_VertexBuilder.m_pCurrColor = -9873091;
  *(Vector2D *)pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[1] = lightCoord;
  switch ( nEdge )
  {
    case WIN_SIDE_BOTTOM:
      v28 = 0;
      goto LABEL_18;
    case WIN_SIDE_RIGHT:
      v27 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      *v27 = 0.0;
      v28 = 1065353216;
      goto LABEL_19;
    case WIN_SIDE_TOP:
      v28 = 1065353216;
LABEL_18:
      v27 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      *(_DWORD *)v27 = v28;
      goto LABEL_19;
    case WIN_SIDE_LEFT:
      v27 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      *v27 = 1.0;
      v28 = 0;
LABEL_19:
      *((_DWORD *)v27 + 1) = v28;
      break;
    default:
      break;
  }
  CVertexBuilder::AdvanceVertex(this: &pMeshBuilder->m_VertexBuilder);
  v29 = vNextPos.y - vWStep->y;
  v30 = vNextPos.z - vWStep->z;
  v31 = pBrushSurface->ComputeTextureCoordinate;
  vNextPos.x = vNextPos.x - vWStep->x;
  vNextPos.y = v29;
  vNextPos.z = v30;
  v31(this: pBrushSurface, a2: &vNextPos, a3: &texCoord);
  pBrushSurface->ComputeLightmapCoordinate(this: pBrushSurface, a2: &vNextPos, a3: &lightCoord);
  *(Vector *)pMeshBuilder->m_VertexBuilder.m_pCurrPosition = vNextPos;
  v32 = pMeshBuilder->m_VertexBuilder.m_pCurrNormal;
  *v32 = this->m_vNormal.x;
  v32[1] = this->m_vNormal.y;
  v32[2] = this->m_vNormal.z;
  *(_DWORD *)pMeshBuilder->m_VertexBuilder.m_pCurrColor = -9873091;
  *(Vector2D *)pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[1] = lightCoord;
  switch ( nEdge )
  {
    case WIN_SIDE_BOTTOM:
      v33 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      *v33 = 1.0;
      v34 = 0;
      goto LABEL_25;
    case WIN_SIDE_RIGHT:
      v33 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      v34 = 0;
      *v33 = 0.0;
      goto LABEL_25;
    case WIN_SIDE_TOP:
      v33 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      *v33 = 0.0;
      v34 = 1065353216;
      goto LABEL_25;
    case WIN_SIDE_LEFT:
      v33 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
      v34 = 1065353216;
      *v33 = 1.0;
LABEL_25:
      *((_DWORD *)v33 + 1) = v34;
      break;
    default:
      break;
  }
  CVertexBuilder::AdvanceVertex(this: &pMeshBuilder->m_VertexBuilder);
  if ( pMeshBuilder->m_bGenerateIndices )
  {
    m_Type = pMeshBuilder->m_Type;
    v36 = CMeshBuilder::IndicesFromVertices(
            this: pMeshBuilder,
            type: m_Type,
            nVertexCount: pMeshBuilder->m_VertexBuilder.m_nVertexCount);
    CIndexBuilder::GenerateIndices(this: &pMeshBuilder->m_IndexBuilder, primitiveType: m_Type, nIndexCount: v36);
  }
  pMeshBuilder->m_pMesh->UnlockMesh(
    this: pMeshBuilder->m_pMesh,
    a2: pMeshBuilder->m_VertexBuilder.m_nVertexCount,
    a3: pMeshBuilder->m_IndexBuilder.m_nIndexCount,
    a4: pMeshBuilder);
  pMeshBuilder->m_IndexBuilder.m_pIndexBuffer = nullptr;
  pMeshBuilder->m_IndexBuilder.m_nMaxIndexCount = 0;
  pMeshBuilder->m_VertexBuilder.m_nMaxVertexCount = 0;
  pMeshBuilder->m_VertexBuilder.m_pVertexBuffer = nullptr;
  pMeshBuilder->m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  pMeshBuilder->m_pMesh = nullptr;
  pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006D740
// Name: CCBreakableSurfaceProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCBreakableSurfaceProxyFactory()
{
  IMaterialProxy *result; // eax

  result = (IMaterialProxy *)MemAlloc_Alloc(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (IMaterialProxy_vtbl *)&CBreakableSurfaceProxy::`vftable';
  result[1].__vftable = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006D8E0
// Name: private: void C_BreakableSurface::DrawRenderList(class IBrushSurface __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BreakableSurface::DrawRenderList(C_BreakableSurface *this, IBrushSurface *pBrushSurface)
{
  float m_flPanelWidth; // xmm0_4
  float v4; // xmm1_4
  float m_flPanelHeight; // xmm0_4
  IMaterialSystem_vtbl *v6; // edx
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // eax
  int v8; // eax
  int v9; // edi
  unsigned __int16 i; // ax
  UtlLinkedListElem_t<Panel_t,unsigned short> *m_pMemory; // edx
  unsigned int v12; // ebx
  int m_nStyle; // ecx
  UtlLinkedListElem_t<Panel_t,unsigned short> *v14; // eax
  int m_nEdgeType; // eax
  UtlLinkedListElem_t<Panel_t,unsigned short> *v16; // eax
  float m_nHeight; // xmm0_4
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm5_4
  float m_nWidth; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  CMeshBuilder pMeshBuilder; // [esp+0h] [ebp-224h] BYREF
  QAngle vAngles; // [esp+1E8h] [ebp-3Ch] BYREF
  Vector vRenderPos; // [esp+1F4h] [ebp-30h] BYREF
  IMesh *pMesh; // [esp+200h] [ebp-24h]
  int nCurStyle; // [esp+204h] [ebp-20h]
  int nCurEdgeType; // [esp+208h] [ebp-1Ch]
  Vector vWidthStep; // [esp+20Ch] [ebp-18h] BYREF
  Vector vHeightStep; // [esp+218h] [ebp-Ch] BYREF

  vRenderPos.x = this->m_vNormal.x * -1.0;
  vRenderPos.y = this->m_vNormal.y * -1.0;
  vRenderPos.z = this->m_vNormal.z * -1.0;
  VectorAngles(forward: &vRenderPos, angles: &vAngles);
  AngleVectors(angles: &vAngles, forward: nullptr, right: &vWidthStep, up: &vHeightStep);
  m_flPanelWidth = this->m_flPanelWidth;
  vWidthStep.x = vWidthStep.x * m_flPanelWidth;
  vWidthStep.y = vWidthStep.y * m_flPanelWidth;
  v4 = vWidthStep.z * m_flPanelWidth;
  m_flPanelHeight = this->m_flPanelHeight;
  vWidthStep.z = v4;
  vHeightStep.x = m_flPanelHeight * vHeightStep.x;
  vHeightStep.y = vHeightStep.y * m_flPanelHeight;
  vHeightStep.z = vHeightStep.z * m_flPanelHeight;
  CMeshBuilder::CMeshBuilder(this: &pMeshBuilder);
  v6 = materials->__vftable;
  nCurStyle = -1;
  nCurEdgeType = -1;
  GetRenderContext = v6->GetRenderContext;
  pMesh = nullptr;
  v8 = (int)GetRenderContext(this: materials);
  v9 = v8;
  if ( v8 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 8))(a1: v8);
  for ( i = this->m_RenderList.m_Head; i != 0xFFFF; i = this->m_RenderList.m_Memory.m_pMemory[v12].m_Next )
  {
    m_pMemory = this->m_RenderList.m_Memory.m_pMemory;
    v12 = i;
    m_nStyle = m_pMemory[v12].m_Element.m_nStyle;
    v14 = &m_pMemory[v12];
    if ( nCurStyle != m_nStyle || nCurEdgeType != v14->m_Element.m_nEdgeType )
    {
      m_nEdgeType = v14->m_Element.m_nEdgeType;
      nCurStyle = m_pMemory[v12].m_Element.m_nStyle;
      this->m_pCurrentDetailTexture = this->m_pEdge[0][2 * m_nEdgeType + m_nEdgeType + m_nStyle].m_pMaterialEdgeTexture.m_pTexture;
      nCurEdgeType = m_nEdgeType;
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v9 + 16))(a1: v9, a2: 0);
      (*(void (__thiscall **)(int, IMaterial *, IClientRenderable *))(*(_DWORD *)v9 + 36))(
        a1: v9,
        a2: this->m_pCrackedMaterial.m_pMaterial,
        a3: &this->IClientRenderable);
      pMesh = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v9 + 228))(
                         a1: v9,
                         a2: 1,
                         a3: 0,
                         a4: 0,
                         a5: 0);
    }
    v16 = this->m_RenderList.m_Memory.m_pMemory;
    m_nHeight = (float)v16[v12].m_Element.m_nHeight;
    v18 = m_nHeight * vHeightStep.x;
    v19 = vHeightStep.y * m_nHeight;
    v20 = vHeightStep.z * m_nHeight;
    m_nWidth = (float)v16[v12].m_Element.m_nWidth;
    v22 = this->m_vCorner.y + (float)(vWidthStep.y * m_nWidth);
    v23 = (float)(this->m_vCorner.z + (float)(vWidthStep.z * m_nWidth)) + v20;
    vRenderPos.x = (float)(this->m_vCorner.x + (float)(m_nWidth * vWidthStep.x)) + v18;
    vRenderPos.y = v22 + v19;
    vRenderPos.z = v23;
    C_BreakableSurface::DrawOneEdge(
      this,
      pBrushSurface,
      pMesh,
      &pMeshBuilder,
      vStartPos: &vRenderPos,
      vWStep: &vWidthStep,
      vHStep: &vHeightStep,
      nEdge: (WinSide_t)v16[v12].m_Element.m_nSide);
  }
  if ( v9 != 0 )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 12))(a1: v9);
    (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 4))(a1: v9);
  }
  if ( pMeshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && pMeshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: pMeshBuilder.m_VertexBuilder.m_pVertexBuffer) )
  {
    pMeshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: pMeshBuilder.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( pMeshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && pMeshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: pMeshBuilder.m_IndexBuilder.m_pIndexBuffer) )
  {
    pMeshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: pMeshBuilder.m_IndexBuilder.m_pIndexBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006DBB0
// Name: private: void C_BreakableSurface::DrawRenderListHighlights(class IBrushSurface __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BreakableSurface::DrawRenderListHighlights(C_BreakableSurface *this, IBrushSurface *pBrushSurface)
{
  float m_flPanelWidth; // xmm0_4
  float v4; // xmm1_4
  float m_flPanelHeight; // xmm0_4
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // eax
  int m_nStyle; // ebx
  IMatRenderContext *v8; // eax
  IMatRenderContext *m_pObject; // edi
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<Panel_t,unsigned short> *m_pMemory; // edx
  unsigned int v12; // edi
  UtlLinkedListElem_t<Panel_t,unsigned short> *v13; // eax
  UtlLinkedListElem_t<Panel_t,unsigned short> *v14; // ecx
  int m_nHeight; // edx
  UtlLinkedListElem_t<Panel_t,unsigned short> *v16; // eax
  int m_nWidth; // ecx
  float v18; // xmm4_4
  float v19; // xmm5_4
  float v20; // xmm3_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  CMeshBuilder pMeshBuilder; // [esp+0h] [ebp-230h] BYREF
  QAngle vAngles; // [esp+1E8h] [ebp-48h] BYREF
  Vector vRenderPos; // [esp+1F4h] [ebp-3Ch] BYREF
  Vector forward; // [esp+200h] [ebp-30h] BYREF
  IMesh *pMesh; // [esp+20Ch] [ebp-24h]
  CMatRenderContextPtr pRenderContext; // [esp+210h] [ebp-20h]
  int nCurEdgeType; // [esp+214h] [ebp-1Ch]
  Vector vHeightStep; // [esp+218h] [ebp-18h] BYREF
  Vector vWidthStep; // [esp+224h] [ebp-Ch] BYREF

  forward.x = this->m_vNormal.x * -1.0;
  forward.y = this->m_vNormal.y * -1.0;
  forward.z = this->m_vNormal.z * -1.0;
  VectorAngles(&forward, angles: &vAngles);
  AngleVectors(angles: &vAngles, forward: nullptr, right: &vWidthStep, up: &vHeightStep);
  m_flPanelWidth = this->m_flPanelWidth;
  vWidthStep.x = vWidthStep.x * m_flPanelWidth;
  vWidthStep.y = vWidthStep.y * m_flPanelWidth;
  v4 = vWidthStep.z * m_flPanelWidth;
  m_flPanelHeight = this->m_flPanelHeight;
  vWidthStep.z = v4;
  vHeightStep.x = m_flPanelHeight * vHeightStep.x;
  vHeightStep.y = vHeightStep.y * m_flPanelHeight;
  vHeightStep.z = vHeightStep.z * m_flPanelHeight;
  CMeshBuilder::CMeshBuilder(this: &pMeshBuilder);
  GetRenderContext = materials->GetRenderContext;
  m_nStyle = -1;
  pMesh = nullptr;
  nCurEdgeType = -1;
  v8 = GetRenderContext(this: materials);
  m_pObject = v8;
  pRenderContext.m_pObject = v8;
  if ( v8 != nullptr )
    v8->BeginRender(this: v8);
  m_Head = this->m_RenderList.m_Head;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      m_pMemory = this->m_RenderList.m_Memory.m_pMemory;
      v12 = m_Head;
      if ( m_nStyle != m_pMemory[v12].m_Element.m_nStyle || nCurEdgeType != m_pMemory[v12].m_Element.m_nEdgeType )
      {
        v13 = this->m_RenderList.m_Memory.m_pMemory;
        m_nStyle = v13[v12].m_Element.m_nStyle;
        nCurEdgeType = v13[v12].m_Element.m_nEdgeType;
        pMesh = pRenderContext.m_pObject->GetDynamicMesh(
                  this: pRenderContext.m_pObject,
                  a2: 1,
                  a3: 0,
                  a4: 0,
                  a5: this->m_pEdge[0][2 * nCurEdgeType + nCurEdgeType + m_nStyle].m_pMaterialEdge.m_pMaterial);
      }
      v14 = this->m_RenderList.m_Memory.m_pMemory;
      m_nHeight = v14[v12].m_Element.m_nHeight;
      v16 = &v14[v12];
      m_nWidth = v14[v12].m_Element.m_nWidth;
      v18 = this->m_vNormal.y * 0.30000001;
      v19 = this->m_vNormal.z * 0.30000001;
      v20 = this->m_vNormal.x * 0.30000001;
      forward.y = vHeightStep.y * (float)m_nHeight;
      forward.z = vHeightStep.z * (float)m_nHeight;
      v21 = (float)((float)(this->m_vCorner.y + (float)(vWidthStep.y * (float)m_nWidth)) + forward.y) + v18;
      v22 = (float)((float)(this->m_vCorner.z + (float)(vWidthStep.z * (float)m_nWidth)) + forward.z) + v19;
      vRenderPos.x = (float)((float)(this->m_vCorner.x + (float)((float)m_nWidth * vWidthStep.x))
                           + (float)((float)m_nHeight * vHeightStep.x))
                   + v20;
      vRenderPos.y = v21;
      vRenderPos.z = v22;
      C_BreakableSurface::DrawOneHighlight(
        this,
        a2: m_nStyle,
        a3: v12 * 10,
        a4: (int)this,
        pBrushSurface,
        pMesh,
        &pMeshBuilder,
        vStartPos: &vRenderPos,
        vWStep: &vWidthStep,
        vHStep: &vHeightStep,
        nEdge: (WinSide_t)v16->m_Element.m_nSide);
      m_Head = this->m_RenderList.m_Memory.m_pMemory[v12].m_Next;
    }
    while ( m_Head != 0xFFFF );
    m_pObject = pRenderContext.m_pObject;
  }
  if ( m_pObject != nullptr )
  {
    m_pObject->EndRender(this: m_pObject);
    m_pObject->Release(this: m_pObject);
  }
  if ( pMeshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && pMeshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: pMeshBuilder.m_VertexBuilder.m_pVertexBuffer) )
  {
    pMeshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: pMeshBuilder.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( pMeshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && pMeshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: pMeshBuilder.m_IndexBuilder.m_pIndexBuffer) )
  {
    pMeshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: pMeshBuilder.m_IndexBuilder.m_pIndexBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006DEB0
// Name: private: int C_BreakableSurface::FindRenderPanel(int,int,enum WinSide_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BreakableSurface::FindRenderPanel(
        C_BreakableSurface *this,
        int nWidth,
        int nHeight,
        WinSide_t nWinSide)
{
  unsigned __int16 m_Head; // dx
  UtlLinkedListElem_t<Panel_t,unsigned short> *m_pMemory; // ecx
  UtlLinkedListElem_t<Panel_t,unsigned short> *v6; // eax

  m_Head = this->m_RenderList.m_Head;
  if ( m_Head == 0xFFFF )
    return 0xFFFF;
  m_pMemory = this->m_RenderList.m_Memory.m_pMemory;
  while ( 1 )
  {
    v6 = &m_pMemory[m_Head];
    if ( v6->m_Element.m_nSide == nWinSide && v6->m_Element.m_nWidth == nWidth && v6->m_Element.m_nHeight == nHeight )
      break;
    m_Head = v6->m_Next;
    if ( m_Head == 0xFFFF )
      return 0xFFFF;
  }
  return m_Head;
}

//------------------------------------------------------------------------------
// Address: 0x1006DF20
// Name: private: int C_BreakableSurface::FindFirstRenderTexture(enum WinEdge_t,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BreakableSurface::FindFirstRenderTexture(C_BreakableSurface *this, WinEdge_t nEdgeType, int nStyle)
{
  unsigned __int16 m_Head; // dx
  UtlLinkedListElem_t<Panel_t,unsigned short> *m_pMemory; // ecx
  UtlLinkedListElem_t<Panel_t,unsigned short> *v5; // eax

  m_Head = this->m_RenderList.m_Head;
  if ( m_Head == 0xFFFF )
    return 0xFFFF;
  m_pMemory = this->m_RenderList.m_Memory.m_pMemory;
  while ( 1 )
  {
    v5 = &m_pMemory[m_Head];
    if ( v5->m_Element.m_nStyle == nStyle && v5->m_Element.m_nEdgeType == nEdgeType )
      break;
    m_Head = v5->m_Next;
    if ( m_Head == 0xFFFF )
      return 0xFFFF;
  }
  return m_Head;
}

//------------------------------------------------------------------------------
// Address: 0x1006DF90
// Name: public: void C_BreakableSurface::DrawSolidBlocks(class IBrushSurface __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BreakableSurface::DrawSolidBlocks(C_BreakableSurface *this, IBrushSurface *pBrushSurface)
{
  IMatRenderContext *m_pObject; // edi
  float m_flPanelWidth; // xmm0_4
  float z; // edx
  float y; // xmm3_4
  float v7; // xmm1_4
  float m_flPanelHeight; // xmm0_4
  float x; // xmm6_4
  float v10; // xmm4_4
  float v11; // xmm7_4
  __int64 v12; // xmm0_8
  int v13; // ebx
  int v14; // eax
  int v15; // edi
  float v16; // xmm0_4
  float v17; // xmm5_4
  float v18; // xmm6_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm4_4
  int v22; // edi
  float v23; // xmm2_4
  float v24; // xmm3_4
  float v25; // xmm5_4
  CMeshBuilder pMeshBuilder; // [esp+Ch] [ebp-248h] BYREF
  QAngle vAngles; // [esp+1F4h] [ebp-60h] BYREF
  Vector v28; // [esp+200h] [ebp-54h] BYREF
  float v29; // [esp+20Ch] [ebp-48h]
  float v30; // [esp+210h] [ebp-44h]
  CMatRenderContextPtr pRenderContext; // [esp+218h] [ebp-3Ch]
  Vector forward; // [esp+21Ch] [ebp-38h] BYREF
  IMesh *pMesh; // [esp+228h] [ebp-2Ch]
  Vector vCurPos; // [esp+22Ch] [ebp-28h] BYREF
  unsigned __int8 *v35; // [esp+238h] [ebp-1Ch]
  Vector vHeightStep; // [esp+23Ch] [ebp-18h] BYREF
  Vector vWidthStep; // [esp+248h] [ebp-Ch] BYREF

  m_pObject = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  this->m_pCurrentDetailTexture = this->m_pMaterialBoxTexture.m_pTexture;
  m_pObject->Flush(this: m_pObject, a2: false);
  m_pObject->Bind(this: m_pObject, a2: this->m_pCrackedMaterial.m_pMaterial, a3: &this->IClientRenderable);
  pMesh = m_pObject->GetDynamicMesh(this: m_pObject, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  CMeshBuilder::CMeshBuilder(this: &pMeshBuilder);
  forward.x = this->m_vNormal.x * -1.0;
  forward.y = this->m_vNormal.y * -1.0;
  forward.z = this->m_vNormal.z * -1.0;
  VectorAngles(&forward, angles: &vAngles);
  AngleVectors(angles: &vAngles, forward: nullptr, right: &vWidthStep, up: &vHeightStep);
  m_flPanelWidth = this->m_flPanelWidth;
  z = this->m_vCorner.z;
  vWidthStep.x = vWidthStep.x * m_flPanelWidth;
  y = vWidthStep.y * m_flPanelWidth;
  v7 = vWidthStep.z * m_flPanelWidth;
  m_flPanelHeight = this->m_flPanelHeight;
  x = m_flPanelHeight * vHeightStep.x;
  v10 = vHeightStep.y * m_flPanelHeight;
  v11 = vHeightStep.z * m_flPanelHeight;
  v12 = *(_QWORD *)&this->m_vCorner.x;
  v13 = 0;
  vWidthStep.y = y;
  vWidthStep.z = v7;
  vHeightStep.x = x;
  vHeightStep.y = v10;
  vHeightStep.z = v11;
  *(_QWORD *)&vCurPos.x = v12;
  vCurPos.z = z;
  if ( this->m_nNumWide > 0 )
  {
    v35 = this->m_nPanelBits[0];
    do
    {
      v14 = 0;
      v15 = 0;
      if ( this->m_nNumHigh > 0 )
      {
        do
        {
          if ( (v35[v15] & 1) != 0 )
          {
            ++v14;
          }
          else if ( v14 > 0 )
          {
            v16 = (float)(v15 - v14);
            v17 = v16 * x;
            v18 = v16 * v10;
            v19 = (float)((float)v13 * vWidthStep.x) + this->m_vCorner.x;
            v20 = this->m_vCorner.y + (float)((float)v13 * y);
            v21 = (float)(this->m_vCorner.z + (float)((float)v13 * vWidthStep.z)) + (float)(v16 * v11);
            forward.x = (float)v14 * vHeightStep.x;
            vCurPos.x = v19 + v17;
            vCurPos.y = v20 + v18;
            vCurPos.z = v21;
            forward.y = (float)v14 * vHeightStep.y;
            forward.z = (float)v14 * v11;
            C_BreakableSurface::DrawOneBlock(
              this,
              pBrushSurface,
              pMesh,
              &pMeshBuilder,
              &vCurPos,
              &vWidthStep,
              vHeightStep: &forward);
            y = vWidthStep.y;
            v11 = vHeightStep.z;
            v10 = vHeightStep.y;
            x = vHeightStep.x;
            v14 = 0;
          }
          ++v15;
        }
        while ( v15 < this->m_nNumHigh );
        if ( v14 != 0 )
        {
          v22 = v15 - v14;
          v29 = (float)v22 * x;
          v30 = (float)v22 * v10;
          v23 = (float)((float)((float)v13 * vWidthStep.x) + this->m_vCorner.x) + v29;
          v24 = (float)(this->m_vCorner.y + (float)((float)v13 * y)) + v30;
          v25 = (float)(this->m_vCorner.z + (float)((float)v13 * vWidthStep.z)) + (float)((float)v22 * v11);
          v28.x = (float)v14 * x;
          vCurPos.x = v23;
          vCurPos.y = v24;
          vCurPos.z = v25;
          v28.y = (float)v14 * v10;
          v28.z = (float)v14 * v11;
          C_BreakableSurface::DrawOneBlock(
            this,
            pBrushSurface,
            pMesh,
            &pMeshBuilder,
            &vCurPos,
            &vWidthStep,
            vHeightStep: &v28);
          y = vWidthStep.y;
          v11 = vHeightStep.z;
          v10 = vHeightStep.y;
          x = vHeightStep.x;
        }
      }
      v35 += 16;
      ++v13;
    }
    while ( v13 < this->m_nNumWide );
    m_pObject = pRenderContext.m_pObject;
  }
  if ( pMeshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && pMeshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: pMeshBuilder.m_VertexBuilder.m_pVertexBuffer) )
  {
    pMeshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: pMeshBuilder.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( pMeshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && pMeshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: pMeshBuilder.m_IndexBuilder.m_pIndexBuffer) )
  {
    pMeshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: pMeshBuilder.m_IndexBuilder.m_pIndexBuffer);
  }
  m_pObject->EndRender(this: m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x1006E360
// Name: public: C_BreakableSurface::C_BreakableSurface(void)
// Source: json
//------------------------------------------------------------------------------
C_BreakableSurface *__thiscall C_BreakableSurface::C_BreakableSurface(C_BreakableSurface *this)
{
  UtlLinkedListElem_t<Panel_t,unsigned short> *m_pMemory; // eax
  int v3; // ebx
  CTextureReference *p_m_pMaterialEdgeTexture; // edi

  C_BaseEntity::C_BaseEntity(this);
  this->IBrushRenderer::__vftable = (IBrushRenderer_vtbl *)&IBrushRenderer::`vftable';
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BreakableSurface_vtbl *)&C_BreakableSurface::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_BreakableSurface::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_BreakableSurface::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_BreakableSurface::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_BreakableSurface::`vftable'{for `C_BaseEntity'};
  this->IBrushRenderer::__vftable = (IBrushRenderer_vtbl *)&C_BreakableSurface::`vftable'{for `IBrushRenderer'};
  this->m_RenderList.m_Memory.m_pMemory = nullptr;
  this->m_RenderList.m_Memory.m_nAllocationCount = 0;
  this->m_RenderList.m_Memory.m_nGrowSize = 0;
  this->m_RenderList.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_RenderList.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_RenderList.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_RenderList.m_Head = -1;
  this->m_RenderList.m_NumAlloced = 0;
  this->m_RenderList.m_pElements = m_pMemory;
  CMaterialReference::CMaterialReference(
    this: &this->m_pMaterialBox,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_pSolid.m_pMaterialEdge,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CTextureReference::CTextureReference(this: &this->m_pSolid.m_pMaterialEdgeTexture);
  v3 = 11;
  p_m_pMaterialEdgeTexture = &this->m_pEdge[0][0].m_pMaterialEdgeTexture;
  do
  {
    CMaterialReference::CMaterialReference(
      this: (CMaterialReference *)&p_m_pMaterialEdgeTexture[-1],
      pMaterialName: nullptr,
      pTextureGroupName: nullptr,
      bComplain: true);
    CTextureReference::CTextureReference(this: p_m_pMaterialEdgeTexture);
    p_m_pMaterialEdgeTexture += 4;
    --v3;
  }
  while ( v3 >= 0 );
  CMaterialReference::CMaterialReference(
    this: &this->m_pCrackedMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CTextureReference::CTextureReference(this: &this->m_pMaterialBoxTexture);
  this->m_vNormal.x = 0.0;
  this->m_vNormal.y = 0.0;
  this->m_vNormal.z = 0.0;
  this->m_vCorner.x = 0.0;
  this->m_vCorner.y = 0.0;
  this->m_vCorner.z = 0.0;
  this->m_bIsBroken = false;
  this->m_pCurrentDetailTexture = nullptr;
  _V_memset(dest: this->m_PrevRawPanelBitVec, fill: 255, count: 256);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006E4C0
// Name: public: virtual C_BreakableSurface::~C_BreakableSurface(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BreakableSurface::~C_BreakableSurface(C_BreakableSurface *this)
{
  int v2; // ebx
  C_BreakableSurface *v3; // edi

  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BreakableSurface_vtbl *)&C_BreakableSurface::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_BreakableSurface::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_BreakableSurface::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_BreakableSurface::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_BreakableSurface::`vftable'{for `C_BaseEntity'};
  this->IBrushRenderer::__vftable = (IBrushRenderer_vtbl *)&C_BreakableSurface::`vftable'{for `IBrushRenderer'};
  CTextureReference::~CTextureReference(this: &this->m_pMaterialBoxTexture);
  CMaterialReference::~CMaterialReference(this: &this->m_pCrackedMaterial);
  v2 = 11;
  v3 = this + 1;
  do
  {
    v3 = (C_BreakableSurface *)((char *)v3 - 16);
    CTextureReference::~CTextureReference(this: (CTextureReference *)&v3->IClientRenderable);
    CMaterialReference::~CMaterialReference(this: (CMaterialReference *)v3);
    --v2;
  }
  while ( v2 >= 0 );
  CTextureReference::~CTextureReference(this: &this->m_pSolid.m_pMaterialEdgeTexture);
  CMaterialReference::~CMaterialReference(this: &this->m_pSolid.m_pMaterialEdge);
  CMaterialReference::~CMaterialReference(this: &this->m_pMaterialBox);
  CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *)&this->m_RenderList);
  if ( this->m_RenderList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_RenderList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_RenderList.m_Memory.m_pMemory);
      this->m_RenderList.m_Memory.m_pMemory = nullptr;
    }
    this->m_RenderList.m_Memory.m_nAllocationCount = 0;
  }
  C_BaseEntity::~C_BaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x1006E5A0
// Name: public: virtual bool C_BreakableSurface::RenderBrushModelSurface(class IClientEntity __near *,class IBrushSurface __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_BreakableSurface::RenderBrushModelSurface(
        C_BreakableSurface *this,
        IClientEntity *pBaseEntity,
        IBrushSurface *pBrushSurface)
{
  if ( this->m_VarMap.m_Entries.m_pElements == (VarMapEntry_t *)1 )
    C_BreakableSurface::DrawRenderListHighlights(this: (C_BreakableSurface *)((char *)this - 2432), pBrushSurface);
  C_BreakableSurface::DrawSolidBlocks(this: (C_BreakableSurface *)((char *)this - 2432), pBrushSurface);
  C_BreakableSurface::DrawRenderList(this: (C_BreakableSurface *)((char *)this - 2432), pBrushSurface);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1006E780
// Name: private: void C_BreakableSurface::AddToRenderList(int,int,enum WinSide_t,enum WinEdge_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BreakableSurface::AddToRenderList(
        C_BreakableSurface *this,
        int nWidth,
        int nHeight,
        WinSide_t nSide,
        WinEdge_t nEdgeType,
        int forceStyle)
{
  unsigned __int16 RenderPanel; // ax
  unsigned __int16 v8; // di
  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *p_m_RenderList; // esi
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // ecx
  int v11; // eax
  int m_Count_low; // ebx
  unsigned __int16 FirstRenderTexture; // ax
  unsigned __int16 v14; // di
  bool v15; // zf
  int v16; // eax
  unsigned __int16 v17; // ax
  unsigned __int16 v18; // ax
  unsigned __int16 v19; // ax
  unsigned __int16 v20; // di
  int v21; // eax
  int v22; // [esp+Ch] [ebp-8h]
  unsigned __int16 forceStylea; // [esp+2Ch] [ebp+18h]

  RenderPanel = C_BreakableSurface::FindRenderPanel(this, nWidth, nHeight, nWinSide: nSide);
  v8 = RenderPanel;
  p_m_RenderList = (CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *)&this->m_RenderList;
  if ( RenderPanel >= p_m_RenderList->m_Memory.m_nAllocationCount
    || RenderPanel > p_m_RenderList->m_LastAlloc.index
    || (m_pMemory = p_m_RenderList->m_Memory.m_pMemory,
        v11 = RenderPanel,
        v22 = v11 * 10,
        p_m_RenderList->m_Memory.m_pMemory[v11].m_Previous == v8)
    && m_pMemory[v11].m_Next != v8 )
  {
    m_Count_low = random->RandomInt(this: random, a2: 0, a3: 2);
  }
  else
  {
    m_Count_low = SLOBYTE(m_pMemory[v11].m_Element.m_Count);
    CUtlLinkedList<Panel_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<Panel_t,unsigned short>,unsigned short>>::Unlink(
      this: p_m_RenderList,
      elem: v8);
    *(unsigned __int16 *)((char *)&p_m_RenderList->m_Memory.m_pMemory->m_Next + v22) = p_m_RenderList->m_FirstFree;
    p_m_RenderList->m_FirstFree = v8;
  }
  if ( forceStyle != -1 )
    m_Count_low = forceStyle;
  if ( nEdgeType != EDGE_NOT )
  {
    FirstRenderTexture = C_BreakableSurface::FindFirstRenderTexture(this, nEdgeType, nStyle: m_Count_low);
    v14 = FirstRenderTexture;
    if ( FirstRenderTexture >= p_m_RenderList->m_Memory.m_nAllocationCount
      || FirstRenderTexture > p_m_RenderList->m_LastAlloc.index
      || (v15 = p_m_RenderList->m_Memory.m_pMemory[FirstRenderTexture].m_Previous == FirstRenderTexture,
          v16 = (int)&p_m_RenderList->m_Memory.m_pMemory[FirstRenderTexture],
          v15)
      && *(_WORD *)(v16 + 8) != v14 )
    {
      v19 = CUtlLinkedList<Panel_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<Panel_t,unsigned short>,unsigned short>>::AllocInternal(
              this: (CUtlLinkedList<Panel_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<Panel_t,unsigned short>,unsigned short> > *)p_m_RenderList,
              multilist: false);
      v20 = v19;
      if ( v19 == 0xFFFF )
      {
        v18 = -1;
      }
      else
      {
        CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
          this: p_m_RenderList,
          before: 0xFFFFu,
          elem: v19);
        v18 = v20;
      }
    }
    else
    {
      v17 = CUtlLinkedList<Panel_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<Panel_t,unsigned short>,unsigned short>>::AllocInternal(
              this: (CUtlLinkedList<Panel_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<Panel_t,unsigned short>,unsigned short> > *)p_m_RenderList,
              multilist: false);
      forceStylea = v17;
      if ( v17 == 0xFFFF )
      {
        v18 = -1;
      }
      else
      {
        CUtlLinkedList<Panel_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<Panel_t,unsigned short>,unsigned short>>::LinkAfter(
          this: (CUtlLinkedList<Panel_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<Panel_t,unsigned short>,unsigned short> > *)p_m_RenderList,
          after: v14,
          elem: v17);
        v18 = forceStylea;
      }
    }
    v21 = v18;
    HIBYTE(p_m_RenderList->m_Memory.m_pMemory[v21].m_Element.m_Head) = nHeight;
    LOBYTE(p_m_RenderList->m_Memory.m_pMemory[v21].m_Element.m_Head) = nWidth;
    HIBYTE(p_m_RenderList->m_Memory.m_pMemory[v21].m_Element.m_Tail) = nEdgeType;
    LOBYTE(p_m_RenderList->m_Memory.m_pMemory[v21].m_Element.m_Tail) = nSide;
    LOBYTE(p_m_RenderList->m_Memory.m_pMemory[v21].m_Element.m_Count) = m_Count_low;
    this->m_nPanelBits[nWidth][nHeight] = (4 * m_Count_low) | this->m_nPanelBits[nWidth][nHeight] & 0xF0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006E910
// Name: private: void C_BreakableSurface::UpdateEdgeType(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BreakableSurface::UpdateEdgeType(C_BreakableSurface *this, int nWidth, int nHeight, int forceStyle)
{
  int v6; // ecx
  unsigned __int8 *v7; // edx
  int m_nNumWide; // edx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // edi
  int v13; // ecx
  char v14; // dl
  int v15; // ecx
  int v16; // ecx
  int v17; // eax
  bool v18; // cl
  bool v19; // al
  int v20; // edi
  bool v21; // cl
  bool v22; // al
  bool v23; // cl
  bool v24; // al
  bool v25; // cl
  bool v26; // al
  WinEdge_t v27; // [esp-Ch] [ebp-1Ch]
  WinEdge_t v28; // [esp-Ch] [ebp-1Ch]
  bool bDownRight; // [esp+9h] [ebp-7h]
  bool bUpRight; // [esp+Ah] [ebp-6h]
  bool bDownLeft; // [esp+Bh] [ebp-5h]
  bool bUpLeft; // [esp+Ch] [ebp-4h]
  bool bDown; // [esp+Dh] [ebp-3h]
  bool bUp; // [esp+Eh] [ebp-2h]
  bool bRight; // [esp+Fh] [ebp-1h]
  char bLeft_3; // [esp+1Fh] [ebp+Fh]

  if ( nWidth < this->m_nNumWide && nHeight < this->m_nNumHigh && nWidth >= 0 && nHeight >= 0 )
  {
    v6 = nWidth;
    v7 = &this->m_nPanelBits[nWidth][nHeight];
    if ( (*v7 & 1) == 0 )
    {
      *v7 &= ~2u;
      m_nNumWide = this->m_nNumWide;
      v9 = nHeight + 1;
      if ( nWidth < m_nNumWide && v9 < this->m_nNumHigh && v9 >= 0 )
        bUp = this->m_nPanelBits[v6][v9] & 1;
      else
        bUp = true;
      v10 = nHeight - 1;
      if ( nWidth < m_nNumWide && v10 < this->m_nNumHigh && v10 >= 0 )
        bDown = this->m_nPanelBits[v6][v10] & 1;
      else
        bDown = true;
      v11 = nWidth - 1;
      if ( nWidth - 1 < m_nNumWide && nHeight < this->m_nNumHigh && v11 >= 0 )
        bLeft_3 = this->m_nPanelBits[v11][nHeight] & 1;
      else
        bLeft_3 = 1;
      v12 = nWidth + 1;
      if ( nWidth + 1 < m_nNumWide && nHeight < this->m_nNumHigh && v12 >= 0 )
        bRight = this->m_nPanelBits[v12][nHeight] & 1;
      else
        bRight = true;
      if ( v11 < m_nNumWide && (v13 = nHeight + 1, nHeight + 1 < this->m_nNumHigh) && v11 >= 0 && v13 >= 0 )
        v14 = this->m_nPanelBits[v11][v13] & 1;
      else
        v14 = 1;
      bUpLeft = v14;
      if ( v12 < this->m_nNumWide && (v15 = nHeight + 1, nHeight + 1 < this->m_nNumHigh) && v12 >= 0 && v15 >= 0 )
        bUpRight = this->m_nPanelBits[v12][v15] & 1;
      else
        bUpRight = true;
      if ( v11 < this->m_nNumWide && (v16 = nHeight - 1, nHeight - 1 < this->m_nNumHigh) && v11 >= 0 && v16 >= 0 )
        bDownLeft = this->m_nPanelBits[v11][v16] & 1;
      else
        bDownLeft = true;
      if ( v12 < this->m_nNumWide && (v17 = nHeight - 1, nHeight - 1 < this->m_nNumHigh) && v12 >= 0 && v17 >= 0 )
        bDownRight = this->m_nPanelBits[v12][v17] & 1;
      else
        bDownRight = true;
      if ( bUp )
      {
        v18 = bLeft_3 == 0 && v14 != 0;
        v19 = !bRight && bUpRight;
        v20 = forceStyle;
        if ( v18 )
        {
          if ( v19 )
            C_BreakableSurface::AddToRenderList(
              this,
              nWidth,
              nHeight,
              nSide: WIN_SIDE_TOP,
              nEdgeType: EDGE_FULL,
              forceStyle);
          else
            C_BreakableSurface::AddToRenderList(
              this,
              nWidth,
              nHeight,
              nSide: WIN_SIDE_TOP,
              nEdgeType: EDGE_LEFT,
              forceStyle);
        }
        else
        {
          if ( v19 )
            v27 = EDGE_RIGHT;
          else
            v27 = EDGE_NONE;
          C_BreakableSurface::AddToRenderList(this, nWidth, nHeight, nSide: WIN_SIDE_TOP, nEdgeType: v27, forceStyle);
        }
      }
      else
      {
        v20 = forceStyle;
        C_BreakableSurface::AddToRenderList(this, nWidth, nHeight, nSide: WIN_SIDE_TOP, nEdgeType: EDGE_NOT, forceStyle);
      }
      if ( bDown )
      {
        v21 = bLeft_3 == 0 && bDownLeft;
        v22 = !bRight && bDownRight;
        if ( v21 )
        {
          if ( v22 )
            C_BreakableSurface::AddToRenderList(
              this,
              nWidth,
              nHeight,
              nSide: WIN_SIDE_BOTTOM,
              nEdgeType: EDGE_FULL,
              forceStyle: v20);
          else
            C_BreakableSurface::AddToRenderList(
              this,
              nWidth,
              nHeight,
              nSide: WIN_SIDE_BOTTOM,
              nEdgeType: EDGE_RIGHT,
              forceStyle: v20);
        }
        else
        {
          if ( v22 )
            v28 = EDGE_LEFT;
          else
            v28 = EDGE_NONE;
          C_BreakableSurface::AddToRenderList(
            this,
            nWidth,
            nHeight,
            nSide: WIN_SIDE_BOTTOM,
            nEdgeType: v28,
            forceStyle: v20);
        }
      }
      else
      {
        C_BreakableSurface::AddToRenderList(
          this,
          nWidth,
          nHeight,
          nSide: WIN_SIDE_BOTTOM,
          nEdgeType: EDGE_NOT,
          forceStyle: v20);
      }
      if ( bLeft_3 != 0 )
      {
        v23 = !bUp && bUpLeft;
        v24 = !bDown && bDownLeft;
        if ( v23 )
        {
          if ( v24 )
            C_BreakableSurface::AddToRenderList(
              this,
              nWidth,
              nHeight,
              nSide: WIN_SIDE_LEFT,
              nEdgeType: EDGE_FULL,
              forceStyle: v20);
          else
            C_BreakableSurface::AddToRenderList(
              this,
              nWidth,
              nHeight,
              nSide: WIN_SIDE_LEFT,
              nEdgeType: EDGE_RIGHT,
              forceStyle: v20);
        }
        else if ( v24 )
        {
          C_BreakableSurface::AddToRenderList(
            this,
            nWidth,
            nHeight,
            nSide: WIN_SIDE_LEFT,
            nEdgeType: EDGE_LEFT,
            forceStyle: v20);
        }
        else
        {
          C_BreakableSurface::AddToRenderList(
            this,
            nWidth,
            nHeight,
            nSide: WIN_SIDE_LEFT,
            nEdgeType: EDGE_NONE,
            forceStyle: v20);
        }
      }
      else
      {
        C_BreakableSurface::AddToRenderList(
          this,
          nWidth,
          nHeight,
          nSide: WIN_SIDE_LEFT,
          nEdgeType: EDGE_NOT,
          forceStyle: v20);
      }
      if ( bRight )
      {
        v25 = !bUp && bUpRight;
        v26 = !bDown && bDownRight;
        if ( v25 )
        {
          if ( v26 )
            C_BreakableSurface::AddToRenderList(
              this,
              nWidth,
              nHeight,
              nSide: WIN_SIDE_RIGHT,
              nEdgeType: EDGE_FULL,
              forceStyle: v20);
          else
            C_BreakableSurface::AddToRenderList(
              this,
              nWidth,
              nHeight,
              nSide: WIN_SIDE_RIGHT,
              nEdgeType: EDGE_LEFT,
              forceStyle: v20);
        }
        else if ( v26 )
        {
          C_BreakableSurface::AddToRenderList(
            this,
            nWidth,
            nHeight,
            nSide: WIN_SIDE_RIGHT,
            nEdgeType: EDGE_RIGHT,
            forceStyle: v20);
        }
        else
        {
          C_BreakableSurface::AddToRenderList(
            this,
            nWidth,
            nHeight,
            nSide: WIN_SIDE_RIGHT,
            nEdgeType: EDGE_NONE,
            forceStyle: v20);
        }
      }
      else
      {
        C_BreakableSurface::AddToRenderList(
          this,
          nWidth,
          nHeight,
          nSide: WIN_SIDE_RIGHT,
          nEdgeType: EDGE_NOT,
          forceStyle: v20);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006ECD0
// Name: public: virtual void C_BreakableSurface::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BreakableSurface::OnRestore(C_BreakableSurface *this)
{
  int v2; // edx
  unsigned __int8 *v3; // edi
  int i; // esi
  unsigned __int8 v5; // al
  unsigned __int8 v6; // al
  int w; // [esp+4h] [ebp-4h]

  C_BaseEntity::OnRestore(this);
  v2 = 0;
  w = 0;
  if ( this->m_nNumWide > 0 )
  {
    v3 = this->m_nPanelBits[0];
    do
    {
      for ( i = 0; i < this->m_nNumHigh; ++i )
      {
        v5 = v3[i];
        if ( v2 < this->m_nNumWide )
        {
          v2 = w;
          if ( i < this->m_nNumHigh && w >= 0 && i >= 0 )
          {
            if ( (v3[i] & 1) != 0 )
              v6 = v5 | 1;
            else
              v6 = v5 & 0xFE;
            v3[i] = v6;
          }
          if ( w < this->m_nNumWide && i < this->m_nNumHigh && w >= 0 && i >= 0 )
            v3[i] |= 2u;
        }
        C_BreakableSurface::UpdateEdgeType(this, nWidth: v2, nHeight: i, forceStyle: (v3[i] >> 2) & 3);
        v2 = w;
      }
      ++v2;
      v3 += 16;
      w = v2;
    }
    while ( v2 < this->m_nNumWide );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006ED90
// Name: public: virtual void C_BreakableSurface::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BreakableSurface::OnDataChanged(C_BreakableSurface *this, bool *updateType)
{
  DataUpdateType_t v2; // ebx
  C_BreakableSurface *v3; // edi
  C_BreakableSurface *v4; // esi
  int (__thiscall ***v5)(_DWORD); // eax
  ITexture *v6; // eax
  C_BreakableSurface *v7; // ecx
  int v8; // ecx
  int v9; // eax
  int v10; // edi
  int v11; // ebx
  int v12; // eax
  char v13; // cl
  int v14; // ecx
  int v15; // edx
  int v16; // ebx
  int v17; // eax
  int v18; // ebx
  C_BreakableSurface *v19; // eax
  int i; // edi
  int v22; // [esp+14h] [ebp-Ch]
  int j; // [esp+18h] [ebp-8h]
  unsigned __int8 *v24; // [esp+1Ch] [ebp-4h]

  v2 = (DataUpdateType_t)updateType;
  v3 = this;
  C_BaseEntity::OnDataChanged(this, type: (DataUpdateType_t)updateType);
  v4 = (C_BreakableSurface *)((char *)v3 - 8);
  C_BaseEntity::OnTranslucencyTypeChanged(this: (C_BreakableSurface *)((char *)v3 - 8));
  if ( v2 == DATA_UPDATE_CREATED )
  {
    C_BreakableSurface::FindCrackedMaterial(this: (C_BreakableSurface *)((char *)v3 - 8));
    CMaterialReference::Init(
      this: (CMaterialReference *)&v3->m_nPanelBits[15][8],
      pMaterialName: "models/brokenglass/glassbroken_solid",
      pTextureGroupName: "Model textures",
      bComplain: true);
    v5 = (int (__thiscall ***)(_DWORD))(*(int (__thiscall **)(_DWORD, const char *, char *, _DWORD))(**(_DWORD **)&v3->m_nPanelBits[15][8] + 44))(
                                         a1: *(_DWORD *)&v3->m_nPanelBits[15][8],
                                         a2: "$basetexture",
                                         a3: (char *)&updateType + 3,
                                         a4: 0);
    if ( HIBYTE(updateType) != 0 )
      v6 = (ITexture *)(**v5)(a1: v5);
    else
      v6 = nullptr;
    CTextureReference::Init(this: &v3->m_pEdge[3][2].m_pMaterialEdgeTexture, pTexture: v6);
    v7 = (C_BreakableSurface *)((char *)v3 - 8);
    if ( LODWORD(v3->m_vCorner.z) == 1 )
    {
      C_BreakableSurface::InitMaterial(
        this: v7,
        nEdgeType: EDGE_NONE,
        nEdgeStyle: 0,
        pMaterialName: "models/brokentile/tilebroken_03a");
      C_BreakableSurface::InitMaterial(
        this: (C_BreakableSurface *)((char *)v3 - 8),
        nEdgeType: EDGE_FULL,
        nEdgeStyle: 0,
        pMaterialName: "models/brokentile/tilebroken_03b");
      C_BreakableSurface::InitMaterial(
        this: (C_BreakableSurface *)((char *)v3 - 8),
        nEdgeType: EDGE_LEFT,
        nEdgeStyle: 0,
        pMaterialName: "models/brokentile/tilebroken_03c");
      C_BreakableSurface::InitMaterial(
        this: (C_BreakableSurface *)((char *)v3 - 8),
        nEdgeType: EDGE_RIGHT,
        nEdgeStyle: 0,
        pMaterialName: "models/brokentile/tilebroken_03d");
      C_BreakableSurface::InitMaterial(
        this: (C_BreakableSurface *)((char *)v3 - 8),
        nEdgeType: EDGE_NONE,
        nEdgeStyle: 1,
        pMaterialName: "models/brokentile/tilebroken_02a");
      C_BreakableSurface::InitMaterial(
        this: (C_BreakableSurface *)((char *)v3 - 8),
        nEdgeType: EDGE_FULL,
        nEdgeStyle: 1,
        pMaterialName: "models/brokentile/tilebroken_02b");
      C_BreakableSurface::InitMaterial(
        this: (C_BreakableSurface *)((char *)v3 - 8),
        nEdgeType: EDGE_LEFT,
        nEdgeStyle: 1,
        pMaterialName: "models/brokentile/tilebroken_02c");
      C_BreakableSurface::InitMaterial(
        this: (C_BreakableSurface *)((char *)v3 - 8),
        nEdgeType: EDGE_RIGHT,
        nEdgeStyle: 1,
        pMaterialName: "models/brokentile/tilebroken_02d");
      C_BreakableSurface::InitMaterial(
        this: (C_BreakableSurface *)((char *)v3 - 8),
        nEdgeType: EDGE_NONE,
        nEdgeStyle: 2,
        pMaterialName: "models/brokentile/tilebroken_01a");
      C_BreakableSurface::InitMaterial(
        this: (C_BreakableSurface *)((char *)v3 - 8),
        nEdgeType: EDGE_FULL,
        nEdgeStyle: 2,
        pMaterialName: "models/brokentile/tilebroken_01b");
      C_BreakableSurface::InitMaterial(
        this: (C_BreakableSurface *)((char *)v3 - 8),
        nEdgeType: EDGE_LEFT,
        nEdgeStyle: 2,
        pMaterialName: "models/brokentile/tilebroken_01c");
      C_BreakableSurface::InitMaterial(
        this: (C_BreakableSurface *)((char *)v3 - 8),
        nEdgeType: EDGE_RIGHT,
        nEdgeStyle: 2,
        pMaterialName: "models/brokentile/tilebroken_01d");
    }
    else
    {
      C_BreakableSurface::InitMaterial(
        this: v7,
        nEdgeType: EDGE_NONE,
        nEdgeStyle: 0,
        pMaterialName: "models/brokenglass/glassbroken_03a");
      C_BreakableSurface::InitMaterial(
        this: (C_BreakableSurface *)((char *)v3 - 8),
        nEdgeType: EDGE_FULL,
        nEdgeStyle: 0,
        pMaterialName: "models/brokenglass/glassbroken_03b");
      C_BreakableSurface::InitMaterial(
        this: (C_BreakableSurface *)((char *)v3 - 8),
        nEdgeType: EDGE_LEFT,
        nEdgeStyle: 0,
        pMaterialName: "models/brokenglass/glassbroken_03c");
      C_BreakableSurface::InitMaterial(
        this: (C_BreakableSurface *)((char *)v3 - 8),
        nEdgeType: EDGE_RIGHT,
        nEdgeStyle: 0,
        pMaterialName: "models/brokenglass/glassbroken_03d");
      C_BreakableSurface::InitMaterial(
        this: (C_BreakableSurface *)((char *)v3 - 8),
        nEdgeType: EDGE_NONE,
        nEdgeStyle: 1,
        pMaterialName: "models/brokenglass/glassbroken_02a");
      C_BreakableSurface::InitMaterial(
        this: (C_BreakableSurface *)((char *)v3 - 8),
        nEdgeType: EDGE_FULL,
        nEdgeStyle: 1,
        pMaterialName: "models/brokenglass/glassbroken_02b");
      C_BreakableSurface::InitMaterial(
        this: (C_BreakableSurface *)((char *)v3 - 8),
        nEdgeType: EDGE_LEFT,
        nEdgeStyle: 1,
        pMaterialName: "models/brokenglass/glassbroken_02c");
      C_BreakableSurface::InitMaterial(
        this: (C_BreakableSurface *)((char *)v3 - 8),
        nEdgeType: EDGE_RIGHT,
        nEdgeStyle: 1,
        pMaterialName: "models/brokenglass/glassbroken_02d");
      C_BreakableSurface::InitMaterial(
        this: (C_BreakableSurface *)((char *)v3 - 8),
        nEdgeType: EDGE_NONE,
        nEdgeStyle: 2,
        pMaterialName: "models/brokenglass/glassbroken_01a");
      C_BreakableSurface::InitMaterial(
        this: (C_BreakableSurface *)((char *)v3 - 8),
        nEdgeType: EDGE_FULL,
        nEdgeStyle: 2,
        pMaterialName: "models/brokenglass/glassbroken_01b");
      C_BreakableSurface::InitMaterial(
        this: (C_BreakableSurface *)((char *)v3 - 8),
        nEdgeType: EDGE_LEFT,
        nEdgeStyle: 2,
        pMaterialName: "models/brokenglass/glassbroken_01c");
      C_BreakableSurface::InitMaterial(
        this: (C_BreakableSurface *)((char *)v3 - 8),
        nEdgeType: EDGE_RIGHT,
        nEdgeStyle: 2,
        pMaterialName: "models/brokenglass/glassbroken_01d");
    }
  }
  v8 = 0;
  HIBYTE(updateType) = 0;
  j = 0;
  if ( (int)v3->IBrushRenderer::__vftable > 0 )
  {
    while ( 1 )
    {
      v9 = *((_DWORD *)&v3->m_bIsBlurred + 1);
      if ( v9 <= 0 )
        goto LABEL_70;
      v22 = -1;
      v10 = -1;
      v24 = &v4->m_nPanelBits[0][v8];
      while ( 1 )
      {
        v11 = v22 + 1;
        v12 = v22 + 1 + v8 * v9;
        v13 = *((_BYTE *)&this->m_RenderList.m_NumAlloced + v12);
        if ( v13 != this->m_RawPanelBitVec.m_Value[v12 + 248] )
          HIBYTE(updateType) = 1;
        if ( v11 >= v4->m_nNumWide || j >= v4->m_nNumHigh || v11 < 0 || j < 0 )
          goto LABEL_20;
        if ( v13 != 0 )
        {
          *v24 |= 1u;
LABEL_20:
          if ( v13 != 0 )
            goto LABEL_68;
          goto LABEL_21;
        }
        *v24 &= ~1u;
LABEL_21:
        if ( HIBYTE(updateType) != 0 )
        {
          if ( v11 < v4->m_nNumWide && j < v4->m_nNumHigh && v11 >= 0 && j >= 0 )
            *v24 |= 2u;
          v14 = j + 1;
          if ( v11 < v4->m_nNumWide && v14 < v4->m_nNumHigh && v11 >= 0 && v14 >= 0 )
            v4->m_nPanelBits[v10 + 1][v14] |= 2u;
          v15 = j - 1;
          if ( v11 < v4->m_nNumWide && v15 < v4->m_nNumHigh && v11 >= 0 && v15 >= 0 )
            v4->m_nPanelBits[v10 + 1][v15] |= 2u;
          if ( v22 < v4->m_nNumWide && j < v4->m_nNumHigh && v22 >= 0 && j >= 0 )
            *(v24 - 16) |= 2u;
          v16 = v22 + 2;
          if ( v22 + 2 < v4->m_nNumWide )
          {
            if ( j < v4->m_nNumHigh && v16 >= 0 && j >= 0 )
              v24[16] |= 2u;
            if ( v16 < v4->m_nNumWide && v14 < v4->m_nNumHigh && v16 >= 0 && v14 >= 0 )
              v4->m_nPanelBits[v10 + 2][v14] |= 2u;
          }
          v17 = v22;
          if ( v22 < v4->m_nNumWide && v14 < v4->m_nNumHigh && v22 >= 0 && v14 >= 0 )
          {
            v4->m_nPanelBits[v10][v14] |= 2u;
            v17 = v22;
          }
          if ( v16 < v4->m_nNumWide && v15 < v4->m_nNumHigh && v16 >= 0 && v15 >= 0 )
          {
            v4->m_nPanelBits[v10 + 2][v15] |= 2u;
            v17 = v22;
          }
          if ( v17 < v4->m_nNumWide && v15 < v4->m_nNumHigh && v17 >= 0 && v15 >= 0 )
            v4->m_nPanelBits[v10][v15] |= 2u;
          v11 = v22 + 1;
        }
LABEL_68:
        v9 = *((_DWORD *)&this->m_bIsBlurred + 1);
        v24 += 16;
        v22 = v11;
        ++v10;
        if ( v11 + 1 >= v9 )
          break;
        v8 = j;
      }
      v3 = this;
      v8 = j;
LABEL_70:
      j = ++v8;
      if ( v8 >= (int)v3->IBrushRenderer::__vftable )
      {
        if ( HIBYTE(updateType) != 0 )
        {
          v18 = 0;
          if ( *((int *)&v3->m_bIsBlurred + 1) > 0 )
          {
            updateType = &v3->m_PrevRawPanelBitVec[248];
            do
            {
              v19 = this;
              for ( i = 0; i < (int)v19->IBrushRenderer::__vftable; ++i )
              {
                if ( (updateType[i] & 2) != 0 )
                {
                  C_BreakableSurface::UpdateEdgeType(this: v4, nWidth: v18, nHeight: i, forceStyle: -1);
                  v19 = this;
                }
              }
              updateType += 16;
              ++v18;
            }
            while ( v18 < *((_DWORD *)&v19->m_bIsBlurred + 1) );
            v3 = this;
          }
        }
        break;
      }
    }
  }
  _V_memcpy(dest: &v3->m_RawPanelBitVec.m_Value[248], src: &v3->m_RenderList.m_NumAlloced, count: 256);
}

//------------------------------------------------------------------------------
// Address: 0x10411FC0
// Name: C_BreakableSurface_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *C_BreakableSurface_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<C_BreakableSurface>();
  C_BreakableSurface_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10411FF0
// Name: DT_BreakableSurface::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BreakableSurface::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_BreakableSurface::g_RecvTable);
  return atexit(func: DT_BreakableSurface::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412010
// Name: DT_BreakableSurface::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BreakableSurface::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_BreakableSurface::ignored>();
  DT_BreakableSurface::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104302B0
// Name: DT_BreakableSurface::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BreakableSurface::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_BreakableSurface::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10411FD0
// Name: _dynamic_initializer_for____g_C_BreakableSurfaceClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_BreakableSurfaceClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_BreakableSurfaceClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_BreakableSurfaceClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412020
// Name: _dynamic_initializer_for__g_CBreakableSurfaceFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CBreakableSurfaceFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, IMaterialProxy *(__cdecl *)()))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "BreakableSurface",
           a3: CCBreakableSurfaceProxyFactory);
}

//------------------------------------------------------------------------------
// Address: 0x10412040
// Name: _dynamic_initializer_for____g_C_FuncBrushClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_FuncBrushClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_FuncBrushClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_FuncBrushClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104302C0
// Name: _DataMapInit_C_BreakableSurface__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_C_BreakableSurface__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_7);
}
