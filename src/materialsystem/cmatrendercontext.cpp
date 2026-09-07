// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/cmatrendercontext.cpp
// Functions: 275
// ============================================================

#include "materialsystem\cmatrendercontext.h"

//------------------------------------------------------------------------------
// Address: 0x1002AEE0
// Name: public: virtual bool CMatRenderContext::IsCullingEnabledForSinglePassFlashlight(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatRenderContext::IsCullingEnabledForSinglePassFlashlight(CMatQueuedRenderContext *this)
{
  return (*((_BYTE *)&this->CMatRenderContextBase + 492) & 0x40) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002B0B0
// Name: public: virtual float CMatRenderContextBase::Knob(char __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CMatRenderContextBase::Knob(CMatQueuedRenderContext *this, char *knobname, float *setvalue)
{
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10043120
// Name: public: void CVertexBuilder::AttachBegin(class IMesh __near *,int,struct MeshDesc_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBuilder::AttachBegin(
        CVertexBuilder *this,
        IMesh *pMesh,
        int nMaxVertexCount,
        const MeshDesc_t *desc)
{
  bool v4; // zf

  this->m_pVertexBuffer = pMesh;
  this->VertexDesc_t = desc->VertexDesc_t;
  this->m_nMaxVertexCount = nMaxVertexCount;
  this->m_NumBoneWeights = this->m_NumBoneWeights != 0 ? 2 : 0;
  v4 = this->m_nBufferOffset == -1;
  this->m_nVertexCount = 0;
  this->m_bModify = false;
  if ( v4 )
  {
    this->m_nTotalVertexCount = 0;
    this->m_nBufferOffset = desc->VertexDesc_t::m_nOffset;
    this->m_nBufferFirstVertex = desc->m_nFirstVertex;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10043190
// Name: public: void CVertexBuilder::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBuilder::Reset(CVertexBuilder *this)
{
  float *m_pNormal; // edx
  float *v2; // edx
  float *v3; // eax
  float *v4; // edx
  float *v5; // eax
  float *v6; // edx
  float *v7; // eax
  float *v8; // edx

  m_pNormal = this->m_pNormal;
  this->m_pCurrPosition = this->m_pPosition;
  this->m_nCurrentVertex = 0;
  this->m_pCurrNormal = m_pNormal;
  v2 = this->m_pTexCoord[1];
  this->m_pCurrTexCoord[0] = this->m_pTexCoord[0];
  v3 = this->m_pTexCoord[2];
  this->m_pCurrTexCoord[1] = v2;
  v4 = this->m_pTexCoord[3];
  this->m_pCurrTexCoord[2] = v3;
  v5 = this->m_pTexCoord[4];
  this->m_pCurrTexCoord[3] = v4;
  v6 = this->m_pTexCoord[5];
  this->m_pCurrTexCoord[4] = v5;
  v7 = this->m_pTexCoord[6];
  this->m_pCurrTexCoord[5] = v6;
  v8 = this->m_pTexCoord[7];
  this->m_pCurrTexCoord[6] = v7;
  this->m_pCurrTexCoord[7] = v8;
  this->m_pCurrColor = this->m_pColor;
}

//------------------------------------------------------------------------------
// Address: 0x10043210
// Name: public: CIndexBuilder::~CIndexBuilder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIndexBuilder::~CIndexBuilder(CIndexBuilder *this)
{
  if ( this->m_pIndexBuffer != nullptr && this->m_pIndexBuffer->IsDynamic(this: this->m_pIndexBuffer) )
    this->m_pIndexBuffer->EndCastBuffer(this: this->m_pIndexBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x10043240
// Name: public: void CIndexBuilder::GenerateIndices(enum MaterialPrimitiveType_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIndexBuilder::GenerateIndices(
        CIndexBuilder *this,
        MaterialPrimitiveType_t primitiveType,
        int nIndexCount)
{
  int v4; // edi
  unsigned __int16 *v5; // eax
  int m_nCurrentIndex; // eax

  if ( this->m_nIndexSize != 0 )
  {
    v4 = nIndexCount;
    if ( this->m_nMaxIndexCount - this->m_nCurrentIndex < nIndexCount )
      v4 = this->m_nMaxIndexCount - this->m_nCurrentIndex;
    if ( v4 != 0 )
    {
      v5 = &this->m_pIndices[this->m_nCurrentIndex];
      switch ( primitiveType )
      {
        case MATERIAL_POINTS:
        case MATERIAL_INSTANCED_QUADS:
          break;
        case MATERIAL_LINE_STRIP:
          GenerateLineStripIndexBuffer(pIndices: v5, nIndexCount: v4, nFirstVertex: this->m_nIndexOffset);
          break;
        case MATERIAL_LINE_LOOP:
          GenerateLineLoopIndexBuffer(pIndices: v5, nIndexCount: v4, nFirstVertex: this->m_nIndexOffset);
          break;
        case MATERIAL_POLYGON:
          GeneratePolygonIndexBuffer(pIndices: v5, nIndexCount: v4, nFirstVertex: this->m_nIndexOffset);
          break;
        case MATERIAL_QUADS:
          GenerateQuadIndexBuffer(pIndices: v5, nIndexCount: v4, nFirstVertex: this->m_nIndexOffset);
          break;
        default:
          GenerateSequentialIndexBuffer(pIndices: v5, nIndexCount: v4, nFirstVertex: this->m_nIndexOffset);
          break;
      }
      this->m_nCurrentIndex += v4 * this->m_nIndexSize;
      m_nCurrentIndex = this->m_nCurrentIndex;
      if ( m_nCurrentIndex > this->m_nIndexCount )
        this->m_nIndexCount = m_nCurrentIndex;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10043310
// Name: public: CMeshBuilder::~CMeshBuilder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::~CMeshBuilder(CMeshBuilder *this)
{
  if ( this->m_VertexBuilder.m_pVertexBuffer != nullptr
    && this->m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: this->m_VertexBuilder.m_pVertexBuffer) )
  {
    this->m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: this->m_VertexBuilder.m_pVertexBuffer);
  }
  if ( this->m_IndexBuilder.m_pIndexBuffer != nullptr
    && this->m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: this->m_IndexBuilder.m_pIndexBuffer) )
  {
    this->m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: this->m_IndexBuilder.m_pIndexBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100433A0
// Name: public: CMeshBuilder::CMeshBuilder(void)
// Source: json
//------------------------------------------------------------------------------
CMeshBuilder *__thiscall CMeshBuilder::CMeshBuilder(CMeshBuilder *this)
{
  this->m_pMesh = nullptr;
  this->m_bGenerateIndices = false;
  this->m_IndexBuilder.m_pIndexBuffer = nullptr;
  this->m_IndexBuilder.m_nMaxIndexCount = 0;
  this->m_IndexBuilder.m_nIndexCount = 0;
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  this->m_IndexBuilder.m_nTotalIndexCount = 0;
  this->m_IndexBuilder.m_nBufferFirstIndex = 0;
  this->m_IndexBuilder.m_nBufferOffset = -1;
  this->m_VertexBuilder.m_pVertexBuffer = nullptr;
  this->m_VertexBuilder.m_nBufferOffset = -1;
  this->m_VertexBuilder.m_nBufferFirstVertex = 0;
  this->m_VertexBuilder.m_nVertexCount = 0;
  this->m_VertexBuilder.m_nCurrentVertex = 0;
  this->m_VertexBuilder.m_nMaxVertexCount = 0;
  this->m_VertexBuilder.m_nTotalVertexCount = 0;
  this->m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10043410
// Name: void SetupDirtyDiskReportFunc(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupDirtyDiskReportFunc()
{
  g_pFullFileSystem->InstallDirtyDiskReportFunc(this: g_pFullFileSystem, a2: CDummyMaterialSystem::EndBatch);
}

//------------------------------------------------------------------------------
// Address: 0x10043430
// Name: char const __near * COM_GetModDirectory(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl COM_GetModDirectory()
{
  int v0; // ecx
  int v1; // edi
  int v2; // ecx
  int *v3; // ebx
  int v4; // esi
  int v5; // eax
  const char *v6; // esi
  int v7; // eax
  int v8; // eax
  int v9; // eax

  if ( _V_strlen(str: modDir) != 0 )
    return modDir;
  v1 = _CommandLine(a1: v0);
  v3 = (int *)_CommandLine(a1: v2);
  v4 = *v3;
  v5 = (*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v1 + 32))(
         a1: v1,
         a2: "-defaultgamedir",
         a3: "hl2");
  v6 = (const char *)(*(int (__thiscall **)(int *, const char *, int))(v4 + 32))(a1: v3, a2: "-game", a3: v5);
  V_strncpy(pDest: modDir, pSrc: v6, maxLen: 260);
  strchr(string: (unsigned __int8 *)modDir, chr: 0x2Fu);
  if ( v7 != 0 || (strchr(string: (unsigned __int8 *)modDir, chr: 0x5Cu), v8 != 0) )
  {
    V_StripLastDir(dirName: modDir, maxlen: 260);
    v9 = _V_strlen(str: modDir);
    V_strncpy(pDest: modDir, pSrc: &v6[v9], maxLen: 260 - v9);
  }
  return modDir;
}

//------------------------------------------------------------------------------
// Address: 0x100434F0
// Name: public: enum InitReturnVal_t CMatRenderContextBase::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatRenderContextBase::Init(CMatRenderContextBase *this)
{
  unsigned int v1; // esi
  char *ModDirectory; // eax
  char *v3; // eax
  char *v4; // eax

  if ( CMatRenderContextBase::sm_nInitializeCount == 0 )
  {
    v1 = 2252800;
    ModDirectory = COM_GetModDirectory();
    if ( _V_stricmp(s1: "infested", s2: ModDirectory) != 0
      && (v3 = COM_GetModDirectory(), _V_stricmp(s1: "swarm", s2: v3) != 0) )
    {
      v4 = COM_GetModDirectory();
      if ( _V_stricmp(s1: "portal2", s2: v4) == 0 )
        v1 = 6758400;
    }
    else
    {
      v1 = 4505600;
    }
    CMemoryStack::Init(
      this: CMatRenderContextBase::sm_RenderData,
      pszAllocOwner: "CMatRenderContextBase::sm_RenderData[0]",
      maxSize: v1,
      commitSize: 0x8000u,
      initialCommit: 0,
      alignment: 0x20u);
    CMemoryStack::Init(
      this: &stru_1034D160,
      pszAllocOwner: "CMatRenderContextBase::sm_RenderData[1]",
      maxSize: v1,
      commitSize: 0x8000u,
      initialCommit: 0,
      alignment: 0x20u);
    CMatRenderContextBase::sm_nRenderStack = 0;
    CMatRenderContextBase::sm_nRenderLockCount = 0;
  }
  ++CMatRenderContextBase::sm_nInitializeCount;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100435B0
// Name: public: void CMatRenderContextBase::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::Shutdown(CMatRenderContextBase *this)
{
  if ( --CMatRenderContextBase::sm_nInitializeCount == 0 )
  {
    CMemoryStack::Term(this: CMatRenderContextBase::sm_RenderData);
    CMemoryStack::Term(this: &stru_1034D160);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100435D0
// Name: public: void CMatRenderContextBase::CompactMemory(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::CompactMemory(CMatRenderContextBase *this)
{
  if ( CMatRenderContextBase::sm_nRenderLockCount != 0 )
  {
    DevWarning(a1: "CMatRenderContext: Trying to compact with render data still locked!\n");
    CMatRenderContextBase::sm_nRenderLockCount = 0;
  }
  CMemoryStack::FreeAll(this: CMatRenderContextBase::sm_RenderData, bDecommit: true);
  CMemoryStack::FreeAll(this: &stru_1034D160, bDecommit: true);
}

//------------------------------------------------------------------------------
// Address: 0x10043610
// Name: public: virtual void CMatRenderContextBase::MarkRenderDataUnused(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::MarkRenderDataUnused(CMatRenderContextBase *this, bool bFrameBegin)
{
  int v2; // eax

  if ( CMatRenderContextBase::sm_nRenderLockCount != 0 )
  {
    DevWarning(
      a1: "CMatRenderContext: Trying to clear render data with render data still locked (%d)!\n",
      CMatRenderContextBase::sm_nRenderLockCount);
    CMatRenderContextBase::sm_nRenderLockCount = 0;
  }
  if ( bFrameBegin )
  {
    v2 = 1 - CMatRenderContextBase::sm_nRenderStack;
    CMatRenderContextBase::sm_nRenderStack = 1 - CMatRenderContextBase::sm_nRenderStack;
  }
  else
  {
    v2 = CMatRenderContextBase::sm_nRenderStack;
  }
  CMemoryStack::FreeAll(this: &CMatRenderContextBase::sm_RenderData[v2], bDecommit: false);
}

//------------------------------------------------------------------------------
// Address: 0x10043670
// Name: public: int CMatRenderContextBase::RenderDataSizeUsed(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CMatRenderContextBase::RenderDataSizeUsed(CMatRenderContextBase *this)
{
  return &CMatRenderContextBase::sm_RenderData[CMatRenderContextBase::sm_nRenderStack].m_pNextAlloc[-dword_1034D144[10 * CMatRenderContextBase::sm_nRenderStack]];
}

//------------------------------------------------------------------------------
// Address: 0x10043690
// Name: public: virtual bool CMatRenderContextBase::IsRenderData(void const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMatRenderContextBase::IsRenderData(CMatRenderContextBase *this, unsigned __int8 *pData)
{
  return pData == nullptr
      || (int)pData >= dword_1034D144[10 * CMatRenderContextBase::sm_nRenderStack]
      && (int)pData < (int)CMatRenderContextBase::sm_RenderData[CMatRenderContextBase::sm_nRenderStack].m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x100436E0
// Name: public: virtual void CMatRenderContextBase::Bind(class IMaterial __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::Bind(CMatRenderContextBase *this, IMaterialInternal *pMaterial, void *proxyData)
{
  IMaterialInternal *v4; // ecx
  IMaterialInternal *v5; // esi
  const char *v6; // eax

  v4 = pMaterial;
  if ( pMaterial == nullptr )
  {
    _Warning(a1: "Programming error: CMatRenderContextBase::Bind: NULL material\n");
    v4 = g_pErrorMaterial;
  }
  v5 = v4->GetRealTimeVersion(this: v4);
  if ( this->m_pCurrentMaterial == v5 )
  {
    this->m_pCurrentProxyData = proxyData;
  }
  else
  {
    if ( !v5->IsPrecached(this: v5) )
    {
      v6 = (const char *)v5->GetName(this: v5);
      DevWarning(a1: "Binding uncached material \"%s\", artificially incrementing refcount\n", v6);
      v5->ArtificialAddRef(this: v5);
      v5->Precache(this: v5);
    }
    this->m_pCurrentMaterial = v5;
    this->m_pCurrentProxyData = proxyData;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10043770
// Name: public: virtual void CMatRenderContextBase::BindLightmapPage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::BindLightmapPage(CMatRenderContextBase *this, int lightmapPageID)
{
  this->m_lightmapPageID = lightmapPageID;
}

//------------------------------------------------------------------------------
// Address: 0x10043780
// Name: public: virtual void CMatRenderContextBase::BindLocalCubemap(class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::BindLocalCubemap(CMatRenderContextBase *this, ITextureInternal *pTexture)
{
  ITextureInternal *v2; // eax

  v2 = pTexture;
  if ( pTexture == nullptr )
    v2 = g_pTextureManager->ErrorTexture(this: g_pTextureManager);
  this->m_pLocalCubemapTexture = v2;
}

//------------------------------------------------------------------------------
// Address: 0x100437B0
// Name: public: virtual class ITexture __near * CMatRenderContextBase::GetFrameBufferCopyTexture(int)
// Source: json
//------------------------------------------------------------------------------
ITexture *__thiscall CMatRenderContextBase::GetFrameBufferCopyTexture(
        CMatRenderContextBase *this,
        unsigned int textureIndex)
{
  if ( textureIndex > 4 )
    return nullptr;
  else
    return this->m_pCurrentFrameBufferCopyTexture[textureIndex];
}

//------------------------------------------------------------------------------
// Address: 0x100437D0
// Name: public: virtual void CMatRenderContextBase::LoadMatrix(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::LoadMatrix(CMatRenderContextBase *this, const VMatrix *matrix)
{
  MaterialMatrixMode_t m_MatrixMode; // eax

  VMatrix::operator=(this: &this->m_pCurMatrixItem->matrix, mOther: matrix);
  this->m_pCurMatrixItem->flags = 1;
  m_MatrixMode = this->m_MatrixMode;
  if ( m_MatrixMode != MATERIAL_VIEW )
  {
    if ( m_MatrixMode == MATERIAL_PROJECTION )
      *((_BYTE *)this + 492) |= 4u;
  }
  else
  {
    *((_BYTE *)this + 492) |= 6u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10043810
// Name: public: virtual void CMatRenderContextBase::LoadMatrix(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::LoadMatrix(CMatRenderContextBase *this, const matrix3x4_t *matrix)
{
  CMatRenderContextBase::MatrixStackItem_t *m_pCurMatrixItem; // eax
  MaterialMatrixMode_t m_MatrixMode; // eax

  m_pCurMatrixItem = this->m_pCurMatrixItem;
  *(matrix3x4_t *)&m_pCurMatrixItem->matrix.m[0][0] = *matrix;
  m_pCurMatrixItem->matrix.m[3][0] = 0.0;
  m_pCurMatrixItem->matrix.m[3][1] = 0.0;
  m_pCurMatrixItem->matrix.m[3][2] = 0.0;
  m_pCurMatrixItem->matrix.m[3][3] = 1.0;
  this->m_pCurMatrixItem->flags = 1;
  m_MatrixMode = this->m_MatrixMode;
  if ( m_MatrixMode != MATERIAL_VIEW )
  {
    if ( m_MatrixMode == MATERIAL_PROJECTION )
      *((_BYTE *)this + 492) |= 4u;
  }
  else
  {
    *((_BYTE *)this + 492) |= 6u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100438A0
// Name: public: virtual void CMatRenderContextBase::MultMatrix(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::MultMatrix(CMatRenderContextBase *this, const VMatrix *matrix)
{
  MaterialMatrixMode_t m_MatrixMode; // eax
  VMatrix result; // [esp+4h] [ebp-40h] BYREF

  MatrixMultiply(src1: matrix, src2: &this->m_pCurMatrixItem->matrix, dst: &result);
  VMatrix::operator=(this: &this->m_pCurMatrixItem->matrix, mOther: &result);
  this->m_pCurMatrixItem->flags = 1;
  m_MatrixMode = this->m_MatrixMode;
  if ( m_MatrixMode != MATERIAL_VIEW )
  {
    if ( m_MatrixMode == MATERIAL_PROJECTION )
      *((_BYTE *)this + 492) |= 4u;
  }
  else
  {
    *((_BYTE *)this + 492) |= 6u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10043900
// Name: public: virtual void CMatRenderContextBase::MultMatrixLocal(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::MultMatrixLocal(CMatRenderContextBase *this, const VMatrix *matrix)
{
  MaterialMatrixMode_t m_MatrixMode; // eax
  VMatrix result; // [esp+4h] [ebp-40h] BYREF

  MatrixMultiply(src1: &this->m_pCurMatrixItem->matrix, src2: matrix, dst: &result);
  VMatrix::operator=(this: &this->m_pCurMatrixItem->matrix, mOther: &result);
  this->m_pCurMatrixItem->flags = 1;
  m_MatrixMode = this->m_MatrixMode;
  if ( m_MatrixMode != MATERIAL_VIEW )
  {
    if ( m_MatrixMode == MATERIAL_PROJECTION )
      *((_BYTE *)this + 492) |= 4u;
  }
  else
  {
    *((_BYTE *)this + 492) |= 6u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10043960
// Name: public: virtual void CMatRenderContextBase::LoadIdentity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::LoadIdentity(CMatRenderContextBase *this)
{
  MaterialMatrixMode_t m_MatrixMode; // eax

  MatrixSetIdentity(dst: &this->m_pCurMatrixItem->matrix);
  this->m_pCurMatrixItem->flags = 3;
  m_MatrixMode = this->m_MatrixMode;
  if ( m_MatrixMode != MATERIAL_VIEW )
  {
    if ( m_MatrixMode == MATERIAL_PROJECTION )
      *((_BYTE *)this + 492) |= 4u;
  }
  else
  {
    *((_BYTE *)this + 492) |= 6u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100439A0
// Name: public: virtual void CMatRenderContextBase::Ortho(double,double,double,double,double,double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::Ortho(
        CMatRenderContextBase *this,
        long double left,
        long double top,
        long double right,
        long double bottom,
        long double zNear,
        long double zFar)
{
  CMatRenderContextBase::MatrixStackItem_t *m_pCurMatrixItem; // edi
  VMatrix mOther; // [esp+38h] [ebp-80h] BYREF
  VMatrix dst; // [esp+78h] [ebp-40h] BYREF

  m_pCurMatrixItem = this->m_pCurMatrixItem;
  MatrixBuildOrtho(&dst, left, top, right, bottom, zNear, zFar);
  MatrixMultiply(src1: &m_pCurMatrixItem->matrix, src2: &dst, dst: &mOther);
  VMatrix::operator=(this: &m_pCurMatrixItem->matrix, &mOther);
  this->m_pCurMatrixItem->flags = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10043A30
// Name: public: virtual void CMatRenderContextBase::PerspectiveX(double,double,double,double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::PerspectiveX(
        CMatRenderContextBase *this,
        long double flFovX,
        long double flAspect,
        long double flZNear,
        long double flZFar)
{
  CMatRenderContextBase::MatrixStackItem_t *m_pCurMatrixItem; // edi
  VMatrix mOther; // [esp+28h] [ebp-80h] BYREF
  VMatrix dst; // [esp+68h] [ebp-40h] BYREF

  m_pCurMatrixItem = this->m_pCurMatrixItem;
  MatrixBuildPerspectiveX(&dst, flFovX, flAspect, flZNear, flZFar);
  MatrixMultiply(src1: &m_pCurMatrixItem->matrix, src2: &dst, dst: &mOther);
  VMatrix::operator=(this: &m_pCurMatrixItem->matrix, &mOther);
  this->m_pCurMatrixItem->flags = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10043AB0
// Name: public: virtual void CMatRenderContextBase::PerspectiveOffCenterX(double,double,double,double,double,double,double,double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::PerspectiveOffCenterX(
        CMatRenderContextBase *this,
        long double flFovX,
        long double flAspect,
        long double flZNear,
        long double flZFar,
        long double bottom,
        long double top,
        long double left,
        long double right)
{
  CMatRenderContextBase::MatrixStackItem_t *m_pCurMatrixItem; // edi
  VMatrix mOther; // [esp+48h] [ebp-80h] BYREF
  VMatrix dst; // [esp+88h] [ebp-40h] BYREF

  m_pCurMatrixItem = this->m_pCurMatrixItem;
  MatrixBuildPerspectiveOffCenterX(&dst, flFovX, flAspect, flZNear, flZFar, bottom, top, left, right);
  MatrixMultiply(src1: &m_pCurMatrixItem->matrix, src2: &dst, dst: &mOther);
  VMatrix::operator=(this: &m_pCurMatrixItem->matrix, &mOther);
  this->m_pCurMatrixItem->flags = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10043B60
// Name: public: virtual void CMatRenderContextBase::PickMatrix(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::PickMatrix(CMatRenderContextBase *this, int x, int y, int nWidth, int nHeight)
{
  CMatRenderContextBase::MatrixStackItem_t *m_pCurMatrixItem; // eax
  float v7; // xmm2_4
  float v8; // xmm0_4
  MaterialMatrixMode_t m_MatrixMode; // eax
  VMatrix dst; // [esp+4h] [ebp-98h] BYREF
  VMatrix mat; // [esp+44h] [ebp-58h] BYREF
  int vheight; // [esp+84h] [ebp-18h] BYREF
  int vwidth; // [esp+88h] [ebp-14h] BYREF
  float py; // [esp+8Ch] [ebp-10h]
  int vx; // [esp+90h] [ebp-Ch] BYREF
  float px; // [esp+94h] [ebp-8h]
  int vy; // [esp+98h] [ebp-4h] BYREF
  float pw; // [esp+A4h] [ebp+8h]
  float ph; // [esp+A8h] [ebp+Ch]

  this->GetViewport(this, a2: &vx, a3: &vy, a4: &vwidth, a5: &vheight);
  px = (float)((float)((float)(x - vx) * 2.0) / (float)vwidth) - 1.0;
  py = (float)((float)((float)(y - vy) * 2.0) / (float)vheight) - 1.0;
  pw = (float)((float)nWidth * 2.0) / (float)vwidth;
  ph = (float)((float)nHeight * 2.0) / (float)vheight;
  MatrixSetIdentity(dst: &mat);
  m_pCurMatrixItem = this->m_pCurMatrixItem;
  v7 = 2.0 / pw;
  mat.m[0][0] = v7;
  v8 = 2.0 / ph;
  mat.m[1][1] = v8;
  mat.m[0][3] = (float)(px * -2.0) / pw;
  mat.m[1][3] = (float)(py * -2.0) / ph;
  MatrixMultiply(src1: &m_pCurMatrixItem->matrix, src2: &mat, &dst);
  VMatrix::operator=(this: &this->m_pCurMatrixItem->matrix, mOther: &dst);
  this->m_pCurMatrixItem->flags = 1;
  m_MatrixMode = this->m_MatrixMode;
  if ( m_MatrixMode != MATERIAL_VIEW )
  {
    if ( m_MatrixMode == MATERIAL_PROJECTION )
      *((_BYTE *)this + 492) |= 4u;
  }
  else
  {
    *((_BYTE *)this + 492) |= 6u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10043CE0
// Name: public: virtual void CMatRenderContextBase::Scale(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::Scale(CMatRenderContextBase *this, float x, float y, float z)
{
  MaterialMatrixMode_t m_MatrixMode; // eax
  VMatrix dst; // [esp+10h] [ebp-80h] BYREF
  VMatrix mat; // [esp+50h] [ebp-40h] BYREF

  MatrixBuildScale(dst: &mat, x, y, z);
  MatrixMultiply(src1: &this->m_pCurMatrixItem->matrix, src2: &mat, &dst);
  VMatrix::operator=(this: &this->m_pCurMatrixItem->matrix, mOther: &dst);
  this->m_pCurMatrixItem->flags = 1;
  m_MatrixMode = this->m_MatrixMode;
  if ( m_MatrixMode != MATERIAL_VIEW )
  {
    if ( m_MatrixMode == MATERIAL_PROJECTION )
      *((_BYTE *)this + 492) |= 4u;
  }
  else
  {
    *((_BYTE *)this + 492) |= 6u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10043D70
// Name: protected: void CMatRenderContextBase::RecomputeViewState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::RecomputeViewState(CMatRenderContextBase *this)
{
  char v2; // al
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm7_4
  float v8; // xmm2_4
  float v9; // xmm6_4
  float v10; // xmm7_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  matrix3x4_t viewMatrix; // [esp+4h] [ebp-30h] BYREF

  v2 = *((_BYTE *)this + 492);
  if ( (v2 & 2) != 0 )
  {
    *((_BYTE *)this + 492) = v2 & 0xFD;
    this->GetMatrix(this, a2: MATERIAL_VIEW, a3: &viewMatrix);
    v3 = viewMatrix.m_flMatVal[1][3];
    v4 = viewMatrix.m_flMatVal[0][3];
    v5 = viewMatrix.m_flMatVal[1][0];
    v6 = viewMatrix.m_flMatVal[0][0];
    v7 = viewMatrix.m_flMatVal[0][1] * viewMatrix.m_flMatVal[0][3];
    v8 = viewMatrix.m_flMatVal[2][3];
    this->m_vecViewOrigin.x = -(float)((float)((float)(viewMatrix.m_flMatVal[1][0] * viewMatrix.m_flMatVal[1][3])
                                             + (float)(viewMatrix.m_flMatVal[0][0] * viewMatrix.m_flMatVal[0][3]))
                                     + (float)(viewMatrix.m_flMatVal[2][0] * viewMatrix.m_flMatVal[2][3]));
    this->m_vecViewOrigin.y = -(float)((float)((float)(viewMatrix.m_flMatVal[1][1] * v3) + v7)
                                     + (float)(viewMatrix.m_flMatVal[2][1] * v8));
    v9 = viewMatrix.m_flMatVal[1][2];
    v10 = (float)(viewMatrix.m_flMatVal[1][2] * v3) + (float)(viewMatrix.m_flMatVal[0][2] * v4);
    v11 = viewMatrix.m_flMatVal[2][2];
    v12 = viewMatrix.m_flMatVal[2][0];
    this->m_vecViewOrigin.z = -(float)(v10 + (float)(viewMatrix.m_flMatVal[2][2] * v8));
    this->m_vecViewForward.x = v12;
    v13 = viewMatrix.m_flMatVal[2][1];
    this->m_vecViewForward.z = v11;
    this->m_vecViewForward.y = v13;
    this->m_vecViewForward.x = this->m_vecViewForward.x * -1.0;
    this->m_vecViewForward.y = this->m_vecViewForward.y * -1.0;
    v14 = viewMatrix.m_flMatVal[0][1];
    this->m_vecViewForward.z = this->m_vecViewForward.z * -1.0;
    *(_QWORD *)&this->m_vecViewRight.y = __PAIR64__(LODWORD(viewMatrix.m_flMatVal[0][2]), LODWORD(v14));
    v15 = viewMatrix.m_flMatVal[1][1];
    this->m_vecViewRight.x = v6;
    this->m_vecViewUp.x = v5;
    this->m_vecViewUp.y = v15;
    this->m_vecViewUp.z = v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10043F00
// Name: public: virtual void CMatRenderContextBase::GetWorldSpaceCameraPosition(class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::GetWorldSpaceCameraPosition(CMatRenderContextBase *this, Vector *pCameraPos)
{
  CMatRenderContextBase::RecomputeViewState(this);
  *pCameraPos = this->m_vecViewOrigin;
}

//------------------------------------------------------------------------------
// Address: 0x10043F30
// Name: public: virtual void CMatRenderContextBase::GetWorldSpaceCameraVectors(class Vector __near *,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::GetWorldSpaceCameraVectors(
        CMatRenderContextBase *this,
        Vector *pVecForward,
        Vector *pVecRight,
        Vector *pVecUp)
{
  CMatRenderContextBase::RecomputeViewState(this);
  if ( pVecForward != nullptr )
    *pVecForward = this->m_vecViewForward;
  if ( pVecRight != nullptr )
    *pVecRight = this->m_vecViewRight;
  if ( pVecUp != nullptr )
    *pVecUp = this->m_vecViewUp;
}

//------------------------------------------------------------------------------
// Address: 0x10043FB0
// Name: public: virtual void CMatRenderContextBase::UnlockRenderData(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::UnlockRenderData(CMatRenderContextBase *this, void *pData)
{
  this->ReleaseRenderData(this);
}

//------------------------------------------------------------------------------
// Address: 0x10043FC0
// Name: public: virtual void CMatRenderContextBase::AddRefRenderData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::AddRefRenderData(CMatRenderContextBase *this)
{
  ++CMatRenderContextBase::sm_nRenderLockCount;
}

//------------------------------------------------------------------------------
// Address: 0x10043FD0
// Name: public: virtual void CMatRenderContextBase::ReleaseRenderData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::ReleaseRenderData(CMatRenderContextBase *this)
{
  if ( --CMatRenderContextBase::sm_nRenderLockCount == 0 )
    this->OnRenderDataUnreferenced(this);
}

//------------------------------------------------------------------------------
// Address: 0x10043FF0
// Name: public: virtual void CMatRenderContextBase::SetHeightClipMode(enum MaterialHeightClipMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::SetHeightClipMode(
        CMatRenderContextBase *this,
        MaterialHeightClipMode_t heightClipMode)
{
  if ( this->m_HeightClipMode != heightClipMode )
  {
    this->m_HeightClipMode = heightClipMode;
    this->UpdateHeightClipUserClipPlane(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10044010
// Name: public: virtual void CMatRenderContextBase::SetHeightClipZ(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::SetHeightClipZ(CMatRenderContextBase *this, float z)
{
  void (*UpdateHeightClipUserClipPlane)(void); // edx

  if ( z != this->m_HeightClipZ )
  {
    UpdateHeightClipUserClipPlane = (void (*)(void))this->UpdateHeightClipUserClipPlane;
    this->m_HeightClipZ = z;
    UpdateHeightClipUserClipPlane();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10044040
// Name: public: virtual bool CMatRenderContextBase::EnableClipping(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatRenderContextBase::EnableClipping(CMatRenderContextBase *this, bool bEnable)
{
  CMatRenderContextBase_vtbl *v2; // eax

  if ( bEnable == ((*((_BYTE *)this + 492) & 8) != 0) )
    return bEnable;
  v2 = this->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable;
  *((_BYTE *)this + 492) ^= (*((_BYTE *)this + 492) ^ (8 * bEnable)) & 8;
  ((void (*)(void))v2->ApplyCustomClipPlanes)();
  return !bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x10044090
// Name: public: virtual float CMatRenderContextBase::ComputePixelDiameterOfSphere(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CMatRenderContextBase::ComputePixelDiameterOfSphere(
        CMatRenderContextBase *this,
        const Vector *vecAbsOrigin,
        float flRadius)
{
  const VMatrix *v4; // eax
  float x; // xmm0_4
  float y; // xmm2_4
  float v7; // xmm7_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  VMatrix v11; // [esp+4h] [ebp-110h] BYREF
  VMatrix v12; // [esp+44h] [ebp-D0h] BYREF
  VMatrix vm; // [esp+84h] [ebp-90h] BYREF
  int vwidth; // [esp+C4h] [ebp-50h] BYREF
  int vy; // [esp+C8h] [ebp-4Ch] BYREF
  int vx; // [esp+CCh] [ebp-48h] BYREF
  Vector4D testPoint2; // [esp+D0h] [ebp-44h] BYREF
  Vector4D testPoint1; // [esp+E0h] [ebp-34h] BYREF
  Vector4D clipPos2; // [esp+F0h] [ebp-24h] BYREF
  Vector4D clipPos1; // [esp+100h] [ebp-14h] BYREF
  int vheight; // [esp+110h] [ebp-4h] BYREF

  CMatRenderContextBase::RecomputeViewState(this);
  if ( (*((_BYTE *)this + 492) & 4) != 0 )
  {
    this->GetMatrix_2(this, a2: MATERIAL_VIEW, a3: &vm);
    this->GetMatrix_2(this, a2: MATERIAL_PROJECTION, a3: &v12);
    v4 = VMatrix::operator*(this: &v12, result: &v11, &vm);
    VMatrix::operator=(this: &this->m_viewProjMatrix, mOther: v4);
    *((_BYTE *)this + 492) &= ~4u;
  }
  x = this->m_vecViewUp.x;
  testPoint1.x = (float)(x * flRadius) + vecAbsOrigin->x;
  y = this->m_vecViewUp.y;
  testPoint1.y = (float)(y * flRadius) + vecAbsOrigin->y;
  v7 = (float)(this->m_vecViewUp.z * flRadius) + vecAbsOrigin->z;
  v8 = (float)(y * COERCE_FLOAT(LODWORD(flRadius) ^ _mask__NegFloat_)) + vecAbsOrigin->y;
  v9 = (float)(this->m_vecViewUp.z * COERCE_FLOAT(LODWORD(flRadius) ^ _mask__NegFloat_)) + vecAbsOrigin->z;
  testPoint2.x = (float)(x * COERCE_FLOAT(LODWORD(flRadius) ^ _mask__NegFloat_)) + vecAbsOrigin->x;
  testPoint1.z = v7;
  testPoint2.y = v8;
  testPoint2.z = v9;
  testPoint2.w = 1.0;
  testPoint1.w = 1.0;
  Vector4DMultiply(src1: &this->m_viewProjMatrix, src2: &testPoint1, dst: &clipPos1);
  Vector4DMultiply(src1: &this->m_viewProjMatrix, src2: &testPoint2, dst: &clipPos2);
  if ( clipPos1.w < 0.001 )
    clipPos1.y = clipPos1.y * 1000.0;
  else
    clipPos1.y = clipPos1.y / clipPos1.w;
  if ( clipPos2.w < 0.001 )
    clipPos2.y = clipPos2.y * 1000.0;
  else
    clipPos2.y = clipPos2.y / clipPos2.w;
  this->GetViewport(this, a2: &vx, a3: &vy, a4: &vwidth, a5: &vheight);
  return fabs(clipPos2.y - clipPos1.y) * (double)vheight * 0.5;
}

//------------------------------------------------------------------------------
// Address: 0x10044250
// Name: public: virtual class Vector CMatRenderContextBase::GetToneMappingScaleLinear(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CMatRenderContextBase::GetToneMappingScaleLinear(CMatRenderContextBase *this, Vector *result)
{
  bool v3; // zf
  Vector *v4; // eax
  float z; // ecx

  v3 = g_pHWConfig->GetHDRType(this: g_pHWConfig) == HDR_TYPE_NONE;
  v4 = result;
  if ( v3 )
  {
    result->x = 1.0;
    result->y = 1.0;
    result->z = 1.0;
  }
  else
  {
    z = this->m_LastSetToneMapScale.z;
    *(_QWORD *)&result->x = *(_QWORD *)&this->m_LastSetToneMapScale.x;
    result->z = z;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100442B0
// Name: public: enum InitReturnVal_t CMatRenderContext::Init(class CMaterialSystem __near *)
// Source: json
//------------------------------------------------------------------------------
InitReturnVal_t __thiscall CMatRenderContext::Init(CMatRenderContext *this, CMaterialSystem *pMaterialSystem)
{
  InitReturnVal_t result; // eax

  result = CMatRenderContextBase::Init(this);
  if ( result == INIT_OK )
  {
    this->m_pMaterialSystem = pMaterialSystem;
    this->m_pBoundMorph = nullptr;
    this->m_pLocalCubemapTexture = g_pTextureManager->ErrorTexture(this: g_pTextureManager);
    this->m_pMorphRenderContext = g_pMorphMgr->AllocateRenderContext(this: g_pMorphMgr);
    return INIT_OK;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10044300
// Name: public: void CMatRenderContext::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::Shutdown(CMatRenderContext *this)
{
  ITextureInternal *m_pUserDefinedLightmap; // ecx

  m_pUserDefinedLightmap = this->m_pUserDefinedLightmap;
  if ( m_pUserDefinedLightmap != nullptr )
  {
    m_pUserDefinedLightmap->DecrementReferenceCount(this: m_pUserDefinedLightmap);
    this->m_pUserDefinedLightmap = nullptr;
  }
  if ( this->m_pMorphRenderContext != nullptr )
  {
    g_pMorphMgr->FreeRenderContext(this: g_pMorphMgr, a2: this->m_pMorphRenderContext);
    this->m_pMorphRenderContext = nullptr;
  }
  if ( --CMatRenderContextBase::sm_nInitializeCount == 0 )
  {
    CMemoryStack::Term(this: CMatRenderContextBase::sm_RenderData);
    CMemoryStack::Term(this: &stru_1034D160);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10044360
// Name: public: void CMatRenderContext::OnReleaseShaderObjects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::OnReleaseShaderObjects(CMatRenderContext *this)
{
  this->m_pBoundMorph = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10044370
// Name: public: virtual void CMatRenderContext::BeginRender(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::BeginRender(CMatRenderContext *this)
{
  DWORD CurrentThreadId; // ecx

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != g_MatSysMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&g_MatSysMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &g_MatSysMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++g_MatSysMutex.m_depth;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100443B0
// Name: public: virtual void CMatRenderContext::EndRender(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::EndRender(CMatRenderContext *this)
{
  if ( --g_MatSysMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&g_MatSysMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100443D0
// Name: public: virtual void CMatRenderContext::SwapBuffers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::SwapBuffers(CMatRenderContext *this)
{
  g_pMorphMgr->AdvanceFrame(this: g_pMorphMgr);
  BaseSlot::AddRef(this: (BaseSlot *)g_pOcclusionQueryMgr);
  g_pShaderDevice->Present(this: g_pShaderDevice);
}

//------------------------------------------------------------------------------
// Address: 0x10044400
// Name: protected: virtual void CMatRenderContext::OnRenderDataUnreferenced(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::OnRenderDataUnreferenced(CMatRenderContext *this)
{
  this->MarkRenderDataUnused(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x10044410
// Name: public: virtual class IMorph __near * CMatRenderContext::CreateMorph(unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
IMorphInternal *__thiscall CMatRenderContext::CreateMorph(
        CMatRenderContext *this,
        unsigned int format,
        const char *pDebugName)
{
  IMorphInternal *v3; // esi

  v3 = g_pMorphMgr->CreateMorph(this: g_pMorphMgr);
  v3->Init(this: v3, a2: format, a3: pDebugName);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10044440
// Name: public: virtual void CMatRenderContext::DestroyMorph(class IMorph __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::DestroyMorph(CMatRenderContext *this, IMorphInternal *pMorph)
{
  g_pMorphMgr->DestroyMorph(this: g_pMorphMgr, a2: pMorph);
}

//------------------------------------------------------------------------------
// Address: 0x10044460
// Name: public: virtual void CMatRenderContext::BindMorph(class IMorph __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::BindMorph(CMatRenderContext *this, IMorphInternal *pMorph)
{
  IMorphInternal *v2; // eax

  v2 = pMorph;
  if ( this->m_pBoundMorph != pMorph )
  {
    this->m_pBoundMorph = pMorph;
    LOBYTE(pMorph) = 0;
    if ( v2 == (IMorphInternal *)1 )
    {
      LOBYTE(pMorph) = 1;
    }
    else if ( v2 != nullptr )
    {
      LOBYTE(pMorph) = v2->Bind(this: v2, a2: this->m_pMorphRenderContext);
    }
    g_pShaderAPI->EnableHWMorphing(this: g_pShaderAPI, a2: (bool)pMorph);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100444B0
// Name: public: virtual class IMesh __near * CMatRenderContext::GetDynamicMesh(bool,class IMesh __near *,class IMesh __near *,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
IMesh *__thiscall CMatRenderContext::GetDynamicMesh(
        CMatRenderContext *this,
        int buffered,
        IMesh *pVertexOverride,
        IMesh *pIndexOverride,
        IMaterial *pAutoBind)
{
  int v7; // eax
  IShaderAPI_vtbl *v8; // ebx
  int v9; // eax

  if ( pAutoBind != nullptr )
    this->Bind(this, a2: pAutoBind, a3: nullptr);
  if ( pVertexOverride != nullptr && (pVertexOverride->GetVertexFormat(this: pVertexOverride) & 0x400) != 0 )
  {
    __debugbreak();
    return nullptr;
  }
  else
  {
    v7 = this->GetCurrentNumBones(this);
    if ( v7 > 1 )
      --v7;
    v8 = g_pShaderAPI->__vftable;
    v9 = ((int (__thiscall *)(CMatRenderContext *, int, int, IMesh *, IMesh *))this->GetCurrentMaterialInternal)(
           a1: this,
           a2: v7,
           a3: buffered,
           a4: pVertexOverride,
           a5: pIndexOverride);
    return (IMesh *)((int (__thiscall *)(IShaderAPI *, int))v8->GetDynamicMesh)(a1: g_pShaderAPI, a2: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10044540
// Name: public: virtual class IMesh __near * CMatRenderContext::GetDynamicMeshEx(unsigned __int64,bool,class IMesh __near *,class IMesh __near *,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
IMesh *__thiscall CMatRenderContext::GetDynamicMeshEx(
        CMatRenderContext *this,
        unsigned __int64 vertexFormat,
        int bBuffered,
        IMesh *pVertexOverride,
        IMesh *pIndexOverride,
        IMaterial *pAutoBind)
{
  int v8; // eax
  IShaderAPI_vtbl *v9; // ebx
  int v10; // eax

  if ( pAutoBind != nullptr )
    this->Bind(this, a2: pAutoBind, a3: nullptr);
  if ( pVertexOverride != nullptr && (pVertexOverride->GetVertexFormat(this: pVertexOverride) & 0x400) != 0 )
  {
    __debugbreak();
    return nullptr;
  }
  else
  {
    v8 = this->GetCurrentNumBones(this);
    if ( v8 > 1 )
      --v8;
    v9 = g_pShaderAPI->__vftable;
    v10 = ((int (__thiscall *)(CMatRenderContext *, _DWORD, _DWORD, int, int, IMesh *, IMesh *))this->GetCurrentMaterialInternal)(
            a1: this,
            a2: vertexFormat,
            a3: HIDWORD(vertexFormat),
            a4: v8,
            a5: bBuffered,
            a6: pVertexOverride,
            a7: pIndexOverride);
    return (IMesh *)((int (__thiscall *)(IShaderAPI *, int))v9->GetDynamicMeshEx)(a1: g_pShaderAPI, a2: v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100445D0
// Name: public: virtual void CMatRenderContext::DepthRange(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::DepthRange(CMatRenderContext *this, float zNear, float zFar)
{
  this->m_Viewport.m_flMinZ = zNear;
  this->m_Viewport.m_flMaxZ = zFar;
  g_pShaderAPI->SetViewports(this: g_pShaderAPI, a2: 1, a3: &this->m_Viewport, a4: false);
}

//------------------------------------------------------------------------------
// Address: 0x10044610
// Name: public: virtual void CMatRenderContextBase::SetFrameBufferCopyTexture(class ITexture __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::SetFrameBufferCopyTexture(
        CMatRenderContext *this,
        ITexture *pTexture,
        unsigned int textureIndex)
{
  if ( textureIndex <= 4 )
    this->m_pCurrentFrameBufferCopyTexture[textureIndex] = pTexture;
}

//------------------------------------------------------------------------------
// Address: 0x10044630
// Name: public: virtual void CMatRenderContext::BindLocalCubemap(class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::BindLocalCubemap(CMatRenderContext *this, ITexture *pTexture)
{
  IShaderAPI_vtbl *v2; // edi
  int v3; // eax

  if ( pTexture != nullptr )
    this->m_pLocalCubemapTexture = pTexture;
  else
    this->m_pLocalCubemapTexture = g_pTextureManager->ErrorTexture(this: g_pTextureManager);
  if ( g_pShaderDevice->IsUsingGraphics(this: g_pShaderDevice) )
  {
    if ( pTexture != nullptr )
    {
      v2 = g_pShaderAPI->__vftable;
      v3 = ((int (__thiscall *)(ITexture *, _DWORD, _DWORD))pTexture->__vftable[1].SetTextureRegenerator)(
             a1: pTexture,
             a2: 0,
             a3: 0);
      v2->SetStandardTextureHandle(this: g_pShaderAPI, a2: TEXTURE_LOCAL_ENV_CUBEMAP, a3: v3);
    }
    else
    {
      g_pShaderAPI->SetStandardTextureHandle(this: g_pShaderAPI, a2: TEXTURE_LOCAL_ENV_CUBEMAP, a3: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100446B0
// Name: public: virtual void CMatRenderContext::SetNonInteractiveLogoTexture(class ITexture __near *,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::SetNonInteractiveLogoTexture(
        CMatRenderContext *this,
        ITexture *pTexture,
        float flNormalizedX,
        float flNormalizedY,
        float flNormalizedW,
        float flNormalizedH)
{
  CTextureReference::Init(this: &this->m_pNonInteractiveLogo, pTexture);
  this->m_flLogoNormalizedX = flNormalizedX;
  this->m_flLogoNormalizedY = flNormalizedY;
  this->m_flLogoNormalizedW = flNormalizedW;
  this->m_flLogoNormalizedH = flNormalizedH;
}

//------------------------------------------------------------------------------
// Address: 0x10044700
// Name: public: virtual void CMatRenderContext::SetNonInteractivePacifierTexture(class ITexture __near *,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::SetNonInteractivePacifierTexture(
        CMatRenderContext *this,
        ITexture *pTexture,
        float flNormalizedX,
        float flNormalizedY,
        float flNormalizedSize)
{
  CTextureReference::Init(this: &this->m_pNonInteractivePacifier, pTexture);
  this->m_flNormalizedX = flNormalizedX;
  this->m_flNormalizedY = flNormalizedY;
  this->m_flNormalizedSize = flNormalizedSize;
}

//------------------------------------------------------------------------------
// Address: 0x10044750
// Name: public: virtual void CMatRenderContext::SetNonInteractiveTempFullscreenBuffer(class ITexture __near *,enum MaterialNonInteractiveMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::SetNonInteractiveTempFullscreenBuffer(
        CMatRenderContext *this,
        ITexture *pTexture,
        MaterialNonInteractiveMode_t mode)
{
  if ( mode != MATERIAL_NON_INTERACTIVE_MODE_NONE )
    CTextureReference::Init(this: &this->m_pNonInteractiveTempFullscreenBuffer[mode], pTexture);
}

//------------------------------------------------------------------------------
// Address: 0x10044770
// Name: public: virtual void CMatRenderContext::RefreshFrontBufferNonInteractive(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::RefreshFrontBufferNonInteractive(CMatRenderContext *this)
{
  g_pShaderDevice->RefreshFrontBufferNonInteractive(this: g_pShaderDevice);
}

//------------------------------------------------------------------------------
// Address: 0x10044780
// Name: public: virtual void CMatRenderContext::EnableNonInteractiveMode(enum MaterialNonInteractiveMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::EnableNonInteractiveMode(CMatRenderContext *this, MaterialNonInteractiveMode_t mode)
{
  ITexture *m_pTexture; // ecx
  ITexture *v4; // ecx
  ITexture *v5; // edi
  int v6; // eax
  int v7; // esi
  ShaderNonInteractiveInfo_t info; // [esp+4h] [ebp-128h] BYREF

  this->m_NonInteractiveMode = mode;
  if ( mode == MATERIAL_NON_INTERACTIVE_MODE_NONE )
  {
    g_pShaderDevice->EnableNonInteractiveMode(
      this: g_pShaderDevice,
      a2: MATERIAL_NON_INTERACTIVE_MODE_NONE,
      a3: nullptr);
  }
  else
  {
    m_pTexture = this->m_pNonInteractiveTempFullscreenBuffer[mode].m_pTexture;
    if ( m_pTexture != nullptr )
      info.m_hTempFullscreenTexture = ((int (__thiscall *)(ITexture *, _DWORD, _DWORD))m_pTexture->__vftable[1].SetTextureRegenerator)(
                                        a1: m_pTexture,
                                        a2: 0,
                                        a3: 0);
    else
      info.m_hTempFullscreenTexture = 0;
    v4 = this->m_pNonInteractiveLogo.m_pTexture;
    info.m_flLogoNormalizedX = this->m_flLogoNormalizedX;
    info.m_flLogoNormalizedY = this->m_flLogoNormalizedY;
    info.m_flLogoNormalizedW = this->m_flLogoNormalizedW;
    info.m_flLogoNormalizedH = this->m_flLogoNormalizedH;
    if ( v4 != nullptr )
      info.m_hLogoTexture = ((int (__thiscall *)(ITexture *, _DWORD, _DWORD))v4->__vftable[1].SetTextureRegenerator)(
                              a1: v4,
                              a2: 0,
                              a3: 0);
    else
      info.m_hLogoTexture = 0;
    info.m_flNormalizedX = this->m_flNormalizedX;
    v5 = this->m_pNonInteractivePacifier.m_pTexture;
    info.m_flNormalizedY = this->m_flNormalizedY;
    info.m_flNormalizedSize = this->m_flNormalizedSize;
    if ( v5 != nullptr )
      v6 = v5->GetNumAnimationFrames(this: v5);
    else
      v6 = 0;
    v7 = 0;
    for ( info.m_nPacifierCount = v6; v7 < info.m_nPacifierCount; ++v7 )
      info.m_pPacifierTextures[v7] = ((int (__thiscall *)(ITexture *, int, _DWORD))v5->__vftable[1].SetTextureRegenerator)(
                                       a1: v5,
                                       a2: v7,
                                       a3: 0);
    g_pShaderDevice->EnableNonInteractiveMode(this: g_pShaderDevice, a2: mode, a3: &info);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100448E0
// Name: public: virtual void CMatRenderContext::GetLightmapDimensions(int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::GetLightmapDimensions(CMatRenderContext *this, int *w, int *h)
{
  CMaterialSystem *m_pMaterialSystem; // ebx
  CMaterialSystem_vtbl *v5; // edi
  int v6; // eax
  CMaterialSystem *v7; // ebx
  CMaterialSystem_vtbl *v8; // edi
  int v9; // eax

  m_pMaterialSystem = this->m_pMaterialSystem;
  v5 = m_pMaterialSystem->CTier2AppSystem<IMaterialSystemInternal,0>::CTier1AppSystem<IMaterialSystemInternal,0>::CTier0AppSystem<IMaterialSystemInternal>::CBaseAppSystem<IMaterialSystemInternal>::IMaterialSystemInternal::IMaterialSystem::IAppSystem::__vftable;
  v6 = this->GetLightmapPage(this);
  *w = v5->GetLightmapWidth(this: m_pMaterialSystem, a2: v6);
  v7 = this->m_pMaterialSystem;
  v8 = v7->CTier2AppSystem<IMaterialSystemInternal,0>::CTier1AppSystem<IMaterialSystemInternal,0>::CTier0AppSystem<IMaterialSystemInternal>::CBaseAppSystem<IMaterialSystemInternal>::IMaterialSystemInternal::IMaterialSystem::IAppSystem::__vftable;
  v9 = this->GetLightmapPage(this);
  *h = v8->GetLightmapHeight(this: v7, a2: v9);
}

//------------------------------------------------------------------------------
// Address: 0x10044940
// Name: public: virtual void CMatRenderContext::DrawScreenSpaceRectangle(class IMaterial __near *,int,int,int,int,float,float,float,float,int,int,void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::DrawScreenSpaceRectangle(
        CMatRenderContext *this,
        IMaterial *pMaterial,
        int destx,
        int desty,
        int width,
        int height,
        float src_texture_x0,
        float src_texture_y0,
        float src_texture_x1,
        float src_texture_y1,
        int src_texture_width,
        int src_texture_height,
        void *pClientRenderable,
        int nXDice,
        int nYDice)
{
  IMaterial *v15; // eax

  v15 = (IMaterial *)((int (__thiscall *)(IMaterial *))pMaterial->__vftable[1].Refresh)(a1: pMaterial);
  DrawScreenSpaceRectangle(
    pMaterial: v15,
    nDestX: destx,
    nDestY: desty,
    nWidth: width,
    nHeight: height,
    flSrcTextureX0: src_texture_x0,
    flSrcTextureY0: src_texture_y0,
    flSrcTextureX1: src_texture_x1,
    flSrcTextureY1: src_texture_y1,
    nSrcTextureWidth: src_texture_width,
    nSrcTextureHeight: src_texture_height,
    pClientRenderable,
    nXDice,
    nYDice,
    fDepth: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x100449C0
// Name: public: virtual int CMatRenderContext::CompareMaterialCombos(class IMaterial __near *,class IMaterial __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatRenderContext::CompareMaterialCombos(
        CMatRenderContext *this,
        ShaderRenderState_t *pMaterial1,
        IMaterial *pMaterial2,
        int lightMapID1,
        int lightMapID2)
{
  int v5; // esi
  int v6; // edi
  int v7; // ebx
  _DWORD *v8; // edx
  int m_nPassCount; // ecx
  int result; // eax
  unsigned __int64 v11; // rax
  RenderPassList_t *m_pSnapshots; // eax
  int v13; // ecx
  int v14; // edx
  int v15; // eax
  __int64 v16; // rax
  unsigned int v17; // ebx
  unsigned __int64 v18; // rax
  int v19; // eax
  char v20; // dl
  int (__thiscall ***v21)(_DWORD); // ebx
  const char *v22; // eax
  const char *v23; // [esp-4h] [ebp-24h]
  unsigned int v24; // [esp+10h] [ebp-10h]
  ShaderRenderState_t *pState2; // [esp+14h] [ebp-Ch]
  unsigned __int64 v26; // [esp+18h] [ebp-8h]
  int v27; // [esp+1Ch] [ebp-4h]
  ShaderRenderState_t *pState1; // [esp+28h] [ebp+8h]
  ShaderRenderState_t *pState1a; // [esp+28h] [ebp+8h]
  char pState1_3; // [esp+2Bh] [ebp+Bh]
  int i; // [esp+2Ch] [ebp+Ch]
  int ia; // [esp+2Ch] [ebp+Ch]

  v5 = (*(int (__thiscall **)(ShaderRenderState_t *))(pMaterial1->m_Flags + 368))(a1: pMaterial1);
  v6 = ((int (__thiscall *)(IMaterial *))pMaterial2->__vftable[1].Refresh)(a1: pMaterial2);
  pState1 = (ShaderRenderState_t *)(*(int (__thiscall **)(int))(*(_DWORD *)v5 + 316))(a1: v5);
  v7 = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 316))(a1: v6);
  v8 = *(_DWORD **)(v7 + 24);
  m_nPassCount = pState1->m_pSnapshots->m_nPassCount;
  result = *v8 - m_nPassCount;
  pState2 = (ShaderRenderState_t *)v7;
  if ( *v8 == m_nPassCount )
  {
    if ( m_nPassCount > 1 )
    {
      v26 = ((__int64 (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v6 + 80))(a1: v6);
      v11 = ((__int64 (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v5 + 80))(a1: v5);
      if ( v11 != v26 )
      {
        if ( v11 > v26 )
          return 1;
        return -1;
      }
    }
    m_pSnapshots = pState1->m_pSnapshots;
    i = 0;
    if ( m_pSnapshots->m_nPassCount <= 0 )
    {
LABEL_13:
      v16 = ((__int64 (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v6 + 80))(a1: v6);
      v24 = HIDWORD(v16);
      v17 = v16;
      LODWORD(v18) = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 80))(a1: v5);
      if ( v18 == __PAIR64__(v24, v17) )
      {
        ia = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 164))(a1: v5);
        v19 = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 164))(a1: v6);
        v20 = *(_BYTE *)(*(_DWORD *)(ia + 24) + 28);
        if ( (v20 & 0xF) != 3 && (*(_BYTE *)(*(_DWORD *)(v19 + 24) + 28) & 0xF) != 3 )
          goto LABEL_21;
        pState1_3 = *(_BYTE *)(*(_DWORD *)(v19 + 24) + 28);
        if ( (v20 & 0xF) != (pState1_3 & 0xF) )
          return (pState1_3 & 0xF) - (v20 & 0xF);
        v21 = (int (__thiscall ***)(_DWORD))(***(int (__thiscall ****)(_DWORD))(v19 + 24))(a1: *(_DWORD *)(v19 + 24));
        pState1a = (ShaderRenderState_t *)(***(int (__thiscall ****)(_DWORD))(ia + 24))(a1: *(_DWORD *)(ia + 24));
        v23 = (const char *)(**v21)(a1: v21);
        v22 = (const char *)(*(int (__thiscall **)(ShaderRenderState_t *))pState1a->m_Flags)(a1: pState1a);
        result = _V_stricmp(s1: v22, s2: v23);
        if ( result == 0 )
        {
LABEL_21:
          result = lightMapID1 - lightMapID2;
          if ( lightMapID1 == lightMapID2 )
            return v5 - v6;
        }
      }
      else
      {
        if ( v18 <= __PAIR64__(v24, v17) )
          return -1;
        return 1;
      }
    }
    else
    {
      v13 = 4;
      v27 = 4;
      while ( 1 )
      {
        v14 = *(unsigned __int16 *)(v13 + *(_DWORD *)(v7 + 24));
        v15 = *(unsigned __int16 *)((char *)&m_pSnapshots->m_nPassCount + v13);
        if ( (__int16)v15 != (__int16)v14 )
        {
          result = g_pShaderAPI->CompareSnapshots(this: g_pShaderAPI, a2: v15, a3: v14);
          if ( result != 0 )
            break;
        }
        m_pSnapshots = pState1->m_pSnapshots;
        v13 = v27 + 2;
        ++i;
        v27 += 2;
        if ( i >= m_pSnapshots->m_nPassCount )
          goto LABEL_13;
        v7 = (int)pState2;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10044BD0
// Name: public: virtual void CMatRenderContext::Bind(class IMaterial __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMatRenderContext::Bind(
        CMatRenderContext *this@<ecx>,
        int a2@<ebx>,
        IMaterialInternal *pMaterial,
        void *proxyData)
{
  IMaterialInternal *v5; // ecx
  int v6; // eax
  IMaterialInternal *v7; // eax
  IShaderAPI_vtbl *v8; // edi
  IMaterialInternal *v9; // eax

  v5 = pMaterial;
  if ( pMaterial == nullptr )
  {
    if ( g_pErrorMaterial == nullptr )
      return;
    _Warning(a1: "Programming error: CMatRenderContext::Bind: NULL material\n");
    v5 = g_pErrorMaterial;
  }
  v6 = (int)v5->GetRealTimeVersion(this: v5);
  if ( g_config.bDrawFlat )
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 292))(a1: v6);
  CMatRenderContextBase::Bind(this, pMaterial, proxyData);
  ((void (__thiscall *)(CMatRenderContext *, int))this->SyncMatrices)(a1: this, a2);
  if ( this->m_pMaterialSystem->GetThreadMode(this: this->m_pMaterialSystem) == MATERIAL_SINGLE_THREADED )
  {
    v7 = this->GetCurrentMaterialInternal(this);
    v7->CallBindProxy(this: v7, a2: proxyData, a3: nullptr);
  }
  v8 = g_pShaderAPI->__vftable;
  v9 = this->GetCurrentMaterialInternal(this);
  v8->Bind(this: g_pShaderAPI, a2: v9);
}

//------------------------------------------------------------------------------
// Address: 0x10044C90
// Name: public: virtual void CMatRenderContext::CopyRenderTargetToTextureEx(class ITexture __near *,int,struct Rect_t __near *,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::CopyRenderTargetToTextureEx(
        CMatRenderContext *this,
        ITexture *pTexture,
        int nRenderTargetID,
        Rect_t *pSrcRect,
        Rect_t *pDstRect)
{
  if ( pTexture != nullptr )
  {
    this->m_pMaterialSystem->Flush(this: this->m_pMaterialSystem, a2: false);
    ((void (__thiscall *)(ITexture *, int, Rect_t *, Rect_t *))pTexture->__vftable[1].IncrementReferenceCount)(
      a1: pTexture,
      a2: nRenderTargetID,
      a3: pSrcRect,
      a4: pDstRect);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10044CD0
// Name: public: virtual void CMatRenderContext::CopyRenderTargetToTexture(class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::CopyRenderTargetToTexture(CMatRenderContext *this, ITexture *pTexture)
{
  this->CopyRenderTargetToTextureEx(this, a2: pTexture, a3: 0, a4: nullptr, a5: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10044CF0
// Name: public: virtual void CMatRenderContext::ClearBuffers(bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::ClearBuffers(
        CMatRenderContext *this,
        BOOL bClearColor,
        BOOL bClearDepth,
        BOOL bClearStencil)
{
  int width; // [esp+0h] [ebp-8h] BYREF
  int height; // [esp+4h] [ebp-4h] BYREF

  this->GetRenderTargetDimensions(this, a2: &width, a3: &height);
  g_pShaderAPI->ClearBuffers(
    this: g_pShaderAPI,
    a2: bClearColor,
    a3: bClearDepth,
    a4: bClearStencil,
    a5: width,
    a6: height);
}

//------------------------------------------------------------------------------
// Address: 0x10044D30
// Name: public: virtual void CMatRenderContext::BindLightmapPage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::BindLightmapPage(CMatRenderContext *this, int lightmapPageID)
{
  IShaderAPI_vtbl *v3; // ebx
  int v4; // eax
  IShaderAPI_vtbl *v5; // ebx
  int v6; // eax

  if ( this->m_lightmapPageID != lightmapPageID )
  {
    if ( g_pShaderDevice->IsUsingGraphics(this: g_pShaderDevice) )
    {
      v3 = g_pShaderAPI->__vftable;
      v4 = this->GetLightmapTexture(this, a2: lightmapPageID);
      v3->SetStandardTextureHandle(this: g_pShaderAPI, a2: TEXTURE_LIGHTMAP, a3: v4);
      v5 = g_pShaderAPI->__vftable;
      v6 = this->GetPaintmapTexture(this, a2: lightmapPageID);
      v5->SetStandardTextureHandle(this: g_pShaderAPI, a2: TEXTURE_PAINT, a3: v6);
    }
    this->m_lightmapPageID = lightmapPageID;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10044DB0
// Name: public: virtual void CMatRenderContext::BindLightmapTexture(class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::BindLightmapTexture(CMatRenderContext *this, ITextureInternal *pLightmapTexture)
{
  ITextureInternal *m_pUserDefinedLightmap; // ecx
  IShaderAPI_vtbl *v4; // edi
  int v5; // eax
  IShaderAPI_vtbl *v6; // edi
  int v7; // eax

  if ( this->m_lightmapPageID != -3 || this->m_pUserDefinedLightmap != pLightmapTexture )
  {
    if ( pLightmapTexture != nullptr )
      pLightmapTexture->IncrementReferenceCount(this: pLightmapTexture);
    m_pUserDefinedLightmap = this->m_pUserDefinedLightmap;
    if ( m_pUserDefinedLightmap != nullptr )
      m_pUserDefinedLightmap->DecrementReferenceCount(this: m_pUserDefinedLightmap);
    this->m_pUserDefinedLightmap = pLightmapTexture;
    this->m_lightmapPageID = -3;
    if ( g_pShaderDevice->IsUsingGraphics(this: g_pShaderDevice) )
    {
      v4 = g_pShaderAPI->__vftable;
      v5 = this->GetLightmapTexture(this, a2: this->m_lightmapPageID);
      v4->SetStandardTextureHandle(this: g_pShaderAPI, a2: TEXTURE_LIGHTMAP, a3: v5);
      v6 = g_pShaderAPI->__vftable;
      v7 = this->GetPaintmapTexture(this, a2: this->m_lightmapPageID);
      v6->SetStandardTextureHandle(this: g_pShaderAPI, a2: TEXTURE_PAINT, a3: v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10044E60
// Name: protected: void CMatRenderContext::BindLightmap(enum Sampler_t,enum TextureBindFlags_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::BindLightmap(
        CMatRenderContext *this,
        Sampler_t sampler,
        TextureBindFlags_t nBindFlags)
{
  IShaderAPI_vtbl *v3; // esi
  int v4; // eax

  v3 = g_pShaderAPI->__vftable;
  v4 = ((int (__stdcall *)(int))this->GetLightmapTexture)(a1: this->m_lightmapPageID);
  v3->BindTexture(this: g_pShaderAPI, a2: sampler, a3: nBindFlags, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10044EA0
// Name: public: virtual int CMatRenderContext::GetPaintmapTexture(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatRenderContext::GetPaintmapTexture(CMatRenderContext *this, int nLightmapPage)
{
  CMaterialSystem *m_pMaterialSystem; // eax

  if ( !CMatPaintmaps::IsEnabled(this: &this->m_pMaterialSystem->m_Paintmaps) )
    return this->m_pMaterialSystem->m_BlackAlphaZeroTextureHandle;
  if ( nLightmapPage < 0 )
    return this->m_pMaterialSystem->m_BlackAlphaZeroTextureHandle;
  m_pMaterialSystem = this->m_pMaterialSystem;
  if ( nLightmapPage >= m_pMaterialSystem->m_Lightmaps.m_NumLightmapPages )
    return this->m_pMaterialSystem->m_BlackAlphaZeroTextureHandle;
  return CMatPaintmaps::GetPaintmapPageTextureHandle(this: &m_pMaterialSystem->m_Paintmaps, paintmap: nLightmapPage);
}

//------------------------------------------------------------------------------
// Address: 0x10044F10
// Name: protected: void CMatRenderContext::BindPaintTexture(enum Sampler_t,enum TextureBindFlags_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::BindPaintTexture(
        CMatRenderContext *this,
        Sampler_t sampler,
        TextureBindFlags_t nBindFlags)
{
  int v3; // eax

  v3 = this->GetPaintmapTexture(this, a2: this->m_lightmapPageID);
  g_pShaderAPI->BindTexture(this: g_pShaderAPI, a2: sampler, a3: nBindFlags, a4: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10044F40
// Name: protected: void CMatRenderContext::BindBumpLightmap(enum Sampler_t,enum TextureBindFlags_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::BindBumpLightmap(
        CMatRenderContext *this,
        Sampler_t sampler,
        TextureBindFlags_t nBindFlags)
{
  int v3; // esi

  v3 = this->GetLightmapTexture(this, a2: this->m_lightmapPageID);
  g_pShaderAPI->BindTexture(this: g_pShaderAPI, a2: sampler, a3: nBindFlags, a4: v3);
  g_pShaderAPI->BindTexture(this: g_pShaderAPI, a2: (Sampler_t)(sampler + 1), a3: nBindFlags, a4: v3);
  g_pShaderAPI->BindTexture(this: g_pShaderAPI, a2: (Sampler_t)(sampler + 2), a3: nBindFlags, a4: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10044FB0
// Name: protected: void CMatRenderContext::BindFullbrightLightmap(enum Sampler_t,enum TextureBindFlags_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::BindFullbrightLightmap(
        CMatRenderContext *this,
        Sampler_t sampler,
        TextureBindFlags_t nBindFlags)
{
  g_pShaderAPI->BindTexture(
    this: g_pShaderAPI,
    a2: sampler,
    a3: nBindFlags,
    a4: this->m_pMaterialSystem->m_FullbrightLightmapTextureHandle);
}

//------------------------------------------------------------------------------
// Address: 0x10044FE0
// Name: protected: void CMatRenderContext::BindBumpedFullbrightLightmap(enum Sampler_t,enum TextureBindFlags_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::BindBumpedFullbrightLightmap(
        CMatRenderContext *this,
        Sampler_t sampler,
        TextureBindFlags_t nBindFlags)
{
  g_pShaderAPI->BindTexture(
    this: g_pShaderAPI,
    a2: sampler,
    a3: nBindFlags,
    a4: this->m_pMaterialSystem->m_FullbrightBumpedLightmapTextureHandle);
}

//------------------------------------------------------------------------------
// Address: 0x10045010
// Name: public: virtual void CMatRenderContext::BindStandardTexture(enum Sampler_t,enum TextureBindFlags_t,enum StandardTextureId_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::BindStandardTexture(
        CMatRenderContext *this,
        Sampler_t sampler,
        TextureBindFlags_t nBindFlags,
        StandardTextureId_t id)
{
  int m_WhiteTextureHandle; // eax
  ITextureInternal *v5; // eax
  IShaderAPI_vtbl *v6; // esi
  int v7; // eax

  switch ( id )
  {
    case TEXTURE_LIGHTMAP:
      CMatRenderContext::BindLightmap(this, sampler, nBindFlags);
      return;
    case TEXTURE_LIGHTMAP_FULLBRIGHT:
      CMatRenderContext::BindFullbrightLightmap(this, sampler, nBindFlags);
      return;
    case TEXTURE_LIGHTMAP_BUMPED:
      CMatRenderContext::BindBumpLightmap(this, sampler, nBindFlags);
      return;
    case TEXTURE_LIGHTMAP_BUMPED_FULLBRIGHT:
      CMatRenderContext::BindBumpedFullbrightLightmap(this, sampler, nBindFlags);
      return;
    case TEXTURE_WHITE:
      m_WhiteTextureHandle = this->m_pMaterialSystem->m_WhiteTextureHandle;
      goto LABEL_8;
    case TEXTURE_BLACK:
      m_WhiteTextureHandle = this->m_pMaterialSystem->m_BlackTextureHandle;
      goto LABEL_8;
    case TEXTURE_BLACK_ALPHA_ZERO:
      m_WhiteTextureHandle = this->m_pMaterialSystem->m_BlackAlphaZeroTextureHandle;
      goto LABEL_8;
    case TEXTURE_GREY:
      m_WhiteTextureHandle = this->m_pMaterialSystem->m_GreyTextureHandle;
      goto LABEL_8;
    case TEXTURE_GREY_ALPHA_ZERO:
      m_WhiteTextureHandle = this->m_pMaterialSystem->m_GreyAlphaZeroTextureHandle;
      goto LABEL_8;
    case TEXTURE_NORMALMAP_FLAT:
      m_WhiteTextureHandle = this->m_pMaterialSystem->m_FlatNormalTextureHandle;
      goto LABEL_8;
    case TEXTURE_SSBUMP_FLAT:
      m_WhiteTextureHandle = this->m_pMaterialSystem->m_FlatSSBumpTextureHandle;
      goto LABEL_8;
    case TEXTURE_NORMALIZATION_CUBEMAP:
      v5 = g_pTextureManager->NormalizationCubemap(this: g_pTextureManager);
      goto LABEL_31;
    case TEXTURE_NORMALIZATION_CUBEMAP_SIGNED:
      v5 = g_pTextureManager->SignedNormalizationCubemap(this: g_pTextureManager);
      goto LABEL_31;
    case TEXTURE_FRAME_BUFFER_FULL_TEXTURE_0:
    case TEXTURE_FRAME_BUFFER_FULL_TEXTURE_1:
      if ( *((_DWORD *)this + id - 5) == 0 )
        return;
      v5 = *((ITextureInternal **)this + id - 5);
      goto LABEL_31;
    case TEXTURE_COLOR_CORRECTION_VOLUME_0:
    case TEXTURE_COLOR_CORRECTION_VOLUME_1:
    case TEXTURE_COLOR_CORRECTION_VOLUME_2:
    case TEXTURE_COLOR_CORRECTION_VOLUME_3:
      v5 = g_pTextureManager->ColorCorrectionTexture(this: g_pTextureManager, a2: id - 15);
      if ( v5 != nullptr )
        goto LABEL_31;
      return;
    case TEXTURE_SHADOW_NOISE_2D:
      v5 = g_pTextureManager->ShadowNoise2D(this: g_pTextureManager);
      goto LABEL_31;
    case TEXTURE_MORPH_ACCUMULATOR:
      v5 = g_pMorphMgr->MorphAccumulator(this: g_pMorphMgr);
      goto LABEL_31;
    case TEXTURE_MORPH_WEIGHTS:
      v5 = g_pMorphMgr->MorphWeights(this: g_pMorphMgr);
      goto LABEL_31;
    case TEXTURE_FRAME_BUFFER_FULL_DEPTH:
      if ( (*((_BYTE *)&this->CMatRenderContextBase + 492) & 0x10) != 0 )
      {
        v5 = g_pTextureManager->FullFrameDepthTexture(this: g_pTextureManager);
LABEL_31:
        v5->Bind_2(this: v5, a2: sampler, a3: nBindFlags);
      }
      else
      {
        m_WhiteTextureHandle = this->m_pMaterialSystem->m_MaxDepthTextureHandle;
LABEL_8:
        g_pShaderAPI->BindTexture(this: g_pShaderAPI, a2: sampler, a3: nBindFlags, a4: m_WhiteTextureHandle);
      }
      return;
    case TEXTURE_IDENTITY_LIGHTWARP:
      v5 = g_pTextureManager->IdentityLightWarp(this: g_pTextureManager);
      goto LABEL_31;
    case TEXTURE_LOCAL_ENV_CUBEMAP:
      v6 = g_pShaderAPI->__vftable;
      v7 = ((int (__thiscall *)(ITexture *, _DWORD, _DWORD))this->m_pLocalCubemapTexture->CMatRenderContextBase::__vftable[1].SetTextureRegenerator)(
             a1: this->m_pLocalCubemapTexture,
             a2: 0,
             a3: 0);
      v6->BindTexture(this: g_pShaderAPI, a2: sampler, a3: nBindFlags, a4: v7);
      return;
    case TEXTURE_SSAO_NOISE_2D:
      v5 = g_pTextureManager->SSAONoise2D(this: g_pTextureManager);
      goto LABEL_31;
    case TEXTURE_PAINT:
      CMatRenderContext::BindPaintTexture(this, sampler, nBindFlags);
      return;
    case TEXTURE_STEREO_PARAM_MAP:
      v5 = g_pTextureManager->StereoParamTexture(this: g_pTextureManager);
      goto LABEL_31;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100452B0
// Name: public: virtual void CMatRenderContext::BindStandardVertexTexture(enum VertexTextureSampler_t,enum StandardTextureId_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::BindStandardVertexTexture(
        CMatRenderContext *this,
        VertexTextureSampler_t vtSampler,
        StandardTextureId_t id)
{
  ITextureInternal *v3; // eax
  ITextureInternal *v4; // eax

  switch ( id )
  {
    case TEXTURE_BLACK:
      g_pShaderAPI->BindVertexTexture(
        this: g_pShaderAPI,
        a2: vtSampler,
        a3: this->m_pMaterialSystem->m_BlackTextureHandle);
      break;
    case TEXTURE_MORPH_ACCUMULATOR:
      v3 = g_pMorphMgr->MorphAccumulator(this: g_pMorphMgr);
      v3->BindVertexTexture(this: v3, a2: vtSampler, a3: 0);
      break;
    case TEXTURE_MORPH_WEIGHTS:
      v4 = g_pMorphMgr->MorphWeights(this: g_pMorphMgr);
      v4->BindVertexTexture(this: v4, a2: vtSampler, a3: 0);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10045370
// Name: public: virtual void CMatRenderContext::GetStandardTextureDimensions(int __near *,int __near *,enum StandardTextureId_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::GetStandardTextureDimensions(
        CMatRenderContext *this,
        int *pWidth,
        int *pHeight,
        StandardTextureId_t id)
{
  int (*NormalizationCubemap)(void); // eax
  ITextureInternal *v5; // eax
  ITextureInternal *v6; // esi

  switch ( id )
  {
    case TEXTURE_NORMALIZATION_CUBEMAP:
      NormalizationCubemap = (int (*)(void))g_pTextureManager->NormalizationCubemap;
      goto LABEL_3;
    case TEXTURE_NORMALIZATION_CUBEMAP_SIGNED:
      NormalizationCubemap = (int (*)(void))g_pTextureManager->SignedNormalizationCubemap;
LABEL_3:
      v5 = (ITextureInternal *)NormalizationCubemap();
      goto LABEL_4;
    case TEXTURE_FRAME_BUFFER_FULL_TEXTURE_0:
    case TEXTURE_FRAME_BUFFER_FULL_TEXTURE_1:
      v6 = *((ITextureInternal **)this + id - 5);
      goto LABEL_5;
    case TEXTURE_COLOR_CORRECTION_VOLUME_0:
    case TEXTURE_COLOR_CORRECTION_VOLUME_1:
    case TEXTURE_COLOR_CORRECTION_VOLUME_2:
    case TEXTURE_COLOR_CORRECTION_VOLUME_3:
      v5 = g_pTextureManager->ColorCorrectionTexture(this: g_pTextureManager, a2: id - 15);
      goto LABEL_4;
    case TEXTURE_SHADOW_NOISE_2D:
      v5 = g_pTextureManager->ShadowNoise2D(this: g_pTextureManager);
      goto LABEL_4;
    case TEXTURE_MORPH_ACCUMULATOR:
      v5 = g_pMorphMgr->MorphAccumulator(this: g_pMorphMgr);
      goto LABEL_4;
    case TEXTURE_MORPH_WEIGHTS:
      v5 = g_pMorphMgr->MorphWeights(this: g_pMorphMgr);
      goto LABEL_4;
    case TEXTURE_IDENTITY_LIGHTWARP:
      g_pTextureManager->IdentityLightWarp(this: g_pTextureManager);
      return;
    case TEXTURE_SSAO_NOISE_2D:
      v5 = g_pTextureManager->SSAONoise2D(this: g_pTextureManager);
      goto LABEL_4;
    case TEXTURE_STEREO_PARAM_MAP:
      v5 = g_pTextureManager->StereoParamTexture(this: g_pTextureManager);
LABEL_4:
      v6 = v5;
LABEL_5:
      if ( v6 == nullptr )
        goto LABEL_17;
      *pWidth = v6->GetActualWidth(this: v6);
      *pHeight = v6->GetActualHeight(this: v6);
      break;
    default:
      _Warning(a1: "GetStandardTextureDimensions: still unimplemented for this type!\n");
      *pHeight = -1;
      *pWidth = -1;
LABEL_17:
      _Warning(a1: "GetStandardTextureDimensions: Couldn't find the texture to get the dimensions!\n");
      *pHeight = -1;
      *pWidth = -1;
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100454E0
// Name: public: virtual void CMatRenderContext::SetFlashlightMode(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::SetFlashlightMode(CMatRenderContext *this, bool bEnable)
{
  *((_BYTE *)&this->CMatRenderContextBase + 492) ^= (bEnable ^ *((_BYTE *)&this->CMatRenderContextBase + 492)) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x10045500
// Name: public: virtual void CMatRenderContext::SetRenderingPaint(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::SetRenderingPaint(CMatRenderContext *this, bool bEnable)
{
  *((_BYTE *)&this->CMatRenderContextBase + 492) ^= (*((_BYTE *)&this->CMatRenderContextBase + 492)
                                                   ^ (32 * bEnable))
                                                  & 0x20;
}

//------------------------------------------------------------------------------
// Address: 0x10045520
// Name: public: virtual void CMatRenderContext::EnableCullingForSinglePassFlashlight(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::EnableCullingForSinglePassFlashlight(CMatRenderContext *this, bool bEnable)
{
  *((_BYTE *)&this->CMatRenderContextBase + 492) ^= (*((_BYTE *)&this->CMatRenderContextBase + 492)
                                                   ^ (bEnable << 6))
                                                  & 0x40;
}

//------------------------------------------------------------------------------
// Address: 0x10045540
// Name: public: virtual void CMatRenderContext::EnableSinglePassFlashlightMode(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::EnableSinglePassFlashlightMode(CMatRenderContext *this, BOOL bEnable)
{
  *((_BYTE *)&this->CMatRenderContextBase + 492) = (bEnable << 7)
                                                 | *((_BYTE *)&this->CMatRenderContextBase + 492) & 0x7F;
  g_pShaderAPI->EnableSinglePassFlashlightMode(this: g_pShaderAPI, a2: bEnable);
}

//------------------------------------------------------------------------------
// Address: 0x10045580
// Name: public: virtual bool CMatRenderContext::SinglePassFlashlightModeEnabled(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatRenderContext::SinglePassFlashlightModeEnabled(CMatQueuedRenderContext *this)
{
  return *((_BYTE *)&this->CMatRenderContextBase + 492) >> 7;
}

//------------------------------------------------------------------------------
// Address: 0x10045590
// Name: public: virtual void CMatRenderContext::SetFlashlightStateEx(struct FlashlightState_t const __near &,class VMatrix const __near &,class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::SetFlashlightStateEx(
        CMatRenderContext *this,
        const FlashlightState_t *state,
        const VMatrix *worldToTexture,
        ITexture *pFlashlightDepthTexture)
{
  g_pShaderAPI->SetFlashlightStateEx(this: g_pShaderAPI, a2: state, a3: worldToTexture, a4: pFlashlightDepthTexture);
}

//------------------------------------------------------------------------------
// Address: 0x100455B0
// Name: public: virtual void CMatRenderContext::SetToneMappingScaleLinear(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::SetToneMappingScaleLinear(CMatRenderContext *this, const Vector *vScale)
{
  this->m_LastSetToneMapScale = *vScale;
  g_pShaderAPI->SetToneMappingScaleLinear(this: g_pShaderAPI, a2: vScale);
}

//------------------------------------------------------------------------------
// Address: 0x100455F0
// Name: public: virtual void CMatRenderContext::BeginBatch(class IMesh __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::BeginBatch(CMatRenderContext *this, IMesh *pIndices)
{
  this->m_pBatchIndices = pIndices;
}

//------------------------------------------------------------------------------
// Address: 0x10045600
// Name: public: virtual void CMatRenderContext::BindBatch(class IMesh __near *,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::BindBatch(CMatRenderContext *this, IMesh *pVertices, IMaterial *pAutoBind)
{
  this->m_pBatchMesh = this->GetDynamicMesh(this, a2: 0, a3: pVertices, a4: this->m_pBatchIndices, a5: pAutoBind);
}

//------------------------------------------------------------------------------
// Address: 0x10045630
// Name: public: virtual void CMatRenderContext::DrawBatch(enum MaterialPrimitiveType_t,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::DrawBatch(
        CMatRenderContext *this,
        MaterialPrimitiveType_t primType,
        int firstIndex,
        int numIndices)
{
  this->m_pBatchMesh->SetPrimitiveType(this: this->m_pBatchMesh, a2: primType);
  this->m_pBatchMesh->Draw_2(this: this->m_pBatchMesh, a2: firstIndex, a3: numIndices);
}

//------------------------------------------------------------------------------
// Address: 0x10045670
// Name: public: virtual void CMatRenderContext::EndBatch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::EndBatch(CMatRenderContext *this)
{
  this->m_pBatchIndices = nullptr;
  this->m_pBatchMesh = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10045680
// Name: public: virtual bool CMatRenderContext::OnDrawMesh(class IMesh __near *,class CPrimList __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMatRenderContext::OnDrawMesh(CMatRenderContext *this, IMesh *pMesh, IMesh *pLists, CPrimList *nLists)
{
  this->SyncMatrices(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10045690
// Name: public: virtual bool CMatRenderContext::OnDrawMeshModulated(class IMesh __near *,class Vector4D const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMatRenderContext::OnDrawMeshModulated(
        CMatRenderContext *this,
        IMesh *pMesh,
        IMesh *vecDiffuseModulation,
        const Vector4D *firstIndex,
        int numIndices)
{
  this->SyncMatrices(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100456A0
// Name: public: virtual void CMatRenderContext::BeginMorphAccumulation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::BeginMorphAccumulation(CMatRenderContext *this)
{
  g_pMorphMgr->BeginMorphAccumulation(this: g_pMorphMgr, a2: this->m_pMorphRenderContext);
}

//------------------------------------------------------------------------------
// Address: 0x100456C0
// Name: public: virtual void CMatRenderContext::EndMorphAccumulation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::EndMorphAccumulation(CMatRenderContext *this)
{
  g_pMorphMgr->EndMorphAccumulation(this: g_pMorphMgr, a2: this->m_pMorphRenderContext);
}

//------------------------------------------------------------------------------
// Address: 0x100456E0
// Name: public: virtual void CMatRenderContext::AccumulateMorph(class IMorph __near *,int,struct MorphWeight_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::AccumulateMorph(
        CMatRenderContext *this,
        IMorph *pMorph,
        int nMorphCount,
        const MorphWeight_t *pWeights)
{
  g_pMorphMgr->AccumulateMorph(
    this: g_pMorphMgr,
    a2: this->m_pMorphRenderContext,
    a3: pMorph,
    a4: nMorphCount,
    a5: pWeights);
}

//------------------------------------------------------------------------------
// Address: 0x10045710
// Name: public: virtual bool CMatRenderContext::GetMorphAccumulatorTexCoord(class Vector2D __near *,class IMorph __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatRenderContext::GetMorphAccumulatorTexCoord(
        CMatRenderContext *this,
        Vector2D *pTexCoord,
        IMorph *pMorph,
        int nVertex)
{
  return g_pMorphMgr->GetMorphAccumulatorTexCoord(
           this: g_pMorphMgr,
           a2: this->m_pMorphRenderContext,
           a3: pTexCoord,
           a4: pMorph,
           a5: nVertex);
}

//------------------------------------------------------------------------------
// Address: 0x10045740
// Name: public: virtual struct OcclusionQueryObjectHandle_t__ __near * CMatRenderContext::CreateOcclusionQueryObject(void)
// Source: json
//------------------------------------------------------------------------------
OcclusionQueryObjectHandle_t__ *__thiscall CMatRenderContext::CreateOcclusionQueryObject(CMatRenderContext *this)
{
  OcclusionQueryObjectHandle_t__ *OcclusionQueryObject; // esi

  OcclusionQueryObject = COcclusionQueryMgr::CreateOcclusionQueryObject(this: g_pOcclusionQueryMgr);
  COcclusionQueryMgr::OnCreateOcclusionQueryObject(this: g_pOcclusionQueryMgr, h: OcclusionQueryObject);
  return OcclusionQueryObject;
}

//------------------------------------------------------------------------------
// Address: 0x10045760
// Name: public: virtual int CMatRenderContext::OcclusionQuery_GetNumPixelsRendered(struct OcclusionQueryObjectHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatRenderContext::OcclusionQuery_GetNumPixelsRendered(
        CMatRenderContext *this,
        OcclusionQueryObjectHandle_t__ *h)
{
  return COcclusionQueryMgr::OcclusionQuery_GetNumPixelsRendered(this: g_pOcclusionQueryMgr, h, bDoQuery: true);
}

//------------------------------------------------------------------------------
// Address: 0x10045780
// Name: public: virtual void CMatRenderContext::SetFullScreenDepthTextureValidityFlag(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::SetFullScreenDepthTextureValidityFlag(CMatRenderContext *this, bool bIsValid)
{
  *((_BYTE *)&this->CMatRenderContextBase + 492) ^= (*((_BYTE *)&this->CMatRenderContextBase + 492)
                                                   ^ (16 * bIsValid))
                                                  & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x100457A0
// Name: public: void CVertexBuilder::AdvanceVertex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBuilder::AdvanceVertex(CVertexBuilder *this)
{
  int v1; // eax

  v1 = ++this->m_nCurrentVertex;
  if ( v1 > this->m_nVertexCount )
    this->m_nVertexCount = v1;
  this->m_pCurrPosition = (float *)((char *)this->m_pCurrPosition + this->m_VertexSize_Position);
  this->m_pCurrNormal = (float *)((char *)this->m_pCurrNormal + this->m_VertexSize_Normal);
  this->m_pCurrColor += this->m_VertexSize_Color;
  this->m_pCurrTexCoord[0] = (float *)((char *)this->m_pCurrTexCoord[0] + this->m_VertexSize_TexCoord[0]);
  this->m_pCurrTexCoord[1] = (float *)((char *)this->m_pCurrTexCoord[1] + this->m_VertexSize_TexCoord[1]);
  this->m_pCurrTexCoord[2] = (float *)((char *)this->m_pCurrTexCoord[2] + this->m_VertexSize_TexCoord[2]);
  this->m_pCurrTexCoord[3] = (float *)((char *)this->m_pCurrTexCoord[3] + this->m_VertexSize_TexCoord[3]);
  this->m_pCurrTexCoord[4] = (float *)((char *)this->m_pCurrTexCoord[4] + this->m_VertexSize_TexCoord[4]);
  this->m_pCurrTexCoord[5] = (float *)((char *)this->m_pCurrTexCoord[5] + this->m_VertexSize_TexCoord[5]);
  this->m_pCurrTexCoord[6] = (float *)((char *)this->m_pCurrTexCoord[6] + this->m_VertexSize_TexCoord[6]);
  this->m_pCurrTexCoord[7] = (float *)((char *)this->m_pCurrTexCoord[7] + this->m_VertexSize_TexCoord[7]);
}

//------------------------------------------------------------------------------
// Address: 0x10045820
// Name: public: virtual void CMatRenderContextBase::MultMatrix(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::MultMatrix(CMatRenderContextBase *this, const matrix3x4_t *matrix)
{
  CMatRenderContextBase::MatrixStackItem_t *m_pCurMatrixItem; // ecx
  MaterialMatrixMode_t m_MatrixMode; // eax
  VMatrix dst; // [esp+0h] [ebp-80h] BYREF
  VMatrix src1; // [esp+40h] [ebp-40h] BYREF

  *(_QWORD *)&src1.m[0][0] = *(_QWORD *)&matrix->m_flMatVal[0][0];
  *(_QWORD *)&src1.m[0][2] = *(_QWORD *)&matrix->m_flMatVal[0][2];
  *(_OWORD *)&src1.m[1][0] = *(_OWORD *)&matrix->m_flMatVal[1][0];
  *(_QWORD *)&src1.m[2][0] = *(_QWORD *)&matrix->m_flMatVal[2][0];
  m_pCurMatrixItem = this->m_pCurMatrixItem;
  *(_QWORD *)&src1.m[2][2] = *(_QWORD *)&matrix->m_flMatVal[2][2];
  *(_QWORD *)&src1.m[3][0] = 0;
  *(_QWORD *)&src1.m[3][2] = 0x3F80000000000000LL;
  MatrixMultiply(&src1, src2: &m_pCurMatrixItem->matrix, &dst);
  VMatrix::operator=(this: &this->m_pCurMatrixItem->matrix, mOther: &dst);
  this->m_pCurMatrixItem->flags = 1;
  m_MatrixMode = this->m_MatrixMode;
  if ( m_MatrixMode != MATERIAL_VIEW )
  {
    if ( m_MatrixMode == MATERIAL_PROJECTION )
      *((_BYTE *)this + 492) |= 4u;
  }
  else
  {
    *((_BYTE *)this + 492) |= 6u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100458E0
// Name: public: virtual void CMatRenderContextBase::MultMatrixLocal(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::MultMatrixLocal(CMatRenderContextBase *this, const matrix3x4_t *matrix)
{
  CMatRenderContextBase::MatrixStackItem_t *m_pCurMatrixItem; // edx
  MaterialMatrixMode_t m_MatrixMode; // eax
  VMatrix dst; // [esp+0h] [ebp-80h] BYREF
  VMatrix src2; // [esp+40h] [ebp-40h] BYREF

  *(_QWORD *)&src2.m[0][0] = *(_QWORD *)&matrix->m_flMatVal[0][0];
  *(_QWORD *)&src2.m[0][2] = *(_QWORD *)&matrix->m_flMatVal[0][2];
  *(_OWORD *)&src2.m[1][0] = *(_OWORD *)&matrix->m_flMatVal[1][0];
  *(_QWORD *)&src2.m[2][0] = *(_QWORD *)&matrix->m_flMatVal[2][0];
  m_pCurMatrixItem = this->m_pCurMatrixItem;
  *(_QWORD *)&src2.m[2][2] = *(_QWORD *)&matrix->m_flMatVal[2][2];
  *(_QWORD *)&src2.m[3][0] = 0;
  *(_QWORD *)&src2.m[3][2] = 0x3F80000000000000LL;
  MatrixMultiply(src1: &m_pCurMatrixItem->matrix, &src2, &dst);
  VMatrix::operator=(this: &this->m_pCurMatrixItem->matrix, mOther: &dst);
  this->m_pCurMatrixItem->flags = 1;
  m_MatrixMode = this->m_MatrixMode;
  if ( m_MatrixMode != MATERIAL_VIEW )
  {
    if ( m_MatrixMode == MATERIAL_PROJECTION )
      *((_BYTE *)this + 492) |= 4u;
  }
  else
  {
    *((_BYTE *)this + 492) |= 6u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100459A0
// Name: public: virtual void CMatRenderContextBase::Rotate(float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::Rotate(CMatRenderContextBase *this, float flAngle, float x, float y, float z)
{
  CMatRenderContextBase::MatrixStackItem_t *m_pCurMatrixItem; // edi
  VMatrix mOther; // [esp+Ch] [ebp-8Ch] BYREF
  VMatrix dst; // [esp+4Ch] [ebp-4Ch] BYREF
  Vector vAxisOfRot; // [esp+8Ch] [ebp-Ch] BYREF

  vAxisOfRot.x = x;
  vAxisOfRot.y = y;
  vAxisOfRot.z = z;
  m_pCurMatrixItem = this->m_pCurMatrixItem;
  MatrixBuildRotationAboutAxis(&dst, &vAxisOfRot, angleDegrees: flAngle);
  MatrixMultiply(src1: &m_pCurMatrixItem->matrix, src2: &dst, dst: &mOther);
  VMatrix::operator=(this: &m_pCurMatrixItem->matrix, &mOther);
  this->m_pCurMatrixItem->flags = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10045A20
// Name: public: virtual void CMatRenderContextBase::Translate(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::Translate(CMatRenderContextBase *this, float x, float y, float z)
{
  CMatRenderContextBase::MatrixStackItem_t *m_pCurMatrixItem; // edi
  VMatrix mOther; // [esp+0h] [ebp-8Ch] BYREF
  VMatrix dst; // [esp+40h] [ebp-4Ch] BYREF
  Vector translation; // [esp+80h] [ebp-Ch] BYREF

  m_pCurMatrixItem = this->m_pCurMatrixItem;
  translation.x = x;
  translation.y = y;
  translation.z = z;
  MatrixBuildTranslation(&dst, &translation);
  MatrixMultiply(src1: &m_pCurMatrixItem->matrix, src2: &dst, dst: &mOther);
  VMatrix::operator=(this: &m_pCurMatrixItem->matrix, &mOther);
  this->m_pCurMatrixItem->flags = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10045A90
// Name: public: virtual void __near * CMatRenderContextBase::LockRenderData(int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CMatRenderContextBase::LockRenderData(
        CMatRenderContextBase *this,
        unsigned int nSizeInBytes)
{
  unsigned int v2; // eax
  int v3; // ecx
  CMemoryStack *v4; // esi
  unsigned __int8 *m_pNextAlloc; // edi
  int v6; // ecx
  unsigned __int8 *v7; // ebx

  v2 = dword_1034D154[10 * CMatRenderContextBase::sm_nRenderStack];
  v3 = nSizeInBytes;
  v4 = &CMatRenderContextBase::sm_RenderData[CMatRenderContextBase::sm_nRenderStack];
  if ( nSizeInBytes <= v2 )
    v3 = dword_1034D154[10 * CMatRenderContextBase::sm_nRenderStack];
  m_pNextAlloc = v4->m_pNextAlloc;
  v6 = ~(v2 - 1) & (v2 + v3 - 1);
  v7 = &v4->m_pNextAlloc[v6];
  if ( v7 <= v4->m_pCommitLimit
    || CMemoryStack::CommitTo(
         this: &CMatRenderContextBase::sm_RenderData[CMatRenderContextBase::sm_nRenderStack],
         pNextAlloc: &v4->m_pNextAlloc[v6]) )
  {
    v4->m_pNextAlloc = v7;
    if ( m_pNextAlloc != nullptr )
      goto LABEL_9;
  }
  else
  {
    m_pNextAlloc = nullptr;
  }
  if ( _executeCount_6 < 10 )
  {
    ++_executeCount_6;
    _Warning(a1: "MaterialSystem: Out of memory in render data!\n");
  }
LABEL_9:
  this->AddRefRenderData(this);
  return m_pNextAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x10045B20
// Name: public: virtual void CMatRenderContext::DrawScreenSpaceQuad(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMatRenderContext::DrawScreenSpaceQuad(
        CMatRenderContext *this@<ecx>,
        int a2@<edi>,
        IMaterial *pMaterial)
{
  float v4; // xmm1_4
  float v5; // xmm5_4
  float v6; // xmm0_4
  float v7; // xmm4_4
  void (__thiscall *Bind)(struct CMatRenderContext *, IMaterial *, void *); // edx
  IMesh *v9; // edi
  void (__thiscall *SetPrimitiveType)(IMesh *, MaterialPrimitiveType_t); // edx
  float *m_pCurrPosition; // eax
  _DWORD *v12; // eax
  _DWORD *v13; // eax
  float *m_pCurrNormal; // eax
  float v15; // xmm0_4
  float *v16; // eax
  float *v17; // eax
  _DWORD *v18; // eax
  _DWORD *v19; // eax
  float *v20; // eax
  float v21; // xmm0_4
  float *v22; // eax
  float *v23; // eax
  _DWORD *v24; // eax
  _DWORD *v25; // eax
  float *v26; // eax
  float v27; // xmm0_4
  float *v28; // eax
  float *v29; // eax
  _DWORD *v30; // eax
  _DWORD *v31; // eax
  float *v32; // eax
  float v33; // xmm0_4
  float *v34; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-20Ch] BYREF
  int h; // [esp+1F0h] [ebp-24h] BYREF
  int w; // [esp+1F4h] [ebp-20h] BYREF
  float t0; // [esp+1F8h] [ebp-1Ch]
  float s1; // [esp+1FCh] [ebp-18h]
  float s0; // [esp+200h] [ebp-14h]
  float t1; // [esp+204h] [ebp-10h]
  int v43; // [esp+210h] [ebp-4h]

  this->GetRenderTargetDimensions(this, a2: &w, a3: &h);
  if ( w != 0 && h != 0 )
  {
    v4 = (float)w;
    if ( (float)w == 0.0 )
      v5 = 0.0;
    else
      v5 = 1.0 / v4;
    v6 = (float)h;
    if ( (float)h == 0.0 )
      v7 = 0.0;
    else
      v7 = 1.0 / v6;
    Bind = this->Bind;
    s0 = v5 * 0.5;
    t0 = v7 * 0.5;
    s1 = (float)(v4 - 0.5) * v5;
    t1 = (float)(v6 - 0.5) * v7;
    ((void (__thiscall *)(CMatRenderContext *, IMaterial *, _DWORD, int))Bind)(a1: this, a2: pMaterial, a3: 0, a4: a2);
    v9 = this->GetDynamicMesh(this, a2: 1, a3: 0, a4: 0, a5: 0);
    this->MatrixMode(this, a2: MATERIAL_VIEW);
    this->PushMatrix(this);
    this->LoadIdentity(this);
    this->MatrixMode(this, a2: MATERIAL_PROJECTION);
    this->PushMatrix(this);
    this->LoadIdentity(this);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v9;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_QUADS;
    SetPrimitiveType = v9->SetPrimitiveType;
    v43 = 0;
    SetPrimitiveType(this: v9, a2: MATERIAL_TRIANGLES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v9->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v9, nMaxVertexCount: 4, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = -1.0;
    m_pCurrPosition[1] = -1.0;
    m_pCurrPosition[2] = 0.0;
    v12 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                   + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
    *v12 = 0;
    v12[1] = 1065353216;
    v12[2] = 0;
    v13 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                   + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
    *v13 = 1065353216;
    v13[1] = 0;
    v13[2] = 0;
    m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
    *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
    m_pCurrNormal[1] = 0.0;
    v15 = s0;
    m_pCurrNormal[2] = 1.0;
    v16 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v15;
    v16[1] = t1;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v17 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = -1.0;
    v17[1] = 1.0;
    v17[2] = 0.0;
    v18 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                   + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
    *v18 = 0;
    v18[1] = 1065353216;
    v18[2] = 0;
    v19 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                   + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
    *v19 = 1065353216;
    v19[1] = 0;
    v19[2] = 0;
    v20 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
    *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
    v20[1] = 0.0;
    v21 = s0;
    v20[2] = 1.0;
    v22 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v21;
    v22[1] = t0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v23 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 1.0;
    v23[1] = 1.0;
    v23[2] = 0.0;
    v24 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                   + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
    *v24 = 0;
    v24[1] = 1065353216;
    v24[2] = 0;
    v25 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                   + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
    *v25 = 1065353216;
    v25[1] = 0;
    v25[2] = 0;
    v26 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
    *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
    v26[1] = 0.0;
    v27 = s1;
    v26[2] = 1.0;
    v28 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v27;
    v28[1] = t0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v29 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 1.0;
    v29[1] = -1.0;
    v29[2] = 0.0;
    v30 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                   + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS);
    *v30 = 0;
    v30[1] = 1065353216;
    v30[2] = 0;
    v31 = (_DWORD *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                   + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT);
    *v31 = 1065353216;
    v31[1] = 0;
    v31[2] = 0;
    v32 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
    *meshBuilder.m_VertexBuilder.m_pCurrNormal = 0.0;
    v32[1] = 0.0;
    v33 = s1;
    v32[2] = 1.0;
    v34 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v33;
    v34[1] = t1;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
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
    ((void (__thiscall *)(IMesh *, int, int))meshBuilder.m_pMesh->UnlockMesh)(
      a1: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v9->Draw_2(this: v9, a2: -1, a3: 0);
    this->MatrixMode(this, a2: MATERIAL_VIEW);
    this->PopMatrix(this);
    this->MatrixMode(this, a2: MATERIAL_PROJECTION);
    this->PopMatrix(this);
    v43 = -1;
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046050
// Name: public: virtual void CMatRenderContext::DrawClearBufferQuad(unsigned char,unsigned char,unsigned char,unsigned char,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::DrawClearBufferQuad(
        CMatRenderContext *this,
        unsigned __int8 r,
        unsigned __int8 g,
        unsigned __int8 b,
        unsigned __int8 a,
        bool bClearColor,
        bool bClearAlpha,
        bool bClearDepth)
{
  IMesh *v9; // ebx
  int v10; // xmm0_4
  void (__thiscall *SetPrimitiveType)(IMesh *, MaterialPrimitiveType_t); // eax
  float *m_pCurrPosition; // eax
  int v13; // edi
  float *v14; // eax
  float *v15; // eax
  float *v16; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-1F4h] BYREF
  int v19; // [esp+1FCh] [ebp-4h]

  this->Bind(
    this,
    a2: (&(&this->m_pMaterialSystem->m_pBufferClearObeyStencil[4 * bClearDepth])[2 * bClearAlpha])[bClearColor],
    a3: nullptr);
  v9 = this->GetDynamicMesh(this, a2: 1, a3: 0, a4: 0, a5: 0);
  this->MatrixMode(this, a2: MATERIAL_MODEL);
  this->PushMatrix(this);
  this->LoadIdentity(this);
  this->MatrixMode(this, a2: MATERIAL_VIEW);
  this->PushMatrix(this);
  this->LoadIdentity(this);
  this->MatrixMode(this, a2: MATERIAL_PROJECTION);
  this->PushMatrix(this);
  this->LoadIdentity(this);
  if ( this->m_pMaterialSystem->GetConfig(this: &this->m_pMaterialSystem->IShaderUtil)->bReverseDepth )
    v10 = 0;
  else
    v10 = 1065353216;
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v9;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_QUADS;
  SetPrimitiveType = v9->SetPrimitiveType;
  v19 = 0;
  SetPrimitiveType(this: v9, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v9->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v9, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = -1.1;
  m_pCurrPosition[1] = -1.1;
  *((_DWORD *)m_pCurrPosition + 2) = v10;
  v13 = b | ((g | ((r | (a << 8)) << 8)) << 8);
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v13;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v14 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = -1.1;
  v14[1] = 1.1;
  *((_DWORD *)v14 + 2) = v10;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v13;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v15 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = 1.1;
  v15[1] = 1.1;
  *((_DWORD *)v15 + 2) = v10;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v13;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v16 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = 1.1;
  v16[1] = -1.1;
  *((_DWORD *)v16 + 2) = v10;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v13;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
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
  v9->Draw_2(this: v9, a2: -1, a3: 0);
  this->MatrixMode(this, a2: MATERIAL_MODEL);
  this->PopMatrix(this);
  this->MatrixMode(this, a2: MATERIAL_VIEW);
  this->PopMatrix(this);
  this->MatrixMode(this, a2: MATERIAL_PROJECTION);
  this->PopMatrix(this);
  v19 = -1;
  CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
}

//------------------------------------------------------------------------------
// Address: 0x10046400
// Name: public: virtual void CMatRenderContext::FogColor3f(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::FogColor3f(CMatRenderContext *this, float r, float g, float b)
{
  int v4; // eax
  int v5; // esi
  int v6; // eax
  int v7; // edx
  int v8; // eax

  v4 = (int)(float)(r * 255.0);
  if ( v4 >= 0 )
  {
    v5 = 255;
    if ( v4 <= 255 )
      v5 = (int)(float)(r * 255.0);
  }
  else
  {
    v5 = 0;
  }
  v6 = (int)(float)(g * 255.0);
  if ( v6 >= 0 )
  {
    v7 = 255;
    if ( v6 <= 255 )
      v7 = (int)(float)(g * 255.0);
  }
  else
  {
    v7 = 0;
  }
  v8 = (int)(float)(b * 255.0);
  if ( v8 >= 0 )
  {
    if ( v8 > 255 )
      v8 = 255;
  }
  else
  {
    v8 = 0;
  }
  g_pShaderAPI->SceneFogColor3ub(this: g_pShaderAPI, a2: v5, a3: v7, a4: v8);
}

//------------------------------------------------------------------------------
// Address: 0x10046490
// Name: public: virtual void CMatRenderContext::FogColor3fv(float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::FogColor3fv(CMatRenderContext *this, const float *rgb)
{
  int v2; // eax
  float v3; // xmm1_4
  int v4; // esi
  int v5; // edx

  v2 = (int)(float)(*rgb * 255.0);
  if ( v2 >= 0 )
  {
    if ( v2 > 255 )
      v2 = 255;
  }
  else
  {
    v2 = 0;
  }
  v3 = rgb[1] * 255.0;
  if ( (int)v3 >= 0 )
  {
    v4 = 255;
    if ( (int)v3 <= 255 )
      v4 = (int)v3;
  }
  else
  {
    v4 = 0;
  }
  v5 = (int)(float)(rgb[2] * 255.0);
  if ( v5 >= 0 )
  {
    if ( v5 > 255 )
      v5 = 255;
  }
  else
  {
    v5 = 0;
  }
  g_pShaderAPI->SceneFogColor3ub(this: g_pShaderAPI, a2: v2, a3: v4, a4: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10046560
// Name: public: void CUtlMemory<struct CMatRenderContextBase::RenderTargetStackElement_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CMatRenderContextBase::RenderTargetStackElement_t,int>::Grow(
        CUtlMemory<CMatRenderContextBase::RenderTargetStackElement_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CMatRenderContextBase::RenderTargetStackElement_t *m_pMemory; // edx
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
    v7 = 36 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CMatRenderContextBase::RenderTargetStackElement_t *)_g_pMemAlloc->Realloc_2(
                                                                               this: _g_pMemAlloc,
                                                                               a2: m_pMemory,
                                                                               a3: v7);
    else
      this->m_pMemory = (CMatRenderContextBase::RenderTargetStackElement_t *)_g_pMemAlloc->Alloc_2(
                                                                               this: _g_pMemAlloc,
                                                                               a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046600
// Name: public: void CUtlMemory<struct CMatRenderContextBase::ScissorRectStackElement_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CMatRenderContextBase::ScissorRectStackElement_t,int>::Grow(
        CUtlMemory<CUtlString,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlString *m_pMemory; // edx
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
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlString *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUtlString *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046690
// Name: public: void CUtlMemory<struct CMatRenderContextBase::MatrixStackItem_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Grow(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CMatRenderContextBase::MatrixStackItem_t *m_pMemory; // edx

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
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CMatRenderContextBase::MatrixStackItem_t *)_g_pMemAlloc->Realloc_2(
                                                                      this: _g_pMemAlloc,
                                                                      a2: m_pMemory,
                                                                      a3: 68 * m_nAllocationCount);
    else
      this->m_pMemory = (CMatRenderContextBase::MatrixStackItem_t *)_g_pMemAlloc->Alloc_2(
                                                                      this: _g_pMemAlloc,
                                                                      a2: 68 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046740
// Name: public: void CUtlMemory<struct CMatRenderContextBase::PlaneStackElement,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CMatRenderContextBase::PlaneStackElement,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MissingMaterial_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CMaterialDict::MissingMaterial_t,int> *m_pMemory; // edx
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
    v7 = 20 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CMaterialDict::MissingMaterial_t,int> *)_g_pMemAlloc->Realloc_2(
                                                                                   this: _g_pMemAlloc,
                                                                                   a2: m_pMemory,
                                                                                   a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CMaterialDict::MissingMaterial_t,int> *)_g_pMemAlloc->Alloc_2(
                                                                                   this: _g_pMemAlloc,
                                                                                   a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100467E0
// Name: public: virtual int CMatRenderContext::GetLightmapTexture(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatRenderContext::GetLightmapTexture(CMatRenderContext *this, int nLightmapPage)
{
  int result; // eax
  CMaterialSystem *m_pMaterialSystem; // ecx

  switch ( nLightmapPage )
  {
    case -4:
      goto $LN5_10;
    case -3:
      result = this->m_pUserDefinedLightmap->GetTextureHandle(this: this->m_pUserDefinedLightmap, a2: 0, a3: 0);
      break;
    case -2:
      result = this->m_pMaterialSystem->m_FullbrightBumpedLightmapTextureHandle;
      break;
    case -1:
      result = this->m_pMaterialSystem->m_FullbrightLightmapTextureHandle;
      break;
    default:
      if ( nLightmapPage < 0
        || (m_pMaterialSystem = this->m_pMaterialSystem,
            nLightmapPage >= m_pMaterialSystem->m_Lightmaps.m_NumLightmapPages) )
      {
$LN5_10:
        result = 0;
      }
      else
      {
        result = m_pMaterialSystem->m_Lightmaps.m_LightmapPageTextureHandles.m_Memory.m_pMemory[nLightmapPage];
      }
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10046860
// Name: public: virtual void CMatRenderContext::PopCustomClipPlane(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::PopCustomClipPlane(CMatRenderContext *this)
{
  int v2; // eax
  CMatRenderContextBase::PlaneStackElement *m_pMemory; // edx
  bool *p_bHack_IsHeightClipPlane; // ecx

  v2 = this->m_CustomClipPlanes.m_Size - 1;
  if ( v2 >= 0 )
  {
    m_pMemory = this->m_CustomClipPlanes.m_Memory.m_pMemory;
    p_bHack_IsHeightClipPlane = &m_pMemory[v2].bHack_IsHeightClipPlane;
    while ( *p_bHack_IsHeightClipPlane )
    {
      p_bHack_IsHeightClipPlane -= 20;
      if ( --v2 < 0 )
        goto LABEL_9;
    }
    if ( this->m_CustomClipPlanes.m_Size - v2 - 1 > 0 )
      _V_memmove(dest: &m_pMemory[v2], src: &m_pMemory[v2 + 1], count: 20 * (this->m_CustomClipPlanes.m_Size - v2 - 1));
    --this->m_CustomClipPlanes.m_Size;
  }
LABEL_9:
  this->ApplyCustomClipPlanes(this);
}

//------------------------------------------------------------------------------
// Address: 0x100468D0
// Name: public: virtual void CMatRenderContext::ApplyCustomClipPlanes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::ApplyCustomClipPlanes(CMatRenderContext *this)
{
  int (__thiscall *MaxUserClipPlanes)(struct IHardwareConfigInternal *); // edx
  int v3; // eax
  bool v4; // zf
  int v5; // edi
  int m_Size; // ebx
  void (__thiscall *SyncMatrices)(struct CMatRenderContext *); // edx
  int v8; // esi
  int v9; // edi
  int v10; // esi
  int v11; // ecx
  int v12; // edi
  float fFakePlane[4]; // [esp+Ch] [ebp-1Ch] BYREF
  CMatRenderContext *v14; // [esp+1Ch] [ebp-Ch]
  int iMaxClipPlanes; // [esp+20h] [ebp-8h]
  int v16; // [esp+24h] [ebp-4h]

  MaxUserClipPlanes = g_pHWConfig->MaxUserClipPlanes;
  v14 = this;
  v3 = MaxUserClipPlanes(this: g_pHWConfig);
  v4 = (*((_BYTE *)&this->CMatRenderContextBase + 492) & 8) == 0;
  v5 = v3;
  iMaxClipPlanes = v3;
  if ( v4 )
    m_Size = 0;
  else
    m_Size = this->m_CustomClipPlanes.m_Size;
  SyncMatrices = this->SyncMatrices;
  memset(fFakePlane, 255, sizeof(fFakePlane));
  SyncMatrices(this);
  if ( v5 < 1 || g_pHWConfig->UseFastClipping(this: g_pHWConfig) )
  {
    if ( m_Size != 0 )
    {
      g_pShaderAPI->EnableFastClip(this: g_pShaderAPI, a2: true);
      g_pShaderAPI->SetFastClipPlane(
        this: g_pShaderAPI,
        a2: (const float *)&this->m_CustomClipPlanes.m_Memory.m_pMemory[m_Size - 1]);
    }
    else
    {
      g_pShaderAPI->EnableFastClip(this: g_pShaderAPI, a2: false);
      g_pShaderAPI->SetFastClipPlane(this: g_pShaderAPI, a2: fFakePlane);
    }
  }
  else if ( v5 < m_Size )
  {
    v10 = m_Size - v5;
    if ( m_Size - v5 < m_Size )
    {
      v11 = 20 * v10;
      v16 = 20 * v10;
      while ( 1 )
      {
        v12 = v10 % v5;
        g_pShaderAPI->SetClipPlane(
          this: g_pShaderAPI,
          a2: v12,
          a3: (const float *)((char *)v14->m_CustomClipPlanes.m_Memory.m_pMemory + v11));
        g_pShaderAPI->EnableClipPlane(this: g_pShaderAPI, a2: v12, a3: true);
        v16 += 20;
        if ( ++v10 >= m_Size )
          break;
        v11 = v16;
        v5 = iMaxClipPlanes;
      }
    }
  }
  else
  {
    v8 = 0;
    if ( m_Size > 0 )
    {
      v9 = 0;
      do
      {
        g_pShaderAPI->SetClipPlane(
          this: g_pShaderAPI,
          a2: v8,
          a3: (const float *)&v14->m_CustomClipPlanes.m_Memory.m_pMemory[v9]);
        g_pShaderAPI->EnableClipPlane(this: g_pShaderAPI, a2: v8++, a3: true);
        ++v9;
      }
      while ( v8 < m_Size );
      v5 = iMaxClipPlanes;
    }
    for ( ; v8 < v5; ++v8 )
    {
      g_pShaderAPI->EnableClipPlane(this: g_pShaderAPI, a2: v8, a3: false);
      g_pShaderAPI->SetClipPlane(this: g_pShaderAPI, a2: v8, a3: fFakePlane);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046AC0
// Name: public: void CUtlStack<struct CMatRenderContextBase::MatrixStackItem_t,class CUtlMemory<struct CMatRenderContextBase::MatrixStackItem_t,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlStack<CMatRenderContextBase::MatrixStackItem_t,CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>>::EnsureCapacity(
        CUtlStack<CMatRenderContextBase::MatrixStackItem_t,CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> > *this,
        int num)
{
  CMatRenderContextBase::MatrixStackItem_t *m_pMemory; // eax
  CMatRenderContextBase::MatrixStackItem_t *v4; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    m_pMemory = this->m_Memory.m_pMemory;
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = m_pMemory;
      return;
    }
    this->m_Memory.m_nAllocationCount = num;
    if ( m_pMemory != nullptr )
    {
      m_pMemory = (CMatRenderContextBase::MatrixStackItem_t *)_g_pMemAlloc->Realloc_2(
                                                                this: _g_pMemAlloc,
                                                                a2: m_pMemory,
                                                                a3: 68 * num);
      this->m_Memory.m_pMemory = m_pMemory;
      goto LABEL_5;
    }
    v4 = (CMatRenderContextBase::MatrixStackItem_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 68 * num);
    this->m_Memory.m_pMemory = v4;
    this->m_pElements = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046B30
// Name: public: virtual class ITexture __near * CMatRenderContextBase::GetRenderTarget(void)
// Source: json
//------------------------------------------------------------------------------
ITexture *__thiscall CMatRenderContextBase::GetRenderTarget(CMatRenderContextBase *this)
{
  if ( this->m_RenderTargetStack.m_Size <= 0 )
    return nullptr;
  else
    return this->m_RenderTargetStack.m_Memory.m_pMemory[this->m_RenderTargetStack.m_Size - 1].m_pRenderTargets[0];
}

//------------------------------------------------------------------------------
// Address: 0x10046B50
// Name: public: virtual class ITexture __near * CMatRenderContextBase::GetRenderTargetEx(int)
// Source: json
//------------------------------------------------------------------------------
ITexture *__thiscall CMatRenderContextBase::GetRenderTargetEx(CMatRenderContextBase *this, int nRenderTargetID)
{
  return (&(&this->m_RenderTargetStack.m_Memory.m_pMemory[-1].m_pRenderTargets[8 * this->m_RenderTargetStack.m_Size])[this->m_RenderTargetStack.m_Size])[nRenderTargetID];
}

//------------------------------------------------------------------------------
// Address: 0x10046B70
// Name: public: virtual void CMatRenderContextBase::MatrixMode(enum MaterialMatrixMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::MatrixMode(CMatRenderContextBase *this, MaterialMatrixMode_t mode)
{
  this->m_MatrixMode = mode;
  this->m_pCurMatrixItem = &this->m_MatrixStacks[mode].m_Memory.m_pMemory[this->m_MatrixStacks[mode].m_Size - 1];
}

//------------------------------------------------------------------------------
// Address: 0x10046BA0
// Name: public: virtual void CMatRenderContextBase::PopMatrix(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::PopMatrix(CMatRenderContextBase *this)
{
  MaterialMatrixMode_t m_MatrixMode; // eax

  --this->m_MatrixStacks[this->m_MatrixMode].m_Size;
  m_MatrixMode = this->m_MatrixMode;
  this->m_pCurMatrixItem = &this->m_MatrixStacks[m_MatrixMode].m_Memory.m_pMemory[this->m_MatrixStacks[m_MatrixMode].m_Size
                                                                                - 1];
  if ( m_MatrixMode != MATERIAL_VIEW )
  {
    if ( m_MatrixMode == MATERIAL_PROJECTION )
      *((_BYTE *)this + 492) |= 4u;
  }
  else
  {
    *((_BYTE *)this + 492) |= 6u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046BF0
// Name: public: virtual void CMatRenderContextBase::GetMatrix(enum MaterialMatrixMode_t,class VMatrix __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::GetMatrix(
        CMatRenderContextBase *this,
        MaterialMatrixMode_t matrixMode,
        VMatrix *pMatrix)
{
  CUtlStack<CMatRenderContextBase::MatrixStackItem_t,CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> > *v3; // ecx
  int m_Size; // eax

  v3 = &this->m_MatrixStacks[matrixMode];
  m_Size = v3->m_Size;
  if ( m_Size != 0 )
    VMatrix::operator=(this: pMatrix, mOther: &v3->m_Memory.m_pMemory[m_Size - 1].matrix);
  else
    MatrixSetIdentity(dst: pMatrix);
}

//------------------------------------------------------------------------------
// Address: 0x10046C30
// Name: public: virtual void CMatRenderContextBase::GetMatrix(enum MaterialMatrixMode_t,struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::GetMatrix(
        CMatRenderContextBase *this,
        MaterialMatrixMode_t matrixMode,
        matrix3x4_t *pMatrix)
{
  CUtlStack<CMatRenderContextBase::MatrixStackItem_t,CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> > *v3; // ecx
  int m_Size; // eax
  int v5; // edx
  CMatRenderContextBase::MatrixStackItem_t *m_pMemory; // eax
  __int64 v7; // xmm0_8
  CMatRenderContextBase::MatrixStackItem_t *v8; // eax

  v3 = &this->m_MatrixStacks[matrixMode];
  m_Size = v3->m_Size;
  if ( m_Size != 0 )
  {
    v5 = m_Size;
    m_pMemory = v3->m_Memory.m_pMemory;
    *(_QWORD *)&pMatrix->m_flMatVal[0][0] = *(_QWORD *)&v3->m_Memory.m_pMemory[v5 - 1].matrix.m[0][0];
    v7 = *(_QWORD *)&m_pMemory[v5 - 1].matrix.m[0][2];
    v8 = &m_pMemory[v5 - 1];
    *(_QWORD *)&pMatrix->m_flMatVal[0][2] = v7;
    *(_QWORD *)&pMatrix->m_flMatVal[1][0] = *(_QWORD *)&v8->matrix.m[1][0];
    *(_QWORD *)&pMatrix->m_flMatVal[1][2] = *(_QWORD *)&v8->matrix.m[1][2];
    *(_QWORD *)&pMatrix->m_flMatVal[2][0] = *(_QWORD *)&v8->matrix.m[2][0];
    *(_QWORD *)&pMatrix->m_flMatVal[2][2] = *(_QWORD *)&v8->matrix.m[2][2];
  }
  else
  {
    SetIdentityMatrix(matrix: pMatrix);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046CB0
// Name: public: virtual void CMatRenderContextBase::PopRenderTargetAndViewport(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::PopRenderTargetAndViewport(CMatRenderContextBase *this)
{
  if ( this->m_RenderTargetStack.m_Size != 0 )
  {
    this->Flush(this, a2: false);
    --this->m_RenderTargetStack.m_Size;
    this->CommitRenderTargetAndViewport(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046CE0
// Name: public: virtual void CMatRenderContext::MatrixMode(enum MaterialMatrixMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::MatrixMode(CMatRenderContext *this, MaterialMatrixMode_t mode)
{
  this->m_MatrixMode = mode;
  this->m_pCurMatrixItem = &this->m_MatrixStacks[mode].m_Memory.m_pMemory[this->m_MatrixStacks[mode].m_Size - 1];
  g_pShaderAPI->MatrixMode(this: g_pShaderAPI, a2: mode);
}

//------------------------------------------------------------------------------
// Address: 0x10046D20
// Name: public: virtual void CMatRenderContext::PopMatrix(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::PopMatrix(CMatRenderContext *this)
{
  MaterialMatrixMode_t m_MatrixMode; // eax

  --this->m_MatrixStacks[this->m_MatrixMode].m_Size;
  m_MatrixMode = this->m_MatrixMode;
  this->m_pCurMatrixItem = &this->m_MatrixStacks[m_MatrixMode].m_Memory.m_pMemory[this->m_MatrixStacks[m_MatrixMode].m_Size
                                                                                - 1];
  if ( m_MatrixMode != MATERIAL_VIEW )
  {
    if ( m_MatrixMode == MATERIAL_PROJECTION )
      *((_BYTE *)&this->CMatRenderContextBase + 492) |= 4u;
  }
  else
  {
    *((_BYTE *)&this->CMatRenderContextBase + 492) |= 6u;
  }
  g_pShaderAPI->PopMatrix(this: g_pShaderAPI);
}

//------------------------------------------------------------------------------
// Address: 0x10046D80
// Name: public: void CMatRenderContext::ForceSyncMatrix(enum MaterialMatrixMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::ForceSyncMatrix(CMatRenderContext *this, MaterialMatrixMode_t mode)
{
  CUtlStack<CMatRenderContextBase::MatrixStackItem_t,CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> > *v2; // eax
  int v3; // edi
  bool v4; // bl
  VMatrix transposeTop; // [esp+8h] [ebp-40h] BYREF

  v2 = &this->m_MatrixStacks[mode];
  v3 = (int)&v2->m_Memory.m_pMemory[this->m_MatrixStacks[mode].m_Size - 1];
  if ( (v2->m_Memory.m_pMemory[this->m_MatrixStacks[mode].m_Size - 1].flags & 1) != 0 )
  {
    v4 = this->m_MatrixMode != mode;
    if ( this->m_MatrixMode != mode )
      g_pShaderAPI->MatrixMode(this: g_pShaderAPI, a2: mode);
    if ( (*(_BYTE *)(v3 + 64) & 2) != 0 )
    {
      g_pShaderAPI->LoadIdentity(this: g_pShaderAPI);
    }
    else
    {
      MatrixTranspose(src: (const VMatrix *)v3, dst: &transposeTop);
      g_pShaderAPI->LoadMatrix(this: g_pShaderAPI, a2: (float *)&transposeTop);
    }
    if ( v4 )
      g_pShaderAPI->MatrixMode(this: g_pShaderAPI, a2: mode);
    *(_DWORD *)(v3 + 64) &= ~1u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046E30
// Name: public: virtual void CMatRenderContext::CommitRenderTargetAndViewport(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::CommitRenderTargetAndViewport(CMatRenderContext *this)
{
  CMatRenderContextBase::RenderTargetStackElement_t *v2; // edi
  unsigned int i; // ebx
  ITexture *v4; // ecx

  v2 = &this->m_RenderTargetStack.m_Memory.m_pMemory[this->m_RenderTargetStack.m_Size - 1];
  for ( i = 0; i < 4; ++i )
  {
    v4 = v2->m_pRenderTargets[i];
    if ( v4 != nullptr )
    {
      ((void (__thiscall *)(ITexture *, unsigned int, ITexture *))v4->__vftable[1].GetActualHeight)(
        a1: v4,
        a2: i,
        a3: v2->m_pDepthTexture);
      if ( i != 0 )
        continue;
      if ( v2->m_pRenderTargets[0]->GetImageFormat(this: v2->m_pRenderTargets[0]) == IMAGE_FORMAT_RGBA16161616F
        || v2->m_pRenderTargets[0]->GetImageFormat(this: v2->m_pRenderTargets[0]) == IMAGE_FORMAT_RGBA32323232F )
      {
        g_pShaderAPI->EnableLinearColorSpaceFrameBuffer(this: g_pShaderAPI, a2: true);
      }
      else
      {
        g_pShaderAPI->EnableLinearColorSpaceFrameBuffer(this: g_pShaderAPI, a2: false);
      }
      if ( v2->m_nViewW < 0 || v2->m_nViewH < 0 )
      {
        this->m_Viewport.m_nTopLeftX = 0;
        this->m_Viewport.m_nTopLeftY = 0;
        this->m_Viewport.m_nWidth = v2->m_pRenderTargets[0]->GetActualWidth(this: v2->m_pRenderTargets[0]);
        this->m_Viewport.m_nHeight = v2->m_pRenderTargets[0]->GetActualHeight(this: v2->m_pRenderTargets[0]);
        g_pShaderAPI->SetViewports(this: g_pShaderAPI, a2: 1, a3: &this->m_Viewport, a4: false);
        continue;
      }
    }
    else
    {
      g_pShaderAPI->SetRenderTargetEx(this: g_pShaderAPI, a2: i, a3: -1, a4: -1);
      g_pShaderAPI->EnableLinearColorSpaceFrameBuffer(this: g_pShaderAPI, a2: false);
      if ( i != 0 )
        continue;
      if ( v2->m_nViewW < 0 || v2->m_nViewH < 0 )
      {
        this->m_Viewport.m_nTopLeftX = 0;
        this->m_Viewport.m_nTopLeftY = 0;
        g_pShaderAPI->GetBackBufferDimensions(
          this: g_pShaderAPI,
          a2: &this->m_Viewport.m_nWidth,
          a3: &this->m_Viewport.m_nHeight);
        g_pShaderAPI->SetViewports(this: g_pShaderAPI, a2: 1, a3: &this->m_Viewport, a4: false);
        continue;
      }
    }
    this->m_Viewport.m_nTopLeftX = v2->m_nViewX;
    this->m_Viewport.m_nTopLeftY = v2->m_nViewY;
    this->m_Viewport.m_nWidth = v2->m_nViewW;
    this->m_Viewport.m_nHeight = v2->m_nViewH;
    g_pShaderAPI->SetViewports(this: g_pShaderAPI, a2: 1, a3: &this->m_Viewport, a4: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046FA0
// Name: public: virtual void CMatRenderContext::GetRenderTargetDimensions(int __near &,int __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::GetRenderTargetDimensions(CMatRenderContext *this, int *width, int *height)
{
  ITexture *v3; // esi

  v3 = this->m_RenderTargetStack.m_Memory.m_pMemory[this->m_RenderTargetStack.m_Size - 1].m_pRenderTargets[0];
  if ( v3 != nullptr )
  {
    *width = v3->GetActualWidth(this: this->m_RenderTargetStack.m_Memory.m_pMemory[this->m_RenderTargetStack.m_Size - 1].m_pRenderTargets[0]);
    *height = v3->GetActualHeight(this: v3);
  }
  else
  {
    g_pShaderAPI->GetBackBufferDimensions(this: g_pShaderAPI, a2: width, a3: height);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046FF0
// Name: public: virtual void CMatRenderContext::GetViewport(int __near &,int __near &,int __near &,int __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::GetViewport(CMatRenderContext *this, int *x, int *y, int *width, int *height)
{
  int m_Size; // eax
  CMatRenderContextBase::RenderTargetStackElement_t *m_pMemory; // ecx
  ITexture **v7; // esi

  m_Size = this->m_RenderTargetStack.m_Size;
  m_pMemory = this->m_RenderTargetStack.m_Memory.m_pMemory;
  m_Size *= 9;
  v7 = &m_pMemory[-1].m_pRenderTargets[m_Size];
  if ( (int)m_pMemory->m_pRenderTargets[m_Size - 2] <= 0 || (int)v7[8] <= 0 )
  {
    *y = 0;
    *x = 0;
    if ( *v7 != nullptr )
    {
      *width = (*v7)->GetActualWidth(this: *v7);
      *height = (*v7)->GetActualHeight(this: *v7);
    }
    else
    {
      g_pShaderAPI->GetBackBufferDimensions(this: g_pShaderAPI, a2: width, a3: height);
    }
  }
  else
  {
    *x = (int)v7[5];
    *y = (int)v7[6];
    *width = (int)v7[7];
    *height = (int)v7[8];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047090
// Name: public: virtual void CMatRenderContext::PopScissorRect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::PopScissorRect(CMatRenderContext *this)
{
  CMatRenderContextBase::ScissorRectStackElement_t *m_pMemory; // edx

  if ( this->m_ScissorRectStack.m_Size > 0 )
  {
    if ( --this->m_ScissorRectStack.m_Size <= 0 )
    {
      g_pShaderAPI->SetScissorRect(this: g_pShaderAPI, a2: -1, a3: -1, a4: -1, a5: -1, a6: false);
    }
    else
    {
      m_pMemory = this->m_ScissorRectStack.m_Memory.m_pMemory;
      g_pShaderAPI->SetScissorRect(
        this: g_pShaderAPI,
        a2: m_pMemory[this->m_ScissorRectStack.m_Size - 1].nLeft,
        a3: m_pMemory[this->m_ScissorRectStack.m_Size - 1].nTop,
        a4: m_pMemory[this->m_ScissorRectStack.m_Size - 1].nRight,
        a5: m_pMemory[this->m_ScissorRectStack.m_Size - 1].nBottom,
        a6: true);
    }
  }
  else
  {
    DevMsg(a1: "Scissor Rect Stack underflow.  Too many Pops?\n");
    g_pShaderAPI->SetScissorRect(this: g_pShaderAPI, a2: -1, a3: -1, a4: -1, a5: -1, a6: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047130
// Name: public: int CUtlStack<struct CMatRenderContextBase::RenderTargetStackElement_t,class CUtlMemory<struct CMatRenderContextBase::RenderTargetStackElement_t,int>>::Push(struct CMatRenderContextBase::RenderTargetStackElement_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlStack<CMatRenderContextBase::RenderTargetStackElement_t,CUtlMemory<CMatRenderContextBase::RenderTargetStackElement_t,int>>::Push(
        CUtlStack<CMatRenderContextBase::RenderTargetStackElement_t,CUtlMemory<CMatRenderContextBase::RenderTargetStackElement_t,int> > *this,
        const CMatRenderContextBase::RenderTargetStackElement_t *src)
{
  CMatRenderContextBase::RenderTargetStackElement_t *v3; // eax

  if ( this->m_Size >= this->m_Memory.m_nAllocationCount )
    CUtlMemory<CMatRenderContextBase::RenderTargetStackElement_t,int>::Grow(this: &this->m_Memory, num: 1);
  v3 = &this->m_Memory.m_pMemory[this->m_Size++];
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v3 != nullptr )
    *v3 = *src;
  return this->m_Size - 1;
}

//------------------------------------------------------------------------------
// Address: 0x10047220
// Name: public: virtual void CMatRenderContextBase::SetRenderTargetEx(int,class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::SetRenderTargetEx(
        CMatRenderContextBase *this,
        int nRenderTargetID,
        ITexture *pNewTarget)
{
  int m_Size; // eax
  CMatRenderContextBase::RenderTargetStackElement_t *m_pMemory; // edx
  CUtlStack<CMatRenderContextBase::RenderTargetStackElement_t,CUtlMemory<CMatRenderContextBase::RenderTargetStackElement_t,int> > *p_m_RenderTargetStack; // ecx
  __int64 v6; // xmm0_8
  int v7; // eax
  __int64 v8; // xmm0_8
  int v9; // eax
  CMatRenderContextBase::RenderTargetStackElement_t newTOS; // [esp+0h] [ebp-24h] BYREF

  m_Size = this->m_RenderTargetStack.m_Size;
  m_pMemory = this->m_RenderTargetStack.m_Memory.m_pMemory;
  p_m_RenderTargetStack = &this->m_RenderTargetStack;
  m_Size *= 9;
  v6 = *(_QWORD *)&m_pMemory[-1].m_pRenderTargets[m_Size];
  v7 = (int)&m_pMemory[-1].m_pRenderTargets[m_Size];
  *(_QWORD *)newTOS.m_pRenderTargets = v6;
  *(_QWORD *)&newTOS.m_pRenderTargets[2] = *(_QWORD *)(v7 + 8);
  *(_QWORD *)&newTOS.m_pDepthTexture = *(_QWORD *)(v7 + 16);
  v8 = *(_QWORD *)(v7 + 24);
  v9 = *(_DWORD *)(v7 + 32);
  --p_m_RenderTargetStack->m_Size;
  newTOS.m_nViewH = v9;
  *(_QWORD *)&newTOS.m_nViewY = v8;
  newTOS.m_pRenderTargets[nRenderTargetID] = pNewTarget;
  CUtlStack<CMatRenderContextBase::RenderTargetStackElement_t,CUtlMemory<CMatRenderContextBase::RenderTargetStackElement_t,int>>::Push(
    this: p_m_RenderTargetStack,
    src: &newTOS);
}

//------------------------------------------------------------------------------
// Address: 0x10047290
// Name: public: virtual void CMatRenderContextBase::PushMatrix(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::PushMatrix(CMatRenderContextBase *this)
{
  CUtlStack<CMatRenderContextBase::MatrixStackItem_t,CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> > *v2; // esi
  CMatRenderContextBase::MatrixStackItem_t *m_pMemory; // edi
  int v4; // edx
  CMatRenderContextBase::MatrixStackItem_t *v5; // edi
  MaterialMatrixMode_t m_MatrixMode; // eax

  v2 = &this->m_MatrixStacks[this->m_MatrixMode];
  if ( this->m_MatrixStacks[this->m_MatrixMode].m_Size >= this->m_MatrixStacks[this->m_MatrixMode].m_Memory.m_nAllocationCount )
    CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Grow(
      this: &this->m_MatrixStacks[this->m_MatrixMode].m_Memory,
      num: 1);
  ++v2->m_Size;
  m_pMemory = v2->m_Memory.m_pMemory;
  v4 = v2->m_Size - 1;
  v2->m_pElements = v2->m_Memory.m_pMemory;
  v5 = &m_pMemory[v4];
  VMatrix::operator=(this: &v5->matrix, mOther: &v5[-1].matrix);
  v5->flags = v5[-1].flags;
  this->m_pCurMatrixItem = &v2->m_Memory.m_pMemory[v2->m_Size - 1];
  m_MatrixMode = this->m_MatrixMode;
  if ( m_MatrixMode != MATERIAL_VIEW )
  {
    if ( m_MatrixMode == MATERIAL_PROJECTION )
      *((_BYTE *)this + 492) |= 4u;
  }
  else
  {
    *((_BYTE *)this + 492) |= 6u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047310
// Name: public: virtual void CMatRenderContextBase::Viewport(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::Viewport(CMatRenderContextBase *this, int x, int y, int width, int height)
{
  int m_Size; // eax
  CMatRenderContextBase::RenderTargetStackElement_t *m_pMemory; // edx
  CUtlStack<CMatRenderContextBase::RenderTargetStackElement_t,CUtlMemory<CMatRenderContextBase::RenderTargetStackElement_t,int> > *p_m_RenderTargetStack; // ecx
  __int64 v8; // xmm0_8
  int v9; // eax
  CMatRenderContextBase::RenderTargetStackElement_t newTOS; // [esp+0h] [ebp-24h] BYREF

  m_Size = this->m_RenderTargetStack.m_Size;
  m_pMemory = this->m_RenderTargetStack.m_Memory.m_pMemory;
  p_m_RenderTargetStack = &this->m_RenderTargetStack;
  m_Size *= 9;
  v8 = *(_QWORD *)&m_pMemory[-1].m_pRenderTargets[m_Size];
  v9 = (int)&m_pMemory[-1].m_pRenderTargets[m_Size];
  *(_QWORD *)newTOS.m_pRenderTargets = v8;
  *(_QWORD *)&newTOS.m_pRenderTargets[2] = *(_QWORD *)(v9 + 8);
  *(_QWORD *)&newTOS.m_pDepthTexture = *(_QWORD *)(v9 + 16);
  --p_m_RenderTargetStack->m_Size;
  newTOS.m_nViewX = x;
  newTOS.m_nViewW = width;
  newTOS.m_nViewY = y;
  newTOS.m_nViewH = height;
  CUtlStack<CMatRenderContextBase::RenderTargetStackElement_t,CUtlMemory<CMatRenderContextBase::RenderTargetStackElement_t,int>>::Push(
    this: p_m_RenderTargetStack,
    src: &newTOS);
}

//------------------------------------------------------------------------------
// Address: 0x10047380
// Name: public: virtual void CMatRenderContextBase::PushRenderTargetAndViewport(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::PushRenderTargetAndViewport(CMatRenderContextBase *this)
{
  int v2; // eax
  CMatRenderContextBase::RenderTargetStackElement_t *m_pMemory; // edx
  unsigned int v4; // eax
  CMatRenderContextBase::RenderTargetStackElement_t *v5; // eax
  CMatRenderContextBase::RenderTargetStackElement_t *v6; // ecx

  v2 = this->m_RenderTargetStack.m_Size + 1;
  if ( this->m_RenderTargetStack.m_Memory.m_nAllocationCount < v2 && this->m_RenderTargetStack.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_RenderTargetStack.m_Memory.m_pMemory;
    this->m_RenderTargetStack.m_Memory.m_nAllocationCount = v2;
    v4 = 36 * v2;
    if ( m_pMemory != nullptr )
      v5 = (CMatRenderContextBase::RenderTargetStackElement_t *)_g_pMemAlloc->Realloc_2(
                                                                  this: _g_pMemAlloc,
                                                                  a2: m_pMemory,
                                                                  a3: v4);
    else
      v5 = (CMatRenderContextBase::RenderTargetStackElement_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_RenderTargetStack.m_Memory.m_pMemory = v5;
  }
  v6 = this->m_RenderTargetStack.m_Memory.m_pMemory;
  this->m_RenderTargetStack.m_pElements = v6;
  CUtlStack<CMatRenderContextBase::RenderTargetStackElement_t,CUtlMemory<CMatRenderContextBase::RenderTargetStackElement_t,int>>::Push(
    this: &this->m_RenderTargetStack,
    src: &v6[this->m_RenderTargetStack.m_Size - 1]);
  this->CommitRenderTargetAndViewport(this);
}

//------------------------------------------------------------------------------
// Address: 0x100473F0
// Name: public: virtual void CMatRenderContextBase::PushRenderTargetAndViewport(class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::PushRenderTargetAndViewport(CMatRenderContextBase *this, ITexture *pTexture)
{
  CMatRenderContextBase::RenderTargetStackElement_t element; // [esp+4h] [ebp-24h] BYREF

  element.m_pRenderTargets[0] = pTexture;
  memset(&element.m_pRenderTargets[1], 0, 24);
  element.m_nViewW = -1;
  element.m_nViewH = -1;
  CUtlStack<CMatRenderContextBase::RenderTargetStackElement_t,CUtlMemory<CMatRenderContextBase::RenderTargetStackElement_t,int>>::Push(
    this: &this->m_RenderTargetStack,
    src: &element);
  this->CommitRenderTargetAndViewport(this);
}

//------------------------------------------------------------------------------
// Address: 0x10047440
// Name: public: virtual void CMatRenderContextBase::PushRenderTargetAndViewport(class ITexture __near *,class ITexture __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::PushRenderTargetAndViewport(
        CMatRenderContextBase *this,
        ITexture *pTexture,
        ITexture *pDepthTexture,
        int nViewX,
        int nViewY,
        int nViewW,
        int nViewH)
{
  CMatRenderContextBase::RenderTargetStackElement_t element; // [esp+4h] [ebp-24h] BYREF

  element.m_pRenderTargets[0] = pTexture;
  memset(&element.m_pRenderTargets[1], 0, 12);
  element.m_pDepthTexture = pDepthTexture;
  element.m_nViewY = nViewY;
  element.m_nViewX = nViewX;
  element.m_nViewW = nViewW;
  element.m_nViewH = nViewH;
  CUtlStack<CMatRenderContextBase::RenderTargetStackElement_t,CUtlMemory<CMatRenderContextBase::RenderTargetStackElement_t,int>>::Push(
    this: &this->m_RenderTargetStack,
    src: &element);
  this->CommitRenderTargetAndViewport(this);
}

//------------------------------------------------------------------------------
// Address: 0x100474A0
// Name: public: virtual void CMatRenderContext::PushMatrix(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::PushMatrix(CMatRenderContext *this)
{
  CMatRenderContextBase::PushMatrix(this);
  g_pShaderAPI->PushMatrix(this: g_pShaderAPI);
}

//------------------------------------------------------------------------------
// Address: 0x100474C0
// Name: public: virtual void CMatRenderContext::LoadMatrix(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::LoadMatrix(CMatRenderContext *this, const VMatrix *matrix)
{
  MaterialMatrixMode_t m_MatrixMode; // eax

  VMatrix::operator=(this: &this->m_pCurMatrixItem->matrix, mOther: matrix);
  this->m_pCurMatrixItem->flags = 1;
  m_MatrixMode = this->m_MatrixMode;
  if ( m_MatrixMode != MATERIAL_VIEW )
  {
    if ( m_MatrixMode == MATERIAL_PROJECTION )
      *((_BYTE *)&this->CMatRenderContextBase + 492) |= 4u;
    CMatRenderContext::ForceSyncMatrix(this, mode: m_MatrixMode);
  }
  else
  {
    *((_BYTE *)&this->CMatRenderContextBase + 492) |= 6u;
    CMatRenderContext::ForceSyncMatrix(this, mode: MATERIAL_VIEW);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047510
// Name: public: virtual void CMatRenderContext::LoadMatrix(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::LoadMatrix(CMatRenderContext *this, const matrix3x4_t *matrix)
{
  CMatRenderContext *v2; // ecx

  CMatRenderContextBase::LoadMatrix(this, matrix);
  CMatRenderContext::ForceSyncMatrix(this: v2, mode: v2->m_MatrixMode);
}

//------------------------------------------------------------------------------
// Address: 0x10047530
// Name: public: virtual void CMatRenderContext::MultMatrix(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::MultMatrix(CMatRenderContext *this, const VMatrix *matrix)
{
  MaterialMatrixMode_t m_MatrixMode; // eax
  VMatrix dst; // [esp+4h] [ebp-40h] BYREF

  MatrixMultiply(src1: matrix, src2: &this->m_pCurMatrixItem->matrix, &dst);
  VMatrix::operator=(this: &this->m_pCurMatrixItem->matrix, mOther: &dst);
  this->m_pCurMatrixItem->flags = 1;
  m_MatrixMode = this->m_MatrixMode;
  if ( m_MatrixMode != MATERIAL_VIEW )
  {
    if ( m_MatrixMode == MATERIAL_PROJECTION )
      *((_BYTE *)&this->CMatRenderContextBase + 492) |= 4u;
    CMatRenderContext::ForceSyncMatrix(this, mode: m_MatrixMode);
  }
  else
  {
    *((_BYTE *)&this->CMatRenderContextBase + 492) |= 6u;
    CMatRenderContext::ForceSyncMatrix(this, mode: MATERIAL_VIEW);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100475A0
// Name: public: virtual void CMatRenderContext::MultMatrix(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::MultMatrix(CMatRenderContext *this, const matrix3x4_t *matrix)
{
  CMatRenderContextBase::MatrixStackItem_t *m_pCurMatrixItem; // ecx
  MaterialMatrixMode_t m_MatrixMode; // eax
  VMatrix dst; // [esp+0h] [ebp-80h] BYREF
  VMatrix src1; // [esp+40h] [ebp-40h] BYREF

  *(_QWORD *)&src1.m[0][0] = *(_QWORD *)&matrix->m_flMatVal[0][0];
  *(_QWORD *)&src1.m[0][2] = *(_QWORD *)&matrix->m_flMatVal[0][2];
  *(_OWORD *)&src1.m[1][0] = *(_OWORD *)&matrix->m_flMatVal[1][0];
  *(_QWORD *)&src1.m[2][0] = *(_QWORD *)&matrix->m_flMatVal[2][0];
  m_pCurMatrixItem = this->m_pCurMatrixItem;
  *(_QWORD *)&src1.m[2][2] = *(_QWORD *)&matrix->m_flMatVal[2][2];
  *(_QWORD *)&src1.m[3][0] = 0;
  *(_QWORD *)&src1.m[3][2] = 0x3F80000000000000LL;
  MatrixMultiply(&src1, src2: &m_pCurMatrixItem->matrix, &dst);
  VMatrix::operator=(this: &this->m_pCurMatrixItem->matrix, mOther: &dst);
  this->m_pCurMatrixItem->flags = 1;
  m_MatrixMode = this->m_MatrixMode;
  if ( m_MatrixMode != MATERIAL_VIEW )
  {
    if ( m_MatrixMode == MATERIAL_PROJECTION )
      *((_BYTE *)&this->CMatRenderContextBase + 492) |= 4u;
    CMatRenderContext::ForceSyncMatrix(this, mode: m_MatrixMode);
  }
  else
  {
    *((_BYTE *)&this->CMatRenderContextBase + 492) |= 6u;
    CMatRenderContext::ForceSyncMatrix(this, mode: MATERIAL_VIEW);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047670
// Name: public: virtual void CMatRenderContext::MultMatrixLocal(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::MultMatrixLocal(CMatRenderContext *this, const VMatrix *matrix)
{
  MaterialMatrixMode_t m_MatrixMode; // eax
  VMatrix dst; // [esp+4h] [ebp-40h] BYREF

  MatrixMultiply(src1: &this->m_pCurMatrixItem->matrix, src2: matrix, &dst);
  VMatrix::operator=(this: &this->m_pCurMatrixItem->matrix, mOther: &dst);
  this->m_pCurMatrixItem->flags = 1;
  m_MatrixMode = this->m_MatrixMode;
  if ( m_MatrixMode != MATERIAL_VIEW )
  {
    if ( m_MatrixMode == MATERIAL_PROJECTION )
      *((_BYTE *)&this->CMatRenderContextBase + 492) |= 4u;
    CMatRenderContext::ForceSyncMatrix(this, mode: m_MatrixMode);
  }
  else
  {
    *((_BYTE *)&this->CMatRenderContextBase + 492) |= 6u;
    CMatRenderContext::ForceSyncMatrix(this, mode: MATERIAL_VIEW);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100476E0
// Name: public: virtual void CMatRenderContext::MultMatrixLocal(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::MultMatrixLocal(CMatRenderContext *this, const matrix3x4_t *matrix)
{
  CMatRenderContextBase::MatrixStackItem_t *m_pCurMatrixItem; // edx
  MaterialMatrixMode_t m_MatrixMode; // eax
  VMatrix dst; // [esp+0h] [ebp-80h] BYREF
  VMatrix src2; // [esp+40h] [ebp-40h] BYREF

  *(_QWORD *)&src2.m[0][0] = *(_QWORD *)&matrix->m_flMatVal[0][0];
  *(_QWORD *)&src2.m[0][2] = *(_QWORD *)&matrix->m_flMatVal[0][2];
  *(_OWORD *)&src2.m[1][0] = *(_OWORD *)&matrix->m_flMatVal[1][0];
  *(_QWORD *)&src2.m[2][0] = *(_QWORD *)&matrix->m_flMatVal[2][0];
  m_pCurMatrixItem = this->m_pCurMatrixItem;
  *(_QWORD *)&src2.m[2][2] = *(_QWORD *)&matrix->m_flMatVal[2][2];
  *(_QWORD *)&src2.m[3][0] = 0;
  *(_QWORD *)&src2.m[3][2] = 0x3F80000000000000LL;
  MatrixMultiply(src1: &m_pCurMatrixItem->matrix, &src2, &dst);
  VMatrix::operator=(this: &this->m_pCurMatrixItem->matrix, mOther: &dst);
  this->m_pCurMatrixItem->flags = 1;
  m_MatrixMode = this->m_MatrixMode;
  if ( m_MatrixMode != MATERIAL_VIEW )
  {
    if ( m_MatrixMode == MATERIAL_PROJECTION )
      *((_BYTE *)&this->CMatRenderContextBase + 492) |= 4u;
    CMatRenderContext::ForceSyncMatrix(this, mode: m_MatrixMode);
  }
  else
  {
    *((_BYTE *)&this->CMatRenderContextBase + 492) |= 6u;
    CMatRenderContext::ForceSyncMatrix(this, mode: MATERIAL_VIEW);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100477B0
// Name: public: virtual void CMatRenderContext::LoadIdentity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::LoadIdentity(CMatRenderContext *this)
{
  MaterialMatrixMode_t m_MatrixMode; // eax

  MatrixSetIdentity(dst: &this->m_pCurMatrixItem->matrix);
  this->m_pCurMatrixItem->flags = 3;
  m_MatrixMode = this->m_MatrixMode;
  if ( m_MatrixMode != MATERIAL_VIEW )
  {
    if ( m_MatrixMode == MATERIAL_PROJECTION )
      *((_BYTE *)&this->CMatRenderContextBase + 492) |= 4u;
    CMatRenderContext::ForceSyncMatrix(this, mode: m_MatrixMode);
  }
  else
  {
    *((_BYTE *)&this->CMatRenderContextBase + 492) |= 6u;
    CMatRenderContext::ForceSyncMatrix(this, mode: MATERIAL_VIEW);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047800
// Name: public: virtual void CMatRenderContext::Ortho(double,double,double,double,double,double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::Ortho(
        CMatRenderContext *this,
        long double left,
        long double top,
        long double right,
        long double bottom,
        long double zNear,
        long double zFar)
{
  CMatRenderContextBase::MatrixStackItem_t *m_pCurMatrixItem; // edi
  VMatrix mOther; // [esp+38h] [ebp-80h] BYREF
  VMatrix dst; // [esp+78h] [ebp-40h] BYREF

  m_pCurMatrixItem = this->m_pCurMatrixItem;
  MatrixBuildOrtho(&dst, left, top, right, bottom, zNear, zFar);
  MatrixMultiply(src1: &m_pCurMatrixItem->matrix, src2: &dst, dst: &mOther);
  VMatrix::operator=(this: &m_pCurMatrixItem->matrix, &mOther);
  this->m_pCurMatrixItem->flags = 1;
  CMatRenderContext::ForceSyncMatrix(this, mode: this->m_MatrixMode);
}

//------------------------------------------------------------------------------
// Address: 0x100478A0
// Name: public: virtual void CMatRenderContext::PerspectiveX(double,double,double,double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::PerspectiveX(
        CMatRenderContext *this,
        long double flFovX,
        long double flAspect,
        long double flZNear,
        long double flZFar)
{
  CMatRenderContextBase::MatrixStackItem_t *m_pCurMatrixItem; // edi
  VMatrix mOther; // [esp+28h] [ebp-80h] BYREF
  VMatrix dst; // [esp+68h] [ebp-40h] BYREF

  m_pCurMatrixItem = this->m_pCurMatrixItem;
  MatrixBuildPerspectiveX(&dst, flFovX, flAspect, flZNear, flZFar);
  MatrixMultiply(src1: &m_pCurMatrixItem->matrix, src2: &dst, dst: &mOther);
  VMatrix::operator=(this: &m_pCurMatrixItem->matrix, &mOther);
  this->m_pCurMatrixItem->flags = 1;
  CMatRenderContext::ForceSyncMatrix(this, mode: this->m_MatrixMode);
}

//------------------------------------------------------------------------------
// Address: 0x10047920
// Name: public: virtual void CMatRenderContext::PerspectiveOffCenterX(double,double,double,double,double,double,double,double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::PerspectiveOffCenterX(
        CMatRenderContext *this,
        long double flFovX,
        long double flAspect,
        long double flZNear,
        long double flZFar,
        long double bottom,
        long double top,
        long double left,
        long double right)
{
  CMatRenderContextBase::MatrixStackItem_t *m_pCurMatrixItem; // edi
  VMatrix mOther; // [esp+48h] [ebp-80h] BYREF
  VMatrix dst; // [esp+88h] [ebp-40h] BYREF

  m_pCurMatrixItem = this->m_pCurMatrixItem;
  MatrixBuildPerspectiveOffCenterX(&dst, flFovX, flAspect, flZNear, flZFar, bottom, top, left, right);
  MatrixMultiply(src1: &m_pCurMatrixItem->matrix, src2: &dst, dst: &mOther);
  VMatrix::operator=(this: &m_pCurMatrixItem->matrix, &mOther);
  this->m_pCurMatrixItem->flags = 1;
  CMatRenderContext::ForceSyncMatrix(this, mode: this->m_MatrixMode);
}

//------------------------------------------------------------------------------
// Address: 0x100479D0
// Name: public: virtual void CMatRenderContext::PickMatrix(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::PickMatrix(CMatRenderContext *this, int x, int y, int nWidth, int nHeight)
{
  CMatRenderContextBase::PickMatrix(this, x, y, nWidth, nHeight);
  CMatRenderContext::ForceSyncMatrix(this, mode: this->m_MatrixMode);
}

//------------------------------------------------------------------------------
// Address: 0x10047A00
// Name: public: virtual void CMatRenderContext::Rotate(float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::Rotate(CMatRenderContext *this, float flAngle, float x, float y, float z)
{
  CMatRenderContextBase::MatrixStackItem_t *m_pCurMatrixItem; // edi
  VMatrix mOther; // [esp+Ch] [ebp-8Ch] BYREF
  VMatrix dst; // [esp+4Ch] [ebp-4Ch] BYREF
  Vector vAxisOfRot; // [esp+8Ch] [ebp-Ch] BYREF

  vAxisOfRot.x = x;
  vAxisOfRot.y = y;
  vAxisOfRot.z = z;
  m_pCurMatrixItem = this->m_pCurMatrixItem;
  MatrixBuildRotationAboutAxis(&dst, &vAxisOfRot, angleDegrees: flAngle);
  MatrixMultiply(src1: &m_pCurMatrixItem->matrix, src2: &dst, dst: &mOther);
  VMatrix::operator=(this: &m_pCurMatrixItem->matrix, &mOther);
  this->m_pCurMatrixItem->flags = 1;
  CMatRenderContext::ForceSyncMatrix(this, mode: this->m_MatrixMode);
}

//------------------------------------------------------------------------------
// Address: 0x10047A90
// Name: public: virtual void CMatRenderContext::Translate(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::Translate(CMatRenderContext *this, float x, float y, float z)
{
  CMatRenderContextBase::MatrixStackItem_t *m_pCurMatrixItem; // edi
  VMatrix mOther; // [esp+0h] [ebp-8Ch] BYREF
  VMatrix dst; // [esp+40h] [ebp-4Ch] BYREF
  Vector translation; // [esp+80h] [ebp-Ch] BYREF

  m_pCurMatrixItem = this->m_pCurMatrixItem;
  translation.x = x;
  translation.y = y;
  translation.z = z;
  MatrixBuildTranslation(&dst, &translation);
  MatrixMultiply(src1: &m_pCurMatrixItem->matrix, src2: &dst, dst: &mOther);
  VMatrix::operator=(this: &m_pCurMatrixItem->matrix, &mOther);
  this->m_pCurMatrixItem->flags = 1;
  CMatRenderContext::ForceSyncMatrix(this, mode: this->m_MatrixMode);
}

//------------------------------------------------------------------------------
// Address: 0x10047B10
// Name: public: virtual void CMatRenderContext::Scale(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::Scale(CMatRenderContext *this, float x, float y, float z)
{
  MaterialMatrixMode_t m_MatrixMode; // eax
  VMatrix mOther; // [esp+10h] [ebp-80h] BYREF
  VMatrix dst; // [esp+50h] [ebp-40h] BYREF

  MatrixBuildScale(&dst, x, y, z);
  MatrixMultiply(src1: &this->m_pCurMatrixItem->matrix, src2: &dst, dst: &mOther);
  VMatrix::operator=(this: &this->m_pCurMatrixItem->matrix, &mOther);
  this->m_pCurMatrixItem->flags = 1;
  m_MatrixMode = this->m_MatrixMode;
  if ( m_MatrixMode != MATERIAL_VIEW )
  {
    if ( m_MatrixMode == MATERIAL_PROJECTION )
      *((_BYTE *)&this->CMatRenderContextBase + 492) |= 4u;
    CMatRenderContext::ForceSyncMatrix(this, mode: m_MatrixMode);
  }
  else
  {
    *((_BYTE *)&this->CMatRenderContextBase + 492) |= 6u;
    CMatRenderContext::ForceSyncMatrix(this, mode: MATERIAL_VIEW);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047BB0
// Name: public: virtual void CMatRenderContext::GetMatrix(enum MaterialMatrixMode_t,class VMatrix __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::GetMatrix(
        CMatRenderContext *this,
        MaterialMatrixMode_t matrixMode,
        VMatrix *pMatrix)
{
  CUtlStack<CMatRenderContextBase::MatrixStackItem_t,CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> > *v4; // ecx
  int m_Size; // eax

  v4 = &this->m_MatrixStacks[matrixMode];
  m_Size = v4->m_Size;
  if ( m_Size != 0 )
    VMatrix::operator=(this: pMatrix, mOther: &v4->m_Memory.m_pMemory[m_Size - 1].matrix);
  else
    MatrixSetIdentity(dst: pMatrix);
  CMatRenderContext::ForceSyncMatrix(this, mode: this->m_MatrixMode);
}

//------------------------------------------------------------------------------
// Address: 0x10047C10
// Name: public: virtual void CMatRenderContext::GetMatrix(enum MaterialMatrixMode_t,struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::GetMatrix(
        CMatRenderContext *this,
        MaterialMatrixMode_t matrixMode,
        matrix3x4_t *pMatrix)
{
  CMatRenderContextBase::GetMatrix(this, matrixMode, pMatrix);
}

//------------------------------------------------------------------------------
// Address: 0x10047C20
// Name: public: virtual void CMatRenderContext::SetRenderTargetEx(int,class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::SetRenderTargetEx(
        CMatRenderContext *this,
        int nRenderTargetID,
        ITexture *pNewTarget)
{
  int m_Size; // eax
  CMatRenderContextBase::RenderTargetStackElement_t *m_pMemory; // edx
  CUtlStack<CMatRenderContextBase::RenderTargetStackElement_t,CUtlMemory<CMatRenderContextBase::RenderTargetStackElement_t,int> > *p_m_RenderTargetStack; // ecx
  ITexture *v7; // edi
  __int64 v8; // xmm0_8
  int v9; // eax
  int v10; // edx
  __int64 v11; // xmm0_8
  CMatRenderContextBase::RenderTargetStackElement_t src; // [esp+Ch] [ebp-24h] BYREF

  m_Size = this->m_RenderTargetStack.m_Size;
  m_pMemory = this->m_RenderTargetStack.m_Memory.m_pMemory;
  p_m_RenderTargetStack = &this->m_RenderTargetStack;
  v7 = (&(&m_pMemory[-1].m_pRenderTargets[8 * m_Size])[m_Size])[nRenderTargetID];
  m_Size *= 9;
  v8 = *(_QWORD *)&m_pMemory[-1].m_pRenderTargets[m_Size];
  v9 = (int)&m_pMemory[-1].m_pRenderTargets[m_Size];
  v10 = *(_DWORD *)(v9 + 32);
  *(_QWORD *)src.m_pRenderTargets = v8;
  *(_QWORD *)&src.m_pRenderTargets[2] = *(_QWORD *)(v9 + 8);
  *(_QWORD *)&src.m_pDepthTexture = *(_QWORD *)(v9 + 16);
  v11 = *(_QWORD *)(v9 + 24);
  --p_m_RenderTargetStack->m_Size;
  *(_QWORD *)&src.m_nViewY = v11;
  src.m_nViewH = v10;
  src.m_pRenderTargets[nRenderTargetID] = pNewTarget;
  CUtlStack<CMatRenderContextBase::RenderTargetStackElement_t,CUtlMemory<CMatRenderContextBase::RenderTargetStackElement_t,int>>::Push(
    this: p_m_RenderTargetStack,
    &src);
  if ( pNewTarget != v7 )
  {
    if ( pNewTarget != nullptr )
    {
      if ( nRenderTargetID == 0 )
      {
        this->m_Viewport.m_nTopLeftX = 0;
        this->m_Viewport.m_nTopLeftY = 0;
        this->m_Viewport.m_nWidth = pNewTarget->GetActualWidth(this: pNewTarget);
        this->m_Viewport.m_nHeight = pNewTarget->GetActualHeight(this: pNewTarget);
        g_pShaderAPI->SetViewports(this: g_pShaderAPI, a2: 1, a3: &this->m_Viewport, a4: false);
      }
      if ( ((unsigned __int8 (__thiscall *)(ITexture *, int))pNewTarget->__vftable[1].GetNumAnimationFrames)(
             a1: pNewTarget,
             a2: nRenderTargetID) == 0 )
        g_pShaderAPI->SetRenderTargetEx(this: g_pShaderAPI, a2: nRenderTargetID, a3: -1, a4: -1);
      if ( pNewTarget->GetImageFormat(this: pNewTarget) == IMAGE_FORMAT_RGBA16161616F
        || pNewTarget->GetImageFormat(this: pNewTarget) == IMAGE_FORMAT_RGBA32323232F )
      {
        g_pShaderAPI->EnableLinearColorSpaceFrameBuffer(this: g_pShaderAPI, a2: true);
      }
      else
      {
        g_pShaderAPI->EnableLinearColorSpaceFrameBuffer(this: g_pShaderAPI, a2: false);
      }
    }
    else
    {
      if ( nRenderTargetID == 0 )
      {
        this->m_Viewport.m_nTopLeftX = 0;
        this->m_Viewport.m_nTopLeftY = 0;
        g_pShaderAPI->GetBackBufferDimensions(
          this: g_pShaderAPI,
          a2: &this->m_Viewport.m_nWidth,
          a3: &this->m_Viewport.m_nHeight);
        g_pShaderAPI->SetViewports(this: g_pShaderAPI, a2: 1, a3: &this->m_Viewport, a4: false);
      }
      g_pShaderAPI->SetRenderTargetEx(this: g_pShaderAPI, a2: nRenderTargetID, a3: -1, a4: -1);
    }
  }
  this->CommitRenderTargetAndViewport(this);
}

//------------------------------------------------------------------------------
// Address: 0x10047DC0
// Name: public: virtual void CMatRenderContext::Viewport(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::Viewport(CMatRenderContext *this, int x, int y, int width, int height)
{
  ITexture *v6; // edi

  CMatRenderContextBase::Viewport(this, x, y, width, height);
  if ( width < 0 || height < 0 )
  {
    v6 = this->m_RenderTargetStack.m_Memory.m_pMemory[this->m_RenderTargetStack.m_Size - 1].m_pRenderTargets[0];
    this->m_Viewport.m_nTopLeftX = 0;
    this->m_Viewport.m_nTopLeftY = 0;
    if ( v6 != nullptr )
    {
      this->m_Viewport.m_nWidth = v6->GetActualWidth(this: v6);
      this->m_Viewport.m_nHeight = v6->GetActualHeight(this: v6);
    }
    else
    {
      g_pShaderAPI->GetBackBufferDimensions(
        this: g_pShaderAPI,
        a2: &this->m_Viewport.m_nWidth,
        a3: &this->m_Viewport.m_nHeight);
    }
    g_pShaderAPI->SetViewports(this: g_pShaderAPI, a2: 1, a3: &this->m_Viewport, a4: false);
  }
  else
  {
    this->m_Viewport.m_nTopLeftX = x;
    this->m_Viewport.m_nTopLeftY = y;
    this->m_Viewport.m_nWidth = width;
    this->m_Viewport.m_nHeight = height;
    g_pShaderAPI->SetViewports(this: g_pShaderAPI, a2: 1, a3: &this->m_Viewport, a4: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047E90
// Name: public: virtual void CMatRenderContext::PushScissorRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::PushScissorRect(
        CMatRenderContext *this,
        int nLeft,
        int nTop,
        int nRight,
        int nBottom)
{
  int v6; // eax
  CMatRenderContextBase::ScissorRectStackElement_t *m_pMemory; // edx
  CMatRenderContextBase::ScissorRectStackElement_t *v8; // eax
  int v10; // ebx
  int v11; // edi
  CMatRenderContextBase::ScissorRectStackElement_t *v12; // edx
  int v13; // edx
  CMatRenderContextBase::ScissorRectStackElement_t *v14; // ecx
  CMatRenderContextBase::ScissorRectStackElement_t *v15; // eax
  unsigned int v16; // [esp-4h] [ebp-28h]
  int nNewLeft; // [esp+20h] [ebp-4h]
  int nNewTop; // [esp+2Ch] [ebp+8h]

  if ( this->m_ScissorRectStack.m_Size > 32 )
    DevMsg(a1: "Scissor Rect Stack overflow.  Too many Pushes?\n");
  v6 = this->m_ScissorRectStack.m_Size + 1;
  if ( this->m_ScissorRectStack.m_Memory.m_nAllocationCount < v6 && this->m_ScissorRectStack.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_ScissorRectStack.m_Memory.m_pMemory;
    this->m_ScissorRectStack.m_Memory.m_nAllocationCount = v6;
    v16 = 16 * v6;
    if ( m_pMemory != nullptr )
      v8 = (CMatRenderContextBase::ScissorRectStackElement_t *)_g_pMemAlloc->Realloc_2(
                                                                 this: _g_pMemAlloc,
                                                                 a2: m_pMemory,
                                                                 a3: v16);
    else
      v8 = (CMatRenderContextBase::ScissorRectStackElement_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v16);
    this->m_ScissorRectStack.m_Memory.m_pMemory = v8;
  }
  v10 = nRight;
  v11 = nBottom;
  this->m_ScissorRectStack.m_pElements = this->m_ScissorRectStack.m_Memory.m_pMemory;
  nNewLeft = nLeft;
  nNewTop = nTop;
  if ( this->m_ScissorRectStack.m_Size > 0 )
  {
    v12 = &this->m_ScissorRectStack.m_Memory.m_pMemory[this->m_ScissorRectStack.m_Size];
    nNewLeft = v12[-1].nLeft;
    if ( nNewLeft <= nLeft )
      nNewLeft = nLeft;
    nNewTop = v12[-1].nTop;
    if ( nNewTop <= nTop )
      nNewTop = nTop;
    if ( v12[-1].nRight < nRight )
      v10 = v12[-1].nRight;
    v13 = v12[-1].nBottom;
    v11 = nBottom;
    if ( v13 < nBottom )
      v11 = v13;
  }
  if ( nNewLeft > v10 )
    nNewLeft = v10;
  if ( nNewTop > v11 )
    nNewTop = v11;
  if ( this->m_ScissorRectStack.m_Size >= this->m_ScissorRectStack.m_Memory.m_nAllocationCount )
    CUtlMemory<CMatRenderContextBase::ScissorRectStackElement_t,int>::Grow(
      this: (CUtlMemory<CUtlString,int> *)&this->m_ScissorRectStack,
      num: 1);
  ++this->m_ScissorRectStack.m_Size;
  v14 = this->m_ScissorRectStack.m_Memory.m_pMemory;
  v15 = &v14[this->m_ScissorRectStack.m_Size - 1];
  this->m_ScissorRectStack.m_pElements = v14;
  if ( v15 != nullptr )
  {
    *(_QWORD *)&v15->nLeft = __PAIR64__(nNewTop, nNewLeft);
    *(_QWORD *)&v15->nRight = __PAIR64__(v11, v10);
  }
  g_pShaderAPI->SetScissorRect(this: g_pShaderAPI, a2: nNewLeft, a3: nNewTop, a4: v10, a5: v11, a6: true);
}

//------------------------------------------------------------------------------
// Address: 0x10047FD0
// Name: public: void CUtlStack<struct CMatRenderContextBase::MatrixStackItem_t,class CUtlMemory<struct CMatRenderContextBase::MatrixStackItem_t,int>>::CopyFrom(class CUtlStack<struct CMatRenderContextBase::MatrixStackItem_t,class CUtlMemory<struct CMatRenderContextBase::MatrixStackItem_t,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlStack<CMatRenderContextBase::MatrixStackItem_t,CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>>::CopyFrom(
        CUtlStack<CMatRenderContextBase::MatrixStackItem_t,CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> > *this,
        const CUtlStack<CMatRenderContextBase::MatrixStackItem_t,CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> > *from)
{
  const CUtlStack<CMatRenderContextBase::MatrixStackItem_t,CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> > *v3; // esi
  CMatRenderContextBase::MatrixStackItem_t *v4; // esi
  CMatRenderContextBase::MatrixStackItem_t *v5; // edi
  int i; // [esp+Ch] [ebp-8h]
  int v7; // [esp+10h] [ebp-4h]

  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v3 = from;
  this->m_pElements = this->m_Memory.m_pMemory;
  CUtlStack<CMatRenderContextBase::MatrixStackItem_t,CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>>::EnsureCapacity(
    this,
    num: from->m_Size);
  i = 0;
  if ( from->m_Size > 0 )
  {
    v7 = 0;
    while ( 1 )
    {
      v4 = &v3->m_Memory.m_pMemory[v7];
      if ( this->m_Size >= this->m_Memory.m_nAllocationCount )
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Grow(this: &this->m_Memory, num: 1);
      v5 = &this->m_Memory.m_pMemory[this->m_Size++];
      this->m_pElements = this->m_Memory.m_pMemory;
      if ( v5 != nullptr )
        qmemcpy(v5, v4, sizeof(CMatRenderContextBase::MatrixStackItem_t));
      ++v7;
      if ( ++i >= from->m_Size )
        break;
      v3 = from;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10048080
// Name: protected: CMatRenderContextBase::CMatRenderContextBase(void)
// Source: json
//------------------------------------------------------------------------------
CMatRenderContextBase *__thiscall CMatRenderContextBase::CMatRenderContextBase(CMatRenderContextBase *this)
{
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  CMatRenderContextBase::RenderTargetStackElement_t *v3; // eax
  void *(__thiscall *v4)(IMemAlloc *, unsigned int); // eax
  CMatRenderContextBase::ScissorRectStackElement_t *v5; // eax
  char v6; // dl
  int *p_m_Size; // edi
  int v8; // ecx
  CMatRenderContextBase::RenderTargetStackElement_t initialElement; // [esp+Ch] [ebp-38h] BYREF
  CMatRenderContextBase *v11; // [esp+30h] [ebp-14h]
  int i; // [esp+34h] [ebp-10h]
  int v13; // [esp+40h] [ebp-4h]

  this->m_iRefs = 1;
  this->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable = (CMatRenderContextBase_vtbl *)&CMatRenderContextBase::`vftable'{for `IMatRenderContextInternal'};
  this->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CMatRenderContextBase::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_RenderTargetStack.m_Memory.m_nAllocationCount = 32;
  this->m_RenderTargetStack.m_Memory.m_nGrowSize = 16;
  this->m_RenderTargetStack.m_Memory.m_pMemory = nullptr;
  Alloc_2 = _g_pMemAlloc->Alloc_2;
  v11 = this;
  v3 = (CMatRenderContextBase::RenderTargetStackElement_t *)Alloc_2(this: _g_pMemAlloc, a2: 1152u);
  this->m_RenderTargetStack.m_Memory.m_pMemory = v3;
  this->m_RenderTargetStack.m_Size = 0;
  this->m_RenderTargetStack.m_pElements = v3;
  this->m_ScissorRectStack.m_Memory.m_pMemory = nullptr;
  this->m_ScissorRectStack.m_Memory.m_nAllocationCount = 32;
  this->m_ScissorRectStack.m_Memory.m_nGrowSize = 16;
  v4 = _g_pMemAlloc->Alloc_2;
  v13 = 0;
  v5 = (CMatRenderContextBase::ScissorRectStackElement_t *)v4(this: _g_pMemAlloc, a2: 512u);
  this->m_ScissorRectStack.m_Memory.m_pMemory = v5;
  this->m_ScissorRectStack.m_Size = 0;
  this->m_ScissorRectStack.m_pElements = v5;
  LOBYTE(v13) = 1;
  this->m_MatrixMode = NUM_MATRIX_MODES;
  `eh vector constructor iterator'(
    ptr: this->m_MatrixStacks,
    size: 0x14u,
    count: 11,
    pCtor: (void (__thiscall *)(void *))CUtlVector<GFxValue *,CUtlMemory<GFxValue *,int>>::`default constructor closure',
    pDtor: (void (__thiscall *)(void *))CUtlVector<CMatRenderContextBase::PlaneStackElement,CUtlMemory<CMatRenderContextBase::PlaneStackElement,int>>::~CUtlVector<CMatRenderContextBase::PlaneStackElement,CUtlMemory<CMatRenderContextBase::PlaneStackElement,int>>);
  this->m_Viewport.m_nVersion = 1;
  *((_BYTE *)this + 492) |= 2u;
  LOBYTE(v13) = 2;
  this->m_pMaterialSystem = nullptr;
  memset(&initialElement, 0, 28);
  initialElement.m_nViewW = -1;
  initialElement.m_nViewH = -1;
  CUtlStack<CMatRenderContextBase::RenderTargetStackElement_t,CUtlMemory<CMatRenderContextBase::RenderTargetStackElement_t,int>>::Push(
    this: &this->m_RenderTargetStack,
    src: &initialElement);
  this->m_pCurrentFrameBufferCopyTexture[0] = nullptr;
  this->m_pCurrentFrameBufferCopyTexture[1] = nullptr;
  this->m_pCurrentFrameBufferCopyTexture[2] = nullptr;
  this->m_pCurrentFrameBufferCopyTexture[3] = nullptr;
  v6 = *((_BYTE *)this + 492) & 0x86 | 8;
  this->m_pCurrentMaterial = nullptr;
  this->m_pCurrentProxyData = nullptr;
  this->m_pUserDefinedLightmap = nullptr;
  this->m_HeightClipMode = MATERIAL_HEIGHTCLIPMODE_DISABLE;
  this->m_HeightClipZ = 0.0;
  *((_BYTE *)this + 492) = v6;
  p_m_Size = &this->m_MatrixStacks[0].m_Size;
  for ( i = 11; i != 0; --i )
  {
    if ( *p_m_Size >= *(p_m_Size - 2) )
      CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Grow(
        this: (CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)p_m_Size - 1,
        num: 1);
    v8 = *(p_m_Size - 3);
    ++*p_m_Size;
    p_m_Size[1] = v8;
    MatrixSetIdentity(dst: (VMatrix *)(v8 + 68 * *p_m_Size - 68));
    *(_DWORD *)(*(p_m_Size - 3) + 68 * *p_m_Size - 4) |= 3u;
    p_m_Size += 5;
  }
  this->m_pCurMatrixItem = &this->m_MatrixStacks[0].m_Memory.m_pMemory[this->m_MatrixStacks[0].m_Size - 1];
  this->m_Viewport.m_flMinZ = 0.0;
  this->m_Viewport.m_nTopLeftX = 0;
  this->m_Viewport.m_nTopLeftY = 0;
  this->m_Viewport.m_nWidth = 0;
  this->m_Viewport.m_nHeight = 0;
  this->m_Viewport.m_nVersion = 1;
  this->m_Viewport.m_flMaxZ = 1.0;
  this->m_LastSetToneMapScale.x = 1.0;
  this->m_LastSetToneMapScale.y = 1.0;
  this->m_LastSetToneMapScale.z = 1.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10048290
// Name: public: virtual void CMatRenderContextBase::InitializeFrom(class CMatRenderContextBase __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::InitializeFrom(
        CMatRenderContextBase *this,
        CMatRenderContextBase *pInitialState)
{
  char v4; // dl
  int m_Size; // eax
  CMatRenderContextBase::RenderTargetStackElement_t *v6; // eax
  CMatRenderContextBase::RenderTargetStackElement_t *v7; // ecx
  CMatRenderContextBase::RenderTargetStackElement_t *m_pMemory; // eax
  int v9; // edx
  int v10; // eax
  int v11; // eax
  CMatRenderContextBase::ScissorRectStackElement_t *v12; // eax
  CMatRenderContextBase::ScissorRectStackElement_t *v13; // edx
  CMatRenderContextBase::ScissorRectStackElement_t *v14; // ecx
  CMatRenderContextBase::ScissorRectStackElement_t *v15; // eax
  int v16; // eax
  CUtlStack<CMatRenderContextBase::MatrixStackItem_t,CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> > *m_MatrixStacks; // esi
  unsigned int v18; // [esp-4h] [ebp-18h]
  unsigned int v19; // [esp-4h] [ebp-18h]
  CMatRenderContextBase::RenderTargetStackElement_t *v20; // [esp+Ch] [ebp-8h]
  CMatRenderContextBase::ScissorRectStackElement_t *v21; // [esp+Ch] [ebp-8h]
  int v22; // [esp+10h] [ebp-4h]
  int v23; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]
  int ia; // [esp+1Ch] [ebp+8h]
  int ib; // [esp+1Ch] [ebp+8h]

  this->m_pCurrentMaterial = pInitialState->m_pCurrentMaterial;
  this->m_pCurrentProxyData = pInitialState->m_pCurrentProxyData;
  this->m_lightmapPageID = pInitialState->m_lightmapPageID;
  v4 = *((_BYTE *)this + 492);
  this->m_pUserDefinedLightmap = pInitialState->m_pUserDefinedLightmap;
  this->m_pLocalCubemapTexture = pInitialState->m_pLocalCubemapTexture;
  *(_OWORD *)this->m_pCurrentFrameBufferCopyTexture = *(_OWORD *)pInitialState->m_pCurrentFrameBufferCopyTexture;
  *((_BYTE *)this + 492) ^= (*((_BYTE *)pInitialState + 492) ^ v4) & 8;
  this->m_HeightClipMode = pInitialState->m_HeightClipMode;
  this->m_HeightClipZ = pInitialState->m_HeightClipZ;
  this->m_pBoundMorph = pInitialState->m_pBoundMorph;
  this->m_RenderTargetStack.m_Size = 0;
  m_Size = pInitialState->m_RenderTargetStack.m_Size;
  if ( this->m_RenderTargetStack.m_Memory.m_nAllocationCount < m_Size
    && this->m_RenderTargetStack.m_Memory.m_nGrowSize >= 0 )
  {
    this->m_RenderTargetStack.m_Memory.m_nAllocationCount = m_Size;
    v18 = 36 * m_Size;
    if ( this->m_RenderTargetStack.m_Memory.m_pMemory != nullptr )
      v6 = (CMatRenderContextBase::RenderTargetStackElement_t *)_g_pMemAlloc->Realloc_2(
                                                                  this: _g_pMemAlloc,
                                                                  a2: this->m_RenderTargetStack.m_Memory.m_pMemory,
                                                                  a3: v18);
    else
      v6 = (CMatRenderContextBase::RenderTargetStackElement_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v18);
    this->m_RenderTargetStack.m_Memory.m_pMemory = v6;
  }
  this->m_RenderTargetStack.m_pElements = this->m_RenderTargetStack.m_Memory.m_pMemory;
  i = 0;
  if ( pInitialState->m_RenderTargetStack.m_Size > 0 )
  {
    v22 = 0;
    do
    {
      v7 = &pInitialState->m_RenderTargetStack.m_Memory.m_pMemory[v22];
      v20 = v7;
      if ( this->m_RenderTargetStack.m_Size >= this->m_RenderTargetStack.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CMatRenderContextBase::RenderTargetStackElement_t,int>::Grow(
          this: &this->m_RenderTargetStack.m_Memory,
          num: 1);
        v7 = v20;
      }
      ++this->m_RenderTargetStack.m_Size;
      m_pMemory = this->m_RenderTargetStack.m_Memory.m_pMemory;
      v9 = this->m_RenderTargetStack.m_Size;
      this->m_RenderTargetStack.m_pElements = m_pMemory;
      v10 = (int)&m_pMemory[v9 - 1];
      if ( v10 != 0 )
      {
        *(_QWORD *)v10 = *(_QWORD *)v7->m_pRenderTargets;
        *(_QWORD *)(v10 + 8) = *(_QWORD *)&v7->m_pRenderTargets[2];
        *(_QWORD *)(v10 + 16) = *(_QWORD *)&v7->m_pDepthTexture;
        *(_QWORD *)(v10 + 24) = *(_QWORD *)&v7->m_nViewY;
        *(_DWORD *)(v10 + 32) = v7->m_nViewH;
      }
      ++v22;
      ++i;
    }
    while ( i < pInitialState->m_RenderTargetStack.m_Size );
  }
  this->m_ScissorRectStack.m_Size = 0;
  v11 = pInitialState->m_ScissorRectStack.m_Size;
  if ( this->m_ScissorRectStack.m_Memory.m_nAllocationCount < v11 && this->m_ScissorRectStack.m_Memory.m_nGrowSize >= 0 )
  {
    this->m_ScissorRectStack.m_Memory.m_nAllocationCount = v11;
    v19 = 16 * v11;
    if ( this->m_ScissorRectStack.m_Memory.m_pMemory != nullptr )
      v12 = (CMatRenderContextBase::ScissorRectStackElement_t *)_g_pMemAlloc->Realloc_2(
                                                                  this: _g_pMemAlloc,
                                                                  a2: this->m_ScissorRectStack.m_Memory.m_pMemory,
                                                                  a3: v19);
    else
      v12 = (CMatRenderContextBase::ScissorRectStackElement_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v19);
    this->m_ScissorRectStack.m_Memory.m_pMemory = v12;
  }
  this->m_ScissorRectStack.m_pElements = this->m_ScissorRectStack.m_Memory.m_pMemory;
  ia = 0;
  if ( pInitialState->m_ScissorRectStack.m_Size > 0 )
  {
    v23 = 0;
    do
    {
      v13 = &pInitialState->m_ScissorRectStack.m_Memory.m_pMemory[v23];
      v21 = v13;
      if ( this->m_ScissorRectStack.m_Size >= this->m_ScissorRectStack.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CMatRenderContextBase::ScissorRectStackElement_t,int>::Grow(
          this: (CUtlMemory<CUtlString,int> *)&this->m_ScissorRectStack,
          num: 1);
        v13 = v21;
      }
      ++this->m_ScissorRectStack.m_Size;
      v14 = this->m_ScissorRectStack.m_Memory.m_pMemory;
      v15 = &v14[this->m_ScissorRectStack.m_Size - 1];
      this->m_ScissorRectStack.m_pElements = v14;
      if ( v15 != nullptr )
      {
        *(_QWORD *)&v15->nLeft = *(_QWORD *)&v13->nLeft;
        *(_QWORD *)&v15->nRight = *(_QWORD *)&v13->nRight;
      }
      ++v23;
      ++ia;
    }
    while ( ia < pInitialState->m_ScissorRectStack.m_Size );
  }
  v16 = (char *)pInitialState - (char *)this;
  this->m_MatrixMode = pInitialState->m_MatrixMode;
  m_MatrixStacks = this->m_MatrixStacks;
  ib = 11;
  while ( 1 )
  {
    CUtlStack<CMatRenderContextBase::MatrixStackItem_t,CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>>::CopyFrom(
      this: m_MatrixStacks,
      from: (CUtlStack<CMatRenderContextBase::MatrixStackItem_t,CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> > *)((char *)m_MatrixStacks + v16));
    ++m_MatrixStacks;
    if ( --ib == 0 )
      break;
    v16 = (char *)pInitialState - (char *)this;
  }
  *((_BYTE *)this + 492) ^= (*((_BYTE *)pInitialState + 492) ^ *((_BYTE *)this + 492)) & 1;
  *((_BYTE *)this + 492) ^= (*((_BYTE *)this + 492) ^ *((_BYTE *)pInitialState + 492)) & 0x20;
  this->m_LastSetToneMapScale.x = pInitialState->m_LastSetToneMapScale.x;
  this->m_LastSetToneMapScale.y = pInitialState->m_LastSetToneMapScale.y;
  this->m_LastSetToneMapScale.z = pInitialState->m_LastSetToneMapScale.z;
}

//------------------------------------------------------------------------------
// Address: 0x10048510
// Name: public: virtual void CMatRenderContextBase::PushRenderTargetAndViewport(class ITexture __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextBase::PushRenderTargetAndViewport(
        CMatRenderContextBase *this,
        ITexture *pTexture,
        int nViewX,
        int nViewY,
        int nViewW,
        int nViewH)
{
  CMatRenderContextBase::RenderTargetStackElement_t src; // [esp+4h] [ebp-24h] BYREF

  src.m_pRenderTargets[0] = pTexture;
  src.m_nViewX = nViewX;
  src.m_nViewY = nViewY;
  memset(&src.m_pRenderTargets[1], 0, 16);
  src.m_nViewH = nViewH;
  src.m_nViewW = nViewW;
  CUtlStack<CMatRenderContextBase::RenderTargetStackElement_t,CUtlMemory<CMatRenderContextBase::RenderTargetStackElement_t,int>>::Push(
    this: &this->m_RenderTargetStack,
    &src);
  this->CommitRenderTargetAndViewport(this);
}

//------------------------------------------------------------------------------
// Address: 0x10048570
// Name: public: CMatRenderContext::CMatRenderContext(void)
// Source: json
//------------------------------------------------------------------------------
CMatRenderContext *__thiscall CMatRenderContext::CMatRenderContext(CMatRenderContext *this)
{
  CMatRenderContextBase::CMatRenderContextBase(this);
  this->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable = (CMatRenderContext_vtbl *)&CMatRenderContext::`vftable'{for `IMatRenderContextInternal'};
  this->CMatRenderContextBase::CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CMatRenderContext::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_CustomClipPlanes.m_Memory.m_pMemory = nullptr;
  this->m_CustomClipPlanes.m_Memory.m_nAllocationCount = 0;
  this->m_CustomClipPlanes.m_Memory.m_nGrowSize = 0;
  this->m_CustomClipPlanes.m_Size = 0;
  this->m_CustomClipPlanes.m_pElements = nullptr;
  `eh vector constructor iterator'(
    ptr: this->m_pNonInteractiveTempFullscreenBuffer,
    size: 4u,
    count: 2,
    pCtor: (void (__thiscall *)(void *))CTextureReference::CTextureReference,
    pDtor: (void (__thiscall *)(void *))CTextureReference::~CTextureReference);
  CTextureReference::CTextureReference(this: &this->m_pNonInteractivePacifier);
  CTextureReference::CTextureReference(this: &this->m_pNonInteractiveLogo);
  g_FrameNum = 0;
  this->m_pBatchIndices = nullptr;
  this->m_pBatchMesh = nullptr;
  this->m_pCurrentIndexBuffer = nullptr;
  this->m_pMorphRenderContext = nullptr;
  this->m_NonInteractiveMode = MATERIAL_NON_INTERACTIVE_MODE_NONE;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10048640
// Name: public: virtual void CMatRenderContext::EvictManagedResources(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::EvictManagedResources(CMaterialSystem *this)
{
  g_pShaderAPI->EvictManagedResources(this: g_pShaderAPI);
}

//------------------------------------------------------------------------------
// Address: 0x10048650
// Name: public: virtual void CMatRenderContext::DestroyStaticMesh(class IMesh __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::DestroyStaticMesh(CMatRenderContext *this, IMesh *a1)
{
  g_pShaderDevice->DestroyStaticMesh(this: g_pShaderDevice, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10048670
// Name: public: virtual class IMesh __near * CMatRenderContext::GetFlexMesh(void)
// Source: json
//------------------------------------------------------------------------------
IMesh *__thiscall CMatRenderContext::GetFlexMesh(CMatRenderContext *this)
{
  return g_pShaderAPI->GetFlexMesh(this: g_pShaderAPI);
}

//------------------------------------------------------------------------------
// Address: 0x10048680
// Name: public: virtual class IVertexBuffer __near * CMatRenderContext::CreateStaticVertexBuffer(unsigned __int64,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
IVertexBuffer *__thiscall CMatRenderContext::CreateStaticVertexBuffer(
        CMatRenderContext *this,
        unsigned __int64 fmt,
        int nVertexCount,
        const char *pBudgetGroup)
{
  return ((IVertexBuffer *(__thiscall *)(IShaderDevice *, _DWORD, _DWORD, _DWORD, int, const char *))g_pShaderDevice->CreateVertexBuffer)(
           a1: g_pShaderDevice,
           a2: 0,
           a3: fmt,
           a4: HIDWORD(fmt),
           a5: nVertexCount,
           a6: pBudgetGroup);
}

//------------------------------------------------------------------------------
// Address: 0x100486B0
// Name: public: virtual class IIndexBuffer __near * CMatRenderContext::CreateStaticIndexBuffer(enum MaterialIndexFormat_t,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
IIndexBuffer *__thiscall CMatRenderContext::CreateStaticIndexBuffer(
        CMatRenderContext *this,
        MaterialIndexFormat_t fmt,
        int nIndexCount,
        const char *pBudgetGroup)
{
  return g_pShaderDevice->CreateIndexBuffer(
           this: g_pShaderDevice,
           a2: SHADER_BUFFER_TYPE_STATIC,
           a3: fmt,
           a4: nIndexCount,
           a5: pBudgetGroup);
}

//------------------------------------------------------------------------------
// Address: 0x100486E0
// Name: public: virtual void CMatRenderContext::DestroyVertexBuffer(class IVertexBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::DestroyVertexBuffer(CMatRenderContext *this, IVertexBuffer *a1)
{
  g_pShaderDevice->DestroyVertexBuffer(this: g_pShaderDevice, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10048700
// Name: public: virtual void CMatRenderContext::DestroyIndexBuffer(class IIndexBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::DestroyIndexBuffer(CMatRenderContext *this, IIndexBuffer *a1)
{
  g_pShaderDevice->DestroyIndexBuffer(this: g_pShaderDevice, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10048720
// Name: public: virtual class IVertexBuffer __near * CMatRenderContext::GetDynamicVertexBuffer(int,unsigned __int64,bool)
// Source: json
//------------------------------------------------------------------------------
IVertexBuffer *__thiscall CMatRenderContext::GetDynamicVertexBuffer(
        CMatRenderContext *this,
        int a1,
        unsigned __int64 a2,
        int a3)
{
  return ((IVertexBuffer *(__thiscall *)(IShaderDevice *, int, _DWORD, _DWORD, int))g_pShaderDevice->GetDynamicVertexBuffer)(
           a1: g_pShaderDevice,
           a2: a1,
           a3: a2,
           a4: HIDWORD(a2),
           a5: a3);
}

//------------------------------------------------------------------------------
// Address: 0x10048750
// Name: public: virtual class IIndexBuffer __near * CMatRenderContext::GetDynamicIndexBuffer(void)
// Source: json
//------------------------------------------------------------------------------
IIndexBuffer *__thiscall CMatRenderContext::GetDynamicIndexBuffer(CMatRenderContext *this)
{
  return g_pShaderDevice->GetDynamicIndexBuffer(this: g_pShaderDevice);
}

//------------------------------------------------------------------------------
// Address: 0x10048760
// Name: public: virtual void CMatRenderContext::BindVertexBuffer(int,class IVertexBuffer __near *,int,int,int,unsigned __int64,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::BindVertexBuffer(
        CMatRenderContext *this,
        int a1,
        IVertexBuffer *a2,
        int a3,
        int a4,
        int a5,
        unsigned __int64 a6,
        int a7)
{
  ((void (__thiscall *)(IShaderAPI *, int, IVertexBuffer *, int, int, int, _DWORD, _DWORD, int))g_pShaderAPI->BindVertexBuffer)(
    a1: g_pShaderAPI,
    a2: a1,
    a3: a2,
    a4: a3,
    a5: a4,
    a6: a5,
    a7: a6,
    a8: HIDWORD(a6),
    a9: a7);
}

//------------------------------------------------------------------------------
// Address: 0x100487A0
// Name: public: virtual void CMatRenderContext::BindIndexBuffer(class IIndexBuffer __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::BindIndexBuffer(CMatRenderContext *this, IIndexBuffer *a1, int a2)
{
  g_pShaderAPI->BindIndexBuffer(this: g_pShaderAPI, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x100487C0
// Name: public: virtual void CMatRenderContext::Draw(enum MaterialPrimitiveType_t,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::Draw(CMatRenderContext *this, MaterialPrimitiveType_t a1, int a2, int a3)
{
  g_pShaderAPI->Draw(this: g_pShaderAPI, a2: a1, a3: a2, a4: a3);
}

//------------------------------------------------------------------------------
// Address: 0x100487E0
// Name: public: virtual void CMatRenderContext::OverrideDepthEnable(bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::OverrideDepthEnable(CMatRenderContext *this, BOOL a1, BOOL a2, BOOL a3)
{
  g_pShaderAPI->OverrideDepthEnable(this: g_pShaderAPI, a2: a1, a3: a2, a4: a3);
}

//------------------------------------------------------------------------------
// Address: 0x10048800
// Name: public: virtual void CMatRenderContext::OverrideAlphaWriteEnable(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::OverrideAlphaWriteEnable(CMatRenderContext *this, BOOL a1, BOOL a2)
{
  g_pShaderAPI->OverrideAlphaWriteEnable(this: g_pShaderAPI, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10048820
// Name: public: virtual void CMatRenderContext::OverrideColorWriteEnable(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::OverrideColorWriteEnable(CMatRenderContext *this, BOOL a1, BOOL a2)
{
  g_pShaderAPI->OverrideColorWriteEnable(this: g_pShaderAPI, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10048840
// Name: public: virtual void CMatRenderContext::SetLights(int,struct LightDesc_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::SetLights(CMatRenderContext *this, int a1, const LightDesc_t *a2)
{
  g_pShaderAPI->SetLights(this: g_pShaderAPI, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10048860
// Name: public: virtual void CMatRenderContext::SetLightingOrigin(class Vector)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::SetLightingOrigin(CMatRenderContext *this, Vector a1)
{
  ((void (__thiscall *)(IShaderAPI *, _DWORD, _DWORD, _DWORD))g_pShaderAPI->SetLightingOrigin)(
    a1: g_pShaderAPI,
    a2: LODWORD(a1.x),
    a3: LODWORD(a1.y),
    a4: LODWORD(a1.z));
}

//------------------------------------------------------------------------------
// Address: 0x10048890
// Name: public: virtual void CMatRenderContext::SetAmbientLightCube(class Vector4D __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::SetAmbientLightCube(CMatRenderContext *this, Vector4D *a1)
{
  g_pShaderAPI->SetAmbientLightCube(this: g_pShaderAPI, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x100488B0
// Name: public: virtual void CMatRenderContext::DisableAllLocalLights(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::DisableAllLocalLights(CMatRenderContext *this)
{
  g_pShaderAPI->DisableAllLocalLights(this: g_pShaderAPI);
}

//------------------------------------------------------------------------------
// Address: 0x100488C0
// Name: public: virtual void CMatRenderContext::SetLightingState(struct MaterialLightingState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::SetLightingState(CMatRenderContext *this, const MaterialLightingState_t *a1)
{
  g_pShaderAPI->SetLightingState(this: g_pShaderAPI, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x100488E0
// Name: public: virtual void CMatRenderContext::ClearColor3ub(unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::ClearColor3ub(CMatRenderContext *this, int a1, int a2, int a3)
{
  g_pShaderAPI->ClearColor3ub(this: g_pShaderAPI, a2: a1, a3: a2, a4: a3);
}

//------------------------------------------------------------------------------
// Address: 0x10048900
// Name: public: virtual void CMatRenderContext::ClearColor4ub(unsigned char,unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::ClearColor4ub(CMatRenderContext *this, int a1, int a2, int a3, int a4)
{
  g_pShaderAPI->ClearColor4ub(this: g_pShaderAPI, a2: a1, a3: a2, a4: a3, a5: a4);
}

//------------------------------------------------------------------------------
// Address: 0x10048920
// Name: public: virtual void CMatRenderContext::ClearBuffersObeyStencil(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::ClearBuffersObeyStencil(CMatRenderContext *this, BOOL a1, BOOL a2)
{
  g_pShaderAPI->ClearBuffersObeyStencil(this: g_pShaderAPI, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10048940
// Name: public: virtual void CMatRenderContext::ClearBuffersObeyStencilEx(bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::ClearBuffersObeyStencilEx(CMatRenderContext *this, BOOL a1, BOOL a2, BOOL a3)
{
  g_pShaderAPI->ClearBuffersObeyStencilEx(this: g_pShaderAPI, a2: a1, a3: a2, a4: a3);
}

//------------------------------------------------------------------------------
// Address: 0x10048960
// Name: public: virtual void CMatRenderContext::PerformFullScreenStencilOperation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::PerformFullScreenStencilOperation(CMatRenderContext *this)
{
  g_pShaderAPI->PerformFullScreenStencilOperation(this: g_pShaderAPI);
}

//------------------------------------------------------------------------------
// Address: 0x10048970
// Name: public: virtual void CMatRenderContext::ReadPixels(int,int,int,int,unsigned char __near *,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::ReadPixels(
        CMatRenderContext *this,
        int a1,
        int a2,
        int a3,
        int a4,
        unsigned __int8 *a5,
        ImageFormat a6)
{
  g_pShaderAPI->ReadPixels_2(this: g_pShaderAPI, a2: a1, a3: a2, a4: a3, a5: a4, a6: a5, a7: a6);
}

//------------------------------------------------------------------------------
// Address: 0x10048990
// Name: public: virtual void CMatRenderContext::ReadPixelsAndStretch(struct Rect_t __near *,struct Rect_t __near *,unsigned char __near *,enum ImageFormat,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::ReadPixelsAndStretch(
        CMatRenderContext *this,
        Rect_t *pSrcRect,
        Rect_t *pDstRect,
        unsigned __int8 *pBuffer,
        ImageFormat dstFormat,
        int nDstStride)
{
  g_pShaderAPI->ReadPixels(this: g_pShaderAPI, a2: pSrcRect, a3: pDstRect, a4: pBuffer, a5: dstFormat, a6: nDstStride);
}

//------------------------------------------------------------------------------
// Address: 0x100489B0
// Name: public: virtual int CMatRenderContext::SelectionMode(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatRenderContext::SelectionMode(CMatRenderContext *this, BOOL a1)
{
  return g_pShaderAPI->SelectionMode(this: g_pShaderAPI, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x100489D0
// Name: public: virtual void CMatRenderContext::SelectionBuffer(unsigned int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::SelectionBuffer(CMatRenderContext *this, unsigned int *a1, int a2)
{
  g_pShaderAPI->SelectionBuffer(this: g_pShaderAPI, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x100489F0
// Name: public: virtual void CMatRenderContext::ClearSelectionNames(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::ClearSelectionNames(CMatRenderContext *this)
{
  g_pShaderAPI->ClearSelectionNames(this: g_pShaderAPI);
}

//------------------------------------------------------------------------------
// Address: 0x10048A00
// Name: public: virtual void CMatRenderContext::LoadSelectionName(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::LoadSelectionName(CMatRenderContext *this, int a1)
{
  g_pShaderAPI->LoadSelectionName(this: g_pShaderAPI, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10048A20
// Name: public: virtual void CMatRenderContext::PushSelectionName(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::PushSelectionName(CMatRenderContext *this, int a1)
{
  g_pShaderAPI->PushSelectionName(this: g_pShaderAPI, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10048A40
// Name: public: virtual void CMatRenderContext::PopSelectionName(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::PopSelectionName(CMatRenderContext *this)
{
  g_pShaderAPI->PopSelectionName(this: g_pShaderAPI);
}

//------------------------------------------------------------------------------
// Address: 0x10048A50
// Name: public: virtual void CMatRenderContext::CullMode(enum MaterialCullMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::CullMode(CMatRenderContext *this, MaterialCullMode_t a1)
{
  g_pShaderAPI->CullMode(this: g_pShaderAPI, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10048A70
// Name: public: virtual void CMatRenderContext::FlipCullMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::FlipCullMode(CMatRenderContext *this)
{
  g_pShaderAPI->FlipCullMode(this: g_pShaderAPI);
}

//------------------------------------------------------------------------------
// Address: 0x10048A80
// Name: public: virtual void CMatRenderContext::SetNumBoneWeights(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::SetNumBoneWeights(CMatRenderContext *this, int a1)
{
  g_pShaderAPI->SetNumBoneWeights(this: g_pShaderAPI, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10048AA0
// Name: public: virtual void CMatRenderContext::SetFlexWeights(int,int,struct MorphWeight_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::SetFlexWeights(CMatRenderContext *this, int a1, int a2, const MorphWeight_t *a3)
{
  g_pShaderAPI->SetFlexWeights(this: g_pShaderAPI, a2: a1, a3: a2, a4: a3);
}

//------------------------------------------------------------------------------
// Address: 0x10048AC0
// Name: public: virtual void CMatRenderContext::FogMode(enum MaterialFogMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::FogMode(CMatRenderContext *this, MaterialFogMode_t fogMode)
{
  g_pShaderAPI->SceneFogMode(this: g_pShaderAPI, a2: fogMode);
}

//------------------------------------------------------------------------------
// Address: 0x10048AE0
// Name: public: virtual void CMatRenderContext::FogStart(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::FogStart(CMatRenderContext *this, float a1)
{
  ((void (__stdcall *)(_DWORD))g_pShaderAPI->FogStart)(a1: LODWORD(a1));
}

//------------------------------------------------------------------------------
// Address: 0x10048B10
// Name: public: virtual void CMatRenderContext::FogEnd(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::FogEnd(CMatRenderContext *this, float a1)
{
  ((void (__stdcall *)(_DWORD))g_pShaderAPI->FogEnd)(a1: LODWORD(a1));
}

//------------------------------------------------------------------------------
// Address: 0x10048B40
// Name: public: virtual void CMatRenderContext::SetFogZ(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::SetFogZ(CMatRenderContext *this, float a1)
{
  ((void (__stdcall *)(_DWORD))g_pShaderAPI->SetFogZ)(a1: LODWORD(a1));
}

//------------------------------------------------------------------------------
// Address: 0x10048B70
// Name: public: virtual void CMatRenderContext::FogColor3ub(unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::FogColor3ub(CMatRenderContext *this, int r, int g, int b)
{
  g_pShaderAPI->SceneFogColor3ub(this: g_pShaderAPI, a2: r, a3: g, a4: b);
}

//------------------------------------------------------------------------------
// Address: 0x10048B90
// Name: public: virtual enum MaterialFogMode_t CMatRenderContext::GetFogMode(void)
// Source: json
//------------------------------------------------------------------------------
MaterialFogMode_t __thiscall CMatRenderContext::GetFogMode(CMatRenderContext *this)
{
  return g_pShaderAPI->GetSceneFogMode(this: g_pShaderAPI);
}

//------------------------------------------------------------------------------
// Address: 0x10048BA0
// Name: public: virtual void CMatRenderContext::GetFogColor(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::GetFogColor(CMatRenderContext *this, unsigned __int8 *rgb)
{
  g_pShaderAPI->GetSceneFogColor(this: g_pShaderAPI, a2: rgb);
}

//------------------------------------------------------------------------------
// Address: 0x10048BC0
// Name: public: virtual void CMatRenderContext::GetFogDistances(float __near *,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::GetFogDistances(CMatRenderContext *this, float *a1, float *a2, float *a3)
{
  g_pShaderAPI->GetFogDistances(this: g_pShaderAPI, a2: a1, a3: a2, a4: a3);
}

//------------------------------------------------------------------------------
// Address: 0x10048BE0
// Name: public: virtual int CMatRenderContext::GetCurrentNumBones(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatRenderContext::GetCurrentNumBones(CMatRenderContext *this)
{
  return g_pShaderAPI->GetCurrentNumBones(this: g_pShaderAPI);
}

//------------------------------------------------------------------------------
// Address: 0x10048BF0
// Name: public: virtual void CMatRenderContext::EnableUserClipTransformOverride(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::EnableUserClipTransformOverride(CMatRenderContext *this, BOOL a1)
{
  g_pShaderAPI->EnableUserClipTransformOverride(this: g_pShaderAPI, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10048C10
// Name: public: virtual void CMatRenderContext::UserClipTransform(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::UserClipTransform(CMatRenderContext *this, const VMatrix *a1)
{
  g_pShaderAPI->UserClipTransform(this: g_pShaderAPI, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10048C30
// Name: public: virtual void CMatRenderContext::GetWindowSize(int __near &,int __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::GetWindowSize(CMatRenderContext *this, int *a1, int *a2)
{
  g_pShaderDevice->GetWindowSize(this: g_pShaderDevice, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10048C50
// Name: public: virtual void CMatRenderContext::DestroyOcclusionQueryObject(struct OcclusionQueryObjectHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::DestroyOcclusionQueryObject(
        CMatRenderContext *this,
        OcclusionQueryObjectHandle_t__ *a1)
{
  COcclusionQueryMgr::DestroyOcclusionQueryObject(this: g_pOcclusionQueryMgr, hOcclusionQuery: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10048C60
// Name: public: virtual void CMatRenderContext::BeginOcclusionQueryDrawing(struct OcclusionQueryObjectHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::BeginOcclusionQueryDrawing(
        CMatRenderContext *this,
        OcclusionQueryObjectHandle_t__ *a1)
{
  COcclusionQueryMgr::BeginOcclusionQueryDrawing(this: g_pOcclusionQueryMgr, hOcclusionQuery: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10048C70
// Name: public: virtual void CMatRenderContext::EndOcclusionQueryDrawing(struct OcclusionQueryObjectHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::EndOcclusionQueryDrawing(
        CMatRenderContext *this,
        OcclusionQueryObjectHandle_t__ *a1)
{
  COcclusionQueryMgr::EndOcclusionQueryDrawing(this: g_pOcclusionQueryMgr, hOcclusionQuery: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10048C80
// Name: public: virtual void CMatRenderContext::ResetOcclusionQueryObject(struct OcclusionQueryObjectHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::ResetOcclusionQueryObject(
        CMatRenderContext *this,
        OcclusionQueryObjectHandle_t__ *a1)
{
  COcclusionQueryMgr::ResetOcclusionQueryObject(this: g_pOcclusionQueryMgr, hOcclusionQuery: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10048C90
// Name: public: virtual void CMatRenderContext::ForceDepthFuncEquals(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::ForceDepthFuncEquals(CMatRenderContext *this, BOOL a1)
{
  g_pShaderAPI->ForceDepthFuncEquals(this: g_pShaderAPI, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10048CB0
// Name: public: virtual void CMatRenderContext::SetFloatRenderingParameter(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::SetFloatRenderingParameter(CMatRenderContext *this, int a1, float a2)
{
  ((void (__stdcall *)(int, _DWORD))g_pShaderAPI->SetFloatRenderingParameter)(a1, a2: LODWORD(a2));
}

//------------------------------------------------------------------------------
// Address: 0x10048CE0
// Name: public: virtual void CMatRenderContext::SetIntRenderingParameter(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::SetIntRenderingParameter(CMatRenderContext *this, int a1, int a2)
{
  g_pShaderAPI->SetIntRenderingParameter(this: g_pShaderAPI, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10048D00
// Name: public: virtual void CMatRenderContext::SetTextureRenderingParameter(int,class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::SetTextureRenderingParameter(CMatRenderContext *this, int a1, ITexture *a2)
{
  g_pShaderAPI->SetTextureRenderingParameter(this: g_pShaderAPI, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10048D20
// Name: public: virtual void CMatRenderContext::SetVectorRenderingParameter(int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::SetVectorRenderingParameter(CMatRenderContext *this, int a1, const Vector *a2)
{
  g_pShaderAPI->SetVectorRenderingParameter(this: g_pShaderAPI, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10048D40
// Name: public: virtual float CMatRenderContext::GetFloatRenderingParameter(int)const
// Source: json
//------------------------------------------------------------------------------
float __thiscall CMatRenderContext::GetFloatRenderingParameter(CMatRenderContext *this, int a1)
{
  return g_pShaderAPI->GetFloatRenderingParameter(this: g_pShaderAPI, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10048D60
// Name: public: virtual int CMatRenderContext::GetIntRenderingParameter(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatRenderContext::GetIntRenderingParameter(CMatRenderContext *this, int a1)
{
  return g_pShaderAPI->GetIntRenderingParameter(this: g_pShaderAPI, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10048D80
// Name: public: virtual class ITexture __near * CMatRenderContext::GetTextureRenderingParameter(int)const
// Source: json
//------------------------------------------------------------------------------
ITexture *__thiscall CMatRenderContext::GetTextureRenderingParameter(CMatRenderContext *this, int a1)
{
  return g_pShaderAPI->GetTextureRenderingParameter(this: g_pShaderAPI, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10048DA0
// Name: public: virtual class Vector CMatRenderContext::GetVectorRenderingParameter(int)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CMatRenderContext::GetVectorRenderingParameter(CMatRenderContext *this, Vector *result, int a1)
{
  g_pShaderAPI->GetVectorRenderingParameter(this: g_pShaderAPI, result, a3: a1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10048DC0
// Name: public: virtual void CMatRenderContext::GetMaxToRender(class IMesh __near *,bool,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::GetMaxToRender(CMatRenderContext *this, IMesh *a1, BOOL a2, int *a3, int *a4)
{
  g_pShaderAPI->GetMaxToRender(this: g_pShaderAPI, a2: a1, a3: a2, a4: a3, a5: a4);
}

//------------------------------------------------------------------------------
// Address: 0x10048DE0
// Name: public: virtual int CMatRenderContext::GetMaxVerticesToRender(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatRenderContext::GetMaxVerticesToRender(CMatRenderContext *this, IMaterial *a1)
{
  return g_pShaderAPI->GetMaxVerticesToRender(this: g_pShaderAPI, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10048E00
// Name: public: virtual int CMatRenderContext::GetMaxIndicesToRender(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatRenderContext::GetMaxIndicesToRender(CMatRenderContext *this)
{
  return g_pShaderAPI->GetMaxIndicesToRender(this: g_pShaderAPI);
}

//------------------------------------------------------------------------------
// Address: 0x10048E10
// Name: public: virtual void CMatRenderContext::SetStencilState(struct ShaderStencilState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::SetStencilState(CMatRenderContext *this, const ShaderStencilState_t *a1)
{
  g_pShaderAPI->SetStencilState(this: g_pShaderAPI, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10048E30
// Name: public: virtual void CMatRenderContext::ClearStencilBufferRectangle(int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::ClearStencilBufferRectangle(
        CMatRenderContext *this,
        int a1,
        int a2,
        int a3,
        int a4,
        int a5)
{
  g_pShaderAPI->ClearStencilBufferRectangle(this: g_pShaderAPI, a2: a1, a3: a2, a4: a3, a5: a4, a6: a5);
}

//------------------------------------------------------------------------------
// Address: 0x10048E50
// Name: public: virtual void CMatRenderContext::BeginPIXEvent(unsigned long,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::BeginPIXEvent(CMatRenderContext *this, unsigned int a1, const char *a2)
{
  g_pShaderAPI->BeginPIXEvent(this: g_pShaderAPI, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10048E70
// Name: public: virtual void CMatRenderContext::EndPIXEvent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::EndPIXEvent(CMatRenderContext *this)
{
  g_pShaderAPI->EndPIXEvent(this: g_pShaderAPI);
}

//------------------------------------------------------------------------------
// Address: 0x10048E80
// Name: public: virtual void CMatRenderContext::SetPIXMarker(unsigned long,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::SetPIXMarker(CMatRenderContext *this, unsigned int a1, const char *a2)
{
  g_pShaderAPI->SetPIXMarker(this: g_pShaderAPI, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10048EA0
// Name: public: virtual void CMatRenderContext::SetShadowDepthBiasFactors(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::SetShadowDepthBiasFactors(CMatRenderContext *this, float a1, float a2)
{
  ((void (__thiscall *)(IShaderAPI *, _DWORD, _DWORD))g_pShaderAPI->SetShadowDepthBiasFactors)(
    a1: g_pShaderAPI,
    a2: LODWORD(a1),
    a3: LODWORD(a2));
}

//------------------------------------------------------------------------------
// Address: 0x10048EE0
// Name: public: virtual void CMatRenderContext::ForceHardwareSync(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::ForceHardwareSync(CMatRenderContext *this)
{
  g_pShaderAPI->ForceHardwareSync(this: g_pShaderAPI);
}

//------------------------------------------------------------------------------
// Address: 0x10048EF0
// Name: public: virtual void CMatRenderContext::BeginFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::BeginFrame(CMatRenderContext *this)
{
  g_pShaderAPI->BeginFrame(this: g_pShaderAPI);
}

//------------------------------------------------------------------------------
// Address: 0x10048F00
// Name: public: virtual void CMatRenderContext::EndFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::EndFrame(CMatRenderContext *this)
{
  g_pShaderAPI->EndFrame(this: g_pShaderAPI);
}

//------------------------------------------------------------------------------
// Address: 0x10048F10
// Name: public: virtual void CMatRenderContext::PushDeformation(struct DeformationBase_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::PushDeformation(CMatRenderContext *this, const DeformationBase_t *a1)
{
  g_pShaderAPI->PushDeformation(this: g_pShaderAPI, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10048F30
// Name: public: virtual void CMatRenderContext::PopDeformation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::PopDeformation(CMatRenderContext *this)
{
  g_pShaderAPI->PopDeformation(this: g_pShaderAPI);
}

//------------------------------------------------------------------------------
// Address: 0x10048F40
// Name: public: virtual int CMatRenderContext::GetNumActiveDeformations(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatRenderContext::GetNumActiveDeformations(CMatRenderContext *this)
{
  return g_pShaderAPI->GetNumActiveDeformations(this: g_pShaderAPI);
}

//------------------------------------------------------------------------------
// Address: 0x10048F50
// Name: public: virtual void CMatRenderContext::EnableColorCorrection(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::EnableColorCorrection(CMatRenderContext *this, BOOL a1)
{
  g_pColorCorrectionSystem->EnableColorCorrection(this: g_pColorCorrectionSystem, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10048F70
// Name: public: virtual unsigned int CMatRenderContext::AddLookup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CMatRenderContext::AddLookup(CMatRenderContext *this, const char *a1)
{
  return g_pColorCorrectionSystem->AddLookup(this: g_pColorCorrectionSystem, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10048F90
// Name: public: virtual bool CMatRenderContext::RemoveLookup(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatRenderContext::RemoveLookup(CMatRenderContext *this, unsigned int a1)
{
  return g_pColorCorrectionSystem->RemoveLookup(this: g_pColorCorrectionSystem, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10048FB0
// Name: public: virtual void CMatRenderContext::LockLookup(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::LockLookup(CMatRenderContext *this, unsigned int a1)
{
  g_pColorCorrectionSystem->LockLookup(this: g_pColorCorrectionSystem, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10048FD0
// Name: public: virtual void CMatRenderContext::LoadLookup(unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::LoadLookup(CMatRenderContext *this, unsigned int a1, const char *a2)
{
  g_pColorCorrectionSystem->LoadLookup(this: g_pColorCorrectionSystem, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10048FF0
// Name: public: virtual void CMatRenderContext::UnlockLookup(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::UnlockLookup(CMatRenderContext *this, unsigned int a1)
{
  g_pColorCorrectionSystem->UnlockLookup(this: g_pColorCorrectionSystem, a2: a1, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x10049010
// Name: public: virtual void CMatRenderContext::SetLookupWeight(unsigned int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::SetLookupWeight(CMatRenderContext *this, unsigned int a1, float a2)
{
  ((void (__stdcall *)(unsigned int, _DWORD))g_pColorCorrectionSystem->SetLookupWeight)(a1, a2: LODWORD(a2));
}

//------------------------------------------------------------------------------
// Address: 0x10049040
// Name: public: virtual void CMatRenderContext::ResetLookupWeights(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::ResetLookupWeights(CMatRenderContext *this)
{
  g_pColorCorrectionSystem->ResetLookupWeights(this: g_pColorCorrectionSystem);
}

//------------------------------------------------------------------------------
// Address: 0x10049050
// Name: public: virtual void CMatRenderContext::SetResetable(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::SetResetable(CMatRenderContext *this, unsigned int a1, BOOL a2)
{
  g_pColorCorrectionSystem->SetResetable(this: g_pColorCorrectionSystem, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10049070
// Name: public: virtual void CMatRenderContext::AntiAliasingHint(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::AntiAliasingHint(CMatRenderContext *this, int a1)
{
  g_pShaderAPI->AntiAliasingHint(this: g_pShaderAPI, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10049090
// Name: public: virtual void CMatRenderContext::DrawInstances(int,struct MeshInstanceData_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::DrawInstances(CMatRenderContext *this, int a1, const MeshInstanceData_t *a2)
{
  g_pShaderAPI->DrawInstances(this: g_pShaderAPI, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x100490B0
// Name: public: virtual void CMatRenderContext::UpdateGameTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::UpdateGameTime(CMatRenderContext *this, float a1)
{
  ((void (__stdcall *)(_DWORD))g_pShaderAPI->UpdateGameTime)(a1: LODWORD(a1));
}

//------------------------------------------------------------------------------
// Address: 0x100490E0
// Name: public: virtual void CMatRenderContext::SetScaleformSlotViewport(int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::SetScaleformSlotViewport(
        CMatRenderContext *this,
        int slot,
        int x,
        int y,
        int w,
        int h)
{
  g_pScaleformUI->SetSlotViewport(this: g_pScaleformUI, a2: slot, a3: x, a4: y, a5: w, a6: h);
}

//------------------------------------------------------------------------------
// Address: 0x10049100
// Name: public: virtual void CMatRenderContext::RenderScaleformSlot(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::RenderScaleformSlot(CMatRenderContext *this, int slot)
{
  g_pScaleformUI->RenderSlot(this: g_pScaleformUI, a2: slot);
}

//------------------------------------------------------------------------------
// Address: 0x10049120
// Name: public: virtual void CMatRenderContext::SetScaleformCursorViewport(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::SetScaleformCursorViewport(CMatRenderContext *this, int x, int y, int w, int h)
{
  g_pScaleformUI->SetCursorViewport(this: g_pScaleformUI, a2: x, a3: y, a4: w, a5: h);
}

//------------------------------------------------------------------------------
// Address: 0x10049140
// Name: public: virtual void CMatRenderContext::RenderScaleformCursor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::RenderScaleformCursor(CMatRenderContext *this)
{
  g_pScaleformUI->RenderCursor(this: g_pScaleformUI);
}

//------------------------------------------------------------------------------
// Address: 0x10049150
// Name: public: virtual void CMatRenderContext::LoadBoneMatrix(int,struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::LoadBoneMatrix(CMatRenderContext *this, int boneIndex, const matrix3x4_t *matrix)
{
  g_pShaderAPI->LoadBoneMatrix(this: g_pShaderAPI, a2: boneIndex, a3: (const float *)matrix);
}

//------------------------------------------------------------------------------
// Address: 0x10049170
// Name: public: virtual bool CMatRenderContext::InFlashlightMode(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatRenderContext::InFlashlightMode(CMatQueuedRenderContext *this)
{
  return *((_BYTE *)&this->CMatRenderContextBase + 492) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x10049180
// Name: public: virtual bool CMatRenderContext::IsRenderingPaint(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatRenderContext::IsRenderingPaint(CMatRenderContext *this)
{
  return (*((_BYTE *)&this->CMatRenderContextBase + 492) & 0x20) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10049190
// Name: public: virtual void CMatRenderContext::SetFlashlightState(struct FlashlightState_t const __near &,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::SetFlashlightState(
        CMatRenderContext *this,
        const FlashlightState_t *state,
        const VMatrix *worldToTexture)
{
  this->SetFlashlightStateEx(this, a2: state, a3: worldToTexture, a4: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100491B0
// Name: public: virtual void CMatRenderContext::FogColor3ubv(unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::FogColor3ubv(CMatRenderContext *this, const unsigned __int8 *rgb)
{
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))g_pShaderAPI->SceneFogColor3ub)(a1: *rgb, a2: rgb[1], a3: rgb[2]);
}

//------------------------------------------------------------------------------
// Address: 0x100491E0
// Name: public: virtual void CMatRenderContext::FogMaxDensity(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::FogMaxDensity(CMatRenderContext *this, float flMaxDensity)
{
  ((void (__stdcall *)(_DWORD))g_pShaderAPI->FogMaxDensity)(a1: LODWORD(flMaxDensity));
}

//------------------------------------------------------------------------------
// Address: 0x10049220
// Name: public: virtual unsigned int CMatRenderContext::GetBoundMorphFormat(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CMatRenderContext::GetBoundMorphFormat(CMatRenderContext *this)
{
  if ( this->m_pBoundMorph != nullptr )
    return this->m_pBoundMorph->GetMorphFormat(this: this->m_pBoundMorph);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10049240
// Name: public: virtual class IMesh __near * CMatRenderContext::CreateStaticMesh(unsigned __int64,char const __near *,class IMaterial __near *,struct VertexStreamSpec_t __near *)
// Source: json
//------------------------------------------------------------------------------
IMesh *__thiscall CMatRenderContext::CreateStaticMesh(
        CMatRenderContext *this,
        unsigned __int64 vertexFormat,
        const char *pTextureBudgetGroup,
        IMaterial *pMaterial,
        VertexStreamSpec_t *pStreamSpec)
{
  return ((IMesh *(__thiscall *)(IShaderDevice *, _DWORD, _DWORD, const char *, IMaterial *, VertexStreamSpec_t *))g_pShaderDevice->CreateStaticMesh)(
           a1: g_pShaderDevice,
           a2: vertexFormat,
           a3: HIDWORD(vertexFormat),
           a4: pTextureBudgetGroup,
           a5: pMaterial,
           a6: pStreamSpec);
}

//------------------------------------------------------------------------------
// Address: 0x10049270
// Name: public: virtual void CMatRenderContext::SyncToken(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::SyncToken(CMatRenderContext *this, const char *pToken)
{
  if ( g_pShaderAPI != nullptr )
    g_pShaderAPI->SyncToken(this: g_pShaderAPI, a2: pToken);
}

//------------------------------------------------------------------------------
// Address: 0x100492D0
// Name: public: virtual void CMatRenderContext::PushCustomClipPlane(float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::PushCustomClipPlane(CMatRenderContext *this, const float *pPlane)
{
  int m_Size; // edx
  CMatRenderContextBase::PlaneStackElement psePlane; // [esp+0h] [ebp-14h] BYREF

  m_Size = this->m_CustomClipPlanes.m_Size;
  *(_QWORD *)psePlane.fValues = *(_QWORD *)pPlane;
  *(_QWORD *)&psePlane.fValues[2] = *((_QWORD *)pPlane + 1);
  psePlane.bHack_IsHeightClipPlane = false;
  CUtlVector<CMatRenderContextBase::PlaneStackElement,CUtlMemory<CMatRenderContextBase::PlaneStackElement,int>>::InsertBefore(
    this: &this->m_CustomClipPlanes,
    elem: m_Size,
    src: &psePlane);
  this->ApplyCustomClipPlanes(this);
}

//------------------------------------------------------------------------------
// Address: 0x10049320
// Name: public: virtual void CMatRenderContext::UpdateHeightClipUserClipPlane(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContext::UpdateHeightClipUserClipPlane(CMatRenderContext *this)
{
  int v2; // eax
  bool *p_bHack_IsHeightClipPlane; // ecx
  MaterialHeightClipMode_t m_HeightClipMode; // ecx
  __int32 v5; // ecx
  float m_HeightClipZ; // xmm0_4
  CMatRenderContextBase::PlaneStackElement pse; // [esp+4h] [ebp-14h] BYREF

  v2 = this->m_CustomClipPlanes.m_Size - 1;
  pse.bHack_IsHeightClipPlane = true;
  if ( v2 >= 0 )
  {
    p_bHack_IsHeightClipPlane = &this->m_CustomClipPlanes.m_Memory.m_pMemory[v2].bHack_IsHeightClipPlane;
    do
    {
      if ( *p_bHack_IsHeightClipPlane )
        break;
      p_bHack_IsHeightClipPlane -= 20;
      --v2;
    }
    while ( v2 >= 0 );
  }
  m_HeightClipMode = this->m_HeightClipMode;
  if ( m_HeightClipMode == MATERIAL_HEIGHTCLIPMODE_DISABLE )
  {
    if ( v2 != -1 )
      CUtlVector<CMatRenderContextBase::PlaneStackElement,CUtlMemory<CMatRenderContextBase::PlaneStackElement,int>>::Remove(
        this: &this->m_CustomClipPlanes,
        elem: v2);
    goto LABEL_15;
  }
  v5 = m_HeightClipMode - 1;
  if ( v5 != 0 )
  {
    if ( v5 == 1 )
    {
      pse.fValues[0] = 0.0;
      pse.fValues[1] = 0.0;
      pse.fValues[2] = -1.0;
      LODWORD(m_HeightClipZ) = LODWORD(this->m_HeightClipZ) ^ _mask__NegFloat_;
      goto LABEL_9;
    }
LABEL_15:
    this->ApplyCustomClipPlanes(this);
    return;
  }
  pse.fValues[0] = 0.0;
  pse.fValues[1] = 0.0;
  pse.fValues[2] = 1.0;
  m_HeightClipZ = this->m_HeightClipZ;
LABEL_9:
  pse.fValues[3] = m_HeightClipZ;
  if ( v2 == -1 )
  {
    CUtlVector<CMatRenderContextBase::PlaneStackElement,CUtlMemory<CMatRenderContextBase::PlaneStackElement,int>>::InsertBefore(
      this: &this->m_CustomClipPlanes,
      elem: this->m_CustomClipPlanes.m_Size,
      src: &pse);
    this->ApplyCustomClipPlanes(this);
  }
  else
  {
    this->m_CustomClipPlanes.m_Memory.m_pMemory[v2] = pse;
    this->ApplyCustomClipPlanes(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028B2A0
// Name: _dynamic_initializer_for__CMatRenderContextBase::sm_RenderData__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CMatRenderContextBase::sm_RenderData__()
{
  `eh vector constructor iterator'(
    ptr: CMatRenderContextBase::sm_RenderData,
    size: 0x28u,
    count: 2,
    pCtor: (void (__thiscall *)(void *))CMemoryStack::CMemoryStack,
    pDtor: (void (__thiscall *)(void *))CMemoryStack::~CMemoryStack);
  return atexit(func: dynamic_atexit_destructor_for__CMatRenderContextBase::sm_RenderData__);
}

//------------------------------------------------------------------------------
// Address: 0x1028C610
// Name: _dynamic_atexit_destructor_for__CMatRenderContextBase::sm_RenderData__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMatRenderContextBase::sm_RenderData__()
{
  `eh vector destructor iterator'(
    ptr: CMatRenderContextBase::sm_RenderData,
    size: 0x28u,
    count: 2,
    pDtor: (void (__thiscall *)(void *))CMemoryStack::~CMemoryStack);
}

//------------------------------------------------------------------------------
// Address: 0x1028B2D0
// Name: _dynamic_initializer_for__mat_spewalloc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_spewalloc__()
{
  ConVar::ConVar(this: &mat_spewalloc, pName: "mat_spewalloc", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__mat_spewalloc__);
}

//------------------------------------------------------------------------------
// Address: 0x1028C630
// Name: _dynamic_atexit_destructor_for__mat_spewalloc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_spewalloc__()
{
  ConVar::~ConVar(this: &mat_spewalloc);
}

//------------------------------------------------------------------------------
// Address: 0x1028C640
// Name: _dynamic_atexit_destructor_for__mat_texture_list_content_path__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_texture_list_content_path__()
{
  ConVar::~ConVar(this: &mat_texture_list_content_path);
}

//------------------------------------------------------------------------------
// Address: 0x1028C650
// Name: _dynamic_atexit_destructor_for__mat_texture_list_txlod_sync_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_texture_list_txlod_sync_command__()
{
  ConCommand::~ConCommand(this: &mat_texture_list_txlod_sync_command);
}

//------------------------------------------------------------------------------
// Address: 0x1028C660
// Name: _dynamic_atexit_destructor_for__mat_texture_list_exclude_editing__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_texture_list_exclude_editing__()
{
  ConVar::~ConVar(this: &mat_texture_list_exclude_editing);
}

//------------------------------------------------------------------------------
// Address: 0x1028C670
// Name: _dynamic_atexit_destructor_for__mat_texture_list_exclude_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_texture_list_exclude_command__()
{
  ConCommand::~ConCommand(this: &mat_texture_list_exclude_command);
}
