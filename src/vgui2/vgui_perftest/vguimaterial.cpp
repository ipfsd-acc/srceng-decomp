// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_perftest/vguimaterial.cpp
// Functions: 206
// ============================================================

#include "vgui2\vgui_perftest\vguimaterial.h"

//------------------------------------------------------------------------------
// Address: 0x00401260
// Name: public: int CUtlVector<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,class CUtlMemory<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>::InsertMultipleBefore(
        CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CStudioHdr::CActivityToSequenceMapping::HashValueType *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CStudioHdr::CActivityToSequenceMapping::HashValueType *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 16 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->activityIdx = -1;
          v11->startingIdx = -1;
          v11->count = -1;
          v11->totalWeight = -1;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004013C0
// Name: public: int CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
        CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  S3RGBA *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00401D70
// Name: public: class CUtlMemory<struct UtlLinkedListElem_t<struct CTGARenderer::UIQuadInfo,unsigned short>,unsigned short>::Iterator_t CUtlMemory<struct UtlLinkedListElem_t<struct CTGARenderer::UIQuadInfo,unsigned short>,unsigned short>::Next(class CUtlMemory<struct UtlLinkedListElem_t<struct CTGARenderer::UIQuadInfo,unsigned short>,unsigned short>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short>,unsigned short>::Iterator_t *__thiscall CUtlMemory<UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short>,unsigned short>::Next(
        CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short> *this,
        CUtlMemory<UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short>,unsigned short>::Iterator_t *result,
        const CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>::Iterator_t *it)
{
  CUtlMemory<UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short>,unsigned short>::Iterator_t *v3; // eax

  v3 = result;
  if ( (unsigned __int16)(it->index + 1) >= this->m_nAllocationCount )
    result->index = -1;
  else
    result->index = it->index + 1;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x004024E0
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
// Address: 0x00402550
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
// Address: 0x004025D0
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
// Address: 0x00402690
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
// Address: 0x004026F0
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
// Address: 0x00402760
// Name: private: void CMeshBuilder::ComputeNumVertsAndIndices(int __near *,int __near *,enum MaterialPrimitiveType_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::ComputeNumVertsAndIndices(
        CMeshBuilder *this,
        int *pMaxVertices,
        int *pMaxIndices,
        MaterialPrimitiveType_t type,
        int nPrimitiveCount)
{
  switch ( type )
  {
    case MATERIAL_POINTS:
      *pMaxIndices = nPrimitiveCount;
      *pMaxVertices = nPrimitiveCount;
      break;
    case MATERIAL_LINES:
      *pMaxIndices = 2 * nPrimitiveCount;
      *pMaxVertices = 2 * nPrimitiveCount;
      break;
    case MATERIAL_TRIANGLES:
      *pMaxIndices = 3 * nPrimitiveCount;
      *pMaxVertices = 3 * nPrimitiveCount;
      break;
    case MATERIAL_TRIANGLE_STRIP:
      *pMaxIndices = nPrimitiveCount + 2;
      *pMaxVertices = nPrimitiveCount + 2;
      break;
    case MATERIAL_LINE_STRIP:
      *pMaxVertices = nPrimitiveCount + 1;
      *pMaxIndices = 2 * nPrimitiveCount;
      break;
    case MATERIAL_LINE_LOOP:
      *pMaxVertices = nPrimitiveCount;
      *pMaxIndices = 2 * nPrimitiveCount;
      break;
    case MATERIAL_POLYGON:
      *pMaxVertices = nPrimitiveCount;
      *pMaxIndices = 3 * nPrimitiveCount - 6;
      break;
    case MATERIAL_QUADS:
      *pMaxVertices = 4 * nPrimitiveCount;
      *pMaxIndices = 6 * nPrimitiveCount;
      break;
    case MATERIAL_INSTANCED_QUADS:
      *pMaxVertices = nPrimitiveCount;
      *pMaxIndices = 0;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402870
// Name: private: int CMeshBuilder::IndicesFromVertices(enum MaterialPrimitiveType_t,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMeshBuilder::IndicesFromVertices(CMeshBuilder *this, MaterialPrimitiveType_t type, int nVertexCount)
{
  int result; // eax

  switch ( type )
  {
    case MATERIAL_LINE_STRIP:
      result = 2 * nVertexCount - 2;
      break;
    case MATERIAL_LINE_LOOP:
      result = 2 * nVertexCount;
      break;
    case MATERIAL_POLYGON:
      result = 3 * nVertexCount - 6;
      break;
    case MATERIAL_QUADS:
      result = 6 * nVertexCount / 4;
      break;
    case MATERIAL_INSTANCED_QUADS:
      result = 0;
      break;
    default:
      result = nVertexCount;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004028E0
// Name: public: void CMeshBuilder::End(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::End(CMeshBuilder *this, bool bSpewData, bool bDraw)
{
  MaterialPrimitiveType_t m_Type; // edi
  int v5; // eax

  if ( this->m_bGenerateIndices )
  {
    m_Type = this->m_Type;
    v5 = CMeshBuilder::IndicesFromVertices(this, type: m_Type, nVertexCount: this->m_VertexBuilder.m_nVertexCount);
    CIndexBuilder::GenerateIndices(this: &this->m_IndexBuilder, primitiveType: m_Type, nIndexCount: v5);
  }
  if ( bSpewData )
    this->m_pMesh->Spew_2(
      this: this->m_pMesh,
      a2: this->m_VertexBuilder.m_nVertexCount,
      a3: this->m_IndexBuilder.m_nIndexCount,
      a4: this);
  this->m_pMesh->UnlockMesh(
    this: this->m_pMesh,
    a2: this->m_VertexBuilder.m_nVertexCount,
    a3: this->m_IndexBuilder.m_nIndexCount,
    a4: this);
  this->m_IndexBuilder.m_pIndexBuffer = nullptr;
  this->m_IndexBuilder.m_nMaxIndexCount = 0;
  this->m_VertexBuilder.m_nMaxVertexCount = 0;
  this->m_VertexBuilder.m_pVertexBuffer = nullptr;
  this->m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  if ( bDraw )
    this->m_pMesh->Draw_2(this: this->m_pMesh, a2: -1, a3: 0);
  this->m_pMesh = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004029A0
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
// Address: 0x00402A20
// Name: public: void CMeshBuilder::Begin(class IMesh __near *,enum MaterialPrimitiveType_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBuilder::Begin(CMeshBuilder *this, IMesh *pMesh, int type, int numPrimitives)
{
  MaterialPrimitiveType_t v4; // ebp
  IMesh *v5; // edi
  MaterialPrimitiveType_t v7; // ebp
  IMesh *v8; // edx
  MaterialPrimitiveType_t v9; // [esp-8h] [ebp-18h]
  int v10; // [esp-4h] [ebp-14h]

  v4 = type;
  v5 = pMesh;
  v10 = numPrimitives;
  v9 = type;
  this->m_pMesh = pMesh;
  this->m_bGenerateIndices = true;
  this->m_Type = v4;
  pMesh = nullptr;
  type = 0;
  CMeshBuilder::ComputeNumVertsAndIndices(
    this,
    pMaxVertices: (int *)&pMesh,
    pMaxIndices: &type,
    type: v9,
    nPrimitiveCount: v10);
  switch ( v4 )
  {
    case MATERIAL_LINE_STRIP:
    case MATERIAL_LINE_LOOP:
      v5->SetPrimitiveType(this: v5, a2: MATERIAL_LINES);
      break;
    case MATERIAL_POLYGON:
    case MATERIAL_QUADS:
      v5->SetPrimitiveType(this: v5, a2: MATERIAL_TRIANGLES);
      break;
    case MATERIAL_INSTANCED_QUADS:
      v5->SetPrimitiveType(this: v5, a2: MATERIAL_INSTANCED_QUADS);
      break;
    default:
      v5->SetPrimitiveType(this: v5, a2: v4);
      break;
  }
  v7 = type;
  this->m_pMesh->LockMesh(this: this->m_pMesh, a2: (int)pMesh, a3: type, a4: this, a5: nullptr);
  this->m_IndexBuilder.m_nMaxIndexCount = v7;
  this->m_IndexBuilder.m_pIndexBuffer = &v5->IIndexBuffer;
  this->m_IndexBuilder.m_nIndexCount = 0;
  this->m_IndexBuilder.m_bModify = false;
  this->m_IndexBuilder.m_nIndexOffset = this->m_nFirstVertex;
  v8 = pMesh;
  this->m_IndexBuilder.m_pIndices = this->m_pIndices;
  this->m_IndexBuilder.m_nIndexSize = this->m_nIndexSize;
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &this->m_VertexBuilder, pMesh: v5, nMaxVertexCount: (int)v8, desc: this);
  this->m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &this->m_VertexBuilder);
}

//------------------------------------------------------------------------------
// Address: 0x00402B30
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CTGARenderer::UIQuadInfo,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short> *m_pMemory; // edx
  bool v7; // zf

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
    v7 = this->m_pMemory == nullptr;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( v7 )
      this->m_pMemory = (UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                          this: _g_pMemAlloc,
                                                                                          a2: 56 * m_nAllocationCount);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                          this: _g_pMemAlloc,
                                                                                          a2: m_pMemory,
                                                                                          a3: 56 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402C00
// Name: private: int CTGARenderer::FindSheetTextureEntry(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTGARenderer::FindSheetTextureEntry(CTGARenderer *this, int sublayer, const char *pTextureName)
{
  int v4; // edi
  int *v5; // esi
  int i; // ebx
  const char *v7; // eax

  if ( pTextureName == nullptr )
    return 0;
  v4 = 0;
  v5 = (int *)((char *)this + 20 * sublayer);
  if ( v5[4] <= 0 )
    return -1;
  for ( i = 0; ; i += 16 )
  {
    v7 = CUtlString::operator char const *(this: (CUtlString *)(i + v5[1]));
    if ( _V_strcmp(s1: v7, s2: pTextureName) == 0 )
      break;
    if ( ++v4 >= v5[4] )
      return -1;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00402C60
// Name: public: void CUtlIntrusiveDList<class CUtlReference<class CSheet>>::RemoveNode(class CUtlReference<class CSheet> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlIntrusiveDList<CUtlReference<CSheet>>::RemoveNode(
        CUtlIntrusiveDList<CUtlReference<CSheet> > *this,
        CUtlReference<CSheet> *which)
{
  CUtlReference<CSheet> *m_pPrev; // edx
  CUtlReference<CSheet> *m_pNext; // edx
  bool v4; // zf

  m_pPrev = which->m_pPrev;
  if ( m_pPrev != nullptr )
  {
    m_pPrev->m_pNext = which->m_pNext;
    if ( which->m_pNext != nullptr )
    {
      which->m_pNext->m_pPrev = which->m_pPrev;
      which->m_pPrev = nullptr;
      which->m_pNext = nullptr;
      return;
    }
  }
  else if ( this->m_pHead == which )
  {
    m_pNext = which->m_pNext;
    v4 = which->m_pNext == nullptr;
    this->m_pHead = which->m_pNext;
    if ( !v4 )
      m_pNext->m_pPrev = nullptr;
  }
  which->m_pPrev = nullptr;
  which->m_pNext = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00402CB0
// Name: protected: unsigned short CUtlLinkedList<struct CTGARenderer::UIQuadInfo,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CTGARenderer::UIQuadInfo,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlLinkedList<CTGARenderer::UIQuadInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CTGARenderer::UIQuadInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  unsigned __int16 m_FirstFree; // cx
  CUtlMemory<UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short>,unsigned short>::Iterator_t *p_m_LastAlloc; // ebx
  int m_nAllocationCount; // ecx
  unsigned __int16 result; // ax
  int v7; // edi
  unsigned __int16 *v8; // eax
  UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short> *v9; // ecx
  CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>::Iterator_t v10; // [esp+Eh] [ebp-2h] BYREF

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_20:
    v9 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  p_m_LastAlloc = &this->m_LastAlloc;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else if ( (unsigned __int16)(p_m_LastAlloc->index + 1) >= m_nAllocationCount )
  {
    result = -1;
  }
  else
  {
    result = p_m_LastAlloc->index + 1;
  }
  v10.index = result;
  if ( result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short>,unsigned short>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( p_m_LastAlloc->index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      v10.index = (v7 > 0) - 1;
      v8 = (unsigned __int16 *)&v10;
    }
    else
    {
      v8 = (unsigned __int16 *)CUtlMemory<UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short>,unsigned short>::Next(
                                 (CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short> *)this,
                                 result: (CUtlMemory<UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short>,unsigned short>::Iterator_t *)&v10,
                                 it: (const CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>::Iterator_t *)&this->m_LastAlloc);
    }
    result = *v8;
    if ( result >= v7 )
    {
      if ( _executeCount_0 < 10 )
      {
        ++_executeCount_0;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  if ( result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    p_m_LastAlloc->index = result;
    goto LABEL_20;
  }
  if ( _executeCount >= 10 )
    return -1;
  ++_executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00402E30
// Name: public: CTGARenderer::UIQuadInfo::UIQuadInfo(struct CTGARenderer::UIQuadInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
CTGARenderer::UIQuadInfo *__thiscall CTGARenderer::UIQuadInfo::UIQuadInfo(
        CTGARenderer::UIQuadInfo *this,
        const CTGARenderer::UIQuadInfo *__that)
{
  this->x1Pos = __that->x1Pos;
  this->y1Pos = __that->y1Pos;
  this->x2Pos = __that->x2Pos;
  this->y2Pos = __that->y2Pos;
  this->width = __that->width;
  this->height = __that->height;
  CUtlString::CUtlString(this: &this->textureName, string: &__that->textureName);
  this->sheetSequenceNumber = __that->sheetSequenceNumber;
  this->color = __that->color;
  this->sublayer = __that->sublayer;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00402E80
// Name: public: virtual void CTGARenderer::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTGARenderer::Shutdown(CTGARenderer *this)
{
  CTGARenderer::Layer *m_pMemory; // eax
  int v3; // ecx
  CTGARenderer::LayerInfo *v4; // eax
  int i; // edx
  int v6; // edi
  int v7; // ebx

  m_pMemory = this->m_Layers.m_Memory.m_pMemory;
  v3 = 0;
  v4 = &m_pMemory->layerInfo[2];
  for ( i = 10; i != 0; --i )
  {
    v6 = v4[-1].pQuads->m_ElementCount + v4[-2].pQuads->m_ElementCount;
    v7 = v3 + v4->pQuads->m_ElementCount;
    v4 += 3;
    v3 = v7 + v6;
  }
  _Warning(a1: "Total generated quads = %d\n", v7 + v6);
  this->m_Layers.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00402ED0
// Name: private: void CTGARenderer::GenerateUIMesh(class CMatRenderContextPtr __near &,class IMesh __near *,class CUtlLinkedList<struct CTGARenderer::UIQuadInfo,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CTGARenderer::UIQuadInfo,unsigned short>,unsigned short>> __near &,class CSheet __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTGARenderer::GenerateUIMesh(
        CTGARenderer *this,
        CMatRenderContextPtr *pRenderContext,
        IMesh *pMesh,
        CUtlLinkedList<CTGARenderer::UIQuadInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short>,unsigned short> > *quads,
        CSheet *pSheet)
{
  int m_Head; // ecx
  UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short> *m_pMemory; // eax
  int v7; // esi
  color32_s color; // ebx
  float y1Pos; // xmm1_4
  SheetSequenceSample_t *m_pSamples; // ebp
  float *m_pCurrNormal; // ecx
  float m_fTop_V0; // xmm1_4
  float *v13; // eax
  float v14; // xmm0_4
  float *v15; // eax
  int v16; // edi
  float v17; // xmm1_4
  float *v18; // eax
  float y2Pos; // xmm0_4
  float *v20; // eax
  float *v21; // eax
  float m_fBottom_V0; // xmm1_4
  float v23; // xmm0_4
  float *v24; // eax
  float *v25; // eax
  float v26; // xmm1_4
  MaterialPrimitiveType_t v27; // esi
  int v28; // eax
  int y; // [esp+3Ch] [ebp-1F8h] BYREF
  int x; // [esp+40h] [ebp-1F4h] BYREF
  int height; // [esp+44h] [ebp-1F0h] BYREF
  CMeshBuilder meshBuilder; // [esp+48h] [ebp-1ECh] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "GenerateUIMesh",
    a3: 0,
    a4: "GenerateUIMesh",
    a5: false,
    a6: 4);
  if ( quads->m_ElementCount != 0 )
  {
    CMeshBuilder::CMeshBuilder(this: (CMeshBuilder *)&meshBuilder.m_VertexSize_BoneWeight);
    CMeshBuilder::Begin(
      this: (CMeshBuilder *)&meshBuilder.m_VertexSize_BoneWeight,
      pMesh,
      type: 7,
      numPrimitives: quads->m_ElementCount);
    pRenderContext->m_pObject->GetViewport(
      this: pRenderContext->m_pObject,
      a2: &height,
      a3: &x,
      a4: &y,
      a5: (int *)&meshBuilder);
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "meshBuilder",
      a3: 0,
      a4: "meshBuilder",
      a5: false,
      a6: 4);
    m_Head = quads->m_Head;
    if ( m_Head != 0xFFFF )
    {
      m_pMemory = quads->m_Memory.m_pMemory;
      do
      {
        v7 = (unsigned __int16)m_Head;
        color = m_pMemory[v7].m_Element.color;
        y1Pos = (float)m_pMemory[v7].m_Element.y1Pos;
        m_pSamples = pSheet->m_SheetInfo.m_Memory.m_pMemory[m_pMemory[v7].m_Element.sheetSequenceNumber].m_pSamples;
        m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = (float)m_pMemory[v7].m_Element.x1Pos;
        m_pCurrNormal[1] = y1Pos;
        m_pCurrNormal[2] = 0.0;
        LOBYTE(m_pCurrNormal) = 0;
        BYTE1(m_pCurrNormal) = color.a;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = color.b
                                                                  | ((color.g
                                                                    | ((color.r | (unsigned __int16)m_pCurrNormal) << 8)) << 8);
        m_fTop_V0 = m_pSamples->m_TextureCoordData[0].m_fTop_V0;
        v13 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] + 1;
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = m_pSamples->m_TextureCoordData[0].m_fLeft_U0;
        *v13 = m_fTop_V0;
        v13[1] = 0.0;
        CVertexBuilder::AdvanceVertex(this: (CVertexBuilder *)&meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight);
        v14 = (float)quads->m_Memory.m_pMemory[v7].m_Element.y1Pos;
        v15 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = (float)quads->m_Memory.m_pMemory[v7].m_Element.x2Pos;
        v15[1] = v14;
        v15[2] = 0.0;
        v16 = color.b | ((color.g | ((color.r | (color.a << 8)) << 8)) << 8);
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v16;
        v17 = m_pSamples->m_TextureCoordData[0].m_fTop_V0;
        v18 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] + 1;
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = m_pSamples->m_TextureCoordData[0].m_fRight_U0;
        *v18 = v17;
        v18[1] = 0.0;
        CVertexBuilder::AdvanceVertex(this: (CVertexBuilder *)&meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight);
        y2Pos = (float)quads->m_Memory.m_pMemory[v7].m_Element.y2Pos;
        v20 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = (float)quads->m_Memory.m_pMemory[v7].m_Element.x2Pos;
        v20[1] = y2Pos;
        v20[2] = 0.0;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v16;
        v21 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
        m_fBottom_V0 = m_pSamples->m_TextureCoordData[0].m_fBottom_V0;
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = m_pSamples->m_TextureCoordData[0].m_fRight_U0;
        *++v21 = m_fBottom_V0;
        v21[1] = 0.0;
        CVertexBuilder::AdvanceVertex(this: (CVertexBuilder *)&meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight);
        v23 = (float)quads->m_Memory.m_pMemory[v7].m_Element.y2Pos;
        v24 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
        *meshBuilder.m_VertexBuilder.m_pCurrNormal = (float)quads->m_Memory.m_pMemory[v7].m_Element.x1Pos;
        v24[1] = v23;
        v24[2] = 0.0;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = v16;
        v25 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
        v26 = m_pSamples->m_TextureCoordData[0].m_fBottom_V0;
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = m_pSamples->m_TextureCoordData[0].m_fLeft_U0;
        *++v25 = v26;
        v25[1] = 0.0;
        CVertexBuilder::AdvanceVertex(this: (CVertexBuilder *)&meshBuilder.m_VertexBuilder.m_VertexSize_BoneWeight);
        m_pMemory = quads->m_Memory.m_pMemory;
        m_Head = quads->m_Memory.m_pMemory[v7].m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    if ( LOBYTE(meshBuilder.m_IndexBuilder.m_pIndices) != 0 )
    {
      v27 = *(_DWORD *)&meshBuilder.m_bGenerateIndices;
      v28 = CMeshBuilder::IndicesFromVertices(
              this: (CMeshBuilder *)&meshBuilder.m_VertexSize_BoneWeight,
              type: *(MaterialPrimitiveType_t *)&meshBuilder.m_bGenerateIndices,
              nVertexCount: meshBuilder.m_VertexBuilder.m_nCurrentVertex);
      CIndexBuilder::GenerateIndices(
        this: (CIndexBuilder *)&meshBuilder.m_IndexBuilder.m_nOffset,
        primitiveType: v27,
        nIndexCount: v28);
    }
    (*(void (__thiscall **)(MaterialPrimitiveType_t, int, int, int *))(*(_DWORD *)meshBuilder.m_Type + 80))(
      a1: meshBuilder.m_Type,
      a2: meshBuilder.m_VertexBuilder.m_nCurrentVertex,
      a3: meshBuilder.m_IndexBuilder.m_nIndexOffset,
      a4: &meshBuilder.m_VertexSize_BoneWeight);
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
    *(_DWORD *)&meshBuilder.m_VertexBuilder.m_bModify = 0;
    meshBuilder.m_VertexBuilder.m_NumBoneWeights = -1;
    meshBuilder.m_Type = MATERIAL_POINTS;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x00403230
// Name: public: int CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::InsertBefore(int,class CUtlString const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        int elem,
        const CUtlString *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlString *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  CUtlString *v9; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    CUtlString::CUtlString(this: v9, string: src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004032A0
// Name: public: void CUtlLinkedList<struct CTGARenderer::UIQuadInfo,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CTGARenderer::UIQuadInfo,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CTGARenderer::UIQuadInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CTGARenderer::UIQuadInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short> *v3; // eax
  unsigned __int16 m_Next; // dx
  unsigned __int16 m_Previous; // bx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Next = v3->m_Next;
      m_Previous = v3->m_Previous;
      if ( m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        v2 = elem;
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      }
      if ( m_Next == 0xFFFF )
      {
        --this->m_ElementCount;
        this->m_Tail = m_Previous;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
        --this->m_ElementCount;
      }
      v3->m_Next = v2;
      v3->m_Previous = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403360
// Name: public: virtual void CTGARenderer::Render(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTGARenderer::Render(CTGARenderer *this)
{
  CTGARenderer *v1; // edi
  IMatRenderContext *v2; // esi
  int v3; // ebp
  CSheet **p_m_pObject; // ebx
  IMesh *v5; // edi
  int i; // [esp+ACh] [ebp-18h]
  int height; // [esp+B0h] [ebp-14h] BYREF
  int width; // [esp+B4h] [ebp-10h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+B8h] [ebp-Ch] BYREF
  int y; // [esp+BCh] [ebp-8h] BYREF
  int x; // [esp+C0h] [ebp-4h] BYREF

  v1 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "Render",
    a3: 0,
    a4: "Render",
    a5: false,
    a6: 4);
  if ( v1->m_bInitialized )
  {
    v2 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    pRenderContext.m_pObject = v2;
    if ( v2 != nullptr )
      v2->BeginRender(this: v2);
    v2->ClearColor4ub(this: v2, a2: 76u, a3: 88u, a4: 68u, a5: 255u);
    v2->ClearBuffers(this: v2, a2: true, a3: true, a4: false);
    v2->GetViewport(this: v2, a2: &x, a3: &y, a4: &width, a5: &height);
    v2->MatrixMode(this: v2, a2: MATERIAL_PROJECTION);
    v2->PushMatrix(this: v2);
    v2->LoadIdentity(this: v2);
    ((void (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, _DWORD))v2->Scale)(a1: v2, a2: 1.0, a3: -1.0, a4: 1.0);
    ((void (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v2->Ortho)(
      a1: v2,
      a2: COERCE_UNSIGNED_INT64(0.5),
      a3: HIDWORD(COERCE_UNSIGNED_INT64(0.5)),
      a4: COERCE_UNSIGNED_INT64(0.5),
      a5: HIDWORD(COERCE_UNSIGNED_INT64(0.5)),
      a6: COERCE_UNSIGNED_INT64((float)((float)width + 0.5)),
      a7: HIDWORD(COERCE_UNSIGNED_INT64((float)((float)width + 0.5))),
      a8: COERCE_UNSIGNED_INT64((float)((float)height + 0.5)),
      a9: HIDWORD(COERCE_UNSIGNED_INT64((float)((float)height + 0.5))),
      a10: COERCE_UNSIGNED_INT64(-1.0),
      a11: HIDWORD(COERCE_UNSIGNED_INT64(-1.0)),
      a12: COERCE_UNSIGNED_INT64(1.0),
      a13: HIDWORD(COERCE_UNSIGNED_INT64(1.0)));
    v2->MatrixMode(this: v2, a2: MATERIAL_MODEL);
    v2->PushMatrix(this: v2);
    v2->LoadIdentity(this: v2);
    v2->MatrixMode(this: v2, a2: MATERIAL_VIEW);
    v2->PushMatrix(this: v2);
    v2->LoadIdentity(this: v2);
    v3 = 0;
    do
    {
      p_m_pObject = &v1->m_LayerTextureInfo[0].m_Sheet.m_pObject;
      for ( i = 3; i != 0; --i )
      {
        if ( v1->m_Layers.m_Memory.m_pMemory->layerInfo[v3].pQuads->m_ElementCount != 0 )
        {
          v2->Bind(this: v2, a2: (IMaterial *)*(p_m_pObject - 3), a3: nullptr);
          v5 = v2->GetDynamicMesh(this: v2, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
          CTGARenderer::GenerateUIMesh(
            this,
            &pRenderContext,
            pMesh: v5,
            quads: this->m_Layers.m_Memory.m_pMemory->layerInfo[v3].pQuads,
            pSheet: *p_m_pObject);
          v5->Draw_2(this: v5, a2: -1, a3: 0);
          v1 = this;
        }
        ++v3;
        p_m_pObject += 4;
      }
    }
    while ( v3 < 30 );
    v2->MatrixMode(this: v2, a2: MATERIAL_PROJECTION);
    v2->PopMatrix(this: v2);
    v2->MatrixMode(this: v2, a2: MATERIAL_MODEL);
    v2->PopMatrix(this: v2);
    v2->MatrixMode(this: v2, a2: MATERIAL_VIEW);
    v2->PopMatrix(this: v2);
    v2->EndRender(this: v2);
    v2->Release(this: v2);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    _Warning(a1: "CTGARenderer: Unable to render.\n");
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004035E0
// Name: private: bool CTGARenderer::InitSheetTexture(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTGARenderer::InitSheetTexture(CTGARenderer *this, int sublayer, const char *pBaseTextureName)
{
  KeyValues *v4; // eax
  KeyValues *v5; // ebp
  CTGARenderer::LayerTextureInfo *v6; // esi
  const char *v7; // eax
  CSheet *Sheet; // eax
  CSheet *v9; // esi
  const char *v10; // eax
  CSheet *m_pObject; // ecx
  CUtlReference<CSheet> *p_m_Sheet; // edi
  CUtlString materialName; // [esp+Ch] [ebp-14h] BYREF
  int v15; // [esp+1Ch] [ebp-4h]

  CUtlString::CUtlString(this: (CUtlString *)&materialName.m_Storage.m_Memory.m_nAllocationCount);
  if ( sublayer != 0 )
  {
    if ( sublayer == 1 )
    {
      CUtlString::operator=(this: (CUtlString *)&materialName.m_Storage.m_Memory.m_nAllocationCount, src: "dynamictx");
    }
    else if ( sublayer == 2 )
    {
      CUtlString::operator=(this: (CUtlString *)&materialName.m_Storage.m_Memory.m_nAllocationCount, src: "fonttx");
    }
    else
    {
      _Warning(a1: "CTGARenderer: Invalid sublayer for %s\n", pBaseTextureName);
    }
  }
  else
  {
    CUtlString::operator=(this: (CUtlString *)&materialName.m_Storage.m_Memory.m_nAllocationCount, src: "statictx");
  }
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "GameControls");
  else
    v5 = nullptr;
  KeyValues::SetString(this: v5, keyName: "$basetexture", value: pBaseTextureName);
  v6 = &this->m_LayerTextureInfo[sublayer];
  v7 = CUtlString::operator char const *(this: (CUtlString *)&materialName.m_Storage.m_Memory.m_nAllocationCount);
  CMaterialReference::Init(
    this: &v6->m_SublayerMaterial,
    pMaterialName: v7,
    pTextureGroupName: "Other textures",
    pVMTKeyValues: v5);
  v6->m_SublayerMaterial.m_pMaterial->Refresh(this: v6->m_SublayerMaterial.m_pMaterial);
  Sheet = CTGARenderer::LoadSheet((CGameLayer *)this, pMaterial: v6->m_SublayerMaterial.m_pMaterial);
  v9 = Sheet;
  if ( Sheet != nullptr )
  {
    m_pObject = this->m_LayerTextureInfo[sublayer].m_Sheet.m_pObject;
    p_m_Sheet = &this->m_LayerTextureInfo[sublayer].m_Sheet;
    if ( m_pObject != Sheet )
    {
      if ( m_pObject != nullptr )
      {
        CUtlIntrusiveDList<CUtlReference<CSheet>>::RemoveNode(this: &m_pObject->m_References, which: p_m_Sheet);
        this->m_LayerTextureInfo[sublayer].m_Sheet.m_pObject = nullptr;
      }
      this->m_LayerTextureInfo[sublayer].m_Sheet.m_pObject = v9;
      p_m_Sheet->m_pNext = v9->m_References.m_pHead;
      if ( v9->m_References.m_pHead != nullptr )
        v9->m_References.m_pHead->m_pPrev = p_m_Sheet;
      this->m_LayerTextureInfo[sublayer].m_Sheet.m_pPrev = nullptr;
      v9->m_References.m_pHead = p_m_Sheet;
    }
    v15 = 0;
    if ( materialName.m_Storage.m_nActualLength >= 0 && materialName.m_Storage.m_Memory.m_nAllocationCount != 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)materialName.m_Storage.m_Memory.m_nAllocationCount);
    return 1;
  }
  else
  {
    v10 = CUtlString::Get(this: (CUtlString *)&materialName.m_Storage.m_Memory.m_nAllocationCount);
    _Warning(a1: "CTGARenderer: Unable to load sheet for %s %s\n", v10, pBaseTextureName);
    v15 = 0;
    if ( materialName.m_Storage.m_nActualLength >= 0 && materialName.m_Storage.m_Memory.m_nAllocationCount != 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)materialName.m_Storage.m_Memory.m_nAllocationCount);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403760
// Name: private: void CTGARenderer::AddSheetTextureEntry(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTGARenderer::AddSheetTextureEntry(CTGARenderer *this, int sublayer, const char *pTextureName)
{
  CUtlString src; // [esp+4h] [ebp-10h] BYREF

  CUtlString::CUtlString(this: &src, pString: pTextureName);
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
    this: &this->m_sheetDict[sublayer].m_SheetTexEntry,
    elem: this->m_sheetDict[sublayer].m_SheetTexEntry.m_Size,
    &src);
  src.m_Storage.m_nActualLength = 0;
  if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004037C0
// Name: public: unsigned short CUtlLinkedList<struct CTGARenderer::UIQuadInfo,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CTGARenderer::UIQuadInfo,unsigned short>,unsigned short>>::AddToTail(struct CTGARenderer::UIQuadInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CTGARenderer::UIQuadInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short>,unsigned short>>::AddToTail(
        CUtlLinkedList<CTGARenderer::UIQuadInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short>,unsigned short> > *this,
        const CTGARenderer::UIQuadInfo *src)
{
  unsigned __int16 v3; // ax
  unsigned __int16 v4; // di
  int v6; // eax
  UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short> *v7; // ecx
  unsigned __int16 m_Tail; // bx
  UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short> *m_pMemory; // ecx
  CTGARenderer::UIQuadInfo *p_m_Element; // ecx

  v3 = CUtlLinkedList<CTGARenderer::UIQuadInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short>,unsigned short>>::AllocInternal(
         this,
         multilist: false);
  v4 = v3;
  if ( v3 == 0xFFFF )
    return 0xFFFF;
  CUtlLinkedList<CTGARenderer::UIQuadInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short>,unsigned short>>::Unlink(
    this,
    elem: v3);
  v6 = v4;
  v7 = &this->m_Memory.m_pMemory[v6];
  v7->m_Next = -1;
  m_Tail = this->m_Tail;
  v7->m_Previous = m_Tail;
  this->m_Tail = v4;
  if ( m_Tail == 0xFFFF )
    this->m_Head = v4;
  else
    this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
  m_pMemory = this->m_Memory.m_pMemory;
  ++this->m_ElementCount;
  p_m_Element = &m_pMemory[v6].m_Element;
  if ( p_m_Element != nullptr )
    CTGARenderer::UIQuadInfo::UIQuadInfo(this: p_m_Element, __that: src);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00403860
// Name: public: CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::~CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this)
{
  bool v2; // sf
  CUtlBinaryBlock *m_pMemory; // eax

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004038C0
// Name: public: virtual void CTGARenderer::Init(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTGARenderer::Init(CTGARenderer *this, int screenWidth, int screenHeight, int numTiles)
{
  CUtlVector<CTGARenderer::Layer,CUtlMemory<CTGARenderer::Layer,int> > *p_m_Layers; // ebp
  int v6; // edi
  CUtlLinkedList<CTGARenderer::UIQuadInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short>,unsigned short> > *v7; // eax
  UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short> *m_pMemory; // ecx
  int SheetTextureEntry; // edi
  int v10; // edi
  bool v11; // sf
  CTGARenderer::UIQuadInfo testQuad; // [esp+8h] [ebp-6Ch] BYREF
  int v13; // [esp+3Ch] [ebp-38h]
  int v14; // [esp+40h] [ebp-34h]
  int v15; // [esp+44h] [ebp-30h]
  int v16; // [esp+48h] [ebp-2Ch]
  int v17; // [esp+4Ch] [ebp-28h]
  int v18; // [esp+50h] [ebp-24h]
  int v19; // [esp+54h] [ebp-20h]
  CUtlString src; // [esp+58h] [ebp-1Ch] BYREF
  color32_s v21; // [esp+68h] [ebp-Ch]
  int v22; // [esp+6Ch] [ebp-8h]
  int v23; // [esp+70h] [ebp-4h]

  this->m_bInitialized = false;
  CTGARenderer::AddSheetTextureEntry(this, sublayer: 0, pTextureName: "pixel.tga");
  CTGARenderer::AddSheetTextureEntry(this, sublayer: 0, pTextureName: "decalposter003a.tga");
  CTGARenderer::AddSheetTextureEntry(this, sublayer: 0, pTextureName: "decalgraffiti037a.tga");
  CTGARenderer::AddSheetTextureEntry(this, sublayer: 0, pTextureName: "Climb_node.tga");
  CTGARenderer::AddSheetTextureEntry(this, sublayer: 0, pTextureName: "gibshooter.tga");
  CTGARenderer::AddSheetTextureEntry(this, sublayer: 0, pTextureName: "ErrorIcon.tga");
  CTGARenderer::AddSheetTextureEntry(this, sublayer: 1, pTextureName: "glassclock001a.tga");
  CTGARenderer::AddSheetTextureEntry(this, sublayer: 1, pTextureName: "decalgraffiti038a.tga");
  CTGARenderer::AddSheetTextureEntry(this, sublayer: 1, pTextureName: "Air_node_hint.tga");
  CTGARenderer::AddSheetTextureEntry(this, sublayer: 1, pTextureName: "info_lighting.tga");
  CTGARenderer::AddSheetTextureEntry(this, sublayer: 1, pTextureName: "SelfIllumIcon.tga");
  CTGARenderer::AddSheetTextureEntry(this, sublayer: 2, pTextureName: "glasswindow006a.tga");
  CTGARenderer::AddSheetTextureEntry(this, sublayer: 2, pTextureName: "decalgraffiti043a.tga");
  CTGARenderer::AddSheetTextureEntry(this, sublayer: 2, pTextureName: "Ground_node.tga");
  CTGARenderer::AddSheetTextureEntry(this, sublayer: 2, pTextureName: "info_target.tga");
  CTGARenderer::AddSheetTextureEntry(this, sublayer: 2, pTextureName: "translucenticon.tga");
  if ( CTGARenderer::InitSheetTexture(this, sublayer: 0, pBaseTextureName: "debug/sheettest/debug_meta1") != 0 )
  {
    if ( CTGARenderer::InitSheetTexture(this, sublayer: 1, pBaseTextureName: "debug/sheettest/debug_meta2") != 0 )
    {
      if ( CTGARenderer::InitSheetTexture(this, sublayer: 2, pBaseTextureName: "debug/sheettest/debug_meta3") != 0 )
      {
        p_m_Layers = &this->m_Layers;
        this->m_Layers.m_Size = 0;
        v6 = 0;
        do
        {
          CUtlVector<CTGARenderer::Layer,CUtlMemory<CTGARenderer::Layer,int>>::InsertBefore(
            this: (CUtlVector<CFontAmalgam::TFontRange,CUtlMemory<CFontAmalgam::TFontRange,int> > *)&this->m_Layers,
            elem: this->m_Layers.m_Size);
          testQuad.x1Pos = 3;
          do
          {
            v7 = (CUtlLinkedList<CTGARenderer::UIQuadInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short>,unsigned short> > *)MemAlloc_Alloc(nSize: 0x1Cu);
            if ( v7 != nullptr )
            {
              v7->m_Memory.m_pMemory = nullptr;
              v7->m_Memory.m_nAllocationCount = 0;
              v7->m_Memory.m_nGrowSize = 0;
              v7->m_LastAlloc.index = -1;
              v7->m_Head = -1;
              v7->m_Tail = -1;
              v7->m_FirstFree = -1;
              m_pMemory = v7->m_Memory.m_pMemory;
              v7->m_ElementCount = 0;
              v7->m_NumAlloced = 0;
              v7->m_pElements = m_pMemory;
            }
            else
            {
              v7 = nullptr;
            }
            p_m_Layers->m_Memory.m_pMemory->layerInfo[v6++].pQuads = v7;
            --testQuad.x1Pos;
          }
          while ( testQuad.x1Pos != 0 );
        }
        while ( v6 < 30 );
        CUtlString::CUtlString(this: (CUtlString *)&testQuad.textureName.m_Storage.m_Memory.m_nAllocationCount);
        v13 = -1;
        testQuad.color = (color32_s)-1;
        testQuad.sublayer = -1;
        CUtlString::operator=(
          this: (CUtlString *)&testQuad.textureName.m_Storage.m_Memory.m_nAllocationCount,
          src: defaultValue);
        SheetTextureEntry = CTGARenderer::FindSheetTextureEntry(this, sublayer: 0, pTextureName: "gibshooter.tga");
        CUtlString::CUtlString(this: &src);
        v14 = 0;
        v15 = 0;
        v18 = 64;
        v19 = 64;
        v16 = 64;
        v17 = 64;
        v23 = 0;
        v21 = (color32_s)SheetTextureEntry;
        testQuad.y1Pos = 0;
        testQuad.x2Pos = 0;
        testQuad.y2Pos = 64;
        testQuad.width = 64;
        testQuad.height = 64;
        testQuad.textureName.m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)64;
        CUtlString::operator=(this: (CUtlString *)&testQuad.textureName.m_Storage.m_Memory.m_nAllocationCount, &src);
        testQuad.color = v21;
        testQuad.sublayer = v22;
        v13 = v23;
        src.m_Storage.m_nActualLength = 0;
        if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
        CUtlLinkedList<CTGARenderer::UIQuadInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short>,unsigned short>>::AddToTail(
          this: p_m_Layers->m_Memory.m_pMemory->layerInfo[v13].pQuads,
          src: (const CTGARenderer::UIQuadInfo *)&testQuad.y1Pos);
        v10 = CTGARenderer::FindSheetTextureEntry(this, sublayer: 1, pTextureName: "Air_node_hint.tga");
        CUtlString::CUtlString(this: &src);
        v17 = 256;
        testQuad.width = 256;
        v14 = 0;
        v15 = 128;
        v18 = 128;
        v19 = 128;
        v16 = 128;
        v23 = 1;
        v21 = (color32_s)v10;
        testQuad.y1Pos = 0;
        testQuad.x2Pos = 128;
        testQuad.y2Pos = 128;
        testQuad.height = 128;
        testQuad.textureName.m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)128;
        CUtlString::operator=(this: (CUtlString *)&testQuad.textureName.m_Storage.m_Memory.m_nAllocationCount, &src);
        testQuad.color = v21;
        testQuad.sublayer = v22;
        v13 = v23;
        src.m_Storage.m_nActualLength = 0;
        if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
        CUtlLinkedList<CTGARenderer::UIQuadInfo,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short>,unsigned short>>::AddToTail(
          this: p_m_Layers->m_Memory.m_pMemory->layerInfo[v13].pQuads,
          src: (const CTGARenderer::UIQuadInfo *)&testQuad.y1Pos);
        v11 = testQuad.textureName.m_Storage.m_nActualLength < 0;
        this->m_bInitialized = true;
        testQuad.sheetSequenceNumber = 0;
        if ( !v11 && testQuad.textureName.m_Storage.m_Memory.m_nAllocationCount != 0 )
          _g_pMemAlloc->Free_2(
            this: _g_pMemAlloc,
            a2: (void *)testQuad.textureName.m_Storage.m_Memory.m_nAllocationCount);
      }
      else
      {
        _Warning(a1: "CDataModel: Unable to load sheet for %s\n", "debug/sheettest/debug_meta3");
      }
    }
    else
    {
      _Warning(a1: "CDataModel: Unable to load sheet for %s\n", "debug/sheettest/debug_meta2");
    }
  }
  else
  {
    _Warning(a1: "CDataModel: Unable to load sheet for %s\n", "debug/sheettest/debug_meta1");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403C80
// Name: public: CTGARenderer::CTGARenderer(void)
// Source: json
//------------------------------------------------------------------------------
CTGARenderer *__thiscall CTGARenderer::CTGARenderer(CTGARenderer *this)
{
  CTGARenderer::SheetInfo *m_sheetDict; // eax
  int i; // edx
  CTGARenderer::LayerTextureInfo *m_LayerTextureInfo; // ebx
  int v4; // ebp
  CSheet **p_m_pObject; // esi

  this->__vftable = (CTGARenderer_vtbl *)&CTGARenderer::`vftable';
  m_sheetDict = this->m_sheetDict;
  for ( i = 2; i >= 0; --i )
  {
    m_sheetDict->m_SheetTexEntry.m_Memory.m_pMemory = nullptr;
    m_sheetDict->m_SheetTexEntry.m_Memory.m_nAllocationCount = 0;
    m_sheetDict->m_SheetTexEntry.m_Memory.m_nGrowSize = 0;
    m_sheetDict->m_SheetTexEntry.m_Size = 0;
    m_sheetDict->m_SheetTexEntry.m_pElements = nullptr;
    ++m_sheetDict;
  }
  m_LayerTextureInfo = this->m_LayerTextureInfo;
  v4 = 2;
  p_m_pObject = &this->m_LayerTextureInfo[0].m_Sheet.m_pObject;
  do
  {
    CMaterialReference::CMaterialReference(
      this: &m_LayerTextureInfo->m_SublayerMaterial,
      pMaterialName: nullptr,
      pTextureGroupName: nullptr,
      bComplain: true);
    *(p_m_pObject - 1) = nullptr;
    *(p_m_pObject - 2) = nullptr;
    *p_m_pObject = nullptr;
    ++m_LayerTextureInfo;
    p_m_pObject += 4;
    --v4;
  }
  while ( v4 >= 0 );
  this->m_Layers.m_Memory.m_pMemory = nullptr;
  this->m_Layers.m_Memory.m_nAllocationCount = 0;
  this->m_Layers.m_Memory.m_nGrowSize = 0;
  this->m_Layers.m_Size = 0;
  this->m_Layers.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00403D00
// Name: public: CTGARenderer::~CTGARenderer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTGARenderer::~CTGARenderer(CTGARenderer *this)
{
  CUtlVector<CTGARenderer::Layer,CUtlMemory<CTGARenderer::Layer,int> > *p_m_Layers; // esi
  CMaterialReference *v3; // edi
  int *p_m_nGrowSize; // esi
  int **v5; // eax
  int v6; // eax
  int *v7; // ecx
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *m_LayerTextureInfo; // esi
  int i; // edi
  bool v10; // sf
  CUtlBinaryBlock *m_pMemory; // eax
  int v12; // [esp+10h] [ebp-4h]

  p_m_Layers = &this->m_Layers;
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Layers);
  v3 = (CMaterialReference *)p_m_Layers;
  v12 = 2;
  p_m_nGrowSize = &p_m_Layers->m_Memory.m_nGrowSize;
  do
  {
    v5 = (int **)*(p_m_nGrowSize - 3);
    p_m_nGrowSize -= 4;
    v3 -= 4;
    if ( v5 != nullptr )
    {
      if ( *p_m_nGrowSize != 0 )
      {
        *(_DWORD *)*p_m_nGrowSize = *(p_m_nGrowSize - 1);
        v6 = *(p_m_nGrowSize - 1);
        if ( v6 != 0 )
          *(_DWORD *)(v6 + 4) = *p_m_nGrowSize;
      }
      else if ( *v5 == p_m_nGrowSize - 1 )
      {
        v7 = (int *)*(p_m_nGrowSize - 1);
        *v5 = v7;
        if ( v7 != nullptr )
          v7[1] = 0;
      }
      *p_m_nGrowSize = 0;
      *(p_m_nGrowSize - 1) = 0;
      p_m_nGrowSize[1] = 0;
    }
    CMaterialReference::~CMaterialReference(this: v3);
    --v12;
  }
  while ( v12 >= 0 );
  m_LayerTextureInfo = (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)this->m_LayerTextureInfo;
  for ( i = 2; i >= 0; --i )
  {
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: --m_LayerTextureInfo);
    if ( m_LayerTextureInfo->m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_LayerTextureInfo->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_LayerTextureInfo->m_Memory.m_pMemory);
        m_LayerTextureInfo->m_Memory.m_pMemory = nullptr;
      }
      m_LayerTextureInfo->m_Memory.m_nAllocationCount = 0;
    }
    v10 = m_LayerTextureInfo->m_Memory.m_nGrowSize < 0;
    m_pMemory = m_LayerTextureInfo->m_Memory.m_pMemory;
    m_LayerTextureInfo->m_pElements = m_LayerTextureInfo->m_Memory.m_pMemory;
    if ( !v10 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        m_LayerTextureInfo->m_Memory.m_pMemory = nullptr;
      }
      m_LayerTextureInfo->m_Memory.m_nAllocationCount = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404390
// Name: protected: void CUtlVector<class CUtlSymbolTable,class CUtlMemory<class CUtlSymbolTable,int>>::ShiftElementsRight(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int>>::ShiftElementsRight(
        CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int> > *this,
        int elem,
        int num)
{
  if ( this->m_Size - elem - num > 0 && num > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem + num],
      src: &this->m_Memory.m_pMemory[elem],
      count: 56 * (this->m_Size - elem - num));
}

//------------------------------------------------------------------------------
// Address: 0x004043F0
// Name: public: void CUtlMemory<class CUtlSymbolTable,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlSymbolTable,int>::Grow(CUtlMemory<CUtlSymbolTable,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbolTable *m_pMemory; // edx
  bool v7; // zf

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
    v7 = this->m_pMemory == nullptr;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( v7 )
      this->m_pMemory = (CUtlSymbolTable *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 56 * m_nAllocationCount);
    else
      this->m_pMemory = (CUtlSymbolTable *)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: m_pMemory,
                                             a3: 56 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004044B0
// Name: public: void CUtlVector<class CUtlSymbolTable,class CUtlMemory<class CUtlSymbolTable,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int>>::RemoveAll(
        CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int> > *this)
{
  int v2; // esi
  int v3; // edi

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_Memory.m_pMemory[v3]);
      --v2;
      --v3;
    }
    while ( v2 >= 0 );
  }
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004049E0
// Name: public: int CUtlVector<struct CTGARenderer::Layer,class CUtlMemory<struct CTGARenderer::Layer,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CTGARenderer::Layer,CUtlMemory<CTGARenderer::Layer,int>>::InsertBefore(
        CUtlVector<CFontAmalgam::TFontRange,CUtlMemory<CFontAmalgam::TFontRange,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CFontAmalgam::TFontRange *m_pMemory; // ecx
  int v6; // eax
  int v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v7 = v6 - elem - 1;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00404B40
// Name: public: int CUtlVector<class CUtlSymbolTable,class CUtlMemory<class CUtlSymbolTable,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int>>::InsertMultipleBefore(
        CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlSymbolTable *m_pMemory; // eax
  int v9; // ebx
  CUtlSymbolTable *v10; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlSymbolTable,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size += num;
  this->m_pElements = m_pMemory;
  CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int>>::ShiftElementsRight(this, elem, num);
  if ( num > 0 )
  {
    v9 = elem;
    do
    {
      v10 = &this->m_Memory.m_pMemory[v9];
      if ( v10 != nullptr )
        CUtlSymbolTable::CUtlSymbolTable(this: v10, growSize: 0, initSize: 16, caseInsensitive: false);
      ++v9;
      --v3;
    }
    while ( v3 != 0 );
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004051A0
// Name: public: CUtlVector<class CUtlSymbolTable,class CUtlMemory<class CUtlSymbolTable,int>>::~CUtlVector<class CUtlSymbolTable,class CUtlMemory<class CUtlSymbolTable,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int>>::~CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int>>(
        CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int> > *this)
{
  bool v2; // sf
  CUtlSymbolTable *m_pMemory; // eax

  CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004073E0
// Name: public: int CUtlVector<char,class CUtlMemory<char,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
        CUtlVector<bool,CUtlMemory<bool,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  bool *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<bool,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00408990
// Name: public: void CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::EnsureCapacity(
        CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *this,
        int num)
{
  CVTFTexture::ResourceMemorySection *m_pMemory; // edx
  unsigned int v4; // eax
  CVTFTexture::ResourceMemorySection *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 12 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (CVTFTexture::ResourceMemorySection *)_g_pMemAlloc->Realloc_2(
                                                                         this: _g_pMemAlloc,
                                                                         a2: m_pMemory,
                                                                         a3: v4);
      goto LABEL_5;
    }
    v5 = (CVTFTexture::ResourceMemorySection *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040BB00
// Name: public: int CUtlVector<struct InputEvent_t,class CUtlMemory<struct InputEvent_t,int>>::InsertBefore(int,struct InputEvent_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<InputEvent_t,CUtlMemory<InputEvent_t,int>>::InsertBefore(
        CUtlVector<InputEvent_t,CUtlMemory<InputEvent_t,int> > *this,
        int elem,
        const InputEvent_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  InputEvent_t *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  InputEvent_t *v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
      (CUtlMemory<BitmapFontTable_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: (void *)&m_pMemory[elem + 1], src: &m_pMemory[elem], count: 20 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0040E650
// Name: public: void CUtlMemory<class ImageAliasData_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<ImageAliasData_t,int>::Grow(CUtlMemory<ScriptFunctionBinding_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  ScriptFunctionBinding_t *m_pMemory; // edx
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
    v7 = 48 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (ScriptFunctionBinding_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (ScriptFunctionBinding_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E810
// Name: public: int CUtlVector<class ImageAliasData_t,class CUtlMemory<class ImageAliasData_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ImageAliasData_t,CUtlMemory<ImageAliasData_t,int>>::InsertMultipleBefore(
        CUtlVector<ImageAliasData_t,CUtlMemory<ImageAliasData_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ImageAliasData_t *m_pMemory; // ecx
  int v9; // ebp
  int v10; // eax
  int v11; // ebp
  ImageAliasData_t *v12; // ebx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ImageAliasData_t,int>::Grow(
      (CUtlMemory<ScriptFunctionBinding_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = elem;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[num + elem], src: &m_pMemory[elem], count: 48 * v10);
LABEL_8:
    if ( num > 0 )
    {
      v11 = elem;
      do
      {
        v12 = &this->m_Memory.m_pMemory[v11];
        if ( v12 != nullptr )
        {
          CUtlString::CUtlString(this: &v12->m_szBaseTextureName);
          CMaterialReference::CMaterialReference(
            this: &v12->m_Material,
            pMaterialName: nullptr,
            pTextureGroupName: nullptr,
            bComplain: true);
          ImageAliasData_t::Init(this: v12);
        }
        ++v11;
        --v3;
      }
      while ( v3 != 0 );
      return elem;
    }
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x0040E8D0
// Name: public: void CUtlVector<class ImageAliasData_t,class CUtlMemory<class ImageAliasData_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<ImageAliasData_t,CUtlMemory<ImageAliasData_t,int>>::RemoveAll(
        CUtlVector<ImageAliasData_t,CUtlMemory<ImageAliasData_t,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  ImageAliasData_t *v3; // esi
  bool v4; // sf
  CUtlVector<ImageAliasData_t,CUtlMemory<ImageAliasData_t,int> > *v5; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      CMaterialReference::~CMaterialReference(this: &v3->m_Material);
      v4 = v3->m_szBaseTextureName.m_Storage.m_Memory.m_nGrowSize < 0;
      v3->m_szBaseTextureName.m_Storage.m_nActualLength = 0;
      if ( !v4 )
      {
        if ( v3->m_szBaseTextureName.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_szBaseTextureName.m_Storage.m_Memory.m_pMemory);
          v3->m_szBaseTextureName.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_szBaseTextureName.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      this = v5;
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    v5->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E950
// Name: public: CUtlVector<class ImageAliasData_t,class CUtlMemory<class ImageAliasData_t,int>>::~CUtlVector<class ImageAliasData_t,class CUtlMemory<class ImageAliasData_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<ImageAliasData_t,CUtlMemory<ImageAliasData_t,int>>::~CUtlVector<ImageAliasData_t,CUtlMemory<ImageAliasData_t,int>>(
        CUtlVector<ImageAliasData_t,CUtlMemory<ImageAliasData_t,int> > *this)
{
  bool v2; // sf
  ImageAliasData_t *m_pMemory; // eax

  CUtlVector<ImageAliasData_t,CUtlMemory<ImageAliasData_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410B10
// Name: public: int CUtlVector<class CUtlSymbol,class CUtlMemory<class CUtlSymbol,int>>::InsertBefore(int,class CUtlSymbol const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>>::InsertBefore(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int elem,
        wchar_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  wchar_t *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  wchar_t *v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<wchar_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 2 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004128E0
// Name: public: int CUtlVector<struct CGameUIScheme::fontrange_t,class CUtlMemory<struct CGameUIScheme::fontrange_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CGameUIScheme::fontrange_t,CUtlMemory<CGameUIScheme::fontrange_t,int>>::InsertBefore(
        CUtlVector<CGameUIScheme::fontrange_t,CUtlMemory<CGameUIScheme::fontrange_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CGameUIScheme::fontrange_t *m_pMemory; // ecx
  int v6; // eax
  bool v7; // zf
  CGameUIScheme::fontrange_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  v7 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 >= 0 && !v7 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v6);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    v8->_fontName.m_Id = -1;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00414690
// Name: protected: unsigned int CUtlLinkedList<struct CInputGameUI::InputContext_t,unsigned int,0,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<struct CInputGameUI::InputContext_t,unsigned int>,unsigned int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
signed int __thiscall CUtlLinkedList<CInputGameUI::InputContext_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int>,unsigned int>>::AllocInternal(
        CUtlLinkedList<CInputGameUI::InputContext_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int>,unsigned int> > *this,
        bool multilist)
{
  unsigned int m_FirstFree; // ecx
  signed int index; // eax
  int m_nAllocationCount; // ecx
  signed int result; // eax
  signed int v7; // eax
  int v8; // ecx
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree != -1 )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_23:
    v9 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int>,unsigned int>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_LastAlloc.index;
    if ( v7 < 0 || (v8 = this->m_Memory.m_nAllocationCount, v7 >= v8) )
    {
      v8 = this->m_Memory.m_nAllocationCount;
      result = (v8 > 0) - 1;
    }
    else
    {
      result = v7 + 1;
      if ( result < 0 || result >= v8 )
        result = -1;
    }
    if ( result < 0 || result >= v8 )
    {
      if ( _executeCount_2 < 10 )
      {
        ++_executeCount_2;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x00414F60
// Name: public: int CUtlVector<class vgui::ClickPanel __near *,class CUtlMemory<class vgui::ClickPanel __near *,int>>::InsertBefore(int,class vgui::ClickPanel __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
        CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *this,
        int elem,
        vgui::TreeNode **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::TreeNode **m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  vgui::TreeNode **v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00414FD0
// Name: public: void CUtlLinkedList<struct CInputGameUI::InputContext_t,unsigned int,0,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<struct CInputGameUI::InputContext_t,unsigned int>,unsigned int>>::Unlink(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CInputGameUI::InputContext_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int>,unsigned int>>::Unlink(
        CUtlLinkedList<CInputGameUI::InputContext_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int>,unsigned int> > *this,
        int elem)
{
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *v2; // eax
  unsigned int m_Next; // edx
  unsigned int m_Previous; // ebx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      --this->m_ElementCount;
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004162B0
// Name: public: void CUtlLinkedList<struct CInputGameUI::InputContext_t,unsigned int,0,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<struct CInputGameUI::InputContext_t,unsigned int>,unsigned int>>::LinkBefore(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CInputGameUI::InputContext_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int>,unsigned int>>::LinkBefore(
        CUtlLinkedList<CInputGameUI::InputContext_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int>,unsigned int> > *this,
        unsigned int before,
        unsigned int elem)
{
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *m_pMemory; // ebx
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *v5; // eax
  unsigned int m_Tail; // edx

  CUtlLinkedList<CInputGameUI::InputContext_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int>,unsigned int>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == -1 )
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    m_Tail = m_pMemory[before].m_Previous;
    m_pMemory[before].m_Previous = elem;
  }
  v5->m_Previous = m_Tail;
  if ( m_Tail == -1 )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416A00
// Name: public: unsigned int CUtlLinkedList<struct CInputGameUI::InputContext_t,unsigned int,0,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<struct CInputGameUI::InputContext_t,unsigned int>,unsigned int>>::InsertBefore(unsigned int)
// Source: json
//------------------------------------------------------------------------------
signed int __thiscall CUtlLinkedList<CInputGameUI::InputContext_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int>,unsigned int>>::InsertBefore(
        CUtlLinkedList<CInputGameUI::InputContext_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int>,unsigned int> > *this,
        unsigned int before)
{
  signed int result; // eax
  unsigned int v4; // edi
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *v5; // eax

  result = CUtlLinkedList<CInputGameUI::InputContext_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int>,unsigned int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<CInputGameUI::InputContext_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int>,unsigned int>>::LinkBefore(
      this,
      before,
      elem: result);
    v5 = &this->m_Memory.m_pMemory[v4];
    if ( v5 != nullptr )
    {
      v5->m_Element.m_KeyCodeUnhandledListeners.m_Memory.m_pMemory = nullptr;
      v5->m_Element.m_KeyCodeUnhandledListeners.m_Memory.m_nAllocationCount = 0;
      v5->m_Element.m_KeyCodeUnhandledListeners.m_Memory.m_nGrowSize = 0;
      v5->m_Element.m_KeyCodeUnhandledListeners.m_Size = 0;
      v5->m_Element.m_KeyCodeUnhandledListeners.m_pElements = nullptr;
      CKeyRepeatHandler::CKeyRepeatHandler(this: &v5->m_Element.m_keyRepeater);
    }
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00416A70
// Name: public: void CUtlLinkedList<struct CInputGameUI::InputContext_t,unsigned int,0,unsigned int,class CUtlMemory<struct UtlLinkedListElem_t<struct CInputGameUI::InputContext_t,unsigned int>,unsigned int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CInputGameUI::InputContext_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int>,unsigned int>>::RemoveAll(
        CUtlLinkedList<CInputGameUI::InputContext_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int>,unsigned int> > *this)
{
  unsigned int m_Head; // ebx
  unsigned int m_Next; // edi
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *v4; // esi
  unsigned int m_FirstFree; // eax
  unsigned int v6; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        m_Next = this->m_Memory.m_pMemory[m_Head].m_Next;
        v4 = &this->m_Memory.m_pMemory[m_Head];
        CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v4->m_Element.m_KeyCodeUnhandledListeners);
        v4->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v4->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v6 = this->m_Head;
    if ( v6 != -1 )
      this->m_FirstFree = v6;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417580
// Name: public: void CUtlMemory<class CRenderGeometry,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CRenderGeometry,int>::Grow(CUtlMemory<CRenderGeometry,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CRenderGeometry *m_pMemory; // edx
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
    v7 = 100 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CRenderGeometry *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CRenderGeometry *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417940
// Name: public: int CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::InsertBefore(int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *this,
        int elem,
        const Vector2D *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector2D *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  Vector2D *v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlHandleTable<CDmAttribute,21>::EntryType_t,int>::Grow(
      (CUtlMemory<ResourceEntryInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004179B0
// Name: public: int CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::InsertBefore(int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
        CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *this,
        int elem,
        const CVTFTexture::ResourceMemorySection *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CVTFTexture::ResourceMemorySection *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  CVTFTexture::ResourceMemorySection *v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00417D40
// Name: public: int CUtlVector<class CRenderGeometry,class CUtlMemory<class CRenderGeometry,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int>>::InsertBefore(
        CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CRenderGeometry *m_pMemory; // ecx
  int v6; // eax
  bool v7; // zf

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CRenderGeometry,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  v7 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 >= 0 && !v7 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 100 * v6);
  Construct<CRenderGeometry>(pMemory: &this->m_Memory.m_pMemory[elem]);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00419420
// Name: public: CUtlVector<class CDmxElement __near *,class CUtlMemory<class CDmxElement __near *,int>>::CUtlVector<class CDmxElement __near *,class CUtlMemory<class CDmxElement __near *,int>>(int,int)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *__thiscall CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int>>::CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int>>(
        CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *this,
        int growSize,
        int initSize)
{
  CDmxElement **m_pMemory; // ecx

  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = initSize;
  this->m_Memory.m_nGrowSize = growSize;
  if ( initSize != 0 )
    this->m_Memory.m_pMemory = (CDmxElement **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * initSize);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size = 0;
  this->m_pElements = m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0041A110
// Name: public: class CUtlVector<class CDmxElement __near *,class CUtlMemory<class CDmxElement __near *,int>> const __near & CDmxAttribute::GetArray<class CDmxElement __near *>(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *__thiscall CDmxAttribute::GetArray<CDmxElement *>(
        CDmxAttribute *this)
{
  if ( this->m_Type == AT_FIRST_ARRAY_TYPE )
    return (const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *)this->m_pData;
  if ( (`CDmxAttribute::GetArray<CDmxElement *>'::`4'::`local static guard' & 1) == 0 )
  {
    `CDmxAttribute::GetArray<CDmxElement *>'::`4'::`local static guard' |= 1u;
    `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_pMemory = nullptr;
    `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_nAllocationCount = 0;
    `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Memory.m_nGrowSize = 0;
    `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_Size = 0;
    `CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray.m_pElements = nullptr;
    atexit(func: `CDmxAttribute::GetArray<CDmxElement *>'::`4'::`dynamic atexit destructor for 'defaultArray'');
  }
  return &`CDmxAttribute::GetArray<CDmxElement *>'::`4'::defaultArray;
}

//------------------------------------------------------------------------------
// Address: 0x0041A3E0
// Name: public: class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> const __near & CDmxAttribute::GetArray<class CUtlString>(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *__thiscall CDmxAttribute::GetArray<CUtlString>(
        CDmxAttribute *this)
{
  if ( this->m_Type == AT_STRING_ARRAY )
    return (const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData;
  if ( (`CDmxAttribute::GetArray<CUtlString>'::`4'::`local static guard' & 1) == 0 )
  {
    `CDmxAttribute::GetArray<CUtlString>'::`4'::`local static guard' |= 1u;
    `CDmxAttribute::GetArray<CUtlString>'::`4'::defaultArray.m_Memory.m_pMemory = nullptr;
    `CDmxAttribute::GetArray<CUtlString>'::`4'::defaultArray.m_Memory.m_nAllocationCount = 0;
    `CDmxAttribute::GetArray<CUtlString>'::`4'::defaultArray.m_Memory.m_nGrowSize = 0;
    `CDmxAttribute::GetArray<CUtlString>'::`4'::defaultArray.m_Size = 0;
    `CDmxAttribute::GetArray<CUtlString>'::`4'::defaultArray.m_pElements = nullptr;
    atexit(func: `CDmxAttribute::GetArray<CUtlString>'::`4'::`dynamic atexit destructor for 'defaultArray'');
  }
  return &`CDmxAttribute::GetArray<CUtlString>'::`4'::defaultArray;
}

//------------------------------------------------------------------------------
// Address: 0x0041B3E0
// Name: public: int CUtlVector<class CUtlVector<class CRenderGeometry,class CUtlMemory<class CRenderGeometry,int>>,class CUtlMemory<class CUtlVector<class CRenderGeometry,class CUtlMemory<class CRenderGeometry,int>>,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int>>,CUtlMemory<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int>>,int>>::InsertBefore(
        CUtlVector<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> >,CUtlMemory<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> >,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> > *m_pMemory; // ecx
  int v6; // eax
  bool v7; // zf
  CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> > *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
      (CUtlMemory<BitmapFontTable_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  v7 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 >= 0 && !v7 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 20 * v6);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
  {
    v8->m_Memory.m_pMemory = nullptr;
    v8->m_Memory.m_nAllocationCount = 0;
    v8->m_Memory.m_nGrowSize = 0;
    v8->m_Size = 0;
    v8->m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0041FA10
// Name: public: void CUtlVector<class CRenderGeometry,class CUtlMemory<class CRenderGeometry,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int>>::RemoveAll(
        CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> > *this)
{
  int v1; // ebx
  int v2; // ebp
  CRenderGeometry *v3; // esi
  bool v4; // sf
  CTriangle *m_pMemory; // eax
  color32_s *v6; // eax
  Vector2D *v7; // eax
  Vector2D *v8; // eax
  CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> > *v9; // [esp+20h] [ebp-4h]

  v1 = this->m_Size - 1;
  v9 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v4 = v3->m_Triangles.m_Memory.m_nGrowSize < 0;
      v3->m_Triangles.m_Size = 0;
      if ( !v4 )
      {
        if ( v3->m_Triangles.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Triangles.m_Memory.m_pMemory);
          v3->m_Triangles.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Triangles.m_Memory.m_nAllocationCount = 0;
      }
      v4 = v3->m_Triangles.m_Memory.m_nGrowSize < 0;
      m_pMemory = v3->m_Triangles.m_Memory.m_pMemory;
      v3->m_Triangles.m_pElements = m_pMemory;
      if ( !v4 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_Triangles.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Triangles.m_Memory.m_nAllocationCount = 0;
      }
      v4 = v3->m_VertexColors.m_Memory.m_nGrowSize < 0;
      v3->m_VertexColors.m_Size = 0;
      if ( !v4 )
      {
        if ( v3->m_VertexColors.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_VertexColors.m_Memory.m_pMemory);
          v3->m_VertexColors.m_Memory.m_pMemory = nullptr;
        }
        v3->m_VertexColors.m_Memory.m_nAllocationCount = 0;
      }
      v4 = v3->m_VertexColors.m_Memory.m_nGrowSize < 0;
      v6 = v3->m_VertexColors.m_Memory.m_pMemory;
      v3->m_VertexColors.m_pElements = v6;
      if ( !v4 )
      {
        if ( v6 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
          v3->m_VertexColors.m_Memory.m_pMemory = nullptr;
        }
        v3->m_VertexColors.m_Memory.m_nAllocationCount = 0;
      }
      v4 = v3->m_TextureCoords.m_Memory.m_nGrowSize < 0;
      v3->m_TextureCoords.m_Size = 0;
      if ( !v4 )
      {
        if ( v3->m_TextureCoords.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_TextureCoords.m_Memory.m_pMemory);
          v3->m_TextureCoords.m_Memory.m_pMemory = nullptr;
        }
        v3->m_TextureCoords.m_Memory.m_nAllocationCount = 0;
      }
      v4 = v3->m_TextureCoords.m_Memory.m_nGrowSize < 0;
      v7 = v3->m_TextureCoords.m_Memory.m_pMemory;
      v3->m_TextureCoords.m_pElements = v7;
      if ( !v4 )
      {
        if ( v7 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
          v3->m_TextureCoords.m_Memory.m_pMemory = nullptr;
        }
        v3->m_TextureCoords.m_Memory.m_nAllocationCount = 0;
      }
      v4 = v3->m_Positions.m_Memory.m_nGrowSize < 0;
      v3->m_Positions.m_Size = 0;
      if ( !v4 )
      {
        if ( v3->m_Positions.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Positions.m_Memory.m_pMemory);
          v3->m_Positions.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Positions.m_Memory.m_nAllocationCount = 0;
      }
      v4 = v3->m_Positions.m_Memory.m_nGrowSize < 0;
      v8 = v3->m_Positions.m_Memory.m_pMemory;
      v3->m_Positions.m_pElements = v3->m_Positions.m_Memory.m_pMemory;
      if ( !v4 )
      {
        if ( v8 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
          v3->m_Positions.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Positions.m_Memory.m_nAllocationCount = 0;
      }
      this = v9;
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    v9->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041FC10
// Name: public: void CUtlVector<class CUtlVector<class CRenderGeometry,class CUtlMemory<class CRenderGeometry,int>>,class CUtlMemory<class CUtlVector<class CRenderGeometry,class CUtlMemory<class CRenderGeometry,int>>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int>>,CUtlMemory<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int>>,int>>::RemoveAll(
        CUtlVector<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> >,CUtlMemory<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> >,int> > *this)
{
  int v1; // edi
  int v2; // ebp
  CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> > *v3; // esi
  bool v4; // sf
  CRenderGeometry *m_pMemory; // eax
  CUtlVector<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> >,CUtlMemory<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> >,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int>>::RemoveAll(this: v3);
      if ( v3->m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      v4 = v3->m_Memory.m_nGrowSize < 0;
      m_pMemory = v3->m_Memory.m_pMemory;
      v3->m_pElements = v3->m_Memory.m_pMemory;
      if ( !v4 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      this = v6;
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    v6->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041FCA0
// Name: public: void CUtlVector<struct LayerRenderLists_t,class CUtlMemory<struct LayerRenderLists_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<LayerRenderLists_t,CUtlMemory<LayerRenderLists_t,int>>::RemoveAll(
        CUtlVector<LayerRenderLists_t,CUtlMemory<LayerRenderLists_t,int> > *this)
{
  int v1; // ebx
  int v2; // ebp
  const ResourceBinding_t<CTextureBits> *m_pBinding; // eax
  LayerRenderLists_t *v4; // esi
  bool v5; // sf
  CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> > *m_pMemory; // eax
  CUtlVector<LayerRenderLists_t,CUtlMemory<LayerRenderLists_t,int> > *v7; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v7 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      m_pBinding = this->m_Memory.m_pMemory[v2].m_hTexture.m_pBinding;
      v4 = &this->m_Memory.m_pMemory[v2];
      if ( m_pBinding != nullptr )
      {
        _InterlockedExchangeAdd(&m_pBinding->m_nRefCount.m_value, 0xFFFFFFFF);
        v4->m_hTexture.m_pBinding = nullptr;
      }
      CUtlVector<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int>>,CUtlMemory<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int>>,int>>::RemoveAll(this: &v4->m_RenderGeometryLists);
      if ( v4->m_RenderGeometryLists.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v4->m_RenderGeometryLists.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4->m_RenderGeometryLists.m_Memory.m_pMemory);
          v4->m_RenderGeometryLists.m_Memory.m_pMemory = nullptr;
        }
        v4->m_RenderGeometryLists.m_Memory.m_nAllocationCount = 0;
      }
      v5 = v4->m_RenderGeometryLists.m_Memory.m_nGrowSize < 0;
      m_pMemory = v4->m_RenderGeometryLists.m_Memory.m_pMemory;
      v4->m_RenderGeometryLists.m_pElements = v4->m_RenderGeometryLists.m_Memory.m_pMemory;
      if ( !v5 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v4->m_RenderGeometryLists.m_Memory.m_pMemory = nullptr;
        }
        v4->m_RenderGeometryLists.m_Memory.m_nAllocationCount = 0;
      }
      this = v7;
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    v7->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421C90
// Name: public: class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>> const __near & CDmxAttribute::GetArray<class Vector2D>(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *__thiscall CDmxAttribute::GetArray<Vector2D>(CDmxAttribute *this)
{
  if ( this->m_Type == AT_VECTOR2_ARRAY )
    return (const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)this->m_pData;
  if ( (`CDmxAttribute::GetArray<Vector2D>'::`4'::`local static guard' & 1) == 0 )
  {
    `CDmxAttribute::GetArray<Vector2D>'::`4'::`local static guard' |= 1u;
    `CDmxAttribute::GetArray<Vector2D>'::`4'::defaultArray.m_Memory.m_pMemory = nullptr;
    `CDmxAttribute::GetArray<Vector2D>'::`4'::defaultArray.m_Memory.m_nAllocationCount = 0;
    `CDmxAttribute::GetArray<Vector2D>'::`4'::defaultArray.m_Memory.m_nGrowSize = 0;
    `CDmxAttribute::GetArray<Vector2D>'::`4'::defaultArray.m_Size = 0;
    `CDmxAttribute::GetArray<Vector2D>'::`4'::defaultArray.m_pElements = nullptr;
    atexit(func: `CDmxAttribute::GetArray<Vector2D>'::`4'::`dynamic atexit destructor for 'defaultArray'');
  }
  return &`CDmxAttribute::GetArray<Vector2D>'::`4'::defaultArray;
}

//------------------------------------------------------------------------------
// Address: 0x00422A30
// Name: private: class CSheet __near * CTGARenderer::LoadSheet(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
CSheet *__thiscall CTGARenderer::LoadSheet(CGameLayer *this, IMaterial *pMaterial)
{
  IMaterial *v3; // ecx
  IMaterialVar *(__thiscall *FindVar)(IMaterial *, const char *, bool *, bool); // eax
  int v6; // eax
  int (__thiscall ***v7)(_DWORD); // esi
  int v8; // eax
  ITexture *v9; // esi
  const char *v10; // eax

  v3 = pMaterial;
  if ( pMaterial == nullptr )
    return nullptr;
  FindVar = pMaterial->FindVar;
  LOBYTE(pMaterial) = 0;
  v6 = (int)FindVar(this: v3, a2: "$basetexture", a3: (bool *)&pMaterial, a4: true);
  v7 = (int (__thiscall ***)(_DWORD))v6;
  if ( (_BYTE)pMaterial == 0 )
    return nullptr;
  if ( v6 == 0 )
    return nullptr;
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 68))(a1: v6) == 0 )
    return nullptr;
  v8 = (**v7)(a1: v7);
  v9 = (ITexture *)v8;
  if ( v8 == 0 || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v8 + 60))(a1: v8) != 0 )
    return nullptr;
  v10 = (const char *)v9->GetName(this: v9);
  return CGameLayer::LoadSheet(this, pszFname: v10, pTexture: v9);
}

//------------------------------------------------------------------------------
// Address: 0x004232F0
// Name: public: int CUtlVector<struct LayerRenderLists_t,class CUtlMemory<struct LayerRenderLists_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<LayerRenderLists_t,CUtlMemory<LayerRenderLists_t,int>>::InsertBefore(
        CUtlVector<LayerRenderLists_t,CUtlMemory<LayerRenderLists_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  LayerRenderLists_t *m_pMemory; // ecx
  int v6; // eax
  bool v7; // zf
  LayerRenderLists_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<LayerRenderLists_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  v7 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 >= 0 && !v7 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 36 * v6);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
  {
    v8->m_RenderGeometryLists.m_Memory.m_pMemory = nullptr;
    v8->m_RenderGeometryLists.m_Memory.m_nAllocationCount = 0;
    v8->m_RenderGeometryLists.m_Memory.m_nGrowSize = 0;
    v8->m_RenderGeometryLists.m_Size = 0;
    v8->m_RenderGeometryLists.m_pElements = nullptr;
    v8->m_hTexture.m_pBinding = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00426F30
// Name: public: int CUtlVector<float,class CUtlMemory<float,int>>::InsertBefore(int,float const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<float,CUtlMemory<float,int>>::InsertBefore(
        CUtlVector<float,CUtlMemory<float,int> > *this,
        int elem,
        float *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  float *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  float *v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00426FF0
// Name: public: class CUtlVector<class Color,class CUtlMemory<class Color,int>> const __near & CDmxAttribute::GetArray<class Color>(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<Color,CUtlMemory<Color,int> > *__thiscall CDmxAttribute::GetArray<Color>(CDmxAttribute *this)
{
  if ( this->m_Type == AT_COLOR_ARRAY )
    return (const CUtlVector<Color,CUtlMemory<Color,int> > *)this->m_pData;
  if ( (`CDmxAttribute::GetArray<Color>'::`4'::`local static guard' & 1) == 0 )
  {
    `CDmxAttribute::GetArray<Color>'::`4'::`local static guard' |= 1u;
    `CDmxAttribute::GetArray<Color>'::`4'::defaultArray.m_Memory.m_pMemory = nullptr;
    `CDmxAttribute::GetArray<Color>'::`4'::defaultArray.m_Memory.m_nAllocationCount = 0;
    `CDmxAttribute::GetArray<Color>'::`4'::defaultArray.m_Memory.m_nGrowSize = 0;
    `CDmxAttribute::GetArray<Color>'::`4'::defaultArray.m_Size = 0;
    `CDmxAttribute::GetArray<Color>'::`4'::defaultArray.m_pElements = nullptr;
    atexit(func: `CDmxAttribute::GetArray<Color>'::`4'::`dynamic atexit destructor for 'defaultArray'');
  }
  return &`CDmxAttribute::GetArray<Color>'::`4'::defaultArray;
}

//------------------------------------------------------------------------------
// Address: 0x00427040
// Name: public: class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>> const __near & CDmxAttribute::GetArray<class DmeTime_t>(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *__thiscall CDmxAttribute::GetArray<DmeTime_t>(
        CDmxAttribute *this)
{
  if ( this->m_Type == AT_TIME_ARRAY )
    return (const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)this->m_pData;
  if ( (`CDmxAttribute::GetArray<DmeTime_t>'::`4'::`local static guard' & 1) == 0 )
  {
    `CDmxAttribute::GetArray<DmeTime_t>'::`4'::`local static guard' |= 1u;
    `CDmxAttribute::GetArray<DmeTime_t>'::`4'::defaultArray.m_Memory.m_pMemory = nullptr;
    `CDmxAttribute::GetArray<DmeTime_t>'::`4'::defaultArray.m_Memory.m_nAllocationCount = 0;
    `CDmxAttribute::GetArray<DmeTime_t>'::`4'::defaultArray.m_Memory.m_nGrowSize = 0;
    `CDmxAttribute::GetArray<DmeTime_t>'::`4'::defaultArray.m_Size = 0;
    `CDmxAttribute::GetArray<DmeTime_t>'::`4'::defaultArray.m_pElements = nullptr;
    atexit(func: `CDmxAttribute::GetArray<DmeTime_t>'::`4'::`dynamic atexit destructor for 'defaultArray'');
  }
  return &`CDmxAttribute::GetArray<DmeTime_t>'::`4'::defaultArray;
}

//------------------------------------------------------------------------------
// Address: 0x004270F0
// Name: public: class CUtlVector<float,class CUtlMemory<float,int>> const __near & CDmxAttribute::GetArray<float>(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<float,CUtlMemory<float,int> > *__thiscall CDmxAttribute::GetArray<float>(CDmxAttribute *this)
{
  if ( this->m_Type == AT_FLOAT_ARRAY )
    return (const CUtlVector<float,CUtlMemory<float,int> > *)this->m_pData;
  if ( (`CDmxAttribute::GetArray<float>'::`4'::`local static guard' & 1) == 0 )
  {
    `CDmxAttribute::GetArray<float>'::`4'::`local static guard' |= 1u;
    `CDmxAttribute::GetArray<float>'::`4'::defaultArray.m_Memory.m_pMemory = nullptr;
    `CDmxAttribute::GetArray<float>'::`4'::defaultArray.m_Memory.m_nAllocationCount = 0;
    `CDmxAttribute::GetArray<float>'::`4'::defaultArray.m_Memory.m_nGrowSize = 0;
    `CDmxAttribute::GetArray<float>'::`4'::defaultArray.m_Size = 0;
    `CDmxAttribute::GetArray<float>'::`4'::defaultArray.m_pElements = nullptr;
    atexit(func: `CDmxAttribute::GetArray<float>'::`4'::`dynamic atexit destructor for 'defaultArray'');
  }
  return &`CDmxAttribute::GetArray<float>'::`4'::defaultArray;
}

//------------------------------------------------------------------------------
// Address: 0x00429450
// Name: public: void CUtlVector<float,class CUtlMemory<float,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(
        CUtlVector<CWin32Font *,CUtlMemory<CWin32Font *,int> > *this,
        int num)
{
  CWin32Font **m_pMemory; // edx
  unsigned int v4; // eax
  CWin32Font **v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 4 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (CWin32Font **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (CWin32Font **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B8D0
// Name: public: int CUtlVector<struct ScriptFunctionBinding_t,class CUtlMemory<struct ScriptFunctionBinding_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::InsertBefore(
        CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ScriptFunctionBinding_t *m_pMemory; // ecx
  int v6; // eax
  bool v7; // zf
  ScriptFunctionBinding_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ImageAliasData_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  v7 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 >= 0 && !v7 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 48 * v6);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
  {
    v8->m_desc.m_Parameters.m_Memory.m_pMemory = nullptr;
    v8->m_desc.m_Parameters.m_Memory.m_nAllocationCount = 0;
    v8->m_desc.m_Parameters.m_Memory.m_nGrowSize = 0;
    v8->m_desc.m_Parameters.m_Size = 0;
    v8->m_desc.m_Parameters.m_pElements = nullptr;
    v8->m_desc.m_pszFunction = nullptr;
    v8->m_desc.m_ReturnType = 31;
    v8->m_desc.m_pszDescription = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0042B960
// Name: public: void CUtlVector<struct ScriptFunctionBinding_t,class CUtlMemory<struct ScriptFunctionBinding_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::RemoveAll(
        CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int> > *this)
{
  int v1; // ebx
  int v2; // ebp
  bool v3; // sf
  CUtlVector<int,CUtlMemory<int,int> > *p_m_Parameters; // esi
  int *m_pMemory; // eax
  CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = this->m_Memory.m_pMemory[v2].m_desc.m_Parameters.m_Memory.m_nGrowSize < 0;
      p_m_Parameters = &this->m_Memory.m_pMemory[v2].m_desc.m_Parameters;
      this->m_Memory.m_pMemory[v2].m_desc.m_Parameters.m_Size = 0;
      if ( !v3 )
      {
        if ( p_m_Parameters->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_Parameters->m_Memory.m_pMemory);
          this = v6;
          p_m_Parameters->m_Memory.m_pMemory = nullptr;
        }
        p_m_Parameters->m_Memory.m_nAllocationCount = 0;
      }
      v3 = p_m_Parameters->m_Memory.m_nGrowSize < 0;
      m_pMemory = p_m_Parameters->m_Memory.m_pMemory;
      p_m_Parameters->m_pElements = p_m_Parameters->m_Memory.m_pMemory;
      if ( !v3 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          this = v6;
          p_m_Parameters->m_Memory.m_pMemory = nullptr;
        }
        p_m_Parameters->m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042C300
// Name: public: CUtlVector<struct ScriptFunctionBinding_t,class CUtlMemory<struct ScriptFunctionBinding_t,int>>::~CUtlVector<struct ScriptFunctionBinding_t,class CUtlMemory<struct ScriptFunctionBinding_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::~CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>(
        CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int> > *this)
{
  bool v2; // sf
  ScriptFunctionBinding_t *m_pMemory; // eax

  CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046AFD0
// Name: public: int CUtlVector<struct vgui::OverridableColorEntry,class CUtlMemory<struct vgui::OverridableColorEntry,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
        CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::OverridableColorEntry *m_pMemory; // ecx
  int v6; // eax
  bool v7; // zf
  vgui::OverridableColorEntry *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  v7 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 >= 0 && !v7 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v6);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    v8->m_colFromScript = 0;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00478A40
// Name: public: int CUtlVector<struct vgui::BoundKey_t,class CUtlMemory<struct vgui::BoundKey_t,int>>::InsertBefore(int,struct vgui::BoundKey_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertBefore(
        CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int> > *this,
        int elem,
        const vgui::BoundKey_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::BoundKey_t *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  vgui::BoundKey_t *v9; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    vgui::BoundKey_t::BoundKey_t(this: v9, src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00478AB0
// Name: public: int CUtlVector<struct PanelAnimationMapEntry,class CUtlMemory<struct PanelAnimationMapEntry,int>>::InsertBefore(int,struct PanelAnimationMapEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
        CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int> > *this,
        int elem,
        const PanelAnimationMapEntry *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  PanelAnimationMapEntry *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  PanelAnimationMapEntry *v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00483E50
// Name: public: void CUtlLinkedList<struct vgui::GraphPanel::Sample_t,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::GraphPanel::Sample_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::GraphPanel::Sample_t,int>,int>>::RemoveAll(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this)
{
  int m_Head; // edx
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v2; // esi
  int m_Next; // eax
  int m_FirstFree; // edx
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004843D0
// Name: public: void CUtlVector<float,class CUtlMemory<float,int>>::CopyArray(float const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<float,CUtlMemory<float,int>>::CopyArray(
        CUtlVector<float,CUtlMemory<float,int> > *this,
        const float *pArray,
        int size)
{
  int v3; // ebp
  int v4; // edi
  const float *v6; // ecx
  const float *v7; // eax
  int v8; // edx
  unsigned int v9; // ecx
  int v10; // ebx
  char *v11; // edx
  double v12; // st7
  char *v13; // edx

  v3 = size;
  v4 = 0;
  this->m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)this,
    elem: 0,
    num: size);
  v6 = pArray;
  if ( size >= 4 )
  {
    v7 = pArray + 2;
    v8 = -8 - (_DWORD)pArray;
    v9 = ((unsigned int)(size - 4) >> 2) + 1;
    v10 = 2;
    v4 = 4 * v9;
    while ( 1 )
    {
      v11 = (char *)v7 + v8;
      *(float *)&v11[(unsigned int)this->m_Memory.m_pMemory] = *(v7 - 2);
      v10 += 4;
      *(float *)&v11[(unsigned int)this->m_Memory.m_pMemory + 4] = *(v7 - 1);
      this->m_Memory.m_pMemory[v10 - 4] = *v7;
      v12 = v7[1];
      v13 = (char *)v7 + 4 - (_DWORD)pArray;
      v7 += 4;
      *(float *)&v13[(unsigned int)this->m_Memory.m_pMemory] = v12;
      if ( --v9 == 0 )
        break;
      v8 = -8 - (_DWORD)pArray;
    }
    v3 = size;
    v6 = pArray;
  }
  for ( ; v4 < v3; ++v4 )
    this->m_Memory.m_pMemory[v4] = v6[v4];
}

//------------------------------------------------------------------------------
// Address: 0x00486DD0
// Name: public: int CUtlVector<class vgui::Panel __near *,class CUtlMemory<class vgui::Panel __near *,int>>::Find(class vgui::Panel __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::Panel *,CUtlMemory<vgui::Panel *,int>>::Find(
        CUtlVector<vgui::Panel *,CUtlMemory<vgui::Panel *,int> > *this,
        vgui::Panel **src)
{
  int m_Size; // edx
  int result; // eax
  vgui::Panel **i; // ecx

  m_Size = this->m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00486E00
// Name: public: bool CUtlVector<int,class CUtlMemory<int,int>>::HasElement(int const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlVector<int,CUtlMemory<int,int>>::HasElement(
        CUtlVector<int,CUtlMemory<int,int> > *this,
        const int *src)
{
  int m_Size; // edx
  int v3; // eax
  int *m_pMemory; // ecx

  m_Size = this->m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    m_pMemory = this->m_Memory.m_pMemory;
    while ( *m_pMemory != *src )
    {
      ++v3;
      ++m_pMemory;
      if ( v3 >= m_Size )
        goto LABEL_5;
    }
  }
  return v3 >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x00487080
// Name: protected: unsigned char CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        bool multilist)
{
  unsigned __int8 result; // al
  int index; // eax
  CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>::Iterator_t *p_m_LastAlloc; // ebp
  int m_nAllocationCount; // ecx
  int v7; // edi
  CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>::Iterator_t *v8; // eax
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v9; // ecx
  CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>::Iterator_t v10; // [esp+Fh] [ebp-1h] BYREF

  result = this->m_FirstFree;
  if ( result != 0xFF )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_20:
    v9 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  p_m_LastAlloc = &this->m_LastAlloc;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else if ( (unsigned __int8)(p_m_LastAlloc->index + 1) >= m_nAllocationCount )
  {
    result = -1;
  }
  else
  {
    result = p_m_LastAlloc->index + 1;
  }
  v10.index = result;
  if ( result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( p_m_LastAlloc->index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      v10.index = (v7 > 0) - 1;
      v8 = &v10;
    }
    else
    {
      v8 = CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>::Next(
             this: &this->m_Memory,
             result: &v10,
             it: &this->m_LastAlloc);
    }
    result = v8->index;
    if ( result >= v7 )
    {
      if ( _executeCount_4 < 10 )
      {
        ++_executeCount_4;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  if ( result != 0xFF )
  {
    ++this->m_NumAlloced;
    p_m_LastAlloc->index = result;
    goto LABEL_20;
  }
  if ( _executeCount_3 >= 10 )
    return -1;
  ++_executeCount_3;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004871E0
// Name: protected: int CUtlLinkedList<class vgui::FastSortListPanelItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::FastSortListPanelItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( _executeCount_6 < 10 )
      {
        ++_executeCount_6;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x00488B00
// Name: public: int CUtlVector<int,class CUtlMemory<int,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<int,CUtlMemory<int,int>>::InsertBefore(CUtlVector<int,CUtlMemory<int,int> > *this, int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int *m_pMemory; // ecx
  int v6; // eax
  int v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v7 = v6 - elem - 1;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00489550
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 elem)
{
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v2; // eax
  unsigned __int8 m_Next; // dl
  unsigned __int8 m_Previous; // bl

  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == 0xFF )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == 0xFF )
      {
        --this->m_ElementCount;
        this->m_Tail = m_Previous;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004895D0
// Name: public: void CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // edi

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        --this->m_ElementCount;
        this->m_Tail = m_Previous;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00489B50
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 before,
        unsigned __int8 elem)
{
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *m_pMemory; // edi
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // ecx
  unsigned __int8 m_Tail; // al

  CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFF )
  {
    m_Tail = this->m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    m_Tail = m_pMemory[before].m_Previous;
    m_pMemory[before].m_Previous = elem;
  }
  v5->m_Previous = m_Tail;
  if ( m_Tail == 0xFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048A750
// Name: public: int CUtlLinkedList<class vgui::FastSortListPanelItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::FastSortListPanelItem __near *,int>,int>>::AddToTail(class vgui::FastSortListPanelItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int> > *this,
        vgui::FastSortListPanelItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *v5; // eax
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int> *v7; // esi

  result = CUtlLinkedList<vgui::FastSortListPanelItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::FastSortListPanelItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: result);
    v5 = &this->m_Memory.m_pMemory[v4];
    v5->m_Next = -1;
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v7 = &this->m_Memory.m_pMemory[v4];
    if ( v7 != nullptr )
      v7->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048A7C0
// Name: public: unsigned char CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::InsertBefore(unsigned char)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::InsertBefore(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this,
        unsigned __int8 before)
{
  unsigned __int8 result; // al
  unsigned __int8 v4; // bl
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // eax

  result = CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != 0xFF )
  {
    CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::LinkBefore(
      this,
      before,
      elem: result);
    v5 = &this->m_Memory.m_pMemory[v4];
    if ( v5 != nullptr )
    {
      v5->m_Element.m_SortedTree.m_LessFunc = nullptr;
      v5->m_Element.m_SortedTree.m_Elements.m_pMemory = nullptr;
      v5->m_Element.m_SortedTree.m_Elements.m_nAllocationCount = 0;
      v5->m_Element.m_SortedTree.m_Elements.m_nGrowSize = 0;
      v5->m_Element.m_SortedTree.m_Root = -1;
      v5->m_Element.m_SortedTree.m_FirstFree = -1;
      v5->m_Element.m_SortedTree.m_NumElements = 0;
      v5->m_Element.m_SortedTree.m_LastAlloc.index = -1;
      v5->m_Element.m_SortedTree.m_pElements = v5->m_Element.m_SortedTree.m_Elements.m_pMemory;
    }
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048AB90
// Name: public: void CUtlLinkedList<struct vgui::ListPanel::column_t,unsigned char,0,unsigned char,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::ListPanel::column_t,unsigned char>,unsigned char>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char>>::RemoveAll(
        CUtlLinkedList<vgui::ListPanel::column_t,unsigned char,0,unsigned char,CUtlMemory<UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char>,unsigned char> > *this)
{
  unsigned __int8 m_Head; // al
  int v3; // eax
  unsigned __int8 m_Next; // bl
  UtlLinkedListElem_t<vgui::ListPanel::column_t,unsigned char> *v5; // esi
  unsigned __int8 v6; // al
  unsigned __int8 v7; // al
  unsigned __int8 v8; // [esp+7h] [ebp-1h]

  if ( this->m_LastAlloc.index != 0xFF )
  {
    m_Head = this->m_Head;
    v8 = m_Head;
    if ( m_Head != 0xFF )
    {
      while ( 1 )
      {
        v3 = m_Head;
        m_Next = this->m_Memory.m_pMemory[v3].m_Next;
        v5 = &this->m_Memory.m_pMemory[v3];
        CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>::~CUtlRBTree<vgui::ListPanel::IndexItem_t,int,bool (__cdecl *)(vgui::ListPanel::IndexItem_t const &,vgui::ListPanel::IndexItem_t const &),CUtlMemory<UtlRBTreeNode_t<vgui::ListPanel::IndexItem_t,int>,int>>(this: &v5->m_Element.m_SortedTree);
        v5->m_Previous = v8;
        v6 = m_Next == 0xFF ? this->m_FirstFree : m_Next;
        v5->m_Next = v6;
        v8 = m_Next;
        if ( m_Next == 0xFF )
          break;
        m_Head = m_Next;
      }
    }
    v7 = this->m_Head;
    if ( v7 != 0xFF )
      this->m_FirstFree = v7;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048BF10
// Name: protected: int CUtlLinkedList<class vgui::ListViewItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::ListViewItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( _executeCount_8 < 10 )
      {
        ++_executeCount_8;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x0048D690
// Name: public: int CUtlLinkedList<class vgui::ListViewItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::ListViewItem __near *,int>,int>>::AddToTail(class vgui::ListViewItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int> > *this,
        vgui::ListViewItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *v5; // eax
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::ListViewItem *,int> *v7; // esi

  result = CUtlLinkedList<vgui::ListViewItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::ListViewItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: result);
    v5 = &this->m_Memory.m_pMemory[v4];
    v5->m_Next = -1;
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v7 = &this->m_Memory.m_pMemory[v4];
    if ( v7 != nullptr )
      v7->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048ECF0
// Name: public: bool CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::IsValidIndex(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::IsValidIndex(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        int i)
{
  UtlLinkedListElem_t<vgui::MenuItem *,int> *m_pMemory; // ecx
  bool v4; // zf
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v5; // ecx

  if ( i < 0 || i >= this->m_Memory.m_nAllocationCount || i > this->m_LastAlloc.index )
    return false;
  m_pMemory = this->m_Memory.m_pMemory;
  v4 = m_pMemory[i].m_Previous == i;
  v5 = &m_pMemory[i];
  return !v4 || v5->m_Next == i;
}

//------------------------------------------------------------------------------
// Address: 0x0048F370
// Name: protected: int CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( _executeCount_10 < 10 )
      {
        ++_executeCount_10;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x004900C0
// Name: public: void CUtlLinkedList<class vgui::TreeNode __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::TreeNode __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v2; // esi
  int m_Next; // edx
  int m_FirstFree; // eax
  int v5; // eax

  if ( this->m_LastAlloc.index != -1 )
  {
    m_Head = this->m_Head;
    if ( m_Head != -1 )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == -1 )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != -1 );
    }
    v5 = this->m_Head;
    if ( v5 != -1 )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00491800
// Name: public: int CUtlLinkedList<class vgui::MenuItem __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::MenuItem __near *,int>,int>>::AddToTail(class vgui::MenuItem __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int> > *this,
        vgui::MenuItem **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v5; // eax
  int m_Tail; // edx
  UtlLinkedListElem_t<vgui::MenuItem *,int> *v7; // esi

  result = CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: result);
    v5 = &this->m_Memory.m_pMemory[v4];
    v5->m_Next = -1;
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v7 = &this->m_Memory.m_pMemory[v4];
    if ( v7 != nullptr )
      v7->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004971E0
// Name: public: void CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::RemoveMultiple(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::RemoveMultiple(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int elem,
        int num)
{
  if ( this->m_Size - elem - num > 0 && num > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[elem + num],
      count: 2 * (this->m_Size - elem - num));
  this->m_Size -= num;
}

//------------------------------------------------------------------------------
// Address: 0x00497C90
// Name: public: void CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::EnsureCapacity(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int num)
{
  wchar_t *m_pMemory; // edx
  unsigned int v4; // eax
  wchar_t *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 2 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (wchar_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (wchar_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00497F90
// Name: public: int CUtlVector<struct vgui::RichText::TFormatStream,class CUtlMemory<struct vgui::RichText::TFormatStream,int>>::InsertBefore(int,struct vgui::RichText::TFormatStream const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::RichText::TFormatStream,CUtlMemory<vgui::RichText::TFormatStream,int>>::InsertBefore(
        CUtlVector<vgui::RichText::TFormatStream,CUtlMemory<vgui::RichText::TFormatStream,int> > *this,
        int elem,
        const vgui::RichText::TFormatStream *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::RichText::TFormatStream *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  vgui::RichText::TFormatStream *v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDmElementDictionary::DmIdPair_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 32 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0049FFA0
// Name: public: int CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::InsertMultipleBefore(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  wchar_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<wchar_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 2 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004A1F50
// Name: public: void CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::CopyArray(wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::CopyArray(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        const wchar_t *pArray,
        int size)
{
  int i; // eax

  this->m_Size = 0;
  CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::InsertMultipleBefore(this, elem: 0, num: size);
  for ( i = 0; i < size; ++i )
    this->m_Memory.m_pMemory[i] = pArray[i];
}

//------------------------------------------------------------------------------
// Address: 0x004A40B0
// Name: public: void CUtlVector<class vgui::TreeNode __near *,class CUtlMemory<class vgui::TreeNode __near *,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int>>::Remove(
        CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *this,
        int elem)
{
  int v3; // eax

  v3 = this->m_Size - elem - 1;
  if ( v3 > 0 )
    _V_memmove(dest: &this->m_Memory.m_pMemory[elem], src: &this->m_Memory.m_pMemory[elem + 1], count: 4 * v3);
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004A40F0
// Name: protected: int CUtlLinkedList<class vgui::TreeNode __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::TreeNode __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( _executeCount_12 < 10 )
      {
        ++_executeCount_12;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x004A6F40
// Name: public: int CUtlLinkedList<class vgui::TreeNode __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class vgui::TreeNode __near *,int>,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *this)
{
  int result; // eax
  int v3; // edi
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v4; // ecx
  int m_Tail; // eax

  result = CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v3 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      this,
      elem: result);
    v4 = &this->m_Memory.m_pMemory[v3];
    v4->m_Next = -1;
    m_Tail = this->m_Tail;
    v4->m_Previous = m_Tail;
    this->m_Tail = v3;
    if ( m_Tail == -1 )
    {
      ++this->m_ElementCount;
      this->m_Head = v3;
    }
    else
    {
      this->m_Memory.m_pMemory[m_Tail].m_Next = v3;
      ++this->m_ElementCount;
    }
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004A7740
// Name: public: int CUtlVector<class vgui::CTreeViewListControl::CColumnInfo,class CUtlMemory<class vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(
        CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  vgui::CTreeViewListControl::CColumnInfo *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
      (CUtlMemory<BitmapFontTable_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_Title.m_Id = -1;
          v11->m_ciFlags = 0;
          v11->m_Right = 0;
          v11->m_Left = 0;
          v11->m_Width = 0;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004A81D0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<class CDmAttribute __near *,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CDmAttribute *,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<void *,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<void *,unsigned short> *m_pMemory; // edx
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
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<void *,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                    this: _g_pMemAlloc,
                                                                    a2: m_pMemory,
                                                                    a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<void *,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A8B60
// Name: public: int CUtlVector<struct vgui::AnimationController::ActiveAnimation_t,class CUtlMemory<struct vgui::AnimationController::ActiveAnimation_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::AnimationController::ActiveAnimation_t,CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int>>::InsertBefore(
        CUtlVector<vgui::AnimationController::ActiveAnimation_t,CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::AnimationController::ActiveAnimation_t *m_pMemory; // ecx
  int v6; // eax
  bool v7; // zf
  vgui::AnimationController::ActiveAnimation_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  v7 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 >= 0 && !v7 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 68 * v6);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    v8->panel.m_iPanelID = -1;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004A9F70
// Name: public: void CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(
        CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *this)
{
  int v1; // ebx
  int v2; // ebp
  bool v3; // sf
  CUtlVector<vgui::AnimationController::AnimCommand_t,CUtlMemory<vgui::AnimationController::AnimCommand_t,int> > *p_cmdList; // esi
  vgui::AnimationController::AnimCommand_t *m_pMemory; // eax
  CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = this->m_Memory.m_pMemory[v2].cmdList.m_Memory.m_nGrowSize < 0;
      p_cmdList = &this->m_Memory.m_pMemory[v2].cmdList;
      this->m_Memory.m_pMemory[v2].cmdList.m_Size = 0;
      if ( !v3 )
      {
        if ( p_cmdList->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_cmdList->m_Memory.m_pMemory);
          this = v6;
          p_cmdList->m_Memory.m_pMemory = nullptr;
        }
        p_cmdList->m_Memory.m_nAllocationCount = 0;
      }
      v3 = p_cmdList->m_Memory.m_nGrowSize < 0;
      m_pMemory = p_cmdList->m_Memory.m_pMemory;
      p_cmdList->m_pElements = p_cmdList->m_Memory.m_pMemory;
      if ( !v3 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          this = v6;
          p_cmdList->m_Memory.m_pMemory = nullptr;
        }
        p_cmdList->m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AA1F0
// Name: public: CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>::~CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::~CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>(
        CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *this)
{
  bool v2; // sf
  vgui::AnimationController::AnimSequence_t *m_pMemory; // eax

  CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AA880
// Name: public: virtual class CUtlVector<class vgui::PHandle,class CUtlMemory<class vgui::PHandle,int>> __near * vgui::BuildGroup::GetControlGroup(void)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int> > *__thiscall vgui::BuildGroup::GetControlGroup(
        vgui::BuildGroup *this)
{
  return &this->_controlGroup;
}

//------------------------------------------------------------------------------
// Address: 0x004ABEA0
// Name: public: int CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>::InsertMultipleBefore(
        CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::PHandle *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  vgui::PHandle *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          v11->m_iPanelID = -1;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004AE5A0
// Name: public: void CUtlMemory<struct PanelItem_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<PanelItem_t,int>::Grow(CUtlMemory<PanelItem_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  PanelItem_t *m_pMemory; // edx
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
    v7 = 84 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (PanelItem_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (PanelItem_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AF250
// Name: public: int CUtlVector<struct PanelItem_t,class CUtlMemory<struct PanelItem_t,int>>::InsertBefore(int,struct PanelItem_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<PanelItem_t,CUtlMemory<PanelItem_t,int>>::InsertBefore(
        CUtlVector<PanelItem_t,CUtlMemory<PanelItem_t,int> > *this,
        int elem,
        const PanelItem_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  PanelItem_t *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<PanelItem_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 84 * v7);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B95C0
// Name: protected: int CUtlLinkedList<struct vgui::PanelListPanel::dataitem_s,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int index; // eax
  int m_nAllocationCount; // ecx
  int result; // eax
  int v7; // eax
  int v8; // ecx
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree != -1 )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_23:
    v9 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_LastAlloc.index;
    if ( v7 < 0 || (v8 = this->m_Memory.m_nAllocationCount, v7 >= v8) )
    {
      v8 = this->m_Memory.m_nAllocationCount;
      result = (v8 > 0) - 1;
    }
    else
    {
      result = v7 + 1;
      if ( result < 0 || result >= v8 )
        result = -1;
    }
    if ( result < 0 || result >= v8 )
    {
      if ( _executeCount_14 < 10 )
      {
        ++_executeCount_14;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x004B96F0
// Name: public: void CUtlLinkedList<struct vgui::PanelListPanel::dataitem_s,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::PanelListPanel::dataitem_s,int>,int>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::Unlink(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this,
        int elem)
{
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v2; // eax
  int m_Next; // edx
  int m_Previous; // ebx

  if ( elem >= 0 && elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == -1 )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == -1 )
      {
        --this->m_ElementCount;
        this->m_Tail = m_Previous;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B9D00
// Name: public: int CUtlLinkedList<struct vgui::PanelListPanel::dataitem_s,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<struct vgui::PanelListPanel::dataitem_s,int>,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AddToTail(
        CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> > *this)
{
  int result; // eax
  int v3; // edi
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v4; // eax
  int m_Tail; // ecx

  result = CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v3 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::PanelListPanel::dataitem_s,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>>::Unlink(
      this,
      elem: result);
    v4 = &this->m_Memory.m_pMemory[v3];
    v4->m_Next = -1;
    m_Tail = this->m_Tail;
    v4->m_Previous = m_Tail;
    this->m_Tail = v3;
    if ( m_Tail == -1 )
    {
      ++this->m_ElementCount;
      this->m_Head = v3;
    }
    else
    {
      this->m_Memory.m_pMemory[m_Tail].m_Next = v3;
      ++this->m_ElementCount;
    }
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B9FA0
// Name: public: void CUtlMemory<class CFontAmalgam,int>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CFontAmalgam,int>::EnsureCapacity(CUtlMemory<CFontAmalgam,int> *this, int num)
{
  CFontAmalgam *m_pMemory; // edx
  bool v3; // zf

  if ( this->m_nAllocationCount < num && this->m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_pMemory;
    v3 = this->m_pMemory == nullptr;
    this->m_nAllocationCount = num;
    if ( v3 )
      this->m_pMemory = (CFontAmalgam *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 28 * num);
    else
      this->m_pMemory = (CFontAmalgam *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: 28 * num);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BA1B0
// Name: public: void CUtlVector<class CFontAmalgam,class CUtlMemory<class CFontAmalgam,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CFontAmalgam,CUtlMemory<CFontAmalgam,int>>::RemoveAll(
        CUtlVector<CFontAmalgam,CUtlMemory<CFontAmalgam,int> > *this)
{
  int v2; // esi
  int v3; // edi

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      CFontAmalgam::~CFontAmalgam(this: &this->m_Memory.m_pMemory[v3]);
      --v2;
      --v3;
    }
    while ( v2 >= 0 );
  }
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004BA260
// Name: public: CUtlVector<class CFontAmalgam,class CUtlMemory<class CFontAmalgam,int>>::~CUtlVector<class CFontAmalgam,class CUtlMemory<class CFontAmalgam,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CFontAmalgam,CUtlMemory<CFontAmalgam,int>>::~CUtlVector<CFontAmalgam,CUtlMemory<CFontAmalgam,int>>(
        CUtlVector<CFontAmalgam,CUtlMemory<CFontAmalgam,int> > *this)
{
  bool v2; // sf
  CFontAmalgam *m_pMemory; // eax

  CUtlVector<CFontAmalgam,CUtlMemory<CFontAmalgam,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BA2C0
// Name: public: int CUtlVector<class CFontAmalgam,class CUtlMemory<class CFontAmalgam,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CFontAmalgam,CUtlMemory<CFontAmalgam,int>>::InsertBefore(
        CUtlVector<CFontAmalgam,CUtlMemory<CFontAmalgam,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CFontAmalgam *m_pMemory; // ecx
  int v6; // eax
  bool v7; // zf
  CFontAmalgam *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlNTree<CTexturePacker::TreeEntry_t,unsigned short>::Node_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  v7 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 >= 0 && !v7 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 28 * v6);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CFontAmalgam::CFontAmalgam(this: v8);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004BB970
// Name: public: int CUtlVector<struct CFontTextureCache::Page_t,class CUtlMemory<struct CFontTextureCache::Page_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CFontTextureCache::Page_t,CUtlMemory<CFontTextureCache::Page_t,int>>::InsertBefore(
        CUtlVector<CFontTextureCache::Page_t,CUtlMemory<CFontTextureCache::Page_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CFontTextureCache::Page_t *m_pMemory; // ecx
  int v6; // eax
  bool v7; // zf
  CFontTextureCache::Page_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlHandleTable<CDmAttribute,21>::EntryType_t,int>::Grow(
      (CUtlMemory<ResourceEntryInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  v7 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 >= 0 && !v7 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v6);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    v8->pPackedFontTextureCache = nullptr;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004BDC60
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<class CMatSystemTexture,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CMatSystemTexture,unsigned short> *m_pMemory; // edx
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
    v7 = m_nAllocationCount << 6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CMatSystemTexture,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                   this: _g_pMemAlloc,
                                                                                   a2: m_pMemory,
                                                                                   a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CMatSystemTexture,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                   this: _g_pMemAlloc,
                                                                                   a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BDF80
// Name: protected: unsigned short CUtlLinkedList<class CMatSystemTexture,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CMatSystemTexture,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  unsigned __int16 m_FirstFree; // cx
  CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>::Iterator_t *p_m_LastAlloc; // ebx
  int m_nAllocationCount; // ecx
  unsigned __int16 result; // ax
  int v7; // edi
  unsigned __int16 *v8; // eax
  UtlLinkedListElem_t<CMatSystemTexture,unsigned short> *v9; // ecx
  CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>::Iterator_t v10; // [esp+Eh] [ebp-2h] BYREF

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_20:
    v9 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  p_m_LastAlloc = &this->m_LastAlloc;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else if ( (unsigned __int16)(p_m_LastAlloc->index + 1) >= m_nAllocationCount )
  {
    result = -1;
  }
  else
  {
    result = p_m_LastAlloc->index + 1;
  }
  v10.index = result;
  if ( result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( p_m_LastAlloc->index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      v10.index = (v7 > 0) - 1;
      v8 = (unsigned __int16 *)&v10;
    }
    else
    {
      v8 = (unsigned __int16 *)CUtlMemory<UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short>,unsigned short>::Next(
                                 (CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short> *)this,
                                 result: (CUtlMemory<UtlLinkedListElem_t<CTGARenderer::UIQuadInfo,unsigned short>,unsigned short>::Iterator_t *)&v10,
                                 it: (const CUtlMemory<UtlRBTreeNode_t<CWin32Font::abc_cache_t,unsigned short>,unsigned short>::Iterator_t *)&this->m_LastAlloc);
    }
    result = *v8;
    if ( result >= v7 )
    {
      if ( _executeCount_16 < 10 )
      {
        ++_executeCount_16;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  if ( result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    p_m_LastAlloc->index = result;
    goto LABEL_20;
  }
  if ( _executeCount_15 >= 10 )
    return -1;
  ++_executeCount_15;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BE590
// Name: public: void CUtlLinkedList<class CMatSystemTexture,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CMatSystemTexture,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CMatSystemTexture,unsigned short> *v2; // eax
  unsigned __int16 m_Next; // dx
  unsigned __int16 m_Previous; // di

  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == 0xFFFF )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == 0xFFFF )
      {
        --this->m_ElementCount;
        this->m_Tail = m_Previous;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BE940
// Name: public: unsigned short CUtlLinkedList<class CMatSystemTexture,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CMatSystemTexture,unsigned short>,unsigned short>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>>::AddToTail(
        CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 v2; // ax
  unsigned __int16 v3; // di
  int v5; // ecx
  char *v6; // eax
  unsigned __int16 m_Tail; // bx
  UtlLinkedListElem_t<CMatSystemTexture,unsigned short> *m_pMemory; // eax

  v2 = CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>>::AllocInternal(
         this,
         multilist: false);
  v3 = v2;
  if ( v2 == 0xFFFF )
    return 0xFFFF;
  CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>>::Unlink(
    this,
    elem: v2);
  v5 = v3 << 6;
  v6 = (char *)this->m_Memory.m_pMemory + v5;
  *((_WORD *)v6 + 31) = -1;
  m_Tail = this->m_Tail;
  *((_WORD *)v6 + 30) = m_Tail;
  this->m_Tail = v3;
  if ( m_Tail == 0xFFFF )
    this->m_Head = v3;
  else
    this->m_Memory.m_pMemory[m_Tail].m_Next = v3;
  m_pMemory = this->m_Memory.m_pMemory;
  ++this->m_ElementCount;
  Construct<CMatSystemTexture>(pMemory: (CMatSystemTexture *)((char *)&m_pMemory->m_Element + v5));
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x004BE9C0
// Name: public: void CUtlLinkedList<class CMatSystemTexture,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CMatSystemTexture,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // bx
  int v3; // eax
  unsigned __int16 v4; // di
  CMatSystemTexture *v5; // esi
  const ResourceBinding_t<CTextureBits> *m_pBinding; // eax
  unsigned __int16 m_FirstFree; // ax
  unsigned __int16 v8; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v3 = m_Head << 6;
        v4 = *(unsigned __int16 *)((char *)&this->m_Memory.m_pMemory->m_Next + v3);
        v5 = (CMatSystemTexture *)((char *)&this->m_Memory.m_pMemory->m_Element + v3);
        CMatSystemTexture::CleanUpMaterial(this: v5);
        m_pBinding = v5->m_Texture2.m_pBinding;
        if ( m_pBinding != nullptr )
        {
          _InterlockedExchangeAdd(&m_pBinding->m_nRefCount.m_value, 0xFFFFFFFF);
          v5->m_Texture2.m_pBinding = nullptr;
        }
        LOWORD(v5[1].m_s0) = m_Head;
        if ( v4 == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = v4;
        HIWORD(v5[1].m_s0) = m_FirstFree;
        m_Head = v4;
      }
      while ( v4 != 0xFFFF );
    }
    v8 = this->m_Head;
    if ( v8 != 0xFFFF )
      this->m_FirstFree = v8;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BEAB0
// Name: public: void CUtlLinkedList<class CMatSystemTexture,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<class CMatSystemTexture,unsigned short>,unsigned short>>::Remove(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>>::Remove(
        CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CMatSystemTexture,unsigned short> *v3; // esi
  const ResourceBinding_t<CTextureBits> *m_pBinding; // eax

  CUtlLinkedList<CMatSystemTexture,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMatSystemTexture,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  v3 = &this->m_Memory.m_pMemory[elem];
  CMatSystemTexture::CleanUpMaterial(this: &v3->m_Element);
  m_pBinding = v3->m_Element.m_Texture2.m_pBinding;
  if ( m_pBinding != nullptr )
  {
    _InterlockedExchangeAdd(&m_pBinding->m_nRefCount.m_value, 0xFFFFFFFF);
    v3->m_Element.m_Texture2.m_pBinding = nullptr;
  }
  v3->m_Next = this->m_FirstFree;
  this->m_FirstFree = elem;
}

//------------------------------------------------------------------------------
// Address: 0x004C0940
// Name: public: int CUtlVector<struct BitmapFontTable_t,class CUtlMemory<struct BitmapFontTable_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<BitmapFontTable_t,CUtlMemory<BitmapFontTable_t,int>>::InsertBefore(
        CUtlVector<BitmapFontTable_t,CUtlMemory<BitmapFontTable_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  BitmapFontTable_t *m_pMemory; // ecx
  int v6; // eax
  bool v7; // zf
  BitmapFontTable_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  v7 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 >= 0 && !v7 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 20 * v6);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
  {
    v8->m_pTexture2.m_pBinding = nullptr;
    v8->m_szName.m_Id = -1;
    v8->m_pBitmapFont = nullptr;
    v8->m_pBitmapGlyphs = nullptr;
    v8->m_pTexture = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004C0AC0
// Name: public: void CUtlVector<struct BitmapFontTable_t,class CUtlMemory<struct BitmapFontTable_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<BitmapFontTable_t,CUtlMemory<BitmapFontTable_t,int>>::RemoveAll(
        CUtlVector<BitmapFontTable_t,CUtlMemory<BitmapFontTable_t,int> > *this)
{
  int v1; // esi
  int v2; // edi
  const ResourceBinding_t<CTextureBits> *m_pBinding; // edx
  CStrongHandle<CTextureBits> *p_m_pTexture2; // eax

  v1 = this->m_Size - 1;
  if ( v1 >= 0 )
  {
    v2 = v1;
    do
    {
      m_pBinding = this->m_Memory.m_pMemory[v2].m_pTexture2.m_pBinding;
      p_m_pTexture2 = &this->m_Memory.m_pMemory[v2].m_pTexture2;
      if ( m_pBinding != nullptr )
      {
        _InterlockedExchangeAdd(&m_pBinding->m_nRefCount.m_value, 0xFFFFFFFF);
        p_m_pTexture2->m_pBinding = nullptr;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
  }
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004C0E30
// Name: public: CUtlVector<struct BitmapFontTable_t,class CUtlMemory<struct BitmapFontTable_t,int>>::~CUtlVector<struct BitmapFontTable_t,class CUtlMemory<struct BitmapFontTable_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<BitmapFontTable_t,CUtlMemory<BitmapFontTable_t,int>>::~CUtlVector<BitmapFontTable_t,CUtlMemory<BitmapFontTable_t,int>>(
        CUtlVector<BitmapFontTable_t,CUtlMemory<BitmapFontTable_t,int> > *this)
{
  bool v2; // sf
  BitmapFontTable_t *m_pMemory; // eax

  CUtlVector<BitmapFontTable_t,CUtlMemory<BitmapFontTable_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C4D40
// Name: public: int CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
        CUtlVector<ResourceEntryInfo,CUtlMemory<ResourceEntryInfo,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ResourceEntryInfo *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlHandleTable<CDmAttribute,21>::EntryType_t,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 8 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004C4DB0
// Name: public: int CUtlVector<struct CVTFTexture::ResourceMemorySection,class CUtlMemory<struct CVTFTexture::ResourceMemorySection,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int>>::InsertMultipleBefore(
        CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CVTFTexture::ResourceMemorySection *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CVTFTexture::ResourceMemorySection *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 12 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          *(_QWORD *)&v11->m_nDataAllocSize = 0;
          v11->m_pData = nullptr;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004C51F0
// Name: public: int CUtlVector<struct CVTFTexture::ResourceMemorySection,class CUtlMemory<struct CVTFTexture::ResourceMemorySection,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int>>::InsertBefore(
        CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CVTFTexture::ResourceMemorySection *m_pMemory; // ecx
  int v6; // eax
  bool v7; // zf
  CVTFTexture::ResourceMemorySection *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  v7 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 >= 0 && !v7 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v6);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
  {
    *(_QWORD *)&v8->m_nDataAllocSize = 0;
    v8->m_pData = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004EE740
// Name: public: void CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>>::Sort(int (*)(class CUtlSymbolLarge const __near *,class CUtlSymbolLarge const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>::Sort(
        CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > *this,
        int (__cdecl *pfnCompare)(const void *, const void *))
{
  signed int m_Size; // eax
  CUtlSymbolLarge *m_pMemory; // ecx
  int v5; // ebx
  int i; // esi
  CUtlSymbolLarge *v7; // eax
  CUtlSymbolLarge::<unnamed_tag> v8; // ecx

  m_Size = this->m_Size;
  if ( m_Size > 1 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      qsort(base: m_pMemory, num: m_Size, width: 4u, comp: pfnCompare);
    }
    else
    {
      v5 = m_Size - 1;
      do
      {
        for ( i = 1; i <= v5; ++i )
        {
          if ( pfnCompare(a1: &this->m_Memory.m_pMemory[i - 1], a2: &this->m_Memory.m_pMemory[i]) < 0 )
          {
            v7 = &this->m_Memory.m_pMemory[i];
            v8.m_Id = (int)v7[-1].u;
            v7[-1].u.m_Id = v7->u.m_Id;
            v7->u.m_Id = v8.m_Id;
          }
        }
        --v5;
      }
      while ( v5 >= 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EEB60
// Name: public: void CUtlMemory<struct LayerRenderLists_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<LayerRenderLists_t,int>::Grow(CUtlMemory<LayerRenderLists_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  LayerRenderLists_t *m_pMemory; // edx
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
      this->m_pMemory = (LayerRenderLists_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (LayerRenderLists_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EF370
// Name: public: void CUtlVector<struct CDataModel::ElementIdHandlePair_t,class CUtlMemory<struct CDataModel::ElementIdHandlePair_t,int>>::FastRemove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int>>::FastRemove(
        CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  CDataModel::ElementIdHandlePair_t *m_pMemory; // edx
  int v4; // eax
  __int64 v5; // xmm0_8
  CDataModel::ElementIdHandlePair_t *v6; // eax
  CDataModel::ElementIdHandlePair_t *v7; // edx

  m_Size = this->m_Size;
  if ( m_Size > 0 )
  {
    if ( elem != m_Size - 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v4 = m_Size;
      v5 = *(_QWORD *)this->m_Memory.m_pMemory[v4 - 1].m_id.m_Value;
      v6 = &this->m_Memory.m_pMemory[v4 - 1];
      *(_QWORD *)m_pMemory[elem].m_id.m_Value = v5;
      v7 = &m_pMemory[elem];
      *(_QWORD *)&v7->m_id.m_Value[8] = *(_QWORD *)&v6->m_id.m_Value[8];
      v7->m_ref = v6->m_ref;
    }
    --this->m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EFA50
// Name: public: int CUtlVector<struct CDataModel::ElementIdHandlePair_t,class CUtlMemory<struct CDataModel::ElementIdHandlePair_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int>>::InsertMultipleBefore(
        CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDataModel::ElementIdHandlePair_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // ecx
  int i; // edx
  CDataModel::ElementIdHandlePair_t *v11; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<LayerRenderLists_t,int>::Grow(
      (CUtlMemory<LayerRenderLists_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 36 * v8);
LABEL_8:
    if ( num > 0 )
    {
      v9 = elem;
      for ( i = num; i != 0; --i )
      {
        v11 = &this->m_Memory.m_pMemory[v9];
        if ( v11 != nullptr )
        {
          *((_DWORD *)&v11->m_ref + 1) &= 0xC0000000;
          *((_BYTE *)&v11->m_ref + 8) &= ~1u;
          v11->m_ref.m_hElement = DMELEMENT_HANDLE_INVALID;
          v11->m_ref.m_attributes.m_hAttribute = DMATTRIBUTE_HANDLE_INVALID;
          v11->m_ref.m_attributes.m_pNext = nullptr;
        }
        ++v9;
      }
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004F1710
// Name: public: int CUtlVector<struct CUtlHandleTable<class CDmAttribute,21>::EntryType_t,class CUtlMemory<struct CUtlHandleTable<class CDmAttribute,21>::EntryType_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlHandleTable<CDmAttribute,21>::EntryType_t,CUtlMemory<CUtlHandleTable<CDmAttribute,21>::EntryType_t,int>>::InsertBefore(
        CUtlVector<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *m_pMemory; // ecx
  int v6; // eax
  bool v7; // zf
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlHandleTable<CDmAttribute,21>::EntryType_t,int>::Grow(
      (CUtlMemory<ResourceEntryInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  v7 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 >= 0 && !v7 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v6);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
  {
    *(_DWORD *)v8 = 0;
    v8->m_pData = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004F1780
// Name: public: int CUtlVector<struct CDataModel::ElementIdHandlePair_t,class CUtlMemory<struct CDataModel::ElementIdHandlePair_t,int>>::InsertBefore(int,struct CDataModel::ElementIdHandlePair_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int>>::InsertBefore(
        CUtlVector<CDataModel::ElementIdHandlePair_t,CUtlMemory<CDataModel::ElementIdHandlePair_t,int> > *this,
        int elem,
        const CDataModel::ElementIdHandlePair_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDataModel::ElementIdHandlePair_t *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  CDataModel::ElementIdHandlePair_t *v9; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<LayerRenderLists_t,int>::Grow(
      (CUtlMemory<LayerRenderLists_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 36 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
  {
    DmElementReference_t::DmElementReference_t(this: &v9->m_ref, that: &src->m_ref);
    CopyUniqueId(src: &src->m_id, pDest: &v9->m_id);
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004F3C60
// Name: public: CUtlVector<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,class CUtlMemory<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,int>>::~CUtlVector<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,class CUtlMemory<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(
        CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *this)
{
  bool v2; // sf
  CVTFTexture::ResourceMemorySection *m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F4840
// Name: public: void CUtlVector<class CUtlVector<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,class CUtlMemory<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,class CUtlMemory<class CUtlVector<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,class CUtlMemory<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll(
        CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *this)
{
  int v1; // ebx
  int v2; // ebp
  CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> > *v3; // esi
  bool v4; // sf
  CDmElementDictionary::DmIdPair_t *m_pMemory; // eax
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v4 = v3->m_Memory.m_nGrowSize < 0;
      v3->m_Size = 0;
      if ( !v4 )
      {
        if ( v3->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
          this = v6;
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      v4 = v3->m_Memory.m_nGrowSize < 0;
      m_pMemory = v3->m_Memory.m_pMemory;
      v3->m_pElements = v3->m_Memory.m_pMemory;
      if ( !v4 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          this = v6;
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F6250
// Name: public: class CUtlVector<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,class CUtlMemory<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,int>> __near & CUtlVector<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,class CUtlMemory<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,int>>::operator=(class CUtlVector<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,class CUtlMemory<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,int> > *__thiscall CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>::operator=(
        CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,int> > *this,
        const CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,int> > *other)
{
  int m_Size; // esi
  CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *v3; // edi
  int v4; // ebp
  CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> > *m_pMemory; // esi
  int v6; // edi
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > *v7; // ebx
  CUtlMemory<S3RGBA,int> *v8; // esi
  int m_nAllocationCount; // eax
  S3RGBA *v10; // ecx
  int v11; // eax
  bool v12; // zf
  int i; // eax
  int v15; // [esp+8h] [ebp-8h]

  m_Size = other->m_Size;
  v3 = (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)this;
  CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll((CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)this);
  CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::InsertMultipleBefore(
    this: v3,
    elem: v3->m_Size,
    num: m_Size);
  if ( m_Size <= 0 )
    return (CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> >,int> > *)v3;
  v4 = 0;
  v15 = m_Size;
  while ( 1 )
  {
    m_pMemory = v3->m_Memory.m_pMemory;
    v6 = other->m_Memory.m_pMemory[v4].m_Size;
    v7 = &other->m_Memory.m_pMemory[v4];
    v8 = (CUtlMemory<S3RGBA,int> *)&m_pMemory[v4];
    v8[1].m_pMemory = nullptr;
    if ( v6 != 0 )
    {
      m_nAllocationCount = v8->m_nAllocationCount;
      if ( v6 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v8, num: v6 - m_nAllocationCount);
      v8[1].m_pMemory = (S3RGBA *)((char *)v8[1].m_pMemory + v6);
      v10 = v8->m_pMemory;
      v11 = (int)v8[1].m_pMemory - v6;
      v12 = v8[1].m_pMemory == (S3RGBA *)v6;
      v8[1].m_nAllocationCount = (int)v8->m_pMemory;
      if ( v11 >= 0 && !v12 && v6 > 0 )
        _V_memmove(dest: &v10[v6], src: v10, count: 4 * v11);
    }
    for ( i = 0; i < v6; ++i )
      v8->m_pMemory[i] = (S3RGBA)v7->m_Memory.m_pMemory[i];
    ++v4;
    if ( --v15 == 0 )
      break;
    v3 = (CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *)this;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004F80B0
// Name: protected: int CUtlLinkedList<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *__thiscall CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::AllocInternal(
        CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > > *this,
        bool multilist)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *result; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *m_pBlockHeader; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *p_m_LastAlloc; // esi
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *v7; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *v8; // ecx
  bool v9; // zf
  int v10; // eax
  int v11; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *v12; // eax
  int v13; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t v14; // [esp+Ch] [ebp-18h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t v15; // [esp+14h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t v16; // [esp+1Ch] [ebp-8h] BYREF

  result = (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *)this->m_FirstFree;
  if ( result != nullptr )
  {
    this->m_FirstFree = result[1].m_nBlockSize;
LABEL_33:
    if ( multilist )
    {
      result[1].m_nBlockSize = 0;
      result[1].m_pNext = nullptr;
    }
    else
    {
      result[1].m_nBlockSize = (int)result;
      result[1].m_pNext = result;
    }
    return result;
  }
  m_pBlockHeader = this->m_LastAlloc.m_pBlockHeader;
  p_m_LastAlloc = &this->m_LastAlloc;
  if ( m_pBlockHeader != nullptr
    && (m_nIndex = this->m_LastAlloc.m_nIndex) >= 0
    && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    v7 = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Next(
           this: &this->m_Memory,
           result: &v15,
           it: &this->m_LastAlloc);
  }
  else
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      v14.m_pBlockHeader = this->m_Memory.m_pBlocks;
      v14.m_nIndex = 0;
    }
    else
    {
      v14.m_pBlockHeader = nullptr;
      v14.m_nIndex = -1;
    }
    v15 = v14;
    v7 = &v15;
  }
  v8 = v7->m_pBlockHeader;
  v9 = v7->m_pBlockHeader == nullptr;
  v10 = v7->m_nIndex;
  if ( v9 || v10 < 0 || v10 >= v8->m_nBlockSize )
  {
    CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = nullptr;
    if ( p_m_LastAlloc->m_pBlockHeader != nullptr
      && (v11 = this->m_LastAlloc.m_nIndex) >= 0
      && v11 < p_m_LastAlloc->m_pBlockHeader->m_nBlockSize )
    {
      v12 = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Next(
              this: &this->m_Memory,
              result: &v14,
              it: &this->m_LastAlloc);
    }
    else
    {
      v12 = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::First(
              this: &this->m_Memory,
              result: &v16);
    }
    v8 = v12->m_pBlockHeader;
    v9 = v12->m_pBlockHeader == nullptr;
    v10 = v12->m_nIndex;
    if ( v9 || v10 < 0 || v10 >= v8->m_nBlockSize )
    {
      if ( _executeCount_18 < 10 )
      {
        ++_executeCount_18;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return nullptr;
    }
  }
  if ( &v8[2 * v10] != (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *)-8 )
  {
    this->m_LastAlloc.m_nIndex = v10;
    p_m_LastAlloc->m_pBlockHeader = v8;
    if ( v8 != nullptr && (v13 = this->m_LastAlloc.m_nIndex) >= 0 && v13 < v8->m_nBlockSize )
    {
      ++this->m_NumAlloced;
      result = &v8[2 * v13 + 1];
    }
    else
    {
      result = nullptr;
      ++this->m_NumAlloced;
    }
    goto LABEL_33;
  }
  if ( _executeCount_17 >= 10 )
    return nullptr;
  ++_executeCount_17;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004F8910
// Name: public: void CUtlLinkedList<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::RemoveAll(
        CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t *i; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *m_pBlockHeader; // edi
  bool v4; // zf
  int m_nIndex; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t it; // [esp+10h] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::Iterator_t result; // [esp+18h] [ebp-8h] BYREF

  if ( this->m_LastAlloc.m_pBlockHeader != nullptr || this->m_LastAlloc.m_nIndex != -1 )
  {
    if ( this->m_Memory.m_pBlocks != nullptr )
    {
      result.m_pBlockHeader = this->m_Memory.m_pBlocks;
      result.m_nIndex = 0;
    }
    else
    {
      result.m_pBlockHeader = nullptr;
      result.m_nIndex = -1;
    }
    for ( i = &result;
          ;
          i = CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::Next(
                this: &this->m_Memory,
                &result,
                &it) )
    {
      m_pBlockHeader = i->m_pBlockHeader;
      v4 = i->m_pBlockHeader == nullptr;
      m_nIndex = i->m_nIndex;
      it.m_nIndex = m_nIndex;
      it.m_pBlockHeader = m_pBlockHeader;
      if ( v4 )
      {
        if ( m_nIndex == -1 )
          break;
      }
      else if ( m_nIndex >= 0
             && m_nIndex < m_pBlockHeader->m_nBlockSize
             && &m_pBlockHeader[2 * m_nIndex] != (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *)-8
             && !CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::IsIdxAfter(
                   this: &this->m_Memory,
                   i: (int)&m_pBlockHeader[2 * m_nIndex + 1],
                   it: &this->m_LastAlloc)
             && (m_pBlockHeader[2 * m_nIndex + 2].m_pNext != &m_pBlockHeader[2 * m_nIndex + 1]
              || (CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *)m_pBlockHeader[2 * m_nIndex + 2].m_nBlockSize == &m_pBlockHeader[2 * m_nIndex + 1]) )
      {
        m_pBlockHeader[2 * m_nIndex + 2].m_pNext = &m_pBlockHeader[2 * m_nIndex + 1];
        m_pBlockHeader[2 * m_nIndex + 2].m_nBlockSize = this->m_FirstFree;
        this->m_FirstFree = (int)&m_pBlockHeader[2 * m_nIndex + 1];
      }
      if ( m_pBlockHeader == this->m_LastAlloc.m_pBlockHeader && m_nIndex == this->m_LastAlloc.m_nIndex )
        break;
    }
    this->m_Head = 0;
    this->m_Tail = 0;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F8F20
// Name: public: void CUtlLinkedList<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::Unlink(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::Unlink(
        CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > > *this,
        int elem)
{
  int v3; // ecx
  int v4; // eax

  if ( elem != 0
    && !CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>::IsIdxAfter(
          this: &this->m_Memory,
          i: elem,
          it: &this->m_LastAlloc)
    && *(_DWORD *)(elem + 8) != elem )
  {
    v3 = *(_DWORD *)(elem + 8);
    v4 = *(_DWORD *)(elem + 12);
    if ( v3 != 0 )
      *(_DWORD *)(v3 + 12) = v4;
    else
      this->m_Head = v4;
    if ( v4 != 0 )
    {
      *(_DWORD *)(v4 + 8) = v3;
      --this->m_ElementCount;
    }
    else
    {
      --this->m_ElementCount;
      this->m_Tail = v3;
    }
    *(_DWORD *)(elem + 12) = elem;
    *(_DWORD *)(elem + 8) = elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F9040
// Name: public: void CUtlLinkedList<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CUtlHashFast<enum DmElementHandle_t,class CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::Purge(
        CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> > > *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int> >::BlockHeader_t *v3; // eax

  CUtlLinkedList<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CUtlHashFast<enum DmElementHandle_t,CUtlHashFastNoHash>::HashFastData_t_<enum DmElementHandle_t>,int>>>::RemoveAll(this);
  m_pBlocks = this->m_Memory.m_pBlocks;
  if ( this->m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v3 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
    }
    while ( m_pBlocks != nullptr );
    this->m_Memory.m_pBlocks = nullptr;
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_FirstFree = 0;
  this->m_NumAlloced = 0;
  this->m_pElements = nullptr;
  this->m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_LastAlloc.m_nIndex = -1;
}

//------------------------------------------------------------------------------
// Address: 0x004FC770
// Name: public: void CUtlVector<bool,class CUtlMemory<bool,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCapacity(
        CUtlVector<bool,CUtlMemory<bool,int> > *this,
        int num)
{
  bool *m_pMemory; // eax
  bool v4; // zf
  bool *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    m_pMemory = this->m_Memory.m_pMemory;
    v4 = this->m_Memory.m_pMemory == nullptr;
    this->m_Memory.m_nAllocationCount = num;
    if ( v4 )
      v5 = (bool *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: num);
    else
      v5 = (bool *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: num);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004FC7D0
// Name: public: void CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::EnsureCapacity(
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *this,
        int num)
{
  Vector2D *m_pMemory; // edx
  unsigned int v4; // eax
  Vector2D *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 8 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (Vector2D *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (Vector2D *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004FC830
// Name: public: void CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>>::RemoveMultiple(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<QAngle,CUtlMemory<QAngle,int>>::RemoveMultiple(
        CUtlVector<QAngle,CUtlMemory<QAngle,int> > *this,
        int elem,
        int num)
{
  if ( this->m_Size - elem - num > 0 && num > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[elem + num],
      count: 12 * (this->m_Size - elem - num));
  this->m_Size -= num;
}

//------------------------------------------------------------------------------
// Address: 0x004FC880
// Name: public: void CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::EnsureCapacity(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        int num)
{
  CUtlString *m_pMemory; // edx
  unsigned int v4; // eax
  CUtlString *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 16 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (CUtlString *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (CUtlString *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004FC8E0
// Name: public: void CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>::EnsureCapacity(
        CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *this,
        int num)
{
  VMatrix *m_pMemory; // edx
  unsigned int v4; // eax
  VMatrix *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = num << 6;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (VMatrix *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (VMatrix *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004FCDA0
// Name: public: int CUtlVector<class Color,class CUtlMemory<class Color,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Color,CUtlMemory<Color,int>>::InsertBefore(
        CUtlVector<Color,CUtlMemory<Color,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Color *m_pMemory; // ecx
  int v6; // eax
  bool v7; // zf
  Color *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  v7 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 >= 0 && !v7 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v6);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = 0;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004FCE10
// Name: public: int CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertBefore(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlBinaryBlock *m_pMemory; // ecx
  int v6; // eax
  bool v7; // zf
  CUtlBinaryBlock *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  v7 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 >= 0 && !v7 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v6);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CUtlBinaryBlock::CUtlBinaryBlock(this: v8, growSize: 0, initSize: 0);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004FCE80
// Name: public: int CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>::InsertBefore(
        CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  DmeTime_t *m_pMemory; // ecx
  int v6; // eax
  bool v7; // zf
  DmeTime_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  v7 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 >= 0 && !v7 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v6);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    v8->m_tms = 0x80000000;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00503140
// Name: public: int CUtlVector<bool,class CUtlMemory<bool,int>>::InsertBefore(int,bool const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<bool,CUtlMemory<bool,int>>::InsertBefore(
        CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *this,
        int elem,
        unsigned __int8 *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  unsigned __int8 *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  unsigned __int8 *v9; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<bool,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x005031A0
// Name: public: int CUtlVector<class Color,class CUtlMemory<class Color,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Color,CUtlMemory<Color,int>>::InsertMultipleBefore(
        CUtlVector<Color,CUtlMemory<Color,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Color *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  Color *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          *v11 = 0;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00503230
// Name: public: int CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
        CUtlVector<QAngle,CUtlMemory<QAngle,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  QAngle *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 12 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x005032B0
// Name: public: int CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>::InsertBefore(int,class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::InsertBefore(
        CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *this,
        int elem,
        const Vector4D *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector4D *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  Vector4D *v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00503330
// Name: public: int CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::InsertMultipleBefore(
        CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Quaternion *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 16 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x005033A0
// Name: public: int CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>::InsertBefore(int,class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::InsertBefore(
        CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *this,
        int elem,
        const Quaternion *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Quaternion *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  Quaternion *v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00503420
// Name: public: int CUtlVector<struct vgui::MessageMapItem_t,class CUtlMemory<struct vgui::MessageMapItem_t,int>>::InsertBefore(int,struct vgui::MessageMapItem_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
        CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int> > *this,
        int elem,
        const vgui::MessageMapItem_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::MessageMapItem_t *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::MessageMapItem_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: v7 << 6);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00503490
// Name: public: int CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>::InsertMultipleBefore(
        CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  VMatrix *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<vgui::MessageMapItem_t,int>::Grow(
      (CUtlMemory<vgui::MessageMapItem_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: (void *)&m_pMemory[elem + num], src: &m_pMemory[elem], count: v9 << 6);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00503500
// Name: public: int CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::InsertBefore(int,class CUtlBinaryBlock const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertBefore(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem,
        const CUtlBinaryBlock *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlBinaryBlock *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  CUtlBinaryBlock *v9; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    CUtlBinaryBlock::CUtlBinaryBlock(this: v9, src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00503570
// Name: public: int CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertMultipleBefore(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlBinaryBlock *m_pMemory; // ecx
  int v9; // eax
  int v10; // ebx
  CUtlBinaryBlock *v11; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[num + elem], src: &m_pMemory[elem], count: 16 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          CUtlBinaryBlock::CUtlBinaryBlock(this: v11, growSize: 0, initSize: 0);
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00503610
// Name: public: int CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>::InsertMultipleBefore(
        CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  DmeTime_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  DmeTime_t *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          v11->m_tms = 0x80000000;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0050F220
// Name: public: void CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CUtlBinaryBlock *v3; // esi
  bool v4; // sf
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *v5; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v4 = v3->m_Memory.m_nGrowSize < 0;
      v3->m_nActualLength = 0;
      if ( !v4 )
      {
        if ( v3->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
          this = v5;
          v3->m_Memory.m_pMemory = nullptr;
        }
        v3->m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00516B40
// Name: public: void CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::FastRemove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::FastRemove(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem)
{
  CUtlBinaryBlock *v3; // esi
  bool v4; // sf
  int m_Size; // eax
  int v6; // eax
  __int64 v7; // xmm0_8
  CUtlBinaryBlock *v8; // eax
  CUtlBinaryBlock *v9; // ecx

  v3 = &this->m_Memory.m_pMemory[elem];
  v4 = v3->m_Memory.m_nGrowSize < 0;
  v3->m_nActualLength = 0;
  if ( !v4 )
  {
    if ( v3->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
      v3->m_Memory.m_pMemory = nullptr;
    }
    v3->m_Memory.m_nAllocationCount = 0;
  }
  m_Size = this->m_Size;
  if ( m_Size > 0 )
  {
    if ( elem != m_Size - 1 )
    {
      v6 = m_Size;
      v7 = *(_QWORD *)&this->m_Memory.m_pMemory[v6 - 1].m_Memory.m_pMemory;
      v8 = &this->m_Memory.m_pMemory[v6 - 1];
      v9 = &this->m_Memory.m_pMemory[elem];
      *(_QWORD *)&v9->m_Memory.m_pMemory = v7;
      *(_QWORD *)&v9->m_Memory.m_nGrowSize = *(_QWORD *)&v8->m_Memory.m_nGrowSize;
    }
    --this->m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00516BC0
// Name: public: void CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::Remove(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem)
{
  CUtlBinaryBlock *v3; // esi
  bool v4; // sf

  v3 = &this->m_Memory.m_pMemory[elem];
  v4 = v3->m_Memory.m_nGrowSize < 0;
  v3->m_nActualLength = 0;
  if ( !v4 )
  {
    if ( v3->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Memory.m_pMemory);
      v3->m_Memory.m_pMemory = nullptr;
    }
    v3->m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_Size - elem - 1 > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[elem + 1],
      count: 16 * (this->m_Size - elem - 1));
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00516C30
// Name: public: void CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::RemoveMultiple(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveMultiple(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        int elem,
        int num)
{
  int v5; // ecx
  int v6; // edx
  int v7; // ebp
  CUtlBinaryBlock *v8; // esi
  bool v9; // sf
  int v10; // [esp+8h] [ebp-4h]
  int elema; // [esp+10h] [ebp+4h]

  v5 = num;
  v6 = elem + num;
  v10 = elem + num;
  if ( elem + num - 1 >= elem )
  {
    v7 = elem + num - 1;
    elema = num;
    do
    {
      v8 = &this->m_Memory.m_pMemory[v7];
      v9 = v8->m_Memory.m_nGrowSize < 0;
      v8->m_nActualLength = 0;
      if ( !v9 )
      {
        if ( v8->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8->m_Memory.m_pMemory);
          v5 = num;
          v6 = v10;
          v8->m_Memory.m_pMemory = nullptr;
        }
        v8->m_Memory.m_nAllocationCount = 0;
      }
      --v7;
      --elema;
    }
    while ( elema != 0 );
  }
  if ( this->m_Size - elem - v5 > 0 && v5 > 0 )
  {
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[v6],
      count: 16 * (this->m_Size - elem - v5));
    v5 = num;
  }
  this->m_Size -= v5;
}

//------------------------------------------------------------------------------
// Address: 0x0051B210
// Name: public: void CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>::CopyArray(class Vector2D const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::CopyArray(
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *this,
        const Vector2D *pArray,
        int size)
{
  int v3; // edi
  int v4; // ebp
  int v7; // edx
  unsigned int v8; // edi
  float *p_y; // eax
  Vector2D *m_pMemory; // ecx
  char *v11; // edx
  float *v12; // ecx
  float *v13; // ecx
  double v14; // st7
  float *v15; // ecx
  int v16; // ecx
  Vector2D *v17; // eax
  int v18; // [esp+10h] [ebp-8h]
  int v19; // [esp+14h] [ebp-4h]
  const Vector2D *pArraya; // [esp+1Ch] [ebp+4h]

  v3 = size;
  v4 = 0;
  this->m_Size = 0;
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
    (CUtlVector<ResourceEntryInfo,CUtlMemory<ResourceEntryInfo,int> > *)this,
    elem: 0,
    num: size);
  if ( size >= 4 )
  {
    v18 = -4 - (_DWORD)pArray;
    v7 = -20 - (_DWORD)pArray;
    v8 = ((unsigned int)(size - 4) >> 2) + 1;
    p_y = &pArray[2].y;
    v19 = 4 - (_DWORD)pArray;
    pArraya = (const Vector2D *)(-20 - (_DWORD)pArray);
    v4 = 4 * v8;
    while ( 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v11 = (char *)p_y + v7;
      *(float *)&v11[(_DWORD)m_pMemory] = *(p_y - 5);
      *(float *)((char *)&m_pMemory->y + (_DWORD)v11) = *(p_y - 4);
      v12 = (float *)&v11[(unsigned int)this->m_Memory.m_pMemory + 8];
      *v12 = *(p_y - 3);
      v12[1] = *(p_y - 2);
      v13 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_y + v18);
      *v13 = *(p_y - 1);
      v13[1] = *p_y;
      v14 = p_y[1];
      v15 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_y + v19);
      p_y += 8;
      --v8;
      *v15 = v14;
      v15[1] = *(p_y - 6);
      if ( v8 == 0 )
        break;
      v7 = (int)pArraya;
    }
    v3 = size;
  }
  for ( ; v4 < v3; v17->y = pArray[v16].y )
  {
    v16 = v4;
    v17 = &this->m_Memory.m_pMemory[v4];
    v17->x = pArray[v4++].x;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051B300
// Name: public: void CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::CopyArray(class Vector const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::CopyArray(
        CUtlVector<QAngle,CUtlMemory<QAngle,int> > *this,
        const QAngle *pArray,
        int size)
{
  int v3; // edi
  int v5; // eax
  int v6; // edx
  unsigned int v7; // edi
  float *p_z; // eax
  QAngle *m_pMemory; // ecx
  char *v10; // edx
  float *v11; // ecx
  float *v12; // ecx
  float *v13; // ecx
  float *v14; // ecx
  double v15; // st7
  float *v16; // ecx
  int v17; // edi
  double v18; // st7
  float *v19; // eax
  int v20; // [esp+10h] [ebp-4h]

  v3 = size;
  this->m_Size = 0;
  CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(this, elem: 0, num: size);
  v5 = 0;
  if ( size >= 4 )
  {
    v6 = -20 - (_DWORD)pArray;
    v7 = ((unsigned int)(size - 4) >> 2) + 1;
    p_z = &pArray[1].z;
    v20 = 4 * v7;
    while ( 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v10 = (char *)p_z + v6;
      *(float *)&v10[(_DWORD)m_pMemory] = *(p_z - 5);
      v11 = (float *)((int)&m_pMemory->x + (_DWORD)v10);
      v11[1] = *(p_z - 4);
      v11[2] = *(p_z - 3);
      v12 = (float *)&v10[(unsigned int)this->m_Memory.m_pMemory + 12];
      *v12 = *(p_z - 2);
      v12[1] = *(p_z - 1);
      v12[2] = *p_z;
      v13 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 4 - (_DWORD)pArray);
      *v13 = p_z[1];
      v13[1] = p_z[2];
      v13[2] = p_z[3];
      v14 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 16 - (_DWORD)pArray);
      v15 = p_z[4];
      p_z += 12;
      --v7;
      *v14 = v15;
      v14[1] = *(p_z - 7);
      v14[2] = *(p_z - 6);
      if ( v7 == 0 )
        break;
      v6 = -20 - (_DWORD)pArray;
    }
    v5 = v20;
    v3 = size;
  }
  if ( v5 < v3 )
  {
    v16 = &pArray[v5].z;
    v17 = v3 - v5;
    do
    {
      v18 = *(v16 - 2);
      v19 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)v16 - 8 - (_DWORD)pArray);
      v16 += 3;
      --v17;
      *v19 = v18;
      v19[1] = *(v16 - 4);
      v19[2] = *(v16 - 3);
    }
    while ( v17 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051B410
// Name: public: void CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>::CopyArray(class Vector4D const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::CopyArray(
        CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *this,
        const Vector4D *pArray,
        int size)
{
  int v3; // edi
  int v5; // eax
  int v6; // edx
  unsigned int v7; // edi
  float *p_z; // eax
  Vector4D *m_pMemory; // ecx
  char *v10; // edx
  float *v11; // ecx
  float *v12; // ecx
  float *v13; // ecx
  float *v14; // ecx
  double v15; // st7
  float *v16; // ecx
  int v17; // edi
  float *v18; // eax
  int v19; // [esp+10h] [ebp-4h]

  v3 = size;
  this->m_Size = 0;
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::InsertMultipleBefore(
    (CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *)this,
    elem: 0,
    num: size);
  v5 = 0;
  if ( size >= 4 )
  {
    v6 = -24 - (_DWORD)pArray;
    v7 = ((unsigned int)(size - 4) >> 2) + 1;
    p_z = &pArray[1].z;
    v19 = 4 * v7;
    while ( 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v10 = (char *)p_z + v6;
      *(float *)&v10[(_DWORD)m_pMemory] = *(p_z - 6);
      v11 = (float *)((int)&m_pMemory->x + (_DWORD)v10);
      v11[1] = *(p_z - 5);
      v11[2] = *(p_z - 4);
      v11[3] = *(p_z - 3);
      v12 = (float *)&v10[(unsigned int)this->m_Memory.m_pMemory + 16];
      *v12 = *(p_z - 2);
      v12[1] = *(p_z - 1);
      v12[2] = *p_z;
      v12[3] = p_z[1];
      v13 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 8 - (_DWORD)pArray);
      *v13 = p_z[2];
      v13[1] = p_z[3];
      v13[2] = p_z[4];
      v13[3] = p_z[5];
      v14 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 24 - (_DWORD)pArray);
      v15 = p_z[6];
      p_z += 16;
      --v7;
      *v14 = v15;
      v14[1] = *(p_z - 9);
      v14[2] = *(p_z - 8);
      v14[3] = *(p_z - 7);
      if ( v7 == 0 )
        break;
      v6 = -24 - (_DWORD)pArray;
    }
    v3 = size;
    v5 = v19;
  }
  if ( v5 < v3 )
  {
    v16 = &pArray[v5].z;
    v17 = v3 - v5;
    do
    {
      v18 = (float *)((char *)v16 + (unsigned int)this->m_Memory.m_pMemory + -8 - (_DWORD)pArray);
      *v18 = *(v16 - 2);
      v16 += 4;
      --v17;
      v18[1] = *(v16 - 5);
      v18[2] = *(v16 - 4);
      v18[3] = *(v16 - 3);
    }
    while ( v17 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051B540
// Name: public: void CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>::CopyArray(class Quaternion const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::CopyArray(
        CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *this,
        const Quaternion *pArray,
        int size)
{
  int v4; // edx
  int v5; // ecx
  Quaternion *v6; // eax
  __int64 v7; // xmm0_8

  this->m_Size = 0;
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>::InsertMultipleBefore(this, elem: 0, num: size);
  if ( size > 0 )
  {
    v4 = size;
    v5 = 0;
    do
    {
      v6 = &this->m_Memory.m_pMemory[v5];
      *(_QWORD *)&v6->x = *(_QWORD *)&pArray[v5].x;
      v7 = *(_QWORD *)&pArray[v5++].z;
      --v4;
      *(_QWORD *)&v6->z = v7;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051B590
// Name: public: void CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>::CopyArray(class VMatrix const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>::CopyArray(
        CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *this,
        const VMatrix *pArray,
        int size)
{
  int v3; // ebx
  int v4; // esi

  v3 = size;
  v4 = 0;
  this->m_Size = 0;
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>::InsertMultipleBefore(this, elem: 0, num: size);
  if ( size > 0 )
  {
    do
    {
      VMatrix::operator=(this: &this->m_Memory.m_pMemory[v4], mOther: &pArray[v4]);
      ++v4;
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051CF00
// Name: public: void CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>::CopyArray(class CUtlBinaryBlock const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::CopyArray(
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *this,
        const CUtlBinaryBlock *pArray,
        int size)
{
  int v4; // ebx
  int v5; // esi

  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this);
  v4 = size;
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertMultipleBefore(this, elem: this->m_Size, num: size);
  if ( size > 0 )
  {
    v5 = 0;
    do
    {
      CUtlString::operator=(this: (CUtlString *)&this->m_Memory.m_pMemory[v5], src: (const CUtlString *)&pArray[v5]);
      ++v5;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051CF50
// Name: public: class CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x13 )
    return (CDmaVar<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0051E400
// Name: public: class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>> const __near & CDmAttribute::GetValue<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_ElementType.u.m_Id = -1;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0xF )
    return (CDmaVar<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0051E470
// Name: public: class CUtlVector<int,class CUtlMemory<int,int>> const __near & CDmAttribute::GetValue<class CUtlVector<int,class CUtlMemory<int,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<int,CUtlMemory<int,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x10 )
    return (CDmaVar<CUtlVector<int,CUtlMemory<int,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<int,CUtlMemory<int,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0051E4D0
// Name: public: class CUtlVector<float,class CUtlMemory<float,int>> const __near & CDmAttribute::GetValue<class CUtlVector<float,class CUtlMemory<float,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<float,CUtlMemory<float,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x11 )
    return (CDmaVar<CUtlVector<float,CUtlMemory<float,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<float,CUtlMemory<float,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0051E530
// Name: public: class CUtlVector<bool,class CUtlMemory<bool,int>> const __near & CDmAttribute::GetValue<class CUtlVector<bool,class CUtlMemory<bool,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<bool,CUtlMemory<bool,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x12 )
    return (CDmaVar<CUtlVector<bool,CUtlMemory<bool,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<bool,CUtlMemory<bool,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0051E590
// Name: public: class CUtlVector<class Color,class CUtlMemory<class Color,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Color,class CUtlMemory<class Color,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Color,CUtlMemory<Color,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x16 )
    return (CDmaVar<CUtlVector<Color,CUtlMemory<Color,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Color,CUtlMemory<Color,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0051E5F0
// Name: public: class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x17 )
    return (CDmaVar<CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0051E650
// Name: public: class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Vector,class CUtlMemory<class Vector,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Vector,CUtlMemory<Vector,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x18 )
    return (CDmaVar<CUtlVector<Vector,CUtlMemory<Vector,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Vector,CUtlMemory<Vector,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0051E6B0
// Name: public: class CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x19 )
    return (CDmaVar<CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0051E710
// Name: public: class CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<QAngle,CUtlMemory<QAngle,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x1A )
    return (CDmaVar<CUtlVector<QAngle,CUtlMemory<QAngle,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<QAngle,CUtlMemory<QAngle,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0051E770
// Name: public: class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x1B )
    return (CDmaVar<CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0051E7D0
// Name: public: class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x1C )
    return (CDmaVar<CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0051E830
// Name: public: class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    atexit(func: `CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x15 )
    return (CDmaVar<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0051E920
// Name: public: class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>> const __near & CDmAttribute::GetValue<class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > > *__thiscall CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>(
        CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_pMemory = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nAllocationCount = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_Memory.m_nGrowSize = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_Size = 0;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage.m_pElements = nullptr;
    `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_pAttribute = nullptr;
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: &`CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal.m_Storage);
    atexit(func: `CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 0x14 )
    return (CDmaVar<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > > *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00520000
// Name: public: void CUtlMemory<class CUtlVector<class CAttributeNode __near *,class CUtlMemory<class CAttributeNode __near *,int>>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
        CUtlMemory<BitmapFontTable_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  BitmapFontTable_t *m_pMemory; // edx
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
      this->m_pMemory = (BitmapFontTable_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (BitmapFontTable_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00520130
// Name: public: bool CUtlVector<class CHitArea __near *,class CUtlMemory<class CHitArea __near *,int>>::FindAndRemove(class CHitArea __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<CHitArea *,CUtlMemory<CHitArea *,int>>::FindAndRemove(
        CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *this,
        vgui::TreeNode **src)
{
  int m_Size; // edx
  int v4; // eax
  vgui::TreeNode **m_pMemory; // ebx
  vgui::TreeNode **i; // ecx
  int v8; // edx

  m_Size = this->m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Memory.m_pMemory;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 == -1 )
    return 0;
  v8 = m_Size - v4 - 1;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v4], src: &m_pMemory[v4 + 1], count: 4 * v8);
  --this->m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00520190
// Name: protected: int CUtlLinkedList<class IUndoElement __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class IUndoElement __near *,int>,int>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal(
        CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> > *this,
        bool multilist)
{
  int result; // eax
  int index; // eax
  int m_nAllocationCount; // ecx
  int v6; // eax
  int v7; // ecx
  UtlLinkedListElem_t<IUndoElement *,int> *v8; // ecx

  result = this->m_FirstFree;
  if ( result != -1 )
  {
    this->m_FirstFree = this->m_Memory.m_pMemory[result].m_Next;
LABEL_23:
    v8 = &this->m_Memory.m_pMemory[result];
    if ( multilist )
    {
      v8->m_Next = -1;
      v8->m_Previous = -1;
    }
    else
    {
      v8->m_Next = result;
      v8->m_Previous = result;
    }
    return result;
  }
  index = this->m_LastAlloc.index;
  if ( index < 0 || (m_nAllocationCount = this->m_Memory.m_nAllocationCount, index >= m_nAllocationCount) )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    result = index + 1;
    if ( result < 0 || result >= m_nAllocationCount )
      result = -1;
  }
  if ( result < 0 || result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v6 = this->m_LastAlloc.index;
    if ( v6 < 0 || (v7 = this->m_Memory.m_nAllocationCount, v6 >= v7) )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      result = (v7 > 0) - 1;
    }
    else
    {
      result = v6 + 1;
      if ( result < 0 || result >= v7 )
        result = -1;
    }
    if ( result < 0 || result >= v7 )
    {
      if ( _executeCount_20 < 10 )
      {
        ++_executeCount_20;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  ++this->m_NumAlloced;
  this->m_LastAlloc.index = result;
  goto LABEL_23;
}

//------------------------------------------------------------------------------
// Address: 0x005209C0
// Name: public: int CUtlLinkedList<class IUndoElement __near *,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<class IUndoElement __near *,int>,int>>::AddToTail(class IUndoElement __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AddToTail(
        CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> > *this,
        IUndoElement **src)
{
  int result; // eax
  int v4; // edi
  UtlLinkedListElem_t<IUndoElement *,int> *v5; // eax
  int m_Tail; // edx
  UtlLinkedListElem_t<IUndoElement *,int> *v7; // esi

  result = CUtlLinkedList<IUndoElement *,int,0,int,CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int>>::AllocInternal(
             this,
             multilist: false);
  v4 = result;
  if ( result != -1 )
  {
    CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
      (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)this,
      elem: result);
    v5 = &this->m_Memory.m_pMemory[v4];
    v5->m_Next = -1;
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = v4;
    if ( m_Tail == -1 )
      this->m_Head = v4;
    else
      this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
    ++this->m_ElementCount;
    v7 = &this->m_Memory.m_pMemory[v4];
    if ( v7 != nullptr )
      v7->m_Element = *src;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00520DE0
// Name: public: class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near & CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>>::operator=(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *__thiscall CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int>>::operator=(
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *this,
        const CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *other)
{
  int m_Size; // edi
  int i; // eax

  m_Size = other->m_Size;
  this->m_Size = 0;
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)this,
    elem: 0,
    num: m_Size);
  for ( i = 0; i < m_Size; ++i )
    this->m_Memory.m_pMemory[i] = other->m_Memory.m_pMemory[i];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00521230
// Name: public: void CUtlMemory<class IDmFormatUpdater __near *,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<IDmFormatUpdater *,int>::Grow(CUtlMemory<S3RGBA,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  S3RGBA *m_pMemory; // edx
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
        m_nAllocationCount = 8;
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
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (S3RGBA *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (S3RGBA *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005264B0
// Name: public: CUtlVector<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,class CUtlMemory<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,int>>::~CUtlVector<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,class CUtlMemory<class CUtlVector<enum DmElementHandle_t,class CUtlMemory<enum DmElementHandle_t,int>>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>::~CUtlVector<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,CUtlMemory<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>,int>>(
        CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *this)
{
  bool v2; // sf
  CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> > *m_pMemory; // eax

  CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005272B0
// Name: public: virtual class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near & CDmElementFramework::GetSortedOperators(void)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *__thiscall CDmElementFramework::GetSortedOperators(
        CDmElementFramework *this)
{
  return &this->m_dependencyGraph.m_operators;
}

//------------------------------------------------------------------------------
// Address: 0x00527A70
// Name: public: int CUtlVector<struct CDmElementDictionary::DmIdPair_t,class CUtlMemory<struct CDmElementDictionary::DmIdPair_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>::InsertMultipleBefore(
        CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDmElementDictionary::DmIdPair_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CDmElementDictionary::DmIdPair_t,int>::Grow(
      (CUtlMemory<vgui::RichText::TFormatStream,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 32 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00527ED0
// Name: public: int CUtlVector<struct CDmxElementDictionary::AttributeInfo_t,class CUtlMemory<struct CDmxElementDictionary::AttributeInfo_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmxElementDictionary::AttributeInfo_t,CUtlMemory<CDmxElementDictionary::AttributeInfo_t,int>>::InsertBefore(
        CUtlVector<CDmxElementDictionary::AttributeInfo_t,CUtlMemory<CDmxElementDictionary::AttributeInfo_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDmxElementDictionary::AttributeInfo_t *m_pMemory; // ecx
  int v6; // eax
  int v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CGameGraphic *,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v7 = v6 - elem - 1;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00528060
// Name: public: int CUtlVector<struct CDmElementDictionary::DmIdPair_t,class CUtlMemory<struct CDmElementDictionary::DmIdPair_t,int>>::InsertBefore(int,struct CDmElementDictionary::DmIdPair_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int>>::InsertBefore(
        CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> > *this,
        int elem,
        const CDmElementDictionary::DmIdPair_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDmElementDictionary::DmIdPair_t *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  CDmElementDictionary::DmIdPair_t *v9; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDmElementDictionary::DmIdPair_t,int>::Grow(
      (CUtlMemory<vgui::RichText::TFormatStream,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  v8 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 >= 0 && !v8 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 32 * v7);
  v9 = &this->m_Memory.m_pMemory[elem];
  if ( v9 != nullptr )
    *v9 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00529740
// Name: public: int CUtlVector<class CUtlVector<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,class CUtlMemory<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,class CUtlMemory<class CUtlVector<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,class CUtlMemory<struct CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::InsertMultipleBefore(
        CUtlVector<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,CUtlMemory<CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> >,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> > *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CUtlVector<CDmElementDictionary::DmIdPair_t,CUtlMemory<CDmElementDictionary::DmIdPair_t,int> > *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
      (CUtlMemory<BitmapFontTable_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_Memory.m_pMemory = nullptr;
          v11->m_Memory.m_nAllocationCount = 0;
          v11->m_Memory.m_nGrowSize = 0;
          v11->m_Size = 0;
          v11->m_pElements = nullptr;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0052D720
// Name: public: int CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlString *m_pMemory; // ecx
  int v6; // eax
  bool v7; // zf
  CUtlString *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  v7 = this->m_Size - elem == 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 >= 0 && !v7 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v6);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CUtlString::CUtlString(this: v8);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0052FA10
// Name: public: int CUtlVector<struct CDmxElementDictionary::DictInfo_t,class CUtlMemory<struct CDmxElementDictionary::DictInfo_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDmxElementDictionary::DictInfo_t,CUtlMemory<CDmxElementDictionary::DictInfo_t,int>>::InsertBefore(
        CUtlVector<CDmxElementDictionary::DictInfo_t,CUtlMemory<CDmxElementDictionary::DictInfo_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDmxElementDictionary::DictInfo_t *m_pMemory; // ecx
  int v6; // eax
  int v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
      (CUtlMemory<BitmapFontTable_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v7 = v6 - elem - 1;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 20 * v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00401DB0
// Name: protected: struct UtlRBTreeLinks_t<unsigned short> const __near & CUtlRBTree<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short,class CUtlMap<char const __near *,int,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(unsigned short)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *__thiscall CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links(
        CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Right = -1;
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Parent = -1;
    `CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel.m_Tag = 1;
  }
  if ( i == 0xFFFF )
    return (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)&`CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i];
}

//------------------------------------------------------------------------------
// Address: 0x004C09C0
// Name: struct datamap_t __near * DataMapInit<struct BitmapGlyph_s>(struct BitmapGlyph_s __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<BitmapGlyph_s>()
{
  if ( (_S1_10 & 1) == 0 )
  {
    _S1_10 |= 1u;
    nameHolder.m_pszBase = "BitmapGlyph_t";
    nameHolder.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder.m_Names.m_Size = 0;
    nameHolder.m_Names.m_pElements = nullptr;
    nameHolder.m_nLenBase = strlen("BitmapGlyph_t");
    atexit(func: DataMapInit_BitmapGlyph_s__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  BitmapGlyph_s::m_DataMap.baseMap = nullptr;
  BitmapGlyph_s::m_DataMap.dataNumFields = 7;
  BitmapGlyph_s::m_DataMap.dataDesc = &dataDesc[1];
  return &BitmapGlyph_s::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x004C0A40
// Name: struct datamap_t __near * DataMapInit<struct BitmapFont_s>(struct BitmapFont_s __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<BitmapFont_s>()
{
  if ( (_S2_1 & 1) == 0 )
  {
    _S2_1 |= 1u;
    nameHolder_0.m_pszBase = "BitmapFont_t";
    nameHolder_0.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_0.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_0.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_0.m_Names.m_Size = 0;
    nameHolder_0.m_Names.m_pElements = nullptr;
    nameHolder_0.m_nLenBase = strlen("BitmapFont_t");
    atexit(func: DataMapInit_BitmapFont_s__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  BitmapFont_s::m_DataMap.baseMap = nullptr;
  BitmapFont_s::m_DataMap.dataNumFields = 10;
  BitmapFont_s::m_DataMap.dataDesc = &dataDesc_0[1];
  return &BitmapFont_s::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x005212C0
// Name: protected: struct UtlRBTreeLinks_t<int> const __near & CUtlRBTree<struct CDmElementSerializationDictionary::ElementInfo_t,int,bool (*)(struct CDmElementSerializationDictionary::ElementInfo_t const __near &,struct CDmElementSerializationDictionary::ElementInfo_t const __near &),class CUtlBlockMemory<struct UtlRBTreeNode_t<struct CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int> *__thiscall CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links(
        CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl*)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Left = -1;
    `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Right = -1;
    `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Parent = -1;
    `CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel.m_Tag = 1;
  }
  if ( i == -1 )
    return (UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int> *)&`CUtlRBTree<CDmElementSerializationDictionary::ElementInfo_t,int,bool (__cdecl *)(CDmElementSerializationDictionary::ElementInfo_t const &,CDmElementSerializationDictionary::ElementInfo_t const &),CUtlBlockMemory<UtlRBTreeNode_t<CDmElementSerializationDictionary::ElementInfo_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    return &this->m_Elements.m_pMemory[i >> (*((int *)&this->m_Elements + 2) >> 27)][i
                                                                                   & ((32
                                                                                     * *((_DWORD *)&this->m_Elements + 2)) >> 5)];
}
