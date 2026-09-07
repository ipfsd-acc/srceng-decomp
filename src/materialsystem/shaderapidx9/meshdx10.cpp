// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/shaderapidx9/meshdx10.cpp
// Functions: 50
// ============================================================

#include "materialsystem\shaderapidx9\meshdx10.h"

//------------------------------------------------------------------------------
// Address: 0x100049B0
// Name: protected: int CIndexBufferDx10::IndexSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CIndexBufferDx10::IndexSize(CIndexBufferDx10 *this)
{
  MaterialIndexFormat_t m_IndexFormat; // eax

  m_IndexFormat = this->m_IndexFormat;
  if ( m_IndexFormat == MATERIAL_INDEX_FORMAT_16BIT )
    return 2;
  if ( m_IndexFormat == MATERIAL_INDEX_FORMAT_32BIT )
    return 4;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100049D0
// Name: public: CVertexBufferDx10::CVertexBufferDx10(enum ShaderBufferType_t,unsigned __int64,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVertexBufferDx10 *__thiscall CVertexBufferDx10::CVertexBufferDx10(
        CVertexBufferDx10 *this,
        ShaderBufferType_t type,
        unsigned __int64 fmt,
        int nVertexCount,
        const char *pBudgetGroupName)
{
  int v6; // edx
  int v7; // eax
  char v8; // cl

  CVertexBufferBase::CVertexBufferBase(this, pBudgetGroupName);
  this->__vftable = (CVertexBufferDx10_vtbl *)&CVertexBufferDx10::`vftable';
  this->m_pVertexBuffer = nullptr;
  this->m_VertexFormat = fmt;
  if ( fmt != 0 )
    v6 = nVertexCount;
  else
    v6 = 0;
  this->m_nVertexCount = v6;
  if ( fmt != 0 )
    v7 = nVertexCount * CVertexBufferBase::VertexFormatSize(vertexFormat: fmt);
  else
    v7 = nVertexCount;
  *((_BYTE *)this + 36) &= ~1u;
  v8 = *((_BYTE *)this + 36);
  this->m_nBufferSize = v7;
  this->m_nFirstUnwrittenOffset = 0;
  if ( type == SHADER_BUFFER_TYPE_DYNAMIC || type == SHADER_BUFFER_TYPE_DYNAMIC_TEMP )
  {
    *((_BYTE *)this + 36) = v8 & 0xF9 | 2;
    return this;
  }
  else
  {
    *((_BYTE *)this + 36) = v8 & 0xF9;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004A70
// Name: public: virtual void CVertexBufferDx10::BeginCastBuffer(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBufferDx10::BeginCastBuffer(CVertexBufferDx10 *this, unsigned __int64 format)
{
  if ( (*((_BYTE *)this + 36) & 2) != 0 )
  {
    this->m_VertexFormat = format;
    this->m_nVertexCount = this->m_nBufferSize / CVertexBufferBase::VertexFormatSize(vertexFormat: format);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004AA0
// Name: public: virtual void CVertexBufferDx10::EndCastBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBufferDx10::EndCastBuffer(CVertexBufferDx10 *this)
{
  if ( (*((_BYTE *)this + 36) & 2) != 0 )
  {
    this->m_VertexFormat = 0;
    this->m_nVertexCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004AE0
// Name: public: virtual void CVertexBufferDx10::Unlock(int,struct VertexDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBufferDx10::Unlock(CVertexBufferDx10 *this, int nWrittenVertexCount, VertexDesc_t *desc)
{
  ID3D10Buffer *m_pVertexBuffer; // eax

  if ( (*((_BYTE *)this + 36) & 1) != 0 )
  {
    m_pVertexBuffer = this->m_pVertexBuffer;
    if ( m_pVertexBuffer != nullptr )
      m_pVertexBuffer->Unmap(this: this->m_pVertexBuffer);
    this->m_nFirstUnwrittenOffset += nWrittenVertexCount
                                   * CVertexBufferBase::VertexFormatSize(vertexFormat: this->m_VertexFormat);
    *((_BYTE *)this + 36) &= ~1u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004B20
// Name: public: CIndexBufferDx10::CIndexBufferDx10(enum ShaderBufferType_t,enum MaterialIndexFormat_t,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CIndexBufferDx10 *__thiscall CIndexBufferDx10::CIndexBufferDx10(
        CIndexBufferDx10 *this,
        ShaderBufferType_t type,
        MaterialIndexFormat_t fmt,
        int nIndexCount,
        const char *pBudgetGroupName)
{
  int v6; // eax
  int v7; // eax
  char v8; // cl
  bool v9; // al
  char v10; // al
  bool v11; // zf
  CIndexBufferDx10 *result; // eax

  CIndexBufferBase::CIndexBufferBase(this, pBudgetGroupName);
  this->__vftable = (CIndexBufferDx10_vtbl *)&CIndexBufferDx10::`vftable';
  this->m_pIndexBuffer = nullptr;
  this->m_IndexFormat = fmt;
  this->m_nIndexCount = fmt != MATERIAL_INDEX_FORMAT_UNKNOWN ? nIndexCount : 0;
  if ( fmt == MATERIAL_INDEX_FORMAT_UNKNOWN )
  {
    v6 = nIndexCount;
  }
  else
  {
    if ( fmt != MATERIAL_INDEX_FORMAT_16BIT )
    {
      if ( fmt == MATERIAL_INDEX_FORMAT_32BIT )
        v7 = 4;
      else
        v7 = 0;
    }
    else
    {
      v7 = 2;
    }
    v6 = nIndexCount * v7;
  }
  *((_BYTE *)this + 28) &= ~1u;
  v8 = *((_BYTE *)this + 28);
  this->m_nBufferSize = v6;
  this->m_nFirstUnwrittenOffset = 0;
  v9 = type == SHADER_BUFFER_TYPE_DYNAMIC || type == SHADER_BUFFER_TYPE_DYNAMIC_TEMP;
  v10 = v8 & 0xF9 | (2 * v9);
  *((_BYTE *)this + 28) = v10;
  v11 = (v10 & 2) == 0;
  result = this;
  if ( !v11 )
  {
    this->m_IndexFormat = MATERIAL_INDEX_FORMAT_UNKNOWN;
    this->m_nIndexCount = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10004BC0
// Name: public: virtual void CIndexBufferDx10::BeginCastBuffer(enum MaterialIndexFormat_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIndexBufferDx10::BeginCastBuffer(CIndexBufferDx10 *this, MaterialIndexFormat_t format)
{
  if ( (*((_BYTE *)this + 28) & 2) != 0 )
  {
    this->m_IndexFormat = format;
    if ( format != MATERIAL_INDEX_FORMAT_16BIT )
    {
      if ( format == MATERIAL_INDEX_FORMAT_32BIT )
        this->m_nIndexCount = this->m_nBufferSize / 4;
      else
        this->m_nIndexCount = this->m_nBufferSize / 0;
    }
    else
    {
      this->m_nIndexCount = this->m_nBufferSize / 2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004C10
// Name: public: virtual void CIndexBufferDx10::EndCastBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIndexBufferDx10::EndCastBuffer(CIndexBufferDx10 *this)
{
  if ( (*((_BYTE *)this + 28) & 2) != 0 )
  {
    this->m_IndexFormat = MATERIAL_INDEX_FORMAT_UNKNOWN;
    this->m_nIndexCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004C30
// Name: public: virtual int CIndexBufferDx10::GetRoomRemaining(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CIndexBufferDx10::GetRoomRemaining(CIndexBufferDx10 *this)
{
  MaterialIndexFormat_t m_IndexFormat; // eax

  m_IndexFormat = this->m_IndexFormat;
  if ( m_IndexFormat == MATERIAL_INDEX_FORMAT_16BIT )
    return (this->m_nBufferSize - this->m_nFirstUnwrittenOffset) / 2;
  if ( m_IndexFormat == MATERIAL_INDEX_FORMAT_32BIT )
    return (this->m_nBufferSize - this->m_nFirstUnwrittenOffset) / 4;
  return (this->m_nBufferSize - this->m_nFirstUnwrittenOffset) / 0;
}

//------------------------------------------------------------------------------
// Address: 0x10004C70
// Name: public: virtual void CIndexBufferDx10::Unlock(int,struct IndexDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIndexBufferDx10::Unlock(CIndexBufferDx10 *this, int nWrittenIndexCount, IndexDesc_t *desc)
{
  ID3D10Buffer *m_pIndexBuffer; // eax
  MaterialIndexFormat_t m_IndexFormat; // eax

  if ( (*((_BYTE *)this + 28) & 1) != 0 )
  {
    m_pIndexBuffer = this->m_pIndexBuffer;
    if ( m_pIndexBuffer != nullptr )
      m_pIndexBuffer->Unmap(this: this->m_pIndexBuffer);
    m_IndexFormat = this->m_IndexFormat;
    if ( m_IndexFormat != MATERIAL_INDEX_FORMAT_16BIT )
    {
      if ( m_IndexFormat == MATERIAL_INDEX_FORMAT_32BIT )
        this->m_nFirstUnwrittenOffset += 4 * nWrittenIndexCount;
      else
        this->m_nFirstUnwrittenOffset = this->m_nFirstUnwrittenOffset;
      *((_BYTE *)this + 28) &= ~1u;
    }
    else
    {
      this->m_nFirstUnwrittenOffset += 2 * nWrittenIndexCount;
      *((_BYTE *)this + 28) &= ~1u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004CE0
// Name: public: CMeshDx10::CMeshDx10(void)
// Source: json
//------------------------------------------------------------------------------
CMeshDx10 *__thiscall CMeshDx10::CMeshDx10(CMeshDx10 *this)
{
  CMeshBase::CMeshBase(this);
  this->CMeshBase::IMesh::IVertexBuffer::__vftable = (CMeshDx10_vtbl *)&CMeshDx10::`vftable'{for `IVertexBuffer'};
  this->CMeshBase::IMesh::IIndexBuffer::__vftable = (IIndexBuffer_vtbl *)&CMeshDx10::`vftable'{for `IIndexBuffer'};
  this->m_pVertexMemory = (unsigned __int8 *)operator new(nSize: 0x100000u);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10004D20
// Name: public: virtual unsigned __int64 CMeshDx10::GetVertexFormat(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CMeshDx10::GetVertexFormat(CMeshDx10 *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10004D30
// Name: public: virtual class IMesh __near * CMeshDx10::GetMesh(void)
// Source: json
//------------------------------------------------------------------------------
CMeshBase *__thiscall CMeshDx10::GetMesh(CMeshBase *this)
{
  return (CMeshBase *)((char *)this - 4);
}

//------------------------------------------------------------------------------
// Address: 0x10004D40
// Name: public: virtual CMeshDx10::~CMeshDx10(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshDx10::~CMeshDx10(CMeshDx10 *this)
{
  unsigned __int8 *m_pVertexMemory; // [esp-4h] [ebp-8h]

  m_pVertexMemory = this->m_pVertexMemory;
  this->CMeshBase::IMesh::IVertexBuffer::__vftable = (CMeshDx10_vtbl *)&CMeshDx10::`vftable'{for `IVertexBuffer'};
  this->CMeshBase::IMesh::IIndexBuffer::__vftable = (IIndexBuffer_vtbl *)&CMeshDx10::`vftable'{for `IIndexBuffer'};
  free(pMem: m_pVertexMemory);
  CMeshBase::~CMeshBase(this);
}

//------------------------------------------------------------------------------
// Address: 0x10004D70
// Name: public: virtual void CMeshDx10::LockMesh(int,int,struct MeshDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshDx10::LockMesh(CMeshDx10 *this, int numVerts, int numIndices, MeshDesc_t *desc)
{
  desc->m_pPosition = (float *)this->m_pVertexMemory;
  desc->m_pNormal = (float *)this->m_pVertexMemory;
  desc->m_pColor = this->m_pVertexMemory;
  desc->m_pTexCoord[0] = (float *)this->m_pVertexMemory;
  desc->m_pTexCoord[1] = (float *)this->m_pVertexMemory;
  desc->m_pTexCoord[2] = (float *)this->m_pVertexMemory;
  desc->m_pTexCoord[3] = (float *)this->m_pVertexMemory;
  desc->m_pTexCoord[4] = (float *)this->m_pVertexMemory;
  desc->m_pTexCoord[5] = (float *)this->m_pVertexMemory;
  desc->m_pTexCoord[6] = (float *)this->m_pVertexMemory;
  desc->m_pTexCoord[7] = (float *)this->m_pVertexMemory;
  desc->m_pIndices = (unsigned __int16 *)this->m_pVertexMemory;
  desc->m_pBoneWeight = (float *)this->m_pVertexMemory;
  desc->m_pBoneMatrixIndex = this->m_pVertexMemory;
  desc->m_pTangentS = (float *)this->m_pVertexMemory;
  desc->m_pTangentT = (float *)this->m_pVertexMemory;
  desc->m_pUserData = (float *)this->m_pVertexMemory;
  desc->m_NumBoneWeights = 2;
  desc->m_VertexSize_Position = 0;
  desc->m_VertexSize_BoneWeight = 0;
  desc->m_VertexSize_BoneMatrixIndex = 0;
  desc->m_VertexSize_Normal = 0;
  desc->m_VertexSize_Color = 0;
  desc->m_VertexSize_TexCoord[0] = 0;
  desc->m_VertexSize_TexCoord[1] = 0;
  desc->m_VertexSize_TexCoord[2] = 0;
  desc->m_VertexSize_TexCoord[3] = 0;
  desc->m_VertexSize_TexCoord[4] = 0;
  desc->m_VertexSize_TexCoord[5] = 0;
  desc->m_VertexSize_TexCoord[6] = 0;
  desc->m_VertexSize_TexCoord[7] = 0;
  desc->m_VertexSize_TangentS = 0;
  desc->m_VertexSize_TangentT = 0;
  desc->m_VertexSize_UserData = 0;
  desc->m_ActualVertexSize = 0;
  desc->m_nFirstVertex = 0;
  desc->m_nIndexSize = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10004E40
// Name: public: virtual void CMeshDx10::ModifyBeginEx(bool,int,int,int,int,struct MeshDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshDx10::ModifyBeginEx(
        CMeshDx10 *this,
        bool bReadOnly,
        int firstVertex,
        int numVerts,
        int firstIndex,
        int numIndices,
        MeshDesc_t *desc)
{
  desc->m_pPosition = (float *)this->m_pVertexMemory;
  desc->m_pNormal = (float *)this->m_pVertexMemory;
  desc->m_pColor = this->m_pVertexMemory;
  desc->m_pTexCoord[0] = (float *)this->m_pVertexMemory;
  desc->m_pTexCoord[1] = (float *)this->m_pVertexMemory;
  desc->m_pTexCoord[2] = (float *)this->m_pVertexMemory;
  desc->m_pTexCoord[3] = (float *)this->m_pVertexMemory;
  desc->m_pTexCoord[4] = (float *)this->m_pVertexMemory;
  desc->m_pTexCoord[5] = (float *)this->m_pVertexMemory;
  desc->m_pTexCoord[6] = (float *)this->m_pVertexMemory;
  desc->m_pTexCoord[7] = (float *)this->m_pVertexMemory;
  desc->m_pIndices = (unsigned __int16 *)this->m_pVertexMemory;
  desc->m_pBoneWeight = (float *)this->m_pVertexMemory;
  desc->m_pBoneMatrixIndex = this->m_pVertexMemory;
  desc->m_pTangentS = (float *)this->m_pVertexMemory;
  desc->m_pTangentT = (float *)this->m_pVertexMemory;
  desc->m_pUserData = (float *)this->m_pVertexMemory;
  desc->m_NumBoneWeights = 2;
  desc->m_VertexSize_Position = 0;
  desc->m_VertexSize_BoneWeight = 0;
  desc->m_VertexSize_BoneMatrixIndex = 0;
  desc->m_VertexSize_Normal = 0;
  desc->m_VertexSize_Color = 0;
  desc->m_VertexSize_TexCoord[0] = 0;
  desc->m_VertexSize_TexCoord[1] = 0;
  desc->m_VertexSize_TexCoord[2] = 0;
  desc->m_VertexSize_TexCoord[3] = 0;
  desc->m_VertexSize_TexCoord[4] = 0;
  desc->m_VertexSize_TexCoord[5] = 0;
  desc->m_VertexSize_TexCoord[6] = 0;
  desc->m_VertexSize_TexCoord[7] = 0;
  desc->m_VertexSize_TangentS = 0;
  desc->m_VertexSize_TangentT = 0;
  desc->m_VertexSize_UserData = 0;
  desc->m_ActualVertexSize = 0;
  desc->m_nFirstVertex = 0;
  desc->m_nIndexSize = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10004F30
// Name: protected: bool CVertexBufferDx10::Allocate(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVertexBufferDx10::Allocate(CVertexBufferDx10 *this)
{
  D3D10_USAGE m_nBufferSize; // eax
  ID3D10Buffer **p_m_pVertexBuffer; // edi
  VertexCompressionType_t v5; // eax
  IVBAllocTracker_vtbl *v6; // ebx
  VertexCompressionType_t v7; // ebp
  unsigned __int64 v8; // rax
  D3D10_BUFFER_DESC bd; // [esp+8h] [ebp-18h] BYREF
  int v10; // [esp+1Ch] [ebp-4h]

  m_nBufferSize = this->m_nBufferSize;
  this->m_nFirstUnwrittenOffset = 0;
  bd.BindFlags = 2;
  bd.Usage = m_nBufferSize;
  bd.CPUAccessFlags = 1;
  bd.MiscFlags = 0x10000;
  v10 = 0;
  p_m_pVertexBuffer = &this->m_pVertexBuffer;
  if ( g_pShaderDeviceDx10->m_pDevice->CreateBuffer(
         this: g_pShaderDeviceDx10->m_pDevice,
         a2: (const D3D10_BUFFER_DESC *)&bd.Usage,
         a3: nullptr,
         a4: &this->m_pVertexBuffer) < 0
    || *p_m_pVertexBuffer == nullptr )
  {
    return 0;
  }
  v5 = CVertexBufferBase::VertexFormatSize(vertexFormat: this->m_VertexFormat);
  v6 = g_VBAllocTracker->__vftable;
  v7 = v5;
  v8 = this->GetVertexFormat(this);
  ((void (__thiscall *)(IVBAllocTracker *, ID3D10Buffer *, bool, int, VertexCompressionType_t, _DWORD, _DWORD))v6->CountVB)(
    a1: g_VBAllocTracker,
    a2: *p_m_pVertexBuffer,
    a3: (*((_BYTE *)this + 36) & 2) != 0,
    a4: this->m_nBufferSize,
    a5: v7,
    a6: v8,
    a7: HIDWORD(v8));
  if ( (*((_BYTE *)this + 36) & 2) != 0 )
  {
    if ( (_S1 & 2) == 0 )
    {
      _S1 |= 2u;
      counter.m_pCounter = CVProfile::FindOrCreateCounter(
                             this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                             a2: "TexGroup_global_Dynamic Indices",
                             a3: COUNTER_GROUP_TEXTURE_GLOBAL);
      atexit(func: CVertexBufferDx10::Allocate_::_14_::_dynamic_atexit_destructor_for___counter__);
    }
    *counter.m_pCounter += this->m_nBufferSize;
    return 1;
  }
  else
  {
    if ( (_S1 & 1) == 0 )
    {
      _S1 |= 1u;
      counter_0.m_pCounter = CVProfile::FindOrCreateCounter(
                               this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                               a2: "TexGroup_global_Static Indices",
                               a3: COUNTER_GROUP_TEXTURE_GLOBAL);
      atexit(func: CVertexBufferDx10::Allocate_::_10_::_dynamic_atexit_destructor_for___counter__);
    }
    *counter_0.m_pCounter += this->m_nBufferSize;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005070
// Name: protected: void CVertexBufferDx10::Free(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexBufferDx10::Free(CVertexBufferDx10 *this)
{
  ID3D10Buffer *m_pVertexBuffer; // eax
  bool v3; // zf

  m_pVertexBuffer = this->m_pVertexBuffer;
  if ( m_pVertexBuffer != nullptr )
  {
    g_VBAllocTracker->UnCountVB(this: g_VBAllocTracker, a2: m_pVertexBuffer);
    this->m_pVertexBuffer->Release(this: this->m_pVertexBuffer);
    v3 = (*((_BYTE *)this + 36) & 2) == 0;
    this->m_pVertexBuffer = nullptr;
    if ( v3 )
    {
      if ( (_S2 & 1) == 0 )
      {
        _S2 |= 1u;
        counter_2.m_pCounter = CVProfile::FindOrCreateCounter(
                                 this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                                 a2: "TexGroup_global_Static Indices",
                                 a3: COUNTER_GROUP_TEXTURE_GLOBAL);
        atexit(func: CVertexBufferDx10::Free_::_10_::_dynamic_atexit_destructor_for___counter__);
      }
      *counter_2.m_pCounter -= this->m_nBufferSize;
    }
    else
    {
      if ( (_S2 & 2) == 0 )
      {
        _S2 |= 2u;
        counter_1.m_pCounter = CVProfile::FindOrCreateCounter(
                                 this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                                 a2: "TexGroup_global_Dynamic Indices",
                                 a3: COUNTER_GROUP_TEXTURE_GLOBAL);
        atexit(func: CVertexBufferDx10::Free_::_14_::_dynamic_atexit_destructor_for___counter__);
      }
      *counter_1.m_pCounter -= this->m_nBufferSize;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005130
// Name: public: virtual bool CVertexBufferDx10::Lock(int,bool,struct VertexDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVertexBufferDx10::Lock(CVertexBufferDx10 *this, int nMaxVertexCount, bool bAppend, VertexDesc_t *desc)
{
  bool v5; // zf
  VertexCompressionType_t v7; // eax
  int m_nFirstUnwrittenOffset; // ecx
  bool v9; // dl
  D3D10_MAP v10; // ecx
  char v11; // al
  int v12; // [esp+10h] [ebp-4h] BYREF

  g_pShaderUtil->SyncMatrices(this: g_pShaderUtil);
  v5 = this->m_VertexFormat == 0;
  v12 = 0;
  if ( v5 || g_pShaderDevice->IsDeactivated(this: g_pShaderDevice) || nMaxVertexCount == 0 )
    goto vertexBufferLockFailed;
  if ( nMaxVertexCount > this->m_nVertexCount )
  {
    _Warning(
      a1: "Too many vertices for vertex buffer. . tell a programmer (%d>%d)\n",
      nMaxVertexCount,
      this->m_nVertexCount);
vertexBufferLockFailed:
    CVertexBufferBase::ComputeVertexDescription(pBuffer: nullptr, vertexFormat: 0, desc);
    desc->m_nFirstVertex = 0;
    desc->m_nOffset = 0;
    return 0;
  }
  if ( this->m_pVertexBuffer == nullptr && CVertexBufferDx10::Allocate(this) == 0 )
    goto vertexBufferLockFailed;
  v7 = CVertexBufferBase::VertexFormatSize(vertexFormat: this->m_VertexFormat);
  m_nFirstUnwrittenOffset = this->m_nFirstUnwrittenOffset;
  v9 = m_nFirstUnwrittenOffset + nMaxVertexCount * v7 <= this->m_nBufferSize;
  if ( bAppend )
  {
    if ( m_nFirstUnwrittenOffset + nMaxVertexCount * v7 > this->m_nBufferSize || (*((_BYTE *)this + 36) & 4) != 0 )
      goto vertexBufferLockFailed;
    v10 = (m_nFirstUnwrittenOffset != 0) + 4;
  }
  else
  {
    v11 = *((_BYTE *)this + 36);
    if ( (v11 & 4) == 0 && v9 && (v11 & 2) != 0 )
    {
      v10 = (m_nFirstUnwrittenOffset != 0) + 4;
    }
    else
    {
      v10 = D3D10_MAP_WRITE_DISCARD;
      this->m_nFirstUnwrittenOffset = 0;
      *((_BYTE *)this + 36) = v11 & 0xFB;
    }
  }
  if ( this->m_pVertexBuffer->Map(this: this->m_pVertexBuffer, a2: v10, a3: 0, a4: (void **)&v12) < 0 )
  {
    _Warning(a1: "Failed to lock vertex buffer in CVertexBufferDx10::Lock\n");
    goto vertexBufferLockFailed;
  }
  CVertexBufferBase::ComputeVertexDescription(
    pBuffer: (float *)(v12 + this->m_nFirstUnwrittenOffset),
    vertexFormat: this->m_VertexFormat,
    desc);
  desc->m_nFirstVertex = 0;
  desc->m_nOffset = this->m_nFirstUnwrittenOffset;
  *((_BYTE *)this + 36) |= 1u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10005280
// Name: protected: bool CIndexBufferDx10::Allocate(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CIndexBufferDx10::Allocate(CIndexBufferDx10 *this)
{
  D3D10_USAGE m_nBufferSize; // eax
  ID3D10Buffer **p_m_pIndexBuffer; // edi
  D3D10_BUFFER_DESC bd; // [esp+8h] [ebp-18h] BYREF
  int v6; // [esp+1Ch] [ebp-4h]

  m_nBufferSize = this->m_nBufferSize;
  this->m_nFirstUnwrittenOffset = 0;
  bd.BindFlags = 2;
  bd.Usage = m_nBufferSize;
  bd.CPUAccessFlags = 2;
  bd.MiscFlags = 0x10000;
  v6 = 0;
  p_m_pIndexBuffer = &this->m_pIndexBuffer;
  if ( g_pShaderDeviceDx10->m_pDevice->CreateBuffer(
         this: g_pShaderDeviceDx10->m_pDevice,
         a2: (const D3D10_BUFFER_DESC *)&bd.Usage,
         a3: nullptr,
         a4: &this->m_pIndexBuffer) < 0
    || *p_m_pIndexBuffer == nullptr )
  {
    return 0;
  }
  if ( (*((_BYTE *)this + 28) & 2) != 0 )
  {
    if ( (_S3 & 2) == 0 )
    {
      _S3 |= 2u;
      counter_3.m_pCounter = CVProfile::FindOrCreateCounter(
                               this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                               a2: "TexGroup_global_Dynamic Indices",
                               a3: COUNTER_GROUP_TEXTURE_GLOBAL);
      atexit(func: CIndexBufferDx10::Allocate_::_14_::_dynamic_atexit_destructor_for___counter__);
    }
    *counter_3.m_pCounter += this->m_nBufferSize;
    return 1;
  }
  else
  {
    if ( (_S3 & 1) == 0 )
    {
      _S3 |= 1u;
      counter_4.m_pCounter = CVProfile::FindOrCreateCounter(
                               this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                               a2: "TexGroup_global_Static Indices",
                               a3: COUNTER_GROUP_TEXTURE_GLOBAL);
      atexit(func: CIndexBufferDx10::Allocate_::_10_::_dynamic_atexit_destructor_for___counter__);
    }
    *counter_4.m_pCounter += this->m_nBufferSize;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005380
// Name: protected: void CIndexBufferDx10::Free(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIndexBufferDx10::Free(CIndexBufferDx10 *this)
{
  ID3D10Buffer *m_pIndexBuffer; // eax
  bool v3; // zf

  m_pIndexBuffer = this->m_pIndexBuffer;
  if ( m_pIndexBuffer != nullptr )
  {
    m_pIndexBuffer->Release(this: m_pIndexBuffer);
    v3 = (*((_BYTE *)this + 28) & 2) == 0;
    this->m_pIndexBuffer = nullptr;
    if ( v3 )
    {
      if ( (_S4 & 1) == 0 )
      {
        _S4 |= 1u;
        counter_6.m_pCounter = CVProfile::FindOrCreateCounter(
                                 this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                                 a2: "TexGroup_global_Static Indices",
                                 a3: COUNTER_GROUP_TEXTURE_GLOBAL);
        atexit(func: CIndexBufferDx10::Free_::_10_::_dynamic_atexit_destructor_for___counter__);
      }
      *counter_6.m_pCounter -= this->m_nBufferSize;
    }
    else
    {
      if ( (_S4 & 2) == 0 )
      {
        _S4 |= 2u;
        counter_5.m_pCounter = CVProfile::FindOrCreateCounter(
                                 this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                                 a2: "TexGroup_global_Dynamic Indices",
                                 a3: COUNTER_GROUP_TEXTURE_GLOBAL);
        atexit(func: CIndexBufferDx10::Free_::_14_::_dynamic_atexit_destructor_for___counter__);
      }
      *counter_5.m_pCounter -= this->m_nBufferSize;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005430
// Name: public: virtual bool CIndexBufferDx10::Lock(int,bool,struct IndexDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CIndexBufferDx10::Lock(CIndexBufferDx10 *this, int nMaxIndexCount, bool bAppend, IndexDesc_t *desc)
{
  bool v5; // zf
  int m_nFirstUnwrittenOffset; // edi
  bool v8; // cl
  D3D10_MAP v9; // ecx
  char v10; // al
  int v11; // [esp+10h] [ebp-4h] BYREF

  g_pShaderUtil->SyncMatrices(this: g_pShaderUtil);
  v5 = this->m_IndexFormat == MATERIAL_INDEX_FORMAT_UNKNOWN;
  v11 = 0;
  if ( v5 || g_pShaderDevice->IsDeactivated(this: g_pShaderDevice) || nMaxIndexCount == 0 )
    goto indexBufferLockFailed;
  if ( nMaxIndexCount > this->m_nIndexCount )
  {
    _Warning(
      a1: "Too many indices for index buffer. . tell a programmer (%d>%d)\n",
      nMaxIndexCount,
      this->m_nIndexCount);
indexBufferLockFailed:
    desc->m_nFirstIndex = 0;
    desc->m_nIndexSize = 0;
    desc->m_nOffset = 0;
    desc->m_pIndices = (unsigned __int16 *)&s_nScratchIndexBuffer;
    return 0;
  }
  if ( this->m_pIndexBuffer == nullptr && CIndexBufferDx10::Allocate(this) == 0 )
    goto indexBufferLockFailed;
  m_nFirstUnwrittenOffset = this->m_nFirstUnwrittenOffset;
  v8 = m_nFirstUnwrittenOffset + nMaxIndexCount * CIndexBufferDx10::IndexSize(this) <= this->m_nBufferSize;
  if ( bAppend )
  {
    if ( !v8 || (*((_BYTE *)this + 28) & 4) != 0 )
      goto indexBufferLockFailed;
    v9 = (m_nFirstUnwrittenOffset != 0) + 4;
  }
  else
  {
    v10 = *((_BYTE *)this + 28);
    if ( (v10 & 4) == 0 && v8 && (v10 & 2) != 0 )
    {
      v9 = (m_nFirstUnwrittenOffset != 0) + 4;
    }
    else
    {
      v9 = D3D10_MAP_WRITE_DISCARD;
      this->m_nFirstUnwrittenOffset = 0;
      *((_BYTE *)this + 28) = v10 & 0xFB;
    }
  }
  if ( this->m_pIndexBuffer->Map(this: this->m_pIndexBuffer, a2: v9, a3: 0, a4: (void **)&v11) < 0 )
  {
    _Warning(a1: "Failed to lock index buffer in CIndexBufferDx10::Lock\n");
    goto indexBufferLockFailed;
  }
  desc->m_pIndices = (unsigned __int16 *)(v11 + this->m_nFirstUnwrittenOffset);
  desc->m_nIndexSize = CIndexBufferDx10::IndexSize(this) >> 1;
  desc->m_nFirstIndex = 0;
  desc->m_nOffset = this->m_nFirstUnwrittenOffset;
  *((_BYTE *)this + 28) |= 1u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100067A0
// Name: public: virtual int CVertexBufferDx10::VertexCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVertexBufferDx10::VertexCount(CVertexBufferDx10 *this)
{
  return this->m_nVertexCount;
}

//------------------------------------------------------------------------------
// Address: 0x100067B0
// Name: public: virtual unsigned __int64 CVertexBufferDx10::GetVertexFormat(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CVertexBufferDx10::GetVertexFormat(CVertexBufferDx10 *this)
{
  return this->m_VertexFormat;
}

//------------------------------------------------------------------------------
// Address: 0x100067C0
// Name: public: virtual bool CVertexBufferDx10::IsDynamic(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVertexBufferDx10::IsDynamic(CVertexBufferDx10 *this)
{
  return (*((_BYTE *)this + 36) & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10006B60
// Name: public: virtual bool CMeshDx10::Lock(int,bool,struct IndexDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMeshDx10::Lock(CMeshDx10 *this, int nVertexCount, bool bAppend, VertexDesc_t *desc)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10027F10
// Name: public: virtual enum MaterialIndexFormat_t CMeshDx10::IndexFormat(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMeshDx10::IndexFormat(CMeshDx10 *this)
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10039B40
// Name: public: virtual int CIndexBufferDx10::IndexCount(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CIndexBufferDx10::IndexCount(ConCommandBase *this)
{
  return this->m_pszHelpString;
}

//------------------------------------------------------------------------------
// Address: 0x10079930
// Name: _CVertexBufferDx10::Allocate_::_14_::_dynamic_atexit_destructor_for___counter__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CVertexBufferDx10::Allocate_::_14_::_dynamic_atexit_destructor_for___counter__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10079940
// Name: _CVertexBufferDx10::Allocate_::_10_::_dynamic_atexit_destructor_for___counter__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CVertexBufferDx10::Allocate_::_10_::_dynamic_atexit_destructor_for___counter__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10079950
// Name: _CVertexBufferDx10::Free_::_14_::_dynamic_atexit_destructor_for___counter__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CVertexBufferDx10::Free_::_14_::_dynamic_atexit_destructor_for___counter__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10079960
// Name: _CVertexBufferDx10::Free_::_10_::_dynamic_atexit_destructor_for___counter__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CVertexBufferDx10::Free_::_10_::_dynamic_atexit_destructor_for___counter__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10079970
// Name: _CIndexBufferDx10::Allocate_::_14_::_dynamic_atexit_destructor_for___counter__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CIndexBufferDx10::Allocate_::_14_::_dynamic_atexit_destructor_for___counter__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10079980
// Name: _CIndexBufferDx10::Allocate_::_10_::_dynamic_atexit_destructor_for___counter__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CIndexBufferDx10::Allocate_::_10_::_dynamic_atexit_destructor_for___counter__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10079990
// Name: _CIndexBufferDx10::Free_::_14_::_dynamic_atexit_destructor_for___counter__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CIndexBufferDx10::Free_::_14_::_dynamic_atexit_destructor_for___counter__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100799A0
// Name: _CIndexBufferDx10::Free_::_10_::_dynamic_atexit_destructor_for___counter__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CIndexBufferDx10::Free_::_10_::_dynamic_atexit_destructor_for___counter__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10079660
// Name: _dynamic_initializer_for__mat_spewvertexandpixelshaders_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_spewvertexandpixelshaders_command__()
{
  ConCommand::ConCommand(
    this: &mat_spewvertexandpixelshaders_command,
    pName: "mat_spewvertexandpixelshaders",
    callback: mat_spewvertexandpixelshaders,
    pHelpString: "Print all vertex and pixel shaders currently loaded to the console",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_spewvertexandpixelshaders_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10079690
// Name: _dynamic_initializer_for__mat_shadercount_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_shadercount_command__()
{
  ConCommand::ConCommand(
    this: &mat_shadercount_command,
    pName: "mat_shadercount",
    callback: mat_shadercount,
    pHelpString: "display count of all shaders and reset that count",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_shadercount_command__);
}

//------------------------------------------------------------------------------
// Address: 0x100796C0
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  s_EmptyConVar.m_Value.m_StringLength = strlen("0") + 1;
  s_EmptyConVar.m_Value.m_pszString = (char *)operator new(nSize: s_EmptyConVar.m_Value.m_StringLength);
  memcpy(
    dst: (unsigned __int8 *)s_EmptyConVar.m_Value.m_pszString,
    src: (unsigned __int8 *)s_EmptyConVar.m_pszDefaultValue,
    count: s_EmptyConVar.m_Value.m_StringLength);
  if ( !ConVar::InternalSetColorFromString(this: &s_EmptyConVar, value: s_EmptyConVar.m_Value.m_pszString) )
  {
    s_EmptyConVar.m_Value.m_fValue = atof(nptr: s_EmptyConVar.m_Value.m_pszString);
    if ( (LODWORD(s_EmptyConVar.m_Value.m_fValue) & 0x7F800000) == 0x7F800000 )
    {
      _Warning(a1: "ConVar(%s) defined with infinite float value (%s)\n", str, s_EmptyConVar.m_Value.m_pszString);
      s_EmptyConVar.m_Value.m_fValue = 3.4028235e38;
    }
    s_EmptyConVar.m_Value.m_nValue = (int)s_EmptyConVar.m_Value.m_fValue;
  }
  s_EmptyConVar.m_bRegistered = false;
  s_EmptyConVar.m_pszName = str;
  s_EmptyConVar.m_pszHelpString = empty_string;
  s_EmptyConVar.m_nFlags = 0;
  s_EmptyConVar.m_pNext = ConCommandBase::s_pConCommandBases;
  ConCommandBase::s_pConCommandBases = &s_EmptyConVar;
  if ( ConCommandBase::s_pAccessor != nullptr )
    s_EmptyConVar.Init(this: &s_EmptyConVar);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&CEmptyConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&CEmptyConVar::`vftable'{for `IConVar'};
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x100797F0
// Name: _dynamic_initializer_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::CExpressionEvaluator(this: &g_ExpressionEvaluator);
  return atexit(func: dynamic_atexit_destructor_for__g_ExpressionEvaluator__);
}

//------------------------------------------------------------------------------
// Address: 0x10079810
// Name: _dynamic_initializer_for__g_KVMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KVMutex__()
{
  g_KVMutex.m_ownerID = 0;
  g_KVMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10079820
// Name: _dynamic_initializer_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupSymbolTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10079830
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (unsigned __int8 *)s_StringCharConversion.m_pConversion,
    value: 0,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10079890
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100798C0
// Name: sub_100798C0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_100798C0()
{
  _SYSTEM_INFO SystemInfo; // [esp+0h] [ebp-24h] BYREF

  GetSystemInfo(lpSystemInfo: &SystemInfo);
  dword_100FF0DC = SystemInfo.dwNumberOfProcessors;
}

//------------------------------------------------------------------------------
// Address: 0x100798E0
// Name: _dynamic_initializer_for__vtMissing__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__vtMissing__()
{
  return atexit(func: dynamic_atexit_destructor_for__vtMissing__);
}

//------------------------------------------------------------------------------
// Address: 0x100798F0
// Name: _dynamic_atexit_destructor_for__mem_dumpvballocs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mem_dumpvballocs__()
{
  ConCommand::~ConCommand(this: &mem_dumpvballocs);
}

//------------------------------------------------------------------------------
// Address: 0x10079900
// Name: _dynamic_atexit_destructor_for__developer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__developer__()
{
  ConVar::~ConVar(this: &developer);
}

//------------------------------------------------------------------------------
// Address: 0x10079910
// Name: _dynamic_atexit_destructor_for__r_shader_srgb__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_shader_srgb__()
{
  ConVar::~ConVar(this: &r_shader_srgb);
}

//------------------------------------------------------------------------------
// Address: 0x10079920
// Name: _dynamic_atexit_destructor_for__mat_disablehwmorph__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_disablehwmorph__()
{
  ConVar::~ConVar(this: &mat_disablehwmorph);
}
