// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/shaderapidx9/meshbase.cpp
// Functions: 15
// ============================================================

#include "materialsystem\shaderapidx9\meshbase.h"

//------------------------------------------------------------------------------
// Address: 0x10003E00
// Name: int GetVertexElementSize(enum VertexElement_t,enum VertexCompressionType_t)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetVertexElementSize(VertexElement_t element, VertexCompressionType_t compressionType)
{
  int result; // eax

  if ( compressionType == VERTEX_COMPRESSION_ON )
  {
    switch ( element )
    {
      case VERTEX_ELEMENT_NORMAL:
      case VERTEX_ELEMENT_BONEWEIGHTS1:
      case VERTEX_ELEMENT_BONEWEIGHTS2:
$LN57:
        result = 4;
        break;
      case VERTEX_ELEMENT_USERDATA4:
$LN1:
        result = 0;
        break;
      default:
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    switch ( element )
    {
      case VERTEX_ELEMENT_POSITION:
      case VERTEX_ELEMENT_NORMAL:
      case VERTEX_ELEMENT_TANGENT_S:
      case VERTEX_ELEMENT_TANGENT_T:
      case VERTEX_ELEMENT_BONEWEIGHTS3:
      case VERTEX_ELEMENT_USERDATA3:
      case VERTEX_ELEMENT_TEXCOORD3D_0:
      case VERTEX_ELEMENT_TEXCOORD3D_1:
      case VERTEX_ELEMENT_TEXCOORD3D_2:
      case VERTEX_ELEMENT_TEXCOORD3D_3:
      case VERTEX_ELEMENT_TEXCOORD3D_4:
      case VERTEX_ELEMENT_TEXCOORD3D_5:
      case VERTEX_ELEMENT_TEXCOORD3D_6:
      case VERTEX_ELEMENT_TEXCOORD3D_7:
        result = 12;
        break;
      case VERTEX_ELEMENT_POSITION4D:
      case VERTEX_ELEMENT_NORMAL4D:
      case VERTEX_ELEMENT_BONEWEIGHTS4:
      case VERTEX_ELEMENT_USERDATA4:
      case VERTEX_ELEMENT_TEXCOORD4D_0:
      case VERTEX_ELEMENT_TEXCOORD4D_1:
      case VERTEX_ELEMENT_TEXCOORD4D_2:
      case VERTEX_ELEMENT_TEXCOORD4D_3:
      case VERTEX_ELEMENT_TEXCOORD4D_4:
      case VERTEX_ELEMENT_TEXCOORD4D_5:
      case VERTEX_ELEMENT_TEXCOORD4D_6:
      case VERTEX_ELEMENT_TEXCOORD4D_7:
        result = 16;
        break;
      case VERTEX_ELEMENT_COLOR:
      case VERTEX_ELEMENT_SPECULAR:
      case VERTEX_ELEMENT_WRINKLE:
      case VERTEX_ELEMENT_BONEINDEX:
      case VERTEX_ELEMENT_BONEWEIGHTS1:
      case VERTEX_ELEMENT_USERDATA1:
      case VERTEX_ELEMENT_TEXCOORD1D_0:
      case VERTEX_ELEMENT_TEXCOORD1D_1:
      case VERTEX_ELEMENT_TEXCOORD1D_2:
      case VERTEX_ELEMENT_TEXCOORD1D_3:
      case VERTEX_ELEMENT_TEXCOORD1D_4:
      case VERTEX_ELEMENT_TEXCOORD1D_5:
      case VERTEX_ELEMENT_TEXCOORD1D_6:
      case VERTEX_ELEMENT_TEXCOORD1D_7:
        goto $LN57;
      case VERTEX_ELEMENT_BONEWEIGHTS2:
      case VERTEX_ELEMENT_USERDATA2:
      case VERTEX_ELEMENT_TEXCOORD2D_0:
      case VERTEX_ELEMENT_TEXCOORD2D_1:
      case VERTEX_ELEMENT_TEXCOORD2D_2:
      case VERTEX_ELEMENT_TEXCOORD2D_3:
      case VERTEX_ELEMENT_TEXCOORD2D_4:
      case VERTEX_ELEMENT_TEXCOORD2D_5:
      case VERTEX_ELEMENT_TEXCOORD2D_6:
      case VERTEX_ELEMENT_TEXCOORD2D_7:
        result = 8;
        break;
      default:
        goto $LN1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10003F40
// Name: public: virtual CVertexBufferBase::~CVertexBufferBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBufferBase::~CVertexBufferBase(CVertexBufferBase *this)
{
  this->__vftable = (CVertexBufferBase_vtbl *)&CVertexBufferBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10003F60
// Name: public: static void CVertexBufferBase::PrintVertexFormat(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CVertexBufferBase::PrintVertexFormat(unsigned __int64 vertexFormat)
{
  const char *v1; // ecx
  int v2; // ebx
  int i; // edi
  int v4; // eax
  char pBuf[256]; // [esp+Ch] [ebp-104h] BYREF
  VertexCompressionType_t compression; // [esp+10Ch] [ebp-4h]

  compression = (vertexFormat & 0x400) != 0;
  if ( (vertexFormat & 1) != 0 )
    _Msg(a1: "VERTEX_POSITION|");
  if ( (vertexFormat & 2) != 0 )
  {
    if ( compression == VERTEX_COMPRESSION_ON )
      _Msg(a1: "VERTEX_NORMAL[COMPRESSED]|");
    else
      _Msg(a1: "VERTEX_NORMAL|");
  }
  if ( (vertexFormat & 4) != 0 )
    _Msg(a1: "VERTEX_COLOR|");
  if ( (vertexFormat & 8) != 0 )
    _Msg(a1: "VERTEX_SPECULAR|");
  if ( (vertexFormat & 0x10) != 0 )
    _Msg(a1: "VERTEX_TANGENT_S|");
  if ( (vertexFormat & 0x20) != 0 )
    _Msg(a1: "VERTEX_TANGENT_T|");
  if ( (vertexFormat & 0x80) != 0 )
    _Msg(a1: "VERTEX_BONE_INDEX|");
  if ( ((vertexFormat >> 12) & 7) != 0 )
  {
    v1 = "[COMPRESSED]";
    if ( compression == VERTEX_COMPRESSION_NONE )
      v1 = pMem;
    V_snprintf(
      pDest: pBuf,
      maxLen: 256,
      pFormat: "VERTEX_BONEWEIGHT(%d)%s|",
      (unsigned __int8)(vertexFormat >> 12) & 7,
      v1);
    _Msg(a1: pBuf);
  }
  if ( ((vertexFormat >> 15) & 7) != 0 )
  {
    V_snprintf(
      pDest: pBuf,
      maxLen: 256,
      pFormat: "VERTEX_USERDATA_SIZE(%d)|",
      (unsigned __int8)(vertexFormat >> 15) & 7);
    _Msg(a1: pBuf);
  }
  v2 = 0;
  for ( i = 18; i < 42; i += 3 )
  {
    v4 = (vertexFormat >> i) & 7;
    if ( v4 != 0 )
    {
      V_snprintf(pDest: pBuf, maxLen: 256, pFormat: "VERTEX_TEXCOORD_SIZE(%d,%d)", v2, v4);
      _Msg(a1: pBuf);
    }
    ++v2;
  }
  _Msg(a1: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x10004110
// Name: public: virtual void CVertexBufferBase::Spew(int,struct VertexDesc_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBufferBase::Spew(CVertexBufferBase *this, int nVertexCount, const VertexDesc_t *desc)
{
  int v4; // ebx
  int v5; // esi
  float *v6; // eax
  int m_VertexSize_Wrinkle; // eax
  float *v8; // eax
  int m_VertexSize_BoneMatrixIndex; // eax
  unsigned __int8 *v10; // eax
  int m_VertexSize_Normal; // eax
  int m_VertexSize_Color; // eax
  unsigned __int8 *v13; // eax
  int v14; // edx
  float *m_VertexSize_TexCoord; // ecx
  float *v16; // eax
  int v17; // eax
  int m_VertexSize_TangentS; // eax
  int m_VertexSize_TangentT; // eax
  unsigned __int64 v20; // [esp+8h] [ebp-424h]
  unsigned __int64 v21; // [esp+8h] [ebp-424h]
  char pTempBuf[1024]; // [esp+24h] [ebp-408h] BYREF
  int nBoneWeightCount; // [esp+424h] [ebp-8h]
  float *pWeight; // [esp+428h] [ebp-4h]
  int j; // [esp+438h] [ebp+Ch]
  int ja; // [esp+438h] [ebp+Ch]

  V_snprintf(
    pDest: pTempBuf,
    maxLen: 1024,
    pFormat: "\nVerts %d (First %d, Offset %d) :\n",
    nVertexCount,
    desc->m_nFirstVertex,
    desc->m_nOffset);
  _Warning(a1: pTempBuf);
  v4 = 0;
  for ( nBoneWeightCount = desc->m_NumBoneWeights; v4 < nVertexCount; ++v4 )
  {
    v5 = V_snprintf(pDest: pTempBuf, maxLen: 1024, pFormat: "[%4d] ", v4 + desc->m_nFirstVertex);
    if ( desc->m_VertexSize_Position != 0 )
    {
      v6 = (float *)((char *)desc->m_pPosition + v4 * desc->m_VertexSize_Position);
      v5 += V_snprintf(pDest: &pTempBuf[v5], maxLen: 1024 - v5, pFormat: "P %8.2f %8.2f %8.2f ", *v6, v6[1], v6[2]);
    }
    m_VertexSize_Wrinkle = desc->m_VertexSize_Wrinkle;
    if ( m_VertexSize_Wrinkle != 0 )
      v5 += V_snprintf(
              pDest: &pTempBuf[v5],
              maxLen: 1024 - v5,
              pFormat: "Wr %8.2f ",
              *(float *)((char *)desc->m_pWrinkle + v4 * m_VertexSize_Wrinkle));
    if ( nBoneWeightCount != 0 )
    {
      v5 += V_snprintf(pDest: &pTempBuf[v5], maxLen: 1024 - v5, pFormat: "BW ");
      v8 = (float *)((char *)desc->m_pBoneWeight + v4 * desc->m_VertexSize_BoneWeight);
      pWeight = v8;
      j = 0;
      if ( nBoneWeightCount > 0 )
      {
        while ( 1 )
        {
          v5 += V_snprintf(pDest: &pTempBuf[v5], maxLen: 1024 - v5, pFormat: "%1.2f ", v8[j++]);
          if ( j >= nBoneWeightCount )
            break;
          v8 = pWeight;
        }
      }
    }
    m_VertexSize_BoneMatrixIndex = desc->m_VertexSize_BoneMatrixIndex;
    if ( m_VertexSize_BoneMatrixIndex != 0 )
    {
      v10 = &desc->m_pBoneMatrixIndex[v4 * m_VertexSize_BoneMatrixIndex];
      v20 = __PAIR64__(v10[1], *v10);
      v5 += V_snprintf(
              pDest: &pTempBuf[v5],
              maxLen: 1024 - v5,
              pFormat: "BI %d %d %d %d ",
              (_DWORD)v20,
              HIDWORD(v20),
              v10[2],
              v10[3]);
    }
    m_VertexSize_Normal = desc->m_VertexSize_Normal;
    if ( m_VertexSize_Normal != 0 )
      v5 += V_snprintf(
              pDest: &pTempBuf[v5],
              maxLen: 1024 - v5,
              pFormat: "N %1.2f %1.2f %1.2f ",
              *(float *)((char *)desc->m_pNormal + v4 * m_VertexSize_Normal),
              *(float *)((char *)desc->m_pNormal + v4 * m_VertexSize_Normal + 4),
              *(float *)((char *)desc->m_pNormal + v4 * m_VertexSize_Normal + 8));
    m_VertexSize_Color = desc->m_VertexSize_Color;
    if ( m_VertexSize_Color != 0 )
    {
      v13 = &desc->m_pColor[v4 * m_VertexSize_Color];
      v21 = __PAIR64__(v13[1], *v13);
      v5 += V_snprintf(
              pDest: &pTempBuf[v5],
              maxLen: 1024 - v5,
              pFormat: "C b %3d g %3d r %3d a %3d ",
              (_DWORD)v21,
              HIDWORD(v21),
              v13[2],
              v13[3]);
    }
    v14 = 0;
    m_VertexSize_TexCoord = (float *)desc->m_VertexSize_TexCoord;
    ja = 0;
    pWeight = (float *)desc->m_VertexSize_TexCoord;
    do
    {
      if ( *(_DWORD *)m_VertexSize_TexCoord != 0 )
      {
        v16 = (float *)(*((_DWORD *)m_VertexSize_TexCoord + 21) + v4 * *(_DWORD *)m_VertexSize_TexCoord);
        v17 = V_snprintf(pDest: &pTempBuf[v5], maxLen: 1024 - v5, pFormat: "T%d %.2f %.2f ", v14, *v16, v16[1]);
        m_VertexSize_TexCoord = pWeight;
        v14 = ja;
        v5 += v17;
      }
      ++v14;
      ++m_VertexSize_TexCoord;
      ja = v14;
      pWeight = m_VertexSize_TexCoord;
    }
    while ( v14 < 8 );
    m_VertexSize_TangentS = desc->m_VertexSize_TangentS;
    if ( m_VertexSize_TangentS != 0 )
      v5 += V_snprintf(
              pDest: &pTempBuf[v5],
              maxLen: 1024 - v5,
              pFormat: "S %1.2f %1.2f %1.2f ",
              *(float *)((char *)desc->m_pTangentS + v4 * m_VertexSize_TangentS),
              *(float *)((char *)desc->m_pTangentS + v4 * m_VertexSize_TangentS + 4),
              *(float *)((char *)desc->m_pTangentS + v4 * m_VertexSize_TangentS + 8));
    m_VertexSize_TangentT = desc->m_VertexSize_TangentT;
    if ( m_VertexSize_TangentT != 0 )
      v5 += V_snprintf(
              pDest: &pTempBuf[v5],
              maxLen: 1024 - v5,
              pFormat: "T %1.2f %1.2f %1.2f ",
              *(float *)((char *)desc->m_pTangentT + v4 * m_VertexSize_TangentT),
              *(float *)((char *)desc->m_pTangentT + v4 * m_VertexSize_TangentT + 4),
              *(float *)((char *)desc->m_pTangentT + v4 * m_VertexSize_TangentT + 8));
    V_snprintf(pDest: &pTempBuf[v5], maxLen: 1024 - v5, pFormat: "\n");
    _Warning(a1: pTempBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100044D0
// Name: public: virtual void CIndexBufferBase::Spew(int,struct IndexDesc_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIndexBufferBase::Spew(CIndexBufferBase *this, int nIndexCount, const IndexDesc_t *indexDesc)
{
  char *v3; // edi
  int v4; // esi
  int i; // ebx
  unsigned int m_nFirstIndex; // [esp-8h] [ebp-214h]
  unsigned int m_nOffset; // [esp-4h] [ebp-210h]
  char pTempBuf[512]; // [esp+Ch] [ebp-200h] BYREF

  m_nOffset = indexDesc->m_nOffset;
  m_nFirstIndex = indexDesc->m_nFirstIndex;
  v3 = pTempBuf;
  v4 = 0;
  pTempBuf[0] = 0;
  V_snprintf(
    pDest: pTempBuf,
    maxLen: 512,
    pFormat: "\nIndices: %d (First %d, Offset %d)\n",
    nIndexCount,
    m_nFirstIndex,
    m_nOffset);
  _Warning(a1: pTempBuf);
  for ( i = 0; i < nIndexCount; ++i )
  {
    v4 += V_snprintf(pDest: v3, maxLen: 511 - v4, pFormat: "%d ", indexDesc->m_pIndices[i]);
    v3 = &pTempBuf[v4];
    if ( (i & 0xF) == 0xF )
    {
      V_snprintf(pDest: &pTempBuf[v4], maxLen: 511 - v4, pFormat: "\n");
      _Warning(a1: pTempBuf);
      pTempBuf[0] = 0;
      v4 = 0;
      v3 = pTempBuf;
    }
  }
  V_snprintf(pDest: v3, maxLen: 511 - v4, pFormat: "\n");
  _Warning(a1: pTempBuf);
}

//------------------------------------------------------------------------------
// Address: 0x100045C0
// Name: public: virtual CMeshBase::~CMeshBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBase::~CMeshBase(CMeshBase *this)
{
  this->IMesh::IVertexBuffer::__vftable = (CMeshBase_vtbl *)&CMeshBase::`vftable'{for `IVertexBuffer'};
  this->IMesh::IIndexBuffer::__vftable = (IIndexBuffer_vtbl *)&CMeshBase::`vftable'{for `IIndexBuffer'};
}

//------------------------------------------------------------------------------
// Address: 0x100045D0
// Name: public: virtual class IMesh __near * CMeshBase::GetMesh(void)
// Source: json
//------------------------------------------------------------------------------
CMeshBase *__thiscall CMeshBase::GetMesh(CMeshBase *this)
{
  return (CMeshBase *)((char *)this - 4);
}

//------------------------------------------------------------------------------
// Address: 0x100045E0
// Name: public: virtual void __near * CMeshBase::AccessRawHardwareDataStream(unsigned char,unsigned int,unsigned int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CMeshBase::AccessRawHardwareDataStream(
        CMeshBase *this,
        unsigned __int8 nRawStreamIndex,
        unsigned int numBytes,
        unsigned int uiFlags,
        unsigned int pvContext)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10004600
// Name: public: CVertexBufferBase::CVertexBufferBase(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVertexBufferBase *__thiscall CVertexBufferBase::CVertexBufferBase(
        CVertexBufferBase *this,
        const char *pBudgetGroupName)
{
  this->__vftable = (CVertexBufferBase_vtbl *)&CVertexBufferBase::`vftable';
  this->m_pBudgetGroupName = pBudgetGroupName;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10004650
// Name: public: CIndexBufferBase::CIndexBufferBase(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CIndexBufferBase *__thiscall CIndexBufferBase::CIndexBufferBase(CIndexBufferBase *this, const char *pBudgetGroupName)
{
  this->__vftable = (CIndexBufferBase_vtbl *)&CIndexBufferBase::`vftable';
  this->m_pBudgetGroupName = pBudgetGroupName;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100046A0
// Name: public: CMeshBase::CMeshBase(void)
// Source: json
//------------------------------------------------------------------------------
CMeshBase *__thiscall CMeshBase::CMeshBase(CMeshBase *this)
{
  this->IMesh::IIndexBuffer::__vftable = (IIndexBuffer_vtbl *)&IIndexBuffer::`vftable';
  this->IMesh::IVertexBuffer::__vftable = (CMeshBase_vtbl *)&CMeshBase::`vftable'{for `IVertexBuffer'};
  this->IMesh::IIndexBuffer::__vftable = (IIndexBuffer_vtbl *)&CMeshBase::`vftable'{for `IIndexBuffer'};
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100046F0
// Name: int ComputeVertexDesc<0>(unsigned char __near *,unsigned __int64,struct VertexDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ComputeVertexDesc<0>(float *pBuffer, unsigned __int64 vertexFormat, VertexDesc_t *desc)
{
  int v4; // ebx
  int v5; // eax
  int v6; // esi
  int v7; // esi
  unsigned __int8 *v8; // eax
  int v9; // eax
  unsigned __int8 *v10; // eax
  int v11; // ebx
  int *m_VertexSize_TexCoord; // esi
  int v13; // eax
  int v14; // ecx
  char *v15; // eax
  int v16; // ecx
  int v17; // eax
  int v18; // ecx
  signed int v19; // esi
  int v20; // ecx
  int j; // eax
  int *v22; // edx
  int *pVertexSizesToSet[64]; // [esp+4h] [ebp-10Ch]
  int i; // [esp+104h] [ebp-Ch]
  VertexCompressionType_t compression; // [esp+108h] [ebp-8h]
  int nVertexSizesToSet; // [esp+10Ch] [ebp-4h]
  int offset; // [esp+124h] [ebp+14h]

  nVertexSizesToSet = 0;
  if ( (`ComputeVertexDesc<0>'::`2'::`local static guard' & 1) == 0 )
    `ComputeVertexDesc<0>'::`2'::`local static guard' |= 1u;
  compression = (vertexFormat & 0x400) != 0;
  desc->m_CompressionType = compression;
  v4 = 0;
  desc->m_NumBoneWeights = (vertexFormat >> 12) & 7;
  offset = 0;
  if ( (vertexFormat & 1) != 0 )
  {
    desc->m_pPosition = pBuffer;
    pVertexSizesToSet[0] = &desc->m_VertexSize_Position;
    nVertexSizesToSet = 1;
    switch ( (vertexFormat & 0x800) != 0 )
    {
      case false:
        v5 = 12;
        break;
      case true:
        v5 = 16;
        break;
    }
    v4 = v5;
    offset = v5;
    if ( (vertexFormat & 0x40) != 0 )
    {
      v4 = v5 + 4;
      desc->m_pWrinkle = &pBuffer[v5 / 4u];
      pVertexSizesToSet[1] = &desc->m_VertexSize_Wrinkle;
      nVertexSizesToSet = 2;
      offset = v5 + 4;
    }
    else
    {
      desc->m_pWrinkle = (float *)`ComputeVertexDesc<0>'::`2'::temp;
      desc->m_VertexSize_Wrinkle = 0;
    }
  }
  else
  {
    desc->m_pPosition = (float *)`ComputeVertexDesc<0>'::`2'::temp;
    desc->m_VertexSize_Position = 0;
    desc->m_pWrinkle = (float *)`ComputeVertexDesc<0>'::`2'::temp;
    desc->m_VertexSize_Wrinkle = 0;
  }
  if ( (vertexFormat & 0x80) != 0 )
  {
    v6 = nVertexSizesToSet;
    if ( ((vertexFormat >> 12) & 7) != 0 )
    {
      desc->m_pBoneWeight = (float *)((char *)pBuffer + v4);
      pVertexSizesToSet[v6++] = &desc->m_VertexSize_BoneWeight;
      v4 += 4 * (compression != VERTEX_COMPRESSION_ON) + 4;
    }
    else
    {
      desc->m_pBoneWeight = (float *)`ComputeVertexDesc<0>'::`2'::temp;
      desc->m_VertexSize_BoneWeight = 0;
    }
    pVertexSizesToSet[v6] = &desc->m_VertexSize_BoneMatrixIndex;
    v7 = v6 + 1;
    v8 = (unsigned __int8 *)pBuffer + v4;
    v4 += 4;
    nVertexSizesToSet = v7;
    offset = v4;
  }
  else
  {
    v7 = nVertexSizesToSet;
    v8 = (unsigned __int8 *)`ComputeVertexDesc<0>'::`2'::temp;
    desc->m_pBoneWeight = (float *)`ComputeVertexDesc<0>'::`2'::temp;
    desc->m_VertexSize_BoneWeight = 0;
    desc->m_VertexSize_BoneMatrixIndex = 0;
  }
  desc->m_pBoneMatrixIndex = v8;
  if ( (vertexFormat & 2) != 0 )
  {
    desc->m_pNormal = (float *)((char *)pBuffer + v4);
    pVertexSizesToSet[v7++] = &desc->m_VertexSize_Normal;
    nVertexSizesToSet = v7;
    v9 = 3;
    if ( (vertexFormat & 0x800) == 0 )
      v9 = 2;
    if ( compression == VERTEX_COMPRESSION_ON && v9 == 2 )
    {
$LN597:
      v4 += 4;
      offset = v4;
    }
    else
    {
      switch ( v9 )
      {
        case 0:
        case 2:
        case 6:
        case 7:
        case 12:
        case 16:
        case 34:
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
        case 41:
          v4 += 12;
          offset = v4;
          break;
        case 1:
        case 3:
        case 13:
        case 17:
        case 42:
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
        case 48:
        case 49:
          v4 += 16;
          offset = v4;
          break;
        case 4:
        case 5:
        case 8:
        case 9:
        case 10:
        case 14:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
          goto $LN597;
        case 11:
        case 15:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        case 33:
          v4 += 8;
          offset = v4;
          break;
        default:
          offset = v4;
          break;
      }
    }
  }
  else
  {
    desc->m_pNormal = (float *)`ComputeVertexDesc<0>'::`2'::temp;
    desc->m_VertexSize_Normal = 0;
  }
  if ( (vertexFormat & 4) != 0 )
  {
    v10 = (unsigned __int8 *)pBuffer + v4;
    pVertexSizesToSet[v7++] = &desc->m_VertexSize_Color;
    v4 += 4;
    desc->m_pColor = v10;
    nVertexSizesToSet = v7;
    offset = v4;
  }
  else
  {
    desc->m_pColor = (unsigned __int8 *)`ComputeVertexDesc<0>'::`2'::temp;
    desc->m_VertexSize_Color = 0;
  }
  if ( (vertexFormat & 8) != 0 )
  {
    pVertexSizesToSet[v7] = &desc->m_VertexSize_Specular;
    desc->m_pSpecular = (unsigned __int8 *)pBuffer + v4;
    nVertexSizesToSet = v7 + 1;
    offset = v4 + 4;
  }
  else
  {
    desc->m_pSpecular = (unsigned __int8 *)`ComputeVertexDesc<0>'::`2'::temp;
    desc->m_VertexSize_Specular = 0;
  }
  i = 0;
  v11 = 18;
  m_VertexSize_TexCoord = desc->m_VertexSize_TexCoord;
  do
  {
    v13 = (vertexFormat >> v11) & 7;
    if ( v13 != 0 )
    {
      v14 = nVertexSizesToSet;
      m_VertexSize_TexCoord[21] = (int)pBuffer + offset;
      v15 = (char *)*(&off_100F6CB0 + v13) + i;
      pVertexSizesToSet[v14] = m_VertexSize_TexCoord;
      nVertexSizesToSet = v14 + 1;
      if ( compression == VERTEX_COMPRESSION_ON )
      {
        switch ( (unsigned int)v15 )
        {
          case 2u:
          case 0xAu:
          case 0xBu:
$LN950:
            offset += 4;
            break;
          case 0x11u:
            break;
          default:
            goto LABEL_40;
        }
      }
      else
      {
LABEL_40:
        switch ( (unsigned int)v15 )
        {
          case 0u:
          case 2u:
          case 6u:
          case 7u:
          case 0xCu:
          case 0x10u:
          case 0x22u:
          case 0x23u:
          case 0x24u:
          case 0x25u:
          case 0x26u:
          case 0x27u:
          case 0x28u:
          case 0x29u:
            offset += 12;
            break;
          case 1u:
          case 3u:
          case 0xDu:
          case 0x11u:
          case 0x2Au:
          case 0x2Bu:
          case 0x2Cu:
          case 0x2Du:
          case 0x2Eu:
          case 0x2Fu:
          case 0x30u:
          case 0x31u:
            offset += 16;
            break;
          case 4u:
          case 5u:
          case 8u:
          case 9u:
          case 0xAu:
          case 0xEu:
          case 0x12u:
          case 0x13u:
          case 0x14u:
          case 0x15u:
          case 0x16u:
          case 0x17u:
          case 0x18u:
          case 0x19u:
            goto $LN950;
          case 0xBu:
          case 0xFu:
          case 0x1Au:
          case 0x1Bu:
          case 0x1Cu:
          case 0x1Du:
          case 0x1Eu:
          case 0x1Fu:
          case 0x20u:
          case 0x21u:
            offset += 8;
            break;
          default:
            break;
        }
      }
    }
    else
    {
      m_VertexSize_TexCoord[21] = (int)`ComputeVertexDesc<0>'::`2'::temp;
      *m_VertexSize_TexCoord = 0;
    }
    ++i;
    v11 += 3;
    ++m_VertexSize_TexCoord;
  }
  while ( v11 < 42 );
  if ( (vertexFormat & 0x10) != 0 )
  {
    desc->m_pTangentS = (float *)((char *)pBuffer + offset);
    v16 = nVertexSizesToSet;
    pVertexSizesToSet[nVertexSizesToSet] = &desc->m_VertexSize_TangentS;
    nVertexSizesToSet = v16 + 1;
    offset += 12;
  }
  else
  {
    desc->m_pTangentS = (float *)`ComputeVertexDesc<0>'::`2'::temp;
    desc->m_VertexSize_TangentS = 0;
  }
  if ( (vertexFormat & 0x20) != 0 )
  {
    desc->m_pTangentT = (float *)((char *)pBuffer + offset);
    v17 = nVertexSizesToSet;
    pVertexSizesToSet[nVertexSizesToSet] = &desc->m_VertexSize_TangentT;
    offset += 12;
    nVertexSizesToSet = v17 + 1;
  }
  else
  {
    desc->m_pTangentT = (float *)`ComputeVertexDesc<0>'::`2'::temp;
    desc->m_VertexSize_TangentT = 0;
  }
  if ( ((vertexFormat >> 15) & 7) != 0 )
  {
    desc->m_pUserData = (float *)((char *)pBuffer + offset);
    v18 = nVertexSizesToSet;
    pVertexSizesToSet[nVertexSizesToSet] = &desc->m_VertexSize_UserData;
    nVertexSizesToSet = v18 + 1;
    if ( compression == VERTEX_COMPRESSION_ON )
    {
      switch ( (vertexFormat >> 15) & 7 )
      {
        case 0xFFFFFFFFFFFFFFF5uLL:
        case 0xFFFFFFFFFFFFFFFDuLL:
        case 0xFFFFFFFFFFFFFFFEuLL:
$LN1303:
          v19 = offset + 4;
          break;
        case 4uLL:
$LN1247:
          v19 = offset;
          break;
        default:
          goto LABEL_56;
      }
    }
    else
    {
LABEL_56:
      switch ( (vertexFormat >> 15) & 7 )
      {
        case 0xFFFFFFFFFFFFFFF3uLL:
        case 0xFFFFFFFFFFFFFFF5uLL:
        case 0xFFFFFFFFFFFFFFF9uLL:
        case 0xFFFFFFFFFFFFFFFAuLL:
        case 0xFFFFFFFFFFFFFFFFuLL:
        case 3uLL:
        case 0x15uLL:
        case 0x16uLL:
        case 0x17uLL:
        case 0x18uLL:
        case 0x19uLL:
        case 0x1AuLL:
        case 0x1BuLL:
        case 0x1CuLL:
          v19 = offset + 12;
          break;
        case 0xFFFFFFFFFFFFFFF4uLL:
        case 0xFFFFFFFFFFFFFFF6uLL:
        case 0uLL:
        case 4uLL:
        case 0x1DuLL:
        case 0x1EuLL:
        case 0x1FuLL:
        case 0x20uLL:
        case 0x21uLL:
        case 0x22uLL:
        case 0x23uLL:
        case 0x24uLL:
          v19 = offset + 16;
          break;
        case 0xFFFFFFFFFFFFFFF7uLL:
        case 0xFFFFFFFFFFFFFFF8uLL:
        case 0xFFFFFFFFFFFFFFFBuLL:
        case 0xFFFFFFFFFFFFFFFCuLL:
        case 0xFFFFFFFFFFFFFFFDuLL:
        case 1uLL:
        case 5uLL:
        case 6uLL:
        case 7uLL:
        case 8uLL:
        case 9uLL:
        case 0xAuLL:
        case 0xBuLL:
        case 0xCuLL:
          goto $LN1303;
        case 0xFFFFFFFFFFFFFFFEuLL:
        case 2uLL:
        case 0xDuLL:
        case 0xEuLL:
        case 0xFuLL:
        case 0x10uLL:
        case 0x11uLL:
        case 0x12uLL:
        case 0x13uLL:
        case 0x14uLL:
          v19 = offset + 8;
          break;
        default:
          goto $LN1247;
      }
    }
  }
  else
  {
    v19 = offset;
    desc->m_pUserData = (float *)`ComputeVertexDesc<0>'::`2'::temp;
    desc->m_VertexSize_UserData = 0;
  }
  if ( (vertexFormat & 0x200) == 0 && v19 > 16 )
    v19 = (v19 + 15) & 0xFFFFFFF0;
  v20 = nVertexSizesToSet;
  desc->m_ActualVertexSize = v19;
  for ( j = 0; j < v20; *v22 = v19 )
    v22 = pVertexSizesToSet[j++];
  return v19;
}

//------------------------------------------------------------------------------
// Address: 0x10004F50
// Name: int ComputeVertexDesc<1>(unsigned char __near *,unsigned __int64,struct VertexDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl ComputeVertexDesc<1>(unsigned __int8 *pBuffer, unsigned __int64 vertexFormat, VertexDesc_t *desc)
{
  int v3; // edx
  int v4; // edi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // edi
  int i; // esi
  int v10; // eax
  char *v11; // eax
  int v12; // edx
  int v13; // eax
  unsigned int result; // eax
  VertexCompressionType_t compression; // [esp+0h] [ebp-8h]
  int offset; // [esp+4h] [ebp-4h]

  v3 = 1;
  if ( (`ComputeVertexDesc<1>'::`2'::`local static guard' & 1) == 0 )
    `ComputeVertexDesc<1>'::`2'::`local static guard' |= 1u;
  if ( (vertexFormat & 0x400) == 0 )
    v3 = 0;
  v4 = 0;
  compression = v3;
  offset = 0;
  if ( (vertexFormat & 1) != 0 )
  {
    switch ( (vertexFormat & 0x800) != 0 )
    {
      case false:
        v5 = 12;
        break;
      case true:
        v5 = 16;
        break;
    }
    v4 = v5;
    offset = v5;
    if ( (vertexFormat & 0x40) != 0 )
    {
      v4 = v5 + 4;
      offset = v5 + 4;
    }
  }
  if ( (vertexFormat & 0x80) != 0 )
  {
    if ( ((vertexFormat >> 12) & 7) != 0 )
      v4 += 4 * (v3 != 1) + 4;
    v4 += 4;
    offset = v4;
  }
  if ( (vertexFormat & 2) != 0 )
  {
    v6 = 3;
    if ( (vertexFormat & 0x800) == 0 )
      v6 = 2;
    if ( v3 == 1 && v6 == 2 )
    {
$LN597_0:
      v7 = 4;
    }
    else
    {
      switch ( v6 )
      {
        case 0:
        case 2:
        case 6:
        case 7:
        case 12:
        case 16:
        case 34:
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
        case 41:
          v7 = 12;
          break;
        case 1:
        case 3:
        case 13:
        case 17:
        case 42:
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
        case 48:
        case 49:
          v7 = 16;
          break;
        case 4:
        case 5:
        case 8:
        case 9:
        case 10:
        case 14:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
          goto $LN597_0;
        case 11:
        case 15:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        case 33:
          v7 = 8;
          break;
        default:
          v7 = 0;
          break;
      }
    }
    v4 += v7;
    offset = v4;
  }
  if ( (vertexFormat & 4) != 0 )
  {
    v4 += 4;
    offset = v4;
  }
  if ( (vertexFormat & 8) != 0 )
    offset = v4 + 4;
  v8 = 0;
  for ( i = 18; i < 42; i += 3 )
  {
    v10 = (vertexFormat >> i) & 7;
    if ( v10 != 0 )
    {
      v11 = (char *)*(&off_100F6CB0 + v10) + v8;
      if ( compression == VERTEX_COMPRESSION_ON )
      {
        switch ( (unsigned int)v11 )
        {
          case 2u:
          case 0xAu:
          case 0xBu:
$LN950_0:
            v12 = offset + 4;
            offset += 4;
            break;
          case 0x11u:
$LN894_0:
            v12 = offset;
            break;
          default:
            goto LABEL_36;
        }
      }
      else
      {
LABEL_36:
        switch ( (unsigned int)v11 )
        {
          case 0u:
          case 2u:
          case 6u:
          case 7u:
          case 0xCu:
          case 0x10u:
          case 0x22u:
          case 0x23u:
          case 0x24u:
          case 0x25u:
          case 0x26u:
          case 0x27u:
          case 0x28u:
          case 0x29u:
            v12 = offset + 12;
            offset += 12;
            break;
          case 1u:
          case 3u:
          case 0xDu:
          case 0x11u:
          case 0x2Au:
          case 0x2Bu:
          case 0x2Cu:
          case 0x2Du:
          case 0x2Eu:
          case 0x2Fu:
          case 0x30u:
          case 0x31u:
            v12 = offset + 16;
            offset += 16;
            break;
          case 4u:
          case 5u:
          case 8u:
          case 9u:
          case 0xAu:
          case 0xEu:
          case 0x12u:
          case 0x13u:
          case 0x14u:
          case 0x15u:
          case 0x16u:
          case 0x17u:
          case 0x18u:
          case 0x19u:
            goto $LN950_0;
          case 0xBu:
          case 0xFu:
          case 0x1Au:
          case 0x1Bu:
          case 0x1Cu:
          case 0x1Du:
          case 0x1Eu:
          case 0x1Fu:
          case 0x20u:
          case 0x21u:
            v12 = offset + 8;
            offset += 8;
            break;
          default:
            goto $LN894_0;
        }
      }
    }
    else
    {
      v12 = offset;
    }
    ++v8;
  }
  if ( (vertexFormat & 0x10) != 0 )
    v12 += 12;
  if ( (vertexFormat & 0x20) != 0 )
    v12 += 12;
  if ( ((vertexFormat >> 15) & 7) != 0 )
  {
    if ( compression == VERTEX_COMPRESSION_ON )
    {
      switch ( (vertexFormat >> 15) & 7 )
      {
        case 0xFFFFFFFFFFFFFFF5uLL:
        case 0xFFFFFFFFFFFFFFFDuLL:
        case 0xFFFFFFFFFFFFFFFEuLL:
$LN1303_0:
          v13 = 4;
          break;
        case 4uLL:
$LN1247_0:
          v13 = 0;
          break;
        default:
          goto LABEL_51;
      }
    }
    else
    {
LABEL_51:
      switch ( (vertexFormat >> 15) & 7 )
      {
        case 0xFFFFFFFFFFFFFFF3uLL:
        case 0xFFFFFFFFFFFFFFF5uLL:
        case 0xFFFFFFFFFFFFFFF9uLL:
        case 0xFFFFFFFFFFFFFFFAuLL:
        case 0xFFFFFFFFFFFFFFFFuLL:
        case 3uLL:
        case 0x15uLL:
        case 0x16uLL:
        case 0x17uLL:
        case 0x18uLL:
        case 0x19uLL:
        case 0x1AuLL:
        case 0x1BuLL:
        case 0x1CuLL:
          v13 = 12;
          break;
        case 0xFFFFFFFFFFFFFFF4uLL:
        case 0xFFFFFFFFFFFFFFF6uLL:
        case 0uLL:
        case 4uLL:
        case 0x1DuLL:
        case 0x1EuLL:
        case 0x1FuLL:
        case 0x20uLL:
        case 0x21uLL:
        case 0x22uLL:
        case 0x23uLL:
        case 0x24uLL:
          v13 = 16;
          break;
        case 0xFFFFFFFFFFFFFFF7uLL:
        case 0xFFFFFFFFFFFFFFF8uLL:
        case 0xFFFFFFFFFFFFFFFBuLL:
        case 0xFFFFFFFFFFFFFFFCuLL:
        case 0xFFFFFFFFFFFFFFFDuLL:
        case 1uLL:
        case 5uLL:
        case 6uLL:
        case 7uLL:
        case 8uLL:
        case 9uLL:
        case 0xAuLL:
        case 0xBuLL:
        case 0xCuLL:
          goto $LN1303_0;
        case 0xFFFFFFFFFFFFFFFEuLL:
        case 2uLL:
        case 0xDuLL:
        case 0xEuLL:
        case 0xFuLL:
        case 0x10uLL:
        case 0x11uLL:
        case 0x12uLL:
        case 0x13uLL:
        case 0x14uLL:
          v13 = 8;
          break;
        default:
          goto $LN1247_0;
      }
    }
    v12 += v13;
  }
  if ( (vertexFormat & 0x200) != 0 )
  {
    desc->m_ActualVertexSize = v12;
    return v12;
  }
  else if ( v12 <= 16 )
  {
    desc->m_ActualVertexSize = v12;
    return v12;
  }
  else
  {
    result = (v12 + 15) & 0xFFFFFFF0;
    desc->m_ActualVertexSize = result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100055B0
// Name: public: static void CVertexBufferBase::ComputeVertexDescription(unsigned char __near *,unsigned __int64,struct VertexDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CVertexBufferBase::ComputeVertexDescription(
        float *pBuffer,
        unsigned __int64 vertexFormat,
        VertexDesc_t *desc)
{
  ComputeVertexDesc<0>(pBuffer, vertexFormat, desc);
}

//------------------------------------------------------------------------------
// Address: 0x100055D0
// Name: public: static int CVertexBufferBase::VertexFormatSize(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl CVertexBufferBase::VertexFormatSize(unsigned __int64 vertexFormat)
{
  VertexDesc_t desc; // [esp+0h] [ebp-A4h] BYREF

  return ComputeVertexDesc<1>(pBuffer: nullptr, vertexFormat, &desc);
}

// ============================================================
// Overlay from shaderapidx10 (Missing functions)
// ============================================================
namespace shaderapidx10 {

//------------------------------------------------------------------------------
// Address: 0x10003D20
// Name: int GetVertexElementSize(enum VertexElement_t,enum VertexCompressionType_t)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetVertexElementSize(VertexElement_t element, VertexCompressionType_t compressionType)
{
  int result; // eax

  if ( compressionType == VERTEX_COMPRESSION_ON )
  {
    switch ( element )
    {
      case VERTEX_ELEMENT_NORMAL:
      case VERTEX_ELEMENT_BONEWEIGHTS1:
      case VERTEX_ELEMENT_BONEWEIGHTS2:
$LN57:
        result = 4;
        break;
      case VERTEX_ELEMENT_USERDATA4:
$LN1:
        result = 0;
        break;
      default:
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    switch ( element )
    {
      case VERTEX_ELEMENT_POSITION:
      case VERTEX_ELEMENT_NORMAL:
      case VERTEX_ELEMENT_TANGENT_S:
      case VERTEX_ELEMENT_TANGENT_T:
      case VERTEX_ELEMENT_BONEWEIGHTS3:
      case VERTEX_ELEMENT_USERDATA3:
      case VERTEX_ELEMENT_TEXCOORD3D_0:
      case VERTEX_ELEMENT_TEXCOORD3D_1:
      case VERTEX_ELEMENT_TEXCOORD3D_2:
      case VERTEX_ELEMENT_TEXCOORD3D_3:
      case VERTEX_ELEMENT_TEXCOORD3D_4:
      case VERTEX_ELEMENT_TEXCOORD3D_5:
      case VERTEX_ELEMENT_TEXCOORD3D_6:
      case VERTEX_ELEMENT_TEXCOORD3D_7:
        result = 12;
        break;
      case VERTEX_ELEMENT_POSITION4D:
      case VERTEX_ELEMENT_NORMAL4D:
      case VERTEX_ELEMENT_BONEWEIGHTS4:
      case VERTEX_ELEMENT_USERDATA4:
      case VERTEX_ELEMENT_TEXCOORD4D_0:
      case VERTEX_ELEMENT_TEXCOORD4D_1:
      case VERTEX_ELEMENT_TEXCOORD4D_2:
      case VERTEX_ELEMENT_TEXCOORD4D_3:
      case VERTEX_ELEMENT_TEXCOORD4D_4:
      case VERTEX_ELEMENT_TEXCOORD4D_5:
      case VERTEX_ELEMENT_TEXCOORD4D_6:
      case VERTEX_ELEMENT_TEXCOORD4D_7:
        result = 16;
        break;
      case VERTEX_ELEMENT_COLOR:
      case VERTEX_ELEMENT_SPECULAR:
      case VERTEX_ELEMENT_WRINKLE:
      case VERTEX_ELEMENT_BONEINDEX:
      case VERTEX_ELEMENT_BONEWEIGHTS1:
      case VERTEX_ELEMENT_USERDATA1:
      case VERTEX_ELEMENT_TEXCOORD1D_0:
      case VERTEX_ELEMENT_TEXCOORD1D_1:
      case VERTEX_ELEMENT_TEXCOORD1D_2:
      case VERTEX_ELEMENT_TEXCOORD1D_3:
      case VERTEX_ELEMENT_TEXCOORD1D_4:
      case VERTEX_ELEMENT_TEXCOORD1D_5:
      case VERTEX_ELEMENT_TEXCOORD1D_6:
      case VERTEX_ELEMENT_TEXCOORD1D_7:
        goto $LN57;
      case VERTEX_ELEMENT_BONEWEIGHTS2:
      case VERTEX_ELEMENT_USERDATA2:
      case VERTEX_ELEMENT_TEXCOORD2D_0:
      case VERTEX_ELEMENT_TEXCOORD2D_1:
      case VERTEX_ELEMENT_TEXCOORD2D_2:
      case VERTEX_ELEMENT_TEXCOORD2D_3:
      case VERTEX_ELEMENT_TEXCOORD2D_4:
      case VERTEX_ELEMENT_TEXCOORD2D_5:
      case VERTEX_ELEMENT_TEXCOORD2D_6:
      case VERTEX_ELEMENT_TEXCOORD2D_7:
        result = 8;
        break;
      default:
        goto $LN1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10003E50
// Name: public: virtual CVertexBufferBase::~CVertexBufferBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBufferBase::~CVertexBufferBase(CVertexBufferBase *this)
{
  this->__vftable = (CVertexBufferBase_vtbl *)&CVertexBufferBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10003E60
// Name: public: static void CVertexBufferBase::PrintVertexFormat(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CVertexBufferBase::PrintVertexFormat(unsigned __int64 vertexFormat)
{
  const char *v1; // ecx
  int v2; // ebx
  int i; // edi
  int v4; // eax
  char pBuf[260]; // [esp+Ch] [ebp-104h] BYREF

  if ( (vertexFormat & 1) != 0 )
    _Msg(a1: "VERTEX_POSITION|");
  if ( (vertexFormat & 2) != 0 )
  {
    if ( (vertexFormat & 0x400) != 0 )
      _Msg(a1: "VERTEX_NORMAL[COMPRESSED]|");
    else
      _Msg(a1: "VERTEX_NORMAL|");
  }
  if ( (vertexFormat & 4) != 0 )
    _Msg(a1: "VERTEX_COLOR|");
  if ( (vertexFormat & 8) != 0 )
    _Msg(a1: "VERTEX_SPECULAR|");
  if ( (vertexFormat & 0x10) != 0 )
    _Msg(a1: "VERTEX_TANGENT_S|");
  if ( (vertexFormat & 0x20) != 0 )
    _Msg(a1: "VERTEX_TANGENT_T|");
  if ( (vertexFormat & 0x80) != 0 )
    _Msg(a1: "VERTEX_BONE_INDEX|");
  if ( ((vertexFormat >> 12) & 7) != 0 )
  {
    v1 = "[COMPRESSED]";
    if ( (vertexFormat & 0x400) == 0 )
      v1 = str;
    V_snprintf(
      pDest: &pBuf[4],
      maxLen: 256,
      pFormat: "VERTEX_BONEWEIGHT(%d)%s|",
      (unsigned __int8)(vertexFormat >> 12) & 7,
      v1);
    _Msg(a1: &pBuf[4]);
  }
  if ( ((vertexFormat >> 15) & 7) != 0 )
  {
    V_snprintf(
      pDest: &pBuf[4],
      maxLen: 256,
      pFormat: "VERTEX_USERDATA_SIZE(%d)|",
      (unsigned __int8)(vertexFormat >> 15) & 7);
    _Msg(a1: &pBuf[4]);
  }
  v2 = 0;
  for ( i = 18; i < 42; i += 3 )
  {
    v4 = (vertexFormat >> i) & 7;
    if ( v4 != 0 )
    {
      V_snprintf(pDest: &pBuf[4], maxLen: 256, pFormat: "VERTEX_TEXCOORD_SIZE(%d,%d)", v2, v4);
      _Msg(a1: &pBuf[4]);
    }
    ++v2;
  }
  _Msg(a1: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x10004000
// Name: public: virtual void CVertexBufferBase::Spew(int,struct VertexDesc_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBufferBase::Spew(CVertexBufferBase *this, int nVertexCount, const VertexDesc_t *desc)
{
  int v3; // ebx
  int v4; // esi
  float *v5; // eax
  int m_VertexSize_Wrinkle; // eax
  float *v7; // eax
  int m_VertexSize_BoneMatrixIndex; // eax
  unsigned __int8 *v9; // eax
  int m_VertexSize_Normal; // eax
  int m_VertexSize_Color; // eax
  unsigned __int8 *v12; // eax
  int v13; // edx
  int *m_VertexSize_TexCoord; // ecx
  float *v15; // eax
  int v16; // eax
  int m_VertexSize_TangentS; // eax
  int m_VertexSize_TangentT; // eax
  unsigned __int64 v19; // [esp+8h] [ebp-450h]
  unsigned __int64 v20; // [esp+8h] [ebp-450h]
  int j; // [esp+4Ch] [ebp-40Ch]
  int ja; // [esp+4Ch] [ebp-40Ch]
  float *pWeight; // [esp+50h] [ebp-408h]
  int *pWeighta; // [esp+50h] [ebp-408h]
  int nBoneWeightCount; // [esp+54h] [ebp-404h]
  char pTempBuf[1024]; // [esp+58h] [ebp-400h] BYREF

  V_snprintf(
    pDest: pTempBuf,
    maxLen: 1024,
    pFormat: "\nVerts %d (First %d, Offset %d) :\n",
    nVertexCount,
    desc->m_nFirstVertex,
    desc->m_nOffset);
  _Warning(a1: pTempBuf);
  v3 = 0;
  for ( nBoneWeightCount = desc->m_NumBoneWeights; v3 < nVertexCount; ++v3 )
  {
    v4 = V_snprintf(pDest: pTempBuf, maxLen: 1024, pFormat: "[%4d] ", v3 + desc->m_nFirstVertex);
    if ( desc->m_VertexSize_Position != 0 )
    {
      v5 = (float *)((char *)desc->m_pPosition + v3 * desc->m_VertexSize_Position);
      v4 += V_snprintf(pDest: &pTempBuf[v4], maxLen: 1024 - v4, pFormat: "P %8.2f %8.2f %8.2f ", *v5, v5[1], v5[2]);
    }
    m_VertexSize_Wrinkle = desc->m_VertexSize_Wrinkle;
    if ( m_VertexSize_Wrinkle != 0 )
      v4 += V_snprintf(
              pDest: &pTempBuf[v4],
              maxLen: 1024 - v4,
              pFormat: "Wr %8.2f ",
              *(float *)((char *)desc->m_pWrinkle + v3 * m_VertexSize_Wrinkle));
    if ( nBoneWeightCount != 0 )
    {
      v4 += V_snprintf(pDest: &pTempBuf[v4], maxLen: 1024 - v4, pFormat: "BW ");
      v7 = (float *)((char *)desc->m_pBoneWeight + v3 * desc->m_VertexSize_BoneWeight);
      pWeight = v7;
      j = 0;
      if ( nBoneWeightCount > 0 )
      {
        while ( 1 )
        {
          v4 += V_snprintf(pDest: &pTempBuf[v4], maxLen: 1024 - v4, pFormat: "%1.2f ", v7[j++]);
          if ( j >= nBoneWeightCount )
            break;
          v7 = pWeight;
        }
      }
    }
    m_VertexSize_BoneMatrixIndex = desc->m_VertexSize_BoneMatrixIndex;
    if ( m_VertexSize_BoneMatrixIndex != 0 )
    {
      v9 = &desc->m_pBoneMatrixIndex[v3 * m_VertexSize_BoneMatrixIndex];
      v19 = __PAIR64__(v9[1], *v9);
      v4 += V_snprintf(
              pDest: &pTempBuf[v4],
              maxLen: 1024 - v4,
              pFormat: "BI %d %d %d %d ",
              (_DWORD)v19,
              HIDWORD(v19),
              v9[2],
              v9[3]);
    }
    m_VertexSize_Normal = desc->m_VertexSize_Normal;
    if ( m_VertexSize_Normal != 0 )
      v4 += V_snprintf(
              pDest: &pTempBuf[v4],
              maxLen: 1024 - v4,
              pFormat: "N %1.2f %1.2f %1.2f ",
              *(float *)((char *)desc->m_pNormal + v3 * m_VertexSize_Normal),
              *(float *)((char *)desc->m_pNormal + v3 * m_VertexSize_Normal + 4),
              *(float *)((char *)desc->m_pNormal + v3 * m_VertexSize_Normal + 8));
    m_VertexSize_Color = desc->m_VertexSize_Color;
    if ( m_VertexSize_Color != 0 )
    {
      v12 = &desc->m_pColor[v3 * m_VertexSize_Color];
      v20 = __PAIR64__(v12[1], *v12);
      v4 += V_snprintf(
              pDest: &pTempBuf[v4],
              maxLen: 1024 - v4,
              pFormat: "C b %3d g %3d r %3d a %3d ",
              (_DWORD)v20,
              HIDWORD(v20),
              v12[2],
              v12[3]);
    }
    v13 = 0;
    m_VertexSize_TexCoord = desc->m_VertexSize_TexCoord;
    ja = 0;
    pWeighta = desc->m_VertexSize_TexCoord;
    do
    {
      if ( *m_VertexSize_TexCoord != 0 )
      {
        v15 = (float *)(m_VertexSize_TexCoord[21] + v3 * *m_VertexSize_TexCoord);
        v16 = V_snprintf(pDest: &pTempBuf[v4], maxLen: 1024 - v4, pFormat: "T%d %.2f %.2f ", v13, *v15, v15[1]);
        m_VertexSize_TexCoord = pWeighta;
        v13 = ja;
        v4 += v16;
      }
      ++v13;
      ++m_VertexSize_TexCoord;
      ja = v13;
      pWeighta = m_VertexSize_TexCoord;
    }
    while ( v13 < 8 );
    m_VertexSize_TangentS = desc->m_VertexSize_TangentS;
    if ( m_VertexSize_TangentS != 0 )
      v4 += V_snprintf(
              pDest: &pTempBuf[v4],
              maxLen: 1024 - v4,
              pFormat: "S %1.2f %1.2f %1.2f ",
              *(float *)((char *)desc->m_pTangentS + v3 * m_VertexSize_TangentS),
              *(float *)((char *)desc->m_pTangentS + v3 * m_VertexSize_TangentS + 4),
              *(float *)((char *)desc->m_pTangentS + v3 * m_VertexSize_TangentS + 8));
    m_VertexSize_TangentT = desc->m_VertexSize_TangentT;
    if ( m_VertexSize_TangentT != 0 )
      v4 += V_snprintf(
              pDest: &pTempBuf[v4],
              maxLen: 1024 - v4,
              pFormat: "T %1.2f %1.2f %1.2f ",
              *(float *)((char *)desc->m_pTangentT + v3 * m_VertexSize_TangentT),
              *(float *)((char *)desc->m_pTangentT + v3 * m_VertexSize_TangentT + 4),
              *(float *)((char *)desc->m_pTangentT + v3 * m_VertexSize_TangentT + 8));
    V_snprintf(pDest: &pTempBuf[v4], maxLen: 1024 - v4, pFormat: "\n");
    _Warning(a1: pTempBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100043C0
// Name: public: virtual void CIndexBufferBase::Spew(int,struct IndexDesc_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIndexBufferBase::Spew(CIndexBufferBase *this, int nIndexCount, const IndexDesc_t *indexDesc)
{
  char *v3; // edi
  int v4; // esi
  int i; // ebp
  unsigned int m_nFirstIndex; // [esp-8h] [ebp-218h]
  unsigned int m_nOffset; // [esp-4h] [ebp-214h]
  char pTempBuf[516]; // [esp+Ch] [ebp-204h] BYREF

  m_nOffset = indexDesc->m_nOffset;
  m_nFirstIndex = indexDesc->m_nFirstIndex;
  v3 = &pTempBuf[4];
  v4 = 0;
  pTempBuf[4] = 0;
  V_snprintf(
    pDest: &pTempBuf[4],
    maxLen: 512,
    pFormat: "\nIndices: %d (First %d, Offset %d)\n",
    nIndexCount,
    m_nFirstIndex,
    m_nOffset);
  _Warning(a1: &pTempBuf[4]);
  for ( i = 0; i < nIndexCount; ++i )
  {
    v4 += V_snprintf(pDest: v3, maxLen: 511 - v4, pFormat: "%d ", indexDesc->m_pIndices[i]);
    v3 = &pTempBuf[v4 + 4];
    if ( (i & 0xF) == 0xF )
    {
      V_snprintf(pDest: &pTempBuf[v4 + 4], maxLen: 511 - v4, pFormat: "\n");
      _Warning(a1: &pTempBuf[4]);
      pTempBuf[4] = 0;
      v4 = 0;
      v3 = &pTempBuf[4];
    }
  }
  V_snprintf(pDest: v3, maxLen: 511 - v4, pFormat: "\n");
  _Warning(a1: &pTempBuf[4]);
}

//------------------------------------------------------------------------------
// Address: 0x100044B0
// Name: public: virtual CMeshBase::~CMeshBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshBase::~CMeshBase(CMeshBase *this)
{
  this->IMesh::IVertexBuffer::__vftable = (CMeshBase_vtbl *)&CMeshBase::`vftable'{for `IVertexBuffer'};
  this->IMesh::IIndexBuffer::__vftable = (IIndexBuffer_vtbl *)&CMeshBase::`vftable'{for `IIndexBuffer'};
}

//------------------------------------------------------------------------------
// Address: 0x100044C0
// Name: void ComputeVertexDesc(unsigned char __near *,unsigned __int64,struct VertexDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeVertexDesc(float *pBuffer, unsigned __int64 vertexFormat, VertexDesc_t *desc)
{
  int v3; // ebx
  VertexCompressionType_t v4; // edx
  signed int VertexElementSize; // edi
  float *v6; // ecx
  int v7; // edi
  unsigned __int8 *v8; // eax
  VertexElement_t v9; // eax
  int v10; // eax
  unsigned __int8 *v11; // ecx
  int *m_VertexSize_TexCoord; // ebp
  int v13; // eax
  float *v14; // ecx
  float *v15; // eax
  float *v16; // eax
  int j; // eax
  int *v18; // ecx
  VertexCompressionType_t compressionType; // [esp+8h] [ebp-11Ch]
  int i; // [esp+Ch] [ebp-118h]
  VertexElement_t texCoordElements[4]; // [esp+10h] [ebp-114h]
  int *pVertexSizesToSet[64]; // [esp+20h] [ebp-104h]

  v3 = 0;
  if ( (`ComputeVertexDesc'::`2'::`local static guard' & 1) == 0 )
    `ComputeVertexDesc'::`2'::`local static guard' |= 1u;
  if ( (vertexFormat & 0x400) != 0 )
  {
    v4 = VERTEX_COMPRESSION_ON;
    compressionType = VERTEX_COMPRESSION_ON;
  }
  else
  {
    compressionType = VERTEX_COMPRESSION_NONE;
    v4 = VERTEX_COMPRESSION_NONE;
  }
  VertexElementSize = 0;
  desc->m_CompressionType = v4;
  if ( (vertexFormat & 1) != 0 )
  {
    desc->m_pPosition = pBuffer;
    VertexElementSize = GetVertexElementSize(
                          element: (VertexElement_t)((vertexFormat & 0x800) != 0),
                          compressionType: v4);
    pVertexSizesToSet[1] = &desc->m_VertexSize_Position;
    v3 = 1;
    if ( (vertexFormat & 0x40) != 0 )
    {
      desc->m_pWrinkle = (float *)((char *)pBuffer + VertexElementSize);
      VertexElementSize += 4;
      pVertexSizesToSet[2] = &desc->m_VertexSize_Wrinkle;
      v3 = 2;
      goto LABEL_12;
    }
    desc->m_pWrinkle = (float *)`ComputeVertexDesc'::`2'::temp;
  }
  else
  {
    desc->m_pPosition = (float *)`ComputeVertexDesc'::`2'::temp;
    desc->m_VertexSize_Position = 0;
    desc->m_pWrinkle = (float *)`ComputeVertexDesc'::`2'::temp;
  }
  desc->m_VertexSize_Wrinkle = 0;
LABEL_12:
  desc->m_NumBoneWeights = (vertexFormat >> 12) & 7;
  if ( (vertexFormat & 0x80) != 0 )
  {
    v6 = pBuffer;
    if ( ((vertexFormat >> 12) & 7) != 0 )
    {
      desc->m_pBoneWeight = (float *)((char *)pBuffer + VertexElementSize);
      pVertexSizesToSet[++v3] = &desc->m_VertexSize_BoneWeight;
      pVertexSizesToSet[v3 + 1] = &desc->m_VertexSize_BoneMatrixIndex;
      v7 = 4 * (compressionType != VERTEX_COMPRESSION_ON) + 4 + VertexElementSize;
      v8 = (unsigned __int8 *)pBuffer + v7;
      VertexElementSize = v7 + 4;
    }
    else
    {
      desc->m_VertexSize_BoneWeight = 0;
      v8 = (unsigned __int8 *)pBuffer + VertexElementSize;
      VertexElementSize += 4;
      pVertexSizesToSet[v3 + 1] = &desc->m_VertexSize_BoneMatrixIndex;
      desc->m_pBoneWeight = (float *)`ComputeVertexDesc'::`2'::temp;
    }
    ++v3;
  }
  else
  {
    v8 = (unsigned __int8 *)`ComputeVertexDesc'::`2'::temp;
    desc->m_VertexSize_BoneWeight = 0;
    desc->m_VertexSize_BoneMatrixIndex = 0;
    v6 = pBuffer;
    desc->m_pBoneWeight = (float *)`ComputeVertexDesc'::`2'::temp;
  }
  desc->m_pBoneMatrixIndex = v8;
  if ( (vertexFormat & 2) != 0 )
  {
    desc->m_pNormal = (float *)((char *)v6 + VertexElementSize);
    v9 = VERTEX_ELEMENT_NORMAL4D;
    if ( (vertexFormat & 0x800) == 0 )
      v9 = VERTEX_ELEMENT_NORMAL;
    v10 = GetVertexElementSize(element: v9, compressionType);
    v6 = pBuffer;
    VertexElementSize += v10;
    pVertexSizesToSet[++v3] = &desc->m_VertexSize_Normal;
  }
  else
  {
    desc->m_pNormal = (float *)`ComputeVertexDesc'::`2'::temp;
    desc->m_VertexSize_Normal = 0;
  }
  if ( (vertexFormat & 4) != 0 )
  {
    pVertexSizesToSet[v3 + 1] = &desc->m_VertexSize_Color;
    desc->m_pColor = (unsigned __int8 *)v6 + VertexElementSize;
    VertexElementSize += 4;
    ++v3;
  }
  else
  {
    desc->m_pColor = (unsigned __int8 *)`ComputeVertexDesc'::`2'::temp;
    desc->m_VertexSize_Color = 0;
  }
  if ( (vertexFormat & 8) != 0 )
  {
    v11 = (unsigned __int8 *)v6 + VertexElementSize;
    VertexElementSize += 4;
    pVertexSizesToSet[v3 + 1] = &desc->m_VertexSize_Specular;
    desc->m_pSpecular = v11;
    ++v3;
  }
  else
  {
    desc->m_pSpecular = (unsigned __int8 *)`ComputeVertexDesc'::`2'::temp;
    desc->m_VertexSize_Specular = 0;
  }
  texCoordElements[0] = VERTEX_ELEMENT_POSITION;
  texCoordElements[1] = VERTEX_ELEMENT_TEXCOORD1D_0;
  texCoordElements[2] = VERTEX_ELEMENT_TEXCOORD2D_0;
  texCoordElements[3] = VERTEX_ELEMENT_TEXCOORD3D_0;
  pVertexSizesToSet[0] = (int *)42;
  i = 18;
  m_VertexSize_TexCoord = desc->m_VertexSize_TexCoord;
  do
  {
    v13 = (vertexFormat >> i) & 7;
    if ( v13 != 0 )
    {
      m_VertexSize_TexCoord[21] = (int)pBuffer + VertexElementSize;
      VertexElementSize += GetVertexElementSize(
                             element: (VertexElement_t)(texCoordElements[0] + texCoordElements[v13]),
                             compressionType);
      pVertexSizesToSet[++v3] = m_VertexSize_TexCoord;
    }
    else
    {
      m_VertexSize_TexCoord[21] = (int)`ComputeVertexDesc'::`2'::temp;
      *m_VertexSize_TexCoord = 0;
    }
    ++texCoordElements[0];
    ++m_VertexSize_TexCoord;
    i += 3;
  }
  while ( i < 42 );
  if ( (vertexFormat & 0x10) != 0 )
  {
    v14 = pBuffer;
    v15 = (float *)((char *)pBuffer + VertexElementSize);
    VertexElementSize += 12;
    pVertexSizesToSet[v3 + 1] = &desc->m_VertexSize_TangentS;
    desc->m_pTangentS = v15;
    ++v3;
  }
  else
  {
    desc->m_VertexSize_TangentS = 0;
    v14 = pBuffer;
    desc->m_pTangentS = (float *)`ComputeVertexDesc'::`2'::temp;
  }
  if ( (vertexFormat & 0x20) != 0 )
  {
    v16 = (float *)((char *)v14 + VertexElementSize);
    VertexElementSize += 12;
    pVertexSizesToSet[v3 + 1] = &desc->m_VertexSize_TangentT;
    desc->m_pTangentT = v16;
    ++v3;
  }
  else
  {
    desc->m_pTangentT = (float *)`ComputeVertexDesc'::`2'::temp;
    desc->m_VertexSize_TangentT = 0;
  }
  if ( ((vertexFormat >> 15) & 7) != 0 )
  {
    desc->m_pUserData = (float *)((char *)v14 + VertexElementSize);
    VertexElementSize += GetVertexElementSize(
                           element: (VertexElement_t)(((vertexFormat >> 15) & 7) + 13),
                           compressionType);
    pVertexSizesToSet[++v3] = &desc->m_VertexSize_UserData;
  }
  else
  {
    desc->m_pUserData = (float *)`ComputeVertexDesc'::`2'::temp;
    desc->m_VertexSize_UserData = 0;
  }
  if ( (vertexFormat & 0x200) == 0 && VertexElementSize > 16 )
    VertexElementSize = (VertexElementSize + 15) & 0xFFFFFFF0;
  desc->m_ActualVertexSize = VertexElementSize;
  for ( j = 0; j < v3; *v18 = VertexElementSize )
    v18 = pVertexSizesToSet[++j];
}

//------------------------------------------------------------------------------
// Address: 0x10004890
// Name: public: CVertexBufferBase::CVertexBufferBase(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVertexBufferBase *__thiscall CVertexBufferBase::CVertexBufferBase(
        CVertexBufferBase *this,
        const char *pBudgetGroupName)
{
  this->__vftable = (CVertexBufferBase_vtbl *)&CVertexBufferBase::`vftable';
  this->m_pBudgetGroupName = pBudgetGroupName;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100048D0
// Name: public: static void CVertexBufferBase::ComputeVertexDescription(unsigned char __near *,unsigned __int64,struct VertexDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CVertexBufferBase::ComputeVertexDescription(
        float *pBuffer,
        unsigned __int64 vertexFormat,
        VertexDesc_t *desc)
{
  ComputeVertexDesc(pBuffer, vertexFormat, desc);
}

//------------------------------------------------------------------------------
// Address: 0x100048F0
// Name: public: static int CVertexBufferBase::VertexFormatSize(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
VertexCompressionType_t __cdecl CVertexBufferBase::VertexFormatSize(unsigned __int64 vertexFormat)
{
  MeshDesc_t temp; // [esp+0h] [ebp-B8h] BYREF

  ComputeVertexDesc(pBuffer: nullptr, vertexFormat, desc: (VertexDesc_t *)&temp.m_VertexSize_BoneWeight);
  return temp.m_CompressionType;
}

//------------------------------------------------------------------------------
// Address: 0x10004920
// Name: public: CIndexBufferBase::CIndexBufferBase(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CIndexBufferBase *__thiscall CIndexBufferBase::CIndexBufferBase(CIndexBufferBase *this, const char *pBudgetGroupName)
{
  this->__vftable = (CIndexBufferBase_vtbl *)&CIndexBufferBase::`vftable';
  this->m_pBudgetGroupName = pBudgetGroupName;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10004960
// Name: public: CMeshBase::CMeshBase(void)
// Source: json
//------------------------------------------------------------------------------
CMeshBase *__thiscall CMeshBase::CMeshBase(CMeshBase *this)
{
  this->IMesh::IIndexBuffer::__vftable = (IIndexBuffer_vtbl *)&IIndexBuffer::`vftable';
  this->IMesh::IVertexBuffer::__vftable = (CMeshBase_vtbl *)&CMeshBase::`vftable'{for `IVertexBuffer'};
  this->IMesh::IIndexBuffer::__vftable = (IIndexBuffer_vtbl *)&CMeshBase::`vftable'{for `IIndexBuffer'};
  return this;
}

} // namespace shaderapidx10
