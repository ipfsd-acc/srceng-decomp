// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/spatialpartition.cpp
// Functions: 94
// ============================================================

#include "engine\spatialpartition.h"

//------------------------------------------------------------------------------
// Address: 0x1008D080
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<class CEventInfo,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<class CEventInfo,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // edx
  CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1] && i < (unsigned int)&m_pBlockHeader[8 * m_pBlockHeader->m_nBlockSize + 1] )
    return (int)i > (int)&m_pBlockHeader[8 * m_nIndex + 1];
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[8 * m_pNext->m_nBlockSize + 1] )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1008D100
// Name: public: class CUtlFixedMemory<struct UtlLinkedListElem_t<struct LeafListData_t,int>>::Iterator_t CUtlFixedMemory<struct UtlLinkedListElem_t<struct LeafListData_t,int>>::Next(class CUtlFixedMemory<struct UtlLinkedListElem_t<struct LeafListData_t,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *__thiscall CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
        CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *this,
        CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *result,
        const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *m_pBlockHeader; // ecx
  int m_nIndex; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *m_pNext; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v7; // [esp+0h] [ebp-8h]

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader != nullptr && (m_nIndex = it->m_nIndex) >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    if ( m_nIndex + 1 >= m_pBlockHeader->m_nBlockSize )
    {
      m_pNext = m_pBlockHeader->m_pNext;
      if ( m_pNext != nullptr )
      {
        v7 = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t)(unsigned int)m_pNext;
      }
      else
      {
        v7.m_pBlockHeader = nullptr;
        v7.m_nIndex = -1;
      }
      *result = v7;
      return result;
    }
    else
    {
      result->m_pBlockHeader = m_pBlockHeader;
      result->m_nIndex = m_nIndex + 1;
      return result;
    }
  }
  else
  {
    result->m_pBlockHeader = nullptr;
    result->m_nIndex = -1;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009CD10
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<class CEventInfo,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> > *this,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *v4; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *m_pBlocks; // eax

  if ( num > 0 )
  {
    m_nGrowSize = this->m_nGrowSize;
    if ( m_nGrowSize == 0 )
    {
      m_nGrowSize = this->m_nAllocationCount;
      if ( m_nGrowSize == 0 )
        m_nGrowSize = 1;
    }
    if ( m_nGrowSize < num )
      m_nGrowSize *= (m_nGrowSize + num - 1) / m_nGrowSize;
    this->m_nAllocationCount += m_nGrowSize;
    v4 = (CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *)_g_pMemAlloc->Alloc_2(
                                                                                   this: _g_pMemAlloc,
                                                                                   a2: (m_nGrowSize << 6) + 8);
    if ( v4 == nullptr )
      _Error(a1: "CUtlFixedMemory overflow!\n");
    m_pBlocks = this->m_pBlocks;
    v4->m_pNext = nullptr;
    v4->m_nBlockSize = m_nGrowSize;
    if ( m_pBlocks != nullptr )
    {
      for ( ; m_pBlocks->m_pNext != nullptr; m_pBlocks = m_pBlocks->m_pNext )
        ;
      m_pBlocks->m_pNext = v4;
    }
    else
    {
      this->m_pBlocks = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AA270
// Name: public: virtual int CSpatialPartition::GetSuppressedLists(void)
// Source: json
//------------------------------------------------------------------------------
CColorBalanceOperation *__thiscall CSpatialPartition::GetSuppressedLists(CColorBalanceUIPanel *this)
{
  return this->m_pBalanceOp;
}

//------------------------------------------------------------------------------
// Address: 0x1011F710
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<class PackedEntity __near *,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > *this,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *v4; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *m_pBlocks; // eax

  if ( num > 0 )
  {
    m_nGrowSize = this->m_nGrowSize;
    if ( m_nGrowSize == 0 )
    {
      m_nGrowSize = this->m_nAllocationCount;
      if ( m_nGrowSize == 0 )
        m_nGrowSize = 3;
    }
    if ( m_nGrowSize < num )
      m_nGrowSize *= (m_nGrowSize + num - 1) / m_nGrowSize;
    this->m_nAllocationCount += m_nGrowSize;
    v4 = (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *)_g_pMemAlloc->Alloc_2(
                                                                                  this: _g_pMemAlloc,
                                                                                  a2: 12 * m_nGrowSize + 8);
    if ( v4 == nullptr )
      _Error(a1: "CUtlFixedMemory overflow!\n");
    m_pBlocks = this->m_pBlocks;
    v4->m_pNext = nullptr;
    v4->m_nBlockSize = m_nGrowSize;
    if ( m_pBlocks != nullptr )
    {
      for ( ; m_pBlocks->m_pNext != nullptr; m_pBlocks = m_pBlocks->m_pNext )
        ;
      m_pBlocks->m_pNext = v4;
    }
    else
    {
      this->m_pBlocks = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011F7A0
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<unsigned short,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<unsigned short,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1] && i < (unsigned int)&m_pBlockHeader[1] + 12 * m_pBlockHeader->m_nBlockSize )
    return (int)i > (int)&m_pBlockHeader[1] + 12 * m_nIndex;
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[1] + 12 * m_pNext->m_nBlockSize )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10150AE0
// Name: public: CTSPool<struct TraceInfo_t>::~CTSPool<struct TraceInfo_t>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSPool<TraceInfo_t>::~CTSPool<TraceInfo_t>(CTSPool<TraceInfo_t> *this)
{
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax

  while ( 1 )
  {
    Next = this->m_Head.value.Next;
    DepthAndSequence = this->m_Head.value32.DepthAndSequence;
    if ( this->m_Head.value.Next == nullptr )
      break;
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: this,
                               a2: Next->Next,
                               a3: DepthAndSequence - 1,
                               a4: Next,
                               a5: DepthAndSequence) == 0 )
    {
      _mm_pause();
      Next = this->m_Head.value.Next;
      DepthAndSequence = this->m_Head.value32.DepthAndSequence;
      if ( this->m_Head.value.Next == nullptr )
        goto LABEL_4;
    }
    TraceInfo_t::~TraceInfo_t(this: (TraceInfo_t *)(&Next->Next + 1));
    free(pMem: Next);
  }
LABEL_4:
  CTSListBase::Detach(this);
}

//------------------------------------------------------------------------------
// Address: 0x101584E0
// Name: void DestroySpatialPartition(class ISpatialPartition __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DestroySpatialPartition(void *pMem)
{
  free(pMem);
}

//------------------------------------------------------------------------------
// Address: 0x101B4E40
// Name: public: CTSPool<struct net_scratchbuffer_t>::~CTSPool<struct net_scratchbuffer_t>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSPool<net_scratchbuffer_t>::~CTSPool<net_scratchbuffer_t>(CTSPool<net_scratchbuffer_t> *this)
{
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax

  while ( 1 )
  {
    Next = this->m_Head.value.Next;
    DepthAndSequence = this->m_Head.value32.DepthAndSequence;
    if ( this->m_Head.value.Next == nullptr )
      break;
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: this,
                               a2: Next->Next,
                               a3: DepthAndSequence - 1,
                               a4: Next,
                               a5: DepthAndSequence) == 0 )
    {
      _mm_pause();
      Next = this->m_Head.value.Next;
      DepthAndSequence = this->m_Head.value32.DepthAndSequence;
      if ( this->m_Head.value.Next == nullptr )
        goto LABEL_4;
    }
    free(pMem: Next);
  }
LABEL_4:
  CTSListBase::Detach(this);
}

//------------------------------------------------------------------------------
// Address: 0x101D8210
// Name: void ClampStartPoint(struct Ray_t __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClampStartPoint(Ray_t *ray, const Vector *vecEnd)
{
  long double x; // st7
  float v4; // xmm1_4
  float v5; // xmm4_4
  float v6; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  float v9; // xmm0_4
  float raya; // [esp+8h] [ebp+8h]
  float rayb; // [esp+8h] [ebp+8h]
  float rayc; // [esp+8h] [ebp+8h]

  x = ray->m_Delta.x;
  raya = ray->m_Delta.x;
  if ( fabs(x) >= 1.0e-10 )
  {
    if ( raya <= 0.0 )
    {
      if ( ray->m_Start.x <= 16384.0 )
        goto LABEL_8;
      v4 = (float)(ray->m_Start.x - 16379.0) * (float)(-1.0 / ray->m_Delta.x);
    }
    else
    {
      if ( ray->m_Start.x >= -16384.0 )
        goto LABEL_8;
      v4 = (float)(-16379.0 - ray->m_Start.x) / raya;
    }
    ray->m_Start.x = (float)(raya * v4) + ray->m_Start.x;
    ray->m_Start.y = (float)(ray->m_Delta.y * v4) + ray->m_Start.y;
    ray->m_Start.z = (float)(ray->m_Delta.z * v4) + ray->m_Start.z;
  }
LABEL_8:
  if ( fabs(ray->m_Delta.y) < 1.0e-10 )
    goto LABEL_15;
  rayb = ray->m_Delta.y;
  if ( rayb <= 0.0 )
  {
    y = ray->m_Start.y;
    if ( y <= 16384.0 )
      goto LABEL_15;
    v6 = (float)(y - 16379.0) * (float)(-1.0 / rayb);
  }
  else
  {
    v5 = ray->m_Start.y;
    if ( v5 >= -16384.0 )
      goto LABEL_15;
    v6 = (float)(-16379.0 - v5) / rayb;
  }
  ray->m_Start.x = (float)(v6 * ray->m_Delta.x) + ray->m_Start.x;
  ray->m_Start.y = (float)(ray->m_Delta.y * v6) + ray->m_Start.y;
  ray->m_Start.z = (float)(ray->m_Delta.z * v6) + ray->m_Start.z;
LABEL_15:
  if ( fabs(ray->m_Delta.z) >= 1.0e-10 )
  {
    z = ray->m_Start.z;
    rayc = ray->m_Delta.z;
    if ( rayc <= 0.0 )
    {
      if ( z > 16384.0 )
      {
        v9 = (float)(z - 16379.0) * (float)(-1.0 / rayc);
        goto LABEL_21;
      }
    }
    else if ( z < -16384.0 )
    {
      v9 = (float)(-16379.0 - z) / rayc;
LABEL_21:
      ray->m_Start.x = (float)(v9 * ray->m_Delta.x) + ray->m_Start.x;
      ray->m_Start.y = (float)(ray->m_Delta.y * v9) + ray->m_Start.y;
      ray->m_Start.z = (float)(ray->m_Delta.z * v9) + ray->m_Start.z;
    }
  }
  ray->m_Delta.x = vecEnd->x - ray->m_Start.x;
  ray->m_Delta.y = vecEnd->y - ray->m_Start.y;
  ray->m_Delta.z = vecEnd->z - ray->m_Start.z;
}

//------------------------------------------------------------------------------
// Address: 0x101D83F0
// Name: void ClampEndPoint(struct Ray_t __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClampEndPoint(Ray_t *ray, Vector *vecEnd)
{
  long double x; // st7
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float raya; // [esp+8h] [ebp+8h]
  float rayb; // [esp+8h] [ebp+8h]
  float rayc; // [esp+8h] [ebp+8h]

  x = ray->m_Delta.x;
  raya = ray->m_Delta.x;
  if ( fabs(x) >= 1.0e-10 )
  {
    if ( raya >= 0.0 )
    {
      if ( vecEnd->x <= 16384.0 )
        goto LABEL_8;
      v4 = (float)(ray->m_Start.x - -16379.0) / ray->m_Delta.x;
    }
    else
    {
      if ( vecEnd->x >= -16384.0 )
        goto LABEL_8;
      v4 = (float)(ray->m_Start.x - -16379.0) * (float)(-1.0 / raya);
    }
    vecEnd->x = (float)(raya * v4) + ray->m_Start.x;
    vecEnd->y = (float)(ray->m_Delta.y * v4) + ray->m_Start.y;
    vecEnd->z = (float)(ray->m_Delta.z * v4) + ray->m_Start.z;
  }
LABEL_8:
  rayb = ray->m_Delta.y;
  if ( fabs(rayb) >= 1.0e-10 )
  {
    if ( rayb >= 0.0 )
    {
      if ( vecEnd->y <= 16384.0 )
        goto LABEL_15;
      v5 = (float)(ray->m_Start.y - -16379.0) / rayb;
    }
    else
    {
      if ( vecEnd->y >= -16384.0 )
        goto LABEL_15;
      v5 = (float)(ray->m_Start.y - -16379.0) * (float)(-1.0 / rayb);
    }
    vecEnd->x = (float)(ray->m_Delta.x * v5) + ray->m_Start.x;
    vecEnd->y = (float)(ray->m_Delta.y * v5) + ray->m_Start.y;
    vecEnd->z = (float)(ray->m_Delta.z * v5) + ray->m_Start.z;
  }
LABEL_15:
  rayc = ray->m_Delta.z;
  if ( fabs(rayc) >= 1.0e-10 )
  {
    if ( rayc >= 0.0 )
    {
      if ( vecEnd->z > 16384.0 )
      {
        v6 = (float)(ray->m_Start.z - -16379.0) / rayc;
        goto LABEL_21;
      }
    }
    else if ( vecEnd->z < -16384.0 )
    {
      v6 = (float)(ray->m_Start.z - -16379.0) * (float)(-1.0 / rayc);
LABEL_21:
      vecEnd->x = (float)(ray->m_Delta.x * v6) + ray->m_Start.x;
      vecEnd->y = (float)(ray->m_Delta.y * v6) + ray->m_Start.y;
      vecEnd->z = (float)(ray->m_Delta.z * v6) + ray->m_Start.z;
    }
  }
  ray->m_Delta.x = vecEnd->x - ray->m_Start.x;
  ray->m_Delta.y = vecEnd->y - ray->m_Start.y;
  ray->m_Delta.z = vecEnd->z - ray->m_Start.z;
}

//------------------------------------------------------------------------------
// Address: 0x101D85E0
// Name: public: bool CIntersectSweptBox::Intersects(float const __near *,float const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CIntersectSweptBox::Intersects@<al>(
        CIntersectSweptBox *this@<ecx>,
        int a2@<ebp>,
        __m128 *pMins,
        __m128 *pMaxs)
{
  __m128 v5; // [esp-20h] [ebp-2Ch] BYREF
  __m128 v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a2;
  v8 = retaddr;
  v6 = _mm_add_ps(*pMaxs, this->m_f4Extents);
  v5 = _mm_sub_ps(*pMins, this->m_f4Extents);
  return IsBoxIntersectingRay(
           inBoxMin: &v5,
           inBoxMax: &v6,
           origin: &this->m_f4Start,
           delta: &this->m_f4Delta,
           invDelta: &this->m_f4InvDelta,
           vTolerance: &Four_Zeros);
}

//------------------------------------------------------------------------------
// Address: 0x101D8640
// Name: public: void CVoxelHash::LeafListRaySetup(struct Ray_t const __near &,class Vector const __near &,class Vector const __near &,union Voxel_t,int __near *,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelHash::LeafListRaySetup(
        CVoxelHash *this,
        const Ray_t *ray,
        const Vector *vecEnd,
        const Vector *vecInvDelta,
        Voxel_t voxel,
        int *pStep,
        float *pMax,
        float *pDelta)
{
  const Ray_t *v9; // ecx
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm4_4
  float v13; // xmm1_4
  float v14; // xmm3_4
  float v15; // xmm5_4
  int v16; // edi
  unsigned int v17; // esi
  int *v18; // ebx
  const Vector *v19; // edi
  int v20; // eax
  float v21; // xmm7_4
  float x; // xmm0_4
  float v23; // xmm1_4
  int v24; // eax
  float v25; // xmm2_4
  float v26; // xmm3_4
  float y; // xmm0_4
  int v28; // eax
  int v29; // eax
  float v30; // xmm4_4
  float v31; // xmm5_4
  float z; // xmm0_4
  int v33; // eax
  unsigned int iVoxel_8; // [esp+8h] [ebp-4h]
  float flDistStart; // [esp+20h] [ebp+14h]

  v9 = ray;
  v10 = ray->m_Start.x - this->m_vecVoxelOrigin.x;
  v11 = ray->m_Start.y - this->m_vecVoxelOrigin.y;
  v12 = ray->m_Start.z - this->m_vecVoxelOrigin.z;
  iVoxel_8 = voxel.uiVoxel >> 22;
  v13 = vecEnd->x - this->m_vecVoxelOrigin.x;
  v14 = vecEnd->y - this->m_vecVoxelOrigin.y;
  v15 = vecEnd->z - this->m_vecVoxelOrigin.z;
  v16 = *(_WORD *)&voxel.bitsVoxel & 0x7FF;
  v17 = (voxel.uiVoxel >> 11) & 0x7FF;
  if ( v10 == v13 )
  {
    v18 = pStep;
    v19 = vecInvDelta;
    *pStep = 0;
    *pMax = 65536.0;
    *pDelta = 65536.0;
  }
  else
  {
    if ( ray->m_Delta.x >= 0.0 )
    {
      *pStep = 1;
      v21 = (float)((v16 + 1) * (-256 << (2 * this->m_nLevel)));
      flDistStart = (float)-v10 - v21;
      x = vecInvDelta->x;
      v13 = -v13;
      v19 = vecInvDelta;
    }
    else
    {
      *pStep = -1;
      v20 = v16 * (256 << (2 * LOBYTE(this->m_nLevel)));
      v19 = vecInvDelta;
      v21 = (float)v20;
      flDistStart = v10 - (float)v20;
      x = -vecInvDelta->x;
    }
    v23 = v13 - v21;
    if ( flDistStart <= 0.0 || v23 <= 0.0 )
    {
      *pMax = x * flDistStart;
      *pDelta = (float)(256 << (2 * this->m_nLevel)) * x;
    }
    else
    {
      *pMax = 65536.0;
      *pDelta = 65536.0;
    }
    v9 = ray;
    v18 = pStep;
  }
  if ( v11 == v14 )
  {
    v18[1] = 0;
    pMax[1] = 65536.0;
    pDelta[1] = 65536.0;
  }
  else
  {
    if ( v9->m_Delta.y >= 0.0 )
    {
      v18[1] = 1;
      v28 = (v17 + 1) * (-256 << (2 * LOBYTE(this->m_nLevel)));
      v25 = (float)-v11 - (float)v28;
      v26 = (float)-v14 - (float)v28;
      y = v19->y;
    }
    else
    {
      v18[1] = -1;
      v24 = v17 * (256 << (2 * LOBYTE(this->m_nLevel)));
      v25 = v11 - (float)v24;
      v26 = v14 - (float)v24;
      y = -v19->y;
    }
    if ( v25 <= 0.0 || v26 <= 0.0 )
    {
      pMax[1] = y * v25;
      pDelta[1] = (float)(256 << (2 * this->m_nLevel)) * y;
    }
    else
    {
      pMax[1] = 65536.0;
      pDelta[1] = 65536.0;
    }
    v9 = ray;
  }
  if ( v12 == v15 )
  {
    v18[2] = 0;
LABEL_23:
    pMax[2] = 65536.0;
    pDelta[2] = 65536.0;
    return;
  }
  if ( v9->m_Delta.z >= 0.0 )
  {
    v18[2] = 1;
    v33 = (iVoxel_8 + 1) * (-256 << (2 * this->m_nLevel));
    v30 = (float)-v12 - (float)v33;
    v31 = (float)-v15 - (float)v33;
    z = v19->z;
  }
  else
  {
    v18[2] = -1;
    v29 = iVoxel_8 * (256 << (2 * LOBYTE(this->m_nLevel)));
    v30 = v12 - (float)v29;
    v31 = v15 - (float)v29;
    z = -v19->z;
  }
  if ( v30 > 0.0 && v31 > 0.0 )
    goto LABEL_23;
  pMax[2] = z * v30;
  pDelta[2] = (float)(256 << (2 * LOBYTE(this->m_nLevel))) * z;
}

//------------------------------------------------------------------------------
// Address: 0x101D8990
// Name: public: void CVoxelHash::LeafListExtrudedRaySetup(struct Ray_t const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,int __near * const,int __near * const,int __near *,float __near *,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelHash::LeafListExtrudedRaySetup(
        CVoxelHash *this,
        const Ray_t *ray,
        const Vector *vecInvDelta,
        const Vector *vecMin,
        const Vector *vecMax,
        int *iVoxelMin,
        int *iVoxelMax,
        int *pStep,
        float *pMin,
        float *pMax,
        float *pDelta)
{
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm0_4
  int v17; // ecx
  VectorAligned *p_m_Delta; // ebx
  int i; // edx
  float *v20; // eax
  int v21; // esi
  float v22; // xmm0_4
  float v23; // xmm1_4
  float x; // xmm3_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  int v27; // esi
  Vector vecVoxelMin; // [esp+0h] [ebp-18h]
  Vector vecVoxelMax; // [esp+Ch] [ebp-Ch] BYREF
  const Vector *vecMina; // [esp+28h] [ebp+10h]

  v12 = vecMax->y - this->m_vecVoxelOrigin.y;
  v13 = vecMin->x - this->m_vecVoxelOrigin.x;
  v14 = vecMin->y - this->m_vecVoxelOrigin.y;
  vecVoxelMin.z = vecMin->z - this->m_vecVoxelOrigin.z;
  v15 = vecMax->x - this->m_vecVoxelOrigin.x;
  vecVoxelMax.y = v12;
  v16 = vecMax->z - this->m_vecVoxelOrigin.z;
  v17 = (char *)pStep - (char *)&vecVoxelMax;
  p_m_Delta = &ray->m_Delta;
  vecVoxelMin.x = v13;
  vecVoxelMin.y = v14;
  vecVoxelMax.x = v15;
  vecVoxelMax.z = v16;
  vecMina = (const Vector *)((char *)iVoxelMax - (char *)&vecVoxelMax);
  for ( i = 0; i < 3; ++i )
  {
    if ( p_m_Delta->x == 0.0 )
    {
      pMax[i] = 65536.0;
      pMin[i] = 65536.0;
      pDelta[i] = 65536.0;
    }
    else
    {
      v20 = (float *)((char *)&vecVoxelMax.x + i * 4);
      if ( p_m_Delta->x >= 0.0 )
      {
        v26 = *v20;
        *(_DWORD *)((char *)v20 + v17) = 1;
        v27 = -256 << (2 * this->m_nLevel);
        x = p_m_Delta->x;
        v22 = (float)-v26 - (float)(v27 * (*(_DWORD *)((char *)v20 + (_DWORD)vecMina) + 1));
        v23 = (float)-*(float *)((char *)&vecVoxelMin.x + i * 4) - (float)(v27 * (iVoxelMin[i] + 1));
        v25 = *(float *)((char *)&vecInvDelta->x + i * 4);
      }
      else
      {
        *(float *)((char *)v20 + v17) = NAN;
        v21 = 256 << (2 * this->m_nLevel);
        v22 = *(float *)((char *)&vecVoxelMin.x + i * 4) - (float)(v21 * iVoxelMin[i]);
        v23 = *v20 - (float)(v21 * *(_DWORD *)((char *)v20 + (_DWORD)vecMina));
        x = -p_m_Delta->x;
        v25 = -*(float *)((char *)&vecInvDelta->x + i * 4);
      }
      if ( v22 <= x )
      {
        pMax[i] = v25 * v22;
        pDelta[i] = (float)(256 << (2 * this->m_nLevel)) * v25;
      }
      else
      {
        pMax[i] = 65536.0;
        pDelta[i] = 65536.0;
      }
      if ( v23 <= x )
        pMin[i] = v25 * v23;
      else
        pMin[i] = 65536.0;
      v17 = (char *)pStep - (char *)&vecVoxelMax;
    }
    p_m_Delta = (VectorAligned *)((char *)p_m_Delta + 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D8B90
// Name: public: void CVoxelHash::RenderGrid(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelHash::RenderGrid(CVoxelHash *this)
{
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  int m_nLevel; // edx
  float v6; // xmm1_4
  int v7; // eax
  int v8; // edx
  int v9; // edi
  int v10; // ebx
  int v11; // ecx
  int v12; // eax
  int v13; // edx
  int v14; // edi
  int v15; // ebx
  int v16; // ecx
  int v17; // eax
  Color v18; // edx
  Color v19; // [esp-8h] [ebp-30h]
  Color v20; // [esp-8h] [ebp-30h]
  Vector vecStart; // [esp+Ch] [ebp-1Ch] BYREF
  Vector vecEnd; // [esp+18h] [ebp-10h] BYREF
  int i; // [esp+24h] [ebp-4h]

  v2 = 0;
  if ( this->m_nVoxelDelta[0] > 0 )
  {
    v3 = this->m_nVoxelDelta[1];
    do
    {
      v4 = 0;
      vecEnd.x = (float)(v2 * (256 << (2 * LOBYTE(this->m_nLevel)))) + this->m_vecVoxelOrigin.x;
      for ( vecStart.x = vecEnd.x; v4 < v3; ++v4 )
      {
        m_nLevel = this->m_nLevel;
        v19 = s_pVoxelColor[m_nLevel];
        v6 = (float)((256 << (2 * m_nLevel)) * this->m_nVoxelDelta[2]);
        vecEnd.y = (float)(v4 * (256 << (2 * m_nLevel))) + this->m_vecVoxelOrigin.y;
        vecStart.y = vecEnd.y;
        vecStart.z = this->m_vecVoxelOrigin.z;
        vecEnd.z = v6 + vecStart.z;
        RenderLine(v1: &vecStart, v2: &vecEnd, c: v19, bZBuffer: true);
        v3 = this->m_nVoxelDelta[1];
      }
      ++v2;
    }
    while ( v2 < this->m_nVoxelDelta[0] );
  }
  v7 = 0;
  i = 0;
  if ( this->m_nVoxelDelta[0] > 0 )
  {
    v8 = this->m_nVoxelDelta[2];
    do
    {
      v9 = 0;
      vecEnd.x = (float)(v7 * (256 << (2 * LOBYTE(this->m_nLevel)))) + this->m_vecVoxelOrigin.x;
      vecStart.x = vecEnd.x;
      if ( v8 > 0 )
      {
        do
        {
          v10 = this->m_nLevel;
          v11 = 256 << (2 * v10);
          v20 = s_pVoxelColor[v10];
          vecEnd.z = (float)(v9 * v11) + this->m_vecVoxelOrigin.z;
          vecStart.z = vecEnd.z;
          vecStart.y = this->m_vecVoxelOrigin.y;
          vecEnd.y = (float)(v8 * v11) + vecStart.y;
          RenderLine(v1: &vecStart, v2: &vecEnd, c: v20, bZBuffer: true);
          v8 = this->m_nVoxelDelta[2];
          ++v9;
        }
        while ( v9 < v8 );
        v7 = i;
      }
      i = ++v7;
    }
    while ( v7 < this->m_nVoxelDelta[0] );
  }
  v12 = 0;
  i = 0;
  if ( this->m_nVoxelDelta[1] > 0 )
  {
    v13 = this->m_nVoxelDelta[2];
    do
    {
      v14 = 0;
      vecEnd.y = (float)(v12 * (256 << (2 * LOBYTE(this->m_nLevel)))) + this->m_vecVoxelOrigin.y;
      vecStart.y = vecEnd.y;
      if ( v13 > 0 )
      {
        do
        {
          v15 = this->m_nLevel;
          vecStart.x = this->m_vecVoxelOrigin.z;
          v16 = 256 << (2 * v15);
          v17 = v13 * v16;
          v18 = s_pVoxelColor[v15];
          vecEnd.z = (float)(v14 * v16) + vecStart.x;
          vecStart.z = vecEnd.z;
          vecEnd.x = (float)v17 + this->m_vecVoxelOrigin.x;
          RenderLine(v1: &vecStart, v2: &vecEnd, c: v18, bZBuffer: true);
          v13 = this->m_nVoxelDelta[2];
          ++v14;
        }
        while ( v14 < v13 );
        v12 = i;
      }
      i = ++v12;
    }
    while ( v12 < this->m_nVoxelDelta[1] );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D8E10
// Name: public: virtual void CVoxelTree::EnumerateElementsInSphere(int,class Vector const __near &,float,bool,class IPartitionEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelTree::EnumerateElementsInSphere(
        CVoxelTree *this,
        int listMask,
        const Vector *origin,
        float radius,
        BOOL coarseTest,
        IPartitionEnumerator *pIterator)
{
  float x; // xmm1_4
  float y; // xmm2_4
  void (__thiscall *EnumerateElementsInBox)(CVoxelTree *, int, const Vector *, const Vector *, bool, IPartitionEnumerator *); // eax
  float z; // xmm4_4
  Vector vecMin; // [esp+0h] [ebp-18h] BYREF
  Vector vecMax; // [esp+Ch] [ebp-Ch] BYREF

  x = origin->x;
  vecMin.x = origin->x - radius;
  y = origin->y;
  vecMin.y = y - radius;
  EnumerateElementsInBox = this->EnumerateElementsInBox;
  z = origin->z;
  vecMin.z = z - radius;
  vecMax.x = x + radius;
  vecMax.y = y + radius;
  vecMax.z = z + radius;
  EnumerateElementsInBox(this, a2: listMask, a3: &vecMin, a4: &vecMax, a5: coarseTest, a6: pIterator);
}

//------------------------------------------------------------------------------
// Address: 0x101D8E90
// Name: bool DEBUG_THINK_TRACE_COUNTER_ALLOWED(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl DEBUG_THINK_TRACE_COUNTER_ALLOWED()
{
  if ( (_S1_18 & 1) == 0 )
  {
    _S1_18 |= 1u;
    bIsPublic = GetSteamUniverse() == k_EUniversePublic;
  }
  return !bIsPublic;
}

//------------------------------------------------------------------------------
// Address: 0x101D8EC0
// Name: class ISpatialPartitionInternal __near * SpatialPartition(void)
// Source: json
//------------------------------------------------------------------------------
CSpatialPartition *__cdecl SpatialPartition()
{
  return &g_SpatialPartition;
}

//------------------------------------------------------------------------------
// Address: 0x101D8ED0
// Name: public: virtual void CSpatialPartition::InstallQueryCallback(class IPartitionQueryCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::InstallQueryCallback(CSpatialPartition *this, IPartitionQueryCallback *pCallback)
{
  int m_nQueryCallbackCount; // eax

  if ( pCallback != nullptr )
  {
    m_nQueryCallbackCount = this->m_nQueryCallbackCount;
    if ( m_nQueryCallbackCount < 3 )
    {
      this->m_pQueryCallback[m_nQueryCallbackCount] = pCallback;
      ++this->m_nQueryCallbackCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D8F00
// Name: public: virtual void CSpatialPartition::RemoveQueryCallback(class IPartitionQueryCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::RemoveQueryCallback(CSpatialPartition *this, IPartitionQueryCallback *pCallback)
{
  int v2; // esi
  int v3; // eax
  IPartitionQueryCallback **i; // edx

  if ( pCallback != nullptr )
  {
    v2 = this->m_nQueryCallbackCount - 1;
    v3 = v2;
    if ( v2 >= 0 )
    {
      for ( i = &this->m_pQueryCallback[v2]; *i != pCallback; --i )
      {
        if ( --v3 < 0 )
          return;
      }
      this->m_nQueryCallbackCount = v2;
      this->m_pQueryCallback[v3] = this->m_pQueryCallback[v2];
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D8F50
// Name: public: virtual unsigned short CSpatialPartition::CreateHandle(class IHandleEntity __near *,int,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CSpatialPartition::CreateHandle(
        CSpatialPartition *this,
        IHandleEntity *pHandleEntity,
        int listMask,
        const Vector *mins,
        const Vector *maxs)
{
  int v6; // edi

  v6 = this->CreateHandle_2(this, a2: pHandleEntity);
  this->Insert(this, a2: listMask, a3: v6);
  this->InsertIntoTree(this, a2: v6, a3: mins, a4: maxs);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101D8FA0
// Name: public: virtual void CSpatialPartition::SuppressLists(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::SuppressLists(CSpatialPartition *this, int nListMask, bool bSuppress)
{
  if ( bSuppress )
    this->m_nSuppressedListMask |= nListMask;
  else
    this->m_nSuppressedListMask &= ~nListMask;
}

//------------------------------------------------------------------------------
// Address: 0x101D8FD0
// Name: public: virtual void CSpatialPartition::EnumerateElementsInBox(int,class Vector const __near &,class Vector const __near &,bool,class IPartitionEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::EnumerateElementsInBox(
        CSpatialPartition *this,
        int listMask,
        const Vector *mins,
        const Vector *maxs,
        BOOL coarseTest,
        IPartitionEnumerator *pIterator)
{
  int v8; // ebx
  CVoxelTree *v9; // ecx
  int v10; // ebx
  IMDLCache *cacheCriticalSection; // [esp+Ch] [ebp-8h]
  CVoxelTree *pTree; // [esp+10h] [ebp-4h]
  IPartitionQueryCallback **listMaska; // [esp+1Ch] [ebp+8h]
  IPartitionQueryCallback **listMaskb; // [esp+1Ch] [ebp+8h]

  cacheCriticalSection = g_pMDLCache;
  ((void (*)(void))g_pMDLCache->BeginLock)();
  v8 = 0;
  v9 = &this->m_VoxelTrees[(listMask & 0x1AC) == 0];
  pTree = v9;
  if ( this->m_nQueryCallbackCount > 0 )
  {
    listMaska = this->m_pQueryCallback;
    do
    {
      (*listMaska)->OnPreQuery(this: *listMaska, a2: listMask);
      ++listMaska;
      ++v8;
    }
    while ( v8 < this->m_nQueryCallbackCount );
    v9 = pTree;
  }
  v9->EnumerateElementsInBox(this: v9, a2: listMask, a3: mins, a4: maxs, a5: coarseTest, a6: pIterator);
  v10 = 0;
  if ( this->m_nQueryCallbackCount > 0 )
  {
    listMaskb = this->m_pQueryCallback;
    do
    {
      (*listMaskb)->OnPostQuery(this: *listMaskb, a2: listMask);
      ++listMaskb;
      ++v10;
    }
    while ( v10 < this->m_nQueryCallbackCount );
  }
  cacheCriticalSection->EndLock(this: cacheCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x101D90A0
// Name: public: virtual void CSpatialPartition::EnumerateElementsInSphere(int,class Vector const __near &,float,bool,class IPartitionEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::EnumerateElementsInSphere(
        CSpatialPartition *this,
        CMDLCacheCriticalSection listMask,
        CVoxelTree *origin,
        float radius,
        int coarseTest,
        IPartitionEnumerator *pIterator)
{
  int v8; // ebx
  CVoxelTree *v9; // ecx
  int v10; // ebx
  IMDLCache *v11; // [esp+18h] [ebp-8h]
  CVoxelTree *v12; // [esp+1Ch] [ebp-4h]
  IPartitionQueryCallback **cacheCriticalSection; // [esp+28h] [ebp+8h]
  IPartitionQueryCallback **cacheCriticalSectiona; // [esp+28h] [ebp+8h]

  v11 = g_pMDLCache;
  ((void (*)(void))g_pMDLCache->BeginLock)();
  v8 = 0;
  v9 = &this->m_VoxelTrees[((int)listMask.m_pCache & 0x1AC) == 0];
  v12 = v9;
  if ( this->m_nQueryCallbackCount > 0 )
  {
    cacheCriticalSection = this->m_pQueryCallback;
    do
    {
      ((void (__thiscall *)(IPartitionQueryCallback *, CMDLCacheCriticalSection))(*cacheCriticalSection)->OnPreQuery)(
        a1: *cacheCriticalSection,
        a2: listMask);
      ++cacheCriticalSection;
      ++v8;
    }
    while ( v8 < this->m_nQueryCallbackCount );
    v9 = v12;
  }
  ((void (__stdcall *)(CMDLCacheCriticalSection, CVoxelTree *, _DWORD, int, IPartitionEnumerator *))v9->EnumerateElementsInSphere)(
    a1: listMask,
    a2: origin,
    a3: LODWORD(radius),
    a4: coarseTest,
    a5: pIterator);
  v10 = 0;
  if ( this->m_nQueryCallbackCount > 0 )
  {
    cacheCriticalSectiona = this->m_pQueryCallback;
    do
    {
      ((void (__thiscall *)(IPartitionQueryCallback *, CMDLCacheCriticalSection))(*cacheCriticalSectiona)->OnPostQuery)(
        a1: *cacheCriticalSectiona,
        a2: listMask);
      ++cacheCriticalSectiona;
      ++v10;
    }
    while ( v10 < this->m_nQueryCallbackCount );
  }
  v11->EndLock(this: v11);
}

//------------------------------------------------------------------------------
// Address: 0x101D9170
// Name: public: virtual void CSpatialPartition::EnumerateElementsAlongRay(int,struct Ray_t const __near &,bool,class IPartitionEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::EnumerateElementsAlongRay(
        CSpatialPartition *this,
        int listMask,
        const Ray_t *ray,
        BOOL coarseTest,
        IPartitionEnumerator *pIterator)
{
  int v7; // ebx
  CVoxelTree *v8; // ecx
  int v9; // ebx
  IMDLCache *cacheCriticalSection; // [esp+Ch] [ebp-8h]
  CVoxelTree *pTree; // [esp+10h] [ebp-4h]
  IPartitionQueryCallback **listMaska; // [esp+1Ch] [ebp+8h]
  IPartitionQueryCallback **listMaskb; // [esp+1Ch] [ebp+8h]

  cacheCriticalSection = g_pMDLCache;
  ((void (*)(void))g_pMDLCache->BeginLock)();
  v7 = 0;
  v8 = &this->m_VoxelTrees[(listMask & 0x1AC) == 0];
  pTree = v8;
  if ( this->m_nQueryCallbackCount > 0 )
  {
    listMaska = this->m_pQueryCallback;
    do
    {
      (*listMaska)->OnPreQuery(this: *listMaska, a2: listMask);
      ++listMaska;
      ++v7;
    }
    while ( v7 < this->m_nQueryCallbackCount );
    v8 = pTree;
  }
  v8->EnumerateElementsAlongRay(this: v8, a2: listMask, a3: ray, a4: coarseTest, a5: pIterator);
  v9 = 0;
  if ( this->m_nQueryCallbackCount > 0 )
  {
    listMaskb = this->m_pQueryCallback;
    do
    {
      (*listMaskb)->OnPostQuery(this: *listMaskb, a2: listMask);
      ++listMaskb;
      ++v9;
    }
    while ( v9 < this->m_nQueryCallbackCount );
  }
  cacheCriticalSection->EndLock(this: cacheCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x101D9230
// Name: public: virtual void CSpatialPartition::EnumerateElementsAtPoint(int,class Vector const __near &,bool,class IPartitionEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::EnumerateElementsAtPoint(
        CSpatialPartition *this,
        int listMask,
        const Vector *pt,
        BOOL coarseTest,
        IPartitionEnumerator *pIterator)
{
  int v7; // ebx
  CVoxelTree *v8; // ecx
  int v9; // ebx
  IMDLCache *cacheCriticalSection; // [esp+Ch] [ebp-8h]
  CVoxelTree *pTree; // [esp+10h] [ebp-4h]
  IPartitionQueryCallback **listMaska; // [esp+1Ch] [ebp+8h]
  IPartitionQueryCallback **listMaskb; // [esp+1Ch] [ebp+8h]

  cacheCriticalSection = g_pMDLCache;
  ((void (*)(void))g_pMDLCache->BeginLock)();
  v7 = 0;
  v8 = &this->m_VoxelTrees[(listMask & 0x1AC) == 0];
  pTree = v8;
  if ( this->m_nQueryCallbackCount > 0 )
  {
    listMaska = this->m_pQueryCallback;
    do
    {
      (*listMaska)->OnPreQuery(this: *listMaska, a2: listMask);
      ++listMaska;
      ++v7;
    }
    while ( v7 < this->m_nQueryCallbackCount );
    v8 = pTree;
  }
  v8->EnumerateElementsAtPoint(this: v8, a2: listMask, a3: pt, a4: coarseTest, a5: pIterator);
  v9 = 0;
  if ( this->m_nQueryCallbackCount > 0 )
  {
    listMaskb = this->m_pQueryCallback;
    do
    {
      (*listMaskb)->OnPostQuery(this: *listMaskb, a2: listMask);
      ++listMaskb;
      ++v9;
    }
    while ( v9 < this->m_nQueryCallbackCount );
  }
  cacheCriticalSection->EndLock(this: cacheCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x101D92F0
// Name: public: virtual void CSpatialPartition::RenderAllObjectsInTree(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::RenderAllObjectsInTree(CSpatialPartition *this, float flTime)
{
  CVoxelTree *m_VoxelTrees; // esi
  int i; // edi

  m_VoxelTrees = this->m_VoxelTrees;
  for ( i = 2; i != 0; --i )
  {
    ((void (__thiscall *)(CVoxelTree *, _DWORD))m_VoxelTrees->RenderAllObjectsInTree)(
      a1: m_VoxelTrees,
      a2: LODWORD(flTime));
    ++m_VoxelTrees;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D9320
// Name: public: virtual void CSpatialPartition::RenderObjectsInPlayerLeafs(class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::RenderObjectsInPlayerLeafs(
        CSpatialPartition *this,
        const Vector *vecPlayerMin,
        const Vector *vecPlayerMax,
        float flTime)
{
  CVoxelTree *m_VoxelTrees; // esi
  int i; // edi

  m_VoxelTrees = this->m_VoxelTrees;
  for ( i = 2; i != 0; --i )
  {
    ((void (__thiscall *)(CVoxelTree *, const Vector *, const Vector *, _DWORD))m_VoxelTrees->RenderObjectsInPlayerLeafs)(
      a1: m_VoxelTrees,
      a2: vecPlayerMin,
      a3: vecPlayerMax,
      a4: LODWORD(flTime));
    ++m_VoxelTrees;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D9360
// Name: public: virtual void CSpatialPartition::DrawDebugOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::DrawDebugOverlays(CSpatialPartition *this)
{
  CVoxelTree *m_VoxelTrees; // esi
  int i; // edi

  m_VoxelTrees = this->m_VoxelTrees;
  for ( i = 2; i != 0; --i )
  {
    m_VoxelTrees->DrawDebugOverlays(this: m_VoxelTrees);
    ++m_VoxelTrees;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D9390
// Name: public: void CUtlHashFixed<int,512,class CUtlHashFixedGenericHash<512>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::RemoveAll(
        CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *this)
{
  CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *v1; // esi
  int i; // ebx
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *m_pFirst; // eax
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *pNext; // edi

  v1 = this;
  for ( i = 512; i != 0; --i )
  {
    m_pFirst = v1->m_aBuckets[0].m_pFirst;
    if ( v1->m_aBuckets[0].m_pFirst != nullptr )
    {
      do
      {
        pNext = m_pFirst->pNext;
        free(pMem: m_pFirst);
        m_pFirst = pNext;
      }
      while ( pNext != v1->m_aBuckets[0].m_pFirst );
    }
    v1->m_aBuckets[0].m_pFirst = nullptr;
    v1->m_aBuckets[0].m_nElems = 0;
    v1 = (CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *)((char *)v1 + 8);
  }
  this->m_nElements = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101D93E0
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct LeafListData_t,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> > *this,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *v4; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *m_pBlocks; // eax

  if ( num > 0 )
  {
    m_nGrowSize = this->m_nGrowSize;
    if ( m_nGrowSize == 0 )
    {
      m_nGrowSize = this->m_nAllocationCount;
      if ( m_nGrowSize == 0 )
        m_nGrowSize = 2;
    }
    if ( m_nGrowSize < num )
      m_nGrowSize *= (m_nGrowSize + num - 1) / m_nGrowSize;
    this->m_nAllocationCount += m_nGrowSize;
    v4 = (CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *)_g_pMemAlloc->Alloc_2(
                                                                                       this: _g_pMemAlloc,
                                                                                       a2: 16 * m_nGrowSize + 8);
    if ( v4 == nullptr )
      _Error(a1: "CUtlFixedMemory overflow!\n");
    m_pBlocks = this->m_pBlocks;
    v4->m_pNext = nullptr;
    v4->m_nBlockSize = m_nGrowSize;
    if ( m_pBlocks != nullptr )
    {
      for ( ; m_pBlocks->m_pNext != nullptr; m_pBlocks = m_pBlocks->m_pNext )
        ;
      m_pBlocks->m_pNext = v4;
    }
    else
    {
      this->m_pBlocks = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D9470
// Name: public: virtual void CSpatialPartition::ReportStats(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::ReportStats(CSpatialPartition *this, const char *pFileName)
{
  CVoxelTree *m_VoxelTrees; // esi
  int i; // edi
  int v5; // [esp+0h] [ebp-Ch]

  _Msg(
    a1: "Handle Count %d (%d bytes, %d total)\n",
    this->m_aHandles.m_ElementCount,
    60 * this->m_aHandles.m_ElementCount,
    v5);
  m_VoxelTrees = this->m_VoxelTrees;
  for ( i = 2; i != 0; --i )
  {
    m_VoxelTrees->ReportStats(this: m_VoxelTrees, a2: pFileName);
    ++m_VoxelTrees;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D94C0
// Name: public: void CUtlHashFixed<int,512,class CUtlHashFixedGenericHash<512>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::Remove(
        CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *this,
        CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *hHash)
{
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *pNext; // eax
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> > *v4; // ebx

  pNext = hHash->pNext;
  v4 = &this->m_aBuckets[((unsigned __int16)(HIBYTE(hHash->elem.m_uiKey)
                                           + 33
                                           * (BYTE2(hHash->elem.m_uiKey)
                                            + 33
                                            * (BYTE1(hHash->elem.m_uiKey)
                                             + 33 * ((unsigned __int8)hHash->elem.m_uiKey - 21846))))
                        ^ ((unsigned int)(HIBYTE(hHash->elem.m_uiKey)
                                        + 33
                                        * ((unsigned __int8)BYTE2(hHash->elem.m_uiKey)
                                         + 33
                                         * ((unsigned __int8)BYTE1(hHash->elem.m_uiKey)
                                          + 33 * ((unsigned __int8)hHash->elem.m_uiKey - 1431655766)))) >> 16))
                       & 0x1FF];
  if ( pNext == hHash )
  {
    v4->m_pFirst = nullptr;
  }
  else
  {
    if ( v4->m_pFirst == hHash )
      v4->m_pFirst = pNext;
    hHash->pNext->pPrev = hHash->pPrev;
    hHash->pPrev->pNext = hHash->pNext;
  }
  free(pMem: hHash);
  --v4->m_nElems;
  --this->m_nElements;
}

//------------------------------------------------------------------------------
// Address: 0x101D9570
// Name: public: int CUtlHashFixed<int,512,class CUtlHashFixedGenericHash<512>>::Find(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *__thiscall CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::Find(
        CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *this,
        unsigned int uiKey)
{
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *m_pFirst; // ecx
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *result; // eax

  m_pFirst = this->m_aBuckets[((unsigned __int16)(HIBYTE(uiKey)
                                                + 33
                                                * (BYTE2(uiKey)
                                                 + 33 * (BYTE1(uiKey) + 33 * ((unsigned __int8)uiKey - 21846))))
                             ^ ((HIBYTE(uiKey)
                               + 33
                               * (BYTE2(uiKey)
                                + 33 * (BYTE1(uiKey) + 33 * ((unsigned int)(unsigned __int8)uiKey - 1431655766)))) >> 16))
                            & 0x1FF].m_pFirst;
  result = m_pFirst;
  if ( m_pFirst == nullptr )
    return (CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *)-1;
  while ( result->elem.m_uiKey != uiKey )
  {
    result = result->pNext;
    if ( result == m_pFirst || result == nullptr )
      return (CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *)-1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D95F0
// Name: public: CUtlPtrLinkedList<struct CUtlHashFixed<int,512,class CUtlHashFixedGenericHash<512>>::HashFixedData_t_<int>>::~CUtlPtrLinkedList<struct CUtlHashFixed<int,512,class CUtlHashFixedGenericHash<512>>::HashFixedData_t_<int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::HashFixedData_t_<int>>::~CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::HashFixedData_t_<int>>(
        CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> > *this)
{
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *m_pFirst; // eax
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *pNext; // edi

  m_pFirst = this->m_pFirst;
  if ( this->m_pFirst != nullptr )
  {
    do
    {
      pNext = m_pFirst->pNext;
      free(pMem: m_pFirst);
      m_pFirst = pNext;
    }
    while ( pNext != this->m_pFirst );
  }
  this->m_nElems = 0;
  this->m_pFirst = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101D9630
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<struct LeafListData_t,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct LeafListData_t,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // edx
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1] && i < (unsigned int)&m_pBlockHeader[2 * m_pBlockHeader->m_nBlockSize + 1] )
    return (int)i > (int)&m_pBlockHeader[2 * m_nIndex + 1];
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[2 * m_pNext->m_nBlockSize + 1] )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x101D96B0
// Name: public: void CVoxelTree::EndVisit(class CVarBitVec __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelTree::EndVisit(CVoxelTree *this, CVarBitVec *pPrev)
{
  void *v3; // edi

  v3 = GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index);
  CTSListBase::Push(this: &this->m_FreeVisits, pNode: (TSLNodeBase_t *)&this->m_pVisits[(_DWORD)v3][-1].m_pInt);
  this->m_pVisits[(_DWORD)v3] = pPrev;
}

//------------------------------------------------------------------------------
// Address: 0x101D96F0
// Name: public: CUtlHashFixed<int,512,class CUtlHashFixedGenericHash<512>>::~CUtlHashFixed<int,512,class CUtlHashFixedGenericHash<512>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::~CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>(
        CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *this)
{
  int *p_m_nElements; // esi
  int i; // ebx
  _DWORD *v4; // eax
  _DWORD *v5; // edi

  CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::RemoveAll(this);
  p_m_nElements = &this->m_nElements;
  for ( i = 511; i >= 0; --i )
  {
    v4 = (_DWORD *)*(p_m_nElements - 2);
    p_m_nElements -= 2;
    if ( v4 != nullptr )
    {
      do
      {
        v5 = (_DWORD *)v4[3];
        free(pMem: v4);
        v4 = v5;
      }
      while ( v5 != (_DWORD *)*p_m_nElements );
    }
    *p_m_nElements = 0;
    p_m_nElements[1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D9C00
// Name: public: void CVoxelHash::UpdateListMask(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelHash::UpdateListMask(CVoxelHash *this, Voxel_t hPartition)
{
  unsigned __int8 *m_pBase; // eax
  __int16 v3; // dx
  unsigned __int8 *v4; // eax
  int v5; // esi
  unsigned int v6; // edi
  int v7; // eax
  int v8; // eax
  __int16 v9; // cx
  unsigned int v10; // edx
  signed int v11; // eax
  int v12; // esi
  int v13; // edi
  unsigned int v14; // esi
  unsigned int v15; // ecx
  unsigned int v16; // esi
  int v17; // edi
  int v18; // eax
  int v19; // eax
  int cz; // [esp+14h] [ebp-1Ch]
  int cy; // [esp+18h] [ebp-18h]
  int v23; // [esp+20h] [ebp-10h]
  unsigned int v24; // [esp+24h] [ebp-Ch]
  __int16 nListMask; // [esp+28h] [ebp-8h]
  Voxel_t vmin; // [esp+2Ch] [ebp-4h]

  m_pBase = this->m_pTree->m_pOwner->m_aHandles.m_Memory.m_MemoryStack.m_pBase;
  v3 = *(_WORD *)&m_pBase[60 * LOWORD(hPartition.uiVoxel) + 36];
  v4 = &m_pBase[60 * LOWORD(hPartition.uiVoxel)];
  v5 = *((_DWORD *)v4 + 7);
  v6 = *((_DWORD *)v4 + 3);
  nListMask = v3;
  vmin.uiVoxel = v6;
  if ( v6 == v5 )
  {
    v7 = CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::Find(this: &this->m_aVoxelHash, uiKey: v6);
    if ( v7 != -1 )
    {
      v8 = *(_DWORD *)(v7 + 4);
      if ( v8 != 0 )
      {
        while ( *(_WORD *)v8 != hPartition.bitsVoxel )
        {
          v8 = *(_DWORD *)(v8 + 8);
          if ( v8 == 0 )
            goto LABEL_8;
        }
        *(_WORD *)(v8 + 2) = nListMask;
      }
    }
  }
LABEL_8:
  v9 = v5 - v6;
  v10 = ((v5 - v6) >> 11) & 0x7FF;
  v11 = (v5 - v6) >> 22;
  v12 = ((unsigned __int16)v6 ^ *(_WORD *)&hPartition.bitsVoxel) & 0x7FF ^ hPartition.uiVoxel;
  cy = v10;
  cz = v11;
  v13 = v6 & 0x3FF800;
  v23 = (v9 & 0x7FF) + 1;
  do
  {
    v14 = v13 | v12 & 0xFFC007FF;
    v15 = vmin.uiVoxel & 0xFFC00000;
    v24 = v10 + 1;
    do
    {
      v16 = v15 | v14 & 0x3FFFFF;
      if ( v11 >= 0 )
      {
        v17 = v11 + 1;
        do
        {
          v18 = CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::Find(this: &this->m_aVoxelHash, uiKey: v16);
          if ( v18 != -1 )
          {
            v19 = *(_DWORD *)(v18 + 4);
            if ( v19 != 0 )
            {
              while ( *(_WORD *)v19 != hPartition.bitsVoxel )
              {
                v19 = *(_DWORD *)(v19 + 8);
                if ( v19 == 0 )
                  goto LABEL_18;
              }
              *(_WORD *)(v19 + 2) = nListMask;
            }
          }
LABEL_18:
          v16 = ((v16 & 0xFFC00000) + 0x400000) ^ v16 & 0x3FFFFF;
          --v17;
        }
        while ( v17 != 0 );
        v10 = cy;
        v11 = cz;
        v15 = vmin.uiVoxel & 0xFFC00000;
      }
      v14 = (v16 ^ ((v16 & 0xFFFFF800) + 2048)) & 0x3FF800 ^ v16;
      --v24;
    }
    while ( v24 != 0 );
    v13 = vmin.uiVoxel & 0x3FF800;
    v12 = ((unsigned __int16)v14 ^ (unsigned __int16)(v14 + 1)) & 0x7FF ^ v14;
    --v23;
  }
  while ( v23 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x101D9D80
// Name: public: bool CVoxelHash::EnumerateElementsAtPoint(int,union Voxel_t,class Vector const __near &,class IPartitionEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVoxelHash::EnumerateElementsAtPoint(
        CVoxelHash *this,
        int listMask,
        Voxel_t v,
        const Vector *pt,
        IPartitionEnumerator *pIterator)
{
  int v6; // eax
  unsigned __int16 *v7; // edi
  int v8; // eax
  int v9; // ecx
  unsigned __int8 *v10; // esi

  v6 = CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::Find(this: &this->m_aVoxelHash, uiKey: v.uiVoxel);
  if ( v6 == -1 )
    return 1;
  v7 = *(unsigned __int16 **)(v6 + 4);
  if ( v7 == nullptr )
    return 1;
  while ( 1 )
  {
    v8 = *v7;
    v9 = v7[1];
    v7 = *((unsigned __int16 **)v7 + 2);
    if ( (_WORD)v8 != 0xFFFF && (v9 & listMask) != 0 )
    {
      v10 = &this->m_pTree->m_pOwner->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * v8];
      if ( (v10[38] & 1) == 0
        && IsPointInBox(pt, boxMin: (const Vector *)v10, boxMax: (const Vector *)(v10 + 16))
        && pIterator->EnumElement(this: pIterator, a2: *((IHandleEntity **)v10 + 8)) == 1 )
      {
        break;
      }
    }
    if ( v7 == nullptr )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101D9E20
// Name: public: void CVoxelHash::RenderObjectInVoxel(unsigned short,class CPartitionVisitor __near *,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CVoxelHash::RenderObjectInVoxel(
        CVoxelHash *this,
        unsigned __int16 hPartition,
        CPartitionVisitor *pVisitor,
        float flTime)
{
  unsigned __int8 *v5; // edi
  unsigned int *v6; // eax
  int v7; // edx
  float v8; // xmm1_4
  float v9; // xmm2_4
  int v10; // xmm3_4
  int v11; // xmm4_4
  int v12; // xmm5_4
  int v13; // [esp-20h] [ebp-84h]
  int v14; // [esp-1Ch] [ebp-80h]
  int v15; // [esp-18h] [ebp-7Ch]
  Vector origin; // [esp+4h] [ebp-60h] BYREF
  _BYTE vecPoints[84]; // [esp+10h] [ebp-54h] OVERLAPPED BYREF

  if ( hPartition != 0xFFFF )
  {
    v5 = &this->m_pTree->m_pOwner->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * hPartition];
    v6 = &pVisitor->m_pVisits->m_pInt[(int)*(unsigned __int16 *)&v5[2 * pVisitor->m_iTree + 42] >> 5];
    v7 = 1 << (*(_WORD *)&v5[2 * pVisitor->m_iTree + 42] & 0x1F);
    if ( (v7 & *v6) == 0 )
    {
      *v6 |= v7;
      CDebugOverlay::AddBoxOverlay(
        origin: &vec3_origin,
        mins: (const Vector *)v5,
        maxs: (const Vector *)(v5 + 16),
        angles: &vec3_angle,
        r: s_pVoxelColor[this->m_nLevel]._color[0],
        g: s_pVoxelColor[this->m_nLevel]._color[1],
        b: (const Vector *)s_pVoxelColor[this->m_nLevel]._color[2],
        a: (const Vector *)0x4B,
        flDuration: flTime);
      v8 = *((float *)v5 + 1);
      v9 = *((float *)v5 + 2);
      v10 = *((_DWORD *)v5 + 4);
      v11 = *((_DWORD *)v5 + 5);
      v12 = *((_DWORD *)v5 + 6);
      v15 = s_pVoxelColor[this->m_nLevel]._color[2];
      v14 = s_pVoxelColor[this->m_nLevel]._color[1];
      v13 = s_pVoxelColor[this->m_nLevel]._color[0];
      origin.x = *(float *)v5;
      origin.y = v8;
      origin.z = v9;
      *(float *)vecPoints = origin.x;
      *(_DWORD *)&vecPoints[4] = v11;
      *(float *)&vecPoints[8] = v9;
      *(_DWORD *)&vecPoints[12] = v10;
      *(_DWORD *)&vecPoints[16] = v11;
      *(float *)&vecPoints[20] = v9;
      *(_DWORD *)&vecPoints[24] = v10;
      *(float *)&vecPoints[28] = v8;
      *(float *)&vecPoints[32] = v9;
      *(float *)&vecPoints[36] = origin.x;
      *(float *)&vecPoints[40] = v8;
      *(_DWORD *)&vecPoints[44] = v12;
      *(float *)&vecPoints[48] = origin.x;
      *(_DWORD *)&vecPoints[52] = v11;
      *(_DWORD *)&vecPoints[56] = v12;
      *(_DWORD *)&vecPoints[60] = v10;
      *(_DWORD *)&vecPoints[64] = v11;
      *(_DWORD *)&vecPoints[68] = v12;
      *(_DWORD *)&vecPoints[72] = v10;
      *(float *)&vecPoints[76] = v8;
      *(_DWORD *)&vecPoints[80] = v12;
      CDebugOverlay::AddLineOverlay(
        &origin,
        dest: (const Vector *)vecPoints,
        r: v13,
        g: v14,
        b: v15,
        a: 255,
        noDepthTest: true,
        flDuration: flTime);
      CDebugOverlay::AddLineOverlay(
        origin: (const Vector *)vecPoints,
        dest: (const Vector *)&vecPoints[12],
        r: s_pVoxelColor[this->m_nLevel]._color[0],
        g: s_pVoxelColor[this->m_nLevel]._color[1],
        b: s_pVoxelColor[this->m_nLevel]._color[2],
        a: 255,
        noDepthTest: true,
        flDuration: flTime);
      CDebugOverlay::AddLineOverlay(
        origin: (const Vector *)&vecPoints[12],
        dest: (const Vector *)&vecPoints[24],
        r: s_pVoxelColor[this->m_nLevel]._color[0],
        g: s_pVoxelColor[this->m_nLevel]._color[1],
        b: s_pVoxelColor[this->m_nLevel]._color[2],
        a: 255,
        noDepthTest: true,
        flDuration: flTime);
      CDebugOverlay::AddLineOverlay(
        origin: (const Vector *)&vecPoints[24],
        dest: &origin,
        r: s_pVoxelColor[this->m_nLevel]._color[0],
        g: s_pVoxelColor[this->m_nLevel]._color[1],
        b: s_pVoxelColor[this->m_nLevel]._color[2],
        a: 255,
        noDepthTest: true,
        flDuration: flTime);
      CDebugOverlay::AddLineOverlay(
        origin: (const Vector *)&vecPoints[36],
        dest: (const Vector *)&vecPoints[48],
        r: s_pVoxelColor[this->m_nLevel]._color[0],
        g: s_pVoxelColor[this->m_nLevel]._color[1],
        b: s_pVoxelColor[this->m_nLevel]._color[2],
        a: 255,
        noDepthTest: true,
        flDuration: flTime);
      CDebugOverlay::AddLineOverlay(
        origin: (const Vector *)&vecPoints[48],
        dest: (const Vector *)&vecPoints[60],
        r: s_pVoxelColor[this->m_nLevel]._color[0],
        g: s_pVoxelColor[this->m_nLevel]._color[1],
        b: s_pVoxelColor[this->m_nLevel]._color[2],
        a: 255,
        noDepthTest: true,
        flDuration: flTime);
      CDebugOverlay::AddLineOverlay(
        origin: (const Vector *)&vecPoints[60],
        dest: (const Vector *)&vecPoints[72],
        r: s_pVoxelColor[this->m_nLevel]._color[0],
        g: s_pVoxelColor[this->m_nLevel]._color[1],
        b: s_pVoxelColor[this->m_nLevel]._color[2],
        a: 255,
        noDepthTest: true,
        flDuration: flTime);
      CDebugOverlay::AddLineOverlay(
        origin: (const Vector *)&vecPoints[72],
        dest: (const Vector *)&vecPoints[36],
        r: s_pVoxelColor[this->m_nLevel]._color[0],
        g: s_pVoxelColor[this->m_nLevel]._color[1],
        b: s_pVoxelColor[this->m_nLevel]._color[2],
        a: 255,
        noDepthTest: true,
        flDuration: flTime);
      CDebugOverlay::AddLineOverlay(
        &origin,
        dest: (const Vector *)&vecPoints[36],
        r: s_pVoxelColor[this->m_nLevel]._color[0],
        g: s_pVoxelColor[this->m_nLevel]._color[1],
        b: s_pVoxelColor[this->m_nLevel]._color[2],
        a: 255,
        noDepthTest: true,
        flDuration: flTime);
      CDebugOverlay::AddLineOverlay(
        origin: (const Vector *)&vecPoints[24],
        dest: (const Vector *)&vecPoints[72],
        r: s_pVoxelColor[this->m_nLevel]._color[0],
        g: s_pVoxelColor[this->m_nLevel]._color[1],
        b: s_pVoxelColor[this->m_nLevel]._color[2],
        a: 255,
        noDepthTest: true,
        flDuration: flTime);
      CDebugOverlay::AddLineOverlay(
        origin: (const Vector *)vecPoints,
        dest: (const Vector *)&vecPoints[48],
        r: s_pVoxelColor[this->m_nLevel]._color[0],
        g: s_pVoxelColor[this->m_nLevel]._color[1],
        b: s_pVoxelColor[this->m_nLevel]._color[2],
        a: 255,
        noDepthTest: true,
        flDuration: flTime);
      CDebugOverlay::AddLineOverlay(
        origin: (const Vector *)&vecPoints[12],
        dest: (const Vector *)&vecPoints[60],
        r: s_pVoxelColor[this->m_nLevel]._color[0],
        g: s_pVoxelColor[this->m_nLevel]._color[1],
        b: s_pVoxelColor[this->m_nLevel]._color[2],
        a: 255,
        noDepthTest: true,
        flDuration: flTime);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DA280
// Name: public: void CVoxelTree::UpdateListMask(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelTree::UpdateListMask(CVoxelTree *this, Voxel_t hPartition)
{
  CThreadSpinRWLock *p_m_lock; // edi
  signed __int32 m_i32; // ecx
  int nLevel; // [esp+4h] [ebp-4h]

  nLevel = (char)this->m_pOwner->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * LOWORD(hPartition.uiVoxel)
                                                                         + 39
                                                                         + this->m_TreeId];
  if ( nLevel >= 0 )
  {
    p_m_lock = &this->m_lock;
    if ( (this->m_lock.m_lockInfo.m_i32 & 0x10000) != 0
      || (m_i32 = (unsigned __int16)p_m_lock->m_lockInfo.m_i32,
          _InterlockedCompareExchange((volatile signed __int32 *)p_m_lock, m_i32 + 1, m_i32) != m_i32) )
    {
      CThreadSpinRWLock::SpinLockForRead(this: &this->m_lock);
    }
    CVoxelHash::UpdateListMask(this: &this->m_pVoxelHash[nLevel], hPartition);
    _InterlockedExchangeAdd((volatile signed __int32 *)p_m_lock, 0xFFFFFFFF);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DA310
// Name: public: virtual void CVoxelTree::EnumerateElementsAtPoint(int,class Vector const __near &,bool,class IPartitionEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelTree::EnumerateElementsAtPoint(
        CVoxelTree *this,
        int listMask,
        const Vector *pt,
        bool coarseTest,
        IPartitionEnumerator *pIterator)
{
  CThreadSpinRWLock::LockInfo_t m_lockInfo; // eax
  CThreadSpinRWLock *p_m_lock; // ecx
  signed __int32 m_i32; // edx
  CVoxelHash *m_pVoxelHash; // eax
  unsigned int v10; // esi
  unsigned int v11; // esi
  unsigned int v12; // esi
  CThreadSpinRWLock *v14; // [esp+8h] [ebp-4h]

  if ( listMask != 0 )
  {
    m_lockInfo = this->m_lock.m_lockInfo;
    p_m_lock = &this->m_lock;
    v14 = &this->m_lock;
    if ( (m_lockInfo.m_i32 & 0x10000) != 0
      || (m_i32 = (unsigned __int16)p_m_lock->m_lockInfo.m_i32,
          _InterlockedCompareExchange((volatile signed __int32 *)p_m_lock, m_i32 + 1, m_i32) != m_i32) )
    {
      CThreadSpinRWLock::SpinLockForRead(this: p_m_lock);
    }
    m_pVoxelHash = this->m_pVoxelHash;
    v10 = ((int)(float)(pt->x - m_pVoxelHash->m_vecVoxelOrigin.x) >> m_pVoxelHash->m_nLevelShift) & 0x7FF
        | ((((int)(float)(pt->z - m_pVoxelHash->m_vecVoxelOrigin.z) >> m_pVoxelHash->m_nLevelShift << 11)
          | ((int)(float)(pt->y - m_pVoxelHash->m_vecVoxelOrigin.y) >> m_pVoxelHash->m_nLevelShift) & 0x7FF) << 11);
    if ( CVoxelHash::EnumerateElementsAtPoint(this: m_pVoxelHash, listMask, v: (Voxel_t)v10, pt, pIterator) != 0 )
    {
      v11 = (v10 >> 2) & 0x3FCFF9FF;
      if ( CVoxelHash::EnumerateElementsAtPoint(this: this->m_pVoxelHash + 1, listMask, v: (Voxel_t)v11, pt, pIterator) != 0 )
      {
        v12 = (v11 >> 2) & 0x3FCFF9FF;
        if ( CVoxelHash::EnumerateElementsAtPoint(
               this: this->m_pVoxelHash + 2,
               listMask,
               v: (Voxel_t)v12,
               pt,
               pIterator) != 0 )
          CVoxelHash::EnumerateElementsAtPoint(
            this: this->m_pVoxelHash + 3,
            listMask,
            v: (Voxel_t)((v12 >> 2) & 0x3FCFF9FF),
            pt,
            pIterator);
      }
    }
    _InterlockedExchangeAdd((volatile signed __int32 *)v14, 0xFFFFFFFF);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DA470
// Name: public: virtual void CSpatialPartition::Insert(int,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::Insert(CSpatialPartition *this, __int16 listId, unsigned __int16 handle)
{
  unsigned __int8 *v4; // esi
  __int16 v5; // ax
  bool v6; // zf

  v4 = &this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * handle];
  v5 = listId | *((_WORD *)v4 + 18);
  if ( *((_WORD *)v4 + 18) != v5 )
  {
    v6 = (v4[38] & 2) == 0;
    *((_WORD *)v4 + 18) = v5;
    if ( !v6 )
      CVoxelTree::UpdateListMask(this: this->m_VoxelTrees, hPartition: handle);
    if ( (v4[38] & 4) != 0 )
      CVoxelTree::UpdateListMask(this: &this->m_VoxelTrees[1], hPartition: handle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DA4D0
// Name: public: virtual void CSpatialPartition::Remove(int,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::Remove(CSpatialPartition *this, __int16 listId, unsigned __int16 handle)
{
  unsigned __int8 *v4; // esi
  __int16 v5; // ax
  bool v6; // zf

  v4 = &this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * handle];
  v5 = ~listId & *((_WORD *)v4 + 18);
  if ( *((_WORD *)v4 + 18) != v5 )
  {
    v6 = (v4[38] & 2) == 0;
    *((_WORD *)v4 + 18) = v5;
    if ( !v6 )
      CVoxelTree::UpdateListMask(this: this->m_VoxelTrees, hPartition: handle);
    if ( (v4[38] & 4) != 0 )
      CVoxelTree::UpdateListMask(this: &this->m_VoxelTrees[1], hPartition: handle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DA530
// Name: public: virtual void CSpatialPartition::RemoveAndInsert(int,int,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::RemoveAndInsert(
        CSpatialPartition *this,
        __int16 removeMask,
        __int16 insertMask,
        unsigned __int16 handle)
{
  unsigned __int8 *v5; // esi
  __int16 v6; // ax
  bool v7; // zf

  v5 = &this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * handle];
  v6 = insertMask | ~removeMask & *((_WORD *)v5 + 18);
  if ( *((_WORD *)v5 + 18) != v6 )
  {
    v7 = (v5[38] & 2) == 0;
    *((_WORD *)v5 + 18) = v6;
    if ( !v7 )
      CVoxelTree::UpdateListMask(this: this->m_VoxelTrees, hPartition: handle);
    if ( (v5[38] & 4) != 0 )
      CVoxelTree::UpdateListMask(this: &this->m_VoxelTrees[1], hPartition: handle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DA590
// Name: public: virtual void CSpatialPartition::Remove(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::Remove(CSpatialPartition *this, unsigned __int16 handle)
{
  unsigned __int8 *v3; // edi
  bool v4; // zf

  v3 = &this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * handle];
  if ( *((_WORD *)v3 + 18) != 0 )
  {
    v4 = (v3[38] & 2) == 0;
    *((_WORD *)v3 + 18) = 0;
    if ( !v4 )
      CVoxelTree::UpdateListMask(this: this->m_VoxelTrees, hPartition: handle);
    if ( (v3[38] & 4) != 0 )
      CVoxelTree::UpdateListMask(this: &this->m_VoxelTrees[1], hPartition: handle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DA5F0
// Name: public: virtual void CSpatialPartition::UnhideElement(unsigned short,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::UnhideElement(CSpatialPartition *this, unsigned __int16 handle, int tempHandle)
{
  CThreadFastMutex *p_m_HandlesMutex; // esi
  DWORD CurrentThreadId; // ecx

  p_m_HandlesMutex = &this->m_HandlesMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_HandlesMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_HandlesMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_HandlesMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_HandlesMutex->m_depth;
  }
  this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * handle + 38] &= ~1u;
  if ( p_m_HandlesMutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_HandlesMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x101DA660
// Name: public: virtual int CSpatialPartition::HideElement(unsigned short)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSpatialPartition::HideElement(CSpatialPartition *this, unsigned __int16 handle)
{
  CThreadFastMutex *p_m_HandlesMutex; // esi
  DWORD CurrentThreadId; // ecx

  p_m_HandlesMutex = &this->m_HandlesMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_HandlesMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_HandlesMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_HandlesMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_HandlesMutex->m_depth;
  }
  this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * handle + 38] |= 1u;
  if ( p_m_HandlesMutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_HandlesMutex, 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101DA6D0
// Name: public: virtual void CSpatialPartition::ElementMoved(unsigned short,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::ElementMoved(
        CSpatialPartition *this,
        int handle,
        const Vector *mins,
        const Vector *maxs)
{
  unsigned __int8 *m_pBase; // edx
  int v7; // eax
  unsigned __int8 *v8; // esi
  int listMask; // [esp+14h] [ebp+8h]

  m_pBase = this->m_aHandles.m_Memory.m_MemoryStack.m_pBase;
  v7 = *(unsigned __int16 *)&m_pBase[60 * (unsigned __int16)handle + 36];
  v8 = &m_pBase[60 * (unsigned __int16)handle];
  listMask = v7;
  if ( (v7 & 0x1AC) != 0 )
  {
    this->m_VoxelTrees[0].ElementMoved(this: this->m_VoxelTrees, a2: handle, a3: mins, a4: maxs);
    v8[38] |= 2u;
    v7 = listMask;
  }
  if ( (v7 & 0xFFFFFE53) != 0 )
  {
    this->m_VoxelTrees[1].ElementMoved(this: &this->m_VoxelTrees[1], a2: handle, a3: mins, a4: maxs);
    v8[38] |= 4u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DA750
// Name: public: virtual void CVoxelTree::ReportStats(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelTree::ReportStats(CVoxelTree *this, const char *pFileName)
{
  CVoxelTree *v2; // esi
  int v3; // ebx
  int v4; // edx
  CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *p_m_aVoxelHash; // edi
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *m_pFirst; // ecx
  int j; // eax
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *pNext; // eax
  int i; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]

  v2 = this;
  _Msg(a1: "Histogram : Entities per level\n");
  v3 = 0;
  if ( v2->m_nLevelCount > 0 )
  {
    v11 = 0;
    do
    {
      v4 = 0;
      p_m_aVoxelHash = &v2->m_pVoxelHash[v11].m_aVoxelHash;
      for ( i = 512; i != 0; --i )
      {
        if ( p_m_aVoxelHash->m_aBuckets[0].m_nElems != 0 )
        {
          m_pFirst = p_m_aVoxelHash->m_aBuckets[0].m_pFirst;
          if ( p_m_aVoxelHash->m_aBuckets[0].m_pFirst != nullptr )
          {
            do
            {
              for ( j = m_pFirst->elem.m_Data; j != 0; ++v4 )
                j = *(_DWORD *)(j + 8);
              pNext = m_pFirst->pNext;
              if ( pNext == p_m_aVoxelHash->m_aBuckets[0].m_pFirst )
                break;
              m_pFirst = m_pFirst->pNext;
            }
            while ( pNext != nullptr );
          }
        }
        p_m_aVoxelHash = (CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *)((char *)p_m_aVoxelHash + 8);
      }
      _Msg(a1: "\t%d - %d\n", v3, v4);
      v2 = this;
      ++v11;
      ++v3;
    }
    while ( v3 < this->m_nLevelCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DA860
// Name: public: bool CVoxelHash::EnumerateElementsInSingleVoxel<class CIntersectBox>(union Voxel_t,class CIntersectBox const __near &,int,class IPartitionEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVoxelHash::EnumerateElementsInSingleVoxel<CIntersectBox>(
        CVoxelHash *this,
        Voxel_t voxel,
        const CIntersectBox *intersectTest,
        int listMask,
        IPartitionEnumerator *pIterator)
{
  int v6; // eax
  unsigned __int16 *v7; // esi
  int v8; // eax
  int v9; // ecx
  unsigned __int8 *m_pBase; // edx
  bool v11; // zf
  unsigned __int8 *v12; // eax
  const Vector *m_vecMaxs; // edx
  const Vector *m_vecMins; // ecx

  v6 = CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::Find(this: &this->m_aVoxelHash, uiKey: voxel.uiVoxel);
  if ( v6 == -1 )
    return 1;
  v7 = *(unsigned __int16 **)(v6 + 4);
  if ( v7 == nullptr )
    return 1;
  while ( 1 )
  {
    v8 = *v7;
    v9 = v7[1];
    v7 = *((unsigned __int16 **)v7 + 2);
    if ( (_WORD)v8 != 0xFFFF && (v9 & listMask) != 0 )
    {
      m_pBase = this->m_pTree->m_pOwner->m_aHandles.m_Memory.m_MemoryStack.m_pBase;
      v11 = (m_pBase[60 * v8 + 38] & 1) == 0;
      v12 = &m_pBase[60 * v8];
      if ( v11 )
      {
        m_vecMaxs = intersectTest->m_vecMaxs;
        if ( m_vecMaxs->x >= *(float *)v12 )
        {
          m_vecMins = intersectTest->m_vecMins;
          if ( *((float *)v12 + 4) >= m_vecMins->x
            && m_vecMaxs->y >= *((float *)v12 + 1)
            && *((float *)v12 + 5) >= m_vecMins->y
            && m_vecMaxs->z >= *((float *)v12 + 2)
            && *((float *)v12 + 6) >= m_vecMins->z
            && pIterator->EnumElement(this: pIterator, a2: *((IHandleEntity **)v12 + 8)) == 1 )
          {
            break;
          }
        }
      }
    }
    if ( v7 == nullptr )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DA940
// Name: public: bool CVoxelHash::EnumerateElementsInVoxel<class CIntersectBox>(union Voxel_t,class CIntersectBox const __near &,int,class IPartitionEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVoxelHash::EnumerateElementsInVoxel<CIntersectBox>(
        CVoxelHash *this,
        Voxel_t voxel,
        const CIntersectBox *intersectTest,
        unsigned __int16 listMask,
        IPartitionEnumerator *pIterator)
{
  CVoxelHash *v5; // esi
  int v6; // eax
  unsigned __int16 *v8; // ebx
  int v9; // eax
  int v10; // edx
  unsigned __int8 *m_pBase; // eax
  bool v12; // zf
  unsigned __int8 *v13; // eax
  unsigned int *v14; // esi
  int v15; // edx
  const Vector *m_vecMaxs; // ecx
  const Vector *m_vecMins; // edx

  v5 = this;
  v6 = CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::Find(this: &this->m_aVoxelHash, uiKey: voxel.uiVoxel);
  if ( v6 == -1 )
    return 1;
  v8 = *(unsigned __int16 **)(v6 + 4);
  if ( v8 == nullptr )
    return 1;
  while ( 1 )
  {
    v9 = *v8;
    if ( (_WORD)v9 != 0xFFFF )
    {
      if ( (v8[1] & listMask) == 0 )
        goto LABEL_16;
      v10 = 15 * v9;
      m_pBase = v5->m_pTree->m_pOwner->m_aHandles.m_Memory.m_MemoryStack.m_pBase;
      v12 = (m_pBase[4 * v10 + 38] & 1) == 0;
      v13 = &m_pBase[4 * v10];
      if ( !v12 )
        goto LABEL_16;
      v14 = &intersectTest->m_pVisits->m_pInt[(int)*(unsigned __int16 *)&v13[2 * intersectTest->m_iTree + 42] >> 5];
      v15 = 1 << (*(_WORD *)&v13[2 * intersectTest->m_iTree + 42] & 0x1F);
      if ( (v15 & *v14) == 0 )
      {
        *v14 |= v15;
        m_vecMaxs = intersectTest->m_vecMaxs;
        if ( m_vecMaxs->x >= *(float *)v13 )
        {
          m_vecMins = intersectTest->m_vecMins;
          if ( *((float *)v13 + 4) >= m_vecMins->x
            && m_vecMaxs->y >= *((float *)v13 + 1)
            && *((float *)v13 + 5) >= m_vecMins->y
            && m_vecMaxs->z >= *((float *)v13 + 2)
            && *((float *)v13 + 6) >= m_vecMins->z
            && pIterator->EnumElement(this: pIterator, a2: *((IHandleEntity **)v13 + 8)) == 1 )
          {
            return 0;
          }
        }
      }
      v5 = this;
    }
LABEL_16:
    v8 = *((unsigned __int16 **)v8 + 2);
    if ( v8 == nullptr )
      return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DAA60
// Name: public: bool CVoxelHash::EnumerateElementsInSingleVoxel<class CIntersectRay>(union Voxel_t,class CIntersectRay const __near &,int,class IPartitionEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CVoxelHash::EnumerateElementsInSingleVoxel<CIntersectRay>@<al>(
        CVoxelHash *this@<ecx>,
        int a2@<ebp>,
        Voxel_t voxel,
        const CIntersectRay *intersectTest,
        int listMask,
        IPartitionEnumerator *pIterator)
{
  CVoxelHash *v6; // esi
  int v7; // eax
  unsigned __int16 *v8; // edi
  int v10; // eax
  int v11; // ecx
  int v12; // esi
  __m128 v13; // [esp-30h] [ebp-3Ch] BYREF
  __m128 v14; // [esp-20h] [ebp-2Ch] BYREF
  CVoxelHash *v15; // [esp-4h] [ebp-10h]
  int v16; // [esp+0h] [ebp-Ch]
  void *v17; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v16 = a2;
  v17 = retaddr;
  v6 = this;
  v15 = this;
  v7 = CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::Find(this: &this->m_aVoxelHash, uiKey: voxel.uiVoxel);
  if ( v7 == -1 )
    return 1;
  v8 = *(unsigned __int16 **)(v7 + 4);
  if ( v8 == nullptr )
    return 1;
  while ( 1 )
  {
    v10 = *v8;
    v11 = v8[1];
    v8 = *((unsigned __int16 **)v8 + 2);
    if ( (_WORD)v10 != 0xFFFF && (v11 & listMask) != 0 )
    {
      v12 = (int)&v6->m_pTree->m_pOwner->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * v10];
      if ( (*(_BYTE *)(v12 + 38) & 1) == 0 )
      {
        v13 = *(__m128 *)v12;
        v14 = *(__m128 *)(v12 + 16);
        if ( IsBoxIntersectingRay(
               inBoxMin: &v13,
               inBoxMax: &v14,
               origin: &intersectTest->m_f4Start,
               delta: &intersectTest->m_f4Delta,
               invDelta: &intersectTest->m_f4InvDelta,
               vTolerance: &Four_Zeros)
          && pIterator->EnumElement(this: pIterator, a2: *(IHandleEntity **)(v12 + 32)) == 1 )
        {
          break;
        }
      }
    }
    if ( v8 == nullptr )
      return 1;
    v6 = v15;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DAB50
// Name: public: bool CVoxelHash::EnumerateElementsInVoxel<class CIntersectRay>(union Voxel_t,class CIntersectRay const __near &,int,class IPartitionEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CVoxelHash::EnumerateElementsInVoxel<CIntersectRay>@<al>(
        CVoxelHash *this@<ecx>,
        int a2@<ebp>,
        Voxel_t voxel,
        const CIntersectRay *intersectTest,
        unsigned __int16 listMask,
        IPartitionEnumerator *pIterator)
{
  int v6; // eax
  unsigned __int16 *v7; // ecx
  int v8; // eax
  int v9; // esi
  unsigned __int8 *m_pBase; // eax
  bool v11; // zf
  unsigned __int8 *v12; // esi
  unsigned int *v13; // edx
  int v14; // eax
  __m128 v16; // [esp-30h] [ebp-3Ch] BYREF
  __m128 v17; // [esp-20h] [ebp-2Ch] BYREF
  CVoxelHash *v18; // [esp-8h] [ebp-14h]
  unsigned __int16 *v19; // [esp-4h] [ebp-10h]
  int v20; // [esp+0h] [ebp-Ch]
  void *v21; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v20 = a2;
  v21 = retaddr;
  v18 = this;
  v6 = CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::Find(this: &this->m_aVoxelHash, uiKey: voxel.uiVoxel);
  if ( v6 == -1 )
    return 1;
  v7 = *(unsigned __int16 **)(v6 + 4);
  v19 = v7;
  if ( v7 == nullptr )
    return 1;
  while ( 1 )
  {
    v8 = *v7;
    if ( (_WORD)v8 != 0xFFFF && (v7[1] & listMask) != 0 )
    {
      v9 = 15 * v8;
      m_pBase = v18->m_pTree->m_pOwner->m_aHandles.m_Memory.m_MemoryStack.m_pBase;
      v11 = (m_pBase[4 * v9 + 38] & 1) == 0;
      v12 = &m_pBase[4 * v9];
      if ( v11 )
        break;
    }
LABEL_12:
    v19 = *((unsigned __int16 **)v7 + 2);
    if ( v19 == nullptr )
      return 1;
    v7 = v19;
  }
  v13 = &intersectTest->m_pVisits->m_pInt[(int)*(unsigned __int16 *)&v12[2 * intersectTest->m_iTree + 42] >> 5];
  v14 = 1 << (*(_WORD *)&v12[2 * intersectTest->m_iTree + 42] & 0x1F);
  if ( (v14 & *v13) != 0
    || (*v13 |= v14,
        v16 = *(__m128 *)v12,
        v17 = *((__m128 *)v12 + 1),
        !IsBoxIntersectingRay(
           inBoxMin: &v16,
           inBoxMax: &v17,
           origin: &intersectTest->m_f4Start,
           delta: &intersectTest->m_f4Delta,
           invDelta: &intersectTest->m_f4InvDelta,
           vTolerance: &Four_Zeros))
    || pIterator->EnumElement(this: pIterator, a2: *((IHandleEntity **)v12 + 8)) != 1 )
  {
    v7 = v19;
    goto LABEL_12;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DAC80
// Name: public: bool CVoxelHash::EnumerateElementsInVoxel<class CIntersectSweptBox>(union Voxel_t,class CIntersectSweptBox const __near &,int,class IPartitionEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVoxelHash::EnumerateElementsInVoxel<CIntersectSweptBox>(
        CVoxelHash *this,
        Voxel_t voxel,
        CIntersectSweptBox *intersectTest,
        unsigned __int16 listMask,
        IPartitionEnumerator *pIterator)
{
  CVoxelHash *v5; // esi
  int v6; // eax
  unsigned __int16 *v8; // ebx
  int v9; // eax
  int v10; // esi
  unsigned int *v11; // edx
  int v12; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  v5 = this;
  v6 = CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::Find(this: &this->m_aVoxelHash, uiKey: voxel.uiVoxel);
  if ( v6 == -1 )
    return 1;
  v8 = *(unsigned __int16 **)(v6 + 4);
  if ( v8 == nullptr )
    return 1;
  while ( 1 )
  {
    v9 = *v8;
    if ( (_WORD)v9 != 0xFFFF && (v8[1] & listMask) != 0 )
    {
      v10 = (int)&v5->m_pTree->m_pOwner->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * v9];
      if ( (*(_BYTE *)(v10 + 38) & 1) == 0 )
      {
        v11 = &intersectTest->m_pVisits->m_pInt[(int)*(unsigned __int16 *)(v10 + 2 * intersectTest->m_iTree + 42) >> 5];
        v12 = 1 << (*(_WORD *)(v10 + 2 * intersectTest->m_iTree + 42) & 0x1F);
        if ( (v12 & *v11) == 0 )
        {
          *v11 |= v12;
          if ( CIntersectSweptBox::Intersects(
                 this: intersectTest,
                 a2: (int)&savedregs,
                 pMins: (__m128 *)v10,
                 pMaxs: (__m128 *)(v10 + 16))
            && pIterator->EnumElement(this: pIterator, a2: *(IHandleEntity **)(v10 + 32)) == 1 )
          {
            break;
          }
        }
      }
    }
    if ( *((_DWORD *)v8 + 2) == 0 )
      return 1;
    v8 = *((unsigned __int16 **)v8 + 2);
    v5 = this;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DAF00
// Name: public: bool CVoxelHash::EnumerateElementsInBox(int,union Voxel_t,union Voxel_t,class Vector const __near &,class Vector const __near &,class IPartitionEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVoxelHash::EnumerateElementsInBox(
        CVoxelHash *this,
        int listMask,
        Voxel_t vmin,
        Voxel_t vmax,
        const Vector *mins,
        const Vector *maxs,
        IPartitionEnumerator *pIterator)
{
  CVoxelTree *m_pTree; // esi
  CVarBitVec *v9; // ecx
  int m_TreeId; // edx
  Voxel_t v12; // ecx
  int uiVoxel; // esi
  int v14; // edi
  int v15; // edx
  unsigned int v16; // esi
  Voxel_t v17; // esi
  signed int v18; // edi
  CIntersectBox rect; // [esp+Ch] [ebp-1Ch] BYREF
  int v20; // [esp+1Ch] [ebp-Ch]
  int cy; // [esp+20h] [ebp-8h]
  CVoxelHash *v22; // [esp+24h] [ebp-4h]
  int iX; // [esp+3Ch] [ebp+14h]
  int iY; // [esp+40h] [ebp+18h]

  m_pTree = this->m_pTree;
  v22 = this;
  v9 = m_pTree->m_pVisits[(_DWORD)GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index)];
  m_TreeId = m_pTree->m_TreeId;
  rect.m_pVisits = v9;
  rect.m_iTree = m_TreeId;
  rect.m_vecMins = mins;
  rect.m_vecMaxs = maxs;
  if ( vmin.uiVoxel == vmax.uiVoxel )
    return CVoxelHash::EnumerateElementsInSingleVoxel<CIntersectBox>(
             this,
             voxel: vmin,
             intersectTest: &rect,
             listMask,
             pIterator);
  v12.bitsVoxel = vmin.bitsVoxel;
  uiVoxel = vmin.uiVoxel;
  v14 = (*(_WORD *)&vmax.bitsVoxel - *(_WORD *)&vmin.bitsVoxel) & 0x7FF;
  v15 = ((vmax.uiVoxel - vmin.uiVoxel) >> 11) & 0x7FF;
  v20 = (unsigned __int16)v14;
  cy = v15;
  iX = 0;
  while ( 1 )
  {
    v16 = (v12.uiVoxel ^ uiVoxel) & 0x3FF800 ^ uiVoxel;
    iY = 0;
    if ( v15 >= 0 )
      break;
LABEL_11:
    ++iX;
    uiVoxel = ((unsigned __int16)v16 ^ (unsigned __int16)(v16 + 1)) & 0x7FF ^ v16;
    if ( iX > v14 )
      return 1;
  }
LABEL_5:
  v17.uiVoxel = v12.uiVoxel ^ (v12.uiVoxel ^ v16) & 0x3FFFFF;
  v18 = 0;
  while ( CVoxelHash::EnumerateElementsInVoxel<CIntersectBox>(
            this: v22,
            voxel: v17,
            intersectTest: &rect,
            listMask,
            pIterator) != 0 )
  {
    ++v18;
    v17.uiVoxel = ((v17.uiVoxel & 0xFFC00000) + 0x400000) ^ v17.uiVoxel & 0x3FFFFF;
    if ( v18 > (int)((vmax.uiVoxel - vmin.uiVoxel) >> 22) )
    {
      v12.bitsVoxel = vmin.bitsVoxel;
      v15 = cy;
      v16 = (v17.uiVoxel ^ ((v17.uiVoxel & 0xFFFFF800) + 2048)) & 0x3FF800 ^ v17.uiVoxel;
      if ( ++iY > cy )
      {
        v14 = v20;
        goto LABEL_11;
      }
      goto LABEL_5;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DB070
// Name: public: bool CVoxelHash::EnumerateElementsAlongRay_ExtrudedRaySlice(int,class IPartitionEnumerator __near *,class CIntersectSweptBox const __near &,int __near * const,int __near * const,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CVoxelHash::EnumerateElementsAlongRay_ExtrudedRaySlice@<al>(
        CVoxelHash *this@<ecx>,
        int a2@<ebp>,
        unsigned __int16 listMask,
        IPartitionEnumerator *pIterator,
        const CIntersectSweptBox *intersectSweptBox,
        int *voxelMin,
        int *voxelMax,
        int iAxis,
        int *pStep)
{
  int v9; // edx
  int v10; // ecx
  int v11; // eax
  float v12; // xmm0_4
  int v13; // edx
  int v14; // eax
  int v15; // esi
  int v16; // eax
  unsigned __int16 *v17; // ecx
  int v18; // eax
  int v19; // esi
  int v20; // eax
  bool v21; // zf
  int v22; // esi
  unsigned int *v23; // edx
  int v24; // eax
  __m128 v26; // [esp-2Ch] [ebp-5Ch] BYREF
  __m128 v27; // [esp-1Ch] [ebp-4Ch] BYREF
  int v28; // [esp-Ch] [ebp-3Ch]
  int v29; // [esp-8h] [ebp-38h]
  int v30; // [esp-4h] [ebp-34h]
  int mins[3]; // [esp+0h] [ebp-30h]
  int maxs[3]; // [esp+Ch] [ebp-24h]
  int iX; // [esp+18h] [ebp-18h]
  int iY; // [esp+1Ch] [ebp-14h]
  int iZ; // [esp+20h] [ebp-10h]
  int v36; // [esp+24h] [ebp-Ch]
  void *v37; // [esp+28h] [ebp-8h]
  void *retaddr; // [esp+30h] [ebp+0h]

  v36 = a2;
  v37 = retaddr;
  v9 = voxelMin[1];
  iX = (int)this;
  v10 = *voxelMin;
  v30 = voxelMin[2];
  v29 = v9;
  mins[0] = *voxelMax;
  v11 = voxelMax[2];
  mins[1] = voxelMax[1];
  mins[2] = v11;
  v12 = (float)pStep[iAxis];
  v28 = v10;
  if ( v12 >= 0.0 )
  {
    *(&v28 + iAxis) = mins[iAxis];
    v10 = v28;
  }
  else
  {
    mins[iAxis] = *(&v28 + iAxis);
  }
  v13 = v10;
  maxs[0] = v10;
  if ( v10 > mins[0] )
    return 1;
  while ( 1 )
  {
    iZ ^= ((unsigned __int16)v13 ^ (unsigned __int16)iZ) & 0x7FF;
    v14 = v29;
    maxs[1] = v29;
    if ( v29 <= mins[1] )
      break;
LABEL_24:
    maxs[0] = ++v13;
    if ( v13 > mins[0] )
      return 1;
  }
  while ( 1 )
  {
    v15 = v30;
    iZ ^= (iZ ^ (v14 << 11)) & 0x3FF800;
    maxs[2] = v30;
    if ( v30 <= mins[2] )
      break;
LABEL_22:
    maxs[1] = ++v14;
    if ( v14 > mins[1] )
    {
      v13 = maxs[0];
      goto LABEL_24;
    }
  }
  while ( 1 )
  {
    iZ = iZ & 0x3FFFFF | (v15 << 22);
    v16 = CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::Find(
            this: (CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *)(iX + 12),
            uiKey: iZ);
    if ( v16 != -1 )
    {
      v17 = *(unsigned __int16 **)(v16 + 4);
      iY = (int)v17;
      if ( v17 != nullptr )
        break;
    }
LABEL_20:
    maxs[2] = ++v15;
    if ( v15 > mins[2] )
    {
      v14 = maxs[1];
      goto LABEL_22;
    }
  }
  while ( 1 )
  {
    v18 = *v17;
    if ( (_WORD)v18 != 0xFFFF )
    {
      if ( (v17[1] & listMask) == 0 )
        goto LABEL_18;
      v19 = 15 * v18;
      v20 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(iX + 4168) + 192) + 16);
      v21 = (*(_BYTE *)(v20 + 4 * v19 + 38) & 1) == 0;
      v22 = v20 + 4 * v19;
      if ( !v21 )
        goto LABEL_18;
      v23 = &intersectSweptBox->m_pVisits->m_pInt[(int)*(unsigned __int16 *)(v22 + 2 * intersectSweptBox->m_iTree + 42) >> 5];
      v24 = 1 << (*(_WORD *)(v22 + 2 * intersectSweptBox->m_iTree + 42) & 0x1F);
      if ( (v24 & *v23) == 0 )
      {
        *v23 |= v24;
        v27 = _mm_add_ps(*(__m128 *)(v22 + 16), intersectSweptBox->m_f4Extents);
        v26 = _mm_sub_ps(*(__m128 *)v22, intersectSweptBox->m_f4Extents);
        if ( IsBoxIntersectingRay(
               inBoxMin: &v26,
               inBoxMax: &v27,
               origin: &intersectSweptBox->m_f4Start,
               delta: &intersectSweptBox->m_f4Delta,
               invDelta: &intersectSweptBox->m_f4InvDelta,
               vTolerance: &Four_Zeros)
          && pIterator->EnumElement(this: pIterator, a2: *(IHandleEntity **)(v22 + 32)) == 1 )
        {
          return 0;
        }
      }
      v17 = (unsigned __int16 *)iY;
    }
LABEL_18:
    iY = *((_DWORD *)v17 + 2);
    if ( iY == 0 )
    {
      v15 = maxs[2];
      goto LABEL_20;
    }
    v17 = (unsigned __int16 *)iY;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DB280
// Name: public: bool CVoxelTree::EnumerateElementsAlongRay_Ray(int,struct Ray_t const __near &,class Vector const __near &,class Vector const __near &,class IPartitionEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
char __userpurge CVoxelTree::EnumerateElementsAlongRay_Ray@<al>(
        CVoxelTree *this@<ecx>,
        Voxel_t a2@<ebp>,
        int listMask,
        const Ray_t *ray,
        const Vector *vecInvDelta,
        const Vector *vecEnd,
        IPartitionEnumerator *pIterator)
{
  CVoxelHash *m_pVoxelHash; // eax
  float v8; // xmm0_4
  int v9; // edx
  float v10; // ecx
  int v11; // esi
  int v12; // edx
  unsigned int v13; // esi
  Voxel_t v14; // edi
  int v15; // ecx
  int v16; // edx
  VectorAligned m_Delta; // xmm0
  __m128 v18; // xmm0
  unsigned int v19; // esi
  unsigned int v20; // esi
  unsigned int v22; // edi
  float v23; // xmm0_4
  Voxel_t v24; // eax
  Voxel_t v25; // ecx
  _DWORD v26[3]; // [esp-Ch] [ebp-8Ch] BYREF
  CIntersectRay intersectRay; // [esp+0h] [ebp-80h] BYREF
  float tDelta[3]; // [esp+40h] [ebp-40h] BYREF
  int nStep[3]; // [esp+4Ch] [ebp-34h] BYREF
  float tMax[3]; // [esp+58h] [ebp-28h] BYREF
  Voxel_t ov3; // [esp+64h] [ebp-1Ch]
  Voxel_t ov2; // [esp+68h] [ebp-18h]
  Voxel_t ov1; // [esp+6Ch] [ebp-14h]
  Voxel_t v3; // [esp+70h] [ebp-10h]
  Voxel_t v2; // [esp+74h] [ebp-Ch] BYREF
  void *v36; // [esp+78h] [ebp-8h]
  void *retaddr; // [esp+80h] [ebp+0h]

  v2.bitsVoxel = a2.bitsVoxel;
  v36 = retaddr;
  m_pVoxelHash = this->m_pVoxelHash;
  v8 = ray->m_Start.y - m_pVoxelHash->m_vecVoxelOrigin.y;
  v9 = (int)(float)(ray->m_Start.z - m_pVoxelHash->m_vecVoxelOrigin.z);
  ov1.uiVoxel = (unsigned int)this;
  v10 = *(float *)&m_pVoxelHash->m_nLevelShift;
  v11 = (v9 >> SLOBYTE(v10) << 11) | ((int)v8 >> SLOBYTE(v10)) & 0x7FF;
  v12 = (int)(float)(ray->m_Start.x - m_pVoxelHash->m_vecVoxelOrigin.x) >> SLOBYTE(v10);
  tMax[0] = v10;
  v13 = v12 & 0x7FF | (v11 << 11);
  HIBYTE(v3.uiVoxel) = v13 == (((int)(float)(vecEnd->x - m_pVoxelHash->m_vecVoxelOrigin.x) >> SLOBYTE(v10)) & 0x7FF
                             | ((((int)(float)(vecEnd->z - m_pVoxelHash->m_vecVoxelOrigin.z) >> SLOBYTE(v10) << 11)
                               | ((int)(float)(vecEnd->y - m_pVoxelHash->m_vecVoxelOrigin.y) >> SLOBYTE(v10)) & 0x7FF) << 11));
  v14.bitsVoxel = ov1.bitsVoxel;
  v15 = *(_DWORD *)(ov1.uiVoxel
                  + 4
                  * (_DWORD)GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index)
                  + 64);
  v16 = *(_DWORD *)(ov1.uiVoxel + 60);
  *(VectorAligned *)&intersectRay.m_iTree = ray->m_Start;
  m_Delta = ray->m_Delta;
  v26[1] = v16;
  *(VectorAligned *)((char *)&intersectRay.m_f4Start + 4) = m_Delta;
  v18 = *(__m128 *)&vecInvDelta->x;
  v26[0] = v15;
  *(__m128 *)((char *)&intersectRay.m_f4Delta + 4) = v18;
  if ( HIBYTE(v3.uiVoxel) != 0 )
  {
    if ( CVoxelHash::EnumerateElementsInSingleVoxel<CIntersectRay>(
           this: *(CVoxelHash **)(ov1.uiVoxel + 12),
           a2: (int)&v2,
           voxel: (Voxel_t)v13,
           intersectTest: (const CIntersectRay *)v26,
           listMask,
           pIterator) != 0 )
    {
      v19 = (v13 >> 2) & 0x3FCFF9FF;
      if ( CVoxelHash::EnumerateElementsInSingleVoxel<CIntersectRay>(
             this: (CVoxelHash *)(*(_DWORD *)(v14.uiVoxel + 12) + 4184),
             a2: (int)&v2,
             voxel: (Voxel_t)v19,
             intersectTest: (const CIntersectRay *)v26,
             listMask,
             pIterator) != 0 )
      {
        v20 = (v19 >> 2) & 0x3FCFF9FF;
        if ( CVoxelHash::EnumerateElementsInSingleVoxel<CIntersectRay>(
               this: (CVoxelHash *)(*(_DWORD *)(v14.uiVoxel + 12) + 8368),
               a2: (int)&v2,
               voxel: (Voxel_t)v20,
               intersectTest: (const CIntersectRay *)v26,
               listMask,
               pIterator) != 0 )
          return CVoxelHash::EnumerateElementsInSingleVoxel<CIntersectRay>(
                   this: (CVoxelHash *)(*(_DWORD *)(v14.uiVoxel + 12) + 12552),
                   a2: (int)&v2,
                   voxel: (Voxel_t)((v20 >> 2) & 0x3FCFF9FF),
                   intersectTest: (const CIntersectRay *)v26,
                   listMask,
                   pIterator);
      }
    }
    return 0;
  }
  CVoxelHash::LeafListRaySetup(
    this: *(CVoxelHash **)(ov1.uiVoxel + 12),
    ray,
    vecEnd,
    vecInvDelta,
    voxel: (Voxel_t)v13,
    pStep: (int *)tDelta,
    pMax: (float *)nStep,
    pDelta: &intersectRay.m_f4InvDelta.m128_f32[1]);
  memset(tMax, 255, sizeof(tMax));
  v22 = (v13 >> 2) & 0x3FCFF9FF;
  ov3.uiVoxel = (((v22 >> 2) & 0xFCFF9FF) >> 2) & 0x3CFF9FF;
  if ( CVoxelHash::EnumerateElementsInVoxel<CIntersectRay>(
         this: (CVoxelHash *)pIterator[3].__vftable,
         a2: (int)&v2,
         voxel: (Voxel_t)v13,
         intersectTest: (const CIntersectRay *)v26,
         listMask,
         pIterator) == 0 )
    return 0;
  while ( 1 )
  {
    v23 = *(float *)&nStep[2];
    if ( v22 != LODWORD(tMax[2]) )
    {
      if ( CVoxelHash::EnumerateElementsInVoxel<CIntersectRay>(
             this: (CVoxelHash *)&pIterator[3].__vftable[1046],
             a2: (int)&v2,
             voxel: (Voxel_t)v22,
             intersectTest: (const CIntersectRay *)v26,
             listMask,
             pIterator) == 0 )
        return 0;
      v23 = *(float *)&nStep[2];
    }
    if ( ov2.uiVoxel != LODWORD(tMax[1]) )
    {
      if ( CVoxelHash::EnumerateElementsInVoxel<CIntersectRay>(
             this: (CVoxelHash *)&pIterator[3].__vftable[2092],
             a2: (int)&v2,
             voxel: ov2,
             intersectTest: (const CIntersectRay *)v26,
             listMask,
             pIterator) == 0 )
        return 0;
      v23 = *(float *)&nStep[2];
    }
    v24.bitsVoxel = ov3.bitsVoxel;
    if ( ov3.uiVoxel != LODWORD(tMax[0]) )
    {
      if ( CVoxelHash::EnumerateElementsInVoxel<CIntersectRay>(
             this: (CVoxelHash *)&pIterator[3].__vftable[3138],
             a2: (int)&v2,
             voxel: ov3,
             intersectTest: (const CIntersectRay *)v26,
             listMask,
             pIterator) == 0 )
        return 0;
      v23 = *(float *)&nStep[2];
      v24.bitsVoxel = ov3.bitsVoxel;
    }
    if ( *(float *)nStep >= 1.0 && *(float *)&nStep[1] >= 1.0 && v23 >= 1.0 )
      return 1;
    if ( *(float *)&nStep[1] <= *(float *)nStep )
    {
      if ( v23 <= *(float *)&nStep[1] )
      {
LABEL_24:
        *(float *)&nStep[2] = intersectRay.m_f4InvDelta.m128_f32[3] + v23;
        v13 += LODWORD(tDelta[2]) << 22;
        goto LABEL_25;
      }
      *(float *)&nStep[1] = intersectRay.m_f4InvDelta.m128_f32[2] + *(float *)&nStep[1];
      v13 ^= (v13 ^ (v13 + (LODWORD(tDelta[1]) << 11))) & 0x3FF800;
    }
    else
    {
      if ( v23 <= *(float *)nStep )
        goto LABEL_24;
      *(float *)nStep = intersectRay.m_f4InvDelta.m128_f32[1] + *(float *)nStep;
      v13 ^= ((unsigned __int16)v13 ^ (unsigned __int16)(v13 + LOWORD(tDelta[0]))) & 0x7FF;
    }
LABEL_25:
    v25.bitsVoxel = ov2.bitsVoxel;
    LODWORD(tMax[2]) = v22;
    tMax[0] = *(float *)&v24.uiVoxel;
    v22 = (v13 >> 2) & 0x3FCFF9FF;
    ov2.uiVoxel = (v22 >> 2) & 0xFCFF9FF;
    tMax[1] = *(float *)&v25.uiVoxel;
    if ( CVoxelHash::EnumerateElementsInVoxel<CIntersectRay>(
           this: (CVoxelHash *)pIterator[3].__vftable,
           a2: (int)&v2,
           voxel: (Voxel_t)v13,
           intersectTest: (const CIntersectRay *)v26,
           listMask,
           pIterator) == 0 )
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DB640
// Name: public: bool CVoxelTree::EnumerateRayStartVoxels(int,class IPartitionEnumerator __near *,class CIntersectSweptBox __near &,int (__near * const)[2][3])
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVoxelTree::EnumerateRayStartVoxels(
        CVoxelTree *this,
        unsigned __int16 listMask,
        IPartitionEnumerator *pIterator,
        CIntersectSweptBox *intersectSweptBox,
        int (*voxelBounds)[2][3])
{
  int v6; // edx
  int v7; // ebx
  int *v8; // esi
  int v9; // ebx
  int v10; // eax
  int v11; // edi
  int *v12; // ecx
  int v13; // esi
  int v14; // eax
  int *v17; // [esp+10h] [ebp-24h]
  int i; // [esp+14h] [ebp-20h]
  int iY; // [esp+18h] [ebp-1Ch]
  int nMinZ; // [esp+1Ch] [ebp-18h]
  int v21; // [esp+20h] [ebp-14h]
  int nMinX; // [esp+24h] [ebp-10h]
  int iX; // [esp+28h] [ebp-Ch]
  int nMaxX; // [esp+2Ch] [ebp-8h]
  int nMaxY; // [esp+30h] [ebp-4h]
  int voxel; // [esp+48h] [ebp+14h]

  v6 = (*voxelBounds)[0][0];
  nMaxX = (*voxelBounds)[1][0];
  v7 = (*voxelBounds)[1][1];
  voxel = (*voxelBounds)[0][1];
  v8 = &(*voxelBounds)[0][2];
  nMaxY = v7;
  v9 = (*voxelBounds)[1][2];
  v10 = 0;
  v11 = *v8;
  nMinX = v6;
  nMinZ = *v8;
  i = 0;
  if ( this->m_nLevelCount <= 0 )
    return 1;
  v12 = v8;
  v13 = voxel;
  v21 = 0;
  v17 = v12;
  while ( 1 )
  {
    if ( v10 != 0 )
    {
      voxel >>= 2;
      nMaxX >>= 2;
      nMaxY >>= 2;
      *(v12 - 1) = voxel;
      v6 >>= 2;
      v11 >>= 2;
      v12[1] = nMaxX;
      v9 >>= 2;
      nMinX = v6;
      nMinZ = v11;
      *(v12 - 2) = v6;
      *v12 = v11;
      v12[2] = nMaxY;
      v12[3] = v9;
    }
    iX = v6;
    if ( nMinX <= nMaxX )
      break;
LABEL_14:
    ++v21;
    v10 = i + 1;
    v12 += 6;
    i = v10;
    v17 = v12;
    if ( v10 >= this->m_nLevelCount )
      return 1;
    v6 = nMinX;
  }
  while ( 1 )
  {
    v13 ^= ((unsigned __int16)iX ^ (unsigned __int16)v13) & 0x7FF;
    v14 = voxel;
    iY = voxel;
    if ( voxel <= nMaxY )
      break;
LABEL_13:
    if ( ++iX > nMaxX )
      goto LABEL_14;
  }
  while ( 1 )
  {
    v13 ^= (v13 ^ (v14 << 11)) & 0x3FF800;
    if ( v11 <= v9 )
      break;
LABEL_12:
    iY = ++v14;
    if ( v14 > nMaxY )
      goto LABEL_13;
  }
  while ( 1 )
  {
    v13 = (v11 << 22) | v13 & 0x3FFFFF;
    if ( CVoxelHash::EnumerateElementsInVoxel<CIntersectSweptBox>(
           this: &this->m_pVoxelHash[v21],
           voxel: (Voxel_t)v13,
           intersectTest: intersectSweptBox,
           listMask,
           pIterator) == 0 )
      return 0;
    if ( ++v11 > v9 )
    {
      v12 = v17;
      v14 = iY;
      v11 = nMinZ;
      goto LABEL_12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DB790
// Name: public: bool CVoxelTree::EnumerateElementsAlongRay_ExtrudedRay(int,struct Ray_t const __near &,class Vector const __near &,class Vector const __near &,class IPartitionEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
char __userpurge CVoxelTree::EnumerateElementsAlongRay_ExtrudedRay@<al>(
        CVoxelTree *this@<ecx>,
        int a2@<ebp>,
        unsigned __int16 listMask,
        const Ray_t *ray,
        const Vector *vecInvDelta,
        const Vector *vecEnd,
        IPartitionEnumerator *pIterator)
{
  float y; // xmm4_4
  float z; // xmm5_4
  CVoxelHash *m_pVoxelHash; // eax
  unsigned int m_nLevelShift; // ecx
  float v12; // xmm3_4
  int v13; // xmm1_4
  float v14; // xmm4_4
  int v15; // xmm2_4
  float v16; // xmm5_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm5_4
  void *v21; // eax
  int m_TreeId; // edx
  VectorAligned m_Start; // xmm0
  VectorAligned m_Delta; // xmm0
  __m128 v25; // xmm0
  float v26; // xmm4_4
  float v27; // xmm5_4
  CVoxelHash *v28; // eax
  unsigned int v29; // ecx
  float v30; // xmm3_4
  float v31; // xmm1_4
  float v32; // xmm4_4
  float v33; // xmm2_4
  float v34; // xmm5_4
  int v36; // eax
  int v37; // ecx
  int v38; // edx
  int v39; // eax
  int v40; // ecx
  int v41; // edx
  int v42; // eax
  int v43; // ecx
  int v44; // edx
  float v45; // eax
  float v46; // xmm2_4
  float v47; // xmm3_4
  float v48; // xmm4_4
  int v49; // esi
  int v50; // eax
  float v51; // xmm0_4
  float v52; // xmm1_4
  int v53; // esi
  int v54; // eax
  int v55; // ecx
  int v56; // ecx
  int v57; // eax
  int v58; // edi
  int v59; // ecx
  int v60; // edx
  int v61; // edi
  CVoxelHash *v62; // ecx
  _DWORD v63[3]; // [esp-Ch] [ebp-11Ch] BYREF
  CIntersectSweptBox intersectSweptBox; // [esp+0h] [ebp-110h]
  int nLastVoxel1[3]; // [esp+50h] [ebp-C0h] BYREF
  _BYTE tDelta[108]; // [esp+5Ch] [ebp-B4h] OVERLAPPED BYREF
  float v67; // [esp+C8h] [ebp-48h]
  int nLastVoxel3[3]; // [esp+CCh] [ebp-44h] BYREF
  int nLastVoxel2[3]; // [esp+D8h] [ebp-38h] BYREF
  int nStep[3]; // [esp+E4h] [ebp-2Ch] BYREF
  float tMax[3]; // [esp+F0h] [ebp-20h] BYREF
  int endVoxelMin[3]; // [esp+FCh] [ebp-14h] BYREF
  void *v73; // [esp+108h] [ebp-8h]
  void *retaddr; // [esp+110h] [ebp+0h]

  endVoxelMin[2] = a2;
  v73 = retaddr;
  endVoxelMin[0] = (int)this;
  y = ray->m_Start.y;
  z = ray->m_Start.z;
  m_pVoxelHash = this->m_pVoxelHash;
  m_nLevelShift = m_pVoxelHash->m_nLevelShift;
  v12 = ray->m_Start.x + ray->m_Extents.x;
  *(float *)nLastVoxel3 = ray->m_Start.x - ray->m_Extents.x;
  *(float *)&v13 = y - ray->m_Extents.y;
  v14 = y + ray->m_Extents.y;
  *(_DWORD *)tDelta = (int)(float)(*(float *)nLastVoxel3 - m_pVoxelHash->m_vecVoxelOrigin.x) >> m_nLevelShift;
  nLastVoxel3[1] = v13;
  *(float *)&v15 = z - ray->m_Extents.z;
  v16 = z + ray->m_Extents.z;
  *(_DWORD *)&tDelta[4] = (int)(float)(*(float *)&v13 - m_pVoxelHash->m_vecVoxelOrigin.y) >> m_nLevelShift;
  nLastVoxel3[2] = v15;
  v17 = *(float *)&v15 - m_pVoxelHash->m_vecVoxelOrigin.z;
  *(float *)&tDelta[100] = v12;
  v18 = v12 - m_pVoxelHash->m_vecVoxelOrigin.x;
  *(float *)&tDelta[104] = v14;
  v19 = v14 - m_pVoxelHash->m_vecVoxelOrigin.y;
  *(_DWORD *)&tDelta[8] = (int)v17 >> m_nLevelShift;
  v67 = v16;
  v20 = v16 - m_pVoxelHash->m_vecVoxelOrigin.z;
  *(_DWORD *)&tDelta[12] = (int)v18 >> m_nLevelShift;
  *(_DWORD *)&tDelta[16] = (int)v19 >> m_nLevelShift;
  *(_DWORD *)&tDelta[20] = (int)v20 >> m_nLevelShift;
  v21 = GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index);
  m_TreeId = this->m_TreeId;
  m_Start = ray->m_Start;
  v63[0] = this->m_pVisits[(_DWORD)v21];
  *(VectorAligned *)&intersectSweptBox.m_iTree = m_Start;
  m_Delta = ray->m_Delta;
  endVoxelMin[0] = (int)tDelta;
  v63[1] = m_TreeId;
  *(VectorAligned *)((char *)&intersectSweptBox.m_f4Start + 4) = m_Delta;
  v25 = *(__m128 *)&vecInvDelta->x;
  LODWORD(tMax[2]) = v63;
  LODWORD(tMax[1]) = pIterator;
  *(__m128 *)((char *)&intersectSweptBox.m_f4Delta + 4) = v25;
  *(__m128 *)((char *)&intersectSweptBox.m_f4InvDelta + 4) = (__m128)ray->m_Extents;
  if ( CVoxelTree::EnumerateRayStartVoxels(
         this,
         listMask,
         pIterator,
         intersectSweptBox: (CIntersectSweptBox *)v63,
         voxelBounds: (int (*)[2][3])tDelta) != 0 )
  {
    v26 = vecEnd->y;
    v27 = vecEnd->z;
    v28 = this->m_pVoxelHash;
    v29 = v28->m_nLevelShift;
    v30 = (float)(vecEnd->x + ray->m_Extents.x) - v28->m_vecVoxelOrigin.x;
    v31 = (float)(v26 - ray->m_Extents.y) - v28->m_vecVoxelOrigin.y;
    v32 = (float)(v26 + ray->m_Extents.y) - v28->m_vecVoxelOrigin.y;
    LODWORD(tMax[0]) = (int)(float)((float)(vecEnd->x - ray->m_Extents.x) - v28->m_vecVoxelOrigin.x) >> v29;
    v33 = (float)(v27 - ray->m_Extents.z) - v28->m_vecVoxelOrigin.z;
    v34 = (float)(v27 + ray->m_Extents.z) - v28->m_vecVoxelOrigin.z;
    LODWORD(tMax[1]) = (int)v31 >> v29;
    LODWORD(tMax[2]) = (int)v33 >> v29;
    nLastVoxel1[0] = (int)v30 >> v29;
    if ( SLODWORD(tMax[0]) >= *(int *)tDelta
      && SLODWORD(tMax[1]) >= *(int *)&tDelta[4]
      && SLODWORD(tMax[2]) >= *(int *)&tDelta[8]
      && nLastVoxel1[0] <= *(int *)&tDelta[12]
      && (int)v32 >> v29 <= *(int *)&tDelta[16]
      && (int)v34 >> v29 <= *(int *)&tDelta[20] )
    {
      return 1;
    }
    CVoxelHash::LeafListExtrudedRaySetup(
      this: this->m_pVoxelHash,
      ray,
      vecInvDelta,
      vecMin: (const Vector *)nLastVoxel3,
      vecMax: (const Vector *)&tDelta[100],
      iVoxelMin: (int *)tDelta,
      iVoxelMax: (int *)&tDelta[12],
      pStep: nLastVoxel2,
      pMin: tMax,
      pMax: (float *)nStep,
      pDelta: (float *)nLastVoxel1);
    v36 = 12 * (nLastVoxel2[0] > 0);
    v37 = *(_DWORD *)&tDelta[v36 + 48];
    intersectSweptBox.m_f4Extents.m128_i32[1] = *(_DWORD *)&tDelta[v36 + 24];
    v38 = *(_DWORD *)&tDelta[v36 + 72];
    nLastVoxel3[0] = v37;
    *(_DWORD *)&tDelta[100] = v38;
    v39 = 12 * (nLastVoxel2[1] > 0);
    v40 = *(_DWORD *)&tDelta[v39 + 28];
    v41 = *(_DWORD *)&tDelta[v39 + 52];
    *(_DWORD *)&tDelta[104] = *(_DWORD *)&tDelta[v39 + 76];
    intersectSweptBox.m_f4Extents.m128_i32[2] = v40;
    nLastVoxel3[1] = v41;
    v42 = 12 * (nLastVoxel2[2] > 0);
    v43 = *(_DWORD *)&tDelta[v42 + 32];
    v44 = *(_DWORD *)&tDelta[v42 + 56];
    v45 = *(float *)&tDelta[v42 + 80];
    intersectSweptBox.m_f4Extents.m128_i32[3] = v43;
    nLastVoxel3[2] = v44;
    v67 = v45;
LABEL_10:
    v46 = *(float *)&nStep[2];
    v47 = *(float *)&nStep[1];
    v48 = *(float *)nStep;
    while ( 1 )
    {
      if ( v48 >= 1.0 && v47 >= 1.0 && v46 >= 1.0 )
        return 1;
      if ( v47 <= v48 )
      {
        v49 = 1;
        if ( v46 > v47 )
          goto LABEL_19;
      }
      else if ( v46 > v48 )
      {
        v49 = 0;
        goto LABEL_19;
      }
      v49 = 2;
LABEL_19:
      if ( tMax[1] <= tMax[0] )
      {
        v50 = 1;
        if ( tMax[2] > tMax[1] )
          goto LABEL_24;
      }
      else if ( tMax[2] > tMax[0] )
      {
        v50 = 0;
        goto LABEL_24;
      }
      v50 = 2;
LABEL_24:
      v51 = tMax[v50];
      v52 = *(float *)&nStep[v49];
      if ( v52 <= v51 )
      {
        v56 = nLastVoxel2[v49];
        *(float *)&nStep[v49] = *(float *)&nLastVoxel1[v49] + v52;
        v57 = 4 * ((v56 > 0) + v49 + 2 * (v56 > 0));
        *(_DWORD *)&tDelta[v57] += v56;
        v58 = *(_DWORD *)&tDelta[v57];
        v59 = v58 >> 6;
        v60 = v58 >> 4;
        *(_DWORD *)&tDelta[v57 + 72] = v58 >> 6;
        *(_DWORD *)&tDelta[v57 + 48] = v58 >> 4;
        v61 = v58 >> 2;
        *(_DWORD *)&tDelta[v57 + 24] = v61;
        *(_DWORD *)&tDelta[96] = v59;
        endVoxelMin[1] = v60;
        if ( CVoxelHash::EnumerateElementsAlongRay_ExtrudedRaySlice(
               this: (CVoxelHash *)nStep[0],
               a2: (int)&endVoxelMin[2],
               listMask,
               pIterator,
               intersectSweptBox: (const CIntersectSweptBox *)v63,
               voxelMin: (int *)tDelta,
               voxelMax: (int *)&tDelta[12],
               iAxis: v49,
               pStep: nLastVoxel2) != 0 )
        {
          if ( intersectSweptBox.m_f4Extents.m128_i32[v49 + 1] == v61 )
            goto LABEL_36;
          endVoxelMin[0] = (int)nLastVoxel2;
          LODWORD(tMax[2]) = v49;
          LODWORD(tMax[1]) = &tDelta[36];
          LODWORD(tMax[0]) = &tDelta[24];
          nStep[2] = (int)v63;
          v62 = (CVoxelHash *)nStep[0];
          nStep[1] = (int)pIterator;
          LOWORD(nStep[0]) = listMask;
          intersectSweptBox.m_f4Extents.m128_i32[v49 + 1] = v61;
          if ( CVoxelHash::EnumerateElementsAlongRay_ExtrudedRaySlice(
                 this: v62 + 1,
                 a2: (int)&endVoxelMin[2],
                 listMask: nStep[0],
                 pIterator: (IPartitionEnumerator *)nStep[1],
                 intersectSweptBox: (const CIntersectSweptBox *)nStep[2],
                 voxelMin: (int *)LODWORD(tMax[0]),
                 voxelMax: (int *)LODWORD(tMax[1]),
                 iAxis: SLODWORD(tMax[2]),
                 pStep: (int *)endVoxelMin[0]) != 0 )
          {
LABEL_36:
            if ( nLastVoxel3[v49] == endVoxelMin[1]
              || (endVoxelMin[0] = (int)nLastVoxel2,
                  LODWORD(tMax[2]) = v49,
                  nLastVoxel3[v49] = endVoxelMin[1],
                  CVoxelHash::EnumerateElementsAlongRay_ExtrudedRaySlice(
                    this: (CVoxelHash *)(*(_DWORD *)(endVoxelMin[0] + 12) + 8368),
                    a2: (int)&endVoxelMin[2],
                    listMask,
                    pIterator,
                    intersectSweptBox: (const CIntersectSweptBox *)v63,
                    voxelMin: (int *)&tDelta[48],
                    voxelMax: (int *)&tDelta[60],
                    iAxis: SLODWORD(tMax[2]),
                    pStep: (int *)endVoxelMin[0]) != 0) )
            {
              if ( *(_DWORD *)&tDelta[4 * v49 + 100] == *(_DWORD *)&tDelta[96] )
                goto LABEL_10;
              *(_DWORD *)&tDelta[4 * v49 + 100] = *(_DWORD *)&tDelta[96];
              if ( CVoxelHash::EnumerateElementsAlongRay_ExtrudedRaySlice(
                     this: (CVoxelHash *)(nStep[0] + 12552),
                     a2: (int)&endVoxelMin[2],
                     listMask,
                     pIterator,
                     intersectSweptBox: (const CIntersectSweptBox *)v63,
                     voxelMin: (int *)&tDelta[72],
                     voxelMax: (int *)&tDelta[84],
                     iAxis: v49,
                     pStep: nLastVoxel2) != 0 )
                goto LABEL_10;
            }
          }
        }
        return 0;
      }
      v53 = nLastVoxel2[v50];
      tMax[v50] = *(float *)&nLastVoxel1[v50] + v51;
      v54 = 4 * ((v53 <= 0) + v50 + 2 * (v53 <= 0));
      *(_DWORD *)&tDelta[v54] += v53;
      v55 = *(_DWORD *)&tDelta[v54];
      *(_DWORD *)&tDelta[v54 + 24] = v55 >> 2;
      *(_DWORD *)&tDelta[v54 + 48] = v55 >> 4;
      *(_DWORD *)&tDelta[v54 + 72] = v55 >> 6;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DBCD0
// Name: public: int CUtlHashFixed<int,512,class CUtlHashFixedGenericHash<512>>::FastInsert(unsigned int,int const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *__thiscall CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::FastInsert(
        CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *this,
        unsigned int uiKey,
        int *data)
{
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> > *v5; // esi
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *result; // eax
  unsigned int uiKeya; // [esp+14h] [ebp+8h]

  v5 = &this->m_aBuckets[((unsigned __int16)(HIBYTE(uiKey)
                                           + 33
                                           * (BYTE2(uiKey) + 33 * (BYTE1(uiKey) + 33 * ((unsigned __int8)uiKey - 21846))))
                        ^ ((HIBYTE(uiKey)
                          + 33
                          * (BYTE2(uiKey)
                           + 33 * (BYTE1(uiKey) + 33 * ((unsigned int)(unsigned __int8)uiKey - 1431655766)))) >> 16))
                       & 0x1FF];
  uiKeya = (unsigned int)v5->m_pFirst;
  result = (CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *)MemAlloc_Alloc(nSize: 0x10u);
  if ( uiKeya != 0 )
  {
    result->pNext = (CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *)uiKeya;
    result->pPrev = *(CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t **)(uiKeya + 8);
    *(_DWORD *)(uiKeya + 8) = result;
    result->pPrev->pNext = result;
  }
  else
  {
    result->pPrev = result;
    result->pNext = result;
    v5->m_pFirst = result;
  }
  v5->m_pFirst = result;
  ++v5->m_nElems;
  result->elem.m_uiKey = uiKey;
  result->elem.m_Data = *data;
  ++this->m_nElements;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DBF50
// Name: public: class CVarBitVec __near * CVoxelTree::BeginVisit(void)
// Source: json
//------------------------------------------------------------------------------
CVarBitVec *__thiscall CVoxelTree::BeginVisit(CVoxelTree *this)
{
  TSLNodeBase_t *v2; // eax
  TSLNodeBase_t *v3; // esi
  CVarBitVec *v4; // esi
  int m_nNextVisitBit; // eax
  unsigned __int8 *m_pInt; // eax
  CVarBitVec *pPrev; // [esp+Ch] [ebp-4h]

  pPrev = this->m_pVisits[(_DWORD)GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index)];
  v2 = CTSListBase::Pop(this: &this->m_FreeVisits);
  if ( v2 == nullptr )
  {
    v3 = (TSLNodeBase_t *)MemAlloc_Alloc(nSize: 0x10u);
    v2 = nullptr;
    if ( v3 != nullptr )
    {
      *((_DWORD *)&v3->Next + 1) = 0;
      v3[1].Next = nullptr;
      *((_DWORD *)&v3[1].Next + 1) = 0;
      v2 = v3;
    }
  }
  v4 = (CVarBitVec *)(&v2->Next + 1);
  m_nNextVisitBit = this->m_nNextVisitBit;
  if ( v4->m_numBits >= (unsigned __int16)m_nNextVisitBit )
  {
    m_pInt = (unsigned __int8 *)v4->m_pInt;
    if ( m_pInt != nullptr )
      memset(dst: m_pInt, value: 0, count: 4 * v4->m_numInts);
  }
  else
  {
    CVarBitVecBase<unsigned short>::Resize(this: v4, resizeNumBits: m_nNextVisitBit, bClearAll: true);
  }
  this->m_pVisits[(_DWORD)GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index)] = v4;
  return pPrev;
}

//------------------------------------------------------------------------------
// Address: 0x101DC000
// Name: public: void CVoxelHash::Init(class CVoxelTree __near *,class Vector const __near &,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelHash::Init(
        CVoxelHash *this,
        CVoxelTree *pPartition,
        const Vector *worldmin,
        const Vector *worldmax,
        int nLevel)
{
  int v5; // edx
  int v6; // esi
  CUtlFixedLinkedList<CSpatialEntry> *p_m_aEntityList; // edi

  this->m_pTree = pPartition;
  this->m_nLevel = nLevel;
  this->m_nLevelShift = 2 * nLevel + 8;
  v5 = 128 >> (2 * nLevel);
  this->m_flVoxelSize = (float)(256 << (2 * nLevel));
  if ( v5 == 0 )
    v5 = 1;
  v6 = 256 >> nLevel;
  this->m_vecVoxelOrigin.x = -16384.0;
  this->m_vecVoxelOrigin.y = -16384.0;
  this->m_vecVoxelOrigin.z = -16384.0;
  this->m_nVoxelDelta[0] = v5;
  this->m_nVoxelDelta[1] = v5;
  this->m_nVoxelDelta[2] = v5;
  if ( (unsigned int)(256 >> nLevel) < 0x10 )
    v6 = 16;
  p_m_aEntityList = &this->m_aEntityList;
  CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::Purge(this: (CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *)&this->m_aEntityList);
  CUtlLinkedList<unsigned short,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int>>>::SetGrowSize(
    this: (CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *)p_m_aEntityList,
    growSize: v6);
}

//------------------------------------------------------------------------------
// Address: 0x101DC0B0
// Name: public: void CVoxelHash::InsertIntoTree(unsigned short,union Voxel_t,union Voxel_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelHash::InsertIntoTree(
        CVoxelHash *this,
        unsigned __int16 hPartition,
        Voxel_t voxelMin,
        Voxel_t voxelMax)
{
  CVoxelHash *v4; // ebx
  CVoxelTree *m_pTree; // eax
  CUtlFixedLinkedList<LeafListData_t> *p_m_aLeafList; // edx
  int v7; // ecx
  int m_TreeId; // esi
  int v9; // eax
  Voxel_t v10; // edx
  unsigned int v11; // esi
  unsigned int v12; // ecx
  unsigned int v13; // eax
  unsigned int uiVoxel; // edi
  _WORD *v15; // esi
  __int16 v16; // ax
  int v17; // eax
  int v18; // ebx
  int *v19; // edi
  int v20; // eax
  unsigned int v21; // eax
  int v22; // [esp+8h] [ebp-30h]
  int v23; // [esp+Ch] [ebp-2Ch]
  CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *p_m_aEntityList; // [esp+10h] [ebp-28h]
  CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *p_m_aVoxelHash; // [esp+14h] [ebp-24h]
  int iEntity; // [esp+18h] [ebp-20h] BYREF
  int nListMask; // [esp+1Ch] [ebp-1Ch]
  unsigned int iX; // [esp+20h] [ebp-18h]
  unsigned int iY; // [esp+24h] [ebp-14h]
  CVoxelHash *v30; // [esp+28h] [ebp-10h]
  CUtlFixedLinkedList<LeafListData_t> *leafList; // [esp+2Ch] [ebp-Ch]
  unsigned int iZ; // [esp+30h] [ebp-8h]
  Voxel_t voxel; // [esp+34h] [ebp-4h]

  v4 = this;
  m_pTree = this->m_pTree;
  p_m_aLeafList = &m_pTree->m_aLeafList;
  v7 = (int)&m_pTree->m_pOwner->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * hPartition];
  m_TreeId = m_pTree->m_TreeId;
  v9 = *(unsigned __int16 *)(v7 + 36);
  leafList = p_m_aLeafList;
  *(_BYTE *)(m_TreeId + v7 + 39) = v4->m_nLevel;
  v10.bitsVoxel = voxelMax.bitsVoxel;
  v22 = m_TreeId;
  nListMask = v9;
  v11 = *(_WORD *)&voxelMin.bitsVoxel & 0x7FF;
  v30 = v4;
  v23 = v7;
  iX = v11;
  if ( v11 <= (*(_WORD *)&voxelMax.bitsVoxel & 0x7FFu) )
  {
    do
    {
      voxel.uiVoxel ^= ((unsigned __int16)v11 ^ *(_WORD *)&voxel.bitsVoxel) & 0x7FF;
      v12 = (voxelMin.uiVoxel >> 11) & 0x7FF;
      for ( iY = v12; v12 <= ((v10.uiVoxel >> 11) & 0x7FF); iY = v12 )
      {
        voxel.uiVoxel ^= (voxel.uiVoxel ^ (v12 << 11)) & 0x3FF800;
        v13 = voxelMin.uiVoxel >> 22;
        iZ = voxelMin.uiVoxel >> 22;
        if ( voxelMin.uiVoxel >> 22 <= v10.uiVoxel >> 22 )
        {
          while ( 1 )
          {
            voxel.uiVoxel = (v13 << 22) | voxel.uiVoxel & 0x3FFFFF;
            uiVoxel = voxel.uiVoxel;
            p_m_aEntityList = (CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *)&v4->m_aEntityList;
            v15 = (_WORD *)CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::AllocInternal(
                             this: &v4->m_aEntityList,
                             multilist: true);
            v16 = nListMask;
            *v15 = hPartition;
            iEntity = (int)v15;
            v15[1] = v16;
            p_m_aVoxelHash = &v4->m_aVoxelHash;
            v17 = CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::Find(this: &v4->m_aVoxelHash, uiKey: uiVoxel);
            v18 = v17;
            if ( v17 == -1 )
            {
              v18 = CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::FastInsert(
                      this: p_m_aVoxelHash,
                      uiKey: uiVoxel,
                      data: &iEntity);
            }
            else
            {
              CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::LinkBefore(
                this: p_m_aEntityList,
                before: *(_DWORD *)(v17 + 4),
                elem: (int)v15);
              *(_DWORD *)(v18 + 4) = v15;
            }
            v19 = (int *)CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>>::AllocInternal(
                           this: leafList,
                           multilist: true);
            *v19 = v18;
            v19[1] = (int)v15;
            v20 = *(_DWORD *)(v23 + 4 * v22 + 48);
            if ( v20 != 0 )
              CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>>::LinkBefore(
                this: leafList,
                before: v20,
                elem: (int)v19);
            v21 = iZ;
            *(_DWORD *)(v23 + 4 * v22 + 48) = v19;
            v10.bitsVoxel = voxelMax.bitsVoxel;
            v4 = v30;
            iZ = v21 + 1;
            if ( v21 + 1 > voxelMax.uiVoxel >> 22 )
              break;
            v13 = iZ;
          }
          v12 = iY;
          v11 = iX;
        }
        ++v12;
      }
      iX = ++v11;
    }
    while ( v11 <= (*(_WORD *)&v10.bitsVoxel & 0x7FFu) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DC270
// Name: public: void CVoxelHash::RenderAllObjectsInTree(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelHash::RenderAllObjectsInTree(CVoxelHash *this, float flTime)
{
  CVarBitVec *v3; // eax
  CVoxelTree *m_pTree; // esi
  CVarBitVec *v5; // eax
  CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *p_m_aVoxelHash; // ecx
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *m_pFirst; // edi
  int m_Data; // esi
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *pNext; // eax
  bool v10; // zf
  CVoxelTree *v11; // ebx
  void *v12; // eax
  CTSPool<CVarBitVec> *p_m_FreeVisits; // esi
  unsigned int **p_m_pInt; // edi
  TSLNodeBase_t *Next; // [esp-4h] [ebp-28h]
  TSLNodeBase_t *v16; // [esp-4h] [ebp-28h]
  int DepthAndSequence; // [esp+0h] [ebp-24h]
  int v18; // [esp+0h] [ebp-24h]
  CPartitionVisitor pVisitor; // [esp+10h] [ebp-14h] BYREF
  CVarBitVec *v20; // [esp+18h] [ebp-Ch]
  CVarBitVec *pPrevVisits; // [esp+1Ch] [ebp-8h]
  CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *v22; // [esp+20h] [ebp-4h]
  void *v23; // [esp+2Ch] [ebp+8h]

  v3 = CVoxelTree::BeginVisit(this: this->m_pTree);
  m_pTree = this->m_pTree;
  v20 = v3;
  v5 = m_pTree->m_pVisits[(_DWORD)GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index)];
  pVisitor.m_iTree = m_pTree->m_TreeId;
  p_m_aVoxelHash = &this->m_aVoxelHash;
  pVisitor.m_pVisits = v5;
  v22 = &this->m_aVoxelHash;
  pPrevVisits = (CVarBitVec *)512;
  do
  {
    if ( p_m_aVoxelHash->m_aBuckets[0].m_nElems != 0 )
    {
      m_pFirst = p_m_aVoxelHash->m_aBuckets[0].m_pFirst;
      if ( p_m_aVoxelHash->m_aBuckets[0].m_pFirst != nullptr )
      {
        do
        {
          m_Data = m_pFirst->elem.m_Data;
          if ( m_Data != 0 )
          {
            do
            {
              CVoxelHash::RenderObjectInVoxel(this, hPartition: *(_WORD *)m_Data, &pVisitor, flTime);
              m_Data = *(_DWORD *)(m_Data + 8);
            }
            while ( m_Data != 0 );
            p_m_aVoxelHash = v22;
          }
          pNext = m_pFirst->pNext;
          if ( pNext == p_m_aVoxelHash->m_aBuckets[0].m_pFirst )
            break;
          m_pFirst = m_pFirst->pNext;
        }
        while ( pNext != nullptr );
      }
    }
    p_m_aVoxelHash = (CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *)((char *)p_m_aVoxelHash + 8);
    v10 = pPrevVisits == (CVarBitVec *)1;
    pPrevVisits = (CVarBitVec *)((char *)pPrevVisits - 1);
    v22 = p_m_aVoxelHash;
  }
  while ( !v10 );
  v11 = this->m_pTree;
  v12 = GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index);
  p_m_FreeVisits = &v11->m_FreeVisits;
  DepthAndSequence = v11->m_FreeVisits.m_Head.value32.DepthAndSequence;
  v23 = v12;
  Next = v11->m_FreeVisits.m_Head.value.Next;
  p_m_pInt = &v11->m_pVisits[(_DWORD)v12][-1].m_pInt;
  *p_m_pInt = (unsigned int *)Next;
  if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                          a1: &v11->m_FreeVisits,
                          a2: p_m_pInt,
                          a3: DepthAndSequence + 65537,
                          a4: Next,
                          a5: DepthAndSequence) != 0 )
  {
    v11->m_pVisits[(_DWORD)v23] = v20;
  }
  else
  {
    do
    {
      _mm_pause();
      v18 = v11->m_FreeVisits.m_Head.value32.DepthAndSequence;
      v16 = p_m_FreeVisits->m_Head.value.Next;
      *p_m_pInt = (unsigned int *)p_m_FreeVisits->m_Head.value.Next;
    }
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: &v11->m_FreeVisits,
                               a2: p_m_pInt,
                               a3: v18 + 65537,
                               a4: v16,
                               a5: v18) == 0 );
    v11->m_pVisits[(_DWORD)v23] = v20;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DC390
// Name: public: void CVoxelHash::RenderObjectsInPlayerLeafs(class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelHash::RenderObjectsInPlayerLeafs(
        CVoxelHash *this,
        const Vector *vecPlayerMin,
        const Vector *vecPlayerMax,
        float flTime)
{
  float v5; // xmm3_4
  unsigned int m_nLevelShift; // ecx
  unsigned int v7; // ebx
  int v8; // edx
  int v9; // esi
  int v10; // eax
  CVoxelTree *m_pTree; // ecx
  CVarBitVec *v12; // eax
  CVoxelTree *v13; // esi
  CVarBitVec *v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // edx
  float v17; // esi
  unsigned int v18; // ecx
  unsigned int v19; // ebx
  CVarBitVec *m_pVisits; // eax
  int m_iTree; // ecx
  Voxel_t v22; // edx
  int v23; // eax
  int i; // esi
  CVoxelTree *v25; // edi
  unsigned int v26; // eax
  CTSPool<CVarBitVec> *p_m_FreeVisits; // esi
  unsigned int **p_m_pInt; // ebx
  TSLNodeBase_t *Next; // [esp-4h] [ebp-38h]
  TSLNodeBase_t *v30; // [esp-4h] [ebp-38h]
  int DepthAndSequence; // [esp+0h] [ebp-34h]
  int v32; // [esp+0h] [ebp-34h]
  CPartitionVisitor pVisitor; // [esp+4h] [ebp-30h] BYREF
  unsigned int v34; // [esp+Ch] [ebp-28h]
  float v35; // [esp+10h] [ebp-24h]
  CPartitionVisitor visitor; // [esp+14h] [ebp-20h]
  Voxel_t voxelMin; // [esp+1Ch] [ebp-18h]
  unsigned int v38; // [esp+20h] [ebp-14h]
  unsigned int v39; // [esp+24h] [ebp-10h]
  CVarBitVec *v40; // [esp+28h] [ebp-Ch]
  unsigned int v41; // [esp+2Ch] [ebp-8h]
  unsigned int v42; // [esp+30h] [ebp-4h]
  unsigned int iX; // [esp+3Ch] [ebp+8h]
  unsigned int iXa; // [esp+3Ch] [ebp+8h]
  unsigned int voxelMax; // [esp+40h] [ebp+Ch]

  v5 = vecPlayerMin->y - this->m_vecVoxelOrigin.y;
  m_nLevelShift = this->m_nLevelShift;
  v7 = ((int)(float)(vecPlayerMin->x - this->m_vecVoxelOrigin.x) >> m_nLevelShift) & 0x7FF
     | ((((int)(float)(vecPlayerMin->z - this->m_vecVoxelOrigin.z) >> m_nLevelShift << 11)
       | ((int)v5 >> m_nLevelShift) & 0x7FF) << 11);
  v8 = (int)(float)(vecPlayerMax->y - this->m_vecVoxelOrigin.y) >> m_nLevelShift;
  v9 = (int)(float)(vecPlayerMax->z - this->m_vecVoxelOrigin.z) >> m_nLevelShift;
  v10 = (int)(float)(vecPlayerMax->x - this->m_vecVoxelOrigin.x) >> m_nLevelShift;
  m_pTree = this->m_pTree;
  v34 = v7;
  v42 = v10 & 0x7FF | (((v9 << 11) | v8 & 0x7FF) << 11);
  v12 = CVoxelTree::BeginVisit(this: m_pTree);
  v13 = this->m_pTree;
  v40 = v12;
  v14 = v13->m_pVisits[(_DWORD)GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index)];
  v15 = v42;
  pVisitor.m_iTree = v13->m_TreeId;
  v16 = v7 & 0x7FF;
  LODWORD(v17) = v42 & 0x7FF;
  pVisitor.m_pVisits = v14;
  v41 = v16;
  v35 = v17;
  if ( v16 <= LODWORD(v17) )
  {
    v39 = (v7 >> 11) & 0x7FF;
    voxelMax = (v42 >> 11) & 0x7FF;
    do
    {
      iX = v39;
      if ( v39 <= voxelMax )
      {
        v18 = v39;
        v19 = v7 >> 22;
        m_pVisits = (CVarBitVec *)(v15 >> 22);
        v38 = v19;
        visitor.m_pVisits = m_pVisits;
        while ( 1 )
        {
          if ( v19 <= (unsigned int)m_pVisits )
          {
            m_iTree = v18 & 0x7FF;
            v22.uiVoxel = v16 & 0x7FF;
            visitor.m_iTree = m_iTree;
            voxelMin.bitsVoxel = v22.bitsVoxel;
            while ( 1 )
            {
              v23 = CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::Find(
                      this: &this->m_aVoxelHash,
                      uiKey: v22.uiVoxel | ((m_iTree | (v19 << 11)) << 11));
              if ( v23 != -1 )
              {
                for ( i = *(_DWORD *)(v23 + 4); i != 0; i = *(_DWORD *)(i + 8) )
                  CVoxelHash::RenderObjectInVoxel(this, hPartition: *(_WORD *)i, &pVisitor, flTime);
              }
              m_pVisits = visitor.m_pVisits;
              if ( (CVarBitVec *)++v19 > visitor.m_pVisits )
                break;
              v22.bitsVoxel = voxelMin.bitsVoxel;
              m_iTree = visitor.m_iTree;
            }
            v16 = v41;
            v18 = iX;
            v17 = v35;
          }
          iX = ++v18;
          if ( v18 > voxelMax )
            break;
          v19 = v38;
        }
        v7 = v34;
        v15 = v42;
      }
      v41 = ++v16;
    }
    while ( v16 <= LODWORD(v17) );
  }
  v25 = this->m_pTree;
  v26 = (unsigned int)GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index);
  p_m_FreeVisits = &v25->m_FreeVisits;
  DepthAndSequence = v25->m_FreeVisits.m_Head.value32.DepthAndSequence;
  iXa = v26;
  Next = v25->m_FreeVisits.m_Head.value.Next;
  p_m_pInt = &v25->m_pVisits[v26][-1].m_pInt;
  *p_m_pInt = (unsigned int *)Next;
  if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                          a1: &v25->m_FreeVisits,
                          a2: p_m_pInt,
                          a3: DepthAndSequence + 65537,
                          a4: Next,
                          a5: DepthAndSequence) != 0 )
  {
    v25->m_pVisits[iXa] = v40;
  }
  else
  {
    do
    {
      _mm_pause();
      v32 = v25->m_FreeVisits.m_Head.value32.DepthAndSequence;
      v30 = p_m_FreeVisits->m_Head.value.Next;
      *p_m_pInt = (unsigned int *)p_m_FreeVisits->m_Head.value.Next;
    }
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: &v25->m_FreeVisits,
                               a2: p_m_pInt,
                               a3: v32 + 65537,
                               a4: v30,
                               a5: v32) == 0 );
    v25->m_pVisits[iXa] = v40;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DC5E0
// Name: public: virtual void CVoxelTree::Init(class CSpatialPartition __near *,int,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelTree::Init(
        CVoxelTree *this,
        CSpatialPartition *pOwner,
        int iTree,
        const Vector *worldmin,
        const Vector *worldmax)
{
  int v6; // ebx
  int i; // edi
  CUtlFixedLinkedList<LeafListData_t> *p_m_aLeafList; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t **p_m_pBlocks; // eax
  int v10; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *v11; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *v12; // edi
  int m_nBlockSize; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *m_pNext; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *v15; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *v16; // [esp-4h] [ebp-20h]
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *v17; // [esp-4h] [ebp-20h]
  _DWORD v18[2]; // [esp+Ch] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *m_pBlocks; // [esp+14h] [ebp-8h] BYREF
  int v20; // [esp+18h] [ebp-4h]
  CSpatialPartition *pOwnera; // [esp+24h] [ebp+8h]

  v6 = 0;
  this->m_pOwner = pOwner;
  this->m_TreeId = iTree;
  memset(dst: (unsigned __int8 *)this->m_pVisits, value: 0, count: sizeof(this->m_pVisits));
  for ( i = 0; i < this->m_nLevelCount; ++v6 )
    CVoxelHash::Init(this: &this->m_pVoxelHash[v6], pPartition: this, worldmin, worldmax, nLevel: i++);
  p_m_aLeafList = &this->m_aLeafList;
  pOwnera = (CSpatialPartition *)p_m_aLeafList;
  if ( p_m_aLeafList->m_LastAlloc.m_pBlockHeader != nullptr || p_m_aLeafList->m_LastAlloc.m_nIndex != -1 )
  {
    if ( p_m_aLeafList->m_Memory.m_pBlocks != nullptr )
    {
      m_pBlocks = p_m_aLeafList->m_Memory.m_pBlocks;
      v20 = 0;
    }
    else
    {
      m_pBlocks = nullptr;
      v20 = -1;
    }
LABEL_8:
    p_m_pBlocks = &m_pBlocks;
LABEL_9:
    v10 = (int)p_m_pBlocks[1];
    v11 = *p_m_pBlocks;
    while ( 1 )
    {
      if ( v11 != nullptr )
      {
        if ( v10 >= 0 && v10 < v11->m_nBlockSize )
        {
          if ( &v11[2 * v10] == (CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::IsIdxAfter(
                 this: (CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> > *)pOwnera,
                 i: (int)&v11[2 * v10 + 1],
                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::Iterator_t *)&pOwnera->m_aHandles.m_Memory.m_MemoryStack.m_alignment)
            || v11[2 * v10 + 2].m_pNext == &v11[2 * v10 + 1]
            && (CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *)v11[2 * v10 + 2].m_nBlockSize != &v11[2 * v10 + 1] )
          {
            p_m_aLeafList = (CUtlFixedLinkedList<LeafListData_t> *)pOwnera;
          }
          else
          {
            v11[2 * v10 + 2].m_pNext = &v11[2 * v10 + 1];
            v11[2 * v10 + 2].m_nBlockSize = *(_DWORD *)&pOwnera->m_aHandles.m_Memory.m_MemoryStack.m_bRegisteredAllocation;
            *(_DWORD *)&pOwnera->m_aHandles.m_Memory.m_MemoryStack.m_bRegisteredAllocation = &v11[2 * v10 + 1];
            p_m_aLeafList = (CUtlFixedLinkedList<LeafListData_t> *)pOwnera;
          }
        }
      }
      else if ( v10 == -1 )
      {
        break;
      }
      if ( v11 == p_m_aLeafList->m_LastAlloc.m_pBlockHeader && v10 == p_m_aLeafList->m_LastAlloc.m_nIndex )
        break;
      if ( v11 != nullptr && v10 >= 0 && (m_nBlockSize = v11->m_nBlockSize, v10 < m_nBlockSize) )
      {
        if ( ++v10 >= m_nBlockSize )
        {
          m_pNext = v11->m_pNext;
          if ( m_pNext != nullptr )
          {
            m_pBlocks = m_pNext;
            v20 = 0;
            goto LABEL_8;
          }
          v18[0] = 0;
          v18[1] = -1;
          p_m_pBlocks = (CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t **)v18;
          goto LABEL_9;
        }
      }
      else
      {
        v11 = nullptr;
        v10 = -1;
      }
    }
    p_m_aLeafList->m_Head = 0;
    p_m_aLeafList->m_Tail = 0;
    p_m_aLeafList->m_ElementCount = 0;
  }
  v12 = p_m_aLeafList->m_Memory.m_pBlocks;
  if ( p_m_aLeafList->m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v16 = v12;
      v12 = v12->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16);
    }
    while ( v12 != nullptr );
    p_m_aLeafList->m_Memory.m_pBlocks = nullptr;
    p_m_aLeafList->m_Memory.m_nAllocationCount = 0;
  }
  p_m_aLeafList->m_FirstFree = 0;
  p_m_aLeafList->m_NumAlloced = 0;
  p_m_aLeafList->m_LastAlloc.m_pBlockHeader = nullptr;
  p_m_aLeafList->m_LastAlloc.m_nIndex = -1;
  p_m_aLeafList->m_pElements = nullptr;
  v15 = p_m_aLeafList->m_Memory.m_pBlocks;
  if ( p_m_aLeafList->m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v17 = v15;
      v15 = v15->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v17);
    }
    while ( v15 != nullptr );
    p_m_aLeafList->m_Memory.m_pBlocks = nullptr;
    p_m_aLeafList->m_Memory.m_nAllocationCount = 0;
  }
  p_m_aLeafList->m_pElements = nullptr;
  p_m_aLeafList->m_Memory.m_nGrowSize = 512;
}

//------------------------------------------------------------------------------
// Address: 0x101DC880
// Name: public: void CVoxelTree::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelTree::Shutdown(CVoxelTree *this)
{
  CVoxelTree *v1; // esi
  CVoxelHash *v2; // ebx
  CUtlFixedLinkedList<CSpatialEntry> *p_m_aEntityList; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::Iterator_t *p_m_LastAlloc; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int> >::BlockHeader_t *m_pBlocks; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t **v6; // eax
  int v7; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *v8; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int> >::BlockHeader_t *v9; // esi
  CVoxelHash *v10; // eax
  CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *p_m_aVoxelHash; // esi
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *m_pFirst; // eax
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *pNext; // edi
  CVoxelTree *v14; // ecx
  int v15; // eax
  CVoxelHash *v16; // eax
  int m_nBlockSize; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *m_pNext; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int> >::BlockHeader_t *v19; // [esp-Ch] [ebp-44h]
  _DWORD v20[2]; // [esp+4h] [ebp-34h] BYREF
  _DWORD v21[2]; // [esp+Ch] [ebp-2Ch] BYREF
  _DWORD v22[2]; // [esp+14h] [ebp-24h] BYREF
  _DWORD v23[2]; // [esp+1Ch] [ebp-1Ch] BYREF
  CVoxelTree *v24; // [esp+24h] [ebp-14h]
  int i; // [esp+28h] [ebp-10h]
  unsigned int v26; // [esp+2Ch] [ebp-Ch]
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::Iterator_t *it; // [esp+30h] [ebp-8h]
  CVoxelHash *v28; // [esp+34h] [ebp-4h]

  v1 = this;
  v24 = this;
  CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>>::Purge(this: &this->m_aLeafList);
  i = 0;
  if ( v1->m_nLevelCount > 0 )
  {
    v26 = 0;
    while ( 1 )
    {
      v2 = &v1->m_pVoxelHash[v26 / 0x1058];
      p_m_aEntityList = &v2->m_aEntityList;
      p_m_LastAlloc = (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::Iterator_t *)&v2->m_aEntityList.m_LastAlloc;
      v28 = v2;
      it = (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::Iterator_t *)&v2->m_aEntityList.m_LastAlloc;
      if ( v2->m_aEntityList.m_LastAlloc.m_pBlockHeader != nullptr || v2->m_aEntityList.m_LastAlloc.m_nIndex != -1 )
      {
        m_pBlocks = p_m_aEntityList->m_Memory.m_pBlocks;
        if ( m_pBlocks != nullptr )
        {
          v23[0] = m_pBlocks;
          v23[1] = 0;
          v6 = (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t **)v23;
        }
        else
        {
          v22[0] = 0;
          v22[1] = -1;
          v6 = (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t **)v22;
        }
LABEL_9:
        v7 = (int)v6[1];
        v8 = *v6;
        while ( 1 )
        {
          if ( v8 != nullptr )
          {
            if ( v7 >= 0
              && v7 < v8->m_nBlockSize
              && (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *)((char *)v8 + 12 * v7) != (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *)-8
              && !CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int>>::IsIdxAfter(
                    this: (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > *)&v28->m_aEntityList,
                    i: (int)&v8[1] + 12 * v7,
                    it)
              && (*((CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t **)&v8[1].m_nBlockSize + 3 * v7) != (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *)((char *)&v8[1] + 12 * v7)
               || *(&v8[2].m_pNext + 3 * v7) == (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *)((char *)&v8[1] + 12 * v7)) )
            {
              v16 = v28;
              *(&v8[1].m_nBlockSize + 3 * v7) = (int)v8 + 12 * v7 + 8;
              *((_DWORD *)&v8[2].m_pNext + 3 * v7) = v16->m_aEntityList.m_FirstFree;
              v16->m_aEntityList.m_FirstFree = (int)&v8[1] + 12 * v7;
            }
          }
          else if ( v7 == -1 )
          {
            break;
          }
          if ( v8 == it->m_pBlockHeader && v7 == it->m_nIndex )
            break;
          if ( v8 != nullptr && v7 >= 0 && (m_nBlockSize = v8->m_nBlockSize, v7 < m_nBlockSize) )
          {
            if ( ++v7 >= m_nBlockSize )
            {
              m_pNext = v8->m_pNext;
              if ( m_pNext != nullptr )
              {
                v21[0] = m_pNext;
                v21[1] = 0;
                v6 = (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t **)v21;
              }
              else
              {
                v20[0] = 0;
                v20[1] = -1;
                v6 = (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t **)v20;
              }
              goto LABEL_9;
            }
          }
          else
          {
            v8 = nullptr;
            v7 = -1;
          }
        }
        v2 = v28;
        p_m_LastAlloc = it;
        p_m_aEntityList = &v28->m_aEntityList;
        v28->m_aEntityList.m_Head = 0;
        p_m_aEntityList->m_Tail = 0;
        p_m_aEntityList->m_ElementCount = 0;
      }
      v9 = p_m_aEntityList->m_Memory.m_pBlocks;
      if ( p_m_aEntityList->m_Memory.m_pBlocks != nullptr )
      {
        do
        {
          v19 = v9;
          v9 = v9->m_pNext;
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19);
        }
        while ( v9 != nullptr );
        v10 = v28;
        p_m_LastAlloc = it;
        v28->m_aEntityList.m_Memory.m_pBlocks = nullptr;
        v10->m_aEntityList.m_Memory.m_nAllocationCount = 0;
        v2 = v10;
      }
      v2->m_aEntityList.m_FirstFree = 0;
      v2->m_aEntityList.m_NumAlloced = 0;
      p_m_LastAlloc->m_pBlockHeader = nullptr;
      p_m_LastAlloc->m_nIndex = -1;
      v2->m_aEntityList.m_pElements = nullptr;
      p_m_aVoxelHash = &v2->m_aVoxelHash;
      for ( it = (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::Iterator_t *)512;
            it != nullptr;
            it = (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::Iterator_t *)((char *)it - 1) )
      {
        m_pFirst = p_m_aVoxelHash->m_aBuckets[0].m_pFirst;
        if ( p_m_aVoxelHash->m_aBuckets[0].m_pFirst != nullptr )
        {
          do
          {
            pNext = m_pFirst->pNext;
            free(pMem: m_pFirst);
            m_pFirst = pNext;
          }
          while ( pNext != p_m_aVoxelHash->m_aBuckets[0].m_pFirst );
        }
        p_m_aVoxelHash->m_aBuckets[0].m_pFirst = nullptr;
        p_m_aVoxelHash->m_aBuckets[0].m_nElems = 0;
        p_m_aVoxelHash = (CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *)((char *)p_m_aVoxelHash + 8);
      }
      v14 = v24;
      v26 += 4184;
      v15 = i + 1;
      v2->m_aVoxelHash.m_nElements = 0;
      i = v15;
      if ( v15 >= v14->m_nLevelCount )
        break;
      v1 = v14;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DCA70
// Name: public: virtual void CVoxelTree::EnumerateElementsInBox(int,class Vector const __near &,class Vector const __near &,bool,class IPartitionEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelTree::EnumerateElementsInBox(
        CVoxelTree *this,
        int listMask,
        CVarBitVec *vecMins,
        const Vector *vecMaxs,
        bool coarseTest,
        IPartitionEnumerator *pIterator)
{
  double x; // st7
  double y; // st6
  double z; // st5
  double v10; // st2
  double v11; // st7
  double v12; // st3
  double v13; // st7
  double v14; // st3
  double v15; // st6
  double v16; // st4
  double v17; // st6
  double v18; // st3
  double v19; // st5
  double v20; // st4
  double v21; // st3
  double v22; // rtt
  double v23; // st3
  double v24; // st4
  double v25; // st7
  double v26; // st5
  double v27; // st7
  CVarBitVec *v28; // eax
  CThreadSpinRWLock *p_m_lock; // ecx
  signed __int32 m_i32; // edx
  CVoxelHash *m_pVoxelHash; // eax
  unsigned int m_nLevelShift; // ecx
  unsigned int v33; // esi
  unsigned int v34; // edi
  void *v35; // esi
  unsigned int v36; // edi
  unsigned int v37; // esi
  unsigned int v38; // edi
  unsigned int v39; // esi
  Vector mins; // [esp+4h] [ebp-18h] BYREF
  Vector maxs; // [esp+10h] [ebp-Ch] BYREF
  CVarBitVec *pPrevVisits; // [esp+28h] [ebp+Ch]

  if ( listMask != 0 )
  {
    x = s_PartitionMin.x;
    if ( *(float *)&vecMins->m_numBits >= (double)s_PartitionMin.x )
      x = *(float *)&vecMins->m_numBits;
    y = s_PartitionMin.y;
    if ( *(float *)&vecMins->m_iBitStringStorage >= (double)s_PartitionMin.y )
      y = *(float *)&vecMins->m_iBitStringStorage;
    z = s_PartitionMin.z;
    if ( *(float *)&vecMins->m_pInt >= (double)s_PartitionMin.z )
      z = *(float *)&vecMins->m_pInt;
    v10 = x;
    v11 = s_PartitionMax.x;
    if ( v10 <= s_PartitionMax.x )
      v11 = v10;
    v12 = v11;
    v13 = s_PartitionMax.x;
    mins.x = v12;
    v14 = y;
    v15 = s_PartitionMax.y;
    if ( v14 <= s_PartitionMax.y )
      v15 = v14;
    v16 = v15;
    v17 = s_PartitionMin.z;
    mins.y = v16;
    v18 = z;
    v19 = s_PartitionMax.z;
    if ( v18 <= s_PartitionMax.z )
      v19 = v18;
    mins.z = v19;
    v20 = s_PartitionMin.x;
    if ( vecMaxs->x >= (double)s_PartitionMin.x )
      v20 = vecMaxs->x;
    v21 = s_PartitionMin.y;
    if ( vecMaxs->y >= (double)s_PartitionMin.y )
      v21 = vecMaxs->y;
    if ( vecMaxs->z >= v17 )
      v17 = vecMaxs->z;
    v22 = v21;
    v23 = v20;
    v24 = v22;
    if ( v23 <= v13 )
      v13 = v23;
    maxs.x = v13;
    v25 = s_PartitionMax.y;
    if ( v24 <= s_PartitionMax.y )
      v25 = v24;
    v26 = v25;
    v27 = s_PartitionMax.z;
    maxs.y = v26;
    if ( v17 <= s_PartitionMax.z )
      v27 = v17;
    maxs.z = v27;
    v28 = CVoxelTree::BeginVisit(this);
    p_m_lock = &this->m_lock;
    pPrevVisits = v28;
    if ( (this->m_lock.m_lockInfo.m_i32 & 0x10000) != 0
      || (m_i32 = (unsigned __int16)p_m_lock->m_lockInfo.m_i32,
          _InterlockedCompareExchange((volatile signed __int32 *)p_m_lock, m_i32 + 1, m_i32) != m_i32) )
    {
      CThreadSpinRWLock::SpinLockForRead(this: p_m_lock);
    }
    m_pVoxelHash = this->m_pVoxelHash;
    m_nLevelShift = m_pVoxelHash->m_nLevelShift;
    v33 = ((int)(float)(mins.x - m_pVoxelHash->m_vecVoxelOrigin.x) >> m_nLevelShift) & 0x7FF
        | ((((int)(float)(mins.y - m_pVoxelHash->m_vecVoxelOrigin.y) >> m_nLevelShift) & 0x7FF
          | ((int)(float)(mins.z - m_pVoxelHash->m_vecVoxelOrigin.z) >> m_nLevelShift << 11)) << 11);
    v34 = ((int)(float)(maxs.x - m_pVoxelHash->m_vecVoxelOrigin.x) >> m_nLevelShift) & 0x7FF
        | ((((int)(float)(maxs.z - m_pVoxelHash->m_vecVoxelOrigin.z) >> m_nLevelShift << 11)
          | ((int)(float)(maxs.y - m_pVoxelHash->m_vecVoxelOrigin.y) >> m_nLevelShift) & 0x7FF) << 11);
    if ( CVoxelHash::EnumerateElementsInBox(
           this: m_pVoxelHash,
           listMask,
           vmin: (Voxel_t)v33,
           vmax: (Voxel_t)v34,
           &mins,
           &maxs,
           pIterator) != 0
      && (v36 = (v34 >> 2) & 0x3FCFF9FF,
          v37 = (v33 >> 2) & 0x3FCFF9FF,
          CVoxelHash::EnumerateElementsInBox(
            this: this->m_pVoxelHash + 1,
            listMask,
            vmin: (Voxel_t)v37,
            vmax: (Voxel_t)v36,
            &mins,
            &maxs,
            pIterator) != 0) )
    {
      v38 = (v36 >> 2) & 0x3FCFF9FF;
      v39 = (v37 >> 2) & 0x3FCFF9FF;
      if ( CVoxelHash::EnumerateElementsInBox(
             this: this->m_pVoxelHash + 2,
             listMask,
             vmin: (Voxel_t)v39,
             vmax: (Voxel_t)v38,
             &mins,
             &maxs,
             pIterator) != 0 )
        CVoxelHash::EnumerateElementsInBox(
          this: this->m_pVoxelHash + 3,
          listMask,
          vmin: (Voxel_t)((v39 >> 2) & 0x3FCFF9FF),
          vmax: (Voxel_t)((v38 >> 2) & 0x3FCFF9FF),
          &mins,
          &maxs,
          pIterator);
      _InterlockedExchangeAdd((volatile signed __int32 *)&this->m_lock, 0xFFFFFFFF);
      CVoxelTree::EndVisit(this, pPrev: pPrevVisits);
    }
    else
    {
      _InterlockedExchangeAdd((volatile signed __int32 *)&this->m_lock, 0xFFFFFFFF);
      v35 = GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index);
      CTSListBase::Push(this: &this->m_FreeVisits, pNode: (TSLNodeBase_t *)&this->m_pVisits[(_DWORD)v35][-1].m_pInt);
      this->m_pVisits[(_DWORD)v35] = pPrevVisits;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DCDA0
// Name: public: virtual void CVoxelTree::EnumerateElementsAlongRay(int,struct Ray_t const __near &,bool,class IPartitionEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CVoxelTree::EnumerateElementsAlongRay(
        CVoxelTree *this@<ecx>,
        float a2@<ebp>,
        int listMask,
        const Ray_t *ray,
        int coarseTest,
        IPartitionEnumerator *pIterator)
{
  char *v6; // esi
  int v7; // ecx
  int v8; // ecx
  int m_nValue; // eax
  float x; // xmm0_4
  float y; // xmm2_4
  float z; // xmm6_4
  void (__stdcall *v13)(int, Vector *, _BYTE *, int, IPartitionEnumerator *, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // eax
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm6_4
  float v21; // xmm2_4
  bool v22; // al
  float v23; // esi
  CVarBitVec *v24; // eax
  CThreadSpinRWLock::LockInfo_t v25; // ecx
  signed __int32 v26; // ecx
  void *v27; // edi
  int v28; // [esp-1Ch] [ebp-ACh]
  int v29; // [esp-18h] [ebp-A8h]
  int v30; // [esp-14h] [ebp-A4h]
  int v31; // [esp-10h] [ebp-A0h]
  _BYTE v32[92]; // [esp-Ch] [ebp-9Ch] OVERLAPPED BYREF
  float v33; // [esp+50h] [ebp-40h]
  float v34; // [esp+54h] [ebp-3Ch]
  Vector vecMax; // [esp+58h] [ebp-38h] BYREF
  Vector vecMin; // [esp+64h] [ebp-2Ch] BYREF
  Vector vecInvDelta; // [esp+70h] [ebp-20h] BYREF
  Vector vecEnd; // [esp+7Ch] [ebp-14h]
  CVarBitVec *pPrevVisits; // [esp+88h] [ebp-8h]
  CVarBitVec *retaddr; // [esp+90h] [ebp+0h]

  vecEnd.z = a2;
  pPrevVisits = retaddr;
  LODWORD(vecEnd.x) = this;
  if ( (_S1_18 & 1) == 0 )
  {
    _S1_18 |= 1u;
    bIsPublic = GetSteamUniverse() == k_EUniversePublic;
  }
  if ( !bIsPublic
    && think_trace_limit.m_pParent != nullptr
    && think_trace_limit.m_pParent->m_Value.m_nValue != 0
    && (int)GenericThreadLocals::CThreadLocalBase::Get(this: &g_DebugTracesRemainingBeforeTrap) > 0 )
  {
    v6 = (char *)GenericThreadLocals::CThreadLocalBase::Get(this: &g_DebugTracesRemainingBeforeTrap) - 1;
    GenericThreadLocals::CThreadLocalBase::Set(this: &g_DebugTracesRemainingBeforeTrap, a2: v6);
    if ( (int)v6 <= 0 && (unsigned __int8)_Plat_IsInDebugSession(a1: v7) != 0 )
    {
      if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v8) != 0 )
        __debugbreak();
      if ( think_trace_limit.m_pParent != nullptr )
      {
        m_nValue = think_trace_limit.m_pParent->m_Value.m_nValue;
        if ( m_nValue < 0 )
          GenericThreadLocals::CThreadLocalBase::Set(this: &g_DebugTracesRemainingBeforeTrap, a2: (void *)-m_nValue);
      }
    }
  }
  if ( !ray->m_IsSwept )
  {
    x = ray->m_Extents.x;
    y = ray->m_Start.y;
    z = ray->m_Start.z;
    v13 = *(void (__stdcall **)(int, Vector *, _BYTE *, int, IPartitionEnumerator *, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)LODWORD(vecEnd.x) + 12);
    v14 = ray->m_Start.x - x;
    v15 = x + ray->m_Start.x;
    vecMax.x = v14;
    v16 = ray->m_Extents.y;
    v17 = y - v16;
    v18 = v16 + ray->m_Start.y;
    vecMax.y = v17;
    v19 = ray->m_Extents.z;
    v20 = z - v19;
    v21 = v19 + ray->m_Start.z;
    vecMax.z = v20;
    *(float *)&v32[88] = v15;
    v33 = v18;
    v34 = v21;
    v13(
      a1: listMask,
      a2: &vecMax,
      a3: &v32[88],
      a4: coarseTest,
      a5: pIterator,
      a6: v28,
      a7: v29,
      a8: v30,
      a9: v31,
      a10: *(_DWORD *)v32,
      a11: *(_DWORD *)&v32[4],
      a12: *(_DWORD *)&v32[8],
      a13: *(_DWORD *)&v32[12],
      a14: *(_DWORD *)&v32[16],
      a15: *(_DWORD *)&v32[20],
      a16: *(_DWORD *)&v32[24],
      a17: *(_DWORD *)&v32[28],
      a18: *(_DWORD *)&v32[32],
      a19: *(_DWORD *)&v32[36],
      a20: *(_DWORD *)&v32[40],
      a21: *(_DWORD *)&v32[44],
      a22: *(_DWORD *)&v32[48],
      a23: *(_DWORD *)&v32[52],
      a24: *(_DWORD *)&v32[56],
      a25: *(_DWORD *)&v32[60],
      a26: *(_DWORD *)&v32[64],
      a27: *(_DWORD *)&v32[68],
      a28: *(_DWORD *)&v32[72],
      a29: *(_DWORD *)&v32[76],
      a30: *(_DWORD *)&v32[80],
      a31: *(_DWORD *)&v32[84]);
    return;
  }
  if ( listMask != 0 )
  {
    *(Ray_t *)v32 = *ray;
    vecInvDelta.x = *(float *)&v32[16] + *(float *)v32;
    vecInvDelta.y = *(float *)&v32[20] + *(float *)&v32[4];
    vecInvDelta.z = *(float *)&v32[24] + *(float *)&v32[8];
    HIBYTE(vecEnd.y) = IsPointInBox(pt: &ray->m_Start, boxMin: &s_PartitionMin, boxMax: &s_PartitionMax);
    v22 = IsPointInBox(pt: &vecInvDelta, boxMin: &s_PartitionMin, boxMax: &s_PartitionMax);
    if ( HIBYTE(vecEnd.y) != 0 )
    {
      if ( !v22 )
        ClampEndPoint(ray: (Ray_t *)v32, vecEnd: &vecInvDelta);
    }
    else
    {
      if ( !v22 )
        return;
      ClampStartPoint(ray: (Ray_t *)v32, vecEnd: &vecInvDelta);
    }
    if ( *(float *)&v32[16] == 0.0 )
      vecMin.x = 3.4028235e38;
    else
      vecMin.x = 1.0 / *(float *)&v32[16];
    if ( *(float *)&v32[20] == 0.0 )
      vecMin.y = 3.4028235e38;
    else
      vecMin.y = 1.0 / *(float *)&v32[20];
    if ( *(float *)&v32[24] == 0.0 )
      vecMin.z = 3.4028235e38;
    else
      vecMin.z = 1.0 / *(float *)&v32[24];
    v23 = vecEnd.x;
    v24 = CVoxelTree::BeginVisit(this: (CVoxelTree *)LODWORD(vecEnd.x));
    v25 = *(CThreadSpinRWLock::LockInfo_t *)(LODWORD(v23) + 232);
    LODWORD(vecEnd.x) = v24;
    if ( (v25.m_i32 & 0x10000) != 0
      || (v26 = (unsigned __int16)*(_DWORD *)(LODWORD(v23) + 232),
          _InterlockedCompareExchange((volatile signed __int32 *)(LODWORD(v23) + 232), v26 + 1, v26) != v26) )
    {
      CThreadSpinRWLock::SpinLockForRead(this: (CThreadSpinRWLock *)(LODWORD(v23) + 232));
    }
    if ( ray->m_IsRay )
      CVoxelTree::EnumerateElementsAlongRay_Ray(
        this: (CVoxelTree *)LODWORD(v23),
        listMask,
        ray: (const Ray_t *)v32,
        vecInvDelta: &vecMin,
        vecEnd: &vecInvDelta,
        pIterator);
    else
      CVoxelTree::EnumerateElementsAlongRay_ExtrudedRay(
        this: (CVoxelTree *)LODWORD(v23),
        listMask,
        ray: (const Ray_t *)v32,
        vecInvDelta: &vecMin,
        vecEnd: &vecInvDelta,
        pIterator);
    _InterlockedExchangeAdd((volatile signed __int32 *)(LODWORD(v23) + 232), 0xFFFFFFFF);
    v27 = GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index);
    CTSListBase::Push(
      this: (CTSListBase *)(LODWORD(v23) + 224),
      pNode: (TSLNodeBase_t *)(*(_DWORD *)(LODWORD(v23) + 4 * (_DWORD)v27 + 64) - 4));
    *(float *)(LODWORD(v23) + 4 * (_DWORD)v27 + 64) = vecEnd.x;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DD0D0
// Name: public: virtual void CVoxelTree::RenderAllObjectsInTree(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelTree::RenderAllObjectsInTree(CVoxelTree *this, float flTime)
{
  CThreadSpinRWLock *p_m_lock; // ebx
  signed __int32 m_i32; // ecx
  int v5; // edi
  int v6; // ebx
  IMDLCache *v7; // [esp+Ch] [ebp-8h]

  v7 = g_pMDLCache;
  ((void (*)(void))g_pMDLCache->BeginLock)();
  p_m_lock = &this->m_lock;
  if ( (this->m_lock.m_lockInfo.m_i32 & 0x10000) != 0
    || (m_i32 = (unsigned __int16)p_m_lock->m_lockInfo.m_i32,
        _InterlockedCompareExchange((volatile signed __int32 *)p_m_lock, m_i32 + 1, m_i32) != m_i32) )
  {
    CThreadSpinRWLock::SpinLockForRead(this: &this->m_lock);
  }
  v5 = 0;
  if ( this->m_nLevelCount > 0 )
  {
    v6 = 0;
    do
    {
      CVoxelHash::RenderAllObjectsInTree(this: &this->m_pVoxelHash[v6], flTime);
      ++v5;
      ++v6;
    }
    while ( v5 < this->m_nLevelCount );
    p_m_lock = &this->m_lock;
  }
  _InterlockedExchangeAdd((volatile signed __int32 *)p_m_lock, 0xFFFFFFFF);
  v7->EndLock(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x101DD170
// Name: public: virtual void CVoxelTree::RenderObjectsInPlayerLeafs(class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelTree::RenderObjectsInPlayerLeafs(
        CVoxelTree *this,
        const Vector *vecPlayerMin,
        const Vector *vecPlayerMax,
        float flTime)
{
  CThreadSpinRWLock *p_m_lock; // ebx
  signed __int32 m_i32; // ecx
  int v7; // edi
  int v8; // ebx
  IMDLCache *v9; // [esp+Ch] [ebp-8h]

  v9 = g_pMDLCache;
  ((void (*)(void))g_pMDLCache->BeginLock)();
  p_m_lock = &this->m_lock;
  if ( (this->m_lock.m_lockInfo.m_i32 & 0x10000) != 0
    || (m_i32 = (unsigned __int16)p_m_lock->m_lockInfo.m_i32,
        _InterlockedCompareExchange((volatile signed __int32 *)p_m_lock, m_i32 + 1, m_i32) != m_i32) )
  {
    CThreadSpinRWLock::SpinLockForRead(this: &this->m_lock);
  }
  v7 = 0;
  if ( this->m_nLevelCount > 0 )
  {
    v8 = 0;
    do
    {
      CVoxelHash::RenderObjectsInPlayerLeafs(this: &this->m_pVoxelHash[v8], vecPlayerMin, vecPlayerMax, flTime);
      ++v7;
      ++v8;
    }
    while ( v7 < this->m_nLevelCount );
    p_m_lock = &this->m_lock;
  }
  _InterlockedExchangeAdd((volatile signed __int32 *)p_m_lock, 0xFFFFFFFF);
  v9->EndLock(this: v9);
}

//------------------------------------------------------------------------------
// Address: 0x101DD220
// Name: public: virtual void CVoxelTree::DrawDebugOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelTree::DrawDebugOverlays(CVoxelTree *this)
{
  CThreadSpinRWLock *p_m_lock; // edi
  signed __int32 m_i32; // ecx
  int v4; // esi
  int v5; // edi
  CThreadSpinRWLock *v6; // [esp+10h] [ebp-8h]
  int m_nValue; // [esp+14h] [ebp-4h]

  if ( r_partition_level.m_pParent != nullptr )
  {
    m_nValue = r_partition_level.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
      return;
  }
  else
  {
    m_nValue = 0;
  }
  p_m_lock = &this->m_lock;
  v6 = &this->m_lock;
  if ( (this->m_lock.m_lockInfo.m_i32 & 0x10000) != 0
    || (m_i32 = (unsigned __int16)p_m_lock->m_lockInfo.m_i32,
        _InterlockedCompareExchange((volatile signed __int32 *)p_m_lock, m_i32 + 1, m_i32) != m_i32) )
  {
    CThreadSpinRWLock::SpinLockForRead(this: &this->m_lock);
  }
  v4 = 0;
  if ( this->m_nLevelCount > 0 )
  {
    v5 = 0;
    do
    {
      if ( m_nValue == v4 )
      {
        CVoxelHash::RenderGrid(this: &this->m_pVoxelHash[v5]);
        CVoxelHash::RenderAllObjectsInTree(this: &this->m_pVoxelHash[v5], flTime: 0.0099999998);
      }
      ++v4;
      ++v5;
    }
    while ( v4 < this->m_nLevelCount );
    p_m_lock = v6;
  }
  _InterlockedExchangeAdd((volatile signed __int32 *)p_m_lock, 0xFFFFFFFF);
}

//------------------------------------------------------------------------------
// Address: 0x101DD2D0
// Name: public: CTSPool<class CVarBitVec>::~CTSPool<class CVarBitVec>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSPool<CVarBitVec>::~CTSPool<CVarBitVec>(CTSPool<CVarBitVec> *this)
{
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax

  while ( 1 )
  {
    Next = this->m_Head.value.Next;
    DepthAndSequence = this->m_Head.value32.DepthAndSequence;
    if ( this->m_Head.value.Next == nullptr )
      break;
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: this,
                               a2: Next->Next,
                               a3: DepthAndSequence - 1,
                               a4: Next,
                               a5: DepthAndSequence) == 0 )
    {
      _mm_pause();
      Next = this->m_Head.value.Next;
      DepthAndSequence = this->m_Head.value32.DepthAndSequence;
      if ( this->m_Head.value.Next == nullptr )
        goto LABEL_4;
    }
    if ( *((_WORD *)&Next->Next + 3) > 1u )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)&Next[1].Next + 1));
    *((_DWORD *)&Next[1].Next + 1) = 0;
    free(pMem: Next);
  }
LABEL_4:
  CTSListBase::Detach(this);
}

//------------------------------------------------------------------------------
// Address: 0x101DD480
// Name: public: CVoxelHash::CVoxelHash(void)
// Source: json
//------------------------------------------------------------------------------
CVoxelHash *__thiscall CVoxelHash::CVoxelHash(CVoxelHash *this)
{
  CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *p_m_aVoxelHash; // ecx
  CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *v3; // eax
  int i; // edx

  p_m_aVoxelHash = &this->m_aVoxelHash;
  v3 = p_m_aVoxelHash;
  for ( i = 511; i >= 0; --i )
  {
    v3->m_aBuckets[0].m_pFirst = nullptr;
    v3->m_aBuckets[0].m_nElems = 0;
    v3 = (CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *)((char *)v3 + 8);
  }
  CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::RemoveAll(this: p_m_aVoxelHash);
  this->m_aEntityList.m_Memory.m_pBlocks = nullptr;
  this->m_aEntityList.m_Memory.m_nAllocationCount = 0;
  this->m_aEntityList.m_Memory.m_nGrowSize = 0;
  this->m_aEntityList.m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_aEntityList.m_LastAlloc.m_nIndex = -1;
  this->m_aEntityList.m_Head = 0;
  this->m_aEntityList.m_Tail = 0;
  this->m_aEntityList.m_FirstFree = 0;
  this->m_aEntityList.m_ElementCount = 0;
  this->m_aEntityList.m_NumAlloced = 0;
  this->m_aEntityList.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101DD4F0
// Name: public: CVoxelHash::~CVoxelHash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelHash::~CVoxelHash(CVoxelHash *this)
{
  CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *p_m_aEntityList; // edi
  CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *p_m_aVoxelHash; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *v5; // [esp-4h] [ebp-10h]

  p_m_aEntityList = (CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *)&this->m_aEntityList;
  CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::Purge(this: (CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *)&this->m_aEntityList);
  p_m_aVoxelHash = &this->m_aVoxelHash;
  CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::RemoveAll(this: &this->m_aVoxelHash);
  CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::RemoveAll(this: p_m_aEntityList);
  m_pBlocks = p_m_aEntityList->m_Memory.m_pBlocks;
  if ( p_m_aEntityList->m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v5 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
    }
    while ( m_pBlocks != nullptr );
    p_m_aEntityList->m_Memory.m_pBlocks = nullptr;
    p_m_aEntityList->m_Memory.m_nAllocationCount = 0;
  }
  CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::~CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>(this: p_m_aVoxelHash);
}

//------------------------------------------------------------------------------
// Address: 0x101DD550
// Name: public: void CVoxelHash::RemoveFromTree(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelHash::RemoveFromTree(CVoxelHash *this, unsigned __int16 hPartition)
{
  CVoxelTree *m_pTree; // eax
  int v3; // esi
  CUtlFixedLinkedList<LeafListData_t> *p_m_aLeafList; // edx
  int m_TreeId; // eax
  int *v6; // edi
  int v7; // edx
  int v8; // ebx
  int v9; // esi
  int v10; // eax
  int v11; // eax
  CUtlFixedLinkedList<CSpatialEntry> *p_m_aEntityList; // ebx
  int v13; // eax
  int v14; // eax
  int v15; // eax
  CUtlFixedLinkedList<LeafListData_t> *v16; // eax
  int v17; // ecx
  EntityInfo_t *data; // [esp+8h] [ebp-10h]
  int treeId; // [esp+Ch] [ebp-Ch]
  CVoxelHash *v20; // [esp+10h] [ebp-8h]
  int iNext; // [esp+14h] [ebp-4h]
  CUtlFixedLinkedList<LeafListData_t> *leafList; // [esp+20h] [ebp+8h]

  m_pTree = this->m_pTree;
  v3 = (int)&m_pTree->m_pOwner->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * hPartition];
  p_m_aLeafList = &m_pTree->m_aLeafList;
  m_TreeId = m_pTree->m_TreeId;
  v6 = *(int **)(v3 + 4 * m_TreeId + 48);
  v20 = this;
  data = (EntityInfo_t *)v3;
  leafList = p_m_aLeafList;
  treeId = m_TreeId;
  if ( v6 != nullptr )
  {
    do
    {
      v7 = *v6;
      v8 = v6[3];
      iNext = v8;
      if ( *v6 == -1 )
      {
        v6 = (int *)v6[3];
      }
      else
      {
        v9 = v6[1];
        v10 = *(_DWORD *)(v7 + 4);
        if ( v10 == v9 )
        {
          v11 = *(_DWORD *)(v10 + 8);
          if ( v11 != 0 )
          {
            *(_DWORD *)(v7 + 4) = v11;
          }
          else
          {
            CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::Remove(this: &this->m_aVoxelHash, hHash: v7);
            this = v20;
          }
        }
        p_m_aEntityList = &this->m_aEntityList;
        if ( v9 != 0
          && !CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int>>::IsIdxAfter(
                this: (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > *)&this->m_aEntityList,
                i: v9,
                it: (const CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::Iterator_t *)&this->m_aEntityList.m_LastAlloc) )
        {
          v13 = *(_DWORD *)(v9 + 4);
          if ( v13 != v9 )
          {
            if ( v13 != 0 )
              *(_DWORD *)(v13 + 8) = *(_DWORD *)(v9 + 8);
            else
              p_m_aEntityList->m_Head = *(_DWORD *)(v9 + 8);
            v14 = *(_DWORD *)(v9 + 8);
            if ( v14 != 0 )
              *(_DWORD *)(v14 + 4) = *(_DWORD *)(v9 + 4);
            else
              p_m_aEntityList->m_Tail = *(_DWORD *)(v9 + 4);
            *(_DWORD *)(v9 + 8) = v9;
            *(_DWORD *)(v9 + 4) = v9;
            --p_m_aEntityList->m_ElementCount;
          }
        }
        *(_DWORD *)(v9 + 8) = p_m_aEntityList->m_FirstFree;
        p_m_aEntityList->m_FirstFree = v9;
        if ( CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::IsIdxAfter(
               this: &leafList->m_Memory,
               i: (int)v6,
               it: &leafList->m_LastAlloc)
          || (int *)(v15 = v6[2]) == v6 )
        {
          v16 = leafList;
        }
        else
        {
          if ( v15 != 0 )
          {
            *(_DWORD *)(v15 + 12) = v6[3];
            v16 = leafList;
          }
          else
          {
            v16 = leafList;
            leafList->m_Head = v6[3];
          }
          v17 = v6[3];
          if ( v17 != 0 )
            *(_DWORD *)(v17 + 8) = v6[2];
          else
            v16->m_Tail = v6[2];
          v6[3] = (int)v6;
          v6[2] = (int)v6;
          --v16->m_ElementCount;
        }
        v3 = (int)data;
        this = v20;
        v6[3] = v16->m_FirstFree;
        v16->m_FirstFree = (int)v6;
        v6 = (int *)iNext;
        m_TreeId = treeId;
        v8 = iNext;
      }
    }
    while ( v8 != 0 );
  }
  *(_DWORD *)(v3 + 4 * m_TreeId + 48) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DD6C0
// Name: public: CVoxelTree::CVoxelTree(void)
// Source: json
//------------------------------------------------------------------------------
CVoxelTree *__thiscall CVoxelTree::CVoxelTree(CVoxelTree *this)
{
  int m_nLevelCount; // edx
  int v3; // edi
  int v4; // ecx
  int *v5; // eax
  CVoxelHash *v6; // eax
  int v7; // edi
  CVoxelHash *v8; // ebx
  unsigned __int16 *m_pMemory; // eax
  IMemAlloc_vtbl *v10; // edx
  unsigned __int16 *v11; // eax
  CVoxelHash *v13; // [esp+8h] [ebp-4h]

  this->__vftable = (CVoxelTree_vtbl *)&CVoxelTree::`vftable';
  this->m_pVoxelHash = nullptr;
  this->m_aLeafList.m_Memory.m_pBlocks = nullptr;
  this->m_aLeafList.m_Memory.m_nAllocationCount = 0;
  this->m_aLeafList.m_Memory.m_nGrowSize = 0;
  this->m_aLeafList.m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_aLeafList.m_LastAlloc.m_nIndex = -1;
  this->m_aLeafList.m_Head = 0;
  this->m_aLeafList.m_Tail = 0;
  this->m_aLeafList.m_FirstFree = 0;
  this->m_aLeafList.m_ElementCount = 0;
  this->m_aLeafList.m_NumAlloced = 0;
  this->m_aLeafList.m_pElements = nullptr;
  this->m_pOwner = nullptr;
  this->m_AvailableVisitBits.m_Memory.m_pMemory = nullptr;
  this->m_AvailableVisitBits.m_Memory.m_nAllocationCount = 0;
  this->m_AvailableVisitBits.m_Memory.m_nGrowSize = 0;
  this->m_AvailableVisitBits.m_Size = 0;
  this->m_AvailableVisitBits.m_pElements = nullptr;
  this->m_nNextVisitBit = 0;
  if ( (((_BYTE)this - 32) & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  this->m_FreeVisits.m_Head.value.Next = nullptr;
  this->m_FreeVisits.m_Head.value32.DepthAndSequence = 0;
  this->m_lock.m_lockInfo.m_i32 = 0;
  this->m_lock.m_writerId = 0;
  for ( this->m_nLevelCount = 0; ; this->m_nLevelCount = m_nLevelCount + 1 )
  {
    m_nLevelCount = this->m_nLevelCount;
    if ( 128 >> (2 * m_nLevelCount) <= 2 )
      break;
  }
  v3 = ++this->m_nLevelCount;
  v4 = (4184 * (unsigned __int64)(unsigned int)v3) >> 32 != 0 ? -1 : 4184 * v3;
  v5 = (int *)MemAlloc_Alloc(nSize: __CFADD__(v4, 4) ? -1 : v4 + 4);
  if ( v5 != nullptr )
  {
    *v5 = v3;
    v6 = (CVoxelHash *)(v5 + 1);
    v7 = v3 - 1;
    v13 = v6;
    v8 = v6;
    if ( v7 >= 0 )
    {
      do
      {
        CVoxelHash::CVoxelHash(this: v8++);
        --v7;
      }
      while ( v7 >= 0 );
      v6 = v13;
    }
  }
  else
  {
    v6 = nullptr;
  }
  this->m_pVoxelHash = v6;
  if ( this->m_AvailableVisitBits.m_Memory.m_nAllocationCount < 2048
    && this->m_AvailableVisitBits.m_Memory.m_nGrowSize >= 0 )
  {
    this->m_AvailableVisitBits.m_Memory.m_nAllocationCount = 2048;
    m_pMemory = this->m_AvailableVisitBits.m_Memory.m_pMemory;
    v10 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v11 = (unsigned __int16 *)((int (__stdcall *)(unsigned __int16 *, int))v10->Realloc_2)(a1: m_pMemory, a2: 4096);
    else
      v11 = (unsigned __int16 *)((int (__stdcall *)(int))v10->Alloc_2)(a1: 4096);
    this->m_AvailableVisitBits.m_Memory.m_pMemory = v11;
  }
  this->m_AvailableVisitBits.m_pElements = this->m_AvailableVisitBits.m_Memory.m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101DDC20
// Name: public: virtual CVoxelTree::~CVoxelTree(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelTree::~CVoxelTree(CVoxelTree *this)
{
  CVoxelHash *m_pVoxelHash; // ecx
  CUtlFixedLinkedList<LeafListData_t> *p_m_aLeafList; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *v5; // [esp-4h] [ebp-Ch]

  m_pVoxelHash = this->m_pVoxelHash;
  this->__vftable = (CVoxelTree_vtbl *)&CVoxelTree::`vftable';
  if ( m_pVoxelHash != nullptr )
    CVoxelHash::`vector deleting destructor'(this: m_pVoxelHash, a2: 3u);
  CTSPool<CVarBitVec>::~CTSPool<CVarBitVec>(this: &this->m_FreeVisits);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_AvailableVisitBits);
  p_m_aLeafList = &this->m_aLeafList;
  CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>>::RemoveAll(this: &this->m_aLeafList);
  m_pBlocks = p_m_aLeafList->m_Memory.m_pBlocks;
  if ( p_m_aLeafList->m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v5 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
    }
    while ( m_pBlocks != nullptr );
    p_m_aLeafList->m_Memory.m_pBlocks = nullptr;
    p_m_aLeafList->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DDC80
// Name: public: void CVoxelTree::RemoveFromTree(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelTree::RemoveFromTree(CVoxelTree *this, unsigned __int16 hPartition)
{
  unsigned __int8 *v3; // ebx
  void *v4; // eax
  CThreadSpinRWLock *p_m_lock; // edi
  signed __int32 m_i32; // ecx
  int nLevel; // [esp+8h] [ebp-8h]
  bool bWasReading; // [esp+Fh] [ebp-1h]

  v3 = &this->m_pOwner->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * hPartition];
  nLevel = (char)v3[this->m_TreeId + 39];
  if ( nLevel >= 0 )
  {
    v4 = GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index);
    bWasReading = this->m_pVisits[(_DWORD)v4] != nullptr;
    if ( this->m_pVisits[(_DWORD)v4] != nullptr )
      _InterlockedExchangeAdd((volatile signed __int32 *)&this->m_lock, 0xFFFFFFFF);
    p_m_lock = &this->m_lock;
    if ( (this->m_lock.m_lockInfo.m_i32 & 0x10000) != 0
      || _InterlockedCompareExchange((volatile signed __int32 *)p_m_lock, 0x10000, 0) != 0 )
    {
      CThreadSpinRWLock::SpinLockForWrite(this: &this->m_lock);
    }
    else
    {
      this->m_lock.m_writerId = GetCurrentThreadId();
    }
    CVoxelHash::RemoveFromTree(this: &this->m_pVoxelHash[nLevel], hPartition);
    CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertBefore(
      this: &this->m_AvailableVisitBits,
      elem: this->m_AvailableVisitBits.m_Size,
      src: (const unsigned __int16 *)&v3[2 * this->m_TreeId + 42]);
    *(_WORD *)&v3[2 * this->m_TreeId + 42] = -1;
    this->m_lock.m_writerId = 0;
    p_m_lock->m_lockInfo.m_i32 = 0;
    if ( bWasReading )
    {
      if ( (p_m_lock->m_lockInfo.m_i32 & 0x10000) != 0
        || (m_i32 = (unsigned __int16)p_m_lock->m_lockInfo.m_i32,
            _InterlockedCompareExchange((volatile signed __int32 *)p_m_lock, m_i32 + 1, m_i32) != m_i32) )
      {
        CThreadSpinRWLock::SpinLockForRead(this: p_m_lock);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DDDA0
// Name: public: virtual void CSpatialPartition::RemoveFromTree(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::RemoveFromTree(CSpatialPartition *this, unsigned __int16 hPartition)
{
  unsigned __int8 *v3; // esi

  v3 = &this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * hPartition];
  if ( (v3[38] & 2) != 0 )
  {
    CVoxelTree::RemoveFromTree(this: this->m_VoxelTrees, hPartition);
    v3[38] &= ~2u;
  }
  if ( (v3[38] & 4) != 0 )
  {
    CVoxelTree::RemoveFromTree(this: &this->m_VoxelTrees[1], hPartition);
    v3[38] &= ~4u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DDEB0
// Name: public: void CVoxelTree::InsertIntoTree(unsigned short,class Vector const __near &,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelTree::InsertIntoTree(
        CVoxelTree *this,
        unsigned __int16 hPartition,
        const Vector *mins,
        const Vector *maxs,
        bool bReinsert)
{
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm5_4
  float v10; // xmm6_4
  float v11; // xmm4_4
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm7_4
  float v15; // xmm0_4
  float v16; // xmm3_4
  int v17; // eax
  float v18; // xmm0_4
  float *p_m_flVoxelSize; // ecx
  float v20; // xmm5_4
  CVoxelHash *v21; // eax
  unsigned int m_nLevelShift; // ecx
  int v23; // edi
  int v24; // ebx
  float *p_x; // eax
  void *v26; // eax
  CThreadSpinRWLock *p_m_lock; // ecx
  int m_TreeId; // ecx
  signed __int32 m_i32; // edx
  float vecMax; // [esp+0h] [ebp-24h]
  float vecMin; // [esp+Ch] [ebp-18h]
  int v32; // [esp+18h] [ebp-Ch]
  EntityInfo_t *info; // [esp+20h] [ebp-4h]
  CThreadSpinRWLock *bDoInsert; // [esp+30h] [ebp+Ch]
  char bDoInsert_3; // [esp+33h] [ebp+Fh]
  bool bWasReading; // [esp+3Bh] [ebp+17h]

  v6 = mins->x - 0.03125;
  v7 = mins->y - 0.03125;
  v8 = mins->z - 0.03125;
  v9 = maxs->x + 0.03125;
  v10 = maxs->y + 0.03125;
  v11 = maxs->z + 0.03125;
  x = s_PartitionMin.x;
  info = (EntityInfo_t *)&this->m_pOwner->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * hPartition];
  if ( s_PartitionMin.x <= v6 )
  {
    if ( v6 > s_PartitionMax.x )
      v6 = s_PartitionMax.x;
  }
  else
  {
    v6 = s_PartitionMin.x;
  }
  vecMin = v6;
  y = s_PartitionMin.y;
  if ( s_PartitionMin.y > v7 || (y = s_PartitionMax.y, v7 > s_PartitionMax.y) )
    v7 = y;
  if ( s_PartitionMin.z <= v8 )
  {
    z = s_PartitionMax.z;
    if ( v8 <= s_PartitionMax.z )
      z = mins->z - 0.03125;
  }
  else
  {
    z = s_PartitionMin.z;
  }
  if ( s_PartitionMin.x > v9 || (x = s_PartitionMax.x, v9 > s_PartitionMax.x) )
    v9 = x;
  v15 = s_PartitionMin.y;
  v16 = v9;
  vecMax = v9;
  if ( s_PartitionMin.y > v10 || (v15 = s_PartitionMax.y, v10 > s_PartitionMax.y) )
    v10 = v15;
  if ( s_PartitionMin.z <= v11 )
  {
    if ( v11 > s_PartitionMax.z )
      v11 = s_PartitionMax.z;
  }
  else
  {
    v11 = s_PartitionMin.z;
  }
  v17 = 0;
  v18 = v9 - vecMin;
  if ( this->m_nLevelCount - 1 > 0 )
  {
    p_m_flVoxelSize = &this->m_pVoxelHash->m_flVoxelSize;
    do
    {
      v20 = *p_m_flVoxelSize;
      if ( *p_m_flVoxelSize > v18 && v20 > (float)(v10 - v7) && v20 > (float)(v11 - z) )
        break;
      ++v17;
      p_m_flVoxelSize += 1046;
    }
    while ( v17 < this->m_nLevelCount - 1 );
  }
  v32 = v17;
  v21 = &this->m_pVoxelHash[v17];
  m_nLevelShift = v21->m_nLevelShift;
  bDoInsert_3 = 1;
  v23 = ((int)(float)(vecMin - v21->m_vecVoxelOrigin.x) >> m_nLevelShift) & 0x7FF
      | ((((int)(float)(z - v21->m_vecVoxelOrigin.z) >> m_nLevelShift << 11)
        | ((int)(float)(v7 - v21->m_vecVoxelOrigin.y) >> m_nLevelShift) & 0x7FF) << 11);
  v24 = ((int)(float)(v16 - v21->m_vecVoxelOrigin.x) >> m_nLevelShift) & 0x7FF
      | ((((int)(float)(v10 - v21->m_vecVoxelOrigin.y) >> m_nLevelShift) & 0x7FF
        | ((int)(float)(v11 - v21->m_vecVoxelOrigin.z) >> m_nLevelShift << 11)) << 11);
  p_x = &info->m_vecMin.x;
  if ( bReinsert )
  {
    if ( info->m_voxelMin.uiVoxel == v23 && info->m_voxelMax.uiVoxel == v24 )
    {
      bDoInsert_3 = 0;
    }
    else
    {
      CVoxelTree::RemoveFromTree(this, hPartition);
      v16 = vecMax;
      p_x = &info->m_vecMin.x;
    }
  }
  *p_x = vecMin;
  p_x[1] = v7;
  p_x[2] = z;
  p_x[4] = v16;
  p_x[5] = v10;
  p_x[6] = v11;
  if ( bDoInsert_3 != 0 )
  {
    v26 = GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index);
    bWasReading = this->m_pVisits[(_DWORD)v26] != nullptr;
    if ( this->m_pVisits[(_DWORD)v26] != nullptr )
      _InterlockedExchangeAdd((volatile signed __int32 *)&this->m_lock, 0xFFFFFFFF);
    p_m_lock = &this->m_lock;
    bDoInsert = &this->m_lock;
    if ( (this->m_lock.m_lockInfo.m_i32 & 0x10000) != 0
      || _InterlockedCompareExchange((volatile signed __int32 *)p_m_lock, 0x10000, 0) != 0 )
    {
      CThreadSpinRWLock::SpinLockForWrite(this: p_m_lock);
    }
    else
    {
      this->m_lock.m_writerId = GetCurrentThreadId();
    }
    info->m_voxelMin.uiVoxel = v23;
    info->m_voxelMax.uiVoxel = v24;
    m_TreeId = this->m_TreeId;
    if ( this->m_AvailableVisitBits.m_Size != 0 )
      info->m_nVisitBit[m_TreeId] = this->m_AvailableVisitBits.m_Memory.m_pMemory[--this->m_AvailableVisitBits.m_Size];
    else
      info->m_nVisitBit[m_TreeId] = this->m_nNextVisitBit++;
    CVoxelHash::InsertIntoTree(
      this: &this->m_pVoxelHash[v32],
      hPartition,
      voxelMin: (Voxel_t)v23,
      voxelMax: (Voxel_t)v24);
    this->m_lock.m_writerId = 0;
    bDoInsert->m_lockInfo.m_i32 = 0;
    if ( bWasReading )
    {
      if ( (bDoInsert->m_lockInfo.m_i32 & 0x10000) != 0
        || (m_i32 = (unsigned __int16)bDoInsert->m_lockInfo.m_i32,
            _InterlockedCompareExchange((volatile signed __int32 *)bDoInsert, m_i32 + 1, m_i32) != m_i32) )
      {
        CThreadSpinRWLock::SpinLockForRead(this: bDoInsert);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DE270
// Name: public: virtual void CVoxelTree::ElementMoved(unsigned short,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelTree::ElementMoved(
        CVoxelTree *this,
        unsigned __int16 hPartition,
        const Vector *mins,
        const Vector *maxs)
{
  if ( hPartition != 0xFFFF )
  {
    if ( *(_DWORD *)&this->m_pOwner->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * hPartition + 48 + 4 * this->m_TreeId] != 0 )
      CVoxelTree::InsertIntoTree(this, hPartition, mins, maxs, bReinsert: true);
    else
      CVoxelTree::InsertIntoTree(this, hPartition, mins, maxs, bReinsert: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DE2D0
// Name: public: CSpatialPartition::CSpatialPartition(void)
// Source: json
//------------------------------------------------------------------------------
CSpatialPartition *__thiscall CSpatialPartition::CSpatialPartition(CSpatialPartition *this)
{
  unsigned __int8 *m_pBase; // eax
  CVoxelTree *m_VoxelTrees; // ebx
  int i; // [esp+Ch] [ebp-4h]

  this->__vftable = (CSpatialPartition_vtbl *)&CSpatialPartition::`vftable';
  CMemoryStack::CMemoryStack(this: &this->m_aHandles.m_Memory.m_MemoryStack);
  CMemoryStack::Init(
    this: &this->m_aHandles.m_Memory.m_MemoryStack,
    pszAllocOwner: "CUtlMemoryStack",
    maxSize: 0x3BFFC4u,
    commitSize: 0xF000u,
    initialCommit: 0,
    alignment: 4u);
  this->m_aHandles.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_aHandles.m_FirstFree = 0xFFFF;
  m_pBase = this->m_aHandles.m_Memory.m_MemoryStack.m_pBase;
  *(_DWORD *)&this->m_aHandles.m_Head = -1;
  this->m_aHandles.m_NumAlloced = 0;
  this->m_aHandles.m_pElements = (UtlLinkedListElem_t<EntityInfo_t,unsigned short> *)m_pBase;
  this->m_HandlesMutex.m_ownerID = 0;
  this->m_HandlesMutex.m_depth = 0;
  m_VoxelTrees = this->m_VoxelTrees;
  for ( i = 1; i >= 0; --i )
    CVoxelTree::CVoxelTree(this: m_VoxelTrees++);
  this->m_nQueryCallbackCount = 0;
  CMemoryStack::SetAllocOwner(
    this: &this->m_aHandles.m_Memory.m_MemoryStack,
    pszAllocOwner: "CSpatialPartition::m_aHandles");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101DE370
// Name: public: virtual void CSpatialPartition::Init(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::Init(CSpatialPartition *this, const Vector *worldmin, const Vector *worldmax)
{
  unsigned __int8 *m_pBase; // eax
  int v5; // esi
  CVoxelTree *m_VoxelTrees; // edi

  CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::RemoveAll(this: &this->m_aHandles);
  CMemoryStack::FreeAll(this: &this->m_aHandles.m_Memory.m_MemoryStack, bDecommit: true);
  this->m_aHandles.m_FirstFree = -1;
  m_pBase = this->m_aHandles.m_Memory.m_MemoryStack.m_pBase;
  this->m_aHandles.m_Memory.m_nAllocated = 0;
  *(_DWORD *)&this->m_aHandles.m_NumAlloced = -65536;
  this->m_aHandles.m_pElements = (UtlLinkedListElem_t<EntityInfo_t,unsigned short> *)m_pBase;
  CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::EnsureCapacity(
    this: &this->m_aHandles,
    num: 256);
  v5 = 0;
  m_VoxelTrees = this->m_VoxelTrees;
  do
  {
    m_VoxelTrees->Init(this: m_VoxelTrees, a2: this, a3: v5++, a4: worldmin, a5: worldmax);
    ++m_VoxelTrees;
  }
  while ( v5 < 2 );
}

//------------------------------------------------------------------------------
// Address: 0x101DE3F0
// Name: public: void CSpatialPartition::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::Shutdown(CSpatialPartition *this)
{
  CVoxelTree *m_VoxelTrees; // esi
  int i; // edi
  unsigned __int8 *m_pBase; // eax

  m_VoxelTrees = this->m_VoxelTrees;
  for ( i = 2; i != 0; --i )
    CVoxelTree::Shutdown(this: m_VoxelTrees++);
  CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::RemoveAll(this: &this->m_aHandles);
  CMemoryStack::FreeAll(this: &this->m_aHandles.m_Memory.m_MemoryStack, bDecommit: true);
  this->m_aHandles.m_Memory.m_nAllocated = 0;
  this->m_aHandles.m_FirstFree = -1;
  m_pBase = this->m_aHandles.m_Memory.m_MemoryStack.m_pBase;
  *(_DWORD *)&this->m_aHandles.m_NumAlloced = -65536;
  this->m_aHandles.m_pElements = (UtlLinkedListElem_t<EntityInfo_t,unsigned short> *)m_pBase;
}

//------------------------------------------------------------------------------
// Address: 0x101DE440
// Name: public: virtual void CSpatialPartition::InsertIntoTree(unsigned short,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::InsertIntoTree(
        CSpatialPartition *this,
        unsigned __int16 hPartition,
        const Vector *mins,
        const Vector *maxs)
{
  unsigned __int8 *m_pBase; // edx
  int v7; // eax
  unsigned __int8 *v8; // esi
  int listMask; // [esp+14h] [ebp+8h]

  m_pBase = this->m_aHandles.m_Memory.m_MemoryStack.m_pBase;
  v7 = *(unsigned __int16 *)&m_pBase[60 * hPartition + 36];
  v8 = &m_pBase[60 * hPartition];
  listMask = v7;
  if ( (v7 & 0x1AC) != 0 && (v8[38] & 2) == 0 )
  {
    CVoxelTree::InsertIntoTree(this: this->m_VoxelTrees, hPartition, mins, maxs, bReinsert: false);
    v8[38] |= 2u;
    v7 = listMask;
  }
  if ( (v7 & 0xFFFFFE53) != 0 && (v8[38] & 4) == 0 )
  {
    CVoxelTree::InsertIntoTree(this: &this->m_VoxelTrees[1], hPartition, mins, maxs, bReinsert: false);
    v8[38] |= 4u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DE4C0
// Name: class ISpatialPartition __near * CreateSpatialPartition(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
CSpatialPartition *__cdecl CreateSpatialPartition(const Vector *worldmin, const Vector *worldmax)
{
  CSpatialPartition *v2; // eax
  CSpatialPartition *v3; // esi

  v2 = (CSpatialPartition *)MemAlloc_Alloc(nSize: 0x240u);
  if ( v2 != nullptr )
    v3 = CSpatialPartition::CSpatialPartition(this: v2);
  else
    v3 = nullptr;
  v3->Init(this: v3, a2: worldmin, a3: worldmax);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101DE500
// Name: public: CSpatialPartition::~CSpatialPartition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::~CSpatialPartition(CSpatialPartition *this)
{
  IPartitionQueryCallback **m_pQueryCallback; // eax
  CTSPool<CVarBitVec> *v3; // esi
  CVoxelHash *DepthAndSequence; // ecx
  void *v5; // eax
  const CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::Iterator_t *v6; // ecx
  TSLNodeBase_t **v7; // eax
  TSLNodeBase_t *v8; // edi
  int i; // ebx
  TSLNodeBase_t *v10; // edi
  CSpatialPartition *v11; // esi
  CTSPool<CVarBitVec> *v12; // eax
  TSLNodeBase_t *Next; // eax
  int v14; // eax
  TSLNodeBase_t *v15; // [esp-4h] [ebp-44h]
  _DWORD v16[2]; // [esp+1Ch] [ebp-24h] BYREF
  _DWORD v17[2]; // [esp+24h] [ebp-1Ch] BYREF
  CSpatialPartition *v18; // [esp+2Ch] [ebp-14h]
  const CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::Iterator_t *v19; // [esp+30h] [ebp-10h]
  IPartitionQueryCallback **v20; // [esp+34h] [ebp-Ch]
  int v21; // [esp+38h] [ebp-8h]
  CTSPool<CVarBitVec> *v22; // [esp+3Ch] [ebp-4h]

  v18 = this;
  this->__vftable = (CSpatialPartition_vtbl *)&CSpatialPartition::`vftable';
  CSpatialPartition::Shutdown(this);
  m_pQueryCallback = this->m_pQueryCallback;
  v21 = 1;
  v3 = (CTSPool<CVarBitVec> *)((char *)this + 760);
  while ( 1 )
  {
    DepthAndSequence = (CVoxelHash *)v3[-55].m_Head.value32.DepthAndSequence;
    v3 -= 30;
    v20 = m_pQueryCallback - 60;
    v22 = v3;
    *(m_pQueryCallback - 60) = (IPartitionQueryCallback *)&CVoxelTree::`vftable';
    if ( DepthAndSequence != nullptr )
      CVoxelHash::`vector deleting destructor'(this: DepthAndSequence, a2: 3u);
    CTSPool<CVarBitVec>::~CTSPool<CVarBitVec>(this: v3 + 2);
    v3->m_Head.value.Next = nullptr;
    if ( v3[-1].m_Head.value32.DepthAndSequence >= 0 )
    {
      if ( v3[-2].m_Head.value32.DepthAndSequence != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v3[-2].m_Head.value32.DepthAndSequence);
        v3[-2].m_Head.value32.DepthAndSequence = 0;
      }
      v3[-1].m_Head.value.Next = nullptr;
    }
    v5 = (void *)v3[-2].m_Head.value32.DepthAndSequence;
    v3->m_Head.value32.DepthAndSequence = (int)v5;
    if ( v3[-1].m_Head.value32.DepthAndSequence >= 0 )
    {
      if ( v5 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
        v3[-2].m_Head.value32.DepthAndSequence = 0;
      }
      v3[-1].m_Head.value.Next = nullptr;
    }
    v6 = (const CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::Iterator_t *)&v3[-20];
    if ( v3[-20].m_Head.value.Next != nullptr || v3[-20].m_Head.value32.DepthAndSequence != -1 )
    {
      if ( v3[-24].m_Head.value.Next != nullptr )
      {
        v17[0] = v3[-24].m_Head.value.Next;
        v17[1] = 0;
        v7 = (TSLNodeBase_t **)v17;
      }
      else
      {
        v16[0] = 0;
        v16[1] = -1;
        v7 = (TSLNodeBase_t **)v16;
      }
      v8 = *v7;
      for ( i = (int)v7[1]; ; i = 0 )
      {
        while ( 1 )
        {
          while ( 1 )
          {
            if ( v8 != nullptr )
            {
              if ( i >= 0 && i < *((_DWORD *)&v8->Next + 1) )
              {
                if ( &v8[2 * i] != (TSLNodeBase_t *)-8
                  && !CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::IsIdxAfter(
                        this: (CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> > *)&v22[-24],
                        i: (int)&v8[2 * i + 1],
                        it: v6)
                  && (v8[2 * i + 2].Next != &v8[2 * i + 1] || *(&v8[2 * i + 2].Next + 1) == &v8[2 * i + 1]) )
                {
                  v12 = v22;
                  v8[2 * i + 2].Next = &v8[2 * i + 1];
                  *((_DWORD *)&v8[2 * i + 2].Next + 1) = v12[-22].m_Head.value32.DepthAndSequence;
                  v12[-22].m_Head.value32.DepthAndSequence = (int)&v8[2 * i + 1];
                }
                v3 = v22;
              }
            }
            else if ( i == -1 )
            {
              goto LABEL_21;
            }
            Next = v3[-20].m_Head.value.Next;
            v19 = (const CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::Iterator_t *)&v3[-20];
            if ( v8 == Next && i == v3[-20].m_Head.value32.DepthAndSequence )
            {
LABEL_21:
              v3[-23].m_Head.value32.DepthAndSequence = 0;
              v3[-22].m_Head.value.Next = nullptr;
              v3[-21].m_Head.value.Next = nullptr;
              goto LABEL_22;
            }
            if ( v8 != nullptr && i >= 0 )
            {
              v14 = *((_DWORD *)&v8->Next + 1);
              if ( i < v14 )
                break;
            }
            v6 = v19;
            v8 = nullptr;
            i = -1;
          }
          if ( ++i >= v14 )
            break;
LABEL_45:
          v6 = v19;
        }
        v8 = v8->Next;
        if ( v8 == nullptr )
        {
          v8 = nullptr;
          i = -1;
          goto LABEL_45;
        }
        v6 = v19;
      }
    }
LABEL_22:
    v10 = v3[-24].m_Head.value.Next;
    if ( v10 != nullptr )
    {
      do
      {
        v15 = v10;
        v10 = v10->Next;
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
      }
      while ( v10 != nullptr );
      v3[-24].m_Head.value.Next = nullptr;
      v3[-24].m_Head.value32.DepthAndSequence = 0;
    }
    if ( --v21 < 0 )
      break;
    m_pQueryCallback = v20;
  }
  v11 = v18;
  CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::RemoveAll(this: &v18->m_aHandles);
  CMemoryStack::~CMemoryStack(this: &v11->m_aHandles.m_Memory.m_MemoryStack);
}

//------------------------------------------------------------------------------
// Address: 0x101DE730
// Name: public: virtual void CSpatialPartition::DestroyHandle(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::DestroyHandle(CSpatialPartition *this, int hPartition)
{
  CThreadFastMutex *p_m_HandlesMutex; // esi
  DWORD CurrentThreadId; // eax

  if ( (_WORD)hPartition != 0xFFFF )
  {
    this->RemoveFromTree(this, a2: hPartition);
    p_m_HandlesMutex = &this->m_HandlesMutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_HandlesMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_HandlesMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_HandlesMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_HandlesMutex.m_depth;
    }
    CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::Unlink(
      this: &this->m_aHandles,
      elem: hPartition);
    *(_WORD *)&this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * (unsigned __int16)hPartition + 58] = this->m_aHandles.m_FirstFree;
    this->m_aHandles.m_FirstFree = hPartition;
    if ( this->m_HandlesMutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_HandlesMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DE7C0
// Name: public: virtual unsigned short CSpatialPartition::CreateHandle(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CSpatialPartition::CreateHandle(CSpatialPartition *this, IHandleEntity *pHandleEntity)
{
  CThreadFastMutex *p_m_HandlesMutex; // ebx
  DWORD CurrentThreadId; // ecx
  unsigned __int16 v5; // di
  unsigned __int16 v6; // ax
  bool v7; // zf
  int v8; // edi
  int v9; // ecx
  unsigned __int8 *v10; // edx
  int v11; // eax
  int v12; // edx
  unsigned __int16 v14; // [esp+10h] [ebp-4h]

  p_m_HandlesMutex = &this->m_HandlesMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_HandlesMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_HandlesMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_HandlesMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_HandlesMutex->m_depth;
  }
  v5 = CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::AllocInternal(
         this: &this->m_aHandles,
         multilist: false);
  v6 = -1;
  if ( v5 != 0xFFFF )
  {
    CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::LinkBefore(
      this: &this->m_aHandles,
      before: 0xFFFFu,
      elem: v5);
    v6 = v5;
  }
  v7 = p_m_HandlesMutex->m_depth-- == 1;
  v14 = v6;
  if ( v7 )
    _InterlockedExchange((volatile __int32 *)p_m_HandlesMutex, 0);
  v8 = v6;
  v9 = 60 * v6;
  *(_DWORD *)&this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[v9 + 32] = pHandleEntity;
  v10 = &this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[v9];
  *(_DWORD *)v10 = 2139095039;
  *((_DWORD *)v10 + 1) = 2139095039;
  *((_DWORD *)v10 + 2) = 2139095039;
  *((_DWORD *)v10 + 4) = 0x800000;
  *((_DWORD *)v10 + 5) = 0x800000;
  *((_DWORD *)v10 + 6) = 0x800000;
  *((_WORD *)v10 + 18) = 0;
  this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[v9 + 38] = 0;
  v11 = 30 * v6;
  *(_WORD *)&this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[2 * v11 + 42] = -1;
  this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[v9 + 39] = -1;
  v12 = 15 * v8;
  *(_DWORD *)&this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[4 * v12 + 48] = 0;
  *(_WORD *)&this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[2 * v11 + 44] = -1;
  this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[v9 + 40] = -1;
  *(_DWORD *)&this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[4 * v12 + 52] = 0;
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x10276A30
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct CCommandBuffer::Command_t,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *this,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *v4; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *m_pBlocks; // eax

  if ( num > 0 )
  {
    m_nGrowSize = this->m_nGrowSize;
    if ( m_nGrowSize == 0 )
    {
      m_nGrowSize = this->m_nAllocationCount;
      if ( m_nGrowSize == 0 )
        m_nGrowSize = 2;
    }
    if ( m_nGrowSize < num )
      m_nGrowSize *= (m_nGrowSize + num - 1) / m_nGrowSize;
    this->m_nAllocationCount += m_nGrowSize;
    v4 = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)_g_pMemAlloc->Alloc_2(
                                                                                                  this: _g_pMemAlloc,
                                                                                                  a2: 20 * m_nGrowSize + 8);
    if ( v4 == nullptr )
      _Error(a1: "CUtlFixedMemory overflow!\n");
    m_pBlocks = this->m_pBlocks;
    v4->m_pNext = nullptr;
    v4->m_nBlockSize = m_nGrowSize;
    if ( m_pBlocks != nullptr )
    {
      for ( ; m_pBlocks->m_pNext != nullptr; m_pBlocks = m_pBlocks->m_pNext )
        ;
      m_pBlocks->m_pNext = v4;
    }
    else
    {
      this->m_pBlocks = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10276B10
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<struct CCommandBuffer::Command_t,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CCommandBuffer::Command_t,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1] && i < (unsigned int)&m_pBlockHeader[1] + 20 * m_pBlockHeader->m_nBlockSize )
    return (int)i > (int)&m_pBlockHeader[1] + 20 * m_nIndex;
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[1] + 20 * m_pNext->m_nBlockSize )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10075AD0
// Name: void DestroySpatialPartition(class ISpatialPartition __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DestroySpatialPartition(void *pMem)
{
  free(pMem);
}

//------------------------------------------------------------------------------
// Address: 0x1008CDB0
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<class CEventInfo,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<class CEventInfo,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // edx
  CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1] && i < (unsigned int)&m_pBlockHeader[8 * m_pBlockHeader->m_nBlockSize + 1] )
    return (int)i > (int)&m_pBlockHeader[8 * m_nIndex + 1];
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[8 * m_pNext->m_nBlockSize + 1] )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1009CA00
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<class CEventInfo,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> > *this,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *v4; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *m_pBlocks; // eax

  if ( num > 0 )
  {
    m_nGrowSize = this->m_nGrowSize;
    if ( m_nGrowSize == 0 )
    {
      m_nGrowSize = this->m_nAllocationCount;
      if ( m_nGrowSize == 0 )
        m_nGrowSize = 1;
    }
    if ( m_nGrowSize < num )
      m_nGrowSize *= (m_nGrowSize + num - 1) / m_nGrowSize;
    this->m_nAllocationCount += m_nGrowSize;
    v4 = (CUtlFixedMemory<UtlLinkedListElem_t<CEventInfo,int> >::BlockHeader_t *)_g_pMemAlloc->Alloc_2(
                                                                                   this: _g_pMemAlloc,
                                                                                   a2: (m_nGrowSize << 6) + 8);
    if ( v4 == nullptr )
      _Error(a1: "CUtlFixedMemory overflow!\n");
    m_pBlocks = this->m_pBlocks;
    v4->m_pNext = nullptr;
    v4->m_nBlockSize = m_nGrowSize;
    if ( m_pBlocks != nullptr )
    {
      for ( ; m_pBlocks->m_pNext != nullptr; m_pBlocks = m_pBlocks->m_pNext )
        ;
      m_pBlocks->m_pNext = v4;
    }
    else
    {
      this->m_pBlocks = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BD630
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<unsigned short,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<unsigned short,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1] && i < (unsigned int)&m_pBlockHeader[1] + 12 * m_pBlockHeader->m_nBlockSize )
    return (int)i > (int)&m_pBlockHeader[1] + 12 * m_nIndex;
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[1] + 12 * m_pNext->m_nBlockSize )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x100BDD80
// Name: public: class CUtlFixedMemory<struct UtlLinkedListElem_t<struct LeafListData_t,int>>::Iterator_t CUtlFixedMemory<struct UtlLinkedListElem_t<struct LeafListData_t,int>>::Next(class CUtlFixedMemory<struct UtlLinkedListElem_t<struct LeafListData_t,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *__thiscall CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Next(
        CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *this,
        CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *result,
        const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *m_pBlockHeader; // ecx
  int m_nIndex; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *m_pNext; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t v7; // [esp+0h] [ebp-8h]

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader != nullptr && (m_nIndex = it->m_nIndex) >= 0 && m_nIndex < m_pBlockHeader->m_nBlockSize )
  {
    if ( m_nIndex + 1 >= m_pBlockHeader->m_nBlockSize )
    {
      m_pNext = m_pBlockHeader->m_pNext;
      if ( m_pNext != nullptr )
      {
        v7 = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t)(unsigned int)m_pNext;
      }
      else
      {
        v7.m_pBlockHeader = nullptr;
        v7.m_nIndex = -1;
      }
      *result = v7;
      return result;
    }
    else
    {
      result->m_pBlockHeader = m_pBlockHeader;
      result->m_nIndex = m_nIndex + 1;
      return result;
    }
  }
  else
  {
    result->m_pBlockHeader = nullptr;
    result->m_nIndex = -1;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10150C40
// Name: public: CTSPool<struct TraceInfo_t>::~CTSPool<struct TraceInfo_t>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSPool<TraceInfo_t>::~CTSPool<TraceInfo_t>(CTSPool<TraceInfo_t> *this)
{
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax

  while ( 1 )
  {
    Next = this->m_Head.value.Next;
    DepthAndSequence = this->m_Head.value32.DepthAndSequence;
    if ( this->m_Head.value.Next == nullptr )
      break;
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: this,
                               a2: Next->Next,
                               a3: DepthAndSequence - 1,
                               a4: Next,
                               a5: DepthAndSequence) == 0 )
    {
      _mm_pause();
      Next = this->m_Head.value.Next;
      DepthAndSequence = this->m_Head.value32.DepthAndSequence;
      if ( this->m_Head.value.Next == nullptr )
        goto LABEL_4;
    }
    TraceInfo_t::~TraceInfo_t(this: (TraceInfo_t *)(&Next->Next + 1));
    free(pMem: Next);
  }
LABEL_4:
  CTSListBase::Detach(this);
}

//------------------------------------------------------------------------------
// Address: 0x101B5140
// Name: public: CTSPool<struct net_scratchbuffer_t>::~CTSPool<struct net_scratchbuffer_t>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSPool<net_scratchbuffer_t>::~CTSPool<net_scratchbuffer_t>(CTSPool<net_scratchbuffer_t> *this)
{
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax

  while ( 1 )
  {
    Next = this->m_Head.value.Next;
    DepthAndSequence = this->m_Head.value32.DepthAndSequence;
    if ( this->m_Head.value.Next == nullptr )
      break;
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: this,
                               a2: Next->Next,
                               a3: DepthAndSequence - 1,
                               a4: Next,
                               a5: DepthAndSequence) == 0 )
    {
      _mm_pause();
      Next = this->m_Head.value.Next;
      DepthAndSequence = this->m_Head.value32.DepthAndSequence;
      if ( this->m_Head.value.Next == nullptr )
        goto LABEL_4;
    }
    free(pMem: Next);
  }
LABEL_4:
  CTSListBase::Detach(this);
}

//------------------------------------------------------------------------------
// Address: 0x101D8590
// Name: void ClampStartPoint(struct Ray_t __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClampStartPoint(Ray_t *ray, const Vector *vecEnd)
{
  long double x; // st7
  float v4; // xmm1_4
  float v5; // xmm4_4
  float v6; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  float v9; // xmm0_4
  float raya; // [esp+8h] [ebp+8h]
  float rayb; // [esp+8h] [ebp+8h]
  float rayc; // [esp+8h] [ebp+8h]

  x = ray->m_Delta.x;
  raya = ray->m_Delta.x;
  if ( fabs(x) >= 1.0e-10 )
  {
    if ( raya <= 0.0 )
    {
      if ( ray->m_Start.x <= 16384.0 )
        goto LABEL_8;
      v4 = (float)(ray->m_Start.x - 16379.0) * (float)(-1.0 / ray->m_Delta.x);
    }
    else
    {
      if ( ray->m_Start.x >= -16384.0 )
        goto LABEL_8;
      v4 = (float)(-16379.0 - ray->m_Start.x) / raya;
    }
    ray->m_Start.x = (float)(raya * v4) + ray->m_Start.x;
    ray->m_Start.y = (float)(ray->m_Delta.y * v4) + ray->m_Start.y;
    ray->m_Start.z = (float)(ray->m_Delta.z * v4) + ray->m_Start.z;
  }
LABEL_8:
  if ( fabs(ray->m_Delta.y) < 1.0e-10 )
    goto LABEL_15;
  rayb = ray->m_Delta.y;
  if ( rayb <= 0.0 )
  {
    y = ray->m_Start.y;
    if ( y <= 16384.0 )
      goto LABEL_15;
    v6 = (float)(y - 16379.0) * (float)(-1.0 / rayb);
  }
  else
  {
    v5 = ray->m_Start.y;
    if ( v5 >= -16384.0 )
      goto LABEL_15;
    v6 = (float)(-16379.0 - v5) / rayb;
  }
  ray->m_Start.x = (float)(v6 * ray->m_Delta.x) + ray->m_Start.x;
  ray->m_Start.y = (float)(ray->m_Delta.y * v6) + ray->m_Start.y;
  ray->m_Start.z = (float)(ray->m_Delta.z * v6) + ray->m_Start.z;
LABEL_15:
  if ( fabs(ray->m_Delta.z) >= 1.0e-10 )
  {
    z = ray->m_Start.z;
    rayc = ray->m_Delta.z;
    if ( rayc <= 0.0 )
    {
      if ( z > 16384.0 )
      {
        v9 = (float)(z - 16379.0) * (float)(-1.0 / rayc);
        goto LABEL_21;
      }
    }
    else if ( z < -16384.0 )
    {
      v9 = (float)(-16379.0 - z) / rayc;
LABEL_21:
      ray->m_Start.x = (float)(v9 * ray->m_Delta.x) + ray->m_Start.x;
      ray->m_Start.y = (float)(ray->m_Delta.y * v9) + ray->m_Start.y;
      ray->m_Start.z = (float)(ray->m_Delta.z * v9) + ray->m_Start.z;
    }
  }
  ray->m_Delta.x = vecEnd->x - ray->m_Start.x;
  ray->m_Delta.y = vecEnd->y - ray->m_Start.y;
  ray->m_Delta.z = vecEnd->z - ray->m_Start.z;
}

//------------------------------------------------------------------------------
// Address: 0x101D8770
// Name: void ClampEndPoint(struct Ray_t __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClampEndPoint(Ray_t *ray, Vector *vecEnd)
{
  long double x; // st7
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float raya; // [esp+8h] [ebp+8h]
  float rayb; // [esp+8h] [ebp+8h]
  float rayc; // [esp+8h] [ebp+8h]

  x = ray->m_Delta.x;
  raya = ray->m_Delta.x;
  if ( fabs(x) >= 1.0e-10 )
  {
    if ( raya >= 0.0 )
    {
      if ( vecEnd->x <= 16384.0 )
        goto LABEL_8;
      v4 = (float)(ray->m_Start.x - -16379.0) / ray->m_Delta.x;
    }
    else
    {
      if ( vecEnd->x >= -16384.0 )
        goto LABEL_8;
      v4 = (float)(ray->m_Start.x - -16379.0) * (float)(-1.0 / raya);
    }
    vecEnd->x = (float)(raya * v4) + ray->m_Start.x;
    vecEnd->y = (float)(ray->m_Delta.y * v4) + ray->m_Start.y;
    vecEnd->z = (float)(ray->m_Delta.z * v4) + ray->m_Start.z;
  }
LABEL_8:
  rayb = ray->m_Delta.y;
  if ( fabs(rayb) >= 1.0e-10 )
  {
    if ( rayb >= 0.0 )
    {
      if ( vecEnd->y <= 16384.0 )
        goto LABEL_15;
      v5 = (float)(ray->m_Start.y - -16379.0) / rayb;
    }
    else
    {
      if ( vecEnd->y >= -16384.0 )
        goto LABEL_15;
      v5 = (float)(ray->m_Start.y - -16379.0) * (float)(-1.0 / rayb);
    }
    vecEnd->x = (float)(ray->m_Delta.x * v5) + ray->m_Start.x;
    vecEnd->y = (float)(ray->m_Delta.y * v5) + ray->m_Start.y;
    vecEnd->z = (float)(ray->m_Delta.z * v5) + ray->m_Start.z;
  }
LABEL_15:
  rayc = ray->m_Delta.z;
  if ( fabs(rayc) >= 1.0e-10 )
  {
    if ( rayc >= 0.0 )
    {
      if ( vecEnd->z > 16384.0 )
      {
        v6 = (float)(ray->m_Start.z - -16379.0) / rayc;
        goto LABEL_21;
      }
    }
    else if ( vecEnd->z < -16384.0 )
    {
      v6 = (float)(ray->m_Start.z - -16379.0) * (float)(-1.0 / rayc);
LABEL_21:
      vecEnd->x = (float)(ray->m_Delta.x * v6) + ray->m_Start.x;
      vecEnd->y = (float)(ray->m_Delta.y * v6) + ray->m_Start.y;
      vecEnd->z = (float)(ray->m_Delta.z * v6) + ray->m_Start.z;
    }
  }
  ray->m_Delta.x = vecEnd->x - ray->m_Start.x;
  ray->m_Delta.y = vecEnd->y - ray->m_Start.y;
  ray->m_Delta.z = vecEnd->z - ray->m_Start.z;
}

//------------------------------------------------------------------------------
// Address: 0x101D8960
// Name: public: bool CIntersectSweptBox::Intersects(float const __near *,float const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CIntersectSweptBox::Intersects@<al>(
        CIntersectSweptBox *this@<ecx>,
        int a2@<ebp>,
        __m128 *pMins,
        __m128 *pMaxs)
{
  __m128 v5; // [esp-20h] [ebp-2Ch] BYREF
  __m128 v6; // [esp-10h] [ebp-1Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a2;
  v8 = retaddr;
  v6 = _mm_add_ps(*pMaxs, this->m_f4Extents);
  v5 = _mm_sub_ps(*pMins, this->m_f4Extents);
  return IsBoxIntersectingRay(
           inBoxMin: &v5,
           inBoxMax: &v6,
           origin: &this->m_f4Start,
           delta: &this->m_f4Delta,
           invDelta: &this->m_f4InvDelta,
           vTolerance: &Four_Zeros);
}

//------------------------------------------------------------------------------
// Address: 0x101D89C0
// Name: public: void CVoxelHash::LeafListRaySetup(struct Ray_t const __near &,class Vector const __near &,class Vector const __near &,union Voxel_t,int __near *,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelHash::LeafListRaySetup(
        CVoxelHash *this,
        const Ray_t *ray,
        const Vector *vecEnd,
        const Vector *vecInvDelta,
        Voxel_t voxel,
        int *pStep,
        float *pMax,
        float *pDelta)
{
  const Ray_t *v9; // ecx
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm4_4
  float v13; // xmm1_4
  float v14; // xmm3_4
  float v15; // xmm5_4
  int v16; // edi
  unsigned int v17; // esi
  int *v18; // ebx
  const Vector *v19; // edi
  int v20; // eax
  float v21; // xmm7_4
  float x; // xmm0_4
  float v23; // xmm1_4
  int v24; // eax
  float v25; // xmm2_4
  float v26; // xmm3_4
  float y; // xmm0_4
  int v28; // eax
  int v29; // eax
  float v30; // xmm4_4
  float v31; // xmm5_4
  float z; // xmm0_4
  int v33; // eax
  unsigned int iVoxel_8; // [esp+8h] [ebp-4h]
  float flDistStart; // [esp+20h] [ebp+14h]

  v9 = ray;
  v10 = ray->m_Start.x - this->m_vecVoxelOrigin.x;
  v11 = ray->m_Start.y - this->m_vecVoxelOrigin.y;
  v12 = ray->m_Start.z - this->m_vecVoxelOrigin.z;
  iVoxel_8 = voxel.uiVoxel >> 22;
  v13 = vecEnd->x - this->m_vecVoxelOrigin.x;
  v14 = vecEnd->y - this->m_vecVoxelOrigin.y;
  v15 = vecEnd->z - this->m_vecVoxelOrigin.z;
  v16 = *(_WORD *)&voxel.bitsVoxel & 0x7FF;
  v17 = (voxel.uiVoxel >> 11) & 0x7FF;
  if ( v10 == v13 )
  {
    v18 = pStep;
    v19 = vecInvDelta;
    *pStep = 0;
    *pMax = 65536.0;
    *pDelta = 65536.0;
  }
  else
  {
    if ( ray->m_Delta.x >= 0.0 )
    {
      *pStep = 1;
      v21 = (float)((v16 + 1) * (-256 << (2 * this->m_nLevel)));
      flDistStart = (float)-v10 - v21;
      x = vecInvDelta->x;
      v13 = -v13;
      v19 = vecInvDelta;
    }
    else
    {
      *pStep = -1;
      v20 = v16 * (256 << (2 * LOBYTE(this->m_nLevel)));
      v19 = vecInvDelta;
      v21 = (float)v20;
      flDistStart = v10 - (float)v20;
      x = -vecInvDelta->x;
    }
    v23 = v13 - v21;
    if ( flDistStart <= 0.0 || v23 <= 0.0 )
    {
      *pMax = x * flDistStart;
      *pDelta = (float)(256 << (2 * this->m_nLevel)) * x;
    }
    else
    {
      *pMax = 65536.0;
      *pDelta = 65536.0;
    }
    v9 = ray;
    v18 = pStep;
  }
  if ( v11 == v14 )
  {
    v18[1] = 0;
    pMax[1] = 65536.0;
    pDelta[1] = 65536.0;
  }
  else
  {
    if ( v9->m_Delta.y >= 0.0 )
    {
      v18[1] = 1;
      v28 = (v17 + 1) * (-256 << (2 * LOBYTE(this->m_nLevel)));
      v25 = (float)-v11 - (float)v28;
      v26 = (float)-v14 - (float)v28;
      y = v19->y;
    }
    else
    {
      v18[1] = -1;
      v24 = v17 * (256 << (2 * LOBYTE(this->m_nLevel)));
      v25 = v11 - (float)v24;
      v26 = v14 - (float)v24;
      y = -v19->y;
    }
    if ( v25 <= 0.0 || v26 <= 0.0 )
    {
      pMax[1] = y * v25;
      pDelta[1] = (float)(256 << (2 * this->m_nLevel)) * y;
    }
    else
    {
      pMax[1] = 65536.0;
      pDelta[1] = 65536.0;
    }
    v9 = ray;
  }
  if ( v12 == v15 )
  {
    v18[2] = 0;
LABEL_23:
    pMax[2] = 65536.0;
    pDelta[2] = 65536.0;
    return;
  }
  if ( v9->m_Delta.z >= 0.0 )
  {
    v18[2] = 1;
    v33 = (iVoxel_8 + 1) * (-256 << (2 * this->m_nLevel));
    v30 = (float)-v12 - (float)v33;
    v31 = (float)-v15 - (float)v33;
    z = v19->z;
  }
  else
  {
    v18[2] = -1;
    v29 = iVoxel_8 * (256 << (2 * LOBYTE(this->m_nLevel)));
    v30 = v12 - (float)v29;
    v31 = v15 - (float)v29;
    z = -v19->z;
  }
  if ( v30 > 0.0 && v31 > 0.0 )
    goto LABEL_23;
  pMax[2] = z * v30;
  pDelta[2] = (float)(256 << (2 * LOBYTE(this->m_nLevel))) * z;
}

//------------------------------------------------------------------------------
// Address: 0x101D8D10
// Name: public: void CVoxelHash::LeafListExtrudedRaySetup(struct Ray_t const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,int __near * const,int __near * const,int __near *,float __near *,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelHash::LeafListExtrudedRaySetup(
        CVoxelHash *this,
        const Ray_t *ray,
        const Vector *vecInvDelta,
        const Vector *vecMin,
        const Vector *vecMax,
        int *iVoxelMin,
        int *iVoxelMax,
        int *pStep,
        float *pMin,
        float *pMax,
        float *pDelta)
{
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm0_4
  int v17; // ecx
  VectorAligned *p_m_Delta; // ebx
  int i; // edx
  float *v20; // eax
  int v21; // esi
  float v22; // xmm0_4
  float v23; // xmm1_4
  float x; // xmm3_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  int v27; // esi
  Vector vecVoxelMin; // [esp+0h] [ebp-18h]
  Vector vecVoxelMax; // [esp+Ch] [ebp-Ch] BYREF
  const Vector *vecMina; // [esp+28h] [ebp+10h]

  v12 = vecMax->y - this->m_vecVoxelOrigin.y;
  v13 = vecMin->x - this->m_vecVoxelOrigin.x;
  v14 = vecMin->y - this->m_vecVoxelOrigin.y;
  vecVoxelMin.z = vecMin->z - this->m_vecVoxelOrigin.z;
  v15 = vecMax->x - this->m_vecVoxelOrigin.x;
  vecVoxelMax.y = v12;
  v16 = vecMax->z - this->m_vecVoxelOrigin.z;
  v17 = (char *)pStep - (char *)&vecVoxelMax;
  p_m_Delta = &ray->m_Delta;
  vecVoxelMin.x = v13;
  vecVoxelMin.y = v14;
  vecVoxelMax.x = v15;
  vecVoxelMax.z = v16;
  vecMina = (const Vector *)((char *)iVoxelMax - (char *)&vecVoxelMax);
  for ( i = 0; i < 3; ++i )
  {
    if ( p_m_Delta->x == 0.0 )
    {
      pMax[i] = 65536.0;
      pMin[i] = 65536.0;
      pDelta[i] = 65536.0;
    }
    else
    {
      v20 = (float *)((char *)&vecVoxelMax.x + i * 4);
      if ( p_m_Delta->x >= 0.0 )
      {
        v26 = *v20;
        *(_DWORD *)((char *)v20 + v17) = 1;
        v27 = -256 << (2 * this->m_nLevel);
        x = p_m_Delta->x;
        v22 = (float)-v26 - (float)(v27 * (*(_DWORD *)((char *)v20 + (_DWORD)vecMina) + 1));
        v23 = (float)-*(float *)((char *)&vecVoxelMin.x + i * 4) - (float)(v27 * (iVoxelMin[i] + 1));
        v25 = *(float *)((char *)&vecInvDelta->x + i * 4);
      }
      else
      {
        *(float *)((char *)v20 + v17) = NAN;
        v21 = 256 << (2 * this->m_nLevel);
        v22 = *(float *)((char *)&vecVoxelMin.x + i * 4) - (float)(v21 * iVoxelMin[i]);
        v23 = *v20 - (float)(v21 * *(_DWORD *)((char *)v20 + (_DWORD)vecMina));
        x = -p_m_Delta->x;
        v25 = -*(float *)((char *)&vecInvDelta->x + i * 4);
      }
      if ( v22 <= x )
      {
        pMax[i] = v25 * v22;
        pDelta[i] = (float)(256 << (2 * this->m_nLevel)) * v25;
      }
      else
      {
        pMax[i] = 65536.0;
        pDelta[i] = 65536.0;
      }
      if ( v23 <= x )
        pMin[i] = v25 * v23;
      else
        pMin[i] = 65536.0;
      v17 = (char *)pStep - (char *)&vecVoxelMax;
    }
    p_m_Delta = (VectorAligned *)((char *)p_m_Delta + 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D8F10
// Name: public: void CVoxelHash::RenderGrid(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelHash::RenderGrid(CVoxelHash *this)
{
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  int m_nLevel; // edx
  float v6; // xmm1_4
  int v7; // eax
  int v8; // edx
  int v9; // edi
  int v10; // ebx
  int v11; // ecx
  int v12; // eax
  int v13; // edx
  int v14; // edi
  int v15; // ebx
  int v16; // ecx
  int v17; // eax
  Color v18; // edx
  Color v19; // [esp-8h] [ebp-30h]
  Color v20; // [esp-8h] [ebp-30h]
  Vector vecStart; // [esp+Ch] [ebp-1Ch] BYREF
  Vector vecEnd; // [esp+18h] [ebp-10h] BYREF
  int i; // [esp+24h] [ebp-4h]

  v2 = 0;
  if ( this->m_nVoxelDelta[0] > 0 )
  {
    v3 = this->m_nVoxelDelta[1];
    do
    {
      v4 = 0;
      vecEnd.x = (float)(v2 * (256 << (2 * LOBYTE(this->m_nLevel)))) + this->m_vecVoxelOrigin.x;
      for ( vecStart.x = vecEnd.x; v4 < v3; ++v4 )
      {
        m_nLevel = this->m_nLevel;
        v19 = s_pVoxelColor[m_nLevel];
        v6 = (float)((256 << (2 * m_nLevel)) * this->m_nVoxelDelta[2]);
        vecEnd.y = (float)(v4 * (256 << (2 * m_nLevel))) + this->m_vecVoxelOrigin.y;
        vecStart.y = vecEnd.y;
        vecStart.z = this->m_vecVoxelOrigin.z;
        vecEnd.z = v6 + vecStart.z;
        RenderLine(v1: &vecStart, v2: &vecEnd, c: v19, bZBuffer: true);
        v3 = this->m_nVoxelDelta[1];
      }
      ++v2;
    }
    while ( v2 < this->m_nVoxelDelta[0] );
  }
  v7 = 0;
  i = 0;
  if ( this->m_nVoxelDelta[0] > 0 )
  {
    v8 = this->m_nVoxelDelta[2];
    do
    {
      v9 = 0;
      vecEnd.x = (float)(v7 * (256 << (2 * LOBYTE(this->m_nLevel)))) + this->m_vecVoxelOrigin.x;
      vecStart.x = vecEnd.x;
      if ( v8 > 0 )
      {
        do
        {
          v10 = this->m_nLevel;
          v11 = 256 << (2 * v10);
          v20 = s_pVoxelColor[v10];
          vecEnd.z = (float)(v9 * v11) + this->m_vecVoxelOrigin.z;
          vecStart.z = vecEnd.z;
          vecStart.y = this->m_vecVoxelOrigin.y;
          vecEnd.y = (float)(v8 * v11) + vecStart.y;
          RenderLine(v1: &vecStart, v2: &vecEnd, c: v20, bZBuffer: true);
          v8 = this->m_nVoxelDelta[2];
          ++v9;
        }
        while ( v9 < v8 );
        v7 = i;
      }
      i = ++v7;
    }
    while ( v7 < this->m_nVoxelDelta[0] );
  }
  v12 = 0;
  i = 0;
  if ( this->m_nVoxelDelta[1] > 0 )
  {
    v13 = this->m_nVoxelDelta[2];
    do
    {
      v14 = 0;
      vecEnd.y = (float)(v12 * (256 << (2 * LOBYTE(this->m_nLevel)))) + this->m_vecVoxelOrigin.y;
      vecStart.y = vecEnd.y;
      if ( v13 > 0 )
      {
        do
        {
          v15 = this->m_nLevel;
          vecStart.x = this->m_vecVoxelOrigin.z;
          v16 = 256 << (2 * v15);
          v17 = v13 * v16;
          v18 = s_pVoxelColor[v15];
          vecEnd.z = (float)(v14 * v16) + vecStart.x;
          vecStart.z = vecEnd.z;
          vecEnd.x = (float)v17 + this->m_vecVoxelOrigin.x;
          RenderLine(v1: &vecStart, v2: &vecEnd, c: v18, bZBuffer: true);
          v13 = this->m_nVoxelDelta[2];
          ++v14;
        }
        while ( v14 < v13 );
        v12 = i;
      }
      i = ++v12;
    }
    while ( v12 < this->m_nVoxelDelta[1] );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D9190
// Name: public: virtual void CVoxelTree::EnumerateElementsInSphere(int,class Vector const __near &,float,bool,class IPartitionEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelTree::EnumerateElementsInSphere(
        CVoxelTree *this,
        int listMask,
        const Vector *origin,
        float radius,
        BOOL coarseTest,
        IPartitionEnumerator *pIterator)
{
  float x; // xmm1_4
  float y; // xmm2_4
  void (__thiscall *EnumerateElementsInBox)(CVoxelTree *, int, const Vector *, const Vector *, bool, IPartitionEnumerator *); // eax
  float z; // xmm4_4
  Vector vecMin; // [esp+0h] [ebp-18h] BYREF
  Vector vecMax; // [esp+Ch] [ebp-Ch] BYREF

  x = origin->x;
  vecMin.x = origin->x - radius;
  y = origin->y;
  vecMin.y = y - radius;
  EnumerateElementsInBox = this->EnumerateElementsInBox;
  z = origin->z;
  vecMin.z = z - radius;
  vecMax.x = x + radius;
  vecMax.y = y + radius;
  vecMax.z = z + radius;
  EnumerateElementsInBox(this, a2: listMask, a3: &vecMin, a4: &vecMax, a5: coarseTest, a6: pIterator);
}

//------------------------------------------------------------------------------
// Address: 0x101D9210
// Name: bool DEBUG_THINK_TRACE_COUNTER_ALLOWED(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl DEBUG_THINK_TRACE_COUNTER_ALLOWED()
{
  if ( (_S1_18 & 1) == 0 )
  {
    _S1_18 |= 1u;
    bIsPublic = GetSteamUniverse() == k_EUniversePublic;
  }
  return !bIsPublic;
}

//------------------------------------------------------------------------------
// Address: 0x101D9240
// Name: class ISpatialPartitionInternal __near * SpatialPartition(void)
// Source: json
//------------------------------------------------------------------------------
CSpatialPartition *__cdecl SpatialPartition()
{
  return &g_SpatialPartition;
}

//------------------------------------------------------------------------------
// Address: 0x101D9250
// Name: public: virtual void CSpatialPartition::InstallQueryCallback(class IPartitionQueryCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::InstallQueryCallback(CSpatialPartition *this, IPartitionQueryCallback *pCallback)
{
  int m_nQueryCallbackCount; // eax

  if ( pCallback != nullptr )
  {
    m_nQueryCallbackCount = this->m_nQueryCallbackCount;
    if ( m_nQueryCallbackCount < 3 )
    {
      this->m_pQueryCallback[m_nQueryCallbackCount] = pCallback;
      ++this->m_nQueryCallbackCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D9280
// Name: public: virtual void CSpatialPartition::RemoveQueryCallback(class IPartitionQueryCallback __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::RemoveQueryCallback(CSpatialPartition *this, IPartitionQueryCallback *pCallback)
{
  int v2; // esi
  int v3; // eax
  IPartitionQueryCallback **i; // edx

  if ( pCallback != nullptr )
  {
    v2 = this->m_nQueryCallbackCount - 1;
    v3 = v2;
    if ( v2 >= 0 )
    {
      for ( i = &this->m_pQueryCallback[v2]; *i != pCallback; --i )
      {
        if ( --v3 < 0 )
          return;
      }
      this->m_nQueryCallbackCount = v2;
      this->m_pQueryCallback[v3] = this->m_pQueryCallback[v2];
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D92D0
// Name: public: virtual unsigned short CSpatialPartition::CreateHandle(class IHandleEntity __near *,int,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CSpatialPartition::CreateHandle(
        CSpatialPartition *this,
        IHandleEntity *pHandleEntity,
        int listMask,
        const Vector *mins,
        const Vector *maxs)
{
  int v6; // edi

  v6 = this->CreateHandle_2(this, a2: pHandleEntity);
  this->Insert(this, a2: listMask, a3: v6);
  this->InsertIntoTree(this, a2: v6, a3: mins, a4: maxs);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101D9350
// Name: public: virtual int CSpatialPartition::GetSuppressedLists(void)
// Source: json
//------------------------------------------------------------------------------
CColorBalanceOperation *__thiscall CSpatialPartition::GetSuppressedLists(CColorBalanceUIPanel *this)
{
  return this->m_pBalanceOp;
}

//------------------------------------------------------------------------------
// Address: 0x101D9430
// Name: public: virtual void CSpatialPartition::EnumerateElementsInSphere(int,class Vector const __near &,float,bool,class IPartitionEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::EnumerateElementsInSphere(
        CSpatialPartition *this,
        int listMask,
        const Vector *origin,
        float radius,
        int coarseTest,
        IPartitionEnumerator *pIterator)
{
  int v8; // ebx
  CVoxelTree *v9; // ecx
  int v10; // ebx
  IMDLCache *cacheCriticalSection; // [esp+1Ch] [ebp-8h]
  CVoxelTree *pTree; // [esp+20h] [ebp-4h]
  IPartitionQueryCallback **listMaska; // [esp+2Ch] [ebp+8h]
  IPartitionQueryCallback **listMaskb; // [esp+2Ch] [ebp+8h]

  cacheCriticalSection = g_pMDLCache;
  ((void (*)(void))g_pMDLCache->BeginLock)();
  v8 = 0;
  v9 = &this->m_VoxelTrees[(listMask & 0x1AC) == 0];
  pTree = v9;
  if ( this->m_nQueryCallbackCount > 0 )
  {
    listMaska = this->m_pQueryCallback;
    do
    {
      (*listMaska)->OnPreQuery(this: *listMaska, a2: listMask);
      ++listMaska;
      ++v8;
    }
    while ( v8 < this->m_nQueryCallbackCount );
    v9 = pTree;
  }
  ((void (__stdcall *)(int, const Vector *, _DWORD, int, IPartitionEnumerator *))v9->EnumerateElementsInSphere)(
    a1: listMask,
    a2: origin,
    a3: LODWORD(radius),
    a4: coarseTest,
    a5: pIterator);
  v10 = 0;
  if ( this->m_nQueryCallbackCount > 0 )
  {
    listMaskb = this->m_pQueryCallback;
    do
    {
      (*listMaskb)->OnPostQuery(this: *listMaskb, a2: listMask);
      ++listMaskb;
      ++v10;
    }
    while ( v10 < this->m_nQueryCallbackCount );
  }
  cacheCriticalSection->EndLock(this: cacheCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x101D9500
// Name: public: virtual void CSpatialPartition::EnumerateElementsAlongRay(int,struct Ray_t const __near &,bool,class IPartitionEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::EnumerateElementsAlongRay(
        CSpatialPartition *this,
        int listMask,
        const Ray_t *ray,
        BOOL coarseTest,
        IPartitionEnumerator *pIterator)
{
  int v7; // ebx
  CVoxelTree *v8; // ecx
  int v9; // ebx
  IMDLCache *cacheCriticalSection; // [esp+Ch] [ebp-8h]
  CVoxelTree *pTree; // [esp+10h] [ebp-4h]
  IPartitionQueryCallback **listMaska; // [esp+1Ch] [ebp+8h]
  IPartitionQueryCallback **listMaskb; // [esp+1Ch] [ebp+8h]

  cacheCriticalSection = g_pMDLCache;
  ((void (*)(void))g_pMDLCache->BeginLock)();
  v7 = 0;
  v8 = &this->m_VoxelTrees[(listMask & 0x1AC) == 0];
  pTree = v8;
  if ( this->m_nQueryCallbackCount > 0 )
  {
    listMaska = this->m_pQueryCallback;
    do
    {
      (*listMaska)->OnPreQuery(this: *listMaska, a2: listMask);
      ++listMaska;
      ++v7;
    }
    while ( v7 < this->m_nQueryCallbackCount );
    v8 = pTree;
  }
  v8->EnumerateElementsAlongRay(this: v8, a2: listMask, a3: ray, a4: coarseTest, a5: pIterator);
  v9 = 0;
  if ( this->m_nQueryCallbackCount > 0 )
  {
    listMaskb = this->m_pQueryCallback;
    do
    {
      (*listMaskb)->OnPostQuery(this: *listMaskb, a2: listMask);
      ++listMaskb;
      ++v9;
    }
    while ( v9 < this->m_nQueryCallbackCount );
  }
  cacheCriticalSection->EndLock(this: cacheCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x101D95C0
// Name: public: virtual void CSpatialPartition::EnumerateElementsAtPoint(int,class Vector const __near &,bool,class IPartitionEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::EnumerateElementsAtPoint(
        CSpatialPartition *this,
        int listMask,
        const Vector *pt,
        BOOL coarseTest,
        IPartitionEnumerator *pIterator)
{
  int v7; // ebx
  CVoxelTree *v8; // ecx
  int v9; // ebx
  IMDLCache *cacheCriticalSection; // [esp+Ch] [ebp-8h]
  CVoxelTree *pTree; // [esp+10h] [ebp-4h]
  IPartitionQueryCallback **listMaska; // [esp+1Ch] [ebp+8h]
  IPartitionQueryCallback **listMaskb; // [esp+1Ch] [ebp+8h]

  cacheCriticalSection = g_pMDLCache;
  ((void (*)(void))g_pMDLCache->BeginLock)();
  v7 = 0;
  v8 = &this->m_VoxelTrees[(listMask & 0x1AC) == 0];
  pTree = v8;
  if ( this->m_nQueryCallbackCount > 0 )
  {
    listMaska = this->m_pQueryCallback;
    do
    {
      (*listMaska)->OnPreQuery(this: *listMaska, a2: listMask);
      ++listMaska;
      ++v7;
    }
    while ( v7 < this->m_nQueryCallbackCount );
    v8 = pTree;
  }
  v8->EnumerateElementsAtPoint(this: v8, a2: listMask, a3: pt, a4: coarseTest, a5: pIterator);
  v9 = 0;
  if ( this->m_nQueryCallbackCount > 0 )
  {
    listMaskb = this->m_pQueryCallback;
    do
    {
      (*listMaskb)->OnPostQuery(this: *listMaskb, a2: listMask);
      ++listMaskb;
      ++v9;
    }
    while ( v9 < this->m_nQueryCallbackCount );
  }
  cacheCriticalSection->EndLock(this: cacheCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x101D9680
// Name: public: virtual void CSpatialPartition::RenderAllObjectsInTree(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::RenderAllObjectsInTree(CSpatialPartition *this, float flTime)
{
  CVoxelTree *m_VoxelTrees; // esi
  int i; // edi

  m_VoxelTrees = this->m_VoxelTrees;
  for ( i = 2; i != 0; --i )
  {
    ((void (__thiscall *)(CVoxelTree *, _DWORD))m_VoxelTrees->RenderAllObjectsInTree)(
      a1: m_VoxelTrees,
      a2: LODWORD(flTime));
    ++m_VoxelTrees;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D9720
// Name: public: void CUtlHashFixed<int,512,class CUtlHashFixedGenericHash<512>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::RemoveAll(
        CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *this)
{
  CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *v1; // esi
  int i; // ebx
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *m_pFirst; // eax
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *pNext; // edi

  v1 = this;
  for ( i = 512; i != 0; --i )
  {
    m_pFirst = v1->m_aBuckets[0].m_pFirst;
    if ( v1->m_aBuckets[0].m_pFirst != nullptr )
    {
      do
      {
        pNext = m_pFirst->pNext;
        free(pMem: m_pFirst);
        m_pFirst = pNext;
      }
      while ( pNext != v1->m_aBuckets[0].m_pFirst );
    }
    v1->m_aBuckets[0].m_pFirst = nullptr;
    v1->m_aBuckets[0].m_nElems = 0;
    v1 = (CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *)((char *)v1 + 8);
  }
  this->m_nElements = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101D9770
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<class PackedEntity __near *,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > *this,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *v4; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *m_pBlocks; // eax

  if ( num > 0 )
  {
    m_nGrowSize = this->m_nGrowSize;
    if ( m_nGrowSize == 0 )
    {
      m_nGrowSize = this->m_nAllocationCount;
      if ( m_nGrowSize == 0 )
        m_nGrowSize = 3;
    }
    if ( m_nGrowSize < num )
      m_nGrowSize *= (m_nGrowSize + num - 1) / m_nGrowSize;
    this->m_nAllocationCount += m_nGrowSize;
    v4 = (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *)_g_pMemAlloc->Alloc_2(
                                                                                  this: _g_pMemAlloc,
                                                                                  a2: 12 * m_nGrowSize + 8);
    if ( v4 == nullptr )
      _Error(a1: "CUtlFixedMemory overflow!\n");
    m_pBlocks = this->m_pBlocks;
    v4->m_pNext = nullptr;
    v4->m_nBlockSize = m_nGrowSize;
    if ( m_pBlocks != nullptr )
    {
      for ( ; m_pBlocks->m_pNext != nullptr; m_pBlocks = m_pBlocks->m_pNext )
        ;
      m_pBlocks->m_pNext = v4;
    }
    else
    {
      this->m_pBlocks = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D9800
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct LeafListData_t,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> > *this,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *v4; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *m_pBlocks; // eax

  if ( num > 0 )
  {
    m_nGrowSize = this->m_nGrowSize;
    if ( m_nGrowSize == 0 )
    {
      m_nGrowSize = this->m_nAllocationCount;
      if ( m_nGrowSize == 0 )
        m_nGrowSize = 2;
    }
    if ( m_nGrowSize < num )
      m_nGrowSize *= (m_nGrowSize + num - 1) / m_nGrowSize;
    this->m_nAllocationCount += m_nGrowSize;
    v4 = (CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *)_g_pMemAlloc->Alloc_2(
                                                                                       this: _g_pMemAlloc,
                                                                                       a2: 16 * m_nGrowSize + 8);
    if ( v4 == nullptr )
      _Error(a1: "CUtlFixedMemory overflow!\n");
    m_pBlocks = this->m_pBlocks;
    v4->m_pNext = nullptr;
    v4->m_nBlockSize = m_nGrowSize;
    if ( m_pBlocks != nullptr )
    {
      for ( ; m_pBlocks->m_pNext != nullptr; m_pBlocks = m_pBlocks->m_pNext )
        ;
      m_pBlocks->m_pNext = v4;
    }
    else
    {
      this->m_pBlocks = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D9890
// Name: public: virtual void CSpatialPartition::ReportStats(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::ReportStats(CSpatialPartition *this, const char *pFileName)
{
  CVoxelTree *m_VoxelTrees; // esi
  int i; // edi
  int v5; // [esp+0h] [ebp-Ch]

  _Msg(
    a1: "Handle Count %d (%d bytes, %d total)\n",
    this->m_aHandles.m_ElementCount,
    60 * this->m_aHandles.m_ElementCount,
    v5);
  m_VoxelTrees = this->m_VoxelTrees;
  for ( i = 2; i != 0; --i )
  {
    m_VoxelTrees->ReportStats(this: m_VoxelTrees, a2: pFileName);
    ++m_VoxelTrees;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D98E0
// Name: public: void CUtlHashFixed<int,512,class CUtlHashFixedGenericHash<512>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::Remove(
        CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *this,
        CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *hHash)
{
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *pNext; // eax
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> > *v4; // ebx

  pNext = hHash->pNext;
  v4 = &this->m_aBuckets[((unsigned __int16)(HIBYTE(hHash->elem.m_uiKey)
                                           + 33
                                           * (BYTE2(hHash->elem.m_uiKey)
                                            + 33
                                            * (BYTE1(hHash->elem.m_uiKey)
                                             + 33 * ((unsigned __int8)hHash->elem.m_uiKey - 21846))))
                        ^ ((unsigned int)(HIBYTE(hHash->elem.m_uiKey)
                                        + 33
                                        * ((unsigned __int8)BYTE2(hHash->elem.m_uiKey)
                                         + 33
                                         * ((unsigned __int8)BYTE1(hHash->elem.m_uiKey)
                                          + 33 * ((unsigned __int8)hHash->elem.m_uiKey - 1431655766)))) >> 16))
                       & 0x1FF];
  if ( pNext == hHash )
  {
    v4->m_pFirst = nullptr;
  }
  else
  {
    if ( v4->m_pFirst == hHash )
      v4->m_pFirst = pNext;
    hHash->pNext->pPrev = hHash->pPrev;
    hHash->pPrev->pNext = hHash->pNext;
  }
  free(pMem: hHash);
  --v4->m_nElems;
  --this->m_nElements;
}

//------------------------------------------------------------------------------
// Address: 0x101D9990
// Name: public: int CUtlHashFixed<int,512,class CUtlHashFixedGenericHash<512>>::Find(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *__thiscall CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::Find(
        CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *this,
        unsigned int uiKey)
{
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *m_pFirst; // ecx
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *result; // eax

  m_pFirst = this->m_aBuckets[((unsigned __int16)(HIBYTE(uiKey)
                                                + 33
                                                * (BYTE2(uiKey)
                                                 + 33 * (BYTE1(uiKey) + 33 * ((unsigned __int8)uiKey - 21846))))
                             ^ ((HIBYTE(uiKey)
                               + 33
                               * (BYTE2(uiKey)
                                + 33 * (BYTE1(uiKey) + 33 * ((unsigned int)(unsigned __int8)uiKey - 1431655766)))) >> 16))
                            & 0x1FF].m_pFirst;
  result = m_pFirst;
  if ( m_pFirst == nullptr )
    return (CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *)-1;
  while ( result->elem.m_uiKey != uiKey )
  {
    result = result->pNext;
    if ( result == m_pFirst || result == nullptr )
      return (CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *)-1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D9A10
// Name: public: CUtlPtrLinkedList<struct CUtlHashFixed<int,512,class CUtlHashFixedGenericHash<512>>::HashFixedData_t_<int>>::~CUtlPtrLinkedList<struct CUtlHashFixed<int,512,class CUtlHashFixedGenericHash<512>>::HashFixedData_t_<int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::HashFixedData_t_<int>>::~CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::HashFixedData_t_<int>>(
        CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> > *this)
{
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *m_pFirst; // eax
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *pNext; // edi

  m_pFirst = this->m_pFirst;
  if ( this->m_pFirst != nullptr )
  {
    do
    {
      pNext = m_pFirst->pNext;
      free(pMem: m_pFirst);
      m_pFirst = pNext;
    }
    while ( pNext != this->m_pFirst );
  }
  this->m_nElems = 0;
  this->m_pFirst = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101D9A50
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<struct LeafListData_t,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct LeafListData_t,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // edx
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1] && i < (unsigned int)&m_pBlockHeader[2 * m_pBlockHeader->m_nBlockSize + 1] )
    return (int)i > (int)&m_pBlockHeader[2 * m_nIndex + 1];
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[2 * m_pNext->m_nBlockSize + 1] )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x101D9AD0
// Name: public: void CVoxelTree::EndVisit(class CVarBitVec __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelTree::EndVisit(CVoxelTree *this, CVarBitVec *pPrev)
{
  void *v3; // edi

  v3 = GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index);
  CTSListBase::Push(this: &this->m_FreeVisits, pNode: (TSLNodeBase_t *)&this->m_pVisits[(_DWORD)v3][-1].m_pInt);
  this->m_pVisits[(_DWORD)v3] = pPrev;
}

//------------------------------------------------------------------------------
// Address: 0x101D9B10
// Name: public: CUtlHashFixed<int,512,class CUtlHashFixedGenericHash<512>>::~CUtlHashFixed<int,512,class CUtlHashFixedGenericHash<512>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::~CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>(
        CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *this)
{
  int *p_m_nElements; // esi
  int i; // ebx
  _DWORD *v4; // eax
  _DWORD *v5; // edi

  CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::RemoveAll(this);
  p_m_nElements = &this->m_nElements;
  for ( i = 511; i >= 0; --i )
  {
    v4 = (_DWORD *)*(p_m_nElements - 2);
    p_m_nElements -= 2;
    if ( v4 != nullptr )
    {
      do
      {
        v5 = (_DWORD *)v4[3];
        free(pMem: v4);
        v4 = v5;
      }
      while ( v5 != (_DWORD *)*p_m_nElements );
    }
    *p_m_nElements = 0;
    p_m_nElements[1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DA020
// Name: public: void CVoxelHash::UpdateListMask(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelHash::UpdateListMask(CVoxelHash *this, Voxel_t hPartition)
{
  unsigned __int8 *m_pBase; // eax
  __int16 v3; // dx
  unsigned __int8 *v4; // eax
  int v5; // esi
  unsigned int v6; // edi
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *v7; // eax
  int m_Data; // eax
  __int16 v9; // cx
  unsigned int v10; // edx
  signed int v11; // eax
  int v12; // esi
  int v13; // edi
  unsigned int v14; // esi
  unsigned int v15; // ecx
  unsigned int v16; // esi
  int v17; // edi
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *v18; // eax
  int v19; // eax
  int cz; // [esp+14h] [ebp-1Ch]
  int cy; // [esp+18h] [ebp-18h]
  int v23; // [esp+20h] [ebp-10h]
  unsigned int v24; // [esp+24h] [ebp-Ch]
  __int16 nListMask; // [esp+28h] [ebp-8h]
  Voxel_t vmin; // [esp+2Ch] [ebp-4h]

  m_pBase = this->m_pTree->m_pOwner->m_aHandles.m_Memory.m_MemoryStack.m_pBase;
  v3 = *(_WORD *)&m_pBase[60 * LOWORD(hPartition.uiVoxel) + 36];
  v4 = &m_pBase[60 * LOWORD(hPartition.uiVoxel)];
  v5 = *((_DWORD *)v4 + 7);
  v6 = *((_DWORD *)v4 + 3);
  nListMask = v3;
  vmin.uiVoxel = v6;
  if ( v6 == v5 )
  {
    v7 = CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::Find(this: &this->m_aVoxelHash, uiKey: v6);
    if ( v7 != (CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *)-1 )
    {
      m_Data = v7->elem.m_Data;
      if ( m_Data != 0 )
      {
        while ( *(_WORD *)m_Data != hPartition.bitsVoxel )
        {
          m_Data = *(_DWORD *)(m_Data + 8);
          if ( m_Data == 0 )
            goto LABEL_8;
        }
        *(_WORD *)(m_Data + 2) = nListMask;
      }
    }
  }
LABEL_8:
  v9 = v5 - v6;
  v10 = ((v5 - v6) >> 11) & 0x7FF;
  v11 = (v5 - v6) >> 22;
  v12 = ((unsigned __int16)v6 ^ *(_WORD *)&hPartition.bitsVoxel) & 0x7FF ^ hPartition.uiVoxel;
  cy = v10;
  cz = v11;
  v13 = v6 & 0x3FF800;
  v23 = (v9 & 0x7FF) + 1;
  do
  {
    v14 = v13 | v12 & 0xFFC007FF;
    v15 = vmin.uiVoxel & 0xFFC00000;
    v24 = v10 + 1;
    do
    {
      v16 = v15 | v14 & 0x3FFFFF;
      if ( v11 >= 0 )
      {
        v17 = v11 + 1;
        do
        {
          v18 = CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::Find(this: &this->m_aVoxelHash, uiKey: v16);
          if ( v18 != (CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *)-1 )
          {
            v19 = v18->elem.m_Data;
            if ( v19 != 0 )
            {
              while ( *(_WORD *)v19 != hPartition.bitsVoxel )
              {
                v19 = *(_DWORD *)(v19 + 8);
                if ( v19 == 0 )
                  goto LABEL_18;
              }
              *(_WORD *)(v19 + 2) = nListMask;
            }
          }
LABEL_18:
          v16 = ((v16 & 0xFFC00000) + 0x400000) ^ v16 & 0x3FFFFF;
          --v17;
        }
        while ( v17 != 0 );
        v10 = cy;
        v11 = cz;
        v15 = vmin.uiVoxel & 0xFFC00000;
      }
      v14 = (v16 ^ ((v16 & 0xFFFFF800) + 2048)) & 0x3FF800 ^ v16;
      --v24;
    }
    while ( v24 != 0 );
    v13 = vmin.uiVoxel & 0x3FF800;
    v12 = ((unsigned __int16)v14 ^ (unsigned __int16)(v14 + 1)) & 0x7FF ^ v14;
    --v23;
  }
  while ( v23 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x101DA1A0
// Name: public: bool CVoxelHash::EnumerateElementsAtPoint(int,union Voxel_t,class Vector const __near &,class IPartitionEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVoxelHash::EnumerateElementsAtPoint(
        CVoxelHash *this,
        int listMask,
        Voxel_t v,
        const Vector *pt,
        IPartitionEnumerator *pIterator)
{
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *v6; // eax
  unsigned __int16 *m_Data; // edi
  int v8; // eax
  int v9; // ecx
  unsigned __int8 *v10; // esi

  v6 = CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::Find(this: &this->m_aVoxelHash, uiKey: v.uiVoxel);
  if ( v6 == (CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *)-1 )
    return 1;
  m_Data = (unsigned __int16 *)v6->elem.m_Data;
  if ( m_Data == nullptr )
    return 1;
  while ( 1 )
  {
    v8 = *m_Data;
    v9 = m_Data[1];
    m_Data = *((unsigned __int16 **)m_Data + 2);
    if ( (_WORD)v8 != 0xFFFF && (v9 & listMask) != 0 )
    {
      v10 = &this->m_pTree->m_pOwner->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * v8];
      if ( (v10[38] & 1) == 0
        && IsPointInBox(pt, boxMin: (const Vector *)v10, boxMax: (const Vector *)(v10 + 16))
        && pIterator->EnumElement(this: pIterator, a2: *((IHandleEntity **)v10 + 8)) == 1 )
      {
        break;
      }
    }
    if ( m_Data == nullptr )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DA240
// Name: public: void CVoxelHash::RenderObjectInVoxel(unsigned short,class CPartitionVisitor __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelHash::RenderObjectInVoxel(
        CVoxelHash *this,
        unsigned __int16 hPartition,
        CPartitionVisitor *pVisitor,
        float flTime)
{
  unsigned __int8 *v5; // edi
  unsigned int *v6; // eax
  int v7; // edx
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm4_4
  float v12; // xmm5_4
  int v13; // [esp-14h] [ebp-84h]
  int v14; // [esp-10h] [ebp-80h]
  int v15; // [esp-Ch] [ebp-7Ch]
  Vector vecPoints[8]; // [esp+10h] [ebp-60h] BYREF

  if ( hPartition != 0xFFFF )
  {
    v5 = &this->m_pTree->m_pOwner->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * hPartition];
    v6 = &pVisitor->m_pVisits->m_pInt[(int)*(unsigned __int16 *)&v5[2 * pVisitor->m_iTree + 42] >> 5];
    v7 = 1 << (*(_WORD *)&v5[2 * pVisitor->m_iTree + 42] & 0x1F);
    if ( (v7 & *v6) == 0 )
    {
      *v6 |= v7;
      CDebugOverlay::AddBoxOverlay(
        origin: &vec3_origin,
        mins: (const Vector *)v5,
        maxs: (const Vector *)(v5 + 16),
        angles: &vec3_angle,
        r: s_pVoxelColor[this->m_nLevel]._color[0],
        g: s_pVoxelColor[this->m_nLevel]._color[1],
        b: s_pVoxelColor[this->m_nLevel]._color[2],
        a: 75,
        flDuration: flTime);
      v8 = *((float *)v5 + 1);
      v9 = *((float *)v5 + 2);
      v10 = *((float *)v5 + 4);
      v11 = *((float *)v5 + 5);
      v12 = *((float *)v5 + 6);
      v15 = s_pVoxelColor[this->m_nLevel]._color[2];
      v14 = s_pVoxelColor[this->m_nLevel]._color[1];
      v13 = s_pVoxelColor[this->m_nLevel]._color[0];
      vecPoints[0].x = *(float *)v5;
      vecPoints[0].y = v8;
      vecPoints[0].z = v9;
      vecPoints[1].x = vecPoints[0].x;
      vecPoints[1].y = v11;
      vecPoints[1].z = v9;
      vecPoints[2].x = v10;
      vecPoints[2].y = v11;
      vecPoints[2].z = v9;
      vecPoints[3].x = v10;
      vecPoints[3].y = v8;
      vecPoints[3].z = v9;
      vecPoints[4].x = vecPoints[0].x;
      vecPoints[4].y = v8;
      vecPoints[4].z = v12;
      vecPoints[5].x = vecPoints[0].x;
      vecPoints[5].y = v11;
      vecPoints[5].z = v12;
      vecPoints[6].x = v10;
      vecPoints[6].y = v11;
      vecPoints[6].z = v12;
      vecPoints[7].x = v10;
      vecPoints[7].y = v8;
      vecPoints[7].z = v12;
      CDebugOverlay::AddLineOverlay(
        origin: vecPoints,
        dest: &vecPoints[1],
        r: v13,
        g: v14,
        b: v15,
        a: 255,
        noDepthTest: true,
        flDuration: flTime);
      CDebugOverlay::AddLineOverlay(
        origin: &vecPoints[1],
        dest: &vecPoints[2],
        r: s_pVoxelColor[this->m_nLevel]._color[0],
        g: s_pVoxelColor[this->m_nLevel]._color[1],
        b: s_pVoxelColor[this->m_nLevel]._color[2],
        a: 255,
        noDepthTest: true,
        flDuration: flTime);
      CDebugOverlay::AddLineOverlay(
        origin: &vecPoints[2],
        dest: &vecPoints[3],
        r: s_pVoxelColor[this->m_nLevel]._color[0],
        g: s_pVoxelColor[this->m_nLevel]._color[1],
        b: s_pVoxelColor[this->m_nLevel]._color[2],
        a: 255,
        noDepthTest: true,
        flDuration: flTime);
      CDebugOverlay::AddLineOverlay(
        origin: &vecPoints[3],
        dest: vecPoints,
        r: s_pVoxelColor[this->m_nLevel]._color[0],
        g: s_pVoxelColor[this->m_nLevel]._color[1],
        b: s_pVoxelColor[this->m_nLevel]._color[2],
        a: 255,
        noDepthTest: true,
        flDuration: flTime);
      CDebugOverlay::AddLineOverlay(
        origin: &vecPoints[4],
        dest: &vecPoints[5],
        r: s_pVoxelColor[this->m_nLevel]._color[0],
        g: s_pVoxelColor[this->m_nLevel]._color[1],
        b: s_pVoxelColor[this->m_nLevel]._color[2],
        a: 255,
        noDepthTest: true,
        flDuration: flTime);
      CDebugOverlay::AddLineOverlay(
        origin: &vecPoints[5],
        dest: &vecPoints[6],
        r: s_pVoxelColor[this->m_nLevel]._color[0],
        g: s_pVoxelColor[this->m_nLevel]._color[1],
        b: s_pVoxelColor[this->m_nLevel]._color[2],
        a: 255,
        noDepthTest: true,
        flDuration: flTime);
      CDebugOverlay::AddLineOverlay(
        origin: &vecPoints[6],
        dest: &vecPoints[7],
        r: s_pVoxelColor[this->m_nLevel]._color[0],
        g: s_pVoxelColor[this->m_nLevel]._color[1],
        b: s_pVoxelColor[this->m_nLevel]._color[2],
        a: 255,
        noDepthTest: true,
        flDuration: flTime);
      CDebugOverlay::AddLineOverlay(
        origin: &vecPoints[7],
        dest: &vecPoints[4],
        r: s_pVoxelColor[this->m_nLevel]._color[0],
        g: s_pVoxelColor[this->m_nLevel]._color[1],
        b: s_pVoxelColor[this->m_nLevel]._color[2],
        a: 255,
        noDepthTest: true,
        flDuration: flTime);
      CDebugOverlay::AddLineOverlay(
        origin: vecPoints,
        dest: &vecPoints[4],
        r: s_pVoxelColor[this->m_nLevel]._color[0],
        g: s_pVoxelColor[this->m_nLevel]._color[1],
        b: s_pVoxelColor[this->m_nLevel]._color[2],
        a: 255,
        noDepthTest: true,
        flDuration: flTime);
      CDebugOverlay::AddLineOverlay(
        origin: &vecPoints[3],
        dest: &vecPoints[7],
        r: s_pVoxelColor[this->m_nLevel]._color[0],
        g: s_pVoxelColor[this->m_nLevel]._color[1],
        b: s_pVoxelColor[this->m_nLevel]._color[2],
        a: 255,
        noDepthTest: true,
        flDuration: flTime);
      CDebugOverlay::AddLineOverlay(
        origin: &vecPoints[1],
        dest: &vecPoints[5],
        r: s_pVoxelColor[this->m_nLevel]._color[0],
        g: s_pVoxelColor[this->m_nLevel]._color[1],
        b: s_pVoxelColor[this->m_nLevel]._color[2],
        a: 255,
        noDepthTest: true,
        flDuration: flTime);
      CDebugOverlay::AddLineOverlay(
        origin: &vecPoints[2],
        dest: &vecPoints[6],
        r: s_pVoxelColor[this->m_nLevel]._color[0],
        g: s_pVoxelColor[this->m_nLevel]._color[1],
        b: s_pVoxelColor[this->m_nLevel]._color[2],
        a: 255,
        noDepthTest: true,
        flDuration: flTime);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DA6A0
// Name: public: void CVoxelTree::UpdateListMask(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelTree::UpdateListMask(CVoxelTree *this, Voxel_t hPartition)
{
  CThreadSpinRWLock *p_m_lock; // edi
  signed __int32 m_i32; // ecx
  int nLevel; // [esp+4h] [ebp-4h]

  nLevel = (char)this->m_pOwner->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * LOWORD(hPartition.uiVoxel)
                                                                         + 39
                                                                         + this->m_TreeId];
  if ( nLevel >= 0 )
  {
    p_m_lock = &this->m_lock;
    if ( (this->m_lock.m_lockInfo.m_i32 & 0x10000) != 0
      || (m_i32 = (unsigned __int16)p_m_lock->m_lockInfo.m_i32,
          _InterlockedCompareExchange((volatile signed __int32 *)p_m_lock, m_i32 + 1, m_i32) != m_i32) )
    {
      CThreadSpinRWLock::SpinLockForRead(this: &this->m_lock);
    }
    CVoxelHash::UpdateListMask(this: &this->m_pVoxelHash[nLevel], hPartition);
    _InterlockedExchangeAdd((volatile signed __int32 *)p_m_lock, 0xFFFFFFFF);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DA730
// Name: public: virtual void CVoxelTree::EnumerateElementsAtPoint(int,class Vector const __near &,bool,class IPartitionEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelTree::EnumerateElementsAtPoint(
        CVoxelTree *this,
        int listMask,
        const Vector *pt,
        bool coarseTest,
        IPartitionEnumerator *pIterator)
{
  CThreadSpinRWLock::LockInfo_t m_lockInfo; // eax
  CThreadSpinRWLock *p_m_lock; // ecx
  signed __int32 m_i32; // edx
  CVoxelHash *m_pVoxelHash; // eax
  unsigned int v10; // esi
  unsigned int v11; // esi
  unsigned int v12; // esi
  CThreadSpinRWLock *v14; // [esp+8h] [ebp-4h]

  if ( listMask != 0 )
  {
    m_lockInfo = this->m_lock.m_lockInfo;
    p_m_lock = &this->m_lock;
    v14 = &this->m_lock;
    if ( (m_lockInfo.m_i32 & 0x10000) != 0
      || (m_i32 = (unsigned __int16)p_m_lock->m_lockInfo.m_i32,
          _InterlockedCompareExchange((volatile signed __int32 *)p_m_lock, m_i32 + 1, m_i32) != m_i32) )
    {
      CThreadSpinRWLock::SpinLockForRead(this: p_m_lock);
    }
    m_pVoxelHash = this->m_pVoxelHash;
    v10 = ((int)(float)(pt->x - m_pVoxelHash->m_vecVoxelOrigin.x) >> m_pVoxelHash->m_nLevelShift) & 0x7FF
        | ((((int)(float)(pt->z - m_pVoxelHash->m_vecVoxelOrigin.z) >> m_pVoxelHash->m_nLevelShift << 11)
          | ((int)(float)(pt->y - m_pVoxelHash->m_vecVoxelOrigin.y) >> m_pVoxelHash->m_nLevelShift) & 0x7FF) << 11);
    if ( CVoxelHash::EnumerateElementsAtPoint(this: m_pVoxelHash, listMask, v: (Voxel_t)v10, pt, pIterator) != 0 )
    {
      v11 = (v10 >> 2) & 0x3FCFF9FF;
      if ( CVoxelHash::EnumerateElementsAtPoint(this: this->m_pVoxelHash + 1, listMask, v: (Voxel_t)v11, pt, pIterator) != 0 )
      {
        v12 = (v11 >> 2) & 0x3FCFF9FF;
        if ( CVoxelHash::EnumerateElementsAtPoint(
               this: this->m_pVoxelHash + 2,
               listMask,
               v: (Voxel_t)v12,
               pt,
               pIterator) != 0 )
          CVoxelHash::EnumerateElementsAtPoint(
            this: this->m_pVoxelHash + 3,
            listMask,
            v: (Voxel_t)((v12 >> 2) & 0x3FCFF9FF),
            pt,
            pIterator);
      }
    }
    _InterlockedExchangeAdd((volatile signed __int32 *)v14, 0xFFFFFFFF);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DA890
// Name: public: virtual void CSpatialPartition::Insert(int,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::Insert(CSpatialPartition *this, __int16 listId, Voxel_t handle)
{
  unsigned __int8 *v4; // esi
  __int16 v5; // ax
  bool v6; // zf

  v4 = &this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * LOWORD(handle.uiVoxel)];
  v5 = listId | *((_WORD *)v4 + 18);
  if ( *((_WORD *)v4 + 18) != v5 )
  {
    v6 = (v4[38] & 2) == 0;
    *((_WORD *)v4 + 18) = v5;
    if ( !v6 )
      CVoxelTree::UpdateListMask(this: this->m_VoxelTrees, hPartition: handle);
    if ( (v4[38] & 4) != 0 )
      CVoxelTree::UpdateListMask(this: &this->m_VoxelTrees[1], hPartition: handle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DA8F0
// Name: public: virtual void CSpatialPartition::Remove(int,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::Remove(CSpatialPartition *this, __int16 listId, Voxel_t handle)
{
  unsigned __int8 *v4; // esi
  __int16 v5; // ax
  bool v6; // zf

  v4 = &this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * LOWORD(handle.uiVoxel)];
  v5 = ~listId & *((_WORD *)v4 + 18);
  if ( *((_WORD *)v4 + 18) != v5 )
  {
    v6 = (v4[38] & 2) == 0;
    *((_WORD *)v4 + 18) = v5;
    if ( !v6 )
      CVoxelTree::UpdateListMask(this: this->m_VoxelTrees, hPartition: handle);
    if ( (v4[38] & 4) != 0 )
      CVoxelTree::UpdateListMask(this: &this->m_VoxelTrees[1], hPartition: handle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DA950
// Name: public: virtual void CSpatialPartition::RemoveAndInsert(int,int,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::RemoveAndInsert(
        CSpatialPartition *this,
        __int16 removeMask,
        __int16 insertMask,
        Voxel_t handle)
{
  unsigned __int8 *v5; // esi
  __int16 v6; // ax
  bool v7; // zf

  v5 = &this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * LOWORD(handle.uiVoxel)];
  v6 = insertMask | ~removeMask & *((_WORD *)v5 + 18);
  if ( *((_WORD *)v5 + 18) != v6 )
  {
    v7 = (v5[38] & 2) == 0;
    *((_WORD *)v5 + 18) = v6;
    if ( !v7 )
      CVoxelTree::UpdateListMask(this: this->m_VoxelTrees, hPartition: handle);
    if ( (v5[38] & 4) != 0 )
      CVoxelTree::UpdateListMask(this: &this->m_VoxelTrees[1], hPartition: handle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DA9B0
// Name: public: virtual void CSpatialPartition::Remove(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::Remove(CSpatialPartition *this, Voxel_t handle)
{
  unsigned __int8 *v3; // edi
  bool v4; // zf

  v3 = &this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * LOWORD(handle.uiVoxel)];
  if ( *((_WORD *)v3 + 18) != 0 )
  {
    v4 = (v3[38] & 2) == 0;
    *((_WORD *)v3 + 18) = 0;
    if ( !v4 )
      CVoxelTree::UpdateListMask(this: this->m_VoxelTrees, hPartition: handle);
    if ( (v3[38] & 4) != 0 )
      CVoxelTree::UpdateListMask(this: &this->m_VoxelTrees[1], hPartition: handle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DAA10
// Name: public: virtual void CSpatialPartition::UnhideElement(unsigned short,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::UnhideElement(CSpatialPartition *this, unsigned __int16 handle, int tempHandle)
{
  CThreadFastMutex *p_m_HandlesMutex; // esi
  DWORD CurrentThreadId; // ecx

  p_m_HandlesMutex = &this->m_HandlesMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_HandlesMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_HandlesMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_HandlesMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_HandlesMutex->m_depth;
  }
  this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * handle + 38] &= ~1u;
  if ( p_m_HandlesMutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_HandlesMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x101DAA80
// Name: public: virtual int CSpatialPartition::HideElement(unsigned short)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSpatialPartition::HideElement(CSpatialPartition *this, unsigned __int16 handle)
{
  CThreadFastMutex *p_m_HandlesMutex; // esi
  DWORD CurrentThreadId; // ecx

  p_m_HandlesMutex = &this->m_HandlesMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_HandlesMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_HandlesMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_HandlesMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_HandlesMutex->m_depth;
  }
  this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * handle + 38] |= 1u;
  if ( p_m_HandlesMutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_HandlesMutex, 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101DAAF0
// Name: public: virtual void CSpatialPartition::ElementMoved(unsigned short,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::ElementMoved(
        CSpatialPartition *this,
        int handle,
        const Vector *mins,
        const Vector *maxs)
{
  unsigned __int8 *m_pBase; // edx
  int v7; // eax
  unsigned __int8 *v8; // esi
  int listMask; // [esp+14h] [ebp+8h]

  m_pBase = this->m_aHandles.m_Memory.m_MemoryStack.m_pBase;
  v7 = *(unsigned __int16 *)&m_pBase[60 * (unsigned __int16)handle + 36];
  v8 = &m_pBase[60 * (unsigned __int16)handle];
  listMask = v7;
  if ( (v7 & 0x1AC) != 0 )
  {
    this->m_VoxelTrees[0].ElementMoved(this: this->m_VoxelTrees, a2: handle, a3: mins, a4: maxs);
    v8[38] |= 2u;
    v7 = listMask;
  }
  if ( (v7 & 0xFFFFFE53) != 0 )
  {
    this->m_VoxelTrees[1].ElementMoved(this: &this->m_VoxelTrees[1], a2: handle, a3: mins, a4: maxs);
    v8[38] |= 4u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DAB70
// Name: public: virtual void CVoxelTree::ReportStats(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelTree::ReportStats(CVoxelTree *this, const char *pFileName)
{
  CVoxelTree *v2; // esi
  int v3; // ebx
  int v4; // edx
  CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *p_m_aVoxelHash; // edi
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *m_pFirst; // ecx
  int j; // eax
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *pNext; // eax
  int i; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]

  v2 = this;
  _Msg(a1: "Histogram : Entities per level\n");
  v3 = 0;
  if ( v2->m_nLevelCount > 0 )
  {
    v11 = 0;
    do
    {
      v4 = 0;
      p_m_aVoxelHash = &v2->m_pVoxelHash[v11].m_aVoxelHash;
      for ( i = 512; i != 0; --i )
      {
        if ( p_m_aVoxelHash->m_aBuckets[0].m_nElems != 0 )
        {
          m_pFirst = p_m_aVoxelHash->m_aBuckets[0].m_pFirst;
          if ( p_m_aVoxelHash->m_aBuckets[0].m_pFirst != nullptr )
          {
            do
            {
              for ( j = m_pFirst->elem.m_Data; j != 0; ++v4 )
                j = *(_DWORD *)(j + 8);
              pNext = m_pFirst->pNext;
              if ( pNext == p_m_aVoxelHash->m_aBuckets[0].m_pFirst )
                break;
              m_pFirst = m_pFirst->pNext;
            }
            while ( pNext != nullptr );
          }
        }
        p_m_aVoxelHash = (CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *)((char *)p_m_aVoxelHash + 8);
      }
      _Msg(a1: "\t%d - %d\n", v3, v4);
      v2 = this;
      ++v11;
      ++v3;
    }
    while ( v3 < this->m_nLevelCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DAD60
// Name: public: bool CVoxelHash::EnumerateElementsInVoxel<class CIntersectBox>(union Voxel_t,class CIntersectBox const __near &,int,class IPartitionEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVoxelHash::EnumerateElementsInVoxel<CIntersectBox>(
        CVoxelHash *this,
        Voxel_t voxel,
        const CIntersectBox *intersectTest,
        unsigned __int16 listMask,
        IPartitionEnumerator *pIterator)
{
  CVoxelHash *v5; // esi
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *v6; // eax
  unsigned __int16 *m_Data; // ebx
  int v9; // eax
  int v10; // edx
  unsigned __int8 *m_pBase; // eax
  bool v12; // zf
  unsigned __int8 *v13; // eax
  unsigned int *v14; // esi
  int v15; // edx
  const Vector *m_vecMaxs; // ecx
  const Vector *m_vecMins; // edx

  v5 = this;
  v6 = CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::Find(this: &this->m_aVoxelHash, uiKey: voxel.uiVoxel);
  if ( v6 == (CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *)-1 )
    return 1;
  m_Data = (unsigned __int16 *)v6->elem.m_Data;
  if ( m_Data == nullptr )
    return 1;
  while ( 1 )
  {
    v9 = *m_Data;
    if ( (_WORD)v9 != 0xFFFF )
    {
      if ( (m_Data[1] & listMask) == 0 )
        goto LABEL_16;
      v10 = 15 * v9;
      m_pBase = v5->m_pTree->m_pOwner->m_aHandles.m_Memory.m_MemoryStack.m_pBase;
      v12 = (m_pBase[4 * v10 + 38] & 1) == 0;
      v13 = &m_pBase[4 * v10];
      if ( !v12 )
        goto LABEL_16;
      v14 = &intersectTest->m_pVisits->m_pInt[(int)*(unsigned __int16 *)&v13[2 * intersectTest->m_iTree + 42] >> 5];
      v15 = 1 << (*(_WORD *)&v13[2 * intersectTest->m_iTree + 42] & 0x1F);
      if ( (v15 & *v14) == 0 )
      {
        *v14 |= v15;
        m_vecMaxs = intersectTest->m_vecMaxs;
        if ( m_vecMaxs->x >= *(float *)v13 )
        {
          m_vecMins = intersectTest->m_vecMins;
          if ( *((float *)v13 + 4) >= m_vecMins->x
            && m_vecMaxs->y >= *((float *)v13 + 1)
            && *((float *)v13 + 5) >= m_vecMins->y
            && m_vecMaxs->z >= *((float *)v13 + 2)
            && *((float *)v13 + 6) >= m_vecMins->z
            && pIterator->EnumElement(this: pIterator, a2: *((IHandleEntity **)v13 + 8)) == 1 )
          {
            return 0;
          }
        }
      }
      v5 = this;
    }
LABEL_16:
    m_Data = *((unsigned __int16 **)m_Data + 2);
    if ( m_Data == nullptr )
      return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DAE80
// Name: public: bool CVoxelHash::EnumerateElementsInSingleVoxel<class CIntersectRay>(union Voxel_t,class CIntersectRay const __near &,int,class IPartitionEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CVoxelHash::EnumerateElementsInSingleVoxel<CIntersectRay>@<al>(
        CVoxelHash *this@<ecx>,
        int a2@<ebp>,
        Voxel_t voxel,
        const CIntersectRay *intersectTest,
        int listMask,
        IPartitionEnumerator *pIterator)
{
  CVoxelHash *v6; // esi
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *v7; // eax
  unsigned __int16 *m_Data; // edi
  int v10; // eax
  int v11; // ecx
  int v12; // esi
  __m128 v13; // [esp-30h] [ebp-3Ch] BYREF
  __m128 v14; // [esp-20h] [ebp-2Ch] BYREF
  CVoxelHash *v15; // [esp-4h] [ebp-10h]
  int v16; // [esp+0h] [ebp-Ch]
  void *v17; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v16 = a2;
  v17 = retaddr;
  v6 = this;
  v15 = this;
  v7 = CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::Find(this: &this->m_aVoxelHash, uiKey: voxel.uiVoxel);
  if ( v7 == (CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *)-1 )
    return 1;
  m_Data = (unsigned __int16 *)v7->elem.m_Data;
  if ( m_Data == nullptr )
    return 1;
  while ( 1 )
  {
    v10 = *m_Data;
    v11 = m_Data[1];
    m_Data = *((unsigned __int16 **)m_Data + 2);
    if ( (_WORD)v10 != 0xFFFF && (v11 & listMask) != 0 )
    {
      v12 = (int)&v6->m_pTree->m_pOwner->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * v10];
      if ( (*(_BYTE *)(v12 + 38) & 1) == 0 )
      {
        v13 = *(__m128 *)v12;
        v14 = *(__m128 *)(v12 + 16);
        if ( IsBoxIntersectingRay(
               inBoxMin: &v13,
               inBoxMax: &v14,
               origin: &intersectTest->m_f4Start,
               delta: &intersectTest->m_f4Delta,
               invDelta: &intersectTest->m_f4InvDelta,
               vTolerance: &Four_Zeros)
          && pIterator->EnumElement(this: pIterator, a2: *(IHandleEntity **)(v12 + 32)) == 1 )
        {
          break;
        }
      }
    }
    if ( m_Data == nullptr )
      return 1;
    v6 = v15;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DAF70
// Name: public: bool CVoxelHash::EnumerateElementsInVoxel<class CIntersectRay>(union Voxel_t,class CIntersectRay const __near &,int,class IPartitionEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CVoxelHash::EnumerateElementsInVoxel<CIntersectRay>@<al>(
        CVoxelHash *this@<ecx>,
        int a2@<ebp>,
        Voxel_t voxel,
        const CIntersectRay *intersectTest,
        unsigned __int16 listMask,
        IPartitionEnumerator *pIterator)
{
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *v6; // eax
  unsigned __int16 *m_Data; // ecx
  int v8; // eax
  int v9; // esi
  unsigned __int8 *m_pBase; // eax
  bool v11; // zf
  unsigned __int8 *v12; // esi
  unsigned int *v13; // edx
  int v14; // eax
  __m128 v16; // [esp-30h] [ebp-3Ch] BYREF
  __m128 v17; // [esp-20h] [ebp-2Ch] BYREF
  CVoxelHash *v18; // [esp-8h] [ebp-14h]
  unsigned __int16 *v19; // [esp-4h] [ebp-10h]
  int v20; // [esp+0h] [ebp-Ch]
  void *v21; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v20 = a2;
  v21 = retaddr;
  v18 = this;
  v6 = CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::Find(this: &this->m_aVoxelHash, uiKey: voxel.uiVoxel);
  if ( v6 == (CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *)-1 )
    return 1;
  m_Data = (unsigned __int16 *)v6->elem.m_Data;
  v19 = m_Data;
  if ( m_Data == nullptr )
    return 1;
  while ( 1 )
  {
    v8 = *m_Data;
    if ( (_WORD)v8 != 0xFFFF && (m_Data[1] & listMask) != 0 )
    {
      v9 = 15 * v8;
      m_pBase = v18->m_pTree->m_pOwner->m_aHandles.m_Memory.m_MemoryStack.m_pBase;
      v11 = (m_pBase[4 * v9 + 38] & 1) == 0;
      v12 = &m_pBase[4 * v9];
      if ( v11 )
        break;
    }
LABEL_12:
    v19 = *((unsigned __int16 **)m_Data + 2);
    if ( v19 == nullptr )
      return 1;
    m_Data = v19;
  }
  v13 = &intersectTest->m_pVisits->m_pInt[(int)*(unsigned __int16 *)&v12[2 * intersectTest->m_iTree + 42] >> 5];
  v14 = 1 << (*(_WORD *)&v12[2 * intersectTest->m_iTree + 42] & 0x1F);
  if ( (v14 & *v13) != 0
    || (*v13 |= v14,
        v16 = *(__m128 *)v12,
        v17 = *((__m128 *)v12 + 1),
        !IsBoxIntersectingRay(
           inBoxMin: &v16,
           inBoxMax: &v17,
           origin: &intersectTest->m_f4Start,
           delta: &intersectTest->m_f4Delta,
           invDelta: &intersectTest->m_f4InvDelta,
           vTolerance: &Four_Zeros))
    || pIterator->EnumElement(this: pIterator, a2: *((IHandleEntity **)v12 + 8)) != 1 )
  {
    m_Data = v19;
    goto LABEL_12;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DB0A0
// Name: public: bool CVoxelHash::EnumerateElementsInVoxel<class CIntersectSweptBox>(union Voxel_t,class CIntersectSweptBox const __near &,int,class IPartitionEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVoxelHash::EnumerateElementsInVoxel<CIntersectSweptBox>(
        CVoxelHash *this,
        Voxel_t voxel,
        CIntersectSweptBox *intersectTest,
        unsigned __int16 listMask,
        IPartitionEnumerator *pIterator)
{
  CVoxelHash *v5; // esi
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *v6; // eax
  unsigned __int16 *m_Data; // ebx
  int v9; // eax
  int v10; // esi
  unsigned int *v11; // edx
  int v12; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  v5 = this;
  v6 = CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::Find(this: &this->m_aVoxelHash, uiKey: voxel.uiVoxel);
  if ( v6 == (CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *)-1 )
    return 1;
  m_Data = (unsigned __int16 *)v6->elem.m_Data;
  if ( m_Data == nullptr )
    return 1;
  while ( 1 )
  {
    v9 = *m_Data;
    if ( (_WORD)v9 != 0xFFFF && (m_Data[1] & listMask) != 0 )
    {
      v10 = (int)&v5->m_pTree->m_pOwner->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * v9];
      if ( (*(_BYTE *)(v10 + 38) & 1) == 0 )
      {
        v11 = &intersectTest->m_pVisits->m_pInt[(int)*(unsigned __int16 *)(v10 + 2 * intersectTest->m_iTree + 42) >> 5];
        v12 = 1 << (*(_WORD *)(v10 + 2 * intersectTest->m_iTree + 42) & 0x1F);
        if ( (v12 & *v11) == 0 )
        {
          *v11 |= v12;
          if ( CIntersectSweptBox::Intersects(
                 this: intersectTest,
                 a2: (int)&savedregs,
                 pMins: (__m128 *)v10,
                 pMaxs: (__m128 *)(v10 + 16))
            && pIterator->EnumElement(this: pIterator, a2: *(IHandleEntity **)(v10 + 32)) == 1 )
          {
            break;
          }
        }
      }
    }
    if ( *((_DWORD *)m_Data + 2) == 0 )
      return 1;
    m_Data = *((unsigned __int16 **)m_Data + 2);
    v5 = this;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DB250
// Name: public: bool CVoxelHash::EnumerateElementsInBox(int,union Voxel_t,union Voxel_t,class Vector const __near &,class Vector const __near &,class IPartitionEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVoxelHash::EnumerateElementsInBox(
        CVoxelHash *this,
        int listMask,
        Voxel_t vmin,
        Voxel_t vmax,
        const Vector *mins,
        const Vector *maxs,
        IPartitionEnumerator *pIterator)
{
  CVoxelTree *m_pTree; // esi
  CVarBitVec *v9; // ecx
  int m_TreeId; // edx
  Voxel_t v12; // ecx
  int uiVoxel; // esi
  int v14; // edi
  int v15; // edx
  unsigned int v16; // esi
  Voxel_t v17; // esi
  signed int v18; // edi
  CIntersectBox rect; // [esp+Ch] [ebp-1Ch] BYREF
  int v20; // [esp+1Ch] [ebp-Ch]
  int cy; // [esp+20h] [ebp-8h]
  CVoxelHash *v22; // [esp+24h] [ebp-4h]
  int iX; // [esp+3Ch] [ebp+14h]
  int iY; // [esp+40h] [ebp+18h]

  m_pTree = this->m_pTree;
  v22 = this;
  v9 = m_pTree->m_pVisits[(_DWORD)GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index)];
  m_TreeId = m_pTree->m_TreeId;
  rect.m_pVisits = v9;
  rect.m_iTree = m_TreeId;
  rect.m_vecMins = mins;
  rect.m_vecMaxs = maxs;
  if ( vmin.uiVoxel == vmax.uiVoxel )
    return CVoxelHash::EnumerateElementsInSingleVoxel<CIntersectBox>(
             this,
             voxel: vmin,
             intersectTest: &rect,
             listMask,
             pIterator);
  v12.bitsVoxel = vmin.bitsVoxel;
  uiVoxel = vmin.uiVoxel;
  v14 = (*(_WORD *)&vmax.bitsVoxel - *(_WORD *)&vmin.bitsVoxel) & 0x7FF;
  v15 = ((vmax.uiVoxel - vmin.uiVoxel) >> 11) & 0x7FF;
  v20 = (unsigned __int16)v14;
  cy = v15;
  iX = 0;
  while ( 1 )
  {
    v16 = (v12.uiVoxel ^ uiVoxel) & 0x3FF800 ^ uiVoxel;
    iY = 0;
    if ( v15 >= 0 )
      break;
LABEL_11:
    ++iX;
    uiVoxel = ((unsigned __int16)v16 ^ (unsigned __int16)(v16 + 1)) & 0x7FF ^ v16;
    if ( iX > v14 )
      return true;
  }
LABEL_5:
  v17.uiVoxel = v12.uiVoxel ^ (v12.uiVoxel ^ v16) & 0x3FFFFF;
  v18 = 0;
  while ( CVoxelHash::EnumerateElementsInVoxel<CIntersectBox>(
            this: v22,
            voxel: v17,
            intersectTest: &rect,
            listMask,
            pIterator) != 0 )
  {
    ++v18;
    v17.uiVoxel = ((v17.uiVoxel & 0xFFC00000) + 0x400000) ^ v17.uiVoxel & 0x3FFFFF;
    if ( v18 > (int)((vmax.uiVoxel - vmin.uiVoxel) >> 22) )
    {
      v12.bitsVoxel = vmin.bitsVoxel;
      v15 = cy;
      v16 = (v17.uiVoxel ^ ((v17.uiVoxel & 0xFFFFF800) + 2048)) & 0x3FF800 ^ v17.uiVoxel;
      if ( ++iY > cy )
      {
        v14 = v20;
        goto LABEL_11;
      }
      goto LABEL_5;
    }
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x101DB3C0
// Name: public: bool CVoxelHash::EnumerateElementsAlongRay_ExtrudedRaySlice(int,class IPartitionEnumerator __near *,class CIntersectSweptBox const __near &,int __near * const,int __near * const,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CVoxelHash::EnumerateElementsAlongRay_ExtrudedRaySlice@<al>(
        CVoxelHash *this@<ecx>,
        int a2@<ebp>,
        unsigned __int16 listMask,
        IPartitionEnumerator *pIterator,
        const CIntersectSweptBox *intersectSweptBox,
        int *voxelMin,
        int *voxelMax,
        int iAxis,
        int *pStep)
{
  int v9; // edx
  int v10; // ecx
  int v11; // eax
  float v12; // xmm0_4
  int v13; // edx
  int v14; // eax
  int v15; // esi
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *v16; // eax
  unsigned __int16 *m_Data; // ecx
  int v18; // eax
  int v19; // esi
  int v20; // eax
  bool v21; // zf
  int v22; // esi
  unsigned int *v23; // edx
  int v24; // eax
  __m128 v26; // [esp-2Ch] [ebp-5Ch] BYREF
  __m128 v27; // [esp-1Ch] [ebp-4Ch] BYREF
  int v28; // [esp-Ch] [ebp-3Ch]
  int v29; // [esp-8h] [ebp-38h]
  int v30; // [esp-4h] [ebp-34h]
  int mins[3]; // [esp+0h] [ebp-30h]
  int maxs[3]; // [esp+Ch] [ebp-24h]
  int iX; // [esp+18h] [ebp-18h]
  int iY; // [esp+1Ch] [ebp-14h]
  int iZ; // [esp+20h] [ebp-10h]
  int v36; // [esp+24h] [ebp-Ch]
  void *v37; // [esp+28h] [ebp-8h]
  void *retaddr; // [esp+30h] [ebp+0h]

  v36 = a2;
  v37 = retaddr;
  v9 = voxelMin[1];
  iX = (int)this;
  v10 = *voxelMin;
  v30 = voxelMin[2];
  v29 = v9;
  mins[0] = *voxelMax;
  v11 = voxelMax[2];
  mins[1] = voxelMax[1];
  mins[2] = v11;
  v12 = (float)pStep[iAxis];
  v28 = v10;
  if ( v12 >= 0.0 )
  {
    *(&v28 + iAxis) = mins[iAxis];
    v10 = v28;
  }
  else
  {
    mins[iAxis] = *(&v28 + iAxis);
  }
  v13 = v10;
  maxs[0] = v10;
  if ( v10 > mins[0] )
    return 1;
  while ( 1 )
  {
    iZ ^= ((unsigned __int16)v13 ^ (unsigned __int16)iZ) & 0x7FF;
    v14 = v29;
    maxs[1] = v29;
    if ( v29 <= mins[1] )
      break;
LABEL_24:
    maxs[0] = ++v13;
    if ( v13 > mins[0] )
      return 1;
  }
  while ( 1 )
  {
    v15 = v30;
    iZ ^= (iZ ^ (v14 << 11)) & 0x3FF800;
    maxs[2] = v30;
    if ( v30 <= mins[2] )
      break;
LABEL_22:
    maxs[1] = ++v14;
    if ( v14 > mins[1] )
    {
      v13 = maxs[0];
      goto LABEL_24;
    }
  }
  while ( 1 )
  {
    iZ = iZ & 0x3FFFFF | (v15 << 22);
    v16 = CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::Find(
            this: (CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *)(iX + 12),
            uiKey: iZ);
    if ( v16 != (CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *)-1 )
    {
      m_Data = (unsigned __int16 *)v16->elem.m_Data;
      iY = (int)m_Data;
      if ( m_Data != nullptr )
        break;
    }
LABEL_20:
    maxs[2] = ++v15;
    if ( v15 > mins[2] )
    {
      v14 = maxs[1];
      goto LABEL_22;
    }
  }
  while ( 1 )
  {
    v18 = *m_Data;
    if ( (_WORD)v18 != 0xFFFF )
    {
      if ( (m_Data[1] & listMask) == 0 )
        goto LABEL_18;
      v19 = 15 * v18;
      v20 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(iX + 4168) + 192) + 16);
      v21 = (*(_BYTE *)(v20 + 4 * v19 + 38) & 1) == 0;
      v22 = v20 + 4 * v19;
      if ( !v21 )
        goto LABEL_18;
      v23 = &intersectSweptBox->m_pVisits->m_pInt[(int)*(unsigned __int16 *)(v22 + 2 * intersectSweptBox->m_iTree + 42) >> 5];
      v24 = 1 << (*(_WORD *)(v22 + 2 * intersectSweptBox->m_iTree + 42) & 0x1F);
      if ( (v24 & *v23) == 0 )
      {
        *v23 |= v24;
        v27 = _mm_add_ps(*(__m128 *)(v22 + 16), intersectSweptBox->m_f4Extents);
        v26 = _mm_sub_ps(*(__m128 *)v22, intersectSweptBox->m_f4Extents);
        if ( IsBoxIntersectingRay(
               inBoxMin: &v26,
               inBoxMax: &v27,
               origin: &intersectSweptBox->m_f4Start,
               delta: &intersectSweptBox->m_f4Delta,
               invDelta: &intersectSweptBox->m_f4InvDelta,
               vTolerance: &Four_Zeros)
          && pIterator->EnumElement(this: pIterator, a2: *(IHandleEntity **)(v22 + 32)) == 1 )
        {
          return 0;
        }
      }
      m_Data = (unsigned __int16 *)iY;
    }
LABEL_18:
    iY = *((_DWORD *)m_Data + 2);
    if ( iY == 0 )
    {
      v15 = maxs[2];
      goto LABEL_20;
    }
    m_Data = (unsigned __int16 *)iY;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DB5D0
// Name: public: bool CVoxelTree::EnumerateElementsAlongRay_Ray(int,struct Ray_t const __near &,class Vector const __near &,class Vector const __near &,class IPartitionEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
char __userpurge CVoxelTree::EnumerateElementsAlongRay_Ray@<al>(
        CVoxelTree *this@<ecx>,
        Voxel_t a2@<ebp>,
        int listMask,
        const Ray_t *ray,
        const Vector *vecInvDelta,
        const Vector *vecEnd,
        IPartitionEnumerator *pIterator)
{
  CVoxelHash *m_pVoxelHash; // eax
  float v8; // xmm0_4
  int v9; // edx
  float v10; // ecx
  int v11; // esi
  int v12; // edx
  unsigned int v13; // esi
  Voxel_t v14; // edi
  int v15; // ecx
  int v16; // edx
  VectorAligned m_Delta; // xmm0
  __m128 v18; // xmm0
  unsigned int v19; // esi
  unsigned int v20; // esi
  unsigned int v22; // edi
  float v23; // xmm0_4
  Voxel_t v24; // eax
  Voxel_t v25; // ecx
  _DWORD v26[3]; // [esp-Ch] [ebp-8Ch] BYREF
  CIntersectRay intersectRay; // [esp+0h] [ebp-80h] BYREF
  float tDelta[3]; // [esp+40h] [ebp-40h] BYREF
  int nStep[3]; // [esp+4Ch] [ebp-34h] BYREF
  float tMax[3]; // [esp+58h] [ebp-28h] BYREF
  Voxel_t ov3; // [esp+64h] [ebp-1Ch]
  Voxel_t ov2; // [esp+68h] [ebp-18h]
  Voxel_t ov1; // [esp+6Ch] [ebp-14h]
  Voxel_t v3; // [esp+70h] [ebp-10h]
  Voxel_t v2; // [esp+74h] [ebp-Ch] BYREF
  void *v36; // [esp+78h] [ebp-8h]
  void *retaddr; // [esp+80h] [ebp+0h]

  v2.bitsVoxel = a2.bitsVoxel;
  v36 = retaddr;
  m_pVoxelHash = this->m_pVoxelHash;
  v8 = ray->m_Start.y - m_pVoxelHash->m_vecVoxelOrigin.y;
  v9 = (int)(float)(ray->m_Start.z - m_pVoxelHash->m_vecVoxelOrigin.z);
  ov1.uiVoxel = (unsigned int)this;
  v10 = *(float *)&m_pVoxelHash->m_nLevelShift;
  v11 = (v9 >> SLOBYTE(v10) << 11) | ((int)v8 >> SLOBYTE(v10)) & 0x7FF;
  v12 = (int)(float)(ray->m_Start.x - m_pVoxelHash->m_vecVoxelOrigin.x) >> SLOBYTE(v10);
  tMax[0] = v10;
  v13 = v12 & 0x7FF | (v11 << 11);
  HIBYTE(v3.uiVoxel) = v13 == (((int)(float)(vecEnd->x - m_pVoxelHash->m_vecVoxelOrigin.x) >> SLOBYTE(v10)) & 0x7FF
                             | ((((int)(float)(vecEnd->z - m_pVoxelHash->m_vecVoxelOrigin.z) >> SLOBYTE(v10) << 11)
                               | ((int)(float)(vecEnd->y - m_pVoxelHash->m_vecVoxelOrigin.y) >> SLOBYTE(v10)) & 0x7FF) << 11));
  v14.bitsVoxel = ov1.bitsVoxel;
  v15 = *(_DWORD *)(ov1.uiVoxel
                  + 4
                  * (_DWORD)GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index)
                  + 64);
  v16 = *(_DWORD *)(ov1.uiVoxel + 60);
  *(VectorAligned *)&intersectRay.m_iTree = ray->m_Start;
  m_Delta = ray->m_Delta;
  v26[1] = v16;
  *(VectorAligned *)((char *)&intersectRay.m_f4Start + 4) = m_Delta;
  v18 = *(__m128 *)&vecInvDelta->x;
  v26[0] = v15;
  *(__m128 *)((char *)&intersectRay.m_f4Delta + 4) = v18;
  if ( HIBYTE(v3.uiVoxel) != 0 )
  {
    if ( CVoxelHash::EnumerateElementsInSingleVoxel<CIntersectRay>(
           this: *(CVoxelHash **)(ov1.uiVoxel + 12),
           a2: (int)&v2,
           voxel: (Voxel_t)v13,
           intersectTest: (const CIntersectRay *)v26,
           listMask,
           pIterator) != 0 )
    {
      v19 = (v13 >> 2) & 0x3FCFF9FF;
      if ( CVoxelHash::EnumerateElementsInSingleVoxel<CIntersectRay>(
             this: (CVoxelHash *)(*(_DWORD *)(v14.uiVoxel + 12) + 4184),
             a2: (int)&v2,
             voxel: (Voxel_t)v19,
             intersectTest: (const CIntersectRay *)v26,
             listMask,
             pIterator) != 0 )
      {
        v20 = (v19 >> 2) & 0x3FCFF9FF;
        if ( CVoxelHash::EnumerateElementsInSingleVoxel<CIntersectRay>(
               this: (CVoxelHash *)(*(_DWORD *)(v14.uiVoxel + 12) + 8368),
               a2: (int)&v2,
               voxel: (Voxel_t)v20,
               intersectTest: (const CIntersectRay *)v26,
               listMask,
               pIterator) != 0 )
          return CVoxelHash::EnumerateElementsInSingleVoxel<CIntersectRay>(
                   this: (CVoxelHash *)(*(_DWORD *)(v14.uiVoxel + 12) + 12552),
                   a2: (int)&v2,
                   voxel: (Voxel_t)((v20 >> 2) & 0x3FCFF9FF),
                   intersectTest: (const CIntersectRay *)v26,
                   listMask,
                   pIterator);
      }
    }
    return 0;
  }
  CVoxelHash::LeafListRaySetup(
    this: *(CVoxelHash **)(ov1.uiVoxel + 12),
    ray,
    vecEnd,
    vecInvDelta,
    voxel: (Voxel_t)v13,
    pStep: (int *)tDelta,
    pMax: (float *)nStep,
    pDelta: &intersectRay.m_f4InvDelta.m128_f32[1]);
  memset(tMax, 255, sizeof(tMax));
  v22 = (v13 >> 2) & 0x3FCFF9FF;
  ov3.uiVoxel = (((v22 >> 2) & 0xFCFF9FF) >> 2) & 0x3CFF9FF;
  if ( CVoxelHash::EnumerateElementsInVoxel<CIntersectRay>(
         this: (CVoxelHash *)pIterator[3].__vftable,
         a2: (int)&v2,
         voxel: (Voxel_t)v13,
         intersectTest: (const CIntersectRay *)v26,
         listMask,
         pIterator) == 0 )
    return 0;
  while ( 1 )
  {
    v23 = *(float *)&nStep[2];
    if ( v22 != LODWORD(tMax[2]) )
    {
      if ( CVoxelHash::EnumerateElementsInVoxel<CIntersectRay>(
             this: (CVoxelHash *)&pIterator[3].__vftable[1046],
             a2: (int)&v2,
             voxel: (Voxel_t)v22,
             intersectTest: (const CIntersectRay *)v26,
             listMask,
             pIterator) == 0 )
        return 0;
      v23 = *(float *)&nStep[2];
    }
    if ( ov2.uiVoxel != LODWORD(tMax[1]) )
    {
      if ( CVoxelHash::EnumerateElementsInVoxel<CIntersectRay>(
             this: (CVoxelHash *)&pIterator[3].__vftable[2092],
             a2: (int)&v2,
             voxel: ov2,
             intersectTest: (const CIntersectRay *)v26,
             listMask,
             pIterator) == 0 )
        return 0;
      v23 = *(float *)&nStep[2];
    }
    v24.bitsVoxel = ov3.bitsVoxel;
    if ( ov3.uiVoxel != LODWORD(tMax[0]) )
    {
      if ( CVoxelHash::EnumerateElementsInVoxel<CIntersectRay>(
             this: (CVoxelHash *)&pIterator[3].__vftable[3138],
             a2: (int)&v2,
             voxel: ov3,
             intersectTest: (const CIntersectRay *)v26,
             listMask,
             pIterator) == 0 )
        return 0;
      v23 = *(float *)&nStep[2];
      v24.bitsVoxel = ov3.bitsVoxel;
    }
    if ( *(float *)nStep >= 1.0 && *(float *)&nStep[1] >= 1.0 && v23 >= 1.0 )
      return 1;
    if ( *(float *)&nStep[1] <= *(float *)nStep )
    {
      if ( v23 <= *(float *)&nStep[1] )
      {
LABEL_24:
        *(float *)&nStep[2] = intersectRay.m_f4InvDelta.m128_f32[3] + v23;
        v13 += LODWORD(tDelta[2]) << 22;
        goto LABEL_25;
      }
      *(float *)&nStep[1] = intersectRay.m_f4InvDelta.m128_f32[2] + *(float *)&nStep[1];
      v13 ^= (v13 ^ (v13 + (LODWORD(tDelta[1]) << 11))) & 0x3FF800;
    }
    else
    {
      if ( v23 <= *(float *)nStep )
        goto LABEL_24;
      *(float *)nStep = intersectRay.m_f4InvDelta.m128_f32[1] + *(float *)nStep;
      v13 ^= ((unsigned __int16)v13 ^ (unsigned __int16)(v13 + LOWORD(tDelta[0]))) & 0x7FF;
    }
LABEL_25:
    v25.bitsVoxel = ov2.bitsVoxel;
    LODWORD(tMax[2]) = v22;
    tMax[0] = *(float *)&v24.uiVoxel;
    v22 = (v13 >> 2) & 0x3FCFF9FF;
    ov2.uiVoxel = (v22 >> 2) & 0xFCFF9FF;
    tMax[1] = *(float *)&v25.uiVoxel;
    if ( CVoxelHash::EnumerateElementsInVoxel<CIntersectRay>(
           this: (CVoxelHash *)pIterator[3].__vftable,
           a2: (int)&v2,
           voxel: (Voxel_t)v13,
           intersectTest: (const CIntersectRay *)v26,
           listMask,
           pIterator) == 0 )
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DB990
// Name: public: bool CVoxelTree::EnumerateRayStartVoxels(int,class IPartitionEnumerator __near *,class CIntersectSweptBox __near &,int (__near * const)[2][3])
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVoxelTree::EnumerateRayStartVoxels(
        CVoxelTree *this,
        unsigned __int16 listMask,
        IPartitionEnumerator *pIterator,
        CIntersectSweptBox *intersectSweptBox,
        int (*voxelBounds)[2][3])
{
  int v6; // edx
  int v7; // ebx
  int *v8; // esi
  int v9; // ebx
  int v10; // eax
  int v11; // edi
  int *v12; // ecx
  int v13; // esi
  int v14; // eax
  int *v17; // [esp+10h] [ebp-24h]
  int i; // [esp+14h] [ebp-20h]
  int iY; // [esp+18h] [ebp-1Ch]
  int nMinZ; // [esp+1Ch] [ebp-18h]
  int v21; // [esp+20h] [ebp-14h]
  int nMinX; // [esp+24h] [ebp-10h]
  int iX; // [esp+28h] [ebp-Ch]
  int nMaxX; // [esp+2Ch] [ebp-8h]
  int nMaxY; // [esp+30h] [ebp-4h]
  int voxel; // [esp+48h] [ebp+14h]

  v6 = (*voxelBounds)[0][0];
  nMaxX = (*voxelBounds)[1][0];
  v7 = (*voxelBounds)[1][1];
  voxel = (*voxelBounds)[0][1];
  v8 = &(*voxelBounds)[0][2];
  nMaxY = v7;
  v9 = (*voxelBounds)[1][2];
  v10 = 0;
  v11 = *v8;
  nMinX = v6;
  nMinZ = *v8;
  i = 0;
  if ( this->m_nLevelCount <= 0 )
    return 1;
  v12 = v8;
  v13 = voxel;
  v21 = 0;
  v17 = v12;
  while ( 1 )
  {
    if ( v10 != 0 )
    {
      voxel >>= 2;
      nMaxX >>= 2;
      nMaxY >>= 2;
      *(v12 - 1) = voxel;
      v6 >>= 2;
      v11 >>= 2;
      v12[1] = nMaxX;
      v9 >>= 2;
      nMinX = v6;
      nMinZ = v11;
      *(v12 - 2) = v6;
      *v12 = v11;
      v12[2] = nMaxY;
      v12[3] = v9;
    }
    iX = v6;
    if ( nMinX <= nMaxX )
      break;
LABEL_14:
    ++v21;
    v10 = i + 1;
    v12 += 6;
    i = v10;
    v17 = v12;
    if ( v10 >= this->m_nLevelCount )
      return 1;
    v6 = nMinX;
  }
  while ( 1 )
  {
    v13 ^= ((unsigned __int16)iX ^ (unsigned __int16)v13) & 0x7FF;
    v14 = voxel;
    iY = voxel;
    if ( voxel <= nMaxY )
      break;
LABEL_13:
    if ( ++iX > nMaxX )
      goto LABEL_14;
  }
  while ( 1 )
  {
    v13 ^= (v13 ^ (v14 << 11)) & 0x3FF800;
    if ( v11 <= v9 )
      break;
LABEL_12:
    iY = ++v14;
    if ( v14 > nMaxY )
      goto LABEL_13;
  }
  while ( 1 )
  {
    v13 = (v11 << 22) | v13 & 0x3FFFFF;
    if ( CVoxelHash::EnumerateElementsInVoxel<CIntersectSweptBox>(
           this: &this->m_pVoxelHash[v21],
           voxel: (Voxel_t)v13,
           intersectTest: intersectSweptBox,
           listMask,
           pIterator) == 0 )
      return 0;
    if ( ++v11 > v9 )
    {
      v12 = v17;
      v14 = iY;
      v11 = nMinZ;
      goto LABEL_12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DBAE0
// Name: public: bool CVoxelTree::EnumerateElementsAlongRay_ExtrudedRay(int,struct Ray_t const __near &,class Vector const __near &,class Vector const __near &,class IPartitionEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
char __userpurge CVoxelTree::EnumerateElementsAlongRay_ExtrudedRay@<al>(
        CVoxelTree *this@<ecx>,
        int a2@<ebp>,
        unsigned __int16 listMask,
        const Ray_t *ray,
        const Vector *vecInvDelta,
        const Vector *vecEnd,
        IPartitionEnumerator *pIterator)
{
  float y; // xmm4_4
  float z; // xmm5_4
  CVoxelHash *m_pVoxelHash; // eax
  unsigned int m_nLevelShift; // ecx
  float v12; // xmm3_4
  int v13; // xmm1_4
  float v14; // xmm4_4
  int v15; // xmm2_4
  float v16; // xmm5_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm5_4
  void *v21; // eax
  int m_TreeId; // edx
  VectorAligned m_Start; // xmm0
  VectorAligned m_Delta; // xmm0
  __m128 v25; // xmm0
  float v26; // xmm4_4
  float v27; // xmm5_4
  CVoxelHash *v28; // eax
  unsigned int v29; // ecx
  float v30; // xmm3_4
  float v31; // xmm1_4
  float v32; // xmm4_4
  float v33; // xmm2_4
  float v34; // xmm5_4
  int v36; // eax
  int v37; // ecx
  int v38; // edx
  int v39; // eax
  int v40; // ecx
  int v41; // edx
  int v42; // eax
  int v43; // ecx
  int v44; // edx
  float v45; // eax
  float v46; // xmm2_4
  float v47; // xmm3_4
  float v48; // xmm4_4
  int v49; // esi
  int v50; // eax
  float v51; // xmm0_4
  float v52; // xmm1_4
  int v53; // esi
  int v54; // eax
  int v55; // ecx
  int v56; // ecx
  int v57; // eax
  int v58; // edi
  int v59; // ecx
  int v60; // edx
  int v61; // edi
  CVoxelHash *v62; // ecx
  _DWORD v63[3]; // [esp-Ch] [ebp-11Ch] BYREF
  CIntersectSweptBox intersectSweptBox; // [esp+0h] [ebp-110h]
  int nLastVoxel1[3]; // [esp+50h] [ebp-C0h] BYREF
  _BYTE tDelta[108]; // [esp+5Ch] [ebp-B4h] OVERLAPPED BYREF
  float v67; // [esp+C8h] [ebp-48h]
  int nLastVoxel3[3]; // [esp+CCh] [ebp-44h] BYREF
  int nLastVoxel2[3]; // [esp+D8h] [ebp-38h] BYREF
  int nStep[3]; // [esp+E4h] [ebp-2Ch] BYREF
  float tMax[3]; // [esp+F0h] [ebp-20h] BYREF
  int endVoxelMin[3]; // [esp+FCh] [ebp-14h] BYREF
  void *v73; // [esp+108h] [ebp-8h]
  void *retaddr; // [esp+110h] [ebp+0h]

  endVoxelMin[2] = a2;
  v73 = retaddr;
  endVoxelMin[0] = (int)this;
  y = ray->m_Start.y;
  z = ray->m_Start.z;
  m_pVoxelHash = this->m_pVoxelHash;
  m_nLevelShift = m_pVoxelHash->m_nLevelShift;
  v12 = ray->m_Start.x + ray->m_Extents.x;
  *(float *)nLastVoxel3 = ray->m_Start.x - ray->m_Extents.x;
  *(float *)&v13 = y - ray->m_Extents.y;
  v14 = y + ray->m_Extents.y;
  *(_DWORD *)tDelta = (int)(float)(*(float *)nLastVoxel3 - m_pVoxelHash->m_vecVoxelOrigin.x) >> m_nLevelShift;
  nLastVoxel3[1] = v13;
  *(float *)&v15 = z - ray->m_Extents.z;
  v16 = z + ray->m_Extents.z;
  *(_DWORD *)&tDelta[4] = (int)(float)(*(float *)&v13 - m_pVoxelHash->m_vecVoxelOrigin.y) >> m_nLevelShift;
  nLastVoxel3[2] = v15;
  v17 = *(float *)&v15 - m_pVoxelHash->m_vecVoxelOrigin.z;
  *(float *)&tDelta[100] = v12;
  v18 = v12 - m_pVoxelHash->m_vecVoxelOrigin.x;
  *(float *)&tDelta[104] = v14;
  v19 = v14 - m_pVoxelHash->m_vecVoxelOrigin.y;
  *(_DWORD *)&tDelta[8] = (int)v17 >> m_nLevelShift;
  v67 = v16;
  v20 = v16 - m_pVoxelHash->m_vecVoxelOrigin.z;
  *(_DWORD *)&tDelta[12] = (int)v18 >> m_nLevelShift;
  *(_DWORD *)&tDelta[16] = (int)v19 >> m_nLevelShift;
  *(_DWORD *)&tDelta[20] = (int)v20 >> m_nLevelShift;
  v21 = GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index);
  m_TreeId = this->m_TreeId;
  m_Start = ray->m_Start;
  v63[0] = this->m_pVisits[(_DWORD)v21];
  *(VectorAligned *)&intersectSweptBox.m_iTree = m_Start;
  m_Delta = ray->m_Delta;
  endVoxelMin[0] = (int)tDelta;
  v63[1] = m_TreeId;
  *(VectorAligned *)((char *)&intersectSweptBox.m_f4Start + 4) = m_Delta;
  v25 = *(__m128 *)&vecInvDelta->x;
  LODWORD(tMax[2]) = v63;
  LODWORD(tMax[1]) = pIterator;
  *(__m128 *)((char *)&intersectSweptBox.m_f4Delta + 4) = v25;
  *(__m128 *)((char *)&intersectSweptBox.m_f4InvDelta + 4) = (__m128)ray->m_Extents;
  if ( CVoxelTree::EnumerateRayStartVoxels(
         this,
         listMask,
         pIterator,
         intersectSweptBox: (CIntersectSweptBox *)v63,
         voxelBounds: (int (*)[2][3])tDelta) != 0 )
  {
    v26 = vecEnd->y;
    v27 = vecEnd->z;
    v28 = this->m_pVoxelHash;
    v29 = v28->m_nLevelShift;
    v30 = (float)(vecEnd->x + ray->m_Extents.x) - v28->m_vecVoxelOrigin.x;
    v31 = (float)(v26 - ray->m_Extents.y) - v28->m_vecVoxelOrigin.y;
    v32 = (float)(v26 + ray->m_Extents.y) - v28->m_vecVoxelOrigin.y;
    LODWORD(tMax[0]) = (int)(float)((float)(vecEnd->x - ray->m_Extents.x) - v28->m_vecVoxelOrigin.x) >> v29;
    v33 = (float)(v27 - ray->m_Extents.z) - v28->m_vecVoxelOrigin.z;
    v34 = (float)(v27 + ray->m_Extents.z) - v28->m_vecVoxelOrigin.z;
    LODWORD(tMax[1]) = (int)v31 >> v29;
    LODWORD(tMax[2]) = (int)v33 >> v29;
    nLastVoxel1[0] = (int)v30 >> v29;
    if ( SLODWORD(tMax[0]) >= *(int *)tDelta
      && SLODWORD(tMax[1]) >= *(int *)&tDelta[4]
      && SLODWORD(tMax[2]) >= *(int *)&tDelta[8]
      && nLastVoxel1[0] <= *(int *)&tDelta[12]
      && (int)v32 >> v29 <= *(int *)&tDelta[16]
      && (int)v34 >> v29 <= *(int *)&tDelta[20] )
    {
      return 1;
    }
    CVoxelHash::LeafListExtrudedRaySetup(
      this: this->m_pVoxelHash,
      ray,
      vecInvDelta,
      vecMin: (const Vector *)nLastVoxel3,
      vecMax: (const Vector *)&tDelta[100],
      iVoxelMin: (int *)tDelta,
      iVoxelMax: (int *)&tDelta[12],
      pStep: nLastVoxel2,
      pMin: tMax,
      pMax: (float *)nStep,
      pDelta: (float *)nLastVoxel1);
    v36 = 12 * (nLastVoxel2[0] > 0);
    v37 = *(_DWORD *)&tDelta[v36 + 48];
    intersectSweptBox.m_f4Extents.m128_i32[1] = *(_DWORD *)&tDelta[v36 + 24];
    v38 = *(_DWORD *)&tDelta[v36 + 72];
    nLastVoxel3[0] = v37;
    *(_DWORD *)&tDelta[100] = v38;
    v39 = 12 * (nLastVoxel2[1] > 0);
    v40 = *(_DWORD *)&tDelta[v39 + 28];
    v41 = *(_DWORD *)&tDelta[v39 + 52];
    *(_DWORD *)&tDelta[104] = *(_DWORD *)&tDelta[v39 + 76];
    intersectSweptBox.m_f4Extents.m128_i32[2] = v40;
    nLastVoxel3[1] = v41;
    v42 = 12 * (nLastVoxel2[2] > 0);
    v43 = *(_DWORD *)&tDelta[v42 + 32];
    v44 = *(_DWORD *)&tDelta[v42 + 56];
    v45 = *(float *)&tDelta[v42 + 80];
    intersectSweptBox.m_f4Extents.m128_i32[3] = v43;
    nLastVoxel3[2] = v44;
    v67 = v45;
LABEL_10:
    v46 = *(float *)&nStep[2];
    v47 = *(float *)&nStep[1];
    v48 = *(float *)nStep;
    while ( 1 )
    {
      if ( v48 >= 1.0 && v47 >= 1.0 && v46 >= 1.0 )
        return 1;
      if ( v47 <= v48 )
      {
        v49 = 1;
        if ( v46 > v47 )
          goto LABEL_19;
      }
      else if ( v46 > v48 )
      {
        v49 = 0;
        goto LABEL_19;
      }
      v49 = 2;
LABEL_19:
      if ( tMax[1] <= tMax[0] )
      {
        v50 = 1;
        if ( tMax[2] > tMax[1] )
          goto LABEL_24;
      }
      else if ( tMax[2] > tMax[0] )
      {
        v50 = 0;
        goto LABEL_24;
      }
      v50 = 2;
LABEL_24:
      v51 = tMax[v50];
      v52 = *(float *)&nStep[v49];
      if ( v52 <= v51 )
      {
        v56 = nLastVoxel2[v49];
        *(float *)&nStep[v49] = *(float *)&nLastVoxel1[v49] + v52;
        v57 = 4 * ((v56 > 0) + v49 + 2 * (v56 > 0));
        *(_DWORD *)&tDelta[v57] += v56;
        v58 = *(_DWORD *)&tDelta[v57];
        v59 = v58 >> 6;
        v60 = v58 >> 4;
        *(_DWORD *)&tDelta[v57 + 72] = v58 >> 6;
        *(_DWORD *)&tDelta[v57 + 48] = v58 >> 4;
        v61 = v58 >> 2;
        *(_DWORD *)&tDelta[v57 + 24] = v61;
        *(_DWORD *)&tDelta[96] = v59;
        endVoxelMin[1] = v60;
        if ( CVoxelHash::EnumerateElementsAlongRay_ExtrudedRaySlice(
               this: (CVoxelHash *)nStep[0],
               a2: (int)&endVoxelMin[2],
               listMask,
               pIterator,
               intersectSweptBox: (const CIntersectSweptBox *)v63,
               voxelMin: (int *)tDelta,
               voxelMax: (int *)&tDelta[12],
               iAxis: v49,
               pStep: nLastVoxel2) != 0 )
        {
          if ( intersectSweptBox.m_f4Extents.m128_i32[v49 + 1] == v61 )
            goto LABEL_36;
          endVoxelMin[0] = (int)nLastVoxel2;
          LODWORD(tMax[2]) = v49;
          LODWORD(tMax[1]) = &tDelta[36];
          LODWORD(tMax[0]) = &tDelta[24];
          nStep[2] = (int)v63;
          v62 = (CVoxelHash *)nStep[0];
          nStep[1] = (int)pIterator;
          LOWORD(nStep[0]) = listMask;
          intersectSweptBox.m_f4Extents.m128_i32[v49 + 1] = v61;
          if ( CVoxelHash::EnumerateElementsAlongRay_ExtrudedRaySlice(
                 this: v62 + 1,
                 a2: (int)&endVoxelMin[2],
                 listMask: nStep[0],
                 pIterator: (IPartitionEnumerator *)nStep[1],
                 intersectSweptBox: (const CIntersectSweptBox *)nStep[2],
                 voxelMin: (int *)LODWORD(tMax[0]),
                 voxelMax: (int *)LODWORD(tMax[1]),
                 iAxis: SLODWORD(tMax[2]),
                 pStep: (int *)endVoxelMin[0]) != 0 )
          {
LABEL_36:
            if ( nLastVoxel3[v49] == endVoxelMin[1]
              || (endVoxelMin[0] = (int)nLastVoxel2,
                  LODWORD(tMax[2]) = v49,
                  nLastVoxel3[v49] = endVoxelMin[1],
                  CVoxelHash::EnumerateElementsAlongRay_ExtrudedRaySlice(
                    this: (CVoxelHash *)(*(_DWORD *)(endVoxelMin[0] + 12) + 8368),
                    a2: (int)&endVoxelMin[2],
                    listMask,
                    pIterator,
                    intersectSweptBox: (const CIntersectSweptBox *)v63,
                    voxelMin: (int *)&tDelta[48],
                    voxelMax: (int *)&tDelta[60],
                    iAxis: SLODWORD(tMax[2]),
                    pStep: (int *)endVoxelMin[0]) != 0) )
            {
              if ( *(_DWORD *)&tDelta[4 * v49 + 100] == *(_DWORD *)&tDelta[96] )
                goto LABEL_10;
              *(_DWORD *)&tDelta[4 * v49 + 100] = *(_DWORD *)&tDelta[96];
              if ( CVoxelHash::EnumerateElementsAlongRay_ExtrudedRaySlice(
                     this: (CVoxelHash *)(nStep[0] + 12552),
                     a2: (int)&endVoxelMin[2],
                     listMask,
                     pIterator,
                     intersectSweptBox: (const CIntersectSweptBox *)v63,
                     voxelMin: (int *)&tDelta[72],
                     voxelMax: (int *)&tDelta[84],
                     iAxis: v49,
                     pStep: nLastVoxel2) != 0 )
                goto LABEL_10;
            }
          }
        }
        return 0;
      }
      v53 = nLastVoxel2[v50];
      tMax[v50] = *(float *)&nLastVoxel1[v50] + v51;
      v54 = 4 * ((v53 <= 0) + v50 + 2 * (v53 <= 0));
      *(_DWORD *)&tDelta[v54] += v53;
      v55 = *(_DWORD *)&tDelta[v54];
      *(_DWORD *)&tDelta[v54 + 24] = v55 >> 2;
      *(_DWORD *)&tDelta[v54 + 48] = v55 >> 4;
      *(_DWORD *)&tDelta[v54 + 72] = v55 >> 6;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DC020
// Name: public: int CUtlHashFixed<int,512,class CUtlHashFixedGenericHash<512>>::FastInsert(unsigned int,int const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *__thiscall CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::FastInsert(
        CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *this,
        unsigned int uiKey,
        int *data)
{
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> > *v5; // esi
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *result; // eax
  unsigned int uiKeya; // [esp+14h] [ebp+8h]

  v5 = &this->m_aBuckets[((unsigned __int16)(HIBYTE(uiKey)
                                           + 33
                                           * (BYTE2(uiKey) + 33 * (BYTE1(uiKey) + 33 * ((unsigned __int8)uiKey - 21846))))
                        ^ ((HIBYTE(uiKey)
                          + 33
                          * (BYTE2(uiKey)
                           + 33 * (BYTE1(uiKey) + 33 * ((unsigned int)(unsigned __int8)uiKey - 1431655766)))) >> 16))
                       & 0x1FF];
  uiKeya = (unsigned int)v5->m_pFirst;
  result = (CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *)MemAlloc_Alloc(nSize: 0x10u);
  if ( uiKeya != 0 )
  {
    result->pNext = (CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *)uiKeya;
    result->pPrev = *(CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t **)(uiKeya + 8);
    *(_DWORD *)(uiKeya + 8) = result;
    result->pPrev->pNext = result;
  }
  else
  {
    result->pPrev = result;
    result->pNext = result;
    v5->m_pFirst = result;
  }
  v5->m_pFirst = result;
  ++v5->m_nElems;
  result->elem.m_uiKey = uiKey;
  result->elem.m_Data = *data;
  ++this->m_nElements;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DC1C0
// Name: public: class CVarBitVec __near * CVoxelTree::BeginVisit(void)
// Source: json
//------------------------------------------------------------------------------
CVarBitVec *__thiscall CVoxelTree::BeginVisit(CVoxelTree *this)
{
  TSLNodeBase_t *v2; // eax
  TSLNodeBase_t *v3; // esi
  CVarBitVec *v4; // esi
  int m_nNextVisitBit; // eax
  unsigned __int8 *m_pInt; // eax
  CVarBitVec *pPrev; // [esp+Ch] [ebp-4h]

  pPrev = this->m_pVisits[(_DWORD)GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index)];
  v2 = CTSListBase::Pop(this: &this->m_FreeVisits);
  if ( v2 == nullptr )
  {
    v3 = (TSLNodeBase_t *)MemAlloc_Alloc(nSize: 0x10u);
    v2 = nullptr;
    if ( v3 != nullptr )
    {
      *((_DWORD *)&v3->Next + 1) = 0;
      v3[1].Next = nullptr;
      *((_DWORD *)&v3[1].Next + 1) = 0;
      v2 = v3;
    }
  }
  v4 = (CVarBitVec *)(&v2->Next + 1);
  m_nNextVisitBit = this->m_nNextVisitBit;
  if ( v4->m_numBits >= (unsigned __int16)m_nNextVisitBit )
  {
    m_pInt = (unsigned __int8 *)v4->m_pInt;
    if ( m_pInt != nullptr )
      memset(dst: m_pInt, value: 0, count: 4 * v4->m_numInts);
  }
  else
  {
    CVarBitVecBase<unsigned short>::Resize(this: v4, resizeNumBits: m_nNextVisitBit, bClearAll: true);
  }
  this->m_pVisits[(_DWORD)GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index)] = v4;
  return pPrev;
}

//------------------------------------------------------------------------------
// Address: 0x101DC320
// Name: public: void CVoxelHash::InsertIntoTree(unsigned short,union Voxel_t,union Voxel_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelHash::InsertIntoTree(
        CVoxelHash *this,
        unsigned __int16 hPartition,
        Voxel_t voxelMin,
        Voxel_t voxelMax)
{
  CVoxelHash *v4; // ebx
  CVoxelTree *m_pTree; // eax
  CUtlFixedLinkedList<LeafListData_t> *p_m_aLeafList; // edx
  int v7; // ecx
  int m_TreeId; // esi
  int v9; // eax
  Voxel_t v10; // edx
  unsigned int v11; // esi
  unsigned int v12; // ecx
  unsigned int v13; // eax
  unsigned int uiVoxel; // edi
  _WORD *v15; // esi
  __int16 v16; // ax
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *v17; // eax
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *v18; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *v19; // edi
  int v20; // eax
  unsigned int v21; // eax
  int v22; // [esp+8h] [ebp-30h]
  int v23; // [esp+Ch] [ebp-2Ch]
  CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *p_m_aEntityList; // [esp+10h] [ebp-28h]
  CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *p_m_aVoxelHash; // [esp+14h] [ebp-24h]
  int iEntity; // [esp+18h] [ebp-20h] BYREF
  int nListMask; // [esp+1Ch] [ebp-1Ch]
  unsigned int iX; // [esp+20h] [ebp-18h]
  unsigned int iY; // [esp+24h] [ebp-14h]
  CVoxelHash *v30; // [esp+28h] [ebp-10h]
  CUtlFixedLinkedList<LeafListData_t> *leafList; // [esp+2Ch] [ebp-Ch]
  unsigned int iZ; // [esp+30h] [ebp-8h]
  Voxel_t voxel; // [esp+34h] [ebp-4h]

  v4 = this;
  m_pTree = this->m_pTree;
  p_m_aLeafList = &m_pTree->m_aLeafList;
  v7 = (int)&m_pTree->m_pOwner->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * hPartition];
  m_TreeId = m_pTree->m_TreeId;
  v9 = *(unsigned __int16 *)(v7 + 36);
  leafList = p_m_aLeafList;
  *(_BYTE *)(m_TreeId + v7 + 39) = v4->m_nLevel;
  v10.bitsVoxel = voxelMax.bitsVoxel;
  v22 = m_TreeId;
  nListMask = v9;
  v11 = *(_WORD *)&voxelMin.bitsVoxel & 0x7FF;
  v30 = v4;
  v23 = v7;
  iX = v11;
  if ( v11 <= (*(_WORD *)&voxelMax.bitsVoxel & 0x7FFu) )
  {
    do
    {
      voxel.uiVoxel ^= ((unsigned __int16)v11 ^ *(_WORD *)&voxel.bitsVoxel) & 0x7FF;
      v12 = (voxelMin.uiVoxel >> 11) & 0x7FF;
      for ( iY = v12; v12 <= ((v10.uiVoxel >> 11) & 0x7FF); iY = v12 )
      {
        voxel.uiVoxel ^= (voxel.uiVoxel ^ (v12 << 11)) & 0x3FF800;
        v13 = voxelMin.uiVoxel >> 22;
        iZ = voxelMin.uiVoxel >> 22;
        if ( voxelMin.uiVoxel >> 22 <= v10.uiVoxel >> 22 )
        {
          while ( 1 )
          {
            voxel.uiVoxel = (v13 << 22) | voxel.uiVoxel & 0x3FFFFF;
            uiVoxel = voxel.uiVoxel;
            p_m_aEntityList = (CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *)&v4->m_aEntityList;
            v15 = (_WORD *)CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::AllocInternal(
                             this: &v4->m_aEntityList,
                             multilist: true);
            v16 = nListMask;
            *v15 = hPartition;
            iEntity = (int)v15;
            v15[1] = v16;
            p_m_aVoxelHash = &v4->m_aVoxelHash;
            v17 = CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::Find(this: &v4->m_aVoxelHash, uiKey: uiVoxel);
            v18 = v17;
            if ( v17 == (CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *)-1 )
            {
              v18 = CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::FastInsert(
                      this: p_m_aVoxelHash,
                      uiKey: uiVoxel,
                      data: &iEntity);
            }
            else
            {
              CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::LinkBefore(
                this: p_m_aEntityList,
                before: v17->elem.m_Data,
                elem: (int)v15);
              v18->elem.m_Data = (int)v15;
            }
            v19 = CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>>::AllocInternal(
                    this: leafList,
                    multilist: true);
            v19->m_pNext = (CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *)v18;
            v19->m_nBlockSize = (int)v15;
            v20 = *(_DWORD *)(v23 + 4 * v22 + 48);
            if ( v20 != 0 )
              CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>>::LinkBefore(
                this: leafList,
                before: v20,
                elem: (int)v19);
            v21 = iZ;
            *(_DWORD *)(v23 + 4 * v22 + 48) = v19;
            v10.bitsVoxel = voxelMax.bitsVoxel;
            v4 = v30;
            iZ = v21 + 1;
            if ( v21 + 1 > voxelMax.uiVoxel >> 22 )
              break;
            v13 = iZ;
          }
          v12 = iY;
          v11 = iX;
        }
        ++v12;
      }
      iX = ++v11;
    }
    while ( v11 <= (*(_WORD *)&v10.bitsVoxel & 0x7FFu) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DC4E0
// Name: public: void CVoxelHash::RenderAllObjectsInTree(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelHash::RenderAllObjectsInTree(CVoxelHash *this, float flTime)
{
  CVarBitVec *v3; // eax
  CVoxelTree *m_pTree; // esi
  CVarBitVec *v5; // eax
  CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *p_m_aVoxelHash; // ecx
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *m_pFirst; // edi
  int m_Data; // esi
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *pNext; // eax
  bool v10; // zf
  CVoxelTree *v11; // ebx
  void *v12; // eax
  CTSPool<CVarBitVec> *p_m_FreeVisits; // esi
  unsigned int **p_m_pInt; // edi
  TSLNodeBase_t *Next; // [esp-4h] [ebp-28h]
  TSLNodeBase_t *v16; // [esp-4h] [ebp-28h]
  int DepthAndSequence; // [esp+0h] [ebp-24h]
  int v18; // [esp+0h] [ebp-24h]
  CPartitionVisitor visitor; // [esp+10h] [ebp-14h] BYREF
  CVarBitVec *pPrevVisits; // [esp+18h] [ebp-Ch]
  int v21; // [esp+1Ch] [ebp-8h]
  CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *v22; // [esp+20h] [ebp-4h]
  void *flTimea; // [esp+2Ch] [ebp+8h]

  v3 = CVoxelTree::BeginVisit(this: this->m_pTree);
  m_pTree = this->m_pTree;
  pPrevVisits = v3;
  v5 = m_pTree->m_pVisits[(_DWORD)GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index)];
  visitor.m_iTree = m_pTree->m_TreeId;
  p_m_aVoxelHash = &this->m_aVoxelHash;
  visitor.m_pVisits = v5;
  v22 = &this->m_aVoxelHash;
  v21 = 512;
  do
  {
    if ( p_m_aVoxelHash->m_aBuckets[0].m_nElems != 0 )
    {
      m_pFirst = p_m_aVoxelHash->m_aBuckets[0].m_pFirst;
      if ( p_m_aVoxelHash->m_aBuckets[0].m_pFirst != nullptr )
      {
        do
        {
          m_Data = m_pFirst->elem.m_Data;
          if ( m_Data != 0 )
          {
            do
            {
              CVoxelHash::RenderObjectInVoxel(this, hPartition: *(_WORD *)m_Data, pVisitor: &visitor, flTime);
              m_Data = *(_DWORD *)(m_Data + 8);
            }
            while ( m_Data != 0 );
            p_m_aVoxelHash = v22;
          }
          pNext = m_pFirst->pNext;
          if ( pNext == p_m_aVoxelHash->m_aBuckets[0].m_pFirst )
            break;
          m_pFirst = m_pFirst->pNext;
        }
        while ( pNext != nullptr );
      }
    }
    p_m_aVoxelHash = (CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *)((char *)p_m_aVoxelHash + 8);
    v10 = v21-- == 1;
    v22 = p_m_aVoxelHash;
  }
  while ( !v10 );
  v11 = this->m_pTree;
  v12 = GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index);
  p_m_FreeVisits = &v11->m_FreeVisits;
  DepthAndSequence = v11->m_FreeVisits.m_Head.value32.DepthAndSequence;
  flTimea = v12;
  Next = v11->m_FreeVisits.m_Head.value.Next;
  p_m_pInt = &v11->m_pVisits[(_DWORD)v12][-1].m_pInt;
  *p_m_pInt = (unsigned int *)Next;
  if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                          a1: &v11->m_FreeVisits,
                          a2: p_m_pInt,
                          a3: DepthAndSequence + 65537,
                          a4: Next,
                          a5: DepthAndSequence) != 0 )
  {
    v11->m_pVisits[(_DWORD)flTimea] = pPrevVisits;
  }
  else
  {
    do
    {
      _mm_pause();
      v18 = v11->m_FreeVisits.m_Head.value32.DepthAndSequence;
      v16 = p_m_FreeVisits->m_Head.value.Next;
      *p_m_pInt = (unsigned int *)p_m_FreeVisits->m_Head.value.Next;
    }
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: &v11->m_FreeVisits,
                               a2: p_m_pInt,
                               a3: v18 + 65537,
                               a4: v16,
                               a5: v18) == 0 );
    v11->m_pVisits[(_DWORD)flTimea] = pPrevVisits;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DC600
// Name: public: void CVoxelHash::RenderObjectsInPlayerLeafs(class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelHash::RenderObjectsInPlayerLeafs(
        CVoxelHash *this,
        const Vector *vecPlayerMin,
        const Vector *vecPlayerMax,
        float flTime)
{
  float v5; // xmm3_4
  unsigned int m_nLevelShift; // ecx
  Voxel_t v7; // ebx
  int v8; // edx
  int v9; // esi
  int v10; // eax
  CVoxelTree *m_pTree; // ecx
  CVarBitVec *v12; // eax
  CVoxelTree *v13; // esi
  CVarBitVec *v14; // ecx
  Voxel_t v15; // eax
  unsigned int v16; // edx
  unsigned int v17; // esi
  unsigned int v18; // ecx
  unsigned int v19; // ebx
  unsigned int v20; // eax
  int v21; // ecx
  int v22; // edx
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *v23; // eax
  int i; // esi
  CVoxelTree *v25; // edi
  unsigned int v26; // eax
  CTSPool<CVarBitVec> *p_m_FreeVisits; // esi
  unsigned int **p_m_pInt; // ebx
  TSLNodeBase_t *Next; // [esp+8h] [ebp-38h]
  TSLNodeBase_t *v30; // [esp+8h] [ebp-38h]
  int DepthAndSequence; // [esp+Ch] [ebp-34h]
  int v32; // [esp+Ch] [ebp-34h]
  CPartitionVisitor visitor; // [esp+10h] [ebp-30h] BYREF
  Voxel_t voxelMin; // [esp+18h] [ebp-28h]
  unsigned int v35; // [esp+1Ch] [ebp-24h]
  unsigned int v36; // [esp+20h] [ebp-20h]
  int v37; // [esp+24h] [ebp-1Ch]
  int v38; // [esp+28h] [ebp-18h]
  unsigned int v39; // [esp+2Ch] [ebp-14h]
  unsigned int v40; // [esp+30h] [ebp-10h]
  CVarBitVec *pPrevVisits; // [esp+34h] [ebp-Ch]
  unsigned int iX; // [esp+38h] [ebp-8h]
  Voxel_t voxelMax; // [esp+3Ch] [ebp-4h]
  unsigned int iY; // [esp+48h] [ebp+8h]
  unsigned int iYa; // [esp+48h] [ebp+8h]
  const Vector *vecPlayerMaxa; // [esp+4Ch] [ebp+Ch]

  v5 = vecPlayerMin->y - this->m_vecVoxelOrigin.y;
  m_nLevelShift = this->m_nLevelShift;
  v7.uiVoxel = ((int)(float)(vecPlayerMin->x - this->m_vecVoxelOrigin.x) >> m_nLevelShift) & 0x7FF
             | ((((int)(float)(vecPlayerMin->z - this->m_vecVoxelOrigin.z) >> m_nLevelShift << 11)
               | ((int)v5 >> m_nLevelShift) & 0x7FF) << 11);
  v8 = (int)(float)(vecPlayerMax->y - this->m_vecVoxelOrigin.y) >> m_nLevelShift;
  v9 = (int)(float)(vecPlayerMax->z - this->m_vecVoxelOrigin.z) >> m_nLevelShift;
  v10 = (int)(float)(vecPlayerMax->x - this->m_vecVoxelOrigin.x) >> m_nLevelShift;
  m_pTree = this->m_pTree;
  voxelMin.bitsVoxel = v7.bitsVoxel;
  voxelMax.uiVoxel = v10 & 0x7FF | (((v9 << 11) | v8 & 0x7FF) << 11);
  v12 = CVoxelTree::BeginVisit(this: m_pTree);
  v13 = this->m_pTree;
  pPrevVisits = v12;
  v14 = v13->m_pVisits[(_DWORD)GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index)];
  v15.bitsVoxel = voxelMax.bitsVoxel;
  visitor.m_iTree = v13->m_TreeId;
  v16 = *(_WORD *)&v7.bitsVoxel & 0x7FF;
  v17 = *(_WORD *)&voxelMax.bitsVoxel & 0x7FF;
  visitor.m_pVisits = v14;
  iX = v16;
  v35 = v17;
  if ( v16 <= v17 )
  {
    v40 = (v7.uiVoxel >> 11) & 0x7FF;
    vecPlayerMaxa = (const Vector *)((voxelMax.uiVoxel >> 11) & 0x7FF);
    do
    {
      iY = v40;
      if ( v40 <= (unsigned int)vecPlayerMaxa )
      {
        v18 = v40;
        v19 = v7.uiVoxel >> 22;
        v20 = v15.uiVoxel >> 22;
        v39 = v19;
        v36 = v20;
        while ( 1 )
        {
          if ( v19 <= v20 )
          {
            v21 = v18 & 0x7FF;
            v22 = v16 & 0x7FF;
            v37 = v21;
            v38 = v22;
            while ( 1 )
            {
              v23 = CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::Find(
                      this: &this->m_aVoxelHash,
                      uiKey: v22 | ((v21 | (v19 << 11)) << 11));
              if ( v23 != (CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *)-1 )
              {
                for ( i = v23->elem.m_Data; i != 0; i = *(_DWORD *)(i + 8) )
                  CVoxelHash::RenderObjectInVoxel(this, hPartition: *(_WORD *)i, pVisitor: &visitor, flTime);
              }
              v20 = v36;
              if ( ++v19 > v36 )
                break;
              v22 = v38;
              v21 = v37;
            }
            v16 = iX;
            v18 = iY;
            v17 = v35;
          }
          iY = ++v18;
          if ( v18 > (unsigned int)vecPlayerMaxa )
            break;
          v19 = v39;
        }
        v7.bitsVoxel = voxelMin.bitsVoxel;
        v15.bitsVoxel = voxelMax.bitsVoxel;
      }
      iX = ++v16;
    }
    while ( v16 <= v17 );
  }
  v25 = this->m_pTree;
  v26 = (unsigned int)GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index);
  p_m_FreeVisits = &v25->m_FreeVisits;
  DepthAndSequence = v25->m_FreeVisits.m_Head.value32.DepthAndSequence;
  iYa = v26;
  Next = v25->m_FreeVisits.m_Head.value.Next;
  p_m_pInt = &v25->m_pVisits[v26][-1].m_pInt;
  *p_m_pInt = (unsigned int *)Next;
  if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                          a1: &v25->m_FreeVisits,
                          a2: p_m_pInt,
                          a3: DepthAndSequence + 65537,
                          a4: Next,
                          a5: DepthAndSequence) != 0 )
  {
    v25->m_pVisits[iYa] = pPrevVisits;
  }
  else
  {
    do
    {
      _mm_pause();
      v32 = v25->m_FreeVisits.m_Head.value32.DepthAndSequence;
      v30 = p_m_FreeVisits->m_Head.value.Next;
      *p_m_pInt = (unsigned int *)p_m_FreeVisits->m_Head.value.Next;
    }
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: &v25->m_FreeVisits,
                               a2: p_m_pInt,
                               a3: v32 + 65537,
                               a4: v30,
                               a5: v32) == 0 );
    v25->m_pVisits[iYa] = pPrevVisits;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DC850
// Name: public: virtual void CVoxelTree::Init(class CSpatialPartition __near *,int,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelTree::Init(
        CVoxelTree *this,
        CSpatialPartition *pOwner,
        int iTree,
        const Vector *worldmin,
        const Vector *worldmax)
{
  int v6; // ebx
  int i; // edi
  CUtlFixedLinkedList<LeafListData_t> *p_m_aLeafList; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t **p_m_pBlocks; // eax
  int v10; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *v11; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *v12; // edi
  int m_nBlockSize; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *m_pNext; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *v15; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *v16; // [esp-4h] [ebp-20h]
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *v17; // [esp-4h] [ebp-20h]
  _DWORD v18[2]; // [esp+Ch] [ebp-10h] BYREF
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *m_pBlocks; // [esp+14h] [ebp-8h] BYREF
  int v20; // [esp+18h] [ebp-4h]
  CSpatialPartition *pOwnera; // [esp+24h] [ebp+8h]

  v6 = 0;
  this->m_pOwner = pOwner;
  this->m_TreeId = iTree;
  memset(dst: (unsigned __int8 *)this->m_pVisits, value: 0, count: sizeof(this->m_pVisits));
  for ( i = 0; i < this->m_nLevelCount; ++v6 )
    CVoxelHash::Init(this: &this->m_pVoxelHash[v6], pPartition: this, worldmin, worldmax, nLevel: i++);
  p_m_aLeafList = &this->m_aLeafList;
  pOwnera = (CSpatialPartition *)p_m_aLeafList;
  if ( p_m_aLeafList->m_LastAlloc.m_pBlockHeader != nullptr || p_m_aLeafList->m_LastAlloc.m_nIndex != -1 )
  {
    if ( p_m_aLeafList->m_Memory.m_pBlocks != nullptr )
    {
      m_pBlocks = p_m_aLeafList->m_Memory.m_pBlocks;
      v20 = 0;
    }
    else
    {
      m_pBlocks = nullptr;
      v20 = -1;
    }
LABEL_8:
    p_m_pBlocks = &m_pBlocks;
LABEL_9:
    v10 = (int)p_m_pBlocks[1];
    v11 = *p_m_pBlocks;
    while ( 1 )
    {
      if ( v11 != nullptr )
      {
        if ( v10 >= 0 && v10 < v11->m_nBlockSize )
        {
          if ( &v11[2 * v10] == (CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *)-8
            || CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::IsIdxAfter(
                 this: (CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> > *)pOwnera,
                 i: (unsigned int)&v11[2 * v10 + 1],
                 it: (const CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::Iterator_t *)&pOwnera->m_aHandles.m_Memory.m_MemoryStack.m_alignment)
            || v11[2 * v10 + 2].m_pNext == &v11[2 * v10 + 1]
            && (CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *)v11[2 * v10 + 2].m_nBlockSize != &v11[2 * v10 + 1] )
          {
            p_m_aLeafList = (CUtlFixedLinkedList<LeafListData_t> *)pOwnera;
          }
          else
          {
            v11[2 * v10 + 2].m_pNext = &v11[2 * v10 + 1];
            v11[2 * v10 + 2].m_nBlockSize = *(_DWORD *)&pOwnera->m_aHandles.m_Memory.m_MemoryStack.m_bRegisteredAllocation;
            *(_DWORD *)&pOwnera->m_aHandles.m_Memory.m_MemoryStack.m_bRegisteredAllocation = &v11[2 * v10 + 1];
            p_m_aLeafList = (CUtlFixedLinkedList<LeafListData_t> *)pOwnera;
          }
        }
      }
      else if ( v10 == -1 )
      {
        break;
      }
      if ( v11 == p_m_aLeafList->m_LastAlloc.m_pBlockHeader && v10 == p_m_aLeafList->m_LastAlloc.m_nIndex )
        break;
      if ( v11 != nullptr && v10 >= 0 && (m_nBlockSize = v11->m_nBlockSize, v10 < m_nBlockSize) )
      {
        if ( ++v10 >= m_nBlockSize )
        {
          m_pNext = v11->m_pNext;
          if ( m_pNext != nullptr )
          {
            m_pBlocks = m_pNext;
            v20 = 0;
            goto LABEL_8;
          }
          v18[0] = 0;
          v18[1] = -1;
          p_m_pBlocks = (CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t **)v18;
          goto LABEL_9;
        }
      }
      else
      {
        v11 = nullptr;
        v10 = -1;
      }
    }
    p_m_aLeafList->m_Head = 0;
    p_m_aLeafList->m_Tail = 0;
    p_m_aLeafList->m_ElementCount = 0;
  }
  v12 = p_m_aLeafList->m_Memory.m_pBlocks;
  if ( p_m_aLeafList->m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v16 = v12;
      v12 = v12->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16);
    }
    while ( v12 != nullptr );
    p_m_aLeafList->m_Memory.m_pBlocks = nullptr;
    p_m_aLeafList->m_Memory.m_nAllocationCount = 0;
  }
  p_m_aLeafList->m_FirstFree = 0;
  p_m_aLeafList->m_NumAlloced = 0;
  p_m_aLeafList->m_LastAlloc.m_pBlockHeader = nullptr;
  p_m_aLeafList->m_LastAlloc.m_nIndex = -1;
  p_m_aLeafList->m_pElements = nullptr;
  v15 = p_m_aLeafList->m_Memory.m_pBlocks;
  if ( p_m_aLeafList->m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v17 = v15;
      v15 = v15->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v17);
    }
    while ( v15 != nullptr );
    p_m_aLeafList->m_Memory.m_pBlocks = nullptr;
    p_m_aLeafList->m_Memory.m_nAllocationCount = 0;
  }
  p_m_aLeafList->m_pElements = nullptr;
  p_m_aLeafList->m_Memory.m_nGrowSize = 512;
}

//------------------------------------------------------------------------------
// Address: 0x101DCAF0
// Name: public: void CVoxelTree::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelTree::Shutdown(CVoxelTree *this)
{
  CVoxelTree *v1; // esi
  CVoxelHash *v2; // ebx
  CUtlFixedLinkedList<CSpatialEntry> *p_m_aEntityList; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::Iterator_t *p_m_LastAlloc; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int> >::BlockHeader_t *m_pBlocks; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t **v6; // eax
  int v7; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *v8; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int> >::BlockHeader_t *v9; // esi
  CVoxelHash *v10; // eax
  CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *p_m_aVoxelHash; // esi
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *m_pFirst; // eax
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *pNext; // edi
  CVoxelTree *v14; // ecx
  int v15; // eax
  CVoxelHash *v16; // eax
  int m_nBlockSize; // eax
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *m_pNext; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int> >::BlockHeader_t *v19; // [esp-Ch] [ebp-44h]
  _DWORD v20[2]; // [esp+4h] [ebp-34h] BYREF
  _DWORD v21[2]; // [esp+Ch] [ebp-2Ch] BYREF
  _DWORD v22[2]; // [esp+14h] [ebp-24h] BYREF
  _DWORD v23[2]; // [esp+1Ch] [ebp-1Ch] BYREF
  CVoxelTree *v24; // [esp+24h] [ebp-14h]
  int i; // [esp+28h] [ebp-10h]
  unsigned int v26; // [esp+2Ch] [ebp-Ch]
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::Iterator_t *it; // [esp+30h] [ebp-8h]
  CVoxelHash *v28; // [esp+34h] [ebp-4h]

  v1 = this;
  v24 = this;
  CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>>::Purge(this: &this->m_aLeafList);
  i = 0;
  if ( v1->m_nLevelCount > 0 )
  {
    v26 = 0;
    while ( 1 )
    {
      v2 = &v1->m_pVoxelHash[v26 / 0x1058];
      p_m_aEntityList = &v2->m_aEntityList;
      p_m_LastAlloc = (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::Iterator_t *)&v2->m_aEntityList.m_LastAlloc;
      v28 = v2;
      it = (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::Iterator_t *)&v2->m_aEntityList.m_LastAlloc;
      if ( v2->m_aEntityList.m_LastAlloc.m_pBlockHeader != nullptr || v2->m_aEntityList.m_LastAlloc.m_nIndex != -1 )
      {
        m_pBlocks = p_m_aEntityList->m_Memory.m_pBlocks;
        if ( m_pBlocks != nullptr )
        {
          v23[0] = m_pBlocks;
          v23[1] = 0;
          v6 = (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t **)v23;
        }
        else
        {
          v22[0] = 0;
          v22[1] = -1;
          v6 = (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t **)v22;
        }
LABEL_9:
        v7 = (int)v6[1];
        v8 = *v6;
        while ( 1 )
        {
          if ( v8 != nullptr )
          {
            if ( v7 >= 0
              && v7 < v8->m_nBlockSize
              && (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *)((char *)v8 + 12 * v7) != (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *)-8
              && !CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int>>::IsIdxAfter(
                    this: (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > *)&v28->m_aEntityList,
                    i: (unsigned int)&v8[1] + 12 * v7,
                    it)
              && (*((CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t **)&v8[1].m_nBlockSize + 3 * v7) != (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *)((char *)&v8[1] + 12 * v7)
               || *(&v8[2].m_pNext + 3 * v7) == (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *)((char *)&v8[1] + 12 * v7)) )
            {
              v16 = v28;
              *(&v8[1].m_nBlockSize + 3 * v7) = (int)v8 + 12 * v7 + 8;
              *((_DWORD *)&v8[2].m_pNext + 3 * v7) = v16->m_aEntityList.m_FirstFree;
              v16->m_aEntityList.m_FirstFree = (int)&v8[1] + 12 * v7;
            }
          }
          else if ( v7 == -1 )
          {
            break;
          }
          if ( v8 == it->m_pBlockHeader && v7 == it->m_nIndex )
            break;
          if ( v8 != nullptr && v7 >= 0 && (m_nBlockSize = v8->m_nBlockSize, v7 < m_nBlockSize) )
          {
            if ( ++v7 >= m_nBlockSize )
            {
              m_pNext = v8->m_pNext;
              if ( m_pNext != nullptr )
              {
                v21[0] = m_pNext;
                v21[1] = 0;
                v6 = (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t **)v21;
              }
              else
              {
                v20[0] = 0;
                v20[1] = -1;
                v6 = (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t **)v20;
              }
              goto LABEL_9;
            }
          }
          else
          {
            v8 = nullptr;
            v7 = -1;
          }
        }
        v2 = v28;
        p_m_LastAlloc = it;
        p_m_aEntityList = &v28->m_aEntityList;
        v28->m_aEntityList.m_Head = 0;
        p_m_aEntityList->m_Tail = 0;
        p_m_aEntityList->m_ElementCount = 0;
      }
      v9 = p_m_aEntityList->m_Memory.m_pBlocks;
      if ( p_m_aEntityList->m_Memory.m_pBlocks != nullptr )
      {
        do
        {
          v19 = v9;
          v9 = v9->m_pNext;
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19);
        }
        while ( v9 != nullptr );
        v10 = v28;
        p_m_LastAlloc = it;
        v28->m_aEntityList.m_Memory.m_pBlocks = nullptr;
        v10->m_aEntityList.m_Memory.m_nAllocationCount = 0;
        v2 = v10;
      }
      v2->m_aEntityList.m_FirstFree = 0;
      v2->m_aEntityList.m_NumAlloced = 0;
      p_m_LastAlloc->m_pBlockHeader = nullptr;
      p_m_LastAlloc->m_nIndex = -1;
      v2->m_aEntityList.m_pElements = nullptr;
      p_m_aVoxelHash = &v2->m_aVoxelHash;
      for ( it = (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::Iterator_t *)512;
            it != nullptr;
            it = (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::Iterator_t *)((char *)it - 1) )
      {
        m_pFirst = p_m_aVoxelHash->m_aBuckets[0].m_pFirst;
        if ( p_m_aVoxelHash->m_aBuckets[0].m_pFirst != nullptr )
        {
          do
          {
            pNext = m_pFirst->pNext;
            free(pMem: m_pFirst);
            m_pFirst = pNext;
          }
          while ( pNext != p_m_aVoxelHash->m_aBuckets[0].m_pFirst );
        }
        p_m_aVoxelHash->m_aBuckets[0].m_pFirst = nullptr;
        p_m_aVoxelHash->m_aBuckets[0].m_nElems = 0;
        p_m_aVoxelHash = (CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *)((char *)p_m_aVoxelHash + 8);
      }
      v14 = v24;
      v26 += 4184;
      v15 = i + 1;
      v2->m_aVoxelHash.m_nElements = 0;
      i = v15;
      if ( v15 >= v14->m_nLevelCount )
        break;
      v1 = v14;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DCCE0
// Name: public: virtual void CVoxelTree::EnumerateElementsInBox(int,class Vector const __near &,class Vector const __near &,bool,class IPartitionEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelTree::EnumerateElementsInBox(
        CVoxelTree *this,
        int listMask,
        CVarBitVec *vecMins,
        const Vector *vecMaxs,
        bool coarseTest,
        IPartitionEnumerator *pIterator)
{
  double x; // st7
  double y; // st6
  double z; // st5
  double v10; // st2
  double v11; // st7
  double v12; // st3
  double v13; // st7
  double v14; // st3
  double v15; // st6
  double v16; // st4
  double v17; // st6
  double v18; // st3
  double v19; // st5
  double v20; // st4
  double v21; // st3
  double v22; // rtt
  double v23; // st3
  double v24; // st4
  double v25; // st7
  double v26; // st5
  double v27; // st7
  CVarBitVec *v28; // eax
  CThreadSpinRWLock *p_m_lock; // ecx
  signed __int32 m_i32; // edx
  CVoxelHash *m_pVoxelHash; // eax
  unsigned int m_nLevelShift; // ecx
  unsigned int v33; // esi
  unsigned int v34; // edi
  void *v35; // esi
  unsigned int v36; // edi
  unsigned int v37; // esi
  unsigned int v38; // edi
  unsigned int v39; // esi
  Vector mins; // [esp+4h] [ebp-18h] BYREF
  Vector maxs; // [esp+10h] [ebp-Ch] BYREF
  CVarBitVec *pPrevVisits; // [esp+28h] [ebp+Ch]

  if ( listMask != 0 )
  {
    x = s_PartitionMin.x;
    if ( *(float *)&vecMins->m_numBits >= (double)s_PartitionMin.x )
      x = *(float *)&vecMins->m_numBits;
    y = s_PartitionMin.y;
    if ( *(float *)&vecMins->m_iBitStringStorage >= (double)s_PartitionMin.y )
      y = *(float *)&vecMins->m_iBitStringStorage;
    z = s_PartitionMin.z;
    if ( *(float *)&vecMins->m_pInt >= (double)s_PartitionMin.z )
      z = *(float *)&vecMins->m_pInt;
    v10 = x;
    v11 = s_PartitionMax.x;
    if ( v10 <= s_PartitionMax.x )
      v11 = v10;
    v12 = v11;
    v13 = s_PartitionMax.x;
    mins.x = v12;
    v14 = y;
    v15 = s_PartitionMax.y;
    if ( v14 <= s_PartitionMax.y )
      v15 = v14;
    v16 = v15;
    v17 = s_PartitionMin.z;
    mins.y = v16;
    v18 = z;
    v19 = s_PartitionMax.z;
    if ( v18 <= s_PartitionMax.z )
      v19 = v18;
    mins.z = v19;
    v20 = s_PartitionMin.x;
    if ( vecMaxs->x >= (double)s_PartitionMin.x )
      v20 = vecMaxs->x;
    v21 = s_PartitionMin.y;
    if ( vecMaxs->y >= (double)s_PartitionMin.y )
      v21 = vecMaxs->y;
    if ( vecMaxs->z >= v17 )
      v17 = vecMaxs->z;
    v22 = v21;
    v23 = v20;
    v24 = v22;
    if ( v23 <= v13 )
      v13 = v23;
    maxs.x = v13;
    v25 = s_PartitionMax.y;
    if ( v24 <= s_PartitionMax.y )
      v25 = v24;
    v26 = v25;
    v27 = s_PartitionMax.z;
    maxs.y = v26;
    if ( v17 <= s_PartitionMax.z )
      v27 = v17;
    maxs.z = v27;
    v28 = CVoxelTree::BeginVisit(this);
    p_m_lock = &this->m_lock;
    pPrevVisits = v28;
    if ( (this->m_lock.m_lockInfo.m_i32 & 0x10000) != 0
      || (m_i32 = (unsigned __int16)p_m_lock->m_lockInfo.m_i32,
          _InterlockedCompareExchange((volatile signed __int32 *)p_m_lock, m_i32 + 1, m_i32) != m_i32) )
    {
      CThreadSpinRWLock::SpinLockForRead(this: p_m_lock);
    }
    m_pVoxelHash = this->m_pVoxelHash;
    m_nLevelShift = m_pVoxelHash->m_nLevelShift;
    v33 = ((int)(float)(mins.x - m_pVoxelHash->m_vecVoxelOrigin.x) >> m_nLevelShift) & 0x7FF
        | ((((int)(float)(mins.y - m_pVoxelHash->m_vecVoxelOrigin.y) >> m_nLevelShift) & 0x7FF
          | ((int)(float)(mins.z - m_pVoxelHash->m_vecVoxelOrigin.z) >> m_nLevelShift << 11)) << 11);
    v34 = ((int)(float)(maxs.x - m_pVoxelHash->m_vecVoxelOrigin.x) >> m_nLevelShift) & 0x7FF
        | ((((int)(float)(maxs.z - m_pVoxelHash->m_vecVoxelOrigin.z) >> m_nLevelShift << 11)
          | ((int)(float)(maxs.y - m_pVoxelHash->m_vecVoxelOrigin.y) >> m_nLevelShift) & 0x7FF) << 11);
    if ( CVoxelHash::EnumerateElementsInBox(
           this: m_pVoxelHash,
           listMask,
           vmin: (Voxel_t)v33,
           vmax: (Voxel_t)v34,
           &mins,
           &maxs,
           pIterator)
      && (v36 = (v34 >> 2) & 0x3FCFF9FF,
          v37 = (v33 >> 2) & 0x3FCFF9FF,
          CVoxelHash::EnumerateElementsInBox(
            this: this->m_pVoxelHash + 1,
            listMask,
            vmin: (Voxel_t)v37,
            vmax: (Voxel_t)v36,
            &mins,
            &maxs,
            pIterator)) )
    {
      v38 = (v36 >> 2) & 0x3FCFF9FF;
      v39 = (v37 >> 2) & 0x3FCFF9FF;
      if ( CVoxelHash::EnumerateElementsInBox(
             this: this->m_pVoxelHash + 2,
             listMask,
             vmin: (Voxel_t)v39,
             vmax: (Voxel_t)v38,
             &mins,
             &maxs,
             pIterator) )
      {
        CVoxelHash::EnumerateElementsInBox(
          this: this->m_pVoxelHash + 3,
          listMask,
          vmin: (Voxel_t)((v39 >> 2) & 0x3FCFF9FF),
          vmax: (Voxel_t)((v38 >> 2) & 0x3FCFF9FF),
          &mins,
          &maxs,
          pIterator);
      }
      _InterlockedExchangeAdd((volatile signed __int32 *)&this->m_lock, 0xFFFFFFFF);
      CVoxelTree::EndVisit(this, pPrev: pPrevVisits);
    }
    else
    {
      _InterlockedExchangeAdd((volatile signed __int32 *)&this->m_lock, 0xFFFFFFFF);
      v35 = GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index);
      CTSListBase::Push(this: &this->m_FreeVisits, pNode: (TSLNodeBase_t *)&this->m_pVisits[(_DWORD)v35][-1].m_pInt);
      this->m_pVisits[(_DWORD)v35] = pPrevVisits;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DD010
// Name: public: virtual void CVoxelTree::EnumerateElementsAlongRay(int,struct Ray_t const __near &,bool,class IPartitionEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CVoxelTree::EnumerateElementsAlongRay(
        CVoxelTree *this@<ecx>,
        float a2@<ebp>,
        int listMask,
        const Ray_t *ray,
        int coarseTest,
        IPartitionEnumerator *pIterator)
{
  char *v6; // esi
  int m_nValue; // eax
  float x; // xmm0_4
  float y; // xmm2_4
  float z; // xmm6_4
  void (__stdcall *v11)(int, Vector *, _BYTE *, int, IPartitionEnumerator *, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // eax
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm6_4
  float v19; // xmm2_4
  bool v20; // al
  float v21; // esi
  CVarBitVec *v22; // eax
  CThreadSpinRWLock::LockInfo_t v23; // ecx
  signed __int32 v24; // ecx
  void *v25; // edi
  int v26; // [esp-1Ch] [ebp-ACh]
  int v27; // [esp-18h] [ebp-A8h]
  int v28; // [esp-14h] [ebp-A4h]
  int v29; // [esp-10h] [ebp-A0h]
  _BYTE v30[92]; // [esp-Ch] [ebp-9Ch] OVERLAPPED BYREF
  float v31; // [esp+50h] [ebp-40h]
  float v32; // [esp+54h] [ebp-3Ch]
  Vector vecMax; // [esp+58h] [ebp-38h] BYREF
  Vector vecMin; // [esp+64h] [ebp-2Ch] BYREF
  Vector vecInvDelta; // [esp+70h] [ebp-20h] BYREF
  Vector vecEnd; // [esp+7Ch] [ebp-14h] BYREF
  CVarBitVec *pPrevVisits; // [esp+88h] [ebp-8h]
  CVarBitVec *retaddr; // [esp+90h] [ebp+0h]

  vecEnd.z = a2;
  pPrevVisits = retaddr;
  LODWORD(vecEnd.x) = this;
  if ( (_S1_18 & 1) == 0 )
  {
    _S1_18 |= 1u;
    bIsPublic = GetSteamUniverse() == k_EUniversePublic;
  }
  if ( !bIsPublic
    && think_trace_limit.m_pParent != nullptr
    && think_trace_limit.m_pParent->m_Value.m_nValue != 0
    && (int)GenericThreadLocals::CThreadLocalBase::Get(this: &g_DebugTracesRemainingBeforeTrap) > 0 )
  {
    v6 = (char *)GenericThreadLocals::CThreadLocalBase::Get(this: &g_DebugTracesRemainingBeforeTrap) - 1;
    GenericThreadLocals::CThreadLocalBase::Set(this: &g_DebugTracesRemainingBeforeTrap, a2: v6);
    if ( (int)v6 <= 0 && (unsigned __int8)_Plat_IsInDebugSession() != 0 )
    {
      if ( (unsigned __int8)_Plat_IsInDebugSession() != 0 )
        __debugbreak();
      if ( think_trace_limit.m_pParent != nullptr )
      {
        m_nValue = think_trace_limit.m_pParent->m_Value.m_nValue;
        if ( m_nValue < 0 )
          GenericThreadLocals::CThreadLocalBase::Set(this: &g_DebugTracesRemainingBeforeTrap, a2: (void *)-m_nValue);
      }
    }
  }
  if ( !ray->m_IsSwept )
  {
    x = ray->m_Extents.x;
    y = ray->m_Start.y;
    z = ray->m_Start.z;
    v11 = *(void (__stdcall **)(int, Vector *, _BYTE *, int, IPartitionEnumerator *, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)LODWORD(vecEnd.x) + 12);
    v12 = ray->m_Start.x - x;
    v13 = x + ray->m_Start.x;
    vecMax.x = v12;
    v14 = ray->m_Extents.y;
    v15 = y - v14;
    v16 = v14 + ray->m_Start.y;
    vecMax.y = v15;
    v17 = ray->m_Extents.z;
    v18 = z - v17;
    v19 = v17 + ray->m_Start.z;
    vecMax.z = v18;
    *(float *)&v30[88] = v13;
    v31 = v16;
    v32 = v19;
    v11(
      a1: listMask,
      a2: &vecMax,
      a3: &v30[88],
      a4: coarseTest,
      a5: pIterator,
      a6: v26,
      a7: v27,
      a8: v28,
      a9: v29,
      a10: *(_DWORD *)v30,
      a11: *(_DWORD *)&v30[4],
      a12: *(_DWORD *)&v30[8],
      a13: *(_DWORD *)&v30[12],
      a14: *(_DWORD *)&v30[16],
      a15: *(_DWORD *)&v30[20],
      a16: *(_DWORD *)&v30[24],
      a17: *(_DWORD *)&v30[28],
      a18: *(_DWORD *)&v30[32],
      a19: *(_DWORD *)&v30[36],
      a20: *(_DWORD *)&v30[40],
      a21: *(_DWORD *)&v30[44],
      a22: *(_DWORD *)&v30[48],
      a23: *(_DWORD *)&v30[52],
      a24: *(_DWORD *)&v30[56],
      a25: *(_DWORD *)&v30[60],
      a26: *(_DWORD *)&v30[64],
      a27: *(_DWORD *)&v30[68],
      a28: *(_DWORD *)&v30[72],
      a29: *(_DWORD *)&v30[76],
      a30: *(_DWORD *)&v30[80],
      a31: *(_DWORD *)&v30[84]);
    return;
  }
  if ( listMask != 0 )
  {
    *(Ray_t *)v30 = *ray;
    vecInvDelta.x = *(float *)&v30[16] + *(float *)v30;
    vecInvDelta.y = *(float *)&v30[20] + *(float *)&v30[4];
    vecInvDelta.z = *(float *)&v30[24] + *(float *)&v30[8];
    HIBYTE(vecEnd.y) = IsPointInBox(pt: &ray->m_Start, boxMin: &s_PartitionMin, boxMax: &s_PartitionMax);
    v20 = IsPointInBox(pt: &vecInvDelta, boxMin: &s_PartitionMin, boxMax: &s_PartitionMax);
    if ( HIBYTE(vecEnd.y) != 0 )
    {
      if ( !v20 )
        ClampEndPoint(ray: (Ray_t *)v30, vecEnd: &vecInvDelta);
    }
    else
    {
      if ( !v20 )
        return;
      ClampStartPoint(ray: (Ray_t *)v30, vecEnd: &vecInvDelta);
    }
    if ( *(float *)&v30[16] == 0.0 )
      vecMin.x = 3.4028235e38;
    else
      vecMin.x = 1.0 / *(float *)&v30[16];
    if ( *(float *)&v30[20] == 0.0 )
      vecMin.y = 3.4028235e38;
    else
      vecMin.y = 1.0 / *(float *)&v30[20];
    if ( *(float *)&v30[24] == 0.0 )
      vecMin.z = 3.4028235e38;
    else
      vecMin.z = 1.0 / *(float *)&v30[24];
    v21 = vecEnd.x;
    v22 = CVoxelTree::BeginVisit(this: (CVoxelTree *)LODWORD(vecEnd.x));
    v23 = *(CThreadSpinRWLock::LockInfo_t *)(LODWORD(v21) + 232);
    LODWORD(vecEnd.x) = v22;
    if ( (v23.m_i32 & 0x10000) != 0
      || (v24 = (unsigned __int16)*(_DWORD *)(LODWORD(v21) + 232),
          _InterlockedCompareExchange((volatile signed __int32 *)(LODWORD(v21) + 232), v24 + 1, v24) != v24) )
    {
      CThreadSpinRWLock::SpinLockForRead(this: (CThreadSpinRWLock *)(LODWORD(v21) + 232));
    }
    if ( ray->m_IsRay )
      CVoxelTree::EnumerateElementsAlongRay_Ray(
        this: (CVoxelTree *)LODWORD(v21),
        a2: (Voxel_t)&vecEnd.z,
        listMask,
        ray: (const Ray_t *)v30,
        vecInvDelta: &vecMin,
        vecEnd: &vecInvDelta,
        pIterator);
    else
      CVoxelTree::EnumerateElementsAlongRay_ExtrudedRay(
        this: (CVoxelTree *)LODWORD(v21),
        a2: (int)&vecEnd.z,
        listMask,
        ray: (const Ray_t *)v30,
        vecInvDelta: &vecMin,
        vecEnd: &vecInvDelta,
        pIterator);
    _InterlockedExchangeAdd((volatile signed __int32 *)(LODWORD(v21) + 232), 0xFFFFFFFF);
    v25 = GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index);
    CTSListBase::Push(
      this: (CTSListBase *)(LODWORD(v21) + 224),
      pNode: (TSLNodeBase_t *)(*(_DWORD *)(LODWORD(v21) + 4 * (_DWORD)v25 + 64) - 4));
    *(float *)(LODWORD(v21) + 4 * (_DWORD)v25 + 64) = vecEnd.x;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DD340
// Name: public: virtual void CVoxelTree::RenderAllObjectsInTree(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelTree::RenderAllObjectsInTree(CVoxelTree *this, float flTime)
{
  CThreadSpinRWLock *p_m_lock; // ebx
  signed __int32 m_i32; // ecx
  int v5; // edi
  int v6; // ebx
  IMDLCache *cacheCriticalSection; // [esp+10h] [ebp-8h]

  cacheCriticalSection = g_pMDLCache;
  ((void (*)(void))g_pMDLCache->BeginLock)();
  p_m_lock = &this->m_lock;
  if ( (this->m_lock.m_lockInfo.m_i32 & 0x10000) != 0
    || (m_i32 = (unsigned __int16)p_m_lock->m_lockInfo.m_i32,
        _InterlockedCompareExchange((volatile signed __int32 *)p_m_lock, m_i32 + 1, m_i32) != m_i32) )
  {
    CThreadSpinRWLock::SpinLockForRead(this: &this->m_lock);
  }
  v5 = 0;
  if ( this->m_nLevelCount > 0 )
  {
    v6 = 0;
    do
    {
      CVoxelHash::RenderAllObjectsInTree(this: &this->m_pVoxelHash[v6], flTime);
      ++v5;
      ++v6;
    }
    while ( v5 < this->m_nLevelCount );
    p_m_lock = &this->m_lock;
  }
  _InterlockedExchangeAdd((volatile signed __int32 *)p_m_lock, 0xFFFFFFFF);
  cacheCriticalSection->EndLock(this: cacheCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x101DD3E0
// Name: public: virtual void CVoxelTree::RenderObjectsInPlayerLeafs(class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelTree::RenderObjectsInPlayerLeafs(
        CVoxelTree *this,
        const Vector *vecPlayerMin,
        const Vector *vecPlayerMax,
        float flTime)
{
  CThreadSpinRWLock *p_m_lock; // ebx
  signed __int32 m_i32; // ecx
  int v7; // edi
  int v8; // ebx
  IMDLCache *cacheCriticalSection; // [esp+10h] [ebp-8h]

  cacheCriticalSection = g_pMDLCache;
  ((void (*)(void))g_pMDLCache->BeginLock)();
  p_m_lock = &this->m_lock;
  if ( (this->m_lock.m_lockInfo.m_i32 & 0x10000) != 0
    || (m_i32 = (unsigned __int16)p_m_lock->m_lockInfo.m_i32,
        _InterlockedCompareExchange((volatile signed __int32 *)p_m_lock, m_i32 + 1, m_i32) != m_i32) )
  {
    CThreadSpinRWLock::SpinLockForRead(this: &this->m_lock);
  }
  v7 = 0;
  if ( this->m_nLevelCount > 0 )
  {
    v8 = 0;
    do
    {
      CVoxelHash::RenderObjectsInPlayerLeafs(this: &this->m_pVoxelHash[v8], vecPlayerMin, vecPlayerMax, flTime);
      ++v7;
      ++v8;
    }
    while ( v7 < this->m_nLevelCount );
    p_m_lock = &this->m_lock;
  }
  _InterlockedExchangeAdd((volatile signed __int32 *)p_m_lock, 0xFFFFFFFF);
  cacheCriticalSection->EndLock(this: cacheCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x101DD490
// Name: public: virtual void CVoxelTree::DrawDebugOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelTree::DrawDebugOverlays(CVoxelTree *this)
{
  CThreadSpinRWLock *p_m_lock; // edi
  signed __int32 m_i32; // ecx
  int v4; // esi
  int v5; // edi
  CThreadSpinRWLock *v6; // [esp+10h] [ebp-8h]
  int nLevel; // [esp+14h] [ebp-4h]

  if ( r_partition_level.m_pParent != nullptr )
  {
    nLevel = r_partition_level.m_pParent->m_Value.m_nValue;
    if ( nLevel < 0 )
      return;
  }
  else
  {
    nLevel = 0;
  }
  p_m_lock = &this->m_lock;
  v6 = &this->m_lock;
  if ( (this->m_lock.m_lockInfo.m_i32 & 0x10000) != 0
    || (m_i32 = (unsigned __int16)p_m_lock->m_lockInfo.m_i32,
        _InterlockedCompareExchange((volatile signed __int32 *)p_m_lock, m_i32 + 1, m_i32) != m_i32) )
  {
    CThreadSpinRWLock::SpinLockForRead(this: &this->m_lock);
  }
  v4 = 0;
  if ( this->m_nLevelCount > 0 )
  {
    v5 = 0;
    do
    {
      if ( nLevel == v4 )
      {
        CVoxelHash::RenderGrid(this: &this->m_pVoxelHash[v5]);
        CVoxelHash::RenderAllObjectsInTree(this: &this->m_pVoxelHash[v5], flTime: 0.0099999998);
      }
      ++v4;
      ++v5;
    }
    while ( v4 < this->m_nLevelCount );
    p_m_lock = v6;
  }
  _InterlockedExchangeAdd((volatile signed __int32 *)p_m_lock, 0xFFFFFFFF);
}

//------------------------------------------------------------------------------
// Address: 0x101DD540
// Name: public: CTSPool<class CVarBitVec>::~CTSPool<class CVarBitVec>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSPool<CVarBitVec>::~CTSPool<CVarBitVec>(CTSPool<CVarBitVec> *this)
{
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax

  while ( 1 )
  {
    Next = this->m_Head.value.Next;
    DepthAndSequence = this->m_Head.value32.DepthAndSequence;
    if ( this->m_Head.value.Next == nullptr )
      break;
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: this,
                               a2: Next->Next,
                               a3: DepthAndSequence - 1,
                               a4: Next,
                               a5: DepthAndSequence) == 0 )
    {
      _mm_pause();
      Next = this->m_Head.value.Next;
      DepthAndSequence = this->m_Head.value32.DepthAndSequence;
      if ( this->m_Head.value.Next == nullptr )
        goto LABEL_4;
    }
    if ( *((_WORD *)&Next->Next + 3) > 1u )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)&Next[1].Next + 1));
    *((_DWORD *)&Next[1].Next + 1) = 0;
    free(pMem: Next);
  }
LABEL_4:
  CTSListBase::Detach(this);
}

//------------------------------------------------------------------------------
// Address: 0x101DD6F0
// Name: public: CVoxelHash::CVoxelHash(void)
// Source: json
//------------------------------------------------------------------------------
CVoxelHash *__thiscall CVoxelHash::CVoxelHash(CVoxelHash *this)
{
  CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *p_m_aVoxelHash; // ecx
  CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *v3; // eax
  int i; // edx

  p_m_aVoxelHash = &this->m_aVoxelHash;
  v3 = p_m_aVoxelHash;
  for ( i = 511; i >= 0; --i )
  {
    v3->m_aBuckets[0].m_pFirst = nullptr;
    v3->m_aBuckets[0].m_nElems = 0;
    v3 = (CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *)((char *)v3 + 8);
  }
  CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::RemoveAll(this: p_m_aVoxelHash);
  this->m_aEntityList.m_Memory.m_pBlocks = nullptr;
  this->m_aEntityList.m_Memory.m_nAllocationCount = 0;
  this->m_aEntityList.m_Memory.m_nGrowSize = 0;
  this->m_aEntityList.m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_aEntityList.m_LastAlloc.m_nIndex = -1;
  this->m_aEntityList.m_Head = 0;
  this->m_aEntityList.m_Tail = 0;
  this->m_aEntityList.m_FirstFree = 0;
  this->m_aEntityList.m_ElementCount = 0;
  this->m_aEntityList.m_NumAlloced = 0;
  this->m_aEntityList.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101DD760
// Name: public: CVoxelHash::~CVoxelHash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelHash::~CVoxelHash(CVoxelHash *this)
{
  CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *p_m_aEntityList; // edi
  CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> > *p_m_aVoxelHash; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::BlockHeader_t *v5; // [esp-4h] [ebp-10h]

  p_m_aEntityList = (CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *)&this->m_aEntityList;
  CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::Purge(this: (CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *)&this->m_aEntityList);
  p_m_aVoxelHash = &this->m_aVoxelHash;
  CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::RemoveAll(this: &this->m_aVoxelHash);
  CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::RemoveAll(this: p_m_aEntityList);
  m_pBlocks = p_m_aEntityList->m_Memory.m_pBlocks;
  if ( p_m_aEntityList->m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v5 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
    }
    while ( m_pBlocks != nullptr );
    p_m_aEntityList->m_Memory.m_pBlocks = nullptr;
    p_m_aEntityList->m_Memory.m_nAllocationCount = 0;
  }
  CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::~CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>(this: p_m_aVoxelHash);
}

//------------------------------------------------------------------------------
// Address: 0x101DD7C0
// Name: public: void CVoxelHash::RemoveFromTree(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelHash::RemoveFromTree(CVoxelHash *this, unsigned __int16 hPartition)
{
  CVoxelTree *m_pTree; // eax
  int v3; // esi
  CUtlFixedLinkedList<LeafListData_t> *p_m_aLeafList; // edx
  int m_TreeId; // eax
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t **v6; // edi
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *v7; // edx
  int v8; // ebx
  unsigned int v9; // esi
  int m_Data; // eax
  int v11; // eax
  CUtlFixedLinkedList<CSpatialEntry> *p_m_aEntityList; // ebx
  int v13; // eax
  int v14; // eax
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *v15; // eax
  CUtlFixedLinkedList<LeafListData_t> *v16; // eax
  CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *v17; // ecx
  EntityInfo_t *data; // [esp+8h] [ebp-10h]
  int treeId; // [esp+Ch] [ebp-Ch]
  CVoxelHash *v20; // [esp+10h] [ebp-8h]
  int iNext; // [esp+14h] [ebp-4h]
  CUtlFixedLinkedList<LeafListData_t> *leafList; // [esp+20h] [ebp+8h]

  m_pTree = this->m_pTree;
  v3 = (int)&m_pTree->m_pOwner->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * hPartition];
  p_m_aLeafList = &m_pTree->m_aLeafList;
  m_TreeId = m_pTree->m_TreeId;
  v6 = *(CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t ***)(v3 + 4 * m_TreeId + 48);
  v20 = this;
  data = (EntityInfo_t *)v3;
  leafList = p_m_aLeafList;
  treeId = m_TreeId;
  if ( v6 != nullptr )
  {
    do
    {
      v7 = *v6;
      v8 = (int)v6[3];
      iNext = v8;
      if ( *v6 == (CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *)-1 )
      {
        v6 = (CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t **)v6[3];
      }
      else
      {
        v9 = (unsigned int)v6[1];
        m_Data = v7->elem.m_Data;
        if ( m_Data == v9 )
        {
          v11 = *(_DWORD *)(m_Data + 8);
          if ( v11 != 0 )
          {
            v7->elem.m_Data = v11;
          }
          else
          {
            CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512>>::Remove(this: &this->m_aVoxelHash, hHash: v7);
            this = v20;
          }
        }
        p_m_aEntityList = &this->m_aEntityList;
        if ( v9 != 0
          && !CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int>>::IsIdxAfter(
                this: (CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > *)&this->m_aEntityList,
                i: v9,
                it: (const CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> >::Iterator_t *)&this->m_aEntityList.m_LastAlloc) )
        {
          v13 = *(_DWORD *)(v9 + 4);
          if ( v13 != v9 )
          {
            if ( v13 != 0 )
              *(_DWORD *)(v13 + 8) = *(_DWORD *)(v9 + 8);
            else
              p_m_aEntityList->m_Head = *(_DWORD *)(v9 + 8);
            v14 = *(_DWORD *)(v9 + 8);
            if ( v14 != 0 )
              *(_DWORD *)(v14 + 4) = *(_DWORD *)(v9 + 4);
            else
              p_m_aEntityList->m_Tail = *(_DWORD *)(v9 + 4);
            *(_DWORD *)(v9 + 8) = v9;
            *(_DWORD *)(v9 + 4) = v9;
            --p_m_aEntityList->m_ElementCount;
          }
        }
        *(_DWORD *)(v9 + 8) = p_m_aEntityList->m_FirstFree;
        p_m_aEntityList->m_FirstFree = v9;
        if ( CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::IsIdxAfter(
               this: &leafList->m_Memory,
               i: (unsigned int)v6,
               it: &leafList->m_LastAlloc)
          || (v15 = v6[2]) == (CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *)v6 )
        {
          v16 = leafList;
        }
        else
        {
          if ( v15 != nullptr )
          {
            v15->pNext = v6[3];
            v16 = leafList;
          }
          else
          {
            v16 = leafList;
            leafList->m_Head = (int)v6[3];
          }
          v17 = v6[3];
          if ( v17 != nullptr )
            v17->pPrev = v6[2];
          else
            v16->m_Tail = (int)v6[2];
          v6[3] = (CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *)v6;
          v6[2] = (CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *)v6;
          --v16->m_ElementCount;
        }
        v3 = (int)data;
        this = v20;
        v6[3] = (CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t *)v16->m_FirstFree;
        v16->m_FirstFree = (int)v6;
        v6 = (CUtlPtrLinkedList<CUtlHashFixed<int,512,CUtlHashFixedGenericHash<512> >::HashFixedData_t_<int> >::Node_t **)iNext;
        m_TreeId = treeId;
        v8 = iNext;
      }
    }
    while ( v8 != 0 );
  }
  *(_DWORD *)(v3 + 4 * m_TreeId + 48) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DD930
// Name: public: CVoxelTree::CVoxelTree(void)
// Source: json
//------------------------------------------------------------------------------
CVoxelTree *__thiscall CVoxelTree::CVoxelTree(CVoxelTree *this)
{
  int m_nLevelCount; // edx
  int v3; // edi
  int v4; // ecx
  int *v5; // eax
  CVoxelHash *v6; // eax
  int v7; // edi
  CVoxelHash *v8; // ebx
  unsigned __int16 *m_pMemory; // eax
  IMemAlloc_vtbl *v10; // edx
  unsigned __int16 *v11; // eax
  CVoxelHash *v13; // [esp+8h] [ebp-4h]

  this->__vftable = (CVoxelTree_vtbl *)&CVoxelTree::`vftable';
  this->m_pVoxelHash = nullptr;
  this->m_aLeafList.m_Memory.m_pBlocks = nullptr;
  this->m_aLeafList.m_Memory.m_nAllocationCount = 0;
  this->m_aLeafList.m_Memory.m_nGrowSize = 0;
  this->m_aLeafList.m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_aLeafList.m_LastAlloc.m_nIndex = -1;
  this->m_aLeafList.m_Head = 0;
  this->m_aLeafList.m_Tail = 0;
  this->m_aLeafList.m_FirstFree = 0;
  this->m_aLeafList.m_ElementCount = 0;
  this->m_aLeafList.m_NumAlloced = 0;
  this->m_aLeafList.m_pElements = nullptr;
  this->m_pOwner = nullptr;
  this->m_AvailableVisitBits.m_Memory.m_pMemory = nullptr;
  this->m_AvailableVisitBits.m_Memory.m_nAllocationCount = 0;
  this->m_AvailableVisitBits.m_Memory.m_nGrowSize = 0;
  this->m_AvailableVisitBits.m_Size = 0;
  this->m_AvailableVisitBits.m_pElements = nullptr;
  this->m_nNextVisitBit = 0;
  if ( (((_BYTE)this - 32) & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  this->m_FreeVisits.m_Head.value.Next = nullptr;
  this->m_FreeVisits.m_Head.value32.DepthAndSequence = 0;
  this->m_lock.m_lockInfo.m_i32 = 0;
  this->m_lock.m_writerId = 0;
  for ( this->m_nLevelCount = 0; ; this->m_nLevelCount = m_nLevelCount + 1 )
  {
    m_nLevelCount = this->m_nLevelCount;
    if ( 128 >> (2 * m_nLevelCount) <= 2 )
      break;
  }
  v3 = ++this->m_nLevelCount;
  v4 = (4184 * (unsigned __int64)(unsigned int)v3) >> 32 != 0 ? -1 : 4184 * v3;
  v5 = (int *)MemAlloc_Alloc(nSize: __CFADD__(v4, 4) ? -1 : v4 + 4);
  if ( v5 != nullptr )
  {
    *v5 = v3;
    v6 = (CVoxelHash *)(v5 + 1);
    v7 = v3 - 1;
    v13 = v6;
    v8 = v6;
    if ( v7 >= 0 )
    {
      do
      {
        CVoxelHash::CVoxelHash(this: v8++);
        --v7;
      }
      while ( v7 >= 0 );
      v6 = v13;
    }
  }
  else
  {
    v6 = nullptr;
  }
  this->m_pVoxelHash = v6;
  if ( this->m_AvailableVisitBits.m_Memory.m_nAllocationCount < 2048
    && this->m_AvailableVisitBits.m_Memory.m_nGrowSize >= 0 )
  {
    this->m_AvailableVisitBits.m_Memory.m_nAllocationCount = 2048;
    m_pMemory = this->m_AvailableVisitBits.m_Memory.m_pMemory;
    v10 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v11 = (unsigned __int16 *)((int (__stdcall *)(unsigned __int16 *, int))v10->Realloc_2)(a1: m_pMemory, a2: 4096);
    else
      v11 = (unsigned __int16 *)((int (__stdcall *)(int))v10->Alloc_2)(a1: 4096);
    this->m_AvailableVisitBits.m_Memory.m_pMemory = v11;
  }
  this->m_AvailableVisitBits.m_pElements = this->m_AvailableVisitBits.m_Memory.m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101DDE90
// Name: public: virtual CVoxelTree::~CVoxelTree(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelTree::~CVoxelTree(CVoxelTree *this)
{
  CVoxelHash *m_pVoxelHash; // ecx
  CUtlFixedLinkedList<LeafListData_t> *p_m_aLeafList; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::BlockHeader_t *v5; // [esp-4h] [ebp-Ch]

  m_pVoxelHash = this->m_pVoxelHash;
  this->__vftable = (CVoxelTree_vtbl *)&CVoxelTree::`vftable';
  if ( m_pVoxelHash != nullptr )
    CVoxelHash::`vector deleting destructor'(this: m_pVoxelHash, a2: 3u);
  CTSPool<CVarBitVec>::~CTSPool<CVarBitVec>(this: &this->m_FreeVisits);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_AvailableVisitBits);
  p_m_aLeafList = &this->m_aLeafList;
  CUtlLinkedList<LeafListData_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>>::RemoveAll(this: &this->m_aLeafList);
  m_pBlocks = p_m_aLeafList->m_Memory.m_pBlocks;
  if ( p_m_aLeafList->m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v5 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
    }
    while ( m_pBlocks != nullptr );
    p_m_aLeafList->m_Memory.m_pBlocks = nullptr;
    p_m_aLeafList->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DDEF0
// Name: public: void CVoxelTree::RemoveFromTree(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelTree::RemoveFromTree(CVoxelTree *this, unsigned __int16 hPartition)
{
  unsigned __int8 *v3; // ebx
  void *v4; // eax
  CThreadSpinRWLock *p_m_lock; // edi
  signed __int32 m_i32; // ecx
  int nLevel; // [esp+8h] [ebp-8h]
  bool bWasReading; // [esp+Fh] [ebp-1h]

  v3 = &this->m_pOwner->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * hPartition];
  nLevel = (char)v3[this->m_TreeId + 39];
  if ( nLevel >= 0 )
  {
    v4 = GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index);
    bWasReading = this->m_pVisits[(_DWORD)v4] != nullptr;
    if ( this->m_pVisits[(_DWORD)v4] != nullptr )
      _InterlockedExchangeAdd((volatile signed __int32 *)&this->m_lock, 0xFFFFFFFF);
    p_m_lock = &this->m_lock;
    if ( (this->m_lock.m_lockInfo.m_i32 & 0x10000) != 0
      || _InterlockedCompareExchange((volatile signed __int32 *)p_m_lock, 0x10000, 0) != 0 )
    {
      CThreadSpinRWLock::SpinLockForWrite(this: &this->m_lock);
    }
    else
    {
      this->m_lock.m_writerId = GetCurrentThreadId();
    }
    CVoxelHash::RemoveFromTree(this: &this->m_pVoxelHash[nLevel], hPartition);
    CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertBefore(
      this: &this->m_AvailableVisitBits,
      elem: this->m_AvailableVisitBits.m_Size,
      src: (const unsigned __int16 *)&v3[2 * this->m_TreeId + 42]);
    *(_WORD *)&v3[2 * this->m_TreeId + 42] = -1;
    this->m_lock.m_writerId = 0;
    p_m_lock->m_lockInfo.m_i32 = 0;
    if ( bWasReading )
    {
      if ( (p_m_lock->m_lockInfo.m_i32 & 0x10000) != 0
        || (m_i32 = (unsigned __int16)p_m_lock->m_lockInfo.m_i32,
            _InterlockedCompareExchange((volatile signed __int32 *)p_m_lock, m_i32 + 1, m_i32) != m_i32) )
      {
        CThreadSpinRWLock::SpinLockForRead(this: p_m_lock);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DE010
// Name: public: virtual void CSpatialPartition::RemoveFromTree(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::RemoveFromTree(CSpatialPartition *this, unsigned __int16 hPartition)
{
  unsigned __int8 *v3; // esi

  v3 = &this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * hPartition];
  if ( (v3[38] & 2) != 0 )
  {
    CVoxelTree::RemoveFromTree(this: this->m_VoxelTrees, hPartition);
    v3[38] &= ~2u;
  }
  if ( (v3[38] & 4) != 0 )
  {
    CVoxelTree::RemoveFromTree(this: &this->m_VoxelTrees[1], hPartition);
    v3[38] &= ~4u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DE120
// Name: public: void CVoxelTree::InsertIntoTree(unsigned short,class Vector const __near &,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelTree::InsertIntoTree(
        CVoxelTree *this,
        unsigned __int16 hPartition,
        const Vector *mins,
        const Vector *maxs,
        bool bReinsert)
{
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm5_4
  float v10; // xmm6_4
  float v11; // xmm4_4
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm7_4
  float v15; // xmm0_4
  float v16; // xmm3_4
  int v17; // eax
  float v18; // xmm0_4
  float *p_m_flVoxelSize; // ecx
  float v20; // xmm5_4
  CVoxelHash *v21; // eax
  unsigned int m_nLevelShift; // ecx
  int v23; // edi
  int v24; // ebx
  float *p_x; // eax
  void *v26; // eax
  CThreadSpinRWLock *p_m_lock; // ecx
  int m_TreeId; // ecx
  signed __int32 m_i32; // edx
  float vecMax; // [esp+0h] [ebp-24h]
  float vecMin; // [esp+Ch] [ebp-18h]
  int v32; // [esp+18h] [ebp-Ch]
  EntityInfo_t *info; // [esp+20h] [ebp-4h]
  CThreadSpinRWLock *bDoInsert; // [esp+30h] [ebp+Ch]
  char bDoInsert_3; // [esp+33h] [ebp+Fh]
  bool bWasReading; // [esp+3Bh] [ebp+17h]

  v6 = mins->x - 0.03125;
  v7 = mins->y - 0.03125;
  v8 = mins->z - 0.03125;
  v9 = maxs->x + 0.03125;
  v10 = maxs->y + 0.03125;
  v11 = maxs->z + 0.03125;
  x = s_PartitionMin.x;
  info = (EntityInfo_t *)&this->m_pOwner->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * hPartition];
  if ( s_PartitionMin.x <= v6 )
  {
    if ( v6 > s_PartitionMax.x )
      v6 = s_PartitionMax.x;
  }
  else
  {
    v6 = s_PartitionMin.x;
  }
  vecMin = v6;
  y = s_PartitionMin.y;
  if ( s_PartitionMin.y > v7 || (y = s_PartitionMax.y, v7 > s_PartitionMax.y) )
    v7 = y;
  if ( s_PartitionMin.z <= v8 )
  {
    z = s_PartitionMax.z;
    if ( v8 <= s_PartitionMax.z )
      z = mins->z - 0.03125;
  }
  else
  {
    z = s_PartitionMin.z;
  }
  if ( s_PartitionMin.x > v9 || (x = s_PartitionMax.x, v9 > s_PartitionMax.x) )
    v9 = x;
  v15 = s_PartitionMin.y;
  v16 = v9;
  vecMax = v9;
  if ( s_PartitionMin.y > v10 || (v15 = s_PartitionMax.y, v10 > s_PartitionMax.y) )
    v10 = v15;
  if ( s_PartitionMin.z <= v11 )
  {
    if ( v11 > s_PartitionMax.z )
      v11 = s_PartitionMax.z;
  }
  else
  {
    v11 = s_PartitionMin.z;
  }
  v17 = 0;
  v18 = v9 - vecMin;
  if ( this->m_nLevelCount - 1 > 0 )
  {
    p_m_flVoxelSize = &this->m_pVoxelHash->m_flVoxelSize;
    do
    {
      v20 = *p_m_flVoxelSize;
      if ( *p_m_flVoxelSize > v18 && v20 > (float)(v10 - v7) && v20 > (float)(v11 - z) )
        break;
      ++v17;
      p_m_flVoxelSize += 1046;
    }
    while ( v17 < this->m_nLevelCount - 1 );
  }
  v32 = v17;
  v21 = &this->m_pVoxelHash[v17];
  m_nLevelShift = v21->m_nLevelShift;
  bDoInsert_3 = 1;
  v23 = ((int)(float)(vecMin - v21->m_vecVoxelOrigin.x) >> m_nLevelShift) & 0x7FF
      | ((((int)(float)(z - v21->m_vecVoxelOrigin.z) >> m_nLevelShift << 11)
        | ((int)(float)(v7 - v21->m_vecVoxelOrigin.y) >> m_nLevelShift) & 0x7FF) << 11);
  v24 = ((int)(float)(v16 - v21->m_vecVoxelOrigin.x) >> m_nLevelShift) & 0x7FF
      | ((((int)(float)(v10 - v21->m_vecVoxelOrigin.y) >> m_nLevelShift) & 0x7FF
        | ((int)(float)(v11 - v21->m_vecVoxelOrigin.z) >> m_nLevelShift << 11)) << 11);
  p_x = &info->m_vecMin.x;
  if ( bReinsert )
  {
    if ( info->m_voxelMin.uiVoxel == v23 && info->m_voxelMax.uiVoxel == v24 )
    {
      bDoInsert_3 = 0;
    }
    else
    {
      CVoxelTree::RemoveFromTree(this, hPartition);
      v16 = vecMax;
      p_x = &info->m_vecMin.x;
    }
  }
  *p_x = vecMin;
  p_x[1] = v7;
  p_x[2] = z;
  p_x[4] = v16;
  p_x[5] = v10;
  p_x[6] = v11;
  if ( bDoInsert_3 != 0 )
  {
    v26 = GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index);
    bWasReading = this->m_pVisits[(_DWORD)v26] != nullptr;
    if ( this->m_pVisits[(_DWORD)v26] != nullptr )
      _InterlockedExchangeAdd((volatile signed __int32 *)&this->m_lock, 0xFFFFFFFF);
    p_m_lock = &this->m_lock;
    bDoInsert = &this->m_lock;
    if ( (this->m_lock.m_lockInfo.m_i32 & 0x10000) != 0
      || _InterlockedCompareExchange((volatile signed __int32 *)p_m_lock, 0x10000, 0) != 0 )
    {
      CThreadSpinRWLock::SpinLockForWrite(this: p_m_lock);
    }
    else
    {
      this->m_lock.m_writerId = GetCurrentThreadId();
    }
    info->m_voxelMin.uiVoxel = v23;
    info->m_voxelMax.uiVoxel = v24;
    m_TreeId = this->m_TreeId;
    if ( this->m_AvailableVisitBits.m_Size != 0 )
      info->m_nVisitBit[m_TreeId] = this->m_AvailableVisitBits.m_Memory.m_pMemory[--this->m_AvailableVisitBits.m_Size];
    else
      info->m_nVisitBit[m_TreeId] = this->m_nNextVisitBit++;
    CVoxelHash::InsertIntoTree(
      this: &this->m_pVoxelHash[v32],
      hPartition,
      voxelMin: (Voxel_t)v23,
      voxelMax: (Voxel_t)v24);
    this->m_lock.m_writerId = 0;
    bDoInsert->m_lockInfo.m_i32 = 0;
    if ( bWasReading )
    {
      if ( (bDoInsert->m_lockInfo.m_i32 & 0x10000) != 0
        || (m_i32 = (unsigned __int16)bDoInsert->m_lockInfo.m_i32,
            _InterlockedCompareExchange((volatile signed __int32 *)bDoInsert, m_i32 + 1, m_i32) != m_i32) )
      {
        CThreadSpinRWLock::SpinLockForRead(this: bDoInsert);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DE4E0
// Name: public: virtual void CVoxelTree::ElementMoved(unsigned short,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVoxelTree::ElementMoved(
        CVoxelTree *this,
        unsigned __int16 hPartition,
        const Vector *mins,
        const Vector *maxs)
{
  if ( hPartition != 0xFFFF )
  {
    if ( *(_DWORD *)&this->m_pOwner->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * hPartition + 48 + 4 * this->m_TreeId] != 0 )
      CVoxelTree::InsertIntoTree(this, hPartition, mins, maxs, bReinsert: true);
    else
      CVoxelTree::InsertIntoTree(this, hPartition, mins, maxs, bReinsert: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DE540
// Name: public: CSpatialPartition::CSpatialPartition(void)
// Source: json
//------------------------------------------------------------------------------
CSpatialPartition *__thiscall CSpatialPartition::CSpatialPartition(CSpatialPartition *this)
{
  unsigned __int8 *m_pBase; // eax
  CVoxelTree *m_VoxelTrees; // ebx
  int i; // [esp+Ch] [ebp-4h]

  this->__vftable = (CSpatialPartition_vtbl *)&CSpatialPartition::`vftable';
  CMemoryStack::CMemoryStack(this: &this->m_aHandles.m_Memory.m_MemoryStack);
  CMemoryStack::Init(
    this: &this->m_aHandles.m_Memory.m_MemoryStack,
    pszAllocOwner: "CUtlMemoryStack",
    maxSize: 0x3BFFC4u,
    commitSize: 0xF000u,
    initialCommit: 0,
    alignment: 4u);
  this->m_aHandles.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_aHandles.m_FirstFree = 0xFFFF;
  m_pBase = this->m_aHandles.m_Memory.m_MemoryStack.m_pBase;
  *(_DWORD *)&this->m_aHandles.m_Head = -1;
  this->m_aHandles.m_NumAlloced = 0;
  this->m_aHandles.m_pElements = (UtlLinkedListElem_t<EntityInfo_t,unsigned short> *)m_pBase;
  this->m_HandlesMutex.m_ownerID = 0;
  this->m_HandlesMutex.m_depth = 0;
  m_VoxelTrees = this->m_VoxelTrees;
  for ( i = 1; i >= 0; --i )
    CVoxelTree::CVoxelTree(this: m_VoxelTrees++);
  this->m_nQueryCallbackCount = 0;
  CMemoryStack::SetAllocOwner(
    this: &this->m_aHandles.m_Memory.m_MemoryStack,
    pszAllocOwner: "CSpatialPartition::m_aHandles");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101DE5E0
// Name: public: virtual void CSpatialPartition::Init(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::Init(CSpatialPartition *this, const Vector *worldmin, const Vector *worldmax)
{
  unsigned __int8 *m_pBase; // eax
  int v5; // esi
  CVoxelTree *m_VoxelTrees; // edi

  CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::RemoveAll(this: &this->m_aHandles);
  CMemoryStack::FreeAll(this: &this->m_aHandles.m_Memory.m_MemoryStack, bDecommit: true);
  this->m_aHandles.m_FirstFree = -1;
  m_pBase = this->m_aHandles.m_Memory.m_MemoryStack.m_pBase;
  this->m_aHandles.m_Memory.m_nAllocated = 0;
  *(_DWORD *)&this->m_aHandles.m_NumAlloced = -65536;
  this->m_aHandles.m_pElements = (UtlLinkedListElem_t<EntityInfo_t,unsigned short> *)m_pBase;
  CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::EnsureCapacity(
    this: &this->m_aHandles,
    num: 256);
  v5 = 0;
  m_VoxelTrees = this->m_VoxelTrees;
  do
  {
    m_VoxelTrees->Init(this: m_VoxelTrees, a2: this, a3: v5++, a4: worldmin, a5: worldmax);
    ++m_VoxelTrees;
  }
  while ( v5 < 2 );
}

//------------------------------------------------------------------------------
// Address: 0x101DE660
// Name: public: void CSpatialPartition::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::Shutdown(CSpatialPartition *this)
{
  CVoxelTree *m_VoxelTrees; // esi
  int i; // edi
  unsigned __int8 *m_pBase; // eax

  m_VoxelTrees = this->m_VoxelTrees;
  for ( i = 2; i != 0; --i )
    CVoxelTree::Shutdown(this: m_VoxelTrees++);
  CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::RemoveAll(this: &this->m_aHandles);
  CMemoryStack::FreeAll(this: &this->m_aHandles.m_Memory.m_MemoryStack, bDecommit: true);
  this->m_aHandles.m_Memory.m_nAllocated = 0;
  this->m_aHandles.m_FirstFree = -1;
  m_pBase = this->m_aHandles.m_Memory.m_MemoryStack.m_pBase;
  *(_DWORD *)&this->m_aHandles.m_NumAlloced = -65536;
  this->m_aHandles.m_pElements = (UtlLinkedListElem_t<EntityInfo_t,unsigned short> *)m_pBase;
}

//------------------------------------------------------------------------------
// Address: 0x101DE6B0
// Name: public: virtual void CSpatialPartition::InsertIntoTree(unsigned short,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::InsertIntoTree(
        CSpatialPartition *this,
        unsigned __int16 hPartition,
        const Vector *mins,
        const Vector *maxs)
{
  unsigned __int8 *m_pBase; // edx
  int v7; // eax
  unsigned __int8 *v8; // esi
  int listMask; // [esp+14h] [ebp+8h]

  m_pBase = this->m_aHandles.m_Memory.m_MemoryStack.m_pBase;
  v7 = *(unsigned __int16 *)&m_pBase[60 * hPartition + 36];
  v8 = &m_pBase[60 * hPartition];
  listMask = v7;
  if ( (v7 & 0x1AC) != 0 && (v8[38] & 2) == 0 )
  {
    CVoxelTree::InsertIntoTree(this: this->m_VoxelTrees, hPartition, mins, maxs, bReinsert: false);
    v8[38] |= 2u;
    v7 = listMask;
  }
  if ( (v7 & 0xFFFFFE53) != 0 && (v8[38] & 4) == 0 )
  {
    CVoxelTree::InsertIntoTree(this: &this->m_VoxelTrees[1], hPartition, mins, maxs, bReinsert: false);
    v8[38] |= 4u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DE770
// Name: public: CSpatialPartition::~CSpatialPartition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::~CSpatialPartition(CSpatialPartition *this)
{
  IPartitionQueryCallback **m_pQueryCallback; // eax
  CTSPool<CVarBitVec> *v3; // esi
  CVoxelHash *DepthAndSequence; // ecx
  void *v5; // eax
  const CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::Iterator_t *v6; // ecx
  TSLNodeBase_t **v7; // eax
  TSLNodeBase_t *v8; // edi
  int i; // ebx
  TSLNodeBase_t *v10; // edi
  CSpatialPartition *v11; // esi
  CTSPool<CVarBitVec> *v12; // eax
  TSLNodeBase_t *Next; // eax
  int v14; // eax
  TSLNodeBase_t *v15; // [esp-4h] [ebp-44h]
  _DWORD v16[2]; // [esp+1Ch] [ebp-24h] BYREF
  _DWORD v17[2]; // [esp+24h] [ebp-1Ch] BYREF
  CSpatialPartition *v18; // [esp+2Ch] [ebp-14h]
  const CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::Iterator_t *v19; // [esp+30h] [ebp-10h]
  IPartitionQueryCallback **v20; // [esp+34h] [ebp-Ch]
  int v21; // [esp+38h] [ebp-8h]
  CTSPool<CVarBitVec> *v22; // [esp+3Ch] [ebp-4h]

  v18 = this;
  this->__vftable = (CSpatialPartition_vtbl *)&CSpatialPartition::`vftable';
  CSpatialPartition::Shutdown(this);
  m_pQueryCallback = this->m_pQueryCallback;
  v21 = 1;
  v3 = (CTSPool<CVarBitVec> *)((char *)this + 760);
  while ( 1 )
  {
    DepthAndSequence = (CVoxelHash *)v3[-55].m_Head.value32.DepthAndSequence;
    v3 -= 30;
    v20 = m_pQueryCallback - 60;
    v22 = v3;
    *(m_pQueryCallback - 60) = (IPartitionQueryCallback *)&CVoxelTree::`vftable';
    if ( DepthAndSequence != nullptr )
      CVoxelHash::`vector deleting destructor'(this: DepthAndSequence, a2: 3u);
    CTSPool<CVarBitVec>::~CTSPool<CVarBitVec>(this: v3 + 2);
    v3->m_Head.value.Next = nullptr;
    if ( v3[-1].m_Head.value32.DepthAndSequence >= 0 )
    {
      if ( v3[-2].m_Head.value32.DepthAndSequence != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v3[-2].m_Head.value32.DepthAndSequence);
        v3[-2].m_Head.value32.DepthAndSequence = 0;
      }
      v3[-1].m_Head.value.Next = nullptr;
    }
    v5 = (void *)v3[-2].m_Head.value32.DepthAndSequence;
    v3->m_Head.value32.DepthAndSequence = (int)v5;
    if ( v3[-1].m_Head.value32.DepthAndSequence >= 0 )
    {
      if ( v5 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
        v3[-2].m_Head.value32.DepthAndSequence = 0;
      }
      v3[-1].m_Head.value.Next = nullptr;
    }
    v6 = (const CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::Iterator_t *)&v3[-20];
    if ( v3[-20].m_Head.value.Next != nullptr || v3[-20].m_Head.value32.DepthAndSequence != -1 )
    {
      if ( v3[-24].m_Head.value.Next != nullptr )
      {
        v17[0] = v3[-24].m_Head.value.Next;
        v17[1] = 0;
        v7 = (TSLNodeBase_t **)v17;
      }
      else
      {
        v16[0] = 0;
        v16[1] = -1;
        v7 = (TSLNodeBase_t **)v16;
      }
      v8 = *v7;
      for ( i = (int)v7[1]; ; i = 0 )
      {
        while ( 1 )
        {
          while ( 1 )
          {
            if ( v8 != nullptr )
            {
              if ( i >= 0 && i < *((_DWORD *)&v8->Next + 1) )
              {
                if ( &v8[2 * i] != (TSLNodeBase_t *)-8
                  && !CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int>>::IsIdxAfter(
                        this: (CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> > *)&v22[-24],
                        i: (unsigned int)&v8[2 * i + 1],
                        it: v6)
                  && (v8[2 * i + 2].Next != &v8[2 * i + 1] || *(&v8[2 * i + 2].Next + 1) == &v8[2 * i + 1]) )
                {
                  v12 = v22;
                  v8[2 * i + 2].Next = &v8[2 * i + 1];
                  *((_DWORD *)&v8[2 * i + 2].Next + 1) = v12[-22].m_Head.value32.DepthAndSequence;
                  v12[-22].m_Head.value32.DepthAndSequence = (int)&v8[2 * i + 1];
                }
                v3 = v22;
              }
            }
            else if ( i == -1 )
            {
              goto LABEL_21;
            }
            Next = v3[-20].m_Head.value.Next;
            v19 = (const CUtlFixedMemory<UtlLinkedListElem_t<LeafListData_t,int> >::Iterator_t *)&v3[-20];
            if ( v8 == Next && i == v3[-20].m_Head.value32.DepthAndSequence )
            {
LABEL_21:
              v3[-23].m_Head.value32.DepthAndSequence = 0;
              v3[-22].m_Head.value.Next = nullptr;
              v3[-21].m_Head.value.Next = nullptr;
              goto LABEL_22;
            }
            if ( v8 != nullptr && i >= 0 )
            {
              v14 = *((_DWORD *)&v8->Next + 1);
              if ( i < v14 )
                break;
            }
            v6 = v19;
            v8 = nullptr;
            i = -1;
          }
          if ( ++i >= v14 )
            break;
LABEL_45:
          v6 = v19;
        }
        v8 = v8->Next;
        if ( v8 == nullptr )
        {
          v8 = nullptr;
          i = -1;
          goto LABEL_45;
        }
        v6 = v19;
      }
    }
LABEL_22:
    v10 = v3[-24].m_Head.value.Next;
    if ( v10 != nullptr )
    {
      do
      {
        v15 = v10;
        v10 = v10->Next;
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
      }
      while ( v10 != nullptr );
      v3[-24].m_Head.value.Next = nullptr;
      v3[-24].m_Head.value32.DepthAndSequence = 0;
    }
    if ( --v21 < 0 )
      break;
    m_pQueryCallback = v20;
  }
  v11 = v18;
  CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::RemoveAll(this: &v18->m_aHandles);
  CMemoryStack::~CMemoryStack(this: &v11->m_aHandles.m_Memory.m_MemoryStack);
}

//------------------------------------------------------------------------------
// Address: 0x101DE9A0
// Name: public: virtual void CSpatialPartition::DestroyHandle(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialPartition::DestroyHandle(CSpatialPartition *this, int hPartition)
{
  CThreadFastMutex *p_m_HandlesMutex; // esi
  DWORD CurrentThreadId; // eax

  if ( (_WORD)hPartition != 0xFFFF )
  {
    this->RemoveFromTree(this, a2: hPartition);
    p_m_HandlesMutex = &this->m_HandlesMutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != this->m_HandlesMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_HandlesMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_HandlesMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_HandlesMutex.m_depth;
    }
    CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::Unlink(
      this: &this->m_aHandles,
      elem: hPartition);
    *(_WORD *)&this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[60 * (unsigned __int16)hPartition + 58] = this->m_aHandles.m_FirstFree;
    this->m_aHandles.m_FirstFree = hPartition;
    if ( this->m_HandlesMutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_HandlesMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DEA30
// Name: public: virtual unsigned short CSpatialPartition::CreateHandle(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CSpatialPartition::CreateHandle(CSpatialPartition *this, IHandleEntity *pHandleEntity)
{
  CThreadFastMutex *p_m_HandlesMutex; // ebx
  DWORD CurrentThreadId; // ecx
  unsigned __int16 v5; // di
  unsigned __int16 v6; // ax
  bool v7; // zf
  int v8; // edi
  int v9; // ecx
  unsigned __int8 *v10; // edx
  int v11; // eax
  int v12; // edx
  unsigned __int16 v14; // [esp+10h] [ebp-4h]

  p_m_HandlesMutex = &this->m_HandlesMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_HandlesMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_HandlesMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_HandlesMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_HandlesMutex->m_depth;
  }
  v5 = CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::AllocInternal(
         this: &this->m_aHandles,
         multilist: false);
  v6 = -1;
  if ( v5 != 0xFFFF )
  {
    CUtlLinkedList<EntityInfo_t,unsigned short,0,unsigned short,CUtlMemoryStack<UtlLinkedListElem_t<EntityInfo_t,unsigned short>,unsigned short,65535,1024,0>>::LinkBefore(
      this: &this->m_aHandles,
      before: 0xFFFFu,
      elem: v5);
    v6 = v5;
  }
  v7 = p_m_HandlesMutex->m_depth-- == 1;
  v14 = v6;
  if ( v7 )
    _InterlockedExchange((volatile __int32 *)p_m_HandlesMutex, 0);
  v8 = v6;
  v9 = 60 * v6;
  *(_DWORD *)&this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[v9 + 32] = pHandleEntity;
  v10 = &this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[v9];
  *(_DWORD *)v10 = 2139095039;
  *((_DWORD *)v10 + 1) = 2139095039;
  *((_DWORD *)v10 + 2) = 2139095039;
  *((_DWORD *)v10 + 4) = 0x800000;
  *((_DWORD *)v10 + 5) = 0x800000;
  *((_DWORD *)v10 + 6) = 0x800000;
  *((_WORD *)v10 + 18) = 0;
  this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[v9 + 38] = 0;
  v11 = 30 * v6;
  *(_WORD *)&this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[2 * v11 + 42] = -1;
  this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[v9 + 39] = -1;
  v12 = 15 * v8;
  *(_DWORD *)&this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[4 * v12 + 48] = 0;
  *(_WORD *)&this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[2 * v11 + 44] = -1;
  this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[v9 + 40] = -1;
  *(_DWORD *)&this->m_aHandles.m_Memory.m_MemoryStack.m_pBase[4 * v12 + 52] = 0;
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x10276AB0
// Name: public: void CUtlFixedMemory<struct UtlLinkedListElem_t<struct CCommandBuffer::Command_t,int>>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>::Grow(
        CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *this,
        int num)
{
  int m_nGrowSize; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *v4; // ebx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *m_pBlocks; // eax

  if ( num > 0 )
  {
    m_nGrowSize = this->m_nGrowSize;
    if ( m_nGrowSize == 0 )
    {
      m_nGrowSize = this->m_nAllocationCount;
      if ( m_nGrowSize == 0 )
        m_nGrowSize = 2;
    }
    if ( m_nGrowSize < num )
      m_nGrowSize *= (m_nGrowSize + num - 1) / m_nGrowSize;
    this->m_nAllocationCount += m_nGrowSize;
    v4 = (CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *)_g_pMemAlloc->Alloc_2(
                                                                                                  this: _g_pMemAlloc,
                                                                                                  a2: 20 * m_nGrowSize + 8);
    if ( v4 == nullptr )
      _Error(a1: "CUtlFixedMemory overflow!\n");
    m_pBlocks = this->m_pBlocks;
    v4->m_pNext = nullptr;
    v4->m_nBlockSize = m_nGrowSize;
    if ( m_pBlocks != nullptr )
    {
      for ( ; m_pBlocks->m_pNext != nullptr; m_pBlocks = m_pBlocks->m_pNext )
        ;
      m_pBlocks->m_pNext = v4;
    }
    else
    {
      this->m_pBlocks = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10276B90
// Name: public: bool CUtlFixedMemory<struct UtlLinkedListElem_t<struct CCommandBuffer::Command_t,int>>::IsIdxAfter(int,class CUtlFixedMemory<struct UtlLinkedListElem_t<struct CCommandBuffer::Command_t,int>>::Iterator_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>::IsIdxAfter(
        CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> > *this,
        unsigned int i,
        const CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::Iterator_t *it)
{
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *m_pBlockHeader; // eax
  int m_nIndex; // ecx
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *m_pNext; // eax

  m_pBlockHeader = it->m_pBlockHeader;
  if ( it->m_pBlockHeader == nullptr )
    return false;
  m_nIndex = it->m_nIndex;
  if ( m_nIndex < 0 || m_nIndex >= m_pBlockHeader->m_nBlockSize )
    return false;
  if ( i >= (unsigned int)&m_pBlockHeader[1] && i < (unsigned int)&m_pBlockHeader[1] + 20 * m_pBlockHeader->m_nBlockSize )
    return (int)i > (int)&m_pBlockHeader[1] + 20 * m_nIndex;
  m_pNext = m_pBlockHeader->m_pNext;
  if ( m_pNext == nullptr )
    return false;
  while ( i < (unsigned int)&m_pNext[1] || i >= (unsigned int)&m_pNext[1] + 20 * m_pNext->m_nBlockSize )
  {
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return false;
  }
  return true;
}

} // namespace engine_xlsp
