// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmematerialoverlayfxclip.cpp
// Functions: 27
// ============================================================

#include "movieobjects\dmematerialoverlayfxclip.h"

//------------------------------------------------------------------------------
// Address: 0x00568EC0
// Name: public: virtual void CDmeMaterialOverlayFXClip::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::Resolve(CDmeMaterialOverlayFXClip *this)
{
  const char *m_pAsString; // eax

  if ( SLOBYTE(this->m_Material.m_pAttribute->m_nFlags) < 0 )
  {
    CMaterialReference::Shutdown(this: &this->m_OverlayMaterial, bDeleteIfUnreferenced: false);
    m_pAsString = this->m_Material.m_Storage.u.m_pAsString;
    if ( m_pAsString != (const char *)-1 && m_pAsString != nullptr && *m_pAsString != 0 )
      CMaterialReference::Init(
        this: &this->m_OverlayMaterial,
        pMaterialName: m_pAsString,
        pTextureGroupName: nullptr,
        bComplain: false);
    this->m_Material.m_pAttribute->m_nFlags &= ~0x80u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00568F20
// Name: protected: void CDmeMaterialOverlayFXClip::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::OnConstruction(CDmeMaterialOverlayFXClip *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  CDmAttribute *v4; // ecx
  CDmAttribute *v5; // ecx
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  KeyValues *Key; // eax
  Color value; // [esp+Ch] [ebp-8h] BYREF
  bool v10; // [esp+13h] [ebp-1h] BYREF

  this->m_Material.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "material",
                                    type: AT_STRING,
                                    pMemory: &this->m_Material);
  this->m_Color.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "overlaycolor",
                                 type: AT_COLOR,
                                 pMemory: &this->m_Color);
  this->m_nLeft.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "left",
                                 type: AT_INT,
                                 pMemory: &this->m_nLeft);
  this->m_nTop.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "top",
                                type: AT_INT,
                                pMemory: &this->m_nTop);
  this->m_nWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "width",
                                  type: AT_INT,
                                  pMemory: &this->m_nWidth);
  this->m_nHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "height",
                                   type: AT_INT,
                                   pMemory: &this->m_nHeight);
  this->m_bFullScreen.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "fullscreen",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bFullScreen);
  this->m_bUseSubRect.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "useSubRect",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bUseSubRect);
  this->m_flMovementAngle.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "movementAngle",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flMovementAngle);
  this->m_flMovementSpeed.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "movementSpeed",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flMovementSpeed);
  this->m_nSubRectLeft.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "subRectLeft",
                                        type: AT_INT,
                                        pMemory: &this->m_nSubRectLeft);
  this->m_nSubRectTop.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "subRectTop",
                                       type: AT_INT,
                                       pMemory: &this->m_nSubRectTop);
  this->m_nSubRectWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "subRectWidth",
                                         type: AT_INT,
                                         pMemory: &this->m_nSubRectWidth);
  this->m_nSubRectHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "subRectHeight",
                                          type: AT_INT,
                                          pMemory: &this->m_nSubRectHeight);
  m_pAttribute = this->m_Color.m_pAttribute;
  value = (Color)-1;
  CDmAttribute::SetValue<Color>(this: m_pAttribute, &value);
  v3 = this->m_bFullScreen.m_pAttribute;
  v10 = true;
  CDmAttribute::SetValue<bool>(this: v3, value: &v10);
  v4 = this->m_nTop.m_pAttribute;
  value = 0;
  CDmAttribute::SetValue<int>(this: v4, (int *)&value);
  CDmAttribute::SetValue<int>(this: this->m_nLeft.m_pAttribute, value: &this->m_nTop.m_Storage);
  v5 = this->m_nHeight.m_pAttribute;
  value = (Color)1;
  CDmAttribute::SetValue<int>(this: v5, (int *)&value);
  CDmAttribute::SetValue<int>(this: this->m_nWidth.m_pAttribute, value: &this->m_nHeight.m_Storage);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "accumbuff4sample");
  else
    v7 = nullptr;
  KeyValues::SetString(this: v7, keyName: "$INPUT", value: "Effects/FilmScan256");
  Key = KeyValues::FindKey(this: v7, keyName: "proxies", bCreate: true);
  KeyValues::FindKey(this: Key, keyName: "sfm_blt", bCreate: true);
  CMaterialReference::Init(this: &this->m_BltMaterial, pMaterialName: "accumbuff4sample", pVMTKeyValues: v7);
  this->m_BltMaterial.m_pMaterial->Refresh(this: this->m_BltMaterial.m_pMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x00569170
// Name: private: void CDmeMaterialOverlayFXClip::DrawQuad(int,int,int,int,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeMaterialOverlayFXClip::DrawQuad(
        CDmeMaterialOverlayFXClip *this@<ecx>,
        int a2@<edi>,
        int x,
        int y,
        int w,
        int h,
        float u0,
        float v0,
        float u1,
        float v1)
{
  IMatRenderContext *v10; // esi
  IMesh *v11; // esi
  float *m_pCurrPosition; // eax
  float *v13; // eax
  float *v14; // eax
  float *v15; // eax
  int v16; // eax
  float *v17; // eax
  float v18; // xmm5_4
  float *v19; // eax
  float *v20; // eax
  float *v21; // eax
  int v22; // eax
  float *v23; // eax
  float v24; // xmm2_4
  float *v25; // eax
  float *v26; // eax
  float *v27; // eax
  int v28; // eax
  float *v29; // eax
  float *v30; // eax
  float *v31; // eax
  float *v32; // eax
  int m_nVertexCount; // eax
  int v34; // ecx
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1ECh] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F0h] [ebp-4h]

  v10 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v10;
  if ( v10 != nullptr )
    v10->BeginRender(this: v10);
  v11 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, int))v10->GetDynamicMesh)(
                   a1: v10,
                   a2: 1,
                   a3: 0,
                   a4: 0,
                   a5: 0,
                   a6: a2);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v11;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_TRIANGLE_STRIP;
  v11->SetPrimitiveType(this: v11, a2: MATERIAL_TRIANGLE_STRIP);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 4, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v11->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 4;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v11, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)x;
  m_pCurrPosition[1] = (float)y;
  m_pCurrPosition[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v13 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u0;
  v13[1] = v0;
  v14 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 0.0;
  v14[1] = 0.0;
  v15 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v15[1] = 0.0;
  v16 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v16;
  if ( v16 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v16;
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  v17 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v17;
  *v17 = (float)x;
  v18 = (float)(h + y);
  v17[1] = v18;
  v17[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v19 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u0;
  v19[1] = v1;
  v20 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 0.0;
  v20[1] = 1.0;
  v21 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v21[1] = 0.0;
  v22 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v22;
  if ( v22 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v22;
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  v23 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v23;
  v24 = (float)(w + x);
  *v23 = v24;
  v23[1] = (float)y;
  v23[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v25 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u1;
  v25[1] = v0;
  v26 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 1.0;
  v26[1] = 0.0;
  v27 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v27[1] = 0.0;
  v28 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v28;
  if ( v28 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v28;
  v29 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v29;
  *v29 = v24;
  v29[1] = v18;
  v29[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v30 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u1;
  v30[1] = v1;
  v31 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 1.0;
  v31[1] = 1.0;
  v32 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v32[1] = 0.0;
  m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  v34 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v34;
  if ( v34 > meshBuilder.m_VertexBuilder.m_nVertexCount )
  {
    m_nVertexCount = v34;
    meshBuilder.m_VertexBuilder.m_nVertexCount = v34;
  }
  meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount *= 2;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  }
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
  v11->Draw_2(this: v11, a2: -1, a3: 0);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x00569670
// Name: private: void CDmeMaterialOverlayFXClip::DrawOneToOneQuad(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::DrawOneToOneQuad(CDmeMaterialOverlayFXClip *this, int nWidth, int nHeight)
{
  IMatRenderContext *v3; // esi
  IMesh *v4; // esi
  float *m_pCurrPosition; // eax
  float v6; // xmm0_4
  float *v7; // eax
  int v8; // eax
  float *v9; // eax
  float *v10; // eax
  int v11; // eax
  float *v12; // eax
  float *v13; // eax
  float v14; // xmm0_4
  int v15; // eax
  float *v16; // eax
  float *v17; // eax
  int m_nVertexCount; // eax
  int v19; // ecx
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1ECh] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F0h] [ebp-4h]
  float fHeightEpsilon; // [esp+200h] [ebp+Ch]

  v3 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v3;
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  v4 = v3->GetDynamicMesh(this: v3, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v4;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_QUADS;
  fHeightEpsilon = 0.5 / (float)nHeight;
  v4->SetPrimitiveType(this: v4, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v4->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v4, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v6 = 0.5 / (float)nWidth;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = -1.0;
  m_pCurrPosition[1] = 1.0;
  m_pCurrPosition[2] = 0.5;
  v7 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v6;
  v7[1] = fHeightEpsilon;
  v8 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v8;
  if ( v8 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v8;
  v9 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v9;
  *v9 = -1.0;
  v9[1] = -1.0;
  v9[2] = 0.5;
  v10 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v6;
  v10[1] = fHeightEpsilon + 1.0;
  v11 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v11;
  if ( v11 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v11;
  v12 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v12;
  *v12 = 1.0;
  v12[1] = -1.0;
  v12[2] = 0.5;
  v13 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  v14 = v6 + 1.0;
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v14;
  v13[1] = fHeightEpsilon + 1.0;
  v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
  if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
  v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
  *v16 = 1.0;
  v16[1] = 1.0;
  v16[2] = 0.5;
  v17 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v14;
  v17[1] = fHeightEpsilon;
  m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  v19 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v19;
  if ( v19 > meshBuilder.m_VertexBuilder.m_nVertexCount )
  {
    m_nVertexCount = v19;
    meshBuilder.m_VertexBuilder.m_nVertexCount = v19;
  }
  meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount *= 2;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  }
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v4->Draw_2(this: v4, a2: -1, a3: 0);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x005699E0
// Name: public: virtual void CDmeMaterialOverlayFXClip::ApplyEffect(class DmeTime_t,struct Rect_t __near &,struct Rect_t __near &,class ITexture __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CDmeMaterialOverlayFXClip::ApplyEffect(
        CDmeMaterialOverlayFXClip *this@<ecx>,
        int a2@<edi>,
        DmeTime_t time,
        Rect_t *currentRect,
        int totalRect,
        float pTextures)
{
  int width; // edx
  int v9; // ecx
  Rect_t *v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // edx
  int v17; // eax
  int v18; // edx
  int v19; // eax
  int v20; // eax
  int v21; // edx
  int v22; // eax
  IMaterial *m_pMaterial; // ecx
  int v24; // eax
  bool v25; // zf
  float v26; // xmm5_4
  float v27; // xmm6_4
  float m_Storage; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm3_4
  float v31; // xmm1_4
  double v32; // xmm0_8
  double v33; // xmm0_8
  double v34; // xmm0_8
  float v35; // xmm1_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm3_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  int v42; // eax
  bool v43; // al
  Rect_t *v44; // edi
  long double v46; // [esp+78h] [ebp-50h] OVERLAPPED BYREF
  int g; // [esp+80h] [ebp-48h] BYREF
  float b; // [esp+84h] [ebp-44h] BYREF
  DmeTime_t v1; // [esp+88h] [ebp-40h] BYREF
  float u1; // [esp+8Ch] [ebp-3Ch]
  float dU; // [esp+90h] [ebp-38h]
  float flRadians; // [esp+94h] [ebp-34h]
  int mw; // [esp+98h] [ebp-30h]
  float vMin; // [esp+9Ch] [ebp-2Ch]
  float uMax; // [esp+A0h] [ebp-28h]
  float uMin; // [esp+A4h] [ebp-24h]
  float v57; // [esp+A8h] [ebp-20h]
  float v58; // [esp+ACh] [ebp-1Ch]
  int ty; // [esp+B0h] [ebp-18h]
  int th; // [esp+B4h] [ebp-14h]
  int tx; // [esp+B8h] [ebp-10h]
  int w; // [esp+BCh] [ebp-Ch]
  int h; // [esp+C0h] [ebp-8h]
  int x; // [esp+C4h] [ebp-4h]
  int timea; // [esp+D0h] [ebp+8h]
  int y; // [esp+D4h] [ebp+Ch]
  int ya; // [esp+D4h] [ebp+Ch]

  if ( this->m_OverlayMaterial.m_pMaterial == nullptr
    || this->m_BltMaterial.m_pMaterial == nullptr
    || this->m_Color.m_Storage._color[3] == 0 )
  {
    return;
  }
  timea = CDmeClip::ToChildMediaTime(this, result: &v1, t: time, bClamp: 0)->m_tms;
  width = currentRect->width;
  if ( this->m_bFullScreen.m_Storage )
  {
    v9 = currentRect->y;
    x = currentRect->x;
    h = currentRect->height;
    y = v9;
    v10 = *(Rect_t **)(totalRect + 8);
    w = width;
    v11 = *(_DWORD *)(totalRect + 12);
    ty = 0;
    tx = 0;
    totalRect = (int)v10;
    th = v11;
LABEL_22:
    if ( totalRect != 0 && th != 0 )
    {
      v22 = ((int (__thiscall *)(IMaterial *, int))this->m_OverlayMaterial.m_pMaterial->GetMappingWidth)(
              a1: this->m_OverlayMaterial.m_pMaterial,
              a2);
      m_pMaterial = this->m_OverlayMaterial.m_pMaterial;
      mw = v22;
      v24 = m_pMaterial->GetMappingHeight(this: m_pMaterial);
      v25 = !this->m_bUseSubRect.m_Storage;
      v26 = (float)mw;
      v27 = (float)v24;
      m_Storage = 0.0;
      v29 = (float)mw;
      v30 = 0.0;
      v31 = (float)v24;
      uMin = 0.0;
      u1 = (float)mw;
      uMax = (float)mw;
      vMin = 0.0;
      *(float *)&v1.m_tms = (float)v24;
      *(float *)&mw = (float)v24;
      if ( !v25 )
      {
        m_Storage = (float)this->m_nSubRectLeft.m_Storage;
        v30 = (float)this->m_nSubRectTop.m_Storage;
        v29 = (float)this->m_nSubRectWidth.m_Storage + m_Storage;
        v31 = (float)this->m_nSubRectHeight.m_Storage + v30;
        uMin = m_Storage;
        vMin = v30;
        uMax = v29;
        *(float *)&mw = v31;
      }
      v58 = this->m_flMovementSpeed.m_Storage;
      if ( v58 != 0.0 )
      {
        v32 = this->m_flMovementAngle.m_Storage;
        v57 = (float)timea * 0.000099999997;
        flRadians = v32 * 3.141592653589793 * 0.005555555555555556;
        v33 = flRadians;
        __libm_sse2_cos(x: v46);
        *(float *)&v33 = v33;
        dU = COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&v33 * v58) ^ _mask__NegFloat_) * v57;
        v34 = flRadians;
        __libm_sse2_sin(x: v46);
        v26 = u1;
        v27 = *(float *)&v1.m_tms;
        v35 = v34;
        v36 = (float)(v35 * v58) * v57;
        m_Storage = dU + uMin;
        v29 = dU + uMax;
        v30 = v36 + vMin;
        v31 = v36 + *(float *)&mw;
      }
      v37 = (float)(m_Storage + 0.5) / v26;
      v38 = (float)((float)(v29 - 0.5) / v26) - v37;
      v39 = (float)(v30 + 0.5) / v27;
      v40 = (float)((float)(v31 - 0.5) / v27) - v39;
      flRadians = (float)((float)((x - tx) / totalRect) * v38) + v37;
      u1 = (float)((float)((x + w - tx) / totalRect) * v38) + v37;
      v41 = (float)((float)((y - ty) / th) * v40) + v39;
      v42 = (y + h - ty) / th;
      ya = y - currentRect->y;
      dU = v41;
      x -= currentRect->x;
      *(float *)&v1.m_tms = (float)((float)v42 * v40) + v39;
      CMatRenderContextPtr::CMatRenderContextPtr(this: (CMatRenderContextPtr *)&totalRect, pFrom: materials);
      v43 = this->m_OverlayMaterial.m_pMaterial->NeedsPowerOfTwoFrameBufferTexture(
              this: this->m_OverlayMaterial.m_pMaterial,
              a2: true);
      v44 = (Rect_t *)totalRect;
      if ( v43 )
      {
        (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)totalRect + 36))(
          a1: totalRect,
          a2: this->m_BltMaterial.m_pMaterial,
          a3: *(_DWORD *)LODWORD(pTextures));
        (*(void (__thiscall **)(Rect_t *, ITexture *, _DWORD, _DWORD, int, int))(v44->x + 432))(
          a1: v44,
          a2: *(ITexture **)(LODWORD(pTextures) + 4),
          a3: 0,
          a4: 0,
          a5: w,
          a6: h);
        CDmeMaterialOverlayFXClip::DrawOneToOneQuad(this, nWidth: w, nHeight: h);
        (*(void (__thiscall **)(Rect_t *))(v44->x + 444))(a1: v44);
        (*(void (__thiscall **)(Rect_t *, ITexture *, _DWORD))(v44->x + 72))(
          a1: v44,
          a2: *(ITexture **)(LODWORD(pTextures) + 4),
          a3: 0);
        (*(void (__thiscall **)(Rect_t *, _DWORD, _DWORD, _DWORD, int, int))(v44->x + 432))(
          a1: v44,
          a2: *(_DWORD *)LODWORD(pTextures),
          a3: 0,
          a4: 0,
          a5: w,
          a6: h);
      }
      this->m_OverlayMaterial.m_pMaterial->GetColorModulation(
        this: this->m_OverlayMaterial.m_pMaterial,
        a2: (float *)((char *)&v46 + 4),
        a3: (float *)&g,
        a4: &b);
      pTextures = this->m_OverlayMaterial.m_pMaterial->GetAlphaModulation(this: this->m_OverlayMaterial.m_pMaterial);
      ((void (__thiscall *)(IMaterial *, _DWORD, _DWORD, _DWORD))this->m_OverlayMaterial.m_pMaterial->ColorModulate)(
        a1: this->m_OverlayMaterial.m_pMaterial,
        a2: (float)this->m_Color.m_Storage._color[0] * 0.0039215689,
        a3: (float)this->m_Color.m_Storage._color[1] * 0.0039215689,
        a4: (float)this->m_Color.m_Storage._color[2] * 0.0039215689);
      ((void (__stdcall *)(_DWORD))this->m_OverlayMaterial.m_pMaterial->AlphaModulate)(a1: (float)this->m_Color.m_Storage._color[3] * 0.0039215689);
      (*(void (__thiscall **)(Rect_t *, IMaterial *, _DWORD))(v44->x + 36))(
        a1: v44,
        a2: this->m_OverlayMaterial.m_pMaterial,
        a3: 0);
      CDmeMaterialOverlayFXClip::DrawQuad(
        this,
        a2: (int)v44,
        x,
        y: ya,
        w,
        h,
        u0: flRadians,
        v0: dU,
        u1,
        v1: *(float *)&v1.m_tms);
      if ( this->m_OverlayMaterial.m_pMaterial->NeedsPowerOfTwoFrameBufferTexture(
             this: this->m_OverlayMaterial.m_pMaterial,
             a2: true) )
      {
        (*(void (__thiscall **)(Rect_t *))(v44->x + 444))(a1: v44);
      }
      ((void (__thiscall *)(IMaterial *, _DWORD, int))this->m_OverlayMaterial.m_pMaterial->ColorModulate)(
        a1: this->m_OverlayMaterial.m_pMaterial,
        a2: HIDWORD(v46),
        a3: g);
      ((void (__stdcall *)(_DWORD))this->m_OverlayMaterial.m_pMaterial->AlphaModulate)(a1: LODWORD(pTextures));
      CMatRenderContextPtr::~CMatRenderContextPtr(this: (CMatRenderContextPtr *)&totalRect);
    }
    return;
  }
  v12 = currentRect->x;
  v13 = this->m_nLeft.m_Storage;
  v14 = currentRect->x + width;
  mw = v14;
  if ( v13 >= v12 )
  {
    x = v14;
    if ( v13 <= v14 )
      x = v13;
  }
  else
  {
    x = v12;
  }
  v15 = currentRect->y;
  totalRect = v15 + currentRect->height;
  v16 = this->m_nTop.m_Storage;
  if ( v16 >= v15 )
  {
    y = totalRect;
    if ( v16 <= totalRect )
      y = this->m_nTop.m_Storage;
  }
  else
  {
    y = v15;
  }
  v17 = this->m_nLeft.m_Storage + this->m_nWidth.m_Storage;
  if ( v17 >= v12 )
  {
    v12 = mw;
    if ( v17 <= mw )
      v12 = this->m_nLeft.m_Storage + this->m_nWidth.m_Storage;
  }
  v18 = this->m_nHeight.m_Storage + v16;
  v19 = currentRect->y;
  if ( v18 >= v19 )
  {
    v19 = totalRect;
    if ( v18 <= totalRect )
      v19 = v18;
  }
  v20 = v19 - y;
  tx = this->m_nLeft.m_Storage;
  ty = this->m_nTop.m_Storage;
  totalRect = this->m_nWidth.m_Storage;
  v21 = this->m_nHeight.m_Storage;
  w = v12 - x;
  h = v20;
  th = v21;
  if ( v12 - x > 0 && v20 > 0 )
    goto LABEL_22;
}

//------------------------------------------------------------------------------
// Address: 0x00569FF0
// Name: protected: CDmeMaterialOverlayFXClip::CDmeMaterialOverlayFXClip(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMaterialOverlayFXClip *__thiscall CDmeMaterialOverlayFXClip::CDmeMaterialOverlayFXClip(
        CDmeMaterialOverlayFXClip *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeMaterialOverlayFXClip_vtbl *)&CDmeClip::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_TrackGroups);
  this->m_TimeFrame.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_TimeFrame.m_pAttribute = nullptr;
  this->m_TimeFrame.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_ClipColor.m_pAttribute = nullptr;
  this->m_ClipColor.m_Storage = (Color)-16777216;
  this->m_bMute.m_pAttribute = nullptr;
  this->m_bMute.m_Storage = false;
  this->m_flDisplayScale = 0;
  this->m_ClipText.m_pAttribute = nullptr;
  this->m_ClipText.m_Storage.u.CDmeFXClip::CDmeClip::m_Id = -1;
  this->__vftable = (CDmeMaterialOverlayFXClip_vtbl *)&CDmeMaterialOverlayFXClip::`vftable';
  this->m_Material.m_pAttribute = nullptr;
  this->m_Material.m_Storage.u.m_Id = -1;
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_nLeft.m_pAttribute = nullptr;
  this->m_nLeft.m_Storage = 0;
  this->m_nTop.m_pAttribute = nullptr;
  this->m_nTop.m_Storage = 0;
  this->m_nWidth.m_pAttribute = nullptr;
  this->m_nWidth.m_Storage = 0;
  this->m_nHeight.m_pAttribute = nullptr;
  this->m_nHeight.m_Storage = 0;
  this->m_bFullScreen.m_pAttribute = nullptr;
  this->m_bFullScreen.m_Storage = false;
  this->m_bUseSubRect.m_pAttribute = nullptr;
  this->m_bUseSubRect.m_Storage = false;
  this->m_nSubRectLeft.m_pAttribute = nullptr;
  this->m_nSubRectLeft.m_Storage = 0;
  this->m_nSubRectTop.m_pAttribute = nullptr;
  this->m_nSubRectTop.m_Storage = 0;
  this->m_nSubRectWidth.m_pAttribute = nullptr;
  this->m_nSubRectWidth.m_Storage = 0;
  this->m_nSubRectHeight.m_pAttribute = nullptr;
  this->m_nSubRectHeight.m_Storage = 0;
  this->m_flMovementAngle = 0;
  this->m_flMovementSpeed = 0;
  CMaterialReference::CMaterialReference(
    this: &this->m_OverlayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_BltMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0056A140
// Name: public: virtual bool CDmeMaterialOverlayFXClip::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMaterialOverlayFXClip::IsA(CDmeMaterialOverlayFXClip *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMaterialOverlayFXClip::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFXClip::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeClip::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0056A180
// Name: public: virtual int CDmeMaterialOverlayFXClip::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialOverlayFXClip::GetInheritanceDepth(
        CDmeMaterialOverlayFXClip *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMaterialOverlayFXClip::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFXClip::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeClip::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0056A1E0
// Name: protected: virtual void CDmeMaterialOverlayFXClip::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::PerformDestruction(CDmeMaterialOverlayFXClip *this)
{
  CMaterialReference::Shutdown(this: &this->m_BltMaterial, bDeleteIfUnreferenced: false);
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x0056A210
// Name: protected: virtual int CDmeMaterialOverlayFXClip::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialOverlayFXClip::AllocatedSize(CDmeMaterialOverlayFXClip *this)
{
  return 260;
}

//------------------------------------------------------------------------------
// Address: 0x0056A220
// Name: protected: virtual void CDmeMaterialOverlayFXClip::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::PerformConstruction(CDmeMaterialOverlayFXClip *this)
{
  CDmeFXClip::OnDestruction();
  CDmeClip::OnConstruction(this);
  CDmeFXClip::OnDestruction();
  CDmeMaterialOverlayFXClip::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005AF040
// Name: _dynamic_initializer_for__CDmeMaterialOverlayFXClip::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMaterialOverlayFXClip::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMaterialOverlayFXClip::s_Allocator,
    blockSize: 260,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMaterialOverlayFXClip pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005B0C10
// Name: _dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMaterialOverlayFXClip::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AF070
// Name: _dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Factory__()
{
  CDmeFXClip::InstallFXClipType(pElementType: "DmeMaterialOverlayFXClip", pDescription: "Material Overlay Effect");
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AF090
// Name: _dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMaterialOverlayFXClip_Helper,
           classname: "DmeMaterialOverlayFXClip",
           pFactory: &g_CDmeMaterialOverlayFXClip_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AF0B0
// Name: _dynamic_initializer_for__mod_load_preload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_preload__()
{
  ConVar::ConVar(
    this: &mod_load_preload,
    pName: "mod_load_preload",
    pDefaultValue: "1.0",
    flags: 0,
    pHelpString: "Indicates how far ahead in seconds to preload animations.");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_preload__);
}

//------------------------------------------------------------------------------
// Address: 0x005AF0E0
// Name: _dynamic_initializer_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_showstall__()
{
  ConVar::ConVar(
    this: &mod_load_showstall,
    pName: "mod_load_showstall",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "1 - show hitches , 2 - show stalls");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_showstall__);
}

//------------------------------------------------------------------------------
// Address: 0x005AF110
// Name: _dynamic_initializer_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ActivityModifiersTable, growSize: 0, initSize: 16, caseInsensitive: false);
  return atexit(func: dynamic_atexit_destructor_for__g_ActivityModifiersTable__);
}

//------------------------------------------------------------------------------
// Address: 0x005AF130
// Name: _dynamic_initializer_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall dynamic_initializer_for__emptyMapping__(char a1)
{
  int v2; // [esp-4h] [ebp-Ch] BYREF
  CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs v3; // [esp+0h] [ebp-8h]
  int *v4; // [esp+4h] [ebp-4h]

  v4 = &v2;
  CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>::CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>(
    this: &emptyMapping.m_ActToSeqHash,
    bucketCount: 8,
    growCount: 0,
    initCount: 0,
    compareFunc: (CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs)a1,
    keyFunc: v3);
  emptyMapping.m_pStudioHdr = nullptr;
  emptyMapping.m_expectedVModel = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__emptyMapping__);
}

//------------------------------------------------------------------------------
// Address: 0x005AF180
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMaps__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__);
}

//------------------------------------------------------------------------------
// Address: 0x005AF190
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMapsLock__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMapsLock__()
{
  g_StudioHdrToActivityMapsLock.m_ownerID = 0;
  g_StudioHdrToActivityMapsLock.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005B0C20
// Name: _dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMaterialOverlayFXClip_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005B0C30
// Name: _dynamic_atexit_destructor_for__mod_load_preload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_preload__()
{
  ConVar::~ConVar(this: &mod_load_preload);
}

//------------------------------------------------------------------------------
// Address: 0x005B0C40
// Name: _dynamic_atexit_destructor_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_showstall__()
{
  ConVar::~ConVar(this: &mod_load_showstall);
}

//------------------------------------------------------------------------------
// Address: 0x005B0C50
// Name: _dynamic_atexit_destructor_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ActivityModifiersTable);
}

//------------------------------------------------------------------------------
// Address: 0x005B0C60
// Name: _dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__()
{
  CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_StudioHdrToActivityMaps.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x005B0C70
// Name: _dynamic_atexit_destructor_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__emptyMapping__()
{
  CStudioHdr::CActivityToSequenceMapping::SequenceTuple *m_pSequenceTuples; // ecx

  m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
  if ( emptyMapping.m_pSequenceTuples != nullptr )
  {
    if ( emptyMapping.m_pSequenceTuples->pActivityModifiers != nullptr )
    {
      free(pMem: emptyMapping.m_pSequenceTuples->pActivityModifiers);
      m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
    }
    free(pMem: m_pSequenceTuples);
  }
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: &emptyMapping.m_ActToSeqHash);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&emptyMapping.m_ActToSeqHash);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005C7C30
// Name: public: virtual void CDmeMaterialOverlayFXClip::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::Resolve(CDmeMaterialOverlayFXClip *this)
{
  const char *m_pAsString; // eax

  if ( SLOBYTE(this->m_Material.m_pAttribute->m_nFlags) < 0 )
  {
    CMaterialReference::Shutdown(this: &this->m_OverlayMaterial, bDeleteIfUnreferenced: false);
    m_pAsString = this->m_Material.m_Storage.u.m_pAsString;
    if ( m_pAsString != (const char *)-1 && m_pAsString != nullptr && *m_pAsString != 0 )
      CMaterialReference::Init(
        this: &this->m_OverlayMaterial,
        pMaterialName: m_pAsString,
        pTextureGroupName: nullptr,
        bComplain: false);
    this->m_Material.m_pAttribute->m_nFlags &= ~0x80u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C7C90
// Name: protected: void CDmeMaterialOverlayFXClip::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::OnConstruction(CDmeMaterialOverlayFXClip *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  CDmAttribute *v4; // ecx
  CDmAttribute *v5; // ecx
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  KeyValues *Key; // eax
  Color value; // [esp+Ch] [ebp-8h] BYREF
  bool v10; // [esp+13h] [ebp-1h] BYREF

  this->m_Material.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "material",
                                    type: AT_STRING,
                                    pMemory: &this->m_Material);
  this->m_Color.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "overlaycolor",
                                 type: AT_COLOR,
                                 pMemory: &this->m_Color);
  this->m_nLeft.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "left",
                                 type: AT_INT,
                                 pMemory: &this->m_nLeft);
  this->m_nTop.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "top",
                                type: AT_INT,
                                pMemory: &this->m_nTop);
  this->m_nWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "width",
                                  type: AT_INT,
                                  pMemory: &this->m_nWidth);
  this->m_nHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "height",
                                   type: AT_INT,
                                   pMemory: &this->m_nHeight);
  this->m_bFullScreen.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "fullscreen",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bFullScreen);
  this->m_bUseSubRect.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "useSubRect",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bUseSubRect);
  this->m_flMovementAngle.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "movementAngle",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flMovementAngle);
  this->m_flMovementSpeed.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "movementSpeed",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flMovementSpeed);
  this->m_nSubRectLeft.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "subRectLeft",
                                        type: AT_INT,
                                        pMemory: &this->m_nSubRectLeft);
  this->m_nSubRectTop.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "subRectTop",
                                       type: AT_INT,
                                       pMemory: &this->m_nSubRectTop);
  this->m_nSubRectWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "subRectWidth",
                                         type: AT_INT,
                                         pMemory: &this->m_nSubRectWidth);
  this->m_nSubRectHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "subRectHeight",
                                          type: AT_INT,
                                          pMemory: &this->m_nSubRectHeight);
  m_pAttribute = this->m_Color.m_pAttribute;
  value = (Color)-1;
  CDmAttribute::SetValue<Color>(this: m_pAttribute, &value);
  v3 = this->m_bFullScreen.m_pAttribute;
  v10 = true;
  CDmAttribute::SetValue<bool>(this: v3, value: &v10);
  v4 = this->m_nTop.m_pAttribute;
  value = 0;
  CDmAttribute::SetValue<int>(this: v4, (const int *)&value);
  CDmAttribute::SetValue<int>(this: this->m_nLeft.m_pAttribute, value: &this->m_nTop.m_Storage);
  v5 = this->m_nHeight.m_pAttribute;
  value = (Color)1;
  CDmAttribute::SetValue<int>(this: v5, (const int *)&value);
  CDmAttribute::SetValue<int>(this: this->m_nWidth.m_pAttribute, value: &this->m_nHeight.m_Storage);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "accumbuff4sample");
  else
    v7 = nullptr;
  KeyValues::SetString(this: v7, keyName: "$INPUT", value: "Effects/FilmScan256");
  Key = KeyValues::FindKey(this: v7, keyName: "proxies", bCreate: true);
  KeyValues::FindKey(this: Key, keyName: "sfm_blt", bCreate: true);
  CMaterialReference::Init(this: &this->m_BltMaterial, pMaterialName: "accumbuff4sample", pVMTKeyValues: v7);
  this->m_BltMaterial.m_pMaterial->Refresh(this: this->m_BltMaterial.m_pMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x005C7EE0
// Name: private: void CDmeMaterialOverlayFXClip::DrawQuad(int,int,int,int,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeMaterialOverlayFXClip::DrawQuad(
        CDmeMaterialOverlayFXClip *this@<ecx>,
        int a2@<edi>,
        int x,
        int y,
        int w,
        int h,
        float u0,
        float v0,
        float u1,
        float v1)
{
  IMatRenderContext *v10; // esi
  IMesh *v11; // esi
  float *m_pCurrPosition; // eax
  float *v13; // eax
  float *v14; // eax
  float *v15; // eax
  int v16; // eax
  float *v17; // eax
  float v18; // xmm5_4
  float *v19; // eax
  float *v20; // eax
  float *v21; // eax
  int v22; // eax
  float *v23; // eax
  float v24; // xmm2_4
  float *v25; // eax
  float *v26; // eax
  float *v27; // eax
  int v28; // eax
  float *v29; // eax
  float *v30; // eax
  float *v31; // eax
  float *v32; // eax
  int m_nVertexCount; // eax
  int v34; // ecx
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1ECh] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F0h] [ebp-4h]

  v10 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v10;
  if ( v10 != nullptr )
    v10->BeginRender(this: v10);
  v11 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, int))v10->GetDynamicMesh)(
                   a1: v10,
                   a2: 1,
                   a3: 0,
                   a4: 0,
                   a5: 0,
                   a6: a2);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v11;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_TRIANGLE_STRIP;
  v11->SetPrimitiveType(this: v11, a2: MATERIAL_TRIANGLE_STRIP);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 4, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v11->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 4;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v11, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)x;
  m_pCurrPosition[1] = (float)y;
  m_pCurrPosition[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v13 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u0;
  v13[1] = v0;
  v14 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 0.0;
  v14[1] = 0.0;
  v15 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v15[1] = 0.0;
  v16 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v16;
  if ( v16 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v16;
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  v17 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v17;
  *v17 = (float)x;
  v18 = (float)(h + y);
  v17[1] = v18;
  v17[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v19 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u0;
  v19[1] = v1;
  v20 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 0.0;
  v20[1] = 1.0;
  v21 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v21[1] = 0.0;
  v22 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v22;
  if ( v22 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v22;
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  v23 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v23;
  v24 = (float)(w + x);
  *v23 = v24;
  v23[1] = (float)y;
  v23[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v25 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u1;
  v25[1] = v0;
  v26 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 1.0;
  v26[1] = 0.0;
  v27 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v27[1] = 0.0;
  v28 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v28;
  if ( v28 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v28;
  v29 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v29;
  *v29 = v24;
  v29[1] = v18;
  v29[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v30 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u1;
  v30[1] = v1;
  v31 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 1.0;
  v31[1] = 1.0;
  v32 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v32[1] = 0.0;
  m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  v34 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v34;
  if ( v34 > meshBuilder.m_VertexBuilder.m_nVertexCount )
  {
    m_nVertexCount = v34;
    meshBuilder.m_VertexBuilder.m_nVertexCount = v34;
  }
  meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount *= 2;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  }
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
  v11->Draw_2(this: v11, a2: -1, a3: 0);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x005C83E0
// Name: private: void CDmeMaterialOverlayFXClip::DrawOneToOneQuad(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::DrawOneToOneQuad(CDmeMaterialOverlayFXClip *this, int nWidth, int nHeight)
{
  IMatRenderContext *v3; // esi
  IMesh *v4; // esi
  float *m_pCurrPosition; // eax
  float v6; // xmm0_4
  float *v7; // eax
  int v8; // eax
  float *v9; // eax
  float *v10; // eax
  int v11; // eax
  float *v12; // eax
  float *v13; // eax
  float v14; // xmm0_4
  int v15; // eax
  float *v16; // eax
  float *v17; // eax
  int m_nVertexCount; // eax
  int v19; // ecx
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1ECh] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F0h] [ebp-4h]
  float fHeightEpsilon; // [esp+200h] [ebp+Ch]

  v3 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v3;
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  v4 = v3->GetDynamicMesh(this: v3, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v4;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_QUADS;
  fHeightEpsilon = 0.5 / (float)nHeight;
  v4->SetPrimitiveType(this: v4, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v4->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v4, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v6 = 0.5 / (float)nWidth;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = -1.0;
  m_pCurrPosition[1] = 1.0;
  m_pCurrPosition[2] = 0.5;
  v7 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v6;
  v7[1] = fHeightEpsilon;
  v8 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v8;
  if ( v8 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v8;
  v9 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v9;
  *v9 = -1.0;
  v9[1] = -1.0;
  v9[2] = 0.5;
  v10 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v6;
  v10[1] = fHeightEpsilon + 1.0;
  v11 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v11;
  if ( v11 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v11;
  v12 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v12;
  *v12 = 1.0;
  v12[1] = -1.0;
  v12[2] = 0.5;
  v13 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  v14 = v6 + 1.0;
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v14;
  v13[1] = fHeightEpsilon + 1.0;
  v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
  if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
  v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
  *v16 = 1.0;
  v16[1] = 1.0;
  v16[2] = 0.5;
  v17 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v14;
  v17[1] = fHeightEpsilon;
  m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  v19 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v19;
  if ( v19 > meshBuilder.m_VertexBuilder.m_nVertexCount )
  {
    m_nVertexCount = v19;
    meshBuilder.m_VertexBuilder.m_nVertexCount = v19;
  }
  meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount *= 2;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  }
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v4->Draw_2(this: v4, a2: -1, a3: 0);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x005C8750
// Name: public: virtual void CDmeMaterialOverlayFXClip::ApplyEffect(class DmeTime_t,struct Rect_t __near &,struct Rect_t __near &,class ITexture __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CDmeMaterialOverlayFXClip::ApplyEffect(
        CDmeMaterialOverlayFXClip *this@<ecx>,
        int a2@<edi>,
        DmeTime_t time,
        Rect_t *currentRect,
        int totalRect,
        float pTextures)
{
  int width; // edx
  int v9; // ecx
  Rect_t *v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // edx
  int v17; // eax
  int v18; // edx
  int v19; // eax
  int v20; // eax
  int v21; // edx
  int v22; // eax
  IMaterial *m_pMaterial; // ecx
  int v24; // eax
  bool v25; // zf
  float v26; // xmm5_4
  float v27; // xmm6_4
  float m_Storage; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm3_4
  float v31; // xmm1_4
  __m128d v32; // xmm0
  __m128 v33; // xmm1
  double v34; // xmm0_8
  double v35; // xmm0_8
  float v36; // xmm2_4
  float v37; // xmm0_4
  float v38; // xmm3_4
  float v39; // xmm1_4
  float v40; // xmm0_4
  int v41; // eax
  bool v42; // al
  Rect_t *v43; // edi
  long double v45; // [esp+78h] [ebp-50h] OVERLAPPED BYREF
  int g; // [esp+80h] [ebp-48h] BYREF
  float b; // [esp+84h] [ebp-44h] BYREF
  DmeTime_t v1; // [esp+88h] [ebp-40h] BYREF
  float u1; // [esp+8Ch] [ebp-3Ch]
  float dU; // [esp+90h] [ebp-38h]
  float flRadians; // [esp+94h] [ebp-34h]
  int mw; // [esp+98h] [ebp-30h]
  float vMin; // [esp+9Ch] [ebp-2Ch]
  float uMax; // [esp+A0h] [ebp-28h]
  float uMin; // [esp+A4h] [ebp-24h]
  float v56; // [esp+A8h] [ebp-20h]
  float v57; // [esp+ACh] [ebp-1Ch]
  int ty; // [esp+B0h] [ebp-18h]
  int th; // [esp+B4h] [ebp-14h]
  int tx; // [esp+B8h] [ebp-10h]
  int w; // [esp+BCh] [ebp-Ch]
  int h; // [esp+C0h] [ebp-8h]
  int x; // [esp+C4h] [ebp-4h]
  int timea; // [esp+D0h] [ebp+8h]
  int y; // [esp+D4h] [ebp+Ch]
  int ya; // [esp+D4h] [ebp+Ch]

  if ( this->m_OverlayMaterial.m_pMaterial == nullptr
    || this->m_BltMaterial.m_pMaterial == nullptr
    || this->m_Color.m_Storage._color[3] == 0 )
  {
    return;
  }
  timea = CDmeClip::ToChildMediaTime(this, result: &v1, t: time, bClamp: 0)->m_tms;
  width = currentRect->width;
  if ( this->m_bFullScreen.m_Storage )
  {
    v9 = currentRect->y;
    x = currentRect->x;
    h = currentRect->height;
    y = v9;
    v10 = *(Rect_t **)(totalRect + 8);
    w = width;
    v11 = *(_DWORD *)(totalRect + 12);
    ty = 0;
    tx = 0;
    totalRect = (int)v10;
    th = v11;
LABEL_22:
    if ( totalRect != 0 && th != 0 )
    {
      v22 = ((int (__thiscall *)(IMaterial *, int))this->m_OverlayMaterial.m_pMaterial->GetMappingWidth)(
              a1: this->m_OverlayMaterial.m_pMaterial,
              a2);
      m_pMaterial = this->m_OverlayMaterial.m_pMaterial;
      mw = v22;
      v24 = m_pMaterial->GetMappingHeight(this: m_pMaterial);
      v25 = !this->m_bUseSubRect.m_Storage;
      v26 = (float)mw;
      v27 = (float)v24;
      m_Storage = 0.0;
      v29 = (float)mw;
      v30 = 0.0;
      v31 = (float)v24;
      uMin = 0.0;
      u1 = (float)mw;
      uMax = (float)mw;
      vMin = 0.0;
      *(float *)&v1.m_tms = (float)v24;
      *(float *)&mw = (float)v24;
      if ( !v25 )
      {
        m_Storage = (float)this->m_nSubRectLeft.m_Storage;
        v30 = (float)this->m_nSubRectTop.m_Storage;
        v29 = (float)this->m_nSubRectWidth.m_Storage + m_Storage;
        v31 = (float)this->m_nSubRectHeight.m_Storage + v30;
        uMin = m_Storage;
        vMin = v30;
        uMax = v29;
        *(float *)&mw = v31;
      }
      v57 = this->m_flMovementSpeed.m_Storage;
      if ( v57 != 0.0 )
      {
        v32 = _mm_cvtps_pd((__m128)LODWORD(this->m_flMovementAngle.m_Storage));
        v32.m128d_f64[0] = v32.m128d_f64[0] * 3.141592653589793 * 0.005555555555555556;
        v33 = _mm_cvtpd_ps(v32);
        v56 = (float)timea * 0.000099999997;
        flRadians = v33.m128_f32[0];
        __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd(v33));
        *(float *)&v34 = v34;
        dU = COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&v34 * v57) ^ _mask__NegFloat_) * v56;
        v35 = flRadians;
        __libm_sse2_sin(x: v45);
        v26 = u1;
        v27 = *(float *)&v1.m_tms;
        v33.m128_f32[0] = v35;
        v33.m128_f32[0] = (float)(v33.m128_f32[0] * v57) * v56;
        m_Storage = dU + uMin;
        v29 = dU + uMax;
        v30 = v33.m128_f32[0] + vMin;
        v31 = v33.m128_f32[0] + *(float *)&mw;
      }
      v36 = (float)(m_Storage + 0.5) / v26;
      v37 = (float)((float)(v29 - 0.5) / v26) - v36;
      v38 = (float)(v30 + 0.5) / v27;
      v39 = (float)((float)(v31 - 0.5) / v27) - v38;
      flRadians = (float)((float)((x - tx) / totalRect) * v37) + v36;
      u1 = (float)((float)((x + w - tx) / totalRect) * v37) + v36;
      v40 = (float)((float)((y - ty) / th) * v39) + v38;
      v41 = (y + h - ty) / th;
      ya = y - currentRect->y;
      dU = v40;
      x -= currentRect->x;
      *(float *)&v1.m_tms = (float)((float)v41 * v39) + v38;
      CMatRenderContextPtr::CMatRenderContextPtr(this: (CMatRenderContextPtr *)&totalRect, pFrom: materials);
      v42 = this->m_OverlayMaterial.m_pMaterial->NeedsPowerOfTwoFrameBufferTexture(
              this: this->m_OverlayMaterial.m_pMaterial,
              a2: true);
      v43 = (Rect_t *)totalRect;
      if ( v42 )
      {
        (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)totalRect + 36))(
          a1: totalRect,
          a2: this->m_BltMaterial.m_pMaterial,
          a3: *(_DWORD *)LODWORD(pTextures));
        (*(void (__thiscall **)(Rect_t *, ITexture *, _DWORD, _DWORD, int, int))(v43->x + 432))(
          a1: v43,
          a2: *(ITexture **)(LODWORD(pTextures) + 4),
          a3: 0,
          a4: 0,
          a5: w,
          a6: h);
        CDmeMaterialOverlayFXClip::DrawOneToOneQuad(this, nWidth: w, nHeight: h);
        (*(void (__thiscall **)(Rect_t *))(v43->x + 444))(a1: v43);
        (*(void (__thiscall **)(Rect_t *, ITexture *, _DWORD))(v43->x + 72))(
          a1: v43,
          a2: *(ITexture **)(LODWORD(pTextures) + 4),
          a3: 0);
        (*(void (__thiscall **)(Rect_t *, _DWORD, _DWORD, _DWORD, int, int))(v43->x + 432))(
          a1: v43,
          a2: *(_DWORD *)LODWORD(pTextures),
          a3: 0,
          a4: 0,
          a5: w,
          a6: h);
      }
      this->m_OverlayMaterial.m_pMaterial->GetColorModulation(
        this: this->m_OverlayMaterial.m_pMaterial,
        a2: (float *)((char *)&v45 + 4),
        a3: (float *)&g,
        a4: &b);
      pTextures = this->m_OverlayMaterial.m_pMaterial->GetAlphaModulation(this: this->m_OverlayMaterial.m_pMaterial);
      ((void (__thiscall *)(IMaterial *, _DWORD, _DWORD, _DWORD))this->m_OverlayMaterial.m_pMaterial->ColorModulate)(
        a1: this->m_OverlayMaterial.m_pMaterial,
        a2: (float)this->m_Color.m_Storage._color[0] * 0.0039215689,
        a3: (float)this->m_Color.m_Storage._color[1] * 0.0039215689,
        a4: (float)this->m_Color.m_Storage._color[2] * 0.0039215689);
      ((void (__stdcall *)(_DWORD))this->m_OverlayMaterial.m_pMaterial->AlphaModulate)(a1: (float)this->m_Color.m_Storage._color[3] * 0.0039215689);
      (*(void (__thiscall **)(Rect_t *, IMaterial *, _DWORD))(v43->x + 36))(
        a1: v43,
        a2: this->m_OverlayMaterial.m_pMaterial,
        a3: 0);
      CDmeMaterialOverlayFXClip::DrawQuad(
        this,
        a2: (int)v43,
        x,
        y: ya,
        w,
        h,
        u0: flRadians,
        v0: dU,
        u1,
        v1: *(float *)&v1.m_tms);
      if ( this->m_OverlayMaterial.m_pMaterial->NeedsPowerOfTwoFrameBufferTexture(
             this: this->m_OverlayMaterial.m_pMaterial,
             a2: true) )
      {
        (*(void (__thiscall **)(Rect_t *))(v43->x + 444))(a1: v43);
      }
      ((void (__thiscall *)(IMaterial *, _DWORD, int))this->m_OverlayMaterial.m_pMaterial->ColorModulate)(
        a1: this->m_OverlayMaterial.m_pMaterial,
        a2: HIDWORD(v45),
        a3: g);
      ((void (__stdcall *)(_DWORD))this->m_OverlayMaterial.m_pMaterial->AlphaModulate)(a1: LODWORD(pTextures));
      CMatRenderContextPtr::~CMatRenderContextPtr(this: (CMatRenderContextPtr *)&totalRect);
    }
    return;
  }
  v12 = currentRect->x;
  v13 = this->m_nLeft.m_Storage;
  v14 = currentRect->x + width;
  mw = v14;
  if ( v13 >= v12 )
  {
    x = v14;
    if ( v13 <= v14 )
      x = v13;
  }
  else
  {
    x = v12;
  }
  v15 = currentRect->y;
  totalRect = v15 + currentRect->height;
  v16 = this->m_nTop.m_Storage;
  if ( v16 >= v15 )
  {
    y = totalRect;
    if ( v16 <= totalRect )
      y = this->m_nTop.m_Storage;
  }
  else
  {
    y = v15;
  }
  v17 = this->m_nLeft.m_Storage + this->m_nWidth.m_Storage;
  if ( v17 >= v12 )
  {
    v12 = mw;
    if ( v17 <= mw )
      v12 = this->m_nLeft.m_Storage + this->m_nWidth.m_Storage;
  }
  v18 = this->m_nHeight.m_Storage + v16;
  v19 = currentRect->y;
  if ( v18 >= v19 )
  {
    v19 = totalRect;
    if ( v18 <= totalRect )
      v19 = v18;
  }
  v20 = v19 - y;
  tx = this->m_nLeft.m_Storage;
  ty = this->m_nTop.m_Storage;
  totalRect = this->m_nWidth.m_Storage;
  v21 = this->m_nHeight.m_Storage;
  w = v12 - x;
  h = v20;
  th = v21;
  if ( v12 - x > 0 && v20 > 0 )
    goto LABEL_22;
}

//------------------------------------------------------------------------------
// Address: 0x005C8D60
// Name: protected: CDmeMaterialOverlayFXClip::CDmeMaterialOverlayFXClip(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMaterialOverlayFXClip *__thiscall CDmeMaterialOverlayFXClip::CDmeMaterialOverlayFXClip(
        CDmeMaterialOverlayFXClip *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeMaterialOverlayFXClip_vtbl *)&CDmeClip::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_TrackGroups);
  this->m_TimeFrame.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_TimeFrame.m_pAttribute = nullptr;
  this->m_TimeFrame.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_ClipColor.m_pAttribute = nullptr;
  this->m_ClipColor.m_Storage = (Color)-16777216;
  this->m_bMute.m_pAttribute = nullptr;
  this->m_bMute.m_Storage = false;
  this->m_flDisplayScale = 0;
  this->m_ClipText.m_pAttribute = nullptr;
  this->m_ClipText.m_Storage.u.CDmeFXClip::CDmeClip::m_Id = -1;
  this->__vftable = (CDmeMaterialOverlayFXClip_vtbl *)&CDmeMaterialOverlayFXClip::`vftable';
  this->m_Material.m_pAttribute = nullptr;
  this->m_Material.m_Storage.u.m_Id = -1;
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_nLeft.m_pAttribute = nullptr;
  this->m_nLeft.m_Storage = 0;
  this->m_nTop.m_pAttribute = nullptr;
  this->m_nTop.m_Storage = 0;
  this->m_nWidth.m_pAttribute = nullptr;
  this->m_nWidth.m_Storage = 0;
  this->m_nHeight.m_pAttribute = nullptr;
  this->m_nHeight.m_Storage = 0;
  this->m_bFullScreen.m_pAttribute = nullptr;
  this->m_bFullScreen.m_Storage = false;
  this->m_bUseSubRect.m_pAttribute = nullptr;
  this->m_bUseSubRect.m_Storage = false;
  this->m_nSubRectLeft.m_pAttribute = nullptr;
  this->m_nSubRectLeft.m_Storage = 0;
  this->m_nSubRectTop.m_pAttribute = nullptr;
  this->m_nSubRectTop.m_Storage = 0;
  this->m_nSubRectWidth.m_pAttribute = nullptr;
  this->m_nSubRectWidth.m_Storage = 0;
  this->m_nSubRectHeight.m_pAttribute = nullptr;
  this->m_nSubRectHeight.m_Storage = 0;
  this->m_flMovementAngle = 0;
  this->m_flMovementSpeed = 0;
  CMaterialReference::CMaterialReference(
    this: &this->m_OverlayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_BltMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005C8EB0
// Name: public: virtual bool CDmeMaterialOverlayFXClip::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMaterialOverlayFXClip::IsA(CDmeMaterialOverlayFXClip *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMaterialOverlayFXClip::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFXClip::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeClip::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C8EF0
// Name: public: virtual int CDmeMaterialOverlayFXClip::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialOverlayFXClip::GetInheritanceDepth(
        CDmeMaterialOverlayFXClip *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMaterialOverlayFXClip::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFXClip::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeClip::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C8F50
// Name: protected: virtual void CDmeMaterialOverlayFXClip::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::PerformDestruction(CDmeMaterialOverlayFXClip *this)
{
  CMaterialReference::Shutdown(this: &this->m_BltMaterial, bDeleteIfUnreferenced: false);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x005C8F80
// Name: protected: virtual int CDmeMaterialOverlayFXClip::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialOverlayFXClip::AllocatedSize(CDmeMaterialOverlayFXClip *this)
{
  return 260;
}

//------------------------------------------------------------------------------
// Address: 0x005C8F90
// Name: protected: virtual void CDmeMaterialOverlayFXClip::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::PerformConstruction(CDmeMaterialOverlayFXClip *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeClip::OnConstruction(this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeMaterialOverlayFXClip::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00680C70
// Name: _dynamic_initializer_for__CDmeMaterialOverlayFXClip::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMaterialOverlayFXClip::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMaterialOverlayFXClip::s_Allocator,
    blockSize: 260,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMaterialOverlayFXClip pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006832C0
// Name: _dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMaterialOverlayFXClip::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00680CA0
// Name: _dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Factory__()
{
  CDmeFXClip::InstallFXClipType(pElementType: "DmeMaterialOverlayFXClip", pDescription: "Material Overlay Effect");
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00680CC0
// Name: _dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMaterialOverlayFXClip_Helper,
           classname: "DmeMaterialOverlayFXClip",
           pFactory: &g_CDmeMaterialOverlayFXClip_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006832D0
// Name: _dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeMaterialOverlayFXClip_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10252FC0
// Name: protected: virtual int CDmeMaterialOverlayFXClip::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CDmeMaterialOverlayFXClip::AllocatedSize(C_INIT_RandomSequence *this)
{
  return 260;
}

//------------------------------------------------------------------------------
// Address: 0x10596F70
// Name: public: virtual void CDmeMaterialOverlayFXClip::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::Resolve(CDmeMaterialOverlayFXClip *this)
{
  const char *m_pAsString; // eax

  if ( SLOBYTE(this->m_Material.m_pAttribute->m_nFlags) < 0 )
  {
    CMaterialReference::Shutdown(this: &this->m_OverlayMaterial, bDeleteIfUnreferenced: false);
    m_pAsString = this->m_Material.m_Storage.u.m_pAsString;
    if ( m_pAsString != (const char *)-1 && m_pAsString != nullptr && *m_pAsString != 0 )
      CMaterialReference::Init(
        this: &this->m_OverlayMaterial,
        pMaterialName: m_pAsString,
        pTextureGroupName: nullptr,
        bComplain: false);
    this->m_Material.m_pAttribute->m_nFlags &= ~0x80u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10596FD0
// Name: protected: void CDmeMaterialOverlayFXClip::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::OnConstruction(CDmeMaterialOverlayFXClip *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  CDmAttribute *v4; // ecx
  CDmAttribute *v5; // ecx
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  KeyValues *Key; // eax
  Color value; // [esp+Ch] [ebp-8h] BYREF
  bool v10; // [esp+13h] [ebp-1h] BYREF

  this->m_Material.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "material",
                                    type: AT_STRING,
                                    pMemory: &this->m_Material);
  this->m_Color.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "overlaycolor",
                                 type: AT_COLOR,
                                 pMemory: &this->m_Color);
  this->m_nLeft.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "left",
                                 type: AT_INT,
                                 pMemory: &this->m_nLeft);
  this->m_nTop.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "top",
                                type: AT_INT,
                                pMemory: &this->m_nTop);
  this->m_nWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "width",
                                  type: AT_INT,
                                  pMemory: &this->m_nWidth);
  this->m_nHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "height",
                                   type: AT_INT,
                                   pMemory: &this->m_nHeight);
  this->m_bFullScreen.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "fullscreen",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bFullScreen);
  this->m_bUseSubRect.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "useSubRect",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bUseSubRect);
  this->m_flMovementAngle.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "movementAngle",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flMovementAngle);
  this->m_flMovementSpeed.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "movementSpeed",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flMovementSpeed);
  this->m_nSubRectLeft.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "subRectLeft",
                                        type: AT_INT,
                                        pMemory: &this->m_nSubRectLeft);
  this->m_nSubRectTop.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "subRectTop",
                                       type: AT_INT,
                                       pMemory: &this->m_nSubRectTop);
  this->m_nSubRectWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "subRectWidth",
                                         type: AT_INT,
                                         pMemory: &this->m_nSubRectWidth);
  this->m_nSubRectHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "subRectHeight",
                                          type: AT_INT,
                                          pMemory: &this->m_nSubRectHeight);
  m_pAttribute = this->m_Color.m_pAttribute;
  value = (Color)-1;
  CDmAttribute::SetValue<Color>(this: m_pAttribute, &value);
  v3 = this->m_bFullScreen.m_pAttribute;
  v10 = true;
  CDmAttribute::SetValue<bool>(this: v3, value: &v10);
  v4 = this->m_nTop.m_pAttribute;
  value = 0;
  CDmAttribute::SetValue<int>(this: v4, (int *)&value);
  CDmAttribute::SetValue<int>(this: this->m_nLeft.m_pAttribute, value: &this->m_nTop.m_Storage);
  v5 = this->m_nHeight.m_pAttribute;
  value = (Color)1;
  CDmAttribute::SetValue<int>(this: v5, (int *)&value);
  CDmAttribute::SetValue<int>(this: this->m_nWidth.m_pAttribute, value: &this->m_nHeight.m_Storage);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "accumbuff4sample");
  else
    v7 = nullptr;
  KeyValues::SetString(this: v7, keyName: "$INPUT", value: "Effects/FilmScan256");
  Key = KeyValues::FindKey(this: v7, keyName: "proxies", bCreate: true);
  KeyValues::FindKey(this: Key, keyName: "sfm_blt", bCreate: true);
  CMaterialReference::Init(this: &this->m_BltMaterial, pMaterialName: "accumbuff4sample", pVMTKeyValues: v7);
  this->m_BltMaterial.m_pMaterial->Refresh(this: this->m_BltMaterial.m_pMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x10597220
// Name: private: void CDmeMaterialOverlayFXClip::DrawQuad(int,int,int,int,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeMaterialOverlayFXClip::DrawQuad(
        CDmeMaterialOverlayFXClip *this@<ecx>,
        int a2@<edi>,
        int x,
        int y,
        int w,
        int h,
        float u0,
        float v0,
        float u1,
        float v1)
{
  IMatRenderContext *v10; // esi
  IMesh *v11; // esi
  float *m_pCurrPosition; // eax
  float *v13; // eax
  float *v14; // eax
  float *v15; // eax
  int v16; // eax
  float *v17; // eax
  float v18; // xmm5_4
  float *v19; // eax
  float *v20; // eax
  float *v21; // eax
  int v22; // eax
  float *v23; // eax
  float v24; // xmm2_4
  float *v25; // eax
  float *v26; // eax
  float *v27; // eax
  int v28; // eax
  float *v29; // eax
  float *v30; // eax
  float *v31; // eax
  float *v32; // eax
  int m_nVertexCount; // eax
  int v34; // ecx
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1ECh] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F0h] [ebp-4h]

  v10 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v10;
  if ( v10 != nullptr )
    v10->BeginRender(this: v10);
  v11 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, int))v10->GetDynamicMesh)(
                   a1: v10,
                   a2: 1,
                   a3: 0,
                   a4: 0,
                   a5: 0,
                   a6: a2);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v11;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_TRIANGLE_STRIP;
  v11->SetPrimitiveType(this: v11, a2: MATERIAL_TRIANGLE_STRIP);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 4, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v11->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 4;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v11, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)x;
  m_pCurrPosition[1] = (float)y;
  m_pCurrPosition[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v13 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u0;
  v13[1] = v0;
  v14 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 0.0;
  v14[1] = 0.0;
  v15 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v15[1] = 0.0;
  v16 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v16;
  if ( v16 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v16;
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  v17 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v17;
  *v17 = (float)x;
  v18 = (float)(h + y);
  v17[1] = v18;
  v17[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v19 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u0;
  v19[1] = v1;
  v20 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 0.0;
  v20[1] = 1.0;
  v21 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v21[1] = 0.0;
  v22 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v22;
  if ( v22 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v22;
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  v23 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v23;
  v24 = (float)(w + x);
  *v23 = v24;
  v23[1] = (float)y;
  v23[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v25 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u1;
  v25[1] = v0;
  v26 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 1.0;
  v26[1] = 0.0;
  v27 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v27[1] = 0.0;
  v28 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v28;
  if ( v28 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v28;
  v29 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v29;
  *v29 = v24;
  v29[1] = v18;
  v29[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v30 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u1;
  v30[1] = v1;
  v31 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 1.0;
  v31[1] = 1.0;
  v32 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v32[1] = 0.0;
  m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  v34 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v34;
  if ( v34 > meshBuilder.m_VertexBuilder.m_nVertexCount )
  {
    m_nVertexCount = v34;
    meshBuilder.m_VertexBuilder.m_nVertexCount = v34;
  }
  meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount *= 2;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  }
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
  v11->Draw_2(this: v11, a2: -1, a3: 0);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x10597720
// Name: private: void CDmeMaterialOverlayFXClip::DrawOneToOneQuad(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::DrawOneToOneQuad(CDmeMaterialOverlayFXClip *this, int nWidth, int nHeight)
{
  IMatRenderContext *v3; // esi
  IMesh *v4; // esi
  float *m_pCurrPosition; // eax
  float v6; // xmm0_4
  float *v7; // eax
  int v8; // eax
  float *v9; // eax
  float *v10; // eax
  int v11; // eax
  float *v12; // eax
  float *v13; // eax
  float v14; // xmm0_4
  int v15; // eax
  float *v16; // eax
  float *v17; // eax
  int m_nVertexCount; // eax
  int v19; // ecx
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1ECh] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F0h] [ebp-4h]
  float fHeightEpsilon; // [esp+200h] [ebp+Ch]

  v3 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v3;
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  v4 = v3->GetDynamicMesh(this: v3, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v4;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_QUADS;
  fHeightEpsilon = 0.5 / (float)nHeight;
  v4->SetPrimitiveType(this: v4, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v4->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v4, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v6 = 0.5 / (float)nWidth;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = -1.0;
  m_pCurrPosition[1] = 1.0;
  m_pCurrPosition[2] = 0.5;
  v7 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v6;
  v7[1] = fHeightEpsilon;
  v8 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v8;
  if ( v8 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v8;
  v9 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v9;
  *v9 = -1.0;
  v9[1] = -1.0;
  v9[2] = 0.5;
  v10 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v6;
  v10[1] = fHeightEpsilon + 1.0;
  v11 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v11;
  if ( v11 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v11;
  v12 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v12;
  *v12 = 1.0;
  v12[1] = -1.0;
  v12[2] = 0.5;
  v13 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  v14 = v6 + 1.0;
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v14;
  v13[1] = fHeightEpsilon + 1.0;
  v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
  if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
  v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
  *v16 = 1.0;
  v16[1] = 1.0;
  v16[2] = 0.5;
  v17 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v14;
  v17[1] = fHeightEpsilon;
  m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  v19 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v19;
  if ( v19 > meshBuilder.m_VertexBuilder.m_nVertexCount )
  {
    m_nVertexCount = v19;
    meshBuilder.m_VertexBuilder.m_nVertexCount = v19;
  }
  meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount *= 2;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  }
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v4->Draw_2(this: v4, a2: -1, a3: 0);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x10597A90
// Name: public: virtual void CDmeMaterialOverlayFXClip::ApplyEffect(class DmeTime_t,struct Rect_t __near &,struct Rect_t __near &,class ITexture __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeMaterialOverlayFXClip::ApplyEffect(
        CDmeMaterialOverlayFXClip *this@<ecx>,
        int a2@<edi>,
        DmeTime_t time,
        Rect_t *currentRect,
        int totalRect,
        float pTextures)
{
  int width; // edx
  int y; // ecx
  Rect_t *v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // edx
  int v17; // eax
  int v18; // edx
  int v19; // eax
  int v20; // eax
  int v21; // edx
  int v22; // eax
  IMaterial *m_pMaterial; // ecx
  int v24; // eax
  bool v25; // zf
  float v26; // xmm5_4
  float v27; // xmm6_4
  float m_Storage; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm3_4
  float v31; // xmm1_4
  double v32; // xmm0_8
  double v33; // xmm0_8
  double v34; // xmm0_8
  float v35; // xmm1_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm3_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  int v42; // eax
  bool v43; // al
  Rect_t *v44; // edi
  long double v46; // [esp+10h] [ebp-50h] BYREF
  int v47; // [esp+18h] [ebp-48h] BYREF
  int v48; // [esp+1Ch] [ebp-44h] BYREF
  DmeTime_t result; // [esp+20h] [ebp-40h] BYREF
  float v50; // [esp+24h] [ebp-3Ch]
  float v51; // [esp+28h] [ebp-38h]
  float v52; // [esp+2Ch] [ebp-34h]
  float v53; // [esp+30h] [ebp-30h]
  float v54; // [esp+34h] [ebp-2Ch]
  float v55; // [esp+38h] [ebp-28h]
  float v56; // [esp+3Ch] [ebp-24h]
  float v57; // [esp+40h] [ebp-20h]
  float v58; // [esp+44h] [ebp-1Ch]
  int v59; // [esp+48h] [ebp-18h]
  int v60; // [esp+4Ch] [ebp-14h]
  int v61; // [esp+50h] [ebp-10h]
  int nWidth; // [esp+54h] [ebp-Ch]
  int nHeight; // [esp+58h] [ebp-8h]
  int x; // [esp+5Ch] [ebp-4h]
  int t; // [esp+68h] [ebp+8h]
  int v66; // [esp+6Ch] [ebp+Ch]
  int v67; // [esp+6Ch] [ebp+Ch]

  if ( this->m_OverlayMaterial.m_pMaterial == nullptr
    || this->m_BltMaterial.m_pMaterial == nullptr
    || this->m_Color.m_Storage._color[3] == 0 )
  {
    return;
  }
  t = CDmeClip::ToChildMediaTime(this, &result, t: time, bClamp: nullptr)->m_tms;
  width = currentRect->width;
  if ( this->m_bFullScreen.m_Storage )
  {
    y = currentRect->y;
    x = currentRect->x;
    nHeight = currentRect->height;
    v66 = y;
    v10 = *(Rect_t **)(totalRect + 8);
    nWidth = width;
    v11 = *(_DWORD *)(totalRect + 12);
    v59 = 0;
    v61 = 0;
    totalRect = (int)v10;
    v60 = v11;
LABEL_22:
    if ( totalRect != 0 && v60 != 0 )
    {
      v22 = ((int (__thiscall *)(IMaterial *, int))this->m_OverlayMaterial.m_pMaterial->GetMappingWidth)(
              a1: this->m_OverlayMaterial.m_pMaterial,
              a2);
      m_pMaterial = this->m_OverlayMaterial.m_pMaterial;
      v53 = *(float *)&v22;
      v24 = m_pMaterial->GetMappingHeight(this: m_pMaterial);
      v25 = !this->m_bUseSubRect.m_Storage;
      v26 = (float)SLODWORD(v53);
      v27 = (float)v24;
      m_Storage = 0.0;
      v29 = (float)SLODWORD(v53);
      v30 = 0.0;
      v31 = (float)v24;
      v56 = 0.0;
      v50 = (float)SLODWORD(v53);
      v55 = (float)SLODWORD(v53);
      v54 = 0.0;
      *(float *)&result.m_tms = (float)v24;
      v53 = (float)v24;
      if ( !v25 )
      {
        m_Storage = (float)this->m_nSubRectLeft.m_Storage;
        v30 = (float)this->m_nSubRectTop.m_Storage;
        v29 = (float)this->m_nSubRectWidth.m_Storage + m_Storage;
        v31 = (float)this->m_nSubRectHeight.m_Storage + v30;
        v56 = m_Storage;
        v54 = v30;
        v55 = v29;
        v53 = v31;
      }
      v58 = this->m_flMovementSpeed.m_Storage;
      if ( v58 != 0.0 )
      {
        v32 = this->m_flMovementAngle.m_Storage;
        v57 = (float)t * 0.000099999997;
        v52 = v32 * 3.141592653589793 * 0.005555555555555556;
        v33 = v52;
        __libm_sse2_cos(x: v46);
        *(float *)&v33 = v33;
        v51 = COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&v33 * v58) ^ _mask__NegFloat_) * v57;
        v34 = v52;
        __libm_sse2_sin(x: v46);
        v26 = v50;
        v27 = *(float *)&result.m_tms;
        v35 = v34;
        v36 = (float)(v35 * v58) * v57;
        m_Storage = v51 + v56;
        v29 = v51 + v55;
        v30 = v36 + v54;
        v31 = v36 + v53;
      }
      v37 = (float)(m_Storage + 0.5) / v26;
      v38 = (float)((float)(v29 - 0.5) / v26) - v37;
      v39 = (float)(v30 + 0.5) / v27;
      v40 = (float)((float)(v31 - 0.5) / v27) - v39;
      v52 = (float)((float)((x - v61) / totalRect) * v38) + v37;
      v50 = (float)((float)((x + nWidth - v61) / totalRect) * v38) + v37;
      v41 = (float)((float)((v66 - v59) / v60) * v40) + v39;
      v42 = (v66 + nHeight - v59) / v60;
      v67 = v66 - currentRect->y;
      v51 = v41;
      x -= currentRect->x;
      *(float *)&result.m_tms = (float)((float)v42 * v40) + v39;
      CMatRenderContextPtr::CMatRenderContextPtr(this: (CMatRenderContextPtr *)&totalRect, pFrom: materials);
      v43 = this->m_OverlayMaterial.m_pMaterial->NeedsPowerOfTwoFrameBufferTexture(
              this: this->m_OverlayMaterial.m_pMaterial,
              a2: true);
      v44 = (Rect_t *)totalRect;
      if ( v43 )
      {
        (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)totalRect + 36))(
          a1: totalRect,
          a2: this->m_BltMaterial.m_pMaterial,
          a3: *(_DWORD *)LODWORD(pTextures));
        (*(void (__thiscall **)(Rect_t *, ITexture *, _DWORD, _DWORD, int, int))(v44->x + 432))(
          a1: v44,
          a2: *(ITexture **)(LODWORD(pTextures) + 4),
          a3: 0,
          a4: 0,
          a5: nWidth,
          a6: nHeight);
        CDmeMaterialOverlayFXClip::DrawOneToOneQuad(this, nWidth, nHeight);
        (*(void (__thiscall **)(Rect_t *))(v44->x + 444))(a1: v44);
        (*(void (__thiscall **)(Rect_t *, ITexture *, _DWORD))(v44->x + 72))(
          a1: v44,
          a2: *(ITexture **)(LODWORD(pTextures) + 4),
          a3: 0);
        (*(void (__thiscall **)(Rect_t *, _DWORD, _DWORD, _DWORD, int, int))(v44->x + 432))(
          a1: v44,
          a2: *(_DWORD *)LODWORD(pTextures),
          a3: 0,
          a4: 0,
          a5: nWidth,
          a6: nHeight);
      }
      this->m_OverlayMaterial.m_pMaterial->GetColorModulation(
        this: this->m_OverlayMaterial.m_pMaterial,
        a2: (float *)((char *)&v46 + 4),
        a3: (float *)&v47,
        a4: (float *)&v48);
      pTextures = this->m_OverlayMaterial.m_pMaterial->GetAlphaModulation(this: this->m_OverlayMaterial.m_pMaterial);
      ((void (__thiscall *)(IMaterial *, _DWORD, _DWORD, _DWORD))this->m_OverlayMaterial.m_pMaterial->ColorModulate)(
        a1: this->m_OverlayMaterial.m_pMaterial,
        a2: (float)this->m_Color.m_Storage._color[0] * 0.0039215689,
        a3: (float)this->m_Color.m_Storage._color[1] * 0.0039215689,
        a4: (float)this->m_Color.m_Storage._color[2] * 0.0039215689);
      ((void (__stdcall *)(_DWORD))this->m_OverlayMaterial.m_pMaterial->AlphaModulate)(a1: (float)this->m_Color.m_Storage._color[3] * 0.0039215689);
      (*(void (__thiscall **)(Rect_t *, IMaterial *, _DWORD))(v44->x + 36))(
        a1: v44,
        a2: this->m_OverlayMaterial.m_pMaterial,
        a3: 0);
      CDmeMaterialOverlayFXClip::DrawQuad(
        this,
        a2: (int)v44,
        x,
        y: v67,
        w: nWidth,
        h: nHeight,
        u0: v52,
        v0: v51,
        u1: v50,
        v1: *(float *)&result.m_tms);
      if ( this->m_OverlayMaterial.m_pMaterial->NeedsPowerOfTwoFrameBufferTexture(
             this: this->m_OverlayMaterial.m_pMaterial,
             a2: true) )
      {
        (*(void (__thiscall **)(Rect_t *))(v44->x + 444))(a1: v44);
      }
      ((void (__thiscall *)(IMaterial *, _DWORD, int))this->m_OverlayMaterial.m_pMaterial->ColorModulate)(
        a1: this->m_OverlayMaterial.m_pMaterial,
        a2: HIDWORD(v46),
        a3: v47);
      ((void (__stdcall *)(_DWORD))this->m_OverlayMaterial.m_pMaterial->AlphaModulate)(a1: LODWORD(pTextures));
      CMatRenderContextPtr::~CMatRenderContextPtr(this: (CMatRenderContextPtr *)&totalRect);
    }
    return;
  }
  v12 = currentRect->x;
  v13 = this->m_nLeft.m_Storage;
  v14 = currentRect->x + width;
  v53 = *(float *)&v14;
  if ( v13 >= v12 )
  {
    x = v14;
    if ( v13 <= v14 )
      x = v13;
  }
  else
  {
    x = v12;
  }
  v15 = currentRect->y;
  totalRect = v15 + currentRect->height;
  v16 = this->m_nTop.m_Storage;
  if ( v16 >= v15 )
  {
    v66 = totalRect;
    if ( v16 <= totalRect )
      v66 = this->m_nTop.m_Storage;
  }
  else
  {
    v66 = v15;
  }
  v17 = this->m_nLeft.m_Storage + this->m_nWidth.m_Storage;
  if ( v17 >= v12 )
  {
    v12 = LODWORD(v53);
    if ( v17 <= SLODWORD(v53) )
      v12 = this->m_nLeft.m_Storage + this->m_nWidth.m_Storage;
  }
  v18 = this->m_nHeight.m_Storage + v16;
  v19 = currentRect->y;
  if ( v18 >= v19 )
  {
    v19 = totalRect;
    if ( v18 <= totalRect )
      v19 = v18;
  }
  v20 = v19 - v66;
  v61 = this->m_nLeft.m_Storage;
  v59 = this->m_nTop.m_Storage;
  totalRect = this->m_nWidth.m_Storage;
  v21 = this->m_nHeight.m_Storage;
  nWidth = v12 - x;
  nHeight = v20;
  v60 = v21;
  if ( v12 - x > 0 && v20 > 0 )
    goto LABEL_22;
}

//------------------------------------------------------------------------------
// Address: 0x105980A0
// Name: protected: CDmeMaterialOverlayFXClip::CDmeMaterialOverlayFXClip(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMaterialOverlayFXClip *__thiscall CDmeMaterialOverlayFXClip::CDmeMaterialOverlayFXClip(
        CDmeMaterialOverlayFXClip *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeMaterialOverlayFXClip_vtbl *)&CDmeClip::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_TrackGroups);
  this->m_TimeFrame.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_TimeFrame.m_pAttribute = nullptr;
  this->m_TimeFrame.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_ClipColor.m_pAttribute = nullptr;
  this->m_ClipColor.m_Storage = (Color)-16777216;
  this->m_bMute.m_pAttribute = nullptr;
  this->m_bMute.m_Storage = false;
  this->m_flDisplayScale = 0;
  this->m_ClipText.m_pAttribute = nullptr;
  this->m_ClipText.m_Storage.u.CDmeFXClip::CDmeClip::m_Id = -1;
  this->__vftable = (CDmeMaterialOverlayFXClip_vtbl *)&CDmeMaterialOverlayFXClip::`vftable';
  this->m_Material.m_pAttribute = nullptr;
  this->m_Material.m_Storage.u.m_Id = -1;
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_nLeft.m_pAttribute = nullptr;
  this->m_nLeft.m_Storage = 0;
  this->m_nTop.m_pAttribute = nullptr;
  this->m_nTop.m_Storage = 0;
  this->m_nWidth.m_pAttribute = nullptr;
  this->m_nWidth.m_Storage = 0;
  this->m_nHeight.m_pAttribute = nullptr;
  this->m_nHeight.m_Storage = 0;
  this->m_bFullScreen.m_pAttribute = nullptr;
  this->m_bFullScreen.m_Storage = false;
  this->m_bUseSubRect.m_pAttribute = nullptr;
  this->m_bUseSubRect.m_Storage = false;
  this->m_nSubRectLeft.m_pAttribute = nullptr;
  this->m_nSubRectLeft.m_Storage = 0;
  this->m_nSubRectTop.m_pAttribute = nullptr;
  this->m_nSubRectTop.m_Storage = 0;
  this->m_nSubRectWidth.m_pAttribute = nullptr;
  this->m_nSubRectWidth.m_Storage = 0;
  this->m_nSubRectHeight.m_pAttribute = nullptr;
  this->m_nSubRectHeight.m_Storage = 0;
  this->m_flMovementAngle = 0;
  this->m_flMovementSpeed = 0;
  CMaterialReference::CMaterialReference(
    this: &this->m_OverlayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_BltMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x105981F0
// Name: public: virtual bool CDmeMaterialOverlayFXClip::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMaterialOverlayFXClip::IsA(CDmeMaterialOverlayFXClip *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMaterialOverlayFXClip::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFXClip::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeClip::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x10598230
// Name: public: virtual int CDmeMaterialOverlayFXClip::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialOverlayFXClip::GetInheritanceDepth(
        CDmeMaterialOverlayFXClip *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMaterialOverlayFXClip::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFXClip::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeClip::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10598290
// Name: protected: virtual void CDmeMaterialOverlayFXClip::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::PerformDestruction(CDmeMaterialOverlayFXClip *this)
{
  CMaterialReference::Shutdown(this: &this->m_BltMaterial, bDeleteIfUnreferenced: false);
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
}

//------------------------------------------------------------------------------
// Address: 0x105982C0
// Name: protected: virtual void CDmeMaterialOverlayFXClip::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::PerformConstruction(CDmeMaterialOverlayFXClip *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeClip::OnConstruction(this);
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeMaterialOverlayFXClip::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x105C99B0
// Name: _dynamic_initializer_for__CDmeMaterialOverlayFXClip::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMaterialOverlayFXClip::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMaterialOverlayFXClip::s_Allocator,
    blockSize: 260,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMaterialOverlayFXClip pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CDB50
// Name: _dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMaterialOverlayFXClip::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105C99E0
// Name: _dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Factory__()
{
  CDmeFXClip::InstallFXClipType(pElementType: "DmeMaterialOverlayFXClip", pDescription: "Material Overlay Effect");
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9A00
// Name: _dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMaterialOverlayFXClip_Helper,
           classname: "DmeMaterialOverlayFXClip",
           pFactory: &g_CDmeMaterialOverlayFXClip_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CDB60
// Name: _dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeMaterialOverlayFXClip_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x00566BB0
// Name: public: virtual void CDmeMaterialOverlayFXClip::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::Resolve(CDmeMaterialOverlayFXClip *this)
{
  const char *m_pAsString; // eax

  if ( SLOBYTE(this->m_Material.m_pAttribute->m_nFlags) < 0 )
  {
    CMaterialReference::Shutdown(this: &this->m_OverlayMaterial, bDeleteIfUnreferenced: false);
    m_pAsString = this->m_Material.m_Storage.u.m_pAsString;
    if ( m_pAsString != (const char *)-1 && m_pAsString != nullptr && *m_pAsString != 0 )
      CMaterialReference::Init(
        this: &this->m_OverlayMaterial,
        pMaterialName: m_pAsString,
        pTextureGroupName: nullptr,
        bComplain: false);
    this->m_Material.m_pAttribute->m_nFlags &= ~0x80u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00566C10
// Name: protected: void CDmeMaterialOverlayFXClip::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::OnConstruction(CDmeMaterialOverlayFXClip *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  CDmAttribute *v4; // ecx
  CDmAttribute *v5; // ecx
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  KeyValues *Key; // eax
  Color value; // [esp+Ch] [ebp-8h] BYREF
  bool v10; // [esp+13h] [ebp-1h] BYREF

  this->m_Material.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "material",
                                    type: AT_STRING,
                                    pMemory: &this->m_Material);
  this->m_Color.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "overlaycolor",
                                 type: AT_COLOR,
                                 pMemory: &this->m_Color);
  this->m_nLeft.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "left",
                                 type: AT_INT,
                                 pMemory: &this->m_nLeft);
  this->m_nTop.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "top",
                                type: AT_INT,
                                pMemory: &this->m_nTop);
  this->m_nWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "width",
                                  type: AT_INT,
                                  pMemory: &this->m_nWidth);
  this->m_nHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "height",
                                   type: AT_INT,
                                   pMemory: &this->m_nHeight);
  this->m_bFullScreen.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "fullscreen",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bFullScreen);
  this->m_bUseSubRect.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "useSubRect",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bUseSubRect);
  this->m_flMovementAngle.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "movementAngle",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flMovementAngle);
  this->m_flMovementSpeed.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "movementSpeed",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flMovementSpeed);
  this->m_nSubRectLeft.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "subRectLeft",
                                        type: AT_INT,
                                        pMemory: &this->m_nSubRectLeft);
  this->m_nSubRectTop.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "subRectTop",
                                       type: AT_INT,
                                       pMemory: &this->m_nSubRectTop);
  this->m_nSubRectWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "subRectWidth",
                                         type: AT_INT,
                                         pMemory: &this->m_nSubRectWidth);
  this->m_nSubRectHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "subRectHeight",
                                          type: AT_INT,
                                          pMemory: &this->m_nSubRectHeight);
  m_pAttribute = this->m_Color.m_pAttribute;
  value = (Color)-1;
  CDmAttribute::SetValue<Color>(this: m_pAttribute, &value);
  v3 = this->m_bFullScreen.m_pAttribute;
  v10 = true;
  CDmAttribute::SetValue<bool>(this: v3, value: &v10);
  v4 = this->m_nTop.m_pAttribute;
  value = 0;
  CDmAttribute::SetValue<int>(this: v4, (int *)&value);
  CDmAttribute::SetValue<int>(this: this->m_nLeft.m_pAttribute, value: &this->m_nTop.m_Storage);
  v5 = this->m_nHeight.m_pAttribute;
  value = (Color)1;
  CDmAttribute::SetValue<int>(this: v5, (int *)&value);
  CDmAttribute::SetValue<int>(this: this->m_nWidth.m_pAttribute, value: &this->m_nHeight.m_Storage);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "accumbuff4sample");
  else
    v7 = nullptr;
  KeyValues::SetString(this: v7, keyName: "$INPUT", value: "Effects/FilmScan256");
  Key = KeyValues::FindKey(this: v7, keyName: "proxies", bCreate: true);
  KeyValues::FindKey(this: Key, keyName: "sfm_blt", bCreate: true);
  CMaterialReference::Init(this: &this->m_BltMaterial, pMaterialName: "accumbuff4sample", pVMTKeyValues: v7);
  this->m_BltMaterial.m_pMaterial->Refresh(this: this->m_BltMaterial.m_pMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x00566E60
// Name: private: void CDmeMaterialOverlayFXClip::DrawQuad(int,int,int,int,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeMaterialOverlayFXClip::DrawQuad(
        CDmeMaterialOverlayFXClip *this@<ecx>,
        int a2@<edi>,
        int x,
        int y,
        int w,
        int h,
        float u0,
        float v0,
        float u1,
        float v1)
{
  IMatRenderContext *v10; // esi
  IMesh *v11; // esi
  float *m_pCurrPosition; // eax
  float *v13; // eax
  float *v14; // eax
  float *v15; // eax
  int v16; // eax
  float *v17; // eax
  float v18; // xmm5_4
  float *v19; // eax
  float *v20; // eax
  float *v21; // eax
  int v22; // eax
  float *v23; // eax
  float v24; // xmm2_4
  float *v25; // eax
  float *v26; // eax
  float *v27; // eax
  int v28; // eax
  float *v29; // eax
  float *v30; // eax
  float *v31; // eax
  float *v32; // eax
  int m_nVertexCount; // eax
  int v34; // ecx
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1ECh] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F0h] [ebp-4h]

  v10 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v10;
  if ( v10 != nullptr )
    v10->BeginRender(this: v10);
  v11 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, int))v10->GetDynamicMesh)(
                   a1: v10,
                   a2: 1,
                   a3: 0,
                   a4: 0,
                   a5: 0,
                   a6: a2);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v11;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_TRIANGLE_STRIP;
  v11->SetPrimitiveType(this: v11, a2: MATERIAL_TRIANGLE_STRIP);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 4, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v11->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 4;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v11, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)x;
  m_pCurrPosition[1] = (float)y;
  m_pCurrPosition[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v13 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u0;
  v13[1] = v0;
  v14 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 0.0;
  v14[1] = 0.0;
  v15 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v15[1] = 0.0;
  v16 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v16;
  if ( v16 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v16;
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  v17 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v17;
  *v17 = (float)x;
  v18 = (float)(h + y);
  v17[1] = v18;
  v17[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v19 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u0;
  v19[1] = v1;
  v20 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 0.0;
  v20[1] = 1.0;
  v21 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v21[1] = 0.0;
  v22 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v22;
  if ( v22 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v22;
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  v23 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v23;
  v24 = (float)(w + x);
  *v23 = v24;
  v23[1] = (float)y;
  v23[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v25 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u1;
  v25[1] = v0;
  v26 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 1.0;
  v26[1] = 0.0;
  v27 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v27[1] = 0.0;
  v28 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v28;
  if ( v28 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v28;
  v29 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v29;
  *v29 = v24;
  v29[1] = v18;
  v29[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v30 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u1;
  v30[1] = v1;
  v31 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 1.0;
  v31[1] = 1.0;
  v32 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v32[1] = 0.0;
  m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  v34 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v34;
  if ( v34 > meshBuilder.m_VertexBuilder.m_nVertexCount )
  {
    m_nVertexCount = v34;
    meshBuilder.m_VertexBuilder.m_nVertexCount = v34;
  }
  meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount *= 2;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  }
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
  v11->Draw_2(this: v11, a2: -1, a3: 0);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x00567360
// Name: private: void CDmeMaterialOverlayFXClip::DrawOneToOneQuad(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::DrawOneToOneQuad(CDmeMaterialOverlayFXClip *this, int nWidth, int nHeight)
{
  IMatRenderContext *v3; // esi
  IMesh *v4; // esi
  float *m_pCurrPosition; // eax
  float v6; // xmm0_4
  float *v7; // eax
  int v8; // eax
  float *v9; // eax
  float *v10; // eax
  int v11; // eax
  float *v12; // eax
  float *v13; // eax
  float v14; // xmm0_4
  int v15; // eax
  float *v16; // eax
  float *v17; // eax
  int m_nVertexCount; // eax
  int v19; // ecx
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1ECh] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F0h] [ebp-4h]
  float fHeightEpsilon; // [esp+200h] [ebp+Ch]

  v3 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v3;
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  v4 = v3->GetDynamicMesh(this: v3, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v4;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_QUADS;
  fHeightEpsilon = 0.5 / (float)nHeight;
  v4->SetPrimitiveType(this: v4, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v4->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v4, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v6 = 0.5 / (float)nWidth;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = -1.0;
  m_pCurrPosition[1] = 1.0;
  m_pCurrPosition[2] = 0.5;
  v7 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v6;
  v7[1] = fHeightEpsilon;
  v8 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v8;
  if ( v8 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v8;
  v9 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v9;
  *v9 = -1.0;
  v9[1] = -1.0;
  v9[2] = 0.5;
  v10 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v6;
  v10[1] = fHeightEpsilon + 1.0;
  v11 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v11;
  if ( v11 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v11;
  v12 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v12;
  *v12 = 1.0;
  v12[1] = -1.0;
  v12[2] = 0.5;
  v13 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  v14 = v6 + 1.0;
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v14;
  v13[1] = fHeightEpsilon + 1.0;
  v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
  if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
  v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
  *v16 = 1.0;
  v16[1] = 1.0;
  v16[2] = 0.5;
  v17 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v14;
  v17[1] = fHeightEpsilon;
  m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  v19 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v19;
  if ( v19 > meshBuilder.m_VertexBuilder.m_nVertexCount )
  {
    m_nVertexCount = v19;
    meshBuilder.m_VertexBuilder.m_nVertexCount = v19;
  }
  meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount *= 2;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  }
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v4->Draw_2(this: v4, a2: -1, a3: 0);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x005676D0
// Name: public: virtual void CDmeMaterialOverlayFXClip::ApplyEffect(class DmeTime_t,struct Rect_t __near &,struct Rect_t __near &,class ITexture __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CDmeMaterialOverlayFXClip::ApplyEffect(
        CDmeMaterialOverlayFXClip *this@<ecx>,
        int a2@<edi>,
        DmeTime_t time,
        Rect_t *currentRect,
        int totalRect,
        float pTextures)
{
  int width; // edx
  int v9; // ecx
  Rect_t *v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // edx
  int v17; // eax
  int v18; // edx
  int v19; // eax
  int v20; // eax
  int v21; // edx
  int v22; // eax
  IMaterial *m_pMaterial; // ecx
  int v24; // eax
  bool v25; // zf
  float v26; // xmm5_4
  float v27; // xmm6_4
  float m_Storage; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm3_4
  float v31; // xmm1_4
  double v32; // xmm0_8
  double v33; // xmm0_8
  double v34; // xmm0_8
  float v35; // xmm1_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm3_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  int v42; // eax
  bool v43; // al
  Rect_t *v44; // edi
  long double v46; // [esp+78h] [ebp-50h] OVERLAPPED BYREF
  int g; // [esp+80h] [ebp-48h] BYREF
  float b; // [esp+84h] [ebp-44h] BYREF
  DmeTime_t v1; // [esp+88h] [ebp-40h] BYREF
  float u1; // [esp+8Ch] [ebp-3Ch]
  float dU; // [esp+90h] [ebp-38h]
  float flRadians; // [esp+94h] [ebp-34h]
  int mw; // [esp+98h] [ebp-30h]
  float vMin; // [esp+9Ch] [ebp-2Ch]
  float uMax; // [esp+A0h] [ebp-28h]
  float uMin; // [esp+A4h] [ebp-24h]
  float v57; // [esp+A8h] [ebp-20h]
  float v58; // [esp+ACh] [ebp-1Ch]
  int ty; // [esp+B0h] [ebp-18h]
  int th; // [esp+B4h] [ebp-14h]
  int tx; // [esp+B8h] [ebp-10h]
  int w; // [esp+BCh] [ebp-Ch]
  int h; // [esp+C0h] [ebp-8h]
  int x; // [esp+C4h] [ebp-4h]
  int timea; // [esp+D0h] [ebp+8h]
  int y; // [esp+D4h] [ebp+Ch]
  int ya; // [esp+D4h] [ebp+Ch]

  if ( this->m_OverlayMaterial.m_pMaterial == nullptr
    || this->m_BltMaterial.m_pMaterial == nullptr
    || this->m_Color.m_Storage._color[3] == 0 )
  {
    return;
  }
  timea = CDmeClip::ToChildMediaTime(this, result: &v1, t: time, bClamp: 0)->m_tms;
  width = currentRect->width;
  if ( this->m_bFullScreen.m_Storage )
  {
    v9 = currentRect->y;
    x = currentRect->x;
    h = currentRect->height;
    y = v9;
    v10 = *(Rect_t **)(totalRect + 8);
    w = width;
    v11 = *(_DWORD *)(totalRect + 12);
    ty = 0;
    tx = 0;
    totalRect = (int)v10;
    th = v11;
LABEL_22:
    if ( totalRect != 0 && th != 0 )
    {
      v22 = ((int (__thiscall *)(IMaterial *, int))this->m_OverlayMaterial.m_pMaterial->GetMappingWidth)(
              a1: this->m_OverlayMaterial.m_pMaterial,
              a2);
      m_pMaterial = this->m_OverlayMaterial.m_pMaterial;
      mw = v22;
      v24 = m_pMaterial->GetMappingHeight(this: m_pMaterial);
      v25 = !this->m_bUseSubRect.m_Storage;
      v26 = (float)mw;
      v27 = (float)v24;
      m_Storage = 0.0;
      v29 = (float)mw;
      v30 = 0.0;
      v31 = (float)v24;
      uMin = 0.0;
      u1 = (float)mw;
      uMax = (float)mw;
      vMin = 0.0;
      *(float *)&v1.m_tms = (float)v24;
      *(float *)&mw = (float)v24;
      if ( !v25 )
      {
        m_Storage = (float)this->m_nSubRectLeft.m_Storage;
        v30 = (float)this->m_nSubRectTop.m_Storage;
        v29 = (float)this->m_nSubRectWidth.m_Storage + m_Storage;
        v31 = (float)this->m_nSubRectHeight.m_Storage + v30;
        uMin = m_Storage;
        vMin = v30;
        uMax = v29;
        *(float *)&mw = v31;
      }
      v58 = this->m_flMovementSpeed.m_Storage;
      if ( v58 != 0.0 )
      {
        v32 = this->m_flMovementAngle.m_Storage;
        v57 = (float)timea * 0.000099999997;
        flRadians = v32 * 3.141592653589793 * 0.005555555555555556;
        v33 = flRadians;
        __libm_sse2_cos(x: v46);
        *(float *)&v33 = v33;
        dU = COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&v33 * v58) ^ _mask__NegFloat_) * v57;
        v34 = flRadians;
        __libm_sse2_sin(x: v46);
        v26 = u1;
        v27 = *(float *)&v1.m_tms;
        v35 = v34;
        v36 = (float)(v35 * v58) * v57;
        m_Storage = dU + uMin;
        v29 = dU + uMax;
        v30 = v36 + vMin;
        v31 = v36 + *(float *)&mw;
      }
      v37 = (float)(m_Storage + 0.5) / v26;
      v38 = (float)((float)(v29 - 0.5) / v26) - v37;
      v39 = (float)(v30 + 0.5) / v27;
      v40 = (float)((float)(v31 - 0.5) / v27) - v39;
      flRadians = (float)((float)((x - tx) / totalRect) * v38) + v37;
      u1 = (float)((float)((x + w - tx) / totalRect) * v38) + v37;
      v41 = (float)((float)((y - ty) / th) * v40) + v39;
      v42 = (y + h - ty) / th;
      ya = y - currentRect->y;
      dU = v41;
      x -= currentRect->x;
      *(float *)&v1.m_tms = (float)((float)v42 * v40) + v39;
      CMatRenderContextPtr::CMatRenderContextPtr(this: (CMatRenderContextPtr *)&totalRect, pFrom: materials);
      v43 = this->m_OverlayMaterial.m_pMaterial->NeedsPowerOfTwoFrameBufferTexture(
              this: this->m_OverlayMaterial.m_pMaterial,
              a2: true);
      v44 = (Rect_t *)totalRect;
      if ( v43 )
      {
        (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)totalRect + 36))(
          a1: totalRect,
          a2: this->m_BltMaterial.m_pMaterial,
          a3: *(_DWORD *)LODWORD(pTextures));
        (*(void (__thiscall **)(Rect_t *, ITexture *, _DWORD, _DWORD, int, int))(v44->x + 432))(
          a1: v44,
          a2: *(ITexture **)(LODWORD(pTextures) + 4),
          a3: 0,
          a4: 0,
          a5: w,
          a6: h);
        CDmeMaterialOverlayFXClip::DrawOneToOneQuad(this, nWidth: w, nHeight: h);
        (*(void (__thiscall **)(Rect_t *))(v44->x + 444))(a1: v44);
        (*(void (__thiscall **)(Rect_t *, ITexture *, _DWORD))(v44->x + 72))(
          a1: v44,
          a2: *(ITexture **)(LODWORD(pTextures) + 4),
          a3: 0);
        (*(void (__thiscall **)(Rect_t *, _DWORD, _DWORD, _DWORD, int, int))(v44->x + 432))(
          a1: v44,
          a2: *(_DWORD *)LODWORD(pTextures),
          a3: 0,
          a4: 0,
          a5: w,
          a6: h);
      }
      this->m_OverlayMaterial.m_pMaterial->GetColorModulation(
        this: this->m_OverlayMaterial.m_pMaterial,
        a2: (float *)((char *)&v46 + 4),
        a3: (float *)&g,
        a4: &b);
      pTextures = this->m_OverlayMaterial.m_pMaterial->GetAlphaModulation(this: this->m_OverlayMaterial.m_pMaterial);
      ((void (__thiscall *)(IMaterial *, _DWORD, _DWORD, _DWORD))this->m_OverlayMaterial.m_pMaterial->ColorModulate)(
        a1: this->m_OverlayMaterial.m_pMaterial,
        a2: (float)this->m_Color.m_Storage._color[0] * 0.0039215689,
        a3: (float)this->m_Color.m_Storage._color[1] * 0.0039215689,
        a4: (float)this->m_Color.m_Storage._color[2] * 0.0039215689);
      ((void (__stdcall *)(_DWORD))this->m_OverlayMaterial.m_pMaterial->AlphaModulate)(a1: (float)this->m_Color.m_Storage._color[3] * 0.0039215689);
      (*(void (__thiscall **)(Rect_t *, IMaterial *, _DWORD))(v44->x + 36))(
        a1: v44,
        a2: this->m_OverlayMaterial.m_pMaterial,
        a3: 0);
      CDmeMaterialOverlayFXClip::DrawQuad(
        this,
        a2: (int)v44,
        x,
        y: ya,
        w,
        h,
        u0: flRadians,
        v0: dU,
        u1,
        v1: *(float *)&v1.m_tms);
      if ( this->m_OverlayMaterial.m_pMaterial->NeedsPowerOfTwoFrameBufferTexture(
             this: this->m_OverlayMaterial.m_pMaterial,
             a2: true) )
      {
        (*(void (__thiscall **)(Rect_t *))(v44->x + 444))(a1: v44);
      }
      ((void (__thiscall *)(IMaterial *, _DWORD, int))this->m_OverlayMaterial.m_pMaterial->ColorModulate)(
        a1: this->m_OverlayMaterial.m_pMaterial,
        a2: HIDWORD(v46),
        a3: g);
      ((void (__stdcall *)(_DWORD))this->m_OverlayMaterial.m_pMaterial->AlphaModulate)(a1: LODWORD(pTextures));
      CMatRenderContextPtr::~CMatRenderContextPtr(this: (CMatRenderContextPtr *)&totalRect);
    }
    return;
  }
  v12 = currentRect->x;
  v13 = this->m_nLeft.m_Storage;
  v14 = currentRect->x + width;
  mw = v14;
  if ( v13 >= v12 )
  {
    x = v14;
    if ( v13 <= v14 )
      x = v13;
  }
  else
  {
    x = v12;
  }
  v15 = currentRect->y;
  totalRect = v15 + currentRect->height;
  v16 = this->m_nTop.m_Storage;
  if ( v16 >= v15 )
  {
    y = totalRect;
    if ( v16 <= totalRect )
      y = this->m_nTop.m_Storage;
  }
  else
  {
    y = v15;
  }
  v17 = this->m_nLeft.m_Storage + this->m_nWidth.m_Storage;
  if ( v17 >= v12 )
  {
    v12 = mw;
    if ( v17 <= mw )
      v12 = this->m_nLeft.m_Storage + this->m_nWidth.m_Storage;
  }
  v18 = this->m_nHeight.m_Storage + v16;
  v19 = currentRect->y;
  if ( v18 >= v19 )
  {
    v19 = totalRect;
    if ( v18 <= totalRect )
      v19 = v18;
  }
  v20 = v19 - y;
  tx = this->m_nLeft.m_Storage;
  ty = this->m_nTop.m_Storage;
  totalRect = this->m_nWidth.m_Storage;
  v21 = this->m_nHeight.m_Storage;
  w = v12 - x;
  h = v20;
  th = v21;
  if ( v12 - x > 0 && v20 > 0 )
    goto LABEL_22;
}

//------------------------------------------------------------------------------
// Address: 0x00567CE0
// Name: protected: CDmeMaterialOverlayFXClip::CDmeMaterialOverlayFXClip(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMaterialOverlayFXClip *__thiscall CDmeMaterialOverlayFXClip::CDmeMaterialOverlayFXClip(
        CDmeMaterialOverlayFXClip *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeMaterialOverlayFXClip_vtbl *)&CDmeClip::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_TrackGroups);
  this->m_TimeFrame.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_TimeFrame.m_pAttribute = nullptr;
  this->m_TimeFrame.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_ClipColor.m_pAttribute = nullptr;
  this->m_ClipColor.m_Storage = (Color)-16777216;
  this->m_bMute.m_pAttribute = nullptr;
  this->m_bMute.m_Storage = false;
  this->m_flDisplayScale = 0;
  this->m_ClipText.m_pAttribute = nullptr;
  this->m_ClipText.m_Storage.u.CDmeFXClip::CDmeClip::m_Id = -1;
  this->__vftable = (CDmeMaterialOverlayFXClip_vtbl *)&CDmeMaterialOverlayFXClip::`vftable';
  this->m_Material.m_pAttribute = nullptr;
  this->m_Material.m_Storage.u.m_Id = -1;
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_nLeft.m_pAttribute = nullptr;
  this->m_nLeft.m_Storage = 0;
  this->m_nTop.m_pAttribute = nullptr;
  this->m_nTop.m_Storage = 0;
  this->m_nWidth.m_pAttribute = nullptr;
  this->m_nWidth.m_Storage = 0;
  this->m_nHeight.m_pAttribute = nullptr;
  this->m_nHeight.m_Storage = 0;
  this->m_bFullScreen.m_pAttribute = nullptr;
  this->m_bFullScreen.m_Storage = false;
  this->m_bUseSubRect.m_pAttribute = nullptr;
  this->m_bUseSubRect.m_Storage = false;
  this->m_nSubRectLeft.m_pAttribute = nullptr;
  this->m_nSubRectLeft.m_Storage = 0;
  this->m_nSubRectTop.m_pAttribute = nullptr;
  this->m_nSubRectTop.m_Storage = 0;
  this->m_nSubRectWidth.m_pAttribute = nullptr;
  this->m_nSubRectWidth.m_Storage = 0;
  this->m_nSubRectHeight.m_pAttribute = nullptr;
  this->m_nSubRectHeight.m_Storage = 0;
  this->m_flMovementAngle = 0;
  this->m_flMovementSpeed = 0;
  CMaterialReference::CMaterialReference(
    this: &this->m_OverlayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_BltMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00567E30
// Name: public: virtual bool CDmeMaterialOverlayFXClip::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMaterialOverlayFXClip::IsA(CDmeMaterialOverlayFXClip *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMaterialOverlayFXClip::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFXClip::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeClip::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00567E70
// Name: public: virtual int CDmeMaterialOverlayFXClip::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialOverlayFXClip::GetInheritanceDepth(
        CDmeMaterialOverlayFXClip *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMaterialOverlayFXClip::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFXClip::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeClip::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00567ED0
// Name: protected: virtual void CDmeMaterialOverlayFXClip::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::PerformDestruction(CDmeMaterialOverlayFXClip *this)
{
  CMaterialReference::Shutdown(this: &this->m_BltMaterial, bDeleteIfUnreferenced: false);
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x00567F00
// Name: protected: virtual int CDmeMaterialOverlayFXClip::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialOverlayFXClip::AllocatedSize(CDmeMaterialOverlayFXClip *this)
{
  return 260;
}

//------------------------------------------------------------------------------
// Address: 0x00567F10
// Name: protected: virtual void CDmeMaterialOverlayFXClip::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::PerformConstruction(CDmeMaterialOverlayFXClip *this)
{
  CDmeFXClip::OnDestruction();
  CDmeClip::OnConstruction(this);
  CDmeFXClip::OnDestruction();
  CDmeMaterialOverlayFXClip::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0059D350
// Name: _dynamic_initializer_for__CDmeMaterialOverlayFXClip::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMaterialOverlayFXClip::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMaterialOverlayFXClip::s_Allocator,
    blockSize: 260,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMaterialOverlayFXClip pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059F900
// Name: _dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMaterialOverlayFXClip::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059D380
// Name: _dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Factory__()
{
  CDmeFXClip::InstallFXClipType(pElementType: "DmeMaterialOverlayFXClip", pDescription: "Material Overlay Effect");
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059D3A0
// Name: _dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMaterialOverlayFXClip_Helper,
           classname: "DmeMaterialOverlayFXClip",
           pFactory: &g_CDmeMaterialOverlayFXClip_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059F910
// Name: _dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMaterialOverlayFXClip_Factory.m_CallBackList);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x005AFC30
// Name: public: virtual void CDmeMaterialOverlayFXClip::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::Resolve(CDmeMaterialOverlayFXClip *this)
{
  const char *m_pAsString; // eax

  if ( SLOBYTE(this->m_Material.m_pAttribute->m_nFlags) < 0 )
  {
    CMaterialReference::Shutdown(this: &this->m_OverlayMaterial, bDeleteIfUnreferenced: false);
    m_pAsString = this->m_Material.m_Storage.u.m_pAsString;
    if ( m_pAsString != (const char *)-1 && m_pAsString != nullptr && *m_pAsString != 0 )
      CMaterialReference::Init(
        this: &this->m_OverlayMaterial,
        pMaterialName: m_pAsString,
        pTextureGroupName: nullptr,
        bComplain: false);
    this->m_Material.m_pAttribute->m_nFlags &= ~0x80u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005AFC90
// Name: protected: void CDmeMaterialOverlayFXClip::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::OnConstruction(CDmeMaterialOverlayFXClip *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  CDmAttribute *v4; // ecx
  CDmAttribute *v5; // ecx
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  KeyValues *Key; // eax
  Color value; // [esp+Ch] [ebp-8h] BYREF
  bool v10; // [esp+13h] [ebp-1h] BYREF

  this->m_Material.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "material",
                                    type: AT_STRING,
                                    pMemory: &this->m_Material);
  this->m_Color.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "overlaycolor",
                                 type: AT_COLOR,
                                 pMemory: &this->m_Color);
  this->m_nLeft.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "left",
                                 type: AT_INT,
                                 pMemory: &this->m_nLeft);
  this->m_nTop.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "top",
                                type: AT_INT,
                                pMemory: &this->m_nTop);
  this->m_nWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "width",
                                  type: AT_INT,
                                  pMemory: &this->m_nWidth);
  this->m_nHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "height",
                                   type: AT_INT,
                                   pMemory: &this->m_nHeight);
  this->m_bFullScreen.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "fullscreen",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bFullScreen);
  this->m_bUseSubRect.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "useSubRect",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bUseSubRect);
  this->m_flMovementAngle.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "movementAngle",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flMovementAngle);
  this->m_flMovementSpeed.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "movementSpeed",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flMovementSpeed);
  this->m_nSubRectLeft.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "subRectLeft",
                                        type: AT_INT,
                                        pMemory: &this->m_nSubRectLeft);
  this->m_nSubRectTop.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "subRectTop",
                                       type: AT_INT,
                                       pMemory: &this->m_nSubRectTop);
  this->m_nSubRectWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "subRectWidth",
                                         type: AT_INT,
                                         pMemory: &this->m_nSubRectWidth);
  this->m_nSubRectHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "subRectHeight",
                                          type: AT_INT,
                                          pMemory: &this->m_nSubRectHeight);
  m_pAttribute = this->m_Color.m_pAttribute;
  value = (Color)-1;
  CDmAttribute::SetValue<Color>(this: m_pAttribute, &value);
  v3 = this->m_bFullScreen.m_pAttribute;
  v10 = true;
  CDmAttribute::SetValue<bool>(this: v3, value: &v10);
  v4 = this->m_nTop.m_pAttribute;
  value = 0;
  CDmAttribute::SetValue<int>(this: v4, (int *)&value);
  CDmAttribute::SetValue<int>(this: this->m_nLeft.m_pAttribute, value: &this->m_nTop.m_Storage);
  v5 = this->m_nHeight.m_pAttribute;
  value = (Color)1;
  CDmAttribute::SetValue<int>(this: v5, (int *)&value);
  CDmAttribute::SetValue<int>(this: this->m_nWidth.m_pAttribute, value: &this->m_nHeight.m_Storage);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "accumbuff4sample");
  else
    v7 = nullptr;
  KeyValues::SetString(this: v7, keyName: "$INPUT", value: "Effects/FilmScan256");
  Key = KeyValues::FindKey(this: v7, keyName: "proxies", bCreate: true);
  KeyValues::FindKey(this: Key, keyName: "sfm_blt", bCreate: true);
  CMaterialReference::Init(this: &this->m_BltMaterial, pMaterialName: "accumbuff4sample", pVMTKeyValues: v7);
  this->m_BltMaterial.m_pMaterial->Refresh(this: this->m_BltMaterial.m_pMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x005AFEE0
// Name: private: void CDmeMaterialOverlayFXClip::DrawQuad(int,int,int,int,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeMaterialOverlayFXClip::DrawQuad(
        CDmeMaterialOverlayFXClip *this@<ecx>,
        int a2@<edi>,
        int x,
        int y,
        int w,
        int h,
        float u0,
        float v0,
        float u1,
        float v1)
{
  IMatRenderContext *v10; // esi
  IMesh *v11; // esi
  float *m_pCurrPosition; // eax
  float *v13; // eax
  float *v14; // eax
  float *v15; // eax
  int v16; // eax
  float *v17; // eax
  float v18; // xmm5_4
  float *v19; // eax
  float *v20; // eax
  float *v21; // eax
  int v22; // eax
  float *v23; // eax
  float v24; // xmm2_4
  float *v25; // eax
  float *v26; // eax
  float *v27; // eax
  int v28; // eax
  float *v29; // eax
  float *v30; // eax
  float *v31; // eax
  float *v32; // eax
  int m_nVertexCount; // eax
  int v34; // ecx
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1ECh] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F0h] [ebp-4h]

  v10 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v10;
  if ( v10 != nullptr )
    v10->BeginRender(this: v10);
  v11 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, int))v10->GetDynamicMesh)(
                   a1: v10,
                   a2: 1,
                   a3: 0,
                   a4: 0,
                   a5: 0,
                   a6: a2);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v11;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_TRIANGLE_STRIP;
  v11->SetPrimitiveType(this: v11, a2: MATERIAL_TRIANGLE_STRIP);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 4, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v11->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 4;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v11, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)x;
  m_pCurrPosition[1] = (float)y;
  m_pCurrPosition[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v13 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u0;
  v13[1] = v0;
  v14 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 0.0;
  v14[1] = 0.0;
  v15 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v15[1] = 0.0;
  v16 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v16;
  if ( v16 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v16;
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  v17 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v17;
  *v17 = (float)x;
  v18 = (float)(h + y);
  v17[1] = v18;
  v17[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v19 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u0;
  v19[1] = v1;
  v20 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 0.0;
  v20[1] = 1.0;
  v21 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v21[1] = 0.0;
  v22 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v22;
  if ( v22 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v22;
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  v23 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v23;
  v24 = (float)(w + x);
  *v23 = v24;
  v23[1] = (float)y;
  v23[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v25 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u1;
  v25[1] = v0;
  v26 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 1.0;
  v26[1] = 0.0;
  v27 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v27[1] = 0.0;
  v28 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v28;
  if ( v28 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v28;
  v29 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v29;
  *v29 = v24;
  v29[1] = v18;
  v29[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v30 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u1;
  v30[1] = v1;
  v31 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 1.0;
  v31[1] = 1.0;
  v32 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v32[1] = 0.0;
  m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  v34 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v34;
  if ( v34 > meshBuilder.m_VertexBuilder.m_nVertexCount )
  {
    m_nVertexCount = v34;
    meshBuilder.m_VertexBuilder.m_nVertexCount = v34;
  }
  meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount *= 2;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  }
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
  v11->Draw_2(this: v11, a2: -1, a3: 0);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x005B03E0
// Name: private: void CDmeMaterialOverlayFXClip::DrawOneToOneQuad(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::DrawOneToOneQuad(CDmeMaterialOverlayFXClip *this, int nWidth, int nHeight)
{
  IMatRenderContext *v3; // esi
  IMesh *v4; // esi
  float *m_pCurrPosition; // eax
  float v6; // xmm0_4
  float *v7; // eax
  int v8; // eax
  float *v9; // eax
  float *v10; // eax
  int v11; // eax
  float *v12; // eax
  float *v13; // eax
  float v14; // xmm0_4
  int v15; // eax
  float *v16; // eax
  float *v17; // eax
  int m_nVertexCount; // eax
  int v19; // ecx
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1ECh] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F0h] [ebp-4h]
  float fHeightEpsilon; // [esp+200h] [ebp+Ch]

  v3 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v3;
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  v4 = v3->GetDynamicMesh(this: v3, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v4;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_QUADS;
  fHeightEpsilon = 0.5 / (float)nHeight;
  v4->SetPrimitiveType(this: v4, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v4->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v4, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v6 = 0.5 / (float)nWidth;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = -1.0;
  m_pCurrPosition[1] = 1.0;
  m_pCurrPosition[2] = 0.5;
  v7 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v6;
  v7[1] = fHeightEpsilon;
  v8 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v8;
  if ( v8 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v8;
  v9 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v9;
  *v9 = -1.0;
  v9[1] = -1.0;
  v9[2] = 0.5;
  v10 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v6;
  v10[1] = fHeightEpsilon + 1.0;
  v11 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v11;
  if ( v11 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v11;
  v12 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v12;
  *v12 = 1.0;
  v12[1] = -1.0;
  v12[2] = 0.5;
  v13 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  v14 = v6 + 1.0;
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v14;
  v13[1] = fHeightEpsilon + 1.0;
  v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
  if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
  v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
  *v16 = 1.0;
  v16[1] = 1.0;
  v16[2] = 0.5;
  v17 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v14;
  v17[1] = fHeightEpsilon;
  m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  v19 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v19;
  if ( v19 > meshBuilder.m_VertexBuilder.m_nVertexCount )
  {
    m_nVertexCount = v19;
    meshBuilder.m_VertexBuilder.m_nVertexCount = v19;
  }
  meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount *= 2;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  }
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v4->Draw_2(this: v4, a2: -1, a3: 0);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x005B0750
// Name: public: virtual void CDmeMaterialOverlayFXClip::ApplyEffect(class DmeTime_t,struct Rect_t __near &,struct Rect_t __near &,class ITexture __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CDmeMaterialOverlayFXClip::ApplyEffect(
        CDmeMaterialOverlayFXClip *this@<ecx>,
        int a2@<edi>,
        DmeTime_t time,
        Rect_t *currentRect,
        int totalRect,
        float pTextures)
{
  int width; // edx
  int v9; // ecx
  Rect_t *v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // edx
  int v17; // eax
  int v18; // edx
  int v19; // eax
  int v20; // eax
  int v21; // edx
  int v22; // eax
  IMaterial *m_pMaterial; // ecx
  int v24; // eax
  bool v25; // zf
  float v26; // xmm5_4
  float v27; // xmm6_4
  float m_Storage; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm3_4
  float v31; // xmm1_4
  double v32; // xmm0_8
  double v33; // xmm0_8
  double v34; // xmm0_8
  float v35; // xmm1_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm3_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  int v42; // eax
  bool v43; // al
  Rect_t *v44; // edi
  long double v46; // [esp+78h] [ebp-50h] OVERLAPPED BYREF
  int g; // [esp+80h] [ebp-48h] BYREF
  float b; // [esp+84h] [ebp-44h] BYREF
  DmeTime_t v1; // [esp+88h] [ebp-40h] BYREF
  float u1; // [esp+8Ch] [ebp-3Ch]
  float dU; // [esp+90h] [ebp-38h]
  float flRadians; // [esp+94h] [ebp-34h]
  int mw; // [esp+98h] [ebp-30h]
  float vMin; // [esp+9Ch] [ebp-2Ch]
  float uMax; // [esp+A0h] [ebp-28h]
  float uMin; // [esp+A4h] [ebp-24h]
  float v57; // [esp+A8h] [ebp-20h]
  float v58; // [esp+ACh] [ebp-1Ch]
  int ty; // [esp+B0h] [ebp-18h]
  int th; // [esp+B4h] [ebp-14h]
  int tx; // [esp+B8h] [ebp-10h]
  int w; // [esp+BCh] [ebp-Ch]
  int h; // [esp+C0h] [ebp-8h]
  int x; // [esp+C4h] [ebp-4h]
  int timea; // [esp+D0h] [ebp+8h]
  int y; // [esp+D4h] [ebp+Ch]
  int ya; // [esp+D4h] [ebp+Ch]

  if ( this->m_OverlayMaterial.m_pMaterial == nullptr
    || this->m_BltMaterial.m_pMaterial == nullptr
    || this->m_Color.m_Storage._color[3] == 0 )
  {
    return;
  }
  timea = CDmeClip::ToChildMediaTime(this, result: &v1, t: time, bClamp: 0)->m_tms;
  width = currentRect->width;
  if ( this->m_bFullScreen.m_Storage )
  {
    v9 = currentRect->y;
    x = currentRect->x;
    h = currentRect->height;
    y = v9;
    v10 = *(Rect_t **)(totalRect + 8);
    w = width;
    v11 = *(_DWORD *)(totalRect + 12);
    ty = 0;
    tx = 0;
    totalRect = (int)v10;
    th = v11;
LABEL_22:
    if ( totalRect != 0 && th != 0 )
    {
      v22 = ((int (__thiscall *)(IMaterial *, int))this->m_OverlayMaterial.m_pMaterial->GetMappingWidth)(
              a1: this->m_OverlayMaterial.m_pMaterial,
              a2);
      m_pMaterial = this->m_OverlayMaterial.m_pMaterial;
      mw = v22;
      v24 = m_pMaterial->GetMappingHeight(this: m_pMaterial);
      v25 = !this->m_bUseSubRect.m_Storage;
      v26 = (float)mw;
      v27 = (float)v24;
      m_Storage = 0.0;
      v29 = (float)mw;
      v30 = 0.0;
      v31 = (float)v24;
      uMin = 0.0;
      u1 = (float)mw;
      uMax = (float)mw;
      vMin = 0.0;
      *(float *)&v1.m_tms = (float)v24;
      *(float *)&mw = (float)v24;
      if ( !v25 )
      {
        m_Storage = (float)this->m_nSubRectLeft.m_Storage;
        v30 = (float)this->m_nSubRectTop.m_Storage;
        v29 = (float)this->m_nSubRectWidth.m_Storage + m_Storage;
        v31 = (float)this->m_nSubRectHeight.m_Storage + v30;
        uMin = m_Storage;
        vMin = v30;
        uMax = v29;
        *(float *)&mw = v31;
      }
      v58 = this->m_flMovementSpeed.m_Storage;
      if ( v58 != 0.0 )
      {
        v32 = this->m_flMovementAngle.m_Storage;
        v57 = (float)timea * 0.000099999997;
        flRadians = v32 * 3.141592653589793 * 0.005555555555555556;
        v33 = flRadians;
        __libm_sse2_cos(x: v46);
        *(float *)&v33 = v33;
        dU = COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&v33 * v58) ^ _mask__NegFloat_) * v57;
        v34 = flRadians;
        __libm_sse2_sin(x: v46);
        v26 = u1;
        v27 = *(float *)&v1.m_tms;
        v35 = v34;
        v36 = (float)(v35 * v58) * v57;
        m_Storage = dU + uMin;
        v29 = dU + uMax;
        v30 = v36 + vMin;
        v31 = v36 + *(float *)&mw;
      }
      v37 = (float)(m_Storage + 0.5) / v26;
      v38 = (float)((float)(v29 - 0.5) / v26) - v37;
      v39 = (float)(v30 + 0.5) / v27;
      v40 = (float)((float)(v31 - 0.5) / v27) - v39;
      flRadians = (float)((float)((x - tx) / totalRect) * v38) + v37;
      u1 = (float)((float)((x + w - tx) / totalRect) * v38) + v37;
      v41 = (float)((float)((y - ty) / th) * v40) + v39;
      v42 = (y + h - ty) / th;
      ya = y - currentRect->y;
      dU = v41;
      x -= currentRect->x;
      *(float *)&v1.m_tms = (float)((float)v42 * v40) + v39;
      CMatRenderContextPtr::CMatRenderContextPtr(this: (CMatRenderContextPtr *)&totalRect, pFrom: materials);
      v43 = this->m_OverlayMaterial.m_pMaterial->NeedsPowerOfTwoFrameBufferTexture(
              this: this->m_OverlayMaterial.m_pMaterial,
              a2: true);
      v44 = (Rect_t *)totalRect;
      if ( v43 )
      {
        (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)totalRect + 36))(
          a1: totalRect,
          a2: this->m_BltMaterial.m_pMaterial,
          a3: *(_DWORD *)LODWORD(pTextures));
        (*(void (__thiscall **)(Rect_t *, ITexture *, _DWORD, _DWORD, int, int))(v44->x + 432))(
          a1: v44,
          a2: *(ITexture **)(LODWORD(pTextures) + 4),
          a3: 0,
          a4: 0,
          a5: w,
          a6: h);
        CDmeMaterialOverlayFXClip::DrawOneToOneQuad(this, nWidth: w, nHeight: h);
        (*(void (__thiscall **)(Rect_t *))(v44->x + 444))(a1: v44);
        (*(void (__thiscall **)(Rect_t *, ITexture *, _DWORD))(v44->x + 72))(
          a1: v44,
          a2: *(ITexture **)(LODWORD(pTextures) + 4),
          a3: 0);
        (*(void (__thiscall **)(Rect_t *, _DWORD, _DWORD, _DWORD, int, int))(v44->x + 432))(
          a1: v44,
          a2: *(_DWORD *)LODWORD(pTextures),
          a3: 0,
          a4: 0,
          a5: w,
          a6: h);
      }
      this->m_OverlayMaterial.m_pMaterial->GetColorModulation(
        this: this->m_OverlayMaterial.m_pMaterial,
        a2: (float *)((char *)&v46 + 4),
        a3: (float *)&g,
        a4: &b);
      pTextures = this->m_OverlayMaterial.m_pMaterial->GetAlphaModulation(this: this->m_OverlayMaterial.m_pMaterial);
      ((void (__thiscall *)(IMaterial *, _DWORD, _DWORD, _DWORD))this->m_OverlayMaterial.m_pMaterial->ColorModulate)(
        a1: this->m_OverlayMaterial.m_pMaterial,
        a2: (float)this->m_Color.m_Storage._color[0] * 0.0039215689,
        a3: (float)this->m_Color.m_Storage._color[1] * 0.0039215689,
        a4: (float)this->m_Color.m_Storage._color[2] * 0.0039215689);
      ((void (__stdcall *)(_DWORD))this->m_OverlayMaterial.m_pMaterial->AlphaModulate)(a1: (float)this->m_Color.m_Storage._color[3] * 0.0039215689);
      (*(void (__thiscall **)(Rect_t *, IMaterial *, _DWORD))(v44->x + 36))(
        a1: v44,
        a2: this->m_OverlayMaterial.m_pMaterial,
        a3: 0);
      CDmeMaterialOverlayFXClip::DrawQuad(
        this,
        a2: (int)v44,
        x,
        y: ya,
        w,
        h,
        u0: flRadians,
        v0: dU,
        u1,
        v1: *(float *)&v1.m_tms);
      if ( this->m_OverlayMaterial.m_pMaterial->NeedsPowerOfTwoFrameBufferTexture(
             this: this->m_OverlayMaterial.m_pMaterial,
             a2: true) )
      {
        (*(void (__thiscall **)(Rect_t *))(v44->x + 444))(a1: v44);
      }
      ((void (__thiscall *)(IMaterial *, _DWORD, int))this->m_OverlayMaterial.m_pMaterial->ColorModulate)(
        a1: this->m_OverlayMaterial.m_pMaterial,
        a2: HIDWORD(v46),
        a3: g);
      ((void (__stdcall *)(_DWORD))this->m_OverlayMaterial.m_pMaterial->AlphaModulate)(a1: LODWORD(pTextures));
      CMatRenderContextPtr::~CMatRenderContextPtr(this: (CMatRenderContextPtr *)&totalRect);
    }
    return;
  }
  v12 = currentRect->x;
  v13 = this->m_nLeft.m_Storage;
  v14 = currentRect->x + width;
  mw = v14;
  if ( v13 >= v12 )
  {
    x = v14;
    if ( v13 <= v14 )
      x = v13;
  }
  else
  {
    x = v12;
  }
  v15 = currentRect->y;
  totalRect = v15 + currentRect->height;
  v16 = this->m_nTop.m_Storage;
  if ( v16 >= v15 )
  {
    y = totalRect;
    if ( v16 <= totalRect )
      y = this->m_nTop.m_Storage;
  }
  else
  {
    y = v15;
  }
  v17 = this->m_nLeft.m_Storage + this->m_nWidth.m_Storage;
  if ( v17 >= v12 )
  {
    v12 = mw;
    if ( v17 <= mw )
      v12 = this->m_nLeft.m_Storage + this->m_nWidth.m_Storage;
  }
  v18 = this->m_nHeight.m_Storage + v16;
  v19 = currentRect->y;
  if ( v18 >= v19 )
  {
    v19 = totalRect;
    if ( v18 <= totalRect )
      v19 = v18;
  }
  v20 = v19 - y;
  tx = this->m_nLeft.m_Storage;
  ty = this->m_nTop.m_Storage;
  totalRect = this->m_nWidth.m_Storage;
  v21 = this->m_nHeight.m_Storage;
  w = v12 - x;
  h = v20;
  th = v21;
  if ( v12 - x > 0 && v20 > 0 )
    goto LABEL_22;
}

//------------------------------------------------------------------------------
// Address: 0x005B0D60
// Name: protected: CDmeMaterialOverlayFXClip::CDmeMaterialOverlayFXClip(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMaterialOverlayFXClip *__thiscall CDmeMaterialOverlayFXClip::CDmeMaterialOverlayFXClip(
        CDmeMaterialOverlayFXClip *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeMaterialOverlayFXClip_vtbl *)&CDmeClip::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_TrackGroups);
  this->m_TimeFrame.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_TimeFrame.m_pAttribute = nullptr;
  this->m_TimeFrame.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_ClipColor.m_pAttribute = nullptr;
  this->m_ClipColor.m_Storage = (Color)-16777216;
  this->m_bMute.m_pAttribute = nullptr;
  this->m_bMute.m_Storage = false;
  this->m_flDisplayScale = 0;
  this->m_ClipText.m_pAttribute = nullptr;
  this->m_ClipText.m_Storage.u.CDmeFXClip::CDmeClip::m_Id = -1;
  this->__vftable = (CDmeMaterialOverlayFXClip_vtbl *)&CDmeMaterialOverlayFXClip::`vftable';
  this->m_Material.m_pAttribute = nullptr;
  this->m_Material.m_Storage.u.m_Id = -1;
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_nLeft.m_pAttribute = nullptr;
  this->m_nLeft.m_Storage = 0;
  this->m_nTop.m_pAttribute = nullptr;
  this->m_nTop.m_Storage = 0;
  this->m_nWidth.m_pAttribute = nullptr;
  this->m_nWidth.m_Storage = 0;
  this->m_nHeight.m_pAttribute = nullptr;
  this->m_nHeight.m_Storage = 0;
  this->m_bFullScreen.m_pAttribute = nullptr;
  this->m_bFullScreen.m_Storage = false;
  this->m_bUseSubRect.m_pAttribute = nullptr;
  this->m_bUseSubRect.m_Storage = false;
  this->m_nSubRectLeft.m_pAttribute = nullptr;
  this->m_nSubRectLeft.m_Storage = 0;
  this->m_nSubRectTop.m_pAttribute = nullptr;
  this->m_nSubRectTop.m_Storage = 0;
  this->m_nSubRectWidth.m_pAttribute = nullptr;
  this->m_nSubRectWidth.m_Storage = 0;
  this->m_nSubRectHeight.m_pAttribute = nullptr;
  this->m_nSubRectHeight.m_Storage = 0;
  this->m_flMovementAngle = 0;
  this->m_flMovementSpeed = 0;
  CMaterialReference::CMaterialReference(
    this: &this->m_OverlayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_BltMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005B0EB0
// Name: public: virtual bool CDmeMaterialOverlayFXClip::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMaterialOverlayFXClip::IsA(CDmeMaterialOverlayFXClip *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMaterialOverlayFXClip::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFXClip::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeClip::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B0EF0
// Name: public: virtual int CDmeMaterialOverlayFXClip::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialOverlayFXClip::GetInheritanceDepth(
        CDmeMaterialOverlayFXClip *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMaterialOverlayFXClip::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFXClip::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeClip::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B0F50
// Name: protected: virtual void CDmeMaterialOverlayFXClip::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::PerformDestruction(CDmeMaterialOverlayFXClip *this)
{
  CMaterialReference::Shutdown(this: &this->m_BltMaterial, bDeleteIfUnreferenced: false);
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x005B0F80
// Name: protected: virtual int CDmeMaterialOverlayFXClip::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialOverlayFXClip::AllocatedSize(CDmeMaterialOverlayFXClip *this)
{
  return 260;
}

//------------------------------------------------------------------------------
// Address: 0x005B0F90
// Name: protected: virtual void CDmeMaterialOverlayFXClip::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::PerformConstruction(CDmeMaterialOverlayFXClip *this)
{
  CDmeFXClip::OnDestruction();
  CDmeClip::OnConstruction(this);
  CDmeFXClip::OnDestruction();
  CDmeMaterialOverlayFXClip::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005F1FF0
// Name: _dynamic_initializer_for__CDmeMaterialOverlayFXClip::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMaterialOverlayFXClip::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMaterialOverlayFXClip::s_Allocator,
    blockSize: 260,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMaterialOverlayFXClip pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F4C10
// Name: _dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMaterialOverlayFXClip::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F2020
// Name: _dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Factory__()
{
  CDmeFXClip::InstallFXClipType(pElementType: "DmeMaterialOverlayFXClip", pDescription: "Material Overlay Effect");
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F2040
// Name: _dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMaterialOverlayFXClip_Helper,
           classname: "DmeMaterialOverlayFXClip",
           pFactory: &g_CDmeMaterialOverlayFXClip_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F4C20
// Name: _dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMaterialOverlayFXClip_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0052BE80
// Name: public: virtual void CDmeMaterialOverlayFXClip::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::Resolve(CDmeMaterialOverlayFXClip *this)
{
  const char *m_pAsString; // eax

  if ( SLOBYTE(this->m_Material.m_pAttribute->m_nFlags) < 0 )
  {
    CMaterialReference::Shutdown(this: &this->m_OverlayMaterial, bDeleteIfUnreferenced: false);
    m_pAsString = this->m_Material.m_Storage.u.m_pAsString;
    if ( m_pAsString != (const char *)-1 && m_pAsString != nullptr && *m_pAsString != 0 )
      CMaterialReference::Init(
        this: &this->m_OverlayMaterial,
        pMaterialName: m_pAsString,
        pTextureGroupName: nullptr,
        bComplain: false);
    this->m_Material.m_pAttribute->m_nFlags &= ~0x80u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052BEE0
// Name: protected: void CDmeMaterialOverlayFXClip::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::OnConstruction(CDmeMaterialOverlayFXClip *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  CDmAttribute *v4; // ecx
  CDmAttribute *v5; // ecx
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  KeyValues *Key; // eax
  Color value; // [esp+Ch] [ebp-8h] BYREF
  bool v10; // [esp+13h] [ebp-1h] BYREF

  this->m_Material.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "material",
                                    type: AT_STRING,
                                    pMemory: &this->m_Material);
  this->m_Color.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "overlaycolor",
                                 type: AT_COLOR,
                                 pMemory: &this->m_Color);
  this->m_nLeft.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "left",
                                 type: AT_INT,
                                 pMemory: &this->m_nLeft);
  this->m_nTop.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "top",
                                type: AT_INT,
                                pMemory: &this->m_nTop);
  this->m_nWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "width",
                                  type: AT_INT,
                                  pMemory: &this->m_nWidth);
  this->m_nHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "height",
                                   type: AT_INT,
                                   pMemory: &this->m_nHeight);
  this->m_bFullScreen.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "fullscreen",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bFullScreen);
  this->m_bUseSubRect.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "useSubRect",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bUseSubRect);
  this->m_flMovementAngle.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "movementAngle",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flMovementAngle);
  this->m_flMovementSpeed.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "movementSpeed",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flMovementSpeed);
  this->m_nSubRectLeft.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "subRectLeft",
                                        type: AT_INT,
                                        pMemory: &this->m_nSubRectLeft);
  this->m_nSubRectTop.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "subRectTop",
                                       type: AT_INT,
                                       pMemory: &this->m_nSubRectTop);
  this->m_nSubRectWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "subRectWidth",
                                         type: AT_INT,
                                         pMemory: &this->m_nSubRectWidth);
  this->m_nSubRectHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "subRectHeight",
                                          type: AT_INT,
                                          pMemory: &this->m_nSubRectHeight);
  m_pAttribute = this->m_Color.m_pAttribute;
  value = (Color)-1;
  CDmAttribute::SetValue<Color>(this: m_pAttribute, &value);
  v3 = this->m_bFullScreen.m_pAttribute;
  v10 = true;
  CDmAttribute::SetValue<bool>(this: v3, value: &v10);
  v4 = this->m_nTop.m_pAttribute;
  value = 0;
  CDmAttribute::SetValue<int>(this: v4, (int *)&value);
  CDmAttribute::SetValue<int>(this: this->m_nLeft.m_pAttribute, value: &this->m_nTop.m_Storage);
  v5 = this->m_nHeight.m_pAttribute;
  value = (Color)1;
  CDmAttribute::SetValue<int>(this: v5, (int *)&value);
  CDmAttribute::SetValue<int>(this: this->m_nWidth.m_pAttribute, value: &this->m_nHeight.m_Storage);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "accumbuff4sample");
  else
    v7 = nullptr;
  KeyValues::SetString(this: v7, keyName: "$INPUT", value: "Effects/FilmScan256");
  Key = KeyValues::FindKey(this: v7, keyName: "proxies", bCreate: true);
  KeyValues::FindKey(this: Key, keyName: "sfm_blt", bCreate: true);
  CMaterialReference::Init(this: &this->m_BltMaterial, pMaterialName: "accumbuff4sample", pVMTKeyValues: v7);
  this->m_BltMaterial.m_pMaterial->Refresh(this: this->m_BltMaterial.m_pMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x0052C130
// Name: private: void CDmeMaterialOverlayFXClip::DrawQuad(int,int,int,int,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeMaterialOverlayFXClip::DrawQuad(
        CDmeMaterialOverlayFXClip *this@<ecx>,
        int a2@<edi>,
        int x,
        int y,
        int w,
        int h,
        float u0,
        float v0,
        float u1,
        float v1)
{
  IMatRenderContext *v10; // esi
  IMesh *v11; // esi
  float *m_pCurrPosition; // eax
  float *v13; // eax
  float *v14; // eax
  float *v15; // eax
  int v16; // eax
  float *v17; // eax
  float v18; // xmm5_4
  float *v19; // eax
  float *v20; // eax
  float *v21; // eax
  int v22; // eax
  float *v23; // eax
  float v24; // xmm2_4
  float *v25; // eax
  float *v26; // eax
  float *v27; // eax
  int v28; // eax
  float *v29; // eax
  float *v30; // eax
  float *v31; // eax
  float *v32; // eax
  int m_nVertexCount; // eax
  int v34; // ecx
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1ECh] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F0h] [ebp-4h]

  v10 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v10;
  if ( v10 != nullptr )
    v10->BeginRender(this: v10);
  v11 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, int))v10->GetDynamicMesh)(
                   a1: v10,
                   a2: 1,
                   a3: 0,
                   a4: 0,
                   a5: 0,
                   a6: a2);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v11;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_TRIANGLE_STRIP;
  v11->SetPrimitiveType(this: v11, a2: MATERIAL_TRIANGLE_STRIP);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 4, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v11->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 4;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v11, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)x;
  m_pCurrPosition[1] = (float)y;
  m_pCurrPosition[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v13 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u0;
  v13[1] = v0;
  v14 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 0.0;
  v14[1] = 0.0;
  v15 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v15[1] = 0.0;
  v16 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v16;
  if ( v16 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v16;
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  v17 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v17;
  *v17 = (float)x;
  v18 = (float)(h + y);
  v17[1] = v18;
  v17[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v19 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u0;
  v19[1] = v1;
  v20 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 0.0;
  v20[1] = 1.0;
  v21 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v21[1] = 0.0;
  v22 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v22;
  if ( v22 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v22;
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  v23 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v23;
  v24 = (float)(w + x);
  *v23 = v24;
  v23[1] = (float)y;
  v23[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v25 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u1;
  v25[1] = v0;
  v26 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 1.0;
  v26[1] = 0.0;
  v27 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v27[1] = 0.0;
  v28 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v28;
  if ( v28 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v28;
  v29 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v29;
  *v29 = v24;
  v29[1] = v18;
  v29[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v30 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u1;
  v30[1] = v1;
  v31 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 1.0;
  v31[1] = 1.0;
  v32 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v32[1] = 0.0;
  m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  v34 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v34;
  if ( v34 > meshBuilder.m_VertexBuilder.m_nVertexCount )
  {
    m_nVertexCount = v34;
    meshBuilder.m_VertexBuilder.m_nVertexCount = v34;
  }
  meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount *= 2;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  }
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
  v11->Draw_2(this: v11, a2: -1, a3: 0);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x0052C630
// Name: private: void CDmeMaterialOverlayFXClip::DrawOneToOneQuad(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::DrawOneToOneQuad(CDmeMaterialOverlayFXClip *this, int nWidth, int nHeight)
{
  IMatRenderContext *v3; // esi
  IMesh *v4; // esi
  float *m_pCurrPosition; // eax
  float v6; // xmm0_4
  float *v7; // eax
  int v8; // eax
  float *v9; // eax
  float *v10; // eax
  int v11; // eax
  float *v12; // eax
  float *v13; // eax
  float v14; // xmm0_4
  int v15; // eax
  float *v16; // eax
  float *v17; // eax
  int m_nVertexCount; // eax
  int v19; // ecx
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1ECh] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F0h] [ebp-4h]
  float fHeightEpsilon; // [esp+200h] [ebp+Ch]

  v3 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v3;
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  v4 = v3->GetDynamicMesh(this: v3, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v4;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_QUADS;
  fHeightEpsilon = 0.5 / (float)nHeight;
  v4->SetPrimitiveType(this: v4, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v4->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v4, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v6 = 0.5 / (float)nWidth;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = -1.0;
  m_pCurrPosition[1] = 1.0;
  m_pCurrPosition[2] = 0.5;
  v7 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v6;
  v7[1] = fHeightEpsilon;
  v8 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v8;
  if ( v8 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v8;
  v9 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v9;
  *v9 = -1.0;
  v9[1] = -1.0;
  v9[2] = 0.5;
  v10 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v6;
  v10[1] = fHeightEpsilon + 1.0;
  v11 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v11;
  if ( v11 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v11;
  v12 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v12;
  *v12 = 1.0;
  v12[1] = -1.0;
  v12[2] = 0.5;
  v13 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  v14 = v6 + 1.0;
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v14;
  v13[1] = fHeightEpsilon + 1.0;
  v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
  if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
  v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
  *v16 = 1.0;
  v16[1] = 1.0;
  v16[2] = 0.5;
  v17 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v14;
  v17[1] = fHeightEpsilon;
  m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  v19 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v19;
  if ( v19 > meshBuilder.m_VertexBuilder.m_nVertexCount )
  {
    m_nVertexCount = v19;
    meshBuilder.m_VertexBuilder.m_nVertexCount = v19;
  }
  meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount *= 2;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  }
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v4->Draw_2(this: v4, a2: -1, a3: 0);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x0052C9A0
// Name: public: virtual void CDmeMaterialOverlayFXClip::ApplyEffect(class DmeTime_t,struct Rect_t __near &,struct Rect_t __near &,class ITexture __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CDmeMaterialOverlayFXClip::ApplyEffect(
        CDmeMaterialOverlayFXClip *this@<ecx>,
        int a2@<edi>,
        DmeTime_t time,
        Rect_t *currentRect,
        int totalRect,
        float pTextures)
{
  int width; // edx
  int v9; // ecx
  Rect_t *v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // edx
  int v17; // eax
  int v18; // edx
  int v19; // eax
  int v20; // eax
  int v21; // edx
  int v22; // eax
  IMaterial *m_pMaterial; // ecx
  int v24; // eax
  bool v25; // zf
  float v26; // xmm5_4
  float v27; // xmm6_4
  float m_Storage; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm3_4
  float v31; // xmm1_4
  __m128d v32; // xmm0
  __m128 v33; // xmm1
  double v34; // xmm0_8
  double v35; // xmm0_8
  float v36; // xmm2_4
  float v37; // xmm0_4
  float v38; // xmm3_4
  float v39; // xmm1_4
  float v40; // xmm0_4
  int v41; // eax
  bool v42; // al
  Rect_t *v43; // edi
  long double v45; // [esp+78h] [ebp-50h] OVERLAPPED BYREF
  int g; // [esp+80h] [ebp-48h] BYREF
  float b; // [esp+84h] [ebp-44h] BYREF
  DmeTime_t v1; // [esp+88h] [ebp-40h] BYREF
  float u1; // [esp+8Ch] [ebp-3Ch]
  float dU; // [esp+90h] [ebp-38h]
  float flRadians; // [esp+94h] [ebp-34h]
  int mw; // [esp+98h] [ebp-30h]
  float vMin; // [esp+9Ch] [ebp-2Ch]
  float uMax; // [esp+A0h] [ebp-28h]
  float uMin; // [esp+A4h] [ebp-24h]
  float v56; // [esp+A8h] [ebp-20h]
  float v57; // [esp+ACh] [ebp-1Ch]
  int ty; // [esp+B0h] [ebp-18h]
  int th; // [esp+B4h] [ebp-14h]
  int tx; // [esp+B8h] [ebp-10h]
  int w; // [esp+BCh] [ebp-Ch]
  int h; // [esp+C0h] [ebp-8h]
  int x; // [esp+C4h] [ebp-4h]
  int timea; // [esp+D0h] [ebp+8h]
  int y; // [esp+D4h] [ebp+Ch]
  int ya; // [esp+D4h] [ebp+Ch]

  if ( this->m_OverlayMaterial.m_pMaterial == nullptr
    || this->m_BltMaterial.m_pMaterial == nullptr
    || this->m_Color.m_Storage._color[3] == 0 )
  {
    return;
  }
  timea = CDmeClip::ToChildMediaTime(this, result: &v1, t: time, bClamp: 0)->m_tms;
  width = currentRect->width;
  if ( this->m_bFullScreen.m_Storage )
  {
    v9 = currentRect->y;
    x = currentRect->x;
    h = currentRect->height;
    y = v9;
    v10 = *(Rect_t **)(totalRect + 8);
    w = width;
    v11 = *(_DWORD *)(totalRect + 12);
    ty = 0;
    tx = 0;
    totalRect = (int)v10;
    th = v11;
LABEL_22:
    if ( totalRect != 0 && th != 0 )
    {
      v22 = ((int (__thiscall *)(IMaterial *, int))this->m_OverlayMaterial.m_pMaterial->GetMappingWidth)(
              a1: this->m_OverlayMaterial.m_pMaterial,
              a2);
      m_pMaterial = this->m_OverlayMaterial.m_pMaterial;
      mw = v22;
      v24 = m_pMaterial->GetMappingHeight(this: m_pMaterial);
      v25 = !this->m_bUseSubRect.m_Storage;
      v26 = (float)mw;
      v27 = (float)v24;
      m_Storage = 0.0;
      v29 = (float)mw;
      v30 = 0.0;
      v31 = (float)v24;
      uMin = 0.0;
      u1 = (float)mw;
      uMax = (float)mw;
      vMin = 0.0;
      *(float *)&v1.m_tms = (float)v24;
      *(float *)&mw = (float)v24;
      if ( !v25 )
      {
        m_Storage = (float)this->m_nSubRectLeft.m_Storage;
        v30 = (float)this->m_nSubRectTop.m_Storage;
        v29 = (float)this->m_nSubRectWidth.m_Storage + m_Storage;
        v31 = (float)this->m_nSubRectHeight.m_Storage + v30;
        uMin = m_Storage;
        vMin = v30;
        uMax = v29;
        *(float *)&mw = v31;
      }
      v57 = this->m_flMovementSpeed.m_Storage;
      if ( v57 != 0.0 )
      {
        v32 = _mm_cvtps_pd((__m128)LODWORD(this->m_flMovementAngle.m_Storage));
        v32.m128d_f64[0] = v32.m128d_f64[0] * 3.141592653589793 * 0.005555555555555556;
        v33 = _mm_cvtpd_ps(v32);
        v56 = (float)timea * 0.000099999997;
        flRadians = v33.m128_f32[0];
        __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd(v33));
        *(float *)&v34 = v34;
        dU = COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&v34 * v57) ^ _mask__NegFloat_) * v56;
        v35 = flRadians;
        __libm_sse2_sin(x: v45);
        v26 = u1;
        v27 = *(float *)&v1.m_tms;
        v33.m128_f32[0] = v35;
        v33.m128_f32[0] = (float)(v33.m128_f32[0] * v57) * v56;
        m_Storage = dU + uMin;
        v29 = dU + uMax;
        v30 = v33.m128_f32[0] + vMin;
        v31 = v33.m128_f32[0] + *(float *)&mw;
      }
      v36 = (float)(m_Storage + 0.5) / v26;
      v37 = (float)((float)(v29 - 0.5) / v26) - v36;
      v38 = (float)(v30 + 0.5) / v27;
      v39 = (float)((float)(v31 - 0.5) / v27) - v38;
      flRadians = (float)((float)((x - tx) / totalRect) * v37) + v36;
      u1 = (float)((float)((x + w - tx) / totalRect) * v37) + v36;
      v40 = (float)((float)((y - ty) / th) * v39) + v38;
      v41 = (y + h - ty) / th;
      ya = y - currentRect->y;
      dU = v40;
      x -= currentRect->x;
      *(float *)&v1.m_tms = (float)((float)v41 * v39) + v38;
      CMatRenderContextPtr::CMatRenderContextPtr(this: (CMatRenderContextPtr *)&totalRect, pFrom: materials);
      v42 = this->m_OverlayMaterial.m_pMaterial->NeedsPowerOfTwoFrameBufferTexture(
              this: this->m_OverlayMaterial.m_pMaterial,
              a2: true);
      v43 = (Rect_t *)totalRect;
      if ( v42 )
      {
        (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)totalRect + 36))(
          a1: totalRect,
          a2: this->m_BltMaterial.m_pMaterial,
          a3: *(_DWORD *)LODWORD(pTextures));
        (*(void (__thiscall **)(Rect_t *, ITexture *, _DWORD, _DWORD, int, int))(v43->x + 432))(
          a1: v43,
          a2: *(ITexture **)(LODWORD(pTextures) + 4),
          a3: 0,
          a4: 0,
          a5: w,
          a6: h);
        CDmeMaterialOverlayFXClip::DrawOneToOneQuad(this, nWidth: w, nHeight: h);
        (*(void (__thiscall **)(Rect_t *))(v43->x + 444))(a1: v43);
        (*(void (__thiscall **)(Rect_t *, ITexture *, _DWORD))(v43->x + 72))(
          a1: v43,
          a2: *(ITexture **)(LODWORD(pTextures) + 4),
          a3: 0);
        (*(void (__thiscall **)(Rect_t *, _DWORD, _DWORD, _DWORD, int, int))(v43->x + 432))(
          a1: v43,
          a2: *(_DWORD *)LODWORD(pTextures),
          a3: 0,
          a4: 0,
          a5: w,
          a6: h);
      }
      this->m_OverlayMaterial.m_pMaterial->GetColorModulation(
        this: this->m_OverlayMaterial.m_pMaterial,
        a2: (float *)((char *)&v45 + 4),
        a3: (float *)&g,
        a4: &b);
      pTextures = this->m_OverlayMaterial.m_pMaterial->GetAlphaModulation(this: this->m_OverlayMaterial.m_pMaterial);
      ((void (__thiscall *)(IMaterial *, _DWORD, _DWORD, _DWORD))this->m_OverlayMaterial.m_pMaterial->ColorModulate)(
        a1: this->m_OverlayMaterial.m_pMaterial,
        a2: (float)this->m_Color.m_Storage._color[0] * 0.0039215689,
        a3: (float)this->m_Color.m_Storage._color[1] * 0.0039215689,
        a4: (float)this->m_Color.m_Storage._color[2] * 0.0039215689);
      ((void (__stdcall *)(_DWORD))this->m_OverlayMaterial.m_pMaterial->AlphaModulate)(a1: (float)this->m_Color.m_Storage._color[3] * 0.0039215689);
      (*(void (__thiscall **)(Rect_t *, IMaterial *, _DWORD))(v43->x + 36))(
        a1: v43,
        a2: this->m_OverlayMaterial.m_pMaterial,
        a3: 0);
      CDmeMaterialOverlayFXClip::DrawQuad(
        this,
        a2: (int)v43,
        x,
        y: ya,
        w,
        h,
        u0: flRadians,
        v0: dU,
        u1,
        v1: *(float *)&v1.m_tms);
      if ( this->m_OverlayMaterial.m_pMaterial->NeedsPowerOfTwoFrameBufferTexture(
             this: this->m_OverlayMaterial.m_pMaterial,
             a2: true) )
      {
        (*(void (__thiscall **)(Rect_t *))(v43->x + 444))(a1: v43);
      }
      ((void (__thiscall *)(IMaterial *, _DWORD, int))this->m_OverlayMaterial.m_pMaterial->ColorModulate)(
        a1: this->m_OverlayMaterial.m_pMaterial,
        a2: HIDWORD(v45),
        a3: g);
      ((void (__stdcall *)(_DWORD))this->m_OverlayMaterial.m_pMaterial->AlphaModulate)(a1: LODWORD(pTextures));
      CMatRenderContextPtr::~CMatRenderContextPtr(this: (CMatRenderContextPtr *)&totalRect);
    }
    return;
  }
  v12 = currentRect->x;
  v13 = this->m_nLeft.m_Storage;
  v14 = currentRect->x + width;
  mw = v14;
  if ( v13 >= v12 )
  {
    x = v14;
    if ( v13 <= v14 )
      x = v13;
  }
  else
  {
    x = v12;
  }
  v15 = currentRect->y;
  totalRect = v15 + currentRect->height;
  v16 = this->m_nTop.m_Storage;
  if ( v16 >= v15 )
  {
    y = totalRect;
    if ( v16 <= totalRect )
      y = this->m_nTop.m_Storage;
  }
  else
  {
    y = v15;
  }
  v17 = this->m_nLeft.m_Storage + this->m_nWidth.m_Storage;
  if ( v17 >= v12 )
  {
    v12 = mw;
    if ( v17 <= mw )
      v12 = this->m_nLeft.m_Storage + this->m_nWidth.m_Storage;
  }
  v18 = this->m_nHeight.m_Storage + v16;
  v19 = currentRect->y;
  if ( v18 >= v19 )
  {
    v19 = totalRect;
    if ( v18 <= totalRect )
      v19 = v18;
  }
  v20 = v19 - y;
  tx = this->m_nLeft.m_Storage;
  ty = this->m_nTop.m_Storage;
  totalRect = this->m_nWidth.m_Storage;
  v21 = this->m_nHeight.m_Storage;
  w = v12 - x;
  h = v20;
  th = v21;
  if ( v12 - x > 0 && v20 > 0 )
    goto LABEL_22;
}

//------------------------------------------------------------------------------
// Address: 0x0052CFB0
// Name: protected: CDmeMaterialOverlayFXClip::CDmeMaterialOverlayFXClip(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMaterialOverlayFXClip *__thiscall CDmeMaterialOverlayFXClip::CDmeMaterialOverlayFXClip(
        CDmeMaterialOverlayFXClip *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeMaterialOverlayFXClip_vtbl *)&CDmeClip::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_TrackGroups);
  this->m_TimeFrame.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_TimeFrame.m_pAttribute = nullptr;
  this->m_TimeFrame.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_ClipColor.m_pAttribute = nullptr;
  this->m_ClipColor.m_Storage = (Color)-16777216;
  this->m_bMute.m_pAttribute = nullptr;
  this->m_bMute.m_Storage = false;
  this->m_flDisplayScale = 0;
  this->m_ClipText.m_pAttribute = nullptr;
  this->m_ClipText.m_Storage.u.CDmeFXClip::CDmeClip::m_Id = -1;
  this->__vftable = (CDmeMaterialOverlayFXClip_vtbl *)&CDmeMaterialOverlayFXClip::`vftable';
  this->m_Material.m_pAttribute = nullptr;
  this->m_Material.m_Storage.u.m_Id = -1;
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_nLeft.m_pAttribute = nullptr;
  this->m_nLeft.m_Storage = 0;
  this->m_nTop.m_pAttribute = nullptr;
  this->m_nTop.m_Storage = 0;
  this->m_nWidth.m_pAttribute = nullptr;
  this->m_nWidth.m_Storage = 0;
  this->m_nHeight.m_pAttribute = nullptr;
  this->m_nHeight.m_Storage = 0;
  this->m_bFullScreen.m_pAttribute = nullptr;
  this->m_bFullScreen.m_Storage = false;
  this->m_bUseSubRect.m_pAttribute = nullptr;
  this->m_bUseSubRect.m_Storage = false;
  this->m_nSubRectLeft.m_pAttribute = nullptr;
  this->m_nSubRectLeft.m_Storage = 0;
  this->m_nSubRectTop.m_pAttribute = nullptr;
  this->m_nSubRectTop.m_Storage = 0;
  this->m_nSubRectWidth.m_pAttribute = nullptr;
  this->m_nSubRectWidth.m_Storage = 0;
  this->m_nSubRectHeight.m_pAttribute = nullptr;
  this->m_nSubRectHeight.m_Storage = 0;
  this->m_flMovementAngle = 0;
  this->m_flMovementSpeed = 0;
  CMaterialReference::CMaterialReference(
    this: &this->m_OverlayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_BltMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0052D100
// Name: public: virtual bool CDmeMaterialOverlayFXClip::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMaterialOverlayFXClip::IsA(CDmeMaterialOverlayFXClip *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMaterialOverlayFXClip::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFXClip::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeClip::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052D140
// Name: public: virtual int CDmeMaterialOverlayFXClip::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialOverlayFXClip::GetInheritanceDepth(
        CDmeMaterialOverlayFXClip *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMaterialOverlayFXClip::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFXClip::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeClip::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052D1A0
// Name: protected: virtual void CDmeMaterialOverlayFXClip::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::PerformDestruction(CDmeMaterialOverlayFXClip *this)
{
  CMaterialReference::Shutdown(this: &this->m_BltMaterial, bDeleteIfUnreferenced: false);
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x0052D1D0
// Name: protected: virtual int CDmeMaterialOverlayFXClip::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialOverlayFXClip::AllocatedSize(CDmeMaterialOverlayFXClip *this)
{
  return 260;
}

//------------------------------------------------------------------------------
// Address: 0x0052D1E0
// Name: protected: virtual void CDmeMaterialOverlayFXClip::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::PerformConstruction(CDmeMaterialOverlayFXClip *this)
{
  CDmeFXClip::OnDestruction();
  CDmeClip::OnConstruction(this);
  CDmeFXClip::OnDestruction();
  CDmeMaterialOverlayFXClip::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0056D5E0
// Name: _dynamic_initializer_for__CDmeMaterialOverlayFXClip::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMaterialOverlayFXClip::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMaterialOverlayFXClip::s_Allocator,
    blockSize: 260,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMaterialOverlayFXClip pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056F3A0
// Name: _dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMaterialOverlayFXClip::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056D610
// Name: _dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Factory__()
{
  CDmeFXClip::InstallFXClipType(pElementType: "DmeMaterialOverlayFXClip", pDescription: "Material Overlay Effect");
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056D630
// Name: _dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMaterialOverlayFXClip_Helper,
           classname: "DmeMaterialOverlayFXClip",
           pFactory: &g_CDmeMaterialOverlayFXClip_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056D650
// Name: _dynamic_initializer_for__mod_load_preload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_preload__()
{
  ConVar::ConVar(
    this: &mod_load_preload,
    pName: "mod_load_preload",
    pDefaultValue: "1.0",
    flags: 0,
    pHelpString: "Indicates how far ahead in seconds to preload animations.");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_preload__);
}

//------------------------------------------------------------------------------
// Address: 0x0056D680
// Name: _dynamic_initializer_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_showstall__()
{
  ConVar::ConVar(
    this: &mod_load_showstall,
    pName: "mod_load_showstall",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "1 - show hitches , 2 - show stalls");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_showstall__);
}

//------------------------------------------------------------------------------
// Address: 0x0056D6B0
// Name: _dynamic_initializer_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ActivityModifiersTable, growSize: 0, initSize: 16, caseInsensitive: false);
  return atexit(func: dynamic_atexit_destructor_for__g_ActivityModifiersTable__);
}

//------------------------------------------------------------------------------
// Address: 0x0056D6D0
// Name: _dynamic_initializer_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall dynamic_initializer_for__emptyMapping__(char a1)
{
  int v2; // [esp-4h] [ebp-Ch] BYREF
  CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs v3; // [esp+0h] [ebp-8h]
  int *v4; // [esp+4h] [ebp-4h]

  v4 = &v2;
  CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>::CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>(
    this: &emptyMapping.m_ActToSeqHash,
    bucketCount: 8,
    growCount: 0,
    initCount: 0,
    compareFunc: (CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs)a1,
    keyFunc: v3);
  emptyMapping.m_pStudioHdr = nullptr;
  emptyMapping.m_expectedVModel = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__emptyMapping__);
}

//------------------------------------------------------------------------------
// Address: 0x0056D720
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMaps__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__);
}

//------------------------------------------------------------------------------
// Address: 0x0056D730
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMapsLock__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMapsLock__()
{
  g_StudioHdrToActivityMapsLock.m_ownerID = 0;
  g_StudioHdrToActivityMapsLock.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0056F3B0
// Name: _dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMaterialOverlayFXClip_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056F3C0
// Name: _dynamic_atexit_destructor_for__mod_load_preload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_preload__()
{
  ConVar::~ConVar(this: &mod_load_preload);
}

//------------------------------------------------------------------------------
// Address: 0x0056F3D0
// Name: _dynamic_atexit_destructor_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_showstall__()
{
  ConVar::~ConVar(this: &mod_load_showstall);
}

//------------------------------------------------------------------------------
// Address: 0x0056F3E0
// Name: _dynamic_atexit_destructor_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ActivityModifiersTable);
}

//------------------------------------------------------------------------------
// Address: 0x0056F3F0
// Name: _dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__()
{
  CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_StudioHdrToActivityMaps.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x0056F400
// Name: _dynamic_atexit_destructor_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__emptyMapping__()
{
  CStudioHdr::CActivityToSequenceMapping::SequenceTuple *m_pSequenceTuples; // ecx

  m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
  if ( emptyMapping.m_pSequenceTuples != nullptr )
  {
    if ( emptyMapping.m_pSequenceTuples->pActivityModifiers != nullptr )
    {
      free(pMem: emptyMapping.m_pSequenceTuples->pActivityModifiers);
      m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
    }
    free(pMem: m_pSequenceTuples);
  }
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: &emptyMapping.m_ActToSeqHash);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: &emptyMapping.m_ActToSeqHash.m_Buckets);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00534340
// Name: public: virtual void CDmeMaterialOverlayFXClip::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::Resolve(CDmeMaterialOverlayFXClip *this)
{
  const char *m_pAsString; // eax

  if ( SLOBYTE(this->m_Material.m_pAttribute->m_nFlags) < 0 )
  {
    CMaterialReference::Shutdown(this: &this->m_OverlayMaterial, bDeleteIfUnreferenced: false);
    m_pAsString = this->m_Material.m_Storage.u.m_pAsString;
    if ( m_pAsString != (const char *)-1 && m_pAsString != nullptr && *m_pAsString != 0 )
      CMaterialReference::Init(
        this: &this->m_OverlayMaterial,
        pMaterialName: m_pAsString,
        pTextureGroupName: nullptr,
        bComplain: false);
    this->m_Material.m_pAttribute->m_nFlags &= ~0x80u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005343A0
// Name: protected: void CDmeMaterialOverlayFXClip::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::OnConstruction(CDmeMaterialOverlayFXClip *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  CDmAttribute *v4; // ecx
  CDmAttribute *v5; // ecx
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  KeyValues *Key; // eax
  Color value; // [esp+Ch] [ebp-8h] BYREF
  bool v10; // [esp+13h] [ebp-1h] BYREF

  this->m_Material.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "material",
                                    type: AT_STRING,
                                    pMemory: &this->m_Material);
  this->m_Color.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "overlaycolor",
                                 type: AT_COLOR,
                                 pMemory: &this->m_Color);
  this->m_nLeft.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "left",
                                 type: AT_INT,
                                 pMemory: &this->m_nLeft);
  this->m_nTop.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "top",
                                type: AT_INT,
                                pMemory: &this->m_nTop);
  this->m_nWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "width",
                                  type: AT_INT,
                                  pMemory: &this->m_nWidth);
  this->m_nHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "height",
                                   type: AT_INT,
                                   pMemory: &this->m_nHeight);
  this->m_bFullScreen.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "fullscreen",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bFullScreen);
  this->m_bUseSubRect.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "useSubRect",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bUseSubRect);
  this->m_flMovementAngle.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "movementAngle",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flMovementAngle);
  this->m_flMovementSpeed.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "movementSpeed",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flMovementSpeed);
  this->m_nSubRectLeft.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "subRectLeft",
                                        type: AT_INT,
                                        pMemory: &this->m_nSubRectLeft);
  this->m_nSubRectTop.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "subRectTop",
                                       type: AT_INT,
                                       pMemory: &this->m_nSubRectTop);
  this->m_nSubRectWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "subRectWidth",
                                         type: AT_INT,
                                         pMemory: &this->m_nSubRectWidth);
  this->m_nSubRectHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "subRectHeight",
                                          type: AT_INT,
                                          pMemory: &this->m_nSubRectHeight);
  m_pAttribute = this->m_Color.m_pAttribute;
  value = (Color)-1;
  CDmAttribute::SetValue<Color>(this: m_pAttribute, &value);
  v3 = this->m_bFullScreen.m_pAttribute;
  v10 = true;
  CDmAttribute::SetValue<bool>(this: v3, value: &v10);
  v4 = this->m_nTop.m_pAttribute;
  value = 0;
  CDmAttribute::SetValue<int>(this: v4, (int *)&value);
  CDmAttribute::SetValue<int>(this: this->m_nLeft.m_pAttribute, value: &this->m_nTop.m_Storage);
  v5 = this->m_nHeight.m_pAttribute;
  value = (Color)1;
  CDmAttribute::SetValue<int>(this: v5, (int *)&value);
  CDmAttribute::SetValue<int>(this: this->m_nWidth.m_pAttribute, value: &this->m_nHeight.m_Storage);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "accumbuff4sample");
  else
    v7 = nullptr;
  KeyValues::SetString(this: v7, keyName: "$INPUT", value: "Effects/FilmScan256");
  Key = KeyValues::FindKey(this: v7, keyName: "proxies", bCreate: true);
  KeyValues::FindKey(this: Key, keyName: "sfm_blt", bCreate: true);
  CMaterialReference::Init(this: &this->m_BltMaterial, pMaterialName: "accumbuff4sample", pVMTKeyValues: v7);
  this->m_BltMaterial.m_pMaterial->Refresh(this: this->m_BltMaterial.m_pMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x005345F0
// Name: private: void CDmeMaterialOverlayFXClip::DrawQuad(int,int,int,int,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeMaterialOverlayFXClip::DrawQuad(
        CDmeMaterialOverlayFXClip *this@<ecx>,
        int a2@<edi>,
        int x,
        int y,
        int w,
        int h,
        float u0,
        float v0,
        float u1,
        float v1)
{
  IMatRenderContext *v10; // esi
  IMesh *v11; // esi
  float *m_pCurrPosition; // eax
  float *v13; // eax
  float *v14; // eax
  float *v15; // eax
  int v16; // eax
  float *v17; // eax
  float v18; // xmm5_4
  float *v19; // eax
  float *v20; // eax
  float *v21; // eax
  int v22; // eax
  float *v23; // eax
  float v24; // xmm2_4
  float *v25; // eax
  float *v26; // eax
  float *v27; // eax
  int v28; // eax
  float *v29; // eax
  float *v30; // eax
  float *v31; // eax
  float *v32; // eax
  int m_nVertexCount; // eax
  int v34; // ecx
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1ECh] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F0h] [ebp-4h]

  v10 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v10;
  if ( v10 != nullptr )
    v10->BeginRender(this: v10);
  v11 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, int))v10->GetDynamicMesh)(
                   a1: v10,
                   a2: 1,
                   a3: 0,
                   a4: 0,
                   a5: 0,
                   a6: a2);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v11;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_TRIANGLE_STRIP;
  v11->SetPrimitiveType(this: v11, a2: MATERIAL_TRIANGLE_STRIP);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 4, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v11->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 4;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v11, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)x;
  m_pCurrPosition[1] = (float)y;
  m_pCurrPosition[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v13 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u0;
  v13[1] = v0;
  v14 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 0.0;
  v14[1] = 0.0;
  v15 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v15[1] = 0.0;
  v16 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v16;
  if ( v16 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v16;
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  v17 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v17;
  *v17 = (float)x;
  v18 = (float)(h + y);
  v17[1] = v18;
  v17[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v19 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u0;
  v19[1] = v1;
  v20 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 0.0;
  v20[1] = 1.0;
  v21 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v21[1] = 0.0;
  v22 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v22;
  if ( v22 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v22;
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  v23 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v23;
  v24 = (float)(w + x);
  *v23 = v24;
  v23[1] = (float)y;
  v23[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v25 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u1;
  v25[1] = v0;
  v26 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 1.0;
  v26[1] = 0.0;
  v27 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v27[1] = 0.0;
  v28 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v28;
  if ( v28 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v28;
  v29 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v29;
  *v29 = v24;
  v29[1] = v18;
  v29[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v30 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u1;
  v30[1] = v1;
  v31 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 1.0;
  v31[1] = 1.0;
  v32 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v32[1] = 0.0;
  m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  v34 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v34;
  if ( v34 > meshBuilder.m_VertexBuilder.m_nVertexCount )
  {
    m_nVertexCount = v34;
    meshBuilder.m_VertexBuilder.m_nVertexCount = v34;
  }
  meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount *= 2;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  }
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
  v11->Draw_2(this: v11, a2: -1, a3: 0);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x00534AF0
// Name: private: void CDmeMaterialOverlayFXClip::DrawOneToOneQuad(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::DrawOneToOneQuad(CDmeMaterialOverlayFXClip *this, int nWidth, int nHeight)
{
  IMatRenderContext *v3; // esi
  IMesh *v4; // esi
  float *m_pCurrPosition; // eax
  float v6; // xmm0_4
  float *v7; // eax
  int v8; // eax
  float *v9; // eax
  float *v10; // eax
  int v11; // eax
  float *v12; // eax
  float *v13; // eax
  float v14; // xmm0_4
  int v15; // eax
  float *v16; // eax
  float *v17; // eax
  int m_nVertexCount; // eax
  int v19; // ecx
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1ECh] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F0h] [ebp-4h]
  float fHeightEpsilon; // [esp+200h] [ebp+Ch]

  v3 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v3;
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  v4 = v3->GetDynamicMesh(this: v3, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v4;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_QUADS;
  fHeightEpsilon = 0.5 / (float)nHeight;
  v4->SetPrimitiveType(this: v4, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v4->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v4, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v6 = 0.5 / (float)nWidth;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = -1.0;
  m_pCurrPosition[1] = 1.0;
  m_pCurrPosition[2] = 0.5;
  v7 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v6;
  v7[1] = fHeightEpsilon;
  v8 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v8;
  if ( v8 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v8;
  v9 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v9;
  *v9 = -1.0;
  v9[1] = -1.0;
  v9[2] = 0.5;
  v10 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v6;
  v10[1] = fHeightEpsilon + 1.0;
  v11 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v11;
  if ( v11 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v11;
  v12 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v12;
  *v12 = 1.0;
  v12[1] = -1.0;
  v12[2] = 0.5;
  v13 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  v14 = v6 + 1.0;
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v14;
  v13[1] = fHeightEpsilon + 1.0;
  v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
  if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
  v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
  *v16 = 1.0;
  v16[1] = 1.0;
  v16[2] = 0.5;
  v17 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v14;
  v17[1] = fHeightEpsilon;
  m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  v19 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v19;
  if ( v19 > meshBuilder.m_VertexBuilder.m_nVertexCount )
  {
    m_nVertexCount = v19;
    meshBuilder.m_VertexBuilder.m_nVertexCount = v19;
  }
  meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount *= 2;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  }
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v4->Draw_2(this: v4, a2: -1, a3: 0);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x00534E60
// Name: public: virtual void CDmeMaterialOverlayFXClip::ApplyEffect(class DmeTime_t,struct Rect_t __near &,struct Rect_t __near &,class ITexture __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CDmeMaterialOverlayFXClip::ApplyEffect(
        CDmeMaterialOverlayFXClip *this@<ecx>,
        int a2@<edi>,
        DmeTime_t time,
        Rect_t *currentRect,
        int totalRect,
        float pTextures)
{
  int width; // edx
  int v9; // ecx
  Rect_t *v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // edx
  int v17; // eax
  int v18; // edx
  int v19; // eax
  int v20; // eax
  int v21; // edx
  int v22; // eax
  IMaterial *m_pMaterial; // ecx
  int v24; // eax
  bool v25; // zf
  float v26; // xmm5_4
  float v27; // xmm6_4
  float m_Storage; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm3_4
  float v31; // xmm1_4
  double v32; // xmm0_8
  double v33; // xmm0_8
  double v34; // xmm0_8
  float v35; // xmm1_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm3_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  int v42; // eax
  bool v43; // al
  Rect_t *v44; // edi
  long double v46; // [esp+78h] [ebp-50h] OVERLAPPED BYREF
  int g; // [esp+80h] [ebp-48h] BYREF
  float b; // [esp+84h] [ebp-44h] BYREF
  DmeTime_t v1; // [esp+88h] [ebp-40h] BYREF
  float u1; // [esp+8Ch] [ebp-3Ch]
  float dU; // [esp+90h] [ebp-38h]
  float flRadians; // [esp+94h] [ebp-34h]
  int mw; // [esp+98h] [ebp-30h]
  float vMin; // [esp+9Ch] [ebp-2Ch]
  float uMax; // [esp+A0h] [ebp-28h]
  float uMin; // [esp+A4h] [ebp-24h]
  float v57; // [esp+A8h] [ebp-20h]
  float v58; // [esp+ACh] [ebp-1Ch]
  int ty; // [esp+B0h] [ebp-18h]
  int th; // [esp+B4h] [ebp-14h]
  int tx; // [esp+B8h] [ebp-10h]
  int w; // [esp+BCh] [ebp-Ch]
  int h; // [esp+C0h] [ebp-8h]
  int x; // [esp+C4h] [ebp-4h]
  int timea; // [esp+D0h] [ebp+8h]
  int y; // [esp+D4h] [ebp+Ch]
  int ya; // [esp+D4h] [ebp+Ch]

  if ( this->m_OverlayMaterial.m_pMaterial == nullptr
    || this->m_BltMaterial.m_pMaterial == nullptr
    || this->m_Color.m_Storage._color[3] == 0 )
  {
    return;
  }
  timea = CDmeClip::ToChildMediaTime(this, result: &v1, t: time, bClamp: 0)->m_tms;
  width = currentRect->width;
  if ( this->m_bFullScreen.m_Storage )
  {
    v9 = currentRect->y;
    x = currentRect->x;
    h = currentRect->height;
    y = v9;
    v10 = *(Rect_t **)(totalRect + 8);
    w = width;
    v11 = *(_DWORD *)(totalRect + 12);
    ty = 0;
    tx = 0;
    totalRect = (int)v10;
    th = v11;
LABEL_22:
    if ( totalRect != 0 && th != 0 )
    {
      v22 = ((int (__thiscall *)(IMaterial *, int))this->m_OverlayMaterial.m_pMaterial->GetMappingWidth)(
              a1: this->m_OverlayMaterial.m_pMaterial,
              a2);
      m_pMaterial = this->m_OverlayMaterial.m_pMaterial;
      mw = v22;
      v24 = m_pMaterial->GetMappingHeight(this: m_pMaterial);
      v25 = !this->m_bUseSubRect.m_Storage;
      v26 = (float)mw;
      v27 = (float)v24;
      m_Storage = 0.0;
      v29 = (float)mw;
      v30 = 0.0;
      v31 = (float)v24;
      uMin = 0.0;
      u1 = (float)mw;
      uMax = (float)mw;
      vMin = 0.0;
      *(float *)&v1.m_tms = (float)v24;
      *(float *)&mw = (float)v24;
      if ( !v25 )
      {
        m_Storage = (float)this->m_nSubRectLeft.m_Storage;
        v30 = (float)this->m_nSubRectTop.m_Storage;
        v29 = (float)this->m_nSubRectWidth.m_Storage + m_Storage;
        v31 = (float)this->m_nSubRectHeight.m_Storage + v30;
        uMin = m_Storage;
        vMin = v30;
        uMax = v29;
        *(float *)&mw = v31;
      }
      v58 = this->m_flMovementSpeed.m_Storage;
      if ( v58 != 0.0 )
      {
        v32 = this->m_flMovementAngle.m_Storage;
        v57 = (float)timea * 0.000099999997;
        flRadians = v32 * 3.141592653589793 * 0.005555555555555556;
        v33 = flRadians;
        __libm_sse2_cos(x: v46);
        *(float *)&v33 = v33;
        dU = COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&v33 * v58) ^ _mask__NegFloat_) * v57;
        v34 = flRadians;
        __libm_sse2_sin(x: v46);
        v26 = u1;
        v27 = *(float *)&v1.m_tms;
        v35 = v34;
        v36 = (float)(v35 * v58) * v57;
        m_Storage = dU + uMin;
        v29 = dU + uMax;
        v30 = v36 + vMin;
        v31 = v36 + *(float *)&mw;
      }
      v37 = (float)(m_Storage + 0.5) / v26;
      v38 = (float)((float)(v29 - 0.5) / v26) - v37;
      v39 = (float)(v30 + 0.5) / v27;
      v40 = (float)((float)(v31 - 0.5) / v27) - v39;
      flRadians = (float)((float)((x - tx) / totalRect) * v38) + v37;
      u1 = (float)((float)((x + w - tx) / totalRect) * v38) + v37;
      v41 = (float)((float)((y - ty) / th) * v40) + v39;
      v42 = (y + h - ty) / th;
      ya = y - currentRect->y;
      dU = v41;
      x -= currentRect->x;
      *(float *)&v1.m_tms = (float)((float)v42 * v40) + v39;
      CMatRenderContextPtr::CMatRenderContextPtr(this: (CMatRenderContextPtr *)&totalRect, pFrom: materials);
      v43 = this->m_OverlayMaterial.m_pMaterial->NeedsPowerOfTwoFrameBufferTexture(
              this: this->m_OverlayMaterial.m_pMaterial,
              a2: true);
      v44 = (Rect_t *)totalRect;
      if ( v43 )
      {
        (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)totalRect + 36))(
          a1: totalRect,
          a2: this->m_BltMaterial.m_pMaterial,
          a3: *(_DWORD *)LODWORD(pTextures));
        (*(void (__thiscall **)(Rect_t *, ITexture *, _DWORD, _DWORD, int, int))(v44->x + 432))(
          a1: v44,
          a2: *(ITexture **)(LODWORD(pTextures) + 4),
          a3: 0,
          a4: 0,
          a5: w,
          a6: h);
        CDmeMaterialOverlayFXClip::DrawOneToOneQuad(this, nWidth: w, nHeight: h);
        (*(void (__thiscall **)(Rect_t *))(v44->x + 444))(a1: v44);
        (*(void (__thiscall **)(Rect_t *, ITexture *, _DWORD))(v44->x + 72))(
          a1: v44,
          a2: *(ITexture **)(LODWORD(pTextures) + 4),
          a3: 0);
        (*(void (__thiscall **)(Rect_t *, _DWORD, _DWORD, _DWORD, int, int))(v44->x + 432))(
          a1: v44,
          a2: *(_DWORD *)LODWORD(pTextures),
          a3: 0,
          a4: 0,
          a5: w,
          a6: h);
      }
      this->m_OverlayMaterial.m_pMaterial->GetColorModulation(
        this: this->m_OverlayMaterial.m_pMaterial,
        a2: (float *)((char *)&v46 + 4),
        a3: (float *)&g,
        a4: &b);
      pTextures = this->m_OverlayMaterial.m_pMaterial->GetAlphaModulation(this: this->m_OverlayMaterial.m_pMaterial);
      ((void (__thiscall *)(IMaterial *, _DWORD, _DWORD, _DWORD))this->m_OverlayMaterial.m_pMaterial->ColorModulate)(
        a1: this->m_OverlayMaterial.m_pMaterial,
        a2: (float)this->m_Color.m_Storage._color[0] * 0.0039215689,
        a3: (float)this->m_Color.m_Storage._color[1] * 0.0039215689,
        a4: (float)this->m_Color.m_Storage._color[2] * 0.0039215689);
      ((void (__stdcall *)(_DWORD))this->m_OverlayMaterial.m_pMaterial->AlphaModulate)(a1: (float)this->m_Color.m_Storage._color[3] * 0.0039215689);
      (*(void (__thiscall **)(Rect_t *, IMaterial *, _DWORD))(v44->x + 36))(
        a1: v44,
        a2: this->m_OverlayMaterial.m_pMaterial,
        a3: 0);
      CDmeMaterialOverlayFXClip::DrawQuad(
        this,
        a2: (int)v44,
        x,
        y: ya,
        w,
        h,
        u0: flRadians,
        v0: dU,
        u1,
        v1: *(float *)&v1.m_tms);
      if ( this->m_OverlayMaterial.m_pMaterial->NeedsPowerOfTwoFrameBufferTexture(
             this: this->m_OverlayMaterial.m_pMaterial,
             a2: true) )
      {
        (*(void (__thiscall **)(Rect_t *))(v44->x + 444))(a1: v44);
      }
      ((void (__thiscall *)(IMaterial *, _DWORD, int))this->m_OverlayMaterial.m_pMaterial->ColorModulate)(
        a1: this->m_OverlayMaterial.m_pMaterial,
        a2: HIDWORD(v46),
        a3: g);
      ((void (__stdcall *)(_DWORD))this->m_OverlayMaterial.m_pMaterial->AlphaModulate)(a1: LODWORD(pTextures));
      CMatRenderContextPtr::~CMatRenderContextPtr(this: (CMatRenderContextPtr *)&totalRect);
    }
    return;
  }
  v12 = currentRect->x;
  v13 = this->m_nLeft.m_Storage;
  v14 = currentRect->x + width;
  mw = v14;
  if ( v13 >= v12 )
  {
    x = v14;
    if ( v13 <= v14 )
      x = v13;
  }
  else
  {
    x = v12;
  }
  v15 = currentRect->y;
  totalRect = v15 + currentRect->height;
  v16 = this->m_nTop.m_Storage;
  if ( v16 >= v15 )
  {
    y = totalRect;
    if ( v16 <= totalRect )
      y = this->m_nTop.m_Storage;
  }
  else
  {
    y = v15;
  }
  v17 = this->m_nLeft.m_Storage + this->m_nWidth.m_Storage;
  if ( v17 >= v12 )
  {
    v12 = mw;
    if ( v17 <= mw )
      v12 = this->m_nLeft.m_Storage + this->m_nWidth.m_Storage;
  }
  v18 = this->m_nHeight.m_Storage + v16;
  v19 = currentRect->y;
  if ( v18 >= v19 )
  {
    v19 = totalRect;
    if ( v18 <= totalRect )
      v19 = v18;
  }
  v20 = v19 - y;
  tx = this->m_nLeft.m_Storage;
  ty = this->m_nTop.m_Storage;
  totalRect = this->m_nWidth.m_Storage;
  v21 = this->m_nHeight.m_Storage;
  w = v12 - x;
  h = v20;
  th = v21;
  if ( v12 - x > 0 && v20 > 0 )
    goto LABEL_22;
}

//------------------------------------------------------------------------------
// Address: 0x00535470
// Name: protected: CDmeMaterialOverlayFXClip::CDmeMaterialOverlayFXClip(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMaterialOverlayFXClip *__thiscall CDmeMaterialOverlayFXClip::CDmeMaterialOverlayFXClip(
        CDmeMaterialOverlayFXClip *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeMaterialOverlayFXClip_vtbl *)&CDmeClip::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_TrackGroups);
  this->m_TimeFrame.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_TimeFrame.m_pAttribute = nullptr;
  this->m_TimeFrame.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_ClipColor.m_pAttribute = nullptr;
  this->m_ClipColor.m_Storage = (Color)-16777216;
  this->m_bMute.m_pAttribute = nullptr;
  this->m_bMute.m_Storage = false;
  this->m_flDisplayScale = 0;
  this->m_ClipText.m_pAttribute = nullptr;
  this->m_ClipText.m_Storage.u.CDmeFXClip::CDmeClip::m_Id = -1;
  this->__vftable = (CDmeMaterialOverlayFXClip_vtbl *)&CDmeMaterialOverlayFXClip::`vftable';
  this->m_Material.m_pAttribute = nullptr;
  this->m_Material.m_Storage.u.m_Id = -1;
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_nLeft.m_pAttribute = nullptr;
  this->m_nLeft.m_Storage = 0;
  this->m_nTop.m_pAttribute = nullptr;
  this->m_nTop.m_Storage = 0;
  this->m_nWidth.m_pAttribute = nullptr;
  this->m_nWidth.m_Storage = 0;
  this->m_nHeight.m_pAttribute = nullptr;
  this->m_nHeight.m_Storage = 0;
  this->m_bFullScreen.m_pAttribute = nullptr;
  this->m_bFullScreen.m_Storage = false;
  this->m_bUseSubRect.m_pAttribute = nullptr;
  this->m_bUseSubRect.m_Storage = false;
  this->m_nSubRectLeft.m_pAttribute = nullptr;
  this->m_nSubRectLeft.m_Storage = 0;
  this->m_nSubRectTop.m_pAttribute = nullptr;
  this->m_nSubRectTop.m_Storage = 0;
  this->m_nSubRectWidth.m_pAttribute = nullptr;
  this->m_nSubRectWidth.m_Storage = 0;
  this->m_nSubRectHeight.m_pAttribute = nullptr;
  this->m_nSubRectHeight.m_Storage = 0;
  this->m_flMovementAngle = 0;
  this->m_flMovementSpeed = 0;
  CMaterialReference::CMaterialReference(
    this: &this->m_OverlayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_BltMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005355C0
// Name: public: virtual bool CDmeMaterialOverlayFXClip::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMaterialOverlayFXClip::IsA(CDmeMaterialOverlayFXClip *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMaterialOverlayFXClip::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFXClip::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeClip::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00535600
// Name: public: virtual int CDmeMaterialOverlayFXClip::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialOverlayFXClip::GetInheritanceDepth(
        CDmeMaterialOverlayFXClip *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMaterialOverlayFXClip::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFXClip::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeClip::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00535660
// Name: protected: virtual void CDmeMaterialOverlayFXClip::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::PerformDestruction(CDmeMaterialOverlayFXClip *this)
{
  CMaterialReference::Shutdown(this: &this->m_BltMaterial, bDeleteIfUnreferenced: false);
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x00535690
// Name: protected: virtual int CDmeMaterialOverlayFXClip::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialOverlayFXClip::AllocatedSize(CDmeMaterialOverlayFXClip *this)
{
  return 260;
}

//------------------------------------------------------------------------------
// Address: 0x005356A0
// Name: protected: virtual void CDmeMaterialOverlayFXClip::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::PerformConstruction(CDmeMaterialOverlayFXClip *this)
{
  CDmeFXClip::OnDestruction();
  CDmeClip::OnConstruction(this);
  CDmeFXClip::OnDestruction();
  CDmeMaterialOverlayFXClip::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057D700
// Name: _dynamic_initializer_for__CDmeMaterialOverlayFXClip::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMaterialOverlayFXClip::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMaterialOverlayFXClip::s_Allocator,
    blockSize: 260,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMaterialOverlayFXClip pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F4D0
// Name: _dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMaterialOverlayFXClip::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057D730
// Name: _dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Factory__()
{
  CDmeFXClip::InstallFXClipType(pElementType: "DmeMaterialOverlayFXClip", pDescription: "Material Overlay Effect");
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D750
// Name: _dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMaterialOverlayFXClip_Helper,
           classname: "DmeMaterialOverlayFXClip",
           pFactory: &g_CDmeMaterialOverlayFXClip_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057D770
// Name: _dynamic_initializer_for__mod_load_preload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_preload__()
{
  ConVar::ConVar(
    this: &mod_load_preload,
    pName: "mod_load_preload",
    pDefaultValue: "1.0",
    flags: 0,
    pHelpString: "Indicates how far ahead in seconds to preload animations.");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_preload__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D7A0
// Name: _dynamic_initializer_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_showstall__()
{
  ConVar::ConVar(
    this: &mod_load_showstall,
    pName: "mod_load_showstall",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "1 - show hitches , 2 - show stalls");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_showstall__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D7D0
// Name: _dynamic_initializer_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ActivityModifiersTable, growSize: 0, initSize: 16, caseInsensitive: false);
  return atexit(func: dynamic_atexit_destructor_for__g_ActivityModifiersTable__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D7F0
// Name: _dynamic_initializer_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall dynamic_initializer_for__emptyMapping__(char a1)
{
  int v2; // [esp-4h] [ebp-Ch] BYREF
  CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs v3; // [esp+0h] [ebp-8h]
  int *v4; // [esp+4h] [ebp-4h]

  v4 = &v2;
  CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>::CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>(
    this: &emptyMapping.m_ActToSeqHash,
    bucketCount: 8,
    growCount: 0,
    initCount: 0,
    compareFunc: (CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs)a1,
    keyFunc: v3);
  emptyMapping.m_pStudioHdr = nullptr;
  emptyMapping.m_expectedVModel = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__emptyMapping__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D840
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMaps__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D850
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMapsLock__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMapsLock__()
{
  g_StudioHdrToActivityMapsLock.m_ownerID = 0;
  g_StudioHdrToActivityMapsLock.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0057F4E0
// Name: _dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMaterialOverlayFXClip_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057F4F0
// Name: _dynamic_atexit_destructor_for__mod_load_preload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_preload__()
{
  ConVar::~ConVar(this: &mod_load_preload);
}

//------------------------------------------------------------------------------
// Address: 0x0057F500
// Name: _dynamic_atexit_destructor_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_showstall__()
{
  ConVar::~ConVar(this: &mod_load_showstall);
}

//------------------------------------------------------------------------------
// Address: 0x0057F510
// Name: _dynamic_atexit_destructor_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ActivityModifiersTable);
}

//------------------------------------------------------------------------------
// Address: 0x0057F520
// Name: _dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__()
{
  CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_StudioHdrToActivityMaps.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x0057F530
// Name: _dynamic_atexit_destructor_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__emptyMapping__()
{
  CStudioHdr::CActivityToSequenceMapping::SequenceTuple *m_pSequenceTuples; // ecx

  m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
  if ( emptyMapping.m_pSequenceTuples != nullptr )
  {
    if ( emptyMapping.m_pSequenceTuples->pActivityModifiers != nullptr )
    {
      free(pMem: emptyMapping.m_pSequenceTuples->pActivityModifiers);
      m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
    }
    free(pMem: m_pSequenceTuples);
  }
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: &emptyMapping.m_ActToSeqHash);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: &emptyMapping.m_ActToSeqHash.m_Buckets);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005F3DF0
// Name: public: virtual void CDmeMaterialOverlayFXClip::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::Resolve(CDmeMaterialOverlayFXClip *this)
{
  const char *m_pAsString; // eax

  if ( SLOBYTE(this->m_Material.m_pAttribute->m_nFlags) < 0 )
  {
    CMaterialReference::Shutdown(this: &this->m_OverlayMaterial, bDeleteIfUnreferenced: false);
    m_pAsString = this->m_Material.m_Storage.u.m_pAsString;
    if ( m_pAsString != (const char *)-1 && m_pAsString != nullptr && *m_pAsString != 0 )
      CMaterialReference::Init(
        this: &this->m_OverlayMaterial,
        pMaterialName: m_pAsString,
        pTextureGroupName: nullptr,
        bComplain: false);
    this->m_Material.m_pAttribute->m_nFlags &= ~0x80u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005F3E50
// Name: protected: void CDmeMaterialOverlayFXClip::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::OnConstruction(CDmeMaterialOverlayFXClip *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  CDmAttribute *v4; // ecx
  CDmAttribute *v5; // ecx
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  KeyValues *Key; // eax
  Color value; // [esp+Ch] [ebp-8h] BYREF
  bool v10; // [esp+13h] [ebp-1h] BYREF

  this->m_Material.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "material",
                                    type: AT_STRING,
                                    pMemory: &this->m_Material);
  this->m_Color.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "overlaycolor",
                                 type: AT_COLOR,
                                 pMemory: &this->m_Color);
  this->m_nLeft.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "left",
                                 type: AT_INT,
                                 pMemory: &this->m_nLeft);
  this->m_nTop.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "top",
                                type: AT_INT,
                                pMemory: &this->m_nTop);
  this->m_nWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "width",
                                  type: AT_INT,
                                  pMemory: &this->m_nWidth);
  this->m_nHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "height",
                                   type: AT_INT,
                                   pMemory: &this->m_nHeight);
  this->m_bFullScreen.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "fullscreen",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bFullScreen);
  this->m_bUseSubRect.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "useSubRect",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bUseSubRect);
  this->m_flMovementAngle.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "movementAngle",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flMovementAngle);
  this->m_flMovementSpeed.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "movementSpeed",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flMovementSpeed);
  this->m_nSubRectLeft.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "subRectLeft",
                                        type: AT_INT,
                                        pMemory: &this->m_nSubRectLeft);
  this->m_nSubRectTop.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "subRectTop",
                                       type: AT_INT,
                                       pMemory: &this->m_nSubRectTop);
  this->m_nSubRectWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "subRectWidth",
                                         type: AT_INT,
                                         pMemory: &this->m_nSubRectWidth);
  this->m_nSubRectHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "subRectHeight",
                                          type: AT_INT,
                                          pMemory: &this->m_nSubRectHeight);
  m_pAttribute = this->m_Color.m_pAttribute;
  value = (Color)-1;
  CDmAttribute::SetValue<Color>(this: m_pAttribute, &value);
  v3 = this->m_bFullScreen.m_pAttribute;
  v10 = true;
  CDmAttribute::SetValue<bool>(this: v3, value: &v10);
  v4 = this->m_nTop.m_pAttribute;
  value = 0;
  CDmAttribute::SetValue<int>(this: v4, (const int *)&value);
  CDmAttribute::SetValue<int>(this: this->m_nLeft.m_pAttribute, value: &this->m_nTop.m_Storage);
  v5 = this->m_nHeight.m_pAttribute;
  value = (Color)1;
  CDmAttribute::SetValue<int>(this: v5, (const int *)&value);
  CDmAttribute::SetValue<int>(this: this->m_nWidth.m_pAttribute, value: &this->m_nHeight.m_Storage);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "accumbuff4sample");
  else
    v7 = nullptr;
  KeyValues::SetString(this: v7, keyName: "$INPUT", value: "Effects/FilmScan256");
  Key = KeyValues::FindKey(this: v7, keyName: "proxies", bCreate: true);
  KeyValues::FindKey(this: Key, keyName: "sfm_blt", bCreate: true);
  CMaterialReference::Init(this: &this->m_BltMaterial, pMaterialName: "accumbuff4sample", pVMTKeyValues: v7);
  this->m_BltMaterial.m_pMaterial->Refresh(this: this->m_BltMaterial.m_pMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x005F40A0
// Name: private: void CDmeMaterialOverlayFXClip::DrawQuad(int,int,int,int,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeMaterialOverlayFXClip::DrawQuad(
        CDmeMaterialOverlayFXClip *this@<ecx>,
        int a2@<edi>,
        int x,
        int y,
        int w,
        int h,
        float u0,
        float v0,
        float u1,
        float v1)
{
  IMatRenderContext *v10; // esi
  IMesh *v11; // esi
  float *m_pCurrPosition; // eax
  float *v13; // eax
  float *v14; // eax
  float *v15; // eax
  int v16; // eax
  float *v17; // eax
  float v18; // xmm5_4
  float *v19; // eax
  float *v20; // eax
  float *v21; // eax
  int v22; // eax
  float *v23; // eax
  float v24; // xmm2_4
  float *v25; // eax
  float *v26; // eax
  float *v27; // eax
  int v28; // eax
  float *v29; // eax
  float *v30; // eax
  float *v31; // eax
  float *v32; // eax
  int m_nVertexCount; // eax
  int v34; // ecx
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1ECh] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F0h] [ebp-4h]

  v10 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v10;
  if ( v10 != nullptr )
    v10->BeginRender(this: v10);
  v11 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, int))v10->GetDynamicMesh)(
                   a1: v10,
                   a2: 1,
                   a3: 0,
                   a4: 0,
                   a5: 0,
                   a6: a2);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v11;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_TRIANGLE_STRIP;
  v11->SetPrimitiveType(this: v11, a2: MATERIAL_TRIANGLE_STRIP);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 4, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v11->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 4;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v11, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)x;
  m_pCurrPosition[1] = (float)y;
  m_pCurrPosition[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v13 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u0;
  v13[1] = v0;
  v14 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 0.0;
  v14[1] = 0.0;
  v15 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v15[1] = 0.0;
  v16 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v16;
  if ( v16 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v16;
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  v17 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v17;
  *v17 = (float)x;
  v18 = (float)(h + y);
  v17[1] = v18;
  v17[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v19 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u0;
  v19[1] = v1;
  v20 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 0.0;
  v20[1] = 1.0;
  v21 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v21[1] = 0.0;
  v22 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v22;
  if ( v22 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v22;
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  v23 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v23;
  v24 = (float)(w + x);
  *v23 = v24;
  v23[1] = (float)y;
  v23[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v25 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u1;
  v25[1] = v0;
  v26 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 1.0;
  v26[1] = 0.0;
  v27 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v27[1] = 0.0;
  v28 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v28;
  if ( v28 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v28;
  v29 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v29;
  *v29 = v24;
  v29[1] = v18;
  v29[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v30 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u1;
  v30[1] = v1;
  v31 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 1.0;
  v31[1] = 1.0;
  v32 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v32[1] = 0.0;
  m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  v34 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v34;
  if ( v34 > meshBuilder.m_VertexBuilder.m_nVertexCount )
  {
    m_nVertexCount = v34;
    meshBuilder.m_VertexBuilder.m_nVertexCount = v34;
  }
  meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount *= 2;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  }
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
  v11->Draw_2(this: v11, a2: -1, a3: 0);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x005F45A0
// Name: private: void CDmeMaterialOverlayFXClip::DrawOneToOneQuad(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::DrawOneToOneQuad(CDmeMaterialOverlayFXClip *this, int nWidth, int nHeight)
{
  IMatRenderContext *v3; // esi
  IMesh *v4; // esi
  float *m_pCurrPosition; // eax
  float v6; // xmm0_4
  float *v7; // eax
  int v8; // eax
  float *v9; // eax
  float *v10; // eax
  int v11; // eax
  float *v12; // eax
  float *v13; // eax
  float v14; // xmm0_4
  int v15; // eax
  float *v16; // eax
  float *v17; // eax
  int m_nVertexCount; // eax
  int v19; // ecx
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1ECh] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F0h] [ebp-4h]
  float fHeightEpsilon; // [esp+200h] [ebp+Ch]

  v3 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v3;
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  v4 = v3->GetDynamicMesh(this: v3, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v4;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_QUADS;
  fHeightEpsilon = 0.5 / (float)nHeight;
  v4->SetPrimitiveType(this: v4, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v4->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v4, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v6 = 0.5 / (float)nWidth;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = -1.0;
  m_pCurrPosition[1] = 1.0;
  m_pCurrPosition[2] = 0.5;
  v7 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v6;
  v7[1] = fHeightEpsilon;
  v8 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v8;
  if ( v8 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v8;
  v9 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v9;
  *v9 = -1.0;
  v9[1] = -1.0;
  v9[2] = 0.5;
  v10 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v6;
  v10[1] = fHeightEpsilon + 1.0;
  v11 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v11;
  if ( v11 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v11;
  v12 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v12;
  *v12 = 1.0;
  v12[1] = -1.0;
  v12[2] = 0.5;
  v13 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  v14 = v6 + 1.0;
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v14;
  v13[1] = fHeightEpsilon + 1.0;
  v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
  if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
  v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
  *v16 = 1.0;
  v16[1] = 1.0;
  v16[2] = 0.5;
  v17 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v14;
  v17[1] = fHeightEpsilon;
  m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  v19 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v19;
  if ( v19 > meshBuilder.m_VertexBuilder.m_nVertexCount )
  {
    m_nVertexCount = v19;
    meshBuilder.m_VertexBuilder.m_nVertexCount = v19;
  }
  meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount *= 2;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  }
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v4->Draw_2(this: v4, a2: -1, a3: 0);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x005F4910
// Name: public: virtual void CDmeMaterialOverlayFXClip::ApplyEffect(class DmeTime_t,struct Rect_t __near &,struct Rect_t __near &,class ITexture __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CDmeMaterialOverlayFXClip::ApplyEffect(
        CDmeMaterialOverlayFXClip *this@<ecx>,
        int a2@<edi>,
        DmeTime_t time,
        Rect_t *currentRect,
        int totalRect,
        float pTextures)
{
  int width; // edx
  int v9; // ecx
  Rect_t *v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // edx
  int v17; // eax
  int v18; // edx
  int v19; // eax
  int v20; // eax
  int v21; // edx
  int v22; // eax
  IMaterial *m_pMaterial; // ecx
  int v24; // eax
  bool v25; // zf
  float v26; // xmm5_4
  float v27; // xmm6_4
  float m_Storage; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm3_4
  float v31; // xmm1_4
  double v32; // xmm0_8
  double v33; // xmm0_8
  double v34; // xmm0_8
  float v35; // xmm1_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm3_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  int v42; // eax
  bool v43; // al
  Rect_t *v44; // edi
  long double v46; // [esp+78h] [ebp-50h] OVERLAPPED BYREF
  int g; // [esp+80h] [ebp-48h] BYREF
  float b; // [esp+84h] [ebp-44h] BYREF
  DmeTime_t v1; // [esp+88h] [ebp-40h] BYREF
  float u1; // [esp+8Ch] [ebp-3Ch]
  float dU; // [esp+90h] [ebp-38h]
  float flRadians; // [esp+94h] [ebp-34h]
  int mw; // [esp+98h] [ebp-30h]
  float vMin; // [esp+9Ch] [ebp-2Ch]
  float uMax; // [esp+A0h] [ebp-28h]
  float uMin; // [esp+A4h] [ebp-24h]
  float v57; // [esp+A8h] [ebp-20h]
  float v58; // [esp+ACh] [ebp-1Ch]
  int ty; // [esp+B0h] [ebp-18h]
  int th; // [esp+B4h] [ebp-14h]
  int tx; // [esp+B8h] [ebp-10h]
  int w; // [esp+BCh] [ebp-Ch]
  int h; // [esp+C0h] [ebp-8h]
  int x; // [esp+C4h] [ebp-4h]
  int timea; // [esp+D0h] [ebp+8h]
  int y; // [esp+D4h] [ebp+Ch]
  int ya; // [esp+D4h] [ebp+Ch]

  if ( this->m_OverlayMaterial.m_pMaterial == nullptr
    || this->m_BltMaterial.m_pMaterial == nullptr
    || this->m_Color.m_Storage._color[3] == 0 )
  {
    return;
  }
  timea = CDmeClip::ToChildMediaTime(this, result: &v1, t: time, bClamp: 0)->m_tms;
  width = currentRect->width;
  if ( this->m_bFullScreen.m_Storage )
  {
    v9 = currentRect->y;
    x = currentRect->x;
    h = currentRect->height;
    y = v9;
    v10 = *(Rect_t **)(totalRect + 8);
    w = width;
    v11 = *(_DWORD *)(totalRect + 12);
    ty = 0;
    tx = 0;
    totalRect = (int)v10;
    th = v11;
LABEL_22:
    if ( totalRect != 0 && th != 0 )
    {
      v22 = ((int (__thiscall *)(IMaterial *, int))this->m_OverlayMaterial.m_pMaterial->GetMappingWidth)(
              a1: this->m_OverlayMaterial.m_pMaterial,
              a2);
      m_pMaterial = this->m_OverlayMaterial.m_pMaterial;
      mw = v22;
      v24 = m_pMaterial->GetMappingHeight(this: m_pMaterial);
      v25 = !this->m_bUseSubRect.m_Storage;
      v26 = (float)mw;
      v27 = (float)v24;
      m_Storage = 0.0;
      v29 = (float)mw;
      v30 = 0.0;
      v31 = (float)v24;
      uMin = 0.0;
      u1 = (float)mw;
      uMax = (float)mw;
      vMin = 0.0;
      *(float *)&v1.m_tms = (float)v24;
      *(float *)&mw = (float)v24;
      if ( !v25 )
      {
        m_Storage = (float)this->m_nSubRectLeft.m_Storage;
        v30 = (float)this->m_nSubRectTop.m_Storage;
        v29 = (float)this->m_nSubRectWidth.m_Storage + m_Storage;
        v31 = (float)this->m_nSubRectHeight.m_Storage + v30;
        uMin = m_Storage;
        vMin = v30;
        uMax = v29;
        *(float *)&mw = v31;
      }
      v58 = this->m_flMovementSpeed.m_Storage;
      if ( v58 != 0.0 )
      {
        v32 = this->m_flMovementAngle.m_Storage;
        v57 = (float)timea * 0.000099999997;
        flRadians = v32 * 3.141592653589793 * 0.005555555555555556;
        v33 = flRadians;
        __libm_sse2_cos(x: v46);
        *(float *)&v33 = v33;
        dU = COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&v33 * v58) ^ _mask__NegFloat_) * v57;
        v34 = flRadians;
        __libm_sse2_sin(x: v46);
        v26 = u1;
        v27 = *(float *)&v1.m_tms;
        v35 = v34;
        v36 = (float)(v35 * v58) * v57;
        m_Storage = dU + uMin;
        v29 = dU + uMax;
        v30 = v36 + vMin;
        v31 = v36 + *(float *)&mw;
      }
      v37 = (float)(m_Storage + 0.5) / v26;
      v38 = (float)((float)(v29 - 0.5) / v26) - v37;
      v39 = (float)(v30 + 0.5) / v27;
      v40 = (float)((float)(v31 - 0.5) / v27) - v39;
      flRadians = (float)((float)((x - tx) / totalRect) * v38) + v37;
      u1 = (float)((float)((x + w - tx) / totalRect) * v38) + v37;
      v41 = (float)((float)((y - ty) / th) * v40) + v39;
      v42 = (y + h - ty) / th;
      ya = y - currentRect->y;
      dU = v41;
      x -= currentRect->x;
      *(float *)&v1.m_tms = (float)((float)v42 * v40) + v39;
      CMatRenderContextPtr::CMatRenderContextPtr(this: (CMatRenderContextPtr *)&totalRect, pFrom: materials);
      v43 = this->m_OverlayMaterial.m_pMaterial->NeedsPowerOfTwoFrameBufferTexture(
              this: this->m_OverlayMaterial.m_pMaterial,
              a2: true);
      v44 = (Rect_t *)totalRect;
      if ( v43 )
      {
        (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)totalRect + 36))(
          a1: totalRect,
          a2: this->m_BltMaterial.m_pMaterial,
          a3: *(_DWORD *)LODWORD(pTextures));
        (*(void (__thiscall **)(Rect_t *, ITexture *, _DWORD, _DWORD, int, int))(v44->x + 432))(
          a1: v44,
          a2: *(ITexture **)(LODWORD(pTextures) + 4),
          a3: 0,
          a4: 0,
          a5: w,
          a6: h);
        CDmeMaterialOverlayFXClip::DrawOneToOneQuad(this, nWidth: w, nHeight: h);
        (*(void (__thiscall **)(Rect_t *))(v44->x + 444))(a1: v44);
        (*(void (__thiscall **)(Rect_t *, ITexture *, _DWORD))(v44->x + 72))(
          a1: v44,
          a2: *(ITexture **)(LODWORD(pTextures) + 4),
          a3: 0);
        (*(void (__thiscall **)(Rect_t *, _DWORD, _DWORD, _DWORD, int, int))(v44->x + 432))(
          a1: v44,
          a2: *(_DWORD *)LODWORD(pTextures),
          a3: 0,
          a4: 0,
          a5: w,
          a6: h);
      }
      this->m_OverlayMaterial.m_pMaterial->GetColorModulation(
        this: this->m_OverlayMaterial.m_pMaterial,
        a2: (float *)((char *)&v46 + 4),
        a3: (float *)&g,
        a4: &b);
      pTextures = this->m_OverlayMaterial.m_pMaterial->GetAlphaModulation(this: this->m_OverlayMaterial.m_pMaterial);
      ((void (__thiscall *)(IMaterial *, _DWORD, _DWORD, _DWORD))this->m_OverlayMaterial.m_pMaterial->ColorModulate)(
        a1: this->m_OverlayMaterial.m_pMaterial,
        a2: (float)this->m_Color.m_Storage._color[0] * 0.0039215689,
        a3: (float)this->m_Color.m_Storage._color[1] * 0.0039215689,
        a4: (float)this->m_Color.m_Storage._color[2] * 0.0039215689);
      ((void (__stdcall *)(_DWORD))this->m_OverlayMaterial.m_pMaterial->AlphaModulate)(a1: (float)this->m_Color.m_Storage._color[3] * 0.0039215689);
      (*(void (__thiscall **)(Rect_t *, IMaterial *, _DWORD))(v44->x + 36))(
        a1: v44,
        a2: this->m_OverlayMaterial.m_pMaterial,
        a3: 0);
      CDmeMaterialOverlayFXClip::DrawQuad(
        this,
        a2: (int)v44,
        x,
        y: ya,
        w,
        h,
        u0: flRadians,
        v0: dU,
        u1,
        v1: *(float *)&v1.m_tms);
      if ( this->m_OverlayMaterial.m_pMaterial->NeedsPowerOfTwoFrameBufferTexture(
             this: this->m_OverlayMaterial.m_pMaterial,
             a2: true) )
      {
        (*(void (__thiscall **)(Rect_t *))(v44->x + 444))(a1: v44);
      }
      ((void (__thiscall *)(IMaterial *, _DWORD, int))this->m_OverlayMaterial.m_pMaterial->ColorModulate)(
        a1: this->m_OverlayMaterial.m_pMaterial,
        a2: HIDWORD(v46),
        a3: g);
      ((void (__stdcall *)(_DWORD))this->m_OverlayMaterial.m_pMaterial->AlphaModulate)(a1: LODWORD(pTextures));
      CMatRenderContextPtr::~CMatRenderContextPtr(this: (CMatRenderContextPtr *)&totalRect);
    }
    return;
  }
  v12 = currentRect->x;
  v13 = this->m_nLeft.m_Storage;
  v14 = currentRect->x + width;
  mw = v14;
  if ( v13 >= v12 )
  {
    x = v14;
    if ( v13 <= v14 )
      x = v13;
  }
  else
  {
    x = v12;
  }
  v15 = currentRect->y;
  totalRect = v15 + currentRect->height;
  v16 = this->m_nTop.m_Storage;
  if ( v16 >= v15 )
  {
    y = totalRect;
    if ( v16 <= totalRect )
      y = this->m_nTop.m_Storage;
  }
  else
  {
    y = v15;
  }
  v17 = this->m_nLeft.m_Storage + this->m_nWidth.m_Storage;
  if ( v17 >= v12 )
  {
    v12 = mw;
    if ( v17 <= mw )
      v12 = this->m_nLeft.m_Storage + this->m_nWidth.m_Storage;
  }
  v18 = this->m_nHeight.m_Storage + v16;
  v19 = currentRect->y;
  if ( v18 >= v19 )
  {
    v19 = totalRect;
    if ( v18 <= totalRect )
      v19 = v18;
  }
  v20 = v19 - y;
  tx = this->m_nLeft.m_Storage;
  ty = this->m_nTop.m_Storage;
  totalRect = this->m_nWidth.m_Storage;
  v21 = this->m_nHeight.m_Storage;
  w = v12 - x;
  h = v20;
  th = v21;
  if ( v12 - x > 0 && v20 > 0 )
    goto LABEL_22;
}

//------------------------------------------------------------------------------
// Address: 0x005F4F20
// Name: protected: CDmeMaterialOverlayFXClip::CDmeMaterialOverlayFXClip(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMaterialOverlayFXClip *__thiscall CDmeMaterialOverlayFXClip::CDmeMaterialOverlayFXClip(
        CDmeMaterialOverlayFXClip *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeMaterialOverlayFXClip_vtbl *)&CDmeClip::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_TrackGroups);
  this->m_TimeFrame.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_TimeFrame.m_pAttribute = nullptr;
  this->m_TimeFrame.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_ClipColor.m_pAttribute = nullptr;
  this->m_ClipColor.m_Storage = (Color)-16777216;
  this->m_bMute.m_pAttribute = nullptr;
  this->m_bMute.m_Storage = false;
  this->m_flDisplayScale = 0;
  this->m_ClipText.m_pAttribute = nullptr;
  this->m_ClipText.m_Storage.u.CDmeFXClip::CDmeClip::m_Id = -1;
  this->__vftable = (CDmeMaterialOverlayFXClip_vtbl *)&CDmeMaterialOverlayFXClip::`vftable';
  this->m_Material.m_pAttribute = nullptr;
  this->m_Material.m_Storage.u.m_Id = -1;
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_nLeft.m_pAttribute = nullptr;
  this->m_nLeft.m_Storage = 0;
  this->m_nTop.m_pAttribute = nullptr;
  this->m_nTop.m_Storage = 0;
  this->m_nWidth.m_pAttribute = nullptr;
  this->m_nWidth.m_Storage = 0;
  this->m_nHeight.m_pAttribute = nullptr;
  this->m_nHeight.m_Storage = 0;
  this->m_bFullScreen.m_pAttribute = nullptr;
  this->m_bFullScreen.m_Storage = false;
  this->m_bUseSubRect.m_pAttribute = nullptr;
  this->m_bUseSubRect.m_Storage = false;
  this->m_nSubRectLeft.m_pAttribute = nullptr;
  this->m_nSubRectLeft.m_Storage = 0;
  this->m_nSubRectTop.m_pAttribute = nullptr;
  this->m_nSubRectTop.m_Storage = 0;
  this->m_nSubRectWidth.m_pAttribute = nullptr;
  this->m_nSubRectWidth.m_Storage = 0;
  this->m_nSubRectHeight.m_pAttribute = nullptr;
  this->m_nSubRectHeight.m_Storage = 0;
  this->m_flMovementAngle = 0;
  this->m_flMovementSpeed = 0;
  CMaterialReference::CMaterialReference(
    this: &this->m_OverlayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_BltMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005F5070
// Name: public: virtual bool CDmeMaterialOverlayFXClip::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMaterialOverlayFXClip::IsA(CDmeMaterialOverlayFXClip *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMaterialOverlayFXClip::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFXClip::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeClip::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005F50B0
// Name: public: virtual int CDmeMaterialOverlayFXClip::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialOverlayFXClip::GetInheritanceDepth(
        CDmeMaterialOverlayFXClip *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMaterialOverlayFXClip::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFXClip::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeClip::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005F5110
// Name: protected: virtual void CDmeMaterialOverlayFXClip::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::PerformDestruction(CDmeMaterialOverlayFXClip *this)
{
  CMaterialReference::Shutdown(this: &this->m_BltMaterial, bDeleteIfUnreferenced: false);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x005F5140
// Name: protected: virtual int CDmeMaterialOverlayFXClip::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialOverlayFXClip::AllocatedSize(CDmeMaterialOverlayFXClip *this)
{
  return 260;
}

//------------------------------------------------------------------------------
// Address: 0x005F5150
// Name: protected: virtual void CDmeMaterialOverlayFXClip::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::PerformConstruction(CDmeMaterialOverlayFXClip *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeClip::OnConstruction(this);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeMaterialOverlayFXClip::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006B2A40
// Name: _dynamic_initializer_for__CDmeMaterialOverlayFXClip::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMaterialOverlayFXClip::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMaterialOverlayFXClip::s_Allocator,
    blockSize: 260,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMaterialOverlayFXClip pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5D60
// Name: _dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMaterialOverlayFXClip::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B2A70
// Name: _dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Factory__()
{
  CDmeFXClip::InstallFXClipType(pElementType: "DmeMaterialOverlayFXClip", pDescription: "Material Overlay Effect");
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B2A90
// Name: _dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMaterialOverlayFXClip_Helper,
           classname: "DmeMaterialOverlayFXClip",
           pFactory: &g_CDmeMaterialOverlayFXClip_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B2AB0
// Name: _dynamic_initializer_for__s_ParticleSystemMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ParticleSystemMgr__()
{
  CParticleSystemMgr::CParticleSystemMgr(this: &s_ParticleSystemMgr);
  return atexit(func: dynamic_atexit_destructor_for__s_ParticleSystemMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5D70
// Name: _dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeMaterialOverlayFXClip_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B5D80
// Name: _dynamic_atexit_destructor_for__s_ParticleSystemMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ParticleSystemMgr__()
{
  CParticleSystemMgr::~CParticleSystemMgr(this: &s_ParticleSystemMgr);
}

//------------------------------------------------------------------------------
// Address: 0x006B5D90
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5DA0
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x006B5DF0
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x006B5E30
// Name: _dynamic_atexit_destructor_for__g_OverridenColorSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_OverridenColorSymbols__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_OverridenColorSymbols);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00535F80
// Name: public: virtual void CDmeMaterialOverlayFXClip::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::Resolve(CDmeMaterialOverlayFXClip *this)
{
  const char *m_pAsString; // eax

  if ( SLOBYTE(this->m_Material.m_pAttribute->m_nFlags) < 0 )
  {
    CMaterialReference::Shutdown(this: &this->m_OverlayMaterial, bDeleteIfUnreferenced: false);
    m_pAsString = this->m_Material.m_Storage.u.m_pAsString;
    if ( m_pAsString != (const char *)-1 && m_pAsString != nullptr && *m_pAsString != 0 )
      CMaterialReference::Init(
        this: &this->m_OverlayMaterial,
        pMaterialName: m_pAsString,
        pTextureGroupName: nullptr,
        bComplain: false);
    this->m_Material.m_pAttribute->m_nFlags &= ~0x80u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00535FE0
// Name: protected: void CDmeMaterialOverlayFXClip::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::OnConstruction(CDmeMaterialOverlayFXClip *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  CDmAttribute *v4; // ecx
  CDmAttribute *v5; // ecx
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  KeyValues *Key; // eax
  Color value; // [esp+Ch] [ebp-8h] BYREF
  bool v10; // [esp+13h] [ebp-1h] BYREF

  this->m_Material.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "material",
                                    type: AT_STRING,
                                    pMemory: &this->m_Material);
  this->m_Color.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "overlaycolor",
                                 type: AT_COLOR,
                                 pMemory: &this->m_Color);
  this->m_nLeft.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "left",
                                 type: AT_INT,
                                 pMemory: &this->m_nLeft);
  this->m_nTop.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "top",
                                type: AT_INT,
                                pMemory: &this->m_nTop);
  this->m_nWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "width",
                                  type: AT_INT,
                                  pMemory: &this->m_nWidth);
  this->m_nHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "height",
                                   type: AT_INT,
                                   pMemory: &this->m_nHeight);
  this->m_bFullScreen.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "fullscreen",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bFullScreen);
  this->m_bUseSubRect.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "useSubRect",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bUseSubRect);
  this->m_flMovementAngle.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "movementAngle",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flMovementAngle);
  this->m_flMovementSpeed.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "movementSpeed",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flMovementSpeed);
  this->m_nSubRectLeft.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "subRectLeft",
                                        type: AT_INT,
                                        pMemory: &this->m_nSubRectLeft);
  this->m_nSubRectTop.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "subRectTop",
                                       type: AT_INT,
                                       pMemory: &this->m_nSubRectTop);
  this->m_nSubRectWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "subRectWidth",
                                         type: AT_INT,
                                         pMemory: &this->m_nSubRectWidth);
  this->m_nSubRectHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "subRectHeight",
                                          type: AT_INT,
                                          pMemory: &this->m_nSubRectHeight);
  m_pAttribute = this->m_Color.m_pAttribute;
  value = (Color)-1;
  CDmAttribute::SetValue<Color>(this: m_pAttribute, &value);
  v3 = this->m_bFullScreen.m_pAttribute;
  v10 = true;
  CDmAttribute::SetValue<bool>(this: v3, value: &v10);
  v4 = this->m_nTop.m_pAttribute;
  value = 0;
  CDmAttribute::SetValue<int>(this: v4, (int *)&value);
  CDmAttribute::SetValue<int>(this: this->m_nLeft.m_pAttribute, value: &this->m_nTop.m_Storage);
  v5 = this->m_nHeight.m_pAttribute;
  value = (Color)1;
  CDmAttribute::SetValue<int>(this: v5, (int *)&value);
  CDmAttribute::SetValue<int>(this: this->m_nWidth.m_pAttribute, value: &this->m_nHeight.m_Storage);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "accumbuff4sample");
  else
    v7 = nullptr;
  KeyValues::SetString(this: v7, keyName: "$INPUT", value: "Effects/FilmScan256");
  Key = KeyValues::FindKey(this: v7, keyName: "proxies", bCreate: true);
  KeyValues::FindKey(this: Key, keyName: "sfm_blt", bCreate: true);
  CMaterialReference::Init(this: &this->m_BltMaterial, pMaterialName: "accumbuff4sample", pVMTKeyValues: v7);
  this->m_BltMaterial.m_pMaterial->Refresh(this: this->m_BltMaterial.m_pMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x00536230
// Name: private: void CDmeMaterialOverlayFXClip::DrawQuad(int,int,int,int,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeMaterialOverlayFXClip::DrawQuad(
        CDmeMaterialOverlayFXClip *this@<ecx>,
        int a2@<edi>,
        int x,
        int y,
        int w,
        int h,
        float u0,
        float v0,
        float u1,
        float v1)
{
  IMatRenderContext *v10; // esi
  IMesh *v11; // esi
  float *m_pCurrPosition; // eax
  float *v13; // eax
  float *v14; // eax
  float *v15; // eax
  int v16; // eax
  float *v17; // eax
  float v18; // xmm5_4
  float *v19; // eax
  float *v20; // eax
  float *v21; // eax
  int v22; // eax
  float *v23; // eax
  float v24; // xmm2_4
  float *v25; // eax
  float *v26; // eax
  float *v27; // eax
  int v28; // eax
  float *v29; // eax
  float *v30; // eax
  float *v31; // eax
  float *v32; // eax
  int m_nVertexCount; // eax
  int v34; // ecx
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1ECh] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F0h] [ebp-4h]

  v10 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v10;
  if ( v10 != nullptr )
    v10->BeginRender(this: v10);
  v11 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, int))v10->GetDynamicMesh)(
                   a1: v10,
                   a2: 1,
                   a3: 0,
                   a4: 0,
                   a5: 0,
                   a6: a2);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v11;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_TRIANGLE_STRIP;
  v11->SetPrimitiveType(this: v11, a2: MATERIAL_TRIANGLE_STRIP);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 4, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v11->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 4;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v11, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)x;
  m_pCurrPosition[1] = (float)y;
  m_pCurrPosition[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v13 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u0;
  v13[1] = v0;
  v14 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 0.0;
  v14[1] = 0.0;
  v15 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v15[1] = 0.0;
  v16 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v16;
  if ( v16 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v16;
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  v17 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v17;
  *v17 = (float)x;
  v18 = (float)(h + y);
  v17[1] = v18;
  v17[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v19 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u0;
  v19[1] = v1;
  v20 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 0.0;
  v20[1] = 1.0;
  v21 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v21[1] = 0.0;
  v22 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v22;
  if ( v22 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v22;
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  v23 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v23;
  v24 = (float)(w + x);
  *v23 = v24;
  v23[1] = (float)y;
  v23[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v25 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u1;
  v25[1] = v0;
  v26 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 1.0;
  v26[1] = 0.0;
  v27 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v27[1] = 0.0;
  v28 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v28;
  if ( v28 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v28;
  v29 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v29;
  *v29 = v24;
  v29[1] = v18;
  v29[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v30 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u1;
  v30[1] = v1;
  v31 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 1.0;
  v31[1] = 1.0;
  v32 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v32[1] = 0.0;
  m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  v34 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v34;
  if ( v34 > meshBuilder.m_VertexBuilder.m_nVertexCount )
  {
    m_nVertexCount = v34;
    meshBuilder.m_VertexBuilder.m_nVertexCount = v34;
  }
  meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount *= 2;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  }
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
  v11->Draw_2(this: v11, a2: -1, a3: 0);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x00536730
// Name: private: void CDmeMaterialOverlayFXClip::DrawOneToOneQuad(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::DrawOneToOneQuad(CDmeMaterialOverlayFXClip *this, int nWidth, int nHeight)
{
  IMatRenderContext *v3; // esi
  IMesh *v4; // esi
  float *m_pCurrPosition; // eax
  float v6; // xmm0_4
  float *v7; // eax
  int v8; // eax
  float *v9; // eax
  float *v10; // eax
  int v11; // eax
  float *v12; // eax
  float *v13; // eax
  float v14; // xmm0_4
  int v15; // eax
  float *v16; // eax
  float *v17; // eax
  int m_nVertexCount; // eax
  int v19; // ecx
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1ECh] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F0h] [ebp-4h]
  float fHeightEpsilon; // [esp+200h] [ebp+Ch]

  v3 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v3;
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  v4 = v3->GetDynamicMesh(this: v3, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v4;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_QUADS;
  fHeightEpsilon = 0.5 / (float)nHeight;
  v4->SetPrimitiveType(this: v4, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v4->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v4, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v6 = 0.5 / (float)nWidth;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = -1.0;
  m_pCurrPosition[1] = 1.0;
  m_pCurrPosition[2] = 0.5;
  v7 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v6;
  v7[1] = fHeightEpsilon;
  v8 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v8;
  if ( v8 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v8;
  v9 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v9;
  *v9 = -1.0;
  v9[1] = -1.0;
  v9[2] = 0.5;
  v10 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v6;
  v10[1] = fHeightEpsilon + 1.0;
  v11 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v11;
  if ( v11 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v11;
  v12 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v12;
  *v12 = 1.0;
  v12[1] = -1.0;
  v12[2] = 0.5;
  v13 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  v14 = v6 + 1.0;
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v14;
  v13[1] = fHeightEpsilon + 1.0;
  v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
  if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
  v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
  *v16 = 1.0;
  v16[1] = 1.0;
  v16[2] = 0.5;
  v17 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v14;
  v17[1] = fHeightEpsilon;
  m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  v19 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v19;
  if ( v19 > meshBuilder.m_VertexBuilder.m_nVertexCount )
  {
    m_nVertexCount = v19;
    meshBuilder.m_VertexBuilder.m_nVertexCount = v19;
  }
  meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount *= 2;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  }
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v4->Draw_2(this: v4, a2: -1, a3: 0);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x00536AA0
// Name: public: virtual void CDmeMaterialOverlayFXClip::ApplyEffect(class DmeTime_t,struct Rect_t __near &,struct Rect_t __near &,class ITexture __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CDmeMaterialOverlayFXClip::ApplyEffect(
        CDmeMaterialOverlayFXClip *this@<ecx>,
        int a2@<edi>,
        DmeTime_t time,
        Rect_t *currentRect,
        int totalRect,
        float pTextures)
{
  int width; // edx
  int v9; // ecx
  Rect_t *v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // edx
  int v17; // eax
  int v18; // edx
  int v19; // eax
  int v20; // eax
  int v21; // edx
  int v22; // eax
  IMaterial *m_pMaterial; // ecx
  int v24; // eax
  bool v25; // zf
  float v26; // xmm5_4
  float v27; // xmm6_4
  float m_Storage; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm3_4
  float v31; // xmm1_4
  double v32; // xmm0_8
  double v33; // xmm0_8
  double v34; // xmm0_8
  float v35; // xmm1_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm3_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  int v42; // eax
  bool v43; // al
  Rect_t *v44; // edi
  long double v46; // [esp+78h] [ebp-50h] OVERLAPPED BYREF
  int g; // [esp+80h] [ebp-48h] BYREF
  float b; // [esp+84h] [ebp-44h] BYREF
  DmeTime_t v1; // [esp+88h] [ebp-40h] BYREF
  float u1; // [esp+8Ch] [ebp-3Ch]
  float dU; // [esp+90h] [ebp-38h]
  float flRadians; // [esp+94h] [ebp-34h]
  int mw; // [esp+98h] [ebp-30h]
  float vMin; // [esp+9Ch] [ebp-2Ch]
  float uMax; // [esp+A0h] [ebp-28h]
  float uMin; // [esp+A4h] [ebp-24h]
  float v57; // [esp+A8h] [ebp-20h]
  float v58; // [esp+ACh] [ebp-1Ch]
  int ty; // [esp+B0h] [ebp-18h]
  int th; // [esp+B4h] [ebp-14h]
  int tx; // [esp+B8h] [ebp-10h]
  int w; // [esp+BCh] [ebp-Ch]
  int h; // [esp+C0h] [ebp-8h]
  int x; // [esp+C4h] [ebp-4h]
  int timea; // [esp+D0h] [ebp+8h]
  int y; // [esp+D4h] [ebp+Ch]
  int ya; // [esp+D4h] [ebp+Ch]

  if ( this->m_OverlayMaterial.m_pMaterial == nullptr
    || this->m_BltMaterial.m_pMaterial == nullptr
    || this->m_Color.m_Storage._color[3] == 0 )
  {
    return;
  }
  timea = CDmeClip::ToChildMediaTime(this, result: &v1, t: time, bClamp: 0)->m_tms;
  width = currentRect->width;
  if ( this->m_bFullScreen.m_Storage )
  {
    v9 = currentRect->y;
    x = currentRect->x;
    h = currentRect->height;
    y = v9;
    v10 = *(Rect_t **)(totalRect + 8);
    w = width;
    v11 = *(_DWORD *)(totalRect + 12);
    ty = 0;
    tx = 0;
    totalRect = (int)v10;
    th = v11;
LABEL_22:
    if ( totalRect != 0 && th != 0 )
    {
      v22 = ((int (__thiscall *)(IMaterial *, int))this->m_OverlayMaterial.m_pMaterial->GetMappingWidth)(
              a1: this->m_OverlayMaterial.m_pMaterial,
              a2);
      m_pMaterial = this->m_OverlayMaterial.m_pMaterial;
      mw = v22;
      v24 = m_pMaterial->GetMappingHeight(this: m_pMaterial);
      v25 = !this->m_bUseSubRect.m_Storage;
      v26 = (float)mw;
      v27 = (float)v24;
      m_Storage = 0.0;
      v29 = (float)mw;
      v30 = 0.0;
      v31 = (float)v24;
      uMin = 0.0;
      u1 = (float)mw;
      uMax = (float)mw;
      vMin = 0.0;
      *(float *)&v1.m_tms = (float)v24;
      *(float *)&mw = (float)v24;
      if ( !v25 )
      {
        m_Storage = (float)this->m_nSubRectLeft.m_Storage;
        v30 = (float)this->m_nSubRectTop.m_Storage;
        v29 = (float)this->m_nSubRectWidth.m_Storage + m_Storage;
        v31 = (float)this->m_nSubRectHeight.m_Storage + v30;
        uMin = m_Storage;
        vMin = v30;
        uMax = v29;
        *(float *)&mw = v31;
      }
      v58 = this->m_flMovementSpeed.m_Storage;
      if ( v58 != 0.0 )
      {
        v32 = this->m_flMovementAngle.m_Storage;
        v57 = (float)timea * 0.000099999997;
        flRadians = v32 * 3.141592653589793 * 0.005555555555555556;
        v33 = flRadians;
        __libm_sse2_cos(x: v46);
        *(float *)&v33 = v33;
        dU = COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&v33 * v58) ^ _mask__NegFloat_) * v57;
        v34 = flRadians;
        __libm_sse2_sin(x: v46);
        v26 = u1;
        v27 = *(float *)&v1.m_tms;
        v35 = v34;
        v36 = (float)(v35 * v58) * v57;
        m_Storage = dU + uMin;
        v29 = dU + uMax;
        v30 = v36 + vMin;
        v31 = v36 + *(float *)&mw;
      }
      v37 = (float)(m_Storage + 0.5) / v26;
      v38 = (float)((float)(v29 - 0.5) / v26) - v37;
      v39 = (float)(v30 + 0.5) / v27;
      v40 = (float)((float)(v31 - 0.5) / v27) - v39;
      flRadians = (float)((float)((x - tx) / totalRect) * v38) + v37;
      u1 = (float)((float)((x + w - tx) / totalRect) * v38) + v37;
      v41 = (float)((float)((y - ty) / th) * v40) + v39;
      v42 = (y + h - ty) / th;
      ya = y - currentRect->y;
      dU = v41;
      x -= currentRect->x;
      *(float *)&v1.m_tms = (float)((float)v42 * v40) + v39;
      CMatRenderContextPtr::CMatRenderContextPtr(this: (CMatRenderContextPtr *)&totalRect, pFrom: materials);
      v43 = this->m_OverlayMaterial.m_pMaterial->NeedsPowerOfTwoFrameBufferTexture(
              this: this->m_OverlayMaterial.m_pMaterial,
              a2: true);
      v44 = (Rect_t *)totalRect;
      if ( v43 )
      {
        (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)totalRect + 36))(
          a1: totalRect,
          a2: this->m_BltMaterial.m_pMaterial,
          a3: *(_DWORD *)LODWORD(pTextures));
        (*(void (__thiscall **)(Rect_t *, ITexture *, _DWORD, _DWORD, int, int))(v44->x + 432))(
          a1: v44,
          a2: *(ITexture **)(LODWORD(pTextures) + 4),
          a3: 0,
          a4: 0,
          a5: w,
          a6: h);
        CDmeMaterialOverlayFXClip::DrawOneToOneQuad(this, nWidth: w, nHeight: h);
        (*(void (__thiscall **)(Rect_t *))(v44->x + 444))(a1: v44);
        (*(void (__thiscall **)(Rect_t *, ITexture *, _DWORD))(v44->x + 72))(
          a1: v44,
          a2: *(ITexture **)(LODWORD(pTextures) + 4),
          a3: 0);
        (*(void (__thiscall **)(Rect_t *, _DWORD, _DWORD, _DWORD, int, int))(v44->x + 432))(
          a1: v44,
          a2: *(_DWORD *)LODWORD(pTextures),
          a3: 0,
          a4: 0,
          a5: w,
          a6: h);
      }
      this->m_OverlayMaterial.m_pMaterial->GetColorModulation(
        this: this->m_OverlayMaterial.m_pMaterial,
        a2: (float *)((char *)&v46 + 4),
        a3: (float *)&g,
        a4: &b);
      pTextures = this->m_OverlayMaterial.m_pMaterial->GetAlphaModulation(this: this->m_OverlayMaterial.m_pMaterial);
      ((void (__thiscall *)(IMaterial *, _DWORD, _DWORD, _DWORD))this->m_OverlayMaterial.m_pMaterial->ColorModulate)(
        a1: this->m_OverlayMaterial.m_pMaterial,
        a2: (float)this->m_Color.m_Storage._color[0] * 0.0039215689,
        a3: (float)this->m_Color.m_Storage._color[1] * 0.0039215689,
        a4: (float)this->m_Color.m_Storage._color[2] * 0.0039215689);
      ((void (__stdcall *)(_DWORD))this->m_OverlayMaterial.m_pMaterial->AlphaModulate)(a1: (float)this->m_Color.m_Storage._color[3] * 0.0039215689);
      (*(void (__thiscall **)(Rect_t *, IMaterial *, _DWORD))(v44->x + 36))(
        a1: v44,
        a2: this->m_OverlayMaterial.m_pMaterial,
        a3: 0);
      CDmeMaterialOverlayFXClip::DrawQuad(
        this,
        a2: (int)v44,
        x,
        y: ya,
        w,
        h,
        u0: flRadians,
        v0: dU,
        u1,
        v1: *(float *)&v1.m_tms);
      if ( this->m_OverlayMaterial.m_pMaterial->NeedsPowerOfTwoFrameBufferTexture(
             this: this->m_OverlayMaterial.m_pMaterial,
             a2: true) )
      {
        (*(void (__thiscall **)(Rect_t *))(v44->x + 444))(a1: v44);
      }
      ((void (__thiscall *)(IMaterial *, _DWORD, int))this->m_OverlayMaterial.m_pMaterial->ColorModulate)(
        a1: this->m_OverlayMaterial.m_pMaterial,
        a2: HIDWORD(v46),
        a3: g);
      ((void (__stdcall *)(_DWORD))this->m_OverlayMaterial.m_pMaterial->AlphaModulate)(a1: LODWORD(pTextures));
      CMatRenderContextPtr::~CMatRenderContextPtr(this: (CMatRenderContextPtr *)&totalRect);
    }
    return;
  }
  v12 = currentRect->x;
  v13 = this->m_nLeft.m_Storage;
  v14 = currentRect->x + width;
  mw = v14;
  if ( v13 >= v12 )
  {
    x = v14;
    if ( v13 <= v14 )
      x = v13;
  }
  else
  {
    x = v12;
  }
  v15 = currentRect->y;
  totalRect = v15 + currentRect->height;
  v16 = this->m_nTop.m_Storage;
  if ( v16 >= v15 )
  {
    y = totalRect;
    if ( v16 <= totalRect )
      y = this->m_nTop.m_Storage;
  }
  else
  {
    y = v15;
  }
  v17 = this->m_nLeft.m_Storage + this->m_nWidth.m_Storage;
  if ( v17 >= v12 )
  {
    v12 = mw;
    if ( v17 <= mw )
      v12 = this->m_nLeft.m_Storage + this->m_nWidth.m_Storage;
  }
  v18 = this->m_nHeight.m_Storage + v16;
  v19 = currentRect->y;
  if ( v18 >= v19 )
  {
    v19 = totalRect;
    if ( v18 <= totalRect )
      v19 = v18;
  }
  v20 = v19 - y;
  tx = this->m_nLeft.m_Storage;
  ty = this->m_nTop.m_Storage;
  totalRect = this->m_nWidth.m_Storage;
  v21 = this->m_nHeight.m_Storage;
  w = v12 - x;
  h = v20;
  th = v21;
  if ( v12 - x > 0 && v20 > 0 )
    goto LABEL_22;
}

//------------------------------------------------------------------------------
// Address: 0x005370B0
// Name: protected: CDmeMaterialOverlayFXClip::CDmeMaterialOverlayFXClip(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMaterialOverlayFXClip *__thiscall CDmeMaterialOverlayFXClip::CDmeMaterialOverlayFXClip(
        CDmeMaterialOverlayFXClip *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeMaterialOverlayFXClip_vtbl *)&CDmeClip::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_TrackGroups);
  this->m_TimeFrame.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_TimeFrame.m_pAttribute = nullptr;
  this->m_TimeFrame.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_ClipColor.m_pAttribute = nullptr;
  this->m_ClipColor.m_Storage = (Color)-16777216;
  this->m_bMute.m_pAttribute = nullptr;
  this->m_bMute.m_Storage = false;
  this->m_flDisplayScale = 0;
  this->m_ClipText.m_pAttribute = nullptr;
  this->m_ClipText.m_Storage.u.CDmeFXClip::CDmeClip::m_Id = -1;
  this->__vftable = (CDmeMaterialOverlayFXClip_vtbl *)&CDmeMaterialOverlayFXClip::`vftable';
  this->m_Material.m_pAttribute = nullptr;
  this->m_Material.m_Storage.u.m_Id = -1;
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_nLeft.m_pAttribute = nullptr;
  this->m_nLeft.m_Storage = 0;
  this->m_nTop.m_pAttribute = nullptr;
  this->m_nTop.m_Storage = 0;
  this->m_nWidth.m_pAttribute = nullptr;
  this->m_nWidth.m_Storage = 0;
  this->m_nHeight.m_pAttribute = nullptr;
  this->m_nHeight.m_Storage = 0;
  this->m_bFullScreen.m_pAttribute = nullptr;
  this->m_bFullScreen.m_Storage = false;
  this->m_bUseSubRect.m_pAttribute = nullptr;
  this->m_bUseSubRect.m_Storage = false;
  this->m_nSubRectLeft.m_pAttribute = nullptr;
  this->m_nSubRectLeft.m_Storage = 0;
  this->m_nSubRectTop.m_pAttribute = nullptr;
  this->m_nSubRectTop.m_Storage = 0;
  this->m_nSubRectWidth.m_pAttribute = nullptr;
  this->m_nSubRectWidth.m_Storage = 0;
  this->m_nSubRectHeight.m_pAttribute = nullptr;
  this->m_nSubRectHeight.m_Storage = 0;
  this->m_flMovementAngle = 0;
  this->m_flMovementSpeed = 0;
  CMaterialReference::CMaterialReference(
    this: &this->m_OverlayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_BltMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00537200
// Name: public: virtual bool CDmeMaterialOverlayFXClip::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMaterialOverlayFXClip::IsA(CDmeMaterialOverlayFXClip *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMaterialOverlayFXClip::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFXClip::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeClip::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00537240
// Name: public: virtual int CDmeMaterialOverlayFXClip::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialOverlayFXClip::GetInheritanceDepth(
        CDmeMaterialOverlayFXClip *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMaterialOverlayFXClip::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFXClip::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeClip::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005372A0
// Name: protected: virtual void CDmeMaterialOverlayFXClip::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::PerformDestruction(CDmeMaterialOverlayFXClip *this)
{
  CMaterialReference::Shutdown(this: &this->m_BltMaterial, bDeleteIfUnreferenced: false);
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x005372D0
// Name: protected: virtual int CDmeMaterialOverlayFXClip::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialOverlayFXClip::AllocatedSize(CDmeMaterialOverlayFXClip *this)
{
  return 260;
}

//------------------------------------------------------------------------------
// Address: 0x005372E0
// Name: protected: virtual void CDmeMaterialOverlayFXClip::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::PerformConstruction(CDmeMaterialOverlayFXClip *this)
{
  CDmeFXClip::OnDestruction();
  CDmeClip::OnConstruction(this);
  CDmeFXClip::OnDestruction();
  CDmeMaterialOverlayFXClip::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057F6E0
// Name: _dynamic_initializer_for__CDmeMaterialOverlayFXClip::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMaterialOverlayFXClip::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMaterialOverlayFXClip::s_Allocator,
    blockSize: 260,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMaterialOverlayFXClip pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005814B0
// Name: _dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMaterialOverlayFXClip::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057F710
// Name: _dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Factory__()
{
  CDmeFXClip::InstallFXClipType(pElementType: "DmeMaterialOverlayFXClip", pDescription: "Material Overlay Effect");
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F730
// Name: _dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMaterialOverlayFXClip_Helper,
           classname: "DmeMaterialOverlayFXClip",
           pFactory: &g_CDmeMaterialOverlayFXClip_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057F750
// Name: _dynamic_initializer_for__mod_load_preload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_preload__()
{
  ConVar::ConVar(
    this: &mod_load_preload,
    pName: "mod_load_preload",
    pDefaultValue: "1.0",
    flags: 0,
    pHelpString: "Indicates how far ahead in seconds to preload animations.");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_preload__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F780
// Name: _dynamic_initializer_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_showstall__()
{
  ConVar::ConVar(
    this: &mod_load_showstall,
    pName: "mod_load_showstall",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "1 - show hitches , 2 - show stalls");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_showstall__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F7B0
// Name: _dynamic_initializer_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ActivityModifiersTable, growSize: 0, initSize: 16, caseInsensitive: false);
  return atexit(func: dynamic_atexit_destructor_for__g_ActivityModifiersTable__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F7D0
// Name: _dynamic_initializer_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall dynamic_initializer_for__emptyMapping__(char a1)
{
  int v2; // [esp-4h] [ebp-Ch] BYREF
  CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs v3; // [esp+0h] [ebp-8h]
  int *v4; // [esp+4h] [ebp-4h]

  v4 = &v2;
  CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>::CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>(
    this: &emptyMapping.m_ActToSeqHash,
    bucketCount: 8,
    growCount: 0,
    initCount: 0,
    compareFunc: (CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs)a1,
    keyFunc: v3);
  emptyMapping.m_pStudioHdr = nullptr;
  emptyMapping.m_expectedVModel = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__emptyMapping__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F820
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMaps__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F830
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMapsLock__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMapsLock__()
{
  g_StudioHdrToActivityMapsLock.m_ownerID = 0;
  g_StudioHdrToActivityMapsLock.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005814C0
// Name: _dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMaterialOverlayFXClip_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005814D0
// Name: _dynamic_atexit_destructor_for__mod_load_preload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_preload__()
{
  ConVar::~ConVar(this: &mod_load_preload);
}

//------------------------------------------------------------------------------
// Address: 0x005814E0
// Name: _dynamic_atexit_destructor_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_showstall__()
{
  ConVar::~ConVar(this: &mod_load_showstall);
}

//------------------------------------------------------------------------------
// Address: 0x005814F0
// Name: _dynamic_atexit_destructor_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ActivityModifiersTable);
}

//------------------------------------------------------------------------------
// Address: 0x00581500
// Name: _dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__()
{
  CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_StudioHdrToActivityMaps.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00581510
// Name: _dynamic_atexit_destructor_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__emptyMapping__()
{
  CStudioHdr::CActivityToSequenceMapping::SequenceTuple *m_pSequenceTuples; // ecx

  m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
  if ( emptyMapping.m_pSequenceTuples != nullptr )
  {
    if ( emptyMapping.m_pSequenceTuples->pActivityModifiers != nullptr )
    {
      free(pMem: emptyMapping.m_pSequenceTuples->pActivityModifiers);
      m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
    }
    free(pMem: m_pSequenceTuples);
  }
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: &emptyMapping.m_ActToSeqHash);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: &emptyMapping.m_ActToSeqHash.m_Buckets);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005A8B90
// Name: public: virtual void CDmeMaterialOverlayFXClip::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::Resolve(CDmeMaterialOverlayFXClip *this)
{
  const char *m_pAsString; // eax

  if ( SLOBYTE(this->m_Material.m_pAttribute->m_nFlags) < 0 )
  {
    CMaterialReference::Shutdown(this: &this->m_OverlayMaterial, bDeleteIfUnreferenced: false);
    m_pAsString = this->m_Material.m_Storage.u.m_pAsString;
    if ( m_pAsString != (const char *)-1 && m_pAsString != nullptr && *m_pAsString != 0 )
      CMaterialReference::Init(
        this: &this->m_OverlayMaterial,
        pMaterialName: m_pAsString,
        pTextureGroupName: nullptr,
        bComplain: false);
    this->m_Material.m_pAttribute->m_nFlags &= ~0x80u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005A8BF0
// Name: protected: void CDmeMaterialOverlayFXClip::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::OnConstruction(CDmeMaterialOverlayFXClip *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  CDmAttribute *v4; // ecx
  CDmAttribute *v5; // ecx
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  KeyValues *Key; // eax
  Color value; // [esp+Ch] [ebp-8h] BYREF
  bool v10; // [esp+13h] [ebp-1h] BYREF

  this->m_Material.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "material",
                                    type: AT_STRING,
                                    pMemory: &this->m_Material);
  this->m_Color.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "overlaycolor",
                                 type: AT_COLOR,
                                 pMemory: &this->m_Color);
  this->m_nLeft.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "left",
                                 type: AT_INT,
                                 pMemory: &this->m_nLeft);
  this->m_nTop.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "top",
                                type: AT_INT,
                                pMemory: &this->m_nTop);
  this->m_nWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "width",
                                  type: AT_INT,
                                  pMemory: &this->m_nWidth);
  this->m_nHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "height",
                                   type: AT_INT,
                                   pMemory: &this->m_nHeight);
  this->m_bFullScreen.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "fullscreen",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bFullScreen);
  this->m_bUseSubRect.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "useSubRect",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bUseSubRect);
  this->m_flMovementAngle.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "movementAngle",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flMovementAngle);
  this->m_flMovementSpeed.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "movementSpeed",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flMovementSpeed);
  this->m_nSubRectLeft.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "subRectLeft",
                                        type: AT_INT,
                                        pMemory: &this->m_nSubRectLeft);
  this->m_nSubRectTop.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "subRectTop",
                                       type: AT_INT,
                                       pMemory: &this->m_nSubRectTop);
  this->m_nSubRectWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "subRectWidth",
                                         type: AT_INT,
                                         pMemory: &this->m_nSubRectWidth);
  this->m_nSubRectHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "subRectHeight",
                                          type: AT_INT,
                                          pMemory: &this->m_nSubRectHeight);
  m_pAttribute = this->m_Color.m_pAttribute;
  value = (Color)-1;
  CDmAttribute::SetValue<Color>(this: m_pAttribute, &value);
  v3 = this->m_bFullScreen.m_pAttribute;
  v10 = true;
  CDmAttribute::SetValue<bool>(this: v3, value: &v10);
  v4 = this->m_nTop.m_pAttribute;
  value = 0;
  CDmAttribute::SetValue<int>(this: v4, (int *)&value);
  CDmAttribute::SetValue<int>(this: this->m_nLeft.m_pAttribute, value: &this->m_nTop.m_Storage);
  v5 = this->m_nHeight.m_pAttribute;
  value = (Color)1;
  CDmAttribute::SetValue<int>(this: v5, (int *)&value);
  CDmAttribute::SetValue<int>(this: this->m_nWidth.m_pAttribute, value: &this->m_nHeight.m_Storage);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "accumbuff4sample");
  else
    v7 = nullptr;
  KeyValues::SetString(this: v7, keyName: "$INPUT", value: "Effects/FilmScan256");
  Key = KeyValues::FindKey(this: v7, keyName: "proxies", bCreate: true);
  KeyValues::FindKey(this: Key, keyName: "sfm_blt", bCreate: true);
  CMaterialReference::Init(this: &this->m_BltMaterial, pMaterialName: "accumbuff4sample", pVMTKeyValues: v7);
  this->m_BltMaterial.m_pMaterial->Refresh(this: this->m_BltMaterial.m_pMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x005A8E40
// Name: private: void CDmeMaterialOverlayFXClip::DrawQuad(int,int,int,int,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeMaterialOverlayFXClip::DrawQuad(
        CDmeMaterialOverlayFXClip *this@<ecx>,
        int a2@<edi>,
        int x,
        int y,
        int w,
        int h,
        float u0,
        float v0,
        float u1,
        float v1)
{
  IMatRenderContext *v10; // esi
  IMesh *v11; // esi
  float *m_pCurrPosition; // eax
  float *v13; // eax
  float *v14; // eax
  float *v15; // eax
  int v16; // eax
  float *v17; // eax
  float v18; // xmm5_4
  float *v19; // eax
  float *v20; // eax
  float *v21; // eax
  int v22; // eax
  float *v23; // eax
  float v24; // xmm2_4
  float *v25; // eax
  float *v26; // eax
  float *v27; // eax
  int v28; // eax
  float *v29; // eax
  float *v30; // eax
  float *v31; // eax
  float *v32; // eax
  int m_nVertexCount; // eax
  int v34; // ecx
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1ECh] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F0h] [ebp-4h]

  v10 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v10;
  if ( v10 != nullptr )
    v10->BeginRender(this: v10);
  v11 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, int))v10->GetDynamicMesh)(
                   a1: v10,
                   a2: 1,
                   a3: 0,
                   a4: 0,
                   a5: 0,
                   a6: a2);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v11;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_TRIANGLE_STRIP;
  v11->SetPrimitiveType(this: v11, a2: MATERIAL_TRIANGLE_STRIP);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 4, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v11->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 4;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v11, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)x;
  m_pCurrPosition[1] = (float)y;
  m_pCurrPosition[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v13 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u0;
  v13[1] = v0;
  v14 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 0.0;
  v14[1] = 0.0;
  v15 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v15[1] = 0.0;
  v16 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v16;
  if ( v16 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v16;
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  v17 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v17;
  *v17 = (float)x;
  v18 = (float)(h + y);
  v17[1] = v18;
  v17[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v19 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u0;
  v19[1] = v1;
  v20 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 0.0;
  v20[1] = 1.0;
  v21 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v21[1] = 0.0;
  v22 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v22;
  if ( v22 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v22;
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  v23 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v23;
  v24 = (float)(w + x);
  *v23 = v24;
  v23[1] = (float)y;
  v23[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v25 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u1;
  v25[1] = v0;
  v26 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 1.0;
  v26[1] = 0.0;
  v27 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v27[1] = 0.0;
  v28 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v28;
  if ( v28 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v28;
  v29 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v29;
  *v29 = v24;
  v29[1] = v18;
  v29[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v30 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u1;
  v30[1] = v1;
  v31 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 1.0;
  v31[1] = 1.0;
  v32 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v32[1] = 0.0;
  m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  v34 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v34;
  if ( v34 > meshBuilder.m_VertexBuilder.m_nVertexCount )
  {
    m_nVertexCount = v34;
    meshBuilder.m_VertexBuilder.m_nVertexCount = v34;
  }
  meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount *= 2;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  }
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
  v11->Draw_2(this: v11, a2: -1, a3: 0);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x005A9340
// Name: private: void CDmeMaterialOverlayFXClip::DrawOneToOneQuad(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::DrawOneToOneQuad(CDmeMaterialOverlayFXClip *this, int nWidth, int nHeight)
{
  IMatRenderContext *v3; // esi
  IMesh *v4; // esi
  float *m_pCurrPosition; // eax
  float v6; // xmm0_4
  float *v7; // eax
  int v8; // eax
  float *v9; // eax
  float *v10; // eax
  int v11; // eax
  float *v12; // eax
  float *v13; // eax
  float v14; // xmm0_4
  int v15; // eax
  float *v16; // eax
  float *v17; // eax
  int m_nVertexCount; // eax
  int v19; // ecx
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1ECh] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F0h] [ebp-4h]
  float fHeightEpsilon; // [esp+200h] [ebp+Ch]

  v3 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v3;
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  v4 = v3->GetDynamicMesh(this: v3, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v4;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_QUADS;
  fHeightEpsilon = 0.5 / (float)nHeight;
  v4->SetPrimitiveType(this: v4, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v4->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v4, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v6 = 0.5 / (float)nWidth;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = -1.0;
  m_pCurrPosition[1] = 1.0;
  m_pCurrPosition[2] = 0.5;
  v7 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v6;
  v7[1] = fHeightEpsilon;
  v8 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v8;
  if ( v8 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v8;
  v9 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v9;
  *v9 = -1.0;
  v9[1] = -1.0;
  v9[2] = 0.5;
  v10 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v6;
  v10[1] = fHeightEpsilon + 1.0;
  v11 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v11;
  if ( v11 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v11;
  v12 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v12;
  *v12 = 1.0;
  v12[1] = -1.0;
  v12[2] = 0.5;
  v13 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  v14 = v6 + 1.0;
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v14;
  v13[1] = fHeightEpsilon + 1.0;
  v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
  if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
  v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
  *v16 = 1.0;
  v16[1] = 1.0;
  v16[2] = 0.5;
  v17 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v14;
  v17[1] = fHeightEpsilon;
  m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  v19 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v19;
  if ( v19 > meshBuilder.m_VertexBuilder.m_nVertexCount )
  {
    m_nVertexCount = v19;
    meshBuilder.m_VertexBuilder.m_nVertexCount = v19;
  }
  meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount *= 2;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  }
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v4->Draw_2(this: v4, a2: -1, a3: 0);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x005A96B0
// Name: public: virtual void CDmeMaterialOverlayFXClip::ApplyEffect(class DmeTime_t,struct Rect_t __near &,struct Rect_t __near &,class ITexture __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CDmeMaterialOverlayFXClip::ApplyEffect(
        CDmeMaterialOverlayFXClip *this@<ecx>,
        int a2@<edi>,
        DmeTime_t time,
        Rect_t *currentRect,
        int totalRect,
        float pTextures)
{
  int width; // edx
  int v9; // ecx
  Rect_t *v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // edx
  int v17; // eax
  int v18; // edx
  int v19; // eax
  int v20; // eax
  int v21; // edx
  int v22; // eax
  IMaterial *m_pMaterial; // ecx
  int v24; // eax
  bool v25; // zf
  float v26; // xmm5_4
  float v27; // xmm6_4
  float m_Storage; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm3_4
  float v31; // xmm1_4
  double v32; // xmm0_8
  double v33; // xmm0_8
  double v34; // xmm0_8
  float v35; // xmm1_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm3_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  int v42; // eax
  bool v43; // al
  Rect_t *v44; // edi
  long double v46; // [esp+78h] [ebp-50h] OVERLAPPED BYREF
  int g; // [esp+80h] [ebp-48h] BYREF
  float b; // [esp+84h] [ebp-44h] BYREF
  DmeTime_t v1; // [esp+88h] [ebp-40h] BYREF
  float u1; // [esp+8Ch] [ebp-3Ch]
  float dU; // [esp+90h] [ebp-38h]
  float flRadians; // [esp+94h] [ebp-34h]
  int mw; // [esp+98h] [ebp-30h]
  float vMin; // [esp+9Ch] [ebp-2Ch]
  float uMax; // [esp+A0h] [ebp-28h]
  float uMin; // [esp+A4h] [ebp-24h]
  float v57; // [esp+A8h] [ebp-20h]
  float v58; // [esp+ACh] [ebp-1Ch]
  int ty; // [esp+B0h] [ebp-18h]
  int th; // [esp+B4h] [ebp-14h]
  int tx; // [esp+B8h] [ebp-10h]
  int w; // [esp+BCh] [ebp-Ch]
  int h; // [esp+C0h] [ebp-8h]
  int x; // [esp+C4h] [ebp-4h]
  int timea; // [esp+D0h] [ebp+8h]
  int y; // [esp+D4h] [ebp+Ch]
  int ya; // [esp+D4h] [ebp+Ch]

  if ( this->m_OverlayMaterial.m_pMaterial == nullptr
    || this->m_BltMaterial.m_pMaterial == nullptr
    || this->m_Color.m_Storage._color[3] == 0 )
  {
    return;
  }
  timea = CDmeClip::ToChildMediaTime(this, result: &v1, t: time, bClamp: 0)->m_tms;
  width = currentRect->width;
  if ( this->m_bFullScreen.m_Storage )
  {
    v9 = currentRect->y;
    x = currentRect->x;
    h = currentRect->height;
    y = v9;
    v10 = *(Rect_t **)(totalRect + 8);
    w = width;
    v11 = *(_DWORD *)(totalRect + 12);
    ty = 0;
    tx = 0;
    totalRect = (int)v10;
    th = v11;
LABEL_22:
    if ( totalRect != 0 && th != 0 )
    {
      v22 = ((int (__thiscall *)(IMaterial *, int))this->m_OverlayMaterial.m_pMaterial->GetMappingWidth)(
              a1: this->m_OverlayMaterial.m_pMaterial,
              a2);
      m_pMaterial = this->m_OverlayMaterial.m_pMaterial;
      mw = v22;
      v24 = m_pMaterial->GetMappingHeight(this: m_pMaterial);
      v25 = !this->m_bUseSubRect.m_Storage;
      v26 = (float)mw;
      v27 = (float)v24;
      m_Storage = 0.0;
      v29 = (float)mw;
      v30 = 0.0;
      v31 = (float)v24;
      uMin = 0.0;
      u1 = (float)mw;
      uMax = (float)mw;
      vMin = 0.0;
      *(float *)&v1.m_tms = (float)v24;
      *(float *)&mw = (float)v24;
      if ( !v25 )
      {
        m_Storage = (float)this->m_nSubRectLeft.m_Storage;
        v30 = (float)this->m_nSubRectTop.m_Storage;
        v29 = (float)this->m_nSubRectWidth.m_Storage + m_Storage;
        v31 = (float)this->m_nSubRectHeight.m_Storage + v30;
        uMin = m_Storage;
        vMin = v30;
        uMax = v29;
        *(float *)&mw = v31;
      }
      v58 = this->m_flMovementSpeed.m_Storage;
      if ( v58 != 0.0 )
      {
        v32 = this->m_flMovementAngle.m_Storage;
        v57 = (float)timea * 0.000099999997;
        flRadians = v32 * 3.141592653589793 * 0.005555555555555556;
        v33 = flRadians;
        __libm_sse2_cos(x: v46);
        *(float *)&v33 = v33;
        dU = COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&v33 * v58) ^ _mask__NegFloat_) * v57;
        v34 = flRadians;
        __libm_sse2_sin(x: v46);
        v26 = u1;
        v27 = *(float *)&v1.m_tms;
        v35 = v34;
        v36 = (float)(v35 * v58) * v57;
        m_Storage = dU + uMin;
        v29 = dU + uMax;
        v30 = v36 + vMin;
        v31 = v36 + *(float *)&mw;
      }
      v37 = (float)(m_Storage + 0.5) / v26;
      v38 = (float)((float)(v29 - 0.5) / v26) - v37;
      v39 = (float)(v30 + 0.5) / v27;
      v40 = (float)((float)(v31 - 0.5) / v27) - v39;
      flRadians = (float)((float)((x - tx) / totalRect) * v38) + v37;
      u1 = (float)((float)((x + w - tx) / totalRect) * v38) + v37;
      v41 = (float)((float)((y - ty) / th) * v40) + v39;
      v42 = (y + h - ty) / th;
      ya = y - currentRect->y;
      dU = v41;
      x -= currentRect->x;
      *(float *)&v1.m_tms = (float)((float)v42 * v40) + v39;
      CMatRenderContextPtr::CMatRenderContextPtr(this: (CMatRenderContextPtr *)&totalRect, pFrom: materials);
      v43 = this->m_OverlayMaterial.m_pMaterial->NeedsPowerOfTwoFrameBufferTexture(
              this: this->m_OverlayMaterial.m_pMaterial,
              a2: true);
      v44 = (Rect_t *)totalRect;
      if ( v43 )
      {
        (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)totalRect + 36))(
          a1: totalRect,
          a2: this->m_BltMaterial.m_pMaterial,
          a3: *(_DWORD *)LODWORD(pTextures));
        (*(void (__thiscall **)(Rect_t *, ITexture *, _DWORD, _DWORD, int, int))(v44->x + 432))(
          a1: v44,
          a2: *(ITexture **)(LODWORD(pTextures) + 4),
          a3: 0,
          a4: 0,
          a5: w,
          a6: h);
        CDmeMaterialOverlayFXClip::DrawOneToOneQuad(this, nWidth: w, nHeight: h);
        (*(void (__thiscall **)(Rect_t *))(v44->x + 444))(a1: v44);
        (*(void (__thiscall **)(Rect_t *, ITexture *, _DWORD))(v44->x + 72))(
          a1: v44,
          a2: *(ITexture **)(LODWORD(pTextures) + 4),
          a3: 0);
        (*(void (__thiscall **)(Rect_t *, _DWORD, _DWORD, _DWORD, int, int))(v44->x + 432))(
          a1: v44,
          a2: *(_DWORD *)LODWORD(pTextures),
          a3: 0,
          a4: 0,
          a5: w,
          a6: h);
      }
      this->m_OverlayMaterial.m_pMaterial->GetColorModulation(
        this: this->m_OverlayMaterial.m_pMaterial,
        a2: (float *)((char *)&v46 + 4),
        a3: (float *)&g,
        a4: &b);
      pTextures = this->m_OverlayMaterial.m_pMaterial->GetAlphaModulation(this: this->m_OverlayMaterial.m_pMaterial);
      ((void (__thiscall *)(IMaterial *, _DWORD, _DWORD, _DWORD))this->m_OverlayMaterial.m_pMaterial->ColorModulate)(
        a1: this->m_OverlayMaterial.m_pMaterial,
        a2: (float)this->m_Color.m_Storage._color[0] * 0.0039215689,
        a3: (float)this->m_Color.m_Storage._color[1] * 0.0039215689,
        a4: (float)this->m_Color.m_Storage._color[2] * 0.0039215689);
      ((void (__stdcall *)(_DWORD))this->m_OverlayMaterial.m_pMaterial->AlphaModulate)(a1: (float)this->m_Color.m_Storage._color[3] * 0.0039215689);
      (*(void (__thiscall **)(Rect_t *, IMaterial *, _DWORD))(v44->x + 36))(
        a1: v44,
        a2: this->m_OverlayMaterial.m_pMaterial,
        a3: 0);
      CDmeMaterialOverlayFXClip::DrawQuad(
        this,
        a2: (int)v44,
        x,
        y: ya,
        w,
        h,
        u0: flRadians,
        v0: dU,
        u1,
        v1: *(float *)&v1.m_tms);
      if ( this->m_OverlayMaterial.m_pMaterial->NeedsPowerOfTwoFrameBufferTexture(
             this: this->m_OverlayMaterial.m_pMaterial,
             a2: true) )
      {
        (*(void (__thiscall **)(Rect_t *))(v44->x + 444))(a1: v44);
      }
      ((void (__thiscall *)(IMaterial *, _DWORD, int))this->m_OverlayMaterial.m_pMaterial->ColorModulate)(
        a1: this->m_OverlayMaterial.m_pMaterial,
        a2: HIDWORD(v46),
        a3: g);
      ((void (__stdcall *)(_DWORD))this->m_OverlayMaterial.m_pMaterial->AlphaModulate)(a1: LODWORD(pTextures));
      CMatRenderContextPtr::~CMatRenderContextPtr(this: (CMatRenderContextPtr *)&totalRect);
    }
    return;
  }
  v12 = currentRect->x;
  v13 = this->m_nLeft.m_Storage;
  v14 = currentRect->x + width;
  mw = v14;
  if ( v13 >= v12 )
  {
    x = v14;
    if ( v13 <= v14 )
      x = v13;
  }
  else
  {
    x = v12;
  }
  v15 = currentRect->y;
  totalRect = v15 + currentRect->height;
  v16 = this->m_nTop.m_Storage;
  if ( v16 >= v15 )
  {
    y = totalRect;
    if ( v16 <= totalRect )
      y = this->m_nTop.m_Storage;
  }
  else
  {
    y = v15;
  }
  v17 = this->m_nLeft.m_Storage + this->m_nWidth.m_Storage;
  if ( v17 >= v12 )
  {
    v12 = mw;
    if ( v17 <= mw )
      v12 = this->m_nLeft.m_Storage + this->m_nWidth.m_Storage;
  }
  v18 = this->m_nHeight.m_Storage + v16;
  v19 = currentRect->y;
  if ( v18 >= v19 )
  {
    v19 = totalRect;
    if ( v18 <= totalRect )
      v19 = v18;
  }
  v20 = v19 - y;
  tx = this->m_nLeft.m_Storage;
  ty = this->m_nTop.m_Storage;
  totalRect = this->m_nWidth.m_Storage;
  v21 = this->m_nHeight.m_Storage;
  w = v12 - x;
  h = v20;
  th = v21;
  if ( v12 - x > 0 && v20 > 0 )
    goto LABEL_22;
}

//------------------------------------------------------------------------------
// Address: 0x005A9CD0
// Name: protected: CDmeMaterialOverlayFXClip::CDmeMaterialOverlayFXClip(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMaterialOverlayFXClip *__thiscall CDmeMaterialOverlayFXClip::CDmeMaterialOverlayFXClip(
        CDmeMaterialOverlayFXClip *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeMaterialOverlayFXClip_vtbl *)&CDmeClip::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_TrackGroups);
  this->m_TimeFrame.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_TimeFrame.m_pAttribute = nullptr;
  this->m_TimeFrame.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_ClipColor.m_pAttribute = nullptr;
  this->m_ClipColor.m_Storage = (Color)-16777216;
  this->m_bMute.m_pAttribute = nullptr;
  this->m_bMute.m_Storage = false;
  this->m_flDisplayScale = 0;
  this->m_ClipText.m_pAttribute = nullptr;
  this->m_ClipText.m_Storage.u.CDmeFXClip::CDmeClip::m_Id = -1;
  this->__vftable = (CDmeMaterialOverlayFXClip_vtbl *)&CDmeMaterialOverlayFXClip::`vftable';
  this->m_Material.m_pAttribute = nullptr;
  this->m_Material.m_Storage.u.m_Id = -1;
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_nLeft.m_pAttribute = nullptr;
  this->m_nLeft.m_Storage = 0;
  this->m_nTop.m_pAttribute = nullptr;
  this->m_nTop.m_Storage = 0;
  this->m_nWidth.m_pAttribute = nullptr;
  this->m_nWidth.m_Storage = 0;
  this->m_nHeight.m_pAttribute = nullptr;
  this->m_nHeight.m_Storage = 0;
  this->m_bFullScreen.m_pAttribute = nullptr;
  this->m_bFullScreen.m_Storage = false;
  this->m_bUseSubRect.m_pAttribute = nullptr;
  this->m_bUseSubRect.m_Storage = false;
  this->m_nSubRectLeft.m_pAttribute = nullptr;
  this->m_nSubRectLeft.m_Storage = 0;
  this->m_nSubRectTop.m_pAttribute = nullptr;
  this->m_nSubRectTop.m_Storage = 0;
  this->m_nSubRectWidth.m_pAttribute = nullptr;
  this->m_nSubRectWidth.m_Storage = 0;
  this->m_nSubRectHeight.m_pAttribute = nullptr;
  this->m_nSubRectHeight.m_Storage = 0;
  this->m_flMovementAngle = 0;
  this->m_flMovementSpeed = 0;
  CMaterialReference::CMaterialReference(
    this: &this->m_OverlayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_BltMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005A9E20
// Name: public: virtual bool CDmeMaterialOverlayFXClip::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMaterialOverlayFXClip::IsA(CDmeMaterialOverlayFXClip *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMaterialOverlayFXClip::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFXClip::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeClip::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A9E60
// Name: public: virtual int CDmeMaterialOverlayFXClip::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialOverlayFXClip::GetInheritanceDepth(
        CDmeMaterialOverlayFXClip *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMaterialOverlayFXClip::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFXClip::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeClip::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A9EC0
// Name: protected: virtual void CDmeMaterialOverlayFXClip::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::PerformDestruction(CDmeMaterialOverlayFXClip *this)
{
  CMaterialReference::Shutdown(this: &this->m_BltMaterial, bDeleteIfUnreferenced: false);
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x005A9EF0
// Name: protected: virtual int CDmeMaterialOverlayFXClip::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialOverlayFXClip::AllocatedSize(CDmeMaterialOverlayFXClip *this)
{
  return 260;
}

//------------------------------------------------------------------------------
// Address: 0x005A9F00
// Name: protected: virtual void CDmeMaterialOverlayFXClip::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::PerformConstruction(CDmeMaterialOverlayFXClip *this)
{
  CDmeFXClip::OnDestruction();
  CDmeClip::OnConstruction(this);
  CDmeFXClip::OnDestruction();
  CDmeMaterialOverlayFXClip::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005EAE90
// Name: _dynamic_initializer_for__CDmeMaterialOverlayFXClip::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMaterialOverlayFXClip::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMaterialOverlayFXClip::s_Allocator,
    blockSize: 260,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMaterialOverlayFXClip pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EDAB0
// Name: _dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMaterialOverlayFXClip::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EAEC0
// Name: _dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Factory__()
{
  CDmeFXClip::InstallFXClipType(pElementType: "DmeMaterialOverlayFXClip", pDescription: "Material Overlay Effect");
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EAEE0
// Name: _dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMaterialOverlayFXClip_Helper,
           classname: "DmeMaterialOverlayFXClip",
           pFactory: &g_CDmeMaterialOverlayFXClip_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EDAC0
// Name: _dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMaterialOverlayFXClip_Factory.m_CallBackList);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x0053A800
// Name: public: virtual void CDmeMaterialOverlayFXClip::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::Resolve(CDmeMaterialOverlayFXClip *this)
{
  const char *m_pAsString; // eax

  if ( SLOBYTE(this->m_Material.m_pAttribute->m_nFlags) < 0 )
  {
    CMaterialReference::Shutdown(this: &this->m_OverlayMaterial, bDeleteIfUnreferenced: false);
    m_pAsString = this->m_Material.m_Storage.u.m_pAsString;
    if ( m_pAsString != (const char *)-1 && m_pAsString != nullptr && *m_pAsString != 0 )
      CMaterialReference::Init(
        this: &this->m_OverlayMaterial,
        pMaterialName: m_pAsString,
        pTextureGroupName: nullptr,
        bComplain: false);
    this->m_Material.m_pAttribute->m_nFlags &= ~0x80u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053A860
// Name: protected: void CDmeMaterialOverlayFXClip::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::OnConstruction(CDmeMaterialOverlayFXClip *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  CDmAttribute *v4; // ecx
  CDmAttribute *v5; // ecx
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  KeyValues *Key; // eax
  Color value; // [esp+Ch] [ebp-8h] BYREF
  bool v10; // [esp+13h] [ebp-1h] BYREF

  this->m_Material.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "material",
                                    type: AT_STRING,
                                    pMemory: &this->m_Material);
  this->m_Color.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "overlaycolor",
                                 type: AT_COLOR,
                                 pMemory: &this->m_Color);
  this->m_nLeft.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "left",
                                 type: AT_INT,
                                 pMemory: &this->m_nLeft);
  this->m_nTop.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "top",
                                type: AT_INT,
                                pMemory: &this->m_nTop);
  this->m_nWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "width",
                                  type: AT_INT,
                                  pMemory: &this->m_nWidth);
  this->m_nHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "height",
                                   type: AT_INT,
                                   pMemory: &this->m_nHeight);
  this->m_bFullScreen.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "fullscreen",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bFullScreen);
  this->m_bUseSubRect.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "useSubRect",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bUseSubRect);
  this->m_flMovementAngle.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "movementAngle",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flMovementAngle);
  this->m_flMovementSpeed.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "movementSpeed",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flMovementSpeed);
  this->m_nSubRectLeft.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "subRectLeft",
                                        type: AT_INT,
                                        pMemory: &this->m_nSubRectLeft);
  this->m_nSubRectTop.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "subRectTop",
                                       type: AT_INT,
                                       pMemory: &this->m_nSubRectTop);
  this->m_nSubRectWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "subRectWidth",
                                         type: AT_INT,
                                         pMemory: &this->m_nSubRectWidth);
  this->m_nSubRectHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "subRectHeight",
                                          type: AT_INT,
                                          pMemory: &this->m_nSubRectHeight);
  m_pAttribute = this->m_Color.m_pAttribute;
  value = (Color)-1;
  CDmAttribute::SetValue<Color>(this: m_pAttribute, &value);
  v3 = this->m_bFullScreen.m_pAttribute;
  v10 = true;
  CDmAttribute::SetValue<bool>(this: v3, value: &v10);
  v4 = this->m_nTop.m_pAttribute;
  value = 0;
  CDmAttribute::SetValue<int>(this: v4, (const int *)&value);
  CDmAttribute::SetValue<int>(this: this->m_nLeft.m_pAttribute, value: &this->m_nTop.m_Storage);
  v5 = this->m_nHeight.m_pAttribute;
  value = (Color)1;
  CDmAttribute::SetValue<int>(this: v5, (const int *)&value);
  CDmAttribute::SetValue<int>(this: this->m_nWidth.m_pAttribute, value: &this->m_nHeight.m_Storage);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "accumbuff4sample");
  else
    v7 = nullptr;
  KeyValues::SetString(this: v7, keyName: "$INPUT", value: "Effects/FilmScan256");
  Key = KeyValues::FindKey(this: v7, keyName: "proxies", bCreate: true);
  KeyValues::FindKey(this: Key, keyName: "sfm_blt", bCreate: true);
  CMaterialReference::Init(this: &this->m_BltMaterial, pMaterialName: "accumbuff4sample", pVMTKeyValues: v7);
  this->m_BltMaterial.m_pMaterial->Refresh(this: this->m_BltMaterial.m_pMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x0053AAB0
// Name: private: void CDmeMaterialOverlayFXClip::DrawQuad(int,int,int,int,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeMaterialOverlayFXClip::DrawQuad(
        CDmeMaterialOverlayFXClip *this@<ecx>,
        int a2@<edi>,
        int x,
        int y,
        int w,
        int h,
        float u0,
        float v0,
        float u1,
        float v1)
{
  IMatRenderContext *v10; // esi
  IMesh *v11; // esi
  float *m_pCurrPosition; // eax
  float *v13; // eax
  float *v14; // eax
  float *v15; // eax
  int v16; // eax
  float *v17; // eax
  float v18; // xmm5_4
  float *v19; // eax
  float *v20; // eax
  float *v21; // eax
  int v22; // eax
  float *v23; // eax
  float v24; // xmm2_4
  float *v25; // eax
  float *v26; // eax
  float *v27; // eax
  int v28; // eax
  float *v29; // eax
  float *v30; // eax
  float *v31; // eax
  float *v32; // eax
  int m_nVertexCount; // eax
  int v34; // ecx
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1ECh] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F0h] [ebp-4h]

  v10 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v10;
  if ( v10 != nullptr )
    v10->BeginRender(this: v10);
  v11 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, int))v10->GetDynamicMesh)(
                   a1: v10,
                   a2: 1,
                   a3: 0,
                   a4: 0,
                   a5: 0,
                   a6: a2);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v11;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_TRIANGLE_STRIP;
  v11->SetPrimitiveType(this: v11, a2: MATERIAL_TRIANGLE_STRIP);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 4, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v11->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 4;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v11, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)x;
  m_pCurrPosition[1] = (float)y;
  m_pCurrPosition[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v13 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u0;
  v13[1] = v0;
  v14 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 0.0;
  v14[1] = 0.0;
  v15 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v15[1] = 0.0;
  v16 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v16;
  if ( v16 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v16;
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  v17 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v17;
  *v17 = (float)x;
  v18 = (float)(h + y);
  v17[1] = v18;
  v17[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v19 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u0;
  v19[1] = v1;
  v20 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 0.0;
  v20[1] = 1.0;
  v21 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v21[1] = 0.0;
  v22 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v22;
  if ( v22 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v22;
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  v23 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v23;
  v24 = (float)(w + x);
  *v23 = v24;
  v23[1] = (float)y;
  v23[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v25 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u1;
  v25[1] = v0;
  v26 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 1.0;
  v26[1] = 0.0;
  v27 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v27[1] = 0.0;
  v28 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v28;
  if ( v28 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v28;
  v29 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v29;
  *v29 = v24;
  v29[1] = v18;
  v29[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v30 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u1;
  v30[1] = v1;
  v31 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 1.0;
  v31[1] = 1.0;
  v32 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v32[1] = 0.0;
  m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  v34 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v34;
  if ( v34 > meshBuilder.m_VertexBuilder.m_nVertexCount )
  {
    m_nVertexCount = v34;
    meshBuilder.m_VertexBuilder.m_nVertexCount = v34;
  }
  meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount *= 2;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  }
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
  v11->Draw_2(this: v11, a2: -1, a3: 0);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x0053AFB0
// Name: private: void CDmeMaterialOverlayFXClip::DrawOneToOneQuad(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::DrawOneToOneQuad(CDmeMaterialOverlayFXClip *this, int nWidth, int nHeight)
{
  IMatRenderContext *v3; // esi
  IMesh *v4; // esi
  float *m_pCurrPosition; // eax
  float v6; // xmm0_4
  float *v7; // eax
  int v8; // eax
  float *v9; // eax
  float *v10; // eax
  int v11; // eax
  float *v12; // eax
  float *v13; // eax
  float v14; // xmm0_4
  int v15; // eax
  float *v16; // eax
  float *v17; // eax
  int m_nVertexCount; // eax
  int v19; // ecx
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1ECh] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F0h] [ebp-4h]
  float fHeightEpsilon; // [esp+200h] [ebp+Ch]

  v3 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v3;
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  v4 = v3->GetDynamicMesh(this: v3, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v4;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_QUADS;
  fHeightEpsilon = 0.5 / (float)nHeight;
  v4->SetPrimitiveType(this: v4, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v4->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v4, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v6 = 0.5 / (float)nWidth;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = -1.0;
  m_pCurrPosition[1] = 1.0;
  m_pCurrPosition[2] = 0.5;
  v7 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v6;
  v7[1] = fHeightEpsilon;
  v8 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v8;
  if ( v8 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v8;
  v9 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v9;
  *v9 = -1.0;
  v9[1] = -1.0;
  v9[2] = 0.5;
  v10 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v6;
  v10[1] = fHeightEpsilon + 1.0;
  v11 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v11;
  if ( v11 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v11;
  v12 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v12;
  *v12 = 1.0;
  v12[1] = -1.0;
  v12[2] = 0.5;
  v13 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  v14 = v6 + 1.0;
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v14;
  v13[1] = fHeightEpsilon + 1.0;
  v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
  if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
  v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
  *v16 = 1.0;
  v16[1] = 1.0;
  v16[2] = 0.5;
  v17 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v14;
  v17[1] = fHeightEpsilon;
  m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  v19 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v19;
  if ( v19 > meshBuilder.m_VertexBuilder.m_nVertexCount )
  {
    m_nVertexCount = v19;
    meshBuilder.m_VertexBuilder.m_nVertexCount = v19;
  }
  meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount *= 2;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  }
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v4->Draw_2(this: v4, a2: -1, a3: 0);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x0053B320
// Name: public: virtual void CDmeMaterialOverlayFXClip::ApplyEffect(class DmeTime_t,struct Rect_t __near &,struct Rect_t __near &,class ITexture __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeMaterialOverlayFXClip::ApplyEffect(
        CDmeMaterialOverlayFXClip *this@<ecx>,
        int a2@<edi>,
        DmeTime_t time,
        Rect_t *currentRect,
        int totalRect,
        float pTextures)
{
  int width; // edx
  int v9; // ecx
  Rect_t *v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // edx
  int v17; // eax
  int v18; // edx
  int v19; // eax
  int v20; // eax
  int v21; // edx
  int v22; // eax
  IMaterial *m_pMaterial; // ecx
  int v24; // eax
  bool v25; // zf
  float v26; // xmm5_4
  float v27; // xmm6_4
  float m_Storage; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm3_4
  float v31; // xmm1_4
  __m128d v32; // xmm0
  __m128 v33; // xmm1
  double v34; // xmm0_8
  double v35; // xmm0_8
  float v36; // xmm2_4
  float v37; // xmm0_4
  float v38; // xmm3_4
  float v39; // xmm1_4
  float v40; // xmm0_4
  int v41; // eax
  bool v42; // al
  Rect_t *v43; // edi
  int r; // [esp+7Ch] [ebp-4Ch] BYREF
  int g; // [esp+80h] [ebp-48h] BYREF
  float b; // [esp+84h] [ebp-44h] BYREF
  DmeTime_t v1; // [esp+88h] [ebp-40h] BYREF
  float u1; // [esp+8Ch] [ebp-3Ch]
  float dU; // [esp+90h] [ebp-38h]
  float flRadians; // [esp+94h] [ebp-34h]
  int mw; // [esp+98h] [ebp-30h]
  float vMin; // [esp+9Ch] [ebp-2Ch]
  float uMax; // [esp+A0h] [ebp-28h]
  float uMin; // [esp+A4h] [ebp-24h]
  float v56; // [esp+A8h] [ebp-20h]
  float v57; // [esp+ACh] [ebp-1Ch]
  int ty; // [esp+B0h] [ebp-18h]
  int th; // [esp+B4h] [ebp-14h]
  int tx; // [esp+B8h] [ebp-10h]
  int w; // [esp+BCh] [ebp-Ch]
  int h; // [esp+C0h] [ebp-8h]
  int x; // [esp+C4h] [ebp-4h]
  int timea; // [esp+D0h] [ebp+8h]
  int y; // [esp+D4h] [ebp+Ch]
  int ya; // [esp+D4h] [ebp+Ch]

  if ( this->m_OverlayMaterial.m_pMaterial == nullptr
    || this->m_BltMaterial.m_pMaterial == nullptr
    || this->m_Color.m_Storage._color[3] == 0 )
  {
    return;
  }
  timea = CDmeClip::ToChildMediaTime(this, result: &v1, t: time, bClamp: 0)->m_tms;
  width = currentRect->width;
  if ( this->m_bFullScreen.m_Storage )
  {
    v9 = currentRect->y;
    x = currentRect->x;
    h = currentRect->height;
    y = v9;
    v10 = *(Rect_t **)(totalRect + 8);
    w = width;
    v11 = *(_DWORD *)(totalRect + 12);
    ty = 0;
    tx = 0;
    totalRect = (int)v10;
    th = v11;
LABEL_22:
    if ( totalRect != 0 && th != 0 )
    {
      v22 = ((int (__thiscall *)(IMaterial *, int))this->m_OverlayMaterial.m_pMaterial->GetMappingWidth)(
              a1: this->m_OverlayMaterial.m_pMaterial,
              a2);
      m_pMaterial = this->m_OverlayMaterial.m_pMaterial;
      mw = v22;
      v24 = m_pMaterial->GetMappingHeight(this: m_pMaterial);
      v25 = !this->m_bUseSubRect.m_Storage;
      v26 = (float)mw;
      v27 = (float)v24;
      m_Storage = 0.0;
      v29 = (float)mw;
      v30 = 0.0;
      v31 = (float)v24;
      uMin = 0.0;
      u1 = (float)mw;
      uMax = (float)mw;
      vMin = 0.0;
      *(float *)&v1.m_tms = (float)v24;
      *(float *)&mw = (float)v24;
      if ( !v25 )
      {
        m_Storage = (float)this->m_nSubRectLeft.m_Storage;
        v30 = (float)this->m_nSubRectTop.m_Storage;
        v29 = (float)this->m_nSubRectWidth.m_Storage + m_Storage;
        v31 = (float)this->m_nSubRectHeight.m_Storage + v30;
        uMin = m_Storage;
        vMin = v30;
        uMax = v29;
        *(float *)&mw = v31;
      }
      v57 = this->m_flMovementSpeed.m_Storage;
      if ( v57 != 0.0 )
      {
        v32 = _mm_cvtps_pd((__m128)LODWORD(this->m_flMovementAngle.m_Storage));
        v32.m128d_f64[0] = v32.m128d_f64[0] * 3.141592653589793 * 0.005555555555555556;
        v33 = _mm_cvtpd_ps(v32);
        v56 = (float)timea * 0.000099999997;
        flRadians = v33.m128_f32[0];
        __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd(v33));
        *(float *)&v34 = v34;
        dU = COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&v34 * v57) ^ _mask__NegFloat_) * v56;
        __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(flRadians)));
        v26 = u1;
        v27 = *(float *)&v1.m_tms;
        v33.m128_f32[0] = v35;
        v33.m128_f32[0] = (float)(v33.m128_f32[0] * v57) * v56;
        m_Storage = dU + uMin;
        v29 = dU + uMax;
        v30 = v33.m128_f32[0] + vMin;
        v31 = v33.m128_f32[0] + *(float *)&mw;
      }
      v36 = (float)(m_Storage + 0.5) / v26;
      v37 = (float)((float)(v29 - 0.5) / v26) - v36;
      v38 = (float)(v30 + 0.5) / v27;
      v39 = (float)((float)(v31 - 0.5) / v27) - v38;
      flRadians = (float)((float)((x - tx) / totalRect) * v37) + v36;
      u1 = (float)((float)((x + w - tx) / totalRect) * v37) + v36;
      v40 = (float)((float)((y - ty) / th) * v39) + v38;
      v41 = (y + h - ty) / th;
      ya = y - currentRect->y;
      dU = v40;
      x -= currentRect->x;
      *(float *)&v1.m_tms = (float)((float)v41 * v39) + v38;
      CMatRenderContextPtr::CMatRenderContextPtr(this: (CMatRenderContextPtr *)&totalRect, pFrom: materials);
      v42 = this->m_OverlayMaterial.m_pMaterial->NeedsPowerOfTwoFrameBufferTexture(
              this: this->m_OverlayMaterial.m_pMaterial,
              a2: true);
      v43 = (Rect_t *)totalRect;
      if ( v42 )
      {
        (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)totalRect + 36))(
          a1: totalRect,
          a2: this->m_BltMaterial.m_pMaterial,
          a3: *(_DWORD *)LODWORD(pTextures));
        (*(void (__thiscall **)(Rect_t *, ITexture *, _DWORD, _DWORD, int, int))(v43->x + 432))(
          a1: v43,
          a2: *(ITexture **)(LODWORD(pTextures) + 4),
          a3: 0,
          a4: 0,
          a5: w,
          a6: h);
        CDmeMaterialOverlayFXClip::DrawOneToOneQuad(this, nWidth: w, nHeight: h);
        (*(void (__thiscall **)(Rect_t *))(v43->x + 444))(a1: v43);
        (*(void (__thiscall **)(Rect_t *, ITexture *, _DWORD))(v43->x + 72))(
          a1: v43,
          a2: *(ITexture **)(LODWORD(pTextures) + 4),
          a3: 0);
        (*(void (__thiscall **)(Rect_t *, _DWORD, _DWORD, _DWORD, int, int))(v43->x + 432))(
          a1: v43,
          a2: *(_DWORD *)LODWORD(pTextures),
          a3: 0,
          a4: 0,
          a5: w,
          a6: h);
      }
      this->m_OverlayMaterial.m_pMaterial->GetColorModulation(
        this: this->m_OverlayMaterial.m_pMaterial,
        a2: (float *)&r,
        a3: (float *)&g,
        a4: &b);
      pTextures = this->m_OverlayMaterial.m_pMaterial->GetAlphaModulation(this: this->m_OverlayMaterial.m_pMaterial);
      ((void (__thiscall *)(IMaterial *, _DWORD, _DWORD, _DWORD))this->m_OverlayMaterial.m_pMaterial->ColorModulate)(
        a1: this->m_OverlayMaterial.m_pMaterial,
        a2: (float)this->m_Color.m_Storage._color[0] * 0.0039215689,
        a3: (float)this->m_Color.m_Storage._color[1] * 0.0039215689,
        a4: (float)this->m_Color.m_Storage._color[2] * 0.0039215689);
      ((void (__stdcall *)(_DWORD))this->m_OverlayMaterial.m_pMaterial->AlphaModulate)(a1: (float)this->m_Color.m_Storage._color[3] * 0.0039215689);
      (*(void (__thiscall **)(Rect_t *, IMaterial *, _DWORD))(v43->x + 36))(
        a1: v43,
        a2: this->m_OverlayMaterial.m_pMaterial,
        a3: 0);
      CDmeMaterialOverlayFXClip::DrawQuad(
        this,
        a2: (int)v43,
        x,
        y: ya,
        w,
        h,
        u0: flRadians,
        v0: dU,
        u1,
        v1: *(float *)&v1.m_tms);
      if ( this->m_OverlayMaterial.m_pMaterial->NeedsPowerOfTwoFrameBufferTexture(
             this: this->m_OverlayMaterial.m_pMaterial,
             a2: true) )
      {
        (*(void (__thiscall **)(Rect_t *))(v43->x + 444))(a1: v43);
      }
      ((void (__thiscall *)(IMaterial *, int, int))this->m_OverlayMaterial.m_pMaterial->ColorModulate)(
        a1: this->m_OverlayMaterial.m_pMaterial,
        a2: r,
        a3: g);
      ((void (__stdcall *)(_DWORD))this->m_OverlayMaterial.m_pMaterial->AlphaModulate)(a1: LODWORD(pTextures));
      CMatRenderContextPtr::~CMatRenderContextPtr(this: (CMatRenderContextPtr *)&totalRect);
    }
    return;
  }
  v12 = currentRect->x;
  v13 = this->m_nLeft.m_Storage;
  v14 = currentRect->x + width;
  mw = v14;
  if ( v13 >= v12 )
  {
    x = v14;
    if ( v13 <= v14 )
      x = v13;
  }
  else
  {
    x = v12;
  }
  v15 = currentRect->y;
  totalRect = v15 + currentRect->height;
  v16 = this->m_nTop.m_Storage;
  if ( v16 >= v15 )
  {
    y = totalRect;
    if ( v16 <= totalRect )
      y = this->m_nTop.m_Storage;
  }
  else
  {
    y = v15;
  }
  v17 = this->m_nLeft.m_Storage + this->m_nWidth.m_Storage;
  if ( v17 >= v12 )
  {
    v12 = mw;
    if ( v17 <= mw )
      v12 = this->m_nLeft.m_Storage + this->m_nWidth.m_Storage;
  }
  v18 = this->m_nHeight.m_Storage + v16;
  v19 = currentRect->y;
  if ( v18 >= v19 )
  {
    v19 = totalRect;
    if ( v18 <= totalRect )
      v19 = v18;
  }
  v20 = v19 - y;
  tx = this->m_nLeft.m_Storage;
  ty = this->m_nTop.m_Storage;
  totalRect = this->m_nWidth.m_Storage;
  v21 = this->m_nHeight.m_Storage;
  w = v12 - x;
  h = v20;
  th = v21;
  if ( v12 - x > 0 && v20 > 0 )
    goto LABEL_22;
}

//------------------------------------------------------------------------------
// Address: 0x0053B930
// Name: protected: CDmeMaterialOverlayFXClip::CDmeMaterialOverlayFXClip(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMaterialOverlayFXClip *__thiscall CDmeMaterialOverlayFXClip::CDmeMaterialOverlayFXClip(
        CDmeMaterialOverlayFXClip *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeMaterialOverlayFXClip_vtbl *)&CDmeClip::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_TrackGroups);
  this->m_TimeFrame.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_TimeFrame.m_pAttribute = nullptr;
  this->m_TimeFrame.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_ClipColor.m_pAttribute = nullptr;
  this->m_ClipColor.m_Storage = (Color)-16777216;
  this->m_bMute.m_pAttribute = nullptr;
  this->m_bMute.m_Storage = false;
  this->m_flDisplayScale = 0;
  this->m_ClipText.m_pAttribute = nullptr;
  this->m_ClipText.m_Storage.u.CDmeFXClip::CDmeClip::m_Id = -1;
  this->__vftable = (CDmeMaterialOverlayFXClip_vtbl *)&CDmeMaterialOverlayFXClip::`vftable';
  this->m_Material.m_pAttribute = nullptr;
  this->m_Material.m_Storage.u.m_Id = -1;
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_nLeft.m_pAttribute = nullptr;
  this->m_nLeft.m_Storage = 0;
  this->m_nTop.m_pAttribute = nullptr;
  this->m_nTop.m_Storage = 0;
  this->m_nWidth.m_pAttribute = nullptr;
  this->m_nWidth.m_Storage = 0;
  this->m_nHeight.m_pAttribute = nullptr;
  this->m_nHeight.m_Storage = 0;
  this->m_bFullScreen.m_pAttribute = nullptr;
  this->m_bFullScreen.m_Storage = false;
  this->m_bUseSubRect.m_pAttribute = nullptr;
  this->m_bUseSubRect.m_Storage = false;
  this->m_nSubRectLeft.m_pAttribute = nullptr;
  this->m_nSubRectLeft.m_Storage = 0;
  this->m_nSubRectTop.m_pAttribute = nullptr;
  this->m_nSubRectTop.m_Storage = 0;
  this->m_nSubRectWidth.m_pAttribute = nullptr;
  this->m_nSubRectWidth.m_Storage = 0;
  this->m_nSubRectHeight.m_pAttribute = nullptr;
  this->m_nSubRectHeight.m_Storage = 0;
  this->m_flMovementAngle = 0;
  this->m_flMovementSpeed = 0;
  CMaterialReference::CMaterialReference(
    this: &this->m_OverlayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_BltMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0053BA80
// Name: public: virtual bool CDmeMaterialOverlayFXClip::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMaterialOverlayFXClip::IsA(CDmeMaterialOverlayFXClip *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMaterialOverlayFXClip::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFXClip::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeClip::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0053BAC0
// Name: public: virtual int CDmeMaterialOverlayFXClip::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialOverlayFXClip::GetInheritanceDepth(
        CDmeMaterialOverlayFXClip *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMaterialOverlayFXClip::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFXClip::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeClip::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0053BB20
// Name: protected: virtual void CDmeMaterialOverlayFXClip::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::PerformDestruction(CDmeMaterialOverlayFXClip *this)
{
  CMaterialReference::Shutdown(this: &this->m_BltMaterial, bDeleteIfUnreferenced: false);
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
}

//------------------------------------------------------------------------------
// Address: 0x0053BB50
// Name: protected: virtual int CDmeMaterialOverlayFXClip::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialOverlayFXClip::AllocatedSize(CDmeMaterialOverlayFXClip *this)
{
  return 260;
}

//------------------------------------------------------------------------------
// Address: 0x0053BB60
// Name: protected: virtual void CDmeMaterialOverlayFXClip::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::PerformConstruction(CDmeMaterialOverlayFXClip *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeClip::OnConstruction(this);
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeMaterialOverlayFXClip::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057CF20
// Name: _dynamic_initializer_for__CDmeMaterialOverlayFXClip::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMaterialOverlayFXClip::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMaterialOverlayFXClip::s_Allocator,
    blockSize: 260,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMaterialOverlayFXClip pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057EBA0
// Name: _dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMaterialOverlayFXClip::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057CF50
// Name: _dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Factory__()
{
  CDmeFXClip::InstallFXClipType(pElementType: "DmeMaterialOverlayFXClip", pDescription: "Material Overlay Effect");
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CF70
// Name: _dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMaterialOverlayFXClip_Helper,
           classname: "DmeMaterialOverlayFXClip",
           pFactory: &g_CDmeMaterialOverlayFXClip_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057CF90
// Name: _dynamic_initializer_for__mod_load_preload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_preload__()
{
  ConVar::ConVar(
    this: &mod_load_preload,
    pName: "mod_load_preload",
    pDefaultValue: "1.0",
    flags: 0,
    pHelpString: "Indicates how far ahead in seconds to preload animations.");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_preload__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CFC0
// Name: _dynamic_initializer_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_showstall__()
{
  ConVar::ConVar(
    this: &mod_load_showstall,
    pName: "mod_load_showstall",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "1 - show hitches , 2 - show stalls");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_showstall__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CFF0
// Name: _dynamic_initializer_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ActivityModifiersTable, growSize: 0, initSize: 16, caseInsensitive: false);
  return atexit(func: dynamic_atexit_destructor_for__g_ActivityModifiersTable__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D010
// Name: _dynamic_initializer_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall dynamic_initializer_for__emptyMapping__(char a1)
{
  int v2; // [esp-4h] [ebp-Ch] BYREF
  CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs v3; // [esp+0h] [ebp-8h]
  int *v4; // [esp+4h] [ebp-4h]

  v4 = &v2;
  CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>::CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>(
    this: &emptyMapping.m_ActToSeqHash,
    bucketCount: 8,
    growCount: 0,
    initCount: 0,
    compareFunc: (CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs)a1,
    keyFunc: v3);
  emptyMapping.m_pStudioHdr = nullptr;
  emptyMapping.m_expectedVModel = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__emptyMapping__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D060
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMaps__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D070
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMapsLock__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMapsLock__()
{
  g_StudioHdrToActivityMapsLock.m_ownerID = 0;
  g_StudioHdrToActivityMapsLock.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0057EBB0
// Name: _dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMaterialOverlayFXClip_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057EBC0
// Name: _dynamic_atexit_destructor_for__mod_load_preload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_preload__()
{
  ConVar::~ConVar(this: &mod_load_preload);
}

//------------------------------------------------------------------------------
// Address: 0x0057EBD0
// Name: _dynamic_atexit_destructor_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_showstall__()
{
  ConVar::~ConVar(this: &mod_load_showstall);
}

//------------------------------------------------------------------------------
// Address: 0x0057EBE0
// Name: _dynamic_atexit_destructor_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ActivityModifiersTable);
}

//------------------------------------------------------------------------------
// Address: 0x0057EBF0
// Name: _dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__()
{
  CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_StudioHdrToActivityMaps.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x0057EC00
// Name: _dynamic_atexit_destructor_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__emptyMapping__()
{
  CStudioHdr::CActivityToSequenceMapping::SequenceTuple *m_pSequenceTuples; // ecx

  m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
  if ( emptyMapping.m_pSequenceTuples != nullptr )
  {
    if ( emptyMapping.m_pSequenceTuples->pActivityModifiers != nullptr )
    {
      free(pMem: emptyMapping.m_pSequenceTuples->pActivityModifiers);
      m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
    }
    free(pMem: m_pSequenceTuples);
  }
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: &emptyMapping.m_ActToSeqHash);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::~CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>(this: &emptyMapping.m_ActToSeqHash.m_Buckets);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0063D8B0
// Name: public: virtual void CDmeMaterialOverlayFXClip::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::Resolve(CDmeMaterialOverlayFXClip *this)
{
  const char *m_pAsString; // eax

  if ( SLOBYTE(this->m_Material.m_pAttribute->m_nFlags) < 0 )
  {
    CMaterialReference::Shutdown(this: &this->m_OverlayMaterial, bDeleteIfUnreferenced: false);
    m_pAsString = this->m_Material.m_Storage.u.m_pAsString;
    if ( m_pAsString != (const char *)-1 && m_pAsString != nullptr && *m_pAsString != 0 )
      CMaterialReference::Init(
        this: &this->m_OverlayMaterial,
        pMaterialName: m_pAsString,
        pTextureGroupName: nullptr,
        bComplain: false);
    this->m_Material.m_pAttribute->m_nFlags &= ~0x80u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063D910
// Name: protected: void CDmeMaterialOverlayFXClip::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::OnConstruction(CDmeMaterialOverlayFXClip *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  CDmAttribute *v4; // ecx
  CDmAttribute *v5; // ecx
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  KeyValues *Key; // eax
  Color value; // [esp+Ch] [ebp-8h] BYREF
  bool v10; // [esp+13h] [ebp-1h] BYREF

  this->m_Material.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "material",
                                    type: AT_STRING,
                                    pMemory: &this->m_Material);
  this->m_Color.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "overlaycolor",
                                 type: AT_COLOR,
                                 pMemory: &this->m_Color);
  this->m_nLeft.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "left",
                                 type: AT_INT,
                                 pMemory: &this->m_nLeft);
  this->m_nTop.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "top",
                                type: AT_INT,
                                pMemory: &this->m_nTop);
  this->m_nWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "width",
                                  type: AT_INT,
                                  pMemory: &this->m_nWidth);
  this->m_nHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "height",
                                   type: AT_INT,
                                   pMemory: &this->m_nHeight);
  this->m_bFullScreen.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "fullscreen",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bFullScreen);
  this->m_bUseSubRect.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "useSubRect",
                                       type: AT_BOOL,
                                       pMemory: &this->m_bUseSubRect);
  this->m_flMovementAngle.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "movementAngle",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flMovementAngle);
  this->m_flMovementSpeed.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "movementSpeed",
                                           type: AT_FLOAT,
                                           pMemory: &this->m_flMovementSpeed);
  this->m_nSubRectLeft.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "subRectLeft",
                                        type: AT_INT,
                                        pMemory: &this->m_nSubRectLeft);
  this->m_nSubRectTop.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "subRectTop",
                                       type: AT_INT,
                                       pMemory: &this->m_nSubRectTop);
  this->m_nSubRectWidth.m_pAttribute = CDmElement::AddExternalAttribute(
                                         this,
                                         pAttributeName: "subRectWidth",
                                         type: AT_INT,
                                         pMemory: &this->m_nSubRectWidth);
  this->m_nSubRectHeight.m_pAttribute = CDmElement::AddExternalAttribute(
                                          this,
                                          pAttributeName: "subRectHeight",
                                          type: AT_INT,
                                          pMemory: &this->m_nSubRectHeight);
  m_pAttribute = this->m_Color.m_pAttribute;
  value = (Color)-1;
  CDmAttribute::SetValue<Color>(this: m_pAttribute, &value);
  v3 = this->m_bFullScreen.m_pAttribute;
  v10 = true;
  CDmAttribute::SetValue<bool>(this: v3, value: &v10);
  v4 = this->m_nTop.m_pAttribute;
  value = 0;
  CDmAttribute::SetValue<int>(this: v4, (int *)&value);
  CDmAttribute::SetValue<int>(this: this->m_nLeft.m_pAttribute, value: &this->m_nTop.m_Storage);
  v5 = this->m_nHeight.m_pAttribute;
  value = (Color)1;
  CDmAttribute::SetValue<int>(this: v5, (int *)&value);
  CDmAttribute::SetValue<int>(this: this->m_nWidth.m_pAttribute, value: &this->m_nHeight.m_Storage);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "accumbuff4sample");
  else
    v7 = nullptr;
  KeyValues::SetString(this: v7, keyName: "$INPUT", value: "Effects/FilmScan256");
  Key = KeyValues::FindKey(this: v7, keyName: "proxies", bCreate: true);
  KeyValues::FindKey(this: Key, keyName: "sfm_blt", bCreate: true);
  CMaterialReference::Init(this: &this->m_BltMaterial, pMaterialName: "accumbuff4sample", pVMTKeyValues: v7);
  this->m_BltMaterial.m_pMaterial->Refresh(this: this->m_BltMaterial.m_pMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x0063DB60
// Name: private: void CDmeMaterialOverlayFXClip::DrawQuad(int,int,int,int,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeMaterialOverlayFXClip::DrawQuad(
        CDmeMaterialOverlayFXClip *this@<ecx>,
        int a2@<edi>,
        int x,
        int y,
        int w,
        int h,
        float u0,
        float v0,
        float u1,
        float v1)
{
  IMatRenderContext *v10; // esi
  IMesh *v11; // esi
  float *m_pCurrPosition; // eax
  float *v13; // eax
  float *v14; // eax
  float *v15; // eax
  int v16; // eax
  float *v17; // eax
  float v18; // xmm5_4
  float *v19; // eax
  float *v20; // eax
  float *v21; // eax
  int v22; // eax
  float *v23; // eax
  float v24; // xmm2_4
  float *v25; // eax
  float *v26; // eax
  float *v27; // eax
  int v28; // eax
  float *v29; // eax
  float *v30; // eax
  float *v31; // eax
  float *v32; // eax
  int m_nVertexCount; // eax
  int v34; // ecx
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1ECh] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F0h] [ebp-4h]

  v10 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v10;
  if ( v10 != nullptr )
    v10->BeginRender(this: v10);
  v11 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, int))v10->GetDynamicMesh)(
                   a1: v10,
                   a2: 1,
                   a3: 0,
                   a4: 0,
                   a5: 0,
                   a6: a2);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v11;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_TRIANGLE_STRIP;
  v11->SetPrimitiveType(this: v11, a2: MATERIAL_TRIANGLE_STRIP);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 4, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v11->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 4;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v11, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)x;
  m_pCurrPosition[1] = (float)y;
  m_pCurrPosition[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v13 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u0;
  v13[1] = v0;
  v14 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 0.0;
  v14[1] = 0.0;
  v15 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v15[1] = 0.0;
  v16 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v16;
  if ( v16 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v16;
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  v17 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v17;
  *v17 = (float)x;
  v18 = (float)(h + y);
  v17[1] = v18;
  v17[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v19 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u0;
  v19[1] = v1;
  v20 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 0.0;
  v20[1] = 1.0;
  v21 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v21[1] = 0.0;
  v22 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v22;
  if ( v22 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v22;
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  v23 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v23;
  v24 = (float)(w + x);
  *v23 = v24;
  v23[1] = (float)y;
  v23[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v25 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u1;
  v25[1] = v0;
  v26 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 1.0;
  v26[1] = 0.0;
  v27 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v27[1] = 0.0;
  v28 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v28;
  if ( v28 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v28;
  v29 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v29;
  *v29 = v24;
  v29[1] = v18;
  v29[2] = 0.0;
  if ( meshBuilder.m_VertexBuilder.m_NumBoneWeights > 0 )
    *(float *)((char *)meshBuilder.m_VertexBuilder.m_pBoneWeight
             + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight) = 1.0;
  meshBuilder.m_VertexBuilder.m_pBoneMatrixIndex[meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                               * meshBuilder.m_VertexBuilder.m_VertexSize_BoneMatrixIndex] = 0;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -1;
  v30 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = u1;
  v30[1] = v1;
  v31 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = 1.0;
  v31[1] = 1.0;
  v32 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = 0.0;
  v32[1] = 0.0;
  m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  v34 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v34;
  if ( v34 > meshBuilder.m_VertexBuilder.m_nVertexCount )
  {
    m_nVertexCount = v34;
    meshBuilder.m_VertexBuilder.m_nVertexCount = v34;
  }
  meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount *= 2;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  }
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
  v11->Draw_2(this: v11, a2: -1, a3: 0);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x0063E060
// Name: private: void CDmeMaterialOverlayFXClip::DrawOneToOneQuad(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::DrawOneToOneQuad(CDmeMaterialOverlayFXClip *this, int nWidth, int nHeight)
{
  IMatRenderContext *v3; // esi
  IMesh *v4; // esi
  float *m_pCurrPosition; // eax
  float v6; // xmm0_4
  float *v7; // eax
  int v8; // eax
  float *v9; // eax
  float *v10; // eax
  int v11; // eax
  float *v12; // eax
  float *v13; // eax
  float v14; // xmm0_4
  int v15; // eax
  float *v16; // eax
  float *v17; // eax
  int m_nVertexCount; // eax
  int v19; // ecx
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1ECh] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F0h] [ebp-4h]
  float fHeightEpsilon; // [esp+200h] [ebp+Ch]

  v3 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v3;
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  v4 = v3->GetDynamicMesh(this: v3, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v4;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_QUADS;
  fHeightEpsilon = 0.5 / (float)nHeight;
  v4->SetPrimitiveType(this: v4, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v4->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v4, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v6 = 0.5 / (float)nWidth;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = -1.0;
  m_pCurrPosition[1] = 1.0;
  m_pCurrPosition[2] = 0.5;
  v7 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v6;
  v7[1] = fHeightEpsilon;
  v8 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v8;
  if ( v8 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v8;
  v9 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v9;
  *v9 = -1.0;
  v9[1] = -1.0;
  v9[2] = 0.5;
  v10 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v6;
  v10[1] = fHeightEpsilon + 1.0;
  v11 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v11;
  if ( v11 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v11;
  v12 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v12;
  *v12 = 1.0;
  v12[1] = -1.0;
  v12[2] = 0.5;
  v13 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  v14 = v6 + 1.0;
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v14;
  v13[1] = fHeightEpsilon + 1.0;
  v15 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v15;
  if ( v15 > meshBuilder.m_VertexBuilder.m_nVertexCount )
    meshBuilder.m_VertexBuilder.m_nVertexCount = v15;
  v16 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  meshBuilder.m_VertexBuilder.m_pCurrPosition = v16;
  *v16 = 1.0;
  v16[1] = 1.0;
  v16[2] = 0.5;
  v17 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v14;
  v17[1] = fHeightEpsilon;
  m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  v19 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = v19;
  if ( v19 > meshBuilder.m_VertexBuilder.m_nVertexCount )
  {
    m_nVertexCount = v19;
    meshBuilder.m_VertexBuilder.m_nVertexCount = v19;
  }
  meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                        + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
  meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                           + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount *= 2;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  }
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v4->Draw_2(this: v4, a2: -1, a3: 0);
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
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x0063E3D0
// Name: public: virtual void CDmeMaterialOverlayFXClip::ApplyEffect(class DmeTime_t,struct Rect_t __near &,struct Rect_t __near &,class ITexture __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CDmeMaterialOverlayFXClip::ApplyEffect(
        CDmeMaterialOverlayFXClip *this@<ecx>,
        int a2@<edi>,
        DmeTime_t time,
        Rect_t *currentRect,
        int totalRect,
        float pTextures)
{
  int width; // edx
  int v9; // ecx
  Rect_t *v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // edx
  int v17; // eax
  int v18; // edx
  int v19; // eax
  int v20; // eax
  int v21; // edx
  int v22; // eax
  IMaterial *m_pMaterial; // ecx
  int v24; // eax
  bool v25; // zf
  float v26; // xmm5_4
  float v27; // xmm6_4
  float m_Storage; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm3_4
  float v31; // xmm1_4
  double v32; // xmm0_8
  double v33; // xmm0_8
  double v34; // xmm0_8
  float v35; // xmm1_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm3_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  int v42; // eax
  bool v43; // al
  Rect_t *v44; // edi
  long double v46; // [esp+78h] [ebp-50h] OVERLAPPED BYREF
  int g; // [esp+80h] [ebp-48h] BYREF
  float b; // [esp+84h] [ebp-44h] BYREF
  DmeTime_t v1; // [esp+88h] [ebp-40h] BYREF
  float u1; // [esp+8Ch] [ebp-3Ch]
  float dU; // [esp+90h] [ebp-38h]
  float flRadians; // [esp+94h] [ebp-34h]
  int mw; // [esp+98h] [ebp-30h]
  float vMin; // [esp+9Ch] [ebp-2Ch]
  float uMax; // [esp+A0h] [ebp-28h]
  float uMin; // [esp+A4h] [ebp-24h]
  float v57; // [esp+A8h] [ebp-20h]
  float v58; // [esp+ACh] [ebp-1Ch]
  int ty; // [esp+B0h] [ebp-18h]
  int th; // [esp+B4h] [ebp-14h]
  int tx; // [esp+B8h] [ebp-10h]
  int w; // [esp+BCh] [ebp-Ch]
  int h; // [esp+C0h] [ebp-8h]
  int x; // [esp+C4h] [ebp-4h]
  int timea; // [esp+D0h] [ebp+8h]
  int y; // [esp+D4h] [ebp+Ch]
  int ya; // [esp+D4h] [ebp+Ch]

  if ( this->m_OverlayMaterial.m_pMaterial == nullptr
    || this->m_BltMaterial.m_pMaterial == nullptr
    || this->m_Color.m_Storage._color[3] == 0 )
  {
    return;
  }
  timea = CDmeClip::ToChildMediaTime(this, result: &v1, t: time, bClamp: 0)->m_tms;
  width = currentRect->width;
  if ( this->m_bFullScreen.m_Storage )
  {
    v9 = currentRect->y;
    x = currentRect->x;
    h = currentRect->height;
    y = v9;
    v10 = *(Rect_t **)(totalRect + 8);
    w = width;
    v11 = *(_DWORD *)(totalRect + 12);
    ty = 0;
    tx = 0;
    totalRect = (int)v10;
    th = v11;
LABEL_22:
    if ( totalRect != 0 && th != 0 )
    {
      v22 = ((int (__thiscall *)(IMaterial *, int))this->m_OverlayMaterial.m_pMaterial->GetMappingWidth)(
              a1: this->m_OverlayMaterial.m_pMaterial,
              a2);
      m_pMaterial = this->m_OverlayMaterial.m_pMaterial;
      mw = v22;
      v24 = m_pMaterial->GetMappingHeight(this: m_pMaterial);
      v25 = !this->m_bUseSubRect.m_Storage;
      v26 = (float)mw;
      v27 = (float)v24;
      m_Storage = 0.0;
      v29 = (float)mw;
      v30 = 0.0;
      v31 = (float)v24;
      uMin = 0.0;
      u1 = (float)mw;
      uMax = (float)mw;
      vMin = 0.0;
      *(float *)&v1.m_tms = (float)v24;
      *(float *)&mw = (float)v24;
      if ( !v25 )
      {
        m_Storage = (float)this->m_nSubRectLeft.m_Storage;
        v30 = (float)this->m_nSubRectTop.m_Storage;
        v29 = (float)this->m_nSubRectWidth.m_Storage + m_Storage;
        v31 = (float)this->m_nSubRectHeight.m_Storage + v30;
        uMin = m_Storage;
        vMin = v30;
        uMax = v29;
        *(float *)&mw = v31;
      }
      v58 = this->m_flMovementSpeed.m_Storage;
      if ( v58 != 0.0 )
      {
        v32 = this->m_flMovementAngle.m_Storage;
        v57 = (float)timea * 0.000099999997;
        flRadians = v32 * 3.141592653589793 * 0.005555555555555556;
        v33 = flRadians;
        __libm_sse2_cos(x: v46);
        *(float *)&v33 = v33;
        dU = COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&v33 * v58) ^ _mask__NegFloat_) * v57;
        v34 = flRadians;
        __libm_sse2_sin(x: v46);
        v26 = u1;
        v27 = *(float *)&v1.m_tms;
        v35 = v34;
        v36 = (float)(v35 * v58) * v57;
        m_Storage = dU + uMin;
        v29 = dU + uMax;
        v30 = v36 + vMin;
        v31 = v36 + *(float *)&mw;
      }
      v37 = (float)(m_Storage + 0.5) / v26;
      v38 = (float)((float)(v29 - 0.5) / v26) - v37;
      v39 = (float)(v30 + 0.5) / v27;
      v40 = (float)((float)(v31 - 0.5) / v27) - v39;
      flRadians = (float)((float)((x - tx) / totalRect) * v38) + v37;
      u1 = (float)((float)((x + w - tx) / totalRect) * v38) + v37;
      v41 = (float)((float)((y - ty) / th) * v40) + v39;
      v42 = (y + h - ty) / th;
      ya = y - currentRect->y;
      dU = v41;
      x -= currentRect->x;
      *(float *)&v1.m_tms = (float)((float)v42 * v40) + v39;
      CMatRenderContextPtr::CMatRenderContextPtr(this: (CMatRenderContextPtr *)&totalRect, pFrom: materials);
      v43 = this->m_OverlayMaterial.m_pMaterial->NeedsPowerOfTwoFrameBufferTexture(
              this: this->m_OverlayMaterial.m_pMaterial,
              a2: true);
      v44 = (Rect_t *)totalRect;
      if ( v43 )
      {
        (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)totalRect + 36))(
          a1: totalRect,
          a2: this->m_BltMaterial.m_pMaterial,
          a3: *(_DWORD *)LODWORD(pTextures));
        (*(void (__thiscall **)(Rect_t *, ITexture *, _DWORD, _DWORD, int, int))(v44->x + 432))(
          a1: v44,
          a2: *(ITexture **)(LODWORD(pTextures) + 4),
          a3: 0,
          a4: 0,
          a5: w,
          a6: h);
        CDmeMaterialOverlayFXClip::DrawOneToOneQuad(this, nWidth: w, nHeight: h);
        (*(void (__thiscall **)(Rect_t *))(v44->x + 444))(a1: v44);
        (*(void (__thiscall **)(Rect_t *, ITexture *, _DWORD))(v44->x + 72))(
          a1: v44,
          a2: *(ITexture **)(LODWORD(pTextures) + 4),
          a3: 0);
        (*(void (__thiscall **)(Rect_t *, _DWORD, _DWORD, _DWORD, int, int))(v44->x + 432))(
          a1: v44,
          a2: *(_DWORD *)LODWORD(pTextures),
          a3: 0,
          a4: 0,
          a5: w,
          a6: h);
      }
      this->m_OverlayMaterial.m_pMaterial->GetColorModulation(
        this: this->m_OverlayMaterial.m_pMaterial,
        a2: (float *)((char *)&v46 + 4),
        a3: (float *)&g,
        a4: &b);
      pTextures = this->m_OverlayMaterial.m_pMaterial->GetAlphaModulation(this: this->m_OverlayMaterial.m_pMaterial);
      ((void (__thiscall *)(IMaterial *, _DWORD, _DWORD, _DWORD))this->m_OverlayMaterial.m_pMaterial->ColorModulate)(
        a1: this->m_OverlayMaterial.m_pMaterial,
        a2: (float)this->m_Color.m_Storage._color[0] * 0.0039215689,
        a3: (float)this->m_Color.m_Storage._color[1] * 0.0039215689,
        a4: (float)this->m_Color.m_Storage._color[2] * 0.0039215689);
      ((void (__stdcall *)(_DWORD))this->m_OverlayMaterial.m_pMaterial->AlphaModulate)(a1: (float)this->m_Color.m_Storage._color[3] * 0.0039215689);
      (*(void (__thiscall **)(Rect_t *, IMaterial *, _DWORD))(v44->x + 36))(
        a1: v44,
        a2: this->m_OverlayMaterial.m_pMaterial,
        a3: 0);
      CDmeMaterialOverlayFXClip::DrawQuad(
        this,
        a2: (int)v44,
        x,
        y: ya,
        w,
        h,
        u0: flRadians,
        v0: dU,
        u1,
        v1: *(float *)&v1.m_tms);
      if ( this->m_OverlayMaterial.m_pMaterial->NeedsPowerOfTwoFrameBufferTexture(
             this: this->m_OverlayMaterial.m_pMaterial,
             a2: true) )
      {
        (*(void (__thiscall **)(Rect_t *))(v44->x + 444))(a1: v44);
      }
      ((void (__thiscall *)(IMaterial *, _DWORD, int))this->m_OverlayMaterial.m_pMaterial->ColorModulate)(
        a1: this->m_OverlayMaterial.m_pMaterial,
        a2: HIDWORD(v46),
        a3: g);
      ((void (__stdcall *)(_DWORD))this->m_OverlayMaterial.m_pMaterial->AlphaModulate)(a1: LODWORD(pTextures));
      CMatRenderContextPtr::~CMatRenderContextPtr(this: (CMatRenderContextPtr *)&totalRect);
    }
    return;
  }
  v12 = currentRect->x;
  v13 = this->m_nLeft.m_Storage;
  v14 = currentRect->x + width;
  mw = v14;
  if ( v13 >= v12 )
  {
    x = v14;
    if ( v13 <= v14 )
      x = v13;
  }
  else
  {
    x = v12;
  }
  v15 = currentRect->y;
  totalRect = v15 + currentRect->height;
  v16 = this->m_nTop.m_Storage;
  if ( v16 >= v15 )
  {
    y = totalRect;
    if ( v16 <= totalRect )
      y = this->m_nTop.m_Storage;
  }
  else
  {
    y = v15;
  }
  v17 = this->m_nLeft.m_Storage + this->m_nWidth.m_Storage;
  if ( v17 >= v12 )
  {
    v12 = mw;
    if ( v17 <= mw )
      v12 = this->m_nLeft.m_Storage + this->m_nWidth.m_Storage;
  }
  v18 = this->m_nHeight.m_Storage + v16;
  v19 = currentRect->y;
  if ( v18 >= v19 )
  {
    v19 = totalRect;
    if ( v18 <= totalRect )
      v19 = v18;
  }
  v20 = v19 - y;
  tx = this->m_nLeft.m_Storage;
  ty = this->m_nTop.m_Storage;
  totalRect = this->m_nWidth.m_Storage;
  v21 = this->m_nHeight.m_Storage;
  w = v12 - x;
  h = v20;
  th = v21;
  if ( v12 - x > 0 && v20 > 0 )
    goto LABEL_22;
}

//------------------------------------------------------------------------------
// Address: 0x0063E9E0
// Name: protected: CDmeMaterialOverlayFXClip::CDmeMaterialOverlayFXClip(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMaterialOverlayFXClip *__thiscall CDmeMaterialOverlayFXClip::CDmeMaterialOverlayFXClip(
        CDmeMaterialOverlayFXClip *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeMaterialOverlayFXClip_vtbl *)&CDmeClip::`vftable';
  CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::CDmaArrayConstBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>(this: &this->m_TrackGroups);
  this->m_TimeFrame.m_Storage.m_ElementType.u.m_Id = -1;
  this->m_TimeFrame.m_pAttribute = nullptr;
  this->m_TimeFrame.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  this->m_ClipColor.m_pAttribute = nullptr;
  this->m_ClipColor.m_Storage = (Color)-16777216;
  this->m_bMute.m_pAttribute = nullptr;
  this->m_bMute.m_Storage = false;
  this->m_flDisplayScale = 0;
  this->m_ClipText.m_pAttribute = nullptr;
  this->m_ClipText.m_Storage.u.CDmeFXClip::CDmeClip::m_Id = -1;
  this->__vftable = (CDmeMaterialOverlayFXClip_vtbl *)&CDmeMaterialOverlayFXClip::`vftable';
  this->m_Material.m_pAttribute = nullptr;
  this->m_Material.m_Storage.u.m_Id = -1;
  this->m_Color.m_pAttribute = nullptr;
  this->m_Color.m_Storage = (Color)-16777216;
  this->m_nLeft.m_pAttribute = nullptr;
  this->m_nLeft.m_Storage = 0;
  this->m_nTop.m_pAttribute = nullptr;
  this->m_nTop.m_Storage = 0;
  this->m_nWidth.m_pAttribute = nullptr;
  this->m_nWidth.m_Storage = 0;
  this->m_nHeight.m_pAttribute = nullptr;
  this->m_nHeight.m_Storage = 0;
  this->m_bFullScreen.m_pAttribute = nullptr;
  this->m_bFullScreen.m_Storage = false;
  this->m_bUseSubRect.m_pAttribute = nullptr;
  this->m_bUseSubRect.m_Storage = false;
  this->m_nSubRectLeft.m_pAttribute = nullptr;
  this->m_nSubRectLeft.m_Storage = 0;
  this->m_nSubRectTop.m_pAttribute = nullptr;
  this->m_nSubRectTop.m_Storage = 0;
  this->m_nSubRectWidth.m_pAttribute = nullptr;
  this->m_nSubRectWidth.m_Storage = 0;
  this->m_nSubRectHeight.m_pAttribute = nullptr;
  this->m_nSubRectHeight.m_Storage = 0;
  this->m_flMovementAngle = 0;
  this->m_flMovementSpeed = 0;
  CMaterialReference::CMaterialReference(
    this: &this->m_OverlayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_BltMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0063EB30
// Name: public: virtual bool CDmeMaterialOverlayFXClip::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMaterialOverlayFXClip::IsA(CDmeMaterialOverlayFXClip *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMaterialOverlayFXClip::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeFXClip::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeClip::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0063EB70
// Name: public: virtual int CDmeMaterialOverlayFXClip::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialOverlayFXClip::GetInheritanceDepth(
        CDmeMaterialOverlayFXClip *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMaterialOverlayFXClip::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeFXClip::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeClip::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0063EBD0
// Name: protected: virtual void CDmeMaterialOverlayFXClip::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::PerformDestruction(CDmeMaterialOverlayFXClip *this)
{
  CMaterialReference::Shutdown(this: &this->m_BltMaterial, bDeleteIfUnreferenced: false);
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
}

//------------------------------------------------------------------------------
// Address: 0x0063EC00
// Name: protected: virtual int CDmeMaterialOverlayFXClip::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterialOverlayFXClip::AllocatedSize(CDmeMaterialOverlayFXClip *this)
{
  return 260;
}

//------------------------------------------------------------------------------
// Address: 0x0063EC10
// Name: protected: virtual void CDmeMaterialOverlayFXClip::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterialOverlayFXClip::PerformConstruction(CDmeMaterialOverlayFXClip *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeClip::OnConstruction(this);
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeMaterialOverlayFXClip::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006BAE90
// Name: _dynamic_initializer_for__CDmeMaterialOverlayFXClip::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMaterialOverlayFXClip::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMaterialOverlayFXClip::s_Allocator,
    blockSize: 0x104u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMaterialOverlayFXClip pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BD9C0
// Name: _dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMaterialOverlayFXClip::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMaterialOverlayFXClip::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BAEC0
// Name: _dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Factory__()
{
  CDmeFXClip::InstallFXClipType(pElementType: "DmeMaterialOverlayFXClip", pDescription: "Material Overlay Effect");
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BAEE0
// Name: _dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMaterialOverlayFXClip_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMaterialOverlayFXClip_Helper,
           classname: "DmeMaterialOverlayFXClip",
           pFactory: &g_CDmeMaterialOverlayFXClip_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BAF00
// Name: _dynamic_initializer_for__mod_load_preload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_preload__()
{
  ConVar::ConVar(
    this: &mod_load_preload,
    pName: "mod_load_preload",
    pDefaultValue: "1.0",
    flags: 0,
    pHelpString: "Indicates how far ahead in seconds to preload animations.");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_preload__);
}

//------------------------------------------------------------------------------
// Address: 0x006BAF30
// Name: _dynamic_initializer_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_showstall__()
{
  ConVar::ConVar(
    this: &mod_load_showstall,
    pName: "mod_load_showstall",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "1 - show hitches , 2 - show stalls");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_showstall__);
}

//------------------------------------------------------------------------------
// Address: 0x006BAF60
// Name: _dynamic_initializer_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ActivityModifiersTable, growSize: 0, initSize: 16, caseInsensitive: false);
  return atexit(func: dynamic_atexit_destructor_for__g_ActivityModifiersTable__);
}

//------------------------------------------------------------------------------
// Address: 0x006BAF80
// Name: _dynamic_initializer_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall dynamic_initializer_for__emptyMapping__(char a1)
{
  int v2; // [esp-4h] [ebp-Ch] BYREF
  CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs v3; // [esp+0h] [ebp-8h]
  int *v4; // [esp+4h] [ebp-4h]

  v4 = &v2;
  CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>::CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>(
    this: &emptyMapping.m_ActToSeqHash,
    bucketCount: 8,
    growCount: 0,
    initCount: 0,
    compareFunc: (CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs)a1,
    keyFunc: v3);
  emptyMapping.m_pStudioHdr = nullptr;
  emptyMapping.m_expectedVModel = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__emptyMapping__);
}

//------------------------------------------------------------------------------
// Address: 0x006BAFD0
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMaps__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__);
}

//------------------------------------------------------------------------------
// Address: 0x006BAFE0
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMapsLock__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMapsLock__()
{
  g_StudioHdrToActivityMapsLock.m_ownerID = 0;
  g_StudioHdrToActivityMapsLock.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x006BD9D0
// Name: _dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMaterialOverlayFXClip_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeMaterialOverlayFXClip_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BD9E0
// Name: _dynamic_atexit_destructor_for__mod_load_preload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_preload__()
{
  ConVar::~ConVar(this: &mod_load_preload);
}

//------------------------------------------------------------------------------
// Address: 0x006BD9F0
// Name: _dynamic_atexit_destructor_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_showstall__()
{
  ConVar::~ConVar(this: &mod_load_showstall);
}

//------------------------------------------------------------------------------
// Address: 0x006BDA00
// Name: _dynamic_atexit_destructor_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ActivityModifiersTable);
}

//------------------------------------------------------------------------------
// Address: 0x006BDA10
// Name: _dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__()
{
  CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_StudioHdrToActivityMaps.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x006BDA20
// Name: _dynamic_atexit_destructor_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__emptyMapping__()
{
  CStudioHdr::CActivityToSequenceMapping::SequenceTuple *m_pSequenceTuples; // ecx

  m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
  if ( emptyMapping.m_pSequenceTuples != nullptr )
  {
    if ( emptyMapping.m_pSequenceTuples->pActivityModifiers != nullptr )
    {
      free(pMem: emptyMapping.m_pSequenceTuples->pActivityModifiers);
      m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
    }
    free(pMem: m_pSequenceTuples);
  }
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: &emptyMapping.m_ActToSeqHash);
  CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>::~CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>(this: &emptyMapping.m_ActToSeqHash.m_Buckets);
}

} // namespace vmap
