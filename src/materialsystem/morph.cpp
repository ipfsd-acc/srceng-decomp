// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/morph.cpp
// Functions: 64
// ============================================================

#include "materialsystem\morph.h"

//------------------------------------------------------------------------------
// Address: 0x10050690
// Name: public: virtual void CMorph::Init(unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMorph::Init(CMorph *this, unsigned int format, const char *pDebugName)
{
  this->m_Format = format;
}

//------------------------------------------------------------------------------
// Address: 0x100506A0
// Name: public: virtual bool CMorphMgr::ShouldAllocateScratchTextures(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMorphMgr::ShouldAllocateScratchTextures(CMorphMgr *this)
{
  return g_pMaterialSystemHardwareConfig->ActualHasFastVertexTextures(this: g_pMaterialSystemHardwareConfig);
}

//------------------------------------------------------------------------------
// Address: 0x100506B0
// Name: public: virtual void CMorphMgr::AllocateScratchTextures(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMorphMgr::AllocateScratchTextures(CMorphMgr *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  float v4; // xmm0_4
  int v5; // edi
  ITextureInternal *v6; // eax
  float v7; // xmm0_4
  int i; // eax
  ITextureInternal *v9; // eax

  this->m_nAccumulatorWidth = 256;
  this->m_nAccumulatorHeight = 256;
  v4 = sqrt(4.0);
  v5 = (int)v4;
  this->m_nSubrectVerticalCount = (int)v4;
  v6 = (ITextureInternal *)((int (__thiscall *)(ITextureManager *, const char *, int, int, int, int, int, int, _DWORD, _DWORD, int, int))g_pTextureManager->CreateRenderTargetTexture)(
                             a1: g_pTextureManager,
                             a2: "_rt_MorphAccumulator",
                             a3: (int)v4 << 8,
                             a4: (int)v4 << 8,
                             a5: 5,
                             a6: 24,
                             a7: 3,
                             a8: 67240717,
                             a9: 0,
                             a10: 0,
                             a11: a2,
                             a12: a3);
  this->m_pMorphAccumTexture = v6;
  v6->IncrementReferenceCount(this: v6);
  v7 = sqrt(1024.0);
  for ( i = (int)v7; i * i < 1024; ++i )
    ;
  this->m_nWeightHeight = i;
  this->m_nWeightWidth = i;
  this->m_bUsingConstantRegisters = false;
  v9 = (ITextureInternal *)((int (__thiscall *)(ITextureManager *, const char *, int, int, int, int, int, int))g_pTextureManager->CreateRenderTargetTexture)(
                             a1: g_pTextureManager,
                             a2: "_rt_MorphWeight",
                             a3: v5 * i,
                             a4: v5 * i,
                             a5: 5,
                             a6: 24,
                             a7: 3,
                             a8: 131853);
  this->m_pMorphWeightTexture = v9;
  v9->IncrementReferenceCount(this: v9);
}

//------------------------------------------------------------------------------
// Address: 0x10050770
// Name: public: virtual void CMorphMgr::FreeScratchTextures(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMorphMgr::FreeScratchTextures(CMorphMgr *this)
{
  ITextureInternal *m_pMorphAccumTexture; // ecx
  ITextureInternal *m_pMorphWeightTexture; // ecx

  m_pMorphAccumTexture = this->m_pMorphAccumTexture;
  if ( m_pMorphAccumTexture != nullptr )
  {
    m_pMorphAccumTexture->DecrementReferenceCount(this: m_pMorphAccumTexture);
    this->m_pMorphAccumTexture->DeleteIfUnreferenced(this: this->m_pMorphAccumTexture);
    this->m_pMorphAccumTexture = nullptr;
  }
  m_pMorphWeightTexture = this->m_pMorphWeightTexture;
  if ( m_pMorphWeightTexture != nullptr )
  {
    m_pMorphWeightTexture->DecrementReferenceCount(this: m_pMorphWeightTexture);
    this->m_pMorphWeightTexture->DeleteIfUnreferenced(this: this->m_pMorphWeightTexture);
    this->m_pMorphWeightTexture = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100507C0
// Name: public: virtual void CMorphMgr::AllocateMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMorphMgr::AllocateMaterials(CMorphMgr *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IMaterial *v4; // eax
  bool v5; // zf
  KeyValues *v6; // eax
  KeyValues *v7; // esi
  KeyValues *v8; // eax
  KeyValues *v9; // esi

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v3 = nullptr;
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "debugmorphaccumulator");
  KeyValues::SetString(this: v3, keyName: "$basetexture", value: "_rt_MorphAccumulator");
  KeyValues::SetString(this: v3, keyName: "$nocull", value: "1");
  KeyValues::SetString(this: v3, keyName: "$ignorez", value: "1");
  v4 = g_pMaterialSystem->CreateMaterial(this: g_pMaterialSystem, a2: "___visualizeMorphAccum.vmt", a3: v3);
  v5 = !this->m_bUsingConstantRegisters;
  this->m_pVisualizeMorphAccum = v4;
  if ( v5 )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "morphweight");
    else
      v7 = nullptr;
    KeyValues::SetString(this: v7, keyName: "$model", value: "0");
    KeyValues::SetString(this: v7, keyName: "$nocull", value: "1");
    KeyValues::SetString(this: v7, keyName: "$ignorez", value: "1");
    this->m_pRenderMorphWeight = g_pMaterialSystem->CreateMaterial(
                                   this: g_pMaterialSystem,
                                   a2: "___morphweight.vmt",
                                   a3: v7);
    v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v8 != nullptr )
      v9 = KeyValues::KeyValues(this: v8, setName: "debugmorphaccumulator");
    else
      v9 = nullptr;
    KeyValues::SetString(this: v9, keyName: "$basetexture", value: "_rt_MorphWeight");
    KeyValues::SetString(this: v9, keyName: "$nocull", value: "1");
    KeyValues::SetString(this: v9, keyName: "$ignorez", value: "1");
    this->m_pVisualizeMorphWeight = g_pMaterialSystem->CreateMaterial(
                                      this: g_pMaterialSystem,
                                      a2: "___visualizeMorphWeight.vmt",
                                      a3: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10050970
// Name: public: virtual void CMorphMgr::FreeMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMorphMgr::FreeMaterials(CMorphMgr *this)
{
  IMaterial *m_pVisualizeMorphAccum; // ecx
  IMaterial *m_pVisualizeMorphWeight; // ecx
  IMaterial *m_pRenderMorphWeight; // ecx

  m_pVisualizeMorphAccum = this->m_pVisualizeMorphAccum;
  if ( m_pVisualizeMorphAccum != nullptr )
  {
    m_pVisualizeMorphAccum->DecrementReferenceCount(this: m_pVisualizeMorphAccum);
    this->m_pVisualizeMorphAccum->DeleteIfUnreferenced(this: this->m_pVisualizeMorphAccum);
    this->m_pVisualizeMorphAccum = nullptr;
  }
  m_pVisualizeMorphWeight = this->m_pVisualizeMorphWeight;
  if ( m_pVisualizeMorphWeight != nullptr )
  {
    m_pVisualizeMorphWeight->DecrementReferenceCount(this: m_pVisualizeMorphWeight);
    this->m_pVisualizeMorphWeight->DeleteIfUnreferenced(this: this->m_pVisualizeMorphWeight);
    this->m_pVisualizeMorphWeight = nullptr;
  }
  m_pRenderMorphWeight = this->m_pRenderMorphWeight;
  if ( m_pRenderMorphWeight != nullptr )
  {
    m_pRenderMorphWeight->DecrementReferenceCount(this: m_pRenderMorphWeight);
    this->m_pRenderMorphWeight->DeleteIfUnreferenced(this: this->m_pRenderMorphWeight);
    this->m_pRenderMorphWeight = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100509E0
// Name: public: virtual class IMorphMgrRenderContext __near * CMorphMgr::AllocateRenderContext(void)
// Source: json
//------------------------------------------------------------------------------
IMorphMgrRenderContext *__thiscall CMorphMgr::AllocateRenderContext(CMorphMgr *this)
{
  IMorphMgrRenderContext *result; // eax

  result = (IMorphMgrRenderContext *)MemAlloc_Alloc(nSize: 0x14u);
  if ( result == nullptr )
    return nullptr;
  *(_DWORD *)result = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10050A00
// Name: public: virtual void CMorphMgr::FreeRenderContext(class IMorphMgrRenderContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMorphMgr::FreeRenderContext(CMorphMgr *this, IMorphMgrRenderContext *pRenderContext)
{
  free(pMem: pRenderContext);
}

//------------------------------------------------------------------------------
// Address: 0x10050A20
// Name: public: virtual class ITextureInternal __near * CMorphMgr::MorphAccumulator(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMorphMgr::MorphAccumulator()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10050A30
// Name: public: virtual class ITextureInternal __near * CMorphMgr::MorphWeights(void)
// Source: json
//------------------------------------------------------------------------------
ITextureInternal *__thiscall CMorphMgr::MorphWeights(CMorphMgr *this)
{
  return this->m_pMorphWeightTexture;
}

//------------------------------------------------------------------------------
// Address: 0x10050A40
// Name: public: virtual void CMorphMgr::AdvanceFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMorphMgr::AdvanceFrame(CMorphMgr *this)
{
  ++this->m_nFrameCount;
}

//------------------------------------------------------------------------------
// Address: 0x10050A50
// Name: public: int CMorphMgr::GetTotalMemoryUsage(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMorphMgr::GetTotalMemoryUsage(CMorphMgr *this)
{
  int v2; // edi
  ImageFormat v3; // eax
  ITextureInternal *m_pMorphAccumTexture; // ebx
  int v5; // edi
  ImageFormat v6; // eax
  ITextureInternal *m_pMorphWeightTexture; // ebx
  int v9; // [esp+Ch] [ebp-8h]
  int m_nNumBytes; // [esp+10h] [ebp-4h]
  int v11; // [esp+10h] [ebp-4h]

  v2 = 0;
  if ( this->m_pMorphAccumTexture != nullptr )
  {
    v3 = this->m_pMorphAccumTexture->GetImageFormat(this: this->m_pMorphAccumTexture);
    m_nNumBytes = ImageLoader::ImageFormatInfo(fmt: v3)->m_nNumBytes;
    m_pMorphAccumTexture = this->m_pMorphAccumTexture;
    v5 = ((int (*)(void))m_pMorphAccumTexture->GetActualHeight)();
    v2 = m_nNumBytes * m_pMorphAccumTexture->GetActualWidth(this: m_pMorphAccumTexture) * v5;
  }
  if ( this->m_pMorphWeightTexture != nullptr )
  {
    v6 = this->m_pMorphWeightTexture->GetImageFormat(this: this->m_pMorphWeightTexture);
    v9 = ImageLoader::ImageFormatInfo(fmt: v6)->m_nNumBytes;
    m_pMorphWeightTexture = this->m_pMorphWeightTexture;
    v11 = ((int (*)(void))m_pMorphWeightTexture->GetActualHeight)();
    v2 += v9 * m_pMorphWeightTexture->GetActualWidth(this: m_pMorphWeightTexture) * v11;
  }
  return v2 + this->m_nTotalMorphSizeInBytes;
}

//------------------------------------------------------------------------------
// Address: 0x10050AF0
// Name: public: virtual bool CMorphMgr::GetMorphAccumulatorTexCoord(class IMorphMgrRenderContext __near *,class Vector2D __near *,class IMorph __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMorphMgr::GetMorphAccumulatorTexCoord(
        CMorphMgr *this,
        IMorphMgrRenderContext *pRenderContext,
        Vector2D *pTexCoord,
        IMorph *pMorph,
        int nVertex)
{
  int v6; // esi
  IMorph **v7; // ecx
  int v9; // edi
  int v10; // eax
  int m_nSubrectVerticalCount; // ecx
  float v12; // xmm1_4
  int m_nAccumulatorHeight; // edi

  v6 = 0;
  if ( *(_DWORD *)pRenderContext <= 0 )
    goto LABEL_7;
  v7 = (IMorph **)&pRenderContext[4];
  while ( *v7 != pMorph )
  {
    ++v6;
    ++v7;
    if ( v6 >= *(_DWORD *)pRenderContext )
      goto LABEL_7;
  }
  if ( v6 >= 0 )
  {
    v9 = this->m_pMorphAccumTexture->GetActualWidth(this: this->m_pMorphAccumTexture);
    v10 = this->m_pMorphAccumTexture->GetActualHeight(this: this->m_pMorphAccumTexture);
    if ( v9 != 0 && v10 != 0 )
    {
      m_nSubrectVerticalCount = this->m_nSubrectVerticalCount;
      v12 = 1.0 / (float)v9;
      m_nAccumulatorHeight = this->m_nAccumulatorHeight;
      pTexCoord->x = (float)((float)(v6 / m_nSubrectVerticalCount * this->m_nAccumulatorWidth
                                   + 2 * (nVertex / m_nAccumulatorHeight))
                           + 0.5)
                   * v12;
      pTexCoord->y = (float)((float)(nVertex
                                   + v6 % m_nSubrectVerticalCount * m_nAccumulatorHeight
                                   - m_nAccumulatorHeight * (nVertex / m_nAccumulatorHeight))
                           + 0.5)
                   * (float)(1.0 / (float)v10);
      return 1;
    }
    else
    {
      pTexCoord->x = 0.0;
      pTexCoord->y = 0.0;
      return 0;
    }
  }
  else
  {
LABEL_7:
    pTexCoord->x = 0.0;
    pTexCoord->y = 0.0;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10050C00
// Name: protected: static int CUtlSortVector<struct MorphVertexInfo_t,class CVertexMorphDict::CMorphVertexListLess>::CompareHelper(void __near *,struct MorphVertexInfo_t const __near *,struct MorphVertexInfo_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CUtlSortVector<MorphVertexInfo_t,CVertexMorphDict::CMorphVertexListLess>::CompareHelper(
        void *context,
        const MorphVertexInfo_t *lhs,
        const MorphVertexInfo_t *rhs)
{
  if ( lhs->m_nVertexId >= rhs->m_nVertexId )
    return rhs->m_nVertexId < lhs->m_nVertexId;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10050C30
// Name: public: void CMeshBuilder::Begin(class IMesh __near *,enum MaterialPrimitiveType_t,int,int,struct MeshBuffersAllocationSettings_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::Begin(
        CMeshBuilder *this,
        IMesh *pMesh,
        MaterialPrimitiveType_t type,
        int nVertexCount,
        int nIndexCount,
        MeshBuffersAllocationSettings_t *pMeshSettings)
{
  this->m_Type = type;
  this->m_pMesh = pMesh;
  this->m_bGenerateIndices = false;
  pMesh->SetPrimitiveType(this: pMesh, a2: type);
  this->m_pMesh->LockMesh(this: this->m_pMesh, a2: nVertexCount, a3: nIndexCount, a4: this, a5: pMeshSettings);
  this->m_IndexBuilder.m_pIndexBuffer = &pMesh->IIndexBuffer;
  this->m_IndexBuilder.m_nIndexCount = 0;
  this->m_IndexBuilder.m_nMaxIndexCount = nIndexCount;
  this->m_IndexBuilder.m_bModify = false;
  this->m_IndexBuilder.m_nIndexOffset = this->m_nFirstVertex;
  this->m_IndexBuilder.m_pIndices = this->m_pIndices;
  this->m_IndexBuilder.m_nIndexSize = this->m_nIndexSize;
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &this->m_VertexBuilder, pMesh, nMaxVertexCount: nVertexCount, desc: this);
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &this->m_VertexBuilder);
}

//------------------------------------------------------------------------------
// Address: 0x10050CF0
// Name: public: virtual bool CMorph::Bind(class IMorphMgrRenderContext __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMorph::Bind(CMorph *this, IMorphMgrRenderContext *pIRenderContext)
{
  int v2; // esi
  CMorph **i; // edx
  int v5; // edi
  int v6; // ebx
  int m_nAccumulatorWidth; // esi
  int nHeight; // [esp+Ch] [ebp+8h]

  v2 = 0;
  if ( *(_DWORD *)pIRenderContext <= 0 )
    return 0;
  for ( i = (CMorph **)&pIRenderContext[4]; *i != this; ++i )
  {
    if ( ++v2 >= *(_DWORD *)pIRenderContext )
      return 0;
  }
  if ( v2 < 0 )
    return 0;
  v5 = v2 / s_MorphMgr.m_nSubrectVerticalCount * s_MorphMgr.m_nAccumulatorWidth;
  v6 = v2 % s_MorphMgr.m_nSubrectVerticalCount * s_MorphMgr.m_nAccumulatorHeight;
  m_nAccumulatorWidth = s_MorphMgr.m_nAccumulatorWidth;
  nHeight = s_MorphMgr.m_nAccumulatorHeight;
  g_pShaderAPI->SetIntRenderingParameter(this: g_pShaderAPI, a2: 5, a3: 2);
  g_pShaderAPI->SetIntRenderingParameter(this: g_pShaderAPI, a2: 1, a3: v5);
  g_pShaderAPI->SetIntRenderingParameter(this: g_pShaderAPI, a2: 2, a3: v6);
  g_pShaderAPI->SetIntRenderingParameter(this: g_pShaderAPI, a2: 3, a3: m_nAccumulatorWidth);
  g_pShaderAPI->SetIntRenderingParameter(this: g_pShaderAPI, a2: 4, a3: nHeight);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10050DB0
// Name: private: void CMorph::BindMorphWeight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMorph::BindMorphWeight(CMorph *this, int nRenderId)
{
  int m_nWeightHeight; // edi
  int m_nWeightWidth; // ebx
  int v4; // esi

  m_nWeightHeight = s_MorphMgr.m_nWeightHeight;
  m_nWeightWidth = s_MorphMgr.m_nWeightWidth;
  v4 = nRenderId % s_MorphMgr.m_nSubrectVerticalCount * s_MorphMgr.m_nWeightHeight;
  g_pShaderAPI->SetIntRenderingParameter(
    this: g_pShaderAPI,
    a2: 6,
    a3: nRenderId / s_MorphMgr.m_nSubrectVerticalCount * s_MorphMgr.m_nWeightWidth);
  g_pShaderAPI->SetIntRenderingParameter(this: g_pShaderAPI, a2: 7, a3: v4);
  g_pShaderAPI->SetIntRenderingParameter(this: g_pShaderAPI, a2: 8, a3: m_nWeightWidth);
  g_pShaderAPI->SetIntRenderingParameter(this: g_pShaderAPI, a2: 9, a3: m_nWeightHeight);
}

//------------------------------------------------------------------------------
// Address: 0x10050E30
// Name: private: void CMorph::CreateAccumulatorMaterial(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMorph::CreateAccumulatorMaterial(CMorph *this, int nMaterialIndex)
{
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  float m_flFloatToFixedScale; // xmm1_4
  float value; // xmm0_4
  const char *v7; // eax
  const char *v8; // eax
  unsigned int m_Format; // ecx
  int v10; // eax
  char pTemp[256]; // [esp+Ch] [ebp-110h] BYREF
  KeyValues *v12; // [esp+10Ch] [ebp-10h]
  int v13; // [esp+118h] [ebp-4h]

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v12 = v3;
  v13 = 0;
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "MorphAccumulate");
  else
    v4 = nullptr;
  v13 = -1;
  KeyValues::SetInt(this: v4, keyName: "$nocull", value: 1);
  m_flFloatToFixedScale = this->m_flFloatToFixedScale;
  if ( m_flFloatToFixedScale == 0.0 )
    value = 1.0;
  else
    value = 32768.0 / m_flFloatToFixedScale;
  KeyValues::SetFloat(this: v4, keyName: "$deltascale", value);
  if ( this->m_pMorphTexture[0] != nullptr )
  {
    v7 = this->m_pMorphTexture[0]->GetName(this: this->m_pMorphTexture[0]);
    KeyValues::SetString(this: v4, keyName: "$delta", value: v7);
  }
  if ( this->m_pMorphTexture[1] != nullptr )
  {
    v8 = this->m_pMorphTexture[1]->GetName(this: this->m_pMorphTexture[1]);
    KeyValues::SetString(this: v4, keyName: "$sidespeed", value: v8);
  }
  m_Format = this->m_Format;
  v10 = (m_Format & 5) != 0;
  if ( (m_Format & 2) != 0 )
    ++v10;
  V_snprintf(pDest: pTemp, maxLen: 256, pFormat: "[%d %d %d]", this->m_nTextureWidth, this->m_nTextureHeight, v10);
  KeyValues::SetString(this: v4, keyName: "$dimensions", value: pTemp);
  V_snprintf(pDest: pTemp, maxLen: 256, pFormat: "___AccumulateMorph%d.vmt", nMaterialIndex);
  CMaterialReference::Init(this: &this->m_MorphAccumulationMaterial, pMaterialName: pTemp, pVMTKeyValues: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10050F90
// Name: private: void CMorph::WriteDeltaPositionNormalToTexture(class CPixelWriter __near &,int,int,struct MorphVertexInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMorph::WriteDeltaPositionNormalToTexture(
        CMorph *this,
        CPixelWriter *pixelWriter,
        int x,
        int y,
        const MorphVertexInfo_t *info)
{
  CMorph *v5; // edx
  unsigned int m_Format; // ecx
  int v7; // eax
  unsigned __int8 *v9; // eax
  const MorphVertexInfo_t *v10; // edi
  unsigned int v11; // ebx
  int v12; // ecx
  float m_flFloatToFixedScale; // xmm0_4
  int v14; // edx
  int v15; // eax
  int v16; // eax
  unsigned __int8 v17; // al
  bool v18; // cf
  unsigned int m_GMask; // eax
  int v20; // eax
  __int16 m_BShift; // cx
  unsigned int v22; // eax
  unsigned int v23; // edx
  unsigned int v24; // edx
  unsigned int v25; // eax
  unsigned __int64 v26; // kr00_8
  unsigned __int64 v27; // rax
  __int16 v28; // cx
  int v29; // ebx
  int v30; // edi
  __int64 v31; // rax
  __int64 v32; // rax
  unsigned __int64 v33; // rax
  unsigned __int8 *v34; // ebx
  int v35; // edi
  int v36; // eax
  float v37; // xmm0_4
  float v38; // xmm1_4
  int v39; // eax
  int v40; // ecx
  int v41; // edx
  unsigned __int8 v42; // al
  unsigned int v43; // eax
  int v44; // eax
  __int16 v45; // cx
  unsigned int v46; // eax
  unsigned int v47; // edx
  unsigned int v48; // edx
  unsigned int v49; // eax
  unsigned __int64 v50; // kr08_8
  unsigned __int64 v51; // rax
  __int16 v52; // cx
  int v53; // ebx
  int v54; // edi
  __int64 v55; // rax
  __int64 v56; // rax
  unsigned __int64 v57; // rax
  int v58; // ebx
  int v59; // edi
  __int64 v60; // [esp+0h] [ebp-14h]
  __int64 v61; // [esp+0h] [ebp-14h]
  CMorph *v62; // [esp+8h] [ebp-Ch]
  int a; // [esp+Ch] [ebp-8h]
  int m_Size; // [esp+10h] [ebp-4h]
  CPixelWriter *pixelWritera; // [esp+1Ch] [ebp+8h]
  int pixelWriterb; // [esp+1Ch] [ebp+8h]
  int r; // [esp+20h] [ebp+Ch]
  int b; // [esp+24h] [ebp+10h]
  int infoa; // [esp+28h] [ebp+14h]

  v5 = this;
  m_Format = this->m_Format;
  v62 = v5;
  v7 = (m_Format & 5) != 0;
  if ( (m_Format & 2) != 0 )
    ++v7;
  m_Size = pixelWriter->m_Size;
  v9 = &pixelWriter->m_pBase[x * v7 * m_Size + y * pixelWriter->m_BytesPerRow];
  v10 = info;
  pixelWriter->m_pBits = v9;
  v11 = v5->m_Format;
  pixelWritera = (CPixelWriter *)v9;
  if ( (v11 & 5) != 0 )
  {
    v12 = 0x7FFF;
    r = 0x7FFF;
    b = 0x7FFF;
    a = 0x7FFF;
    if ( (v11 & 1) != 0 )
    {
      m_flFloatToFixedScale = v5->m_flFloatToFixedScale;
      v12 = (int)(float)(info->m_PositionDelta.y * m_flFloatToFixedScale) + 0x7FFF;
      v14 = (int)(float)(info->m_PositionDelta.z * m_flFloatToFixedScale) + 0x7FFF;
      v15 = (int)(float)(info->m_PositionDelta.x * m_flFloatToFixedScale) + 0x7FFF;
      if ( v15 >= 0 )
      {
        if ( v15 > 65534 )
          v15 = 65534;
      }
      else
      {
        v15 = 0;
      }
      r = v15;
      if ( v12 >= 0 )
      {
        if ( v12 > 65534 )
          v12 = 65534;
      }
      else
      {
        v12 = 0;
      }
      if ( v14 >= 0 )
      {
        if ( v14 > 65534 )
          v14 = 65534;
      }
      else
      {
        v14 = 0;
      }
      b = v14;
    }
    if ( (v11 & 4) != 0 )
    {
      v16 = (int)(float)(v62->m_flFloatToFixedScale * info->m_flWrinkleDelta) + 0x7FFF;
      if ( v16 >= 0 )
      {
        if ( v16 > 65534 )
          v16 = 65534;
      }
      else
      {
        v16 = 0;
      }
      a = v16;
    }
    v17 = pixelWriter->m_Size;
    if ( v17 != 0 )
    {
      v18 = v17 < 5u;
      m_GMask = pixelWriter->m_GMask;
      if ( v18 )
      {
        v20 = (v12 & m_GMask) << LOBYTE(pixelWriter->m_GShift);
        m_BShift = pixelWriter->m_BShift;
        v22 = ((r & pixelWriter->m_RMask) << LOBYTE(pixelWriter->m_RShift)) | v20;
        v23 = b & pixelWriter->m_BMask;
        if ( m_BShift <= 0 )
          v24 = v23 >> -(char)m_BShift;
        else
          v24 = v23 << m_BShift;
        v25 = v24 | ((a & pixelWriter->m_AMask) << LOBYTE(pixelWriter->m_AShift)) | v22;
        switch ( m_Size )
        {
          case 1:
            LOBYTE(pixelWritera->m_pBase) = v25;
            break;
          case 2:
            LOWORD(pixelWritera->m_pBase) = v25;
            break;
          case 3:
            LOWORD(pixelWritera->m_pBase) = v25;
            pixelWriter->m_pBits[2] = BYTE2(v25);
            break;
          case 4:
            pixelWritera->m_pBase = (unsigned __int8 *)v25;
            break;
          default:
            break;
        }
      }
      else
      {
        v26 = (unsigned __int64)(v12 & m_GMask) << pixelWriter->m_GShift;
        v27 = (unsigned __int64)(r & pixelWriter->m_RMask) << pixelWriter->m_RShift;
        v28 = pixelWriter->m_BShift;
        v29 = v27 | v26;
        LODWORD(v31) = b & pixelWriter->m_BMask;
        v30 = HIDWORD(v27) | HIDWORD(v26);
        HIDWORD(v31) = 0;
        if ( v28 <= 0 )
          v32 = v31 >> -(char)v28;
        else
          v32 = v31 << v28;
        v60 = v32;
        v33 = (unsigned __int64)(a & pixelWriter->m_AMask) << pixelWriter->m_AShift;
        v34 = (unsigned __int8 *)(v60 | v33 | v29);
        v35 = HIDWORD(v60) | HIDWORD(v33) | v30;
        if ( m_Size == 6 )
        {
          pixelWritera->m_pBase = v34;
          *((_WORD *)pixelWriter->m_pBits + 2) = v35;
        }
        else if ( m_Size == 8 )
        {
          pixelWritera->m_pBase = v34;
          *((_DWORD *)pixelWriter->m_pBits + 1) = v35;
        }
        v10 = info;
      }
    }
    v36 = pixelWriter->m_Size;
    pixelWriter->m_pBits += v36;
    v5 = v62;
    m_Size = v36;
  }
  if ( (v5->m_Format & 2) != 0 )
  {
    v37 = v5->m_flFloatToFixedScale;
    v38 = v10->m_NormalDelta.z * v37;
    v39 = (int)(float)(v10->m_NormalDelta.x * v37) + 0x7FFF;
    v40 = (int)(float)(v10->m_NormalDelta.y * v37) + 0x7FFF;
    v41 = (int)v38 + 0x7FFF;
    if ( v39 >= 0 )
    {
      pixelWriterb = 65534;
      if ( v39 <= 65534 )
        pixelWriterb = (int)(float)(v10->m_NormalDelta.x * v37) + 0x7FFF;
    }
    else
    {
      pixelWriterb = 0;
    }
    if ( v40 >= 0 )
    {
      if ( v40 > 65534 )
        v40 = 65534;
    }
    else
    {
      v40 = 0;
    }
    if ( v41 >= 0 )
    {
      infoa = 65534;
      if ( v41 <= 65534 )
        infoa = (int)v38 + 0x7FFF;
    }
    else
    {
      infoa = 0;
    }
    v42 = pixelWriter->m_Size;
    if ( v42 != 0 )
    {
      v18 = v42 < 5u;
      v43 = pixelWriter->m_GMask;
      if ( v18 )
      {
        v44 = (v40 & v43) << LOBYTE(pixelWriter->m_GShift);
        v45 = pixelWriter->m_BShift;
        v46 = ((pixelWriterb & pixelWriter->m_RMask) << LOBYTE(pixelWriter->m_RShift)) | v44;
        v47 = infoa & pixelWriter->m_BMask;
        if ( v45 <= 0 )
          v48 = v47 >> -(char)v45;
        else
          v48 = v47 << v45;
        v49 = v48 | ((pixelWriter->m_AMask & 0x7FFF) << LOBYTE(pixelWriter->m_AShift)) | v46;
        switch ( m_Size )
        {
          case 1:
            *pixelWriter->m_pBits = v49;
            pixelWriter->m_pBits += pixelWriter->m_Size;
            break;
          case 2:
            *(_WORD *)pixelWriter->m_pBits = v49;
            pixelWriter->m_pBits += pixelWriter->m_Size;
            break;
          case 3:
            *(_WORD *)pixelWriter->m_pBits = v49;
            pixelWriter->m_pBits[2] = BYTE2(v49);
            pixelWriter->m_pBits += pixelWriter->m_Size;
            break;
          case 4:
            *(_DWORD *)pixelWriter->m_pBits = v49;
            pixelWriter->m_pBits += pixelWriter->m_Size;
            break;
          default:
            goto LABEL_73;
        }
        return;
      }
      v50 = (unsigned __int64)(v40 & v43) << pixelWriter->m_GShift;
      v51 = (unsigned __int64)(pixelWriterb & pixelWriter->m_RMask) << pixelWriter->m_RShift;
      v52 = pixelWriter->m_BShift;
      v53 = v51 | v50;
      LODWORD(v55) = infoa & pixelWriter->m_BMask;
      v54 = HIDWORD(v51) | HIDWORD(v50);
      HIDWORD(v55) = 0;
      if ( v52 <= 0 )
        v56 = v55 >> -(char)v52;
      else
        v56 = v55 << v52;
      v61 = v56;
      v57 = (unsigned __int64)(pixelWriter->m_AMask & 0x7FFF) << pixelWriter->m_AShift;
      v58 = v61 | v57 | v53;
      v59 = HIDWORD(v61) | HIDWORD(v57) | v54;
      if ( m_Size == 6 )
      {
        *(_DWORD *)pixelWriter->m_pBits = v58;
        *((_WORD *)pixelWriter->m_pBits + 2) = v59;
      }
      else if ( m_Size == 8 )
      {
        *(_DWORD *)pixelWriter->m_pBits = v58;
        *((_DWORD *)pixelWriter->m_pBits + 1) = v59;
      }
    }
LABEL_73:
    pixelWriter->m_pBits += pixelWriter->m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051410
// Name: private: void CMorph::WriteSideSpeedToTexture(class CPixelWriter __near &,int,int,struct MorphVertexInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMorph::WriteSideSpeedToTexture(
        CMorph *this,
        CPixelWriter *pixelWriter,
        int x,
        int y,
        const MorphVertexInfo_t *info)
{
  unsigned int m_Format; // ecx
  int v6; // eax
  int v7; // edx
  int v8; // ecx
  unsigned __int8 m_Size; // al
  int v11; // edi
  unsigned __int8 *v12; // edi
  bool v13; // cf
  unsigned int m_GMask; // eax
  unsigned int v15; // eax
  unsigned __int64 v16; // kr00_8
  unsigned __int64 v17; // rax
  int v18; // ebx
  int v19; // edi
  CPixelWriter *pixelWritera; // [esp+10h] [ebp+8h]
  unsigned __int8 *ya; // [esp+18h] [ebp+10h]
  int infoa; // [esp+1Ch] [ebp+14h]

  m_Format = this->m_Format;
  v6 = 0;
  v7 = 0;
  if ( (m_Format & 0x10) != 0 )
    v6 = (int)(float)(info->m_flSide * 255.0);
  if ( (m_Format & 8) != 0 )
    v7 = (int)(float)(info->m_flSpeed * 255.0);
  v8 = 255;
  if ( v6 >= 0 )
  {
    infoa = 255;
    if ( v6 <= 255 )
      infoa = v6;
  }
  else
  {
    infoa = 0;
  }
  if ( v7 >= 0 )
  {
    if ( v7 <= 255 )
      v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  m_Size = pixelWriter->m_Size;
  v11 = y * pixelWriter->m_BytesPerRow;
  pixelWritera = (CPixelWriter *)m_Size;
  v12 = &pixelWriter->m_pBase[x * m_Size + v11];
  ya = v12;
  pixelWriter->m_pBits = v12;
  if ( m_Size == 0 )
    goto LABEL_24;
  v13 = m_Size < 5u;
  m_GMask = pixelWriter->m_GMask;
  if ( !v13 )
  {
    v16 = (unsigned __int64)(v8 & m_GMask) << pixelWriter->m_GShift;
    v17 = (unsigned __int64)(infoa & pixelWriter->m_RMask) << pixelWriter->m_RShift;
    v18 = v17 | v16;
    v19 = HIDWORD(v17) | HIDWORD(v16);
    if ( pixelWritera == (CPixelWriter *)6 )
    {
      *(_DWORD *)ya = v18;
      *((_WORD *)pixelWriter->m_pBits + 2) = v19;
    }
    else if ( pixelWritera == (CPixelWriter *)8 )
    {
      *(_DWORD *)ya = v18;
      *((_DWORD *)pixelWriter->m_pBits + 1) = v19;
    }
LABEL_24:
    pixelWriter->m_pBits += pixelWriter->m_Size;
    return;
  }
  v15 = ((infoa & pixelWriter->m_RMask) << LOBYTE(pixelWriter->m_RShift))
      | ((v8 & m_GMask) << LOBYTE(pixelWriter->m_GShift));
  switch ( (unsigned int)pixelWritera )
  {
    case 1u:
      *v12 = v15;
      pixelWriter->m_pBits += pixelWriter->m_Size;
      break;
    case 2u:
      *(_WORD *)v12 = v15;
      pixelWriter->m_pBits += pixelWriter->m_Size;
      break;
    case 3u:
      *(_WORD *)v12 = v15;
      pixelWriter->m_pBits[2] = BYTE2(v15);
      pixelWriter->m_pBits += pixelWriter->m_Size;
      break;
    case 4u:
      *(_DWORD *)v12 = v15;
      pixelWriter->m_pBits += pixelWriter->m_Size;
      break;
    default:
      goto LABEL_24;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051600
// Name: mat_reporthwmorphmemory
// Source: json
//------------------------------------------------------------------------------
void __cdecl mat_reporthwmorphmemory()
{
  int TotalMemoryUsage; // eax

  TotalMemoryUsage = CMorphMgr::GetTotalMemoryUsage(this: &s_MorphMgr);
  ConMsg(a1: "Total HW Morph memory used: %dk\n", TotalMemoryUsage / 1024);
}

//------------------------------------------------------------------------------
// Address: 0x10051630
// Name: public: int CUtlSortVector<struct CVertexMorphDict::MorphVertexList_t,class CVertexMorphDict::VertexMorphDictLess>::FindLessOrEqual(struct CVertexMorphDict::MorphVertexList_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CVertexMorphDict::MorphVertexList_t,CVertexMorphDict::VertexMorphDictLess>::FindLessOrEqual(
        CUtlSortVector<CVertexMorphDict::MorphVertexList_t,CVertexMorphDict::VertexMorphDictLess> *this,
        const CVertexMorphDict::MorphVertexList_t *src)
{
  int v3; // esi
  int v4; // ecx
  CVertexMorphDict::MorphVertexList_t *m_pMemory; // ebx
  int m_nMorphTargetId; // edi
  int result; // eax
  int v8; // edx

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
         277,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1\\utlsortvector.h",
                            a2: 277,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
      a2: 277);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    m_nMorphTargetId = src->m_nMorphTargetId;
    do
    {
      result = (v4 + v3) >> 1;
      v8 = m_pMemory[result].m_nMorphTargetId;
      if ( m_nMorphTargetId <= v8 )
      {
        if ( m_nMorphTargetId >= v8 )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
    }
    while ( v3 <= v4 );
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10051770
// Name: public: void CUtlMemory<struct CVertexMorphDict::MorphVertexList_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CVertexMorphDict::MorphVertexList_t,int>::Grow(
        CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CVertexMorphDict::MorphVertexList_t *m_pMemory; // edx
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
    v7 = 32 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CVertexMorphDict::MorphVertexList_t *)_g_pMemAlloc->Realloc_2(
                                                                 this: _g_pMemAlloc,
                                                                 a2: m_pMemory,
                                                                 a3: v7);
    else
      this->m_pMemory = (CVertexMorphDict::MorphVertexList_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051800
// Name: public: void CUtlMemory<struct CMorph::MorphQuad_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CMorph::MorphQuad_t,int>::Grow(
        CUtlMemory<CVTFTexture::ResourceMemorySection,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CVTFTexture::ResourceMemorySection *m_pMemory; // edx
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
        m_nAllocationCount = 3;
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
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CVTFTexture::ResourceMemorySection *)_g_pMemAlloc->Realloc_2(
                                                                this: _g_pMemAlloc,
                                                                a2: m_pMemory,
                                                                a3: v7);
    else
      this->m_pMemory = (CVTFTexture::ResourceMemorySection *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100518A0
// Name: public: void CUtlMemory<struct CMorph::MorphSegment_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CMorph::MorphSegment_t,int>::Grow(CUtlMemory<ResourceEntryInfo,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  ResourceEntryInfo *m_pMemory; // edx
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
        m_nAllocationCount = 4;
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
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (ResourceEntryInfo *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (ResourceEntryInfo *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051940
// Name: private: int CMorph::DetermineTotalDeltaCount(class CUtlVector<class CUtlVector<struct CMorph::MorphSegment_t,class CUtlMemory<struct CMorph::MorphSegment_t,int>>,class CUtlMemory<class CUtlVector<struct CMorph::MorphSegment_t,class CUtlMemory<struct CMorph::MorphSegment_t,int>>,int>> const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMorph::DetermineTotalDeltaCount(
        CMorph *this,
        const CUtlVector<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,CUtlMemory<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,int> > *morphSegments)
{
  int result; // eax
  CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> > *m_pMemory; // ebx
  int m_Size; // edx
  int v5; // esi
  int v6; // edi
  int v7; // ecx
  unsigned __int16 *p_m_nCount; // ecx
  unsigned int v9; // edx
  bool v10; // zf
  int j; // [esp+0h] [ebp-8h]
  int nDeltaCount; // [esp+4h] [ebp-4h]
  const CUtlVector<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,CUtlMemory<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,int> > *morphSegmentsa; // [esp+10h] [ebp+8h]

  result = 0;
  nDeltaCount = 0;
  if ( morphSegments->m_Size > 0 )
  {
    m_pMemory = morphSegments->m_Memory.m_pMemory;
    morphSegmentsa = (const CUtlVector<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,CUtlMemory<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,int> > *)morphSegments->m_Size;
    do
    {
      m_Size = m_pMemory->m_Size;
      v5 = 0;
      v6 = 0;
      v7 = 0;
      if ( m_Size >= 2 )
      {
        p_m_nCount = &m_pMemory->m_Memory.m_pMemory[1].m_nCount;
        v9 = ((unsigned int)(m_Size - 2) >> 1) + 1;
        j = 2 * v9;
        do
        {
          v5 += *(p_m_nCount - 4);
          v6 += *p_m_nCount;
          p_m_nCount += 8;
          --v9;
        }
        while ( v9 != 0 );
        result = nDeltaCount;
        v7 = j;
      }
      if ( v7 < m_pMemory->m_Size )
        result += m_pMemory->m_Memory.m_pMemory[v7].m_nCount;
      result += v5 + v6;
      ++m_pMemory;
      v10 = morphSegmentsa == (const CUtlVector<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,CUtlMemory<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,int> > *)1;
      morphSegmentsa = (const CUtlVector<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,CUtlMemory<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,int> > *)((char *)morphSegmentsa - 1);
      nDeltaCount = result;
    }
    while ( !v10 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100519C0
// Name: private: void CMorph::ComputeTextureDimensions(class CUtlVector<class CUtlVector<struct CMorph::MorphSegment_t,class CUtlMemory<struct CMorph::MorphSegment_t,int>>,class CUtlMemory<class CUtlVector<struct CMorph::MorphSegment_t,class CUtlMemory<struct CMorph::MorphSegment_t,int>>,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMorph::ComputeTextureDimensions(
        CMorph *this,
        const CUtlVector<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,CUtlMemory<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,int> > *morphSegments)
{
  int v3; // edi
  signed int v4; // ecx
  int v5; // eax
  unsigned int m_Format; // eax
  int v7; // edi
  int v8; // ebx
  int v9; // eax
  int nMaxTextureHeight; // [esp+1Ch] [ebp+8h]

  v3 = CMorph::DetermineTotalDeltaCount(this, morphSegments);
  v4 = ((int)ceil(X: fsqrt((float)v3)) + 3) & 0xFFFFFFFC;
  this->m_nTextureHeight = v4;
  if ( v4 != 0 )
    v5 = (v4 + v3 - 1) / v4;
  else
    v5 = 0;
  this->m_nTextureWidth = (v5 + 3) & 0xFFFFFFFC;
  m_Format = this->m_Format;
  v7 = (m_Format & 5) != 0;
  if ( (m_Format & 2) != 0 )
    ++v7;
  v8 = g_pHWConfig->MaxTextureWidth(this: g_pHWConfig);
  v9 = g_pHWConfig->MaxTextureHeight(this: g_pHWConfig);
  nMaxTextureHeight = v9;
  if ( v7 * this->m_nTextureWidth > v8 )
  {
    while ( 1 )
    {
      this->m_nTextureWidth >>= 1;
      this->m_nTextureHeight *= 2;
      if ( this->m_nTextureHeight > v9 )
        break;
      if ( v7 * this->m_nTextureWidth <= v8 )
        return;
    }
    _Warning(a1: "Morph texture is too big!!! Make brian add support for morphs having multiple textures.\n");
    this->m_nTextureHeight = nMaxTextureHeight;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051A90
// Name: private: int CMorph::CountStaticMeshVertices(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMorph::CountStaticMeshVertices(CMorph *this)
{
  int m_Size; // edx
  int v2; // ebx
  int v3; // esi
  int v4; // edi
  int v5; // eax
  int *p_m_Size; // eax
  unsigned int v7; // edx
  int v8; // ebx
  int i; // [esp+Ch] [ebp-8h]

  m_Size = this->m_MorphQuads.m_Size;
  v2 = 0;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  if ( m_Size >= 2 )
  {
    p_m_Size = &this->m_MorphQuads.m_Memory.m_pMemory[1].m_Size;
    v7 = ((unsigned int)(m_Size - 2) >> 1) + 1;
    i = 2 * v7;
    do
    {
      v3 += 4 * *(p_m_Size - 5);
      v8 = *p_m_Size;
      p_m_Size += 10;
      --v7;
      v4 += 4 * v8;
    }
    while ( v7 != 0 );
    v2 = 0;
    v5 = i;
  }
  if ( v5 < this->m_MorphQuads.m_Size )
    v2 = 4 * this->m_MorphQuads.m_Memory.m_pMemory[v5].m_Size;
  return v2 + v4 + v3;
}

//------------------------------------------------------------------------------
// Address: 0x10051B00
// Name: private: void CMorph::CreateStaticMesh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMorph::CreateStaticMesh(CMorph *this)
{
  CMorph *v1; // edi
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // edx
  IMatRenderContext *m_pObject; // ebx
  IMaterial *m_pMaterial; // ecx
  void (__thiscall *Refresh)(IMaterial *); // edx
  __int64 v6; // rax
  int v7; // esi
  unsigned int m_Format; // eax
  __m128i v9; // xmm2
  int m_Size; // esi
  int v11; // edx
  CUtlVector<CMorph::MorphQuad_t,CUtlMemory<CMorph::MorphQuad_t,int> > *v12; // eax
  int v13; // ecx
  unsigned int m_nTextureHeight; // edi
  CMorph::MorphQuad_t *v15; // esi
  int v16; // ebx
  int v17; // eax
  int v18; // ecx
  int v19; // edi
  int v20; // ebx
  float *v21; // eax
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  int m_nCount; // eax
  int v26; // edx
  float v27; // xmm0_4
  float *v28; // eax
  float v29; // xmm0_4
  int v30; // eax
  float v31; // xmm1_4
  int v32; // ecx
  float v33; // xmm0_4
  float *v34; // eax
  float v35; // xmm0_4
  float v36; // xmm2_4
  float v37; // xmm1_4
  float *v38; // eax
  bool v39; // zf
  int m_nVertexCount; // eax
  void (__thiscall *EndRender)(IMatRenderContext *); // edx
  int (__thiscall *Release)(struct IMatRenderContext *); // edx
  IMesh *m_pMorphBuffer; // [esp-14h] [ebp-270h]
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-250h] BYREF
  float v45; // [esp+1F4h] [ebp-68h]
  int nMorphCount; // [esp+1F8h] [ebp-64h]
  float v47; // [esp+1FCh] [ebp-60h]
  CMatRenderContextPtr pRenderContext; // [esp+200h] [ebp-5Ch]
  float v49; // [esp+204h] [ebp-58h]
  float v50; // [esp+208h] [ebp-54h]
  CUtlVector<CMorph::MorphQuad_t,CUtlMemory<CMorph::MorphQuad_t,int> > *quadList; // [esp+20Ch] [ebp-50h]
  float v52; // [esp+210h] [ebp-4Ch]
  float v53; // [esp+214h] [ebp-48h]
  int i; // [esp+218h] [ebp-44h]
  int dy; // [esp+21Ch] [ebp-40h]
  CMorph *v56; // [esp+220h] [ebp-3Ch]
  float flOOTexWidth; // [esp+224h] [ebp-38h]
  int nDestTextureHeight; // [esp+228h] [ebp-34h]
  float flOODestWidth; // [esp+22Ch] [ebp-30h]
  int v60; // [esp+230h] [ebp-2Ch]
  unsigned int v61; // [esp+234h] [ebp-28h]
  int sy; // [esp+238h] [ebp-24h]
  unsigned int v63; // [esp+23Ch] [ebp-20h]
  float flOODestHeight; // [esp+240h] [ebp-1Ch]
  float flOOTexHeight; // [esp+244h] [ebp-18h]
  float v66; // [esp+248h] [ebp-14h]
  int v67; // [esp+24Ch] [ebp-10h]
  int v68; // [esp+258h] [ebp-4h]

  v1 = this;
  GetRenderContext = g_pMaterialSystem->GetRenderContext;
  v56 = this;
  m_pObject = GetRenderContext(this: g_pMaterialSystem);
  pRenderContext.m_pObject = m_pObject;
  v68 = 0;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  m_pMaterial = v1->m_MorphAccumulationMaterial.m_pMaterial;
  Refresh = m_pMaterial->Refresh;
  v68 = 1;
  Refresh(this: m_pMaterial);
  v6 = v1->m_MorphAccumulationMaterial.m_pMaterial->GetVertexFormat(this: v1->m_MorphAccumulationMaterial.m_pMaterial);
  v1->m_pMorphBuffer = (IMesh *)((int (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, const char *, IMaterial *, _DWORD))m_pObject->CreateStaticMesh)(
                                  a1: m_pObject,
                                  a2: v6 & 0xFFFFFBFF,
                                  a3: HIDWORD(v6),
                                  a4: "Morph Targets",
                                  a5: v1->m_MorphAccumulationMaterial.m_pMaterial,
                                  a6: 0);
  v7 = CMorph::CountStaticMeshVertices(this: v1);
  if ( v7 >= 0xFFFF )
    _Warning(a1: "Too many morph vertices! Call brian\n");
  m_Format = v1->m_Format;
  v67 = (m_Format & 5) != 0;
  if ( (m_Format & 2) != 0 )
    ++v67;
  v9 = _mm_cvtsi32_si128(v1->m_nTextureHeight);
  flOOTexWidth = 1.0 / (float)(v67 * v1->m_nTextureWidth);
  flOOTexHeight = 1.0 / _mm_cvtepi32_ps(v9).m128_f32[0];
  flOODestWidth = 1.0 / (float)s_MorphMgr.m_nAccumulatorWidth;
  nDestTextureHeight = s_MorphMgr.m_nAccumulatorHeight;
  flOODestHeight = 1.0 / (float)s_MorphMgr.m_nAccumulatorHeight;
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  m_pMorphBuffer = v1->m_pMorphBuffer;
  LOBYTE(v68) = 2;
  CMeshBuilder::Begin(
    this: &meshBuilder,
    pMesh: m_pMorphBuffer,
    type: MATERIAL_TRIANGLES,
    nVertexCount: v7,
    nIndexCount: 0,
    pMeshSettings: nullptr);
  m_Size = v1->m_MorphQuads.m_Size;
  v11 = 0;
  nMorphCount = m_Size;
  i = 0;
  if ( m_Size > 0 )
  {
    v61 = 0;
    do
    {
      v12 = &v1->m_MorphQuads.m_Memory.m_pMemory[v61 / 0x14];
      v13 = v12->m_Size;
      quadList = v12;
      if ( v13 > 0 )
      {
        v66 = (float)v11;
        v63 = 0;
        v60 = v13;
        while ( 1 )
        {
          m_nTextureHeight = v1->m_nTextureHeight;
          v15 = &v12->m_Memory.m_pMemory[v63 / 0xC];
          v16 = v15->m_nFirstSrc / m_nTextureHeight;
          sy = v15->m_nFirstSrc % m_nTextureHeight;
          v17 = v15->m_nFirstDest / nDestTextureHeight;
          v18 = v15->m_nFirstDest % nDestTextureHeight;
          v19 = v16 * v67;
          v53 = (float)(v16 * v67) * flOOTexWidth;
          v20 = v17 * v67;
          v21 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
          *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v53;
          v22 = (float)sy * flOOTexHeight;
          v21[1] = v22;
          v45 = v22;
          v23 = (float)((float)v20 - 0.5) * flOODestWidth;
          v21[2] = v23;
          v47 = v23;
          v24 = (float)((float)v18 - 0.5) * flOODestHeight;
          v21[3] = v24;
          dy = v18;
          v50 = v24;
          *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = v66;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          m_nCount = v15->m_nCount;
          v26 = m_nCount + sy;
          v27 = (float)(dy + m_nCount);
          v28 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
          v29 = (float)(v27 - 0.5) * flOODestHeight;
          *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v53;
          v28[1] = (float)v26 * flOOTexHeight;
          v28[2] = v47;
          v28[3] = v29;
          *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = v66;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v30 = v15->m_nCount;
          v31 = (float)(v30 + sy) * flOOTexHeight;
          v32 = v67;
          v33 = (float)(dy + v30);
          v34 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
          v35 = (float)(v33 - 0.5) * flOODestHeight;
          v36 = (float)(v67 + v19) * flOOTexWidth;
          *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v36;
          v34[1] = v31;
          v37 = (float)((float)(v20 + v32) - 0.5) * flOODestWidth;
          v34[2] = v37;
          v34[3] = v35;
          v49 = v36;
          v52 = v37;
          *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = v66;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v38 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
          *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v49;
          v38[1] = v45;
          v38[2] = v52;
          v38[3] = v50;
          *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = v66;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v63 += 12;
          v39 = v60-- == 1;
          v1 = v56;
          if ( v39 )
            break;
          v12 = quadList;
        }
        m_pObject = pRenderContext.m_pObject;
        m_Size = nMorphCount;
        v11 = i;
      }
      v61 += 20;
      i = ++v11;
    }
    while ( v11 < m_Size );
  }
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
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  EndRender = m_pObject->EndRender;
  v68 = 4;
  EndRender(this: m_pObject);
  Release = m_pObject->Release;
  v68 = -1;
  Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x10051FE0
// Name: private: virtual void CMorph::RegenerateTextureBits(class ITexture __near *,class IVTFTexture __near *,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CMorph::RegenerateTextureBits(
        CMorph *this,
        ITexture *pTexture,
        IVTFTexture *pVTFTexture,
        Rect_t *pRect)
{
  int v4; // eax
  unsigned int *p_m_Format; // ecx
  _QWORD *v7; // eax
  int (__thiscall *RowSizeInBytes)(IVTFTexture *, int); // edx
  __int16 v9; // bx
  unsigned __int8 *v10; // edi
  ImageFormat v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // edi
  int v15; // edi
  int v16; // eax
  int v17; // esi
  int v18; // ebx
  int m_nGrowSize; // ecx
  CUtlVector<CMorph::MorphQuad_t,CUtlMemory<CMorph::MorphQuad_t,int> > *v20; // ebx
  int m_Size; // eax
  CMorph::MorphQuad_t *v22; // edi
  unsigned int m_nFirstSrc; // esi
  unsigned int m_nTextureWidth; // ecx
  int v25; // eax
  int v26; // edx
  int m_nFirstDest; // eax
  unsigned int v28; // esi
  unsigned int v29; // ebx
  int v30; // eax
  int v31; // esi
  int *v32; // eax
  int m_nCount; // ecx
  MorphVertexInfo_t zeroDelta; // [esp+Ch] [ebp-8Ch] BYREF
  int v35; // [esp+38h] [ebp-60h]
  int sx; // [esp+3Ch] [ebp-5Ch]
  CUtlVector<CMorph::MorphQuad_t,CUtlMemory<CMorph::MorphQuad_t,int> > *quadList; // [esp+40h] [ebp-58h]
  int nQuadListCount; // [esp+44h] [ebp-54h]
  int k; // [esp+48h] [ebp-50h]
  int j; // [esp+4Ch] [ebp-4Ch]
  int nDest; // [esp+50h] [ebp-48h]
  int v42; // [esp+54h] [ebp-44h]
  unsigned int v43; // [esp+58h] [ebp-40h]
  int i; // [esp+5Ch] [ebp-3Ch]
  __int128 writeFunc; // [esp+60h] [ebp-38h]
  CMorph *v46; // [esp+70h] [ebp-28h]
  _BYTE pWriteFuncs[36]; // [esp+74h] [ebp-24h] OVERLAPPED BYREF
  ITexture *pTexturea; // [esp+A0h] [ebp+8h]
  ITexture *pTextureb; // [esp+A0h] [ebp+8h]
  int nVertIndex; // [esp+A4h] [ebp+Ch]
  int nVertIndexa; // [esp+A4h] [ebp+Ch]

  v46 = this;
  v4 = 0;
  p_m_Format = &this->m_Format;
  do
  {
    if ( pTexture == (ITexture *)*p_m_Format )
      break;
    ++v4;
    ++p_m_Format;
  }
  while ( v4 < 2 );
  *(_QWORD *)&pWriteFuncs[4] = (unsigned int)CMorph::WriteDeltaPositionNormalToTexture;
  *(_QWORD *)&pWriteFuncs[12] = 0;
  *((_QWORD *)&writeFunc + 1) = 0;
  *(_QWORD *)&writeFunc = (unsigned int)CMorph::WriteSideSpeedToTexture;
  *(_QWORD *)&pWriteFuncs[20] = (unsigned int)CMorph::WriteSideSpeedToTexture;
  v7 = &pWriteFuncs[16 * v4 + 4];
  *(_QWORD *)&pWriteFuncs[28] = 0;
  *(_QWORD *)&writeFunc = *v7;
  RowSizeInBytes = pVTFTexture->RowSizeInBytes;
  *((_QWORD *)&writeFunc + 1) = v7[1];
  v9 = RowSizeInBytes(this: pVTFTexture, a2: 0);
  v10 = pVTFTexture->ImageData_3(this: pVTFTexture);
  v11 = pVTFTexture->Format(this: pVTFTexture);
  *(_DWORD *)&pWriteFuncs[4] = v10;
  *(_DWORD *)pWriteFuncs = v10;
  *(_WORD *)&pWriteFuncs[8] = v9;
  pWriteFuncs[11] = 0;
  switch ( v11 )
  {
    case IMAGE_FORMAT_RGBA8888:
    case IMAGE_FORMAT_UVWQ8888:
      v12 = 255;
      pWriteFuncs[10] = 4;
      *(_DWORD *)&pWriteFuncs[12] = 0x80000;
      *(_QWORD *)&pWriteFuncs[16] = 0xFF00180010LL;
      goto LABEL_22;
    case IMAGE_FORMAT_BGR888:
      v12 = 255;
      pWriteFuncs[10] = 3;
      *(_DWORD *)&pWriteFuncs[12] = 524304;
      *(_QWORD *)&pWriteFuncs[16] = 0xFF00000000LL;
      *(_DWORD *)&pWriteFuncs[32] = 0;
      goto LABEL_23;
    case IMAGE_FORMAT_I8:
      pWriteFuncs[10] = 1;
      *(_DWORD *)&pWriteFuncs[12] = 0;
      *(_DWORD *)&pWriteFuncs[16] = 0;
      goto LABEL_20;
    case IMAGE_FORMAT_A8:
      v12 = 0;
      pWriteFuncs[10] = 1;
      memset(&pWriteFuncs[12], 0, 12);
      *(_DWORD *)&pWriteFuncs[32] = 255;
      goto LABEL_23;
    case IMAGE_FORMAT_BGRA8888:
      v12 = 255;
      pWriteFuncs[10] = 4;
      *(_DWORD *)&pWriteFuncs[12] = 524304;
      *(_QWORD *)&pWriteFuncs[16] = 0xFF00180000LL;
      goto LABEL_22;
    case IMAGE_FORMAT_BGRX8888:
      v12 = 255;
      pWriteFuncs[10] = 4;
      *(_DWORD *)&pWriteFuncs[12] = 524304;
      *(_QWORD *)&pWriteFuncs[16] = 0xFF00180000LL;
      *(_DWORD *)&pWriteFuncs[32] = 0;
      goto LABEL_23;
    case IMAGE_FORMAT_BGR565:
      v12 = 248;
      pWriteFuncs[10] = 2;
      *(_DWORD *)&pWriteFuncs[12] = 196616;
      *(_QWORD *)&pWriteFuncs[16] = 0xF80000FFFDLL;
      *(_DWORD *)&pWriteFuncs[24] = 252;
      *(_DWORD *)&pWriteFuncs[32] = 0;
      goto LABEL_24;
    case IMAGE_FORMAT_BGRX5551:
    case IMAGE_FORMAT_BGRA5551:
      v12 = 248;
      pWriteFuncs[10] = 2;
      *(_DWORD *)&pWriteFuncs[12] = 131079;
      *(_QWORD *)&pWriteFuncs[16] = 0xF80008FFFDLL;
      *(_DWORD *)&pWriteFuncs[32] = 128;
      goto LABEL_23;
    case IMAGE_FORMAT_BGRA4444:
      v12 = 240;
      pWriteFuncs[10] = 2;
      *(_DWORD *)&pWriteFuncs[12] = 4;
      *(_QWORD *)&pWriteFuncs[16] = 0xF00008FFFCLL;
      goto LABEL_22;
    case IMAGE_FORMAT_RGBA16161616F:
      v12 = 0xFFFF;
      *(_DWORD *)&pWriteFuncs[12] = 0x100000;
      *(_QWORD *)&pWriteFuncs[16] = 0xFFFF00300020LL;
      *(_WORD *)&pWriteFuncs[10] = 776;
      goto LABEL_22;
    case IMAGE_FORMAT_RGBA16161616:
      v12 = 0xFFFF;
      pWriteFuncs[10] = 8;
      *(_DWORD *)&pWriteFuncs[12] = 0x100000;
      *(_QWORD *)&pWriteFuncs[16] = 0xFFFF00300020LL;
      goto LABEL_22;
    case IMAGE_FORMAT_R32F:
      *(_DWORD *)&pWriteFuncs[12] = 0;
      *(_QWORD *)&pWriteFuncs[16] = 0xFFFFFFFF00000000uLL;
      *(_WORD *)&pWriteFuncs[10] = 260;
      goto LABEL_21;
    case IMAGE_FORMAT_RGBA32323232F:
      v12 = -1;
      *(_DWORD *)&pWriteFuncs[12] = 0x200000;
      *(_QWORD *)&pWriteFuncs[16] = -4288675776LL;
      *(_WORD *)&pWriteFuncs[10] = 272;
      goto LABEL_22;
    case IMAGE_FORMAT_BGRA1010102:
      v12 = 1023;
      pWriteFuncs[10] = 4;
      *(_DWORD *)&pWriteFuncs[12] = 655380;
      *(_QWORD *)&pWriteFuncs[16] = 0x3FF001E0000LL;
      *(_DWORD *)&pWriteFuncs[32] = 3;
      goto LABEL_23;
    default:
      *(_QWORD *)&pWriteFuncs[10] = 2048;
      *(_WORD *)&pWriteFuncs[18] = 0;
LABEL_20:
      *(_DWORD *)&pWriteFuncs[20] = 255;
LABEL_21:
      v12 = 0;
LABEL_22:
      *(_DWORD *)&pWriteFuncs[32] = v12;
LABEL_23:
      *(_DWORD *)&pWriteFuncs[24] = v12;
LABEL_24:
      memset(&zeroDelta.m_PositionDelta, 0, 28);
      *(_DWORD *)&pWriteFuncs[28] = v12;
      v13 = *(_DWORD *)&v46->m_bLocked;
      zeroDelta.m_flSpeed = 1.0;
      zeroDelta.m_flSide = 0.5;
      v14 = (v13 & 5) != 0;
      if ( (v13 & 2) != 0 )
        ++v14;
      v15 = pVTFTexture->Width(this: pVTFTexture) / v14;
      v16 = pVTFTexture->Height(this: pVTFTexture);
      v17 = 0;
      v18 = 0;
      for ( nVertIndex = v16; v18 < v16; ++v18 )
      {
        if ( v15 > 0 )
        {
          pTexturea = (ITexture *)((char *)v46 + DWORD1(writeFunc) - 4);
          do
            ((void (__thiscall *)(ITexture *, _BYTE *, int, int, MorphVertexInfo_t *))writeFunc)(
              a1: pTexturea,
              a2: pWriteFuncs,
              a3: v17++,
              a4: v18,
              a5: &zeroDelta);
          while ( v17 < v15 );
          v16 = nVertIndex;
          v17 = 0;
        }
      }
      m_nGrowSize = v46->m_MorphQuads.m_Memory.m_nGrowSize;
      nQuadListCount = m_nGrowSize;
      i = 0;
      if ( m_nGrowSize > 0 )
      {
        v42 = 0;
        do
        {
          v20 = (CUtlVector<CMorph::MorphQuad_t,CUtlMemory<CMorph::MorphQuad_t,int> > *)((char *)v46->m_pMorphBuffer
                                                                                       + v42);
          nVertIndexa = 0;
          m_Size = v20->m_Size;
          quadList = v20;
          if ( m_Size > 0 )
          {
            v43 = 0;
            for ( j = m_Size; j != 0; --j )
            {
              v22 = &v20->m_Memory.m_pMemory[v43 / 0xC];
              m_nFirstSrc = v22->m_nFirstSrc;
              m_nTextureWidth = v46->m_nTextureWidth;
              v25 = v22->m_nFirstSrc / m_nTextureWidth;
              k = 0;
              v26 = v25;
              m_nFirstDest = v22->m_nFirstDest;
              v28 = m_nFirstSrc - v26 * m_nTextureWidth;
              sx = v26;
              nDest = m_nFirstDest;
              if ( v22->m_nCount != 0 )
              {
                v29 = v28;
                v30 = 32 * i;
                v31 = 44 * nVertIndexa;
                v35 = 32 * i;
                pTextureb = (ITexture *)((char *)v46 + DWORD1(writeFunc) - 4);
                while ( 1 )
                {
                  v32 = (int *)(*(char **)((char *)&v46->Release + v30) + v31);
                  if ( *v32 <= nDest )
                  {
                    ((void (__thiscall *)(ITexture *, _BYTE *, int, unsigned int, int *))writeFunc)(
                      a1: pTextureb,
                      a2: pWriteFuncs,
                      a3: v26,
                      a4: v29,
                      a5: v32);
                    ++nVertIndexa;
                    v31 += 44;
                  }
                  else
                  {
                    ((void (__thiscall *)(ITexture *, _BYTE *, int, unsigned int, MorphVertexInfo_t *))writeFunc)(
                      a1: pTextureb,
                      a2: pWriteFuncs,
                      a3: v26,
                      a4: v29,
                      a5: &zeroDelta);
                  }
                  m_nCount = v22->m_nCount;
                  ++nDest;
                  ++v29;
                  if ( ++k >= m_nCount )
                    break;
                  v26 = sx;
                  v30 = v35;
                }
                v20 = quadList;
              }
              v43 += 12;
            }
            m_nGrowSize = nQuadListCount;
          }
          v42 += 20;
          ++i;
        }
        while ( i < m_nGrowSize );
      }
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100524C0
// Name: private: void CMorph::RenderMorphQuads(class IMatRenderContext __near *,int,int,int,int __near *,struct MorphWeight_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMorph::RenderMorphQuads(
        CMorph *this,
        IMatRenderContext *pRenderContext,
        int nRenderId,
        int nTotalQuadCount,
        int nWeightCount,
        int *pWeightLookup,
        const MorphWeight_t *pWeights)
{
  CMorph *v7; // ebx
  IMesh *(__thiscall *GetDynamicMesh)(IMatRenderContext *, bool, IMesh *, IMesh *, IMaterial *); // edx
  IMesh *v9; // edi
  int v10; // edx
  unsigned int m_nCurrentIndex; // ecx
  int v12; // eax
  CUtlVector<CMorph::MorphQuad_t,CUtlMemory<CMorph::MorphQuad_t,int> > *v13; // esi
  int v14; // edx
  __int16 v15; // ax
  bool v16; // zf
  int m_nVertexCount; // eax
  IMesh *m_pMorphBuffer; // [esp-Ch] [ebp-214h]
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-1FCh] BYREF
  IMesh *pMesh; // [esp+1F4h] [ebp-14h]
  CMorph *v21; // [esp+1F8h] [ebp-10h]
  int v22; // [esp+204h] [ebp-4h]
  int i; // [esp+210h] [ebp+8h]
  int nRenderIda; // [esp+214h] [ebp+Ch]

  v7 = this;
  v21 = this;
  if ( s_MorphMgr.m_bUsingConstantRegisters )
    pRenderContext->SetFlexWeights(
      this: pRenderContext,
      a2: 0,
      a3: this->m_nMaxMorphTargetCount,
      a4: this->m_pRenderMorphWeight);
  else
    CMorph::BindMorphWeight(this, nRenderId);
  pRenderContext->Viewport(
    this: pRenderContext,
    a2: nRenderId / s_MorphMgr.m_nSubrectVerticalCount * s_MorphMgr.m_nAccumulatorWidth,
    a3: nRenderId % s_MorphMgr.m_nSubrectVerticalCount * s_MorphMgr.m_nAccumulatorHeight,
    a4: s_MorphMgr.m_nAccumulatorWidth,
    a5: s_MorphMgr.m_nAccumulatorHeight);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  GetDynamicMesh = pRenderContext->GetDynamicMesh;
  m_pMorphBuffer = v7->m_pMorphBuffer;
  v22 = 0;
  v9 = GetDynamicMesh(this: pRenderContext, a2: false, a3: m_pMorphBuffer, a4: nullptr, a5: nullptr);
  pMesh = v9;
  CMeshBuilder::Begin(
    this: &meshBuilder,
    pMesh: v9,
    type: MATERIAL_TRIANGLES,
    nVertexCount: 0,
    nIndexCount: 6 * nTotalQuadCount,
    pMeshSettings: nullptr);
  v10 = 0;
  i = 0;
  if ( nWeightCount > 0 )
  {
    m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
    do
    {
      v12 = v7->m_MorphTargetIdToQuadIndex.m_Memory.m_pMemory[pWeightLookup[v10]];
      if ( v12 >= 0 )
      {
        v13 = &v7->m_MorphQuads.m_Memory.m_pMemory[v12];
        if ( v13->m_Size > 0 )
        {
          v14 = 0;
          nRenderIda = v13->m_Size;
          do
          {
            v15 = 4 * v13->m_Memory.m_pMemory[v14].m_nQuadIndex;
            meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = v15
                                                                   + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
            meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
            meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                              + v15
                                                                                              + 1;
            meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
            meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                              + v15
                                                                                              + 2;
            meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
            meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = v15
                                                                                              + LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset);
            meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
            meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                              + v15
                                                                                              + 2;
            meshBuilder.m_IndexBuilder.m_nCurrentIndex += meshBuilder.m_IndexBuilder.m_nIndexSize;
            meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                                              + v15
                                                                                              + 3;
            m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
            ++v14;
            v16 = nRenderIda-- == 1;
            meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
            meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
          }
          while ( !v16 );
          v10 = i;
          v9 = pMesh;
          v7 = v21;
        }
      }
      i = ++v10;
    }
    while ( v10 < nWeightCount );
  }
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
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v9->Draw_2(this: v9, a2: -1, a3: 0);
  v22 = 1;
  if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
  {
    meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
  }
  v22 = -1;
  if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
  {
    meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10052820
// Name: private: int CMorph::BuildNonZeroMorphList(int __near *,int,struct MorphWeight_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMorph::BuildNonZeroMorphList(
        CMorph *this,
        int *pWeightIndices,
        int nWeightCount,
        const MorphWeight_t *pWeights)
{
  __int64 v4; // rax
  float *v5; // esi

  v4 = 0;
  if ( this->m_nMaxMorphTargetCount > 0 )
  {
    v5 = &pWeights->m_pWeight[2];
    do
    {
      if ( this->m_MorphTargetIdToQuadIndex.m_Memory.m_pMemory[HIDWORD(v4)] >= 0
        && (fabs(*(v5 - 2)) >= 0.001 || fabs(*(v5 - 1)) >= 0.001 || fabs(*v5) >= 0.001 || fabs(v5[1]) >= 0.001) )
      {
        pWeightIndices[(_DWORD)v4] = HIDWORD(v4);
        LODWORD(v4) = v4 + 1;
      }
      ++HIDWORD(v4);
      v5 += 4;
    }
    while ( SHIDWORD(v4) < this->m_nMaxMorphTargetCount );
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100528C0
// Name: public: bool CMorph::RenderMorphWeights(class IMatRenderContext __near *,int,int,struct MorphWeight_t const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMorph::RenderMorphWeights(
        CMorph *this,
        IMesh *pRenderContext,
        int nRenderId,
        int nWeightCount,
        const MorphWeight_t *pWeights)
{
  int m_nMaxMorphTargetCount; // eax
  int v8; // edi
  void *v9; // esp
  int v10; // ebx
  ITextureInternal_vtbl *v11; // edx
  ITextureInternal *m_pMorphWeightTexture; // esi
  int v13; // eax
  float v14; // xmm0_4
  IMesh *(__thiscall *AccessRawHardwareDataStream)(IMatRenderContext *, bool, IMesh *, IMesh *, IMaterial *); // eax
  IMesh *v16; // esi
  int v17; // edi
  const MorphWeight_t *v18; // esi
  int v19; // ecx
  float *v20; // eax
  float *v21; // eax
  int m_nVertexCount; // eax
  int v23[3]; // [esp+0h] [ebp-214h] BYREF
  CMeshBuilder meshBuilder; // [esp+10h] [ebp-204h] BYREF
  int y; // [esp+1F8h] [ebp-1Ch]
  int *pWeightIndices; // [esp+1FCh] [ebp-18h]
  int nIndexCount; // [esp+200h] [ebp-14h]
  float flOOHeight; // [esp+204h] [ebp-10h]
  int v29; // [esp+210h] [ebp-4h]
  IMesh *pMesh; // [esp+21Ch] [ebp+8h]
  int nWidth; // [esp+220h] [ebp+Ch]
  float nWidtha; // [esp+220h] [ebp+Ch]
  int h; // [esp+224h] [ebp+10h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CMorph::RenderMorphWeights",
    a3: 0,
    a4: "HW Morphing",
    a5: false,
    a6: 4);
  m_nMaxMorphTargetCount = this->m_nMaxMorphTargetCount;
  v29 = 0;
  if ( m_nMaxMorphTargetCount == 0 )
    goto LABEL_2;
  v8 = nWeightCount;
  if ( nWeightCount >= m_nMaxMorphTargetCount )
    v8 = m_nMaxMorphTargetCount;
  memcpy(dst: (unsigned __int8 *)this->m_pRenderMorphWeight, src: (unsigned __int8 *)pWeights, count: 16 * v8);
  if ( this->m_nMaxMorphTargetCount - nWeightCount > 0 )
    memset(
      dst: (unsigned __int8 *)&this->m_pRenderMorphWeight[v8],
      value: 0,
      count: 16 * (this->m_nMaxMorphTargetCount - nWeightCount));
  v9 = alloca(4 * v8);
  pWeightIndices = v23;
  nIndexCount = CMorph::BuildNonZeroMorphList(this, pWeightIndices: v23, nWeightCount: v8, pWeights);
  if ( nIndexCount != 0 )
  {
    if ( s_MorphMgr.m_bUsingConstantRegisters )
    {
      v29 = -1;
    }
    else
    {
      h = s_MorphMgr.m_nWeightHeight;
      v10 = nRenderId / s_MorphMgr.m_nSubrectVerticalCount * s_MorphMgr.m_nWeightWidth;
      v11 = s_MorphMgr.m_pMorphWeightTexture->__vftable;
      y = nRenderId % s_MorphMgr.m_nSubrectVerticalCount * s_MorphMgr.m_nWeightHeight;
      m_pMorphWeightTexture = s_MorphMgr.m_pMorphWeightTexture;
      nWidth = ((int (*)(void))v11->GetActualWidth)();
      v13 = m_pMorphWeightTexture->GetActualHeight(this: m_pMorphWeightTexture);
      v14 = 1.0;
      if ( nWidth != 0 )
        nWidtha = 1.0 / (float)nWidth;
      else
        nWidtha = 1.0;
      if ( v13 != 0 )
        v14 = 1.0 / (float)v13;
      flOOHeight = v14;
      CMeshBuilder::CMeshBuilder(this: &meshBuilder);
      AccessRawHardwareDataStream = (IMesh *(__thiscall *)(IMatRenderContext *, bool, IMesh *, IMesh *, IMaterial *))pRenderContext->IVertexBuffer::__vftable[1].AccessRawHardwareDataStream;
      LOBYTE(v29) = 1;
      v16 = AccessRawHardwareDataStream(
              this: (IMatRenderContext *)pRenderContext,
              a2: true,
              a3: nullptr,
              a4: nullptr,
              a5: nullptr);
      meshBuilder.m_pMesh = v16;
      meshBuilder.m_bGenerateIndices = true;
      meshBuilder.m_Type = MATERIAL_POINTS;
      pMesh = v16;
      v16->SetPrimitiveType(this: v16, a2: MATERIAL_POINTS);
      meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v8, a3: v8, a4: &meshBuilder, a5: nullptr);
      meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
      meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v16->IIndexBuffer;
      meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
      meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v8;
      meshBuilder.m_IndexBuilder.m_bModify = false;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      CVertexBuilder::AttachBegin(
        this: &meshBuilder.m_VertexBuilder,
        pMesh: v16,
        nMaxVertexCount: v8,
        desc: &meshBuilder);
      v17 = 0;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
      if ( nIndexCount > 0 )
      {
        do
        {
          v18 = &pWeights[pWeightIndices[v17]];
          v19 = y + pWeightIndices[v17] % h;
          v20 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
          *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float)(v10 + pWeightIndices[v17] / h) * nWidtha;
          v20[1] = (float)v19 * flOOHeight;
          v21 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
          *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = v18->m_pWeight[0];
          v21[1] = v18->m_pWeight[1];
          v21[2] = v18->m_pWeight[2];
          v21[3] = v18->m_pWeight[3];
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          ++v17;
        }
        while ( v17 < nIndexCount );
        v16 = pMesh;
      }
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
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
      meshBuilder.m_pMesh = nullptr;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      v16->Draw_2(this: v16, a2: -1, a3: 0);
      LOBYTE(v29) = 0;
      CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
      v29 = -1;
    }
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 1;
  }
  else
  {
LABEL_2:
    v29 = -1;
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10052C70
// Name: public: void CMorph::AccumulateMorph(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMorph::AccumulateMorph(CMorph *this, int nRenderId)
{
  int m_nMaxMorphTargetCount; // esi
  void *v4; // esp
  int v5; // eax
  int v6; // edx
  int v7; // ecx
  int v8; // eax
  IMatRenderContext *v9; // eax
  IMatRenderContext *v10; // esi
  void (__thiscall *Bind)(IMatRenderContext *, IMaterial *, void *); // eax
  void (__thiscall *EndRender)(IMatRenderContext *); // eax
  int (__thiscall *Release)(struct IMatRenderContext *); // eax
  IMaterial *m_pMaterial; // [esp-8h] [ebp-30h]
  int v15[3]; // [esp+0h] [ebp-28h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+10h] [ebp-18h]
  int nTotalQuadCount; // [esp+14h] [ebp-14h]
  int nTargetCount; // [esp+18h] [ebp-10h]
  int v19; // [esp+24h] [ebp-4h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CMorph::AccumulateMorph",
    a3: 0,
    a4: "HW Morphing",
    a5: false,
    a6: 4);
  m_nMaxMorphTargetCount = this->m_nMaxMorphTargetCount;
  v19 = 0;
  v4 = alloca(4 * m_nMaxMorphTargetCount);
  v5 = CMorph::BuildNonZeroMorphList(
         this,
         pWeightIndices: v15,
         nWeightCount: m_nMaxMorphTargetCount,
         pWeights: this->m_pRenderMorphWeight);
  v6 = 0;
  v7 = 0;
  nTargetCount = v5;
  if ( v5 > 0 )
  {
    do
    {
      v8 = this->m_MorphTargetIdToQuadIndex.m_Memory.m_pMemory[v15[v7]];
      if ( v8 >= 0 )
        v6 += this->m_MorphQuads.m_Memory.m_pMemory[v8].m_Size;
      ++v7;
    }
    while ( v7 < nTargetCount );
    nTotalQuadCount = v6;
    if ( v6 != 0 && this->m_nTextureWidth != 0 && this->m_nTextureHeight != 0 )
    {
      v9 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
      v10 = v9;
      pRenderContext.m_pObject = v9;
      LOBYTE(v19) = 1;
      if ( v9 != nullptr )
        v9->BeginRender(this: v9);
      m_pMaterial = this->m_MorphAccumulationMaterial.m_pMaterial;
      Bind = v10->Bind;
      LOBYTE(v19) = 2;
      Bind(this: v10, a2: m_pMaterial, a3: nullptr);
      CMorph::RenderMorphQuads(
        this,
        pRenderContext: v10,
        nRenderId,
        nTotalQuadCount,
        nWeightCount: nTargetCount,
        pWeightLookup: v15,
        pWeights: this->m_pRenderMorphWeight);
      EndRender = v10->EndRender;
      LOBYTE(v19) = 3;
      EndRender(this: v10);
      Release = v10->Release;
      LOBYTE(v19) = 0;
      Release(this: v10);
    }
  }
  v19 = -1;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10052DB0
// Name: public: virtual void CMorphMgr::BeginMorphAccumulation(class IMorphMgrRenderContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMorphMgr::BeginMorphAccumulation(CMorphMgr *this, IMorphMgrRenderContext *pIRenderContext)
{
  IMatRenderContext *v3; // eax
  IMatRenderContext *v4; // esi

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CMorph::BeginMorphAccumulation",
    a3: 0,
    a4: "HW Morphing",
    a5: false,
    a6: 4);
  *(_DWORD *)pIRenderContext = 0;
  v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  v4 = v3;
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  this->m_pPrevMaterial = v4->GetCurrentMaterial(this: v4);
  this->m_pPrevProxy = v4->GetCurrentProxy(this: v4);
  this->m_nPrevBoneCount = v4->GetCurrentNumBones(this: v4);
  this->m_nPrevClipMode = v4->GetHeightClipMode(this: v4);
  this->m_bPrevClippingEnabled = v4->EnableClipping(this: v4, a2: false);
  this->m_bFlashlightMode = v4->GetFlashlightMode(this: v4);
  v4->SetHeightClipMode(this: v4, a2: MATERIAL_HEIGHTCLIPMODE_DISABLE);
  v4->SetNumBoneWeights(this: v4, a2: 0);
  v4->SetFlashlightMode(this: v4, a2: false);
  if ( !this->m_bUsingConstantRegisters )
    v4->PushRenderTargetAndViewport_3(this: v4, a2: this->m_pMorphWeightTexture);
  v4->EndRender(this: v4);
  v4->Release(this: v4);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10052F00
// Name: public: virtual void CMorphMgr::EndMorphAccumulation(class IMorphMgrRenderContext __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMorphMgr::EndMorphAccumulation(CMorphMgr *this, IMorphMgrRenderContext *pIRenderContext)
{
  IMatRenderContext *v3; // eax
  IMatRenderContext *v4; // esi
  int v5; // ebx
  int v6; // ebx
  int nHeight; // [esp+14h] [ebp-10h]
  CMorph **nHeighta; // [esp+14h] [ebp-10h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CMorph::EndMorphAccumulation",
    a3: 0,
    a4: "HW Morphing",
    a5: false,
    a6: 4);
  if ( (_S1_1 & 1) == 0 )
  {
    _S1_1 |= 1u;
    counter_1.m_pCounter = CVProfile::FindOrCreateCounter(
                             this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                             a2: "HW Morph Count",
                             a3: COUNTER_GROUP_DEFAULT);
    atexit(func: CMorphMgr::EndMorphAccumulation_::_4_::_dynamic_atexit_destructor_for___counter__);
  }
  *counter_1.m_pCounter += *(_DWORD *)pIRenderContext;
  v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  v4 = v3;
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  v5 = this->m_pMorphAccumTexture->GetActualWidth(this: this->m_pMorphAccumTexture);
  nHeight = this->m_pMorphAccumTexture->GetActualHeight(this: this->m_pMorphAccumTexture);
  if ( this->m_bUsingConstantRegisters )
  {
    v4->PushRenderTargetAndViewport_3(this: v4, a2: this->m_pMorphAccumTexture);
  }
  else
  {
    v4->SetRenderTargetEx(this: v4, a2: 0, a3: this->m_pMorphAccumTexture);
    v4->Viewport(this: v4, a2: 0, a3: 0, a4: v5, a5: nHeight);
  }
  v4->ClearColor4ub(this: v4, a2: 0, a3: 0, a4: 0, a5: 0);
  v4->ClearBuffers(this: v4, a2: true, a3: false, a4: false);
  v6 = 0;
  if ( *(_DWORD *)pIRenderContext > 0 )
  {
    nHeighta = (CMorph **)&pIRenderContext[4];
    do
      CMorph::AccumulateMorph(this: *nHeighta++, nRenderId: v6++);
    while ( v6 < *(_DWORD *)pIRenderContext );
  }
  v4->PopRenderTargetAndViewport(this: v4);
  v4->Bind(this: v4, a2: this->m_pPrevMaterial, a3: this->m_pPrevProxy);
  v4->SetNumBoneWeights(this: v4, a2: this->m_nPrevBoneCount);
  v4->SetHeightClipMode(this: v4, a2: this->m_nPrevClipMode);
  v4->EnableClipping(this: v4, a2: this->m_bPrevClippingEnabled);
  v4->SetFlashlightMode(this: v4, a2: this->m_bFlashlightMode);
  v4->EndRender(this: v4);
  v4->Release(this: v4);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10053100
// Name: public: virtual void CMorphMgr::AccumulateMorph(class IMorphMgrRenderContext __near *,class IMorph __near *,int,struct MorphWeight_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMorphMgr::AccumulateMorph(
        CMorphMgr *this,
        IMorphMgrRenderContext *pIRenderContext,
        CMorph *pMorph,
        int nMorphCount,
        const MorphWeight_t *pWeights)
{
  IMesh *v6; // esi

  if ( *(_DWORD *)pIRenderContext < 4 )
  {
    v6 = (IMesh *)g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    if ( v6 != nullptr )
      v6->IsDynamic(this: v6);
    if ( !this->m_bUsingConstantRegisters )
      v6->ValidateData(this: v6, a2: (int)this->m_pRenderMorphWeight, a3: nullptr);
    if ( CMorph::RenderMorphWeights(
           this: pMorph,
           pRenderContext: v6,
           nRenderId: *(_DWORD *)pIRenderContext,
           nWeightCount: nMorphCount,
           pWeights) != 0 )
      *(_DWORD *)&pIRenderContext[4 * (*(_DWORD *)pIRenderContext)++ + 4] = pMorph;
    if ( v6 != nullptr )
    {
      ((void (__thiscall *)(IMesh *))v6->BeginCastBuffer)(a1: v6);
      v6->GetVertexFormat(this: v6);
    }
  }
  else
  {
    _Warning(a1: "Attempted to morph too many meshes in a single model!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100531F0
// Name: public: int CUtlSortVector<struct CVertexMorphDict::MorphVertexList_t,class CVertexMorphDict::VertexMorphDictLess>::Find(struct CVertexMorphDict::MorphVertexList_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CVertexMorphDict::MorphVertexList_t,CVertexMorphDict::VertexMorphDictLess>::Find(
        CUtlSortVector<CVertexMorphDict::MorphVertexList_t,CVertexMorphDict::VertexMorphDictLess> *this,
        const CVertexMorphDict::MorphVertexList_t *src)
{
  int v3; // esi
  int v4; // ecx
  CVertexMorphDict::MorphVertexList_t *m_pMemory; // ebx
  int m_nMorphTargetId; // edi
  int result; // eax
  int v8; // edx

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
         215,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1\\utlsortvector.h",
                            a2: 215,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
      a2: 215);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    m_nMorphTargetId = src->m_nMorphTargetId;
    do
    {
      result = (v4 + v3) >> 1;
      v8 = m_pMemory[result].m_nMorphTargetId;
      if ( m_nMorphTargetId <= v8 )
      {
        if ( m_nMorphTargetId >= v8 )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
    }
    while ( v3 <= v4 );
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100532A0
// Name: private: int CMorph::ComputeMorphTextureSizeInBytes(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMorph::ComputeMorphTextureSizeInBytes(CMorph *this)
{
  int v2; // esi
  unsigned int m_Format; // eax
  int v4; // ebx

  v2 = 0;
  if ( this->m_pMorphTexture[0] != nullptr )
  {
    m_Format = this->m_Format;
    v4 = (m_Format & 5) != 0;
    if ( (m_Format & 2) != 0 )
      ++v4;
    v2 = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGBA16161616)->m_nNumBytes
       * v4
       * this->m_nTextureWidth
       * this->m_nTextureHeight;
  }
  if ( this->m_pMorphTexture[1] != nullptr )
    v2 += ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGBA8888)->m_nNumBytes
        * this->m_nTextureWidth
        * this->m_nTextureHeight;
  return v2 + 20 * CMorph::CountStaticMeshVertices(this);
}

//------------------------------------------------------------------------------
// Address: 0x10053310
// Name: private: void CMorph::CleanUp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMorph::CleanUp(CMorph *this)
{
  IMatRenderContext *v2; // ebx
  IMaterial *m_pMaterial; // esi
  ITextureInternal **m_pMorphTexture; // esi
  int i; // [esp+Ch] [ebp-10h]

  v2 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  s_MorphMgr.m_nTotalMorphSizeInBytes -= CMorph::ComputeMorphTextureSizeInBytes(this);
  m_pMaterial = this->m_MorphAccumulationMaterial.m_pMaterial;
  CMaterialReference::Shutdown(this: &this->m_MorphAccumulationMaterial, bDeleteIfUnreferenced: false);
  if ( m_pMaterial != nullptr )
    m_pMaterial->DeleteIfUnreferenced(this: m_pMaterial);
  if ( this->m_pMorphBuffer != nullptr )
  {
    v2->DestroyStaticMesh(this: v2, a2: this->m_pMorphBuffer);
    this->m_pMorphBuffer = nullptr;
  }
  m_pMorphTexture = this->m_pMorphTexture;
  for ( i = 2; i != 0; --i )
  {
    if ( *m_pMorphTexture != nullptr )
    {
      (*m_pMorphTexture)->SetTextureRegenerator(this: *m_pMorphTexture, a2: nullptr, a3: true);
      (*m_pMorphTexture)->DecrementReferenceCount(this: *m_pMorphTexture);
      (*m_pMorphTexture)->DeleteIfUnreferenced(this: *m_pMorphTexture);
      *m_pMorphTexture = nullptr;
    }
    ++m_pMorphTexture;
  }
  if ( this->m_pRenderMorphWeight != nullptr )
  {
    free(pMem: (void *)this->m_pRenderMorphWeight);
    this->m_pRenderMorphWeight = nullptr;
  }
  this->m_nMaxMorphTargetCount = 0;
  if ( v2 != nullptr )
  {
    v2->EndRender(this: v2);
    v2->Release(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053440
// Name: public: int CUtlSortVector<struct MorphVertexInfo_t,class CVertexMorphDict::CMorphVertexListLess>::InsertNoSort(struct MorphVertexInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<MorphVertexInfo_t,CVertexMorphDict::CMorphVertexListLess>::InsertNoSort(
        CUtlSortVector<MorphVertexInfo_t,CVertexMorphDict::CMorphVertexListLess> *this,
        const MorphVertexInfo_t *src)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  MorphVertexInfo_t *m_pMemory; // ecx
  int v6; // eax
  MorphVertexInfo_t *v7; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  this->m_bNeedsSort = true;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<MorphVertexInfo_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: (void *)&m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 44 * v6);
  v7 = &this->m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = *src;
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100534E0
// Name: public: CVertexMorphDict::MorphVertexList_t::~MorphVertexList_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexMorphDict::MorphVertexList_t::~MorphVertexList_t(CVertexMorphDict::MorphVertexList_t *this)
{
  CUtlSortVector<MorphVertexInfo_t,CVertexMorphDict::CMorphVertexListLess> *p_m_MorphInfo; // esi
  MorphVertexInfo_t *m_pMemory; // eax

  p_m_MorphInfo = &this->m_MorphInfo;
  this->m_MorphInfo.m_Size = 0;
  if ( this->m_MorphInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_MorphInfo->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)p_m_MorphInfo->m_Memory.m_pMemory);
      p_m_MorphInfo->m_Memory.m_pMemory = nullptr;
    }
    p_m_MorphInfo->m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = p_m_MorphInfo->m_Memory.m_pMemory;
  p_m_MorphInfo->m_pElements = p_m_MorphInfo->m_Memory.m_pMemory;
  if ( p_m_MorphInfo->m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)m_pMemory);
      p_m_MorphInfo->m_Memory.m_pMemory = nullptr;
    }
    p_m_MorphInfo->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053570
// Name: public: void CVertexMorphDict::SortDeltas(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexMorphDict::SortDeltas(CVertexMorphDict *this)
{
  int v2; // esi
  int m_Size; // edi
  CUtlSortVector<MorphVertexInfo_t,CVertexMorphDict::CMorphVertexListLess> *p_m_MorphInfo; // eax
  signed int v5; // ecx
  void *m_pLessContext; // edx
  MorphVertexInfo_t *m_pMemory; // eax
  _DWORD context[2]; // [esp+4h] [ebp-Ch] BYREF
  char v9; // [esp+Fh] [ebp-1h] BYREF

  if ( this->m_MorphLists.m_Size > 0 )
  {
    v2 = 0;
    m_Size = this->m_MorphLists.m_Size;
    do
    {
      p_m_MorphInfo = &this->m_MorphLists.m_Memory.m_pMemory[v2].m_MorphInfo;
      if ( this->m_MorphLists.m_Memory.m_pMemory[v2].m_MorphInfo.m_bNeedsSort )
      {
        v5 = this->m_MorphLists.m_Memory.m_pMemory[v2].m_MorphInfo.m_Size;
        this->m_MorphLists.m_Memory.m_pMemory[v2].m_MorphInfo.m_bNeedsSort = false;
        if ( v5 > 1 )
        {
          m_pLessContext = p_m_MorphInfo->m_pLessContext;
          m_pMemory = p_m_MorphInfo->m_Memory.m_pMemory;
          context[0] = m_pLessContext;
          context[1] = &v9;
          qsort_s(
            base: (void *)m_pMemory,
            num: v5,
            width: 0x2Cu,
            comp: (int (__cdecl *)(void *, const void *, const void *))CUtlSortVector<MorphVertexInfo_t,CVertexMorphDict::CMorphVertexListLess>::CompareHelper,
            context);
        }
      }
      ++v2;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100535E0
// Name: private: void CMorph::BuildSegmentList(class CUtlVector<class CUtlVector<struct CMorph::MorphSegment_t,class CUtlMemory<struct CMorph::MorphSegment_t,int>>,class CUtlMemory<class CUtlVector<struct CMorph::MorphSegment_t,class CUtlMemory<struct CMorph::MorphSegment_t,int>>,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMorph::BuildSegmentList(
        CMorph *this,
        CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MissingMaterial_t,int>,int> *morphSegments)
{
  CMorph *v2; // edi
  int m_Size; // ecx
  int v4; // ebx
  int v5; // eax
  int v6; // edx
  int v7; // esi
  int m_nMorphTargetId; // ecx
  int v9; // ecx
  MorphWeight_t *v10; // eax
  int m_nMaxMorphTargetCount; // ebx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // ebx
  int v18; // eax
  CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> > *v19; // ecx
  int v20; // eax
  CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> > *v21; // ecx
  CUtlMemory<ResourceEntryInfo,int> *v22; // esi
  __int16 v23; // dx
  int m_nVertexId; // ecx
  MorphVertexInfo_t *v25; // ebx
  ResourceEntryInfo *v26; // edi
  int v27; // eax
  ResourceEntryInfo *v28; // ecx
  int v29; // eax
  ResourceEntryInfo *v30; // edi
  int v31; // eax
  bool v32; // zf
  ResourceEntryInfo *v33; // ebx
  int v34; // eax
  ResourceEntryInfo *v35; // ecx
  int v36; // eax
  ResourceEntryInfo *v37; // ebx
  int segment; // [esp+14h] [ebp-34h]
  unsigned int segment_4; // [esp+18h] [ebp-30h]
  int v40; // [esp+1Ch] [ebp-2Ch]
  int nDestTextureHeight; // [esp+20h] [ebp-28h]
  int nMorphTargetCount; // [esp+24h] [ebp-24h]
  int i; // [esp+28h] [ebp-20h]
  int v44; // [esp+2Ch] [ebp-1Ch]
  CMorph *v45; // [esp+30h] [ebp-18h]
  int nSrcIndex; // [esp+34h] [ebp-14h]
  int j; // [esp+38h] [ebp-10h]

  v2 = this;
  m_Size = this->m_MorphDict.m_MorphLists.m_Size;
  v4 = 0;
  nDestTextureHeight = s_MorphMgr.m_nAccumulatorHeight;
  v5 = 0;
  v45 = v2;
  v2->m_nMaxMorphTargetCount = 0;
  nMorphTargetCount = m_Size;
  if ( m_Size > 0 )
  {
    v6 = 0;
    do
    {
      v7 = v2->m_MorphDict.m_MorphLists.m_Size;
      if ( v5 < v7 )
        m_nMorphTargetId = v2->m_MorphDict.m_MorphLists.m_Memory.m_pMemory[v6].m_nMorphTargetId;
      else
        m_nMorphTargetId = -1;
      if ( v4 <= m_nMorphTargetId )
      {
        if ( v5 < v7 )
          v9 = v2->m_MorphDict.m_MorphLists.m_Memory.m_pMemory[v6].m_nMorphTargetId;
        else
          v9 = -1;
        v4 = v9 + 1;
        v2->m_nMaxMorphTargetCount = v9 + 1;
      }
      ++v5;
      ++v6;
    }
    while ( v5 < nMorphTargetCount );
  }
  v10 = (MorphWeight_t *)MemAlloc_Alloc(
                           nSize: (unsigned __int64)(unsigned int)v2->m_nMaxMorphTargetCount >> 28 != 0
                         ? -1
                         : 16 * v2->m_nMaxMorphTargetCount);
  m_nMaxMorphTargetCount = v2->m_nMaxMorphTargetCount;
  v2->m_pRenderMorphWeight = v10;
  v2->m_MorphTargetIdToQuadIndex.m_Size = 0;
  if ( m_nMaxMorphTargetCount != 0 )
  {
    m_nAllocationCount = v2->m_MorphTargetIdToQuadIndex.m_Memory.m_nAllocationCount;
    if ( m_nMaxMorphTargetCount > m_nAllocationCount )
      CUtlMemory<IMaterialVar *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&v2->m_MorphTargetIdToQuadIndex,
        num: m_nMaxMorphTargetCount - m_nAllocationCount);
    v2->m_MorphTargetIdToQuadIndex.m_Size += m_nMaxMorphTargetCount;
    m_pMemory = v2->m_MorphTargetIdToQuadIndex.m_Memory.m_pMemory;
    v14 = v2->m_MorphTargetIdToQuadIndex.m_Size - m_nMaxMorphTargetCount;
    v2->m_MorphTargetIdToQuadIndex.m_pElements = m_pMemory;
    if ( v14 > 0 && m_nMaxMorphTargetCount > 0 )
      _V_memmove(dest: &m_pMemory[m_nMaxMorphTargetCount], src: m_pMemory, count: 4 * v14);
  }
  memset(
    dst: (unsigned __int8 *)v2->m_MorphTargetIdToQuadIndex.m_Memory.m_pMemory,
    value: 0xFFu,
    count: 4 * v2->m_nMaxMorphTargetCount);
  v15 = 0;
  nSrcIndex = 0;
  i = 0;
  if ( nMorphTargetCount > 0 )
  {
    for ( j = 0; ; ++j )
    {
      if ( v15 < v2->m_MorphDict.m_MorphLists.m_Size )
        v16 = v2->m_MorphDict.m_MorphLists.m_Memory.m_pMemory[j].m_nMorphTargetId;
      else
        v16 = -1;
      v2->m_MorphTargetIdToQuadIndex.m_Memory.m_pMemory[v16] = v15;
      v17 = (int)morphSegments[1].m_pMemory;
      v18 = morphSegments->m_nAllocationCount;
      if ( v17 + 1 > v18 )
        CUtlMemory<CMatRenderContextBase::PlaneStackElement,int>::Grow(this: morphSegments, num: v17 - v18 + 1);
      ++morphSegments[1].m_pMemory;
      v19 = (CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> > *)morphSegments->m_pMemory;
      v20 = (int)morphSegments[1].m_pMemory - v17 - 1;
      morphSegments[1].m_nAllocationCount = (int)morphSegments->m_pMemory;
      if ( v20 > 0 )
        _V_memmove(dest: &v19[v17 + 1], src: &v19[v17], count: 20 * v20);
      v21 = (CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> > *)&morphSegments->m_pMemory[v17];
      if ( v21 != nullptr )
      {
        v21->m_Memory.m_pMemory = nullptr;
        v21->m_Memory.m_nAllocationCount = 0;
        v21->m_Memory.m_nGrowSize = 0;
        v21->m_Size = 0;
        v21->m_pElements = nullptr;
      }
      v22 = (CUtlMemory<ResourceEntryInfo,int> *)&morphSegments->m_pMemory[v17];
      v23 = 0;
      m_nVertexId = -1;
      HIWORD(segment_4) = 0;
      if ( v2->m_MorphDict.m_MorphLists.m_Memory.m_pMemory[j].m_MorphInfo.m_Size > 0 )
        break;
LABEL_55:
      if ( ++i >= nMorphTargetCount )
        return;
      v15 = i;
    }
    v44 = 0;
    v40 = v2->m_MorphDict.m_MorphLists.m_Memory.m_pMemory[j].m_MorphInfo.m_Size;
    while ( 1 )
    {
      v25 = &v2->m_MorphDict.m_MorphLists.m_Memory.m_pMemory[j].m_MorphInfo.m_Memory.m_pMemory[v44];
      if ( v23 != 0 )
      {
        if ( m_nVertexId < 0
          || v25->m_nVertexId > m_nVertexId + 12
          || v25->m_nVertexId / nDestTextureHeight != m_nVertexId / nDestTextureHeight )
        {
          v26 = v22[1].m_pMemory;
          v27 = v22->m_nAllocationCount;
          if ( (int)&v26->eType + 1 > v27 )
            CUtlMemory<CMorph::MorphSegment_t,int>::Grow(this: v22, num: (int)&v26->___u0 - v27 + 1);
          ++v22[1].m_pMemory;
          v28 = v22->m_pMemory;
          v29 = (char *)v22[1].m_pMemory - (char *)v26 - 1;
          v22[1].m_nAllocationCount = (int)v22->m_pMemory;
          if ( v29 > 0 )
            _V_memmove(dest: &v28[(int)v26 + 1], src: &v28[(_DWORD)v26], count: 8 * v29);
          v30 = &v22->m_pMemory[(_DWORD)v26];
          if ( v30 != nullptr )
          {
            v30->eType = segment;
            v30->resData = segment_4;
          }
          v2 = v45;
          goto LABEL_43;
        }
        v2 = v45;
        v23 = HIWORD(segment_4);
      }
      if ( m_nVertexId >= 0 )
      {
        v31 = v25->m_nVertexId - m_nVertexId;
        v23 += v31;
        nSrcIndex += v31;
        goto LABEL_47;
      }
LABEL_43:
      segment = nSrcIndex;
      LOWORD(segment_4) = v25->m_nVertexId;
      v23 = 1;
      ++nSrcIndex;
LABEL_47:
      ++v44;
      v32 = v40-- == 1;
      m_nVertexId = v25->m_nVertexId;
      HIWORD(segment_4) = v23;
      if ( v32 )
      {
        if ( v23 != 0 )
        {
          v33 = v22[1].m_pMemory;
          v34 = v22->m_nAllocationCount;
          if ( (int)&v33->eType + 1 > v34 )
            CUtlMemory<CMorph::MorphSegment_t,int>::Grow(this: v22, num: (int)&v33->___u0 - v34 + 1);
          ++v22[1].m_pMemory;
          v35 = v22->m_pMemory;
          v36 = (char *)v22[1].m_pMemory - (char *)v33 - 1;
          v22[1].m_nAllocationCount = (int)v22->m_pMemory;
          if ( v36 > 0 )
            _V_memmove(dest: &v35[(int)v33 + 1], src: &v35[(_DWORD)v33], count: 8 * v36);
          v37 = &v22->m_pMemory[(_DWORD)v33];
          if ( v37 != nullptr )
          {
            v37->eType = segment;
            v37->resData = segment_4;
          }
        }
        goto LABEL_55;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053900
// Name: public: int CUtlSortVector<struct CVertexMorphDict::MorphVertexList_t,class CVertexMorphDict::VertexMorphDictLess>::Insert(struct CVertexMorphDict::MorphVertexList_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CVertexMorphDict::MorphVertexList_t,CVertexMorphDict::VertexMorphDictLess>::Insert(
        CUtlSortVector<CVertexMorphDict::MorphVertexList_t,CVertexMorphDict::VertexMorphDictLess> *this,
        const CVertexMorphDict::MorphVertexList_t *src)
{
  int LessOrEqual; // eax
  int m_nAllocationCount; // ecx
  int v5; // edi
  int m_Size; // eax
  CVertexMorphDict::MorphVertexList_t *m_pMemory; // ecx
  int v8; // eax
  CVertexMorphDict::MorphVertexList_t *v9; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
         150,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1\\utlsortvector.h",
                            a2: 150,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
      a2: 150);
  }
  LessOrEqual = CUtlSortVector<CVertexMorphDict::MorphVertexList_t,CVertexMorphDict::VertexMorphDictLess>::FindLessOrEqual(
                  this,
                  src);
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  v5 = LessOrEqual + 1;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CVertexMorphDict::MorphVertexList_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - v5 - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 32 * v8);
  v9 = &this->m_Memory.m_pMemory[v5];
  if ( v9 != nullptr )
  {
    v9->m_nMorphTargetId = src->m_nMorphTargetId;
    v9->m_MorphInfo.m_Memory.m_pMemory = nullptr;
    v9->m_MorphInfo.m_Memory.m_nAllocationCount = 0;
    v9->m_MorphInfo.m_Memory.m_nGrowSize = 0;
    v9->m_MorphInfo.m_Size = 0;
    v9->m_MorphInfo.m_pElements = nullptr;
    v9->m_MorphInfo.m_pLessContext = nullptr;
    v9->m_MorphInfo.m_bNeedsSort = false;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10053BB0
// Name: public: void CVertexMorphDict::AddMorph(struct MorphVertexInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexMorphDict::AddMorph(CVertexMorphDict *this, const MorphVertexInfo_t *info)
{
  int m_nMorphTargetId; // eax
  int v4; // eax
  MorphVertexInfo_t *m_pMemory; // eax
  CVertexMorphDict::MorphVertexList_t find; // [esp+Ch] [ebp-2Ch] BYREF
  int v7; // [esp+34h] [ebp-4h]

  memset(&find.m_MorphInfo, 0, 25);
  m_nMorphTargetId = info->m_nMorphTargetId;
  v7 = 0;
  find.m_nMorphTargetId = m_nMorphTargetId;
  v4 = CUtlSortVector<CVertexMorphDict::MorphVertexList_t,CVertexMorphDict::VertexMorphDictLess>::Find(
         this: &this->m_MorphLists,
         src: &find);
  if ( v4 == -1 )
  {
    CUtlSortVector<CVertexMorphDict::MorphVertexList_t,CVertexMorphDict::VertexMorphDictLess>::Insert(
      this: &this->m_MorphLists,
      src: &find);
    v4 = CUtlSortVector<CVertexMorphDict::MorphVertexList_t,CVertexMorphDict::VertexMorphDictLess>::Find(
           this: &this->m_MorphLists,
           src: &find);
  }
  CUtlSortVector<MorphVertexInfo_t,CVertexMorphDict::CMorphVertexListLess>::InsertNoSort(
    this: &this->m_MorphLists.m_Memory.m_pMemory[v4].m_MorphInfo,
    src: info);
  m_pMemory = find.m_MorphInfo.m_Memory.m_pMemory;
  v7 = 1;
  find.m_MorphInfo.m_Size = 0;
  if ( find.m_MorphInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( find.m_MorphInfo.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)find.m_MorphInfo.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      find.m_MorphInfo.m_Memory.m_pMemory = nullptr;
    }
    find.m_MorphInfo.m_Memory.m_nAllocationCount = 0;
  }
  find.m_MorphInfo.m_pElements = m_pMemory;
  v7 = -1;
  if ( find.m_MorphInfo.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10053CA0
// Name: public: virtual void CMorph::AddMorph(struct MorphVertexInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMorph::AddMorph(CMorph *this, const MorphVertexInfo_t *info)
{
  CVertexMorphDict::AddMorph(this: &this->m_MorphDict, info);
}

//------------------------------------------------------------------------------
// Address: 0x10053CB0
// Name: private: void CMorph::BuildQuadList(class CUtlVector<class CUtlVector<struct CMorph::MorphSegment_t,class CUtlMemory<struct CMorph::MorphSegment_t,int>>,class CUtlMemory<class CUtlVector<struct CMorph::MorphSegment_t,class CUtlMemory<struct CMorph::MorphSegment_t,int>>,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMorph::BuildQuadList(
        CMorph *this,
        const CUtlVector<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,CUtlMemory<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,int> > *morphSegments)
{
  CMorph *v2; // esi
  int v3; // edi
  int m_nAllocationCount; // eax
  CUtlVector<CMorph::MorphQuad_t,CUtlMemory<CMorph::MorphQuad_t,int> > *m_pMemory; // ecx
  int v6; // eax
  CUtlVector<CMorph::MorphQuad_t,CUtlMemory<CMorph::MorphQuad_t,int> > *v7; // ecx
  CUtlMemory<CVTFTexture::ResourceMemorySection,int> *v8; // esi
  CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> > *v9; // eax
  int m_nFirstSrc; // ecx
  int m_nCount; // edi
  int v12; // ebx
  int v13; // eax
  CVTFTexture::ResourceMemorySection *v14; // edi
  CVTFTexture::ResourceMemorySection *v15; // edx
  int v16; // eax
  int v17; // eax
  int nSegmentCount; // [esp+10h] [ebp-34h]
  const CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> > *segmentList; // [esp+14h] [ebp-30h]
  int m_Size; // [esp+18h] [ebp-2Ch]
  int nTotalCount; // [esp+1Ch] [ebp-28h]
  int nDest; // [esp+20h] [ebp-24h]
  int nQuadIndex; // [esp+24h] [ebp-20h]
  int v25; // [esp+2Ch] [ebp-18h]
  int j; // [esp+30h] [ebp-14h]
  int nSrc; // [esp+34h] [ebp-10h]

  v2 = this;
  CUtlVector<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int>>,CUtlMemory<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int>>,int>>::RemoveAll(this: (CUtlVector<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,CUtlMemory<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,int> > *)&this->m_MorphQuads);
  nQuadIndex = 0;
  if ( morphSegments->m_Size > 0 )
  {
    v25 = 0;
    m_Size = morphSegments->m_Size;
    while ( 1 )
    {
      v3 = v2->m_MorphQuads.m_Size;
      m_nAllocationCount = v2->m_MorphQuads.m_Memory.m_nAllocationCount;
      if ( v3 + 1 > m_nAllocationCount )
        CUtlMemory<CMatRenderContextBase::PlaneStackElement,int>::Grow(
          this: (CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MissingMaterial_t,int>,int> *)&v2->m_MorphQuads,
          num: v3 - m_nAllocationCount + 1);
      ++v2->m_MorphQuads.m_Size;
      m_pMemory = v2->m_MorphQuads.m_Memory.m_pMemory;
      v6 = v2->m_MorphQuads.m_Size - v3 - 1;
      v2->m_MorphQuads.m_pElements = m_pMemory;
      if ( v6 > 0 )
        _V_memmove(dest: &m_pMemory[v3 + 1], src: &m_pMemory[v3], count: 20 * v6);
      v7 = &v2->m_MorphQuads.m_Memory.m_pMemory[v3];
      if ( v7 != nullptr )
      {
        v7->m_Memory.m_pMemory = nullptr;
        v7->m_Memory.m_nAllocationCount = 0;
        v7->m_Memory.m_nGrowSize = 0;
        v7->m_Size = 0;
        v7->m_pElements = nullptr;
      }
      v8 = (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&v2->m_MorphQuads.m_Memory.m_pMemory[v3];
      v9 = &morphSegments->m_Memory.m_pMemory[v25];
      segmentList = v9;
      nSegmentCount = v9->m_Size;
      j = 0;
      if ( nSegmentCount > 0 )
      {
        while ( 1 )
        {
          m_nFirstSrc = v9->m_Memory.m_pMemory[j].m_nFirstSrc;
          m_nCount = v9->m_Memory.m_pMemory[j].m_nCount;
          nSrc = m_nFirstSrc;
          nDest = v9->m_Memory.m_pMemory[j].m_nFirstDest;
          while ( 1 )
          {
            v12 = this->m_nTextureHeight * (m_nFirstSrc / this->m_nTextureHeight + 1) - m_nFirstSrc;
            if ( v12 >= m_nCount )
              v12 = m_nCount;
            v13 = v8->m_nAllocationCount;
            nTotalCount = m_nCount - v12;
            v14 = v8[1].m_pMemory;
            if ( (int)&v14->m_nDataAllocSize + 1 > v13 )
            {
              CUtlMemory<CMorph::MorphQuad_t,int>::Grow(this: v8, num: (int)&v14->m_nDataAllocSize - v13 + 1);
              m_nFirstSrc = nSrc;
            }
            ++v8[1].m_pMemory;
            v15 = v8->m_pMemory;
            v16 = (char *)v8[1].m_pMemory - (char *)v14 - 1;
            v8[1].m_nAllocationCount = (int)v8->m_pMemory;
            if ( v16 > 0 )
            {
              _V_memmove(dest: &v15[(int)v14 + 1], src: &v15[(_DWORD)v14], count: 12 * v16);
              m_nFirstSrc = nSrc;
            }
            v17 = (int)&v8->m_pMemory[(_DWORD)v14];
            *(_WORD *)(v17 + 8) = nQuadIndex++;
            *(_DWORD *)v17 = m_nFirstSrc;
            *(_WORD *)(v17 + 4) = nDest;
            m_nFirstSrc += v12;
            *(_WORD *)(v17 + 6) = v12;
            nSrc = m_nFirstSrc;
            nDest += v12;
            if ( nTotalCount <= 0 )
              break;
            m_nCount = nTotalCount;
          }
          if ( ++j >= nSegmentCount )
            break;
          v9 = (CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> > *)segmentList;
        }
      }
      ++v25;
      if ( --m_Size == 0 )
        break;
      v2 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053F20
// Name: public: virtual void CMorph::Lock(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMorph::Lock(CMorph *this, float flFloatToFixedScale)
{
  CVertexMorphDict::MorphVertexList_t *m_pMemory; // ecx

  this->m_bLocked = true;
  CMorph::CleanUp(this);
  this->m_flFloatToFixedScale = flFloatToFixedScale;
  CUtlVector<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int>>,CUtlMemory<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int>>,int>>::RemoveAll(this: (CUtlVector<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,CUtlMemory<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,int> > *)&this->m_MorphQuads);
  if ( this->m_MorphQuads.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_MorphQuads.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_MorphQuads.m_Memory.m_pMemory);
      this->m_MorphQuads.m_Memory.m_pMemory = nullptr;
    }
    this->m_MorphQuads.m_Memory.m_nAllocationCount = 0;
  }
  this->m_MorphQuads.m_pElements = this->m_MorphQuads.m_Memory.m_pMemory;
  this->m_MorphTargetIdToQuadIndex.m_Size = 0;
  CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int>>::RemoveAll(this: &this->m_MorphDict.m_MorphLists);
  if ( this->m_MorphDict.m_MorphLists.m_Memory.m_nGrowSize < 0 )
  {
    this->m_MorphDict.m_MorphLists.m_pElements = this->m_MorphDict.m_MorphLists.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_MorphDict.m_MorphLists.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_MorphDict.m_MorphLists.m_Memory.m_pMemory);
      this->m_MorphDict.m_MorphLists.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_MorphDict.m_MorphLists.m_Memory.m_pMemory;
    this->m_MorphDict.m_MorphLists.m_Memory.m_nAllocationCount = 0;
    this->m_MorphDict.m_MorphLists.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054070
// Name: public: CVertexMorphDict::~CVertexMorphDict(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CVertexMorphDict::~CVertexMorphDict(CVertexMorphDict *this)
{
  CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int>>::~CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int>>(this: &this->m_MorphLists);
}

//------------------------------------------------------------------------------
// Address: 0x10054080
// Name: public: CMorph::~CMorph(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMorph::~CMorph(CMorph *this)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_MorphTargetIdToQuadIndex; // esi
  int *m_pMemory; // eax

  this->IMorphInternal::IMorph::__vftable = (CMorph_vtbl *)&CMorph::`vftable'{for `IMorphInternal'};
  this->ITextureRegenerator::__vftable = (ITextureRegenerator_vtbl *)&CMorph::`vftable'{for `ITextureRegenerator'};
  CMorph::CleanUp(this);
  CMaterialReference::~CMaterialReference(this: &this->m_MorphAccumulationMaterial);
  p_m_MorphTargetIdToQuadIndex = &this->m_MorphTargetIdToQuadIndex;
  this->m_MorphTargetIdToQuadIndex.m_Size = 0;
  if ( this->m_MorphTargetIdToQuadIndex.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_MorphTargetIdToQuadIndex->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_MorphTargetIdToQuadIndex->m_Memory.m_pMemory);
      p_m_MorphTargetIdToQuadIndex->m_Memory.m_pMemory = nullptr;
    }
    this->m_MorphTargetIdToQuadIndex.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = p_m_MorphTargetIdToQuadIndex->m_Memory.m_pMemory;
  this->m_MorphTargetIdToQuadIndex.m_pElements = this->m_MorphTargetIdToQuadIndex.m_Memory.m_pMemory;
  if ( this->m_MorphTargetIdToQuadIndex.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      p_m_MorphTargetIdToQuadIndex->m_Memory.m_pMemory = nullptr;
    }
    this->m_MorphTargetIdToQuadIndex.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int>>,CUtlMemory<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int>>,int>>::~CUtlVector<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int>>,CUtlMemory<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int>>,int>>(this: (CUtlVector<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,CUtlMemory<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,int> > *)&this->m_MorphQuads);
  CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int>>::~CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int>>(this: &this->m_MorphDict.m_MorphLists);
}

//------------------------------------------------------------------------------
// Address: 0x10054150
// Name: private: void CMorph::PackMorphData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMorph::PackMorphData(CMorph *this)
{
  unsigned int m_Format; // ecx
  int v3; // eax
  ITextureInternal **m_pMorphTexture; // edi
  int i; // ebx
  char pTemp[512]; // [esp+8h] [ebp-220h] BYREF
  CUtlVector<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,CUtlMemory<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,int> > morphSegments; // [esp+208h] [ebp-20h] BYREF
  int v8; // [esp+224h] [ebp-4h]

  memset(&morphSegments, 0, sizeof(morphSegments));
  v8 = 0;
  CMorph::BuildSegmentList(
    this,
    (CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MissingMaterial_t,int>,int> *)&morphSegments);
  CMorph::ComputeTextureDimensions(this, &morphSegments);
  CMorph::BuildQuadList(this, &morphSegments);
  if ( this->m_nTextureWidth != 0 && this->m_nTextureHeight != 0 )
  {
    if ( (this->m_Format & 7) != 0 )
    {
      V_snprintf(pDest: pTemp, maxLen: 512, pFormat: "__morphtarget[%d]: pos/norm", CMorph::s_nUniqueId);
      m_Format = this->m_Format;
      v3 = (m_Format & 5) != 0;
      if ( (m_Format & 2) != 0 )
        ++v3;
      this->m_pMorphTexture[0] = (ITextureInternal *)((int (__stdcall *)(char *, const char *, int, int, int, int))g_pMaterialSystem->CreateProceduralTexture)(
                                                       a1: pTemp,
                                                       a2: "Morph Targets",
                                                       a3: v3 * this->m_nTextureWidth,
                                                       a4: this->m_nTextureHeight,
                                                       a5: 25,
                                                       a6: 393997);
    }
    if ( (this->m_Format & 0x18) != 0 )
    {
      V_snprintf(pDest: pTemp, maxLen: 512, pFormat: "__morphtarget[%d]: side/speed", CMorph::s_nUniqueId);
      this->m_pMorphTexture[1] = (ITextureInternal *)g_pMaterialSystem->CreateProceduralTexture(
                                                       this: g_pMaterialSystem,
                                                       a2: pTemp,
                                                       a3: "Morph Targets",
                                                       a4: this->m_nTextureWidth,
                                                       a5: this->m_nTextureHeight,
                                                       a6: 0,
                                                       a7: 393997);
    }
    m_pMorphTexture = this->m_pMorphTexture;
    for ( i = 2; i != 0; --i )
    {
      if ( *m_pMorphTexture != nullptr )
      {
        (*m_pMorphTexture)->SetTextureRegenerator(this: *m_pMorphTexture, a2: &this->ITextureRegenerator, a3: true);
        (*m_pMorphTexture)->Download(this: *m_pMorphTexture, a2: nullptr, a3: 0);
      }
      ++m_pMorphTexture;
    }
    CMorph::CreateAccumulatorMaterial(this, nMaterialIndex: CMorph::s_nUniqueId);
    ++CMorph::s_nUniqueId;
    CMorph::CreateStaticMesh(this);
    v8 = -1;
    CUtlVector<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int>>,CUtlMemory<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int>>,int>>::~CUtlVector<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int>>,CUtlMemory<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int>>,int>>(this: &morphSegments);
  }
  else
  {
    v8 = -1;
    CUtlVector<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int>>,CUtlMemory<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int>>,int>>::~CUtlVector<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int>>,CUtlMemory<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int>>,int>>(this: &morphSegments);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054310
// Name: public: virtual void CMorph::Unlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMorph::Unlock(CMorph *this)
{
  CVertexMorphDict::SortDeltas(this: &this->m_MorphDict);
  CMorph::PackMorphData(this);
  this->m_bLocked = false;
  s_MorphMgr.m_nTotalMorphSizeInBytes += CMorph::ComputeMorphTextureSizeInBytes(this);
}

//------------------------------------------------------------------------------
// Address: 0x10054340
// Name: public: virtual class IMorphInternal __near * CMorphMgr::CreateMorph(void)
// Source: json
//------------------------------------------------------------------------------
CMaterialReference *__thiscall CMorphMgr::CreateMorph(CMorphMgr *this)
{
  CMaterialReference *v1; // eax
  CMaterialReference *v2; // esi

  v1 = (CMaterialReference *)MemAlloc_Alloc(nSize: 0x78u);
  v2 = v1;
  if ( v1 == nullptr )
    return nullptr;
  v1[1].m_pMaterial = (IMaterial *)&ITextureRegenerator::`vftable';
  v1->m_pMaterial = (IMaterial *)&CMorph::`vftable'{for `IMorphInternal'};
  v1[1].m_pMaterial = (IMaterial *)&CMorph::`vftable'{for `ITextureRegenerator'};
  v1[2].m_pMaterial = nullptr;
  v1[3].m_pMaterial = nullptr;
  v1[4].m_pMaterial = nullptr;
  v1[5].m_pMaterial = nullptr;
  v1[6].m_pMaterial = nullptr;
  v1[7].m_pMaterial = nullptr;
  LOBYTE(v1[8].m_pMaterial) = 0;
  v1[14].m_pMaterial = nullptr;
  v1[15].m_pMaterial = nullptr;
  v1[16].m_pMaterial = nullptr;
  v1[17].m_pMaterial = nullptr;
  v1[18].m_pMaterial = nullptr;
  v1[19].m_pMaterial = nullptr;
  v1[20].m_pMaterial = nullptr;
  v1[21].m_pMaterial = nullptr;
  v1[22].m_pMaterial = nullptr;
  v1[23].m_pMaterial = nullptr;
  CMaterialReference::CMaterialReference(
    this: v1 + 26,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  *(_QWORD *)&v2[11].m_pMaterial = 0;
  v2[13].m_pMaterial = nullptr;
  v2[28].m_pMaterial = nullptr;
  v2[29].m_pMaterial = nullptr;
  LOBYTE(v2[9].m_pMaterial) = 0;
  v2[10].m_pMaterial = nullptr;
  v2[25].m_pMaterial = nullptr;
  v2[24].m_pMaterial = nullptr;
  v2[27].m_pMaterial = (IMaterial *)1065353216;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10054420
// Name: public: virtual void CMorphMgr::DestroyMorph(class IMorphInternal __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMorphMgr::DestroyMorph(CMorphMgr *this, CMorph *pMorphData)
{
  if ( pMorphData != nullptr )
  {
    CMorph::~CMorph(this: pMorphData);
    free(pMem: pMorphData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028C770
// Name: _CMorphMgr::EndMorphAccumulation_::_4_::_dynamic_atexit_destructor_for___counter__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMorphMgr::EndMorphAccumulation_::_4_::_dynamic_atexit_destructor_for___counter__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1028C780
// Name: _dynamic_atexit_destructor_for__s_ActiveMorphHisto__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ActiveMorphHisto__()
{
  int *m_pMemory; // eax

  m_pMemory = s_ActiveMorphHisto.m_Memory.m_pMemory;
  s_ActiveMorphHisto.m_Size = 0;
  if ( s_ActiveMorphHisto.m_Memory.m_nGrowSize >= 0 )
  {
    if ( s_ActiveMorphHisto.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: s_ActiveMorphHisto.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      s_ActiveMorphHisto.m_Memory.m_pMemory = nullptr;
    }
    s_ActiveMorphHisto.m_Memory.m_nAllocationCount = 0;
  }
  s_ActiveMorphHisto.m_pElements = m_pMemory;
  if ( s_ActiveMorphHisto.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      s_ActiveMorphHisto.m_Memory.m_pMemory = nullptr;
    }
    s_ActiveMorphHisto.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028C820
// Name: _dynamic_atexit_destructor_for__s_RenderedQuadHisto__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_RenderedQuadHisto__()
{
  int *m_pMemory; // eax

  m_pMemory = s_RenderedQuadHisto.m_Memory.m_pMemory;
  s_RenderedQuadHisto.m_Size = 0;
  if ( s_RenderedQuadHisto.m_Memory.m_nGrowSize >= 0 )
  {
    if ( s_RenderedQuadHisto.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: s_RenderedQuadHisto.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      s_RenderedQuadHisto.m_Memory.m_pMemory = nullptr;
    }
    s_RenderedQuadHisto.m_Memory.m_nAllocationCount = 0;
  }
  s_RenderedQuadHisto.m_pElements = m_pMemory;
  if ( s_RenderedQuadHisto.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      s_RenderedQuadHisto.m_Memory.m_pMemory = nullptr;
    }
    s_RenderedQuadHisto.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028C8C0
// Name: _dynamic_atexit_destructor_for__s_RenderedTexelHisto__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_RenderedTexelHisto__()
{
  int *m_pMemory; // eax

  m_pMemory = s_RenderedTexelHisto.m_Memory.m_pMemory;
  s_RenderedTexelHisto.m_Size = 0;
  if ( s_RenderedTexelHisto.m_Memory.m_nGrowSize >= 0 )
  {
    if ( s_RenderedTexelHisto.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: s_RenderedTexelHisto.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      s_RenderedTexelHisto.m_Memory.m_pMemory = nullptr;
    }
    s_RenderedTexelHisto.m_Memory.m_nAllocationCount = 0;
  }
  s_RenderedTexelHisto.m_pElements = m_pMemory;
  if ( s_RenderedTexelHisto.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      s_RenderedTexelHisto.m_Memory.m_pMemory = nullptr;
    }
    s_RenderedTexelHisto.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028C960
// Name: _dynamic_atexit_destructor_for__s_OcclusionQueryMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_OcclusionQueryMgr__()
{
  CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::BlockHeader_t *v1; // [esp-4h] [ebp-8h]

  CUtlLinkedList<COcclusionQueryMgr::OcclusionQueryObject_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int>>>::RemoveAll(this: &s_OcclusionQueryMgr.m_OcclusionQueryObjects);
  m_pBlocks = s_OcclusionQueryMgr.m_OcclusionQueryObjects.m_Memory.m_pBlocks;
  if ( s_OcclusionQueryMgr.m_OcclusionQueryObjects.m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v1 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1);
    }
    while ( m_pBlocks != nullptr );
    s_OcclusionQueryMgr.m_OcclusionQueryObjects.m_Memory.m_pBlocks = nullptr;
    s_OcclusionQueryMgr.m_OcclusionQueryObjects.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028C9A0
// Name: _dynamic_atexit_destructor_for__mat_showenvmapmask__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_showenvmapmask__()
{
  ConVar::~ConVar(this: &mat_showenvmapmask);
}

//------------------------------------------------------------------------------
// Address: 0x1028C9B0
// Name: _dynamic_atexit_destructor_for__mat_debugdepth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_debugdepth__()
{
  ConVar::~ConVar(this: &mat_debugdepth);
}

//------------------------------------------------------------------------------
// Address: 0x1028C9C0
// Name: _dynamic_atexit_destructor_for__s_ShaderSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ShaderSystem__()
{
  if ( s_ShaderSystem.m_BufferedLoggingListener.m_StoredSpew.m_Memory.m_nGrowSize >= 0 )
  {
    if ( s_ShaderSystem.m_BufferedLoggingListener.m_StoredSpew.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(
        this: _g_pMemAlloc,
        a2: s_ShaderSystem.m_BufferedLoggingListener.m_StoredSpew.m_Memory.m_pMemory);
      s_ShaderSystem.m_BufferedLoggingListener.m_StoredSpew.m_Memory.m_pMemory = nullptr;
    }
    s_ShaderSystem.m_BufferedLoggingListener.m_StoredSpew.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int>>::~CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int>>(this: &s_ShaderSystem.m_ShaderDLLs);
}

//------------------------------------------------------------------------------
// Address: 0x1028CA40
// Name: _dynamic_atexit_destructor_for__s_TextureManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_TextureManager__()
{
  CTextureManager::~CTextureManager(this: &s_TextureManager);
}
