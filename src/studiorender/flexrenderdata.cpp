// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: studiorender/flexrenderdata.cpp
// Functions: 12
// ============================================================

#include "studiorender\flexrenderdata.h"

//------------------------------------------------------------------------------
// Address: 0x10001000
// Name: public: void CCachedRenderData::StartModel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCachedRenderData::StartModel(CCachedRenderData *this)
{
  ++this->m_CurrentTag;
  this->m_IndexCount = 0;
  this->m_FlexVertexCount = 0;
  this->m_ThinFlexVertexCount = 0;
  this->m_WorldVertexCount = 0;
  this->m_pFirstFlexIndex = nullptr;
  this->m_pFirstThinFlexIndex = nullptr;
  this->m_pFirstWorldIndex = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10001030
// Name: public: struct CachedPosNormTan_t __near * CCachedRenderData::CreateFlexVertex(int)
// Source: json
//------------------------------------------------------------------------------
CachedPosNormTan_t *__thiscall CCachedRenderData::CreateFlexVertex(CCachedRenderData *this, int vertex)
{
  if ( this->m_FlexVertexCount >= 10000 )
    return nullptr;
  this->m_pFirstFlexIndex[vertex].m_Tag = this->m_CurrentTag;
  this->m_pFirstFlexIndex[vertex].m_VertexIndex = this->m_FlexVertexCount;
  ++this->m_FlexVertexCount;
  return &this->m_pFlexVerts[this->m_pFirstFlexIndex[vertex].m_VertexIndex];
}

//------------------------------------------------------------------------------
// Address: 0x10001080
// Name: public: struct CachedPosNorm_t __near * CCachedRenderData::CreateThinFlexVertex(int)
// Source: json
//------------------------------------------------------------------------------
CachedPosNorm_t *__thiscall CCachedRenderData::CreateThinFlexVertex(CCachedRenderData *this, int vertex)
{
  if ( this->m_ThinFlexVertexCount >= 10000 )
    return nullptr;
  this->m_pFirstThinFlexIndex[vertex].m_Tag = this->m_CurrentTag;
  this->m_pFirstThinFlexIndex[vertex].m_VertexIndex = this->m_ThinFlexVertexCount;
  ++this->m_ThinFlexVertexCount;
  return &this->m_pThinFlexVerts[this->m_pFirstThinFlexIndex[vertex].m_VertexIndex];
}

//------------------------------------------------------------------------------
// Address: 0x100010E0
// Name: public: void CCachedRenderData::RenormalizeFlexVertices(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCachedRenderData::RenormalizeFlexVertices(
        CCachedRenderData *this,
        bool bHasTangentData,
        bool bQuadList)
{
  int v3; // ebx
  float *p_w; // edi
  float v5; // xmm0_4

  v3 = 0;
  if ( this->m_FlexVertexCount > 0 )
  {
    p_w = &this->m_pFlexVerts[0].m_Position.w;
    do
    {
      VectorNormalize(vec: (Vector *)(p_w + 1));
      if ( bHasTangentData )
      {
        VectorNormalize(vec: (Vector *)(p_w + 5));
        if ( bQuadList )
        {
          v5 = 1.0;
          if ( *p_w < 1.0 )
          {
            v5 = -1.0;
            if ( *p_w > -1.0 )
              v5 = *p_w;
          }
          *p_w = (float)(v5 + 2.0) * p_w[8];
        }
      }
      ++v3;
      p_w += 12;
    }
    while ( v3 < this->m_FlexVertexCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001170
// Name: public: struct CachedPosNorm_t __near * CCachedRenderData::CreateWorldVertex(int)
// Source: json
//------------------------------------------------------------------------------
CachedPosNorm_t *__thiscall CCachedRenderData::CreateWorldVertex(CCachedRenderData *this, int vertex)
{
  CCachedRenderData::CacheIndex_t *m_pFirstWorldIndex; // eax
  unsigned __int16 m_CurrentTag; // dx
  bool v4; // zf
  CCachedRenderData::CacheIndex_t *v5; // eax

  m_pFirstWorldIndex = this->m_pFirstWorldIndex;
  m_CurrentTag = this->m_CurrentTag;
  v4 = m_pFirstWorldIndex[vertex].m_Tag == m_CurrentTag;
  v5 = &m_pFirstWorldIndex[vertex];
  if ( !v4 )
  {
    v5->m_Tag = m_CurrentTag;
    this->m_pFirstWorldIndex[vertex].m_VertexIndex = this->m_WorldVertexCount;
    ++this->m_WorldVertexCount;
  }
  return &this->m_pWorldVerts[this->m_pFirstWorldIndex[vertex].m_VertexIndex];
}

//------------------------------------------------------------------------------
// Address: 0x10001270
// Name: public: void CUtlMemory<struct CCachedRenderData::CacheDict_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CCachedRenderData::CacheDict_t,int>::Grow(
        CUtlMemory<CCachedRenderData::CacheDict_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CCachedRenderData::CacheDict_t *m_pMemory; // edx
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
      this->m_pMemory = (CCachedRenderData::CacheDict_t *)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: v7);
    else
      this->m_pMemory = (CCachedRenderData::CacheDict_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001310
// Name: public: bool CCachedRenderData::IsFlexComputationDone(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCachedRenderData::IsFlexComputationDone(CCachedRenderData *this)
{
  return this->m_CacheDict.m_Memory.m_pMemory[this->m_Body].m_Memory.m_pMemory[this->m_Model].m_Memory.m_pMemory[this->m_Mesh].m_FlexTag == this->m_CurrentTag;
}

//------------------------------------------------------------------------------
// Address: 0x10001350
// Name: public: void CCachedRenderData::SetupComputation(struct mstudiomesh_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCachedRenderData::SetupComputation(
        CCachedRenderData *this,
        mstudiomesh_t *pMesh,
        bool flexComputation)
{
  int m_Mesh; // esi
  CCachedRenderData::CacheDict_t *m_pMemory; // eax
  unsigned __int16 m_Tag; // dx
  CCachedRenderData::CacheDict_t *v6; // eax

  m_Mesh = this->m_Mesh;
  m_pMemory = this->m_CacheDict.m_Memory.m_pMemory[this->m_Body].m_Memory.m_pMemory[this->m_Model].m_Memory.m_pMemory;
  m_Tag = m_pMemory[m_Mesh].m_Tag;
  v6 = &m_pMemory[m_Mesh];
  if ( m_Tag != this->m_CurrentTag )
  {
    v6->m_FirstIndex = this->m_IndexCount;
    v6->m_IndexCount = pMesh->numvertices;
    v6->m_Tag = this->m_CurrentTag;
    this->m_IndexCount += v6->m_IndexCount;
  }
  if ( flexComputation )
    v6->m_FlexTag = this->m_CurrentTag;
  this->m_pFirstFlexIndex = &this->m_pFlexIndex[v6->m_FirstIndex];
  this->m_pFirstThinFlexIndex = &this->m_pThinFlexIndex[v6->m_FirstIndex];
  this->m_pFirstWorldIndex = &this->m_pWorldIndex[v6->m_FirstIndex];
}

//------------------------------------------------------------------------------
// Address: 0x100015E0
// Name: public: void CCachedRenderData::SetBodyPart(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCachedRenderData::SetBodyPart(CCachedRenderData *this, int bodypart)
{
  bool v3; // cc
  CUtlVector<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,CUtlMemory<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,int> > *p_m_CacheDict; // ecx

  this->m_Body = bodypart;
  v3 = this->m_CacheDict.m_Size < bodypart + 1;
  p_m_CacheDict = (CUtlVector<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,CUtlMemory<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,int> > *)&this->m_CacheDict;
  if ( v3 )
    CUtlVector<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int>>,CUtlMemory<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int>>,int>>::InsertMultipleBefore(
      this: p_m_CacheDict,
      elem: p_m_CacheDict->m_Size,
      num: bodypart + 1 - p_m_CacheDict->m_Size);
  this->m_Mesh = -1;
  this->m_Model = -1;
  this->m_pFirstFlexIndex = nullptr;
  this->m_pFirstThinFlexIndex = nullptr;
  this->m_pFirstWorldIndex = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10001640
// Name: public: void CCachedRenderData::SetModel(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCachedRenderData::SetModel(CCachedRenderData *this, int model)
{
  int m_Body; // ecx
  CUtlVector<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,CUtlMemory<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,int> > *m_pMemory; // edx
  bool v5; // cc
  CUtlVector<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,CUtlMemory<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,int> > *v6; // ecx

  m_Body = this->m_Body;
  m_pMemory = this->m_CacheDict.m_Memory.m_pMemory;
  this->m_Model = model;
  m_Body *= 5;
  v5 = *(&m_pMemory->m_Size + m_Body) < model + 1;
  v6 = (CUtlVector<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,CUtlMemory<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,int> > *)((char *)m_pMemory + 4 * m_Body);
  if ( v5 )
    CUtlVector<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int>>,CUtlMemory<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int>>,int>>::InsertMultipleBefore(
      this: v6,
      elem: v6->m_Size,
      num: model + 1 - v6->m_Size);
  this->m_Mesh = -1;
  this->m_pFirstFlexIndex = nullptr;
  this->m_pFirstThinFlexIndex = nullptr;
  this->m_pFirstWorldIndex = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100016A0
// Name: public: void CCachedRenderData::SetMesh(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCachedRenderData::SetMesh(CCachedRenderData *this, int mesh)
{
  int m_Body; // edx
  int m_Model; // ecx
  CUtlVector<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,CUtlMemory<CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> >,int> > *m_pMemory; // edi
  CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> > *v6; // edx
  bool v7; // cc
  CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> > *v8; // ecx
  int m_Mesh; // edx
  CCachedRenderData::CacheDict_t *v10; // eax
  unsigned __int16 m_Tag; // cx
  CCachedRenderData::CacheDict_t *v12; // eax

  m_Body = this->m_Body;
  m_Model = this->m_Model;
  m_pMemory = this->m_CacheDict.m_Memory.m_pMemory;
  this->m_Mesh = mesh;
  v6 = m_pMemory[m_Body].m_Memory.m_pMemory;
  m_Model *= 5;
  v7 = *(&v6->m_Size + m_Model) < mesh + 1;
  v8 = (CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int> > *)((char *)v6 + 4 * m_Model);
  if ( v7 )
    CUtlVector<CCachedRenderData::CacheDict_t,CUtlMemory<CCachedRenderData::CacheDict_t,int>>::InsertMultipleBefore(
      this: v8,
      elem: v8->m_Size,
      num: mesh + 1 - v8->m_Size);
  m_Mesh = this->m_Mesh;
  v10 = this->m_CacheDict.m_Memory.m_pMemory[this->m_Body].m_Memory.m_pMemory[this->m_Model].m_Memory.m_pMemory;
  m_Tag = v10[m_Mesh].m_Tag;
  v12 = &v10[m_Mesh];
  if ( m_Tag == this->m_CurrentTag )
  {
    this->m_pFirstFlexIndex = &this->m_pFlexIndex[v12->m_FirstIndex];
    this->m_pFirstThinFlexIndex = &this->m_pThinFlexIndex[v12->m_FirstIndex];
    this->m_pFirstWorldIndex = &this->m_pWorldIndex[v12->m_FirstIndex];
  }
  else
  {
    this->m_pFirstFlexIndex = nullptr;
    this->m_pFirstThinFlexIndex = nullptr;
    this->m_pFirstWorldIndex = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001810
// Name: public: CCachedRenderData::CCachedRenderData(void)
// Source: json
//------------------------------------------------------------------------------
CCachedRenderData *__thiscall CCachedRenderData::CCachedRenderData(CCachedRenderData *this)
{
  this->m_CacheDict.m_Memory.m_pMemory = nullptr;
  this->m_CacheDict.m_Memory.m_nAllocationCount = 0;
  this->m_CacheDict.m_Memory.m_nGrowSize = 0;
  this->m_CacheDict.m_Size = 0;
  this->m_CacheDict.m_pElements = nullptr;
  this->m_CurrentTag = 0;
  this->m_pFirstFlexIndex = nullptr;
  this->m_pFirstWorldIndex = nullptr;
  return this;
}
